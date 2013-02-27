<div class="notifications">
  <?php if (empty($organization) && empty($organization) && empty($organization)): ?>
    <div><?php print t('There are no notifications configured for this content'); ?></div>
  <?php endif; ?>
  <?php if (!empty($organization)): ?>
    <div class="notification-group">
      <h5><?php print t('Organizations'); ?></h5>
      <?php foreach ($organization as $id => $o): ?>
        <?php print l($o, 'node/' . $id, array('attributes' => array('class' => array('label', 'label-info')))); ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($team)): ?>
    <div class="notification-group">
      <h5><?php print t('Teams'); ?></h5>
      <?php foreach ($team as $id => $t): ?>
        <?php print l($t, 'node/' . $id, array('attributes' => array('class' => array('label', 'label-info')))); ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($user)): ?>
    <div class="notification-group">
      <h5><?php print t('Users'); ?></h5>
      <?php foreach ($user as $u):
        $attributes = array('class' => array('label'));
        if ($u['access']) {
           $attributes['class'][] = 'label-info';
        }
        else {
          $attributes['class'][] = 'label-important';
          $attributes['data-toggle'] = 'tooltip';
          $attributes['title'] = t('Access has been revoked');
        }
        ?>
        <?php print l($u['name'], 'user/' . $u['uid'], array('attributes' => $attributes)); ?>
      <?php endforeach; ?>
    </div>
  <?php endif; ?>
</div>
