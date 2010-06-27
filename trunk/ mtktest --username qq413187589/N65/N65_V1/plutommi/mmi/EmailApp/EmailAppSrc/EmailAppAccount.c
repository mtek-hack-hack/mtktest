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
 * EmailAppAccount.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Account Settings Part of Email application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**************************************************************/

#include "MMI_include.h"
#ifndef MMI_EMAILAPPACCOUNT_C
#define MMI_EMAILAPPACCOUNT_C

#ifdef __MMI_EMAIL__
#include "CommonScreens.h"
#include "Conversions.h"
#include "app_mine.h"

#include "wgui_status_icons.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "MemPoolContainerProt.h"

#include "fmt_struct.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"

#include "DataAccountGprot.h"
#include "PhoneBookGprot.h"
#include "PhoneSetupGprots.h"

#include "mdi_datatype.h"
#include "AudioPlayerProt.h"
#include "VdoPlyGProt.h"
#include "VdoPlyResDef.h"
#include "ImageViewer.h"

#include "App_usedetails.h" /*to use applib_get_address_list_from_text_ext*/
#include "CallManagementGprot.h"   /*to use MakeCall*/
#include "wapadp.h"  /*to use wap_start_browser*/

#ifdef __MMI_EMAIL_DRM_SUPPORT__
#include "Drm_gprot.h"
#endif 
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 
#include "gpioinc.h"

#include "MessagesResourceData.h"
#include "EmailAppResDef.h"
#include "EmailAppProt.h"
#include "EmailAppGProt.h"

/*****************************************************************************
 * variables
 *****************************************************************************/
/* extern */
#ifdef __MMI_EMAIL_DRM_SUPPORT__
extern S8 rights_issuer[MAX_LINE_LENGTH];
#endif /* __MMI_EMAIL_DRM_SUPPORT__ */

#ifdef __MMI_TOUCH_SCREEN__
extern const UI_character_type g_email_allowed[];
#endif
extern const S16 g_email_addr_input_modes[];

extern InlineItem wgui_inline_items[];
/* static */
static UI_character_type email_sig_old_file_path[(FMGR_MAX_PATH_LEN + 1)];
static UI_character_type email_addr_buffer[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
static MMI_BOOL is_reply_insert = MMI_FALSE;
static MMI_BOOL is_email_auth_inline_changed = MMI_FALSE;

/*****************************************************************************
 * functions
 *****************************************************************************/
 /* extern */
extern void set_leading_zero(U8 u8type);
#ifdef __FLIGHT_MODE_SUPPORT__
extern pBOOL mmi_bootup_get_active_flight_mode(void);
#endif
extern pBOOL mmi_bootup_is_network_service_available(void);

/* static */
/* SMTP Authentication */
static void mmi_email_smtp_auth_option_handler(S32 item_index);
static void mmi_email_entry_prof_auth(void);
static void mmi_email_exit_prof_auth(void);
static void mmi_email_prof_fill_auth_inline_struct(void);
static void mmi_email_auth_same_option_handler(S32 item_index);
static void mmi_email_auth_done_handler(void);
static void mmi_email_auth_back_handler(void);

#define ACCT_EMAIL

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_setting
 * DESCRIPTION
 *  highlight handler for Profile Setting option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_email_prof_get_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_PROF_SETTING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_smtp
 * DESCRIPTION
 *  highlight handler for SMTP option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_smtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_email_prof_get_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_PROF_SMTP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_pop3_impa4
 * DESCRIPTION
 *  highlight handler for POP3/IMAP4 option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_pop3_impa4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_email_prof_get_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_PROF_POP3_IMAP4;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_sig
 * DESCRIPTION
 *  highlight handler for Signature option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_sig(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_email_prof_get_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    email_p->prof_info.prof_misc.curr_scr = SCR_ID_EMAIL_PROF_SIG;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comm_full_edit_opt
 * DESCRIPTION
 *  Entry common full screen editor in Profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comm_full_edit_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 itemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_FULL_EDIT_OPT, NULL, mmi_email_entry_comm_full_edit_opt, NULL);
    SetParentHandler(MENU_ID_EMAIL_PROF_EDITOR_OPT);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_FULL_EDIT_OPT);
    nItems = GetNumOfChild(MENU_ID_EMAIL_PROF_EDITOR_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_PROF_EDITOR_OPT, itemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
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
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof
 * DESCRIPTION
 *  Entry profile list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern const U16 gIndexIconsImageList[];
void mmi_email_entry_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrItemList[MMI_EMAIL_MAX_ACCTS];
    U16 nIconItemList[MMI_EMAIL_MAX_ACCTS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF, NULL, mmi_email_entry_prof, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF);

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        nStrItemList[i] = (U8*) email_p->prof_info.prof_misc.acct_names[i];
        nIconItemList[i] = 0;
    }

    if (mmi_email_prof_is_activated())
    {
        nIconItemList[email_p->prof_info.act_prof.act_indx] = IMG_VICON;
        email_p->prof_info.prof_misc.curr_sel_prof = email_p->prof_info.act_prof.act_indx;
    }
    else
    {
        email_p->prof_info.prof_misc.curr_sel_prof = 0;
    }

    RegisterHighlightHandler(mmi_email_hilite_prof_list);

    ShowCategory73Screen(
        STR_EMAIL_EMAIL_ACCTS_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_EMAIL_MAX_ACCTS,
        nStrItemList,
        (U16*) nIconItemList,
        (U16*) gIndexIconsImageList,
        (S32) email_p->prof_info.prof_misc.curr_sel_prof,
        guiBuffer,
        ICON_ICON_TEXT);

    SetLeftSoftkeyFunction(mmi_email_entry_prof_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_prof_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_email_prof_go_back_to_main, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_prof_go_back_to_main, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_go_back_to_main
 * DESCRIPTION
 *  Profile setting right soft key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_go_back_to_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.is_acct_change)
    {
        email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_PROF;
        mmi_email_ps_list_folders_req();
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROF);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_list
 * DESCRIPTION
 *  Highlight handler of Profile list.
 * PARAMETERS
 *  index       [IN]        Index of highlighted profile.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_list(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->prof_info.prof_misc.curr_sel_prof = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_opt
 * DESCRIPTION
 *  Entry function of Profile->Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only Done and Input Method */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_OPT, NULL, mmi_email_entry_prof_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_OPT);
    SetParentHandler(MENU_ID_EMAIL_PROF_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_PROF_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_PROF_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_EMAIL_ACCT_OPTIONS_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_activate
 * DESCRIPTION
 *  Highlight handler of Profile->Activate option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_prof_activate, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_prof_activate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_activate
 * DESCRIPTION
 *  Handler of Profile->Option->Activate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_ps_activate_acct_req((U8) (email_p->prof_info.prof_misc.curr_sel_prof + 1));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_get_data
 * DESCRIPTION
 *  Send request to get current selected profile data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_get_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_ps_get_acct_profile_req((U8) (email_p->prof_info.prof_misc.curr_sel_prof + 1));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_edit
 * DESCRIPTION
 *  Highlight handler of Profile->Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_prof_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_prof_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_edit
 * DESCRIPTION
 *  Entry function of Profile->Option->Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[EMAIL_PROF_TOTAL];
    U8 *guiBuffer;

    U16 emailEmailProfileSettingIcons[EMAIL_PROF_TOTAL] = 
    {
        IMG_EMAIL_PROFILE_SETTING_ID,
        IMG_EMAIL_SMTP_SETTING_ID,
        IMG_EMAIL_IMAP_POP3_SETTING_ID,
        IMG_EMAIL_SIGNATURE_SETTING_ID
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_OPT_EDIT, NULL, mmi_email_entry_prof_edit, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_OPT_EDIT);

    SetParentHandler(MENU_ID_EMAIL_PROF_EDIT_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_PROF_EDIT_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_PROF_EDIT_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_EMAIL_ACCT_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) emailEmailProfileSettingIcons,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetLeftSoftkeyFunction(mmi_email_prof_get_data, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_prof_get_data, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_setting
 * DESCRIPTION
 *  Entry function of Profile Setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 setting_icon[EMAIL_SETTING_TOTAL_ITEM] = 
    {
        IMG_EMAIL_PROFILE_NAME_ID, 0,
        IMG_EMAIL_DATA_ACCOUNT_ID, 0,
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        IMG_EMAIL_PROTOCOL_ID, 0,
    #endif 
    #if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
        IMG_EMAIL_CHECK_INTERVAL_ID, 0,
    #endif 
        IMG_EMAIL_DOWNLOAD_SIZE_ID, 0,
        IMG_EMAIL_REPLY_TO_ID, 0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_SETTING, mmi_email_exit_prof_setting, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_PROF_SETTING, &inputBufferSize);
    mmi_email_prof_fill_setting_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_SETTING_TOTAL_ITEM, inputBuffer);
    }

    RegisterHighlightHandler(mmi_email_hilite_prof_setting_item);
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    gdi_layer_lock_frame_buffer();
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
    ShowCategory57Screen(
        STR_EMAIL_ACCT_SETTING_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_SETTING_TOTAL_ITEM,
        (U16*) setting_icon,
        wgui_inline_items,
        0,
        guiBuffer);
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    gdi_layer_unlock_frame_buffer();
    if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_IMAP4)
    {
        DisableInlineItem(&(wgui_inline_items[EMAIL_SETTING_CHK_INT]), EMAIL_SETTING_CHK_INT);
        Category57ChangeItemText(
            EMAIL_SETTING_CHK_INT,
            (U8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        EnableInlineItem(&(wgui_inline_items[EMAIL_SETTING_CHK_INT]), EMAIL_SETTING_CHK_INT);
        Category57ChangeItemText(
            EMAIL_SETTING_CHK_INT,
            email_p->prof_info.prof_misc.chk_interval[email_p->prof_info.editing_prof.setting_info.chk_interval]);
    }
    RedrawCategory57Screen();
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 

    SetCategory57RightSoftkeyFunctions(mmi_email_prof_save_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_prof_setting
 * DESCRIPTION
 *  Exit function of Profile Setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_prof_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_n_history(SCR_ID_EMAIL_PROF_SETTING, mmi_email_entry_prof_setting);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_setting_item
 * DESCRIPTION
 *  Highlight handler of Profile setting.
 * PARAMETERS
 *  index       [IN]        Index of highlighted profile.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_setting_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == EMAIL_SETTING_DATA_ACCT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
    }
    else if (index == EMAIL_SETTING_REPLY_TO)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_email_entry_prof_setting_reply_to, KEY_EVENT_UP);
        is_email_auth_inline_changed = MMI_FALSE;
        mmi_ucs2cpy((S8*)email_addr_buffer, (S8*)email_p->prof_info.editing_prof.setting_info.reply_to);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_save_setting
 * DESCRIPTION
 *  Save Profile Setting data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_save_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 DownloadMaxSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Profile name shall not be empty */
    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.setting_info.prof_name) == 0)
    {
        mmi_ucs2cpy(
            (S8*) email_p->prof_info.editing_prof.setting_info.prof_name,
            (S8*) GetString((U16) (STR_EMAIL_PROFILE_NAME_1 + email_p->prof_info.prof_misc.curr_sel_prof)));
    }

    CloseCategory57Screen();

    /* Download size exceeds boundary */
    DownloadMaxSize = gui_atoi((UI_string_type) email_p->prof_info.editing_prof.setting_info.dwnl_size);
    if (mmi_ucs2strlen((S8*)email_p->prof_info.editing_prof.setting_info.dwnl_size) == 0)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_DOWNLOAD_SIZE_EMPTY_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SETTING_DWNL_SIZE);    
        return;
    }
    if (DownloadMaxSize < MMI_EMAIL_MIN_MSG_SIZE || DownloadMaxSize > MMI_EMAIL_MAX_MSG_SIZE)
    {
        S8 *asciiMaxString = OslMalloc(EMAIL_MAX_DWNL_LEN);
        S8 *ucs2MaxString = OslMalloc(EMAIL_MAX_DWNL_LEN * ENCODING_LENGTH);

        if (DownloadMaxSize < MMI_EMAIL_MIN_MSG_SIZE)
        {
            sprintf((S8*) asciiMaxString, "\n < %u", (U32) MMI_EMAIL_MIN_MSG_SIZE);
        }
        else
        {
            sprintf((S8*) asciiMaxString, "\n > %u", (U32) MMI_EMAIL_MAX_MSG_SIZE);
        }

        mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) GetString(STR_EMAIL_MAX_SIZE));
        mmi_asc_to_ucs2((S8*) ucs2MaxString, (S8*) asciiMaxString);
        mmi_ucs2cat((S8*) email_p->comm_buff, (S8*) ucs2MaxString);
        mmi_email_util_display_popup(
            (U8*) email_p->comm_buff,
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        OslMfree(asciiMaxString);
        OslMfree(ucs2MaxString);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SETTING_DWNL_SIZE);
        return;
    }
    /* reply to address */
    if ((mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.setting_info.reply_to) > 0)
            && (!mmi_email_util_chk_addr((U8*) email_p->prof_info.editing_prof.setting_info.reply_to)))
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SETTING_REPLY_TO);
        return;
    }
