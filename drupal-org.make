api = 2
core = 7.x

; Panopoly Core
; Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here
; #################### Panopoly #######################
projects[panopoly_core][version] = 1.x-dev
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][revision] = 192ed62
projects[panopoly_core][download][branch] = 7.x-1.x

projects[panopoly_images][version] = 1.x-dev
projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][revision] = b57b48f
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][version] = 1.x-dev
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][revision] = b8d3809
projects[panopoly_theme][download][branch] = 7.x-1.x

projects[panopoly_magic][version] = 1.x-dev
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][revision] = 4f59733
projects[panopoly_magic][download][branch] = 7.x-1.x

projects[panopoly_widgets][version] = 1.x-dev
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][revision] = 0dafe32
projects[panopoly_widgets][download][branch] = 7.x-1.x

projects[panopoly_admin][version] = 1.x-dev
projects[panopoly_admin][subdir] = panopoly
projects[panopoly_admin][download][type] = git
projects[panopoly_admin][download][revision] = 4d9d071
projects[panopoly_admin][download][branch] = 7.x-1.x

projects[panopoly_users][version] = 1.x-dev
projects[panopoly_users][subdir] = panopoly
projects[panopoly_users][download][type] = git
projects[panopoly_users][download][revision] = cb4ca09
projects[panopoly_users][download][branch] = 7.x-1.x

; The Panopoly Toolset

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][revision] = 4125aa6
projects[panopoly_pages][download][branch] = 7.x-1.x

projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][revision] = e2f938b
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][version] = 1.x-dev
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][revision] = 2f6d3e4
projects[panopoly_search][download][branch] = 7.x-1.x
; #################### END Panopoly #######################
; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][download][type] = git
;projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
;projects[panopoly][download][branch] = 7.x-1.x

; **** Panopoly Overrides ****
; Update Panels to fix issue with custom region styles
projects[panels][version] = 3.x-dev
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][revision] = a915408
projects[panels][download][branch] = 7.x-3.x
projects[panels][patch][] = http://drupal.org/files/1838544-panels_ipe_region_style_0.patch

; Update Panelizer to latest with features override patch
projects[panelizer][type] = module
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][url] = http://git.drupal.org/project/panelizer.git
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][download][revision] = 775e91df7a50d8bd7591e2258780aba106558151
projects[panelizer][patch][] = http://drupal.org/files/panelizer-features-override-1912162-2.patch

; Update File entity to handle private content
projects[file_entity][type] = module
projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = git
projects[file_entity][download][url] = http://git.drupal.org/project/file_entity.git
projects[file_entity][download][branch] = 7.x-2.x
projects[file_entity][download][revision] = e1fa3e05a8f849e54cddd703a9dc1b6e8f7c55de
projects[file_entity][patch][] = http://drupal.org/files/1420812-file_download-41.patch

; Entityreference to work with Devel Generate
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][download][type] = git
projects[entityreference][download][url] = http://git.drupal.org/project/entityreference.git
projects[entityreference][download][branch] = 7.x-1.x
projects[entityreference][download][revision] = 1c176daef3e7483389cbebeb34784b3af6521f7f

; Private file system fix
projects[media_youtube][version] = 2.x-dev
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = c53660cde8c7d223f62ea41bc1ce0391c15ed006
projects[media_youtube][download][branch] = 7.x-2.x

;
; **** end of overrides ****

; Parent Theme
projects[radix][version] = 2.0-alpha3
projects[radix][patch][] = http://drupal.org/files/radix-template-1907666-2.patch

; Parent Theme
;projects[radix][download][type] = git
;projects[radix][download][url] = http://git.drupal.org/project/radix.git
;projects[radix][download][branch] = 7.x-2.x
;projects[radix][download][revision] = fbcbc725ba78792efc4fe2aee78d37b1cc567fc6
;projects[radix][patch][] = http://drupal.org/files/radix_button_parent-1975516.patch

; Features Override
projects[features_override][subdir] = contrib
projects[features_override][version] = 2.0-beta2

; Organic Groups
projects[og][subdir] = contrib
projects[og][version] = 2.1

; Organic Groups Vocabulary
projects[og_vocab][subdir] = contrib
projects[og_vocab][version] = 1.1

; Rules
projects[rules][subdir] = contrib
projects[rules][version] = 2.2

