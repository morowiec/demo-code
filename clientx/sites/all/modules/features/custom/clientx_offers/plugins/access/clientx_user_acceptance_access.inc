<?php
/**
 * @file
 * Plugin check if user has proper role - Content manager.
 */

/**
 * Describe the plugin.
 */
$plugin = array(
  'title' => t('clientx | Offers | Users | Acceptance'),
  'description' => t('Show variant for clientx Acceptance users.'),
  'required context' => array(
    0 => new ctools_context_required(t('Node'), 'node'),
    1 => new ctools_context_required(t('User'), 'user'),
  ),
  'callback' => 'clientx_user_acceptance_access',
  'summary' => 'clientx_user_acceptance_access_summary',
);

/**
 * Provide a summary description based on selected settings.
 */
function clientx_user_acceptance_access_summary($conf, $context) {
  return t('Will show variant clientx Acceptance users.');
}

/**
 * Function which will check if user is having access to administrative options.
 */
function clientx_user_acceptance_access($conf, $context) {
  if (!user_is_logged_in()) {
    return FALSE;
  }
  if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_clientx_ACCEPTANCE, $context[1]->data)) {
    return TRUE;
  }
  return FALSE;
}
