/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * JBrowserMMITypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains all the data structures used for browser secondary MMI implementation.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _JBROWSERMMITYPES_H
#define _JBROWSERMMITYPES_H

#include "MMI_features.h"
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "custom_wap_config.h"
#include "custom_nvram_editor_data_item.h"

/* Jataayu Module Includes */
#include "jdi_servicehandler.h"
#include "jdi_communicator.h"
#include "jcal.h"
#include "jdi_BrowserDatatype.h"
#include "ddl.h"

#include "EventsGprot.h"

#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
#include "FileMgr.h"
#endif 

#define MMI_BRW_DCS_ASCII                               0x00
#define MMI_BRW_DCS_UCS                                 0x01
#define MMI_BRW_MAX_BOOKMARKS                           NVRAM_BRW_MAX_BOOKMARKS
#define MMI_BRW_BKM_MAX_TITLE_LENGTH                    NVRAM_BRW_BKM_MAX_TITLE_LENGTH
#define MMI_BRW_BKM_MAX_URL_LENGTH                      NVRAM_BRW_BKM_MAX_URL_LENGTH
#define MMI_BRW_MAX_ADDRESS_HISTORY                     NVRAM_BRW_MAX_ADDRESS_HISTORY
#define MMI_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH        NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH
#define MMI_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH          NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH
#define MMI_BRW_WAP_PROFILE_HOMEPAGE_URL_LEN            NVRAM_WAP_PROFILE_HOMEPAGE_URL_LEN

/* Maximum number of characters to be shown in case of url */
#define MMI_BRW_MAX_VISIBLE_URL_LENGTH                  38
#ifndef MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION
#define MMI_BRW_NUM_ITEMS_IN_BROWSER_OPTION             8
#else 
#define MMI_BRW_NUM_ITEMS_IN_BROWSER_OPTION             10
#endif 
#define MMI_BRW_SHOW_IMAGES_OPTION                      2
#define MMI_BRW_SHOW_HISTORY_AS_OPTION                  2
#define MMI_BRW_SHOW_IMAGES_SELECTION                   2
#define MMI_BRW_TIME_OUT_LEN                            3

/* Added for authentication */
#define MMI_BRW_AUTH_USERNAME_LEN                       31
#define MMI_BRW_AUTH_PASSWORD_LEN                       31
#define MMI_BRW_MAX_WSP_RETRIES                         4

/* Added for maximum do elemnts on a page */
#define MMI_BRW_MAX_DO_ELEMENTS                         30

#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
#define MMI_BRW_MAX_PATH_LENGTH      FMGR_MAX_PATH_LEN*ENCODING_LENGTH
#define MMI_BRW_MAX_FILENAME_LENGTH  (FMGR_MAX_INPUT_FILE_LEN)*ENCODING_LENGTH
#endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 
/* Browser Screen Error Tone Duration */
#define MMI_BRW_POPUP_TIME                              UI_POPUP_NOTIFYDURATION_TIME

#define MMI_BRW_SERVER_CERTIFICATE_FILE                     L"z:\\@wap\\TempFiles\\brw_server_cert"
#define MMI_BRW_USER_CERTIFICATES_FOLDER                    L"z:\\@wap\\TempFiles\\user_certs\\"
#define MMI_BRW_MAX_MODULE_NAME_LENGTH                      7

/* Browser Max Accesskey Value.Its value should always be TOTAL KEYS + 1 */
/* Currently registered Accesskeys are as follows: */
/* 
 * (1)  KEY_STAR,   (2)  KEY_0, 
 * (3)  KEY_1,      (4)  KEY_2, 
 * (5)  KEY_3,      (6)  KEY_4, 
 * (7)  KEY_5,      (8)  KEY_6, 
 * (9)  KEY_7,      (10) KEY_8, 
 * (11) KEY_9,      (12) KEY_POUND
 * (13) KEY_SEND (if BROWSER_SENDKEY_AS_ACCESSKEY is defined in ddl.h)
 */
#ifdef BROWSER_SENDKEY_AS_ACCESSKEY
#define MMI_BRW_MAX_ACCESSKEY                           14
#else 
#define MMI_BRW_MAX_ACCESSKEY                           13
#endif 

