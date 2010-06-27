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
 * mmi_compose.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef _MMI_JMMS_STRUCTS_H
#define _MMI_JMMS_STRUCTS_H

#include "ddlbase.h"
#include "jcerror.h"
#include "jcevent.h"
#include "jcutils.h"
#include "jdd_MMIdatatype.h"

#include "SmsGuiInterfaceType.h"
#include "MessagingDataTypes.h"
#include "PixcomFontengine.h"
#include <ddl.h>
#include <jcal.h>
#include <jcalnet.h>
#include "jdi_wspdatatype.h"
#include "jdi_transport.h"
#include "customer_ps_inc.h"
#include <jdi_communicator.h>

#include "JsrTypes.h"
#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSUseDetails.h"
#include "custom_wap_config.h"
#include "wgui_categories_PE.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 
#ifdef __MMI_UNIFIED_COMPOSER__
#include "UnifiedComposerGProt.h"
#include "JMMSUCXMLProt.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

#ifdef __MMI_UNIFIED_COMPOSER__
#define JMMS_COMPOSE_TEXT_LENGTH       (2048)
#else 
#define JMMS_COMPOSE_TEXT_LENGTH       (612)
#endif 
#define MAX_JMMS_COLOR_NUM             6
#define MAX_JMMS_SLIDE_TIME_DIGITS        3
#define MAX_JMMS_MEDIA_DURATION_DIGITS    3

#define JMMS_POPUP_TIME    UI_POPUP_NOTIFYDURATION_TIME_2000

#define E_COMM_ERROR_INDICATION_EVENT   41
#define MAX_RESPONSE_TEXT_LENGTH    64
typedef void (*error_callback) (JC_RETCODE);
typedef void (*abort_callback) (void);

/* MAUI_00421253 START */
typedef void (*fwd_callback) (void *);

/* MAUI_00421253 END */

typedef void (*MMI_JMMS_JSR_SEND_CALLBACK) (mmi_jsr_result_enum result);
typedef void (*MMI_JMMS_JSR_RETRIEVE_CALLBACK) (void *resp, S8 *buffer, U16 buffer_size);

typedef enum
{
    MEDIA_TEXT,
    MEDIA_IMAGE,
    MEDIA_AUDIO,
    MEDIA_VIDEO,
    MEDIA_OTHER
} mmi_jmms_media_type_enum;

typedef enum
{
    SIZE_SMALL,
    SIZE_NORMAL,
    SIZE_LARGE
} mmi_jmms_text_size_enum;

/* keep this enum synchronized with color list g_jmms_color_RGB_list declared in jmms_gdcl.h */
typedef enum
{
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_RED,
    COLOR_BLUE,
    COLOR_GREEN
} mmi_jmms_color_enum;

typedef enum
{
    JMMS_NOT_INITIALIZED,
    JMMS_INITIALIZING,
    JMMS_INITIALIZED,
    JMMS_TEMPLATES_INITIALIZED,
    JMMS_READY,
    JMMS_READY_WITHOUT_STORE
} mmi_jmms_state_enum;

typedef enum
{
    JMMS_CONFIG_PREVIEW,
    JMMS_CONFIG_VIEW
} mmi_jmms_config_arg_enum;

typedef enum
{
    PRESENTATION_START_STATE,
    PRESENTATION_STOP_STATE,
    PRESENTATION_PLAYING_STATE,
    PRESENTATION_ERR_STATE
} mmi_jmms_presentation_state_enum;

typedef enum
{
    NAVIGATION_STOP_STATE,
    NAVIGATION_PLAYING_STATE
} mmi_jmms_navigation_state_enum;

typedef enum
{
    PAGE_START_STATE,
    PAGE_END_STATE
} mmi_jmms_page_state_enum;

typedef enum
{
    E_MSG_UNKNOWN = 0x00,
    E_MSG_NOTIFICATION,
    E_MSG_RECEIVE,
    E_MSG_DELIVERY_REPORT,
    E_MSG_READ_REPORT,
    E_MSG_JAVA_MESSAGE,
    E_MSG_NEW_MMS_SEND,
    E_MSG_NEW_MMS_TEMPLATES
} mmi_jmms_msg_type_enum;

