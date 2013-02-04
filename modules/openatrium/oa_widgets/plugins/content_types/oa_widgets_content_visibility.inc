<?php

$plugin = array(
  'title' => t('Content Visibility'),
  'description' => t('Show content visibility.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_widgets_content_visibility_edit_form',
  'render callback' => 'oa_widgets_content_visibility_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_widgets_content_visibility_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  $block = new stdClass();
  $block->title = 'Content Visibility';

  $discussion_node = $context->data;
  $group_reference_field = field_get_items('node', $discussion_node, OA_GROUP_FIELD);
  $section_reference_field = field_get_items('node', $discussion_node, OA_SECTION_FIELD);
  $section_node = node_load($section_reference_field[0]['target_id']);
  $group_node = node_load($group_reference_field[0]['target_id']);
  $node_is_public = oa_groups_section_is_public($section_node);
  $block_content = '';
  if ($node_is_public) {
    $block_content = '<p>PUBLIC</p>';
  }
  else {
    $block_content = '<p>PRIVATE</p>';
    $section_organization_field = field_get_items('node', $section_node, OA_ORG_FIELD);
    if (!empty($section_organization_field)) {
      $block_content .= '<p>Organizations: ';
      $organization_node_links =  array();
      foreach ($section_organization_field as $organization_reference) {
        $organization_node = node_load($organization_reference['target_id']);
        $organization_node_links[] = l($organization_node->title, 'node/' . $organization_node->nid);
      }
      $block_content .= implode(' ', $organization_node_links) . '</p>';
    }
    $section_team_field =  field_get_items('node', $section_node, OA_TEAM_FIELD);
    if (!empty($section_team_field)) {
      $block_content .= '<p>Teams: ';
      $team_node_links = array();
      foreach ($section_team_field as $team_reference) {
        $team_node = node_load($team_reference['target_id']);
        $team_node_links[] = l($team_node->title, 'node/' . $team_node->nid);
      }
      $block_content .= implode(' ', $team_node_links) . '</p>';
    }
    $section_user_ref_field = field_get_items('node', $section_node, OA_USER_FIELD);
    if (!empty($section_user_ref_field)) {
      $block_content .= '<p>Users: ';
      $user_names = array();
      foreach ($section_user_ref_field as $user_reference) {
        $user_object = user_load($user_reference['target_id']);
        $user_names[] = l($user_object->name, 'user/' . $user_object->uid);
      }
      $block_content .= implode(' ', $user_names) . '</p>';
    }
    $block_content .= '<p>Group: ' . l($group_node->title, 'node/' . $group_node->nid) . '</p>';
    $block_content .= '<p>Section: ' . l($section_node->title, 'node/' . $section_node->nid) . '</p>';
  }
  $block->content = $block_content;

  return $block;
}

/**
 * Custom edit form to allow users to enable/disable selectable content types
 */
function oa_widgets_content_visibility_edit_form($form, &$form_state) {
  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_widgets_content_visibility_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

