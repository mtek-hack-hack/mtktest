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
 * JMMSComposeUI.C
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
/*  Include: MMI header file */
#include "JMMSCompose.h"
#include "JMMSResDef.h"
#include "JMMSExdcl.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "wgui.h"
#include "MessagesResourceData.h"
#include "JMMSView.h"
#include "JMMSInbox.h"
#include "wapadp.h"
#include "FileManagerGProt.h"
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#endif 
#include "JMMSCoreAPI.h"
#include "ddlbase.h"
#include "JMMSGdcl.h"
#include "jcutils.h"
#include "ddlutils.h"
#include "ddl.h"
#include "jdi_MMSErr.h"
#include "jcerror.h"
#include "ddl.h"
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "jdd_memapi.h"
#include "jdd_ui_ResDef.h"
#include "miscutils.h"
#include "JMMSGprot.h"
#include "ToDoListDef.h"
#include "vCard.h"
#include "PhoneBookDef.h"
#include "PhoneBookGprot.h"
#include "PhoneBookTypes.h"
#include "MainMenuDef.h"
#include "jMMSDRMHandler.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
/* PMT VIKAS START 20060502 */
#if defined(__MMI_AUDIO_PLAYER__) || defined (_MMI_VIDEO_PLAYER__)
#endif /* defined(__MMI_AUDIO_PLAYER__) || defined (_MMI_VIDEO_PLAYER__) */ 
#if defined(__MMI_AUDIO_PLAYER__)
#include "AudioPlayerProt.h"
#endif 
#ifdef __MMI_VIDEO_PLAYER__
#include "mdi_video.h"
#include "jdd_videoapi.h"
/* PMT VIKAS END 20060502 */
#endif /* __MMI_VIDEO_PLAYER__ */ 

#include "JMMSMessageSettingsUtils.h"
#include "jdd_fileapi.h"
#include  "lcd_sw_rnd.h"
#include "custom_wap_config.h"
#ifdef __MMI_UNIFIED_MESSAGE__
#include "JMMSUMHandling.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "mmsadp.h"
#endif
#endif 
#include "CallManagementGprot.h"

/*  Include: PS header file */
/* ... Add More PS header */
extern MMI_ALERT_TYPE GetMtCallAlertTypeEnum(void);

const fmgr_filter_struct g_jmms_exclude_filter[] = 
{
    {FMGR_TYPE_EMS, "EMS"},
    {FMGR_TYPE_ANM, "ANM"},
    {FMGR_TYPE_DCF, "DCF"},
    {FMGR_TYPE_DM, "DM"}
};

const JC_UINT16 content_class_offset[] = 
{
	11,		// Text
	10,		// Image Basic
	3,		// Image Rich
	0,		// Video Basic
	0		// Video Rich
} ;

const S8* restricted_attachment_filter[] =
{
	#if defined(ISP_SUPPORT)
	"3GP",
	"MP4",
	"3G2",
	#else
	0,0,0,
	#endif 

	"MID",
	"MIDI",

	"GIF",
	"WBMP",
	"WBM",
	#ifdef JPG_DECODE
	"JPG",
	"JPEG",
	#else
	0,0,
	#endif /* JPG_DECODE */ 
	"AMR",

	#ifdef __MMI_EBOOK_READER__
	"TXT"
	#else
	0
	#endif
};

extern const fmgr_filter_struct fmgr_filter[FMGR_MAX_FILTER_COUNT];
extern JC_BOOLEAN mmi_jdd_check_for_image_size_and_resolution(S8 *path, S32 width, S32 height, U32 media_size);

/***************************************************************************** 
* Define
*****************************************************************************/

#define TEMP_FOLDER_PATH_VOBJ "@mms\\temp\\vobj\\"
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/
/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifndef __MMI_UNIFIED_COMPOSER__
/* PMT VIKAS START 20060502 */
static void mmi_jmms_video_idle_preview_in_composer(
                S8 *filename_p,
                S32 x_frame,
                S32 y_frame,
                S32 width_frame,
                S32 height_frame);
static void mmi_jmms_image_idle_preview_in_composer(
                S8 *filename_p,
                S32 img_x,
                S32 img_y,
                S32 img_width,
                S32 img_height);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
/* PMT VIKAS END 20060502 */
/***************************************************************************** 
* Global Variable
*****************************************************************************/

/* MAUI_00018451 Start */

/* MAUI_00018451 End */

/* PMT VIKAS START 20060502 */

/* PMT VIKAS END 20060502 */

extern BOOL r2lMMIFlag; /* Right-to-left languages (e.g. Arabic) */

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern JC_RETCODE jdd_FSTranslateErr(kal_int32 err);
extern kal_wchar *mime_get_extension(kal_wchar *file_path);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_init
 * DESCRIPTION
 *  Initialization function of MMS compose.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UNIFIED_COMPOSER__
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_INSERT, mmi_jmms_highlight_attachment_insert);
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_DELETE, mmi_jmms_highlight_attachment_delete);

    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_ATTACHMENT, mmi_jmms_highlight_attachment_attachment);
#ifdef __MMI_VCARD__
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_VCARD, mmi_jmms_highlight_attachment_vcard);
#endif 
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_VCALENDAR, mmi_jmms_highlight_attachment_vcalendar);
#ifdef __MMI_VCARD__
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_INSERT_VCARD_FILEMGR, mmi_jmms_highlight_attachment_vcard_fm);
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_INSERT_VCARD_PHB, mmi_jmms_highlight_attachment_vcard_phb);
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_INSERT_MY_VCARD, mmi_jmms_highlight_attachment_my_vcard);
#endif /* __MMI_VCARD__ */ 
#if defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_INSERT_VCALENDAR_TODO_LIST, mmi_jmms_highlight_attachment_vcal_todolist);
#endif 
    SetHiliteHandler(MENU_ID_JMMS_ATTACHMENT_INSERT_VCALENDAR_FILEMGR, mmi_jmms_highlight_attachment_vcal_fm);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INPUT_METHOD, mmi_jmms_highlight_edit_content_ip_method);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INSERT, mmi_jmms_highlight_edit_content_insert);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_DELETE, mmi_jmms_highlight_edit_content_delete);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_REPLACE, mmi_jmms_highlight_edit_content_replace);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_PLAY_AUDIO, mmi_jmms_highlight_edit_content_play_audio);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_PLAY_VIDEO, mmi_jmms_highlight_edit_content_play_video);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_GOTO, mmi_jmms_highlight_edit_content_goto);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_SETTINGS, mmi_jmms_highlight_edit_content_settings);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_PREVIEW, mmi_jmms_highlight_edit_content_preview);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_OPTION_DONE, mmi_jmms_highlight_edit_content_done);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INSERT_IMAGE, mmi_jmms_highlight_edit_content_insert_image);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INSERT_AUDIO, mmi_jmms_highlight_edit_content_insert_audio);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INSERT_VIDEO, mmi_jmms_highlight_edit_content_insert_video);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INSERT_SLIDE, mmi_jmms_highlight_edit_content_insert_slide);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_INSERT_CONTACT, mmi_jmms_highlight_edit_content_insert_contact);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_DELETE_IMAGE, mmi_jmms_highlight_edit_content_delete_image);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_DELETE_AUDIO, mmi_jmms_highlight_edit_content_delete_audio);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_DELETE_VIDEO, mmi_jmms_highlight_edit_content_delete_video);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_DELETE_SLIDE, mmi_jmms_highlight_edit_content_delete_slide);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_IMAGE, mmi_jmms_highlight_edit_content_replace_image);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_AUDIO, mmi_jmms_highlight_edit_content_replace_audio);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_VIDEO, mmi_jmms_highlight_edit_content_replace_video);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_GOTO_NEXT, mmi_jmms_highlight_edit_content_goto_next);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_GOTO_PREVIOUS, mmi_jmms_highlight_edit_content_goto_previous);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_GOTO_SLIDE_LIST, mmi_jmms_highlight_edit_content_goto_slide_list);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SLIDE_TIME, mmi_jmms_highlight_edit_content_slide_time);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT, mmi_jmms_highlight_edit_content_text_settings);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL, mmi_jmms_highlight_edit_content_smil_settings);

    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_TEXT_TIME, mmi_jmms_highlight_smil_settings_text_timings);
    SetHiliteHandler(
        MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_IMAGE_TIME,
        mmi_jmms_highlight_smil_settings_image_timings);
    SetHiliteHandler(
        MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_AUDIO_TIME,
        mmi_jmms_highlight_smil_settings_audio_timings);
    SetHiliteHandler(
        MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_VIDEO_TIME,
        mmi_jmms_highlight_smil_settings_video_timings);
    SetHiliteHandler(MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_BGCOLOR, mmi_jmms_highlight_smil_settings_bg_color);
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#ifdef __MMI_UNIFIED_MESSAGE__
    mmi_um_jmms_set_folder_list_callback_function(mmi_um_jmms_dummy_folder_list_callback);
#endif 
    // #ifdef __MMI_MMS_SIGNATURE__
    mmi_jmms_reset_fw_flag_of_inbox();
    // #endif
}

