<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Invoice'),
  'description' => t('E-dos Invoice.'),
  'render callback' => 'invoice_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Order'), 'entity:commerce_order'),
  ),
  'category' => t('Morowiec'),
);

function invoice_content_type_render($subtype, $conf, $panel_args, $context) {
  $data = array();

  $order = $context[0]->data;
  
  if(isset($order->field_invoice_number[LANGUAGE_NONE][0]['value']) && !empty($order->field_invoice_number[LANGUAGE_NONE][0]['value'])){
    $data['number'] = $order->field_invoice_number[LANGUAGE_NONE][0]['value'];
  } else {
    $data['number'] = 'CHANGE ME!';
  }
  $data['status'] = $order->status;
  
  // TODO - zrobić wyliczanie jak jest kilka produktów!
  $line_item = commerce_line_item_load($order->commerce_line_items[LANGUAGE_NONE][0]['line_item_id']);

  $product = commerce_product_load($line_item->commerce_product[LANGUAGE_NONE][0]['product_id']);
  $registrations = registration_load_multiple(FALSE, array('order_id' => $order->order_id));
  
  //ddl(array($order, $line_item, $product, $registrations, $order->order_id));
  
  $billing = commerce_customer_profile_load($order->commerce_customer_billing[LANGUAGE_NONE][0]['profile_id']);
  
  foreach ($registrations as $reg_id => $registration) {
    $data['rows'][] = array(
      'title' => 'Warsztaty dla nauczycieli języka angielskiego: ' . $product->title . ' - '. $registration->field_registration_firstname[LANGUAGE_NONE][0]['value'] . ' '. $registration->field_registration_lastname[LANGUAGE_NONE][0]['value'],
      'qty' => 1,
      'uom' => 'szt.',
      'price' => commerce_currency_amount_to_decimal($line_item->commerce_unit_price[LANGUAGE_NONE][0]['amount'], $order->commerce_order_total[LANGUAGE_NONE][0]['currency_code']),
    );
  }
  if(isset($order->commerce_line_items[LANGUAGE_NONE][1]['line_item_id'])){
    $discount = commerce_line_item_load($order->commerce_line_items[LANGUAGE_NONE][1]['line_item_id']);
    if ($discount->type == 'commerce_discount') {
      $data['rows'][] = array(
        'title' => 'Zniżka dla rejestracji grupowych',
        'qty' => 1,
        'uom' => 'szt.',
        'price' => commerce_currency_amount_to_decimal($discount->commerce_unit_price[LANGUAGE_NONE][0]['amount'], $order->commerce_order_total[LANGUAGE_NONE][0]['currency_code']),
      );      
    }
  }
  //ddl($discount);  
  
  $data['total'] = commerce_currency_amount_to_decimal($order->commerce_order_total[LANGUAGE_NONE][0]['amount'], $order->commerce_order_total[LANGUAGE_NONE][0]['currency_code']);
  $data['billing'] = array(
    'name_line' => $billing->commerce_customer_address[LANGUAGE_NONE][0]['name_line'],
    'thoroughfare' => $billing->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'],
    'postal_code' => $billing->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'],
    'locality' => $billing->commerce_customer_address[LANGUAGE_NONE][0]['locality'],
    'tax_number' => $billing->field_tax_number[LANGUAGE_NONE][0]['value'],
  );

  $content = array(
    '#theme' => 'edos_invoice',
    '#data' => $data,
  );
  $block = new stdClass();
  $block->content = $content;
  
  return $block;
}
