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
 * TypicalStopwatch.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for phone setup application
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
/***************** Stopwatch Application implementation *********************/

/**************************************************************

   FILENAME : TypicalStopwatch.c

   PURPOSE     : Typical Stopwatch application implementation

   REMARKS     : nil

   AUTHOR      : Deepali Gupta

   DATE     : 05/01/2004

**************************************************************/
#include "MMI_include.h"
#ifdef __MMI_STOPWATCH__

/***********  Include: MMI header file **************/
#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "CommonScreens.h"
#include "MainMenuDef.h"
#include "ProfileGprots.h"

#include "StopwatchResDef.h"
#include "StopwatchGprot.h"
#include "StopwatchProt.h"

#include "gpioInc.h"
#include "wgui_status_icons.h"


wtchCntxStruct gStopwatchAppInfo;    
stopwatchRecord gTimerRecordList[MAX_STOPWATCH_RECORDS];
UI_stop_watch gCurrentRecords[MAX_TIMER_RECORDS];


/***************************************************************************** 
* Define
*****************************************************************************/
#if (!defined(NVRAM_EF_STOPWATCH_RECORD_SIZE))
#define NVRAM_EF_STOPWATCH_RECORD_SIZE sizeof(gTimerRecordList)
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable (Local to this file - static)
*****************************************************************************/

