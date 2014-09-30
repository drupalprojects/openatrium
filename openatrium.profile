<?php

/**
 * @file
 * Install profile for Open Atrium.
 */

include_once 'install_from_db/install_from_db.profile';

/**
 * Implements hook_appstore_stores_info().
 */
function openatrium_apps_servers_info() {
 $info =  drupal_parse_info_file(dirname(__file__) . '/openatrium.info');
 return array(
   'openatrium' => array(
     'title' => 'OpenAtrium',
     'description' => "Apps for the OpenAtrium distribution",
     // @CHANGE this to -stable for stable releases.
     'manifest' => 'http://appserver.openatrium.com/app/query/openatrium-development',
     'profile' => 'openatrium',
     'profile_version' => isset($info['version']) ? $info['version'] : '7.x-2.x-dev',
     'server_name' => !empty($_SERVER['SERVER_NAME']) ? $_SERVER['SERVER_NAME'] : '',
     'server_ip' => !empty($_SERVER['SERVER_ADDR']) ? $_SERVER['SERVER_ADDR'] : '',
   ),
 );
}

/**
 * Implements hook_install_tasks()
 */
function openatrium_install_tasks(&$install_state) {
  $tasks = array();

  // Add our custom CSS file for the installation process
  drupal_add_css(drupal_get_path('profile', 'openatrium') . '/openatrium.css');

  $tasks['openatrium_features_revert_all'] = array(
    'type' => 'normal',
  );

  // Need to rebuild search index tables since oa_search changes panopoly_search.
  $tasks['openatrium_rebuild_search'] = array(
    'type' => 'normal',
  );


  require_once(drupal_get_path('module', 'apps') . '/apps.profile.inc');
  $server = array(
    'machine name' => 'openatrium',
    'default apps' => array(
      'oa_discussion',
      'oa_wiki',
      'oa_events',
      'oa_events_import',
      'oa_worktracker',
      'oa_home',
      'oa_appearance',
      'oa_htmlmail',
      'oa_archive',
      'oa_tour_defaults',
      'oa_tour',
      'oa_admin',
      'oa_styles',
      'oa_media',
      'oa_contextual_tabs',
      'oa_clone',
      'oa_subspaces',
      'oa_sandbox',
      'oa_messages_digest',
      'oa_favorites',
      'oa_notifications',
      'oa_toolbar',
    ),
  );
  $tasks = array_merge($tasks, apps_profile_install_tasks($install_state, $server));

  return $tasks;
}

/**
 * Revert all features.
 */
function openatrium_features_revert_all() {
  global $install_state;
  drupal_set_time_limit(0);
  // only revert features when not doing a quick install
  if (empty($install_state['parameters']['quickstart']) || ($install_state['parameters']['quickstart'] != 'quick')) {
    features_revert(array(
      'oa_core' => array('field_base'),
      'oa_sections' => array('field_base', 'field_instance'),
      'oa_users' => array('field_instance'),
    ));
    features_revert();
  }
}

/**
 * Rebuild search index.
 */
function openatrium_rebuild_search() {
  global $install_state;
  // only rebuild search when not doing a quick install
  if (empty($install_state['parameters']['quickstart']) || ($install_state['parameters']['quickstart'] != 'quick')) {
    require_once(drupal_get_path('module', 'oa_search') . '/oa_search.install');
    features_revert(array(
      'oa_search' => array('search_api_index'),
    ));
    oa_search_rebuild_index();
  }
}

/**
 * Implements hook_install_tasks_alter()
 */
function openatrium_install_tasks_alter(&$tasks, $install_state) {
  require_once(drupal_get_path('module', 'oa_core') . '/oa_core.profile.inc');
  $tasks['install_load_profile']['function'] = 'oa_core_install_load_profile';
  // Add option for importing from db.
  install_from_db_install_tasks_alter($tasks, $install_state);
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form.
 */
function openatrium_form_install_configure_form_alter(&$form, $form_state) {
  // @todo Why am I here?
}

/**
 * Implements hook_form_FORM_ID_alter() for apps_profile_apps_select.
 */
function openatrium_form_apps_profile_apps_select_form_alter(&$form, $form_state) {
  // panopoly_form_apps_profile_apps_select_form_alter($form, $form_state);
  ############## INCLUDE FROM PANOPOLY #####################
  // Disabling showing of these for now.
  $form['apps_message']['#access'] = FALSE;
  unset($form['apps_fieldset']['apps']['#title']);

  // Improve style of apps selection form
  if (isset($form['apps_fieldset'])) {
    $manifest = apps_manifest(apps_servers('panopoly'));
    foreach ($manifest['apps'] as $name => $app) {
      if ($name != '#theme') {
        $form['apps_fieldset']['apps']['#options'][$name] = '<strong>' . $app['name'] . '</strong><p><div class="admin-options"><div class="form-item">' . theme('image', array('path' => $app['logo']['path'], 'height' => '32', 'width' => '32')) . '</div>' . $app['description'] . '</div></p>';
      }
    }
  }

  // Remove the demo content selection option since this is handled through the Panopoly demo module.
  $form['default_content_fieldset']['#access'] = FALSE;
  // ########### END PANOPOLY ################
}

/**
 * Implements hook_form_FORM_ID_alter() for panopoly_theme_selection_form.
 */
function openatrium_form_panopoly_theme_selection_form_alter(&$form, &$form_state, $form_id) {
  // Change the default theme in the selection form.
  unset($form['theme_wrapper']['theme']['#options']['radix']);
  unset($form['theme_wrapper']['theme']['#options']['radix_starter']);
  $form['theme_wrapper']['theme']['#default_value'] = 'oa_radix';
}

