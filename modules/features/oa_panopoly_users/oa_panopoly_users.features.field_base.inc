<?php
/**
 * @file
 * oa_panopoly_users.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_panopoly_users_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_user_display_name'
  $field_bases['field_user_display_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_user_display_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
