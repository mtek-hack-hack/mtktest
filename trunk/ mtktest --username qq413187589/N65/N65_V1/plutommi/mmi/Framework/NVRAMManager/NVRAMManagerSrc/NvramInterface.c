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
 * NVRAMINTERFACE.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for nvram read write data interface.
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
#include "MMI_features.h"
#include "StdC.h"

#include "l4dr.h"
#include "MMIDataType.h"
#include "MMI_trc.h"
#include "lcddr.h"

#include "TimerEvents.h"
#include "FrameworkGprot.h"
#include "FrameworkProt.h"
#include "DebugInitDef.h"

#include "ucs2prot.h"
#include "SimDetectionGexdcl.h" /* for g_pwr_context */
#include "SimDetectionGprot.h"
#define __ONLY_FOR_AUTO_RESGEN__
#include "PhoneSetup.h"
#undef __ONLY_FOR_AUTO_RESGEN__


static U8 in_nvram_procedure = 0;
static oslMsgqid nvramQID;
static U8 byte_data[NVRAM_CACHE_SIZE];
static U8 uint_data[NVRAM_CACHE_SIZE];
static U8 double_data[NVRAM_CACHE_SIZE];

static U8 byteDataReadFlag = 0;
static U8 uintDataReadFlag = 0;
static U8 doubleDataReadFlag = 0;

static U8 byteDataWriteFlashFlag = 0;
static U8 uintDataWriteFlashFlag = 0;
static U8 doubleDataWriteFlashFlag = 0;

#if defined(__NEW_NVRAMINTERFACE__)

/* only for internal read/write value */
#define WriteRecordInt(nFileId,nRecordId,pBuffer,nBufferSize,pError, fileName,lineNumber)\
   AccessRecordInt(nFileId,nRecordId,pBuffer,nBufferSize, 1, pError, MMI_TRUE, MMI_TRUE, fileName,lineNumber)

/* only for internal read/write value */
#define ReadRecordInt(nFileId,nRecordId,pBuffer,nBufferSize,pError,fileName,lineNumber)\
   AccessRecordInt(nFileId,nRecordId,pBuffer,nBufferSize, 1, pError, MMI_FALSE, MMI_TRUE, fileName,lineNumber)

#endif /* defined(__NEW_NVRAMINTERFACE__) */


/*****************************************************************************
 * FUNCTION
 *  SendNVRAMReadReq
 * DESCRIPTION
 *  Send Read NVRAM request to L4
 * PARAMETERS
 *  nFileId             [IN]        File LID
 *  nRecordId           [IN]        Record Index
 *  nRecordAmount       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void SendNVRAMReadReq(U16 nFileId, U16 nRecordId, U16 nRecordAmount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE Message;
    mmi_eq_nvram_read_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_NVRAM_READ_REQ;

    local_data = (mmi_eq_nvram_read_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_nvram_read_req_struct));

    /* since we truncate U16 to U8, make sure the value is in U8 range here */
    MMI_ASSERT(nFileId <= 0xFF);
    
    local_data->file_idx = (U8) nFileId;
    local_data->para = nRecordId;
    local_data->rec_amount = nRecordAmount;
    if (local_data->rec_amount == 0)
    {

        local_data->rec_amount = 1;

    }

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);


}


/*****************************************************************************
 * FUNCTION
 *  SendNVRAMWriteReq
 * DESCRIPTION
 *  Send Write NVRAM request to L4
 *  
 *  Size should be an even number
 * PARAMETERS
 *  nFileId         [IN]        File ID
 *  nRecordId       [IN]        Record Index
 *  pBuffer         [IN]        Data to be writen
 *  nBufferSize     [IN]        Size of data to be writen
 * RETURNS
 *  void
 *****************************************************************************/
static void SendNVRAMWriteReq(U16 nFileId, U16 nRecordId, void *pBuffer, U16 nBufferSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_nvram_write_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_NVRAM_WRITE_REQ;
    local_data = (mmi_eq_nvram_write_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_nvram_write_req_struct) + nBufferSize);

    /* since we truncate U16 to U8, make sure the value is in U8 range here */
    MMI_ASSERT(nFileId <= 0xFF);

    local_data->file_idx = (U8) nFileId;

    local_data->length = nBufferSize;

    memcpy(local_data->data, pBuffer, nBufferSize);

    local_data->para = nRecordId;

    Message.oslDataPtr = (oslParaType*) local_data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_HDLR);

}


#ifdef __NEW_NVRAMINTERFACE__
#define CIRCQ_NODE_SIZE sizeof(MYQUEUE)
#if defined(__MMI_DUAL_SIM_MASTER__)
#define CIRCQ_NO_OF_NODES 130
#else   /* __MMI_DUAL_SIM_MASTER__ */
#define CIRCQ_NO_OF_NODES 65
#endif  /* __MMI_DUAL_SIM_MASTER__ */

