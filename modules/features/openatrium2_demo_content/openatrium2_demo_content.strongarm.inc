<?php
/**
 * @file
 * openatrium2_demo_content.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function openatrium2_demo_content_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_group_article';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_group_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_group_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_group_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_group_article';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_group_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_group_article';
  $strongarm->value = '1';
  $export['node_preview_group_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_group_article';
  $strongarm->value = 1;
  $export['node_submitted_group_article'] = $strongarm;

  return $export;
}
