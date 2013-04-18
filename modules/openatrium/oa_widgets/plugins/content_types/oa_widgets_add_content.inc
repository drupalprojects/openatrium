<?php

/**
 * @file
 * Provides a panel pane that displays add content links.
 */

$plugin = array(
  'title' => t('Add content types'),
  'description' => t('List of content types in a widget.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_widgets_add_content_edit_form',
  'render callback' => 'oa_widgets_add_content_render',
  'defaults' => array(
    'oa_widgets_types' => array(),
    'oa_widgets_use_all' => TRUE,
  ),
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_widgets_add_content_render($subtype, $conf, $args, $context = NULL) {
  global $user;

  $nodes = $conf['oa_widgets_types'];

  $links = array();
  foreach ($nodes as $node_type) {
    $node = node_type_load($node_type);
    if (is_object($node) && node_access('create', $node_type)) {
      $links[] = '<li>' . l($node->name, 'node/add/' . str_replace('_', '-', $node_type)) . '</li>';
    }
  }
  $output = '<ul>' . implode($links) . '</ul>';

  $block = new stdClass();
  $block->title = 'Create content';
  $block->content = $output;

  if (!empty($links)) {
    return $block;
  }
  return FALSE;
}

/**
 * Custom edit form to allow users to enable/disable selectable content types
 */
function oa_widgets_add_content_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $nodes = oa_core_list_content_types();

  $options = array();
  foreach ($nodes as $node) {
    $options[$node->type] = check_plain($node->name);
  }
  $form['settings']['oa_widgets_types'] = array(
    '#title' => t('Enable content types'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => isset($conf['oa_widgets_types']) ? $conf['oa_widgets_types'] : array_values($options),
    '#description' => t('Select which content types you would like to enable for this widget.'),
  );

  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_widgets_add_content_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

