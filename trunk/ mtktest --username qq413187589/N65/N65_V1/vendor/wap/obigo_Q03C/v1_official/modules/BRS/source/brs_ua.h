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










#ifndef _brs_ua_h
#define _brs_ua_h

#ifndef  _msf_int_h
#include "msf_int.h"
#endif
#ifndef  _brs_main_h
#include "brs_main.h"
#endif
#ifndef  _brs_sig_h
#include "brs_sig.h"
#endif
#ifndef  _brs_ddt_h
#include "brs_ddt.h"
#endif
#ifndef  _brs_hist_h
#include "brs_hist.h"
#endif
#ifndef  _brs_uad_h
#include "brs_uad.h"
#endif






#define BRS_UA_SIG_PROCESSING_INSTRUCTION         BRS_MODULE_UA + 1
#define BRS_UA_SIG_PARSING_PROLOGUE_DONE          BRS_MODULE_UA + 2







#define BRS_UA_SIG_NEW_DOCUMENT                   BRS_MODULE_UA + 3
#define BRS_UA_SIG_START_DISPLAYING               BRS_MODULE_UA + 4
#define BRS_UA_SIG_STOP_DISPLAYING                BRS_MODULE_UA + 5
#define BRS_UA_SIG_ABORT_DISPLAYING               BRS_MODULE_UA + 6
#define BRS_UA_SIG_STOP_LOADING                   BRS_MODULE_UA + 7









#define BRS_UA_SIG_FORMS_INITIALIZED              BRS_MODULE_UA + 7
#define BRS_UA_SIG_DISPLAYING_ABORTED             BRS_MODULE_UA + 8
#define BRS_UA_SIG_ELEMENT_SELECTED               BRS_MODULE_UA + 9
#define BRS_UA_SIG_IMAGE_MAP_SELECTED             BRS_MODULE_UA + 10











#define BRS_UA_SIG_DISPLAYING_COMPLETED           BRS_MODULE_UA + 11





#define BRS_UA_SIG_START                          BRS_MODULE_UA + 12
#define BRS_UA_SIG_TERMINATE                      BRS_MODULE_UA + 13
#define BRS_UA_SIG_LOAD_URL                       BRS_MODULE_UA + 14
#define BRS_UA_SIG_MOVE                           BRS_MODULE_UA + 15
#define BRS_UA_SIG_RELOAD                         BRS_MODULE_UA + 16
#define BRS_UA_SIG_STOP                           BRS_MODULE_UA + 17















#define BRS_UA_OPTION_RELOAD                      0x01


#define BRS_UA_DISP_ACTION_GOTO_FRAGMENT          1
#define BRS_UA_DISP_ACTION_REFRESH                2
#define BRS_UA_DISP_ACTION_NEW_DOC                3


#define BRS_UA_TASK_GO                            1
#define BRS_UA_TASK_PREV                          2
#define BRS_UA_TASK_REFRESH                       3


#define BRS_UA_EVENT_ENTERFORWARD                 0
#define BRS_UA_EVENT_ENTERBACKWARD                1
#define BRS_UA_EVENT_TIMER                        2
#define BRS_UA_EVENT_PICK                         3
#define BRS_UA_EVENT_DO                           4


#define BRS_UA_PARSER_STATUS_NORMAL               0
#define BRS_UA_PARSER_STATUS_NO_DOCUMENT          1
#define BRS_UA_PARSER_STATUS_FRAMES               2


#define BRS_UA_EVENT_HANDLER_NONE                 0
#define BRS_UA_EVENT_HANDLER_ATTRIBUTE            1
#define BRS_UA_EVENT_HANDLER_ELEMENT              2






typedef struct {
  int               instance_id;
  MSF_UINT8         mod_id;
  MsfScreenHandle   screen_handle;
  MsfPosition       pos;
  MsfSize           size;
} brs_ua_start_t;

typedef struct {
  int                 doc_type;
  int                 state;
  int                 flags;
  int                 image_doc;   
  int                 charset;
  char               *url;         
  char               *fragment;    
  char               *base_url;
  char               *image_pipe;  
  char               *image_type;  
  brs_dt_document_t   doc;
  brs_dt_tree_node_t *body_or_card;
} brs_ua_document_t;

typedef struct {
  int                instance_id;
  int                options;          
  int                display_action;
  brs_ua_document_t *doc;
  brs_ua_t          *ua;
  int                screen_pos_x;
  int                screen_pos_y;
  int                screen_node_id;
} brs_ua_new_document_t;

typedef struct {
  int   instance_id;
  char *href;
  char *title;
  char *charset;
  int   alternate;
} brs_ua_processing_instruction_t;

typedef struct {
  int               type;
  int               refresh;
  union {
    char           *url;
    
    void           *elt;
  } _u;
} brs_ua_event_handler_t;

#ifdef BRS_CONFIG_WML
typedef struct {
  int         is_present;
  int         is_set;
  char       *default_wait_time;
  int         wait_time;
  char       *var_name;
  MSF_UINT32  started_at;
} brs_ua_timer_t;
#endif

typedef struct brs_ua_pi_st {
  struct brs_ua_pi_st *next;

  int   instance_id;
  char *href;
  char *charset;
  int   alternate;
} brs_ua_pi_t;

typedef struct {
  struct brs_ua_st      *ua;
  int                    type;
  int                    options;
  int                    flags;
  int                    state;
  int                    target_type;
  int                    request_id;
  int                    pipe_handle;
  brs_hist_element_t    *history_elt;
  brs_ua_document_t     *doc;
  brs_dt_tree_node_t    *target_elt;
  char                  *refresh_string;
#ifdef BRS_CONFIG_WML
  brs_var_t             *temp_variables;
  brs_ua_event_handler_t global_handlers[3];
#endif
  int                    error_code;
  brs_ua_pi_t           *processing_instructions;
} brs_ua_task_t;


struct brs_ua_st {
  struct brs_ua_st *next;

  MSF_UINT8              mod_id;
  int                    instance_id;
  int                    transaction_id;
  long                   total_size;
  brs_ua_document_t     *current_doc;
  brs_ua_task_t         *task;
  int                    refresh_enabled;
  brs_hist_t             history;
  int                    page_count;
  brs_ua_event_handler_t local_handlers[3];

#ifdef BRS_CONFIG_WML
  brs_var_t             *global_variables;
  brs_ua_event_handler_t global_handlers[3];
  brs_ua_timer_t         timer;
#endif
};







void
brs_ua_init (void);




void
brs_ua_terminate (void);





int
brs_ua_get_current_transaction_id (int instance_id);





void
brs_ua_abort_current_transaction (int instance_id);


void
brs_ua_set_variable (brs_ua_t *ua, char *name, int var_id, char *value);

char *
brs_ua_get_variable (brs_ua_t *ua, char *name, int var_id);

#ifdef BRS_CONFIG_WML
void
brs_ua_set_wml_variable (int ua_id, char *name, char *value);

char *
brs_ua_get_wml_variable (int ua_id, char *name);
#endif

#ifdef BRS_CONFIG_WMLS









char *
brs_ua_wmls_get_variable (brs_ua_t *ua, const char *name);





int
brs_ua_wmls_set_variable (brs_ua_t *ua, const char *name, const char *value);




void
brs_ua_wmls_new_context (brs_ua_t *ua);







char *
brs_ua_wmls_get_current_card (brs_ua_t *ua);






char *
brs_ua_wmls_get_base_url (brs_ua_t *ua);

#endif
#endif
