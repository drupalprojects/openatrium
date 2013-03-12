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
  'defaults' => array(
    'display_type' => WIDGET_TITLE_AND_PICTURE,
  ),
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
  $roles = array();
  $owners = array();
  foreach ($members as $member) {
    $roles[$member->uid] = og_get_user_roles('node', $group->nid, $member->uid);
    if (in_array(OG_ADMINISTRATOR_ROLE, $roles[$member->uid])) {
      $owners[] = $member;
    }
  }
  
  $vars = array();
  $items = array(
    'teams' => $teams,
    'members' => $members,
    'owners' => $owners,
  );
  foreach ($items as $key => $entities) {
    foreach ($entities as $id => $entity) {
      $vars[$key][$id] = oa_groups_entity_build_display($entity, $id, $roles[$id]);
    }
  }
  
  $block->content = theme('oa_groups_members_widget', $vars);
  return $block;
}

/**
 * Convert known entities in to a simple array of title and picture.
 */
function oa_groups_entity_build_display($entity, $id, $roles) {
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
  $conf = $form_state['conf'];
  $form['display_type'] = array(
    '#type' => 'select',
    '#title' => t('Display mode'),
    '#options' => array(
      WIDGET_TITLE_AND_PICTURE => t('Title and picture'),
      WIDGET_TITLE_ONLY => t('Title only'),
      WIDGET_PICTURE_ONLY => t('Picture only'),
    ),
    '#default_value' => empty($conf['display_type']) ? WIDGET_TITLE_AND_PICTURE : $form_state['conf']['display_type'],
  );

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_groups_members_widget_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
