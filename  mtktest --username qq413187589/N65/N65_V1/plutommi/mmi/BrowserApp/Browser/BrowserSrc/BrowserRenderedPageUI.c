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
 * BrowserRenderedPageUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function definations for UI implementation 
 *   of rendered page.
 *
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
#ifndef MMI_BROWSERRENDEREDPAGEUI_C
#define MMI_BROWSERRENDEREDPAGEUI_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#include "Conversions.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserRenderedPage.h"


U8 g_brw_auth_dlg_save_option = BRW_AUTH_DLG_SAVE_NONE_INDEX;
S8 *gBrwAuthDlgSaveOptionStringArray[BRW_AUTH_DLG_SAVE_OPTION_TOTAL];


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_highlight_handlers_init
 * DESCRIPTION
 *  Set highlight handler for rendered page menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_highlight_handlers_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_THIS_LINK, mmi_brw_ren_page_this_link_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_EDIT, mmi_brw_ren_page_edit_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_RESET, mmi_brw_ren_page_reset_highlight_hdlr);
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_DOWNLOADS, mmi_brw_ren_page_bkgrd_downloads_highlight_hdlr);
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_NAVIGATE, mmi_brw_ren_page_navigate_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_THIS_PAGE, mmi_brw_ren_page_this_page_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SELECT_MODE, mmi_brw_ren_page_select_mode_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_EXIT, mmi_brw_ren_page_exit_highlight_hdlr);

	/* This Link */
    SetHiliteHandler(MENU_ID_BRW_THIS_LINK_GOTO, mmi_brw_this_link_goto_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_THIS_LINK_SET_AS_HOMEPAGE, mmi_brw_this_link_set_as_hmpage_highlight_hdlr);
#ifdef __MMI_VBOOKMARK__
    SetHiliteHandler(MENU_ID_BRW_THIS_LINK_ADD_TO_BOOKMARK, mmi_brw_this_link_add_to_bookmark_highlight_hdlr);
#endif /*__MMI_VBOOKMARK__*/
    SetHiliteHandler(MENU_ID_BRW_THIS_LINK_SEND_ADDRESS, mmi_brw_this_link_send_address_highlight_hdlr);
	/* This Link */

	/* This Page */
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SET_AS_HOMEPAGE, mmi_brw_this_page_set_as_hmpage_highlight_hdlr);
#ifdef __MMI_VBOOKMARK__
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_ADD_TO_BOOKMARK, mmi_brw_this_page_add_to_bookmark_highlight_hdlr);
#endif /*__MMI_VBOOKMARK__*/
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_SEND_ADDRESS, mmi_brw_this_page_send_address_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_STORE_OFFLINE, mmi_brw_this_page_store_offline_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_PAGE_OBJECTS, mmi_brw_this_page_objects_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_PROPERTIES, mmi_brw_this_page_properties_highlight_hdlr);
	/* This Page */

	/* Page Objects */
    SetHiliteHandler(MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS, mmi_brw_page_objects_save_as_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_PAGE_OBJECTS_PROPERTIES, mmi_brw_page_objects_properties_highlight_hdlr);
	/* Page Objects */

	/* Select Mode */
    SetHiliteHandler(MENU_ID_BRW_SELECT_MODE_SAVE_AS, mmi_brw_select_mode_save_as_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SELECT_MODE_PROPERTIES, mmi_brw_select_mode_properties_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SELECT_MODE_EXIT, mmi_brw_select_mode_exit_highlight_hdlr);
	/* Select Mode */

	mmi_brw_ren_page_navigate_highlight_handlers_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_highlight_handlers_init
 * DESCRIPTION
 *  Set highlight handler for rendered page menu items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_highlight_handlers_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_NAVIGATE_REFRESH, mmi_brw_ren_page_navigate_refresh_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_NAVIGATE_FORWARD, mmi_brw_ren_page_navigate_forward_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_NAVIGATE_BACKWARD, mmi_brw_ren_page_navigate_backward_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_REN_PAGE_NAVIGATE_PAGE_ACTIONS, mmi_brw_ren_page_navigate_page_actions_highlight_hdlr);
}


