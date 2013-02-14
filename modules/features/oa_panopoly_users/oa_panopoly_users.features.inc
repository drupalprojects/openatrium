<?php
/**
 * @file
 * oa_panopoly_users.features.inc
 */

/**
 * Implements hook_field_default_fields_alter().
 */
function oa_panopoly_users_field_default_fields_alter(&$data) {
  if (isset($data['user-user-field_user_picture'])) {
    $data['user-user-field_user_picture']['field_instance']['settings']['min_resolution'] = '150x150'; /* WAS: '300x200' */
    $data['user-user-field_user_picture']['field_instance']['widget']['weight'] = '4'; /* WAS: '3' */
  }
}

/**
 * Implements hook_panelizer_defaults_override_alter().
 */
function oa_panopoly_users_panelizer_defaults_override_alter(&$data) {
  if (isset($data['user:user:default'])) {
    $data['user:user:default']->display->content['new-1']->panel = 'contentmain'; /* WAS: 'column1' */
    $data['user:user:default']->display->content['new-2']->panel = 'sidebar'; /* WAS: 'column2' */
    $data['user:user:default']->display->layout = 'burr_flipped'; /* WAS: 'phelan' */
    $data['user:user:default']->display->panels['contentmain'] = array(
      0 => 'new-1',
    ); /* WAS: '' */
    $data['user:user:default']->display->panels['sidebar'] = array(
      0 => 'new-2',
    ); /* WAS: '' */
    unset($data['user:user:default']->display->panels['column1']);
    unset($data['user:user:default']->display->panels['column2']);
  }
}
