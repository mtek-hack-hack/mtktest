/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSAppProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file local API's Variables and the local context for MMS Application
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#ifndef __MMI_UMMS_APP_PROT_H_
#define __MMI_UMMS_APP_PROT_H_

#include "MMI_features.h"

#ifdef __MMI_MMS_2__
#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "app_usedetails.h"
#include "MMSViewerAPPDefs.h"
//#include "FileSystemDef.h"
#include "FileManagerGProt.h"
#include "bam_struct.h"
#include "MMSXMLDef.h"
#define  MAX_PROGRESS_STRING_LENGTH 100
#define  MAX_POSSIBLE_MESSAGES_THRESHOLD  WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG
#define  MAX_POSSIBLE_MESSAGES_MAX        (WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG -1)
#define  MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER   2000
#define  XML_VERSION_TAG                     "</version>"
/* Ashwani Starts */
#define         MMI_UMMS_POPUP_TIME               UI_POPUP_NOTIFYDURATION_TIME_2000
#define         MMI_UMMS_NUM_ADDR_TYPE            3
#define         MMI_UMMS_MAX_URL_LENGTH           WAP_BAM_MAX_URL_LEN
#define         MMI_UMMS_NUM_OPTIONS_LOCK_MODE    2
#define         MMI_UMMS_LOCK_MODE_ON             0x0A
#define         MMI_UMMS_LOCK_MODE_OFF            0x00
/* Ashwani Ends */

#define			UMMS_CONVERT_INDEX			  10
#define			UMMS_MEMSET_BUFFER_1			6
#define			UMMS_MEMSET_BUFFER_2			4

/* Ashwani Ends */
#define   TEMP_BUFFER_SIZE                   14

typedef enum
{
    OPTION_KEY,
    OPTION_OK
} mmi_umms_key_enum;

typedef enum
{
    E_STATE_NONE = 0,
	E_STATE_GET_NUM_REQ_FILE_FORMAT,
    E_STATE_NORMAL_MSG,
    E_STATE_NEW_MSG,
    E_STATE_DOWNLOADED_MSG,
    E_STATE_SEND_MSG,
    E_STATE_SEND_SAVE_MSG,
    E_STATE_DELETE_MSG,
    E_STATE_MOVE_MSG,
    E_STATE_CANCEL_SEND_MSG,
    E_STATE_CANCEL_DOWNLOAD_MSG,
    E_STATE_DOWNLOAD_MSG,
    E_STATE_EDIT_MSG,
    E_STATE_FWD_MSG,
    E_STATE_REPLY_MSG,
    E_STATE_SAVE_MSG,
    E_STATE_DELETE_AFTER_SAVE_SEND,
    E_STATE_DELETE_BEFORE_SEND,
    E_STATE_DELETE_AFTER_SEND,
    E_STATE_SAVE_BEFORE_SEND,
	E_STATE_DELETE_AFTER_NEW_MSG_CREATION,
    E_STATE_SAVE_AFTER_SEND,
    E_STATE_INTR_SEND_MSG,
    E_STATE_GLOBAL_DELETE_ALL_MSG,
    E_STATE_GLOBAL_DELETE_MSG,
    E_STATE_GET_NUM_REQ_INTERMEDATE_MSG,
    E_STATE_GET_NUM_REQ_AT_START_UP,
    E_STATE_GET_NUM_REQ_MSG,
    E_STATE_CANCEL_SEND_AND_DELETE_MSG,
    E_STATE_CANCEL_SEND_AND_DELETE_ALL_MSG,
    E_STATE_CANCEL_DOWNLOAD_MSG_BY_END_KEY,
    E_STATE_NORMAL_MSG_OPTION_KEY,
    E_STATE_SAVE_MMS_FROM_UC,
    E_STATE_GET_CONTENT_MSG,
    E_STATE_SAVE_NEW_MMS,
    E_STATE_CREATE_MSG,
	E_STATE_CANCEL_SEND_AND_DELETE_FOLDER_MSG,
	E_STATE_USB_PLUG_IN,
	E_STATE_SEND_MMS_FROM_UC,
	E_STATE_DELETE_CORRUPT_MSG,
    E_STATE_DD_RR_MSG_STATUS_PROPERTIES,
    E_STATE_DD_RR_MSG_STATUS_VIEW,
	E_STATE_DELETE_WITHOUT_READ,
	E_STATE_DOWNLOAD_IN_CALL_MSG,
    E_STATE_GET_NUM_REQ_FOR_GLOBAL_UPDATE,
    E_STATE_GET_CONTENT_FOR_MSG_INFO,
    E_STATE_DOWNLOAD_FAIL_DUE_TO_CALL,
    E_STATE_DOWNLOAD_AFTER_CALL,
    E_SATE_DOWNLOAD_BEFORE_CALL,
	E_STATE_ALL_MSG_MAX
} umms_state_enum;

