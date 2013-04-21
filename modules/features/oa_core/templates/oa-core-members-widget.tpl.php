<?php
/**
 * @file
 * Template that provides the view for the space members widget.
 *
 * $owners - Array of owners.
 *   'title'    - Link to the owner user.
 *   'picture'  - Rendered image of the user.
 * $teams - Array of teams.
 *   'title'    - Link to the team node.
 * $users - Array of users.
 *   'title'    - Link to the owner user.
 *   'picture'  - Rendered image of the user.
 */
?>

<?php if (!empty($owners)): ?>
<div class='clearfix well well-small owners'>
  <h5>Space owners</h5>
  <?php foreach ($owners as $owner): ?>
    <div class='pull-left user-badge'>
      <?php print $owner['picture']; ?>
      <?php print $owner['title']; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>

<?php if (!empty($teams)): ?>
<div class='clearfix well well-small teams'>
  <h5>Teams</h5>
  <?php foreach ($teams as $team): ?>
    <div class='pull-left team'>
      <?php print $team['title']; ?>
    </div>
  <?php endforeach; ?>
</div>
<?php endif; ?>

<?php if (!empty($members)): ?>
<div class='clearfix members'>
  <?php foreach ($members as $member): ?>
    <div class='oa-member-list user-badge no-border pull-left'>
      <?php print $member['picture']; ?>
      <?php print $member['title']; ?>
    </div>
  <?php endforeach; ?>
  <div class="clear-both more">
    <?php print $see_all_link; ?>
  </div>
</div>
<?php endif; ?>
