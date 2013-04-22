<?php
/**
 * @file
 * Provides view for the user spaces panel.
 *
 * $spaces - Array of spaces, keyed by ID.
 *    'title' - Title of space
 *    'href' - Url to the space.
 *    'sections' - Array of sections, keyed by section ID.
 *      'title' - Title of the section.
 *      'href' - Url to the section.
 * $featured_spaces - Array of spaces, same as above sans sections.
 * $featured_spaces_title - Title of the featured spaces.
 */
?>

<div class="oa-spaces tabbable clearfix">
  <?php if (count($space_groups) > 1): ?>
    <ul class="nav nav-tabs">
      <?php $active_class = 'active'; ?>
      <?php foreach ($space_groups as $category => $spaces): ?>
        <li class='<?php print $active_class;?>'><a href="#<?php print 'tab-'.$category?>" data-toggle="tab">
          <?php print $category; ?>
          <?php $active_class = ''; ?>
        </a></li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>
  <div class="tab-content">
    <?php $active_class = 'active'; ?>
    <?php foreach ($space_groups as $category => $spaces): ?>
      <div class="tab-pane oa-list <?php print $active_class;?>" id="<?php print 'tab-'.$category; ?>">
        <?php $active_class = ''; ?>
        <?php foreach ($spaces as $id => $space): ?>
          <?php $sections = !empty($space['sections']); ?>
          <div class="space clearfix space-<?php print $id; ?>">
            <a class="title" href="<?php print $space['href']; ?>">
              <<?php print $title_tag; ?>>
                <?php print $space['title']; ?>
              </<?php print $title_tag; ?>>
            </a>
            <?php if (!empty($space['picture'])): ?>
              <div class='pull-left'>
                <?php print $space['picture']; ?>
              </div>
            <?php endif; ?>
            <?php if (!empty($space['body'])): ?>
              <p><?php print $space['body']; ?></p>
            <?php endif; ?>
            <?php if ($sections): ?>
              <div class='oa-sections'>
                <?php print t('Sections: '); ?>
                <?php print implode(', ', $space['sections']); ?>
              </div>
            <?php endif ?>
            <?php if (!empty($space['links'])): ?>
              <?php print render($space['links']); ?>
            <?php endif; ?>
          </div>
        <?php endforeach; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
