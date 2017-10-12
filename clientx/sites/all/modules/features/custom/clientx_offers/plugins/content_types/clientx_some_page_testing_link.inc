<?php

/**
 * @file
 * clientx | Some page Selection procedure dates content type plugin.
 */

$plugin = array(
  'title' => t('clientx | Offers | Testing link'),
  'single' => TRUE,
  'category' => t('clientx | Offers'),
  'render callback' => 'clientx_some_page_Testing_link_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render callback.
 */
function clientx_some_page_Testing_link_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = $context[0]->data;
  $block = new stdClass();
  $buttons = '';

  foreach ($node->field_clientx_Testing_tests[LANGUAGE_NONE] as $link) {
    $buttons .= theme('link',
      array(
        'text' => $link['title'],
        'path' => $link['url'],
        'options' => array(
          'attributes' => array(
            'class' => array(
              'btn',
              'btn-default',
              'btn-clientx',
              'btn-clientx-Testing',
            ),
          ),
          'html' => FALSE,
        ),
      )
    );
  }

  $block_content = array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array('text-center'),
      ),
      '#value' => $buttons,
    ),
  );

  $block->content = theme('html_tag', $block_content);
  return $block;
}
