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

<div class="well clearfix">
  <?php if (!empty($featured_spaces)): ?>
  <div class="spaces-container featured-spaces">
    <h5><?php print $featured_spaces_title; ?></h5>
    <div class="spaces">
      <?php foreach ($featured_spaces as $id => $space): ?>
      <div class="spaces">
        <a class="title" href="<?php print $space['href']; ?>"><?php print $space['title']; ?></a>
      </div>
      <?php endforeach ?>
    </div>
  </div>
  <?php endif ?>

  <div class="btn-group group-switcher" data-toggle="buttons-radio">
    <button class="btn btn-small">Active</button>
    <button class="btn btn-small">All</button>
  </div>

  <div class="accordion groups-container">
    <div class="spaces">
      <?php foreach ($spaces as $id => $space): ?>
      <?php $sections = !empty($space['sections']); ?>
      <div class="space 'space-'<?php print $id; ?> accordion-group">
        <div class="accordion-heading">
          <div class="accordion-toggle">
            <?php if ($sections): ?>
              <a class="icon icon-chevron-down" data-toggle="collapse" href="#accordion-all-body-<?php print $id; ?>"></a>
            <?php endif; ?>
            <a class="title" href="<?php print $space['href']; ?>"><?php print $space['title']; ?></a>
          </div>
        </div>
        <?php if ($sections): ?>
        <div id="accordion-all-body-<?php print $id; ?>" class="sections accordion-body collapse">
          <div class="accordion-inner">
          <?php foreach ($space['sections'] as $id => $section): ?>
            <div class="section section-<?php print $id; ?>">
              <?php print l($section['title'], $section['href']); ?>
            </div>
          <?php endforeach; ?>
          </div>
        </div>
        <?php endif ?>
      </div>
      <?php endforeach; ?>
    </div>
  </div>
</div>
