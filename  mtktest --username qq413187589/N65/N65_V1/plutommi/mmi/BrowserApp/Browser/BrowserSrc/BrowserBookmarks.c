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
 * BrowserBookmarks.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the function defination for logical implementation 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef MMI_BROWSERBOOKMARKS_C
#define MMI_BROWSERBOOKMARKS_C

/*  Include: MMI header file */

//#ifdef __MMI_BROWSER_2__
#if defined(__MMI_BROWSER_2__) && defined(__MMI_VBOOKMARK__)

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "OrganizerDef.h"
#include "DateTimeGprot.h"
#include "ServiceDefs.h"
#include "BrowserResDef.h"
#include "BrowserMain.h"
#include "BrowserTypes.h"
#include "BrowserGprots.h"
#include "BrowserBookmarks.h"
#include "string.h"
#include "Fmt_struct.h"
#include "vObjects.h"
#include "oppmmigprots.h"
#include "extdevicedefs.h"
#include "FileManagerDef.h"
#ifdef BRW_DEFAULT_BKM_SUPPORT
#include "custom_wap_config.h"
#endif /* BRW_DEFAULT_BKM_SUPPORT */
#if  defined(__MMI_IRDA_SUPPORT__)	 
#include "IrdaMMIGprots.h"
#endif /* __MMI_IRDA_SUPPORT__ */

/*  Include: NVRAM header file */
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#endif 


