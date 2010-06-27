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
 *  MMSBGSRMain.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Event Handlers and Main flow of the MMS BGSR Application.
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


#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "time.h"

#include "FileManagerGProt.h"
#include "CallManagementGprot.h"
/* For Bearer Type */
#include "Custom_nvram_editor_data_item.h"


#ifndef __MMI_BGSR_PROT_H_
#include "MMSBGSRProt.h"
#endif

#include "USBDeviceGprot.h"
#include "MMSBGSRResDef.h"
#include "USBDeviceGProt.h"
#include "msf_def.h"
#if OBIGO_Q03C
#include "Mea_int.h"
#endif
/* TRACE */

/*******************************************************************************
 * Static Declaration
 *******************************************************************************/
mmi_mms_bgsr_context_struct g_mmi_mms_bgsr_context;
mmi_mms_bgsr_context_struct *mmi_mms_bgsr_p = &g_mmi_mms_bgsr_context;
kal_uint8 mmi_mms_bgsr_adm_mem[MMI_MMS_BGSR_ADM_MEM_SIZE];
mmi_mms_bgsr_msg_struct mmi_mms_bgsr_msg_struct_array[MMI_MMS_BGSR_MAX_MSG_NUM];
kal_uint8 mmi_mms_bgsr_sync_flag = 0;
kal_uint32 mmi_mms_bgsr_free_space = 0;
kal_uint8 mmi_mms_bgsr_mms_storage_exported = 0;
/*******************************************************************************
 * Global Variable
 *******************************************************************************/
/* MMI_MMS_BGSR_CFG_RETRY_INTERVAL can be customized */
static kal_uint8 MMI_MMS_BGSR_CFG_RETRY_INTERVAL[MMI_MMS_BGSR_CFG_RETRY_QUOTA] = {2,2};

/* please specify the callback funciton here */
static mmi_mms_bgsr_callback_struct mmi_mms_bgsr_callback_table
                    [MMI_MMS_BGSR_TOTAL_SOLUTION_NUM][MMI_MMS_BGSR_CALLBACK_NUM] =
{
#if OBIGO_Q03C
    {mmi_mms_send_rsp_callback,
    mmi_mms_cancel_send_rsp_callback,
    mmi_mms_download_rsp_callback,
    mmi_mms_cancel_download_rsp_callback},
#elif JATAAYU4
    {mmi_jmms_send_rsp_callback,
    mmi_jmms_cancel_send_rsp_callback,
    mmi_jmms_download_rsp_callback,
    mmi_jmms_cancel_download_rsp_callback},
#else /*OBIGO_Q05A*/
    {mmi_umms_send_rsp_callback,
    mmi_umms_cancel_send_rsp_callback,
    mmi_umms_download_rsp_callback,
    mmi_umms_cancel_download_rsp_callback},*/
#endif
    {
    NULL,
    NULL,
    NULL,
    NULL
    }
};

/*******************************************************************************
 * Local Function
 *******************************************************************************/

/*******************************************************************************
 * Global Function
 *******************************************************************************/

