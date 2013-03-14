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
    'views_view_fields__oa_user_groups__full' => array(
      'template'  => 'views-view-fields--oa-user-groups--full',
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => $path,
    ),
  );
}
