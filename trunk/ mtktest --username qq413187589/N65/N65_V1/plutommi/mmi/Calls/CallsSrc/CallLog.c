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
 * CallLog.C
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
  * Dec 16 2005 mtk00418
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
 *
 *
 * removed!
 * removed!
 *
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

   FILENAME : CallsLog.c

   PURPOSE     : Call Setting Application

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 10/22/2003

**************************************************************/

#include "MMI_include.h"
#ifndef _CALL_LOG_C
#define _CALL_LOG_C

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "wgui_datetime.h"
#include "ProtocolEvents.h"
#include "IdleAppProt.h"
#include "IdleAppDef.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "AlarmProt.h"
#include "AlarmFrameworkProt.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
#include "app_datetime.h"


#include "MainMenuDef.h"
#include "ShortcutsDefs.h"
#include "CallManagementStruct.h"
#include "CallManagementGprot.h"
#include "PhoneBookDef.h"
#include "PhoneBookTypes.h"
#include "PhoneBookGProt.h"
#include "PhoneBookProt.h"

#include "CallHistoryMain.h"
#include "CallHistoryEnum.h"
#include "CallHistoryGProts.h"
#include "CallsStruct.h"
#include "CallsLog.h"
#include "CallsReset.h"
#include "CallmanagementIdDef.h"        /* for ERROR_UNRECOGNIZED_NUMBER */
#include "GSM7BitDefaultAlphabet.h"

#ifdef __MMI_CH_OPTIONS_SENDSMS__
#include "MessagesMiscell.h"                 /* for IsMessagesReEntering */
#include "MessagesResourceData.h"       /* for STR_SMS_MSG_NOT_READY_YET */
#include "MessagesExDcl.h"			/* for MMI_SEND_SMS_FROM_PHB */
#include "SMSApi.h"
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
#include "Wapadp.h"				/* mms_address_insert_hdlr */
#endif /*__MMI_CH_OPTIONS_SENDMMS__*/

#if  defined(__MMI_CH_OPTIONS_SENDSMS__) || defined(__MMI_CH_OPTIONS_SENDMMS__)
#include "SimDetectionGProt.h"
#endif

#ifdef __IP_NUMBER__
#include "CallStructureManagementProt.h"
#endif

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif

#if defined(__MMI_UCM__)
#include "UCMGprot.h"
#endif

#if defined (__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_AD_master_header.h"
#include "MTPNP_PFAL_CC.h"
#include "MTPNP_AD_resdef.h"
#include "MTPNP_PFAL_Master_CallHistory.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Gemini_CallHistory.h"
#endif	/* __MMI_DUAL_SIM_SINGLE_CALL__ */

#ifdef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
#include "MTPNP_AD_slave_header.h"
#include "MTPNP_PFAL_Slave_CallHistory.h"
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

/*
 * Local Variable
 */
#ifdef __MMI_DUAL_SIM_MASTER__
#define CHIST_MSG_LENGTH 60
U8 CHISTMsgStr[CHIST_MSG_LENGTH];
U8 CHISTMsgStr2[CHIST_MSG_LENGTH];
#else /* __MMI_DUAL_SIM_MASTER__ */
U8 CHISTMsgStr[40];
#endif /* __MMI_DUAL_SIM_MASTER__ */
U8 addToHistory = 1;
U8 nMissedCallNumBkp;
U8 g_chist_have_missed_call = 0;

/*
 * Global Function
 */
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
void MTPNP_PFAL_CallHistory_ReadyIndication(void *info);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */

 #ifdef __GEMINI__
extern kal_bool is_sim_replaced(kal_uint8 simInterface);
#else /* __GEMINI__ */
extern kal_bool is_sim_replaced(void);
#endif /* __GEMINI__ */
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
S32 call_log_on_idle = 0;


/*****************************************************************************
 * FUNCTION
 *  SetCHISTTabPaneIdleScreen
 * DESCRIPTION
 *  Set tab pane function for call history in tab pane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCHISTTabPaneIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;

#ifdef __MMI_CH_MIXED_CALL_LOG__
    U16 ImageItemList[] = 
    {
        TAB_MIXED_CALLS,
        TAB_MISSED_CALLS,
        TAB_RECIEVED_CALLS,
        TAB_DIALED_CALLS
    };
#else /* __MMI_CH_MIXED_CALL_LOG__ */ 
    U16 ImageItemList[] = 
    {
        TAB_MISSED_CALLS,
        TAB_RECIEVED_CALLS,
        TAB_DIALED_CALLS
    };
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nNumofItem = GetNumOfChild(IDLE_SCREEN_CALL_HISTORY_SEND);
    GetSequenceStringIds(IDLE_SCREEN_CALL_HISTORY_SEND, nStrItemList);

    SetParentHandler(IDLE_SCREEN_CALL_HISTORY_SEND);
    register_tab_pane_hilite_handler(ExecuteCurrHiliteHandler);
    set_tab_pane(nNumofItem, nStrItemList, ImageItemList, 0);
}


/*****************************************************************************
 * FUNCTION
 *  SetDataCHISTTabPaneIdleScreen
 * DESCRIPTION
 *  Set data function for call history in tab pane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetDataCHISTTabPaneIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_log_on_idle = 1;
}


/*****************************************************************************
 * FUNCTION
 *  ResetDataCHISTTabPaneIdleScreen
 * DESCRIPTION
 *  Reset data function for call history in tab pane
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetDataCHISTTabPaneIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_log_on_idle = 0;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTTabPaneIdleScreen
 * DESCRIPTION
 *  Entry Screen for IDLE_SCREEN_CALL_HISTORY_SEND Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTTabPaneIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isReqSent == TRUE)
    {
        return;
    }
    if (chis_p->isCallLogReady == TRUE && chis_p->isFirstTime == FALSE)
    {
        if (chis_p->process == CALL_LOG_PROC_WRITE)
        {
            PRINT_INFORMATION("still writing, wait till write complete then read!!!!");
            chis_p->process = CALL_LOG_PROC_SYNC;
            return;
        }
        chis_p->currRecvdCallIndex = 0;
        chis_p->currMissedCallIndex = 0;
        chis_p->currDialedCallIndex = 0;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        chis_p->currMixedCallIndex = 0;
    #endif 
        register_set_tab_pane_callback(
            SetCHISTTabPaneIdleScreen,
            SetDataCHISTTabPaneIdleScreen,
            ResetDataCHISTTabPaneIdleScreen);
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        show_category_four_icon_tab_pane();
    #else 
        show_category_three_icon_tab_pane();
    #endif 
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8057_CAPTION,
            IMG_SCR8057_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTMixedCalls
 * DESCRIPTION
 *  Hilite Handler for Mixed Call logs menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTMixedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* SetKeyHandler( CHISTGetCallLogBySENDKey,KEY_RIGHT_ARROW, KEY_EVENT_DOWN ); */
    /* 1 Change left soft key icon and label */
    disable_tab_pane_keys();
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTGetCallLogBySENDKey, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 


/*****************************************************************************
 * FUNCTION
 *  InitCallLogs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallLogs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_DUAL_CALL_SLAVE__
    SetProtocolEventHandler(ReadyLogIndication, PRT_MMI_PHB_LAST_NUMBER_READY_IND);
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    /* SetHiliteHandler( IDLE_SCREEN_CALL_HISTORY_SEND, HighlightCHISTIdleScreen ); */
    SetHiliteHandler(MENU8100_MIXED_CALLS, HighlightCHISTMixedCalls);
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    SetHiliteHandler(MENU8101_RECEIVED_CALLS, HighlightCHISTRecvdCalls);
    SetHiliteHandler(MENU8102_DIALED_CALLS, HighlightCHISTDialedCalls);
    SetHiliteHandler(MENU8103_MISSED_CALLS, HighlightCHISTMissedCalls);
    SetHiliteHandler(RECEIVED_CALL_MENU_CALL, HighlightCHISTCallRecvdNum);
    SetHiliteHandler(RECEIVED_CALL_MENU_SAVE, HighlightCHISTSaveRecvdNum);
    SetHiliteHandler(RECEIVED_CALL_MENU_DELETE, HighlightCHISTDeleteRecvdNum);
    SetHiliteHandler(RECEIVED_CALL_MENU_EDIT, HighlightCHISTEditRecvdNum);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
    SetHiliteHandler(RECEIVED_CALL_MENU_SENDSMS, HighlightCHISTSendSMSRecvdNum);
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
    SetHiliteHandler(RECEIVED_CALL_MENU_SENDMMS, HighlightCHISTSendMMSRecvdNum);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */
    SetHiliteHandler(DIALED_CALL_MENU_CALL, HighlightCHISTCallDialedNum);
    SetHiliteHandler(DIALED_CALL_MENU_SAVE, HighlightCHISTSaveDialedNum);
    SetHiliteHandler(DIALED_CALL_MENU_DELETE, HighlightCHISTDeleteDialedNum);
    SetHiliteHandler(DIALED_CALL_MENU_EDIT, HighlightCHISTEditDialedNum);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
    SetHiliteHandler(DIALED_CALL_MENU_SENDSMS, HighlightCHISTSendSMSDialedNum);
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
    SetHiliteHandler(DIALED_CALL_MENU_SENDMMS, HighlightCHISTSendMMSDialedNum);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */
    SetHiliteHandler(MISSED_CALL_MENU_CALL, HighlightCHISTCallMissedNum);
    SetHiliteHandler(MISSED_CALL_MENU_SAVE, HighlightCHISTSaveMissedNum);
    SetHiliteHandler(MISSED_CALL_MENU_DELETE, HighlightCHISTDeleteMissedNum);
    SetHiliteHandler(MISSED_CALL_MENU_EDIT, HighlightCHISTEditMissedNum);
#ifdef __MMI_CH_OPTIONS_SENDSMS__
    SetHiliteHandler(MISSED_CALL_MENU_SENDSMS, HighlightCHISTSendSMSMissedNum);
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */
#ifdef __MMI_CH_OPTIONS_SENDMMS__
    SetHiliteHandler(MISSED_CALL_MENU_SENDMMS, HighlightCHISTSendMMSMissedNum);
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    SetHiliteHandler(RECEIVED_CALL_MENU_INFO, HighlightCHISTInfoRecvdNum);
    SetHiliteHandler(DIALED_CALL_MENU_INFO, HighlightCHISTInfoDialedNum);
    SetHiliteHandler(MISSED_CALL_MENU_INFO, HighlightCHISTInfoMissedNum);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    SetHintHandler(MENU8101_RECEIVED_CALLS, HintCHISTRecvdCalls);
    SetHintHandler(MENU8102_DIALED_CALLS, HintCHISTDialedCalls);
    SetHintHandler(MENU8103_MISSED_CALLS, HintCHISTMissedCalls);
    InitCallHistoryContext();
#else	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */
    SetProtocolEventHandler(MTPNP_PFAL_CallHistory_ReadyIndication, PRT_MMI_PHB_LAST_NUMBER_READY_IND);
#endif	/* __MMI_DUAL_SIM_DUAL_CALL_SLAVE__ */

