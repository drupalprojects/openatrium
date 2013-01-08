<?php
/**
 * @file
 * Code for custom Views filters.
 */
/**
 * Implements hook_views_data()
 * Exposes our section access table to views
 */
function oa_section_access_views_data() {
  // Basic table information.
  // Hook into existing entity field table to add a filter
  $data['field_data_oa_section_ref'] = array(
    'table' => array(
      'group' => t('Open Atrium'),
    )
  );

  // Adds our field in the "Filters" section of Views
  $data['field_data_oa_section_ref']['entity_id']['filter'] = array(
    'title' => 'Section Access (Content)',
    'help' => 'Only show content within Sections current user can access.',
    'handler' => 'oa_section_access_content_filter',
  );

  $data['oa_section_access'] = array(
    'table' => array(
      'group' => t('Open Atrium'),
      'join' => array(
        'node' => array(
          'left_field' => 'nid',
          'field' => 'sid',
        ),
      ),
    )
  );

  // Adds our field in the "Filters" section of Views
  $data['oa_section_access']['nid']['filter'] = array(
    'title' => 'Section Access (Section)',
    'help' => 'Only show Sections current user can access.',
    'handler' => 'oa_section_access_section_filter',
  );

  return $data;
}
