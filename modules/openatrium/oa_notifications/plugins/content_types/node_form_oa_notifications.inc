<?php

/**
 * @file
 * Notifications form for the node.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Node form Open Atrium Notification'),
  //'icon' => 'icon_node_form.png',
  'description' => t('Notification configuration on the Node form.'),
  'render callback' => 'oa_notifications_node_form_notifications_render',
  'required context' => new ctools_context_required(t('Form'), 'node_form'),
  'category' => t('Form'),
);

function oa_notifications_node_form_notifications_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();

  $block->title = t('Notifications');
  $block->module = t('oa_notifications');
  $block->delta = 'oa-notifications';

  if (isset($context->form)) {
    if (isset($context->form['oa_notifications'])) {
      $block->content['oa_notifications'] = $context->form['oa_notifications'];
      unset($block->content['oa_notifications']['#pre_render']);
      unset($block->content['oa_notifications']['#theme_wrappers']);
      $block->content['oa_notifications']['#type'] = '';

      // Set access to false on the original rather than removing so that
      // vertical tabs doesn't clone it. I think this is due to references.
      $context->form['oa_notifications']['#access'] = FALSE;
    }
  }
  else {
    $block->content = t('Notifications');
  }
  return $block;
}
