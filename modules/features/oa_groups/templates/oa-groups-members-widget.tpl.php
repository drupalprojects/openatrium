<?php
/**
 * @file
 * Template that provides the view for the group members widget.
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

<div class='clearfix well well-small owners'>
  <h5>Group owners</h3>
  <?php foreach ($owners as $owner): ?>
    <div class='pull-left user-badge'>
      <?php print $owner['picture']; ?>
      <?php print $owner['title']; ?>
    </div>
  <?php endforeach; ?>
</div>

<div class='clearfix well well-small teams'>
  <h5>Teams</h3>
  <?php foreach ($teams as $team): ?>
    <div class='pull-left team'>
      <?php print $team['title']; ?>
    </div>
  <?php endforeach; ?>
</div>

<div class='clearfix well well-small members'>
  <h5>Members</h3>
  <?php foreach ($members as $member): ?>
    <div class='pull-left user-badge'>
      <?php print $member['picture']; ?>
      <?php print $member['title']; ?>
    </div>
  <?php endforeach; ?>
  <div class="clearfix more">
    <a href="#">See all members</a>
  </div>
</div>