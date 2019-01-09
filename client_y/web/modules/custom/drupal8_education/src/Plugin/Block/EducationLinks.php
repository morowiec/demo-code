<?php

namespace Drupal\drupal8_education\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\Core\StringTranslation\TranslationInterface;
use Drupal\Core\Menu\MenuLinkTreeInterface;
use Drupal\Core\Menu\MenuTreeParameters;
use Drupal\Core\Menu\MenuLinkManager;
use Drupal\Core\Url;
use Drupal\Component\Utility\Unicode;

/**
 * Provides a 'Education Links' Block.
 *
 * @package Drupal\drupal8_education
 *
 * @Block(
 *   id = "drupal8_education_links",
 *   admin_label = @Translation("Drupal8 | Education | Education Links"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class EducationLinks extends BlockBase implements ContainerFactoryPluginInterface {

  use StringTranslationTrait;

  /**
   * The menu link tree manager.
   *
   * @var \Drupal\Core\Menu\MenuLinkTreeInterface
   */
  protected $menuTree;

  /**
   * The menu link manager.
   *
   * @var \Drupal\Core\Menu\MenuLinkManager
   */
  protected $menuLinkManager;

  /**
   * Constructor.
   *
   * @param array $configuration
   *   Configuration.
   * @param string $plugin_id
   *   Plugin ID.
   * @param mixed $plugin_definition
   *   Plugin Definition.
   * @param \Drupal\Core\StringTranslation\TranslationInterface $string_translation
   *   The string translation service.
   * @param \Drupal\Core\Menu\MenuLinkTreeInterface $menu_tree
   *   The Menu Link Manager service.
   * @param \Drupal\Core\Menu\MenuLinkManager $menu_link_manager
   *   The Menu Link Manager service.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, TranslationInterface $string_translation, MenuLinkTreeInterface $menu_tree, MenuLinkManager $menu_link_manager) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->stringTranslation = $string_translation;
    $this->menuTree = $menu_tree;
    $this->menuLinkManager = $menu_link_manager;

  }

  /**
   * Create container.
   *
   * @param \Symfony\Component\DependencyInjection\ContainerInterface $container
   *   Container.
   * @param array $configuration
   *   Configuration.
   * @param string $plugin_id
   *   Plugin ID.
   * @param mixed $plugin_definition
   *   Plugin Definition.
   *
   * @return static
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('string_translation'),
      $container->get('menu.link_tree'),
      $container->get('plugin.manager.menu.link')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);

    $alias = \Drupal::service('path.alias_manager')
      ->getPathByAlias('/edukacja');
    $params = Url::fromUri("internal:" . $alias)->getRouteParameters();
    $entity_type = key($params);
    $node = \Drupal::entityTypeManager()
      ->getStorage($entity_type)
      ->load($params[$entity_type]);
    if (!$node) {
      return $form;
    }

    $menu_name = 'main';

    $parents = $this->menuLinkManager->loadLinksByRoute('entity.node.canonical', ['node' => $node->id()]);
    $parent = reset($parents);

    $tree = $this->getMenuSubTree($menu_name, $parent->getPluginId());

    $options = [];
    $this->getOptionsTreeWalk($tree, '--', $options);
    for ($i = 0; $i < 6; $i++) {
      $form['education_link' . $i] = [
        '#type' => 'select',
        '#title' => $this->t('Menu link @i', ['@i' => $i + 1]),
        '#description' => $this->t('Link for column @i', ['@i' => $i]),
        '#options' => $options,
        '#default_value' => !empty($this->configuration['education_link' . $i]) ? $this->configuration['education_link' . $i] : FALSE,

      ];
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    for ($i = 0; $i < 6; $i++) {
      $this->configuration['education_link' . $i] = $form_state->getValue('education_link' . $i);
    }
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $config = $this->getConfiguration();

    $build = [];
    $build['#title'] = $this->t('<span class="secondary">Tematy</span> edukacyjne');
    $menu_name = 'main';
    $headers = [];
    $links = [];

    for ($i = 0; $i < 6; $i++) {
      if (empty($config['education_link' . $i])) {
        $headers[$i] = '';
        $links[$i] = [];
        continue;
      }
      $header = $this->menuLinkManager->createInstance($config['education_link' . $i]);
      $headers[$i] = $header->getTitle();

      $menu_links = $this->getMenuSubTree($menu_name, $config['education_link' . $i]);
      foreach ($menu_links as $menu_link) {
        $link['url'] = $menu_link->link->getUrlObject();
        $link['title'] = $menu_link->link->getTitle();
        $links[$i][] = $link;
      }
    }
    $build['#headers'] = $headers;
    $build['#links'] = $links;
    $build['#cache']['keys'][] = 'education_links';
    $build['#cache'] = ['max-age' => -1];
    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];
    $build['#theme'] = 'drupal8_education_links';

    return $build;
  }

  /**
   * Get Menu Item Entity ID from Menu UUID.
   *
   * Loads a menu tree with a menu link plugin instance at each element.
   *
   * @param string $menu_name
   *   The name of the menu.
   * @param string $root
   *   The ID of the plugin being root.
   *
   * @return \Drupal\Core\Menu\MenuLinkTreeElement[]
   *   A menu link tree.
   */
  protected function getMenuSubTree($menu_name, $root) {
    $parameters = new MenuTreeParameters();
    $parameters->setRoot($root)
      ->excludeRoot()
      ->onlyEnabledLinks();

    $tree = $this->menuTree->load($menu_name, $parameters);
    $manipulators = [
      ['callable' => 'menu.default_tree_manipulators:checkNodeAccess'],
      ['callable' => 'menu.default_tree_manipulators:checkAccess'],
      ['callable' => 'menu.default_tree_manipulators:generateIndexAndSort'],
    ];

    return $this->menuTree->transform($tree, $manipulators);
  }

  /**
   * Iterates over all items in the tree to prepare the parents select options.
   *
   * @param \Drupal\Core\Menu\MenuLinkTreeElement[] $tree
   *   The menu tree.
   * @param string $indent
   *   The indentation string used for the label.
   * @param array $options
   *   The select options.
   */
  protected function getOptionsTreeWalk(array $tree, $indent, array &$options) {
    foreach ($tree as $leaf) {
      $options[$leaf->link->getPluginId()] = $indent . ' ' . Unicode::truncate($leaf->link->getTitle(), 30, TRUE, FALSE);
      if (!empty($leaf->subtree)) {
        $this
          ->getOptionsTreeWalk($leaf->subtree, $indent . '--', $options);
      }
    }
  }

}
