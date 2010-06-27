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
* Shortcuts.c
*
* Project:
* --------
* MAUI
*
* Description:
* ------------
* This file implements Shortcuts application.
*
* Author:
* -------
* Max Chen
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
* Dec 21 2007 mbj06019
* [MAUI_00505696] Adjust Gemini branch - raplace string api and trace api, add backward compatible fil
* created by clearfsimport
*
* Dec 12 2007 mbj06066
* [MAUI_00503623] shortcuts for Gemini
* 
*
* Oct 20 2007 mbj06019
* [MAUI_00482896] Check in mmi_include.h and adjustment header files for application source code
* created by clearfsimport
*
* Oct 9 2007 MBJ06066
* [MAUI_00478796] [Dedicated key] the title error
* 
*
* Sep 11 2007 MBJ06066
* [MAUI_00468274] [Idle]Same prompt but not same icon.
* 
*
* Aug 9 2007 MBJ06066
* [MAUI_00456911] Shortcuts avoid ASSERT
* void ASSERT
*
* Jul 15 2007 mtk01215
* [MAUI_00235482] Shortcut_THe 31 entries haven't icon
* Replace category15 with category89 to draw counter icons larger than 30.
*
* Apr 14 2007 mtk01215
* [MAUI_00382204] [PC Simulator] Remove MMI_ON_WIN32 and MMI_ON_HARDWARE_P
* 
*
* Feb 22 2007 mtk01136
* [MAUI_00367163] Flight Mode_The dedicated key for shortcuts chould be work
* Allow shortcut in flight mode
*
* Feb 8 2007 mtk01215
* [MAUI_00365393] [MMI][Shortcuts]Add condition to check if shortcut item could be used on preferred m
* 
*
* Feb 7 2007 mtk01215
* [MAUI_00421364] [Shortcuts] title display error
* Modify title string of shortcut option screen.
*
* Jan 29 2007 mtk01215
* [MAUI_00228241] [Preferred Mode]Shortcuts_It has Call Divert, Owner Number & Preferred Storage witho
* 
*
* Nov 3 2006 mtk01542
* [MAUI_00340428] Remove __NEWSIMULATOR #define and #undef in MainTrunk
* 
*
* Aug 17 2006 mtk01215
* [MAUI_00322514] [Need Patch] Shortcuts sanity test fail
* Extern nCustMenus as a point.
*
* Jul 17 2006 mtk01215
* [MAUI_00208658] Shortcuts-Highlight "Delete (or Delete All or Disable)" and press "¡÷", it should not
* Remove right arrow key handler of delete, delete all, enable, disable on option screen.
*
* Jun 25 2006 mtk00609
* [MAUI_00222897] Call History_highlight issue
* 
*
* Jun 21 2006 mtk01215
* [MAUI_00222629] TDL_save a TDl,screen is mess yard
* Delete popup msg -- press up key in idle to use, because it's too long.
*
* Jun 19 2006 mtk01215
* [MAUI_00203596] [MMI]Modify the icon to check box -- alarm, shortcuts, SPOF
* 
*
* May 2 2006 mtk00563
* [MAUI_00184484] [MMI] New API: ClearInputEventHandler
* 
*
* Apr 24 2006 mtk01215
* [MAUI_00189654] [MMI][Shortcuts]Revise compile option
* 
*
* Apr 22 2006 mtk01215
* [MAUI_00189422] [MMI][Shortcuts]Remove redundant ClearAllKeyHandler
* 
*
* Apr 20 2006 mtk01215
* [MAUI_00189072] [1] Assert fail: !RB_FULL( l1d.queuedFunctions2 ) m12100.c 5178 - MMI
* Set LSK to Add when shortcuts list is empty.
*
* Apr 4 2006 mtk01215
* [MAUI_00184869] [MMI]Clean compile warning
* Remove nEmptyId.
*
* Apr 3 2006 mtk01215
* [MAUI_00184171] shortcuts - item name error
* Add array size of shortcuts list in touch screen project.
*
* Mar 27 2006 mtk01215
* [MAUI_00219341] Change Feature- Shortcuts_when delete all shortcuts,Pen Calibration still exised
* Check the menu status when entry shortcuts setting screen from main menu.
*
* Mar 26 2006 mtk01215
* [MAUI_00219341] Change Feature- Shortcuts_when delete all shortcuts,Pen Calibration still exised
* Add Pan Calibration as default item in touch screen project.
*
* Mar 20 2006 mtk01215
* [MAUI_00180622] Please turn-off "Shortcut" function in Malata26_05C 06.12
* 
*
* Feb 6 2006 mtk01215
* [MAUI_00171288] [MMI][Extra]update shortcuts list and clean compile option
* Add MMI_TRACE when shortcuts is not found.
*
* Jan 13 2006 mtk01215
* [MAUI_00166183] Shortcut_Add BlueTooth item in the list
* Chagne macro name: SHCT_MAX_SEL_LIST -> SHCT_MAX_LIST, because SHCT_MAX_SEL_LIST  is used in resource_shortcuts.c.
*
* Jan 10 2006 mtk01215
* [MAUI_00218550] Shortcut_it jump abnormal
* If there is no enabled shortcuts item, disable LSK.
* For touch panel, pen calibration will always be last item.
*
* Jan 6 2006 mtk01215
* [MAUI_00166312] Shortcut-The display is abnormal while change order the item.
* Modify the way of memory copy when changing order
*
* Jan 2 2006 mtk01215
* [MAUI_00165326] [MMI][Extra]clean compile warning
* 
*
* Dec 30 2005 mtk01215
* [MAUI_00218317] Fatal Error (b03): Abnormal Reset - MMI
* 
*
* Dec 30 2005 mtk01215
* [MAUI_00161193] [MMI][Shortcuts]Add compile option -- __MMI_FOURWAYS_KEY_DISABLE__
* 
*
* Dec 23 2005 mtk01215
* [MAUI_00163221] [MMI][Shortcuts]Patch to 05.52
* Remove __MMI_FOURWAYS_KEY_DISABLE__
*
* Dec 19 2005 mtk01215
* [MAUI_00161193] [MMI][Shortcuts]Add compile option -- __MMI_FOURWAYS_KEY_DISABLE__
* 
*
* Dec 12 2005 mtk01215
* [MAUI_00161193] [MMI][Shortcuts]Add compile option -- __MMI_FOURWAYS_KEY_DISABLE__
* 
*
* Dec 5 2005 mtk01215
* [MAUI_00159735] [MMI][Extra]Revise clear handler of calculator
* Fix compile warning
*
* Nov 12 2005 mtk01215
* [MAUI_00155675] [MMI][Extra]Revise Extra Code
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

  FILENAME : Shortcuts.c
  
    PURPOSE     : Shortcuts Application
    
      REMARKS     : nil
      
        AUTHOR      : NEERAJ SHARMA
        
          DATE     : May 12,03
          