#if (!defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) && defined (__CBM_ALWAYS_ASK_FEATURE__))
    else if (always_ask_is_always_ask_data_account(email_p->prof_info.editing_prof.setting_info.data_acct) && 
        email_p->prof_info.editing_prof.setting_info.chk_interval 
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        && (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_POP3)
#endif
        )
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_WRONG_SETTINGS),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SETTING_CHK_INT);
        return;
    }
#endif
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SAVING),
        NULL,
        IMG_GLOBAL_SAVE,
        NULL,
        NULL,
        NULL);
    mmi_email_ps_set_acct_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_setting_inline_struct
 * DESCRIPTION
 *  Fill inline structure data for Profile Setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_fill_setting_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_dwnl_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* protocol list */
    email_p->prof_info.prof_misc.prot_list[0] = (U8*) GetString(STR_EMAIL_POP3_ID);
    email_p->prof_info.prof_misc.prot_list[1] = (U8*) GetString(STR_EMAIL_IMAP4_ID);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    /* check interval list */
    email_p->prof_info.prof_misc.chk_interval[0] = (U8*) GetString(STR_GLOBAL_OFF);
    email_p->prof_info.prof_misc.chk_interval[1] = (U8*) GetString(STR_EMAIL_5_MIN_ID);
    email_p->prof_info.prof_misc.chk_interval[2] = (U8*) GetString(STR_EMAIL_30_MIN_ID);
    email_p->prof_info.prof_misc.chk_interval[3] = (U8*) GetString(STR_EMAIL_1_HOUR_ID);
    email_p->prof_info.prof_misc.chk_interval[4] = (U8*) GetString(STR_EMAIL_2_HOURS_ID);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 

    /* Profile Name caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_NAME_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SETTING_NAME_CAP], (U8*) GetString(STR_EMAIL_ACCT_NAME_ID));

    /* Profile Name */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_NAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[EMAIL_SETTING_NAME],
        STR_EMAIL_ACCT_NAME_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.setting_info.prof_name,
        (EMAIL_MAX_ACCT_NAME + 1),
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SETTING_NAME], mmi_email_hilite_prof_full_edit);

    /* Data Account Caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_DATA_ACCT_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SETTING_DATA_ACCT_CAP], (U8*) GetString(STR_EMAIL_DATA_ACCOUNT_ID));

    /* Data Account */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_DATA_ACCT], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &wgui_inline_items[EMAIL_SETTING_DATA_ACCT],
        (U8*) email_p->prof_info.prof_misc.data_acct_name,
        (PU8) NULL,
        NULL,
        NULL,
        MAX_DATA_ACCOUNT_NAME_LEN,
        0,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(
        &wgui_inline_items[EMAIL_SETTING_DATA_ACCT],
        mmi_email_prof_list_data_acct);
    ShowAsControl(&wgui_inline_items[EMAIL_SETTING_DATA_ACCT]);

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /* Protocol Caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_PROTOCOL_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SETTING_PROTOCOL_CAP], (U8*) GetString(STR_EMAIL_PROTOCOL_ID));

    /* Protocol */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_PROTOCOL], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_SETTING_PROTOCOL],
        EMAIL_MAX_PROT_ITEM,
        email_p->prof_info.prof_misc.prot_list,
        &email_p->prof_info.editing_prof.setting_info.in_prot);
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[EMAIL_SETTING_PROTOCOL], mmi_email_protocol_change_handler);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    /* Check interval caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_CHK_INT_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SETTING_CHK_INT_CAP], (U8*) GetString(STR_EMAIL_CHECK_INTERVAL_ID));

    /* Check interval */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_CHK_INT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_SETTING_CHK_INT],
        EMAIL_MAX_CHK_INTERVAL_ITEM,
        email_p->prof_info.prof_misc.chk_interval,
        &email_p->prof_info.editing_prof.setting_info.chk_interval);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 

    /* Maximum size of download caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_DWNL_SIZE_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SETTING_DWNL_SIZE_CAP], (U8*) GetString(STR_EMAIL_MAX_SIZE));

    /* Max size */
    max_dwnl_len = mmi_email_util_get_num_len(MMI_EMAIL_MAX_MSG_SIZE) + 1;
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_DWNL_SIZE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[EMAIL_SETTING_DWNL_SIZE],
        (U8*) email_p->prof_info.editing_prof.setting_info.dwnl_size,
        max_dwnl_len,
        INPUT_TYPE_NUMERIC);
    DisableInlineItemHighlight(&wgui_inline_items[EMAIL_SETTING_DWNL_SIZE]);

    /* caption of reply-to */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SETTING_REPLY_TO_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SETTING_REPLY_TO_CAP], (U8*) GetString(STR_EMAIL_REPLY_TO_ID));

    /* email reply-to */
    SetInlineItemDisplayOnly(&wgui_inline_items[EMAIL_SETTING_REPLY_TO], (U8*) email_p->prof_info.editing_prof.setting_info.reply_to );
}


#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)