extern pBOOL mmi_bootup_get_active_flight_mode(void);
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_init
 * DESCRIPTION
 *  init the bgsr module
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    mmi_mms_bgsr_init_context();    /* init context */
    mmi_mms_bgsr_create_adm_mem();  /* create adm memory */
    mmi_mms_bgsr_init_msg_array();  /* init array */
    mmi_mms_bgsr_sync();

    if(mmi_mms_bgsr_is_sync())
    {
        StartTimer(MMI_MMS_BGSR_TIMER, 
                    MMI_MMS_BGSR_CFG_RETRY_TIMER * 60000, 
                    mmi_mms_bgsr_timeout_procedure);
    }
    else
    {
        StartTimer(MMI_MMS_BGSR_TIMER, 
                    MMI_MMS_BGSR_FAST_TIMEOUT_TIMER, 
                    mmi_mms_bgsr_timeout_procedure);
    }
    mmi_mms_bgsr_get_mem_status_req();
    if(mmi_mms_bgsr_is_ready())
    {
        /* start to send and download message */
        message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q;
        if(message != NULL)
        {
            mmi_mms_bgsr_send_mms_req(message);
        }
        else
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id = 0;
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_SEND_ID);
        }

        message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q;
        if(message != NULL)
        {
            mmi_mms_bgsr_download_mms_req(message);
        }
        else
        {
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id = 0;
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_DOWNLOAD_ID);                            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_terminate
 * DESCRIPTION
 *  terminate the bgsr module
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_terminate(void)
{
    StopTimer(MMI_MMS_BGSR_TIMER);
    kal_adm_free(g_mmi_mms_bgsr_context.mem_pool_id, mmi_mms_bgsr_msg_struct_array);
    kal_adm_delete(g_mmi_mms_bgsr_context.mem_pool_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_init_context
 * DESCRIPTION
 *  init the bgsr context
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    
    memset(mmi_mms_bgsr_p, 0 , sizeof(mmi_mms_bgsr_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_create_adm_mem
 * DESCRIPTION
 *  create adm memory
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_create_adm_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    g_mmi_mms_bgsr_context.mem_pool_id = kal_adm_create(mmi_mms_bgsr_adm_mem,
                                        MMI_MMS_BGSR_ADM_MEM_SIZE,
                                        NULL,
                                        KAL_FALSE);

    MMI_ASSERT(g_mmi_mms_bgsr_context.mem_pool_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_init_msg_array
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_init_msg_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    int i = 0;
    S16 error;
    S32 readSize = 0;
    U8 totalRecord = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    memset(mmi_mms_bgsr_msg_struct_array, 0 , sizeof(mmi_mms_bgsr_msg_struct)*MMI_MMS_BGSR_MAX_MSG_NUM);        

    /*read array from nvram */
    while (totalRecord < MMI_MMS_BGSR_MAX_MSG_NUM)
    {
        readSize = ReadMultiRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16) totalRecord + 1,
            &(mmi_mms_bgsr_msg_struct_array[totalRecord]),
            sizeof(mmi_mms_bgsr_msg_struct) * MMI_MMS_BGSR_MAX_MSG_NUM,
            MMI_MMS_BGSR_MAX_MSG_NUM,
            &error);
        
        totalRecord += (U8)(readSize / sizeof(mmi_mms_bgsr_msg_struct));
    }     

    for(i=0;i<MMI_MMS_BGSR_MAX_MSG_NUM;i++)
    {
        mmi_mms_bgsr_msg_struct_array[i].next = NULL;
        if(mmi_mms_bgsr_msg_struct_array[i].msg_id != 0)
        {
            switch(mmi_mms_bgsr_msg_struct_array[i].status)
            {
                case    MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND:
                    if(mmi_mms_bgsr_msg_struct_array[i].ntt == 0)
                    {
                        mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
                    }
                    else if(mmi_mms_bgsr_msg_struct_array[i].quota <= MMI_MMS_BGSR_CFG_RETRY_QUOTA)
                    {
                        mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                    }
                    else
                    {
                        mmi_mms_bgsr_msg_struct_array[i].msg_id = 0;
                        mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
                    }
                    break;
                case    MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
                    if(mmi_mms_bgsr_msg_struct_array[i].ntt == 0 &&
                       mmi_mms_bgsr_msg_struct_array[i].expire_time > 0)
                    {
                        mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
                    }
                    else if(mmi_mms_bgsr_msg_struct_array[i].quota <= MMI_MMS_BGSR_CFG_RETRY_QUOTA)
                    {
                        mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
                    }
                    else
                    {
                        mmi_mms_bgsr_msg_struct_array[i].msg_id = 0;                    
                        mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
                    }
                    
                    break;
                case    MMI_MMS_BGSR_STATUS_SENDING:
                    mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
                    break;
                case    MMI_MMS_BGSR_STATUS_SEND_FAIL:
                case    MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND:
                case    MMI_MMS_BGSR_STATUS_SAVING:
                case    MMI_MMS_BGSR_STATUS_DELETING:
                    mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                    break;
                case    MMI_MMS_BGSR_STATUS_DOWNLOADING:
                    mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
                    break;
                case    MMI_MMS_BGSR_STATUS_DOWNLOAD_FAIL:
                case    MMI_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD:
                    mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
                    break;
                default:
                    mmi_mms_bgsr_msg_struct_array[i].msg_id = 0;
                    mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
                    break;
            }
        }
        else
        {
            mmi_mms_bgsr_enqueue(&(mmi_mms_bgsr_msg_struct_array[i]),
                &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_timeout_procedue
 * DESCRIPTION
 *  timeout procedure, 
 *  1. decrease the ntt (and expire time for DL q)
 *  2. move the msg to send / download q
 *  3. deliver the request to send and downlaod
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_timeout_procedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    mmi_mms_bgsr_msg_struct *message = NULL, *to_move_msg = NULL;
    kal_uint32 move_msg_id = 0;
    S16 error;
    kal_uint16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_TIMEOUT_PROCEDURE,__LINE__);
    mmi_mms_bgsr_get_mem_status_req();

    if(!mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);
        mmi_mms_bgsr_sync();
/*        if( !mmi_mms_bgsr_is_sync())
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);
            mmi_mms_bgsr_sync();
        }*/
        StartTimer(MMI_MMS_BGSR_TIMER, 
                    MMI_MMS_BGSR_FAST_TIMEOUT_TIMER, 
                    mmi_mms_bgsr_timeout_procedure);
        
        return;
    }


    /* decrease the next transmission time of each msg in send fail q*/
    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_DECREASE_NTT,__LINE__);    
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
        if(message->ntt > 0)
        {
            message->ntt --;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
        message = message->next;
    }

    /* decrease the next transmission time of each msg in download fail q*/    
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
        if(message->ntt > 0)
        {
            message->ntt --;
        }
        if(message->expire_time > 0)
        {
            message->expire_time -= 60*MMI_MMS_BGSR_CFG_RETRY_TIMER;
        }
        WriteRecord(
            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
            (U16)(index+1),
            &(mmi_mms_bgsr_msg_struct_array[index]),
            NVRAM_BGSR_MSG_STRUCT_SIZE,
            &error);
        message = message->next;
    }

    /* if the conditions are satified, start to move msg to send q / downlaod q*/
    if( mmi_mms_bgsr_is_ready())
    {
        /* start to move msg to send q */
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MOVE_MSG_FROM_FAIL_Q,__LINE__);            
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
            if(message->ntt == 0 && 
               message->quota > 0 &&
               message->status == MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND &&
               message->result != MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
               {
                    move_msg_id = message->msg_id;
                    message = message->next;
                    to_move_msg = mmi_mms_bgsr_extract_q(
                                    move_msg_id, 
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                    if(to_move_msg->quota > 0)
                    {
                        to_move_msg->quota--;
                    }
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
            if(message->ntt == 0 && 
               message->quota > 0 &&
               message->status == MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD &&
               message->result != MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT &&
               message->expire_time > 0)
                {
                    move_msg_id = message->msg_id;
                    message = message->next;
                    to_move_msg = mmi_mms_bgsr_extract_q(
                                    move_msg_id, 
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
                    if(to_move_msg->quota > 0)
                    {
                        to_move_msg->quota--;
                    }
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

        /* if there is no msg sending, deliver the send req */
        if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id == 0)
        {
            message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q;
            mmi_mms_bgsr_send_mms_req(message);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ALREADY_A_SENDING_MSG, g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id,__LINE__);    
        }

        /* if there is no msg downloading, deliver the download req */
        if(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id == 0)
        {
            message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q;
            mmi_mms_bgsr_download_mms_req(message);
        }
        else
        {
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG, g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id,__LINE__);    
        }
        
    }
    else if( !mmi_mms_bgsr_is_sync())
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_SYNC,__LINE__);        
        mmi_mms_bgsr_sync();
    }
    else
    {
        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_READY,__LINE__);
    }

    StartTimer(MMI_MMS_BGSR_TIMER, 
                MMI_MMS_BGSR_CFG_RETRY_TIMER * 60000, 
                mmi_mms_bgsr_timeout_procedure);

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_TIMEOUT_PROCEDURE_FINISH,__LINE__);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_translate_msg_id_to_nvram_ind
 * DESCRIPTION
 *  translate msg id to nvram index
 * PARAMETERS
 *  mma_result
 * RETURNS
 *  mmi_mms_bgsr_result_enum
 *****************************************************************************/
