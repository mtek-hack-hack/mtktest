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
 * EbookSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Ebook Application implementation *********************/

/**************************************************************

   FILENAME : EbookSrc.c

   PURPOSE     : Ebook Appliocation

   REMARKS     : nil

   AUTHOR      : Rajat Kumar

   DATE     : 

**************************************************************/

/*  */
#include "MMI_include.h"
#include "SettingProfile.h"

#ifdef __MMI_EBOOK_READER__
#include "gpioInc.h"
#include "FileManagerDef.h"
#include "FileManagerGprot.h"
#include "EbookDefs.h"
#include "EbookProt.h"
#include "EbookManager.h"
#include "CommonScreens.h"
#include "DownloadDefs.h"
#include "wgui_inputs.h"
#include "drm_gprot.h"
#include "SimDetectionDef.h"
#include "USBDeviceGprot.h"

#ifdef __MMI_BPP_SUPPORT__
#include "BTMMICm.h"
#include "BTMMIBppGprot.h"
#include "BTMMIBppXhtmlGprot.h"
#include "SimDetectionGprot.h"
#endif /* __MMI_BPP_SUPPORT__ */ 

/* Global Variables */
extern pBOOL IsBackHistory;
g_ebook_app_cntx g_ebook_app_context;
g_ebook_app_cntx *g_ebook_app_cntx_p = &g_ebook_app_context;
EBOOKSET_CNTX g_ebookset_cntx;
EBOOKSET_CNTX *g_ebookset_cntx_p = &g_ebookset_cntx;
gui_page_info_app ebook_frm_setting_struct;
gui_page_info_app *ebook_frm_setting = &ebook_frm_setting_struct;


