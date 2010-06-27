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














#ifndef _brs_dleh_h
#define _brs_dleh_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#ifndef _brs_dfcf_h
#include "brs_dfcf.h"
#endif
#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif

typedef struct brs_d_button_iterator_st {
  int           current_index;
  brs_d_control_t *select_control;
} brs_d_button_iterator_t;

typedef struct brs_d_ctrl_iterator_st {
  brs_d_button_iterator_t  *current_select;
  brs_d_control_t          *current_ctrl;
  int                       text_only;
} brs_d_ctrl_iterator_t;



void
brs_d_event_text_selected (int instance_id, brs_dt_tree_node_t *link_node);

#ifdef BRS_CONFIG_WML
void
brs_d_event_key_selected (int instance_id, brs_dt_tree_node_t *key_node);
#endif

brs_d_button_iterator_t*
brs_d_event_option_selected (int instance_id, brs_dt_tree_node_t *option_node);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_event_area_selected (int instance_id, brs_d_area_def_t *area, brs_d_object_select_event_t *event);
#endif

void
brs_d_event_object_selected (int instance_id, brs_dt_tree_node_t *object_node,   
                             brs_d_object_select_event_t *event);

int
brs_d_event_input_string (int instance_id, brs_dt_tree_node_t *input_node,
                          char *the_string, int *err_pos);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
brs_d_ctrl_iterator_t*
brs_d_event_button_selected (int instance_id, brs_dt_tree_node_t *button_node);

brs_d_button_iterator_t*
brs_d_event_radio_button_selected (int instance_id, brs_dt_tree_node_t *radio_button_node);
#endif

brs_d_button_iterator_t*
brs_d_event_checkbox_selected (int instance_id, brs_dt_tree_node_t *checkbox_node);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_event_input_file (int instance_id, brs_dt_tree_node_t *file_node, char *file_path);
#endif

brs_dt_tree_node_t*
brs_d_button_iterator_next_node (int instance_id, brs_d_button_iterator_t *bi);

brs_d_button_iterator_t*
brs_d_new_button_iterator (int instance_id, brs_dt_tree_node_t *button_node);

brs_d_button_iterator_t*
brs_d_new_select_iterator (brs_d_control_t *select_ctrl);

void
brs_d_delete_button_iterator (brs_d_button_iterator_t *bi);

brs_dt_tree_node_t*
brs_d_ctrl_iterator_next_node (int instance_id, brs_d_ctrl_iterator_t *ci);

brs_d_ctrl_iterator_t*
brs_d_new_text_ctrl_iterator (brs_d_form_t *form);

brs_dt_tree_node_t*
brs_d_next_text_ctrl (int instance_id, brs_d_ctrl_iterator_t *ci);

brs_d_ctrl_iterator_t*
brs_d_new_ctrl_iterator (int instance_id, brs_d_form_t *form, int text_only);

void
brs_d_delete_ctrl_iterator (brs_d_ctrl_iterator_t *ci);


#endif
