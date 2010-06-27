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
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "wap_ps_struct.h"

/* MSF */
#include "msf_def.h"
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_mem.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mltypes.h"
    
/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"
    
/* MMA */
#include "mmsadp.h"
#include "mma_def.h"
#include "mma_cfg.h"
#include "mma_env.h"
#include "mma_rpl.h"
#include "mma_if_wrapper.h"

static mma_send_request_entry_struct send_queue[MMA_CFG_SENDING_QUEUE_SIZE];
static kal_uint32 send_num;
static kal_uint32 send_id = 0;
static mma_timer_struct resend_timer;

/*****************************************************************************
 * FUNCTION
 *  send_enqueue
 * DESCRIPTION
 *  Add request to the send queue
 * PARAMETERS
 *  ilm_sender    [IN]        
 *  ilm_msg       [IN]        
 *  app_id        [IN]        
 *  req_id        [IN]        
 *  msg_id        [IN]
 *  is_read_report[IN]
 *  send_and_save [IN]
 *  folder        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void send_enqueue(kal_uint32 id, kal_uint32 ilm_sender, kal_uint32 mms_sender, kal_uint8 app_id, 
    kal_uint32 req_id, kal_uint32 msg_id, kal_bool send_and_save, kal_bool is_read_report, mma_folder_enum folder)
{
    int i;

    ASSERT(id > 0);
    ASSERT(send_num < MMA_CFG_SENDING_QUEUE_SIZE);  /* queue overflow check */

    for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if(send_queue[i].id == 0)
            break;
    }

    ASSERT(i < MMA_CFG_SENDING_QUEUE_SIZE);
    send_queue[i].id = id;
    send_queue[i].ilm_sender = ilm_sender;
    send_queue[i].mms_sender = mms_sender;
    send_queue[i].app_id = app_id;
    send_queue[i].req_id = req_id;
    send_queue[i].msg_id = msg_id;
    send_queue[i].send_and_save = send_and_save;
    send_queue[i].is_read_report = is_read_report;
    send_queue[i].folder = folder;
    send_queue[i].state = MMA_SEND_START;
    send_queue[i].percent = 0;
    send_queue[i].retry = 0;
    send_queue[i].retry_countdown = 0;
    send_num++;
}

/*****************************************************************************
 * FUNCTION
 *  send_dequeue
 * DESCRIPTION
 *  remove request from the send queue
 * PARAMETERS
 *  ilm_sender    [IN]        
 *  ilm_msg       [IN]        
 *  req_id        [IN]        
 *  entry_info    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void send_dequeue(kal_uint32 id)
{
    int i;

    ASSERT(id > 0 && send_num > 0);  /* queue underflow check */
    if (id > 0)
    {
        for (i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
        {
            if (send_queue[i].id == id)
                break;
        }

        if(i < MMA_CFG_SENDING_QUEUE_SIZE)
        {
            memset(&send_queue[i], 0x00, sizeof(mma_send_request_entry_struct));
            send_num--;
        }
        else
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_SEND_FCC0EB6804E2919D2884B8D0C0F9A966, "(%s) (%d) send_dequeue(%d)\n", __FILE__, __LINE__, id));
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  is_send_queue_full
 * DESCRIPTION
 *  Check if the send queue is full
 * PARAMETERS
 * RETURNS
 *  KAL_TRUE, full; otherwise, not full
 *****************************************************************************/
static kal_bool is_send_queue_full()
{
    return (send_num >= MMA_CFG_SENDING_QUEUE_SIZE);
}

/*****************************************************************************
 * FUNCTION
 *  get_send_id
 * DESCRIPTION
 *  Get non-zero send id for issuing a request. 
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 get_send_id()
{
    if(send_id + 1 == 0)
    {
        ++send_id;
    }
    return ++send_id;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_send entry_by_send_id
 * DESCRIPTION
 *  get request entry from the queue by request ID
 * PARAMETERS
 *  req_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_send_request_entry_struct *mma_get_send_entry_by_send_id(kal_uint32 id)
{
    int i;

    for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if(send_queue[i].id == id)
            break;
    }

    ASSERT(i < MMA_CFG_SENDING_QUEUE_SIZE);  /* cannot find the request */
    return &send_queue[i];
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_send_entry_by_msg_id
 * DESCRIPTION
 *  get request entry from the queue by message ID
 * PARAMETERS
 *  req_id        [IN]        
 * RETURNS
 *  Entry address. NULL if not found
 *****************************************************************************/
