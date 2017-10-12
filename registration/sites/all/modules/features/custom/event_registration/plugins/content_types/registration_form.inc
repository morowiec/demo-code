<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Registration form'),
  'description' => t('Registration form.'),
  'render callback' => 'registration_form_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Event'), 'entity:commerce_product'),
    new ctools_context_optional(t('User'), 'user'),
  ),
  'category' => t('Morowiec'),
);

function registration_form_content_type_render($subtype, $conf, $panel_args, $context) {
  //ddl($context);
  $form = drupal_get_form('event_registration_form');
  // Setup product ID.
  $form['product_id']['#value'] = $context[0]->argument;
  $product = $context[0]->data;
  $product->commerce_price['und'][0]['amount'];
  //ddl($form);  
  $price = commerce_currency_amount_to_decimal($product->commerce_price['und'][0]['amount'], $product->commerce_price['und'][0]['currency_code']) . ' ' . $product->commerce_price['und'][0]['currency_code'];
  if (isset($form['accepted_agreement']['#title'])) {
    $form['accepted_agreement']['#title'] = t('I confirm that I have read and accepted the !link and I agree to be invoiced with the amount of <strong>@price</strong>', array('@price' => $price, '!link' => l('Terms of agreement', 'http://e-dos.org/regulamin', array('attributes' => array('target' => '_blank')))));
  }

  //ddl(array('registration_form_content_type_render',$form));
  $block = new stdClass();
  $block->title = t('Registration form');
  $block->content = '<p><span style="color: #ff0000;"><strong>Registration fee: ' . $price . '</strong></span></p>';
  $block->content .= render($form);

  return $block;
}
