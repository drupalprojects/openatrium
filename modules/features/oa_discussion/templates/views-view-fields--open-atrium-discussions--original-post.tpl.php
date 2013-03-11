<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
drupal_add_js(drupal_get_path('module', 'oa_discussion') . '/js/mark-as-read.js');
?>
<div class='oa-list well clearfix <?php print $current_class; ?> <?php print $status_class; ?>'>
  <div class='pull-right user-badge'>
    <?php print $name; ?>
    <?php print $field_user_picture; ?>
  </div>
  <div class='oa-list-header'>
    <?php print $created; ?>
    <div class='pull-right'>
      <?php if (!empty($unpublished)): ?>
        <span class="status"><?php print $unpublished; ?></span>
      <?php endif; ?>
    </div>
    <div class='oa-body'>
      <?php print $title; ?>
      <?php print $body; ?>
      <?php print $field_oa_media; ?>
      <div class="links">
        <a href='#'>reply</a>
        <?php print $edit_node; ?>
        <?php print $remove_link; ?>
      </div>
    </div>
  </div>
</div>
