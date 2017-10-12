<?php

/**
 * Library:
 * http://internetdevels.com/blog/ctools-modal-api
 * http://dominiquedecooman.com/blog/drupal-7-using-ctools-modal-frames-and-field-collection-forms-create-better-user-experience
 * https://rapiddg.com/blog/use-ajax-support-multiple-item-values-custom-drupal-7-forms
 */

/**
 * Event registration form.
 *
 * @param type $form
 * @param type $form_submit
 * @return string
 */
//function event_registration_form($form, &$form_submit) {
function event_registration_form($form, &$form_state) {
  // Set default number of participants
  drupal_session_start();
  global $user;
  //ddl($user);
  if (user_is_logged_in()) {
    $profile2 = profile2_load_by_user($user);
    //ddl($profile2);
    if (isset($profile2['individual'])) {
      $firstname = $profile2['individual']->field_firstname[LANGUAGE_NONE][0]['safe_value'];
      $lastname = $profile2['individual']->field_lastname[LANGUAGE_NONE][0]['safe_value'];
    }
    else {
      $firstname = '';
      $lastname = '';
    }
  }
  else {
    $firstname = '';
    $lastname = '';
  }

  if (!isset($_SESSION['participants']['count'])) {
    $_SESSION['participants']['count'] = 1;
  }
  if (!isset($_SESSION['participants']['remove'])) {
    $_SESSION['participants']['remove'] = array();
  }

  if (!user_is_logged_in()) {
    $form['registration_type'] = array(
      '#title' => t('Registration type'),
      '#type' => 'radios',
      '#options' => array('single' => t('single'), 'group' => t('group')),
      '#default_value' => 'single',
      '#required' => TRUE,
      '#description' => t('<strong>PLEASE NOTE!</strong> Only one invoice per 1 registration can be issued.'),
      '#ajax' => array(
        'callback' => '_event_registration_type_switch',
      ),
    );
  }
  $form['user_data'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#prefix' => '<div id="user_data">',
    '#suffix' => '</div>',
  );
  if (!user_is_logged_in()) {    
    $form['user_data']['email'] = array(
      '#title' => t('Email'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#ajax' => array(
        'callback' => '_event_registration_validate_email',
        'effect' => 'fade',
      ),
      '#suffix' => '<div id="email-error" class="red"></div>',
      '#description' => t('Your confirmation message will be sent to this address. Use it to log in in the future'),
    );
  }
  $form['user_data']['lastname'] = array(
    '#id' => 'registration-lastname',
    '#title' => t('Last name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => '_event_registration_validate_lastname',
      'effect' => 'fade',
    ),
    '#default_value' => $lastname,
    '#suffix' => '<div id="lastname-error" class="red"></div>',
    '#description' => t('Please give us your last name.'),
  );
  $form['user_data']['firstname'] = array(
    '#title' => t('First name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => '_event_registration_validate_firstname',
      'effect' => 'fade',
    ),
    '#default_value' => $firstname,
    '#suffix' => '<div id="firstname-error" class="red"></div>',
    '#description' => t('Please give us your first name.'),
  );
  if (!user_is_logged_in()) {  
    $form['password1'] = array(
      '#title' => t('Password'),
      '#type' => 'password',
      '#required' => TRUE,
      '#ajax' => array(
        'callback' => '_event_registration_validate_password1',
        'effect' => 'fade',
      ),
      '#suffix' => '<div id="password1-error" class="red"></div>',
      '#description' => t('Any combination of at least 8 letters or digits'),
    );
    $form['password2'] = array(
      '#title' => t('Repeat password'),
      '#type' => 'password',
      '#required' => TRUE,
      '#ajax' => array(
        'callback' => '_event_registration_validate_password2',
        'effect' => 'fade',
      ),
      '#suffix' => '<div id="password2-error" class="red"></div>',
      '#description' => t('The password must be exactly the same as above'),
    );
  }
  $form['institution'] = array(
    '#title' => t('Institution'),
    '#type' => 'textfield',
    '#required' => FALSE,
    '#description' => t('Optional.'),
  );
  $form['phone'] = array(
    '#title' => t('Phone'),
    '#type' => 'textfield',
    '#required' => FALSE,
    '#description' => t('Optional. It will be used only to contact You about your registration'),
  );

  $form['participants'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
    '#prefix' => '<div id="participants">',
    '#suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name=registration_type]' => array('value' => 'group'),
      ),
    ),
    '#description' => t('If you register a group of participants, please ensure to include e-mail addresses of <strong>EACH person!</strong> This will allow us to send any necessary reminders or contact participants in an unlikely event of event cancellation, room change etc.'),
  );
  if (isset($form_state['triggering_element']['#name'])) {
    if ($form_state['triggering_element']['#name'] == 'add_participant') {
      $_SESSION['participants']['count'] ++;
    }
    if (preg_match('/participants\[(\d+)\]\[cancel\]/', $form_state['triggering_element']['#name'])) {
      preg_match_all('/participants\[(?P<digits>\d+)\]\[cancel\]/', $form_state['triggering_element']['#name'], $matches);
      $i = $matches['digits'][0];
      $_SESSION['participants']['remove'][] = $i;
      //ddl($_SESSION['participants']);
    }
  }

  if ($_SESSION['participants']['count'] > 0) {
    $part_num = 0;
    $count = $_SESSION['participants']['count'];
    for ($i = 1; $i <= $count; $i++) {
      if (is_array($_SESSION['participants']['remove']) && in_array($i, $_SESSION['participants']['remove'])) {
        $_SESSION['participants']['count'] --;
        //ddl($_SESSION['participants']['count']);
        continue;
      }
      $part_num++;
      $form['participants'][$i] = array(
        '#type' => 'fieldset',
        '#title' => t('Participant @key', array('@key' => $part_num)),
        '#tree' => TRUE,
        '#prefix' => '<div id="participants-' . $i . '" class="participant">',
        '#suffix' => '</div>',
      );
      $form['participants'][$i]['lastname'] = array(
        '#id' => 'participants-' . $i . '-lastname',
        '#title' => t('Last name'),
        '#type' => 'textfield',
        '#required' => TRUE,
//        '#ajax' => array(
//          'callback' => '_event_registration_validate_lastname',
//          'effect' => 'fade',
//        ),
        '#suffix' => '<div id="lastname-error" class="red"></div>',
        '#description' => t('Please give us participant last name.'),
      );
      $form['participants'][$i]['firstname'] = array(
        '#id' => 'participants-' . $i . '-firstname',
        '#title' => t('First name'),
        '#type' => 'textfield',
        '#required' => TRUE,
//        '#ajax' => array(
//          'callback' => '_event_registration_validate_firstname',
//          'effect' => 'fade',
//        ),
        '#suffix' => '<div id="firstname-error" class="red"></div>',
        '#description' => t('Please give us participant first name.'),
      );
      $form['participants'][$i]['email'] = array(
        '#id' => 'participants-' . $i . '-email',
        '#title' => t('Email'),
        '#type' => 'textfield',
        '#required' => TRUE,
        '#description' => t('This email adress will allow us to send any necessary reminders or contact participants in an unlikely event of event cancellation, room change etc.'),
      );
      $form['participants'][$i]['cancel'] = array(
        '#type' => 'button', // Don't change this!
        '#attributes' => array('class' => array('participantsCancel')),
        '#value' => t('Cancel'),
        '#name' => 'participants[' . $i . '][cancel]',
        '#href' => '',
        '#ajax' => array(
          'callback' => '_event_registration_participant_cancel',
        ),
        '#prefix' => '<div class="cancel">',
        '#suffix' => '</div>',
      );
    }
    // Reset keys.
    //ddl(array('participants', $form['participants']));
    //$form['participants'] = array_values($form['participants']);
    $_SESSION['participants']['remove'] = array();
  }

  $form['add_participant'] = array(
    '#type' => 'button',
    '#attributes' => array('class' => array('addParticipantBtn')),
    '#value' => t('Add another participant'),
    '#name' => 'add_participant',
    '#ajax' => array(
      'callback' => '_event_registration_add_participant',
    ),
    '#prefix' => '<div id="addParticipantBox" class="add-participant">',
    '#suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name=registration_type]' => array('value' => 'group'),
      ),
    ),
  );
  $form['invoice'] = array(
    '#title' => t('Invoice'),
    '#type' => 'radios',
    '#options' => array('yes' => t('Yes'), 'no' => t('No')),
    '#required' => TRUE,
  );
  $form['invoice_data'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#prefix' => '<div id="invoice_data">',
    '#suffix' => '</div>',
    '#states' => array(
      'visible' => array(
        ':input[name=invoice]' => array('value' => 'yes'),
      ),
    ),
  );
  $form['invoice_data']['fields']['company'] = array(
    '#title' => t('Company'),
    '#type' => 'textfield',
    '#states' => array(
      'required' => array(
        ':input[name=invoice]' => array('value' => 'yes'),
      ),
    ),
  );
  $form['invoice_data']['fields']['street'] = array(
    '#title' => t('Street'),
    '#type' => 'textfield',
    '#states' => array(
      'required' => array(
        ':input[name=invoice]' => array('value' => 'yes'),
      ),
    ),
  );
  $form['invoice_data']['fields']['postcode'] = array(
    '#title' => t('Postcode'),
    '#type' => 'textfield',
    '#states' => array(
      'required' => array(
        ':input[name=invoice]' => array('value' => 'yes'),
      ),
    ),
    '#ajax' => array(
      'callback' => '_event_registration_validate_postcode',
      'effect' => 'fade',
    ),
    '#suffix' => '<div id="postcode-error" class="red"></div>',
    '#description' => t('correct format: XX-XXX'),
  );
  $form['invoice_data']['fields']['city'] = array(
    '#title' => t('City'),
    '#type' => 'textfield',
    '#states' => array(
      'required' => array(
        ':input[name=invoice]' => array('value' => 'yes'),
      ),
    ),
  );
  $form['invoice_data']['fields']['tax_number'] = array(
    '#title' => t('NIP'),
    '#type' => 'textfield',
    '#states' => array(
      'required' => array(
        ':input[name=invoice]' => array('value' => 'yes'),
      ),
    ),
    '#ajax' => array(
      'callback' => '_event_registration_validate_tax_number',
      'effect' => 'fade',
    ),
    '#suffix' => '<div id="tax-number-error" class="red"></div>',
    '#description' => t('correct format: XXX-XXX-XX-XX, XXX-XX-XX-XXX or XXXXXXXXXX'),
  );
  $form['comments'] = array(
    '#title' => t('Additional comments'),
    '#type' => 'textarea',
    '#required' => FALSE,
  );
  if (!user_is_logged_in()) {
    $form['accepted_agreement'] = array(
      '#title' => t('I confirm that I have read and accepted the Terms of agreement.'),
      '#type' => 'checkbox',
      '#required' => TRUE,
    );
    $form['accepted_data_storage'] = array(
      '#title' => t('I agree to have my personal data stored, processed and used ' .
          'in order to carry out the registration process, in accordance with ' .
          'the personal data protection act of 29 Aug 1997 [Dz. U. nr 133 poz. 883].'),
      '#type' => 'checkbox',
      '#required' => TRUE,
    );
  }
  $form['product_id'] = array(
    '#type' => 'hidden',
  );
  $form['submit'] = array(
    '#value' => 'Submit',
    '#type' => 'submit',
  );
  $form['#after_build'][] = 'event_registration_form_after_build';

  //ddl($form);
  return $form;
}

