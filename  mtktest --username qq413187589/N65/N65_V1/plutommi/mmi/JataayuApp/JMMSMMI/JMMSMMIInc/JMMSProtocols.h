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
 *  JMMSProtocols.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * This file contans the enums,constants,structures, function prototypes used in
 * jmms_sent.c
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSPROTCOLS_H
#define __MMI_JMMSPROTCOLS_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

#include "ddl.h"
#include "jcal.h"
#include "jcalnet.h"
#include "jdi_wspdatatype.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "mmsadp.h"
#endif 

//#include "jdi_transport.h"
//#include "transport.h"

//#include <jdi_miscutils.h>
//#include <jdi_communicator.h>

/* 
 * Define
 */
#define MAX_NUMBER_OF_EVENTS_IN_MMS_QUEUE 150

#define E_MSG_TYPE_IDLE_SCREEN_POP_UP 100

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
#define E_MSG_TYPE_IDLE_SCREEN_POP_UP_WITH_TEXT_BUFFER 101
#endif 

#define MAX_TITLE_LENGTH 32

#define MMI_JMMS_SEND_TIMEOUT_TIME 20000

#define TIMER_RESPONSE_BIT 1

#define MAX_RETRIES 3
/* 
 * Typedef 
 */
typedef enum
{
    E_FROM_URL_CALLBACK = 0x01,
    E_FROM_ERROR_CALLBACK
} mmi_jmms_retry_calling_function;

typedef enum
{
    MMS_STATUS_OFF = 0,
    MMS_STATUS_NEW_MESSAGE,
    MMS_STATUS_BUSY,
    MMS_STATUS_FULL
} mmi_jmms_status_icon_type_enum;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

/*  */

/* /for test */
extern U8 *mmi_jmms_get_activated_mmsc_url(mmi_jmms_context_struct *jmms_context);
extern void mmi_jmms_push_ind_callback(void *pCommArg, COMM_PUSH_IND *pPushContentInd);
extern JC_RETCODE mmi_jmms_init_protocol(void);
extern JC_RETCODE mmi_jmms_url_ind_callback(
                    mmi_jmms_context_struct *jmms_context,
                    COMM_FETCH_URL_IND_RESP *URL_ind_p);
extern JC_RETCODE mmi_jmms_header_ind_callback(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_HEADER_INDICATION *comm_header_ind_p);

extern void mmi_jmms_progress_ind_callback(
                mmi_jmms_context_struct *jmms_context_p,
                JC_UINT32 ui_reference_id,
                COMM_PROGRESS_IND *progress_ind_p);

extern void mmi_jmms_error_ind_callback(
                mmi_jmms_context_struct *jmms_context_p,
                JC_UINT32 ui_reference_id,
                JC_RETCODE ret_code);

extern void mmi_jmms_get_ip_address(U8 *ip_address_p, U8 *proxy_ip_p);
extern void mmi_jmms_free_mms_pdu_memory(mmi_jmms_context_struct *jmms_context_p);
extern JC_RETCODE mmi_jmms_create_and_send_new_mms(
                    U16 message_setting,
                    mmi_jmms_context_struct *jmms_context_p,
                    MMI_BOOL is_create_for_send);

extern JC_RETCODE mmi_jmms_send_mms(MSG_HANDLE h_msg_handle,
                                    U16 comm_state, JC_BOOLEAN is_stream, U8 retry_counter, JC_BOOLEAN is_asynch
#ifdef __MMI_UNIFIED_COMPOSER__
                                    , MMS_COMMUNICATION_CALLBACK communication_cb
#endif 
    );
extern JC_RETCODE mmi_jmms_send_synchronous_mms(
                    MSG_HANDLE h_msg_handle,
                    U16 comm_state,
                    JC_BOOLEAN is_stream,
                    U8 retry_counter,
                    JC_BOOLEAN is_asynch,
                    U32 *unique_id_p);

extern void mmi_jmms_update_mmsc_url_version(S8 *mmsc_url_used_p, S8 *mmsc_version_p);

extern void mmi_jmms_entry_communication_progress_screen(void);

#ifdef __MMI_UNIFIED_COMPOSER__
extern JC_RETCODE mmi_jmms_cancel_mms_sending(
                    MSG_HANDLE msg_handle,
                    mmi_jmms_communication_state_node_struct *communication_handle);
