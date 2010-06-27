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
 * JBrowserMMISettings.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for settigs feature in browser.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_JBROWSERMMISETTINGS_C
#define _MMI_JBROWSERMMISETTINGS_C

/*  Include: MMI header file */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "JBrowserResDef.h"
#include "JBrowserMMIProts.h"
#include "JBrowserMMITypes.h"
#include "JProfileHandlerTypes.h"
#include "JProfileHandlerProts.h"
#include "JPushInboxCommonAPIs.h"
#ifdef __MMI_JATAAYU_BRW_SECURITY_SETTING__
#include "CertManMMIGprots.h"
#endif 

static S8 *g_mmi_brw_show_images_string[MMI_BRW_SHOW_IMAGES_OPTION];
static S32 g_mmi_brw_show_image_state = 0;
static S8 *g_mmi_brw_show_history_as_string[MMI_BRW_SHOW_HISTORY_AS_OPTION];
static S32 g_mmi_brw_show_history_state = 0;
static S8 g_mmi_brw_timeout_value[(MMI_BRW_TIME_OUT_LEN + 1) * ENCODING_LENGTH];
static S8 *g_mmi_brw_show_images_selection[MMI_BRW_SHOW_IMAGES_SELECTION];
static S32 g_mmi_brw_show_images_selection_state = 0;

/* extern jdd_MemSetActiveModuleID(ETaskID taskId); */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_init
 * DESCRIPTION
 *  Set highlight handlers for settings menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_brw_setting_init for initialising hilite handlers");
    SetHiliteHandler(MENU_ID_BRW_SETTINGS_1, mmi_brw_setting_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SETTINGS_2, mmi_brw_setting_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SELECT_PROFILE, mmi_brw_setting_select_profile_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS, mmi_brw_setting_browser_option_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SERVICE_MESSAGES, mmi_brw_setting_service_messages_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_CLEAR_CACHE, mmi_brw_setting_clear_cache_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_CLEAR_COOKIES, mmi_brw_setting_clear_cookies_highlight_hdlr);
#ifdef __MMI_JATAAYU_BRW_SECURITY_SETTING__
    SetHiliteHandler(MENU_ID_BRW_SECURITY_SETTING, mmi_brw_setting_security_setting_highlight_hdlr);
#endif 
    /* hint handler */
    SetHintHandler(MENU_ID_BRW_SERVICE_MESSAGES, mmi_brw_setting_service_messages_hint_hdlr);

    /* Added by Sandeep to read the values from NVRAM */
    mmi_brw_read_setting_browser_option();
}

/* ------------------------Settings----------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Settings in WAP browser main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_entry_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_setting
 * DESCRIPTION
 *  Entry function for settings screen from main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 nstr_item_list[MAX_SUB_MENUS];
    U8 *nhint_list_p[MAX_SUB_MENUS];
    U16 nnum_of_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_UI);

    EntryNewScreen(SCR_ID_BRW_SETTINGS, NULL, mmi_brw_entry_setting, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_SETTINGS);

    nnum_of_item = GetNumOfChild(MENU_ID_BRW_SETTINGS_1);
    GetSequenceStringIds(MENU_ID_BRW_SETTINGS_1, nstr_item_list);
    SetParentHandler(MENU_ID_BRW_SETTINGS_1);
    ConstructHintsList(MENU_ID_BRW_SETTINGS_1, nhint_list_p);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_SETTINGS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nnum_of_item,
        nstr_item_list,
        (U16*) gIndexIconsImageList,
        nhint_list_p,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_setting_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Settings on rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_setting_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__
    SetLeftSoftkeyFunction(mmi_brw_entry_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 
    SetLeftSoftkeyFunction(mmi_brw_ren_page_entry_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_entry_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_JATAAYU_BRW_ADVANCED_RENDERED_PAGE_OPTIONS__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_entry_setting
 * DESCRIPTION
 *  Entry function for settings screen from rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 nstr_item_list[MAX_SUB_MENUS];
    U8 *nhint_list_p[MAX_SUB_MENUS];
    U16 nnum_of_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SETTINGS, NULL, mmi_brw_ren_page_entry_setting, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_SETTINGS);

    nnum_of_item = GetNumOfChild(MENU_ID_BRW_SETTINGS_2);
    GetSequenceStringIds(MENU_ID_BRW_SETTINGS_2, nstr_item_list);
    SetParentHandler(MENU_ID_BRW_SETTINGS_2);
    ConstructHintsList(MENU_ID_BRW_SETTINGS_2, nhint_list_p);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_SETTINGS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nnum_of_item,
        nstr_item_list,
        (U16*) gIndexIconsImageList,
        nhint_list_p,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/* -------------------------Profile------------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_select_profile_highlight_hdlr
 * DESCRIPTION
 *  Entry function for profile menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_select_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_show_profile_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_show_profile_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_show_profile_list
 * DESCRIPTION
 *  Entry function for select profile menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* PMT DARA  PROFILE HANDLER 020106 */
