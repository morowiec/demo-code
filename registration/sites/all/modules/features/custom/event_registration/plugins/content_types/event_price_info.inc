<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Event price info'),
  'description' => t('Info about conference fee.'),
  'render callback' => 'event_price_info_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Event'), 'entity:commerce_product'),
  ),
  'category' => t('Morowiec'),
);

function event_price_info_content_type_render($subtype, $conf, $panel_args, $context) {
  //ddl($context);

  // Setup product ID.
  $form['product_id']['#value'] = $context[0]->argument;
  $product = $context[0]->data;

  $price = commerce_currency_amount_to_decimal($product->commerce_price['und'][0]['amount'], $product->commerce_price['und'][0]['currency_code']) . ' ' . $product->commerce_price['und'][0]['currency_code'];

  $block = new stdClass();
  $block->content = '<p style="color:#FF0000; font-size:1.1em; font-weight:bold">' . t('Registration fee: @price', array('@price' => $price)) . '</p>';

  return $block;
}