/***************************************************************************** 
* Local Function (local to this file - static)
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/**********************************************************************
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  InitStopwatchApp
 * DESCRIPTION
 *  Initialize stopwatch Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitStopwatchApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_STOPWATCH, HighlightStopwatch);
    SetHiliteHandler(MENU_TYPICALSTOPWATCH, HighlightTypicalStopwatch);
    SetHiliteHandler(MENU_MULTIPURPOSEWATCH, HighlightMultipurposeStopwatch);

    SetHiliteHandler(MENU_SPLIT_TIMING, HighlightSplitTiming);
    SetHiliteHandler(MENU_LAP_TIMING, HighlightLapTiming);
    SetHiliteHandler(MENU_VIEW_RECORD, HighlightViewRecord);

    SetHiliteHandler(MENU_SAVE_DONE, HighlightOptionDone);
    SetHiliteHandler(MENU_SAVE_INPUTMETHOD, HighlightOptionInputMethod);

    SetHiliteHandler(MENU_OPTION_VR_VIEW, HighlightOptionView);
    SetHiliteHandler(MENU_OPTION_VR_DELETE, HighlightOptionDelete);
    SetHiliteHandler(MENU_OPTION_VR_DELETE_ALL, HighlightOptionDeleteAll);

    InitMultipurposeStopwatch();
    ResetTypicalStopwatch();
}


/*****************************************************************************
 * FUNCTION
 *  InitStopwatchNVRAM
 * DESCRIPTION
 *  Initialize NVRAM for Stopwatch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitStopwatchNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], MAX_STOPWATCH_RECORDS * sizeof(stopwatchRecord), &error);
    ReadValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);

    if (gStopwatchAppInfo.numOfSavedTimerRecords == 0xFF)
    {
        gStopwatchAppInfo.numOfSavedTimerRecords = 0;
        WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
    }

}


/*****************************************************************************
 * FUNCTION
 *  HighlightStopwatch
 * DESCRIPTION
 *  Highlight handler fn for stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrStopwatch, KEY_EVENT_UP);
    SetKeyHandler(EntryWtchScrStopwatch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightTypicalStopwatch
 * DESCRIPTION
 *  Highlight handler fn for Typical stopwatch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightTypicalStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrTypicalStopwatch, KEY_EVENT_UP);
    SetKeyHandler(EntryWtchScrTypicalStopwatch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightMultipurposeStopwatch
 * DESCRIPTION
 *  Highlight handler function for Multipurpose stop watch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightMultipurposeStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrMultipurposeStopwatch, KEY_EVENT_UP);
    SetKeyHandler(EntryWtchScrMultipurposeStopwatch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* ClearKeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightSplitTiming
 * DESCRIPTION
 *  Highlight handler fn for Split timing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightSplitTiming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gStopwatchAppInfo.TimerState != TIMER_NOT_STARTED) && (gStopwatchAppInfo.splitLapTimer == LAP_TIMER))
    {
        SetLeftSoftkeyFunction(DisplayDiscontinueTimerQuery, KEY_EVENT_UP);
        SetKeyHandler(DisplayDiscontinueTimerQuery, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        gStopwatchAppInfo.splitLapTimer = SPLIT_TIMER;
        /* Register function for left soft key */
        SetLeftSoftkeyFunction(EntryWtchScrSplitLapTimingStopwatch, KEY_EVENT_UP);
        SetKeyHandler(EntryWtchScrSplitLapTimingStopwatch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightLapTiming
 * DESCRIPTION
 *  Highlight handler fn for Lap Timing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightLapTiming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gStopwatchAppInfo.TimerState != TIMER_NOT_STARTED) && (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER))
    {
        SetLeftSoftkeyFunction(DisplayDiscontinueTimerQuery, KEY_EVENT_UP);
        SetKeyHandler(DisplayDiscontinueTimerQuery, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        gStopwatchAppInfo.splitLapTimer = LAP_TIMER;
        /* Register function for left soft key */
        SetLeftSoftkeyFunction(EntryWtchScrSplitLapTimingStopwatch, KEY_EVENT_UP);
        SetKeyHandler(EntryWtchScrSplitLapTimingStopwatch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightViewRecord
 * DESCRIPTION
 *  Highlight handler fn for View record
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightViewRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.currHilitedRecord = 0;

    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrViewRecord, KEY_EVENT_UP);
    SetKeyHandler(EntryWtchScrViewRecord, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    /* ClearKeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightOptionDone
 * DESCRIPTION
 *  Highlight handler for option Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOptionDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    if (gStopwatchAppInfo.replaceRecord == TRUE)
    {
        SetLeftSoftkeyFunction(ReplaceSelectedRecord, KEY_EVENT_UP);
        SetKeyHandler(ReplaceSelectedRecord, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(SaveTimerRecord, KEY_EVENT_UP);
        SetKeyHandler(SaveTimerRecord, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* ClearKeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  HighlightOptionInputMethod
 * DESCRIPTION
 *  Highlight handler fn for option Input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOptionInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    RegisterInputMethodScreenCloseFunction(GoBackHistoryFnFromInputMethod);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightOptionView
 * DESCRIPTION
 *  Highlight handler fn for option View
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOptionView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrViewSavedRecord, KEY_EVENT_UP);
    SetKeyHandler(EntryWtchScrViewSavedRecord, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    //ClearKeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
    //ClearKeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightOptionDelete
 * DESCRIPTION
 *  Highlight handler fn for option Delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOptionDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrDeleteRecord, KEY_EVENT_UP);
    /* SetKeyHandler(EntryWtchScrDeleteRecord,KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* ClearKeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  HighlightOptionDeleteAll
 * DESCRIPTION
 *  Highlight handler fn for option Delete All.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightOptionDeleteAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Change left soft key icon and label */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    /* 2 Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    /* 3 Register function for left soft key */
    SetLeftSoftkeyFunction(EntryWtchScrDeleteAllRecord, KEY_EVENT_UP);
    /* SetKeyHandler(EntryWtchScrDeleteAllRecord,KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    /* ClearKeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrStopwatch
 * DESCRIPTION
 *  Entry fn for Stopwatch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[15];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 nDispAttribute;     /* Stores display attribue */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_STOPWATCH, NULL, EntryWtchScrStopwatch, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_STOPWATCH);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_STOPWATCH);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_STOPWATCH);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_STOPWATCH, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_STOPWATCH);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category Screen */
    ShowCategory15Screen(
        STR_STOPWATCH_TITLE,
        GetRootTitleIcon(MENU_STOPWATCH),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* SetExitHandler(SCR_STOPWATCH,ExitWtchScrStopwatch); */
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrTypicalStopwatch
 * DESCRIPTION
 *  Entry fn for Typical Stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrTypicalStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[15];   /* Stores the strings id of submenus returned */
    U16 nNumofItem;         /* Stores no of children in the submenu */
    U16 nDispAttribute;     /* Stores display attribue */
    U8 *guiBuffer;          /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_TYPICAL_STOPWATCH, NULL, EntryWtchScrTypicalStopwatch, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_TYPICAL_STOPWATCH);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_TYPICALSTOPWATCH);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_TYPICALSTOPWATCH);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_TYPICALSTOPWATCH, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_TYPICALSTOPWATCH);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category Screen */
    ShowCategory15Screen(
        STR_TYPICAL_STOPWATCH,
        GetRootTitleIcon(MENU_TYPICALSTOPWATCH),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* SetExitHandler(SCR_TYPICAL_STOPWATCH,ExitWtchScrTypicalStopwatch); */

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrSplitLapTimingStopwatch
 * DESCRIPTION
 *  Entry fn for Split/Lap timing stopwatch screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrSplitLapTimingStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_SPLIT_TIMING, ExitWtchScrSplitLapTimingStopwatch, EntryWtchScrSplitLapTimingStopwatch, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_SPLIT_TIMING);

    /* 6 Set current parent id */
    SetParentHandler(MENU_SPLIT_TIMING);

    memset(gStopwatchAppInfo.recordName, 0, (MAX_RECORD_NAME_LENGTH + 1) * ENCODING_LENGTH);
    /* 8 Display Category Screen */
    /* entry_full_screen();//053005 Calvin moved to inside of ShowCategory307Screen */
    if (gStopwatchAppInfo.TimerState == TIMER_NOT_STARTED)
    {
        if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
        {
            ShowCategory307Screen(
                STR_STOPWATCH_START,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                0,
                NULL,
                0,
                guiBuffer,
                IMG_TYPICALSW_BACKGROUND,
                CONTINUE_TIMER);
        }
        else
        {
            ShowCategory307Screen(
                STR_STOPWATCH_START,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                0,
                NULL,
                0,
                guiBuffer,
                IMG_TYPICALSW_BACKGROUND,
                STOP_START_AGAIN);
        }
        SetLeftSoftkeyFunction(StartSplitLapTimer, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else if (gStopwatchAppInfo.TimerState == TIMER_STOPPED)
    {
        if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
        {
            ShowCategory307Screen(
                STR_STOPWATCH_RESUME,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                gStopwatchAppInfo.numofCurrTimerRecords,
                gCurrentRecords,
                0,
                guiBuffer,
                IMG_TYPICALSW_BACKGROUND,
                CONTINUE_TIMER);
        }
        else
        {
            ShowCategory307Screen(
                STR_STOPWATCH_RESUME,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                gStopwatchAppInfo.numofCurrTimerRecords,
                gCurrentRecords,
                0,
                guiBuffer,
                IMG_TYPICALSW_BACKGROUND,
                STOP_START_AGAIN);
        }

        SetLeftSoftkeyFunction(ResumeSplitLapTimer, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(ResetSplitLapTimer, KEY_LONG_PRESS);
        SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);
    }
    else
    {
        if (gStopwatchAppInfo.numofCurrTimerRecords < MAX_TIMER_RECORDS)
        {
            if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
            {
                ShowCategory307Screen(
                    STR_STOPWATCH_STOP,
                    0,
                    STR_STOPWATCH_SPLIT,
                    IMG_GLOBAL_BACK,
                    gStopwatchAppInfo.numofCurrTimerRecords,
                    gCurrentRecords,
                    0,
                    guiBuffer,
                    IMG_TYPICALSW_BACKGROUND,
                    CONTINUE_TIMER);
            }
            else
            {
                ShowCategory307Screen(
                    STR_STOPWATCH_STOP,
                    0,
                    STR_STOPWATCH_LAP,
                    IMG_GLOBAL_BACK,
                    gStopwatchAppInfo.numofCurrTimerRecords,
                    gCurrentRecords,
                    0,
                    guiBuffer,
                    IMG_TYPICALSW_BACKGROUND,
                    STOP_START_AGAIN);
            }

            SetRightSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
        }
        else
        {
            if (gStopwatchAppInfo.splitLapTimer == SPLIT_TIMER)
            {
                ShowCategory307Screen(
                    STR_STOPWATCH_STOP,
                    0,
                    0,
                    0,
                    gStopwatchAppInfo.numofCurrTimerRecords,
                    gCurrentRecords,
                    0,
                    guiBuffer,
                    IMG_TYPICALSW_BACKGROUND,
                    CONTINUE_TIMER);
            }
            else
            {
                ShowCategory307Screen(
                    STR_STOPWATCH_STOP,
                    0,
                    0,
                    0,
                    gStopwatchAppInfo.numofCurrTimerRecords,
                    gCurrentRecords,
                    0,
                    guiBuffer,
                    IMG_TYPICALSW_BACKGROUND,
                    STOP_START_AGAIN);
            }
        }

        SetLeftSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitWtchScrSplitLapTimingStopwatch
 * DESCRIPTION
 *  Exit fn for Split/Lap timing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWtchScrSplitLapTimingStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* leave_full_screen(); // 111104 Calvin removed */

    if (gStopwatchAppInfo.TimerState == TIMER_RUNNING || gStopwatchAppInfo.MPTimerState == TIMER_RUNNING)
    {
        ShowStatusIcon(STATUS_ICON_STOP_WATCH);
    }
    else
    {
        HideStatusIcon(STATUS_ICON_STOP_WATCH);
    }
    UpdateStatusIcons();
}


/*****************************************************************************
 * FUNCTION
 *  StartSplitLapTimer
 * DESCRIPTION
 *  Start Split/lap Timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_stop_watch_timer(TIMER_START);
    ChangeLeftSoftkey(STR_STOPWATCH_STOP, 0);
    if (gStopwatchAppInfo.splitLapTimer)
    {
        ChangeRightSoftkey(STR_STOPWATCH_SPLIT, 0);
    }
    else
    {
        ChangeRightSoftkey(STR_STOPWATCH_LAP, 0);
    }

    SetLeftSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NULL, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
    gStopwatchAppInfo.TimerState = TIMER_RUNNING;

    /* TurnOnBacklight(0); */

}


/*****************************************************************************
 * FUNCTION
 *  StopSplitLapTimer
 * DESCRIPTION
 *  Stop split/Lap timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_stop_watch_timer(TIMER_STOP);
    ChangeLeftSoftkey(STR_STOPWATCH_RESUME, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ResumeSplitLapTimer, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ResetSplitLapTimer, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(ConfirmSaveTimerRecord, KEY_EVENT_UP);

    /* TurnOnBacklight(1); */

    gStopwatchAppInfo.TimerState = TIMER_STOPPED;

}


