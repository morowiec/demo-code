<?php
/**
 * @file
 * Plugin check if user has proper role - Content manager.
 */

/**
 * Describe the plugin.
 */
$plugin = array(
  'title' => t('clientx | Offers | Users | Administrator'),
  'description' => t('Show variant for clientx Administrator users.'),
  'required context' => array(
    0 => new ctools_context_required(t('Node'), 'node'),
  ),
  'callback' => 'clientx_administrator_access',
  'summary' => 'clientx_administrator_access_summary',
);

/**
 * Provide a summary description based on selected settings.
 */
function clientx_administrator_access_summary($conf, $context) {
  return t('Will show variant clientx Content manager users.');
}

/**
 * Function which will check if user is having access to administrative options.
 */
function clientx_administrator_access($conf, $context) {
  global $user;
  if (!user_is_logged_in()) {
    return FALSE;
  }
  if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_ADMINISTRATOR, $user)) {
    return TRUE;
  }
  if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_clientx_ADMINISTRATOR, $user)) {
    return TRUE;
  }
  return FALSE;
}
