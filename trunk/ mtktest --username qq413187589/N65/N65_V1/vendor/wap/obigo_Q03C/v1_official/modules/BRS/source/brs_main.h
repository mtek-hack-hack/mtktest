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









#ifndef _brs_main_h
#define _brs_main_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_core_h
#include "msf_core.h"
#endif
#ifndef _msf_lib_h
#include "msf_lib.h"
#endif
#ifndef _msf_mem_h
#include "msf_mem.h"
#endif
#ifndef _stk_if_h
#include "stk_if.h"
#endif
#ifndef  _brs_if_h
#include "brs_if.h"
#endif
#ifndef  _brs_dlg_h
#include "brs_dlg.h"
#endif






#define BRS_MEM_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_BRS, (x))
#define BRS_MEM_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_BRS, x)
#define BRS_MEM_FREE(x)       MSF_MEM_FREE (MSF_MODID_BRS, (x))

#define BRS_UNUSED_PARAMETER(x)                   (x) = (x)


#define BRS_STREAM_MEM_READ                       1
#define BRS_STREAM_FILE_READ                      2
#define BRS_STREAM_PIPE_READ                      3
#define BRS_STREAM_MEM_WRITE                      4
#define BRS_STREAM_FILE_WRITE                     5
#define BRS_STREAM_PIPE_WRITE                     6


#define BRS_STREAM_ERROR_DELAYED                  -1
#define BRS_STREAM_ERROR_EOF                      -2
#define BRS_STREAM_ERROR                          -3


#define BRS_STREAM_EVENT_CLOSED                   1
#define BRS_STREAM_EVENT_READ_READY               2
#define BRS_STREAM_EVENT_WRITE_READY              3
#ifdef NEW_PIPE_ERROR_EVENT
#define BRS_STREAM_EVENT_CLOSED_ERROR             4
#endif

#define BRS_PREF_HISTORY_SIZE                     1
#define BRS_PREF_REFRESH_ENABLED                  2
#define BRS_PREF_CSS_ENABLED                      3
#define BRS_PREF_ACCEPT_HEADER                    4
#define BRS_PREF_ACCEPT_OBJECT_HEADER             5
#define BRS_PREF_ACCEPT_CHARSET_HEADER            6
#define BRS_PREF_ACCEPT_LANGUAGE_HEADER           7
#define BRS_PREF_USER_AGENT_HEADER                8
#define BRS_PREF_IMODE_USER_AGENT_HEADER          9
#define BRS_PREF_OBJECT_LOAD_MIME_TYPES           10
#define BRS_PREF_OBJECT_ASK_MIME_TYPES            11
#define BRS_PREF_WML_INLINE_DO                    12
#define BRS_PREF_OBJECT_LOAD_NULL_MIME            13
#define BRS_PREF_USER_STYLE_SHEET                 14
#define BRS_PREF_REQUEST_TIMEOUT                  15
#define BRS_PREF_SEND_REFERRER                    16
#define BRS_PREF_NARROW_RENDERING_ENABLED         17
#define BRS_PREF_CACHE_ON                         18


#define BRS_DOWNLOAD_FIRST_PART                   1
#define BRS_DOWNLOAD_PRIMARY_PART                 2
#define BRS_DOWNLOAD_SECONDARY_PART               3








#define BRS_DOCTYPE_WML         1
#define BRS_DOCTYPE_XHTML       2
#define BRS_DOCTYPE_HTML        3

#define BRS_DOCTYPE_PUSH_SI     8
#define BRS_DOCTYPE_PUSH_SL     9
#define BRS_DOCTYPE_PUSH_CO     10

#define BRS_DOCTYPE_UNKNOWN     11






#define BRS_SIG_TIMER_EXPIRED                     BRS_MODULE_MAIN + 1
#define BRS_SIG_HTTP_REPLY                        BRS_MODULE_MAIN + 2
#define BRS_SIG_HTTP_ABORTED                      BRS_MODULE_MAIN + 3
#define BRS_SIG_NOTIFY                            BRS_MODULE_MAIN + 4
#define BRS_SIG_REGISTRY_RESPONSE                 BRS_MODULE_MAIN + 5
#define BRS_SIG_REGISTRY_RESPONSE_FINISHED        BRS_MODULE_MAIN + 6
#define BRS_SIG_DIALOG_RESPONSE                   BRS_MODULE_MAIN + 7
#define BRS_SIG_PREFERENCES_CHANGED               BRS_MODULE_MAIN + 8
#define BRS_SIG_WIDGET_ACTION                     BRS_MODULE_MAIN + 9
#define BRS_SIG_WIDGET_NOTIFY                     BRS_MODULE_MAIN + 10
#define BRS_SIG_WIDGET_USEREVT                    BRS_MODULE_MAIN + 11
#define BRS_SIG_WIDGET_ACCESS_KEY                 BRS_MODULE_MAIN + 12


























extern jmp_buf brs_jmp_buf;
extern int     brs_inside_run;






void
brs_init (void);

void
brs_terminate (void);

int
brs_new_handle (void);

void
brs_replace_bkslash (char *url);

void
brs_clean_up_url (char *url);

void
brs_status_stk (msf_module_status_t *p);

void
brs_mem_abort_current_activities (void);

void
brs_set_offline_mode (int instance_id, int mode);

int
brs_instance_is_offline (int instance_id);