#if defined(__MMI_DUAL_SIM_SINGLE_CALL__)
    SetSlaveProtocolEventHandler(MTPNP_PFAL_CallHistory_ReadyIndication, PRT_MMI_PHB_LAST_NUMBER_READY_IND);
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDialedCalls
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDialedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->isMixedStyle = FALSE;
#endif 
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    if (!call_log_on_idle)
#endif 
    {
        SetKeyHandler(ReqReadDialedNumByKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    else
    {
        disable_tab_pane_keys();
    }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(ReqReadDialedNumByKey, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTMissedCalls
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTMissedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->isMixedStyle = FALSE;
#endif 
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    if (!call_log_on_idle)
#endif 
    {
        SetKeyHandler(ReqReadMissedNumByKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    else
    {
        disable_tab_pane_keys();
    }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(ReqReadMissedNumByKey, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTRecvdCalls
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTRecvdCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->isMixedStyle = FALSE;
#endif 
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    if (!call_log_on_idle)
#endif 
    {
        SetKeyHandler(ReqReadRecvdNumByKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    else
    {
        disable_tab_pane_keys();
    }
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(ReqReadRecvdNumByKey, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTCallDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTCallDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTCallDialedNum, KEY_EVENT_UP);
#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSaveDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSaveDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(CHISTSaveDialedNum, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSaveDialedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTDeleteDialedCallConfirm, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTEditDialedNum
 * DESCRIPTION
 *  Dialed call list option Edit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTEditDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTEditDialedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


#ifdef __MMI_CH_OPTIONS_SENDSMS__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSendSMSDialedNum
 * DESCRIPTION
 *  Dialed call list option Send SMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSendSMSDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSendSMSDialedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_SENDMMS__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSendMMSDialedNum
 * DESCRIPTION
 *  Dialed call list option Send MMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSendMMSDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSendMMSDialedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */


#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTInfoDialedNum
 * DESCRIPTION
 *  Dialed call list option Info handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTInfoDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTViewDialedCall, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTCallMissedNum
 * DESCRIPTION
 *  Missed call list option call handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTCallMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTCallMissedNum, KEY_EVENT_UP);
#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSaveMissedNum
 * DESCRIPTION
 *  Missed call list option save handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSaveMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(CHISTSaveMissedNum, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSaveMissedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteMissedNum
 * DESCRIPTION
 *  Missed call list option delete handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTDeleteMissedCallConfirm, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTEditMissedNum
 * DESCRIPTION
 *  Missed call list option Edit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTEditMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTEditMissedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


#ifdef __MMI_CH_OPTIONS_SENDSMS__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSendSMSMissedNum
 * DESCRIPTION
 *  Missed call list option Send SMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSendSMSMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSendSMSMissedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_SENDMMS__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSendMMSMissedNum
 * DESCRIPTION
 *  Missed call list option Send MMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSendMMSMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSendMMSMissedNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */


#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTInfoMissedNum
 * DESCRIPTION
 *  Missed call list option Info handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTInfoMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTViewMissedCall, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTCallRecvdNum
 * DESCRIPTION
 *  Recvd call list option Call handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTCallRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTCallRecvdNum, KEY_EVENT_UP);
#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSaveRecvdNum
 * DESCRIPTION
 *  Recvd call list option Save to phonebook handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSaveRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(CHISTSaveRecvdNum, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSaveRecvdNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteRecvdNum
 * DESCRIPTION
 *  Recvd call list option Delete handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTDeleteRecvdCallConfirm, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTEditRecvdNum
 * DESCRIPTION
 *  Recvd call list option Edit handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTEditRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTEditRecvdNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


#ifdef __MMI_CH_OPTIONS_SENDSMS__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSendSMSRecvdNum
 * DESCRIPTION
 *  Recvd call list option Send SMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSendSMSRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSendSMSRecvdNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_SENDMMS__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSendMMSRecvdNum
 * DESCRIPTION
 *  Recvd call list option Send MMS handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSendMMSRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(CHISTSendMMSRecvdNum, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTInfoRecvdNum
 * DESCRIPTION
 *  Recvd call list option Info handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTInfoRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCHISTViewRecvdCall, KEY_EVENT_UP);
    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 


/*****************************************************************************
 * FUNCTION
 *  HintCHISTDialedCalls
 * DESCRIPTION
 *  fill in hint buffer for dialed calls
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTDialedCalls(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (chis_p->nDialedCalls == 0)
    {
        mmi_ucs2ncpy((S8*) hintData[index], (S8*) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8*) value, "%d ", chis_p->nDialedCalls);
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (chis_p->nDialedCalls == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTMissedCalls
 * DESCRIPTION
 *  fill in hint buffer for missed calls
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTMissedCalls(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (chis_p->nMissedCalls == 0)
    {
        mmi_ucs2ncpy((S8*) hintData[index], (S8*) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8*) value, "%d ", chis_p->nMissedCalls);
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (chis_p->nMissedCalls == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTRecvdCalls
 * DESCRIPTION
 *  fill in hint buffer for recvd calls
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTRecvdCalls(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (chis_p->nRecvdCalls == 0)
    {
        mmi_ucs2ncpy((S8*) hintData[index], (S8*) GetString(STR_NO_ENTRY), MAX_GET_STRING_LEN);
    }
    else
    {
        sprintf((S8*) value, "%d ", chis_p->nRecvdCalls);
        mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
        if (chis_p->nRecvdCalls == 1)
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRY), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) hintData[index], (S8*) GetString(STR_ENTRIES), MAX_GET_STRING_LEN);
        }    
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewDialedCallList
 * DESCRIPTION
 *  Dialed call list viewer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewDialedCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *phoneNumbers[TOT_SIZE_OF_DIALED_LIST];
    U8 *phoneNames[TOT_SIZE_OF_DIALED_LIST];
    U8 *guiBuffer;
    U16 Cat23DemoIcons[TOT_SIZE_OF_DIALED_LIST];
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

    if (chis_p->nDialedCalls)
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR8055_CALLS_LIST_DIALED, NULL, ReqReadDialedNum, MMI_FULL_SCREEN);
        }
        else
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        {
            /* from menu or from shorcut */
        #ifndef __DISABLE_SHORTCUTS_MENU__
            if ((IsScreenPresent(MAIN_MENU_SCREENID) || IsScreenPresent(SCR_ID_SHCT_IDLE_SHORTCUT) ||
                (GetExitScrnID() == SCR_ID_SHCT_IDLE_SHORTCUT))
            #ifdef __MMI_CH_MIXED_CALL_LOG__
                 || chis_p->isMixedStyle == FALSE
            #endif
                )
        #else /* __DISABLE_SHORTCUTS_MENU__ */ 
            if (IsScreenPresent(MAIN_MENU_SCREENID)            
            #ifdef __MMI_CH_MIXED_CALL_LOG__
                 || chis_p->isMixedStyle == FALSE
            #endif
                )
        #endif /* __DISABLE_SHORTCUTS_MENU__ */ 
                EntryNewScreen(SCR8055_CALLS_LIST_DIALED, NULL, ReqReadDialedNum, MMI_FULL_SCREEN);
            else
            {
                EntryNewScreen(SCR8055_CALLS_LIST_DIALED, NULL, CHISTGetCallLogBySENDKey, MMI_FULL_SCREEN);
            }
        }

        guiBuffer = GetCurrGuiBuffer(SCR8055_CALLS_LIST_DIALED);
        RegisterHighlightHandler(CHISTGetCurrDialedCallIndex);
        CHISTPopulateDialedCallList(phoneNumbers, phoneNames);

        for (count = 0; count < chis_p->nDialedCalls; count++)
        {
        #ifdef __MMI_VOIP__
            if (chis_p->dialedCalls[count].address_type == PHB_LN_VOIP)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_DIALED_CALLS;
            }
            else
        #endif /* __MMI_VOIP__ */
        #if defined(__MMI_VIDEO_TELEPHONY__)
            if (chis_p->dialedCalls[count].address_type == PHB_LN_VIDEO)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VIDEO_DIALED_CALLS;
            }
            else        
        #endif
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                Cat23DemoIcons[count] = IMG_MTPNP_CARD1_MENU_DIALED_CALLS;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                Cat23DemoIcons[count] = IMG_MENU8102_DIALED_CALLS;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_all_hints_in_menuitem();
    #endif 
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (GetExitScrnID() == SCR8055_CALLS_LIST_DIALED)
        {
            ShowCategory53Screen(
                STR_SCR8056_CAPTION,
                IMG_SCR8056_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nDialedCalls,
                phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currDialedCallIndex,
                guiBuffer);
        }
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        if (GetExitScrnID() == SCR8055_CALLS_LIST_DIALED)
        {
            ShowCategory53Screen(
                STR_SCR8056_CAPTION,
                IMG_SCR8056_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nDialedCalls,
                phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currDialedCallIndex,
                guiBuffer);
        }
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    #ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_PFAL_CC_HandleSendKeys(CHISTCallDialedNum,KEY_EVENT_DOWN);
    #else /* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(CHISTCallDialedNum, KEY_SEND, KEY_EVENT_DOWN);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    
    #ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
        SetKeyHandler(CHISTCallVTDialedNum, KEY_ENTER, KEY_EVENT_DOWN);
    #endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */ 
       
    #ifdef __MMI_IP_KEY__
/* under construction !*/
    #endif 

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        SetKeyHandler(EntryCHISTDialedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTDialedListOptions, KEY_EVENT_UP);
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetKeyHandler(EntryCHISTViewDialedCall, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTViewDialedCall, KEY_EVENT_UP);
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_post_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 

    }
    else
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR8055_CALLS_LIST_DIALED, NULL, ReqReadDialedNum, MMI_FULL_SCREEN);
            guiBuffer = GetCurrGuiBuffer(SCR8055_CALLS_LIST_DIALED);

            if (GetExitScrnID() == SCR8055_CALLS_LIST_DIALED)
            {
                ShowCategory53Screen(
                    STR_SCR8056_CAPTION,
                    IMG_SCR8056_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    chis_p->nDialedCalls,
                    NULL,
                    NULL,
                    NULL,
                    0,
                    0,
                    guiBuffer);
            }
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            set_post_tab_pane_display();
        }
        else
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        {
            DisplayPopup(
                (PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                IMG_GLOBAL_EMPTY,
                1,
                CS_NOTIFYDURATION,
                EMPTY_LIST_TONE);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewDialedCall
 * DESCRIPTION
 *  To show the screen containing details
 *  of the dialed call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewDialedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start= 0;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR8008_CALL_DIALED, ExitCHISTViewDialedCall, NULL, NULL);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif 
    guiBuffer = GetCurrGuiBuffer(SCR8008_CALL_DIALED);
    index = chis_p->currDialedCallIndex;

    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    
    if (chis_p->dialedCalls[index].startTime.nDay != 0)
    {
        date_string(&chis_p->dialedCalls[index].startTime, (UI_string_type) subMenuDataPtrs[start], DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_DATE_ENTRY;
        time_string(&chis_p->dialedCalls[index].startTime, (UI_string_type) subMenuDataPtrs[start], DT_IDLE_SCREEN);
        Cat23DemoIcons[start++] = IMG_TIME_ENTRY;
    }

    if (chis_p->dialedCalls[index].pbName[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8*) subMenuDataPtrs[start++], (S8*) chis_p->dialedCalls[index].pbName);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (chis_p->dialedCalls[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) chis_p->dialedCalls[index].number, MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
        #ifdef __MMI_VOIP__
            if (chis_p->dialedCalls[index].address_type == PHB_LN_VOIP)
            {
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_ID_CHIST_ANONYMOUS_URI), MAX_GET_STRING_LEN);
            }
            else
        #endif            
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;

        if (chis_p->dialedCalls[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) chis_p->dialedCalls[index].number, MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
        #ifdef __MMI_VOIP__
            if (chis_p->dialedCalls[index].address_type == PHB_LN_VOIP)
            {
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_ID_CHIST_ANONYMOUS_URI), MAX_GET_STRING_LEN);
            }
            else
        #endif
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8*) subMenuDataPtrs[start+1], "%d ", chis_p->dialedCalls[index].no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start+1]);
    if (chis_p->dialedCalls[index].no_of_times == 1)
    {
        mmi_ucs2ncat((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* __PHB_LN_SINGLE_COUNT__ */ 
    if (mmi_dt_mytime_2_utc_sec(&chis_p->dialedCalls[index].duration, MMI_FALSE) != 0)
    {
        U8 value[20];
        sprintf(
            (S8*) value,
            "%02d:%02d:%02d",
            chis_p->dialedCalls[index].duration.nHour,
            chis_p->dialedCalls[index].duration.nMin,
            chis_p->dialedCalls[index].duration.nSec);
        mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) value);
        Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    }
    noItems = start;
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    ShowCategory84Screen(
        STR_SCR8069_CAPTION1,
        IMG_SCR8069_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noItems,
        subMenuDataPtrs,
        Cat23DemoIcons,
        LIST_MENU,
        0,
        guiBuffer);
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    ShowCategory84Screen(
        STR_SCR8069_CAPTION1,
        IMG_SCR8069_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noItems,
        subMenuDataPtrs,
        Cat23DemoIcons,
        LIST_MENU,
        0,
        guiBuffer);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_PFAL_CC_HandleSendKeys(CHISTCallDialedNum,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(CHISTCallDialedNum, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
    SetKeyHandler(CHISTCallVTDialedNum, KEY_ENTER, KEY_EVENT_DOWN);
#endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */ 

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    SetKeyHandler(EntryCHISTDialedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryCHISTDialedListOptions, KEY_EVENT_UP);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTViewDialedCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTViewDialedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR8008_CALL_DIALED;
    currHistory.entryFuncPtr = EntryCHISTViewDialedCall;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDialedListOptions
 * DESCRIPTION
 *  To show a screen displaying options
 *  available on dialed call list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDialedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR8009_DIALED_CALL_OPTIONS, ExitCHISTDialedListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(DIALED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(DIALED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(DIALED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(DIALED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(DIALED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(DIALED_CALL_MENU_SENDMMS);    

    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].numLength == 0)
    {
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDMMS);
    }
#ifdef __MMI_VOIP__
    else if (chis_p->dialedCalls[chis_p->currDialedCallIndex].address_type == PHB_LN_VOIP)
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_INFO);
    #endif
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDMMS);
    }
#endif /* __MMI_VOIP__ */
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDSMS);
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(DIALED_CALL_MENU_SENDMMS);
        }
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */       
    }

    guiBuffer = GetCurrGuiBuffer(SCR8009_DIALED_CALL_OPTIONS);
    nNumofItem = GetNumOfChild_Ext(DIALED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(DIALED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(DIALED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR8070_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTDialedListOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTDialedListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR8008_CALL_DIALED))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR8009_DIALED_CALL_OPTIONS;
        currHistory.entryFuncPtr = EntryCHISTDialedListOptions;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
    #endif 
            AddHistory(currHistory);
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
    #endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDeleteDialedCallConfirm
 * DESCRIPTION
 *  To delete the current active dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDeleteDialedCallConfirm(void)
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
        get_string(STR_ENTRY_DELETED_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(CHISTDeleteDialedNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewMissedCallList
 * DESCRIPTION
 *  Missed call list viewer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewMissedCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *phoneNumbers[TOT_SIZE_OF_MISSED_LIST];
    U8 *phoneNames[TOT_SIZE_OF_MISSED_LIST];
    U8 *guiBuffer;
    U16 Cat23DemoIcons[TOT_SIZE_OF_MISSED_LIST];
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

    if (chis_p->nMissedCallBeforeView != 0)
    {
        chis_p->nMissedCallBeforeView = 0;
        /* re-enter:
           call history menu -> missed list -> X missed calls -> missed list */
        if (IsScreenPresent(SCR8056_CALLS_LIST_MISSED))
        {
            DeleteUptoScrID(SCR_CALL_HISTORY_MAIN_MENU);
        }
    }

    g_chist_have_missed_call = 0;
    mmi_chist_set_have_missed_call();
    HideStatusIcon(STATUS_ICON_MISSED_CALL);
    /* Add two statusicons on sublcd */
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    HideStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
#endif /* __MMI_SUBLCD_SHORT_STATUSICON_LIST__ */ 
    UpdateStatusIcons();

    if (chis_p->nMissedCalls)
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        EntryNewScreen(SCR8056_CALLS_LIST_MISSED, NULL, ReqReadMissedNum, MMI_FULL_SCREEN);

        guiBuffer = GetCurrGuiBuffer(SCR8056_CALLS_LIST_MISSED);
        RegisterHighlightHandler(CHISTGetCurrMissedCallIndex);
        CHISTPopulateMissedCallList(phoneNumbers, phoneNames);
        for (count = 0; count < chis_p->nMissedCalls; count++)
        {
        #ifdef __MMI_VOIP__
            if (chis_p->missedCalls[count].address_type == PHB_LN_VOIP)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_MISSED_CALLS;
            }
            else
        #endif /* __MMI_VOIP__ */
        #ifdef __MMI_VIDEO_TELEPHONY__
            if (chis_p->missedCalls[count].address_type == PHB_LN_VIDEO)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VIDEO_MISSED_CALLS;
            }
            else
        #endif /* __MMI_VIDEO_TELEPHONY__ */        
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                Cat23DemoIcons[count] = IMG_MTPNP_CARD1_MENU_MISSED_CALLS;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                Cat23DemoIcons[count] = IMG_MENU8103_MISSED_CALLS;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_all_hints_in_menuitem();
    #endif 
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (GetExitScrnID() == SCR8056_CALLS_LIST_MISSED)
        {
            ShowCategory53Screen(
                STR_SCR8055_CAPTION,
                IMG_SCR8055_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nMissedCalls,
                phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currMissedCallIndex,
                guiBuffer);
        }
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        if (GetExitScrnID() == SCR8056_CALLS_LIST_MISSED)
        {
            ShowCategory53Screen(
                STR_SCR8055_CAPTION,
                IMG_SCR8055_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nMissedCalls,
                phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currMissedCallIndex,
                guiBuffer);
        }
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
	MTPNP_PFAL_CC_HandleSendKeys(CHISTCallMissedNum,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(CHISTCallMissedNum, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    #ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
        SetKeyHandler(CHISTCallVTMissedNum, KEY_ENTER, KEY_EVENT_DOWN);
    #endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */
    
    #ifdef __MMI_IP_KEY__
/* under construction !*/
    #endif 

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        SetKeyHandler(EntryCHISTMissedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTMissedListOptions, KEY_EVENT_UP);
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetKeyHandler(EntryCHISTViewMissedCall, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTViewMissedCall, KEY_EVENT_UP);
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_post_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    }
    else
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR8056_CALLS_LIST_MISSED, NULL, ReqReadMissedNum, MMI_FULL_SCREEN);
            guiBuffer = GetCurrGuiBuffer(SCR8056_CALLS_LIST_MISSED);
            //phoneNames[0]=(PU8)GetString(STR_EMPTY_LIST_NOTIFICATION);
            //Cat23DemoIcons[0]=0;
            if (GetExitScrnID() == SCR8056_CALLS_LIST_MISSED)
            {
                ShowCategory53Screen(
                    STR_SCR8055_CAPTION,
                    IMG_SCR8055_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    chis_p->nMissedCalls,
                    NULL,
                    NULL,
                    NULL,
                    0,
                    0,
                    guiBuffer);
            }
            /* ShowCategory56Screen( STR_SCR8055_CAPTION, IMG_SCR8055_CAPTION,
               0,0, STR_GLOBAL_BACK,
               IMG_GLOBAL_BACK, 1, phoneNames,
               NULL,
               0, guiBuffer ); */
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            set_post_tab_pane_display();
        }
        else
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        {
            DisplayPopup(
                (PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                IMG_GLOBAL_EMPTY,
                1,
                CS_NOTIFYDURATION,
                EMPTY_LIST_TONE);
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    DeleteScreenIfPresent(SCR_MTPNP_CALL_HISTORY_NOTIFY);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewMissedCall
 * DESCRIPTION
 *  To show the screen containing details
 *  of the missed call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 noItems, index, i = 0;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[4];
#else 
    U16 Cat23DemoIcons[5];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR8520_CALL_MISSED, ExitCHISTViewMissedCall, NULL, NULL);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif 
    guiBuffer = GetCurrGuiBuffer(SCR8520_CALL_MISSED);
    index = chis_p->currMissedCallIndex;

    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    
    date_string(&chis_p->missedCalls[index].startTime, (UI_string_type) subMenuDataPtrs[0], DT_IDLE_SCREEN);
    time_string(&chis_p->missedCalls[index].startTime, (UI_string_type) subMenuDataPtrs[1], DT_IDLE_SCREEN);

    if (chis_p->missedCalls[index].pbName[0] != 0)
    {
        mmi_ucs2cpy((S8*) subMenuDataPtrs[2], (S8*) chis_p->missedCalls[index].pbName);

        if (chis_p->missedCalls[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8*) subMenuDataPtrs[3], (S8*) chis_p->missedCalls[index].number, MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
        #ifdef __MMI_VOIP__
            if (chis_p->missedCalls[index].address_type == PHB_LN_VOIP)
            {
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[3], (S8*) GetString(STR_ID_CHIST_ANONYMOUS_URI), MAX_GET_STRING_LEN);
            }
            else
        #endif            
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[3], (S8*) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    #ifdef __PHB_LN_SINGLE_COUNT__
        noItems = 4;
    #else /* __PHB_LN_SINGLE_COUNT__ */ 
        sprintf((S8*) subMenuDataPtrs[5], "%d ", chis_p->missedCalls[index].no_of_times);
        mmi_asc_to_ucs2((PS8) subMenuDataPtrs[4], (PS8) subMenuDataPtrs[5]);
        if (chis_p->missedCalls[index].no_of_times == 1)
        {
            mmi_ucs2ncat((S8*) subMenuDataPtrs[4], (S8*) GetString(STR_TIME), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) subMenuDataPtrs[4], (S8*) GetString(STR_TIMES), MAX_GET_STRING_LEN);
        }

        noItems = 5;
        Cat23DemoIcons[4] = IMG_COUNT_ENTRY;
    #endif /* __PHB_LN_SINGLE_COUNT__ */ 
        Cat23DemoIcons[0] = IMG_DATE_ENTRY;
        Cat23DemoIcons[1] = IMG_TIME_ENTRY;
        Cat23DemoIcons[2] = IMG_NAME_ENTRY;
        Cat23DemoIcons[3] = IMG_NUMBER_ENTRY;
    }
    else
    {
        if (chis_p->missedCalls[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8*) subMenuDataPtrs[2], (S8*) chis_p->missedCalls[index].number, MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
        #ifdef __MMI_VOIP__
            if (chis_p->missedCalls[index].address_type == PHB_LN_VOIP)
            {
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[2], (S8*) GetString(STR_ID_CHIST_ANONYMOUS_URI), MAX_GET_STRING_LEN);
            }
            else
        #endif
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[2], (S8*) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    #ifdef __PHB_LN_SINGLE_COUNT__
        noItems = 3;
    #else /* __PHB_LN_SINGLE_COUNT__ */ 
        sprintf((S8*) subMenuDataPtrs[4], "%d ", chis_p->missedCalls[index].no_of_times);
        mmi_asc_to_ucs2((PS8) subMenuDataPtrs[3], (PS8) subMenuDataPtrs[4]);
        if (chis_p->missedCalls[index].no_of_times == 1)
        {
            mmi_ucs2ncat((S8*) subMenuDataPtrs[3], (S8*) GetString(STR_TIME), MAX_GET_STRING_LEN);
        }
        else
        {
            mmi_ucs2ncat((S8*) subMenuDataPtrs[3], (S8*) GetString(STR_TIMES), MAX_GET_STRING_LEN);
        }

        noItems = 4;
        Cat23DemoIcons[3] = IMG_COUNT_ENTRY;
    #endif /* __PHB_LN_SINGLE_COUNT__ */ 
        Cat23DemoIcons[0] = IMG_DATE_ENTRY;
        Cat23DemoIcons[1] = IMG_TIME_ENTRY;
        Cat23DemoIcons[2] = IMG_NUMBER_ENTRY;
    }
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    ShowCategory84Screen(
        STR_SCR8069_CAPTION1,
        IMG_SCR8069_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noItems,
        subMenuDataPtrs,
        Cat23DemoIcons,
        LIST_MENU,
        0,
        guiBuffer);
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    ShowCategory84Screen(
        STR_SCR8069_CAPTION1,
        IMG_SCR8069_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noItems,
        subMenuDataPtrs,
        Cat23DemoIcons,
        LIST_MENU,
        0,
        guiBuffer);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(CHISTCallMissedNum,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(CHISTCallMissedNum, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
    SetKeyHandler(CHISTCallVTMissedNum, KEY_ENTER, KEY_EVENT_DOWN);
#endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    SetKeyHandler(EntryCHISTMissedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryCHISTMissedListOptions, KEY_EVENT_UP);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTViewMissedCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTViewMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR8520_CALL_MISSED;
    currHistory.entryFuncPtr = EntryCHISTViewMissedCall;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTMissedListOptions
 * DESCRIPTION
 *  To show a screen displaying options
 *  available on Missed call list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTMissedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR8521_MISSED_CALL_OPTIONS, ExitCHISTMissedListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif 
    nMissedCallNumBkp = chis_p->nMissedCalls;
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(MISSED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(MISSED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(MISSED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(MISSED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(MISSED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(MISSED_CALL_MENU_SENDMMS);
    
    if (chis_p->missedCalls[chis_p->currMissedCallIndex].numLength == 0)
    {
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDMMS);
    }
#ifdef __MMI_VOIP__
    else if (chis_p->missedCalls[chis_p->currMissedCallIndex].address_type == PHB_LN_VOIP)
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_INFO);
    #endif
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDMMS);
    }
#endif /* __MMI_VOIP__ */
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_INFO);
    #endif

    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDSMS);
    #else /* __MMI_CH_OPTIONS_SENDSMS__ */
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDSMS);
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */

    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(MISSED_CALL_MENU_SENDMMS);
        }   
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */
    }

    guiBuffer = GetCurrGuiBuffer(SCR8521_MISSED_CALL_OPTIONS);
    nNumofItem = GetNumOfChild_Ext(MISSED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(MISSED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(MISSED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
 


    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR8071_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTMissedListOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTMissedListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR8520_CALL_MISSED))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR8521_MISSED_CALL_OPTIONS;
        currHistory.entryFuncPtr = EntryCHISTMissedListOptions;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
    #endif 
            AddHistory(currHistory);
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
    #endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDeleteMissedCallConfirm
 * DESCRIPTION
 *  To delete the current active dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDeleteMissedCallConfirm(void)
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
        get_string(STR_ENTRY_DELETED_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(CHISTDeleteMissedNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#if 1
// Huyanwei Add It 
extern void CHISTGetCallLogBySENDKey(void);
extern void EntrySlaveReadCallHistoryBySend(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryCHISTNotifyMissedCall
 * DESCRIPTION
 *  Notify user of missed call presence when
 *  entering IDLE screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTNotifyMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    U8 typeBeenHandle = 0;// 1 ==SIM1 2 ==SIM2 
    U8 bothMissedCall = 0;// 0 no missed call , 1 master havs missed call,2 slave has.., 3 both have missed call
    U8 sim2MissedCallBeforeView = MTPNP_AD_Get_MissedCallCount_BeforeView();
    UI_character_type temp[10];
#endif /* __MMI_DUAL_SIM_MASTER__ */
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    EntryNewScreen(ITEM_SCR_MISSED_CALL, ExitCHISTNotifyMissedCall, NULL, NULL);
    memset(CHISTMsgStr, 0, CHIST_MSG_LENGTH);
    memset(CHISTMsgStr2, 0, CHIST_MSG_LENGTH);

    if ((MTPNP_PFAL_GetLastMissedCallType() == LASTMISSEDCALL_TYPE_SIM1) && (chis_p->nMissedCallBeforeView != 0) && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE))
    {            
        typeBeenHandle = 1;

        mmi_ucs2cat((PS8) CHISTMsgStr, GetString(STRING_MTPNP_SIM1));
        mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L": ");
        memset(temp, 0, sizeof(temp));
        gui_itoa(chis_p->nMissedCallBeforeView, temp, 10);
        mmi_ucs2cat((PS8) CHISTMsgStr, (const S8 *)temp);
        mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L" ");
        if (chis_p->nMissedCallBeforeView == 1)
        {
            mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALL), 20);
        }
        else
        {
            mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALLS), 20);
        }
    }
    else if ((MTPNP_PFAL_GetLastMissedCallType() == LASTMISSEDCALL_TYPE_SIM2) && (sim2MissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)))
    {
        typeBeenHandle=2;

        mmi_ucs2cat((PS8) CHISTMsgStr,GetString(STRING_MTPNP_SIM2));
        mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L": ");
        memset(temp,0,sizeof(temp));
        gui_itoa(sim2MissedCallBeforeView, temp, 10);
        mmi_ucs2cat((PS8) CHISTMsgStr, (const S8 *)temp);
        mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L" ");
        if (sim2MissedCallBeforeView == 1)
        {
            mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALL), 20);
        }
        else
        {
            mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALLS), 20);
        }
    }   

    if (typeBeenHandle == 0)
    {
        if (chis_p->nMissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE))
        {
            mmi_ucs2cat((PS8) CHISTMsgStr, GetString(STRING_MTPNP_SIM1));
            mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L": ");
            memset(temp, 0, sizeof(temp));
            gui_itoa(chis_p->nMissedCallBeforeView, temp, 10);
            mmi_ucs2cat((PS8) CHISTMsgStr, (const S8 *)temp);
            mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L" ");
            if (chis_p->nMissedCallBeforeView == 1)
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALL), 20);
            }
            else
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALLS), 20);
            }            
        }
        else if (sim2MissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE))
        {
            mmi_ucs2cat((PS8) CHISTMsgStr,GetString(STRING_MTPNP_SIM2));
            mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L": ");
            memset(temp,0,sizeof(temp));
            gui_itoa(sim2MissedCallBeforeView, temp, 10);
            mmi_ucs2cat((PS8) CHISTMsgStr, (const S8 *)temp);
            mmi_ucs2cat((PS8) CHISTMsgStr, (PS8) L" ");            
            if (sim2MissedCallBeforeView == 1)
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALL), 20);
            }
            else
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALLS), 20);
            }
        }        
    }
    else
    {
        if ((typeBeenHandle == 1) && (sim2MissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)))
        {
            bothMissedCall = 3;
            mmi_ucs2cat((PS8) CHISTMsgStr2,GetString(STRING_MTPNP_SIM2));
            mmi_ucs2cat((PS8) CHISTMsgStr2, (PS8) L": ");
            memset(temp, 0, sizeof(temp));
            gui_itoa(sim2MissedCallBeforeView, temp, 10);
            mmi_ucs2cat((PS8) CHISTMsgStr2, (const S8 *)temp);
            mmi_ucs2cat((PS8) CHISTMsgStr2, (PS8) L" ");            
            if (sim2MissedCallBeforeView == 1)
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr2, (PS8) GetString(STR_MISSED_CALL), 20);
            }
            else
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr2, (PS8) GetString(STR_MISSED_CALLS), 20);
            }
        }
        else if ((typeBeenHandle == 2) && (chis_p->nMissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)))
        {
            bothMissedCall = 3;
            mmi_ucs2cat((PS8) CHISTMsgStr2,GetString(STRING_MTPNP_SIM1));
            mmi_ucs2cat((PS8) CHISTMsgStr2, (PS8) L": ");
            memset(temp, 0, sizeof(temp));
            gui_itoa(chis_p->nMissedCallBeforeView, temp, 10);
            mmi_ucs2cat((PS8) CHISTMsgStr2, (const S8 *)temp);
            mmi_ucs2cat((PS8) CHISTMsgStr2, (PS8) L" ");            
            if (chis_p->nMissedCallBeforeView == 1)
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr2, (PS8) GetString(STR_MISSED_CALL), 20);
            }
            else
            {
                mmi_ucs2ncat((PS8) CHISTMsgStr2, (PS8) GetString(STR_MISSED_CALLS), 20);
            }
        }
    }