typedef enum
{
    E_JMMS_WRITE_MMS,
    E_JMMS_INBOX,
    E_JMMS_OUTBOX,
    E_JMMS_DRAFTS,
    E_JMMS_SENT,
    E_JMMS_TEMPLATES
} mmi_jmms_folder_name_enum;

#ifdef __MMI_UNIFIED_MESSAGE__
typedef enum
{
    E_JMMS_PARSE_PENDING = 0x00,
    E_JMMS_ATTACHMENT_PRESENT,
    E_JMMS_ATTACHMENT_NOT_PRESENT
} mmi_jmms_mms_attachment_status_enum;

typedef struct _mmi_jmms_um_jmms_attachment_present_list_struct
{
    S8 index_to_parse;
    struct _mmi_jmms_um_jmms_attachment_present_list_struct *next_p;
} mmi_jmms_um_jmms_attachment_present_list_struct;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

typedef enum
{
    DEFAULT_LAYOUT = 0x00,
    CUSTOM_LAYOUT
} mmi_jmms_creation_layout;

#ifdef __MMI_UNIFIED_COMPOSER__
typedef enum
{
    MMS_SEND_NULL = 0,
    MMS_SENDING_START_CALLBACK,
    MMS_COMMUNICATION_PROGRESS_CALLBACK,
    MMS_SENDING_COMPELETE_CALLBACK,
    MMS_SENDING_ERROR_CALLBACK,
    MMS_COMMUNICATION_STOP_CALLBACK
} mmi_jmms_communication_callback_enumm;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

typedef enum
{
    MMS_INBOX_FOLDER = 0x01,    /* folder ID for Inbox */
    MMS_OUTBOX_FOLDER,          /* folder ID for Outbox */
    MMS_SENT_FOLDER,            /* folder ID for Sent */
    MMS_DRAFTS_FOLDER,          /* folder ID for Drafts */
    MMS_TEMPLATES_FOLDER        /* folder ID for Templates */
} mmi_jmms_folder_info_enum;
typedef struct _mmi_jmms_get_msg_list_queue_event_struct
{

    mmi_jmms_folder_name_enum folder_name;
    U8 total_num_msgs;
} mmi_jmms_get_msg_list_queue_event_struct;

/* PMT VIKAS START 20060325 */
typedef enum
{
    MMS_SIZE_RETRIVE,
    MMS_SIZE_STORE
} mmi_jmms_size_store_get_option;

typedef struct _mmi_jmms_media_time_struct
{
    U32 start_time;
    U32 duration;
} mmi_jmms_media_time_struct;

typedef struct _mmi_jmms_image_info_struct
{
    U8 custom_img_display;
    U8 *file_name_p;
    S32 img_width;
    S32 img_height;
    U32 img_x;
    U32 img_y;
    U32 zoom_in_width;
    U32 zoom_in_height;
    U8 img_delete;  /* sandeep 21Nov added this inorder to fix bug number PMT005940 */
} mmi_jmms_image_info_struct;

typedef struct _mmi_jmms_slide_prop_struct
{
    U32 text_color;
    U32 slide_time;
    stFontAttribute text_font;
} mmi_jmms_slide_prop_struct;

typedef struct _mmi_jmms_context_slide_node_struct
{
    U8 edit_content_buffer[(JMMS_COMPOSE_TEXT_LENGTH + 1) *ENCODING_LENGTH];
    /* text_meida_state_enum        text_state; */
    U32 text_id;
    U32 image_id;
    U32 audio_id;
    U32 video_id;
    mmi_jmms_slide_prop_struct slide_prop;
    mmi_jmms_image_info_struct img_info;

} mmi_jmms_context_slide_node_struct;

typedef struct _mmi_jmms_pending_mms_info_struct
{
    U16 index;
    U8 type;
    S8 *mms_url_p;  /* /valid only for MMS_NOTIFICATION */
    struct _mmi_jmms_pending_mms_info_struct *next_p;
} mmi_jmms_pending_mms_info_struct;

