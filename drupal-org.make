api = 2
core = 7.x

; Panopoly Core
projects[panopoly][type] = profile
projects[panopoly][download][type] = git
projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
projects[panopoly][download][branch] = 7.x-1.x

; Parent Theme
projects[radix][version] = 2.0-alpha3
projects[radix][patch][] = http://drupal.org/files/radix-template-1907666-2.patch

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

; Message Notify
projects[message_notify][subdir] = contrib
projects[message_notify][version] = 2.3

; Message Subscribe
projects[message_subscribe][subdir] = contrib
projects[message_subscribe][version] = 1.0-alpha3

; Flag
projects[flag][subdir] = contrib
projects[flag][version] = 2.0

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
projects[twitter_bootstrap_ui][patch][] = http://drupal.org/files/twitter_bootstrap_ui-allow_admin_configuration-1906722-1.patch
projects[twitter_bootstrap_ui][download][revision] = 7dccf08a63d6e2ee301c481a044a3a1a58f4e912

libraries[twitter_bootstrap][type] = "libraries"
libraries[twitter_bootstrap][download][type] = "file"
libraries[twitter_bootstrap][download][url] = "http://twitter.github.com/bootstrap/assets/bootstrap.zip"

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
