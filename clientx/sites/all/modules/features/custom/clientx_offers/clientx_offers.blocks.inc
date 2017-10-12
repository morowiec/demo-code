<?php

/**
 * @file
 * This file describing custom blocks.
 */

/**
 * Implements hook_block_info().
 */
function clientx_offers_block_info() {
  $blocks['clientx_offers_important_dates'] = array(
    'info' => t('clientx Some Page - Important dates'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  $blocks['clientx_offers_login_button'] = array(
    'info' => t('clientx Some Page - Login button'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  $blocks['clientx_offers_deadline_count'] = array(
    'info' => t('clientx Some Page - Deadline countdown'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  $blocks['clientx_offers_keyword_search'] = array(
    'info' => t('clientx Some search - keyword search exposed filter'),
    'cache' => DRUPAL_CACHE_PER_PAGE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function clientx_offers_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'clientx_offers_important_dates':
      $block['title'] = t('Important dates');
      $block['content'] = _clientx_prepare_important_dates_block_content();
      break;

    case 'clientx_offers_login_button':
      $block['title'] = t('clientx Account');
      $block['content'] = _clientx_prepare_login_button_block_content();
      break;

    case 'clientx_offers_deadline_count':
      $block['title'] = t('Time left to some');
      $block['content'] = _clientx_prepare_deadline_count_block_content();
      break;

    case 'clientx_offers_keyword_search':
      $block['content'] = _clientx_prepare_keyword_search_block_content();
      break;
  }
  return $block;
}

/**
 * Create the related faqs block content.
 */
function _clientx_prepare_important_dates_block_content() {
  // Loading node object.
  $node = node_load(arg(3));
  if (!$node) {
    // Node not found - hide block.
    return FALSE;
  }

  $fields = [];
  $application_phases = clientxSomeOffersTools::getNumberApplicationPhases($node);

  // Add open for application date.
  $open_for_aplication = field_get_items('node', $node, clientxSomeOffers::OPEN_FOR_APLICATION_FIELD);
  if (isset($open_for_aplication[0]['value'])) {
    $fields['open_for_aplication'] = [
      'label' => ($application_phases == 1) ? t('Application open') : t('Application open - first part'),
      'value' => clientxSomeOffersTools::openForApplicationFormatter($node),
    ];
  }

  // Add deadline date.
  $deadline = field_get_items('node', $node, clientxSomeOffers::DEADLINE_FIELD);
  $now = time();
  if (isset($deadline[0]['value']) || $deadline[0]['value'] >= $now) {
    $fields['deadline'] = [
      'label' => ($application_phases == 1) ? t('Deadline for application') : t('Deadline for application - first part'),
      'value' => clientxSomeOffersTools::deadlineDateFormatter($deadline[0]['value']),
    ];
    // Get variable for deadline switch. Variable created via hook_update_N.
    $deadline_switch_period = variable_get('clientx_deadline_switch_period');
    $left = floor((($deadline[0]['value'] - $now) / $deadline_switch_period));
    $upcoming = field_get_items('node', $node, clientxSomeOffers::UPCOMING_FIELD);

    if ($left < 3 && $left >= 0) {
      // Less then 3 day - red text color.
      $fields['deadline']['value'] = theme('html_tag', [
        'element' => [
          '#tag' => 'span',
          '#attributes' => ['class' => 'clientx-red'],
          '#value' => $fields['deadline']['value'],
        ],
      ]);
    }
    elseif ($upcoming[0]['value'] == 0 && !clientxSomeOffersTools::deadlineIsPermanent($deadline[0]['value'])) {
      // Add how many Day(s) left for application.
      // Hidden for upcoming phase and when is no deadline.
      $fields['deadline_left'] = [
        'label' => t('Day(s) left for application'),
        'value' => $left,
      ];
    }
  }

  $deadline_for_question = field_get_items('node', $node, clientxSomeOffers::DEADLINE_FOR_QUESTION_FIELD);
  if (isset($deadline_for_question[0]['value'])) {
    $fields['deadline_for_question'] = [
      'label' => t('Deadline for questions'),
      'value' => format_date($deadline_for_question[0]['value'], 'clientx_short_date_only'),
    ];
  }

  $open_for_aplication2 = field_get_items('node', $node, clientxSomeOffers::OPEN_FOR_APLICATION_FIELD2);
  $open_for_aplication2_confirmed = field_get_items('node', $node, clientxSomeOffers::OPEN_FOR_APLICATION_FIELD2_CONFIRMED);
  if (isset($open_for_aplication2[0]['value'])) {
    $fields['open_for_aplication2'] = [
      'label' => t('Application open - second part'),
      'value' => clientxSomeOffersTools::formatTimelineDate($open_for_aplication2, $open_for_aplication2_confirmed),
    ];
  }

  $deadline2 = field_get_items('node', $node, clientxSomeOffers::DEADLINE_FIELD2);
  $deadline2_confirmed = field_get_items('node', $node, clientxSomeOffers::DEADLINE_FIELD2_CONFIRMED);
  if (isset($deadline2[0]['value'])) {
    $fields['deadline2'] = [
      'label' => t('Deadline for application - second part'),
      'value' => clientxSomeOffersTools::formatTimelineDate($deadline2, $deadline2_confirmed, TRUE),
    ];
  }

  if (!$fields) {
    // No important dates found - hide block.
    return FALSE;
  }

  return [
    '#theme' => 'clientx_some_page_important_dates',
    '#fields' => $fields,
  ];
}

/**
 * Deadline block.
 */
function _clientx_prepare_deadline_count_block_content() {
  // Loading node object.
  $node = node_load(arg(3));
  if (!$node) {
    // Node not found.
    return FALSE;
  }
  $deadline = field_get_items('node', $node, clientxSomeOffers::DEADLINE_FIELD);
  $now = time();
  if (isset($deadline[0]['value']) && $deadline[0]['value'] >= $now) {
    // Get variable for deadline switch. Variable created via hook_update_N.
    $deadline_switch_period = variable_get('clientx_deadline_switch_period');
    $left = floor((($deadline[0]['value'] - $now) / $deadline_switch_period));
    if ($left >= 3) {
      return FALSE;
    }
    else {
      $timezone = new DateTimeZone(date_default_timezone());
      $offset = $timezone->getOffset(new DateTime()) / 3600;
      $options = array(
        'until' => date("F d, Y g:i a", $deadline[0]['value']),
        'format' => 'DHMS',
        'timezone' => $offset,
      );
      $content = theme('jquery_countdown', array('id' => 'deadline_count', 'options' => $options));
    }
  }
  else {
    return FALSE;
  }

  return array(
    '#content' => $content,
    '#theme' => 'clientx_some_page_deadline_count',
  );
}

/**
 * Create the login button.
 */
function _clientx_prepare_login_button_block_content() {
  // Loading node object.
  $node = node_load(arg(3));
  if (!$node) {
    // Node not found.
    return FALSE;
  }
  // Get value of upcoming field.
  $upcoming = field_get_items('node', $node, clientxSomeOffers::UPCOMING_FIELD);
  if (!empty($upcoming) && $upcoming[0]['value'] == 1) {
    // Hide block for upcoming comp/CASTING.
    return FALSE;
  }

  return array(
    '#theme' => 'clientx_some_page_login_button',
  );
}

/**
 * Render exposed filter form.
 */
function _clientx_prepare_keyword_search_block_content() {
  $view = views_get_view('clientx_offers_et_search');
  $view->set_display('advanced');
  $view->init_handlers();
  $exposed_form_state = array(
    'view' => &$view,
    'display' => &$view->display['advanced'],
    'exposed_form_plugin' => $view->display_handler->get_plugin('exposed_form'),
    'method' => 'get',
    'rerender' => TRUE,
    'no_redirect' => TRUE,
    'always_process' => TRUE,
  );

  // Remove unused fields.
  $form = drupal_build_form('views_exposed_form', $exposed_form_state);
  unset($form['#info']['filter-field_clientx_type_of_contract']);
  $form['contract']['#access'] = FALSE;
  unset($form['#info']['filter-field_clientx_grade']);
  $form['grade']['#access'] = FALSE;
  unset($form['#info']['filter-field_clientx_locations_parent']);
  $form['location']['#access'] = FALSE;
  unset($form['#info']['filter-field_clientx_company_id']);
  $form['company']['#access'] = FALSE;

  $form['#action'] = url(clientxSomeOffers::SOME_OFFERS_PATH);
  return drupal_render($form);
}
