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
 * SoundRecorderSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifdef __MMI_SOUND_RECORDER__

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif 

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "CallmanagementIdDef.h"
#include "CallManagementGprot.h"

#include "MainMenuDef.h"
#include "FunAndGamesDefs.h"
#include "CustomCfg.h"
#include "Ucs2prot.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "rtc_sw.h"
#include "ProfileGprots.h"
#include "SettingProfile.h"
#include "wgui_inline_edit.h"

#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FileMgr.h"

#include "SoundRecorderDef.h"
#include "SoundRecorderType.h"
#include "SoundRecorderProt.h"
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#include "ProfileMgrGProt.h"
#endif 

#include "USBDeviceGprot.h"
#include "WPSSProtos.h"
#include "PhoneSetupGprots.h"


#ifdef __DRM_SUPPORT__
#define DRM_NOT_PERMIT_TO_PLAY   9999
#define DRM_NOT_PERMIT_TO_APPEND 10000
#endif /* __DRM_SUPPORT__ */ 

/*=============  Constants & Global Variables  ================ */

SoundRecorderStruct SoundRecorder;
static SoundFileListStruct *FileList_p = &SoundRecorder.SoundFileList;
static SoundRecorderSettingsStruct *Settings_p = &SoundRecorder.Settings;
U8 mmi_sndrec_is_rename_editor_in_call = 0;
void (*mmi_sndrec_sms_record_callback) (BOOL result, U16* filepath);
/*============= Local Variables =================*/

/* settings */
#define MAX_SR_SETTINGS_FIELDS 3

U16 SRTitleStrings[MAX_SR_SETTINGS_FIELDS];

S32 selectedStorageIndex;
S32 selectedFormatIndex;
S32 selectedAudioqualityindex;

#define NO_OF_STORAGES  2

//#ifdef MT6205B
//#define NO_OF_FORMATS  NO_OF_FORMAT     /* vm is explicit if this is our only one format */
//#else 
//#define NO_OF_FORMATS  (NO_OF_FORMAT-1) /* vm is not explicit */
//#endif 

MMI_ID_TYPE gFormatIds[] = 
{
#ifndef MT6205B
    STR_ID_SNDREC_SETTINGS_AMR,
    STR_ID_SNDREC_SETTINGS_WAV,
#endif /* MT6205B */ 
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    STR_ID_SNDREC_SETTINGS_AMRWB,
#endif 
    STR_ID_SNDREC_SETTINGS_VM
};

MMI_ID_TYPE gAudioquality[] =
{
    STR_ID_SNDREC_QUALITY_LOW,
    STR_ID_SNDREC_QUALITY_HIGH
};

UI_string_type gFormats[NO_OF_FORMAT];
UI_string_type gQuality[NO_OF_QUALITY];
static S32 currFileIndex;
static UI_character_type editorBuffer[MAX_INPUT_FILE_LEN + 2];

static UI_character_type strBuffer[30];
static UI_character_type extBuffer[FMGR_MAX_EXT_LEN + 1];

#define NO_BLOCK_INT  2
/*
 * U16 BlockInterruptTable[]=
 * {
 * PRT_EQ_GPIO_DETECT_IND,
 * PRT_BATTERY_STATUS_IND   
 * };
 * 
 * #define NO_ENABLE_INT  2
 * 
 * U16 EnableInterruptTable[]=
 * {
 * PRT_INCOMINGCALL_EVENT,
 * MSG_ID_SIM_CARD_FAILURE
 * };
 */

static U16 current_scr_id;
static FuncPtr current_entry_func;

/*===============    Functions    ====================*/

#define SR_MAIN


/*****************************************************************************
 * FUNCTION
 *  InitSoundRecorderApp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitSoundRecorderApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_SNDREC_MAIN, mmi_sndrec_hightlight_main);
#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    SetHiliteHandler(MENU_ID_SNDREC_NEW_RECORD, mmi_sndrec_hightlight_record);
    SetHiliteHandler(MENU_ID_SNDREC_LIST, mmi_sndrec_highlight_list);
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    SetHiliteHandler(MENU_ID_SNDREC_RECORD, mmi_sndrec_hightlight_record);
    SetHiliteHandler(MENU_ID_SNDREC_PLAY, mmi_sndrec_hightlight_play);
    SetHiliteHandler(MENU_ID_SNDREC_APPEND, mmi_sndrec_hightlight_append);
    SetHiliteHandler(MENU_ID_SNDREC_RENAME, highlight_fmgr_rename);
    SetHiliteHandler(MENU_ID_SNDREC_OPTION_SAVE, mmi_sndrec_hightlight_save);
    SetHiliteHandler(MENU_ID_SNDREC_OPTION_INPUT_METHOD, mmi_sndrec_hightlight_input_method);
    SetHiliteHandler(MENU_ID_SNDREC_DELETE, mmi_sndrec_hightlight_delete);
    SetHiliteHandler(MENU_ID_SNDREC_DELETE_ALL, mmi_sndrec_hightlight_delete_all);
    SetHiliteHandler(MENU_ID_SNDREC_SETTINGS, mmi_sndrec_hightlight_settings);

    SoundRecorder.inCall = FALSE;
    SoundRecorder.isFromCallExpress = FALSE;
    SoundRecorder.isSlefStop = FALSE;
    SoundRecorder.isAppend = FALSE;
    SoundRecorder.is_sim_two = MMI_FALSE;
    SoundRecorder.need_file_prefix = MMI_FALSE;
    mmi_sndrec_auto_record_init();
    mmi_sndrec_init_settings();
    mmi_sndrec_init_file_list();
    /* mmi_sndrec_create_sound_folder(); */
}

