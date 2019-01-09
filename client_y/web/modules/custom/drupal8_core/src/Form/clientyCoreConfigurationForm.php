<?php

namespace Drupal\drupal8_core\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 * Defines a form that configures forms module settings.
 */
class drupal8CoreConfigurationForm extends ConfigFormBase {

  /**
   * Links settings name.
   */
  const LINKS_SETTINGS_NAME = 'drupal8_core.settings';

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'drupal8_admin_settings';
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      self::LINKS_SETTINGS_NAME,
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config(self::LINKS_SETTINGS_NAME);
    $form['download_mobile_app'] = [
      '#type' => 'fieldset',
      '#title' => t('Download Mobile APP'),
      '#collapsible' => FALSE,
      '#collapsed' => FALSE,
    ];

    $form['download_mobile_app']['google_play_url'] = [
      '#type' => 'textfield',
      '#title' => t('Google Play Url'),
      '#default_value' => $config->get('download_mobile_app.google_play_url'),
      '#required' => TRUE,
    ];

    $form['download_mobile_app']['app_store_play'] = [
      '#type' => 'textfield',
      '#title' => t('App Store Url'),
      '#default_value' => $config->get('download_mobile_app.app_store_play'),
      '#required' => TRUE,
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $values = $form_state->getValues();
    $this->config(self::LINKS_SETTINGS_NAME)
      ->set('download_mobile_app.google_play_url', $values['google_play_url'])
      ->set('download_mobile_app.app_store_play', $values['app_store_play'])
      ->save();
    parent::submitForm($form, $form_state);
  }

}
