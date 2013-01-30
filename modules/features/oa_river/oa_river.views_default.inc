<?php
/**
 * @file
 * oa_river.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oa_river_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'open_atrium_recent_activity';
  $view->description = 'Displays recent activity for users and groups';
  $view->tag = 'OA';
  $view->base_table = 'node';
  $view->human_name = 'Open Atrium Recent Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_oa_node_ref_message']['id'] = 'reverse_field_oa_node_ref_message';
  $handler->display->display_options['relationships']['reverse_field_oa_node_ref_message']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_oa_node_ref_message']['field'] = 'reverse_field_oa_node_ref_message';
  $handler->display->display_options['relationships']['reverse_field_oa_node_ref_message']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['relationship'] = 'reverse_field_node_ref_message';
  $handler->display->display_options['fields']['message_render']['label'] = '';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['partials'] = 0;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Field: Field: Groups audience */
  $handler->display->display_options['fields']['og_group_ref_2']['id'] = 'og_group_ref_2';
  $handler->display->display_options['fields']['og_group_ref_2']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref_2']['field'] = 'og_group_ref';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Message: Group ID */
  $handler->display->display_options['fields']['field_oa_group_id']['id'] = 'field_oa_group_id';
  $handler->display->display_options['fields']['field_oa_group_id']['table'] = 'field_data_field_oa_group_id';
  $handler->display->display_options['fields']['field_oa_group_id']['field'] = 'field_oa_group_id';
  $handler->display->display_options['fields']['field_oa_group_id']['relationship'] = 'reverse_field_oa_node_ref_message';
  $handler->display->display_options['fields']['field_oa_group_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['relationship'] = 'reverse_field_oa_node_ref_message';
  /* Sort criterion: Message: Message ID */
  $handler->display->display_options['sorts']['mid']['id'] = 'mid';
  $handler->display->display_options['sorts']['mid']['table'] = 'message';
  $handler->display->display_options['sorts']['mid']['field'] = 'mid';
  $handler->display->display_options['sorts']['mid']['relationship'] = 'reverse_field_oa_node_ref_message';
  $handler->display->display_options['sorts']['mid']['order'] = 'DESC';
  /* Contextual filter: Message: Group ID (field_oa_group_id) */
  $handler->display->display_options['arguments']['field_oa_group_id_value']['id'] = 'field_oa_group_id_value';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['table'] = 'field_data_field_oa_group_id';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['field'] = 'field_oa_group_id_value';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['relationship'] = 'reverse_field_oa_node_ref_message';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_oa_group_id_value']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Groups */
  $handler = $view->new_display('panel_pane', 'Groups', 'group_river');
  $handler->display->display_options['display_description'] = 'Recent Activity for Groups';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'OA';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['open_atrium_recent_activity'] = $view;

  return $export;
}
