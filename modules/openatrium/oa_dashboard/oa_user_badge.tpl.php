<?php
/**
 * @file
 * Provides view for nav bar user badge.
 *
 * $picture - Markup of the user's profile picture.
 * $realname - Real name field. Defaults to unique name if unavailable.
 * $name - Unique user name.
 * $links - Array of useful links.
 *    'dashboard' - Link to the user's page.
 *    'edit_profile' - Link to edit user's profile.
 *    'logout' - Logout link.
 */
?>
<div id="oa-user-badge" class="pull-right">
  <div class="dropdown oa-dropdown btn-group">
    <div class="user-badge dropdown-toggle btn clearfix" id="user-badge-dropdown" data-toggle="dropdown">
      <div class="pull-left user-name">
        <?php print $realname; ?>
      </div>
      <div class="pull-right user-picture">
        <?php print $picture; ?>
      </div>
    </div>
    <div class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
      <ul>
        <li><?php print l(t('Dashboard'), $links['dashboard']); ?></li>
        <li><?php print l(t('Edit profile'), $links['edit_profile']); ?></li>
        <li><?php print l(t('Log out'), $links['logout']); ?></li>
      </ul>
    </div>
  </div>
</div>