<?php
/**
 * @file
 * oa_demo_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_demo_content_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function oa_demo_content_node_info() {
  $items = array(
    'group_article' => array(
      'name' => t('Group Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
