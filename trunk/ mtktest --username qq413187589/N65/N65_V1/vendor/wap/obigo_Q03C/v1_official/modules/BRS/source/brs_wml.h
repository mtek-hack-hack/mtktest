/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */












#ifndef _brs_wml_h
#define _brs_wml_h

#ifndef  _brs_hist_h
#include "brs_hist.h"
#endif
#ifndef  _brs_ddt_h
#include "brs_ddt.h"
#endif
#ifndef  _brs_ua_h
#include "brs_ua.h"
#endif










int
brs_wml_check_variable_syntax (const char *name, int len);













char *
brs_wml_evaluate_attribute (brs_ua_t *ua, const char *attr_string, int url_escape);







brs_dt_tree_node_t *
brs_wml_find_card_by_fragment (brs_dt_document_t *doc, char *frag);




int
brs_wml_card_has_newcontext (brs_dt_tree_node_t *card);









int
brs_wml_get_request_info (brs_ua_t *ua, brs_dt_tree_node_t *node,
                          brs_hist_element_t *info);






int
brs_wml_find_event_handlers (brs_ua_t *ua, brs_dt_tree_node_t *root,
                             brs_ua_event_handler_t *enter_forward,
                             brs_ua_event_handler_t *enter_backward,
                             brs_ua_event_handler_t *timer);






int
brs_wml_find_option_event_handler (brs_ua_t *ua, brs_dt_tree_node_t *option_node,
                                   brs_ua_event_handler_t *onpick);










int
brs_wml_check_access (brs_dt_tree_node_t *root, char *url, char *referrer);






void
brs_wml_find_setvar_elements (brs_ua_t *ua, brs_dt_tree_node_t *root, brs_var_t **vlist);








int
brs_wml_find_timer_element (brs_dt_tree_node_t *root, char **name, char **value);








char *
brs_wml_find_title (brs_dt_tree_node_t *card);












void
brs_wml_find_cache_control (brs_ua_document_t *doc, char **refresh, char **cache_control);






int
brs_wml_get_attribute_i (brs_dt_element_t *elt, int attr_type);







const char *
brs_wml_get_attribute_s (brs_dt_element_t *elt, int attr_type);

#endif