#ifndef __MMI_UNIFIED_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_insert
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_insert(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_attachment_insert, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_attachment_insert, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_attachment_insert, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_delete
 * DESCRIPTION
 *  highlight fn for menu option attachment->delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_delete(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_delete_attachment, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_delete_attachment, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_delete_attachment, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_attachment
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_attachment(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_filemgr_insert_attachment, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_attachment, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_attachment, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_vcard
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->vcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_vcard(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_attachment_insert_vcard, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_attachment_insert_vcard, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_attachment_insert_vcard, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_vcalendar
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->vcalendar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_vcalendar(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_attachment_insert_vcalender, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_attachment_insert_vcalender, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_attachment_insert_vcalender, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#ifdef __MMI_VCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_vcard_fm
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->vcard->file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_vcard_fm(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_filemgr_insert_vcard, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_vcard, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_vcard, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_vcard_phb
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->vacrd->phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_vcard_phb(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_insert_vcard_phb, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_insert_vcard_phb, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_insert_vcard_phb, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_my_vcard
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->my vcard
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_my_vcard(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_insert_my_vcard, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_insert_my_vcard, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_insert_my_vcard, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_VCARD__ */ 

#if defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_vcal_todolist
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->vaclendar->to do list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_vcal_todolist(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_insert_vclndr_tdl, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_insert_vclndr_tdl, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_insert_vclndr_tdl, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_attachment_vcal_fm
 * DESCRIPTION
 *  highlight fn for menu option attachment->insert->vcalendar->file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_attachment_vcal_fm(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_filemgr_insert_vcalander, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_vcalander, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_vcalander, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_ip_method
 * DESCRIPTION
 *  highlight fn for menu option edit content->input method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_ip_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryInputMethodScreen, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_jmms_compose_go_back_history_ip_method);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_insert
 * DESCRIPTION
 *  highlight fn for menu option edit content->insert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_insert(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_insert, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_insert, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_insert, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_delete
 * DESCRIPTION
 *  highlight fn for menu option edit content->delete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_delete(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_delete, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_delete, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_delete, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_replace
 * DESCRIPTION
 *  highlight fn for menu option edit content->replace
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_replace(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_replace, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_replace, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_replace, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_play_audio
 * DESCRIPTION
 *  highlight fn for menu option edit content->play audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_play_audio(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_compose_play_audio, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_compose_play_audio, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_compose_play_audio, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_play_video
 * DESCRIPTION
 *  highlight fn for menu option edit content->play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_play_video(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_compose_play_video, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_compose_play_video, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_compose_play_video, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_goto
 * DESCRIPTION
 *  highlight fn for menu option edit content->goto
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_goto(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_goto, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_goto, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_goto, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_settings
 * DESCRIPTION
 *  highlight fn for menu option edit content->settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_settings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_preview
 * DESCRIPTION
 *  highlight fn for menu option edit content->preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_preview(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_mms_preview, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_mms_preview, KEY_WAP, KEY_EVENT_DOWN);
    /* MAUI_00018463 Start */
    /* SetKeyHandler(mmi_jmms_pre_entry_mms_preview, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */
    /* MAUI_00018463 End */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_done
 * DESCRIPTION
 *  highlight fn for menu option edit content->done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_done(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_mms_edit_content_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_mms_edit_content_done, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_mms_edit_content_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_mms_edit_content_done
 * DESCRIPTION
 *  to go back to write mms screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_mms_edit_content_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

    GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_insert_image
 * DESCRIPTION
 *  highlight fn for menu option edit content->insert->image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_insert_image(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_filemgr_insert_image, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_image, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_image, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_insert_audio
 * DESCRIPTION
 *  highlight fn for menu option edit content->insert->audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_insert_audio(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_filemgr_insert_audio, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_audio, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_audio, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_insert_video
 * DESCRIPTION
 *  highlight fn for menu option edit content->insert->video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_insert_video(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_filemgr_insert_video, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_video, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_filemgr_insert_video, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_insert_slide
 * DESCRIPTION
 *  highlight fn for menu option edit content->insert->slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_insert_slide(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_insert_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_edit_content_insert_slide, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_edit_content_insert_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_insert_contact
 * DESCRIPTION
 *  highlight fn for menu option edit content->insert->contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_insert_contact(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_insert_phb_contact, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_insert_phb_contact, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_insert_phb_contact, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_delete_image
 * DESCRIPTION
 *  highlight fn for menu option edit content->delete->image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_delete_image(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_delete_image, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_delete_audio
 * DESCRIPTION
 *  highlight fn for menu option edit content->delete->audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_delete_audio(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_delete_audio, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_delete_video
 * DESCRIPTION
 *  highlight fn for menu option edit content->delete->video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_delete_video(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_delete_video, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_delete_slide
 * DESCRIPTION
 *  highlight fn for menu option edit content->delete->slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_delete_slide(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_delete_slide, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_replace_image
 * DESCRIPTION
 *  highlight fn for menu option edit content->replace->image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_replace_image(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_replace_image, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_replace_image, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_replace_image, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_replace_audio
 * DESCRIPTION
 *  highlight fn for menu option edit content->replace->audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_replace_audio(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_replace_audio, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_replace_audio, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_replace_audio, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_replace_video
 * DESCRIPTION
 *  highlight fn for menu option edit content->replace->video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_replace_video(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_replace_video, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_replace_video, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_replace_video, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_goto_next
 * DESCRIPTION
 *  highlight fn for menu option edit content->goto->next slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_goto_next(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_next_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_edit_content_next_slide, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_edit_content_next_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_goto_previous
 * DESCRIPTION
 *  highlight fn for menu option edit content->goto->previous slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_goto_previous(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_edit_content_prev_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_edit_content_prev_slide, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_edit_content_prev_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_goto_slide_list
 * DESCRIPTION
 *  highlight fn for menu option edit content->goto->slide list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_goto_slide_list(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_goto_slide_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_goto_slide_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_goto_slide_list, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_slide_time
 * DESCRIPTION
 *  highlight fn for menu option edit content->slide time settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_slide_time(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_edit_content_slide_time, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_edit_content_slide_time, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_text_settings
 * DESCRIPTION
 *  highlight fn for menu option edit content->text settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_text_settings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_edit_content_text_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_edit_content_text_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_edit_content_text_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_edit_content_smil_settings
 * DESCRIPTION
 *  highlight fn for menu option edit content->smil settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_edit_content_smil_settings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_edit_content_smil_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_edit_content_smil_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_edit_content_smil_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_smil_settings_text_timings
 * DESCRIPTION
 *  highlight fn for menu option edit content->smil settings->text timings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_smil_settings_text_timings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_text_timing_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_text_timing_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_text_timing_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_smil_settings_image_timings
 * DESCRIPTION
 *  highlight fn for menu option edit content->smil settings->image timings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_smil_settings_image_timings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_image_timing_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_image_timing_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_image_timing_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_smil_settings_audio_timings
 * DESCRIPTION
 *  highlight fn for menu option edit content->smil settings->audio timings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_smil_settings_audio_timings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_audio_timing_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_audio_timing_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_audio_timing_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_smil_settings_video_timings
 * DESCRIPTION
 *  highlight fn for menu option edit content->smil settings->video timings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_smil_settings_video_timings(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_pre_entry_video_timing_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_pre_entry_video_timing_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_pre_entry_video_timing_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_highlight_smil_settings_bg_color
 * DESCRIPTION
 *  highlight fn for menu option edit content->smil settings->back ground color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_highlight_smil_settings_bg_color(void)
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
    SetLeftSoftkeyFunction(mmi_jmms_entry_smil_bg_color_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_jmms_entry_smil_bg_color_settings, KEY_WAP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_jmms_entry_smil_bg_color_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_attachment_options
 * DESCRIPTION
 *  Entry function when user want to edit attachments.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_attachment_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Himanshu Fix MAUI_00228900 START */
    if (g_jmms_context && g_jmms_context->compose_context)
    {
        g_jmms_context->compose_context->from_jmms_app = 0;
    }
    /* Himanshu Fix MAUI_00228900 END */
#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
    EntryNewScreen(SCR_ID_JMMS_ATTACHMENT_OPTIONS, NULL, mmi_jmms_entry_attachment_options, NULL);

    parent_id = MENU_ID_JMMS_ATTACHMENT_OPTIONS;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_ATTACHMENT_OPTIONS);

    if (g_jmms_context->num_attachments > 0)
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_ATTACHMENT_DELETE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_ATTACHMENT_DELETE);
    }

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    num_item = GetNumOfChild_Ext(parent_id);

    GetSequenceStringIds_Ext(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBacktoWriteMMS, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_attachment_insert
 * DESCRIPTION
 *  Entry function when user want to insert attachments.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_attachment_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MAUI_00228376 Start */
    if (g_jmms_context->num_attachments >= JMMS_MAX_ATTACHMENTS_LIMIT)
    {
        DisplayPopup((PU8) GetString(STR_ID_MAX_ATTACHMENT_LIMIT), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return;
    }
    /* MAUI_00228376 End */

    //#if (!defined (__MMI_VCARD__) && !defined (__MMI_VCALENDAR__))
    //    mmi_jmms_entry_filemgr_insert_attachment();
    //#else /* (!defined (__MMI_VCARD__) && !defined (__MMI_VCALENDAR__)) */ 
    EntryNewScreen(SCR_ID_JMMS_ATTACHMENT_INSERT, NULL, mmi_jmms_entry_attachment_insert, NULL);

    parent_id = MENU_ID_JMMS_ATTACHMENT_INSERT;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_ATTACHMENT_INSERT);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    // #endif /* (!defined (__MMI_VCARD__) && !defined (__MMI_VCALENDAR__)) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_attachment_insert_vcard
 * DESCRIPTION
 *  Entry function when user want to insert Vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_attachment_insert_vcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_ATTACHMENT_VCARD, NULL, mmi_jmms_entry_attachment_insert_vcard, NULL);

    parent_id = MENU_ID_JMMS_ATTACHMENT_VCARD;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_ATTACHMENT_VCARD);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 *  
 * FUNCTION
 *  mmi_jmms_entry_attachment_insert_vcalender
 * DESCRIPTION
 *  Entry function when user want to insert vcalendar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_attachment_insert_vcalender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_ATTACHMENT_VCALENDAR, NULL, mmi_jmms_entry_attachment_insert_vcalender, NULL);

    parent_id = MENU_ID_JMMS_ATTACHMENT_VCALENDAR;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_ATTACHMENT_VCALENDAR);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_edit_content_option
 * DESCRIPTION
 *  Entry function for edit content options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_edit_content_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_jmms_exit_curr_slide() == JMMS_COMP_POPUP_OK)
    {
        history *temphistory_p;

        temphistory_p = (history*) jdd_MemAlloc(sizeof(history), 1);
        if (temphistory_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        }
        else
        {
            memset(temphistory_p, 0, sizeof(history));
            temphistory_p->scrnID = SCR_ID_JMMS_EDIT_CONTENT_OPTIONS;
            temphistory_p->entryFuncPtr = mmi_jmms_entry_edit_content_option;
            AddHistory(*temphistory_p);
            jdd_MemFree(temphistory_p);
        }
    }
    else if (mmi_jmms_exit_curr_slide() == JMMS_COMP_FAIL)
    {
        return;
    }
    else
    {
        mmi_jmms_entry_edit_content_option();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_option
 * DESCRIPTION
 *  Entry function for edit content options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;
    U8 total_media_count = 0;
    U8 page_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_OPTIONS, NULL, mmi_jmms_entry_edit_content_option, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_OPTIONS;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_OPTIONS);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    if (g_jmms_context->compose_context->curr_slide_info.audio_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_PLAY_AUDIO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_PLAY_AUDIO);
    }

    if (g_jmms_context->compose_context->curr_slide_info.video_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_PLAY_VIDEO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_PLAY_VIDEO);
    }

    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    if (page_count <= 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_GOTO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_GOTO);
    }

    /* to count total medias present in a slide. */
    if (g_jmms_context->compose_context->curr_slide_info.image_id != 0)
    {
        total_media_count++;
    }
    if (g_jmms_context->compose_context->curr_slide_info.audio_id != 0)
    {
        total_media_count++;
    }
    if (g_jmms_context->compose_context->curr_slide_info.video_id != 0)
    {
        total_media_count++;
    }

    if (total_media_count == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE);
    }

    if (total_media_count == 0 && page_count <= 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE);
    }

    num_item = GetNumOfChild_Ext(parent_id);

    GetSequenceStringIds_Ext(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_insert
 * DESCRIPTION
 *  Entry function when user press edit content->insert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_INSERT, NULL, mmi_jmms_entry_edit_content_insert, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_INSERT;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_INSERT);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_delete
 * DESCRIPTION
 *  Entry function when user press edit content->delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;
    U8 page_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_DELETE, NULL, mmi_jmms_entry_edit_content_delete, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_DELETE;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_DELETE);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (g_jmms_context->compose_context->curr_slide_info.image_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_IMAGE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_IMAGE);
    }

    if (g_jmms_context->compose_context->curr_slide_info.audio_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_AUDIO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_AUDIO);
    }

    if (g_jmms_context->compose_context->curr_slide_info.video_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_VIDEO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_VIDEO);
    }

    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    if (page_count <= 1)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_SLIDE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_DELETE_SLIDE);
    }

    num_item = GetNumOfChild_Ext(parent_id);

    GetSequenceStringIds_Ext(parent_id, str_item_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_replace
 * DESCRIPTION
 *  Entry function when user press edit content->replace.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_REPLACE, NULL, mmi_jmms_entry_edit_content_replace, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_REPLACE;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (g_jmms_context->compose_context->curr_slide_info.image_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_IMAGE);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_IMAGE);
    }

    if (g_jmms_context->compose_context->curr_slide_info.audio_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_AUDIO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_AUDIO);
    }

    if (g_jmms_context->compose_context->curr_slide_info.video_id == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_VIDEO);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_REPLACE_VIDEO);
    }

    num_item = GetNumOfChild_Ext(parent_id);

    GetSequenceStringIds_Ext(parent_id, str_item_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_goto
 * DESCRIPTION
 *  Entry function when user press edit content->goto.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;
    U8 page_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);

    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_GOTO, NULL, mmi_jmms_entry_edit_content_goto, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_GOTO;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_GOTO);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (g_jmms_context->compose_context->curr_page_index > 1)
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_GOTO_PREVIOUS);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_GOTO_PREVIOUS);
    }

    if (page_count > g_jmms_context->compose_context->curr_page_index)
    {
        mmi_frm_unhide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_GOTO_NEXT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_JMMS_EDIT_CONTENT_GOTO_NEXT);
    }

    num_item = GetNumOfChild_Ext(parent_id);

    GetSequenceStringIds_Ext(parent_id, str_item_list);

    ShowCategory52Screen(
        STR_ID_JMMS_SLIDE_LIST,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_settings
 * DESCRIPTION
 *  Entry function when user press edit content->SETTINGS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s ", "mmi_jmms_entry_edit_content_settings");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Compose context Values: Text Size of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Compose context Values: Italic Selection of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Compose context Values: Bold Selection of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold);

    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_SETTINGS, NULL, mmi_jmms_entry_edit_content_settings, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_SETTINGS;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_SETTINGS);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_JMMS_EDIT_CONTENT_SETTINGS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_edit_content_text_settings
 * DESCRIPTION
 *  pre Entry function when user press edit content->SETTINGS->text settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_edit_content_text_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s ", "mmi_jmms_pre_entry_edit_content_text_settings ");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Set Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    if (g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size == SMALL_FONT)
    {
        g_jmms_context->jmms_inline_items.text_settings_items.size_selected = SIZE_SMALL;
    }
    else if (g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size == LARGE_FONT)
    {
        g_jmms_context->jmms_inline_items.text_settings_items.size_selected = SIZE_LARGE;
    }
    else
    {
        g_jmms_context->jmms_inline_items.text_settings_items.size_selected = SIZE_NORMAL;
    }

    g_jmms_context->jmms_inline_items.text_settings_items.italic_selected =
        g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic;
    g_jmms_context->jmms_inline_items.text_settings_items.bold_selected =
        g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold;

    for (count = 0;
         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color != g_jmms_color_RGB_list[count] &&
         count < MAX_JMMS_COLOR_NUM - 1; count++);

    if (count == MAX_JMMS_COLOR_NUM - 1)
    {
        g_jmms_context->jmms_inline_items.text_settings_items.color_selected = MAX_JMMS_COLOR_NUM - 1;
        g_jmms_context->g_text_custom_color_rgb = g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color;       /* sanjeev added */
    }
    else
    {
        g_jmms_context->jmms_inline_items.text_settings_items.color_selected = count;
        g_jmms_context->g_text_custom_color_rgb = 100;  /* sanjeev added */
    }

    g_jmms_context->g_custom_var_change = 0;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Set Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    mmi_jmms_entry_edit_content_text_settings();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_text_settings
 * DESCRIPTION
 *  Entry function when user press edit content->SETTINGS->text settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_text_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;
    U16 input_buffer_size;
    U16 parent_id;
    U16 num_item;   /* Stores no of children in the submenu */
    InlineItem text_settings_inline_edit_list[8];

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_TEXT_SETTINGS, mmi_mms_exit_text_settings, NULL, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT;

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_TEXT_SETTINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_EDIT_CONTENT_TEXT_SETTINGS, &input_buffer_size);

    SetParentHandler(parent_id);

    num_item = GetNumOfChild(parent_id);

    InitializeCategory57Screen();

    mmi_jmms_fill_txt_setting_inline_edit_struct((void*)text_settings_inline_edit_list);

    if (input_buffer_p != NULL) /* added for inline edit history */
    {
        SetCategory57Data(text_settings_inline_edit_list, num_item, input_buffer_p);    /* sets the data */
    }

    if (GetInlineDoneFlag(gui_buffer_p) == 0)
    {
        if (g_jmms_context->g_custom_var_change == 1)
        {
            SetInlineDoneFlag(gui_buffer_p);
        }
    }

    ShowCategory57Screen(
        STR_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        num_item * 2,
        (PU16) item_icons,
        text_settings_inline_edit_list,
        0,
        gui_buffer_p);

    SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_txt_settings, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_exit_text_settings
 * DESCRIPTION
 *  Exit function when user press edit content->SETTINGS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mms_exit_text_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr;    /* Variable to hold the history data */
    S16 history_data = 0;
    U16 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    scr.scrnID = SCR_ID_JMMS_EDIT_CONTENT_TEXT_SETTINGS;
    scr.entryFuncPtr = mmi_jmms_entry_edit_content_text_settings;
    mmi_ucs2cpy((S8*) scr.inputBuffer, (S8*) & history_data);
    GetCategory57History(scr.guiBuffer);
    size = (U16) GetCategory57DataSize();       /* added for inline edit history */
    GetCategory57Data((U8*) scr.inputBuffer);   /* added for inline edit history */
    AddNHistory(scr, size);
    if (g_jmms_context->jmms_inline_lists != NULL)
    {
        jdd_MemFree(g_jmms_context->jmms_inline_lists);
        g_jmms_context->jmms_inline_lists = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fill_txt_setting_inline_edit_struct
 * DESCRIPTION
 *  this fn will fill the inline struct of text settings
 * PARAMETERS
 *  inline_edit_p       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fill_txt_setting_inline_edit_struct(void *inline_edit_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    InlineItem *inline_struct_p = (InlineItem*) inline_edit_p;
    U8 item_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_inline_lists == NULL)
    {
        g_jmms_context->jmms_inline_lists =
            (mmi_jmms_common_inline_lists_struct*) jdd_MemAlloc(sizeof(mmi_jmms_common_inline_lists_struct), 1);
        if (g_jmms_context->jmms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }
    g_jmms_context->jmms_inline_lists->on_off_list[1] = (S8*) GetString(STR_GLOBAL_ON);
    g_jmms_context->jmms_inline_lists->on_off_list[0] = (S8*) GetString(STR_GLOBAL_OFF);

    g_jmms_context->jmms_inline_items.text_settings_items.size_list[0] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_SIZE_SMALL);
    g_jmms_context->jmms_inline_items.text_settings_items.size_list[1] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_SIZE_MEDIUM);
    g_jmms_context->jmms_inline_items.text_settings_items.size_list[2] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_SIZE_LARGE);

    g_jmms_context->jmms_inline_items.text_settings_items.color_list[0] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR1);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[1] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR2);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[2] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR3);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[3] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR4);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[4] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR5);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[5] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_CUSTOM);

    SetInlineItemActivation(&inline_struct_p[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(
        &inline_struct_p[item_offset],
        (PU8) (U8*) GetString(STR_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT_SIZE));

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &inline_struct_p[item_offset],
        3,
        (U8 **) g_jmms_context->jmms_inline_items.text_settings_items.size_list,
        (S32*) & (g_jmms_context->jmms_inline_items.text_settings_items.size_selected) /* CurrSelect */ );

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(
        &inline_struct_p[item_offset],
        (PU8) (U8*) GetString(STR_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT_ITALIC));

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &inline_struct_p[item_offset],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        (S32*) & (g_jmms_context->jmms_inline_items.text_settings_items.italic_selected) /* CurrSelect */ );

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(
        &inline_struct_p[item_offset],
        (PU8) (U8*) GetString(STR_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT_BOLD));

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &inline_struct_p[item_offset],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        (S32*) & (g_jmms_context->jmms_inline_items.text_settings_items.bold_selected) /* CurrSelect */ );

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(
        &inline_struct_p[item_offset],
        (PU8) (U8*) GetString(STR_ID_JMMS_EDIT_CONTENT_SETTINGS_TEXT_COLOR));

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &inline_struct_p[item_offset],
        MAX_JMMS_COLOR_NUM,
        (U8 **) g_jmms_context->jmms_inline_items.text_settings_items.color_list,
        (S32*) & (g_jmms_context->jmms_inline_items.text_settings_items.color_selected) /* CurrSelect */ );
    RegisterInlineSelectHighlightHandler(&inline_struct_p[item_offset], mmi_jmms_inline_text_color_hilite_handler);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_txt_settings
 * DESCRIPTION
 *  fn shown confirmation popup when user press done on text settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_txt_settings(void)
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

    SetLeftSoftkeyFunction(mmi_jmms_save_txt_settings, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_txt_settings
 * DESCRIPTION
 *  fn to be called when user press yes on text settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_txt_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    mmi_jmms_slide_prop_struct curr_slide_prop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        &curr_slide_prop,
        &g_jmms_context->compose_context->curr_slide_info.slide_prop,
        sizeof(mmi_jmms_slide_prop_struct));

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s ", "mmi_jmms_save_txt_settings");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Save Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Save Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "Previous Save Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    if (g_jmms_context->jmms_inline_items.text_settings_items.size_selected == SIZE_SMALL)
    {
        curr_slide_prop.text_font.size = SMALL_FONT;
    }
    else if (g_jmms_context->jmms_inline_items.text_settings_items.size_selected == SIZE_LARGE)
    {
        curr_slide_prop.text_font.size = LARGE_FONT;
    }
    else
    {
        curr_slide_prop.text_font.size = MEDIUM_FONT;
    }

    curr_slide_prop.text_font.italic = g_jmms_context->jmms_inline_items.text_settings_items.italic_selected;
    curr_slide_prop.text_font.bold = g_jmms_context->jmms_inline_items.text_settings_items.bold_selected;

    if (g_jmms_context->jmms_inline_items.text_settings_items.color_selected < MAX_JMMS_COLOR_NUM - 1)
    {
        curr_slide_prop.text_color =
            g_jmms_color_RGB_list[g_jmms_context->jmms_inline_items.text_settings_items.color_selected];

    }
    else
    {
        curr_slide_prop.text_color = g_jmms_context->g_text_custom_color_rgb;
    }

    if (g_jmms_context->compose_context->curr_slide_info.text_id != 0)
    {
        err_code = mmi_jmms_set_text_attributes(
                    g_jmms_context->compose_context->curr_slide_info.text_id,
                    g_jmms_context->compose_context->curr_page_index,
                    &curr_slide_prop);
        if (err_code == JMMS_COMP_OK)
        {
            memcpy(
                &g_jmms_context->compose_context->curr_slide_info.slide_prop,
                &curr_slide_prop,
                sizeof(mmi_jmms_slide_prop_struct));
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        }
    }
    else
    {
        memcpy(
            &g_jmms_context->compose_context->curr_slide_info.slide_prop,
            &curr_slide_prop,
            sizeof(mmi_jmms_slide_prop_struct));
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Save Values: Text Size of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size,
                         g_jmms_context->jmms_inline_items.text_settings_items.size_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Save Values: Italic Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic,
                         g_jmms_context->jmms_inline_items.text_settings_items.italic_selected);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d %d",
                         "After Save Values: Bold Selection of compose context and inline item is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold,
                         g_jmms_context->jmms_inline_items.text_settings_items.bold_selected);

    GoBackHistory();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inline_text_color_hilite_handler
 * DESCRIPTION
 *  fn to be called when color is highlited in text settings.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inline_text_color_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == MAX_JMMS_COLOR_NUM - 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetCategory57LeftSoftkeyFunction(mmi_jmms_entry_txt_custom_color);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_txt_custom_color
 * DESCRIPTION
 *  entry fn for custom color screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_txt_custom_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_CUSTOM_COLOR, NULL, mmi_jmms_entry_txt_custom_color, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_CUSTOM_COLOR);
    /* MAUI_00018451 Start */
    if (gui_buffer_p == NULL)
    {
        g_jmms_context->g_slider_info = MMI_CAT91_COLOR_SLIDER_RED_COLOR;
    }
    /* MAUI_00018451 End */
    g_jmms_context->g_custom_color_RGB_list[0] = (U8) ((0xFF000000 & g_jmms_context->g_text_custom_color_rgb) >> 24);
    g_jmms_context->g_custom_color_RGB_list[1] = (U8) ((0x00FF0000 & g_jmms_context->g_text_custom_color_rgb) >> 16);
    g_jmms_context->g_custom_color_RGB_list[2] = (U8) ((0x0000FF00 & g_jmms_context->g_text_custom_color_rgb) >> 8);

    ShowCategory91Screen(
        STR_ID_JMMS_EDIT_TEXT_COLOR,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        &g_jmms_context->g_custom_color_RGB_list[0],
        &g_jmms_context->g_custom_color_RGB_list[1],
        &g_jmms_context->g_custom_color_RGB_list[2],
        /* MAUI_00018451 Start */ &g_jmms_context->g_slider_info,
        /* MAUI_00018451 End */ gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_save_txt_custom_color, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_txt_custom_color
 * DESCRIPTION
 *  fn to save customized color.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_txt_custom_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_text_custom_color_rgb = 0;
    g_jmms_context->g_text_custom_color_rgb |= 0x00000064;

    g_jmms_context->g_text_custom_color_rgb |=
        ((((U32) g_jmms_context->g_custom_color_RGB_list[0]) << 24) | (((U32) g_jmms_context->
                                                                        g_custom_color_RGB_list[1]) << 16) | (((U32)
                                                                                                               g_jmms_context->
                                                                                                               g_custom_color_RGB_list
                                                                                                               [2]) <<
                                                                                                              8));
    g_jmms_context->g_custom_var_change = 1;

    GoBackHistory();
}

