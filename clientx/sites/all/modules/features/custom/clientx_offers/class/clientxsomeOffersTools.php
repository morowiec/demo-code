<?php

/**
 * @file
 * Helper class with generic static methods which can be reused.
 */

/**
 * clientxSomeOffersTools File Doc Comment.
 *
 * Helper class with generic static methods which can be reused.
 */
class clientxSomeOffersTools {

  /**
   * Fetching first term id for given term name in a given vocabulary.
   *
   * @param string $term_name
   *   The taxonomy term name.
   * @param string $vocabulary_machine_name
   *   The taxonomy term vocabluary machine name.
   *
   * @return int|bool
   *   Taxonomy term ID or NULL.
   */
  public static function getTermIdByName($term_name, $vocabulary_machine_name) {
    $terms = taxonomy_get_term_by_name($term_name);
    if (count($terms) > 0) {
      foreach ($terms as $term) {
        if ($term->vocabulary_machine_name == $vocabulary_machine_name) {
          return $term->tid;
        }
      }
    }
    return NULL;
  }

  /**
   * Helper function for fetching active section from the end of url.
   *
   * Used for theming - active class for section which is currently used.
   *
   * @return array|bool
   *   Array with a components of the current Drupal path or FALSE.
   */
  public static function getActiveSectionFromUrl() {
    $args = arg();
    $last_url_arg = array_pop($args);
    if (!is_numeric($last_url_arg)) {
      $sub_args = explode('-', $last_url_arg);
      return reset($sub_args);
    }
    return FALSE;
  }

  /**
   * Helper function for checking if user is having provided role.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public static function userHasRole($role, $account = NULL) {
    if (!$account) {
      $account = $GLOBALS['user'];
    }

    if (is_numeric($role)) {
      $role = user_role_load($role);
    }
    else {
      $role = user_role_load_by_name($role);
    }

    if (!$role) {
      return FALSE;
    }

    return isset($account->roles[$role->rid]);
  }

  /**
   * Helper function for fetching Company ID from object.
   *
   * @param object $node
   *   A node object.
   *
   * @return int|bool
   *   Taxonomy term ID or FALSE.
   */
  public static function getCompanyIdFromObject($node) {
    if (isset($node->field_clientx_company_id[LANGUAGE_NONE][0]['target_id'])) {
      return $node->field_clientx_company_id[LANGUAGE_NONE][0]['target_id'];
    }
    return FALSE;
  }

  /**
   * Helper function for fetching Company term object from user.
   *
   * @param object $user
   *   The user object.
   *
   * @return object
   *   Taxonomy term.
   */
  public static function getCompanyFromUser($user) {
    $company_id = clientxSomeOffersTools::getCompanyIdFromObject($user);
    return taxonomy_term_load($company_id);
  }

  /**
   * Helper function for checking if deadline is permanent date.
   *
   * @param int $timestamp
   *   An integer containing the Unix timestamp being checked / compared.
   */
  public static function deadlineIsPermanent($timestamp) {
    if ($timestamp == clientxSomeOffers::DEADLINE_PERMANENT) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Helper function return markup for Brussels time suffix.
   *
   * @return string
   *   Brussels time suffix.
   */
  public static function brusselTimeSuffix() {
    $label = '(';
    $label .= t('CET time');
    $label .= ')';

    return theme(
      'html_tag',
      array(
        'element' => array(
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array('clientx-suffix'),
          ),
          '#value' => $label,
        ),
      )
    );
  }

  /**
   * Helper function returns markup for Permanent deadline.
   *
   * @return string
   *   Permanent deadline string.
   */
  public static function permanentDeadline() {
    return theme(
      'html_tag',
      array(
        'element' => array(
          '#tag' => 'span',
          '#value' => t('no deadline for application'),
        ),
      )
    );
  }

  /**
   * Helper function return markup for  link.
   *
   * In proper format (indicative or not).
   *
   * @param object $node
   *   A node object.
   *
   * @return string|bool
   *   An indicative date or FALSE.
   */
  public static function noticeOfCompetitionLink($node) {
    $notice_call = field_get_items('node', $node, 'field_clientx_noc_call');
    if ($notice_call) {
      $label = '- ';
      $label .= l(t('Read more'), $notice_call[0]['url'], array('attributes' => array('target' => '_blank')));

      return theme(
        'html_tag',
        array(
          'element' => array(
            '#tag' => 'span',
            '#attributes' => array(
              'class' => array('clientx-suffix'),
            ),
            '#value' => $label,
          ),
        )
      );
    }
    return FALSE;
  }

