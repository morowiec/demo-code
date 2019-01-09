<?php

namespace Drupal\drupal8_education\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Menu\MenuActiveTrailInterface;
use Drupal\Core\Menu\MenuLinkManager;
use Drupal\Core\Menu\MenuLinkTreeInterface;
use Drupal\drupal8_education\EducationUtilities;
use Drupal\node\NodeInterface;

/**
 * Provides a 'Counter Lessons' Block.
 *
 * @package Drupal\drupal8_core
 *
 * @Block(
 *   id = "drupal8_counter_lessons",
 *   admin_label = @Translation("Drupal8 | Edukacja | Lekcja | Numer lekcji"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class CounterLessons extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * Drupal8 Utilities.
   *
   * @var \Drupal\drupal8_education\EducationUtilities
   */
  protected $educationUtilities;

  /**
   * MenuActiveTrailInterface.
   *
   * @var Drupal\Core\Menu\MenuActiveTrailInterface
   */
  protected $menuActiveTrail;

  /**
   * MenuLinkManager.
   *
   * @var Drupal\Core\Menu\MenuLinkManager
   */
  protected $menuLink;

  /**
   * MenuLinkTreeInterface.
   *
   * @var Drupal\Core\Menu\MenuLinkTreeInterface
   */
  protected $menuTree;

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
   *   A configuration array containing information about the plugin
   *   instance.
   * @param string $plugin_id
   *   The plugin ID for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\drupal8_education\EducationUtilities $education_utilities
   *   drupal8 Education Utilities.
   * @param \Drupal\Core\Menu\MenuActiveTrailInterface $menu_active_trail
   *   The Menu Active Trail service.
   * @param \Drupal\Core\Menu\MenuLinkManager $menu_link
   *   The Menu Link Manager service.
   * @param \Drupal\Core\Menu\MenuLinkTreeInterface $menu_tree
   *   The Menu Link Manager service.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, EducationUtilities $education_utilities, MenuActiveTrailInterface $menu_active_trail, MenuLinkManager $menu_link, MenuLinkTreeInterface $menu_tree) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->educationUtilities = $education_utilities;
    $this->menuActiveTrail = $menu_active_trail;
    $this->menuLink = $menu_link;
    $this->menuTree = $menu_tree;
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
      $container->get('menu.active_trail'),
      $container->get('plugin.manager.menu.link'),
      $container->get('menu.link_tree')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $menu_name = 'main';
    $total = 1;
    $current = 1;
    if (!$this->node instanceof NodeInterface || $this->node->getType() != 'drupal8_education_lessons') {
      return [];
    }

    $link = $this->menuActiveTrail->getActiveLink($menu_name);

    if (empty($link)) {
      return [];
    }
    if ($link->getParent() && $parent = $this->menuLink->createInstance($link->getParent())) {
      $siblings = $this->educationUtilities->getSiblings($menu_name, $parent->getPluginId());

      $current = array_search($link->getPluginId(), $siblings) + 1;
      $total = count($siblings);
    }
    $build['#current'] = $current;
    $build['#total'] = $total;

    $build['#cache']['keys'][] = 'prev_next_block';
    $build['#cache'] = ['max-age' => -1];
    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];
    // Invalidate this cache when menu is resaved, updated.
    $build['#cache']['tags'][] = 'config:system.menu.' . $menu_name;
    $build['#theme'] = 'drupal8_counter_lessons';

    return $build;
  }

}