/*****************************************************************************
 * FUNCTION
 *  ResumeSplitLapTimer
 * DESCRIPTION
 *  Resume current split/Lap timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResumeSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_stop_watch_timer(TIMER_START);
    ChangeLeftSoftkey(STR_STOPWATCH_STOP, 0);
    if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS)
    {
        ChangeRightSoftkey(0, 0);
    }
    else
    {
        if (gStopwatchAppInfo.splitLapTimer)
        {
            ChangeRightSoftkey(STR_STOPWATCH_SPLIT, 0);
        }
        else
        {
            ChangeRightSoftkey(STR_STOPWATCH_LAP, 0);
        }
        SetRightSoftkeyFunction(RecordSplitLapTime, KEY_EVENT_UP);
    }

    SetLeftSoftkeyFunction(StopSplitLapTimer, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NULL, KEY_LONG_PRESS);

    /* TurnOnBacklight(0); */

    gStopwatchAppInfo.TimerState = TIMER_RUNNING;
}


/*****************************************************************************
 * FUNCTION
 *  ResetSplitLapTimer
 * DESCRIPTION
 *  Reset the Split/Lap Timer when Resume is long
 *  pressed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSplitLapTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_timer();

    ResetTypicalStopwatch();

    ChangeLeftSoftkey(STR_STOPWATCH_START, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(SetLSKforSplitLapTimerResumeLongPress, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(NULL, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  SetLSKforSplitLapTimerResumeLongPress
 * DESCRIPTION
 *  Set LSK handler fn when Resume is long
 *  pressed to reset the Split timer..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetLSKforSplitLapTimerResumeLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(StartSplitLapTimer, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  RecordSplitLapTime
 * DESCRIPTION
 *  This function splits/Laps the Time..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RecordSplitLapTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mili, hr, min, sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UpdateHistoryValue(&mili, &hr, &min, &sec);

    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].hour = hr;
    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].min = min;
    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].sec = sec;
    gCurrentRecords[gStopwatchAppInfo.numofCurrTimerRecords].mili_sec = mili;

    gStopwatchAppInfo.numofCurrTimerRecords++;
    if (gStopwatchAppInfo.numofCurrTimerRecords >= MAX_TIMER_RECORDS)
    {
        ChangeRightSoftkey(0, 0);
    }

    gStopwatchAppInfo.isRecordPresent = TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  ConfirmSaveTimerRecord
 * DESCRIPTION
 *  Confirmation screen for saving the timer record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConfirmSaveTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gStopwatchAppInfo.isRecordPresent == TRUE)
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        /* 9.Register function with right softkey */
        SetRightSoftkeyFunction(GoBackToStopwatchMenu, KEY_EVENT_UP);

        if (gStopwatchAppInfo.numOfSavedTimerRecords < MAX_STOPWATCH_RECORDS)
        {
            SetLeftSoftkeyFunction(EntryWtchScrEnterRecordName, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(EntryWtchScrMemoryFull, KEY_EVENT_UP);
        }

    }
    else
    {
        ResetTypicalStopwatch();
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackToStopwatchMenu
 * DESCRIPTION
 *  This fn takes user to StopwatchMenu screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackToStopwatchMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_TYPICAL_STOPWATCH);
    ResetTypicalStopwatch();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrEnterRecordName
 * DESCRIPTION
 *  This function gets the record name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrEnterRecordName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ENTER_RECORD_NAME, ExitWtchScrRecordName, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ENTER_RECORD_NAME);

    ShowCategory5Screen(
        STR_STOPWATCH_SAVE_STOPWATCH,
        GetRootTitleIcon(MENU_TYPICALSTOPWATCH),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (PU8) gStopwatchAppInfo.recordName,
        (MAX_RECORD_NAME_LENGTH + 1),
        guiBuffer);

    SetLeftSoftkeyFunction(EntryWtchRecordSaveOption, KEY_EVENT_UP);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ExitWtchScrRecordName
 * DESCRIPTION
 *  Exit function for Record Name Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWtchScrRecordName(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr.scrnID = SCR_ENTER_RECORD_NAME;
    scr.entryFuncPtr = EntryWtchScrEnterRecordName;
    mmi_ucs2cpy((S8*) scr.inputBuffer, (S8*) gStopwatchAppInfo.recordName);
    GetCategoryHistory(scr.guiBuffer);
    AddHistory(scr);

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchRecordSaveOption
 * DESCRIPTION
 *  This function Displays the options for record save.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchRecordSaveOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 itemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_SAVE_OPTIONS, NULL, EntryWtchRecordSaveOption, NULL);

    SetParentHandler(MENU_RECORD_SAVE_OPTIONS);

    guiBuffer = GetCurrGuiBuffer(SCR_SAVE_OPTIONS);

    nItems = GetNumOfChild(MENU_RECORD_SAVE_OPTIONS);
    GetSequenceStringIds(MENU_RECORD_SAVE_OPTIONS, itemList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_TYPICALSTOPWATCH),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        itemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistoryFnFromInputMethod
 * DESCRIPTION
 *  Fn to be register for go back history from Input method screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistoryFnFromInputMethod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  SaveTimerRecord
 * DESCRIPTION
 *  Saves Timer Record in NVRAM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gStopwatchAppInfo.recordName) != 0)
    {

        memset(&gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords], 0, sizeof(stopwatchRecord));
        memcpy(
            &gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].name,
            gStopwatchAppInfo.recordName,
            MAX_RECORD_NAME_LENGTH * ENCODING_LENGTH);
        gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].numOfRecords =
            (U8) gStopwatchAppInfo.numofCurrTimerRecords;
        for (index = 0; index < gStopwatchAppInfo.numofCurrTimerRecords; index++)
        {
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recHr =
                (U8) gCurrentRecords[index].hour;
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recMin =
                (U8) gCurrentRecords[index].min;
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recSec =
                (U8) gCurrentRecords[index].sec;
            gTimerRecordList[gStopwatchAppInfo.numOfSavedTimerRecords].nRecordData[index].recMsec =
                (U8) gCurrentRecords[index].mili_sec;
        }

        gStopwatchAppInfo.numOfSavedTimerRecords++;

        WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
        WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, SUCCESS_TONE);
        ResetTypicalStopwatch();
        DeleteUptoScrID(SCR_TYPICAL_STOPWATCH);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_EMPTY_NAME), IMG_GLOBAL_EMPTY, 1, POPUP_TIME, ERROR_TONE);
        DeleteUptoScrID(SCR_ENTER_RECORD_NAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  FailedSaveTimerRecord
 * DESCRIPTION
 *  Failed in saving timer record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FailedSaveTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_STOPWATCH_NOT_SAVED), IMG_GLOBAL_WARNING, 1, POPUP_TIME, WARNING_TONE);
    DeleteUptoScrID(SCR_TYPICAL_STOPWATCH);
    ResetTypicalStopwatch();
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrViewRecord
 * DESCRIPTION
 *  Entry fn for view record list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrViewRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gStopwatchAppInfo.numOfSavedTimerRecords > 0)
    {
        for (count = 0; count < gStopwatchAppInfo.numOfSavedTimerRecords; count++)
        {
            mmi_ucs2cpy((S8*) subMenuDataPtrs[count], (S8*) gTimerRecordList[count].name);
        }
    }

    if (gStopwatchAppInfo.numOfSavedTimerRecords == 0)
    {
        /* Robin 0726, use global string defination */
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY /* STR_STOPWATCH_LIST_EMPTY */ ),
            IMG_GLOBAL_EMPTY,
            1,
            POPUP_TIME,
            EMPTY_LIST_TONE);
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_VIEW_RECORD);

        EntryNewScreen(SCR_VIEW_RECORD, NULL, EntryWtchScrViewRecord, NULL);

        SetParentHandler(MENU_VIEW_RECORD);

        RegisterHighlightHandler(GetSelectedItemIndex);
        /* Register function for left soft key */
        ShowCategory84Screen(
            STR_VIEW_RECORD,
            GetRootTitleIcon(MENU_TYPICALSTOPWATCH),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            gStopwatchAppInfo.numOfSavedTimerRecords,
            (U8 **) subMenuDataPtrs,
            (PU16) gIndexIconsImageList,
            0,
            gStopwatchAppInfo.currHilitedRecord,
            guiBuffer);
        SetLeftSoftkeyFunction(EntryWtchScrViewRecordOptions, KEY_EVENT_UP);

        /* Register function for right soft key */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    }

}


