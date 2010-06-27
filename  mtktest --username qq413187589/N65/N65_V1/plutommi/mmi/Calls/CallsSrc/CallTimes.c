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
 * CallTimes.C
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

   FILENAME : CallTimes.c 

   PURPOSE     : To maintain call times in call history

   REMARKS     : nil

   AUTHOR      : Anil Kumar Vutukuru

   DATE     : 10/22/2003

**************************************************************/

#include "MMI_include.h"
#ifndef _CALL_TIMES_C
#define _CALL_TIMES_C

/*  Include: MMI header file */

/* ... Add More MMI header */
#include "wgui_inline_edit.h"
#include "CommonScreens.h"

#include "SettingDefs.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "PhoneBookTypes.h"
#include "CallSetupEnum.h"


#include "CallHistoryEnum.h"
#include "CallsStruct.h"
#include "CallsDefs.h"
#include "CallTimes.h"

/* diamond, 2005/06/13 reset call time with phone lock check */
#ifdef __MMI_KLG__
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#include "SettingGenum.h"
#endif /* __MMI_KLG__ */ 
/* end, diamond */


#ifdef __MMI_CH_QUICK_END__
U8 *QuickEndString[2];
U8 QuickEndInput[20];
#endif /* __MMI_CH_QUICK_END__ */ 


/*****************************************************************************
 * FUNCTION
 *  InitCallTimes
 * DESCRIPTION
 *  Set highlite/hint handlers for sub menu items.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCallTimes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the highlight handler for sub menu items */
    SetHiliteHandler(MENU_CALL_TIME_SETUP, HighlightCHISTCallTime);
    SetHiliteHandler(MENU_LAST_CALL_TIME, HighlightCHISTLastTime);
    SetHiliteHandler(MENU_CALL_OUT_TIME, HighlightCHISTSentTime);
    SetHiliteHandler(MENU_CALL_IN_TIME, HighlightCHISTRecvdTime);
    SetHiliteHandler(MENU_ALL_CALL_TIME, HighlightCHISTResetAllTime);
    /* Set the hinthandlers for the sub menu items */
    SetHintHandler(MENU_LAST_CALL_TIME, HintCHISTLastTime);
    SetHintHandler(MENU_CALL_OUT_TIME, HintCHISTSentTime);
    SetHintHandler(MENU_CALL_IN_TIME, HintCHISTRecvdTime);

#ifdef __MMI_CH_QUICK_END__
    SetHiliteHandler(MENU_CALL_HISTORY_QUICK_END, HighlightCHISTQuickEnd);
    SetHintHandler(MENU_CALL_HISTORY_QUICK_END, HintCHISTQuickEnd);
