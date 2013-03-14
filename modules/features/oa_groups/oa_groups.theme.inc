<?php
/**
 * @file
 * Code for Theme functions for OpenAtrium groups
 */


/**
 * Implements hook_theme()
 */
function oa_groups_theme() {
  $path = drupal_get_path('module', 'oa_groups') . '/templates';
  return array(
    'oa_groups_members_widget' => array(
      'template'  => 'oa-groups-members-widget',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => $path,
    ),
    'oa_groups_summary' => array(
      'template'  => 'oa-groups-summary',
      'path' => $path,
    ),
    'oa_groups_user_groups' => array(
      'template'  => 'oa-groups-user-groups',
      'path' => $path,
    ),
  );
}