/* Global variables */
MMI_BOOL g_brw_bkm_sel_bkm_pool = MMI_FALSE;
static U16 g_brw_bkm_scr_id;
static brw_bkm_calling_module_type_enum g_brw_bkm_caller_id;
brw_bkm_add_bookmark_enum g_brw_bkm_add_type; 
brw_bkm_context_struct g_brw_bkm_cntx;
brw_bkm_browse_path_context_struct g_brw_bkm_browse_path_cntx;
brw_bkm_browse_path_enum g_brw_bkm_browse_path_event;
#ifdef BRW_DEFAULT_BKM_SUPPORT
extern const custom_wap_bkm_struct wap_bkm_default;
#endif /* BRW_DEFAULT_BKM_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_context_init
 * DESCRIPTION
 *  it initializes the global bookmark context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 def_drive_str[BRW_BKM_DRIVE_NAME_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_bkm_cntx.sel_file_index = -1;
	g_brw_bkm_cntx.total_file_count = 0;
	g_brw_bkm_cntx.file_info_list = NULL;

	sprintf((S8*)def_drive_str, "%c", BRW_BKM_DEFAULT_DRIVE);

	mmi_asc_to_ucs2((S8*)g_brw_bkm_cntx.default_drive_name, (S8*)def_drive_str);
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.default_drive_name, (S8*)L":");

	mmi_asc_to_ucs2((S8*)g_brw_bkm_cntx.default_folder_path, (S8*)def_drive_str);
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.default_folder_path, (S8*)L":\\");
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.default_folder_path, (S8*)BRW_BKM_DEFAULT_FOLDER_NAME);

	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_folder_path);
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_extn, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_url, (S8*)L"");

	g_brw_bkm_browse_path_cntx.sel_folder_index = -1;
	g_brw_bkm_browse_path_cntx.total_folder_count = 0;
	mmi_ucs2cpy((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)L"");
	mmi_ucs2cpy((S8*)g_brw_bkm_browse_path_cntx.sel_folder_name, (S8*)L"");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_confirm_dialog_GoBackHistory
 * DESCRIPTION
 *  To go back to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_confirm_dialog_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteUptoScrID(g_brw_bkm_scr_id);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm_dialog_GoBackHistory
 * DESCRIPTION
 *  To go back to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_from_fmgr_confirm_dialog_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteNHistory(1);
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_add_bookmark
 * DESCRIPTION
 *  Function to save the bookmark as a file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8	file_name[FILE_PATH_LEN];
	FS_HANDLE	file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*removing white spaces from title string*/
	mmi_brw_trim_left_white_spaces((S8*)g_brw_current_title);
	mmi_brw_trim_right_white_spaces((S8*)g_brw_current_title);

	/*removing white spaces from URL string*/
	//mmi_brw_trim_left_white_spaces((S8*)g_brw_current_url);
	//mmi_brw_trim_right_white_spaces((S8*)g_brw_current_url);

	/*check filename regarding the special chars*/
	if(!mmi_brw_bookmarks_validate_filename(g_brw_current_title))
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_TITLE), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		//DeleteUptoScrID(g_brw_bkm_scr_id);
		return;
	}

	/*validating the url string*/
	if(mmi_brw_validate_url(g_brw_current_url) < 0)
    {
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
 		//DeleteUptoScrID(g_brw_bkm_scr_id);
        return;
    }

	mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)file_path, (S8*)g_brw_current_title);
	mmi_ucs2cat((S8*)file_path, (S8*)L".");
	mmi_ucs2cat((S8*)file_path, (S8*)BRW_BKM_USER_CREATED_FILE_DEFAULT_EXTN);

	/*Checking the maximum allowable full path length for the file*/
    if ( mmi_ucs2strlen((S8*) file_path) >= FMGR_MAX_PATH_LEN )
	{
        DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		//DeleteUptoScrID(g_brw_bkm_scr_id);
		return;
	}

	file_handle = FS_Open((UI_string_type)file_path, FS_READ_ONLY);
	if(file_handle < 0)
	{
		file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE | FS_CREATE);
		if(file_handle < 0)
		{
			if(file_handle == FS_INVALID_FILENAME)
			{
				DisplayPopup(
					(PU8) GetString(STR_ID_BRW_INVALID_TITLE), 
					IMG_GLOBAL_ERROR, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					ERROR_TONE);
			}
			else
			{
				mmi_brw_bookmarks_file_system_error_handler(file_handle);
			    DeleteUptoScrID(g_brw_bkm_scr_id);
			}
			return;
		} /*if(file_handle < 0)*/
		else
		{
			if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
			{
			    DisplayPopup(
				    (PU8) GetString(STR_GLOBAL_DONE), 
				    IMG_GLOBAL_ACTIVATED, 
				    1, 
				    UI_POPUP_NOTIFYDURATION_TIME, 
				    SUCCESS_TONE);
			    if(g_brw_bkm_scr_id == SCR_ID_BRW_BOOKMARK_OPTIONS)
			    {
			        DeleteNScrId(g_brw_bkm_scr_id);
			    }
			    else
			    {
				    DeleteUptoScrID(g_brw_bkm_scr_id);
			    }
			    FS_Close(file_handle);
				return;
			} /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
			else
			{
				DisplayPopup(
					(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
					(U16) IMG_GLOBAL_ERROR,
					0,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) ERROR_TONE);
				DeleteUptoScrID(g_brw_bkm_scr_id);
				FS_Close(file_handle);
				FS_Delete((UI_string_type)file_path);
				return;
		    }
	    }
	} /*if(file_handle < 0)*/
	else
	{
		FS_Close(file_handle);
		mmi_brw_bookmarks_replace_file_confirm();
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_add_bookmark_replace_file
 * DESCRIPTION
 *  it replaces the existing bookmark file with the new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_add_bookmark_replace_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8	file_name[FILE_PATH_LEN];
	FS_HANDLE	file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	//S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)file_path, (S8*)g_brw_current_title);
	mmi_ucs2cat((S8*)file_path, (S8*)L".");
	mmi_ucs2cat((S8*)file_path, (S8*)BRW_BKM_USER_CREATED_FILE_DEFAULT_EXTN);

	/*Checking the maximum allowable full path length for the file*/
    if ( mmi_ucs2strlen((S8*) file_path) >= FMGR_MAX_PATH_LEN )
    {
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		//DeleteUptoScrID(g_brw_bkm_scr_id);
        return;
    }

	//error_code = FS_Delete((UI_string_type)file_path);
	file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
		{
		    DisplayPopup(
			    (PU8) GetString(STR_GLOBAL_DONE), 
			    IMG_GLOBAL_ACTIVATED, 
			    1, 
			    UI_POPUP_NOTIFYDURATION_TIME, 
			    SUCCESS_TONE);
		    if(g_brw_bkm_scr_id == SCR_ID_BRW_BOOKMARK_OPTIONS)
		    {
		        DeleteNScrId(g_brw_bkm_scr_id);
	        }
	        else
	        {
			    DeleteUptoScrID(g_brw_bkm_scr_id);
		    }
	    }
	    else
	    {
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			DeleteUptoScrID(g_brw_bkm_scr_id);
		}
		FS_Close(file_handle);
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		DeleteUptoScrID(g_brw_bkm_scr_id);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_replace_file
 * DESCRIPTION
 *  it replaces the existing bookmark file with the new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_replace_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE	file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	S32 error_code;
	U8 file_extn[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_extract_file_extn_from_filepath(g_brw_bkm_cntx.sel_file_path, file_extn);
	mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)file_path, (S8*)g_brw_current_title);
	mmi_ucs2cat((S8*)file_path, (S8*)L".");
	mmi_ucs2cat((S8*)file_path, (S8*)file_extn);

	/*Checking the maximum allowable full path length for the file*/
    if ( mmi_ucs2strlen((S8*) file_path) >= FMGR_MAX_PATH_LEN )
    {
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		//DeleteUptoScrID(g_brw_bkm_scr_id);
        return;
    }

	file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
		{
		    if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0 )
		    {
			    DisplayPopup(
				    (PU8) GetString(STR_GLOBAL_DONE), 
				    IMG_GLOBAL_ACTIVATED, 
				    1, 
				    UI_POPUP_NOTIFYDURATION_TIME, 
				    SUCCESS_TONE);
			    if( g_brw_bkm_scr_id == SCR_ID_BRW_BOOKMARK_OPTIONS ||
				    g_brw_bkm_caller_id == BRW_BKM_FROM_FILE_MANAGER
				    )
			    {
			        DeleteNScrId(g_brw_bkm_scr_id);
		        }
		        else
		        {
				    DeleteUptoScrID(g_brw_bkm_scr_id);
			    }
			} /*if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)*/
		    else
		    {
			    mmi_brw_bookmarks_file_system_error_handler(error_code);
			    DeleteUptoScrID(g_brw_bkm_scr_id);
		    }
		} /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
		else
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			DeleteUptoScrID(g_brw_bkm_scr_id);
	    }
		FS_Close(file_handle);
	} /*if(file_handle >= 0)*/
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		DeleteUptoScrID(g_brw_bkm_scr_id);
	}

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark
 * DESCRIPTION
 *  Function to save the bookmark to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 file_name[FILE_PATH_LEN];
	FS_HANDLE file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_brw_bookmarks_validate_filename(g_brw_current_title))
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_TITLE), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		//DeleteUptoScrID(g_brw_bkm_scr_id);
		return;
	}

	if(mmi_brw_validate_url(g_brw_current_url) < 0)
	{
        DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		//DeleteUptoScrID(g_brw_bkm_scr_id);
		return;
	}

	//if(!_wcsicmp((unsigned short*)g_brw_bkm_cntx.sel_file_name, (unsigned short*)g_brw_current_title))
	if(!mmi_ucs2icmp((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)g_brw_current_title))
	{
		file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_WRITE);
		if(file_handle >= 0)
		{
			if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
			{
			    DisplayPopup(
				    (PU8) GetString(STR_GLOBAL_DONE), 
				    IMG_GLOBAL_ACTIVATED, 
				    1, 
				    UI_POPUP_NOTIFYDURATION_TIME, 
				    SUCCESS_TONE);
			    if( g_brw_bkm_scr_id == SCR_ID_BRW_BOOKMARK_OPTIONS ||
				    g_brw_bkm_caller_id == BRW_BKM_FROM_FILE_MANAGER
				    )
			    {
			        DeleteNScrId(g_brw_bkm_scr_id);
			    }
			    else
			    {
				    DeleteUptoScrID(g_brw_bkm_scr_id);
			    }
			} /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
			else
			{
				DisplayPopup(
					(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
					(U16) IMG_GLOBAL_ERROR,
					0,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) ERROR_TONE);
				DeleteUptoScrID(g_brw_bkm_scr_id);
		    }
			FS_Close(file_handle);
		} /*if(file_handle >= 0)*/
		else
		{
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			DeleteUptoScrID(g_brw_bkm_scr_id);
		}
		return;
	}
	else
	{
		mmi_brw_bookmarks_extract_file_extn_from_filepath(g_brw_bkm_cntx.sel_file_path, file_extn_string);
		mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
		mmi_ucs2cat((S8*)file_path, (S8*)g_brw_current_title);
		mmi_ucs2cat((S8*)file_path, (S8*)L".");
		mmi_ucs2cat((S8*)file_path, (S8*)file_extn_string);

		/*Checking the maximum allowable full path length for the file*/
		if ( mmi_ucs2strlen((S8*) file_path) >= FMGR_MAX_PATH_LEN )
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
 			//DeleteUptoScrID(g_brw_bkm_scr_id);
			return;
		}

		file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE);
		if(file_handle < 0)
		{
			file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE | FS_CREATE);
			if(file_handle >= 0)
			{
				if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
				{
				    if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)
				    {
					    DisplayPopup(
						    (PU8) GetString(STR_GLOBAL_DONE), 
						    IMG_GLOBAL_ACTIVATED, 
						    1, 
						    UI_POPUP_NOTIFYDURATION_TIME, 
						    SUCCESS_TONE);
					    if( g_brw_bkm_scr_id == SCR_ID_BRW_BOOKMARK_OPTIONS ||
						    g_brw_bkm_caller_id == BRW_BKM_FROM_FILE_MANAGER
						    )
					    {
					        DeleteNScrId(g_brw_bkm_scr_id);
				        }
				        else
				        {
						    DeleteUptoScrID(g_brw_bkm_scr_id);
					    }
				    } /*if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)*/
				    else
				    {
					    mmi_brw_bookmarks_file_system_error_handler(error_code);
					    DeleteUptoScrID(g_brw_bkm_scr_id);
				    }
				    FS_Close(file_handle);
			    } /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
			    else
			    {
				    DisplayPopup(
					    (U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
					    (U16) IMG_GLOBAL_ERROR,
					    0,
					    UI_POPUP_NOTIFYDURATION_TIME,
					    (U8) ERROR_TONE);
				    DeleteUptoScrID(g_brw_bkm_scr_id);
				    FS_Close(file_handle);
				    FS_Delete((UI_string_type)file_path);
			    }
				return;
			} /*if(file_handle >= 0)*/
			else
			{
				if(file_handle == FS_INVALID_FILENAME)
				{
					DisplayPopup(
						(PU8) GetString(STR_ID_BRW_INVALID_TITLE), 
						IMG_GLOBAL_ERROR, 
						1, 
						UI_POPUP_NOTIFYDURATION_TIME, 
						ERROR_TONE);
				}
				else
				{
					mmi_brw_bookmarks_file_system_error_handler(file_handle);
				    DeleteUptoScrID(g_brw_bkm_scr_id);
				}
				return;
			}

		} /*if(file_handle < 0)*/
		else
		{
			FS_Close(file_handle);
			mmi_brw_bookmarks_replace_file_confirm();
		}
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_from_fmgr
 * DESCRIPTION
 *  Function to edit the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_brw_bookmarks_validate_filename(g_brw_current_title))
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_TITLE), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		return;
	}

	if(mmi_brw_validate_url(g_brw_current_url) < 0)
	{
        DisplayPopup(
			(PU8) GetString(STR_ID_BRW_INVALID_URL), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		return;
	}

	/*in case if New & Old filenames are same*/
	if(!mmi_ucs2icmp((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)g_brw_current_title))
	{
		file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_WRITE);
		if(file_handle >= 0)
		{
			if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
			{
				DisplayPopup(
					(PU8) GetString(STR_GLOBAL_DONE), 
					IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					SUCCESS_TONE);
				DeleteNScrId(g_brw_bkm_scr_id);
			} /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
			else
			{
				DisplayPopup(
					(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
					(U16) IMG_GLOBAL_ERROR,
					0,
					UI_POPUP_NOTIFYDURATION_TIME,
					(U8) ERROR_TONE);
				DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
			}
			FS_Close(file_handle);
		} /*if(file_handle >= 0)*/
		else
		{
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
		}
		return;
	}
	else
	{
		mmi_brw_bookmarks_extract_file_extn_from_filepath(g_brw_bkm_cntx.sel_file_path, file_extn_string);
		mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
		mmi_ucs2cat((S8*)file_path, (S8*)g_brw_current_title);
		mmi_ucs2cat((S8*)file_path, (S8*)L".");
		mmi_ucs2cat((S8*)file_path, (S8*)file_extn_string);

		/*Checking the maximum allowable full path length for the file*/
		if ( mmi_ucs2strlen((S8*) file_path) >= FMGR_MAX_PATH_LEN )
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
			return;
		}

		file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE);
		if(file_handle < 0)
		{
			file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE | FS_CREATE);
			if(file_handle >= 0)
			{
				if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
				{
					if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)
					{
						DisplayPopup(
							(PU8) GetString(STR_GLOBAL_DONE), 
							IMG_GLOBAL_ACTIVATED, 
							1, 
							UI_POPUP_NOTIFYDURATION_TIME, 
							SUCCESS_TONE);
						DeleteNScrId(g_brw_bkm_scr_id);
					} /*if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)*/
					else
					{
						mmi_brw_bookmarks_file_system_error_handler(error_code);
						DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
					}
					FS_Close(file_handle);
				} /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
				else
				{
					DisplayPopup(
						(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
						(U16) IMG_GLOBAL_ERROR,
						0,
						UI_POPUP_NOTIFYDURATION_TIME,
						(U8) ERROR_TONE);
					DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
					FS_Close(file_handle);
					FS_Delete((UI_string_type)file_path);
				}
				return;
			} /*if(file_handle >= 0)*/
			else
			{
				if(file_handle == FS_INVALID_FILENAME)
				{
					DisplayPopup(
						(PU8) GetString(STR_ID_BRW_INVALID_TITLE), 
						IMG_GLOBAL_ERROR, 
						1, 
						UI_POPUP_NOTIFYDURATION_TIME, 
						ERROR_TONE);
				}
				else
				{
					mmi_brw_bookmarks_file_system_error_handler(file_handle);
					DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
				}
				return;
			}

		} /*if(file_handle < 0)*/
		else
		{
			FS_Close(file_handle);
			mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file_confirm();
		}
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file
 * DESCRIPTION
 *  it replaces the existing bookmark file with the new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_edit_bookmark_from_fmgr_replace_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE	file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	S32 error_code;
	U8 file_extn[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_extract_file_extn_from_filepath(g_brw_bkm_cntx.sel_file_path, file_extn);
	mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)file_path, (S8*)g_brw_current_title);
	mmi_ucs2cat((S8*)file_path, (S8*)L".");
	mmi_ucs2cat((S8*)file_path, (S8*)file_extn);

	/*Checking the maximum allowable full path length for the file*/
    if ( mmi_ucs2strlen((S8*) file_path) >= FMGR_MAX_PATH_LEN )
    {
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
        return;
    }

	file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
		{
			if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)
			{
				DisplayPopup(
					(PU8) GetString(STR_GLOBAL_DONE), 
					IMG_GLOBAL_ACTIVATED, 
					1, 
					UI_POPUP_NOTIFYDURATION_TIME, 
					SUCCESS_TONE);
				DeleteNScrId(g_brw_bkm_scr_id);
			} /*if((error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path)) >= 0)*/
			else
			{
				mmi_brw_bookmarks_file_system_error_handler(error_code);
				DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
			}
		} /*if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))*/
		else
		{
			DisplayPopup(
				(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
				(U16) IMG_GLOBAL_ERROR,
				0,
				UI_POPUP_NOTIFYDURATION_TIME,
				(U8) ERROR_TONE);
			DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
		}
		FS_Close(file_handle);
	} /*if(file_handle >= 0)*/
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPEN_FROM_FMGR);
	}

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_file
 * DESCRIPTION
 *  Delete the selected bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	//U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	//FS_HANDLE file_handle;
	S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	error_code = FS_Delete((UI_string_type)g_brw_bkm_cntx.sel_file_path);

	if(error_code >= 0)
	{
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);
		DeleteNScrId(SCR_ID_BRW_BOOKMARK_OPTIONS);
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(error_code);
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_all_user_files
 * DESCRIPTION
 *  Deletes all the bookmarks
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_all_user_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
	FS_DOSDirEntry file_info;
	U8 filename[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 pattern[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	FS_Pattern_Struct TestArray[2];
	S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)pattern, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)pattern, (S8*)L"\\*");

	kal_wstrcpy(TestArray[0].Pattern, BRW_BKM_FILE_SEARCH_PATTERN_URL);
	kal_wstrcpy(TestArray[1].Pattern, BRW_BKM_FILE_SEARCH_PATTERN_VBM);

    if ((handle =  FS_FindFirstN(
                    (UI_string_type)pattern,
					TestArray,
					2,
                    0,
                    0,
					0,
                    &file_info,
                    (U16*) filename,
                    (BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH,
					0,
					0)) >= 0)
    {
        do
        {
			mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
			mmi_ucs2cat((S8*)file_path, (S8*)L"\\");
			mmi_ucs2cat((S8*)file_path, (S8*)filename);
			error_code = FS_Delete((UI_string_type)file_path);

        } while ((FS_FindNextN(
				handle, 
				TestArray, 
				2, 
				0, 
				&file_info, 
				(UI_string_type) filename, 
				(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH, 
				0) >= 0));

        FS_FindClose(handle);
	}

    DisplayPopup(
		(PU8) GetString(STR_GLOBAL_DONE), 
		IMG_GLOBAL_ACTIVATED, 
		1, 
		UI_POPUP_NOTIFYDURATION_TIME, 
		SUCCESS_TONE);

	DeleteNScrId(SCR_ID_BRW_BOOKMARK_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_goto
 * DESCRIPTION
 *  This function fetches the current highlighted bookmark url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*)g_brw_current_url, (S8*)g_brw_bkm_cntx.sel_file_url);
    mmi_brw_pre_entry_goto_url();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_set_as_homepage
 * DESCRIPTION
 *  This function sets the bookmark url as homepage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_set_as_homepage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url_ascii[BRW_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2_to_asc((S8*)url_ascii, (S8*)g_brw_bkm_cntx.sel_file_url);
    mmi_brw_set_as_homepage(url_ascii);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_edit
 * DESCRIPTION
 *  Pre Entry function for Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)g_brw_current_title, (S8*)g_brw_bkm_cntx.sel_file_name);
	mmi_ucs2cpy((S8*)g_brw_current_url, (S8*)g_brw_bkm_cntx.sel_file_url);

	if(g_brw_bkm_caller_id != BRW_BKM_FROM_FILE_MANAGER)
	{
	    g_brw_bkm_scr_id = GetActiveScreenId();
	}

	mmi_brw_bookmarks_entry_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_recv_file_view
 * DESCRIPTION
 *  Pre Entry function for Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_recv_file_view(U8* file_path, U8* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(file_path);

	file_handle = FS_Open((UI_string_type)file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_reader_validate_file(file_handle))
		{			
			mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)file_name);
			mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);

			mmi_brw_bookmarks_entry_view();
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
		}
		FS_Close(file_handle);
		return;
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_recv_file_save_to_bookmark
 * DESCRIPTION
 *  This function is the external interface for saving a received vbookmark file
 *  into bookmark application
 * PARAMETERS
 *  file_path		[IN]	file path in UCS2
 *  file_name		[IN]	file name in UCS2
 *  file_extn		[IN]	file extension in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_recv_file_save_to_bookmark(U8* file_path, U8* file_name, U8* file_extn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
	U8 file_path_ascii[(BRW_BKM_MAX_PATH_LEN+1) * BRW_UTF8_ENCODING_LENGTH];
	U8 file_name_ascii[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1) * BRW_UTF8_ENCODING_LENGTH];
	U8 file_extn_ascii[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * BRW_UTF8_ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(file_path);
	MMI_ASSERT(file_name);
	MMI_ASSERT(file_extn);

	mmi_chset_ucs2_to_utf8_string((U8*)file_path_ascii, (BRW_BKM_MAX_PATH_LEN+1) * BRW_UTF8_ENCODING_LENGTH, (U8*)file_path);
	mmi_chset_ucs2_to_utf8_string((U8*)file_name_ascii, (BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1) * BRW_UTF8_ENCODING_LENGTH, (U8*)file_name);
	mmi_chset_ucs2_to_utf8_string((U8*)file_extn_ascii, (BRW_BKM_MAX_FILE_EXTN_LEN+1) * BRW_UTF8_ENCODING_LENGTH, (U8*)file_extn);

    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserBookmarks.c] mmi_brw_bookmarks_recv_file_save_to_bookmark file_path = %s\n", file_path_ascii);
    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserBookmarks.c] mmi_brw_bookmarks_recv_file_save_to_bookmark file_name = %s\n", file_name_ascii);
    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserBookmarks.c] mmi_brw_bookmarks_recv_file_save_to_bookmark file_extn = %s\n", file_extn_ascii);

	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	g_brw_bkm_scr_id = IDLE_SCREEN_ID;
	g_brw_bkm_caller_id = BRW_BKM_FROM_VBOOKMARK;

	/*create vbookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else 
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			return;
        }
    }

	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)file_path);
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)file_name);
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_extn, (S8*)file_extn);

	mmi_brw_bookmarks_pre_entry_save_to_bookmark();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_save_to_bookmark
 * DESCRIPTION
 *  Pre Entry function for Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_save_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_reader_validate_file(file_handle))
		{
			mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);
			mmi_brw_bookmarks_entry_save_to_bookmark();
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
		}
		FS_Close(file_handle);
		return;
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_save_to_bookmark
 * DESCRIPTION
 *  Pre Entry function for Edit bookmark screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_save_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 full_file_name[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 dest_file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.default_folder_path);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L".");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.sel_file_extn);

	mmi_brw_bookmarks_copy_recv_file_to_dest(g_brw_bkm_cntx.sel_file_path, dest_file_path);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_create_folder
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE	file_handle;
	U8 dir_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	S32 error_code;
	U16 ScrID;
	//U8 len1, len2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*initialize the correct return screen according to the operation*/
	if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_NONE)
	{
		mmi_ucs2cpy((S8*)dir_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		ScrID = SCR_ID_BRW_BOOKMARKS;
	}
	else
	{
		mmi_ucs2cpy((S8*)dir_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
		ScrID = SCR_ID_BRW_BOOKMARK_BROWSE_PATH;
	}

	/*removing white spaces from folder name*/
	mmi_brw_trim_left_white_spaces((S8*)g_brw_current_title);
	mmi_brw_trim_right_white_spaces((S8*)g_brw_current_title);

	/*check folder name regarding the special chars*/
	if(!mmi_brw_bookmarks_validate_filename(g_brw_current_title))
	{
		mmi_brw_bookmarks_file_system_error_handler(FS_INVALID_FILENAME);
 		DeleteUptoScrID(SCR_ID_BRW_BKM_CREATE_FOLDER);
		return;
	}

	mmi_ucs2cat((S8*)dir_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dir_path, (S8*)g_brw_current_title);

	/*checking the maximum allowable full path length for the folder*/
    if ( mmi_ucs2strlen((S8*) dir_path) >= (FMGR_MAX_PATH_LEN - BRW_BKM_AVERAGE_FILENAME_LENGTH) )
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
 		DeleteUptoScrID(SCR_ID_BRW_BKM_CREATE_FOLDER);
       return;
	}

	/*checking the maximum allowable folder path depth*/
    if ( mmi_brw_bookmarks_get_folder_depth((U8*)dir_path) > BRW_BKM_MAX_DIR_DEPTH )
    {
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_DIR_PATH_TOO_DEEP), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
 		DeleteUptoScrID(ScrID);
        return;
    }

	/*check whether any folder with the same name already exists*/
	file_handle = FS_Open((UI_string_type)dir_path, FS_READ_ONLY | FS_OPEN_DIR);
	if(file_handle >= 0)
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FOLDER_ALREADY_EXISTS), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
		FS_Close(file_handle);
		DeleteUptoScrID(SCR_ID_BRW_BKM_CREATE_FOLDER);
		return;
	}

	error_code = FS_CreateDir((UI_string_type)dir_path);
	if(error_code == FS_NO_ERROR)
	{
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);
		DeleteUptoScrID(ScrID);
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(error_code);
		DeleteUptoScrID(ScrID);
	}
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_copy_to
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_copy_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	g_brw_bkm_browse_path_event = BRW_BKM_BROWSE_PATH_COPY_TO;

	mmi_ucs2cpy((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name);

	/*highlighting the first element on entering*/
	g_brw_bkm_browse_path_cntx.index_highlighted_item = 0;

	mmi_brw_bookmarks_entry_browse_path();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_move_to
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_move_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_bkm_browse_path_event = BRW_BKM_BROWSE_PATH_MOVE_TO;

	mmi_ucs2cpy((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name);

	/*highlighting the first element on entering*/
	g_brw_bkm_browse_path_cntx.index_highlighted_item = 0;

	mmi_brw_bookmarks_entry_browse_path();	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_memory_status
 * DESCRIPTION
 *  Pre Entry function for send address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_memory_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 avail_memory;
	S32 alloc_memory;
	S32 total_memory = BRW_BKM_FOLDER_QUOTA;
	U8	temp_str[BRW_MEMORY_STATUS_MSG_LEN+1];
	U8	avail_str[50];
	U8	alloc_str[50];
	U8	total_str[50];
	U8	kbytes_str[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_display_info_str)
	{
		mmi_brw_mfree(g_brw_display_info_str);
	}

	g_brw_display_info_str = mmi_brw_malloc(BRW_MEMORY_STATUS_MSG_LEN+1);

	alloc_memory = FS_GetFolderSize((const WCHAR*)g_brw_bkm_cntx.default_folder_path, FS_COUNT_IN_BYTE, NULL, 0);
	avail_memory = total_memory - alloc_memory;

	mmi_chset_ucs2_to_utf8_string((U8*)avail_str, 50, (U8*)GetString(STR_ID_BRW_AVAILABLE));
	mmi_chset_ucs2_to_utf8_string((U8*)alloc_str, 50, (U8*)GetString(STR_ID_BRW_ALLOCATED));
	mmi_chset_ucs2_to_utf8_string((U8*)total_str, 50, (U8*)GetString(STR_ID_BRW_TOTAL));
	mmi_chset_ucs2_to_utf8_string((U8*)kbytes_str, 10, (U8*)GetString(STR_ID_BRW_KBYTES));

	sprintf((S8*) temp_str, "%s : %d %s\n%s : %d %s \n%s : %d %s", 
		avail_str, avail_memory/1024, kbytes_str, alloc_str, alloc_memory/1024, kbytes_str,
		total_str, total_memory/1024, kbytes_str);
	mmi_chset_utf8_to_ucs2_string((U8*)g_brw_display_info_str, BRW_MEMORY_STATUS_MSG_LEN+1, (U8*)temp_str);

	mmi_brw_entry_memory_status();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_show_list
 * DESCRIPTION
 *  Entry function for Bookmark list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_show_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_free_memory();
	mmi_brw_bookmarks_context_init();

	g_brw_bkm_caller_id = BRW_BKM_FROM_NONE;

	/*create vbookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			return;
        }
    }

	/*highlighting the first element on entering*/
	g_brw_bkm_cntx.index_highlighted_item = 0;

	/*displaying the bookmark list*/
	mmi_brw_bookmarks_entry_show_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_file_and_folder_count
 * DESCRIPTION
 *  func for calculating the total number of bookmark files and folder in the given
 *  directory
 * PARAMETERS
 *  bkm_folder_path		[IN]	path for which bookmark files are to be counted         
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_brw_bookmarks_get_file_and_folder_count(U8* bkm_folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
	FS_DOSDirEntry file_info;
	U8 filename[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 pattern[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	FS_Pattern_Struct TestArray[3];
	U32 total_file_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)pattern, (S8*)bkm_folder_path);
	mmi_ucs2cat((S8*)pattern, (S8*)L"\\*");

	kal_wstrcpy(TestArray[0].Pattern, BRW_BKM_FILE_SEARCH_PATTERN_DFT);
	kal_wstrcpy(TestArray[1].Pattern, BRW_BKM_FILE_SEARCH_PATTERN_URL);
	kal_wstrcpy(TestArray[2].Pattern, BRW_BKM_FILE_SEARCH_PATTERN_VBM);

    if ((handle =  FS_FindFirstN(
                    (UI_string_type)pattern,
					TestArray,
					3,
                    FS_ATTR_DIR,
                    0,
					0,
                    &file_info,
                    (UI_string_type) filename,
                    (BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH,
					0,
					0)) >= 0)
    {
        do
        {
			if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
				mmi_ucs2cmp((S8*)filename, (S8*)L"..")
				)
			{
				++total_file_count;
			}
        } while ((FS_FindNextN(handle, 
			TestArray, 
			3, 
			FS_ATTR_DIR, 
			&file_info, 
			(UI_string_type) filename, 
			(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH, 
			0) == FS_NO_ERROR));

        FS_FindClose(handle);
	}
	return total_file_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_only_folder_count
 * DESCRIPTION
 *  func for calculating the total number of bookmark files and folder in the given
 *  directory
 * PARAMETERS
 *  bkm_folder_path		[IN]	path for which bookmark files are to be counted         
 * RETURNS
 *  number of folders present in the current directory
 *****************************************************************************/
U32 mmi_brw_bookmarks_get_only_folder_count(U8* bkm_folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
	FS_DOSDirEntry file_info;
	U8 filename[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	//U8 file_extn[BRW_BKM_MAX_FILE_EXTN_LEN+1];
	U8 pattern[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U32 folder_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2cmp((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name))
	{
		folder_count = 1;
		handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
		MMI_ASSERT(handle >= 0);
		FS_Close(handle);
	}
	else
	{
		mmi_ucs2cpy((S8*)pattern, (S8*)bkm_folder_path);
		mmi_ucs2cat((S8*)pattern, (S8*)L"\\*");

		if ((handle =  FS_FindFirst(
						(UI_string_type)pattern,
						FS_ATTR_DIR,
						0,
						&file_info,
						(U16*) filename,
						BRW_BKM_MAX_FILE_NAME_LEN)) >= 0)
		{
			do
			{
				if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
					mmi_ucs2cmp((S8*)filename, (S8*)L"..")
					)
				{
					++folder_count;
				}
			} while (FS_FindNext(
				handle, 
				&file_info, 
				(UI_string_type) filename, 
				BRW_BKM_MAX_FILE_NAME_LEN) >= 0);

			FS_FindClose(handle);
		}
	}

	return folder_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_file_extn
 * DESCRIPTION
 *  It finds the bookmark file extension
 * PARAMETERS
 *  filename	[IN]	File name in unicode
 * RETURNS
 * file extn type enum
 *****************************************************************************/
brw_bkm_file_extension_types_enum mmi_brw_bookmarks_get_file_extn(U8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	U8* file_extn_ptr;
	U8 file_extn;
	//U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(filename);

	file_extn_ptr = (U8*)mmi_ucs2rchr((const S8*)filename, (U16)'.');
	if(file_extn_ptr)
	{
		mmi_ucs2cpy((S8*)file_extn_string, (S8*)(file_extn_ptr+ENCODING_LENGTH));
		mmi_brw_UCS2Strtolower((S8*)file_extn_string);
	}
	else
	{
		return BRW_BKM_FILE_EXTN_NONE;
	}

	if(!mmi_ucs2cmp((S8*)file_extn_string, (S8*)BRW_BKM_FILE_EXTN_DFT_STRING))
	{
		file_extn = BRW_BKM_FILE_EXTN_DFT;
	}
	else if(!mmi_ucs2cmp((S8*)file_extn_string, (S8*)BRW_BKM_FILE_EXTN_URL_STRING))
	{
		file_extn = BRW_BKM_FILE_EXTN_URL;
	}
	else if(!mmi_ucs2cmp((S8*)file_extn_string, (S8*)BRW_BKM_FILE_EXTN_VBM_STRING))
	{
		file_extn = BRW_BKM_FILE_EXTN_VBM;
	}
	else
	{
		file_extn = BRW_BKM_FILE_EXTN_NONE;
	}

	return file_extn;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_file_extn_string
 * DESCRIPTION
 *  It gives the bookmark file extension string and should only be used at the 
 *  time of calculating the selected file path. It shouldn't be used at other
 *  places.
 * PARAMETERS
 *  file_extn			[IN]	file extension enum
 *  file_extn_string	[IN]	file extension string
 * RETURNS
 * void
 *****************************************************************************/
void mmi_brw_bookmarks_get_file_extn_string(U8 file_extn, U8* file_extn_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(file_extn < BRW_BKM_FILE_EXTN_TOTAL);

	switch(file_extn)
	{
		case BRW_BKM_FILE_EXTN_NONE:
		{
			mmi_ucs2cpy((S8*)file_extn_string, (S8*)L"");
			break;
		}
		case BRW_BKM_FILE_EXTN_DFT:
		{
			mmi_ucs2cpy((S8*)file_extn_string, (S8*)BRW_BKM_FILE_EXTN_DFT_STRING);
			break;
		}
		case BRW_BKM_FILE_EXTN_URL:
		{
			mmi_ucs2cpy((S8*)file_extn_string, (S8*)BRW_BKM_FILE_EXTN_URL_STRING);
			break;
		}
		case BRW_BKM_FILE_EXTN_VBM:
		{
			mmi_ucs2cpy((S8*)file_extn_string, (S8*)BRW_BKM_FILE_EXTN_VBM_STRING);
			break;
		}
	}

	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of bookmarks screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_bookmarks_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_DOSDirEntry file_info;
	U8 filename[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 pattern[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8* file_extn_ptr;
	static FS_Pattern_Struct filter_Array[2];
    static FS_HANDLE handle = 0;
	static U8 array_count = 0;
	static BYTE file_attr = FS_ATTR_DIR;
	static U8 find_next = MMI_FALSE;
	static U8 file_type = BRW_BKM_FOLDER;
	static S32 curr_item_index = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)pattern, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)pattern, (S8*)L"\\*");

	if(curr_item_index >= item_index)
	{
		curr_item_index = -1;
		array_count = 0;
		file_attr = FS_ATTR_DIR;
		file_type = BRW_BKM_FOLDER;
		find_next = MMI_FALSE;
		FS_FindClose(handle);
	}

	while(1)
	{
		if(!find_next)
		{
				if ((handle =  FS_FindFirstN(
								(UI_string_type)pattern,
								filter_Array,
								array_count,
								0,
								file_attr,
								0,
								&file_info,
								(UI_string_type) filename,
								(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH,
								0,
								0)) >= 0)
				{
					find_next = MMI_TRUE;
					if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
						mmi_ucs2cmp((S8*)filename, (S8*)L"..") &&
						(++curr_item_index == item_index )
						)
					{
						break;
					}
				}
				else
				{
					if(file_type == BRW_BKM_FOLDER)
					{
						mmi_ucs2cpy((S8*)filter_Array[0].Pattern, (S8*)BRW_BKM_FILE_SEARCH_PATTERN_DFT);
						array_count = 1;
						file_attr = 0;
						file_type = BRW_BKM_DEFAULT_FILE;
					}
					else if(file_type == BRW_BKM_DEFAULT_FILE)
					{
						mmi_ucs2cpy((S8*)filter_Array[0].Pattern, (S8*)BRW_BKM_FILE_SEARCH_PATTERN_URL);
						mmi_ucs2cpy((S8*)filter_Array[1].Pattern, (S8*)BRW_BKM_FILE_SEARCH_PATTERN_VBM);
						array_count = 2;
						file_attr = 0;
						file_type = BRW_BKM_USER_CREATED_FILE;
					}
				}
		}
		else
		{
				if( FS_FindNextN
					(handle, 
					filter_Array, 
					array_count, 
					file_attr, 
					&file_info, 
					(UI_string_type) filename, 
					(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH, 
					0) >= 0 )
				{
					if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
						mmi_ucs2cmp((S8*)filename, (S8*)L"..") &&
						(++curr_item_index == item_index )
						)
					{
						break;
					}
				}
				else
				{
					find_next = MMI_FALSE;
					FS_FindClose(handle);

					if(file_type == BRW_BKM_FOLDER)
					{
						mmi_ucs2cpy((S8*)filter_Array[0].Pattern, (S8*)BRW_BKM_FILE_SEARCH_PATTERN_DFT);
						array_count = 1;
						file_attr = 0;
						file_type = BRW_BKM_DEFAULT_FILE;
					}
					else if(file_type == BRW_BKM_DEFAULT_FILE)
					{
						mmi_ucs2cpy((S8*)filter_Array[0].Pattern, (S8*)BRW_BKM_FILE_SEARCH_PATTERN_URL);
						mmi_ucs2cpy((S8*)filter_Array[1].Pattern, (S8*)BRW_BKM_FILE_SEARCH_PATTERN_VBM);
						array_count = 2;
						file_attr = 0;
						file_type = BRW_BKM_USER_CREATED_FILE;
					}
				}
		}
	}

	if(file_type == BRW_BKM_FOLDER)
	{
		g_brw_bkm_cntx.file_info_list[item_index].file_extn = BRW_BKM_FILE_EXTN_NONE;
	}
	else
	{
	    g_brw_bkm_cntx.file_info_list[item_index].file_extn = mmi_brw_bookmarks_get_file_extn(filename);
  	    if(g_brw_bkm_cntx.file_info_list[item_index].file_extn != BRW_BKM_FILE_EXTN_NONE)
	    {
		    file_extn_ptr = (U8*)mmi_ucs2rchr((const S8*)filename, (U16)'.');
		    mmi_ucs2cpy((S8*)file_extn_ptr, (S8*)L"\0");
	    }
	}
	mmi_ucs2cpy((S8*)str_buff, (S8*)filename);

	if(file_type == BRW_BKM_FOLDER)
	{
		*img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);
	}
	else if(file_type == BRW_BKM_DEFAULT_FILE)
	{
		*img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_DEFAULT_FILE);
	}
	else if(file_type == BRW_BKM_USER_CREATED_FILE)
	{
		*img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_USER_FILE);
	}

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_folder_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic fodler list of bookmarks screen
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [?]         [?]         image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_brw_bookmarks_folder_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_DOSDirEntry file_info;
	U8 filename[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 pattern[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
    static FS_HANDLE handle = 0;
	static U8 find_next = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2cmp((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name))
	{
		mmi_ucs2cpy((S8*)str_buff, (S8*)BRW_BKM_DEFAULT_FOLDER_NAME);
		*img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);
		return MMI_TRUE;
	}

	mmi_ucs2cpy((S8*)pattern, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)pattern, (S8*)L"\\*");

	while(1)
	{
		if(!find_next)
		{
				if ((handle =  FS_FindFirst(
								(UI_string_type)pattern,
								FS_ATTR_DIR,
								0,
								&file_info,
								(UI_string_type) filename,
								(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH)) >= 0)
				{
					find_next = MMI_TRUE;
					if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
						mmi_ucs2cmp((S8*)filename, (S8*)L"..")
						)
					{
						break;
					}
				}
		}
		else
		{
				if( FS_FindNext
					(handle, 
					&file_info, 
					(UI_string_type) filename, 
					(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH) >= 0 )
				{
					if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
						mmi_ucs2cmp((S8*)filename, (S8*)L"..")
						)
					{
						break;
					}
				}
		}
	}

	mmi_ucs2cpy((S8*)str_buff, (S8*)filename);
	*img_buff_p = get_image(IMG_ID_BRW_BOOKMARKS_FOLDER_ICON);

	if(item_index == g_brw_bkm_browse_path_cntx.total_folder_count-1)
	{
		find_next = MMI_FALSE;
		FS_FindClose(handle);
	}

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_allocate_file_info_list
 * DESCRIPTION
 *  This function allocates  memory for file info list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_allocate_file_info_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_bkm_cntx.file_info_list)
	{
		mmi_brw_mfree(g_brw_bkm_cntx.file_info_list);
		g_brw_bkm_cntx.file_info_list = NULL;
	}

	g_brw_bkm_cntx.file_info_list = 
			(brw_bkm_file_info_struct*) mmi_brw_malloc(sizeof(brw_bkm_file_info_struct) * g_brw_bkm_cntx.total_file_count);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_add_bookmark
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	memset(g_brw_current_title, 0, sizeof(g_brw_current_title));
	mmi_asc_to_ucs2((S8*) g_brw_current_url, (S8*)BRW_DEFAULT_ENTER_ADDR_STR);
	
	g_brw_bkm_scr_id = GetActiveScreenId();
	g_brw_bkm_add_type = BRW_BKM_ADD_BOOKMARK;

	mmi_brw_bookmarks_entry_add_bookmark();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_file_list_go_back_history
 * DESCRIPTION
 *  Its is called when user selects back option from bookmark list screen. Its
 *  purpose is to displays appropiate screen. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_file_list_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 folder_path[BRW_BKM_MAX_PATH_LEN+1];
	//U16 len=0;
	//S16 index;
	UI_string_type end_sep_loc;
	U8 sel_folder_name[(BRW_BKM_MAX_FILE_NAME_LEN+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2cmp((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_folder_path))
	{
		mmi_brw_bookmarks_GoBackHistory();
	}
	else
	{
		/*mmi_ucs2_to_asc((S8*)folder_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		len = strlen((S8*)folder_path);
		for(index = len-1; index >= 0; index--)
		{
			if(folder_path[index] == '\\')
			{
				folder_path[index] = '\0';
				break;
			}
		}
		mmi_asc_to_ucs2((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)folder_path);*/

		end_sep_loc = (UI_string_type)mmi_ucs2rchr((const S8*)g_brw_bkm_cntx.sel_folder_path, (U16)'\\');
		mmi_ucs2cpy((S8*)sel_folder_name, (S8*)end_sep_loc + ENCODING_LENGTH);
		*end_sep_loc = '\0';

		/*here it is used for highlighting the default menu item*/
		mmi_brw_entry_dummy_screen();

		/*highlighting the selected folder*/
		g_brw_bkm_cntx.index_highlighted_item = 
			mmi_brw_bookmarks_get_highlight_item((U8*)g_brw_bkm_cntx.sel_folder_path, (U8*)sel_folder_name);

		/*displaying the bookmark list*/
		mmi_brw_bookmarks_entry_show_list();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_go_back_history
 * DESCRIPTION
 *  Its is called when user selects back option from select path bookmark folder
 *  list screen. Its  purpose is to displays appropiate screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 folder_path[BRW_BKM_MAX_PATH_LEN+1];
	//U16 len=0;
	//S16 index;
	UI_string_type end_sep_loc;
	U8 sel_folder_name[(BRW_BKM_MAX_FILE_NAME_LEN+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2cmp((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name))
	{
		GoBackHistory();
	}
	else
	{
		/*mmi_ucs2_to_asc((S8*)folder_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
		len = strlen((S8*)folder_path);
		for(index = len-1; index >= 0; index--)
		{
			if(folder_path[index] == '\\')
			{
				folder_path[index] = '\0';
				break;
			}
		}
		mmi_asc_to_ucs2((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)folder_path);*/

		end_sep_loc = (UI_string_type)mmi_ucs2rchr((const S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (U16)'\\');
		mmi_ucs2cpy((S8*)sel_folder_name, (S8*)end_sep_loc + ENCODING_LENGTH);
		*end_sep_loc = '\0';

		/*here it is used for highlighting the default menu item*/
		mmi_brw_entry_dummy_screen();

		/*highlighting the selected folder*/
		g_brw_bkm_browse_path_cntx.index_highlighted_item = 
			mmi_brw_bookmarks_get_highlight_item((U8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (U8*)sel_folder_name);

		mmi_brw_bookmarks_entry_browse_path();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_options
 * DESCRIPTION
 *  Pre Entry function for bookmark options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_bkm_cntx.total_file_count)
	{
		g_brw_bkm_cntx.sel_file_index = (S32)GetHighlightedItem();
		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)get_dynamic_item_text(g_brw_bkm_cntx.sel_file_index));

		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)L"\\");
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);

		mmi_brw_bookmarks_get_file_extn_string(
			g_brw_bkm_cntx.file_info_list[g_brw_bkm_cntx.sel_file_index].file_extn, g_brw_bkm_cntx.sel_file_extn);

		/*handling bookmark files*/
		if(mmi_ucs2strlen((S8*)g_brw_bkm_cntx.sel_file_extn))
		{
			mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)L".");
			mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_file_extn);

			file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_ONLY);
			if(file_handle >= 0)
			{
				if(mmi_vbkm_reader_validate_file(file_handle))
				{
					mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);
					FS_Close(file_handle);
					mmi_brw_bookmarks_entry_options();
				}
				else
				{
					DisplayPopup(
						(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
						IMG_GLOBAL_ERROR, 
						1, 
						UI_POPUP_NOTIFYDURATION_TIME, 
						ERROR_TONE);
					FS_Close(file_handle);
					return;
				}
			}
			else
			{
				mmi_brw_bookmarks_file_system_error_handler(file_handle);
				return;
			}

		} /*if(mmi_ucs2strlen((S8*)g_brw_bkm_cntx.sel_file_extn))*/

		else /*handling bookmark folders*/
		{
			mmi_brw_bookmarks_entry_options();
		}

	} /*if(g_brw_bkm_cntx.total_file_count)*/

	else /*handling empty folder*/
	{
		mmi_brw_bookmarks_entry_options();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_pre_entry_options
 * DESCRIPTION
 *  Pre Entry function for bookmark select path options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//FS_HANDLE file_handle;
	//U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	//U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_bkm_browse_path_cntx.total_folder_count)
	{
		g_brw_bkm_browse_path_cntx.sel_folder_index = (S32)GetHighlightedItem();

		mmi_ucs2cpy((S8*)g_brw_bkm_browse_path_cntx.sel_folder_name, (S8*)get_item_text(g_brw_bkm_browse_path_cntx.sel_folder_index));
	}

	mmi_brw_bookmarks_browse_path_entry_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_folder_or_show_options
 * DESCRIPTION
 *  If the selected item is a folder then it will open that folder otherwise
 *  it will show the file options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_folder_or_show_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_bkm_cntx.total_file_count)
	{
		g_brw_bkm_cntx.sel_file_index = (S32)GetHighlightedItem();

		/*if selected file is not a folder then please show the options menu*/
		if(g_brw_bkm_cntx.file_info_list[g_brw_bkm_cntx.sel_file_index].file_extn != BRW_BKM_FILE_EXTN_NONE)
		{
			mmi_brw_bookmarks_pre_entry_options();
			return;
		}

		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)get_dynamic_item_text(g_brw_bkm_cntx.sel_file_index));

		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)L"\\");
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);

		mmi_brw_bookmarks_get_file_extn_string(
			g_brw_bkm_cntx.file_info_list[g_brw_bkm_cntx.sel_file_index].file_extn, g_brw_bkm_cntx.sel_file_extn);

		/*here it is used for highlighting the default menu item*/
		mmi_brw_entry_dummy_screen();

		mmi_brw_bookmarks_open_folder();

	} /*if(g_brw_bkm_cntx.total_file_count)*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_folder
 * DESCRIPTION
 *  It opens the selected bookmark folder to display all bookmark files and
 *  directories
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.sel_file_name);

	/*highlighting the first element on entering*/
	g_brw_bkm_cntx.index_highlighted_item = 0;

	/*displaying the bookmark list*/
	mmi_brw_bookmarks_entry_show_list();	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_open_folder_directly
 * DESCRIPTION
 *  It opens the selected folder directly by pressing right arrow key while 
 *  copying or moving a bookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_open_folder_directly(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_brw_bkm_browse_path_cntx.total_folder_count)
	{
		g_brw_bkm_browse_path_cntx.sel_folder_index = (S32)GetHighlightedItem();

		mmi_ucs2cpy((S8*)g_brw_bkm_browse_path_cntx.sel_folder_name, (S8*)get_item_text(g_brw_bkm_browse_path_cntx.sel_folder_index));

		/*here it is used for highlighting the default menu item*/
		mmi_brw_entry_dummy_screen();

		/*highlighting the first element on entering*/
		g_brw_bkm_browse_path_cntx.index_highlighted_item = 0;

		mmi_brw_bookmarks_browse_path_open_folder();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_delete_folder
 * DESCRIPTION
 *  It deletes the selected bookmark folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	result = FS_XDelete((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_FILE_TYPE|FS_DIR_TYPE|FS_RECURSIVE_TYPE, NULL, 0);
	if(result >= 0)
	{
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(result);
	}
	DeleteUptoScrID(SCR_ID_BRW_BOOKMARKS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_select_folder
 * DESCRIPTION
 *  It deletes the selected bookmark folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_select_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE	file_handle;
	U8 dest_file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_extract_file_extn_from_filepath(g_brw_bkm_cntx.sel_file_path, file_extn_string);
	mmi_ucs2cpy((S8*)dest_file_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_name);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L".");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)file_extn_string);

	/*Checking the maximum allowable full path length for the file*/
    if ( mmi_ucs2strlen((S8*) dest_file_path) >= FMGR_MAX_PATH_LEN )
    {
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_FILE_PATH_LEN_EXCEEDED), 
			IMG_GLOBAL_ERROR, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			ERROR_TONE);
        return;
    }

	file_handle = FS_Open((UI_string_type)dest_file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		FS_Close(file_handle);
		mmi_brw_bookmarks_replace_file_confirm();
	}
	else
	{
		if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO)
		{
			mmi_fmgr_send_copy_req(
				FMGR_ACTION_COPY,
				(U8*) g_brw_bkm_cntx.sel_file_path,
				(U8*) dest_file_path,
				mmi_brw_bookmarks_copy_bookmark_file_rsp);
		}
		else if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_MOVE_TO)
		{
			mmi_fmgr_send_copy_req(
				FMGR_ACTION_MOVE,
				(U8*) g_brw_bkm_cntx.sel_file_path,
				(U8*) dest_file_path,
				mmi_brw_bookmarks_move_bookmark_file_rsp);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_copy_bookmark_file_rsp
 * DESCRIPTION
 *  response handler for copying a bookmark file
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_copy_bookmark_file_rsp(void *info)
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
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);

		/*updating the current selected bookmark folder path*/
		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)L"\\");
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_name);

		/*highlighting the first element on entering the bookmark list*/
		g_brw_bkm_cntx.index_highlighted_item = 0;

		/*displaying the copied folder contents*/
		mmi_brw_bookmarks_entry_show_list();
    }
    else
    {
		mmi_brw_bookmarks_file_system_error_handler(msgPtr->result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_move_bookmark_file_rsp
 * DESCRIPTION
 *  response handler for moving a bookmark file
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_move_bookmark_file_rsp(void *info)
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
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);

		/*updating the current selected bookmark folder path*/
		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)L"\\");
		mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_name);

		/*highlighting the first element on entering the bookmark list*/
		g_brw_bkm_cntx.index_highlighted_item = 0;

		/*displaying the moved folder contents*/
		mmi_brw_bookmarks_entry_show_list();
    }
    else
    {
		mmi_brw_bookmarks_file_system_error_handler(msgPtr->result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_replace_file
 * DESCRIPTION
 *  it replaces the existing bookmark file with the new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_replace_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//FS_HANDLE	file_handle;
	U8 dest_file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 file_extn_string[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * ENCODING_LENGTH];
	S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_extract_file_extn_from_filepath(g_brw_bkm_cntx.sel_file_path, file_extn_string);
	mmi_ucs2cpy((S8*)dest_file_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_name);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L".");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)file_extn_string);

	if(!mmi_ucs2icmp((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)dest_file_path))
	{
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);

		/*highlighting the first element on entering the bookmark list*/
		g_brw_bkm_cntx.index_highlighted_item = 0;

		/*displaying the bookmark list*/
		mmi_brw_bookmarks_entry_show_list();

		return;
	}

	error_code = FS_Delete((UI_string_type)dest_file_path);
	if(error_code < 0)
	{
		mmi_brw_bookmarks_file_system_error_handler(error_code);
		return;
	}

	if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_COPY_TO)
	{
		mmi_fmgr_send_copy_req(
			FMGR_ACTION_COPY,
			(U8*) g_brw_bkm_cntx.sel_file_path,
			(U8*) dest_file_path,
			mmi_brw_bookmarks_copy_bookmark_file_rsp);
	}
	else if(g_brw_bkm_browse_path_event == BRW_BKM_BROWSE_PATH_MOVE_TO)
	{
		mmi_fmgr_send_copy_req(
			FMGR_ACTION_MOVE,
			(U8*) g_brw_bkm_cntx.sel_file_path,
			(U8*) dest_file_path,
			mmi_brw_bookmarks_move_bookmark_file_rsp);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_browse_path_open_folder
 * DESCRIPTION
 *  It deletes the selected bookmark folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_browse_path_open_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U32 temp_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cat((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)g_brw_bkm_browse_path_cntx.sel_folder_path, (S8*)g_brw_bkm_browse_path_cntx.sel_folder_name);

	/*highlighting the first element on entering*/
	g_brw_bkm_browse_path_cntx.index_highlighted_item = 0;

	mmi_brw_bookmarks_entry_browse_path();	
}


