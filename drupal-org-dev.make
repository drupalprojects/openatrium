api = 2
core = 7.x

; ************************************************
; ************* Open Atrium Plugins DEV **********

projects[oa_core][download][type] = git
projects[oa_core][subdir] = contrib
projects[oa_core][download][url] = http://git.drupal.org/project/oa_core.git
projects[oa_core][download][branch] = 7.x-2.x

projects[oa_discussion][download][type] = git
projects[oa_discussion][subdir] = contrib
projects[oa_discussion][download][url] = http://git.drupal.org/project/oa_discussion.git
projects[oa_discussion][download][branch] = 7.x-2.x

projects[oa_wiki][download][type] = git
projects[oa_wiki][subdir] = contrib
projects[oa_wiki][download][url] = http://git.drupal.org/project/oa_wiki.git
projects[oa_wiki][download][branch] = 7.x-2.x

projects[oa_events][download][type] = git
projects[oa_events][subdir] = contrib
projects[oa_events][download][url] = http://git.drupal.org/project/oa_events.git
projects[oa_events][download][branch] = 7.x-2.x

projects[oa_events_import][download][type] = git
projects[oa_events_import][subdir] = contrib
projects[oa_events_import][download][url] = http://git.drupal.org/project/oa_events_import.git
projects[oa_events_import][download][branch] = 7.x-2.x

projects[oa_worktracker][download][type] = git
projects[oa_worktracker][subdir] = contrib
projects[oa_worktracker][download][url] = http://git.drupal.org/project/oa_worktracker.git
projects[oa_worktracker][download][branch] = 7.x-2.x

projects[oa_contextual_tabs][download][type] = git
projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][download][url] = http://git.drupal.org/project/oa_contextual_tabs.git
projects[oa_contextual_tabs][download][branch] = 7.x-2.x

projects[oa_notifications][download][type] = git
projects[oa_notifications][subdir] = contrib
projects[oa_notifications][download][url] = http://git.drupal.org/project/oa_notifications.git
projects[oa_notifications][download][branch] = 7.x-2.x

projects[oa_media][download][type] = git
projects[oa_media][subdir] = contrib
projects[oa_media][download][url] = http://git.drupal.org/project/oa_media.git
projects[oa_media][download][branch] = 7.x-2.x

projects[oa_subspaces][download][type] = git
projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][download][url] = http://git.drupal.org/project/oa_subspaces.git
projects[oa_subspaces][download][branch] = 7.x-2.x

projects[oa_mailhandler][download][type] = git
projects[oa_mailhandler][subdir] = contrib
projects[oa_mailhandler][download][url] = http://git.drupal.org/project/oa_mailhandler.git
projects[oa_mailhandler][download][branch] = 7.x-2.x

projects[oa_radix][type] = theme
projects[oa_radix][download][type] = git
projects[oa_radix][download][url] = http://git.drupal.org/project/oa_radix.git
projects[oa_radix][download][branch] = 7.x-2.x

; ##### oa_devel #####
; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Coder
projects[coder][type] = module
projects[coder][download][type] = git
projects[coder][download][url] = http://git.drupal.org/project/coder.git
projects[coder][download][branch] = 7.x-2.x
projects[coder][subdir] = contrib

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

; projects[panopoly_core][version] = 1.0
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][download][revision] = 96e012
projects[panopoly_core][download][type] = git

projects[panopoly_images][version] = 1.0
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.0
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.0
projects[panopoly_magic][subdir] = panopoly

; projects[panopoly_widgets][version] = 1.0
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][branch] = 7.x-1.x
projects[panopoly_widgets][download][revision] = 5555e3
projects[panopoly_widgets][download][type] = git

; projects[panopoly_admin][version] = 1.0
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][branch] = 7.x-1.x
projects[panopoly_admin][download][revision] = 36aec4
projects[panopoly_admin][download][type] = git

; projects[panopoly_users][version] = 1.0
projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][branch] = 7.x-1.x
projects[panopoly_users][download][revision] = 2ccc76
projects[panopoly_users][download][type] = git

projects[panopoly_pages][version] = 1.0
projects[panopoly_pages][subdir] = panopoly

; projects[panopoly_wysiwyg][version] = 1.0
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x
projects[panopoly_wysiwyg][download][revision] = a5973c
projects[panopoly_wysiwyg][download][type] = git

; projects[panopoly_search][version] = 1.0
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][branch] = 7.x-1.x
projects[panopoly_search][download][revision] = 5f3562
projects[panopoly_search][download][type] = git

; ***************** End Panopoly *****************
; ************************************************
