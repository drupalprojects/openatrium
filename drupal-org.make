api = 2
core = 7.x

; ************************************************
; ************** PANOPOLY OVERRIDES **************

; Note that makefiles are parsed bottom-up and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY OVERRIDES need to be listed AT THE TOP of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; Override panopoly_core.make: a915408
; Patch Panels to fix issue with custom region styles (#1838544)
projects[panels][type] = module
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][url] = http://git.drupal.org/project/panels.git
projects[panels][download][revision] = a915408
projects[panels][download][branch] = 7.x-3.x
projects[panels][patch][1838544] = http://drupal.org/files/1838544-panels_ipe_region_style_0.patch
projects[panels][patch][2024441] = http://drupal.org/files/panels_edit_style_settings_form_validate_include_plugins.patch

projects[ctools][type] = module
projects[ctools][subdir] = contrib
projects[ctools][download][type] = git
projects[ctools][download][url] = http://git.drupal.org/project/ctools.git
projects[ctools][download][revision] = 83817fa
projects[ctools][download][branch] = 7.x-1.x
projects[ctools][patch][1901106] = http://drupal.org/files/1901106-ctools-views_content-exposed_form_override-13.patch
projects[ctools][patch][2016559] = http://drupal.org/files/ctools_views_content_numeric_pager_id.patch
projects[ctools][patch][2023705] = http://drupal.org/files/2023705-ctools-autosubmit-2.patch
projects[ctools][patch][1910608] = https://drupal.org/files/1910608-views_content-ajax-4.patch

; Override panopoly_core.make: 3.1
; Update Panelizer to latest dev version
projects[panelizer][type] = module
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][url] = http://git.drupal.org/project/panelizer.git
projects[panelizer][download][branch] = 7.x-3.x
projects[panelizer][download][revision] = 1e050d3
projects[panelizer][patch][1992106] = http://drupal.org/files/1992106_panelizer_features_pipe-1.patch
projects[panelizer][patch][1982654] = http://drupal.org/files/1982654-panelizer-dontaskmethatagain-2.patch
projects[panelizer][patch][2022541] = http://drupal.org/files/2022541-panelizer-node-page-unpublished-1.patch


