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














#ifndef _brs_dfcf_h
#define _brs_dfcf_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#ifndef _brs_var_h
#include "brs_var.h"
#endif









#define BRS_D_CTRL_NULL             0
#define BRS_D_CTRL_TEXT             1
#define BRS_D_CTRL_TEXTAREA         2
#define BRS_D_CTRL_PASSWORD         3
#define BRS_D_CTRL_FILE             4
#define BRS_D_CTRL_HIDDEN           5
#define BRS_D_CTRL_IMAGE_BUTTON     6
#define BRS_D_CTRL_BUTTON           7
#define BRS_D_CTRL_INP_BUTTON       8
#define BRS_D_CTRL_SUBMIT           9
#define BRS_D_CTRL_RESET            10
#define BRS_D_CTRL_MULTI_SELECT     11
#define BRS_D_CTRL_SINGLE_SELECT    12
#define BRS_D_CTRL_RADIO_BUTTON     13
#define BRS_D_CTRL_CHECKBOX         14
#define BRS_D_CTRL_WML_TEXT         15
#define BRS_D_CTRL_WML_PASSWORD     16
#define BRS_D_CTRL_WML_MULTIPLE     17
#define BRS_D_CTRL_WML_SINGLE       18


#define BRS_D_CTRL_STATE_NULL       0




typedef struct brs_d_select_ctrl_st         brs_d_select_ctrl_t;
typedef struct brs_d_button_ctrl_st         brs_d_button_ctrl_t;
typedef struct brs_d_file_ctrl_st           brs_d_file_ctrl_t;
typedef struct brs_d_text_ctrl_st           brs_d_text_ctrl_t;
typedef struct brs_d_form_st                brs_d_form_t;
typedef struct brs_d_control_st             brs_d_control_t;










typedef union ctrl_data_u {
    brs_d_select_ctrl_t        *select_ctrl; 
    brs_d_button_ctrl_t        *button_ctrl; 
    brs_d_text_ctrl_t          *text_ctrl;   
    brs_d_file_ctrl_t          *file_ctrl;   
} brs_d_ctrl_data_t;

struct brs_d_control_st {
  struct brs_d_control_st *next;
  int                      state; 
  int                      ctrl_type;   
  struct brs_d_form_st    *form;      
  const char              *ctrl_name;
#ifdef BRS_CONFIG_WML
  const char              *ctrl_iname; 
#endif
  brs_dt_tree_node_t      *node;
  brs_d_ctrl_data_t        ctrl_data;
};

struct brs_d_select_ctrl_st {
  brs_d_button_ctrl_t **buttons;     
  int                   n_buttons;     
  int                   max_buttons;   
};

struct brs_d_button_ctrl_st {
  int                   handle;
  brs_dt_tree_node_t   *node;
};

struct brs_d_file_ctrl_st {
  int                   handle;
  char                 *file_name;
  char                 *file_path;
  int                   size;
  brs_dt_tree_node_t   *node;
};



struct brs_d_file_upload_st {
  char        *name;
  char        *path;
  char        *contentType;
  int          size;
};

struct brs_d_text_ctrl_st {
  int                   handle;
  brs_dt_tree_node_t   *node;
};








struct brs_d_form_st {
  int                    state;          
  int                    form_id;        
  int                    ctrl_counter;   
  brs_dt_tree_node_t    *form_node;      
  brs_d_control_t       *controls;       
  brs_d_control_t       *current_select; 
  struct brs_d_form_st  *next;
};

typedef struct brs_d_selected_element_st {
  int                  element_type; 
  brs_dt_tree_node_t  *tree_node;
  brs_d_form_t        *selected_form;
} brs_d_selected_element_t;

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML







void
brs_d_get_form_controls (brs_d_form_t *form, brs_var_t **var_list);

void
brs_d_add_new_form (brs_d_doc_t *d, brs_dt_tree_node_t *form_node);
#endif

brs_d_form_t*
brs_d_new_form (brs_dt_tree_node_t *form_node, int var_id);

brs_d_form_t*
brs_d_get_doc_global_form (brs_d_doc_t *d);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_close_current_form (brs_d_doc_t *d);
#endif

