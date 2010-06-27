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

/* MSF */
#include "msf_def.h"
#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_log.h"
#include "msf_dcvt.h"

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
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_send.h"
#include "mma_rpl.h"
#include "mma_if_wrapper.h"

static mma_wrapper_entry_struct w_queue[MMA_WRAPPER_END][MMA_IF_REQUEST_QUEUE_SIZE];
static kal_uint8 w_queue_active_idx[MMA_WRAPPER_END];

/*****************************************************************************
 * FUNCTION
 *  mma_if_wrapper_init
 * DESCRIPTION
 *  Initialize the MMS exported function adaptor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_if_wrapper_init (void)
{
    memset(w_queue, 0x00, sizeof(mma_wrapper_entry_struct) * MMA_WRAPPER_END * MMA_IF_REQUEST_QUEUE_SIZE);
    memset(w_queue_active_idx, 0x00, MMA_WRAPPER_END * sizeof(kal_uint8));
    MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "mma_if_wrapper_init()\n"));
}

/*****************************************************************************
 * FUNCTION
 *  w_enqueue
 * DESCRIPTION
 *  Add request to the queue
 * PARAMETERS
 *  sender        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void w_enqueue(kal_uint8 sender, mma_wrapper_type_enum type, void *info)
{
    kal_uint8 i = 0, idx = 0;
    ASSERT(sender < MSF_NUMBER_OF_MODULES);
    
    for (; i < MMA_IF_REQUEST_QUEUE_SIZE; i++)
    {
        idx = (w_queue_active_idx[type] + i) % MMA_IF_REQUEST_QUEUE_SIZE;
        if (w_queue[type][idx].type == MMA_WRAPPER_NONE)
        {
            break;
        }
    }
    ASSERT(w_queue[type][idx].type == MMA_WRAPPER_NONE);  /* queue full */
    w_queue[type][idx].type = type;
    w_queue[type][idx].sender = sender;
    w_queue[type][idx].entry_info = info;
}

/*****************************************************************************
 * FUNCTION
 *  w_dequeue
 * DESCRIPTION
 *  Remove the (active) request from head of the queue by its type
 * PARAMETERS
 *  type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void w_dequeue(mma_wrapper_type_enum type)
{
    kal_uint8 idx = w_queue_active_idx[type];
    
    if (w_queue[type][idx].type != MMA_WRAPPER_NONE)
    {
        w_queue[type][idx].sender = 0;
        w_queue[type][idx].type = MMA_WRAPPER_NONE;
        MMA_FREE(w_queue[type][idx].entry_info);
        w_queue[type][idx].entry_info = NULL;
        w_queue_active_idx[type] = (w_queue_active_idx[type] + 1) % MMA_IF_REQUEST_QUEUE_SIZE;  /* next request */
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_IF_WRAPPER_7E28A4631FFABB42C6B98FB1F4A476D9, "(%s) (%d) w_dequeue(): queue is empty\n", __FILE__, __LINE__));
    }
}

/*****************************************************************************
 * FUNCTION
 *  is_w_queue_empty
 * DESCRIPTION
 *  Check if the request queue is empty by its response signal
 * PARAMETERS
 *  reply_sig     [IN]        Response signal of this request
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool is_w_queue_empty(mma_wrapper_type_enum type)
{
    kal_uint8 idx = w_queue_active_idx[type];
    
    return (w_queue[type][idx].type == MMA_WRAPPER_NONE);
}

/*****************************************************************************
 * FUNCTION
 *  mma_wrapper_get_active_entry
 * DESCRIPTION
 *  this function returns the receiver for the active entry by the specified signal
 * PARAMETERS
 * RETURNS
 *  Entry address; null if queue empty
 *****************************************************************************/