#define MMI_BRW_PH_CONN_PORTNUMBER                      9201
#define MMI_BRW_PH_CONN_SECURE_PORTNUMBER               9203
#define MMI_BRW_PH_CONN_HTTP_PORTNUMBER                 80
#define MMI_BRW_PROGRESS_STRING_SIZE                    100

#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
/* Defining macros  for offline pages */
#define MMI_BRW_OFFLINE_PAGE_EXTENSION  ".mrt"  /* When Modified, Macro MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH should also modify */
#define MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH 4
#define MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH    (MMI_BRW_MAX_FILENAME_LENGTH + (MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH * ENCODING_LENGTH))
/* #define MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION */
#endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 

/* Typedefs */
typedef enum
{
    BRW_STATUS_NO,
    BRW_STATUS_YES,
    BRW_STATUS_FROM_ENTER_ADDRESS,
    BRW_STATUS_ADD_BKM_FROM_USE_URL,
#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
    BRW_STATUS_ADD_BKM_FROM_OFFLINE_PAGES,
#endif 
    BRW_STATUS_TOTAL
} mmi_brw_status_enum;

typedef enum
{
    BRW_DATACONN_ACTIVATING,
    BRW_DATACONN_ACTIVATED,
    BRW_DATACONN_DEACTIVATING,
    BRW_DATACONN_DEACTIVATED,
    BRW_DATACONN_TOTAL
} mmi_brw_data_conn_state_enum;

typedef enum
{
    BRW_INLINE_TITLE_CAPTION,
    BRW_INLINE_TITLE,
    BRW_INLINE_ADDRESS_CAPTION,
    BRW_INLINE_URL,
    BRW_INLINE_TOTAL
} mmi_brw_inline_item_display_enum;

typedef enum
{
    BRW_SAT_LAUCH_SUCC,
    BRW_SAT_BRWOSER_BUSY,
    BRW_SAT_BEARER_UNAVAILABLE,
    BRW_SAT_PARAM_GATEWAY_ERROR,
    BRW_SAT_PARAM_URL_ERROR,
    BRW_SAT_PROV_DATA_ERROR,
    BRW_SAT_UNKNOWN_ERROR,
    BRW_SAT_TOTAL_ERROR
} mmi_brw_sat_lauch_res_enum;

typedef enum
{
    BRW_SAT_USER_TERMINATION,
    BRW_SAT_ERROR_TERMINATION,
    BRW_SAT_TOTAL_TERMINATION
} mmi_brw_sat_browser_termination_mode_enum;

typedef enum
{
    BRW_INLINE_USERNAME_CAPTION,
    BRW_INLINE_USERNAME,
    BRW_INLINE_PASSWORD_CAPTION,
    BRW_INLINE_PASSWORD,
    BRW_INLINE_TOTAL_USER
} mmi_brw_auth_inline_item_display_enum;

typedef enum
{
    BRW_INLINE_TIMEOUT_CAPTION = 0,
    BRW_INLINE_TIMEOUT_EDIT,
    BRW_INLINE_SHOW_IMAGES_CAPTION,
    BRW_INLINE_SHOW_IMAGES_SELECT,
    BRW_INLINE_SHOW_HISTORY_CAPTION,
    BRW_INLINE_SHOW_HISTORY_SELECT,
    BRW_INLINE_IMAGES_SELECTION_CAPTION,
    BRW_INLINE_IMAGES_SELECTION_SELECT,
#ifdef MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION
    BRW_INLINE_OFFLINE_LOCATION_CAPTION,
    BRW_INLINE_OFFLINE_LOCATION_SELECT,
#endif /* MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION */ 
    BRW_INLINE_TOTAL_SELECTION
} mmi_brw_option_inline_item_display_enum;

/* BROWSER EVENT TYPES */
typedef enum
{
    E_BRW_STARTUP_EVENT = 1,
    E_BRW_START_FETCH_EVENT,
    E_BRW_STOP_FETCH_EVENT,
    E_BRW_ACTION_EVENT,
    E_BRW_KEY_UP_EVENT,
    E_BRW_KEY_DOWN_EVENT,
    E_BRW_KEY_LEFT_EVENT,
    E_BRW_KEY_RIGHT_EVENT,
    E_BRW_REFRESH_EVENT,
    E_BRW_SAT_GOTO_URL_EVENT,
    E_BRW_PARSE_DRM_EVENT,
    E_BRW_DEINIT_EVENT,
    E_BRW_DATACONN_AUTO_DISC_TIMEOUT_EVENT,
    E_BRW_ENDKEY_EVENT,
    E_TOTAL_EVENTS
} mmi_brw_secondary_mmi_events_enum;

