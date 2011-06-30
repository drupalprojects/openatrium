#!/bin/bash
#
# This command expects to be run within the Open Atrium profile directory. To
# generate a full distribution you must be in a git checkout.
#
# To use this command you must have `drush make` and `git` installed.
#

if [ -f openatrium.make ]; then
  echo -e "\nThis command can be used to run openatrium.make in place, or to generate"
  echo -e "a complete distribution of Open Atrium.\n\nWhich would you like?"
  echo "  [1] Rebuild Open Atrium in place."
  echo "  [2] Build a full Open Atrium distribution"
  echo -e "Selection: \c"
  read SELECTION

  if [ $SELECTION = "1" ]; then

    # Run openatrium.make only.
    echo "Building Open Atrium install profile..."
    drush make --download-mechanism='drush_make' --working-copy --no-core --contrib-destination=. openatrium.make

  elif [ $SELECTION = "2" ]; then

    # Generate a complete tar.gz of Drupal + Open Atrium.
    echo "Building Open Atrium distribution..."

MAKE=$(cat <<EOF
core = "6.x"\n
api = "2"\n
projects[drupal][type] = "core"\n
projects[drupal][version] = "6.22"\n
projects[drupal][patch][] = "http://drupalcode.org/project/openatrium.git/blob_plain/refs/heads/master:/robots_txt_rollback.patch"\n
projects[openatrium][type] = "profile"\n
projects[openatrium][download][type] = "git"\n
projects[openatrium][download][url] = "git://git.drupal.org/project/openatrium.git"\n
EOF
)

    TAG=`git describe --tags --abbrev=0`
    if [ -n $TAG ]; then
      if [ $TAG = "fatal: No names found, cannot describe anything." ]; then
        MAKETAG=""
        VERSION="head"
      else
        MAKETAG="projects[openatrium][download][tag] = $TAG"
        VERSION="${TAG:4}"
      fi
      MAKE="$MAKE $MAKETAG\n"
      NAME=`echo "atrium-$VERSION" | tr '[:upper:]' '[:lower:]'`
      echo -e $MAKE | drush make --download-mechanism='drush_make' --yes --tar - $NAME
    else
      echo 'Could not determine git tag. Is openatium git clone checkout?'
    fi
  else
   echo "Invalid selection."
  fi
else
  echo 'Could not locate file "openatrium.make"'
fi
