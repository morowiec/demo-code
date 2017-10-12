<?php

/**
 * @file
 * clientx | Some page more link content type plugin.
 */

$plugin = array(
  'title' => t('clientx | Offers | Some page more link'),
  'single' => TRUE,
  'category' => t('clientx | Offers'),
  'render callback' => 'clientx_some_page_more_link_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render callback.
 */
function clientx_some_page_more_link_content_type_render($subtype, $conf, $panel_args, $context) {
  $some_page_type = taxonomy_term_load($context[0]->data->field_clientx_some_page_type[LANGUAGE_NONE][0]['target_id']);
  $path = clientxSomeOffers::SOME_OFFERS_PATH . '/' . drupal_strtolower($some_page_type->name) . '/' . $context[0]->data->nid . '/description';

  // Link to description some page.
  $button = theme('link',
    array(
      'text' => t('More information'),
      'path' => $path,
      'options' => array(
        'attributes' => array(
          'class' => array('btn', 'btn-default', 'btn-clientx'),
        ),
        'html' => TRUE,
      ),
    )
  );

  // Markup.
  $block_content = array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array('clientx-some-page-more-info'),
      ),
      '#value' => $button,
    ),
  );

  $block = new stdClass();
  $block->content = theme('html_tag', $block_content);
  return $block;
}