typedef enum
{
	UMMS_STATUS_OFF = 0,
    UMMS_STATUS_NEW_MESSAGE,
    UMMS_STATUS_BUSY,
    UMMS_STATUS_FULL,
	UMMS_STATUS_MAX
} mmi_umms_status_icon_type_enum;

typedef enum
{
    UMMS_SEND_VERSION_NONE	= 0x00,
    UMMS_SEND_VESRION_1_0	= 0x10,
	UMMS_SEND_VESRION_1_1	= 0x11,
    UMMS_SEND_VESRION_1_2	= 0x12,
	UMMS_SEND_VERSION_MAX
} mmi_enum_retry_send_verion_enum;

typedef enum
{
    UMMS_SCR_ID_PLEASE_WAIT,
    UMMS_SCR_ID_SENDING,
    UMMS_SCR_ID_DOWNLOADING,
    UMMS_SCR_ID_DELETING_MSG,
    UMMS_SCR_ID_CANCEL_DOWNLOAD_MMS,
	UMMS_SCR_ID_SAVING,
    UMMS_SCR_ID_CANCEL_SEND,
	UMMS_SCR_ID_MAX
} umms_progress_screen_enum;

typedef enum
{
	UMMS_SEND_COUNTER_0,
	UMMS_SEND_COUNTER_1,
	UMMS_SEND_COUNTER_2,
	UMMS_SEND_COUNTER_3,
	UMMS_SEND_COUNTER_MAX
}umms_send_counter_enum;

/* Ashwani Starts */

typedef enum
{
    UMMS_DATA_TYPE_ANSII,
    UMMS_DATA_TYPE_UCS2,
    UMMS_TOTAL_DATA_TYPES
}umms_data_type_enum;

typedef enum
{
    UMMS_FROM,
    UMMS_TO_LIST,
    UMMS_CC_LIST,
    UMMS_BCC_LIST,
    UMMS_ADDR_LIST_TOTAL
}umms_addr_list_enum;


typedef struct
{
    mmi_mv_get_use_details_rsp_struct get_use_details_rsp;
    mmi_mv_get_use_details_enum mms_umms_app_slide;
    U8 applib_addr_type;
} mmi_umms_use_details_struct;

/* Ashwani Ends */

typedef struct
{
	kal_bool no_space;
	U8 g_umms_downloading_busy;
    U8 g_umms_sending_busy;
} mmi_umms_dwnld_send_status_struct;

typedef struct _umms_req_msg_handler_struct
{
    U32 msg_id;
    U32 req_id;
	umms_state_enum current_state;
    mma_folder_enum current_folder;
    struct _umms_req_msg_handler_struct *next;

} umms_req_msg_handler_struct;

typedef struct _umms_download_msg_handler
{
    U32 msg_id;
    U32 req_id;
	U16 retry_counter;
    U8 percent_val;
    umms_state_enum current_state;
    umms_state_enum intermediate_state;
    struct _umms_download_msg_handler *next;
} umms_download_msg_handler_struct;

typedef struct _umms_send_msg_handler
{

    U32 msg_id;
    U32 req_id;
	U32 send_counter;
	U32 old_msg_id;
	U32 retry_version_count;
    U8 xml_file_path[MAX_PROGRESS_STRING_LENGTH*ENCODING_LENGTH];
    kal_wchar to_address[MMA_MAX_ADDR_LEN];
    kal_bool is_send_save;
    kal_bool more_data;
    umms_state_enum current_state;
    umms_state_enum intermediate_state;
    mma_folder_enum current_folder;
    mmi_enum_retry_send_verion_enum retry_version;
    struct _umms_send_msg_handler *next;
} umms_send_msg_handler_struct;

