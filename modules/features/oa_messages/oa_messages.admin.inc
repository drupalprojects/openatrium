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
  
  $form['#attached']['js'][] = drupal_get_path('module', 'oa_messages') . '/js/oa-messages-settings.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'oa_messages') . '/css/oa-messages-settings.css';
}

/**
 * Build a table of notification types per group, much like
 * the permissions table.
 */
function oa_messages_build_message_types_table($user, $defaults = array()) {
  $groups = node_load_multiple(oa_groups_get_user_groups($user->uid));
  $message_types = message_type_load();
  
  // Split them out by module.
  $message_types_modules = array();
  foreach ($message_types as $type) {
    $module = $type->module ? $type->module : 'Custom';
    $message_types_modules[$module][] = $type;
  }
  
  $form = array(
    'tabs' => array(
      '#prefix' => '<ul id="messages-tabs" class="nav nav-tabs">',
      '#suffix' => '</ul>',
    ),
    'tables' => array(
      '#prefix' => '<div class="tab-content">',
      '#suffix' => '</div>',
    ),
  );
  
  foreach ($message_types_modules as $module => $message_types) {
    $module_info = system_get_info('module', $module);
    $module_name = $module_info ? $module_info['name'] : $module;
    $form['tabs'][$module] = array(
      '#prefix' => '<li><a href="#message-settings-' . $module . '" data-toggle="tab">',
      '#markup' => $module_name,
      '#suffix' => '</a></li>',
    );
    
    $table = array(
      '#prefix' => '<div id="message-settings-' . $module . '" class="tab-pane"><table class="table table-bordered table-striped table-hover checkbox-table">',
      '#suffix' => '</table></div>',
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
      $table['rows'][$group->nid] = array(
        '#prefix' => '<tr>',
        'group' => array(
          '#prefix' => '<td class="group-label">',
          '#markup' => $group->title,
          '#suffix' => '</td>',
        ),
        '#suffix' => '</tr>',
      );
      
      $notifiers = oa_message_notifiers();
      foreach ($message_types as $message_type) {
        $table['rows'][$group->nid][$message_type->name] = array(
          '#prefix' => '<td class="center">',
          '#suffix' => '</td>',
        );
        foreach ($notifiers as $notifier) {
          $value = isset($defaults['message_types'][$group->nid][$message_type->name][$notifier]) ?
            $defaults['message_types'][$group->nid][$message_type->name][$notifier] :
            TRUE;

          $table['rows'][$group->nid][$message_type->name][$notifier] = array(
            '#type' => 'checkbox',
            '#default_value' => $value,
            '#field_prefix' => '<span class="label">' . $notifier . '</span>',
          );
        }
      }
    }
    
    $form['tables'][$module] = $table;
  }
  
  return $form;
}

/**
 * Implements hook_oa_user_settings_form_submit().
 */
function oa_messages_oa_user_settings_form_submit($form_state, $user) {
  return array('oa_messages' => $form_state['values']['oa_messages']);
}
