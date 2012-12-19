api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = 7.16
projects[drupal][patch][] = http://drupal.org/files/1356276-make-D7-21.patch

projects[panopoly][type] = profile
projects[panopoly][download][type] = git
projects[panopoly][download][url] = http://git.drupal.org/project/panopoly.git
projects[panopoly][download][branch] = 7.x-1.x

; Organic Groups
projects[og][type] = module
projects[og][download][type] = git
projects[og][download][url] = http://git.drupal.org/project/og.git
projects[og][download][branch] = 7.x-2.x
projects[og][subdir] = contrib

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

; Devel
projects[devel][type] = module
projects[devel][download][type] = git
projects[devel][download][url] = http://git.drupal.org/project/devel.git
projects[devel][download][branch] = 7.x-1.x
projects[devel][subdir] = contrib

; Diff
projects[diff][subdir] = contrib
projects[diff][version] = 3.2
