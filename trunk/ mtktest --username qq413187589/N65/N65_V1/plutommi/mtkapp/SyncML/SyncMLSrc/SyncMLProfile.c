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
 *    SyncMLProfile.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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

#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "MessagesResourceData.h" /* Profile 1 */
#include "ServiceDefs.h"          /* SERVICES_DATA_CONNECT_STRING_ID */
#include "app_url.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "DataAccountGProt.h"

#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#endif 

/*
 * Global Function
 */
extern void PreparedIPAddressString(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);


/*
 * Local Variable
 */
static syncml_profile_struct g_syncml_profile;

static syncml_profile_edit_struct g_syncml_profile_edit_context;  /* for inline editor */
static syncml_data_account_edit_struct g_syncml_data_account_edit_context; /* for inline editor */
static void mmi_syncml_profile_ip_conv(PU8 string_val, U8 digit_val);

/*
 * Global Variable
 */
extern syncml_context_struct g_syncml_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_profile_init
 * DESCRIPTION
 *  Initialize highlight and hint for SyncML profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (defined(__MMI_DUAL_SIM__) || defined(__CBM_ALWAYS_ASK_FEATURE__))
    g_syncml_context.app_id = always_ask_register_app_id(STR_ID_SYNC_MENU);
#endif 
    
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_ACTIVATE, mmi_syncml_highlight_profile_activate);
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT, mmi_syncml_highlight_profile_edit);
#ifndef __MMI_OP01_SYNCML_SETTING__
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_NAME, mmi_syncml_highlight_profile_name);
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_SERVER, mmi_syncml_highlight_profile_server);
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_CONTACT, mmi_syncml_highlight_profile_contact);
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_CALENDAR, mmi_syncml_highlight_profile_calendar); 
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_CONNECTION, mmi_syncml_highlight_profile_connection);
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_NAME_DONE, mmi_syncml_highlight_profile_edit_name_done);
    SetHiliteHandler(MENU_ID_SYNCML_PROFILE_EDIT_NAME_INPUT, mmi_syncml_highlight_profile_edit_name_input);
