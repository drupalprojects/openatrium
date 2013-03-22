/**
 * @file
 * Defines the behavior of the toolbar menu toggle button.
 */
(function ($) {

  Drupal.behaviors.toolbarMenuButton = {
    attach: function(context, settings) {
      var tray = $('#navbar .navbar-tray');
      var button = $('#toolbar-menu-button');
      var navbar = $('#oa-navbar');

      if (button.length) {
        // if using the button in toolbar, hide the navbar module's nav bar
        $('#navbar .navbar-bar').hide();
      }
      if (tray.length && button.length) {
        button.click(function(e) {
          $('body').toggleClass('menu-tray-open');
          tray.toggleClass('active');

          // When it's stickied, we need to manually shrink the navbar width.
          if (settings.oa_toolbar_sticky == 1) {
            navbar.css('margin-left', tray.hasClass('active') ? tray.width() : 0);
          }
        });
      }
    }
  }

}(jQuery));
