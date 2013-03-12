<?php
/**
 * @file
 * Code for Theme functions for OpenAtrium groups
 */


/**
 * Implements hook_theme()
 */
function oa_groups_theme() {
  return array(
    'oa_groups_members_widget' => array(
      'template'  => 'oa-groups-members-widget',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => drupal_get_path('module', 'oa_groups') . '/templates',
    ),
  );
}
