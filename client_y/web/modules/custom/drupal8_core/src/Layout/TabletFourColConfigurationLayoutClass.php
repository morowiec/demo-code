<?php

namespace Drupal\drupal8_core\Layout;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\PluginFormInterface;

/**
 * Class TabletFourColConfigurationLayoutClass. Configuration form for section.
 *
 * @package Drupal\drupal8_core\Layout
 */
class TabletFourColConfigurationLayoutClass extends BasicConfigurationLayoutClass implements PluginFormInterface {

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return parent::defaultConfiguration() + [
      'tabletFourCol' => 'last-bottom',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);

    $configuration = $this->getConfiguration();
    $form['tabletFourCol'] = [
      '#type' => 'select',
      '#default_value' => $configuration['tabletFourCol'],
      '#title' => $this->t('Tablet behavior'),
      '#required' => TRUE,
      '#options' => [
        'one-row' => $this->t('1 row x 4 column'),
        'two-row' => $this->t('2 row x 2 column'),
        'four-row' => $this->t('4 row x 1 column'),
      ],
    ];
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitConfigurationForm(array &$form, FormStateInterface $form_state) {
    parent::submitConfigurationForm($form, $form_state);
    $this->configuration['tabletFourCol'] = $form_state->getValue('tabletFourCol');
  }

}