void mmi_brw_show_profile_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ph_pre_entry_show_profile_list_menu(PH_BROWSER_PROFILE);

}

/* -------------------------Browser Option-----------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_read_setting_browser_option
 * DESCRIPTION
 *  Function to read settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_read_setting_browser_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_BRW_TIME_OUT_VALUE, &(g_mmi_brw_cntx.timeout_value), DS_SHORT, &error);
    if (g_mmi_brw_cntx.timeout_value == 0xFFFF)
    {
        g_mmi_brw_cntx.timeout_value = WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT;
        WriteValue(NVRAM_BRW_TIME_OUT_VALUE, &(g_mmi_brw_cntx.timeout_value), DS_SHORT, &error);
    }

    ReadValue(NVRAM_BRW_SHOW_IMAGE_ON_OFF, &(g_mmi_brw_cntx.show_images), DS_BYTE, &error);
    if (g_mmi_brw_cntx.show_images == 0xFF)
    {
        g_mmi_brw_cntx.show_images = WAP_CUSTOM_CFG_DEFAULT_SHOW_IMAGES_ON;
        WriteValue(NVRAM_BRW_SHOW_IMAGE_ON_OFF, &(g_mmi_brw_cntx.show_images), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_SHOW_HISTORY_AS, &(g_mmi_brw_cntx.show_history_as_url), DS_BYTE, &error);
    if (g_mmi_brw_cntx.show_history_as_url == 0xFF)
    {
        g_mmi_brw_cntx.show_history_as_url = WAP_CUSTOM_CFG_DEFAULT_SHOW_HISTORY_AS_URL;
        WriteValue(NVRAM_BRW_SHOW_HISTORY_AS, &(g_mmi_brw_cntx.show_history_as_url), DS_BYTE, &error);
    }

    ReadValue(NVRAM_BRW_IMAGE_SELECTION_ON_OFF, &(g_mmi_brw_cntx.image_selection), DS_BYTE, &error);
    if (g_mmi_brw_cntx.image_selection == 0xFF)
    {
        g_mmi_brw_cntx.image_selection = WAP_CUSTOM_CFG_DEFAULT_IMAGE_SELECTION_ON;
        WriteValue(NVRAM_BRW_IMAGE_SELECTION_ON_OFF, &(g_mmi_brw_cntx.image_selection), DS_BYTE, &error);
    }
    ReadValue(NVRAM_BRW_SHOW_SERVICE_INBOX_MSG, &(g_mmi_brw_cntx.is_service_msg_setting), DS_BYTE, &error);
    if (g_mmi_brw_cntx.is_service_msg_setting == 0xFF)
    {
        g_mmi_brw_cntx.is_service_msg_setting = WAP_CUSTOM_CFG_DEFAULT_SHOW_SERVICE_INBOX_MSG;
        WriteValue(NVRAM_BRW_SHOW_SERVICE_INBOX_MSG, &(g_mmi_brw_cntx.is_service_msg_setting), DS_BYTE, &error);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Reading browser setting options!");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_write_setting_browser_option
 * DESCRIPTION
 *  Function to write settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_write_setting_browser_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_BRW_TIME_OUT_VALUE, &(g_mmi_brw_cntx.timeout_value), DS_SHORT, &error);

    WriteValue(NVRAM_BRW_SHOW_IMAGE_ON_OFF, &(g_mmi_brw_cntx.show_images), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_SHOW_HISTORY_AS, &(g_mmi_brw_cntx.show_history_as_url), DS_BYTE, &error);

    WriteValue(NVRAM_BRW_IMAGE_SELECTION_ON_OFF, &(g_mmi_brw_cntx.image_selection), DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_browser_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for browser settings option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_browser_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_setting_entry_browser_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_setting_entry_browser_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_entry_browser_option
 * DESCRIPTION
 *  Entry function for browser settings option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_entry_browser_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;
    U16 input_buffer_size;
    U16 browser_option_image_list[MMI_BRW_NUM_ITEMS_IN_BROWSER_OPTION] = {IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BROWSER_OPTIONS, mmi_brw_setting_exit_browser_option, NULL, NULL);

    InitializeCategory57Screen();

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_BRW_BROWSER_OPTIONS);
    if (gui_buffer_p == NULL)
    {
        mmi_brw_time_out_get_string_value(g_mmi_brw_timeout_value, g_mmi_brw_cntx.timeout_value);
        g_mmi_brw_show_image_state = g_mmi_brw_cntx.show_images;
        g_mmi_brw_show_history_state = g_mmi_brw_cntx.show_history_as_url;
        g_mmi_brw_show_images_selection_state = g_mmi_brw_cntx.image_selection;
    }
    else
    {
        DisableCategory57ScreenDone();
    }

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_BRW_BROWSER_OPTIONS, &input_buffer_size);

    SetParentHandler(0);

    mmi_brw_setting_fill_inline_struct_browser_option();

    RegisterHighlightHandler(mmi_brw_setting_highlight_browser_option_edit_inline_item);

    if (input_buffer_p != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_BRW_NUM_ITEMS_IN_BROWSER_OPTION, input_buffer_p);
    }

    ShowCategory57Screen(
        STR_ID_BRW_BROWSER_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_BRW_NUM_ITEMS_IN_BROWSER_OPTION,
        browser_option_image_list,
        wgui_inline_items,
        0,
        gui_buffer_p);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_exit_browser_option
 * DESCRIPTION
 *  Exit function for browser settings option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_exit_browser_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nhistory = 0;
    U16 input_buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_BRW_BROWSER_OPTIONS;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_setting_entry_browser_option;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nhistory);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "In mmi_brw_setting_exit_browser_option");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_fill_inline_struct_browser_option
 * DESCRIPTION
 *  Function to Fill valuses in inine edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_fill_inline_struct_browser_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_brw_show_images_string[0] = GetString(STR_GLOBAL_OFF);
    g_mmi_brw_show_images_string[1] = GetString(STR_GLOBAL_ON);

    g_mmi_brw_show_history_as_string[0] = GetString(STR_ID_BRW_SHOW_HISTORY_AS_OPTION_TITLE);
    g_mmi_brw_show_history_as_string[1] = GetString(STR_ID_BRW_SHOW_HISTORY_AS_OPTION_URL);

    g_mmi_brw_show_images_selection[0] = GetString(STR_GLOBAL_OFF);
    g_mmi_brw_show_images_selection[1] = GetString(STR_GLOBAL_ON);

    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_TIMEOUT_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(&(wgui_inline_items[BRW_INLINE_TIMEOUT_CAPTION]), (U8*) GetString(STR_ID_BRW_TIMEOUT));

    /* Inline Edit */
    SetInlineItemActivation(&(wgui_inline_items[BRW_INLINE_TIMEOUT_EDIT]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &(wgui_inline_items[BRW_INLINE_TIMEOUT_EDIT]),
        (U8*) g_mmi_brw_timeout_value,
        MMI_BRW_TIME_OUT_LEN + 1,
        INPUT_TYPE_NUMERIC);
    LeftJustifyInlineItem(&(wgui_inline_items[BRW_INLINE_TIMEOUT_EDIT]));
    DisableInlineItemHighlight(&wgui_inline_items[BRW_INLINE_TIMEOUT_EDIT]);

    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_SHOW_IMAGES_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_INLINE_SHOW_IMAGES_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SHOW_IMAGES));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_SHOW_IMAGES_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_INLINE_SHOW_IMAGES_SELECT]),
        (S32) MMI_BRW_SHOW_IMAGES_OPTION,
        (U8 **) g_mmi_brw_show_images_string,
        &g_mmi_brw_show_image_state);

    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_SHOW_HISTORY_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_INLINE_SHOW_HISTORY_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SHOW_ADDRESS_LIST_AS));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_SHOW_HISTORY_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_INLINE_SHOW_HISTORY_SELECT]),
        (S32) MMI_BRW_SHOW_HISTORY_AS_OPTION,
        (U8 **) g_mmi_brw_show_history_as_string,
        &g_mmi_brw_show_history_state);

    /* Caption for image selection */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_IMAGES_SELECTION_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_INLINE_IMAGES_SELECTION_CAPTION]),
        (U8*) GetString(STR_ID_BRW_IMAGE_SELECTION));

    /* Inline Select for image selection */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_INLINE_IMAGES_SELECTION_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_INLINE_IMAGES_SELECTION_SELECT]),
        (S32) MMI_BRW_SHOW_IMAGES_OPTION,
        (U8 **) g_mmi_brw_show_images_selection,
        &g_mmi_brw_show_images_selection_state);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_highlight_browser_option_edit_inline_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_highlight_browser_option_edit_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_brw_setting_browser_option_confirm_save, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_browser_option_confirm_save
 * DESCRIPTION
 *  Function to confirm save settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_browser_option_confirm_save(void)
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
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_setting_browser_option_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_setting_browser_option_cancel_save, KEY_EVENT_UP);  /* added by tk */
}

