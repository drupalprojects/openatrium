<?php
/**
 * @file
 * Provides the view for the groups summary panel.
 *
 * $title - Title of the group
 * $description - Group description
 * $picture - Markup for the group's image.
 * $links - Array of links.
 *    'favorite' - Link to mark the group as favorite. Only available if user
 *                 is logged in.
 *    'edit' - Link to edit the group. Only available if user can edit it.
 */
?>

<div class="group-details clearfix">
  <?php if ($picture): ?>
  <div class="picture">
    <?php print $picture; ?>
  </div>
  <?php endif ?>
  <div class="description">
    <?php print $description; ?>
  </div>
</div>
<?php if (!empty($links)): ?>
<div class="group-links clearfix">
  <?php foreach($links as $class => $link): ?>
    <div class="<?php print $class; ?>">
      <?php print $link; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif ?>