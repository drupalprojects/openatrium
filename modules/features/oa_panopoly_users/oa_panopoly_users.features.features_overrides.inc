<?php
/**
 * @file
 * oa_panopoly_users.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oa_panopoly_users_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field
  $overrides["field.user-user-field_user_picture.field_instance|settings|min_resolution"] = '150x150';
  $overrides["field.user-user-field_user_picture.field_instance|widget|weight"] = '4';

  // Exported overrides for: panelizer_defaults
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|delta_limit"] = 0;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|delta_offset"] = '0';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|delta_reversed"] = FALSE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|exposed"] = array(
    'sort_by' => NULL,
    'sort_order' => NULL,
  );
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|formatter"] = 'text_default';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|formatter_settings"] = array();
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|items_per_page"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|label"] = 'hidden';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|link_to_view"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|more_link"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|offset"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|override_title"] = 0;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|pager_id"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|path"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|use_pager"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|configuration|widget_title"] = NULL;
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|panel"] = 'contentmain';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|subtype"] = 'user:field_user_about';
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|type"] = 'entity_field';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|context"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|delta_limit"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|delta_offset"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|delta_reversed"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|formatter"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|formatter_settings"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|header_type"] = 'none';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|label"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|override_title"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|override_title_text"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|view_mode"] = 'teaser';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|configuration|view_settings"] = 'fields';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|panel"] = 'contentmain';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|position"] = 1;
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|subtype"] = 'oa_recent_activity-user_activity';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|type"] = 'views_panes';
  $overrides["panelizer_defaults.user:user:default.display|content|new-3"] = (object) array(
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
    );
  $overrides["panelizer_defaults.user:user:default.display|content|new-4"] = (object) array(
      'pid' => 'new-4',
      'panel' => 'sidebar',
      'type' => 'views_panes',
      'subtype' => 'open_atrium_spaces-spaces',
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
    );
  $overrides["panelizer_defaults.user:user:default.display|layout"] = 'burr_flipped';
  $overrides["panelizer_defaults.user:user:default.display|panels|column1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|panels|column2"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|panels|contentmain"] = array(
    0 => 'new-1',
    1 => 'new-2',
  );
  $overrides["panelizer_defaults.user:user:default.display|panels|sidebar"] = array(
    0 => 'new-3',
    1 => 'new-4',
  );

 return $overrides;
}
