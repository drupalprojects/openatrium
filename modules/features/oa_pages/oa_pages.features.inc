<?php
/**
 * @file
 * oa_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_pages_ctools_plugin_api() {
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
function oa_pages_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oa_pages_node_info() {
  $items = array(
    'oa_pages_page' => array(
      'name' => t('Document Page'),
      'base' => 'node_content',
      'description' => t('An Open Atrium document page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
