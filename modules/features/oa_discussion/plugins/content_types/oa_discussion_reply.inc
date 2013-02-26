<?php

$plugin = array(
  'title' => t('Reply button'),
  'description' => t('Reply to current content.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_discussion_reply_edit_form',
  'render callback' => 'oa_discussion_reply_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_discussion_reply_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  $node = $context->data;
  // only show reply form if user is allowed to create a reply
  if (!node_access('create', $node)) {
    return;
  }
  $output = drupal_get_form('oa_discussion_reply_form', $node);

  $block = new stdClass();
  $block->title = t('Quick Reply');
  $block->content = $output;
  return $block;
}

/**
 * Empty config form
 */
function oa_discussion_reply_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Saves changes to the widget.
 */
function oa_discussion_reply_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['values']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render the edit form for Replies
 *
 * @param $form
 *    The FAPI array
 * @param $form_state
 *    The state of the form
 * @param $node
 *    The node being viewed/edited
 * @return
 *    The form
 */
function oa_discussion_reply_form($form, &$form_state, $node) {
  $parent = field_get_items('node', $node, 'oa_parent');
  $parent_id = !empty($parent[0]['target_id']) ? $parent[0]['target_id'] : 0;

  $form['oa_reply']['body'] = array(
    '#type' => 'text_format',
    '#default_value' => '',
    '#format' => 'panopoly_wysiwyg_text',
  );

  $form['oa_reply']['reply'] = array(
    '#markup' => theme('oa_discussion_reply', array('parent_id' => $parent_id)),
    '#suffix' => '&nbsp;',
  );

  $form['oa_reply']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Reply'),
  );
  return $form;
}

/**
 * Submit handler for the Notifications Pane
 */
function oa_discussion_reply_form_submit($form, &$form_state) {
  dsm('REPLY SUBMITTED');
}
