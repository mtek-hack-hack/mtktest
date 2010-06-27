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
 * JBrowserMMIOfflinePages.c
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
 *   Vikas Lal Srivastava  -20070925
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_JBROWSERMMIOFFLINEPAGES_C
#define _MMI_JBROWSERMMIOFFLINEPAGES_C

/*  Include: MMI header file */
#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)
#ifdef __MMI_JATAAYU_BRW_OFFLINE_PAGES__
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "DateTimeGprot.h"
#include "USBDeviceGprot.h"
/*  Include: Jataayu and other header files */
#include "JBrowserMMIProts.h"
#include "jdd_fileapi.h"        /* Included for the function jdd_FSGetDiskLabel() */
#include "JBrowserResDef.h"
#include "CallManagementGprot.h"        /* included for function --------  isInCall() */
#include "jdd_browserconfig.h"  /* For the config macros of offline pages */

static brw_offline_pages_context_struct g_offline_pages_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_init
 * DESCRIPTION
 *  initialize highlight handlers for the menu items of the offline pages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_SAVE, mmi_brw_offline_pages_save_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_SAVED_PAGES, mmi_brw_offline_pages_saved_pages_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_SAVED_PAGES, mmi_brw_offline_pages_saved_pages_highlight_hdlr);
    SetHiliteHandler(
        MENU_ID_BRW_OFFLINE_PAGES_OPTION_GOTO,
        mmi_brw_offline_pages_saved_pages_options_goto_highlight_hdlr);
    SetHiliteHandler(
        MENU_ID_BRW_OFFLINE_PAGES_OPTION_RENAME,
        mmi_brw_offline_pages_saved_pages_options_rename_highlight_hdlr);
    SetHiliteHandler(
        MENU_ID_BRW_OFFLINE_PAGES_OPTION_DELETE,
        mmi_brw_offline_pages_saved_pages_options_delete_highlight_hdlr);
    SetHiliteHandler(
        MENU_ID_BRW_OFFLINE_PAGES_OPTION_DELETE_ALL,
        mmi_brw_offline_pages_saved_pages_options_delete_all_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_OPTION_SET_HOMEPAGE, mmi_brw_offline_pages_set_hmpage_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_OPTION_ADD_TO_BKM, mmi_brw_offline_pages_add_bkms_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_OPTION_PAGE_INFO, mmi_brw_offline_pages_page_info_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_EDIT_OPTION_DONE, mmi_brw_offline_pages_edit_done_highlight_hdlr);
    SetHiliteHandler(
        MENU_ID_BRW_OFFLINE_PAGES_EDIT_OPTION_INPUT_METHOD,
        mmi_brw_offline_edit_input_method_info_highlight_hdlr);
    SetHiliteHandler(MENU_ID_BRW_OFFLINE_PAGES_EDIT_OPTION_CANCEL, mmi_brw_offline_pages_edit_cancel_highlight_hdlr);
}

/********************************************************************************************
 ********************************---START OF HILIGHT HANDLERS---*****************************
 ********************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_save_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_save_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_pre_entry_offline_pages_enter_name, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_pre_entry_offline_pages_saved_pages_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_brw_pre_entry_offline_pages_saved_pages_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_set_hmpage_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_set_hmpage_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_set_hmpage, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_add_bkms_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_add_bkms_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_add_to_bookmark, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_goto_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_saved_pages_options_goto, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_delete_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_saved_pages_confirm_delete, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_delete_all_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_delete_all_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_saved_pages_confirm_delete_all, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_rename_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_rename_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_saved_pages_options_pre_rename, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_page_info_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_page_info_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_offline_pages_options_page_info, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_edit_done_highlight_hdlr
 * DESCRIPTION
 *  This highlight hndlr set the left soft key function according to the screen present in history
 *  So that we can use common screen for editor option screen while saving or renaming a file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_edit_done_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    if (IsScreenPresent(SCR_ID_BRW_OFFLINE_PAGES_ENTER_NAME))
    {
        SetLeftSoftkeyFunction(mmi_brw_offline_pages_save_page_pre_entry, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_offline_pages_save_page_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (IsScreenPresent(SCR_ID_BRW_OFFLINE_PAGES_ENTER_NEW_NAME))
    {
        SetLeftSoftkeyFunction(mmi_brw_offline_pages_rename_pre_entry, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_offline_pages_rename_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ASSERT(0);
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_edit_input_method_info_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_edit_input_method_info_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_brw_go_back_two_history);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_edit_cancel_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_edit_cancel_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_brw_go_back_two_history, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_brw_go_back_two_history, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/********************************************************************************************
 ********************************---END OF HIGHLIGHT HANDLERS---*******************************
 ********************************************************************************************/