/* Page fetch event type */
typedef enum
{
    BRW_START_FETCH_EVENT,
    BRW_ACTION_EVENT,
    BRW_TOTAL_EVENT
} mmi_brw_page_fetch_event_enum;

/* Added by vikas lal - Push Context Structure */
typedef struct
{
    MMI_BOOL push_delete_notification;
    /*
     * We will set this flag when a push delete notification will come. So that 
     * on idle 'new service message' pop can be avoid in case of push 
     * replacement. This flag will be reset at the following place
     *  - While reading the push message.
     *  - While displaying the Inbox.
     *  - While entering to the idle screen.
     *  - While displaying the UM Main Screen (Only for UM)
     */

    S32 max_push_messages;
    SERVICE_VALUE *current_service_message;
    SERVICE_VALUE **service_msg_list_p;
    U16 curr_hilited_item_index;
    U8 *message_buffer;
} mmi_brw_push_context_struct;

#ifdef JBROWSER_USE_ASM
/* BROWSER INIT EVENT TYPES */
typedef enum
{
    BRW_INIT_APP_GOTO_INTERNET_SERVICES,
    BRW_INIT_APP_GOTO_HOMEPAGE,
    BRW_INIT_APP_GOTO_URL,
    BRW_INIT_APP_GOTO_PUSH_MESSAGE,
    BRW_INIT_APP_GOTO_SAT,
    BRW_INIT_APP_GOTO_TOTAL
} mmi_brw_init_app_enum;
#endif /* JBROWSER_USE_ASM */ 

/* Browser Context Structure */
typedef struct
{
    nvram_brw_bkm_title_struct *bookmark_title_p;
    nvram_brw_bkm_url_struct *bookmark_url_p;
    nvram_brw_hist_title_struct *address_history_title_p;
    nvram_brw_hist_url_struct *address_history_url_p;
    U8 total_bookmark_items;
    U8 total_address_history_items;
    U16 timeout_value;
    U8 show_images;
    U8 show_history_as_url;
    U8 image_selection;
    U8 index_highlighted_item;
    MMI_BOOL push_msg_rcvd_flag;
    JC_DO_LIST **do_element_list;
    U16 do_element_count;
    U16 used_do_element_count;
    JC_AUTH_INFO pauthinfo;
    U8 brw_auth_username[MMI_BRW_AUTH_USERNAME_LEN *ENCODING_LENGTH];
    U8 brw_auth_password[MMI_BRW_AUTH_PASSWORD_LEN *ENCODING_LENGTH];
    U8 is_browser_ready;
    U8 is_browser_init_in_progress;
    JC_BOOLEAN is_connection_active;
    JC_BOOLEAN is_rendered_flag;
    JC_BOOLEAN is_layout_initialized;
    JC_BOOLEAN is_saturl;                       /* added to identify if browsing from SAT application */
    JC_BOOLEAN is_service_msg_setting;          /* added to identify whether service message is on or of */
#ifdef __MMI_JBROWSER_SCREEN_LOCKING_ENABLED__
    JC_BOOLEAN is_brw_screen_locked;            /* added to identify if browsing screen is locked */
#endif 
#ifndef __JBROWSER_DLS_SUPPORT__
    U8 is_downloading;
    U8 is_download_suspended;
    U8 download_size_in_kb;
    U8 show_download_aborted_popup;
    S8 dwnld_progress_str[MMI_BRW_PROGRESS_STRING_SIZE];
    JC_MIME_INFO dwnld_mime_info;
#endif /* __JBROWSER_DLS_SUPPORT__ */ 
    U32 total_content_length;
    U32 downloaded_content_length;
    JDD_FSHANDLE dwnld_fs_handle;
    JDD_FILE dwnld_file_handle;
    U8 page_fetch_event;                        /* added to iddentify if page is fetched from E_BRW_START_FETCH_EVENT or E_BRW_ACTION_EVENT */
    U8 page_fetch_req_src;                      /* added to iddentify if page is requested from wap menu(setting as 0) or from other screen (setting as 1) */
    JC_CHAR *prompt_buffer;                     /* added by pawan for prompt input */
    COMM_HANDLE hcomm_handle;
    U8 jbrowser_frm_ext_app;
    JC_BOOLEAN is_data_connection_deactivate;   /* Added to iddentify if the data connection is deactivated bt the app in case of csd connection */
    U8 data_connection_state;                   /* Added to iddentify the current state of the data connection in case of csd */
    JC_FETCH_URL_INFO fetch_url_info;
    U8 brw_current_url[MMI_BRW_BKM_MAX_URL_LENGTH *ENCODING_LENGTH];
    BOOL brw_csd_call_disconnect;               /* It is being set when csd call get disconnected */
    BOOL end_key_pressed;                       /* Added to process the end key through internal queue */
    U8 enter_add_hist_flag;                     /* added by tk to set the highlighter to a 2nd position */
    U8 brw_bkm_selected_title[(MMI_BRW_BKM_MAX_TITLE_LENGTH) *ENCODING_LENGTH];
    JC_CHAR *pm_msg;
    JC_CHAR *pm_default_value;
    JC_CHAR *confirm_soft1;
    JC_CHAR *confirm_soft2;
    void *arg_p;
    mmi_brw_status_enum edit_flag;
#ifdef JBROWSER_USE_ASM
    mmi_brw_init_app_enum init_app_flag;
#endif 
    kal_uint32 asm_mem_size;
    BROWSER_ALERT_CB call_back_alert;
    BROWSER_CONFIRM_CB call_back_confirm;
    BROWSER_PROMPT_CB call_back_prompt;
    MMI_BOOL title_icon_animation_status;
    BOOL csd_call_aborted_status;
#ifdef JBROWSER_USE_ASM
    void *wap_heap_space;
#endif 
} mmi_brw_context_struct;