mma_wrapper_entry_struct *mma_wrapper_get_active_entry(mma_wrapper_type_enum type)
{
    if(is_w_queue_empty(type))
    {
        return NULL;
    }
    else
    {
        kal_uint8 idx = w_queue_active_idx[type];
        
        return &w_queue[type][idx];
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_wrapper_schedule
 * DESCRIPTION
 *  Proceed to the next request
 * PARAMETERS
 * RETURNS
 *  
 *****************************************************************************/
void mma_wrapper_schedule(mma_wrapper_type_enum type)
{
    w_dequeue(type);  /* removed finished job */

    if(is_w_queue_empty(type) != KAL_TRUE)  /* proceed to next job */
    {
        kal_uint8 idx = w_queue_active_idx[type];
        switch(type)
        {
        case MMA_WRAPPER_CREATE:
        {
            MmsFileType f_type = *(MmsFileType *)(w_queue[type][idx].entry_info);
            MMSif_createMessage(MSF_MODID_MMA, f_type);
            break;
        }
        
        case MMA_WRAPPER_CREATE_DONE:
        {
            mma_wrapper_create_done_struct *info = w_queue[type][idx].entry_info;
            MMSif_createMessageDone(MSF_MODID_MMA, info->msg_id, info->folder);
            break;
        }
        
        case MMA_WRAPPER_GET_FOLDER:
        {
            mma_wrapper_get_folder_struct *info = w_queue[type][idx].entry_info;
            MMSif_getFolderContent(MSF_MODID_MMA, info->folder, info->from, info->to);
            break;
        }
        
        case MMA_WRAPPER_MOVE:
        {
            mma_wrapper_move_struct *info = w_queue[type][idx].entry_info;
            MMSif_moveMessage(MSF_MODID_MMA, info->msg_id, info->folder);
            break;
        }
        
        case MMA_WRAPPER_SEND:
        {
            MmsMsgId msg_id = *(MmsMsgId *)(w_queue[type][idx].entry_info);
            MMSif_sendMessage(MSF_MODID_MMA, msg_id);
            break;
        }

        default:
            ASSERT(0);
        }
        
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_IF_WRAPPER_09F7E2631A417C2AA7FA1DE029B4BC8F, "(%s) (%d) mma_wrapper_schedule(%d)\n", __FILE__, __LINE__, 
            w_queue[type][idx].type));
    }
}

/*****************************************************************************
 * FUNCTION
 *  MMA_createMessage
 * DESCRIPTION
 *  MMSif_createMessage() wrapper. Add sender management
 * PARAMETERS
 *  source: sender
 *  fileType
 * RETURNS
 *  
 *****************************************************************************/
void MMA_createMessage(MSF_UINT8 source, MmsFileType fileType)
{
    MmsFileType *info = NULL;
    kal_bool is_busy = (is_w_queue_empty(MMA_WRAPPER_CREATE) == FALSE);

    MMA_CALLOC(info, sizeof(MmsFileType));
    *info = fileType;
    w_enqueue(source, MMA_WRAPPER_CREATE, info);

    if (is_busy)
    {
/* ADD A LOG*/
    }
    else
    {
        MMSif_createMessage(MSF_MODID_MMA, fileType);
    }
}

/*****************************************************************************
 * FUNCTION
 *  MMA_createMessageDone
 * DESCRIPTION
 *  MMSif_createMessageDone() wrapper. Add sender management
 * PARAMETERS
 *  source: sender
 *  msgId
 *  folder
 * RETURNS
 *  
 *****************************************************************************/
void MMA_createMessageDone(MSF_UINT8 source, MmsMsgId msgId, MmsFolderType folder)
{
    mma_wrapper_create_done_struct *info = NULL;
    kal_bool is_busy = (is_w_queue_empty(MMA_WRAPPER_CREATE_DONE) == FALSE);

    MMA_CALLOC(info, sizeof(mma_wrapper_create_done_struct));
    info->msg_id = msgId;
    info->folder = folder;
    w_enqueue(source, MMA_WRAPPER_CREATE_DONE, info);

    if (is_busy)
    {
/* ADD A LOG*/
    }
    else
    {
        MMSif_createMessageDone(MSF_MODID_MMA, msgId, folder);
    }
}

/*****************************************************************************
 * FUNCTION
 *  MMA_getFolderContent
 * DESCRIPTION
 *  MMSif_getFolderContent() wrapper. Add sender management
 * PARAMETERS
 *  source: sender
 *  folderId
 *  from
 *  to
 * RETURNS
 *  
 *****************************************************************************/