#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_as_sms
 * DESCRIPTION
 *  it sends the bookmark file as a text message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_as_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_standardize_file_before_sending())
	{
		/* call send via sms API */
        mmi_ems_vobject_send_by_ems(
			VOBJ_SRC_PORT, 
			VOBJ_VBKM_PORT, 
			(S8*)g_brw_bkm_cntx.sel_file_path, 
			mmi_brw_bookmarks_send_bookmark_as_sms_callback);
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_as_sms_callback
 * DESCRIPTION
 *  callback function for sending bookmark file as SMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_as_sms_callback(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_SEND_BOOKMARK_OPTIONS);
}
#endif


#if defined(__MMI_MMS__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_as_mms
 * DESCRIPTION
 *  it sends the bookmark file as a multimedia message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_as_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_standardize_file_before_sending())
	{
		/* call send as mms API */
		mms_content_insert_hdlr((S8*)g_brw_bkm_cntx.sel_file_path);
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_as_mms_callback
 * DESCRIPTION
 *  callback function for sending bookmark file as MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_as_mms_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DisplayPopup(
		(PU8) GetString(STR_GLOBAL_DONE), 
		IMG_GLOBAL_ACTIVATED, 
		1, 
		UI_POPUP_NOTIFYDURATION_TIME, 
		SUCCESS_TONE);
	DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPTIONS);
}
#endif


