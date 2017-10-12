<?php
/**
 * @file
 * Plugin check if user has proper role and can edit node.
 */

/**
 * Describe the plugin.
 */
$plugin = array(
  'title' => t('clientx | Offers | Some page | Stage: closed'),
  'description' => t('Show variant for closed pages.'),
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
  'callback' => 'clientx_some_page_closed_access',
  'summary' => 'clientx_some_page_closed_access_summary',
);

/**
 * Provide a summary description based on selected settings.
 */
function clientx_some_page_closed_access_summary($conf, $context) {
  return t('Will show for pages with closed comp/CASTING.');
}

/**
 * Function which will check if user is having access to administrative options.
 */
function clientx_some_page_closed_access($conf, $context) {
  $node = $context[0]->data;

  if (isset($node->field_clientx_closed[LANGUAGE_NONE][0]['value']) && $node->field_clientx_closed[LANGUAGE_NONE][0]['value'] == 1) {
    return TRUE;
  }
  return FALSE;
}
