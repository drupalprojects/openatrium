/**
 * @file
 * Defines the behavior of the toolbar menu toggle button.
 */
(function ($) {

  Drupal.behaviors.oaDashboard = {
    attach: function(context, settings) {
      var tray = $('#navbar .navbar-tray');
      var button = $('#toolbar-menu-button');
      var navbar = $('#oa-navbar');

      if (navbar.length) {
        $('body').css('padding-top', (navbar.height()+10) + 'px');
      }
    }
  }

}(jQuery));
