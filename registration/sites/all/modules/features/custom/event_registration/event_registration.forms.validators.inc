<?php

/* 
 * Event registration validators.
 */

/**
 * Validate email adress.
 */
function _event_registration_validate_email($form, &$form_state) {
  $commands = array();

  $validation = _event_registration_validate_email_check($form['user_data']['email']['#value']);
  if ($validation['status']) {
    $commands[] = ajax_command_invoke('#edit-email', 'removeClass', array('error'));
  }
  else {
    $commands[] = ajax_command_invoke('#edit-email', 'addClass', array('error'));
  }
  // Show message.
  $commands[] = ajax_command_html('#email-error', $validation['msg']);

  return array('#type' => 'ajax', '#commands' => $commands);
}
/**
 * Validate email adress.
 */
function _event_registration_validate_participant_email($form, &$form_state) {
  $commands = array();
  
  // TODO: wrzucić do zenętrznej funckji.
  $value = $form['email']['#value'];
  if (empty($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Field is reqired.'),
    );
  }
  else if (!valid_email_address($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Email adress is invalid.'),
    );
  }
  else {
    $result = array(
      'status' => TRUE,
      'msg' => FALSE,
    );
  }

  $validation = $result;
  if ($validation['status']) {
    $commands[] = ajax_command_invoke('#edit-email', 'removeClass', array('error'));
  }
  else {
    $commands[] = ajax_command_invoke('#edit-email', 'addClass', array('error'));
  }
  // Show message.
  $commands[] = ajax_command_html('#email-error', $validation['msg']);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate last name is not empty.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _event_registration_validate_lastname($form, &$form_state) {
  $commands = array();
  if (!isset($form['user_data']['lastname']['#value']) || empty($form['user_data']['lastname']['#value'])) {
    $form['user_data']['lastname']['#children'] = '<div class="messages error messages-inline">This is an error.</div>';
    $tmp = drupal_render($form['user_data']['lastname']);
    //ddl($tmp);
    $commands[] = ajax_command_replace('#registration-lastname', $tmp);
    //$commands[] = ajax_command_html('#lastname-error', t('Field is reqired.'));
    //$commands[] = ajax_command_invoke('#edit-lastname', 'addClass', array('error'));
  }
  else {
    $commands[] = ajax_command_html('#lastname-error', FALSE);
    $commands[] = ajax_command_invoke('#edit-lastname', 'removeClass', array('error'));
  }
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate last name is not empty.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _event_registration_validate_firstname($form, &$form_state) {
  $commands = array();
  if (!isset($form['user_data']['firstname']['#value']) || empty($form['user_data']['firstname']['#value'])) {
    $commands[] = ajax_command_html('#firstname-error', t('Field is reqired.'));
    $commands[] = ajax_command_invoke('#edit-firstname', 'addClass', array('error'));
  }
  else {
    $commands[] = ajax_command_html('#lastname-error', FALSE);
    $commands[] = ajax_command_invoke('#edit-firstname', 'removeClass', array('error'));
  }
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate Password1.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _event_registration_validate_password1($form, &$form_state) {
  $validation = _event_registration_validate_password1_check($form['password1']['#value']);
  if ($validation['status']) {
    $commands[] = ajax_command_invoke('#edit-password1', 'removeClass', array('error'));
  }
  else {
    $commands[] = ajax_command_invoke('#edit-password1', 'addClass', array('error'));
  }
  // Show message.
  $commands[] = ajax_command_html('#password1-error', $validation['msg']);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate Password2.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _event_registration_validate_password2($form, &$form_state) {
  $validation = _event_registration_validate_password2_check($form['password2']['#value'], $form['password1']['#value']);
  if ($validation['status']) {
    $commands[] = ajax_command_invoke('#edit-password2', 'removeClass', array('error'));
  }
  else {
    $commands[] = ajax_command_invoke('#edit-password2', 'addClass', array('error'));
  }
  // Show message.
  $commands[] = ajax_command_html('#password2-error', $validation['msg']);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate postcode.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _event_registration_validate_postcode($form, &$form_state) {
  $validation = _event_registration_validate_postcode_check($form['invoice_data']['fields']['postcode']['#value']);
  if ($validation['status']) {
    $commands[] = ajax_command_invoke('#edit-invoice-data-fields-postcode', 'removeClass', array('error'));
  }
  else {
    $commands[] = ajax_command_invoke('#edit-invoice-data-fields-postcode', 'addClass', array('error'));
  }
  // Show message.
  $commands[] = ajax_command_html('#postcode-error', $validation['msg']);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate tax number.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _event_registration_validate_tax_number($form, &$form_state) {
  $validation = _event_registration_validate_tax_number_check($form['invoice_data']['fields']['tax_number']['#value']);
  if ($validation['status']) {
    $commands[] = ajax_command_invoke('#edit-invoice-data-fields-tax-number', 'removeClass', array('error'));
  }
  else {
    $commands[] = ajax_command_invoke('#edit-invoice-data-fields-tax-number', 'addClass', array('error'));
  }
  // Show message.
  $commands[] = ajax_command_html('#tax-number-error', $validation['msg']);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Validate email adress.
 */
function _event_registration_validate_email_check($value) {
    $result = array(
      'status' => TRUE,
      'msg' => FALSE,
    );

    if (empty($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Field is reqired.'),
    );
  }
  else if (!valid_email_address($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Email adress is invalid.'),
    );
  }
  else {
    $user = user_load_by_mail($value);
    if ($user) {
      $result = array(
        'status' => FALSE,
        'msg' => t('User exists. Click !link to log in.', array('!link' => l('here', 'user'))),
      );
    }
  }
  return $result;
}

function _event_registration_validate_tax_number_check($value) {
  if (empty($value)) {
    return array(
      'status' => FALSE,
      'msg' => t('Tax number is reqired.'),
    );
  }

  $str = preg_replace("/[^0-9]+/", "", $value);

  if (strlen($str) != 10) {
    return array(
      'status' => FALSE,
      'msg' => t('Tax number is too short.'),
    );
  }

  $arrSteps = array(6, 5, 7, 2, 3, 4, 5, 6, 7);
  $intSum = 0;
  for ($i = 0; $i < 9; $i++) {
    $intSum += $arrSteps[$i] * $str[$i];
  }
  $int = $intSum % 11;

  $intControlNr = ($int == 10) ? 0 : $int;
  if ($intControlNr == $str[9]) {
    return array(
      'status' => TRUE,
      'msg' => FALSE,
    );
  }

  return array(
    'status' => FALSE,
    'msg' => t('Tax number is invalid.'),
  );
}

function _event_registration_validate_postcode_check($value) {
  if (empty($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Field is reqired.'),
    );
  }
  else if (preg_match("/^([0-9]{2})(-[0-9]{3})?$/i", $value)) {
    $result = array(
      'status' => TRUE,
      'msg' => FALSE,
    );
  }
  else {
    $result = array(
      'status' => FALSE,
      'msg' => t('Postcode is invalid.'),
    );
  }
  return $result;
}

function _event_registration_validate_password1_check($value) {
  if (empty($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Field is reqired.'),
    );
  }
  else if (strlen($value) >= 8) {
    $result = array(
      'status' => TRUE,
      'msg' => FALSE,
    );
  }
  else {
    $result = array(
      'status' => FALSE,
      'msg' => t('First password is invalid.'),
    );
  }
  return $result;
}

function _event_registration_validate_password2_check($value, $value2) {
  if (empty($value)) {
    $result = array(
      'status' => FALSE,
      'msg' => t('Field is reqired.'),
    );
  }
  else if ($value == $value2) {
    $result = array(
      'status' => TRUE,
      'msg' => FALSE,
    );
  }
  else {
    $result = array(
      'status' => FALSE,
      'msg' => t('Second password is different.'),
    );
  }
  return $result;
}