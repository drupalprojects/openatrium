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
    'space' => t('Space'),
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
 * Build a table of notification types per space, much like
 * the permissions table.
 */
function oa_messages_build_message_types_table($user, $defaults = array()) {
  $spaces = node_load_multiple(oa_core_get_user_spaces($user->uid));
  $message_types = message_type_load();
  $table = array(
    '#prefix' => '<table class="table table-bordered table-striped table-hover checkbox-table">',
    '#suffix' => '</table>',
    '#tree' => TRUE,
  );

  $table['header'] = array(
    '#prefix' => '<thead><tr>',
    'space' => array(
      '#prefix' => '<th>',
      '#markup' => t('Space'),
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
  foreach ($spaces as $space) {
    $table[$space->nid] = array(
      '#prefix' => '<tr>',
      'space' => array(
        '#prefix' => '<td>',
        '#markup' => $space->title,
        '#suffix' => '</td>',
      ),
      '#suffix' => '</tr>',
    );
    foreach ($message_types as $message_type) {
      $table[$space->nid][$message_type->name] = array(
        '#prefix' => '<td class="center">',
        '#type' => 'checkbox',
        '#default_value' => isset($defaults['message_types'][$space->nid][$message_type->name]) ?
          $defaults['message_types'][$space->nid][$message_type->name] :
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
