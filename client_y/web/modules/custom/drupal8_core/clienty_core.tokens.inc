<?php

/**
 * @file
 * Contain core tokens for Drupal8 v1.0.
 *
 * @package Drupal\drupal8_core
 */

/**
 * Implements hook_token_info().
 */
function drupal8_core_token_info() {
  return [
    'types' => [
      'drupal8' => [
        'name' => t('Drupal8'),
        'description' => t('Define custom token type'),
      ],
    ],
    'tokens' => [],
  ];
}
