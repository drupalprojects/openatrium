<?php
/**
 * @file
 * openatrium2_content_types.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function openatrium2_content_types_defaultconfig_features() {
  return array(
    'openatrium2_content_types' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function openatrium2_content_types_defaultconfig_strongarm() {
  $export = array();

  return $export;
}
