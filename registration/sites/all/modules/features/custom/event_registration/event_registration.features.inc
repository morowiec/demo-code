<?php
/**
 * @file
 * event_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_registration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function event_registration_node_info() {
  $items = array(
    'conference' => array(
      'name' => t('Conference'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'conference_event' => array(
      'name' => t('Conference event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function event_registration_default_registration_type() {
  $items = array();
  $items['conference'] = entity_import('registration_type', '{
    "name" : "conference",
    "label" : "Conference",
    "locked" : "0",
    "default_state" : null,
    "weight" : "0",
    "rdf_mapping" : [],
    "data" : { "held_expire" : "1", "held_expire_state" : "canceled" }
  }');
  return $items;
}
