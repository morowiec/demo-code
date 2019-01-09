<?php

namespace Drupal\drupal8_education\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\Core\StringTranslation\TranslationInterface;
use Drupal\views\Views;
use Drupal\drupal8_core\Utilities;

/**
 * Provides a 'Top Rated Articles' Block.
 *
 * @package Drupal\drupal8_education
 *
 * @Block(
 *   id = "drupal8_top_rated_articles",
 *   admin_label = @Translation("Drupal8 | Education | Top Rated Articles"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class TopRatedArticles extends BlockBase implements ContainerFactoryPluginInterface {

  use StringTranslationTrait;

  /**
   * Drupal8 Utilities.
   *
   * @var \Drupal\drupal8_core\Utilities
   */
  protected $coreUtilities;

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
   * @param \Drupal\drupal8_core\Utilities $core_utilities
   *   Drupal8 Utilities.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, TranslationInterface $string_translation, Utilities $core_utilities) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->stringTranslation = $string_translation;
    $this->coreUtilities = $core_utilities;
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
      $container->get('drupal8_core.utilities')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);
    $config = $this->getConfiguration();

    $form['label']['#default_value'] = isset($config['label']) ? $config['label'] : $this->t('Najlepiej oceniane artykuły');
    $form['drupal8_top_rated_articles_button_label'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Button label'),
      '#description' => $this->t('Label displayed on button on bottom of the block'),
      '#default_value' => isset($config['drupal8_top_rated_articles_button_label']) ? $config['drupal8_top_rated_articles_button_label'] : $this->t('Zobacz wszystkie artykuły'),
    ];
    $form['drupal8_top_rated_articles_button_url'] = [
      '#title' => $this->t('Button URL'),
      '#type' => 'url',
      '#maxlength' => 1024,
      '#description' => $this->t('Link for button on bottom of the block'),
      '#default_value' => isset($config['drupal8_top_rated_articles_button_url']) ? $config['drupal8_top_rated_articles_button_url'] : 'http://drupal8.pl',
    ];
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    $this->setConfigurationValue('drupal8_top_rated_articles_button_label', $form_state->getValue('drupal8_top_rated_articles_button_label'));
    $this->setConfigurationValue('drupal8_top_rated_articles_button_url', $form_state->getValue('drupal8_top_rated_articles_button_url'));
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $config = $this->getConfiguration();
    $has_button_label = isset($config['drupal8_top_rated_articles_button_label']) ? TRUE : FALSE;
    $has_button_url = isset($config['drupal8_top_rated_articles_button_url']) ? TRUE : FALSE;

    $build = [];

    $view = Views::getView('drupal8_edu_top_rated_articles');
    $render_array = $view->buildRenderable('block_education_homepage');
    $rendered = \Drupal::service('renderer')->renderRoot($render_array);

    $build['#content'] = $rendered;
    if ($has_button_label && $has_button_url) {
      $options = [
        'attributes' => [
          'class' => [
            'btn',
            'btn-outline-secondary',
          ],
        ],
      ];
      $build['#buttons'][] = $this->coreUtilities->getRenderedLink($config['drupal8_top_rated_articles_button_label'], $config['drupal8_top_rated_articles_button_url'], $options);
    }
    else {
      $build['#buttons'][] = '';
    }

    $build['#cache']['keys'][] = 'top_rated_articles';
    $build['#cache'] = ['max-age' => -1];
    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];
    $build['#theme'] = 'drupal8_top_rated_articles';

    return $build;
  }

}