/*****************************************************************************
 * FUNCTION
 *  mmi_email_protocol_change_handler
 * DESCRIPTION
 *  Highlight handler of the inline select for pulling interval
 * PARAMETERS
 *  item_index      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_protocol_change_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* check interval list */
    email_p->prof_info.prof_misc.chk_interval[0] = (U8*) GetString(STR_GLOBAL_OFF);
    email_p->prof_info.prof_misc.chk_interval[1] = (U8*) GetString(STR_EMAIL_5_MIN_ID);
    email_p->prof_info.prof_misc.chk_interval[2] = (U8*) GetString(STR_EMAIL_30_MIN_ID);
    email_p->prof_info.prof_misc.chk_interval[3] = (U8*) GetString(STR_EMAIL_1_HOUR_ID);
    email_p->prof_info.prof_misc.chk_interval[4] = (U8*) GetString(STR_EMAIL_2_HOURS_ID);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == EMAIL_PROT_IMAP4)
    {
        DisableInlineItem(&(wgui_inline_items[EMAIL_SETTING_CHK_INT]), EMAIL_SETTING_CHK_INT);
        Category57ChangeItemText(
            EMAIL_SETTING_CHK_INT,
            (U8*) GetString(STR_GLOBAL_OFF));
    }
    else
    {
        EnableInlineItem(&(wgui_inline_items[EMAIL_SETTING_CHK_INT]), EMAIL_SETTING_CHK_INT);
        Category57ChangeItemText(
            EMAIL_SETTING_CHK_INT,
            email_p->prof_info.prof_misc.chk_interval[email_p->prof_info.editing_prof.setting_info.chk_interval]);
    }
    RedrawCategory57Screen();
}
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_setting_reply_to
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_setting_reply_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO, NULL, mmi_email_entry_prof_setting_reply_to, NULL);
    
    if (mmi_ucs2strlen((S8*)email_addr_buffer) && is_reply_insert)
    {
        guiBuffer = NULL;
        is_reply_insert = MMI_FALSE;
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO);
    }

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_editor_set_vk_keys(MMI_TRUE, g_email_allowed, NULL);
#endif

    ShowCategory5Screen_ext(
        STR_EMAIL_REPLY_TO_ID, 
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN), 
        STR_GLOBAL_OPTIONS, 
        IMG_GLOBAL_OPTIONS, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK, 
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE, 
        (U8*)email_addr_buffer, 
        MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1, 
        guiBuffer, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        (S16*)g_email_addr_input_modes,
        NULL);  
    SetLeftSoftkeyFunction(mmi_email_entry_prof_setting_reply_to_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_setting_reply_to_opt
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_setting_reply_to_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];    /* Add, Done,Input Method */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_mutliline_inputbox_change_status())
    {
        is_email_auth_inline_changed = MMI_TRUE;
    }
    EntryNewScreen(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT, NULL, mmi_email_entry_prof_setting_reply_to_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT);
    SetParentHandler(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT);
    if (mmi_ucs2strlen((S8*)email_addr_buffer))
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_ADD);    
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_ADD);
    }
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_setting_reply_to_done_opt
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_setting_reply_to_done_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_save_prof_setting_reply_to, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_save_prof_setting_reply_to, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_save_prof_setting_reply_to
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_save_prof_setting_reply_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    historyNode *ptr_to_prof_setting_History = NULL;
    if (is_email_auth_inline_changed)
    {
        mmi_ucs2cpy((S8*)email_p->prof_info.editing_prof.setting_info.reply_to, (S8*)email_addr_buffer);
        GetHistoryPointer(SCR_ID_EMAIL_PROF_SETTING, &ptr_to_prof_setting_History);
        SetInlineDoneFlag(ptr_to_prof_setting_History->guiBuffer);
    }
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_setting_reply_to_add_opt
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_setting_reply_to_add_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_prof_setting_reply_to_search_in_phb, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_prof_setting_reply_to_search_in_phb, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_setting_reply_to_search_in_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_setting_reply_to_search_in_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_EMAIL, mmi_email_entry_prof_setting_reply_to_phb_get_addr_callback);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_setting_reply_to_phb_get_addr_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_setting_reply_to_phb_get_addr_callback(S8 *name, S8 *email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(email) == 0)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_EMAIL_ADDRESS_EMPTY),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        mmi_ucs2cpy((S8*)email_addr_buffer, (S8*) email);
        is_reply_insert = MMI_TRUE;
        is_email_auth_inline_changed = MMI_TRUE;
        GoBackToHistory(SCR_ID_EMAIL_PROF_SETTING_REPLY_TO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_list_data_acct
 * DESCRIPTION
 *  Enter Data Account option.
 *  If GPRS is enabled, go to CSD/GPRS screen; otherwse, go to CSD account list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_list_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(mmi_email_prof_data_acct_callback, MENU_ID_EMAIL_MAIN, DATA_ACCOUNT_BEARER_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_data_acct_callback
 * DESCRIPTION
 *  Callback function for Data Account
 * PARAMETERS
 *  index       [IN]        Index of selected account
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_data_acct_callback(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->prof_info.prof_misc.curr_data_acct = index;
    mmi_email_prof_save_data_acct();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_save_data_acct
 * DESCRIPTION
 *  Save setting of data account and update the account name of buffer in inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_save_data_acct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_get_account_name(
        (U32) email_p->prof_info.prof_misc.curr_data_acct,
        (S8*) email_p->prof_info.prof_misc.data_acct_name,
        MAX_DATA_ACCOUNT_NAME_LEN);
    email_p->prof_info.editing_prof.setting_info.data_acct = email_p->prof_info.prof_misc.curr_data_acct;
    DeleteUptoScrID(SCR_ID_EMAIL_PROF_SETTING);
    GoBackHistory();
    SetInlineListMenuChanged();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_smtp
 * DESCRIPTION
 *  Entry SMTP setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_smtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 smtp_icons[EMAIL_SMTP_TOTAL_ITEM] = 
    {
        IMG_EMAIL_OUTGOING_SERVER_ID, 0,
        IMG_EMAIL_OUTGOING_PORT_ID, 0,
        IMG_EMAIL_DISPLAY_NAME_ID, 0,
        IMG_EMAIL_EMAIL_ADDRESS_ID, 0,
        IMG_EMAIL_AUTH_ID, 0
    };

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_SMTP, mmi_email_exit_prof_smtp, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_SMTP);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_PROF_SMTP, &inputBufferSize);

    mmi_email_prof_fill_smtp_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_SMTP_TOTAL_ITEM, inputBuffer);
    }

    /*show DONE after back from auth setting screen*/
    if(is_email_auth_inline_changed == MMI_TRUE)
    {
        is_email_auth_inline_changed = MMI_FALSE;
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
        STR_EMAIL_SMTP_SETTING_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        EMAIL_SMTP_TOTAL_ITEM,
        (U16*) smtp_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_email_prof_save_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_prof_smtp
 * DESCRIPTION
 *  Exit function of SMTP setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_prof_smtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    mmi_email_util_add_n_history(SCR_ID_EMAIL_PROF_SMTP, mmi_email_entry_prof_smtp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_save_smtp
 * DESCRIPTION
 *  Function to save SMTP setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_save_smtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 OutgoingPortnumber;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    if ((mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.email_addr)) == 0)
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_EMAIL_ADDRESS_EMPTY),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SMTP_ADDR);
        return;
    }
    if (!mmi_email_util_chk_addr((U8*) email_p->prof_info.editing_prof.smtp_info.email_addr))
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SMTP_ADDR);
        return;
    }
    if (mmi_ucs2strlen((S8*)email_p->prof_info.editing_prof.smtp_info.out_port) == 0)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_PORT_NUMBER_EMPTY),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = EMAIL_SMTP_OUT_PORT;
        return;
    }
    OutgoingPortnumber = gui_atoi((UI_string_type) email_p->prof_info.editing_prof.smtp_info.out_port);
    if ((OutgoingPortnumber > EMAIL_MAX_PORT) || (OutgoingPortnumber < EMAIL_MIN_PORT))
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_PORT_NUMBER_OUTOF_RANGE),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = EMAIL_SMTP_OUT_PORT;
        return;
    }

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SAVING),
        NULL,
        IMG_GLOBAL_SAVE,
        NULL,
        NULL,
        NULL);
    mmi_email_ps_set_acct_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_smtp_inline_struct
 * DESCRIPTION
 *  Fill inline structure of SMTP setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_fill_smtp_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->prof_info.editing_prof.smtp_info.auth_status[0] = (U8*) GetString(STR_GLOBAL_OFF);
    email_p->prof_info.editing_prof.smtp_info.auth_status[1] = (U8*) GetString(STR_GLOBAL_ON);

    /* caption of outgoing server */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_OUT_SERVER_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_OUT_SERVER_CAP], (U8*) GetString(STR_EMAIL_OUTGOING_SERVER_ID));

    /* outgoing server */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_OUT_SERVER], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[EMAIL_SMTP_OUT_SERVER],
        STR_EMAIL_OUTGOING_SERVER_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.smtp_info.out_server,
        MMI_EMAIL_MAX_SERVER_NAME + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SMTP_OUT_SERVER], mmi_email_hilite_prof_full_edit);
    set_leading_zero(FALSE);

    /* caption of outgoing port */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_OUT_PORT_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_OUT_PORT_CAP], (U8*) GetString(STR_EMAIL_OUTGOING_PORT_ID));

    /* outgoing port */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_OUT_PORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[EMAIL_SMTP_OUT_PORT],
        (U8*) email_p->prof_info.editing_prof.smtp_info.out_port,
        EMAIL_MAX_PROF_PORT_LEN + 1,
        INPUT_TYPE_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[EMAIL_SMTP_OUT_PORT]);
    DisableInlineItemHighlight(&wgui_inline_items[EMAIL_SMTP_OUT_PORT]);

    /* caption of display name */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_DISP_NAME_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_DISP_NAME_CAP], (U8*) GetString(STR_EMAIL_DISPLAY_NAME_ID));

    /* display name */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_DISP_NAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[EMAIL_SMTP_DISP_NAME],
        STR_EMAIL_DISPLAY_NAME_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.smtp_info.disp_name,
        EMAIL_PROF_DISP_NAME_LEN + 1,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SMTP_DISP_NAME], mmi_email_hilite_prof_full_edit);

    /* caption of email address */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_ADDR_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_ADDR_CAP], (U8*) GetString(STR_EMAIL_EMAIL_ADDRESS_ID));

    /* email address */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_ADDR], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[EMAIL_SMTP_ADDR], 
        STR_EMAIL_EMAIL_ADDRESS_ID, 
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN), 
        (U8*)email_p->prof_info.editing_prof.smtp_info.email_addr, 
        MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1, 
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES |INPUT_TYPE_ALPHANUMERIC_SENTENCECASE, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SMTP_ADDR], mmi_email_hilite_prof_full_edit_ext);

    /* caption of authentication */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_AUTH_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_AUTH_CAP], (U8*) GetString(STR_EMAIL_AUTH_ID));

    /* authentication */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_AUTH], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_SMTP_AUTH],
        EMAIL_PROF_AUTH_STATUS_ITEM,
        email_p->prof_info.editing_prof.smtp_info.auth_status,
        &email_p->prof_info.editing_prof.smtp_info.auth_flag);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[EMAIL_SMTP_AUTH], mmi_email_smtp_auth_option_handler);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_smtp_auth_option_handler
 * DESCRIPTION
 *  Highlight handler of the inline select for authentication
 * PARAMETERS
 *  item_index      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_smtp_auth_option_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if it is off */
    if (item_index == 0) 
    {
        ChangeLeftSoftkey(0, 0); /*not to show left softkey and no left softkey function*/
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(mmi_email_entry_prof_auth, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_auth
 * DESCRIPTION
 *  Entry Authentication setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_prof_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 auth_icons[EMAIL_AUTH_TOTAL_ITEM] = 
    {    
        IMG_EMAIL_AUTH_SAME_ID, 0,
        IMG_EMAIL_USER_NAME_ID, 0,
        IMG_EMAIL_PASSWORD_ID, 0
    };

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_AUTH, mmi_email_exit_prof_auth, NULL, NULL);
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_AUTH);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_PROF_AUTH, &inputBufferSize);

    mmi_email_prof_fill_auth_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_AUTH_TOTAL_ITEM, inputBuffer);
    }

    ShowCategory57Screen(
        STR_EMAIL_AUTH_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_AUTH_TOTAL_ITEM,
        (U16*) auth_icons,
        wgui_inline_items,
        0,
        guiBuffer);
    
    SetCategory57RightSoftkeyFunctions(mmi_email_auth_done_handler, mmi_email_auth_back_handler);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_auth_done_handler
 * DESCRIPTION
 *  Highlight handler of all common full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_auth_done_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_email_util_is_username_vaild((S8*) email_p->prof_info.editing_prof.smtp_info.user_name))
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_WRONG_USERNAME),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SMTP_USERNAME);
    }
    else if (((MMI_BOOL)email_p->prof_info.editing_prof.smtp_info.auth_same_flag == MMI_FALSE)
            && (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.smtp_info.user_name) == 0))
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_USER_NAME_EMPTY_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_SMTP_USERNAME);    
    }
    else
    {
        is_email_auth_inline_changed = (MMI_BOOL)get_wgui_inline_list_menu_status();
        GoBackHistory();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_auth_back_handler
 * DESCRIPTION
 *  Highlight handler of all common full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_auth_back_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_email_auth_inline_changed = (MMI_BOOL)get_wgui_inline_list_menu_status();
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_auth_inline_struct
 * DESCRIPTION
 *  Fill inline structure of AUTH setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_prof_fill_auth_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->prof_info.editing_prof.smtp_info.auth_same_status[0] = (U8*) GetString(STR_GLOBAL_NO);
    email_p->prof_info.editing_prof.smtp_info.auth_same_status[1] = (U8*) GetString(STR_GLOBAL_YES);

    /* caption of authentication same with incoming server */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_AUTH_SAME_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_AUTH_SAME_CAP], (U8*) GetString(STR_EMAIL_AUTH_SAME_ID));

    /* authentication same with incoming server */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_AUTH_SAME], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_SMTP_AUTH_SAME],
        EMAIL_PROF_AUTH_SAME_STATUS_ITEM,
        email_p->prof_info.editing_prof.smtp_info.auth_same_status,
        &email_p->prof_info.editing_prof.smtp_info.auth_same_flag);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[EMAIL_SMTP_AUTH_SAME], mmi_email_auth_same_option_handler);

    /* caption of username */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_USERNAME_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_USERNAME_CAP], (U8*) GetString(STR_EMAIL_USER_NAME_ID));

    /* username */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_USERNAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[EMAIL_SMTP_USERNAME],
        STR_EMAIL_USER_NAME_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.smtp_info.user_name,
        MMI_EMAIL_USR_MAX_LEN + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SMTP_USERNAME], mmi_email_hilite_prof_full_edit);

    /* caption of password */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_PASSWD_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SMTP_PASSWD_CAP], (U8*) GetString(STR_EMAIL_PASSWORD_ID));

    /* password */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SMTP_PASSWD], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[EMAIL_SMTP_PASSWD],
        STR_EMAIL_PASSWORD_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.smtp_info.passwd,
        MMI_EMAIL_PASS_MAX_LEN + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SMTP_PASSWD], mmi_email_hilite_prof_full_edit);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_auth_same_option_handler
 * DESCRIPTION
 *  Highlight handler of the inline select for same with incoming server
 * PARAMETERS
 *  item_index      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_auth_same_option_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 1) /*if it is yes*/
    {
        DisableInlineItem(&(wgui_inline_items[EMAIL_SMTP_USERNAME]), EMAIL_SMTP_USERNAME);
        Category57ChangeItemText(EMAIL_SMTP_USERNAME, (U8*) wgui_inline_items[EMAIL_SMTP_USERNAME].text_p);

        DisableInlineItem(&(wgui_inline_items[EMAIL_SMTP_PASSWD]), EMAIL_SMTP_PASSWD);
        Category57ChangeItemText(EMAIL_SMTP_PASSWD, (U8*) wgui_inline_items[EMAIL_SMTP_PASSWD].text_p);
    }
    else
    {
        EnableInlineItem(&(wgui_inline_items[EMAIL_SMTP_USERNAME]), EMAIL_SMTP_USERNAME);
        Category57ChangeItemText(
            EMAIL_SMTP_USERNAME,
            (U8*) wgui_inline_items[EMAIL_SMTP_USERNAME].text_p);

        EnableInlineItem(&(wgui_inline_items[EMAIL_SMTP_PASSWD]), EMAIL_SMTP_PASSWD);
        Category57ChangeItemText(
            EMAIL_SMTP_PASSWD,
            (U8*) wgui_inline_items[EMAIL_SMTP_PASSWD].text_p);
    }
    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_prof_auth
 * DESCRIPTION
 *  Exit function of SMTP setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_exit_prof_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    mmi_email_util_add_n_history(SCR_ID_EMAIL_PROF_AUTH, mmi_email_entry_prof_auth);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_full_edit
 * DESCRIPTION
 *  Highlight handler of all common full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_full_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
    SetLeftSoftkeyFunction(mmi_email_entry_comm_full_edit_opt, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*   mmi_email_hilite_prof_full_edit_ext
* DESCRIPTION
*   Highlight handler of full screen editor without newline symbol.
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void mmi_email_hilite_prof_full_edit_ext(void)
{
    ChangeLeftSoftkey (STR_GLOBAL_OPTIONS, 0);
    SetLeftSoftkeyFunction(mmi_email_entry_comm_full_edit_opt, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_editor_set_vk_keys(MMI_TRUE, g_email_allowed, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_done
 * DESCRIPTION
 *  Highlight handler of all common full screen editor -> Done option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
    SetKeyHandler(ConfirmInlineFullScreenEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_input_meth
 * DESCRIPTION
 *  Highlight handler of all common full screen editor -> Input Method option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_input_meth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RegisterInputMethodScreenCloseFunction(mmi_email_util_go_back_2_hist);
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryAPRequiredInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_input_meth_ext
 * DESCRIPTION
 *  Highlight handler of all common full screen editor -> Input Method option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_input_meth_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RegisterInputMethodScreenCloseFunction(mmi_email_util_go_back_2_hist);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_pop3_imap4
 * DESCRIPTION
 *  Entry POP3/IMAP4 setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_pop3_imap4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pop3_icons[EMAIL_POP3_TOTAL_ITEM] = 
    {
        IMG_EMAIL_INCOMING_SERVER_ID, 0,
        IMG_EMAIL_INCOMING_PORT_ID, 0,
        IMG_EMAIL_USER_NAME_ID, 0,
        IMG_EMAIL_PASSWORD_ID, 0,
        IMG_EMAIL_DOWNLOAD_OPTION_ID, 0,
        IMG_EMAIL_SERVER_COPY_ID, 0,
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
        IMG_EMAIL_DEL_AFTER_N_DAYS_ID, 0,
#endif
        IMG_EMAIL_DEL_SERVER_MAILS_ID, 0
    };
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    U16 imap4_icon[EMAIL_IMAP4_TOTAL_ITEM] = 
    {
        IMG_EMAIL_INCOMING_SERVER_ID, 0,
        IMG_EMAIL_INCOMING_PORT_ID, 0,
        IMG_EMAIL_USER_NAME_ID, 0,
        IMG_EMAIL_PASSWORD_ID, 0,
        IMG_EMAIL_DOWNLOAD_OPTION_ID, 0,
        IMG_EMAIL_DRAFT_FOLDER_ID, 0,
        IMG_EMAIL_SENT_FOLDER_ID, 0
    };
#endif
    U16* pop3_imap4_icons;
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_POP3_IMAP4, mmi_email_exit_prof_pop3_imap4, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_POP3_IMAP4);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_PROF_POP3_IMAP4, &inputBufferSize);

    mmi_email_prof_fill_pop3_imap4_inline_struct();
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.editing_prof.setting_info.in_prot == MMI_EMAIL_PROTOCOL_POP3)
#endif
    {
        mmi_email_pop3_copy_on_server_option_init();
    }

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.editing_prof.setting_info.in_prot == MMI_EMAIL_PROTOCOL_IMAP4)
    {
        pop3_imap4_icons = imap4_icon;
        num_of_items = EMAIL_IMAP4_TOTAL_ITEM;
    }
    else
#endif
    {
        pop3_imap4_icons = pop3_icons;
        num_of_items = EMAIL_POP3_TOTAL_ITEM;
    }
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, num_of_items, inputBuffer);
    }
    ShowCategory57Screen(
        STR_EMAIL_POP3_IMAP4_SETTING_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        pop3_imap4_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_email_prof_save_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_prof_pop3_imap4
 * DESCRIPTION
 *  Exit function of POP3/IMAP4 setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_prof_pop3_imap4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_leading_zero(TRUE);
    mmi_email_util_add_n_history(SCR_ID_EMAIL_PROF_POP3_IMAP4, mmi_email_entry_prof_pop3_imap4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_save_pop3_imap4
 * DESCRIPTION
 *  Function to save POP3/IMAP4 setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_save_pop3_imap4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 IncomingPortNumber;
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    S32 n_days;
#endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    if (mmi_ucs2strlen((S8*)email_p->prof_info.editing_prof.pop_imap_info.in_port) == 0)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_PORT_NUMBER_EMPTY),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = EMAIL_INCOMING_IN_PORT;
        return;
    }
    IncomingPortNumber = gui_atoi((UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.in_port);
    if (IncomingPortNumber > EMAIL_MAX_PORT || IncomingPortNumber < EMAIL_MIN_PORT)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_PORT_NUMBER_OUTOF_RANGE),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = EMAIL_INCOMING_IN_PORT;
        return;
    }

    #ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    n_days = gui_atoi((UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days);
    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.pop_imap_info.in_port) == 0)
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        if (email_p->prof_info.editing_prof.setting_info.in_prot == EMAIL_PROT_POP3)
        {
            n_days = EMAIL_DEFAULT_N_DAYS;
        }
        else
        {
            n_days = 0;
        }
    #else /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
        n_days = EMAIL_DEFAULT_N_DAYS;
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ /*the last parameter indicate: decimal*/
        gui_itoa(n_days, (UI_string_type) email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days, 10);
    }
    #endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/

    if (!mmi_email_util_is_username_vaild((S8*) email_p->prof_info.editing_prof.pop_imap_info.user_name))
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_WRONG_USERNAME),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = (EMAIL_INCOMING_USERNAME);
        return;
    }
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    if ((MMI_BOOL) email_p->prof_info.editing_prof.pop_imap_info.copy_on_server == MMI_TRUE
        && (n_days > EMAIL_MAX_DEL_AFTER_N_DAYS || n_days < EMAIL_MIN_DEL_AFTER_N_DAYS)) 
    { 
        S8 *asciiMaxString = OslMalloc((EMAIL_MAX_N_DAYS_LEN + 1) * 2);
        S8 *ucs2MaxString = OslMalloc(((EMAIL_MAX_N_DAYS_LEN + 1) * 2) * ENCODING_LENGTH);

        if (n_days < EMAIL_MIN_DEL_AFTER_N_DAYS)
        {
            sprintf((S8*) asciiMaxString, "\n < %u", (U32) EMAIL_MIN_DEL_AFTER_N_DAYS);
        }
        else
        {
            sprintf((S8*) asciiMaxString, "\n > %u", (U32) EMAIL_MAX_DEL_AFTER_N_DAYS);
        }

        mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) GetString(STR_EMAIL_N_OF_DAYS));
        mmi_asc_to_ucs2((S8*) ucs2MaxString, (S8*) asciiMaxString);
        mmi_ucs2cat((S8*) email_p->comm_buff, (S8*) ucs2MaxString);
        mmi_email_util_display_popup(
            (U8*) email_p->comm_buff,
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
        email_p->prof_info.prof_misc.curr_hilite_indx = EMAIL_POP3_DEL_AFTER_N_DAYS;
        OslMfree(asciiMaxString);
        OslMfree(ucs2MaxString);
        return;
    }
#endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SAVING),
        NULL,
        IMG_GLOBAL_SAVE,
        NULL,
        NULL,
        NULL);
    mmi_email_ps_set_acct_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_pop3_imap4_inline_struct
 * DESCRIPTION
 *  Fill inline structure for POP/IMAP4 screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_fill_pop3_imap4_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On/Off inline selection */
    email_p->prof_info.prof_misc.copy_on_server[0] = (U8*) GetString(STR_GLOBAL_OFF);
    email_p->prof_info.prof_misc.copy_on_server[1] = (U8*) GetString(STR_GLOBAL_ON);
    email_p->prof_info.prof_misc.del_server_mails[0] = (U8*) GetString(STR_GLOBAL_OFF);
    email_p->prof_info.prof_misc.del_server_mails[1] = (U8*) GetString(STR_GLOBAL_ON);
    email_p->prof_info.prof_misc.download_opt[0] = (U8*) GetString(STR_EMAIL_DOWNLOAD_ALL);
    email_p->prof_info.prof_misc.download_opt[1] = (U8*) GetString(STR_EMAIL_HEADER_ONLY);
    email_p->prof_info.prof_misc.download_opt[2] = (U8*) GetString(STR_EMAIL_HEADER_TEXT);

    /* caption of incoming server */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_IN_SERVER_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_INCOMING_IN_SERVER_CAP], (U8*) GetString(STR_EMAIL_INCOMING_SERVER_ID));

    /* incoming server */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_IN_SERVER], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[EMAIL_INCOMING_IN_SERVER],
        STR_EMAIL_INCOMING_SERVER_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.pop_imap_info.in_server,
        MMI_EMAIL_MAX_SERVER_NAME + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_INCOMING_IN_SERVER], mmi_email_hilite_prof_full_edit);
    set_leading_zero(FALSE);

    /* caption of incoming port */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_IN_PORT_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_INCOMING_IN_PORT_CAP], (U8*) GetString(STR_EMAIL_INCOMING_PORT_ID));

    /* incoming port */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_IN_PORT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[EMAIL_INCOMING_IN_PORT],
        (U8*) email_p->prof_info.editing_prof.pop_imap_info.in_port,
        EMAIL_MAX_PROF_PORT_LEN + 1,
        INPUT_TYPE_NUMERIC);
    EnableInlineItemBoundary(&wgui_inline_items[EMAIL_INCOMING_IN_PORT]);
    DisableInlineItemHighlight(&wgui_inline_items[EMAIL_INCOMING_IN_PORT]);

    /* caption of username */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_USERNAME_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_INCOMING_USERNAME_CAP], (U8*) GetString(STR_EMAIL_USER_NAME_ID));

    /* username */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_USERNAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[EMAIL_INCOMING_USERNAME],
        STR_EMAIL_USER_NAME_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.pop_imap_info.user_name,
        MMI_EMAIL_USR_MAX_LEN + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_INCOMING_USERNAME], mmi_email_hilite_prof_full_edit);

    /* caption of password */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_PASSWD_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_INCOMING_PASSWD_CAP], (U8*) GetString(STR_EMAIL_PASSWORD_ID));

    /* password */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_PASSWD], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[EMAIL_INCOMING_PASSWD],
        STR_EMAIL_PASSWORD_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (U8*) email_p->prof_info.editing_prof.pop_imap_info.passwd,
        MMI_EMAIL_PASS_MAX_LEN + 1,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_INCOMING_PASSWD], mmi_email_hilite_prof_full_edit);

    /* caption of Download Option */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_DOWNLOAD_OPTION_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_INCOMING_DOWNLOAD_OPTION_CAP], (U8*) GetString(STR_EMAIL_DOWNLOAD_OPTION_ID));

    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.editing_prof.setting_info.in_prot == MMI_EMAIL_PROTOCOL_IMAP4)
    {
        SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_DOWNLOAD_OPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[EMAIL_INCOMING_DOWNLOAD_OPTION],
            EMAIL_PROF_DOWNLOAD_OPTION_STATUS_ITEM_IMAP4,
            email_p->prof_info.prof_misc.download_opt,
            &email_p->prof_info.editing_prof.pop_imap_info.download_opt);
    }    
    else
    #endif
    {
        SetInlineItemActivation(&wgui_inline_items[EMAIL_INCOMING_DOWNLOAD_OPTION], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[EMAIL_INCOMING_DOWNLOAD_OPTION],
            EMAIL_PROF_DOWNLOAD_OPTION_STATUS_ITEM_POP3,
            email_p->prof_info.prof_misc.download_opt,
            &email_p->prof_info.editing_prof.pop_imap_info.download_opt);
    }

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.editing_prof.setting_info.in_prot == MMI_EMAIL_PROTOCOL_POP3)
#endif
    {
        /* caption of copy on server */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_POP3_SERVER_COPY_CAP], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemCaption(&wgui_inline_items[EMAIL_POP3_SERVER_COPY_CAP], (U8*) GetString(STR_EMAIL_SERVER_COPY_ID));

        /* copy on server */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_POP3_SERVER_COPY], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[EMAIL_POP3_SERVER_COPY],
            EMAIL_PROF_SERVER_COPY_STATUS_ITEM,
            email_p->prof_info.prof_misc.copy_on_server,
            &email_p->prof_info.editing_prof.pop_imap_info.copy_on_server);
        RegisterInlineSelectHighlightHandler(&wgui_inline_items[EMAIL_POP3_SERVER_COPY], mmi_email_pop3_copy_on_server_option_handler);