#endif /* __MMI_OP01_SYNCML_SETTING__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_sync_profile
 * DESCRIPTION
 *  "Sync Profile" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_sync_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_syncml_entry_sync_profile, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_sync_profile, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_activate
 * DESCRIPTION
 *  "Activate" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_activate, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_syncml_entry_profile_activate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_data_account
 * DESCRIPTION
 *  Retrieve the data accounts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_get_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
    /* get data accounts before enter 'Edit' options because of hint string updating */
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else 
    DataAccountReadyCheck(mmi_syncml_entry_profile_edit);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_edit
 * DESCRIPTION
 *  "Edit" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_syncml_context.selected_profile < MAX_SYNCML_SV_PROFILES)
    {
    /*
     *  SetLeftSoftkeyFunction(mmi_syncml_entry_profile_edit, KEY_EVENT_UP);
     *  SetKeyHandler(mmi_syncml_entry_profile_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
     */
        SetLeftSoftkeyFunction(mmi_syncml_get_data_account, KEY_EVENT_UP);
        SetKeyHandler(mmi_syncml_get_data_account, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_syncml_entry_pc_profile_edit, KEY_EVENT_UP);
        SetKeyHandler(mmi_syncml_entry_pc_profile_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_name
 * DESCRIPTION
 *  "Profile Name" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_name, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_profile_name, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_server
 * DESCRIPTION
 *  "Server Settings" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_server, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_profile_server, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_contact
 * DESCRIPTION
 *  "Contact Settings" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_contact, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_profile_contact, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_calendar
 * DESCRIPTION
 *  "Calendar Settings" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_calendar, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_profile_calendar, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_connection
 * DESCRIPTION
 *  "Connection Settings" menu highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_connection, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_profile_connection, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
/*
 *  SetLeftSoftkeyFunction(mmi_syncml_get_data_account, KEY_EVENT_UP);
 *  SetKeyHandler(mmi_syncml_get_data_account, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_edit_name_done
 * DESCRIPTION
 *  "Done" menu highlight handler of profile name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_edit_name_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucs2cmp((S8*) g_syncml_profile.profile_name, (S8*) g_syncml_profile_edit_context.addr_buffer) == 0) 
    {
        SetLeftSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
        SetKeyHandler(mmi_syncml_abort_profile_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_syncml_entry_profile_edit_name_done, KEY_EVENT_UP);
        SetKeyHandler(mmi_syncml_entry_profile_edit_name_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_highlight_profile_edit_name_input
 * DESCRIPTION
 *  "Input Method" menu highlight handler of profile name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_highlight_profile_edit_name_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_profile
 * DESCRIPTION
 *  "Sync Profile" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 i;
    U16 icon_list[MAX_SYNCML_PROFILES];
    U8 *SyncMLItem[MAX_SYNCML_PROFILES];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_SELECTION, NULL, mmi_syncml_entry_sync_profile, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_SELECTION);

    RegisterHighlightHandler(mmi_syncml_profile_highlight_handler);

    memset(icon_list, 0, sizeof(icon_list));

    if (g_syncml_context.active_profile != 0)
    {
        /* active profile from 1 to max */
        icon_list[g_syncml_context.active_profile - 1] = IMG_VICON;
    }

    for (i = 0; i < MAX_SYNCML_PROFILES; i++)
    {
        SyncMLItem[i] = g_syncml_context.profile_name_display[i];
    }

    ShowCategory73Screen(
        STR_ID_SYNC_PROFILE,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SYNCML_PROFILES,
        (U8 **) SyncMLItem,
        (U16*) icon_list,
        (U16*) gIndexIconsImageList,
        g_syncml_context.selected_profile,
        guiBuffer,
        ICON_ICON_TEXT);

    SetLeftSoftkeyFunction(mmi_syncml_entry_profiles_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_syncml_entry_profiles_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_profile_highlight_handler
 * DESCRIPTION
 *  Highlight handler of "Profile" selctions
 * PARAMETERS
 *  index       [IN]            highlight index
 * RETURNS
 *  U16  total amount of todolist
 *****************************************************************************/
void mmi_syncml_profile_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_context.selected_profile = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profiles_options
 * DESCRIPTION
 *  "Options" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profiles_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 SyncMLItem[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_OPTION, NULL, mmi_syncml_entry_profiles_options, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_OPTION);
    nNumofItem = GetNumOfChild(MENU_ID_SYNCML_PROFILE_OPTIONS);
    GetSequenceStringIds(MENU_ID_SYNCML_PROFILE_OPTIONS, SyncMLItem);
    SetParentHandler(MENU_ID_SYNCML_PROFILE_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
#endif
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        SyncMLItem,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* read the selected profile for edit */
    mmi_syncml_read_profile_from_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_activate
 * DESCRIPTION
 *  "Activate" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0 /* not check applications to sync before activate */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
    if (mmi_syncml_validate_profile_before_activate())
    {
        g_syncml_context.active_profile = g_syncml_context.selected_profile + 1;
        mmi_syncml_update_settings_to_nvram();

        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_ACTIVATED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_INCOMPLETE_PROFILE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_construct_profile_hint
 * DESCRIPTION
 *  "Activate" menu entry function
 * PARAMETERS
 *  hintCount       [IN]      The hint count
 *  hintArray       [OUT]     The hint pointer array to the strings
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_construct_profile_hint(U16 hintCount, U8 **hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < hintCount; i++)
    {
        switch (i)
        {
            case 0:
                hintArray[i] = g_syncml_profile.profile_name;
                break;

            case 1:
                mmi_asc_to_ucs2(
                    (S8*) g_syncml_profile_edit_context.server_addr_hint,
                    (S8*) g_syncml_profile.server_address);
                hintArray[i] = g_syncml_profile_edit_context.server_addr_hint;
                break;

            case 2:
                mmi_asc_to_ucs2(
                    (S8*) g_syncml_profile_edit_context.contact_addr_hint,
                    (S8*) g_syncml_profile.contact_address);
                hintArray[i] = g_syncml_profile_edit_context.contact_addr_hint;
                break;

            case 3:
                mmi_asc_to_ucs2(
                    (S8*) g_syncml_profile_edit_context.calendar_addr_hint,
                    (S8*) g_syncml_profile.calendar_address);
                hintArray[i] = g_syncml_profile_edit_context.calendar_addr_hint;
                break;

            case 4:
                mmi_dtcnt_get_account_name(
                    g_syncml_profile.net_id,
                    (PS8) g_syncml_profile_edit_context.data_account_hint,
                    MAX_DATA_ACCOUNT_NAME_LEN);
                hintArray[i] = g_syncml_profile_edit_context.data_account_hint;
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_edit
 * DESCRIPTION
 *  "Edit" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 SyncMLItem[MAX_SUB_MENUS];
    U16 SyncMLIcon[MAX_SUB_MENUS];
    U8 *SyncMLHint[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_EDIT, NULL, mmi_syncml_entry_profile_edit, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_EDIT);
    nNumofItem = GetNumOfChild(MENU_ID_SYNCML_PROFILE_EDIT);
    GetSequenceStringIds(MENU_ID_SYNCML_PROFILE_EDIT, SyncMLItem);
    GetSequenceImageIds(MENU_ID_SYNCML_PROFILE_EDIT, SyncMLIcon);
    SetParentHandler(MENU_ID_SYNCML_PROFILE_EDIT);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* reset the edit buffer */
    memset(&g_syncml_profile_edit_context, 0, sizeof(syncml_profile_edit_struct));
    memset(&g_syncml_data_account_edit_context, 0, sizeof(syncml_data_account_edit_struct));

	/* prepare hint data without pre-registered hint handlers */
    mmi_syncml_construct_profile_hint(nNumofItem, SyncMLHint);

    ShowCategory52Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        SyncMLItem,
        SyncMLIcon,
        SyncMLHint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (g_syncml_context.profile_deactivated)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_PROFILE_DEACTIVATED),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        g_syncml_context.profile_deactivated = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_name
 * DESCRIPTION
 *  "Profile Name" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_NAME, NULL, mmi_syncml_entry_profile_name, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_NAME);

    if (guiBuffer == NULL)
    {
        /* prepare default strings to display if this screen is first entered */
        mmi_ucs2ncpy(
            (S8*) g_syncml_profile_edit_context.addr_buffer,
            (S8*) g_syncml_profile.profile_name,
            MAX_SYNCML_PROFILE_NAME);
    }

    ShowCategory5Screen_ext(
        STR_ID_SYNC_PROFILE_NAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        g_syncml_profile_edit_context.addr_buffer,
        MAX_SYNCML_PROFILE_NAME, // + 1,
        guiBuffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_name_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    RegisterInputMethodScreenCloseFunction(mmi_syncml_entry_profile_edit_name_close_input_method);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_name_option
 * DESCRIPTION
 *  "Option" menu entry function of profile name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_name_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 SyncMLItem[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_NAME_OPTION, NULL, mmi_syncml_entry_profile_name_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_NAME_OPTION);
    numItems = GetNumOfChild(MENU_ID_SYNCML_PROFILE_EDIT_NAME_OPTION);
    GetSequenceStringIds(MENU_ID_SYNCML_PROFILE_EDIT_NAME_OPTION, SyncMLItem);
    SetParentHandler(MENU_ID_SYNCML_PROFILE_EDIT_NAME_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        SyncMLItem,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_profile_server_inline_editor
 * DESCRIPTION
 *  "Server Settings" menu inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_profile_server_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_SYNC_SERVER_ADDRESS));

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_SYNC_SERVER_ADDRESS,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_SERVER,
        (U8*) g_syncml_profile_edit_context.addr_buffer,
        MAX_SYNCML_SERVER_ADDR_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_GLOBAL_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_GLOBAL_USERNAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_USERNAME,
        (U8*) g_syncml_profile_edit_context.name_buffer,
        MAX_SYNCML_USERNAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_GLOBAL_PASSWORD));

    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_GLOBAL_PASSWORD,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_PASSWORD,
        (U8*) g_syncml_profile_edit_context.pswd_buffer,
        MAX_SYNCML_PASSWORD,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_syncml_set_profile_custom_function);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_server_save
 * DESCRIPTION
 *  "Server Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_server_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_server[MAX_SYNCML_SERVER_ADDR_LEN];
    U8 *fs_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    /* last anchor and change log should be reset if the server is changed */
    mmi_ucs2_to_asc((S8*) temp_server, (S8*) g_syncml_profile_edit_context.addr_buffer);
    if (strcmp((S8*) g_syncml_profile.server_address, (S8*) temp_server) != 0)
    {
        g_syncml_context.last_phb_anchor[g_syncml_context.selected_profile] = 0;
        g_syncml_context.last_tdl_anchor[g_syncml_context.selected_profile] = 0;
        mmi_syncml_update_settings_to_nvram();

        fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((S8*) fs_path, (S8*) SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_syncml_context.selected_profile + 1;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);

        fs_path = OslMalloc(sizeof(SYNCML_TDL_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((S8*) fs_path, (S8*) SYNCML_TDL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TDL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + g_syncml_context.selected_profile + 1;
        FS_Delete((U16*) fs_path);
        OslMfree(fs_path);
    }

    memset(g_syncml_profile.server_address, 0, MAX_SYNCML_SERVER_ADDR_LEN);
    memset(g_syncml_profile.server_username, 0, MAX_SYNCML_USERNAME);
    memset(g_syncml_profile.server_password, 0, MAX_SYNCML_PASSWORD);

    /* save to nvram */
    if (mmi_ucs2strlen((S8*) g_syncml_profile_edit_context.addr_buffer) == 0
    ||  mmi_ucs2cmp((S8*) g_syncml_profile_edit_context.addr_buffer, (S8*) L"http://") == 0)
    {
        strcpy((PS8) g_syncml_profile.server_address, "http://");
        g_syncml_profile.profile_validation &= ~0x02;
        if (g_syncml_context.selected_profile + 1 == g_syncml_context.active_profile)
        {
            g_syncml_context.active_profile = 0; /* deactivate the profile if the server address is empty */
            g_syncml_context.profile_deactivated = 1;
            mmi_syncml_update_settings_to_nvram();
        }
    }
    else
    {
        mmi_ucs2_to_asc((S8*) g_syncml_profile.server_address, (S8*) g_syncml_profile_edit_context.addr_buffer);
        g_syncml_profile.profile_validation |= 0x02;
    }
    mmi_ucs2_to_asc((S8*) g_syncml_profile.server_username, (S8*) g_syncml_profile_edit_context.name_buffer);
    mmi_ucs2_to_asc((S8*) g_syncml_profile.server_password, (S8*) g_syncml_profile_edit_context.pswd_buffer);
    mmi_syncml_update_profile_to_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_SERVER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_server_done
 * DESCRIPTION
 *  "Server Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_server_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_server[MAX_SYNCML_SERVER_ADDR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) temp_server, (S8*) g_syncml_profile_edit_context.addr_buffer);
    if (applib_url_is_valid((const char *) temp_server) != 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_INVALID_INPUT),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_edit_profile_server_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_profile_server
 * DESCRIPTION
 *  "Server Settings" menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_exit_profile_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_SYNC_PROFILE_SERVER;
    Scr.entryFuncPtr = mmi_syncml_entry_profile_server;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_server
 * DESCRIPTION
 *  "Server Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_server(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 IconList[] = {IMG_ID_SYNC_SERVER, 0, IMG_ID_SYNC_USERNAME, 0, IMG_ID_SYNC_PASSWORD, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_SERVER, mmi_syncml_exit_profile_server, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_SERVER);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SYNC_PROFILE_SERVER, &inputBufferSize);
    SetParentHandler(0);

    if (inputBuffer == NULL)
    {
        /* prepare default strings to display if this screen is first entered */
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.addr_buffer,
            (S8*) g_syncml_profile.server_address,
            MAX_SYNCML_SERVER_ADDR_LEN);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.name_buffer,
            (S8*) g_syncml_profile.server_username,
            MAX_SYNCML_USERNAME);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.pswd_buffer,
            (S8*) g_syncml_profile.server_password,
            MAX_SYNCML_PASSWORD);
    }

    mmi_syncml_set_profile_server_inline_editor();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 6, inputBuffer);
    }

    ClearHighlightHandler();

    ShowCategory57Screen(
        STR_ID_SYNC_PROFILE_SERVER,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_syncml_edit_profile_server_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_profile_contact_inline_editor
 * DESCRIPTION
 *  "Contact Settings" menu inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_profile_contact_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_SYNC_CONTACT_ADDRESS));

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_SYNC_CONTACT_ADDRESS,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_CONTACT,
        (U8*) g_syncml_profile_edit_context.addr_buffer,
        MAX_SYNCML_DATABASE_ADDR_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_GLOBAL_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_GLOBAL_USERNAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_USERNAME,
        (U8*) g_syncml_profile_edit_context.name_buffer,
        MAX_SYNCML_USERNAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_GLOBAL_PASSWORD));

    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_GLOBAL_PASSWORD,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_PASSWORD,
        (U8*) g_syncml_profile_edit_context.pswd_buffer,
        MAX_SYNCML_PASSWORD,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_syncml_set_profile_custom_function);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_contact_save
 * DESCRIPTION
 *  "Contact Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_contact_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    memset(g_syncml_profile.contact_address, 0, MAX_SYNCML_DATABASE_ADDR_LEN);
    memset(g_syncml_profile.contact_username, 0, MAX_SYNCML_USERNAME);
    memset(g_syncml_profile.contact_password, 0, MAX_SYNCML_PASSWORD);

    /* save to nvram */
    if (mmi_ucs2strlen((S8*) g_syncml_profile_edit_context.addr_buffer) == 0
    ||  mmi_ucs2cmp((S8*) g_syncml_profile_edit_context.addr_buffer, (S8*) L"./") == 0)
    {
        strcpy((PS8) g_syncml_profile.contact_address, "./");
        g_syncml_profile.profile_validation &= ~0x04;
        if ((g_syncml_context.active_profile != 0) && (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK))
        {
            g_syncml_context.active_profile = 0;
            g_syncml_context.profile_deactivated = 1;
            mmi_syncml_update_settings_to_nvram();
        }
    }
    else
    {
        mmi_ucs2_to_asc((S8*) g_syncml_profile.contact_address, (S8*) g_syncml_profile_edit_context.addr_buffer);
        g_syncml_profile.profile_validation |= 0x04;
    }
    mmi_ucs2_to_asc((S8*) g_syncml_profile.contact_username, (S8*) g_syncml_profile_edit_context.name_buffer);
    mmi_ucs2_to_asc((S8*) g_syncml_profile.contact_password, (S8*) g_syncml_profile_edit_context.pswd_buffer);
    mmi_syncml_update_profile_to_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_CONTACT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_contact_done
 * DESCRIPTION
 *  "Contact Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_contact_done(void)
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
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_edit_profile_contact_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_profile_contact
 * DESCRIPTION
 *  "Contact Settings" menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_exit_profile_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_SYNC_PROFILE_CONTACT;
    Scr.entryFuncPtr = mmi_syncml_entry_profile_contact;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_contact
 * DESCRIPTION
 *  "Contact Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 IconList[] = {IMG_ID_SYNC_CONTACT, 0, IMG_ID_SYNC_USERNAME, 0, IMG_ID_SYNC_PASSWORD, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_CONTACT, mmi_syncml_exit_profile_contact, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_CONTACT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SYNC_PROFILE_CONTACT, &inputBufferSize);
    SetParentHandler(0);

    if (inputBuffer == NULL)
    {
        /* prepare default strings to display if this screen is first entered */
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.addr_buffer,
            (S8*) g_syncml_profile.contact_address,
            MAX_SYNCML_DATABASE_ADDR_LEN);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.name_buffer,
            (S8*) g_syncml_profile.contact_username,
            MAX_SYNCML_USERNAME);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.pswd_buffer,
            (S8*) g_syncml_profile.contact_password,
            MAX_SYNCML_PASSWORD);
    }

    mmi_syncml_set_profile_contact_inline_editor();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 6, inputBuffer);
    }

    ClearHighlightHandler();

    ShowCategory57Screen(
        STR_ID_SYNC_PROFILE_CONTACT,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_syncml_edit_profile_contact_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_profile_calendar_inline_editor
 * DESCRIPTION
 *  "Calendar Settings" menu inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_profile_calendar_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_SYNC_CALENDAR_ADDRESS));

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_SYNC_CALENDAR_ADDRESS,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_CALENDAR,
        (U8*) g_syncml_profile_edit_context.addr_buffer,
        MAX_SYNCML_DATABASE_ADDR_LEN,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_GLOBAL_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_GLOBAL_USERNAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_USERNAME,
        (U8*) g_syncml_profile_edit_context.name_buffer,
        MAX_SYNCML_USERNAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_GLOBAL_PASSWORD));

    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_GLOBAL_PASSWORD,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_PASSWORD,
        (U8*) g_syncml_profile_edit_context.pswd_buffer,
        MAX_SYNCML_PASSWORD,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_syncml_set_profile_custom_function);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_calendar_save
 * DESCRIPTION
 *  "Calendar Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_calendar_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    memset(g_syncml_profile.calendar_address, 0, MAX_SYNCML_DATABASE_ADDR_LEN);
    memset(g_syncml_profile.calendar_username, 0, MAX_SYNCML_USERNAME);
    memset(g_syncml_profile.calendar_password, 0, MAX_SYNCML_PASSWORD);

    /* save to nvram */
    if (mmi_ucs2strlen((S8*) g_syncml_profile_edit_context.addr_buffer) == 0
    ||  mmi_ucs2cmp((S8*) g_syncml_profile_edit_context.addr_buffer, (S8*) L"./") == 0)
    {
        strcpy((PS8) g_syncml_profile.calendar_address, "./");
        g_syncml_profile.profile_validation &= ~0x08;
        if ((g_syncml_context.active_profile != 0) && (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST))
        {
            g_syncml_context.active_profile = 0;
            g_syncml_context.profile_deactivated = 1;
            mmi_syncml_update_settings_to_nvram();
        }
    }
    else
    {
        mmi_ucs2_to_asc((S8*) g_syncml_profile.calendar_address, (S8*) g_syncml_profile_edit_context.addr_buffer);
        g_syncml_profile.profile_validation |= 0x08;
    }
    mmi_ucs2_to_asc((S8*) g_syncml_profile.calendar_username, (S8*) g_syncml_profile_edit_context.name_buffer);
    mmi_ucs2_to_asc((S8*) g_syncml_profile.calendar_password, (S8*) g_syncml_profile_edit_context.pswd_buffer);
    mmi_syncml_update_profile_to_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_CALENDAR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_calendar_done
 * DESCRIPTION
 *  "Calendar Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_calendar_done(void)
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
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_edit_profile_calendar_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_profile_calendar
 * DESCRIPTION
 *  "Calendar Settings" menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_exit_profile_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_SYNC_PROFILE_CALENDAR;
    Scr.entryFuncPtr = mmi_syncml_entry_profile_calendar;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_calendar
 * DESCRIPTION
 *  "Calendar Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 IconList[] = {IMG_ID_SYNC_CALENDAR, 0, IMG_ID_SYNC_USERNAME, 0, IMG_ID_SYNC_PASSWORD, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_CALENDAR, mmi_syncml_exit_profile_calendar, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_CALENDAR);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SYNC_PROFILE_CALENDAR, &inputBufferSize);
    SetParentHandler(0);

    if (inputBuffer == NULL)
    {
        /* prepare default strings to display if this screen is first entered */
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.addr_buffer,
            (S8*) g_syncml_profile.calendar_address,
            MAX_SYNCML_DATABASE_ADDR_LEN);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.name_buffer,
            (S8*) g_syncml_profile.calendar_username,
            MAX_SYNCML_USERNAME);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.pswd_buffer,
            (S8*) g_syncml_profile.calendar_password,
            MAX_SYNCML_PASSWORD);
    }

    mmi_syncml_set_profile_calendar_inline_editor();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 6, inputBuffer);
    }

    ClearHighlightHandler();

    ShowCategory57Screen(
        STR_ID_SYNC_PROFILE_CALENDAR,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_syncml_edit_profile_calendar_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_validate_profile_before_activate
 * DESCRIPTION
 *  Validation check before activate the selected profile
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_syncml_validate_profile_before_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (g_syncml_profile.profile_validation == 0x1F) /* five profile settings are validated */
    if (g_syncml_profile.profile_validation & 0x02)
    {
        /* server is edited and contact or calendar is edited */
        switch (g_syncml_context.applications_to_sync)
        {
            case SYNCML_DB_PHONEBOOK:
                if (g_syncml_profile.profile_validation & 0x04)
                {
                    return 1;
                }
                break;

            case SYNCML_DB_TODOLIST:
                if (g_syncml_profile.profile_validation & 0x08)
                {
                    return 1;
                }
                break;

            case (SYNCML_DB_PHONEBOOK + SYNCML_DB_TODOLIST):
                if (g_syncml_profile.profile_validation & 0x04 && g_syncml_profile.profile_validation & 0x08)
                {
                    return 1;
                }
                break;

            default:
                return 1; /* not check applications to sync before activate */
                break;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_edit_name_close_input_method
 * DESCRIPTION
 *  Close input method screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_edit_name_close_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_NAME_OPTION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_edit_name_save
 * DESCRIPTION
 *  "Profile Name" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_edit_name_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_profile.profile_validation |= 0x01;

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    /* save to nvram */
    mmi_ucs2cpy((S8*) g_syncml_profile.profile_name, (S8*) g_syncml_profile_edit_context.addr_buffer);
    mmi_syncml_update_profile_to_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);

    /* update profile name */
    if (mmi_ucs2strlen((S8*) g_syncml_profile.profile_name) == 0)
    {
        /* update display name */
        mmi_ucs2cpy((S8*) g_syncml_context.profile_name_display[g_syncml_context.selected_profile], GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + g_syncml_context.selected_profile)));
        /* update hint */
        mmi_ucs2cpy((S8*) g_syncml_profile.profile_name, GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + g_syncml_context.selected_profile)));
    }
    else
    {
        mmi_ucs2cpy((S8*) g_syncml_context.profile_name_display[g_syncml_context.selected_profile], (S8*) g_syncml_profile.profile_name);
    }

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_NAME_OPTION);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_NAME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_edit_name_done
 * DESCRIPTION
 *  "Profile Name" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_edit_name_done(void)
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
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_syncml_entry_profile_edit_name_save, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_gprs_dt_callback
 * DESCRIPTION
 *  Callback of data account selection to get the corresponding string
 * PARAMETERS
 *  index       [IN]            highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_gprs_dt_callback(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_get_account_name(
        index,
        (S8*) g_syncml_data_account_edit_context.data_account,
        MAX_DATA_ACCOUNT_NAME_LEN);

#if (defined(__MMI_DUAL_SIM__) || defined(__CBM_ALWAYS_ASK_FEATURE__))
    g_syncml_data_account_edit_context.net_id = 
        always_ask_encode_app_id_data_account_id(index, g_syncml_context.app_id);
#else 
    g_syncml_data_account_edit_context.net_id = index;
#endif 

    DeleteUptoScrID(SCR_ID_SYNC_PROFILE_CONNECTION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_list_data_account
 * DESCRIPTION
 *  List function of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_list_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_DUAL_SIM__) || defined(__CBM_ALWAYS_ASK_FEATURE__))

    mmi_dtcnt_select_account_option(
        mmi_syncml_gprs_dt_callback,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        MENU_ID_SYNCML_MAIN,
#endif
        DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI,
        DTCNT_SELECT_NO_SIM,
        DTCNT_SELECT_NO_ALWAYS_ASK);

