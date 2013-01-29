<?php
/**
 * @file
 * oa_discussion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_discussion_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_discussion_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oa_discussion_node_info() {
  $items = array(
    'oa_discussion_post' => array(
      'name' => t('Discussion Post'),
      'base' => 'node_content',
      'description' => t('An Open Atrium discussion post'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