#else /* __MMI_DUAL_SIM_MASTER__ */
    EntryNewScreen(ITEM_SCR_MISSED_CALL, ExitCHISTNotifyMissedCall, NULL, NULL);

    memset(CHISTMsgStr, 0, 40);
    gui_itoa(chis_p->nMissedCallBeforeView, (UI_character_type*) CHISTMsgStr, 10);

    mmi_ucs2cat((PS8) CHISTMsgStr, " ");
    if (chis_p->nMissedCallBeforeView == 1)
    {
        mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALL), 20);
    }
    else
    {
        mmi_ucs2ncat((PS8) CHISTMsgStr, (PS8) GetString(STR_MISSED_CALLS), 20);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    if (g_keylock_context.gKeyPadLockFlag == 0)
    {
        chis_p->saveMissedScrn = TRUE;
        ShowCategory154Screen(
            0,
            0,
            MISSED_LSK_STR,
            0,
            STR_GLOBAL_BACK,
            0,
            (U8*) CHISTMsgStr,
            #ifdef __MMI_DUAL_SIM_MASTER__
            (U8*)CHISTMsgStr2,
            #else /*__MMI_DUAL_SIM_MASTER__*/
            NULL,
            #endif /*__MMI_DUAL_SIM_MASTER__*/
            MISSED_LSK_ICN,
            NULL);
	#if defined(NOKE_DEBUG)
	    noke_dbg_printf("Huyanwei debug EntryCHISTNotifyMissedCall() missed call %s %d",__FILE__,__LINE__);
	#endif

       if ((MTPNP_PFAL_GetLastMissedCallType() == LASTMISSEDCALL_TYPE_SIM1) && (chis_p->nMissedCallBeforeView != 0) && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE))
	{
  		#if defined(NOKE_DEBUG)
		    noke_dbg_printf("Huyanwei debug EntryCHISTNotifyMissedCall() missed call %s %d",__FILE__,__LINE__);
		#endif

		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_ENTER, KEY_EVENT_UP);	 
		
		SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND1, KEY_EVENT_UP);	 		
		//if ((sim2MissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)))
		{
			SetKeyHandler( EntrySlaveReadCallHistoryBySend , KEY_SEND2, KEY_EVENT_UP);		
		}
		
	       SetLeftSoftkeyFunction(CHISTGetCallLogBySENDKey, KEY_EVENT_UP);
			
	       SetKeyHandler(CHISTIgnoreMissedCallScreen, KEY_END, KEY_EVENT_DOWN);
	       SetRightSoftkeyFunction(CHISTIgnoreMissedCallScreen, KEY_EVENT_UP);			
	}
       else if ((MTPNP_PFAL_GetLastMissedCallType() == LASTMISSEDCALL_TYPE_SIM2) && (sim2MissedCallBeforeView != 0 && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)))
	{
	   #if defined(NOKE_DEBUG)
	    noke_dbg_printf("Huyanwei debug EntryCHISTNotifyMissedCall() missed call %s %d",__FILE__,__LINE__);
	    #endif

		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
		SetKeyHandler( EntrySlaveReadCallHistoryBySend , KEY_ENTER, KEY_EVENT_UP);

		//if ( (chis_p->nMissedCallBeforeView != 0) && (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE || MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) )
		{
			SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND1, KEY_EVENT_UP);	 
		}
		SetKeyHandler( EntrySlaveReadCallHistoryBySend , KEY_SEND2, KEY_EVENT_UP);
		
	       SetLeftSoftkeyFunction(EntrySlaveReadCallHistoryBySend, KEY_EVENT_UP);	
			
	        SetKeyHandler(CHISTIgnoreMissedCallScreen, KEY_END, KEY_EVENT_DOWN);
	        SetRightSoftkeyFunction(CHISTIgnoreMissedCallScreen, KEY_EVENT_UP);	
	}
	else
	{
  		#if defined(NOKE_DEBUG)
		    noke_dbg_printf("Huyanwei debug EntryCHISTNotifyMissedCall() missed call %s %d",__FILE__,__LINE__);
		#endif
		SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);	       			
       //SetLeftSoftkeyFunction(MTPNP_PFAL_ReadDualModeMissedNum, KEY_EVENT_UP);
		//SetKeyHandler(MTPNP_PFAL_ReadDualModeMissedNum, KEY_ENTER, KEY_EVENT_UP);	

 	    SetLeftSoftkeyFunction(EntrySlaveReadCallHistoryBySend,KEY_EVENT_UP);
		SetKeyHandler(EntrySlaveReadCallHistoryBySend,KEY_ENTER, KEY_EVENT_UP);	

		SetKeyHandler(CHISTGetCallLogBySENDKey, KEY_SEND1, KEY_EVENT_UP);	 
		SetKeyHandler( EntrySlaveReadCallHistoryBySend , KEY_SEND2, KEY_EVENT_UP);		

		 SetKeyHandler(CHISTIgnoreMissedCallScreen, KEY_END, KEY_EVENT_DOWN);
	        SetRightSoftkeyFunction(CHISTIgnoreMissedCallScreen, KEY_EVENT_UP);	
	}
	
    #ifndef __MMI_DUAL_SIM_MASTER__
        SetMissedCallFlag(FALSE);
     #else
         if(3!=  bothMissedCall)
         {
             SetMissedCallFlag(FALSE);
         }
     #endif
        chis_p->currMissedCallIndex = 0;
    }
    else    /* keypad is locked */
    {
        chis_p->saveMissedScrn = FALSE;
        ShowCategory154Screen(
            0,
            0,
            g_keylock_context.KeyLockLSKStringID,
            g_keylock_context.KeyLockLSKIconID,
            g_keylock_context.KeyLockRSKStringID,
            g_keylock_context.KeyLockRSKIconID,
            (U8*) CHISTMsgStr,
            #ifdef __MMI_DUAL_SIM_MASTER__
            (U8*)CHISTMsgStr2,
            #else /*__MMI_DUAL_SIM_MASTER__*/
            NULL,
            #endif /*__MMI_DUAL_SIM_MASTER__*/
            MISSED_LSK_ICN,
            NULL);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    }

    ForceSubLCDScreen(EntrySubCHISTNotifyMissedCall);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTNotifyMissedCall
 * DESCRIPTION
 *  This function is the exit screen for the Active Call and
 *  incoming options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTNotifyMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->saveMissedScrn == TRUE)
    {
        U16 nHistory = 0;
        history scr101;

        mmi_ucs2cpy((S8*) scr101.inputBuffer, (PS8) & nHistory);
        scr101.scrnID = ITEM_SCR_MISSED_CALL;
        scr101.entryFuncPtr = EntryCHISTNotifyMissedCall;
        GetCategoryHistory(scr101.guiBuffer);
        AddHistory(scr101);
    }   /* else
           {
           GoBackSubLCDHistory();
           }
           return; */
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubCHISTNotifyMissedCall
 * DESCRIPTION
 *  Entry screen for Sub Lcd Missed Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern FuncPtr GetCurrSubLCDScreenFunc(void);
void EntrySubCHISTNotifyMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetCurrSubLCDScreenFunc() == ExitSubCHISTNotifyMissedCall))
    {
        return;
    }

    ExecSubLCDCurrExitHandler();

    /* DeleteSubLCDScreen(SUB_LCD_ITEM_SCR_MISSED_CALL); */
    ShowCategory304Screen(IMG_CM_STATE_MISSED, NULL);
    /* do not add sub LCD to history, the main screen will force to show sub LCD anyway */
    /* SetSubLCDExitHandler(ExitSubCHISTNotifyMissedCall); */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitSubCHISTNotifyMissedCall
 * DESCRIPTION
 *  Exit Handler for Sub Lcd Missed Call Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubCHISTNotifyMissedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->saveMissedScrn == TRUE && !IsSubLCDScreenPresent(SUB_LCD_ITEM_SCR_MISSED_CALL))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = EntrySubCHISTNotifyMissedCall;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SUB_LCD_ITEM_SCR_MISSED_CALL);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewRecvdCallList
 * DESCRIPTION
 *  Recvd call list viewer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewRecvdCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *phoneNumbers[TOT_SIZE_OF_RECVD_LIST];
    U8 *phoneNames[TOT_SIZE_OF_RECVD_LIST];
    U8 *guiBuffer;
    U16 Cat23DemoIcons[TOT_SIZE_OF_RECVD_LIST];
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

    if (chis_p->nRecvdCalls)
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        EntryNewScreen(SCR8054_CALLS_LIST_RECEIVED, NULL, ReqReadRecvdNum, MMI_FULL_SCREEN);

        guiBuffer = GetCurrGuiBuffer(SCR8054_CALLS_LIST_RECEIVED);
        RegisterHighlightHandler(CHISTGetCurrRecvdCallIndex);
        memset(Cat23DemoIcons, 0, (TOT_SIZE_OF_RECVD_LIST * sizeof(U8*)));
        CHISTPopulateRecvdCallList(phoneNumbers, phoneNames);

        for (count = 0; count < chis_p->nRecvdCalls; count++)
        {
        #ifdef __MMI_VOIP__
            if (chis_p->recvdCalls[count].address_type == PHB_LN_VOIP)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_RECEIVED_CALLS;
            }
            else
        #endif /* __MMI_VOIP__ */
        #ifdef __MMI_VIDEO_TELEPHONY__
            if (chis_p->recvdCalls[count].address_type == PHB_LN_VIDEO)
            {
                Cat23DemoIcons[count] = IMG_ID_CHIST_VIDEO_RECEIVED_CALLS;
            }
            else
        #endif /* __MMI_VIDEO_TELEPHONY__ */        
            {
            #ifdef __MMI_DUAL_SIM_MASTER__
                Cat23DemoIcons[count] = IMG_MTPNP_CARD1_MENU_RECEIVED_CALLS;
            #else /* __MMI_DUAL_SIM_MASTER__ */
                Cat23DemoIcons[count] = IMG_MENU8101_RECEIVED_CALLS;
            #endif /* __MMI_DUAL_SIM_MASTER__ */
            }
        }
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_all_hints_in_menuitem();
    #endif 
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (GetExitScrnID() == SCR8054_CALLS_LIST_RECEIVED)
        {
            ShowCategory53Screen(
                STR_SCR8054_CAPTION,
                IMG_SCR8054_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nRecvdCalls,
                phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currRecvdCallIndex,
                guiBuffer);
        }
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        if (GetExitScrnID() == SCR8054_CALLS_LIST_RECEIVED)
        {
            ShowCategory53Screen(
                STR_SCR8054_CAPTION,
                IMG_SCR8054_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nRecvdCalls,
                phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currRecvdCallIndex,
                guiBuffer);
        }
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(CHISTCallRecvdNum,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(CHISTCallRecvdNum, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    #ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
        SetKeyHandler(CHISTCallVTRecvdNum, KEY_ENTER, KEY_EVENT_DOWN);
    #endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */

    #ifdef __MMI_IP_KEY__
/* under construction !*/
    #endif 

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        SetKeyHandler(EntryCHISTRecvdListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTRecvdListOptions, KEY_EVENT_UP);
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetKeyHandler(EntryCHISTViewRecvdCall, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTViewRecvdCall, KEY_EVENT_UP);
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_post_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    }
    else
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR8054_CALLS_LIST_RECEIVED, NULL, ReqReadRecvdNum, MMI_FULL_SCREEN);
            guiBuffer = GetCurrGuiBuffer(SCR8054_CALLS_LIST_RECEIVED);
            //phoneNames[0]=(PU8)GetString(STR_EMPTY_LIST_NOTIFICATION);
            //Cat23DemoIcons[0]=0;
            if (GetExitScrnID() == SCR8054_CALLS_LIST_RECEIVED)
            {
                ShowCategory53Screen(
                    STR_SCR8054_CAPTION,
                    IMG_SCR8054_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    chis_p->nRecvdCalls,
                    NULL,
                    NULL,
                    NULL,
                    0,
                    0,
                    guiBuffer);
            }
            /* ShowCategory56Screen( STR_SCR8054_CAPTION, IMG_SCR8054_CAPTION,
               0,0, STR_GLOBAL_BACK,
               IMG_GLOBAL_BACK, 1, phoneNames,
               NULL,
               0, guiBuffer ); */
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            set_post_tab_pane_display();
        }
        else
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        {
            DisplayPopup(
                (PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                IMG_GLOBAL_EMPTY,
                1,
                CS_NOTIFYDURATION,
                EMPTY_LIST_TONE);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewRecvdCall
 * DESCRIPTION
 *  To show the screen containing details
 *  of the recvd call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewRecvdCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 index, noItems, i, start= 0;

#ifdef __PHB_LN_SINGLE_COUNT__
    U16 Cat23DemoIcons[5];
#else 
    U16 Cat23DemoIcons[6];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR8006_CALL_RECEIVED, ExitCHISTViewRecvdCall, NULL, NULL);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif 
    guiBuffer = GetCurrGuiBuffer(SCR8006_CALL_RECEIVED);
    index = chis_p->currRecvdCallIndex;

    /* reset subMenuDataPtrs before use */
    for (i = 0; i < MAX_SUB_MENUS; i++)
    {
        subMenuDataPtrs[i] = subMenuData[i];
        memset((S8*)subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
    }
    
    date_string(&chis_p->recvdCalls[index].startTime, (UI_string_type) subMenuDataPtrs[start], DT_IDLE_SCREEN);
    Cat23DemoIcons[start++] = IMG_DATE_ENTRY;    
    time_string(&chis_p->recvdCalls[index].startTime, (UI_string_type) subMenuDataPtrs[start], DT_IDLE_SCREEN);
    Cat23DemoIcons[start++] = IMG_TIME_ENTRY;

    if (chis_p->recvdCalls[index].pbName[0] != 0)
    {
        Cat23DemoIcons[start] = IMG_NAME_ENTRY;
        mmi_ucs2cpy((S8*) subMenuDataPtrs[start++], (S8*) chis_p->recvdCalls[index].pbName);
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;
        if (chis_p->recvdCalls[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) chis_p->recvdCalls[index].number, MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
        #ifdef __MMI_VOIP__
            if (chis_p->recvdCalls[index].address_type == PHB_LN_VOIP)
            {
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_ID_CHIST_ANONYMOUS_URI), MAX_GET_STRING_LEN);
            }
            else
        #endif      
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
    else
    {
        Cat23DemoIcons[start] = IMG_NUMBER_ENTRY;
        if (chis_p->recvdCalls[index].number[0] != 0)
        {
            mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) chis_p->recvdCalls[index].number, MAX_SUBMENU_CHARACTERS - 1);
        }
        else
        {
        #ifdef __MMI_VOIP__
            if (chis_p->recvdCalls[index].address_type == PHB_LN_VOIP)
            {
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_ID_CHIST_ANONYMOUS_URI), MAX_GET_STRING_LEN);
            }
            else
        #endif
                mmi_ucs2ncpy((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_NO_NUMBER), MAX_GET_STRING_LEN);
        }
    }
#ifndef __PHB_LN_SINGLE_COUNT__
    sprintf((S8*) subMenuDataPtrs[start+1], "%d ", chis_p->recvdCalls[index].no_of_times);
    Cat23DemoIcons[start] = IMG_COUNT_ENTRY;
    mmi_asc_to_ucs2((PS8) subMenuDataPtrs[start], (PS8) subMenuDataPtrs[start+1]);
    if (chis_p->recvdCalls[index].no_of_times == 1)
    {
        mmi_ucs2ncat((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_TIME), MAX_GET_STRING_LEN);
    }
    else
    {
        mmi_ucs2ncat((S8*) subMenuDataPtrs[start++], (S8*) GetString(STR_TIMES), MAX_GET_STRING_LEN);
    }
#endif /* ~__PHB_LN_SINGLE_COUNT__ */ 
    if (mmi_dt_mytime_2_utc_sec(&chis_p->recvdCalls[index].duration, MMI_FALSE) != 0)
    {
        U8 value[20];
        sprintf(
            (S8*) value,
            "%02d:%02d:%02d",
            chis_p->recvdCalls[index].duration.nHour,
            chis_p->recvdCalls[index].duration.nMin,
            chis_p->recvdCalls[index].duration.nSec);
        mmi_asc_to_ucs2((S8*) subMenuDataPtrs[start], (S8*) value);
        Cat23DemoIcons[start++] = IMG_ID_CHIST_DURATION;
    }
    noItems = start;
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    ShowCategory84Screen(
        STR_SCR8069_CAPTION1,
        IMG_SCR8069_CAPTION,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noItems,
        subMenuDataPtrs,
        Cat23DemoIcons,
        LIST_MENU,
        0,
        guiBuffer);
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    ShowCategory84Screen(
        STR_SCR8069_CAPTION1,
        IMG_SCR8069_CAPTION,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noItems,
        subMenuDataPtrs,
        Cat23DemoIcons,
        LIST_MENU,
        0,
        guiBuffer);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 

#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(CHISTCallRecvdNum,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    SetKeyHandler(CHISTCallRecvdNum, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
    SetKeyHandler(CHISTCallVTRecvdNum, KEY_ENTER, KEY_EVENT_DOWN);
#endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */

#ifdef __MMI_IP_KEY__
/* under construction !*/
#endif 

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    SetKeyHandler(EntryCHISTRecvdListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryCHISTRecvdListOptions, KEY_EVENT_UP);
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTViewRecvdCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTViewRecvdCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR8006_CALL_RECEIVED;
    currHistory.entryFuncPtr = EntryCHISTViewRecvdCall;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(currHistory.guiBuffer);
    if (addToHistory)
    {
        AddHistory(currHistory);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTRecvdListOptions
 * DESCRIPTION
 *  To show a screen displaying options
 *  available on Recvd call list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTRecvdListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR8007_RECEIVED_CALL_OPTIONS, ExitCHISTRecvdListOptions, NULL, NULL);
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
    addToHistory = 1;
#endif
    chis_p->dialFromCallLog = ITEM_NONE;
    /* reset all menu */
    mmi_frm_unhide_menu_item(RECEIVED_CALL_MENU_INFO);
    mmi_frm_unhide_menu_item(RECEIVED_CALL_MENU_SAVE);
    mmi_frm_unhide_menu_item(RECEIVED_CALL_MENU_CALL);
    mmi_frm_unhide_menu_item(RECEIVED_CALL_MENU_EDIT);
    mmi_frm_unhide_menu_item(RECEIVED_CALL_MENU_SENDSMS);
    mmi_frm_unhide_menu_item(RECEIVED_CALL_MENU_SENDMMS);

    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].numLength == 0)
    {
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_INFO);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SAVE);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_CALL);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDMMS);
    }
#ifdef __MMI_VOIP__
    else if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].address_type == PHB_LN_VOIP)
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_INFO);
    #endif
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_EDIT);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDSMS);
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDMMS);
    }