#else /* __MMI_DUAL_SIM__ */
    
    mmi_dtcnt_select_account(
        mmi_syncml_gprs_dt_callback,
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
        MENU_ID_SYNCML_MAIN,
#endif
        DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI);

#endif /* __MMI_DUAL_SIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_prof_ip_addr_callback
 * DESCRIPTION
 *  Callback function for IP address editor in inline editor screen
 * PARAMETERS
 *  string_buffer       [?]     
 *  IP1                 [?]     
 *  IP2                 [?]     
 *  IP3                 [?]     
 *  IP4                 [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_prof_ip_addr_callback(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Point[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) Point, (S8*) ".");

    mmi_ucs2cpy((PS8) string_buffer, (PS8) IP1);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP2);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP3);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) IP4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_profile_connection_inline_editor
 * DESCRIPTION
 *  "Connection Settings" menu inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_profile_connection_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_data_account_edit_context.yes_no_list[0] = (U8*) GetString(STR_GLOBAL_NO);
    g_syncml_data_account_edit_context.yes_no_list[1] = (U8*) GetString(STR_GLOBAL_YES);

    g_syncml_data_account_edit_context.http_wap_list[0] = (U8*) GetString(STR_ID_SYNC_CONN_HTTP);
    g_syncml_data_account_edit_context.http_wap_list[1] = (U8*) GetString(STR_ID_SYNC_CONN_WAP);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(SERVICES_DATA_CONNECT_MAIN_STRING_ID));

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &wgui_inline_items[1],
        (U8*) g_syncml_data_account_edit_context.data_account,
        (PU8) NULL,
        NULL,
        NULL,
        MAX_DATA_ACCOUNT_NAME_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(
        &wgui_inline_items[1],
        mmi_syncml_list_data_account);
    ShowAsControl(&wgui_inline_items[1]);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_ID_SYNC_CONN_TYPE));

    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[3],
        2,
        g_syncml_data_account_edit_context.http_wap_list,
        &g_syncml_data_account_edit_context.conn_type);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_ID_SYNC_PROXY_USAGE));

    SetInlineItemActivation(&wgui_inline_items[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[5],
        2,
        g_syncml_data_account_edit_context.yes_no_list,
        &g_syncml_data_account_edit_context.use_proxy);

    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[6], (PU8) GetString(STR_ID_SYNC_PROXY_SERVER));

    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[7],
        (U8*) g_syncml_data_account_edit_context.proxy_ip[0],
        (U8*) g_syncml_data_account_edit_context.proxy_ip[1],
        (U8*) g_syncml_data_account_edit_context.proxy_ip[2],
        (U8*) g_syncml_data_account_edit_context.proxy_ip[3],
        mmi_syncml_prof_ip_addr_callback);

    SetInlineItemActivation(&wgui_inline_items[8], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[8], (PU8) GetString(STR_ID_SYNC_PROXY_PORT));

    SetInlineItemActivation(&wgui_inline_items[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[9],
        (U8*) (g_syncml_data_account_edit_context.proxy_port),
        MAX_SYNCML_PROXY_PORT_LEN,
        INPUT_TYPE_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[9]);
    DisableInlineItemHighlight(&wgui_inline_items[9]);

    SetInlineItemActivation(&wgui_inline_items[10], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[10], (PU8) GetString(STR_GLOBAL_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[11], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[11],
        STR_GLOBAL_USERNAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_USERNAME,
        (U8*) g_syncml_data_account_edit_context.name_buffer,
        MAX_SYNCML_PROXY_USERNAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[11], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[12], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[12], (PU8) GetString(STR_GLOBAL_PASSWORD));

    SetInlineItemActivation(&wgui_inline_items[13], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[13],
        STR_GLOBAL_PASSWORD,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_PASSWORD,
        (U8*) g_syncml_data_account_edit_context.pswd_buffer,
        MAX_SYNCML_PROXY_PASSWORD,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[13], mmi_syncml_set_profile_custom_function);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_connection_save
 * DESCRIPTION
 *  "Connection Settings" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_connection_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_profile.profile_validation |= 0x10;

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    /* save to nvram */
    g_syncml_profile.net_id = g_syncml_data_account_edit_context.net_id;
    g_syncml_profile.conn_type = g_syncml_data_account_edit_context.conn_type;
    g_syncml_profile.use_proxy = g_syncml_data_account_edit_context.use_proxy;
    g_syncml_profile.proxy_ip[0] = (U8) gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_ip[0]);
    g_syncml_profile.proxy_ip[1] = (U8) gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_ip[1]);
    g_syncml_profile.proxy_ip[2] = (U8) gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_ip[2]);
    g_syncml_profile.proxy_ip[3] = (U8) gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_ip[3]);
    g_syncml_profile.proxy_port = (U16) (gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_port));
    mmi_ucs2_to_asc((S8*) g_syncml_profile.proxy_username, (S8*) g_syncml_data_account_edit_context.name_buffer);
    mmi_ucs2_to_asc((S8*) g_syncml_profile.proxy_password, (S8*) g_syncml_data_account_edit_context.pswd_buffer);
    mmi_syncml_update_profile_to_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_CONNECTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_profile_connection_done
 * DESCRIPTION
 *  "Connection Settings" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_profile_connection_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_port) > 65535) ||
        (g_syncml_data_account_edit_context.use_proxy == 1 && (U8) gui_atoi((UI_string_type) g_syncml_data_account_edit_context.proxy_ip[0]) == 0))
    {
        /* port number shall not exceed 65535 */
        DisplayPopup(
            (U8*) GetString(STR_ID_SYNC_INVALID_INPUT),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

   DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_edit_profile_connection_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_profile_connection
 * DESCRIPTION
 *  "Connection Settings" menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_exit_profile_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_SYNC_PROFILE_CONNECTION;
    Scr.entryFuncPtr = mmi_syncml_entry_profile_connection;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_profile_ip_conv
 * DESCRIPTION
 *  This Fun Convert the integer value to String with prefix zero.
 *  
 *  Works only for three digit integer.(0-256)
 * PARAMETERS
 *  string_val      [OUT]       Out put string value
 *  digit_val       [IN]        Input digit value
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_profile_ip_conv(PU8 string_val, U8 digit_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 local_buffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (digit_val == 0)
    {
        mmi_asc_to_ucs2((S8*) string_val, (S8*) "000");
    }
    else if (digit_val < 10)
    {
        sprintf(local_buffer, "00%d", digit_val);
        mmi_asc_to_ucs2((S8*) string_val, (S8*) local_buffer);
    }
    else if (digit_val < 100)
    {
        sprintf(local_buffer, "0%d", digit_val);
        mmi_asc_to_ucs2((S8*) string_val, (S8*) local_buffer);
    }
    else
    {
        sprintf(local_buffer, "%d", digit_val);
        mmi_asc_to_ucs2((S8*) string_val, (S8*) local_buffer);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_profile_connection
 * DESCRIPTION
 *  "Connection Settings" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_profile_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 IconList[] = 
    {
        IMG_GLOBAL_L1, 0,
        IMG_GLOBAL_L2, 0,
        IMG_GLOBAL_L3, 0,
        IMG_GLOBAL_L4, 0,
        IMG_GLOBAL_L5, 0,
        IMG_GLOBAL_L6, 0,
        IMG_GLOBAL_L7, 0
    };
    const S8 g_syncml_zero_ip[] = { '0', '\0', '0', '\0', '0', '\0', '\0', '\0' }; /* 000 */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_CONNECTION, mmi_syncml_exit_profile_connection, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_CONNECTION);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SYNC_PROFILE_CONNECTION, &inputBufferSize);
    SetParentHandler(0);

    if (inputBuffer == NULL)
    {
        g_syncml_data_account_edit_context.net_id = g_syncml_profile.net_id;
        g_syncml_data_account_edit_context.conn_type = g_syncml_profile.conn_type;
        g_syncml_data_account_edit_context.use_proxy = g_syncml_profile.use_proxy;

        mmi_dtcnt_get_account_name(
            g_syncml_data_account_edit_context.net_id,
            (S8*) g_syncml_data_account_edit_context.data_account,
            MAX_DATA_ACCOUNT_NAME_LEN);

        if (g_syncml_profile.proxy_ip[0] == 0)
        {
            mmi_ucs2cpy((S8*) g_syncml_data_account_edit_context.proxy_ip[0], (S8*) g_syncml_zero_ip);
            mmi_ucs2cpy((S8*) g_syncml_data_account_edit_context.proxy_ip[1], (S8*) g_syncml_zero_ip);
            mmi_ucs2cpy((S8*) g_syncml_data_account_edit_context.proxy_ip[2], (S8*) g_syncml_zero_ip);
            mmi_ucs2cpy((S8*) g_syncml_data_account_edit_context.proxy_ip[3], (S8*) g_syncml_zero_ip);
        }
        else
        {
           mmi_syncml_profile_ip_conv((PU8) g_syncml_data_account_edit_context.proxy_ip[0], (U8)g_syncml_profile.proxy_ip[0]);
	       mmi_syncml_profile_ip_conv((PU8) g_syncml_data_account_edit_context.proxy_ip[1], (U8)g_syncml_profile.proxy_ip[1]);
	       mmi_syncml_profile_ip_conv((PU8) g_syncml_data_account_edit_context.proxy_ip[2], (U8)g_syncml_profile.proxy_ip[2]);
	       mmi_syncml_profile_ip_conv((PU8) g_syncml_data_account_edit_context.proxy_ip[3], (U8)g_syncml_profile.proxy_ip[3]);
        }

        if (g_syncml_profile.proxy_port == 0)
        {
            memset(g_syncml_data_account_edit_context.proxy_port, 0, sizeof(g_syncml_data_account_edit_context.proxy_port));
        }
        else
        {
            gui_itoa(
                (S32) g_syncml_profile.proxy_port,
                (UI_string_type) g_syncml_data_account_edit_context.proxy_port,
                10);
        }

        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_data_account_edit_context.name_buffer,
            (S8*) g_syncml_profile.proxy_username,
            MAX_SYNCML_PROXY_USERNAME);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_data_account_edit_context.pswd_buffer,
            (S8*) g_syncml_profile.proxy_password,
            MAX_SYNCML_PROXY_PASSWORD);
    }
    
    mmi_syncml_set_profile_connection_inline_editor();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 14, inputBuffer);
    }

    if (get_wgui_inline_list_menu_status() || g_syncml_data_account_edit_context.net_id != g_syncml_profile.net_id)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ClearHighlightHandler();

    ShowCategory57Screen(
        STR_ID_SYNC_PROFILE_CONNECTION,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        14,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_syncml_edit_profile_connection_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_abort_profile_edit
 * DESCRIPTION
 *  Generic abortion of profile settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_abort_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_NAME);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_NAME_OPTION);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_SERVER);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_CONTACT);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_CALENDAR);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_CONNECTION);
    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_PC);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_update_profile_to_nvram
 * DESCRIPTION
 *  Updating profile to NVRAM
 * PARAMETERS
 *  record_id       [IN]            record index
 *  nvram_buf       [IN]            buffer to write
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_update_profile_to_nvram(U8 record_id, void *nvram_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_profile_struct *temp_profile = (syncml_profile_struct *) nvram_buf;
    S16 error;

    pBOOL profile_name_modified = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2cmp((S8*) temp_profile->profile_name, GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + record_id - 1))) == 0)
    {
        memset(temp_profile->profile_name, 0, MAX_SYNCML_PROFILE_NAME * ENCODING_LENGTH);
        profile_name_modified = 1;
    }

    WriteRecord(NVRAM_EF_SYNCML_PROFILE_LID, record_id, (void*)nvram_buf, NVRAM_EF_SYNCML_PROFILE_SIZE, &error);

    if (profile_name_modified)
    {
        mmi_ucs2cpy((S8*) temp_profile->profile_name, GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + record_id - 1)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_profile_from_nvram
 * DESCRIPTION
 *  Reading profile from NVRAM
 * PARAMETERS
 *  record_id       [IN]            record index
 *  nvram_buf       [IN]            buffer to read
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_read_profile_from_nvram(U8 record_id, void *nvram_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_profile_struct *temp_profile = (syncml_profile_struct *) nvram_buf;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_id == 0)
    {
        return; /* invalid id */
    }

    ReadRecord(NVRAM_EF_SYNCML_PROFILE_LID, record_id, (void*)nvram_buf, NVRAM_EF_SYNCML_PROFILE_SIZE, &error);

    if(temp_profile->profile_id == 0xFF)
    {
        memset(temp_profile, 0, sizeof(syncml_profile_struct));

        temp_profile->profile_id = record_id;
        temp_profile->profile_validation = 0x11;

        if (record_id < MAX_SYNCML_SV_PROFILES + 1)
        {
            strcpy((PS8) temp_profile->server_address, "http://");
            strcpy((PS8) temp_profile->contact_address, "./");
            strcpy((PS8) temp_profile->calendar_address, "./");
            temp_profile->net_id = CUSTOM_DEFAULT_SYNCML_DTCNT_ID; /* mmi_dtcnt_get_first_account_id(DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI); */
        }
        else
        {
            kal_sprintf((PS8) temp_profile->profile_name, "Profile PC %d", record_id - MAX_SYNCML_SV_PROFILES);
        }

        mmi_syncml_update_profile_to_nvram(record_id, nvram_buf); /* reset to default */
    }

    if (mmi_ucs2strlen((S8*) temp_profile->profile_name) == 0)
    {
        mmi_ucs2cpy((S8*) temp_profile->profile_name, GetString((U16) (STR_ID_SYNC_PROFILE_ID1 + record_id - 1)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_pc_profile_inline_editor
 * DESCRIPTION
 *  "PC Profile" menu inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_pc_profile_inline_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_profile_edit_context.bearer_list[0] = (U8*) GetString(STR_ID_SYNC_BEARER_USB);
    g_syncml_profile_edit_context.bearer_list[1] = (U8*) GetString(STR_ID_SYNC_BEARER_BT);
    g_syncml_profile_edit_context.bearer_list[2] = (U8*) GetString(STR_ID_SYNC_BEARER_IRDA);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (PU8) GetString(STR_ID_SYNC_PROFILE_NAME));

    SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[1],
        STR_ID_SYNC_PROFILE_NAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_PROFILE,
        (U8*) g_syncml_profile_edit_context.addr_buffer,
        MAX_SYNCML_PROFILE_NAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[1], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[2], (PU8) GetString(STR_GLOBAL_USERNAME));

    SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[3],
        STR_GLOBAL_USERNAME,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_USERNAME,
        (U8*) g_syncml_profile_edit_context.name_buffer,
        MAX_SYNCML_USERNAME,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[3], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[4], (PU8) GetString(STR_GLOBAL_PASSWORD));

    SetInlineItemActivation(&wgui_inline_items[5], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[5],
        STR_GLOBAL_PASSWORD,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_PASSWORD,
        (U8*) g_syncml_profile_edit_context.pswd_buffer,
        MAX_SYNCML_PASSWORD,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[5], mmi_syncml_set_profile_custom_function);

    SetInlineItemActivation(&wgui_inline_items[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[6], (PU8) GetString(STR_ID_SYNC_BEARER));

    SetInlineItemActivation(&wgui_inline_items[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[7],
        3,
        g_syncml_profile_edit_context.bearer_list,
        &g_syncml_profile_edit_context.use_bearer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_pc_profile_save
 * DESCRIPTION
 *  "PC Profile" menu save function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_pc_profile_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_syncml_profile.profile_validation = 0x1F;

    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    /* save to nvram */
    mmi_ucs2_to_asc((S8*) g_syncml_profile.profile_name, (S8*) g_syncml_profile_edit_context.addr_buffer);
    mmi_ucs2_to_asc((S8*) g_syncml_profile.server_username, (S8*) g_syncml_profile_edit_context.name_buffer);
    mmi_ucs2_to_asc((S8*) g_syncml_profile.server_password, (S8*) g_syncml_profile_edit_context.pswd_buffer);
    g_syncml_profile.net_id = (U32)g_syncml_profile_edit_context.use_bearer;
    mmi_syncml_update_profile_to_nvram((U8)(g_syncml_context.selected_profile + 1), &g_syncml_profile);

    /* update profile name */
    mmi_asc_to_ucs2((S8*) g_syncml_context.profile_name_display[g_syncml_context.selected_profile], (S8*) g_syncml_profile.profile_name);

    DeleteScreenIfPresent(SCR_ID_SYNC_PROFILE_PC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_edit_pc_profile_done
 * DESCRIPTION
 *  "PC Profile" menu finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_edit_pc_profile_done(void)
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
        get_string(STR_GLOBAL_SAVE_ASK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_syncml_edit_pc_profile_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_syncml_abort_profile_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_pc_profile_edit
 * DESCRIPTION
 *  "PC Profile" menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_exit_pc_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = SCR_ID_SYNC_PROFILE_PC;
    Scr.entryFuncPtr = mmi_syncml_entry_pc_profile_edit;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (S16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    GetCategory57History(Scr.guiBuffer);
    AddNHistory(Scr, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_pc_profile_edit
 * DESCRIPTION
 *  "PC Profile" menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_pc_profile_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;          /* buffer holding history data */
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 IconList[] = {IMG_ID_SYNC_PROFILE, 0, IMG_ID_SYNC_USERNAME, 0, IMG_ID_SYNC_PASSWORD, 0, IMG_ID_SYNC_SERVER, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SYNC_PROFILE_PC, mmi_syncml_exit_pc_profile_edit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SYNC_PROFILE_PC);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SYNC_PROFILE_PC, &inputBufferSize);
    SetParentHandler(0);

    if (inputBuffer == NULL)
    {
        /* prepare default strings to display if this screen is first entered */
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.addr_buffer,
            (S8*) g_syncml_profile.profile_name,
            MAX_SYNCML_PROFILE_NAME);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.name_buffer,
            (S8*) g_syncml_profile.server_username,
            MAX_SYNCML_USERNAME);
        mmi_asc_n_to_ucs2(
            (S8*) g_syncml_profile_edit_context.pswd_buffer,
            (S8*) g_syncml_profile.server_password,
            MAX_SYNCML_PASSWORD);
        g_syncml_profile_edit_context.use_bearer = (S32)g_syncml_profile.net_id;
    }

    mmi_syncml_set_pc_profile_inline_editor();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 8, inputBuffer);
    }

    ClearHighlightHandler();

    ShowCategory57Screen(
        STR_ID_SYNC_PROFILE,
        GetRootTitleIcon(MENU_ID_SYNCML_MAIN), //IMG_ID_SYNC_MENU,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        8,
        IconList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_syncml_edit_pc_profile_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_profile_name_display_strings
 * DESCRIPTION
 *  Read profile name display strings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
void mmi_syncml_read_profile_name_display_strings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_profile_struct temp_profile;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i <MAX_SYNCML_PROFILES ; i++)
    {
        /* temporarily read profiles to check if they are not initialized */
        mmi_syncml_read_profile_from_nvram((U8)(i + 1), (void *)(&temp_profile));
        /* retrieve the profile names */
        mmi_ucs2cpy((S8*) g_syncml_context.profile_name_display[i], (S8*) temp_profile.profile_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_profile_custom_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
void mmi_syncml_set_profile_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(MENU_ID_SYNCML_MAIN));
#endif
}


#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_active_profile_bearer
 * DESCRIPTION
 *  Bearer check for preferred mode
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U32 mmi_syncml_get_active_profile_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    syncml_profile_struct active_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_read_profile_from_nvram(g_syncml_context.active_profile, &active_profile);

    return active_profile.net_id;
}
#endif /* __MMI_WLAN_FEATURES__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_profile_edit_context
 * DESCRIPTION
 *  get g_syncml_profile_edit_context static variable
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
void* mmi_syncml_get_profile_edit_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return (void*)(&g_syncml_profile_edit_context);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_data_account_edit_context
 * DESCRIPTION
 *  get g_syncml_profile_edit_context static variable
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
void* mmi_syncml_get_data_account_edit_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return (void*)(&g_syncml_data_account_edit_context);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_syncml_profile
 * DESCRIPTION
 *  get g_syncml_profile static variable
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
void* mmi_syncml_get_syncml_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return (void*)(&g_syncml_profile);
}

#endif /* __SYNCML_SUPPORT__ */

