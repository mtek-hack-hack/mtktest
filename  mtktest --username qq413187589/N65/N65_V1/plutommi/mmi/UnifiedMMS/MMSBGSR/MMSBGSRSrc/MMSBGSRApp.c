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
 *  MMSBGSRApp.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Utilities API of the MMS BGSR Application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MMS_BGSR_SUPPORT__

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "time.h"

#include "wap_ps_struct.h"
#include "custom_wap_config.h"


#ifndef __MMI_BGSR_PROT_H_
#include "MMSBGSRProt.h"
#endif
#include "MMSBGSRResDef.h"
#include "wgui_status_icons.h"
#include "wap.h"
/* TRACE */
/*******************************************************************************
 * Static Declaration
 *******************************************************************************/

/*******************************************************************************
 * Global Variable
 *******************************************************************************/
S16 error;
extern kal_uint8 mmi_mms_bgsr_sync_flag;

/*******************************************************************************
 * Local Function
 *******************************************************************************/

/*******************************************************************************
 * Global Function
 *******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_extract_q
 * DESCRIPTION
 *  extract the message from the queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id              [IN]    message id
 *  queue               [IN]    the queue
 * RETURNS
 *  mmi_mms_bgsr_msg_struct*    the message element of the message id
 *****************************************************************************/
mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_extract_q( 
                            U32 msg_id,
                            mmi_mms_bgsr_msg_struct **queue )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *message = NULL, *pre = NULL;
    int find_flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    message = *queue;
    while( message != NULL )
    {
        if( message->msg_id == msg_id )
        {
            find_flag = TRUE;
            break;
        }
        pre = message;
        message = message->next;
    }
    
    if(find_flag == TRUE)
    {
        if(pre == NULL)
        {
            *queue = message->next;
        }
        else
        {
            pre->next = message->next;
        }

        message->next = NULL;
        return message;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_q
 * DESCRIPTION
 *  get the message from the queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id              [IN]    message id
 *  queue               [IN]    the queue
 * RETURNS
 *  mmi_mms_bgsr_msg_struct*    the message element of the message id
 *****************************************************************************/
mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_get_q(
                            U32 msg_id,
                            mmi_mms_bgsr_msg_struct* queue )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *message = NULL;
    int find_flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    message = queue;
    while( message != NULL )
    {
        if( message->msg_id == msg_id )
        {
            find_flag = TRUE;
            break;
        }
        message = message->next;
    }

    if( find_flag == TRUE)
    {
        return message;
    }
    else
    {
        return NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_find_q
 * DESCRIPTION
 *  find the corresponding message from the queue
 * CALLS
 *  
 * PARAMETERS
 *  msg_id              [IN]    message id
 *  queue               [IN]    SendQ or DownloadQ
 *  fail_q              [IN]    SendFailQ or DownloadFailQ
 * RETURNS
 *  BOOL                whether the message is in the queue
 *****************************************************************************/
BOOL mmi_mms_bgsr_find_q(   U32 msg_id,
                                    mmi_mms_bgsr_msg_struct * queue,
                                    mmi_mms_bgsr_msg_struct * fail_q )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *check = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    check = queue;

    while( check != NULL )
    {
        if( check->msg_id == msg_id )
        {
            return TRUE;
        }
        check = check->next;
    }

    check = fail_q;

    while( check != NULL )
    {
        if( check->msg_id == msg_id )
        {
            return TRUE;
        }
        check = check->next;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_enqueue
 * DESCRIPTION
 *  put the message into the SendQ or DownloadQ
 * CALLS
 *  
 * PARAMETERS
 *  msg                 [IN]    message
 *  queue               [IN]    SendQ or DownloadQ
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_enqueue( mmi_mms_bgsr_msg_struct *msg,
                                    mmi_mms_bgsr_msg_struct **queue )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *insert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    if( msg == NULL)
    {
        return;
    }

    if( *queue == NULL )
    {
        *queue = msg;
        return;
    }

    insert = *queue;    
    while( insert->next != NULL )
    {
        insert = insert->next;
    }
    insert->next = msg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_delete_queue
 * DESCRIPTION
 *  delete the whole queue, except the certain message
 * CALLS
 *  
 * PARAMETERS
 *  queue              [IN]    the queue
 *  except_msg_id      [IN]    except the message
 * RETURNS
 *  mmi_mms_bgsr_msg_struct
 *****************************************************************************/
mmi_mms_bgsr_msg_struct *mmi_mms_bgsr_delete_queue(
                            mmi_mms_bgsr_msg_struct **queue,
                            U32 except_msg_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *this_msg = NULL,
                            *except_msg = NULL,
                            *next_msg = NULL;
    U16 index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    this_msg = *queue;
    while(this_msg != NULL && this_msg->msg_id != 0)
    {
        if(this_msg->msg_id == except_msg_id)
        {
            except_msg = this_msg;
            this_msg = this_msg->next;
            except_msg->next = NULL;
        }
        else
        {
            index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(this_msg->msg_id);
            if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                mmi_mms_bgsr_echo_current_info();
                break;
            }
            next_msg = this_msg->next;
            this_msg->msg_id = 0;
            this_msg->next = NULL;
            mmi_mms_bgsr_enqueue(this_msg, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
            this_msg = next_msg;

            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);

        }
    }

    return except_msg;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_send_req
 * DESCRIPTION
 *  handle the send request, move a message to send q
 * CALLS
 *  
 * PARAMETERS
 *  msg_id              [IN]    message id
 *  is_rr               [IN]    is read report or not
 *  send_setting        [IN]    send setting
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_send_req(kal_uint32 msg_id,
                                    kal_bool is_rr,
                                    mmi_mms_bgsr_send_setting_enum send_setting )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *send_msg = NULL;
    kal_uint16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SEND_REQ,msg_id,__LINE__);

    if(!mmi_mms_bgsr_is_ready())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_READY,__LINE__);
        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);
            mmi_mms_bgsr_sync();
        }
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
        return;
    }

    /* if it's not a read report, move it to OUTBOX first*/    
    if( is_rr == 0)
    {
        mmi_mms_bgsr_save_mms_req(msg_id, MMA_FOLDER_OUTBOX);    
    }
    if( (mmi_mms_bgsr_find_q( 
            msg_id,
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q,
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q  )) == TRUE )
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_PREVIOUS_MSG,__LINE__);
        send_msg = mmi_mms_bgsr_extract_q(
                    msg_id,
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
        if( send_msg != NULL)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_PREVIOUS_FAIL_MSG,__LINE__);        
            mmi_mms_bgsr_enqueue(   send_msg,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q) );
        }
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_SEND),
                         IMG_GLOBAL_PROGRESS,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_SEND),
                         IMG_GLOBAL_PROGRESS,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_NEW_MSG,__LINE__);
        send_msg = mmi_mms_bgsr_extract_q(0, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
        if (send_msg != NULL)
        {
            memset(send_msg , 0, sizeof(mmi_mms_bgsr_msg_struct));

            /* INIT */

            send_msg->fail_retry_flag = 0;
            send_msg->folder = MMI_MMS_BGSR_FOLDER_OUTBOX;
            send_msg->is_rr = is_rr;
            send_msg->msg_id = msg_id;
            send_msg->ntt = 0;
            send_msg->quota = MMI_MMS_BGSR_CFG_RETRY_QUOTA;
            send_msg->result = MMI_MMS_BGSR_RESULT_NOT_USED;
            send_msg->send_setting = send_setting;
            send_msg->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND;
            send_msg->next = NULL;
            mmi_mms_bgsr_enqueue(   send_msg,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q) );
            if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_SEND),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             SUCCESS_TONE);
            }
            else if ( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_SEND),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             0);
            }

        }
        else
        {
            MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_MEMORY_NOT_ALLOCATED,__LINE__);
        }
    }
    if(send_msg != NULL)
    {
        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(send_msg->msg_id);                
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            return;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
    }
    
    if( is_rr == 1)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_SEND_RR,__LINE__);    
        mmi_mms_bgsr_send_mms_req(send_msg);
    }
    else if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id == 0)
    {
        send_msg = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q;
        mmi_mms_bgsr_send_mms_req(send_msg);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ALREADY_A_SENDING_MSG, g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id,__LINE__);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_cancel_send_req
 * DESCRIPTION
 *  handle cancelling the sending message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_cancel_send_req( U32 msg_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *msg = NULL;
    kal_uint16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_CANCEL_SEND_REQ,msg_id,__LINE__);

    if(!mmi_mms_bgsr_is_ready())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_READY,__LINE__);        
        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);        
            mmi_mms_bgsr_sync();
        }
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
        return;
    }

    msg = mmi_mms_bgsr_extract_q(   msg_id,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
    if( msg == NULL)
    {
        msg = mmi_mms_bgsr_extract_q(   msg_id,
                                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));    
    }
    if( msg != NULL)
    {
        msg->status = MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND;
        mmi_mms_bgsr_enqueue( msg, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q) );
        if( msg_id == g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id)
        {
            mmi_mms_bgsr_abort_send_mms_req(msg_id);
            if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_CANCEL),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             SUCCESS_TONE);
            }            
            else if (mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_CANCEL),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             0);
            }
        }

        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(msg->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            return;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_download_req
 * DESCRIPTION
 *  handle the download request, move a message to download q
 * CALLS
 *  
 * PARAMETERS
 *  msg_id          [IN]    message id
 *  expire_time     [IN]    expire time
 *  size            [IN]    size
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_download_req( U32 msg_id, U32 expire_time, U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *dl_msg = NULL;
    kal_uint16 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_DOWNLOAD_REQ,msg_id,__LINE__);

    if(!mmi_mms_bgsr_is_ready())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_READY,__LINE__);
        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);        
            mmi_mms_bgsr_sync();
        }
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if (mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
        
        return;
    }

    if( (mmi_mms_bgsr_find_q(
            msg_id,
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q, 
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q  )) == TRUE )
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DOWNLOAD_PREVIOUS_MSG,__LINE__);    
        dl_msg = mmi_mms_bgsr_extract_q(
                    msg_id,
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
        if(dl_msg != NULL)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DOWNLOAD_PREVIOUS_FAIL_MSG,__LINE__);            
            mmi_mms_bgsr_enqueue( dl_msg, 
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
        }
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_DOWNLOAD),
                         IMG_GLOBAL_PROGRESS,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_DOWNLOAD),
                         IMG_GLOBAL_PROGRESS,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }

    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DOWNLOAD_NEW_MSG,__LINE__);    
        dl_msg = mmi_mms_bgsr_extract_q(0, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
        if (dl_msg != NULL)
        {
            memset(dl_msg , 0, sizeof(mmi_mms_bgsr_msg_struct));

            /* INIT */

            dl_msg->fail_retry_flag = 0;
            dl_msg->folder = MMI_MMS_BGSR_FOLDER_INBOX;
            dl_msg->msg_id = msg_id;
            dl_msg->ntt = 0;
            dl_msg->quota = MMI_MMS_BGSR_CFG_RETRY_QUOTA;
            dl_msg->result = MMI_MMS_BGSR_RESULT_NOT_USED;
            dl_msg->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
            dl_msg->expire_time = expire_time;
            dl_msg->size = size;
            dl_msg->next = NULL;
            mmi_mms_bgsr_enqueue( dl_msg,
                                  &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
            if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_DOWNLOAD),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             SUCCESS_TONE);
            }
            else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_DOWNLOAD),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             0);
            }
        }
        else
        {
            MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_MEMORY_NOT_ALLOCATED,__LINE__);
        }
    }

    if(dl_msg != NULL)
    {
        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(dl_msg->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            return;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
    }

    if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id == 0)
    {
        dl_msg = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q;
        mmi_mms_bgsr_download_mms_req(dl_msg);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG, g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id,__LINE__);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_cancel_download_req
 * DESCRIPTION
 *  handle cancelling the sending message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]    message id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_cancel_download_req( U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *msg;
    kal_uint16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_CANCEL_DOWNLOAD_REQ,msg_id,__LINE__);

    if(!mmi_mms_bgsr_is_ready())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_READY,__LINE__);
        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);
            mmi_mms_bgsr_sync();
        }
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if (mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
        return;
    }

    msg = mmi_mms_bgsr_extract_q( msg_id,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
    if( msg == NULL)
    {
        msg = mmi_mms_bgsr_extract_q(   msg_id,
                                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));    
    }
    if(msg != NULL)
    {
        msg->status = MMI_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD;
        mmi_mms_bgsr_enqueue( msg, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
        if( msg_id == g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id)
        {
            mmi_mms_bgsr_abort_download_mms_req(msg_id);
            if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_CANCEL),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             SUCCESS_TONE);
            }
            else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
            {
                DisplayPopup((U8 *)GetString(STR_GLOBAL_CANCEL),
                             IMG_GLOBAL_PROGRESS,
                             1,
                             MMI_MMS_BGSR_POPUP_TIME,
                             0);
            }
        }

        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(msg->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            return;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_msg_info
 * DESCRIPTION
 *  get the message information
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                  [IN]    the message id
 *  msg_info                [IN]    the memory block for the message info
 *  get_msg_info_callback   [IN]    the callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_get_msg_info( 
        U32 msg_id,
        mmi_mms_bgsr_msg_info_struct *msg_info,
        mmi_mms_bgsr_msg_funcptr_type get_msg_info_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *local_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_GET_MSG_INFO,msg_id,__LINE__);

    if(!mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);            
        mmi_mms_bgsr_sync();
/*        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);            
            mmi_mms_bgsr_sync();
        }*/
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
        return;
    }

    local_msg = mmi_mms_bgsr_get_q(
                    msg_id,
                    g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q);
    if( local_msg == NULL )
    {
        local_msg = mmi_mms_bgsr_get_q(
                        msg_id,
                        g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q);
    }
    if( local_msg == NULL )
    {
        local_msg = mmi_mms_bgsr_get_q(
                        msg_id,
                        g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q);
    }
    if( local_msg == NULL )
    {
        local_msg = mmi_mms_bgsr_get_q(
                        msg_id,
                        g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q);
    }

    if (local_msg == NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
        mmi_mms_bgsr_echo_current_info();
        msg_info->result = MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
        get_msg_info_callback(msg_id, msg_info);
    }
    else
    {
        msg_info->folder    = local_msg->folder;
        msg_info->msg_id    = local_msg->msg_id;
        msg_info->ntt       = local_msg->ntt;
        msg_info->quota     = local_msg->quota;
        msg_info->result    = local_msg->result;
        msg_info->status    = local_msg->status;
        get_msg_info_callback(msg_id, msg_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_sending_msg_id;
 * DESCRIPTION
 *  return the sending message id
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32 mmi_mms_bgsr_send_msg_id
 *****************************************************************************/
U32 mmi_mms_bgsr_get_sending_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    if(!mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);    
        mmi_mms_bgsr_sync();
/*        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);    
            mmi_mms_bgsr_sync();
        }*/
        return 0;
    }
    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ALREADY_A_SENDING_MSG, g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id,__LINE__);    
    return g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_downloading_msg_id
 * DESCRIPTION
 *  return the downloading message id
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32 mmi_mms_bgsr_download_msg_id
 *****************************************************************************/
