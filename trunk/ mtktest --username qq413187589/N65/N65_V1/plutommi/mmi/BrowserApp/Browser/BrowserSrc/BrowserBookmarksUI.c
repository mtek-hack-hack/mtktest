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
 * BrowserBookmarksUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for UI implementation 
 *   of browser bookmarks.
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
#ifndef MMI_BROWSERBOOKMARKSUI_C
#define MMI_BROWSERBOOKMARKSUI_C


//#ifdef __MMI_BROWSER_2__
#if defined(__MMI_BROWSER_2__) && defined(__MMI_VBOOKMARK__)

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "OrganizerDef.h"
#include "DateTimeGprot.h"
//#include "settingGprots.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserGprots.h"
#include "BrowserBookmarks.h"
/*  Include: NVRAM header file */
#include "PhoneBookDef.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_highlight_handlers_init
 * DESCRIPTION
 *  This function is used for registering highlight and hint handlers of
 *  recent pages module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_highlight_handlers_init(void)
{
    SetHiliteHandler(MENU_ID_BRW_BOOKMARKS, mmi_brw_bookmarks_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_OPEN_FOLDER, mmi_brw_bookmarks_open_folder_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_DELETE_FOLDER, mmi_brw_bookmarks_delete_folder_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_GOTO, mmi_brw_bookmarks_goto_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_VIEW, mmi_brw_bookmarks_view_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_EDIT, mmi_brw_bookmarks_edit_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_DELETE, mmi_brw_bookmarks_delete_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_DELETE_ALL_USER_FILES, mmi_brw_bookmarks_delete_all_user_files_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_ADD_BOOKMARK, mmi_brw_bookmarks_add_bookmark_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_SET_AS_HOMEPAGE, mmi_brw_bookmarks_set_as_homepage_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK, mmi_brw_bookmarks_send_bookmark_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_CREATE_FOLDER, mmi_brw_bookmarks_create_folder_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_COPY_TO, mmi_brw_bookmarks_copy_to_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_MOVE_TO, mmi_brw_bookmarks_move_to_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_MEMORY_STATUS, mmi_brw_bookmarks_memory_status_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT, mmi_brw_bookmarks_browse_path_select_folder_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER, mmi_brw_bookmarks_browse_path_open_folder_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER, mmi_brw_bookmarks_browse_path_create_folder_highlight_hdlr);

	/*highlight handlers for file manager interface*/
    SetHiliteHandler(MENU_ID_BRW_BKM_GOTO_FROM_FMGR, mmi_brw_bookmarks_open_goto_from_fmgr_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_EDIT_FROM_FMGR, mmi_brw_bookmarks_open_edit_from_fmgr_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_BKM_SAVE_TO_BOOKMARK_FROM_FMGR, mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr_highlight_hdlr);
	/*highlight handlers for file manager interface*/

	mmi_brw_bookmarks_send_bookmark_highlight_handlers_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_highlight_handlers_init
 * DESCRIPTION
 *  This function is used for registering highlight and hint handlers of
 *  recent pages module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_highlight_handlers_init(void)
{
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    SetHiliteHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_SMS, mmi_brw_bookmarks_send_bookmark_as_sms_highlight_hdlr);
#endif
#if defined(__MMI_MMS__)
    SetHiliteHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_MMS, mmi_brw_bookmarks_send_bookmark_as_mms_highlight_hdlr);
#endif
#if  defined(__MMI_IRDA_SUPPORT__)	 
    SetHiliteHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_INFRARED, mmi_brw_bookmarks_send_bookmark_via_infrared_highlight_hdlr);
#endif
#ifdef __MMI_OPP_SUPPORT__
    SetHiliteHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_BLUETOOTH, mmi_brw_bookmarks_send_bookmark_via_bluetooth_highlight_hdlr);
#endif
#if  defined(__MMI_EMAIL__)
    SetHiliteHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_EMAIL, mmi_brw_bookmarks_send_bookmark_via_email_highlight_hdlr);
#endif
}


