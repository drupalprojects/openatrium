<?php

define('FEATURED_NONE', 0);
define('FEATURED_FAVORITES', 1);
define('FEATURED_MOST_RECENT', 2);
define('FEATURED_ACTIVITY', 3);

$plugin = array(
  'title' => t('Space summary'),
  'description' => t('Provides a summary of a space, including the picture, description, and useful links.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_core_user_spaces_edit_form',
  'render callback' => 'oa_core_user_spaces_render',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'defaults' => array(
    'featured_spaces' => FEATURED_FAVORITES,
  ),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_core_user_spaces_render($subtype, $conf, $args, $context = NULL) {
  if (empty($context->data)) {
    return;
  }
  $user = $context->data;
  $spaces = node_load_multiple(oa_core_get_user_spaces($user->uid));
  $vars = array();
  $vars['spaces'] = oa_core_build_display($spaces);

  $featured_spaces = oa_core_build_featured_spaces($user, $conf['featured_spaces']);
  $vars['featured_spaces'] = $featured_spaces['spaces'];
  $vars['featured_spaces_title'] = $featured_spaces['title'];

  $block = new stdClass();
  $block->title = t('My Spaces');
  $block->content = theme('oa_core_user_spaces', $vars);
  return $block;
}


/**
 * Build the list of featured spaces based on the settings.
 */
function oa_core_build_featured_spaces($user, $option) {
  $spaces = array();
  $title = '';
  if ($option == FEATURED_NONE) {
    return array('', $title);
  }
  elseif ($option == FEATURED_FAVORITES) {
    $title = t('Favorites');
    $spaces = oa_favorites_get_spaces($user);
    $spaces = node_load_multiple($spaces['ids']);
  }

  return array(
    'title' => $title,
    'spaces' => oa_core_build_display($spaces, FALSE),
  );
}


/**
 * Builds display variables for spaces. Optionally sections as well.
 */
function oa_core_build_display($spaces, $build_sections = TRUE) {
  $vars = array();
  usort($spaces, 'oa_core_sort_node_by_title');
  foreach ($spaces as $space) {
    $vars[$space->nid]['title'] = $space->title;
    $vars[$space->nid]['href'] = url('node/' . $space->nid);
    $vars[$space->nid]['sections'] = array();
    if ($build_sections) {
      $sections = oa_core_space_sections($space->nid);
      foreach ($sections as $id => $title) {
        $vars[$space->nid]['sections'][$id]['title'] = $title;
        $vars[$space->nid]['sections'][$id]['href'] = url('node/' . $id);
      }
    }
  }

  return $vars;
}


/**
 * Sort function, sorts nodes by title.
 */
function oa_core_sort_node_by_title($n1, $n2) {
  return strcasecmp($n1->title, $n2->title);
}


/**
 * Edit form for the panel.
 */
function oa_core_user_spaces_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['featured_spaces'] = array(
    '#type' => 'radios',
    '#title' => t('Featured spaces'),
    '#options' => array(
      FEATURED_NONE => t('None'),
      FEATURED_FAVORITES => t('Favorites'),
      FEATURED_MOST_RECENT => t('Most recent'),
      FEATURED_ACTIVITY => t('Activity'),
    ),
    '#default_value' => isset($conf['featured_spaces']) ? $conf['featured_spaces'] : FEATURED_FAVORITES,
  );

  return $form;
}


/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_core_user_spaces_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