**************************************************************/
#include "MMI_include.h"
#ifdef SHORTCUTS_APP

#ifndef _MMI_SHORTCUTS_C
#define _MMI_SHORTCUTS_C

#ifndef __DISABLE_SHORTCUTS_IMPL__
/*  Include: MMI header file */

#include "ShortcutsDefs.h"
#include "CommonScreens.h"
#include "ShortcutsProts.h"
#include "MainMenuDef.h"
#include "wgui_softkeys.h"
#include "WrapperGprot.h"
#include "IdleAppDef.h"
#include "ProfileGprots.h"
#include "AudioInc.h"
#include "MessagesResourceData.h"
#include "SettingDefs.h"
#include "CallHistoryMain.h"    /* CHISTResetCallLogIndex */
#include "SimDetectionDef.h"
#include "SimDetectionGProt.h"
#include "NetworkSetupDefs.h"

#if defined(__MMI_DUAL_SIM_MASTER__)
#include "MTPNP_AD_master_header.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */
/*
* Define
*/

/* 
* Typedef 
*/
/* 
* Global Variable
*/
shct_context_struct g_shct_cntx;

/* 
* Global Function
*/
extern MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id);

/*
* Local Variable
*/

/* 
* Local Function
*/
void ShctSelOption(void);
void EntryShctOptionScreen(void);
void HighlightShctOption(S32 index);
void ShctDeleteItem(void);
void ShctShowPopupScreen(U16 Msg);
void ShctChangeState(U8 state);
void HighlightShctOptionAdd(void);
void HighlightShctOptionEdit(void);
void HighlightShctOptionDelete(void);
void HighlightShctOptionDeleteAll(void);
void HighlightShctOptionEnable(void);
void HighlightShctOptionDisable(void);
void HighlightShctOptionChangeOrder(void);
void ShctSetOrder(void);
void EntryShctInvalidSIM(void);
S32 ShctCheckItemCanbeExecuted(U16 selitem);
void EntryShctInvalidIdleScreen(void);
#ifdef __FLIGHT_MODE_SUPPORT__
void EntryShctInvalidFlightMode(void);
#endif /* __FLIGHT_MODE_SUPPORT__ */

#if defined (__MMI_DUAL_SIM_MASTER__)
void EntryShctInvalidSIM1(void);
void EntryShctInvalidSIM2(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern CUSTOM_MENU *nCustMenus;
extern hiliteInfo maxHiliteInfo[MAX_HILITE_HANDLER];    /* available hilite func ptrs */

/* retrieve shortcut from custom folder */
extern const shct_item_struct gShctCandList[];
extern const shct_item_struct gShctDefaultList[];
//extern const U16 gShctDefaultList[];
//extern const U8 gShctDefaultState[];

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
extern U16 gShctDefaultDediList[];
#endif 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
* FUNCTION
*  ShctInit
* DESCRIPTION
*  Initialises variables & Protocol Handlers for Shortcuts
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShctGetCandidateList();
    
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_ADD_MENUID, HighlightShctOptionAdd);
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_EDIT_MENUID, HighlightShctOptionEdit);
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_DELETE_MENUID, HighlightShctOptionDelete);
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID, HighlightShctOptionDeleteAll);
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID, HighlightShctOptionEnable);
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID, HighlightShctOptionDisable);
    SetHiliteHandler(EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID, HighlightShctOptionChangeOrder);
    ShctReadFromNvram();
    
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
    g_shct_cntx.IsKeyRetrieving = FALSE;
    ShctReadDedicatedListFromNVRAM();
#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ 
}


/*****************************************************************************
* FUNCTION
*  ShctWriteToNvram
* DESCRIPTION
*  Write shortcut data to NVRAM.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctWriteToNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvramData[SHCT_NVRAM_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvramData, 0xff, sizeof(nvramData));
    nvramData[SHCT_COUNT_BYTE] = g_shct_cntx.NumSelShct;
    nvramData[SHCT_INTEGRITY_BYTE] = 1;
    
    memcpy(
        (void*)&nvramData[SHCT_DATA_BYTE],
        (void*)&g_shct_cntx.SelShctList,
        sizeof(shct_item_struct) * g_shct_cntx.NumSelShct);
    
    WriteRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
}


/*****************************************************************************
* FUNCTION
*  ShctGetCandidateList
* DESCRIPTION
*  Get candidate list of shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctGetCandidateList()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 count = (S32) shct_max_list_cand;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.NumCandShct = 0;
    
    for (i = 0; i < count; i++)
        if (maxHiliteInfo[gShctCandList[i].shortcuts].entryFuncPtr)
        {
            g_shct_cntx.CandShctList[g_shct_cntx.NumCandShct++] = gShctCandList[i].shortcuts;
        }
}


/*****************************************************************************
* FUNCTION
*  ShctReadFromNvram
* DESCRIPTION
*  Read shortcut data from NVRAM and initialize selected shortcut list.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctReadFromNvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 j, total;
    
    U8 nvramData[SHCT_NVRAM_SIZE];
    shct_item_struct menuID;
    S16 error;
    S8 shortcut_not_found = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
    
    if (nvramData[1] != 1)
    {
        nvramData[SHCT_COUNT_BYTE] = shct_list_default;
        nvramData[SHCT_INTEGRITY_BYTE] = 1;
        memcpy(
            (void*)&nvramData[SHCT_DATA_BYTE],
            (void*)&gShctDefaultList,
            sizeof(shct_item_struct) * shct_list_default);
        WriteRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
    }
    
    total = nvramData[SHCT_COUNT_BYTE];
    g_shct_cntx.Integrity = nvramData[SHCT_INTEGRITY_BYTE];
    
    for (j = 0; j < total; j++)
    {
        memcpy(&menuID, &nvramData[j * sizeof(shct_item_struct) + SHCT_DATA_BYTE], sizeof(shct_item_struct));
        if (maxHiliteInfo[menuID.shortcuts].entryFuncPtr)
        {
            g_shct_cntx.SelShctList[j] = menuID;
            error = menuID.shortcuts;
        }
        else
        {
            shortcut_not_found = TRUE;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_SHORTCUTS_NOT_FOUND, menuID.shortcuts);
            break;
        }
    }
    //MMI_ASSERT(shortcut_not_found == FALSE);
    if (shortcut_not_found == TRUE)
    {
        /* first write default list to NVRAM */
        nvramData[SHCT_COUNT_BYTE] = shct_list_default;
        nvramData[SHCT_INTEGRITY_BYTE] = 1;
        memcpy(
            (void*)&nvramData[SHCT_DATA_BYTE],
            (void*)&gShctDefaultList,
            sizeof(shct_item_struct) * shct_list_default);
        WriteRecord(NVRAM_EF_SHORTCUTS_LID, 1, (void*)nvramData, SHCT_NVRAM_SIZE, &error);        
        
        /* then copy default list to g_shct_cntx.SelShctList[] */
        for (j = 0; j < shct_list_default; j++)
        {
            g_shct_cntx.SelShctList[j] = gShctDefaultList[j];
        }  
    }
    g_shct_cntx.NumSelShct = j;
}


