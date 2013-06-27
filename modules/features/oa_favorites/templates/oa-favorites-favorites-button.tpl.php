<?php
/**
 * @file
 * Provides view for favorites button.
 *
 * $spaces_favorite - Rendered list for space favorites.
 */
?>
<ul id="oa_favorites">
  <li class="dropdown btn-group">
    <a class="dropdown-toggle btn" id="favorites-dropdown" data-toggle="dropdown" href="#"><b class="caret"></b></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="space-dropdown">
      <li class="dropdown-column"><?php print $spaces_favorite; ?></li>
    </ul>
  </li>
</ul>
