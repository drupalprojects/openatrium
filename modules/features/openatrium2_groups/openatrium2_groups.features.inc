<?php
/**
 * @file
 * openatrium2_groups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openatrium2_groups_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function openatrium2_groups_node_info() {
  $items = array(
    'openatrium_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A collection of members'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
