<div class="notifications">
  <?php if (empty($organization) && empty($organization) && empty($organization)): ?>
    <div><?php print t('There are no notifications configured for this content'); ?></div>
  <?php endif; ?>
  <?php if (!empty($organization)): ?>
    <div class="notification-group">
      <h5><?php print t('Organizations'); ?></h5>
      <?php foreach ($organization as $o): ?>
        <span class="label label-info"><?php print $o; ?></span>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($team)): ?>
    <div class="notification-group">
      <h5><?php print t('Teams'); ?></h5>
      <?php foreach ($team as $t): ?>
        <span class="label label-info"><?php print $t; ?></span>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($user)): ?>
    <div class="notification-group">
      <h5><?php print t('Users'); ?></h5>
      <?php foreach ($user as $u): ?>
        <?php if ($u['access']): ?>
          <span class="label label-info">
        <?php else: ?>
          <span class="label label-important" data-toggle="tooltip" title="<?php print t('No current access'); ?>">
        <?php endif; ?><?php print $u['name']; ?></span>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
</div>