/****************************************** HIGHLIGHT HANDLERS - START *****************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of bookmark menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_show_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_pre_entry_show_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_folder_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of open folder menu item
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_open_folder, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_folder_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of delete folder menu item
 *  Register key handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_delete_folder_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_goto, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_view_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of goto menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_view_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_entry_view, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_entry_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of edit bookmark menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_pre_entry_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of delete menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_delete_file_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_all_user_files_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Delete all menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_all_user_files_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_delete_all_user_files_confirm, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_add_bookmark_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Add to Bookmark menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_add_bookmark_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_add_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_pre_entry_add_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_set_as_homepage_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of add bookmark menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_set_as_homepage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_set_as_homepage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_entry_send_bookmark, KEY_EVENT_UP);
	SetKeyHandler(mmi_brw_bookmarks_entry_send_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_create_folder_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_create_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_create_folder, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_copy_to_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_copy_to_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_copy_to, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_move_to_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_move_to_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_move_to, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_memory_status_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_memory_status_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_memory_status, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_select_folder_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_select_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_browse_path_select_folder, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_open_folder_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_open_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_browse_path_open_folder, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_create_folder_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_create_folder_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_create_folder, KEY_EVENT_UP);
}


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_as_sms_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_as_sms_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_send_bookmark_as_sms, KEY_EVENT_UP);
}
#endif


#if defined(__MMI_MMS__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_as_mms_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_as_mms_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_send_bookmark_as_mms, KEY_EVENT_UP);
}
#endif


#if  defined(__MMI_IRDA_SUPPORT__)	 
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_infrared_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_infrared_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_send_bookmark_via_infrared, KEY_EVENT_UP);
}
#endif


#ifdef __MMI_OPP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_bluetooth_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_bluetooth_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_send_bookmark_via_bluetooth, KEY_EVENT_UP);
}
#endif


#if  defined(__MMI_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_email_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_email_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_send_bookmark_via_email, KEY_EVENT_UP);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_goto_from_fmgr_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_goto_from_fmgr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_open_goto_from_fmgr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_edit_from_fmgr_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_edit_from_fmgr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_edit_from_fmgr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of 'Set as homepage' menu item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_save_to_bookmark_items_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of save to bookmark menu items
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_save_to_bookmark_items_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_ID_BRW_SAVE, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_brw_bookmarks_save_to_bookmark);

    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_select_bookmark_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of selecting a bookmark from the list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_select_bookmark_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_bkm_cntx.sel_file_index = item_index;

	if(g_brw_bkm_cntx.file_info_list[item_index].file_extn == BRW_BKM_FILE_EXTN_NONE)
	{
		ChangeLeftSoftkey(STR_ID_BRW_OPEN, IMG_GLOBAL_OK);
	    SetLeftSoftkeyFunction(mmi_brw_bookmarks_select_bookmark_open_folder, KEY_EVENT_UP);
		SetKeyHandler(mmi_brw_bookmarks_select_bookmark_open_folder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	}
	else
	{
		ChangeLeftSoftkey(STR_ID_BRW_SELECT, IMG_GLOBAL_OK);
	    SetLeftSoftkeyFunction(mmi_brw_bookmarks_select_bookmark_done, KEY_EVENT_UP);
		SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_create_folder_editor_done_option_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Enter Address DeleteAll Menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_create_folder_editor_done_option_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_bookmarks_create_folder, KEY_EVENT_UP);
}
/****************************************** HIGHLIGHT HANDLERS - END *******************************************/