/****************************************** HIGHLIGHT HANDLERS - START *****************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_goto_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for goto homepage option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_goto_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_goto_homepage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_exit_menu_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for exit option of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_exit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_pre_exit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_this_link_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for this link option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_this_link_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_entry_this_link, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_entry_this_link, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_edit_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for edit option of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_edit_req, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_reset_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for reset option of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_reset_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_reset_req, KEY_EVENT_UP);
}


#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_bkgrd_downloads_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for background downloads of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_bkgrd_downloads_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_bkgrd_downloads_display_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_bkgrd_downloads_display_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for navigate option of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_entry_navigate, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_entry_navigate, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_this_page_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for this page option of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_this_page_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_entry_this_page, KEY_EVENT_UP);
	SetKeyHandler(mmi_brw_ren_page_entry_this_page, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for select mode option of rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select_mode_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_select_mode_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for goto option of this link menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_link_goto, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_set_as_hmpage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for set as homepage option of this link menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_set_as_hmpage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_link_set_as_homepage, KEY_EVENT_UP);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_add_to_bookmark_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for add to bookmark option of this link menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_add_to_bookmark_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_link_add_to_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_link_add_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_link_send_address_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for send address option of this link menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_link_send_address_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_link_pre_entry_send_address, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_link_pre_entry_send_address, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_set_as_hmpage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for set as homepage option of this page menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_set_as_hmpage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_set_as_homepage, KEY_EVENT_UP);
}


#ifdef __MMI_VBOOKMARK__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_add_to_bookmark_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for add to bookmark option of this page menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_add_to_bookmark_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_add_to_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_page_add_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*__MMI_VBOOKMARK__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_send_address_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for send address option of this page menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_send_address_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_pre_entry_send_address, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_page_pre_entry_send_address, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_store_offline_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for store offline option of this page menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_store_offline_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_pre_entry_store_offline, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_objects_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for page objects option of this page menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_objects_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_get_resource_list_start_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_page_get_resource_list_start_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_properties_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for page properties option of this page menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_properties_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_pre_entry_page_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_page_pre_entry_page_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_select_mode_save_as_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for save as option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_select_mode_save_as_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_select_mode_save_as, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_select_mode_properties_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_select_mode_properties_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_select_mode_pre_entry_image_properties, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_select_mode_exit_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for exit option of select mode menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_select_mode_exit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_select_mode_exit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_save_as_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for save as option of page objects menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_objects_save_as_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_page_objects_save_as, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_properties_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of page objects menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_objects_properties_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_page_objects_pre_entry_object_properties, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_page_objects_pre_entry_object_properties, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_refresh_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of page objects menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_refresh_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_navigate_refresh, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_forward_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of page objects menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_forward_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_navigate_forward, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_backward_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of page objects menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_backward_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_navigate_backward, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_page_actions_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for properties option of page objects menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_page_actions_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_ren_page_navigate_entry_page_actions, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_ren_page_navigate_entry_page_actions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_items_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for authentication dialog items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_items_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 NumericKeys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetGroupKeyHandler(mmi_brw_http_auth_open_full_screen_editor, NumericKeys, 11, KEY_EVENT_UP);
	if(index == BRW_AUTH_DLG_INLINE_SAVE_OPTION)
	{
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetCategory57LeftSoftkeyFunction(mmi_brw_ren_page_auth_dlg_ok);
	}
	else
	{
		ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
	    //SetCategory57LeftSoftkeyFunction(mmi_brw_http_auth_open_full_screen_editor);
	}
	ChangeRightSoftkey(STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK);
    SetCategory57RightSoftkeyFunctions(mmi_brw_ren_page_auth_dlg_cancel, mmi_brw_ren_page_auth_dlg_cancel);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_store_offline_editor_done_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_store_offline_editor_done_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_this_page_store_offline_confirm, KEY_EVENT_UP);
}
/****************************************** HIGHLIGHT HANDLERS - END *******************************************/


