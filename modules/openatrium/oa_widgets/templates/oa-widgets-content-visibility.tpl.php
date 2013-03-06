<?php

/**
 * @file
 * Provides the view for the content visibility widget.
 *
 * - $public: boolean, whether or not content is public.
 * - $accessors: array of arrays that represent things that have access to the
 *   content
 *   - ['label']: string label of the accessor
 *   - ['links']: array of link strings
 */
?>

<?php if ($public): ?>
  <p class="visibility public">Public</p>
<?php else: ?>
  <p class="visibility private">Private</p>
  <?php foreach ($accessors as $class => $accessor): ?>
    <p class="<?php print $class ?>">
      <?php print $accessor['label']; ?>
      <?php print implode(', ', $accessor['links']); ?>
    </p>
  <?php endforeach ?>
<?php endif ?>