function event_registration_form_after_build($form, &$form_state) {
  global $user;
  if (user_is_logged_in()) {
//    $form['registration_type']['#access'] = FALSE;
//    $form['user_data']['email']['#access'] = FALSE;
//    $form['registration_type']['#access'] = FALSE;
//    $form['accepted_agreement']['#access'] = FALSE;
//    $form['accepted_data_storage']['#access'] = FALSE;
//    $form['password1']['#access'] = FALSE;
//    $form['password2']['#access'] = FALSE;
//    $form['registration_type']['#required'] = FALSE;
//    $form['user_data']['email']['#required'] = FALSE;
//    $form['registration_type']['#required'] = FALSE;
//    $form['accepted_agreement']['#required'] = FALSE;
//    $form['accepted_data_storage']['#required'] = FALSE;
//    $form['password1']['#required'] = FALSE;
//    $form['password2']['#required'] = FALSE;
  }

  if (isset($_SESSION['registration_type']) && $_SESSION['registration_type'] == 'group') {
    $form['user_data']['lastname']['#title'] = t('Contact person\'s last name');
    $form['user_data']['firstname']['#title'] = t('Contact person\'s first name');
    $form['user_data']['email']['#title'] = t('Contact person\'s e-mail address');
  }
  else {
    $form['user_data']['lastname']['#title'] = t('Last name');
    $form['user_data']['firstname']['#title'] = t('First name');
    $form['user_data']['email']['#title'] = t('E-mail address');

    unset($form['participants']);
    unset($form['add_participant']);
  }

  if (isset($form_state['values']['invoice']) && $form_state['values']['invoice'] == 'yes') {
    $form['invoice_data']['fields']['company']['#required'] = TRUE;
    $form['invoice_data']['fields']['street']['#required'] = TRUE;
    $form['invoice_data']['fields']['postcode']['#required'] = TRUE;
    $form['invoice_data']['fields']['city']['#required'] = TRUE;
    $form['invoice_data']['fields']['tax_number']['#required'] = TRUE;
  }
  else {
    $form['invoice_data']['fields']['company']['#required'] = FALSE;
    $form['invoice_data']['fields']['street']['#required'] = FALSE;
    $form['invoice_data']['fields']['postcode']['#required'] = FALSE;
    $form['invoice_data']['fields']['city']['#required'] = FALSE;
    $form['invoice_data']['fields']['tax_number']['#required'] = FALSE;
  }
  return $form;
}

