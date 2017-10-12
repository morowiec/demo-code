<?php

/**
 * @file
 * Company/Agency name content type plugin.
 */

$plugin = array(
  'title' => t('clientx | Offers | Company name from Company ID'),
  'single' => TRUE,
  'category' => t('clientx | Offers'),
  'render callback' => 'clientx_offers_company_name_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render callback.
 */
function clientx_offers_company_name_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = $context[0]->data;
  $company_id = field_get_items('node', $node, 'field_clientx_company_id');

  if (isset($company_id[0]['target_id'])) {

    $company = _clientx_offers_get_company_from_id($company_id[0]['target_id']);

    if ($company) {
      $block = new stdClass();
      $block->content = _clientx_offers_theme_company($company);
      return $block;
    }
  }
}

/**
 * Return Company name or Company ID.
 */
function _clientx_offers_get_company_from_id($tid) {
  global $language;

  $node = clientxSomeOffersTools::getCompanyNodeFromId($tid, $language->language);
  $title = field_get_items('node', $node, 'title_field');

  if ($node) {
    $company = array(
      'title' => $title[0]['value'],
      'url' => $node->path['source'],
    );
    return $company;
  }
  else {
    $term = taxonomy_term_load($tid);
    if ($term) {
      $company = array(
        'title' => $term->name,
      );
      return $company;
    }
  }

  return FALSE;
}

/**
 * Helper function for theming company name or ID.
 */
function _clientx_offers_theme_company($company) {
  $field = array(
    'label' => t('Company/Agency'),
    'items' => array(),
    'classes_array' => array(
      'field',
      'field-name-field-companys-and-agencies',
      'field-type-entityreference',
      'field-label-inline',
      'clearfix',
    ),
    'classes' => 'field field-name-field-companys-and-agencies field-type-entityreference field-label-inline clearfix',
    'theme_hook_original' => 'field',
    'label_hidden' => FALSE,
    'attributes' => '',
    'title_attributes' => '',
    'content_attributes' => '',
    'item_attributes' => array('0' => ''),
  );

  if (isset($company['url'])) {
    // Display as link to Company/Agency node.
    $field['items'][0] = array(
      '#type' => 'link',
      '#title' => $company['title'],
      '#href' => $company['url'],
    );
  }
  else {
    // Display as a Company ID.
    $field['items'][0] = array(
      '#markup' => $company['title'],
    );
  }

  return array(
    '#theme' => 'clientx_company_name',
    '#field' => $field,
  );
}
