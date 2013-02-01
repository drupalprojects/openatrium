api = 2
core = 7.x

; Panopoly Core
projects[panopoly][type] = profile
projects[panopoly][download][type] = git
projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
projects[panopoly][download][branch] = 7.x-1.x

; override panelizer version
projects[panelizer][version] = 3.x-dev
projects[panelizer][subdir] = contrib
projects[panelizer][download][type] = git
projects[panelizer][download][revision] = 8a58e76da74fa01d1f8eab1ece9b5117a20ab7ff
projects[panelizer][download][branch] = 7.x-3.x

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
projects[message][version] = 1.6

; Message Notify
projects[message_notify][subdir] = contrib
projects[message_notify][version] = 2.3

; Message Subscribe
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][version] = 1.0-alpha2

; Flag
projects[flag][subdir] = contrib
projects[flag][version] = 2.0

; Chosen
projects[chosen][subdir] = contrib
projects[chosen][version] = 1.0
projects[chosen][patch][] = http://drupal.org/files/issues/chosen-7.x-1.x-install_profile.patch

; Navbar (Overridden from Panopoly)
projects[navbar][subdir] = contrib
projects[navbar][version] = 1.0-alpha3
projects[navbar][patch][] = http://drupal.org/files/navbar_has_mismatching_closing_tag_1875254_1.patch

; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2