typedef enum
{
    circularQ_check_never_check,
    circularQ_check_not_found,
    circularQ_check_found
} circularQ_check_enum;

#ifdef __MMI_TEST_NEW_NVRAMINTERFACE__


/*****************************************************************************
 * FUNCTION
 *  NVRAMDummyTestRW
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void NVRAMDummyTestRW(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static pBOOL isRead = MMI_TRUE;
    static kal_uint8 settingBuffer[NVRAM_SETTING_SIZE] = {0};
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(AT_TEST_TIMER, 3000, NVRAMDummyTestRW);

    if (isRead)
    {
        ReadRecord(NVRAM_EF_SETTING_LID, 1, settingBuffer, NVRAM_SETTING_SIZE, &error);
        isRead = MMI_FALSE;
    }
    else
    {
        WriteRecord(NVRAM_EF_SETTING_LID, 1, settingBuffer, NVRAM_SETTING_SIZE, &error);
        isRead = MMI_TRUE;
    }

}
#endif /* __MMI_TEST_NEW_NVRAMINTERFACE__ */ 


/*****************************************************************************
 * FUNCTION
 *  NVRAMCheckCircularQ
 * DESCRIPTION
 *  check if there is nvram access response
 *  in the circular queue; if there is,
 *  retrieve it and put a dummy one in the
 *  same position
 * PARAMETERS
 *  msgPtr          [?]         
 *  nFileId         [IN]        The LID currently waiting
 *  memory(?)       [OUT]       For this.
 *  pBuffer(?)      [OUT]       Buffer in which data need to
 *  be(?)           [OUT]       Retrieved,caller will allocate
 * RETURNS
 *  circularQ_check_enum
 *****************************************************************************/
circularQ_check_enum NVRAMCheckCircularQ(void *msgPtr, U16 nFileId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    extern U8 circq_array[];
    MYQUEUE *tempQueueNode;

#ifdef __MMI_TEST_NEW_NVRAMINTERFACE__
    static pBOOL testFlag = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (testFlag)
    {
        NVRAMDummyTestRW();
        testFlag = MMI_FALSE;
    }
#endif /* __MMI_TEST_NEW_NVRAMINTERFACE__ */ 

    for (i = 0; i < CIRCQ_NO_OF_NODES; i++)
    {
        tempQueueNode = ((MYQUEUE*) (circq_array + i * CIRCQ_NODE_SIZE));

        switch (tempQueueNode->msg_id)
        {
            case MSG_ID_MMI_EQ_NVRAM_READ_RSP:
            case MSG_ID_MMI_EQ_NVRAM_WRITE_RSP:
            {
                ilm_struct ilm_ptr; /* DUMMY message */

                if (((mmi_eq_nvram_read_rsp_struct*) (tempQueueNode->local_para_ptr))->file_idx == nFileId
                    || ((mmi_eq_nvram_write_rsp_struct*) (tempQueueNode->local_para_ptr))->file_idx == nFileId)
                {
                    memcpy(msgPtr, circq_array + (i * CIRCQ_NODE_SIZE), CIRCQ_NODE_SIZE);

                    ilm_ptr.src_mod_id = MOD_NIL;
                    ilm_ptr.dest_mod_id = MOD_NIL;
                    ilm_ptr.msg_id = MSG_ID_MMI_EQ_NVRAM_READY_IND;
                    ilm_ptr.sap_id = INVALID_SAP;
                    ilm_ptr.local_para_ptr = NULL;
                    ilm_ptr.peer_buff_ptr = NULL;
                    memcpy(circq_array + (i * CIRCQ_NODE_SIZE), &ilm_ptr, CIRCQ_NODE_SIZE);
                    return circularQ_check_found;
                }

            }
            default:
                break;
        }
    }
    return circularQ_check_not_found;
}


