<?php

namespace Drupal\drupal8_core;

use Drupal\Core\Config\ConfigFactory;
use Drupal\Core\Link;
use Drupal\Core\Routing\CurrentRouteMatch;
use Drupal\Core\Url;
use Drupal\node\NodeInterface;

/**
 * Class Utilities.
 *
 * @package Drupal\drupal8_core
 *
 * Helper class for Drupal8 Core module.
 */
class Utilities {

  use \Drupal\Core\StringTranslation\StringTranslationTrait;

  /**
   * Config Factory.
   *
   * @var \Drupal\Core\Config\ConfigFactory
   */
  protected $configFactory;

  /**
   * Config Factory.
   *
   * @var \Drupal\Core\Routing\CurrentRouteMatch
   */
  protected $currentRouteMatch;

  /**
   * Constructs an Utilities.
   *
   * @param \Drupal\Core\Config\ConfigFactory $config_factory
   *   Config Factory.
   * @param \Drupal\Core\Routing\CurrentRouteMatch $current_route_match
   *   Config Factory.
   */
  public function __construct(
    ConfigFactory $config_factory,
    CurrentRouteMatch $current_route_match
  ) {
    $this->configFactory = $config_factory;
    $this->currentRouteMatch = $current_route_match;
  }

  /**
   * Helper function. Return array from configuration.
   *
   * @param string $name
   *   The name of the configuration object to retrieve. The name corresponds to
   *   a configuration file. For @code \Drupal::config('book.admin') @endcode,
   *   the config object returned will contain the contents of book.admin
   *   configuration file.
   * @param string $type
   *   Link id.
   *
   * @return array|bool
   *   Array with link config or FALSE.
   */
  public function getLinkConfig($name, $type) {
    $config = $this->configFactory->get($name);
    if (empty($config)) {
      return FALSE;
    }

    return [
      'title' => $config->get($type . '.title'),
      'url' => $config->get($type . '.url'),
    ];
  }

  /**
   * Get rendered Link.
   *
   * @param string|array $text
   *   The text of the link.
   * @param string $uri
   *   The URI of the resource including the scheme. For user input that may
   *   correspond to a Drupal route, use internal: for the scheme. For paths
   *   that are known not to be handled by the Drupal routing system (such as
   *   static files), use base: for the scheme to get a link relative to the
   *   Drupal base path (like the <base> HTML element). For a link to an entity
   *   you may use entity:{entity_type}/{entity_id} URIs. The internal: scheme
   *   should be avoided except when processing actual user input that may or
   *   may not correspond to a Drupal route. Normally use Url::fromRoute() for
   *   code linking to any any Drupal page.
   * @param array $options
   *   The array of options. See \Drupal\Core\Url::fromUri() for details on what
   *   it contains.
   *
   * @return \Drupal\Core\GeneratedLink
   *   The link HTML markup.
   */
  public function getRenderedLink($text, $uri, array $options = []) {
    return Link::fromTextAndUrl($text, Url::fromUri($uri)
      ->setOptions($options)
    )->toString();
  }

  /**
   * Helper function. Return link from configuration.
   *
   * @param string $name
   *   The name of the configuration object to retrieve. The name corresponds to
   *   a configuration file. For @code \Drupal::config('book.admin') @endcode,
   *   the config object returned will contain the contents of book.admin
   *   configuration file.
   * @param string $type
   *   Link id.
   * @param array $options
   *   The array of options. See \Drupal\Core\Url::fromUri() for details on what
   *   it contains.
   *
   * @return \Drupal\Core\GeneratedLink|string
   *   Link generated from configuration.
   */
  public function getLinkFromConfig($name, $type, array $options = []) {
    $link = $this->t('No url for: @type', ['@type' => $type]);

    $config = $this->getLinkConfig($name, $type);
    if (!$config) {
      return $link;
    }

    $title = $config['title'];
    $url = $config['url'];

    if (empty($title) || empty($url)) {
      return $link;
    }

    return $this->getRenderedLink($title, $url, $options);
  }

  /**
   * Helper function to check if current path is frontpage.
   *
   * @param bool $with_node_preview
   *   Check if the hp bundle is in preview mode.
   *
   * @return bool
   *   Return true or false regarding condition.
   */
  public function isFrontpageBundle($with_node_preview = TRUE) {

    if ($with_node_preview && (($node = $this->currentRouteMatch->getParameter('node_preview')) instanceof NodeInterface && $node->bundle() === 'drupal8_hp')) {
      return TRUE;
    }

    if (($node = $this->currentRouteMatch->getParameter('node')) instanceof NodeInterface && $node->bundle() === 'drupal8_hp') {
      return TRUE;
    }

    return FALSE;
  }

}
