<?php

/**
 * @file
 * Install profile helper to add option for importing from database.
 */

/**
 * CALL THIS from your profile_install_tasks_alter() hook function.
 */
function install_from_db_install_tasks_alter(&$tasks, $install_state) {
  // redirect the drupal install_profile_modules step to our own function
  $tasks['install_profile_modules']['function'] = 'install_from_db_install_profile_modules';

  // add the new quickstart step to the installer
  $quickstart = array(
      'display_name' => st('Choose installation method'),
      'type' => 'form',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    );
  $tasks = _install_from_db_insert_before_key($tasks, 'install_profile_modules',
    'install_from_db_install_quickstart_form', $quickstart);
}

/**
 * Helper function to insert a key/value pair before an existing key
 * Used to re-order the install tasks array
 */
function _install_from_db_insert_before_key( $originalArray, $originalKey, $insertKey, $insertValue ) {
  $newArray = array();
  $inserted = false;
  foreach ($originalArray as $key => $value) {
    if (!$inserted && ($key === $originalKey)) {
      $newArray[$insertKey] = $insertValue;
      $inserted = true;
    }
    $newArray[$key] = $value;
  }
  return $newArray;
}

/**
 * Prompt user to select normal or quick installation method
 * TODO: Check db to be sure it is mysql, or provide mechanism for
 * using dumps of other database types.
 *
 * @see install_from_db_install_quickstart_form_validate()
 * @see install_from_db_install_quickstart_form_submit()
 */
function install_from_db_install_quickstart_form($form, &$form_state, &$install_state) {
  $profile = $install_state['parameters']['profile'];
  // find database dump in the /db folder within the profile
  // TODO: support different database dump formats
  $filename = DRUPAL_ROOT . '/profiles/' . $profile . '/db/' . $profile . '.sql';

  $conn = Database::getConnection('default');
  if (!file_exists($filename) || !$conn || ($conn->driver() !== 'mysql')) {
    // can't do quickstart if no db dump exists
    // also only allow quickstart for mysql databases currently
    unset($install_state['parameters']['quickstart']);
    $form_state['executed'] = TRUE;
    return;
  }
  $install_state['parameters']['db_import_filename'] = $filename;

  if (isset($install_state['parameters']['quickstart'])) {
    // if url argument is already specified, then just use it
    $form_state['executed'] = TRUE;
    return;
  }

  if (!$install_state['interactive']) {
    // no url argument, and not running interactively, so default to drupal standard
    $install_state['parameters']['quickstart'] = 'standard';
    $form_state['executed'] = TRUE;
    return;
  }

  $form['quickstart']['quick'] = array(
    '#type' => 'radio',
    '#value' => 'quick',
    '#return_value' => 'quick',
    '#title' => st('Quick installation'),
    '#description' => st('Quickly install using a predefined database dump. (recommended)'),
    '#parents' => array('quickstart'),
  );
  $form['quickstart']['standard'] = array(
    '#type' => 'radio',
    '#value' => 'quick',
    '#return_value' => 'standard',
    '#title' => st('Standard installation'),
    '#description' => st('Install using the full Drupal process.  This is slower.'),
    '#parents' => array('quickstart'),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] =  array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
  );
  return $form;
}

/**
 * Form validation handler for install_from_db_install_quickstart_form().
 *
 * @see install_from_db_install_quickstart_form_submit()
 */
function install_from_db_install_quickstart_form_validate($form, &$form_state) {
}

/**
 * Form submission handler for install_from_db_install_quickstart_form().
 *
 * @see install_from_db_install_quickstart_form_validate()
 */
function install_from_db_install_quickstart_form_submit($form, &$form_state) {
  global $install_state;
  $install_state['parameters']['quickstart'] = $form_state['input']['quickstart'];
}


/**
 * overrides install_profile_modules()
 * For quick install, load database from sql dump
 * otherwise install normally
 */
function install_from_db_install_profile_modules(&$install_state) {
  if (!empty($install_state['parameters']['quickstart']) && ($install_state['parameters']['quickstart'] === 'quick') && !empty($install_state['parameters']['db_import_filename'])) {
    // bypass normal module installation
    // load database dump instead
    // uses batch because normal module install task uses batch
    // and it's also good for this potentially time consuming db restore
    $operations = array();
    $defer_operations = array();
    $system_sql = '';
    $filename = $install_state['parameters']['db_import_filename'];
    if (file_exists($filename)) {
      $file = fopen($filename, 'rb');
      if ($file) {
        while (($line = _install_from_db_read_sql_batch($file, $table)) !== false) {
          if (!empty($line)) {
            // don't process blank lines
            if ($table === '') {
              // skip operations at end of dump that don't have a table,
              // like SET TIME_ZONE=@OLD_TIME_ZONE
            }
            elseif (in_array($table, array('system'))) {
              $defer_operations[] = array('_install_from_db_install_db_import', array($line, $table));
            }
            else {
              $operations[] = array('_install_from_db_install_db_import', array($line, $table));
            }
          }
        }
      }
      fclose($file);
      $operations = array_merge($operations, $defer_operations);
    }
    $batch = array(
      'operations' => $operations,
      'title' => st('Importing site database'),
      'error_message' => st('The database import has encountered an error.'),
      'finished' => '_install_from_db_install_db_import_finished',
    );
    return $batch;
  }
  return install_profile_modules($install_state);
}

/**
 * 'Finished' callback for module installation batch.
 */