typedef struct _mmi_jmms_pending_mms_delivery_reports_struct
{
    U8 status;
    S8 *to_p;
    JC_UINT32 date;
    struct _mmi_jmms_pending_mms_delivery_reports_struct *next_p;
} mmi_jmms_pending_mms_delivery_reports_struct;

typedef struct _mmi_jmms_pending_mms_read_reports_struct
{
    U8 status;
    S8 *from_p;
    JC_UINT32 date;
    struct _mmi_jmms_pending_mms_read_reports_struct *next_p;
} mmi_jmms_pending_mms_read_reports_struct;

#ifdef __MMI_UNIFIED_COMPOSER__
typedef void (*MMS_COMMUNICATION_CALLBACK) (mmi_jmms_communication_callback_enumm, void *);
#endif 

typedef struct _mmi_jmms_communication_state_node_struct
{
    JC_INT8 *content_type_p;
    JC_CHAR *send_file_name_p;
    JC_CHAR *file_name_p;
    U16 mms_communication_state;
    JDD_FILE file_handle;
    JC_UINT32 reference_id;
    JC_UINT32 reponse_size;
    JC_UINT32 msg_index;
    U8 retry_counter;
    S8 *mms_content_location_p;
    JDD_FSHANDLE fs_handle;
#ifdef __MMI_UNIFIED_COMPOSER__
    MMS_COMMUNICATION_CALLBACK callback;
    U8 percent_sent;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    struct _mmi_jmms_communication_state_node_struct *next_p;
} mmi_jmms_communication_state_node_struct;

typedef struct _mmi_jmms_address_list_struct
{
    S8 *address_p;
    struct _mmi_jmms_address_list_struct *next_p;
} mmi_jmms_address_list_struct;

typedef struct _mmi_jmms_dur_max_info
{
    U8 txt_dur_max_set;
    U8 img_dur_max_set;
    U8 audio_dur_max_set;
    U8 video_dur_max_set;

} mmi_jmms_dur_max_info;

/* structure for msgs list Screen */
typedef struct _mmi_jmms_folder_msgs_list_struct
{
#ifndef __MMI_UNIFIED_MESSAGE__
    S8 *subject_as_caption_p;
    S8 *address_as_hint_p;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    U16 msg_type;
#ifdef __MMI_UNIFIED_MESSAGE__
    U16 msg_index;
    mmi_um_msg_info_struct *um_msg_info_p;
    mmi_jmms_mms_attachment_status_enum attachment_status;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    struct _mmi_jmms_folder_msgs_list_struct *next_p;
} mmi_jmms_folder_msgs_list_struct;

/* structure for inline screens */
typedef struct _mmi_jmms_inline_compose_items_struct
{
    U8 max_num_pages_buffer[(MAX_NO_PAGES_INPUT + 1) *ENCODING_LENGTH];
    U8 defualt_slide_time_buffer[(MAX_DEFAULT_SLIDE_TIME_INPUT + 1) *ENCODING_LENGTH];
    S32 layout;
#ifdef __DRM_SUPPORT__
    S32 add_drm;
#endif 
    S32 creation_mode;
    S32 best_page_duration;
    S32 auto_signature;
    S8 *layout_list[LAYOUT_TOTAL];
    S8 *creation_modes_list[CREATION_MODES_TOTAL];
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    S32 image_resize_option;
    S8 *image_resize_list[IMAGE_RESIZE_TOTAL];
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
} mmi_jmms_inline_compose_items_struct;

typedef struct _mmi_jmms_inline_sending_items_struct
{
    /* /new */
    S32 validity_period;
    S32 delivery_report;
    S32 read_report;
    S32 priority;
    S32 delivery_time;
    S32 reply_charging;
    S32 request_type;
    S32 hide_sender;

    S8 *validity_period_list[VALIDITY_PERIOD_TOTAL];
    S8 *priority_list[PRIORITY_TOTAL];
    S8 *delivery_time_list[DELIEVERY_TOTAL];
    S8 *reply_charging_request_list[REPLY_CHARGING_TYPE_TOTAL];
    U8 deadline_for_reply_buffer[(MAX_DEADLINE_TIME_VALUE_INPUT + 1) *ENCODING_LENGTH];
    U8 reply_msg_size_buffer[(MAX_REPLY_CHARGE_SIZE_INPUT + 1) *ENCODING_LENGTH];
} mmi_jmms_inline_sending_items_struct;