/******************************************* ENTRY FUNCTIONS - START *******************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_entry_options
 * DESCRIPTION
 *  Entry function to display rendered page options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_options(void)
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
    EntryNewScreen(SCR_ID_BRW_RENDERED_PAGE_OPTIONS, NULL, mmi_brw_ren_page_entry_options, NULL);
	guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		mmi_brw_ren_page_notify_screen_info_req(MMI_FALSE);
	}

	//de-allocate memory for recent pages and stored pages
	mmi_brw_recent_pages_get_recent_pages_list_end_req();
	mmi_brw_stored_pages_get_saved_pages_list_end_req();

	/*if select mode is active*/
	if(g_brw_cntx.select_mode_flag == MMI_TRUE)
	{
		/*if image is not selected*/
		if( !g_brw_cntx.focused_element_info_p || 
			 (g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_IMAGE)
		   )
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
			mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_PROPERTIES);
		}
		/*if image is selected & its object file also exist*/
		else if( strlen((S8*)g_brw_cntx.focused_element_info_p->object_filePath) ) 
		{
			mmi_frm_unhide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
			mmi_frm_unhide_menu_item(MENU_ID_BRW_SELECT_MODE_PROPERTIES);
		}
		/*if image is selected but its object file don't exist*/
		else
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_SELECT_MODE_SAVE_AS);
			mmi_frm_unhide_menu_item(MENU_ID_BRW_SELECT_MODE_PROPERTIES);
		}
	}
	else
	{
		/*if hyperlink is not selected*/
		if( !g_brw_cntx.focused_element_info_p ||
					(g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_LINK &&
					 g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_SUBMIT &&
					 g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_INPUT &&
					 g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_BUTTON &&
					 g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_DO) 
				)
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_THIS_LINK);
		}
		else /*if hyperlink is selected*/
		{
			mmi_frm_unhide_menu_item(MENU_ID_BRW_REN_PAGE_THIS_LINK);
		}

		/*if edit box is not selected*/
		if( !g_brw_cntx.focused_element_info_p ||
				  (g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_TEXTINPUT &&
				   g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_SELECT)
				)
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_EDIT);
		}
		else /*if edit box is selected*/
		{
			mmi_frm_unhide_menu_item(MENU_ID_BRW_REN_PAGE_EDIT);
		}

		/*if reset element is not selected*/
		if( !g_brw_cntx.focused_element_info_p ||
				 (g_brw_cntx.focused_element_info_p->type != WAP_BAM_FOCUSED_ELEMENT_RESET)
				)
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_RESET);
		}
		else /*if reset element is selected*/
		{
			mmi_frm_unhide_menu_item(MENU_ID_BRW_REN_PAGE_RESET);
		}

#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
		/*if background download is not active*/
		if( !g_brw_cntx.download_info_p ||
			!g_brw_cntx.download_info_p->job_count)
		{
			mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_DOWNLOADS);
		}
		else /*if background download is active*/
		{
			mmi_frm_unhide_menu_item(MENU_ID_BRW_REN_PAGE_DOWNLOADS);
		}
