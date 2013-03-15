<?php

$plugin = array(
  'title' => t('Group summary'),
  'description' => t('Provides a summary of a group, including the picture, description, and useful links.'),
  'single' => TRUE,
  'category' => array(t('Open Atrium'), -9),
  'edit form' => 'oa_groups_summary_edit_form',
  'render callback' => 'oa_groups_summary_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'image_size' => 'quarter',
  ),
);


/**
 * Render callback for the content visibility panel.
 */
function oa_groups_summary_render($subtype, $conf, $args, $context = NULL) {
  if (!isset($context->data)) {
    return;
  }
  
  global $user;
  $group = $context->data;
  $vars = array();
  
  $vars['title'] = $group->title;
  
  $body = array_shift(field_get_items('node', $group, 'body'));
  $vars['description'] = $body['value'];
  
  $vars['picture'] = '';
  $picture = array_shift(field_get_items('node', $group, 'field_featured_image'));
  if ($picture) {
    $vars['picture'] = theme('image_style', array(
      'style_name' => 'panopoly_image_' . $conf['image_size'],
      'path' => $picture['uri'],
      'width' => $picture['width'],
      'height' => $picture['height'],
      'alt' => $picture['alt'],
      'attributes' => array(
        'class' => array(
          'img-polaroid',
        ),
      ),
    ));
  }
  
  $vars['links'] = array();
  if ($user->uid && module_exists('oa_favorites')) {
    $favorite = oa_favorites_is_favorite_group($user->uid, $group->nid);
    $vars['links']['favorite'] = theme('flag', array(
      'flag' => flag_get_flag(FAVORITE_GROUP),
      'action' => $favorite ? 'unflag' : 'flag',
      'content_id' => $group->nid,
    ));
  }
  if (node_access('update', $group)) {
    $vars['links']['edit'] = l(t('Edit'), 'node/' . $group->nid . '/edit');
  }
  
  $block = new stdClass();
  $block->title = $group->title;
  $block->content = theme('oa_groups_summary', $vars);
  
  return $block;
}


/**
 * Edit form for the panel.
 */
function oa_groups_summary_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['image_size'] = array(
    '#type' => 'radios',
    '#title' => t('Image size'),
    '#options' => array(
      'quarter' => t('Quarter'),
      'half' => t('Half'),
      'full' => t('Full'),
    ),
    '#default' => $conf['image_size'],
  );

  return $form;
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_groups_summary_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

