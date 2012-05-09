; Drupal Core
core = "7.x"
api = "2"

; Contrib projects 
projects[apps][subdir] = custom
projects[apps][version] = 1.0-beta5

projects[boxes][subdir] = "contrib"
projects[boxes][version] = "1.0-beta7"

;projects[casetracker][subdir] = "contrib"
;projects[casetracker][version] = "1.0-beta9"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.x-dev"

projects[codefilter][subdir] = "contrib"
projects[codefilter][version] = "1.0"

;projects[comment_upload][subdir] = "contrib"
;projects[comment_upload][version] = "1.0-alpha6"

projects[conditional_styles][subdir] = contrib
projects[conditional_styles][version] = 2.1

;projects[content_profile][subdir] = "contrib"
;projects[content_profile][version] = "1.0"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta2"

projects[context_field][subdir] = contrib
projects[context_field][version] = 1.0-beta3

;projects[crayon][subdir] = "contrib"
;projects[crayon][version] = "1.0-beta3"

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.0
;projects[ctools][patch][] = http://drupal.org/files/1371180-add-export-module.patch

projects[data][subdir] = "contrib"
projects[data][version] = "1.0-alpha3"

projects[date][subdir] = "contrib"
projects[date][version] = "2.2"

projects[delta][subdir] = contrib
projects[delta][version] = 3.0-beta9

;projects[designkit][subdir] = "contrib"
;projects[designkit][version] = "1.0-beta1"

projects[diff][subdir] = contrib
projects[diff][version] = 2.0

projects[entity][subdir] = contrib
projects[entity][version] = 1.0-rc1

projects[entity_autocomplete][subdir] = contrib
projects[entity_autocomplete][version] = 1.0-beta1

projects[entitycache][subdir] = contrib
projects[entitycache][version] = 1.1

projects[features][subdir] = "contrib"
projects[features][version = "1.0-rc1"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "2.0-alpha4"

projects[field_collection][subdir] = contrib
projects[field_collection][version] = 1.x-dev
projects[field_collection][patch][] = http://drupal.org/files/issue_1329856_1.patch

projects[field_group][subdir] = contrib
projects[field_group][version] = 1.1

; d.o problem with filefield_sources downloads
;projects[filefield_sources][subdir] = contrib
;projects[filefield_sources][version] = 1.4

;projects[imageapi][subdir] = "contrib"
;projects[imageapi][version] = "1.10"

;projects[imagecache][subdir] = "contrib"
;projects[imagecache][version] = "2.0-beta12"

projects[imagecache_profiles][subdir] = "contrib"
projects[imagecache_profiles][version] = "1.0"

projects[imce][subdir] = contrib
projects[imce][version] = 1.5

projects[imce_wysiwyg][subdir] = contrib
projects[imce_wysiwyg][version] = 1.0

;projects[itweak_upload][subdir] = "contrib"
;projects[itweak_upload][version] = "2.5"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "2.0-alpha2"

;projects[jquery_ui][subdir] = "contrib"
;projects[jquery_ui][version] = "1.5"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "2.2"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0"

;projects[litecal][subdir] = "contrib"
;projects[litecal][version] = "1.0"

projects[mailcomment][subdir] = "contrib"
projects[mailcomment][version] = "2.1"

projects[mailhandler][subdir] = "contrib"
projects[mailhandler][version] = "2.4"

projects[markdown][subdir] = "contrib"
projects[markdown][version] = "1.0"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "1.0-alpha2"

projects[nodeblock][subdir] = contrib
projects[nodeblock][version] = 1.2

projects[nodeconnect][subdir] = contrib
projects[nodeconnect][version] = 1.0-alpha2

projects[nodeformcols][subdir] = "contrib"
projects[nodeformcols][version] = "1.x-dev"

projects[notifications][subdir] = "contrib"
projects[notifications][version] = "1.0-alpha2"
;projects[notifications][patch][] = "https://raw.github.com/gist/1444791/77e3bc869fe8fab2b78f782c28799e662a959dad/plain_check--notification-6.x-2.3.patch"

projects[notifications_team][subdir] = "contrib"
projects[notifications_team][version] = "3.x-dev"

projects[og][subdir] = "contrib"
projects[og][version] = "1.3"

projects[og_views][subdir] = "contrib"
projects[og_views][version] = "1.0"

projects[omega_tools][subdir] = contrib
projects[omega_tools][version] = 3.0-rc4

projects[openidadmin][subdir] = contrib
projects[openidadmin][version] = 1.0

;projects[parser_ical][subdir] = "contrib"
;projects[parser_ical][version] = "2.0-beta1"

projects[prepopulate][subdir] = "contrib"
projects[prepopulate][version] = "2.x-dev"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.0-beta1"

projects[references][subdir] = contrib
projects[references][version] = 2.0

;projects[reldate][subdir] = "contrib"
;projects[reldate][version] = "1.0-beta2"

projects[spaces][type] = "module"
projects[spaces][download][type] = "git"
projects[spaces][download][url] = "http://git.drupal.org/project/spaces.git"
projects[spaces][download][branch] = "7.x-3.x"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0-rc1"

projects[token][subdir] = "contrib"
projects[token][version] = "1.0-rc1"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.0"

;projects[ucreate][subdir] = "contrib"
;projects[ucreate][version] = "1.0-beta4"

projects[views][subdir] = "contrib"
projects[views][version] = "3.3"
; http://drupal.org/node/694094
;projects[views][patch][] = "http://drupal.org/files/issues/views-static-cache-resets-694094-7.patch"
; original issue: http://drupal.org/node/357529
;projects[views][patch][] = "http://cloud.github.com/downloads/developmentseed/atrium_features/views2_simple_translatables.patch"
; http://drupal.org/node/789674#comment-3230930
;projects[views][patch][] = "http://drupal.org/files/789674-29-vocabulary_module-6.x-2.x.patch"
; fix views SQL missing alias
;projects[views][patch][] = "https://raw.github.com/gist/1434459/99c827d0500acd78c2e428a72eb1d29d642d1a2a/views-2.16-1040744.patch"

projects[views_arguments_extras][subdir] = contrib
projects[views_arguments_extras][version] = 1.0-beta1

projects[views_boxes][subdir] = contrib
projects[views_boxes][version] = 1.0-beta8

projects[views_infinite_scroll][subdir] = contrib
projects[views_infinite_scroll][version] = 1.0

projects[vntf][subdir] = contrib
projects[vntf][version] = 1.0-beta6

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][version] = 2.1
projects[wysiwyg][patch][] = http://drupal.org/files/issues/wysiwyg-835682-12.patch

