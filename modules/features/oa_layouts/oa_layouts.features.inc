<?php
/**
 * @file
 * oa_layouts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_layouts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}
