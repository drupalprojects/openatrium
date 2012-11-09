#!/bin/sh
# Script to build the Wilson Quarterly.
# Make sure the correct number of args was passed from the command line
if [ $# -eq 0 ]; then
  echo "Usage $0 target_build_dir"
  exit 1
fi
DRUSH_OPTS='--working-copy --no-gitinfofile'
MAKEFILE='build-panopoly.make'
TARGET=$1
# Make sure we have a target directory
if [ -z "$TARGET" ]; then
  echo "Usage $0 target_build_diri"
  exit 2
fi
CALLPATH=`dirname $0`
ABS_CALLPATH=`cd $CALLPATH; pwd -P`

echo '_______      ___'
echo '| ___ |     /  |'
echo '| | | |    /   |'
echo '| |_| |   / /| |'
echo '|____ |  / / | |'
echo '   OpenAtrium   '
echo '================'
 
# Temp move settings
echo 'Backing up settings.php...'
mv $TARGET/sites/default/settings.php settings.php
# Remove current drupal dir
echo 'Wiping Drupal directory...'
rm -rf $TARGET
# Do the build
echo 'Running drush make...'
drush make $DRUSH_OPTS $ABS_CALLPATH/$MAKEFILE $TARGET
# Build Symlinks
echo 'Setting up symlinks...'
DRUPAL=`cd $TARGET; pwd -P`
ln -s $ABS_CALLPATH $DRUPAL/profiles/panopoly
ln -s /opt/development/files/openatrium $DRUPAL/sites/default/files
ln -s ../../../settings.local.inc $DRUPAL/sites/default/settings.local.inc
 
# Restore settings
echo 'Restoring settings...'
mv settings.php $DRUPAL/sites/default/settings.php
# Clear caches and Run updates
cd $DRUPAL;
echo 'Clearing caches...'
drush cc all; drush cc all;
echo 'Running updates...'
drush updb -y;
echo 'Build complete.'