/******************************************* ENTRY FUNCTIONS - START *******************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_show_list
 * DESCRIPTION
 *  Entry function for Bookmark list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_show_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	//U16 bkm_file_count=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BOOKMARKS, NULL, mmi_brw_bookmarks_entry_show_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARKS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	g_brw_bkm_cntx.total_file_count = mmi_brw_bookmarks_get_file_and_folder_count(g_brw_bkm_cntx.sel_folder_path);

	if(g_brw_bkm_cntx.total_file_count)
	{
		mmi_brw_bookmarks_allocate_file_info_list();

		ShowCategory184Screen(
			STR_ID_BRW_BOOKMARKS,
			GetRootTitleIcon(SERVICES_WAP_MENU_ID),
			STR_GLOBAL_OPTIONS,
			0,
			STR_GLOBAL_BACK,
			0,
			g_brw_bkm_cntx.total_file_count,
			mmi_brw_bookmarks_list_get_item,
			0,
			g_brw_bkm_cntx.index_highlighted_item,
			guiBuffer);
	}
	else
	{
        ShowCategory213Screen(
            STR_ID_BRW_BOOKMARKS,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            0, 
            STR_GLOBAL_BACK,
            0,  
            0,
            NULL,
            NULL,
            0,      
            0,
            (U8*) guiBuffer);
	}

	if(IsScreenPresent(SCR_ID_BRW_BOOKMARKS))
	{
		DeleteNScrId(SCR_ID_BRW_BOOKMARKS);
	}

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_open_folder_or_show_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_brw_bookmarks_file_list_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_file_list_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_options
 * DESCRIPTION
 *  Entry function for Bookmark options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U8 *guiBuffer;
    S32 num_of_items;
	U16 MenuID;
	U8  file_extn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BOOKMARK_OPTIONS, NULL, mmi_brw_bookmarks_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARK_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	g_brw_bkm_browse_path_event = BRW_BKM_BROWSE_PATH_NONE;

	if(g_brw_bkm_cntx.total_file_count)
	{
		file_extn = g_brw_bkm_cntx.file_info_list[g_brw_bkm_cntx.sel_file_index].file_extn;
	}
	else
	{
		file_extn = BRW_BKM_FILE_EXTN_NONE;
	}

    /* If no bookmarks are present, Display scren with only one option i.e 'Add bookmark' */
    switch(file_extn)
    {
		case BRW_BKM_FILE_EXTN_NONE:
		{
			if(g_brw_bkm_cntx.total_file_count)
			{
				MenuID = MENU_ID_BRW_BKM_OPTIONS_FOR_FOLDER;
			}
			else
			{
				MenuID = MENU_ID_BRW_BKM_OPTIONS_FOR_EMPTY_FOLDER;
			}
			break;
		}
		case BRW_BKM_FILE_EXTN_DFT:
		{
			MenuID = MENU_ID_BRW_BKM_OPTIONS_FOR_DEFAULT_FILE;
			break;
		}
		case BRW_BKM_FILE_EXTN_URL:
		case BRW_BKM_FILE_EXTN_VBM:
		{
			MenuID = MENU_ID_BRW_BKM_OPTIONS_FOR_USER_FILE;
			break;
		}
		default:
		{
			MenuID = MENU_ID_BRW_BKM_OPTIONS_FOR_EMPTY_FOLDER;
			break;
		}
    }

    num_of_items = GetNumOfChild(MenuID);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MenuID, UC_list_of_items);
    SetParentHandler(MenuID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
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
 *  mmi_brw_bookmarks_entry_browse_path
 * DESCRIPTION
 *  Entry function for selecting a path to copy/move a bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_browse_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	//U16 bkm_file_count=0;
	U16 title_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BOOKMARK_BROWSE_PATH, NULL, mmi_brw_bookmarks_entry_browse_path, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARK_BROWSE_PATH);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO)
	{
		title_ID = STR_ID_BRW_COPY_TO;
	}
	else
	{
		title_ID = STR_ID_BRW_MOVE_TO;
	}

	g_brw_bkm_browse_path_cntx.total_folder_count = 
		mmi_brw_bookmarks_get_only_folder_count(g_brw_bkm_browse_path_cntx.sel_folder_path);

	if(g_brw_bkm_browse_path_cntx.total_folder_count)
	{
		ShowCategory184Screen(
			title_ID,
			GetRootTitleIcon(SERVICES_WAP_MENU_ID),
			STR_GLOBAL_OPTIONS,
			0,
			STR_GLOBAL_BACK,
			0,
			g_brw_bkm_browse_path_cntx.total_folder_count,
			mmi_brw_bookmarks_folder_list_get_item,
			0,
			g_brw_bkm_browse_path_cntx.index_highlighted_item,
			guiBuffer);
	}
	else
	{
        ShowCategory213Screen(
            title_ID,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            0, 
            STR_GLOBAL_BACK,
            0,  
            0,
            NULL,
            NULL,
            0,      
            0,
            (U8*) guiBuffer);
	}

	if(IsScreenPresent(SCR_ID_BRW_BOOKMARK_BROWSE_PATH))
	{
		DeleteNScrId(SCR_ID_BRW_BOOKMARK_BROWSE_PATH);
	}

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_browse_path_pre_entry_options, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_browse_path_open_folder_directly, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_brw_bookmarks_browse_path_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_browse_path_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_entry_options
 * DESCRIPTION
 *  Entry function for select path bookmark options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* UC_list_of_items;
    U8 *guiBuffer;
    S32 num_of_items;
	S32 HideItemId = -1;
	U32 Mask = 0xffffffff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BOOKMARK_BROWSE_PATH_OPTIONS, NULL, mmi_brw_bookmarks_browse_path_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARK_BROWSE_PATH_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	mmi_brw_bookmarks_highlight_handlers_init();

	if(!mmi_ucs2cmp((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name))
	{
		HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS, MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_CREATE_FOLDER);
		if(HideItemId != -1)
		{
			ResetBit(Mask, HideItemId);
		}
	}
	else if(!g_brw_bkm_browse_path_cntx.total_folder_count)
	{
		HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS, MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_SELECT);
		if(HideItemId != -1)
		{
			ResetBit(Mask, HideItemId);
		}
		HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS, MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS_OPEN_FOLDER);
		if(HideItemId != -1)
		{
			ResetBit(Mask, HideItemId);
		}
	}

    num_of_items = GetNumOfChild(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    MaskHiliteItems(MENU_ID_BRW_BKM_BROWSE_PATH_OPTIONS, Mask);
	num_of_items = MaskItems(UC_list_of_items, (U8)num_of_items, Mask);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
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
 *  mmi_brw_bookmarks_entry_add_bookmark
 * DESCRIPTION
 *  Entry function for Add bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
	//U16 stringID = 0;
    U16 AddBookmarkImageList[2*BRW_BKM_ADD_BOOKMARK_ITEM_COUNT] = 
	{
		IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
	};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_ADD_BOOKMARK, mmi_brw_bookmarks_exit_add_bookmark, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_ADD_BOOKMARK);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();
    
	mmi_brw_bookmarks_fill_inline_struct_for_add_bookmark();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_ADD_BOOKMARK, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2*BRW_BKM_ADD_BOOKMARK_ITEM_COUNT, inputBuffer);
    }

    SetParentHandler(0);

	if (g_brw_bkm_add_type == BRW_BKM_ADD_TO_BOOKMARK)
	{
		if ((GetInlineDoneFlag(guiBuffer) == 0))
		{
			SetInlineDoneFlag(guiBuffer);
		}
		set_wgui_inline_list_menu_status(1);
	}

    ShowCategory57Screen(
		STR_ID_BRW_ADD_BOOKMARK,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2*BRW_BKM_ADD_BOOKMARK_ITEM_COUNT,
        (U16*) AddBookmarkImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(mmi_brw_bookmarks_add_bookmark_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_edit
 * DESCRIPTION
 *  Entry function for Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
	//U16 stringID = 0;
    U16 EditBookmarkImageList[2*BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT] = 
	{
		IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
	};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_EDIT_BOOKMARK, mmi_brw_bookmarks_exit_edit, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_EDIT_BOOKMARK);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();
    
	mmi_brw_bookmarks_fill_inline_struct_for_add_bookmark();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_EDIT_BOOKMARK, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2*BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT, inputBuffer);
    }

    SetParentHandler(0);

    ShowCategory57Screen(
		STR_ID_BRW_EDIT_BOOKMARK,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2*BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT,
        (U16*) EditBookmarkImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(mmi_brw_bookmarks_edit_bookmark_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_edit_from_fmgr
 * DESCRIPTION
 *  Entry function for Edit bookmark screen from File Manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_edit_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 EditBookmarkImageList[2*BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT] = 
	{
		IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
	};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_EDIT_BOOKMARK_FROM_FMGR, mmi_brw_bookmarks_exit_edit_from_fmgr, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_EDIT_BOOKMARK_FROM_FMGR);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();
    
	mmi_brw_bookmarks_fill_inline_struct_for_add_bookmark();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_EDIT_BOOKMARK_FROM_FMGR, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2*BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT, inputBuffer);
    }

    SetParentHandler(0);

    ShowCategory57Screen(
		STR_ID_BRW_EDIT_BOOKMARK,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2*BRW_BKM_EDIT_BOOKMARK_ITEM_COUNT,
        (U16*) EditBookmarkImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_exit_add_bookmark
 * DESCRIPTION
 *  Exit function for Add/Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_exit_add_bookmark(void)
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

    Scr.scrnID = SCR_ID_BRW_ADD_BOOKMARK;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_brw_bookmarks_entry_add_bookmark;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_exit_edit
 * DESCRIPTION
 *  Exit function for Add/Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_exit_edit(void)
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

    Scr.scrnID = SCR_ID_BRW_EDIT_BOOKMARK;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_brw_bookmarks_entry_edit;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_exit_edit_from_fmgr
 * DESCRIPTION
 *  Exit function for Add/Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_exit_edit_from_fmgr(void)
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
    Scr.scrnID = SCR_ID_BRW_EDIT_BOOKMARK_FROM_FMGR;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_brw_bookmarks_entry_edit_from_fmgr;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_create_folder
 * DESCRIPTION
 *  Entry function for full screen editor to enter zoom value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BKM_CREATE_FOLDER, NULL, mmi_brw_bookmarks_entry_create_folder, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BKM_CREATE_FOLDER);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if(!guiBuffer)
	{
		mmi_asc_to_ucs2((S8 *)g_brw_current_title, "");
	}

    SetHiliteHandler(MENU_ID_BRW_EDITOR_OPTION_DONE, mmi_brw_bookmarks_create_folder_editor_done_option_highlight_hdlr);

    ShowCategory215Screen(
        STR_ID_BRW_ENTER_NAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_brw_current_title,
        BRW_BKM_MAX_FILE_NAME_LEN+1,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_brw_editor_entry_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_view
 * DESCRIPTION
 *  It displays the bookmark title and URL information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 ViewBookmarkImageList[2*BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT] = 
	{
		IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
	};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_VIEW_BOOKMARK, mmi_brw_bookmarks_exit_view, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_VIEW_BOOKMARK);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();
    
	mmi_brw_bookmarks_fill_inline_struct_for_view_bookmark();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_VIEW_BOOKMARK, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2*BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT, inputBuffer);
    }

    SetParentHandler(0);


    ShowCategory57Screen(
		STR_ID_BRW_VIEW,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2*BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT,
        (U16*) ViewBookmarkImageList,
        wgui_inline_items,
        0,
        guiBuffer);

     DisableCategory57ScreenDone();
   /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_exit_view
 * DESCRIPTION
 *  Exit function for view bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_exit_view(void)
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
    Scr.scrnID = SCR_ID_BRW_VIEW_BOOKMARK;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_brw_bookmarks_entry_view;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_save_to_bookmark
 * DESCRIPTION
 *  It displays the bookmark title and URL information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_save_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 ViewBookmarkImageList[2*BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT] = 
	{
		IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
	};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SAVE_TO_BOOKMARK, mmi_brw_bookmarks_exit_save_to_bookmark, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SAVE_TO_BOOKMARK);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    InitializeCategory57Screen();
    
    DisableCategory57ScreenDone();
	
    inputBuffer = GetCurrNInputBuffer(SCR_ID_BRW_SAVE_TO_BOOKMARK, &inputBufferSize);

    SetParentHandler(0);

	mmi_brw_bookmarks_fill_inline_struct_for_view_bookmark();

	RegisterHighlightHandler(mmi_brw_bookmarks_save_to_bookmark_items_highlight_hdlr);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 2*BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT, inputBuffer);
    }

    ShowCategory57Screen(
		STR_ID_BRW_SAVE_BOOKMARK,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_ID_BRW_SAVE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2*BRW_BKM_VIEW_BOOKMARK_ITEM_COUNT,
        (U16*) ViewBookmarkImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_brw_bookmarks_save_to_bookmark);
	SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_exit_save_to_bookmark
 * DESCRIPTION
 *  Exit function for view bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_exit_save_to_bookmark(void)
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
    Scr.scrnID = SCR_ID_BRW_SAVE_TO_BOOKMARK;
    CloseCategory57Screen();
    Scr.entryFuncPtr = mmi_brw_bookmarks_entry_save_to_bookmark;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategory57History(Scr.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) Scr.inputBuffer);           /* added for inline edit history */
    AddNHistory(Scr, (U16) inputBufferSize);            /* added for inline edit history */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_send_bookmark
 * DESCRIPTION
 *  Entry function for sending bookmark file to other device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_send_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    S32 HideItemId = -1;
    U32 maskingByte = 0xffffffff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_BOOKMARK_SEND_BOOKMARK_OPTIONS, NULL, mmi_brw_bookmarks_entry_send_bookmark, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARK_SEND_BOOKMARK_OPTIONS);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    nNumofItem = GetNumOfChild(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS);
    GetSequenceStringIds(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_brw_bookmarks_send_bookmark_highlight_handlers_init(); /* Register highlight handler every time you enter into options */

#if defined(MMS_SUPPORT)
    if ( isInCall() /*|| IsScreenPresent((U16)wap_get_screen_id())*/
	#if defined (__FLIGHT_MODE_SUPPORT__)
         || (mmi_bootup_get_active_flight_mode() == 1)
    #endif /* defined(__FLIGHT_MODE_SUPPORT__) */
         || (!mmi_bootup_is_sim_valid())
		)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_MMS);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
        }
    }
