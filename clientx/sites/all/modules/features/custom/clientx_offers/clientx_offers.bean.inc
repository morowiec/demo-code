<?php
/**
 * @file
 * clientx_offers.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function clientx_offers_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'clientx_some_page_info';
  $bean_type->label = 'clientx | Some page | Info';
  $bean_type->options = '';
  $bean_type->description = 'Block with will be used on some pages.';
  $export['clientx_some_page_info'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'clientx_comp_news_standard_t';
  $bean_type->label = 'clientx | Competition news | Standard text';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['clientx_comp_news_standard_t'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'clientx_diagram_step';
  $bean_type->label = 'clientx | Diagram step';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['clientx_diagram_step'] = $bean_type;

  return $export;
}
