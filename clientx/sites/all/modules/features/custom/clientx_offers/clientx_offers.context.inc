<?php
/**
 * @file
 * clientx_offers.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function clientx_offers_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clientx_aaa_menu_selection';
  $context->description = 'Some offer selected item for Some menu.';
  $context->tag = 'clientx | Some search';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'clientx_some_page' => 'clientx_some_page',
        'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
        'clientx_offers' => 'clientx_offers',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'some' => 'some',
        'some/offers' => 'some/offers',
        'some/offers/*' => 'some/offers/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-clientx-some' => array(
          'module' => 'menu',
          'delta' => 'menu-clientx-some',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('clientx | Some search');
  t('Some offer selected item for Some menu.');
  $export['clientx_aaa_menu_selection'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clientx_offers_some_page_important_dates';
  $context->description = '';
  $context->tag = 'clientx | Some page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'some/offers/casting/*/*' => 'some/offers/casting/*/*',
        'some/offers/comp/*/*' => 'some/offers/comp/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'clientx_offers-clientx_offers_important_dates' => array(
          'module' => 'clientx_offers',
          'delta' => 'clientx_offers_important_dates',
          'region' => 'sidebar_right',
          'weight' => '-6',
        ),
        'clientx_offers-clientx_offers_deadline_count' => array(
          'module' => 'clientx_offers',
          'delta' => 'clientx_offers_deadline_count',
          'region' => 'sidebar_right',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('clientx | Some page');
  $export['clientx_offers_some_page_important_dates'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clientx_offers_some_page_login_button';
  $context->description = '';
  $context->tag = 'clientx | Some page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'some/offers/casting/*/*' => 'some/offers/casting/*/*',
        'some/offers/comp/*/*' => 'some/offers/comp/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'clientx_offers-clientx_offers_login_button' => array(
          'module' => 'clientx_offers',
          'delta' => 'clientx_offers_login_button',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('clientx | Some page');
  $export['clientx_offers_some_page_login_button'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'clientx_related_aaa_offer';
  $context->description = 'Related aaa offer in right sidebar';
  $context->tag = 'clientx | Some search';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'clientx_offers' => 'clientx_offers',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-clientx_related_aaa_offer-block' => array(
          'module' => 'views',
          'delta' => 'clientx_related_aaa_offer-block',
          'region' => 'sidebar_right',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('clientx | Some search');
  t('Related aaa offer in right sidebar');
  $export['clientx_related_aaa_offer'] = $context;

  return $export;
}