/*****************************************************************************
* FUNCTION
*  ShctMenuShortcut
* DESCRIPTION
*  Shortcut handler of selected menu item
* PARAMETERS
*  index       [IN]        
*  a(?)        [IN]        Index of menu item
* RETURNS
*  void
*****************************************************************************/
void ShctMenuShortcut(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= 0 && index <= g_shct_cntx.NumSelShct)
    {
        execute_left_softkey_function(KEY_EVENT_UP);
    }
}


/*****************************************************************************
* FUNCTION
*  EntryShctInIdle
* DESCRIPTION
*  Display shorcut list in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, index = 0;
    U8 *guiBuffer;
    
    /* U8 num=0; */
    
    // #if 0
#ifdef __MMI_TOUCH_SCREEN__
    U8* ShortcutList[SHCT_MAX_LIST + 1];
#else 
    U8* ShortcutList[SHCT_MAX_LIST];
#endif 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #endif
    
    for (i = 0; i < g_shct_cntx.NumSelShct; i++)
    {
        if (g_shct_cntx.SelShctList[i].shortcut_state == ENABLE_STATE)
        {
            ShortcutList[index++] = (U8*)GetString(ShctGetStringID(g_shct_cntx.SelShctList[i].shortcuts));
        }
    }
#ifdef __MMI_TOUCH_SCREEN__
    
    /* Last Entry is always Calibration */
    if (maxHiliteInfo[MENU_SETTING_CALIBRATION].entryFuncPtr)
    {
        g_shct_cntx.SelShctList[i].shortcuts = MENU_SETTING_CALIBRATION;
        g_shct_cntx.SelShctList[i].shortcut_state = ENABLE_STATE;
        ShortcutList[index++] = (U8*)GetString(ShctGetStringID(MENU_SETTING_CALIBRATION));
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    EntryNewScreen(SCR_ID_SHCT_IDLE_SHORTCUT, NULL, EntryShctInIdle, NULL);
    
    if (g_shct_cntx.CurrSelShct > g_shct_cntx.NumSelShct - 1)
    {
        g_shct_cntx.CurrSelShct = 0;
    }
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_IDLE_SHORTCUT);
    
    RegisterHighlightHandler(HighlightShctSelShortcut);
    
    if (index > 0)
    {
        ShowCategory89Screen(
            MAIN_MENU_SHORTCUTS_TEXT,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            index,
            ShortcutList,
            0,
            0,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(ShctExecSelectedShortcut, KEY_EVENT_UP);
        SetKeyHandler(ShctExecSelectedShortcut, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        register_menu_shortcut_selected(ShctMenuShortcut);
    }
    else
    {
        ShowCategory89Screen(
            MAIN_MENU_SHORTCUTS_TEXT,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            index,
            ShortcutList,
            0,
            0,
            0,
            guiBuffer);
    }
    CHISTResetCallLogIndex();
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}


/*****************************************************************************
* FUNCTION
*  HighlightShctSelShortcut
* DESCRIPTION
*  Highlight handler for IDLE screen shortcut.
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void HighlightShctSelShortcut(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrSelShct = (U8) index;
    /*
    * ChangeLeftSoftkey(STR_GLOBAL_OK,IMG_GLOBAL_OK);
    * SetLeftSoftkeyFunction(ShctExecSelectedShortcut,KEY_EVENT_UP);
    * SetKeyHandler(ShctExecSelectedShortcut,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
    * 
    * ChangeRightSoftkey(STR_GLOBAL_BACK,IMG_GLOBAL_BACK);
    * SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
    * SetKeyHandler(GoBackHistory,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
    */
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionAdd
* DESCRIPTION
*  Highlight handler of add option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionAdd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_ADD;
    SetKeyHandler(ShctSelOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionEdit
* DESCRIPTION
*  Highlight handler of edit option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_EDIT;
    SetKeyHandler(ShctSelOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionDelete
* DESCRIPTION
*  Highlight handler of delete option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionDelete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_DELETE;
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionDeleteAll
* DESCRIPTION
*  Highlight handler of delete all option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionDeleteAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_DELETE_ALL;
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionEnable
* DESCRIPTION
*  Highlight handler of delete all option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionEnable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_ENABLE;
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionDisable
* DESCRIPTION
*  Highlight handler of delete all option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionDisable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_DISABLE;
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctOptionChangeOrder
* DESCRIPTION
*  Highlight handler of change order
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightShctOptionChangeOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrOptionShct = SHR_OPTIONS_CHANGE_ORDER;
    SetKeyHandler(ShctSelOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  ShctExecSelectedShortcut
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecSelectedShortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, count = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCurrentProfileAsActivatedProfile();
    
    while (count < g_shct_cntx.CurrSelShct + 1) /* search for nth enable shortcut item */
    {
        if (g_shct_cntx.SelShctList[i++].shortcut_state == ENABLE_STATE)
        {
            count++;
        }
    }
    
    if (ShctCheckItemCanbeExecuted(g_shct_cntx.SelShctList[i - 1].shortcuts) == 0)
    {
        
        (*maxHiliteInfo[g_shct_cntx.SelShctList[i - 1].shortcuts].entryFuncPtr) ();
        g_shct_cntx.LSKFunc = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        (*g_shct_cntx.LSKFunc) ();
    }
}


/*****************************************************************************
* FUNCTION
*  ShctCheckItemCanbeExecuted
* DESCRIPTION
*  Check if menu item can be executed based on SIM status
* PARAMETERS
*  0: can be executed.
* -1: cannot be executed, popup invalid prompt string
* RETURNS
*  void
*****************************************************************************/
S32 ShctCheckItemCanbeExecuted(U16 selitem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U8 i = 0;   
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    for (i = 0;i < SHCT_MAX_CANDI_LIST; i++)
    {
        if (gShctCandList[i].shortcuts == selitem)
       	{
            break;
        }
    }  

    if (((IsScreenPresent(IDLE_SCREEN_ID)== FALSE) && (GetActiveScreenId() != IDLE_SCREEN_ID))
     && ((gShctCandList[i].shortcut_state & SHCT_INVALID_UNDER_NO_IDLE) > 0))
    {
        EntryShctInvalidIdleScreen();
        return -1;
    }

#ifdef __FLIGHT_MODE_SUPPORT__
    if (mmi_bootup_get_active_flight_mode() != 0)
    {       
        if( ((gShctCandList[i].shortcut_state & SHCT_NEED_SIM) > 0) && 
            ((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_FLIGHT_MODE) == 0))
        {
            EntryShctInvalidFlightMode();
            return -1;
        }
#ifdef __MMI_DUAL_SIM_MASTER__
        if (((gShctCandList[i].shortcut_state & SHCT_NEED_SIM) > 0) && 
            (gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_FLIGHT_MODE))
        {
            if((gShctCandList[i].shortcut_state & SHCT_NEED_SIM1) && (mmi_bootup_is_sim_valid() == MMI_FALSE)) 
            {
                EntryShctInvalidSIM1();
                return -1;
            }            
            if((gShctCandList[i].shortcut_state & SHCT_NEED_SIM2) && (mmi_bootup_is_sim2_valid() == MMI_FALSE)) 
            {
                EntryShctInvalidSIM2();
                return -1;
            }

            if ((mmi_bootup_is_sim_valid() == MMI_FALSE) && (mmi_bootup_is_sim2_valid() == MMI_FALSE))
            {
                EntryShctInvalidSIM();
                return -1;
            }
            return 0;
        }
#endif
        return 0;
    }
#endif /* __FLIGHT_MODE_SUPPORT__ */
    
#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_FALSE)
#else   /* __MMI_DUAL_SIM_MASTER__ */
        if ((MTPNP_AD_Get_UsableSide() < MTPNP_AD_SIMCARD1_USABLE) && 
            (MTPNP_AD_Get_UsableSide() > MTPNP_AD_DUALSIM_UNUSABLE) ) //both SIM are unavailable, but not include flight mode.
#endif /*__MMI_DUAL_SIM_MASTER__ */
        {
#ifdef __MMI_DUAL_SIM_MASTER__
            if (gShctCandList[i].shortcut_state & SHCT_NEED_SIM1)
            {
                if((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) 
                    && (mmi_bootup_is_sim_valid() == MMI_TRUE)) 
                {
                    return 0;
                }
                else
                {
                EntryShctInvalidSIM1();
                return -1;            
            }
            }
            if (gShctCandList[i].shortcut_state & SHCT_NEED_SIM2)
            {
                if((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) 
                    && (mmi_bootup_is_sim2_valid() == MMI_TRUE)) 
                {
                    return 0;
                }
                else
                {
                EntryShctInvalidSIM2();
                return -1;            
            }          
                
            }          
#endif /*__MMI_DUAL_SIM_MASTER__ */
            if ((gShctCandList[i].shortcut_state & SHCT_NEED_SIM) > 0)
            {
#ifdef __MMI_WLAN_FEATURES__
                if (gShctCandList[i].shortcut_state & SHCT_NEED_PREFERRED_MODE_CHECK)
                {
                    if (mmi_netset_get_active_preferred_mode() == 0) // GSM only
                    {
                        EntryShctInvalidSIM();
                        return -1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
#endif /* __MMI_WLAN_FEATURES__ */
                {
#ifdef      __MMI_DUAL_SIM_MASTER__           
                    if ((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) && 
                        (mmi_bootup_is_sim_valid() || mmi_bootup_is_sim2_valid()))
                    {                            
                        return 0;
                    }
#endif /* __MMI_DUAL_SIM_MASTER__ */					
                    EntryShctInvalidSIM();
                    return -1;
                }
            }
            return 0;        
        }
#if defined (__MMI_DUAL_SIM_MASTER__)
        else if(MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE) // tow sim card are both available
        {
            return 0;
        }
        else // only one sim is valid
        {
            if(gShctCandList[i].shortcut_state & SHCT_NEED_SIM1)
            {
                if (((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) == 0) && (MTPNP_AD_Get_UsableSide() != MTPNP_AD_SIMCARD1_USABLE)) 
            {
                EntryShctInvalidSIM1();
                return -1;
            }
                if((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) && (mmi_bootup_is_sim_valid() == MMI_FALSE)) 
                {
                    EntryShctInvalidSIM1();
                    return -1; 
                }
            }
            
            if(gShctCandList[i].shortcut_state & SHCT_NEED_SIM2)
            {
                if (((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) == 0) && (MTPNP_AD_Get_UsableSide() != MTPNP_AD_SIMCARD2_USABLE)) 
            {
                EntryShctInvalidSIM2();
                return -1;
            }
                if((gShctCandList[i].shortcut_state & SHCT_VALID_UNDER_CLOSED_SIM) && (mmi_bootup_is_sim2_valid() == MMI_FALSE)) 
                {
                    EntryShctInvalidSIM2();
                    return -1; 
                }
            }
            return 0;
        }
#endif /* __MMI_DUAL_SIM_MASTER__ */
        return 0;
}

/*****************************************************************************
* FUNCTION
*  EntryShctNoIdleScreen
* DESCRIPTION
*  Display for no idle screen while a shortcut(such as wallpaper, screen saver)
*  is selected to execute
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInvalidIdleScreen(void)
{
    DisplayPopup(
            (U8*) GetString(SHORTCUTS_INVALID_NO_IDLE_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
}
/*****************************************************************************
* FUNCTION
*  EntryShctInvalidSIM
* DESCRIPTION
*  Display for invalid SIM while a shortcut is selected to execute
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInvalidSIM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef  __MMI_DUAL_SIM_MASTER__   
    if (mmi_bootup_is_sim_removed() == MMI_TRUE)
#else
    if ((mmi_bootup_is_sim_removed() == MMI_TRUE) && (MTPNP_PFAL_Is_Card2Absent() == MMI_TRUE))
#endif
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_NO_SIM_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_INVALID_SIM_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
}

/*****************************************************************************
* FUNCTION
*  EntryShctInvalidFlightMode
* DESCRIPTION
*  Display for invalid under flight mode while a shortcut is selected to execute
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __FLIGHT_MODE_SUPPORT__
void EntryShctInvalidFlightMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    DisplayPopup(
        (U8*) GetString(STR_MENU_FLIGHT_MODE),
        IMG_GLOBAL_ERROR,
        0,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
    
}
#endif /* __FLIGHT_MODE_SUPPORT__ */

#if defined (__MMI_DUAL_SIM_MASTER__)

/*****************************************************************************
* FUNCTION
*  EntryShctInvalidSIM1
* DESCRIPTION
*  Display for invalid SIM1 while a shortcut is selected to execute
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInvalidSIM1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MTPNP_PFAL_Is_Card1Absent())
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_NO_SIM1_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);						
    }
    else if(mmi_bootup_is_sim_valid() == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_INVALID_SIM1_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }    	
    else
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_SIM1_CLOSED_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    return;
    
}

/*****************************************************************************
* FUNCTION
*  EntryShctInvalidSIM2
* DESCRIPTION
*  Display for invalid SIM2 while a shortcut is selected to execute
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInvalidSIM2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MTPNP_PFAL_Is_Card2Absent())
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_NO_SIM2_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);						
    }
    else if(mmi_bootup_is_sim2_valid() == MMI_FALSE)
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_INVALID_SIM2_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }   	
    else
    {
        DisplayPopup(
            (U8*) GetString(SHORTCUTS_SIM2_CLOSED_WARNING_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    return;
    
}
#endif /* __MMI_DUAL_SIM_MASTER__ */

/*****************************************************************************
* FUNCTION
*  EntryShctInMainMenu
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctInMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer;
    
#ifdef __MMI_TOUCH_SCREEN__
    U16 ShortcutList[SHCT_MAX_LIST + 1];
    U16 ShortcutStateIcon[SHCT_MAX_LIST + 1];
#else /* __MMI_TOUCH_SCREEN__ */ 
    U16 ShortcutList[SHCT_MAX_LIST];
    U16 ShortcutStateIcon[SHCT_MAX_LIST];
#endif /* __MMI_TOUCH_SCREEN__ */ 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SHCT_MAIN_MENU, NULL, EntryShctInMainMenu, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_MAIN_MENU);
    
    for (i = 0; i < g_shct_cntx.NumSelShct; i++)
    {
        ShortcutList[i] = ShctGetStringID(g_shct_cntx.SelShctList[i].shortcuts);
        if (g_shct_cntx.SelShctList[i].shortcut_state == ENABLE_STATE)
        {
            ShortcutStateIcon[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            ShortcutStateIcon[i] = CHECKBOX_OFF_IMAGE_ID;
        }
    }
#ifdef __MMI_TOUCH_SCREEN__
    
    /* Last Entry is always Calibration */
    if (maxHiliteInfo[MENU_SETTING_CALIBRATION].entryFuncPtr)
    {
        ShortcutList[i] = ShctGetStringID(MENU_SETTING_CALIBRATION);
        ShortcutStateIcon[i++] = CHECKBOX_ON_IMAGE_ID;
    }
    
    if (mmi_frm_test_menu_item_hide(EXTRA_SHORTCUTS_OPTION_EDIT_MENUID))
    {
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_EDIT_MENUID);
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID);
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_DELETE_MENUID);
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    
    if (g_shct_cntx.CurrSelShct > g_shct_cntx.NumSelShct - 1)
    {
        g_shct_cntx.CurrSelShct = 0;
    }
    
    if (i == 0)
    {
        g_shct_cntx.CurrOptionShct = SHR_OPTIONS_ADD;
        ShowCategory15Screen(
            MAIN_MENU_SHORTCUTS_TEXT,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_ADD,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            i,
            ShortcutList,
            (U16*) ShortcutStateIcon,
            LIST_MENU,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(EntryShctEditScreen, KEY_EVENT_UP);
        SetKeyHandler(EntryShctEditScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        RegisterHighlightHandler(ShortcutsMenuIndex);
        ShowCategory15Screen(
            MAIN_MENU_SHORTCUTS_TEXT,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            i,
            ShortcutList,
            (U16*) ShortcutStateIcon,
            LIST_MENU,
            0,
            guiBuffer);
        SetLeftSoftkeyFunction(EntryShctOptionScreen, KEY_EVENT_UP);
        SetKeyHandler(EntryShctOptionScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  ShortcutsMenuIndex
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void ShortcutsMenuIndex(S32 index)
{
#ifdef __MMI_TOUCH_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == g_shct_cntx.NumSelShct)
    {
        mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_EDIT_MENUID);
        mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID);
        mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_DELETE_MENUID);
    }
    else if (g_shct_cntx.CurrSelShct == g_shct_cntx.NumSelShct)
    {
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_EDIT_MENUID);
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID);
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_DELETE_MENUID);
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 
    g_shct_cntx.CurrSelShct = (U8) index;
}


/*****************************************************************************
* FUNCTION
*  ShctResetOptions
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctResetOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_test_menu_item_hide(EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID))
    {
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID);
    }
    if (mmi_frm_test_menu_item_hide(EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID))
    {
        mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID);
    }
}


/*****************************************************************************
* FUNCTION
*  EntryShctOptionScreen
* DESCRIPTION
*  Entry the option screen of shortcuts
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctOptionScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 OptionShortcutsIds[6];
    U8 *guiBuffer;
    U16 MenuId;
    U16 nNumofItem; /* Stores no of children in the submenu */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SHCT_OPTION, NULL, EntryShctOptionScreen, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_OPTION);
    
    ShctResetOptions();
    
    if (g_shct_cntx.CurrOptionShct > SHR_OPTIONS_TOTAL)
    {
        g_shct_cntx.CurrOptionShct = 0;
    }
    
    MenuId = EXTRA_SHORTCUTS_OPTION_MENUID;
    
    if (g_shct_cntx.NumSelShct >= SHCT_MAX_LIST)
    {
        mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_ADD_MENUID);
    }
    
#ifdef __MMI_TOUCH_SCREEN__
    if (g_shct_cntx.CurrSelShct == g_shct_cntx.NumSelShct)
    {
        mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID);
        mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID);
    }
    else
