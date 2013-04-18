(function($) {

  Drupal.behaviors.oa_toolbar_search = {
    attach: function(context, settings) {
      var $form = $('.toolbar-search form');
      var $search_bar = $form.find('input[type="text"]');
      var $dropdown = $form.find('.dropdown-menu');
      var $dropdown_toggle = $form.find('.dropdown-toggle');
      $form.submit(function() {
        var term = $form.find('input[type="text"]').val();
        var type = $form.find('input:checked').val();
        var action = '/search' + '/' + (type === 'users' ? 'user' : 'node') + '/' + term;

        $form.attr('action', action);
      });

      $dropdown.click(function(e) {
        e.stopPropagation();
      });
    }
  };

})(jQuery);