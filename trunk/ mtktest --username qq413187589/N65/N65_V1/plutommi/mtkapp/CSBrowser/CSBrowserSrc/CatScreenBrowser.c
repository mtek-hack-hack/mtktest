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
*  CatScreenBrowser.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Category Screen Browser
*
* Author:
* -------
*  
*
*==============================================================================
*           HISTORY
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
 * created by clearfsimport
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_CSB_BROWSER__

#include "SettingProfile.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"

#include "CatScreenBrowserDefs.h"
#include "CatScreenBrowserProts.h"

/* Global Variables */
csb_struct g_CSB_struct;
U8 csb_buffer[MAX_CSB_SCREEN_NAME_LENGTH];
extern csb_screen_info screen_info[TOTAL_CATEGORY_SCREENS];

csb_category_screen csb_category_screen_list[TOTAL_CATEGORY_SCREENS];

U16 csb_search_hint_popups[CSB_TOTAL_CONTROLS] = {0};
U16 csb_app_hint_popups[CSB_TOTAL_APP] = {0};

S32 g_csb_timer;
U8 g_csb_highlighted_item;
U16 g_csb_index;

U8 g_buffer[MAX_LOCAL_BUFFER];
U8 g_buffer1[MAX_LOCAL_BUFFER_1];

/* Global image list array */
U16 g_image_id_list[2];

#ifdef __MMI_PREFER_INPUT_METHOD__
extern void SetInputMethod(U16 index);
#endif /* __MMI_PREFER_INPUT_METHOD__ */

