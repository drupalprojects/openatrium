/**
 * @file
 * Manage spacing for dashboard and navbar tray.
 */
(function ($) {

  Drupal.behaviors.oaDashboard = {
    attach: function(context, settings) {
      var $tray = $('#navbar .navbar-tray');
      var $button = $('#toolbar-menu-button');
      var $navbar = $('#oa-navbar');

      $(window).resize(function() {
        if ($navbar.css('position') == 'static') {
          $('body').css('padding-top', '0');
        }
      });
    }
  }

}(jQuery));
