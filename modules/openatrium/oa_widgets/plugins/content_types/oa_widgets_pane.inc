<?php
/**
 * This plugin array is more or less self documenting
 */
$plugin = array(
  // the title in the admin
  'title' => t('Add content'),
  'description' => t('asdf'),
  // no one knows if "single" defaults to FALSE...
  'single' => TRUE,
  // oh joy, I get my own section of panel panes
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
 * 'Edit form' callback for the content type.
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
 * Submit function, note anything in the formstate[conf] automatically gets saved 
 */
function oa_widgets_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

