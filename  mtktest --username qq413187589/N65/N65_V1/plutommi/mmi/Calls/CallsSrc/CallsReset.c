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
 * CallsReset.C
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

   FILENAME : CallsReset.c

   PURPOSE     : Call reset submodule of call history Application

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 10/22/2003

**************************************************************/

#include "MMI_include.h"
#ifndef _CALLS_RESET_C
#define _CALLS_RESET_C

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "ProtocolEvents.h"
#include "IdleAppProt.h"
#include "CommonScreens.h"
#include "wgui_status_icons.h"

#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookTypes.h"
#include "CallManagementStruct.h"

#include "CallHistoryEnum.h"
#include "CallsDefs.h"
#include "CallsStruct.h"
#include "CallsLog.h"
#include "CallsReset.h"

/*
 * Local Variable
 */
extern U8 g_chist_have_missed_call;

/*****************************************************************************
 * FUNCTION
 *  InitCallsReset
 * DESCRIPTION
 *  Set highlite/hint handlers for sub menu items.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallsReset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the highlight handler for sub menu items */
    SetHiliteHandler(MENU8113_CALLHISTORY_RESETCALL, HighlightCHISTResetCallLog);
    SetHiliteHandler(MENU_DIALED_CALLS, HighlightCHISTDeleteAllDialed);
    SetHiliteHandler(MENU_MISSED_CALLS, HighlightCHISTDeleteAllMissed);
    SetHiliteHandler(MENU_RECEIVED_CALLS, HighlightCHISTDeleteAllRecvd);
    SetHiliteHandler(MENU_ALL_CALLS, HighlightCHISTDeleteAllLogs);

    /* Set the hinthandlers for the sub menu items */
    SetHintHandler(MENU_DIALED_CALLS, HintCHISTDialedCalls);
    SetHintHandler(MENU_MISSED_CALLS, HintCHISTMissedCalls);
    SetHintHandler(MENU_RECEIVED_CALLS, HintCHISTRecvdCalls);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTResetCallLog
 * DESCRIPTION
 *  Function called when reset is highlited
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTResetCallLog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the left/right arrow key functions */
    SetKeyHandler(EntryCHISTResetCallLog, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* Set the left and right soft key functions */
    SetLeftSoftkeyFunction(EntryCHISTResetCallLog, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteAllDialed
 * DESCRIPTION
 *  Dial call list option Delete All handler
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteAllDialed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->isDeleteAll = FALSE;

    /* Check if the number of dialed calls is zero or not */
    if (chis_p->nDialedCalls != 0)
    {
        /* dialed calls count is non zero */
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* 3 Register function for left soft key */
        SetLeftSoftkeyFunction(EntryCHISTDeleteAllDialedConfirm, KEY_EVENT_UP);
    }
    else
    {
        /* dialed calls count is zero then disable left soft key */
        ChangeLeftSoftkey(0, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteAllMissed
 * DESCRIPTION
 *  Missed call list option delete all handler
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteAllMissed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->isDeleteAll = FALSE;

    /* Check if the number of missed calls is zero or not */
    if (chis_p->nMissedCalls != 0)
    {
        /* missed calls count is non zero */
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* Register function for left soft key */
        SetLeftSoftkeyFunction(EntryCHISTDeleteAllMissedConfirm, KEY_EVENT_UP);
    }
    else
    {
        /* Missed calls count is zero then disable left soft key */
        ChangeLeftSoftkey(0, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteAllRecvd
 * DESCRIPTION
 *  Recd call list option Delete All handler
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteAllRecvd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chis_p->isDeleteAll = FALSE;

    /* Check if the number of received calls is zero or not */
    if (chis_p->nRecvdCalls != 0)
    {
        /* received calls count is non zero */
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* Register function for left soft key */
        SetLeftSoftkeyFunction(EntryCHISTDeleteAllRecvdConfirm, KEY_EVENT_UP);
    }
    else
    {
        /* received calls count is zero then disable left soft key */
        ChangeLeftSoftkey(0, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTDeleteAllLogs
 * DESCRIPTION
 *  Call list option Delete All handler
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTDeleteAllLogs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if the number of dialed calls is zero or not */
    if (chis_p->nDialedCalls != 0)
    {
        chis_p->isDeleteAll = TRUE;
        /* dialed calls count is non zero */
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* 3 Register function for left soft key */
        SetLeftSoftkeyFunction(EntryCHISTDeleteAllDialedConfirm, KEY_EVENT_UP);
    }
    else if (chis_p->nMissedCalls != 0)
    {
        chis_p->isDeleteAll = TRUE;
        /* missed calls count is non zero */
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* 3 Register function for left soft key */
        SetLeftSoftkeyFunction(EntryCHISTDeleteAllMissedConfirm, KEY_EVENT_UP);
    }
    else if (chis_p->nRecvdCalls != 0)
    {
        chis_p->isDeleteAll = TRUE;
        /* recd calls count is non zero */
        /* Change left soft key icon and label */
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* 3 Register function for left soft key */
        SetLeftSoftkeyFunction(EntryCHISTDeleteAllRecvdConfirm, KEY_EVENT_UP);
    }
    else
    {
        /* dialed calls count is zero then disable left soft key */
        ChangeLeftSoftkey(0, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTResetCallLog
 * DESCRIPTION
 *  Entry function of reset calls.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTResetCallLog(void)
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    EntryNewScreen(SCR_CALLHISTORY_RESETCALL, wgui_restore_list_menu_slim_style, EntryCHISTResetCallLog, NULL);
#else /* __MMI_CH_NUMERIC_LIST_ICON__ */ 

    EntryNewScreen(SCR_CALLHISTORY_RESETCALL, NULL, EntryCHISTResetCallLog, NULL);
#endif /* __MMI_CH_NUMERIC_LIST_ICON__ */ 
    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CALLHISTORY_RESETCALL);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU8113_CALLHISTORY_RESETCALL);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MENU8113_CALLHISTORY_RESETCALL ); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU8113_CALLHISTORY_RESETCALL, nStrItemList);
    GetSequenceImageIds(MENU8113_CALLHISTORY_RESETCALL, ItemIcons);
    /* Set current parent id */
    SetParentHandler(MENU8113_CALLHISTORY_RESETCALL);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* Construct the hint handler for the menu items */
    ConstructHintsList(MENU8113_CALLHISTORY_RESETCALL, PopUpList);

#ifdef __MMI_CH_NUMERIC_LIST_ICON__
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
#endif 

    /* Display the screen for the reset call logs */
    ShowCategory52Screen(
        STR_MENU8113_CALLHISTORY_RESETCALL,
        IMG_SCR8056_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        ItemIcons,
        (U8 **)PopUpList,
        0,
        0,
        guiBuffer);

    /* Register function with right softkey */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDeleteAllDialedConfirm
 * DESCRIPTION
 *  Entry funtion for delete dialed list confirmation screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDeleteAllDialedConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isDeleteAll == TRUE)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_CHIST_DELETE_ALL_QUERY),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_CHIST_DELETE_QUERY),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    /* Set left/right soft key functions */
    SetLeftSoftkeyFunction(DeleteAllDialedCalls, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Set the exit function for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDeleteAllMissedConfirm
 * DESCRIPTION
 *  Entry funtion for delete missed call list
 *  confirmation screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDeleteAllMissedConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isDeleteAll == TRUE)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_CHIST_DELETE_ALL_QUERY),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_CHIST_DELETE_QUERY),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    /* Set the left/right soft key functions */
    SetLeftSoftkeyFunction(DeleteAllMissedCalls, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Set the exit function for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTDeleteAllRecvdConfirm
 * DESCRIPTION
 *  Entry funtion for delete received list confirmation screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTDeleteAllRecvdConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (chis_p->isDeleteAll == TRUE)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_CHIST_DELETE_ALL_QUERY),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_CHIST_DELETE_QUERY),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

    /* Set left/right soft key functions */
    SetLeftSoftkeyFunction(DeleteAllRecdCalls, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Set the exit function for the current screen */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteAllDialedCalls
 * DESCRIPTION
 *  To delete all the dialed call entries
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllDialedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    DEL_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear key handler; not to process any other key */
    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* format the message for delete all dialed calls */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_DEL_LAST_NUMBER_REQ;

    dataPtr = (DEL_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(DEL_LAST_NUMBER_REQ));

    dataPtr->type = PHB_LND;
    dataPtr->index = 0xff;
    dataPtr->no_data = 0;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    /* Set the response handler for the delete all missed calls request */
    SetProtocolEventHandler(RspDeleteAllDialedNum, PRT_MMI_PHB_DEL_LAST_NUMBER_RSP);

    /* Send request to l4 for delete all dialed calls */
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspDeleteAllDialedNum
 * DESCRIPTION
 *  Response handler for deleteall dialed calls request.
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspDeleteAllDialedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DEL_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive the data from the response info structure */
    rsp = (DEL_LAST_NUMBER_RSP*) info;

    /* Check the response is success or not */
    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        chis_p->nDialedCalls = 0;
    }

    if (chis_p->isDeleteAll == TRUE)
    {
        if (chis_p->nMissedCalls != 0)
        {
            DeleteAllMissedCalls();
            return;
        }
        else if (chis_p->nRecvdCalls != 0)
        {
            DeleteAllRecdCalls();
            return;
        }
        chis_p->isDeleteAll = FALSE;
    }

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        /* Incase of success */
        /* Display success popup for user notification */
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        /* If failure; then display failure popup for user notification */
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    /* Delete screens in history to go back to reset call main screen */
    /* DeleteUptoScrID(SCR_CALLHISTORY_RESETCALL); */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteAllMissedCalls
 * DESCRIPTION
 *  To delete all the missed call entries
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllMissedCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    DEL_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear key handler; not to process any other key */
    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* format the message for delete all missed calls */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_DEL_LAST_NUMBER_REQ;

    dataPtr = (DEL_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(DEL_LAST_NUMBER_REQ));

    dataPtr->type = PHB_LNM;
    dataPtr->index = 0xff;
    dataPtr->no_data = 0;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    /* Set the response handler for the delete all missed calls request */
    SetProtocolEventHandler(RspDeleteAllMissedNum, PRT_MMI_PHB_DEL_LAST_NUMBER_RSP);

    /* Send request to l4 for delete all missed calls */
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspDeleteAllMissedNum
 * DESCRIPTION
 *  Response handler for deleteallmissedcalls request.
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspDeleteAllMissedNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DEL_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive the data from the response info structure */
    rsp = (DEL_LAST_NUMBER_RSP*) info;

    /* Check the response is success or not */
    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        /* Incase of success */
        /* Reset the missed call icon on idle screen */
        IdleResetStatusIcon(STATUS_ICON_MISSED_CALL);
        /* Reset the missed calls counters */
        /* MTK Leo add 20040322, add two new statusicons on sublcd */
    #ifndef __MMI_SUBLCD_SHORT_STATUSICON_LIST__
        IdleResetStatusIcon(STATUS_ICON_SUBLCD_MISSED_CALL);
    #endif 
        /* MTK Leo end */
        chis_p->nMissedCalls = 0;
        chis_p->nMissedCallBeforeView = 0;
    #ifdef __MMI_DUAL_SIM_MASTER__
        DeleteScreenIfPresent(SCR_MTPNP_CALL_HISTORY_NOTIFY);
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        g_chist_have_missed_call = 0;
    	mmi_chist_set_have_missed_call();
    }

    if (chis_p->isDeleteAll == TRUE)
    {
        if (chis_p->nRecvdCalls != 0)
        {
            DeleteAllRecdCalls();
            return;
        }
        chis_p->isDeleteAll = FALSE;
    }

    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        /* Incase of success */
        /* Display success popup for user notification */
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SAVE_TONE);
    }
    else
    {
        /* If failure; then display failure popup for user notification */
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    /* Delete screens in history to go back to reset call main screen */
    /* DeleteUptoScrID(SCR_CALLHISTORY_RESETCALL); */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  DeleteAllRecdCalls
 * DESCRIPTION
 *  To delete all the recd call entries
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllRecdCalls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    DEL_LAST_NUMBER_REQ *dataPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear key handler; not to process any other key */
    ClearInputEventHandler(MMI_DEVICE_ALL);

    /* format the message for delete all received calls */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PHB_DEL_LAST_NUMBER_REQ;

    dataPtr = (DEL_LAST_NUMBER_REQ*) OslConstructDataPtr(sizeof(DEL_LAST_NUMBER_REQ));

    dataPtr->type = PHB_LNR;
    dataPtr->index = 0xff;
    dataPtr->no_data = 0;

    Message.oslDataPtr = (oslParaType*) dataPtr;
    Message.oslPeerBuffPtr = NULL;

    /* Set the response handler for the delete all received calls request */
    SetProtocolEventHandler(RspDeleteAllRecvdNum, PRT_MMI_PHB_DEL_LAST_NUMBER_RSP);

    /* Send request to l4 for delete all received calls */
    OslMsgSendExtQueue(&Message);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  RspDeleteAllRecvdNum
 * DESCRIPTION
 *  Response handler for deleteall received calls request.
 * NA
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void RspDeleteAllRecvdNum(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DEL_LAST_NUMBER_RSP *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* retrive the data from the response info structure */
    rsp = (DEL_LAST_NUMBER_RSP*) info;

    chis_p->isDeleteAll = FALSE;

    /* Check the response is success or not */
    if (rsp->result.flag == CALL_LOG_RESULT_OK)
    {
        /* Incase of success */
        /* Reset the received calls counters */
        chis_p->nRecvdCalls = 0;
        /* Display success popup for user notification */
        DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);
    }
    else
    {
        /* If failure; then display failure popup for user notification */
        DisplayPopup((PU8) GetString(STR_GLOBAL_UNFINISHED), IMG_GLOBAL_UNFINISHED, 1, CS_NOTIFYDURATION, ERROR_TONE);
    }

    /* Delete screens in history to go back to reset call main screen */
    /* DeleteUptoScrID(SCR_CALLHISTORY_RESETCALL); */
    return;
}

#endif /* _CALLS_RESET_C */ 

