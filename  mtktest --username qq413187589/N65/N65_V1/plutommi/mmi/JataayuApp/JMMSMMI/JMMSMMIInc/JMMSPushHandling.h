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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  JMMSPushHandling.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_store_handling.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSPUSHHANDLING_H
#define __MMI_JMMSPUSHHANDLING_H

#include "JMMSStructs.h"

/* 
 * Define
 */

#define MAX_MMS_SEND_TRY_COUNTER  wap_custom_get_max_mms_post_msg_retry_nums()
#define MAX_MMS_SIGNAL_TRY_COUNTER wap_custom_get_max_mms_post_pdu_retry_nums()
#define MAX_MMS_DOWNLOAD_TRY_COUNTER wap_custom_get_max_mms_get_retry_nums()
#define STOP_RETRY_COUNTER  MAX_MMS_SEND_TRY_COUNTER+MAX_MMS_SIGNAL_TRY_COUNTER+MAX_MMS_DOWNLOAD_TRY_COUNTER

/* 
 * Typedef 
 */
typedef enum
{
    E_TYPE_NULL,
    E_TYPE_NEW_MMS,
    E_TYPE_NOTIFICATION_RESPONSE,
    E_TYPE_IMMEDIATE_RETRIEVAL_FETCH,
    E_TYPE_DEFFERED_RETRIEVAL_FETCH,
    /* E_TYPE_JAVA_MMS_DOWNLAOD, */
    E_TYPE_NEW_JAVA_MMS_SEND,
    E_TYPE_ACK_RESPONSE,
    E_TYPE_READ_REPORT_PDU,
    E_TYPE_READ_REPORT_MMS
} jmms_message_state_enum;

typedef enum
{
    E_JMMS_RETRY_COMPLETE = 2,
    E_UNKNOWN_MSG = 30,
    E_JMMS_GENERAL_ERROR,
    E_JMMS_STORAGE_FULL
} jmms_message_protocol_errors;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

//void mmi_jmms_handle_new_mms_notification(VIEW_CONTENT view_content,MSG_HANDLE        hMsgHandle,MESSAGE_NOTIFICATION *pNotifyIndHdrs);
//JC_RETCODE mmi_jmms_download_mms(JC_INT8 *content_location);
//JC_RETCODE mmi_jmms_notification_reponse(MESSAGE_NOTIFICATION *pNotification, EMessageStatus eMessageStatus);
//JC_RETCODE jmms_mmi_notification_response_for_immediate_retrieval(COMM_FETCH_URL_IND_RESP     *pFetchData);

/* void mmi_jmms_show_new_mms_retrieved(COMM_FETCH_URL_IND_RESP *pURLInd); */
extern void mmi_jmms_entry_show_mms_screen(void);
extern void mmi_jmms_back_msg_view_entry(void);

extern U8 mmi_jmms_need_mms_ind(void);
extern void mmi_jmms_entry_new_mms_ind(void);

extern void mmi_jmms_end_mms_play(void);
extern void mmi_jmms_play_mms(void);
extern void mmi_jmms_delete_mms_pop_up_node(void);
extern void mmi_jmms_handle_mms_pop_up(void);
extern void mmi_jmms_delete_mms_pop_ups_list(void);

extern void mmi_jmms_entry_show_delivery_report_screen(void);

//JC_RETCODE jmms_mmi_ack_for_deffered_retrieval(VIEW_CONTENT   Content);
//JC_RETCODE mmi_jmms_handle_deffered_retrieved_mms(VIEW_CONTENT        Content);
extern void mmi_jmms_show_read_report_query_screen(void);

/* MYTIME mmi_jmms_convert_date_to_mytime(U32 timestamp); */
extern void mmi_jmms_free_pending_mms_info_node(void);
extern void mmi_jmms_entry_show_read_report_screen(void);
extern void mmi_jmms_handle_read_report_confirm(void);
extern void mmi_jmms_create_and_send_read_report(void);

extern void mmi_jmms_free_mms_pop_ups_list(void);
extern void mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry(void);

extern JC_RETCODE mmi_jmms_set_read_reply_message(
                    MSG_HANDLE *h_msg_handle_p,
                    JC_INT8 *message_id_p,
                    JC_CHAR *to_address_p,
                    JC_CHAR *subject_p);
extern JC_RETCODE mmi_jmms_set_read_reply_pdu(
                    MSG_HANDLE *h_msg_handle_p,
                    JC_INT8 *message_id_p,
                    JC_CHAR *to_address_p,
                    JC_INT8 *version_p);
extern JC_RETCODE mmi_jmms_download_mms(JC_INT8 *content_location_p,
                                        U16 comm_state, JC_UINT32 msg_index, U8 retry_counter
#ifdef __MMI_UNIFIED_COMPOSER__
                                        , MMS_COMMUNICATION_CALLBACK communication_cb
#endif 
    );
extern void mmi_jmms_handle_new_mms_notification(
                CONTENT_DATA *view_content_p,
                MSG_HANDLE h_msg_handle_p,
                MESSAGE_NOTIFICATION *notify_ind_hdrs_p);

extern JC_RETCODE mmi_jmms_create_delivery_report_header_for_idle_screen(
                    mmi_jmms_pending_mms_delivery_reports_struct *delivery_header_p);
extern JC_RETCODE mmi_jmms_create_read_report_header_for_idle_screen(
                    mmi_jmms_pending_mms_read_reports_struct *read_report_header_p);
extern JC_RETCODE mmi_jmms_notification_reponse(MESSAGE_NOTIFICATION *notification_p, EMessageStatus message_status);

extern JC_RETCODE jmms_mmi_notification_response_for_immediate_retrieval(CONTENT_DATA view_content);
extern JC_RETCODE jmms_mmi_ack_for_deffered_retrieval(CONTENT_DATA content);
extern JC_RETCODE mmi_jmms_handle_deffered_retrieved_mms(CONTENT_DATA content);
extern void mmi_jmms_exit_read_report_query_screen(void);
extern void mmi_jmms_refresh_inbox_no_screen_update(void);

#if defined(CORRUPT_MMS_HANDLING)
extern JC_BOOLEAN mmi_jmms_is_corrupt_mms_notification(
                    CONTENT_DATA *view_content,
                    MSG_HANDLE msg_handle,
                    MESSAGE_NOTIFICATION *notify_ind_hdrs_p);
#endif /* defined(CORRUPT_MMS_HANDLING) */ 
#ifdef __MMI_JMMS_EXPIRY_HANDLING__
extern JC_BOOLEAN mmi_jmms_check_notification_headers_expired(MESSAGE_NOTIFICATION *notify_ind_headers_p);
extern JC_BOOLEAN mmi_jmms_has_notification_expired(JC_UINT32 msg_index);
#endif /* __MMI_JMMS_EXPIRY_HANDLING__ */ 
#endif /* __MMI_JMMSPUSHHANDLING_H */ 

