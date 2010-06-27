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
 *    PictBridgeMain.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_PICT_BRIDGE_SUPPORT__


#include "CommonScreens.h"
#include "ProfileGprots.h"
#include "SettingProfile.h"
#include "CallManagementGprot.h"
#include "FileManagerGProt.h"

#include "wgui_status_icons.h"

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeGProt.h"
#include "PictBridgeStruct.h"

extern void mmi_frm_add_history_before_cm_marker(U16 scrn_id, FuncPtr func_ptr);


/*
 * Global Variable
 */
extern pict_bridge_setting_struct g_pict_bridge_setting;


/*
 * Local Variable
 */
pict_bridge_context_struct g_pict_bridge_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_init
 * DESCRIPTION
 *  PictBridge initialization function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_pict_bridge_setting, 0, sizeof(pict_bridge_setting_struct));
    memset(&g_pict_bridge_context, 0, sizeof(pict_bridge_context_struct));

#ifdef __MTK_TARGET__
    mmi_pict_protocol_init();
#else
    mmi_pict_xml_init();
#endif

#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_PICT_BRIDGE,
        STR_ID_PICT_TITLE,
        0,
        mmi_pict_app_mem_stop_callback);
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_error_connection_to_pc
 * DESCRIPTION
 *  Entry function for indication of connection to PC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_error_connection_to_pc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_PICT_CONNECT_TO_PC),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_host_reset_popop
 * DESCRIPTION
 *  Entry function for indication of USB host reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_host_reset_popop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_PICT_USB_RESET),
        IMG_GLOBAL_ERROR,
        1,
        1000,
        (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_preview
 * DESCRIPTION
 *  Entry function for print preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_PREVIEW, NULL, mmi_pict_entry_print_preview, NULL);

    guiBuffer = GetCurrGuiBuffer (SCR_ID_PICT_PREVIEW);

    if (g_pict_bridge_setting.layout == 1) /* 2-up layout */
    {
        image_id = IMG_ID_PICT_LAYOUT2;
    }
    else if (g_pict_bridge_setting.layout == 2) /* 4-up layout */
    {
        image_id = IMG_ID_PICT_LAYOUT4;
    }
    else /* 1-up layout */
    {
        image_id = IMG_ID_PICT_LAYOUT1;
    }

    ShowCategory132Screen(
        (U8*) GetString(STR_ID_PICT_PREVIEW), /* title string */
        mmi_pict_return_title_icon(),         /* image ID of title icon */
        STR_ID_PICT_TITLE,                    /* string ID of LSK */
        0,                                    /* image ID of LSK */
        STR_GLOBAL_CANCEL,                    /* string ID of RSK */
        0,                                    /* image ID of RSK */
        image_id,                             /* image ID, displayed at the center */
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_now, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_now
 * DESCRIPTION
 *  Entry function for printing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_now(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_context.printing == PICT_PRINTING_NONE && g_pict_bridge_context.dps_status == PICT_DPS_BUSY)
    {
        DisplayPopup(
            (U8*) GetString(STR_ID_PICT_PRINTER_BUSY),
            IMG_GLOBAL_PROGRESS,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_PICT_PRINTING, NULL, mmi_pict_entry_print_now, NULL);

    if (mmi_ucs2strlen((PS8) g_pict_bridge_context.printing_percentage) == 0)
    {
        mmi_ucs2cpy((PS8) g_pict_bridge_context.printing_percentage, GetString(STR_ID_PICT_PRINTING));
    }
    else
    {
        //...
    }

    ShowCategory66Screen(
        STR_ID_PICT_TITLE,
        mmi_pict_return_title_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_pict_bridge_context.printing_percentage,
        IMG_ID_PICT_PRINTING,
        NULL);

    SetRightSoftkeyFunction(mmi_pict_entry_print_query, KEY_EVENT_UP);
    SetKeyHandler(mmi_pict_entry_print_query, KEY_END, KEY_EVENT_DOWN);

    ShowStatusIcon(STATUS_ICON_PRINT); /* show print icon */
    UpdateStatusIcons();

    if (g_pict_bridge_context.printing == PICT_PRINTING_NONE)
    {
        g_pict_bridge_context.printing = PICT_PRINTING_NOW;
#ifdef __MTK_TARGET__
        g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_start_job;
        mmi_pict_start_job_req();
        mmi_pict_send_dps_operation_req();
#else
        g_pict_bridge_context.xml_operation_cmd = g_pict_bridge_context.xml_modis_buffer;
        mmi_pict_prepare_xml_start_job();
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_update_print_progression
 * DESCRIPTION
 *  Updating for printing progression
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_update_print_progression(const char *percentage_ansii)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 p_cnt[(PICT_PROGRESS_LEN + 1)]; /* 001 */
    S8 t_cnt[(PICT_PROGRESS_LEN + 1)]; /* 002 */
    S8 *p1;
    S8 *p2;
    S32 v1, v2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen((PS8) percentage_ansii) > PICT_PROGRESS_LEN)
    {
        return; /* syntax error */
    }

    p1 = (S8*) percentage_ansii;

    p2 = (S8*) percentage_ansii;
    do
    {
        p2++; 
    } while(*p2 != '/');
    p2++;

    v1 = atoi(p1);
    v2 = atoi(p2);

    gui_itoa(v1, (U16*) p_cnt, 10);
    gui_itoa(v2, (U16*) t_cnt, 10);

    mmi_ucs2cpy((PS8) g_pict_bridge_context.printing_percentage, (PS8) GetString(STR_ID_PICT_PRINTING));
    mmi_ucs2cat((PS8) g_pict_bridge_context.printing_percentage, (PS8) L" ");

    mmi_ucs2cat((PS8) g_pict_bridge_context.printing_percentage, p_cnt);
    mmi_ucs2cat((PS8) g_pict_bridge_context.printing_percentage, (PS8) L"/");
    mmi_ucs2cat((PS8) g_pict_bridge_context.printing_percentage, t_cnt);

    if (GetActiveScreenId() == SCR_ID_PICT_PRINTING)
    {
        cat66_update_progress_string();
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_abort
 * DESCRIPTION
 *  Entry function for printing job abortion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
#ifdef __MTK_TARGET__
    g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_abort_job;
    mmi_pict_send_dps_operation_req();
#else
    mmi_pict_entry_print_done(MMI_TRUE, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_continue
 * DESCRIPTION
 *  Entry function for printing job resume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    HideStatusIcon(STATUS_ICON_PRINT_FAIL); /* hide print error icon */
    UpdateStatusIcons();
#ifdef __MTK_TARGET__
    g_pict_bridge_context.next_operation_request = mmi_pict_prepare_xml_continue_job;
    mmi_pict_send_dps_operation_req();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_background_go_back
 * DESCRIPTION
 *  Entry function for background print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_background_go_back(void)
{
    mmi_pict_delete_print_screens();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_query
 * DESCRIPTION
 *  Query function for print abortion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_QUERY, NULL, mmi_pict_entry_print_query, NULL);

    ShowCategory2Screen(
        STR_ID_PICT_TITLE,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_YES, /* LSK: yes to abort */
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,  /* RSK: no to go back and keep background sync */
        IMG_GLOBAL_NO,
        STR_ID_PICT_QUERY,
        NULL);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_abort, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_pict_entry_background_go_back, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_error_information
 * DESCRIPTION
 *  Entry function for print error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_error_information(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_PICT_ERROR, NULL, mmi_pict_entry_print_error_information, NULL);

    ShowCategory165Screen(
        STR_ID_PICT_CONTINUE,
        0,
        STR_GLOBAL_CANCEL,
        0,
        get_string(g_pict_bridge_context.error_string_id),
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_continue, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_pict_entry_print_abort, KEY_EVENT_UP);

    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_error
 * DESCRIPTION
 *  Entry function for print error screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_popup_print_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HideStatusIcon(STATUS_ICON_PRINT); /* hide print icon */
    ShowStatusIcon(STATUS_ICON_PRINT_FAIL); /* show print error icon */
    UpdateStatusIcons();

    DisplayPopup(
        (U8*) GetString(STR_ID_PICT_ERROR),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) ERROR_TONE);

    /* prevent from continuous error indication from the printer */
    DeleteScreenIfPresent(SCR_ID_PICT_ERROR);

    if (IsScreenPresent(SCR_ID_PICT_PRINTING))
    {
        if (isInCall())
        {
            mmi_frm_add_history_before_cm_marker(SCR_ID_PICT_ERROR, mmi_pict_entry_print_error_information);
        }
        else
        {
            GenericExitScreen(SCR_ID_PICT_ERROR, mmi_pict_entry_print_error_information);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_go_back_from_print_error
 * DESCRIPTION
 *  Go back from print error screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_go_back_from_print_error(void)
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
 *  mmi_pict_entry_print_done
 * DESCRIPTION
 *  Entry function for printing job completion
 * PARAMETERS
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_done(pBOOL result, U16 error_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    mmi_pict_close_job_req();
#endif

    if (result)
    {
        DisplayPopup(
            (U8*) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (U8*) GetString(error_string),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }

    mmi_pict_delete_print_screens();

    HideStatusIcon(STATUS_ICON_PRINT); /* hide print icon */
    HideStatusIcon(STATUS_ICON_PRINT_FAIL); /* hide print error icon */
    UpdateStatusIcons();

    g_pict_bridge_context.printing = PICT_PRINTING_NONE;
    memset(&g_pict_bridge_context.printing_percentage[0], 0, 32 * ENCODING_LENGTH);

#ifdef __DRM_SUPPORT__
#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    memset(&g_pict_bridge_context.multi_file_consume[0], 0, PICT_MAX_MULTI_FILES);
#else
    g_pict_bridge_context.drm_consume_cnt = 0;
#endif
#endif /*__DRM_SUPPORT__ */
}


#ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_printer_connected
 * DESCRIPTION
 *  Entry function for printer connected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_printer_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_PICT_PRINTER_CONNECTED),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_popup_idle_state_error
 * DESCRIPTION
 *  Entry function for error reported in idle state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_popup_idle_state_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (U8*) GetString(STR_ID_PICT_ERROR),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) ERROR_TONE);
}
#endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_delete_print_screens
 * DESCRIPTION
 *  Delete all printing related screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_delete_print_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    mmi_pict_cat426_reset_selected_file();
    DeleteScreenIfPresent(SCR_ID_PICT_FILES);
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */

    DeleteScreenIfPresent(SCR_ID_PICT_CROPPING);
    DeleteScreenIfPresent(SCR_ID_PICT_CROPPING_PHASE1);
    DeleteScreenIfPresent(SCR_ID_PICT_CROPPING_PHASE2);

    DeleteScreenIfPresent(SCR_ID_PICT_SETTINGS);
    DeleteScreenIfPresent(SCR_ID_PICT_PREVIEW);
    DeleteScreenIfPresent(SCR_ID_PICT_PRINTING);
    DeleteScreenIfPresent(SCR_ID_PICT_ERROR);
    DeleteScreenIfPresent(SCR_ID_PICT_QUERY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_return_title_icon
 * DESCRIPTION
 *  Title icon of PictBridge related screens
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_pict_return_title_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* IMG_ID_PICT_TITLE is not populated so return the file manager root icon */
    return GetRootTitleIcon(MAIN_MENU_FILE_MNGR_MENUID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_convert_date_to_unicode
 * DESCRIPTION
 *  Convert file date to unicode string
 * PARAMETERS
 *  fs_entry        [IN]
 *  str_buffer      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_convert_date_to_unicode(const FS_DOSDirEntry *fs_entry, U8 *str_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* year */
    gui_itoa(fs_entry->DateTime.Year1980 + 1980, (U16*) temp, 10);
    mmi_ucs2cpy((S8*) str_buffer, temp);
    mmi_ucs2cat((S8*) str_buffer, (S8*) L"/");
    /* month */
    gui_itoa(fs_entry->DateTime.Month, (U16*) temp, 10);
    mmi_ucs2cat((S8*) str_buffer, temp);
    mmi_ucs2cat((S8*) str_buffer, (S8*) L"/");
    /* day */
    gui_itoa(fs_entry->DateTime.Day, (U16*) temp, 10);
    mmi_ucs2cat((S8*) str_buffer, temp);
}


#ifndef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_file_date
 * DESCRIPTION
 *  Get file date for single file print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_get_file_date(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_FileInfo fs_fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
    FS_GetFileInfo(fs_handle, &fs_fileinfo);
    mmi_pict_convert_date_to_unicode(fs_fileinfo.DirEntry, g_pict_bridge_context.printing_filedate);
    FS_Close(fs_handle);
}
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_file_dimension
 * DESCRIPTION
 *  Get file dimension for single file print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_get_file_dimension(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    S8 image_file_path[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
    mmi_ucs2cpy(image_file_path, (S8*) g_pict_bridge_context.printing_filepath);
    mmi_fmgr_remove_last_dir(image_file_path);
    mmi_ucs2cat(image_file_path, (S8*) g_pict_bridge_context.multi_file_path[0]);
    gdi_image_get_dimension_file(image_file_path, &g_pict_bridge_context.image_width, &g_pict_bridge_context.image_height);
#else /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
    gdi_image_get_dimension_file((S8*) g_pict_bridge_context.printing_filepath, &g_pict_bridge_context.image_width, &g_pict_bridge_context.image_height);
#endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_jpg_format_validation
 * DESCRIPTION
 *  Validate the JPG file is accepted to print
 * PARAMETERS
 *  file            [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_jpg_format_validation(S8 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check image header */
    if (gdi_image_get_type_from_file((PS8) file) != GDI_IMAGE_TYPE_JPG_FILE)
    {
        return MMI_FALSE;
    }

    /* Check image resolution */
    gdi_ret = gdi_image_get_dimension_file((PS8) file, (S32*) & width, (S32*) & height);
    if (gdi_ret < GDI_SUCCEED || width <= 0 || height <= 0)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_print_file_forward_from_fmgr
 * DESCRIPTION
 *  File manager callback function for JPG file selection to print
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_print_file_forward_from_fmgr(void *path, FMGR_FILTER *filter, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_pict_is_dps_device_present())
    {
        /* printer is not present */
        DisplayPopup(
            (U8*) GetString(STR_ID_PICT_PRINTER_REMOVED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }

    if (g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_configure_print_service ||
        g_pict_bridge_context.next_operation_request == mmi_pict_prepare_xml_get_capability)
    {
        /* waiting for initialization with the printer */
        DisplayPopup(
            (U8*) GetString(STR_ID_PICT_CONFIGURATION),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    if (g_pict_bridge_context.printing == PICT_PRINTING_NOW)
    {
        mmi_pict_entry_print_now();
    }
    else if (g_pict_bridge_context.printing == PICT_PRINTING_ERROR)
    {
        mmi_pict_entry_print_error_information();
    }
    else
    {
        mmi_ucs2cpy((S8*) g_pict_bridge_context.printing_filepath, (S8*) path);

        if (!mmi_pict_jpg_format_validation((S8*) g_pict_bridge_context.printing_filepath))
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

    #ifdef __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__
        mmi_pict_retrieve_files_from_current_dir();
        mmi_pict_cat426_mark_selected_file();
        mmi_pict_entry_multi_file_selection();
    #else /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
        mmi_pict_get_file_date();
        mmi_pict_entry_print_settings();
    #endif /* __MMI_PICT_BRIDGE_MULTI_FILE_PRINT__ */
    }
}

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

