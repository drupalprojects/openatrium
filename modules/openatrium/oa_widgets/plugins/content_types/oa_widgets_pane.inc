<?php

$plugin = array(
  'title' => t('Add content types'),
  'description' => t('List of content types in a widget.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium Groups'), -9),
  'edit form' => 'oa_widgets_content_type_edit_form',
  'render callback' => 'oa_widgets_content_type_render',
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_widgets_content_type_render($subtype, $conf, $context = NULL) {
  $nodes = $conf['types'];

  $links = array();
  foreach ($nodes as $node) {
    $node = node_type_load($node);
    if (is_object($node) && user_access('create ' . $node->type . ' content')) {
      $links[] = '<li>' . l($node->name, 'node/add/' . str_replace('_', '-', $node->type)) . '</li>';
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
function oa_widgets_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $nodes = oa_list_content_types();

  $options = array();
  foreach ($nodes as $node) {
    $options[$node->type] = check_plain($node->name);
  }
  $form['types'] = array(
    '#title' => t('Enable content types'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => $conf['types'],
    '#description' => t('Select which content types you would like to enable for this widget.'),
  );

  return $form;
}


/**
 * Saves changes to the widget.
 */
function oa_widgets_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