#endif /* __MMI_CH_QUICK_END__ */ 

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTCallTime
 * DESCRIPTION
 *  Call time menu option highlite handler
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTCallTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the left/right arrow key function */
    SetKeyHandler(EntryCHISTCallTime, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* Register functions for left/right soft keys */
    SetLeftSoftkeyFunction(EntryCHISTCallTime, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTLastTime
 * DESCRIPTION
 *  Highlite function for last call time
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTLastTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left/right soft key icon and label */
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Set left/right soft key functions */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTSentTime
 * DESCRIPTION
 *  Highlight function for total call time out
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTSentTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left/right soft key icon and label */
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Set right soft key functions */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTRecvdTime
 * DESCRIPTION
 *  Highlight function for received call time
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTRecvdTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left/right soft key icon and label */
    ChangeLeftSoftkey(0, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Set right softkey functions */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTResetAllTime
 * DESCRIPTION
 *  Highlight handler for reset call time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTResetAllTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    if (CHISTNeedToResetTimes() == 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        /* diamond, 2005/06/13 reset call time with phone lock check */
    #ifdef __MMI_KLG__
        SetLeftSoftkeyFunction(EntryCHISTResetCheckPhoneLock, KEY_EVENT_UP);    /* check phone lock always */
    #else 
        SetLeftSoftkeyFunction(EntryCHISTResetAllTimeConfirm, KEY_EVENT_UP);
    #endif 
        /* end, diamond */
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}

#ifdef __MMI_CH_QUICK_END__


/*****************************************************************************
 * FUNCTION
 *  HighlightCHISTQuickEnd
 * DESCRIPTION
 *  Highlight handler for quick end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCHISTQuickEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryCHISTQuickEnd, KEY_EVENT_UP);
    SetKeyHandler(EntryCHISTQuickEnd, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTQuickEnd
 * DESCRIPTION
 *  Construct hint string for quick end time
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the hint popup to display.
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTQuickEnd(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CH_QUICK_END_FLAG, &chis_p->nQuickEndFlag, DS_BYTE, &error);

    if (chis_p->nQuickEndFlag == 0xff)
    {
        chis_p->nQuickEndFlag = 0;
        WriteValue(NVRAM_CH_QUICK_END_FLAG, &chis_p->nQuickEndFlag, DS_BYTE, &error);
    }

    ReadValue(NVRAM_CH_QUICK_END_TIME, &chis_p->nQuickEndTime, DS_SHORT, &error);
    if (chis_p->nQuickEndTime == 0xffff)
    {
        chis_p->nQuickEndTime = 0;
        WriteValue(NVRAM_CH_QUICK_END_TIME, &chis_p->nQuickEndFlag, DS_SHORT, &error);
    }

    if (chis_p->nQuickEndFlag == 1)
    {
        U8 data[10];

        sprintf((PS8) data, "%d \0", chis_p->nQuickEndTime);
        mmi_asc_to_ucs2((S8*) hintData[index], (S8*) data);
        mmi_ucs2cat((S8*) hintData[index], (S8*) GetString(STR_SECONDS));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }

    return;
}
#endif /* __MMI_CH_QUICK_END__ */ 


/*****************************************************************************
 * FUNCTION
 *  HintCHISTLastTime
 * DESCRIPTION
 *  Construct hint for last call time
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the hint popup to display.
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTLastTime(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Format the time to display for hint popup */
    sprintf(
        (S8*) value,
        "%02d:%02d:%02d",
        chis_p->last_call_time.nHour,
        chis_p->last_call_time.nMin,
        chis_p->last_call_time.nSec);

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTSentTime
 * DESCRIPTION
 *  construct hint string for call total out call time
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the hint popup to display.
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTSentTime(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Format the time to display for hint popup */
    sprintf(
        (S8*) value,
        "%02d:%02d:%02d",
        chis_p->total_out_time.nHour,
        chis_p->total_out_time.nMin,
        chis_p->total_out_time.nSec);

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  HintCHISTRecvdTime
 * DESCRIPTION
 *  Construct hint string for in call time
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the hint popup to display.
 * RETURNS
 *  void
 *****************************************************************************/
void HintCHISTRecvdTime(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Format the time to display for hint popup */
    sprintf(
        (S8*) value,
        "%02d:%02d:%02d",
        chis_p->total_in_time.nHour,
        chis_p->total_in_time.nMin,
        chis_p->total_in_time.nSec);

    mmi_asc_to_ucs2((S8*) hintData[index], (S8*) value);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTCallTime
 * DESCRIPTION
 *  Entry screen for call times.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTCallTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */

    // U16  nDispAttribute; /* Stores display attribue */
    U8 *guiBuffer;          /* Buffer holding history data */
    U8 *displayBuffer[MAX_SUB_MENUS];
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */
    EntryNewScreen(SCR_CALL_TIME_SETUP_MAIN, NULL, EntryCHISTCallTime, NULL);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 1, (void*)&chis_p->last_call_time, sizeof(MYTIME), &error);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 2, (void*)&chis_p->total_out_time, sizeof(MYTIME), &error);

    ReadRecord(NVRAM_EF_CALL_TIME_LID, 3, (void*)&chis_p->total_in_time, sizeof(MYTIME), &error);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CALL_TIME_SETUP_MAIN);
    /* Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_CALL_TIME_SETUP);
    /* Get attribute of menu to be displayed */
    /* nDispAttribute = GetDispAttributeOfItem( MENU_CALL_TIME_SETUP ); */
    /* Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_CALL_TIME_SETUP, nStrItemList);
    /* Set current parent id */
    SetParentHandler(MENU_CALL_TIME_SETUP);
    /* Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* Construct hint for menu items */
    ConstructHintsList(MENU_CALL_TIME_SETUP, displayBuffer);

    /* Display Category1 Screen */
    ShowCategory52Screen(
        STR_MENU_CALL_TIME_SETUP,
        IMG_MENU_CALL_TIMES,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        displayBuffer,
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
 *  EntryCHISTResetAllTimeConfirm
 * DESCRIPTION
 *  Entry function for call time reset confirm screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTResetAllTimeConfirm(void)
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
        get_string(STR_RESET_ALL_CALL_TIME_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* set left/right soft key functions */
    SetLeftSoftkeyFunction(CHISTResetAllTime, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    /* Set exit funtion for the current screen */
    return;
}

#ifdef __MMI_CH_QUICK_END__


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTQuickEnd
 * DESCRIPTION
 *  Entry function for set quick end time screen
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTQuickEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 QuickEndIcons[4] = {IMG_SETTING_GREET_STATUS, 0, IMG_TIME, 0};
    extern wgui_inline_item wgui_inline_items[];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_CALL_TIME_QUICK_END, ExitCHISTQuickEnd, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_CALL_TIME_QUICK_END);

    InitializeCategory57Screen();

    memset(wgui_inline_items, 0, sizeof(wgui_inline_item) * MAX_INLINE_ITEMS);
    CHISTQuickEndFillInlineStruct((void*)wgui_inline_items);

    inputBuffer = GetCurrNInputBuffer(SCR_CALL_TIME_QUICK_END, &inputBufferSize);       /* added for inline edit history */

    if (inputBuffer != NULL)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, 4, inputBuffer);   /* sets the data */
    }

    RegisterHighlightHandler(CHISTQuickEndHiliteHandler);
    DisableCategory57ScreenDone();
    ShowCategory57Screen(
        STR_MENU_QUICK_END,
        GetRootTitleIcon(MENU_CALL_HISTORY_QUICK_END),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        4,
        QuickEndIcons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(CHISTSetQuickEndTime, GoBackHistory);
    DisableCategory57ScreenDone();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCHISTQuickEnd
 * DESCRIPTION
 *  This function is Exit function for Quick End
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCHISTQuickEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Scr.scrnID = SCR_CALL_TIME_QUICK_END;
    CloseCategory57Screen();
    Scr.entryFuncPtr = EntryCHISTQuickEnd;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  CHISTQuickEndFillInlineStruct
 * DESCRIPTION
 *  This function is to fill inline selection structure for Quick End Time
 *  Functionality:
 * PARAMETERS
 *  p           [?]             
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTQuickEndFillInlineStruct(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data[10];
    wgui_inline_item *setting_inline_edit_items = (wgui_inline_item*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CH_QUICK_END_FLAG, &chis_p->nQuickEndFlag, DS_BYTE, &error);
    ReadValue(NVRAM_CH_QUICK_END_TIME, &chis_p->nQuickEndTime, DS_SHORT, &error);

    QuickEndString[0] = (PU8) GetString(STR_GLOBAL_OFF);
    QuickEndString[1] = (PU8) GetString(STR_GLOBAL_ON);
    sprintf((PS8) data, "%d\0", chis_p->nQuickEndTime);
    mmi_asc_to_ucs2((PS8) QuickEndInput, (PS8) data);

    SetInlineItemActivation(&(setting_inline_edit_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, KEY_EVENT_UP);
    SetInlineItemActivation(&(setting_inline_edit_items[3]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, KEY_EVENT_UP);

    SetInlineItemCaption(&(setting_inline_edit_items[0]), (U8*) GetString(STR_MENU_QUICK_END_SET));
    SetInlineItemSelect(&(setting_inline_edit_items[1]), 2, (U8 **) QuickEndString, (S32*) & chis_p->nQuickEndFlag);
    SetInlineItemFullWidth(&setting_inline_edit_items[1]);

    SetInlineItemCaption(&(setting_inline_edit_items[2]), (U8*) GetString(STR_MENU_QUICK_END_DURATION));
    SetInlineItemTextEdit(&(setting_inline_edit_items[3]), QuickEndInput, 5, INPUT_TYPE_NUMERIC);
}


/*****************************************************************************
 * FUNCTION
 *  CHISTQuickEndHiliteHandler
 * DESCRIPTION
 *  This function is Inline line editor Highlight handler for Quick End TIme
 *  Follow functions:
 * PARAMETERS
 *  currId      [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTQuickEndHiliteHandler(S32 currId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetCategory57LeftSoftkeyFunction(CHISTSetQuickEndTime);
}


/*****************************************************************************
 * FUNCTION
 *  CHISTSetQuickEndTime
 * DESCRIPTION
 *  Sets quick end time.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTSetQuickEndTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 data[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((PS8) data, (PS8) QuickEndInput);
    chis_p->nQuickEndTime = atoi((PS8) data);

    if (chis_p->nQuickEndFlag == MMI_TRUE && chis_p->nQuickEndTime == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID), IMG_GLOBAL_ERROR, 0, 1000, WARNING_TONE);
        return;
    }
    WriteValue(NVRAM_CH_QUICK_END_FLAG, &chis_p->nQuickEndFlag, DS_BYTE, &error);
    WriteValue(NVRAM_CH_QUICK_END_TIME, &chis_p->nQuickEndTime, DS_SHORT, &error);

    /* Display success popup for reset */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);

    /* delete screens from history to go to main call history screen */
    DeleteScreenIfPresent(SCR_CALL_TIME_QUICK_END);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTGetQuickEndTime
 * DESCRIPTION
 *  Sets quick end time.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 CHISTGetQuickEndTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CH_QUICK_END_FLAG, &chis_p->nQuickEndFlag, DS_BYTE, &error);
    if (chis_p->nQuickEndFlag == 0xff)
    {
        chis_p->nQuickEndFlag = 0;
        WriteValue(NVRAM_CH_QUICK_END_FLAG, &chis_p->nQuickEndFlag, DS_BYTE, &error);
    }
    if (chis_p->nQuickEndFlag > 0)
    {
        ReadValue(NVRAM_CH_QUICK_END_TIME, &chis_p->nQuickEndTime, DS_SHORT, &error);
        if (chis_p->nQuickEndTime == 0xffff)
        {
            chis_p->nQuickEndTime = 0;
            WriteValue(NVRAM_CH_QUICK_END_TIME, &chis_p->nQuickEndFlag, DS_SHORT, &error);
        }

        return chis_p->nQuickEndTime;
    }
    else
    {
        return 0;
    }
}
#endif /* __MMI_CH_QUICK_END__ */ 


/*****************************************************************************
 * FUNCTION
 *  CHISTResetAllTime
 * DESCRIPTION
 *  Resets the all call times.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTResetAllTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset the last call time */
    memset(&chis_p->last_call_time, 0, sizeof(MYTIME));
    /* Reset the total out time */
    memset(&chis_p->total_out_time, 0, sizeof(MYTIME));
    /* Reset the total in time */
    memset(&chis_p->total_in_time, 0, sizeof(MYTIME));

    WriteRecord(NVRAM_EF_CALL_TIME_LID, 1, (void*)&chis_p->last_call_time, sizeof(MYTIME), &error);
    WriteRecord(NVRAM_EF_CALL_TIME_LID, 2, (void*)&chis_p->total_out_time, sizeof(MYTIME), &error);
    WriteRecord(NVRAM_EF_CALL_TIME_LID, 3, (void*)&chis_p->total_in_time, sizeof(MYTIME), &error);

    /* Display success popup for reset */
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, CS_NOTIFYDURATION, SUCCESS_TONE);

    /* delete screens from history to go to main calltime screen */
    DeleteUptoScrID(SCR_CALL_TIME_SETUP_MAIN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  CHISTNeedToResetTimes
 * DESCRIPTION
 *  Reset times to be done or not.
 * NA
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
BOOL CHISTNeedToResetTimes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    U8 *buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buf = (U8*) & chis_p->last_call_time;
    /* Check whether last call time is zero or not */
    for (count = 0; count < sizeof(MYTIME); count++)
    {
        /* if non zero return 1 */
        if (buf[count] != 0)
        {
            return TRUE;
        }
    }
    buf = (U8*) & chis_p->total_out_time;
    /* Check whether total out call time is zero or not */
    for (count = 0; count < sizeof(MYTIME); count++)
    {
        /* if non zero return 1 */
        if (buf[count] != 0)
        {
            return TRUE;
        }
    }
    buf = (U8*) & chis_p->total_in_time;
    /* Check whether total in call time is zero or not */
    for (count = 0; count < sizeof(MYTIME); count++)
    {
        /* if non zero return 1 */
        if (buf[count] != 0)
        {
            return TRUE;
        }
    }
    /* call time reset is not to be done as its already in reset mode */
    return FALSE;
}

