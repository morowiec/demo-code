<?php

/**
 * @file
 * Plugin to provide an relationship handler for node from user.
 *
 * Based on PMO.
 */

$plugin = array(
  'title' => t('clientx | Company ID from User profile'),
  'keyword' => 'company_id',
  'description' => t('Fetch Company ID based on given user context.'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'context' => 'clientx_offers_ctools_company_id_from_user_context',
);

/**
 * Return a new context based on an existing context.
 */
function clientx_offers_ctools_company_id_from_user_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    return ctools_context_create_empty('term', NULL);
  }
  // Check if field in the user profile has a value.
  if (isset($context->data->field_clientx_company_id[LANGUAGE_NONE][0]['target_id'])) {
    // Fetch company id from the User profile.
    $company = taxonomy_term_load($context->data->field_clientx_company_id[LANGUAGE_NONE][0]['target_id']);
    if ($company) {
      return ctools_context_create('term', $company);
    }
  }
  return ctools_context_create_empty('term', NULL);
}
