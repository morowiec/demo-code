<?php
/**
 * @file
 * clientx_offers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function clientx_offers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clientx_diagram';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'clientx | Diagram steps';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Block: Internal, numeric block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'bean';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  $handler->display->display_options['fields']['bid']['label'] = '';
  $handler->display->display_options['fields']['bid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
  /* Field: Block: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'bean';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Sort criterion: Block: Label */
  $handler->display->display_options['sorts']['label']['id'] = 'label';
  $handler->display->display_options['sorts']['label']['table'] = 'bean';
  $handler->display->display_options['sorts']['label']['field'] = 'label';
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_diagram_step' => 'clientx_diagram_step',
  );

  /* Display: ER | List of steps */
  $handler = $view->new_display('entityreference', 'ER | List of steps', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'label' => 'label',
    'bid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['clientx_diagram'] = $view;

  $view = new view();
  $view->name = 'clientx_companys_and_agencies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | Offers | Companys and agencies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Companys and agencies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: ER | All company */
  $handler = $view->new_display('entityreference', 'ER | All company', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title_field' => 'title_field',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: P | All companys */
  $handler = $view->new_display('page', 'P | All companys', 'page');
  $handler->display->display_options['path'] = 'some/path/to/view';

  /* Display: B | Companys and bodies */
  $handler = $view->new_display('block', 'B | Companys and bodies', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Companys';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Company type (field_clientx_company_type) */
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['id'] = 'field_clientx_company_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['table'] = 'field_data_field_clientx_company_type';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['field'] = 'field_clientx_company_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['default_argument_options']['argument'] = 'Companys and bodies';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_company_type' => 'clientx_offers_company_type',
  );
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Title (title_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: B | Agencies */
  $handler = $view->new_display('block', 'B | Agencies', 'block_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Company type (field_clientx_company_type) */
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['id'] = 'field_clientx_company_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['table'] = 'field_data_field_clientx_company_type';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['field'] = 'field_clientx_company_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['default_argument_options']['argument'] = 'Agencies';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_company_type' => 'clientx_offers_company_type',
  );
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_clientx_company_type_target_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Title (title_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $export['clientx_companys_and_agencies'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_some_page_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bean';
  $view->human_name = 'clientx | Offers | Some page info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Block: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'bean';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Block: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'bean';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Block: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bean';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_some_page_info' => 'clientx_some_page_info',
  );

  /* Display: ER | Some instruction */
  $handler = $view->new_display('entityreference', 'ER | Some instruction', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'bid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['clientx_offers_some_page_info'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_comp_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | Offers | Competition news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['css_class'] = 'list-group';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all';
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'list-group-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['exclude'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title_field_et]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'pull-left';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_class'] = 'views-label';
  $handler->display->display_options['fields']['changed']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['changed']['element_wrapper_class'] = 'pull-right';
  $handler->display->display_options['fields']['changed']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_comp_news' => 'clientx_comp_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: P | All news */
  $handler = $view->new_display('page', 'P | All news', 'page');
  $handler->display->display_options['path'] = 'some/path/to/view';

  /* Display: CP | Some page */
  $handler = $view->new_display('panel_pane', 'CP | Some page', 'some_page_pane_1');
  $handler->display->display_options['display_description'] = 'View shown on some pages.';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['exclude'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title_field_et] ';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'pull-left';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_wrapper_class'] = 'pull-right';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Reference number (field_clientx_ref_number_term) */
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['id'] = 'field_clientx_ref_number_term_target_id';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['table'] = 'field_data_field_clientx_ref_number_term';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['field'] = 'field_clientx_ref_number_term_target_id';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_comp_news' => 'clientx_comp_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'none',
      'context' => 'entity:node.field-clientx-ref-number-term',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID',
    ),
  );

  /* Display: B | Homepage comps news */
  $handler = $view->new_display('block', 'B | Homepage comps news', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'list-group';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'list-group-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['exclude'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title_field_et]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['text'] = 'Read >';
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alt'] = 'read more about [title]';
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'pull-right';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read >';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_comp_news' => 'clientx_comp_news',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Homepage comps news';
  $export['clientx_offers_comp_news'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_et_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_clientx_et_aaa_search_index';
  $view->human_name = 'clientx | Offers | ET Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'search_api_et_id' => 'search_api_et_id',
    'title_field' => 'title_field',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'search_api_et_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['label'] = '';
  $handler->display->display_options['fields']['search_api_et_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_et_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_et_id']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Some title';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Content: Grade */
  $handler->display->display_options['fields']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_grade']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_grade']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_locations']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Company ID */
  $handler->display->display_options['fields']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['label'] = 'Company/Agency ';
  $handler->display->display_options['fields']['field_clientx_company_id']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_company_id']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_company_id']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Type of contract */
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['fields']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Sort criterion: Indexed Multilingual Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['filters']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['operator'] = '>=';
  $handler->display->display_options['filters']['field_clientx_deadline']['value'] = 'now';
  $handler->display->display_options['filters']['field_clientx_deadline']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '3';
  /* Filter criterion: Indexed Multilingual Content: Type of contract */
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['operator_id'] = 'field_clientx_type_of_contract_op';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['label'] = 'Type of contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['operator'] = 'field_clientx_type_of_contract_op';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['identifier'] = 'contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Grade */
  $handler->display->display_options['filters']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['filters']['field_clientx_grade']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['filters']['field_clientx_grade']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_grade']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_grade']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['operator_id'] = 'field_clientx_grade_op';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['operator'] = 'field_clientx_grade_op';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['identifier'] = 'grade';
  $handler->display->display_options['filters']['field_clientx_grade']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Company ID */
  $handler->display->display_options['filters']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['filters']['field_clientx_company_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['filters']['field_clientx_company_id']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_company_id']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_company_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['operator_id'] = 'field_clientx_company_id_op';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['label'] = ' Company/Agency ';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['operator'] = 'field_clientx_company_id_op';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['identifier'] = 'company';
  $handler->display->display_options['filters']['field_clientx_company_id']['type'] = 'select';
  /* Filter criterion: Location(s): Parent terms (indexed) */
  $handler->display->display_options['filters']['field_clientx_locations_parent']['id'] = 'field_clientx_locations_parent';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['field'] = 'field_clientx_locations_parent';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_locations_parent']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_locations_parent']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['operator_id'] = 'field_clientx_locations_parent_op';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['label'] = 'Location(s)';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['operator'] = 'field_clientx_locations_parent_op';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['identifier'] = 'location';

  /* Display: CP | Main search search */
  $handler = $view->new_display('panel_pane', 'CP | Main search search', 'advanced');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'search_api_et_id' => 'search_api_et_id',
    'title_field' => 'title_field',
    'field_clientx_grade' => 'field_clientx_grade',
    'field_clientx_locations' => 'field_clientx_locations',
    'field_clientx_company_id' => 'field_clientx_company_id',
    'field_clientx_type_of_contract' => 'field_clientx_type_of_contract',
    'field_clientx_deadline' => 'field_clientx_deadline',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'search_api_et_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_grade' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_locations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_company_id' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_type_of_contract' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_deadline' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['sorts']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['sorts']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  /* Sort criterion: Indexed Multilingual Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['filters']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['operator'] = '>=';
  $handler->display->display_options['filters']['field_clientx_deadline']['value'] = 'now';
  $handler->display->display_options['filters']['field_clientx_deadline']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'clientx_some_page' => 'clientx_some_page',
    'clientx_offers' => 'clientx_offers',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '3';
  /* Filter criterion: Indexed Multilingual Content: Type of contract */
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['operator_id'] = 'field_clientx_type_of_contract_op';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['label'] = 'Type of contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['operator'] = 'field_clientx_type_of_contract_op';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['identifier'] = 'contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Grade */
  $handler->display->display_options['filters']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['filters']['field_clientx_grade']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['filters']['field_clientx_grade']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_grade']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_grade']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['operator_id'] = 'field_clientx_grade_op';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['operator'] = 'field_clientx_grade_op';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['identifier'] = 'grade';
  $handler->display->display_options['filters']['field_clientx_grade']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Company ID */
  $handler->display->display_options['filters']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['filters']['field_clientx_company_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['filters']['field_clientx_company_id']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_company_id']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_company_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['operator_id'] = 'field_clientx_company_id_op';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['label'] = ' Company/Agency ';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['operator'] = 'field_clientx_company_id_op';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['identifier'] = 'company';
  $handler->display->display_options['filters']['field_clientx_company_id']['type'] = 'select';
  /* Filter criterion: Location(s): Parent terms (indexed) */
  $handler->display->display_options['filters']['field_clientx_locations_parent']['id'] = 'field_clientx_locations_parent';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['field'] = 'field_clientx_locations_parent';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_locations_parent']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_locations_parent']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['operator_id'] = 'field_clientx_locations_parent_op';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['label'] = 'Location(s)';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['operator'] = 'field_clientx_locations_parent_op';
  $handler->display->display_options['filters']['field_clientx_locations_parent']['expose']['identifier'] = 'location';
  /* Filter criterion: Indexed Multilingual Content: Upcoming */
  $handler->display->display_options['filters']['field_clientx_upcoming']['id'] = 'field_clientx_upcoming';
  $handler->display->display_options['filters']['field_clientx_upcoming']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_upcoming']['field'] = 'field_clientx_upcoming';
  $handler->display->display_options['filters']['field_clientx_upcoming']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_clientx_upcoming']['group'] = 2;
  /* Filter criterion: Indexed Multilingual Content: Upcoming */
  $handler->display->display_options['filters']['field_clientx_upcoming_1']['id'] = 'field_clientx_upcoming_1';
  $handler->display->display_options['filters']['field_clientx_upcoming_1']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_upcoming_1']['field'] = 'field_clientx_upcoming';
  $handler->display->display_options['filters']['field_clientx_upcoming_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_clientx_upcoming_1']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_upcoming_1']['group'] = 2;
  $handler->display->display_options['pane_title'] = 'clientx | Offers | ET | Search advanced';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: CP | Closed search */
  $handler = $view->new_display('panel_pane', 'CP | Closed search', 'closed');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['label'] = '';
  $handler->display->display_options['fields']['search_api_et_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_et_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_et_id']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Some title';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Content: Reference number */
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['id'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['field'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['filters']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['operator'] = '<=';
  $handler->display->display_options['filters']['field_clientx_deadline']['value'] = 'now';
  $handler->display->display_options['filters']['field_clientx_deadline']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_some_page' => 'clientx_some_page',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Closed */
  $handler->display->display_options['filters']['field_clientx_closed']['id'] = 'field_clientx_closed';
  $handler->display->display_options['filters']['field_clientx_closed']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_closed']['field'] = 'field_clientx_closed';
  $handler->display->display_options['filters']['field_clientx_closed']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_clientx_closed']['group'] = 1;
  $handler->display->display_options['pane_title'] = 'clientx | Offers | ET | Search Closed';
  $handler->display->display_options['pane_category']['name'] = 'ESPO | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: CP | Upcoming opportunities */
  $handler = $view->new_display('panel_pane', 'CP | Upcoming opportunities', 'upcoming');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['label'] = '';
  $handler->display->display_options['fields']['search_api_et_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_et_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_et_id']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Some title';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Content: Grade */
  $handler->display->display_options['fields']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_grade']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_grade']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_locations']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_locations']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Company ID */
  $handler->display->display_options['fields']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['label'] = 'Company/Agency ';
  $handler->display->display_options['fields']['field_clientx_company_id']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_company_id']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_company_id']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Type of contract */
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Open for application */
  $handler->display->display_options['fields']['field_clientx_open_for_aplication']['id'] = 'field_clientx_open_for_aplication';
  $handler->display->display_options['fields']['field_clientx_open_for_aplication']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_open_for_aplication']['field'] = 'field_clientx_open_for_aplication';
  $handler->display->display_options['fields']['field_clientx_open_for_aplication']['settings'] = array(
    'format_type' => 'clientx_short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Multilingual Content: Open for application */
  $handler->display->display_options['sorts']['field_clientx_open_for_aplication']['id'] = 'field_clientx_open_for_aplication';
  $handler->display->display_options['sorts']['field_clientx_open_for_aplication']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['field_clientx_open_for_aplication']['field'] = 'field_clientx_open_for_aplication';
  /* Sort criterion: Indexed Multilingual Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keyword(s)';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '3';
  /* Filter criterion: Indexed Multilingual Content: Type of contract */
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['operator_id'] = 'field_clientx_type_of_contract_op';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['label'] = 'Type of contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['operator'] = 'field_clientx_type_of_contract_op';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['expose']['identifier'] = 'contract';
  $handler->display->display_options['filters']['field_clientx_type_of_contract']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Grade */
  $handler->display->display_options['filters']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['filters']['field_clientx_grade']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['filters']['field_clientx_grade']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_grade']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_grade']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['operator_id'] = 'field_clientx_grade_op';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['label'] = 'Grade';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['operator'] = 'field_clientx_grade_op';
  $handler->display->display_options['filters']['field_clientx_grade']['expose']['identifier'] = 'grade';
  $handler->display->display_options['filters']['field_clientx_grade']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Company ID */
  $handler->display->display_options['filters']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['filters']['field_clientx_company_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['filters']['field_clientx_company_id']['value'] = array();
  $handler->display->display_options['filters']['field_clientx_company_id']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_company_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['operator_id'] = 'field_clientx_company_id_op';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['label'] = ' Company/Agency ';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['operator'] = 'field_clientx_company_id_op';
  $handler->display->display_options['filters']['field_clientx_company_id']['expose']['identifier'] = 'company';
  $handler->display->display_options['filters']['field_clientx_company_id']['type'] = 'select';
  /* Filter criterion: Indexed Multilingual Content: Upcoming */
  $handler->display->display_options['filters']['field_clientx_upcoming']['id'] = 'field_clientx_upcoming';
  $handler->display->display_options['filters']['field_clientx_upcoming']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_upcoming']['field'] = 'field_clientx_upcoming';
  $handler->display->display_options['filters']['field_clientx_upcoming']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_clientx_upcoming']['group'] = 1;
  $handler->display->display_options['pane_title'] = 'clientx | Offers | ET | Search future';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: CP | Ongoing search */
  $handler = $view->new_display('panel_pane', 'CP | Ongoing search', 'ongoing');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Multilingual ID */
  $handler->display->display_options['fields']['search_api_et_id']['id'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['search_api_et_id']['field'] = 'search_api_et_id';
  $handler->display->display_options['fields']['search_api_et_id']['label'] = '';
  $handler->display->display_options['fields']['search_api_et_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_et_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_et_id']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Name */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Some title';
  $handler->display->display_options['fields']['title_field']['type'] = 'title_linked';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  /* Field: Indexed Multilingual Content: Reference number */
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['id'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['field'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['sorts']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['sorts']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['sorts']['field_clientx_deadline']['order'] = 'DESC';
  /* Sort criterion: Indexed Multilingual Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Deadline */
  $handler->display->display_options['filters']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline']['operator'] = '<=';
  $handler->display->display_options['filters']['field_clientx_deadline']['value'] = 'now';
  $handler->display->display_options['filters']['field_clientx_deadline']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_some_page' => 'clientx_some_page',
  );
  /* Filter criterion: Indexed Multilingual Content: Closed */
  $handler->display->display_options['filters']['field_clientx_closed']['id'] = 'field_clientx_closed';
  $handler->display->display_options['filters']['field_clientx_closed']['table'] = 'search_api_index_clientx_et_aaa_search_index';
  $handler->display->display_options['filters']['field_clientx_closed']['field'] = 'field_clientx_closed';
  $handler->display->display_options['filters']['field_clientx_closed']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | ET | Search Ongoing';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $export['clientx_offers_et_search'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_company_id';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'clientx | Offers | Company ID';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_company_id' => 'clientx_offers_company_id',
  );

  /* Display: ER | Search filter */
  $handler = $view->new_display('entityreference', 'ER | Search filter', 'search_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
    'tid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Company/Agency */
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['id'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['field'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['ui_name'] = 'Company/Agency';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['label'] = 'Company/Agency';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['relationship'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_company_id' => 'clientx_offers_company_id',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: ER | List of Company/Agencies names */
  $handler = $view->new_display('entityreference', 'ER | List of Company/Agencies names', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
    'tid' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Company/Agency */
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['id'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['field'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['ui_name'] = 'Company/Agency';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['label'] = 'Company/Agency';
  $handler->display->display_options['relationships']['reverse_field_clientx_company_id_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_company_id' => 'clientx_offers_company_id',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_clientx_company_id_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: ER | List of ID's */
  $handler = $view->new_display('entityreference', 'ER | List of ID\'s', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['clientx_offers_company_id'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_managment_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | Offers | Managment | Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_table_plugin_style';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_clientx_reference_number' => 'field_clientx_reference_number',
    'field_clientx_locations' => 'field_clientx_locations',
    'field_clientx_type_of_contract' => 'field_clientx_type_of_contract',
    'field_clientx_deadline' => 'field_clientx_deadline',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = 'field_clientx_deadline';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_reference_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_locations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_type_of_contract' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_clientx_deadline' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['bootstrap_styles'] = array(
    'striped' => 0,
    'bordered' => 0,
    'hover' => 0,
    'condensed' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Some title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Reference */
  $handler->display->display_options['fields']['field_clientx_reference_number']['id'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['table'] = 'field_data_field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['field'] = 'field_clientx_reference_number';
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: Type of contract */
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['table'] = 'field_data_field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Deadline */
  $handler->display->display_options['fields']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Edit';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'some/path/to/view/[nid]/edit';
  $handler->display->display_options['fields']['nid']['alter']['alt'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Company ID */
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['id'] = 'field_clientx_company_id_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['table'] = 'field_data_field_clientx_company_id';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['field'] = 'field_clientx_company_id_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['ui_name'] = 'Company ID';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_company_id' => 'clientx_offers_company_id',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_offers' => 'clientx_offers',
  );

  /* Display: Content pane | Companys and Agencies */
  $handler = $view->new_display('panel_pane', 'Content pane | Companys and Agencies', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'List of offers from selected agency.';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_offers' => 'clientx_offers',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  /* Filter criterion: Content: Reference (field_clientx_reference_number) */
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['id'] = 'field_clientx_reference_number_value';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['table'] = 'field_data_field_clientx_reference_number';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['field'] = 'field_clientx_reference_number_value';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['expose']['operator_id'] = 'field_clientx_reference_number_value_op';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['expose']['label'] = 'Reference';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['expose']['operator'] = 'field_clientx_reference_number_value_op';
  $handler->display->display_options['filters']['field_clientx_reference_number_value']['expose']['identifier'] = 'reference_number';
  /* Filter criterion: Content: Deadline (field_clientx_deadline) */
  $handler->display->display_options['filters']['field_clientx_deadline_value']['id'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['field'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_clientx_deadline_value']['expose']['operator_id'] = 'field_clientx_deadline_value_op';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['expose']['label'] = 'Deadline';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['expose']['operator'] = 'field_clientx_deadline_value_op';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['expose']['identifier'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['form_type'] = 'date_popup';
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Managment | Offer in company';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_company_id_target_id' => array(
      'type' => 'user',
      'context' => 'entity:bean.delta',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Company ID',
    ),
  );
  $export['clientx_offers_managment_content'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_reference_number';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | Offers | Reference number';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related selection procedures';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Entity translation: Title: translated */
  $handler->display->display_options['fields']['title_field_et']['id'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_et']['field'] = 'title_field_et';
  $handler->display->display_options['fields']['title_field_et']['label'] = '';
  $handler->display->display_options['fields']['title_field_et']['exclude'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title_field_et]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Reference number (field_clientx_ref_number_term) */
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['id'] = 'field_clientx_ref_number_term_target_id';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['table'] = 'field_data_field_clientx_ref_number_term';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['field'] = 'field_clientx_ref_number_term_target_id';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_ref_number_term_target_id']['validate_options']['vocabularies'] = array(
    'clientxcrs_ref_numbers' => 'clientxcrs_ref_numbers',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_some_page' => 'clientx_some_page',
  );

  /* Display: CP | Some pages */
  $handler = $view->new_display('panel_pane', 'CP | Some pages', 'panel_pane_1');
  $handler->display->display_options['pane_title'] = ' clientx | Offers | Reference number | Some pages';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_ref_number_term_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Reference number (field_clientx_ref_number_term)',
    ),
  );

  /* Display: CP | Competition news */
  $handler = $view->new_display('panel_pane', 'CP | Competition news', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related news';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_comp_news' => 'clientx_comp_news',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Reference number | Competition news';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_ref_number_term_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Reference number (field_clientx_ref_number_term)',
    ),
  );

  /* Display: CP | FAQ's */
  $handler = $view->new_display('panel_pane', 'CP | FAQ\'s', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related FAQ\'s';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientxcrs_faq' => 'clientxcrs_faq',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Reference number | FAQ\'s';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_ref_number_term_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Reference number (field_clientx_ref_number_term)',
    ),
  );
  $export['clientx_offers_reference_number'] = $view;

  $view = new view();
  $view->name = 'clientx_offers_related_offers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | Offers | Related offers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'More aaas in this agency/company';
  $handler->display->display_options['css_class'] = 'c-listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'c-listing-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Field: Company ID */
  $handler->display->display_options['fields']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['table'] = 'field_data_field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_company_id']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Some title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Reference */
  $handler->display->display_options['fields']['field_clientx_reference_number']['id'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['table'] = 'field_data_field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['field'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_reference_number']['hide_empty'] = TRUE;
  /* Field: Content: Reference number */
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['id'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['table'] = 'field_data_field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['field'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['label'] = 'Reference';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['delta_offset'] = '0';
  /* Field: Content: Deadline */
  $handler->display->display_options['fields']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_locations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: Grade */
  $handler->display->display_options['fields']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['table'] = 'field_data_field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_grade']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_grade']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_grade']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_grade']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_grade']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_grade']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_grade']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_grade']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_grade']['delta_offset'] = '0';
  /* Field: Content: Company/Agency */
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['id'] = 'field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['table'] = 'field_data_field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['field'] = 'field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['alter']['text'] = '[field_clientx_company_id]';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['empty'] = '[field_clientx_company_id]';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['delta_offset'] = '0';
  /* Field: Content: Type of contract */
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['table'] = 'field_data_field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: More information */
  $handler->display->display_options['fields']['field_clientx_url']['id'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['table'] = 'field_data_field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['field'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_clientx_url']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_url']['click_sort_column'] = 'url';
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_clientx_contact_email']['id'] = 'field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['table'] = 'field_data_field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['field'] = 'field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_contact_email']['hide_empty'] = TRUE;
  /* Contextual filter: Company/Agency NID */
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['id'] = 'field_clientx_companys_agencies_target_id';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['table'] = 'field_data_field_clientx_companys_agencies';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['field'] = 'field_clientx_companys_agencies_target_id';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['ui_name'] = 'Company/Agency NID';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['validate_options']['types'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  /* Filter criterion: Content: Deadline (field_clientx_deadline) */
  $handler->display->display_options['filters']['field_clientx_deadline_value']['id'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['field'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_some_page' => 'clientx_some_page',
    'clientx_offers' => 'clientx_offers',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: PP | Grade */
  $handler = $view->new_display('panel_pane', 'PP | Grade', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'More aaas in this grade/function group';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'c-listing';
  $handler->display->display_options['display_description'] = 'List of offers with tha same grade';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'c-listing-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Company ID */
  $handler->display->display_options['fields']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['table'] = 'field_data_field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_company_id']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Some title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Reference */
  $handler->display->display_options['fields']['field_clientx_reference_number']['id'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['table'] = 'field_data_field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['field'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_reference_number']['hide_empty'] = TRUE;
  /* Field: Content: Reference number */
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['id'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['table'] = 'field_data_field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['field'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['label'] = 'Reference';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['delta_offset'] = '0';
  /* Field: Content: Deadline */
  $handler->display->display_options['fields']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_locations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: Grade */
  $handler->display->display_options['fields']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['table'] = 'field_data_field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_grade']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_grade']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_grade']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_grade']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_grade']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_grade']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_grade']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_grade']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_grade']['delta_offset'] = '0';
  /* Field: Content: Company/Agency */
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['id'] = 'field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['table'] = 'field_data_field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['field'] = 'field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['alter']['text'] = '[field_clientx_company_id]';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['empty'] = '[field_clientx_company_id]';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['delta_offset'] = '0';
  /* Field: Content: Type of contract */
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['table'] = 'field_data_field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: More information */
  $handler->display->display_options['fields']['field_clientx_url']['id'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['table'] = 'field_data_field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['field'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_clientx_url']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_url']['click_sort_column'] = 'url';
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_clientx_contact_email']['id'] = 'field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['table'] = 'field_data_field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['field'] = 'field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_contact_email']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Grade TID */
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['id'] = 'field_clientx_grade_target_id';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['table'] = 'field_data_field_clientx_grade';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['field'] = 'field_clientx_grade_target_id';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['ui_name'] = 'Grade TID';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_grade_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_grade' => 'clientx_offers_grade',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Taxonomy related offers | Grade';
  $handler->display->display_options['pane_description'] = 'More aaas in this grade/function group';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_grade_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Grade TID',
    ),
  );

  /* Display: PP | Type of contract */
  $handler = $view->new_display('panel_pane', 'PP | Type of contract', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'More aaas with this contract';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Type of contract TID */
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['id'] = 'field_clientx_type_of_contract_target_id';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['table'] = 'field_data_field_clientx_type_of_contract';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['field'] = 'field_clientx_type_of_contract_target_id';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['ui_name'] = 'Type of contract TID';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_type_of_contract_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_type_of_contract' => 'clientx_offers_type_of_contract',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Taxonomy related offers | Type of contract';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_type_of_contract_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Type of contract TID',
    ),
  );

  /* Display: PP | Locations by city */
  $handler = $view->new_display('panel_pane', 'PP | Locations by city', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'More aaas in this location';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'c-listing';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'c-listing-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Company ID */
  $handler->display->display_options['fields']['field_clientx_company_id']['id'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['table'] = 'field_data_field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['field'] = 'field_clientx_company_id';
  $handler->display->display_options['fields']['field_clientx_company_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_company_id']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Some title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['title']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Reference */
  $handler->display->display_options['fields']['field_clientx_reference_number']['id'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['table'] = 'field_data_field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['field'] = 'field_clientx_reference_number';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_reference_number']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_reference_number']['hide_empty'] = TRUE;
  /* Field: Content: Reference number */
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['id'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['table'] = 'field_data_field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['field'] = 'field_clientx_ref_number_term';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_clientx_ref_number_term']['delta_offset'] = '0';
  /* Field: Content: Deadline */
  $handler->display->display_options['fields']['field_clientx_deadline']['id'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['field'] = 'field_clientx_deadline';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_deadline']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_deadline']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_locations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_locations']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: Grade */
  $handler->display->display_options['fields']['field_clientx_grade']['id'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['table'] = 'field_data_field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['field'] = 'field_clientx_grade';
  $handler->display->display_options['fields']['field_clientx_grade']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_grade']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_grade']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_grade']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_grade']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_grade']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_grade']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_grade']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_grade']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_grade']['delta_offset'] = '0';
  /* Field: Content: Company/Agency */
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['id'] = 'field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['table'] = 'field_data_field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['field'] = 'field_clientx_companys_agencies';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['empty'] = '[field_clientx_company_id]';
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_companys_agencies']['delta_offset'] = '0';
  /* Field: Content: Type of contract */
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['id'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['table'] = 'field_data_field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['field'] = 'field_clientx_type_of_contract';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_type_of_contract']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: More information */
  $handler->display->display_options['fields']['field_clientx_url']['id'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['table'] = 'field_data_field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['field'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_clientx_url']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_url']['click_sort_column'] = 'url';
  /* Field: Content: Contact email */
  $handler->display->display_options['fields']['field_clientx_contact_email']['id'] = 'field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['table'] = 'field_data_field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['field'] = 'field_clientx_contact_email';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_contact_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_contact_email']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Locations City TID */
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['id'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['field'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['ui_name'] = 'Locations City TID';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Taxonomy related offers | Locations by city';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_locations_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Locations with country TID',
    ),
  );

  /* Display: PP | Companys and Agencies */
  $handler = $view->new_display('panel_pane', 'PP | Companys and Agencies', 'panel_pane_4');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'c-listing';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'c-listing-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Company ID */
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['id'] = 'field_clientx_company_id_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['table'] = 'field_data_field_clientx_company_id';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['field'] = 'field_clientx_company_id_target_id';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['ui_name'] = 'Company ID';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_company_id_target_id']['validate_options']['vocabularies'] = array(
    'clientx_offers_company_id' => 'clientx_offers_company_id',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Taxonomy related offers | Company and agencies';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_company_id_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Company ID',
    ),
  );

  /* Display: PP | Locations by country */
  $handler = $view->new_display('panel_pane', 'PP | Locations by country', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'More aaas in this location';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_clientx_locations_target_id']['id'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['relationships']['field_clientx_locations_target_id']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['relationships']['field_clientx_locations_target_id']['field'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['relationships']['field_clientx_locations_target_id']['label'] = 'Taxonomy term Locations';
  $handler->display->display_options['relationships']['field_clientx_locations_target_id']['required'] = TRUE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['relationships']['parent']['label'] = 'Location country (Parent)';
  $handler->display->display_options['relationships']['parent']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Locations Country TID */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['relationship'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['arguments']['parent']['ui_name'] = 'Locations Country TID';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['parent']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['parent']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['parent']['validate_options']['vocabularies'] = array(
    'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
  );
  $handler->display->display_options['pane_title'] = 'clientx | Offers | Taxonomy related offers | Locations by country';
  $handler->display->display_options['pane_category']['name'] = 'clientx | Offers';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'parent' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Locations Country TID',
    ),
  );
  $export['clientx_offers_related_offers'] = $view;

  $view = new view();
  $view->name = 'clientx_locations_with_country';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'clientx | Offers | Locations with country';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Locations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['relationship'] = 'parent';
  $handler->display->display_options['filters']['parent']['operator'] = 'empty';

  /* Display: Countries - page */
  $handler = $view->new_display('page', 'Countries - page', 'page');
  $handler->display->display_options['path'] = 'some/path/to/view';

  /* Display: Cities in country */
  $handler = $view->new_display('block', 'Cities in country', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Cities';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Parent term */
  $handler->display->display_options['arguments']['parent']['id'] = 'parent';
  $handler->display->display_options['arguments']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['arguments']['parent']['field'] = 'parent';
  $handler->display->display_options['arguments']['parent']['default_action'] = 'default';
  $handler->display->display_options['arguments']['parent']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['parent']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['parent']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['parent']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['parent']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['parent']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['parent']['validate_options']['vocabularies'] = array(
    'clientx_locations_with_country' => 'clientx_locations_with_country',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Search filter */
  $handler = $view->new_display('entityreference', 'Search filter', 'search_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['relationship'] = 'parent';
  $handler->display->display_options['filters']['parent']['operator'] = 'empty';

  /* Display: Entity Reference - cities */
  $handler = $view->new_display('entityreference', 'Entity Reference - cities', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'clientx_offers_locations_with_country' => 'clientx_offers_locations_with_country',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['relationship'] = 'parent';
  $handler->display->display_options['filters']['parent']['operator'] = 'not empty';
  $export['clientx_locations_with_country'] = $view;

  $view = new view();
  $view->name = 'clientx_related_aaa_offer';
  $view->description = 'Related aaa offer for right sidebar';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | Offers | Right sidebar related';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'More aaas in this location';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results message';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Sort criterion: Content: Deadline (field_clientx_deadline) */
  $handler->display->display_options['sorts']['field_clientx_deadline_value']['id'] = 'field_clientx_deadline_value';
  $handler->display->display_options['sorts']['field_clientx_deadline_value']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['sorts']['field_clientx_deadline_value']['field'] = 'field_clientx_deadline_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Content: Location(s) (field_clientx_locations) */
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['id'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['field'] = 'field_clientx_locations_target_id';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['default_argument_options']['code'] = 'if ($node = menu_get_object()) {
$locations = array();
foreach($node->field_clientx_locations[LANGUAGE_NONE] as $location){
$locations[]=$location[\'target_id\'];
}
return $locations[array_rand($locations)];
}
';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_locations_target_id']['validate']['type'] = 'taxonomy_term';
  /* Filter criterion: Content: Deadline (field_clientx_deadline) */
  $handler->display->display_options['filters']['field_clientx_deadline_value']['id'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['table'] = 'field_data_field_clientx_deadline';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['field'] = 'field_clientx_deadline_value';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_clientx_deadline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_clientx_deadline_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_offers' => 'clientx_offers',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: B | Location related */
  $handler = $view->new_display('block', 'B | Location related', 'block');
  $export['clientx_related_aaa_offer'] = $view;

  $view = new view();
  $view->name = 'clientx_stages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'clientx | stages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'clientx | stages';
  $handler->display->display_options['css_class'] = 'c-listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['label'] = 'Where';
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: More information */
  $handler->display->display_options['fields']['field_clientx_url']['id'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['table'] = 'field_data_field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['field'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['click_sort_column'] = 'url';
  /* Field: Content: stage type */
  $handler->display->display_options['fields']['field_clientx_stage_type']['id'] = 'field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['table'] = 'field_data_field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['field'] = 'field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['label'] = '';
  $handler->display->display_options['fields']['field_clientx_stage_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_stage_type']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'clientx_stage' => 'clientx_stage',
  );
  /* Filter criterion: Field: Title (title_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: B | stages type */
  $handler = $view->new_display('block', 'B | stages type', 'block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: stage type (field_clientx_stage_type) */
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['id'] = 'field_clientx_stage_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['table'] = 'field_data_field_clientx_stage_type';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['field'] = 'field_clientx_stage_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['default_argument_options']['argument'] = 'stages';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate_options']['vocabularies'] = array(
    'clientx_stage_type' => 'clientx_stage_type',
  );
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate']['fail'] = 'empty';

  /* Display: B | stages for linguists type */
  $handler = $view->new_display('block', 'B | stages for linguists type', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: stage type (field_clientx_stage_type) */
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['id'] = 'field_clientx_stage_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['table'] = 'field_data_field_clientx_stage_type';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['field'] = 'field_clientx_stage_type_target_id';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['default_argument_options']['argument'] = 'stages for linguists';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate_options']['vocabularies'] = array(
    'clientx_stage_type' => 'clientx_stage_type',
  );
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_clientx_stage_type_target_id']['validate']['fail'] = 'empty';

  /* Display: P | stages */
  $handler = $view->new_display('page', 'P | stages', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'stages';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_clientx_stage_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['label'] = 'Where';
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: More information */
  $handler->display->display_options['fields']['field_clientx_url']['id'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['table'] = 'field_data_field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['field'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['click_sort_column'] = 'url';
  /* Field: Content: stage type */
  $handler->display->display_options['fields']['field_clientx_stage_type']['id'] = 'field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['table'] = 'field_data_field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['field'] = 'field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['label'] = '';
  $handler->display->display_options['fields']['field_clientx_stage_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_stage_type']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: stage type (field_clientx_stage_type) */
  $handler->display->display_options['sorts']['field_clientx_stage_type_target_id']['id'] = 'field_clientx_stage_type_target_id';
  $handler->display->display_options['sorts']['field_clientx_stage_type_target_id']['table'] = 'field_data_field_clientx_stage_type';
  $handler->display->display_options['sorts']['field_clientx_stage_type_target_id']['field'] = 'field_clientx_stage_type_target_id';
  /* Sort criterion: Field: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['path'] = 'some/path/to/view';

  /* Display: CP | Related stages */
  $handler = $view->new_display('panel_pane', 'CP | Related stages', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'stages';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'c-listing-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title_field']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['title_field']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['title_field']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title_field']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: stage type */
  $handler->display->display_options['fields']['field_clientx_stage_type']['id'] = 'field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['table'] = 'field_data_field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['field'] = 'field_clientx_stage_type';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_stage_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_stage_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['element_type'] = 'span';
  $handler->display->display_options['fields']['body']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['body']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['body']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Location(s) */
  $handler->display->display_options['fields']['field_clientx_locations']['id'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['table'] = 'field_data_field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['field'] = 'field_clientx_locations';
  $handler->display->display_options['fields']['field_clientx_locations']['label'] = 'Where';
  $handler->display->display_options['fields']['field_clientx_locations']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_locations']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_clientx_locations']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_locations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_locations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_clientx_locations']['delta_offset'] = '0';
  /* Field: Content: More information */
  $handler->display->display_options['fields']['field_clientx_url']['id'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['table'] = 'field_data_field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['field'] = 'field_clientx_url';
  $handler->display->display_options['fields']['field_clientx_url']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_class'] = 'c-listing_value';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_clientx_url']['element_label_class'] = 'c-listing_label';
  $handler->display->display_options['fields']['field_clientx_url']['element_wrapper_class'] = 'c-listing_wrapper';
  $handler->display->display_options['fields']['field_clientx_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_clientx_url']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Company/Agency (field_clientx_companys_agencies) */
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['id'] = 'field_clientx_companys_agencies_target_id';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['table'] = 'field_data_field_clientx_companys_agencies';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['field'] = 'field_clientx_companys_agencies_target_id';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['validate_options']['types'] = array(
    'clientx_companys_and_agencies' => 'clientx_companys_and_agencies',
  );
  $handler->display->display_options['arguments']['field_clientx_companys_agencies_target_id']['validate']['fail'] = 'empty';
  $handler->display->display_options['pane_title'] = 'clientx | Related stages';
  $handler->display->display_options['pane_category']['name'] = 'clientx | stages';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_clientx_companys_agencies_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Company/Agency (field_clientx_companys_agencies)',
    ),
  );
  $export['clientx_stages'] = $view;

  return $export;
}
