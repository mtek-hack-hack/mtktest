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
 * QueueGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for message queue handle.
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
#ifndef _QUEUE_GPROT_H
#define _QUEUE_GPROT_H

/*****************************************************************************
* Include                                                                     
*****************************************************************************/
// #include "MMIDataType.h"
#include "OslMemory.h"

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include "lcd_ip_cqueue.h"
#include "stack_types.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "stack_init.h"
#include "stack_ltlcom.h"
#include "app_buff_alloc.h"
#include "DebugInitDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#define MYQUEUE         ilm_struct
#define oslMsgqid       kal_msgqid
#define oslModuleType   module_type
#define oslMsgType      msg_type
#define oslParaType     local_para_struct
#define oslSrcId        src_mod_id
#define oslDestId       dest_mod_id
#define oslMsgId        msg_id
#define oslSapId        sap_id
#define oslDataPtr      local_para_ptr
#define oslPeerBuffPtr  peer_buff_ptr
#define OSLWAITMODE     kal_wait_mode
#define OSL_NO_WAIT     KAL_NO_WAIT
#define OSL_INFINITE_WAIT   KAL_INFINITE_WAIT

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
/* DO NOT use these functions in AP, these are interface functions */

extern void OslIntMsgSendExtQueue(MYQUEUE *Message);
extern void *OslIntConstructDataPtr(U32 size);
extern void OslIntFreeDataPtr(void *ptr);
extern void OslIntFreeInterTaskMsg(void *Message);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* external queue */

/*****************************************************************************
 * FUNCTION
 *  OslMsgSendExtQueue
 * DESCRIPTION
 *  Send message to external queue
 * PARAMETERS
 *  Message     [IN]        pointer to message structure (type: MYQUEUE *)
 * RETURNS
 *  void
 *****************************************************************************/
#define OslMsgSendExtQueue(Message) \
            OslIntMsgSendExtQueue(Message)

/* function pointer for use as callback function */
#define OslMsgSendExtQueueFptr  OslIntMsgSendExtQueue


/*****************************************************************************
 * FUNCTION
 *  OslConstructDataPtr
 * DESCRIPTION
 *  Construct data buffer (local parameter buffer)
 * PARAMETERS
 *  size        [IN]        desired buffer size (type: U32)
 * RETURNS
 *  void *
 *****************************************************************************/
#define OslConstructDataPtr(size)   \
            OslIntConstructDataPtr(size)
            

/*****************************************************************************
 * FUNCTION
 *  OslHoldDataPtr
 * DESCRIPTION
 *  Hold data buffer (local parameter buffer)
 * PARAMETERS
 *  ptr        [IN]        pointer to data buffer
 * RETURNS
 *  none
 *****************************************************************************/
#define OslHoldDataPtr(ptr)                                         \
    do {                                                            \
        MMI_ASSERT(((local_para_struct*)(ptr))->ref_count != 0);    \
        hold_local_para((local_para_struct*)(ptr));                 \
    } while(0)


/*****************************************************************************
 * FUNCTION
 *  OslFreeDataPtr
 * DESCRIPTION
 *  Free data buffer (local parameter buffer)
 * PARAMETERS
 *  ptr     [IN]    pointer to data buffer (type: void *)
 * RETURNS
 *  void
 *****************************************************************************/
#define OslFreeDataPtr(ptr) \
            OslIntFreeDataPtr(ptr)
            

/*****************************************************************************
 * FUNCTION
 *  OslFreeInterTaskMsg
 * DESCRIPTION
 *  Free itner-task msg
 * PARAMETERS
 *  Message     [IN]    pointer to message structure (type: void *)
 * RETURNS
 *  void
 *****************************************************************************/
#define OslFreeInterTaskMsg(Message)    \
            OslIntFreeInterTaskMsg(Message)


/*****************************************************************************
 * FUNCTION
 *  OslReceiveMsgExtQ
 * DESCRIPTION
 *  Receive message from external queue
 * PARAMETERS
 *  msgqid      [IN]    message queue id to read (type: oslMsgqid)
 *  Message     [OUT]   pointer to message structure (type: MYQUEUE *)
 * RETURNS
 *  success (0) or not (non zero)
 *****************************************************************************/
#define OslReceiveMsgExtQ(msgqid, Message)  \
            receive_msg_ext_q(msgqid, Message)


/*****************************************************************************
 * FUNCTION
 *  OslGetMyTaskIndex
 * DESCRIPTION
 *  get task index
 * PARAMETERS
 *  index     [OUT]     pointer to task index data buffer (type: U32 *)
 * RETURNS
 *  void
 *****************************************************************************/
#define OslGetMyTaskIndex(index)    \
            kal_get_my_task_index(index)


/*****************************************************************************
 * FUNCTION
 *  OslStackSetActiveModuleID
 * DESCRIPTION
 *  set active module id
 * PARAMETERS
 *  task_index      [IN]    task index to set (type: U32)
 *  module_id       [IN]    active module id (type: oslModuleType)
 * RETURNS
 *  void
 *****************************************************************************/