/* added by tk */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_browser_option_cancel_save
 * DESCRIPTION
 *  Function to cacel confirm save settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_browser_option_cancel_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_BRW_SETTINGS);
}

/* tk end */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_browser_option_save
 * DESCRIPTION
 *  Function to save the settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_browser_option_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 timeout[MMI_BRW_TIME_OUT_LEN + 1];
    U16 timeoutvalue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(timeout, (S8*) g_mmi_brw_timeout_value);

    timeoutvalue = atoi(timeout);
    if ((timeoutvalue < 30) || (timeoutvalue > 300))
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_INVALID_TIMEOUT), IMG_GLOBAL_ERROR, 0, MMI_BRW_POPUP_TIME, ERROR_TONE);
        return;
    }
    g_mmi_brw_cntx.timeout_value = timeoutvalue;
    g_mmi_brw_cntx.show_images = g_mmi_brw_show_image_state;
    g_mmi_brw_cntx.show_history_as_url = g_mmi_brw_show_history_state;
    g_mmi_brw_cntx.image_selection = g_mmi_brw_show_images_selection_state;

    mmi_brw_write_setting_browser_option();

    /* Added by sandeep to set the timeout value */
    mmi_brw_set_connection_active_flag(MMI_FALSE);

    /* Added by Sandeep to set if images should be shown on the rendered page or not */
    jdi_BrowserGraphicsEnable(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cntx.show_images);

    jdi_BrowserSetImageAsSelectable(g_mmi_brw_pbrowser_ctxt, g_mmi_brw_cntx.image_selection);

    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_BRW_SETTINGS);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Saving browser setting options");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_time_out_get_string_value
 * DESCRIPTION
 *  Function to make the string from a value
 * PARAMETERS
 *  string_val      [?]         [?]         [?]         [?]
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_time_out_get_string_value(S8 *string_val, U16 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 strval[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strval, "%d", value);
    mmi_asc_to_ucs2(string_val, strval);
}

