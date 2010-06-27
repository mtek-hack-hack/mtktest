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
 * BrowserSettingsUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contain the function definations for UI implementation 
 *   of browser settings.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERSETTINGSUI_C
#define MMI_BROWSERSETTINGSUI_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserSettings.h"
#include "PushInboxProts.h"


U8  gBrwTimeoutValue[(BRW_TIME_OUT_LEN + 1) * ENCODING_LENGTH];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_highlight_handlers_init
 * DESCRIPTION
 *  Set highlight handlers for settings menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_highlight_handlers_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_BRW_SETTINGS, mmi_brw_settings_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SETTINGS, mmi_brw_ren_page_settings_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_EDIT_PROFILE, mmi_brw_settings_edit_profile_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_HOMEPAGE_SETTINGS, mmi_brw_settings_homepage_settings_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS, mmi_brw_settings_browser_options_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_PREFERENCES, mmi_brw_settings_browser_preferences_highlight_hdlr);
#if defined (WAP_SEC_SUPPORT)
    SetHiliteHandler(MENU_ID_BRW_SECURITY_SETTINGS, mmi_brw_settings_security_settings_highlight_hdlr);
#endif /*WAP_SEC_SUPPORT*/
    SetHiliteHandler(MENU_ID_BRW_PUSH_SETTINGS, mmi_brw_settings_push_settings_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RESTORE_BROWSER_SETTINGS, mmi_brw_settings_restore_browser_settings_highlight_hdlr);

	/*Homepage Settings*/
    SetHiliteHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE, mmi_brw_settings_user_defined_hmpage_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_ACTIVATE, mmi_brw_settings_user_defined_hmpage_activate_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY, mmi_brw_settings_user_defined_hmpage_modify_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_VIEW, mmi_brw_settings_user_defined_hmpage_view_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_USE_CURRENT_PAGE, mmi_brw_settings_user_defined_hmpage_use_current_page_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_USE_BLANK, mmi_brw_settings_user_defined_hmpage_use_blank_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_EDIT, mmi_brw_settings_user_defined_hmpage_edit_highlight_hdlr);

    SetHiliteHandler(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE, mmi_brw_settings_active_profile_hmpage_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_ACTIVATE, mmi_brw_settings_active_profile_hmpage_activate_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_EDIT, mmi_brw_settings_active_profile_hmpage_edit_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_VIEW, mmi_brw_settings_active_profile_hmpage_view_highlight_hdlr);
	/*Homepage Settings*/

	mmi_brw_settings_browser_options_highlight_handlers_init();

#if defined (WAP_SEC_SUPPORT)
	mmi_brw_settings_security_setting_highlight_handlers_init();
#endif /*WAP_SEC_SUPPORT*/

}


#if defined (WAP_SEC_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_highlight_handlers_init
 * DESCRIPTION
 *  Set highlight handlers for settings menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_security_setting_highlight_handlers_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_BRW_SECURITY_SETTINGS_SESSION_INFO, mmi_brw_security_settings_session_info_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SECURITY_SETTINGS_CURRENT_CERTIFICATE, mmi_brw_security_settings_current_certificate_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SECURITY_SETTINGS_TRUSTED_CERTIFICATES, mmi_brw_security_settings_trusted_certificates_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_VIEW, mmi_brw_security_settings_trusted_certificates_view_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS_DELETE, mmi_brw_security_settings_trusted_certificates_delete_highlight_hdlr);
}
#endif /*WAP_SEC_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_options_highlight_handlers_init
 * DESCRIPTION
 *  Set highlight handlers for browser options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_options_highlight_handlers_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*Highlight Handlers*/
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES, mmi_brw_settings_rendering_modes_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES, mmi_brw_settings_navigation_modes_highlight_hdlr);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE, mmi_brw_settings_font_size_highlight_hdlr);
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL, mmi_brw_settings_thumbnail_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE, mmi_brw_settings_screen_size_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_ENCODING, mmi_brw_settings_encoding_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_CACHE, mmi_brw_settings_clear_cache_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_COOKIE, mmi_brw_settings_clear_cookie_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_CLEAR_AUTH_INFO, mmi_brw_settings_clear_auth_info_highlight_hdlr);
	/*Highlight Handlers*/

	/*Hint Handlers*/
    SetHintHandler(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES, mmi_brw_settings_rendering_modes_hint_hdlr);
    SetHintHandler(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES, mmi_brw_settings_navigation_modes_hint_hdlr);
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
    SetHintHandler(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE, mmi_brw_settings_font_size_hint_hdlr);
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 
    SetHintHandler(MENU_ID_BRW_BROWSER_OPTIONS_THUMBNAIL, mmi_brw_settings_thumbnail_hint_hdlr);
    SetHintHandler(MENU_ID_BRW_BROWSER_OPTIONS_SCREEN_SIZE, mmi_brw_settings_screen_size_hint_hdlr);
    SetHintHandler(MENU_ID_BRW_BROWSER_OPTIONS_ENCODING, mmi_brw_settings_encoding_hint_hdlr);
	/*Hint Handlers*/

	/*Rendering Modes*/
    SetHiliteHandler(MENU_ID_BRW_RENDERING_MODES_STANDARD, mmi_brw_settings_rendering_modes_standard_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RENDERING_MODES_TEXT_WRAP, mmi_brw_settings_rendering_modes_text_wrap_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RENDERING_MODES_SCREEN_OPTIMIZED, mmi_brw_settings_rendering_modes_screen_optimized_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_RENDERING_MODES_TEXT_ONLY, mmi_brw_settings_rendering_modes_text_only_highlight_hdlr);
	/*Rendering Modes*/

	/*Navigation Modes*/
    SetHiliteHandler(MENU_ID_BRW_NAVIGATION_MODES_FOUR_WAY, mmi_brw_settings_navigation_modes_four_way_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_NAVIGATION_MODES_TWO_WAY, mmi_brw_settings_navigation_modes_two_way_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_NAVIGATION_MODES_SCROLLING, mmi_brw_settings_navigation_modes_scrolling_highlight_hdlr);
	/*Navigation Modes*/

	/*Font Size*/
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_SMALL, mmi_brw_settings_font_size_small_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_MEDIUM, mmi_brw_settings_font_size_medium_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE_LARGE, mmi_brw_settings_font_size_large_highlight_hdlr);
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 
	/*Font Size*/
}


