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
 * MultiPurposeStopwatch.c
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

   FILENAME : MultiPurposeStopwatch.c

   PURPOSE     : Multi Purpose Stopwatch application implementation

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

/***************************************************************************** 
* Define
*****************************************************************************/

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
UI_stop_watch gLastMPTimeRecord;
UI_stop_watch gMultiPurposeTimerList[MAX_MULTIPURPOSE_TIMER];
nWayTimerStruct gMPTimerInit;

/**********************************************************************
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  InitMultipurposeStopwatch
 * DESCRIPTION
 *  Init fn for Multipurpose stop watch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitMultipurposeStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&gLastMPTimeRecord, 0, sizeof(UI_stop_watch));
    memset(gMultiPurposeTimerList, 0, sizeof(UI_stop_watch) * MAX_MULTIPURPOSE_TIMER);
    for (index = 0; index < MAX_MULTIPURPOSE_TIMER; index++)
    {
        gMultiPurposeTimerList[index].normalimagedata = GetImage((U16) (IMG_MULTIPURPOSE_TIMER1 + index));
        gMultiPurposeTimerList[index].highlightimagedata = GetImage((U16) (IMG_MULTIPURPOSE_TIMER1 + index));
    }

    gMPTimerInit.assignedKey[0] = KEY_LEFT_ARROW;
    gMPTimerInit.timerIndex[0] = 0;

    gMPTimerInit.assignedKey[1] = KEY_UP_ARROW;
    gMPTimerInit.timerIndex[1] = 1;

    gMPTimerInit.assignedKey[2] = KEY_RIGHT_ARROW;
    gMPTimerInit.timerIndex[2] = 2;

    gMPTimerInit.assignedKey[3] = KEY_DOWN_ARROW;
    gMPTimerInit.timerIndex[3] = 3;

}


/*****************************************************************************
 * FUNCTION
 *  EntryWtchScrMultipurposeStopwatch
 * DESCRIPTION
 *  Entry fn for Multipurpose stop watch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWtchScrMultipurposeStopwatch(void)
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
    EntryNewScreen(
        SCR_MULTIPURPOSE_STOPWATCH,
        ExitWtchScrMultiPurposeStopwatch,
        EntryWtchScrMultipurposeStopwatch,
        NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_MULTIPURPOSE_STOPWATCH);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_MULTIPURPOSEWATCH);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_MULTIPURPOSEWATCH);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_MULTIPURPOSEWATCH, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_MULTIPURPOSEWATCH);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Display Category Screen */
    if (gStopwatchAppInfo.MPTimerState == TIMER_NOT_STARTED)
    {
        ShowCategory306Screen(
            &gLastMPTimeRecord,
            0,
            STR_MUTIPURPOSE_TITLE_SIDE_MSG,
            STR_STOPWATCH_START,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MAX_MULTIPURPOSE_TIMER,
            gMultiPurposeTimerList,
            0,
            STR_MUTIPURPOSE_TITLE_MSG,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);

        SetLeftSoftkeyFunction(ResetAllTimer, KEY_LONG_PRESS);
        SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    }
    else if (gStopwatchAppInfo.MPTimerState == TIMER_STOPPED)
    {
        ShowCategory306Screen(
            &gLastMPTimeRecord,
            0,
            STR_MUTIPURPOSE_TITLE_SIDE_MSG,
            STR_STOPWATCH_RESUME,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MAX_MULTIPURPOSE_TIMER,
            gMultiPurposeTimerList,
            0,
            STR_MUTIPURPOSE_TITLE_MSG,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
        SetLeftSoftkeyFunction(ResetAllTimer, KEY_LONG_PRESS);
        SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory306Screen(
            &gLastMPTimeRecord,
            0,
            STR_MUTIPURPOSE_TITLE_SIDE_MSG,
            STR_STOPWATCH_STOP,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            MAX_MULTIPURPOSE_TIMER,
            gMultiPurposeTimerList,
            0,
            STR_MUTIPURPOSE_TITLE_MSG,
            guiBuffer,
            gStopwatchAppInfo.currentHiliteTimer);
        SetLeftSoftkeyFunction(StopCurrentTimer, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(0, KEY_LONG_PRESS);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* Robin 0728 */
    /* If using EVENT_UP as action key event, when pressing left key entering the nWay Stopwatch at the previous menu */
    /* The key up event will trigger the related stopwatch start */
    SetGroupKeyHandler(StartKeyTimer, gMPTimerInit.assignedKey, MAX_MULTIPURPOSE_TIMER, KEY_EVENT_DOWN);

    /* SetExitHandler(SCR_MULTIPURPOSE_STOPWATCH,ExitWtchScrMultiPurposeStopwatch); */

}


/*****************************************************************************
 * FUNCTION
 *  ExitWtchScrMultiPurposeStopwatch
 * DESCRIPTION
 *  Exit fn for Multipurpose Stopwatch screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWtchScrMultiPurposeStopwatch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetMultipurposeTimeValues( /* &gLastMPTimeRecord,gMultiPurposeTimerList, */ &gStopwatchAppInfo.currentHiliteTimer);

    if (gStopwatchAppInfo.MPTimerState == TIMER_RUNNING || gStopwatchAppInfo.TimerState == TIMER_RUNNING)
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
 *  StartKeyTimer
 * DESCRIPTION
 *  Start timer associated with any Key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartKeyTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U16 keycode, keytype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);

    for (count = 0; count < MAX_MULTIPURPOSE_TIMER; count++)
    {
        if (keycode == gMPTimerInit.assignedKey[count])
        {
            gStopwatchAppInfo.currentTimerIndex = gMPTimerInit.timerIndex[count];
            StartIndexTimer();
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  StopCurrentTimer
 * DESCRIPTION
 *  Stop Currently active timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopCurrentTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_STOPWATCH_RESUME, 0);
    SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ResetAllTimer, KEY_LONG_PRESS);
    stop_multipurpose_timers();

    /* TurnOnBacklight(1); */

    gStopwatchAppInfo.MPTimerState = TIMER_STOPPED;

}


/*****************************************************************************
 * FUNCTION
 *  ResetAllTimer
 * DESCRIPTION
 *  Reset All Timer when Resume is long
 *  pressed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetAllTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_STOPWATCH_START, 0);
    SetLeftSoftkeyFunction(SetLSKMultiPurposeTimerResumeLongPress, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(0, KEY_LONG_PRESS);
    reset_all_multipurpose_time();
    gStopwatchAppInfo.currentTimerIndex = 0;
    gStopwatchAppInfo.currentHiliteTimer = 0;
    gStopwatchAppInfo.MPTimerState = TIMER_NOT_STARTED;

}


/*****************************************************************************
 * FUNCTION
 *  SetLSKMultiPurposeTimerResumeLongPress
 * DESCRIPTION
 *  Set LSK handler fn when Resume is long
 *  pressed to reset the Multipurpose timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetLSKMultiPurposeTimerResumeLongPress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.currentTimerIndex = 0;
    SetLeftSoftkeyFunction(StartIndexTimer, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  StartIndexTimer
 * DESCRIPTION
 *  Call back fn to start Timer set in gCurrentTimerIndex.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StartIndexTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gStopwatchAppInfo.MPTimerState = TIMER_RUNNING;
    ChangeLeftSoftkey(STR_STOPWATCH_STOP, 0);
    SetLeftSoftkeyFunction(StopCurrentTimer, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(0, KEY_LONG_PRESS);
    start_multipurpose_list_watch(gStopwatchAppInfo.currentTimerIndex);

    /* TurnOnBacklight(0); */

}
#endif /* __MMI_STOPWATCH__ */ 

