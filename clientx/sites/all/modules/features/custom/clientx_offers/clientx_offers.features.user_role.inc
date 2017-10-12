<?php
/**
 * @file
 * clientx_offers.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function clientx_offers_user_default_roles() {
  $roles = array();

  // Exported role: clientx | Some offer | Editor.
  $roles['clientx | Some offer | Editor'] = (object) array(
    'name' => 'clientx | Some offer | Editor',
    'weight' => 9,
  );

  // Exported role: clientx | Some offer | Extended editor.
  $roles['clientx | Some offer | Extended editor'] = (object) array(
    'name' => 'clientx | Some offer | Extended editor',
    'weight' => 10,
  );

  return $roles;
}