/* SMIL Settings */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_smil_settings
 * DESCRIPTION
 *  Entry function when user press edit content->SETTINGS->smil settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_smil_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MAX_SUB_MENUS];   /* Stores the strings id of submenus returned */
    U16 num_item;                       /* Stores no of children in the submenu */
    U16 disp_Attribute;                 /* Stores display attribue */
    U8 *gui_buffer_p;                   /* Buffer holding history data */
    U16 parent_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS, NULL, mmi_jmms_entry_edit_content_smil_settings, NULL);

    parent_id = MENU_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL;

    SetParentHandler(parent_id);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);

    num_item = GetNumOfChild(parent_id);

    disp_Attribute = GetDispAttributeOfItem(parent_id);

    GetSequenceStringIds(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer_p);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_text_timing_settings
 * DESCRIPTION
 *  pre entry fn to enter image media timing screen for text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_text_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 duration_flag;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->compose_context->media_type = MEDIA_TEXT;
    g_jmms_context->g_custom_var_change = 0;
    /* Dilip 13th sept */
    if (g_jmms_context->compose_context->curr_slide_info.text_id < 1)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_TEXT_NOT_INSERTED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
        return;
    }
    /* DIlip 13th sept */
    err_code = mmi_jmms_get_media_time(
                &start_time,
                &duration,
                g_jmms_context->compose_context->curr_slide_info.text_id,
                g_jmms_context->compose_context->curr_page_index);

    if (err_code == JMMS_COMP_OK)
    {
        gui_itoa(
            (S32) start_time,
            (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
            10);
        duration_flag =
            g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                      1].txt_dur_max_set;
        if (duration_flag == 0 && duration != 0)
        {
            g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 1;
            gui_itoa(
                (S32) duration,
                (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                10);
        }
        else
        {
            if (g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time)
            {
                gui_itoa(
                    ((S32) g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time - start_time),
                    (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                    10);
            }
            else
            {
                gui_itoa(
                    ((S32) g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time),
                    (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                    10);
            }
            g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 0;
        }
        memcpy(
            g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
            g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
            ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
        memcpy(
            g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
            g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
            ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
        mmi_jmms_entry_smil_settings_media_timing();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_image_timing_settings
 * DESCRIPTION
 *  pre entry fn to enter image media timing screen for image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_image_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 duration_flag;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->compose_context->media_type = MEDIA_IMAGE;

    g_jmms_context->g_custom_var_change = 0;
    /* Dilip 13th sept */
    if (g_jmms_context->compose_context->curr_slide_info.image_id < 1)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_IMAGE_NOT_INSERTED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
        return;
    }
    /* DIlip 13th sept */
    else
    {
        err_code = mmi_jmms_get_media_time(
                    &start_time,
                    &duration,
                    g_jmms_context->compose_context->curr_slide_info.image_id,
                    g_jmms_context->compose_context->curr_page_index);

        if (err_code == JMMS_COMP_OK)
        {
            gui_itoa(
                (S32) start_time,
                (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
                10);
            duration_flag =
                g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                          1].img_dur_max_set;
            if (duration_flag == 0 && duration != 0)
            {
                g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 1;
                gui_itoa(
                    (S32) duration,
                    (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                    10);
            }
            else
            {
                if (g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time)
                {
                    gui_itoa(
                        ((S32) g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time - start_time),
                        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                        10);
                }
                else
                {
                    gui_itoa(
                        ((S32) g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time),
                        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                        10);
                }
                g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 0;
            }
            memcpy(
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
            memcpy(
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
            mmi_jmms_entry_smil_settings_media_timing();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_audio_timing_settings
 * DESCRIPTION
 *  pre entry fn to enter image media timing screen for audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_audio_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 duration_flag;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->compose_context->media_type = MEDIA_AUDIO;

    g_jmms_context->g_custom_var_change = 0;
    /* Dilip 13th sept */
    if (g_jmms_context->compose_context->curr_slide_info.audio_id < 1)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_AUDIO_NOT_INSERTED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
        return;
    }
    /* DIlip 13th sept */
    else
    {
        err_code = mmi_jmms_get_media_time(
                    &start_time,
                    &duration,
                    g_jmms_context->compose_context->curr_slide_info.audio_id,
                    g_jmms_context->compose_context->curr_page_index);

        if (err_code == JMMS_COMP_OK)
        {
            gui_itoa(
                (S32) start_time,
                (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
                10);

            duration_flag =
                g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index - 1].
                audio_dur_max_set;
            if (duration_flag == 0 && duration != 0)
            {
                g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 1;
                gui_itoa(
                    (S32) duration,
                    (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                    10);
            }
            else
            {
                U32 temp_duration = g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time;

                if ((U8) mmi_jmms_compose_settings_best_page_duration() == (U8) E_ON && temp_duration != 0)
                {
                    temp_duration = duration;
                }
                if (temp_duration)
                {
                    gui_itoa(
                        (S32) (temp_duration - start_time),
                        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                        10);
                }
                else
                {
                    gui_itoa(
                        (S32) temp_duration,
                        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                        10);

                }
                g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 0;
            }
            memcpy(
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
            memcpy(
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
            mmi_jmms_entry_smil_settings_media_timing();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_video_timing_settings
 * DESCRIPTION
 *  pre entry fn to enter image media timing screen for video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_video_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 duration_flag;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->compose_context->media_type = MEDIA_VIDEO;

    g_jmms_context->g_custom_var_change = 0;
    /* Dilip 13th sept */
    if (g_jmms_context->compose_context->curr_slide_info.video_id < 1)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_VIDEO_NOT_INSERTED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
        return;
    }
    /* DIlip 13th sept */
    else
    {
        err_code = mmi_jmms_get_media_time(
                    &start_time,
                    &duration,
                    g_jmms_context->compose_context->curr_slide_info.video_id,
                    g_jmms_context->compose_context->curr_page_index);

        if (err_code == JMMS_COMP_OK)
        {
            gui_itoa(
                (S32) start_time,
                (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
                10);
            duration_flag =
                g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index - 1].
                video_dur_max_set;
            if (duration_flag == 0 && duration != 0)
            {
                gui_itoa(
                    (S32) duration,
                    (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                    10);
                g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 1;
            }
            else
            {
                U32 temp_duration = g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time;

                if ((U8) mmi_jmms_compose_settings_best_page_duration() == (U8) E_ON && temp_duration != 0)
                {
                    temp_duration = duration;
                }
                if (temp_duration)
                {
                    gui_itoa(
                        (S32) (temp_duration - start_time),
                        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                        10);
                }
                else
                {
                    gui_itoa(
                        (S32) temp_duration,
                        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                        10);

                }
                g_jmms_context->jmms_inline_items.smil_settings_items.duration_select = 0;
            }
            memcpy(
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
            memcpy(
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
                g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
                ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
            mmi_jmms_entry_smil_settings_media_timing();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_smil_settings_media_timing
 * DESCRIPTION
 *  Entry function when user press edit content->SETTINGS->smil settings->media timings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_smil_settings_media_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 *input_buffer_p;
    U16 input_buffer_size;
    InlineItem smil_settings_inline_edit_list[4];

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_SMIL_SETTINGS_TEXT_TIMINGS, mmi_jmms_exit_smil_settings_media_timing, NULL, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SMIL_SETTINGS_TEXT_TIMINGS);

    input_buffer_p = GetCurrNInputBuffer(SCR_ID_JMMS_SMIL_SETTINGS_TEXT_TIMINGS, &input_buffer_size);

    InitializeCategory57Screen();

    mmi_jmms_fill_media_timing_inline_edit_struct((void*)smil_settings_inline_edit_list);

    if (input_buffer_p != NULL) /* added for inline edit history */
    {
        SetCategory57Data(smil_settings_inline_edit_list, 4, input_buffer_p);   /* sets the data */
    }

    if (GetInlineDoneFlag(gui_buffer_p) == 0)
    {
        if (g_jmms_context->g_custom_var_change == 1)
        {
            SetInlineDoneFlag(gui_buffer_p);
        }
    }

    ShowCategory57Screen(
        STR_ID_JMMS_EDIT_CONTENT_EDIT_MEDIA_TIME,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_BACK,
        4,
        (PU16) item_icons,
        smil_settings_inline_edit_list,
        0,
        gui_buffer_p);

    switch (g_jmms_context->compose_context->media_type)
    {
        case MEDIA_TEXT:
            SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_text_timing_settings, GoBackHistory);
            break;
        case MEDIA_IMAGE:
            SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_image_timing_settings, GoBackHistory);
            break;
        case MEDIA_AUDIO:
            SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_audio_timing_settings, GoBackHistory);
            break;
        case MEDIA_VIDEO:
            SetCategory57RightSoftkeyFunctions(mmi_jmms_confirm_save_video_timing_settings, GoBackHistory);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_smil_settings_media_timing
 * DESCRIPTION
 *  Exit function when user press edit content->SETTINGS->smil settings->media timing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_smil_settings_media_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history scr;    /* Variable to hold the history data */
    S16 history_data = 0;
    U16 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    scr.scrnID = SCR_ID_JMMS_SMIL_SETTINGS_TEXT_TIMINGS;
    scr.entryFuncPtr = mmi_jmms_entry_smil_settings_media_timing;
    mmi_ucs2cpy((S8*) scr.inputBuffer, (S8*) & history_data);
    GetCategory57History(scr.guiBuffer);
    size = (U16) GetCategory57DataSize();       /* added for inline edit history */
    GetCategory57Data((U8*) scr.inputBuffer);   /* added for inline edit history */
    AddNHistory(scr, size);

    if (g_jmms_context->jmms_inline_lists != NULL)
    {
        jdd_MemFree(g_jmms_context->jmms_inline_lists);
        g_jmms_context->jmms_inline_lists = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fill_media_timing_inline_edit_struct
 * DESCRIPTION
 *  this fn will fill the inline struct of smil media timings settings
 * PARAMETERS
 *  inline_edit_p       [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fill_media_timing_inline_edit_struct(void *inline_edit_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    InlineItem *inline_struct_p = (InlineItem*) inline_edit_p;
    U8 item_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->jmms_inline_lists == NULL)
    {
        g_jmms_context->jmms_inline_lists =
            (mmi_jmms_common_inline_lists_struct*) jdd_MemAlloc(sizeof(mmi_jmms_common_inline_lists_struct), 1);
        if (g_jmms_context->jmms_inline_lists == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }

    }

    g_jmms_context->jmms_inline_lists->on_off_list[0] = (S8*) GetString(STR_ID_JMMS_MAXIMUM);
    g_jmms_context->jmms_inline_lists->on_off_list[1] = (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_CUSTOM);

    SetInlineItemActivation(&inline_struct_p[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&inline_struct_p[item_offset], (PU8) GetString(STR_ID_JMMS_SMIL_SETTINGS_START_TIME));

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &inline_struct_p[item_offset],
        (PU8) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
        MAX_JMMS_SLIDE_TIME_DIGITS + 1,
        INPUT_TYPE_NUMERIC);

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&inline_struct_p[item_offset], (PU8) GetString(STR_ID_JMMS_DURATION));

    SetInlineItemActivation(&inline_struct_p[++item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &inline_struct_p[item_offset],
        2,
        (U8 **) g_jmms_context->jmms_inline_lists->on_off_list,
        (S32*) & (g_jmms_context->jmms_inline_items.smil_settings_items.duration_select) /* CurrSelect */ );

    RegisterInlineSelectHighlightHandler(&inline_struct_p[item_offset], mmi_jmms_inline_media_timings_hilite_handler);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_media_duration
 * DESCRIPTION
 *  fn to be called before entry media duration screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_media_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
        ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
    mmi_jmms_entry_media_duration();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_inline_media_timings_hilite_handler
 * DESCRIPTION
 *  fn to be called when duration is highlited in media time settings.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_inline_media_timings_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 1)
    {
        ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
        SetCategory57LeftSoftkeyFunction(mmi_jmms_pre_entry_media_duration);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_media_duration
 * DESCRIPTION
 *  entry fn for custom media duration screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_media_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_SMIL_SETTINGS_MEDIA_TIMINGS_DURATION, NULL, mmi_jmms_entry_media_duration, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SMIL_SETTINGS_MEDIA_TIMINGS_DURATION);

    ShowCategory5Screen(
        STR_ID_JMMS_DURATION,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
        MAX_JMMS_MEDIA_DURATION_DIGITS + 1,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_save_custom_media_duration, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_custom_media_duration
 * DESCRIPTION
 *  fn to change the value change in custom duartion.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_custom_media_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_custom_var_change = 1;
    memcpy(
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
        ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_text_timing_settings
 * DESCRIPTION
 *  fn to show the confirmation popup when user press done on text timings settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_text_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time &&
        start_time >= g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_SLIDE_TIME_EXCEED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_jmms_save_text_timing_settings, KEY_EVENT_UP);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_text_timing_settings
 * DESCRIPTION
 *  fn to be called when user press yes on text settings confirmation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_text_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 max_set;

    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_temp_buffer,
        ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->jmms_inline_items.smil_settings_items.duration_select == 0)
    {
        duration = 0;
        max_set = 1;
    }
    else
    {
        duration =
            (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.
                           media_duration_edit_buffer);
        max_set = 0;
    }

    err_code = mmi_jmms_set_media_time(
                start_time,
                duration,
                g_jmms_context->compose_context->curr_slide_info.text_id,
                g_jmms_context->compose_context->curr_page_index);

    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].txt_dur_max_set = max_set;

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_image_timing_settings
 * DESCRIPTION
 *  fn to show the confirmation popup when user press done on image timings settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_image_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time &&
        start_time >= g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_SLIDE_TIME_EXCEED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_jmms_save_image_timing_settings, KEY_EVENT_UP);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_image_timing_settings
 * DESCRIPTION
 *  fn to be called when user press yes on image timings settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_image_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 max_set;

    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
        ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->jmms_inline_items.smil_settings_items.duration_select == 0)
    {
        duration = 0;
        max_set = 1;
    }
    else
    {
        duration =
            (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.
                           media_duration_edit_buffer);
        max_set = 0;
    }

    err_code = mmi_jmms_set_media_time(
                start_time,
                duration,
                g_jmms_context->compose_context->curr_slide_info.image_id,
                g_jmms_context->compose_context->curr_page_index);

    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].img_dur_max_set = max_set;

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_audio_timing_settings
 * DESCRIPTION
 *  fn to show the confirmation popup when user press done on audio timings settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_audio_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time &&
        start_time >= g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_SLIDE_TIME_EXCEED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_jmms_save_audio_timing_settings, KEY_EVENT_UP);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_audio_timing_settings
 * DESCRIPTION
 *  fn to be called when user press yes on audio timings settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_audio_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 max_set;

    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
        ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->jmms_inline_items.smil_settings_items.duration_select == 0)
    {
        duration = 0;
        max_set = 1;
    }
    else
    {
        duration =
            (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.
                           media_duration_edit_buffer);
        max_set = 0;
    }
    err_code = mmi_jmms_set_media_time(
                start_time,
                duration,
                g_jmms_context->compose_context->curr_slide_info.audio_id,
                g_jmms_context->compose_context->curr_page_index);
    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].audio_dur_max_set = max_set;

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_save_video_timing_settings
 * DESCRIPTION
 *  fn to show the confirmation popup when user press done on video timings settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_save_video_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time &&
        start_time >= g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_SLIDE_TIME_EXCEED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_GLOBAL_SAVE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetLeftSoftkeyFunction(mmi_jmms_save_video_timing_settings, KEY_EVENT_UP);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_video_timing_settings
 * DESCRIPTION
 *  fn to be called when user press yes on video settings confirmation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_video_timing_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_time, duration;
    U8 max_set;

    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_buffer,
        g_jmms_context->jmms_inline_items.smil_settings_items.media_duration_edit_done_buffer,
        ((MAX_JMMS_MEDIA_DURATION_DIGITS + 1) * ENCODING_LENGTH));
    start_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    if (g_jmms_context->jmms_inline_items.smil_settings_items.duration_select == 0)
    {
        duration = 0;
        max_set = 1;
    }
    else
    {
        duration =
            (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.
                           media_duration_edit_buffer);
        max_set = 0;
    }
    err_code = mmi_jmms_set_media_time(
                start_time,
                duration,
                g_jmms_context->compose_context->curr_slide_info.video_id,
                g_jmms_context->compose_context->curr_page_index);

    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].video_dur_max_set = max_set;

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_smil_bg_color_settings
 * DESCRIPTION
 *  entry fn for BG color smil settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_smil_bg_color_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_SMIL_SETTINGS_BG_COLOR, NULL, mmi_jmms_entry_smil_bg_color_settings, NULL);

    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_SMIL_SETTINGS_BG_COLOR);
    RegisterHighlightHandler(mmi_jmms_bg_color_highlight_hdlr);

    for (count = 0;
         g_jmms_context->compose_context->mms_bg_color != g_jmms_color_RGB_list[count] &&
         count < MAX_JMMS_COLOR_NUM - 1; count++);

    if (count == MAX_JMMS_COLOR_NUM - 1)
    {
        g_jmms_context->jmms_inline_items.text_settings_items.color_selected = MAX_JMMS_COLOR_NUM - 1;
    }
    else
    {
        g_jmms_context->jmms_inline_items.text_settings_items.color_selected = count;
        /* MAUI_00018544 Start */
        g_jmms_context->g_bg_custom_color_rgb = 0x00000064;
        /* MAUI_00018544 End */
    }

    g_jmms_context->jmms_inline_items.text_settings_items.color_list[0] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR1);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[1] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR2);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[2] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR3);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[3] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR4);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[4] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_COLOR5);
    g_jmms_context->jmms_inline_items.text_settings_items.color_list[5] =
        (S8*) GetString(STR_ID_JMMS_TEXT_SETTINGS_CUSTOM);

    ShowCategory53Screen(
        STR_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_BGCOLOR,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (S32) MAX_JMMS_COLOR_NUM,
        (U8 **) g_jmms_context->jmms_inline_items.text_settings_items.color_list,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        g_jmms_context->jmms_inline_items.text_settings_items.color_selected,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_select_bg_color, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_bg_color_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for Bg color screen.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_bg_color_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->curr_scr_hilite_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_select_bg_color
 * DESCRIPTION
 *  fn to be called when bg color is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_select_bg_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bg_color;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->curr_scr_hilite_index >= MAX_JMMS_COLOR_NUM - 1)
    {
        g_jmms_context->g_custom_color_RGB_list[0] = (U8) ((0xFF000000 & g_jmms_context->g_bg_custom_color_rgb) >> 24);
        g_jmms_context->g_custom_color_RGB_list[1] = (U8) ((0x00FF0000 & g_jmms_context->g_bg_custom_color_rgb) >> 16);
        g_jmms_context->g_custom_color_RGB_list[2] = (U8) ((0x0000FF00 & g_jmms_context->g_bg_custom_color_rgb) >> 8);
        mmi_jmms_entry_bg_custom_color();
    }
    else
    {
        bg_color = g_jmms_color_RGB_list[g_jmms_context->curr_scr_hilite_index];
        err_code = mmi_jmms_set_bg_color(bg_color);

        if (err_code == JMMS_COMP_OK)
        {
            g_jmms_context->compose_context->mms_bg_color = bg_color;
            mmi_jmms_set_region_list();
            DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        }

        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_bg_custom_color
 * DESCRIPTION
 *  entry fn for background custom color screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_bg_custom_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_CUSTOM_COLOR, NULL, mmi_jmms_entry_bg_custom_color, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_CUSTOM_COLOR);
    /* MAUI_00018451 Start */
    if (gui_buffer_p == NULL)
    {
        g_jmms_context->g_slider_info = MMI_CAT91_COLOR_SLIDER_RED_COLOR;
    }
    /* MAUI_00018451 End */
    ShowCategory91Screen(
        STR_ID_JMMS_EDIT_CONTENT_SETTINGS_SMIL_BGCOLOR,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        &g_jmms_context->g_custom_color_RGB_list[0],
        &g_jmms_context->g_custom_color_RGB_list[1],
        &g_jmms_context->g_custom_color_RGB_list[2],
        /* MAUI_00018451 Start */ &g_jmms_context->g_slider_info,
        /* MAUI_00018451 End */ gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_save_smil_bg_custom_color, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_smil_bg_custom_color
 * DESCRIPTION
 *  fn to save background customized color.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_smil_bg_custom_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->g_bg_custom_color_rgb &= 0x00000064;
    g_jmms_context->g_bg_custom_color_rgb |=
        ((((U32) g_jmms_context->g_custom_color_RGB_list[0]) << 24) | (((U32) g_jmms_context->
                                                                        g_custom_color_RGB_list[1]) << 16) | (((U32)
                                                                                                               g_jmms_context->
                                                                                                               g_custom_color_RGB_list
                                                                                                               [2]) <<
                                                                                                              8));

    err_code = mmi_jmms_set_bg_color(g_jmms_context->g_bg_custom_color_rgb);

    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->mms_bg_color = g_jmms_context->g_bg_custom_color_rgb;
        mmi_jmms_set_region_list();
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
    }

    DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SMIL_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_edit_content_slide_time
 * DESCRIPTION
 *  pre entry fn for slide duration screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_edit_content_slide_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * if(g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time==0)
     * {
     * g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time=mmi_jmms_compose_settings_default_slide_time();
     * }
     */
    gui_itoa(
        (S32) g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time,
        (UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
        10);
    mmi_jmms_entry_edit_content_slide_time();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_slide_time
 * DESCRIPTION
 *  entry fn for slide duration screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_slide_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_EDIT_CONTENT_SLIDE_TIME, NULL, mmi_jmms_entry_edit_content_slide_time, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT_SLIDE_TIME);

    ShowCategory5Screen(
        STR_ID_JMMS_EDIT_SLIDE_TIME,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_NUMERIC,
        g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer,
        MAX_JMMS_MEDIA_DURATION_DIGITS + 1,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_jmms_save_edit_content_slide_timing, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_edit_content_slide_timing
 * DESCRIPTION
 *  fn save the slide timings when user press ok on slide timings settings.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_edit_content_slide_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    U32 slide_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2ncmp
        ((S8*) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer, "\0",
         1 * ENCODING_LENGTH) == 0)
    {
        DisplayPopup((U8*) GetString(STR_ID_SLIDE_TIME_ZERO_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        return;
    }
    slide_time =
        (U32) gui_atoi((UI_string_type) g_jmms_context->jmms_inline_items.smil_settings_items.slide_time_edit_buffer);
    err_code = mmi_jmms_save_post_entry_edit_content_slide_timing(slide_time);
    if (err_code != JMMS_COMP_OK)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_MEDIA_TIME_EXCEED),
            IMG_GLOBAL_WARNING,
            1,
            JMMS_POPUP_TIME,
            WARNING_TONE);
        return;
    }
    err_code = mmi_jmms_save_page_time(slide_time);
    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.slide_prop.slide_time = slide_time;

        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, JMMS_POPUP_TIME, SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SETTINGS);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_SETTINGS);
    }

}

