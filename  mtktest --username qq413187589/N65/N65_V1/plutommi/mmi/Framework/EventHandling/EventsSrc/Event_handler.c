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
* Event_handler.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends for protocol/keypad/interrupt event handler .
*
* Author:
* -------
*  Xiaodong Wang (mbj06019)
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * call mmi_frm_clear_all_slave_protocol_event_handler() in mmi_frm_clear_all_protocol_event_handler()
 *
 * removed!
 * removed!
 * Remove duplicated interfaces
 *
 * removed!
 * removed!
 * Change the mechanism in mmi_frm_execute_current_protocol_handler()
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * Add event handler trace
 *
 * removed!
 * removed!
 * Add compile option for filemanage message
 *
 * removed!
 * removed!
 * New file for processing event handlers
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "mmi_include.h"
#include "FrameworkGprot.h"
#include "FrameworkProt.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "Wapadp.h"
#include "BTMMIOppGprots.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_EVENT_INVALID  0
#define INTERRUPT_EVENT_GREOUP_SIZE     (4)
#define IS_INTERRUPT_EVENT_GROUP(x)    (((x)&MMI_INT_EVENT_GROUP_MASK) == MMI_INT_EVENT_GROUP_MASK)
#define MMI_FRM_PRE_INT_HDLR    1
#define MMI_FRM_POST_INT_HDLR   2

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
 #ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
 typedef struct
{
    U16 groupID;
    U16 eventID[INTERRUPT_EVENT_GREOUP_SIZE];
} InterruptGroupInfo;
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */

typedef struct _mmi_frm_int_mask_hdlr_struct
{
    mmi_frm_int_event_type event_mask;
    interrupt_event_hdlr int_func_ptr;
    interrupt_event_hdlr post_int_func_ptr;
} mmi_frm_int_mask_hdlr_struct;

typedef struct
{
    U16 event_id;
    mmi_frm_int_event_type int_event_macro;
} mmi_frm_int_event_convert_struct;

typedef enum
{
    MMI_FRM_INT_EVENT_SPECIFIC,
    MMI_FRM_INT_EVENT_GENERAL,
    MMI_FRM_INT_EVENT_TYPE_NUM
} mmi_frm_int_event_type_list_enum;

/*****************************************************************************
 * Global Variable                                                             
 *****************************************************************************/
U16 maxProtocolEvent;
U16 usedProtocolEvent;
PseventInfo protocolEventHandler[MAX_PROTOCOL_EVENT];

#ifdef __MMI_DUAL_SIM__
U16 maxSlaveProtocolEvent;
U16 usedSlaveProtocolEvent;
PseventInfo SlaveProtocolEventHandler[MAX_SLAVE_PROTOCOL_EVENT];
#endif /* __MMI_DUAL_SIM__ */

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
U16 maxInterruptEvent;
PsInteventInfo interruptEventHandler[MAX_INTERRUPT_EVENT];
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */

/*****************************************************************************
 * Local Variable                                                             
 *****************************************************************************/
static mmi_frm_int_mask_hdlr_struct mmi_frm_int_mask_hdlr[MMI_FRM_INT_EVENT_TYPE_NUM];

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
static const InterruptGroupInfo interruptGroupEventTable[] = 
{
    {MMI_SMS_INT_EVENT_GROUP,
     {PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND,
      PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND,
      PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND,
      0 /* end at 0 */
      }
     }
#if defined(__MMI_FILE_MANAGER__)
    ,{MMI_CARD_PLUG_EVENT_GROUP,
     {PRT_MMI_FMGR_CARD_PLUG_IN_IND,
      PRT_MMI_FMGR_CARD_PLUG_OUT_IND,
      0 /* end at 0 */
      }
     }
#endif /* __MMI_FILE_MANAGER__ */
};
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */

static const mmi_frm_int_event_convert_struct mmi_frm_int_event_battery_table[] = 
{
    {PMIC_CHARGER_IN,           MMI_FRM_INT_CHARGER_IN},
    {PMIC_CHARGER_OUT,          MMI_FRM_INT_CHARGER_OUT},
    {PMIC_CHARGE_COMPLETE,      MMI_FRM_INT_CHARGE_COMPLETE},
    {PMIC_USB_CHARGER_IN,       MMI_FRM_INT_USB_CHARGER_IN},
    {PMIC_USB_CHARGER_OUT,      MMI_FRM_INT_USB_CHARGER_OUT},
    {PMIC_USB_NO_CHARGER_IN,    MMI_FRM_INT_USB_NO_CHARGER_IN},
    {PMIC_USB_NO_CHARGER_OUT,   MMI_FRM_INT_USB_NO_CHARGER_OUT}
};

