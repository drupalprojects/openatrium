<?php

/**
 * @file
 * Contains facetapi integration.
 */


/**
 * Implements hook_facetapi_facet_info().
 */
function oa_search_facetapi_facet_info($searcher_info) {
  $facets = array();
  if (isset($searcher_info['types']['node'])) {
    dpm($searcher_info);
    $facets['space'] = array(
      'label' => t('Open Atrium Space'),
      'description' => t('Filter by the space the node is in.'),
      'field' => 'field_og_group_ref',
      'field alias' => 'space',
      'default widget' => 'links',
      //'map callback' => 'oa_search_node_reference_map_callback',
    );

    $facets['section'] = array(
      'label' => t('Open Atrium Section'),
      'description' => t('Filter by the section the content is in.'),
      'field' => 'field_oa_section_ref',
      'field alias' => 'section',
      'default widget' => 'links',
      //'map callback' => 'oa_search_node_reference_map_callback',
    );
  }
  return $facets;
}

/**
 * Map callback to return human-readable names for node reference field facets.
 */
function oa_search_node_reference_map_callback(array $values, array $options) {
  dpm($values);
  dpm($options);
}