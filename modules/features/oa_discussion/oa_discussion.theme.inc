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
    'views_view_fields__open_atrium_discussions__replies' => array(
      'template'  => 'views-view-fields--open-atrium-discussions--replies',
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
        'oa_groups_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => drupal_get_path('module', 'oa_discussion') . '/templates',
    ),
    'views_view_fields__open_atrium_discussions__original_post' => array(
      'template'  => 'views-view-fields--open-atrium-discussions--original-post',
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
        'oa_groups_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => drupal_get_path('module', 'oa_discussion') . '/templates',
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

