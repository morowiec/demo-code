<?php
/**
 * @file
 * clientx_offers.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function clientx_offers_default_rules_configuration() {
  $items = array();
  $items['rules_clientx_offers_index_entity'] = entity_import('rules_config', '{ "rules_clientx_offers_index_entity" : {
      "LABEL" : "clientx | Offers | Index entity",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "clientx", "Offers" ],
      "REQUIRES" : [ "search_api", "rules" ],
      "ON" : { "node_update--clientx_some_page" : { "bundle" : "clientx_some_page" } },
      "DO" : [
        { "search_api_index" : { "entity" : [ "node" ], "index" : "clientx_et_aaa_search_index" } }
      ]
    }
  }');
  return $items;
}