/**
 * Validates the form.
 */
function event_registration_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  //ddl($values);
  // Validation logic.
  if (!user_is_logged_in()) {
    $email_validate = _event_registration_validate_email_check($values['user_data']['email']);
    if (!isset($email_validate['status']) || $email_validate['status'] == FALSE) {
      form_set_error('user_data[email]', $email_validate['msg']);
    }
  }

  // FIXME - update validation.
  if (isset($_SESSION['registration_type']) && $_SESSION['registration_type'] == 'group' && isset($values['participants']['add_participant'])) {
    unset($values['participants']['add_participant']);
    if (count($values['participants']) < 1) {
      form_set_error('registration_type', t('Please add at least one participant.'));
    }
  }
  if (form_get_errors()) {
    ddl(form_get_errors());
  }
}

/**
 * Add a submit handler/function to the form.
 *
 * This will add a completion message to the screen when the
 * form successfully processes
 */
function event_registration_form_submit($form, &$form_state) {
  global $user;

  $values = $form_state['values'];
  //ddl(array($form, $form_state));

  if (!user_is_logged_in()) {
    $registration_type = $values['registration_type'];
    $profile_type = ($registration_type == 'single') ? 'individual' : 'company';
    $role = user_role_load_by_name($profile_type);

    // Create user.
    $newUser = entity_create('user', array());
    $newUser->name = time() . rand(0, 1000);
    $newUser->mail = $values['user_data']['email'];
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
    $newUser->pass = user_hash_password($values['password1']);
    $newUser->roles[$role->rid] = $profile_type;
    $newUser->status = 1;
    entity_save('user', $newUser);

    $newUser->name = $user->uid . time();
    entity_save('user', $newUser);

    $user = $newUser;

    // Create profile.
    $contact = profile2_create(array('type' => $profile_type, 'uid' => $user->uid));
    $contact->field_lastname[LANGUAGE_NONE][0]['value'] = $values['user_data']['lastname'];
    $contact->field_firstname[LANGUAGE_NONE][0]['value'] = $values['user_data']['firstname'];
    $contact->field_phone[LANGUAGE_NONE][0]['value'] = $values['phone'];
    $contact->field_institution[LANGUAGE_NONE][0]['value'] = $values['institution'];
    profile2_save($contact);

    // Log user.
    //user_login_finalize();
  }
  else {
    // FIXME.
    $registration_type = 'single';
  }

  // Load order.
  $order = commerce_cart_order_load($user->uid);
  if (empty($order)) {
    // Create the new order in checkout status.
    $order = commerce_order_new($user->uid);
    commerce_order_save($order);
  }

  // Load whatever product represents the item the customer will be
  // paying for and create a line item for it.
  $product = commerce_product_load((int) $values['product_id']);

  // Create a line item with quantity 1 and this product.
  $line_item = commerce_product_line_item_new($product, 1, $order->order_id);

  // Save the line item to get its ID.
  commerce_line_item_save($line_item);

  // Add the line item to the order using the wrapper.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $order_wrapper->commerce_line_items[] = $line_item;

  // Save user order comments.
  $order_wrapper->field_comments->set($values['comments']);
  // Save conference ID.
  $conference = entity_metadata_wrapper('node', $product->field_conference[LANGUAGE_NONE][0]['target_id']);
  $order_wrapper->field_conference->set($product->field_conference[LANGUAGE_NONE][0]['target_id']);

  if ($values['invoice'] == 'yes') {
    // Set invoice value.
    $order_wrapper->field_invoice->set(1);

    // Load customer profile.
    $customer_profile = _event_registration_load_customer_profile($user->uid);
    commerce_customer_profile_save($customer_profile);
    //Update customer profile.
    $customer_profile->commerce_customer_address[LANGUAGE_NONE][0]['country'] = 'pl';
    $customer_profile->commerce_customer_address[LANGUAGE_NONE][0]['name_line'] = $values['invoice_data']['fields']['company'];
    $customer_profile->commerce_customer_address[LANGUAGE_NONE][0]['thoroughfare'] = $values['invoice_data']['fields']['street'];
    $customer_profile->commerce_customer_address[LANGUAGE_NONE][0]['postal_code'] = $values['invoice_data']['fields']['postcode'];
    $customer_profile->commerce_customer_address[LANGUAGE_NONE][0]['locality'] = $values['invoice_data']['fields']['city'];
    $customer_profile->field_tax_number[LANGUAGE_NONE][0]['value'] = $values['invoice_data']['fields']['tax_number'];

    commerce_customer_profile_save($customer_profile);
    $order->commerce_customer_billing[LANGUAGE_NONE][0]['profile_id'] = $customer_profile->profile_id;

    // Update user billing info.
    // TODO: update profile2.
    $profile2 = profile2_load_by_user($user);
    if (!$profile2['billing']) {
      $billing = profile2_create(array('type' => 'billing', 'uid' => $user->uid));
      profile2_save($billing);
      $profile2 = profile2_load_by_user($user);
    }
    // Update billing data.
    $profile2['billing']->field_address[LANGUAGE_NONE][0]['name_line'] = $values['invoice_data']['fields']['company'];
    $profile2['billing']->field_address[LANGUAGE_NONE][0]['thoroughfare'] = $values['invoice_data']['fields']['street'];
    $profile2['billing']->field_address[LANGUAGE_NONE][0]['postal_code'] = $values['invoice_data']['fields']['postcode'];
    $profile2['billing']->field_address[LANGUAGE_NONE][0]['locality'] = $values['invoice_data']['fields']['city'];
    $profile2['billing']->field_tax_number[LANGUAGE_NONE][0]['value'] = $values['invoice_data']['fields']['tax_number'];
    profile2_save($profile2['billing']);
  }
  else {
    $order_wrapper->field_invoice->set(0);
  }


  // Save the order again to update its line item reference field.
  commerce_order_save($order);

  // Create registration.
  $product_wrapper = entity_metadata_wrapper('commerce_product', $product);

  $bundle = registration_get_entity_registration_type('commerce_product', $product_wrapper->value());

  if (!function_exists('commerce_registration_create_product_registration')) {
    module_load_include('inc', 'commerce_registration', 'includes/commerce_registration.checkout_pane');
  }

  $qty = 0;
  switch ($registration_type) {
    case 'single':
      // For single registrations.
      $qty++;
      $registration = commerce_registration_create_product_registration(
          $product->product_id, $bundle, $order->order_id
      );

      $registration->user_uid = $user->uid;
      $registration->field_registration_lastname[LANGUAGE_NONE][0]['value'] = $values['user_data']['lastname'];
      $registration->field_registration_firstname[LANGUAGE_NONE][0]['value'] = $values['user_data']['firstname'];
      registration_save($registration);

      $prodkey = $line_item->line_item_id . 'prod-' . $product_wrapper->sku->value();
      $order->data['register_entities'][$prodkey][0] = $registration;
      break;
    default:
      // For group registrations.
      //ddl($values['participants']);
      unset($values['participants']['add_participant']);
      foreach ($values['participants'] as $participant) {
        $qty++;
        $registration = commerce_registration_create_product_registration(
            $product->product_id, $bundle, $order->order_id
        );
        $registration->user_uid = $user->uid;
        $registration->field_registration_lastname[LANGUAGE_NONE][0]['value'] = $participant['lastname'];
        $registration->field_registration_firstname[LANGUAGE_NONE][0]['value'] = $participant['firstname'];
        $registration->anon_mail = $participant['email'];
        registration_save($registration);
        //ddl($registration);
        $prodkey = $line_item->line_item_id . 'prod-' . $product_wrapper->sku->value();
        $order->data['register_entities'][$prodkey][] = $registration;
      }
      break;
  }
  // Update line item.
  $line_item->quantity = $qty;
  $line_item->commerce_total[LANGUAGE_NONE][0]['amount'] = $qty * $line_item->commerce_unit_price[LANGUAGE_NONE][0]['amount'];
  $line_item->commerce_total[LANGUAGE_NONE][0]['data']['components']['0']['price']['amount'] = $qty * $line_item->commerce_unit_price[LANGUAGE_NONE][0]['amount'];

  // Save the line item to get its ID.
  commerce_line_item_save($line_item);
  commerce_order_save($order);

  // TODO: Mail subject.
  $message = _event_registration_confirmation_mail_body($order);
  event_registration_mail('Confirmation', $message, $user->mail);
  //ddl(array($order, $bundle, $registration, $line_item, $form, $form_state, $user, $values));

  watchdog('user', 'Session closed for %name.', array('%name' => $user->name));
  module_invoke_all('user_logout', $user);
  // Destroy the current session, and reset $user to the anonymous user.
  session_destroy();

  drupal_goto('registration/' . $order->order_id . '/confirm');
}

