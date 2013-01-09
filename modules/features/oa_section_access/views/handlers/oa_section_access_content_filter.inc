<?php
/**
 * Basic filter for OpenAtrium section access
 */
class oa_section_access_content_filter extends views_handler_filter {
  var $no_operator = TRUE;

  function query() {
    $this->ensure_my_table();
    $join = new views_join();
    $join->construct('oa_section_access', $this->table_alias, 'oa_section_ref_target_id', 'sid');
    $this->query->ensure_table('oa_section_access', $this->relationship, $join);
    $field = 'oa_section_access.uid ';
    $or = db_or();
    $or->condition($field, '***CURRENT_USER***', '=');
    $or->condition($field, 0, '=');
    $this->query->add_where($this->options['group'], $or);
  }

}
