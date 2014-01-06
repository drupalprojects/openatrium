#!/bin/bash
# Script to add the remote Github repos for dev versions
# of Open Atrium submodules
#
TARGET=$1
# Use current dir as default
if [ -z "$TARGET" ]; then
  TARGET=`pwd -P`
fi
echo 'Adding remotes...'
submodules=( "oa_core" "oa_discussion" "oa_wiki" "oa_events" "oa_events_import" "oa_contextual_tabs" "oa_notifications" "oa_media" "oa_subspaces" )
for subdir in "${submodules[@]}"
do
  cd $TARGET/modules/contrib/$subdir
  git remote rename origin drupal
  git remote add --track 7.x-2.x origin git@github.com:phase2/$subdir.git
done
subthemes=( "oa_radix" )
for subdir in "${subthemes[@]}"
do
  cd $TARGET/themes/$subdir
  git remote rename origin drupal
  git remote add --track 7.x-2.x origin git@github.com:phase2/$subdir.git
done

