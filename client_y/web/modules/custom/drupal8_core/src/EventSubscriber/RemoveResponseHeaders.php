<?php

namespace Drupal\drupal8_core\EventSubscriber;

use Symfony\Component\EventDispatcher\EventSubscriberInterface;
use Symfony\Component\HttpKernel\Event\FilterResponseEvent;
use Symfony\Component\HttpKernel\KernelEvents;

/**
 * Class RemoveResponseHeaders.
 *
 * @package Drupal\drupal8_core\EventSubscriber
 */
class RemoveResponseHeaders implements EventSubscriberInterface {

  /**
   * {@inheritdoc}
   */
  public static function getSubscribedEvents() {
    $events[KernelEvents::RESPONSE][] = ['removeXgeneratorOptions', -10];
    return $events;
  }

  /**
   * X-Generator http header handling.
   *
   * @param \Symfony\Component\HttpKernel\Event\FilterResponseEvent $event
   *   Event parameter.
   */
  public function removeXgeneratorOptions(FilterResponseEvent $event) {
    $response = $event->getResponse();
    $response->headers->remove('X-Generator');
  }

}