#ifdef __MMI_SOUND_RECORDER_STYLE_X__


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_highlight_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_highlight_list(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_entry_main, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    SetKeyHandler(mmi_sndrec_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_style_x_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_style_x_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U8 *guiBuffer;                      /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_SNDREC_MAIN, NULL, mmi_sndrec_entry_style_x_main, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_MAIN);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_ID_SNDREC_MAIN);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_ID_SNDREC_MAIN, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_SNDREC_MAIN);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 show category screen */
    ShowCategory15Screen(
        SCR_ID_SNDREC_MAIN,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_sndrec_check_usb_mode(void)
{
#ifdef __USB_IN_NORMAL_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        mmi_sndrec_get_full_path(Settings_p->curr_drv);
		if (mmi_usb_check_path_exported((PS8) FileList_p->storagePath))
        {   
            Settings_p->curr_drv = (U8)MMI_PUBLIC_DRV;
            mmi_sndrec_get_full_path(Settings_p->curr_drv);
            if (mmi_usb_check_path_exported((PS8) FileList_p->storagePath))
            {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                return TRUE;
    }
            else
            {
                WriteValue(NVRAM_SNDREC_STORAGE, &Settings_p->curr_drv, DS_BYTE, &error);
            }
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
        return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_in_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_in_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (mmi_sndrec_check_usb_mode())
    {
        return;
    }

    SoundRecorder.inCall = FALSE;
    SoundRecorder.isFromCallExpress = FALSE;
    mmi_sndrec_is_rename_editor_in_call = 0;
    /* mmi_sndrec_create_sound_folder(); */

#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    mmi_sndrec_entry_style_x_main();
#else 
    mmi_sndrec_entry_main();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_in_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (mmi_sndrec_check_usb_mode())
    {
        return;
    }
    if(mmi_sndrec_auto_record_is_on())
    {
        return;
    }

    SoundRecorder.inCall = TRUE;
    SoundRecorder.isFromCallExpress = FALSE;
    mmi_sndrec_is_rename_editor_in_call = 0;
    mmi_sndrec_send_record_req();
    /*delete screen if MT comes at sound record edit file name screen*/
    DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
    DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME);
    DeleteScreenIfPresent(SCR_INPUT_METHOD_LIST);
    DeleteScreenIfPresent(SCR_FMGR_APP_EMPTY_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_in_voip_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_in_voip_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_format;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
#ifdef __MMI_VOIP__
    if (mmi_sndrec_check_usb_mode())
    {
        return;
    }
    if(mmi_sndrec_auto_record_is_on())
    {
        return;
    }

    SoundRecorder.inCall = TRUE;
    SoundRecorder.isFromCallExpress = FALSE;
    mmi_sndrec_is_rename_editor_in_call = 0;

   if (!mmi_sndrec_check_dest_folder(Settings_p->curr_drv))
    {
        return;
    }
    /*delete screen if MT comes at sound record edit file name screen*/
    DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
    DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME);
    DeleteScreenIfPresent(SCR_INPUT_METHOD_LIST);
    DeleteScreenIfPresent(SCR_FMGR_APP_EMPTY_FOLDER_OPTION);
    DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION);
    ClearInputEventHandler(MMI_DEVICE_ALL);
    temp_format = SoundRecorder.Settings.format;
    /* Modify global variable to get correct file extension in this function */
#ifndef MT6205B
    SoundRecorder.Settings.format = FORMAT_AMR;
#else
    SoundRecorder.Settings.format = FORMAT_EVL;
#endif
    mmi_sndrec_get_new_file(SoundRecorder.fileName, SoundRecorder.fullName);
    SoundRecorder.Settings.format = temp_format;

    if (mmi_sndrec_start_record(SoundRecorder.fullName,
#ifndef MT6205B
        (U8) (FORMAT_AMR), 
#else
        (U8) (FORMAT_EVL),
#endif
        SoundRecorder.Settings.quality))
    {
        mmi_sndrec_set_interrupt_hdlr();
        /* To stop the play when interrupt happened before play confirm */
        ReplaceNewScreenHandler(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, NULL);
    }
    else
        mmi_sndrec_exit_hdlr();            
#endif   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_from_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_from_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (mmi_sndrec_check_usb_mode())
    {
        return;
    }
    if(mmi_sndrec_auto_record_is_on())
    {
        return;
    }

    SoundRecorder.inCall = TRUE;
    SoundRecorder.isFromCallExpress = TRUE;
    mmi_sndrec_is_rename_editor_in_call = 0;
    mmi_sndrec_send_record_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_filename_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullname        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_filename_callback(void *fullname, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullname == NULL)
    {
        GoBackHistory();
    }
    else
    {
        mmi_ucs2cpy((S8*) SoundRecorder.fullName, (S8*) fullname);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
#ifndef MT6205B
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);
#endif /* MT6205B */ 
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AWB);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_VM);

    mmi_sndrec_get_full_path(Settings_p->curr_drv);
    mmi_fmgr_select_path_and_enter(
        APP_SOUNDRECORDER,
        FMGR_SELECT_BROWSE,
        filter,
        (PS8) FileList_p->storagePath, /* Must call get full path before use */
        mmi_sndrec_filename_callback);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_main(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_entry_in_idle, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    SetKeyHandler(mmi_sndrec_entry_in_idle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define SR_FILE_LIST


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_create_sound_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_create_sound_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;
    kal_int16 i;
    S8 drv_array[FMGR_TOTAL_STORAGE];
    U8 drv_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_get_exist_drive_letter((S8*)drv_array, &drv_num);

    for (i = 0; i < drv_num; i++)
    {
        mmi_sndrec_get_full_path(drv_array[i]);
        file_handle = FS_Open(FileList_p->storagePath, FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle < 0)
        {
            result = FS_CreateDir(FileList_p->storagePath);
        }
        else
        {
            FS_Close(file_handle);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_dest_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_sndrec_check_dest_folder(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_path(drv_letter);
    file_handle = FS_Open(FileList_p->storagePath, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        result = FS_CreateDir(FileList_p->storagePath);
        if (result < 0)
        {
            if (result == FS_MEDIA_CHANGED)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_SNDREC_NO_CARD),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(result)),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
            }
            return FALSE;
        }
    }
    else
    {
        FS_Close(file_handle);
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_init_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_init_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FileList_p->noOfEntries = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_is_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_sndrec_get_full_path(S16 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        (kal_wchar*) FileList_p->storagePath,
        "%c:\\%w",
        drv_letter,
        FMGR_DEFAULT_FOLDER_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullname        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type mmi_sndrec_get_file_name(UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = fullname + mmi_ucs2strlen((const S8*)fullname);
    while (p > fullname)
    {
        if (*p == L'\\')
        {
            return (p + 1);
        }
        p--;
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_remove_file_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_remove_file_ext(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extBuffer[0] = 0;
    p = filename + mmi_ucs2strlen((const S8*)filename);
    while (p > filename)
    {
        if (*p == L'.')
        {
            *p = 0;
            mmi_ucs2ncpy((S8*) extBuffer, (S8*) (p + 1), FMGR_MAX_EXT_LEN);
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_append_file_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_append_file_ext(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 format =
#ifndef MT6205B
#if !defined(__MMI_DEDI_AMR_REC__)
        (SoundRecorder.inCall && SoundRecorder.Settings.format != (U8)FORMAT_VM) ? FORMAT_WAV :
#elif defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
        (SoundRecorder.inCall && SoundRecorder.Settings.format == FORMAT_AWB) ? FORMAT_AMR :
#endif 
#endif /* MT6205B */ 
        SoundRecorder.Settings.format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (format)
    {
    #ifndef MT6205B
        case FORMAT_AMR:
            mmi_ucs2ncat((S8*) filename, (S8*) FILE_EXT_AMR, MAX_FILE_NAME_LEN);
            break;
        case FORMAT_WAV:
            mmi_ucs2ncat((S8*) filename, (S8*) FILE_EXT_WAV, MAX_FILE_NAME_LEN);
            break;
    #endif /* MT6205B */ 
    #if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
        case FORMAT_AWB:
            mmi_ucs2ncat((S8*) filename, (S8*) FILE_EXT_AWB, MAX_FILE_NAME_LEN);
            break;
    #endif /* defined(AMRWB_ENCODE) && defined(AMRWB_DECODE) */ 
        case FORMAT_VM:
            mmi_ucs2ncat((S8*) filename, (S8*) FILE_EXT_VM, MAX_FILE_NAME_LEN);
            break;
        case FORMAT_EVL:
            mmi_ucs2ncat((S8*) filename, (S8*) L".evl", MAX_FILE_NAME_LEN);
            break;
    }
    /* } */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_increase_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_increase_file_name(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;
    U16 fileCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = filename + mmi_ucs2strlen((const S8*)filename);
    while (p > filename)
    {
        if (*p == L'.')
        {
            fileCount = (*(p - 2) - '0') * 10 + (*(p - 1) - '0');
            fileCount++;
            *(p - 1) = fileCount % 10 + '0';
            *(p - 2) = fileCount / 10 + '0';
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_check_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_sndrec_check_file_exist(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(filename, FS_READ_ONLY);
    if (fd >= 0)
    {
        FS_Close(fd);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_new_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  fullname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_new_file(UI_string_type filename, UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc rtc_time;
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_create_sound_folder();

    RTC_GetTime(&rtc_time);

#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    kal_wsprintf(
        (kal_wchar*) filename,
        "V%02d%02d%04d_%02d%02d_00",
        rtc_time.rtc_day,
        rtc_time.rtc_mon,
        rtc_time.rtc_year + 2000,
        rtc_time.rtc_hour,
        rtc_time.rtc_min);
#else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    kal_wsprintf(
        (kal_wchar*) filename,
        "%02d%02d%02d%02d00",
        rtc_time.rtc_mon,
        rtc_time.rtc_day,
        rtc_time.rtc_hour,
        rtc_time.rtc_min);
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 

    mmi_sndrec_get_full_path(Settings_p->curr_drv);
    if (SoundRecorder.need_file_prefix == MMI_FALSE)
    {
    kal_wsprintf(
        (kal_wchar*) fullname,
        "%w%w",
        FileList_p->storagePath, /* Must call get full path before use */
        (const kal_wchar*)filename);
    }
    else
    {
        if (SoundRecorder.is_sim_two == MMI_TRUE)
        {
            kal_prompt_trace(MOD_MMI,"mmi_sndrec_get_new_file MMI_SNDREC_SIM_TWO_CAPTION %d", SoundRecorder.is_sim_two);
            kal_wsprintf(
                (kal_wchar*) fullname,
                "%w%w%w",
                FileList_p->storagePath, /* Must call get full path before use */
                MMI_SNDREC_SIM_TWO_CAPTION,
                (const kal_wchar*)filename);
        }
        else
        {
            kal_prompt_trace(MOD_MMI,"mmi_sndrec_get_new_file MMI_SNDREC_SIM_ONE_CAPTION %d", SoundRecorder.is_sim_two);
            kal_wsprintf(
                (kal_wchar*) fullname,
                "%w%w%w",
                FileList_p->storagePath, /* Must call get full path before use */
                MMI_SNDREC_SIM_ONE_CAPTION,
                (const kal_wchar*)filename);
        }
    }
    mmi_sndrec_append_file_ext(fullname);

    for (i = j = 0; mmi_sndrec_check_file_exist(fullname); i++)
    {
        /* this check prevent from infinite loop if 00~99 are all used */
        if (i == 100)
        {
            j++;
        #ifdef __MMI_SOUND_RECORDER_STYLE_X__
            kal_wsprintf(
                (kal_wchar*) filename,
                "V%02d%02d%04d_%02d%02d_%d00",
                rtc_time.rtc_day,
                rtc_time.rtc_mon,
                rtc_time.rtc_year + 2000,
                rtc_time.rtc_hour,
                rtc_time.rtc_min,
                j);
        #else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
            kal_wsprintf(
                (kal_wchar*) filename,
                "%02d%02d%02d%02d%d00",
                rtc_time.rtc_mon,
                rtc_time.rtc_day,
                rtc_time.rtc_hour,
                rtc_time.rtc_min,
                j);
        #endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
            i = -1;
        }
        else
        {
            mmi_sndrec_increase_file_name(fullname);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_new_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_new_file_name(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.inCall = TRUE;
    mmi_sndrec_get_new_file(SoundRecorder.fileName, filename);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_current_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  fullname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_current_file(UI_string_type filename, UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currFileIndex < FileList_p->noOfEntries)
    {
        FMGR_FILE_INFO_STRUCT file_info;

        mmi_fmgr_kernel_get_file_info((U16) currFileIndex, &file_info);
        mmi_ucs2cpy((S8*) filename, (S8*) file_info.file_name);
        kal_wsprintf(fullname, "%c:\\%w%w", Settings_p->curr_drv, FMGR_DEFAULT_FOLDER_AUDIO, filename);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_current_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  forwardable     [OUT]
 * RETURNS
 *  
 *****************************************************************************/
FMGR_FILTER mmi_sndrec_get_current_file_format(BOOL *forwardable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
#ifdef __DRM_SUPPORT__
    BOOL is_drm;
    U8 drm_forward_rule;
#endif /* __DRM_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (currFileIndex < FileList_p->noOfEntries)
    {
        FMGR_FILE_INFO_STRUCT file_info;

        mmi_fmgr_kernel_get_file_info((U16) currFileIndex, &file_info);
#ifdef __DRM_SUPPORT__
        drm_forward_rule = fmgr_get_drm_forward_rule(&file_info, &is_drm);
        if (is_drm)
        {
            if (drm_forward_rule == FMGR_DRM_FWD_APP_NO_FWD_OUT ||
                drm_forward_rule == FMGR_DRM_FWD_APP_FWD_OUT)
                *forwardable = TRUE;
            else
                *forwardable = FALSE;
        }
        else
#endif /* __DRM_SUPPORT__ */
        {
            *forwardable = TRUE;
        }

        return file_info.file_type;
    }

    FMGR_FILTER_INIT(&filter);
    *forwardable = TRUE;

    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_menuId
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_sndrec_get_menuId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menuId;
    FMGR_FILTER filter;
    BOOL forwardable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currFileIndex = mmi_fmgr_kernel_get_cur_idx();
    FileList_p->noOfEntries = mmi_fmgr_kernel_get_file_count();
    filter = mmi_sndrec_get_current_file_format(&forwardable);

    if (FMGR_FILTER_IS_SET(&filter, FMGR_TYPE_WAV))
    {
    #ifdef MT6205B
        if (forwardable)
            menuId = MENU_ID_SNDREC_OPTION_5;
        else
            menuId = MENU_ID_SNDREC_OPTION_9;
    #else 
        if (forwardable)
            menuId = MENU_ID_SNDREC_OPTION_2;   /* record, play,rename, delete, delete all, settings, forward */
        else
            menuId = MENU_ID_SNDREC_OPTION_7;
    #endif 
    }
    else
    {
    #ifdef MT6205B
        if (forwardable)
            menuId = MENU_ID_SNDREC_OPTION_3;
        else
            menuId = MENU_ID_SNDREC_OPTION_8;
    #else 
        if (forwardable)
            menuId = MENU_ID_SNDREC_OPTION; /* record, play, append, rename, delete, delete all, settings, forward */
        else
            menuId = MENU_ID_SNDREC_OPTION_6;
    #endif 
    }
    return menuId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_is_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_sndrec_is_file_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sndrec_check_file_exist(SoundRecorder.fullName))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


#define SR_INTERRUPT_HANDLE


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.state != STATE_IDLE)
    {
        SoundRecorder.cmdProcessing = FALSE;
        if (SoundRecorder.state == STATE_RECORD || SoundRecorder.state == STATE_RECORD_PAUSED)
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_stop_record();
        }
        else
        {
            SoundRecorder.state = STATE_IDLE;
            mmi_sndrec_stop_play();
        }
        SoundRecorder.cmdProcessing = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_exit_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.inCall = FALSE;
    SoundRecorder.isAppend = FALSE;
    mmi_phnset_enable_partial_ss();
    mmi_sndrec_abort();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_exit_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrnID              [IN]        
 *  exitFuncPtr         [IN]        
 *  entryFuncPtr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_set_exit_hdlr(U16 scrnID, FuncPtr exitFuncPtr, FuncPtr entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_scr_id = scrnID;
    current_entry_func = entryFuncPtr;
    ReplaceNewScreenHandler(scrnID, exitFuncPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_enabled_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_sndrec_enabled_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interrupt_event & MMI_FRM_INT_BATTERY)
    {
        SetInterruptPopupDisplay(POPUP_ALL_OFF);
    }
    else if (interrupt_event & MMI_FRM_INT_FMGR_CARD)
    {
        if (Settings_p->curr_drv == (U8)MMI_PUBLIC_DRV)
        {
            SetInterruptPopupDisplay(POPUP_ALL_OFF);
        }
    }
    else if (interrupt_event & MMI_FRM_INT_EARPHONE)
    {
        SetInterruptPopupDisplay(POPUP_ALL_OFF);
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_post_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_sndrec_post_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_ON);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_set_interrupt_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.exitToStop = TRUE;
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_BATTERY | MMI_FRM_INT_FMGR_CARD | MMI_FRM_INT_EARPHONE, 
        mmi_sndrec_enabled_interrupt_hdlr, mmi_sndrec_post_interrupt_hdlr);
    /* SetGroupInterruptEventHandler(mmi_sndrec_enabled_interrupt_hdlr, EnableInterruptTable, NO_ENABLE_INT); */
}

#define SR_RECORD


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 duration = mmi_sndrec_get_duration_ticks();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    mmi_sndrec_set_interrupt_hdlr();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_RECORD);
#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    ShowCategory223Screen(
        STR_ID_SNDREC_NEW_RECORD,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_OPTION_SAVE,
        0,
        STR_ID_SNDREC_PAUSE,
        0,
        IMG_ID_SNDREC_RECORDING,
        1,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_stop_record, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_pause, KEY_EVENT_UP);
#else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    ShowCategory223Screen(
        STR_ID_SNDREC_RECORD,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_PAUSE,
        0,
        STR_ID_SNDREC_STOP,
        0,
        IMG_ID_SNDREC_RECORDING,
        1,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_pause, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_stop_record, KEY_EVENT_UP);
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    mmi_sndrec_set_exit_hdlr(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, mmi_sndrec_entry_record);
    mmi_sndrec_set_sidekey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_paused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record_paused(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 title;
    U32 duration = mmi_sndrec_get_duration_ticks();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_set_interrupt_hdlr();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_RECORD_PAUSED);
#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    if (SoundRecorder.isAppend)
    {
        title = STR_ID_SNDREC_APPEND;
    }
    else
    {
        title = STR_ID_SNDREC_NEW_RECORD;
    }
    ShowCategory223Screen(
        title,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_OPTION_SAVE,
        0,
        STR_ID_SNDREC_RESUME,
        0,
        IMG_ID_SNDREC_RECORDING_PAUSED,
        0,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_stop_record, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_resume, KEY_EVENT_UP);
#else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    if (SoundRecorder.isAppend)
    {
        title = STR_ID_SNDREC_APPEND;
    }
    else
    {
        title = STR_ID_SNDREC_RECORD;
    }
    ShowCategory223Screen(
        title,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_RESUME,
        0,
        STR_ID_SNDREC_STOP,
        0,
        IMG_ID_SNDREC_RECORDING_PAUSED,
        0,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_resume, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_stop_record, KEY_EVENT_UP);
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    mmi_sndrec_set_exit_hdlr(SCR_ID_SNDREC_RECORD_PAUSED, mmi_sndrec_exit_hdlr, mmi_sndrec_entry_record_paused);
    mmi_sndrec_set_sidekey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_stopped_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_record_stopped_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.isAppend = FALSE;
    SoundRecorder.isSlefStop = FALSE;

    filename = mmi_sndrec_get_file_name(SoundRecorder.fullName);
    memcpy(editorBuffer, filename, (MAX_INPUT_FILE_LEN + 2) * ENCODING_LENGTH);
    mmi_sndrec_remove_file_ext(editorBuffer);
    /* delete the same editor screens if in history */
    mmi_sndrec_delete_name_editor_history_nodes();

    if (IsScreenPresent(GetCmMarkerScrnID()))
    {
        mmi_sndrec_is_rename_editor_in_call = 1;
    }

    mmi_sndrec_entry_edit_name();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_disk_full_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_record_disk_full_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type filename;
    history h;
    S16 nHistory = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.isAppend = FALSE;
    SoundRecorder.isSlefStop = FALSE;

    filename = mmi_sndrec_get_file_name(SoundRecorder.fullName);
    memcpy(editorBuffer, filename, (MAX_INPUT_FILE_LEN + 2) * ENCODING_LENGTH);
    mmi_sndrec_remove_file_ext(editorBuffer);
    /* delete the same editor screens if in history */
    mmi_sndrec_delete_name_editor_history_nodes();

    if (IsScreenPresent(GetCmMarkerScrnID()))
    {
        mmi_sndrec_is_rename_editor_in_call = 1;
    }
    h.scrnID = SCR_ID_SNDREC_RENAME;
    h.entryFuncPtr = mmi_sndrec_entry_edit_name;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_edit_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_edit_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SNDREC_RENAME, NULL, mmi_sndrec_entry_edit_name, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_RENAME);
    ShowCategory5Screen(
        STR_GLOBAL_FILENAME,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) editorBuffer,
        MAX_INPUT_FILE_LEN + 1,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_entry_rename_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_sndrec_entry_abort_query, KEY_EVENT_UP);

    RegisterInputMethodScreenCloseFunction(mmi_sndrec_go_back_2_history);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_abort_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_abort_query(void)
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
        get_string(STR_ID_SNDREC_QUERY_ABORT),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_sndrec_abort_file, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_abort_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_abort_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_Delete(SoundRecorder.fullName);
    DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME);
	if (mmi_sndrec_sms_record_callback != NULL)
	{	
		mmi_sndrec_sms_record_callback(FALSE, SoundRecorder.fullName);
		mmi_sndrec_sms_record_callback = NULL;
	}
    if (result < 0)
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 1, 1000, (U8) WARNING_TONE);
    }
    else
#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    if (!IsScreenPresent(GetCmMarkerScrnID()) && !mmi_sndrec_is_rename_editor_in_call)
    {
        GoBackToHistory(SCR_ID_SNDREC_MAIN);
    }
    else
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
        GoBackHistory();
    mmi_sndrec_is_rename_editor_in_call = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_save_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_save_query(void)
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
        get_string(STR_ID_SNDREC_SAVE_AUDIO),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_sndrec_save_file_in_sms, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_abort_file_in_sms, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_file_in_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_save_file_in_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sndrec_sms_record_callback != NULL)
	{	
        mmi_sndrec_sms_record_callback(TRUE, SoundRecorder.fullName);
        mmi_sndrec_sms_record_callback = NULL;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_abort_file_in_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_abort_file_in_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sndrec_sms_record_callback != NULL)
	{	
        mmi_sndrec_sms_record_callback(FALSE, SoundRecorder.fullName);
        mmi_sndrec_sms_record_callback = NULL;
    }
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_send_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if destination folder exists before record. */
    if (!mmi_sndrec_check_dest_folder(Settings_p->curr_drv))
    {
        return;
    }

    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_sndrec_get_new_file(SoundRecorder.fileName, SoundRecorder.fullName);
    if (mmi_sndrec_start_record(SoundRecorder.fullName,
        (U8) (
#ifndef MT6205B
#if !defined(__MMI_DEDI_AMR_REC__)
                 (SoundRecorder.inCall && SoundRecorder.Settings.format != (U8)FORMAT_VM) ? FORMAT_WAV :
#elif defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
                 (SoundRecorder.inCall && 
                 SoundRecorder.Settings.format == (U8)FORMAT_AWB) ? FORMAT_AMR :
#endif 
#endif /* MT6205B */ 
                 SoundRecorder.Settings.format), SoundRecorder.Settings.quality))
    {
        mmi_sndrec_set_interrupt_hdlr();
        /* To stop the play when interrupt happened before play confirm */
        ReplaceNewScreenHandler(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, NULL);
    }
    else
        mmi_sndrec_exit_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_record(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_send_record_req, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define SR_PLAY


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 duration = mmi_sndrec_get_duration_ticks();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_disable_partial_ss();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    mmi_sndrec_set_interrupt_hdlr();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_PLAY);
    ShowCategory223Screen(
        STR_ID_SNDREC_PLAY,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_PAUSE,
        0,
        STR_ID_SNDREC_STOP,
        0,
        IMG_ID_SNDREC_PLAYING,
        1,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_pause, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_stop_play, KEY_EVENT_UP);
    mmi_sndrec_set_exit_hdlr(SCR_ID_SNDREC_PLAY, mmi_sndrec_exit_hdlr, mmi_sndrec_entry_play);
    mmi_sndrec_set_sidekey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_play(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_send_play_req, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    SetKeyHandler(mmi_sndrec_send_play_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_play_paused
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_play_paused(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 duration = mmi_sndrec_get_duration_ticks();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phnset_disable_partial_ss();
    mmi_sndrec_set_interrupt_hdlr();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_PLAY_PAUSED);
    ShowCategory223Screen(
        STR_ID_SNDREC_PLAY,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_RESUME,
        0,
        STR_ID_SNDREC_STOP,
        0,
        IMG_ID_SNDREC_PLAYING_PAUSED,
        0,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_resume, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_stop_play, KEY_EVENT_UP);
    mmi_sndrec_set_exit_hdlr(SCR_ID_SNDREC_PLAY_PAUSED, mmi_sndrec_exit_hdlr, mmi_sndrec_entry_play_paused);
    mmi_sndrec_set_sidekey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_send_play_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_sndrec_get_current_file(SoundRecorder.fileName, SoundRecorder.fullName);
    mmi_sndrec_set_interrupt_hdlr();
    if (mmi_sndrec_start_play(SoundRecorder.fullName))
    {
        /* To stop the play when interrupt happened before play confirm */
        ReplaceNewScreenHandler(SCR_ID_SNDREC_PLAY, mmi_sndrec_exit_hdlr, NULL);
    }
    else
        mmi_sndrec_exit_hdlr();
}

#define SR_APPEND


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_append
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_append(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 duration = mmi_sndrec_get_duration_ticks();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    mmi_sndrec_set_interrupt_hdlr();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_RECORD);
#ifdef __MMI_SOUND_RECORDER_STYLE_X__
    ShowCategory223Screen(
        STR_ID_SNDREC_APPEND,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_OPTION_SAVE,
        0,
        STR_ID_SNDREC_PAUSE,
        0,
        IMG_ID_SNDREC_RECORDING,
        1,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_stop_record, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_pause, KEY_EVENT_UP);
#else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    ShowCategory223Screen(
        STR_ID_SNDREC_APPEND,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_ID_SNDREC_PAUSE,
        0,
        STR_ID_SNDREC_STOP,
        0,
        IMG_ID_SNDREC_RECORDING,
        1,
        duration,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_sndrec_pause, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_sndrec_stop_record, KEY_EVENT_UP);
#endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
    mmi_sndrec_set_exit_hdlr(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, mmi_sndrec_entry_record);
    mmi_sndrec_set_sidekey_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_append
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_append(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_send_append_req, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_append_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_send_append_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if destination folder exists before record. */
    if (!mmi_sndrec_check_dest_folder(Settings_p->curr_drv))
    {
        return;
    }

    SoundRecorder.isAppend = TRUE;
    ClearInputEventHandler(MMI_DEVICE_ALL);
    mmi_sndrec_get_current_file(SoundRecorder.fileName, SoundRecorder.fullName);
    mmi_sndrec_set_interrupt_hdlr();
    /* if no file ext, use default format */
    if (mmi_sndrec_start_record(SoundRecorder.fullName, Settings_p->format, Settings_p->quality))
    {
        /* To stop the play when interrupt happened before play confirm */
        ReplaceNewScreenHandler(SCR_ID_SNDREC_RECORD, mmi_sndrec_exit_hdlr, NULL);
    }
    else
        mmi_sndrec_exit_hdlr();
}

#define SR_RENAME


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_rename_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_rename_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;
    U16 itemIcons[10];
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SNDREC_RENAME_OPTION, NULL, mmi_sndrec_entry_rename_option, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_RENAME_OPTION);
    SetParentHandler(MENU_ID_SNDREC_RENAME_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(MENU_ID_SNDREC_RENAME_OPTION);
    GetSequenceStringIds(MENU_ID_SNDREC_RENAME_OPTION, nStrItemList);
    for (i = 0; (i < numItems); i++)
    {
        itemIcons[i] = IMG_GLOBAL_L1 + i;
    }
    ShowCategory52Screen(
        STR_ID_SNDREC_RENAME_OPTION,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        itemIcons,
        NULL,
        0,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    UI_character_type fullname[MAX_FULL_NAME_LEN];
    S8 *ptr;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (editorBuffer[0] == 0)
    {
    #ifdef __MMI_SOUND_RECORDER_STYLE_X__
        mmi_sndrec_entry_abort_query();
    #else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
        DisplayPopup((PU8) GetString(STR_FMGR_EMPTY_FILENAME), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
    #endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
        return;
    }

    ptr = mmi_fmgr_skip_space((PS8) editorBuffer);
    len = mmi_ucs2strlen(ptr);
    if (len == 0)
    {
        DisplayPopup((PU8) GetString(STR_FMGR_EMPTY_FILENAME), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
        return;
    }
    if ((len == 1) && (ptr[0] == '.') && (ptr[1] == 0))
    {
        DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
        return;
    }
    while (len > 0)
    {
        len--;
        if ((ptr[len << 1] == '/' && ptr[(len << 1) + 1] == 0) || (ptr[len << 1] == '\\' && ptr[(len << 1) + 1] == 0))
        {
            DisplayPopup((PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
            return;
        }
    }
    kal_wsprintf(fullname,
                 "%c:\\%w%w.%w",
                 Settings_p->curr_drv,
                 FMGR_DEFAULT_FOLDER_AUDIO,
                 ptr,
                 extBuffer);

    result = FS_Rename(SoundRecorder.fullName, fullname);
    if (result < 0)
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
        return;
    }
    else if (!IsScreenPresent(GetCmMarkerScrnID()) && !mmi_sndrec_is_rename_editor_in_call)
    {
        mmi_ucs2cpy((S8*) SoundRecorder.fullName, (S8*) fullname);
        /*copy the fullname to the callback filepath*/
    #ifdef __MMI_SOUND_RECORDER_STYLE_X__
        DeleteUptoScrID(SCR_ID_SNDREC_MAIN);
        mmi_sndrec_entry_main();
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
    #else /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
        /* GoBackToHistory( SCR_FMGR_EXPLORER ); */
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
        /*DeleteUptoScrID(SCR_FMGR_EXPLORER);*/
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME);
        DeleteScreenIfPresent(SCR_FMGR_APP_EMPTY_FOLDER_OPTION);
        DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION);
    #endif /* __MMI_SOUND_RECORDER_STYLE_X__ */ 
		if (mmi_sndrec_sms_record_callback != NULL)
		{	
			mmi_sndrec_sms_record_callback(TRUE, SoundRecorder.fullName);
			mmi_sndrec_sms_record_callback = NULL;
		}
    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
        DeleteNScrId(SCR_ID_SNDREC_RENAME);
        /* GoBackHistory(); */
    }
    mmi_sndrec_is_rename_editor_in_call = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_save(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_entry_save, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_input_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_input_method(void)
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
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#define SR_SETTINGS


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_init_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_init_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Settings_p->curr_drv = (U8)MMI_PUBLIC_DRV;
#ifndef MT6205B
    Settings_p->format = FORMAT_AMR;
    Settings_p->dataRate[FORMAT_AMR] = 700;     /* 700 bytes per second  */
    Settings_p->dataRate[FORMAT_WAV] = 4055;    /* 4055 bytes per second  */
#else /* MT6205B */ 
    Settings_p->format = FORMAT_VM;
#endif /* MT6205B */ 
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    Settings_p->dataRate[FORMAT_AWB] = 900;     /*  900 bytes per second */
#endif 
    Settings_p->dataRate[FORMAT_VM] = 1700;     /* 1700 bytes per second  */
    Settings_p->quality = QUALITY_LOW;
    mmi_sndrec_get_settings();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 storage_highlight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SNDREC_STORAGE, &Settings_p->curr_drv, DS_BYTE, &error);
    ReadValue(NVRAM_SNDREC_FORMAT, &Settings_p->format, DS_BYTE, &error);
    ReadValue(NVRAM_SNDREC_QUALITY, &Settings_p->quality, DS_BYTE, &error);
    /* Restore to default drive if hardware not exists */
#if defined(__MMI_FMGR_APP_STORAGE__)
    if(!mmi_fmgr_is_drive_letter_valid(Settings_p->curr_drv))
#endif
    {
         Settings_p->curr_drv = (U8)MMI_PUBLIC_DRV;
    }

    if (Settings_p->format >= SoundRecorder.num_of_formats)
    {
#ifndef MT6205B
        Settings_p->format = FORMAT_AMR;
#else 
        Settings_p->format = FORMAT_VM;
#endif 
    }
#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)
    if (Settings_p->quality >= NO_OF_QUALITY)
    {
        Settings_p->quality = QUALITY_LOW;
    }
#else
    Settings_p->quality = QUALITY_LOW;
#endif
    /* Find storage highlight item in inline editor */
    mmi_fmgr_get_full_storage_inline_list(Settings_p->curr_drv, NULL, NULL, &storage_highlight);
    selectedStorageIndex = storage_highlight;

    selectedFormatIndex = Settings_p->format;
    selectedAudioqualityindex = Settings_p->quality;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_is_settings_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_sndrec_is_settings_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drv_letter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_get_drive_letter_by_inline_index((U8)selectedStorageIndex, (S8*)&drv_letter);
    if (drv_letter != Settings_p->curr_drv)
    {
        return TRUE;
    }
    
    if (selectedFormatIndex != Settings_p->format)
    {
        return TRUE;
    }
    
    if (selectedAudioqualityindex != Settings_p->quality)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pre_entry_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pre_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_settings();
    mmi_sndrec_entry_inline_edit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_inline_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_inline_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U8 i, j;
    U16 DetailImageList[MAX_SR_SETTINGS_FIELDS];
#if defined(__MMI_FMGR_APP_STORAGE__)
    U32 *inline_list_p;
    U8 no_of_storage;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SNDREC_SETTINGS, mmi_sndrec_exit_inline_edit, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SNDREC_SETTINGS);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_SNDREC_SETTINGS, &inputBufferSize);

    RegisterHighlightHandler(mmi_sndrec_inline_edit_hightlight_hdlr);

    j = 0;

#if defined(__MMI_FMGR_APP_STORAGE__)
    mmi_fmgr_get_full_storage_inline_list(0, &no_of_storage, (U32*)&inline_list_p, NULL);

    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[j], no_of_storage, (U8 **) inline_list_p, &selectedStorageIndex);
    SRTitleStrings[j] = STR_GLOBAL_PREFERRED_STORAGE;
    DetailImageList[j++] = IMG_ID_SNDREC_SETTINGS_STORAGE;
#endif /* #if defined(__MMI_FMGR_APP_STORAGE__) */
    
    for (i = 0; i < SoundRecorder.num_of_formats; i++)
    {
        gFormats[i] = (UI_string_type) GetString(gFormatIds[i]);
    }
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[j], SoundRecorder.num_of_formats, (U8 **) gFormats, &selectedFormatIndex);
    SRTitleStrings[j] = STR_ID_SNDREC_SETTINGS_FORMAT;
    DetailImageList[j++] = IMG_ID_SNDREC_SETTINGS_FORMAT;

#if defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6228) || defined(MT6225) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6223) || defined(MT6223P)
    for (i = 0; i < NO_OF_QUALITY; i++)
    {
        gQuality[i] = (UI_string_type) GetString(gAudioquality[i]);
    }
    SetInlineItemActivation(&wgui_inline_items[j], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(&wgui_inline_items[j], 2, (U8 **) gQuality, &selectedAudioqualityindex);
    SRTitleStrings[j] = STR_ID_SNDREC_SETTING_QUALITY;
    DetailImageList[j++] = IMG_ID_SNDREC_SETTINGS_QUALITY;
#endif
    
    ShowCategory57Screen(
        STR_ID_SNDREC_SETTINGS,
        GetRootTitleIcon(MENU_ID_SNDREC_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        j,
        DetailImageList,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57LeftSoftkeyFunction(mmi_sndrec_settings_pre_save);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_inline_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_exit_inline_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_SNDREC_SETTINGS;
    h.entryFuncPtr = mmi_sndrec_entry_inline_edit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_delete(void)
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
    highlight_fmgr_delete();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_hightlight_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_delete_all(void)
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
 *  mmi_sndrec_hightlight_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_hightlight_settings(void)
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
    SetLeftSoftkeyFunction(mmi_sndrec_pre_entry_settings, KEY_EVENT_UP);

    /* 4 Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* 5 Register function for right  key */
    SetKeyHandler(mmi_sndrec_pre_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* 6 Register function for left  key */
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_inline_edit_hightlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_inline_edit_hightlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8) GetString(SRTitleStrings[index]));
    /* MTK Leo add 20040419 */
    draw_title();
    /* MTK Leo end */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_sndrec_settings_pre_save);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_settings_pre_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_settings_pre_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL drive_not_found = FALSE;
    FS_HANDLE file_handle;
    S8 select_drv_letter;
    UI_character_type dir_drv[8];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check does the selected storage drive exist */
    mmi_fmgr_get_drive_letter_by_inline_index((U8)selectedStorageIndex, &select_drv_letter);
    mmi_sndrec_get_full_path(select_drv_letter);

    kal_wsprintf(
        (kal_wchar*) dir_drv,
        "%c:\\",
        (S16)MMI_CARD_DRV);

    file_handle = FS_Open((kal_wchar*)dir_drv, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
            drive_not_found = TRUE;
    }
    else
    {
        FS_Close(file_handle);
    }

    if (FS_GetDevStatus(select_drv_letter, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {   
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_NO_CARD), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);      
    }
    else
    {
        if (mmi_sndrec_is_settings_changed())
        {
            mmi_sndrec_entry_settings_save_query();
        }
        else
        {
            GoBackHistory();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_write_settings_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_write_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S8 select_drv_letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_get_drive_letter_by_inline_index((U8)selectedStorageIndex, &select_drv_letter);
    Settings_p->curr_drv = (U8) select_drv_letter;
    Settings_p->format = (U8) selectedFormatIndex;
    Settings_p->quality = (U8)selectedAudioqualityindex;
    WriteValue(NVRAM_SNDREC_STORAGE, &Settings_p->curr_drv, DS_BYTE, &error);
    WriteValue(NVRAM_SNDREC_FORMAT, &Settings_p->format, DS_BYTE, &error);
    WriteValue(NVRAM_SNDREC_QUALITY, &Settings_p->quality, DS_BYTE, &error);
    DeleteNScrId(SCR_FMGR_EXPLORER);

    mmi_sndrec_entry_main();
    /* mmi_sndrec_go_back_2_history(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_remain_time_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_sndrec_get_remain_time_string(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[3];
    S32 sec, data_rate;
    S8 select_drv_letter;
    U16 temp[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(dir, 0, 6);
    data_rate = mmi_sndrec_get_datarate();
    mmi_fmgr_get_drive_letter_by_inline_index((U8)selectedStorageIndex, &select_drv_letter);
    mmi_sndrec_get_full_path(select_drv_letter);
    kal_mem_cpy(dir, FileList_p->storagePath, 4);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if ((result > 0) && (result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE)))
    {
        sec =
            (disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) /
            data_rate;
        kal_wsprintf(temp, "%d:%2d:%2d  ", sec / 3600, (sec % 3600) / 60, sec % 60);
        mmi_ucs2cpy((S8*) string, (S8*) GetString(STR_ID_SNDREC_AVAILABLE));
        mmi_ucs2cat((S8*) string, (S8*) L" ");
	    mmi_ucs2cat((S8*) string, (S8*) temp);
        return TRUE;
    }
    else
    {
        mmi_ucs2cpy((S8*) string, (S8*) GetString(STR_ID_SNDREC_NO_CARD));
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_settings_save_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_settings_save_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_remain_time_string(strBuffer);
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        strBuffer,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_sndrec_write_settings_to_nvram, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_exit_settings_save_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_exit_settings_save_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#define SR_VOLUME


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_save_speech_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_save_speech_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SaveSpeechVolume((U8) SoundRecorder.volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_increase_speech_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_increase_speech_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.volume < MAX_VOL_LEVEL - 1)
    {
        SoundRecorder.volume++;
        mmi_sndrec_set_speech_volume(SoundRecorder.volume);
        StartTimer(KEY_VOL_TIMER_ID, 2000, mmi_sndrec_save_speech_volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_decrease_speech_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_decrease_speech_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.volume > 0)
    {
        SoundRecorder.volume--;
        mmi_sndrec_set_speech_volume(SoundRecorder.volume);
        StartTimer(KEY_VOL_TIMER_ID, 2000, mmi_sndrec_save_speech_volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_increase_media_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_increase_media_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.volume < MAX_VOL_LEVEL - 1)
    {
        SoundRecorder.volume++;
        mmi_sndrec_set_media_volume(SoundRecorder.volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_decrease_media_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_decrease_media_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.volume > 0)
    {
        SoundRecorder.volume--;
        mmi_sndrec_set_media_volume(SoundRecorder.volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_current_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_set_current_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_set_media_volume(SoundRecorder.volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_set_sidekey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_set_sidekey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.inCall)
    {
        SoundRecorder.volume = GetModeSpeechVolume();
        SetKeyHandler(mmi_sndrec_increase_speech_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_sndrec_decrease_speech_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
    else
    {
        SoundRecorder.volume = GetRingVolumeLevel();
        SetKeyHandler(mmi_sndrec_increase_media_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_sndrec_decrease_media_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    }
}

#define SR_MISC


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_error_hdlr(S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case MDI_AUDIO_SUCCESS:
            GoBackHistory();
            break;
    #ifdef __DRM_SUPPORT__
        case DRM_NOT_PERMIT_TO_PLAY:
        case DRM_NOT_PERMIT_TO_APPEND:
        case MDI_AUDIO_DRM_PROHIBIT:
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE);
            break;
    #endif /* __DRM_SUPPORT__ */ 
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_ERROR), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_BAD_FORMAT:
        case MDI_AUDIO_UNSUPPORTED_TYPE:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_BAD_FORMAT), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_INVALID_FORMAT:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_INVALID_FORMAT), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_BUSY:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_DEVICE_BUSY), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_DISC_FULL:
        case MDI_AUDIO_NO_SPACE:
            //         DisplayPopup((PU8)GetString(STR_ID_SNDREC_DISC_FULL) ,IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            // use file manager disk full string id for unified error message notification
            DisplayPopup((PU8) GetString(FMGR_FS_DISK_FULL_TEXT), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_OPEN_FILE_ERROR), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_NO_DISC:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_NO_CARD), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        case MDI_AUDIO_WRITE_PROTECTION:
            DisplayPopup(
                (PU8) GetString(STR_ID_SNDREC_WRITE_PROTECTION_ERROR),
                IMG_GLOBAL_ERROR,
                1,
                1000,
                ERROR_TONE);
            break;
        case MDI_AUDIO_END_OF_FILE:
        case MDI_AUDIO_TERMINATED:
            GoBackHistory();
            break;
        case MDI_AUDIO_DRM_TIMEOUT:
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE);
            break;
	case MDI_AUDIO_UNSUPPORTED_FREQ:
            DisplayPopup((PU8) GetString(STR_ID_SNDREC_UNSUPPORTED_FREQ), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
            break;
        default:
            GoBackHistory();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_delete_name_editor_history_nodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_delete_name_editor_history_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_SNDREC_RENAME) == TRUE)
    {
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME);
        DeleteScreenIfPresent(SCR_ID_SNDREC_RENAME_OPTION);
        DeleteScreenIfPresent(SCR_INPUT_METHOD_LIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_go_back_2_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_go_back_2_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}

#define SR_AUTO_RECORD
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_auto_record_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_auto_record_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
#ifdef __MTK_TARGET__
    kal_char debug_msg[32];
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ReadValue(NVRAM_AUTO_VM_SETTING_VM_SUPPORT, &SoundRecorder.vm_support, DS_BYTE, &error);
	/* The default setting should be off */
	if(SoundRecorder.vm_support == 0xff)
	{
		SoundRecorder.vm_support = 0;
		WriteValue(NVRAM_AUTO_VM_SETTING_VM_SUPPORT, &SoundRecorder.vm_support, DS_BYTE, &error);
	}

    ReadValue(NVRAM_AUTO_VM_SETTING_AUTO_VM, &SoundRecorder.auto_record, DS_BYTE, &error);
	/* The default setting should be off */
	if(SoundRecorder.auto_record == 0xff)
	{
		SoundRecorder.auto_record = 0;
		WriteValue(NVRAM_AUTO_VM_SETTING_AUTO_VM, &SoundRecorder.auto_record, DS_BYTE, &error);
	}

#ifdef __MTK_TARGET__
    sprintf(debug_msg, "Auto Record = [%d]", SoundRecorder.auto_record);
    kal_print(debug_msg);
#endif    

#ifdef MT6205B
    SoundRecorder.num_of_formats = NO_OF_FORMAT;     /* vm is explicit if this is our only one format */
#else
    if(SoundRecorder.vm_support) /* vm is not explicit */    
    {
        SoundRecorder.num_of_formats = NO_OF_FORMAT;
    }
    else
    {
        SoundRecorder.num_of_formats = NO_OF_FORMAT - 1;
    }
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_auto_record_change_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_auto_record_change_setting(S32 vm_support, S32 auto_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    kal_char debug_msg[32];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(vm_support >= 0)
    {
        SoundRecorder.vm_support = (U8)vm_support;

    #ifdef MT6205B
        SoundRecorder.num_of_formats = NO_OF_FORMAT;     /* vm is explicit if this is our only one format */
    #else
        if(SoundRecorder.vm_support) /* vm is not explicit */    
        {
            SoundRecorder.num_of_formats = NO_OF_FORMAT;
        }
        else
        {
            SoundRecorder.num_of_formats = NO_OF_FORMAT - 1;

            /* Disable VM, restore format to amr */
            if(Settings_p->format == FORMAT_VM)
            {
                Settings_p->format = FORMAT_AMR;
            }
        }
    #endif /* MT6205B */
    }

    if(auto_record >= 0)
    {
        SoundRecorder.auto_record = (U8)auto_record;
    }

#ifdef __MTK_TARGET__
    sprintf(debug_msg, "Auto Record = [%d]", SoundRecorder.auto_record);
    kal_print(debug_msg);
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_auto_record_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_auto_record_event_hdlr(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    kal_char debug_msg[64];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifdef __MTK_TARGET__
        sprintf(debug_msg, "Stop Auto Record... Result = [%d], State = [%d]", result, SoundRecorder.state);
        kal_print(debug_msg);
    #endif

    if (SoundRecorder.state == STATE_RECORD)
    {
        SoundRecorder.state = STATE_IDLE;
        if (result == MDI_AUDIO_TERMINATED)
        {
        }
        else if (result == MDI_AUDIO_DISC_FULL)
        {
            DisplayPopup((U8*) GetString((U16) mmi_sndrec_get_res_string((U8) result)),
                IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE_IN_CALL);
        }
        else
        {
            DisplayPopup((U8*) GetString((U16) mmi_sndrec_get_res_string((U8) result)),
                IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE_IN_CALL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_auto_record_switch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_auto_record_switch(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id, MMI_BOOL speech_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_format;
    mdi_result result;
#ifdef __MTK_TARGET__
    kal_char debug_msg[64];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(SoundRecorder.auto_record)
    {
        if((app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP) && (SoundRecorder.state == STATE_RECORD))
        {
            SoundRecorder.auto_record_count++;
        }

        /* Speech On */
        if(speech_on && (SoundRecorder.state == STATE_IDLE))
        {
        #ifdef __MTK_TARGET__
            sprintf(debug_msg, "Begin Auto Record... Storage = [%d], Format = [%d]", Settings_p->curr_drv, Settings_p->format);
            kal_print(debug_msg);
        #endif

        #ifdef __USB_IN_NORMAL_MODE__
            /* check is in mass storage mode */
            if (mmi_usb_is_in_mass_storage_mode())
            {
                /* phone drive is exported, cant use this app */
                mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
                return;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */ 
        
            /* Check if destination folder exists before record. */
            if (!mmi_sndrec_check_dest_folder(Settings_p->curr_drv))
            {
                return;
            }

            SoundRecorder.inCall = TRUE;
            /* Use special format to record voip call */
            if(app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP)
            {
                U8 temp_format = SoundRecorder.Settings.format;

                /* Modify global variable to get correct file extension in this function */
                SoundRecorder.Settings.format = FORMAT_EVL;
                mmi_sndrec_get_new_file(SoundRecorder.fileName, SoundRecorder.fullName);
                SoundRecorder.Settings.format = temp_format;
                
                file_format = mmi_sndrec_get_record_format(FORMAT_EVL);                
            }
            else
            {
                SoundRecorder.need_file_prefix = MMI_TRUE;
                mmi_sndrec_get_new_file(SoundRecorder.fileName, SoundRecorder.fullName);
                SoundRecorder.need_file_prefix = MMI_FALSE;
                /*add to distingush sim one or sim two auto record*/

                file_format = 
                    mmi_sndrec_get_record_format(
                        (U8) (
                        #ifndef MT6205B
                        #if !defined(__MMI_DEDI_AMR_REC__)
                            (SoundRecorder.inCall && SoundRecorder.Settings.format != (U8)FORMAT_VM) ? FORMAT_WAV :
                        #elif defined( AMRWB_ENCODE ) && defined( AMRWB_DECODE )
                            (SoundRecorder.inCall && SoundRecorder.Settings.format == (U8)FORMAT_AWB) ? FORMAT_AMR :
                        #endif 
                        #endif /* MT6205B */ 
                            SoundRecorder.Settings.format));
            }
            result = mdi_audio_start_record(SoundRecorder.fullName, file_format, SoundRecorder.Settings.quality, NULL, mmi_sndrec_auto_record_event_hdlr);

            if (result == MDI_AUDIO_SUCCESS)
            {
                SoundRecorder.state = STATE_RECORD;
                SoundRecorder.auto_record_count = 1; /* First request for audio record */
            }
            else
            {
                DisplayPopup((U8*) GetString((U16) mmi_sndrec_get_res_string((U8) result)),
                    IMG_GLOBAL_ERROR, 0, 2000, ERROR_TONE_IN_CALL);
            }
        }
        else if(!speech_on)/* Speech Off */
        {
            if(--SoundRecorder.auto_record_count == 0)
        {
            SoundRecorder.inCall = FALSE;
            
            if(SoundRecorder.state == STATE_RECORD)
            {
                mdi_audio_stop_record();
            }
        }
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_auto_record_switch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_auto_record_switch_sim2(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id, MMI_BOOL speech_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SoundRecorder.is_sim_two = MMI_TRUE;
    kal_prompt_trace(MOD_MMI,"mmi_sndrec_auto_record_switch_sim2, %d", SoundRecorder.is_sim_two);
    mmi_sndrec_auto_record_switch(app_id, speech_on);
    SoundRecorder.is_sim_two = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_auto_record_is_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sndrec_auto_record_is_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SoundRecorder.auto_record && SoundRecorder.state != STATE_IDLE)
    {
        DisplayPopup((U8*) GetString(STR_ID_SNDREC_AUTO_RECORD_ON), IMG_GLOBAL_WARNING, 0, UI_POPUP_NOTIFYDURATION_TIME, WARNING_TONE);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_entry_record_in_sms
 * DESCRIPTION
 *  this function is used for record in sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_entry_record_in_sms(U16* file_path, U32 max_file_size, void(*callback_func)(BOOL result, U16* filepath))
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_wchar *ptr = file_path;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check is in mass storage mode */
    if (mmi_sndrec_check_usb_mode())
    {
        return;
    }
	if (ptr == NULL)
	{
		if (!mmi_sndrec_check_dest_folder(Settings_p->curr_drv))
		{
			return;
		}
		mmi_sndrec_get_new_file(SoundRecorder.fileName, SoundRecorder.fullName);
	}
	else
	{
		kal_wsprintf(
        (kal_wchar*) SoundRecorder.fullName,
        "%w",(const kal_wchar*)ptr);
	}
	ClearInputEventHandler(MMI_DEVICE_ALL);
	if (mmi_sndrec_start_record_with_limit(SoundRecorder.fullName,
		(U8) (SoundRecorder.Settings.format), SoundRecorder.Settings.quality, max_file_size * 1024, 0))
	{
		mmi_sndrec_set_interrupt_hdlr();
		mmi_sndrec_sms_record_callback = callback_func;
	}
	else
		mmi_sndrec_exit_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_datarate
 * DESCRIPTION
 *  this function is used for record in sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_sndrec_get_datarate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (selectedAudioqualityindex == QUALITY_LOW)
    {
        return Settings_p->dataRate[selectedFormatIndex];
    }
    else
    {
        switch (selectedFormatIndex)
        {
        #ifndef MT6205B
            case FORMAT_AMR:
                return AMR_HIGH_BIT_RATE;
                break;
            case FORMAT_WAV:
                return WAV_HIGH_BIT_RATE;
                break;
        #endif /* MT6205B */ 
        #if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)    
            case FORMAT_AWB:
                return AWB_HIGH_BIT_RATE;
                break;
        #endif    
            default:
                return VM_HIGH_BIT_RATE;
                break;
        }
    }
    
}
#endif /* __MMI_SOUND_RECORDER__ */ 