#endif /* __MMI_TOUCH_SCREEN__ */ 
        if (g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct].shortcut_state == ENABLE_STATE)
        {
            mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID);
        }
        else
        {
            mmi_frm_hide_menu_item(EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID);
        }
        
        nNumofItem = GetNumOfChild_Ext(MenuId);
        
        GetSequenceStringIds_Ext(MenuId, OptionShortcutsIds);
        
        SetParentHandler(MenuId);
        
        RegisterHighlightHandler(ExecuteCurrHiliteHandler_Ext);
        
        ShowCategory15Screen(
            STR_GLOBAL_OPTIONS,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            OptionShortcutsIds,
            (U16*) gIndexIconsImageList,
            LIST_MENU,
            0,
            guiBuffer);
        
        SetLeftSoftkeyFunction(ShctSelOption, KEY_EVENT_UP);
        
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        
}


/*****************************************************************************
* FUNCTION
*  EntryShctEditScreen
* DESCRIPTION
*  Execute correspoding function of selected shortcuts.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctEditScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 highlighted = 0;
    U16 EditShortcutsIds[SHCT_MAX_CANDI_LIST];
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SHCT_EDIT, NULL, EntryShctEditScreen, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_EDIT);
    
    for (i = 0; i < g_shct_cntx.NumCandShct; i++)
    {
        EditShortcutsIds[i] = ShctGetStringID(g_shct_cntx.CandShctList[i]);
        
        if (g_shct_cntx.CurrOptionShct == SHR_OPTIONS_EDIT)
        {
            if (guiBuffer == NULL)
                if (g_shct_cntx.CandShctList[i] == g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct].shortcuts)
                {
                    highlighted = i;
                }
        }
    }
    
    RegisterHighlightHandler(HighlightShctEdit);
    ShowCategory1Screen(
        MAIN_MENU_SHORTCUTS_TEXT,
        GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_shct_cntx.NumCandShct,
        EditShortcutsIds,
        highlighted,
        guiBuffer);
    
    switch (g_shct_cntx.CurrOptionShct)
    {
    case SHR_OPTIONS_EDIT:
        g_shct_cntx.Order = g_shct_cntx.CurrSelShct + 1;
        SetLeftSoftkeyFunction(ShctSaveChanges, KEY_EVENT_UP);
        break;
    case SHR_OPTIONS_ADD:
        SetLeftSoftkeyFunction(ShctSetOrder, KEY_EVENT_UP);
        break;
    default:
        break;
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  EntryShctDeleteScreen
* DESCRIPTION
*  Display confirmation screen for deleting one shortcut item.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctDeleteScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_shct_cntx.CurrOptionShct)
    {
    case SHR_OPTIONS_DELETE_ALL:
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(SHORTCUTS_DELETE_ALL_ASK_STRING_ID),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        break;
    default:
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(SHORTCUTS_DELETE_ASK_STRING_ID),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        break;
    }
    
    SetLeftSoftkeyFunction(ShctDeleteItem, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  ShctDeleteItem
* DESCRIPTION
*  Display confirmation screen for deleting one shortcut item.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctDeleteItem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.Integrity == 1)
    {
        switch (g_shct_cntx.CurrOptionShct)
        {
        case SHR_OPTIONS_DELETE:
            memcpy(
                &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct],
                &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct + 1],
                (g_shct_cntx.NumSelShct - g_shct_cntx.CurrSelShct - 1) * sizeof(shct_item_struct));
            g_shct_cntx.NumSelShct--;
            break;
        case SHR_OPTIONS_DELETE_ALL:
            g_shct_cntx.NumSelShct = 0;
            break;
        }
        ShctWriteToNvram();
        
        if (g_shct_cntx.NumSelShct < SHCT_MAX_LIST)
        {
            mmi_frm_unhide_menu_item(EXTRA_SHORTCUTS_OPTION_ADD_MENUID);
        }
        
        ShctShowPopupScreen(STR_GLOBAL_DELETED);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    
}


/*****************************************************************************
* FUNCTION
*  ShctGetStringID
* DESCRIPTION
*  Return the string ID of a menu item.
* PARAMETERS
*  menu_id     [IN]        Index of a menu item.
* RETURNS
*  string index
*****************************************************************************/
U16 ShctGetStringID(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nCustMenus[menu_id - 1].nStrId;
}


