<?php

/**
 * @file
 * Provides a panels pane that shows user information.
 */

$plugin = array(
  'title' => t('OpenAtrium Favorites'),
  'description' => t('A single button that contains a dropdown menu exposing a user\'s favorite spaces.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_favorites_favorites_button_edit_form',
  'render callback' => 'oa_favorites_favorites_button_render',
);

/**
 * Render callback for the panel.
 */
function oa_favorites_favorites_button_render($subtype, $conf, $args, $context = NULL) {
  $block = new stdClass();
  $block->title = '';

  global $user;
  if ($user->uid) {
    $items = oa_favorites_get_spaces($user);
    if (!empty($items['links'])) {
      $vars['spaces_favorite'] = theme('item_list', array(
        'items' => $items['links'],
        'title' => t('Favorite Spaces'),
        'type' => 'ul',
      ));
      $block->content = theme('oa_favorites_favorites_button', $vars);
    }
  }
  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_favorites_favorites_button_edit_form($form, &$form_state) {
  return $form;
}