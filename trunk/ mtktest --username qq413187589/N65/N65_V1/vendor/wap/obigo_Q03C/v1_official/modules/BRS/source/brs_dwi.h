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















#ifndef _brs_dwi_h
#define _brs_dwi_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif
#ifndef _brs_dmsh_h
#include "brs_dmsh.h"
#endif




#define BRS_D_WI_TYPE_NULL                   0
#define BRS_D_WI_TYPE_NEW_DOCUMENT           1
#define BRS_D_WI_TYPE_REFRESH_DOC            2
#define BRS_D_WI_TYPE_DISPLAY_DOC            3
#define BRS_D_WI_TYPE_INIT_DOC               4
#define BRS_D_WI_TYPE_COLLECT_TEXT           5
#define BRS_D_WI_TYPE_RESET_FORM             6
#define BRS_D_WI_TYPE_SUBMIT_FORM            7
#define BRS_D_WI_TYPE_LINK_SELECTED          8
#define BRS_D_WI_TYPE_FILE_INPUT             9
#define BRS_D_WI_TYPE_OBJECT_SELECT          10
#ifdef BRS_CONFIG_WML
#define BRS_D_WI_TYPE_WML_OPTION_SELECTED    11
#define BRS_D_WI_TYPE_WML_KEY_SELECT         12
#endif








#define BRS_D_WI_STATE_NEW_DOC_NULL           0
#define BRS_D_WI_STATE_NEW_DOC_CREATED        1
#define BRS_D_WI_STATE_NEW_DOC_INITIALIZED    2
#define BRS_D_WI_STATE_NEW_DOC_DONE           3




#define BRS_D_WI_STATE_INIT_NULL              0
#define BRS_D_WI_STATE_INIT_INITIALIZING      1
#define BRS_D_WI_STATE_INIT_DONE              2




#define BRS_D_WI_STATE_DISPLAY_NULL           0
#define BRS_D_WI_STATE_DISPLAY_DISPLAYING     1
#define BRS_D_WI_STATE_DISPLAY_COMPLETE       2
#define BRS_D_WI_STATE_DISPLAY_STOPPED        3




#define BRS_D_WI_STATE_REFRESH_DOCUMENT_NULL      0
#define BRS_D_WI_STATE_REFRESH_DOCUMENT_WORKING   1
#define BRS_D_WI_STATE_REFRESH_DOCUMENT_DONE      2




#define BRS_D_WI_STATE_COLLECT_TEXT_NULL            0
#define BRS_D_WI_STATE_COLLECT_TEXT_VALIDATE        1
#define BRS_D_WI_STATE_COLLECT_TEXT_GLOBAL_VALIDATE 2
#define BRS_D_WI_STATE_COLLECT_TEXT_ABORT           3
#define BRS_D_WI_STATE_COLLECT_TEXT_DONE            4




#define BRS_D_WI_STATE_SUBMIT_FORM_NULL           0
#define BRS_D_WI_STATE_SUBMIT_FORM_IMODE_DIALOG   1
#define BRS_D_WI_STATE_SUBMIT_FORM_COLLECT_TEXT   2
#define BRS_D_WI_STATE_SUBMIT_FORM_COLLECT_FILE   3
#define BRS_D_WI_STATE_SUBMIT_FORM_DONE           4
#define BRS_D_WI_STATE_SUBMIT_FORM_ABORT          5




#define BRS_D_WI_STATE_RESET_FORM_NULL            0
#define BRS_D_WI_STATE_RESET_FORM_WORKING         1
#define BRS_D_WI_STATE_RESET_FORM_TEXT_COLLECTED  2
#define BRS_D_WI_STATE_RESET_FORM_DONE            3




#define BRS_D_WI_STATE_LINK_SELECT_NULL       0
#define BRS_D_WI_STATE_LINK_SELECT_WORKING    1
#define BRS_D_WI_STATE_LINK_SELECT_DONE       2
#define BRS_D_WI_STATE_LINK_SELECT_ABORT      3




#define BRS_D_WI_STATE_FILE_INPUT_NULL         0
#define BRS_D_WI_STATE_FILE_INPUT_COLLECTING   1
#define BRS_D_WI_STATE_FILE_INPUT_DONE         2




#define BRS_D_WI_STATE_OBJECT_SELECT_NULL            0
#define BRS_D_WI_STATE_OBJECT_SELECT_SERVER_MAP      1
#define BRS_D_WI_STATE_OBJECT_SELECT_CLIENT_MAP      2
#define BRS_D_WI_STATE_OBJECT_SELECT_COLLECT_TEXT    3
#define BRS_D_WI_STATE_OBJECT_SELECT_SEND_HREF_NODE  4
#define BRS_D_WI_STATE_OBJECT_SELECT_DONE            5
#define BRS_D_WI_STATE_OBJECT_SELECT_ABORT           6

#ifdef BRS_CONFIG_WML



#define BRS_D_WI_STATE_WML_OPTION_SELECT_NULL     0
#define BRS_D_WI_STATE_WML_OPTION_SELECT_WORKING  1
#define BRS_D_WI_STATE_WML_OPTION_SELECT_DONE     2
#define BRS_D_WI_STATE_WML_OPTION_SELECT_ABORT    3