/*****************************************************************************
* FUNCTION
*  HighlightShctEdit
* DESCRIPTION
*  Highlight handler for edit shortcut screen
* PARAMETERS
*  index           [IN]        
*  menu_id(?)      [IN]        Index of a menu item.
* RETURNS
*  string index(?)
*****************************************************************************/
void HighlightShctEdit(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrEditShct = (U8) index;
}


/*****************************************************************************
* FUNCTION
*  ATSetShortcuts
* DESCRIPTION
*  Set shortcutfrom AT command
* PARAMETERS
*  index       [?]         
*  inde(?)     [IN]        List of shortcut index
* RETURNS
*  string index
*****************************************************************************/
BOOL ATSetShortcuts(U8 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == NULL)
    {
        return MMI_FALSE;
    }
    
    for (i = 0; i < SHCT_MAX_LIST; i++)
    {
        ID = index[i] - 1;
        if (ID < g_shct_cntx.NumCandShct)
        {
            g_shct_cntx.SelShctList[i].shortcuts = g_shct_cntx.CandShctList[ID];
        }
    }
    
    ShctWriteToNvram();
    
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  ShctSelOption
* DESCRIPTION
*  select option of shortcut item
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  string index(?)
*****************************************************************************/
void ShctSelOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_shct_cntx.CurrOptionShct)
    {
    case SHR_OPTIONS_EDIT:
        EntryShctEditScreen();
        break;
        
    case SHR_OPTIONS_ADD:
        if (g_shct_cntx.NumSelShct < SHCT_MAX_LIST)
        {
            EntryShctEditScreen();
        }
        else
        {
            ShctShowPopupScreen(SHORTCUTS_FULL_MSG_STRING_ID);
        }
        break;
        
    case SHR_OPTIONS_DELETE:
    case SHR_OPTIONS_DELETE_ALL:
        EntryShctDeleteScreen();
        break;
        
    case SHR_OPTIONS_ENABLE:
        ShctChangeState((U8) ENABLE_STATE);
        break;
    case SHR_OPTIONS_DISABLE:
        ShctChangeState((U8) DISABLE_STATE);
        break;
    case SHR_OPTIONS_CHANGE_ORDER:
        ShctSetOrder();
        break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  ShctChangeState
* DESCRIPTION
*  Display confirmation screen for changing the state of the shortcut item.
* PARAMETERS
*  state       [IN]        
* RETURNS
*  void
*****************************************************************************/
void ShctChangeState(U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.Integrity == 1)
    {
        g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct].shortcut_state = state;
        
        ShctWriteToNvram();
        ShctShowPopupScreen(STR_GLOBAL_DONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    
}


/*****************************************************************************
* FUNCTION
*  ShctSetOrder
* DESCRIPTION
*  Set the shortcuts order
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  string index(?)
*****************************************************************************/
void ShctSetOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.Order = g_shct_cntx.CurrSelShct + 1;
    EntryNewScreen(SCR_ID_SHCT_ORDER, NULL, ShctSetOrder, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_ORDER);
    if (g_shct_cntx.CurrOptionShct == SHR_OPTIONS_ADD)
    {
        ShowCategory87Screen(
            SHORTCUTS_CHANGE_ORDER_STRING_ID,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            (S32) (g_shct_cntx.NumSelShct + 1),
            &g_shct_cntx.Order,
            guiBuffer);
    }
    else
    {
        ShowCategory87Screen(
            SHORTCUTS_CHANGE_ORDER_STRING_ID,
            GetRootTitleIcon(EXTRA_SHORTCUTS_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1,
            (S32) (g_shct_cntx.NumSelShct),
            &g_shct_cntx.Order,
            guiBuffer);
    }
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(ShctSaveChanges, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  ShctSaveChanges
* DESCRIPTION
*  Save change of shorcut
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  string index(?)
*****************************************************************************/
void ShctSaveChanges(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    shct_item_struct temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_shct_cntx.CurrOptionShct)
    {
    case SHR_OPTIONS_EDIT:
        g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct].shortcuts =
            g_shct_cntx.CandShctList[g_shct_cntx.CurrEditShct];
        break;
        
    case SHR_OPTIONS_CHANGE_ORDER:
        temp = g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct];
        if (g_shct_cntx.Order < g_shct_cntx.CurrSelShct + 1)
        {
            /* move (order-1) ~ (current select item-1) to next position */
            for (i = g_shct_cntx.CurrSelShct; i >= g_shct_cntx.Order; i--)
            {
                memcpy(&g_shct_cntx.SelShctList[i], &g_shct_cntx.SelShctList[i - 1], sizeof(shct_item_struct));
            }
        }
        else
        {
            memcpy(
                &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct],
                &g_shct_cntx.SelShctList[g_shct_cntx.CurrSelShct + 1],
                sizeof(shct_item_struct) * (g_shct_cntx.Order - (g_shct_cntx.CurrSelShct + 1)));
        }
        g_shct_cntx.SelShctList[g_shct_cntx.Order - 1] = temp;
        g_shct_cntx.CurrSelShct = g_shct_cntx.Order - 1;
        break;
        
    case SHR_OPTIONS_ADD:
        for (i = g_shct_cntx.NumSelShct - 1; i >= g_shct_cntx.Order - 1; i--)
        {
            memcpy(&g_shct_cntx.SelShctList[i + 1], &g_shct_cntx.SelShctList[i], sizeof(shct_item_struct));
        }
        
        g_shct_cntx.SelShctList[g_shct_cntx.Order - 1].shortcuts =
            g_shct_cntx.CandShctList[g_shct_cntx.CurrEditShct];
        g_shct_cntx.SelShctList[g_shct_cntx.Order - 1].shortcut_state = ENABLE_STATE;
        
        g_shct_cntx.NumSelShct++;
        break;
    default:
        break;
    }
    ShctWriteToNvram();
    
    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 2000, SUCCESS_TONE);
    
    DeleteUptoScrID(SCR_ID_SHCT_MAIN_MENU);
}


