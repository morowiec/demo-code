<?php

namespace Drupal\drupal8_core\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Config\ConfigFactory;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Provides a 'Download Mobile App' Block.
 *
 * @Block(
 *   id = "drupal8_download_mobile_app",
 *   admin_label = @Translation("Drupal8 | Core | Download Mobile App"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class DownloadMobileApp extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * Links settings name.
   */
  const LINKS_SETTINGS_NAME = 'drupal8_core.settings';

  /**
   * Config Factory.
   *
   * @var \Drupal\Core\Config\ConfigFactory
   */
  protected $configFactory;

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
      $container->get('config.factory')
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
   * @param \Drupal\Core\Config\ConfigFactory $config_factory
   *   Config Factory.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, ConfigFactory $config_factory) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->configFactory = $config_factory;
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);
    $configuration = $this->getConfiguration();

    $form['text'] = [
      '#type' => 'text_format',
      '#title' => $this->t('Text'),
      '#format' => 'full_html',
      '#default_value' => isset($configuration['text']) ? $configuration['text'] : $this->t('<p>Pobierz aplikację mobilną <span style="color:#16a085;">drupal8Mobile</span> na swój telefon</p>'),
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitConfigurationForm(array &$form, FormStateInterface $form_state) {
    $this->configuration['text'] = $form_state->getValue('text')['value'];
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $build = [];
    $config = $this->configFactory->get(self::LINKS_SETTINGS_NAME);
    if (empty($config)) {
      return $build;
    }
    $build['google_play_url'] = $config->get('download_mobile_app.google_play_url');
    $build['app_store_play'] = $config->get('download_mobile_app.app_store_play');
    $build['open_new_window'] = $config->get('download_mobile_app.open_new_window');

    return $build;
  }

}