U16 mmi_mms_bgsr_translate_msg_id_to_nvram_ind(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_TRANSLATE_MSG_ID_TO_NVRAM_IND,msg_id,__LINE__);

    for(i=0;i<MMI_MMS_BGSR_MAX_MSG_NUM;i++)
    {
        if(mmi_mms_bgsr_msg_struct_array[i].msg_id == msg_id)
        {
            return i;
        }
    }

    return i;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_translate_result
 * DESCRIPTION
 *  translate mms result into mms bgsr result
 * PARAMETERS
 *  mma_result
 * RETURNS
 *  mmi_mms_bgsr_result_enum
 *****************************************************************************/
mmi_mms_bgsr_result_enum mmi_mms_bgsr_translate_result(
                            mma_result_enum mma_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_TRANSLATE_RESULT,mma_result,__LINE__);

    switch( mma_result )
    {
        case    MMA_RESULT_OK:
            return  MMI_MMS_BGSR_RESULT_OK;
        case    MMA_RESULT_FAIL_IN_CALL:                    
            return  MMI_MMS_BGSR_RESULT_FAIL_INCALL;
        case    MMA_RESULT_FAIL_NOT_READY:                  
            return  MMI_MMS_BGSR_RESULT_FAIL_NOT_READY;
        case    MMA_RESULT_FAIL_BUSY:                 
            return  MMI_MMS_BGSR_RESULT_FAIL_BUSY;
        case    MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:        
            return  MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY;            
        case    MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:       
            return  MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case    MMA_RESULT_FAIL_FILE_NOT_FOUND:             
            return  MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;            
        case    MMA_RESULT_FAIL_FILE_CORRUPTED:            
            return  MMI_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED;            
        case    MMA_RESULT_FAIL_FILE_IN_USE:               
            return  MMI_MMS_BGSR_RESULT_FAIL_FILE_IN_USE;            
        case    MMA_RESULT_FAIL_FILE_IO:                
            return  MMI_MMS_BGSR_RESULT_FAIL_FILE_IO;                        
        case    MMA_RESULT_FAIL_FOLDER_NOT_FOUND:   
            return  MMI_MMS_BGSR_RESULT_FAIL_FOLDER_NOT_FOUND;
        case    MMA_RESULT_FAIL_UNSUPPORT_CONTENT:          
            return  MMI_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT;
        case    MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:     
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;            
        case    MMA_RESULT_FAIL_COMM_CONFIG_ERROR:          
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR;            
        case    MMA_RESULT_FAIL_COMM_CONNECT_ERROR:         
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR;            
        case    MMA_RESULT_FAIL_COMM_SERVER_ERROR:          
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR;            
        case    MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT:        
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT;                        
        case    MMA_RESULT_FAIL_COMM_SERVICE_DENIED:        
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED;                        
        case    MMA_RESULT_FAIL_COMM_UNKNOWN_APN:           
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_UNKNOWN_APN;                        
        case    MMA_RESULT_FAIL_COMM_UNAUTHORIZED:          
            return  MMI_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED;                        
        case    MMA_RESULT_FAIL_USER_CANCEL:                
            return  MMI_MMS_BGSR_RESULT_FAIL_USER_CANCEL;
        case    MMA_RESULT_FAIL_INVALID_PARAMETER:      
            return  MMI_MMS_BGSR_RESULT_FAIL_INVALID_PARAMETER;                                    
        case    MMA_RESULT_FAIL_INVALID_MSGID:              
            return  MMI_MMS_BGSR_RESULT_FAIL_INVALID_MSGID;
        case    MMA_RESULT_FAIL_INVALID_FOLDER:            
            return  MMI_MMS_BGSR_RESULT_FAIL_INVALID_FOLDER;            
        case    MMA_RESULT_FAIL_QUEUE_FULL:                
            return  MMI_MMS_BGSR_RESULT_FAIL_QUEUE_FULL;            
        case    MMA_RESULT_FAIL_MSGID_IS_USING:        
            return  MMI_MMS_BGSR_RESULT_FAIL_MSGID_IS_USING;            
        case    MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED:    
            return  MMI_MMS_BGSR_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED;            
        case    MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM:         
            return  MMI_MMS_BGSR_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM;            
        case    MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:    
            return  MMI_MMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;   
        case    MMA_RESULT_FAIL:                            
        default:
            return  MMI_MMS_BGSR_RESULT_FAIL;   
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_translate_result_to_strid
 * DESCRIPTION
 *  translate bgsr result to string ID
 * PARAMETERS
 *  bgsr_result          [IN]    BGSR result
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_mms_bgsr_translate_result_to_strid(mmi_mms_bgsr_result_enum bgsr_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_TRANSLATE_RESULT_TO_STRID,bgsr_result,__LINE__);

    switch( bgsr_result )
    {
        case    MMI_MMS_BGSR_RESULT_OK:
            return  STR_ID_BGSR_RESULT_OK;
        case    MMI_MMS_BGSR_RESULT_FAIL_INCALL:                    
            return  STR_ID_BGSR_RESULT_FAIL_INCALL;
        case    MMI_MMS_BGSR_RESULT_FAIL_NOT_READY:                  
            return  STR_ID_BGSR_RESULT_FAIL_NOT_READY;
        case    MMI_MMS_BGSR_RESULT_FAIL_BUSY:                 
            return  STR_ID_BGSR_RESULT_FAIL_BUSY;
        case    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY:        
            return  STR_ID_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY;
        case    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE:       
            return  STR_ID_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND:             
            return  STR_ID_BGSR_RESULT_FAIL_FILE_NOT_FOUND;     
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED:            
            return  STR_ID_BGSR_RESULT_FAIL_FILE_CORRUPTED;            
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_IN_USE:               
            return  STR_ID_BGSR_RESULT_FAIL_FILE_IN_USE;            
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_IO:                
            return  STR_ID_BGSR_RESULT_FAIL_FILE_IO;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_FOLDER_NOT_FOUND:   
            return  STR_ID_BGSR_RESULT_FAIL_FOLDER_NOT_FOUND;
        case    MMI_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT:          
            return  STR_ID_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT;
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:     
            return  STR_ID_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR:          
            return  STR_ID_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR:         
            return  STR_ID_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR:          
            return  STR_ID_BGSR_RESULT_FAIL_COMM_SERVER_ERROR;            
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT:        
            return  STR_ID_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED:        
            return  STR_ID_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNKNOWN_APN:           
            return  STR_ID_BGSR_RESULT_FAIL_COMM_UNKNOWN_APN;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED:          
            return  STR_ID_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED;                        
        case    MMI_MMS_BGSR_RESULT_FAIL_USER_CANCEL:                
            return  STR_ID_BGSR_RESULT_FAIL_USER_CANCEL;
        case    MMI_MMS_BGSR_RESULT_FAIL_INVALID_PARAMETER:      
            return  STR_ID_BGSR_RESULT_FAIL_INVALID_PARAMETER;                                    
        case    MMI_MMS_BGSR_RESULT_FAIL_INVALID_MSGID:              
            return  STR_ID_BGSR_RESULT_FAIL_INVALID_MSGID;
        case    MMI_MMS_BGSR_RESULT_FAIL_INVALID_FOLDER:            
            return  STR_ID_BGSR_RESULT_FAIL_INVALID_FOLDER;            
        case    MMI_MMS_BGSR_RESULT_FAIL_QUEUE_FULL:                
            return  STR_ID_BGSR_RESULT_FAIL_QUEUE_FULL;            
        case    MMI_MMS_BGSR_RESULT_FAIL_MSGID_IS_USING:        
            return  STR_ID_BGSR_RESULT_FAIL_MSGID_IS_USING;            
        case    MMI_MMS_BGSR_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED:    
            return  STR_ID_BGSR_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED;            
        case    MMI_MMS_BGSR_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM:         
            return  STR_ID_BGSR_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM;            
        case    MMI_MMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:    
            return  STR_ID_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;   
        case    MMI_MMS_BGSR_RESULT_FAIL:                            
        default:
            return  STR_ID_BGSR_RESULT_FAIL;   
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_action_fsm
 * DESCRIPTION
 *  FSM for BGSR action
 * PARAMETERS
 *  action          [IN]    action type
 *  rsp             [IN]    response struct
 *  text            [IN]    response texts
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_bgsr_action_fsm (mmi_mms_bgsr_action_type_enum action,
                                        void *rsp,
                                        U16 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    kal_uint16 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_ACTION_FSM,action,__LINE__);
    
    switch (action)
    {
        case    MMI_MMS_BGSR_ACTION_GET_MEM_STATUS_RSP:
        {
            wap_mma_get_mem_status_rsp_struct *mem_status_rsp = 
                (wap_mma_get_mem_status_rsp_struct *)rsp;

            if(mem_status_rsp->result == MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE)
            {
                mmi_mms_bgsr_mms_storage_exported = 1;
            }
            else
            {
                mmi_mms_bgsr_free_space = mem_status_rsp->free_size;
                MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_FREE_SIZE,mmi_mms_bgsr_free_space,__LINE__);
            }            
            break;
        }
        case    MMI_MMS_BGSR_ACTION_SEND_RSP:
        {
            wap_mma_send_rsp_struct *send_rsp = (wap_mma_send_rsp_struct*) rsp;
            mmi_mms_bgsr_msg_struct *message = NULL;

            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id = 0;
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_SEND_ID);            

            /* find it out from send q or send fail q */
            message = mmi_mms_bgsr_extract_q( send_rsp->msg_id,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
            if(message == NULL)
            {
                message = mmi_mms_bgsr_extract_q( send_rsp->msg_id,
                                        &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
            }
            if(message == NULL)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
                mmi_mms_bgsr_echo_current_info();
                return;
            }
            message->result = mmi_mms_bgsr_translate_result(send_rsp->result);
            index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
            if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                mmi_mms_bgsr_echo_current_info();
                break;
            }
            
            if( message->result == MMI_MMS_BGSR_RESULT_OK)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_OK,__LINE__);                
                if(send_rsp->rr_id == 0)
                {
                     /* if it isn't a read report,check the send setting */
                    if(message->send_setting == MMI_MMS_BGSR_SETTING_SEND_ONLY)
                    {
                        message->status = MMI_MMS_BGSR_STATUS_DELETING;                
                        mmi_mms_bgsr_delete_mms_req(message->msg_id);
                    }
                    else if(message->send_setting == MMI_MMS_BGSR_SETTING_SAVE_AND_SEND)
                    {
                        message->status = MMI_MMS_BGSR_STATUS_SAVING;
                        mmi_mms_bgsr_save_mms_req(message->msg_id, MMA_FOLDER_SENT);
                    }

                    (mmi_mms_bgsr_callback_table[0][0].send_rsp_callback)
                                            (message->msg_id, message->result, text);

                    mmi_mms_bgsr_enqueue(message,
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                }
                else
                {
                    /* if it's a read report, simply delete it */
                    mmi_mms_bgsr_delete_mms_req(send_rsp->rr_id);
                }
            }
            else
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_FAIL,__LINE__);                
            
                if(send_rsp->rr_id == 0)
                {
                     /* if it isn't a read report,check the fail reason */
    				kal_uint8 fail_flag = 0;
                    if(isInCall())
                    {
                        fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_CALL;
                    }
#ifdef  __USB_IN_NORMAL_MODE__
                    if(mmi_usb_is_in_mass_storage_mode() && mmi_mms_bgsr_mms_is_exported())
                    {
                        fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_USB;
                    }
#endif  /*__USB_IN_NORMAL_MODE__*/
                    if(!wap_is_ready())
                    {
                        fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_WAP_RESET;
                    }
                    if(mmi_bootup_get_active_flight_mode())
                    {
                         fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_FLIGHT_MODE;
                    }

                    message->fail_retry_flag = fail_flag;

					if(message->quota == MMI_MMS_BGSR_CFG_RETRY_QUOTA &&
						message->ntt == 0 && 
						message->status != MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND)
                    {
                        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
                        {
                            DisplayPopup((U8 *)GetString(STR_ID_BGSR_SEND_FAIL_RESEND),
                                         IMG_GLOBAL_ERROR,
                                         1,
                                         MMI_MMS_BGSR_POPUP_TIME,
                                         EMPTY_LIST_TONE);
                        }
                        else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                        {
                            DisplayPopup((U8 *)GetString(STR_ID_BGSR_SEND_FAIL_RESEND),
                                         IMG_GLOBAL_ERROR,
                                         1,
                                         MMI_MMS_BGSR_POPUP_TIME,
                                         0);
                        }
                    }

                    if(message->quota > 0 && 
                        message->result != MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
                    {
                        if(message->status != MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND)
                        {
                            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_RETRY,__LINE__);                        
                            message->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND;
                            message->ntt = MMI_MMS_BGSR_CFG_RETRY_INTERVAL[MMI_MMS_BGSR_CFG_RETRY_QUOTA - message->quota];
                            (mmi_mms_bgsr_callback_table[0][0].send_rsp_callback)
                                            (message->msg_id, message->result, text); 
                        }
                    }
                    else
                    {
                        /* if the quota is used up, popup to inform user */
                        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_RETRY,__LINE__);
                        message->status = MMI_MMS_BGSR_STATUS_SEND_FAIL;
                        (mmi_mms_bgsr_callback_table[0][0].send_rsp_callback)
                                            (message->msg_id, message->result, text); 

                        if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
                        {
                            if( text == NULL)
                            {
                                DisplayPopup((U8 *)GetString(
                                                mmi_mms_bgsr_translate_result_to_strid(
                                                    message->result)),
                                             IMG_GLOBAL_ERROR,
                                             1,
                                             MMI_MMS_BGSR_POPUP_TIME,
                                             EMPTY_LIST_TONE);
                            }
                            else
                            {
                                DisplayPopup((U8 *)text,
                                             IMG_GLOBAL_ERROR,
                                             1,
                                             MMI_MMS_BGSR_POPUP_TIME,
                                             EMPTY_LIST_TONE);
                            }
                        }
                        else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                        {
                            if( text == NULL)
                            {
                                DisplayPopup((U8 *)GetString(
                                                mmi_mms_bgsr_translate_result_to_strid(
                                                    message->result)),
                                             IMG_GLOBAL_ERROR,
                                             1,
                                             MMI_MMS_BGSR_POPUP_TIME,
                                             0);
                            }
                            else
                            {
                                DisplayPopup((U8 *)text,
                                             IMG_GLOBAL_ERROR,
                                             1,
                                             MMI_MMS_BGSR_POPUP_TIME,
                                             0);
                            }
                        }
                    }

                    mmi_mms_bgsr_enqueue(message, 
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));

                }
                else
                {
                    /* if it's a read report, replace the original message in the q */
                    message->msg_id = send_rsp->rr_id;
                    if(message->quota > 0 && 
                        message->result != MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
                    {
                        message->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND;
                        message->ntt = MMI_MMS_BGSR_CFG_RETRY_INTERVAL[MMI_MMS_BGSR_CFG_RETRY_QUOTA - message->quota];
                        (mmi_mms_bgsr_callback_table[0][0].send_rsp_callback)
                                            (message->msg_id, message->result, text); 
                    }
                    else
                    {
                        message->status = MMI_MMS_BGSR_STATUS_SEND_FAIL;
                        (mmi_mms_bgsr_callback_table[0][0].send_rsp_callback)
                                            (message->msg_id, message->result, text); 

                    }
                    mmi_mms_bgsr_enqueue(message, 
                                    &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                }
            }

            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);

            message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q;

            if(message != NULL)
            {
                /*send the next message */
                mmi_mms_bgsr_send_mms_req(message);

                index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
                if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
                {
                    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                    mmi_mms_bgsr_echo_current_info();
                    break;
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

        case    MMI_MMS_BGSR_ACTION_CANCEL_SEND_RSP:
        {
            /*just need to refresh the folder*/
            wap_mma_rsp_struct *cancel_send_rsp = (wap_mma_rsp_struct*)rsp;
			if (mmi_mms_bgsr_translate_result(cancel_send_rsp->result) != MMI_MMS_BGSR_RESULT_OK)
			{
                if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)			
                {
                    DisplayPopup((U8 *)GetString(
                                    mmi_mms_bgsr_translate_result_to_strid(
                                        mmi_mms_bgsr_translate_result(cancel_send_rsp->result))),
                                 IMG_GLOBAL_ERROR,
                                 1,
                                 MMI_MMS_BGSR_POPUP_TIME,
                                 EMPTY_LIST_TONE);
                }
                else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                {
                    DisplayPopup((U8 *)GetString(
                                    mmi_mms_bgsr_translate_result_to_strid(
                                        mmi_mms_bgsr_translate_result(cancel_send_rsp->result))),
                                 IMG_GLOBAL_ERROR,
                                 1,
                                 MMI_MMS_BGSR_POPUP_TIME,
                                 0);
                }
                break;
			}
			else
			{
                if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)			
                {
                    DisplayPopup(
                    (U8 *) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MMI_MMS_BGSR_POPUP_TIME,
                    (U8) SUCCESS_TONE);
                }
                else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                {
                    DisplayPopup(
                    (U8 *) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MMI_MMS_BGSR_POPUP_TIME,
                    0);
                }

			}
            index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(cancel_send_rsp->msg_id);
/*            g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_msg_id = 0;*/
            if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                mmi_mms_bgsr_echo_current_info();
                break;
            }
            (mmi_mms_bgsr_callback_table[0][0].cancel_send_rsp_callback)
                            (cancel_send_rsp->msg_id, cancel_send_rsp->result);            
            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);

            
            break;
        }
        case    MMI_MMS_BGSR_ACTION_DOWNLOAD_RSP:
        {

            wap_mma_download_rsp_struct *dl_rsp = (wap_mma_download_rsp_struct*) rsp;
            mmi_mms_bgsr_msg_struct *message = NULL;

            message = mmi_mms_bgsr_extract_q( g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id,
                                              &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
            if(message == NULL)
            {
                message = mmi_mms_bgsr_extract_q( g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id,
                                                  &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
            }
            if(message == NULL)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
                mmi_mms_bgsr_echo_current_info();
                return;
            }
            message->result = mmi_mms_bgsr_translate_result(dl_rsp->result);
            index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);
            if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                mmi_mms_bgsr_echo_current_info();
                break;
            }
            
            if( message->result == MMI_MMS_BGSR_RESULT_OK)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_OK,__LINE__);                
                /* if the result is OK, just remove it */            
                (mmi_mms_bgsr_callback_table[0][0].download_rsp_callback)
                                        (dl_rsp->msg_id, message->result, text);                
                message->msg_id = 0;
                mmi_mms_bgsr_enqueue(message, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
            }
            else
            {
                /* check the fail result */
				kal_uint8 fail_flag = 0;

                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_FAIL,__LINE__);                                
                if(isInCall())
                {
                    fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_CALL;
                }
