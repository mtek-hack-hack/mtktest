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


















#ifndef _brs_dmsh_h
#define _brs_dmsh_h

#ifndef _brs_dcmn_h
#include "brs_dcmn.h"
#endif

#ifndef _brs_ddt_h
#include "brs_ddt.h"
#endif

#ifndef _brs_dhtm_h
#include "brs_dhtm.h"
#endif

#ifndef _brs_ua_h
#include "brs_ua.h"
#endif

#ifndef _brs_var_h
#include "brs_var.h"
#endif

#ifdef BRS_CONFIG_WML
#ifndef _brs_dwml_h
#include "brs_dwml.h"
#endif
#endif

#ifndef _brs_dimf_h
#include "brs_dimf.h"
#endif

#ifndef _brs_dfcf_h
#include "brs_dfcf.h"
#endif

#ifndef _brs_css_h
#include "brs_css.h"
#endif

#ifndef _brs_cssm_h
#include "brs_cssm.h"
#endif







#define BRS_D_NODE_ENTRY   1
#define BRS_D_NODE_EXIT    0

#define BRS_D_NO_IMAGE_MAP      0
#define BRS_D_SERVER_IMAGE_MAP  1
#define BRS_D_CLIENT_IMAGE_MAP  2


#define BRS_D_DOC_STATE_NULL               0
#define BRS_D_DOC_STATE_INITIALIZING       1
#define BRS_D_DOC_STATE_INITIALIZED        2
#define BRS_D_DOC_STATE_START_DISPLAYING   3
#define BRS_D_DOC_STATE_DISPLAYING         4
#define BRS_D_DOC_STATE_WAIT_FOR_DATA      5
#define BRS_D_DOC_STATE_COMPLETE           6
#define BRS_D_DOC_STATE_IDLE               7
#define BRS_D_DOC_STATE_SUBMIT             8
#define BRS_D_DOC_STATE_RESET              9
#define BRS_D_DOC_STATE_REFRESH            10
#define BRS_D_DOC_STATE_STOP_LOADING       11
#define BRS_D_DOC_STATE_STOPPED            12
#define BRS_D_DOC_STATE_ABORTED            13


#define BRS_D_MAX_CONCURRENT_DOCDISPLAY       5






#define BRS_D_OBJECT_NOT_LOADED            0
#define BRS_D_OBJECT_REQUESTED             1
#define BRS_D_OBJECT_LOADING               2
#define BRS_D_OBJECT_LOADED                3











#define BRS_D_NODE_ENTRY   1
#define BRS_D_NODE_EXIT    0





#define BRS_D_GET_TEXT(n)                      ((const char*)(n->data))
#define BRS_D_GET_ELEMENT(n)                   ((brs_dt_element_t*)((n)->data))
#define BRS_D_GET_ELEMENT_HANDLE(n)            (BRS_D_GET_ELEMENT(n)->handle)
#define BRS_D_SET_ELEMENT_HANDLE(n,h)          (BRS_D_GET_ELEMENT_HANDLE(n) = (h))
#define BRS_D_GET_ELEMENT_CURRENT_VALUE(n)     (BRS_D_GET_ELEMENT(n)->current_value)
#define BRS_D_SET_ELEMENT_CURRENT_VALUE(n,v)   BRS_MEM_FREE(BRS_D_GET_ELEMENT_CURRENT_VALUE(n));\
                                              BRS_D_GET_ELEMENT_CURRENT_VALUE(n) = (v);




#define BRS_D_TRAVERSAL_STATE_NULL            0
#define BRS_D_TRAVERSAL_STATE_STOPPED         1
#define BRS_D_TRAVERSAL_STATE_CHILD           2
#define BRS_D_TRAVERSAL_STATE_SIBLING         3
#define BRS_D_TRAVERSAL_STATE_WAIT_FOR_DATA   4
#define BRS_D_TRAVERSAL_STATE_COMPLETE        5






#define BRS_D_LINK_A                1
#ifdef BRS_CONFIG_WML
#define BRS_D_LINK_ANCHOR           2
#define BRS_D_LINK_DO               3
#endif
#define BRS_D_LINK_IMG_IN_A         4
#define BRS_D_LINK_SUBMIT_IMAGE     5
#define BRS_D_LINK_IMG_SERVER_MAP   6
#define BRS_D_LINK_IMG_CLIENT_MAP   7


