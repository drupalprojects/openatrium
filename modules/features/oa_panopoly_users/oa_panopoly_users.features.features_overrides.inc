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
  $overrides["panelizer_defaults.user:user:default.display|content|new-1|panel"] = 'contentmain';
  $overrides["panelizer_defaults.user:user:default.display|content|new-2|panel"] = 'sidebar';
  $overrides["panelizer_defaults.user:user:default.display|layout"] = 'burr_flipped';
  $overrides["panelizer_defaults.user:user:default.display|panels|column1"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|panels|column2"]["DELETED"] = TRUE;
  $overrides["panelizer_defaults.user:user:default.display|panels|contentmain"] = array(
    0 => 'new-1',
  );
  $overrides["panelizer_defaults.user:user:default.display|panels|sidebar"] = array(
    0 => 'new-2',
  );

 return $overrides;
}