void
brs_d_initialize_form (brs_d_doc_t *d, brs_d_form_t *form);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_initialize_select_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);
#endif

void
brs_d_initialize_text_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_initialize_file_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_initialize_button_ctrl (brs_d_control_t *ctrl);

void
brs_d_initialize_image_button_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_reset_form (brs_d_doc_t *d, brs_d_form_t *form);

void
brs_d_reset_select_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_reset_text_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_reset_file_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_reset_button_ctrl (brs_d_control_t *ctrl);

void
brs_d_reset_image_button_ctrl (brs_d_doc_t *d, brs_d_control_t *ctrl);

void
brs_d_delete_forms (brs_d_form_t *form);

void
brs_d_add_new_select (brs_d_doc_t *d, brs_dt_tree_node_t *select_node);

brs_d_control_t*
brs_d_new_select_ctrl (brs_d_doc_t *d, brs_dt_tree_node_t *ctrl_node);

void
brs_d_close_current_select (brs_d_doc_t *d);

int
brs_d_add_option (brs_d_doc_t *d, brs_dt_tree_node_t *option_node);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
int
brs_d_add_button (brs_d_doc_t *d, brs_dt_tree_node_t *button_node);

brs_d_button_ctrl_t*
brs_d_new_button_ctrl (brs_dt_tree_node_t *button_node);

int
brs_d_add_radio_button (brs_d_doc_t *d, brs_dt_tree_node_t *radio_button_node);

int
brs_d_add_checkbox (brs_d_doc_t *d, brs_dt_tree_node_t *checkbox_node);
#endif

int
brs_d_add_text_control (brs_d_doc_t *d, brs_dt_tree_node_t *text_ctrl_node);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
int
brs_d_add_file_control (brs_d_doc_t *d, brs_dt_tree_node_t *file_ctrl_node);

brs_d_file_ctrl_t*
brs_d_new_file_ctrl (brs_d_doc_t *d, brs_dt_tree_node_t *file_ctrl);

void
brs_d_delete_file_ctrl (brs_d_file_ctrl_t *file_ctrl);
#endif

int
brs_d_get_ctrl_type (brs_d_doc_t *d, brs_dt_tree_node_t *ctrl_node);

brs_d_form_t*
brs_d_get_active_form (brs_d_doc_t *d);

brs_d_control_t*
brs_d_find_control_by_handle (brs_d_doc_t *d, int handle);

brs_d_control_t*
brs_d_find_control_by_handle_and_form (int handle, brs_d_form_t *form);

brs_d_control_t*
brs_d_get_control_by_type_and_name (brs_d_form_t *form, int ctrl_type, const char *ctrl_name);

brs_d_control_t*
brs_d_get_active_select_control (brs_d_form_t *form);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML

brs_d_button_ctrl_t*
brs_d_select_ctrl_add_button (brs_d_select_ctrl_t *select_ctrl, brs_dt_tree_node_t *button_node);

void
brs_d_delete_button_ctrl (brs_d_button_ctrl_t *button_ctrl);
#endif

void
brs_d_delete_select_ctrl (brs_d_select_ctrl_t *select_ctrl);

brs_d_text_ctrl_t*
brs_d_new_text_ctrl (brs_d_doc_t *d, brs_dt_tree_node_t *text_ctrl);

void
brs_d_delete_text_ctrl (brs_d_text_ctrl_t *text_ctrl);

brs_d_control_t*
brs_d_new_control (brs_d_doc_t *d, brs_dt_tree_node_t *ctrl_node);

void
brs_d_delete_control (brs_d_control_t *ctrl);

void
brs_d_initialize_doc_node (brs_d_doc_t *d, brs_dt_tree_node_t *n, int is_entry);

void
brs_d_traverse_doc (brs_d_doc_t *d, brs_dt_tree_walker_t *tw, int *traversal_state,
                    brs_d_node_action_function_t node_action);

int
brs_d_set_input_string (brs_d_doc_t *d, brs_d_control_t *text_ctrl, 
                        const char *the_string, int *err_pos, 
                        brs_input_validation_error_t *err_type);

void
brs_d_set_file_ctrl_strings (brs_d_doc_t *d, brs_d_control_t *file_ctrl, const char *file_path);


#endif
