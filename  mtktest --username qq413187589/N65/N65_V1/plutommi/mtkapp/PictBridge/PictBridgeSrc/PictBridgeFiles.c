/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeFiles.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__


#include "CommonScreens.h"
#include "ProfileGprots.h"
#include "SettingProfile.h"
#include "FileManagerGProt.h"
#include "FileManagerDef.h"

#ifdef __FS_SORT_SUPPORT__
#endif /* __FS_SORT_SUPPORT__ */

#include "wgui_tab_bars.h"

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeGProt.h"
#include "PictBridgeStruct.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif


/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_setting_struct g_pict_bridge_setting;


#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_convert_size_to_unicode
 * DESCRIPTION
 *  Convert file size to unicode string
 * PARAMETERS
 *  file_size       [IN]
 *  str_buffer      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_convert_size_to_unicode(U32 file_size, U8 *str_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_size > 1024 * 1024)
    {
        sprintf(temp, "%d.%dM", (U16) ((file_size / 1024) / 1024), (U16) (((file_size / 1024) % 1024) / 103));
    }
    else if (file_size > 1024)
    {
        sprintf(temp, "%d.%dK", (U16) (file_size / 1024), (U16) ((file_size % 1024) / 103));
    }
    else    /* less than 1024 */
    {
        sprintf(temp, "%dB", (U16) (file_size));
    }

    mmi_asc_to_ucs2((S8*) str_buffer, temp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dynamic_get_file_description
 * DESCRIPTION
 *  Rerturn file description to category 426
 * PARAMETERS
 *  start_index     [IN]
 *  menu_data       [OUT]
 *  data_size       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_pict_dynamic_get_file_description(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_DOSDirEntry file_info;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S8 filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    S32 i = 0;
    U8 j;
    gui_iconlist_menu_item *item = menu_data;

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
    S32 fs_ret;
#endif /* __FS_SORT_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) L"*.jpg");

#ifdef __FS_SORT_SUPPORT__
    if (g_pict_bridge_context.multi_file_xreset)
    {
        fs_ret = FS_XFindReset(
                     (U16*) path,
                     NULL,
                     0,
                     0,
                     0,
                     FS_FILE_TYPE | g_pict_bridge_context.multi_file_sort,
                     1, /* RTF_INFINITE */
                     &seq);

        for (i = 0; ; i++)
        {
            fs_handle = FS_XFindStart(
                              (U16*) path,
                              &file_info,
                              (U16*) filename,
                              FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                              start_index + i,
                              &seq,
                              FS_FIND_DEFAULT);

            if (fs_handle < 0)
            {
                if ( i < data_size)
                {
                    /* some files are deleted */
                    for (j = i; j < data_size; j++)
                    {
                        mmi_ucs2cpy((S8*) item->item_list[0], GetString(FMGR_FS_FILE_NOT_FOUND_TEXT));
                        mmi_ucs2cpy((S8*) item->item_list[1], (S8*) L"");

                        item++;
                    }
                    i = data_size - 1;
                }
                break; /* no more files */
            }

            mmi_ucs2cpy((S8*) item->item_list[0], filename);
            mmi_pict_convert_size_to_unicode(file_info.FileSize, (U8*) item->item_list[1]);

            item++;

            if (i == data_size - 1)
            {
                break;
            }
        }

        FS_XFindClose(&seq);

        return i + 1;
    }
    else
#endif /* __FS_SORT_SUPPORT__ */
    {
        if ((fs_handle = FS_FindFirstN((U16*) path, NULL, 0, 0, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH, start_index, FS_FIND_DEFAULT)) >= 0)
        {
            do
            {
                mmi_ucs2cpy((S8*) item->item_list[0], filename);
                mmi_pict_convert_size_to_unicode(file_info.FileSize, (U8*) item->item_list[1]);

                item++;
                i++;

                if (i == data_size)
                {
                    break;
                }

            } while (FS_FindNextN(fs_handle, NULL, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH, FS_FIND_DEFAULT) == FS_NO_ERROR);

            FS_FindClose(fs_handle);
        }

        return i;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_dynamic_get_file_image
 * DESCRIPTION
 *  Rerturn image file to category 426
 * PARAMETERS
 *  index           [IN]
 *  image_filename  [OUT]
 *  max_size        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_dynamic_get_file_image(S32 index, U8 *image_filename, S32 max_size, U16 *default_image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_DOSDirEntry file_info;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S8 filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
    S32 fs_ret;
#endif /* __FS_SORT_SUPPORT__ */

#ifdef __DRM_SUPPORT__
    FS_HANDLE drm_handle;
    MMI_BOOL rtn = MMI_TRUE;
#endif /* __DRM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_ucs2cpy((S8*)image_filename, (S8*) g_pict_bridge_context.multi_file_path[index]);

    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) L"*.jpg");

#ifdef __FS_SORT_SUPPORT__
    if (g_pict_bridge_context.multi_file_xreset)
    {
        fs_ret = FS_XFindReset(
                     (U16*) path,
                     NULL,
                     0,
                     0,
                     0,
                     FS_FILE_TYPE | g_pict_bridge_context.multi_file_sort,
                     1, /* RTF_INFINITE */
                     &seq);

        fs_handle = FS_XFindStart(
                        (U16*) path,
                        &file_info,
                        (U16*) filename,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        index,
                        &seq,
                        FS_FIND_DEFAULT);

        FS_XFindClose(&seq);
    }
    else
#endif /* __FS_SORT_SUPPORT__ */
    {
        fs_handle = FS_FindFirstN((U16*) path, NULL, 0, 0, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH, index, FS_FIND_DEFAULT);
        FS_FindClose(fs_handle);
    }

    if (fs_handle < FS_NO_ERROR)
    {
        /* some files are deleted */
        mmi_ucs2cpy((S8*) image_filename, (S8*) L"");
    }
    else
    {
        mmi_ucs2cpy((S8*) image_filename, (S8*) g_pict_bridge_context.printing_filepath);
        mmi_fmgr_remove_last_dir((S8*) image_filename);
        mmi_ucs2cat((S8*) image_filename, filename);
    }

#ifdef __DRM_SUPPORT__
    drm_handle = DRM_open_file((PU16) image_filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    if (drm_handle > FS_NO_ERROR)
    {
        rtn = DRM_validate_permission(drm_handle, NULL, DRM_PERMISSION_DISPLAY);
        DRM_close_file(drm_handle);
    }
    else
    {
        rtn = MMI_FALSE;
    }

    if (!rtn)
    {
        /* DRM prohibited to display */
        mmi_ucs2cpy((S8*) image_filename, (S8*) L"");
    }
#endif /* __DRM_SUPPORT__ */

    *default_image_id = IMG_ID_FMGR_FILE_TYPE_JPG;
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_drm_file_check
 * DESCRIPTION
 *  Check if the selected file is DRM protected
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_drm_file_check(U16 *display_string, U16 *display_image, U8 *display_tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE drm_handle;
    FS_HANDLE fs_handle;
    FS_DOSDirEntry file_info;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S8 filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
    S32 fs_ret;
#endif /* __FS_SORT_SUPPORT__ */

    MMI_BOOL rtn = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) L"*.jpg");

#ifdef __FS_SORT_SUPPORT__
    if (g_pict_bridge_context.multi_file_xreset)
    {
        fs_ret = FS_XFindReset(
                     (U16*) path,
                     NULL,
                     0,
                     0,
                     0,
                     FS_FILE_TYPE | g_pict_bridge_context.multi_file_sort,
                     1, /* RTF_INFINITE */
                     &seq);

        fs_handle = FS_XFindStart(
                        (U16*) path,
                        &file_info,
                        (U16*) filename,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        g_pict_bridge_context.multi_file_index,
                        &seq,
                        FS_FIND_DEFAULT);

        FS_XFindClose(&seq);
    }
    else
#endif /* __FS_SORT_SUPPORT__ */
    {
        fs_handle = FS_FindFirstN((U16*) path, NULL, 0, 0, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH, g_pict_bridge_context.multi_file_index, FS_FIND_DEFAULT);
        FS_FindClose(fs_handle);
    }

    mmi_ucs2cpy((S8*) path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir((S8*) path);
    mmi_ucs2cat((S8*) path, filename);

    drm_handle = DRM_open_file((PU16) path, FS_READ_ONLY, DRM_PERMISSION_PRINT);
    if (drm_handle > FS_NO_ERROR)
    {
        rtn = DRM_validate_permission(drm_handle, NULL, DRM_PERMISSION_PRINT);
        DRM_close_file(drm_handle);
        *display_string = STR_GLOBAL_DRM_PROHIBITED;
        *display_image = IMG_GLOBAL_WARNING;
        *display_tone = (U8) WARNING_TONE;
    }
    else
    {
        rtn = MMI_FALSE;
        *display_string = GetFileSystemErrorString(drm_handle);
        *display_image = IMG_GLOBAL_ERROR;
        *display_tone = (U8) ERROR_TONE;
    }

    return rtn;
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_jpg_file_check
 * DESCRIPTION
 *  Check if the selected file is JPG compliant
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_jpg_file_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_DOSDirEntry file_info;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S8 filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
    S32 fs_ret;
#endif /* __FS_SORT_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) L"*.jpg");

#ifdef __FS_SORT_SUPPORT__
    if (g_pict_bridge_context.multi_file_xreset)
    {
        fs_ret = FS_XFindReset(
                     (U16*) path,
                     NULL,
                     0,
                     0,
                     0,
                     FS_FILE_TYPE | g_pict_bridge_context.multi_file_sort,
                     1, /* RTF_INFINITE */
                     &seq);

        fs_handle = FS_XFindStart(
                        (U16*) path,
                        &file_info,
                        (U16*) filename,
                        FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                        g_pict_bridge_context.multi_file_index,
                        &seq,
                        FS_FIND_DEFAULT);

        FS_XFindClose(&seq);
    }
    else
#endif /* __FS_SORT_SUPPORT__ */
    {
        fs_handle = FS_FindFirstN((U16*) path, NULL, 0, 0, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH, g_pict_bridge_context.multi_file_index, FS_FIND_DEFAULT);
        FS_FindClose(fs_handle);
    }

    mmi_ucs2cpy((S8*) path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir((S8*) path);
    mmi_ucs2cat((S8*) path, filename);

    return mmi_pict_jpg_format_validation((S8*) path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_refresh_category
 * DESCRIPTION
 *  Left softkey handler to select/unselect the file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_refresh_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 prohibit_access_info[128], prohibit_access_num[16];
    U16 display_string = 0, display_image = 0;
    U8 display_tone = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.multi_file_value[g_pict_bridge_context.multi_file_index])
    {
        g_pict_bridge_context.multi_file_value[g_pict_bridge_context.multi_file_index] = 0;
        g_pict_bridge_context.multi_file_select--;
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
    else
    {
        if (g_pict_bridge_context.multi_file_select == PICT_MAX_MULTI_FILES)
        {
            mmi_ucs2cpy(prohibit_access_info, GetString(STR_ID_PICT_MAX_FILES));
            kal_wsprintf((kal_wchar*) prohibit_access_num, "%d", PICT_MAX_MULTI_FILES);
            mmi_ucs2cat(prohibit_access_info, prohibit_access_num);

            DisplayPopup(
                (U8*) prohibit_access_info,
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }

    #ifdef __DRM_SUPPORT__
        if (!mmi_pict_drm_file_check(&display_string, &display_image, &display_tone))
        {
            DisplayPopup(
                (U8*) GetString(display_string),
                display_image,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                display_tone);
            return;
        }
    #endif /* __DRM_SUPPORT__ */

        if (!mmi_pict_jpg_file_check())
        {
            /* invalid file */
            DisplayPopup(
                (U8*) GetString(STR_ID_INVALID_JPG_FILE),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }

        g_pict_bridge_context.multi_file_value[g_pict_bridge_context.multi_file_index] = 1;
        g_pict_bridge_context.multi_file_select++;
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }

    if (g_pict_bridge_context.multi_file_select == 0)
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_pict_go_back_from_file_selection, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        SetRightSoftkeyFunction(mmi_pict_entry_file_selection_done, KEY_EVENT_UP);
    }

    RefreshCategory426Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_refresh_highlight_hdlr
 * DESCRIPTION
 *  Multi-file selection catefory refresh handler
 * PARAMETERS
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_refresh_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.multi_file_index = (U16) index;

    if (g_pict_bridge_context.multi_file_value[g_pict_bridge_context.multi_file_index])
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_multi_file_selection
 * DESCRIPTION
 *  Entry function for multi-file selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_multi_file_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_pict_is_dps_device_present())
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PICT_PRINTER_REMOVED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    if (g_pict_bridge_context.multi_file_cache == NULL)
    {
        g_pict_bridge_context.multi_file_cache = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_PICT_BRIDGE, UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * 2);
        if (g_pict_bridge_context.multi_file_cache == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_PICT_BRIDGE,
                0,
                UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * 2,
                mmi_pict_entry_multi_file_selection);
            return;
        }
        PRINT_INFORMATION("PictBridge: APP mem allocated");
    }

    EntryNewScreen(SCR_ID_PICT_FILES, NULL, mmi_pict_entry_multi_file_selection, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_PICT_FILES);

    RegisterHighlightHandler(mmi_pict_refresh_highlight_hdlr);
    SetDelScrnIDCallbackHandler(SCR_ID_PICT_FILES, (HistoryDelCBPtr) mmi_pict_delete_multi_file_category_callback);    

    ShowCategory426Screen(
        STR_GLOBAL_SELECT,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OPTIONS,        
        IMG_GLOBAL_OPTIONS,
        (g_pict_bridge_context.multi_file_select == 0) ? STR_GLOBAL_BACK : STR_GLOBAL_DONE,
        (g_pict_bridge_context.multi_file_select == 0) ? IMG_GLOBAL_BACK : 0,
        CHECKBOX_ON_IMAGE_ID, 
        CHECKBOX_OFF_IMAGE_ID,
        g_pict_bridge_context.multi_file_total, //PICT_MAX_MULTI_FILES,
        mmi_pict_dynamic_get_file_description,
        mmi_pict_dynamic_get_file_image,        
        g_pict_bridge_context.multi_file_value,
        g_pict_bridge_context.multi_file_cache,
        UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * 2,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_pict_refresh_category, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_pict_entry_file_selection_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_retrieve_files_from_current_dir
 * DESCRIPTION
 *  Entry function to retrieve all files in the directory which is the same as the selected file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_retrieve_files_from_current_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_DOSDirEntry file_info;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S8 filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    S8 *selected_file_name;

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
    S32 fs_ret;
    S32 i;
    S16 error;
    U8 temp;
#endif /* __FS_SORT_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) L"*.jpg");

    selected_file_name = mmi_fmgr_extract_file_name((S8*) g_pict_bridge_context.printing_filepath);
    g_pict_bridge_context.multi_file_total = 0;

#ifdef __FS_SORT_SUPPORT__
    ReadValue(NVRAM_EF_FMGR_SORT_OPTION_LID, &temp, DS_BYTE, &error);
    g_pict_bridge_context.multi_file_sort = (temp == 0xff) ? FS_NO_SORT : (temp << 5);

    fs_ret = FS_XFindReset(
                 (U16*) path,
                 NULL,
                 0,
                 0,
                 0,
                 FS_FILE_TYPE | g_pict_bridge_context.multi_file_sort,
                 1, /* RTF_INFINITE */
                 &seq);

    g_pict_bridge_context.multi_file_xreset = (fs_ret < FS_NO_ERROR) ? 0 : 1;

    if (fs_ret >= FS_NO_ERROR)
    {
        for (i = 0; ; i++)
        {
            fs_handle = FS_XFindStart(
                              (U16*) path,
                              &file_info,
                              (U16*) filename,
                              FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                              i,
                              &seq,
                              FS_FIND_DEFAULT);

            if (fs_handle < 0)
            {
                break; /* no more files */
            }

            if (mmi_ucs2cmp(selected_file_name, filename) == 0)
            {
                g_pict_bridge_context.multi_file_index = (U16) g_pict_bridge_context.multi_file_total;
            }

            g_pict_bridge_context.multi_file_total++;
        }

        FS_XFindClose(&seq);
    }
    else
#endif /* __FS_SORT_SUPPORT__ */
    {
    if ((fs_handle = FS_FindFirst((U16*) path, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH)) >= 0)
        {
            /* Loop through all file with specific extension. */
            do
            {
                if (mmi_ucs2cmp(selected_file_name, filename) == 0)
                {
                    g_pict_bridge_context.multi_file_index = (U16) g_pict_bridge_context.multi_file_total;
                }

                g_pict_bridge_context.multi_file_total++;
            } while (FS_FindNext(fs_handle, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH) == FS_NO_ERROR);

            FS_FindClose(fs_handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_cat426_reset_selected_file
 * DESCRIPTION
 *  Reset the selected file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_cat426_reset_selected_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.multi_file_value != NULL)
    {
        OslMfree(g_pict_bridge_context.multi_file_value);
    }

    g_pict_bridge_context.multi_file_value = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_cat426_mark_selected_file
 * DESCRIPTION
 *  Mark the selected file from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_cat426_mark_selected_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_cat426_reset_selected_file();

    if (g_pict_bridge_context.multi_file_total > 2048)
    {
        g_pict_bridge_context.multi_file_total = 2048;
    }
    g_pict_bridge_context.multi_file_value = OslMalloc(g_pict_bridge_context.multi_file_total);
    memset(g_pict_bridge_context.multi_file_value, 0, g_pict_bridge_context.multi_file_total);

    if (g_pict_bridge_context.multi_file_total > 2048)
    {
        g_pict_bridge_context.multi_file_total = 2048;
        g_pict_bridge_context.multi_file_select = 0;
    }
    else
    {
        g_pict_bridge_context.multi_file_select = 1;
        g_pict_bridge_context.multi_file_value[g_pict_bridge_context.multi_file_index] = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_file_selection_done
 * DESCRIPTION
 *  Entry function for file selection completion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_file_selection_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_DOSDirEntry file_info;
    S8 path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    S8 filename[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    S32 i = 0, j = 0;

#ifdef __FS_SORT_SUPPORT__
    U32 seq;
    S32 fs_ret;
#endif /* __FS_SORT_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(path);
    mmi_ucs2cat(path, (S8*) L"*.jpg");

#ifdef __FS_SORT_SUPPORT__
    if (g_pict_bridge_context.multi_file_xreset)
    {
        fs_ret = FS_XFindReset(
                     (U16*) path,
                     NULL,
                     0,
                     0,
                     0,
                     FS_FILE_TYPE | g_pict_bridge_context.multi_file_sort,
                     1, /* RTF_INFINITE */
                     &seq);

        if (fs_ret < FS_NO_ERROR)
        {
            DisplayPopup(
                (PU8) GetString(FMGR_FS_FILE_NOT_FOUND_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            DeleteScreenIfPresent(SCR_ID_PICT_FILES);
            return;
        }

        for (i = 0; ; i++)
        {
            fs_handle = FS_XFindStart(
                              (U16*) path,
                              &file_info,
                              (U16*) filename,
                              FMGR_MAX_FILE_LEN * ENCODING_LENGTH,
                              i,
                              &seq,
                              FS_FIND_DEFAULT);

            if (fs_handle < 0)
            {
                break; /* no more files */
            }

            if (g_pict_bridge_context.multi_file_value[i])
            {
                mmi_ucs2cpy((S8*) g_pict_bridge_context.multi_file_path[j], filename);
                g_pict_bridge_context.multi_file_size[j] = file_info.FileSize;
                mmi_pict_convert_date_to_unicode((const FS_DOSDirEntry *) &file_info, g_pict_bridge_context.multi_file_date[j]);
                j++;
            }
        }

        FS_XFindClose(&seq);
    }
    else
#endif /* __FS_SORT_SUPPORT__ */
    {
        if ((fs_handle = FS_FindFirst((U16*) path, 0, 0, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH)) >= 0)
        {
            /* Loop through all file with specific extension. */
            do
            {
                if (g_pict_bridge_context.multi_file_value[i])
                {
                    mmi_ucs2cpy((S8*) g_pict_bridge_context.multi_file_path[j], filename);
                    g_pict_bridge_context.multi_file_size[j] = file_info.FileSize;
                    mmi_pict_convert_date_to_unicode((const FS_DOSDirEntry *) &file_info, g_pict_bridge_context.multi_file_date[j]);
                    j++;
                }

                i++;
            } while (FS_FindNext(fs_handle, &file_info, (U16*) filename, FMGR_MAX_FILE_LEN * ENCODING_LENGTH) == FS_NO_ERROR);

            FS_FindClose(fs_handle);
        }
    }

    if (j < g_pict_bridge_context.multi_file_select)
    {
        DisplayPopup(
            (PU8) GetString(FMGR_FS_FILE_NOT_FOUND_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
             WARNING_TONE);
        DeleteScreenIfPresent(SCR_ID_PICT_FILES);
        return;
    }

    mmi_pict_entry_print_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_app_mem_free
 * DESCRIPTION
 *  Free APP-shared memory allocated for file selection category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_app_mem_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.multi_file_cache)
    {
        applib_mem_ap_free((void*) g_pict_bridge_context.multi_file_cache);
        g_pict_bridge_context.multi_file_cache = NULL;
        PRINT_INFORMATION("PictBridge: APP mem freed");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_app_mem_stop_callback
 * DESCRIPTION
 *  APP-shared memory delete callback for file selection category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_app_mem_free();
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_PICT_BRIDGE, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_delete_multi_file_category_callback
 * DESCRIPTION
 *  Delete screen callback for file selection category
 * PARAMETERS
 *  ptr             [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_pict_delete_multi_file_category_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_app_mem_free();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_go_back_from_file_selection
 * DESCRIPTION
 *  Entry function for go back from file selection category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_go_back_from_file_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_app_mem_free();
    GoBackHistory();
}


#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