/********************************************************************************************
 ********************************---START OF CODE SECTION---*********************************
 ********************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_offline_pages_enter_name
 * DESCRIPTION
 *  Pre entry to enter name. Create OfflinePages directory,check the maximum limit and perform other validations
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_offline_pages_enter_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 dir_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };
    /*    S8 ucs2_extension[(MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH + 1) * ENCODING_LENGTH] = { '\0', }; */
    S8 *temp_name = NULL;
    U16 num_of_files = 0;

    JDD_FSHANDLE fs_handle = NULL;
    JC_RETCODE ret_code = JC_OK;
    JC_PAGE_INFO page_info;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_pre_entry_offline_pages_enter_name");
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    /*    mmi_asc_to_ucs2(ucs2_extension, MMI_BRW_OFFLINE_PAGE_EXTENSION); */
    mmi_brw_offline_pages_get_number_of_pages_at_location(&num_of_files, g_offline_pages_cntx.selected_loc);
    if (num_of_files < (U16) mmi_brw_offline_pages_get_max_num_of_pages())      /* TO-DO : ADD MACRO FOR MEMORY CARD SUPPORT ALSO */
    {
        mmi_brw_offline_pages_suspend_auto_refresh_timer();
        memset(g_offline_pages_cntx.file_name, 0, 4);
        temp_activated_task_id = jdd_MemGetActiveModuleID();
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserGetCurrentPageInfo(g_mmi_brw_pbrowser_ctxt, &page_info);
        jdd_MemSetActiveModuleID(temp_activated_task_id);
        if (JC_OK != ret_code)
        {
            page_info.psTitle = NULL;
        }
        page_info.psTitle = (JC_CHAR*) mmi_brw_offline_pages_remove_blank_spaces_from_start((S8*) page_info.psTitle);

        if (page_info.psTitle != NULL)
        {
            mmi_ucs2ncpy((S8*) g_offline_pages_cntx.file_name, (S8*) page_info.psTitle, FMGR_MAX_INPUT_FILE_LEN);
        }

        temp_name = mmi_brw_saved_pages_validate_name((S8*) g_offline_pages_cntx.file_name);
        if (temp_name == NULL)
        {
            memset(g_offline_pages_cntx.file_name, 0, 4);
        }
        mmi_brw_saved_pages_get_absolute_path_ucs2(dir_path);
        ret_code = jdd_FSInitialize(&fs_handle);
        if (ret_code == JC_OK)
        {
            if (jdd_FSIsDirExist(fs_handle, (WCHAR*) dir_path) == E_FALSE)
            {
                ret_code = jdd_FSMakeDir(fs_handle, (WCHAR*) dir_path);
                if (ret_code != JC_OK)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        MMI_BRW_POPUP_TIME,
                        ERROR_TONE);

                    jdd_FSDeinitialize(fs_handle);
                    return;
                }
            }
            jdd_FSDeinitialize(fs_handle);
            FS_SetAttributes((U16*) dir_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            mmi_brw_entry_offline_pages_enter_name();
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FULL),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_saved_pages_get_absolute_path_ucs2
 * DESCRIPTION
 *  use to get the default path of the offline pages in UCS2 format
 * PARAMETERS
 *  path        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_saved_pages_get_absolute_path_ucs2(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 drv_letter = 0;
    S8 *temp_path = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        ASSERT(0);
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_saved_pages_get_absolute_path_ucs2");
    temp_path = (S8*) jdd_MemAlloc(1, ((strlen((S8*) mmi_brw_offline_pages_get_root_dir())) + 1) * ENCODING_LENGTH);
    if (temp_path == NULL)
    {
        PRINT_INFORMATION("OFFLINE BROWSING: jdd_MemAlloc Fails");
        ASSERT(0);
    }
    mmi_asc_to_ucs2((S8*) temp_path, (S8*) mmi_brw_offline_pages_get_root_dir());
    switch (g_offline_pages_cntx.selected_loc)
    {
        case E_JC_OFFLINE_PAGE_MEM_PHONE:
            drv_letter = jdd_FSGetDiskLabel(WAP_STORAGE_PUBLIC);
            break;
        case E_JC_OFFLINE_PAGE_MEM_CARD:
            drv_letter = jdd_FSGetDiskLabel(WAP_STORAGE_EXTERNAL);
            break;
        default:
            ASSERT(0);
            break;
    }
    sprintf(path, "%c", drv_letter);
    mmi_asc_to_ucs2((S8*) path, (S8*) path);
    mmi_ucs2cat((S8*) path, (S8*) L":");
    mmi_ucs2cat((S8*) path, (S8*) temp_path);
    if (temp_path != NULL)
    {
        jdd_MemFree(temp_path);
        temp_path = NULL;
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Out mmi_brw_saved_pages_get_absolute_path_ucs2");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_offline_pages_enter_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_offline_pages_enter_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_entry_offline_pages_enter_name");
    EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_ENTER_NAME, NULL, mmi_brw_entry_offline_pages_enter_name, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_ENTER_NAME);
    ShowCategory5Screen(
        STR_ID_BRW_OFFLINE_PAGES_EDIT_FILENAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_offline_pages_cntx.file_name,
        (FMGR_MAX_INPUT_FILE_LEN),
        (U8*) gui_buffer);

    SetLeftSoftkeyFunction(mmi_brw_offline_pages_edit_screen_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_confirm_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_confirm_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_delete_extension(g_offline_pages_cntx.file_name);
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_GLOBAL_SAVE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_offline_pages_save_page, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_brw_offline_pages_go_back_history_with_no_replace, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_save_page_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_save_page_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_extension[(MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH + 1) * ENCODING_LENGTH] = { '\0', };
    U8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', '\0', };
    S8 *temp_name = NULL;
    JDD_FSHANDLE fs_handle = NULL;
    JC_RETCODE ret_code = JC_OK;

    JC_BOOLEAN is_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_save_page_pre_entry");
    mmi_asc_to_ucs2(ucs2_extension, MMI_BRW_OFFLINE_PAGE_EXTENSION);
    if (mmi_ucs2strlen((S8*) g_offline_pages_cntx.file_name))
    {
        temp_name = mmi_brw_saved_pages_validate_name((S8*) g_offline_pages_cntx.file_name);
        if (temp_name == NULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_INVALID_FILENAME),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
            return;
        }
        mmi_ucs2cpy((PS8) g_offline_pages_cntx.file_name, (PS8) temp_name);
        mmi_ucs2cat((PS8) g_offline_pages_cntx.file_name, (PS8) ucs2_extension);
        mmi_brw_saved_pages_get_absolute_path_ucs2((S8*) ucs2_path);
        mmi_ucs2cat((S8*) ucs2_path, (S8*) g_offline_pages_cntx.file_name);
        /*      is_exist = mmi_brw_offline_pages_is_file_exists(g_offline_pages_cntx.file_name); */
        ret_code = jdd_FSInitialize(&fs_handle);
        if (ret_code == JC_OK)
        {
            is_exist = jdd_FSIsFileExist(fs_handle, (JC_CHAR*) ucs2_path);
            jdd_FSDeinitialize(fs_handle);
        }
        if (is_exist)
        {
            DisplayConfirm(
                STR_GLOBAL_YES,
                IMG_GLOBAL_YES,
                STR_GLOBAL_NO,
                IMG_GLOBAL_NO,
                get_string(STR_ID_BRW_OFFLINE_PAGES_REPLACE_FILE),
                IMG_GLOBAL_QUESTION,
                WARNING_TONE);

            mmi_brw_delete_extension(g_offline_pages_cntx.file_name);

            SetLeftSoftkeyFunction(mmi_brw_offline_pages_delete_and_save, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_brw_go_back_two_history, KEY_EVENT_UP);
        }
        else
        {
            PRINT_INFORMATION("OFFLINE BROWSING: Calling mmi_brw_offline_pages_save_page from pre save");
            mmi_brw_offline_pages_confirm_save();
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_FILENAME_EMPTY), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_saved_pages_validate_name
 * DESCRIPTION
 *  Use to validate the name entered by the user
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  Name if name is valid otherwise NULL.
 *****************************************************************************/
S8 *mmi_brw_saved_pages_validate_name(S8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = 0;
    FS_HANDLE fs_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return NULL;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside Validate Name For the Name : ");
    mmi_print_ansii_for_unicode_string(name);
    if (name != NULL)
    {
        name = mmi_brw_offline_pages_remove_blank_spaces_from_start(name);
        len = mmi_ucs2strlen(name);
        if (len == 0)
        {
            return NULL;
        }
        fs_handle = FS_GetAttributes((JC_CHAR*) name);
        if (fs_handle == FS_INVALID_FILENAME)
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
    return name;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_remove_blank_spaces_from_start
 * DESCRIPTION
 *  Use to Remove blank spaces from the starting of the name entered by user
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  Modified name
 *****************************************************************************/
S8 *mmi_brw_offline_pages_remove_blank_spaces_from_start(S8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cntr = 0;
    U16 len = 0;
    S8 *temp_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return NULL;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_offline_pages_remove_blank_spaces_from_start");

    temp_name = name;

    len = (mmi_ucs2strlen(name)) * ENCODING_LENGTH;

    while (temp_name[cntr] == ' ' && temp_name[cntr + 1] == 0)
    {
        temp_name += ENCODING_LENGTH;
        if (cntr >= len)
        {
            break;
        }
    }
    return temp_name;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Out mmi_brw_offline_pages_remove_blank_spaces_from_start");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_delete_extension
 * DESCRIPTION
 *  remove the extension from the file name
 * PARAMETERS
 *  name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_delete_extension(S8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length = 0;
    U16 cntr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((name == NULL) || (!mmi_ucs2strlen(name)))
    {
        return;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_delete_extension");
    length = (ENCODING_LENGTH * mmi_ucs2strlen(name));
    cntr = length;
    while (*(name + cntr) != '.')
    {
        if (cntr == 0)
        {
            return; /* error */
        }
        cntr = cntr - ENCODING_LENGTH;
    }
    while (*(name + cntr) != '\0')
    {
        *(name + cntr) = '\0';
        if (cntr == 0)
        {
            break;  /* error */
        }
        length = length + ENCODING_LENGTH;
    }
    *(name + cntr) = '\0';
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_delete_extension");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_save_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_save_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };
    S8 ucs2_extension[(MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH + 1) * ENCODING_LENGTH] = { '\0', };
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_save_page");
    mmi_brw_saved_pages_get_absolute_path_ucs2((S8*) ucs2_path);
    mmi_asc_to_ucs2(ucs2_extension, MMI_BRW_OFFLINE_PAGE_EXTENSION);
    mmi_ucs2cat((PS8) g_offline_pages_cntx.file_name, (PS8) ucs2_extension);
    mmi_ucs2cat((S8*) ucs2_path, (S8*) g_offline_pages_cntx.file_name);
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    ret_code = jdi_BrowserSaveOfflinePage(g_mmi_brw_pbrowser_ctxt, (JC_CHAR*) ucs2_path);
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (JC_OK == ret_code)
    {
        g_offline_pages_cntx.operation_type = E_JC_OFFLINE_PAGE_OPER_SAVE;
        mmi_brw_offline_pages_show_progress_screen();
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    if (IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))  /* Check for Auto Refresh Page change */
    {
        DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_BRW_JBROWSER_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_delete_and_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_delete_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ucs2_path_new[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };
    S8 ucs2_extension[(MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH + 1) * ENCODING_LENGTH] = { '\0', };
    U16 index = 0;

    JC_RETCODE ret_code = JC_OK;
    JDD_FSHANDLE fs_handle = NULL;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_delete_and_save");
    mmi_brw_saved_pages_get_absolute_path_ucs2((S8*) ucs2_path_new);
    mmi_asc_to_ucs2(ucs2_extension, MMI_BRW_OFFLINE_PAGE_EXTENSION);
    mmi_ucs2cat((PS8) g_offline_pages_cntx.file_name, (PS8) ucs2_extension);
    mmi_ucs2cat((S8*) ucs2_path_new, (S8*) g_offline_pages_cntx.file_name);

    index = mmi_brw_offline_pages_get_index_at_file_name((S8*) g_offline_pages_cntx.file_name);
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    if (index >= (U16) mmi_brw_offline_pages_get_max_num_of_pages())
    {
        ret_code = jdd_FSInitialize(&fs_handle);
        if (ret_code == JC_OK)
        {
            ret_code = jdd_FSDelete(fs_handle, (JC_CHAR*) ucs2_path_new);
            if (ret_code != JC_OK)
            {
                ret_code = jdd_GetFSLastErrCode(jdd_MemGetActiveModuleID());
                if (ret_code == JC_ERR_FILE_IS_READ_ONLY)
                {
                    JC_INT32 attribute = 0;

                    ret_code = jdd_FSGetAttributes((JC_CHAR*) ucs2_path_new, &attribute);
                    if (ret_code == JC_OK)
                    {
                        jdd_FSSetAttributes(
                            (JC_CHAR*) ucs2_path_new,
                            (JC_INT8) (attribute & ~(JDD_FS_ATTR_READ_ONLY)));

                        ret_code = jdd_FSDelete(fs_handle, (JC_CHAR*) ucs2_path_new);

                        if (ret_code != JC_OK)
                        {
                            ret_code = jdd_GetFSLastErrCode(jdd_MemGetActiveModuleID());
                        }
                    }
                }
            }
        }
        jdd_FSDeinitialize(fs_handle);
    }
    else
    {
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserDeleteOfflinePage(g_mmi_brw_pbrowser_ctxt, index);
    }

    if ((ret_code == JC_OK) || (ret_code == JC_ERR_FILE_INVALID_PATH))
    {
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserSaveOfflinePage(g_mmi_brw_pbrowser_ctxt, (JC_CHAR*) ucs2_path_new);
    }
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (JC_OK == ret_code)
    {
        g_offline_pages_cntx.operation_type = E_JC_OFFLINE_PAGE_OPER_SAVE;
        mmi_brw_offline_pages_show_progress_screen();
    }
    else
    {
        mmi_brw_offline_pages_show_popup(ret_code);
    }

    if (IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))  /* Check for Auto Refresh Page change */
    {
        DeleteUptoScrID(SCR_ID_BRW_RENDERED_PAGE_OPTIONS);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_BRW_JBROWSER_MAIN);
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Out mmi_brw_offline_pages_delete_and_save");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_print_ansii_for_unicode_string
 * DESCRIPTION
 *  Print log for a UCS2 String
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_print_ansii_for_unicode_string(S8 *ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ansii_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_print_ansii_for_unicode_string");
    if (ucs2_str == NULL)
    {
        return;
    }
    ansii_str = (S8*) jdd_MemAlloc(1, ((mmi_ucs2strlen((S8*) ucs2_str)) + 1));
    if (ansii_str == NULL)
    {
        PRINT_INFORMATION("OFFLINE BROWSING: jdd_MemAlloc Fails");
        ASSERT(0);
    }

    mmi_ucs2_to_asc((S8*) ansii_str, (S8*) ucs2_str);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", ansii_str);
    if (ansii_str != NULL)
    {
        jdd_MemFree(ansii_str);
        ansii_str = NULL;
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Out of mmi_print_ansii_for_unicode_string");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_offline_pages_saved_pages_list
 * DESCRIPTION
 *  Pre Entry function for offline pages list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_offline_pages_saved_pages_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 dir_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };
    U16 num_of_file = 0;

    JDD_FSHANDLE fs_handle = NULL;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    if (mmi_brw_offline_pages_need_sync())
    {
        ret_code = mmi_brw_offline_pages_sync();
    }
    if (JC_OK != ret_code)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        return;
    }
    mmi_brw_offline_pages_get_number_of_pages_at_location(&num_of_file, g_offline_pages_cntx.selected_loc);
    if (num_of_file == 0)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_BRW_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }
    mmi_brw_saved_pages_get_absolute_path_ucs2(dir_path);
    ret_code = jdd_FSInitialize(&fs_handle);
    if (ret_code == JC_OK)
    {
        if (jdd_FSIsDirExist(fs_handle, (WCHAR*) dir_path) == E_FALSE)
        {
            ret_code = jdd_FSMakeDir(fs_handle, (WCHAR*) dir_path);
            if (ret_code != JC_OK)
            {
                DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);

                jdd_FSDeinitialize(fs_handle);
                return;
            }
        }
        jdd_FSDeinitialize(fs_handle);
        FS_SetAttributes((U16*) dir_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        mmi_brw_entry_offline_pages_saved_pages_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_offline_pages_saved_pages_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_offline_pages_saved_pages_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U16 num_of_file = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_entry_offline_pages_saved_pages_list ");
    mmi_brw_offline_pages_free_curr_page_info();
    mmi_brw_offline_pages_get_number_of_pages_at_location(&num_of_file, g_offline_pages_cntx.selected_loc);
    if (num_of_file > (U16) mmi_brw_offline_pages_get_max_num_of_pages())
    {
        ASSERT(0);
    }
    if (num_of_file > 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d ", "OFFLINE BROWSING: Total offline pages Received= ",
                             num_of_file);
        /* temp_node is set to the first node of the list */
        g_offline_pages_cntx.temp_node = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.offline_info->pFileList;

        EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_LIST, NULL, mmi_brw_entry_offline_pages_saved_pages_list, NULL);
        gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_LIST);

        SetParentHandler(MENU_ID_BRW_OFFLINE_PAGES_SAVED_PAGES);
        RegisterHighlightHandler(mmi_brw_offline_pages_set_file_index);
        ShowCategory184Screen(
            STR_ID_BRW_OFFLINE_PAGES_SAVED_PAGES,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            num_of_file,
            mmi_brw_offline_pages_show_list_category_callback,
            NULL,
            0,
            gui_buffer);

        SetLeftSoftkeyFunction(mmi_brw_pre_entry_offline_pages_options, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_pre_entry_offline_pages_options, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_BRW_POPUP_TIME, EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_show_list_category_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [OUT]       
 *  img_buff_p          [OUT]       
 *  str_img_mask        [OUT]       
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_brw_offline_pages_show_list_category_callback(
        S32 item_index,
        UI_string_type str_buff,
        PU8 *img_buff_p,
        U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_string[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_show_list_category_callback");
    if (g_offline_pages_cntx.temp_node != NULL)
    {
        while (g_offline_pages_cntx.temp_node->eMemoryType != g_offline_pages_cntx.selected_loc)
        {
            g_offline_pages_cntx.temp_node = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.temp_node->pNext;
        }
        mmi_ucs2cpy(temp_string, (S8*) g_offline_pages_cntx.temp_node->pfName);
        mmi_brw_delete_extension(temp_string);
        mmi_ucs2cpy((PS8) str_buff, (PS8) temp_string);
        g_offline_pages_cntx.temp_node = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.temp_node->pNext;

        *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: display page name = ");
    mmi_print_ansii_for_unicode_string(temp_string);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_set_file_index
 * DESCRIPTION
 *  This function set the Actual index of the selected file
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_set_file_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_offline_pages_cntx.selected_file_index = 0;
    g_offline_pages_cntx.temp_node = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.offline_info->pFileList;
    while (index >= 0)
    {
        if (g_offline_pages_cntx.temp_node->eMemoryType == g_offline_pages_cntx.selected_loc)
        {
            index--;
        }
        if (g_offline_pages_cntx.selected_file_index > (U16) mmi_brw_offline_pages_get_max_num_of_pages())
        {
            ASSERT(0);
        }
        g_offline_pages_cntx.selected_file_index++;
        g_offline_pages_cntx.temp_node = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.temp_node->pNext;
    }
    g_offline_pages_cntx.selected_file_index--;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_pre_entry_offline_pages_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_pre_entry_offline_pages_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };
    JC_BOOLEAN is_exist = MMI_FALSE;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_pre_entry_offline_pages_options");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        /* Return code should not check, as delete always fails - this is only to modify the XML for syncing purpose */
        /*    temp_activated_task_id = jdd_MemGetActiveModuleID();
           jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
           jdi_BrowserDeleteOfflinePage(g_mmi_brw_pbrowser_ctxt, g_offline_pages_cntx.selected_file_index); 
           jdd_MemSetActiveModuleID(temp_activated_task_id); 
           DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST); */
        return;
    }
    if (g_offline_pages_cntx.curr_page_info_p == NULL)
    {
        ret_code = mmi_brw_offline_pages_allocate_curr_page_info();
        if (JC_OK != ret_code)
        {
            PRINT_INFORMATION("OFFLINE BROWSING: jdd_MemAlloc Fails Inside Saved Pages Pre Entry");
            ASSERT(0);
        }
    }
    mmi_brw_offline_pages_fill_curr_page_info();
    mmi_brw_offline_pages_options();
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out Of mmi_brw_pre_entry_offline_pages_options");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_of_items[MAX_SUB_MENUS] = {0, };
    U8 *gui_buffer = NULL;
    S32 num_of_items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_options");
    EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS, NULL, mmi_brw_offline_pages_options, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
    num_of_items = GetNumOfChild(MENU_ID_BRW_OFFLINE_PAGES_OPTIONS);
    GetSequenceStringIds(MENU_ID_BRW_OFFLINE_PAGES_OPTIONS, list_of_items);
    SetParentHandler(MENU_ID_BRW_OFFLINE_PAGES_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory15Screen(
        STR_ID_BRW_OFFLINE_PAGES_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_goto
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };
    JC_BOOLEAN is_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_saved_pages_options_goto");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }
    mmi_brw_saved_pages_get_absolute_path_ucs2(ucs2_path);
    mmi_ucs2cat((S8*) ucs2_path, (S8*) file_name);
    mmi_ucs2cpy((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) L"file://");
    mmi_ucs2cat((S8*) g_mmi_brw_cntx.brw_current_url, (S8*) ucs2_path);

    if (g_mmi_brw_cntx.fetch_url_info.psUrl != NULL)
    {
        jdd_MemFree(g_mmi_brw_cntx.fetch_url_info.psUrl);
        g_mmi_brw_cntx.fetch_url_info.psUrl = NULL;
    }
    g_mmi_brw_cntx.fetch_url_info.psUrl =
        (JC_CHAR*) jdd_MemAlloc((mmi_ucs2strlen((S8*) g_mmi_brw_cntx.brw_current_url) + 1), sizeof(JC_CHAR));
    mmi_ucs2cpy((S8*) g_mmi_brw_cntx.fetch_url_info.psUrl, (S8*) g_mmi_brw_cntx.brw_current_url);
    g_mmi_brw_cntx.fetch_url_info.pPostData = NULL;
    g_mmi_brw_cntx.fetch_url_info.uiPostDataLen = 0;

    /*    mmi_brw_set_current_url((S8*) g_mmi_brw_cntx.brw_current_url); */
    mmi_brw_pre_entry_goto_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_confirm_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_confirm_delete(void)
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
        get_string(STR_ID_BRW_OFFLINE_PAGES_DELETE_SAVED_PAGE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_offline_pages_saved_pages_options_delete, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };

    JC_RETCODE ret_code = JC_OK;
    JC_BOOLEAN is_exist = MMI_FALSE;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_saved_pages_options_delete");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    ret_code = jdi_BrowserDeleteOfflinePage(g_mmi_brw_pbrowser_ctxt, g_offline_pages_cntx.selected_file_index);
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (ret_code == JC_OK)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
    }
    else
    {
        mmi_brw_offline_pages_show_popup(ret_code);
    }
    DeleteScreenIfPresent(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
    PRINT_INFORMATION("OFFLINE BROWSING: Out mmi_brw_offline_pages_saved_pages_options_delete");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_confirm_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_confirm_delete_all(void)
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
        get_string(STR_ID_BRW_OFFLINE_PAGES_DELETE_ALL_SAVED_PAGES),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_brw_offline_pages_saved_pages_options_delete_all, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };

    JC_RETCODE ret_code = JC_OK;
    JDD_FSHANDLE fs_handle = NULL;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_offline_pages_saved_pages_options_delete_all");
    mmi_brw_saved_pages_get_absolute_path_ucs2(ucs2_path);
    ret_code = jdd_FSInitialize(&fs_handle);
    if (ret_code == JC_OK)
    {
        if (jdd_FSIsDirExist(fs_handle, (WCHAR*) ucs2_path) == E_FALSE)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
            jdd_FSDeinitialize(fs_handle);
            return;
        }
        FS_SetAttributes((const WCHAR*)ucs2_path, (U8) (FS_ATTR_DIR & ~(FS_ATTR_READ_ONLY)));
        jdd_FSDeinitialize(fs_handle);
        temp_activated_task_id = jdd_MemGetActiveModuleID();
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserDeleteAllOfflinePages(g_mmi_brw_pbrowser_ctxt, g_offline_pages_cntx.selected_loc);
        jdd_MemSetActiveModuleID(temp_activated_task_id);
        g_offline_pages_cntx.operation_type = E_JC_OFFLINE_PAGE_OPER_DELETEALL;
        mmi_brw_offline_pages_show_progress_screen();
        DeleteScreenIfPresent(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                             "OFFLINE BROWSING: Out mmi_brw_offline_pages_saved_pages_options_delete_all");
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_saved_pages_options_pre_rename
 * DESCRIPTION
 *  Pre entry to the rename option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_saved_pages_options_pre_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };
    JC_BOOLEAN is_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_saved_pages_options_pre_rename");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }

    memset(g_offline_pages_cntx.file_name, 0, 4);
    mmi_ucs2cpy((S8*) g_offline_pages_cntx.file_name, (S8*) file_name);
    mmi_brw_delete_extension(g_offline_pages_cntx.file_name);
    mmi_brw_entry_offline_pages_enter_new_name();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_offline_pages_enter_new_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_entry_offline_pages_enter_new_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_entry_offline_pages_enter_new_name");
    EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_ENTER_NEW_NAME, NULL, mmi_brw_entry_offline_pages_enter_new_name, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_ENTER_NEW_NAME);
    ShowCategory5Screen(
        STR_ID_BRW_OFFLINE_PAGES_EDIT_FILENAME,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_offline_pages_cntx.file_name,
        (FMGR_MAX_INPUT_FILE_LEN),
        (U8*) gui_buffer);

    SetLeftSoftkeyFunction(mmi_brw_offline_pages_edit_screen_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_rename_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_rename_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_extension[(MMI_BRW_OFFLINE_PAGE_EXTENSION_LENGTH + 1) * ENCODING_LENGTH] = { '\0', };
    S8 *temp_name = NULL;
    U8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', '\0', };
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = {NULL};
    U16 length = 0;
    JDD_FSHANDLE fs_handle = NULL;
    JC_BOOLEAN is_exist = MMI_FALSE;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_rename_pre_entry");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }
    is_exist = MMI_FALSE;
    mmi_asc_to_ucs2(ucs2_extension, MMI_BRW_OFFLINE_PAGE_EXTENSION);
    length = mmi_ucs2strlen((S8*) g_offline_pages_cntx.file_name);
    if (length)
    {
        temp_name = mmi_brw_saved_pages_validate_name((S8*) g_offline_pages_cntx.file_name);
        if (temp_name == NULL)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_INVALID_FILENAME),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
            return;
        }

        mmi_ucs2cpy((PS8) g_offline_pages_cntx.file_name, (PS8) temp_name);
        mmi_ucs2cat((PS8) g_offline_pages_cntx.file_name, (PS8) ucs2_extension);
        mmi_brw_saved_pages_get_absolute_path_ucs2((S8*) ucs2_path);
        mmi_ucs2cat((S8*) ucs2_path, (S8*) g_offline_pages_cntx.file_name);
        /*     is_exist = mmi_brw_offline_pages_is_file_exists(g_offline_pages_cntx.file_name); */
        if (!mmi_ucs2cmp((S8*) g_offline_pages_cntx.file_name, (S8*) file_name))
        {
            GoBacknHistory(1);
            return;
        }
        ret_code = jdd_FSInitialize(&fs_handle);
        if (ret_code == JC_OK)
        {
            is_exist = jdd_FSIsFileExist(fs_handle, (JC_CHAR*) ucs2_path);
            jdd_FSDeinitialize(fs_handle);
        }
        if (is_exist)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_FILE_ALREADY_EXISTS),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
            return;
        }
        else
        {
            mmi_brw_offline_pages_rename();
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_FILENAME_EMPTY), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_rename");
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    ret_code = jdi_BrowserRenameOfflinePage(
                g_mmi_brw_pbrowser_ctxt,
                g_offline_pages_cntx.selected_file_index,
                (JC_CHAR*) g_offline_pages_cntx.file_name);
    jdd_MemSetActiveModuleID(temp_activated_task_id);

    mmi_brw_offline_pages_show_popup(ret_code);
    DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
    PRINT_INFORMATION("OFFLINE BROWSING: Out mmi_brw_offline_pages_rename");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_set_hmpage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_set_hmpage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };
    JC_BOOLEAN is_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_set_hmpage");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }
    if (g_offline_pages_cntx.curr_page_info_p->pmURL != NULL)
    {
        if ((mmi_ucs2strlen((PS8) g_offline_pages_cntx.curr_page_info_p->pmURL)) <= MMI_BRW_BKM_MAX_URL_LENGTH)
        {
            mmi_ucs2ncpy(
                (S8*) g_mmi_brw_cntx.brw_current_url,
                (S8*) g_offline_pages_cntx.curr_page_info_p->pmURL,
                MMI_BRW_BKM_MAX_URL_LENGTH);
            mmi_brw_set_as_homepage(g_mmi_brw_cntx.brw_current_url);
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_URL_LEN_EXCEED),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
        }
    }
    DeleteScreenIfPresent(SCR_ID_BRW_OFFLINE_PAGES_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_fill_page_info_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info_buffer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_fill_page_info_buffer(U8 **info_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = {0};
    S8 ucs2_time_string[40] = { '\0', };
    S8 temp_str[MMI_BRW_BKM_MAX_URL_LENGTH] = { '\0', };
    S8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = { '\0', };

    FS_HANDLE fs_handle = NULL;
    FS_DOSDirEntry file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_fill_page_info_buffer");
    mmi_brw_saved_pages_get_absolute_path_ucs2(ucs2_path);
    mmi_brw_offline_pages_get_file_name_at_index((S8*) file_name, g_offline_pages_cntx.selected_file_index);
    mmi_ucs2cat(ucs2_path, (S8*) file_name);
    if ((fs_handle = FS_FindFirst(
                        (U16*) ucs2_path,
                        0,
                        0,
                        &file_info,
                        (U16*) file_name,
                        MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH)) >= 0)
    {
        FS_FindClose(fs_handle);

        mmi_ucs2cpy((S8*) (*info_buffer), (S8*) get_string(STR_ID_BRW_TITLE));
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        mmi_ucs2cpy((PS8) temp_str, (PS8) file_name);
        mmi_brw_delete_extension(temp_str);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) temp_str);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        mmi_ucs2cat((S8*) (*info_buffer), (S8*) get_string(STR_ID_BRW_PUSH_URL));
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        mmi_ucs2ncat(
            (S8*) (*info_buffer),
            (S8*) g_offline_pages_cntx.curr_page_info_p->pmURL,
            MMI_BRW_BKM_MAX_URL_LENGTH);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        mmi_ucs2cat((S8*) (*info_buffer), (S8*) get_string(STR_ID_BRW_OFFLINE_PAGES_CREATED_TIME));
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        mmi_brw_create_ucs2_offline_pages_time_format_string(&file_info.CreateDateTime, ucs2_time_string);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) ucs2_time_string);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        mmi_ucs2cat((S8*) (*info_buffer), (S8*) get_string(STR_ID_BRW_CONTENT_SIZE));
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");

        gui_itoa(file_info.FileSize, (UI_string_type) temp_str, 10);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) temp_str);
        mmi_asc_to_ucs2((PS8) temp_str, " byte");
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) temp_str);
        mmi_ucs2cat((S8*) (*info_buffer), (S8*) "\n");
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Out of mmi_brw_offline_pages_fill_page_info_buffer");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_options_page_info
 * DESCRIPTION
 *  Use to display the page information of the selected page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_options_page_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *info_buffer = NULL;
    U8 *gui_buffer = NULL;
    U16 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = {0};
    U16 buffer_size = 0;
    U16 url_len = 0;
    U16 title_len = 0;

    JC_BOOLEAN is_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_options_page_info");
    mmi_brw_offline_pages_get_file_name_at_index((S8*) file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists((S8*) file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }
    url_len = mmi_ucs2strlen((S8*) g_offline_pages_cntx.curr_page_info_p->pmURL);
    if (url_len > MMI_BRW_BKM_MAX_URL_LENGTH)
    {
        url_len = MMI_BRW_BKM_MAX_URL_LENGTH;
    }
    title_len = mmi_ucs2strlen((S8*) file_name) * ENCODING_LENGTH;
    if (title_len > MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH)
    {
        title_len = MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH;
    }
    buffer_size = 12 + title_len + 10 + (url_len * ENCODING_LENGTH) + 28 + 80 + 12 + 20;
    info_buffer = (U8*) jdd_MemAlloc((buffer_size), 1);
    if (NULL == info_buffer)
    {
        PRINT_INFORMATION("OFFLINE BROWSING: jdd_MemAlloc Fails");
        ASSERT(0);
    }
    memset(info_buffer, '\0', sizeof(info_buffer));
    mmi_brw_offline_pages_fill_page_info_buffer(&info_buffer);

    if (info_buffer != NULL)
    {
        EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_PAGE_INFO, NULL, mmi_brw_offline_pages_options_page_info, NULL);

        gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_PAGE_INFO);

        buffer_size = mmi_ucs2strlen((PS8) info_buffer);

        ShowCategory74Screen(
            STR_ID_BRW_OFFLINE_PAGES_OPTION_PAGE_INFO,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            info_buffer,
            buffer_size,
            gui_buffer);
        SetLeftSoftkeyFunction(mmi_brw_go_back_two_history, KEY_EVENT_UP);
        SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetKeyHandler(mmi_brw_go_back_two_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        if (NULL != info_buffer)
        {
            jdd_MemFree(info_buffer);
            info_buffer = NULL;
        }
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Out mmi_brw_offline_pages_options_page_info");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_create_ucs2_offline_pages_time_format_string
 * DESCRIPTION
 *  use to create the time string
 * PARAMETERS
 *  created_time            [IN]        
 *  ucs2_time_string        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_create_ucs2_offline_pages_time_format_string(FS_DOSDateTime *created_time, PS8 ucs2_time_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tzdiff = 0;
    U32 time_secs = 0;
    U32 local_time = 0;
    FLOAT tz = 0.0;
    MYTIME time = {0};
    applib_time_struct result = {0};
    applib_time_struct curr_gmt_time = {0};
    applib_time_struct time_difference = {0};
    UI_character_type temp_time_buffer[40] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_create_ucs2_offline_pages_time_format_string");
    curr_gmt_time.nYear = ((created_time->Year1980) + 1980);
    curr_gmt_time.nMonth = created_time->Month;
    curr_gmt_time.nDay = created_time->Day;
    curr_gmt_time.nHour = created_time->Hour;
    curr_gmt_time.nMin = created_time->Minute;
    curr_gmt_time.nSec = created_time->Second2;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "OFFLINE BROWSING : Hour received = ", curr_gmt_time.nHour);

    time_secs = (U32) applib_dt_mytime_2_utc_sec(&curr_gmt_time, MMI_TRUE);
    tz = mmi_dt_get_tz();
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "OFFLINE BROWSING : Time Zone Diff = ", tz);
    if (tz < 0)
    {
        time_difference = applib_conv_tz_to_mytime(tz * (-1));
        tzdiff = time_difference.nHour * 3600 + time_difference.nMin * 60 + time_difference.nSec;
        local_time = time_secs - tzdiff;
    }
    else
    {
        time_difference = applib_conv_tz_to_mytime(tz);
        tzdiff = time_difference.nHour * 3600 + time_difference.nMin * 60 + time_difference.nSec;
        local_time = time_secs + tzdiff;
    }

    applib_dt_utc_sec_2_mytime(local_time, &result, MMI_TRUE);

    time.nYear = result.nYear;
    time.nMonth = result.nMonth;
    time.nDay = result.nDay;
    time.nHour = result.nHour;
    time.nMin = result.nMin;
    time.nSec = result.nSec;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s(%d)", "OFFLINE BROWSING : Total Time = ", time.nHour);

    date_string(&time, temp_time_buffer, DT_IDLE_SCREEN);
    mmi_ucs2ncpy((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));
    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) " ", 1);
    time_string(&time, temp_time_buffer, DT_IDLE_SCREEN);
    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) temp_time_buffer, mmi_ucs2strlen((const S8*)temp_time_buffer));
    mmi_ucs2ncat((S8*) ucs2_time_string, (S8*) "\0", 1);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Out mmi_brw_create_ucs2_offline_pages_time_format_string");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_edit_screen_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_edit_screen_option(void) /* void EntryInLineMultilineEditorOption(void) */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;  /* Buffer holding history data */
    U16 list_of_item[3] = {0, };
    U16 num_of_items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_edit_screen_option");
    EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_EDIT_OPTION, NULL, mmi_brw_offline_pages_edit_screen_option, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_EDIT_OPTION);

    SetParentHandler(MENU_ID_BRW_OFFLINE_PAGES_EDIT_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    num_of_items = GetNumOfChild(MENU_ID_BRW_OFFLINE_PAGES_EDIT_OPTION);

    GetSequenceStringIds(MENU_ID_BRW_OFFLINE_PAGES_EDIT_OPTION, list_of_item);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_items,
        list_of_item,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_go_back_two_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_go_back_two_history(void)
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
 *  mmi_brw_offline_pages_get_file_name_at_index
 * DESCRIPTION
 *  Use to get filename at the given index
 * PARAMETERS
 *  file_name       [OUT]       
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_get_file_name_at_index(S8 *file_name, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cntr = 0;
    JC_OFFLINE_PAGE_FILE_LIST *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_name == NULL)
    {
        return;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_offline_pages_get_file_name_at_index");
    temp = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.offline_info->pFileList;
    while (temp != NULL)
    {
        if (cntr == index)
        {
            mmi_ucs2cpy((S8*) file_name, (S8*) temp->pfName);
            break;
        }
        cntr++;
        temp = (JC_OFFLINE_PAGE_FILE_LIST*) temp->pNext;
        if (cntr >= (U16) mmi_brw_offline_pages_get_max_num_of_pages())
        {
            break;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_offline_pages_get_file_name_at_index");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_show_popup
 * DESCRIPTION
 *  Use to show appropriate popup for the given return code
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_show_popup(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ret_code)
    {
        case JC_OK:
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, SUCCESS_TONE);
            break;
        case JC_ERR_FILE_INVALID_PATH:
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_INVALID_FILENAME),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_FILE_EXIST:
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_FILE_ALREADY_EXISTS),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_FILE_FULL:
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_FILE_SYSTEM_FULL),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_FILE_IS_READ_ONLY:
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_READ_ONLY),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                ERROR_TONE);
            break;
        case JC_ERR_MEMORY_ALLOCATION:
            mmi_brw_offline_pages_show_memory_not_enough_notifycation();
            break;
        default:
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_get_index_at_file_name
 * DESCRIPTION
 *  use to find the index of the given filename
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  index for the given filename
 *****************************************************************************/
