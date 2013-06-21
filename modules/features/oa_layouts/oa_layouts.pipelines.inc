<?php

/**
 * Implements hook_default_panels_renderer_pipeline().
 */
function oa_layouts_default_panels_renderer_pipeline() {
  $pipelines = array();

  $pipeline = new stdClass;
  $pipeline->disabled = FALSE; /* Edit this to true to make a default pipeline disabled initially */
  $pipeline->api_version = 1;
  $pipeline->name = 'ipe_node_access';
  $pipeline->admin_title = t('In-Place Editor (node access)');
  $pipeline->admin_description = t('Allows users who can edit current node to update and rearrange the content while viewing this panel.');
  $pipeline->weight = 0;
  $pipeline->settings = array(
    'renderers' => array(
      0 => array(
        'access' => array(
          'plugins' => array(
            0 => array(
              'name' => 'node_access_current_node',
              'settings' => array(
                'op' => 'update',
              ),
            ),
          ),
          'logic' => 'and',
        ),
        'renderer' => 'ipe',
        'options' => array(),
      ),
    ),
  );
  $pipelines[$pipeline->name] = $pipeline;

  return $pipelines;
}
