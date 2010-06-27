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
 * EventsGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Events gprot.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _EVENTSGPROT_H
#define _EVENTSGPROT_H

#include "Frameworkstruct.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "MMITimer.h"
#include "KeyBrd.h"
#include "EventsDef.h"
#include "FrameworkBackwardCompatible.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define IsBitSet(Word, bit)      ((Word) & (1<<(bit)))
#define IsBitReset(Word, bit)    (!((Word) & (1<<(bit))))
#define SetBit(Word, bit)        (Word)|=(1<<(bit))
#define ResetBit(Word, bit)      (Word) &= ~(1<<(bit))

#define MMI_INT_EVENT_GROUP_MASK (0x8000)

#define MMI_DEVICE_KEY 0x0001
#define MMI_DEVICE_PEN 0x0002
#define MMI_DEVICE_ALL (MMI_DEVICE_KEY | MMI_DEVICE_PEN)

#define MMI_FULL_SCREEN     ((void*)1)   /* identify full-screen APP in EntryNewScreen() */
#define MMI_SMALL_SCREEN    ((void*)2)   /* *RESERVED* identify small-screen APP in EntryNewScreen() */
#define MMI_TAB_PAGE        ((void*)3)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/*
 * If we want to add the new interrupt event group,
 * define the new interrupt event group id here.
 */
typedef enum
{
    MMI_SMS_INT_EVENT_GROUP = MMI_INT_EVENT_GROUP_MASK,
    MMI_CARD_PLUG_EVENT_GROUP
} interrtupGroupEventId;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern PU8 hintDataPtrs[MAX_SUB_MENUS];

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void InitEvents(void);                           /* initilize events func */
extern U8 EntryNewScreen(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *flag);        /* execute current entry func handler */
extern U8 EntryNewScreen_Ext(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *peerBuf);    /* execute current entry func handler without clear all keyhandler */
extern void ExecuteCurrExitHandler(void);
extern void ExecuteCurrExitHandler_Ext(void);
extern void ReplaceNewScreenHandler(U16 scrnID, FuncPtr exitFuncPtr, FuncPtr entryFuncPtr);     /* execute replace current screen screen id, exit and entry func handler */
extern U16 GetActiveScreenId(void);                     /*  Get current active screen ID */
extern void ExecuteCurrHiliteHandler(S32 hiliteid);     /*  execute current hilite handler with arrow key clear */
extern void ExecuteCurrHiliteHandler_Ext(S32 hiliteid); /*  execute current hilite handler without any key clear */
extern void ClearInputEventHandler(U16 device);
extern void SetEntryHandler(U16 scrnID, FuncPtr entryFuncPtr);  /* entry function handler */
extern void ClearEntryHandler(void);
extern U16 GetExitScrnID(void);
extern U16 GetExitScrnID_r(void);
extern void ClearExitHandler(void);
extern void SetHiliteHandler(U16 itemid, FuncPtr hiliteFuncPtr);        /*  set hilite handler & parent id */
extern void ClearHiliteHandler(U16 itemid);
extern void ClearAllHiliteHandler(void);
extern void SetParentHandler(U16 parentid);

/* MTK Brian added for AT+CVIB, 2003/11/23 */
extern U16 GetParentHandler(void);

/* lisen 03/27/2004 */
extern void DeInitFramework_KeyAndEventHandler(void);
extern void DeInitFramework_History(void);
extern void DeInitFramework(void);
extern U8 MaskItems(U16 *maskList, U8 noOfItems, U32 maskingWord);
extern U8 MaskItemsU8(U8 *maskList, U8 noOfItems, U32 maskingWord);
extern U8 MaskStringItems(U8 **maskList, U8 noOfItems, U32 maskingWord);
extern U8 MaskHiliteItems(U16 currParentID, U32 maskingWord);
extern U16 GetCurrHiliteID(void);
extern void ConstructHintsList(U16 currParentID, U8 **hintArray);
extern void SetHintHandler(U16 itemid, FuncPtrShort hintFuncPtr);
extern void ClearHintHandler(U16 itemid);
extern void GenericExitInlineScreen(U16 scrnID, FuncPtr entryFuncPtr);
extern void GenericExitScreen(U16 scrnID, FuncPtr entryFuncPtr);

#define ExecuteCurrProtocolHandler  \
        mmi_frm_execute_current_protocol_handler
//#define SetProtocolEventHandler   
 //       mmi_frm_set_protocol_event_handler
#define ClearProtocolEventHandler   \
        mmi_frm_clear_protocol_event_handler
#define ClearAllProtocolEventHandler    \
        mmi_frm_clear_all_protocol_event_handler
        
#ifdef __MMI_DUAL_SIM__
#define SetSlaveProtocolEventHandler   \
        mmi_frm_set_slave_protocol_event_handler
#define ClearSlaveProtocolEventHandler   \
        mmi_frm_clear_slave_protocol_event_handler
#define ClearSlaveAllProtocolEventHandler    \
        mmi_frm_clear_all_slave_protocol_event_handler
#endif /* #ifdef __MMI_DUAL_SIM__ */
        
extern void mmi_frm_execute_current_protocol_handler(U16 eventID, void *MsgStruct, int mod_src, void *peerBuf);       /* execute current protocol func handler */
extern void SetProtocolEventHandler(PsFuncPtr funcPtr, U16 eventID);
extern void mmi_frm_set_protocol_event_handler(PsFuncPtr funcPtr, U16 eventID);
extern void mmi_frm_clear_protocol_event_handler(U16 eventID);
extern void mmi_frm_clear_all_protocol_event_handler(void);
#ifdef __MMI_DUAL_SIM__
extern void mmi_frm_set_slave_protocol_event_handler(PsFuncPtr funcPtr, U16 eventID);
extern void mmi_frm_clear_slave_protocol_event_handler(U16 eventID);
extern void mmi_frm_clear_all_slave_protocol_event_handler(void);
#endif /* #ifdef __MMI_DUAL_SIM__ */


/* New interrupt api */
extern void mmi_frm_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event, interrupt_event_hdlr int_event_p, interrupt_event_hdlr post_int_event_p);
extern void mmi_frm_block_general_interrupt_event(mmi_frm_int_event_type interrupt_event);
extern void mmi_frm_reset_interrupt_event_context(void);
extern void mmi_frm_clear_interrupt_event_handler(mmi_frm_int_event_type interrupt_event);
extern void mmi_frm_clear_all_interrupt_event_handler(void);


extern void SetCurrExitFuncPtr(FuncPtr ptr);
extern FuncPtr GetCurrExitFuncPtr(void);
extern void SetCurrEntryFuncPtr(FuncPtr ptr);
extern FuncPtr GetCurrEntryFuncPtr(void);
extern MMI_BOOL mmi_execute_scrn_exit_func(void);

extern void ExecuteItemHiliteHandler(U16 hiliteItemID);

#endif /* _EVENTSGPROT_H */ 

