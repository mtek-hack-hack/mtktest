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
 * CallsHistoryMain.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : CallsHistoryMain.c

   PURPOSE     : Call history main screen

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru 

   DATE     : 10/22/2003

**************************************************************/

#include "MMI_include.h"
#ifndef _CALLS_HISTORY_MAIN_C
#define _CALLS_HISTORY_MAIN_C

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "CSP.h"

#include "MessagesExDcl.h"
#include "CallManagementStruct.h"
#include "PhoneBookTypes.h"

#include "CallHistoryEnum.h"
#include "CallsDefs.h"
#include "CallsStruct.h"
#include "CallHistoryMain.h"
#include "CallsLog.h"
#include "CallsReset.h"
#include "CallsSMSCounter.h"
#include "CallTimes.h"
/* micha1020 */
#include "ProtocolEvents.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#endif/*__MMI_DUAL_SIM_MASTER__*/
#ifdef __MMI_GPRS_FEATURES__
#include "CommonScreens.h"
U32 gprsTotalSent = 0;
U32 gprsTotalReceived = 0;
U32 gprsLastSent = 0;
U32 gprsLastReceived = 0;

// #define __MMI_GPRS_UNIT_TEST__

#endif /* __MMI_GPRS_FEATURES__ */ 

static call_history_context_struct g_CallHistory_cntxt;
call_history_context_struct *chis_p = &g_CallHistory_cntxt;


/*****************************************************************************
 * FUNCTION
 *  InitCallHistory
 * DESCRIPTION
 *  Init sub modules of call history application
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialization of callsreset submodule  */
    InitCallsReset();
    /* initialization of smscounters submodule */
    InitSMSCounter();
    /* initialization of calltimes submodule */
    InitCallTimes();

#ifdef __MMI_GPRS_FEATURES__
    InitGPRSCounter();
#endif 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  InitCallHistoryContext
 * DESCRIPTION
 *  Init call history context
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallHistoryContext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((U8*) chis_p, 0, sizeof(call_history_context_struct));
    ReadRecord(NVRAM_EF_CALL_TIME_LID, 1, (void*)&chis_p->last_call_time, sizeof(MYTIME), &error);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 2, (void*)&chis_p->total_out_time, sizeof(MYTIME), &error);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 3, (void*)&chis_p->total_in_time, sizeof(MYTIME), &error);

}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTMainMenu
 * DESCRIPTION
 *  Main screen of call history
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    // U16                  nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;                          /* Buffer holding history data */
    U16 nStrItemList[MAX_SUB_MENUS];        /* Stores the strings id of submenus returned */
    U16 nNumofItem;                         /* Stores no of children in the submenu */
    U16 ItemIcons[MAX_SUB_MENUS];
    U8 *PopUpList[MAX_SUB_MENUS];
    U16 LSKStr;
    U16 LSKImg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* S32       maskingByte=-1;
       S32               menuItemId=-1; */

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */

    /* Call Exit Handler */
#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    EntryNewScreen(SCR_CALL_HISTORY_MAIN_MENU, wgui_restore_list_menu_slim_style, EntryCHISTMainMenu, NULL);
#else 
    EntryNewScreen(SCR_CALL_HISTORY_MAIN_MENU, NULL, EntryCHISTMainMenu, NULL);
#endif 

    /* reset the indicies for dialed/recived/missed call list menus */
    chis_p->currRecvdCallIndex = 0;
    chis_p->currMissedCallIndex = 0;
    chis_p->currDialedCallIndex = 0;

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CALL_HISTORY_MAIN_MENU);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild_Ext(MAIN_MENU_CALL_HISTORY); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MAIN_MENU_CALL_HISTORY ); */
    /* Retrieve string/image ids in sequence of given menu item to be displayed */
    GetSequenceStringIds_Ext(MAIN_MENU_CALL_HISTORY, nStrItemList);     /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceImageIds_Ext(MAIN_MENU_CALL_HISTORY, ItemIcons); /* diamond, 2005/07/01 add _Ext to menu item functions */
    /* Set current parent id */
    SetParentHandler(MAIN_MENU_CALL_HISTORY);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* diamond, 2005/07/01 removed for new menu item architecture to CPHS */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /* construct hint popup strings for menu items */
    ConstructHintsList(MAIN_MENU_CALL_HISTORY, PopUpList);

