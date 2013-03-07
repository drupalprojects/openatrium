<?php
/**
 * @file
 * oa_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: use text format panopoly_wysiwyg_text.
  $permissions['use text format panopoly_wysiwyg_text'] = array(
    'name' => 'use text format panopoly_wysiwyg_text',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
