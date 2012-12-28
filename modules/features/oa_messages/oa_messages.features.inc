<?php
/**
 * @file
 * oa_messages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_messages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function oa_messages_default_message_type() {
  $items = array();
  $items['oa_create'] = entity_import('message_type', '{
    "name" : "oa_create",
    "description" : "Open Atrium Create Content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EA piece of content has been created on the site.\\u003C\\/p\\u003E",
          "format" : "panopoly_wysiwyg_text",
          "safe_value" : "\\u003Cp\\u003EA piece of content has been created on the site.\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['oa_delete'] = entity_import('message_type', '{
    "name" : "oa_delete",
    "description" : "Open Atrium Delete Content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EContent has been deleted.\\u003C\\/p\\u003E",
          "format" : "panopoly_wysiwyg_text",
          "safe_value" : "\\u003Cp\\u003EContent has been deleted.\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['oa_update'] = entity_import('message_type', '{
    "name" : "oa_update",
    "description" : "Open Atrium Update Content",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003EContent has been UPDATED.\\u003C\\/p\\u003E",
          "format" : "panopoly_wysiwyg_text",
          "safe_value" : "\\u003Cp\\u003EContent has been UPDATED.\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}
