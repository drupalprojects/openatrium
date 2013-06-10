<?php
/**
 * @file
 * oa_buttons.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function oa_buttons_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_icons|oa_button|button|form';
  $field_group->group_name = 'group_icons';
  $field_group->entity_type = 'oa_button';
  $field_group->bundle = 'button';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Icons',
    'weight' => '7',
    'children' => array(
      0 => 'field_link_icon',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Icons',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'the-icons clearfix',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_icons|oa_button|button|form'] = $field_group;

  return $export;
}
