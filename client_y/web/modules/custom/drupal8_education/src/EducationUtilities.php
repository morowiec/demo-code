<?php

namespace Drupal\drupal8_education;

use Drupal\Core\Config\ConfigFactory;
use Drupal\Core\Link;
use Drupal\Core\Menu\MenuLinkTreeInterface;
use Drupal\Core\Url;

/**
 * Class EducationUtilities.
 *
 * @package Drupal\drupal8_core
 *
 * Helper class for Drupal8 Education module.
 */
class EducationUtilities {

  use \Drupal\Core\StringTranslation\StringTranslationTrait;

  /**
   * Config Factory.
   *
   * @var \Drupal\Core\Config\ConfigFactory
   */
  protected $configFactory;

  /**
   * The menu link tree manager.
   *
   * @var \Drupal\Core\Menu\MenuLinkTreeInterface
   */
  protected $menuTree;

  /**
   * Constructs an Utilities.
   *
   * @param \Drupal\Core\Config\ConfigFactory $config_factory
   *   Config Factory.
   * @param \Drupal\Core\Menu\MenuLinkTreeInterface $menu_tree
   *   The menu tree manager.
   */
  public function __construct(
    ConfigFactory $config_factory,
    MenuLinkTreeInterface $menu_tree
  ) {
    $this->configFactory = $config_factory;
    $this->menuTree = $menu_tree;
  }

  /**
   * Helper function. Return link from configuration.
   *
   * @param string $type
   *   Link id.
   *
   * @return \Drupal\Core\GeneratedLink|string
   *   Link generated from configuration.
   */
  public function getLink(string $type) {
    $link = '';
    $config = $this->configFactory->get('drupal8_education.settings');
    if (empty($config)) {
      return $link;
    }

    $options = [
      'attributes' => [
        'class' => [
          'btn btn-outline-link btn-sm btn-icon-arrow-right col-12 btn-promo-teaser',
        ],
      ],
    ];

    switch ($type) {
      case 'training-current':
        $uri = 'internal:' . $config->get('education_trainings');
        $link = Link::fromTextAndUrl($this->t('Zobacz nadchodzące szkolenia'), Url::fromUri($uri, $options))
          ->toString();
        break;

      case 'training-archived':
        $uri = 'internal:' . $config->get('education_trainings_archived');
        $link = Link::fromTextAndUrl($this->t('Zobacz szkolenia archiwalne'), Url::fromUri($uri, $options))
          ->toString();
        break;

      case 'training-upcoming':
        $options = [
          'attributes' => [
            'class' => [
              'btn btn-primary btn-promo-current',
            ],
          ],
        ];

        $uri = 'internal:' . $config->get('education_trainings_upcoming');
        $link = Link::fromTextAndUrl($this->t('Zobacz wszystkie szkolenia'), Url::fromUri($uri, $options))
          ->toString();
        break;
    }
    return $link;
  }

  /**
   * Helper function. Return UUID for children od given parent element.
   *
   * @param string $menu_name
   *   The name of the menu.
   * @param string $plugin_id
   *   UUID of a parent menu item.
   *
   * @return array
   *   Childrens menu link entity ids or empty array.
   */
  public function getSiblings($menu_name, $plugin_id) {
    $siblings = [];
    $parameters = $this->menuTree->getCurrentRouteMenuTreeParameters($menu_name);
    $parameters->setRoot($plugin_id);
    $parameters->excludeRoot();
    $tree = $this->menuTree->load($menu_name, $parameters);
    if (empty($tree)) {
      return $siblings;
    }

    $manipulators = [
      ['callable' => 'menu.default_tree_manipulators:checkAccess'],
      ['callable' => 'menu.default_tree_manipulators:generateIndexAndSort'],
    ];
    $tree = $this->menuTree->transform($tree, $manipulators);

    if (empty($tree)) {
      return $siblings;
    }
    foreach ($tree as $leaf) {
      $siblings[] = $leaf->link->getPluginId();
    }
    return $siblings;
  }

}
