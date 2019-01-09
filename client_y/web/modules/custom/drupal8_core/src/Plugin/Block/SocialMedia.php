<?php

namespace Drupal\drupal8_core\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\drupal8_core\Utilities;

/**
 * Provides a 'Social media' Block.
 *
 * @package Drupal\drupal8_core
 *
 * @Block(
 *   id = "drupal8_social_media",
 *   admin_label = @Translation("Drupal8 | Core | Social Media"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class SocialMedia extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * Links settings name.
   */
  const LINKS_SETTINGS_NAME = 'drupal8_core.links.settings';

  /**
   * Drupal8 Utilities.
   *
   * @var \Drupal\drupal8_core\Utilities
   */
  protected $coreUtilities;

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
      $container->get('drupal8_core.utilities')
    );
  }

  /**
   * Constructor.
   *
   * @param array $configuration
   *   Configuration.
   * @param string $plugin_id
   *   Plugin ID.
   * @param mixed $plugin_definition
   *   Plugin Definition.
   * @param \Drupal\drupal8_core\Utilities $core_utilities
   *   Drupal8 Utilities.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, Utilities $core_utilities) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->coreUtilities = $core_utilities;
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);
    $config = $this->getConfiguration();

    $form['label']['#default_value'] = isset($config['label']) ? $config['label'] : $this->t('Dołącz do nas');
    return $form;
  }

  /**
   * Get Link with icon.
   *
   * @param string $type
   *   Link id.
   * @param string $icon
   *   Icon string.
   * @param array $options
   *   The array of options. See \Drupal\Core\Url::fromUri() for details on what
   *   it contains.
   *
   * @return \Drupal\Core\GeneratedLink
   *   The link HTML markup.
   */
  private function getLinkWithIcon($type, $icon, array $options = []) {
    $config = $this->coreUtilities->getLinkConfig(self::LINKS_SETTINGS_NAME, $type);
    $content = [
      '#theme' => 'drupal8_social_media_element',
      '#icon' => $icon,
      '#title' => $config['title'],
    ];
    return $this->coreUtilities->getRenderedLink($content, $config['url'], $options);
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $build['#items']['facebook'] = $this->getLinkWithIcon('facebook', 'facebook');

    $build['#items']['youtube'] = $this->getLinkWithIcon('youtube', 'youtube');

    $build['#theme'] = 'drupal8_social_media';
    return $build;
  }

}
