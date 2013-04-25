<?php

/**
 * @file
 * Provides a message notifier that extends the default's email capabilities
 * with some Open Atrium specific additions.
 */

$plugin = array(
  'title' => t('OA Email'),
  'description' => t('Send Message via email, with OpenAtrium enchancements.'),
  'class' => 'OaEmail',
  'options' => array(
    'html' => TRUE,
    'to' => FALSE,
    'from' => FALSE,
  ),
  // A notifier must define its own view modes.
  // Those view modes are later going to be rendered and sent.
  'view_modes' => array(
    'message_notify_email_subject' => array('label' => t('Notify - Email subject')),
    'message_notify_email_body' => array('label' => t('Notify - Email body')),
  ),
);

// make sure message_notify parent class is included to avoid drush errors
include_once(drupal_get_path('module', 'message_notify') . '/plugins/notifier/email/MessageNotifierEmail.class.php');
/**
 * Email notifier.
 */
class OaEmail extends MessageNotifierEmail {

  /**
   * Override parent deliver() function.
   */
  public function deliver(array $output = array()) {
    $plugin = $this->plugin;
    $message = $this->message;
    $options = $plugin['options'];

    $account = user_load($message->uid);
    $mail = !empty($options['mail']) ? $options['mail'] : $account->mail;

    $languages = language_list();
    if (!$options['language override']) {
      $lang = !empty($account->language) && $account->language != LANGUAGE_NONE ? $languages[$account->language]: language_default();
    }
    else {
      $lang = $languages[$message->language];
    }

    // The subject in an email can't be with HTML, so strip it.
    $output['message_notify_email_subject'] = strip_tags($output['message_notify_email_subject']);

    // Allow for overriding the 'from' of the message.
    $from = isset($options['from']) ? $options['from'] : NULL;

    // Pass the message entity along to hook_drupal_mail().
    $output['message_entity'] = $message;

    return drupal_mail('message_notify', $message->type, $mail, $lang, $output, $from);
  }
}