/*****************************************************************************
 * FUNCTION
 *  GetSelectedItemIndex
 * DESCRIPTION
 *  Function to store current hilited record in global variable.
 * PARAMETERS
 *  hilitedIndex        [IN]        
 *  Current(?)          [IN]        Hilite Index
 * RETURNS
 *  void
 *****************************************************************************/
void GetSelectedItemIndex(S32 hilitedIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.currHilitedRecord = hilitedIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrViewRecordOptions
 * DESCRIPTION
 *  Entry fn for view record options list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrViewRecordOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_VIEW_RECORD_OPTIONS, NULL, EntryWtchScrViewRecordOptions, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_VIEW_RECORD_OPTIONS);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_VIEW_RECORD_OPTIONS);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_VIEW_RECORD_OPTIONS);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_VIEW_RECORD_OPTIONS, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_VIEW_RECORD_OPTIONS);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_TYPICALSTOPWATCH),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 10. Register Exit handler */
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrViewSavedRecord
 * DESCRIPTION
 *  Entry fn To view saved record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrViewSavedRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 currRecordNum = 0;
    U8 *listItemsIcons[MAX_SUB_MENUS];
    nRecordDetail *localRecord;
    U8 localRecordString[(MAX_TIMER_RECORD_DIGITS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_VIEW_SAVED_RECORD, NULL, EntryWtchScrViewSavedRecord, NULL);

    for (currRecordNum = 0; currRecordNum < gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].numOfRecords;
         currRecordNum++)
    {
        memset(localRecordString, 0, (MAX_TIMER_RECORD_DIGITS + 1) * ENCODING_LENGTH);
        localRecord = &gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[currRecordNum];
        change_stopwatchtime_to_string(
            (S32) localRecord->recMsec,
            (S32) localRecord->recHr,
            (S32) localRecord->recMin,
            (S32) localRecord->recSec,
            &localRecordString[0],
            DISPLAY_MILISEC_TRUE);
        mmi_ucs2cpy((S8*) subMenuDataPtrs[currRecordNum], (S8*) localRecordString);
        listItemsIcons[currRecordNum] = (U8*) GetImage(gIndexIconsImageList[currRecordNum]);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_VIEW_SAVED_RECORD);

    SetParentHandler(MENU_OPTION_VR_VIEW);

    /* Register function for left soft key */
    ShowCategory32Screen(
        (U8*) gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].name,
        NULL,
        NULL,
        NULL,
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        currRecordNum,
        (U8 **) subMenuDataPtrs,
        listItemsIcons,
        0,
        0,
        guiBuffer);

    /* Register function for right soft key */
    DeleteUptoScrID(SCR_VIEW_RECORD);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrDeleteRecord
 * DESCRIPTION
 *  Entry fn To Delete record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrDeleteRecord(void)
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
        get_string(STR_GLOBAL_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    /* 9.Register function with right softkey */
    DeleteUptoScrID(SCR_VIEW_RECORD);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(DeleteSelectedRecord, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  DeleteSelectedRecord
 * DESCRIPTION
 *  This function deletes curently selected record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteSelectedRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&gTimerRecordList[gStopwatchAppInfo.currHilitedRecord], 0, sizeof(stopwatchRecord));

    for (count = (U8) gStopwatchAppInfo.currHilitedRecord; count + 1 < gStopwatchAppInfo.numOfSavedTimerRecords;
         count++)
    {
        memcpy(&gTimerRecordList[count], &gTimerRecordList[count + 1], sizeof(stopwatchRecord));
    }
    memset(&gTimerRecordList[--gStopwatchAppInfo.numOfSavedTimerRecords], 0, sizeof(stopwatchRecord));

    WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);

    WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, SUCCESS_TONE);
    if (gStopwatchAppInfo.numOfSavedTimerRecords == 0)
    {
        DeleteUptoScrID(SCR_TYPICAL_STOPWATCH);
    }
    else
    {
        DeleteUptoScrID(SCR_VIEW_RECORD);
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrDeleteAllRecord
 * DESCRIPTION
 *  Entry fn To confirm Delete all record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrDeleteAllRecord(void)
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
        get_string(STR_GLOBAL_DELETE_ALL) /* STR_CONFIRM_DELETE_ALL_RECORD */ ,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* 9.Register function with right softkey */
    DeleteUptoScrID(SCR_VIEW_RECORD);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(DeleteAllTimerRecord, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  DeleteAllTimerRecord
 * DESCRIPTION
 *  This function deletes all Saved Timer Records.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteAllTimerRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(gTimerRecordList, 0, sizeof(stopwatchRecord) * MAX_STOPWATCH_RECORDS);
    gStopwatchAppInfo.numOfSavedTimerRecords = 0;

    WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
    WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_TYPICAL_STOPWATCH);

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrMemoryFull
 * DESCRIPTION
 *  Displays the screen for memory full
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrMemoryFull(void)
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
        get_string(STR_STOPWATCH_MEMORY_FULL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(FailedSaveTimerRecord, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryWtchScrReplaceRecord, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrReplaceRecord
 * DESCRIPTION
 *  Entry fn To replace previous record when memory is full
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrReplaceRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_REPLACE_RECORD, NULL, EntryWtchScrReplaceRecord, NULL);

    for (count = 0; count < gStopwatchAppInfo.numOfSavedTimerRecords; count++)
    {
        mmi_ucs2cpy((S8*) subMenuDataPtrs[count], (S8*) gTimerRecordList[count].name);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_REPLACE_RECORD);

    gStopwatchAppInfo.replaceRecord = TRUE;

    RegisterHighlightHandler(GetSelectedItemIndex);

    /* Register function for left soft key */
    ShowCategory84Screen(
        STR_STOPWATCH_REPLACE_RECORD,
        GetRootTitleIcon(MENU_TYPICALSTOPWATCH),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_CANCEL,
        0,
        gStopwatchAppInfo.numOfSavedTimerRecords,
        (U8 **) subMenuDataPtrs,
        (PU16) gIndexIconsImageList,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryWtchScrEnterRecordName, KEY_EVENT_UP);
    SetRightSoftkeyFunction(FailedSaveTimerRecord, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ReplaceSelectedRecord
 * DESCRIPTION
 *  Replace Existing Record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReplaceSelectedRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) gStopwatchAppInfo.recordName) != 0)
    {
        gStopwatchAppInfo.replaceRecord = FALSE;

        memset(&gTimerRecordList[gStopwatchAppInfo.currHilitedRecord], 0, sizeof(stopwatchRecord));
        memcpy(
            &gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].name,
            gStopwatchAppInfo.recordName,
            MAX_RECORD_NAME_LENGTH * ENCODING_LENGTH);
        gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].numOfRecords =
            (U8) gStopwatchAppInfo.numofCurrTimerRecords;

        for (count = 0; count < gStopwatchAppInfo.numofCurrTimerRecords; count++)
        {
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recHr =
                (U8) gCurrentRecords[count].hour;
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recMin =
                (U8) gCurrentRecords[count].min;
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recSec =
                (U8) gCurrentRecords[count].sec;
            gTimerRecordList[gStopwatchAppInfo.currHilitedRecord].nRecordData[count].recMsec =
                (U8) gCurrentRecords[count].mili_sec;
        }

        WriteValue(NVRAM_STOPWATCH_TOTAL_RECORDS, &gStopwatchAppInfo.numOfSavedTimerRecords, DS_BYTE, &error);
        WriteRecord(NVRAM_EF_STOPWATCH_LID, 1, &gTimerRecordList[0], NVRAM_EF_STOPWATCH_RECORD_SIZE, &error);


        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_TYPICAL_STOPWATCH);
        ResetTypicalStopwatch();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_EMPTY_NAME), IMG_GLOBAL_EMPTY, 1, POPUP_TIME, ERROR_TONE);
        DeleteUptoScrID(SCR_ENTER_RECORD_NAME);
    }
}