#else 
		mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_DOWNLOADS);
		
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/

	}

	if(g_brw_cntx.select_mode_flag == MMI_TRUE)
	{
		nNumofItem = GetNumOfChild_Ext(MENU_ID_BRW_SELECT_MODE_OPTIONS);
		GetSequenceStringIds_Ext(MENU_ID_BRW_SELECT_MODE_OPTIONS, nStrItemList);
		SetParentHandler(MENU_ID_BRW_SELECT_MODE_OPTIONS);
		ConstructHintsList(MENU_ID_BRW_SELECT_MODE_OPTIONS, nHintList);
	}
	else
	{
		nNumofItem = GetNumOfChild_Ext(MENU_ID_BRW_RENDERED_PAGE_OPTIONS);
		GetSequenceStringIds_Ext(MENU_ID_BRW_RENDERED_PAGE_OPTIONS, nStrItemList);
		SetParentHandler(MENU_ID_BRW_RENDERED_PAGE_OPTIONS);
		ConstructHintsList(MENU_ID_BRW_RENDERED_PAGE_OPTIONS, nHintList);
	}

	RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_OPTION,
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
 *  mmi_brw_ren_page_entry_this_link
 * DESCRIPTION
 *  Entry function to display this link options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_this_link(void)
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
    EntryNewScreen(SCR_ID_BRW_REN_PAGE_THIS_LINK, NULL, mmi_brw_ren_page_entry_this_link, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_REN_PAGE_THIS_LINK);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	/*if a hyperlink is selected*/
	if( g_brw_cntx.focused_element_info_p && 
		 (g_brw_cntx.focused_element_info_p->type == WAP_BAM_FOCUSED_ELEMENT_LINK)
	   )
	{
		mmi_frm_unhide_menu_item(MENU_ID_BRW_THIS_LINK_SET_AS_HOMEPAGE);
#ifdef __MMI_VBOOKMARK__
		mmi_frm_unhide_menu_item(MENU_ID_BRW_THIS_LINK_ADD_TO_BOOKMARK);
#endif /*__MMI_VBOOKMARK__*/
		mmi_frm_unhide_menu_item(MENU_ID_BRW_THIS_LINK_SEND_ADDRESS);
	}
	else /*if a hyperlink is not selected*/
	{
		mmi_frm_hide_menu_item(MENU_ID_BRW_THIS_LINK_SET_AS_HOMEPAGE);
#ifdef __MMI_VBOOKMARK__
		mmi_frm_hide_menu_item(MENU_ID_BRW_THIS_LINK_ADD_TO_BOOKMARK);
#endif /*__MMI_VBOOKMARK__*/
		mmi_frm_hide_menu_item(MENU_ID_BRW_THIS_LINK_SEND_ADDRESS);
	}

    nNumofItem = GetNumOfChild_Ext(MENU_ID_BRW_REN_PAGE_THIS_LINK);
    GetSequenceStringIds_Ext(MENU_ID_BRW_REN_PAGE_THIS_LINK, nStrItemList);
    SetParentHandler(MENU_ID_BRW_REN_PAGE_THIS_LINK);
    ConstructHintsList(MENU_ID_BRW_REN_PAGE_THIS_LINK, nHintList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_THIS_LINK,
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
 *  mmi_brw_ren_page_entry_this_page
 * DESCRIPTION
 *  Entry function to display this page options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_this_page(void)
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

    EntryNewScreen(SCR_ID_BRW_REN_PAGE_THIS_PAGE, NULL, mmi_brw_ren_page_entry_this_page, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_REN_PAGE_THIS_PAGE);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	mmi_brw_this_page_get_resource_list_end_req();

	/*Don't show "Store Offline" option if page is opened from "Stored Pages" or*/
	/*through "Open File"*/
	if( g_brw_cntx.document_info_p && 
		 ( ( g_brw_cntx.document_info_p->protocol == WAP_BAM_PROTOCOL_FILE ) ||
		   ( g_brw_cntx.document_info_p->protocol == WAP_BAM_PROTOCOL_OTHER ) )
	  )
	{
		mmi_frm_hide_menu_item(MENU_ID_BRW_REN_PAGE_STORE_OFFLINE);
	}
	else
	{
		mmi_frm_unhide_menu_item(MENU_ID_BRW_REN_PAGE_STORE_OFFLINE);
	}

    nNumofItem = GetNumOfChild_Ext(MENU_ID_BRW_REN_PAGE_THIS_PAGE);
    GetSequenceStringIds_Ext(MENU_ID_BRW_REN_PAGE_THIS_PAGE, nStrItemList);
    SetParentHandler(MENU_ID_BRW_REN_PAGE_THIS_PAGE);
    ConstructHintsList(MENU_ID_BRW_REN_PAGE_THIS_PAGE, nHintList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_BRW_THIS_PAGE,
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
 *  mmi_brw_ren_page_entry_navigate
 * DESCRIPTION
 *  Entry function to display navigate options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_navigate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* nStrItemList;
    U8 *guiBuffer;
    S32 num_of_items;
    S32 HideItemId = -1;
    U32 maskingByte = 0xffffffff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_NAVIGATE, NULL, mmi_brw_ren_page_entry_navigate, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_NAVIGATE);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    num_of_items = GetNumOfChild(MENU_ID_BRW_REN_PAGE_NAVIGATE);
    nStrItemList = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_REN_PAGE_NAVIGATE, nStrItemList);
    SetParentHandler(MENU_ID_BRW_REN_PAGE_NAVIGATE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_ren_page_navigate_highlight_handlers_init(); /* Register highlight handler every time you enter into options */

    if(!mmi_brw_ren_page_is_forward_navigation())
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_REN_PAGE_NAVIGATE, MENU_ID_BRW_REN_PAGE_NAVIGATE_FORWARD);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }
    if(!mmi_brw_ren_page_is_backward_navigation())
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_REN_PAGE_NAVIGATE, MENU_ID_BRW_REN_PAGE_NAVIGATE_BACKWARD);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }
    if(!g_brw_cntx.do_element_count)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_REN_PAGE_NAVIGATE, MENU_ID_BRW_REN_PAGE_NAVIGATE_PAGE_ACTIONS);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }

	MaskHiliteItems(MENU_ID_BRW_REN_PAGE_NAVIGATE, maskingByte);
	num_of_items = MaskItems(nStrItemList, (U8) num_of_items, maskingByte);

    ShowCategory15Screen(
        STR_ID_BRW_NAVIGATE,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    OslMfree(nStrItemList);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_navigate_entry_page_actions
 * DESCRIPTION
 *  Entry function to display page actions options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_navigate_entry_page_actions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_PAGE_ACTIONS, NULL, mmi_brw_ren_page_navigate_entry_page_actions, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_PAGE_ACTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    ShowCategory184Screen(
        STR_ID_BRW_PAGE_ACTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        g_brw_cntx.do_element_count,
        mmi_brw_ren_page_navigate_page_actions_list_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_ren_page_navigate_page_actions_ok, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_entry_store_offline
 * DESCRIPTION
 *  Entry function to display store offline screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_entry_store_offline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_EDIT_STORE_OFFLINE, NULL, mmi_brw_this_page_entry_store_offline, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_EDIT_STORE_OFFLINE);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_DONE, mmi_brw_ren_page_store_offline_editor_done_option_highlight_hdlr);

    ShowCategory215Screen(
        STR_ID_BRW_ENTER_NAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_brw_current_title,
        BRW_MAX_TITLE_LENGTH+1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_editor_entry_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_entry_page_object_types
 * DESCRIPTION
 *  Entry function to display page object types screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_entry_page_object_types(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 list_count=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_PAGE_OBJECT_TYPES, NULL, mmi_brw_this_page_entry_page_object_types, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_PAGE_OBJECT_TYPES);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	mmi_brw_this_page_get_page_object_types_count(&list_count);

    ShowCategory184Screen(
        STR_ID_BRW_PAGE_OBJECTS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        list_count,
        mmi_brw_page_object_types_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_this_page_object_types_ok, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_this_page_object_types_ok, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_entry_page_objects
 * DESCRIPTION
 *  Entry function to display page objects screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_entry_page_objects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 list_count=0;
	U16 string_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_PAGE_OBJECTS, NULL, mmi_brw_this_page_entry_page_objects, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_PAGE_OBJECTS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	mmi_brw_this_page_get_page_objects_count(&list_count);
	switch(g_brw_cntx.selected_page_object_type)
	{
		case BRW_PAGE_OBJECT_TYPE_IMAGE:
			string_ID = STR_ID_BRW_IMAGES;
			break;

		case BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
			string_ID = STR_ID_BRW_BG_IMAGES;
			break;

		case BRW_PAGE_OBJECT_TYPE_SOUNDS:
			string_ID = STR_ID_BRW_SOUNDS;
			break;

		case BRW_PAGE_OBJECT_TYPE_OTHERS:
			string_ID = STR_ID_BRW_OTHERS;
			break;
		default:
			string_ID = 0;
			break;
	}

    ShowCategory184Screen(
        string_ID,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        list_count,
        mmi_brw_this_page_objects_get_item,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_page_objects_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_page_objects_pre_entry_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_entry_options
 * DESCRIPTION
 *  Entry function to display page object options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_page_objects_entry_options(void)
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
    EntryNewScreen(SCR_ID_BRW_PAGE_OBJECTS_OPTIONS, NULL, mmi_brw_page_objects_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_PAGE_OBJECTS_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	/*to hide the Save As option for video objects & for those not having the cache file*/
	if( (g_brw_cntx.selected_page_object_type == BRW_PAGE_OBJECT_TYPE_OTHERS) ||
		!strlen((S8*)g_brw_cntx.brw_res_item_info_p->cache_file)
		)
	{
		mmi_frm_hide_menu_item(MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS);
	}
	else /*if reset element is selected*/
	{
		mmi_frm_unhide_menu_item(MENU_ID_BRW_PAGE_OBJECTS_SAVE_AS);
	}

    num_of_items = GetNumOfChild_Ext(MENU_ID_BRW_PAGE_OBJECTS_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds_Ext(MENU_ID_BRW_PAGE_OBJECTS_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_PAGE_OBJECTS_OPTIONS);
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
 *  mmi_brw_ren_page_entry_auth_dialog
 * DESCRIPTION
 *  Entry function to display authentication dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_auth_dialog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 authInfoImageList[BRW_AUTH_DLG_INLINE_TOTAL] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SHOW_AUTH_DIALOG, mmi_brw_ren_page_exit_auth_dialog, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SHOW_AUTH_DIALOG);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();

    DisableCategory57ScreenDone();

    if(!guiBuffer)
    {
        memset(g_brw_auth_username, 0, sizeof(g_brw_auth_username));
        memset(g_brw_auth_password, 0, sizeof(g_brw_auth_password));
        mmi_chset_utf8_to_ucs2_string((U8*)g_brw_auth_username, (WAP_BAM_MAX_USER_PASSWD_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.http_auth_info_p->username);
        mmi_chset_utf8_to_ucs2_string((U8*)g_brw_auth_password, (WAP_BAM_MAX_USER_PASSWD_LENGTH+1)*ENCODING_LENGTH, (U8*)g_brw_cntx.http_auth_info_p->password);
    }

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_SHOW_AUTH_DIALOG, &inputBufferSize);

    SetParentHandler(0);

    mmi_brw_ren_page_fill_inline_struct_for_auth();

    RegisterHighlightHandler(mmi_brw_ren_page_auth_dlg_items_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, BRW_AUTH_DLG_INLINE_TOTAL, inputBuffer);
    }

    ShowCategory57Screen(
        STR_ID_BRW_AUTHENTICATION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        BRW_AUTH_DLG_INLINE_TOTAL,
	(U16*) authInfoImageList,
        wgui_inline_items,
        0,
        guiBuffer);

	g_brw_cntx.auth_dlg_flag = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_entry_options
 * DESCRIPTION
 *  Entry function to display auth dialog options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_entry_options(void)
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
    EntryNewScreen(SCR_ID_BRW_SHOW_AUTH_DLG_OPTIONS, NULL, mmi_brw_ren_page_auth_dlg_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SHOW_AUTH_DLG_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    num_of_items = GetNumOfChild(MENU_ID_BRW_AUTH_DIALOG_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_AUTH_DIALOG_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_AUTH_DIALOG_OPTIONS);
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
/******************************************** ENTRY FUNCTIONS - END ********************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_confirm
 * DESCRIPTION
 *  Confirmation screen for select mode activation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_select_mode_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_brw_ren_page_select_mode_activate, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_exit_auth_dialog
 * DESCRIPTION
 *  Exit function for authentication dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_exit_auth_dialog(void)
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
    h.scrnID = SCR_ID_BRW_SHOW_AUTH_DIALOG;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_brw_ren_page_entry_auth_dialog;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategory57History(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_fill_inline_struct_for_auth
 * DESCRIPTION
 *  This function is used to fill inline edit screen item values for 
 *  authentication dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_fill_inline_struct_for_auth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/****************** User Name ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_AUTH_DLG_INLINE_USERNAME_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
		&(wgui_inline_items[BRW_AUTH_DLG_INLINE_USERNAME_CAPTION]), 
		(U8*) GetString(STR_ID_BRW_USER_NAME));

    /* Inline Edit */
    SetInlineItemActivation(
		&(wgui_inline_items[BRW_AUTH_DLG_INLINE_USERNAME]), 
		KEY_LSK, 
		KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[BRW_AUTH_DLG_INLINE_USERNAME],
        STR_ID_BRW_USER_NAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_brw_auth_username,
        WAP_BAM_MAX_USER_PASSWD_LENGTH+1,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
		INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[BRW_AUTH_DLG_INLINE_USERNAME],
        mmi_brw_ren_page_auth_dlg_full_screen_editor_options);
	/****************** User Name ******************/

	/****************** Password ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_AUTH_DLG_INLINE_PASSWORD_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
		&(wgui_inline_items[BRW_AUTH_DLG_INLINE_PASSWORD_CAPTION]), 
		(U8*) GetString(STR_ID_BRW_PASSWORD));

    /* Inline Edit */
    SetInlineItemActivation(
		&(wgui_inline_items[BRW_AUTH_DLG_INLINE_PASSWORD]), 
		KEY_LSK, 
		KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[BRW_AUTH_DLG_INLINE_PASSWORD],
        STR_ID_BRW_PASSWORD,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_brw_auth_password,
        WAP_BAM_MAX_USER_PASSWD_LENGTH+1,
        (INPUT_TYPE_ALPHANUMERIC_PASSWORD | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
		INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[BRW_AUTH_DLG_INLINE_PASSWORD],
        mmi_brw_ren_page_auth_dlg_full_screen_editor_options);
	/****************** Password ******************/

	/****************** Show saving options ******************/
    /* Caption */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_AUTH_DLG_INLINE_SAVE_OPTION_CAPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[BRW_AUTH_DLG_INLINE_SAVE_OPTION_CAPTION]),
        (U8*) GetString(STR_ID_BRW_OPTION));

    /* Inline Select */
    SetInlineItemActivation(
        &(wgui_inline_items[BRW_AUTH_DLG_INLINE_SAVE_OPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[BRW_AUTH_DLG_INLINE_SAVE_OPTION]),
        (S32) BRW_AUTH_DLG_SAVE_OPTION_TOTAL,
        (U8 **) gBrwAuthDlgSaveOptionStringArray,
        (PS32) &g_brw_auth_dlg_save_option
		);

	/****************** Show saving options ******************/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_auth_dlg_full_screen_editor_options
 * DESCRIPTION
 *  Callback for full screen edit options from inline edit screen of 
 *  authentication dialog
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_auth_dlg_full_screen_editor_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_http_auth_open_full_screen_editor
 * DESCRIPTION
 *  This function is the alpha-numeric keys handler for
 *  authentication dialog screen. It opens full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_http_auth_open_full_screen_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(KEY_0, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_entry_sec_confirm_dialog
 * DESCRIPTION
 *  This function displays the confirmation dialog for the secure connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_entry_sec_confirm_dialog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID_TYPE ImageId;
	U8  ToneId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(g_brw_cntx.sec_confirm_dlg_info_p->dialog_type)
	{
		case WPS_DLG_ERROR:
		{
			ImageId = IMG_GLOBAL_ERROR;
			ToneId  = ERROR_TONE;
			break;
		}
		case WPS_DLG_INFO:
		{
			ImageId = IMG_GLOBAL_INFO;
			ToneId  = WARNING_TONE;
			break;
		}
		case WPS_DLG_ALERT:
		{
			ImageId = IMG_GLOBAL_QUESTION;
			ToneId  = WARNING_TONE;
			break;
		}
		default:
		{
			ImageId = IMG_GLOBAL_ERROR;
			ToneId  = ERROR_TONE;
			break;
		}
	}

	if(g_brw_cntx.sec_confirm_dlg_info_p->buttons == WPS_DLG_BUTTON_YESNO)
	{
		DisplayConfirm(
			STR_GLOBAL_YES,
			IMG_GLOBAL_YES,
			STR_GLOBAL_NO,
			IMG_GLOBAL_NO,
			get_string((U16)g_brw_cntx.sec_confirm_dlg_info_p->text_id),
			ImageId,
			ToneId);
	}
	else
	{
		DisplayConfirm(
			STR_GLOBAL_OK,
			IMG_GLOBAL_OK,
			NULL,
			NULL,
			get_string((U16)g_brw_cntx.sec_confirm_dlg_info_p->text_id),
			ImageId,
			ToneId);
	}

    SetLeftSoftkeyFunction(mmi_brw_ren_page_sec_confirm_dialog_positive_res, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_ren_page_sec_confirm_dialog_negative_res, KEY_EVENT_UP);

	g_brw_cntx.security_dlg_flag = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_this_page_store_offline_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for storing page offline
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_this_page_store_offline_confirm(void)
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
        get_string(STR_ID_BRW_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_this_page_store_offline, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_suspend_bkgrd_downloads_confirm
 * DESCRIPTION
 *  Confirmation screen for background downloads suspension
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_ren_page_suspend_bkgrd_downloads_confirm(void)
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
        get_string(STR_ID_BRW_BKGRD_DOWNLOAD_SUSPEND),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_ren_page_suspend_bkgrd_downloads_accepted, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_ren_page_suspend_bkgrd_downloads_rejected, KEY_EVENT_UP);
}
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERRENDEREDPAGEUI_C */ 

