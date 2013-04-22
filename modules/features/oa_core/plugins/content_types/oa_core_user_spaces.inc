<?php

/**
 * @file
 * Defines the space summary panels pane.
 */

define('SPACE_TAB_FAVORITE', 'Favorite');
define('SPACE_TAB_ACTIVE', 'Subscribed');
define('SPACE_TAB_ALL', 'All');

$plugin = array(
  'title' => t('User Spaces'),
  'description' => t('Provides a list of spaces for a user.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_core_user_spaces_edit_form',
  'render callback' => 'oa_core_user_spaces_render',
  'required context' => new ctools_context_required(t('User'), 'user'),
  'defaults' => array(
    'tabs' => array(SPACE_TAB_FAVORITE, SPACE_TAB_ACTIVE, SPACE_TAB_ALL),
    'image_size' => 'square',
    'show_description' => TRUE,
    'show_sections' => TRUE,
    'show_links' => TRUE,
    'link_class' => 'btn',
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
  $vars = array();

  $spaces = oa_core_get_public_spaces();
  $spaces = node_load_multiple($spaces['node']);
  $all_spaces = oa_core_build_space_display($spaces, $conf);

  $spaces = oa_core_get_user_spaces($user->uid);
  $spaces = node_load_multiple($spaces);
  $active_spaces = oa_core_build_space_display($spaces, $conf);

  $spaces = oa_favorites_get_spaces($user);
  $spaces = node_load_multiple($spaces['ids']);
  $featured_spaces = oa_core_build_space_display($spaces, $conf);

  $vars['space_groups'] = array();
  if ($conf['tabs'][SPACE_TAB_FAVORITE] && !empty($featured_spaces)) {
    $vars['space_groups'][t(SPACE_TAB_FAVORITE)] = $featured_spaces;
  }
  if ($conf['tabs'][SPACE_TAB_ACTIVE] && !empty($active_spaces)) {
    $vars['space_groups'][t(SPACE_TAB_ACTIVE)] = $active_spaces;
  }
  if ($conf['tabs'][SPACE_TAB_ALL]) {
    $vars['space_groups'][t(SPACE_TAB_ALL)] = $all_spaces;
  }

  $vars['title_tag'] = ($conf['show_description']) ? 'h4' : 'div';

  $block = new stdClass();
  if (count($vars['space_groups']) == 1) {
    $block->title = key($vars['space_groups']) . t(' Spaces');
  }
  else {
    $block->title = t('Spaces');
  }
  $block->content = theme('oa_core_user_spaces', $vars);
  return $block;
}


/**
 * Builds display variables for spaces. Optionally sections as well.
 */
function oa_core_build_space_display($spaces, $conf) {
  $vars = array();
  usort($spaces, 'oa_core_sort_node_by_title');
  foreach ($spaces as $space) {
    $vars[$space->nid]['title'] = $space->title;

    $alter = array(
      'max_length' => 600,
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => TRUE,
    );
    $vars[$space->nid]['href'] = url('node/' . $space->nid);
    $vars[$space->nid]['body'] = '';
    $vars[$space->nid]['links'] = '';
    $vars[$space->nid]['sections'] = array();

    if ($conf['show_links']) {
      $vars[$space->nid]['links'] = oa_core_user_spaces_get_links($space, $conf);
    }

    if ($conf['show_description']) {
      $body = field_get_items('node', $space, 'body');
      if (!empty($body[0]['summary'])) {
        $vars[$space->nid]['body'] = $body[0]['summary'];
      }
      else {
        $vars[$space->nid]['body'] = views_trim_text($alter, $body[0]['value']);
      }
    }

    $vars[$space->nid]['picture'] = '';
    if ($conf['image_size'] != 'none') {
      $picture = field_get_items('node', $space, 'field_featured_image');
      if (!empty($picture)) {
        $picture = array_shift($picture);
        $vars[$space->nid]['picture'] = theme('image_style', array(
          'style_name' => 'panopoly_image_' . $conf['image_size'],
          'path' => $picture['uri'],
          'width' => $picture['width'],
          'height' => $picture['height'],
          'alt' => $picture['alt'],
        ));
      }
    }
    if ($conf['show_sections']) {
      $sections = oa_core_space_sections($space->nid);
      foreach ($sections as $id => $title) {
        $vars[$space->nid]['sections'][$id] = l($title, 'node/' . $id);
      }
    }
  }

  return $vars;
}

function oa_core_user_spaces_get_links($space, $conf) {
  $display = array(
    'settings' => array('field_name' => 'og_user_node'),
    'type' => 'og_group_subscribe',
  );
  $links = og_ui_field_formatter_view('node', $space, NULL, NULL, NULL, NULL, $display);
  $vars['links'] = array();
  if (!empty($links) && !empty($conf['link_class'])) {
    foreach ($links as $key => $link) {
      $links[$key]['#attributes'] = array('class' => $conf['link_class']);
    }
  }
  return $links;
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
  $form['tabs'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Tabs'),
    '#options' => array(
      SPACE_TAB_FAVORITE => t(SPACE_TAB_FAVORITE),
      SPACE_TAB_ACTIVE => t(SPACE_TAB_ACTIVE),
      SPACE_TAB_ALL => t(SPACE_TAB_ALL),
    ),
    '#default_value' => $conf['tabs'],
  );

  $form['image_size'] = array(
    '#type' => 'radios',
    '#title' => t('Image size'),
    '#options' => array(
      'square' => t('Square'),
      'quarter' => t('Quarter'),
      'half' => t('Half'),
      'full' => t('Full'),
      'none' => t('None'),
    ),
    '#default' => $conf['image_size'],
  );

  $form['show_links'] = array(
    '#title' => t('Show links'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_links'],
  );
  $form['link_class'] = array(
    '#title' => t('CSS Link class'),
    '#type' => 'textfield',
    '#default_value' => $conf['link_class'],
    '#description' => 'Enter css classes for links, such as btn',
  );
  $form['show_description'] = array(
    '#title' => t('Show description'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_description'],
  );
  $form['show_sections'] = array(
    '#title' => t('Show sections'),
    '#type' => 'checkbox',
    '#default_value' => $conf['show_sections'],
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