mma_send_request_entry_struct *mma_get_send_entry_by_msg_id(kal_uint32 msg_id)
{
    int i;

    if(msg_id > 0)
    {
        for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
        {
            if(send_queue[i].msg_id == msg_id)
            {
                return &send_queue[i];
            }
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_compare_id
 * DESCRIPTION
 *  Get earlier send id 
 * PARAMETERS
 *  id1      [IN]
 *  id2      [IN]
 * RETURNS
 *  Earlier request id
 *****************************************************************************/
kal_uint32 mma_send_compare_id(kal_uint32 id1, kal_uint32 id2)
{
    if(id1 == id2) return id1;
    
    if((send_id > id1 && send_id > id2) || (send_id < id1 && send_id < id2))
    {
        return (id1 < id2)? id1 : id2;
    }
    else if(send_id < id1 && send_id > id2)  /* wrap around */
    {
        return id1;
    }
    else  /* wrap around : req_id > id1 && req_id < id2 */
    {
        return id2;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_get_sending_entry
 * DESCRIPTION
 *  Get entry in sending
 * PARAMETERS
 * RETURNS
 *  Entry address. NULL if not found
 *****************************************************************************/
mma_send_request_entry_struct *mma_send_get_sending_entry()
{
    int i;
    mma_send_request_entry_struct *entry = NULL;

    for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if(send_queue[i].state == MMA_SEND_SENDING)
        {
            if(entry == NULL)
            {
                entry = &send_queue[i];
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    return entry;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_get_pending_entry
 * DESCRIPTION
 *  Get 1st pending entry for the next sending
 * PARAMETERS
 * RETURNS
 *  Entry address. NULL if not found
 *****************************************************************************/
mma_send_request_entry_struct *mma_send_get_pending_entry()
{
    int i;
    mma_send_request_entry_struct *entry = NULL;

    for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if(send_queue[i].state == MMA_SEND_PENDING && send_queue[i].retry_countdown == 0)
        {
            if(entry == NULL)
            {
                entry = &send_queue[i];
            }
            else
            {
                kal_uint32 id = mma_send_compare_id(entry->id, send_queue[i].id);
                entry = &send_queue[id];
            }
        }
    }

    return entry;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_get_countdown_entry_no
 * DESCRIPTION
 *  Get the number of countdown entries
 * PARAMETERS
 * RETURNS
 *  Number
 *****************************************************************************/
kal_uint32 mma_send_get_countdown_entry_no(void)
{
    kal_uint32 i, count = 0;

    for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if(send_queue[i].state == MMA_SEND_PENDING && send_queue[i].retry_countdown > 0)
        {
            count++;
        }
    }
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_is_msg_sending
 * DESCRIPTION
 *  Check if the specified message is being sent
 * PARAMETERS
 * RETURNS
 *  KAL_TRUE: sending; KAL_FALSE: not sending
 *****************************************************************************/
kal_bool mma_send_is_msg_sending(kal_uint32 msg_id)
{
    kal_uint32 i;
    for (i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if (send_queue[i].msg_id == msg_id && send_queue[i].state == MMA_SEND_SENDING)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_is_msg_pending
 * DESCRIPTION
 *  Check if the specified message is pending
 * PARAMETERS
 * RETURNS
 *  KAL_TRUE: sending; KAL_FALSE: not sending
 *****************************************************************************/
kal_bool mma_send_is_msg_pending(kal_uint32 msg_id)
{
    kal_uint32 i;
    for (i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if (send_queue[i].msg_id == msg_id && send_queue[i].state == MMA_SEND_PENDING)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_start_resend_timer
 * DESCRIPTION
 *  Get 1st pending entry for the next sending
 * PARAMETERS
 * RETURNS
 *  Entry address. NULL if not found
 *****************************************************************************/
void mma_send_start_resend_timer(void)
{
    if(resend_timer.is_active == KAL_FALSE)
    {
        resend_timer.timer_id = MMA_SEND_TIMER_ID;
        MSF_TIMER_SET (MSF_MODID_MMA, resend_timer.timer_id, MMA_1_SEC_IN_DSEC);
        resend_timer.is_active = KAL_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_update_countdown
 * DESCRIPTION
 *  Update retry countdown value by decreasing 1 for pending entries
 * PARAMETERS
 * RETURNS
 *  Entry address. NULL if not found
 *****************************************************************************/
void mma_send_update_countdown(void)
{
    int i;

    for(i = 0; i < MMA_CFG_SENDING_QUEUE_SIZE; i++)
    {
        if(send_queue[i].state == MMA_SEND_PENDING && send_queue[i].retry_countdown > 0)
        {
            send_queue[i].retry_countdown--;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_send_init(void)
{
    send_num = 0;
    memset(send_queue, 0x00, sizeof(mma_send_request_entry_struct) * MMA_CFG_SENDING_QUEUE_SIZE);
    resend_timer.is_active = KAL_FALSE;
    resend_timer.timer_id = 0;
    MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "mma_send_init()\n"));
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_mms_fsm
 * DESCRIPTION
 *  Send mms by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_send_mms_fsm(mma_send_request_entry_struct *entry)
{
    int ret = MMA_RESULT_OK;

    ASSERT(entry != NULL);
    switch(entry->state)
    {
    case MMA_SEND_START:
    case MMA_SEND_PENDING:
        if (mma_send_get_sending_entry() != NULL)
        {
            entry->state = MMA_SEND_PENDING;
            ret = MMA_RESULT_DELAYED;
        }
        else if(entry->retry_countdown > 0)
        {
            entry->state = MMA_SEND_PENDING;
            ret = MMA_RESULT_DELAYED;
        }
        else
        {
            entry->state = MMA_SEND_SENDING;
            ret = MMA_RESULT_CONTINUE;
        }
        break;

    case MMA_SEND_SENDING:
        if (entry->is_read_report)
        {
            MMSif_sendReadReport(MSF_MODID_MMA, entry->msg_id, MMS_READ_STATUS_READ);
        }
        else
        {
            MMA_sendMessage(MSF_MODID_MMA, entry->msg_id);
        }
        ret = MMA_RESULT_DELAYED;
        break;

    case MMA_SEND_FINISHED:
        ret = MMA_RESULT_OK;
    }
    
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SEND_6BCD8E5AB1722DFABEA57D54C84B6671, "(%s) (%d) mma_send_mms_fsm(): state %d, ret %d\n", 
            __FILE__, __LINE__, entry->state, ret));
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mma_send_mms
 * DESCRIPTION
 *  Send mms by specified information
 * PARAMETERS
 *  entry    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_send_mms(mma_send_request_entry_struct *entry)
{
    mma_result_enum ret = MMA_RESULT_OK;

    ASSERT(entry != NULL);

    /* Check if the sending can be arranged */
    if (entry->state == MMA_SEND_START)
    {
        if (is_send_queue_full())
        {
            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "send queue full(sender %d, msg %d)\n", entry->ilm_sender, entry->msg_id));
            if (entry->ilm_sender)
            {
                wap_send_wap_mma_send_rsp(entry->app_id, entry->req_id, MMA_RESULT_FAIL_QUEUE_FULL, entry->msg_id, 0, 
                    NULL, entry->folder, entry->send_and_save);
            }
            else
            {
                MmsResultSig data;
                
                data.result = MMS_RESULT_BUSY;
                data.responseStatus = 0;
                data.responseText="";
                if ( !mmsSendSignalExt( MSF_MODID_MMS, entry->mms_sender, MMS_SIG_SEND_MSG_REPLY, &data, 
                    (MmsIfConvertFunction *)mms_cvt_MmsResult))
                {
                    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_SEND_0C607E82F7E732A5E2D43AB78E761104, "%s(%d): signal send failed.\n", __FILE__, __LINE__));
                } 
            }
            return;
        }
        else if (mma_get_send_entry_by_msg_id(entry->msg_id) != NULL)  /* msg already in sending queue */
        {
            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "msg already in sending(sender %d, msg %d)\n", entry->ilm_sender, entry->msg_id));
            if (entry->ilm_sender)
            {
                wap_send_wap_mma_send_rsp(entry->app_id, entry->req_id, MMA_RESULT_FAIL_FILE_IN_USE, entry->msg_id, 0,
                    NULL, entry->folder, entry->send_and_save);
            }
            return;
        }
        else
        {
            kal_uint32 id = get_send_id();
            send_enqueue(id, entry->ilm_sender, entry->mms_sender, entry->app_id, entry->req_id, entry->msg_id, 
                entry->send_and_save, entry->is_read_report, entry->folder);
            entry = mma_get_send_entry_by_send_id(id);
            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "msg enter send fsm(msg %d)\n", entry->msg_id));
        }
    }

    /* Start sending FSM */
    while((ret = mma_send_mms_fsm(entry)) == MMA_RESULT_CONTINUE);
    switch(ret)
    {
        case MMA_RESULT_DELAYED:
            break;
        case MMA_RESULT_OK:
        default:
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SEND_0303627DDDB6A43FC5B559806762470C, "(%s) (%d) mma_send_mms(%d): msg %d, ret %d\n", 
                __FILE__, __LINE__, entry->req_id, entry->msg_id, ret));
            if (ret == MMA_RESULT_OK)
            {
                mma_reply_send_message_response(entry->mms_sender, MMS_RESULT_OK, 0, NULL, entry->msg_id);
            }
            else
            {
                mma_reply_send_message_response(entry->mms_sender, MMS_RESULT_ERROR, 0, NULL, entry->msg_id);
            }
            break;
        }
    }
}

