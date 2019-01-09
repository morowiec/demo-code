<?php

namespace Drupal\drupal8_core\Layout;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Layout\LayoutDefault;
use Drupal\Core\Plugin\PluginFormInterface;

/**
 * Class BasicConfigurationLayoutClass. Configuration form for section.
 *
 * @package Drupal\drupal8_core\Layout
 */
class BasicConfigurationLayoutClass extends LayoutDefault implements PluginFormInterface {

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return parent::defaultConfiguration() + [
      'color' => 'transparent',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $configuration = $this->getConfiguration();
    $form['color'] = [
      '#type' => 'select',
      '#default_value' => $configuration['color'],
      '#title' => $this->t('BG color'),
      '#required' => TRUE,
      '#options' => [
        'transparent' => $this->t('Transparent'),
        'gray' => $this->t('Gray'),
      ],
    ];
    $form['wrapped'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Wrapped Container Large'),
      '#default_value' => $configuration['wrapped'],
    ];
    $form['line_above'] = [
      '#type' => 'checkbox',
      '#title' => $this->t('Border Line Above - 12 cols'),
      '#default_value' => $configuration['line_above'],
    ];
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function validateConfigurationForm(array &$form, FormStateInterface $form_state) {
  }

  /**
   * {@inheritdoc}
   */
  public function submitConfigurationForm(array &$form, FormStateInterface $form_state) {
    $this->configuration['color'] = $form_state->getValue('color');
    $this->configuration['wrapped'] = $form_state->getValue('wrapped');
    $this->configuration['line_above'] = $form_state->getValue('line_above');
  }

}
