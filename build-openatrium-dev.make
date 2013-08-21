api = 2
core = 7.x
; Include the definition for how to build Drupal core directly, including patches:
includes[] = drupal-org-core.make
; Download the OpenAtrium install profile and recursively build all its dependencies:
projects[openatrium][type] = profile
projects[openatrium][download][type] = git
projects[openatrium][download][branch] = 7.x-2.x
; Provide a -dev version until drupal.org supports include files
projects[openatrium][patch][2071051] = "http://drupal.org/files/openatrium-dev-release-2071051-1.patch"
