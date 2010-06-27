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
 * ThemeArchiver.c
 *
 * Project:
 * --------
 * DLT
 *
 * Description:
 * ------------
 * This file defines all message sequence between WAP & Theme Archiver.
 *
 * Author:
 * -------
 * -------
 * -------
 *
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_THEME_ARCHIVER_C
#define _MMI_THEME_ARCHIVER_C

#include "MMI_features.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "Globaldefs.h"
#include "GlobalScrEnum.h"
#include "TimerEvents.h"
#include "FrameworkGprot.h"         
#include "FrameworkProt.h"   
#include "ProtocolEvents.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_stopwatch.h"
#include "FunAndGamesDefs.h"
#include "CommonScreens.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "FileMgr.h"
#include "SettingProfile.h"
#include "WapResDef.h"
#include "xml_def.h"
#include "Calculator.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "CustMenuRes.h"


/***************************************************************************** 
 * Global data
 *****************************************************************************/

const S8 *g_ta_theme_descriptor_tags_p[MAX_DESCRIPTOR_ELEMENTS_NUM] = 
{
    {"type"},
    {"objectURI"},
    {"size"},
    {"ddversion"},
    {"installNotifyURI"},
    {"Name"},
    {"lcdht"},
    {"lcdwidth"}
};

const S8 *g_tad_acceptable_theme_filetypes_p[MAX_ACCEPTABLE_THEME_FILE_TYPE] = 
{
    {"mtk/med.thm"},
    {"theme"}
};

ta_da_context_struct g_ta_da_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_da_handle_theme_content
 * DESCRIPTION
 *  Handles theme download through WAP
 * PARAMETERS
 *  filename_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_handle_theme_content(S8 *filename_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 nHistory = 0;
    FS_HANDLE fs_hdle;
    U32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_DOWNLOAD_THM_STORAGE;
    currHistory.entryFuncPtr = mmi_ta_entry_select_storage_screen;
    memset((void*)currHistory.guiBuffer, 0, sizeof(currHistory.guiBuffer));
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);

    DisplayPopup(
        (PU8) GetString(STR_THEME_FILE_DOWNLOADED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);

    AddHistory(currHistory);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_p)
    {
        mmi_ucs2cpy((S8*) g_ta_da_context.file_name_with_path, (S8*) filename_p);
    }
    fs_hdle = FS_Open((U16*)filename_p, FS_READ_ONLY);
    FS_GetFileSize(fs_hdle, &file_size);
    FS_Close(fs_hdle);
    g_ta_da_context.da_file_size = (FLOAT)file_size;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ta_receive_theme_file
 * DESCRIPTION
 *  Handles theme download through DLA
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        
 *  mime_subtype            [IN]        
 *  action                  [IN]        
 *  file_path               [IN]        
 *  url                     [IN]        
 *  mime_type_string        [IN]        
 * RETURNS
 *  NONE
 *****************************************************************************/