#ifdef __USB_IN_NORMAL_MODE__
                if(mmi_usb_is_in_mass_storage_mode() && mmi_mms_bgsr_mms_is_exported())
                {
                    fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_USB;
                }
#endif /*__USB_IN_NORMAL_MODE__*/
                if(!wap_is_ready())
                {
                    fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_WAP_RESET;
                }
                if(mmi_bootup_get_active_flight_mode())
                {
                     fail_flag = fail_flag | MMI_MMS_BGSR_INTERRUPT_FLIGHT_MODE;
                }

                message->fail_retry_flag = fail_flag;

                if(message->quota > 0 &&
                    message->result != MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
                {
                    if(message->status != MMI_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD)
                    {
                        MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_RETRY,__LINE__);
                        message->status = MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
                        message->ntt = MMI_MMS_BGSR_CFG_RETRY_INTERVAL[MMI_MMS_BGSR_CFG_RETRY_QUOTA - message->quota];                    
                        (mmi_mms_bgsr_callback_table[0][0].download_rsp_callback)
                                            (dl_rsp->msg_id, message->result, text);                
                    }
                }
                else
                {
                    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NOT_RETRY,__LINE__);                
                    /*if the quota is used up, popup to inform user */
                    message->status = MMI_MMS_BGSR_STATUS_DOWNLOAD_FAIL;

                    (mmi_mms_bgsr_callback_table[0][0].download_rsp_callback)
                                        (message->msg_id, message->result, text);                    
                    if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
                    {
                        if( text == NULL)
                        {
                            DisplayPopup((U8 *)GetString(
                                            mmi_mms_bgsr_translate_result_to_strid(
                                                message->result)),
                                         IMG_GLOBAL_ERROR,
                                         1,
                                         MMI_MMS_BGSR_POPUP_TIME,
                                         EMPTY_LIST_TONE);
                        }
                        else
                        {
                            DisplayPopup((U8 *)text,
                                         IMG_GLOBAL_ERROR,
                                         1,
                                         MMI_MMS_BGSR_POPUP_TIME,
                                         EMPTY_LIST_TONE);
                        }
                    }                    
                    else if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)
                    {
                        if( text == NULL)
                        {
                            DisplayPopup((U8 *)GetString(
                                            mmi_mms_bgsr_translate_result_to_strid(
                                                message->result)),
                                         IMG_GLOBAL_ERROR,
                                         1,
                                         MMI_MMS_BGSR_POPUP_TIME,
                                         0);
                        }
                        else
                        {
                            DisplayPopup((U8 *)text,
                                         IMG_GLOBAL_ERROR,
                                         1,
                                         MMI_MMS_BGSR_POPUP_TIME,
                                         0);
                        }
                    }
                }

                mmi_mms_bgsr_enqueue(message,
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));

            }

            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);

            message = g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q;
            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id = 0;
            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_CLEAR_DOWNLOAD_ID);                            
            if(message != NULL)
            {
                /*download the next message */
                mmi_mms_bgsr_download_mms_req(message);
                index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(message->msg_id);                
                if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
                {
                    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                    mmi_mms_bgsr_echo_current_info();
                    break;
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
        case    MMI_MMS_BGSR_ACTION_CANCEL_DOWNLOAD_RSP:
        {
            /*just need to refresh the folder*/
            wap_mma_rsp_struct *cancel_dl_rsp = (wap_mma_rsp_struct*)rsp;
			if (mmi_mms_bgsr_translate_result(cancel_dl_rsp->result) != MMI_MMS_BGSR_RESULT_OK)
			{
                if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)			
                {
                    DisplayPopup((U8 *)GetString(
                                    mmi_mms_bgsr_translate_result_to_strid(
                                        mmi_mms_bgsr_translate_result(cancel_dl_rsp->result))),
                                 IMG_GLOBAL_ERROR,
                                 1,
                                 MMI_MMS_BGSR_POPUP_TIME,
                                 EMPTY_LIST_TONE);
                }
                else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                {
                    DisplayPopup((U8 *)GetString(
                                    mmi_mms_bgsr_translate_result_to_strid(
                                        mmi_mms_bgsr_translate_result(cancel_dl_rsp->result))),
                                 IMG_GLOBAL_ERROR,
                                 1,
                                 MMI_MMS_BGSR_POPUP_TIME,
                                 0);
                }
                break;
			}
			else
			{
                if( mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NORMAL)			
                {
                    DisplayPopup(
                    (U8 *) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MMI_MMS_BGSR_POPUP_TIME,
                    (U8) SUCCESS_TONE);
                }
                else if(mmi_mms_bgsr_check_popup() == MMI_MMS_BGSR_POPUP_NO_SOUND)
                {
                    DisplayPopup(
                    (U8 *) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    MMI_MMS_BGSR_POPUP_TIME,
                    0);
                }

			}
            index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(cancel_dl_rsp->msg_id);
/*            g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_msg_id = 0;*/
            if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                mmi_mms_bgsr_echo_current_info();
                break;
            }
            
            (mmi_mms_bgsr_callback_table[0][0].cancel_download_rsp_callback)
                                    (cancel_dl_rsp->msg_id, cancel_dl_rsp->result); 
            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);

            break;
        }
        case    MMI_MMS_BGSR_ACTION_SAVE_RSP:
        {
            wap_mma_rsp_struct *save_rsp = (wap_mma_rsp_struct*)rsp;
            mmi_mms_bgsr_msg_struct *message;
            if( mmi_mms_bgsr_find_q(save_rsp->msg_id,
                                    NULL,
                                    g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q))
            {
                index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(save_rsp->msg_id);            
                if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
                {
                    MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                    mmi_mms_bgsr_echo_current_info();
                    break;
                }

                message = mmi_mms_bgsr_extract_q(save_rsp->msg_id,
                                 &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));

                message->msg_id = 0;
                mmi_mms_bgsr_enqueue(message, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));


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
            
            break;

        }
        case    MMI_MMS_BGSR_ACTION_DELETE_RSP:
        {
            wap_mma_rsp_struct *delete_rsp = (wap_mma_rsp_struct*)rsp;
            mmi_mms_bgsr_msg_struct *message = NULL;
            message = mmi_mms_bgsr_extract_q(delete_rsp->msg_id,
                                       &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
            if(message == NULL)
            {
                message = mmi_mms_bgsr_extract_q(delete_rsp->msg_id,
                                           &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
            }
            if(message == NULL)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_MSG_NOT_FOUND,__LINE__);
                mmi_mms_bgsr_echo_current_info();
                break;
            }
            index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(delete_rsp->msg_id);
            if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
            {
                MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                mmi_mms_bgsr_echo_current_info();
                break;
            }

            message->msg_id = 0;
            mmi_mms_bgsr_enqueue(message, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
            WriteRecord(
                NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                (U16)(index+1),
                &(mmi_mms_bgsr_msg_struct_array[index]),
                NVRAM_BGSR_MSG_STRUCT_SIZE,
                &error);
            break;

        }
        case MMI_MMS_BGSR_ACTION_SYNC_MSG_RSP:
        {
            wap_mma_msg_is_valid_rsp_struct *sync_rsp = 
                (wap_mma_msg_is_valid_rsp_struct*)rsp;
            int i;
            mmi_mms_bgsr_msg_struct *local_msg = NULL;
            
            if(mmi_mms_bgsr_is_sync())
            {
                break;
            }

            if(sync_rsp->result == MMA_RESULT_OK)
            {
                for(i = 0; i < MMI_MMS_BGSR_MAX_MSG_NUM ; i++ )   
                {
                    if( mmi_mms_bgsr_msg_struct_array[i].msg_id != 0 &&
                           (sync_rsp->msg_validity_list[i] != 1) )
                    {
                        index = mmi_mms_bgsr_translate_msg_id_to_nvram_ind(mmi_mms_bgsr_msg_struct_array[i].msg_id);
                        if(index >= MMI_MMS_BGSR_MAX_MSG_NUM)
                        {
                            MMI_TRACE(MMI_TRACE_INFO, MMI_MMS_BGSR_NVRAM_IDX_EXCEED,__LINE__);    
                            mmi_mms_bgsr_echo_current_info();
                            break;
                        }
                        local_msg = mmi_mms_bgsr_extract_q(mmi_mms_bgsr_msg_struct_array[i].msg_id, 
                            &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_q));
                        if(local_msg == NULL)
                        {
                            local_msg = mmi_mms_bgsr_extract_q(mmi_mms_bgsr_msg_struct_array[i].msg_id, 
                                &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_send_fail_q));
                        }
                        if(local_msg == NULL)
                        {
                            local_msg = mmi_mms_bgsr_extract_q(mmi_mms_bgsr_msg_struct_array[i].msg_id, 
                                &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_q));
                        }
                        if(local_msg == NULL)
                        {
                            local_msg = mmi_mms_bgsr_extract_q(mmi_mms_bgsr_msg_struct_array[i].msg_id, 
                                &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_download_fail_q));
                        }
                        local_msg->msg_id = 0;
                        mmi_mms_bgsr_enqueue(local_msg, &(g_mmi_mms_bgsr_context.mmi_mms_bgsr_free_q));
                        WriteRecord(
                            NVRAM_EF_MMS_BGSR_MSG_STRUCT_LID,
                            (U16)(index+1),
                            &(mmi_mms_bgsr_msg_struct_array[index]),
                            NVRAM_BGSR_MSG_STRUCT_SIZE,
                            &error);

                    }
                }
                mmi_mms_bgsr_sync_flag = TRUE;

                StartTimer(MMI_MMS_BGSR_TIMER, 
                            MMI_MMS_BGSR_CFG_RETRY_TIMER * 60000, 
                            mmi_mms_bgsr_timeout_procedure);
                
            }
            
            break;
        }
        default:
        {
            MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_UNKNOWN_OPERATION,__LINE__);            
            MMI_ASSERT(0);
        }

    }
    MMI_TRACE(MMI_TRACE_INFO,MMI_MMS_BGSR_ACTION_FSM_FINISH,action,__LINE__);

    if(text != NULL)
    {
        kal_adm_free(g_mmi_mms_bgsr_context.mem_pool_id, text);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_is_ready
 * DESCRIPTION
 *  check bgsr is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 mmi_mms_bgsr_is_ready(void)
{
    return (mms_is_ready() && !isInCall() && mmi_mms_bgsr_is_sync() && !mmi_bootup_get_active_flight_mode()
#ifdef  __USB_IN_NORMAL_MODE__
        && !(mmi_usb_is_in_mass_storage_mode() && mmi_mms_bgsr_mms_is_exported())
#endif  /*__USB_IN_NORMAL_MODE__*/
            );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_is_sync
 * DESCRIPTION
 *  check bgsr is sync with MMA or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 mmi_mms_bgsr_is_sync(void)
{
    return mmi_mms_bgsr_sync_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_get_free_space
 * DESCRIPTION
 *  get the mms free space
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
U32 mmi_mms_bgsr_get_free_space(void)
{
    return mmi_mms_bgsr_free_space;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_bgsr_mms_is_exported
 * DESCRIPTION
 *  get the mms is exported
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
U8 mmi_mms_bgsr_mms_is_exported(void)
{
    return mmi_mms_bgsr_mms_storage_exported;
}

#endif /*__MMI_MMS_BGSR_SUPPORT__*/
