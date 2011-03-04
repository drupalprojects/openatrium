; $Id$
core = "6.x"
api = "2"

; Contrib projects 

projects[admin][subdir] = "contrib"
projects[admin][version] = "2.0"

projects[boxes][subdir] = "contrib"
projects[boxes][version] = "1.0"

projects[casetracker][subdir] = "contrib"
projects[casetracker][version] = "1.0-beta9"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.8"

projects[codefilter][subdir] = "contrib"
projects[codefilter][version] = "1.0"

projects[comment_upload][subdir] = "contrib"
projects[comment_upload][version] = "1.0-alpha5"

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = "1.0"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0"

projects[crayon][subdir] = "contrib"
projects[crayon][version] = "1.0-beta2"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.8"

projects[date][subdir] = "contrib"
projects[date][version] = "2.7"

projects[designkit][subdir] = "contrib"
projects[designkit][version] = "1.0-beta1"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.1"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "1.0-beta10"

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = "1.9"

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = "2.0-beta10"

projects[imagecache_profiles][subdir] = "contrib"
projects[imagecache_profiles][version] = "1.3"

projects[itweak_upload][subdir] = "contrib"
projects[itweak_upload][version] = "2.4"

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = "1.0-beta3"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1.4"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0-alpha1"

projects[mailcomment][subdir] = "contrib"
projects[mailcomment][version] = "1.0"

projects[mailhandler][subdir] = "contrib"
projects[mailhandler][version] = "1.11"

projects[markdown][subdir] = "contrib"
projects[markdown][version] = "1.2"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "2.4"

projects[nodeformcols][subdir] = "contrib"
projects[nodeformcols][version] = "1.6"

projects[notifications][subdir] = "contrib"
projects[notifications][version] = "2.3"

projects[notifications_team][subdir] = "contrib"
projects[notifications_team][version] = "2.1-beta8"

projects[og][subdir] = "contrib"
projects[og][version] = "2.1"

projects[openidadmin][subdir] = "contrib"
projects[openidadmin][version] = "1.2"

projects[parser_ical][subdir] = "contrib"
projects[parser_ical][version] = "2.0-beta1"

projects[prepopulate][subdir] = "contrib"
projects[prepopulate][version] = "2.1"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.0-beta13"

projects[reldate][subdir] = "contrib"
projects[reldate][version] = "1.0-beta2"

projects[spaces][subdir] = "contrib"
projects[spaces][version] = "3.1"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.15"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.0"

projects[ucreate][subdir] = "contrib"
projects[ucreate][version] = "1.0-beta4"

projects[views][subdir] = "contrib"
projects[views][type] = "module"
projects[views][version] = "2.12"
; http://drupal.org/node/694094
projects[views][patch][] = "http://drupal.org/files/issues/views-static-cache-resets-694094-7.patch"
; original issue: http://drupal.org/node/357529
projects[views][patch][] = "http://cloud.github.com/downloads/developmentseed/atrium_features/views2_simple_translatables.patch"
; http://drupal.org/node/789674#comment-3230930
projects[views][patch][] = "http://drupal.org/files/issues/789674-5_vocabulary_module.patch"

; Custom modules
projects[litecal][subdir] = "custom"
projects[litecal][location] = "http://featureserver.phase2technology.com/fserver"
projects[litecal][version] = "1.0-alpha5"

projects[feedapi2feeds][subdir] = "custom"
projects[feedapi2feeds][location] = "http://featureserver.phase2technology.com/fserver"
projects[feedapi2feeds][version] = "1.0-alpha1"

projects[xref][subdir] = "custom"
projects[xref][location] = "http://featureserver.phase2technology.com/fserver"
projects[xref][version] = "1.0-alpha2"

; Development modules
projects[coder][subdir] = "developer"
projects[coder][version] = "2.0-beta1"

projects[devel][subdir] = "developer"
projects[devel][version] = "1.23"

projects[schema][subdir] = "developer"
projects[schema][version] = "1.7"

projects[simpletest][subdir] = "developer"
projects[simpletest][type] = "module"
projects[simpletest][download][type] = "cvs"
projects[simpletest][download][module] = "contributions/modules/simpletest"
projects[simpletest][download][revision] = "DRUPAL-6--2:2010-01-27"

; Features
projects[atrium_features][location] = "http://featureserver.phase2technology.com/fserver"
projects[atrium_features][version] = "1.0-alpha11"

; l10n
projects[core_translation][subdir] = "l10n"
projects[core_translation][type] = "module"
projects[core_translation][download][type] = "cvs"
projects[core_translation][download][module] = "contributions/modules/core_translation"
projects[core_translation][download][revision] = "HEAD:2010-02-17"

projects[l10n_client][subdir] = "l10n"
projects[l10n_client][version] = "1.7"

projects[l10n_update][subdir] = "l10n"
projects[l10n_update][location] = "http://featureserver.phase2technology.com/fserver"
projects[l10n_update][version] = "1.0-alpha1"

; Themes
projects[tao][type] = "theme"
projects[tao][version] = "3.2"

projects[rubik][type] = "theme"
projects[rubik][version] = "3.0-beta2"

projects[ginkgo][type] = "theme"
projects[ginkgo][location] = "http://featureserver.phase2technology.com/fserver"
projects[ginkgo][version] = "1.0-alpha10"

; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; Translations for openatrium install profile
libraries[translations][download][type] = "get"
libraries[translations][download][url] = "https://translate.openatrium.com/sites/translate.openatrium.com/files/atrium-installer-beta9.tar.gz"
libraries[translations][directory_name] = "translations"
libraries[translations][destination] = "."