#endif /* __MMI_VOIP__ */
    else
    {
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_INFO);
    #endif
    #ifndef __MMI_CH_OPTIONS_SENDSMS__
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDSMS);
    #else
        if (mmi_frm_sms_is_hide_send_sms_menu_item() == TRUE)
        {
            mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDSMS);
        }
    #endif /* __MMI_CH_OPTIONS_SENDSMS__ */
    #ifndef __MMI_CH_OPTIONS_SENDMMS__
        mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDMMS);
    #else
        if (!mms_is_ready())
        {
            mmi_frm_hide_menu_item(RECEIVED_CALL_MENU_SENDMMS);
        }   
    #endif /* def __MMI_CH_OPTIONS_SENDMMS__ */ 
    }
    guiBuffer = GetCurrGuiBuffer(SCR8007_RECEIVED_CALL_OPTIONS);
    nNumofItem = GetNumOfChild_Ext(RECEIVED_CALL_LIST_OPTIONS);
    GetSequenceStringIds_Ext(RECEIVED_CALL_LIST_OPTIONS, nStrItemList);
    SetParentHandler(RECEIVED_CALL_LIST_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        IMG_SCR8069_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTRecvdListOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTRecvdListOptions(void)
{
#ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR8006_CALL_RECEIVED))
    {
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        history currHistory;
        S16 nHistory = 0;

        currHistory.scrnID = SCR8007_RECEIVED_CALL_OPTIONS;
        currHistory.entryFuncPtr = EntryCHISTRecvdListOptions;
        mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
        GetCategoryHistory(currHistory.guiBuffer);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (addToHistory)
    #endif 
            AddHistory(currHistory);
    #ifndef __MMI_CH_OPTIONS_INCLUDE_INFO__
    }
    #endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDeleteRecvdCallConfirm
 * DESCRIPTION
 *  To delete the current active dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDeleteRecvdCallConfirm(void)
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
        get_string(STR_ENTRY_DELETED_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(CHISTDeleteRecvdNum, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTAnimationTimeOutHdlr
 * DESCRIPTION
 *  Time out handler for progressing screen before
 *  call log is ready right after power on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTAnimationTimeOutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    GoBackHistory();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTProcessingAnimation
 * DESCRIPTION
 *  Exit handler of call log progressing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTProcessingAnimation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(PHB_NOTIFYDURATION_TIMER);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqReadDialedNumByKey
 * DESCRIPTION
 *  Check if call log is ready before read dialed calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqReadDialedNumByKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isReqSent == TRUE)
    {
        return;
    }

    if (chis_p->isCallLogReady == TRUE && chis_p->isFirstTime == FALSE)
    {
        /* ready and auto read call log is done */
        ReqReadDialedNum();
        chis_p->isReqSent = TRUE;
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8056_CAPTION,
            IMG_SCR8056_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqReadDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqReadDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    GET_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntryCHISTViewDialedCallList();
        return;
    }

#ifndef __MMI_CH_MIXED_CALL_LOG__
    chis_p->dialedCalls = (LOG_CALL*) chis_p->callsLog;
#endif 

    dataPtr = (GET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(GET_LAST_NUMBER_REQ));

    dataPtr->type = PHB_LND;
    if (chis_p->sequenceId == 0)
    {
        chis_p->sequenceId = 1;
    }
    dataPtr->seq_id = chis_p->sequenceId;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_GET_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

/* only the first sequence will clear all key handler */
    if (chis_p->isFirstTime == FALSE && chis_p->sequenceId == 1)
    {
        AlmDisableExpiryHandler();
        ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    SetProtocolEventHandler(RspReadDialedNum, PRT_MMI_PHB_GET_LAST_NUMBER_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspReadDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspReadDialedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GET_LAST_NUMBER_RSP *rsp;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (GET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        if (rsp->type != PHB_LND)
        {
            return;
        }

        if (chis_p->sequenceId == 1)
        {
            chis_p->nDialedCalls = 0;
            memset((PS8) chis_p->dialedCalls, 0, sizeof(LOG_CALL) * TOT_SIZE_OF_ONE_LN_LIST);
        }
        for (index = 0; index < rsp->no_list; index++)
        {
            CHISTExtractPSCallLog(&chis_p->dialedCalls[chis_p->nDialedCalls], &rsp->list[index]);
            chis_p->nDialedCalls++;
        }
        if (rsp->more_data && rsp->no_list == TOT_SIZE_OF_ONE_LN_LIST)
        {
            chis_p->sequenceId++;
            ASSERT(chis_p->sequenceId < 11);
            ReqReadDialedNum();
            return;
        }
    }
    chis_p->sequenceId = 0;

#ifndef __MMI_CH_MIXED_CALL_LOG__
    if (chis_p->isFirstTime == TRUE)
#else 
    if (chis_p->isFirstTime == TRUE || chis_p->isMixedStyle == TRUE)
#endif 
    {
        ReqReadMissedNum();
        return;
    }

    chis_p->isReqSent = FALSE;
    EntryCHISTViewDialedCallList();
    AlmEnableExpiryHandler();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqWriteCallLog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dailCall        [?]         
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ReqWriteCallLog(CALL_INFO *dailCall, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    SET_LAST_NUMBER_REQ *dataPtr;
    U8 *name;
    U8 *number;
    U16 name_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PHB_LND:
            SetProtocolEventHandler(RspWriteNum, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
            number = (U8*) dailCall->num;
            chis_p->process = CALL_LOG_PROC_WRITE;
            break;
        case PHB_LNM:
            SetProtocolEventHandler(RspWriteNum, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
            number = (U8*) dailCall->number;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
            chis_p->process = CALL_LOG_PROC_WRITE;
    #endif 
            break;
        case PHB_LNR:
            SetProtocolEventHandler(RspWriteNum, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
            number = (U8*) dailCall->number;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
            chis_p->process = CALL_LOG_PROC_WRITE;
    #endif 
            break;
        default:
            return;
    }

    if (chis_p->isCallLogReady == FALSE)
    {
        return;
    }

    dataPtr = (SET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(SET_LAST_NUMBER_REQ));
    dataPtr->type = type;
    dataPtr->no_data = 0;
    dataPtr->index = 0xff;
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
#if defined(__MMI_VIDEO_TELEPHONY__)
    if (dailCall->call_type == MMI_UCM_VIDEO_CALL_TYPE)
    {
        dataPtr->entry.address_type = PHB_LN_VIDEO;
    }
    else
#endif /* defined(__MMI_VIDEO_TELEPHONY__) */
    {
        dataPtr->entry.address_type = PHB_LN_CALL;
    }
    memset((U8*) & dataPtr->entry.address.tel, 0, sizeof(CALL_LOG_NUMBER_STRUCT));
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    memset((U8*) & dataPtr->entry.tel, 0, sizeof(CALL_LOG_NUMBER_STRUCT));
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    memset((U8*) & dataPtr->entry.alpha_id, 0, sizeof(CALL_LOG_NAME_STRUCT));

    if (number[0] != 0)
    {
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
        if (number[0] == '+')
        {
            dataPtr->entry.address.tel.type = 145;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.address.tel.number, (PS8) (number + 2));
        }
        else
        {
            dataPtr->entry.address.tel.type = 129;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.address.tel.number, (PS8) (number));
        }
        dataPtr->entry.address.tel.length = strlen((PS8) dataPtr->entry.address.tel.number);
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
        if (number[0] == '+')
        {
            dataPtr->entry.tel.type = 145;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.tel.number, (PS8) (number + 2));
        }
        else
        {
            dataPtr->entry.tel.type = 129;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.tel.number, (PS8) (number));
        }
        dataPtr->entry.tel.length = strlen((PS8) dataPtr->entry.tel.number);
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    }
    if ((name_length = mmi_ucs2strlen((PS8) dailCall->pBname)) > 0)
    {
        name = OslMalloc((MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
        memset((PS8) name, 0, ((MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH));
        mmi_ucs2ncpy((PS8) name, (PS8) dailCall->pBname, ((name_length <= MAX_PB_NAME_LENGTH) ? name_length : MAX_PB_NAME_LENGTH));
        if (GetUCS2Flag((PS8) name))
        {
        #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
            if ((name_length = mmi_phb_convert_to_0x81((S8*) name, TRUE)) > 0)
            {
                dataPtr->entry.alpha_id.name_dcs = MMI_PHB_UCS2_81;
                dataPtr->entry.alpha_id.name_length = name_length;
                memcpy(dataPtr->entry.alpha_id.name, name, name_length);
                memset(dataPtr->entry.alpha_id.name + name_length, 0x00, 1);
            }
            else
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            {
                dataPtr->entry.alpha_id.name_dcs = MMI_PHB_UCS2;
                name_length = ((U8) mmi_ucs2strlen((S8*) dailCall->pBname)) * ENCODING_LENGTH;
                dataPtr->entry.alpha_id.name_length = ((name_length <= MAX_PB_NAME_LENGTH) ? name_length : MAX_PB_NAME_LENGTH);
                InputboxConvertDeviceEncodingToGSM(
                    (PU8) name,
                    dataPtr->entry.alpha_id.name,
                    (MAX_PS_NAME_LENGTH - ENCODING_LENGTH),
                    MMI_PHB_UCS2,
                    0,
                    1);
            }
        }
        else
        {
            dataPtr->entry.alpha_id.name_dcs = MMI_PHB_ASCII;
            dataPtr->entry.alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                                                name,
                                                dataPtr->entry.alpha_id.name,
                                                (MAX_PS_NAME_LENGTH - ENCODING_LENGTH),
                                                MMI_PHB_ASCII,
                                                0,
                                                1) - 1;
        }
        OslMfree(name);
    }

    ConvertMYTIME2RTC(&dataPtr->entry.time, &dailCall->start_time);
    dataPtr->entry.call_duration = 0;
    dataPtr->entry.count = 1;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_SET_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspWriteDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspWriteDialedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SET_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (SET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK && chis_p->nDialedCalls < TOT_SIZE_OF_DIALED_LIST)
    {
    #if (TOT_SIZE_OF_DIALED_LIST <= 20)
        chis_p->nDialedCalls = (U8) rsp->no_list;
    #else 
        chis_p->nDialedCalls++;
    #endif 
    }

    if (chis_p->process == CALL_LOG_PROC_SYNC)
    {
        PRINT_INFORMATION("set dialed rsp comes before read rsp!!!! re-sync.");
        chis_p->process = CALL_LOG_PROC_NONE;
        CHISTGetCallLogBySENDKey();
    }
    chis_p->process = CALL_LOG_PROC_NONE;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSyncCallLogNeeded
 * DESCRIPTION
 *  Check if need to update L4's call log data when
 *  user saves call log number to phonebook with name
 * PARAMETERS
 *  length      [IN]        
 *  type        [IN]        
 *  number      [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL CHISTSyncCallLogNeeded(U8 length, U8 type, PU8 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LOG_CALL *record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (chis_p->curCallLogType)
    {
        case PHB_LNM:
            record = &chis_p->missedCalls[chis_p->currMissedCallIndex];
            break;
        case PHB_LNR:
            record = &chis_p->recvdCalls[chis_p->currRecvdCallIndex];
            break;
        case PHB_LND:
        default:
            record = &chis_p->dialedCalls[chis_p->currDialedCallIndex];
            break;
    }

    if (mmi_ucs2cmp((PS8) number, (PS8) record->number) == 0)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ReqUpdateCallLogName
 * DESCRIPTION
 *  Update L4 call log data with new name
 * PARAMETERS
 *  length      [IN]        
 *  dcs         [IN]        
 *  name        [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void ReqUpdateCallLogName(U8 length, U8 dcs, PU8 name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    SET_LAST_NUMBER_REQ *dataPtr;
    LOG_CALL *record;
#if defined(__PHB_0x81_SUPPORT__) 
    U16 name_length;
#endif /* defined(__PHB_0x81_SUPPORT__)  */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_SET_LAST_NUMBER_REQ;
    dataPtr = (SET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(SET_LAST_NUMBER_REQ));
    dataPtr->type = chis_p->curCallLogType;
    dataPtr->no_data = 0;
    switch (dataPtr->type)
    {
        case PHB_LNM:
            record = &chis_p->missedCalls[chis_p->currMissedCallIndex];
            dataPtr->index = chis_p->currMissedCallIndex;
            break;
        case PHB_LND:
            record = &chis_p->dialedCalls[chis_p->currDialedCallIndex];
            dataPtr->index = chis_p->currDialedCallIndex;
            break;
        case PHB_LNR:
            record = &chis_p->recvdCalls[chis_p->currRecvdCallIndex];
            dataPtr->index = chis_p->currRecvdCallIndex;
            break;
        default:
            record = &chis_p->dialedCalls[chis_p->currDialedCallIndex];
            dataPtr->index = chis_p->currDialedCallIndex;
            break;
    }
    record->nameDCS = dcs;
    record->nameLength = length;
    mmi_ucs2cpy((PS8) record->pbName, (PS8) name);

#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    memset((U8*) & dataPtr->entry.address.tel, 0, sizeof(CALL_LOG_NUMBER_STRUCT));
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    memset((U8*) & dataPtr->entry.tel, 0, sizeof(CALL_LOG_NUMBER_STRUCT));
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    memset((U8*) & dataPtr->entry.alpha_id, 0, sizeof(CALL_LOG_NAME_STRUCT));

    if (record->number[0] != 0)
    {
    #if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
        if (record->number[0] == '+')
        {
            dataPtr->entry.address.tel.type = 145;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.address.tel.number, (PS8) (record->number + 2));
        }
        else
        {
            dataPtr->entry.address.tel.type = 129;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.address.tel.number, (PS8) (record->number));
        }
        dataPtr->entry.address.tel.length = strlen((PS8) dataPtr->entry.address.tel.number);
        dataPtr->entry.address_type = record->address_type;
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
        if (record->number[0] == '+')
        {
            dataPtr->entry.tel.type = 145;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.tel.number, (PS8) (record->number + 2));
        }
        else
        {
            dataPtr->entry.tel.type = 129;
            mmi_ucs2_to_asc((PS8) dataPtr->entry.tel.number, (PS8) (record->number));
        }
        dataPtr->entry.tel.length = strlen((PS8) dataPtr->entry.tel.number);
    #endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    }

    if (mmi_ucs2strlen((PS8) record->pbName) > 0)
    {
        if (GetUCS2Flag((PS8) record->pbName))
        {
        #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
            if ((name_length = mmi_phb_convert_to_0x81((S8*) record->pbName, TRUE)) > 0)
            {
                dataPtr->entry.alpha_id.name_dcs = MMI_PHB_UCS2_81;
                dataPtr->entry.alpha_id.name_length = name_length;
                memcpy(dataPtr->entry.alpha_id.name, record->pbName, name_length);
                memset(dataPtr->entry.alpha_id.name + length, 0x00, 1);
            }
            else
        #endif /* defined(__PHB_0x81_SUPPORT__) */ 
            {
                dataPtr->entry.alpha_id.name_dcs = MMI_PHB_UCS2;
                dataPtr->entry.alpha_id.name_length = ((U8) mmi_ucs2strlen((S8*) record->pbName)) * ENCODING_LENGTH;
                InputboxConvertDeviceEncodingToGSM(
                    (PU8) record->pbName,
                    dataPtr->entry.alpha_id.name,
                    MAX_PS_NAME_LENGTH,
                    MMI_PHB_UCS2,
                    0,
                    1);
            }
        }
        else
        {
            dataPtr->entry.alpha_id.name_dcs = MMI_PHB_ASCII;
            dataPtr->entry.alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8) record->pbName,
                                                dataPtr->entry.alpha_id.name,
                                                MAX_PS_NAME_LENGTH,
                                                MMI_PHB_ASCII,
                                                0,
                                                1) - 1;
        }
    }

    ConvertMYTIME2RTC(&dataPtr->entry.time, &record->startTime);
    dataPtr->entry.count = (U8) record->no_of_times;
    dataPtr->entry.call_duration = (kal_int32)mmi_dt_mytime_2_utc_sec(&record->duration, MMI_FALSE);

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;
    SetProtocolEventHandler(RspUpdateCallLogName, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  RspUpdateCallLogName
 * DESCRIPTION
 *  Response handler for update call log data
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspUpdateCallLogName(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  ReqDeleteCallLog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  index       [IN]        
 *  no_data     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ReqDeleteCallLog(U8 type, U8 index, U8 no_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    DEL_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    switch (type)
    {
        case PHB_LND:
            SetProtocolEventHandler(RspDeleteDialedNum, PRT_MMI_PHB_DEL_LAST_NUMBER_RSP);
            break;
        case PHB_LNM:
            SetProtocolEventHandler(RspDeleteMissedNum, PRT_MMI_PHB_DEL_LAST_NUMBER_RSP);
            break;
        case PHB_LNR:
            SetProtocolEventHandler(RspDeleteRecvdNum, PRT_MMI_PHB_DEL_LAST_NUMBER_RSP);
            break;
        default:
            return;
    }

    dataPtr = (DEL_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(DEL_LAST_NUMBER_REQ));
    dataPtr->type = type;
    dataPtr->index = index;
    dataPtr->no_data = no_data;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_DEL_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    ClearInputEventHandler(MMI_DEVICE_ALL);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspDeleteDialedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspDeleteDialedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    DEL_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (DEL_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        for (i = chis_p->currDialedCallIndex; i < (chis_p->nDialedCalls - 1); i++)
        {
            memcpy(&chis_p->dialedCalls[i], &chis_p->dialedCalls[i + 1], sizeof(DIALED_CALL));
        }
        chis_p->nDialedCalls--;
        if ((chis_p->currDialedCallIndex >= chis_p->nDialedCalls) && (chis_p->nDialedCalls != 0))
        {
            chis_p->currDialedCallIndex = chis_p->nDialedCalls - 1;
        }

        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    if (chis_p->nDialedCalls == 0)
    {
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        if (!IsScreenPresent(SCR8055_CALLS_LIST_DIALED))
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
            DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
    #else 
            DeleteBetweenScreen(SCR8008_CALL_DIALED, SCR8009_DIALED_CALL_OPTIONS);
    #endif 
        else
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
            DeleteBetweenScreen(SCR8055_CALLS_LIST_DIALED, SCR8009_DIALED_CALL_OPTIONS);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
#else 
        DeleteBetweenScreen(SCR8008_CALL_DIALED, SCR8009_DIALED_CALL_OPTIONS);
#endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqReadMissedNumByKey
 * DESCRIPTION
 *  Read missed call data when enter menu
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void ReqReadMissedNumByKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isReqSent == TRUE)
    {
        return;
    }
    if (chis_p->isCallLogReady == TRUE && chis_p->isFirstTime == FALSE)
    {
        /* ready and auto read call log is done */
        ReqReadMissedNum();
        chis_p->isReqSent = TRUE;
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8055_CAPTION,
            IMG_SCR8055_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqReadMissedNum
 * DESCRIPTION
 *  Read missed call log from protocol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqReadMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    GET_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntryCHISTViewMissedCallList();
        return;
    }
    #ifndef __MMI_CH_MIXED_CALL_LOG__
        chis_p->missedCalls = (LOG_CALL*) chis_p->callsLog;
    #endif 
    chis_p->saveMissedScrn = FALSE;

    dataPtr = (GET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(GET_LAST_NUMBER_REQ));
    dataPtr->type = PHB_LNM;
    if (chis_p->sequenceId == 0)
    {
        chis_p->sequenceId = 1;
    }
    dataPtr->seq_id = chis_p->sequenceId;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_GET_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

/* only the first sequence will clear all key handler */
    if (chis_p->isFirstTime == FALSE && chis_p->sequenceId == 1)
    {
        AlmDisableExpiryHandler();
#ifdef __MMI_CH_MIXED_CALL_LOG__
        if (chis_p->isMixedStyle == FALSE)
#endif
            ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    SetProtocolEventHandler(RspReadMissedNum, PRT_MMI_PHB_GET_LAST_NUMBER_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspReadMissedNum
 * DESCRIPTION
 *  Receives missed call log from protocol
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspReadMissedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GET_LAST_NUMBER_RSP *rsp;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (GET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        if (rsp->type != PHB_LNM)
        {
            return;
        }

        if (chis_p->sequenceId == 1)
        {
            chis_p->nMissedCalls = 0;
            memset((PS8) chis_p->missedCalls, 0, sizeof(LOG_CALL) * TOT_SIZE_OF_ONE_LN_LIST);
        }
        for (index = 0; index < rsp->no_list; index++)
        {
            CHISTExtractPSCallLog(&chis_p->missedCalls[chis_p->nMissedCalls], &rsp->list[index]);
            chis_p->nMissedCalls++;
        }
        if (rsp->more_data && rsp->no_list == TOT_SIZE_OF_ONE_LN_LIST)
        {
            chis_p->sequenceId++;
            ASSERT(chis_p->sequenceId < 11);
            ReqReadMissedNum();
            return;
        }
    }
    chis_p->sequenceId = 0;

#ifndef __MMI_CH_MIXED_CALL_LOG__
    if (chis_p->isFirstTime == TRUE)
#else 
    if (chis_p->isFirstTime == TRUE || chis_p->isMixedStyle == TRUE)
#endif 
    {
        ReqReadRecvdNum();
        return;
    }

    chis_p->isReqSent = FALSE;
    EntryCHISTViewMissedCallList();
    AlmEnableExpiryHandler();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspWriteMissedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspWriteMissedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SET_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (SET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        PRINT_INFORMATION("CHISTLogMissedCall Rsp: show status icon");
        /* set g_chist_have_missed_num */
        g_chist_have_missed_call = 1;
        mmi_chist_set_have_missed_call();
        IdleSetStatusIcon(STATUS_ICON_MISSED_CALL);
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        /* for new sublcd statusicons */
        IdleSetStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif
        if (chis_p->nMissedCalls < TOT_SIZE_OF_MISSED_LIST)
        {
        #if (TOT_SIZE_OF_MISSED_LIST <= 20)
            chis_p->nMissedCalls = (U8) rsp->no_list;
        #else 
            chis_p->nMissedCalls++;
        #endif 
        }
    }

#ifdef __MMI_CH_MIXED_CALL_LOG__
    if (chis_p->process == CALL_LOG_PROC_SYNC && chis_p->isMixedStyle == TRUE)
    {
        PRINT_INFORMATION("set missed rsp comes before read rsp!!!! re-sync.");
        chis_p->process = CALL_LOG_PROC_NONE;
        CHISTGetCallLogBySENDKey();
    }
    chis_p->process = CALL_LOG_PROC_NONE;
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspDeleteMissedNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspDeleteMissedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    DEL_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (DEL_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        for (i = chis_p->currMissedCallIndex; i < (chis_p->nMissedCalls - 1); i++)
        {
            memcpy(&chis_p->missedCalls[i], &chis_p->missedCalls[i + 1], sizeof(MISSED_CALL));
        }
        chis_p->nMissedCalls--;
        if ((chis_p->currMissedCallIndex >= chis_p->nMissedCalls) && (chis_p->nMissedCalls != 0))
        {
            chis_p->currMissedCallIndex = chis_p->nMissedCalls - 1;
        }

        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    if (chis_p->nMissedCalls == 0)
    {
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        if (!IsScreenPresent(SCR8056_CALLS_LIST_MISSED))
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
            DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
    #else 
            DeleteBetweenScreen(SCR8520_CALL_MISSED, SCR8521_MISSED_CALL_OPTIONS);
    #endif 
        else
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
            DeleteBetweenScreen(SCR8056_CALLS_LIST_MISSED, SCR8521_MISSED_CALL_OPTIONS);
        chis_p->nMissedCallBeforeView = 0;
    #ifdef __MMI_DUAL_SIM_MASTER__
        DeleteScreenIfPresent(SCR_MTPNP_CALL_HISTORY_NOTIFY);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        g_chist_have_missed_call = 0;
    	mmi_chist_set_have_missed_call();
        IdleResetStatusIcon(STATUS_ICON_MISSED_CALL);
        /* Add two new statusicons on sublcd */
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        IdleResetStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif 
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
#else 
        DeleteBetweenScreen(SCR8520_CALL_MISSED, SCR8521_MISSED_CALL_OPTIONS);
#endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqReadRecvdNumByKey
 * DESCRIPTION
 *  Read recvd call data when enter menu
 * PARAMETERS
 *  void
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void ReqReadRecvdNumByKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isReqSent == TRUE)
    {
        return;
    }
    if (chis_p->isCallLogReady == TRUE && chis_p->isFirstTime == FALSE)
    {
        /* ready and auto read call log is done */
        ReqReadRecvdNum();
        chis_p->isReqSent = TRUE;
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8054_CAPTION,
            IMG_SCR8054_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ReqReadRecvdNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReqReadRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    GET_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntryCHISTViewRecvdCallList();
        return;
    }
#ifndef __MMI_CH_MIXED_CALL_LOG__
    chis_p->recvdCalls = (LOG_CALL*) chis_p->callsLog;
#endif 

    dataPtr = (GET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(GET_LAST_NUMBER_REQ));
    dataPtr->type = PHB_LNR;
    if (chis_p->sequenceId == 0)
    {
        chis_p->sequenceId = 1;
    }
    dataPtr->seq_id = chis_p->sequenceId;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_GET_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

/* only the first sequence will clear all key handler */
    if (chis_p->isFirstTime == FALSE && chis_p->sequenceId == 1)
    {
        AlmDisableExpiryHandler();
#ifdef __MMI_CH_MIXED_CALL_LOG__
        if (chis_p->isMixedStyle == FALSE)
#endif
            ClearInputEventHandler(MMI_DEVICE_ALL);
    }

    SetProtocolEventHandler(RspReadRecvdNum, PRT_MMI_PHB_GET_LAST_NUMBER_RSP);
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspReadRecvdNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspReadRecvdNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GET_LAST_NUMBER_RSP *rsp;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (GET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        if (rsp->type != PHB_LNR)
        {
            return;
        }
        if (chis_p->sequenceId == 1)
        {
            chis_p->nRecvdCalls = 0;
            memset((PS8) chis_p->recvdCalls, 0, sizeof(LOG_CALL) * TOT_SIZE_OF_ONE_LN_LIST);
        }
        for (index = 0; index < rsp->no_list; index++)
        {
            CHISTExtractPSCallLog(&chis_p->recvdCalls[chis_p->nRecvdCalls], &rsp->list[index]);
            chis_p->nRecvdCalls++;
        }
        if (rsp->more_data  && rsp->no_list == TOT_SIZE_OF_ONE_LN_LIST)
        {
            chis_p->sequenceId++;
            ASSERT(chis_p->sequenceId < 11);
            ReqReadRecvdNum();
            return;
        }
    }

    chis_p->sequenceId = 0;
    if (chis_p->isFirstTime == TRUE)
    {
        chis_p->isFirstTime = FALSE;
        return;
    }

    chis_p->isReqSent = FALSE;

#ifdef __MMI_CH_MIXED_CALL_LOG__
    if (chis_p->isMixedStyle == TRUE)
    {
#if defined(NOKE_DEBUG)
    	noke_dbg_printf("\r\nHuyanwei Debug  For  SIM 1 Call Log ......\r\n");
#endif
        CHISTSortCallLogsByTime();
        EntryCHISTViewMixedCallList();
        AlmEnableExpiryHandler();
        chis_p->isMixedStyle = FALSE;
        return;
    }
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

    EntryCHISTViewRecvdCallList();
    AlmEnableExpiryHandler();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspWriteRecvdNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspWriteRecvdNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SET_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (SET_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK && chis_p->nRecvdCalls < TOT_SIZE_OF_RECVD_LIST)
    {
    #if (TOT_SIZE_OF_RECVD_LIST <= 20)
        chis_p->nRecvdCalls = (U8) rsp->no_list;
    #else 
        chis_p->nRecvdCalls++;
    #endif 
    }

#ifdef __MMI_CH_MIXED_CALL_LOG__
    if (chis_p->process == CALL_LOG_PROC_SYNC && chis_p->isMixedStyle == TRUE)
    {
        PRINT_INFORMATION("set recvd rsp comes before read rsp!!!! re-sync.");
        chis_p->process = CALL_LOG_PROC_NONE;
        CHISTGetCallLogBySENDKey();
    }
    chis_p->process = CALL_LOG_PROC_NONE;
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspDeleteRecvdNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspDeleteRecvdNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    DEL_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (DEL_LAST_NUMBER_RSP*) info;

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        for (i = chis_p->currRecvdCallIndex; i < (chis_p->nRecvdCalls - 1); i++)
        {
            memcpy(&chis_p->recvdCalls[i], &chis_p->recvdCalls[i + 1], sizeof(RECEIVED_CALL));
        }
        chis_p->nRecvdCalls--;
        if ((chis_p->currRecvdCallIndex >= chis_p->nRecvdCalls) && (chis_p->nRecvdCalls != 0))
        {
            chis_p->currRecvdCallIndex = chis_p->nRecvdCalls - 1;
        }

        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    if (chis_p->nRecvdCalls == 0)
    {
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        if (!IsScreenPresent(SCR8054_CALLS_LIST_RECEIVED))
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
            DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
    #else 
            DeleteBetweenScreen(SCR8006_CALL_RECEIVED, SCR8007_RECEIVED_CALL_OPTIONS);
    #endif 
        else
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
            DeleteBetweenScreen(SCR8054_CALLS_LIST_RECEIVED, SCR8007_RECEIVED_CALL_OPTIONS);
    }
    else
#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
#else 
        DeleteBetweenScreen(SCR8006_CALL_RECEIVED, SCR8007_RECEIVED_CALL_OPTIONS);
#endif 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspWriteNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspWriteNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SET_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (SET_LAST_NUMBER_RSP*) info;
    switch(rsp->type)
    {
        case PHB_LND:
            RspWriteDialedNum(info);
            break;
        case PHB_LNM:
            RspWriteMissedNum(info);
            break;            
        case PHB_LNR:
            RspWriteRecvdNum(info);
            break;                      
    }    
}


/*****************************************************************************
 * FUNCTION
 *  CHISTDeleteDialedNum
 * DESCRIPTION
 *  To delete the current active dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTDeleteDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReqDeleteCallLog(PHB_LND, chis_p->currDialedCallIndex, 1);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSaveDialedNum
 * DESCRIPTION
 *  To save the dialed number into the
 *  phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSaveDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->curCallLogType = PHB_LND;
    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].number[0] == 0)
    {
        /* no name, number is in name field for display */
        SaveNumberFromIdleScrn(
            (S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName,
            MMI_PHB_ENTER_FROM_CALL_LOG);
    }
#ifdef __MMI_VOIP__
    else if (chis_p->dialedCalls[chis_p->currDialedCallIndex].address_type == PHB_LN_VOIP)
    {
        mmi_phb_save_entry_for_service_field(
            (S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName,
            (S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number,
            MMI_PHB_ENTER_FROM_VOIP);
    }
#endif /* __MMI_VOIP__ */
    else
    {
        SaveNumberFromIdleScrn(
            (S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number,
            MMI_PHB_ENTER_FROM_CALL_LOG);
    }
    return;
}


#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  CHISTCallDialedNumByIP
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallDialedNumByIP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetTempUseIPNumber(TRUE);
    CHISTCallDialedNum();
}
#endif /* __IP_NUMBER__ */ 


/*****************************************************************************
 * FUNCTION
 *  CHISTCallDialedNum
 * DESCRIPTION
 *  To make a call to dialed list entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addToHistory = 0;

    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].number[0] == 0)
    {
        /* no name, number is in name field for display */
        if (chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_DIALED_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR8009_DIALED_CALL_OPTIONS)
            {
                mmi_ucm_app_entry_dial_option((U8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName, mmi_chist_call_dialed_num_cbk, NULL);
            }
            else
        #endif
            {
                MakeCall((S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName);
                mmi_chist_call_dialed_num_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_DIALED_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR8009_DIALED_CALL_OPTIONS)
        {
            mmi_ucm_app_entry_dial_option((U8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number, mmi_chist_call_dialed_num_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (chis_p->dialedCalls[chis_p->currDialedCallIndex].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number);
            }
            mmi_chist_call_dialed_num_cbk(NULL);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_call_dialed_num_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_call_dialed_num_cbk(void *p)
{
    DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
    DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    DeleteScreenIfPresent(SCR8055_CALLS_LIST_DIALED);
#ifdef __MMI_CH_MIXED_CALL_LOG__    
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
    DeleteScreenIfPresent(SCR_ID_CHIST_DUAL_CARD_MIXED_CALLLOG);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  CHISTEditDialedNum
 * DESCRIPTION
 *  To Edit the current active Dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTEditDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].number[0] == 0)
    {
        DisplayPopup((PU8) GetString(ERROR_UNRECOGNIZED_NUMBER), IMG_GLOBAL_ERROR, 1, CS_NOTIFYDURATION, ERROR_TONE);
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        if (!IsScreenPresent(SCR8055_CALLS_LIST_DIALED))
        {
            DeleteUptoScrID(SCR8057_CALLS_LIST_MIXED);
        }
        else
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
            DeleteUptoScrID(SCR8055_CALLS_LIST_DIALED);
    }
    else
    {
        mmi_ucs2cpy(
            g_idle_context.DialPadCallBuffer,
            (S8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number);
        g_idle_context.LongPressEnable = 1;
        IdleScreenDigitHandler();
    }
}


#ifdef __MMI_CH_OPTIONS_SENDSMS__
/*****************************************************************************
 * FUNCTION
 *  CHISTSendSMSDialedNum
 * DESCRIPTION
 *  To Send SMS for the current active Dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSendSMSDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[MAX_CC_ADDR_LEN + 1];
    S32 name_length = 0, number_length = 0;
    mmi_frm_sms_api_entry_write_struct sendData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check SMS re-entering */
    if (IsMessagesReEntering())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    /* set interface for SMS */
    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

    name_length = mmi_ucs2strlen((PS8)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName));
    number_length = mmi_ucs2strlen((PS8)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].number));

    memset(number, 0, (MAX_CC_ADDR_LEN + 1));
    /* set name & number */
    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].number[0] == 0)
    {
        if (name_length <= MAX_CC_ADDR_LEN)
        {
            mmi_ucs2_n_to_asc((S8*)number, (S8*)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName), name_length * ENCODING_LENGTH);
            number_length = name_length;
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
        }
    }
    else
    {
        mmi_ucs2_n_to_asc((S8*)number, (S8*)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].number), number_length * ENCODING_LENGTH);
    }

    if (number_length == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
    }
    else
    {
        memset(&sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

        sendData.string = NULL;
        sendData.stringlength = 0;
        sendData.dcs = 0;
        sendData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
        sendData.ascii_addr = (U8*) number;

        mmi_frm_sms_api_entry_write_msg(&sendData);
    }
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_SENDMMS__
/*****************************************************************************
 * FUNCTION
 *  CHISTSendMMSDialedNum
 * DESCRIPTION
 *  To Send MMS for the current active Dialed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSendMMSDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[(MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH];
    S32 name_length = 0, number_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT
    name_length = mmi_ucs2strlen((PS8)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName));
    number_length = mmi_ucs2strlen((PS8)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].number));

    /* set number */
    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].number[0] == 0)
    {
        mmi_ucs2ncpy((S8*)number, (S8*)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName), name_length);
        number_length = name_length;
    }
    else
    {
        mmi_ucs2ncpy((S8*)number, (S8*)((U8*)chis_p->dialedCalls[chis_p->currDialedCallIndex].number), number_length);
    }

    /* check number */
    if (number_length <= MAX_PB_NUMBER_LENGTH)
    {
        if (number_length == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                IMG_GLOBAL_UNFINISHED,
                1,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
        }
        else
        {
            mms_address_insert_hdlr((char*)number);
        }
    }
    else
#endif
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
    }

    return ;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */


/*****************************************************************************
 * FUNCTION
 *  CHISTDeleteMissedNum
 * DESCRIPTION
 *  To delete the current active missed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTDeleteMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = chis_p->currMissedCallIndex;
    ReqDeleteCallLog(PHB_LNM, (U8) (index + (chis_p->nMissedCalls - nMissedCallNumBkp)), 1);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSaveMissedNum
 * DESCRIPTION
 *  To save the missed number into the
 *  phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSaveMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->curCallLogType = PHB_LNM;
    if (chis_p->missedCalls[chis_p->currMissedCallIndex].number[0] == 0)
    {
        SaveNumberFromIdleScrn(
            (S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].pbName,
            MMI_PHB_ENTER_FROM_CALL_LOG);
    }
#ifdef __MMI_VOIP__
    else if (chis_p->missedCalls[chis_p->currMissedCallIndex].address_type == PHB_LN_VOIP)
    {
        mmi_phb_save_entry_for_service_field(
        (S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].pbName,
        (S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].number,
        MMI_PHB_ENTER_FROM_VOIP);
    }
#endif /* __MMI_VOIP__ */
    else
    {
        SaveNumberFromIdleScrn(
            (S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].number,
            MMI_PHB_ENTER_FROM_CALL_LOG);
    }
    return;
}

#ifdef __IP_NUMBER__


/*****************************************************************************
 * FUNCTION
 *  CHISTCallMissedNumByIP
 * DESCRIPTION
 *  Use IP dialing to call a missed number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallMissedNumByIP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetTempUseIPNumber(TRUE);
    CHISTCallMissedNum();
}
#endif /* __IP_NUMBER__ */ 


/*****************************************************************************
 * FUNCTION
 *  CHISTCallMissedNum
 * DESCRIPTION
 *  To make a call to missed list entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addToHistory = 0;

    if (chis_p->missedCalls[chis_p->currMissedCallIndex].number[0] == 0)
    {
        if (chis_p->missedCalls[chis_p->currMissedCallIndex].pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_MISSED_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR8521_MISSED_CALL_OPTIONS)
            {
                mmi_ucm_app_entry_dial_option((U8*) chis_p->missedCalls[chis_p->currMissedCallIndex].pbName, mmi_chist_call_missed_num_cbk, NULL);
            }
            else                
        #endif
            {
                MakeCall((S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].pbName);
                mmi_chist_call_missed_num_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_MISSED_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR8521_MISSED_CALL_OPTIONS)
        {
            mmi_ucm_app_entry_dial_option((U8*) chis_p->missedCalls[chis_p->currMissedCallIndex].number, mmi_chist_call_missed_num_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (chis_p->missedCalls[chis_p->currMissedCallIndex].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) chis_p->missedCalls[chis_p->currMissedCallIndex].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].number);
            }
            mmi_chist_call_missed_num_cbk(NULL);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_call_missed_num_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_call_missed_num_cbk(void *p)
{
    DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
    DeleteScreenIfPresent(SCR8520_CALL_MISSED);
    DeleteScreenIfPresent(SCR8056_CALLS_LIST_MISSED);
#ifdef __MMI_CH_MIXED_CALL_LOG__    
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */
}


/*****************************************************************************
 * FUNCTION
 *  CHISTEditMissedNum
 * DESCRIPTION
 *  To Edit the current active Missed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTEditMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->missedCalls[chis_p->currMissedCallIndex].number[0] == 0)
    {
        DisplayPopup((PU8) GetString(ERROR_UNRECOGNIZED_NUMBER), IMG_GLOBAL_ERROR, 1, CS_NOTIFYDURATION, ERROR_TONE);
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        if (!IsScreenPresent(SCR8056_CALLS_LIST_MISSED))
        {
            DeleteUptoScrID(SCR8057_CALLS_LIST_MIXED);
        }
        else
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
            DeleteUptoScrID(SCR8056_CALLS_LIST_MISSED);
    }
    else
    {
        mmi_ucs2cpy(
            g_idle_context.DialPadCallBuffer,
            (S8*) chis_p->missedCalls[chis_p->currMissedCallIndex].number);
        g_idle_context.LongPressEnable = 1;
        IdleScreenDigitHandler();
    }
}


#ifdef __MMI_CH_OPTIONS_SENDSMS__
/*****************************************************************************
 * FUNCTION
 *  CHISTSendSMSMissedNum
 * DESCRIPTION
 *  To Send SMS for the current active Missed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSendSMSMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[MAX_CC_ADDR_LEN + 1];
    S32 name_length = 0, number_length = 0;
    mmi_frm_sms_api_entry_write_struct sendData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check SMS re-entering */
    if (IsMessagesReEntering())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    /* set interface for SMS */
    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

    name_length = mmi_ucs2strlen((PS8)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].pbName));
    number_length = mmi_ucs2strlen((PS8)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].number));

    memset(number, 0, (MAX_CC_ADDR_LEN + 1));
    /* set name & number */
    if (chis_p->missedCalls[chis_p->currMissedCallIndex].number[0] == 0)
    {
        if (name_length <= MAX_CC_ADDR_LEN)
        {
            mmi_ucs2_n_to_asc((S8*)number, (S8*)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].pbName), name_length * ENCODING_LENGTH);
            number_length = name_length;
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
        }
    }
    else
    {
        mmi_ucs2_n_to_asc((S8*)number, (S8*)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].number), number_length * ENCODING_LENGTH);
    }

    if (number_length == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
    }
    else
    {
        memset(&sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

        sendData.string = NULL;
        sendData.stringlength = 0;
        sendData.dcs = 0;
        sendData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
        sendData.ascii_addr = (U8*) number;

        mmi_frm_sms_api_entry_write_msg(&sendData);
    }
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_SENDMMS__
/*****************************************************************************
 * FUNCTION
 *  CHISTSendMMSMissedNum
 * DESCRIPTION
 *  To Send MMS for the current active Missed call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSendMMSMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[(MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH];
    S32 name_length = 0, number_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT

    name_length = mmi_ucs2strlen((PS8)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].pbName));
    number_length = mmi_ucs2strlen((PS8)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].number));

    /* set number */
    if (chis_p->missedCalls[chis_p->currMissedCallIndex].number[0] == 0)
    {
        mmi_ucs2ncpy((S8*)number, (S8*)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].pbName), name_length);
        number_length = name_length;
    }
    else
    {
        mmi_ucs2ncpy((S8*)number, (S8*)((U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].number), number_length);
    }

    /* check number */
    if (number_length <= MAX_PB_NUMBER_LENGTH)
    {
        if (number_length == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                IMG_GLOBAL_UNFINISHED,
                1,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
        }
        else
        {
            mms_address_insert_hdlr((char*)number);
        }
    }
    else
