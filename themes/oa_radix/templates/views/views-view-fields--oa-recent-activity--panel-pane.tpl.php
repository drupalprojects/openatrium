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
?>
<div class='oa-river well'>
  <?php if ($display != 'user_activity'): ?>
    <div class='pull-right user-badge'>
      <?php print $name; ?>
      <?php print $field_user_picture; ?>
    </div>
  <?php endif; ?>
  <div class='oa-river-category pull-right'>
    <?php if ($display != 'group_activity'): ?>
      <?php print $og_group_ref; ?><br \>
    <?php endif; ?>
    <?php print $oa_section_ref; ?>
  </div>
  <div class='oa-river-header'>
    <?php print $timestamp; ?>
    <?php print $name; ?>
    <?php print $type; ?>
    <?php print $type_1; ?>:
    <?php print $title; ?>
  </div>
  <div class="accordion" id="oa-river-accordion<?php print $index; ?>">
    <div>
      <div class="accordion-heading">
        <a class="accordion-toggle" data-toggle="collapse" data-parent="#oa-river-accordion<?php print $index; ?>" href="#oa-river-body<?php print $index; ?>">
          <i class="icon-plus" vertical-align="middle"></i>&nbsp;<?php print $body; ?>...
        </a>
      </div>
      <div id="oa-river-body<?php print $index; ?>" class="accordion-body collapse">
        <div class="accordion-inner">
          <?php print $rendered_entity; ?>
        </div>
      </div>
    </div>
  </div>
</div>
