api = 2
core = 7.x

; uncomment next line for -dev releases
includes[] = drupal-org-dev.make

; ************************************************
; ******************* PANOPOLY *******************

; Someday maybe we can turn this on to just inherit Panopoly
;projects[panopoly][type] = profile
;projects[panopoly][version] = 1.0-rc5
; but, Drupal.org does not support recursive profiles
; and also does not support include[]
; so we need to copy the panopoly.make file here

projects[panopoly_core][version] = 1.0-rc5
projects[panopoly_core][subdir] = panopoly

projects[panopoly_images][version] = 1.0-rc5
projects[panopoly_images][subdir] = panopoly

projects[panopoly_theme][version] = 1.0-rc5
projects[panopoly_theme][subdir] = panopoly

projects[panopoly_magic][version] = 1.0-rc5
projects[panopoly_magic][subdir] = panopoly
projects[panopoly_magic][download][branch] = 7.x-1.x
projects[panopoly_magic][download][type] = git
projects[panopoly_magic][patch][2016527] = http://drupal.org/files/2016643_panopoly_magic_screw_pre_render_with_2016527-5.patch
projects[panopoly_magic][patch][2017159] = http://drupal.org/files/2017159_panopoly_magic_preview_post_render-16.patch

projects[panopoly_widgets][version] = 1.0-rc5
projects[panopoly_widgets][subdir] = panopoly

projects[panopoly_admin][version] = 1.0-rc5
projects[panopoly_admin][subdir] = panopoly

projects[panopoly_users][version] = 1.0-rc5
projects[panopoly_users][subdir] = panopoly

projects[panopoly_pages][version] = 1.0-rc5
projects[panopoly_pages][subdir] = panopoly
projects[panopoly_pages][download][branch] = 7.x-1.x
projects[panopoly_pages][download][type] = git
projects[panopoly_pages][patch][2008762] = http://drupal.org/files/2008762-panopoly_pages-missing-depedency-1.patch

projects[panopoly_wysiwyg][version] = 1.0-rc5
projects[panopoly_wysiwyg][subdir] = panopoly

projects[panopoly_search][version] = 1.0-rc5
projects[panopoly_search][subdir] = panopoly

; ***************** End Panopoly *****************
; ************************************************

; ************************************************
; ************** PANOPOLY OVERRIDES **************

