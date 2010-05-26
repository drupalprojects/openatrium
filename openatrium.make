; $Id$
core = "6.x"

; Contrib projects 

projects[admin][subdir] = "contrib"
projects[admin][version] = "2.0-beta2"

projects[boxes][subdir] = "contrib"
projects[boxes][version] = "1.0-beta6"

projects[casetracker][subdir] = "contrib"
projects[casetracker][version] = "1.0-beta7"

projects[cck][subdir] = "contrib"
projects[cck][version] = "2.6"

projects[codefilter][subdir] = "contrib"
projects[codefilter][version] = "1.0"

projects[comment_upload][subdir] = "contrib"
projects[comment_upload][version] = "1.0-alpha5"

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = "1.0-beta4"

projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta5"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.4"

projects[date][subdir] = "contrib"
projects[date][version] = "2.4"

projects[designkit][subdir] = "contrib"
projects[designkit][version] = "1.0-alpha5"

projects[diff][subdir] = "contrib"
projects[diff][version] = "2.1-alpha3"

projects[features][subdir] = "contrib"
projects[features][version] = "1.0-beta7"

projects[feeds][subdir] = "contrib"
projects[feeds][version] = "1.0-alpha13"

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = "1.6"

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = "2.0-beta10"

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = "1"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "1.0-alpha1"

projects[mailcomment][subdir] = "contrib"
projects[mailcomment][version] = "1.0"

projects[mailhandler][subdir] = "contrib"
projects[mailhandler][version] = "1.10"

projects[markdown][subdir] = "contrib"
projects[markdown][version] = "1.1"

projects[messaging][subdir] = "contrib"
projects[messaging][version] = "2.2"

projects[notifications][subdir] = "contrib"
projects[notifications][version] = "2.2"

projects[notifications_team][subdir] = "contrib"
projects[notifications_team][version] = "2.0-beta6"

projects[og][subdir] = "contrib"
projects[og][version] = "2.1"

projects[openidadmin][subdir] = "contrib"
projects[openidadmin][version] = "1.2"

projects[parser_ical][subdir] = "contrib"
projects[parser_ical][version] = "2.0-alpha1"

projects[prepopulate][subdir] = "contrib"
projects[prepopulate][version] = "1.1"

projects[purl][subdir] = "contrib"
projects[purl][version] = "1.0-beta11"

projects[spaces][subdir] = "contrib"
projects[spaces][version] = "3.0-beta4"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0-rc1"

projects[token][subdir] = "contrib"
projects[token][version] = "1.12"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "2.1"

projects[ucreate][subdir] = "contrib"
projects[ucreate][version] = "1.0-beta3"

; Patched
projects[views][subdir] = "contrib"
projects[views][type] = "module"
projects[views][version] = "2.10"
; http://drupal.org/node/694094
projects[views][patch][] = "http://drupal.org/files/issues/694094_views_default_reset_2010-05-25.patch"
; original issue: http://drupal.org/node/357529
projects[views][patch][] = "http://cloud.github.com/downloads/developmentseed/atrium_features/views2_simple_translatables.patch"

; Custom modules
projects[litecal][subdir] = "custom"
projects[litecal][location] = "http://code.developmentseed.org/fserver"
projects[litecal][version] = "1.0-alpha2"

projects[litenode][subdir] = "custom"
projects[litenode][location] = "http://code.developmentseed.org/fserver"
projects[litenode][version] = "1.0-alpha1"

projects[feedapi2feeds][subdir] = "custom"
projects[feedapi2feeds][location] = "http://code.developmentseed.org/fserver"
projects[feedapi2feeds][version] = "1.0-alpha1"

projects[seed][subdir] = "custom"
projects[seed][location] = "http://code.developmentseed.org/fserver"
projects[seed][version] = "4.1"

projects[xref][subdir] = "custom"
projects[xref][location] = "http://code.developmentseed.org/fserver"
projects[xref][version] = "1.0-alpha1"

; Development modules
projects[coder][subdir] = "developer"
projects[coder][version] = "2.0-beta1"

projects[devel][subdir] = "developer"
projects[devel][version] = "1.18"

projects[schema][subdir] = "developer"
projects[schema][version] = "1.7"

projects[simpletest][subdir] = "developer"
projects[simpletest][version] = "2.8"

; Features
; projects[atrium_features][location] = "http://code.developmentseed.org/fserver"
; projects[atrium_features][version] = "1.0-alpha4"
projects[atrium_features][type] = "module"
projects[atrium_features][download][type] = "git"
projects[atrium_features][download][url] = "git://github.com/developmentseed/atrium_features.git"

; l10n
projects[core_translation][subdir] = "l10n"
projects[core_translation][type] = "module"
projects[core_translation][download][type] = "cvs"
projects[core_translation][download][module] = "contributions/modules/core_translation"
projects[core_translation][download][revision] = "HEAD:2010-02-17"

projects[l10n_client][subdir] = "l10n"
projects[l10n_client][version] = "1.7"

projects[l10n_update][subdir] = "l10n"
projects[l10n_update][location] = "http://code.developmentseed.org/fserver"
projects[l10n_update][version] = "1.0-alpha1"

; Themes
projects[tao][location] = "http://code.developmentseed.org/fserver"
projects[tao][version] = "1.9"

projects[rubik][location] = "http://code.developmentseed.org/fserver"
projects[rubik][version] = "1.0-beta6"

projects[ginkgo][location] = "http://code.developmentseed.org/fserver"
projects[ginkgo][version] = "1.0-alpha4"

; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

; Translations for openatrium install profile
libraries[translations][download][type] = "get"
libraries[translations][download][url] = "https://translate.openatrium.com/sites/translate.openatrium.com/files/atrium-installer-beta4.tar.gz"
libraries[translations][directory_name] = "translations"
libraries[translations][destination] = .