#if  defined(__MMI_IRDA_SUPPORT__)	 
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_infrared
 * DESCRIPTION
 *  it sends the bookmark file via infrared
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_infrared(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_standardize_file_before_sending())
	{
		/* call send via infrared API */
        if ( MMI_IRDA_ERR_SUCCESS == 
			 mmi_irda_send_file_obj((S8*)g_brw_bkm_cntx.sel_file_path, mmi_brw_bookmarks_send_bookmark_via_infrared_callback)
			)
        {
            mmi_brw_entry_irda_processing_screen();
        }
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_infrared_callback
 * DESCRIPTION
 *  callback function for sending bookmark file via infrared
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_infrared_callback(void* buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free buffer if send to IrDA by using SRAM */
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    if (result == MMI_IRDA_ERR_SUCCESS)
    {
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
					TRUE,
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }

    DeleteBetweenScreen(SCR_ID_BRW_BOOKMARK_SEND_BOOKMARK_OPTIONS, SCR_ID_BRW_IRDA_FORWARD_PROCESSING);
}
#endif


#ifdef __MMI_OPP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_bluetooth
 * DESCRIPTION
 *  it sends the bookmark file via bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_bluetooth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_standardize_file_before_sending())
	{
		/* call send via bluetooth API */
        if ( MMI_OPP_ERR_SUCCESS == 
			 mmi_opp_discovery_device((S8*) g_brw_bkm_cntx.sel_file_path, mmi_brw_bookmarks_send_bookmark_via_bluetooth_callback)
			)
        {
            mmi_opp_entry_opp_device_discovery();
        }
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_bluetooth_callback
 * DESCRIPTION
 *  callback function for sending bookmark file via bluetooth
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_bluetooth_callback(void *buf_p, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free buffer if send to bt by using SRAM */
    if (buf_p != NULL)
    {
        OslMfree(buf_p);
        buf_p = NULL;
    }

    if (result == MMI_OPP_ERR_SUCCESS)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    DeleteBetweenScreen(SCR_ID_BRW_BOOKMARK_SEND_BOOKMARK_OPTIONS, SCR_OPP_SENDING);
}
#endif


#if  defined(__MMI_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_email
 * DESCRIPTION
 *  it sends the bookmark file via email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_standardize_file_before_sending())
	{
		/* call send via email API */
		mmi_email_app_send_attch((S8*)g_brw_bkm_cntx.sel_file_path);
	}
	else
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_FILE_SYSTEM_ERROR),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_send_bookmark_via_email_callback
 * DESCRIPTION
 *  callback function for sending bookmark file via email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_send_bookmark_via_email_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DisplayPopup(
		(PU8) GetString(STR_GLOBAL_DONE), 
		IMG_GLOBAL_ACTIVATED, 
		1, 
		UI_POPUP_NOTIFYDURATION_TIME, 
		SUCCESS_TONE);
	DeleteUptoScrID(SCR_ID_BRW_BOOKMARK_OPTIONS);
}
#endif /* __MMI_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_standardize_file_before_sending
 * DESCRIPTION
 *  it converts the bookmark file into standard format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_standardize_file_before_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_WRITE);
	if(file_handle < 0)
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return MMI_FALSE;
	}
	else
	{
		if(mmi_vbkm_writer_convert_file_to_standard_format(
			file_handle, g_brw_bkm_cntx.sel_file_name, g_brw_bkm_cntx.sel_file_url))
		{
		    FS_Close(file_handle);
		    return MMI_TRUE;
	    }
		else
		{
			FS_Close(file_handle);
			return MMI_FALSE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_create_standard_vbookmark_file
 * DESCRIPTION
 *  it creates a standard vbookmark file for other modules
 * PARAMETERS
 *  file_name	[IN]	path string where vbookmark file has to be created		
 *	url			[IN]	url string which has to be included in the file contents
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_create_standard_vbookmark_file(U8* file_path, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
	U8 file_dir[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 file_name[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 file_extn[(BRW_BKM_MAX_FILE_EXTN_LEN+1)*ENCODING_LENGTH];
	//U8 file_index_ascii[10];
	//U8 file_index_ucs2[10*ENCODING_LENGTH];
	//U16 file_index = 0;
	//U8 file_sufx_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_extract_file_directory_from_filepath(file_path, file_dir);
	mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(file_path, file_name);
	mmi_brw_bookmarks_extract_file_extn_from_filepath(file_path, file_extn);

	file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE | FS_CREATE);
	if(file_handle < 0)
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return MMI_FALSE;
	}
	else
	{
		if(mmi_vbkm_writer_convert_file_to_standard_format(file_handle, file_name, url))
		{
		    FS_Close(file_handle);
		    return MMI_TRUE;
	    }
		else
		{
			FS_Close(file_handle);
			FS_Delete((UI_string_type)file_path);
			return MMI_FALSE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_extract_filename_without_extn_from_filepath
 * DESCRIPTION
 *  it extracts file name from its path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(U8* file_path, U8* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_string_type start_loc;
	UI_string_type end_loc;
	S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	start_loc = (UI_string_type)mmi_ucs2rchr((const S8*)file_path, (U16)'\\');
	if(start_loc)
	{
		end_loc = (UI_string_type)mmi_ucs2rchr((const S8*)start_loc, (U16)'.');
		if(end_loc)
		{
			len = end_loc - start_loc - 1;
			mmi_ucs2ncpy((S8*)file_name, (S8*)start_loc+ENCODING_LENGTH, len);
		}
		else
		{
			mmi_ucs2cpy((S8*)file_name, (S8*)start_loc+ENCODING_LENGTH);
		}
		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_extract_filename_with_extn_from_filepath
 * DESCRIPTION
 *  it extracts file name with extension(if any) from its file path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_extract_filename_with_extn_from_filepath(U8* file_path, U8* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_string_type start_loc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	start_loc = (UI_string_type)mmi_ucs2rchr((const S8*)file_path, (U16)'\\');
	if(start_loc)
	{
		mmi_ucs2cpy((S8*)file_name, (S8*)start_loc+ENCODING_LENGTH);
		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_extract_file_extn_from_filepath
 * DESCRIPTION
 *  it extracts file name from its path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_extract_file_extn_from_filepath(U8* file_path, U8* file_extn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_string_type start_loc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	start_loc = (UI_string_type)mmi_ucs2rchr((const S8*)file_path, (U16)'.');
	if(start_loc)
	{
		mmi_ucs2cpy((S8*)file_extn, (S8*)start_loc+ENCODING_LENGTH);
		mmi_brw_UCS2Strtolower((S8*)file_extn);
		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_extract_file_directory_from_filepath
 * DESCRIPTION
 *  it extracts file directory from its path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_extract_file_directory_from_filepath(U8* file_path, U8* file_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_string_type end_loc;
	U32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	end_loc = (UI_string_type)mmi_ucs2rchr((const S8*)file_path, (U16)'\\');
	if(end_loc)
	{
		len = end_loc - (UI_string_type)file_path;
		mmi_ucs2ncpy((S8*)file_dir, (S8*)file_path, len);
		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_copy_recv_file_to_dest
 * DESCRIPTION
 *  it copies the received bookmark at the given destination path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_copy_recv_file_to_dest(U8* src_file_path, U8* dest_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
	U8 temp_file_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U8 dest_file_dir[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 dest_file_name[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 dest_file_extn[(BRW_BKM_MAX_FILE_EXTN_LEN+1)*ENCODING_LENGTH];
	U8 file_index_ascii[10];
	U8 file_index_ucs2[10*ENCODING_LENGTH];
	U16 file_index = 0;
	U8 file_sufx_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_extract_file_directory_from_filepath(dest_file_path, dest_file_dir);
	mmi_brw_bookmarks_extract_file_extn_from_filepath(dest_file_path, dest_file_extn);

	mmi_ucs2cpy((S8*)temp_file_path, (S8*)dest_file_path);

	while(1)
	{
		file_handle = FS_Open((UI_string_type)temp_file_path, FS_READ_ONLY);
		if(file_handle >= 0)
		{
			++file_index;
			sprintf((S8*)file_index_ascii,"(%d)", file_index);
			file_sufx_len = strlen((S8*)file_index_ascii);
			mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(dest_file_path, dest_file_name);
			if(mmi_ucs2strlen((S8*)dest_file_name) > (BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len))
			{
				dest_file_name[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len) * ENCODING_LENGTH] = '\0';
				dest_file_name[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len) * ENCODING_LENGTH + 1] = '\0';
			}
			mmi_asc_to_ucs2((S8*)file_index_ucs2, (S8*)file_index_ascii);			
			mmi_ucs2cat((S8*)dest_file_name, (S8*)file_index_ucs2);
			
			mmi_ucs2cpy((S8*)temp_file_path, (S8*)dest_file_dir);
			mmi_ucs2cat((S8*)temp_file_path, (S8*)L"\\");
			mmi_ucs2cat((S8*)temp_file_path, (S8*)dest_file_name);
			mmi_ucs2cat((S8*)temp_file_path, (S8*)L".");
			mmi_ucs2cat((S8*)temp_file_path, (S8*)dest_file_extn);
			FS_Close(file_handle);
			continue;
		}
		else
		{
			mmi_ucs2cpy((S8*)dest_file_path, (S8*)temp_file_path);
			mmi_fmgr_send_copy_req(
				FMGR_ACTION_COPY,
				(U8*) src_file_path,
				(U8*) dest_file_path,
				mmi_brw_bookmarks_copy_recv_file_to_dest_rsp);
			break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_copy_recv_file_to_dest_rsp
 * DESCRIPTION
 *  response handler for copying a received bookmark file
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_copy_recv_file_to_dest_rsp(void *info)
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
		DisplayPopup(
			(PU8) GetString(STR_GLOBAL_DONE), 
			IMG_GLOBAL_ACTIVATED, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			SUCCESS_TONE);

		if(g_brw_bkm_caller_id == BRW_BKM_FROM_VBOOKMARK)
		{
			DeleteUptoScrID(g_brw_bkm_scr_id);
			mmi_vbkm_clean_one_file_buffer();
		}
		else
		{
			DeleteNHistory(1);
		}
    }
    else
    {
		mmi_brw_bookmarks_file_system_error_handler(msgPtr->result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_recv_file_save_to_fmgr
 * DESCRIPTION
 *  This function is an external interface for saving a received vbookmark
 *  file to file manager
 * PARAMETERS
 *  file_path		[IN]	file path in UCS2
 *  file_name		[IN]	file name in UCS2
 *  file_extn		[IN]	file extension in UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_recv_file_save_to_fmgr(U8* file_path, U8* file_name, U8* file_extn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
	U8 file_path_ascii[(BRW_BKM_MAX_PATH_LEN+1) * BRW_UTF8_ENCODING_LENGTH];
	U8 file_name_ascii[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1) * BRW_UTF8_ENCODING_LENGTH];
	U8 file_extn_ascii[(BRW_BKM_MAX_FILE_EXTN_LEN+1) * BRW_UTF8_ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(file_path);
	MMI_ASSERT(file_name);
	MMI_ASSERT(file_extn);

	mmi_chset_ucs2_to_utf8_string((U8*)file_path_ascii, (BRW_BKM_MAX_PATH_LEN+1) * BRW_UTF8_ENCODING_LENGTH, (U8*)file_path);
	mmi_chset_ucs2_to_utf8_string((U8*)file_name_ascii, (BRW_BKM_MAX_INPUT_FILE_NAME_LEN+1) * BRW_UTF8_ENCODING_LENGTH, (U8*)file_name);
	mmi_chset_ucs2_to_utf8_string((U8*)file_extn_ascii, (BRW_BKM_MAX_FILE_EXTN_LEN+1) * BRW_UTF8_ENCODING_LENGTH, (U8*)file_extn);

    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserBookmarks.c] mmi_brw_bookmarks_recv_file_save_to_fmgr file_path = %s\n", file_path_ascii);
    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserBookmarks.c] mmi_brw_bookmarks_recv_file_save_to_fmgr file_name = %s\n", file_name_ascii);
    PRINT_INFORMATION_2(TRACE_GROUP_9, "*[BrowserBookmarks.c] mmi_brw_bookmarks_recv_file_save_to_fmgr file_extn = %s\n", file_extn_ascii);

	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)file_path);
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)file_name);
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_extn, (S8*)file_extn);

	g_brw_bkm_scr_id = IDLE_SCREEN_ID;
	g_brw_bkm_caller_id = BRW_BKM_FROM_VBOOKMARK;

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

	mmi_fmgr_select_path_and_enter
	(
       1,
       FMGR_SELECT_FOLDER | FMGR_SELECT_REPEAT,
       filter,
       (PS8) L"root",
       mmi_brw_bookmarks_recv_file_save_to_fmgr_callback
	);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_recv_file_save_to_fmgr_callback
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_recv_file_save_to_fmgr_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 dest_file_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	//UI_string_type file_name_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(fullname)
	{
		mmi_ucs2cpy((S8*)dest_file_path, (S8*)fullname);
		mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);
		mmi_ucs2cat((S8*)dest_file_path, (S8*)L".");
		mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.sel_file_extn);
		mmi_brw_bookmarks_copy_recv_file_to_dest(g_brw_bkm_cntx.sel_file_path, dest_file_path);
	}
	else
	{
		GoBackHistory();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_validate_filename
 * DESCRIPTION
 *  Call back for Book shelf Screen
 * PARAMETERS
 *  fullname        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_validate_filename(U8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 len;
	MMI_BOOL err_flag = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = (S32)mmi_ucs2strlen((S8*)filename);
	while(len--)
	{
        if ( (filename[len << 1] == '/' && filename[(len << 1) + 1] == 0) || 
			 (filename[len << 1] == '\\' && filename[(len << 1) + 1] == 0)
			)
		{
			err_flag = MMI_TRUE;
			break;
		}	
	}
	len = (S32)mmi_ucs2strlen((S8*)filename);
    if ( (len == 0) || 
		 ((len == 1) && (filename[0] == '.')) ||
		 err_flag 
	    )
	{
		return MMI_FALSE;
	}

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_goto_from_fmgr
 * DESCRIPTION
 *  This function is an external interface for file manager to fetch the URL
 *  given in selected vbookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_goto_from_fmgr(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
	U8 url_ascii[BRW_MAX_URL_LENGTH + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(fullname);

	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	g_brw_bkm_scr_id = GetActiveScreenId();
	g_brw_bkm_caller_id = BRW_BKM_FROM_FILE_MANAGER;

	mmi_ucs2cpy((S8 *)g_brw_bkm_cntx.sel_file_path, (S8 *)fullname);
	file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_reader_validate_file(file_handle))
		{
			mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);
			mmi_chset_ucs2_to_utf8_string((U8*)url_ascii, BRW_MAX_URL_LENGTH+1, (U8*)g_brw_bkm_cntx.sel_file_url);
			mmi_brw_load_url((U8*)url_ascii);
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
		}
		FS_Close(file_handle);
		return;
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_from_fmgr
 * DESCRIPTION
 *  This function is an external interface for file manager to display the Open
 *  menu for the selected vbookmark file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_from_fmgr(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(fullname);

	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	g_brw_bkm_scr_id = GetActiveScreenId();
	g_brw_bkm_caller_id = BRW_BKM_FROM_FILE_MANAGER;

	mmi_ucs2cpy((S8 *)g_brw_bkm_cntx.sel_file_path, (S8 *)fullname);
	file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_reader_validate_file(file_handle))
		{
			mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(
				g_brw_bkm_cntx.sel_file_path, g_brw_bkm_cntx.sel_file_name);
			mmi_brw_bookmarks_extract_file_extn_from_filepath(
				g_brw_bkm_cntx.sel_file_path, g_brw_bkm_cntx.sel_file_extn);
			mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);
			mmi_brw_bookmarks_extract_file_directory_from_filepath(
				g_brw_bkm_cntx.sel_file_path, g_brw_bkm_cntx.sel_folder_path);
			mmi_brw_bookmarks_entry_open_from_fmgr();
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
		}
		FS_Close(file_handle);
		return;
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_goto_from_fmgr
 * DESCRIPTION
 *  This function is used to fetch the URL given in selected vbookmark file
 *  invoked from Open menu of file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_goto_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 url_ascii[BRW_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_chset_ucs2_to_utf8_string((U8*)url_ascii, BRW_MAX_URL_LENGTH+1, (U8*)g_brw_bkm_cntx.sel_file_url);
	mmi_brw_load_url((U8*)url_ascii);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr
 * DESCRIPTION
 *  This function is used to save the selected vbookmark file into bookmark 
 *  application invoked from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_open_save_to_bookmark_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	/*create vbookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else 
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			return;
        }
    }

	mmi_brw_bookmarks_pre_entry_save_to_bookmark();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_use_now_save_to_bookmark
 * DESCRIPTION
 *  This function is an external interface to save the downloaded vbookmark file 
 *  into Bookmark Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_use_now_save_to_bookmark(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(fullname);

	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	g_brw_bkm_scr_id = GetActiveScreenId();
	g_brw_bkm_caller_id = BRW_BKM_FROM_FILE_MANAGER;

	/*create vbookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else 
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			return;
        }
    }

	mmi_ucs2cpy((S8 *)g_brw_bkm_cntx.sel_file_path, (S8 *)fullname);
	file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_reader_validate_file(file_handle))
		{
			mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(
				g_brw_bkm_cntx.sel_file_path, g_brw_bkm_cntx.sel_file_name);
			mmi_brw_bookmarks_extract_file_extn_from_filepath(
				g_brw_bkm_cntx.sel_file_path, g_brw_bkm_cntx.sel_file_extn);
			mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);
			mmi_brw_bookmarks_extract_file_directory_from_filepath(
				g_brw_bkm_cntx.sel_file_path, g_brw_bkm_cntx.sel_folder_path);
			mmi_brw_bookmarks_entry_save_to_bookmark();
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
		}
		FS_Close(file_handle);
		return;
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_add_to_bookmark
 * DESCRIPTION
 *  This function is the external interface for adding bookmark from other 
 *  applications with user interface
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_add_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	g_brw_bkm_scr_id = GetActiveScreenId();
	g_brw_bkm_add_type = BRW_BKM_ADD_TO_BOOKMARK;

	/*create vbookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			return;
        }
    }

	mmi_brw_bookmarks_entry_add_bookmark();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_add_to_bookmark_silently
 * DESCRIPTION
 *  This function is the external interface for adding bookmark from other 
 *  applications without user interface
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_brw_bookmarks_add_to_bookmark_silently(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
	U8 dest_file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 temp_file_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U8 file_index_ascii[10];
	U8 file_index_ucs2[10*ENCODING_LENGTH];
	U16 file_index = 0;
	U8 file_sufx_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();
 
	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		return BRW_ADD_TO_BKM_MEMORY_FULL;
	}

	if(mmi_brw_validate_url(g_brw_current_url) < 0)
	{
		return BRW_ADD_TO_BKM_INVALID_URL;
	}

	/*create vbookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else 
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			return BRW_ADD_TO_BKM_FILE_SYSTEM_ERROR;
        }
    }

	if(!mmi_ucs2strlen((S8*)g_brw_current_title))
	{
		mmi_ucs2cpy((S8*)g_brw_current_title, (S8*)BRW_BKM_DEFAULT_FILE_NAME);
	}

	mmi_ucs2cpy((S8*)dest_file_path, (S8*)g_brw_bkm_cntx.default_folder_path);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)g_brw_current_title);
	mmi_ucs2cat((S8*)dest_file_path, (S8*)L".");
	mmi_ucs2cat((S8*)dest_file_path, (S8*)BRW_BKM_DEFAULT_FILE_EXTN);

	mmi_ucs2cpy((S8*)temp_file_path, (S8*)dest_file_path);

	while(1)
	{
		file_handle = FS_Open((UI_string_type)temp_file_path, FS_READ_ONLY);
		if(file_handle >= 0)
		{
			++file_index;
			sprintf((S8*)file_index_ascii,"(%d)", file_index);
			file_sufx_len = strlen((S8*)file_index_ascii);
			mmi_brw_bookmarks_extract_filename_without_extn_from_filepath(dest_file_path, g_brw_current_title);
			if(mmi_ucs2strlen((S8*)g_brw_current_title) > (BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len))
			{
				g_brw_current_title[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len) * ENCODING_LENGTH] = '\0';
				g_brw_current_title[(BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len) * ENCODING_LENGTH + 1] = '\0';
			}
			mmi_asc_to_ucs2((S8*)file_index_ucs2, (S8*)file_index_ascii);			
			mmi_ucs2cat((S8*)g_brw_current_title, (S8*)file_index_ucs2);

			mmi_ucs2cpy((S8*)temp_file_path, (S8*)g_brw_bkm_cntx.default_folder_path);
			mmi_ucs2cat((S8*)temp_file_path, (S8*)L"\\");
			mmi_ucs2cat((S8*)temp_file_path, (S8*)g_brw_current_title);
			mmi_ucs2cat((S8*)temp_file_path, (S8*)L".");
			mmi_ucs2cat((S8*)temp_file_path, (S8*)BRW_BKM_DEFAULT_FILE_EXTN);
			FS_Close(file_handle);
			continue;
		}
		else
		{
			mmi_ucs2cpy((S8*)dest_file_path, (S8*)temp_file_path);

			file_handle = FS_Open((UI_string_type)dest_file_path, FS_READ_WRITE | FS_CREATE);
			if(file_handle < 0)
			{
				if(file_handle == FS_INVALID_FILENAME)
				{
					return BRW_ADD_TO_BKM_INVALID_TITLE;
				}
				else
				{
					return BRW_ADD_TO_BKM_FILE_SYSTEM_ERROR;
				}
			}
			else
			{
				if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, g_brw_current_url))
				{
				    FS_Close(file_handle);
				    return BRW_ADD_TO_BKM_SUCCESS;
			    }
				else
				{
					FS_Close(file_handle);
					FS_Delete((UI_string_type)dest_file_path);
					return BRW_ADD_TO_BKM_FILE_SYSTEM_ERROR;
				}
			}
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_file_system_error_handler
 * DESCRIPTION
 *  it displays popups for corresponding file system errors
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_file_system_error_handler(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
        (PU8) GetString((U16)GetFileSystemErrorString(error_code)),
        IMG_GLOBAL_ERROR,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) ERROR_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_GoBackHistory
 * DESCRIPTION
 *  it de-allocates the memory for bookmark list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_bookmarks_free_memory();
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_free_memory
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_brw_mfree(g_brw_bkm_cntx.file_info_list);
	g_brw_bkm_cntx.file_info_list = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_select_bookmark
 * DESCRIPTION
 *  This function is the external interface for selecting a bookmark from
 *  bookmark list by some other application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_select_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*initalizing bookmark context*/
	mmi_brw_bookmarks_context_init();

	g_brw_bkm_cntx.total_file_count = mmi_brw_bookmarks_get_file_and_folder_count(g_brw_bkm_cntx.sel_folder_path);

	if(g_brw_bkm_cntx.total_file_count)
	{
		if(!g_brw_memory_pool)
		{
#ifdef APPMEM_SUPPORT
		    g_brw_memory_pool = 
			    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BROWSER, WAP_CUSTOM_CFG_BROWSER_MEM_SIZE + g_brw_memory_pool_size);
		    if(!g_brw_memory_pool)
		    {
			    mmi_frm_appmem_prompt_to_release_mem(
				    APPLIB_MEM_AP_ID_BROWSER,
				    SERVICES_WAP_IMAGE_ID,
				    WAP_CUSTOM_CFG_BROWSER_MEM_SIZE + g_brw_memory_pool_size,
				    mmi_brw_bookmarks_select_bookmark_asm_memory_pool_request_success_callback);
			    return;
		    }
		    else
		    {
				g_brw_bkm_sel_bkm_pool = MMI_TRUE;
			    setAppMemPool(g_brw_memory_pool);
		    }
#endif /* APPMEM_SUPPORT */

		    g_brw_cntx.brw_adm_id = 
			    kal_adm_create((char *)g_brw_memory_pool + WAP_CUSTOM_CFG_BROWSER_MEM_SIZE, g_brw_memory_pool_size, NULL, KAL_FALSE);
		    MMI_ASSERT(g_brw_cntx.brw_adm_id);
    
			/*highlighting the first element on entering*/
			g_brw_bkm_cntx.index_highlighted_item = 0;

		    mmi_brw_bookmarks_entry_select_bookmark();
	    }
	    else
	    {
			/*highlighting the first element on entering*/
			g_brw_bkm_cntx.index_highlighted_item = 0;

			mmi_brw_bookmarks_entry_select_bookmark();
		}
	}
	else
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_EMPTY), 
			IMG_GLOBAL_EMPTY, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			EMPTY_LIST_TONE);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_select_bookmark_asm_memory_pool_request_success_callback
 * DESCRIPTION
 *  Pre Entry function for Internet services screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_select_bookmark_asm_memory_pool_request_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_brw_memory_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BROWSER, 
		WAP_CUSTOM_CFG_BROWSER_MEM_SIZE + g_brw_memory_pool_size);
	MMI_ASSERT(g_brw_memory_pool);

	g_brw_bkm_sel_bkm_pool = MMI_TRUE;
	setAppMemPool(g_brw_memory_pool);

	g_brw_cntx.brw_adm_id = 
		kal_adm_create((char *)g_brw_memory_pool + WAP_CUSTOM_CFG_BROWSER_MEM_SIZE, g_brw_memory_pool_size, NULL, KAL_FALSE);
	MMI_ASSERT(g_brw_cntx.brw_adm_id);

	/*highlighting the first element on entering*/
	g_brw_bkm_cntx.index_highlighted_item = 0;

	mmi_brw_bookmarks_entry_select_bookmark();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_select_bookmark_open_folder
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_select_bookmark_open_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8  temp_folder_path[(BRW_BKM_MAX_PATH_LEN+1) * ENCODING_LENGTH];
	U32 temp_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)get_dynamic_item_text(g_brw_bkm_cntx.sel_file_index));

	mmi_ucs2cpy((S8*)temp_folder_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)temp_folder_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)temp_folder_path, (S8*)g_brw_bkm_cntx.sel_file_name);

	temp_count = mmi_brw_bookmarks_get_file_and_folder_count(temp_folder_path);

	if(temp_count)
	{
		g_brw_bkm_cntx.total_file_count = temp_count;
		mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)temp_folder_path);

		/*here it is used for highlighting the default menu item*/
		mmi_brw_entry_dummy_screen();

		/*highlighting the first element on entering*/
		g_brw_bkm_cntx.index_highlighted_item = 0;

		mmi_brw_bookmarks_entry_select_bookmark();
	}
	else
	{
		DisplayPopup(
			(PU8) GetString(STR_ID_BRW_EMPTY), 
			IMG_GLOBAL_EMPTY, 
			1, 
			UI_POPUP_NOTIFYDURATION_TIME, 
			EMPTY_LIST_TONE);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_select_bookmark_done
 * DESCRIPTION
 *  Showing title with appropiate normal title icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_select_bookmark_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_name, (S8*)get_dynamic_item_text(g_brw_bkm_cntx.sel_file_index));

	mmi_ucs2cpy((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)L"\\");
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_file_name);

	mmi_brw_bookmarks_get_file_extn_string(
		g_brw_bkm_cntx.file_info_list[g_brw_bkm_cntx.sel_file_index].file_extn, g_brw_bkm_cntx.sel_file_extn);

	mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)L".");
	mmi_ucs2cat((S8*)g_brw_bkm_cntx.sel_file_path, (S8*)g_brw_bkm_cntx.sel_file_extn);

	file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.sel_file_path, FS_READ_ONLY);
	if(file_handle >= 0)
	{
		if(mmi_vbkm_reader_validate_file(file_handle))
		{
			mmi_vbkm_reader_extract_url(file_handle, g_brw_bkm_cntx.sel_file_url);
			FS_Close(file_handle);
			mmi_brw_bookmarks_free_memory();
			if(g_brw_bkm_sel_bkm_pool)
			{
			    mmi_brw_app_deinit();
			}
			mmi_brw_select_bookmark_rsp(1);
			return;
		}
		else
		{
			DisplayPopup(
				(PU8) GetString(STR_ID_BRW_INVALID_BOOKMARK_FILE), 
				IMG_GLOBAL_ERROR, 
				1, 
				UI_POPUP_NOTIFYDURATION_TIME, 
				ERROR_TONE);
			FS_Close(file_handle);
			return;
		}
	}
	else
	{
		mmi_brw_bookmarks_file_system_error_handler(file_handle);
		return;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_select_bookmark_rsp
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_select_bookmark_rsp(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_select_bookmark_rsp_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_select_bookmark_rsp_struct*) OslConstructDataPtr(sizeof(wap_select_bookmark_rsp_struct));

	if(result)
	{
		myMsgPtr->result = result;
		myMsgPtr->dcs = 1;
		mmi_ucs2cpy((S8*)myMsgPtr->title, (S8*)g_brw_bkm_cntx.sel_file_name);
		mmi_chset_ucs2_to_utf8_string((U8*)myMsgPtr->url, BRW_MAX_URL_LENGTH + 1, (U8*)g_brw_bkm_cntx.sel_file_url);
	}
	else
	{
		myMsgPtr->result = result;
	}

	mmi_brw_event_hdlr_send_ilm_to_mmi(MSG_ID_WAP_SELECT_BOOKMARK_RSP, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_select_bookmark_go_back_history
 * DESCRIPTION
 *  Its is called when user selects back option from select bookmark list screen.
 *  Its purpose is to displays appropiate screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_select_bookmark_go_back_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 folder_path[BRW_BKM_MAX_PATH_LEN+1];
	//U16 len=0;
	//S16 index;
	UI_string_type end_sep_loc;
	U8 sel_folder_name[(BRW_BKM_MAX_FILE_NAME_LEN+1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2cmp((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)g_brw_bkm_cntx.default_folder_path))
	{
		mmi_brw_bookmarks_free_memory();
		if(g_brw_bkm_sel_bkm_pool)
		{
		    mmi_brw_app_deinit();
		}
		mmi_brw_select_bookmark_rsp(0);
		GoBackHistory();
		return;
	}
	else
	{
		/*mmi_ucs2_to_asc((S8*)folder_path, (S8*)g_brw_bkm_cntx.sel_folder_path);
		len = strlen((S8*)folder_path);
		for(index = len-1; index >= 0; index--)
		{
			if(folder_path[index] == '\\')
			{
				folder_path[index] = '\0';
				break;
			}
		}
		mmi_asc_to_ucs2((S8*)g_brw_bkm_cntx.sel_folder_path, (S8*)folder_path);*/

		end_sep_loc = (UI_string_type)mmi_ucs2rchr((const S8*)g_brw_bkm_cntx.sel_folder_path, (U16)'\\');
		mmi_ucs2cpy((S8*)sel_folder_name, (S8*)end_sep_loc + ENCODING_LENGTH);
		*end_sep_loc = '\0';

		/*here it is used for highlighting the default menu item*/
		mmi_brw_entry_dummy_screen();

		g_brw_bkm_cntx.total_file_count = mmi_brw_bookmarks_get_file_and_folder_count(g_brw_bkm_cntx.sel_folder_path);

		/*highlighting the selected folder*/
		g_brw_bkm_cntx.index_highlighted_item = 
			mmi_brw_bookmarks_get_highlight_item((U8*)g_brw_bkm_cntx.sel_folder_path, (U8*)sel_folder_name);

		mmi_brw_bookmarks_entry_select_bookmark();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_available_memory
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_brw_bookmarks_get_available_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 avail_memory;
	S32 alloc_memory;
	S32 total_memory = BRW_BKM_FOLDER_QUOTA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	alloc_memory = FS_GetFolderSize((const WCHAR*)g_brw_bkm_cntx.default_folder_path, FS_COUNT_IN_BYTE, NULL, 0);
	avail_memory = total_memory - alloc_memory;

	return avail_memory;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_create_folder
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return;
	}

	mmi_brw_bookmarks_entry_create_folder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_folder_depth
 * DESCRIPTION
 *  This func is used for finding the depth of the given folder path with 
 *  respect to default vbookmark directory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_brw_bookmarks_get_folder_depth(U8* folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8* search_str_pos;
	U16 def_len;
	S16 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(folder_path);
	MMI_ASSERT(g_brw_bkm_cntx.default_folder_path);

	def_len = mmi_ucs2strlen((S8*)g_brw_bkm_cntx.default_folder_path);
	
	if(mmi_ucs2strlen((S8*)folder_path) > def_len)
	{
		count = 0;
		search_str_pos = (S8*) folder_path + (def_len * ENCODING_LENGTH);
		while(search_str_pos)
		{
			search_str_pos = (S8*) mmi_ucs2chr((S8*)search_str_pos, '\\');
			if(search_str_pos)
			{
				search_str_pos += ENCODING_LENGTH;
				count++;
			}
		}
		return count;
	}
	else if(mmi_ucs2strlen((S8*)folder_path) == def_len)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_create_default_bkms
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_create_default_bkms(void)
{
#ifdef BRW_DEFAULT_BKM_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 index;
	FS_HANDLE file_handle;
	U8 file_path[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
	U8 url[(BRW_MAX_URL_LENGTH+1)*ENCODING_LENGTH];
	U8 title[(BRW_MAX_TITLE_LENGTH+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*create bookmark folder if it is not being created*/
    file_handle = FS_Open((UI_string_type)g_brw_bkm_cntx.default_folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
    }
    else
    {
        if (FS_CreateDir((UI_string_type) g_brw_bkm_cntx.default_folder_path) < 0)
        {
			mmi_brw_bookmarks_file_system_error_handler(file_handle);
			return;
        }
    }

	/*create bookmark file for each available URL*/
	for(index = 0; index < wap_bkm_default.max_n_bkms; index++)
	{
		if(!wap_bkm_default.bkm[index].empty)
		{
			mmi_asc_to_ucs2((S8*)url, (S8*)wap_bkm_default.bkm[index].bkm_url);
			mmi_asc_to_ucs2((S8*)title, (S8*)wap_bkm_default.bkm[index].bkm_name);

			mmi_ucs2cpy((S8*)file_path, (S8*)g_brw_bkm_cntx.default_folder_path);
			mmi_ucs2cat((S8*)file_path, (S8*)"\\");
			mmi_ucs2cat((S8*)file_path, (S8*)title);
			mmi_ucs2cat((S8*)file_path, (S8*)".");
			mmi_ucs2cat((S8*)file_path, (S8*)BRW_BKM_FILE_EXTN_DFT_STRING);

			file_handle = FS_Open((UI_string_type)file_path, FS_READ_ONLY);
			if(file_handle < 0)
			{
				file_handle = FS_Open((UI_string_type)file_path, FS_READ_WRITE | FS_CREATE);
				if(file_handle >= 0)
				{
					if(mmi_vbkm_writer_convert_file_to_internal_format(file_handle, url))
					{
					    FS_Close(file_handle);
				    }
					else
					{
					    FS_Close(file_handle);
						FS_Delete((UI_string_type)file_path);
					}
				}
			}
			else
			{
				FS_Close(file_handle);
			}
		}
	}
#endif /* BRW_DEFAULT_BKM_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_check_available_memory
 * DESCRIPTION
 *  This func is an external interface for checking the available vbookmark 
 *  memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_brw_bookmarks_check_available_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_brw_bookmarks_get_available_memory() < BRW_BKM_FILE_SIZE)
	{
		DisplayPopup(
			(U8*) GetString(STR_ID_BRW_NOT_ENOUGH_MEM),
			(U16) IMG_GLOBAL_ERROR,
			0,
			UI_POPUP_NOTIFYDURATION_TIME,
			(U8) ERROR_TONE);
		return MMI_FALSE;
	}
	else
	{
		return MMI_TRUE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_get_highlight_item
 * DESCRIPTION
 *  This function is used for getting the index of the selected bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_brw_bookmarks_get_highlight_item(U8* sel_folder_path, U8* sel_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_DOSDirEntry file_info;
	U8 filename[(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH];
	U8 pattern[(BRW_BKM_MAX_PATH_LEN+1)*ENCODING_LENGTH];
    FS_HANDLE handle = 0;
	U8 find_next = MMI_FALSE;
	U16 highlighted = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!mmi_ucs2cmp((S8*)sel_folder_path, (S8*)g_brw_bkm_cntx.default_drive_name))
	{
		return 0;
	}

	mmi_ucs2cpy((S8*)pattern, (S8*)sel_folder_path);
	mmi_ucs2cat((S8*)pattern, (S8*)L"\\*");

	while(1)
	{
		if(!find_next)
		{
			if ((handle =  FS_FindFirst(
							(UI_string_type)pattern,
							FS_ATTR_DIR,
							0,
							&file_info,
							(UI_string_type) filename,
							(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH)) >= 0)
			{
				find_next = MMI_TRUE;
				if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
					mmi_ucs2cmp((S8*)filename, (S8*)L"..")
					)
				{
					if(!mmi_ucs2cmp((S8*)filename,(S8*)sel_file_name))
					{
						break;
					}
					highlighted++;
				}
			}
			else
			{
				FS_FindClose(handle);
				return 0;
			}
		}
		else //(!find_next)
		{
			if( FS_FindNext
				(handle, 
				&file_info, 
				(UI_string_type) filename, 
				(BRW_BKM_MAX_FILE_NAME_LEN+1)*ENCODING_LENGTH) >= 0 )
			{
				if( mmi_ucs2cmp((S8*)filename, (S8*)L".") && 
					mmi_ucs2cmp((S8*)filename, (S8*)L"..")
					)
				{
					if(!mmi_ucs2cmp((S8*)filename,(S8*)sel_file_name))
					{
						break;
					}
					highlighted++;
				}
			}
			else
			{
				FS_FindClose(handle);
				return 0;
			}
		}
	}
	FS_FindClose(handle);
	return highlighted;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_pre_entry_edit_from_fmgr
 * DESCRIPTION
 *  Pre Entry function for Edit bookmark screen from File Manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_brw_bookmarks_pre_entry_edit_from_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)g_brw_current_title, (S8*)g_brw_bkm_cntx.sel_file_name);
	mmi_ucs2cpy((S8*)g_brw_current_url, (S8*)g_brw_bkm_cntx.sel_file_url);

	mmi_brw_bookmarks_entry_edit_from_fmgr();
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERBOOKMARKS_C */