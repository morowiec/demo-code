<?php

namespace Drupal\drupal8_ckeditor\Plugin\CKEditorPlugin;

use Drupal\ckeditor\CKEditorPluginBase;
use Drupal\editor\Entity\Editor;

/**
 * Defines the new "Table" plugin.
 *
 * @CKEditorPlugin(
 *   id = "drupal8Table",
 *   label = @Translation("Drupal8 Table"),
 *   module = "drupal8_ckeditor"
 * )
 */
class Drupal8Table extends CKEditorPluginBase {

  /**
   * {@inheritdoc}
   */
  public function getFile() {
    return drupal_get_path('module', 'drupal8_ckeditor') . '/js/plugins/drupal8Table/plugin.js';

  }

  /**
   * {@inheritdoc}
   */
  public function getDependencies(Editor $editor) {
    return [];
  }

  /**
   * {@inheritdoc}
   */
  public function getLibraries(Editor $editor) {
    return [];
  }

  /**
   * {@inheritdoc}
   */
  public function isInternal() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getButtons() {
    return [
      'drupal8Table' => [
        'label' => t('Drupal8 Table'),
        'image' => drupal_get_path('module', 'drupal8_ckeditor') . '/js/plugins/drupal8Table/icons/drupal8Table.png',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function isEnabled(Editor $editor) {
  }

  /**
   * {@inheritdoc}
   */
  public function getConfig(Editor $editor) {
    $tables = $this->listTables();
    $list = [];
    foreach ($tables as $key => $table) {
      $list[] = [$table['label'], $key];
    }
    return [
      'drupal8Table_options' => $list,
      'drupal8Table_list' => $tables,
    ];
  }

  /**
   * List of tables.
   *
   * @return array
   *   List of tables.
   */
  private function listTables() {
    $tables = [];

    $tables[] = [
      "label" => "Table with promition button",
      "markup" => "<table class=\"block-atomic block-atomic-table-type-1\"><tbody><tr><td class=\"table-td-1\">Text</td><td class=\"table-td-2\"><span class=\"number\">1.00 PLN</span> <span class=\"text\">text text</span></td></tr><tr><td class=\"table-td-1\">Text</td><td class=\"table-td-2\"><span class=\"number\">1.00 PLN</span> <span class=\"text\">text text</span></td></tr><tr><td class=\"table-td-1\">Text</td><td class=\"table-td-2\"><span class=\"number\">1.00 PLN</span> <span class=\"text\">text text</span> <span class=\"btn-small-red\">Promotions</span></td></tr></tbody></table>",
    ];
    return $tables;
  }

}