void
brs_created (int instanceId, MsfWindowHandle paint_box, int errorCode);




void
brs_status (int instanceId, int transaction_id,
            int status, const char *url, long size);




void
brs_error (int instanceId, int errorCode);




void
brs_error_with_stk_error (int instanceId, int error_code, int stk_error);




void
brs_document_info (int instanceId, int documentId, int flags, 
                   const char *url, const char *title,
                   long size, MSF_UINT32 lastModified,
                   int docType, int socketId, MSF_INT32 securityId, int protocol);




void
brs_do_elements (int instanceId, int numElements, brs_do_element_t *elements);




void
brs_element_focused (int instanceId, int type, const char *title, const char *url, 
                     const char *object_url, const char *mime_type, 
                     const char *object_filePath, int drm_restricton);




void
brs_page_not_found_offline (int instance_id, const char *url);





void
brs_create_instance (MSF_UINT8 mod_id, brs_create_instance_t *p);

void
brs_delete_instance (int instance_id);






int
brs_get_preference_i (int instance_id, int pref);

const char *
brs_get_preference_s (int instance_id, int pref);






void
brs_timer_expired (int timer_id);

void
brs_timer_reset_all (int brs_module);

void
brs_timer_set (int brs_module, int interval, int id1, MSF_UINT32 id2);

void
brs_timer_reset (int brs_module, int id1, MSF_UINT32 id2);






int
brs_http_request (int instance_id, int brs_module, int request_id,
                  const char *url, const char *fragment, int method, int options,
                  const char *headers,
                  int num_entries, stk_content_t *content,
                  int is_embedded_object, int download_info);





void
brs_http_embedded_object_finished (int instance_id, int request_id);

void
brs_http_cancel_request (int instance_id, int request_id);

void
brs_http_cancel_all_requests (int instance_id);

void
brs_http_reply (stk_http_reply_t *p);

void
brs_http_aborted (int request_id, int error_code);

void
brs_http_delete_reply (stk_http_reply_t *p, int remove_file_or_pipe);

void
brs_http_delete_content (stk_content_t *content, int num_entries,
                         int remove_file_or_pipe);






int
brs_stream_init (int brs_module, int id, int type,
                 void *data, long datalen,
                 const char *pathname);

int
brs_stream_register_handle (int brs_module, int id, int type, int handle);

int
brs_stream_attach_read_filter (int stream_handle, int charset);

long
brs_stream_read (int stream_handle, void *buf, long buflen);

long
brs_stream_write (int stream_handle, void *buf, long buflen);

void
brs_stream_close (int stream_handle);




int
brs_handle_file_notification (int handle, int event_type);




int
brs_handle_pipe_notification (int handle, int event_type);





void
brs_handle_registry_response (msf_registry_response_t *p);






MSF_UINT32
brs_get_screen_handle (int instance_id);

void
brs_register_dialog (int instance_id, int brs_module, brs_dlg_t *dlg);

void
brs_deregister_dialog (brs_dlg_t *dlg);

void
brs_handle_widget_action (msf_widget_action_t *p);





#ifdef BRS_LOG_POINTS

#define BRS_MAIN_LOG_POINT(msg) brs_log_point(msg, TRUE)
#define BRS_MAIN_LOG_POINT_S(msg, s) brs_log_point_s(msg, s, TRUE)
#define BRS_MAIN_LOG_POINT_I(msg, i) brs_log_point_i(msg, i, TRUE)

#define BRS_DUMP_LOG_POINTS() brs_dump_log_points()
#define BRS_LOG_POINTS_GET_TIME HDIa_timeGetCurrent()
#define BRS_LOG_RESET_TIME brs_reset_log_point_start();

#ifdef BRS_LOG_MINOR_POINTS
#define BRS_MINOR_LOG_POINT(msg) brs_log_point(msg, FALSE)
#define BRS_MINOR_LOG_POINT_S(msg, s) brs_log_point_s(msg, s, FALSE)
#define BRS_MINOR_LOG_POINT_I(msg, i) brs_log_point_i(msg, i, FALSE)
#else
#define BRS_MINOR_LOG_POINT(msg) 
#define BRS_MINOR_LOG_POINT_S(msg, s) 
#define BRS_MINOR_LOG_POINT_I(msg, i) 
#endif

void
brs_log_point(const char* msg, int is_main);

void
brs_log_point_s(const char* msg, const char* s, int is_main);

void
brs_log_point_i(const char* msg, int i, int is_main);

void
brs_dump_log_points();

void
brs_reset_log_point_start();

#else

#define BRS_MAIN_LOG_POINT(msg)         
#define BRS_MINOR_LOG_POINT(msg)        
#define BRS_MAIN_LOG_POINT_S(msg, s) 
#define BRS_MINOR_LOG_POINT_S(msg, s) 
#define BRS_MAIN_LOG_POINT_I(msg, i) 
#define BRS_MINOR_LOG_POINT_I(msg, i) 
#define BRS_DUMP_LOG_POINTS() 
#define BRS_LOG_POINTS_GET_TIME 0
#define BRS_LOG_RESET_TIME 

#endif


#ifdef BRS_SEQUENCE_LOGS
#ifndef _msf_log_h
#include "msf_log.h"
#endif
#define BRS_SEQUENCE_LOG(msg)      HDIa_logMsg (MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BRS, msg)


#else

#define BRS_SEQUENCE_LOG(msg)

#endif

#endif