typedef struct _mmi_jmms_inline_retrieval_items_struct
{
    S32 home_network;
    S32 roaming;
    S32 anonymous_filter;
    S32 advertisement_filter;
    S32 read_report;
    S32 delivery_report;

    S8 *home_network_list[HOME_NETWORK_TOTAL - 1];
    S8 *roaming_list[ROAMING_TOTAL];
    S8 *read_report_list[READ_REPORT_SEND_TOTAL];
    U8 msg_size_filter_buffer[(MAX_FILTER_MSG_SIZE_INPUT + 1) *ENCODING_LENGTH];
} mmi_jmms_inline_retrieval_items_struct;

typedef struct _mmi_jmms_edit_content_text_settings_struct
{
    U32 size_selected;
    U32 italic_selected;
    U32 bold_selected;
    U32 color_selected;
    S8 *size_list[3];
    S8 *color_list[MAX_JMMS_COLOR_NUM];
} mmi_jmms_edit_content_text_settings_struct;

typedef struct _mmi_jmms_edit_content_smil_settings_struct
{
    S32 duration_select;
    U8 slide_time_edit_buffer[(MAX_JMMS_SLIDE_TIME_DIGITS + 1) *ENCODING_LENGTH];
    U8 media_duration_edit_buffer[(MAX_JMMS_MEDIA_DURATION_DIGITS + 1) *ENCODING_LENGTH];
    U8 media_duration_edit_temp_buffer[(MAX_JMMS_MEDIA_DURATION_DIGITS + 1) *ENCODING_LENGTH];
    U8 media_duration_edit_done_buffer[(MAX_JMMS_MEDIA_DURATION_DIGITS + 1) *ENCODING_LENGTH];
} mmi_jmms_edit_content_smil_settings_struct;

typedef union _mmi_jmms_setings_inline_items_union
{
    mmi_jmms_inline_compose_items_struct compose_items_list;
    mmi_jmms_inline_sending_items_struct sending_items_list;
    mmi_jmms_inline_retrieval_items_struct retrieval_items_list;
    mmi_jmms_edit_content_text_settings_struct text_settings_items;
    mmi_jmms_edit_content_smil_settings_struct smil_settings_items;
} mmi_jmms_setings_inline_items_union;

typedef struct _mmi_jmms_common_inline_lists_struct
{
    S8 *allow_reject_list[2];
    S8 *on_off_list[2];
} mmi_jmms_common_inline_lists_struct;

/* /manish for test */

typedef struct _mmi_jmms_compose_context_struct
{
    U8 curr_page_index;
    U8 from_jmms_app;
    U8 is_image_first[WAP_CUSTOM_CFG_MAX_MMS_SLIDES];
    U8 exit_conpose_screen;
    S8 *media_path_p;
    mmi_jmms_media_type_enum media_type;
    JC_INT32 mms_bg_color;
    mmi_jmms_dur_max_info duration[WAP_CUSTOM_CFG_MAX_MMS_SLIDES];      /* deepali: needs to be set equal to max slide macro */
    mmi_jmms_context_slide_node_struct curr_slide_info;

} mmi_jmms_compose_context_struct;

typedef struct _mmi_jmms_view_context_struct
{
    U8 curr_sliding_bar_status;
    U8 focus_object_type;
    mmi_jmms_presentation_state_enum curr_view_state;
    mmi_jmms_page_state_enum curr_page_view_state;
    U32 slide_time_elapsed;
    U32 curr_view_page_duration;
    U32 jdd_view_window_id;
    U32 is_curr_view_screen;
    U32 view_config_arg;
    U32 view_parent_menu_id;
    U32 view_audio_id;
    U32 view_video_id;
    U32 view_navigate_state;

} mmi_jmms_view_context_struct;

typedef struct _mmi_jmms_store_context_struct
{
    U8 num_msg_in_curr_folder;
    U8 update_nmsgs_in_current_folder;
    JC_UINT32 jmms_start_index;
    mmi_jmms_folder_msgs_list_struct *messages_list;
    mmi_jmms_folder_name_enum current_folder_name;
    U8 *inbox_msgs_read_status;

} mmi_jmms_store_context_struct;

