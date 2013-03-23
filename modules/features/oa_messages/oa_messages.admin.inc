<?php

/**
 * @file
 * Provides forms and pages for administering oa_messages.
 */

/**
 * Implements hook_oa_user_settings_form_alter().
 */
function oa_messages_oa_user_settings_form_alter(&$form, $form_state, $user) {
  $form['oa_messages'] = array(
    '#type' => 'fieldset',
    '#title' => t('Messages'),
    '#collapsible' => FALSE,
    '#tree' => TRUE,
  );
  $defaults = $user->data['oa_messages'];
  
  $form['oa_messages']['message_types'] = oa_messages_build_message_types_table($user, $defaults);
  
  $header = array(
    'group' => t('Group'),
  );
  
  $form['oa_messages']['email_type'] = array(
    '#type' => 'radios',
    '#title' => t('Email type'),
    '#description' => t('Select how you would like your emails sent.'),
    '#options' => array(
      EMAIL_TYPE_PLAIN => 'Plain text',
      EMAIL_TYPE_HTML => 'HTML',
    ),
    '#default_value' => isset($defaults['email_type']) ? $defaults['email_type'] : EMAIL_TYPE_HTML,
  );
}

/**
 * Build a table of notification types per group, much like
 * the permissions table.
 */
function oa_messages_build_message_types_table($user, $defaults = array()) {
  $groups = node_load_multiple(oa_groups_get_user_groups($user->uid));
  $message_types = message_type_load();
  $table = array(
    '#prefix' => '<table class="table table-bordered table-striped table-hover checkbox-table">',
    '#suffix' => '</table>',
    '#tree' => TRUE,
  );
  
  $table['header'] = array(
    '#prefix' => '<thead><tr>',
    'group' => array(
      '#prefix' => '<th>',
      '#markup' => t('Group'),
      '#suffix' => '</th>',
    ),
    '#suffix' => '</tr></thead>',
  );
  foreach ($message_types as $message_type) {
    $table['header'][$message_type->name] = array(
      '#prefix' => '<th class="center">',
      '#markup' => $message_type->description,
      '#suffix' => '</th>',
    );
  }
  
  $table['rows'] = array();
  foreach ($groups as $group) {
    $table[$group->nid] = array(
      '#prefix' => '<tr>',
      'group' => array(
        '#prefix' => '<td>',
        '#markup' => $group->title,
        '#suffix' => '</td>',
      ),
      '#suffix' => '</tr>',
    );
    foreach ($message_types as $message_type) {
      $table[$group->nid][$message_type->name] = array(
        '#prefix' => '<td class="center">',
        '#type' => 'checkbox',
        '#default_value' => isset($defaults['message_types'][$group->nid][$message_type->name]) ?
          $defaults['message_types'][$group->nid][$message_type->name] :
          TRUE,
        '#suffix' => '</td>',
      );
    }
  }
  
  return $table;
}

/**
 * Implements hook_oa_user_settings_form_submit().
 */
function oa_messages_oa_user_settings_form_submit($form_state, $user) {
  return array('oa_messages' => $form_state['values']['oa_messages']);
}