void mmi_ta_receive_theme_file(
        S32	session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 file_path,
        PS8 url,
        PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ta_handle_theme_content((S8*)file_path);
    return;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_theme_file_version_compatibility
 * DESCRIPTION
 *  validates Theme version.
 * PARAMETERS
 *  theme_version       [IN]        
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
U16 mmi_ta_check_theme_file_version_compatibility(FLOAT theme_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    FLOAT *VersionTable_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VersionTable_p = (FLOAT*) mmi_tm_get_theme_version_table();

    for (i = 0; i < MAX_SUPPORTED_VERSION_NUM; i++)
    {
        if (VersionTable_p[i] == theme_version)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_theme_file_lcd_dim_compatibiltiy
 * DESCRIPTION
 *  validates LCD dimensions.
 * PARAMETERS
 *  lcd_width       [IN]        
 *  lcd_height      [IN]        
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
U16 mmi_ta_check_theme_file_lcd_dim_compatibiltiy(U32 lcd_width, U32 lcd_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_height == LCD_HEIGHT && lcd_width == LCD_WIDTH)
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
 *  mmi_ta_check_theme_type_compatibility
 * DESCRIPTION
 *  validates Theme type.
 * PARAMETERS
 *  input_type_p        [?]     
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
U16 mmi_ta_check_theme_type_compatibility(S8 *input_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ACCEPTABLE_THEME_FILE_TYPE; i++)
    {
        if (strcmp(input_type_p, g_tad_acceptable_theme_filetypes_p[i]) == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_entry_select_storage_screen
 * DESCRIPTION
 *  Show select storage screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_entry_select_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer_p;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U16 nDispAttribute;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_DOWNLOAD_THM_STORAGE, NULL, mmi_ta_entry_select_storage_screen, NULL);

    guiBuffer_p = GetCurrGuiBuffer(SCR_ID_DOWNLOAD_THM_STORAGE);

   if (FS_DRIVE_NOT_FOUND == FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE))
    {
        mmi_frm_hide_menu_item(MENU_STORAGE_THEMES_CARD);
    }

    nNumofItem = GetNumOfChild_Ext(MENU_DOWNLOAD_THEMES_STORAGE);

    nDispAttribute = GetDispAttributeOfItem(MENU_DOWNLOAD_THEMES_STORAGE);

    GetSequenceStringIds_Ext(MENU_DOWNLOAD_THEMES_STORAGE, nStrItemList);

    SetParentHandler(MENU_DOWNLOAD_THEMES_STORAGE);

    RegisterHighlightHandler(mmi_ta_select_dlt_storage_type);

    ShowCategory11Screen(
        STR_SELECT_STORAGE_TITLE_ID,
        IMG_SELECT_STORAGE_TITLE_ID,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        0,
        guiBuffer_p);

    SetLeftSoftkeyFunction(mmi_ta_set_dlt_storage_type, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_ta_exit_dlt_storage_type, KEY_EVENT_UP);

    SetKeyHandler(DisplayIdleScreen, KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ta_exit_dlt_storage_type
 * DESCRIPTION
 *  CallBack function for highlight movement on Select Storage screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_exit_dlt_storage_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ta_delete_intermediate_dlt_files((U16*) g_ta_da_context.file_name_with_path);
    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_select_dlt_storage_type
 * DESCRIPTION
 *  CallBack function for highlight movement on Select Storage screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_select_dlt_storage_type(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ta_da_context.current_hilite_storage_type = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_set_dlt_storage_type
 * DESCRIPTION
 *  Validate the selected storage type and set storage location for
 *  theme download content.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_set_dlt_storage_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_RetDrv = 0;
    U64 disk_free_space;
    U64 file_size;
    FS_DiskInfo disk_info;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_ta_da_context.current_hilite_storage_type)
    {
        case 0:
            fs_RetDrv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
            g_ta_da_context.curr_storage_type = THEME_TYPE_DOWNLOADED_PHONE;
            break;

        case 1:
            fs_RetDrv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
            g_ta_da_context.curr_storage_type = THEME_TYPE_DOWNLOADED_CARD;
            break;

        default:
            break;
    }

    if (fs_RetDrv >= 0)
    {
        S8 buf[6];
        S32 create_result;

        sprintf(buf, "%c:\\", (U8) fs_RetDrv);
        memset(subMenuData, 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
        mmi_asc_to_ucs2((S8*) subMenuData, (S8*) buf);

        file_handle = FS_Open((kal_uint16*) subMenuData, FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle >= 0)
        {
            FS_Close(file_handle);
            /* drive is avaiable */

            FS_GetDiskInfo((PU16) subMenuData, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

            disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

            file_size = (U64) (g_ta_da_context.da_file_size * 1024);

            if (disk_free_space >= file_size)
            {

                mmi_ucs2cat((PS8) subMenuData, (PS8) FMGR_DEFAULT_FOLDER_THEMES);
                file_handle = FS_Open((kal_uint16*) subMenuData, FS_OPEN_DIR | FS_READ_ONLY);

                /* path already exist */
                if (file_handle >= 0)
                {
                    FS_Close(file_handle);
                    create_result = 0;
                }
                else
                {
                    create_result = FS_CreateDir((PU16) subMenuData);
                }

                if (create_result == FS_WRITE_PROTECTION)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DLT_WRITE_PROTECTED),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }
                else if (create_result == FS_DISK_FULL)
                {
                    DisplayPopup(
                        (PU8) GetString(STR_ID_DLT_DISK_FULL),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }
                else if (create_result == FS_ROOT_DIR_FULL)
                {
                    DisplayPopup(
                        (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }                
                else
                {
                    mmi_ta_save_theme_content((PS8) subMenuData);
                }
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_DLT_UNSUFFICIENT_MEMORY),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
            }

        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_DLT_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
    }
    else
    {
        /* get drive error  */
        DisplayPopup(
            (PU8) GetString(STR_ID_DLT_NO_MEMORY_CARD),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ta_save_theme_content
 * DESCRIPTION
 *  Saves the Theme Content in the right folder
 * PARAMETERS
 *  filepath_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_save_theme_content(S8 *filepath_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_file_name_p;
    S8 temp_file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_file_name_p = mmi_ta_parse_url_extract_file_name((S8*) g_ta_da_context.file_name_with_path);
    mmi_ucs2ncpy(temp_file_name, temp_file_name_p, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
    mmi_ta_check_if_file_alrdy_exist_in_fm((S8*) filepath_p, (S8*) temp_file_name);
    mmi_ucs2cat((S8*) subMenuData, (S8*) temp_file_name);
    FS_Move(
        (const WCHAR*)g_ta_da_context.file_name_with_path,
        (const WCHAR*)subMenuData,
        FS_MOVE_KILL | FS_MOVE_OVERWRITE,
        NULL, NULL, 0);
    mmi_ucs2cpy((S8*) g_ta_da_context.file_name_with_path, (S8*) subMenuData);
    mmi_ta_theme_download_complete_notification();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ta_theme_download_complete_notification
 * DESCRIPTION
 *  show download complete notification..
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_theme_download_complete_notification(void)
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
        get_string(STR_ID_THEME_DOWNLOAD_COMPLETE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    DeleteScreenIfPresent(SCR_ID_DOWNLOAD_THM_STORAGE);
    SetLeftSoftkeyFunction(mmi_ta_set_dlt_as_activated, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_set_dlt_as_activated
 * DESCRIPTION
 *  Apply downloaded theme as currrent theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_set_dlt_as_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int status;
    S8 *temp_file_name_p;
    S8 temp_file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This fn call will create history for the previous screen 
       and the current screen will not be created in history */
    EntryNewScreen(0, NULL, NULL, NULL);

    ShowCategory66Screen(
        STR_SCR3001_THEMES_CAPTION,
        0,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_DLT_THM_PROGRESS),
        IMG_THEME_ACTIVATION,
        NULL);

    DeleteScreenIfPresent(SCR_ID_DOWNLOAD_THM_STORAGE);

    temp_file_name_p = mmi_ta_parse_url_extract_file_name((S8*) g_ta_da_context.file_name_with_path);
    mmi_ucs2ncpy(temp_file_name, temp_file_name_p, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);

    status = mmi_tm_activate_theme_from_fmgr(g_ta_da_context.curr_storage_type, (PU8) temp_file_name, MMI_FALSE);

    mmi_tm_handle_theme_activation_error_status((U16) status);  /* removed warning: by shariq */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_handle_abort_req
 * DESCRIPTION
 *  handle download abort request from JAS
 * PARAMETERS
 *  inMsg_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_handle_abort_req(void *inMsg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For future use */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_parse_url_extract_file_name
 * DESCRIPTION
 *  extract file name from URL for non-oma
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  true if successfully parsed otherwise false
 *****************************************************************************/
PS8 mmi_ta_parse_url_extract_file_name(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_ucs2strlen(path) * 2;
    i = length - 1;

    while (i > 0)
    {
        if (path[i - 1] == '\\' && path[i] == 0 && (i != length - ENCODING_LENGTH))
        {
            break;
        }
        i -= 2;
    }

    if (i < 0)
    {
        return NULL;
    }

    return &path[i + 1];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_delete_intermediate_dlt_files
 * DESCRIPTION
 *  To delete intermediate downloaded files.
 * PARAMETERS
 *  file_path_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_delete_intermediate_dlt_files(U16 *file_path_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if file exists. Delete it. */
    fd = FS_Open((WCHAR*) file_path_p, FS_READ_WRITE);
    if (fd >= 0)
    {
        FS_Close(fd);
        FS_Delete((WCHAR*) file_path_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_if_file_alrdy_exist_in_fm
 * DESCRIPTION
 *  Check if file Already exists in File manager.
 * PARAMETERS
 *  file_path       [IN]        
 *  file_name       [IN]        
 *  PS8 file name and file path(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_check_if_file_alrdy_exist_in_fm(PS8 file_path, PS8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    U8 file_count = 0;
    S8 tempStr[6];
    S8 ucs2_dup_file_rename[12];
    U8 len;
    S8 file_ext_buf[(FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
    S8 *file_ext_p;
    S8 temp_file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_file_name, 0, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy(temp_file_name, file_name, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

    while (file_count < 65535)
    {
        memset(hintData, 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
        mmi_ucs2ncpy((PS8) hintData, file_path, FMGR_PATH_BUFFER_SIZE - ENCODING_LENGTH);
        mmi_ucs2ncat((PS8) hintData, temp_file_name, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
        file_count++;
        fd = FS_Open((WCHAR*) hintData, FS_READ_ONLY);
        if (fd >= 0)
        {
            FS_Close(fd);
            sprintf(tempStr, "%d", file_count);
            mmi_asc_to_ucs2(ucs2_dup_file_rename, tempStr);

            memset(temp_file_name, 0, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy(temp_file_name, file_name, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

            file_ext_p = (S8*) mmi_fmgr_extract_ext_file_name(temp_file_name);
            mmi_ucs2cpy(file_ext_buf, file_ext_p);
            mmi_ta_thmgr_hide_ext_name(temp_file_name);

            len = FMGR_MAX_INPUT_FILE_LEN - mmi_ucs2strlen(temp_file_name);

            if (len >= mmi_ucs2strlen(ucs2_dup_file_rename))
            {
                mmi_ucs2cat(temp_file_name, ucs2_dup_file_rename);
            }
            else
            {
                memset(temp_file_name + (FMGR_MAX_INPUT_FILE_LEN - 6) * ENCODING_LENGTH, 0, 12);
                mmi_asc_to_ucs2(tempStr, "~");
                mmi_ucs2cat(temp_file_name, tempStr);
                mmi_ucs2cat(temp_file_name, ucs2_dup_file_rename);
            }
            mmi_asc_to_ucs2(tempStr, ".");
            mmi_ucs2cat(temp_file_name, tempStr);
            mmi_ucs2cat(temp_file_name, file_ext_buf);
        }
        else
        {
            mmi_ucs2cpy(file_name, temp_file_name);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_thmgr_hide_ext_name
 * DESCRIPTION
 *  hide extension file name
 * PARAMETERS
 *  file_name_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_thmgr_hide_ext_name(S8 *file_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find ext name - by finding "." */
    S32 str_len;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen(file_name_p);
    index = (str_len - 1) * ENCODING_LENGTH;

    while (index > 0)
    {
        if (mmi_ucs2ncmp((PS8) & file_name_p[index], (PS8) L".", 1) == 0)
        {
            file_name_p[index] = '\0';
            file_name_p[index + 1] = '\0';
            break;
        }

        file_name_p[index] = '\0';
        file_name_p[index + 1] = '\0';
        index -= 2;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ta_parse_lcd_size
 * DESCRIPTION
 *  It parses the lcd height and lcd width string given in dd file
 * PARAMETERS
 *  lcd_size_string_p       [IN]        
 *  lcd_height_p            [IN]        
 *  lcd_width_p             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_parse_lcd_size(const S8 *lcd_size_string_p, S8 *lcd_height_p, S8 *lcd_width_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count1 = 0, count2 = 0;
    S8 lcd_size_param[MAX_LCD_STRING_SIZE];
    S8 temp_ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lcd_size_param, 0, MAX_LCD_STRING_SIZE);

    while (*lcd_size_string_p != '\0')
    {
        temp_ch = (S8) * lcd_size_string_p;

        if (temp_ch != ':' && temp_ch != (S8) ';' && temp_ch != ' ' && temp_ch != '\t')
        {
            lcd_size_param[count1] = temp_ch;
            ++count1;
        }
        else if (*lcd_size_string_p == ':')
        {
            lcd_size_param[count1] = 0;
            count1 = 0;
            count2 = 0;

            while (temp_ch == ':' || temp_ch == ';' || temp_ch == ' ' || temp_ch == '\t')
            {
                ++(lcd_size_string_p);
                temp_ch = (S8) * lcd_size_string_p;
            }

            while (temp_ch != '\0' && temp_ch != ':' && temp_ch != ';' && temp_ch != ' ' && temp_ch != '\t')
            {
                if (!strcmp(lcd_size_param, g_ta_theme_descriptor_tags_p[6]))
                {
                    lcd_height_p[count2] = temp_ch;
                    ++count2;
                }
                else if (!strcmp(lcd_size_param, g_ta_theme_descriptor_tags_p[7]))
                {
                    lcd_width_p[count2] = temp_ch;
                    ++count2;
                }
                ++(lcd_size_string_p);
                temp_ch = (S8) * lcd_size_string_p;
            }
            if (!strcmp(lcd_size_param, g_ta_theme_descriptor_tags_p[6]))
            {
                lcd_height_p[count2] = 0;
            }
            else if (!strcmp(lcd_size_param, g_ta_theme_descriptor_tags_p[7]))
            {
                lcd_width_p[count2] = 0;
            }
        }

        ++(lcd_size_string_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_da_oma_install_check_hdlr
 * DESCRIPTION
 *  Its a OMA download callback function and called by download agent for validating the
 *  theme descriptor file
 * PARAMETERS
 *  dd_file     [IN]        
 * RETURNS
 *  TRUE                   if descriptor file contains valid info
 *  FALSE                  if descriptor file contains in-valid info
 *****************************************************************************/
BOOL mmi_ta_da_oma_install_check_hdlr(mmi_da_oma_dd_struct *dd_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* FLOAT theme_version; */
    U16 err_status;
    S8 lcd_height_p[MAX_LCD_STRING_SIZE];
    S8 lcd_width_p[MAX_LCD_STRING_SIZE];

    memset(lcd_height_p, 0, MAX_LCD_STRING_SIZE);
    memset(lcd_width_p, 0, MAX_LCD_STRING_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Checking theme type compatibility */
    if (!mmi_ta_check_theme_type_compatibility(dd_file->type[0]))
    {
        return FALSE;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Checking theme type compatibility */
    mmi_ta_parse_lcd_size(dd_file->installParam, (S8*) lcd_height_p, (S8*) lcd_width_p);
    err_status = mmi_ta_check_theme_file_lcd_dim_compatibiltiy(
                    (U32) atof((const char*)lcd_width_p),
                    (U32) atof((const char*)lcd_height_p));
    if (!err_status)
    {
        return FALSE;
    }

    return TRUE;
}

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ // #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#endif /* _MMI_THEME_ARCHIVER_C */ // #ifndef _MMI_THEME_ARCHIVER_C