/****************************************** HIGHLIGHT HANDLERS - START *****************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Settings in WAP browser main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_entry_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_settings_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Settings on rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_ren_page_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_ren_page_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_edit_profile_highlight_hdlr
 * DESCRIPTION
 *  Entry function for profile menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_edit_profile_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_show_profile_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_show_profile_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_homepage_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_homepage_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_homepage_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_homepage_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_user_defined_homepage, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_user_defined_homepage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_active_profile_homepage, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_active_profile_homepage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_activate_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_activate_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_user_defined_hmpage_activate_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_modify_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_modify_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_user_defined_hmpage_entry_modify, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_user_defined_hmpage_entry_modify, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_activate_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_activate_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_active_profile_hmpage_activate_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_edit_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_active_profile_hmpage_entry_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_view_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_view_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_active_profile_hmpage_entry_view, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_use_current_page_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_use_current_page_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_set_current_page_as_user_defined_homepage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_use_blank_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_use_blank_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_set_blank_as_user_defined_homepage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_edit_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_user_defined_hmpage_entry_edit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_view_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_view_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_user_defined_hmpage_entry_view, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_options_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_options_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_browser_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_browser_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_browser_preferences, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_browser_preferences, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#if defined (WAP_SEC_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_security_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_security_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_security_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_security_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_session_info_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_session_info_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_brw_security_settings_get_session_info_req, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_current_certificate_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_current_certificate_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_brw_security_settings_get_current_certificate_req, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_brw_security_settings_get_trusted_certificate_ids_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_security_settings_get_trusted_certificate_ids_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_view_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_view_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_security_settings_trusted_certificates_entry_view, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_delete_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_security_settings_trusted_certificates_delete, KEY_EVENT_UP);
}
#endif /*WAP_SEC_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_restore_browser_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_restore_browser_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_restore_browser_settings_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_push_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_push_settings_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_phs_pre_entry_push_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_phs_pre_entry_push_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for rendering modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_rendering_modes, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_rendering_modes, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for rendering modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_navigation_modes, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_navigation_modes, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#ifdef BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for setting font size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_font_size, KEY_EVENT_UP);
}
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_thumbnail_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for enabling/disabling thumbnail view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_thumbnail_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_brw_cntx.thumbnail_status)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
   
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(mmi_brw_settings_update_thumbnail_status, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_screen_size_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for enabling/disabling thumbnail view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_screen_size_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_brw_cntx.screen_size_status)
    {
        ChangeLeftSoftkey(STR_ID_BRW_NORMAL, 0);
    }
    else
    {
        ChangeLeftSoftkey(STR_ID_BRW_FULL, 0);
    }
   
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetLeftSoftkeyFunction(mmi_brw_settings_update_screen_size, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_encoding_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for enabling/disabling thumbnail view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_encoding_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_entry_encoding_methods, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_settings_entry_encoding_methods, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_cache_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for enabling/disabling thumbnail view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_cache_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_clear_cache_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_cookie_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for enabling/disabling thumbnail view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_cookie_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_clear_cookie_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_auth_info_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for enabling/disabling thumbnail view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_auth_info_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_clear_auth_info_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_items_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_items_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_brw_settings_browser_preferences_confirm_save, KEY_EVENT_UP);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

	switch(g_brw_cntx.rendering_mode)
	{
		case wap_bam_setting_val_rend_normal:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_STANDARD));
			break;
		}
		case wap_bam_setting_val_rend_wrap:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_TEXT_WRAP));
			break;
		}
		case wap_bam_setting_val_rend_narrow:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_SCREEN_OPTIMIZED));
			break;
		}
		case wap_bam_setting_val_rend_text:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_TEXT_ONLY));
			break;
		}
		default:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_STANDARD));
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

	switch(g_brw_cntx.navigation_mode)
	{
		case wap_bam_setting_val_nav_4_way:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_FOUR_WAY));
			break;
		}
		case wap_bam_setting_val_nav_2_way:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_TWO_WAY));
			break;
		}
		case wap_bam_setting_val_nav_scroll:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_SCROLLING));
			break;
		}
		default:
		{
			mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_FOUR_WAY));
			break;
		}
	}
}


#ifdef BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

	switch(g_brw_cntx.font_size)
	{
		case BRW_FONT_SIZE_SMALL:
		{
	        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_SMALL));
			break;
		}
		case BRW_FONT_SIZE_MEDIUM:
		{
	        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_MEDIUM));
			break;
		}
		case BRW_FONT_SIZE_LARGE:
		{
	        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_LARGE));
			break;
		}
		default:
		{
	        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_MEDIUM));
			break;
		}
	}
}
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_thumbnail_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_thumbnail_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    if (g_brw_cntx.thumbnail_status)
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
 *  mmi_brw_settings_screen_size_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_screen_size_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));
    if (g_brw_cntx.screen_size_status)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_FULL));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_ID_BRW_NORMAL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_encoding_hint_hdlr
 * DESCRIPTION
 *  Hint Handler of service messages.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_encoding_hint_hdlr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) hintData[index], 0, sizeof(hintData[index]));

	mmi_ucs2cpy((S8*) hintData[index], 
		(S8*) GetString((U16)g_brw_cntx.charset_list_p[g_brw_cntx.encoding_method_index].name_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_standard_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_standard_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_rendering_modes_standard, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_text_wrap_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_text_wrap_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_rendering_modes_text_wrap, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_screen_optimized_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_screen_optimized_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_rendering_modes_screen_optimized, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_text_only_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_text_only_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_rendering_modes_text_only, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_four_way_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_four_way_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_navigation_modes_four_way, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_two_way_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_two_way_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_navigation_modes_two_way, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_scrolling_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_scrolling_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_navigation_modes_scrolling, KEY_EVENT_UP);
}


#ifdef BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_small_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_small_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_font_size_small, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_medium_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_medium_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_font_size_medium, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_large_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for homepage settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_large_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_brw_settings_font_size_large, KEY_EVENT_UP);
}
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_editor_done_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_editor_done_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_active_profile_hmpage_save, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_editor_done_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_editor_done_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_settings_user_defined_hmpage_save, KEY_EVENT_UP);
}
/****************************************** HIGHLIGHT HANDLERS - END *******************************************/


