<?php
/**
 * @file
 * oa_discussion.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_discussion_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node oa_discussion_post breadcrumbs.
  $permissions['administer panelizer node oa_discussion_post breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_discussion_post breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post content.
  $permissions['administer panelizer node oa_discussion_post content'] = array(
    'name' => 'administer panelizer node oa_discussion_post content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post context.
  $permissions['administer panelizer node oa_discussion_post context'] = array(
    'name' => 'administer panelizer node oa_discussion_post context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post defaults.
  $permissions['administer panelizer node oa_discussion_post defaults'] = array(
    'name' => 'administer panelizer node oa_discussion_post defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post layout.
  $permissions['administer panelizer node oa_discussion_post layout'] = array(
    'name' => 'administer panelizer node oa_discussion_post layout',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post overview.
  $permissions['administer panelizer node oa_discussion_post overview'] = array(
    'name' => 'administer panelizer node oa_discussion_post overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_discussion_post settings.
  $permissions['administer panelizer node oa_discussion_post settings'] = array(
    'name' => 'administer panelizer node oa_discussion_post settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  return $permissions;
}