/*****************************************************************************
 * FUNCTION
 *  AccessRecordInt
 * DESCRIPTION
 *  MMI level API to access NVRAM
 * PARAMETERS
 *  nFileId             [IN]        NVRAM data item id
 *  nRecordId           [IN]        Record index in a data item
 *  pBuffer             [OUT]       Buffer in which data need to
 *  nBufferSize         [IN]        Size of record to be read
 *  nRecordAmount       [IN]        
 *  pError              [OUT]       Error returned from PS
 *  isWrite             [IN]        True =write, false=read
 *  isValue             [IN]        True = from read/write Value
 *                                  False = from read/write Record
 *  filename            [IN]         
 *  lineNumber          [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 AccessRecordInt
    (U16 nFileId,
     U16 nRecordId,
     void *pBuffer, 
     U16 nBufferSize, 
     U16 nRecordAmount, 
     S16 *pError, 
     pBOOL isWrite, 
     pBOOL isValue,
     S8 *filename, 
     S32 lineNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE queueNode;
    S32 status = -1;
    U32 my_index;
    circularQ_check_enum circularQ_check_result = circularQ_check_never_check;
    static U8 nvram_req_count = 0;
    MMI_BOOL toPush;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_REC_INT_HDLR, nFileId, nRecordId);

    if (isWrite)
    {
        SendNVRAMWriteReq(nFileId, nRecordId, pBuffer, nBufferSize);

        if (!isValue)   /* call from read/write Record */
        {
            /* reset BYTE/SHORT/DOUBLE cache */
            /*   since others may access these LIDs directly */
            if (nFileId == NVRAM_EF_CACHE_BYTE_LID)
            {
                byteDataReadFlag = 0;
            }
            else if (nFileId == NVRAM_EF_CACHE_SHORT_LID)
            {
                uintDataReadFlag = 0;
            }
            else if (nFileId == NVRAM_EF_CACHE_DOUBLE_LID)
            {
                doubleDataReadFlag = 0;
            }
        }    
    }
    else
    {
        SendNVRAMReadReq(nFileId, nRecordId, nRecordAmount);
    }

    in_nvram_procedure++;
    while (1)
    {
        /* if more than 1 access request exist, go through the circular Q */
        if ((nvram_req_count > 0) && (circularQ_check_result == circularQ_check_never_check))
        {
            circularQ_check_result = NVRAMCheckCircularQ(&queueNode, nFileId);
        }

        if (circularQ_check_result != circularQ_check_found)
        {
            OslReceiveMsgExtQ(mmi_ext_qid, &queueNode);
            OslGetMyTaskIndex(&my_index);
            OslStackSetActiveModuleID(my_index, MOD_MMI);
        }

        toPush = MMI_FALSE;
        switch (queueNode.msg_id)
        {
            case MSG_ID_MMI_EQ_PLAY_AUDIO_RSP:
            case MSG_ID_MMI_EQ_STOP_AUDIO_RSP:
            case MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP:
            case MSG_ID_MMI_EQ_SET_VOLUME_RSP:
                OslFreeInterTaskMsg(&queueNode);
                break;
            case MSG_ID_MMI_EQ_KEYPAD_DETECT_IND:
            {
                mmi_eq_keypad_detect_ind_struct *p;

                p = (mmi_eq_keypad_detect_ind_struct*) queueNode.oslDataPtr;

                if (p->func != keypad_ptr)
                {
                    if (!mmi_kbd_process_keyptr_change((void *)p->func))
                    {
                        /* no further key to process */
                        OslFreeInterTaskMsg(&queueNode);
                        break;
                    }
                            
                    ClearKeyEvents();
                    keypad_ptr = p->func;
                }

			 	/* special handling before entering stable stable state.
			 	   But for charger and USB case, need to treat them as stable state */
			 	if ((mmi_bootup_is_power_on_animation_complete() == MMI_FALSE) &&
			 		(g_pwr_context.PowerOnMode != POWER_ON_PRECHARGE) &&
			 	    (g_pwr_context.PowerOnMode != POWER_ON_CHARGER_IN) &&
			 	    (g_pwr_context.PowerOnMode != POWER_ON_USB))
                {
                    ClearKeyEvents();
                }
                else
                {
                    g_keypad_flag = MMI_TRUE;
                }
                OslFreeInterTaskMsg(&queueNode);
                break;
            }
            /* We don't need to handle MSG_ID_MMI_EQ_GET_RTC_TIME_RSP in special condition */
            case MSG_ID_TIMER_EXPIRY:
            {
                /* only process non-alignment timer during power-up */
                if ( (mmi_bootup_is_searching_or_idle_reached() == MMI_FALSE) &&
                     !mmi_frm_is_align_base_timer(queueNode.oslDataPtr))
                {
                    kal_uint16 msg_len;

                    EvshedMMITimerHandler(get_local_para_ptr(queueNode.oslDataPtr, &msg_len));
                    OslFreeInterTaskMsg(&queueNode);
                    break;
                }
                else
                {
                    stack_timer_struct *stack_timer_ptr;

                    stack_timer_ptr = (stack_timer_struct*) queueNode.oslDataPtr;
                    if (!stack_is_time_out_valid(stack_timer_ptr))
                    {
                        PRINT_INFORMATION("==========Time out is not valid==========");
                        OslFreeInterTaskMsg(&queueNode);
                        break;
                    }
                }
                toPush = MMI_TRUE;
                break;
            }
            case MSG_ID_MMI_EQ_NVRAM_READ_RSP:
            {
                mmi_eq_nvram_read_rsp_struct *readMessage;

                readMessage = (mmi_eq_nvram_read_rsp_struct *)queueNode.oslDataPtr;

                if (readMessage->file_idx != nFileId)
                {
                    nvram_req_count++;
                }
                else
                {
                    if (readMessage->result.flag == MMI_OK)
                    {
                        PRINT_INFORMATION(" NVRAM Read Success");
                        if (readMessage->length > nBufferSize)
                        {
                            memcpy(pBuffer, readMessage->data, nBufferSize);
                            *pError = NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ;
                        }
                        else if (readMessage->length < nBufferSize)
                        {
                            memcpy(pBuffer, readMessage->data, readMessage->length);
                            *pError = NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ;
                        }
                        else
                        {
                            memcpy(pBuffer, readMessage->data, readMessage->length);
                            *pError = NVRAM_READ_SUCCESS;
                        }

                        status = readMessage->length;
                    }
                    else
                    {
                        PRINT_INFORMATION(" NVRAM Read Failed. Cause: %d", readMessage->result.cause);
                        //ASSERT(readMessage->result.flag == MMI_OK); //sc.wu  sim card2, calling end, exception
                        *pError = NVRAM_READ_FAIL;
                    }

                    OslFreeInterTaskMsg(&queueNode);
                    PRINT_INFORMATION(" Exiting Reading record status = %d\n", status);
                    if (nvram_req_count && circularQ_check_result == circularQ_check_found)
                    {
                        nvram_req_count--;
                    }

                    in_nvram_procedure--;
                    return status;
                }
                toPush = MMI_TRUE;
                break;
            }
            case MSG_ID_MMI_EQ_NVRAM_WRITE_RSP:
            {

                mmi_eq_nvram_write_rsp_struct *writeMessage;

                writeMessage = (mmi_eq_nvram_write_rsp_struct*) queueNode.oslDataPtr;

                if (writeMessage->file_idx != nFileId)
                {
                    nvram_req_count++;
                }
                else
                {
                    if (writeMessage->result.flag == MMI_OK)
                    {
                        PRINT_INFORMATION(" NVRAM Write Success");
                        *pError = NVRAM_WRITE_SUCCESS;
                        status = nBufferSize;
                    }
                    else
                    {
                        PRINT_INFORMATION(" NVRAM Write Failed. Cause: %d", writeMessage->result.cause);
                        ASSERT(writeMessage->result.flag == MMI_OK);
                        *pError = NVRAM_WRITE_FAIL;
                    }

                    OslFreeInterTaskMsg(&queueNode);
                    PRINT_INFORMATION(" Exiting Wriring record");
                    if (nvram_req_count && circularQ_check_result == circularQ_check_found)
                    {
                        nvram_req_count--;
                    }

                    in_nvram_procedure--;
                    return status;
                }
                toPush = MMI_TRUE;
                break;
            }

            default:
            {
                toPush = MMI_TRUE;
                break;
            }
        }

        if (toPush == MMI_TRUE)
        {
            ilm_struct ilm_ptr;
            U8 flag = 0;

            ilm_ptr.src_mod_id = queueNode.src_mod_id;
            ilm_ptr.dest_mod_id = queueNode.dest_mod_id;
            ilm_ptr.msg_id = queueNode.msg_id;
            ilm_ptr.sap_id = queueNode.sap_id;
            ilm_ptr.local_para_ptr = queueNode.local_para_ptr;
            ilm_ptr.peer_buff_ptr = queueNode.peer_buff_ptr;
            flag = OslWriteCircularQ(&ilm_ptr);
            /* TIMER use special data in the local_para_ptr field. Can NOT treat as general ILM */
            if ((queueNode.src_mod_id != MOD_TIMER) && (flag == 1))
            {
                hold_local_para(ilm_ptr.local_para_ptr);
                hold_peer_buff(ilm_ptr.peer_buff_ptr);
            }
            OslFreeInterTaskMsg(&queueNode);
        }

    }
}

