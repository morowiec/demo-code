<?php

/**
 * @file
 * Helper functions for the install file of clientx_offers.
 */

/**
 * Create or update a translation string for a taxonomy term.
 *
 * Designed for taxonomy vocabulary, that have i18n option selected.
 *
 * @param object $term
 *   The term object with the tid set.
 * @param string $langcode
 *   The langcode for the translation.
 * @param string $translation
 *   The translation string.
 */
function _clientx_offers_create_term_translation($term, $langcode, $translation, $property = 'name') {
  $context = array(
    'term',
    $term->tid,
    $property,
  );
  $textgroup = 'taxonomy';
  i18n_string_textgroup($textgroup)->update_translation($context, $langcode, $translation);
}

/**
 * Create terms for vocabulary.
 *
 * @param string $vocabluary_name
 *    Vocabluary machine name.
 * @param array $terms
 *    Array of terms in 3 languages.
 */
function _clientx_offers_populate_vocab($vocabluary_name, array $terms) {
  // Load the vocabulary object.
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabluary_name);

  // Create the terms for vocabulary.
  foreach ($terms as $term_name) {
    $term = (object) array(
      'name' => $term_name['en'],
      'vid' => $vocabulary->vid,
    );
    taxonomy_term_save($term);

    // Translate terms.
    if (isset($term_name['fr'])) {
      _clientx_offers_create_term_translation($term, 'fr', $term_name['fr']);
    }
    if (isset($term_name['de'])) {
      _clientx_offers_create_term_translation($term, 'de', $term_name['de']);
    }
  }
}