/* edit content screen */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_pre_entry_edit_content_screen
 * DESCRIPTION
 *  pre entry fn for edit content screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_pre_entry_edit_content_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_count;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s ", "mmi_jmms_pre_entry_edit_content_screen");
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Previous Set Values: Text Size of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Previous Set Values: Italic Selection of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "Previous Set Values: Bold Selection of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold);
#ifdef __DRM_SUPPORT__
    if (mmi_jmms_is_drm_fwd_lock_media_in_mms(g_jmms_context->msg_handle, E_TRUE) == E_TRUE)
    {
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
    if (g_jmms_context->compose_context == NULL)
    {
        g_jmms_context->compose_context =
            (mmi_jmms_compose_context_struct*) jdd_MemAlloc(sizeof(mmi_jmms_compose_context_struct), 1);
        if (g_jmms_context->compose_context == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
    }

    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);
    g_jmms_context->compose_context->curr_page_index = 0;

    if (page_count == 0)
    {
        g_jmms_context->compose_context->mms_bg_color = g_jmms_color_RGB_list[COLOR_WHITE];
        /* PMT HIMANSHU START 20060425 */
        /* Added by Deepali for root layout */
        err_code = mmi_jmms_set_bg_color(g_jmms_context->compose_context->mms_bg_color);
        if (err_code == JMMS_COMP_OK)
            /* PMT HIMANSHU END 20060425 */
        {
            err_code = mmi_jmms_compose_insert_slide();
        }

    }
    else
    {
        err_code = mmi_jmms_get_bg_color(&(g_jmms_context->compose_context->mms_bg_color));
        g_jmms_context->compose_context->curr_page_index = 1;

        if (err_code == JMMS_COMP_OK)
        {
            err_code = mmi_jmms_extract_slide_media_info(g_jmms_context->compose_context->curr_page_index);
        }
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "After Set Values: Text Size of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "After Set Values: Italic Selection of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d", "After Set Values: Bold Selection of compose context is: ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold);

    if (err_code == JMMS_COMP_OK)
    {
        mmi_jmms_entry_edit_content_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_edit_content_scr_bg_color
 * DESCRIPTION
 *  set bg-color for MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
color mmi_jmms_get_edit_content_scr_bg_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_convert_u32_to_color(&bg_color, g_jmms_context->compose_context->mms_bg_color);
    return bg_color;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_edit_content_scr_txt_color
 * DESCRIPTION
 *  set txt-color for MMS slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
color mmi_jmms_get_edit_content_scr_txt_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_convert_u32_to_color(&text_color, g_jmms_context->compose_context->curr_slide_info.slide_prop.text_color);
    return text_color;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_edit_content_scr_txt_font
 * DESCRIPTION
 *  set txt-font for MMS slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
UI_font_type mmi_jmms_get_edit_content_scr_txt_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font);
}


/*****************************************************************************
 * FUNCTION
 *  GoBacktoWriteMMS
 * DESCRIPTION
 *  set dlag of write MMS screen as done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBacktoWriteMMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* JMMS_COMP_ERRCODE err_code; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 0, &num_attchments, E_TRUE);
     * mmi_jmms_jdi_get_media_count(g_jmms_context->msg_handle, 1, &num_inline_media, E_FALSE);
     * mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &num_pages);
     * 
     * if ((num_pages == 1) && (num_inline_media == 0)
     * && (jc_tcslen((UI_character_type*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) == 0)
     * && g_jmms_context->compose_context->curr_slide_info.audio_id == 0
     * && g_jmms_context->compose_context->curr_slide_info.image_id == 0
     * && g_jmms_context->compose_context->curr_slide_info.video_id == 0)
     * {
     * err_code = mmi_jmms_compose_delete_page(1);
     * if (err_code == JMMS_COMP_OK)
     * {
     * g_jmms_context->compose_context->curr_page_index = 0;
     * num_pages = 0;
     * }
     * }
     * 
     * if (num_attchments > 0 || num_pages > 0 || num_inline_media > 0)
     * {
     * g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;
     * }
     */
    g_jmms_context->g_write_mms_right_soft_key = STR_GLOBAL_DONE;

    if (mmi_jmms_exit_curr_slide() == JMMS_COMP_POPUP_OK)
    {
        DeleteUptoScrID(SCR_ID_JMMS_WRITE_MMS);
    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_WRITE_MMS);
    }
}

/* Functions for Category 275 */

#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
#define SMIL_EDITOR_TEXT_MIN_HEIGHT       80    // TODO: reference GUI definition
#else 
#define SMIL_EDITOR_TEXT_MIN_HEIGHT       54    // TODO: reference GUI definition
#endif 

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)
#define SMIL_EDITOR_IMAGE_MAX_HEIGHT (GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT - MMI_STATUS_BAR_HEIGHT - SMIL_EDITOR_TEXT_MIN_HEIGHT)
#else 
#define SMIL_EDITOR_IMAGE_MAX_HEIGHT (GDI_LCD_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_TITLE_HEIGHT - SMIL_EDITOR_TEXT_MIN_HEIGHT - INFORMATION_BAR_HEIGHT)
#endif 

#define SMIL_EDITOR_IMAGE_MAX_WIDTH (GDI_LCD_WIDTH - (JMMS_HORZN_MARGIN_SPACE * 2) )

#define SMIL_EDITOR_IMAGE_CACHE_BUF_SIZE  \
         ( SMIL_EDITOR_IMAGE_MAX_WIDTH * SMIL_EDITOR_IMAGE_MAX_HEIGHT * (GDI_MAINLCD_BIT_PER_PIXEL>>3))


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compute_edit_content_screen_layout
 * DESCRIPTION
 *  calculates the layout area.
 * PARAMETERS
 *  area1_height_p      [OUT]       
 *  area2_height_p      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compute_edit_content_screen_layout(U16 *area1_height_p, U16 *area2_height_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0, height = 0, width_bound1 = 0, height_bound1 = 0, img_width = 0, img_height = 0;
    S32 zoom_x = 0, zoom_y = 0, zoom_width = 0, zoom_height = 0;
    U8 *temp_file_name_p = g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p;
    U32 max_width;

#ifdef __MMI_VIDEO_PLAYER__
    MDI_RESULT result_video = 0;
    U32 img_widthv = 0, img_heightv = 0;
#endif /* __MMI_VIDEO_PLAYER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width_bound1 = 0;
    *area1_height_p = 0;
    max_width = MMI_content_width - (current_MMI_theme->scrollbar_size * 2 + JMMS_HORZN_MARGIN_SPACE * 2) * 2;
    if (g_jmms_context->compose_context->curr_slide_info.video_id != 0 ||
        g_jmms_context->compose_context->curr_slide_info.image_id != 0 ||
        g_jmms_context->compose_context->curr_slide_info.audio_id != 0 || g_jmms_context->num_attachments > 0)
    {
        *area1_height_p += JMMS_VERT_ICON_MARGIN_SPACE * 2;
        gui_measure_image((PU8) GetImage(IMG_ID_JMMS_SMIL_EDITOR_PIC_ICON), &width, &height);
        *area1_height_p += height;
        width_bound1 =
            (max_width >
             (SMIL_EDITOR_IMAGE_MAX_WIDTH - (JMMS_HORZN_MARGIN_SPACE * 2))) ? (SMIL_EDITOR_IMAGE_MAX_WIDTH -
                                                                               (JMMS_HORZN_MARGIN_SPACE *
                                                                                2)) : max_width;
        height_bound1 = (SMIL_EDITOR_IMAGE_MAX_HEIGHT - JMMS_VERT_ICON_MARGIN_SPACE * 2);
    }
    else
    {
        height_bound1 = 0;
        *area1_height_p = 0;
        *area2_height_p = 0;
        height = 0;

    }
#ifdef __MMI_VIDEO_PLAYER__
    if (g_jmms_context->compose_context->curr_slide_info.video_id != 0)
    {
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_media_drm_permitted((JC_CHAR*) temp_file_name_p, DRM_PERMISSION_PLAY))
        {
            result_video = mmi_jdd_videoapp_get_video_file_size_info((S8*) temp_file_name_p, &img_widthv, &img_heightv);
            img_width = img_widthv;
            img_height = img_heightv;
        }
        else
        {
            gdi_image_get_dimension((PU8) GetImage(IMG_ID_JATAAYU_JDD_ALT_DRM_VIDEO), &img_width, &img_height);
        }
    #else /* __DRM_SUPPORT__ */ 
        result_video = mmi_jdd_videoapp_get_video_file_size_info((S8*) temp_file_name_p, &img_widthv, &img_heightv);
        img_width = img_widthv;
        img_height = img_heightv;
    #endif /* __DRM_SUPPORT__ */ 
    }
    else
#endif /* __MMI_VIDEO_PLAYER__ */ 
    if (g_jmms_context->compose_context->curr_slide_info.image_id != 0)
    {
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_media_drm_permitted((JC_CHAR*) temp_file_name_p, DRM_PERMISSION_DISPLAY))
        {
            gdi_image_get_dimension_file((S8*) temp_file_name_p, &img_width, &img_height);
        }
        else
        {
            gdi_image_get_dimension((PU8) GetImage(IMG_ID_JATAAYU_JDD_ALT_DRM_IMAGE), &img_width, &img_height);
        }
    #else /* __DRM_SUPPORT__ */ 
        gdi_image_get_dimension_file((S8*) temp_file_name_p, &img_width, &img_height);
    #endif /* __DRM_SUPPORT__ */ 
    }

    if (g_jmms_context->compose_context->curr_slide_info.video_id != 0 ||
        g_jmms_context->compose_context->curr_slide_info.image_id != 0)
    {
        /* Himanshu - Fixed bug MAUI_00228009 START */
        if ((img_width < width_bound1) && (img_height < height_bound1))
        {
            zoom_width = img_width;
            zoom_height = img_height;
        }
        else
        {
            gdi_image_util_fit_bbox(
                width_bound1,
                height_bound1,
                img_width,
                img_height,
                &zoom_x,
                &zoom_y,
                &zoom_width,
                &zoom_height);
        }
        /* Himanshu - Fixed bug MAUI_00228009 END */
    }

    if (g_jmms_context->compose_context->curr_slide_info.image_id == 0 &&
        g_jmms_context->compose_context->curr_slide_info.video_id == 0)
    {
        *area2_height_p = 0;
    }
    else if (g_jmms_context->compose_context->is_image_first[0] == 1)
    {

        *area2_height_p = 0;

        *area1_height_p += SMIL_EDITOR_IMAGE_MAX_HEIGHT + JMMS_VERT_IMAGE_MARGIN_SPACE;

    }
    else
    {
        *area2_height_p = SMIL_EDITOR_IMAGE_MAX_HEIGHT + JMMS_VERT_IMAGE_MARGIN_SPACE * 2;
    }

    g_jmms_context->compose_context->curr_slide_info.img_info.img_x = (MMI_content_width - zoom_width) >> 1;
    /* Himanshu - Media should be center-aligned */
    /* g_jmms_context->compose_context->curr_slide_info.img_info.img_y = JMMS_VERT_ICON_MARGIN_SPACE; */
    g_jmms_context->compose_context->curr_slide_info.img_info.img_y =
        JMMS_VERT_ICON_MARGIN_SPACE + ((height_bound1 >> 1) - (zoom_height >> 1));
    g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_width = zoom_width;
    g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_height = zoom_height;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_smil_editor_title
 * DESCRIPTION
 *  callback fn to show smil editor title.
 * PARAMETERS
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_smil_editor_title(U32 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width, character_height;
    S32 x_start;
    U8 title_buffer[20];
    U8 title_temp_buffer[16];
    U8 page_count = 0;
    U32 mms_size = 0;   /* , mms_bytes = 0; */
    FLOAT mms_kb_size = 0, mms_mb_size = 0, mms_gb_size = 0, mms_tb_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_jdi_get_total_pages(g_jmms_context->msg_handle, &page_count);

    sprintf((S8*) title_temp_buffer, "%d/%d", identifier, page_count);
    mmi_asc_to_ucs2((S8*) title_buffer, (S8*) title_temp_buffer);

    /* Himanshu - For fixing MAUI_00227854 START */
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
    /* 
     * In 128x128 and 128x160, MMS editor title font size will use MMI_small_font.
     * It avoid the title string1 and string2 overlap.
     */
    MMI_title_string = NULL;
#else /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 
    MMI_title_string = (UI_string_type) title_buffer;
#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 
    /* Himanshu - For fixing MAUI_00227854 END */
    MMI_title_icon = (PU8) get_image(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));

    show_title_status_icon();
    draw_title();

    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_set_text_clip(MMI_title_x, MMI_title_y, MMI_title_x + MMI_title_width - 1, MMI_title_y + MMI_title_height - 1);

    gui_set_font(&MMI_small_font);

    /* Himanshu - For fixing MAUI_00227854 START */
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__)
    /* 
     * In 128x128 and 128x160, MMS editor title font size will use MMI_small_font.
     * It avoid the title string1 and string2 overlap.
     */

    /* draw title string 1 */
    gui_measure_string((UI_string_type) title_buffer, &text_width, &character_height);
    if (r2lMMIFlag)
    {
        x_start = (MMI_title_x + MMI_title_width) / 2 + text_width / 2;
    }
    else
    {
        x_start = (MMI_title_x + MMI_title_width) / 2 - text_width / 2;
    }
    gui_move_text_cursor(x_start, MMI_title_y + ((MMI_title_height - character_height) >> 1));
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_print_text((UI_string_type) title_buffer);