; Override panopoly_core.make: 1.0
; Update Entity Reference to work with Devel Generate (#1852112)
projects[entityreference][type] = module
projects[entityreference][subdir] = contrib
projects[entityreference][download][type] = git
projects[entityreference][download][url] = http://git.drupal.org/project/entityreference.git
projects[entityreference][download][branch] = 7.x-1.x
projects[entityreference][download][revision] = 1c176da

; Override panopoly_core.make: 1143ee2
; Patch FAPE to fix warnings (#1846156)
projects[fape][type] = module
projects[fape][subdir] = contrib
projects[fape][download][type] = git
projects[fape][download][url] = http://git.drupal.org/project/fape.git
projects[fape][download][branch] = 7.x-1.x
projects[fape][download][revision] = 1143ee2
projects[fape][patch][1846156] = http://drupal.org/files/fape-1846156-5.patch

; Override panopoly_widgets.make: 5418cbe
; Update Media Youtube to work with private filesystem (#1946002)
projects[media_youtube][type] = module
projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][url] = http://git.drupal.org/project/media_youtube.git
projects[media_youtube][download][branch] = 7.x-2.x
projects[media_youtube][download][revision] = c53660c

; Override panopoly_core.make: 72f3d17
; Update token to allow disabling of empty token errors during test runs
projects[token][type] = module
projects[token][subdir] = contrib
projects[token][download][type] = git
projects[token][download][url] = http://git.drupal.org/project/token.git
projects[token][download][branch] = 7.x-1.x
projects[token][download][revision] = 72f3d17
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch



; ************ End Panopoly Overrides ************
; ************************************************


; ************************************************
; ********** OPEN ATRIUM'S DEPENDENCIES **********

; Features Override
projects[features_override][subdir] = contrib
projects[features_override][version] = 2.0-beta2

; Features
projects[features][subdir] = contrib
projects[features][download][type] = git
projects[features][download][url] = http://git.drupal.org/project/features.git
projects[features][download][branch] = 7.x-2.x
projects[features][patch][2027023] = http://drupal.org/files/features_conflict_components.patch

projects[views][version] = 3.7
projects[views][subdir] = contrib
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = http://drupal.org/files/1735096-views-mltiple-instance-exposed-form-8.patch

; Organic Groups
projects[og][download][type] = git
projects[og][subdir] = contrib
projects[og][download][url] = http://git.drupal.org/project/og.git
projects[og][download][branch] = 7.x-2.x
projects[og][download][revision] = 05ee95269e2c31492158dc6eabd2e386aec1c931
projects[og][patch][1995012] = http://drupal.org/files/og_membership_alter.patch
projects[og][patch][998094] = http://drupal.org/files/998094-og_membership_administer_member-16.patch

; Organic Groups Vocabulary
projects[og_vocab][subdir] = contrib
projects[og_vocab][version] = 1.1

; Organic Groups Subgroups
projects[og_subgroups][subdir] = contrib
projects[og_subgroups][download][type] = git
projects[og_subgroups][download][url] = http://git.drupal.org/project/og_subgroups.git
projects[og_subgroups][download][branch] = 7.x-2.x
projects[og_subgroups][patch][2029123] = http://drupal.org/files/2029123-og_permission_and_cache-5.patch
projects[og_subgroups][patch][1995018] = http://drupal.org/files/1995018-og_subgroups_og_alter-5.patch

; Message
projects[message][subdir] = contrib
projects[message][version] = 1.8

; Message Notify
projects[message_notify][subdir] = contrib
projects[message_notify][version] = 2.5

; Message Subscribe
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][version] = 1.0-alpha5

; Markdown
projects[markdown][subdir] = contrib
projects[markdown][version] = 1.1

; Flag
projects[flag][subdir] = contrib
projects[flag][version] = 2.0
projects[flag][download][type] = git
projects[flag][download][url] = http://git.drupal.org/project/flag.git
projects[flag][download][branch] = 7.x-2.x
projects[flag][download][revision] = 32cac54
projects[flag][patch][471212] = http://drupal.org/files/471212-14-flag-all-bundles.patch
projects[flag][patch][2027091] = http://drupal.org/files/flag_hook_flag_default_flags_alter.patch

; RealName
projects[realname][subdir] = contrib
projects[realname][version] = 1.1

; Chosen
projects[chosen][subdir] = contrib
projects[chosen][version] = 2.0-alpha1

libraries[chosen][download][type]    = git
libraries[chosen][download][url]     = https://github.com/harvesthq/chosen.git
libraries[chosen][download][tag]     = v0.9.15

; Twitter Bootstrap UI
;; Currently removed Twitter Bootstrap because of license issue:
;; http://drupal.org/node/1449452 http://drupal.org/node/1445226#comment-7343538
;; Instead, we load the Bootstrap JS via external CDN in template.php
;;projects[twitter_bootstrap_ui][type] = module
;;projects[twitter_bootstrap_ui][subdir] = contrib
;;projects[twitter_bootstrap_ui][download][type] = git
;;projects[twitter_bootstrap_ui][download][url] = http://git.drupal.org/project/twitter_bootstrap_ui.git
;;projects[twitter_bootstrap_ui][download][branch] = 7.x-2.x
;;projects[twitter_bootstrap_ui][patch][1906722] = http://drupal.org/files/twitter_bootstrap_ui-allow_admin_configuration-1906722-5.patch
; tie to previous commit before the (2.x) was added to libraries
; since that doesn't work when module is patched in inherited profile
;;projects[twitter_bootstrap_ui][download][revision] = 0328b6ff027287fe7e62b058fc4dea12362956f5

;;libraries[twitter_bootstrap][download][type] = file
;;libraries[twitter_bootstrap][download][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip

; Make file for oa_media
; Colorbox
projects[colorbox][subdir] = contrib
projects[colorbox][version] = 2.4

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

; Coder
projects[coder][type] = module
projects[coder][download][type] = git
projects[coder][download][url] = http://git.drupal.org/project/coder.git
projects[coder][download][branch] = 7.x-2.x
projects[coder][subdir] = contrib

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2

; Job Scheduler
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3

; Feeds
projects[feeds][type] = module
projects[feeds][subdir] = contrib
projects[feeds][download][type] = git
projects[feeds][download][url] = http://git.drupal.org/project/feeds.git
projects[feeds][download][branch] = 7.x-2.x
projects[feeds][download][revision] = 7e6679d

; Command buttons
projects[command_buttons][type] = module
projects[command_buttons][subdir] = contrib
projects[command_buttons][download][type] = git
projects[command_buttons][download][url] = http://git.drupal.org/project/command_buttons.git
projects[command_buttons][download][branch] = 7.x-1.x
projects[command_buttons][download][revision] = 8f6c4f4

; Google Analytics
projects[google_analytics][subdir] = contrib
projects[google_analytics][version] = 1.3

; Views Load More
projects[views_load_more][subdir] = contrib
projects[views_load_more][download][type] = git
projects[views_load_more][download][url] = http://git.drupal.org/project/views_load_more.git
projects[views_load_more][download][branch] = 7.x-1.x
projects[views_load_more][download][revision] = 28de384

; Mail System
projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; HTML Mail
projects[htmlmail][subdir] = contrib
projects[htmlmail][version] = 2.65

; Date Facets
projects[date_facets][subdir] = contrib
projects[date_facets][download][type] = git
projects[date_facets][download][url] = http://git.drupal.org/project/date_facets.git
projects[date_facets][download][branch] = 7.x-1.x
projects[date_facets][download][revision] = a7a35f8

; Og menu single
projects[og_menu_single][subdir] = contrib
projects[og_menu_single][download][type] = git
projects[og_menu_single][download][url] = http://git.drupal.org/project/og_menu_single.git
projects[og_menu_single][download][branch] = 7.x-1.x
projects[og_menu_single][type] = module

; Variable
projects[variable][subdir] = contrib
projects[variable][version] = 2.2

; Og Variables
projects[og_variables][subdir] = contrib
projects[og_variables][download][type] = git
projects[og_variables][download][url] = http://git.drupal.org/project/og_variables.git
projects[og_variables][download][branch] = 7.x-1.x
projects[og_variables][type] = module

; Reference Option Limit
projects[reference_option_limit][subdir] = contrib
projects[reference_option_limit][download][type] = git
projects[reference_option_limit][download][url] = http://git.drupal.org/project/reference_option_limit.git
projects[reference_option_limit][download][branch] = 7.x-1.x
projects[reference_option_limit][download][revision] = 74bee91
projects[reference_option_limit][type] = module
projects[reference_option_limit][patch][1986532] = http://drupal.org/files/1986532_reference_option_limit_og-2.patch
projects[reference_option_limit][patch][1986526] = http://drupal.org/files/1986526_reference_option_limit_3.patch

; Conditional Fields
projects[conditional_fields][subdir] = contrib
projects[conditional_fields][download][branch] = 7.x-3.x
projects[conditional_fields][download][revision] = cd29b00
projects[conditional_fields][patch][1982276] = http://drupal.org/files/conditional_fields-typo-in-if-condition-1982276-1.patch
projects[conditional_fields][patch][2027307] = http://drupal.org/files/conditional_fields-export-0.patch
projects[conditional_fields][patch][1916988] = http://drupal.org/files/1916988-conditional-fields-alter-3.patch

; Trash Flag
projects[trash_flag][type] = module
projects[trash_flag][download][type] = git
projects[trash_flag][subdir] = contrib
projects[trash_flag][download][url] = http://git.drupal.org/project/trash_flag.git
projects[trash_flag][download][branch] = 7.x-1.x

projects[panels_customerror][type] = module
projects[panels_customerror][subdir] = contrib
projects[panels_customerror][download][type] = git
projects[panels_customerror][download][url] = http://git.drupal.org/project/panels_customerror.git
projects[panels_customerror][download][branch] = 7.x-1.x

; Jquery Update
projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = 2.3
projects[jquery_update][patch][1448490] = http://drupal.org/files/jquery_update-fixes-states-js-1448490.patch

; ******** End Open Atrium's Dependencies ********
; ************************************************

; ************************************************
; ************* Open Atrium Plugins **************

projects[oa_discussion][type] = module
projects[oa_discussion][subdir] = contrib
projects[oa_discussion][download][type] = git
projects[oa_discussion][download][url] = http://git.drupal.org/project/oa_discussion.git
projects[oa_discussion][download][branch] = 7.x-2.x

projects[oa_wiki][type] = module
projects[oa_wiki][subdir] = contrib
projects[oa_wiki][download][type] = git
projects[oa_wiki][download][url] = http://git.drupal.org/project/oa_wiki.git
projects[oa_wiki][download][branch] = 7.x-2.x

projects[oa_events][type] = module
projects[oa_events][subdir] = contrib
projects[oa_events][download][type] = git
projects[oa_events][download][url] = http://git.drupal.org/project/oa_events.git
projects[oa_events][download][branch] = 7.x-2.x

projects[oa_events_import][type] = module
projects[oa_events_import][subdir] = contrib
projects[oa_events_import][download][type] = git
projects[oa_events_import][download][url] = http://git.drupal.org/project/oa_events_import.git
projects[oa_events_import][download][branch] = 7.x-2.x

projects[oa_radix][type] = theme
projects[oa_radix][download][type] = git
projects[oa_radix][download][url] = http://git.drupal.org/project/oa_radix.git
projects[oa_radix][download][branch] = 7.x-2.x

; ********** End Open Atrium's Plugins ***********
; ************************************************


; ************************************************
; ******************* PANOPOLY *******************

; Note that makefiles are parsed bottom-up, and that in Drush concurrency might
; interfere with recursion.
; Therefore PANOPOLY needs to be listed AT THE BOTTOM of this makefile,
; so we can patch or update certain projects fetched by Panopoly's makefiles.

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][download][type] = git
;projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
;projects[panopoly][download][branch] = 7.x-1.x

; Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.x-dev
projects[panopoly_core][subdir] = panopoly
projects[panopoly_core][download][type] = git
projects[panopoly_core][download][revision] = 6a257ac
projects[panopoly_core][download][branch] = 7.x-1.x
projects[panopoly_core][patch][1979558] = http://drupal.org/files/1979558-panopoly-core-update-patch-4.patch

projects[panopoly_images][version] = 1.x-dev
projects[panopoly_images][subdir] = panopoly
projects[panopoly_images][download][type] = git
projects[panopoly_images][download][revision] = b57b48f
projects[panopoly_images][download][branch] = 7.x-1.x

projects[panopoly_theme][version] = 1.x-dev
projects[panopoly_theme][subdir] = panopoly
projects[panopoly_theme][download][type] = git
projects[panopoly_theme][download][revision] = 7715ded
projects[panopoly_theme][download][branch] = 7.x-1.x


projects[panopoly_magic][version] = 1.x-dev
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][download][revision] = 16add888f93577ad9a27379ca309fcf7bd870a80
projects[panopoly_magic][download][branch] = 7.x-1.x
projects[panopoly_magic][patch][2016527] = http://drupal.org/files/2016527-panopoly_magic_parents_exposed-2.patch
projects[panopoly_magic][patch][2016643] = http://drupal.org/files/2016643_panopoly_magic_screw_pre_render_with_2016527-3-do-not-test.patch
projects[panopoly_magic][patch][2017159] = http://drupal.org/files/2017159_panopoly_magic_preview_post_render-7.patch


projects[panopoly_widgets][version] = 1.x-dev
projects[panopoly_widgets][subdir] = panopoly
projects[panopoly_widgets][download][type] = git
projects[panopoly_widgets][download][revision] = 6ca2f97
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

projects[panopoly_pages][version] = 1.x-dev
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][download][revision] = 4125aa6
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][patch][2008762] = http://drupal.org/files/2008762-panopoly_pages-missing-depedency-1.patch

projects[panopoly_wysiwyg][version] = 1.x-dev
projects[panopoly_wysiwyg][subdir] = panopoly
projects[panopoly_wysiwyg][download][type] = git
projects[panopoly_wysiwyg][download][revision] = 227335f
projects[panopoly_wysiwyg][download][branch] = 7.x-1.x

projects[panopoly_search][version] = 1.x-dev
projects[panopoly_search][subdir] = panopoly
projects[panopoly_search][download][type] = git
projects[panopoly_search][download][revision] = c981ec3
projects[panopoly_search][download][branch] = 7.x-1.x

; ***************** End Panopoly *****************
; ************************************************