function _install_from_db_install_db_import_finished($success, $results, $operations) {
  // remove any field data added to user entity
  // since we did not import any users
  $fields_info = field_info_instances('user', 'user');
  foreach ($fields_info as $field_name => $info) {
    db_delete('field_data_' . $field_name)
      ->condition('entity_type', 'user')
      ->condition('bundle', 'user')
      ->execute();
    db_delete('field_revision_' . $field_name)
      ->condition('entity_type', 'user')
      ->condition('bundle', 'user')
      ->execute();
  }
}

/**
 * Aggressively clear the cache so new database will take affect
 * Do this right after importing the new system module as the last step
 */
function _install_from_db_cc_all() {
  // load the module files as if we just installed them
  $module_list = module_list(TRUE);
  foreach ($module_list as $module) {
    drupal_load('module', $module);
  }

  drupal_static_reset();
  drupal_flush_all_caches();
}

/**
 * Batch callback for batch database import.
 */
function _install_from_db_install_db_import($line, $table, &$context) {
  global $conf;

  if ($table === 'variable') {
    // save/restore some variables needed by installer or unique to new site
    $saved_vars = array('install_task', 'install_current_batch', 'cron_key', 'drupal_private_key');
    foreach ($saved_vars as $var) {
      $saved_values[$var] = variable_get($var, '');
    }
  }

  // Do NOT use db_query here as it will mess with the query data, such as the {} in
  // serialized data fields.
  $conn = Database::getConnection('default');
  $stmt = $conn->prepare($line);
  $stmt->execute();
  $stmt->closeCursor();

  if ($table === 'variable') {
    // restore saved variables
    foreach ($saved_vars as $var) {
      variable_set($var, $saved_values[$var]);
    }
  }
  else if ($table === 'system') {
    // Flush all caches to complete the module installation process. Subsequent
    // installation tasks will now have full access to the profile's modules.
    _install_from_db_cc_all();
  }
  if (empty($table)) {
    $context['message'] = st('Database import completed.');
  }
  else {
    $context['message'] = st('Imported table @table', array('@table' => $table));
  }
}

/**
 * Read a batch of sql commands (ending in commit)
 * @param $file - name of file to read from
 * @param $table - name of table referenced in sql statements is returned
 * @return - string containing sql commands for a single table.
 */
function _install_from_db_read_sql_batch($file, &$table) {
  $conn = Database::getConnection('default');
  $line = '';
  $table = '';
  $skip = FALSE;
  $skip_tables = array('batch', 'cache', 'sessions', 'queue', 'semaphore', 'users');
  while (($newline = _install_from_db_read_sql_command_from_file($file)) !== false) {
    // process the line read.
    $newline_prefix = _install_from_db_replace_prefix($newline, $conn);
    if (!$skip) {
      // block of SQL starts with a DROP TABLE command
      if (preg_match('/\A(DROP TABLE IF EXISTS )`([^`]+)`/', $newline, $matches)) {
        $table = $matches[2];
        if (in_array($table, $skip_tables) || (strpos($table, 'cache_') === 0)) {
          // skip listed tables, along with any cache_* table
          $skip = TRUE;
        }
      }
    }
    else if (preg_match('/\A(CREATE TABLE )`([^`]+)`/', $newline, $matches)) {
      if ($matches[2] === $table) {
        // even though we are skipping a table, be sure it exists
        $newline_prefix = preg_replace('/\ACREATE TABLE/', 'CREATE TABLE IF NOT EXISTS', $newline_prefix);
        $line .= $newline_prefix;
      }
    }
    if (!$skip) {
      $line .= $newline_prefix;
    }
    // block of SQL ends with a commit command.
    if ($newline === 'commit;') {
      // be sure to turn autocommit back on for Drupal batch system and other database
      // queries to work properly
      $line .= 'set autocommit=1;';
      break;
    }
  }
  if (empty($line) && ($newline === FALSE)) {
    return FALSE;
  }
  return $line;
}

/**
 * Read a multiline sql command from a file.
 *
 * Supports the formatting created by mysqldump, but won't handle multiline comments.
 * Taken from backup_migrate module
 */
function _install_from_db_read_sql_command_from_file($file) {
  $out = '';
  while (($line = fgets($file)) !== false) {
    $line = trim($line);
    // Ignore single line comments.
    if (!empty($line) && substr($line, 0, 2) != '--') {
      $out .= ' ' . $line;
      // If a line ends in ; or */ it is a sql command.
      if (substr($out, strlen($out) - 1, 1) == ';' || substr($out, strlen($out) - 2, 2) == '*/') {
        return trim($out);
      }
    }
  }
  if (empty($out) && ($line === FALSE)) {
    return FALSE;
  }
  return trim($out);
}

/**
 * Apply the correct prefix to tables in the SQL statement
 */
function _install_from_db_replace_prefix($line, $conn) {
  $patterns = array(
    'DROP TABLE IF EXISTS',
    'CREATE TABLE',
    'LOCK TABLES',
    'ALTER TABLE',
    'INSERT INTO',
    'UPDATE',
  );
  foreach ($patterns as $pattern) {
    // handle lines like this:  /*!40000 ALTER TABLE `actions` ENABLE KEYS */;
    $find = '#\A((/\*\!\d+ )?' . $pattern . ' )`([^`]+)`#';
    // NOTE: We need to replace `tablename` with the new prefixed table name
    // We cannot run $conn->prefixQuery on the entire $line because it will mess
    // with the {} characters within serialized data.
    // So we ONLY match and replace the table name here.
    if (preg_match($find, $line, $matches)) {
      $new_table = $conn->prefixTables('{' . $matches[3] . '}');
      $replace = '$1`' . $new_table . '`';
      $line = preg_replace($find, $replace, $line);
    }
  }
  return $line;
}