; Message
projects[message][subdir] = contrib
projects[message][version] = 1.7
projects[message][patch][] = http://drupal.org/files/message-install-creates-error-1404838-10.patch

; Message Notify
projects[message_notify][subdir] = contrib
projects[message_notify][version] = 2.4

; Message Subscribe
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][version] = 1.0-alpha4

; Flag
projects[flag][subdir] = contrib
projects[flag][version] = 2.0
projects[flag][patch][] = http://drupal.org/files/flag-all-bundles-7.x-2.x-471212-13.patch
projects[flag][patch][] = http://drupal.org/files/1351124-21.7x2x.patch

; RealName
projects[realname][subdir] = contrib
projects[realname][version] = 1.0
projects[realname][patch][] = http://drupal.org/files/985944_realname_Replace+user+autocomplete+with+realname+autocomplete.patch

; Chosen
projects[chosen][subdir] = contrib
projects[chosen][version] = 1.0
projects[chosen][patch][] = http://drupal.org/files/issues/chosen-7.x-1.x-install_profile.patch

; Twitter Bootstrap UI
;; Currently removed Twitter Bootstrap because of license issue:
;; http://drupal.org/node/1449452 http://drupal.org/node/1445226#comment-7343538
;; Instead, we load the Bootstrap JS via external CDN in template.php
;;projects[twitter_bootstrap_ui][type] = module
;;projects[twitter_bootstrap_ui][subdir] = contrib
;;projects[twitter_bootstrap_ui][download][type] = git
;;projects[twitter_bootstrap_ui][download][url] = http://git.drupal.org/project/twitter_bootstrap_ui.git
;;projects[twitter_bootstrap_ui][download][branch] = 7.x-2.x
;;projects[twitter_bootstrap_ui][patch][] = http://drupal.org/files/twitter_bootstrap_ui-allow_admin_configuration-1906722-5.patch
; tie to previous commit before the (2.x) was added to libraries
; since that doesn't work when module is patched in inherited profile
;;projects[twitter_bootstrap_ui][download][revision] = 0328b6ff027287fe7e62b058fc4dea12362956f5

;;libraries[twitter_bootstrap][download][type] = file
;;libraries[twitter_bootstrap][download][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip

; Make file for oa_media
; Colorbox
projects[colorbox][subdir] = contrib
projects[colorbox][version] = 2.3

projects[media_colorbox][subdir] = contrib
projects[media_colorbox][version] = 1.0-rc3

libraries[colorbox][download][type] = file
libraries[colorbox][download][url] = https://github.com/jackmoore/colorbox/archive/1.x.zip
libraries[colorbox][directory_name] = colorbox

; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2

; Colorbox
projects[colorbox][subdir] = contrib
;projects[colorbox][version] = 2.3
projects[colorbox][download][url] = http://git.drupal.org/project/colorbox.git
projects[colorbox][download][branch] = 7.x-2.x
projects[colorbox][download][revision] = 509c2634bad0a76c9a5e7e3a1f588a36a6a97095
projects[media_colorbox][subdir] = contrib
projects[media_colorbox][version] = 1.0-rc3

; Job Scheduler
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3

; Feeds
projects[feeds][subdir] = contrib
projects[feeds][version] = 2.0-alpha7

; Mailhandler
projects[mailhandler][subdir] = contrib
projects[mailhandler][download][type] = git
projects[mailhandler][download][url] = http://git.drupal.org/project/mailhandler.git
projects[mailhandler][download][branch] = 7.x-2.x
projects[mailhandler][download][revision] = c57579b7990dce3a0cf46336c78f2e7c17581723
projects[mailhandler][patch][] = http://drupal.org/files/mailhandler-version-requirement-1961780-1.patch

; Views Load More
projects[views_load_more][subdir] = contrib
projects[views_load_more][download][type] = git
projects[views_load_more][download][url] = http://git.drupal.org/project/views_load_more.git
projects[views_load_more][download][branch] = 7.x-1.x
projects[views_load_more][download][revision] = 28de3843dba06dcad12aaca2840535b0b7c035a4

; Mail System
projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; HTML Mail
projects[htmlmail][subdir] = contrib
projects[htmlmail][version] = 2.65

; Date Facets
projects[date_facets][subdir] = contrib
projects[date_facets][version] = 1.0-beta1
projects[date_facets][patch][] = http://drupal.org/files/date_facets-search-api-support-1834998-40.patch