#else /* __NEW_NVRAMINTERFACE__ */ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
     	         #ifdef __MTK_TARGET__
/* under construction !*/
     	         #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		         #ifdef __MTK_TARGET__
/* under construction !*/
		         #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
#endif /* __NEW_NVRAMINTERFACE__ */ 


/*****************************************************************************
 * FUNCTION
 *  DeleteRecord
 * DESCRIPTION
 *  User level API for Deleting record from the file
 * PARAMETERS
 *  nFileId         [IN]        File LID
 *  nRecordId       [IN]        Record index in file
 *  pError          [OUT]       Error returned from PS
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
pBOOL DeleteRecord(U16 nFileId, U16 nRecordId, S16 *pError)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYQUEUE queueNode;
    MMIEQNVRAMWRITERSP *writeMessage = NULL;
    U8 *pBuffer = NULL;
    S8 status = (S8) - 1;
    U32 msgSize;
    U8 noOfFiles = 0;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pError = -1;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_DELETE_REC_INT_HDLR);

    /* 0 Search for the LID index in logical_data_item_table_cust
       array of structures  */

    noOfFiles = NVRAM_EF_LAST_LID_CUST - NVRAM_LID_CUST_BEGIN - 1;

    for (count = 0; count < noOfFiles; ++count)
    {

        if (nFileId == logical_data_item_table_cust[count].LID)
        {
            break;
        }
    }

    pBuffer = (U8*) OslMalloc(logical_data_item_table_cust[count].size);

    memset(pBuffer, '\0', logical_data_item_table_cust[count].size);

    /* 1. Send Write Request */
    SendNVRAMWriteReq(nFileId, nRecordId, pBuffer, logical_data_item_table_cust[count].size);

    OslMfree(pBuffer);

    /* 2  Wait for write response on message queue */

    if (OslReadMsgQ(nvramQID, &queueNode, (U16*) & msgSize, OSL_INFINITE_WAIT) == OSL_SUCCESS)
    {
        writeMessage = (MMIEQNVRAMWRITERSP*) queueNode.oslDataPtr;
        if (writeMessage->result.flag == MMI_OK)
        {

            PRINT_INFORMATION(" Inside MMI_OK block");
            *pError = NVRAM_WRITE_SUCCESS;
            status = MMI_TRUE;

        }
        else
        {

            PRINT_INFORMATION(" Inside MMI_ERROR block");
            *pError = ST_FAILURE;
            status = MMI_FALSE;

        }

    }

    PRINT_INFORMATION(" Exiting Wriring record");
    OslMfree(writeMessage);

    return status;

}