static const mmi_frm_int_event_convert_struct mmi_frm_int_event_convert_table[] = 
{
    {PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND,    MMI_FRM_INT_SMS_DELIVER},
    {PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND,  MMI_FRM_INT_SMS_STATUS_REPORT},
    {PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND,    MMI_FRM_INT_SMS_MSG_WAITING},
    {PRT_MSG_ID_MMI_SMS_APP_DATA_IND,       MMI_FRM_INT_SMS_APP_DATA},
#if defined(__MMI_FILE_MANAGER__)
    {PRT_MMI_FMGR_CARD_PLUG_IN_IND,         MMI_FRM_INT_FMGR_CARD_PLUG_IN},
    {PRT_MMI_FMGR_CARD_PLUG_OUT_IND,        MMI_FRM_INT_FMGR_CARD_PLUG_OUT},
#endif /* __MMI_FILE_MANAGER__ */
	{MSG_ID_MMI_VOIP_CALL_RING_IND,				MMI_FRM_INT_VOIP_CALL_RING},
	{MSG_ID_MMI_CC_CALL_RING_IND,				MMI_FRM_INT_CC_CALL_RING},
    {PRT_L4AUD_AUDIO_PLAY_FINISH_IND,       MMI_FRM_INT_AUDIO_PLAY_FINISH}
};

static MMI_BOOL mmi_frm_process_non_mmi_task = MMI_FALSE;

/*****************************************************************************
 * Local Function                                                              
 *****************************************************************************/
/* New interrupt event internal function */
static MMI_BOOL mmi_frm_query_interrupt_event_information(mmi_frm_int_event_type frm_int_event, interrupt_event_hdlr *int_func, interrupt_event_hdlr *post_int_func);
static mmi_frm_int_event_type mmi_frm_interrupt_event_converter(U16 event_id, void *msg);

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
static MMI_BOOL mmi_frm_query_interrupt_handler(U16 event_id, PsIntFuncPtr *func_ptr, PsIntFuncPtr *post_func_ptr);
#endif

/*****************************************************************************
 * Extern data and function                                                             
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_execute_current_protocol_handler
 * DESCRIPTION
 *  This function is used for executes current protocol func handler.
 * PARAMETERS
 *  eventID         [IN]  Unique Protocol/System EventID       
 *  MsgStruct       [IN]  The pointer to the message.      
 *  mod_src         [IN]  Source module ID.     
 *  peerBuf         [IN]  The pointer to the peer buffe.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_execute_current_protocol_handler(U16 eventID, void *MsgStruct, int mod_src, void *peerBuf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /* PsExtFuncPtr currFuncPtr = NULL; */
    PsExtPeerFuncPtr currFuncPtr = NULL;
#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
    PsIntFuncPtr IntFunc = NULL, PostIntFunc = NULL;
    PsExtPeerIntFuncPtr currInterruptFuncPtr = NULL, currPostInterruptFuncPtr = NULL;
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */
    U8 interrup_result = MMI_FALSE; /* False not handle interrupt, True will handle */

    /* new interrupt event mechanism */
    MMI_BOOL query_result = MMI_FALSE, execute_result = MMI_FALSE;
    interrupt_event_hdlr int_func = NULL, post_int_func = NULL;
    mmi_frm_int_event_type current_frm_int_event;
        
#if defined (MMI_EVENT_PROFILING)
    kal_uint32 start_tick, end_tick;
    static kal_uint32 accu_ticks = 0;
    static U32 accu_count = 0;
#endif /* defined (MMI_EVENT_PROFILING) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined (MMI_EVENT_PROFILING)
    kal_get_time(&start_tick);
#endif 
#ifdef __MMI_DUAL_SIM__
    if (mod_src == MOD_L4C_2)
    {
        /* Search events in slave protocol event handler table */
        for (count = 0; count < maxSlaveProtocolEvent; count++)
        {
            if (SlaveProtocolEventHandler[count].eventID == eventID)
            {
                currFuncPtr = (PsExtPeerFuncPtr) SlaveProtocolEventHandler[count].entryFuncPtr;
                if (count > 0)
                {   /* improve the search efficiently */
                    SlaveProtocolEventHandler[count].eventID = SlaveProtocolEventHandler[count - 1].eventID;
                    SlaveProtocolEventHandler[count].entryFuncPtr = SlaveProtocolEventHandler[count - 1].entryFuncPtr;

                    SlaveProtocolEventHandler[count - 1].eventID = eventID;
                    SlaveProtocolEventHandler[count - 1].entryFuncPtr = (PsFuncPtr) currFuncPtr;
                }
                break;
            }
        }
    }
    else
