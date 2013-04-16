<?php

$plugin = array(
  'title' => t('OA Email'),
  'description' => t('Send Message via email, with OpenAtrium enchancements.'),
  'class' => 'OaEmail',
  'options' => array(
    'html' => TRUE,
    'to' => FALSE,
    'from' => FALSE,
  ),
);

/**
 * Email notifier.
 */
class OaEmail extends MessageNotifierEmail {

  /**
   * Add Message notify view mode.
   */
  public static function viewModes() {
    return parent::viewModes();
  }

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
    dpm($options);
    $from = isset($options['from']) ? $options['from'] : NULL;

    // Pass the message entity along to hook_drupal_mail().
    $output['message_entity'] = $message;

    return drupal_mail('message_notify', $message->type, $mail, $lang, $output, $from);
  }
}
