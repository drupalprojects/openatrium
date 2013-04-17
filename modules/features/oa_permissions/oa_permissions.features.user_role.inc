<?php
/**
 * @file
 * oa_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function oa_permissions_user_default_roles() {
  $roles = array();

  // Exported role: space admin.
  $roles['space admin'] = array(
    'name' => 'space admin',
    'weight' => 3,
  );

  return $roles;
}
