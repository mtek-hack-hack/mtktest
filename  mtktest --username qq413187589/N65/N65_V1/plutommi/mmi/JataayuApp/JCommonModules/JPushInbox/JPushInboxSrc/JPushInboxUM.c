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
 * UMPushInbox.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains all the function calls for handling UM requests.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_UMPUSHINBOX_C
#define _MMI_UMPUSHINBOX_C


#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "time.h"

#ifdef __MMI_UNIFIED_MESSAGE__

#include "CommonScreens.h"
#include "SettingProfile.h"
#include "worldclock.h"

#include "wap_ps_struct.h"
#include "wapadp.h"

#include "ddl.h"
#include "jcal.h"
#include "jdd_memapi.h"

#include "jdi_communicator.h"
#include "jdi_BrowserDatatype.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
// #include "JBrowserStartup.h"

/* PMT DARA  PROFILE HANDLER 020106 */
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"

#include "UnifiedMessageGProt.h"
#include "UnifiedMessageResDef.h"

#include "JPushInboxCommonAPIs.h"
#include "JPushInboxUM.h"
#include "JPushInboxCommonUI.h"
#include "wgui_status_icons.h"
#include "app_datetime.h"
#include "JMMSUMHandling.h"

/* extern SERVICE_VALUE *g_brw_service_msg_list_p[BRW_MAX_PUSH_MESSAGES]; */
/* extern U16 g_brw_index_current_highlighted_item; */
/* extern kal_uint8 PhnsetGetHomeCity(void); */
extern FLOAT mmi_dt_get_tz(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_push_time_stamp
 * DESCRIPTION
 *  Decide time stamp and covert it from GMT to local time.
 * PARAMETERS
 *  pServiceValue       [IN]        - push message structure.
 * RETURNS
 *  Created time(in second);else return received time(in second).
 *****************************************************************************/
static U32 mmi_um_brw_get_push_time_stamp(SERVICE_VALUE *pServiceValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tzdiff = 0;
    U32 converted_timestamp = 0;
    FLOAT tz = 0.0;

    UI_time datetime = {0};
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pServiceValue->pSICreated != NULL)
    {
        datetime.nYear = pServiceValue->pSICreated->year;
        if (datetime.nYear > 2090)
        {
            datetime.nYear = datetime.nYear - 100;
        }
        datetime.nMonth = pServiceValue->pSICreated->month;
        datetime.nDay = pServiceValue->pSICreated->day;
        datetime.nHour = pServiceValue->pSICreated->hour;
        datetime.nMin = pServiceValue->pSICreated->minute;
        datetime.nSec = pServiceValue->pSICreated->seconds;
    }
    else if (pServiceValue->pSIRcvd != NULL)
    {
        datetime.nYear = pServiceValue->pSIRcvd->year;
        if (datetime.nYear > 2090)
        {
            datetime.nYear = datetime.nYear - 100;
        }

        datetime.nMonth = pServiceValue->pSIRcvd->month;
        datetime.nDay = pServiceValue->pSIRcvd->day;
        datetime.nHour = pServiceValue->pSIRcvd->hour;
        datetime.nMin = pServiceValue->pSIRcvd->minute;
        datetime.nSec = pServiceValue->pSIRcvd->seconds;
    }

    converted_timestamp = mmi_dt_mytime_2_utc_sec((MYTIME*) & datetime, MMI_TRUE);

    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;

    if (tz > 0)
    {
        converted_timestamp += tzdiff;
    }
    else
    {
        converted_timestamp -= tzdiff;
    }

    return converted_timestamp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_message_count_req
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_UM_GET_MSG_NUM_REQ request.
 * PARAMETERS
 *  msg_count_req       [IN]        - request information.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_get_message_count_req(void *msg_count_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((mmi_um_get_msg_num_req_struct*) msg_count_req)->msg_type)
    {
        case UM_MSG_TYPE_MMS:
        {
            mmi_um_jmms_get_push_message_count_req();
            break;
        }
        case UM_MSG_TYPE_WAP_PUSH:
        {
            mmi_um_brw_get_push_messages_count_req();
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_message_list_req
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_UM_GET_LIST_REQ request.
 * PARAMETERS
 *  msg_list_req        [IN]        - request information.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_get_message_list_req(void *msg_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((mmi_um_get_list_req_struct*) msg_list_req)->msg_type)
    {
        case UM_MSG_TYPE_MMS:
        {
            mmi_um_jmms_get_mms_message_list_req((mmi_um_get_list_req_struct*) msg_list_req);
            break;
        }
        case UM_MSG_TYPE_WAP_PUSH:
        {
            mmi_um_brw_get_push_messages_list_req(msg_list_req);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_message_info_req
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_UM_GET_MSG_INFO_REQ request.
 * PARAMETERS
 *  msg_info_req        [IN]        - request information.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_get_message_info_req(void *msg_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((mmi_um_get_msg_info_req_struct*) msg_info_req)->msg_type)
    {
        case UM_MSG_TYPE_MMS:
        {
            mmi_um_jmms_get_mms_message_info_req((mmi_um_get_msg_info_req_struct*) msg_info_req);
            break;
        }
        case UM_MSG_TYPE_WAP_PUSH:
        {
            mmi_um_brw_get_push_messages_info_req(
                ((mmi_um_get_msg_info_req_struct*) msg_info_req)->start_entry,
                ((mmi_um_get_msg_info_req_struct*) msg_info_req)->msg_number);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_delete_all_messages_req
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_UM_DELETE_FOLDER_REQ request.
 * PARAMETERS
 *  msg_delete_all_req      [IN]        - request information.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_delete_all_messages_req(void *msg_delete_all_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (((mmi_um_delete_folder_req_struct*) msg_delete_all_req)->msg_type)
    {
        case UM_MSG_TYPE_MMS:
        {
            mmi_um_jmms_delete_all_mms_message_req((mmi_um_delete_folder_req_struct*) msg_delete_all_req);
            break;
        }
        case UM_MSG_TYPE_WAP_PUSH:
        {
            mmi_um_brw_delete_all_push_messages_req(msg_delete_all_req);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_delete_all_messages_rsp
 * DESCRIPTION
 *  Function to recieve information that if user has confirmed
 *  to delete all push messages or not.
 * PARAMETERS
 *  msg_delete_all_rsp      [IN]        - confirmation of deletion of all messages.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_delete_all_messages_rsp(void *msg_delete_all_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_delete_all_res_struct *delete_all_rsp = (mmi_um_delete_all_res_struct*) msg_delete_all_rsp;

    switch (delete_all_rsp->msg_type)
    {
        case UM_MSG_TYPE_MMS:
        {
            mmi_um_delete_all_mms_messages_rsp((U16) delete_all_rsp->result);
            break;
        }
        case UM_MSG_TYPE_WAP_PUSH:
        {
            mmi_um_brw_delete_all_push_messages_rsp((U16) delete_all_rsp->result);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_mms_ready_ind
 * DESCRIPTION
 *  Function to send an indication to UM that browser is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_mms_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_ready_ind_struct *push_um_ready_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_um_ready_ind = (mmi_um_ready_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_ready_ind_struct));
    push_um_ready_ind->result = KAL_TRUE;
    push_um_ready_ind->msg_type = UM_MSG_TYPE_MMS;

    /* Prepare response structure */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_READY_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_um_ready_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_push_messages_count_req
 * DESCRIPTION
 *  Function to get count of unread and read push messages and send response to UM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_get_push_messages_count_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 brw_total_msg_count = 0;
    U32 brw_unread_msg_count = 0;
    mmi_um_get_msg_num_rsp_struct *push_count_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_push_cntx.push_delete_notification = MMI_FALSE;

    if (NULL == g_mmi_brw_push_cntx.service_msg_list_p)
    {
        brw_total_msg_count = 0;
        brw_unread_msg_count = 0;
    }
    else
    {
        /* update the copy of local pointers */
        mmi_brw_create_push_msg_list();

        mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);
    }

    push_count_rsp = (mmi_um_get_msg_num_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_msg_num_rsp_struct));
    push_count_rsp->result = KAL_TRUE;
    push_count_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    push_count_rsp->inbox_unread_msg_number = brw_unread_msg_count;
    push_count_rsp->inbox_read_msg_number = brw_total_msg_count - brw_unread_msg_count;
    push_count_rsp->unsent_msg_number = 0;
    push_count_rsp->sent_msg_number = 0;
    push_count_rsp->draft_msg_number = 0;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_GET_MSG_NUM_RSP;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_count_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_push_messages_list_req
 * DESCRIPTION
 *  Function to get push message list information and send response to UM.
 * PARAMETERS
 *  msg_list_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_get_push_messages_list_req(void *msg_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 msg_counter = 0;
    U32 start_entry = 0;
    U32 brw_total_msg_count = 0;
    U32 brw_unread_msg_count = 0;
    mmi_um_get_list_rsp_struct *push_list_rsp = NULL;
    mmi_um_get_list_req_struct *um_msg_list_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_push_cntx.push_delete_notification = MMI_FALSE;

    um_msg_list_req = (mmi_um_get_list_req_struct*) msg_list_req;
    start_entry = um_msg_list_req->start_entry;

    /* Buffer should free while entering the inbox screen  */
    mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);

    if (NULL == g_mmi_brw_push_cntx.service_msg_list_p)
    {
        brw_total_msg_count = 0;
        brw_unread_msg_count = 0;
    }
    else
    {
        mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);
    }

    push_list_rsp = (mmi_um_get_list_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_list_rsp_struct));
    push_list_rsp->result = KAL_TRUE;
    push_list_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;

    if (UM_MSG_BOX_TYPE_INBOX == um_msg_list_req->msg_box_type)
    {
        push_list_rsp->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
        push_list_rsp->start_entry = start_entry;

        if ((brw_total_msg_count - start_entry) <= MMI_UM_MAX_GET_LIST_MSG_NUMBER)
        {
            push_list_rsp->msg_number = brw_total_msg_count - start_entry;
        }
        else
        {
            push_list_rsp->msg_number = MMI_UM_MAX_GET_LIST_MSG_NUMBER;
            push_list_rsp->more = KAL_TRUE;
        }

        for (msg_counter = start_entry; msg_counter < (push_list_rsp->msg_number + start_entry); msg_counter++)
        {
            push_list_rsp->list_info[msg_counter].msg_index = msg_counter;

            push_list_rsp->list_info[msg_counter].timestamp = mmi_um_brw_get_push_time_stamp(g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]);
        }

    }
    else    /* UM_MSG_BOX_TYPE_INBOX != um_msg_list_req->msg_box_type */
    {
        /* As push message can not be a part of outbox, sent or draft folder */
        push_list_rsp->msg_box_type = um_msg_list_req->msg_box_type;
        push_list_rsp->start_entry = 0;
        push_list_rsp->msg_number = 0;

    }

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_GET_LIST_RSP;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_list_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_get_push_messages_info_req
 * DESCRIPTION
 *  Function to get push message list information and send response to UM.
 * PARAMETERS
 *  start_entry     [IN]        - indicates the index of node in the jataayu list from which the information is to be sent
 *  total_msgs      [IN]        - indicated that for how many messages information is to retrived
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_get_push_messages_info_req(U32 start_entry, U32 total_msgs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 msg_counter, rcvd_message_len = 0;
    struct tm expiry_timestamp;
    U64 current_secs_since_1970 = 0;
    U64 expiry_secs_since_1970 = 0;
    mmi_um_get_msg_info_rsp_struct *push_info_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_um_brw_get_push_messages_info_req");

    push_info_rsp = (mmi_um_get_msg_info_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_get_msg_info_rsp_struct));
    push_info_rsp->result = KAL_TRUE;
    push_info_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    push_info_rsp->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    push_info_rsp->start_entry = start_entry;
    push_info_rsp->msg_number = total_msgs;

    for (msg_counter = start_entry; msg_counter < total_msgs + start_entry; msg_counter++)
    {
        push_info_rsp->msg_info[msg_counter - start_entry].msg_index = msg_counter;

        push_info_rsp->msg_info[msg_counter - start_entry].timestamp = mmi_um_brw_get_push_time_stamp(g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]);

        push_info_rsp->msg_info[msg_counter - start_entry].address_type = UM_ADDR_TYPE_PHONE_NUMBER;    /* to be ignored */
        push_info_rsp->msg_info[msg_counter - start_entry].address_length = 0;
        memset(push_info_rsp->msg_info[msg_counter - start_entry].address, 0, MMI_UM_MAX_ADDR_LEN);

        if (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->service_flag == SERVICE_INDICATION)
        {
            rcvd_message_len = mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmMessage);

            if (0 != rcvd_message_len)
            {
                if ((rcvd_message_len * ENCODING_LENGTH) < MMI_UM_MAX_SUBJECT_LEN - ENCODING_LENGTH)
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].subject_length = rcvd_message_len;
                    mmi_ucs2ncpy(
                        (S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject,
                        (S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmMessage,
                        rcvd_message_len);
                    mmi_ucs2cat((S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject, "\0\0");
                }
                else
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].subject_length = MMI_UM_MAX_SUBJECT_LEN;
                    mmi_ucs2ncpy(
                        (S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject,
                        (S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmMessage,
                        (MMI_UM_MAX_SUBJECT_LEN / ENCODING_LENGTH) - 4);
                    mmi_ucs2cat((S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject, ".\0.\0.\0\0\0");
                }
            }
            else    /* if message body for SI is not available then href should dispaly as subject */
            {
                rcvd_message_len = mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmHref);
                if ((rcvd_message_len * ENCODING_LENGTH) < MMI_UM_MAX_SUBJECT_LEN - ENCODING_LENGTH)
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].subject_length = rcvd_message_len;
                    mmi_ucs2ncpy(
                        (S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject,
                        (S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmHref,
                        rcvd_message_len);
                    mmi_ucs2cat((S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject, "\0\0");
                }
                else
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].subject_length = MMI_UM_MAX_SUBJECT_LEN;
                    mmi_ucs2ncpy(
                        (S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject,
                        (S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmHref,
                        (MMI_UM_MAX_SUBJECT_LEN / ENCODING_LENGTH) - 4);
                    mmi_ucs2cat((S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject, ".\0.\0.\0\0\0");
                }
            }
        }
        else    /* SERVICE_LOADING */
        {
            rcvd_message_len = mmi_ucs2strlen((S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmHref);
            if ((rcvd_message_len * ENCODING_LENGTH) < MMI_UM_MAX_SUBJECT_LEN - ENCODING_LENGTH)
            {
                push_info_rsp->msg_info[msg_counter - start_entry].subject_length = rcvd_message_len;
                mmi_ucs2ncpy(
                    (S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject,
                    (S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmHref,
                    rcvd_message_len);
                mmi_ucs2cat((S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject, "\0\0");
            }
            else
            {
                push_info_rsp->msg_info[msg_counter - start_entry].subject_length = MMI_UM_MAX_SUBJECT_LEN;
                mmi_ucs2ncpy(
                    (S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject,
                    (S8*) g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pmHref,
                    (MMI_UM_MAX_SUBJECT_LEN / ENCODING_LENGTH) - 4);
                mmi_ucs2cat((S8*) push_info_rsp->msg_info[msg_counter - start_entry].subject, ".\0.\0.\0\0\0");
            }
        }

        if (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->service_flag == SERVICE_INDICATION)
        {
            if (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires != NULL)
            {
                expiry_timestamp.tm_mon = g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires->month - 1;   /* month scale to 0 to 11 */
                expiry_timestamp.tm_year = g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires->year - 1900;        /* offset since 1900 */
                expiry_timestamp.tm_mday = g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires->day;
                expiry_timestamp.tm_hour = g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires->hour;
                expiry_timestamp.tm_min = g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires->minute;
                expiry_timestamp.tm_sec = g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires->seconds;

                /* Get difference of seconds of expiry time from 1970 (as per UTC standard) */
                expiry_secs_since_1970 = (time_t) mktime(&expiry_timestamp);
                /* Get difference of seconds of current time from 1970 (as per UTC standard) */
                current_secs_since_1970 = get_current_utc_time();
            }

            if (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->bIsRead == 0)
            {
                if ((expiry_secs_since_1970 > current_secs_since_1970) ||
                    (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires == NULL))
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].icon_id = IMG_ID_BRW_PUSH_UNREAD;
                }
                else
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].icon_id = IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
                }
            }
            else
            {
                if ((expiry_secs_since_1970 > current_secs_since_1970) ||
                    (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->pSIExpires == NULL))
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].icon_id = IMG_ID_BRW_PUSH_READ;
                }
                else
                {
                    push_info_rsp->msg_info[msg_counter - start_entry].icon_id = IMG_ID_BRW_PUSH_EXPIRED_READ;
                }
            }
        }
        else
        {
            if (g_mmi_brw_push_cntx.service_msg_list_p[msg_counter]->bIsRead == 0)
            {
                push_info_rsp->msg_info[msg_counter - start_entry].icon_id = IMG_ID_BRW_PUSH_UNREAD;
            }
            else
            {
                push_info_rsp->msg_info[msg_counter - start_entry].icon_id = IMG_ID_BRW_PUSH_READ;
            }
        }
    }

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_GET_MSG_INFO_RSP;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_info_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "END - mmi_um_brw_get_push_messages_info_req");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_delete_all_push_messages_req
 * DESCRIPTION
 *  Function to delete all push messages and send response to UM.
 * PARAMETERS
 *  msg_delete_all_req      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_delete_all_push_messages_req(void *msg_delete_all_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    U32 msg_counter;
    U32 brw_total_msg_count = 0;
    U32 brw_unread_msg_count = 0;
    mmi_um_delete_folder_rsp_struct *push_delete_all_rsp;
    mmi_um_delete_folder_req_struct *um_msg_delete_all_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_msg_delete_all_req = (mmi_um_delete_folder_req_struct*) msg_delete_all_req;

    /* Added by Vivek - 25072006 */
    if (UM_MSG_BOX_TYPE_INBOX & um_msg_delete_all_req->msg_box_type)
    {
        mmi_brw_get_push_statistics(&brw_total_msg_count, &brw_unread_msg_count);

        /* Delete all messages one by one */
        for (msg_counter = 0; msg_counter < brw_total_msg_count; msg_counter++)
        {
            mmi_brw_delete_push_msg(0);
        }

        /* Added by Vivek - 24072006 */
        mmi_brw_push_free_service_value_struct(&g_mmi_brw_push_cntx.current_service_message);

        /* Save to persistant storage */
        mmi_brw_save_current_push_info();

        /* hide unread push message icon on idle screen */
        HideStatusIcon(STATUS_ICON_WAP);
    }

    push_delete_all_rsp =
        (mmi_um_delete_folder_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_delete_folder_rsp_struct));
    push_delete_all_rsp->msg_type = UM_MSG_TYPE_WAP_PUSH;
    push_delete_all_rsp->result = KAL_TRUE;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_DELETE_FOLDER_RSP;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_delete_all_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_push_ready_ind
 * DESCRIPTION
 *  Function to send an indication to UM that browser is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_push_ready_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_ready_ind_struct *push_um_ready_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_um_ready_ind = (mmi_um_ready_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_ready_ind_struct));
    push_um_ready_ind->result = KAL_TRUE;
    push_um_ready_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_READY_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_um_ready_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_new_push_message_ind
 * DESCRIPTION
 *  Function to send an indication to UM that a new push message has arrived.
 * PARAMETERS
 *  pServiceValue       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_new_push_message_ind(SERVICE_VALUE *pServiceValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_new_msg_ind_struct *push_new_msg_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update the copy of local pointers */
    mmi_brw_create_push_msg_list();

    push_new_msg_ind = (mmi_um_new_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_new_msg_ind_struct));
    push_new_msg_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    push_new_msg_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    push_new_msg_ind->msg_index = 0;

    push_new_msg_ind->timestamp = mmi_um_brw_get_push_time_stamp(pServiceValue);

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_NEW_MSG_IND;
    Message.oslDataPtr = (oslParaType*) push_new_msg_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_delete_all_push_messages_ind
 * DESCRIPTION
 *  Function to send an indication to UM that a user has
 *  selected to delete all push messages.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_delete_all_push_messages_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_delete_all_ind_struct *push_delete_all_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_delete_all_ind = (mmi_um_delete_all_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_delete_all_ind_struct));
    push_delete_all_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    push_delete_all_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_DELETE_ALL_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_delete_all_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_delete_all_push_messages_rsp
 * DESCRIPTION
 *  Function to recieve information that if user has confirmed
 *  to delete all push messages or not.
 * PARAMETERS
 *  result      [IN]        - confirmation of deletion of all messages.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_delete_all_push_messages_rsp(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == KAL_TRUE)
    {
        DeleteNHistory(2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_highlight_push_messages_ind
 * DESCRIPTION
 *  Function to send information to UM about the currently highlighted item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_highlight_push_messages_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_um_highlight_msg_ind_struct *push_highlight_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_highlight_ind =
        (mmi_um_highlight_msg_ind_struct*) OslConstructDataPtr(sizeof(mmi_um_highlight_msg_ind_struct));
    push_highlight_ind->msg_type = UM_MSG_TYPE_WAP_PUSH;
    push_highlight_ind->msg_box_type = UM_MSG_BOX_TYPE_INBOX;
    push_highlight_ind->msg_index = g_mmi_brw_push_cntx.curr_hilited_item_index - 1;

    /* Prepare response structure */
    Message.oslSrcId = MOD_WAP /* MOD_MMI */ ;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND;

    /* Send Response to MMI Queue */
    Message.oslDataPtr = (oslParaType*) push_highlight_ind;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_brw_refresh_ind
 * DESCRIPTION
 *  Function to refresh UM message information.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_brw_refresh_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_um_jataayu_entry_message_wap_push
 * DESCRIPTION
 *  Screen Entry function which is called when the user selects to
 *  view a particular push message.
 * PARAMETERS
 *  msg_box_type        [IN]        - type of message box.
 *  msg_index           [IN]        - index of selected message.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_um_jataayu_entry_message_wap_push(UmMsgBoxType msg_box_type, kal_uint16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_push_cntx.curr_hilited_item_index = msg_index;
    mmi_brw_entry_read_push_message();
}

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_UMPUSHINBOX_C */ 

