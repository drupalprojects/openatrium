<?php
/**
 * @file
 * Code for theme functions for oa_groups.
 */


/**
 * Implements hook_theme()
 */
function oa_groups_theme() {
  return array(
    'oa_groups_summary' => array(
      'template'  => 'oa-groups-summary',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => drupal_get_path('module', 'oa_groups') . '/templates',
    ),
  );
}
