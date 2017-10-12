<?php
/**
 * @file
 * Plugin check if user has proper role and can edit node.
 */

/**
 * Describe the plugin.
 */
$plugin = array(
  'title' => t('clientx | Offers | Users | Company/Agency'),
  'description' => t('Show variant for Company/Agency users.'),
  'required context' => array(
    0 => new ctools_context_required(t('User'), 'user'),
  ),
  'callback' => 'clientx_company_agency_editor_access',
  'summary' => 'clientx_company_agency_editor_access_summary',
);

/**
 * Provide a summary description based on selected settings.
 */
function clientx_company_agency_editor_access_summary($conf, $context) {
  return t('Will show administrative option for Company/Agency users.');
}

/**
 * Function which will check if user is having access to administrative options.
 */
function clientx_company_agency_editor_access($conf, $context) {
  if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_ADMINISTRATOR)) {
    // Return true for administrator user.
    return TRUE;
  }

  if (clientxSomeOffersTools::checkIfUserIsSomeOfferEditor($context[0]->data)) {
    return TRUE;
  }
  return FALSE;
}