typedef struct
{
	kal_uint32 current_msg_id;
    kal_uint32 msg_size;
    kal_uint32 date;
    kal_uint32 receive_date;
    kal_uint32 expiry_time;
    kal_uint32 msg_index;
    kal_uint32 hilite_index;
	U32	dwnld_size;
	U32 reported_message_id;
	FS_HANDLE file_handle;
	kal_uint16 menu_id;
    kal_uint8 from_address_type;
    kal_uint8 to_address_type;
    kal_uint8 cc_address_type;
    kal_uint8 bcc_address_type;
    kal_uint8 msg_type;
    kal_uint8 rr_dr_status;
    kal_uint8 msg_class;
    kal_uint8 priority;
    kal_uint8 msg_status;
    kal_uint8 app_data[MMA_MAX_APP_DATA_LENGTH];
    kal_wchar from_address[MMA_MAX_ADDR_LEN];
    kal_wchar to_address[MMA_MAX_ADDR_LEN];
    kal_wchar cc_address[MMA_MAX_ADDR_LEN];
    kal_wchar bcc_address[MMA_MAX_ADDR_LEN];
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];
    kal_wchar app_id[MAX_PROGRESS_STRING_LENGTH];
    kal_wchar reply_app_id[MAX_PROGRESS_STRING_LENGTH];
	kal_bool restricted_option;
    kal_bool isRead;
//	kal_bool is_usb_mode;
    kal_bool need_read_report;
    kal_bool isDRM;
    kal_bool isFollowPhoneMMSContentClass;
    kal_bool hasAttachment;
	kal_bool isForwardLock;
    kal_bool isShowProperties;
    U8 obj_drm_type;
    mma_app_mode_enum uc_mode;
    umms_progress_screen_enum progres_screen_id;
    umms_state_enum msg_num_state;
    mma_folder_enum folder_id;
    mmi_umms_key_enum key_type_press;
    mmi_umms_use_details_struct umms_use_details;
    umms_req_msg_handler_struct *g_umms_req_msg_hndlr;
    mmi_mv_object_struct *media_info;
    U16 *virtual_file_name;
	U16 *media_file_path;
    U16 *src_file_name;
    U16 *addr;
    mmi_umms_xml_msg_struct *umms_mms_xml_msg;


} umms_current_selected_info_struct;

typedef struct _mmi_umms_dwnld_send_list
{
    umms_send_msg_handler_struct *g_umms_send_msg_hndlr;
    umms_download_msg_handler_struct *g_umms_dwnld_msg_hndlr;
} mmi_umms_dwnld_send_list;

typedef struct _mmi_umms_message_number_struct
{
    kal_uint32 msg_number_inbox;
    kal_uint32 msg_number_outbox;
    kal_uint32 msg_number_sent;
    kal_uint32 msg_number_drafts;
    kal_uint32 total_number_of_unread_msgs;
	kal_uint32	predefined_template_msg_number;
	kal_uint32	userdefined_template_msg_number;
	kal_uint32	archive_msg_number;
} mmi_umms_message_number_struct;

typedef struct _mmi_umms_new_mms_list
{
    U32 msg_id;
    struct _mmi_umms_new_mms_list *next;
} mmi_umms_new_mms_list;

/* Event Handlers */
extern void mmi_umms_entry_event_handlers(void);

extern void mmi_umms_get_uc_start_rsp(void *inMsg);

