<?php

$plugin = array(
  'title' => t('Reply button'),
  'description' => t('Reply to current content.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'render callback' => 'oa_discussion_reply_render',
);


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function oa_discussion_reply_render($subtype, $conf, $args, $context = NULL) {
  $block = new stdClass();
  $block->title = '';

  $node = menu_get_object();
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