  /**
   * Helper function return Open for application date.
   *
   * In proper format (indicative or not).
   *
   * @param object $node
   *   A node object.
   *
   * @return string
   *   An indicative date or normal date.
   */
  public static function openForApplicationFormatter($node) {
    $open_for_aplication_season = field_get_items('node', $node, 'field_clientx_ofa_season');
    $deadline = field_get_items('node', $node, 'field_clientx_deadline');
    $open_for_aplication = field_get_items('node', $node, 'field_clientx_open_for_aplication');

    if ($open_for_aplication_season) {
      $season = i18n_taxonomy_term_name(taxonomy_term_load($open_for_aplication_season[0]['target_id']), i18n_langcode());

      return $season . ' ' . date('Y', $open_for_aplication[0]['value']) . clientxSomeOffersTools::indicativeSuffix();
    }
    elseif ($deadline) {
      return format_date($open_for_aplication[0]['value'], 'clientx_short_date_only');
    }
    else {
      return clientxSomeOffersTools::formatIndicativeDate($open_for_aplication[0]['value'], FALSE, TRUE);
    }
  }

  /**
   * Helper function return Deadline date.
   *
   * In proper format (indicative or not).
   *
   * @param int $timestamp
   *   Timestamp.
   *
   * @return string
   *   An indicative date or normal date.
   */
  public static function deadlineDateFormatter($timestamp) {
    if (clientxSomeOffersTools::deadlineIsPermanent($timestamp)) {
      return clientxSomeOffersTools::permanentDeadline();
    }
    else {
      return format_date($timestamp, 'short') . clientxSomeOffersTools::brusselTimeSuffix();
    }
  }

  /**
   * Helper function for compare two Company IDs.
   *
   * @param int $id1
   *   Numeric id.
   * @param int $id2
   *   Numeric id.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public static function checkIfCompanyIdsAreSame($id1, $id2) {
    if (empty($id1) || empty($id2)) {
      return FALSE;
    }
    if ($id1 == $id2) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Helper function for checking if user is Some offer Editor.
   *
   * @param object $user
   *   The user object.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public static function checkIfUserIsEditor($user) {
    // User has correct role.
    if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_clientx_EDITOR, $user)) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Helper function for checking if user is Some offer Editor.
   *
   * @param object $user
   *   The user object.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public static function checkIfUserIsSomeOfferEditor($user) {
    // User has Company ID.
    if (!isset($user->field_clientx_company_id[LANGUAGE_NONE][0]['target_id'])) {
      return FALSE;
    }
    // User has correct role.
    if (clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_clientx_OFFER_EDITOR, $user)
        || clientxSomeOffersTools::userHasRole(clientxSomeOffers::ROLE_clientx_OFFER_EXTENDED_EDITOR, $user)) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Helper function for checking if user is Some offer Editor.
   *
   * @param int $company_id
   *   Taxonomy term ID.
   * @param string $langcode
   *   The langcode for the translation.
   *
   * @return object|bool
   *   A node object or FALSE.
   */
  public static function getCompanyNodeFromId($company_id, $langcode) {
    if (!$company_id) {
      return FALSE;
    }

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', clientxSomeOffers::COMPANY_CT)
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition(clientxSomeOffers::COMPANY_ID_FIELD, 'target_id', $company_id);

    $result = $query->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $node = node_load($nids[0]);
      if ($node) {
        return $node;
      }
    }

