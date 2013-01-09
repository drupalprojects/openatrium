<?php
/**
 * Basic filter for OpenAtrium section access
 */
class oa_section_access_section_filter extends views_handler_filter {
  var $no_operator = TRUE;

  function query() {
    $this->ensure_my_table();
    $field = 'oa_section_access.uid ';
    $or = db_or();
    $or->condition($field, '***CURRENT_USER***', '=');
    $this->query->add_where($this->options['group'], $or);
  }

}