typedef struct _mmi_jmms_async_callback_list_struct
{
    error_callback err_cb;
    struct _mmi_jmms_async_callback_list_struct *next_p;
} mmi_jmms_async_callback_list_struct;

/******************************************************************************
  Writer : Raj Kumar Gupta
  Date   : 08 June 2006 
 *****************************************************************************/
typedef struct _mmi_jmms_async_save_params_struct
{
    S8 folder_name_p[20];
    MMI_BOOL is_store_update;
    JC_UINT32 msg_index;
    MSG_HANDLE msg_handle;
} mmi_jmms_async_save_params_struct;

typedef struct _mmi_jmms_async_send_params_struct
{
    U8 retry_counter;
    JC_BOOLEAN is_stream;
    MSG_HANDLE msg_handle;
    U16 comm_state;
} mmi_jmms_async_send_params_struct;

typedef struct _mmi_jmms_async_parse_context_struct
{
    error_callback callback;
    abort_callback abort_cb;
    S32 is_re_entrant;
    MSG_HANDLE msg_handle;
} mmi_jmms_async_parse_context_struct;

typedef struct _mmi_jmms_async_encapsulate_context_struct
{
    MSG_HANDLE msg_handle;
    mmi_jmms_async_callback_list_struct *callback_list;
    mmi_jmms_async_send_params_struct *params;
} mmi_jmms_async_encapsulate_context_struct;

typedef struct _mmi_jmms_async_save_context_struct
{
    MSG_HANDLE msg_handle;
    mmi_jmms_async_callback_list_struct *callback_list;
    mmi_jmms_async_save_params_struct *params;
} mmi_jmms_async_save_context_struct;

/* MAUI_00227929 Start */
typedef struct _mmi_jmms_sending_items_struct
{
    /* /new */
    S32 validity_period;
    S32 delivery_report;
    S32 read_report;
    S32 priority;
    S32 delivery_time;
    S32 reply_charging;
    S32 request_type;
    S32 hide_sender;

    U8 deadline_for_reply_buffer[(MAX_DEADLINE_TIME_VALUE_INPUT + 1) *ENCODING_LENGTH];
    U8 reply_msg_size_buffer[(MAX_REPLY_CHARGE_SIZE_INPUT + 1) *ENCODING_LENGTH];
} mmi_jmms_sending_items_struct;

/* MAUI_00227929 End */

#ifdef __MMI_UNIFIED_COMPOSER__
typedef struct
{
    MSG_HANDLE msg_handle;
    mmi_jmms_communication_state_node_struct *communication_handle_p;
} mmi_jmms_uc_start_comm_struct;

typedef struct
{
    COMM_PROGRESS_IND *progress_ind_p;
    mmi_jmms_communication_state_node_struct *communication_handle_p;
} mmi_jmms_comm_progress_struct;

typedef struct
{
    mmi_jmms_communication_state_node_struct *communication_handle_p;
    JC_BOOLEAN result;
    JC_RETCODE error_code;
#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    JC_CHAR response_text[MAX_RESPONSE_TEXT_LENGTH];
#endif 
} mmi_jmms_uc_sending_complete_struct;

typedef struct
{
    JC_RETCODE error_code;
    mmi_jmms_communication_state_node_struct *communication_handle_p;
} mmi_jmms_uc_error_struct;

typedef struct
{
    mmi_jmms_communication_state_node_struct *communication_handle_p;
    JC_RETCODE retCode;
    JC_UINT32 msg_id;
} mmi_jmms_communication_stop_struct;

typedef struct _jmms_sending_list_struct
{
    JC_UINT32 msg_id;
    MSG_HANDLE msg_handle;
    mmi_jmms_communication_state_node_struct *communication_handle_p;
    struct _jmms_sending_list_struct *next;
} mmi_jmms_sending_list_struct;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

