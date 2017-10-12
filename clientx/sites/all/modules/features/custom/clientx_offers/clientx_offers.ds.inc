<?php
/**
 * @file
 * clientx_offers.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function clientx_offers_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'clientx_diagram';
  $ds_view_mode->label = 'clientx | Diagram';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['clientx_diagram'] = $ds_view_mode;

  return $export;
}
