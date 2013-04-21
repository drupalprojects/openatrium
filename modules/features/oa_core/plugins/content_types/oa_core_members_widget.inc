<?php

/**
 * @file
 * Defines the space members panels pane.
 */

$plugin = array(
  'title' => t('Members'),
  'description' => t("Show the owners, teams, and members of a Space"),
  'single' => TRUE,
  'category' => t('Open Atrium'),
  'edit form' => 'oa_core_members_widget_edit_form',
  'render callback' => 'oa_core_members_widget_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'hide_owner' => FALSE,
    'hide_teams' => FALSE,
    'show_number' => 10,
  ),
);


/**
 * Main render function for oa_core_members_widget.
 */
function oa_core_members_widget_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }

  $block = new stdClass();
  $block->title = 'Members';

  $space = $context->data;
  $teams = oa_teams_get_teams_for_space($space->nid);
  $teams = node_load_multiple(array_keys($teams));
  $members = oa_core_get_users_for_space($space->nid);
  uasort($members, '_oa_core_sort_user_by_name');
  $owners = array();

  foreach ($members as $member) {
    $roles = og_get_user_roles('node', $space->nid, $member->uid);
    if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
      $owners[$member->uid] = $member;
    }
  }

  $members = array_slice($members, 0, 4);

  $vars = array();
  $items = array(
    'teams' => $teams,
    'members' => $members,
    'owners' => $owners,
  );
  foreach ($items as $key => $entities) {
    $vars[$key] = array();
    foreach ($entities as $id => $entity) {
      $vars[$key][$id] = oa_core_entity_build_display($entity, $id);
    }
  }

  if (!isset($conf['show_number']) || ($conf['show_number'] != '0')) {
    $vars['see_all_link'] = l('See all members', 'node/' . $space->nid . '/members');
  }
  else {
    $vars['see_all_link'] = '';
  }

  if (!empty($conf['hide_owner'])) {
    unset($vars['owners']);
  }
  if (!empty($conf['hide_teams'])) {
    unset($vars['teams']);
  }
  $block->content = theme('oa_core_members_widget', $vars);
  return $block;
}

/**
 * Sort function to sort users by name.
 */
function _oa_core_sort_user_by_name($u1, $u2) {
  // Get last name for sorting.
  $name1 = $u1->realname ? array_pop(explode(' ', $u1->realname)) : $u1->name;
  $name2 = $u2->realname ? array_pop(explode(' ', $u2->realname)) : $u2->name;
  return strcasecmp($name1, $name2);
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_core_entity_build_display($entity, $id) {
  $type = isset($entity->nid) ? 'node' : 'user';
  $title = ($type == 'user') ?
    (empty($entity->realname) ? $entity->name : $entity->realname) :
    $entity->title;
  $display['title'] = l($title, $type . '/' . $id);

  if ($type == 'user') {
    $display['picture'] = oa_dashboard_render_user_picture($entity);
  }
  else {
    $display['picture'] = '';
  }

  return $display;
}

/**
 * Edit form for the widget.
 */
function oa_core_members_widget_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['hide_owner'] = array(
    '#title' => t('Hide space owner'),
    '#type' => 'checkbox',
    '#default_value' => isset($conf['hide_owner']) ? $conf['hide_owner'] : FALSE,
  );
  $form['hide_teams'] = array(
    '#title' => t('Hide teams'),
    '#type' => 'checkbox',
    '#default_value' => isset($conf['hide_teams']) ? $conf['hide_teams'] : FALSE,
  );
  $form['show_number'] = array(
    '#title' => t('Number of members to show'),
    '#type' => 'textfield',
    '#default_value' => isset($conf['show_number']) ? $conf['show_number'] : '10',
    '#description' => 'Enter zero to show all members.'
  );

  return $form;
}

function oa_core_members_widget_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