#endif /* defined(MMS_SUPPORT) */ 

	if ( !mmi_bootup_is_sim_valid()
    #if defined (__FLIGHT_MODE_SUPPORT__)
         || (mmi_bootup_get_active_flight_mode() == 1)
    #endif
        )
    {
		#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
			HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, MENU_ID_BRW_BKM_SEND_BOOKMARK_AS_SMS);
			if (HideItemId != -1)
			{
				ResetBit(maskingByte, HideItemId);
			}
		#endif /* !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__) */

		#if  defined(__MMI_IRDA_SUPPORT__)	 
			HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_INFRARED);
			if (HideItemId != -1)
			{
				ResetBit(maskingByte, HideItemId);
			}
		#endif	/* __MMI_IRDA_SUPPORT__ */

		#if  defined(__MMI_EMAIL__)
			HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_EMAIL);
			if (HideItemId != -1)
			{
				ResetBit(maskingByte, HideItemId);
			}
		#endif /* __MMI_EMAIL__ */
    }

#if defined(__MMI_OPP_SUPPORT__)
	if((mmi_bootup_get_active_flight_mode() == 1))
	{
		HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, MENU_ID_BRW_BKM_SEND_BOOKMARK_VIA_BLUETOOTH);
		if (HideItemId != -1)
		{
			ResetBit(maskingByte, HideItemId);
		}
	}
