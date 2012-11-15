<?php
/**
 * @file
 * openatrium2_groups.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function openatrium2_groups_defaultconfig_features() {
  return array(
    'openatrium2_groups' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function openatrium2_groups_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_team';
  $strongarm->value = '1';
  $export['node_preview_team'] = $strongarm;

  return $export;
}