#endif
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
    }

    return ;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */


/*****************************************************************************
 * FUNCTION
 *  CHISTDeleteRecvdNum
 * DESCRIPTION
 *  To delete the current active recvd call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTDeleteRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReqDeleteCallLog(PHB_LNR, chis_p->currRecvdCallIndex, 1);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSaveRecvdNum
 * DESCRIPTION
 *  To save the recvd number into the
 *  phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSaveRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->curCallLogType = PHB_LNR;
    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].number[0] == 0)
    {
        SaveNumberFromIdleScrn(
            (S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName,
            MMI_PHB_ENTER_FROM_CALL_LOG);
    }
#ifdef __MMI_VOIP__
    else if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].address_type == PHB_LN_VOIP)
    {
        mmi_phb_save_entry_for_service_field(
        (S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName,
        (S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number,
        MMI_PHB_ENTER_FROM_VOIP);
    }
#endif /* __MMI_VOIP__ */
    else
    {
        SaveNumberFromIdleScrn(
            (S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number,
            MMI_PHB_ENTER_FROM_CALL_LOG);
    }
    return;
}

#ifdef __IP_NUMBER__


/*****************************************************************************
 * FUNCTION
 *  CHISTCallRecvdNumByIP
 * DESCRIPTION
 *  Use IP dialing to call a recvd number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallRecvdNumByIP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetTempUseIPNumber(TRUE);
    CHISTCallRecvdNum();
}
#endif /* __IP_NUMBER__ */ 


/*****************************************************************************
 * FUNCTION
 *  CHISTCallRecvdNum
 * DESCRIPTION
 *  To make a call to recvd list entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addToHistory = 0;

    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].number[0] == 0)
    {
        if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_RECVD_CALL;
        #ifdef __MMI_UCM__
            if (GetExitScrnID() == SCR8007_RECEIVED_CALL_OPTIONS)
            {       
                mmi_ucm_app_entry_dial_option((U8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName, mmi_chist_call_recvd_num_cbk, NULL);
            }
            else               
        #endif
            {
                MakeCall((S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName);
                mmi_chist_call_recvd_num_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_RECVD_CALL;
    #ifdef __MMI_UCM__
        if (GetExitScrnID() == SCR8007_RECEIVED_CALL_OPTIONS)
        { 
            mmi_ucm_app_entry_dial_option((U8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number, mmi_chist_call_recvd_num_cbk, NULL);
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number);
            }
            mmi_chist_call_recvd_num_cbk(NULL);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_call_recvd_num_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_call_recvd_num_cbk(void *p)
{
    DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
    DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);
    DeleteScreenIfPresent(SCR8054_CALLS_LIST_RECEIVED);
#ifdef __MMI_CH_MIXED_CALL_LOG__    
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  CHISTEditRecvdNum
 * DESCRIPTION
 *  To Edit the current active Recvd call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTEditRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].number[0] == 0)
    {
        DisplayPopup((PU8) GetString(ERROR_UNRECOGNIZED_NUMBER), IMG_GLOBAL_ERROR, 1, CS_NOTIFYDURATION, ERROR_TONE);
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        if (!IsScreenPresent(SCR8054_CALLS_LIST_RECEIVED))
        {
            DeleteUptoScrID(SCR8057_CALLS_LIST_MIXED);
        }
        else
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
            DeleteUptoScrID(SCR8054_CALLS_LIST_RECEIVED);
    }
    else
    {
        mmi_ucs2cpy(
            g_idle_context.DialPadCallBuffer,
            (S8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number);
        g_idle_context.LongPressEnable = 1;
        IdleScreenDigitHandler();
    }
}


#ifdef __MMI_CH_OPTIONS_SENDSMS__
/*****************************************************************************
 * FUNCTION
 *  CHISTSendSMSRecvdNum
 * DESCRIPTION
 *  To Send SMS for the current active Recvd call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSendSMSRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[MAX_CC_ADDR_LEN + 1];
    S32 name_length = 0, number_length = 0;
    mmi_frm_sms_api_entry_write_struct sendData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check SMS re-entering */
    if (IsMessagesReEntering())
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
        return;
    }

    /* set interface for SMS */
    mmi_msg_set_phb_send_case(MMI_SEND_SMS_FROM_PHB);

    name_length = mmi_ucs2strlen((PS8)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName));
    number_length = mmi_ucs2strlen((PS8)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].number));

    memset(number, 0, (MAX_CC_ADDR_LEN + 1));
    /* set name & number */
    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].number[0] == 0)
    {
        if (name_length <= MAX_CC_ADDR_LEN)
        {
            mmi_ucs2_n_to_asc((S8*)number, (S8*)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName), name_length * ENCODING_LENGTH);
			number_length = name_length;
        }
		else
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
                IMG_GLOBAL_UNFINISHED,
                1,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
        }
    }
    else
    {
        mmi_ucs2_n_to_asc((S8*)number, (S8*)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].number), number_length * ENCODING_LENGTH);
    }

    if (number_length == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
    }
    else
    {
        memset(&sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));

        sendData.string = NULL;
        sendData.stringlength = 0;
        sendData.dcs = 0;
        sendData.flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
        sendData.ascii_addr = (U8*) number;

        mmi_frm_sms_api_entry_write_msg(&sendData);
    }
    return;
}
#endif /* __MMI_CH_OPTIONS_SENDSMS__ */


