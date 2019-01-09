<?php

namespace Drupal\drupal8_education\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Link;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Utility\LinkGeneratorInterface;
use Drupal\Core\Menu\MenuActiveTrailInterface;
use Drupal\Core\Form\FormStateInterface;
use Drupal\drupal8_education\EducationUtilities;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\Core\StringTranslation\TranslationInterface;
use Drupal\node\NodeInterface;

/**
 * Provides a 'Prev/Next Lessons Navigation' Block.
 *
 * @package Drupal\drupal8_core
 *
 * @Block(
 *   id = "drupal8_prev_next_lessons",
 *   admin_label = @Translation("Drupal8 | Edukacja | Lekcja | Wstecz/Dalej"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class PrevNextLessons extends BlockBase implements ContainerFactoryPluginInterface {
  use StringTranslationTrait;

  /**
   * Drupal8 Utilities.
   *
   * @var \Drupal\drupal8_education\EducationUtilities
   */
  protected $educationUtilities;

  /**
   * The Link generator.
   *
   * @var \Drupal\Core\Utility\LinkGeneratorInterface
   */
  protected $linkGenerator;

  /**
   * Entity type manager.
   *
   * @var Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * MenuActiveTrailInterface.
   *
   * @var Drupal\Core\Menu\MenuActiveTrailInterface
   */
  protected $menuActiveTrail;

  /**
   * The node interface.
   *
   * @var \Drupal\node\NodeInterface
   */
  private $node;

  /**
   * Constructs a new BlockBase.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin ID for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\drupal8_education\EducationUtilities $education_utilities
   *   drupal8 Education Utilities.
   * @param \Drupal\Core\Utility\LinkGeneratorInterface $link_generator
   *   The Link generator.
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The Entity Type Manager service.
   * @param \Drupal\Core\Menu\MenuActiveTrailInterface $menu_active_trail
   *   The Menu Active Trail service.
   * @param \Drupal\Core\StringTranslation\TranslationInterface $string_translation
   *   The string translation service.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, EducationUtilities $education_utilities, LinkGeneratorInterface $link_generator, EntityTypeManagerInterface $entity_type_manager, MenuActiveTrailInterface $menu_active_trail, TranslationInterface $string_translation) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->educationUtilities = $education_utilities;
    $this->linkGenerator = $link_generator;
    $this->entityTypeManager = $entity_type_manager;
    $this->menuActiveTrail = $menu_active_trail;
    $this->stringTranslation = $string_translation;
    $this->node = \Drupal::routeMatch()->getParameter('node');
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('drupal8_education.education_utilities'),
      $container->get('link_generator'),
      $container->get('entity_type.manager'),
      $container->get('menu.active_trail'),
      $container->get('string_translation')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);
    $default_value = FALSE;
    if (!empty($this->configuration['display_mode'])) {
      $default_value = $this->configuration['display_mode'];
    }

    $form['display_mode'] = [
      '#type' => 'select',
      '#title' => $this->t('Choose display mode'),
      '#default_value' => $default_value,
      '#options' => ['full' => 'Full', 'next' => 'Next only'],
      '#description' => $this->t('Select display mode for prev/next navigation.'),
      '#required' => TRUE,
    ];
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    $this->configuration['display_mode'] = $form_state->getValue('display_mode');
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    if (!$this->node instanceof NodeInterface || $this->node->getType() != 'drupal8_education_lessons') {
      return [];
    }

    $current_menu_uuid = $parent_menu_uuid = '';
    $prev_index = $next_index = NULL;
    $prev_entity_id = $next_entity_id = $parents = NULL;
    $prev_url = NULL;
    $next_url = NULL;

    $this->menuStorage = $this->entityTypeManager
      ->getStorage('menu_link_content');

    $menu_name = 'main';

    $display_mode = $this->configuration['display_mode'] ?? 'full';

    switch ($display_mode) {
      case 'next':
        $build['#attributes']['class'][] = 'block-drupal8-prev-next-lessons-next';
        break;

      case 'full':
      default:
        $build['#attributes']['class'][] = 'block-drupal8-prev-next-lessons-full';
        break;

    }

    $this->menuName = $menu_name;

    $active_trail_ids = $this->menuActiveTrail->getActiveTrailIds($menu_name);

    // Setup empty array that still correctly sets cache.
    $build['#cache']['keys'][] = 'prev_next_block';
    $build['#cache'] = ['max-age' => -1];
    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];
    // Invalidate this cache when menu is resaved, updated.
    $build['#cache']['tags'][] = 'config:system.menu.' . $menu_name;

    if (count($active_trail_ids) == 1) {
      // This block is on a request with no matching menu items.
      return $build;
    }

    // Start with current menu link.
    $current_menu_uuid = array_shift($active_trail_ids);
    $current_menu_id = $this->getMenuId($current_menu_uuid);
    $current_menu_entity = $this->menuStorage->load($current_menu_id);

    // Parent of '' is top level of menu, so query with parent is NULL.
    $parent_menu_uuid = array_shift($active_trail_ids);

    // Get siblings.
    $siblings_ordered = $this->educationUtilities->getSiblings($menu_name, $parent_menu_uuid);
    // Find current index, prev, next.
    $sibling_index = array_search($current_menu_uuid, $siblings_ordered);

    if ($sibling_index !== FALSE) {
      $prev_index = $sibling_index - 1;
      $next_index = $sibling_index + 1;
    }

    if (!empty($siblings_ordered[$prev_index])) {
      // Simple case of prev sibling.
      // TODO - change from entity id to menu plugin id.
      $prev_entity_id = $siblings_ordered[$prev_index];
      $prev_menu_entity = $this->menuStorage
        ->load($this->getMenuId($siblings_ordered[$prev_index]));
      $url = $prev_menu_entity->getUrlObject();
      $prev_url = $url;
      $prev_title = $prev_menu_entity->getTitle();

    }

    if (!empty($siblings_ordered[$next_index])) {
      // Simplest case of next sibling.
      // TODO - change from entity id to menu plugin id.
      $next_entity_id = $siblings_ordered[$next_index];
      $next_menu_entity = $this->menuStorage
        ->load($this->getMenuId($siblings_ordered[$next_index]));
      $url = $next_menu_entity->getUrlObject();
      $next_url = $url;
      $next_title = $next_menu_entity->getTitle();
    }

    // Generate prev content.
    if ($prev_url && $display_mode != 'next') {
      $prev_url->setOption('attributes', [
        'class' => [
          'pager__link',
          'pager__link--prev',
          'text-truncate',
        ],
      ]);
      $build['#links']['prev'] = Link::fromTextAndUrl($prev_title, $prev_url)
        ->toRenderable();
      $build['#labels']['prev'] = $this->t('Poprzednia lekcja');
    }

    // Generate next content.
    if ($next_url) {
      $next_url->setOption('attributes', [
        'class' => [
          'pager__link',
          'pager__link--next',
          'text-truncate',
        ],
      ]);
      $build['#links']['next'] = Link::fromTextAndUrl($next_title, $next_url)
        ->toRenderable();
      $build['#labels']['next'] = $this->t('Następna lekcja');
    }

    $build['#cache']['keys'][] = 'prev_next_block';
    $build['#cache'] = ['max-age' => -1];
    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];
    // Invalidate this cache when menu is resaved, updated.
    $build['#cache']['tags'][] = 'config:system.menu.' . $menu_name;
    $build['#theme'] = 'drupal8_prev_next_lessons';

    return $build;
  }

  /**
   * Get Menu Item Entity ID from Menu UUID.
   *
   * @param mixed $menu_uuid
   *   UUID of a menu item.
   *
   * @return int
   *   Entity ID of menu item.
   */
  protected function getMenuId($menu_uuid) {

    $parts = explode(':', $menu_uuid);
    if (empty($parts[1])) {
      return FALSE;
    }

    $entity_id = $this->menuStorage->getQuery()
      ->condition('uuid', $parts[1])
      ->execute();
    if (empty($entity_id)) {
      return FALSE;
    }
    return array_shift($entity_id);
  }

}