/******************************************* ENTRY FUNCTIONS - START *******************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_settings
 * DESCRIPTION
 *  Entry function for settings screen from main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SETTINGS, NULL, mmi_brw_entry_settings, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SETTINGS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_SETTINGS);
    GetSequenceStringIds(MENU_ID_BRW_SETTINGS, nStrItemList);
    SetParentHandler(MENU_ID_BRW_SETTINGS);
    ConstructHintsList(MENU_ID_BRW_SETTINGS, nHintList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_SETTINGS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_ren_page_settings
 * DESCRIPTION
 *  Entry function for settings screen from rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_ren_page_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_REN_PAGE_SETTINGS, NULL, mmi_brw_settings_entry_ren_page_settings, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_REN_PAGE_SETTINGS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_REN_PAGE_SETTINGS);
    GetSequenceStringIds(MENU_ID_BRW_REN_PAGE_SETTINGS, nStrItemList);
    SetParentHandler(MENU_ID_BRW_REN_PAGE_SETTINGS);
    ConstructHintsList(MENU_ID_BRW_REN_PAGE_SETTINGS, nHintList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_SETTINGS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_cache_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_cache_confirm(void)
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
        get_string(STR_ID_BRW_CLEAR_CACHE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_settings_clear_cache, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_cookie_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cookies.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_cookie_confirm(void)
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
        get_string(STR_ID_BRW_CLEAR_COOKIE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_settings_clear_cookie, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_clear_auth_info_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_clear_auth_info_confirm(void)
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
        get_string(STR_ID_BRW_CLEAR_AUTH_INFO),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_settings_clear_auth_info, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_homepage_settings
 * DESCRIPTION
 *  Entry function for homepage settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_homepage_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8  nIndex;
    U8 *guiBuffer_p;
    U8  *menuStringList[MAX_SUB_MENUS];
	U16 menuStringIDList[MAX_SUB_MENUS];
    U16 nNumofItems;
    U16 image_list[MAX_SUB_MENUS] = {0, };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_HOMEPAGE_SETTINGS, NULL, mmi_brw_settings_entry_homepage_settings, NULL);
    guiBuffer_p = GetCurrGuiBuffer(SCR_ID_BRW_HOMEPAGE_SETTINGS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItems = GetNumOfChild(MENU_ID_BRW_HOMEPAGE_SETTINGS);
    GetSequenceStringIds(MENU_ID_BRW_HOMEPAGE_SETTINGS, menuStringIDList);
    SetParentHandler(MENU_ID_BRW_HOMEPAGE_SETTINGS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    image_list[g_brw_cntx.homepage_settings_index] = IMG_ID_BRW_ACTIVE_HMPAGE_SETTINGS;

	for(nIndex=0; nIndex<nNumofItems; nIndex++)
	{
		menuStringList[nIndex] = (U8*) GetString(menuStringIDList[nIndex]);
	}

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_BRW_HOMEPAGE_SETTINGS),
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItems,
        menuStringList,
        (PU16) image_list,
        0,
        0,
        g_brw_cntx.homepage_settings_index,
        guiBuffer_p);


    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_user_defined_homepage
 * DESCRIPTION
 *  Entry function for homepage settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_user_defined_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_USER_DEFINED_HOMEPAGE, NULL, mmi_brw_settings_entry_user_defined_homepage, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_USER_DEFINED_HOMEPAGE);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_USER_DEFINED_HOMEPAGE);
    GetSequenceStringIds(MENU_ID_BRW_USER_DEFINED_HOMEPAGE, nStrItemList);
    SetParentHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE);
    ConstructHintsList(MENU_ID_BRW_USER_DEFINED_HOMEPAGE, nHintList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_USER_DEFINED,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_active_profile_homepage
 * DESCRIPTION
 *  Entry function for active profile homepage settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_active_profile_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ACTIVE_PROFILE_HOMEPAGE, NULL, mmi_brw_settings_entry_active_profile_homepage, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ACTIVE_PROFILE_HOMEPAGE);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(mmi_brw_is_active_profile_editable() == BRW_PROF_READ_WRITE)
	{
		nNumofItem = GetNumOfChild(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_EDITABLE);
		GetSequenceStringIds(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_EDITABLE, nStrItemList);
		SetParentHandler(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_EDITABLE);
		ConstructHintsList(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE_EDITABLE, nHintList);
	}
	else
	{
		nNumofItem = GetNumOfChild(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE);
		GetSequenceStringIds(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE, nStrItemList);
		SetParentHandler(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE);
		ConstructHintsList(MENU_ID_BRW_ACTIVE_PROFILE_HOMEPAGE, nHintList);
	}

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_ACTIVE_PROFILE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_browser_options
 * DESCRIPTION
 *  Entry function for browser options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_browser_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BROWSER_OPTIONS, NULL, mmi_brw_settings_entry_browser_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BROWSER_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

#ifndef  BAM_CFG_SUI_ZOOM_ENABLED
	mmi_frm_hide_menu_item(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE);
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */

	nNumofItem = GetNumOfChild_Ext(MENU_ID_BRW_BROWSER_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_BRW_BROWSER_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_BRW_BROWSER_OPTIONS);
    ConstructHintsList(MENU_ID_BRW_BROWSER_OPTIONS, nHintList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_BROWSER_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList, 
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#if defined (WAP_SEC_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_security_settings
 * DESCRIPTION
 *  Entry function for security settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_security_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;
    S32 HideItemId = -1;
    U32 maskingByte = 0xffffffff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SECURITY_SETTINGS, NULL, mmi_brw_settings_entry_security_settings, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SECURITY_SETTINGS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_SECURITY_SETTINGS);
    GetSequenceStringIds(MENU_ID_BRW_SECURITY_SETTINGS, nStrItemList);
    SetParentHandler(MENU_ID_BRW_SECURITY_SETTINGS);
    ConstructHintsList(MENU_ID_BRW_SECURITY_SETTINGS, nHintList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	mmi_brw_settings_security_setting_highlight_handlers_init();

	/*Hide menu items "Session Info" and "Current Certificate" for Internet Services screen.
	  There is no need to display these options if no page is being rendered*/
	if(!IsScreenPresent(SCR_ID_BRW_BROWSER_MAIN))
	{
		/* Hide Menu Item "Session Info"*/
		HideItemId = GetChildMenuIDIndexByParentMenuID(
			MENU_ID_BRW_SECURITY_SETTINGS, MENU_ID_BRW_SECURITY_SETTINGS_SESSION_INFO);
		if (HideItemId != -1)
		{
			ResetBit(maskingByte, HideItemId);
		}

		/* Hide Menu Item "Current Certificate"*/
		HideItemId = GetChildMenuIDIndexByParentMenuID(
			MENU_ID_BRW_SECURITY_SETTINGS, MENU_ID_BRW_SECURITY_SETTINGS_CURRENT_CERTIFICATE);
		if (HideItemId != -1)
		{
			ResetBit(maskingByte, HideItemId);
		}
	}

     MaskHiliteItems(MENU_ID_BRW_SECURITY_SETTINGS, maskingByte);
     nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);

    ShowCategory52Screen(
        STR_ID_BRW_SECURITY_SETTINGS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_entry_view
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_entry_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_TRUSTED_CERTIFICATES_VIEW, NULL, mmi_brw_security_settings_trusted_certificates_entry_view, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_TRUSTED_CERTIFICATES_VIEW);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		if(g_brw_display_info_str)
		{
			mmi_brw_mfree(g_brw_display_info_str);
		}
		g_brw_display_info_str = mmi_brw_malloc((BRW_CURRENT_CERT_STR_LEN+1) * ENCODING_LENGTH);

		mmi_brw_security_settings_get_trusted_certificate_str(
			g_brw_cntx.index_highlighted_item,(U8*)g_brw_display_info_str);
	}

    ShowCategory74Screen(
        STR_ID_BRW_VIEW,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_brw_display_info_str,
        mmi_ucs2strlen((S8*)g_brw_display_info_str)+1,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_brw_display_info_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_display_info_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_entry_trusted_certificates
 * DESCRIPTION
 *  Entry function for trusted certificates list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_entry_trusted_certificates(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_TRUSTED_CERTIFICATES, NULL, mmi_brw_security_settings_entry_trusted_certificates, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_TRUSTED_CERTIFICATES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    ShowCategory184Screen(
        STR_ID_BRW_TRUSTED_CERTIFICATES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        g_brw_cntx.trusted_cert_ids.total,
        mmi_brw_security_settings_trusted_certificates_list_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_security_settings_trusted_certificates_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_security_settings_trusted_certificates_pre_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_trusted_certificates_entry_options
 * DESCRIPTION
 *  Entry function for trusted certificates options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_trusted_certificates_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U8 *guiBuffer;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS, NULL, mmi_brw_security_settings_trusted_certificates_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    num_of_items = GetNumOfChild(MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_TRUSTED_CERTIFICATES_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        UC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	OslMfree(UC_list_of_items);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_entry_session_info
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_entry_session_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SESSION_INFO, NULL, mmi_brw_security_settings_entry_session_info, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SESSION_INFO);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		if(g_brw_display_info_str)
		{
			mmi_brw_mfree(g_brw_display_info_str);
		}
		g_brw_display_info_str = mmi_brw_malloc((BRW_SESSION_INFO_STR_LEN+1) * ENCODING_LENGTH);

		mmi_brw_security_settings_get_session_info_str(g_brw_display_info_str);
	}

    ShowCategory74Screen(
        STR_ID_BRW_SESSION_INFO,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_brw_display_info_str,
        mmi_ucs2strlen((S8*)g_brw_display_info_str)+1,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_brw_display_info_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_display_info_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_security_settings_entry_current_cert
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_security_settings_entry_current_cert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_CURRENT_CERT, NULL, mmi_brw_security_settings_entry_current_cert, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_CURRENT_CERT);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		if(g_brw_display_info_str)
		{
			mmi_brw_mfree(g_brw_display_info_str);
		}
		g_brw_display_info_str = mmi_brw_malloc((BRW_CURRENT_CERT_STR_LEN+1) * ENCODING_LENGTH);

		mmi_brw_security_settings_get_current_cert_str(g_brw_display_info_str);
	}

    ShowCategory74Screen(
        STR_ID_BRW_CURRENT_CERTIFICATE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) g_brw_display_info_str,
        mmi_ucs2strlen((S8*)g_brw_display_info_str)+1,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_brw_display_info_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_display_info_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /*WAP_SEC_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_entry_modify
 * DESCRIPTION
 *  Entry function for user defined homepage edit menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_entry_modify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *nHintList[MAX_SUB_MENUS];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY, NULL, mmi_brw_settings_user_defined_hmpage_entry_modify, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(g_brw_cntx.document_info_p && strlen(g_brw_cntx.document_info_p->url))
	{
		nNumofItem = GetNumOfChild(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY);
		GetSequenceStringIds(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY, nStrItemList);
		SetParentHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY);
		ConstructHintsList(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY, nHintList);
	}
	else
	{
		nNumofItem = GetNumOfChild(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY_1);
		GetSequenceStringIds(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY_1, nStrItemList);
		SetParentHandler(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY_1);
		ConstructHintsList(MENU_ID_BRW_USER_DEFINED_HOMEPAGE_MODIFY_1, nHintList);
	}

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_MODIFY,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        nHintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_rendering_modes
 * DESCRIPTION
 *  Entry function to display different renderings modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_rendering_modes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_RENDERING_MODES, NULL, mmi_brw_settings_entry_rendering_modes, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_RENDERING_MODES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES);
    GetSequenceStringIds(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES, nStrItemList);
    SetParentHandler(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_settings_rendering_modes_set_hilite_index();

    ShowCategory11Screen(
        STR_ID_BRW_RENDERING_MODES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_BRW_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16)g_brw_cntx.index_highlighted_item,
        guiBuffer);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_navigation_modes
 * DESCRIPTION
 *  Entry function to display different navigation modes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_navigation_modes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_NAVIGATION_MODES, NULL, mmi_brw_settings_entry_navigation_modes, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_NAVIGATION_MODES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES);
    GetSequenceStringIds(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES, nStrItemList);
    SetParentHandler(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_settings_navigation_modes_set_hilite_index();

    ShowCategory11Screen(
        STR_ID_BRW_NAVIGATION_MODES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_BRW_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16)g_brw_cntx.index_highlighted_item,
        guiBuffer);


    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#ifdef BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_font_size
 * DESCRIPTION
 *  Entry function for selecting desired font size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_font_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_FONT_SIZE, NULL, mmi_brw_settings_entry_font_size, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_FONT_SIZE);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE);
    GetSequenceStringIds(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE, nStrItemList);
    SetParentHandler(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_settings_font_size_set_hilite_index();

    ShowCategory11Screen(
        STR_ID_BRW_FONT_SIZE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_BRW_SELECT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16)g_brw_cntx.index_highlighted_item,
        guiBuffer);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /*BAM_CFG_SUI_ZOOM_ENABLED*/ 


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_encoding_methods
 * DESCRIPTION
 *  Entry function for encoding methods
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_encoding_methods(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItems = bam_get_total_charset_num();
    U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ENCODING_METHODS, NULL, mmi_brw_settings_entry_encoding_methods, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ENCODING_METHODS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	for(index = 0; index < nNumofItems; index++)
	{
		subMenuDataPtrs[index] = (PU8)GetString((U16)g_brw_cntx.charset_list_p[index].name_id);
	}

    ShowCategory36Screen(
        STR_ID_BRW_ENCODING,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_BRW_SELECT,
        0,
        STR_GLOBAL_BACK,
        0,	
        nNumofItems,
        subMenuDataPtrs,
        g_brw_cntx.encoding_method_index,
        guiBuffer);


    /* Register function for left soft key */
    SetLeftSoftkeyFunction(mmi_brw_settings_update_encoding_method, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_entry_browser_preferences
 * DESCRIPTION
 *  Entry function for browser options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_entry_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 BrowserPreferencesImageList[BROWSER_PREFERENCES_ITEM_COUNT];
	U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BROWSER_PREFERENCES, mmi_brw_settings_exit_browser_preferences, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BROWSER_PREFERENCES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	for(index = 0; index < BROWSER_PREFERENCES_ITEM_COUNT; index++)
	{
		if(index % 2)
		{
			BrowserPreferencesImageList[index] = 0;
		}
		else
		{
			BrowserPreferencesImageList[index] = gIndexIconsImageList[index/2];
		}
	}

    InitializeCategory57Screen();

    DisableCategory57ScreenDone();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_BROWSER_PREFERENCES, &inputBufferSize);

    SetParentHandler(0);

    mmi_brw_settings_fill_inline_struct_for_browser_preferences();

    RegisterHighlightHandler(mmi_brw_settings_browser_preferences_items_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, BROWSER_PREFERENCES_ITEM_COUNT, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_BRW_PREFERENCES,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        BROWSER_PREFERENCES_ITEM_COUNT,
		BrowserPreferencesImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    DisableCategory57ScreenDone();

    SetCategory57RightSoftkeyFunctions(NULL, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_confirm_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_confirm_save(void)
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

    SetLeftSoftkeyFunction(mmi_brw_settings_browser_preferences_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_settings_browser_preferences_cancel, KEY_EVENT_UP);  /* added by tk */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_entry_edit
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_USER_DEFINED_HMPAGE_EDIT, NULL, mmi_brw_settings_user_defined_hmpage_entry_edit, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_USER_DEFINED_HMPAGE_EDIT);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		mmi_brw_settings_get_user_defined_homepage(g_brw_current_url);
	}

    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_DONE, mmi_brw_settings_user_defined_hmpage_editor_done_option_highlight_hdlr);

    ShowCategory5Screen(
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        g_brw_current_url,
        BRW_MAX_URL_LENGTH+1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_editor_entry_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_entry_view
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_entry_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_get_user_defined_homepage(g_brw_current_url);
	mmi_brw_entry_view_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_entry_view
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_entry_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_settings_get_active_profile_homepage(g_brw_current_url);
	mmi_brw_entry_view_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_entry_edit
 * DESCRIPTION
 *  This function is used for clearing the cookies
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ACTIVE_PROFILE_HMPAGE_EDIT, NULL, mmi_brw_settings_active_profile_hmpage_entry_edit, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ACTIVE_PROFILE_HMPAGE_EDIT);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		mmi_brw_settings_get_active_profile_homepage(g_brw_current_url);
	}

    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_DONE, mmi_brw_settings_active_profile_hmpage_editor_done_option_highlight_hdlr);

    ShowCategory5Screen(
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        g_brw_current_url,
        BRW_MAX_URL_LENGTH+1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_editor_entry_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
/******************************************** ENTRY FUNCTIONS - END ********************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_exit_browser_preferences
 * DESCRIPTION
 *  Exit function for browser settings option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_exit_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_BRW_BROWSER_PREFERENCES;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_settings_entry_browser_preferences;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_fill_inline_struct_for_browser_preferences
 * DESCRIPTION
 *  Function to Fill valuses in inine edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_fill_inline_struct_for_browser_preferences(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_settings_browser_preferences_write_inline_struct();

	/****************** Time Out ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_TIMEOUT_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
		&(wgui_inline_items[BRW_PREFERENCES_INLINE_TIMEOUT_CAPTION]), 
		(U8*) GetString(STR_ID_BRW_TIMEOUT));

    /* Inline Edit */
    SetInlineItemActivation(
		&(wgui_inline_items[BRW_PREFERENCES_INLINE_TIMEOUT_EDIT]), 
		INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
		0);
    SetInlineItemTextEdit(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_TIMEOUT_EDIT]),
        (U8*) gBrwTimeoutValue,
        BRW_TIME_OUT_LEN + 1,
        INPUT_TYPE_NUMERIC);
    LeftJustifyInlineItem(&(wgui_inline_items[BRW_PREFERENCES_INLINE_TIMEOUT_EDIT]));
    DisableInlineItemHighlight(&wgui_inline_items[BRW_PREFERENCES_INLINE_TIMEOUT_EDIT]);
	/****************** Time Out ******************/

	/****************** Show Images ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_IMAGES_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_IMAGES_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SHOW_IMAGES));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_SHOW_IMAGES_OPTION_COUNT,
        (U8 **) gBrwAlwaysNeverStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT]);
	/****************** Show Images ******************/

	/****************** Show Videos ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SHOW_VIDEOS));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_SHOW_VIDEOS_OPTION_COUNT,
        (U8 **) gBrwAlwaysNeverStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT]);
	/****************** Show Videos ******************/

	/****************** Play Sounds ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_CAPTION]),
        (U8*) GetString(STR_ID_BRW_PLAY_SOUNDS));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_PLAY_SOUNDS_OPTION_COUNT,
        (U8 **) gBrwAlwaysNeverStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT]);
	/****************** Play Sounds ******************/

	/****************** Load Unknown Media ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_CAPTION]),
        (U8*) GetString(STR_ID_BRW_LOAD_UNKNOWN_MEDIA));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_OPTION_COUNT,
        (U8 **) gBrwAlwaysNeverStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT]);
	/****************** Load Unknown Media ******************/

	/****************** CSS ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CSS_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CSS_CAPTION]),
        (U8*) GetString(STR_ID_BRW_CSS));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CSS_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CSS_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_CSS_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_CSS_SELECT]);
	/****************** CSS ******************/

	/****************** Script ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SCRIPT_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SCRIPT_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SCRIPT));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SCRIPT_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SCRIPT_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_SCRIPT_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_SCRIPT_SELECT]);
	/****************** Script ******************/

	/****************** Cache ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CACHE_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CACHE_CAPTION]),
        (U8*) GetString(STR_ID_BRW_CACHE));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CACHE_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_CACHE_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_CACHE_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_CACHE_SELECT]);
	/****************** Cache ******************/

	/****************** Cookie ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_COOKIE_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_COOKIE_CAPTION]),
        (U8*) GetString(STR_ID_BRW_COOKIE));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_COOKIE_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_COOKIE_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_COOKIE_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_COOKIE_SELECT]);
	/****************** Cookie ******************/