#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
        /* caption of delete after n days */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS_CAP], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemCaption(&wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS_CAP], (U8*) GetString(STR_EMAIL_DEL_AFTER_N_DAYS_ID));

        /* delete after n days */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemTextEdit(
            &wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS],
            (U8*) email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days,
            EMAIL_MAX_N_DAYS_LEN + 1,
            INPUT_TYPE_NUMERIC);
        EnableInlineItemBoundary(&wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS]);
        DisableInlineItemHighlight(&wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS]);
#endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/

        /* caption of delete server mails */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS_CAP], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemCaption(&wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS_CAP], (U8*) GetString(STR_EMAIL_DEL_SERVER_MAILS_ID));

        /* delete server mails */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
        SetInlineItemSelect(
            &wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS],
            EMAIL_PROF_DEL_SERVER_STATUS_ITEM,
            email_p->prof_info.prof_misc.del_server_mails,
            &email_p->prof_info.editing_prof.pop_imap_info.del_server_mails);
    }    

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.editing_prof.setting_info.in_prot == MMI_EMAIL_PROTOCOL_IMAP4)
    {
        /* caption of draft folder */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_IMAP4_DRAFT_NAME_CAP], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemCaption(
            &wgui_inline_items[EMAIL_IMAP4_DRAFT_NAME_CAP],
            (U8*) GetString(STR_EMAIL_DRAFT_FOLDER_NAME));

        /* draft folder */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_IMAP4_DRAFT_NAME], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemFullScreenEdit_ext(
            &wgui_inline_items[EMAIL_IMAP4_DRAFT_NAME],
            STR_EMAIL_DRAFT_FOLDER_NAME,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            (U8*) email_p->prof_info.editing_prof.pop_imap_info.draft_name,
            (EMAIL_MAX_FLDR_NAME_LEN + 1),
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        SetInlineFullScreenEditCustomFunction(
            &wgui_inline_items[EMAIL_IMAP4_DRAFT_NAME],
            mmi_email_hilite_prof_full_edit);

        /* caption of sent folder */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_IMAP4_SENT_NAME_CAP], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemCaption(
            &wgui_inline_items[EMAIL_IMAP4_SENT_NAME_CAP],
            (U8*) GetString(STR_EMAIL_SENT_FOLDER_NAME));

        /* sent folder */
        SetInlineItemActivation(&wgui_inline_items[EMAIL_IMAP4_SENT_NAME], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemFullScreenEdit_ext(
            &wgui_inline_items[EMAIL_IMAP4_SENT_NAME],
            STR_EMAIL_SENT_FOLDER_NAME,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            (U8*) email_p->prof_info.editing_prof.pop_imap_info.sent_name,
            (EMAIL_MAX_FLDR_NAME_LEN + 1),
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        SetInlineFullScreenEditCustomFunction(
            &wgui_inline_items[EMAIL_IMAP4_SENT_NAME],
            mmi_email_hilite_prof_full_edit);
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_pop3_copy_on_server_option_init
 * DESCRIPTION
 *  Highlight handler of the inline select for delete server mails
 * PARAMETERS
 *  item_index      [IN]            
 *  a(?)            [IN/OUT]        Void
 *  b(?)            [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_pop3_copy_on_server_option_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_BOOL)email_p->prof_info.editing_prof.pop_imap_info.copy_on_server == MMI_FALSE) /*if it is off*/
    {
    #ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
        DisableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS]), EMAIL_POP3_DEL_AFTER_N_DAYS);
        Category57ChangeItemText(EMAIL_POP3_DEL_AFTER_N_DAYS, (U8*)email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days);
    #endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/
        DisableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS]), EMAIL_POP3_DEL_SERVER_MAILS);
        Category57ChangeItemText(EMAIL_POP3_DEL_SERVER_MAILS,
            (U8*) email_p->prof_info.prof_misc.del_server_mails[(MMI_BOOL)email_p->prof_info.editing_prof.pop_imap_info.del_server_mails]);
    }
    else /*the following may be canceled?*/
    {
    #ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
        EnableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS]), EMAIL_POP3_DEL_AFTER_N_DAYS);
        Category57ChangeItemText(
            EMAIL_POP3_DEL_AFTER_N_DAYS,
            (U8*)email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days);
    #endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/
        EnableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS]), EMAIL_POP3_DEL_SERVER_MAILS);
        Category57ChangeItemText(
            EMAIL_POP3_DEL_SERVER_MAILS,
            (U8*) email_p->prof_info.prof_misc.del_server_mails[(MMI_BOOL)email_p->prof_info.editing_prof.pop_imap_info.del_server_mails]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_pop3_copy_on_server_option_handler
 * DESCRIPTION
 *  Highlight handler of the inline select for delete server mails
 * PARAMETERS
 *  item_index      [IN]            
 *  a(?)            [IN/OUT]        Void
 *  b(?)            [IN]            Void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_pop3_copy_on_server_option_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 0) /*if it is off*/
    {
    #ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
        DisableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS]), EMAIL_POP3_DEL_AFTER_N_DAYS);
        Category57ChangeItemText(EMAIL_POP3_DEL_AFTER_N_DAYS, (U8*)email_p->prof_info.editing_prof.pop_imap_info.del_after_n_days);
    #endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/
        DisableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS]), EMAIL_POP3_DEL_SERVER_MAILS);
        Category57ChangeItemText(EMAIL_POP3_DEL_SERVER_MAILS, (U8*) wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS].text_p);
    }
    else
    {
    #ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
        EnableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS]), EMAIL_POP3_DEL_AFTER_N_DAYS);
        Category57ChangeItemText(
            EMAIL_POP3_DEL_AFTER_N_DAYS,
            (U8*) wgui_inline_items[EMAIL_POP3_DEL_AFTER_N_DAYS].text_p);
    #endif /*__MMI_EMAIL_DEL_AFTER_N_DAYS__*/
        EnableInlineItem(&(wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS]), EMAIL_POP3_DEL_SERVER_MAILS);
        Category57ChangeItemText(
            EMAIL_POP3_DEL_SERVER_MAILS,
            (U8*) wgui_inline_items[EMAIL_POP3_DEL_SERVER_MAILS].text_p);
    }
    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_is_activated
 * DESCRIPTION
 *  Determine is there any activated profile
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if one of the profiles is activated; otherwise, FALSE.
 *****************************************************************************/