U32 mmi_mms_bgsr_get_downloading_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    if(!mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);    
        mmi_mms_bgsr_sync();
/*        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);    
            mmi_mms_bgsr_sync();
        }*/
        return 0;
    }
    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG, g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id,__LINE__);    
    return g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_change_msg_notify
 * DESCRIPTION
 *  handle the operation on the message
 * CALLS
 *  
 * PARAMETERS
 *  msg_id                      [IN]    message id 
 *  msg_operation_notify        [IN]    operation
 *  msg_folder                  [IN]    the message folder 
 *  change_msg_notify_callback  [IN]    the callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_change_msg_notify(
        U32 msg_id, 
        mmi_mms_bgsr_msg_operation_notify_enum msg_operation_notify,
		mmi_mms_bgsr_msg_box_enum msg_folder,
		mmi_mms_bgsr_funcptr_type change_msg_notify_callback)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_CHANGE_MSG_NOTIFY,msg_operation_notify,__LINE__);

    if(!mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);
        mmi_mms_bgsr_sync();
/*        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);
            mmi_mms_bgsr_sync();
        }*/
        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         SUCCESS_TONE);
        }
        else if ( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
        {
            DisplayPopup((U8 *)GetString(STR_GLOBAL_NOT_AVAILABLE),
                         IMG_GLOBAL_WARNING,
                         1,
                         MMI_MMS_BGSR_POPUP_TIME,
                         0);
        }
        return;
    }

    switch( msg_operation_notify )
    {
        case    MMI_MMS_BGSR_OP_DELETE:
        case    MMI_MMS_BGSR_OP_MOVE_TO_FOLDER:
        {
            mmi_mms_bgsr_msg_struct *local_msg = NULL;
            kal_uint16 index;
            if(msg_id == g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id ||
               msg_id == g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_THE_MSG_IS_TRANSMITTING, msg_id,__LINE__);
                if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
                {
                    DisplayPopup((U8 *)GetString(STR_ID_BGSR_MESSAGE_IS_TRANSMITTING),
                                 IMG_GLOBAL_WARNING,
                                 1,
                                 MMI_MMS_BGSR_POPUP_TIME,
                                 SUCCESS_TONE);
                }
                else if ( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                {
                    DisplayPopup((U8 *)GetString(STR_ID_BGSR_MESSAGE_IS_TRANSMITTING),
                                 IMG_GLOBAL_WARNING,
                                 1,
                                 MMI_MMS_BGSR_POPUP_TIME,
                                 0);
                }
                if(change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(
                        msg_id,
                        MMI_MMS_BGSR_RESULT_FAIL_FILE_IN_USE);
                }
                
                return;

            }
            
            if( msg_folder == MMI_MMS_BGSR_FOLDER_INBOX )
            {
                local_msg = mmi_mms_bgsr_extract_q(
                                msg_id,
                                &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
                if( local_msg == NULL )
                {
                    local_msg = mmi_mms_bgsr_extract_q(
                                    msg_id,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
                }
            }
            else
            {
                local_msg = mmi_mms_bgsr_extract_q(
                                msg_id,
                                &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
                if( local_msg == NULL )
                {
                    local_msg = mmi_mms_bgsr_extract_q(
                                    msg_id,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                }
            }

            if( local_msg == NULL )
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
                mmi_mms_bgsr_echo_current_info();
                if(change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback(
                        msg_id,
                        MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND );
                }
            }
            else
            {
                index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(local_msg->msg_id);
                if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
                {
                    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                    mmi_mms_bgsr_echo_current_info();
                    break;
                }
                local_msg->msg_id = 0;
                mmi_mms_bgsr_enqueue(local_msg, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
                if(change_msg_notify_callback != NULL)
                {
                    change_msg_notify_callback( msg_id, MMI_MMS_BGSR_RESULT_OK );
                }
                WriteRecord(
                    NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                    (U16)(index+1),
                    &(mmi_mms_bgsr_msg_struct_array[index]),
                    NVRAM_BGSR_MSG_STRUCT_SIZE,
                    &error);
            }

            break;
        }
        case    MMI_MMS_BGSR_OP_FORMAT:
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q 
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q), 0);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q), 0);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q), 0);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q), 0);
            if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id != 0)
            {
                g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id = 0;
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_DOWNLOAD_ID);                
            }

            if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id != 0)
            {
                g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id = 0;
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_SEND_ID);
            }

            mmi_mms_bgsr_sync_flag = FALSE;
            mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_IDLE);

            StartTimer(MMI_MMS_BGSR_TIMER, 
                        MMI_MMS_BGSR_FAST_TIMEOUT_TIMER, 
                        mmi_mms_bgsr_timeout_procedure);

            if(change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback( msg_id, MMI_MMS_BGSR_RESULT_OK );
            }
            break;
        }
        case    MMI_MMS_BGSR_OP_DELETE_ALL_INBOX:
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q),
                    g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q),
                    g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id);
            if(change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback( msg_id, MMI_MMS_BGSR_RESULT_OK );            
            }

            break;
        }
        case    MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX:
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q),
                    g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q),
                    g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id);
            if(change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback( msg_id, MMI_MMS_BGSR_RESULT_OK );            
            }
            break;
        }
        case    MMI_MMS_BGSR_OP_CANCEL_ALL_INBOX:
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q), 0);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q), 0);

            if(change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback( msg_id, MMI_MMS_BGSR_RESULT_OK );            
            }

            break;
        }
        case    MMI_MMS_BGSR_OP_CANCEL_ALL_OUTBOX:
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q), 0);

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q
                = mmi_mms_bgsr_delete_queue(
                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q), 0);
                
            if(change_msg_notify_callback != NULL)
            {
                change_msg_notify_callback( msg_id, MMI_MMS_BGSR_RESULT_OK );            
            }

            break;
        }
        
        default:
        {
            MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_UNKNOWN_OPERATION,__LINE__);
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_show_mms_status_icon
 * DESCRIPTION
 *  To show MMS indicator icon
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_show_mms_status_icon(const mmi_mms_bgsr_indicator_type_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_SHOW_MMS_STATUS_ICON,status,__LINE__);
    switch (status)
    {
        case MMI_MMS_BGSR_INDICATOR_IDLE:
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
        case MMI_MMS_BGSR_INDICATOR_BUSY:
            BlinkStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
        default:
            HideStatusIcon(STATUS_ICON_MMS_UNREAD);
            HideStatusIcon(STATUS_ICON_MMS_BUSY);
            break;
    }
    if (GetActiveScreenId() != WAP_SCREEN_WIDGET)
   	{
        UpdateStatusIcons();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_usb_start_cb
 * DESCRIPTION
 *  To handle interrupt end to retry to send and receive
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_usb_start_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_mms_bgsr_msg_struct *message = NULL;
    S16 error;
    kal_uint16 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_USB_START_CB,__LINE__);

    mmi_mms_bgsr_get_mem_status_req();

    if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id != 0)
    {
        mmi_mms_bgsr_abort_send_mms_req(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id);
        message = mmi_mms_bgsr_extract_q(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id,
            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            return;
        }

        message->fail_retry_flag |= MMI_MMS_BGSR_INTERRUPT_USB;
        message->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND;

        mmi_mms_bgsr_enqueue(message, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
        g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id = 0;
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_SEND_ID);
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
        
    }

    if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id != 0)
    {
        mmi_mms_bgsr_abort_download_mms_req(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id);
        message = mmi_mms_bgsr_extract_q(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id,
            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            return;
        }

        message->fail_retry_flag |= MMI_MMS_BGSR_INTERRUPT_USB;
        message->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;

        mmi_mms_bgsr_enqueue(message, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
        g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id = 0;
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_DOWNLOAD_ID);                        

        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);

    }

    mmi_mms_bgsr_show_mms_status_icon(MMI_MMS_BGSR_INDICATOR_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_usb_end_cb
 * DESCRIPTION
 *  To handle interrupt end to retry to send and receive
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_usb_end_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mms_bgsr_interrupt_end_cb(MMI_MMS_BGSR_INTERRUPT_USB);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_interrupt_end_cb
 * DESCRIPTION
 *  To handle interrupt end to retry to send and receive
 * PARAMETERS
 *  status      [IN]        
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_interrupt_end_cb(U32 interrupt_reason)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_mms_bgsr_msg_struct *message = NULL, *to_move_msg = NULL;
    kal_uint32 move_msg_id = 0;
    S16 error;
    kal_uint16 index = 0;
    kal_uint8  retry_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_INTERRUPT_END_CB,interrupt_reason,__LINE__);

    /* start to move msg to send q */
    message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q;
    while(message != NULL)
    {
        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            break;
        }

        if((message->fail_retry_flag & interrupt_reason) != 0)
        {
            retry_flag = 1;
        }
        else
        {
            retry_flag = 0;
        }
        
        message->fail_retry_flag &= !(interrupt_reason);
        if(message->fail_retry_flag == 0 && retry_flag == 1)
        {
            move_msg_id = message->msg_id;
            message = message->next;
            to_move_msg = mmi_mms_bgsr_extract_q(
                            move_msg_id, 
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));

            mmi_mms_bgsr_enqueue(to_move_msg,
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);
            continue;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);

        message = message->next;

    }

    /* start to move msg to download q */        
    message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q;
    while(message != NULL)
    {
        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
            mmi_mms_bgsr_echo_current_info();
            break;
        }
        if((message->fail_retry_flag & interrupt_reason) != 0)
        {
            retry_flag = 1;
        }
        else
        {
            retry_flag = 0;
        }

        message->fail_retry_flag &= !(interrupt_reason);
        if(message->fail_retry_flag == 0 && retry_flag == 1)
        {
            move_msg_id = message->msg_id;
            message = message->next;
            to_move_msg = mmi_mms_bgsr_extract_q(
                            move_msg_id, 
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
            mmi_mms_bgsr_enqueue(to_move_msg,
                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));

            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);
            continue;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);

        message = message->next;
    }

    /* no need to check bgsr is ready or not, 
    cuz mmi_usb_is_in_mass_storage_mode will return TRUE*/
    {
        /* if there is no msg sending, deliver the send req */
        if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id == 0)
        {
            message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q;
            mmi_mms_bgsr_send_mms_req(message);
        }

        /* if there is no msg downloading, deliver the download req */
        if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id == 0)
        {
            message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q;
            mmi_mms_bgsr_download_mms_req(message);
        }
    }

    if( !mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);    
        mmi_mms_bgsr_sync();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_check_popup
 * DESCRIPTION
 *  check the popup display
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_mms_bgsr_check_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pp_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pp_flag = GetInterruptPopupDisplay();
    
    if ((pp_flag & POPUP_DSPL_ON) == 0)
    {
        MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_NO_POPUP,__LINE__);        
        return MMI_MMS_BGSR_POPUP_NO_POPUP;
    }

    if ((pp_flag & POPUP_TONE_ON) == 0)
    {
        MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_NO_SOUND_POPUP,__LINE__);
        return MMI_MMS_BGSR_POPUP_NO_SOUND;
    }
    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_NORMAL_POPUP,__LINE__);
    return MMI_MMS_BGSR_POPUP_NORMAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_echo_current_info
 * DESCRIPTION
 *  echo current infomation
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_echo_current_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_bgsr_msg_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_ID, g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id, g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id);
    msg = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q;
    while(msg != NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_SEND_Q);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_Q,\
            msg->msg_id, \
            msg->ntt, \
            msg->expire_time, \
            msg->status, \
            msg->quota, \
            msg->folder, \
            msg->send_setting, \
            msg->result, \
            msg->fail_retry_flag, \
            msg->size, \
            msg->is_rr, \
            msg->op);
        msg = msg->next;
    }
    msg = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q;
    while(msg != NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_SEND_FAIL_Q);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_Q, \
            msg->msg_id, \
            msg->ntt, \
            msg->expire_time, \
            msg->status, \
            msg->quota, \
            msg->folder, \
            msg->send_setting,\
            msg->result, \
            msg->fail_retry_flag, \
            msg->size, \
            msg->is_rr, \
            msg->op);
        msg = msg->next;
    }
    msg = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q;
    while(msg != NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_DL_Q);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_Q,\
            msg->msg_id, \
            msg->ntt, \
            msg->expire_time, \
            msg->status, \
            msg->quota, \
            msg->folder, \
            msg->send_setting,\
            msg->result, \
            msg->fail_retry_flag, \
            msg->size, \
            msg->is_rr, \
            msg->op);
        msg = msg->next;
    }
    msg = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q;
    while(msg != NULL)
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_DL_FAIL_Q);
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ECHO_CURRENT_INFO_Q,\
            msg->msg_id, \
            msg->ntt, \
            msg->expire_time, \
            msg->status, \
            msg->quota, \
            msg->folder, \
            msg->send_setting,\
            msg->result, \
            msg->fail_retry_flag, \
            msg->size, \
            msg->is_rr, \
            msg->op);
        msg = msg->next;
    }


}
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
