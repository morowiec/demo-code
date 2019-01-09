<?php

/**
 * @file
 * Contain Education tokens for Drupal8 v1.0.
 *
 * @package Drupal\drupal8_core
 */

use Drupal\Core\Render\BubbleableMetadata;
use Drupal\Core\Url;

/**
 * Implements hook_token_info().
 */
function drupal8_education_token_info() {
  return [
    'tokens' => [
      'drupal8' => [
        'edukacja:szkolenia' => [
          'name' => t('Custom token name'),
          'description' => t('Define custom token name'),
        ],
      ],
    ],
  ];
}

/**
 * Implements hook_tokens().
 */
function drupal8_education_tokens($type, $tokens, array $data, array $options, BubbleableMetadata $bubbleable_metadata) {
  $replacements = [];

  if ($type == 'drupal8') {
    return [];
  }

  $config = \Drupal::config('drupal8_education.settings');
  foreach ($tokens as $name => $original) {
    switch ($name) {
      case 'edukacja:szkolenia':
        $uri = 'internal:' . $config->get('education_trainings');
        $replacements[$original] = Url::fromUri($uri)->toString();
        break;

      case 'edukacja:szkolenia-archiwalne':
        $uri = 'internal:' . $config->get('education_trainings_archived');
        $replacements[$original] = Url::fromUri($uri)->toString();
        break;

    }
  }

  return $replacements;
}