#endif /* __MMI_OPP_SUPPORT__ */

	MaskHiliteItems(MENU_ID_BRW_BKM_SEND_BOOKMARK_OPTIONS, maskingByte);
	nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);

    ShowCategory15Screen(
        STR_ID_BRW_SEND_BOOKMARK,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);


	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_entry_open_from_fmgr
 * DESCRIPTION
 *  Entry function for Bookmark options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_open_from_fmgr(void)
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
    EntryNewScreen(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR, NULL, mmi_brw_bookmarks_entry_open_from_fmgr, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

	if( (mmi_bootup_is_network_service_available() == MMI_FALSE) ||
        (mmi_bootup_get_active_flight_mode() == MMI_TRUE)
	  )
	{
		mmi_frm_hide_menu_item(MENU_ID_BRW_BKM_GOTO_FROM_FMGR);
	}
	else
	{
		mmi_frm_unhide_menu_item(MENU_ID_BRW_BKM_GOTO_FROM_FMGR);
	}

    num_of_items = GetNumOfChild_Ext(MENU_ID_BRW_BKM_OPTIONS_OPEN_FROM_FMGR);
	UC_list_of_items = OslMalloc(sizeof(U16)*num_of_items);
    GetSequenceStringIds_Ext(MENU_ID_BRW_BKM_OPTIONS_OPEN_FROM_FMGR, UC_list_of_items);
    SetParentHandler(MENU_ID_BRW_BKM_OPTIONS_OPEN_FROM_FMGR);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_ID_BRW_OPTION,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
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
 *  mmi_brw_bookmarks_entry_select_bookmark
 * DESCRIPTION
 *  Entry function for Bookmark list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_entry_select_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	//U16 bkm_file_count=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_BRW_SELECT_BOOKMARK, NULL, mmi_brw_bookmarks_entry_select_bookmark, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_SELECT_BOOKMARK);

	/*it saves the current screen as the browser top most screen*/
	mmi_brw_set_top_screen_id();

    RegisterHighlightHandler(mmi_brw_bookmarks_select_bookmark_highlight_hdlr);

	mmi_brw_bookmarks_allocate_file_info_list();

	ShowCategory184Screen(
		STR_ID_BRW_BOOKMARKS,
		GetRootTitleIcon(SERVICES_WAP_MENU_ID),
		STR_GLOBAL_OPTIONS,
		0,
		STR_GLOBAL_BACK,
		0,
		g_brw_bkm_cntx.total_file_count,
		mmi_brw_bookmarks_list_get_item,
		0,
		g_brw_bkm_cntx.index_highlighted_item,
		guiBuffer);

	if(IsScreenPresent(SCR_ID_BRW_SELECT_BOOKMARK))
	{
		DeleteNScrId(SCR_ID_BRW_SELECT_BOOKMARK);
	}

    SetRightSoftkeyFunction(mmi_brw_bookmarks_select_bookmark_go_back_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_bookmarks_select_bookmark_go_back_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
/******************************************** ENTRY FUNCTIONS - END ********************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_file_confirm(void)
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
        get_string(STR_ID_BRW_DELETE_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_delete_file, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_folder_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 *  directory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_folder_confirm(void)
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
        get_string(STR_ID_BRW_DELETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_delete_folder, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_replace_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for replacing an existing 
 *  bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_replace_file_confirm(void)
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
        get_string(STR_ID_BRW_FILE_ALREADY_EXISTS_REPLACE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

	if(GetCurrScrnId() == SCR_ID_BRW_ADD_BOOKMARK)
	{
		SetLeftSoftkeyFunction(mmi_brw_bookmarks_add_bookmark_replace_file, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
	else if(GetCurrScrnId() == SCR_ID_BRW_EDIT_BOOKMARK)
	{
		SetLeftSoftkeyFunction(mmi_brw_bookmarks_edit_bookmark_replace_file, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
	else if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO ||
		    g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_MOVE_TO )
	{
		SetLeftSoftkeyFunction(mmi_brw_bookmarks_browse_path_replace_file, KEY_EVENT_UP);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for replacing an existing 
 *  bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file_confirm(void)
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
        get_string(STR_ID_BRW_FILE_ALREADY_EXISTS_REPLACE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

	SetLeftSoftkeyFunction(mmi_brw_bookmarks_edit_bookmark_replace_file, KEY_EVENT_UP);
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_all_user_files_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of all the bookmarks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_all_user_files_confirm(void)
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
        get_string(STR_ID_BRW_DELETE_ALL_FILES),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_delete_all_user_files, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_fill_inline_struct_for_add_bookmark
 * DESCRIPTION
 *  Function to fill values in common inline structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_fill_inline_struct_for_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //InlineItem brw_bookmark_inline_edit_list[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For title caption */
    SetInlineItemActivation(
        &wgui_inline_items[BRW_INLINE_TITLE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[BRW_INLINE_TITLE_CAPTION],
        (U8*) GetString(STR_ID_BRW_TITLE));

    /* For title string */
    SetInlineItemActivation(
		&wgui_inline_items[BRW_INLINE_TITLE],
		KEY_LSK, 
		KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[BRW_INLINE_TITLE],
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_brw_current_title,
        BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1,
        (INPUT_TYPE_ALPHANUMERIC_SENTENCECASE | INPUT_TYPE_ONE_LESS_CHARACTER),
		INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[BRW_INLINE_TITLE],
        mmi_brw_bookmarks_full_screen_edit);

    /* For Address caption */
    SetInlineItemActivation(
        &wgui_inline_items[BRW_INLINE_ADDRESS_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[BRW_INLINE_ADDRESS_CAPTION],
        (U8*) GetString(STR_ID_BRW_ADDRESS));

    /* For Address string (URL) */
    SetInlineItemActivation(
		&wgui_inline_items[BRW_INLINE_URL], 
		KEY_LSK, 
		KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext(
        &wgui_inline_items[BRW_INLINE_URL],
        STR_ID_BRW_EDIT,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        (U8*) g_brw_current_url,
        BRW_MAX_URL_LENGTH+1,
        (INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES),
		INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
    SetInlineFullScreenEditCustomFunction(
		&wgui_inline_items[BRW_INLINE_URL], 
		mmi_brw_bookmarks_full_screen_edit);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_full_screen_edit
 * DESCRIPTION
 *  Callback for full screen edit from inline edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_full_screen_edit(void)
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
 *  mmi_brw_bookmarks_fill_inline_struct_for_view_bookmark
 * DESCRIPTION
 *  Function to fill values in view bookmark inline structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_fill_inline_struct_for_view_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For title caption */
    SetInlineItemActivation(
        &wgui_inline_items[BRW_INLINE_TITLE_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[BRW_INLINE_TITLE_CAPTION],
        (U8*) GetString(STR_ID_BRW_TITLE));

    /* For title string */
    SetInlineItemActivation(
		&wgui_inline_items[BRW_INLINE_TITLE],
		KEY_LSK, 
		KEY_EVENT_UP);
	SetInlineItemDisplayOnly((&wgui_inline_items[BRW_INLINE_TITLE]), 
		(U8*) g_brw_bkm_cntx.sel_file_name);

    /* For Address caption */
    SetInlineItemActivation(
        &wgui_inline_items[BRW_INLINE_ADDRESS_CAPTION],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &wgui_inline_items[BRW_INLINE_ADDRESS_CAPTION],
        (U8*) GetString(STR_ID_BRW_ADDRESS));

    /* For Address string (URL) */
    SetInlineItemActivation(
		&wgui_inline_items[BRW_INLINE_URL], 
		KEY_LSK, 
		KEY_EVENT_UP);
	SetInlineItemDisplayOnly((&wgui_inline_items[BRW_INLINE_URL]), 
		(U8*) g_brw_bkm_cntx.sel_file_url);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_add_bookmark_confirm
 * DESCRIPTION
 *  Entry screen for confirmation
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_add_bookmark_confirm(void)
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
        get_string(STR_ID_BRW_SAVE_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_add_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_bookmarks_confirm_dialog_GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_confirm
 * DESCRIPTION
 *  Entry screen for confirmation
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_confirm(void)
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
        get_string(STR_ID_BRW_SAVE_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_edit_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_bookmarks_confirm_dialog_GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm
 * DESCRIPTION
 *  Entry screen for confirmation
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm(void)
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
        get_string(STR_ID_BRW_SAVE_BOOKMARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_bookmarks_edit_bookmark_from_fmgr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm_dialog_GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERBOOKMARKSUI_C */ 