U8 mmi_email_prof_is_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->prof_info.act_prof.act_indx < MMI_EMAIL_MAX_ACCTS)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_update_hint
 * DESCRIPTION
 *  Update hint value in main menu when profile changed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_update_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset all folders numbers */
    mmi_email_fldr_reset_cntx(EMAIL_RESET_ALL_FLDR);

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_POP3) || EMAIL_IS_MENU(MMI_EMAIL_UNSENT))
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    }
    else
    {
        email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
        email_p->fldr_info.curr_page = 1;

        /* the status bar icon will stay the same not reset unread email */
        /*email_p->main_info.unread_mails = 0;
        mmi_email_util_update_status_icon();*/
    }
#else /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
}

#define SIG_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_pre_entry_sig
 * DESCRIPTION
 *  Pre-Entry function of Signature setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_pre_entry_sig(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.img_name))
    {
        S8 *fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.editing_prof.sig_info.img_name);

        email_p->prof_info.prof_misc.sig_img_indx = 1;
        mmi_ucs2cpy(
            (S8*) email_p->prof_info.editing_prof.sig_info.file_name,
            (S8*) email_p->prof_info.editing_prof.sig_info.img_name);
        mmi_email_util_get_sig_name(
            (U8) (email_p->prof_info.prof_misc.curr_sel_prof + 1),
            (S8*) email_p->prof_info.editing_prof.sig_info.file_path);
        mmi_ucs2cat((S8*) email_p->prof_info.editing_prof.sig_info.file_path, (S8*) fileExt);
    }
    else
    {
        memset(
            email_p->prof_info.editing_prof.sig_info.file_name,
            0,
            sizeof(email_p->prof_info.editing_prof.sig_info.file_name));
        memset(
            email_p->prof_info.editing_prof.sig_info.file_path,
            0,
            sizeof(email_p->prof_info.editing_prof.sig_info.file_path));
        email_p->prof_info.prof_misc.sig_img_indx = 0;
    }

    mmi_ucs2cpy((S8*)email_sig_old_file_path, (S8*)email_p->prof_info.editing_prof.sig_info.file_path);
    email_p->prof_info.prof_misc.is_sig_changed = FALSE;
    mmi_email_entry_prof_sig();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_sig
 * DESCRIPTION
 *  Entry function of Signature setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_sig(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sig_icons[EMAIL_SIG_TOTAL_ITEM] = 
    {
        IMG_STATUS, 0,
        IMG_EMAIL_SIGNATURE_IMAGE_ID, 0,
        IMG_EMAIL_SIGNATURE_TEXT_ID, 0
    };

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_SIG, mmi_email_exit_prof_sig, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_SIG);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_PROF_SIG, &inputBufferSize);
    mmi_email_prof_fill_sig_inline_struct();
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_SIG_TOTAL_ITEM, inputBuffer);

        if (email_p->prof_info.prof_misc.is_sig_changed && GetInlineDoneFlag(guiBuffer) == 0)
        {
            SetInlineDoneFlag(guiBuffer);
        }
    }

    ShowCategory57Screen(
        STR_EMAIL_SIGNATURE_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_BACK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_SIG_TOTAL_ITEM,
        (U16*) sig_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_email_prof_save_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_prof_sig
 * DESCRIPTION
 *  Pre-Entry function of Signature setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_prof_sig(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_n_history(SCR_ID_EMAIL_PROF_SIG, mmi_email_entry_prof_sig);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_fill_sig_inline_struct
 * DESCRIPTION
 *  Fill inline structure for Profile->Signature screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_fill_sig_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* On/Off inline selection */
    email_p->prof_info.prof_misc.sig_status_list[0] = (U8*) GetString(STR_GLOBAL_OFF);
    email_p->prof_info.prof_misc.sig_status_list[1] = (U8*) GetString(STR_GLOBAL_ON);

    /* image inline selection */
    email_p->prof_info.prof_misc.sig_img_list[0] = (U8*) GetString(STR_GLOBAL_NONE);
    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.file_name))
    {
        email_p->prof_info.prof_misc.sig_img_list[1] = (U8*) email_p->prof_info.editing_prof.sig_info.file_name;
    }
    else
    {
        email_p->prof_info.prof_misc.sig_img_list[1] = (U8*) GetString(STR_EMAIL_SELECT_FROM_FILE_ID);
    }

    /* Status caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SIG_STATUS_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SIG_STATUS_CAP], (PU8) GetString(STR_EMAIL_SIGNATURE_ON_OFF_ID));

    /* Status */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SIG_STATUS], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_SIG_STATUS],
        EMAIL_PROF_SIG_STATUS_ITEM,
        email_p->prof_info.prof_misc.sig_status_list,
        &email_p->prof_info.editing_prof.sig_info.sig_status);

    /* Image caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SIG_IMAGE_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SIG_IMAGE_CAP], (PU8) GetString(STR_EMAIL_SIGNATURE_IMAGE_ID));

    /* Image */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SIG_IMAGE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_SIG_IMAGE],
        EMAIL_PROF_SIG_IMG_ITEM,
        email_p->prof_info.prof_misc.sig_img_list,
        &email_p->prof_info.prof_misc.sig_img_indx);
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[EMAIL_SIG_IMAGE], mmi_email_hilite_prof_sig_inline_sel);

    /* Text caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SIG_TEXT_CAP], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_SIG_TEXT_CAP], (PU8) GetString(STR_EMAIL_SIGNATURE_TEXT_ID));

    /* Text */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_SIG_TEXT], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit(
        &wgui_inline_items[EMAIL_SIG_TEXT],
        STR_EMAIL_SIGNATURE_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        (PU8) email_p->prof_info.editing_prof.sig_info.sig_buff,
        (EMAIL_MAX_SIG_LEN + 1),
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[EMAIL_SIG_TEXT], mmi_email_hilite_prof_full_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_sig_inline_sel
 * DESCRIPTION
 *  Highlight handler of selection sig image
 * PARAMETERS
 *  index       [IN]        Index of inline selection item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_sig_inline_sel(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(0, 0);
    if (index != 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetCategory57LeftSoftkeyFunction(mmi_email_entry_prof_sig_sel_file);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_sig_sel_attach_callback
 * DESCRIPTION
 *  Callback function for selected image of signature from File Manager
 * PARAMETERS
 *  filePath        [IN]        File path+name from File Manager
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_sig_sel_attach_callback(void *filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    U8 mime_type, mime_subtype;
#endif
    U16 image_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_EMAIL_PROF_SIG_SEL_FILE);
    }
    else
    {
        S32 fileLen;
        S32 dirLen;
        S8 *fileName;
        S32 f_result;
#ifdef __MMI_EMAIL_DRM_SUPPORT__    
        mmi_email_util_get_mine_type(
            (S8*) filePath,
            &mime_type,
            &mime_subtype);
        if ((mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) || (DRM_interdev_movable(0, (kal_wchar*)filePath) == MMI_FALSE))
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }
#endif
        if ((f_result = mmi_email_util_get_file_size(filePath, &fileLen)) == FS_NO_ERROR)
        {
            if (fileLen == 0)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_EMPTY_FILE_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                return;
            }
            else if (fileLen > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) WARNING_TONE);
                return;
            }
            else if ((U32)fileLen >= mmi_email_get_disk_free_blocks())
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_NO_SPACE_ID),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                return;
            }
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString((U16) GetFileSystemErrorString(f_result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteUptoScrID(SCR_ID_EMAIL_PROF_SIG_SEL_FILE);
            return;
        }
        
        image_type = gdi_image_get_type_from_file((S8*) filePath);
        if ((image_type != GDI_IMAGE_TYPE_JPG_FILE) && 
            (image_type != GDI_IMAGE_TYPE_GIF_FILE) &&
            (image_type != GDI_IMAGE_TYPE_BMP_FILE) &&
#if defined(GDI_USING_PNG)
            (image_type != GDI_IMAGE_TYPE_PNG_FILE) &&
#endif
            (image_type != GDI_IMAGE_TYPE_WBMP_FILE))
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }

        /* proceed adding attachment */
        if (email_p->other_app_info.fmgr_path == NULL)
        {
            email_p->other_app_info.fmgr_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        }
        mmi_ucs2cpy((S8*) email_p->other_app_info.fmgr_path, (S8*) filePath);
        /* extract file name and path */
        dirLen = (S32) mmi_fmgr_get_last_dir_index((S8*) email_p->other_app_info.fmgr_path);
        fileName = (S8*) email_p->other_app_info.fmgr_path;
        fileName += dirLen;
        
        if (is_short)
        {
            S8* fmgr_name = OslMalloc((FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
            U8 encoding = PhnsetGetDefEncodingType();
            
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) fmgr_name,
                FMGR_PATH_BUFFER_SIZE,
                (U8*) fileName,
                (mmi_chset_enum)encoding);
            mmi_ucs2cpy(fileName, fmgr_name);
            OslMfree(fmgr_name);
        }
        mmi_ucs2cpy((S8*) email_p->prof_info.editing_prof.sig_info.file_name, (S8*) fileName);
        mmi_ucs2cpy((S8*) email_p->prof_info.editing_prof.sig_info.file_path, (S8*) filePath);

        /* change RSK of signature screen to Done */
        email_p->prof_info.prof_misc.is_sig_changed = TRUE;

        GoBackToHistory(SCR_ID_EMAIL_PROF_SIG_SEL_FILE);
        OslMfree(email_p->other_app_info.fmgr_path);
        email_p->other_app_info.fmgr_path = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_sig_sel_attach
 * DESCRIPTION
 *  Enter file manager to select an image file for signature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_sig_sel_attach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    /* use APP_SETTINGS because of DRM -- signature shall not be DRM file */
    mmi_fmgr_select_path_and_enter(
        APP_EMAIL,
#ifdef __DRM_V02__
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
#else
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif
        filter,
        (S8*) L"root",
        mmi_email_prof_sig_sel_attach_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_sig_view
 * DESCRIPTION
 *  highlight handler for Signature -> View option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_sig_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_prof_sig_view_attach, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_prof_sig_view_attach, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_sig_select
 * DESCRIPTION
 *  highlight handler for Signature -> Select option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_sig_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_prof_sig_sel_attach, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_prof_sig_sel_attach, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_sig_del
 * DESCRIPTION
 *  highlight handler for Signature -> Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_sig_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_prof_sig_del_attach, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_prof_sig_del_attach, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof_sig_inline_item
 * DESCRIPTION
 *  Highlight handler for inline items in Signature screen
 * PARAMETERS
 *  index           [IN]        
 *  index(?)        [IN]        Index of inline item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof_sig_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index != 2)
    {
        /* if current highlighted item is Image, and the value is not "none" */
        if ((index == 1) && (email_p->prof_info.prof_misc.sig_img_indx != 0))
        {
            mmi_email_hilite_prof_sig_inline_sel(email_p->prof_info.prof_misc.sig_img_indx);
        }

        SetCategory57RightSoftkeyFunctions(mmi_email_prof_save_confirm, GoBackHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_save_sig
 * DESCRIPTION
 *  Save function for Signature
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_save_sig(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 is_attach;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_attach = ((email_p->prof_info.prof_misc.sig_img_indx > 0) &&
                 (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.file_name)));

    if (email_p->prof_info.editing_prof.sig_info.sig_status)
    {
        /* both text and image are empty */
        if (!mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.sig_buff) && !is_attach)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_SIG_EMPTY_WARNING),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }
    }

    if (is_attach)
    {
        S8 *dest_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        S8 *fileExt;

        /* send request to copy file */
        mmi_ucs2cpy(
            (S8*) email_p->prof_info.editing_prof.sig_info.img_name,
            (S8*) email_p->prof_info.editing_prof.sig_info.file_name);
        fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.editing_prof.sig_info.img_name);
        mmi_email_util_get_sig_name((U8) (email_p->prof_info.prof_misc.curr_sel_prof + 1), (S8*) dest_path);
        mmi_ucs2cat((S8*) dest_path, (S8*) fileExt);

        mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) dest_path);
        OslMfree(dest_path);
        if (mmi_ucs2cmp((S8*) email_p->prof_info.editing_prof.sig_info.file_path, (S8*) email_p->comm_buff) != 0)
        {
            mmi_email_util_reset_file_attr(email_p->comm_buff);
            ret = FS_Delete((U16*) email_p->comm_buff);
            if (ret < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PROF_SAVE_SIG_DEL_FILE_NEW, ret);
            }
            mmi_fmgr_send_copy_req(
                FMGR_ACTION_COPY,
                (U8*) email_p->prof_info.editing_prof.sig_info.file_path,
                (U8*) email_p->comm_buff,
                mmi_email_prof_sig_save_file_callback);
            mmi_email_pre_entry_progressing(
                STR_EMAIL_MAIN_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                0,
                0,
                (U8*) GetString(STR_GLOBAL_SAVING),
                NULL,
                IMG_GLOBAL_SAVE,
                NULL,
                NULL,
                NULL);
            return;
        }
    }
    else
    {
        email_p->prof_info.editing_prof.sig_info.img_name[0] = 0;
        email_p->prof_info.editing_prof.sig_info.img_name[1] = 0;
        if (mmi_ucs2strlen((PS8)email_sig_old_file_path) != 0)
        {
            mmi_email_util_reset_file_attr(email_sig_old_file_path);
            ret = FS_Delete((U16*) email_sig_old_file_path);
            if (ret < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PROF_SAVE_SIG_DEL_FILE_OLD, ret);
            }
        }
    }

    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_SAVING),
        NULL,
        IMG_GLOBAL_SAVE,
        NULL,
        NULL,
        NULL);
    mmi_email_ps_set_acct_profile_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_sig_save_file_callback
 * DESCRIPTION
 *  Callback function for saving image file of signature.
 * PARAMETERS
 *  info        [IN]        Variable stores the result of copy
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_sig_save_file_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    if (msgPtr->result >= 0)
    {
        S32 attr = 0, ret = 0;

        if ((strcmp((S8*)email_sig_old_file_path, "") != 0) &&
            (mmi_ucs2cmp((S8*) email_p->comm_buff, (S8*) email_sig_old_file_path) != 0))
        {
            mmi_email_util_reset_file_attr(email_sig_old_file_path);
            ret = FS_Delete((U16*) email_sig_old_file_path);
            if (ret < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_PROF_SIG_SAVE_FILE_CALLBACK_DEL_FILE_OLD, ret);
            }
        }
        attr = FS_GetAttributes((const WCHAR*) email_p->comm_buff);
        if (attr & FS_ATTR_READ_ONLY)
        {
            FS_SetAttributes((const WCHAR*) email_p->comm_buff, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
        }
        mmi_email_ps_set_acct_profile_req();
    }
    else
    {
        mmi_email_util_display_popup(
            (PU8) GetString((U16) GetFileSystemErrorString(msgPtr->result)),
            IMG_GLOBAL_ERROR,
            0,
            1000,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_sig_sel_file
 * DESCRIPTION
 *  Entry Signature -> Select From File screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_sig_sel_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];    /* only 3 options */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROF_SIG_SEL_FILE, NULL, mmi_email_entry_prof_sig_sel_file, NULL);

    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.file_name) == 0)       /* empty */
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW);
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROF_SIG_SEL_FILE);
    SetParentHandler(MENU_ID_EMAIL_SIG_ATTCH_OPT);
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_SIG_ATTCH_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_SIG_ATTCH_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_EMAIL_SIG_ATTACH_OPTION_IMAGES_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_prof_sig_view_attach
 * DESCRIPTION
 *  Entry Signature -> Select From File -> View
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_prof_sig_view_attach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_DRM_SUPPORT__    
    U8 method = DRM_METHOD_NONE;
    FS_HANDLE fileHandle;
