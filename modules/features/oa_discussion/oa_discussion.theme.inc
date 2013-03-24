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
    'views_view_fields__open_atrium_discussions__replies' => array(
      'template'  => 'views-view-fields--open-atrium-discussions--replies',
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
        'oa_core_preprocess_views_view_fields',
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
        'oa_core_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => drupal_get_path('module', 'oa_discussion') . '/templates',
    ),
    'views_view_fields__open_atrium_discussions__attachments' => array(
      'template'  => 'views-view-fields--open-atrium-discussions--attachments',
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
        'oa_core_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => drupal_get_path('module', 'oa_discussion') . '/templates',
    ),
  );
}

