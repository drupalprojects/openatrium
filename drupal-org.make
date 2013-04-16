api = 2
core = 7.x

; Panopoly Core
projects[panopoly][type] = profile
projects[panopoly][download][type] = git
projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
projects[panopoly][download][branch] = 7.x-1.x

; **** Panopoly Overrides ****
; Update Features to latest version
projects[features][subdir] = contrib
projects[features][version] = 2.0-beta2

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

; Navbar (Overridden from Panopoly)
projects[navbar][subdir] = contrib
projects[navbar][version] = 1.0-alpha3
projects[navbar][patch][] = http://drupal.org/files/navbar_has_mismatching_closing_tag_1875254_1.patch
;
; **** end of overrides ****

; Parent Theme
projects[radix][version] = 2.0-alpha3
projects[radix][patch][] = http://drupal.org/files/radix-template-1907666-2.patch

; Features Override
projects[features_override][subdir] = contrib
projects[features_override][version] = 2.0-beta2

; Organic Groups
projects[og][subdir] = contrib
projects[og][version] = 2.0-rc2

; Organic Groups Menu
projects[og_menu][type] = module
projects[og_menu][subdir] = contrib
projects[og_menu][download][type] = git
projects[og_menu][download][url] = http://git.drupal.org/project/og_menu.git
projects[og_menu][download][branch] = 7.x-3.x
projects[og_menu][patch][] = http://drupal.org/files/og_menu-js-10515420-11.patch

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
projects[twitter_bootstrap_ui][type] = module
projects[twitter_bootstrap_ui][subdir] = contrib
projects[twitter_bootstrap_ui][download][type] = git
projects[twitter_bootstrap_ui][download][url] = http://git.drupal.org/project/twitter_bootstrap_ui.git
projects[twitter_bootstrap_ui][download][branch] = 7.x-2.x
projects[twitter_bootstrap_ui][patch][] = http://drupal.org/files/twitter_bootstrap_ui-allow_admin_configuration-1906722-5.patch
; tie to previous commit before the (2.x) was added to libraries
; since that doesn't work when module is patched in inherited profile
projects[twitter_bootstrap_ui][download][revision] = 0328b6ff027287fe7e62b058fc4dea12362956f5

libraries[twitter_bootstrap][download][type] = file
libraries[twitter_bootstrap][download][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip

; Include other Open Atrium make files
includes[oa_media] = "modules/features/oa_media/oa_media.make"

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
projects[mailhandler][download][commit] = c57579b7990dce3a0cf46336c78f2e7c17581723
projects[mailhandler][patch][] = http://drupal.org/files/mailhandler-version-requirement-1961780-1.patch

; Views Load More
projects[views_load_more][subdir] = contrib
projects[views_load_more][download][type] = git
projects[views_load_more][download][url] = http://git.drupal.org/project/views_load_more.git
projects[views_load_more][download][branch] = 7.x-1.x
projects[views_load_more][download][commit] = a92b1f610fcf8ee85c064020d865ab849d0c86e6

; Mail System
projects[mailsystem][subdir] = contrib
projects[mailsystem][version] = 2.34

; HTML Mail
projects[htmlmail][subdir] = contrib
projects[htmlmail][version] = 2.65
