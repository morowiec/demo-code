<?php
/**
 * @file
 * clientx_offers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function clientx_offers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function clientx_offers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function clientx_offers_node_info() {
  $items = array(
    'clientx_some_page' => array(
      'name' => t('clientx | Some page'),
      'base' => 'node_content',
      'description' => t('Content type for add comp and casting some page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clientx_comp_news' => array(
      'name' => t('clientx | Competition news'),
      'base' => 'node_content',
      'description' => t('News related to comp / CASTING.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clientx_diagram' => array(
      'name' => t('clientx | Diagram'),
      'base' => 'node_content',
      'description' => t('Content type for creating'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clientx_companys_and_agencies' => array(
      'name' => t('clientx | Companys and agencies'),
      'base' => 'node_content',
      'description' => t('This content type is made for storing information about Company or agencies.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clientx_offers' => array(
      'name' => t('clientx | Temporary offers'),
      'base' => 'node_content',
      'description' => t('This content type is made for storing temporary offers.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'clientx_stage' => array(
      'name' => t('clientx | stage'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function clientx_offers_default_search_api_index() {
  $items = array();
  $items['clientx_et_aaa_search_index'] = entity_import('search_api_index', '{
    "name" : "clientx | ET | Some search index",
    "machine_name" : "clientx_et_aaa_search_index",
    "description" : null,
    "server" : "clientx_mysql_db",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [ "clientx_some_page", "clientx_offers" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "search_api_et" : {
        "include" : "incomplete",
        "restrict undefined" : 0,
        "fallback language" : ""
      },
      "fields" : {
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_clientx_closed" : { "type" : "boolean" },
        "field_clientx_deadline" : { "type" : "date" },
        "field_clientx_grade" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_clientx_company_id" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_clientx_companys_agencies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_clientx_locations:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_clientx_locations:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_clientx_open_for_aplication" : { "type" : "date" },
        "field_clientx_type_of_contract" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_clientx_upcoming" : { "type" : "boolean" },
        "language" : { "type" : "string" },
        "promote" : { "type" : "boolean" },
        "search_api_et_id" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "clientx_some_page" : "clientx_some_page",
              "clientx_offers" : "clientx_offers"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title_field" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title_field" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "title_field" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "entity_type" : "search_api_index",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function clientx_offers_default_search_api_server() {
  $items = array();
  $items['clientx_mysql_db'] = entity_import('search_api_server', '{
    "name" : "clientx | MySQL DB",
    "machine_name" : "clientx_mysql_db",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 1,
      "indexes" : {
        "clientx_aaa_search_index" : {
          "title" : {
            "table" : "search_api_db_clientx_aaa_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "language" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "url" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_clientx_company_id" : {
            "table" : "search_api_db_clientx_aaa_search_index_field_clientx_company_id",
            "column" : "field_clientx_company_id",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_deadline" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "field_clientx_deadline",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_clientx_companys_agencies" : {
            "table" : "search_api_db_clientx_aaa_search_index_field_clientx_companys_ag",
            "column" : "field_clientx_companys_agencies",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_type_of_contract" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "field_clientx_type_of_contract",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_clientx_locations:name" : {
            "table" : "search_api_db_clientx_aaa_search_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "0.5"
          },
          "field_clientx_locations:parent" : {
            "table" : "search_api_db_clientx_aaa_search_index_field_clientx_locations_parent",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_companys_agencies:title" : {
            "table" : "search_api_db_clientx_aaa_search_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_type_of_contract:name" : {
            "table" : "search_api_db_clientx_aaa_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title_field" : {
            "table" : "search_api_db_clientx_aaa_search_index",
            "column" : "title_field",
            "type" : "string",
            "boost" : "1.0"
          }
        },
        "clientx_et_aaa_search_index" : {
          "search_api_et_id" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "search_api_et_id",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "language" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_clientx_company_id" : {
            "table" : "search_api_db_clientx_et_aaa_search_index_field_clientx_company_",
            "column" : "field_clientx_company_id",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_companys_agencies" : {
            "table" : "search_api_db_clientx_et_aaa_search_index_field_clientx_companys",
            "column" : "field_clientx_companys_agencies",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_type_of_contract" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "field_clientx_type_of_contract",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "title_field" : {
            "table" : "search_api_db_clientx_et_aaa_search_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_clientx_locations:name" : {
            "table" : "search_api_db_clientx_et_aaa_search_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_locations:parent" : {
            "table" : "search_api_db_clientx_et_aaa_search_index_field_clientx_locations_pa",
            "column" : "value",
            "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_deadline" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "field_clientx_deadline",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_clientx_grade" : {
            "table" : "search_api_db_clientx_et_aaa_search_index_field_clientx_grade",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_clientx_upcoming" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "field_clientx_upcoming",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_clientx_open_for_aplication" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "field_clientx_open_for_aplication",
            "type" : "date",
            "boost" : "1.0"
          },
          "promote" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_clientx_closed" : {
            "table" : "search_api_db_clientx_et_aaa_search_index",
            "column" : "field_clientx_closed",
            "type" : "boolean",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "entity_type" : "search_api_server",
    "rdf_mapping" : []
  }');
  return $items;
}
