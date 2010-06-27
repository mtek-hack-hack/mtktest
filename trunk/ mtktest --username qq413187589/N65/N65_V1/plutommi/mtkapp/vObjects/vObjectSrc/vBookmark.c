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
 * vBookmark.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for sending and receiving vbookmark object.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VBOOKMARK_C
#define _MMI_VBOOKMARK_C


#if defined(__MMI_VBOOKMARK__)

/*  Include: MMI header file */
#include "CommonScreens.h"
//#include "FileSystemDef.h"
#include "vObjects.h"
#include "vBookmark.h"
#include "MessagesExDcl.h"
#include "IrdaMMIGprots.h"
#include "Conversions.h"
#include "app_qp.h"
#include "gui_data_types.h"     /* UI_character_type */
#if defined(__MMI_FILE_MANAGER__)
#include "FileManagerDef.h"     /* error string id */
#include "FileManagerGProt.h"
#endif /* defined(__MMI_FILE_MANAGER__) */ 
#include "fmt_struct.h"
#include "SettingProfile.h"

#if defined(__MMI_MMS__)
#include "Wapadp.h"
#if defined (OBIGO_SUPPORT)
#include "Wap.h"        /* MMS ID */
#include "CallManagementGProt.h"        /* To check if is in call for MMS */
#endif /* defined (OBIGO_SUPPORT) */ 
#endif /* defined(__MMI_MMS__) */ 

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"  /* wgui_register_list_item_selected_callback_all */
#endif 

#ifdef __MMI_OPP_SUPPORT__
#include "OPPMMIGprots.h"
#include "ExtDeviceDefs.h"
#endif /* __MMI_OPP_SUPPORT__ */ 

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#endif /* __SYNCML_SUPPORT__ */


/*
 * Global Variable
 */


/*
 * Local Variable
 */
static vbkm_context_struct g_vbkm_cntx;
static vbkm_recv_file_info_list_struct* g_vbkm_recv_file_info_list;
static vbkm_recv_medium_type_enum g_vbkm_recv_med;

const S8 *g_vbkm_field[VBKM_FIELD_TOTAL] = 
{
    "BEGIN",
    "VERSION",
    "TITLE",
    "URL",
    "X-IRMC-URL",
    "[InternetShortcut]",
    "END"
};