/**************************************************************
********************* HIGHLIGHT HANDLERS **********************
***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(PreEntryCSBViewMainMenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBStartView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBStartView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(PreEntryCSBStartView, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBStartViewX
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBStartViewX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBStartViewX, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBViewOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBViewOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBViewOptions, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBOptionsViewMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBOptionsViewMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBOptionsViewMode, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBOptionsModeSettings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBOptionsModeSettings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBOptionsModeSettings, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBOptionsAutoModeTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBOptionsAutoModeTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBOptionsAutoModeTime, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBOptionsManualMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBOptionsManualMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBOptionsManualMode, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBSearch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBSearch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBSearchMainmenu, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBSearchByControl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBSearchByControl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBSearchByControl, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBSearchByApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBSearchByApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBSearchByApp, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBSearchByScrID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBSearchByScrID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBSearchByScrID, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBTestTool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBTestTool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBTestTool, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBTestToolRun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBTestToolRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(PreEntryCSBTestToolRun, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBTestToolSetLoc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBTestToolSetLoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBTestToolSetLoc, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCSBTestToolViewImages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCSBTestToolViewImages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryCSBTestToolViewImages, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  InitCSB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitCSB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 csb_default_folder_path_ansii[MAX_CSB_PATH_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
	/* Commented as suggested by MTK */
    //csb_frm_read_from_nvram();

    g_CSB_struct.csb_settings.timer_value = 2000;
	g_CSB_struct.csb_settings.view_mode		= VIEW_MODE_MANUAL;
	g_CSB_struct.csb_settings.manual_mode	= MANUAL_MODE_INTERACTIVE;

        sprintf(csb_default_folder_path_ansii, "%c%s", MMI_PUBLIC_DRV, CSB_DEFAULT_FOLDER);
        mmi_asc_to_ucs2(
            (PS8) g_CSB_struct.csb_settings.csb_screenshots_folder_path,
            (PS8) csb_default_folder_path_ansii);
  
    g_CSB_struct.pscreen_info = (csb_screen_info*) screen_info;

    /* Prepares the HINT pop-ups */
    csb_frm_prepare_search_hint_popups();
    csb_frm_prepare_app_hint_popups();
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Resets the counter for the next show */
    g_CSB_struct.screen_counter = 0;
    /* Resets the buffer for the editor screens */
    memset(csb_buffer, CSB_NULL, MAX_CSB_SCREEN_NAME_LENGTH);

    /* It creates the CSB folder both in Phone Memory and Card Memory */
    csb_frm_create_csb_folder();
    /* Call the CSB main menu */
    EntryCSBMainMenu();
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[3];
    U16 ItemIcons[3];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[3];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB, NULL, EntryCSBMainMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB);

    nItems = GetNumOfChild(CSB_MENUID);
    GetSequenceStringIds(CSB_MENUID, ItemList);
    SetParentHandler(CSB_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (index = 0; index < nItems; index++)
    {
        PopUpList[index] = NULL;
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBViewMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBViewMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set the screen counter ZERO before starting StartView */
    g_CSB_struct.screen_counter = 0;
    EntryCSBViewMainMenu();
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBViewMainMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBViewMainMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[3];
    U16 ItemIcons[3];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[3];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_VIEW_SCR_ID, NULL, EntryCSBViewMainMenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_VIEW_SCR_ID);

    nItems = GetNumOfChild(CSB_VIEW_MENUID);
    GetSequenceStringIds(CSB_VIEW_MENUID, ItemList);
    SetParentHandler(CSB_VIEW_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    csb_frm_set_search_mode(SEARCH_BY_VIEW);

    for (index = 0; index < nItems; index++)
    {
        PopUpList[index] = NULL;
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_VIEW_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBStartView
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBStartView(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the counter */
    g_CSB_struct.screen_counter = 0;

    EntryCSBStartView();
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBStartViewX
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBStartViewX(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_START_VIEW_X_SCR_ID, NULL, EntryCSBStartViewX, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_START_VIEW_X_SCR_ID);
    inputBuffer = GetCurrInputBuffer(SCR_ID_CSB_START_VIEW_X_SCR_ID);

#ifdef __MMI_PREFER_INPUT_METHOD__
    SetInputMethod(INPUT_MODE_123);
#endif /* __MMI_PREFER_INPUT_METHOD__ */

    ShowCategory5Screen(
        STR_ID_CSB_START_VIEW_X_TEXT,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC_CHANGEABLE,
        (U8*) csb_buffer,
        MAX_CSB_SCREEN_NAME_LENGTH,
        guiBuffer);

    SetLeftSoftkeyFunction(csb_frm_validate_screen_name, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBViewOptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBViewOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[2];
    U16 ItemIcons[2];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[2];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_VIEW_OPTIONS_SCR_ID, NULL, EntryCSBViewOptions, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_VIEW_OPTIONS_SCR_ID);

    nItems = GetNumOfChild(CSB_VIEW_OPTIONS_MENUID);
    GetSequenceStringIds(CSB_VIEW_OPTIONS_MENUID, ItemList);
    SetParentHandler(CSB_VIEW_OPTIONS_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (index = 0; index < nItems; index++)
    {
        PopUpList[index] = NULL;
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_VIEW_OPTIONS_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsViewMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsViewMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[VIEW_MODE_TOTAL];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_OPTIONS_VIEW_MODE_SCR_ID, NULL, EntryCSBOptionsViewMode, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_OPTIONS_VIEW_MODE_SCR_ID);

    nItems = GetNumOfChild(CSB_VIEW_OPTIONS_VIEW_MODE_MENUID);
    GetSequenceStringIds(CSB_VIEW_OPTIONS_VIEW_MODE_MENUID, ItemList);
    SetParentHandler(CSB_VIEW_OPTIONS_VIEW_MODE_MENUID);
    RegisterHighlightHandler(csb_frm_set_current_view_mode);

    ShowCategory11Screen(
        STR_ID_CSB_OPTIONS_VIEW_MODE_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        g_CSB_struct.csb_settings.view_mode,
        guiBuffer);

    SetLeftSoftkeyFunction(csb_frm_save_view_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_view_mode
 * DESCRIPTION
 *  Set the current view mode
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_view_mode(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((U16) nIndex)
    {
        case VIEW_MODE_MANUAL:
            g_csb_highlighted_item = VIEW_MODE_MANUAL;
            break;
        case VIEW_MODE_AUTO:
            g_csb_highlighted_item = VIEW_MODE_AUTO;
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsModeSettings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsModeSettings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[2];
    U16 ItemIcons[2];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[2];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_OPTIONS_MODE_SETTINGS_SCR_ID, NULL, EntryCSBOptionsModeSettings, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_OPTIONS_MODE_SETTINGS_SCR_ID);

    nItems = GetNumOfChild(CSB_VIEW_OPTIONS_MODE_SETTINGS_MENUID);
    GetSequenceStringIds(CSB_VIEW_OPTIONS_MODE_SETTINGS_MENUID, ItemList);
    SetParentHandler(CSB_VIEW_OPTIONS_MODE_SETTINGS_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (index = 0; index < nItems; index++)
    {
        PopUpList[index] = NULL;
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_OPTIONS_MODE_SETTINGS_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsAutoModeTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsAutoModeTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_OPTIONS_AUTO_MODE_TIME_SCR_ID, NULL /* TODO */ , EntryCSBOptionsAutoModeTime, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_OPTIONS_AUTO_MODE_TIME_SCR_ID);
    inputBuffer = GetCurrInputBuffer(SCR_ID_CSB_OPTIONS_AUTO_MODE_TIME_SCR_ID);

    /* Convert the timer value from milli seconds to seconds before passing to category */
    g_csb_timer = g_CSB_struct.csb_settings.timer_value / 1000;

    ShowCategory87Screen(
        STR_ID_CSB_AUTO_MODE_TIME_TEXT,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MIN_CSB_AUTO_MODE_TIME,
        MAX_CSB_AUTO_MODE_TIME,
        &g_csb_timer,
        guiBuffer);

    SetLeftSoftkeyFunction(csb_frm_save_auto_mode_time, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBOptionsManualMode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBOptionsManualMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAUNAL_MODE_TOTAL];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_OPTIONS_MANUAL_MODE_SCR_ID, NULL, EntryCSBOptionsManualMode, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_OPTIONS_MANUAL_MODE_SCR_ID);

    nItems = GetNumOfChild(CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID);
    GetSequenceStringIds(CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID, ItemList);
    SetParentHandler(CSB_OPTIONS_SETTING_MANUAL_MODE_MENUID);
    RegisterHighlightHandler(csb_frm_set_current_manual_mode);

    ShowCategory11Screen(
        STR_ID_CSB_MANUAL_MODE_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        g_CSB_struct.csb_settings.manual_mode,
        guiBuffer);

    SetLeftSoftkeyFunction(csb_frm_save_manual_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_manual_mode
 * DESCRIPTION
 *  Set the current manual mode
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_manual_mode(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((U16) nIndex)
    {
        case MANUAL_MODE_INTERACTIVE:
            g_csb_highlighted_item = MANUAL_MODE_INTERACTIVE;
            break;
        case MANUAL_MODE_NONINTERACTIVE:
            g_csb_highlighted_item = MANUAL_MODE_NONINTERACTIVE;
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchMainmenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchMainmenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[SEARCH_MODE_TOTAL];
    U16 ItemIcons[SEARCH_MODE_TOTAL];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[SEARCH_MODE_TOTAL];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_SEARCH_SCR_ID, NULL, EntryCSBSearchMainmenu, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_SEARCH_SCR_ID);

    nItems = GetNumOfChild(CSB_SEARCH_MENUID);
    GetSequenceStringIds(CSB_SEARCH_MENUID, ItemList);
    SetParentHandler(CSB_SEARCH_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (index = 0; index < nItems; index++)
    {
        PopUpList[index] = NULL;
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_SEARCH_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchByControl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchByControl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[CSB_TOTAL_CONTROLS];
    U16 ItemIcons[CSB_TOTAL_CONTROLS];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[CSB_TOTAL_CONTROLS];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_SEARCH_BY_CONT_SCR_ID, NULL, EntryCSBSearchByControl, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_SEARCH_BY_CONT_SCR_ID);

    nItems = GetNumOfChild(CSB_SEARCH_CONTROL_MENUID);
    GetSequenceStringIds(CSB_SEARCH_CONTROL_MENUID, ItemList);
    SetParentHandler(CSB_SEARCH_CONTROL_MENUID);
    RegisterHighlightHandler(csb_frm_set_current_control_name);

    csb_frm_set_search_mode(SEARCH_BY_CONTROL);

    for (index = 0; index < nItems; index++)
    {
        /* This call creates the hint data for each menu item in coming screen */
        csb_frm_prepare_hint_data((U16) index);

        /* ASSERT if the above API returns NULL in hintData */
        ASSERT(hintData[index] != NULL);
        PopUpList[index] = hintData[index];
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory55Screen(
        STR_ID_CSB_SEARCH_CONTROL_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        (U8 **) PopUpList,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(pre_entry_csb_prepare_cat_scr_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_control_name
 * DESCRIPTION
 *  Set the current control flag
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_control_name(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Store the currently highlighted item to show caption on next screen */
    g_CSB_struct.caption_str_id = (U16)nIndex;
    /* switch case to set the current control flag */
    switch ((U16) nIndex)
    {
        case CSB_CONT_CALL_SCR:
            g_CSB_struct.current_flag = CSB_CALL_SCR;
            break;
        case CSB_CONT_COLOR_PICKER_SCR:
            g_CSB_struct.current_flag = CSB_COLOR_PICKER_SCR;
            break;
        case CSB_CONT_EDITOR_SCR:
            g_CSB_struct.current_flag = CSB_EDITOR_SCR;
            break;
        case CSB_CONT_IDLE_SCR:
            g_CSB_struct.current_flag = CSB_IDLE_SCR;
            break;
        case CSB_CONT_IMAGE_VIEWER_SCR:
            g_CSB_struct.current_flag = CSB_IMAGE_VIEWER_SCR;
            break;
        case CSB_CONT_LIST_MENU_SCR:
            g_CSB_struct.current_flag = CSB_LIST_MENU_SCR;
            break;
        case CSB_CONT_MATRIX_MENU_SCR:
            g_CSB_struct.current_flag = CSB_MATRIX_MENU_SCR;
            break;
        case CSB_CONT_POPUP_SCR:
            g_CSB_struct.current_flag = CSB_POPUP_SCR;
            break;
        case CSB_CONT_PROGRESS_BAR_SCR:
            g_CSB_struct.current_flag = CSB_PROGRESS_BAR_SCR;
            break;
        case CSB_CONT_SLIDER_SCR:
            g_CSB_struct.current_flag = CSB_SLIDER_SCR;
            break;
        case CSB_CONT_RADIO_BUTTON_SCR:
            g_CSB_struct.current_flag = CSB_RADIO_BUTTON_SCR;
            break;
        case CSB_CONT_CHECK_BOX_SCR:
            g_CSB_struct.current_flag = CSB_CHECK_BOX_SCR;
            break;
        case CSB_CONT_SUB_LCD:
            g_CSB_struct.current_flag = CSB_SUB_LCD;
            break;
        case CSB_CONT_PANEL:
            g_CSB_struct.current_flag = CSB_PANEL;//052907 CSB
            break;
        default:
            ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchByApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchByApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[CSB_TOTAL_APP];
    U16 ItemIcons[CSB_TOTAL_APP];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[CSB_TOTAL_APP];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_SEARCH_BY_APP_SCR_ID, NULL, EntryCSBSearchByApp, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_SEARCH_BY_APP_SCR_ID);

    nItems = GetNumOfChild(CSB_SEARCH_APP_MENUID);
    GetSequenceStringIds(CSB_SEARCH_APP_MENUID, ItemList);
    SetParentHandler(CSB_SEARCH_APP_MENUID);
    RegisterHighlightHandler(csb_frm_set_current_app_name);

    csb_frm_set_search_mode(SEARCH_BY_APP);

    for (index = 0; index < nItems; index++)
    {
        /* This call creates the hint data for each menu item in coming screen */
        csb_frm_prepare_hint_data((U16) index);

        /* ASSERT if the above API returns NULL in hintData */
        ASSERT(hintData[index] != NULL);
        PopUpList[index] = hintData[index];
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory55Screen(
        STR_ID_CSB_SEARCH_APP_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        (U8 **) PopUpList,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(pre_entry_csb_prepare_cat_scr_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_app_name
 * DESCRIPTION
 *  Set the current application flag
 * PARAMETERS
 *  nIndex      [IN]        
 *  RETURNS           void(?)
 *****************************************************************************/
void csb_frm_set_current_app_name(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Store the currently highlighted item to show caption on next screen */
    g_CSB_struct.caption_str_id = (U16)nIndex;

    /* switch case to select the current application flag */
    switch ((U16) nIndex)
    {
        case CSB_APP_CALLS:
            g_CSB_struct.current_flag = CSB_CALLS;
            break;
        case CSB_APP_EDITOR:
            g_CSB_struct.current_flag = CSB_EDITOR;
            break;
        case CSB_APP_ENGG_MODE:
            g_CSB_struct.current_flag = CSB_ENGG_MODE;
            break;
        case CSB_APP_EXTRA:
            g_CSB_struct.current_flag = CSB_EXTRA;
            break;
        case CSB_APP_FUN_AND_GAMES:
            g_CSB_struct.current_flag = CSB_FUN_AND_GAMES;
            break;
        case CSB_APP_FILE_MANAGER:
            g_CSB_struct.current_flag = CSB_FILE_MANAGER;
            break;
        case CSB_APP_MESSAGES:
            g_CSB_struct.current_flag = CSB_MESSAGES;
            break;
        case CSB_APP_MISC:
            g_CSB_struct.current_flag = CSB_MISC;
            break;
        case CSB_APP_MULTIMEDIA:
            g_CSB_struct.current_flag = CSB_MULTIMEDIA;
            break;
        case CSB_APP_ORGANIZER:
            g_CSB_struct.current_flag = CSB_ORGANIZER;
            break;
        case CSB_APP_PHONEBOOK:
            g_CSB_struct.current_flag = CSB_PHONEBOOK;
            break;
        case CSB_APP_PROFILE:
            g_CSB_struct.current_flag = CSB_PROFILE;
            break;
        case CSB_APP_SERVICES:
            g_CSB_struct.current_flag = CSB_SERVICES;
            break;
        case CSB_APP_SHORTCUT:
            g_CSB_struct.current_flag = CSB_SHORTCUT;
            break;
        case CSB_APP_SETTINGS:
            g_CSB_struct.current_flag = CSB_SETTINGS;
            break;
        case CSB_APP_WAP:
            g_CSB_struct.current_flag = CSB_WAP;
            break;
        case CSB_APP_HID:
            g_CSB_struct.current_flag = CSB_HID;//052907 CSB
            break;
        default:
            ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_csb_cat_scr_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_csb_cat_scr_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList_app[CSB_TOTAL_APP];
    U16 ItemList_control[CSB_TOTAL_CONTROLS];
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    S32 nitem = 0;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_SEARCH_LIST_SCR_ID, NULL, entry_csb_cat_scr_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_SEARCH_LIST_SCR_ID);
    RegisterHighlightHandler(csb_frm_set_current_screen_index);

    nitem = g_CSB_struct.number_of_screens;
    /* If the number of screens found is ZERO, so pop-up and return back */
    if (!nitem)
    {
        DisplayPopup((PU8) GetString(STR_ID_CSB_NO_SCR_FOUND_TEXT), IMG_GLOBAL_ERROR, 1, CSB_NOTIFY_DURATION, 0);
        DeleteNHistory(1);
        return;
    }

    /* Get the string list of the previous menu, so that we can get the Caption string according to the
       previous menu selected */
    if (SEARCH_MODE_APP == csb_frm_get_search_mode())
    {
        GetSequenceStringIds(CSB_SEARCH_APP_MENUID, ItemList_app);
        str_id = ItemList_app[g_CSB_struct.caption_str_id];
    }
    else if (SEARCH_MODE_CONTROL == csb_frm_get_search_mode())
    {
        GetSequenceStringIds(CSB_SEARCH_CONTROL_MENUID, ItemList_control);
        str_id = ItemList_control[g_CSB_struct.caption_str_id];
    }

    ShowCategory184Screen(
        str_id,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nitem,
        csb_cat_scr_list_get_item,
        0,
        hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(entry_csb_show_cat_scr, KEY_EVENT_UP);
    SetKeyHandler(entry_csb_show_cat_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  csb_frm_set_current_screen_index
 * DESCRIPTION
 *  Set current highlighted screen index
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void csb_frm_set_current_screen_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_CSB_struct.current_index = csb_category_screen_list[nIndex].screen_index;
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBSearchByScrID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBSearchByScrID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */
    U8 *inputBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_SEARCH_BY_SCRID_SCR_ID, NULL, EntryCSBSearchByScrID, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_SEARCH_BY_SCRID_SCR_ID);
    inputBuffer = GetCurrInputBuffer(SCR_ID_CSB_SEARCH_BY_SCRID_SCR_ID);
#ifdef __MMI_PREFER_INPUT_METHOD__
    SetInputMethod(INPUT_MODE_123);
#endif /* __MMI_PREFER_INPUT_METHOD__ */

    csb_frm_set_search_mode(SEARCH_BY_SCREENID);

    ShowCategory5Screen(
        STR_ID_CSB_SEARCH_SCREENID_TEXT,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC_CHANGEABLE,
        (U8*) csb_buffer,
        MAX_CSB_SCREEN_NAME_LENGTH,
        guiBuffer);

    SetLeftSoftkeyFunction(csb_frm_validate_screen_name, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestTool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestTool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[3];
    U16 ItemIcons[3];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[3];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_TESTTOOL_SCR_ID, NULL, EntryCSBTestTool, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_TESTTOOL_SCR_ID);

    nItems = GetNumOfChild(CSB_TESTOOL_MENUID);
    GetSequenceStringIds(CSB_TESTOOL_MENUID, ItemList);
    SetParentHandler(CSB_TESTOOL_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (index = 0; index < nItems; index++)
    {
        PopUpList[index] = NULL;
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_TESTTOOL_TEXT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  PreEntryCSBTestToolRun
 * DESCRIPTION
 *  Function to Run the test tool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PreEntryCSBTestToolRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 disk_free_space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_PATH_NOT_FOUND == FS_GetFolderSize((PU16) g_CSB_struct.csb_settings.csb_screenshots_folder_path, FS_COUNT_IN_BYTE, NULL, 0))
    {
        /* If the set path is invalid */
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, CSB_NOTIFY_DURATION, 0);
        return;
    }

    if (*(g_CSB_struct.csb_settings.csb_screenshots_folder_path) == MMI_CARD_DRV)
    {
        /* Check is memory card is present or not */
        if (fmgr_is_msdc_present())
        {
            if (csb_frm_check_disk_free_space(&disk_free_space))
            {
                EntryCSBTestToolRun();
            }
            else
            {
                /* If the disk space is less that required */
                csb_show_current_memory_status(&disk_free_space);
                DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
                return;
            }
        }
        else
        {
            /* Once all the category screenshots are taken, show the DONE pop-up */
            DisplayPopup((PU8) GetString(STR_ID_CSB_NO_MEMORY_CARD), IMG_GLOBAL_ERROR, 1, CSB_NOTIFY_DURATION, 0);
            DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
            return;
        }
    }
    else
    {
        if (csb_frm_check_disk_free_space(&disk_free_space))
        {
            EntryCSBTestToolRun();
        }
        else
        {
            /* If the disk space is less that required */
            csb_show_current_memory_status(&disk_free_space);
            DeleteUptoScrID(SCR_ID_CSB_TESTTOOL_SCR_ID);
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestToolRun
 * DESCRIPTION
 *  Function to Run the test tool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestToolRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	StartTimer(CSB_AUTO_MODE_TIMER_ID, 250, csb_frm_testtool_callback);
}


/*****************************************************************************
 * FUNCTION
 *  TestToolProcessingScr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void TestToolProcessingScr(U16 str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_PROCESSING_SCR_ID, NULL, NULL, NULL);

    ShowCategory66Screen(
        STR_ID_CSB_PROCESSING_TEXT,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(str_id),
        IMG_GLOBAL_PROGRESS,
        guiBuffer);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestToolSetLoc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestToolSetLoc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 file_path_in_ascii[CSB_DRIVE_LENGTH];
    S8 file_path[CSB_DRIVE_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    //Open the root directory of the file mgr in order to support
    // memory card as well as phone
    sprintf((S8*) file_path_in_ascii, "%s", "root");

    mmi_asc_to_ucs2((PS8) file_path, file_path_in_ascii);

    mmi_fmgr_select_path_and_enter(
        APP_CSB,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) file_path,
        csb_frm_select_folder_callback);
}


/*****************************************************************************
 * FUNCTION
 *  EntryCSBTestToolViewImages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCSBTestToolViewImages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S8 file_path_in_unicode[MAX_CSB_PATH_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);

    mmi_ucs2cpy(file_path_in_unicode, (S8*) g_CSB_struct.csb_settings.csb_screenshots_folder_path);

    mmi_fmgr_select_path_and_enter(
        APP_CSB,
        FMGR_SELECT_BROWSE,
        filter,
        (S8*) file_path_in_unicode,
        csb_frm_view_images_callback);
}


/*****************************************************************************
 * FUNCTION
 *  csb_show_current_screen_ID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void csb_show_current_screen_ID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 local_buffer_ansii[5];
    U8 screen_ID[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_SHOW_CURR_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    /* If the view mode is AUTO, STOP the timer till OK pressed */
    if (VIEW_MODE_AUTO == g_CSB_struct.csb_settings.view_mode)
    {
        StopTimer(CSB_AUTO_MODE_TIMER_ID);
    }

    /* NULLS the memory */
    memset(screen_ID, CSB_NULL, 40);

    /* Copy the string in the final buffer */
    mmi_asc_to_ucs2((PS8) screen_ID, (PS8) "Screen ID = ");

    /* Decrement the index of the database, as it is already incremented by 1 */
    if (g_CSB_struct.screen_counter)
        --g_CSB_struct.screen_counter;

    /* If the category ID is ZERO, append the category name */
    if (g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].cat_ID == 0)
    {
        mmi_ucs2cat((PS8) screen_ID, (PS8) g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].cat_scr_name);
    }
    /* If the category has ID, append the category ID */
    else
    {
        gui_itoa(
            (S32) g_CSB_struct.pscreen_info[g_CSB_struct.screen_counter].cat_ID,
            (UI_string_type) local_buffer_ansii,
            10);
        mmi_ucs2cat((PS8) screen_ID, (PS8) local_buffer_ansii);
    }

    /* Display the screen id in the pop up */
    DisplayPopup((PU8) screen_ID, 0, 1, CSB_NOTIFY_DURATION, 0);

}


/*****************************************************************************
 * FUNCTION
 *  csb_show_current_memory_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdisk_free_space        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void csb_show_current_memory_status(U64 *pdisk_free_space)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer = NULL;
    U8 Mem_Error[90];
    S32 space_required;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_MEM_ERROR_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    /* NULLS the memory */
    memset(Mem_Error, CSB_NULL, 90);
    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    space_required = TOTAL_CATEGORY_SCREENS * 11 * 1024;

    mmi_asc_to_ucs2((PS8) Mem_Error, (PS8) "Mem Error!!\n");
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Req:= ");

    /* Copy the string in the final buffer */
    mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer);

    gui_itoa((S32) space_required, (UI_string_type) g_buffer1, 10);

    mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer1);

    mmi_ucs2cat((PS8) Mem_Error, (PS8) "\n");

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Avl:= ");

    mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer);

    gui_itoa((S32) * pdisk_free_space, (UI_string_type) g_buffer1, 10);

    mmi_ucs2cat((PS8) Mem_Error, (PS8) g_buffer1);

    ShowCategory151Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (PU8) Mem_Error,
        NULL,
        guiBuffer);

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(0, 0);
    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}

#endif /* __MMI_CSB_BROWSER__ */ 