/* Inbox Highlight Handlers */
extern void mmi_umms_highlight_view(void);
extern void mmi_umms_highlight_inbox_reply(void);
extern void mmi_umms_highlight_inbox_reply_all(void);
extern void mmi_umms_highlight_forward(void);
extern void mmi_umms_highlight_edit_msg(void);
extern void mmi_umms_highlight_delete_msg(void);
extern void mmi_umms_highlight_delete_all_msg(void);
extern void mmi_umms_highlight_move_to_archive(void);
extern void mmi_umms_highlight_save_objects(void);
extern void mmi_umms_highlight_use_details(void);
extern void mmi_umms_highlight_show_properties(void);
extern void mmi_umms_highlight_inbox_download_msg(void);
extern void mmi_umms_highlight_use_number(void);
extern void mmi_umms_highlight_use_email(void);
extern void mmi_umms_highlight_use_url(void);
extern void mmi_umms_highlight_details_call(void);
extern void mmi_umms_highlight_details_save_to_phbook(void);
extern void mmi_umms_highlight_details_add_to_contact(void);
extern void mmi_umms_highlight_move_to_drafts(void);
extern void mmi_umms_highlight_show_msg_status(void);
extern void mmi_umms_highlight_send_msg(void);
extern void mmi_umms_highlight_delete_msg(void);
extern void mmi_umms_entry_mms_screen(void);
extern void mmi_umms_entry_java_mms_screen(void);
extern void mmi_umms_entry_notification_option_screen(void);
extern void mmi_umms_entry_report_screen(void);
extern void mmi_umms_show_mms_option_screen_according_to_folder_id(void);
extern void mmi_umms_set_current_msg_box(kal_uint16 msg_box_type, U32 msg_id);
extern void mmi_umms_show_properties(void);

/* Ashwani Starts */
extern void mmi_umms_highlight_use_details_current_slide(void);
extern void mmi_umms_highlight_use_details_all_slides(void);
extern void mmi_umms_use_details_list_highlight_hdlr(S32 index);
extern void mmi_umms_highlight_details_go_to_url(void);
extern void mmi_umms_highlight_details_save_as_bookmark(void);
extern void mmi_umms_highlight_use_details_message_header(void);
extern void mmi_umms_highlight_lock_mode(void);
extern void mmi_umms_lock_mode_highlight_hdlr(S32 index);
extern void mmi_umms_highlight_details_send_email(void);
extern void mmi_umms_highlight_details_send_sms(void);
extern void mmi_umms_highlight_details_send_mms(void);

//Ashwani Ends
// Outbox Highlight Handlers
extern void mmi_umms_get_msg_header_info_rsp(void *);
extern void mmi_umms_highlight_send_msg(void);
extern void mmi_umms_highlight_show_msg_status(void);
extern void mmi_umms_get_msg_delete_rsp_dummy(U32 msg_id, U32 req_id);
extern void mmi_umms_check_sending_state(const U32 msg_id, const mma_folder_enum folder_id);
extern void mmi_umms_get_cancel_rsp(  void *inMsg /* U32 msg_id, U32 req_id*/);
extern umms_state_enum mmi_umms_get_state_of_msg_from_all_the_lists(const U32 msg_id,const  U32 req_id);
extern umms_state_enum mmi_umms_get_state_of_msg_from_send_list(const U32 msg_id);
extern void mmi_umms_check_sending_state_of_all_and_update_state(void);
extern void mmi_umms_cancel_download_mms(void);
extern void mmi_uc_cancel_download_mms_by_end_key(void);
extern void mmi_umms_show_java_mms_pop_up(void);
extern void mmi_umms_handle_new_mms(const wap_mma_get_msg_info_rsp_struct *msgRsp, const U32 msg_id);
extern void mmi_umms_enter_java_mms_options(void);
extern void mmi_umms_show_properties_mms(void);
extern void mmi_umms_entry_delete_all_confirmation(void);
extern void mmi_umms_entry_delete_msg_conformation(void);
extern void mmi_umms_send_rsp(void *inMsg);
extern void mmi_umms_get_send_ind(void *inMsg);
extern void mmi_umms_send_mms_rsp_dummy(U32 msg_id, U32 req_id);
extern void mmi_umms_get_memory_status_req(void);
extern void mmi_umms_set_memory_full(const kal_bool memory_status);
extern void mmi_umms_highlight_save_as_template(void);
extern void mmi_umms_delete_all_req(void);
extern void mmi_umms_update_progress_screen(const U32 new_percent_value);
extern void mmi_umms_update_download_msg_hndlr(const U32 msg_id, const U32 req_id, const umms_state_enum updated_state);
extern kal_bool mmi_umms_is_mms_in_send_list(const U32 msg_id);
extern void mmi_umms_show_properties_according_to_box_type(umms_current_selected_info_struct *current_mms_info_list);
extern kal_bool mmi_umms_is_creation_mode_restricted(void);
extern void mmi_umms_entry_edit_fwd_mode(void);
extern void mmi_umms_show_content_mode_confrm_pop_up(void);
extern void mmi_umms_check_sending_state_and_send_cancel_req(const U8 folder_id);