#endif /* __MMI_DUAL_SIM__ */
    {
        /* Search events in protocol event handler table */
        for (count = 0; count < maxProtocolEvent; count++)
        {
            if (protocolEventHandler[count].eventID == eventID)
            {
                currFuncPtr = (PsExtPeerFuncPtr) protocolEventHandler[count].entryFuncPtr;
                if (count > 0)
                {   /* improve the search efficiently */
                    protocolEventHandler[count].eventID = protocolEventHandler[count - 1].eventID;
                    protocolEventHandler[count].entryFuncPtr = protocolEventHandler[count - 1].entryFuncPtr;
        
                    protocolEventHandler[count - 1].eventID = eventID;
                    protocolEventHandler[count - 1].entryFuncPtr = (PsFuncPtr) currFuncPtr;
                }
                break;
            }
        }
    }

#if defined (MMI_EVENT_PROFILING)
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "ExecuteCurrProtocolHandler count = %d", count);
    accu_count += count;
#endif /* defined (MMI_EVENT_PROFILING) */ 

#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
    /* Old Search events in interrupt event handler table */
    mmi_frm_query_interrupt_handler(eventID, &IntFunc, &PostIntFunc);
    currInterruptFuncPtr = (PsExtPeerIntFuncPtr) IntFunc;
    currPostInterruptFuncPtr = (PsExtPeerIntFuncPtr) PostIntFunc;
    /* Old interruption mechanism */
    if (currInterruptFuncPtr)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURPTO_INTP_HDLR, eventID);
        interrup_result = (*currInterruptFuncPtr) (MsgStruct, mod_src, peerBuf);
    }
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */

    /* New Search events in interrupt event handler mask table */
    current_frm_int_event = mmi_frm_interrupt_event_converter(eventID, MsgStruct);
    if (current_frm_int_event > 0)
    {
        query_result = mmi_frm_query_interrupt_event_information(current_frm_int_event, &int_func, &post_int_func);
    }
    if (query_result && int_func)
    {
        /* New interruption mechanism */
        execute_result = (*int_func)(current_frm_int_event);
    }
    
    /* if(currFuncPtr) */
    if ((currFuncPtr) && (!interrup_result) && (!execute_result))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_EXECURPTO_HDLR, eventID);
        /* (*currFuncPtr)(MsgStruct,mod_src); */
        (*currFuncPtr) (MsgStruct, mod_src, peerBuf);
    }
    else
    {
        MMI_TRACE(MMI_TRACE_WARNING, MMI_FRM_INFO_EVENT_EXECURPTO_NO_HDLR, eventID);
    }
    
#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
    if (currPostInterruptFuncPtr)
    {
        (*currPostInterruptFuncPtr) (MsgStruct, mod_src, peerBuf);
    }
#endif /* MMI_FRM_BACKWARD_COMPATIBLE_EVENTS */

    /* New interruption mechanism */    
    if (query_result && post_int_func)
    {
        execute_result = (*post_int_func)(current_frm_int_event);
    }

#if defined (MMI_EVENT_PROFILING)
    kal_get_time(&end_tick);
    accu_ticks += (end_tick - start_tick);
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "ExecuteCurrProtocolHandler accu_count = %d", accu_count);
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "ExecuteCurrProtocolHandler accu_ticks = %d", accu_ticks);
    PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "ExecuteCurrProtocolHandler maxProtocolEvent = %d", maxProtocolEvent);

#endif /* defined (MMI_EVENT_PROFILING) */ 
}


/*****************************************************************************
 * FUNCTION
 *  SetProtocolEventHandler
 * DESCRIPTION
 *  This function is used for register the protocol event handler. Whenever 
 *  an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  funcPtr     [IN] Function to be executed whenever a event is received 
 *                   from the protocol or system       
 *  eventID     [IN] Unique Protocol/System EventID.       
 * RETURNS
 *  void
 *****************************************************************************/
void SetProtocolEventHandler(PsFuncPtr funcPtr, U16 eventID)
{
	mmi_frm_set_protocol_event_handler( funcPtr,  eventID);
}
 
