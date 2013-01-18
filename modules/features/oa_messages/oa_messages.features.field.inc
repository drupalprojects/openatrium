<?php
/**
 * @file
 * oa_messages.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function oa_messages_field_default_fields() {
  $fields = array();

  // Exported field: 'message-oa_create-field_oa_node_ref'.
  $fields['message-oa_create-field_oa_node_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_oa_node_ref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'oa_create',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'field_oa_node_ref',
      'label' => 'Node',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'message-oa_create-group_group'.
  $fields['message-oa_create-group_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'group_group',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Not a group',
          1 => 'Group',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'oa_create',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Determine if this is an OG group.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og_ui',
          'settings' => array(
            'field_name' => FALSE,
          ),
          'type' => 'og_group_subscribe',
          'weight' => 2,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 1,
      'entity_type' => 'message',
      'field_name' => 'group_group',
      'label' => 'Group',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'view modes' => array(
        'full' => array(
          'custom settings' => FALSE,
          'label' => 'Full',
          'type' => 'og_group_subscribe',
        ),
        'teaser' => array(
          'custom settings' => FALSE,
          'label' => 'Teaser',
          'type' => 'og_group_subscribe',
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
          'og_hide' => TRUE,
        ),
        'type' => 'options_onoff',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'message-oa_create-og_group_ref'.
  $fields['message-oa_create-og_group_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'og_group_ref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'og',
        'handler_settings' => array(
          'behaviors' => array(
            'og_behavior' => array(
              'status' => TRUE,
            ),
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'membership_type' => 'og_membership_type_default',
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'oa_group' => 'oa_group',
          ),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'node',
      ),
      'target_type' => 'node',
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'oa_create',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 1,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'og_group_ref',
      'label' => 'Groups ID',
      'required' => 1,
      'settings' => array(
        'behaviors' => array(
          'og_widget' => array(
            'admin' => array(
              'widget_type' => 'entityreference_autocomplete',
            ),
            'default' => array(
              'widget_type' => 'options_select',
            ),
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'og',
        'settings' => array(),
        'type' => 'og_complex',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'message-oa_delete-field_oa_node_ref'.
  $fields['message-oa_delete-field_oa_node_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_oa_node_ref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'oa_delete',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'field_oa_node_ref',
      'label' => 'Node',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'message-oa_delete-group_group'.
  $fields['message-oa_delete-group_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'group_group',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Not a group',
          1 => 'Group',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'oa_delete',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Determine if this is an OG group.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og_ui',
          'settings' => array(
            'field_name' => FALSE,
          ),
          'type' => 'og_group_subscribe',
          'weight' => 2,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 1,
      'entity_type' => 'message',
      'field_name' => 'group_group',
      'label' => 'Group',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'view modes' => array(
        'full' => array(
          'custom settings' => FALSE,
          'label' => 'Full',
          'type' => 'og_group_subscribe',
        ),
        'teaser' => array(
          'custom settings' => FALSE,
          'label' => 'Teaser',
          'type' => 'og_group_subscribe',
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
          'og_hide' => TRUE,
        ),
        'type' => 'options_onoff',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'message-oa_delete-og_group_ref'.
  $fields['message-oa_delete-og_group_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'og_group_ref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'og',
        'handler_settings' => array(
          'behaviors' => array(
            'og_behavior' => array(
              'status' => TRUE,
            ),
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'membership_type' => 'og_membership_type_default',
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'oa_group' => 'oa_group',
          ),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'node',
      ),
      'target_type' => 'node',
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'oa_delete',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 1,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'og_group_ref',
      'label' => 'Groups ID',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'og',
        'settings' => array(),
        'type' => 'og_complex',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'message-oa_update-field_oa_node_ref'.
  $fields['message-oa_update-field_oa_node_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_oa_node_ref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(),
        ),
        'target_type' => 'node',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'oa_update',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'field_oa_node_ref',
      'label' => 'Node',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Exported field: 'message-oa_update-group_group'.
  $fields['message-oa_update-group_group'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'group_group',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Not a group',
          1 => 'Group',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'oa_update',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Determine if this is an OG group.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'og_ui',
          'settings' => array(
            'field_name' => FALSE,
          ),
          'type' => 'og_group_subscribe',
          'weight' => 3,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'display_label' => 1,
      'entity_type' => 'message',
      'field_name' => 'group_group',
      'label' => 'Group',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'view modes' => array(
        'full' => array(
          'custom settings' => FALSE,
          'label' => 'Full',
          'type' => 'og_group_subscribe',
        ),
        'teaser' => array(
          'custom settings' => FALSE,
          'label' => 'Teaser',
          'type' => 'og_group_subscribe',
        ),
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
          'og_hide' => TRUE,
        ),
        'type' => 'options_onoff',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'message-oa_update-og_group_ref'.
  $fields['message-oa_update-og_group_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'og_group_ref',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'og',
        'handler_settings' => array(
          'behaviors' => array(
            'og_behavior' => array(
              'status' => TRUE,
            ),
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'membership_type' => 'og_membership_type_default',
          'sort' => array(
            'type' => 'none',
          ),
          'target_bundles' => array(
            'oa_group' => 'oa_group',
          ),
        ),
        'handler_submit' => 'Change handler',
        'target_type' => 'node',
      ),
      'target_type' => 'node',
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'oa_update',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 1,
        ),
        'message_notify_email_body' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'message_notify_email_subject' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'og_group_ref',
      'label' => 'Groups ID',
      'required' => 1,
      'settings' => array(
        'behaviors' => array(
          'og_widget' => array(
            'admin' => array(
              'widget_type' => 'entityreference_autocomplete',
            ),
            'default' => array(
              'widget_type' => 'options_select',
            ),
            'status' => TRUE,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'og',
        'settings' => array(),
        'type' => 'og_complex',
        'weight' => '3',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Determine if this is an OG group.');
  t('Group');
  t('Groups ID');
  t('Node');

  return $fields;
}