#ifdef __MMI_JBROWSER_SCREEN_LOCKING_ENABLED__
typedef enum
{
    BRW_SCREEN_LOCK,
    BRW_SCREEN_UNLOCK,
    BRW_SCREEN_TOTAL_LOCK
} mmi_brw_screen_display_enum;
#endif /* __MMI_JBROWSER_SCREEN_LOCKING_ENABLED__ */ 

/* Browser Page context */
typedef struct
{
    U8 brw_page_fetch_status;
    U8 brw_page_refresh_disp_status;
    U8 brw_page_render_status;
    U8 brw_pre_page_render_status;
    U8 brw_cancel_flag;
    U8 brw_page_status_code_stack[3];
    JC_BOOLEAN brw_is_refresh_display;
    FuncPtr brw_lsk_fun_ptr;
    FuncPtr brw_rsk_fun_ptr;
    U16 brw_lsk_label;
    U16 brw_rsk_label;
    BOOL brw_option_refresh_page;
} mmi_brw_page_context_struct;

#ifdef __JBROWSER_DLS_SUPPORT__
/* BROWSER DOWNLOAD STATES */
typedef enum
{
    BRW_DLS_FIRST_CHUNK,
    BRW_DLS_SUSPENDED,
    BRW_DLS_DOWNLOADING,
    BRW_DLS_COMPLETE,
    BRW_DLS_IDLE,
    BRW_DLS_TOTAL
} mmi_brw_dls_dwnld_state_enum;

/* DLS Content Data context */
typedef struct dls_content_st
{
    struct dls_content_st *next;
    JC_UINT32 current_length;
    JC_UINT8 *content_p;
} mmi_brw_dls_content_struct;

/* Download Service context */
typedef struct
{
    S32 session_id;
    U32 seq_num;
    BOOL progress_flag;
    JC_UINT32 header_length;
    JC_UINT32 content_length;
    JC_INT8 *content_type_p;
    JC_UINT8 *url_p;
    JC_CHAR *file_name_p;
    JC_CHAR *file_path_p;
    JC_UINT8 *header_p;
    mmi_brw_dls_content_struct *content_list_p;
    JC_UINT32 total_current_length;
    mmi_brw_dls_dwnld_state_enum download_state;
    BOOL has_more_content_data;
} mmi_brw_dls_context_struct;
#endif /* __JBROWSER_DLS_SUPPORT__ */ 