void mmi_frm_set_protocol_event_handler(PsFuncPtr funcPtr, U16 eventID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 maxUsedInHistory = 0;
    U16 count;
    S16 i, firstNotUsed;
    S16 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eventID != 0);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETPTO_HDLR, eventID, funcPtr, usedProtocolEvent,
               maxProtocolEvent);

    /* serach */
    pos = -1;
    firstNotUsed = -1;
    for (count = 0; count < maxProtocolEvent; count++)
    {
        if (protocolEventHandler[count].eventID == eventID)
        {
            pos = count;
            break;
        }
        /* BTW, find a non-used item */ ;
        if ((firstNotUsed == -1) && (protocolEventHandler[count].eventID == MMI_EVENT_INVALID))
        {
            firstNotUsed = count;
        }
    }

    if (pos != -1)
    {
        /* found */
        if (funcPtr != NULL)
        {
            /* just need to update */
            protocolEventHandler[pos].entryFuncPtr = funcPtr;
        }
        else
        {
            /* reset it */
            protocolEventHandler[pos].eventID = MMI_EVENT_INVALID;
            protocolEventHandler[pos].entryFuncPtr = NULL;
            usedProtocolEvent--;
        }
    }
    else
    {
        /* not found */
        if (funcPtr != NULL)
        {
            /* newly set */
            if (firstNotUsed != -1)
            {
                pos = firstNotUsed;
            }
            else
            {
                /* need to enlarge current searching list */
                pos = maxProtocolEvent;
                maxProtocolEvent++;
                MMI_ASSERT(maxProtocolEvent < MAX_PROTOCOL_EVENT);
            }
            usedProtocolEvent++;
            protocolEventHandler[pos].eventID = eventID;
            protocolEventHandler[pos].entryFuncPtr = funcPtr;
        }
        else
        {
            /* do nothing */
        }
    }

    /* recycle not-used items in the tail of list. It is for searching efficency */
    for (i = (maxProtocolEvent - 1); i >= 0; i--)
    {
        if (protocolEventHandler[i].eventID != MMI_EVENT_INVALID)
        {
            break;
        }
    }
    maxProtocolEvent = i + 1;

    /* record the max value for array size analysis */
    if (maxUsedInHistory < maxProtocolEvent)
    {
        PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "SetProtocolEventHandler old maxUsedInHistory = %d", maxUsedInHistory);
        maxUsedInHistory = maxProtocolEvent;
        PRINT_INFORMATION_2(MMI_FW_TRC_G1_FRM, "SetProtocolEventHandler maxUsedInHistory = %d", maxUsedInHistory);
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETPTO_HDLR, eventID, funcPtr, usedProtocolEvent,
               maxProtocolEvent);
}


/*****************************************************************************
 * FUNCTION
 *  ClearProtocolEventHandler
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  eventID     [IN] Clear the handler of event ID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_protocol_event_handler(U16 eventID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRPTO_HDLR, eventID);
    SetProtocolEventHandler(NULL, eventID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear all the protocol event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRALLPTO_HDLR);

    memset(protocolEventHandler, 0, sizeof(PseventInfo)* maxProtocolEvent); 

    
    usedProtocolEvent = 0;
    
    SetProtocolEventHandler(mmi_proc_inject_string, MSG_ID_TST_INJECT_STRING);

#ifdef __MMI_DUAL_SIM__
    mmi_frm_clear_all_slave_protocol_event_handler();
#endif
}


#ifdef __MMI_DUAL_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_slave_protocol_event_handler
 * DESCRIPTION
 *  This function is used for register the protocol event handler for slave card. 
 *  Whenever an event is received from the protocol or system corresponding function 
 *  is executed.
 * PARAMETERS
 *  funcPtr     [IN] Function to be executed whenever a event is received 
 *                   from the protocol or system       
 *  eventID     [IN] Unique Protocol/System EventID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_slave_protocol_event_handler(PsFuncPtr funcPtr, U16 eventID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 maxUsedInHistory = 0;
    U16 count;
    S16 i, firstNotUsed;
    S16 pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eventID != 0);
  //MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_EVENT_SETSLPTO_HDLR, eventID, funcPtr, usedSlaveProtocolEvent,
  //           maxSlaveProtocolEvent);

    /* serach */
    pos = -1;
    firstNotUsed = -1;
    for (count = 0; count < maxSlaveProtocolEvent; count++)
    {
        if (SlaveProtocolEventHandler[count].eventID == eventID)
        {
            pos = count;
            break;
        }
        /* BTW, find a non-used item */ ;
        if ((firstNotUsed == -1) && (SlaveProtocolEventHandler[count].eventID == MMI_EVENT_INVALID))
        {
            firstNotUsed = count;
        }
    }

    if (pos != -1)
    {
        /* found */
        if (funcPtr != NULL)
        {
            /* just need to update */
            SlaveProtocolEventHandler[pos].entryFuncPtr = funcPtr;
        }
        else
        {
            /* reset it */
            SlaveProtocolEventHandler[pos].eventID = MMI_EVENT_INVALID;
            SlaveProtocolEventHandler[pos].entryFuncPtr = NULL;
            usedSlaveProtocolEvent--;
        }
    }
    else
    {
        /* not found */
        if (funcPtr != NULL)
        {
            /* newly set */
            if (firstNotUsed != -1)
            {
                pos = firstNotUsed;
            }
            else
            {
                /* need to enlarge current searching list */
                pos = maxSlaveProtocolEvent;
                maxSlaveProtocolEvent++;
                MMI_ASSERT(maxSlaveProtocolEvent < MAX_SLAVE_PROTOCOL_EVENT);
            }
            usedSlaveProtocolEvent++;
            SlaveProtocolEventHandler[pos].eventID = eventID;
            SlaveProtocolEventHandler[pos].entryFuncPtr = funcPtr;
        }
        else
        {
            /* do nothing */
        }
    }

    /* recycle not-used items in the tail of list. It is for searching efficency */
    for (i = (maxSlaveProtocolEvent - 1); i >= 0; i--)
    {
        if (SlaveProtocolEventHandler[i].eventID != MMI_EVENT_INVALID)
        {
            break;
        }
    }
    maxSlaveProtocolEvent = i + 1;

    /* record the max value for array size analysis */
    if (maxUsedInHistory < maxSlaveProtocolEvent)
    {
    //    PRINT_INFORMATION_2(MMI_TRACE_G1_FRM, "SetSlaveProtocolEventHandler old maxUsedInHistory = %d", maxUsedInHistory);
        maxUsedInHistory = maxSlaveProtocolEvent;
  //      PRINT_INFORMATION_2(MMI_TRACE_G1_FRM, "SetSlaveProtocolEventHandler maxUsedInHistory = %d", maxUsedInHistory);
    }

   // MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_EVENT_SETSLPTO_HDLR, eventID, funcPtr, usedSlaveProtocolEvent,
   //            maxSlaveProtocolEvent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_slave_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear protocol event handler
 * PARAMETERS
 *  eventID     [IN] Clear the handler of event ID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_slave_protocol_event_handler(U16 eventID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_EVENT_CLRSLPTO_HDLR, eventID);
    mmi_frm_set_slave_protocol_event_handler(NULL, eventID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_slave_protocol_event_handler
 * DESCRIPTION
 *  This is used to clear all the protocol event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_slave_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_TRACE_G1_FRM, MMI_FRM_INFO_EVENT_CLRSLALLPTO_HDLR);

    memset(SlaveProtocolEventHandler, 0, sizeof(PseventInfo) * maxSlaveProtocolEvent); 

    
    usedSlaveProtocolEvent = 0;
    
    mmi_frm_set_slave_protocol_event_handler(mmi_proc_inject_string, MSG_ID_TST_INJECT_STRING);
}
#endif /* __MMI_DUAL_SIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_interrupt_event_information
 * DESCRIPTION
 *  This function could query interrupt event information.
 * PARAMETERS
 *  eventID      [IN]        interrupt event id
 *  int_func     [OUT]       interrupt event pre handler
 *  post_int_func[OUT]       interrupt event post handler   
 * RETURNS
 *  Return MMI_TURE if find the information slot, otherwise, return MMI_FLASE
 *****************************************************************************/
