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
  $block = new stdClass();
  $block->title = '';

  $node = $context->data;
  // no threaded discussions, so if parent is already set, get it's parent
  if (isset($node->oa_parent[LANGUAGE_NONE][0]['target_id'])) {
    $nid = $node->oa_parent[LANGUAGE_NONE][0]['target_id'];
  }
  else {
    $nid = $node->nid;
  }
  $block->content = theme('oa_discussion_reply', array(
    'parent_id' => $nid));

  return $block;
}

/**
 * Custom edit form to allow users to enable/disable selectable content types
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
