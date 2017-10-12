<?php

/**
 * @file
 * Theme include file.
 */

/**
 * Implements hook_theme().
 */
function clientx_offers_theme($existing, $type, $theme, $path) {
  return array(
    'clientx_offers_company_nav_bar' => array(
      'variables' => array(
        'block_vars' => NULL,
      ),
      'template' => 'clientx-offers-company-nav-bar',
      'path' => clientx_OFFERS_MODULE_TEMPLATES_PATH,
    ),
    'clientx_some_page_selection_dates' => array(
      'variables' => array(
        'content' => NULL,
      ),
      'template' => 'clientx-some-page-selection-dates',
      'path' => clientx_OFFERS_MODULE_TEMPLATES_PATH,
    ),
    'clientx_some_page_important_dates' => array(
      'variables' => array(
        'fields' => NULL,
      ),
      'template' => 'clientx-some-page-important-dates',
      'path' => clientx_OFFERS_MODULE_TEMPLATES_PATH,
    ),
    'clientx_company_name' => array(
      'variables' => array(
        'field' => NULL,
      ),
      'template' => 'clientx-company-name',
      'path' => clientx_OFFERS_MODULE_TEMPLATES_PATH,
    ),
    'clientx_some_page_login_button' => array(
      'variables' => array(
        'fields' => NULL,
      ),
      'template' => 'clientx-some-page-login-button',
      'path' => clientx_OFFERS_MODULE_TEMPLATES_PATH,
    ),
    'clientx_some_page_deadline_count' => array(
      'variables' => array(
        'content' => NULL,
      ),
      'template' => 'clientx-some-page-deadline-count',
      'path' => clientx_OFFERS_MODULE_TEMPLATES_PATH,
    ),
    'views_view_field_field_clientx_deadline' => array(
      'variables' => array('view' => NULL, 'field' => NULL, 'row' => NULL),
      'original hook' => 'views_view_field',
    ),
    'views_view_field_field_clientx_open_for_aplication' => array(
      'variables' => array('view' => NULL, 'field' => NULL, 'row' => NULL),
      'original hook' => 'views_view_field',
    ),
    'views_view_field_clientx_offers_et_search_field_clientx_company_id' => array(
      'variables' => array('view' => NULL, 'field' => NULL, 'row' => NULL),
      'original hook' => 'views_view_field',
    ),
  );
}

/**
 * Implements theme_views_view_field() for deadline field on Some search view.
 */
function theme_views_view_field_field_clientx_deadline($variables) {
  $view = $variables['view'];
  $field = $variables['field'];
  $row = $variables['row'];

  $deadline = array();
  switch ($view->name) {
    case 'clientx_offers_et_search':
      $field_clientx_deadline = $row->_entity_properties['entity object']->field_clientx_deadline[LANGUAGE_NONE];
      $deadline = $field_clientx_deadline[0];
      break;

    case 'clientx_offers_related_offers':
      $deadline = $row->field_field_clientx_deadline[0]['raw'];
      break;

    case 'clientx_offers_homepage':
      $node = node_load($row->entity);
      if (!empty($node->field_clientx_deadline[LANGUAGE_NONE][0]['value'])) {
        $deadline = $node->field_clientx_deadline[LANGUAGE_NONE][0];
      }

      break;

  }
  if (isset($deadline['value']) && clientxSomeOffersTools::deadlineIsPermanent($deadline['value'])) {
    return clientxSomeOffersTools::permanentDeadline();
  }
  else {
    return $view->field[$field->options['id']]->advanced_render($row);
  }
}

/**
 * Implements theme_views_view_field().
 *
 * For Company ID field on Some search view.
 */
function theme_views_view_field_clientx_offers_et_search_field_clientx_company_id($variables) {
  $language = i18n_langcode();
  $view = $variables['view'];
  $field = $variables['field'];
  $row = $variables['row'];

  if (isset($row->_entity_properties['entity object']->field_clientx_companys_agencies[LANGUAGE_NONE][0]['target_id'])) {
    $company = node_load($row->_entity_properties['entity object']->field_clientx_companys_agencies[LANGUAGE_NONE][0]['target_id']);
    if (isset($company->field_clientx_company_short_nam[$language][0]['value'])) {
      return $company->field_clientx_company_short_nam[$language][0]['value'];
    }
  }

  return $view->field[$field->options['id']]->advanced_render($row);
}

/**
 * Implements theme_views_view_field().
 *
 * For Open for application field on Some search view.
 */
function theme_views_view_field_field_clientx_open_for_aplication($variables) {
  $view = $variables['view'];
  $field = $variables['field'];
  $row = $variables['row'];

  switch ($view->name) {
    case 'clientx_offers_et_search':
      $markup = clientxSomeOffersTools::openForApplicationFormatter($row->_entity_properties['entity object']);
      break;

    case 'clientx_offers_homepage':
      $node = node_load($row->entity);
      if ($node) {
        $markup = clientxSomeOffersTools::openForApplicationFormatter($node);
      }
      else {
        $markup = $view->field[$field->options['id']]->advanced_render($row);
      }
      break;

    default:
      $markup = $view->field[$field->options['id']]->advanced_render($row);
      break;

  }

  return $markup;
}

/**
 * Implements hook_field_preprocess_field().
 */
function clientx_offers_preprocess_field(&$variables) {
  if (isset($variables['element']['#field_name']) && $variables['element']['#field_name'] == clientxSomeOffers::OPEN_FOR_APLICATION_FIELD) {
    foreach ($variables['items'] as $key => $item) {
      $variables['items'][$key]['#markup'] = clientxSomeOffersTools::openForApplicationFormatter($variables['element']['#object']);
    }
  }
  if (isset($variables['element']['#field_name']) && $variables['element']['#field_name'] == clientxSomeOffers::DEADLINE_FIELD) {
    foreach ($variables['items'] as $key => $item) {
      if (clientxSomeOffersTools::deadlineIsPermanent($variables['element']['#items'][$key]['value'])) {
        $variables['items'][$key]['#markup'] = clientxSomeOffersTools::permanentDeadline();
      }
      else {
        $variables['items'][$key]['#suffix'] = clientxSomeOffersTools::brusselTimeSuffix();
      }
    }
  }
  if (isset($variables['element']['#field_name']) && $variables['element']['#field_name'] == clientxSomeOffers::PUBLICATION_FIELD
      && isset($variables['element']['#object'])
      && $variables['element']['#entity_type'] == 'node'
  ) {
    foreach ($variables['items'] as $key => $item) {
      $variables['items'][$key]['#suffix'] = clientxSomeOffersTools::noticeOfCompetitionLink($variables['element']['#object']);
    }
  }
}
