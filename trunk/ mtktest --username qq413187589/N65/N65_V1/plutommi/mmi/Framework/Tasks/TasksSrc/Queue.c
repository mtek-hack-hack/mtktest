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
 *  Queue.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : Queue.c

   PURPOSE     : Task queue implementation functions 

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma

   DATE     : Dec' 28, 2002

**************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/
#include "MMI_features.h"
#include "stdc.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "FrameworkGprot.h"         
#include "FrameworkProt.h"   
#include "DebugInitDef.h"

/*****************************************************************************
* Define                                                                      
*****************************************************************************/
#ifndef __MTK_TARGET__
#define __align(x)
#endif 


/* 
 * Because MMI task will receive extQ message into circular queue,
 * we increase the circular queue size from 30 to 50
 */

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/

__align(4)
     U8 circq_array[CIRCQ_NODE_SIZE * CIRCQ_NO_OF_NODES];
     U8 circq_read = 0, circq_write = 0, circq_messages = 0, max_circq_messages = 0;


/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  OslIntMsgSendExtQueue
 * DESCRIPTION
 *  Writes to Task External Queue
 * PARAMETERS
 *  Message     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void OslIntMsgSendExtQueue(MYQUEUE *Message)
{
    extern void CheckAndPrintMsgId(U16 Id);

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE *oslMessage;
    U8 ref_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* check ref_count of local para */
    if (Message->local_para_ptr != NULL)
    {
        ref_count = Message->local_para_ptr->ref_count;              
        EXT_ASSERT(ref_count != 0, (int)Message->src_mod_id, 
                    (int)Message->dest_mod_id, (int)Message->msg_id);

    }
        
    oslMessage = allocate_ilm(Message->oslSrcId);
    memcpy(oslMessage, Message, sizeof(MYQUEUE));
    if (oslMessage->oslSrcId == MOD_MMI &&
        oslMessage->oslDestId == MOD_L4C)
    {
        oslMessage->sap_id = MMI_L4C_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_MMI)
    {
        oslMessage->sap_id = MMI_MMI_SAP;
    }
#ifdef __MMI_FILE_MANAGER__    
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_FMT)
    {
        oslMessage->sap_id = MMI_FMT_SAP;
    }
#endif
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_ABM)
    {
        oslMessage->sap_id = MMI_ABM_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_J2ME)
    {
        oslMessage->sap_id = MMI_J2ME_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_JASYN)
    {
        oslMessage->sap_id = MMI_JASYN_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_SYNCML)
    {
        oslMessage->sap_id = MMI_SYNCML_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_POC)
    {
        oslMessage->sap_id = MMI_POC_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_MMI &&
             oslMessage->oslDestId == MOD_WAP)
    {
        oslMessage->sap_id = MMI_WAP_SAP;
    }
    else if (oslMessage->oslSrcId == MOD_WAP &&
             oslMessage->oslDestId == MOD_MMI)
    {
        oslMessage->sap_id = WAP_MMI_SAP;
    }
    else
    {
        oslMessage->sap_id = INVALID_SAP;
    }
    msg_send_ext_queue(oslMessage);
    CheckAndPrintMsgId((U16) (Message->msg_id));
}


/*****************************************************************************
 * FUNCTION
 *  OslIntConstructDataPtr
 * DESCRIPTION
 *  Constructs Data Ptr
 *  
 *  Not used now
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *OslIntConstructDataPtr(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (construct_local_para((kal_uint16) size, TD_CTRL | TD_RESET));
}


/*****************************************************************************
 * FUNCTION
 *  OslIntFreeDataPtr
 * DESCRIPTION
 *  Frees Data Ptr
 *  
 *  Not used now
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void OslIntFreeDataPtr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_local_para(ptr);
}


/*****************************************************************************
 * FUNCTION
 *  OslIntFreeInterTaskMsg
 * DESCRIPTION
 *  Frees InterTask Mesg
 *  
 *  Not used now
 * PARAMETERS
 *  Message     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void OslIntFreeInterTaskMsg(void *Message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ilm(Message);
}

/*****************************************************************************
 * FUNCTION
 *  OslReadCircularQ
 * DESCRIPTION
 *  Reads from Circ Queue
 *  
 *  Not used now
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslReadCircularQ(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "OslReadCircularQ: <#[%d], read:[%d], write:[%d]>", circq_messages,
                         circq_read, circq_write);
    if (circq_messages == 0)
    {
        return 0;
    }
    memcpy(msgPtr, circq_array + (circq_read * CIRCQ_NODE_SIZE), CIRCQ_NODE_SIZE);
    if (++circq_read == CIRCQ_NO_OF_NODES)
    {
        circq_read = 0;
    }
    --circq_messages;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  OslLookUpLastCircularQMsg
 * DESCRIPTION
 *  Look up the last message in Circ Queue
 *  
 *  Not used now
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslLookUpLastCircularQMsg(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 last_read_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (circq_messages > 0)
    {
        if (circq_write == 0)
        {
            last_read_index = CIRCQ_NO_OF_NODES;
        }
        else
        {
            last_read_index = circq_write - 1;
        }
        memcpy(msgPtr, circq_array + (last_read_index * CIRCQ_NODE_SIZE), CIRCQ_NODE_SIZE);
        return 1;
    }
    else
    {
        memset(msgPtr, 0, CIRCQ_NODE_SIZE);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  OslWriteCircularQ
 * DESCRIPTION
 *  Writes to Circ Queue
 *  
 *  Not used now
 * PARAMETERS
 *  msgPtr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslWriteCircularQ(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "OslWriteCircularQ: <#[%d], read:[%d], write:[%d]>", circq_messages,
                         circq_read, circq_write);
    if (circq_messages == CIRCQ_NO_OF_NODES)
    {
        MMI_ASSERT(0);
        return 0;
    }
    memcpy(circq_array + (circq_write * CIRCQ_NODE_SIZE), msgPtr, CIRCQ_NODE_SIZE);
    if (++circq_write == CIRCQ_NO_OF_NODES)
    {
        circq_write = 0;
    }
    ++circq_messages;
    if (max_circq_messages < circq_messages)
    {
        max_circq_messages = circq_messages;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  OslNumOfCircularQMsgs
 * DESCRIPTION
 *  Get the message number
 *  
 *  Not used now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslNumOfCircularQMsgs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return circq_messages;
}


/*****************************************************************************
 * FUNCTION
 *  OslIsCircularQFull
 * DESCRIPTION
 *  Check if Circ Queue is full
 *  
 *  Not used now
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 OslIsCircularQFull(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (circq_messages == CIRCQ_NO_OF_NODES);
}

