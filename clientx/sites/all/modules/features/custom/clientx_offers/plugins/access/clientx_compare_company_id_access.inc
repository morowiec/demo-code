<?php
/**
 * @file
 * Plugin check if user is from proper company or agency and can edit node.
 */

/**
 * Describe the plugin.
 */
$plugin = array(
  'title' => t("clientx | Offers | Users | Compare Company's ID"),
  'description' => t('Show variant only for user with same Company ID.'),
  'required context' => array(
    0 => new ctools_context_required(t('Node'), 'node'),
    1 => new ctools_context_required(t('User'), 'user'),
  ),
  'callback' => 'clientx_compare_company_id_access',
  'summary' => 'clientx_compare_company_id_access_summary',
);

/**
 * Provide a summary description based on selected settings.
 */
function clientx_compare_company_id_access_summary($conf, $context) {
  return t('Show variant only for user with same Company ID.');
}

/**
 * Function which will check if user is having access to administrative options.
 */
function clientx_compare_company_id_access($conf, $context) {
  $node_company_id = clientxSomeOffersTools::getCompanyIdFromObject($context[0]->data);
  $user_company_id = clientxSomeOffersTools::getCompanyIdFromObject($context[1]->data);

  if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_ADMINISTRATOR)) {
    // Return true for administrator user.
    return TRUE;
  }

  if (clientxSomeOffersTools::checkIfCompanyIdsAreSame($node_company_id, $user_company_id)) {
    return TRUE;
  }
  return FALSE;
}