#ifdef __MMI_CH_OPTIONS_SENDMMS__
/*****************************************************************************
 * FUNCTION
 *  CHISTSendMMSRecvdNum
 * DESCRIPTION
 *  To Send MMS for the current active Recvd call entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSendMMSRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 number[(MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH];
    S32 name_length = 0, number_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WAP_SUPPORT

    name_length = mmi_ucs2strlen((PS8)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName));
    number_length = mmi_ucs2strlen((PS8)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].number));

    /* set number */
    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].number[0] == 0)
    {
        mmi_ucs2ncpy((S8*)number, (S8*)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName), name_length);
        number_length = name_length;
    }
    else
    {
        mmi_ucs2ncpy((S8*)number, (S8*)((U8*)chis_p->recvdCalls[chis_p->currRecvdCallIndex].number), number_length);
    }

    /* check number */
    if (number_length <= MAX_PB_NUMBER_LENGTH)
    {
        if (number_length == 0)
        {
            DisplayPopup(
                (PU8) GetString(STR_SMS_NUM_CANNOT_BE_EMPTY),
                IMG_GLOBAL_UNFINISHED,
                1,
                PHB_NOTIFY_TIMEOUT,
                (U8) ERROR_TONE);
        }
        else
        {
            mms_address_insert_hdlr((char*)number);
        }
    }
    else
#endif
    {
        DisplayPopup(
            (PU8) GetString(STR_SMS_NUM_LEN_EXCEEDED),
            IMG_GLOBAL_UNFINISHED,
            1,
            PHB_NOTIFY_TIMEOUT,
            (U8) ERROR_TONE);
    }

    return ;
}
#endif /* __MMI_CH_OPTIONS_SENDMMS__ */