#endif
    S32 f_result;
    S32 fmgr_type = 0;
    FMGR_FILTER fmgr_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.file_path))
    {
        if ((f_result = mmi_email_util_check_file_exist((S8*) email_p->prof_info.editing_prof.sig_info.file_path)) != FS_NO_ERROR)
        {
            email_p->prof_info.prof_misc.is_sig_changed = TRUE;
            memset(
                email_p->prof_info.editing_prof.sig_info.file_name,
                0,
                sizeof(email_p->prof_info.editing_prof.sig_info.file_name));
            memset(
                email_p->prof_info.editing_prof.sig_info.file_path,
                0,
                sizeof(email_p->prof_info.editing_prof.sig_info.file_path));
            mmi_email_util_display_popup(
                (U8*) GetString((U16) GetFileSystemErrorString(f_result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if ((fileHandle = DRM_open_file(
            (UI_string_type)email_p->prof_info.editing_prof.sig_info.file_path, 
            FS_READ_ONLY, 
            DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
        {
            if ((method = DRM_get_object_method(fileHandle, NULL)) != DRM_METHOD_NONE)
            {
                if (DRM_validate_permission(fileHandle, NULL, DRM_PERMISSION_DISPLAY) == MMI_FALSE)
                {
                    if (method & DRM_METHOD_SEPARATE_DELIVERY)
                    {
                        U32 size = sizeof(rights_issuer);
                        /* request rights from server */
                        memset(rights_issuer, 0, sizeof(rights_issuer));
                        if(FS_NO_ERROR <= DRM_get_rights_issuer(fileHandle, rights_issuer, &size))
                        {
                            if (
                        #ifdef __FLIGHT_MODE_SUPPORT__
                                (mmi_bootup_get_active_flight_mode() == 0) &&
                        #endif
                                (mmi_bootup_is_network_service_available() == TRUE))
                            {
                        #ifdef WAP_SUPPORT
                                mmi_email_display_confirm(STR_FMGR_REQ_RIGHTS, mmi_email_request_rights, GoBackHistory);
                        #else
                                mmi_email_util_display_popup(
                                    (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                                    IMG_GLOBAL_WARNING,
                                    0,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) WARNING_TONE);
                        #endif
                                DRM_close_file(fileHandle);
                                return;
                            }
                        }
                    }
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) WARNING_TONE);
                    DRM_close_file(fileHandle);
                    return;
                }
            }
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_PROF_SIG_VIEW_ATTACH_DRM, method);
            DRM_close_file(fileHandle);
        }
        else
        {
            /* open file fail */
            mmi_email_util_display_popup((PU8) GetString(GetFileSystemErrorString(fileHandle)),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
#endif /* __DRM_SUPPORT__ */ 
        
        FMGR_FILTER_INIT(&fmgr_set);
        fmgr_type = mmi_fmgr_get_file_type_by_filename((PS8)email_p->prof_info.editing_prof.sig_info.file_path);
        FMGR_FILTER_SET(&fmgr_set, fmgr_type);
        mmi_imgview_view_image_hdlr(
            (PS8)email_p->prof_info.editing_prof.sig_info.file_path,
            MMI_FALSE,
            fmgr_set,
            GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_sig_del_attach
 * DESCRIPTION
 *  Entry Signature -> Select From File -> Delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_sig_del_attach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) email_p->prof_info.editing_prof.sig_info.file_path))
    {
        /* change RSK of signature screen to Done */
        email_p->prof_info.prof_misc.is_sig_changed = TRUE;

        memset(email_p->prof_info.editing_prof.sig_info.file_path, 0, ENCODING_LENGTH);
        memset(email_p->prof_info.editing_prof.sig_info.file_name, 0, ENCODING_LENGTH);
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_save_confirm
 * DESCRIPTION
 *  Display confirmation screen for Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->prof_info.prof_misc.curr_scr)
    {
        case SCR_ID_EMAIL_PROF_SETTING:
            func = mmi_email_prof_save_setting;
            break;
        case SCR_ID_EMAIL_PROF_SMTP:
            func = mmi_email_prof_save_smtp;
            break;
        case SCR_ID_EMAIL_PROF_POP3_IMAP4:
            func = mmi_email_prof_save_pop3_imap4;
            break;
        default:    /* case SCR_ID_EMAIL_PROF_SIG: */
            func = mmi_email_prof_save_sig;
            break;
    }
    mmi_email_display_confirm(STR_EMAIL_COMMON_SAVE_CHANGES_ID, func, mmi_email_prof_go_back_to_edit_menu);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_prof_go_back_to_edit_menu
 * DESCRIPTION
 *  Delete all screen after Profile -> Edit screen and go back to Edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_prof_go_back_to_edit_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_EMAIL_PROF_OPT_EDIT);
    GoBackHistory();
}
#endif /* __MMI_EMAIL__ */
#endif /* MMI_EMAILAPPACCOUNT_C */