/*****************************************************************************/
typedef struct
{
    U8 is_usb_mode;
    U8 is_add_media_warning;
    U8 is_unread_msg_deleted;
    U8 num_total_addresses;
    U8 num_to_addresses;
    U8 num_cc_addresses;
    U8 num_bcc_addresses;
    U8 sent_retry_counter;
    U8 curr_focused_media_type;
    U8 curr_scr_hilited_index;
    U8 init_done;
    U8 num_attachments;
    U8 is_in_format_mode;
    U8 *activated_mmsc_url_p;
    U8 subject_input_buffer[(MAX_SUBJECT_LENGTH + 1) *ENCODING_LENGTH];
    S8 *last_mmsc_url;
    S8 last_version[(MAX_VERSION_LENGTH + 1)];
    S8 *to_p;
    S8 *cc_p;
    S8 *bcc_p;
    S8 *from_p;
    S8 *version;
    S8 *subject_p;
    JC_CHAR *orig_file_name_replace_mms;
    JC_INT8 *transaction_id_p;
    U16 last_scr_id;
    U32 msg_open_status[2];
    U16 address_list_flag;
    MMI_BOOL save_mms;
    U32 curr_scr_hilite_index;
    U32 curr_roaming_state;
    JC_UINT32 reference_id;
    JC_UINT32 mms_index;
    void *msg_headers_p;
    void *msg_header_type_p;
    MSG_HANDLE msg_handle;
    STORE_HANDLE store_handle;
    COMM_HANDLE comm_handle;
    JDD_FSHANDLE jmms_fs_handle;
    mmi_jmms_compose_context_struct *compose_context;
    mmi_jmms_view_context_struct *view_context;
    mmi_jmms_store_context_struct *store_context;
    mmi_jmms_address_list_struct *to_address_p;
    mmi_jmms_address_list_struct *cc_address_p;
    mmi_jmms_address_list_struct *bcc_address_p;
    mmi_jmms_address_list_struct *from_address_p;
    mmi_jmms_pending_mms_info_struct *pending_mms_info_list;
    mmi_jmms_pending_mms_delivery_reports_struct *pending_delivery_reports;
    mmi_jmms_pending_mms_read_reports_struct *pending_read_reports;
    mmi_jmms_communication_state_node_struct *comm_state_p;
    REPLY_CHARGE_LIMITS *rc_info;

#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
    MM1_HANDLE mm1_handle;
    MMI_JMMS_JSR_SEND_CALLBACK jsr_mms_send_callback;
    MMI_JMMS_JSR_SEND_CALLBACK jsr_mms_send_cancel_callback;
    MMI_JMMS_JSR_RETRIEVE_CALLBACK jsr_mms_receive_callback;

    JC_UINT32 jsr_total_object;
    JC_UINT32 media_obj_index;
#endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 
    // #ifdef __MMI_MMS_SIGNATURE__
    MMI_BOOL fw_from_inbox;
    MMI_BOOL auto_signature_added;
    // #endif /* __MMI_MMS_SIGNATURE__ */
    MMI_BOOL message_to_fw;
    mmi_jmms_common_inline_lists_struct *jmms_inline_lists;
    mmi_jmms_setings_inline_items_union jmms_inline_items;
    U16 progress_screen_title;
    S8 g_jmms_progress_str[MAX_PROGRESS_SCREEN_HINT_LEN *ENCODING_LENGTH];
    U16 g_write_mms_right_soft_key;
    U8 g_use_local_send_setings;
    S8 g_jmms_to_caption_buff[(MAX_RECIPIENTS_CAPTION_LENGTH + 1) *ENCODING_LENGTH];
    S8 g_jmms_cc_caption_buff[(MAX_RECIPIENTS_CAPTION_LENGTH + 1) *ENCODING_LENGTH];
    S8 g_jmms_bcc_caption_buff[(MAX_RECIPIENTS_CAPTION_LENGTH + 1) *ENCODING_LENGTH];
    S8 g_jmms_files_caption_buff[(MAX_FILES_CAPTION_LENGTH + 1) *ENCODING_LENGTH];
    S8 g_jmms_slide_caption_buff[(MAX_SLIDES_CAPTION_LENGTH + 1) *ENCODING_LENGTH];
    U8 g_jmms_add_number_buffer[(MAX_POSSIBLE_NUMBER_LENGHT_SENT + 1) *ENCODING_LENGTH];
    U8 g_jmms_add_email_buffer[(MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1) *ENCODING_LENGTH];
    U16 email_buff[MAX_POSSIBLE_EMAIL_LENGHT_SENT + 1];
    MESSAGE_NOTIFICATION *notification_p;
    MESSAGE_RETRIEVAL *retrieval_p;
    DELIVERY_REPORT *delivery_p;
    READ_REPORT_RESPONSE *read_report_p;
    MESSAGE_SEND *send_msg_p;
    mmi_jmms_async_parse_context_struct async_parse_context;
    mmi_jmms_async_encapsulate_context_struct async_send_context;
    mmi_jmms_async_save_context_struct async_save_context;
    CONTENT_DATA *send_content_p;
    CONTENT_DATA *save_content_p;
    CONTENT_DATA *parse_content_p;
    jmms_nvram_compose_settings_struct nvram_compose_settings;
    jmms_nvram_sending_settings_struct nvram_sending_settings;
    jmms_retrieval_settings_struct nvram_retrieval_settings;
#ifdef __MMI_UNIFIED_MESSAGE__
    MMI_BOOL show_property_screen;
    mmi_jmms_um_jmms_attachment_present_list_struct *g_attachment_pending_list;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    MMI_BOOL disable_warning_popup;
    mmi_jmms_creation_layout layout;
    JC_RETCODE edit_error_code;
    JC_CHAR *content_fname;
    JC_CHAR *filename;
    mmi_jmms_sending_items_struct sending_settings;
    S32 progress_screen_in_history;
    fwd_callback content_fwd_callback;
    void *content_fwd_callback_param;
    MMI_BOOL is_at_delete_mms;
    S32 is_in_ready_without_store_init_mode;
    FuncPtr g_template_complete_callback;
    MMI_BOOL g_show_popup;
    U8 *g_media_buffer_p;
    U16 interupt_screen_title;
#ifdef __MMI_UNIFIED_COMPOSER__
    MMS_COMMUNICATION_CALLBACK ext_cb;
    mmi_jmms_sending_list_struct *send_node_list;
    jmms_uc_xml_parser_context_struct decoder;
    mmi_uc_msg_struct *uc_xml_msg_p;
    void *uc_req_rsp_info_holder_p;
    S32 uc_creation_mode;
    U32 uc_cancel_req_id;
    U32 mms_header_size;
    U32 mms_body_size;
    U32 uc_msg_parsing;
    U32 uc_creation_req;
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    S32 saved_mms_id;
    U8 g_mms_downloading_busy;
    U64 g_jmms_normal_msgid;
    U64 g_jmms_java_msgid;

    U16 g_address_option_index;
    U16 g_address_list_right_soft_key;
    U8 g_hilite_address_item;
    jmms_use_details_struct g_jmms_use_details;
    jmms_send_settings_entry_control_enum g_jmms_control;
    U8 g_reply_charging_done;
    U8 g_recieve_filter_done;
    U16 resize_animation_disable_status;
    U8 g_custom_color_RGB_list[3];
    U32 g_text_custom_color_rgb;
    U32 g_bg_custom_color_rgb;
    U8 g_custom_var_change;
    mmi_cat91_color_slider_enum g_slider_info;
    U8 gtemplate_count;
    U8 *property_display_buffer_p;
    MMI_BOOL is_add_media_as_drm;
    FuncPtr add_media_hdlr;
    FuncPtr end_key_processing_handler;
    JC_UINT32 msg_id;
    U16 current_title_id;
#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
    JC_UINT32 g_reference_id;
    S8 send_status;
#endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 
#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
    JC_CHAR response_text[MAX_RESPONSE_TEXT_LENGTH];
#endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */
} mmi_jmms_context_struct;

typedef struct _mmi_jmms_temp_event_struct
{
    mmi_jmms_context_struct *jmms_context_p;
    JC_UINT32 reference_id;
    JC_RETCODE ret_code;
} mmi_jmms_temp_event_struct;

#endif /* _MMI_JMMS_STRUCTS_H */ 