#define BRS_D_FORM_STATE_NULL         0
#define BRS_D_FORM_STATE_INITIALIZED  1

struct brs_d_object_select_event_st{
  int handle;
  int object_x;
  int object_y;
  int event_x;
  int event_y;
};






#define BRS_DISPLAY_SIG_TEXT_SELECTED             BRS_MODULE_DISPLAY + 0
#define BRS_DISPLAY_SIG_KEY_SELECTED              BRS_MODULE_DISPLAY + 1
#define BRS_DISPLAY_SIG_OPTION_SELECTED           BRS_MODULE_DISPLAY + 2
#define BRS_DISPLAY_SIG_LINK_INFO                 BRS_MODULE_DISPLAY + 3
#define BRS_DISPLAY_SIG_OBJECT_SELECTED           BRS_MODULE_DISPLAY + 4
#define BRS_DISPLAY_SIG_BUTTON_SELECTED           BRS_MODULE_DISPLAY + 5
#define BRS_DISPLAY_SIG_RADIO_BUTTON_SELECTED     BRS_MODULE_DISPLAY + 6
#define BRS_DISPLAY_SIG_CHECKBOX_SELECTED         BRS_MODULE_DISPLAY + 7
#define BRS_DISPLAY_SIG_DIALOG_RESPONSE           BRS_MODULE_DISPLAY + 8












#define BRS_DISPLAY_SIG_TEXT_INPUT_VALIDATED      BRS_MODULE_DISPLAY + 9








#define BRS_DISPLAY_SIG_CONTINUE_DISPLAY          BRS_MODULE_DISPLAY + 10








#define BRS_SIG_DRS_STORE_FINISHED               BRS_MODULE_DISPLAY + 11
#define BRS_SIG_DRS_OPEN_FILE_REPLY              BRS_MODULE_DISPLAY + 12
#define BRS_SIG_DRS_READ_FILE_REPLY              BRS_MODULE_DISPLAY + 13












#define BRS_D_HTML_DOC_FLAG               0x0001
#define BRS_D_WML_DOC_FLAG                0x0002
#define BRS_D_FORMS_INITIALIZED_FLAG      0x0004
#define BRS_D_SCRIPT_WARNING_ISSUED_FLAG  0x0008
#define BRS_D_SCRIPT_ELEMENT_START_FLAG   0x0010
#define BRS_D_SCRIPT_ELEMENT_FOUND_FLAG   0x0020
#define BRS_D_XHTML_DOC_FLAG              0x0040
#define BRS_D_NEW_DOC_SENT_TO_LE_FLAG     0x0080
#define BRS_D_REFRESH_DOC_SENT_TO_LE_FLAG     0x0100

#define BRS_D_FLAG_COMPARE(x,f)            ((((x)->display_flags) & (f)) == (f))

#define BRS_D_IS_HTML_DOC(x)               BRS_D_FLAG_COMPARE (x, BRS_D_HTML_DOC_FLAG)
#define BRS_D_IS_XHTML_DOC(x)              BRS_D_FLAG_COMPARE (x, BRS_D_XHTML_DOC_FLAG)
#define BRS_D_IS_WML_DOC(x)                BRS_D_FLAG_COMPARE (x, BRS_D_WML_DOC_FLAG)
#define BRS_D_IS_FORMS_INITIALIZED(x)      BRS_D_FLAG_COMPARE (x, BRS_D_FORMS_INITIALIZED_FLAG)
#define BRS_D_IS_INSIDE_SCRIPT_ELEMENT(x)  BRS_D_FLAG_COMPARE (x, BRS_D_SCRIPT_ELEMENT_START_FLAG)
#define BRS_D_IS_SCRIPT_WARNING_ISSUED(x)  BRS_D_FLAG_COMPARE (x, BRS_D_SCRIPT_WARNING_ISSUED_FLAG)
#define BRS_D_IS_SCRIPT_ELEMENT_FOUND(x)   BRS_D_FLAG_COMPARE (x, BRS_D_SCRIPT_ELEMENT_FOUND_FLAG)
#define BRS_D_IS_NEW_DOC_SENT_TO_LE(x)     BRS_D_FLAG_COMPARE (x, BRS_D_NEW_DOC_SENT_TO_LE_FLAG)
#define BRS_D_IS_REFRESH_DOC_SENT_TO_LE(x)     BRS_D_FLAG_COMPARE (x, BRS_D_REFRESH_DOC_SENT_TO_LE_FLAG)

