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















#ifndef _brs_datr_h
#define _brs_datr_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif




#ifdef BRS_CONFIG_WML
char *
brs_d_get_wbrs_d_href (brs_d_doc_t *d, brs_dt_tree_node_t *n);
#endif







int
brs_d_get_attribute_i (brs_dt_tree_node_t *n, int attribute_name);




int
brs_d_get_attribute_ip (brs_dt_tree_node_t *n, int attribute_name, int *val, int *is_percent);




int
brs_d_get_attribute_f (brs_dt_tree_node_t *n, int attribute_name);





int
brs_d_get_attribute_t (brs_dt_tree_node_t *n, int attribute_name);





int
brs_d_get_attribute_t_cs (brs_dt_tree_node_t *n, int attribute_name);





const char*
brs_d_get_attribute_s (brs_dt_tree_node_t *n, int attribute_name);







void
brs_d_replace_attribute_value_s (brs_dt_tree_node_t *n, int attr_type, char *new_value);

#endif