/* diamond, 2005/06/13 reset call time with phone lock check */
#ifdef __MMI_KLG__

extern void SECSETVerifyPINReq(U8 pin_type, U8 *ucs2_pin, U8 *ucs2_new_pin, FuncPtr success_callback);
extern void RstrSettingPasswdScrSoftKeyFunc(U8 *text, U8 *cursor, S32 length);

extern U8 gPhonePassword[];


/*****************************************************************************
 * FUNCTION
 *  CHISTResetVerifyPhoneLockReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CHISTResetVerifyPhoneLockReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempBuffer[(MAX_SIM_SETTING_PASSWD_LEN + 1)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempBuffer, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    SECSETVerifyPINReq(MMI_SETTING_TYPE_PHONELOCK, gPhonePassword, tempBuffer, EntryCHISTResetAllTimeConfirm);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCHISTResetCheckPhoneLock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCHISTResetCheckPhoneLock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "=== EntryCHISTResetCheckPhoneLock() ===\n");

    /* Call Exit Handler */
    EntryNewScreen(SCR_CALL_TIME_RESET, NULL, EntryCHISTResetCheckPhoneLock, NULL);

    /* Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_CALL_TIME_RESET);

    /* check the screen flow is from forward or backward */
    if (guiBuffer == NULL)
    {
        memset(gPhonePassword, 0, (MAX_SIM_SETTING_PASSWD_LEN + 1));
    }

    /* register the input validation function handler */
    RegisterInputBoxValidationFunction(RstrSettingPasswdScrSoftKeyFunc);

    /* display the corresponding catergory function */
    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_RESTORE_PHONE,
        INPUT_TYPE_NUMERIC_PASSWORD,
        gPhonePassword,
        (MAX_SIM_SETTING_PASSWD_LEN + 1),
        NULL,
        NULL);

    /* Register function with left/right softkey */
    SetCategory111RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(CHISTResetVerifyPhoneLockReq, KEY_EVENT_UP);

    /* register the key handler function for the pound key */
    SetKeyHandler(CHISTResetVerifyPhoneLockReq, KEY_POUND, KEY_EVENT_UP);

    gSecuritySetupContext.PasswdLenCheckCallBack = CHISTResetVerifyPhoneLockReq;
    if (mmi_ucs2strlen((S8*) gSecuritySetupContext.Password) < MIN_PASSWORD_LENGTH)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_POUND, KEY_EVENT_UP);
    }

}

#endif /* __MMI_KLG__ */ 
/* end, diamond */

#endif /* _CALL_TIMES_C */ 