#define BRS_D_CLEAR_ALL_DOC_FLAGS(x)      ((x)->display_flags = 0)
#define BRS_D_SET_DOC_FLAG(x,z)           ((x)->display_flags |= (z))
#define BRS_D_RESET_DOC_FLAG(x,z)         ((x)->display_flags &= ~(z))

#define BRS_D_GET_BASE_URL(d) ((d)->current_doc->base_url != NULL) ? (d)->current_doc->base_url : (d)->current_doc->url




#define BRS_D_LIST_INDEX_NEW_LEVEL(d,t,i,v)          ((d)->list_index = brs_d_list_index_new ((d)->list_index,(t),(i),(v)))
#define BRS_D_LIST_INDEX_PREV_LEVEL(d)               ((d)->list_index = brs_d_list_index_delete ((d)->list_index))
#define BRS_D_LIST_INDEX_GET_LIST_TYPE(d)            (((d)->list_index)->list_type)
#define BRS_D_LIST_INDEX_INC(d)                      (((d)->list_index)->idx_value++)
#define BRS_D_LIST_INDEX_GET_IDX_TYPE(d)             (((d)->list_index)->idx_type)
#define BRS_D_LIST_INDEX_GET_IDX_VALUE(d)            (((d)->list_index)->idx_value)
#define BRS_D_LIST_INDEX_SET_IDX_VALUE(d,v)          (((d)->list_index)->idx_value = (v))






extern
brs_d_doc_t* brs_d_doc_vec[];




struct brs_d_list_index_st {
 struct brs_d_list_index_st *next;
 int                         list_type;
 int                         idx_type;
 int                         idx_value;
};

brs_d_list_index_t*
brs_d_list_index_new (brs_d_list_index_t *li, int list_type, int idx_type, int idx_value);

brs_d_list_index_t*
brs_d_list_index_delete (brs_d_list_index_t *li);












struct brs_d_link_ref_st {
  struct brs_d_link_ref_st   *next;   
  int                         handle;    
  int                         type;      
  brs_dt_tree_node_t         *href_node; 
  const char                 *map_name;  
};

struct brs_d_le_obj_ref_st {
  struct brs_d_le_obj_ref_st  *next;
  int                          le_object_ref;
};

typedef struct brs_d_drm_object_st {
  int         state;
  char       *mime_type;
  char       *pipe_name;
  char       *boundary;
  char       *file_path;
  MSF_INT32   file_handle;
} brs_d_drm_object_t;

struct brs_d_obj_ref_st {
  struct brs_d_obj_ref_st        *next;
  int                             request_id;
  int                             state;
  int                             no_save;
  MSF_UINT32                      dialog_handle;
  struct brs_d_le_obj_ref_st     *le_object_refs;
  char                           *url;
  char                           *local_src;
  char                           *mime_type;
  char                           *file_path;
  MsfImageHandle                  object_handle; 
  MSF_UINT32                      hash_value;

  MSF_UINT16                      drm_op_id;
  brs_d_drm_object_t             *drm;
  
  int                             object_type; 
  int                             object_format; 
  int                             read_from_cache; 
};

struct brs_d_sas_priv_data_st {
  int instance_id;
};

typedef struct brs_d_object_ready_st {
  struct brs_d_object_ready_st* next;

  MsfImageHandle object_handle;
  int            object_type;     
  int            read_from_cache; 
  int            nbr_of_refs;
  MSF_BOOL       failed_after_received; 

  int            le_reference[1]; 
} brs_d_object_ready_t;
















 
struct brs_d_doc_st {
  int                         instance_id;
  brs_ua_document_t          *current_doc;
  brs_ua_t                   *ua;
  int                         screen_node_id;
  int                         screen_pos_x;
  int                         screen_pos_y;
  int                         display_action;
  int                         reload;
  int                         image_doc;
  char                       *image_pipe;
  char                       *image_type;

  int                         doc_state;       
  brs_d_work_item_t          *work_items;
  
  brs_d_form_t               *doc_global_form; 

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML  
  brs_d_form_t               *forms;
  brs_d_form_t               *current_form;
    
  brs_d_image_map_t          *image_maps;
  brs_d_image_map_t          *current_image_map;

  int                         script_count;
#endif

  brs_d_link_ref_t           *links;
  brs_d_link_ref_t           *current_link;
  