/********************For Stopwatch running in background***************************/


/*****************************************************************************
 * FUNCTION
 *  DisplayDiscontinueTimerQuery
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayDiscontinueTimerQuery(void)
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
        get_string(STR_DISCONTINUE_TIMER_QUERY),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(DiscontinuePreviousStopwatch, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  DiscontinuePreviousStopwatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DiscontinuePreviousStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetTypicalStopwatch();

    if (gStopwatchAppInfo.splitLapTimer == LAP_TIMER)
    {
        gStopwatchAppInfo.splitLapTimer = SPLIT_TIMER;
    }
    else
    {
        gStopwatchAppInfo.splitLapTimer = LAP_TIMER;
    }

    EntryWtchScrSplitLapTimingStopwatch();
}


/*****************************************************************************
 * FUNCTION
 *  ResetTypicalStopwatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetTypicalStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.replaceRecord = FALSE;
    gStopwatchAppInfo.isRecordPresent = FALSE;
    gStopwatchAppInfo.numofCurrTimerRecords = 0;
    gStopwatchAppInfo.TimerState = TIMER_NOT_STARTED;
    memset(gCurrentRecords, 0, sizeof(UI_stop_watch) * MAX_TIMER_RECORDS);
    initialize_stop_watch_timer();
}

#endif /* __MMI_STOPWATCH__ */ 

