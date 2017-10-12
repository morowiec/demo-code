<?php

/**
 * @file
 * clientx | Some page Selection procedure dates content type plugin.
 */

$plugin = array(
  'title' => t('clientx | Offers | Testing maintenance'),
  'single' => TRUE,
  'category' => t('clientx | Offers'),
  'render callback' => 'clientx_Testing_maintenance_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render callback.
 */
function clientx_Testing_maintenance_content_type_render($subtype, $conf, $panel_args, $context) {
  $node = $context[0]->data;
  $block = new stdClass();
  $maintenance_dates = field_get_items('node', $node, 'field_clientx_Testing_off_dates');

  if (!empty($maintenance_dates[0]['value']) && !empty($maintenance_dates[0]['value2'])) {
    $date = format_date($maintenance_dates[0]['value'], 'short') . clientxSomeOffersTools::brusselTimeSuffix();
    $date2 = format_date($maintenance_dates[0]['value2'], 'short') . clientxSomeOffersTools::brusselTimeSuffix();
    $block_content = array(
      'element' => array(
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array('clientx-red clientx-bold'),
        ),
        '#value' => t('Unavailable from !date to !date2.', array('!date' => $date, '!date2' => $date2)),
      ),
    );
    $block->content = theme('html_tag', $block_content);
  }
  return $block;
}
