<div id="oa_toolbar">
  <?php if (!empty($group_label)): ?>
  <div class="dropdown oa-dropdown">
    <a href="<?php print $home_url; ?>"><i class="icon-home"></i></a>
  </div>
  <div class="dropdown btn-group">
    <?php print $group_link; ?>
    <a class="dropdown-toggle btn btn-large" id="group-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="group-dropdown">
      <li class="dropdown-column"><?php print $groups_favorite; ?></li>
      <li class="dropdown-column"><?php print $groups_recent; ?></li>
    </ul>
  </div>
  <?php if (!empty($section_label)): ?>
  <div class="dropdown btn-group">
    <?php print $section_link; ?>
    <a class="dropdown-toggle btn btn-large" id="section-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
      <li class="dropdown-column"><?php print $sections_list; ?></li>
    </ul>
  </div>
  <?php endif; ?>
  <?php endif; ?>
</div>