  brs_d_obj_ref_t            *objects;
  int                        remaining_objects;
#ifdef BRS_CONFIG_WML
  brs_d_wml_do_t             *wml_template_do_list;
  int                         no_template_do;
  brs_d_wml_do_t             *wml_last_in_template_do_list;
  int                         no_card_do;
  brs_d_wml_do_t             *wml_card_do_list;
#endif

  brs_css_stack_t            *css_stack;

  char                       *title; 
  char                       *link_color; 
  brs_d_list_index_t         *list_index;

  int                         display_flags;
  int                         dialog_id;

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
   
  brs_dt_tree_node_t         *i_mode_form;
#endif

};















































int
brs_d_get_object (brs_d_doc_t *d, int le_reference, const char *url,
                  const char *local_src, const char *mime_type,
                  MsfImageHandle *object_handle, MSF_BOOL is_img_element);




int
brs_d_nbr_of_objects_left(brs_d_doc_t* d);



  
int
brs_d_is_all_objects_cached(brs_d_doc_t* d);

















void
brs_d_object_loaded_handle (MsfImageHandle object_handle, int loaded_ok);





void
brs_d_get_obj_mime (brs_d_doc_t *d, const char *URL, char **object_mime, 
                    char **object_filePath, int *drm_restriction);





void
brs_d_cancel_all_obj_reqs (brs_d_doc_t *d);







void
brs_d_reset_le_refs (brs_d_doc_t *d);







int
brs_d_check_xdrm (int instance_id, const char *url);

void
brs_d_delete_link_refs (brs_d_link_ref_t *link);





int
brs_d_add_new_link (brs_d_doc_t *d, brs_dt_tree_node_t *link_node);

void
brs_d_close_current_link (brs_d_doc_t *d);

brs_d_link_ref_t*
brs_d_find_link_ref (brs_d_doc_t *d, int handle);

brs_d_link_ref_t*
brs_d_new_link_ref (brs_d_doc_t *d, brs_dt_tree_node_t *link_node, 
                 int handle, int image_map_type);

void
brs_d_delete_link_ref (brs_d_link_ref_t *link_ref);




void
brs_d_display_init (void);




void
brs_d_display_terminate (void);










void
brs_d_display_abort (int instance_id, int clear_screen);

brs_d_doc_t*
brs_d_create_doc (brs_ua_new_document_t *p);

void
brs_d_doc_init (brs_d_doc_t *d, brs_ua_new_document_t *p);

void
brs_d_delete_doc (brs_d_doc_t *d);

void
brs_d_delete_objects (brs_d_doc_t *d);

void
brs_d_stop_loading (int instance_id);

int
brs_d_doc_is_stopped (brs_d_doc_t *d);


brs_d_doc_t*
brs_d_find_doc_id (int instance_id);






int
brs_d_add_new_link (brs_d_doc_t *d, brs_dt_tree_node_t *link_node);





brs_dt_tree_node_t*
brs_d_find_enclosed_element (brs_dt_tree_node_t *n, brs_dt_node_filter_function_t *filter);




char*
brs_d_get_text_content (brs_dt_tree_node_t *node);





int
brs_d_mime_type_in_list (const char *mime_type, const char *mime_list);

#ifdef BRS_CONFIG_WML
char* 
brs_d_get_var_content (brs_d_doc_t *d, brs_dt_tree_node_t *node);
#endif

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_start_imode_dialog (brs_d_doc_t *d);
#endif

void
brs_d_mark_selected_submit_button (brs_d_control_t *submit_button);

void
brs_d_handle_text_selected (int instance_id, int text_id);

#ifdef BRS_CONFIG_WML
void
brs_d_handle_key_selected (int instance_id, int key_id);
#endif

void
brs_d_handle_option_selected (int instance_id, int option_id);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML  
void
brs_d_handle_area_selected (int instance_id, brs_d_area_def_t* area, brs_d_object_select_event_t *event);
#endif

void
brs_d_handle_object_selected (int instance_id, brs_d_object_select_event_t *event);

void
brs_d_handle_text_input_validated (int instance_id, int text_is_valid);

#if defined BRS_CONFIG_HTML || defined BRS_CONFIG_XHTML
void
brs_d_handle_button_selected (int instance_id, int button_id, brs_d_form_t **form);

void
brs_d_handle_radio_button_selected (int instance_id, int radio_button_id);

void
brs_d_handle_checkbox_selected (int instance_id, int checkbox_id);
#endif


#endif