#define OslStackSetActiveModuleID(task_index, module_id)    \
            stack_set_active_module_id(task_index, module_id)


/*****************************************************************************
 * FUNCTION
 *  OslCreateMsgQ
 * DESCRIPTION
 *  Creates Message Queue
 * PARAMETERS
 *  queue_name          [IN]     queue name (type: PS8)   
 *  max_msg_size        [IN]     max. message size (type: U32)   
 *  max_msgs            [IN]     max. number of messages (type: U32)   
 * RETURNS
 *  message queue id (type: oslMsgqid)
 *****************************************************************************/
#define OslCreateMsgQ(queue_name, max_msg_size, max_msgs)   \
            kal_create_msg_q(queue_name, max_msg_size, max_msgs)


/*****************************************************************************
 * FUNCTION
 *  OslDeleteMsgQ
 * DESCRIPTION
 *  Deletes Message Queue
 * PARAMETERS
 *  msgqid      [IN]      message queue id (type: oslMsgqid)  
 * RETURNS
 *  void
 *****************************************************************************/
#define OslDeleteMsgQ(msgqid)   \
            kal_delete_msg_q(msgqid)


/*****************************************************************************
 * FUNCTION
 *  OslWriteMsgQ
 * DESCRIPTION
 *  Writes to Message Queue
 * PARAMETERS
 *  msgqid          [IN]        message queue id (type: oslMsgqid)
 *  msgPtr          [IN]        pointer to message (type: void *)  
 *  msgSize         [IN]        message size (type: U32)
 *  wait_mode       [IN]        OSL_NO_WAIT or OSL_INFINITE_WAIT (type: OSLWAITMODE)
 *  message_to_head [IN]        write to queue head or not (type: MMI_BOOL)
 * RETURNS
 *  status (type: OSLSTATUS)
 *****************************************************************************/
#define OslWriteMsgQ(msgqid, msgPtr, msgSize, wait_mode, message_to_head)   \
            kal_enque_msg(msgqid, msgPtr, msgSize, wait_mode, message_to_head)


/*****************************************************************************
 * FUNCTION
 *  OslReadMsgQ
 * DESCRIPTION
 *  Reades from Message Queue
 * PARAMETERS
 *  msgqid          [IN]        message queue id (type: oslMsgqid)  
 *  msgPtr          [OUT]       pointer to message (type: void *) 
 *  msgSize         [OUT]       pointer to message size (type: U16 *)  
 *  wait_mode       [IN]        OSL_NO_WAIT or OSL_INFINITE_WAIT (type: OSLWAITMODE)
 * RETURNS
 *  status (type: OSLSTATUS)
 *****************************************************************************/
#define OslReadMsgQ(msgqid, msgPtr, msgSize, wait_mode)     \
            kal_deque_msg(msgqid, msgPtr, msgSize, wait_mode)


/* internal (circular) queue */

/*****************************************************************************
 * FUNCTION
 *  OslReadCircularQ
 * DESCRIPTION
 *  Reads from Circ Queue
 *  Not used now
 * PARAMETERS
 *  msgPtr      [OUT]       pointer to message   
 * RETURNS
 *  success (1) or not (0)
 *****************************************************************************/
extern U8 OslReadCircularQ(void *msgPtr);


/*****************************************************************************
 * FUNCTION
 *  OslLookUpLastCircularQMsg
 * DESCRIPTION
 *  Look up the last message in Circular Queue
 * PARAMETERS
 *  msgPtr      [IN]        pointer to message     
 * RETURNS
 *  success (1) or not (0)
 *****************************************************************************/
extern U8 OslLookUpLastCircularQMsg(void *msgPtr);


/*****************************************************************************
 * FUNCTION
 *  OslWriteCircularQ
 * DESCRIPTION
 *  Writes to Circ Queue
 * PARAMETERS
 *  msgPtr      [IN]        pointer to message     
 * RETURNS
 *  success (1) or not (0)
 *****************************************************************************/
extern U8 OslWriteCircularQ(void *msgPtr);


/*****************************************************************************
 * FUNCTION
 *  OslNumOfCircularQMsgs
 * DESCRIPTION
 *  Get the message number
 * PARAMETERS
 *  void
 * RETURNS
 *  no. of messages in circular queue
 *****************************************************************************/
extern U8 OslNumOfCircularQMsgs(void);


/*****************************************************************************
 * FUNCTION
 *  OslIsCircularQFull
 * DESCRIPTION
 *  Check if Circular Queue is full
 * PARAMETERS
 *  void
 * RETURNS
 *  full (TRUE) or empty (FALSE)
 *****************************************************************************/
extern U8 OslIsCircularQFull(void);


#endif /* _QUEUE_GPROT_H */ 

