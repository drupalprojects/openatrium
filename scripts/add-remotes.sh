#!/bin/bash
# Script to add the remote Github repos for dev versions
# of Open Atrium submodules
#
TARGET=$1
# Use current dir as default
if [ -z "$TARGET" ]; then
  TARGET=`pwd -P`
fi
TARGET=`cd "$TARGET"; pwd -P`
echo 'Adding remotes...'

submodules=(
  "oa_core"
  "oa_discussion"
  "oa_events"
  "oa_wiki"
  "oa_admin"
  "oa_analytics"
  "oa_appearance"
  "oa_archive"
  "oa_clone"
  "oa_contextual_tabs"
  "oa_devel"
  "oa_domains"
  "oa_events_import"
  "oa_favorites"
  "oa_files"
  "oa_home"
  "oa_htmlmail"
  "oa_mailhandler"
  "oa_markdown"
  "oa_media"
  "oa_messages_digest"
  "oa_notifications"
  "oa_sandbox"
  "oa_search"
  "oa_sitemap"
  "oa_styles"
  "oa_subspaces"
  "oa_toolbar"
  "oa_tour"
  "oa_tour_defaults"
  "oa_wizard"
  "oa_files"
  "oa_related"
)

for subdir in "${submodules[@]}"
do
  if [ -e "$TARGET/modules/contrib/$subdir/.git" ]; then
    cd $TARGET/modules/contrib/$subdir
    # adding drupal repo.
    git remote add drupal http://git.drupal.org/project/$subdir.git
  else
    echo "** No git repository found for module $subdir"
  fi
done
subthemes=( "oa_radix" )
for subdir in "${subthemes[@]}"
do
  if [ -e "$TARGET/themes/$subdir/.git" ]; then
    cd $TARGET/themes/$subdir
    # adding drupal repo.
    git remote add drupal http://git.drupal.org/project/$subdir.git
  else
    echo "** No git repository found for theme $subdir"
  fi
done

