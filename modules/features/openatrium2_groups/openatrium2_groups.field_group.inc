<?php
/**
 * @file
 * openatrium2_groups.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function openatrium2_groups_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_logos|node|openatrium_group|form';
  $field_group->group_name = 'group_logos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openatrium_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Logos',
    'weight' => '3',
    'children' => array(
      0 => 'field_logo',
      1 => 'field_logo_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_logos|node|openatrium_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_logos|node|openatrium_organization|form';
  $field_group->group_name = 'group_logos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'openatrium_organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Logos',
    'weight' => '2',
    'children' => array(
      0 => 'field_logo',
      1 => 'field_logo_thumbnail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_logos|node|openatrium_organization|form'] = $field_group;

  return $export;
}