;projects[xref][subdir] = "contrib"
;projects[xref][version] = "1.0"

; Development modules
projects[coder][subdir] = "developer"
projects[coder][version] = "1.0"

projects[devel][subdir] = "developer"
projects[devel][version] = "1.2"

projects[schema][subdir] = "developer"
projects[schema][version] = "1.0-beta3"

projects[simpletest][subdir] = "developer"
projects[simpletest][version] = "2.0"

; Features
projects[atrium_features][type] = "module"
projects[atrium_features][download][type] = "git"
projects[atrium_features][download][url] = "http://git.drupal.org/project/atrium_features.git"
projects[atrium_features][download][branch] = "6.x-1.x"

; l10n
projects[l10n_client][subdir] = "l10n"
projects[l10n_client][version] = "1.0"

projects[l10n_update][subdir] = "l10n"
projects[l10n_update][version] = "1.0-beta3"


; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery-ui-1.7.3.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; Themes
projects[tao][type] = theme
projects[tao][version] = 3.0-beta4

projects[rubik][type] = theme
projects[rubik][version] = 4.0-beta6

projects[omega][type] = theme
projects[omega][version] = "3.1"

; Libraries
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.1/ckeditor_3.6.1.tar.gz
libraries[ckeditor][directory_name] = ckeditor

libraries[views_infinite_scroll][download][type] = get
libraries[views_infinite_scroll][download][url] = http://lagoscript.org/files/jquery/autopager/jquery.autopager-1.0.0.js
libraries[views_infinite_scroll][directory_name] = autopager


;libraries[jquery_ui][download][type] = "get"
;libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery-ui-1.7.3.zip"
;libraries[jquery_ui][directory_name] = "jquery.ui"
;libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; Translations for openatrium install profile
;libraries[translations][download][type] = "get"
;libraries[translations][download][url] = "https://translate.openatrium.com/sites/translate.openatrium.com/files/atrium-installer-beta9.tar.gz"
;libraries[translations][directory_name] = "translations"
;libraries[translations][destination] = "."

;core patches to allow simpletest to look into profiles for modules

// allow simpletest to look into profiles for modules
projects[drupal][type] = core
projects[drupal][patch][] = http://drupal.org/files/issues/911354.46.patch
projects[drupal][patch][] = http://drupal.org/files/issues/object_conversion_menu_router_build-972536-1.patch
projects[drupal][patch][] = http://drupal.org/files/issues/992540-3-reset_flood_limit_on_password_reset-drush.patch
