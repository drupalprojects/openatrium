api = 2
core = 7.x

; ************************************************
; ************* Open Atrium Plugins RELEASE ******

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.21

projects[oa_discussion][subdir] = apps
projects[oa_discussion][version] = 2.20

projects[oa_wiki][subdir] = apps
projects[oa_wiki][version] = 2.20

projects[oa_events][subdir] = apps
projects[oa_events][version] = 2.21

projects[oa_events_import][subdir] = apps
projects[oa_events_import][version] = 2.20

projects[oa_worktracker][subdir] = apps
projects[oa_worktracker][version] = 2.0-beta15
projects[oa_worktracker][patch][2335741] = http://drupal.org/files/issues/2335741-oa_worktracker-app-4.patch

projects[oa_contextual_tabs][subdir] = apps
projects[oa_contextual_tabs][version] = 2.21

projects[oa_notifications][subdir] = apps
projects[oa_notifications][version] = 2.20

projects[oa_media][subdir] = apps
projects[oa_media][version] = 2.20

projects[oa_subspaces][subdir] = apps
projects[oa_subspaces][version] = 2.21

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.21

; ************************************************
; ************* Open Atrium Modules **************
; (Modules in distro, not yet their own separate projects)

; ##### oa_markdown #####
; Markdown
projects[markdown][version] = 1.1
projects[markdown][subdir] = contrib

; ##### oa_analytics #####
; Google Analytics
projects[google_analytics][version] = 1.3
projects[google_analytics][subdir] = contrib

; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][version] = 1.10
; but, Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.10
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][patch][2303783] = http://drupal.org/files/issues/2303783-panopoly_core-apps-14-do-not-test.patch

projects[panopoly_images][version] = 1.10
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.10
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.10
projects[panopoly_magic][subdir] = panopoly

projects[panopoly_widgets][version] = 1.10
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.10
projects[panopoly_admin][subdir] = panopoly

projects[panopoly_users][version] = 1.10
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.10
projects[panopoly_pages][subdir] = panopoly

projects[panopoly_wysiwyg][version] = 1.10
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.10
projects[panopoly_search][subdir] = panopoly

; ***************** End Panopoly *****************
; ************************************************

; ************************************************
; ************* Open Atrium Apps *****************
; (Local apps that included by default)

projects[oa_admin][version] = 2.0-alpha2
projects[oa_admin][subdir] = apps

projects[oa_appearance][version] = 2.0-alpha2
projects[oa_appearance][subdir] = apps

projects[oa_archive][version] = 2.0-alpha2
projects[oa_archive][subdir] = apps

projects[oa_clone][version] = 2.0-alpha2
projects[oa_clone][subdir] = apps

projects[oa_domains][version] = 2.0-alpha2
projects[oa_domains][subdir] = apps

projects[oa_favorites][version] = 2.0-alpha2
projects[oa_favorites][subdir] = apps

projects[oa_htmlmail][version] = 2.0-alpha2
projects[oa_htmlmail][subdir] = apps

projects[oa_home][version] = 2.0-alpha2
projects[oa_home][subdir] = apps

projects[oa_messages_digest][version] = 2.0-alpha2
projects[oa_messages_digest][subdir] = apps

projects[oa_sandbox][version] = 2.0-alpha2
projects[oa_sandbox][subdir] = apps

projects[oa_styles][version] = 2.0-alpha2
projects[oa_styles][subdir] = apps

projects[oa_toolbar][version] = 2.0-alpha3
projects[oa_toolbar][subdir] = apps

projects[oa_tour][version] = 2.0-alpha2
projects[oa_tour][subdir] = apps

projects[oa_tour_defaults][version] = 2.0-alpha2
projects[oa_tour_defaults][subdir] = apps

; ***************** End Apps *********************
; ************************************************