const S8 *g_vbkm_sub_field[VBKM_SUB_FIELD_TOTAL] = 
{
    "VBKM",
    "ENV",
    "CHARSET",
    "ENCODING",
};


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_init
 * DESCRIPTION
 *  Initialize function of vbookmark application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)g_vbkm_cntx.file_path, (S8*)L"");
	g_vbkm_recv_file_info_list = NULL;

    SetHiliteHandler(MENU_ID_VBKM_RECV_OPTION_VIEW, mmi_vbkm_recv_file_view_highlight_hdlr);
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
    SetHiliteHandler(MENU_ID_VBKM_RECV_OPTION_SAVE_TO_FMGR, mmi_vbkm_recv_file_save_to_fmgr_highlight_hdlr);
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__) */
    SetHiliteHandler(MENU_ID_VBKM_RECV_OPTION_SAVE_TO_BOOKMARK, mmi_vbkm_recv_file_save_to_bookmark_highlight_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_deinit
 * DESCRIPTION
 *  Deinitialize function of vbookmark application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*--------------------------------------------------BEGIN vBookmark Received operation ---------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_to_fmgr_highlight_hdlr
 * DESCRIPTION
 *  highlight function for save vbookmark to file manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_to_fmgr_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vbkm_recv_file_save_to_fmgr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vbkm_recv_file_save_to_fmgr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_to_fmgr
 * DESCRIPTION
 *  save vbookmark to file manager, file manager will take over screen after calling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_to_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 file_extn[(VBKM_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)g_vbkm_cntx.file_path, FS_READ_ONLY);
	if(fh >= 0)
	{
		mmi_vbkm_reader_extract_title(fh, title);
		if(mmi_ucs2strlen((S8*)title))
		{
			mmi_ucs2cpy((S8*)filename, (S8*)title);
			if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
			}
			else
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
			}
		}
		else if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
		{
			mmi_ucs2cpy((S8*)filename, (S8*)g_vbkm_recv_file_info_list->file_info.file_name);
			mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
		}	
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)VBKM_TEMP_FILE_NAME);
			mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
		}
		FS_Close(fh);
		mmi_brw_bookmarks_recv_file_save_to_fmgr(g_vbkm_cntx.file_path, filename, file_extn);
	}
	else
	{
		/* error handling */
	}
}
#endif /* defined(__MMI_FILE_MANAGER__) && defined(__FS_MOVE_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_view_highlight_hdlr
 * DESCRIPTION
 *  highlight function for viewing the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_view_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vbkm_recv_file_view, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vbkm_recv_file_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_view
 * DESCRIPTION
 *  function for viewing the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)g_vbkm_cntx.file_path, FS_READ_ONLY);
	if(fh >= 0)
	{
		mmi_vbkm_reader_extract_title(fh, title);
		if(mmi_ucs2strlen((S8*)title))
		{
			mmi_ucs2cpy((S8*)filename, (S8*)title);
		}
		else if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
		{
			mmi_ucs2cpy((S8*)filename, (S8*)g_vbkm_recv_file_info_list->file_info.file_name);
		}	
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)VBKM_TEMP_FILE_NAME);
		}
		FS_Close(fh);
		mmi_brw_bookmarks_recv_file_view(g_vbkm_cntx.file_path, filename);
	}
	else
	{
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(fh)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_to_bookmark_highlight_hdlr
 * DESCRIPTION
 *  highlight function for viewing the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_to_bookmark_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vbkm_recv_file_save_to_bookmark, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vbkm_recv_file_save_to_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_to_bookmark
 * DESCRIPTION
 *  function for viewing the bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_to_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	U8 file_extn[(VBKM_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*Here we are checking the available vbookmark memory.*/
	/*If there is not enough memory then a popup will be displayed by this API*/
	/*and it will also return MMI_FALSE.*/
	if(!mmi_brw_bookmarks_check_available_memory())
	{
		return;
	}

	fh = FS_Open((UI_string_type)g_vbkm_cntx.file_path, FS_READ_ONLY);
	if(fh >= 0)
	{
		mmi_vbkm_reader_extract_title(fh, title);
		if(mmi_ucs2strlen((S8*)title))
		{
			mmi_ucs2cpy((S8*)filename, (S8*)title);
			if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
			}
			else
			{
				mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
			}
		}
		else if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
		{
			mmi_ucs2cpy((S8*)filename, (S8*)g_vbkm_recv_file_info_list->file_info.file_name);
			mmi_ucs2cpy((S8*)file_extn, (S8*)g_vbkm_recv_file_info_list->file_info.file_extn);
		}	
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)VBKM_TEMP_FILE_NAME);
			mmi_ucs2cpy((S8*)file_extn, (S8*)VBKM_DEFAULT_FILE_EXTN);
		}
		FS_Close(fh);
		mmi_brw_bookmarks_recv_file_save_to_bookmark(g_vbkm_cntx.file_path, filename, file_extn);
	}
	else
	{
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(fh)),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_pre_entry_options
 * DESCRIPTION
 *  pre entry func for showing vbookmark options after receiving via SMS/BT/IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_pre_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_vobj_get_full_path_name(g_vobj_cntx.buffer_begin, (S8*)g_vbkm_cntx.file_path, MMI_VOBJ_VBKM);
	mmi_vbkm_recv_file_entry_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_entry_options
 * DESCRIPTION
 *  shows the screen for vbookmark options after receiving via SMS/BT/IRDA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_entry_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;

#if !defined(__MMI_FILE_MANAGER__)
    S32 HideItemId = -1;
    U32 maskingByte = 0xffffffff;
