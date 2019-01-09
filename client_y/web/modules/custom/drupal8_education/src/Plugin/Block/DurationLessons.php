<?php

namespace Drupal\drupal8_education\Plugin\Block;

use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Block\BlockBase;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\Core\Entity\EntityDisplayRepositoryInterface;
use Drupal\node\NodeInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;

/**
 * Provides a 'Duration Lessons' Block.
 *
 * @package Drupal\drupal8_core
 *
 * @Block(
 *   id = "drupal8_duration_lessons",
 *   admin_label = @Translation("Drupal8 | Edukacja | Lekcja | Duration Lessons"),
 *   category = @Translation("Drupal8 v1.0"),
 * )
 */
class DurationLessons extends BlockBase implements ContainerFactoryPluginInterface {

  /**
   * The entity type manager.
   *
   * @var \Drupal\Core\Entity\EntityDisplayRepositoryInterface
   */
  protected $entityDisplayRepository;

  /**
   * The entity view builder interface.
   *
   * @var \Drupal\Core\Entity\EntityViewBuilderInterface
   */
  private $viewBuilder;

  /**
   * The node interface.
   *
   * @var \Drupal\node\NodeInterface
   */
  private $node;

  /**
   * Constructs a DurationLessons instance.
   *
   * @param array $configuration
   *   A configuration array containing information about the plugin instance.
   * @param string $plugin_id
   *   The plugin_id for the formatter.
   * @param mixed $plugin_definition
   *   The plugin implementation definition.
   * @param \Drupal\Core\Entity\EntityDisplayRepositoryInterface $entity_display_repository
   *   The entity display repository.
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_manager
   *   The entity type manager.
   *
   * @throws \Drupal\Component\Plugin\Exception\InvalidPluginDefinitionException
   */
  public function __construct(array $configuration, $plugin_id, $plugin_definition, EntityDisplayRepositoryInterface $entity_display_repository, EntityTypeManagerInterface $entity_manager) {
    parent::__construct($configuration, $plugin_id, $plugin_definition);
    $this->viewBuilder = $entity_manager->getViewBuilder('node');
    $this->node = \Drupal::routeMatch()->getParameter('node');
    $this->entityDisplayRepository = $entity_display_repository;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('entity_display.repository'),
      $container->get('entity.manager')
    );
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    if (!$this->node instanceof NodeInterface || $this->node->getType() != 'drupal8_education_lessons') {
      return [];
    }

    $build = [];
    $markup = [];

    $fieldsToRender = ['field_drupal8_duration'];
    $view_mode = 'default';

    $entityType = 'node';
    $display = entity_get_display($entityType, $this->node->getType(), $view_mode);

    foreach ($fieldsToRender as $field_name) {
      if (isset($this->node->{$field_name}) && $field = $this->node->{$field_name}) {
        $fieldRenderable = $this->viewBuilder->viewField($field, $display->getComponent($field_name));
        if (count($fieldRenderable) && !empty($fieldRenderable)) {
          $markup[] = \Drupal::service('renderer')
            ->renderRoot($fieldRenderable);
        }
      }
    }

    $build['#markup'] = implode("", $markup);

    $build['#cache']['keys'][] = 'drupal8_duration_lessons';
    // Block should be different for each different url.
    $build['#cache']['contexts'] = ['url.path'];

    return $build;
  }

}