U16 mmi_brw_offline_pages_get_index_at_file_name(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    JC_BOOLEAN is_exist = MMI_FALSE;
    JC_OFFLINE_PAGE_FILE_LIST *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_name == NULL)
    {
        return ((U16) mmi_brw_offline_pages_get_max_num_of_pages() + 1);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_offline_pages_get_index_at_file_name");
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        /*
         * DisplayPopup(
         * (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
         * IMG_GLOBAL_ERROR,
         * 1,
         * MMI_BRW_POPUP_TIME,
         * ERROR_TONE);
         * DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
         */
        return ((U16) mmi_brw_offline_pages_get_max_num_of_pages() + 1);
    }
    temp = (JC_OFFLINE_PAGE_FILE_LIST*) g_offline_pages_cntx.offline_info->pFileList;
    while (temp != NULL)
    {
        if (!mmi_ucs2cmp((S8*) temp->pfName, (S8*) file_name))
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                                 "OFFLINE BROWSING: Out mmi_brw_offline_pages_get_index_at_file_name");
            return index;
        }
        index++;
        temp = (JC_OFFLINE_PAGE_FILE_LIST*) temp->pNext;
        if (index >= (U16) mmi_brw_offline_pages_get_max_num_of_pages())
        {
            return index;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Out:Error mmi_brw_offline_pages_get_index_at_file_name");
    return ((U16) mmi_brw_offline_pages_get_max_num_of_pages() + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_get_title_from_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title       [OUT]       
 *  url         [IN]        
 * RETURNS
 *  TRUE if deleted otherwise FALSE
 *****************************************************************************/
void mmi_brw_offline_pages_get_title_from_url(S8 *title, S8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((url == NULL) || (*(url + 0) == '\0'))
    {
        return;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_get_title_from_url");
    if ((mmi_ucs2ncmp((PS8) url, (PS8) L"file://", 7) != 0))
    {
        mmi_ucs2ncpy(
            (S8*) title,
            (S8*) g_offline_pages_cntx.curr_page_info_p->pmURL,
            (MMI_BRW_BKM_MAX_TITLE_LENGTH - 1));
        return;
    }
    length = mmi_ucs2strlen(url) * ENCODING_LENGTH;
    if (length <= (MMI_BRW_BKM_MAX_TITLE_LENGTH - 1))
    {
        mmi_ucs2cpy((S8*) title, (S8*) url);
    }
    else
    {
        mmi_ucs2ncpy((S8*) title, (S8*) url, (MMI_BRW_BKM_MAX_TITLE_LENGTH - 1));
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_offline_pages_get_title_from_url");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_is_file_exists
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  TRUE if if file exists in OfflinePages Directory otherwise return False
 *****************************************************************************/
MMI_BOOL mmi_brw_offline_pages_is_file_exists(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_path[MMI_BRW_MAX_PATH_LENGTH] = {0};

    JDD_FSHANDLE fs_handle = NULL;
    JC_BOOLEAN is_exist = MMI_FALSE;
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_is_file_exists");
    mmi_brw_saved_pages_get_absolute_path_ucs2(ucs2_path);
    mmi_ucs2cat((S8*) ucs2_path, (S8*) file_name);
    ret_code = jdd_FSInitialize(&fs_handle);
    if (ret_code == JC_OK)
    {
        is_exist = jdd_FSIsFileExist(fs_handle, (JC_CHAR*) ucs2_path);
        jdd_FSDeinitialize(fs_handle);
        temp_activated_task_id = jdd_MemGetActiveModuleID();
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserIsValidOfflinePage(g_mmi_brw_pbrowser_ctxt, (U16*) ucs2_path, &is_exist);
        jdd_MemSetActiveModuleID(temp_activated_task_id);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_offline_pages_is_file_exists");
        if (ret_code == JC_OK)
        {
            return is_exist;
        }
        else
        {
            temp_activated_task_id = jdd_MemGetActiveModuleID();
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
            jdi_BrowserDeleteOfflinePage(g_mmi_brw_pbrowser_ctxt, g_offline_pages_cntx.selected_file_index);
            jdd_MemSetActiveModuleID(temp_activated_task_id);
            DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_allocate_curr_page_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if Success otherwise FALSE
 *****************************************************************************/
JC_RETCODE mmi_brw_offline_pages_allocate_curr_page_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_offline_pages_allocate_curr_page_info");
    mmi_brw_offline_pages_free_curr_page_info();
    g_offline_pages_cntx.curr_page_info_p = (JC_OFFLINE_PAGE_INFO*) jdd_MemAlloc(1, sizeof(JC_OFFLINE_PAGE_INFO));
    if (g_offline_pages_cntx.curr_page_info_p == NULL)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }
    g_offline_pages_cntx.curr_page_info_p->pmTitle = NULL;
    g_offline_pages_cntx.curr_page_info_p->pmURL = NULL;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_offline_pages_allocate_curr_page_info");
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_free_curr_page_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_free_curr_page_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_offline_pages_cntx.curr_page_info_p == NULL)
    {
        return;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_free_curr_page_info");
    if (g_offline_pages_cntx.curr_page_info_p->pmTitle != NULL)
    {
        jdd_MemFree(g_offline_pages_cntx.curr_page_info_p->pmTitle);
        g_offline_pages_cntx.curr_page_info_p->pmTitle = NULL;
    }
    if (g_offline_pages_cntx.curr_page_info_p->pmURL != NULL)
    {
        jdd_MemFree(g_offline_pages_cntx.curr_page_info_p->pmURL);
        g_offline_pages_cntx.curr_page_info_p->pmURL = NULL;
    }
    if (g_offline_pages_cntx.curr_page_info_p != NULL)
    {
        jdd_MemFree(g_offline_pages_cntx.curr_page_info_p);
        g_offline_pages_cntx.curr_page_info_p = NULL;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out of mmi_brw_offline_pages_free_curr_page_info");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_fill_curr_page_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if deleted otherwise FALSE
 *****************************************************************************/
void mmi_brw_offline_pages_fill_curr_page_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_fill_curr_page_info");
    if (g_offline_pages_cntx.curr_page_info_p != NULL)
    {
        if (g_offline_pages_cntx.curr_page_info_p->pmTitle != NULL)
        {
            jdd_MemFree(g_offline_pages_cntx.curr_page_info_p->pmTitle);
            g_offline_pages_cntx.curr_page_info_p->pmTitle = NULL;
        }
        if (g_offline_pages_cntx.curr_page_info_p->pmURL != NULL)
        {
            jdd_MemFree(g_offline_pages_cntx.curr_page_info_p->pmURL);
            g_offline_pages_cntx.curr_page_info_p->pmURL = NULL;
        }
    }
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    ret_code = jdi_BrowserGetOfflinePageInfo(
                g_mmi_brw_pbrowser_ctxt,
                (JC_UINT32) g_offline_pages_cntx.selected_file_index,
                (JC_OFFLINE_PAGE_INFO*) g_offline_pages_cntx.curr_page_info_p);
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (JC_OK != ret_code)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, NULL);
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out of mmi_brw_offline_pages_fill_curr_page_info");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_deinit_offline_pages_app
 * DESCRIPTION
 *  Use to DeInitialize Offline Pages
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_deinit_offline_pages_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_offline_pages_cntx.operation_type != E_JC_OFFLINE_PAGE_OPER_NIL)
    {
        mmi_brw_offline_pages_cancel_operation();
    }
    mmi_brw_offline_pages_resume_auto_refresh_timer();
    mmi_brw_offline_pages_free_curr_page_info();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_show_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_show_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_string[20] = { '\0', };
    /* U16 str_id = 0; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_pages_show_progress_screen");
    mmi_brw_offline_pages_get_progress_screen_process_string(ucs2_string);
    /*
     * if(g_offline_pages_cntx.operation_type == E_JC_OFFLINE_PAGE_OPER_SAVE)
     * {
     * str_id = STR_GLOBAL_SAVING;
     * }
     * else
     * {
     * str_id = STR_ID_BRW_OFFLINE_PAGES_DELETING;
     * }
     */

    EntryNewScreen(SCR_ID_BRW_OFFLINE_PAGES_PROGRESS_SCREEN, NULL, mmi_brw_offline_pages_show_progress_screen, NULL);
    ShowCategory66Screen(
        /* str_id, */ STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(SERVICES_WAP_MENU_ID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) ucs2_string,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_UP, KEY_REPEAT);

    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_REPEAT);

    SetRightSoftkeyFunction(mmi_brw_offline_pages_cancel_operation, KEY_EVENT_UP);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_offline_pages_show_progress_screen");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_status_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  eOpType         [IN]        
 *  ret_code        [IN]        
 * RETURNS
 *  JC_OK.
 *****************************************************************************/
JC_RETCODE mmi_brw_offline_status_callback(E_JC_OFFLINE_PAGE_OPER_TYPE eOpType, JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Inside mmi_brw_offline_status_callback");
    g_offline_pages_cntx.operation_type = eOpType;
    if (!isInCall())
    {
        /*
         * if (JC_ERR_FILE_FULL == ret_code)
         * {
         * mmi_brw_saved_pages_get_absolute_path_ucs2((S8*) ucs2_path);
         * mmi_ucs2cat((S8*) ucs2_path, (S8*) g_offline_pages_cntx.file_name);
         * ret_code = jdd_FSInitialize(&fs_handle);
         * if(ret_code == JC_OK)
         * {
         * jdd_FSDelete(fs_handle, (JC_CHAR*) ucs2_path);
         * jdd_FSDeinitialize(fs_handle);
         * }
         * }
         */
        mmi_brw_offline_pages_show_popup(ret_code);
        DeleteScreenIfPresent(SCR_ID_BRW_OFFLINE_PAGES_PROGRESS_SCREEN);
    }
    else
    {
        if (JC_ERR_FILE_FULL == ret_code)
        {
            /*
             * mmi_brw_saved_pages_get_absolute_path_ucs2((S8*) ucs2_path);
             * mmi_ucs2cat((S8*) ucs2_path, (S8*) g_offline_pages_cntx.file_name);
             * ret_code = jdd_FSInitialize(&fs_handle);
             * if(ret_code == JC_OK)
             * {
             * jdd_FSDelete(fs_handle, (JC_CHAR*) ucs2_path);
             * jdd_FSDeinitialize(fs_handle);
             * }
             */
            DisplayPopup((PU8) GetString(STR_ID_BRW_FILE_SYSTEM_FULL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, NULL);
        }
        else if (JC_ERR_FILE_IS_READ_ONLY == ret_code)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_READ_ONLY),
                IMG_GLOBAL_ERROR,
                1,
                MMI_BRW_POPUP_TIME,
                NULL);
        }
        else if (JC_OK == ret_code)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, MMI_BRW_POPUP_TIME, NULL);
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, NULL);
        }
        DeleteScreenIfPresent(SCR_ID_BRW_OFFLINE_PAGES_PROGRESS_SCREEN);
    }
    mmi_brw_offline_pages_resume_auto_refresh_timer();
    g_offline_pages_cntx.operation_type = E_JC_OFFLINE_PAGE_OPER_NIL;
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Out mmi_brw_offline_status_callback");
    return JC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_cancel_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_cancel_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    mmi_brw_offline_pages_resume_auto_refresh_timer();
    switch (g_offline_pages_cntx.operation_type)
    {
        case E_JC_OFFLINE_PAGE_OPER_SAVE:
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
            ret_code = jdi_BrowserCancelSaveOfflinePage(g_mmi_brw_pbrowser_ctxt);
            jdd_MemSetActiveModuleID(temp_activated_task_id);
            if (JC_OK == ret_code)
            {
                if (IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))
                {
                    GoBackHistory();
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_BRW_RENDERED_PAGE_OPTIONS))
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        MMI_BRW_POPUP_TIME,
                        ERROR_TONE);
                    DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
                }
            }
            break;
        case E_JC_OFFLINE_PAGE_OPER_DELETEALL:
            jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
            ret_code = jdi_BrowserCancelDeleteAllOfflinePages(g_mmi_brw_pbrowser_ctxt);
            jdd_MemSetActiveModuleID(temp_activated_task_id);
            if (JC_OK == ret_code)
            {
                if (IsScreenPresent(SCR_ID_BRW_OFFLINE_PAGES_LIST))
                {
                    GoBackHistory();
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_BRW_OFFLINE_PAGES_LIST))
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_ERROR),
                        IMG_GLOBAL_ERROR,
                        1,
                        MMI_BRW_POPUP_TIME,
                        ERROR_TONE);
                    DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
                }
            }
            break;
        case E_JC_OFFLINE_PAGE_OPER_SYNC:
        case E_JC_OFFLINE_PAGE_OPER_NIL:
            break;
        default:
            ASSERT(0);
            break;
    }
    g_offline_pages_cntx.operation_type = E_JC_OFFLINE_PAGE_OPER_NIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_init_offline_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  the address of the offline_info.
 *****************************************************************************/