/*****************************************************************************
* FUNCTION
*  ShctShowPopupScreen
* DESCRIPTION
*  Display popup screen with corresponding messages.
* PARAMETERS
*  Msg     [IN]        Enum value of message type.
* RETURNS
*  void
*****************************************************************************/
void ShctShowPopupScreen(U16 Msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ScreenToShow;
    U16 ScreenImageId;
    ALL_TONE_ENUM ScreenTone;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (Msg)
    {
    case STR_GLOBAL_EMPTY:
        {
            ScreenImageId = IMG_GLOBAL_EMPTY;
            ScreenToShow = SCR_ID_SHCT_OPTION;
            ScreenTone = EMPTY_LIST_TONE;
            break;
            
        }
    case SHORTCUTS_FULL_MSG_STRING_ID:
        {
            ScreenImageId = IMG_GLOBAL_NO;
            ScreenToShow = SCR_ID_SHCT_OPTION;
            ScreenTone = EMPTY_LIST_TONE;
            break;
            
        }
    default:    /* case STR_GLOBAL_DONE */
        {
            ScreenImageId = IMG_GLOBAL_ACTIVATED;
            ScreenToShow = SCR_ID_SHCT_MAIN_MENU;
            ScreenTone = SUCCESS_TONE;
            break;
        }
    }
    
    DisplayPopup((U8*) GetString(Msg), ScreenImageId, 0, UI_POPUP_NOTIFYDURATION_TIME, (U8) ScreenTone);
    
    DeleteUptoScrID(ScreenToShow);
}

