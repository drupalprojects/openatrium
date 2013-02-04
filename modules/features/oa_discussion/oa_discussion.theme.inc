<?php
/**
 * @file
 * Code for Theme functions of the OpenAtrium Discussion feature.
 */

/**
 * Implements hook_theme()
 */
function oa_discussion_theme() {
  return array(
    'oa_discussion_reply' => array(
      'variables' => array('parent_id' => NULL),
    ),
  );
}

function theme_oa_discussion_reply($vars) {
  $output = l('Reply', 'node/add/oa-discussion-post/' . $vars['parent_id'],
    array('attributes' => array(
      'class' => array('btn', 'btn-success'),
    )
  ));
  return $output;
}