#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
/* Offline Browsing Context Structure */
typedef struct
{
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH];
    U16 selected_file_index;
    U16 selected_loc;
    JC_OFFLINE_PAGE_INFO *curr_page_info_p;
    JC_OFFLINE_PAGE_FILE_CONTEXT *offline_info; /* Pointer to the core Structure get initialize on browser Initialization */
    JC_OFFLINE_PAGE_FILE_LIST *temp_node;       /* This is used in the callback for dynamic list category-to keep track of the last node */
    E_JC_OFFLINE_PAGE_OPER_TYPE operation_type;
    JC_BOOLEAN need_sync;
    JC_BOOLEAN auto_refresh_timer;
} brw_offline_pages_context_struct;

/* End of the Structure defination used in offline browsing */
#endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 

extern mmi_brw_context_struct g_mmi_brw_cntx;
extern mmi_brw_push_context_struct g_mmi_brw_push_cntx;
extern JC_BROWSER_CONTEXT g_mmi_brw_pbrowser_ctxt;
extern mmi_brw_page_context_struct g_mmi_brw_page_cntx;

#ifdef __JBROWSER_DLS_SUPPORT__
extern mmi_brw_dls_context_struct g_mmi_brw_dls_cntx;
#endif 

#if defined WAP_SEC_SUPPORT

typedef enum
{
    BRW_NON_SECURE_SESSION_IN_PROGRESS,
    BRW_SECURE_SESSION_IN_PROGRESS,
    BRW_SESSION_TOTAL
} mmi_brw_secure_session_status_enum;

typedef enum
{
    BRW_CERTIFICATES_NOT_ADDED,
    BRW_CERTIFICATES_ADDED,
    BRW_CERTIFICATES_STATUS_TOTAL
} mmi_brw_certificates_addition_status;

typedef enum
{
    BRW_NOT_WAITING_FOR_CERTIFICATES,
    BRW_WAITING_FOR_CERTIFICATES,
    BRW_WAITING_STATUS_TOTAL
} mmi_brw_is_browser_waiting_for_certificates;

typedef enum
{
    BRW_SELECT_USER_CERTIFICATE_IND_NOT_REPEATED,
    BRW_SELECT_USER_CERTIFICATE_IND_REPEATED,
    BRW_SELECT_USER_CERTIFICATE_IND_STATUS_TOTAL
} mmi_brw_select_user_certificate_ind_status;

typedef struct
{
    kal_uint32 user_cert_trans_id;
    kal_uint32 user_cert_id;
} mmi_brw_user_cert_details_struct;

typedef struct mmi_brw_invalid_certificate_urls_list
{
    JC_CHAR url[MMI_BRW_BKM_MAX_URL_LENGTH *ENCODING_LENGTH];
    struct mmi_brw_invalid_certificate_urls_list *next_url;
} mmi_brw_secure_urls_list_struct;

typedef struct
{
    JC_CHAR issuers_names_file[SSL_MAX_AUTHNAMES_FILE_NAME_SIZE];
    E_SSL_CERT_TYPE cert_types[E_SSL_CERT_TYPE_MAX];
    JC_UINT8 cert_type_count;
} mmi_brw_user_cert_req_struct;

typedef struct
{
    kal_uint32 trans_id;
    mmi_brw_secure_session_status_enum session_status;
    JC_UINT32 server_cert_buf_size;
    CB_BROWSER_REWOKE_SECURITY_HANDLER cbrewokehandler;
    void *cbarg_p;
    mmi_brw_user_cert_details_struct *user_cert_details;
    ST_BROWSER_USER_CERT *user_cert;
    JC_UINT8 *server_cert_buf;
    U8 certificate_url[MMI_BRW_BKM_MAX_URL_LENGTH *ENCODING_LENGTH];
    mmi_brw_certificates_addition_status is_user_certs_added;
    mmi_brw_certificates_addition_status is_root_certs_added;
    mmi_brw_secure_urls_list_struct *secure_urls_list;
    mmi_brw_user_cert_req_struct user_cert_req_details;
    mmi_brw_is_browser_waiting_for_certificates is_browser_waiting_for_certificates;
    mmi_brw_select_user_certificate_ind_status is_select_user_cert_ind_repeated;
} mmi_brw_certificates_ctxt_struct;

extern mmi_brw_certificates_ctxt_struct g_mmi_brw_cert_ctxt;
#endif /* defined WAP_SEC_SUPPORT */ 

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _JBROWSERMMITYPES_H */ 

