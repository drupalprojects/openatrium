<?php

/**
 * @file
 * Code to override field to add in auto option.
 */

class oa_core_og_group_ref_views_handler_filter_in_operator extends views_handler_filter_in_operator {
  function init(&$view, &$options) {
    parent::init($view, $options);
    if (!empty($this->options['expose']['identifier']) && empty($this->options['expose']['oa_core_no_auto'])) {
      $id = $this->options['expose']['identifier'];
      $exposed = $this->view->get_exposed_input();
      if (isset($exposed[$id]) && empty($exposed[$id])) {
        if ($group = oa_core_get_space_context()) {
          $exposed[$id] = $group;
        }
        else {
          unset($exposed[$id]);
        }
        $this->view->set_exposed_input($exposed);
      }
    }
  }
}