/*****************************************************************************
 * FUNCTION
 *  CHISTPopulateDialedCallList
 * DESCRIPTION
 *  To fill in the array of numbers/names
 *  to show dialed call list.
 * PARAMETERS
 *  numberList      [?]     
 *  phoneList       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTPopulateDialedCallList(U8 *numberList[], U8 *phoneList[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < chis_p->nDialedCalls; index++)
    {
        if (chis_p->dialedCalls[index].nameLength > 0)
        {
            phoneList[index] = (U8*) chis_p->dialedCalls[index].pbName;
            numberList[index] = (U8*) chis_p->dialedCalls[index].number;
        }
        else
        {
            if (chis_p->dialedCalls[index].number[0] != 0)
            {
                phoneList[index] = (U8*) chis_p->dialedCalls[index].number;
            }
            else
            {
                phoneList[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
            }
            numberList[index] = NULL;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTPopulateMissedCallList
 * DESCRIPTION
 *  To fill in the array of numbers/names
 *  to show missed call list.
 * PARAMETERS
 *  numberList      [?]     
 *  phoneList       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTPopulateMissedCallList(U8 *numberList[], U8 *phoneList[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < chis_p->nMissedCalls; index++)
    {
        if (chis_p->missedCalls[index].nameLength > 0)
        {
            phoneList[index] = (U8*) chis_p->missedCalls[index].pbName;
            if (chis_p->missedCalls[index].number && mmi_ucs2strlen((S8*)chis_p->missedCalls[index].number) > 0)
            {
                numberList[index] = (U8*) chis_p->missedCalls[index].number;
            }
            else
            {
                numberList[index] = NULL;
            }
        }
        else
        {
            if (chis_p->missedCalls[index].number[0] != 0)
            {
                phoneList[index] = (U8*) chis_p->missedCalls[index].number;
            }
            else
            {
                phoneList[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
            }
            numberList[index] = NULL;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTPopulateRecvdCallList
 * DESCRIPTION
 *  To fill in the array of numbers/names
 *  to show recvd call list.
 * PARAMETERS
 *  numberList      [?]     
 *  phoneList       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTPopulateRecvdCallList(U8 *numberList[], U8 *phoneList[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < chis_p->nRecvdCalls; index++)
    {
        if (chis_p->recvdCalls[index].nameLength > 0)
        {
            phoneList[index] = (U8*) chis_p->recvdCalls[index].pbName;
            if (chis_p->recvdCalls[index].number && mmi_ucs2strlen((S8*)chis_p->recvdCalls[index].number) > 0)
            {
                numberList[index] = (U8*) chis_p->recvdCalls[index].number;
            }
            else
            {
                numberList[index] = NULL;
            }
        }
        else
        {
            if (chis_p->recvdCalls[index].number[0] != 0)
            {
                phoneList[index] = (U8*) chis_p->recvdCalls[index].number;
            }
            else
            {
                phoneList[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
            }
            numberList[index] = NULL;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCurrDialedCallIndex
 * DESCRIPTION
 *  To set the current active call item
 * PARAMETERS
 *  ind     [IN]        Index into list of call entries
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCurrDialedCallIndex(S32 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->currDialedCallIndex = (U8) ind;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCurrMissedCallIndex
 * DESCRIPTION
 *  To set the current active call item
 * PARAMETERS
 *  ind     [IN]        Index into list of call entries
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCurrMissedCallIndex(S32 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->currMissedCallIndex = (U8) ind;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCurrRecvdCallIndex
 * DESCRIPTION
 *  To set the current active call item
 * PARAMETERS
 *  ind     [IN]        Index into list of call entries
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCurrRecvdCallIndex(S32 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->currRecvdCallIndex = (U8) ind;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTResetCallLogIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTResetCallLogIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->currCostItem = 0;
    chis_p->currDialedCallIndex = 0;
    chis_p->currMissedCallIndex = 0;
    chis_p->currRecvdCallIndex = 0;
#ifdef __MMI_CH_MIXED_CALL_LOG__
    chis_p->currMixedCallIndex = 0;
#endif 
#ifdef __MMI_DUAL_SIM_MASTER__
    GetSlaveCurrDialedCallHISIndex(0);
    GetSlaveCurrRecvdCallHISIndex(0);
    GetSlaveCurrMissedCallHISIndex(0);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTLogDialedCall
 * DESCRIPTION
 *  To make an entry into dialed call list
 *  
 *  GetDateTime
 * PARAMETERS
 *  call        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTLogDialedCall(CALL_INFO *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    CHISTDeleteTabPaneScreen();
#else
    DeleteScreenIfPresent(SCR8055_CALLS_LIST_DIALED);
#ifdef __MMI_CH_MIXED_CALL_LOG__
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif
    DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
    ReqWriteCallLog(call, PHB_LND);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_log_call_duration
 * DESCRIPTION
 *  To log call duration
 *  
 *  GetDateTime
 * PARAMETERS
 *  call        [IN]     
 *  type        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_log_call_duration(CALL_INFO *call, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    kal_uint16 start_lid;
    nvram_ef_phb_ln_struct *temp_call_log;
    MYTIME start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == PHB_LND)
    {
        start_lid = 1;
    }
    else if (type == PHB_LNR)
    {
        start_lid = 1 + ((TOT_SIZE_OF_DIALED_LIST + TOT_SIZE_OF_ONE_LN_LIST -1)/TOT_SIZE_OF_ONE_LN_LIST) +
                    ((TOT_SIZE_OF_DIALED_LIST + TOT_SIZE_OF_ONE_LN_LIST -1)/TOT_SIZE_OF_ONE_LN_LIST);
    }
    else
    {
        return;
    }
    temp_call_log = OslMalloc(NVRAM_EF_PHB_LN_ENTRY_SIZE);
    if (temp_call_log)
    {
        int i;
        S8 *ucs2_number = OslMalloc((MAX_PB_NUMBER_LENGTH+1+1)* ENCODING_LENGTH);
        ReadRecord(NVRAM_EF_PHB_LN_ENTRY_LID, start_lid, temp_call_log, NVRAM_EF_PHB_LN_ENTRY_SIZE, &error);
        for (i=0; i< temp_call_log->no_entry; i++)
        {
            U8 tempNumber[MAX_PB_NUMBER_LENGTH + 1 + 1];
        #ifdef __MMI_VOIP__
            if (temp_call_log->array[i].addr_type != PHB_LN_CALL)
            {
                continue;
            }
        #endif /* __MMI_VOIP__ */
            ConvertRTC2MYTIME(&start_time, &temp_call_log->array[i].time);
            if (CompareTime(start_time, call->start_time, NULL) == 0)
            {
                if (((temp_call_log->array[i].addr_bcd[0] & 0x90) == 0x90) && (temp_call_log->array[i].addr_bcd[0] != 0xFF))
                {
                    tempNumber[0] = '+';
                    mmi_phb_convert_to_digit((U8*) (tempNumber + 1), temp_call_log->array[i].addr_bcd + 1, MAX_PB_NUMBER_LENGTH + 1);
                }
                else
                {
                    mmi_phb_convert_to_digit(tempNumber, temp_call_log->array[i].addr_bcd + 1, MAX_PB_NUMBER_LENGTH + 1);
                }

                mmi_asc_to_ucs2(ucs2_number, (S8*) tempNumber);

                if (mmi_ucs2cmp((const S8*)ucs2_number, (const S8*)call->num) == 0)
                {
                    temp_call_log->array[i].call_duration = applib_get_time_difference_ext_in_second((applib_time_struct*)&call->end_time, (applib_time_struct*)&call->start_time);
                    WriteRecord(NVRAM_EF_PHB_LN_ENTRY_LID, start_lid, temp_call_log, NVRAM_EF_PHB_LN_ENTRY_SIZE, &error);
                    break;
                }
            }
        }
        OslMfree(ucs2_number);
        OslMfree(temp_call_log);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CHISTLogDialedCallDuration
 * DESCRIPTION
 *  To log last call time and total call time
 *  
 *  GetDateTime
 * PARAMETERS
 *  call        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTLogDialedCallDuration(CALL_INFO *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CompareTime(call->end_time, call->start_time, NULL) != TIME_EQUAL)
    {
        applib_get_time_difference_ext(
            (applib_time_struct*)&call->end_time, 
            (applib_time_struct*)&call->start_time, 
            (applib_time_struct*)&chis_p->last_call_time);
        IncrementTime(chis_p->total_out_time, chis_p->last_call_time, &(chis_p->total_out_time));

        WriteRecord(NVRAM_EF_CALL_TIME_LID, 2, (void*)&chis_p->total_out_time, sizeof(MYTIME), &error);
        WriteRecord(NVRAM_EF_CALL_TIME_LID, 1, (void*)&chis_p->last_call_time, sizeof(MYTIME), &error);

        mmi_chist_log_call_duration(call, PHB_LND);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTLogMissedCall
 * DESCRIPTION
 *  To make an entry into missed call list
 * PARAMETERS
 *  call        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTLogMissedCall(CALL_INFO *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DUAL_SIM_MASTER__)
    MTPNP_PFAL_SetLastMissedCallType(LASTMISSEDCALL_TYPE_SIM1);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    chis_p->nMissedCallBeforeView++;
    /* overflow, loop back */
    if (chis_p->nMissedCallBeforeView == 0)
    {
        chis_p->nMissedCallBeforeView = 1;
    }
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    CHISTDeleteTabPaneScreen();
#else
    DeleteScreenIfPresent(SCR8056_CALLS_LIST_MISSED);
    DeleteScreenIfPresent(SCR8520_CALL_MISSED);
    DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
    ReqWriteCallLog(call, PHB_LNM);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTLogRecvdCall
 * DESCRIPTION
 *  To make an entry into recvd call list
 * PARAMETERS
 *  call        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTLogRecvdCall(CALL_INFO *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
    CHISTDeleteTabPaneScreen();
#else
    DeleteScreenIfPresent(SCR8054_CALLS_LIST_RECEIVED);
    DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);
    DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */
    ReqWriteCallLog(call, PHB_LNR);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTLogRecvdCallDuration
 * DESCRIPTION
 *  To make an entry into recvd call list
 * PARAMETERS
 *  call        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTLogRecvdCallDuration(CALL_INFO *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CompareTime(call->end_time, call->start_time, NULL) != TIME_EQUAL)
    {
        applib_get_time_difference_ext(
            (applib_time_struct*)&call->end_time, 
            (applib_time_struct*)&call->start_time, 
            (applib_time_struct*)&chis_p->last_call_time);
        IncrementTime(chis_p->total_in_time, chis_p->last_call_time, &(chis_p->total_in_time));

        WriteRecord(NVRAM_EF_CALL_TIME_LID, 3, (void*)&chis_p->total_in_time, sizeof(MYTIME), &error);
        WriteRecord(NVRAM_EF_CALL_TIME_LID, 1, (void*)&chis_p->last_call_time, sizeof(MYTIME), &error);

        mmi_chist_log_call_duration(call, PHB_LNR);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTExtractPSCallLog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  logCall             [?]         
 *  phbLastNumber       [?]         
 *  void(?)             [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTExtractPSCallLog(LOG_CALL *logCall, PHB_LN_ENTRY *phbLastNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 m = 0;
    S8 *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
            (phbLastNumber->address_type == PHB_LN_CALL &&
            (strlen((S8*) phbLastNumber->address.tel.number) >= MAX_CC_ADDR_LEN)) ||
            (phbLastNumber->address_type == PHB_LN_VOIP &&
            (strlen((S8*) phbLastNumber->address.uri) >= VOIP_URI_LEN))
        )
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
        (strlen((S8*) phbLastNumber->tel.number) >= MAX_CC_ADDR_LEN))
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    {
        PRINT_INFORMATION("CHISTExtractPSCallLog: wrong length");
        return;
    }

    name = OslMalloc((MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH);
    memset(name, 0, ((MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH));

    if (!(phbLastNumber->alpha_id.name_length == 0 
        || (phbLastNumber->alpha_id.name[0] == 0x00 && phbLastNumber->alpha_id.name[1] == 0x00)))
    {
        InputboxConvertGSMToDeviceEncoding(
            phbLastNumber->alpha_id.name,
            (U8*) name,
            phbLastNumber->alpha_id.name_length,
            (MAX_PB_NAME_LENGTH + 1) * ENCODING_LENGTH,
            phbLastNumber->alpha_id.name_dcs,
            0,
            1);
    }
#if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
    if (phbLastNumber->alpha_id.name_dcs == MMI_PHB_UCS2_81 ||
        phbLastNumber->alpha_id.name_dcs == MMI_PHB_UCS2_82)
    {
        phbLastNumber->alpha_id.name_dcs = MMI_PHB_UCS2;
    }
#endif /* defined(__PHB_0x81_SUPPORT__) */

    m = ((mmi_ucs2strlen(name) <= MAX_PB_NAME_LENGTH) ? (mmi_ucs2strlen(name)) : MAX_PB_NAME_LENGTH);
    mmi_ucs2ncpy((S8*) logCall->pbName, name, m);
    logCall->pbName[m * ENCODING_LENGTH] = '\0';
    logCall->pbName[m * ENCODING_LENGTH + 1] = '\0';

    logCall->nameLength = (U8) mmi_ucs2strlen((PS8) logCall->pbName);
    logCall->nameDCS = phbLastNumber->alpha_id.name_dcs;
    OslMfree(name);

#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    logCall->address_type = phbLastNumber->address_type;
    if (logCall->address_type == PHB_LN_VOIP)
    {
       mmi_asc_to_ucs2((PS8) logCall->number, (PS8) phbLastNumber->address.uri);
    }
    else
    {
        if (phbLastNumber->address.tel.type & 0x10)
        {
            logCall->number[0] = '+';
            mmi_asc_to_ucs2((PS8) (logCall->number + 2), (PS8) phbLastNumber->address.tel.number);
        }
        else
        {
            mmi_asc_to_ucs2((PS8) logCall->number, (PS8) phbLastNumber->address.tel.number);
        }
        logCall->numType = phbLastNumber->address.tel.type;
    }
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    if (phbLastNumber->tel.type & 0x10)
    {
        logCall->number[0] = '+';
        mmi_asc_to_ucs2((PS8) (logCall->number + 2), (PS8) phbLastNumber->tel.number);
    }
    else
    {
        mmi_asc_to_ucs2((PS8) logCall->number, (PS8) phbLastNumber->tel.number);
    }
    logCall->numType = phbLastNumber->tel.type;
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */
    logCall->numLength = (U8) mmi_ucs2strlen((PS8) logCall->number);

    ConvertRTC2MYTIME(&logCall->startTime, &phbLastNumber->time);
    mmi_dt_utc_sec_2_mytime(phbLastNumber->call_duration, &logCall->duration, MMI_FALSE);
    logCall->no_of_times = phbLastNumber->count;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_init_get_data_from_nvram
 * DESCRIPTION
 *  Retrieves the phonebook data like, Caller Group details, view fields,
 *  preferred storage, etc from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_init_get_data_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    U16 tempHaveMissedCall;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CHIST_HAVE_MISSED_CALL, &tempHaveMissedCall, DS_SHORT, &pError);     /* 2 bytes for DS_SHORT */
    g_chist_have_missed_call = (U8) tempHaveMissedCall;
    
    if ((g_chist_have_missed_call != 0 && g_chist_have_missed_call != 1) || 
    #ifdef __GEMINI__
        is_sim_replaced(0x00)
    #else /* __GEMINI__ */
        is_sim_replaced()
    #endif /* __GEMINI__ */
        ) /* sim replaced, no missed call log */
    {
        g_chist_have_missed_call = 0;
        tempHaveMissedCall = g_chist_have_missed_call;
        WriteValue(NVRAM_CHIST_HAVE_MISSED_CALL, &tempHaveMissedCall, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_set_have_missed_call
 * DESCRIPTION
 *  set NVRAM_CHIST_HAVE_MISSED_CALL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_set_have_missed_call(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 pError;
    U16 tempHaveMissedCall;    /* Temp Solution For Write 2 bytes NVRAM_PHB_NAME_LIST_FILTER */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("mmi_chist_set_have_missed_call");

    tempHaveMissedCall = g_chist_have_missed_call;
    WriteValue(NVRAM_CHIST_HAVE_MISSED_CALL, &tempHaveMissedCall, DS_SHORT, &pError);        /* 2 bytes for DS_SHORT */
}


/*****************************************************************************
 * FUNCTION
 *  ReadyLogIndication
 * DESCRIPTION
 *  Receives call log ready indication from PS during
 *  power on
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void ReadyLogIndication(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->isCallLogReady = TRUE;
    chis_p->isFirstTime = TRUE;
    chis_p->sequenceId = 0;

    mmi_chist_init_get_data_from_nvram();

    /* show missed call icon in idle screen */
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CHIST_Rearrange_Missed_Call_Status_Icon();
#else /* __MMI_DUAL_SIM_MASTER__ */
    if (g_chist_have_missed_call == 1)
    {
        IdleSetStatusIcon(STATUS_ICON_MISSED_CALL);
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        /* for new sublcd statusicons */
        IdleSetStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif
    }
    else
    {
        HideStatusIcon(STATUS_ICON_MISSED_CALL);
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        HideStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif /* __MMI_SUBLCD_SHORT_STATUSICON_LIST__ */   	
        UpdateStatusIcons(); 	
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */
    ReqReadDialedNum();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSatHandler
 * DESCRIPTION
 *  Handle SIM refresh command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSatHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isCallLogReady && chis_p->isFirstTime)
    {
        chis_p->sequenceId = 0;
        ReqReadDialedNum();
    }
    else if (chis_p->isReqSent == TRUE)
    {
        chis_p->isReqSent = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetDialFromCallLogFlag
 * DESCRIPTION
 *  Returns dial from which type of call log to
 *  call management
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 CHISTGetDialFromCallLogFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return chis_p->dialFromCallLog;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSetDialFromCallLogFlag
 * DESCRIPTION
 *  Sets dial which type of call log
 * PARAMETERS
 *  flag        [IN]        
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSetDialFromCallLogFlag(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->dialFromCallLog = flag;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCallLogName
 * DESCRIPTION
 *  Returns the name of call log that is dialed
 * PARAMETERS
 *  item        [?]         
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCallLogName(LOG_CALL *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LOG_CALL *curr_hilite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(item, 0, sizeof(LOG_CALL));

#ifdef __MMI_DUAL_SIM_MASTER__
    if (chis_p->dialFromCallLog >= ITEM_SLAVE_DIALED_CALL)
    {
        ST_MTPNP_AD_CALL_NAME AD_LOG_CALL;
        MTPNP_PFAL_GetCallLogName(&AD_LOG_CALL);
        memcpy(item->pbName, AD_LOG_CALL.name, sizeof(item->pbName));
        item->nameLength = AD_LOG_CALL.name_len;
        item->nameDCS = AD_LOG_CALL.dcs;
        return;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    switch (chis_p->dialFromCallLog)
    {
        case ITEM_DIALED_CALL:
            curr_hilite = &chis_p->dialedCalls[chis_p->currDialedCallIndex];
            break;
        case ITEM_MISSED_CALL:
            curr_hilite = &chis_p->missedCalls[chis_p->currMissedCallIndex];
            break;
        case ITEM_RECVD_CALL:
            curr_hilite = &chis_p->recvdCalls[chis_p->currRecvdCallIndex];
            break;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
        case ITEM_MIXED_CALL:
            curr_hilite = chis_p->mixedCalls[chis_p->currMixedCallIndex];
            break;
    #endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
        default:
            return;
    }

    if (curr_hilite->number[0] != 0)
    {
        /*  Display as Emergency Number */
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (CheckValidEmergencyNo1((S8*) curr_hilite->number, SIM1))	
    #else
        if (CheckValidEmergencyNo1((S8*) curr_hilite->number))
    #endif
        {
            mmi_ucs2ncpy((PS8) item->pbName, GetString(STR_EMERGENCY_NUMBER), MAX_PB_NAME_LENGTH);
            item->nameLength = mmi_ucs2strlen((PS8) item->pbName);
            if (GetUCS2Flag((PS8) item->pbName))
            {
                item->nameDCS = MMI_PHB_UCS2;
            }
            else
            {
                item->nameDCS = MMI_PHB_ASCII;
            }
        }
        else
        {
            memcpy(item->pbName, curr_hilite->pbName, sizeof(item->pbName));
            item->nameLength = curr_hilite->nameLength;
            item->nameDCS = curr_hilite->nameDCS;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetMissedCallCountBeforeView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 CHISTGetMissedCallCountBeforeView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return chis_p->nMissedCallBeforeView;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_exit_get_call_log_dummy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_exit_get_call_log_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


#ifndef __MMI_CH_MIXED_CALL_LOG__
/*****************************************************************************
 * FUNCTION
 *  CHISTGetCallLogBySENDKey
 * DESCRIPTION
 *  Reads call log data from idle screen by send key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCallLogBySENDKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntryCHISTViewDialedCallList();
        return;
    }

    if (chis_p->isReqSent == TRUE)
    {
        return;
    }

    if (chis_p->process == CALL_LOG_PROC_WRITE)
    {
        PRINT_INFORMATION("still writing, wait till write complete then read!!!!");
        chis_p->process = CALL_LOG_PROC_SYNC;
        return;
    }
    EntryNewScreen(GLOBAL_SCR_DUMMY, mmi_chist_exit_get_call_log_dummy, NULL, NULL);
    ShowCategoryDummyScreen(); /* dummy category */
    ReqReadDialedNumByKey();
    return;
}


#else /* __MMI_CH_MIXED_CALL_LOG__ */ 

#include "CallsResDef.h"

/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewMixedCallList
 * DESCRIPTION
 *  Display mixed call log list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewMixedCallList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *phoneNumbers[TOT_SIZE_OF_MIXED_LIST];
    U8 *phoneNames[TOT_SIZE_OF_MIXED_LIST];
    U8 *guiBuffer;
    U16 Cat23DemoIcons[TOT_SIZE_OF_MIXED_LIST];
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && !IsWapCallPresent())
    {
        return;
    }

    if (chis_p->nMixedCalls)
    {
    	g_chist_have_missed_call = 0;
    	mmi_chist_set_have_missed_call();
        HideStatusIcon(STATUS_ICON_MISSED_CALL);
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        HideStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif /* __MMI_SUBLCD_SHORT_STATUSICON_LIST__ */ 
        UpdateStatusIcons();

    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 

        EntryNewScreen(SCR8057_CALLS_LIST_MIXED, wgui_restore_list_menu_slim_style, CHISTGetCallLogBySENDKey, MMI_FULL_SCREEN);

        guiBuffer = GetCurrGuiBuffer(SCR8057_CALLS_LIST_MIXED);
        RegisterHighlightHandler(CHISTGetCurrMixedCallIndex);
        CHISTPopulateMixedCallList(phoneNumbers, phoneNames);

        chis_p->nMissedCallBeforeView = 0;

        for (count = 0; count < chis_p->nMixedCalls; count++)
        {
            if (chis_p->mixedCalls[count] >= &chis_p->missedCalls[0] &&
                chis_p->mixedCalls[count] <= &chis_p->missedCalls[TOT_SIZE_OF_MISSED_LIST - 1])
            {
            #ifdef __MMI_VOIP__
                if (chis_p->mixedCalls[count]->address_type == PHB_LN_VOIP)
                {
                    Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_MISSED_CALLS;
                }
                else
            #endif /* __MMI_VOIP__ */
            #ifdef __MMI_VIDEO_TELEPHONY__
                if (chis_p->mixedCalls[count]->address_type == PHB_LN_VIDEO)
                {
                    Cat23DemoIcons[count] = IMG_ID_CHIST_VIDEO_MISSED_CALLS;
                }
                else
            #endif /* __MMI_VIDEO_TELEPHONY__ */       
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
                    Cat23DemoIcons[count] = IMG_MTPNP_CARD1_MENU_MISSED_CALLS;
                #else /* __MMI_DUAL_SIM_MASTER__ */
                    Cat23DemoIcons[count] = IMG_MENU8103_MISSED_CALLS;
                #endif /* __MMI_DUAL_SIM_MASTER__ */
                }
            }
            else if (chis_p->mixedCalls[count] >= &chis_p->dialedCalls[0] &&
                     chis_p->mixedCalls[count] <= &chis_p->dialedCalls[TOT_SIZE_OF_DIALED_LIST - 1])
            {
            #ifdef __MMI_VOIP__
                if (chis_p->mixedCalls[count]->address_type == PHB_LN_VOIP)
                {
                    Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_DIALED_CALLS;
                }
                else
            #endif /* __MMI_VOIP__ */
            #ifdef __MMI_VIDEO_TELEPHONY__
                if (chis_p->mixedCalls[count]->address_type == PHB_LN_VIDEO)
                {
                    Cat23DemoIcons[count] = IMG_ID_CHIST_VIDEO_DIALED_CALLS;
                }
                else
            #endif /* __MMI_VIDEO_TELEPHONY__ */           
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
                    Cat23DemoIcons[count] = IMG_MTPNP_CARD1_MENU_DIALED_CALLS;
                #else /* __MMI_DUAL_SIM_MASTER__ */
                    Cat23DemoIcons[count] = IMG_MENU8102_DIALED_CALLS;
                #endif /* __MMI_DUAL_SIM_MASTER__ */
                }
            }
            else
            {
            #ifdef __MMI_VOIP__
                if (chis_p->mixedCalls[count]->address_type == PHB_LN_VOIP)
                {
                    Cat23DemoIcons[count] = IMG_ID_CHIST_VOIP_RECEIVED_CALLS;
                }
                else
            #endif /* __MMI_VOIP__ */
            #ifdef __MMI_VIDEO_TELEPHONY__
                if (chis_p->mixedCalls[count]->address_type == PHB_LN_VIDEO)
                {
                    Cat23DemoIcons[count] = IMG_ID_CHIST_VIDEO_RECEIVED_CALLS;
                }
                else
            #endif /* __MMI_VIDEO_TELEPHONY__ */           
                {
                #ifdef __MMI_DUAL_SIM_MASTER__
                    Cat23DemoIcons[count] = IMG_MTPNP_CARD1_MENU_RECEIVED_CALLS;
                #else /* __MMI_DUAL_SIM_MASTER__ */
                    Cat23DemoIcons[count] = IMG_MENU8101_RECEIVED_CALLS;
                #endif /* __MMI_DUAL_SIM_MASTER__ */
                }
            }
        }


	#if 1
	// Huyanwei Add it For REad missed call
	DeleteScreenIfPresent(ITEM_SCR_MISSED_CALL);		
	#endif
	
        wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    #ifdef __MMI_UI_HINTS_IN_MENUITEM__
        set_force_all_hints_in_menuitem();
    #endif 
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        if (GetExitScrnID() == SCR8057_CALLS_LIST_MIXED)
        {
            ShowCategory53Screen(
                STR_SCR8057_CAPTION,
                IMG_SCR8057_CAPTION,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nMixedCalls,
            	phoneNames,
                (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
                chis_p->currMixedCallIndex,
                guiBuffer);
	    }
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        if (GetExitScrnID() == SCR8057_CALLS_LIST_MIXED)
        {
            ShowCategory53Screen(
                STR_SCR8057_CAPTION,
                IMG_SCR8057_CAPTION,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                chis_p->nMixedCalls,
                phoneNames,
        	    (U16*) Cat23DemoIcons,
                phoneNumbers,
                0,
    	        chis_p->currMixedCallIndex,
                guiBuffer);
       }
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
#ifdef __MMI_DUAL_SIM_MASTER__
    MTPNP_PFAL_CC_HandleSendKeys(CHISTCallMixedNum,KEY_EVENT_DOWN);
#else	/* __MMI_DUAL_SIM_MASTER__ */
        SetKeyHandler(CHISTCallMixedNum, KEY_SEND, KEY_EVENT_DOWN);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    #ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
        SetKeyHandler(CHISTCallVTMixedNum, KEY_ENTER, KEY_EVENT_DOWN);
    #endif /* __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */

    #ifdef __MMI_IP_KEY__
/* under construction !*/
    #endif 

        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
        SetKeyHandler(EntryCHISTMixedListOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTMixedListOptions, KEY_EVENT_UP);
    #else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetKeyHandler(EntryCHISTViewMixedCall, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryCHISTViewMixedCall, KEY_EVENT_UP);
    #endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_post_tab_pane_display();
        }
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
    }
    else
    {
    #ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
        if (call_log_on_idle)
        {
            set_pre_tab_pane_display();
            EntryNewScreen(SCR8057_CALLS_LIST_MIXED, NULL, CHISTGetCallLogBySENDKey, MMI_FULL_SCREEN);
            guiBuffer = GetCurrGuiBuffer(SCR8057_CALLS_LIST_MIXED);
            //phoneNames[0]=(PU8)GetString(STR_EMPTY_LIST_NOTIFICATION);
            //Cat23DemoIcons[0]=0;
            if (GetExitScrnID() == SCR8057_CALLS_LIST_MIXED)
            {
                ShowCategory53Screen(
                    STR_SCR8057_CAPTION,
                    IMG_SCR8057_CAPTION,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    chis_p->nMixedCalls,
                    NULL,
                    NULL,
                    NULL,
                    0,
                    0,
                    guiBuffer);
            }
            /* ShowCategory56Screen( STR_SCR8057_CAPTION, IMG_SCR8057_CAPTION,
               0,0, STR_GLOBAL_BACK,
               IMG_GLOBAL_BACK, 1, phoneNames,
               NULL,
               0, guiBuffer ); */
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            set_post_tab_pane_display();
        }
        else
    #endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */ 
        {
            DisplayPopup(
                (PU8) GetString(STR_EMPTY_LIST_NOTIFICATION),
                IMG_GLOBAL_EMPTY,
                1,
                CS_NOTIFYDURATION,
                EMPTY_LIST_TONE);
        }
    }
#ifdef __MMI_DUAL_SIM_MASTER__
    DeleteScreenIfPresent(SCR_MTPNP_CALL_HISTORY_NOTIFY);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    return;
}


#ifdef __MMI_CH_OPTIONS_INCLUDE_INFO__
/*****************************************************************************
 * FUNCTION
 *  EntryCHISTMixedListOptions
 * DESCRIPTION
 *  Display a option list of call log from mixed call list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTMixedListOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->mixedCalls[chis_p->currMixedCallIndex] >=
        &chis_p->missedCalls[0] &&
        chis_p->mixedCalls[chis_p->currMixedCallIndex] <= &chis_p->missedCalls[TOT_SIZE_OF_MISSED_LIST - 1])
    {
        chis_p->currMissedCallIndex = (U8)
            (((U32) chis_p->mixedCalls[chis_p->currMixedCallIndex] -
              (U32) & chis_p->missedCalls[0]) / sizeof(MISSED_CALL));
        EntryCHISTMissedListOptions();
    }
    else if (chis_p->mixedCalls[chis_p->currMixedCallIndex] >=
             &chis_p->dialedCalls[0] &&
             chis_p->mixedCalls[chis_p->currMixedCallIndex] <= &chis_p->dialedCalls[TOT_SIZE_OF_DIALED_LIST - 1])
    {
        chis_p->currDialedCallIndex = (U8)
            (((U32) chis_p->mixedCalls[chis_p->currMixedCallIndex] -
              (U32) & chis_p->dialedCalls[0]) / sizeof(DIALED_CALL));
        EntryCHISTDialedListOptions();
    }
    else
    {
        chis_p->currRecvdCallIndex = (U8)
            (((U32) chis_p->mixedCalls[chis_p->currMixedCallIndex] -
              (U32) & chis_p->recvdCalls[0]) / sizeof(RECEIVED_CALL));
        EntryCHISTRecvdListOptions();
    }
    return;
}
#else /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTViewMixedCall
 * DESCRIPTION
 *  Display a single entry of call log from mixed call list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTViewMixedCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->mixedCalls[chis_p->currMixedCallIndex] >=
        &chis_p->missedCalls[0] &&
        chis_p->mixedCalls[chis_p->currMixedCallIndex] <= &chis_p->missedCalls[TOT_SIZE_OF_MISSED_LIST - 1])
    {
        chis_p->currMissedCallIndex = (U8)
            (((U32) chis_p->mixedCalls[chis_p->currMixedCallIndex] -
              (U32) & chis_p->missedCalls[0]) / sizeof(MISSED_CALL));
        EntryCHISTViewMissedCall();
    }
    else if (chis_p->mixedCalls[chis_p->currMixedCallIndex] >=
             &chis_p->dialedCalls[0] &&
             chis_p->mixedCalls[chis_p->currMixedCallIndex] <= &chis_p->dialedCalls[TOT_SIZE_OF_DIALED_LIST - 1])
    {
        chis_p->currDialedCallIndex = (U8)
            (((U32) chis_p->mixedCalls[chis_p->currMixedCallIndex] -
              (U32) & chis_p->dialedCalls[0]) / sizeof(DIALED_CALL));
        EntryCHISTViewDialedCall();
    }
    else
    {
        chis_p->currRecvdCallIndex = (U8)
            (((U32) chis_p->mixedCalls[chis_p->currMixedCallIndex] -
              (U32) & chis_p->recvdCalls[0]) / sizeof(RECEIVED_CALL));
        EntryCHISTViewRecvdCall();
    }
    return;
}
#endif /* __MMI_CH_OPTIONS_INCLUDE_INFO__ */ 


#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  CHISTCallMixedNumByIP
 * DESCRIPTION
 *  Use IP dialing to call a single entry in mixed call list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallMixedNumByIP(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetTempUseIPNumber(TRUE);
    CHISTCallMixedNum();
}
#endif /* __IP_NUMBER__ */ 


/*****************************************************************************
 * FUNCTION
 *  CHISTCallMixedNum
 * DESCRIPTION
 *  make call to a single entry in mixed call list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallMixedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addToHistory = 0;

    if (chis_p->mixedCalls[chis_p->currMixedCallIndex]->number[0] == 0)
    {
        if (chis_p->mixedCalls[chis_p->currMixedCallIndex]->pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_MIXED_CALL;
        #ifdef __MMI_UCM__
            if ((GetExitScrnID() == SCR8009_DIALED_CALL_OPTIONS) || (GetExitScrnID() == SCR8521_MISSED_CALL_OPTIONS) || (GetExitScrnID() == SCR8007_RECEIVED_CALL_OPTIONS))
            {
                mmi_ucm_app_entry_dial_option((U8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->pbName, mmi_chist_call_mixed_num_cbk, NULL);            
            }
            else
        #endif
            {
                MakeCall((S8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->pbName);
                mmi_chist_call_mixed_num_cbk(NULL);
            }
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_MIXED_CALL;
    #ifdef __MMI_UCM__
        if ((GetExitScrnID() == SCR8009_DIALED_CALL_OPTIONS) || (GetExitScrnID() == SCR8521_MISSED_CALL_OPTIONS) || (GetExitScrnID() == SCR8007_RECEIVED_CALL_OPTIONS))
        {
            mmi_ucm_app_entry_dial_option((U8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->pbName, mmi_chist_call_mixed_num_cbk, NULL);            
        }
        else
    #endif /* __MMI_UCM__ */
        {
        #ifdef __MMI_VOIP__
            if (chis_p->mixedCalls[chis_p->currMixedCallIndex]->address_type == PHB_LN_VOIP)
            {
                mmi_voip_app_make_call((U8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->number);
            }
            else
        #endif /* __MMI_VOIP__ */
            {
                MakeCall((S8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->number);
            }
            mmi_chist_call_mixed_num_cbk(NULL);
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_call_mixed_num_cbk
 * DESCRIPTION
 *  Call dialed num cbk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_call_mixed_num_cbk(void *p)
{
    if (IsScreenPresent(SCR8008_CALL_DIALED))
    {
        DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
        DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    }
    else if (IsScreenPresent(SCR8520_CALL_MISSED))
    {    
        DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
        DeleteScreenIfPresent(SCR8520_CALL_MISSED);    
    }
    else if (IsScreenPresent(SCR8006_CALL_RECEIVED))
    {        
        DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
        DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);   
    }
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#ifdef __MMI_DUAL_SIM_MASTER__
    DeleteScreenIfPresent(SCR_ID_CHIST_DUAL_CARD_MIXED_CALLLOG);
#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCallLogBySENDKey
 * DESCRIPTION
 *  Reads mixed call logs from idle screen with send key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCallLogBySENDKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens())
    {
        EntryCHISTViewMixedCallList();
        return;
    }

    if (chis_p->isReqSent == TRUE)
    {
        return;
    }
    if (chis_p->isCallLogReady == TRUE && chis_p->isFirstTime == FALSE)
    {
        if (chis_p->process == CALL_LOG_PROC_WRITE)
        {
            PRINT_INFORMATION("still writing, wait till write complete then read!!!!");
            chis_p->process = CALL_LOG_PROC_SYNC;
            return;
        }
        chis_p->isMixedStyle = TRUE;
        EntryNewScreen(GLOBAL_SCR_DUMMY, mmi_chist_exit_get_call_log_dummy, NULL, NULL);
        ShowCategoryDummyScreen(); /* dummy category */
        ReqReadDialedNumByKey();
    }
    else
    {
        EntryNewScreen(SCR_CALL_LOG_NOT_READY, ExitCHISTProcessingAnimation, NULL, NULL);

        StartTimer(PHB_NOTIFYDURATION_TIMER, PHB_NOTIFY_TIMEOUT, CHISTAnimationTimeOutHdlr);

        ShowCategory66Screen(
            STR_SCR8057_CAPTION,
            IMG_SCR8057_CAPTION,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (PU8) GetString(STR_CALLS_IN_PROGRESS_TEXT),
            IMG_PROCESSING_PHONEBOOK,
            NULL);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTPopulateMixedCallList
 * DESCRIPTION
 *  Construct mixed call list
 * PARAMETERS
 *  numberList      [?]     
 *  phoneList       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTPopulateMixedCallList(U8 *numberList[], U8 *phoneList[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < chis_p->nMixedCalls; index++)
    {
        if (chis_p->mixedCalls[index]->nameLength > 0)
        {
            phoneList[index] = (U8*) chis_p->mixedCalls[index]->pbName;
            if (chis_p->mixedCalls[index]->number && mmi_ucs2strlen((S8*)chis_p->mixedCalls[index]->number) > 0)
            {
                numberList[index] = (U8*) chis_p->mixedCalls[index]->number;
            }
            else
            {
                numberList[index] = NULL;
            }
        }
        else
        {
            if (chis_p->mixedCalls[index]->number[0] != 0)
            {
                phoneList[index] = (U8*) chis_p->mixedCalls[index]->number;
            }
            else
            {
                phoneList[index] = (PU8) GetString(STR_UNKNOWN_NUMBER);
            }
            numberList[index] = NULL;
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetCurrMixedCallIndex
 * DESCRIPTION
 *  Sets current highlighted index in mixed call list
 * PARAMETERS
 *  ind     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTGetCurrMixedCallIndex(S32 ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->currMixedCallIndex = (U8) ind;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSortCallLogsByTime
 * DESCRIPTION
 *  Sort all three types of call logs by time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSortCallLogsByTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0, index1 = 0, index2 = 0, index3 = 0;
    U8 total_logs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_logs = chis_p->nDialedCalls + chis_p->nMissedCalls + chis_p->nRecvdCalls;
    chis_p->nMixedCalls = 0;

#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n chis_p->nDialedCalls + chis_p->nMissedCalls + chis_p->nRecvdCalls = %d \r\n",chis_p->nDialedCalls + chis_p->nMissedCalls + chis_p->nRecvdCalls);
  #endif
    while (total_logs > 0)
    {
        if (index1 >= chis_p->nDialedCalls)
        {
            /* no more dialed */
            if (index2 >= chis_p->nMissedCalls)
            {
                /* no more missed */
                if (index3 >= chis_p->nRecvdCalls)
                {
                    /* all three types are done, no need to sort */
                    break;
                }
                else
                {
                    /* only Recvd remains, recvd wins */
                    chis_p->mixedCalls[index] = &chis_p->recvdCalls[index3];
                    index3++;
                }
            }
            else
            {
                if (index3 >= chis_p->nRecvdCalls)
                {
                    /* only missed remains, missed wins */
                    chis_p->mixedCalls[index] = &chis_p->missedCalls[index2];
                    index2++;
                }
                else
                {
                    /* missed and recvd remain, compare */
                    if (CompareTime(
                            chis_p->missedCalls[index2].startTime,
                            chis_p->recvdCalls[index3].startTime,
                            NULL) == TIME_LESS)
                    {
                        /* recvd wins */
                        chis_p->mixedCalls[index] = &chis_p->recvdCalls[index3];
                        index3++;
                    }
                    else
                    {
                        /* missed wins */
                        chis_p->mixedCalls[index] = &chis_p->missedCalls[index2];
                        index2++;
                    }
                }
            }
        }
        else
        {
            /* dialed remains */
            if (index2 >= chis_p->nMissedCalls)
            {
                /* no more missed */
                if (index3 >= chis_p->nRecvdCalls)
                {
                    /* only dialed remains, dialed wins */
                    chis_p->mixedCalls[index] = &chis_p->dialedCalls[index1];
                    index1++;
                }
                else
                {
                    /* dialed and recvd remains, compare */
                    if (CompareTime(
                            chis_p->dialedCalls[index1].startTime,
                            chis_p->recvdCalls[index3].startTime,
                            NULL) == TIME_LESS)
                    {
                        /* recvd wins */
                        chis_p->mixedCalls[index] = &chis_p->recvdCalls[index3];
                        index3++;
                    }
                    else
                    {
                        /* dialed wins */
                        chis_p->mixedCalls[index] = &chis_p->dialedCalls[index1];
                        index1++;
                    }
                }
            }
            else
            {
                /* missed remains */
                if (index3 >= chis_p->nRecvdCalls)
                {
                    /* dialed and missed remains, compare */
                    if (CompareTime(
                            chis_p->dialedCalls[index1].startTime,
                            chis_p->missedCalls[index2].startTime,
                            NULL) == TIME_LESS)
                    {
                        /* missed wins */
                        chis_p->mixedCalls[index] = &chis_p->missedCalls[index2];
                        index2++;
                    }
                    else
                    {
                        /* dialed wins */
                        chis_p->mixedCalls[index] = &chis_p->dialedCalls[index1];
                        index1++;
                    }
                }
                else
                {
                    /* all remain, compare */
                    if (CompareTime(
                            chis_p->dialedCalls[index1].startTime,
                            chis_p->missedCalls[index2].startTime,
                            NULL) == TIME_LESS)
                    {
                        if (CompareTime(
                                chis_p->missedCalls[index2].startTime,
                                chis_p->recvdCalls[index3].startTime,
                                NULL) == TIME_LESS)
                        {
                            /* recvd wins */
                            chis_p->mixedCalls[index] = &chis_p->recvdCalls[index3];
                            index3++;
                        }
                        else
                        {
                            /* missed wins */
                            chis_p->mixedCalls[index] = &chis_p->missedCalls[index2];
                            index2++;
                        }
                    }
                    else
                    {
                        if (CompareTime(
                                chis_p->missedCalls[index2].startTime,
                                chis_p->recvdCalls[index3].startTime,
                                NULL) == TIME_LESS)
                        {
                            if (CompareTime(
                                    chis_p->dialedCalls[index1].startTime,
                                    chis_p->recvdCalls[index3].startTime,
                                    NULL) == TIME_LESS)
                            {
                                /* recvd wins */
                                chis_p->mixedCalls[index] = &chis_p->recvdCalls[index3];
                                index3++;
                            }
                            else
                            {
                                /* dialed wins */
                                chis_p->mixedCalls[index] = &chis_p->dialedCalls[index1];
                                index1++;
                            }
                        }
                        else
                        {
                            /* dialed wins */
                            chis_p->mixedCalls[index] = &chis_p->dialedCalls[index1];
                            index1++;
                        }
                    }
                }
            }
        }

        total_logs--;
        index++;
    }

#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n index  = %d \r\n", index );
	#endif
#if 0
    // Huyanwei Del It
    for (chis_p->nMixedCalls = 0; chis_p->nMixedCalls < index; chis_p->nMixedCalls++)
    {
        if (CHISTIsDuplicatedNumber(chis_p->nMixedCalls) == TRUE)
        {
            if (chis_p->nMixedCalls + 1 < index)
            {
                /* shift up */
                memcpy(
                    &chis_p->mixedCalls[chis_p->nMixedCalls],
                    &chis_p->mixedCalls[chis_p->nMixedCalls + 1],
                    4 * (index - chis_p->nMixedCalls - 1));
                chis_p->mixedCalls[index - 1] = NULL;
                chis_p->nMixedCalls--;
            }
            else
            {
                chis_p->mixedCalls[index - 1] = NULL;
            }
            index--;
        }
    }
	
#endif

    chis_p->nMixedCalls = index;
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n chis_p->nMixedCalls = %d \r\n", chis_p->nMixedCalls);
#endif
		
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTIsDuplicatedNumber
 * DESCRIPTION
 *  Check if there's a dusplicated number in all three
 *  types of call logs
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
BOOL CHISTIsDuplicatedNumber(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U32 temp1, temp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        return FALSE;
    }

    for (i = 0; i < index; i++)
    {
    #if 1
    #ifdef __MMI_VOIP__
        if (chis_p->mixedCalls[i]->address_type == PHB_LN_VOIP &&  chis_p->mixedCalls[index]->address_type == PHB_LN_VOIP)
        {
            /* exactly match */
            if (mmi_ucs2cmp((PS8) chis_p->mixedCalls[i]->number, (PS8) chis_p->mixedCalls[index]->number) == 0)
            {
                return TRUE;
            }
        }
        else if (chis_p->mixedCalls[i]->address_type == chis_p->mixedCalls[index]->address_type)
    #endif /* __MMI_VOIP__ */
        {
            U8 ascii_num1[MAX_DIGIT];
            U8 ascii_num2[MAX_DIGIT];

            /* only match last 7 digits */
            mmi_ucs2_to_asc((PS8) ascii_num1, (PS8) chis_p->mixedCalls[i]->number);
            mmi_ucs2_to_asc((PS8) ascii_num2, (PS8) chis_p->mixedCalls[index]->number);
            temp1 = mmi_phb_util_convert_number_to_int((PU8) ascii_num1);
            temp2 = mmi_phb_util_convert_number_to_int((PU8) ascii_num2);
            if (temp1 == temp2)
            {
            #ifdef __MMI_PHB_ADV_NUM_MATCH_MOBILE__
                if (mmi_phb_number_compare_extension((PS8) ascii_num1, (PS8) ascii_num2) == FALSE)
                {
                    return FALSE;
                }
            #endif /* __MMI_PHB_ADV_NUM_MATCH_MOBILE__ */ 
                if (temp1 != INVALID_NUMBER &&
                    mmi_ucs2cmp((PS8) chis_p->mixedCalls[i]->number, (PS8) chis_p->mixedCalls[index]->number) == 0)
                {
                    return TRUE;
                }
            }
        }
    #else /* 1 */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 1 */ 
    }
    return FALSE;
}

#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 


/*****************************************************************************
 * FUNCTION
 *  CHISTIgnoreMissedCallScreen
 * DESCRIPTION
 *  Exit the missed call notification screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTIgnoreMissedCallScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DUAL_SIM_MASTER__
    chis_p->saveMissedScrn = FALSE;
#else  /*__MMI_DUAL_SIM_MASTER__*/
    SetMissedCallFlag(FALSE);
#endif  /*__MMI_DUAL_SIM_MASTER__*/
    GoBackBothLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  CHISTReadMissedNum
 * DESCRIPTION
 *  Reads missed call log from missed call notification screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTReadMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackSubLCDHistory();
    ReqReadMissedNum();
}


#ifdef __MMI_VOIP__
/*****************************************************************************
 * FUNCTION
 *  mmi_chist_write_voip_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dailCall        [?]         
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_write_voip_log(mmi_voip_call_log_struct *dailCall, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    SET_LAST_NUMBER_REQ *dataPtr;
    U8 *uri;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case PHB_LND:
            SetProtocolEventHandler(RspWriteDialedNum, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
            uri = (U8*) dailCall->remoteUri;
            chis_p->process = CALL_LOG_PROC_WRITE;
            break;
        case PHB_LNM:
            SetProtocolEventHandler(RspWriteMissedNum, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
            uri = (U8*) dailCall->remoteUri;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
            chis_p->process = CALL_LOG_PROC_WRITE;
    #endif 
            break;
        case PHB_LNR:
            SetProtocolEventHandler(RspWriteRecvdNum, PRT_MMI_PHB_SET_LAST_NUMBER_RSP);
            uri = (U8*) dailCall->remoteUri;
    #ifdef __MMI_CH_MIXED_CALL_LOG__
            chis_p->process = CALL_LOG_PROC_WRITE;
    #endif 
            break;
        default:
            return;
    }

    if (chis_p->isCallLogReady == FALSE)
    {
        return;
    }

    dataPtr = (SET_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(SET_LAST_NUMBER_REQ));
    dataPtr->type = type;
    dataPtr->no_data = 0;
    dataPtr->index = 0xff;
    
    dataPtr->entry.address_type = PHB_LN_VOIP;
    memset((U8*) & dataPtr->entry.address.uri, 0, VOIP_URI_LEN);
    memset((U8*) & dataPtr->entry.alpha_id, 0, sizeof(CALL_LOG_NAME_STRUCT));
    if (uri[0] != 0)
    {
        strncpy((PS8) dataPtr->entry.address.uri, (PS8) (uri), VOIP_URI_LEN);
        //dataPtr->entry.address.tel.length = strlen((PS8) dataPtr->entry.address.tel.number);
    }

    if (mmi_ucs2strlen((PS8) dailCall->dispName) > 0)
    {
        dataPtr->entry.alpha_id.name_dcs = dailCall->dispDcs;
        if (dailCall->dispDcs == MMI_PHB_ASCII)
        {
            mmi_ucs2_to_asc((PS8) dataPtr->entry.alpha_id.name, (PS8) (dailCall->dispName));
        }
        else
        {
            U8 i = 0, len;
            U8 temp_name;
            len = mmi_ucs2strlen((PS8) dailCall->dispName) * ENCODING_LENGTH;
            if (len > MAX_PB_NAME_LENGTH)
            {
                len = MAX_PB_NAME_LENGTH;
            }
            mmi_ucs2ncpy((S8*)dataPtr->entry.alpha_id.name, (S8*) dailCall->dispName, len);
            while (i != len)
            {
                /* big endian <-> little endian */
                temp_name = dataPtr->entry.alpha_id.name[i];
                dataPtr->entry.alpha_id.name[i] = dataPtr->entry.alpha_id.name[i + 1];
                dataPtr->entry.alpha_id.name[i + 1] = temp_name;
                i += 2;
            }
            dataPtr->entry.alpha_id.name[i] = '\0';
            dataPtr->entry.alpha_id.name[i + 1] = '\0';
            dataPtr->entry.alpha_id.name_length = mmi_ucs2strlen((PS8) dataPtr->entry.alpha_id.name) * ENCODING_LENGTH;
        }
    }

    ConvertMYTIME2RTC(&dataPtr->entry.time, &dailCall->startTime);
    dataPtr->entry.call_duration = 0;
    dataPtr->entry.count = 1;

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_SET_LAST_NUMBER_REQ;
    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_log_voip_dialed_call
 * DESCRIPTION
 *  To make a voip entry into dialed call list
 *  
 *  GetDateTime
 * PARAMETERS
 *  call        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_log_voip_dialed_call(mmi_voip_call_log_struct *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR8055_CALLS_LIST_DIALED);
    DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
    mmi_chist_write_voip_log(call, PHB_LND);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_log_voip_missed_call
 * DESCRIPTION
 *  To make a voip entry into missed call list
 * PARAMETERS
 *  call        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_log_voip_missed_call(mmi_voip_call_log_struct *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->nMissedCallBeforeView++;
    /* overflow, loop back */
    if (chis_p->nMissedCallBeforeView == 0)
    {
        chis_p->nMissedCallBeforeView = 1;
    }
    DeleteScreenIfPresent(SCR8056_CALLS_LIST_MISSED);
    DeleteScreenIfPresent(SCR8520_CALL_MISSED);
    DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
    mmi_chist_write_voip_log(call, PHB_LNM);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_log_voip_received_call
 * DESCRIPTION
 *  To make a voip entry into recvd call list
 * PARAMETERS
 *  call        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_log_voip_received_call(mmi_voip_call_log_struct *call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR8054_CALLS_LIST_RECEIVED);
    DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);
    DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
    mmi_chist_write_voip_log(call, PHB_LNR);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_log_voip_call_duration
 * DESCRIPTION
 *  To log call duration
 *  
 *  GetDateTime
 * PARAMETERS
 *  call        [IN]     
 *  type        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_log_voip_call_duration(mmi_voip_call_log_struct *call, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    kal_uint16 start_lid;
    nvram_ef_phb_ln_struct *temp_call_log;
    MYTIME start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (type == PHB_LND)
    {
        start_lid = 1;
    }
    else if (type == PHB_LNR)
    {
        start_lid = 1 + ((TOT_SIZE_OF_DIALED_LIST + TOT_SIZE_OF_ONE_LN_LIST -1)/TOT_SIZE_OF_ONE_LN_LIST) +
                    ((TOT_SIZE_OF_DIALED_LIST + TOT_SIZE_OF_ONE_LN_LIST -1)/TOT_SIZE_OF_ONE_LN_LIST);
    }
    else
    {
        return;
    }
    temp_call_log = OslMalloc(NVRAM_EF_PHB_LN_ENTRY_SIZE);
    if (temp_call_log)
    {
        int i;
        S8 *ucs2_addr = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
        ReadRecord(NVRAM_EF_PHB_LN_ENTRY_LID, start_lid, temp_call_log, NVRAM_EF_PHB_LN_ENTRY_SIZE, &error);
        for (i=0; i< temp_call_log->no_entry; i++)
        {
            if (temp_call_log->array[i].addr_type != PHB_LN_VOIP)
            {
                continue;
            }
            ConvertRTC2MYTIME(&start_time, &temp_call_log->array[i].time);
            if (CompareTime(start_time, call->startTime, NULL) == 0)
            {
                //temp_call_log->array[i].addr_bcd[VOIP_URI_LEN - 1] = '\0';
                //mmi_asc_to_ucs2(ucs2_addr, (S8*) temp_call_log->array[i].addr_bcd);
                //if (mmi_ucs2cmp((const S8*)ucs2_addr, (const S8*)call->remoteUri) == 0)
                if (strcmp((PS8)temp_call_log->array[i].addr_bcd, (PS8)call->remoteUri) == 0)
                {
                    temp_call_log->array[i].call_duration = applib_get_time_difference_ext_in_second((applib_time_struct*)&call->endTime, (applib_time_struct*)&call->startTime);
                    WriteRecord(NVRAM_EF_PHB_LN_ENTRY_LID, start_lid, temp_call_log, NVRAM_EF_PHB_LN_ENTRY_SIZE, &error);
                    break;
                }
            }
        }
        OslMfree(ucs2_addr);
        OslMfree(temp_call_log);
    }
}
#endif /* __MMI_VOIP__ */


#ifdef __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__
/*****************************************************************************
 * FUNCTION
 *  CHISTCallVTDialedNum
 * DESCRIPTION
 *  To make a video call to dialed list entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallVTDialedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->dialedCalls[chis_p->currDialedCallIndex].number[0] == 0)
    {
        /* no name, number is in name field for display */
        if (chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_DIALED_CALL;
            mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].pbName);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_DIALED_CALL;
        mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->dialedCalls[chis_p->currDialedCallIndex].number);
    }
    
    DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
    DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    DeleteScreenIfPresent(SCR8055_CALLS_LIST_DIALED);
#ifdef __MMI_CH_MIXED_CALL_LOG__    
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTCallVTMissedNum
 * DESCRIPTION
 *  To make a video call to missed list entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallVTMissedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->missedCalls[chis_p->currMissedCallIndex].number[0] == 0)
    {
        if (chis_p->missedCalls[chis_p->currMissedCallIndex].pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_MISSED_CALL;
            mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->dialedCalls[chis_p->currMissedCallIndex].pbName);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_MISSED_CALL;
        mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*)chis_p->missedCalls[chis_p->currMissedCallIndex].number);
    }

    DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
    DeleteScreenIfPresent(SCR8520_CALL_MISSED);
    DeleteScreenIfPresent(SCR8056_CALLS_LIST_MISSED);
#ifdef __MMI_CH_MIXED_CALL_LOG__    
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTCallVTRecvdNum
 * DESCRIPTION
 *  To make a video call to recvd list entry
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallVTRecvdNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].number[0] == 0)
    {
        if (chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_RECVD_CALL;
            mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].pbName);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_RECVD_CALL;
        mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->recvdCalls[chis_p->currRecvdCallIndex].number);
    }

    DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
    DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);
    DeleteScreenIfPresent(SCR8054_CALLS_LIST_RECEIVED);
