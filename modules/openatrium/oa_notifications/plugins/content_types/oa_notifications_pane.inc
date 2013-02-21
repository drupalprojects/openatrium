<?php
/**
 * @file oa_notifications_pane.inc
 */

$plugin = array(
  'title' => t('Notifications'),
  'description' => t('Displays the list of Organizations, Teams and Users that will be notified of a change to an Entity.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'render callback' => 'oa_notifications_pane_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  //'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the pane.
 *
 * @see ctools_plugin_examples for more advanced info
 */
function oa_notifications_pane_render($subtype, $conf, $args, $context) {
  $node = isset($context->data) ? $context->data : NULL;

  $has_edit = node_access('update', $node);
  $output = $has_edit
      ? drupal_get_form('oa_notifications_edit_form', $node)
      : oa_notifications_render_view($node);

  $block = new stdClass();
  $block->title = t('Notifications');
  $block->content = $output;
  return $block;
}

/**
 * Render the read only version of the notifications listing.
 *
 * @param object $node
 *    The node being viewed/edited
 *
 * @return
 *    A render array of the notification configuration
 */
function oa_notifications_render_view($node) {
  $render = array('#theme' => "oa_notifications_view");
  $notifications = oa_notifications_load_multiple($node->nid);

  if (array_key_exists('organization', $notifications)) {
    $orgs = node_load_multiple(array_keys($notifications['organization']));
    foreach ($orgs as $org) {
      $render['#organization'][] = $org->title;
    }
  }

  if (array_key_exists('team', $notifications)) {
    $teams = node_load_multiple(array_keys($notifications['team']));
    foreach ($teams as $team) {
      $render['#team'][] = $team->title;
    }
  }

  if (array_key_exists('user', $notifications)) {
    $users = user_load_multiple(array_keys($notifications['user']));
    foreach ($users as $user) {
      $render['#user'][] = array(
        'name' => $user->name,
        'access' => node_access('view', $node, $user),
      );
    }
  }

  // Attach the bootstrap tooltip in case there is an access denied user.
  drupal_add_js('jQuery(document).ready(function () {
    jQuery("span.label-important").tooltip();
  });', 'inline');

  return $render;
}

/**
 * Render the edit form for Notifications
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $node
 *    The node being viewed/edited
 * @return
 *    The form
 */
function oa_notifications_edit_form($form, &$form_state, $node) {
  $form['source_type'] = array(
    '#type' => 'value',
    '#value' => 'node',
  );
  $form['source_id'] = array(
    '#type' => 'value',
    '#value' => $node->nid
  );

  $notifications = oa_notifications_load_multiple($node->nid);
  //dpm($notifications, "Notifications");

  $all_orgs = oa_notifications_get_orgs();
  $form['organization'] = array(
    '#type' => 'select',
    '#title' => t('Organizations'),
    '#multiple' => TRUE,
    '#options' => array_map(create_function('$org', 'return $org->title;'), $all_orgs),
    '#default_value' => array_key_exists('organization', $notifications) ? array_keys($notifications['organization']) : array(),
  );

  $group_teams = oa_notifications_get_teams_for_group();
  $form['team'] = array(
    '#type' => 'select',
    '#title' => t('Teams'),
    '#multiple' => TRUE,
    '#options' => array_map(create_function('$team', 'return $team->title;'), $group_teams),
    '#default_value' => array_key_exists('team', $notifications) ? array_keys($notifications['team']) : array(),
  );

  $group_users = oa_notifications_get_users_for_group();
  $form['user'] = array(
    '#type' => 'select',
    '#title' => t('Users'),
    '#multiple' => TRUE,
    '#options' => array_map(create_function('$user', 'return $user->name;'), $group_users),
    '#default_value' => array_key_exists('user', $notifications) ? array_keys($notifications['user']) : array(),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  return $form;
}

/**
 * Submit handler for the Notifications Pane
 */
function oa_notifications_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $source_id = $values['source_id'];
  $source_type = $values['source_type'];

  $notifications = array();
  foreach (array('organization', 'team', 'user') as $type) {
    foreach ($values[$type] as $id) {
      $n = new stdClass;
      $n->source_id = $source_id;
      $n->source_type = $source_type;
      $n->target_id = $id;
      $n->target_type = $type;
      $notifications[] = $n;
    }
  }

  oa_notifications_save_for_source($source_id, $source_type, $notifications);
}