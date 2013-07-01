<?php

/**
 * @file
 * Defines the space members panels pane.
 */

$plugin = array(
  'title' => t('Space Members'),
  'description' => t("Show the owners, teams, and members of a Space"),
  'single' => TRUE,
  'category' => t('Open Atrium'),
  'edit form' => 'oa_core_members_widget_edit_form',
  'render callback' => 'oa_core_members_widget_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'hide_owner' => FALSE,
    'hide_teams' => FALSE,
    'hide_members' => FALSE,
    'hide_inherited' => FALSE,
    'show_number' => 10,
  ),
);


/**
 * Main render function for oa_core_members_widget.
 */
function oa_core_members_widget_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  if (!isset($context->data->nid) || !($space = oa_core_get_group_from_node($context->data->nid)) || !node_access('view', $space)) {
    return;
  }

  $is_admin = og_user_access('node', $space->nid, 'manage members');

  $block = new stdClass();
  $block->title = t('Members');

  if (empty($conf['hide_teams']) && module_exists('oa_teams') && ($teams = oa_teams_get_teams_for_space($space->nid))) {
    $teams = node_load_multiple(array_keys($teams));
  }
  else {
    $teams = array();
  }
  $members = empty($conf['hide_owner']) || empty($conf['hide_members']) ? oa_core_get_users_for_space($space->nid) : array();
  uasort($members, '_oa_core_sort_user_by_name');
  $owners = array();
  if (empty($conf['hide_owner'])) {
    foreach ($members as $member) {
      $roles = og_get_user_roles('node', $space->nid, $member->uid);
      if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $space->uid) {
        $owners[$member->uid] = $member;
      }
    }
  }

  $parents = array();
  if (empty($conf['hide_inherited']) && $is_admin && ($parent_field = field_get_items('node', $space, 'oa_parent_space'))) {
    foreach ($parent_field as $parent) {
      if (!empty($parent['target_id'])) {
        $parents[$parent['target_id']] = $parent['target_id'];
      }
    }
    $parents = node_load_multiple(array_keys($parents));
  }

  $vars = array();

  $show_number = isset($conf['show_number']) ? $conf['show_number'] : 10;
  if ($show_number > 0) {
    $vars['see_all_link'] = l(t('See all members'), 'node/' . $space->nid . '/members');
    $members = array_slice($members, 0, $show_number-1);
  }
  else {
    $vars['see_all_link'] = '';
  }

  $space_title = node_type_get_name($space->type);
  $vars['title'] = array(
    'teams' => t('Teams'),
    'members' => check_plain($space_title),
    'owners' => t('@type administrators', array('@type' => $space_title)),
    'parents' => t('Inheriting members from'),
  );
  $items = array(
    'teams' => $teams,
    'members' => empty($conf['hide_members']) ? $members : array(),
    'owners' => $owners,
    'parents' => $parents,
  );
  foreach ($items as $key => $entities) {
    $vars[$key] = array();
    if ($entities) {
      foreach ($entities as $id => $entity) {
        $vars[$key][$id] = oa_core_entity_build_display($entity, $id, $space);
        if ($entity->uid == $space->uid) {
          // don't show links for main space owner
          $vars[$key][$id]['uid'] = 0;
        }
      }
    }
    else {
      unset($vars['title'][$key]);
    }
  }
  if (count($vars['title']) == 1) {
    unset($vars['title']);
  }

  $vars['links']['dashboard'] = 'user/';
  if ($is_admin) {
    $vars['links']['remove'] = 'group/node/' . $space->nid . '/remove/single/';
    $vars['links']['add-admin'] = 'group/node/' . $space->nid . '/add-admin/';
    $vars['links']['remove-admin'] = 'group/node/' . $space->nid . '/remove-admin/';
    if (og_user_access('node', $space->nid, 'administer group') && module_exists('oa_subspaces') && og_subgroups_children_load('node', $space->nid, FALSE)) {
      $vars['links']['remove-child'] = 'group/node/' . $space->nid . '/remove/all/';
    }
  }
  else {
    $vars['links']['remove'] = '';
    $vars['links']['add-admin'] = '';
    $vars['links']['remove-admin'] = '';
  }

  $block->content = theme('oa_core_members_widget', $vars);
  return $block;
}

/**
 * Sort function to sort users by name.
 */
function _oa_core_sort_user_by_name($u1, $u2) {
  // Get last name for sorting.
  $name1 = !empty($u1->realname) ? oa_core_get_last_word($u1->realname) : $u1->name;
  $name2 = !empty($u2->realname) ? oa_core_get_last_word($u2->realname) : $u2->name;
  return strcasecmp($name1, $name2);
}

function oa_core_get_last_word($string) {
  return ($pos =  strrpos($string, ' ')) ?  substr($string, $pos + 1) : $string;
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_core_entity_build_display($entity, $id, $space) {
  if (!empty($entity->nid)) {
    if (node_access('view', $entity)) {
      $display['title'] = l($entity->title, 'node/' . $entity->nid);
    }
    else {
      $display['title'] = t('A @type', array('@type' => array('@type' => node_type_get_name($entity->type))));
    }
    $display['picture'] = '';
    $display['uid'] = 0;
    $display['options'] = array();
  }
  else {
    $display['title'] = l(format_username($entity), 'user/' . $entity->uid);
    $display['uid'] = $entity->uid;
    $display['picture'] = oa_users_picture($entity);
    $display['options'] = array(
      'attributes' => array(
        'class' => array('use-ajax'),
      ),
      'query' => drupal_get_destination() + array(
        'token' => drupal_get_token('node_' . $space->nid . '_' . $entity->uid),
      ),
    );
  }

  return $display;
}

/**
 * Edit form for the widget.
 */
function oa_core_members_widget_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['hide_owner'] = array(
    '#title' => t('Hide administrators'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_owner'],
  );
  $form['hide_teams'] = array(
    '#title' => t('Hide teams'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_teams'],
  );
  $form['hide_members'] = array(
    '#title' => t('Hide members'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_members'],
  );
  $form['hide_inherited'] = array(
    '#title' => t('Hide inherited'),
    '#type' => 'checkbox',
    '#default_value' => $conf['hide_inherited'],
  );
  $form['show_number'] = array(
    '#title' => t('Number of members to show'),
    '#type' => 'textfield',
    '#default_value' => $conf['show_number'],
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