#define BRS_D_WI_STATE_WML_KEY_SELECT_NULL    0
#define BRS_D_WI_STATE_WML_KEY_SELECT_DONE    1
#define BRS_D_WI_STATE_WML_KEY_SELECT_ABORT   2
#endif


#define BRS_D_ELEMENT_SELECTED 1
#define BRS_D_FORM_SELECTED    2


















typedef struct brs_d_wi_traverse_st {
  brs_dt_tree_walker_t  *tw;
  int                    traversal_state;
  int                    iterations_to_go;
} brs_d_wi_traverse_t;

#ifndef BRS_CONFIG_LAYOUT_ENGINE

typedef struct brs_d_input_text_req_st {
  struct brs_d_input_text_req_st *next;
  brs_d_control_t                *text_control;
} brs_d_input_text_req_t;

typedef struct brs_d_wi_collect_text_st {
  brs_d_form_t               *form;
  int                         doc_state;
} brs_d_wi_collect_text_t;
#endif

#ifdef BRS_CONFIG_WML
typedef struct brs_d_wi_wml_key_select_st {
  brs_dt_tree_node_t *task;
} brs_d_wi_wml_key_select_t;

typedef struct brs_d_wi_wml_option_select_st {
  brs_d_control_t            *select_ctrl;
  brs_d_button_ctrl_t        *selected_option;
} brs_d_wi_wml_option_select_t;
#endif

typedef struct brs_d_wi_submit_form_st {
  brs_d_control_t         *submit_button;
  brs_d_form_t            *selected_form;
  brs_d_form_t            *current_form;
  int                      send_user_data;
  int                      doc_state;
} brs_d_wi_submit_form_t;

typedef struct brs_d_wi_reset_form_st {
  brs_d_form_t            *selected_form;
  brs_d_form_t            *current_form;
} brs_d_wi_reset_form_t;

typedef struct brs_d_wi_link_select_st {
  brs_d_link_ref_t        *selected_link;
  brs_d_form_t            *current_form;
} brs_d_wi_link_select_t;

typedef struct brs_d_wi_object_select_st {
  brs_d_link_ref_t              *selected_image;
  brs_d_object_select_event_t   *event;
  brs_d_form_t                  *current_form;
  brs_d_image_map_t             *selected_map;
  brs_d_area_def_t              *area_def;
} brs_d_wi_object_select_t;

typedef union brs_d_work_data_u {
    brs_d_wi_traverse_t             *traverse_doc;
#ifndef BRS_CONFIG_LAYOUT_ENGINE
    brs_d_wi_collect_text_t         *collect_text;
#endif
#ifdef BRS_CONFIG_WML
    brs_d_wi_wml_option_select_t    *option_select;
    brs_d_wi_wml_key_select_t       *key_select;
#endif
#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
    brs_d_wi_submit_form_t          *submit_form;
    brs_d_wi_reset_form_t           *reset_form;
#endif
    brs_d_wi_link_select_t          *link_select;
    brs_d_wi_object_select_t        *object_select;
    
} brs_d_work_data_t;











         
struct brs_d_work_item_st {
  int                         state;
  int                         type;
  brs_d_work_data_t           work_data;
  struct brs_d_work_item_st  *next;
};







void
brs_d_wi_new_document (brs_d_doc_t *d, brs_d_work_item_t *work_item);

void
brs_d_delete_work_item (brs_d_work_item_t *work_item);

void
brs_d_wi_initialize_document (brs_d_doc_t *d, brs_d_work_item_t *work_item);

#ifndef BRS_CONFIG_LAYOUT_ENGINE
void
brs_d_wi_display_document (brs_d_doc_t *d, brs_d_work_item_t *work_item);
#endif

#ifndef BRS_CONFIG_LAYOUT_ENGINE
void
brs_d_wi_refresh_document (brs_d_doc_t *d, brs_d_work_item_t *work_item);
#endif

void
brs_d_wi_collect_text (brs_d_doc_t *d, brs_d_work_item_t *work_item);

#ifdef BRS_CONFIG_WML
void
brs_d_wi_wml_key_select (brs_d_doc_t *d, brs_d_work_item_t *work_item, int key_handle);

void
brs_d_wi_wml_option_select (brs_d_doc_t *d, brs_d_work_item_t *work_item, int option_id);
#endif

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML

void
brs_d_wi_submit_form (brs_d_doc_t *d, brs_d_work_item_t *work_item, brs_d_control_t *submit_button);

void
brs_d_wi_reset_form (brs_d_doc_t *d, brs_d_work_item_t *work_item, brs_d_control_t *reset_button);

#endif

void
brs_d_wi_link_select (brs_d_doc_t *d, brs_d_work_item_t *work_item, int link_id);

void
brs_d_wi_object_select (brs_d_doc_t *d, brs_d_work_item_t *work_item, 
                     brs_d_object_select_event_t *event);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_wi_area_select(brs_d_doc_t *d, brs_d_area_def_t* area, brs_d_object_select_event_t *event);
#endif

#ifndef BRS_CONFIG_LAYOUT_ENGINE
void
brs_d_receive_requested_text (brs_d_doc_t *d, int text_id, const char *text);
#endif


#endif
