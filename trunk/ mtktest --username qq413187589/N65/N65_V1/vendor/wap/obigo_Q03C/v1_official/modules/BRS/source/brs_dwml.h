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















#ifndef _brs_dwml_h
#define _brs_dwml_h


#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#ifndef _brs_dmsh_h
#include "brs_dmsh.h"
#endif
#ifndef _brs_dfcf_h
#include "brs_dfcf.h"
#endif


#ifdef BRS_CONFIG_WML





struct brs_d_wml_template_do_st {
  brs_d_wml_do_t          *next;
  const char              *name;
  const char              *type;
  brs_dt_tree_node_t      *do_node;
  int                      is_noop;
  int                      is_shadowed;
};






char *
brs_d_get_wml_href (brs_d_doc_t *d, brs_dt_tree_node_t *n);







void
brs_d_wml_template_do_shadow (brs_d_doc_t *d, const char *name);





int
brs_d_wml_card_do_is_noop (brs_dt_tree_node_t *n);




int
brs_d_wml_do_is_visible (brs_d_doc_t *d, brs_dt_tree_node_t *do_node);





void
brs_d_wml_add_card_do (brs_d_doc_t *d, brs_dt_tree_node_t *do_node,
                       const char *name, const char *type);







int
brs_d_wml_do_in_card_list (brs_d_doc_t *d, const char *name);




void
brs_d_wml_delete_card_do_list (brs_d_doc_t *d);





void
brs_d_wml_delete_template_do_list (brs_d_doc_t *d);





int
brs_d_wml_task_filter (brs_dt_tree_node_t *n);
 



void
brs_d_wml_add_template_do (brs_d_doc_t *d);




void
brs_d_wml_send_do_elements (brs_d_doc_t *d);







void
brs_d_wml_template_do_reset (brs_d_doc_t *d);





void
brs_d_wml_display_template_do_elements (brs_d_doc_t *d);
#endif





int
brs_d_wml_input_empty_ok (const char *format, int format_is_valid, int empty_ok_attrval);




int
brs_d_wml_input_validate_format (const char *format);

#ifdef BRS_CONFIG_WML







brs_d_button_ctrl_t*
brs_d_wml_get_option (brs_d_doc_t *d, int option_id);




void
brs_d_wml_initialize_select (brs_d_doc_t *d, brs_d_control_t *select_ctrl);








brs_d_button_ctrl_t*
brs_d_wml_option_selected (brs_d_doc_t *d, brs_d_control_t *select_ctrl, int option_id);








int
brs_d_wml_input_check_format (brs_dt_tree_node_t *n,
                              char **value,
                              int *err_pos,
                              brs_input_validation_error_t *err_type,
                              int *is_modified);


#endif

#endif