//#ifdef __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__
extern void mmi_umms_enter_restricted_option_screen(void);
extern void mmi_umms_show_mms_option_screen_according_to_folder_id_and_msg_type(void);
//#endif /* __UNIFIED_MESSAGE_LIST_OPTION_SUPPORT__ */ 
extern U32 umms_get_current_utc_time(void);
extern MMI_BOOL umms_end_call_is_download_in_progress(void);
extern MMI_BOOL mmi_umms_is_in_download_list(U32 msg_id);
extern void mmi_umms_show_msg_is_in_use(void);
extern void mmi_umms_pre_entry_download_mms(void);
extern MMI_BOOL mmi_umms_is_option_screen_present(void);
extern void mmi_umms_entry_send_msg_from_box(const U32 msg_id);
extern void mmi_umms_error_in_send_from_uc(void);
extern void mmi_umms_entry_delete_corrupt(void);
extern void mmi_umms_show_corrupt_and_delete(void);
extern void mmi_umms_show_in_creation_process_pop_up(void);
extern void mmi_umms_delete_all_user_def_template_req(void);
extern void mmi_umms_delete_all_user_def_template_rsp(void *inMsg);
extern void mmi_umms_show_um_error_pop_up(U32 result);
extern void mmi_umms_get_content_for_rr_dr_req(U32 msg_id, umms_state_enum current_state);
extern void mmi_umms_get_content_for_rr_dr_rsp(void *inMsg, umms_state_enum current_state);
extern void mmi_umms_get_content_for_msg_info(void *inMsg, umms_state_enum current_state);
extern void *app_decoder_mem_alloc(U32 bytes);
extern void app_decoder_mem_free(void *ptr);
extern void mmi_umms_set_rr_dr_status(U8 status);
extern U8 mmi_umms_get_rr_dr_status(void);
extern void mmi_umms_add_to_new_msg_list(U32 msg_id);
extern void mmi_umms_free_new_msg_handler_list(U32 msg_id);
extern void mmi_umms_free_download_list_msg_id(U32 msg_id);
extern MMI_BOOL mmi_umms_check_downloading_state(void);
extern void mmi_umms_highlight_cancel_send(void);
extern void mmi_umms_reset_xml_struct_msg(mmi_umms_xml_msg_struct *mms_xml_msg);
extern void mmi_umms_entry_send_rr_confirmation(void);
extern void mmi_umms_send_read_mark_for_delete_mms(void);
extern void mmi_umms_dont_send_read_mark_for_delete_mms(void);
extern void mmi_umms_send_read_report_for_delete_mms(void);
extern void mmi_um_umms_highlight_mms_message_ind(void);
extern U8 *mmi_umms_get_to_number(U32 msg_id);
extern U16 mmi_umms_get_total_user_defined_template(void);
extern U8 mmi_umms_get_current_obj_drm_type(void);
extern void mmi_umms_highlight_reply_as_sms(void);
extern void mmi_umms_exit_read_report_screen(void);
extern void mmi_umms_deinit_viewer_and_go_to_box_list(void);
extern void mmi_umms_deinit_viewer_and_globals_and_go_to_box_list(void);
extern void mmi_umms_entry_fwd_edit_confirm_scr(void);
extern void mmi_umms_get_addr_content_by_index(S32 index);
extern S8* mmi_umms_get_addr_content_by_index_for_screen_display(S32 index, U8* type);
extern void mmi_umms_move_to_archive_confirm(void);
extern void mmi_umms_move_to_drafts_confirm(void);

#endif /* __MMI_MMS_2__ */ 

#endif /* __MMI_UMMS_APP_PROT_H_ */ 