static MMI_BOOL mmi_frm_query_interrupt_event_information(mmi_frm_int_event_type frm_int_event, interrupt_event_hdlr *int_func, interrupt_event_hdlr *post_int_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We set specific interrupt event as higher priority than general ones */
    for (count = MMI_FRM_INT_EVENT_SPECIFIC; count < MMI_FRM_INT_EVENT_TYPE_NUM; count++)
    {
        if (frm_int_event & mmi_frm_int_mask_hdlr[count].event_mask)
        {
            if (int_func)
            {
                *int_func = mmi_frm_int_mask_hdlr[count].int_func_ptr;
            }
            if (post_int_func)
            {
                *post_int_func = mmi_frm_int_mask_hdlr[count].post_int_func_ptr;
            }
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_frm_int_event_macro
 * DESCRIPTION
 *  This function will get framework interrupt event macro from convert table
 * PARAMETERS
 *  event_id       [IN]       interrupt event id
 *  msg            [IN]       primitive's local parameter
 * RETURNS
 *  Reture framework interrupt event macro
 *****************************************************************************/
static mmi_frm_int_event_type mmi_frm_get_frm_int_event_macro(U16 int_event, const mmi_frm_int_event_convert_struct *int_event_convert_table, U8 table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  count;
    mmi_frm_int_event_type frm_int_event_macro = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < table_size; count++)
    {
        if (int_event_convert_table[count].event_id == int_event)
        {
            frm_int_event_macro = int_event_convert_table[count].int_event_macro;
            break;
        }
    }
    return frm_int_event_macro;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_interrupt_event_converter
 * DESCRIPTION
 *  This function will convert protocol interrupt event to framework interrupt
 *  event macro.
 * PARAMETERS
 *  event_id       [IN]       interrupt event id
 *  msg            [IN]       primitive's local parameter
 * RETURNS
 *  Reture framework interrupt event macro
 *****************************************************************************/
static mmi_frm_int_event_type mmi_frm_interrupt_event_converter(U16 event_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_int_event_type frm_interrupt_event = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event_id)
    {
        case PRT_EQ_GPIO_DETECT_IND:
        {
            mmi_eq_gpio_detect_ind_struct *gpio_detect_ind = (mmi_eq_gpio_detect_ind_struct *)msg;
            switch (gpio_detect_ind->gpio_device)
            {
                case EXT_DEV_CLAM_CLOSE:
                {
                    frm_interrupt_event = MMI_FRM_INT_CLAM_CLOSE;
                    break;
                }
                case EXT_DEV_CLAM_OPEN:
                {
                    frm_interrupt_event = MMI_FRM_INT_CLAM_OPEN;
                    break;
                }
                case EXT_DEV_EARPHONE:
                {
                    if (gpio_detect_ind->on_off == 1)
                    {
                        frm_interrupt_event = MMI_FRM_INT_EARPHONE_PLUG_IN;
                    }
                    else
                    {
                        frm_interrupt_event = MMI_FRM_INT_EARPHONE_PLUG_OUT;
                    }
                    break;
                }
            }
            break;
        }
        case PRT_BATTERY_STATUS_IND:
        {
            mmi_eq_battery_status_ind_struct *battery_status_ind = (mmi_eq_battery_status_ind_struct*)msg;

            frm_interrupt_event = mmi_frm_get_frm_int_event_macro(
                                      battery_status_ind->battery_status,
                                      mmi_frm_int_event_battery_table,
                                      sizeof(mmi_frm_int_event_battery_table) / sizeof(mmi_frm_int_event_battery_table[0]));
            break;
        }
        case MSG_ID_TIMER_EXPIRY:
        case MSG_ID_MMI_EQ_POWER_ON_IND:
        case MSG_ID_MMI_EQ_KEYPAD_DETECT_IND:
        {
            break;
        }
        default:
        {
            frm_interrupt_event = mmi_frm_get_frm_int_event_macro(
                                      event_id, 
                                      mmi_frm_int_event_convert_table,
                                      sizeof(mmi_frm_int_event_convert_table) / sizeof(mmi_frm_int_event_convert_table[0]));
            break;
        }
    }
    return frm_interrupt_event;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_process_non_mmi_task_interrupt
 * DESCRIPTION
 *  This function is an internal one which will set interrupt event handler
 *  into interrupt information table.
 * PARAMETERS
 *  mmi_frm_int_event_type       [IN]       interrupt event
 *  is_set                       [IN]       set non-mmi task popup screen 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_process_non_mmi_task_interrupt(mmi_frm_int_event_type interrupt_event, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mmi_arg = MMI_FALSE;
    kal_bool kal_arg = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_set)
    {
        mmi_arg = MMI_TRUE;
        kal_arg = KAL_TRUE;
    }

    #ifdef __MMI_MMS__
        if (interrupt_event & MMI_FRM_INT_WAP_MMS)
        {
            wap_suppress_popup(kal_arg);
        }        
    #endif /* __MMI_MMS__ */
    #if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
        if (interrupt_event & MMI_FRM_INT_BT_TASK)
        {
            mmi_bt_opp_suppress_popup(mmi_arg);
        }        
    #endif /* defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__) */
    mmi_frm_process_non_mmi_task = is_set;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_block_interrupt_event_int
 * DESCRIPTION
 *  This function is an internal one which will set interrupt event handler
 *  into interrupt information table.
 * PARAMETERS
 *  int_event_p           [IN]       pre interrupt event handler
 *  post_int_event_p      [IN]       post interrupt event handler
 *  interrupt_event       [IN]       framework interrupt event macro
 *  event_type            [IN]       to decide general or specific event  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_block_interrupt_event_int(mmi_frm_int_event_type interrupt_event, interrupt_event_hdlr int_event_p, interrupt_event_hdlr post_int_event_p, U8 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Non-MMI task interruption is not through the protocol event process, so it needs to set flag to 
     * stop popup screen after EntryNewScreen and reset it when exit the screen
     */
    if (interrupt_event & MMI_FRM_INT_NON_MMI_TASK_EVENTS)
    {
        if (int_event_p)
        {
            mmi_frm_process_non_mmi_task_interrupt(interrupt_event, MMI_TRUE);
        }
        else if (!int_event_p && mmi_frm_process_non_mmi_task)  /* if int_event_p is NULL which means user want to clear this handler */
        {
            mmi_frm_process_non_mmi_task_interrupt(interrupt_event, MMI_FALSE);
        }
    }

    /* This action will only register the events and handlers in the last time calling this interface */
    mmi_frm_int_mask_hdlr[event_type].event_mask = interrupt_event;
    mmi_frm_int_mask_hdlr[event_type].int_func_ptr = int_event_p;
    mmi_frm_int_mask_hdlr[event_type].post_int_func_ptr = post_int_event_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_pre_block_interrupt_event_handler
 * DESCRIPTION
 *  This function is an internal one which will block popup screen caused by
 *  interrupt event handler.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro  
 * RETURNS
 *  Return MMI_FALSE to let protocol handler be executed, otherwise, 
 *  return MMI_TRUE.
 *****************************************************************************/
static U8 mmi_frm_pre_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (interrupt_event)
    {
        /* Now the default action is just to stop popup screen for general interrupt event */
        default:
        {
            SetInterruptPopupDisplay(POPUP_ALL_OFF);
            break;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_post_block_interrupt_event_handler
 * DESCRIPTION
 *  This function is an internal one which will reset the flag of popup screen.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro  
 * RETURNS
 *  Return MMI_FALSE always (remain for expansion).
 *****************************************************************************/
static U8 mmi_frm_post_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (interrupt_event)
    {
        /* Now the default action is just to stop popup screen for general interrupt event */
        default:
        {
            SetInterruptPopupDisplay(POPUP_ALL_ON);
            break;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_block_interrupt_event_handler
 * DESCRIPTION
 *  This function will set event handler which could process what application want 
 *  when the interrupt event is blocked by mmi task.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 *  int_event_p           [IN]       pre interrupt event handler
 *  post_int_event_p      [IN]       post interrupt event handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event, interrupt_event_hdlr int_event_p, interrupt_event_hdlr post_int_event_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_BLOCK_INT_HDLR, interrupt_event);
    mmi_frm_block_interrupt_event_int(
        interrupt_event, 
        int_event_p,
        post_int_event_p,
        MMI_FRM_INT_EVENT_SPECIFIC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_block_general_interrupt_event
 * DESCRIPTION
 *  This function could block all the interruptive popup screen when the general
 *  interrupt event is blocked by mmi task.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_block_general_interrupt_event(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_BLOCK_GEN_INT_HDLR, interrupt_event);
    mmi_frm_block_interrupt_event_int(
        interrupt_event,    
        mmi_frm_pre_block_interrupt_event_handler,
        mmi_frm_post_block_interrupt_event_handler,
        MMI_FRM_INT_EVENT_GENERAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_interrupt_event_handler
 * DESCRIPTION
 *  This function could clear the designated interrupt event handler.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_interrupt_event_handler(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRINTP_HDLR, interrupt_event);
    if ((interrupt_event & MMI_FRM_INT_NON_MMI_TASK_EVENTS) && mmi_frm_process_non_mmi_task)
    {
        mmi_frm_process_non_mmi_task_interrupt(interrupt_event, MMI_FALSE);
    }

    for (count = MMI_FRM_INT_EVENT_SPECIFIC; count < MMI_FRM_INT_EVENT_TYPE_NUM; count++)
    {
        if (interrupt_event & mmi_frm_int_mask_hdlr[count].event_mask)
        {
            mmi_frm_int_mask_hdlr[count].event_mask &= ~interrupt_event;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_interrupt_event_handler
 * DESCRIPTION
 *  This function could clear all the interrupt event handler.
 * PARAMETERS
 *  interrupt_event       [IN]       framework interrupt event macro
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_interrupt_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRALLINTP_HDLR);

    memset(mmi_frm_int_mask_hdlr, 0, sizeof(mmi_frm_int_mask_hdlr));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_interrupt_event_context
 * DESCRIPTION
 *  This function could reset interrupt event context and clear all interrupt
 *  event handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_reset_interrupt_event_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Non-MMI task interruption is not through the protocol event process, so it needs to set flag to 
     * stop popup screen after EntryNewScreen and reset it when exit the screen
     */    
    if (mmi_frm_process_non_mmi_task)
    {
        #ifdef __MMI_MMS__
        if (mmi_frm_query_interrupt_event_information(MMI_FRM_INT_WAP_MMS, NULL, NULL))
        {
            wap_suppress_popup(KAL_FALSE);
        }
        #endif /* __MMI_MMS__ */
        #if defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__)
        if (mmi_frm_query_interrupt_event_information(MMI_FRM_INT_BT_TASK, NULL, NULL))
        {
            mmi_bt_opp_suppress_popup(MMI_FALSE);
        }
        #endif /* defined(__MMI_OPP_SUPPORT__) && defined(__MMI_BT_MTK_SUPPORT__) */
        mmi_frm_process_non_mmi_task = MMI_FALSE;
    }

    mmi_frm_clear_all_interrupt_event_handler();
}


#ifdef MMI_FRM_BACKWARD_COMPATIBLE_EVENTS
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_interrupt_group_table
 * DESCRIPTION
 *  search interrupt group event id is in interrupt
 *  group table and get the index
 * PARAMETERS
 *  eventID     [IN]     Unique Protocol/System EventID.   
 *  index       [OUT]    The index in the interrupt group table. If not find the
 *                       index is -1.
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_is_interrupt_group_table(U16 event_id, int *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(interruptGroupEventTable) / sizeof(InterruptGroupInfo); i++)
    {
        if (interruptGroupEventTable[i].groupID == event_id)
        {
            *index = i;
            return MMI_TRUE;
        }
    }

    *index = -1;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_interrupt_handler
 * DESCRIPTION
 *  query interrupt event handler
 * PARAMETERS
 *  eventID         [IN]   Unique Protocol/System EventID.      
 *  funcPtr         [OUT]  Function to be executed when receiving the interrupt event.     
 *  postfuncPtr     [OUT]  Function to be executed after receiving the interrupt event       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_query_interrupt_handler(U16 event_id, PsIntFuncPtr *func_ptr, PsIntFuncPtr *post_func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_INTERRUPT_EVENT; i++)
    {
        if (!IS_INTERRUPT_EVENT_GROUP(interruptEventHandler[i].eventID))
        {
            /* General interrupt event */
            if (interruptEventHandler[i].eventID == event_id)
            {
                goto is_found;
            }
        }
        else
        {
            if (mmi_frm_is_interrupt_group_table(interruptEventHandler[i].eventID, &index))
            {
                /* Interrupt group event */
                j = 0;
                while (interruptGroupEventTable[index].eventID[j] != 0)
                {
                    if (interruptGroupEventTable[index].eventID[j] == event_id)
                    {
                        goto is_found;
                    }
                    j++;

                    MMI_ASSERT(j < INTERRUPT_EVENT_GREOUP_SIZE);
                }
            }
        }
    
}
    return MMI_FALSE;

  is_found:
    *func_ptr = (PsIntFuncPtr) interruptEventHandler[i].entryIntFuncPtr;
    *post_func_ptr = (PsIntFuncPtr) interruptEventHandler[i].postIntFuncPtr;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_interrupt_event_handler
 * DESCRIPTION
 *  This function is used for register the interrupt event handler. Whenever 
 *  an event is received from the protocol corresponding function is executed.
 *  If the interrupt event handlers are registered, MMI framework  executes 
 *  the functions as follow order: Inpterrupt Event Handler, Protocol Event 
 *  Handler, Post Interrupt Event Handler.
 * PARAMETERS
 *  funcPtr         [IN] Function to be executed when receiving the interrupt event.       
 *  postfuncPtr     [IN] Function to be executed after receiving the interrupt event.       
 *  eventID         [IN] Unique Protocol/System EventID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_interrupt_event_handler(PsIntFuncPtr func_ptr, PsIntFuncPtr post_func_ptr, U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0;
    pBOOL isNewEvent = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETINTP_HDLR, event_id);

    if (!IS_INTERRUPT_EVENT_GROUP(event_id))
    {
        /* General interrupt event will allocate from the begin */
        for (count = 0; count < maxInterruptEvent; count++)
        {
            if (interruptEventHandler[count].eventID == event_id)
            {
                isNewEvent = FALSE;
                break;
            }
            if (interruptEventHandler[count].eventID == 0)
            {
                break;
            }
        }
    }
    else
    {
        /* Interrupt group event will allocate from the end */
        for (count = MAX_INTERRUPT_EVENT - 1; count >= 0; count--)
        {
            if (interruptEventHandler[count].eventID == event_id)
            {
                isNewEvent = FALSE;
                break;
            }
            if (interruptEventHandler[count].eventID == 0)
            {
                break;
            }
        }
    }

    if (isNewEvent)
    {
        maxInterruptEvent++;
        MMI_ASSERT(maxInterruptEvent < MAX_INTERRUPT_EVENT);
    }

    interruptEventHandler[count].eventID = event_id;
    interruptEventHandler[count].entryIntFuncPtr = func_ptr;
    interruptEventHandler[count].postIntFuncPtr = post_func_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_group_interrupt_event_handler
 * DESCRIPTION
 *  This function is used for register the group interrupt event handlers. 
 *  If the interrupt event handlers are registered, MMI framework  executes 
 *  the functions as follow order: InpterruptFuncPtr, ProtocolFuncPtr, 
 *  InterruptPostfuncPtr.
 * PARAMETERS
 *  funcPtr         [IN] Function to be executed when receiving the interrupt event.       
 *  postfuncPtr     [IN] Function to be executed after receiving the interrupt event.       
 *  eventsID        [IN] Unique Protocol/System EventID array.       
 *  len             [IN] The EventsID array size.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_group_interrupt_event_handler(PsIntFuncPtr func_ptr, PsIntFuncPtr post_func_ptr, PU16 events_id, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < len; count++)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_SETGRPINTP_HDLR, events_id[count]);
        mmi_frm_set_interrupt_event_handler(func_ptr, post_func_ptr, events_id[count]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_interrupt_event_handler_old
 * DESCRIPTION
 *  This is used to clear interrupt event handler
 * PARAMETERS
 *  eventID     [IN] Clear the handler of event ID.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_interrupt_event_handler_old(U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRINTP_HDLR, event_id);
    mmi_frm_set_interrupt_event_handler(NULL, NULL, event_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_interrupt_event_handler_old
 * DESCRIPTION
 *  This is used to clear all the interrupt event handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_interrupt_event_handler_old(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_INFO_EVENT_CLRALLINTP_HDLR);

    memset(interruptEventHandler, 0, sizeof(PsInteventInfo)*maxInterruptEvent);

    maxInterruptEvent = 0;
}
#endif /*MMI_FRM_BACKWARD_COMPATIBLE_EVENTS*/