/*****************************************************************************
 * FUNCTION
 *  mmi_ebook_usb_mode_on
 * DESCRIPTION
 *  For USB Power On Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebook_usb_mode_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DisplayPopup((PU8)GetString(STR_NO_BOOK_MARK_PRESENT),IMG_GLOBAL_WARNING,1,EBR_ST_NOTIFYDURATION,ERROR_TONE); */
    g_ebookset_cntx_p->is_usb_plugged_in = TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebook_usb_mode_off
 * DESCRIPTION
 *  For USB Power On Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebook_usb_mode_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebookset_cntx_p->is_usb_plugged_in = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_book_shel_screen
 * DESCRIPTION
 *  Entry function for book shelf screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_book_shel_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S16 local_nfo_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_ebookset_cntx_p->is_usb_plugged_in == TRUE)
    {
    #ifdef __USB_IN_NORMAL_MODE__
        mmi_usb_app_unavailable_popup(0);
    #endif 
    return;
    }
    
    EntryNewScreen(EBOOK_BOOKSHELF_SCREENID, ebr_exit_book_shel_screen, NULL, NULL);
    
    ebr_frm_set_src_application_type();
    ebr_frm_delete_unused_nfo_file();
    local_nfo_id = ebr_frm_read_from_nvram();
    ebr_frm_check_is_nfo_file_exist(local_nfo_id);
    local_nfo_id = ebr_frm_read_from_nvram();
    if (local_nfo_id > 0)
    {
        gdi_layer_lock_frame_buffer();
    }
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_EBOOK_TXT);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_EBOOK_PDB);
        mmi_fmgr_select_path_and_enter(
            APP_EBOOK,
            FMGR_SELECT_BROWSE,
            filter,
            (PS8) ebr_frm_get_path_for_bookshelf(),
            ebr_book_file_callback);
    }
    if (local_nfo_id > 0)
    {
        gdi_layer_unlock_frame_buffer();
        ebr_frm_set_file_name(local_nfo_id);
        ebr_entry_open_book();
    }
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  ebr_exit_book_shel_screen
 * DESCRIPTION
 *  Exit function of book shelf screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_exit_book_shel_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 local_id = 0;
    U8 isShelfExist = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	if (!IsScreenPresent(EBOOK_BOOKSHELF_SCREENID))
	{
		GenericExitScreen(EBOOK_BOOKSHELF_SCREENID, ebr_entry_book_shel_screen);
        isShelfExist = 0;
	}
	else if(GetExitScrnID() == EBOOK_BOOKSHELF_SCREENID)
	{
		GenericExitScreen(EBOOK_BOOKSHELF_SCREENID, ebr_entry_book_shel_screen);
	}

    /* If bookshelf screen will entry open book screen directly, 
    EBOOK_BOOKSHELF_SCREENID should be deleted manually 
    because decrease command in goback procedure won't be executed 
    The condition entry ebook reader by previous reading should be exclusive*/
    local_id = ebr_frm_read_from_nvram();
    if (local_id > 0 && isShelfExist == 1)
    {
        DeleteNScrId(EBOOK_BOOKSHELF_SCREENID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  InitEbookApp
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitEbookApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_EBK_RFS_OPTION, ebr_highlight_refresh_book_shelf);
    SetHiliteHandler(MENU_ID_EBK_RFS_OPTION_LIMITED, ebr_highlight_refresh_book_shelf);
    SetHiliteHandler(MENU_ID_EBK_OPEN, ebr_highlight_open_ebook);
    SetHiliteHandler(MENU_ID_EBK_INFO, ebr_higlight_book_info);

    SetHiliteHandler(MENU_ID_EBK_DELETE, ebr_highlight_delete_ebook);
    SetHiliteHandler(MENU_ID_EBK_HELP, ebr_highlight_help);
    SetHiliteHandler(MENU_ID_EBK_SETTINGS, ebr_highlight_book_shelf_settings);
    SetHiliteHandler(MENU_ID_EBK_SETTINGS_LIMITED, ebr_highlight_book_shelf_settings);

    SetHiliteHandler(MENU_ID_EBK_FIND, ebr_highlight_search);
    SetHiliteHandler(MENU_ID_EBK_FIND_NEXT, ebr_highlight_search_next);
    SetHiliteHandler(MENU_ID_EBK_JUMP, ebr_highlight_jump_to);
    SetHiliteHandler(MENU_ID_EBK_GOTO_BOOKMARK, ebr_highlight_goto_book_mark);
    SetHiliteHandler(MENU_ID_EBK_REMOVE_BOOKMARK, ebr_highlight_remove_book_mark);
    SetHiliteHandler(MENU_ID_EBK_ADD_BOOKMARK, ebr_highlight_add_book_mark);
    SetHiliteHandler(MENU_ID_EBK_BOOK_SETTINGS, ebr_highlight_book_settings);
    SetHiliteHandler(MENU_ID_EBK_BOOK_INFO, ebr_highlight_open_book_info);
    SetHiliteHandler(MENU_ID_EBK_CLOSE, ebr_close_book);

    SetHiliteHandler(MENU_ID_EBK_CASE_SENSITIVE, ebr_highlight_case_sensitive_serach);
    SetHiliteHandler(MENU_ID_EBK_CASE_INSENSITIVE, ebr_highlight_case_in_sensitive_serach);
    SetHiliteHandler(MENU_ID_EBK_BOOK_RESTORE_DEFAULT, ebr_highlight_ebk_restore_default);
    SetHiliteHandler(MENU_ID_EBK_DELETE_ALL, ebr_highlight_delete_all);
    SetHiliteHandler(MENU_ID_EBK_RESTORE_DEFAULT, ebr_highlight_book_shelf_restore_default);
#ifdef __MMI_BPP_SUPPORT__
    SetHiliteHandler(MENU_ID_EBK_BPP_PRINT, ebr_highlight_book_bpp_print);
#endif 
    memset(g_ebook_app_cntx_p->ebr_search_string_input, 0, sizeof(g_ebook_app_cntx_p->ebr_search_string_input));
    ebr_frm_init();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_book_file_callback
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_book_file_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteScreenIfPresent(EBOOK_BOOKSHELF_SCREENID);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  ebr_book_fmgr_empty_list_callback
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_book_fmgr_empty_list_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteScreenIfPresent(EBOOK_BOOKSHELF_SCREENID);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  ebr_show_limit_book_shelf_option
 * DESCRIPTION
 *  Options for Limited Book Shelf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_show_limit_book_shelf_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];
    U8 *hintList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EBOOK_OPEN_OPTION_SCREENID, NULL, ebr_show_limit_book_shelf_option, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_OPEN_OPTION_SCREENID);
    
    nNumofItem = GetNumOfChild(MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION);
    GetSequenceStringIds(MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION, nStrItemList);
    GetSequenceImageIds(MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION, nImgIltemList);
    SetParentHandler(MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION);
    
    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_EBK_BOOKSHELF_OPTION, hintList);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebook_get_menuId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_ebook_get_menuId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count_no_of_nfo_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count_no_of_nfo_file = ebr_frm_get_total_countof_nfo_file();
    ebr_frm_write_default_value_for_nfo_id_in_nvram();
    if (count_no_of_nfo_file <= 0)
    {
        return MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION;
    }
    else
    {
        return MENU_ID_EBK_BOOKSHELF_OPTION;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_refresh_book_shelf
 * DESCRIPTION
 *  Refreshed Book Shelf Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_refresh_book_shelf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_please_wait_actual_screen_2();
    ebr_frm_entry_refresh_book_shelf();
    DisplayPopup(
        (PU8) GetString(STR_BOOK_SHELF_REFRESHED),
        IMG_GLOBAL_ACTIVATED,
        1,
        EBR_ST_NOTIFYDURATION,
        SUCCESS_TONE);
    if (IsScreenPresent(SCR_FMGR_APP_FILE_OPTION))
    {
        DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
    }
    else
    {
        DeleteNScrId(EBOOK_OPEN_OPTION_SCREENID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_refresh_book_shelf
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_refresh_book_shelf(void)
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
    SetLeftSoftkeyFunction(ebr_entry_refresh_book_shelf, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_ebk_restore_default
 * DESCRIPTION
 *  Set highlight handler for Restore Default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_ebk_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(ebr_app_restore_default_book_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_delete_all
 * DESCRIPTION
 *  Set highlight handler Delete All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    highlight_fmgr_delete_all_file();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_book_shelf_restore_default
 * DESCRIPTION
 *  Set highlight handler for Restore Default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_book_shelf_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(ebr_app_restore_default_book_shelf_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_open_ebook
 * DESCRIPTION
 *  Set highlight handler for Open book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_open_ebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_kernel_get_file_info(mmi_fmgr_kernel_get_cur_idx(), &file_info);
    ebr_set_selected_file_name(&file_info);
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(ebr_entry_open_book, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_open_book, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_higlight_book_info
 * DESCRIPTION
 *  Set highlight handler for Book Info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_higlight_book_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_book_info, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_book_info, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_delete_ebook
 * DESCRIPTION
 *  Set highlight handler for Delete Book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_delete_ebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_delete_book_popup, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_delete_book_popup
 * DESCRIPTION
 *  Display popUp for Delete and confirm deletion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_delete_book_popup(void)
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
        get_string(STR_EBOOK_DELETE_INQUIRE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ebr_entry_delete_ebook, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_help
 * DESCRIPTION
 *  Set highlight handler for Help
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_help, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_help, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_book_shelf_settings
 * DESCRIPTION
 *  Set highlight handler for Settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_book_shelf_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_settings, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    g_ebook_app_cntx_p->ebr_set_local_setting_flag = 0;
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_search
 * DESCRIPTION
 *  Set highlight handler for Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_search, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_search, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_search_next
 * DESCRIPTION
 *  Set highlight handler for find next Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_search_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_app_search_string_next_from_menu, KEY_EVENT_UP);
    SetKeyHandler(ebr_app_search_string_next_from_menu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_search_result_successful
 * DESCRIPTION
 *  Set the flag
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_search_result_successful(pBOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebook_app_cntx_p->ebr_search_found_next_flag = result;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_search_string_next_from_menu
 * DESCRIPTION
 *  Shows the Find NExt menu option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_search_string_next_from_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LANG_HINDI__
    pBOOL full_character;
#endif 
	S32 search_satus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    ebr_please_wait_actual_screen_2();
#ifdef __MMI_LANG_HINDI__
    full_character = ebr_frm_check_for_full_characters((S16*) g_ebook_app_cntx_p->ebr_search_string_input);
    if (!full_character)
    {
        ebr_app_show_string_incomplete_pop_up();
        return;
    }
#endif /* __MMI_LANG_HINDI__ */ 
	search_satus = ebr_frm_search_string_algo_find_next();
	if (search_satus == 0xFF)
    {
        return;
    }
    if (search_satus==1)
    {
        ebr_app_search_result_successful(TRUE);
        ebr_app_delete_upto_open_book_screen_id();
        GoBackHistory();
        ebr_frm_set_data_for_display();
    }
    else
    {
        if(search_satus==2)
		{
			ebr_app_search_result_invalid();
		}
		else
		{
        ebr_app_search_result_unsucessfull();
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_search_string_next
 * DESCRIPTION
 *  called when find next is executed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_search_string_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LANG_HINDI__
    pBOOL full_character;
#endif 
	S32 search_satus;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_set_find_next_flag();
	if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    ebr_please_wait_actual_screen_2();
#ifdef __MMI_LANG_HINDI__
    full_character = ebr_frm_check_for_full_characters((S16*) g_ebook_app_cntx_p->ebr_search_string_input);
    if (!full_character)
    {
        ebr_app_show_string_incomplete_pop_up();
        return;
    }
#endif /* __MMI_LANG_HINDI__ */ 
	search_satus = ebr_frm_search_string_algo_find_next();
	if (search_satus == 0xFF)
    {
        return;
    }
    else if (search_satus==1)
    {
        ebr_app_search_result_successful(TRUE);
        g_ebook_app_cntx_p->enable_screen_exit = 0;
        EntryNewScreen(SCR_ID_EBOOK_WAITSCREEN, NULL, NULL, NULL);
        g_ebook_app_cntx_p->enable_screen_exit = 1;
        ebr_app_delete_upto_open_book_screen_id();
        GoBackHistory();
        ebr_frm_set_data_for_display();
    }
    else
    {
        if(search_satus==2)
		{
			ebr_app_search_result_invalid();
		}
		else
		{
        ebr_app_search_result_unsucessfull();
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_jump_to
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_jump_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_jump_to, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_jump_to, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    memset(g_ebook_app_cntx_p->percentage_val, 0, (EBR_MAX_EBOOK_PERCENTAGE_VALUE + 1) * ENCODING_LENGTH);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_pre_entry_jump_to
 * DESCRIPTION
 *  Pre Entry function for jumpTo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_pre_entry_jump_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ebook_app_cntx_p->percentage_val, 0, (EBR_MAX_EBOOK_PERCENTAGE_VALUE + 1) * ENCODING_LENGTH);
    ebr_entry_jump_to();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_goto_book_mark
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_goto_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_goto_book_mark, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_goto_book_mark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_remove_book_mark
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_remove_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_remove_book_mark, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_remove_book_mark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_remove_book_mark
 * DESCRIPTION
 *  Entry Function for Remove Bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_remove_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S16 no_of_book_marks = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    no_of_book_marks = ebr_frm_get_count_of_book_marks();

    EntryNewScreen(EBOOK_REMOVE_BOOKMARK_SCREENID, NULL, ebr_entry_remove_book_mark, NULL);

    guiBuffer = GetCurrGuiBuffer(EBOOK_REMOVE_BOOKMARK_SCREENID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(0);
    if (no_of_book_marks == 0)
    {   /*   ShowCategory184Screen(STR_RMV_BOOKMARK_EBOOK, (U16)NULL,
           0, 0,
           STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
           no_of_book_marks,ebr_get_book_mark_name_list,
           NULL, 0, guiBuffer); */
        DisplayPopup(
            (PU8) GetString(STR_NO_BOOK_MARK_PRESENT),
            IMG_GLOBAL_WARNING,
            1,
            EBR_ST_NOTIFYDURATION,
            EMPTY_LIST_TONE);
        DeleteNScrId(EBOOK_REMOVE_BOOKMARK_SCREENID);
        return;

        /* GoBackHistory(); */

    }
    else
    {
        ShowCategory184Screen(
            STR_RMV_BOOKMARK_EBOOK,
            GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            no_of_book_marks,
            ebr_get_book_mark_name_list,
            NULL,
            0,
            guiBuffer);
    }

    /* register LSK and right key handlers */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(ebr_delete_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_delete_bookmark
 * DESCRIPTION
 *  PopuUp display for deletion of BookMark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_delete_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_DELETE_BOOK_MARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ebr_remove_selected_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_goto_book_mark
 * DESCRIPTION
 *  Entry Function for Go to BookMark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_goto_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S16 no_of_book_marks = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    no_of_book_marks = ebr_frm_get_count_of_book_marks();

    EntryNewScreen(EBOOK_GOTO_BOOKMARK_SCREENID, NULL, ebr_entry_goto_book_mark, NULL);

    guiBuffer = GetCurrGuiBuffer(EBOOK_GOTO_BOOKMARK_SCREENID);
    RegisterHighlightHandler(ebr_highlight_selected_bookmark);
    SetParentHandler(0);
    if (no_of_book_marks == 0)
    {   /* ShowCategory184Screen(STR_GOTO_BOOKMARK_EBOOK, (U16)NULL,
           0, 0,
           STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
           no_of_book_marks ,ebr_get_book_mark_name_list,
           NULL, 0, guiBuffer); */
        DisplayPopup(
            (PU8) GetString(STR_NO_BOOK_MARK_PRESENT),
            IMG_GLOBAL_WARNING,
            1,
            EBR_ST_NOTIFYDURATION,
            EMPTY_LIST_TONE);
        DeleteNScrId(EBOOK_GOTO_BOOKMARK_SCREENID);
        return;

    }
    else
    {
        ShowCategory184Screen(
            STR_GOTO_BOOKMARK_EBOOK,
            GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            no_of_book_marks,
            ebr_get_book_mark_name_list,
            NULL,
            0,
            guiBuffer);
    }
    /* register LSK and right key handlers */
    SetLeftSoftkeyFunction(ebr_goto_selected_bookmark, KEY_EVENT_UP);
    SetKeyHandler(ebr_goto_selected_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_selected_bookmark
 * DESCRIPTION
 *  Highlight Handler for Go to BookMark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_selected_bookmark(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebook_app_cntx_p->current_selected_bookmark = index;
    SetKeyHandler(ebr_goto_selected_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  ebr_goto_selected_bookmark
 * DESCRIPTION
 *  Entry Function for Go to BookMark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_goto_selected_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    ebr_frm_get_record_for_bookmark(g_ebook_app_cntx_p->current_selected_bookmark);
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_remove_selected_bookmark
 * DESCRIPTION
 *  Exit function for Delete book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_remove_selected_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_remove_bookmark(GetCurrHiliteID());
    if (IsScreenPresent(EBOOK_BOOK_SETTINGS_SCREENID))
    {
        DeleteUptoScrID(EBOOK_BOOK_SETTINGS_SCREENID);
    }
    else
    {
        DeleteNScrId(EBOOK_REMOVE_BOOKMARK_SCREENID);
    }

    DisplayPopup((PU8) GetString(STR_DELETED), IMG_GLOBAL_ACTIVATED, 1, EBR_ST_NOTIFYDURATION, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_add_book_mark
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_add_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_add_book_mark, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_add_book_mark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_add_book_mark
 * DESCRIPTION
 *  Entry function for Add book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_add_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S16 no_of_book_marks = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    no_of_book_marks = ebr_frm_get_count_of_book_marks();
    if (no_of_book_marks >= EBR_FRM_MAX_NO_OF_BOOKMARKS)
    {
        /* Display Pop up that no more BookMarks can be added */
        if (IsScreenPresent(EBOOK_BOOK_SETTINGS_SCREENID))
        {
            DeleteUptoScrID(EBOOK_BOOK_SETTINGS_SCREENID);
        }
        DisplayPopup((PU8) GetString(STR_MAX_BOOK_MARK), IMG_GLOBAL_WARNING, 1, EBR_ST_NOTIFYDURATION, ERROR_TONE);
        return;

    }
    EntryNewScreen(EBOOK_ADD_BOOK_MARK_SCREEN_ID, NULL, ebr_entry_add_book_mark, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_ADD_BOOK_MARK_SCREEN_ID);
    if (guiBuffer == NULL)
    {
        ebr_frm_get_default_name_of_book_marks((S8*)g_ebook_app_cntx_p->book_mark_name);
    }

    ShowCategory5Screen(
        STR_ADD_BOOKMARK_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        g_ebook_app_cntx_p->book_mark_name,
        EBR_FRM_MAX_BOOKMARK_NAME_SIZE + 1,
        guiBuffer);
    SetLeftSoftkeyFunction(ebr_entry_book_mark_edit_list, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_book_mark_edit_list
 * DESCRIPTION
 *  Entry function for Add book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_book_mark_edit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[2];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_EDIT_BOOK_MARK_NAME, NULL, ebr_entry_book_mark_edit_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_EDIT_BOOK_MARK_NAME);

    nItems = GetNumOfChild(MENU_EBOOK_EDIT_BOOK_MARK_NAME);
    GetSequenceStringIds(MENU_EBOOK_EDIT_BOOK_MARK_NAME, ItemList);

    RegisterHighlightHandler(ebr_get_add_book_mark_options);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(ebr_get_add_book_mark, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_get_add_book_mark
 * DESCRIPTION
 *  Processing for Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_get_add_book_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_ebook_app_cntx_p->current_highlighted_item)
    {
        case 0:
            ebr_frm_add_book_mark_pre_entry();
            break;
        case 1: /* Input Methods */
            EntryInputMethodScreen();
            RegisterInputMethodScreenCloseFunction(GoBackHistoryFromInputMethod);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_get_add_book_mark_options
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_get_add_book_mark_options(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebook_app_cntx_p->current_highlighted_item = nIndex;
    switch (nIndex)
    {
        case 0: /* Done */
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case 1: /* Input Methods */
            SetKeyHandler(ebr_get_add_book_mark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        default:
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistoryFromInputMethod
 * DESCRIPTION
 *  Go back History
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistoryFromInputMethod(void)
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
 *  ebr_get_book_mark_name
 * DESCRIPTION
 *  Get book mark name
 * PARAMETERS
 *  void
 * RETURNS
 *  S8*
 *****************************************************************************/
S8 *ebr_get_book_mark_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) g_ebook_app_cntx_p->book_mark_name;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_book_settings
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_book_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_settings, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    g_ebook_app_cntx_p->ebr_set_local_setting_flag = 1;
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_open_book_info
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_open_book_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_book_info, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_book_info, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_close_book
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_close_book(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_entry_close_book, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_close_book, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_case_in_sensitive_serach
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_case_in_sensitive_serach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_ebook_search_string, KEY_EVENT_UP);
    SetKeyHandler(ebr_ebook_search_string, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_case_sensitive_serach
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_case_sensitive_serach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetLeftSoftkeyFunction(ebr_ebook_search_string, KEY_EVENT_UP);
    SetKeyHandler(ebr_ebook_search_string, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_jump_to
 * DESCRIPTION
 *  Entry Function for jumpTo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_jump_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer;
    U16 nNumofItem = 4; /* Stores no of children in the submenu */
    U16 inputBufferSize;
    S16 item_index = 0;
    S32 book_size;
    S32 page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    book_size = ebr_frm_get_book_temp_size_from_nfo();
    page_size = ebr_frm_get_page_size();
    if (book_size <= page_size)
    {
        DisplayPopup((PU8) GetString(STR_BOOK_TOO_SMALL), IMG_GLOBAL_WARNING, 1, EBR_ST_NOTIFYDURATION, WARNING_TONE);
        return;
    }
    EntryNewScreen(EBOOK_JUMPTO_SCREEN_ID, ebr_exit_jump_to, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_JUMPTO_SCREEN_ID);
    inputBuffer = GetCurrNInputBuffer(EBOOK_JUMPTO_SCREEN_ID, &inputBufferSize);        /* added for inline edit history */

    InitializeCategory57Screen();

    ebr_fill_settings_inline_edit_struct((void*)&wgui_inline_items);

    g_ebook_app_cntx_p->ebook_jump_text_end_beg[EBR_JUMP_BEGIN] = (U8*) GetString(STR_JMP_BEG_EBOOK);
    g_ebook_app_cntx_p->ebook_jump_text_end_beg[EBR_JUMP_MIDDLE] = (U8*) GetString(STR_JMP_MID_EBOOK);
    g_ebook_app_cntx_p->ebook_jump_text_end_beg[EBR_JUMP_END] = (U8*) GetString(STR_JMP_END_EBOOK);

    SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[item_index], (PU8) (U8*) GetString(STR_JUMP_EBOOK));

    SetInlineItemActivation(&wgui_inline_items[++item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[item_index],
        3,
        g_ebook_app_cntx_p->ebook_jump_text_end_beg,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItem) /* CurrSelect */ );

    SetInlineItemActivation(&wgui_inline_items[++item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[item_index], (PU8) (U8*) GetString(STR_JMP_PERCENTAGE_EBOOK));

    SetInlineItemActivation(&wgui_inline_items[++item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&(wgui_inline_items[item_index]), (U8*) "1");

    RegisterHighlightHandler(ebr_highlight_jump_to_item);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, nNumofItem, inputBuffer);
    }

    if (GetInlineDoneFlag(guiBuffer) == 0 && g_ebook_app_cntx_p->percentage_val == '\0')
    {
        SetInlineDoneFlag(guiBuffer);
    }
    ShowCategory57Screen(
        STR_JUMP_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        NULL,
        wgui_inline_items,
        0,
        guiBuffer);

    /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(ebr_entry_jump_to_done_hndlr, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_jump_to_item
 * DESCRIPTION
 *  Changes the Left soft key options in case of Percentage
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_jump_to_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 3)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(ebr_entry_percentage_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_percentage_screen
 * DESCRIPTION
 *  Entry Function for Percentage Screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_percentage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_EBOOK_ENTER_PERCENTAGE_SCREEN_ID, NULL, ebr_entry_percentage_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_EBOOK_ENTER_PERCENTAGE_SCREEN_ID);
    SetParentHandler(0);

    ShowCategory5Screen(
        STR_PERCENTAGE_SCREEN,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        (U16) STR_GLOBAL_OK,
        (U16) IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC,
        (U8*) g_ebook_app_cntx_p->percentage_val,
        (S32) EBR_MAX_EBOOK_PERCENTAGE_VALUE + 1,
        guiBuffer);

    SetLeftSoftkeyFunction(ebr_go_back_to_inline_edit_screen, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_go_back_to_inline_edit_screen
 * DESCRIPTION
 *  Screen for the percentage editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_go_back_to_inline_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 percentage_number_buffer[4] = {0};
    S16 percantage_val = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*) percentage_number_buffer, (S8*) g_ebook_app_cntx_p->percentage_val);
    percantage_val = atoi((char const*)percentage_number_buffer);
    if ((percantage_val > 0) && (percantage_val <= 100))
    {

    }
    else
    {
        /* DeleteNScrId(EBOOK_JUMPTO_DONE_SCREEN_ID); */
        DisplayPopup(
            (PU8) GetString(STR_WRONG_PERCENTAGE_VALUE),
            IMG_GLOBAL_ERROR,
            1,
            EBR_ST_NOTIFYDURATION,
            ERROR_TONE);
        return;
    }

    ebr_frm_jump_to_record(percantage_val, g_ebookset_cntx_p->inlineHighligtItem);

    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_exit_jump_to
 * DESCRIPTION
 *  Exit function for Jump To
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_exit_jump_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = EBOOK_JUMPTO_SCREEN_ID;
    CloseCategory57Screen();
    Scr.entryFuncPtr = ebr_entry_jump_to;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) Scr.inputBuffer);
    AddNHistory(Scr, size);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_jump_to_done_hndlr
 * DESCRIPTION
 *  Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_jump_to_done_hndlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 percantage_val = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Call Exit Handler */

    if (IsScreenPresent(SCR_FMGR_APP_FILE_OPTION))
    {
        EntryNewScreen(EBOOK_JUMPTO_DONE_SCREEN_ID, NULL, NULL, NULL);
    }

    ebr_frm_jump_to_record(percantage_val, g_ebookset_cntx_p->inlineHighligtItem);

    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_close_book
 * DESCRIPTION
 *  Entry Function for Close
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_close_book(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nfo_id = 0;
    pBOOL is_src_app_is_file_manager;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_rwrite_into_nvram(nfo_id);
    is_src_app_is_file_manager = ebr_frm_ebook_exit(EBR_FRM_EXIT_BY_CLOSE_BOOK);
    if (is_src_app_is_file_manager)
    {
        if (IsScreenPresent(SCR_FMGR_FILE_OPTION))
        {
            ebr_frm_remove_last_directory();
        }
        if (IsScreenPresent(SCR_FMGR_EXPLORER))
        {
            DeleteUptoScrID(SCR_FMGR_EXPLORER);
        }
        else if (IsScreenPresent(SCR_FMGR_DA_FILE_OPTION))
        {
            DeleteUptoScrID(SCR_FMGR_DA_FILE_OPTION);
        }
        else if (IsScreenPresent(EBOOK_OPEN_SCREENID))
        {
            DeleteScreenIfPresent(EBOOK_OPEN_SCREENID);
        }
        GoBackHistory();
    }
    else
    {
        if (IsScreenPresent(SCR_FMGR_EXPLORER))
        {
            DeleteUptoScrID(SCR_FMGR_EXPLORER);
            GoBackHistory();
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_search
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EBOOK_SEARCH_SCREENID, NULL, ebr_entry_search, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_SEARCH_SCREENID);

    nNumofItem = GetNumOfChild(MENU_ID_EBK_FIND);
    GetSequenceStringIds(MENU_ID_EBK_FIND, nStrItemList);
    GetSequenceImageIds(MENU_ID_EBK_FIND, nImgIltemList);
    SetParentHandler(MENU_ID_EBK_FIND);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_FIND_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(ebr_ebook_search_string, KEY_EVENT_UP);
    SetKeyHandler(ebr_ebook_search_string, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(go_back_to_settings_screen, KEY_EVENT_UP);
    SetKeyHandler(go_back_to_settings_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  go_back_to_settings_screen
 * DESCRIPTION
 *  Go back to Setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void go_back_to_settings_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(EBOOK_BOOK_SETTINGS);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_ebook_search_string
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_ebook_search_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EBOOK_SEARCH_STR_SCREENID, ebr_exit_ebook_search_string, ebr_ebook_search_string, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_SEARCH_STR_SCREENID);
    ShowCategory5Screen(
        STR_FIND_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_ebook_app_cntx_p->ebr_search_string_input,
        EBR_MAX_STR_SEARCH_LENGTH + 1,
        guiBuffer);
    SetLeftSoftkeyFunction(ebr_entry_search_edit_list, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  ebr_exit_ebook_search_string
 * DESCRIPTION
 *  exit handler of input search string screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_exit_ebook_search_string(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/       
    S8* last_search_string;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_get_last_search_string(&last_search_string);
	if (mmi_ucs2cmp(last_search_string, g_ebook_app_cntx_p->ebr_search_string_input) != 0)
	{
        mmi_ucs2ncpy(last_search_string, g_ebook_app_cntx_p->ebr_search_string_input, (EBR_MAX_STR_SEARCH_LENGTH + 1) *ENCODING_LENGTH);
	}
    
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_search_edit_list
 * DESCRIPTION
 *  Entry function for Add book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_search_edit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 ItemList[2];
    U16 nItems;

#ifdef __MMI_LANG_HINDI__
    pBOOL full_character;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LANG_HINDI__
    full_character = ebr_frm_check_for_full_characters((S16*) g_ebook_app_cntx_p->ebr_search_string_input);
    if (!full_character)
    {
        ebr_app_show_string_incomplete_pop_up();
        return;
    }
#endif /* __MMI_LANG_HINDI__ */ 
    EntryNewScreen(SCR_EDIT_BOOK_MARK_NAME, NULL, ebr_entry_search_edit_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_EDIT_BOOK_MARK_NAME);

    nItems = GetNumOfChild(MENU_EBOOK_EDIT_BOOK_MARK_NAME);
    GetSequenceStringIds(MENU_EBOOK_EDIT_BOOK_MARK_NAME, ItemList);

    RegisterHighlightHandler(ebr_get_add_search_string_options);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        0,
        0,
        0,
        guiBuffer);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(ebr_get_add_search_string, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_get_add_search_string
 * DESCRIPTION
 *  Processing for Highlight Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_get_add_search_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_ebook_app_cntx_p->current_highlighted_item)
    {
        case 0:
            ebr_app_search_string();
            break;
        case 1: /* Input Methods */
            EntryInputMethodScreen();
            RegisterInputMethodScreenCloseFunction(GoBackHistoryFromInputMethod);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_get_add_search_string_options
 * DESCRIPTION
 *  Highlight Handler
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_get_add_search_string_options(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebook_app_cntx_p->current_highlighted_item = nIndex;
    switch (nIndex)
    {
        case 0: /* Done */
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case 1: /* Input Methods */
            SetKeyHandler(ebr_get_add_search_string, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        default:
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_search_string
 * DESCRIPTION
 *  Function for Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_search_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ebr_app_search_type_enum search_type = GetCurrHiliteID();
	S32 search_satus;

    S32 str_length = mmi_ucs2strlen((const S8*)g_ebook_app_cntx_p->ebr_search_string_input);
	if(!ebr_frm_check_file_exist())
	{
		go_back_to_bookshelf_screen();
		ebr_app_display_pop_up_error_opening_book();
		return;
	}
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str_length == 0)
    {
        ebr_frm_search_string_empty();
        return;
    }
    ebr_please_wait_actual_screen_2();
    ebr_frm_reset_find_next_data();
    search_satus = ebr_frm_search_string_algo(search_type, (S8*) g_ebook_app_cntx_p->ebr_search_string_input, MMI_FALSE);
    /* search not complete */
    if (search_satus == 0xFF)
    {
        return;
    }
    else if ((search_satus ==1) &&
        ((g_ebook_app_cntx_p->ebr_search_string_input[0] != '\0') || (g_ebook_app_cntx_p->ebr_search_string_input[1] != '\0' )))
    {
        if (!ebr_frm_get_auto_scroll_status())
        {
            ebr_frm_reset_auto_scroll();/*[MAUI_00230894]*/
        }
        ebr_app_search_result_successful((pBOOL) search_type);
        ebr_app_delete_upto_open_book_screen_id();
        GoBackHistory();
        ebr_frm_set_data_for_display();
    }
    else
    {
		if(search_satus==2)
		{
			ebr_app_search_result_invalid();
		}
		else
		{
        ebr_app_search_result_unsucessfull();
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_save_settings_scroll
 * DESCRIPTION
 *  Save scroll flag in nfo file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_save_settings_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_app_delete_upto_open_book_screen_id();
    ebr_app_display_pop_up_changed_auto_scroll(ebr_frm_save_settings_scroll());
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_save_settings_screen_mode
 * DESCRIPTION
 *  Saves screen mode in NFO file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_save_settings_screen_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_app_delete_upto_open_book_screen_id();
    ebr_app_display_pop_up_changed_screen_mode(ebr_frm_save_settings_screen_mode());
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_open_book
 * DESCRIPTION
 *  Entry Function for Open Book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern pBOOL isInCall(void);
void ebr_entry_open_book(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S8 *last_search_string;
    S16 buffer_size;
    U16 lsk=STR_GLOBAL_OPTIONS;
    U16 display_name[MAX_EBOOK_NAME_LENGTH + 1];
    S16 return_val;
    S32 book_size;
    S32 page_size;
    S16 full_screen, auto_scroll_staus;

    ebr_frm_nfo_create_type_errors_enum error_type = EBR_FRM_NFO_CREATE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_please_wait_actual_screen();
    
    PowerAndEndKeyHandler();
    if (ebr_frm_get_current_recursive_conversion_state() == EBR_FRM_CONVERSION_UNDERWAY)
    {
        ebr_frm_convert_record_record_recursively();
        return;
    }
    if (ebr_frm_get_current_recursive_conversion_state() == EBR_FRM_NFO_CONVERSION_COMPLETED)
    {
        DeleteNScrId(EBOOK_OPEN_SCREENID);
        ebr_frm_set_current_recursive_conversion_state(EBR_FRM_NO_CONVERSION);
    }
    guiBuffer = GetCurrGuiBuffer(EBOOK_OPEN_SCREENID);
    if (guiBuffer == NULL)
    {

        error_type = ebr_frm_reset_for_new_book();
        g_ebook_app_cntx_p->enable_screen_exit = 1;
        if ((ebr_frm_nfo_create_type_errors_enum) error_type == EBR_FRM_NFO_CREATE_FAILURE)
        {
            if (ebr_frm_check_nfo_file_size())
            {
                ebr_app_dispaly_less_memory_pop_up();
            }
            else
            {
                ebr_app_display_pop_up_error_opening_book();
            }
            DeleteNScrId(EBOOK_OPEN_SCREENID);
            ebr_frm_write_default_value_for_nfo_id_in_nvram();
            return;
        }
        else
        {
            if ((ebr_frm_nfo_create_type_errors_enum) error_type == EBR_FRM_NFO_CREATE_FILE_TYPE_NOT_SUPPORTED)
            {
                ebr_app_display_pop_up_format_not_supported();
                DeleteNScrId(EBOOK_OPEN_SCREENID);
                ebr_frm_write_default_value_for_nfo_id_in_nvram();
                return;
            }
        }
        if ((ebr_frm_nfo_create_type_errors_enum) error_type == EBR_FRM_EMPTY_BOOK)
        {
            ebr_app_display_pop_up_empty_book();
            DeleteNScrId(EBOOK_OPEN_SCREENID);
            ebr_frm_write_default_value_for_nfo_id_in_nvram();
            return;
        }
    }

    memset(g_ebook_app_cntx_p->buffer_data, 0, EBR_RECORD_SIZE_MAX + GUI_SHARED_BYTES);
    ebr_frm_register_recursive_callback_fn(ebr_entry_open_book);
    return_val = ebr_frm_get_data_to_open_book(ebook_frm_setting, g_ebook_app_cntx_p->buffer_data, (PS8)display_name);
    if (return_val == 0)
    {
        ebr_app_dispaly_less_memory_pop_up();
        DeleteNScrId(EBOOK_OPEN_SCREENID);
        ebr_frm_write_default_value_for_nfo_id_in_nvram();
        return;
    }
    else
    {
        if (return_val == -1)
        {
            ebr_app_display_pop_up_error_opening_book();
            DeleteNScrId(EBOOK_OPEN_SCREENID);
            ebr_frm_write_default_value_for_nfo_id_in_nvram();
            return;
        }
    }
    if (return_val == 3)
    {
        ebr_app_display_pop_up_error_opening_book();
        DeleteNScrId(EBOOK_OPEN_SCREENID);
        ebr_frm_write_default_value_for_nfo_id_in_nvram();
        return;
    }
    if (return_val == 2)
    {
        ebr_app_display_pop_up_empty_book();
        DeleteNScrId(EBOOK_OPEN_SCREENID);
        ebr_frm_write_default_value_for_nfo_id_in_nvram();
        return;
    }
    else if (return_val < 0)
    {
        ebr_display_error_pop_up((S32)return_val);
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
        ebr_frm_write_default_value_for_nfo_id_in_nvram();
    	return;
	}
    if (ebr_frm_get_current_recursive_conversion_state() == EBR_FRM_CONVERSION_UNDERWAY)
    {
        return;
    }
    buffer_size = mmi_ucs2strlen((const S8*)g_ebook_app_cntx_p->buffer_data);
    full_screen = ebr_frm_get_full_screen_flag_status();
    auto_scroll_staus = ebr_frm_get_auto_scroll_flag_status();
    if (auto_scroll_staus)
    {
        TurnOnBacklight(0);
    }
    EntryNewScreen(EBOOK_OPEN_SCREENID, ebr_mmi_ebook_exit, ebr_entry_open_book, NULL);
#ifdef __MMI_TOUCH_SCREEN__
    ebook_frm_setting->key_callback = ebr_set_key_TS;
#endif 
    if (isInCall())
        lsk = 0;
    if (full_screen == 0)
    {
        ShowCategory75Screen(
            display_name,
            GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
            lsk,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*) g_ebook_app_cntx_p->buffer_data,
            buffer_size,
            NULL,
            &ebook_frm_setting);

        SetLeftSoftkeyFunction(ebr_entry_book_settings, KEY_EVENT_UP);
        SetRightSoftkeyFunction(go_back_to_bookshelf_screen, KEY_EVENT_UP);
    }
    else
    {
        ShowCategory77Screen(
            (U16*) display_name,
            GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
            lsk,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*) g_ebook_app_cntx_p->buffer_data,
            buffer_size,
            NULL,
            &ebook_frm_setting);

        SetKeyHandler(ebr_entry_book_settings, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(go_back_to_bookshelf_screen, KEY_RSK, KEY_EVENT_DOWN);
    }
    /*    PowerAndEndKeyHandler(); */
    register_multiline_inputbox_navigate_callback(ebr_frm_reset_find_next_data);
    if (ebook_frm_setting->search_flag_is_on)
    {
        ebr_frm_get_and_set_current_page_values();
    }
    g_ebook_app_cntx_p->ebr_set_local_setting_flag = 1;
    book_size = ebr_frm_get_book_size_from_nfo();
    page_size = ebr_frm_get_page_size();
    SetKeyHandler(ebr_entry_settings, KEY_0, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_help, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_add_book_mark, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_search, KEY_3, KEY_EVENT_UP);
    SetKeyHandler(ebr_pre_entry_jump_to, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(ebr_entry_goto_book_mark, KEY_5, KEY_EVENT_UP);
    ebr_frm_get_last_search_string(&last_search_string);
    if (((*last_search_string != '\0') || (*(last_search_string+1) != '\0')) && ebr_frm_get_auto_scroll_status())
    {
        SetKeyHandler(ebr_app_search_string_next, KEY_6, KEY_EVENT_UP);
    }
    SetKeyHandler(ebr_entry_remove_book_mark, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(ebr_app_save_settings_scroll, KEY_7, KEY_EVENT_UP);       /* Auto Scroll */
    SetKeyHandler(ebr_app_save_settings_screen_mode, KEY_9, KEY_EVENT_UP);   /* Full Screen */

}




/*****************************************************************************
 * FUNCTION
 *  ebr_please_wait_actual_screen
 * DESCRIPTION
 *  Please Wait Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_please_wait_actual_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EBOOK_WAITSCREEN, NULL, NULL, NULL);
    ClearHighlightHandler();
    ShowCategory63Screen(
    (U8*) GetString(STR_EBOOK_WAIT),
            IMAGE_EBOOK_WAIT,
            NULL);
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_file_move_wait_screen
 * DESCRIPTION
 *  Please Wait Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_file_move_wait_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EBOOK_FILE_MOVE_WAITSCREEN, exit_file_move_wait_screen, NULL, NULL);
    ClearHighlightHandler();

    ShowCategory66Screen(
        (U16) STR_EBOOK_WAIT,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EBOOK_WAIT_FOR_MOVING_FILE),
        IMAGE_EBOOK_WAIT,
        NULL);
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  exit_file_move_wait_screen
 * DESCRIPTION
 *  Please Wait Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_file_move_wait_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history wait_screen;
    U16 inputBufferSize;
    
    /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

    if (GetActiveScreenId() != POPUP_SCREENID && ebr_frm_fmgr_is_moving_file() == MMI_TRUE)
    {
        mmi_fmgr_send_abort_copy_req();        
    }
    else
    {
        wait_screen.scrnID = SCR_ID_EBOOK_FILE_MOVE_WAITSCREEN;
        wait_screen.entryFuncPtr = ebr_file_move_wait_screen;
        inputBufferSize = 0;
        AddNHistory(wait_screen, inputBufferSize);          /* added for inline edit history */  
    }
}

/*****************************************************************************
 * FUNCTION
 *  ebr_please_wait_actual_screen_2
 * DESCRIPTION
 *  Please Wait Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_please_wait_actual_screen_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EBOOK_WAITSCREEN, NULL, NULL, NULL);
    ClearHighlightHandler();

    ShowCategory63Screen(
    (U8*) GetString(STR_EBOOK_WAIT),
            IMAGE_EBOOK_WAIT,
            NULL);
    /* ShowCategory9Screen(wait_string, wait_image_id, NULL); */
    ClearAllKeyHandler();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_please_wait_move_screen
 * DESCRIPTION
 *  Please Wait Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_please_wait_move_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* EntryNewScreen(SCR_ID_EBOOK_WAITSCREEN, NULL, NULL, NULL); */
    ClearHighlightHandler();
    ClearKeyEvents();
    /* ShowCategory151Screen(0, 0, 0, 0, 0, 0, (PU8)GetString(STR_WAIT_STRING), 0, NULL); */
    ShowCategory66Screen(
        (U16) STR_EBOOK_WAIT,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EBOOK_WAIT),
        IMAGE_EBOOK_WAIT,
        NULL);
    /* ShowCategory9Screen(wait_string, wait_image_id, NULL); */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  go_back_to_bookshelf_screen
 * DESCRIPTION
 *  Go to Book shelf Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void go_back_to_bookshelf_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_close_the_ebook();
    DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_full_screen_on
 * DESCRIPTION
 *  Set full screen ON
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_full_screen_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    ebr_entry_open_book();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_set_full_screen_off
 * DESCRIPTION
 *  Set full screen OFF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_set_full_screen_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    ebr_entry_open_book();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_book_settings
 * DESCRIPTION
 *  Entry Function for Setting Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_book_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];
    U8 *hintList[MAX_SUB_MENUS];
    S32 book_size;
    S32 page_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EBOOK_BOOK_SETTINGS_SCREENID, NULL, ebr_entry_book_settings, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_BOOK_SETTINGS_SCREENID);
    book_size = ebr_frm_get_book_size_from_nfo();
    page_size = ebr_frm_get_page_size();
	/* The UCS2 encoding of Chinese word '¤@' is 00 4e */
#if defined(__MMI_BPP_SUPPORT__) && defined(__FLIGHT_MODE_SUPPORT__)
    if (mmi_bootup_get_active_flight_mode() == 1) /* in flight mode */
    {
        mmi_frm_hide_menu_item(MENU_ID_EBK_BPP_PRINT);        
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EBK_BPP_PRINT);        
    }
#endif /*__MMI_BPP_SUPPORT__ && __FLIGHT_MODE_SUPPORT__*/
    if ((g_ebook_app_cntx_p->ebr_search_string_input[0] != '\0' || g_ebook_app_cntx_p->ebr_search_string_input[1] != '\0') 
		&& ebr_frm_get_auto_scroll_status())
    {
        SetParentHandler(MENU_ID_EBK_OPEN_OPTIONS_1);
        nNumofItem = GetNumOfChild_Ext(MENU_ID_EBK_OPEN_OPTIONS_1);
        GetSequenceStringIds_Ext(MENU_ID_EBK_OPEN_OPTIONS_1, nStrItemList);
        GetSequenceImageIds_Ext(MENU_ID_EBK_OPEN_OPTIONS_1, nImgIltemList);
        ConstructHintsList(MENU_ID_EBK_OPEN_OPTIONS_1, hintList);

    }
    else
    {
        SetParentHandler(MENU_ID_EBK_OPEN_OPTIONS);
        nNumofItem = GetNumOfChild_Ext(MENU_ID_EBK_OPEN_OPTIONS);
        GetSequenceStringIds_Ext(MENU_ID_EBK_OPEN_OPTIONS, nStrItemList);
        GetSequenceImageIds_Ext(MENU_ID_EBK_OPEN_OPTIONS, nImgIltemList);
        /* Construct List To Show Hint */
        ConstructHintsList(MENU_ID_EBK_OPEN_OPTIONS, hintList);

    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_OPEN_BOOK_OPTION,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(go_back_to_settings_screen, KEY_EVENT_UP);
    SetKeyHandler(go_back_to_settings_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_book_info
 * DESCRIPTION
 *  Entry Function for Book Info Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_book_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 book_size[EBR_DISPLAY_INFO_DATA];
    U8 new_line_info[EBR_NEW_LINE_SIZE];
    S32 file_size, total_size;
    U8 *type;
    S8 buffer[MAX_EBOOK_NAME_LENGTH];
    S8 new_line[]="\n";
    U8 type_info[EBR_DISPLAY_INFO_DATA * ENCODING_LENGTH];
    U8 tmp_path_buf[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EBOOK_INFO_SCREENID, NULL, ebr_entry_book_info, NULL);
    SetDelScrnIDCallbackHandler(EBOOK_INFO_SCREENID, (HistoryDelCBPtr)ebr_book_info_del_callback);
    guiBuffer = GetCurrGuiBuffer(EBOOK_INFO_SCREENID);
    type = ebr_frm_get_book_type();
    mmi_asc_to_ucs2((S8*) new_line_info, (S8*) new_line);
    mmi_asc_to_ucs2((S8*) type_info, (S8*) type);
    if (mmi_ebr_is_short_file_name())
        {
                memset(tmp_path_buf, 0, (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
                mmi_chset_mixed_text_to_ucs2_str(
                            (U8*) tmp_path_buf,
                            (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
                            (U8*) ebr_frm_get_book_name(),
                            g_chset_text_encoding);                           
        }
        else
        {
            mmi_ucs2ncpy(
                (S8*) tmp_path_buf,
                (S8*) ebr_frm_get_book_name(),
                (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        }     

    if (g_ebook_app_cntx_p->info_buffer == NULL)
    {
        g_ebook_app_cntx_p->info_buffer = OslMalloc(EBR_DISPLAY_INFO_SIZE);
    }
    mmi_ucs2cpy((PS8) g_ebook_app_cntx_p->info_buffer, (PS8) get_string(STR_EBOOK_BOOK_INFO_TITLE));
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (PS8) tmp_path_buf);
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (S8*) new_line_info);
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (S8*) get_string(STR_EBOOK_BOOK_INFO_SIZE));
    total_size = ebr_frm_get_book_size();
    if (total_size > 1024 * 1024)
    {
        file_size = total_size / 1024;
        sprintf(buffer, "%d.%dM", (U16) (file_size / 1024), (U16) ((file_size % 1024) / 103));
    }
    else if (total_size > 1024)
    {
        sprintf(buffer, "%d.%dK", (U16) (total_size / 1024), (U16) ((total_size % 1024) / 103));
    }
    else    /* less than 1024 */
    {
        sprintf(buffer, "%dB", (U16) (total_size));
    }

    mmi_asc_to_ucs2((S8*) book_size, (S8*) buffer);
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (PS8) book_size);
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (PS8) new_line_info);
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (PS8) get_string(STR_EBOOK_BOOK_INFO_FORMAT));
    mmi_ucs2cat((PS8) g_ebook_app_cntx_p->info_buffer, (PS8) type_info);

    ShowCategory74Screen(
        STR_INFO_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_ebook_app_cntx_p->info_buffer,
        mmi_ucs2strlen((const S8*)g_ebook_app_cntx_p->info_buffer),
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  ebr_book_info_del_callback
 * DESCRIPTION
 *  Delete callback function of book info screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
U8 ebr_book_info_del_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ebook_app_cntx_p->info_buffer)
    {
        OslMfree(g_ebook_app_cntx_p->info_buffer);
        g_ebook_app_cntx_p->info_buffer = NULL;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  ebr_entry_delete_ebook
 * DESCRIPTION
 *  Entry Function for Delete Book Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_delete_ebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 return_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_type = ebr_frm_delete_ebook();
    DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
	if(return_type==-45)
	{
		DisplayPopup((PU8) GetString(FMGR_FS_READ_ONLY_ERROR_TEXT), IMG_GLOBAL_ERROR, 1, EBR_ST_NOTIFYDURATION, ERROR_TONE);
	}
       else if (return_type < 0)
       {
         DisplayPopup((PU8) GetString(GetFileSystemErrorString(return_type)), IMG_GLOBAL_ERROR, 1, EBR_ST_NOTIFYDURATION, ERROR_TONE);   
       }
	else
	{
    DisplayPopup((PU8) GetString(STR_GLOBAL_DELETED), IMG_GLOBAL_ACTIVATED, 1, EBR_ST_NOTIFYDURATION, SUCCESS_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_help
 * DESCRIPTION
 *  Entry Function for Help Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer_data;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EBOOK_HELP_SCREEN, NULL, ebr_entry_help, NULL);
    guiBuffer = GetCurrGuiBuffer(EBOOK_HELP_SCREEN);
    buffer_data = GetString(STR_EBOOK_TOUCH_SCREEN_HELP);

    ShowCategory74Screen(
        STR_HELP_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) buffer_data,
        510,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_settings
 * DESCRIPTION
 *  Entry Function for Settings Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 status;
    U8 *inputBuffer;
    U16 nNumofItem = EBR_TOTAL_NUMBER_OF_ITEM_BKSHLF;   /* Stores no of children in the submenu */
    U16 inputBufferSize;
    U16 gIndexIconsImageList_local[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
        IMG_GLOBAL_L5,
        0,
        IMG_GLOBAL_L6,
        0,
        IMG_GLOBAL_L7,
        0,
        IMG_GLOBAL_L8,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    nNumofItem = EBR_TOTAL_NUMBER_OF_ITEM_BKSHLF;

    mmi_fmgr_get_exist_storage_inline_list(NULL, &status, NULL, NULL);
    
    if (g_ebook_app_cntx_p->ebr_set_local_setting_flag == 1 || 
        (g_ebook_app_cntx_p->ebr_set_local_setting_flag != 1 && (status <= 1)))
    {
        gIndexIconsImageList_local[14] = 0;
        gIndexIconsImageList_local[15] = 0;
        nNumofItem = EBR_TOTAL_NUMBER_OF_ITEM_BOOK;
    }                    

    EntryNewScreen(EBOOK_BOOK_SHELF_SETTINGS_SCREEN_ID, ebr_exit_settings, NULL, NULL);
    InitializeCategory57Screen();
        
    guiBuffer = GetCurrGuiBuffer(EBOOK_BOOK_SHELF_SETTINGS_SCREEN_ID);
    inputBuffer = GetCurrNInputBuffer(EBOOK_BOOK_SHELF_SETTINGS_SCREEN_ID, &inputBufferSize);   /* added for inline edit history */	
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, nNumofItem, inputBuffer);		
    }    
    else
    {
        //ClearHighlightHandler();
		/* Ge the Default value from NVRAM */
		ebr_frm_get_default_settings_value(g_ebookset_cntx_p, g_ebook_app_cntx_p->ebr_set_local_setting_flag);    
    }
	ebr_fill_settings_inline_edit_struct((void*)&wgui_inline_items);	
	RegisterHighlightHandler(mmi_ebr_highlight_setting);

    if (g_ebook_app_cntx_p->ebr_set_local_setting_flag != 1 && 
	 mmi_ebr_is_memory_type_changed(g_ebookset_cntx_p->inlineHighligtItemSelectMemory) && 
	 GetInlineDoneFlag(guiBuffer) == 0)
    {
        SetInlineDoneFlag(guiBuffer);
    }
    
    if (g_ebook_app_cntx_p->ebr_set_local_setting_flag != 1)
    {
    ShowCategory57Screen(
        STR_SETTINGS_EBOOK,
        GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        nNumofItem,
        (U16*) gIndexIconsImageList_local,
        wgui_inline_items,
        0,
        guiBuffer);
    }
    else
    {
        ShowCategory57Screen(
            STR_BOOK_SETTINGS_EBOOK,
            GetRootTitleIcon(MAIN_MENU_EBOOK_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_DONE,
            IMG_GLOBAL_BACK,
            nNumofItem,
            (U16*) gIndexIconsImageList_local,
            wgui_inline_items,
            0,
            guiBuffer);
    }

    /* Register function for right soft key */
    SetCategory57RightSoftkeyFunctions(ebr_book_settings_confirm_pop_up, GoBackHistory);

}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  ebr_set_key_TS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void              
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_set_key_TS(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 *last_search_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (c)
    {

        case '0':
            ebr_entry_settings();
            break;

        case '1':
            ebr_entry_help();
            break;

        case '2':
            ebr_entry_add_book_mark();
            break;

        case '3':
            ebr_entry_search();
            break;

        case '4':
            ebr_pre_entry_jump_to();
            break;

        case '5':
            ebr_entry_goto_book_mark();
            break;

        case '6':
			ebr_frm_get_last_search_string(&last_search_string);
			if (((*last_search_string != '\0') || (*(last_search_string+1) != '\0')) && ebr_frm_get_auto_scroll_status())
			{
				ebr_app_search_string_next();
			}
            break;

        case '7':
            ebr_app_save_settings_scroll();
            break;

        case '8':
            ebr_entry_remove_book_mark();
            break;

        case '9':
            ebr_app_save_settings_screen_mode();
            break;
        default:
            break;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  ebr_book_settings_confirm_pop_up
 * DESCRIPTION
 *  Confirmation Screen for Settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_book_settings_confirm_pop_up(void)
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
        get_string(STR_CONFIRM_SAVE_SETTINGS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    if (g_ebook_app_cntx_p->ebr_set_local_setting_flag == 1)
    {
        SetLeftSoftkeyFunction(ebr_book_settings_done_hdlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(go_back_to_open_book_screen, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(ebr_entry_settings_done_hndlr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(go_back_to_book_shelf_scren, KEY_EVENT_UP);
    }

}


/*****************************************************************************
 * FUNCTION
 *  go_back_to_book_shelf_scren
 * DESCRIPTION
 *  Go to book Shelf Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void go_back_to_book_shelf_scren(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteUptoScrID(SCR_FMGR_EXPLORER);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  go_back_to_open_book_screen
 * DESCRIPTION
 *  Go to Open Book Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void go_back_to_open_book_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(EBOOK_BOOK_SETTINGS_SCREENID))
    {
        DeleteUptoScrID(EBOOK_OPEN_SCREENID);
        GoBackHistory();
    }
    else
    {
        DeleteUptoScrID(EBOOK_OPEN_SCREENID);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_exit_settings
 * DESCRIPTION
 *  Exit function for Settings Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_exit_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history Scr;
    S16 nHistory = 0;
    U16 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    Scr.scrnID = EBOOK_BOOK_SHELF_SETTINGS_SCREEN_ID;
    CloseCategory57Screen();
    Scr.entryFuncPtr = ebr_entry_settings;
    mmi_ucs2cpy((S8*) Scr.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(Scr.guiBuffer);
    size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) Scr.inputBuffer);
    AddNHistory(Scr, size);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_entry_settings_done_hndlr
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_entry_settings_done_hndlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DisplayPopup(
        (PU8) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        EBR_ST_NOTIFYDURATION,
        SUCCESS_TONE);
	if (ebr_is_memory_type_changed(g_ebookset_cntx_p))
    {
		DeleteUptoScrID(EBOOK_BOOKSHELF_SCREENID);
    }
	else
	{
		DeleteUptoScrID(SCR_FMGR_EXPLORER);
	}
	ebr_frm_set_settings_and_save_in_nvram(g_ebookset_cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_book_settings_done_hdlr
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_book_settings_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_set_settings_and_save(g_ebookset_cntx_p);
    if (IsScreenPresent(EBOOK_BOOK_SETTINGS_SCREENID))
    {
        DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    }
    else
    {
        DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    }
	DisplayPopup(
        (PU8) GetString(STR_GLOBAL_SAVED),
        IMG_GLOBAL_ACTIVATED,
        1,
        EBR_ST_NOTIFYDURATION,
        SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_fill_settings_inline_edit_struct
 * DESCRIPTION
 *  Set highlight handler for Menu Ooptions
 * PARAMETERS
 *  pInlineStruct       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_fill_settings_inline_edit_struct(void *pInlineStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;
    U8 status = 0;
    InlineItem *InlineStruct = (InlineItem*) pInlineStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebook_app_cntx_p->ebook_settings_font_style[EBR_FONT_STYLE_NORMAL] =
        (U8*) GetString(STR_SETTINGS_FONT_STYLE_NORMAL);
    g_ebook_app_cntx_p->ebook_settings_font_style[EBR_FONT_STYLE_ITALIC] =
        (U8*) GetString(STR_SETTINGS_FONT_STYLE_ITALIC);
    g_ebook_app_cntx_p->ebook_settings_font_style[EBR_FONT_STYLE_BOLD] = (U8*) GetString(STR_SETTINGS_FONT_STYLE_BOLD);

    g_ebook_app_cntx_p->ebook_settings_font_size[EBR_FONT_SIZE_SMALL] = (U8*) GetString(STR_SETTINGS_FONT_SIZE_SMALL);
    g_ebook_app_cntx_p->ebook_settings_font_size[EBR_FONT_SIZE_MEDIUM] =
        (U8*) GetString(STR_SETTINGS_FONT_SIZE_MEDIUM);
    g_ebook_app_cntx_p->ebook_settings_font_size[EBR_FONT_SIZE_LARGE] = (U8*) GetString(STR_SETTINGS_FONT_SIZE_LARGE);

    g_ebook_app_cntx_p->ebook_settings_scroll_by[EBR_SCROLL_BY_LINE] = (U8*) GetString(STR_SETTINGS_SCROLL_BY_LINE);
    g_ebook_app_cntx_p->ebook_settings_scroll_by[EBR_SCROLL_BY_PAGE] = (U8*) GetString(STR_SETTINGS_SCROLL_BY_PAGE);

    g_ebook_app_cntx_p->ebook_settings_auto_scroll[EBR_SCROLL_OFF] = (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_OFF);
    g_ebook_app_cntx_p->ebook_settings_auto_scroll[EBR_SCROLL_ON] = (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_ON);

    g_ebook_app_cntx_p->ebook_settings_full_screen[EBR_FULL_SCREEN_OFF] =
        (U8*) GetString(STR_SETTINGS_FULL_SCREEN_OFF);
    g_ebook_app_cntx_p->ebook_settings_full_screen[EBR_FULL_SCREEN_ON] = (U8*) GetString(STR_SETTINGS_FULL_SCREEN_ON);

    g_ebook_app_cntx_p->ebook_settings_encoding_format[i++] =
        (U8*) GetString(STR_SETTINGS_ENCODING_FORMAT_WESTERN_WIN);
    g_ebook_app_cntx_p->ebook_settings_encoding_format[i++] = (U8*) GetString(STR_SETTINGS_ENCODING_FORMAT_UCS2);
    g_ebook_app_cntx_p->ebook_settings_encoding_format[i++] = (U8*) GetString(STR_SETTINGS_ENCODING_FORMAT_UTF8);

#ifdef __MMI_CHSET_BIG5__
    g_ebook_app_cntx_p->ebook_settings_encoding_format[i++] = (U8*) GetString(STR_SETTINGS_ENCODING_FORMAT_BIG5);
#endif 
#ifdef __MMI_CHSET_GB2312__
    g_ebook_app_cntx_p->ebook_settings_encoding_format[i++] = (U8*) GetString(STR_SETTINGS_ENCODING_FORMAT_GB2312);
#endif 
#if 0
#ifdef __MMI_CHSET_TURKISH_ISO__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CHSET_TURKISH_ISO__ */ 
/* under construction !*/
#ifdef __MMI_CHSET_TURKISH_WIN__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CHSET_TURKISH_WIN__ */ 
#ifdef __MMI_CHSET_BALTIC_ISO__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_BALTIC_WIN__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_CEURO_ISO__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CHSET_CEURO_ISO__ */ 
#ifdef __MMI_CHSET_CEURO_WIN__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_GREEK_ISO__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_GREEK_WIN__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_HEBREW_ISO__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_HEBREW_WIN__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_LATIN_ISO__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_NORDIC_ISO__
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_SEURO_ISO__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CHSET_SEURO_ISO__ */ 
#ifdef __MMI_CHSET_WESTERN_ISO__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CHSET_WESTERN_ISO__ */ 
#ifdef __MMI_CHSET_ARABIC_ISO__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CHSET_ARABIC_ISO__ */ 
#ifdef __MMI_CHSET_ARABIC_WIN__
/* under construction !*/
#endif 
#endif /* 0 */ 
    mmi_fmgr_get_exist_storage_inline_list(NULL, &status, NULL, NULL);

    g_ebook_app_cntx_p->ebook_settinsg_auto_scroll_speed[EBR_AUTO_SCROLL_SPEED_1] =
        (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_SPEED_1);
    g_ebook_app_cntx_p->ebook_settinsg_auto_scroll_speed[EBR_AUTO_SCROLL_SPEED_2] =
        (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_SPEED_2);
    g_ebook_app_cntx_p->ebook_settinsg_auto_scroll_speed[EBR_AUTO_SCROLL_SPEED_3] =
        (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_SPEED_3);
    g_ebook_app_cntx_p->ebook_settinsg_auto_scroll_speed[EBR_AUTO_SCROLL_SPEED_4] =
        (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_SPEED_4);
    g_ebook_app_cntx_p->ebook_settinsg_auto_scroll_speed[EBR_AUTO_SCROLL_SPEED_5] =
        (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_SPEED_5);
    SetInlineItemActivation(&InlineStruct[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[0], (PU8) (U8*) GetString(STR_SETTINGS_FONT_STYLE));
    SetInlineItemActivation(&InlineStruct[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[2], (PU8) (U8*) GetString(STR_SETTINGS_FONT_SIZE));

    SetInlineItemActivation(&InlineStruct[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[4], (PU8) (U8*) GetString(STR_SETTINGS_SCROLL_BY));

    SetInlineItemActivation(&InlineStruct[6], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[6], (PU8) (U8*) GetString(STR_SETTINGS_AUTO_SCROLL));

    SetInlineItemActivation(&InlineStruct[8], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[8], (PU8) (U8*) GetString(STR_SETTINGS_AUTO_SCROLL_SPEED));

    SetInlineItemActivation(&InlineStruct[10], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[10], (PU8) (U8*) GetString(STR_SETTINGS_FULL_SCREEN));

    SetInlineItemActivation(&InlineStruct[12], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&InlineStruct[12], (PU8) (U8*) GetString(STR_SETTINGS_ENCODING_FORMAT));

    SetInlineItemActivation(&InlineStruct[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[1],
        3,
        g_ebook_app_cntx_p->ebook_settings_font_style,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemFontStyle) /* CurrSelect */ );

    SetInlineItemActivation(&InlineStruct[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[3],
        3,
        g_ebook_app_cntx_p->ebook_settings_font_size,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemFontSize) /* CurrSelect */ );

    SetInlineItemActivation(&InlineStruct[5], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[5],
        2,
        g_ebook_app_cntx_p->ebook_settings_scroll_by,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemScrollBy) /* CurrSelect */ );

    SetInlineItemActivation(&InlineStruct[7], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[7],
        2,
        g_ebook_app_cntx_p->ebook_settings_auto_scroll,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemAutoScroll) /* CurrSelect */ );

    SetInlineItemActivation(&InlineStruct[9], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[9],
        5,
        g_ebook_app_cntx_p->ebook_settinsg_auto_scroll_speed,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemScrollSpeed) /* CurrSelect */ );

    SetInlineItemActivation(&InlineStruct[11], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[11],
        2,
        g_ebook_app_cntx_p->ebook_settings_full_screen,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemFulScreenMode) /* CurrSelect */ );

    SetInlineItemActivation(&InlineStruct[13], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &InlineStruct[13],
        i,
        g_ebook_app_cntx_p->ebook_settings_encoding_format,
        (S32*) & (g_ebookset_cntx_p->inlineHighligtItemEncodingFormat) /* CurrSelect */ );
    if (g_ebook_app_cntx_p->ebr_set_local_setting_flag != 1)
    {
        if (status >= 1)
        {
            SetInlineItemActivation(&InlineStruct[14], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemCaption(&InlineStruct[14], (U8*) GetString(STR_SETTINGS_SELECT_MEMORY));

            mmi_fmgr_get_drive_name(g_ebookset_cntx_p->inlineHighligtItemSelectMemory, g_ebook_app_cntx_p->ebook_settings_memory_type, (FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH);
            SetInlineItemActivation(&InlineStruct[15], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
            SetInlineItemDisplayOnly(&InlineStruct[15], (U8*) g_ebook_app_cntx_p->ebook_settings_memory_type);

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_mmi_ebook_exit
 * DESCRIPTION
 *  exit function for Open Book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_mmi_ebook_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOffBacklight();
    if (g_ebook_app_cntx_p->enable_screen_exit)
    {
        ebr_frm_ebook_exit(EBR_FRM_EXIT_BY_GOBACK_TO_BOOKSHELF);
        if (ebr_frm_get_current_recursive_conversion_state() == EBR_FRM_CONVERSION_UNDERWAY)
        {

            ebr_frm_stop_recursion();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  entry_duplicate_book_mark_pop_up
 * DESCRIPTION
 *  Pop Up for Duplicate Book mark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_duplicate_book_mark_pop_up()
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
        get_string(STR_DUPLICATE_BOOK_MARK),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ebr_frm_add_book_mark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_delete_all_from_book_shelf
 * DESCRIPTION
 *  Pop Up for Delete All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_delete_all_from_book_shelf(void)
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
        get_string(STR_DELETE_ALL_EBOOK_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ebr_confirm_deletion_of_all_files, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_confirm_deletion_of_all_files
 * DESCRIPTION
 *  Pop Up for Delete All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_confirm_deletion_of_all_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_delete_all_from_book_shelf();
    DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
    DisplayPopup((PU8) GetString(STR_DELETED), IMG_GLOBAL_ACTIVATED, 1, EBR_ST_NOTIFYDURATION, SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_restore_default_book_settings_thru_frm
 * DESCRIPTION
 *  Pop Up for Delete All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_restore_default_book_settings_thru_frm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ebr_frm_restore_default_book_settings())
    {
        ebr_app_display_pop_up_default_settings_for_book_restored();
    }
    else    /* Error Settings could not be restored */
    {
        ebr_app_display_pop_up_default_settings_not_restored();
    }

}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_restore_default_book_settings
 * DESCRIPTION
 *  Confirmation screen for Restore default settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_restore_default_book_settings(void)
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
        get_string(STR_RESTORE_DEFAULT_SETTINGS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ebr_app_restore_default_book_settings_thru_frm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_restore_default_book_shelf_settings_thru_frm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_restore_default_book_shelf_settings_thru_frm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_restore_default_book_shelf_settings();
    ebr_app_display_pop_up_default_settings_restored();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_restore_default_book_shelf_settings
 * DESCRIPTION
 *  Confirmation screen for Restore default settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_restore_default_book_shelf_settings(void)
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
        get_string(STR_RESTORE_DEFAULT_SETTINGS),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(ebr_app_restore_default_book_shelf_settings_thru_frm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_maximum_book_marks
 * DESCRIPTION
 *  Pop Up for Maximum book marks added.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_maximum_book_marks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_MAX_BOOK_MARK), IMG_GLOBAL_WARNING, 1, EBR_ST_NOTIFYDURATION, ERROR_TONE);
    DeleteUptoScrID(EBOOK_BOOK_SETTINGS_SCREENID);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_book_mark_name_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_book_mark_name_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_BOOK_MARK_NAME_IS_EMPTY),
        IMG_GLOBAL_UNFINISHED,
        1,
        EBR_ST_NOTIFYDURATION,
        ERROR_TONE);
    /* DeleteUptoScrID(EBOOK_BOOK_SETTINGS_SCREENID); */
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_book_mark_sucessfully_added
 * DESCRIPTION
 *  Pop Up for Book Mark added.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_book_mark_sucessfully_added(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_EBOOK_BOOKMARK_ADDED),
        IMG_GLOBAL_ACTIVATED,
        1,
        EBR_ST_NOTIFYDURATION,
        SUCCESS_TONE);
    if (IsScreenPresent(EBOOK_BOOK_SETTINGS_SCREENID))
    {
        DeleteUptoScrID(EBOOK_BOOK_SETTINGS_SCREENID);
    }
    else
    {
        DeleteNScrId(EBOOK_ADD_BOOK_MARK_SCREEN_ID);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_search_result_unsucessfull
 * DESCRIPTION
 *  Pop Up for Search Uncessfull
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_search_result_unsucessfull(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_EBOOK_SEARCH_UN_SUCESSFULL),
        IMG_GLOBAL_UNFINISHED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    ebr_app_search_result_successful(FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  ebr_app_search_result_invalid
 * DESCRIPTION
 *  Pop Up for Search Invalid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_search_result_invalid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_EBOOK_SEARCH_INVALID),
        IMG_GLOBAL_UNFINISHED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    ebr_app_search_result_successful(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_search_string_empty
 * DESCRIPTION
 *  Pop Up for Search Uncessfull
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_search_string_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_GLOBAL_EMPTY),
        IMG_GLOBAL_UNFINISHED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
    ebr_app_search_result_successful(FALSE);
}



/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_changed_screen_mode
 * DESCRIPTION
 *  Pop Up for Screen mode changed.
 * PARAMETERS
 *  screen_mode     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_changed_screen_mode(S32 screen_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (screen_mode == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_FULL_SCREEN_OFF),
            IMG_GLOBAL_ACTIVATED,
            1,
            EBR_ST_NOTIFYDURATION,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_FULL_SCREEN_ON), IMG_GLOBAL_ACTIVATED, 1, EBR_ST_NOTIFYDURATION, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_changed_auto_scroll
 * DESCRIPTION
 *  Pop Up for Auto Scroll changed.
 * PARAMETERS
 *  auto_scroll_mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_changed_auto_scroll(S32 auto_scroll_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auto_scroll_mode == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_AUTO_SCROLL_OFF),
            IMG_GLOBAL_ACTIVATED,
            1,
            EBR_ST_NOTIFYDURATION,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_AUTO_SCROLL_ON), IMG_GLOBAL_ACTIVATED, 1, EBR_ST_NOTIFYDURATION, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_error_opening_book
 * DESCRIPTION
 *  Pop Up for Error Opening book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_error_opening_book(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_ERROR_OPENINIG_BOOK), IMG_GLOBAL_UNFINISHED, 1, EBR_ST_NOTIFYDURATION, ERROR_TONE);
}



/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_empty_book
 * DESCRIPTION
 *  Pop Up for Error Opening book
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_empty_book(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_UNFINISHED, 1, EBR_ST_NOTIFYDURATION, ERROR_TONE);
}



/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_format_not_supported
 * DESCRIPTION
 *  Pop Up for File fomat not supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_format_not_supported(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_EBOOK_FORMAT_NOT_SUPPORTED),
        IMG_GLOBAL_UNFINISHED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_default_settings_restored
 * DESCRIPTION
 *  Pop Up for Resore defauklt settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_default_settings_restored(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IsBackHistory = MMI_TRUE;
     DisplayPopup(
        (PU8) GetString(STR_SUCESSFULL_RESTORE_DEFAULT),
        IMG_GLOBAL_ACTIVATED,
        1,
        EBR_ST_NOTIFYDURATION,
        SUCCESS_TONE);
     DeleteUptoScrID(SCR_FMGR_EXPLORER);    
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_default_settings_not_restored
 * DESCRIPTION
 *  Pop Up for DDefauklt settings unsucessfull.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_default_settings_not_restored(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_UNSUCESSFULL_RESTORE_DEFAULT),
        IMG_GLOBAL_UNFINISHED,
        1,
        EBR_ST_NOTIFYDURATION,
        ERROR_TONE);
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_display_pop_up_default_settings_for_book_restored
 * DESCRIPTION
 *  Pop Up for Default settings restored.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_display_pop_up_default_settings_for_book_restored(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_SUCESSFULL_RESTORE_DEFAULT),
        IMG_GLOBAL_ACTIVATED,
        1,
        EBR_ST_NOTIFYDURATION,
        SUCCESS_TONE);
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_delete_upto_open_book_screen_id
 * DESCRIPTION
 *  History Handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_delete_upto_open_book_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(EBOOK_OPEN_SCREENID);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_go_back_history
 * DESCRIPTION
 *  History handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_get_nfo_id_from_fmgr
 * DESCRIPTION
 *  Function to get the Nf o id for File manager
 * PARAMETERS
 *  file_name       [IN]        
 *  file_path       [IN]        
 *  file_ext        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 ebr_app_get_nfo_id_from_fmgr(S8 *file_name, S8 *file_path, S8 *file_ext, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 nfo_id = ebr_frm_fmgr_pre_entry_open_book(file_name, file_path, file_ext);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_frm_fmgr_set_nfo_id(nfo_id);

    /* Check wether NFo file is present or not. If not then cretae a new nfo file */
    if (nfo_id > 0)
    {
        nfo_id = ebr_frm_check_nfo_file_present(nfo_id);
    }
    ebr_frm_fmgr_set_nfo_id(nfo_id);
    return nfo_id;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_frm_open_book_from_file_manager
 * DESCRIPTION
 *  open a file from file manager
 * PARAMETERS
 *  file_name       [IN]        
 *  file_path       [IN]        
 *  is_short        [IN]        
 *  file_ext(?)     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_frm_open_book_from_file_manager(S8 *file_name, S8 *file_path, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 drive_type;
    S32 nfo_id;
    PS8 file_ext;
    ebr_memory_type_enum memory_selected;

    pBOOL is_file_valid = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((PS8)g_ebook_app_cntx_p->ebr_file_mgr_file_path,(PS8)file_path);
    file_ext = mmi_fmgr_extract_ext_file_name((PS8) file_name);
    ebr_frm_fmgr_set_application_type();
    drive_type = ebr_fmgr_is_book_shelf_path(g_ebook_app_cntx_p->ebr_file_mgr_file_path);
    memory_selected = ebr_frm_get_drive_type();
    ebr_frm_fmgr_set_drive_type(drive_type);
    ebr_fmgr_set_file_name((PS8) file_name);
    ebr_frm_set_file_info_from_fmgr((S8*) file_name, g_ebook_app_cntx_p->ebr_file_mgr_file_path, file_ext, is_short);
    ebr_frm_fmgr_set_file_type((S8*) file_name);
    if (drive_type < 0)
    {
        nfo_id = -1;
    }
    else
    {
        nfo_id = ebr_app_get_nfo_id_from_fmgr((S8*) file_name, g_ebook_app_cntx_p->ebr_file_mgr_file_path, file_ext, is_short);
    }
    if (nfo_id > 0)
    {
        ebr_entry_open_book();
    }
    else
    {
        if (nfo_id == 0)    /* nfo file dose not exist // Ask the user if he wants to add this in the bookshelf */
        {
            ebr_app_add_to_book_shelf();
        }
        else    /* Means the book is not in the ebook Folder */
        {
            ebr_frm_fmgr_set_drive_type(memory_selected);
            // Check here that the file is a valid file.
            // If not a valid file pop an error and no need to move the file
            is_file_valid = ebr_frm_check_file_validity(g_ebook_app_cntx_p->ebr_file_mgr_file_path, file_name);
            if (!is_file_valid)
            {
                ebr_app_display_pop_up_format_not_supported();
            }
            else
            {
                DisplayConfirm(
                    STR_GLOBAL_YES,
                    IMG_GLOBAL_YES,
                    STR_GLOBAL_NO,
                    IMG_GLOBAL_NO,
                    get_string(STR_ADD_TO_EBOOK_FOLDER),
                    IMG_GLOBAL_QUESTION,
                    WARNING_TONE);

                SetLeftSoftkeyFunction(ebr_fmgr_move_to_ebook_folder, KEY_EVENT_UP);
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_add_to_book_shelf
 * DESCRIPTION
 *  Add files from file manager to book shelf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_add_to_book_shelf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ebr_frm_check_nfo_file_size())
    {
        DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
        ebr_app_dispaly_less_memory_pop_up();
    }
    else
    {
        switch (ebr_frm_add_to_book_shelf())
        {
            case EBR_FRM_NFO_CREATE_SUCCESS:
                ebr_entry_open_book();
                break;
            case EBR_FRM_NFO_CREATE_FILE_TYPE_NOT_SUPPORTED:
                DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
                ebr_app_display_pop_up_format_not_supported();
                ebr_frm_write_default_value_for_nfo_id_in_nvram();
                break;
            case EBR_FRM_EMPTY_BOOK:
                DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
                ebr_app_display_pop_up_empty_book();
                ebr_frm_write_default_value_for_nfo_id_in_nvram();
                break;
            default:
                DeleteNScrId(SCR_FMGR_APP_FILE_OPTION);
                ebr_app_display_pop_up_error_opening_book();
                ebr_frm_write_default_value_for_nfo_id_in_nvram();
                break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ebr_display_error_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_display_error_pop_up(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_dispaly_less_memory_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_dispaly_less_memory_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_EBOOK_MEMORY_LESS), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
}

#ifdef __MMI_LANG_HINDI__


/*****************************************************************************
 * FUNCTION
 *  ebr_app_show_string_incomplete_pop_up
 * DESCRIPTION
 *  Display incomplete popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_show_string_incomplete_pop_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString(STR_INCOMPLETE_SEARCH_STRING),
        IMG_GLOBAL_WARNING,
        1,
        EBR_ST_NOTIFYDURATION,
        WARNING_TONE);
}
#endif /* __MMI_LANG_HINDI__ */ 


/*****************************************************************************
 * FUNCTION
 *  ebr_app_clear_all_key_handlers
 * DESCRIPTION
 *  Clear All key Handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_clear_all_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyEvents();
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  ebr_app_clear_all_key_handlers
 * DESCRIPTION
 *  Highlight handler of ebook setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_highlight_setting(S32 index)
{
    if (index == EBR_TOTAL_NUMBER_OF_ITEM_BKSHLF - 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
        SetLeftSoftkeyFunction(mmi_ebr_entry_select_drive, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(NULL, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
}

void mmi_ebr_entry_select_drive(void)
{        
    mmi_fmgr_sel_drv_and_enter(APP_EBOOK, mmi_ebr_save_drive_selection, g_ebookset_cntx_p->inlineHighligtItemSelectMemory);    
}

void mmi_ebr_save_drive_selection(S8 drive_letter)
{
    /* drive_letter == 0 means user press back and give up the change */
    if (drive_letter != 0)
    {
        g_ebookset_cntx_p->inlineHighligtItemSelectMemory = drive_letter;    
    }    
}

#ifdef __MMI_BPP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  ebr_highlight_book_bpp_print
 * DESCRIPTION
 *  Set highlight handler for BPP print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_highlight_book_bpp_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);

    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(ebr_app_bpp_print, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ebr_app_bpp_print
 * DESCRIPTION
 *  start for BPP print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ebr_app_bpp_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_bpp_app_is_printing() == MMI_BPP_PRINT_STATUS_BUSY)
    {
        mmi_bt_bpp_busy_popup();
    }
    else
    {
        /* create temp file name */

        mmi_bt_bpp_app_print(MMI_BPP_APP_BOOK, ebr_frm_bpp_xhtml_table_constructer);
        ebr_frm_bpp_reset_data();
    }
    return;
}

#endif /* __MMI_BPP_SUPPORT__ */ 

#endif /* __MMI_EBOOK_READER__ */ 
