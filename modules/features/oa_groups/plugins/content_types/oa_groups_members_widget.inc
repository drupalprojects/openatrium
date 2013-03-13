<?php

define('WIDGET_TITLE_AND_PICTURE', 0);
define('WIDGET_TITLE_ONLY', 1);
define('WIDGET_PICTURES_ONLY', 2);

$plugin = array(
  'title' => t('Group Members'),
  'description' => t("Provide information about a group's members and teams, and quick links to add to it."),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_groups_members_widget_edit_form',
  'render callback' => 'oa_groups_members_widget_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Main render function for oa_groups_members_widget.
 */
function oa_groups_members_widget_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  
  $block = new stdClass();
  $block->title = 'Group Members';
  
  $group = $context->data;
  $teams = oa_teams_get_teams_for_group($group->nid);
  $teams = node_load_multiple(array_keys($teams));
  $members = oa_groups_get_users_for_group($group->nid);
  uasort($members, '_oa_groups_sort_user_by_name');
  $owners = array();
  
  foreach ($members as $member) {
    $roles = og_get_user_roles('node', $group->nid, $member->uid);
    if (in_array(OG_ADMINISTRATOR_ROLE, $roles) || $member->uid == $group->uid) {
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
    foreach ($entities as $id => $entity) {
      $vars[$key][$id] = oa_groups_entity_build_display($entity, $id);
    }
  }
  
  $block->content = theme('oa_groups_members_widget', $vars);
  return $block;
}

/**
 * Sort function to sort users by name.
 */
function _oa_groups_sort_user_by_name($u1, $u2) {
  // Get last name for sorting.
  $name1 = $u1->realname ? array_pop(explode(' ', $u1->realname)) : $u1->name;
  $name2 = $u2->realname ? array_pop(explode(' ', $u2->realname)) : $u2->name;
  return strcasecmp($name1, $name2);
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_groups_entity_build_display($entity, $id) {
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
function oa_groups_members_widget_edit_form($form, &$form_state) {
  return $form;
}