#endif /* __MMI_FILE_MANAGER__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VBKM_RECEIVE_OPTION, NULL, mmi_vbkm_recv_file_entry_options, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VBKM_RECEIVE_OPTION);

    nNumofItem = GetNumOfChild(MENU_ID_VBKM_RECV_OPTION);
    GetSequenceStringIds(MENU_ID_VBKM_RECV_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_VBKM_RECV_OPTION);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if !defined(__MMI_FILE_MANAGER__)
    /* Hide Menu Item "Save To File Manager" when FM is not available */
    HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_VBKM_RECV_OPTION, MENU_ID_VBKM_RECV_SAVE_TO_FMGR);
    if (HideItemId != -1)
    {
        ResetBit(maskingByte, HideItemId);
    }
    nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
#endif /* __MMI_FILE_MANAGER__ */ 

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
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
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_recv_file_save_file_info
 * DESCRIPTION
 *  save vbookmark to file manager, file manager will take over screen after calling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_recv_file_save_file_info(U8* file_path, vbkm_recv_medium_type_enum med_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//FS_HANDLE fh;
	//U8 title[(VBKM_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	//U8 filename[(VOBJ_MAX_FILENAME_LENGTH+1)*ENCODING_LENGTH];
	vbkm_recv_file_info_list_struct *pNode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_vbkm_recv_file_info_list)
	{
		g_vbkm_recv_file_info_list = (vbkm_recv_file_info_list_struct*)OslMalloc(sizeof(vbkm_recv_file_info_list_struct));
		g_vbkm_recv_file_info_list->nextNode = NULL;
	}

	for(pNode = g_vbkm_recv_file_info_list; pNode->nextNode != NULL;)
	{
		pNode = (vbkm_recv_file_info_list_struct*)pNode->nextNode;
	}

	mmi_vbkm_util_get_filename_and_extn(file_path, pNode->file_info.file_name,
		pNode->file_info.file_extn);

	g_vbkm_recv_med = med_type;
}
/*--------------------------------------------------END vBookmark Received operation ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vBookmark writer ---------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_writer_convert_file_to_internal_format
 * DESCRIPTION
 *  save vbookmark to file manager, file manager will take over screen after calling.
 * PARAMETERS
 *  filepath	[IN]	path for the vbookmark file
 *  url			[OUT]	copy the extracted url info into it
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_vbkm_writer_convert_file_to_internal_format(FS_HANDLE fh, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 fieldBuff[VBKM_WRITER_FIELD_BUFFER];
	U8 url_ascii[VBKM_MAX_URL_LENGTH+1];
	U32 nBytes;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fieldBuff, 0, VBKM_WRITER_FIELD_BUFFER);

    /* Header */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_BEGIN],
		g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM],
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

    /* URL */
    mmi_ucs2_to_asc((S8*)url_ascii, (S8*)url);
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_URL],
		url_ascii,
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

    /* Footer */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_END],
		g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM],
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

	FS_Truncate(fh);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_writer_convert_file_to_standard_format
 * DESCRIPTION
 *  it convert the bookmark file into standard vbookmark format
 * PARAMETERS
 *  filepath	[IN]	path of the bookmark file
 *  title		[IN]	title of the bookmark
 *  url			[IN]	url of the bookmark
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_vbkm_writer_convert_file_to_standard_format(FS_HANDLE fh, U8* title, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 fieldBuff[VBKM_WRITER_FIELD_BUFFER];
	U8 printable_str[VBKM_WRITER_FIELD_BUFFER];
	U8 url_ascii[VBKM_MAX_URL_LENGTH+1];
	U32 nBytes;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fieldBuff, 0, VBKM_WRITER_FIELD_BUFFER);

    /* Header */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_BEGIN],
		g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM],
		VBKM_LINE_BREAK);

    /* Version */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_VERSION],
		VBKM_VERSION,
		VBKM_LINE_BREAK);

    /* TITLE */
    //mmi_ucs2_to_asc((S8*)title_ascii, (S8*)title);
	mmi_vbkm_util_convert_str_to_printable_form((S8*)printable_str, (S8*)title);

    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s;%s=%s;%s=%s:%s%s",
        g_vbkm_field[VBKM_FIELD_TITLE],
        g_vbkm_sub_field[VBKM_SUB_FIELD_CHARSET],
        VBKM_CHAR_SET,
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENCODING],
        VBKM_ENCODING,
		printable_str,
		VBKM_LINE_BREAK);
	
	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

    /* URL */
    mmi_ucs2_to_asc((S8*)url_ascii, (S8*)url);
    sprintf(
        fieldBuff,
        "%s;%s=%s;%s=%s:%s%s",
        g_vbkm_field[VBKM_FIELD_URL],
        g_vbkm_sub_field[VBKM_SUB_FIELD_CHARSET],
        VBKM_CHAR_SET,
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENCODING],
        VBKM_ENCODING,
		url_ascii,
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

    /* BEGIN ENV */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_BEGIN],
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENV],
		VBKM_LINE_BREAK);

    /* X-IRMC-URL */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s;%s=%s;%s=%s:=%s",
        g_vbkm_field[VBKM_FIELD_XIRMC],
        g_vbkm_sub_field[VBKM_SUB_FIELD_CHARSET],
        VBKM_CHAR_SET,
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENCODING],
        VBKM_ENCODING,
		VBKM_LINE_BREAK);

    /* Internet Shortcut */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s=%s",
        g_vbkm_field[VBKM_FIELD_IS],
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

    /* URL */
    mmi_ucs2_to_asc((S8*)url_ascii, (S8*)url);
    sprintf(
        fieldBuff,
        "%s=%s%s",
        g_vbkm_field[VBKM_FIELD_URL],
		url_ascii,
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

    /* END ENV */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_END],
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENV],
		VBKM_LINE_BREAK);

    /* Footer */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_END],
		g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM],
		VBKM_LINE_BREAK);

	if(FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), &nBytes) != FS_NO_ERROR)
	{
		return MMI_FALSE;
	}

	FS_Truncate(fh);//its truncates the file after the current pointer
	return MMI_TRUE;
}
/*--------------------------------------------------END vBookmark writer ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vbookmark reader ---------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_validate_file
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
MMI_BOOL mmi_vbkm_reader_validate_file(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8 inBuff[VOBJ_READ_BUFF_LEN];
    //U8 token;
	//MMI_BOOL URL_flag = MMI_FALSE;
	//S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mmi_vbkm_reader_check_file_syntax(fh) == VBKM_PARSE_NO_ERROR)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_is_vbookmark_file
 * DESCRIPTION
 *  checks whether the received file is a vbookmark file or not
 * PARAMETERS
 *  file_path	[IN]	path of the file
 * RETURNS
 *  MMI_TRUE  : for a vbookmark file
 *  MMI_FALSE : for non-vbookmark files
 *****************************************************************************/