#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)


/*****************************************************************************
* FUNCTION
*  ShctReadDedicatedListFromNVRAM
* DESCRIPTION
*  Read dedicated key shortcut list and initialized.
* PARAMETERS
*  void
*  index(?)        [IN]        List of shortcut index
* RETURNS
*  void
*****************************************************************************/
void ShctReadDedicatedListFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nvramData[SHCT_NVRAM_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SHORTCUTS_LID, 2, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
    
    for (i = 0; i < TOTAL_DEDICATED_KEYS; i++)
    {
        if (nvramData[i] == 0xffff)
        {
            memcpy((void*)&nvramData, (void*)&gShctDefaultDediList, TOTAL_DEDICATED_KEYS * 2);
            break;
        }
    }
    
    for (i = 0; i < TOTAL_DEDICATED_KEYS; i++)
    {
        if (maxHiliteInfo[nvramData[i]].entryFuncPtr == NULL)
        {
            g_shct_cntx.DediShctList[i] = SHCT_DEFAULT_MENU_ID;
        }
        else
        {
            memcpy((void*)&g_shct_cntx.DediShctList[i], (void*)&nvramData[i], 2);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  ShctWriteDedicatedListToNVRAM
* DESCRIPTION
*  Write dedicated key shortcut list to NVRAM.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctWriteDedicatedListToNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvramData[SHCT_NVRAM_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nvramData, 0xff, sizeof(nvramData));
    
    memcpy((void*)&nvramData, (void*)&g_shct_cntx.DediShctList, sizeof(g_shct_cntx.DediShctList));
    
    WriteRecord(NVRAM_EF_SHORTCUTS_LID, 2, (void*)nvramData, SHCT_NVRAM_SIZE, &error);
}


/*****************************************************************************
* FUNCTION
*  EntryShctArrowKeyList
* DESCRIPTION
*  Display Up/Down/Left/Right key for editing.
* PARAMETERS
*  void
* RETURNS
*  string index(?)
*****************************************************************************/
void EntryShctArrowKeyList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[TOTAL_DEDICATED_KEYS];
    U16 nItems;
    U8 *guiBuffer;
    U8 *popupList[TOTAL_DEDICATED_KEYS];
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SHCT_DEDICATED_KEYS, NULL, EntryShctArrowKeyList, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_DEDICATED_KEYS);
    nItems = GetNumOfChild(MENU_SETTING_DEDICATED_KEYS);
    GetSequenceStringIds(MENU_SETTING_DEDICATED_KEYS, ItemList);
    
    /* get popup hint */
    for (i = 0; i < TOTAL_DEDICATED_KEYS; i++)
    {
        if (g_shct_cntx.DediShctList[i] == SHCT_DEFAULT_MENU_ID)
        {
            popupList[i] = (U8*) GetString(MAIN_MENU_SHORTCUTS_TEXT);
        }
        else
        {
            popupList[i] = (U8*) GetString(ShctGetStringID(g_shct_cntx.DediShctList[i]));
        }
    }
    
    SetParentHandler(MENU_SETTING_DEDICATED_KEYS);
    RegisterHighlightHandler(HighlightShctSelectedKey);
    
    ShowCategory52Screen(
        STR_DEDICATED_KEY,
        GetRootTitleIcon(MENU_SETTING_DEDICATED_KEYS),
        STR_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (U16*) gIndexIconsImageList,
        popupList,
        0,
        0,
        guiBuffer);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryShctEditDedicatedKey, KEY_EVENT_UP);
    SetKeyHandler(EntryShctEditDedicatedKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightDedicatedKeys
* DESCRIPTION
*  Highlight handler of dedicated key shortcut item in Phonesetup
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightDedicatedKeys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EntryShctArrowKeyList, KEY_EVENT_UP);
    SetKeyHandler(EntryShctArrowKeyList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  HighlightShctSelectedKey
* DESCRIPTION
*  Highlight handler of dedicated keys setting
* PARAMETERS
*  nIndex      [IN]        
* RETURNS
*  void
*****************************************************************************/
void HighlightShctSelectedKey(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shct_cntx.CurrSelArrow = (U8) nIndex;
}


/*****************************************************************************
* FUNCTION
*  EntryShctEditDedicatedKey
* DESCRIPTION
*  Entry edit dedicated key shortcut screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void EntryShctEditDedicatedKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 highlighted = 0;
    U16 EditShortcutsIds[SHCT_MAX_CANDI_LIST + 1];
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SHCT_EDIT_DEDICATED_KEYS, NULL, EntryShctEditDedicatedKey, NULL);
    
    /* the first item == Shortcuts */
    EditShortcutsIds[0] = MAIN_MENU_SHORTCUTS_TEXT;
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SHCT_EDIT_DEDICATED_KEYS);
    
    for (i = 0; i < g_shct_cntx.NumCandShct; i++)
    {
        EditShortcutsIds[i + 1] = ShctGetStringID(g_shct_cntx.CandShctList[i]);
        if (guiBuffer == NULL)
            if (g_shct_cntx.CandShctList[i] == g_shct_cntx.DediShctList[g_shct_cntx.CurrSelArrow])
            {
                highlighted = i + 1;
            }
    }
    
    RegisterHighlightHandler(HighlightShctEdit);
    
    ShowCategory1Screen(
        MAIN_MENU_SHORTCUTS_TEXT,
        GetRootTitleIcon(MENU_SETTING_DEDICATED_KEYS),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_shct_cntx.NumCandShct + 1,
        EditShortcutsIds,
        highlighted,
        guiBuffer);
    SetLeftSoftkeyFunction(ShctSaveDedicated, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  ShctSaveDedicated
* DESCRIPTION
*  Save dedicated key shortcut.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctSaveDedicated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.CurrEditShct > 0)
    {
        g_shct_cntx.DediShctList[g_shct_cntx.CurrSelArrow] = g_shct_cntx.CandShctList[g_shct_cntx.CurrEditShct - 1];
    }
    else
    {
        g_shct_cntx.DediShctList[g_shct_cntx.CurrSelArrow] = SHCT_DEFAULT_MENU_ID;
    }
    
    ShctWriteDedicatedListToNVRAM();
    
    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_SHCT_DEDICATED_KEYS);
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteUpKey
* DESCRIPTION
*  Up key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteUpKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.DediShctList[0] != SHCT_DEFAULT_MENU_ID)
    {
        if (ShctCheckItemCanbeExecuted(g_shct_cntx.DediShctList[0]) == 0)
        {
            g_shct_cntx.IsKeyRetrieving = TRUE;
            (*maxHiliteInfo[g_shct_cntx.DediShctList[0]].entryFuncPtr) ();
            g_shct_cntx.IsKeyRetrieving = FALSE;           
            execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        }
    }
    else
    {
        EntryShctInIdle();
    }
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteDownKey
* DESCRIPTION
*  Down key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteDownKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.DediShctList[1] != SHCT_DEFAULT_MENU_ID)
    {
        if (ShctCheckItemCanbeExecuted(g_shct_cntx.DediShctList[1]) == 0)
        {
            g_shct_cntx.IsKeyRetrieving = TRUE;
            (*maxHiliteInfo[g_shct_cntx.DediShctList[1]].entryFuncPtr) ();
            g_shct_cntx.IsKeyRetrieving = FALSE;
            execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        }
    }
    else
    {
        EntryShctInIdle();
    }
    
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteLeftKey
* DESCRIPTION
*  Left key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteLeftKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.DediShctList[2] != SHCT_DEFAULT_MENU_ID)
    {
        if (ShctCheckItemCanbeExecuted(g_shct_cntx.DediShctList[2]) == 0)
        {
            g_shct_cntx.IsKeyRetrieving = TRUE;
            (*maxHiliteInfo[g_shct_cntx.DediShctList[2]].entryFuncPtr) ();
            g_shct_cntx.IsKeyRetrieving = FALSE;
            execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        }
    }
    else
    {
        EntryShctInIdle();
    }
}