void MMA_getFolderContent(MSF_UINT8 source, MmsFolderType folder, int from, int to)
{
    mma_wrapper_get_folder_struct *info = NULL;
    kal_bool is_busy = (is_w_queue_empty(MMA_WRAPPER_GET_FOLDER) == FALSE);

    MMA_CALLOC(info, sizeof(mma_wrapper_get_folder_struct));
    info->folder = folder;
    info->from = from;
    info->to = to;
    w_enqueue(source, MMA_WRAPPER_GET_FOLDER, info);

    if (is_busy)
    {
/* ADD A LOG*/
    }
    else
    {
        MMSif_getFolderContent(MSF_MODID_MMA, folder, from, to);
    }
}

/*****************************************************************************
 * FUNCTION
 *  MMA_moveMessage
 * DESCRIPTION
 *  MMSif_moveMessage() wrapper. Add sender management
 * PARAMETERS
 *  source: sender
 *  msgId
 *  toFolder
 * RETURNS
 *  
 *****************************************************************************/
void MMA_moveMessage(MSF_UINT8 source, MmsMsgId msg_id, MmsFolderType folder)
{
    mma_wrapper_move_struct *info = NULL;
    kal_bool is_busy = (is_w_queue_empty(MMA_WRAPPER_MOVE) == FALSE);

    MMA_CALLOC(info, sizeof(mma_wrapper_move_struct));
    info->msg_id = msg_id;
    info->folder = folder;
    w_enqueue(source, MMA_WRAPPER_MOVE, info);

    if (is_busy)
    {
/* ADD A LOG*/
    }
    else
    {
        MMSif_moveMessage(MSF_MODID_MMA, msg_id, folder);
    }
}

/*****************************************************************************
 * FUNCTION
 *  MMA_sendMessage
 * DESCRIPTION
 *  MMSif_sendMessage() wrapper. Add queue management
 * PARAMETERS
 *  source: sender
 *  msgId
 * RETURNS
 *  
 *****************************************************************************/
void MMA_sendMessage(MSF_UINT8 source, MmsMsgId msgId)
{
    if(source != MSF_MODID_MMA)
    {
        mma_send_request_entry_struct *entry = NULL;
        MMA_CALLOC(entry, sizeof(mma_send_request_entry_struct));
        entry->ilm_sender = 0;
        entry->mms_sender = source;
        entry->req_id = 0;
        entry->msg_id = msgId;
        entry->send_and_save = FALSE;
        entry->folder = MMA_FOLDER_NONE;
        entry->state = MMA_SEND_START;
        mma_send_mms(entry);
        MMA_FREE(entry);
    }
    else
    {
        MmsMsgId *info = NULL;
        kal_bool is_busy = (is_w_queue_empty(MMA_WRAPPER_SEND) == FALSE);
    
        MMA_CALLOC(info, sizeof(MmsMsgId));
        *info = msgId;
        w_enqueue(source, MMA_WRAPPER_SEND, info);
    
        if (is_busy)
        {
            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "MMA_sendMessage is busy()\n"));
        }
        else
        {
            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, "MMSif_sendMessage(%d)\n", msgId));
            MMSif_sendMessage(MSF_MODID_MMA, msgId);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  MMA_sendCancel
 * DESCRIPTION
 *  MMSif_sendCancel() wrapper. 
 *  No queue management since send cancel should be handled immediately and source info is managed by sending.
 * PARAMETERS
 *  source: sender
 *  msgId
 * RETURNS
 *  
 *****************************************************************************/
void MMA_sendCancel(MSF_UINT8 source, MmsMsgId msgId)
{
    if(mma_send_is_msg_pending(msgId) == KAL_TRUE)
    {
        mma_send_request_entry_struct *send_entry = mma_get_send_entry_by_msg_id(msgId);
        if(source == MSF_MODID_MMA)
        {
            mma_reply_cancel_send_message_response(MSF_MODID_MMA, MMS_RESULT_OK, 0, NULL, msgId);
        }
        mma_reply_send_message_response(send_entry->mms_sender, MMS_RESULT_CANCELLED_BY_USER, 0, NULL, msgId);
    }
    else if(mma_send_is_msg_sending(msgId) == KAL_TRUE)
    {
        MMSif_sendCancel(MSF_MODID_MMA, msgId);
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_IF_WRAPPER_26C1648C202CACA2A42248B84C16B91C, "(%s) (%d) MMA_sendCancel(%d, %d) invalid\n", 
            __FILE__, __LINE__, source, msgId));
    }
    return;
}