#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
	/****************** Shortcuts ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHORTCUTS_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHORTCUTS_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SHORTCUTS));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_SHORTCUTS_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT]);
	/****************** Shortcuts ******************/
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */

#ifdef  BRW_SECURITY_WARNINGS_SUPPORT
	/****************** Security Warnings ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SECURITY_WARNINGS));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT]);
	/****************** Security Warnings ******************/
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */

#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
	/****************** Send Device ID ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_CAPTION]),
        (U8*) GetString(STR_ID_BRW_SEND_DEVICE_ID));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT]),
        (S32) BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_OPTION_COUNT,
        (U8 **) gBrwEnableDisableStringArray,
        (PS32) &g_brw_preferences[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT]);
	/****************** Send Device ID ******************/
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_restore_browser_settings_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  enter address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_restore_browser_settings_confirm(void)
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
        get_string(STR_ID_BRW_RESTORE_BROWSER_SETTINGS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_settings_restore_browser_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_browser_preferences_write_inline_struct
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  trusted certificates list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_browser_preferences_write_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/****************** Time Out ******************/
	mmi_brw_convert_int_to_unicode_string(gBrwTimeoutValue, (U32) g_brw_cntx.timeout_value);
	/****************** Time Out ******************/

	/****************** Show Images ******************/
	if(g_brw_cntx.show_images_status == wap_bam_setting_val_images_never)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT] = BRW_PREF_NEVER_INDEX;
	}
	else if(g_brw_cntx.show_images_status == wap_bam_setting_val_images_always)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	/****************** Show Images ******************/

	/****************** Show Videos ******************/
	if(g_brw_cntx.show_videos_status == wap_bam_setting_val_movies_never)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT] = BRW_PREF_NEVER_INDEX;
	}
	else if(g_brw_cntx.show_videos_status == wap_bam_setting_val_movies_always)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	/****************** Show Videos ******************/

	/****************** Play Sounds ******************/
	if(g_brw_cntx.play_sounds_status == wap_bam_setting_val_sounds_never)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT] = BRW_PREF_NEVER_INDEX;
	}
	else if(g_brw_cntx.play_sounds_status == wap_bam_setting_val_sounds_always)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	/****************** Play Sounds ******************/

	/****************** Load Unknown Media ******************/
	if(g_brw_cntx.load_unknown_media_status == wap_bam_setting_val_no_mime_never)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT] = BRW_PREF_NEVER_INDEX;
	}
	else if(g_brw_cntx.load_unknown_media_status == wap_bam_setting_val_no_mime_always)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT] = BRW_PREF_ALWAYS_INDEX;
	}
	/****************** Load Unknown Media ******************/

	/****************** CSS ******************/
	if(g_brw_cntx.css_status == wap_bam_setting_val_css_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_CSS_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.css_status == wap_bam_setting_val_css_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_CSS_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_CSS_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** CSS ******************/

	/****************** Script ******************/
	if(g_brw_cntx.script_status == wap_bam_setting_val_script_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SCRIPT_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.script_status == wap_bam_setting_val_script_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SCRIPT_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SCRIPT_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** Script ******************/

	/****************** Cache ******************/
	if(g_brw_cntx.cache_status == wap_bam_setting_val_cache_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_CACHE_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.cache_status == wap_bam_setting_val_cache_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_CACHE_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_CACHE_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** Cache ******************/

	/****************** Cookie ******************/
	if(g_brw_cntx.cookie_status == wap_bam_setting_val_cookies_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_COOKIE_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.cookie_status == wap_bam_setting_val_cookies_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_COOKIE_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_COOKIE_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** Cookie ******************/

	/****************** Shortcuts ******************/
#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
	if(g_brw_cntx.shortcuts_status == wap_bam_setting_val_shortcuts_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.shortcuts_status == wap_bam_setting_val_shortcuts_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** Shortcuts ******************/
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */

#ifdef  BRW_SECURITY_WARNINGS_SUPPORT
	/****************** Security Warnings ******************/
	if(g_brw_cntx.security_warnings_status == wap_bam_setting_val_sec_warning_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.security_warnings_status == wap_bam_setting_val_sec_warning_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** Security Warnings ******************/
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */

#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
	/****************** Send Device ID ******************/
	if(g_brw_cntx.send_device_id_status == wap_bam_setting_val_imei_disable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT] = BRW_PREF_DISABLE_INDEX;
	}
	else if(g_brw_cntx.send_device_id_status == wap_bam_setting_val_imei_enable)
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	else
	{
		g_brw_preferences[BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT] = BRW_PREF_ENABLE_INDEX;
	}
	/****************** Send Device ID ******************/
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_rendering_modes_set_hilite_index
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  trusted certificates list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_rendering_modes_set_hilite_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
	S8* menuStr_p;
    S32 num_of_items;
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES, nStrItemList);
    num_of_items = GetNumOfChild(MENU_ID_BRW_BROWSER_OPTIONS_RENDERING_MODES);

	switch(g_brw_cntx.rendering_mode)
	{
		case wap_bam_setting_val_rend_normal:
		{
			menuStr_p = GetString(STR_ID_BRW_STANDARD);
			break;
		}
		case wap_bam_setting_val_rend_wrap:
		{
			menuStr_p = GetString(STR_ID_BRW_TEXT_WRAP);
			break;
		}
		case wap_bam_setting_val_rend_narrow:
		{
			menuStr_p = GetString(STR_ID_BRW_SCREEN_OPTIMIZED);
			break;
		}
		case wap_bam_setting_val_rend_text:
		{
			menuStr_p = GetString(STR_ID_BRW_TEXT_ONLY);
			break;
		}
		default:
		{
			menuStr_p = GetString(STR_ID_BRW_STANDARD);
			break;
		}
	}

	for(index=0; index<num_of_items; index++)
	{
		if(!mmi_ucs2cmp(GetString(nStrItemList[index]), menuStr_p))
		{
			g_brw_cntx.index_highlighted_item = index;
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_navigation_modes_set_hilite_index
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  trusted certificates list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_navigation_modes_set_hilite_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
	S8* menuStr_p;
    S32 num_of_items;
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES, nStrItemList);
    num_of_items = GetNumOfChild(MENU_ID_BRW_BROWSER_OPTIONS_NAVIGATION_MODES);

	switch(g_brw_cntx.navigation_mode)
	{
		case wap_bam_setting_val_nav_4_way:
		{
			menuStr_p = GetString(STR_ID_BRW_FOUR_WAY);
			break;
		}
		case wap_bam_setting_val_nav_2_way:
		{
			menuStr_p = GetString(STR_ID_BRW_TWO_WAY);
			break;
		}
		case wap_bam_setting_val_nav_scroll:
		{
			menuStr_p = GetString(STR_ID_BRW_SCROLLING);
			break;
		}
		default:
		{
			menuStr_p = GetString(STR_ID_BRW_FOUR_WAY);
			break;
		}
	}

	for(index=0; index<num_of_items; index++)
	{
		if(!mmi_ucs2cmp(GetString(nStrItemList[index]), menuStr_p))
		{
			g_brw_cntx.index_highlighted_item = index;
			break;
		}
	}
}


#ifdef BAM_CFG_SUI_ZOOM_ENABLED
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_font_size_set_hilite_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_font_size_set_hilite_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
	S8* menuStr_p;
    S32 num_of_items;
	U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceStringIds(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE, nStrItemList);
    num_of_items = GetNumOfChild(MENU_ID_BRW_BROWSER_OPTIONS_FONT_SIZE);

	switch(g_brw_cntx.font_size)
	{
		case BRW_FONT_SIZE_SMALL:
		{
			menuStr_p = GetString(STR_ID_BRW_SMALL);
			break;
		}
		case BRW_FONT_SIZE_MEDIUM:
		{
			menuStr_p = GetString(STR_ID_BRW_MEDIUM);
			break;
		}
		case BRW_FONT_SIZE_LARGE:
		{
			menuStr_p = GetString(STR_ID_BRW_LARGE);
			break;
		}
		default:
		{
			menuStr_p = GetString(STR_ID_BRW_MEDIUM);
			break;
		}
	}

	for(index=0; index<num_of_items; index++)
	{
		if(!mmi_ucs2cmp(GetString(nStrItemList[index]), menuStr_p))
		{
			g_brw_cntx.index_highlighted_item = index;
			break;
		}
	}
}
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_user_defined_hmpage_activate_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_user_defined_hmpage_activate_confirm(void)
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
        get_string(STR_ID_BRW_ACTIVATE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_settings_user_defined_hmpage_activate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_active_profile_hmpage_activate_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deleting the
 *  browser setting cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_settings_active_profile_hmpage_activate_confirm(void)
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
        get_string(STR_ID_BRW_ACTIVATE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_settings_active_profile_hmpage_activate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSETTINGSUI_C */ 