#endif /* defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) */ 
    /* Himanshu - For fixing MAUI_00227854 END */

    mmi_jmms_jdi_get_size(g_jmms_context->msg_handle, 0, &mms_size);

    /* mms_bytes = mms_size % 1024; */
    mms_kb_size = (FLOAT) mms_size / 1024;
    mms_mb_size = mms_kb_size / 1024;
    mms_gb_size = mms_mb_size / 1024;
    mms_tb_size = mms_gb_size / 1024;

    /* Himanshu - For fixing MAUI_00227854 START */
    if (mms_kb_size < 10.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.2f%s", mms_kb_size, "KB");
    }
    else if (mms_kb_size < 100.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.1f%s", mms_kb_size, "KB");
    }
    else if (mms_kb_size < 1000.0)
    {
        sprintf((S8*) title_temp_buffer, "%d%s", (U32) mms_kb_size, "KB");
    }
    else if (mms_mb_size < 10.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.2f%s", mms_mb_size, "MB");
    }
    else if (mms_mb_size < 100.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.1f%s", mms_mb_size, "MB");
    }
    else if (mms_mb_size < 1000.0)
    {
        sprintf((S8*) title_temp_buffer, "%d%s", (U32) mms_mb_size, "MB");
    }
    else if (mms_gb_size < 10.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.2f%s", mms_gb_size, "GB");
    }
    else if (mms_gb_size < 100.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.1f%s", mms_gb_size, "GB");
    }
    else if (mms_gb_size < 1000.0)
    {
        sprintf((S8*) title_temp_buffer, "%d%s", (U32) mms_gb_size, "GB");
    }
    else if (mms_tb_size < 4.1)
    {
        sprintf((S8*) title_temp_buffer, "%0.2f%s", mms_tb_size, "TB");
    }
    else
    {
        /*
         * As the maximum limit of U32 datatype is 4294967295 which is equivalent to 4.0 TB
         */
        ASSERT(0);
    }
    /* Himanshu - For fixing MAUI_00227854 END */

    mmi_asc_to_ucs2((S8*) title_buffer, (S8*) title_temp_buffer);

    gui_measure_string((UI_string_type) title_buffer, &text_width, &character_height);

    /* Himanshu - For fixing MAUI_00227920 START */
    if (r2lMMIFlag)
    {
        x_start = MMI_title_x + text_width + 3;
    }
    else
    {
        x_start = MMI_title_x + MMI_title_width - text_width - 4;
    }
    /* Himanshu - For fixing MAUI_00227920 END */

    gui_move_text_cursor(x_start, MMI_title_y + ((MMI_title_height - character_height) >> 1));
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_print_text((UI_string_type) title_buffer);
    gui_set_font(&MMI_medium_font);

    gui_pop_text_clip();
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_smil_editor_draw_area_1
 * DESCRIPTION
 *  callback fn to show smil draw area 1
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  clip_x1         [IN]        
 *  clip_y1         [IN]        
 *  clip_x2         [IN]        
 *  clip_y2         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_smil_editor_draw_area_1(
        U32 identifier,
        S32 y_offset,
        S32 clip_x1,
        S32 clip_y1,
        S32 clip_x2,
        S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, icon_x;
    S32 width, height;
    U32 vbar_width = current_MMI_theme->scrollbar_size;
    U32 max_width;
    S32 largest_y;
    color c = {100, 150, 200, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set clipping */
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    /* Show attachment icon */
    x1 = clip_x1;
    y1 = y_offset;
    gui_measure_image((PU8) GetImage(IMG_ID_JMMS_EDIT_CONTENT_AUDIO), &width, &height);
    y2 = y1 + height;
    x2 = clip_x2 - JMMS_VERT_ICON_MARGIN_SPACE;
    max_width = MMI_content_width - (vbar_width + JMMS_HORZN_MARGIN_SPACE) * 2;
    x2 = ((x2 - x1) > max_width) ? (x1 + max_width) : x2;
    x1 = x1 + vbar_width;
    gui_fill_rectangle(x1, y1, x2, y2, c);
    g_jmms_context->compose_context->curr_slide_info.img_info.img_x = x1 +
        (((x2 - x1) - g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_width) >> 1);
    largest_y = y2;

    icon_x = x1 + JMMS_HORZN_MARGIN_SPACE;
    if (g_jmms_context->num_attachments > 0)
    {
        gui_show_image(icon_x, y1, (PU8) GetImage(IMG_ID_JMMS_EDIT_CONTENT_ATTACHMENT));
        icon_x = icon_x + width + JMMS_HORZN_MARGIN_SPACE;
    }

    if (g_jmms_context->compose_context->curr_slide_info.audio_id != 0)
    {
        gui_show_image(icon_x, y1, (PU8) GetImage(IMG_ID_JMMS_EDIT_CONTENT_AUDIO));
        icon_x = icon_x + width + JMMS_HORZN_MARGIN_SPACE;
    }

    if (((g_jmms_context->compose_context->curr_slide_info.video_id != 0) ||
         (g_jmms_context->compose_context->curr_slide_info.image_id != 0)))
    {
        if (g_jmms_context->compose_context->is_image_first[0] == 1)
        {
            gui_draw_rectangle(x1, largest_y, x2, largest_y + SMIL_EDITOR_IMAGE_MAX_HEIGHT, c);
        }
        if (g_jmms_context->compose_context->curr_slide_info.video_id != 0)
        {
            gui_show_image(icon_x, y1, (PU8) GetImage(IMG_ID_JMMS_SMIL_EDITOR_VIDEO_ICON));
        }
        else
        {
            gui_show_image(icon_x, y1, (PU8) GetImage(IMG_ID_JMMS_SMIL_EDITOR_PIC_ICON));
        }
    }

    if ((g_jmms_context->compose_context->curr_slide_info.video_id != 0) &&
        (g_jmms_context->compose_context->is_image_first[0] == 1))
    {
        mmi_jmms_smil_editor_show_video_from_file(largest_y);
    }

    if ((g_jmms_context->compose_context->curr_slide_info.image_id != 0) &&
        (g_jmms_context->compose_context->is_image_first[0] == 1))
    {
        mmi_jmms_smil_editor_show_image_from_file(largest_y);
    }

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_smil_editor_draw_area_2
 * DESCRIPTION
 *  callback fn to show smil draw area 2
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  clip_x1         [IN]        
 *  clip_y1         [IN]        
 *  clip_x2         [IN]        
 *  clip_y2         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_smil_editor_draw_area_2(
        U32 identifier,
        S32 y_offset,
        S32 clip_x1,
        S32 clip_y1,
        S32 clip_x2,
        S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS START 20060502 */
    S32 max_width, x1, x2, y2;
    color c = {100, 150, 200, 100};
    U32 vbar_width = current_MMI_theme->scrollbar_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT VIKAS START 20060502 */
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    max_width = MMI_content_width - (vbar_width + JMMS_HORZN_MARGIN_SPACE) * 2;
    x1 = clip_x1;
    x2 = ((clip_x2 - clip_x1) > max_width) ? (clip_x1 + max_width) : clip_x2;
    y2 = y_offset + SMIL_EDITOR_IMAGE_MAX_HEIGHT + JMMS_VERT_IMAGE_MARGIN_SPACE + JMMS_VERT_ICON_MARGIN_SPACE * 2;
    x1 = x1 + vbar_width;
    g_jmms_context->compose_context->curr_slide_info.img_info.img_x = x1 +
        (((x2 - x1) - g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_width) >> 1);

    if (((g_jmms_context->compose_context->curr_slide_info.video_id != 0) ||
         (g_jmms_context->compose_context->curr_slide_info.image_id != 0)) &&
        (g_jmms_context->compose_context->is_image_first[0] == 0))
    {
        gui_draw_rectangle(x1, y_offset + JMMS_VERT_IMAGE_MARGIN_SPACE, x2, y2, c);
    }

    if ((g_jmms_context->compose_context->curr_slide_info.image_id != 0) &&
        (g_jmms_context->compose_context->is_image_first[0] == 0))
    {
        mmi_jmms_smil_editor_show_image_from_file(y_offset + JMMS_VERT_IMAGE_MARGIN_SPACE +
                                                  JMMS_VERT_ICON_MARGIN_SPACE);
    }
    if ((g_jmms_context->compose_context->curr_slide_info.video_id != 0) &&
        (g_jmms_context->compose_context->is_image_first[0] == 0))
    {
        mmi_jmms_smil_editor_show_video_from_file(y_offset + JMMS_VERT_IMAGE_MARGIN_SPACE +
                                                  JMMS_VERT_ICON_MARGIN_SPACE);
    }
    /* PMT VIKAS END20060502 */

    gui_pop_clip();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_key_handler_for_back
 * DESCRIPTION
 *  entry fn for edit content screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_key_handler_for_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &key_type);
    if (keyCode == KEY_CLEAR)
    {
        /* No need to do any thing */
    }
    else
    {
        GoBacktoWriteMMS();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer_p;
    U16 area1_height, area2_height;
    UI_font_type text_font;
    color text_color;
    color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s ", "mmi_jmms_entry_edit_content_screen");

    EntryNewScreen(
        SCR_ID_JMMS_EDIT_CONTENT,
        mmi_jmms_exit_edit_content_screen,
        mmi_jmms_entry_edit_content_screen,
        NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_EDIT_CONTENT);

    if (g_jmms_context->g_media_buffer_p != NULL)
    {
        jdd_MemFree(g_jmms_context->g_media_buffer_p);
        g_jmms_context->g_media_buffer_p = NULL;
    }

    mmi_jmms_compute_edit_content_screen_layout(&area1_height, &area2_height);
    g_jmms_context->compose_context->exit_conpose_screen = 0;

    if ((g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display == 1)
        || (g_jmms_context->compose_context->curr_slide_info.img_info.img_delete))
    {
        gui_lock_double_buffer();
    }

    bg_color = mmi_jmms_get_edit_content_scr_bg_color();
    text_color = mmi_jmms_get_edit_content_scr_txt_color();
    text_font = mmi_jmms_get_edit_content_scr_txt_font();

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d ", "Compose Context Values: Text Size of compose context : ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.size);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d ", "Compose Context Values: Italic Selection of compose context : ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.italic);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s %d ", "Compose Context Values: Bold Selection of compose context : ",
                         g_jmms_context->compose_context->curr_slide_info.slide_prop.text_font.bold);

    ShowCategory277Screen(
        (U32) g_jmms_context->compose_context->curr_page_index,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_DONE,
        IMG_GLOBAL_OK,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
        g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
        (S32) (JMMS_COMPOSE_TEXT_LENGTH + 1),
        (U16) current_MMI_theme->scrollbar_size,
        mmi_jmms_show_smil_editor_title,
        area1_height,
        mmi_jmms_show_smil_editor_draw_area_1,
        area2_height,
        mmi_jmms_show_smil_editor_draw_area_2,
        &text_font,
        &text_color,
        &text_color,
        &bg_color,
        gui_buffer_p);

    /* sandeep start Nov 21 for bug number PMT005940 */

    if (g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display == 1)
    {
        if (g_jmms_context->compose_context->curr_slide_info.image_id != 0)
        {
            if (g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] ==
                0)
            {
                Category275GotoBottom();
            }
            else
            {
                Category275GotoTop();
            }
        }
        else if (g_jmms_context->compose_context->curr_slide_info.video_id != 0)
        {
            if (g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] ==
                0)
            {
                Category275GotoBottom();
            }
            else
            {
                Category275GotoTop();
            }
        }

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 0;
    }
    else if (g_jmms_context->compose_context->curr_slide_info.img_info.img_delete)
    {
        if (g_jmms_context->compose_context->curr_slide_info.img_info.img_delete & 2)   /* check if second bit is set then image is not first */
        {
            Category275GotoBottom();
        }
        else
        {
            Category275GotoTop();
        }
        g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 0;
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

    /* sandeep end Nov 21 for bug number PMT005940 */

    SetLeftSoftkeyFunction(mmi_jmms_show_edit_content_option, KEY_EVENT_UP);
    SetCategory275RightSoftkeyFunction(mmi_jmms_key_handler_for_back, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_exit_edit_content_screen
 * DESCRIPTION
 *  entry fn for edit content screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_exit_edit_content_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_media_buffer_p != NULL)
    {
        jdd_MemFree(g_jmms_context->g_media_buffer_p);
        g_jmms_context->g_media_buffer_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_video_idle_preview_in_composer
 * DESCRIPTION
 *  Function to show the composer screen
 * PARAMETERS
 *  filename_p          [IN]        
 *  x_frame             [IN]        
 *  y_frame             [IN]        
 *  width_frame         [IN]        
 *  height_frame        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_jmms_video_idle_preview_in_composer(
                S8 *filename_p,
                S32 x_frame,
                S32 y_frame,
                S32 width_frame,
                S32 height_frame)
{
#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT mdi_ret;
    mdi_video_info_struct video_clip;
#endif /* __MMI_VIDEO_PLAYER__ */ 
    gdi_handle cache_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_media_buffer_p == NULL)
    {
        g_jmms_context->g_media_buffer_p = (U8*) jdd_MemAlloc(SMIL_EDITOR_IMAGE_CACHE_BUF_SIZE, sizeof(U8));
        gdi_layer_create_using_outside_memory(
            x_frame,
            y_frame,
            width_frame,
            height_frame,
            &cache_layer,
            (U8*) g_jmms_context->g_media_buffer_p,
            SMIL_EDITOR_IMAGE_CACHE_BUF_SIZE);
    #ifdef __MMI_VIDEO_PLAYER__
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_media_drm_permitted((JC_CHAR*) filename_p, DRM_PERMISSION_PLAY))
        {
            mdi_ret = mdi_video_ply_open_clip_file(filename_p, &video_clip);
            if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
            {
                /* draw the first frame of the video */
                mdi_video_ply_seek_and_get_frame((U64) 0, cache_layer);
                mdi_video_ply_close_clip_file();
            }
        }
        else
        {
            gdi_layer_push_and_set_active(cache_layer);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_set_clip(0, 0, width_frame - 1, height_frame - 1);
            gdi_layer_set_position(x_frame, y_frame);
            gdi_draw_solid_rect(0, 0, width_frame - 1, height_frame - 1, GDI_COLOR_WHITE);
            gdi_image_draw_resized(0, 0, width_frame, height_frame, (PU8) GetImage(IMG_ID_JATAAYU_JDD_ALT_DRM_VIDEO));
            gdi_layer_pop_and_restore_active();
        }
    #else /* __DRM_SUPPORT__ */ 
        mdi_ret = mdi_video_ply_open_clip_file(filename_p, &video_clip);
        if (mdi_ret == MDI_RES_VDOPLY_SUCCEED)
        {
            /* draw the first frame of the video */
            mdi_video_ply_seek_and_get_frame((U64) 0, cache_layer);
            mdi_video_ply_close_clip_file();
        }
    #endif /* __DRM_SUPPORT__ */ 
    #endif /* __MMI_VIDEO_PLAYER__ */ /* #ifdef __MMI_VIDEO_PLAYER__ */
        gdi_layer_free(cache_layer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_image_idle_preview_in_composer
 * DESCRIPTION
 *  Function to show the image in composer screen
 * PARAMETERS
 *  filename_p      [IN]        
 *  img_x           [IN]        
 *  img_y           [IN]        
 *  img_width       [IN]        
 *  img_height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_jmms_image_idle_preview_in_composer(
                S8 *filename_p,
                S32 img_x,
                S32 img_y,
                S32 img_width,
                S32 img_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle cache_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context->g_media_buffer_p == NULL)
    {
        g_jmms_context->g_media_buffer_p = (U8*) jdd_MemAlloc(SMIL_EDITOR_IMAGE_CACHE_BUF_SIZE, sizeof(U8));

        if (img_width * img_height * (GDI_MAINLCD_BIT_PER_PIXEL >> 3) > SMIL_EDITOR_IMAGE_CACHE_BUF_SIZE)
        {
            ASSERT(0);
        }

        if (gdi_layer_create_using_outside_memory
            (0, 0, img_width, img_height, &cache_layer, (U8*) g_jmms_context->g_media_buffer_p,
             SMIL_EDITOR_IMAGE_CACHE_BUF_SIZE) != GDI_LAYER_SUCCEED)
        {
            ASSERT(0);
        }

        gdi_layer_push_and_set_active(cache_layer);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_set_clip(0, 0, img_width - 1, img_height - 1);
        gdi_layer_set_position(img_x, img_y);
        gdi_draw_solid_rect(0, 0, img_width - 1, img_height - 1, GDI_COLOR_WHITE);
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_media_drm_permitted((JC_CHAR*) filename_p, DRM_PERMISSION_DISPLAY))
        {
            gdi_image_draw_resized_file(0, 0, img_width, img_height, (S8*) filename_p);
        }
        else
        {
            gdi_image_draw_resized(0, 0, img_width, img_height, (PU8) GetImage(IMG_ID_JATAAYU_JDD_ALT_DRM_IMAGE));
        }
    #else /* __DRM_SUPPORT__ */ 
        gdi_image_draw_resized_file(0, 0, img_width, img_height, (S8*) filename_p);
    #endif /* __DRM_SUPPORT__ */ 
        gdi_layer_pop_and_restore_active();
        gdi_layer_free(cache_layer);

    }
}

/* PMT VIKAS END 20060502 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_show_image_from_cached_buffer
 * DESCRIPTION
 *  show image in cat 275
 * PARAMETERS
 *  x_offset            [IN]        
 *  y_offset            [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  buffer_ptr_p        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_show_image_from_cached_buffer(S32 x_offset, S32 y_offset, S32 width, S32 height, const U8 *buffer_ptr_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    S32 x, y, y_multiple;
    U16 *buf_p = (U16*) buffer_ptr_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    if ((clip_x2 < x_offset) || (clip_x1 > x_offset + width - 1) || (clip_y2 < y_offset) ||
        (clip_y1 > y_offset + height - 1))
    {
        return;
    }

    if (clip_x1 < x_offset)
    {
        clip_x1 = x_offset;
    }

    if (clip_y1 < y_offset)
    {
        clip_y1 = y_offset;
    }

    if (clip_x2 > x_offset + width - 1)
    {
        clip_x2 = x_offset + width - 1;
    }

    if (clip_y2 > y_offset + height - 1)
    {
        clip_y2 = y_offset + height - 1;
    }

    clip_x1 -= x_offset;
    clip_y1 -= y_offset;
    clip_x2 -= x_offset;
    clip_y2 -= y_offset;

    for (y = clip_y1; y <= clip_y2; y++)
    {
        y_multiple = y * width;
        for (x = clip_x1; x <= clip_x2; x++)
        {
            GDI_SET_BUFFER_PIXEL(x + x_offset, y + y_offset, buf_p[y_multiple + x]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_smil_editor_show_video_from_file
 * DESCRIPTION
 *  Show image from file
 * PARAMETERS
 *  y_offset        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_smil_editor_show_video_from_file(S32 y_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_file_name_p = g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p;

    S32 x, y, zoom_width, zoom_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = g_jmms_context->compose_context->curr_slide_info.img_info.img_x;
    y = g_jmms_context->compose_context->curr_slide_info.img_info.img_y;
    zoom_width = g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_width;
    zoom_height = g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_height;

    if (g_jmms_context->g_media_buffer_p == NULL)
    {
        mmi_jmms_video_idle_preview_in_composer((S8*) temp_file_name_p, x, y_offset + y, zoom_width, zoom_height);
    }
    mmi_jmms_show_image_from_cached_buffer(x, y_offset + y, zoom_width, zoom_height, g_jmms_context->g_media_buffer_p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_smil_editor_show_image_from_file
 * DESCRIPTION
 *  Show image from file
 * PARAMETERS
 *  y_offset        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_smil_editor_show_image_from_file(S32 y_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_file_name_p = g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p;

    S32 x, y, zoom_width, zoom_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = g_jmms_context->compose_context->curr_slide_info.img_info.img_x;
    y = g_jmms_context->compose_context->curr_slide_info.img_info.img_y;
    zoom_width = g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_width;
    zoom_height = g_jmms_context->compose_context->curr_slide_info.img_info.zoom_in_height;

    if (g_jmms_context->g_media_buffer_p == NULL)
    {
        mmi_jmms_image_idle_preview_in_composer((S8*) temp_file_name_p, x, y_offset + y, zoom_width, zoom_height);
    }

    mmi_jmms_show_image_from_cached_buffer(x, y_offset + y, zoom_width, zoom_height, g_jmms_context->g_media_buffer_p);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_go_back_history_ip_method
 * DESCRIPTION
 *  callback fn to go in history from input method screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_go_back_history_ip_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    GoBackHistory();
}

/* Insert image */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_filemgr_insert_image
 * DESCRIPTION
 *  entry fn for filemgr from insert image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_filemgr_insert_image(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_image(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_image_restricted(&filter);
	}

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_select_image);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_select_image
 * DESCRIPTION
 *  callback fn for filemgr when user select a image.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_select_image(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT image_result;
    S32 img_widthv = 0, img_heightv = 0;

    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    JC_CHAR *dest_fname = NULL;
    U32 resize_result = 0;
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */
    U32 media_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_DISPLAY, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 

    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif 
        {
            image_result = gdi_image_get_dimension_file((S8*) path_p, &img_widthv, &img_heightv);
            if (image_result != GDI_SUCCEED || (img_widthv * img_heightv) == 0)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                return;
            }
        }
        if (mmi_jmms_selected_media_valid_size_check_for_mms(path_p, is_short, &media_size, E_TRUE) != E_TRUE)
        {
            return;
        }

        /* Himanshu Fix PMTSW00006527 START */
        if (mmi_jmms_check_for_image_size_and_resolution(path_p, img_widthv, img_heightv, media_size) != E_TRUE)
        {
            return;
        }
        /* Himanshu Fix PMTSW00006527 END */

        /* HIMANSHU 05122006 START */
    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    #ifdef __DRM_SUPPORT__
        if (is_drm_content == E_FALSE)
    #endif 
        {
            /* Check if image resizing needs to be done. */
            resize_result = check_for_image_resize(path_p, &dest_fname);

            if (resize_result == JMMS_IMAGE_RESIZE_SUCCEED)
            {
                path_p = dest_fname;
            }
            else if (resize_result == JMMS_IMAGE_RESIZE_UNCHANGED)
            {
                /* Do nothing as same file source is to be used. */
            }
            else
            {
                goto error;
            }
        }
    #endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
        /* HIMANSHU 05122006 END */

        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            /* return; */
            goto error;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_add_image);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_add_image();
        }

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT_INSERT);
    }

  error:

    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    if (dest_fname != NULL)
    {
        jdd_MemFree(dest_fname);
        dest_fname = NULL;
    }

    DeleteScreenIfPresent(SCR_ID_JMMS_IMAGE_RESIZE_TRANSITION);
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_add_image
 * DESCRIPTION
 *  fn for filemgr when user select a image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_add_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_media(
                g_jmms_context->compose_context->media_path_p,
                E_MEDIA_IMAGE,
                0,
                g_jmms_context->compose_context->curr_page_index);
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_FMGR_EXPLORER); /* sanjeev added */
    }
    else if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].img_dur_max_set = 1;

        if (mmi_ucs2strlen((S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) == 0)
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 1;
        }
        else
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        }

        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);

    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].img_dur_max_set = 1;

        if (mmi_ucs2strlen((S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) == 0)
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 1;
        }
        else
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        }

        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }

    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}

