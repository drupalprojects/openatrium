api = 2
core = 7.x

; ************************************************
; ************* Open Atrium Plugins RELEASE ******

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.12

projects[oa_discussion][subdir] = contrib
projects[oa_discussion][version] = 2.11

projects[oa_wiki][subdir] = contrib
projects[oa_wiki][version] = 2.11

projects[oa_events][subdir] = contrib
projects[oa_events][version] = 2.12

projects[oa_events_import][subdir] = contrib
projects[oa_events_import][version] = 2.10

projects[oa_worktracker][subdir] = contrib
projects[oa_worktracker][version] = 2.0-beta6

projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][version] = 2.0

projects[oa_notifications][subdir] = contrib
projects[oa_notifications][version] = 2.0

projects[oa_media][subdir] = contrib
projects[oa_media][version] = 2.10

projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][version] = 2.10

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.11

; ********** End Open Atrium's Plugins ***********
; ************************************************

; ************************************************
; ************* Open Atrium Modules **************
; (Modules in distro, not yet their own separate projects)

; ##### oa_markdown #####
; Markdown
projects[markdown][subdir] = contrib
projects[markdown][version] = 1.1

; ##### oa_analytics #####
; Google Analytics
projects[google_analytics][subdir] = contrib
projects[google_analytics][version] = 1.3

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][version] = 1.0-rc5
; but, Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][download][revision] = 4f4996
projects[panopoly_core][download][type] = git

projects[panopoly_images][version] = 1.0-rc5
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.0-rc5
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][branch] = 7.x-1.x
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][revision] = 7dc1a5
projects[panopoly_magic][patch][2016527] = http://drupal.org/files/2016643_panopoly_magic_screw_pre_render_with_2016527-5.patch
projects[panopoly_magic][patch][2017159] = http://drupal.org/files/2017159_panopoly_magic_preview_post_render-22.patch

projects[panopoly_widgets][version] = 1.0-rc5
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][branch] = 7.x-1.x
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][revision] = 39caff

projects[panopoly_users][version] = 1.0-rc5
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][download][revision] = 97638f
projects[panopoly_pages][download][type] = git

projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x
projects[panopoly_wysiwyg][download][revision] = 0aaf3b
projects[panopoly_wysiwyg][download][type] = git

projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][branch] = 7.x-1.x
projects[panopoly_search][download][revision] = 5bf251
projects[panopoly_search][download][type] = git

; ***************** End Panopoly *****************
; ************************************************
