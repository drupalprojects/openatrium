api = "2"
core = "7.x"

projects[drupal][type] = "core"
projects[drupal][version] = "7.14"
projects[drupal][patch][] = "http://drupalcode.org/project/openatrium.git/blob_plain/refs/heads/master:/patches/robots_txt_rollback.patch"

;core patches to allow simpletest to look into profiles for modules

// allow simpletest to look into profiles for modules
projects[drupal][patch][] = "http://drupal.org/files/issues/911354.46.patch"
projects[drupal][patch][] = "http://drupal.org/files/issues/object_conversion_menu_router_build-972536-1.patch"
projects[drupal][patch][] = "http://drupal.org/files/issues/992540-3-reset_flood_limit_on_password_reset-drush.patch"
