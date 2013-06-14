<?php

/**
 * @file
 * Code for the OpenAtrium Core views alterations.
 */


/**
 * Implements hook_views_data_alter
 */
function oa_core_views_data_alter(&$data) {
  if (isset($data['og_membership']['og_group_ref_target_id']['filter']['handler'])) {
    $data['og_membership']['og_group_ref_target_id']['filter']['handler'] = 'oa_core_og_group_ref_views_handler_filter_in_operator';
  }
  if (isset($data['field_data_oa_section_ref']['oa_section_ref_target_id']['filter']['handler'])) {
    $data['field_data_oa_section_ref']['oa_section_ref_target_id']['filter']['handler'] = 'oa_core_oa_section_ref_views_handler_filter_in_operator';
  }
}