/*****************************************************************************
 * FUNCTION
 *  ReadValueInt
 * DESCRIPTION
 *  User level API for 1 byte , 2 byte and 8 byte
 *  
 *  The nBufferSize shall be even
 * PARAMETERS
 *  nDataItemId     [IN]        Data Item ID
 *  pBuffer         [IN]        Buffer in which data need to
 *  nDataType       [IN]        
 *  pError          [OUT]       Error returned from PS
 *  fileName        [?]         
 *  lineNumber      [IN]        
 *  memory(?)       [IN]        For this.
 *  be(?)           [IN]        Retrieved,caller will allocate
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
S32 ReadValueInt(U8 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError, S8 *fileName, S32 lineNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 status = -1;
    S16 error = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_HDLR, nDataItemId, nDataType);

    switch (nDataType)
    {

        case DS_BYTE:
        {
            /* second time reading, it alwasy return one request item */
            if (byteDataReadFlag)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_INFO_HDLR, nDataType);
                /* Data is cached no need to read from NVRAM */
                memcpy(pBuffer, &byte_data[nDataItemId * nDataType], nDataType);
                status = DS_BYTE;
                error = NVRAM_READ_SUCCESS;
            }
            /* process first time reading all data and return first request item data */
            else
            {
                /* Read data from the NVRAM file */
                /* NVRAM_CACHED_FILE_LID is defined in Pluto NVRAM files, first time to read all out */
                U8 tempBuffer[NVRAM_CACHE_SIZE];

                status = ReadRecordInt(
                            NVRAM_EF_CACHE_BYTE_LID,
                            1,
                            tempBuffer,
                            sizeof(tempBuffer),
                            &error,
                            fileName,
                            lineNumber);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR);
                    *pError = -1;
                    return status;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_INFO2_HDLR, nDataType);
                /* copy out all total reading data */
                memcpy(byte_data, tempBuffer, sizeof(tempBuffer));
                byteDataReadFlag = 1;
                /* return first request item data */
                memcpy(pBuffer, &byte_data[nDataItemId * nDataType], nDataType);
                status = DS_BYTE;
                error = NVRAM_READ_SUCCESS;

            }
            break;
        }   /* End of case DS_BYTE */

        case DS_SHORT:
        {
            if (uintDataReadFlag)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_INFO_HDLR, nDataType);
                /* Data is cached no need to read from NVRAM */
                memcpy(pBuffer, &uint_data[nDataItemId * nDataType], nDataType);
                status = DS_SHORT;
                error = NVRAM_READ_SUCCESS;
            }
            else
            {
                /* Read data from the NVRAM file */
                /* NVRAM_CACHED_FILE_LID is defined in Pluto NVRAM files */
                U8 tempBuffer[NVRAM_CACHE_SIZE];

                status = ReadRecordInt(
                            NVRAM_EF_CACHE_SHORT_LID,
                            1,
                            tempBuffer,
                            sizeof(tempBuffer),
                            &error,
                            fileName,
                            lineNumber);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR);
                    *pError = -1;
                    return status;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_INFO2_HDLR, nDataType);
                memcpy(uint_data, tempBuffer, NVRAM_CACHE_SIZE);
                uintDataReadFlag = 1;
                memcpy(pBuffer, &uint_data[nDataItemId * nDataType], nDataType);
                status = DS_SHORT;
                error = NVRAM_READ_SUCCESS;

            }
            break;
        }   /* End of case DS_SHORT */

        case DS_DOUBLE:
        {
            if (doubleDataReadFlag)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_INFO_HDLR, nDataType);
                /* Data is cached no need to read from NVRAM */
                memcpy(pBuffer, &double_data[nDataItemId * nDataType], nDataType);
                status = DS_DOUBLE;
                error = NVRAM_READ_SUCCESS;
            }
            else
            {
                /* Read data from the NVRAM file */
                /* NVRAM_CACHED_FILE_LID is defined in Pluto NVRAM files */
                U8 tempBuffer[NVRAM_CACHE_SIZE];

                status = ReadRecordInt(
                            NVRAM_EF_CACHE_DOUBLE_LID,
                            1,
                            tempBuffer,
                            NVRAM_CACHE_SIZE,
                            &error,
                            fileName,
                            lineNumber);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR);
                    *pError = -1;
                    return status;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_READ_VAL_INT_INFO2_HDLR, nDataType);
                memcpy(double_data, tempBuffer, NVRAM_CACHE_SIZE);
                doubleDataReadFlag = 1;
                memcpy(pBuffer, &double_data[nDataItemId * nDataType], nDataType);
                status = DS_DOUBLE;
                error = NVRAM_READ_SUCCESS;

            }
            break;
        }   /* End of case DS_DOUBLE */
    }

    *pError = error;
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  WriteValueInt
 * DESCRIPTION
 *  User level API to write 1 byte , 2 byte and 8 byte
 *  
 *  The nBufferSize shall be even
 * PARAMETERS
 *  nDataItemId     [IN]        Data Item ID
 *  pBuffer         [IN]        Buffer in which data need to
 *  nDataType       [IN]        
 *  pError          [OUT]       Error returned from PS
 *  fileName        [?]         
 *  lineNumber      [IN]        
 *  memory(?)       [IN]        For this.
 *  be(?)           [IN]        Retrieved,caller will allocate
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
S32 WriteValueInt(U8 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError, S8 *fileName, S32 lineNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = -1;
    S32 status = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_HDLR, nDataItemId, nDataType);

    switch (nDataType)
    {
        case DS_BYTE:
        {
            /* second time access, it always sets the request item */
            if (byteDataReadFlag)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO_HDLR, nDataType);
                /* Data is cached no need to read from NVRAM */
                memcpy(&byte_data[nDataItemId * nDataType], pBuffer, nDataType);
                /* write into NVRAM module, if not wait for falshing directly */
                if (!byteDataWriteFlashFlag)
                {
                    status = WriteRecordInt(
                                NVRAM_EF_CACHE_BYTE_LID,
                                1,
                                byte_data,
                                NVRAM_CACHE_SIZE,
                                &error,
                                fileName,
                                lineNumber);
                    if (status == -1)
                    {
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                        *pError = -1;
                        return status;
                    }
                }
                status = DS_BYTE;
                error = NVRAM_WRITE_SUCCESS;
            }
            /* process first time access all data and return first write item data */
            else
            {
                /* Read all data from the NVRAM file */
                /* NVRAM_CACHED_FILE_LID is defined in Pluto NVRAM files */
                status = ReadRecordInt(
                            NVRAM_EF_CACHE_BYTE_LID,
                            1,
                            byte_data,
                            NVRAM_CACHE_SIZE,
                            &error,
                            fileName,
                            lineNumber);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR);
                    *pError = -1;
                    return status;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO2_HDLR, nDataType);
                memcpy(&byte_data[nDataItemId * nDataType], pBuffer, nDataType);
                /* write into NVRAM module, if not wait for falshing directly */
                if (!byteDataWriteFlashFlag)
                {
                    status = WriteRecordInt(
                                NVRAM_EF_CACHE_BYTE_LID,
                                1,
                                byte_data,
                                NVRAM_CACHE_SIZE,
                                &error,
                                fileName,
                                lineNumber);
                }
                byteDataReadFlag = 1;
                status = DS_BYTE;
                error = NVRAM_WRITE_SUCCESS;
            }
            break;
        }   /* End of case DS_BYTE */

        case DS_SHORT:
        {
            if (uintDataReadFlag)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO_HDLR, nDataType);
                /* Data is cached no need to read from NVRAM */
                memcpy(&uint_data[nDataItemId * nDataType], pBuffer, nDataType);
                /* write into NVRAM module, if not wait for falshing directly */
                if (!uintDataWriteFlashFlag)
                {
                    status = WriteRecordInt(
                                NVRAM_EF_CACHE_SHORT_LID,
                                1,
                                uint_data,
                                NVRAM_CACHE_SIZE,
                                &error,
                                fileName,
                                lineNumber);
                    if (status == -1)
                    {
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                        *pError = -1;
                        return status;
                    }
                }
                status = DS_SHORT;
                error = NVRAM_WRITE_SUCCESS;

            }
            else
            {
                /* Read data from the NVRAM file */
                /* NVRAM_CACHED_FILE_LID is defined in Pluto NVRAM files */
                status = ReadRecordInt(
                            NVRAM_EF_CACHE_SHORT_LID,
                            1,
                            uint_data,
                            NVRAM_CACHE_SIZE,
                            &error,
                            fileName,
                            lineNumber);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR);
                    *pError = -1;
                    return status;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO2_HDLR, nDataType);
                memcpy(&uint_data[nDataItemId * nDataType], pBuffer, nDataType);
                /* write into NVRAM module, if not wait for falshing directly */
                if (!uintDataWriteFlashFlag)
                {
                    WriteRecordInt(
                        NVRAM_EF_CACHE_SHORT_LID,
                        1,
                        uint_data,
                        NVRAM_CACHE_SIZE,
                        &error,
                        fileName,
                        lineNumber);
                }
                uintDataReadFlag = 1;
                status = DS_SHORT;
                error = NVRAM_WRITE_SUCCESS;
            }
            break;
        }   /* End of case DS_SHORT */

        case DS_DOUBLE:
        {
            if (doubleDataReadFlag)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO_HDLR, nDataType);
                /* Data is cached no need to read from NVRAM */
                memcpy(&double_data[nDataItemId * nDataType], pBuffer, nDataType);
                /* write into NVRAM module, if not wait for falshing directly */
                if (!doubleDataWriteFlashFlag)
                {
                    status = WriteRecordInt(
                                NVRAM_EF_CACHE_DOUBLE_LID,
                                1,
                                double_data,
                                NVRAM_CACHE_SIZE,
                                &error,
                                fileName,
                                lineNumber);
                    if (status == -1)
                    {
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                        *pError = -1;
                        return status;
                    }
                }
                status = DS_DOUBLE;
                error = NVRAM_WRITE_SUCCESS;
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_VAL_INT_INFO_HDLR, nDataType);
                /* Read data from the NVRAM file */
                /* NVRAM_CACHED_FILE_LID is defined in Pluto NVRAM files */
                status = ReadRecordInt(
                            NVRAM_EF_CACHE_DOUBLE_LID,
                            1,
                            double_data,
                            NVRAM_CACHE_SIZE,
                            &error,
                            fileName,
                            lineNumber);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_READ_VAL_INT_HDLR);
                    *pError = -1;
                    return status;
                }
                memcpy(&double_data[nDataItemId * nDataType], pBuffer, nDataType);
                /* write into NVRAM module, if not wait for falshing directly */
                if (!doubleDataWriteFlashFlag)
                {
                    status = WriteRecordInt(
                                NVRAM_EF_CACHE_DOUBLE_LID,
                                1,
                                double_data,
                                NVRAM_CACHE_SIZE,
                                &error,
                                fileName,
                                lineNumber);
                    if (status == -1)
                    {
                        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                        *pError = -1;
                        return status;
                    }
                }
                status = DS_DOUBLE;
                error = NVRAM_WRITE_SUCCESS;
                doubleDataReadFlag = 1;
            }
            break;
        }   /* End of case DS_DOUBLE */

    }   /* End of switch */

    *pError = error;
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  SetFlashNVRAMCatchData
 * DESCRIPTION
 *  This function is to set the flag if want to flash the BYTE, SHORT, or DOUBLE of catch datas into NVRAM.
 * PARAMETERS
 *  nDataType                   [IN]        
 *  l_DataWriteFlashFlag        [IN]        
 *  a(?)                        [IN]        Is to enable to flash into NVRAM or not, TRUE is to flash into NVRAM, otherwise is false.
 * RETURNS
 *  Data set success or not.
 *****************************************************************************/
