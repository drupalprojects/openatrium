<ul id="oa_breadcrumb" class="oa_toolbar">
  <?php if (!empty($space_label)): ?>
    <li class="btn-group">
      <a href="<?php print $home_url; ?>"><i class="icon-home"></i></a>
    </li>
    <?php if (!empty($parent_label)): ?>
      <?php if (empty($parent_list)): ?>
      <li class="btn-group">
        <a href="<?php print $parent_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $parent_label; ?></a>
      </li>
      <?php else: ?>
      <li class="dropdown btn-group <?php if (!empty($parent_list)) { print 'dropdown';}?>">
        <a href="<?php print $parent_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $parent_label; ?></a>
        <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="section-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
        <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
          <li class="dropdown-column"><?php print $parent_list; ?></li>
        </ul>
      </li>
      <?php endif; ?>
    <?php endif; ?>
    <li class="btn-group">
      <a href="<?php print $space_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $space_label; ?></a>
    </li>
    <?php if (!empty($section_label)): ?>
    <li class="dropdown btn-group">
      <a href="<?php print $section_url; ?>" class="btn <?php print $oa_toolbar_btn_class; ?>"><?php print $section_label; ?></a>
      <a class="dropdown-toggle btn <?php print $oa_toolbar_btn_class; ?>" id="section-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
      <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
        <li class="dropdown-column"><?php print $sections_list; ?></li>
      </ul>
    </li>
    <?php endif; ?>
  <?php endif; ?>
</ul>