/*****************************************************************************
* FUNCTION
*  ShctExecuteRightKey
* DESCRIPTION
*  Right key handler in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void ShctExecuteRightKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_shct_cntx.DediShctList[3] != SHCT_DEFAULT_MENU_ID)
    {
        if (ShctCheckItemCanbeExecuted(g_shct_cntx.DediShctList[3]) == 0)
        {
            g_shct_cntx.IsKeyRetrieving = TRUE;
            (*maxHiliteInfo[g_shct_cntx.DediShctList[3]].entryFuncPtr) ();
            g_shct_cntx.IsKeyRetrieving = FALSE;
            execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        }
    }
    else
    {
        EntryShctInIdle();
    }
}


/*****************************************************************************
* FUNCTION
*  RegisterDedicatedKeyHandlers
* DESCRIPTION
*  Register arrow key handlers in IDLE screen.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void RegisterDedicatedKeyHandlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetCurrentProfileAsActivatedProfile();
    SetKeyHandler(ShctExecuteUpKey, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ShctExecuteDownKey, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ShctExecuteLeftKey, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ShctExecuteRightKey, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */ // #ifdef __MMI_DEDICATED_KEY_SHORTCUTS__
#endif /* __DISABLE_SHORTCUTS_IMPL__ */ /* #if !defined (__MMI_FOURWAYS_KEY_DISABLE__) || defined (__MMI_VRSD_SHORTCUT__) || defined (__MMI_VRSI__) */
#endif /* _MMI_SHORTCUTS_C */ /* SHORTCUTS_APP */
#endif /* SHORTCUTS_APP */ /* _MMI_SHORTCUTS_C */