extern void mmi_jmms_cancel_all_mms_sending(void);
#else /* __MMI_UNIFIED_COMPOSER__ */ 
extern void mmi_jmms_cancel_mms_sending(void);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

extern void mmi_jmms_end_comm(void);

extern void mmi_jmms_comm_stop_callback(
                mmi_jmms_context_struct *jmms_context_p,
                JC_UINT32 ui_reference_id,
                JC_RETCODE ret_code);

extern JC_RETCODE mmi_jmms_add_pending_mms_info_node(U16 msg_index, U8 msg_type, S8 *content_location_p);
extern void mmi_jmms_show_new_mms_pop_up(void);

extern JC_RETCODE mmi_jmms_add_pending_mms_delivery_report_node(U8 status, S8 *to_address_p, JC_UINT32 date);
extern JC_RETCODE mmi_jmms_add_pending_mms_read_report_node(U8 status, S8 *from_address_p, JC_UINT32 date);
extern JC_RETCODE mmi_jmms_retry_communication(
                    mmi_jmms_context_struct *jmms_context_p,
                    U16 calling_function,
                    JC_UINT32 ui_reference_id,
                    JC_RETCODE error_code);

extern JC_RETCODE mmi_jmms_set_mmsc_version(void);

extern JC_RETCODE mmi_jmms_handle_notification_ack_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *Content_p);
extern JC_RETCODE mmi_jmms_handle_read_report_pdu_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *Content_p);
extern JC_RETCODE mmi_jmms_handle_read_report_mms_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *Content_p);
extern JC_RETCODE mmi_jmms_handle_immediate_downlaod_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *content_p);
extern JC_RETCODE mmi_jmms_handle_deffered_downlaod_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *content_p);
extern JC_RETCODE mmi_jmms_handle_new_mms_send_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *content_p);

extern mmi_jmms_communication_state_node_struct *mmi_jmms_get_comm_state(
                                                    mmi_jmms_context_struct *jmms_context_p,
                                                    JC_UINT32 ui_reference_id);
extern JC_RETCODE mmi_jmms_add_comm_node(mmi_jmms_context_struct *jmms_context_p,
                                         JC_UINT32 ui_reference_id,
                                         U16 comm_state,
                                         JC_CHAR *file_name_for_send_p,
                                         JC_UINT32 msg_index, U8 retry_counter, S8 *content_location_p
#ifdef __MMI_UNIFIED_COMPOSER__
                                         , MMS_COMMUNICATION_CALLBACK communication_cb
#endif 
    );

extern JC_RETCODE mmi_jmms_update_comm_node(
                    mmi_jmms_context_struct *jmms_context_p,
                    JC_UINT32 new_ui_reference_id,
                    JC_UINT32 old_ui_reference_id,
                    U8 retry_counter);

extern void mmi_jmms_free_comm_node(mmi_jmms_context_struct *jmms_context_p, JC_UINT32 ui_reference_id);

extern void mmi_jmms_handle_error_in_communication(
                mmi_jmms_context_struct *jmms_context_p,
                U16 calling_function,
                mmi_jmms_communication_state_node_struct *comm_node,
                JC_RETCODE error_code);
extern JC_RETCODE mmi_jmms_handle_url_repsonse(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA content);

extern void mmi_jmms_handle_read_report(MESSAGE_RETRIEVAL *msg_retrieval_p);

extern void mmi_jmms_free_message_header(void);

extern void mmi_jmms_handle_error_string(JC_RETCODE error_code, U16 communication_state);

extern JC_RETCODE mmi_jmms_resend_mms(mmi_jmms_communication_state_node_struct *comm_node_p, U8 retry_counter);

/* PMT VIKAS START 20060401 */
extern void mmi_jmms_update_status_icon_indicator(void);
extern void mmi_jmms_set_mms_downloading_busy(void);
extern void mmi_jmms_reset_mms_downloading_busy(void);
extern U8 mmi_jmms_is_download_busy(void);
extern void mmi_jmms_show_mms_status_icon(mmi_jmms_status_icon_type_enum status);

extern void mmi_jmms_free_pending_node_if_present(U32 msg_index);

//PMT HIMANSHU START 20060425
//MMI_BOOL mmi_jmms_is_msg_open(S8 *fname,U32 msg_index);
extern MMI_BOOL mmi_jmms_is_msg_open(S8 *fname_p, U32 msgId, U32 msg_index);

