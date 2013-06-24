<?php
/**
 * @file
 * oa_permissions.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_permissions_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_group:trash any content'
  $permissions['node:oa_group:trash any content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:untrash any content'
  $permissions['node:oa_group:untrash any content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_group:view trash bin'
  $permissions['node:oa_group:view trash bin'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:oa_space:trash any content'
  $permissions['node:oa_space:trash any content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:untrash any content'
  $permissions['node:oa_space:untrash any content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:view trash bin'
  $permissions['node:oa_space:view trash bin'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
