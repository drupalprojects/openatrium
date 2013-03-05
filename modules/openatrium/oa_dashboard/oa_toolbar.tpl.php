<div id="oa_toolbar">
  <?php if (!empty($groups_label)): ?>
  <div class="dropdown oa-dropdown">
    <a href="<?php print $home_url; ?>"><i class="icon-home"></i></a>
  </div>
  <div class="oa-toolbar-separator"><?php print $oa_toolbar_separator; ?></div>
    <div class="dropdown btn-group">
      <?php print $groups_label; ?>
      <a class="dropdown-toggle btn btn-large btn-success" id="group-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="group-dropdown">
        <li class="dropdown-column"><?php print $groups_favorite; ?></li>
        <li class="dropdown-column"><?php print $groups_recent; ?></li>
      </ul>
    </div>
  <div class="oa-toolbar-separator"><?php print $oa_toolbar_separator; ?></div>
  <div class="dropdown oa-dropdown btn-group">
    <a class="dropdown-toggle btn btn-large btn-success" id="section-dropdown" data-toggle="dropdown" href="#"><?php print $sections_label; ?>&nbsp;<b class="caret"></b></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
      <li class="dropdown-column"><?php print $sections_list; ?></li>
    </ul>
  </div>
  <?php endif; ?>
</div>
