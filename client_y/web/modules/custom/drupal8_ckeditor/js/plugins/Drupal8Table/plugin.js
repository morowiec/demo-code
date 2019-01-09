﻿/**
 * @license Copyright (c) 2003-2018, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see LICENSE.md or https://ckeditor.com/legal/ckeditor-oss-license
 */

(function () {
  'use strict';

  CKEDITOR.plugins.add('drupal8Table', {
    requires: 'table',
    icons: 'drupal8Table',

    init: function (editor) {
      editor.addCommand('drupal8Table', new CKEDITOR.dialogCommand('drupal8TableDialog'));
      editor.ui.addButton('drupal8Table', {
        label: 'Drupal8 Table',
        command: 'drupal8Table',
        toolbar: 'insert'
      });
      CKEDITOR.dialog.add('drupal8TableDialog', this.path + 'dialogs/drupal8TableDialog.js');
    }
  });
})();
