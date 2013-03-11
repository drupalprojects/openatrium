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
  $render = array(
    '#theme' => "oa_notifications_view",
    '#node' => $node,
  );
  $notifications = oa_notifications_load_multiple($node->nid);

  if (array_key_exists('organization', $notifications)) {
    $orgs = node_load_multiple(array_keys($notifications['organization']));
    foreach ($orgs as $org) {
      $render['#organization'][$org->nid] = $org->title;
    }
  }

  if (array_key_exists('team', $notifications)) {
    $teams = node_load_multiple(array_keys($notifications['team']));
    foreach ($teams as $team) {
      $render['#team'][$team->nid] = $team->title;
    }
  }

  if (array_key_exists('user', $notifications)) {
    $users = user_load_multiple(array_keys($notifications['user']));
    foreach ($users as $user) {
      $render['#user'][] = array(
        'uid' => $user->uid,
        'name' => $user->realname,
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
  // Since this form functions via AJAX we need to tell the form handlers to include it when processing the form
  ctools_form_include_file($form_state, drupal_get_path('module', 'oa_notifications') . '/plugins/content_types/oa_notifications_pane.inc');

  oa_notifications_form_fields($form, $form_state, $node);

  // Add things for direct pane updates
  $form['organization']['#ajax'] = array(
    'callback' => 'oa_notifications_ajax_callback',
    'wrapper' => 'organization-div',
    'method' => 'replace',
  );
  $form['organization']['#prefix'] = '<div id="organization-div">';
  $form['organization']['#suffix'] = '</div>';

  $form['team']['#ajax'] = array(
    'callback' => 'oa_notifications_ajax_callback',
    'wrapper' => 'team-div',
    'method' => 'replace',
  );
  $form['team']['#prefix'] = '<div id="team-div">';
  $form['team']['#suffix'] = '</div>';

  $form['user']['#ajax'] = array(
    'callback' => 'oa_notifications_ajax_callback',
    'wrapper' => 'user-div',
    'method' => 'replace',
  );
  $form['user']['#prefix'] = '<div id="user-div">';
  $form['user']['#suffix'] = '</div>';

  $details = l(t('Show Details'), 'js/oa_notifications/details/' . $node->nid, array('attributes' => array('data-toggle' => 'modal', 'data-target' => '#oa-notifications-details')));
  $details .= theme('oa_styles_modal', array('modal_id' => 'oa-notifications-details', 'title' => t('Notification Details')));

  $form['details'] = array(
    '#type' => 'markup',
    '#markup' => $details,
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Submit handler for the Notifications Pane
 */
function oa_notifications_edit_form_submit($form, &$form_state) {
  oa_notifications_save_notifications($form_state['values']);
}
