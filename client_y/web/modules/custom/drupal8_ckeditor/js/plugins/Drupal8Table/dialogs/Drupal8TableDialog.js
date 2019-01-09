(function () {
  'use strict';

  CKEDITOR.dialog.add('drupal8TableDialog', function (editor) {
    return {
      title: 'Drupal8 Table',
      minWidth: 300,
      minHeight: 100,
      contents: [
        {
          id: 'tab-basic',
          label: 'Basic Settings',
          elements: [
            {
              type: 'select',
              id: 'type',
              label: 'Table type',
              items: editor.config.drupal8Table_options,
              default: editor.config.drupal8Table_options[0][0],
              validate: CKEDITOR.dialog.validate.notEmpty('Select table type.'),
            }
          ]
        }
      ],
      onOk: function () {
        var dialog = this;
        var value = dialog.getValueOf('tab-basic', 'type');
        if (value != "") {
          var table = editor.config.drupal8Table_list[value];
          editor.insertHtml(table.markup);
        }
      }
    };
  });

})();