#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
#endif 

    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_CALL_HISTORY);
#endif 
    /* MTK Leo end */

    /* There may be no menu items in call log */
    if (nNumofItem == 0)
    {
        LSKStr = 0;
        LSKImg = 0;
    }
    else
    {
        LSKStr = STR_GLOBAL_OK;
        LSKImg = IMG_GLOBAL_OK;        
    }
    /* Display the call history main screen */
    ShowCategory52Screen(
    #ifdef __MMI_DUAL_SIM_MASTER__
        STRING_MTPNP_CARD1_CALL_HISTORY,
    #else /* __MMI_DUAL_SIM_MASTER__ */
        STR_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        IMG_SCR_CALL_HISTORY_MAIN_MENU_CAPTION,
        LSKStr,
        LSKImg,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        ItemIcons,
        (U8 **)PopUpList,
        0,
        0,  /* u16callhist_curindex, */
        guiBuffer);

    /* Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_GPRS_FEATURES__


/*****************************************************************************
 * FUNCTION
 *  InitGPRSCounter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitGPRSCounter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_CALL_HISTORY_GPRSCOUNTER, HighlightGPRSCount);
    SetHiliteHandler(MENU_CALL_HISTORY_GPRS_LASTSENT, HighlightGPRSCountLastSent);
    SetHiliteHandler(MENU_CALL_HISTORY_GPRS_LASTRECEIVED, HighlightGPRSCountLastRecieved);
    SetHiliteHandler(MENU_CALL_HISTORY_GPRS_ALLSENT, HighlightGPRSCountAllSent);
    SetHiliteHandler(MENU_CALL_HISTORY_GPRS_ALLRECEIVED, HighlightGPRSCountAllReceived);
    SetHiliteHandler(MENU_CALL_HISTORY_GPRS_RESETCOUNTER, HighlightGPRSCountCounterReset);

    SetHintHandler(MENU_CALL_HISTORY_GPRS_LASTSENT, HintGPRSCountLastSent);
    SetHintHandler(MENU_CALL_HISTORY_GPRS_LASTRECEIVED, HintGPRSCountLastRecieved);
    SetHintHandler(MENU_CALL_HISTORY_GPRS_ALLSENT, HintGPRSCountAllSent);
    SetHintHandler(MENU_CALL_HISTORY_GPRS_ALLRECEIVED, HintGPRSCountAllReceived);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSCount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_UNIT_TEST__

    gprsTotalSent = 0;
    gprsTotalReceived = 1025;
    gprsLastSent = 1048533;
    gprsLastReceived = 11048576;
    SetKeyHandler(EntryScrGPRSCounter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryScrGPRSCounter, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#else /* __MMI_GPRS_UNIT_TEST__ */ 

    SetKeyHandler(GetGPRSCountersRequest, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(GetGPRSCountersRequest, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#endif /* __MMI_GPRS_UNIT_TEST__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSCountLastSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSCountLastSent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSCountLastRecieved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSCountLastRecieved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSCountAllSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSCountAllSent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSCountAllReceived
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSCountAllReceived(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightGPRSCountCounterReset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightGPRSCountCounterReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gprsTotalSent == 0 &&
        gprsTotalReceived == 0 &&
        gprsLastSent ==   0 &&
        gprsLastReceived == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(EntryScrGPRSRecvCounterResetConfirmation, KEY_EVENT_UP);
    }
}

/* micha0202 begin */


/*****************************************************************************
 * FUNCTION
 *  HintGPRSCountLastSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintGPRSCountLastSent(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gprsLastSent);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintGPRSCountLastRecieved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintGPRSCountLastRecieved(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gprsLastReceived);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintGPRSCountAllSent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintGPRSCountAllSent(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gprsTotalSent);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintGPRSCountAllReceived
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintGPRSCountAllReceived(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    /* micha0216 */
    sprintf((S8*) value, "%d B", gprsTotalReceived);
    mmi_asc_to_ucs2((PS8) hintData[(index)], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  GetGPRSCountersRequest
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GetGPRSCountersRequest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    /* micha1020 */
    SetProtocolEventHandler(GetGPRSCountersResponse, PRT_MMI_PS_GET_GPRS_DATA_COUNTER_RSP);
    /* format message to send req for get plmn list */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha1020 */
    Message.oslMsgId = PRT_MMI_PS_GET_GPRS_DATA_COUNTER_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    return;
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetGPRSCountersResponse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void GetGPRSCountersResponse(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__
    mmi_ps_get_gprs_data_counter_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_get_gprs_data_counter_rsp_struct*) info;

    if (localPtr->result == MMI_TRUE)
    {
        gprsTotalSent = localPtr->counter_info.total_tx_data;
        gprsTotalReceived = localPtr->counter_info.total_rx_data;
        gprsLastSent = localPtr->counter_info.last_tx_data;
        gprsLastReceived = localPtr->counter_info.last_rx_data;
    }
    else
    {
        gprsTotalSent = 0;
        gprsTotalReceived = 0;
        gprsLastSent = 0;
        gprsLastReceived = 0;
    }

    EntryScrGPRSCounter();
#endif /* __MMI_GPRS_FEATURES__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrGPRSRecvCounterResetConfirmation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrGPRSRecvCounterResetConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GPRS_RESET_COUNTER_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* Set the left/right soft key funtions */
    SetLeftSoftkeyFunction(ResetGPRSCounterReq, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* set the exit handler for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ResetGPRSCounterReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetGPRSCounterReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_UNIT_TEST__

    gprsTotalSent = 0;
    gprsTotalReceived = 0;
    gprsLastSent = 0;
    gprsLastReceived = 0;
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR8004_GPRS_COUNTER);

#else /* __MMI_GPRS_UNIT_TEST__ */ 

    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__

    MYQUEUE Message;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    /* micha1020 */
    SetProtocolEventHandler(ResetGPRSCounterRsp, PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_RSP);
    /* format message to send req for get plmn list */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    /* micha1020 */
    Message.oslMsgId = PRT_MMI_PS_RESET_GPRS_DATA_COUNTER_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

#endif /* __MMI_GPRS_FEATURES__ */ 

#endif /* __MMI_GPRS_UNIT_TEST__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  ResetGPRSCounterRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ResetGPRSCounterRsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* micha1020 */
#ifdef __MMI_GPRS_FEATURES__

    mmi_ps_reset_gprs_data_counter_rsp_struct *localPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    localPtr = (mmi_ps_reset_gprs_data_counter_rsp_struct*) info;

    if (localPtr->result == MMI_TRUE)
    {
        gprsTotalSent = 0;
        gprsTotalReceived = 0;
        gprsLastSent = 0;
        gprsLastReceived = 0;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_NOT_DONE), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    DeleteScreenIfPresent(SCR_CONFIRM_SCREEN);
    return;

#endif /* __MMI_GPRS_FEATURES__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  EntryScrGPRSCounter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrGPRSCounter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    // U16                  nDispAttribute; /* Stores display attribue */
    U8 *u8GPRSCount[MAX_SUB_MENUS];         /* sms counters for display hint popups */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR8004_GPRS_COUNTER, NULL, EntryScrGPRSCounter, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR8004_GPRS_COUNTER);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CALL_HISTORY_GPRSCOUNTER);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MENU_CALL_HISTORY_GPRSCOUNTER ); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CALL_HISTORY_GPRSCOUNTER, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_CALL_HISTORY_GPRSCOUNTER);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* construct hint popups for the menu items */
    ConstructHintsList(MENU_CALL_HISTORY_GPRSCOUNTER, u8GPRSCount);
    /* Display Category52 Screen */
    ShowCategory52Screen(
        STR_GPRS_CAPTION,
        IMG_SCR8056_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        u8GPRSCount,
        0,
        0,
        guiBuffer);
    /* Register left arrow key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* Register function with left/right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#endif /* __MMI_GPRS_FEATURES__ */ 
#endif /* _CALLS_HISTORY_MAIN_C */ 

