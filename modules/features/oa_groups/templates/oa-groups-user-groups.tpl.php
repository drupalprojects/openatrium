<?php
/**
 * @file
 * Provides view for the user groups panel.
 *
 * $groups - Array of groups, keyed by ID.
 *    'title' - Title of group
 *    'href' - Url to the group.
 *    'sections' - Array of sections, keyed by section ID.
 *      'title' - Title of the section.
 *      'href' - Url to the section.
 * $featured_groups - Array of groups, same as above sans sections.
 * $featured_groups_title - Title of the featured groups.
 */
?>

<div class="well clearfix">
  <?php if (!empty($featured_groups)): ?>
  <div class="groups-container featured-groups">
    <h5><?php print $featured_groups_title; ?></h5>
    <div class="groups">
      <?php foreach ($featured_groups as $id => $group): ?>
      <div class="group">
        <a class="title" href="<?php print $group['href']; ?>"><?php print $group['title']; ?></a>
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
    <div class="groups">
      <?php foreach ($groups as $id => $group): ?>
      <?php $sections = !empty($group['sections']); ?>
      <div class="group 'group-'<?php print $id; ?> accordion-group">
        <div class="accordion-heading">
          <div class="accordion-toggle">
            <?php if ($sections): ?>
              <a class="icon icon-chevron-down" data-toggle="collapse" href="#accordion-all-body-<?php print $id; ?>"></a>
            <?php endif; ?>
            <a class="title" href="<?php print $group['href']; ?>"><?php print $group['title']; ?></a>
          </div>
        </div>
        <?php if ($sections): ?>
        <div id="accordion-all-body-<?php print $id; ?>" class="sections accordion-body collapse">
          <div class="accordion-inner">
          <?php foreach ($group['sections'] as $id => $section): ?>
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