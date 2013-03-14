<?php

define('FEATURED_NONE', 0);
define('FEATURED_FAVORITES', 1);
define('FEATURED_MOST_RECENT', 2);
define('FEATURED_ACTIVITY', 3);

$plugin = array(
  'title' => t('Group summary'),
  'description' => t('Provides a summary of a group, including the picture, description, and useful links.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_groups_user_groups_edit_form',
  'render callback' => 'oa_groups_user_groups_render',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'defaults' => array(
    'featured_groups' => FEATURED_FAVORITES,
  ),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_groups_user_groups_render($subtype, $conf, $args, $context = NULL) {
  if (empty($context->data)) {
    return;
  }
  $user = $context->data;
  $groups = node_load_multiple(oa_groups_get_user_groups($user->uid));
  $vars = array();
  $vars['groups'] = oa_groups_build_display($groups);
  
  $featured_groups = oa_groups_build_featured_groups($user, $conf['featured_groups']);
  $vars['featured_groups'] = $featured_groups['groups'];
  $vars['featured_groups_title'] = $featured_groups['title'];
  
  $block = new stdClass();
  $block->title = t('My Groups');
  $block->content = theme('oa_groups_user_groups', $vars);
  return $block;
}


/**
 * Build the list of featured groups based on the settings.
 */
function oa_groups_build_featured_groups($user, $option) {
  $groups = array();
  $title = '';
  if ($option == FEATURED_NONE) {
    return array('', $title);
  }
  elseif ($option == FEATURED_FAVORITES) {
    $title = t('Favorites');
    $groups = oa_favorites_get_groups($user);
    $groups = node_load_multiple($groups['ids']);
  }
  
  return array(
    'title' => $title,
    'groups' => oa_groups_build_display($groups, FALSE),
  );
}


/**
 * Builds display variables for groups. Optionally sections as well.
 */
function oa_groups_build_display($groups, $build_sections = TRUE) {
  $vars = array();
  usort($groups, 'oa_groups_sort_node_by_title');
  foreach ($groups as $group) {
    $vars[$group->nid]['title'] = $group->title;
    $vars[$group->nid]['href'] = url('node/' . $group->nid);
    $vars[$group->nid]['sections'] = array();
    if ($build_sections) {
      $sections = oa_groups_group_sections($group->nid);
      foreach ($sections as $id => $title) {
        $vars[$group->nid]['sections'][$id]['title'] = $title;
        $vars[$group->nid]['sections'][$id]['href'] = url('node/' . $id);
      }
    }
  }
  
  return $vars;
}


/**
 * Sort function, sorts nodes by title.
 */
function oa_groups_sort_node_by_title($n1, $n2) {
  return strcasecmp($n1->title, $n2->title);
}


/**
 * Edit form for the panel.
 */
function oa_groups_user_groups_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['featured_groups'] = array(
    '#type' => 'radios',
    '#title' => t('Featured groups'),
    '#options' => array(
      FEATURED_NONE => t('None'),
      FEATURED_FAVORITES => t('Favorites'),
      FEATURED_MOST_RECENT => t('Most recent'),
      FEATURED_ACTIVITY => t('Activity'),
    ),
    '#default_value' => isset($conf['featured_groups']) ? $conf['featured_groups'] : FEATURED_FAVORITES,
  );

  return $form;
}


/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_groups_user_groups_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

