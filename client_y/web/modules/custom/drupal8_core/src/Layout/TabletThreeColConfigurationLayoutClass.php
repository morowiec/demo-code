<?php

namespace Drupal\drupal8_core\Layout;

use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Plugin\PluginFormInterface;

/**
 * Class TabletThreeColConfigurationLayoutClass. Configuration form for section.
 *
 * @package Drupal\drupal8_core\Layout
 */
class TabletThreeColConfigurationLayoutClass extends BasicConfigurationLayoutClass implements PluginFormInterface {

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return parent::defaultConfiguration() + [
      'tabletThreeCol' => 'one-row',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildConfigurationForm(array $form, FormStateInterface $form_state) {
    $form = parent::buildConfigurationForm($form, $form_state);

    $configuration = $this->getConfiguration();
    $form['tabletThreeCol'] = [
      '#type' => 'select',
      '#default_value' => $configuration['tabletThreeCol'],
      '#title' => $this->t('Tablet behavior'),
      '#required' => TRUE,
      '#options' => [
        'one-row' => $this->t('1 top + 1 x 3 column'),
        'three-rows' => $this->t('1 top + 3 x 1 column'),
      ],
    ];
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitConfigurationForm(array &$form, FormStateInterface $form_state) {
    parent::submitConfigurationForm($form, $form_state);
    $this->configuration['tabletThreeCol'] = $form_state->getValue('tabletThreeCol');
  }

}