; Override panopoly_core.make: a915408
; Patch Panels to fix issue with custom region styles (#1838544)
projects[panels][type] = module
projects[panels][subdir] = contrib
projects[panels][download][type] = git
projects[panels][download][url] = http://git.drupal.org/project/panels.git
projects[panels][download][revision] = 2bb470e
projects[panels][download][branch] = 7.x-3.x
projects[panels][patch][1354572] = http://drupal.org/files/ipe-duplicate-1354572-7.patch
projects[panels][patch][2012188] = http://drupal.org/files/panels_ipe-title-ctools-2012188-3.patch
projects[panels][patch][2024441] = http://drupal.org/files/2024441-panels_standard_render_form_include-5.patch

projects[ctools][type] = module
projects[ctools][subdir] = contrib
projects[ctools][download][type] = git
projects[ctools][download][url] = http://git.drupal.org/project/ctools.git
projects[ctools][download][revision] = 83817fa
projects[ctools][download][branch] = 7.x-1.x
projects[ctools][patch][1901106] = http://drupal.org/files/1901106-ctools-views_content-exposed_form_override-13.patch
projects[ctools][patch][2016559] = http://drupal.org/files/ctools_views_content_numeric_pager_id.patch
projects[ctools][patch][2023705] = http://drupal.org/files/2023705-ctools-autosubmit-2.patch
projects[ctools][patch][1910608] = http://drupal.org/files/1910608-views_content-ajax-7.patch

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
projects[media_youtube][subdir] = contrib
projects[media_youtube][version] = 2.0-rc3

; Override panopoly_core.make: 72f3d17
; Update token to allow disabling of empty token errors during test runs
projects[token][type] = module
projects[token][subdir] = contrib
projects[token][download][type] = git
projects[token][download][url] = http://git.drupal.org/project/token.git
projects[token][download][branch] = 7.x-1.x
projects[token][version] = 1.5
projects[token][patch][1999298] = http://drupal.org/files/1999298-disable-test-warnings.patch

; Fix undefined did bug and installation issues.
projects[defaultconfig][subdir] = contrib
projects[defaultconfig][version] = 1.0-alpha9
projects[defaultconfig][download][type] = git
projects[defaultconfig][download][branch] = 7.x-1.x
projects[defaultconfig][patch][2042799] = http://drupal.org/files/default_config_delete_only_if_overriden.patch
projects[defaultconfig][patch][2043307] = http://drupal.org/files/defaultconfig_include_features_file.patch
projects[defaultconfig][patch][2008178] = http://drupal.org/files/defaultconfig-rebuild-filters-2008178-4_0.patch

; ************ End Panopoly Overrides ************
; ************************************************

; ************************************************
; ********** OPEN ATRIUM'S DEPENDENCIES **********

; Features
projects[features][version] = 2.0-rc2
projects[features][subdir] = contrib

; Features Override
projects[features_override][version] = 2.0-beta3
projects[features_override][type] = module
projects[features_override][subdir] = contrib

; Views
projects[views][version] = 3.7
projects[views][subdir] = contrib
projects[views][download][type] = git
projects[views][download][branch] = 7.x-3.x
projects[views][patch][1979926] = http://drupal.org/files/1979926-views-reset_fetch_data-2.patch
projects[views][patch][1735096] = http://drupal.org/files/1735096-views-mltiple-instance-exposed-form-8.patch

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2

; Job Scheduler
projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = 2.0-alpha3

; Mail System
projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; HTML Mail
projects[htmlmail][subdir] = contrib
projects[htmlmail][version] = 2.65

; ******** End Open Atrium's Dependencies ********
; ************************************************

; ************************************************
; ************* Open Atrium Plugins **************

projects[oa_core][subdir] = contrib
projects[oa_core][version] = 2.0-beta2

projects[oa_discussion][subdir] = contrib
projects[oa_discussion][version] = 2.0-beta1

projects[oa_wiki][subdir] = contrib
projects[oa_wiki][version] = 2.0-beta1

projects[oa_events][subdir] = contrib
projects[oa_events][version] = 2.0-beta2

projects[oa_events_import][subdir] = contrib
projects[oa_events_import][version] = 2.0-beta1

projects[oa_contextual_tabs][subdir] = contrib
projects[oa_contextual_tabs][version] = 2.0-beta1

projects[oa_notifications][subdir] = contrib
projects[oa_notifications][version] = 2.0-beta1

projects[oa_media][subdir] = contrib
projects[oa_media][version] = 2.0-beta1

projects[oa_subspaces][subdir] = contrib
projects[oa_subspaces][version] = 2.0-beta2

projects[oa_radix][type] = theme
projects[oa_radix][version] = 2.0-beta1

; ********** End Open Atrium's Plugins ***********
; ************************************************

; ************************************************
; ************* Open Atrium Modules **************
; (Modules in distro, not yet their own separate projects)

; ##### oa_markdown #####
; Markdown
projects[markdown][subdir] = contrib
projects[markdown][version] = 1.1

; ##### oa_search #####
; Date Facets
projects[date_facets][subdir] = contrib
projects[date_facets][download][type] = git
projects[date_facets][download][url] = http://git.drupal.org/project/date_facets.git
projects[date_facets][download][branch] = 7.x-1.x
projects[date_facets][download][revision] = a7a35f8

; ##### oa_analytics #####
; Google Analytics
projects[google_analytics][subdir] = contrib
projects[google_analytics][version] = 1.3

; Coder
projects[coder][type] = module
projects[coder][download][type] = git
projects[coder][download][url] = http://git.drupal.org/project/coder.git
projects[coder][download][branch] = 7.x-2.x
projects[coder][subdir] = contrib