/* Insert audio */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_filemgr_insert_audio
 * DESCRIPTION
 *  entry fn for filemgr from insert audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_filemgr_insert_audio(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_audio(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_audio_restricted(&filter);
	}

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_select_audio);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_select_audio
 * DESCRIPTION
 *  callback fn for filemgr when user select an audio.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_select_audio(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result audio_result = 0;
    U32 audio_du;
    U32 media_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_PLAY, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif 
        {
            audio_result = mdi_audio_get_duration((S8*) g_jmms_context->compose_context->media_path_p, &audio_du);
            if (audio_result != GDI_SUCCEED)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                if (g_jmms_context->compose_context->media_path_p != NULL)
                {
                    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
                    g_jmms_context->compose_context->media_path_p = NULL;
                }
                return;
            }
        }
        if (mmi_jmms_selected_media_valid_size_check_for_mms(path_p, is_short, &media_size, E_FALSE) != E_TRUE)
        {
            if (g_jmms_context->compose_context->media_path_p != NULL)
            {
                jdd_MemFree(g_jmms_context->compose_context->media_path_p);
                g_jmms_context->compose_context->media_path_p = NULL;
            }
            return;
        }
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_add_audio);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_add_audio();
        }

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT_INSERT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_add_audio
 * DESCRIPTION
 *  fn for filemgr when user select an audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_add_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_media(
                g_jmms_context->compose_context->media_path_p,
                E_MEDIA_AUDIO,
                0,
                g_jmms_context->compose_context->curr_page_index);

    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_FMGR_EXPLORER); /* sanjeev added */
    }
    else if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].audio_dur_max_set = 1;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].audio_dur_max_set = 1;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }

    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}

/* Insert video */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_filemgr_insert_video
 * DESCRIPTION
 *  entry fn for filemgr from insert video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_filemgr_insert_video(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_video(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_video_restricted(&filter);
	}

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_select_video);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_select_video
 * DESCRIPTION
 *  callback fn for filemgr when user select a video.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_select_video(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__
    MDI_RESULT result_video = 0;
    U32 img_widthv = 0, img_heightv = 0;
#endif /* __MMI_VIDEO_PLAYER__ */ /* compiler warning removal */
    U32 media_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_PLAY, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);
    #ifdef __MMI_VIDEO_PLAYER__
    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif 
        {
            result_video = mmi_jdd_videoapp_get_video_file_size_info(
                            (S8*) g_jmms_context->compose_context->media_path_p,
                            &img_widthv,
                            &img_heightv);
            if (result_video == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                if (g_jmms_context->compose_context->media_path_p != NULL)
                {
                    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
                    g_jmms_context->compose_context->media_path_p = NULL;
                }
                return;
            }
        }
    #endif /* __MMI_VIDEO_PLAYER__ */ 
        if (mmi_jmms_selected_media_valid_size_check_for_mms(path_p, is_short, &media_size, E_FALSE) != E_TRUE)
        {
            if (g_jmms_context->compose_context->media_path_p != NULL)
            {
                jdd_MemFree(g_jmms_context->compose_context->media_path_p);
                g_jmms_context->compose_context->media_path_p = NULL;
            }
            return;
        }
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_add_video);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_add_video();
        }

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT_INSERT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_add_video
 * DESCRIPTION
 *  fn for filemgr when user select a video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_add_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_media(
                g_jmms_context->compose_context->media_path_p,
                E_MEDIA_VIDEO,
                0,
                g_jmms_context->compose_context->curr_page_index);

    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_FMGR_EXPLORER); /* sanjeev added */
    }
    else if (err_code == JMMS_COMP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        /* sandeep end Nov 21 for bug number PMT005940 */

        if (mmi_ucs2strlen((S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) == 0)
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 1;
        }
        else
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        }
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].video_dur_max_set = 1;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        /* sandeep end Nov 21 for bug number PMT005940 */

        if (mmi_ucs2strlen((S8*) g_jmms_context->compose_context->curr_slide_info.edit_content_buffer) == 0)
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 1;
        }
        else
        {
            g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        }
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].video_dur_max_set = 1;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }

    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}

/* Insert vcard */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_filemgr_insert_vcard
 * DESCRIPTION
 *  entry fn for filemgr from insert vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_filemgr_insert_vcard(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_VCF);
#ifdef __DRM_ODF_SUPPORT__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_select_vcard);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_select_vcard
 * DESCRIPTION
 *  callback fn for filemgr when user select a vcard.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_select_vcard(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_NONE, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_add_vcard);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_add_vcard();
        }

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_VCARD);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_add_vcard
 * DESCRIPTION
 *  fn for filemgr when user select an vcard.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_add_vcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_media(g_jmms_context->compose_context->media_path_p, E_MEDIA_OTHERS, E_TRUE, 0);

    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_VCARD);
    }
    else if (err_code == JMMS_COMP_OK)
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }

    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}

/* Insert vcalendar */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_filemgr_insert_vcalander
 * DESCRIPTION
 *  entry fn for filemgr from insert vcalander.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_filemgr_insert_vcalander(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_VCS);
#ifdef __DRM_ODF_SUPPORT__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_select_vcalander);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_select_vcalander
 * DESCRIPTION
 *  callback fn for filemgr when user select a vcalander.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_select_vcalander(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_NONE, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_add_vcalander);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_add_vcalander();
        }

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_VCALENDAR);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_add_vcalander
 * DESCRIPTION
 *  fn for filemgr when user select an vcalander.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_add_vcalander(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_media(g_jmms_context->compose_context->media_path_p, E_MEDIA_OTHERS, E_TRUE, 0);

    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_VCALENDAR);
    }
    else if (err_code == JMMS_COMP_OK)
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }

    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}

/* Insert attachment */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_filemgr_insert_attachment
 * DESCRIPTION
 *  entry fn for filemgr from insert atachment.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_filemgr_insert_attachment(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_attachment(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_attachment_restricted(&filter);
	}	

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_select_attachment);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_select_attachment
 * DESCRIPTION
 *  callback fn for filemgr when user select an attachemnt.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_select_attachment(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_NONE, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_add_attachment);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_add_attachment();
        }

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_INSERT);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_add_attachment
 * DESCRIPTION
 *  fn for filemgr when user select an attachment.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_add_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_add_media(g_jmms_context->compose_context->media_path_p, E_MEDIA_OTHERS, E_TRUE, 0);

    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_FMGR_EXPLORER);
    }
    else if (err_code == JMMS_COMP_OK)
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }

    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}

