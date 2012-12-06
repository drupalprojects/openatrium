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

  return $export;
}