U8 SetFlashNVRAMCatchData(U8 nDataType, U8 l_DataWriteFlashFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_FLASH_CATCH_DATA_HDLR, nDataType, l_DataWriteFlashFlag);

    switch (nDataType)
    {
        case DS_BYTE:
            byteDataWriteFlashFlag = l_DataWriteFlashFlag;
            break;
        case DS_SHORT:
            uintDataWriteFlashFlag = l_DataWriteFlashFlag;
            break;
        case DS_DOUBLE:
            doubleDataWriteFlashFlag = l_DataWriteFlashFlag;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetFlashAllNVRAMCatchData
 * DESCRIPTION
 *  This function is to set the flag if want to flash all the BYTE, SHORT, and DOUBLE of catch datas into NVRAM.
 * PARAMETERS
 *  l_DataWriteFlashFlag        [IN]        
 *  a(?)                        [IN]        Is to enable to flash into NVRAM or not, TRUE is to flash into NVRAM, otherwise is false.
 * RETURNS
 *  Data set success or not.
 *****************************************************************************/
U8 SetFlashAllNVRAMCatchData(U8 l_DataWriteFlashFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_FLASH_CATCH_ALL_DATA_HDLR, l_DataWriteFlashFlag);

    byteDataWriteFlashFlag = l_DataWriteFlashFlag;
    uintDataWriteFlashFlag = l_DataWriteFlashFlag;
    doubleDataWriteFlashFlag = l_DataWriteFlashFlag;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  WriteFlashNVRAMCatchData
 * DESCRIPTION
 *  This function is to write the BYTE, SHORT, DOUBLE of catch datas into NVRAM.
 * PARAMETERS
 *  nDataType       [IN]        
 *  a(?)            [IN]        Is BYTE, SHORT, DOUBLE data type.
 * RETURNS
 *  Data write success or not.
 *****************************************************************************/
S32 WriteFlashNVRAMCatchData(U8 nDataType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 status = -1;
    S16 error = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_WRITE_NVM_CATCH_DATA_HDLR, nDataType);

    switch (nDataType)
    {
        case DS_BYTE:
            if (byteDataWriteFlashFlag)
            {
                byteDataWriteFlashFlag = MMI_FALSE;
                status = WriteRecordInt(
                            NVRAM_EF_CACHE_BYTE_LID,
                            1,
                            byte_data,
                            sizeof(byte_data),
                            &error,
                            __FILE__,
                            __LINE__);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                    MMI_ASSERT(0);
                    return status;
                }
            }
            break;
        case DS_SHORT:
            if (uintDataWriteFlashFlag)
            {
                uintDataWriteFlashFlag = MMI_FALSE;
                status = WriteRecordInt(
                            NVRAM_EF_CACHE_SHORT_LID,
                            1,
                            uint_data,
                            sizeof(uint_data),
                            &error,
                            __FILE__,
                            __LINE__);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                    MMI_ASSERT(0);
                    return status;
                }
            }
            break;
        case DS_DOUBLE:
            if (doubleDataWriteFlashFlag)
            {
                doubleDataWriteFlashFlag = MMI_FALSE;
                status = WriteRecordInt(
                            NVRAM_EF_CACHE_DOUBLE_LID,
                            1,
                            double_data,
                            sizeof(double_data),
                            &error,
                            __FILE__,
                            __LINE__);
                if (status == -1)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
                    MMI_ASSERT(0);
                    return status;
                }
            }
            break;
        default:
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_WARN_NVM_WRITE_HDLR);
            MMI_ASSERT(0);
            break;
    }
    return status;

}


