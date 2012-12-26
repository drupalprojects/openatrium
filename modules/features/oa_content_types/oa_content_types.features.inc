<?php
/**
 * @file
 * oa_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
function oa_content_types_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function oa_content_types_node_info() {
  $items = array(
    'oa_group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A collection of members'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_organization' => array(
      'name' => t('Organization'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_section' => array(
      'name' => t('Section Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'oa_team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