/* PMT HIMANSHU END 20060425 */
extern void mmi_jmms_check_for_idle_screen(void);
extern void mmi_jmms_handle_pop_up_for_interupt(U16 strid);

extern void mmi_jmms_entry_general_pop_screen_in_case_interupt(void);

extern void mmi_jmms_end_key_downlaod_sucess_pop_screen(void);
extern void mmi_jmms_back_msg_download_sucess(void);

extern void mmi_jmms_remove_memory_full_node_if_present(void);
extern void mmi_jmms_add_memory_full_node_if_not_already(void);

extern void mmi_jmms_comm_time_hdlr(void);

extern S8 *mmi_jmms_get_em_mms_version(void);

extern void mmi_jmms_send_mms_async_callback(JC_RETCODE ret_code);

extern void mmi_jmms_free_comm_node_list(void);
extern void mmi_jmms_cancel_comm_in_usb_mode(void);
extern S32 mmi_jmms_is_immediate_retrival_underway(void);

/******************************************************************************
 Written By : Raj Kumar Gupta
 Date       : 09 June 2006
 *****************************************************************************/
extern void mmi_jmms_send_drafts_sent_callback(JC_RETCODE ret_code);
extern void mmi_jmms_create_and_send_new_mms_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_handle_new_mms_send_response_asynch_callback(JC_RETCODE ret_code);
extern JC_RETCODE mmi_jmms_update_pending_downloads(JC_UINT32 msg_index);
extern JC_BOOLEAN mmi_jmms_is_call_active(void);

extern void mmi_jmms_stop_download_busy(void);

/* PMT VIKAS END 20060401 */
#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
/* void mmi_jmms_jsr_mms_send_response(mmi_jmms_context_struct *jmms_context,COMM_FETCH_URL_IND_RESP        *pURLInd); */
extern JC_RETCODE mmi_jmms_jsr_mms_send_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA content);

/* callbacks for UC */
#ifdef __MMI_UNIFIED_COMPOSER__
extern void mmi_jmms_handle_screen_flow_callback(mmi_jmms_communication_callback_enumm cb_type, void *data);
extern void mmi_jmms_handle_stop_communication(
                mmi_jmms_communication_state_node_struct *comm_node,
                JC_RETCODE eRetCode);
extern void mmi_jmms_handle_progress_ind(
                COMM_PROGRESS_IND *pProgressInd,
                mmi_jmms_communication_state_node_struct *communication_handle);
extern mma_result_enum mmi_jmms_get_error_type(JC_RETCODE error_code);
extern U8 *mmi_jmms_get_error_string(JC_RETCODE error_code);
extern JC_RETCODE mmi_jmms_uc_handle_new_mms_send_response(
                    mmi_jmms_context_struct *jmms_context_p,
                    COMM_FETCH_URL_IND_RESP *url_ind_p,
                    CONTENT_DATA *content_data);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 

extern U8 *mmi_jmms_get_activated_mmsc_url(mmi_jmms_context_struct *jmms_context);
extern S8 *mmi_jmms_get_mms_profile_user_name(void);
extern S8 *mmi_jmms_get_mms_profile_password(void);
#endif /* __MMI_JMMS_JAVA_MMS_SUPPORT__ */ 

#ifdef __MMI_JMMS_SEND_RETRIES__
extern void mmi_jmms_change_title_string(U16 str_id, U8 retry_counter);
#endif 

#ifdef __MMI_JMMS_RESPONSE_TIMEOUT__
extern void mmi_jmms_send_timeout_timer_hdlr(void);
extern void mmi_jmms_stop_timeout_timer(void);
#endif /* __MMI_JMMS_RESPONSE_TIMEOUT__ */ 
extern void mmi_jmms_show_mms_send_response(JC_UINT32 reference_id);

#ifdef __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__
extern void mmi_jmms_free_pop_up_memory(void);
extern void mmi_jmms_entry_general_pop_string_in_case_interupt(void);
extern void mmi_jmms_handle_pop_up_for_interupt_string(JC_CHAR *buffer_string);
#endif /* __MMI_JMMS_REQUEST_STATUS_TEXT_DISPLAY__ */ 
extern void mmi_jmms_set_progress_screen_title(U16 strid);
extern MMI_BOOL mmi_jmms_is_notifiction_in_use(U16 msg_index);
#endif /* __MMI_JMMSPROTCOLS_H */ 

