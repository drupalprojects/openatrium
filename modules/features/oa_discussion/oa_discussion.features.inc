<?php
/**
 * @file
 * oa_discussion.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_discussion_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_discussion_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function oa_discussion_default_message_type() {
  $items = array();
  $items['oa_reply'] = entity_import('message_type', '{
    "name" : "oa_reply",
    "description" : "Open Atrium Reply",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[message:field-oa-message-group] : [message:user:name] replied to [message:field-oa-node-ref:oa-parent:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-oa-message-group] : [message:user:name] replied to [message:field-oa-node-ref:oa-parent:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E[message:field-oa-message-text:value]\\u0026nbsp;[message:field-oa-node-ref:body]\\u003C\\/p\\u003E",
          "format" : "panopoly_wysiwyg_text",
          "safe_value" : "\\u003Cp\\u003E[message:field-oa-message-text:value]\\u00a0[message:field-oa-node-ref:body]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:timestamp:panopoly_time] \\u003Ca href=\\u0022\\/user\\/[message:user:uid]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E replied to \\u003Ca href=\\u0022\\/node\\/[message:field-oa-node-ref:nid]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:oa-parent:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E [message:timestamp:panopoly_time] \\u003Ca href=\\u0022\\/user\\/[message:user:uid]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E replied to \\u003Ca href=\\u0022\\/node\\/[message:field-oa-node-ref:nid]\\u0022\\u003E\\u003Cstrong\\u003E[message:field-oa-node-ref:oa-parent:title]\\u003C\\/strong\\u003E\\u003C\\/a\\u003E \\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-oa-message-text:value] [message:field-oa-node-ref:title]",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E [message:field-oa-message-text:value] [message:field-oa-node-ref:title] \\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-oa-node-ref:body]",
          "format" : "panopoly_html_text",
          "safe_value" : "\\u003Cp\\u003E [message:field-oa-node-ref:body] \\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function oa_discussion_node_info() {
  $items = array(
    'oa_discussion_post' => array(
      'name' => t('Discussion Post'),
      'base' => 'node_content',
      'description' => t('An Open Atrium discussion post'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
