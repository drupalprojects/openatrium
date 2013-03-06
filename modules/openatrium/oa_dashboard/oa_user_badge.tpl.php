<div id="oa-user-badge" class="pull-right">
  <div class="dropdown oa-dropdown btn-group">
    <div class="user-badge dropdown-toggle btn clearfix" id="user-badge-dropdown" data-toggle="dropdown">
      <div class="pull-left user-name">
        <?php print $name; ?>
      </div>
      <div class="pull-right user-picture">
        <?php print $picture; ?>
      </div>
    </div>
    <div class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
      <ul>
        <?php foreach ($links as $link): ?>
          <li><?php print $link; ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  </div>
</div>