/*****************************************************************************
 * FUNCTION
 *  WriteFlashAllNVRAMCatchData
 * DESCRIPTION
 *  This function is to write all catch data into NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  Data write success or not.
 *****************************************************************************/
S32 WriteFlashAllNVRAMCatchData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 status = -1;
    S16 error = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_NVM_FLASH_ALL_CATCH_DATA_HDLR);

    if (byteDataWriteFlashFlag)
    {
        byteDataWriteFlashFlag = MMI_FALSE;
        status = WriteRecordInt(NVRAM_EF_CACHE_BYTE_LID, 1, byte_data, NVRAM_CACHE_SIZE, &error, __FILE__, __LINE__);
        if (status == -1)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
            MMI_ASSERT(0);
            return status;
        }
    }
    if (uintDataWriteFlashFlag)
    {
        uintDataWriteFlashFlag = MMI_FALSE;
        status = WriteRecordInt(NVRAM_EF_CACHE_SHORT_LID, 1, uint_data, NVRAM_CACHE_SIZE, &error, __FILE__, __LINE__);
        if (status == -1)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
            MMI_ASSERT(0);
            return status;
        }
    }
    if (doubleDataWriteFlashFlag)
    {
        doubleDataWriteFlashFlag = MMI_FALSE;
        status = WriteRecordInt(NVRAM_EF_CACHE_DOUBLE_LID, 1, double_data, NVRAM_CACHE_SIZE, &error, __FILE__, __LINE__);
        if (status == -1)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ERROR_NVM_WRITE_VAL_INT_HDLR);
            MMI_ASSERT(0);
            return status;
        }
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  IsInNVRAMProcedure
 * DESCRIPTION
 *  This function is to check if in NVRAM procedure while loop
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE - in NVRAM procedure
 *  MMI_FALSE - not in NVRAM procedure
 *****************************************************************************/
U8 IsInNVRAMProcedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION(" IsInNVRAMProcedure(%d)", in_nvram_procedure);
    return (in_nvram_procedure > 0) ? (U8) MMI_TRUE : (U8) MMI_FALSE;
}