JC_OFFLINE_PAGE_FILE_CONTEXT **mmi_brw_init_offline_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (&g_offline_pages_cntx.offline_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_set_operation_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_set_operation_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_offline_pages_cntx.operation_type = E_JC_OFFLINE_PAGE_OPER_NIL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_go_back_history_with_no_replace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_go_back_history_with_no_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_delete_extension(g_offline_pages_cntx.file_name);
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_get_number_of_pages_at_location
 * DESCRIPTION
 *  Use to get count of total pages at a particular location
 * PARAMETERS
 *  number_of_pages     [OUT]       
 *  location            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_get_number_of_pages_at_location(U16 *number_of_pages, E_JC_OFFLINE_PAGE_MEM_TYPE location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: Inside mmi_brw_offline_pages_get_number_of_pages_at_location");
    if (location == E_JC_OFFLINE_PAGE_MEM_CARD)
    {
        *number_of_pages = g_offline_pages_cntx.offline_info->uiCardCurrCount;
    }
    else if (location == E_JC_OFFLINE_PAGE_MEM_PHONE)
    {
        *number_of_pages = g_offline_pages_cntx.offline_info->uiPhoneCurrCount;
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "OFFLINE BROWSING: Undefined Location ");
        ASSERT(0);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                         "OFFLINE BROWSING: OUT mmi_brw_offline_pages_get_number_of_pages_at_location");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_get_progress_screen_process_string
 * DESCRIPTION
 *  Use to get the proper message in progress screen
 * PARAMETERS
 *  string      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_get_progress_screen_process_string(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_offline_pages_cntx.operation_type)
    {
        case E_JC_OFFLINE_PAGE_OPER_SAVE:
            mmi_ucs2cpy((S8*) string, (S8*) get_string(STR_GLOBAL_SAVING));
            break;
        case E_JC_OFFLINE_PAGE_OPER_DELETEALL:
            mmi_ucs2cpy(string, (S8*) get_string(STR_ID_BRW_OFFLINE_PAGES_DELETING));
            break;
        case E_JC_OFFLINE_PAGE_OPER_SYNC:
            ASSERT(0);
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_add_to_bookmark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_exist = MMI_FALSE;
    U32 length = 0;
    S8 file_name[MMI_BRW_OFFLINE_PAGES_FILENAME_LENGTH] = { '\0', };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("OFFLINE BROWSING: Inside mmi_brw_offline_pages_add_to_bookmark");
    mmi_brw_offline_pages_get_file_name_at_index(file_name, g_offline_pages_cntx.selected_file_index);
    is_exist = mmi_brw_offline_pages_is_file_exists(file_name);
    if (!is_exist)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_BRW_OFFLINE_PAGES_FILE_NOT_FOUND),
            IMG_GLOBAL_ERROR,
            1,
            MMI_BRW_POPUP_TIME,
            ERROR_TONE);
        DeleteUptoScrID(SCR_ID_BRW_OFFLINE_PAGES_LIST);
        return;
    }
    length = mmi_ucs2strlen((PS8) g_offline_pages_cntx.curr_page_info_p->pmURL);
    mmi_brw_read_bookmark_from_nvram();
    if (length >= MMI_BRW_BKM_MAX_URL_LENGTH)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_URL_LEN_EXCEED), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
    else if (g_mmi_brw_cntx.total_bookmark_items >= MMI_BRW_MAX_BOOKMARKS)
    {
        DisplayPopup((PU8) GetString(STR_ID_BRW_BOOKMARK_FULL), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);

        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        if (g_offline_pages_cntx.curr_page_info_p->pmTitle != NULL)
        {
            mmi_ucs2ncpy(
                (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
                (S8*) g_offline_pages_cntx.curr_page_info_p->pmTitle,
                MMI_BRW_BKM_MAX_TITLE_LENGTH);
        }
        else
        {
            mmi_brw_offline_pages_get_title_from_url(
                (S8*) g_mmi_brw_cntx.brw_bkm_selected_title,
                (S8*) g_offline_pages_cntx.curr_page_info_p->pmURL);
        }
        mmi_ucs2ncpy(
            (S8*) g_mmi_brw_cntx.brw_current_url,
            (S8*) g_offline_pages_cntx.curr_page_info_p->pmURL,
            MMI_BRW_BKM_MAX_URL_LENGTH);
        /* Set edit flag */
        g_mmi_brw_cntx.edit_flag = BRW_STATUS_ADD_BKM_FROM_OFFLINE_PAGES;

        mmi_brw_entry_add_bookmark_screen_for_all();
    }
    PRINT_INFORMATION("OFFLINE BROWSING: Out mmi_brw_offline_pages_add_to_bookmark");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_OK if Successfully Sync, otherwise return error code
 *****************************************************************************/
JC_RETCODE mmi_brw_offline_pages_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        return ret_code;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    if (fmgr_is_msdc_present())
    {
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserSyncOfflinePages(g_mmi_brw_pbrowser_ctxt, E_JC_OFFLINE_PAGE_MEM_ALL);
    }
    else
    {
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserSyncOfflinePages(g_mmi_brw_pbrowser_ctxt, E_JC_OFFLINE_PAGE_MEM_PHONE);
    }
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    g_offline_pages_cntx.need_sync = MMI_FALSE;
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_need_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  True if need sync otherwise false;
 *****************************************************************************/
JC_BOOLEAN mmi_brw_offline_pages_need_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_offline_pages_cntx.need_sync;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_reset_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_reset_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_offline_pages_cntx.need_sync = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_brw_offline_set_operation_type();
    if (mmi_brw_offline_pages_need_sync())
    {
        ret_code = mmi_brw_offline_pages_sync();
    }
    /* TO-DO : Remove when implement location */
    g_offline_pages_cntx.selected_loc = E_JC_OFFLINE_PAGE_MEM_PHONE;
    if (JC_OK != ret_code)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_get_root_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  directory name for the offline pages in the drives.
 *****************************************************************************/
S8 *mmi_brw_offline_pages_get_root_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *dir = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dir = (S8*) jdd_BrowserConfigGetOfflinePageDIR();
    return dir;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_get_max_num_of_pages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  max number of offline pages that can be store at a time.
 *****************************************************************************/
S32 mmi_brw_offline_pages_get_max_num_of_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_offline_pages = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_offline_pages = jdd_BrowserConfigGetMaxOfflinePageSize();
    return max_offline_pages;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_resume_auto_refresh_timer
 * DESCRIPTION
 *  Resumes the Auto refresh timer if suspended before save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_resume_auto_refresh_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_offline_pages_cntx.auto_refresh_timer == MMI_TRUE)
    {
        temp_activated_task_id = jdd_MemGetActiveModuleID();
        jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
        ret_code = jdi_BrowserPostSaveOfflinePage(g_mmi_brw_pbrowser_ctxt);
        jdd_MemSetActiveModuleID(temp_activated_task_id);
        if (ret_code != JC_OK)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        }
    }
    g_offline_pages_cntx.auto_refresh_timer = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_suspend_auto_refresh_timer
 * DESCRIPTION
 *  Resumes the Auto refresh timer if suspended before save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_suspend_auto_refresh_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    ETaskID temp_activated_task_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_activated_task_id = jdd_MemGetActiveModuleID();
    jdd_MemSetActiveModuleID(E_TASK_BROWSER_CORE);
    ret_code = jdi_BrowserPreSaveOfflinePage(g_mmi_brw_pbrowser_ctxt);
    jdd_MemSetActiveModuleID(temp_activated_task_id);
    if (ret_code != JC_OK)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_BRW_POPUP_TIME, ERROR_TONE);
        return;
    }
    g_offline_pages_cntx.auto_refresh_timer = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_show_memory_not_enough_notifycation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_show_memory_not_enough_notifycation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_BRW_OFFLINE_PAGES_SHOW_NOTIFICATION,
        NULL,
        mmi_brw_offline_pages_show_memory_not_enough_notifycation,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BRW_OFFLINE_PAGES_SHOW_NOTIFICATION);

    ShowCategory151Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        0,
        0,
        (PU8) GetString(STR_ID_BRW_PUSH_MEMORY_NOT_ENOUGH),
        (PU8) GetImage(IMG_GLOBAL_INFO),
        guiBuffer);

    /* clear the volume key handler */
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_UP, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_UP, KEY_REPEAT);

    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_UP);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_VOL_DOWN, KEY_REPEAT);

    SetLeftSoftkeyFunction(mmi_brw_entry_exit_menu, KEY_EVENT_UP);

}

#ifdef MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_get_offline_pages_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  current selected location.
 *****************************************************************************/
S32 mmi_brw_get_offline_pages_location(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_offline_pages_cntx.selected_loc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_offline_pages_set_curr_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  location        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_offline_pages_set_curr_location(S32 location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_offline_pages_cntx.selected_loc = location;
}

#endif /* MMI_BRW_OFFLINE_PAGES_SELECT_LOCATION */ 

/********************************************************************************************
 ********************************---END OF CODE---*******************************************
 ********************************************************************************************/

#endif /* __MMI_JATAAYU_BRW_OFFLINE_PAGES__ */ 
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ 
#endif /* _MMI_JBROWSERMMIOFFLINEPAGES_C */ 

