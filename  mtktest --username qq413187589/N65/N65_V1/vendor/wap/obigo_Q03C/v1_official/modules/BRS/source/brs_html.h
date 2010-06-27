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












#ifndef _brs_html_h
#define _brs_html_h

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
brs_html_noscript_filter (brs_dt_tree_node_t *n);







char *
brs_html_assemble_text (brs_dt_tree_node_t *root);














int
brs_html_find_basic_elements (brs_ua_document_t *doc,
                              char **base_url, char **refresh,
                              char **title, char **cache_control);




brs_dt_tree_node_t *
brs_html_find_body (brs_ua_document_t *doc);






void
brs_html_get_request_attributes (brs_dt_element_t *elt, brs_hist_element_t *info);






const char *
brs_html_get_attribute_s (brs_dt_element_t *elt, int attr_type);

#endif
