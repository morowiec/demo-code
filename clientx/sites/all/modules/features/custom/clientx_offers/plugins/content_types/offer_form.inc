<?php

/**
 * @file
 * Plugins are described by creating a $plugin array.
 *
 * They will be used by the system that includes this file.
 */

$plugin = array(
  'single' => TRUE,
  'render last' => TRUE,
  'title' => t('clientx | Offers | Content | Form'),
  'icon' => 'icon_form.png',
  'description' => t('Displays offer add/edit node form for Company/Agency users.'),
  'required context' => array(
    new ctools_context_required(t('Form'), 'form'),
    new ctools_context_required(t('User'), 'user'),
  ),
  'category' => t('clientx | Offers'),
);

/**
 * Output function for the Offers content type.
 *
 * Outputs a node based on the module and delta supplied in the configuration.
 */
function clientx_offers_offer_form_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();
  $block->module = 'form';

  if (isset($context[0]->form)) {
    if (isset($context[0]->form['#pre_render'])) {
      foreach ($context[0]->form['#pre_render'] as $function) {
        if (function_exists($function)) {
          $context[0]->form = $function($context[0]->form);
        }
      }
      unset($context[0]->form['#pre_render']);
    }

    // Hide Company ID field.
    $company = clientxSomeOffersTools::getCompanyFromUser($context[1]->data);
    if ($company) {
      $context[0]->form['field_clientx_company_id'][LANGUAGE_NONE]['#options'] = array($company->tid => $company->name);
      $context[0]->form['field_clientx_company_id']['#attributes']['readonly'] = 'readonly';
      $context[0]->form['field_clientx_company_id'][LANGUAGE_NONE]['#chosen'] = FALSE;
    }

    // Make workbench_moderation_state_new field readonly.
    if (isset($context[0]->form['revision_information']['workbench_moderation_state_new'])) {
      $context[0]->form['revision_information']['workbench_moderation_state_new']['#attributes']['readonly'] = 'readonly';
    }

    // Hide body field.
    $context[0]->form['body']['#access'] = FALSE;

    $block->content = array();
    foreach (element_children($context[0]->form) as $element) {
      $block->content[$element] = $context[0]->form[$element];
      unset($context[0]->form[$element]);
    }

    $block->delta = $context[0]->form_id;
  }

  return $block;
}

/**
 * Provide a blank form so we have a place to override title.
 */
function clientx_offers_offer_form_content_type_edit_form($form, &$form_state) {
  return $form;
}