function _event_registration_load_customer_profile($uid) {
  $query = new EntityFieldQuery;
  $result = $query
      ->entityCondition('entity_type', 'commerce_customer_profile')
      ->propertyCondition('uid', $uid)
      ->propertyCondition('status', 1)
      ->range(0, 1)
      ->entityOrderBy('entity_id', 'DESC')
      ->execute();
  if (!empty($result['commerce_customer_profile'])) {
    $profile_ids = array_keys($result['commerce_customer_profile']);
    return commerce_customer_profile_load($profile_ids[0]);
  }
  else {
    $new_profile = commerce_customer_profile_new('billing', $uid);
    return $new_profile;
  }
}

function _event_registration_add_participant($form, &$form_state) {
  $form = drupal_rebuild_form($form['#form_id'], $form_state);

  // Add new upsell form
//  $commands[] = ajax_command_before('#addParticipantBox', render($form['participants'][$_SESSION['participants']['count']]));
  $commands[] = ajax_command_append('#participants', render($form['participants'][$_SESSION['participants']['count']]));

  return array('#type' => 'ajax', '#commands' => $commands);
}

function _event_registration_participant_cancel($form, &$form_state) {
  $commands = array();

  if (isset($form_state['triggering_element']['#name']) && preg_match('/participants\[(\d+)\]\[cancel\]/', $form_state['triggering_element']['#name'])) {
    // Check triggering item id

    preg_match_all('/participants\[(?P<digits>\d+)\]\[cancel\]/', $form_state['triggering_element']['#name'], $matches);
    $i = $matches['digits'][0];
    //ddl(array('_event_registration_participant_cancel', $i, $form_state['triggering_element']['#name']));
    $form = drupal_rebuild_form($form['#form_id'], $form_state);

    // Rebuild form.
    $commands[] = ajax_command_replace('#participants', render($form['participants']));
  }
  //ddl($commands);
  return array('#type' => 'ajax', '#commands' => $commands);
}

function _event_registration_type_switch($form, &$form_state) {
  $commands = array();

  if ($form_state['input']['registration_type'] == 'single') {
    $_SESSION['registration_type'] = 'single';
    $form['user_data']['lastname']['#title'] = t('Last name');
    $form['user_data']['firstname']['#title'] = t('First name');
    $form['user_data']['email']['#title'] = t('E-mail address');
  }
  else {
    $_SESSION['registration_type'] = 'group';
    $form['user_data']['lastname']['#title'] = t('Contact person\'s last name');
    $form['user_data']['firstname']['#title'] = t('Contact person\'s first name');
    $form['user_data']['email']['#title'] = t('Contact person\'s e-mail address');
  }
  $form = drupal_rebuild_form($form['#form_id'], $form_state);
  $commands[] = ajax_command_replace('#user_data', render($form['user_data']));
  //ddl($commands);
  return array('#type' => 'ajax', '#commands' => $commands);
}
