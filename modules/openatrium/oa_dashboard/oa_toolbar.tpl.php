<div id="oa_toolbar">
  <span class="dropdown">
    <a class="dropdown-toggle" data-toggle="dropdown" href="#"><i class="icon-home"></i></a>
  </span>
  <span class="oa_toolbar_separator"><?php print $oa_toolbar_separator; ?></span>
  <span class="dropdown">
    <a class="dropdown-toggle btn btn-large btn-info" id="group-dropdown" data-toggle="dropdown" href="#"><?php print $groups_label; ?>&nbsp;<b class="caret"></b></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="group-dropdown">
      <li><?php print $groups_recent; ?></li>
    </ul>
  </span>
  <span class="oa_toolbar_separator"><?php print $oa_toolbar_separator; ?></span>
  <span class="dropdown">
    <a class="dropdown-toggle btn btn-large btn-info" id="section-dropdown" data-toggle="dropdown" href="#"><?php print $sections_label; ?>&nbsp;<b class="caret"></b></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="section-dropdown">
      <li><ul><li><?php print $sections_main; ?></li></ul></li>
      <li><?php print $sections_list; ?></li>
    </ul>
  </span>
</div>