/* insert Slide */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_insert_slide
 * DESCRIPTION
 *  This fn inserts a slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_insert_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_insert_slide();

    if (err_code == JMMS_COMP_OK)
    {
        HistoryReplace(SCR_ID_JMMS_EDIT_CONTENT, SCR_ID_JMMS_EDIT_CONTENT, mmi_jmms_entry_edit_content_screen); /* to delete guibuffer details as entering new slide. */
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_next_slide
 * DESCRIPTION
 *  This fn go to next slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_next_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE ret_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ;

    ret_code = mmi_jmms_extract_slide_media_info((U8) (g_jmms_context->compose_context->curr_page_index + 1));

    if (ret_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_page_index++;
        HistoryReplace(SCR_ID_JMMS_EDIT_CONTENT, SCR_ID_JMMS_EDIT_CONTENT, mmi_jmms_entry_edit_content_screen); /* to delete guibuffer details as entering new slide. */
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (ret_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_GOTO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_prev_slide
 * DESCRIPTION
 *  This fn go to previous slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_prev_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE ret_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_extract_slide_media_info((U8) (g_jmms_context->compose_context->curr_page_index - 1));

    if (ret_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_page_index--;
        HistoryReplace(SCR_ID_JMMS_EDIT_CONTENT, SCR_ID_JMMS_EDIT_CONTENT, mmi_jmms_entry_edit_content_screen); /* to delete guibuffer details as entering new slide. */
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (ret_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_GOTO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_goto_slide
 * DESCRIPTION
 *  This fn go to previous slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_goto_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE ret_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_extract_slide_media_info((U8) (g_jmms_context->curr_scr_hilite_index + 1));

    if (ret_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_page_index = g_jmms_context->curr_scr_hilite_index + 1;
        HistoryReplace(SCR_ID_JMMS_EDIT_CONTENT, SCR_ID_JMMS_EDIT_CONTENT, mmi_jmms_entry_edit_content_screen); /* to delete guibuffer details as entering new slide. */
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (ret_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_GOTO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_delete_image
 * DESCRIPTION
 *  This fn deletes image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_delete_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    S8 *resized_file_name = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    resized_file_name =
        (S8*)
        jdd_MemAlloc(
            (mmi_ucs2strlen((PS8) g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p) + 1) * ENCODING_LENGTH,
            1);
    if (resized_file_name != NULL)
    {
        mmi_ucs2cpy(
            (PS8) resized_file_name,
            (PS8) g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p);
    }
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    err_code = mmi_jmms_compose_delete_media(
                g_jmms_context->compose_context->curr_slide_info.image_id,
                g_jmms_context->compose_context->curr_page_index,
                E_FALSE);
    if (err_code == JMMS_COMP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        if (g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] == 0)
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1 + (1 << 1);
        }
        else
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1;
        }
        /* sandeep end Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.image_id = 0;
        g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        mmi_jmms_set_region_list();
    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
        mmi_jmms_delete_resized_temp_file(resized_file_name);
    #endif 
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        if (g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] == 0)
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1 + (1 << 1);
        }
        else
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1;
        }
        /* sandeep end Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.image_id = 0;
        g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        mmi_jmms_set_region_list();
    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
        mmi_jmms_delete_resized_temp_file(resized_file_name);
    #endif 
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_DELETE);
    }

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    if (resized_file_name != NULL)
    {
        jdd_MemFree(resized_file_name);
        resized_file_name = NULL;
    }
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_delete_audio
 * DESCRIPTION
 *  This fn deletes audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_delete_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_delete_media(
                g_jmms_context->compose_context->curr_slide_info.audio_id,
                g_jmms_context->compose_context->curr_page_index,
                E_FALSE);

    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.audio_id = 0;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.audio_id = 0;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_DELETE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_delete_video
 * DESCRIPTION
 *  This fn deletes video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_delete_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_delete_media(
                g_jmms_context->compose_context->curr_slide_info.video_id,
                g_jmms_context->compose_context->curr_page_index,
                E_FALSE);

    if (err_code == JMMS_COMP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        if (g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] == 0)
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1 + (1 << 1);
        }
        else
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1;
        }
        /* sandeep end Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.video_id = 0;
        g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        if (g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] == 0)
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1 + (1 << 1);
        }
        else
        {
            g_jmms_context->compose_context->curr_slide_info.img_info.img_delete = 1;
        }
        /* sandeep end Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.video_id = 0;
        g_jmms_context->compose_context->is_image_first[g_jmms_context->compose_context->curr_page_index - 1] = 0;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_DELETE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_edit_content_delete_attachment
 * DESCRIPTION
 *  entry fn for delete attachment.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_edit_content_delete_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE ret_code = JMMS_COMP_OK;
    MEDIA_INFO *media_info_p;
    U8 media_count;
    U8 *gui_buffer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_DELETE_ATTACHMENT, NULL, mmi_jmms_entry_edit_content_delete_attachment, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_JMMS_DELETE_ATTACHMENT);

    RegisterHighlightHandler(mmi_jmms_delete_attachment_highlight_hdlr);

    ret_code = mmi_jmms_compose_get_media_list(0, &media_info_p, &media_count, E_TRUE);

    if (ret_code == JMMS_COMP_OK)
    {

        ShowCategory184Screen(
            STR_ID_JMMS_ATTACHMENT,
            GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (S32) media_count,
            mmi_jmms_get_attachment_data,
            0,
            0,
            gui_buffer_p);

        SetLeftSoftkeyFunction(mmi_jmms_edit_content_delete_attachment, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_attachment_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for slide list screen
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_attachment_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->curr_scr_hilite_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_delete_attachment
 * DESCRIPTION
 *  This fn deletes attachment.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_delete_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE ret_code = JMMS_COMP_OK;
    JMMS_COMP_ERRCODE err_code;
    MEDIA_INFO *media_info_p;
    U8 media_count;
    U8 count = 0;
    U32 iIndex = 0;
    JC_CHAR *tmpfile_ext_p = NULL;  /* extension of the attachment file to be deleted */
    JC_CHAR *tmp_url_p = NULL;      /* path_p of the temp file to be deleted */
    JC_CHAR *filename_p = NULL;     /* filename of the file to be deleted */
    JC_CHAR ext_to_del_p[2][8];
    U16 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_compose_get_media_list(0, &media_info_p, &media_count, E_TRUE);
    if (ret_code == JMMS_COMP_OK)
    {
        for (count = 0; count < media_count; count++)
        {
            if (count == g_jmms_context->curr_scr_hilite_index)
            {

                err_code = mmi_jmms_compose_delete_media(media_info_p->uiMediaID, 0, E_TRUE);

                filename_p = media_info_p->pMimeInfo->MimeHeaders.pObjectName;
                iIndex = jdi_UtilsLastIndexOfTchar(
                            '.',
                            (JC_CHAR*) filename_p,
                            jc_tcslen(media_info_p->pMimeInfo->MimeHeaders.pObjectName) - 1);
                tmpfile_ext_p = &filename_p[iIndex + 1];
                mmi_asc_to_ucs2((PS8) ext_to_del_p[0], (PS8) "vcf");       /* extension for vcard */
                mmi_asc_to_ucs2((PS8) ext_to_del_p[1], (PS8) "vcs");       /* extension for vcalender */

                /* if the file is vCard or vCalender delete the physical file */
                if (mmi_ucs2cmp((S8*) tmpfile_ext_p, (S8*) ext_to_del_p[0]) == 0 ||
                    mmi_ucs2cmp((S8*) tmpfile_ext_p, (S8*) ext_to_del_p[1]) == 0)
                {
                    size =
                        (strlen(TEMP_FOLDER_PATH_VOBJ) * ENCODING_LENGTH) + mmi_ucs2strlen((S8*) filename_p) +
                        (ENCODING_LENGTH * 1);
                    tmp_url_p = (JC_CHAR*) jdd_MemAlloc(size, sizeof(JC_CHAR));
                    if (NULL == tmp_url_p)
                    {
                        goto end;
                    }
                    else
                    {

                        mmi_asc_to_ucs2((S8*) tmp_url_p, (S8*) TEMP_FOLDER_PATH_VOBJ);

                        mmi_ucs2cat((S8*) tmp_url_p, (S8*) filename_p);

                        if (g_jmms_context->jmms_fs_handle == NULL)
                        {
                            jdd_FSInitialize(&g_jmms_context->jmms_fs_handle);
                        }
                        jdd_FSDelete(g_jmms_context->jmms_fs_handle, (JC_CHAR*) tmp_url_p);
                        jdd_MemFree(tmp_url_p);
                    }
                }

              end:
                if ((err_code == JMMS_COMP_OK) || (err_code == JMMS_COMP_POPUP_OK))
                {
                    DisplayPopup(
                        (PU8) GetString(STR_GLOBAL_DONE),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        JMMS_POPUP_TIME,
                        SUCCESS_TONE);
                    g_jmms_context->num_attachments--;
                    if (g_jmms_context->num_attachments == 0)
                    {
                        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
                    }
                    else
                    {
                        DeleteUptoScrID(SCR_ID_JMMS_DELETE_ATTACHMENT);
                    }
                }
                break;
            }
            media_info_p = media_info_p->pNext;

        };
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_edit_content_delete_slide
 * DESCRIPTION
 *  This fn deletes slide.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_edit_content_delete_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_delete_page(g_jmms_context->compose_context->curr_page_index);
    if (err_code == JMMS_COMP_OK)
    {
        U8 page_index;

        if (g_jmms_context->compose_context->curr_page_index > 1)
        {
            page_index = g_jmms_context->compose_context->curr_page_index - 1;
        }
        else
        {
            page_index = g_jmms_context->compose_context->curr_page_index;
        }

        err_code = mmi_jmms_extract_slide_media_info((U8) (page_index));
        if (err_code == JMMS_COMP_OK)
        {
            g_jmms_context->compose_context->curr_page_index = page_index;
            HistoryReplace(SCR_ID_JMMS_EDIT_CONTENT, SCR_ID_JMMS_EDIT_CONTENT, mmi_jmms_entry_edit_content_screen);     /* to delete guibuffer details as entering new slide. */
            GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
        }
        else if (err_code == JMMS_COMP_FAIL)
        {
            DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_DELETE);
        }
        /* shuffling of is_image_first handling array  */
        for (count = g_jmms_context->compose_context->curr_page_index; count < MAX_POSSIBLE_SLIDES - 1; count++)
        {
            g_jmms_context->compose_context->is_image_first[count] =
                g_jmms_context->compose_context->is_image_first[count + 1];
            g_jmms_context->compose_context->duration[count].txt_dur_max_set =
                g_jmms_context->compose_context->duration[count + 1].txt_dur_max_set;
            g_jmms_context->compose_context->duration[count].img_dur_max_set =
                g_jmms_context->compose_context->duration[count + 1].img_dur_max_set;
            g_jmms_context->compose_context->duration[count].audio_dur_max_set =
                g_jmms_context->compose_context->duration[count + 1].audio_dur_max_set;
            g_jmms_context->compose_context->duration[count].video_dur_max_set =
                g_jmms_context->compose_context->duration[count + 1].video_dur_max_set;
        }
        mmi_jmms_set_region_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_replace_image
 * DESCRIPTION
 *  entry fn in file mgr to replace image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_replace_image(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_image(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_image_restricted(&filter);
	}

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_replace_image);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_replace_image
 * DESCRIPTION
 *  This fn replace image.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_replace_image(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    GDI_RESULT image_result;
    S32 img_widthv = 0, img_heightv = 0;

    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    JC_CHAR *dest_fname = NULL;
    U32 resize_result = 0;
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */
    U32 media_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_DISPLAY, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif 
        {
            image_result = gdi_image_get_dimension_file((S8*) path_p, &img_widthv, &img_heightv);
            if (image_result != GDI_SUCCEED || (img_widthv * img_heightv) == 0)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                return;
            }
        }
        if (mmi_jmms_selected_media_valid_size_check_for_mms(path_p, is_short, &media_size, E_TRUE) != E_TRUE)
        {
            return;
        }
        /* Himanshu Fix PMTSW00006527 START */
        if (mmi_jmms_check_for_image_size_and_resolution(path_p, img_widthv, img_heightv, media_size) != E_TRUE)
        {
            return;
        }
        /* Himanshu Fix PMTSW00006527 END */
        /* HIMANSHU 05122006 START */
    #ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    #ifdef __DRM_SUPPORT__
        if (is_drm_content == E_FALSE)
    #endif 
        {
            /* Check if image resizing needs to be done. */
            resize_result = check_for_image_resize(path_p, &dest_fname);

            if (resize_result == JMMS_IMAGE_RESIZE_SUCCEED)
            {
                path_p = dest_fname;
            }
            else if (resize_result == JMMS_IMAGE_RESIZE_UNCHANGED)
            {
                /* Do nothing as same file source is to be used. */
            }
            else
            {
                goto ERROR_HANDLE;
            }
        }
    #endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
        /* HIMANSHU 05122006 END */

        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            /* return; */
            goto ERROR_HANDLE;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_replace_image);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_replace_image();
        }
    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }

  ERROR_HANDLE:
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
    /* HIMANSHU 05122006 START */
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    if (dest_fname != NULL)
    {
        jdd_MemFree(dest_fname);
        dest_fname = NULL;
    }

    DeleteScreenIfPresent(SCR_ID_JMMS_IMAGE_RESIZE_TRANSITION);
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    /* HIMANSHU 05122006 END */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_replace_image
 * DESCRIPTION
 *  fn for filemgr when user select a image.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_replace_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    S8 *resized_file_name = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    resized_file_name =
        (S8*)
        jdd_MemAlloc(
            (mmi_ucs2strlen((PS8) g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p) + 1) * ENCODING_LENGTH,
            1);
    if (resized_file_name != NULL)
    {
        mmi_ucs2cpy(
            (PS8) resized_file_name,
            (PS8) g_jmms_context->compose_context->curr_slide_info.img_info.file_name_p);
    }
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    err_code = mmi_jmms_compose_replace_media(
                g_jmms_context->compose_context->media_path_p,
                E_MEDIA_IMAGE,
                0,
                g_jmms_context->compose_context->curr_page_index,
                g_jmms_context->compose_context->curr_slide_info.image_id);
    if (err_code == JMMS_COMP_FAIL)
    {
        goto ERROR_HANDLE;
    }
    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].img_dur_max_set = 1;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].img_dur_max_set = 1;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    if ((err_code == JMMS_COMP_OK) || (err_code == JMMS_COMP_POPUP_OK))
    {
        mmi_jmms_delete_resized_temp_file(resized_file_name);
    }
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 

  ERROR_HANDLE:
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }
    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    if (resized_file_name != NULL)
    {
        jdd_MemFree(resized_file_name);
        resized_file_name = NULL;
    }
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_replace_audio
 * DESCRIPTION
 *  This fn replace audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_replace_audio(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_audio(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_audio_restricted(&filter);
	}

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_replace_audio);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_replace_audio
 * DESCRIPTION
 *  This fn replace audio.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_replace_audio(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //   U32 file_size = 0;
    //  JDD_FILE file_handle;
    //U32 msg_max_size;
    //  U32 media_size;
    //  MEDIA_MIME_INFO media_mime_info;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /* JC_RETCODE ret_code = JC_OK; */
    mdi_result audio_result = 0;
    U32 audio_du;
    U32 media_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_PLAY, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 

    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif 
        {
            audio_result = mdi_audio_get_duration((S8*) path_p, &audio_du);
            if (audio_result != GDI_SUCCEED)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                return;
            }
        }
        if (mmi_jmms_selected_media_valid_size_check_for_mms(path_p, is_short, &media_size, E_FALSE) != E_TRUE)
        {
            return;
        }
        /*        if (g_jmms_context->jmms_fs_handle == NULL)
           {
           if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
           {
           ret_code = JC_ERR_FILE_SYS_INIT;
           goto ERROR_HANDLE;
           }
           }
           
           file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) path_p, E_OPEN_READ_MODE);
           if (file_handle == NULL)
           {
           ret_code = JC_ERR_FILE_OPEN;
           goto ERROR_HANDLE;
           }
           
           jdd_FSGetSize(file_handle, &file_size);
           jdd_FSClose(file_handle);
           
           ret_code = mmi_jmms_jdi_get_max_size(g_jmms_context->msg_handle, &msg_max_size);
           if (ret_code != JC_OK)
           {
           goto ERROR_HANDLE;
           }
           
           ret_code = mmi_jmms_jdi_get_media_mime_info(
           g_jmms_context->msg_handle,
           g_jmms_context->compose_context->curr_page_index,
           g_jmms_context->compose_context->curr_slide_info.audio_id,
           &media_mime_info,
           E_FALSE);
           if (ret_code != JC_OK)
           {
           goto ERROR_HANDLE;
           }
           
           media_size = media_mime_info.ContentData.uiTotalSize;
           
           if (msg_max_size - media_size >= file_size)
           { */
        /* err_code = mmi_jmms_compose_delete_media(
           g_jmms_context->compose_context->curr_slide_info.audio_id,
           g_jmms_context->compose_context->curr_page_index,
           E_FALSE);
           if (err_code == JMMS_COMP_FAIL)
           {
           goto ERROR_HANDLE;
           } */
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_replace_audio);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_replace_audio();
        }

        /* }
           else
           {
           DisplayPopup(
           (PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY),
           STR_GLOBAL_ERROR,
           1,
           JMMS_POPUP_TIME,
           SUCCESS_TONE);
           DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
           } */

    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }

    /* ERROR_HANDLE: */
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }
    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_replace_audio
 * DESCRIPTION
 *  fn for filemgr when user select an audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_replace_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_replace_media(
                g_jmms_context->compose_context->media_path_p,
                E_MEDIA_AUDIO,
                0,
                g_jmms_context->compose_context->curr_page_index,
                g_jmms_context->compose_context->curr_slide_info.audio_id);

    if (err_code == JMMS_COMP_FAIL)
    {
        goto ERROR_HANDLE;
    }
    if (err_code == JMMS_COMP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].audio_dur_max_set = 1;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].audio_dur_max_set = 1;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }

  ERROR_HANDLE:
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }
    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_replace_video
 * DESCRIPTION
 *  This fn replace video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_replace_video(void)
{
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
	{
		mmi_jmms_set_file_mgr_filter_for_video(&filter);
	}
	else
	{
		mmi_jmms_set_file_mgr_filter_for_video_restricted(&filter);
	}

    mmi_fmgr_select_path_and_enter(APP_JATAAYU_MMS,
#ifdef __DRM_ODF_SUPPORT__
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
#else 
                                   FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif 
                                   filter, (S8*) L"root", mmi_jmms_callback_filemgr_replace_video);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_callback_filemgr_replace_video
 * DESCRIPTION
 *  This fn replace video.
 * PARAMETERS
 *  path_p          [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_callback_filemgr_replace_video(void *path_p, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
#ifdef __MMI_VIDEO_PLAYER__
    MDI_RESULT result_video = 0;
    U32 img_widthv = 0, img_heightv = 0;
#endif /* __MMI_VIDEO_PLAYER__ */ /* compiler warning removal */
    U32 media_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path_p)
    {
    #ifdef __DRM_SUPPORT__
        JC_BOOLEAN is_drm_content = E_FALSE;
        JC_BOOLEAN is_forwardable = E_TRUE;
        JC_BOOLEAN permission = E_FALSE;

        is_drm_content = mmi_jmms_process_drm_object(path_p, DRM_PERMISSION_PLAY, &is_forwardable, &permission);
        if (is_forwardable == E_FALSE)
        {
            mmi_jmms_compose_show_error_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 

    #ifdef __MMI_VIDEO_PLAYER__
    #ifdef __DRM_SUPPORT__
        if ((is_drm_content == E_FALSE) || ((is_drm_content == E_TRUE) && (permission == E_TRUE)))
    #endif 
        {
            result_video = mmi_jdd_videoapp_get_video_file_size_info((S8*) path_p, &img_widthv, &img_heightv);
            if (result_video == MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_JMMS_CORRUPTED_MEDIA_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    JMMS_POPUP_TIME,
                    ERROR_TONE);
                return;
            }
        }
    #endif /* __MMI_VIDEO_PLAYER__ */ 
        if (mmi_jmms_selected_media_valid_size_check_for_mms(path_p, is_short, &media_size, E_FALSE) != E_TRUE)
        {
            return;
        }
        if (g_jmms_context->compose_context->media_path_p != NULL)
        {
            jdd_MemFree(g_jmms_context->compose_context->media_path_p);
            g_jmms_context->compose_context->media_path_p = NULL;
        }
        g_jmms_context->compose_context->media_path_p = (S8*) jdd_MemAlloc((mmi_ucs2strlen(path_p) + 1), sizeof(JC_CHAR));
        if (g_jmms_context->compose_context->media_path_p == NULL)
        {
            DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            return;
        }
        mmi_ucs2cpy((S8*) g_jmms_context->compose_context->media_path_p, (S8*) path_p);

    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_compose_add_as_drm(path_p) && (is_drm_content == E_FALSE))
        {
            mmi_jmms_confirm_add_drm_media(mmi_jmms_fm_replace_video);
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            mmi_jmms_fm_replace_video();
        }
    }
    else
    {
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }

    /* ERROR_HANDLE: */
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_fm_replace_video
 * DESCRIPTION
 *  fn for filemgr when user select a video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_fm_replace_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_code = mmi_jmms_compose_replace_media(
                g_jmms_context->compose_context->media_path_p,
                E_MEDIA_VIDEO,
                0,
                g_jmms_context->compose_context->curr_page_index,
                g_jmms_context->compose_context->curr_slide_info.video_id);

    if (err_code == JMMS_COMP_FAIL)
    {
        goto ERROR_HANDLE;
    }
    if (err_code == JMMS_COMP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        /* sandeep end Nov 21 for bug number PMT005940 */

        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].video_dur_max_set = 1;
        GoBackToHistory(SCR_ID_JMMS_EDIT_CONTENT);
    }
    else if (err_code == JMMS_COMP_POPUP_OK)
    {
        /* sandeep start Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->curr_slide_info.img_info.custom_img_display = 1;
        /* sandeep end Nov 21 for bug number PMT005940 */
        g_jmms_context->compose_context->duration[g_jmms_context->compose_context->curr_page_index -
                                                  1].video_dur_max_set = 1;
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
    }

  ERROR_HANDLE:
    if (err_code == JMMS_COMP_FAIL)
    {
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT_REPLACE);
    }
    jdd_MemFree(g_jmms_context->compose_context->media_path_p);
    g_jmms_context->compose_context->media_path_p = NULL;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_phb_contact
 * DESCRIPTION
 *  insert phb contact to mms
 * PARAMETERS
 *  resut_entry_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_insert_phb_contact(MMI_PHB_VCARD_STRUCT *resut_entry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S8 temp_str[(MAX_PB_NAME_LENGTH + MAX_PB_NUMBER_LENGTH + 3 + 1 + 1) * ENCODING_LENGTH]; */
    S8 temp_str[(MAX_PB_NAME_LENGTH + MAX_PB_NUMBER_LENGTH + 5 + 1 + 1) * ENCODING_LENGTH];
    S8 temp_num_str[(MAX_PB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];

    /* Deepali: contact format will be Deepali <123456789> so 3 is added for one space and angular brackets. 1 for + Sign and 1 for Null Termination. */
    /* Himanshu: contact format will be Himanshu < 123456789 > now. So 5 is added for " < " and " >". 1 for + Sign and 1 for Null Termination. */
    S8 ucs2_space_str[10];

    history *temphistory_p;
    historyNode *history_node_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temphistory_p = (history*) jdd_MemAlloc(sizeof(history), 1);
    if (temphistory_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        if (IsScreenPresent(SCR_PBOOK_LIST))
        {
            DeleteUptoScrID(SCR_PBOOK_LIST);
        }
    }
    else if (!mmi_ucs2strlen((S8*) resut_entry_p->number))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_EDIT_CONTENT_INSERT_PHB_INVALID_NUMBER),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        if (IsScreenPresent(SCR_PBOOK_LIST))
        {
            DeleteUptoScrID(SCR_PBOOK_LIST);
        }
    }
    else
    {
        mmi_ucs2cpy((S8*) temp_str, (S8*) resut_entry_p->name);
        /* mmi_asc_to_ucs2((S8*) ucs2_space_str, " <"); */
        mmi_asc_to_ucs2((S8*) ucs2_space_str, " < ");
        mmi_ucs2cat((S8*) temp_str, (S8*) ucs2_space_str);
        mmi_asc_to_ucs2((S8*) temp_num_str, (S8*) resut_entry_p->number);
        mmi_ucs2cat((S8*) temp_str, (S8*) temp_num_str);
        /* mmi_asc_to_ucs2((S8*) ucs2_space_str, ">"); */
        mmi_asc_to_ucs2((S8*) ucs2_space_str, " >");
        mmi_ucs2cat((S8*) temp_str, (S8*) ucs2_space_str);

        memset(temphistory_p, 0, sizeof(history));
        GetHistory(SCR_ID_JMMS_EDIT_CONTENT, temphistory_p);

        /* Replaced AppendCategory5String with new API AppendCategory275String */
        /* As we are using Category275 for compose MMS so AppenCategory5String */
        /* was sending wrong categoryID which is needed for getting data from  */
        /* the history - Shantanu */
        AppendCategory275String(
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
            g_jmms_context->compose_context->curr_slide_info.edit_content_buffer,
            JMMS_COMPOSE_TEXT_LENGTH,
            (U8*) temp_str,
            temphistory_p->guiBuffer);

        if (GetHistoryScrID(SCR_ID_JMMS_EDIT_CONTENT, &history_node_p) == ST_SUCCESS)
        {
            memcpy(history_node_p->guiBuffer, temphistory_p->guiBuffer, MAX_GUI_BUFFER);
        }
        jdd_MemFree(temphistory_p);
        DeleteUptoScrID(SCR_ID_JMMS_EDIT_CONTENT);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_insert_phb_contact
 * DESCRIPTION
 *  entry fn to phonebook to insert phb contact.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_insert_phb_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_generic_enter_list(mmi_jmms_insert_phb_contact);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_play_audio
 * DESCRIPTION
 *  play audio fn.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_compose_play_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *audio_media_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_media_info_p = mmi_jmms_jdi_get_audio_data(g_jmms_context->compose_context->curr_page_index);

    if (audio_media_info_p != NULL)
    {
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_media_drm_permitted(audio_media_info_p->pMimeInfo->ContentData.pFileName, DRM_PERMISSION_PLAY))
        {
    #endif /* __DRM_SUPPORT__ */ 
            mmi_audply_single_play((UI_string_type) audio_media_info_p->pMimeInfo->ContentData.pFileName, NULL);
        #ifdef __DRM_SUPPORT__
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                WARNING_TONE);
        }
        #endif /* __DRM_SUPPORT__ */ 
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_compose_play_video
 * DESCRIPTION
 *  play audio fn.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_jmms_video_play_finish_callback(S32 result);
void mmi_jmms_compose_play_video(void)
{
#ifdef __MMI_VIDEO_PLAYER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MEDIA_INFO *video_media_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_media_info_p = mmi_jmms_jdi_get_video_data(g_jmms_context->compose_context->curr_page_index);

    if (video_media_info_p != NULL)
    {
    #ifdef __DRM_SUPPORT__
        if (mmi_jmms_is_media_drm_permitted(video_media_info_p->pMimeInfo->ContentData.pFileName, DRM_PERMISSION_PLAY))
        {
    #endif /* __DRM_SUPPORT__ */ 
            U8 *guiBuffer;
            MMI_ALERT_TYPE alert_type;
            BOOL is_play_audio = TRUE;

            alert_type = GetMtCallAlertTypeEnum();
            if ((alert_type == MMI_VIBRATION_AND_RING || alert_type == MMI_VIBRATION_THEN_RING ||
                 alert_type == MMI_RING) && (!isInCall() || (isInCall() && GetWapCallPresent())))
            {
                is_play_audio = TRUE;
            }
            else
            {
                is_play_audio = FALSE;
            }

            guiBuffer = GetCurrGuiBuffer(SCR_ID_JMMS_VIDEO_PLAY);

            EntryNewScreen(SCR_ID_JMMS_VIDEO_PLAY, NULL, mmi_jmms_compose_play_video, NULL);

        #if defined(__MMI_DRAW_MANAGER__)
            ShowCategory225Screen(
                STR_ID_JMMS_PLAY_VIDEO,
                0,                      /* title_str */
                0,                      /* lsk_str */
                0,                      /* lsk_icon */
                STR_GLOBAL_BACK,        /* rsk_str */
                IMG_GLOBAL_BACK,        /* rsk_icon */
                0,                      /* video_id */
                (PS8) video_media_info_p->pMimeInfo->ContentData.pFileName,   /* video_filename */
                1,                      /* repeat_count */
                TRUE,                   /* is_visual_update */
                is_play_audio,          /* is_play_audio */
                TRUE,                   /* is_lcd_no_sleep */
                GDI_COLOR_BLACK,        /* bg_color */
                mmi_jmms_video_play_finish_callback,
                guiBuffer);
        #else /* defined(__MMI_DRAW_MANAGER__) */ 
            ShowCategory225Screen(
                STR_ID_JMMS_PLAY_VIDEO, /* title_str */
                0,                      /* title_icon */
                0,                      /* lsk_str */
                0,                      /* lsk_icon */
                STR_GLOBAL_BACK,        /* rsk_str */
                IMG_GLOBAL_BACK,        /* rsk_icon */
                0,                      /* video_id */
                (PS8) video_media_info_p->pMimeInfo->ContentData.pFileName,   /* video_filename */
                1,                      /* repeat_count */
                TRUE,                   /* is_visual_update */
                is_play_audio,          /* is_play_audio */
                TRUE,                   /* is_lcd_no_sleep */
                GDI_COLOR_BLACK,        /* bg_color */
                mmi_jmms_video_play_finish_callback,
                guiBuffer);
        #endif /* defined(__MMI_DRAW_MANAGER__) */ 
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        #ifdef __DRM_SUPPORT__
        }
        else
        {
            DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                1,
                JMMS_POPUP_TIME,
                WARNING_TONE);
        }
        #endif /* __DRM_SUPPORT__ */ 
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
}

#if defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_insert_vclndr_tdl
 * DESCRIPTION
 *  entry fn of todolist for vcalendar insertion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_insert_vclndr_tdl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->compose_context->from_jmms_app = 1;
    TDLShowAllList();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_vcal_tdl
 * DESCRIPTION
 *  convert tdl task to file and insert in MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 mmi_vclndr_writer(ToDoListNode *, S8 *);
