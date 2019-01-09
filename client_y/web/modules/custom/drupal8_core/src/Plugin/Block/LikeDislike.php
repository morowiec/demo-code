<?php

namespace Drupal\drupal8_core\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\like_and_dislike\LikeDislikeVoteBuilder;
use Drupal\Core\StringTranslation\StringTranslationTrait;
use Drupal\Core\StringTranslation\TranslationInterface;

/**
 * Provides a 'Like and Dislike' Block.
 *
 * @package Drupal\drupal8_core
 *
 * @Block(
 *   id = "drupal8_like_dislike",
 *   admin_label = @Translation("Drupal8 | Core | Oceń artykuł"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class LikeDislike extends BlockBase implements ContainerFactoryPluginInterface {
  use StringTranslationTrait;

  /**
   * Vote builder.
   *
   * @var \Drupal\like_and_dislike\LikeDislikeVoteBuilder
   */
  protected $likeDislikeVoteBuilder;

  /**
   * Constructs a new BlockBase.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin
   *   instance.
   * @param string $plugin_id
   *   The plugin ID for the plugin instance.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\like_and_dislike\LikeDislikeVoteBuilder $like_dislike_vote_builder
   *   The vote builder.
   * @param \Drupal\Core\StringTranslation\TranslationInterface $string_translation
   *   The string translation service.
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, LikeDislikeVoteBuilder $like_dislike_vote_builder, TranslationInterface $string_translation) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->likeDislikeVoteBuilder = $like_dislike_vote_builder;
    $this->stringTranslation = $string_translation;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('like_and_dislike.vote_builder'),
      $container->get('string_translation')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    $build = [];

    $node = \Drupal::routeMatch()->getParameter('node');
    /* @var \Drupal\node\Entity\Node $node */
    if (!$node->get('field_drupal8_like_dislike_show')->isEmpty()
      && $node->get('field_drupal8_like_dislike_show')->value === '1'
    ) {
      $content = $this->likeDislikeVoteBuilder->build('node', $node->id());
      $likes = $content['icons']['#icons']['like']['count'];
      $dislikes = $content['icons']['#icons']['dislike']['count'];
      $total = $likes + $dislikes;
      if ($total != 0) {
        $content['icons']['#icons']['like']['percentage'] = round(($likes / $total) * 100) . '%';
        $content['icons']['#icons']['dislike']['percentage'] = round(($dislikes / $total) * 100) . '%';
      }
      else {
        $content['icons']['#icons']['like']['percentage'] = '';
        $content['icons']['#icons']['dislike']['percentage'] = '';
      }
      $build = $content['icons'];
      $build['#title'] = $this->t('Oceń artykuł');

      $build['#theme'] = 'drupal8_like_dislike';
    }

    // Cache settings.
    $build['#cache']['keys'][] = 'drupal8_like_dislike_block';
    $build['#cache'] = ['max-age' => 0];
    $build['#cache'] = ['disabled' => TRUE];

    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];

    return $build;
  }

}