    return FALSE;
  }

  /**
   * Helper function for checking if user is Some offer Editor.
   *
   * @param object $node
   *   A node object.
   *
   * @return object
   *   A node object.
   */
  public static function setCompanysNodeFromIds($node) {
    if (isset($node->field_clientx_company_id[LANGUAGE_NONE])) {
      $key = 0;
      foreach ($node->field_clientx_company_id[LANGUAGE_NONE] as $company_id) {
        $company = clientxSomeOffersTools::getCompanyNodeFromId($company_id['target_id'], 'en');
        $node->field_clientx_companys_agencies[LANGUAGE_NONE][$key]['target_id'] = $company->nid;
        $key++;
      }
    }

    return $node;
  }

  /**
   * Helper function.
   *
   * Build automatic title form taxonomy term for node.
   *
   * @param object $node
   *   A node object.
   * @param object $field_name
   *   Taxonomy title field name.
   *
   * @return object
   *   A node object.
   */
  public static function setAutomaticTitle($node, $field_name) {
    $automatic_title = field_get_items('node', $node, $field_name);

    $ap_titles = array();
    if ($node->type == clientxSomeOffers::COMP_CT) {
      $ap_titles = clientxSomeOffersTools::getTitlesFromRelatedSomePage($node);
    }

    // No title or wrong state.
    if (!isset($automatic_title[0]['target_id']) || !clientxSomeOffersTools::nodeIsTranslatable($node)) {
      return $node;
    }

    $term = taxonomy_term_load($automatic_title[0]['target_id']);

    $language_list = language_list();

    foreach ($language_list as $langcode => $language) {
      // Load translated title.
      $title = i18n_taxonomy_term_name($term, $langcode);
      if (isset($ap_titles[$langcode])) {
        $title .= $ap_titles[$langcode];
      }

      if (!isset($node->translations->data[$langcode]['entity_type'])) {
        $node = clientxSomeOffersTools::addTranslation($node, $langcode, $title);
      }
      $node->title_field[$langcode][0]['value'] = $title;
    }
    $title_en = i18n_taxonomy_term_name($term, 'en');
    if (isset($ap_titles['en'])) {
      $title_en .= $ap_titles['en'];
    }
    $node->title_field['en'][0]['value'] = $title_en;
    $node->title = $title_en;

    // Clear automatic title field value.
    $node->{$field_name} = [];
    return $node;
  }

  /**
   * Helper function.
   *
   * Add language data to node object.
   *
   * @param object $node
   *   A node object.
   *
   * @return array
   *   A string titles array.
   */
  public static function getTitlesFromRelatedSomePage($node) {
    $language_list = language_list();

    $some_page_titles = array();
    $related_some_pages = field_get_items('node', $node, 'field_clientx_related_some_page');
    foreach ($related_some_pages as $related_some_page) {
      $some_page = node_load($related_some_page['target_id']);
      foreach ($language_list as $langcode => $language) {
        if (isset($some_page_titles[$langcode]) && isset($some_page->title_field[$langcode][0]['safe_value'])) {
          $some_page_titles[$langcode] .= ' - ' . $some_page->title_field[$langcode][0]['safe_value'];
        }
        elseif (isset($some_page->title_field[$langcode][0]['safe_value'])) {
          $some_page_titles[$langcode] = ' - ' . $some_page->title_field[$langcode][0]['safe_value'];
        }
      }
    }
    return $some_page_titles;
  }

  /**
   * Helper function.
   *
   * Build automatic title form taxonomy term for node.
   *
   * @param object $node
   *   A node object.
   * @param string $langcode
   *   The langcode for the translation.
   * @param string $title
   *   Translation title.
   *
   * @return object
   *   A node object.
   */
  public static function addTranslation($node, $langcode, $title) {
    $node->title_field[$langcode][0]['value'] = $title;

    $handler = entity_translation_get_handler('node', $node);

    $translation = array(
      'translate' => 0,
      'status' => 1,
      'language' => $langcode,
      'source' => $node->language,
    );

    $handler->setTranslation($translation, $node);
    field_attach_update('node', $node);

    return $node;
  }

  /**
   * Helper function for checking node moderation state.
   *
   * @param object $node
   *   A node object.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public static function nodeIsTranslatable($node) {
    if ($node->workbench_moderation['current']->state == 'validated' || $node->workbench_moderation['current']->state == 'published') {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Helper function for checking node moderation state.
   *
   * @param object $node
   *   A node object.
   *
   * @return bool
   *   TRUE or FALSE.
   */
  public static function getNumberApplicationPhases($node) {
    $application_phases = field_get_items('node', $node, 'field_clientx_application_phases');
    if (isset($application_phases[0]['value']) && $application_phases[0]['value'] == 2) {
      return 2;
    }
    return 1;
  }

  /**
   * Helper function for formating timelines dates.
   *
   * @param array $date
   *   An array of field items keyed by delta if available, FALSE otherwise.
   * @param array $confirmed
   *   An array of field items keyed by delta if available, FALSE otherwise.
   * @param bool $time
   *   Flag - date need to be displeyd with time or not.
   *
   * @return string
   *   An formatted date.
   */
  public static function formatTimelineDate($date, $confirmed, $time = FALSE) {
    if (isset($confirmed[0]['value']) && $confirmed[0]['value'] == 1) {
      if ($time) {
        $value = format_date($date[0]['value'], 'short') . clientxSomeOffersTools::brusselTimeSuffix();
      }
      else {
        $value = format_date($date[0]['value'], 'clientx_short_date_only');
      }

      // Add end date if isset.
      if (isset($date[0]['value2']) && $date[0]['value'] != $date[0]['value2'] && $time) {
        $value .= ' - ';
        $value .= format_date($date[0]['value2'], 'short') . clientxSomeOffersTools::brusselTimeSuffix();
      }
      elseif (isset($date[0]['value2']) && $date[0]['value'] != $date[0]['value2']) {
        $value .= ' - ';
        $value .= format_date($date[0]['value2'], 'clientx_short_date_only');
      }
    }
    else {
      $value = clientxSomeOffersTools::formatIndicativeDate($date[0]['value']);

      // Add end date if isset.
      if (isset($date[0]['value2']) && $date[0]['value'] != $date[0]['value2']) {
        $value = clientxSomeOffersTools::formatIndicativeDate($date[0]['value'], TRUE, FALSE);
        $value .= ' / ';
        $value .= clientxSomeOffersTools::formatIndicativeDate($date[0]['value2']);
      }
    }

    return $value;
  }

  /**
   * Helper function for formating timelines dates.
   *
   * @param array $date
   *   An array of field items keyed by delta if available, FALSE otherwise.
   *
   * @return string
   *   An formatted date.
   */
  public static function formatTimelineMultiDate($date) {
    if (isset($date['value2']) && $date['value'] != $date['value2']) {
      // Date is confirmed.
      $value = format_date($date['value'], 'clientx_short_date_only');
      $value .= ' - ';
      $value .= format_date($date['value2'], 'clientx_short_date_only');
    }
    else {
      // Date is indicative.
      $value = clientxSomeOffersTools::formatIndicativeDate($date['value']);
    }

    return $value;
  }

  /**
   * Helper function for checking if user is Some offer Editor.
   *
   * @param int $timestamp
   *   An integer containing the Unix timestamp being formated.
   * @param bool $prefix
   *   A bool to add or not prefix.
   * @param bool $indicative
   *   A bool to add or not "indicative" suffix.
   *
   * @return string
   *   An indicative date.
   */
  public static function formatIndicativeDate($timestamp, $prefix = TRUE, $indicative = TRUE) {
    $month_names = array(
      1 => t('January'),
      2 => t('February'),
      3 => t('March'),
      4 => t('April'),
      5 => t('May'),
      6 => t('June'),
      7 => t('July'),
      8 => t('August'),
      9 => t('September'),
      10 => t('October'),
      11 => t('November'),
      12 => t('December'),
    );

    $date = '';

    if ($prefix) {
      switch (date('j', $timestamp)) {
        case 1:
          $date = t('beginning');
          $date .= ' ';
          break;

        case 15:
          $date = t('mid');
          $date .= ' ';
          break;

        case 28:
        case 29:
        case 30:
        case 31:
          $date = t('end');
          $date .= ' ';
          break;
      }
    }

    $date .= $month_names[date('n', $timestamp)];
    $date .= ' ';
    $date .= date('Y', $timestamp);

    if ($indicative) {
      $date .= clientxSomeOffersTools::indicativeSuffix();
    }

    return $date;
  }

  /**
   * Helper function for checking if user is Some offer Editor.
   *
   * @return string
   *   An indicative suffix text.
   */
  public static function indicativeSuffix() {
    $html = theme(
      'html_tag',
      array(
        'element' => array(
          '#tag' => 'span',
          '#attributes' => array(
            'class' => array('clientx-suffix'),
          ),
          '#value' => t('(indicative)'),
        ),
      )
    );
    return $html;
  }

}
