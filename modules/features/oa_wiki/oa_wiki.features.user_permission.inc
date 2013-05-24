<?php
/**
 * @file
 * oa_wiki.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_wiki_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node oa_wiki_page breadcrumbs.
  $permissions['administer panelizer node oa_wiki_page breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_wiki_page breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page content.
  $permissions['administer panelizer node oa_wiki_page content'] = array(
    'name' => 'administer panelizer node oa_wiki_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page context.
  $permissions['administer panelizer node oa_wiki_page context'] = array(
    'name' => 'administer panelizer node oa_wiki_page context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page defaults.
  $permissions['administer panelizer node oa_wiki_page defaults'] = array(
    'name' => 'administer panelizer node oa_wiki_page defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page layout.
  $permissions['administer panelizer node oa_wiki_page layout'] = array(
    'name' => 'administer panelizer node oa_wiki_page layout',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page overview.
  $permissions['administer panelizer node oa_wiki_page overview'] = array(
    'name' => 'administer panelizer node oa_wiki_page overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_wiki_page settings.
  $permissions['administer panelizer node oa_wiki_page settings'] = array(
    'name' => 'administer panelizer node oa_wiki_page settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  return $permissions;
}
