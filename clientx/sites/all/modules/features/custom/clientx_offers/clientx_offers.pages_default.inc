<?php

/**
 * @file
 * clientx_offers.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function clientx_offers_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_clientx-companys-and-agencies-default';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'clientx | Companys and Agencies | Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node: Company ID',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_clientx_company_id-node-taxonomy_term',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'clientx-companys-and-agencies-default',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '10fcf6ea-dd40-40f6-82f4-6f8b0389f96b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-99020cdd-2ed7-4589-b656-1fc6c0567c80';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '99020cdd-2ed7-4589-b656-1fc6c0567c80';
  $display->content['new-99020cdd-2ed7-4589-b656-1fc6c0567c80'] = $pane;
  $display->panels['middle'][0] = 'new-99020cdd-2ed7-4589-b656-1fc6c0567c80';
  $pane = new stdClass();
  $pane->pid = 'new-846aa3c5-2edc-48df-8462-46e46f565e32';
  $pane->panel = 'middle';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '846aa3c5-2edc-48df-8462-46e46f565e32';
  $display->content['new-846aa3c5-2edc-48df-8462-46e46f565e32'] = $pane;
  $display->panels['middle'][1] = 'new-846aa3c5-2edc-48df-8462-46e46f565e32';
  $pane = new stdClass();
  $pane->pid = 'new-f94ff729-6ed4-4836-b07c-b4c4634f236b';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'f94ff729-6ed4-4836-b07c-b4c4634f236b';
  $display->content['new-f94ff729-6ed4-4836-b07c-b4c4634f236b'] = $pane;
  $display->panels['middle'][2] = 'new-f94ff729-6ed4-4836-b07c-b4c4634f236b';
  $pane = new stdClass();
  $pane->pid = 'new-ba705cc9-2c4d-4572-917d-db5df4e513df';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_url';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ba705cc9-2c4d-4572-917d-db5df4e513df';
  $display->content['new-ba705cc9-2c4d-4572-917d-db5df4e513df'] = $pane;
  $display->panels['middle'][3] = 'new-ba705cc9-2c4d-4572-917d-db5df4e513df';
  $pane = new stdClass();
  $pane->pid = 'new-50fa6697-17df-4f68-98ff-924d2d70f2df';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_stages-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '50fa6697-17df-4f68-98ff-924d2d70f2df';
  $display->content['new-50fa6697-17df-4f68-98ff-924d2d70f2df'] = $pane;
  $display->panels['middle'][4] = 'new-50fa6697-17df-4f68-98ff-924d2d70f2df';
  $pane = new stdClass();
  $pane->pid = 'new-2e6537b3-5c7c-412f-abfe-ce207d13b8b8';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_related_offers-panel_pane_4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'relationship_entity_from_field:field_clientx_company_id-node-taxonomy_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '2e6537b3-5c7c-412f-abfe-ce207d13b8b8';
  $display->content['new-2e6537b3-5c7c-412f-abfe-ce207d13b8b8'] = $pane;
  $display->panels['middle'][5] = 'new-2e6537b3-5c7c-412f-abfe-ce207d13b8b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_clientx-companys-and-agencies-default'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_clientx-offers-some-page-short';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'clientx | Offers | Some page short',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node: Company ID',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_clientx_company_id-node-taxonomy_term',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'name' => 'clientx-offers-some-page-short',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '10fcf6ea-dd40-40f6-82f4-6f8b0389f96b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-32e3692b-73c0-465e-8a46-1139d7e7cd9d';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '32e3692b-73c0-465e-8a46-1139d7e7cd9d';
  $display->content['new-32e3692b-73c0-465e-8a46-1139d7e7cd9d'] = $pane;
  $display->panels['middle'][0] = 'new-32e3692b-73c0-465e-8a46-1139d7e7cd9d';
  $pane = new stdClass();
  $pane->pid = 'new-3c433e6e-9c9c-4333-8318-a57e797bda59';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_more_link';
  $pane->subtype = 'clientx_some_page_more_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3c433e6e-9c9c-4333-8318-a57e797bda59';
  $display->content['new-3c433e6e-9c9c-4333-8318-a57e797bda59'] = $pane;
  $display->panels['middle'][1] = 'new-3c433e6e-9c9c-4333-8318-a57e797bda59';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_clientx-offers-some-page-short'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_clientx-offers-user-company-agency';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'clientx | Offers | User | Company/Agency',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'node-clientx-offers',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'clientx-offers-user-company-agency',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_offers' => 'clientx_offers',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_company_agency_editor_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'clientx_compare_company_id_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0c8b8dee-3735-4a8d-9132-e28007ac50f7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-86338fde-c3bb-4edf-b25f-ed38e7b74f71';
  $pane->panel = 'middle';
  $pane->type = 'company_nav_bar';
  $pane->subtype = 'company_nav_bar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '86338fde-c3bb-4edf-b25f-ed38e7b74f71';
  $display->content['new-86338fde-c3bb-4edf-b25f-ed38e7b74f71'] = $pane;
  $display->panels['middle'][0] = 'new-86338fde-c3bb-4edf-b25f-ed38e7b74f71';
  $pane = new stdClass();
  $pane->pid = 'new-aeaf905b-a443-4f6d-8eac-bf2d3a25e059';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_reference_number';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'aeaf905b-a443-4f6d-8eac-bf2d3a25e059';
  $display->content['new-aeaf905b-a443-4f6d-8eac-bf2d3a25e059'] = $pane;
  $display->panels['middle'][1] = 'new-aeaf905b-a443-4f6d-8eac-bf2d3a25e059';
  $pane = new stdClass();
  $pane->pid = 'new-e0de32a0-e858-4b88-9246-85aabd674474';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e0de32a0-e858-4b88-9246-85aabd674474';
  $display->content['new-e0de32a0-e858-4b88-9246-85aabd674474'] = $pane;
  $display->panels['middle'][2] = 'new-e0de32a0-e858-4b88-9246-85aabd674474';
  $pane = new stdClass();
  $pane->pid = 'new-1bc3512a-3d5c-42aa-a49e-0bfdf8042c38';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
      'view_mode' => 'default',
      'links' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1bc3512a-3d5c-42aa-a49e-0bfdf8042c38';
  $display->content['new-1bc3512a-3d5c-42aa-a49e-0bfdf8042c38'] = $pane;
  $display->panels['middle'][3] = 'new-1bc3512a-3d5c-42aa-a49e-0bfdf8042c38';
  $pane = new stdClass();
  $pane->pid = 'new-96585593-2550-465e-afb6-dce6428f881d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '96585593-2550-465e-afb6-dce6428f881d';
  $display->content['new-96585593-2550-465e-afb6-dce6428f881d'] = $pane;
  $display->panels['middle'][4] = 'new-96585593-2550-465e-afb6-dce6428f881d';
  $pane = new stdClass();
  $pane->pid = 'new-e0b033e4-1648-4fc9-8c98-9fc10fb22d21';
  $pane->panel = 'middle';
  $pane->type = 'company_name_content';
  $pane->subtype = 'company_name_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'e0b033e4-1648-4fc9-8c98-9fc10fb22d21';
  $display->content['new-e0b033e4-1648-4fc9-8c98-9fc10fb22d21'] = $pane;
  $display->panels['middle'][5] = 'new-e0b033e4-1648-4fc9-8c98-9fc10fb22d21';
  $pane = new stdClass();
  $pane->pid = 'new-fd53d607-5ef9-45a0-bf8d-7ddd7bb1727f';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'fd53d607-5ef9-45a0-bf8d-7ddd7bb1727f';
  $display->content['new-fd53d607-5ef9-45a0-bf8d-7ddd7bb1727f'] = $pane;
  $display->panels['middle'][6] = 'new-fd53d607-5ef9-45a0-bf8d-7ddd7bb1727f';
  $pane = new stdClass();
  $pane->pid = 'new-89cece25-9693-4f44-ac14-2fc7da62732f';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_url';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'link_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '89cece25-9693-4f44-ac14-2fc7da62732f';
  $display->content['new-89cece25-9693-4f44-ac14-2fc7da62732f'] = $pane;
  $display->panels['middle'][7] = 'new-89cece25-9693-4f44-ac14-2fc7da62732f';
  $pane = new stdClass();
  $pane->pid = 'new-77a3be0a-986a-4a93-b07a-f9aa0fb3112a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_contact_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'email_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '77a3be0a-986a-4a93-b07a-f9aa0fb3112a';
  $display->content['new-77a3be0a-986a-4a93-b07a-f9aa0fb3112a'] = $pane;
  $display->panels['middle'][8] = 'new-77a3be0a-986a-4a93-b07a-f9aa0fb3112a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_clientx-offers-user-company-agency'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_clientx_offers_casting_301';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'clientx | Offers | CASTING redirection',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'some/offers/casting/%node:nid/description',
    'name' => 'clientx_offers_casting_301',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_content_manager_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        2 => array(
          'name' => 'clientx_administrator_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        3 => array(
          'name' => 'clientx_some_page_type_casting_access',
          'settings' => NULL,
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_clientx_offers_casting_301'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_clientx_offers_comp_301';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'clientx | Offers | Competition redirection',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'some/offers/comp/%node:nid/description',
    'name' => 'clientx_offers_comp_301',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_content_manager_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        2 => array(
          'name' => 'clientx_administrator_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        3 => array(
          'name' => 'clientx_some_page_type_comp_access',
          'settings' => NULL,
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_clientx_offers_comp_301'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_default';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'default',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:i18n-name';
  $display->uuid = 'e9739b25-88ef-4611-84a8-3445d7936910';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_default'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_clientx-offers-taxonomy-grade';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'clientx | Offers | Taxonomy | Grade',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'clientx-offers-taxonomy-grade',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'clientx_offers_grade' => 'clientx_offers_grade',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '63121eb6-909c-41c3-b416-97f5a950023f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-20509186-81be-4aa6-832f-8c7440557b4f';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_related_offers-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '20509186-81be-4aa6-832f-8c7440557b4f';
  $display->content['new-20509186-81be-4aa6-832f-8c7440557b4f'] = $pane;
  $display->panels['middle'][0] = 'new-20509186-81be-4aa6-832f-8c7440557b4f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_clientx-offers-taxonomy-grade'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_clientx-offers-taxonomy-location';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'clientx | Offers | Taxonomy | Location',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'clientx-offers-taxonomy-location',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6e5335c5-2757-4840-9a1a-b087a4c0ab64';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6c79e4cc-0f86-4f32-97af-c0fbbbb22849';
  $pane->panel = 'middle';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'taxonomy_term:description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6c79e4cc-0f86-4f32-97af-c0fbbbb22849';
  $display->content['new-6c79e4cc-0f86-4f32-97af-c0fbbbb22849'] = $pane;
  $display->panels['middle'][0] = 'new-6c79e4cc-0f86-4f32-97af-c0fbbbb22849';
  $pane = new stdClass();
  $pane->pid = 'new-bf829fe6-82a8-42af-80c5-02a1a111774a';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_related_offers-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'bf829fe6-82a8-42af-80c5-02a1a111774a';
  $display->content['new-bf829fe6-82a8-42af-80c5-02a1a111774a'] = $pane;
  $display->panels['middle'][1] = 'new-bf829fe6-82a8-42af-80c5-02a1a111774a';
  $pane = new stdClass();
  $pane->pid = 'new-48a1ff7a-5e4a-4180-95d0-ebc3dd61f4c2';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_related_offers-panel_pane_5';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '48a1ff7a-5e4a-4180-95d0-ebc3dd61f4c2';
  $display->content['new-48a1ff7a-5e4a-4180-95d0-ebc3dd61f4c2'] = $pane;
  $display->panels['middle'][2] = 'new-48a1ff7a-5e4a-4180-95d0-ebc3dd61f4c2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_clientx-offers-taxonomy-location'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_clientx-offers-taxonomy-reference-number';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'clientx | Offers | Taxonomy | Reference number',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'clientx-offers-taxonomy-reference-number',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'clientxcrs_ref_numbers' => 'clientxcrs_ref_numbers',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '63121eb6-909c-41c3-b416-97f5a950023f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a93d54f6-7b86-40f8-aaf7-99c7a2a2013f';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_reference_number-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a93d54f6-7b86-40f8-aaf7-99c7a2a2013f';
  $display->content['new-a93d54f6-7b86-40f8-aaf7-99c7a2a2013f'] = $pane;
  $display->panels['middle'][0] = 'new-a93d54f6-7b86-40f8-aaf7-99c7a2a2013f';
  $pane = new stdClass();
  $pane->pid = 'new-70fad676-f717-45e1-ae32-af272fcd3da0';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_reference_number-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '70fad676-f717-45e1-ae32-af272fcd3da0';
  $display->content['new-70fad676-f717-45e1-ae32-af272fcd3da0'] = $pane;
  $display->panels['middle'][1] = 'new-70fad676-f717-45e1-ae32-af272fcd3da0';
  $pane = new stdClass();
  $pane->pid = 'new-3366fe77-dbfd-45ea-9dcd-b4aff9bc63c0';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_reference_number-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3366fe77-dbfd-45ea-9dcd-b4aff9bc63c0';
  $display->content['new-3366fe77-dbfd-45ea-9dcd-b4aff9bc63c0'] = $pane;
  $display->panels['middle'][2] = 'new-3366fe77-dbfd-45ea-9dcd-b4aff9bc63c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_clientx-offers-taxonomy-reference-number'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_clientx-offers-taxonomy-type-of-contract';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'clientx | Offers | Taxonomy | Type of contract',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'clientx-offers-taxonomy-type-of-contract',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'clientx_offers_type_of_contract' => 'clientx_offers_type_of_contract',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f9859639-7231-4003-a7d8-0141f82a4b59';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-85dfd02e-7df7-4ef6-9a5b-d45d9c203961';
  $pane->panel = 'middle';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'taxonomy_term:description';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '85dfd02e-7df7-4ef6-9a5b-d45d9c203961';
  $display->content['new-85dfd02e-7df7-4ef6-9a5b-d45d9c203961'] = $pane;
  $display->panels['middle'][0] = 'new-85dfd02e-7df7-4ef6-9a5b-d45d9c203961';
  $pane = new stdClass();
  $pane->pid = 'new-8c429843-7e64-4d6c-b6df-dfd40da4b6e1';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_related_offers-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8c429843-7e64-4d6c-b6df-dfd40da4b6e1';
  $display->content['new-8c429843-7e64-4d6c-b6df-dfd40da4b6e1'] = $pane;
  $display->panels['middle'][1] = 'new-8c429843-7e64-4d6c-b6df-dfd40da4b6e1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_clientx-offers-taxonomy-type-of-contract'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function clientx_offers_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_some_page_comp';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Some page | Competition';
  $page->admin_description = '';
  $page->path = 'some/offers/%type/%nid/%state';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'clientx_some_page_type_access',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_entity_id:node_1',
          1 => 'argument_string_2',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 2,
      'identifier' => 'some_page_type',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'nid' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'state' => array(
      'id' => 1,
      'identifier' => 'state',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_some_page_comp_panel';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Testing back',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_testing_access',
          'settings' => array(),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'some',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%nid:title_field';
  $display->uuid = '1ad974df-8572-4366-b547-6df8ecefad04';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6fb9a8a0-8272-4b9a-84c5-5a961f66dcb3';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_comp_fields';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6fb9a8a0-8272-4b9a-84c5-5a961f66dcb3';
  $display->content['new-6fb9a8a0-8272-4b9a-84c5-5a961f66dcb3'] = $pane;
  $display->panels['middle'][0] = 'new-6fb9a8a0-8272-4b9a-84c5-5a961f66dcb3';
  $pane = new stdClass();
  $pane->pid = 'new-60b3e0f9-134a-4fa9-9617-63f63f9e3385';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_ref_number_term';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '60b3e0f9-134a-4fa9-9617-63f63f9e3385';
  $display->content['new-60b3e0f9-134a-4fa9-9617-63f63f9e3385'] = $pane;
  $display->panels['middle'][1] = 'new-60b3e0f9-134a-4fa9-9617-63f63f9e3385';
  $pane = new stdClass();
  $pane->pid = 'new-b942d231-45b7-4096-b855-28c879b54645';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'clientx_short_date_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b942d231-45b7-4096-b855-28c879b54645';
  $display->content['new-b942d231-45b7-4096-b855-28c879b54645'] = $pane;
  $display->panels['middle'][2] = 'new-b942d231-45b7-4096-b855-28c879b54645';
  $pane = new stdClass();
  $pane->pid = 'new-19cbe8b5-d0c1-4a32-b3f8-2500fbb90b68';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_open_for_aplication';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '19cbe8b5-d0c1-4a32-b3f8-2500fbb90b68';
  $display->content['new-19cbe8b5-d0c1-4a32-b3f8-2500fbb90b68'] = $pane;
  $display->panels['middle'][3] = 'new-19cbe8b5-d0c1-4a32-b3f8-2500fbb90b68';
  $pane = new stdClass();
  $pane->pid = 'new-f758dd95-907e-4f1c-816d-7182e0ac112e';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'f758dd95-907e-4f1c-816d-7182e0ac112e';
  $display->content['new-f758dd95-907e-4f1c-816d-7182e0ac112e'] = $pane;
  $display->panels['middle'][4] = 'new-f758dd95-907e-4f1c-816d-7182e0ac112e';
  $pane = new stdClass();
  $pane->pid = 'new-a90a7728-6885-4730-960b-3e526f6daba1';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a90a7728-6885-4730-960b-3e526f6daba1';
  $display->content['new-a90a7728-6885-4730-960b-3e526f6daba1'] = $pane;
  $display->panels['middle'][5] = 'new-a90a7728-6885-4730-960b-3e526f6daba1';
  $pane = new stdClass();
  $pane->pid = 'new-83ab08a2-9cae-49d6-9dd7-e95152f0fabf';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '83ab08a2-9cae-49d6-9dd7-e95152f0fabf';
  $display->content['new-83ab08a2-9cae-49d6-9dd7-e95152f0fabf'] = $pane;
  $display->panels['middle'][6] = 'new-83ab08a2-9cae-49d6-9dd7-e95152f0fabf';
  $pane = new stdClass();
  $pane->pid = 'new-a5f3dade-59e0-4cb7-bcf5-ebb1993ca450';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_companys_agencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'a5f3dade-59e0-4cb7-bcf5-ebb1993ca450';
  $display->content['new-a5f3dade-59e0-4cb7-bcf5-ebb1993ca450'] = $pane;
  $display->panels['middle'][7] = 'new-a5f3dade-59e0-4cb7-bcf5-ebb1993ca450';
  $pane = new stdClass();
  $pane->pid = 'new-307b1dcb-5f61-4f87-90eb-42e6acb97094';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '307b1dcb-5f61-4f87-90eb-42e6acb97094';
  $display->content['new-307b1dcb-5f61-4f87-90eb-42e6acb97094'] = $pane;
  $display->panels['middle'][8] = 'new-307b1dcb-5f61-4f87-90eb-42e6acb97094';
  $pane = new stdClass();
  $pane->pid = 'new-500f6e3e-00d5-4179-96c6-745424923c6c';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_sel_procedure_descrip',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => t('Selection procedure'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '500f6e3e-00d5-4179-96c6-745424923c6c';
  $display->content['new-500f6e3e-00d5-4179-96c6-745424923c6c'] = $pane;
  $display->panels['middle'][9] = 'new-500f6e3e-00d5-4179-96c6-745424923c6c';
  $pane = new stdClass();
  $pane->pid = 'new-d9647bef-7a88-44b0-aee8-b32fb66f76ab';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_bean_some_instructio',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => t('Application'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'd9647bef-7a88-44b0-aee8-b32fb66f76ab';
  $display->content['new-d9647bef-7a88-44b0-aee8-b32fb66f76ab'] = $pane;
  $display->panels['middle'][10] = 'new-d9647bef-7a88-44b0-aee8-b32fb66f76ab';
  $pane = new stdClass();
  $pane->pid = 'new-4c8c6ac1-a081-47b0-89b8-787033abdebe';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_application_link';
  $pane->subtype = 'clientx_some_application_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '4c8c6ac1-a081-47b0-89b8-787033abdebe';
  $display->content['new-4c8c6ac1-a081-47b0-89b8-787033abdebe'] = $pane;
  $display->panels['middle'][11] = 'new-4c8c6ac1-a081-47b0-89b8-787033abdebe';
  $pane = new stdClass();
  $pane->pid = 'new-01b405fc-8805-4fad-a65b-6a72939c2211';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--timeline-messa';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '01b405fc-8805-4fad-a65b-6a72939c2211';
  $display->content['new-01b405fc-8805-4fad-a65b-6a72939c2211'] = $pane;
  $display->panels['middle'][12] = 'new-01b405fc-8805-4fad-a65b-6a72939c2211';
  $pane = new stdClass();
  $pane->pid = 'new-49a6198f-0378-4283-95c3-bfe70ecfb886';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_selection_dates';
  $pane->subtype = 'clientx_some_page_selection_dates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '49a6198f-0378-4283-95c3-bfe70ecfb886';
  $display->content['new-49a6198f-0378-4283-95c3-bfe70ecfb886'] = $pane;
  $display->panels['middle'][13] = 'new-49a6198f-0378-4283-95c3-bfe70ecfb886';
  $pane = new stdClass();
  $pane->pid = 'new-a0729d19-3eae-47ed-8b5d-23c1a257b97c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = 'a0729d19-3eae-47ed-8b5d-23c1a257b97c';
  $display->content['new-a0729d19-3eae-47ed-8b5d-23c1a257b97c'] = $pane;
  $display->panels['middle'][14] = 'new-a0729d19-3eae-47ed-8b5d-23c1a257b97c';
  $pane = new stdClass();
  $pane->pid = 'new-45c1d9d3-df09-4824-aedc-87aba3cd304b';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_important_documents';
  $pane->subtype = 'clientx_some_important_documents';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '45c1d9d3-df09-4824-aedc-87aba3cd304b';
  $display->content['new-45c1d9d3-df09-4824-aedc-87aba3cd304b'] = $pane;
  $display->panels['middle'][15] = 'new-45c1d9d3-df09-4824-aedc-87aba3cd304b';
  $pane = new stdClass();
  $pane->pid = 'new-6d79d066-4d8c-442b-a828-926b655ba8e6';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_related_faqs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => t('Related FAQs'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = '6d79d066-4d8c-442b-a828-926b655ba8e6';
  $display->content['new-6d79d066-4d8c-442b-a828-926b655ba8e6'] = $pane;
  $display->panels['middle'][16] = 'new-6d79d066-4d8c-442b-a828-926b655ba8e6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_some_page_comp_panel_context_e42e38df-fc07-4b31-9f5d-0ba8bcff79d1';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Testing start',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_testing_access',
          'settings' => array(),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'description',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%nid:title_field';
  $display->uuid = 'd961928f-04ca-4726-a71b-31bb9aeb9150';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_comp_fields';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '03f4d736-b169-45bd-8477-f779793cbf43';
  $display->content['new-03f4d736-b169-45bd-8477-f779793cbf43'] = $pane;
  $display->panels['middle'][0] = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane = new stdClass();
  $pane->pid = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_ref_number_term';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $display->content['new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c'] = $pane;
  $display->panels['middle'][1] = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane = new stdClass();
  $pane->pid = 'new-c70ca3e6-cc21-4b9e-a3ad-64a8a29acd90';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'clientx_short_date_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c70ca3e6-cc21-4b9e-a3ad-64a8a29acd90';
  $display->content['new-c70ca3e6-cc21-4b9e-a3ad-64a8a29acd90'] = $pane;
  $display->panels['middle'][2] = 'new-c70ca3e6-cc21-4b9e-a3ad-64a8a29acd90';
  $pane = new stdClass();
  $pane->pid = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_open_for_aplication';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '496e411e-3343-4cc6-a218-546345bc0f6d';
  $display->content['new-496e411e-3343-4cc6-a218-546345bc0f6d'] = $pane;
  $display->panels['middle'][3] = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane = new stdClass();
  $pane->pid = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $display->content['new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099'] = $pane;
  $display->panels['middle'][4] = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane = new stdClass();
  $pane->pid = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $display->content['new-f7e465e7-ab8d-4628-858d-be12d24c06f7'] = $pane;
  $display->panels['middle'][5] = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane = new stdClass();
  $pane->pid = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $display->content['new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5'] = $pane;
  $display->panels['middle'][6] = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane = new stdClass();
  $pane->pid = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_companys_agencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $display->content['new-641ea12c-90ff-4be7-a923-d9a28cf3bffa'] = $pane;
  $display->panels['middle'][7] = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane = new stdClass();
  $pane->pid = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '33024abc-eba9-41e7-847a-00b55c70ac01';
  $display->content['new-33024abc-eba9-41e7-847a-00b55c70ac01'] = $pane;
  $display->panels['middle'][8] = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane = new stdClass();
  $pane->pid = 'new-d62b0e25-2bb2-4085-ba82-c171d55ac903';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_bean_profile_procedur',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bean-profile-and-procedure',
  );
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'd62b0e25-2bb2-4085-ba82-c171d55ac903';
  $display->content['new-d62b0e25-2bb2-4085-ba82-c171d55ac903'] = $pane;
  $display->panels['middle'][9] = 'new-d62b0e25-2bb2-4085-ba82-c171d55ac903';
  $pane = new stdClass();
  $pane->pid = 'new-3f0928d8-0735-4d81-aee6-c6ef6db03262';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_Testing_instruction',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '3f0928d8-0735-4d81-aee6-c6ef6db03262';
  $display->content['new-3f0928d8-0735-4d81-aee6-c6ef6db03262'] = $pane;
  $display->panels['middle'][10] = 'new-3f0928d8-0735-4d81-aee6-c6ef6db03262';
  $pane = new stdClass();
  $pane->pid = 'new-bdc02725-97be-49cb-818e-f654b315433c';
  $pane->panel = 'middle';
  $pane->type = 'clientx_Testing_maintenance';
  $pane->subtype = 'clientx_Testing_maintenance';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = 'bdc02725-97be-49cb-818e-f654b315433c';
  $display->content['new-bdc02725-97be-49cb-818e-f654b315433c'] = $pane;
  $display->panels['middle'][11] = 'new-bdc02725-97be-49cb-818e-f654b315433c';
  $pane = new stdClass();
  $pane->pid = 'new-2f93cd0c-927a-46b4-b52f-a911a03e78ed';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_Testing_link';
  $pane->subtype = 'clientx_some_page_Testing_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '2f93cd0c-927a-46b4-b52f-a911a03e78ed';
  $display->content['new-2f93cd0c-927a-46b4-b52f-a911a03e78ed'] = $pane;
  $display->panels['middle'][12] = 'new-2f93cd0c-927a-46b4-b52f-a911a03e78ed';
  $pane = new stdClass();
  $pane->pid = 'new-bf7d9ea2-806e-41bc-87c7-a4bfdfe3d413';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bypass_Testing';
  $pane->subtype = 'clientx_some_page_bypass_Testing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = 'bf7d9ea2-806e-41bc-87c7-a4bfdfe3d413';
  $display->content['new-bf7d9ea2-806e-41bc-87c7-a4bfdfe3d413'] = $pane;
  $display->panels['middle'][13] = 'new-bf7d9ea2-806e-41bc-87c7-a4bfdfe3d413';
  $pane = new stdClass();
  $pane->pid = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = '32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $display->content['new-32bf6aaa-360f-4f2c-923f-501cc362ec4a'] = $pane;
  $display->panels['middle'][14] = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane = new stdClass();
  $pane->pid = 'new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_important_documents';
  $pane->subtype = 'clientx_some_important_documents';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $display->content['new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09'] = $pane;
  $display->panels['middle'][15] = 'new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $pane = new stdClass();
  $pane->pid = 'new-4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $pane->panel = 'middle';
  $pane->type = 'clientx_comp_news';
  $pane->subtype = 'clientx_comp_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = '4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $display->content['new-4493de84-eb30-4122-88c2-dbb479e4e4a0'] = $pane;
  $display->panels['middle'][16] = 'new-4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $pane = new stdClass();
  $pane->pid = 'new-bacb8600-0029-44d6-bebe-5a5a2fac53c8';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_related_faqs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => t('Related FAQs'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 17;
  $pane->locks = array();
  $pane->uuid = 'bacb8600-0029-44d6-bebe-5a5a2fac53c8';
  $display->content['new-bacb8600-0029-44d6-bebe-5a5a2fac53c8'] = $pane;
  $display->panels['middle'][17] = 'new-bacb8600-0029-44d6-bebe-5a5a2fac53c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_some_page_comp_panel_context_a9a1723c-3c2d-4f4e-a6a5-b38183850d5c';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'right_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%nid:title_field';
  $display->uuid = 'e204987e-dcb1-4c19-a422-a373cca1b7ca';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9b61fd55-b8da-4acd-830c-6bfa27971e56';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_comp_fields';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'default',
      'links' => 1,
      'use_content_language' => 1,
      'link' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9b61fd55-b8da-4acd-830c-6bfa27971e56';
  $display->content['new-9b61fd55-b8da-4acd-830c-6bfa27971e56'] = $pane;
  $display->panels['middle'][0] = 'new-9b61fd55-b8da-4acd-830c-6bfa27971e56';
  $pane = new stdClass();
  $pane->pid = 'new-b1626f6d-5357-4b80-9658-c21080c8efec';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_ref_number_term';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b1626f6d-5357-4b80-9658-c21080c8efec';
  $display->content['new-b1626f6d-5357-4b80-9658-c21080c8efec'] = $pane;
  $display->panels['middle'][1] = 'new-b1626f6d-5357-4b80-9658-c21080c8efec';
  $pane = new stdClass();
  $pane->pid = 'new-40bb85d0-6850-40b3-b54c-e4c9abee4c5f';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'clientx_short_date_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '40bb85d0-6850-40b3-b54c-e4c9abee4c5f';
  $display->content['new-40bb85d0-6850-40b3-b54c-e4c9abee4c5f'] = $pane;
  $display->panels['middle'][2] = 'new-40bb85d0-6850-40b3-b54c-e4c9abee4c5f';
  $pane = new stdClass();
  $pane->pid = 'new-83e53d41-ce9b-44ac-b475-c9d6ea058f23';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_open_for_aplication';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '83e53d41-ce9b-44ac-b475-c9d6ea058f23';
  $display->content['new-83e53d41-ce9b-44ac-b475-c9d6ea058f23'] = $pane;
  $display->panels['middle'][3] = 'new-83e53d41-ce9b-44ac-b475-c9d6ea058f23';
  $pane = new stdClass();
  $pane->pid = 'new-9e7c82cd-95f9-4863-9612-652136c764d9';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9e7c82cd-95f9-4863-9612-652136c764d9';
  $display->content['new-9e7c82cd-95f9-4863-9612-652136c764d9'] = $pane;
  $display->panels['middle'][4] = 'new-9e7c82cd-95f9-4863-9612-652136c764d9';
  $pane = new stdClass();
  $pane->pid = 'new-07991afa-479f-4020-9ea8-22eea66f3125';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '07991afa-479f-4020-9ea8-22eea66f3125';
  $display->content['new-07991afa-479f-4020-9ea8-22eea66f3125'] = $pane;
  $display->panels['middle'][5] = 'new-07991afa-479f-4020-9ea8-22eea66f3125';
  $pane = new stdClass();
  $pane->pid = 'new-d91d75f6-2527-4354-b190-1a4167399075';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'd91d75f6-2527-4354-b190-1a4167399075';
  $display->content['new-d91d75f6-2527-4354-b190-1a4167399075'] = $pane;
  $display->panels['middle'][6] = 'new-d91d75f6-2527-4354-b190-1a4167399075';
  $pane = new stdClass();
  $pane->pid = 'new-ee0a6393-a2bc-4af6-b4e6-6314a6ae7b69';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_companys_agencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'ee0a6393-a2bc-4af6-b4e6-6314a6ae7b69';
  $display->content['new-ee0a6393-a2bc-4af6-b4e6-6314a6ae7b69'] = $pane;
  $display->panels['middle'][7] = 'new-ee0a6393-a2bc-4af6-b4e6-6314a6ae7b69';
  $pane = new stdClass();
  $pane->pid = 'new-0445d363-6496-4810-ab66-94f8fcba83c0';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '0445d363-6496-4810-ab66-94f8fcba83c0';
  $display->content['new-0445d363-6496-4810-ab66-94f8fcba83c0'] = $pane;
  $display->panels['middle'][8] = 'new-0445d363-6496-4810-ab66-94f8fcba83c0';
  $pane = new stdClass();
  $pane->pid = 'new-599232f3-5a3d-4879-8f21-3c8631dbae8b';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_bean_profile_procedur',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '599232f3-5a3d-4879-8f21-3c8631dbae8b';
  $display->content['new-599232f3-5a3d-4879-8f21-3c8631dbae8b'] = $pane;
  $display->panels['middle'][9] = 'new-599232f3-5a3d-4879-8f21-3c8631dbae8b';
  $pane = new stdClass();
  $pane->pid = 'new-a26fc4df-8bc9-4863-9640-5f27fa70ef52';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_sel_procedure_descrip',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => t('Selection procedure'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'a26fc4df-8bc9-4863-9640-5f27fa70ef52';
  $display->content['new-a26fc4df-8bc9-4863-9640-5f27fa70ef52'] = $pane;
  $display->panels['middle'][10] = 'new-a26fc4df-8bc9-4863-9640-5f27fa70ef52';
  $pane = new stdClass();
  $pane->pid = 'new-ea88a5c4-78ed-40a1-a10f-027705e52709';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_bean_some_instructio',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => t('Application'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = 'ea88a5c4-78ed-40a1-a10f-027705e52709';
  $display->content['new-ea88a5c4-78ed-40a1-a10f-027705e52709'] = $pane;
  $display->panels['middle'][11] = 'new-ea88a5c4-78ed-40a1-a10f-027705e52709';
  $pane = new stdClass();
  $pane->pid = 'new-d96b27e1-4fb3-4b43-a323-4b368a00c5fa';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_application_link';
  $pane->subtype = 'clientx_some_application_link';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = 'd96b27e1-4fb3-4b43-a323-4b368a00c5fa';
  $display->content['new-d96b27e1-4fb3-4b43-a323-4b368a00c5fa'] = $pane;
  $display->panels['middle'][12] = 'new-d96b27e1-4fb3-4b43-a323-4b368a00c5fa';
  $pane = new stdClass();
  $pane->pid = 'new-2208c84e-1381-492e-9c1c-29dadd957757';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--timeline-messa';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '2208c84e-1381-492e-9c1c-29dadd957757';
  $display->content['new-2208c84e-1381-492e-9c1c-29dadd957757'] = $pane;
  $display->panels['middle'][13] = 'new-2208c84e-1381-492e-9c1c-29dadd957757';
  $pane = new stdClass();
  $pane->pid = 'new-d0be9dc8-ce31-4460-bc94-02ffb746c1e7';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_selection_dates';
  $pane->subtype = 'clientx_some_page_selection_dates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = 'd0be9dc8-ce31-4460-bc94-02ffb746c1e7';
  $display->content['new-d0be9dc8-ce31-4460-bc94-02ffb746c1e7'] = $pane;
  $display->panels['middle'][14] = 'new-d0be9dc8-ce31-4460-bc94-02ffb746c1e7';
  $pane = new stdClass();
  $pane->pid = 'new-6f7e7658-ad8e-4352-946a-3f71252d1c19';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '6f7e7658-ad8e-4352-946a-3f71252d1c19';
  $display->content['new-6f7e7658-ad8e-4352-946a-3f71252d1c19'] = $pane;
  $display->panels['middle'][15] = 'new-6f7e7658-ad8e-4352-946a-3f71252d1c19';
  $pane = new stdClass();
  $pane->pid = 'new-14940178-3e68-4940-b459-c55d3c3119ec';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_important_documents';
  $pane->subtype = 'clientx_some_important_documents';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = '14940178-3e68-4940-b459-c55d3c3119ec';
  $display->content['new-14940178-3e68-4940-b459-c55d3c3119ec'] = $pane;
  $display->panels['middle'][16] = 'new-14940178-3e68-4940-b459-c55d3c3119ec';
  $pane = new stdClass();
  $pane->pid = 'new-09ed8ed4-8fd3-421f-8182-ab237908c8ea';
  $pane->panel = 'middle';
  $pane->type = 'clientx_comp_news';
  $pane->subtype = 'clientx_comp_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 17;
  $pane->locks = array();
  $pane->uuid = '09ed8ed4-8fd3-421f-8182-ab237908c8ea';
  $display->content['new-09ed8ed4-8fd3-421f-8182-ab237908c8ea'] = $pane;
  $display->panels['middle'][17] = 'new-09ed8ed4-8fd3-421f-8182-ab237908c8ea';
  $pane = new stdClass();
  $pane->pid = 'new-0d7ddca5-ef37-436d-a9d9-34be98a6bdb0';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_related_faqs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => t('Related FAQs'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 18;
  $pane->locks = array();
  $pane->uuid = '0d7ddca5-ef37-436d-a9d9-34be98a6bdb0';
  $display->content['new-0d7ddca5-ef37-436d-a9d9-34be98a6bdb0'] = $pane;
  $display->panels['middle'][18] = 'new-0d7ddca5-ef37-436d-a9d9-34be98a6bdb0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page-clientx_some_page_comp_Testing_back_after_deadline';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'http_response';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Testing back after deadline',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'some/offers/comp/%nid:nid/description',
    'name' => 'Testing_back_after_deadline',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_ongoing_access',
          'settings' => array(),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'some',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_some_page_comp_upcoming';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Upcoming',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'upcoming',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_upcoming_access',
          'settings' => array(),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'clientx_user_acceptance_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        3 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'description',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%nid:title_field';
  $display->uuid = 'd961928f-04ca-4726-a71b-31bb9aeb9150';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_comp_fields';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '03f4d736-b169-45bd-8477-f779793cbf43';
  $display->content['new-03f4d736-b169-45bd-8477-f779793cbf43'] = $pane;
  $display->panels['middle'][0] = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane = new stdClass();
  $pane->pid = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_ref_number_term';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $display->content['new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c'] = $pane;
  $display->panels['middle'][1] = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane = new stdClass();
  $pane->pid = 'new-4b33ac3e-faa2-41d2-9980-792308623567';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'clientx_short_date_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4b33ac3e-faa2-41d2-9980-792308623567';
  $display->content['new-4b33ac3e-faa2-41d2-9980-792308623567'] = $pane;
  $display->panels['middle'][2] = 'new-4b33ac3e-faa2-41d2-9980-792308623567';
  $pane = new stdClass();
  $pane->pid = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_open_for_aplication';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '496e411e-3343-4cc6-a218-546345bc0f6d';
  $display->content['new-496e411e-3343-4cc6-a218-546345bc0f6d'] = $pane;
  $display->panels['middle'][3] = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane = new stdClass();
  $pane->pid = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $display->content['new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099'] = $pane;
  $display->panels['middle'][4] = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane = new stdClass();
  $pane->pid = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $display->content['new-f7e465e7-ab8d-4628-858d-be12d24c06f7'] = $pane;
  $display->panels['middle'][5] = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane = new stdClass();
  $pane->pid = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $display->content['new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5'] = $pane;
  $display->panels['middle'][6] = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane = new stdClass();
  $pane->pid = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_companys_agencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $display->content['new-641ea12c-90ff-4be7-a923-d9a28cf3bffa'] = $pane;
  $display->panels['middle'][7] = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane = new stdClass();
  $pane->pid = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '33024abc-eba9-41e7-847a-00b55c70ac01';
  $display->content['new-33024abc-eba9-41e7-847a-00b55c70ac01'] = $pane;
  $display->panels['middle'][8] = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane = new stdClass();
  $pane->pid = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $display->content['new-32bf6aaa-360f-4f2c-923f-501cc362ec4a'] = $pane;
  $display->panels['middle'][9] = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane = new stdClass();
  $pane->pid = 'new-4a5a9e4d-7db7-4fbb-ae52-118d8fd3dd06';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--timeline-messa';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '4a5a9e4d-7db7-4fbb-ae52-118d8fd3dd06';
  $display->content['new-4a5a9e4d-7db7-4fbb-ae52-118d8fd3dd06'] = $pane;
  $display->panels['middle'][10] = 'new-4a5a9e4d-7db7-4fbb-ae52-118d8fd3dd06';
  $pane = new stdClass();
  $pane->pid = 'new-3e917f48-4af9-4e85-9608-dbfef35b1f7b';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_selection_dates';
  $pane->subtype = 'clientx_some_page_selection_dates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '3e917f48-4af9-4e85-9608-dbfef35b1f7b';
  $display->content['new-3e917f48-4af9-4e85-9608-dbfef35b1f7b'] = $pane;
  $display->panels['middle'][11] = 'new-3e917f48-4af9-4e85-9608-dbfef35b1f7b';
  $pane = new stdClass();
  $pane->pid = 'new-491d4d80-b2f7-4f0b-bdfe-820b462aa660';
  $pane->panel = 'middle';
  $pane->type = 'clientx_comp_news';
  $pane->subtype = 'clientx_comp_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '491d4d80-b2f7-4f0b-bdfe-820b462aa660';
  $display->content['new-491d4d80-b2f7-4f0b-bdfe-820b462aa660'] = $pane;
  $display->panels['middle'][12] = 'new-491d4d80-b2f7-4f0b-bdfe-820b462aa660';
  $pane = new stdClass();
  $pane->pid = 'new-f051d74c-8853-416d-b5c2-c829029f1139';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_related_faqs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => t('Related FAQs'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = 'f051d74c-8853-416d-b5c2-c829029f1139';
  $display->content['new-f051d74c-8853-416d-b5c2-c829029f1139'] = $pane;
  $display->panels['middle'][13] = 'new-f051d74c-8853-416d-b5c2-c829029f1139';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_some_page_comp_ongoing';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Ongoing',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'ongoing',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_ongoing_access',
          'settings' => array(),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'description',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%nid:title_field';
  $display->uuid = 'd961928f-04ca-4726-a71b-31bb9aeb9150';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_comp_fields';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '03f4d736-b169-45bd-8477-f779793cbf43';
  $display->content['new-03f4d736-b169-45bd-8477-f779793cbf43'] = $pane;
  $display->panels['middle'][0] = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane = new stdClass();
  $pane->pid = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_ref_number_term';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $display->content['new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c'] = $pane;
  $display->panels['middle'][1] = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane = new stdClass();
  $pane->pid = 'new-e74c372c-9fb7-49da-acd0-8d12c80a53e4';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'clientx_short_date_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e74c372c-9fb7-49da-acd0-8d12c80a53e4';
  $display->content['new-e74c372c-9fb7-49da-acd0-8d12c80a53e4'] = $pane;
  $display->panels['middle'][2] = 'new-e74c372c-9fb7-49da-acd0-8d12c80a53e4';
  $pane = new stdClass();
  $pane->pid = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_open_for_aplication';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '496e411e-3343-4cc6-a218-546345bc0f6d';
  $display->content['new-496e411e-3343-4cc6-a218-546345bc0f6d'] = $pane;
  $display->panels['middle'][3] = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane = new stdClass();
  $pane->pid = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $display->content['new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099'] = $pane;
  $display->panels['middle'][4] = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane = new stdClass();
  $pane->pid = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $display->content['new-f7e465e7-ab8d-4628-858d-be12d24c06f7'] = $pane;
  $display->panels['middle'][5] = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane = new stdClass();
  $pane->pid = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $display->content['new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5'] = $pane;
  $display->panels['middle'][6] = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane = new stdClass();
  $pane->pid = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_companys_agencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $display->content['new-641ea12c-90ff-4be7-a923-d9a28cf3bffa'] = $pane;
  $display->panels['middle'][7] = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane = new stdClass();
  $pane->pid = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '33024abc-eba9-41e7-847a-00b55c70ac01';
  $display->content['new-33024abc-eba9-41e7-847a-00b55c70ac01'] = $pane;
  $display->panels['middle'][8] = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane = new stdClass();
  $pane->pid = 'new-ffef76f3-f1c1-41ad-b0f2-c7e780a8d8cd';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_bean_tokens';
  $pane->subtype = 'clientx_some_page_bean_tokens';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'field' => 'field_clientx_sel_procedure_descrip',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 1,
    'override_title_text' => t('Selection procedure'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'ffef76f3-f1c1-41ad-b0f2-c7e780a8d8cd';
  $display->content['new-ffef76f3-f1c1-41ad-b0f2-c7e780a8d8cd'] = $pane;
  $display->panels['middle'][9] = 'new-ffef76f3-f1c1-41ad-b0f2-c7e780a8d8cd';
  $pane = new stdClass();
  $pane->pid = 'new-5d4e5e06-753d-48aa-b883-8711b21f521b';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--timeline-messa';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '5d4e5e06-753d-48aa-b883-8711b21f521b';
  $display->content['new-5d4e5e06-753d-48aa-b883-8711b21f521b'] = $pane;
  $display->panels['middle'][10] = 'new-5d4e5e06-753d-48aa-b883-8711b21f521b';
  $pane = new stdClass();
  $pane->pid = 'new-f737d2bf-86fc-4b65-944b-9be9b8c2cddd';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_selection_dates';
  $pane->subtype = 'clientx_some_page_selection_dates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = 'f737d2bf-86fc-4b65-944b-9be9b8c2cddd';
  $display->content['new-f737d2bf-86fc-4b65-944b-9be9b8c2cddd'] = $pane;
  $display->panels['middle'][11] = 'new-f737d2bf-86fc-4b65-944b-9be9b8c2cddd';
  $pane = new stdClass();
  $pane->pid = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $display->content['new-32bf6aaa-360f-4f2c-923f-501cc362ec4a'] = $pane;
  $display->panels['middle'][12] = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane = new stdClass();
  $pane->pid = 'new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_important_documents';
  $pane->subtype = 'clientx_some_important_documents';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $display->content['new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09'] = $pane;
  $display->panels['middle'][13] = 'new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $pane = new stdClass();
  $pane->pid = 'new-4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $pane->panel = 'middle';
  $pane->type = 'clientx_comp_news';
  $pane->subtype = 'clientx_comp_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = '4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $display->content['new-4493de84-eb30-4122-88c2-dbb479e4e4a0'] = $pane;
  $display->panels['middle'][14] = 'new-4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $pane = new stdClass();
  $pane->pid = 'new-67718b4e-2d86-4c46-83d5-f40da71f95bd';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_related_faqs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => t('Related FAQs'),
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '67718b4e-2d86-4c46-83d5-f40da71f95bd';
  $display->content['new-67718b4e-2d86-4c46-83d5-f40da71f95bd'] = $pane;
  $display->panels['middle'][15] = 'new-67718b4e-2d86-4c46-83d5-f40da71f95bd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page-clientx_some_page_comp_upcoming_Testing_back';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'http_response';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Upcoming - Testing back',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'some/offers/comp/%nid:nid/description',
    'name' => 'upcoming_Testing_back',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_upcoming_access',
          'settings' => NULL,
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'clientx_user_acceptance_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        3 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'some',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page-clientx_some_page_comp_unpublished';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'http_response';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Unpublished',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'aaa-opportunities',
    'name' => 'unpublished',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_status',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'clientx_user_acceptance_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_some_page_comp_closed';
  $handler->task = 'page';
  $handler->subtask = 'clientx_some_page_comp';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Closed',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'closed',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_some_page' => 'clientx_some_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_some_page_closed_access',
          'settings' => array(),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'description',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%nid:title_field';
  $display->uuid = 'd961928f-04ca-4726-a71b-31bb9aeb9150';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_comp_fields';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '03f4d736-b169-45bd-8477-f779793cbf43';
  $display->content['new-03f4d736-b169-45bd-8477-f779793cbf43'] = $pane;
  $display->panels['middle'][0] = 'new-03f4d736-b169-45bd-8477-f779793cbf43';
  $pane = new stdClass();
  $pane->pid = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_ref_number_term';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $display->content['new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c'] = $pane;
  $display->panels['middle'][1] = 'new-9cb8f0d6-ce66-4c53-913f-b9cb23422a0c';
  $pane = new stdClass();
  $pane->pid = 'new-e74c372c-9fb7-49da-acd0-8d12c80a53e4';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_publication_date';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'clientx_short_date_only',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e74c372c-9fb7-49da-acd0-8d12c80a53e4';
  $display->content['new-e74c372c-9fb7-49da-acd0-8d12c80a53e4'] = $pane;
  $display->panels['middle'][2] = 'new-e74c372c-9fb7-49da-acd0-8d12c80a53e4';
  $pane = new stdClass();
  $pane->pid = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_open_for_aplication';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '496e411e-3343-4cc6-a218-546345bc0f6d';
  $display->content['new-496e411e-3343-4cc6-a218-546345bc0f6d'] = $pane;
  $display->panels['middle'][3] = 'new-496e411e-3343-4cc6-a218-546345bc0f6d';
  $pane = new stdClass();
  $pane->pid = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_deadline';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'date_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'format_type' => 'short',
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_to' => '',
      'fromto' => 'both',
      'show_remaining_days' => 0,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $display->content['new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099'] = $pane;
  $display->panels['middle'][4] = 'new-3b6d4c4d-b3c1-49af-ba6e-f0d2f5517099';
  $pane = new stdClass();
  $pane->pid = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_locations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $display->content['new-f7e465e7-ab8d-4628-858d-be12d24c06f7'] = $pane;
  $display->panels['middle'][5] = 'new-f7e465e7-ab8d-4628-858d-be12d24c06f7';
  $pane = new stdClass();
  $pane->pid = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_grade';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $display->content['new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5'] = $pane;
  $display->panels['middle'][6] = 'new-c8faddb4-5a6c-4edb-b5e9-efb051abc4f5';
  $pane = new stdClass();
  $pane->pid = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_companys_agencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $display->content['new-641ea12c-90ff-4be7-a923-d9a28cf3bffa'] = $pane;
  $display->panels['middle'][7] = 'new-641ea12c-90ff-4be7-a923-d9a28cf3bffa';
  $pane = new stdClass();
  $pane->pid = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_type_of_contract';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '33024abc-eba9-41e7-847a-00b55c70ac01';
  $display->content['new-33024abc-eba9-41e7-847a-00b55c70ac01'] = $pane;
  $display->panels['middle'][8] = 'new-33024abc-eba9-41e7-847a-00b55c70ac01';
  $pane = new stdClass();
  $pane->pid = 'new-5d4e5e06-753d-48aa-b883-8711b21f521b';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--timeline-messa';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '5d4e5e06-753d-48aa-b883-8711b21f521b';
  $display->content['new-5d4e5e06-753d-48aa-b883-8711b21f521b'] = $pane;
  $display->panels['middle'][9] = 'new-5d4e5e06-753d-48aa-b883-8711b21f521b';
  $pane = new stdClass();
  $pane->pid = 'new-f737d2bf-86fc-4b65-944b-9be9b8c2cddd';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_page_selection_dates';
  $pane->subtype = 'clientx_some_page_selection_dates';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'f737d2bf-86fc-4b65-944b-9be9b8c2cddd';
  $display->content['new-f737d2bf-86fc-4b65-944b-9be9b8c2cddd'] = $pane;
  $display->panels['middle'][10] = 'new-f737d2bf-86fc-4b65-944b-9be9b8c2cddd';
  $pane = new stdClass();
  $pane->pid = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $display->content['new-32bf6aaa-360f-4f2c-923f-501cc362ec4a'] = $pane;
  $display->panels['middle'][11] = 'new-32bf6aaa-360f-4f2c-923f-501cc362ec4a';
  $pane = new stdClass();
  $pane->pid = 'new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $pane->panel = 'middle';
  $pane->type = 'clientx_some_important_documents';
  $pane->subtype = 'clientx_some_important_documents';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $display->content['new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09'] = $pane;
  $display->panels['middle'][12] = 'new-9db77ddd-7ed3-4834-b175-b7ac0dbf2d09';
  $pane = new stdClass();
  $pane->pid = 'new-4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $pane->panel = 'middle';
  $pane->type = 'clientx_comp_news';
  $pane->subtype = 'clientx_comp_news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $display->content['new-4493de84-eb30-4122-88c2-dbb479e4e4a0'] = $pane;
  $display->panels['middle'][13] = 'new-4493de84-eb30-4122-88c2-dbb479e4e4a0';
  $pane = new stdClass();
  $pane->pid = 'new-67718b4e-2d86-4c46-83d5-f40da71f95bd';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_clientx_related_faqs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Related FAQs',
    'override_title_heading' => 'h3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = '67718b4e-2d86-4c46-83d5-f40da71f95bd';
  $display->content['new-67718b4e-2d86-4c46-83d5-f40da71f95bd'] = $pane;
  $display->panels['middle'][14] = 'new-67718b4e-2d86-4c46-83d5-f40da71f95bd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_some_page_comp'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_content_add';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Content | Add';
  $page->admin_description = '';
  $page->path = 'some/offers/node/add/%node_type';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node_type' => array(
      'id' => 1,
      'identifier' => 'Node add form: node type',
      'name' => 'node_add',
      'settings' => array(),
      'keyword' => 'node_type',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_content_add_panel_context_da6b2831-c9ae-45ab-8c62-7745794ec854';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_content_add';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User | Company/Agency',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node add form',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'clientx_offers',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'clientx_company_agency_editor_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '210',
        'width_type' => 'px',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_sidebar',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_sidebar' => array(
        'type' => 'region',
        'title' => 'Left sidebar',
        'width' => '180',
        'width_type' => 'px',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'left_sidebar' => NULL,
    ),
    'left_sidebar' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Create Some offer';
  $display->uuid = '74526ce2-4142-44d6-b5be-19f7347013c6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-66871321-69e4-4a40-a410-bad983c958ca';
  $pane->panel = 'center';
  $pane->type = 'offer_form';
  $pane->subtype = 'offer_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'context_node_add_form_1',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '66871321-69e4-4a40-a410-bad983c958ca';
  $display->content['new-66871321-69e4-4a40-a410-bad983c958ca'] = $pane;
  $display->panels['center'][0] = 'new-66871321-69e4-4a40-a410-bad983c958ca';
  $pane = new stdClass();
  $pane->pid = 'new-696f4530-16f2-4725-ae45-d8e9be6821f5';
  $pane->panel = 'left_sidebar';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-aaa-offer-user-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '696f4530-16f2-4725-ae45-d8e9be6821f5';
  $display->content['new-696f4530-16f2-4725-ae45-d8e9be6821f5'] = $pane;
  $display->panels['left_sidebar'][0] = 'new-696f4530-16f2-4725-ae45-d8e9be6821f5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_content_add_http_response_066f3ee6-c1cd-4197-8712-2fde4067fd3f';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_content_add';
  $handler->handler = 'http_response';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'User | Content manager',
    'contexts' => array(
      0 => array(
        'identifier' => 'Node add form',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'clientx_offers',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'node/add/clientx-offers',
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'clientx_content_manager_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_content_add_http_response_9805e29c-437f-425c-9db6-e15ebf2f93d8';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_content_add';
  $handler->handler = 'http_response';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'User | Default',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '403',
    'destination' => '',
    'name' => '',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_content_add'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_content_edit';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Content | Edit';
  $page->admin_description = 'Page for external users to edit offers and company nodes';
  $page->path = 'some/offers/node/%node/edit';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node edit form: node ID',
      'name' => 'node_edit',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_content_edit_panel_context_245ba015-db4a-4098-a610-07460bbdd5b4';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_content_edit';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User | Company/Agency',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'clientx_company_agency_editor_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_compare_company_id_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '210',
        'width_type' => 'px',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_sidebar',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_sidebar' => array(
        'type' => 'region',
        'title' => 'Left sidebar',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 1,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'left_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Edit form for Company/Agency';
  $display->uuid = '6f63f4ab-c862-4e1d-a6d4-b268410121d4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d9084a4d-d68e-403c-a6f5-acc3971ed342';
  $pane->panel = 'center';
  $pane->type = 'company_nav_bar';
  $pane->subtype = 'company_nav_bar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd9084a4d-d68e-403c-a6f5-acc3971ed342';
  $display->content['new-d9084a4d-d68e-403c-a6f5-acc3971ed342'] = $pane;
  $display->panels['center'][0] = 'new-d9084a4d-d68e-403c-a6f5-acc3971ed342';
  $pane = new stdClass();
  $pane->pid = 'new-9e6506d6-2ab9-4973-b6ab-3de19c0eff05';
  $pane->panel = 'center';
  $pane->type = 'offer_form';
  $pane->subtype = 'offer_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_node_edit_1',
      1 => 'context_user_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9e6506d6-2ab9-4973-b6ab-3de19c0eff05';
  $display->content['new-9e6506d6-2ab9-4973-b6ab-3de19c0eff05'] = $pane;
  $display->panels['center'][1] = 'new-9e6506d6-2ab9-4973-b6ab-3de19c0eff05';
  $pane = new stdClass();
  $pane->pid = 'new-76166b4b-9701-459c-8825-7416354bd3e0';
  $pane->panel = 'left_sidebar';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-aaa-offer-user-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '76166b4b-9701-459c-8825-7416354bd3e0';
  $display->content['new-76166b4b-9701-459c-8825-7416354bd3e0'] = $pane;
  $display->panels['left_sidebar'][0] = 'new-76166b4b-9701-459c-8825-7416354bd3e0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_content_edit_http_response_72d3ad9f-2937-4ca8-bbca-d94f2a1190f0';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_content_edit';
  $handler->handler = 'http_response';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'User | Default',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'node/%node/edit',
    'name' => '',
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_content_edit'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_search_closed';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Search | Closed';
  $page->admin_description = 'Teporary solution for displaying list of ongoing comps in drupal.';
  $page->path = 'some/offers/closed';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_search_closed_panel_context_88c5fe1e-1cfb-4a7b-abd6-2590341a9d81';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_search_closed';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = t('Closed selection procedures');
  $display->uuid = '77a09808-d15f-4c8b-bc27-c5b178ba5556';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e1f93737-4db2-4786-acbb-4b4a268d2a84';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--closed-message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e1f93737-4db2-4786-acbb-4b4a268d2a84';
  $display->content['new-e1f93737-4db2-4786-acbb-4b4a268d2a84'] = $pane;
  $display->panels['middle'][0] = 'new-e1f93737-4db2-4786-acbb-4b4a268d2a84';
  $pane = new stdClass();
  $pane->pid = 'new-e4ebe9f9-aeb6-4a99-80fa-0819bf2630d7';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_et_search-closed';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e4ebe9f9-aeb6-4a99-80fa-0819bf2630d7';
  $display->content['new-e4ebe9f9-aeb6-4a99-80fa-0819bf2630d7'] = $pane;
  $display->panels['middle'][1] = 'new-e4ebe9f9-aeb6-4a99-80fa-0819bf2630d7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_search_closed'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_search_future';
  $page->task = 'page';
  $page->admin_title = ' clientx | Offers | Search | Upcoming';
  $page->admin_description = '';
  $page->path = 'aaa-opportunities/upcoming';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_search_future_panel_context_e239c84c-7a4b-4df9-b276-f583f50e826a';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_search_future';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = t('Upcoming opportunities');
  $display->uuid = '93420bb9-36a7-4b58-b594-7f1e9578962e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2f9b7e73-0a10-4453-9d0d-4e3eaf8e3aa1';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--future-message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2f9b7e73-0a10-4453-9d0d-4e3eaf8e3aa1';
  $display->content['new-2f9b7e73-0a10-4453-9d0d-4e3eaf8e3aa1'] = $pane;
  $display->panels['middle'][0] = 'new-2f9b7e73-0a10-4453-9d0d-4e3eaf8e3aa1';
  $pane = new stdClass();
  $pane->pid = 'new-6206a430-b711-4c23-8cc3-0036b261c24a';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-7a6abea492b7f2a668e0ef288bdf75c9';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6206a430-b711-4c23-8cc3-0036b261c24a';
  $display->content['new-6206a430-b711-4c23-8cc3-0036b261c24a'] = $pane;
  $display->panels['middle'][1] = 'new-6206a430-b711-4c23-8cc3-0036b261c24a';
  $pane = new stdClass();
  $pane->pid = 'new-5335a370-8aeb-42a3-ac8d-245d5426d458';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_et_search-upcoming';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5335a370-8aeb-42a3-ac8d-245d5426d458';
  $display->content['new-5335a370-8aeb-42a3-ac8d-245d5426d458'] = $pane;
  $display->panels['middle'][2] = 'new-5335a370-8aeb-42a3-ac8d-245d5426d458';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_search_future'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_search_ongoing';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Search | Ongoing';
  $page->admin_description = 'Teporary solution for displaying list of ongoing comps in drupal.';
  $page->path = 'some/offers/ongoing';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_search_ongoing_panel';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_search_ongoing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = t('In progress');
  $display->uuid = '77a09808-d15f-4c8b-bc27-c5b178ba5556';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cf07cc46-31bc-41b0-8c6c-6158d4f57b17';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--ongoing-messag';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cf07cc46-31bc-41b0-8c6c-6158d4f57b17';
  $display->content['new-cf07cc46-31bc-41b0-8c6c-6158d4f57b17'] = $pane;
  $display->panels['middle'][0] = 'new-cf07cc46-31bc-41b0-8c6c-6158d4f57b17';
  $pane = new stdClass();
  $pane->pid = 'new-ac553020-ff2a-436d-ac95-ddf71a15c16f';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_et_search-ongoing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ac553020-ff2a-436d-ac95-ddf71a15c16f';
  $display->content['new-ac553020-ff2a-436d-ac95-ddf71a15c16f'] = $pane;
  $display->panels['middle'][1] = 'new-ac553020-ff2a-436d-ac95-ddf71a15c16f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_search_ongoing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_search_simple';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Search simple';
  $page->admin_description = '';
  $page->path = 'some/offers';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_search_simple_panel';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_search_simple';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = t('Some opportunities');
  $display->uuid = '767cb116-e2c9-4625-84b5-417873bfacd1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a93bbaa3-94b7-4a7b-8300-8dbcc1285e18';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-clientx--offers--search-message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a93bbaa3-94b7-4a7b-8300-8dbcc1285e18';
  $display->content['new-a93bbaa3-94b7-4a7b-8300-8dbcc1285e18'] = $pane;
  $display->panels['middle'][0] = 'new-a93bbaa3-94b7-4a7b-8300-8dbcc1285e18';
  $pane = new stdClass();
  $pane->pid = 'new-0f907fc4-26bc-42db-ab26-4350c4ab5140';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-2c1e8352820db7524cfefe2fc4fe30a2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0f907fc4-26bc-42db-ab26-4350c4ab5140';
  $display->content['new-0f907fc4-26bc-42db-ab26-4350c4ab5140'] = $pane;
  $display->panels['middle'][1] = 'new-0f907fc4-26bc-42db-ab26-4350c4ab5140';
  $pane = new stdClass();
  $pane->pid = 'new-1b2e74b3-62ae-4059-9a96-085c872c2ae6';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_et_search-advanced';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1b2e74b3-62ae-4059-9a96-085c872c2ae6';
  $display->content['new-1b2e74b3-62ae-4059-9a96-085c872c2ae6'] = $pane;
  $display->panels['middle'][2] = 'new-1b2e74b3-62ae-4059-9a96-085c872c2ae6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_search_simple'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_translation_overview';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | Content | Translation overview';
  $page->admin_description = '';
  $page->path = 'some/offers/node/%node/translate';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_translation_overview_panel_context_0bc941ba-918f-4d9c-85da-5a5a7a6b6e34';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_translation_overview';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User | Company/Agency',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'clientx_offers' => 'clientx_offers',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'clientx_company_agency_editor_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'clientx_compare_company_id_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '213',
        'width_type' => 'px',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_sidebar',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_sidebar' => array(
        'type' => 'region',
        'title' => 'Left sidebar',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'left_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Translations of %node:title';
  $display->uuid = '523336c1-bfac-406f-b5fc-b67e68890443';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-664a2ed7-df90-426d-bb1f-4f150d17dc36';
  $pane->panel = 'center';
  $pane->type = 'company_nav_bar';
  $pane->subtype = 'company_nav_bar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '664a2ed7-df90-426d-bb1f-4f150d17dc36';
  $display->content['new-664a2ed7-df90-426d-bb1f-4f150d17dc36'] = $pane;
  $display->panels['center'][0] = 'new-664a2ed7-df90-426d-bb1f-4f150d17dc36';
  $pane = new stdClass();
  $pane->pid = 'new-e79808aa-c6b4-4d64-86b7-34b796d5736c';
  $pane->panel = 'center';
  $pane->type = 'translation_overview';
  $pane->subtype = 'translation_overview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e79808aa-c6b4-4d64-86b7-34b796d5736c';
  $display->content['new-e79808aa-c6b4-4d64-86b7-34b796d5736c'] = $pane;
  $display->panels['center'][1] = 'new-e79808aa-c6b4-4d64-86b7-34b796d5736c';
  $pane = new stdClass();
  $pane->pid = 'new-21e20ddf-f267-44c7-83ff-103400efc23b';
  $pane->panel = 'left_sidebar';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-aaa-offer-user-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '21e20ddf-f267-44c7-83ff-103400efc23b';
  $display->content['new-21e20ddf-f267-44c7-83ff-103400efc23b'] = $pane;
  $display->panels['left_sidebar'][0] = 'new-21e20ddf-f267-44c7-83ff-103400efc23b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_translation_overview'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'clientx_offers_user_offer_list';
  $page->task = 'page';
  $page->admin_title = 'clientx | Offers | User | Offer list';
  $page->admin_description = '';
  $page->path = 'user/offers';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'clientx_company_agency_editor_access',
        'settings' => array(),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Offers',
    'name' => 'user-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => '',
      'name' => 'user-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clientx_offers_user_offer_list_panel_context_dd6c003e-cfd3-43e7-b577-25b94682fdfa';
  $handler->task = 'page';
  $handler->subtask = 'clientx_offers_user_offer_list';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'User | Company/Agency',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'clientx | Company ID from User profile',
        'keyword' => 'company_id',
        'name' => 'company_id_from_user',
        'context' => 'context_user_1',
        'id' => 1,
      ),
    ),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'clientx_company_agency_editor_access',
          'settings' => array(),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '210',
        'width_type' => 'px',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_sidebar',
        ),
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left_sidebar' => array(
        'type' => 'region',
        'title' => 'Left sidebar',
        'width' => '177',
        'width_type' => 'px',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'left_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Offers for %user:field-clientx-company-id';
  $display->uuid = '53d7fca7-ee99-4884-a6fc-3541d4721f69';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1a318cf3-878a-4790-9b33-a97e9edf0216';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'views-c7769f93343af7af3fe8484a6cf4e38e';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1a318cf3-878a-4790-9b33-a97e9edf0216';
  $display->content['new-1a318cf3-878a-4790-9b33-a97e9edf0216'] = $pane;
  $display->panels['center'][0] = 'new-1a318cf3-878a-4790-9b33-a97e9edf0216';
  $pane = new stdClass();
  $pane->pid = 'new-dc57b95a-dfa8-480c-97da-b5de68ff7e2c';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'clientx_offers_managment_content-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_clientx_company_id_target_id' => '%company_id:tid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dc57b95a-dfa8-480c-97da-b5de68ff7e2c';
  $display->content['new-dc57b95a-dfa8-480c-97da-b5de68ff7e2c'] = $pane;
  $display->panels['center'][1] = 'new-dc57b95a-dfa8-480c-97da-b5de68ff7e2c';
  $pane = new stdClass();
  $pane->pid = 'new-5e8b4f72-195d-46e8-9566-740fbdc8ee1c';
  $pane->panel = 'left_sidebar';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-aaa-offer-user-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5e8b4f72-195d-46e8-9566-740fbdc8ee1c';
  $display->content['new-5e8b4f72-195d-46e8-9566-740fbdc8ee1c'] = $pane;
  $display->panels['left_sidebar'][0] = 'new-5e8b4f72-195d-46e8-9566-740fbdc8ee1c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['clientx_offers_user_offer_list'] = $page;

  return $pages;
}