#ifdef __MMI_CH_MIXED_CALL_LOG__    
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif /* __MMI_CH_MIXED_CALL_LOG__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTCallVTMixedNum
 * DESCRIPTION
 *  make call to a single entry in mixed call list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTCallVTMixedNum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->mixedCalls[chis_p->currMixedCallIndex]->number[0] == 0)
    {
        if (chis_p->mixedCalls[chis_p->currMixedCallIndex]->pbName[0] != 0)
        {
            chis_p->dialFromCallLog = ITEM_MIXED_CALL;
            mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->pbName);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_NONUMBER_TO_DIAL),
                IMG_GLOBAL_ERROR,
                1,
                CS_NOTIFYDURATION,
                ERROR_TONE);
        }
    }
    else
    {
        chis_p->dialFromCallLog = ITEM_MIXED_CALL;
        mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) chis_p->mixedCalls[chis_p->currMixedCallIndex]->number);
    }

    if (IsScreenPresent(SCR8008_CALL_DIALED))
    {
        DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
        DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    }
    else if (IsScreenPresent(SCR8520_CALL_MISSED))
    {    
        DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);
        DeleteScreenIfPresent(SCR8520_CALL_MISSED);    
    }
    else if (IsScreenPresent(SCR8006_CALL_RECEIVED))
    {        
        DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);
        DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);   
    }
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
    return;
}
#endif /* def __MMI_VIDEO_TELEPHONY_DEDICATE_KEY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_chist_delete_miss_call_notify_screen
 * DESCRIPTION
 * delete_miss_call_notify_screen
 *  
 *  
 * PARAMETERS
 *  call        [IN]     
 *  type        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_chist_delete_miss_call_notify_screen(void)
{
    if (GetExitScrnID() == ITEM_SCR_MISSED_CALL)
        GoBackHistory();
    else if (IsScreenPresent(ITEM_SCR_MISSED_CALL))
        DeleteScreenIfPresent(ITEM_SCR_MISSED_CALL);
#ifdef __MMI_DUAL_SIM_MASTER__
    DeleteScreenIfPresent(SCR_MTPNP_CALL_HISTORY_NOTIFY);
#endif /* __MMI_DUAL_SIM_MASTER__ */
    g_chist_have_missed_call = 0;
    mmi_chist_set_have_missed_call();
    HideStatusIcon(STATUS_ICON_MISSED_CALL);
    /* Add two statusicons on sublcd */
#ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
    HideStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
#endif /* __MMI_SUBLCD_SHORT_STATUSICON_LIST__ */ 
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  ConvertRTC2MYTIME
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [OUT]
 *  rtc         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void ConvertRTC2MYTIME(MYTIME *time, CALL_LOG_RTCTIMEFORMAT *rtc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time->nYear = (rtc->rtc_year) + YEARFORMATE;
    time->nMonth = rtc->rtc_mon;
    time->nDay = rtc->rtc_day;
    time->nHour = rtc->rtc_hour;
    time->nMin = rtc->rtc_min;
    time->nSec = rtc->rtc_sec;
    time->DayIndex = rtc->rtc_wday;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ConvertMYTIME2RTC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc         [?]         
 *  time        [?]         
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/
void ConvertMYTIME2RTC(CALL_LOG_RTCTIMEFORMAT *rtc, MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rtc->rtc_year = (U8) ((time->nYear) - YEARFORMATE);
    rtc->rtc_mon = time->nMonth;
    rtc->rtc_day = time->nDay;
    rtc->rtc_hour = time->nHour;
    rtc->rtc_min = time->nMin;
    rtc->rtc_sec = time->nSec;
    rtc->rtc_wday = time->DayIndex;
    return;
}


#ifdef __MMI_UI_CALL_LOG_IN_TAB_PANE__
/*****************************************************************************
 * FUNCTION
 *  CHISTDeleteTabPaneScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc         [?]         
 *  time        [?]         
 *  void(?)     [IN]        *
 * RETURNS
 *  void
 *****************************************************************************/

void CHISTDeleteTabPaneScreen(void)
{

#ifdef __MMI_CH_MIXED_CALL_LOG__
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif
    DeleteScreenIfPresent(SCR8056_CALLS_LIST_MISSED);
    DeleteScreenIfPresent(SCR8520_CALL_MISSED);
    DeleteScreenIfPresent(SCR8521_MISSED_CALL_OPTIONS);

#ifdef __MMI_CH_MIXED_CALL_LOG__
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif
    DeleteScreenIfPresent(SCR8054_CALLS_LIST_RECEIVED);
    DeleteScreenIfPresent(SCR8006_CALL_RECEIVED);
    DeleteScreenIfPresent(SCR8007_RECEIVED_CALL_OPTIONS);

    DeleteScreenIfPresent(SCR8055_CALLS_LIST_DIALED);
#ifdef __MMI_CH_MIXED_CALL_LOG__
    DeleteScreenIfPresent(SCR8057_CALLS_LIST_MIXED);
#endif
    DeleteScreenIfPresent(SCR8008_CALL_DIALED);
    DeleteScreenIfPresent(SCR8009_DIALED_CALL_OPTIONS);
}
#endif /* __MMI_UI_CALL_LOG_IN_TAB_PANE__ */


void mmi_chist_set_processing_flag(U8 state)
{
    chis_p->process = state;
}

const U8 mmi_chist_get_processing_flag(void)
{
    return chis_p->process;
}

void mmi_chist_set_sentreq_flag(BOOL state)
{
    chis_p->isReqSent = state;
}

const BOOL mmi_chist_get_sentreq_flag(void)
{
    return chis_p->isReqSent;
}

void mmi_chist_set_missed_call_flag(U8 has_missed_call)
{
    g_chist_have_missed_call = has_missed_call;
}

const U8 mmi_chist_get_missed_call_flag(void)
{
    return g_chist_have_missed_call;
}
#endif /* _CALL_LOG_C */ 