void mmi_jmms_insert_vcal_tdl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    S8 ucs2_file_name[(MAX_TODO_LIST_NOTE + 30) * ENCODING_LENGTH];     /* 30 for @mms\\temp\\vobj\\.vcs */
    S8 buf[15];
    JDD_FILE fh;
    JC_CHAR *file_path_p = NULL;
    U32 index = 0;
    S8 temp_name[40] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ucs2_file_name, 0, (MAX_TODO_LIST_NOTE + 30) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) "@mms\\temp\\vobj\\");

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
            goto END;
        }
    }

    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name, E_OPEN_READ_MODE);

    if (fh == NULL) /* Folder Does Not Exist */
    {
        jdd_FSMakeDir(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name);
    }
    else
    {
        jdd_FSClose(fh);
    }

    /* Himanshu Fix MAUI_00228900 START */
    mmi_ucs2cat(
        (S8*) ucs2_file_name,
        (S8*) g_tdl_cntx.TaskList[g_tdl_cntx.SortedList[g_tdl_cntx.CurrSelectedTask]].Note);
    /* Himanshu Fix MAUI_00228900 END */
    mmi_asc_to_ucs2((S8*) buf, (S8*) ".vcs");
    mmi_ucs2cat((S8*) ucs2_file_name, (S8*) buf);

    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name, E_CREATE_WRITE_READ_MODE);

    if (fh == NULL)
    {
        for (index = 1; /* Empty Condition */ ; index++)
        {
            memset(temp_name, 0, 40);
            memset(ucs2_file_name, 0, (MAX_TODO_LIST_NOTE + 30) * ENCODING_LENGTH);
            sprintf(temp_name, "@mms\\temp\\vobj\\~vcalendar%d.vcs", index);
            mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) temp_name);
            /* Check whether the file exists with same name */
            if (E_FALSE == jdd_FSIsFileExist(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name))
            {
                /* No file with this name */
                break;
            }
        }
    }

    if (fh != NULL)
    {
        jdd_FSClose(fh);
    }
    file_path_p = (JC_CHAR*) jdd_FSFileNameTranslate(g_jmms_context->jmms_fs_handle, (JC_CHAR*) ucs2_file_name);;

    if (file_path_p == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_JMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, JMMS_POPUP_TIME, ERROR_TONE);
        goto END;
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    /* Himanshu Fix MAUI_00228900 START */
    result = mmi_vclndr_writer(&g_tdl_cntx.TaskList[g_tdl_cntx.SortedList[g_tdl_cntx.CurrSelectedTask]], (S8*) file_path_p);
    /* Himanshu Fix MAUI_00228900 END */
    if (result > 0) /* sachin */
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_VCALENDAR);
        /* Dilip 6th sept */
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_ATTACHEMNT_INSERT_VCALENDAR_TODO_LIST_INVALID_NAME),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        goto END;
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_VCALENDAR);
    }

    err_code = mmi_jmms_compose_add_media(file_path_p, E_MEDIA_OTHERS, E_TRUE, 0);
    if (err_code == JMMS_COMP_OK)
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
  END:

    if (file_path_p != NULL)
    {
        jdd_MemFree(file_path_p);
    }

}

#endif /* defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__) */ 
#ifdef __MMI_VCARD__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_vcard_phb
 * DESCRIPTION
 *  convert phb contact to vcard and insert in mms.
 * PARAMETERS
 *  resut_entry_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_insert_vcard_phb(MMI_PHB_VCARD_STRUCT *resut_entry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;

    S8 ucs2_file_name[(MAX_PB_NAME_LENGTH + 1 + 30) * ENCODING_LENGTH]; /* 30 for @mms\\temp\\vobj\\.vcf */
    S8 buf[15] = {0};
    JDD_FILE fh;
    JC_CHAR *file_path_p = NULL;
    JC_RETCODE ret_code = JC_OK;
    U32 index = 0;
    S8 temp_name[40] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DIlip 5th Sept 2006 */
    if (!mmi_ucs2strlen((S8*) resut_entry_p->name))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_ATTACHEMNT_INSERT_VCARD_PHB_NAME_EMPTY),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        goto END;
    }
    /* DIlip 5th Sept 2006 */
    memset(ucs2_file_name, 0, (MAX_PB_NAME_LENGTH + 1 + 30) * ENCODING_LENGTH);

    mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) "@mms\\temp\\vobj\\");

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if ((ret_code = jdd_FSInitialize(&g_jmms_context->jmms_fs_handle)) != JC_OK)
        {
            goto END;
        }
    }

    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name, E_OPEN_READ_MODE);

    if (fh == NULL) /* Folder Does Not Exist */
    {
        ret_code = jdd_FSMakeDir(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name);
        if ((ret_code != JC_OK) && (ret_code != JC_ERR_FILE_DIR_ALREADY_EXIST))
        {
            goto END;
        }
    }
    else
    {
        ret_code = jdd_FSClose(fh);
        if (ret_code != JC_OK)
        {
            goto END;
        }
    }

    mmi_ucs2cat((S8*) ucs2_file_name, (S8*) resut_entry_p->name);
    mmi_asc_to_ucs2((S8*) buf, (S8*) ".vcf");
    mmi_ucs2cat((S8*) ucs2_file_name, (S8*) buf);

    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name, E_CREATE_WRITE_READ_MODE);

    if (fh == NULL)
    {
        for (index = 1; /* Empty Condition */ ; index++)
        {
            memset(temp_name, 0, 40);
            memset(ucs2_file_name, 0, (MAX_PB_NAME_LENGTH + 1 + 30) * ENCODING_LENGTH);
            sprintf(temp_name, "@mms\\temp\\vobj\\~vcard%d.vcf", index);
            mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) temp_name);
            /* Check whether the file exists with same name */
            if (E_FALSE == jdd_FSIsFileExist(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name))
            {
                /* No file with this name */
                break;
            }
        }
    }

    if (fh != NULL)
    {
        ret_code = jdd_FSClose(fh);
        if (ret_code != JC_OK)
        {
            goto END;
        }
    }

    file_path_p = (JC_CHAR*) jdd_FSFileNameTranslate(g_jmms_context->jmms_fs_handle, (JC_CHAR*) ucs2_file_name);
    if (file_path_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        ret_code = jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
        if (ret_code != JC_OK)
        {
            goto END;
        }
    }

    result = mmi_vcard_writer_v21_select_card_to_file((S8*) file_path_p);
    if (result != FS_NO_ERROR)
    {
        ret_code = jdd_FSTranslateErr(result);
        goto END;
    }

    err_code = mmi_jmms_compose_add_media(file_path_p, E_MEDIA_OTHERS, E_TRUE, 0);
    if (err_code == JMMS_COMP_OK)
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }

  END:

    mmi_jmms_handle_error(ret_code);

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        ret_code = jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    if (file_path_p != NULL)
    {
        jdd_MemFree(file_path_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_entry_insert_vcard_phb
 * DESCRIPTION
 *  entry fn of phonebook for vcard insertion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_entry_insert_vcard_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_generic_enter_list(mmi_jmms_insert_vcard_phb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_my_vcard
 * DESCRIPTION
 *  convert phb contact to vcard and insert in mms.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_insert_my_vcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    JMMS_COMP_ERRCODE err_code = JMMS_COMP_OK;
    JC_RETCODE ret_code = JC_OK;

    S8 buf[15] = {0};
    JDD_FILE fh;
    JC_CHAR *file_path_p = NULL;
    S8 ucs2_file_name[(MAX_PB_NAME_LENGTH + 1 + 30) * ENCODING_LENGTH]; /* 30 for @mms\\temp\\vobj\\.vcf */
    U16 *file_name_p = NULL;
    MMI_PHB_VCARD_STRUCT my_card;
    S16 p_error;
    U32 index = 0;
    S8 temp_name[40] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if the name field is empy before send vCard */

    ReadRecord(NVRAM_EF_PHB_VCARD_LID, 1, (void*)&my_card, MMI_PHB_VCARD_RECORD_SIZE, &p_error);
    if (!mmi_ucs2strlen(my_card.name))
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_ATTACHEMNT_INSERT_VCARD_PHB_NAME_EMPTY),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
        goto END;
    }
    else
    {
        file_name_p = (U16*) my_card.name;
    }

    /* Vcard entry end */
    memset(ucs2_file_name, 0, (MAX_PB_NAME_LENGTH + 1 + 30) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) "@mms\\temp\\vobj\\");

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if ((ret_code = jdd_FSInitialize(&g_jmms_context->jmms_fs_handle)) != JC_OK)
        {
            goto END;
        }
    }

    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name, E_OPEN_READ_MODE);

    if (fh == NULL) /* Folder Does Not Exist */
    {
        ret_code = jdd_FSMakeDir(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name);
        if ((ret_code != JC_OK) && (ret_code != JC_ERR_FILE_DIR_ALREADY_EXIST))
        {
            goto END;
        }
    }
    else
    {
        ret_code = jdd_FSClose(fh);
        if (ret_code != JC_OK)
        {
            goto END;
        }
    }

    mmi_ucs2cat((S8*) ucs2_file_name, (S8*) file_name_p);
    mmi_asc_to_ucs2((S8*) buf, (S8*) ".vcf");
    mmi_ucs2cat((S8*) ucs2_file_name, (S8*) buf);

    fh = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name, E_CREATE_WRITE_READ_MODE);

    if (fh == NULL)
    {
        for (index = 1; /* Empty Condition */ ; index++)
        {
            memset(temp_name, 0, 40);
            memset(ucs2_file_name, 0, (MAX_PB_NAME_LENGTH + 1 + 30) * ENCODING_LENGTH);
            sprintf(temp_name, "@mms\\temp\\vobj\\~vcard%d.vcf", index);
            mmi_asc_to_ucs2((S8*) ucs2_file_name, (S8*) temp_name);
            /* Check whether the file exists with same name */
            if (E_FALSE == jdd_FSIsFileExist(g_jmms_context->jmms_fs_handle, (U16*) ucs2_file_name))
            {
                /* No file with this name */
                break;
            }
        }
    }

    if (fh != NULL)
    {
        ret_code = jdd_FSClose(fh);
        if (ret_code != JC_OK)
        {
            goto END;
        }
    }

    file_path_p = (JC_CHAR*) jdd_FSFileNameTranslate(g_jmms_context->jmms_fs_handle, (JC_CHAR*) ucs2_file_name);;
    if (file_path_p == NULL)
    {
        ret_code = JC_ERR_MEMORY_ALLOCATION;
        goto END;
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        ret_code = jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
        if (ret_code != JC_OK)
        {
            goto END;
        }
    }

    result = mmi_vcard_writer_v21_mycard_to_file((S8*) file_path_p);
    if (result != FS_NO_ERROR)
    {
        ret_code = jdd_FSTranslateErr(result);
        goto END;
    }

    err_code = mmi_jmms_compose_add_media(file_path_p, E_MEDIA_OTHERS, E_TRUE, 0);
    if (err_code == JMMS_COMP_OK)
    {
        GoBackToHistory(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_JMMS_ATTACHMENT_OPTIONS);
    }

  END:

    mmi_jmms_handle_error(ret_code);

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        ret_code = jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    if (file_path_p != NULL)
    {
        jdd_MemFree(file_path_p);
    }
}

#endif /* __MMI_VCARD__ */ 

#else /* __MMI_UNIFIED_COMPOSER__ */ 

#if defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__)


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_insert_vcal_tdl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_insert_vcal_tdl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Wrong Call */
    ASSERT(0);
    return;
}
#endif /* defined (__MMI_TODOLIST__) && defined(__MMI_VCALENDAR__) */ 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_attachment_data
 * DESCRIPTION
 *  to get media list data
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [OUT]       
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_jmms_get_attachment_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JMMS_COMP_ERRCODE ret_code = JMMS_COMP_OK;
    S32 count = 0;
    U8 media_count;
    MEDIA_INFO *media_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }
    ret_code = mmi_jmms_compose_get_media_list(0, &media_info_p, &media_count, E_TRUE);
    if (ret_code == JMMS_COMP_OK)
    {

        while (media_info_p != NULL && count != item_index)
        {
            media_info_p = media_info_p->pNext;
            count++;
        }

        if ((media_info_p == NULL) || (media_info_p->pMimeInfo == NULL))
        {
            return FALSE;
        }

        mmi_jmms_copy_with_dot(
            (S8*) str_buff,
            (S8*) media_info_p->pMimeInfo->MimeHeaders.pObjectName,
            MAX_SUBMENU_CHARACTERS);
        *img_buff_p = (PU8) GetImage((U16) (IMG_ID_JMMS_ATTACHMENT_LIST));
    }
    return TRUE;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_add_drm_media
 * DESCRIPTION
 *  fn shown confirmation popup whether user want to add media as DRM object..
 * PARAMETERS
 *  add_media_hdlr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_add_drm_media(FuncPtr add_media_hdlr)
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
        get_string(STR_ID_JMMS_ADD_MEDIA_AS_DRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    g_jmms_context->add_media_hdlr = add_media_hdlr;

    SetLeftSoftkeyFunction(mmi_jmms_confirm_add_drm_media_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_jmms_confirm_add_drm_media_no, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_add_drm_media_yes
 * DESCRIPTION
 *  Add media as DRM forward-lock media
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_add_drm_media_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->is_add_media_as_drm = MMI_TRUE;
    g_jmms_context->add_media_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_confirm_add_drm_media_no
 * DESCRIPTION
 *  Add media as normal media
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_confirm_add_drm_media_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jmms_context->is_add_media_as_drm = MMI_FALSE;
    g_jmms_context->add_media_hdlr();
}
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_file_can_be_forwarded_to_mms
 * DESCRIPTION
 *  tell file manager about jataayu availablity to forward file to mms
 * PARAMETERS
 *  filename_p      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
S32 mmi_jmms_is_file_can_be_forwarded_to_mms(const char *filename_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *ext_ptr_p;
    JC_CHAR *file_ext_p = NULL;
    U16 index1, start_index = 0;
    U16 index2;
    U8 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jdd_MemSetActiveModuleID(E_TASK_MMS_UI);
    ext_ptr_p = (U16*) mime_get_extension((kal_wchar*) filename_p);
    file_ext_p = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), mmi_ucs2strlen((S8*)ext_ptr_p) + 1);
    mmi_ucs2cpy((S8*) file_ext_p, (S8*) ext_ptr_p);

    count = sizeof(g_jmms_exclude_filter) / sizeof(fmgr_filter_struct);
#ifdef __MMI_UNIFIED_COMPOSER__
	if(mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE)
#else
	if (mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_FREE || mmi_jmms_compose_settings_creation_mode() == E_CREATION_MODE_WARNING)
#endif
	{
		for (index1 = 0; index1 < FMGR_MAX_FILTER_COUNT; ++index1)
		{
			if (jdi_UtilsTcsStrCaseCmp((const JC_CHAR*)file_ext_p, (const JC_INT8*)fmgr_filter[index1].ext) == 0)
			{
				for (index2 = 0; index2 < count; ++index2)
				{
					if (jdi_UtilsTcsStrCaseCmp
						((const JC_CHAR*)file_ext_p, (const JC_INT8*)g_jmms_exclude_filter[index2].ext) == 0)
					{
						jdd_MemFree(file_ext_p);
						return MMI_FALSE;
					}
				}
				jdd_MemFree(file_ext_p);
				return MMI_TRUE;
			}
		}
	}
	else
	{
		start_index = content_class_offset[MMS_SUPPORTED_CONTENT_CLASS];
		for(index1 = start_index; index1 <= content_class_offset[WAP_MMS_CONTENT_CLASS_TEXT]; index1++)
		{
			if ((restricted_attachment_filter[index1] != 0) &&
				jdi_UtilsTcsStrCaseCmp
					((const JC_CHAR*)file_ext_p, (const JC_INT8*)restricted_attachment_filter[index1]) == 0)
			{
				jdd_MemFree(file_ext_p);
				return MMI_TRUE;
			}
		}
	}
	jdd_MemFree(file_ext_p);
	return MMI_FALSE;
}

/* Himanshu Fix PMTSW00006527 START */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_for_image_size_and_resolution
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path_p          [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  media_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_BOOLEAN mmi_jmms_check_for_image_size_and_resolution(S8 *path_p, S32 width, S32 height, U32 media_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_BOOLEAN result = E_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_jdd_check_for_image_size_and_resolution(path_p, width, height, media_size);
    if (result == E_FALSE)
    {
        DisplayPopup(
            (PU8) GetString(STR_ID_JMMS_MEDIA_RESOLUTION_EXCEEDED),
            IMG_GLOBAL_ERROR,
            1,
            JMMS_POPUP_TIME,
            ERROR_TONE);
    }
    return result;
}

/* Himanshu Fix PMTSW00006527 END */
/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_image
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_image(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
#ifdef JPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif /* JPG_DECODE */ 
#ifdef SVG_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);
#endif 
#ifdef __DRM_ODF_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_ODF);
#endif 
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_audio
 * DESCRIPTION
 *  Set the audio filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_audio(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
#ifdef AAC_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);
#endif 
    FMGR_FILTER_SET(filter, FMGR_TYPE_VM);
#ifdef AMRWB_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
#if !defined(MT6205B)
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AU);
    FMGR_FILTER_SET(filter, FMGR_TYPE_SND);
#endif /* !defined(MT6205B) */ 
#if defined(MP4_CODEC) && defined(AAC_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);
#endif 
#if defined(EXT_AUDIO_CHIP) || defined(YAMAHA_MA3)
    FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);
#endif 
#if defined(MUSICAM_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);
#endif 
#ifdef __DRM_ODF_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_ODF);
#endif

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_video
 * DESCRIPTION
 *  Set the video filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_video(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

#if defined(ISP_SUPPORT)
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#elif defined(CAMERA_MODULE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_AVI);
#endif 
#ifdef __DRM_ODF_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_ODF);
#endif

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_attachment
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_attachment(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 count = 0, index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

    FMGR_FILTER_SET_ALL(filter);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
    FMGR_FILTER_CLEAR(filter, FMGR_TYPE_ALL);

    count = sizeof(g_jmms_exclude_filter) / sizeof(fmgr_filter_struct);
    for (index = 0; index < count; ++index)
    {
        FMGR_FILTER_CLEAR(filter, g_jmms_exclude_filter[index].type);
    }

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_image_restricted
 * DESCRIPTION
 *  Set the image filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_image_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

	switch(MMS_SUPPORTED_CONTENT_CLASS)
	{

		case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
		case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:
		case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:
		case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:

			FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
			FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
			FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
		#ifdef JPG_DECODE
			FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
			FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
		#endif /* JPG_DECODE */ 
			break;
	}
	FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
	FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_audio_restricted
 * DESCRIPTION
 *  Set the audio filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_audio_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

	switch(MMS_SUPPORTED_CONTENT_CLASS)
	{
		case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
		case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:
		case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:

			FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
			FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);

		case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:
  
			FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
			break;
	}
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_video_restricted
 * DESCRIPTION
 *  Set the video filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_video_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

	switch(MMS_SUPPORTED_CONTENT_CLASS)
	{
		case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
		case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:

		#if defined(ISP_SUPPORT)
			FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
			FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
			FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
		#endif 

		case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:
		case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:

			break;
	}

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_file_mgr_filter_for_attachment_restricted
 * DESCRIPTION
 *  Set the attachment filter
 * PARAMETERS
 *  filter        [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_file_mgr_filter_for_attachment_restricted(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__))
	FMGR_FILTER_INIT(filter);

	switch(MMS_SUPPORTED_CONTENT_CLASS)
	{
		case WAP_MMS_CONTENT_CLASS_VIDEO_RICH:
		case WAP_MMS_CONTENT_CLASS_VIDEO_BASIC:

		#if defined(ISP_SUPPORT)
			FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
			FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
			FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
		#endif 

		case WAP_MMS_CONTENT_CLASS_IMAGE_RICH:

			FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
			FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);

		case WAP_MMS_CONTENT_CLASS_IMAGE_BASIC:

		#ifdef __MMI_EBOOK_READER__
			FMGR_FILTER_SET(filter, FMGR_TYPE_EBOOK_TXT);
		#endif
			FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
			FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
			FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
		#ifdef JPG_DECODE
			FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
			FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
		#endif /* JPG_DECODE */ 
			FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
			break;
	}

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);

#endif /* ( defined(MMI_ON_HARDWARE_P) && defined(__MMI_FILE_MANAGER__)) */ 
}

#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 