/* -------------------------Service Messages---------------------------// */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_service_messages_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Service Messages menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_service_messages_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_brw_cntx.is_service_msg_setting)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    SetLeftSoftkeyFunction(mmi_brw_setting_service_messages_toggle, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_service_messages_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_service_messages_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    if (g_mmi_brw_cntx.is_service_msg_setting)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_OFF));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_service_messages_toggle
 * DESCRIPTION
 *  Toggle state of service messages.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_service_messages_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (g_mmi_brw_cntx.is_service_msg_setting)
    {
        /* service_message_status = 0; */
        g_mmi_brw_cntx.is_service_msg_setting = E_FALSE;
        mmi_brw_enable_push_Message(0);
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        g_mmi_brw_cntx.is_service_msg_setting = E_TRUE;
        mmi_brw_enable_push_Message(1);
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    WriteValue(NVRAM_BRW_SHOW_SERVICE_INBOX_MSG, &(g_mmi_brw_cntx.is_service_msg_setting), DS_BYTE, &error);
    RedrawCategoryFunction();
    mmi_brw_setting_service_messages_highlight_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_clear_cache_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Clear Cache menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_clear_cache_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_setting_clear_cache_confirm, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_brw_setting_clear_cache_confirm, KEY_RIGHT_ARROW,  KEY_EVENT_DOWN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_clear_cache_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_clear_cache_confirm(void)
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
        get_string(STR_ID_BRW_DELETE_CACHE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_setting_clear_cache, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_clear_cache
 * DESCRIPTION
 *  Deletes the Browser Setting Cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_clear_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdi_BrowserClearCache(g_mmi_brw_pbrowser_ctxt);
    if (ret == JC_OK)
    {
        /* jdi_BrowserCacheSave(g_mmi_brw_pbrowser_ctxt); */
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, MMI_BRW_POPUP_TIME, SUCCESS_TONE);

        /* Clear all the Authorization Information along with Clear Cache */
        jdi_BrowserClearAuthInfo(g_mmi_brw_pbrowser_ctxt, E_BR_CLEAR_ALL);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_clear_cookies_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Clear Cookies menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_clear_cookies_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_setting_clear_cookies_confirm, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_brw_setting_clear_cookies_confirm, KEY_RIGHT_ARROW,KEY_EVENT_DOWN); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_clear_cookies_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cookies.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_clear_cookies_confirm(void)
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
        get_string(STR_ID_BRW_DELETE_COOKIES),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_setting_clear_cookies, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_clear_cookies
 * DESCRIPTION
 *  Deletes the Browser Setting Cookies.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_clear_cookies(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = jdi_BrowserClearCookie(g_mmi_brw_pbrowser_ctxt);

    if (ret == JC_OK)
    {
        jdi_BrowserCookieSave(g_mmi_brw_pbrowser_ctxt);

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Browser setting cookies deleted");
}

#ifdef __MMI_JATAAYU_BRW_SECURITY_SETTING__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_setting_security_setting_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Security Setting menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_setting_security_setting_highlight_hdlr(void)  /* Ramneek */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_invoke_security_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_invoke_security_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_JATAAYU_BRW_SECURITY_SETTING__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_set_timeout_value
 * DESCRIPTION
 *  External function to set the timeout value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_set_timeout_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wap_profile_content_struct *activated_wap_profile;
    ST_BROWSER_SET_OPTION brw_set_timeout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activated_wap_profile = mmi_ph_get_activated_wap_profile();

    if (activated_wap_profile->conn_type == PH_CONN_TYPE_HTTP)
    {
        brw_set_timeout.iMaxConnectRetries = 0;
        brw_set_timeout.iTimeOutVal = g_mmi_brw_cntx.timeout_value;

    }
    else
    {
        brw_set_timeout.iMaxConnectRetries = MMI_BRW_MAX_WSP_RETRIES;
        brw_set_timeout.iTimeOutVal = (g_mmi_brw_cntx.timeout_value) / (MMI_BRW_MAX_WSP_RETRIES + 1);
    }

    jdi_BrowserSetOption(g_mmi_brw_pbrowser_ctxt, &brw_set_timeout);
}

#ifdef __MMI_JATAAYU_BRW_SECURITY_SETTING__


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_invoke_security_setting
 * DESCRIPTION
 *  Function to invoke the security setting screen of Certman.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_invoke_security_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_certman_launch_certificates_ind(MOD_WAP, MMI_CERTMAN_OPEN, 0);
    SetProtocolEventHandler(mmi_brw_security_setting_rsp, MSG_ID_MMI_CERTMAN_LAUNCH_CERT_RSP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_setting_rsp
 * DESCRIPTION
 *  Function to handle response of security setting.
 * PARAMETERS
 *  info_p      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_setting_rsp(void *info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Handle the response. */
}
#endif /* __MMI_JATAAYU_BRW_SECURITY_SETTING__ */ 

#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 

#endif /* _MMI_JBROWSERMMISETTINGS_C */ 

