<?php

/**
 * @file
 * Definition of views_handler_argument_numeric.
 */

/**
 * Basic filter for OpenAtrium section access
 */
class views_handler_argument_oa_parent_id extends views_handler_argument_numeric {
  var $no_operator = TRUE;

  function query() {
    $this->ensure_my_table();
    $this->query->add_where_expression(0, "field_data_oa_parent.oa_parent_target_id = $this->argument OR node.nid = $this->argument");
  }

}
