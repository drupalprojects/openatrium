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
    $data['user:user:default']->display->content['new-1']->configuration['delta_limit'] = 0; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['delta_offset'] = '0'; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['delta_reversed'] = FALSE; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['exposed'] = array(
      'sort_by' => NULL,
      'sort_order' => NULL,
    ); /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['formatter'] = 'text_default'; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['formatter_settings'] = array(); /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['items_per_page'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['label'] = 'hidden'; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['link_to_view'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['more_link'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['offset'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['override_title'] = 0; /* WAS: 1 */
    $data['user:user:default']->display->content['new-1']->configuration['pager_id'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['path'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['use_pager'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->configuration['widget_title'] = NULL; /* WAS: '' */
    $data['user:user:default']->display->content['new-1']->panel = 'contentmain'; /* WAS: 'column1' */
    $data['user:user:default']->display->content['new-1']->subtype = 'user:field_user_about'; /* WAS: 'user_profile' */
    $data['user:user:default']->display->content['new-1']->type = 'entity_field'; /* WAS: 'user_profile' */
    $data['user:user:default']->display->content['new-2']->configuration['header_type'] = 'none'; /* WAS: '' */
    $data['user:user:default']->display->content['new-2']->configuration['view_mode'] = 'teaser'; /* WAS: '' */
    $data['user:user:default']->display->content['new-2']->configuration['view_settings'] = 'fields'; /* WAS: '' */
    $data['user:user:default']->display->content['new-2']->panel = 'contentmain'; /* WAS: 'column2' */
    $data['user:user:default']->display->content['new-2']->position = 1; /* WAS: 0 */
    $data['user:user:default']->display->content['new-2']->subtype = 'oa_recent_activity-user_activity'; /* WAS: 'user:field_user_picture' */
    $data['user:user:default']->display->content['new-2']->type = 'views_panes'; /* WAS: 'entity_field' */
    $data['user:user:default']->display->content['new-3'] = (object) array(
          'pid' => 'new-3',
          'panel' => 'sidebar',
          'type' => 'entity_field',
          'subtype' => 'user:field_user_picture',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'label' => 'hidden',
            'formatter' => 'image',
            'delta_limit' => 0,
            'delta_offset' => '0',
            'delta_reversed' => FALSE,
            'formatter_settings' => array(
              'image_style' => 'panopoly_image_full',
              'image_link' => '',
            ),
            'context' => 'panelizer',
            'override_title' => 1,
            'override_title_text' => '',
            'view_mode' => NULL,
            'widget_title' => NULL,
            'items_per_page' => NULL,
            'exposed' => array(
              'sort_by' => NULL,
              'sort_order' => NULL,
            ),
            'use_pager' => NULL,
            'pager_id' => NULL,
            'offset' => NULL,
            'link_to_view' => NULL,
            'more_link' => NULL,
            'path' => NULL,
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 0,
          'locks' => array(),
        ); /* WAS: '' */
    $data['user:user:default']->display->content['new-4'] = (object) array(
          'pid' => 'new-4',
          'panel' => 'sidebar',
          'type' => 'views_panes',
          'subtype' => 'open_atrium_groups-groups',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'context' => array(
              0 => 'panelizer',
            ),
            'view_mode' => 'teaser',
            'widget_title' => NULL,
            'items_per_page' => NULL,
            'exposed' => array(
              'sort_by' => NULL,
              'sort_order' => NULL,
            ),
            'use_pager' => NULL,
            'pager_id' => NULL,
            'offset' => NULL,
            'link_to_view' => NULL,
            'more_link' => NULL,
            'path' => NULL,
            'view_settings' => 'fields',
            'header_type' => 'none',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 1,
          'locks' => array(),
        ); /* WAS: '' */
    $data['user:user:default']->display->layout = 'burr_flipped'; /* WAS: 'phelan' */
    $data['user:user:default']->display->panels['contentmain'] = array(
      0 => 'new-1',
      1 => 'new-2',
    ); /* WAS: '' */
    $data['user:user:default']->display->panels['sidebar'] = array(
      0 => 'new-3',
      1 => 'new-4',
    ); /* WAS: '' */
    unset($data['user:user:default']->display->content['new-2']->configuration['context']);
    unset($data['user:user:default']->display->content['new-2']->configuration['delta_limit']);
    unset($data['user:user:default']->display->content['new-2']->configuration['delta_offset']);
    unset($data['user:user:default']->display->content['new-2']->configuration['delta_reversed']);
    unset($data['user:user:default']->display->content['new-2']->configuration['formatter']);
    unset($data['user:user:default']->display->content['new-2']->configuration['formatter_settings']);
    unset($data['user:user:default']->display->content['new-2']->configuration['label']);
    unset($data['user:user:default']->display->content['new-2']->configuration['override_title']);
    unset($data['user:user:default']->display->content['new-2']->configuration['override_title_text']);
    unset($data['user:user:default']->display->panels['column1']);
    unset($data['user:user:default']->display->panels['column2']);
  }
}
