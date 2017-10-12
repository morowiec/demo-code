<?php

/**
 * @file
 * clientx | Offers | Bean token block content type plugin.
 */

$plugin = array(
  'title' => t('clientx | Offers | Bean token block'),
  'single' => TRUE,
  'category' => t('clientx | Offers'),
  'render callback' => 'clientx_some_page_bean_tokens_content_type_render',
  'edit form' => 'clientx_some_page_bean_tokens_content_type_settings',
  'admin info' => 'clientx_some_page_bean_tokens_content_type_summary',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render the clientx | Offers | Bean token block.
 */
function clientx_some_page_bean_tokens_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = $context[0]->data;
  $language = i18n_langcode();
  $field = isset($conf['field']) ? $conf['field'] : FALSE;

  switch ($field) {
    case 'field_clientx_bean_profile_procedur':
      if (isset($node->field_clientx_bean_profile_procedur[LANGUAGE_NONE][0]['target_id'])) {
        $bean = bean_load($node->field_clientx_bean_profile_procedur[LANGUAGE_NONE][0]['target_id']);
      }
      break;

    case 'field_clientx_bean_some_instructio':
      if (isset($node->field_clientx_bean_some_instructio[LANGUAGE_NONE][0]['target_id'])) {
        $bean = bean_load($node->field_clientx_bean_some_instructio[LANGUAGE_NONE][0]['target_id']);
      }
      break;

    case 'field_clientx_sel_procedure_descrip':
      if (isset($node->field_clientx_sel_procedure_descrip[LANGUAGE_NONE][0]['target_id'])) {
        $bean = bean_load($node->field_clientx_sel_procedure_descrip[LANGUAGE_NONE][0]['target_id']);
      }
      break;

    case 'field_clientx_standard_text':
      if (isset($node->field_clientx_standard_text[LANGUAGE_NONE][0]['target_id'])) {
        $bean = bean_load($node->field_clientx_standard_text[LANGUAGE_NONE][0]['target_id']);
      }
      break;

    case 'field_clientx_Testing_instruction':
      if (isset($node->field_clientx_Testing_instruction[LANGUAGE_NONE][0]['target_id'])) {
        $bean = bean_load($node->field_clientx_Testing_instruction[LANGUAGE_NONE][0]['target_id']);
      }
      break;
  }

  $block = new stdClass();

  if (isset($bean->field_clientx_text[$language])) {
    $block->content = token_replace($bean->field_clientx_text[$language][0]['value'], array('node' => $node));
  }
  elseif (isset($bean->field_clientx_text['en'])) {
    $block->content = token_replace($bean->field_clientx_text['en'][0]['value'], array('node' => $node));
  }
  else {
    return FALSE;
  }

  return $block;
}

/**
 * Provides settings form for plugin.
 */
function clientx_some_page_bean_tokens_content_type_settings($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['field'] = array(
    '#title' => t('Field to render'),
    '#type' => 'radios',
    '#options' => array(
      'field_clientx_bean_profile_procedur' => t('Profile and procedure'),
      'field_clientx_Testing_instruction' => t('Testing instructions'),
      'field_clientx_bean_some_instructio' => t('Some instructions'),
      'field_clientx_sel_procedure_descrip' => t('Selection procedure description'),
      'field_clientx_standard_text' => t('Standard text field'),
    ),
    '#default_value' => !empty($conf['field']) ? $conf['field'] : '',
  );

  return $form;
}

/**
 * Puts the conf values in correct place on the form_state object for saving.
 */
function clientx_some_page_bean_tokens_content_type_settings_submit($form, &$form_state) {
  $form_state['conf']['field'] = $form_state['values']['field'];
}

/**
 * Provide content type summary.
 */
function clientx_some_page_bean_tokens_content_type_summary($subtype, $conf, $contexts = NULL) {
  $block = new stdClass();
  $block->title = isset($conf['field']) ? $conf['field'] : t('Not provided');
  $block->content = array(
    '#markup' => t('No info available.'),
  );

  return $block;
}
