<?php

/**
 * @file
 * Translation overview content type plugin.
 */

$plugin = array(
  'title' => t('clientx | Offers | Translation overview'),
  'single' => TRUE,
  'category' => t('clientx | Offers'),
  'render callback' => 'clientx_offers_translation_overview_content_type_render',
  'required context' => array(
    0 => new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Render callback.
 */
function clientx_offers_translation_overview_content_type_render($subtype, $conf, $panel_args, $context) {
  include_once DRUPAL_ROOT . '/includes/language.inc';

  $node = $context[0]->data;

  if ($node->tnid) {
    // Already part of a set, grab that set.
    $tnid = $node->tnid;
    $translations = translation_node_get_translations($node->tnid);
  }
  else {
    // We have no translation source nid, this could be a new set, emulate that.
    $tnid = $node->nid;
    $translations = array(entity_language('node', $node) => $node);
  }

  $type = variable_get('translation_language_type', LANGUAGE_TYPE_INTERFACE);
  $header = array(t('Language'), t('Title'), t('Status'), t('Operations'));
  foreach (language_list() as $langcode => $language) {
    $options = array();
    $language_name = $language->name;
    if (isset($translations[$langcode])) {
      // Existing translation in the translation set: display status.
      // We load the full node to check whether the user can edit it.
      $translation_node = node_load($translations[$langcode]->nid);
      $path = 'node/' . $translation_node->nid;
      $links = language_negotiation_get_switch_links($type, $path);
      $title = empty($links->links[$langcode]['href']) ? l($translation_node->title, $path) : l($translation_node->title, $links->links[$langcode]['href'], $links->links[$langcode]);
      $text = t('edit');
      $path = clientxSomeOffers::MAIN_OFFER_PATH . $translation_node->nid . '/edit';
      $links = language_negotiation_get_switch_links($type, $path);
      $options[] = empty($links->links[$langcode]['href']) ? l($text, $path) : l($text, $links->links[$langcode]['href'], $links->links[$langcode]);
      $status = $translation_node->status ? t('Published') : t('Not published');
      $status .= $translation_node->translate ? ' - <span class="marker">' . t('outdated') . '</span>' : '';
      if ($translation_node->nid == $tnid) {
        $language_name = t('<strong>@language_name</strong> (source)', array('@language_name' => $language_name));
      }
    }
    else {
      // No such translation in the set yet: help user to create it.
      $title = t('n/a');
      $text = t('add translation');
      $path = clientxSomeOffers::MAIN_OFFER_PATH . 'add/' . clientxSomeOffers::OFFER_CT_URL;
      $links = language_negotiation_get_switch_links($type, $path);
      $query = array('query' => array('translation' => $node->nid, 'target' => $langcode));
      $options[] = empty($links->links[$langcode]['href']) ? l($text, $path, $query) : l($text, $links->links[$langcode]['href'], array_merge_recursive($links->links[$langcode], $query));
      $status = t('Not translated');
    }
    $rows[] = array($language_name, $title, $status, implode(" | ", $options));
  }

  $build['translation_node_overview'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  $block = new stdClass();
  $block->content = $build;
  return $block;
}
