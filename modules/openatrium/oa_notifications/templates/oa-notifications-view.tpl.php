<div class="well well-large">
    <div class="">
      <h5><?php print t('Organizations'); ?></h5>
      <?php foreach ($organization as $o): ?>
        <span class="label label-info"><?php print $o; ?></span>
      <?php endforeach; ?>
    </div>
    <div class="">
      <h5><?php print t('Teams'); ?></h5>
      <?php foreach ($team as $t): ?>
        <span class="label label-info"><?php print $t; ?></span>
      <?php endforeach; ?>
    </div>
    <div class="">
      <h5><?php print t('Users'); ?></h5>
      <?php foreach ($user as $u): ?>
        <span class="label label-info"><?php print $u; ?></span>
      <?php endforeach; ?>
    </div>
</div>
