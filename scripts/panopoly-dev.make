api = 2
core = 7.x

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush 5 concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.
; NOTE: If you are running Drush 6, this section should be placed at the TOP

projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][patch][2429549] = https://www.drupal.org/files/issues/2429549-panopoly_core-update-latest-panelizer-20.patch
projects[panopoly_core][patch][2477347] = https://www.drupal.org/files/issues/2477347-panopoly_core-views-2.patch
projects[panopoly_core][patch][2477363] = https://www.drupal.org/files/issues/2477363-panopoly_core-ctools-7.patch
projects[panopoly_core][patch][2477369] = https://www.drupal.org/files/issues/2477369-panopoly_core-entity-1.patch
projects[panopoly_core][patch][2477375] = https://www.drupal.org/files/issues/2477375-panopoly_core-entityreference-1.patch
projects[panopoly_core][patch][2477379] = https://www.drupal.org/files/issues/2477379-panopoly_core-token-1.patch
projects[panopoly_core][patch][2477391] = https://www.drupal.org/files/issues/2477391-panopoly_core-features-4.patch
projects[panopoly_core][patch][2235081] = https://www.drupal.org/files/issues/2235081-22-panopoly_core-jquery_update.patch

projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][branch] = 7.x-1.x

projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][branch] = 7.x-1.x

projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][branch] = 7.x-1.x
projects[panopoly_widgets][patch][2473495] = https://www.drupal.org/files/issues/clicking_images_in_my-2473495-4.patch
projects[panopoly_widgets][patch][2477397] = https://www.drupal.org/files/issues/2477397-panopoly_widgets-file_entity-2.patch

projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][branch] = 7.x-1.x

projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][branch] = 7.x-1.x

projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][branch] = 7.x-1.x

projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][branch] = 7.x-1.x
projects[panopoly_search][patch][2469005] = https://www.drupal.org/files/issues/2469005-panopoly_search-search_api-1.patch

; ***************** End Panopoly *****************
; ************************************************