MMI_BOOL mmi_vbkm_reader_is_vbookmark_file(S8* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	MMI_BOOL ret_val;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)file_path, FS_READ_ONLY);
	MMI_ASSERT(fh >= 0);

	ret_val = mmi_vbkm_reader_validate_file(fh);
	FS_Close(fh);

	return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_check_file_syntax
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
U8 mmi_vbkm_reader_check_file_syntax(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VOBJ_READ_BUFF_LEN];
	MMI_BOOL URL_flag = MMI_FALSE;
	U8 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	FS_Seek(fh, 0, SEEK_SET); /*set file pointer to its beginning*/

	/* read BEGIN tag */
	if(mmi_vbkm_reader_get_single_line(inBuff, fh))
	{
        if (mmi_vbkm_reader_get_field(inBuff) == VBKM_FIELD_BEGIN)
        {
			if(mmi_vbkm_reader_check_header(inBuff) != VBKM_SUB_FIELD_VBKM)
			{
	            return VBKM_BEGIN_ERROR;
			}
        }
        else
        {
            return VBKM_BEGIN_ERROR;
        }
	}
	else
	{
		return VBKM_PARSE_UNKNOWN_ERROR;
	}

	while(mmi_vbkm_reader_get_line(inBuff, fh))
	{
		switch(mmi_vbkm_reader_get_field(inBuff))
		{
			case VBKM_FIELD_URL:
			{
				if(!URL_flag)
				{
					if(!mmi_vbkm_reader_check_URL(inBuff))
					{
						return VBKM_URL_ERROR;
					}
					URL_flag = MMI_TRUE;
				}
				break;
			}
			case VBKM_FIELD_END:
			{
				result = mmi_vbkm_reader_check_header(inBuff);
				if((result == VBKM_SUB_FIELD_VBKM) && URL_flag)
				{
					return VBKM_PARSE_NO_ERROR;
				}
				else if(result == VBKM_SUB_FIELD_ENV)
				{
					break;
				}
				else if(!URL_flag)
				{
					return VBKM_URL_ERROR;
				}
				else
				{
					return VBKM_END_ERROR;
				}
				break;
			}
			default:
				break;
		}
	}

	if(URL_flag)
	{
		return VBKM_END_ERROR;
	}
	else
	{
		return VBKM_URL_ERROR;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_extract_url
 * DESCRIPTION
 *  extracts the URL info from vbookmark file
 * PARAMETERS
 *  filepath	[IN]	path for the vbookmark file
 *  url			[OUT]	copy the extracted url info into it
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_reader_extract_url(FS_HANDLE fh, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VOBJ_READ_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)url, (S8*)L"");

	FS_Seek(fh, 0, SEEK_SET); /*set file pointer to its beginning*/

	while(mmi_vbkm_reader_get_line(inBuff, fh))
	{
		switch(mmi_vbkm_reader_get_field(inBuff))
		{
			case VBKM_FIELD_URL:
			{
				mmi_vbkm_reader_get_URL_string(inBuff, url);
				return;
			}
			default:
				break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_extract_title
 * DESCRIPTION
 *  extracts the title info from vbookmark file
 * PARAMETERS
 *  filepath	[IN]	path for the vbookmark file
 *  url			[OUT]	copy the extracted url info into it
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_reader_extract_title(FS_HANDLE fh, U8* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VOBJ_READ_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)title, (S8*)L"");

	FS_Seek(fh, 0, SEEK_SET); /*set file pointer to its beginning*/

	while(mmi_vbkm_reader_get_line(inBuff, fh))
	{
		switch(mmi_vbkm_reader_get_field(inBuff))
		{
			case VBKM_FIELD_TITLE:
			{
				mmi_vbkm_reader_get_title_string(inBuff, title);
				return;
			}
			default:
				break;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_get_single_line
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
MMI_BOOL mmi_vbkm_reader_get_single_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    S8 strLF[2];
    S8 *currCursor;
    S32 strLen = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strLF, "%c", VOBJ_LF_CHAR);
    FS_Read(fh, strOutput, VOBJ_READ_BUFF_LEN - 1, &nBytes);

    strOutput[nBytes] = VOBJ_NULL;

    if (!nBytes)
    {
        return MMI_FALSE;
    }

    if ((currCursor = strstr(strOutput, strLF)) != NULL)  /* find out first LF */
    {
        strLen = (S32) (currCursor - strOutput);
        if (strOutput[strLen - 1] == VOBJ_CR_CHAR)
        {
            strOutput[strLen - 1] = VOBJ_NULL;
        }
        else
        {
            strOutput[strLen] = VOBJ_NULL;
        }

		FS_Seek(fh, (S32) (strLen - nBytes + 1), SEEK_CUR);
		nBytes = strLen;
    }
    else    /* LF not found, read until LF */
    {
        strOutput[nBytes] = VOBJ_NULL;
    }

    return nBytes;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_get_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters for vbookmark
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vbkm_reader_get_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    S8 *buffer = OslMalloc(VOBJ_READ_BUFF_LEN);
    S32 i;
    S32 strLen;
    S8 *curr_cursor;
    S8 *cursor = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Read(fh, buffer, VOBJ_READ_BUFF_LEN - 1, &nBytes);
    buffer[nBytes] = '\0';

    if (!nBytes)
    {
        OslMfree(buffer);
        return 0;
    }

    /*only the BEGIN, END and VERSION are sure to be single line*/
    if( !strncmp(g_vbkm_field[VBKM_FIELD_END], buffer, strlen(g_vbkm_field[VBKM_FIELD_BEGIN])) ||
		!strncmp(g_vbkm_field[VBKM_FIELD_END], buffer, strlen(g_vbkm_field[VBKM_FIELD_END])) ||
        !strncmp(g_vbkm_field[VBKM_FIELD_VERSION], buffer, strlen(g_vbkm_field[VBKM_FIELD_VERSION]))
		)
    {
        FS_Seek(fh, 0 - nBytes, SEEK_CUR);
        OslMfree(buffer);
        return mmi_vbkm_reader_get_single_line(strOutput, fh);
    }

    /* find next filed */
    for (i = VBKM_FIELD_BEGIN; i < VBKM_FIELD_TOTAL; i++)
    {
        curr_cursor = strstr(buffer + 1, g_vbkm_field[i]);

        if (curr_cursor == (S8*) NULL)
        {
            continue;
        }
        else if (cursor == (S8*) NULL && (*(curr_cursor - 1) == 0x0A))
        {
            cursor = curr_cursor;
        }
        else if (((S32) cursor > (S32) curr_cursor) && (*(curr_cursor - 1) == 0x0A))
        {
            cursor = curr_cursor;
        }
    }
    if (cursor == NULL)
    {
        OslMfree(buffer);
        return 0;
    }

    strLen = (S32) cursor - (S32) buffer;
    strncpy(strOutput, buffer, strLen);
    strOutput[strLen] = VOBJ_NULL;

    /* Remove end of line "\r\n" */
    if (strncmp((S8*) ((strOutput + strLen) - strlen(VOBJ_LF_STR)), (S8*) VOBJ_LF_STR, strlen(VOBJ_LF_STR)) ==
        0)
    {
        if (strOutput[strLen - strlen(VOBJ_LF_STR) - 1] == VOBJ_CR_CHAR)
        {
            strOutput[strLen - strlen(VOBJ_LF_STR) - 1] = VOBJ_NULL;
        }
        else
        {
            strOutput[strLen - strlen(VOBJ_LF_STR)] = VOBJ_NULL;
        }
    }

    FS_Seek(fh, (S32) (strLen - nBytes), SEEK_CUR);

    OslMfree(buffer);
    return strLen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_get_field
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
U8 mmi_vbkm_reader_get_field(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VBKM_FIELD_TOTAL; i++)
    {
        if (mmi_vobj_uti_cmp_filed(String, g_vbkm_field[i]))
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_check_header
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
U8 mmi_vbkm_reader_check_header(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = (S8*)strstr(String, (S8*) VBKM_COLON_SEP);
    if (!cursor || !mmi_vobj_uti_strnicmp((cursor + 1), 
		(S8*)g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM], strlen(g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM])))
    {
        return VBKM_SUB_FIELD_VBKM;
    }
    else if (!cursor || !mmi_vobj_uti_strnicmp((cursor + 1), 
		(S8*)g_vbkm_sub_field[VBKM_SUB_FIELD_ENV], strlen(g_vbkm_sub_field[VBKM_SUB_FIELD_ENV])))
    {
        return VBKM_SUB_FIELD_ENV;    
    }
	else
	{
        return VBKM_SUB_FIELD_TOTAL;    
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_check_URL
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
MMI_BOOL mmi_vbkm_reader_check_URL(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
	U32 len;
	U8* url_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = strlen((S8*)g_vbkm_field[VBKM_FIELD_URL]);
	if(!mmi_vobj_uti_strnicmp((S8*)string+len, VBKM_COLON_SEP, strlen((S8*)VBKM_COLON_SEP)))
	{
		url_ptr = (U8*) (string + len + strlen((S8*)VBKM_COLON_SEP));
		len = strlen((S8*)url_ptr);
		if(len)
		{
			return MMI_TRUE;
		}
	}
	else if(!mmi_vobj_uti_strnicmp((S8*)string+len, VBKM_EQUALITY_SEP, strlen((S8*)VBKM_EQUALITY_SEP)))
	{
		url_ptr = (U8*)(string + len + strlen((S8*)VBKM_EQUALITY_SEP));
		len = strlen((S8*)url_ptr);
		if(len)
		{
			return MMI_TRUE;
		}
	}
	else if(!mmi_vobj_uti_strnicmp((S8*)string+len, VBKM_SEMI_COLON_SEP, strlen((S8*)VBKM_SEMI_COLON_SEP)))
	{
		cursor = strstr((S8*)string+len, VBKM_COLON_SEP);
		if(cursor)
		{
			url_ptr = (U8*)cursor + 1;
			len = strlen((S8*)url_ptr);
			if(len)
			{
				return MMI_TRUE;
			}
		}
	}
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_get_URL_string
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
void mmi_vbkm_reader_get_URL_string(S8 *inBuff, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
	U32 len;
	U8* url_ptr;
	U8 temp_str[VBKM_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = strlen((S8*)g_vbkm_field[VBKM_FIELD_URL]);
	if(!mmi_vobj_uti_strnicmp((S8*)inBuff+len, VBKM_COLON_SEP, strlen((S8*)VBKM_COLON_SEP)))
	{
		url_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_COLON_SEP));
		strncpy((S8*)temp_str, (S8*)url_ptr, VBKM_MAX_URL_LENGTH);
		if(strlen((S8*)url_ptr) >= VBKM_MAX_URL_LENGTH)
		{
			temp_str[VBKM_MAX_URL_LENGTH] = '\0';
		}
		mmi_asc_to_ucs2((S8*)url, (S8*)temp_str);
	}
	else if(!mmi_vobj_uti_strnicmp((S8*)inBuff+len, VBKM_EQUALITY_SEP, strlen((S8*)VBKM_EQUALITY_SEP)))
	{
		url_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_EQUALITY_SEP));
		strncpy((S8*)temp_str, (S8*)url_ptr, VBKM_MAX_URL_LENGTH);
		if(strlen((S8*)url_ptr) >= VBKM_MAX_URL_LENGTH)
		{
			temp_str[VBKM_MAX_URL_LENGTH] = '\0';
		}
		mmi_asc_to_ucs2((S8*)url, (S8*)temp_str);
	}
	else if(!mmi_vobj_uti_strnicmp((S8*)inBuff+len, VBKM_SEMI_COLON_SEP, strlen((S8*)VBKM_SEMI_COLON_SEP)))
	{
		cursor = strstr((S8*)inBuff+len, VBKM_COLON_SEP);
		if(cursor)
		{
			url_ptr = (U8*)(cursor + 1);
			strncpy((S8*)temp_str, (S8*)url_ptr, VBKM_MAX_URL_LENGTH);
			if(strlen((S8*)url_ptr) >= VBKM_MAX_URL_LENGTH)
			{
				temp_str[VBKM_MAX_URL_LENGTH] = '\0';
			}
			mmi_asc_to_ucs2((S8*)url, (S8*)temp_str);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_reader_get_title_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inBuff      [IN]        
 *  title      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_reader_get_title_string(S8 *inBuff, U8* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
	U32 len;
	U8* title_ptr;
	U8 temp_str[VBKM_READER_FIELD_BUFFER];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = strlen((S8*)g_vbkm_field[VBKM_FIELD_TITLE]);

	if(!mmi_vobj_uti_strnicmp((S8*)inBuff+len, VBKM_COLON_SEP, strlen((S8*)VBKM_COLON_SEP)))
	{
		title_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_COLON_SEP));
	}
	else if(!mmi_vobj_uti_strnicmp((S8*)inBuff+len, VBKM_EQUALITY_SEP, strlen((S8*)VBKM_EQUALITY_SEP)))
	{
		title_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_EQUALITY_SEP));
	}
	else if(!mmi_vobj_uti_strnicmp((S8*)inBuff+len, VBKM_SEMI_COLON_SEP, strlen((S8*)VBKM_SEMI_COLON_SEP)))
	{
		cursor = strstr((S8*)inBuff+len, VBKM_COLON_SEP);
		if(cursor)
		{
			title_ptr = (U8*)(cursor + 1);
		}
		else
		{
			title_ptr = NULL;
		}
	}
	else
	{
        title_ptr = NULL;
	}

	if(title_ptr)
	{
		applib_qprint_decode((S8*)title_ptr, strlen((S8*)title_ptr), (S8*)temp_str, VBKM_READER_FIELD_BUFFER);
		mmi_vbkm_util_convert_to_ucs2((S8*)title, (VBKM_MAX_FILENAME_LENGTH+1) * ENCODING_LENGTH, (S8*)temp_str, VOBJ_CH_UTF8);

		if(mmi_ucs2strlen((S8*)title) >= VBKM_MAX_FILENAME_LENGTH)
		{
			title[VBKM_MAX_FILENAME_LENGTH * ENCODING_LENGTH] = '\0';
			title[VBKM_MAX_FILENAME_LENGTH * ENCODING_LENGTH + 1] = '\0';
		}
	}
}
/*--------------------------------------------------END vbookmark reader ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vbookmark forward ---------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_fmgr_sms_forward
 * DESCRIPTION
 *  Forward vbookmark to SMS from file manager.
 *  This is a intermediate function between file manager and SMS app.
 * PARAMETERS
 *  path        [IN]	vbookmark file path     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_fmgr_sms_forward(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    mmi_ems_vobject_send_by_ems(VOBJ_SRC_PORT, VOBJ_VBKM_PORT, path, NULL);
#endif 
}
/*--------------------------------------------------END vbookmark forward ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vbookmark utilites ---------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_clean_one_file_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_clean_one_file_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vbkm_recv_file_info_list_struct *pNextNode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_vbkm_recv_med != VBKM_RECV_VIA_SMS)
	{
		if(g_vbkm_recv_file_info_list)
		{
			pNextNode = (vbkm_recv_file_info_list_struct*)g_vbkm_recv_file_info_list->nextNode;
			OslMfree(g_vbkm_recv_file_info_list);
			g_vbkm_recv_file_info_list = pNextNode;
		}
	}

	mmi_vobj_clear_one_file_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_util_convert_to_system_encoding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vbkm_util_convert_to_system_encoding(S8 *dst, S8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)src, (char*)dst, VBKM_WRITER_FIELD_BUFFER);

    return VOBJ_CH_UTF8;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_util_convert_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_util_convert_to_ucs2(S8 *dst, U8 dst_size, S8 *src, U8 encode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (encode == VOBJ_CH_UTF8)
    {
        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
    else
    {
        mmi_chset_convert(g_chset_text_encoding, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_util_replace_filename_in_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_util_replace_filename_in_filepath(U8* file_path, U8* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_util_get_filename_and_extn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_util_get_filename_and_extn(U8* file_path, U8* filename, U8* file_extn)
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
	mmi_ucs2cpy((S8*)filename, (S8*)L"");	
	mmi_ucs2cpy((S8*)file_extn, (S8*)L"");

	start_loc = (UI_string_type)mmi_ucs2rchr((const S8*)file_path, (U16)'\\');
	if(start_loc)
	{
		end_loc = (UI_string_type)mmi_ucs2rchr((const S8*)start_loc, (U16)'.');
		if(end_loc)
		{
			len = end_loc - start_loc - 1;
			mmi_ucs2ncpy((S8*)filename, (S8*)start_loc+ENCODING_LENGTH, len);
			mmi_ucs2cpy((S8*)file_extn, (S8*)end_loc+ENCODING_LENGTH);
		}
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)start_loc+ENCODING_LENGTH);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vbkm_util_convert_str_to_printable_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  printable_str		[OUT]         
 *  title				[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vbkm_util_convert_str_to_printable_form(S8* printable_str, S8* actual_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 temp_buf[VBKM_WRITER_FIELD_BUFFER];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_vbkm_util_convert_to_system_encoding((S8*)temp_buf, (S8*)actual_str);
    applib_qprint_encode_ext((S8*)temp_buf, strlen(temp_buf), (S8*)printable_str, VBKM_WRITER_FIELD_BUFFER, TRUE);
}
/*--------------------------------------------------END vbookmark utilites ---------------------------------------------------*/

#endif /* defined(__MMI_VBOOKMARK__) */ /* END #if defined(__MMI_VBOOKMARK__) */
#endif /* _MMI_VBOOKMARK_C */ /* END #define _MMI_VBOOKMARK_C */

