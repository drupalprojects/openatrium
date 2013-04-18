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

        $form.attr('action', determineSearchPath(term, type, settings.oa_search.space));
      });

      $dropdown.click(function(e) {
        e.stopPropagation();
      });
    }
  };

  function determineSearchPath(term, type, space) {
    var path = '/search' + '/' + (type === 'users' ? 'user' : 'node') + '/' + term;
    if (type === 'this_space') {
      // %3A instead of : because of some weird double encoding on the backend.
      path += '?f[0]=' + encodeURIComponent('og_group_ref%3Atitle:' + space);
    }
    return path;
  }

})(jQuery);