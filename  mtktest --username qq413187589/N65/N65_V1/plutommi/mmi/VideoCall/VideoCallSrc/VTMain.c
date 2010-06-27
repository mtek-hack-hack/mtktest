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
 *  VTMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI VT main file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_VIDEO_TELEPHONY__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DateTimeGprot.h"
#include "csmcc_common_enums.h"

#include "CallStructureManagementProtEx.h"
#include "CommonStubsProtEx.h"
#include "CallManagementStructEx.h"

#ifdef MMS_SUPPORT
#include "wapadp.h"
#endif /* MMS_SUPPORT */

#include "SMSAPI.h"

#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMResDef.h"

#include "VTGProt.h"
#include "VTProt.h"
#include "VTResDef.h"

#include "VTCallScrGProt.h"

mmi_vt_cntx_struct g_mmi_vt_cntx;
mmi_vt_cntx_struct *g_vt_p = &g_mmi_vt_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_init
 * DESCRIPTION
 *  Initialize VT app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_init_highlight_handler();
    mmi_vt_init_setting();
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_init_highlight_handler
 * DESCRIPTION
 *  Initialize highlight handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Video call application */
    SetHiliteHandler(MENU_ID_VT_MAIN, mmi_vt_highlight_main);
    
    /* set the incall option menu highlight handlers */
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_MAKE_VIDEO_CALL, mmi_vt_highlight_incall_opt_make_video_call);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_START_CAMERA, mmi_vt_highlight_incall_opt_start_camera);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_STOP_CAMERA, mmi_vt_highlight_incall_opt_stop_camera);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_MUTE_MIC, mmi_vt_highlight_incall_opt_mute_mic);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_UNMUTE_MIC, mmi_vt_highlight_incall_opt_unmute_mic);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_MUTE_SPEAKER, mmi_vt_highlight_incall_opt_mute_speaker);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_UNMUTE_SPEAKER, mmi_vt_highlight_incall_opt_unmute_speaker);    
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_SWITCH_PIC, mmi_vt_highlight_incall_opt_switch_pic);    
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_HIDE_SMALL_PIC, mmi_vt_highlight_incall_opt_hide_small_pic);    
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_UNHIDE_SMALL_PIC, mmi_vt_highlight_incall_opt_unhide_small_pic);  
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ALT_PIC, mmi_vt_highlight_incall_opt_alt_pic);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH, mmi_vt_highlight_incall_opt_switch_audio_path);		
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ADVANCE, mmi_vt_highlight_incall_opt_advanced);      
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_SETTING, mmi_vt_highlight_incall_opt_setting);

    /* set the setting menu highlight handlers */
    SetHiliteHandler(MENU_ID_VT_SETTING_ANSWER_MODE, mmi_vt_highlight_setting_answer_mode);
    SetHiliteHandler(MENU_ID_VT_SETTING_DIAL_MODE, mmi_vt_highlight_setting_dial_mode);
    SetHiliteHandler(MENU_ID_VT_SETTING_INCALL_IMAGE, mmi_vt_highlight_setting_alt_incall_pic);
    SetHiliteHandler(MENU_ID_VT_SETTING_AUDIO_OPT, mmi_vt_highlight_setting_audio_option);
    SetHintHandler(MENU_ID_VT_SETTING_INCALL_IMAGE, mmi_vt_hint_setting_alt_incall_pic);

    /* set the incall file setting menu highlight handlers */
    SetHiliteHandler(MENU_ID_VT_SETTING_INCALL_IMAGE_DEFAULT, mmi_vt_highlight_setting_incall_image_default);
    SetHiliteHandler(MENU_ID_VT_SETTING_INCALL_IMAGE_USER_DEFINE, mmi_vt_highlight_setting_incall_image_user_define);

    /* set the advance menu highlight handlers */
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_BRIGHTNESS, mmi_vt_highlight_advance_brightness);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, mmi_vt_highlight_advance_video_quality);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_RECORD_AUDIO, mmi_vt_highlight_advance_record_audio);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_SAVE_PIC, mmi_vt_highlight_advance_save_pic);
    SetHiliteHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_MIRROR_IMAGE, mmi_vt_highlight_advance_mirror_image);
    SetHintHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_BRIGHTNESS, mmi_vt_hint_advance_brightness);
    SetHintHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, mmi_vt_hint_advance_video_quality);
    SetHintHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_MIRROR_IMAGE, mmi_vt_hint_advance_mirror_image);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_init_setting
 * DESCRIPTION
 *  Init vt setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_init_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    S16 errorCode = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* answer mode */
    ReadValue(NVRAM_VT_ANSWER_MODE, &index, DS_BYTE, &errorCode);
    
    if (index >= MMI_VT_ANSWER_MODE_END_OF_ENUM)
    {
        index = MMI_VT_ANSWER_MODE_PROMPT;
        WriteValue(NVRAM_VT_ANSWER_MODE, &index, DS_BYTE, &errorCode);
    }
    g_vt_p->setting.answer_mode = index;

    /* dial mode */
    ReadValue(NVRAM_VT_DIAL_MODE, &index, DS_BYTE, &errorCode);
    
    if (index >= MMI_VT_DIAL_MODE_END_OF_ENUM)
    {
        index = MMI_VT_DIAL_MODE_START_CAMERA;
        WriteValue(NVRAM_VT_DIAL_MODE, &index, DS_BYTE, &errorCode);
    }
    g_vt_p->setting.dial_mode = index;

    /* audio option */
    ReadValue(NVRAM_VT_AUDIO_OPT_MIC, &index, DS_BYTE, &errorCode);
    if (index >= 1)
    {
        index = 0;
        WriteValue(NVRAM_VT_AUDIO_OPT_MIC, &index, DS_BYTE, &errorCode);
    }
    g_vt_p->setting.is_mic_off = index;

    ReadValue(NVRAM_VT_AUDIO_OPT_SPEAKER, &index, DS_BYTE, &errorCode);
    if (index >= 1)
    {
        index = 0;
        WriteValue(NVRAM_VT_AUDIO_OPT_SPEAKER, &index, DS_BYTE, &errorCode);
    }
    g_vt_p->setting.is_speaker_off = index;

    /* incall image */
    memset(g_vt_p->setting.incall_image_file_path, 0, sizeof(g_vt_p->setting.incall_image_file_path));
    ReadRecord(
        NVRAM_EF_VT_SETTING_LID,
        1,
        (void*)&g_vt_p->setting.incall_image_file_path,
        NVRAM_EF_VT_SETTING_SIZE,
        &errorCode);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_main
 * DESCRIPTION
 *  Funtion is called when video call main menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_in_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_vt_entry_in_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_make_video_call
 * DESCRIPTION
 *  Funtion is called when make video call menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_make_video_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_vt_p->mo_info.dial_pad_buffer, 0, sizeof(g_vt_p->mo_info.dial_pad_buffer));
    SetLeftSoftkeyFunction(mmi_vt_entry_dialer_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vt_entry_dialer_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_start_camera
 * DESCRIPTION
 *  Funtion is called when start camera menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_start_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_start_camera, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_stop_camera
 * DESCRIPTION
 *  Funtion is called when stop camera menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_stop_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_stop_camera, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_mute_mic
 * DESCRIPTION
 *  Funtion is called when mute mic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_mute_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_mute_mic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_unmute_mic
 * DESCRIPTION
 *  Funtion is called when unmute mic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_unmute_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_unmute_mic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_mute_speaker
 * DESCRIPTION
 *  Funtion is called when mute speaker menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_mute_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_mute_speaker, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_unmute_speaker
 * DESCRIPTION
 *  Funtion is called when unmute speaker menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_unmute_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_unmute_speaker, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_switch_pic
 * DESCRIPTION
 *  Funtion is called when switch pic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_switch_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_switch_pic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_hide_small_pic
 * DESCRIPTION
 *  Funtion is called when hide small pic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_hide_small_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_hide_small_pic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_unhide_small_pic
 * DESCRIPTION
 *  Funtion is called when unhide small pic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_unhide_small_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_incall_opt_unhide_small_pic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_alt_pic
 * DESCRIPTION
 *  Funtion is called when alternative incall pic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_alt_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_alt_incall_pic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_switch_audio_path
 * DESCRIPTION
 *  Funtion is called when switch audio path menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_switch_audio_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_bt_set_audio_path, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_advanced
 * DESCRIPTION
 *  Funtion is called when advanced menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_advanced(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_advanced, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_incall_opt_setting
 * DESCRIPTION
 *  Funtion is called when setting menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_incall_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_setting, KEY_EVENT_UP);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_handle_incall_option
 * DESCRIPTION
 *  Handle incall option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_handle_incall_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_app_total_call(MMI_UCM_VIDEO_CALL_TYPE) > 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_MAKE_VIDEO_CALL);
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_SETTING);

    #if defined(__MMI_BT_SUPPORT__)
        if (mmi_bt_is_hs_connected() == FALSE)
        {
            PRINT_INFORMATION("\n[mmi_vt_handle_incall_option] BT Not Connect\n");
            mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH);
        }        
        else if (g_vt_p->incall_screen.is_speaker_on == FALSE)
        {
            PRINT_INFORMATION("\n[mmi_vt_handle_incall_option] Speech is Off\n");
            mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH);
        }
        else
        {
            PRINT_INFORMATION("\n[mmi_vt_handle_incall_option] unhide switch audio path \n");
            mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH);
        }
    #else /* defined(__MMI_BT_SUPPORT__) */
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH);
    #endif /* defined(__MMI_BT_SUPPORT__) */
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_MAKE_VIDEO_CALL);
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_SETTING);
        
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_SWITCH_AUDIO_PATH);
    }

    
    if (mmi_vt_get_camera_status() == TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_START_CAMERA);
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_STOP_CAMERA);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_START_CAMERA);
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_STOP_CAMERA);
    }

    if (mmi_vt_get_mic_status() == TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_UNMUTE_MIC);
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_MUTE_MIC);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_UNMUTE_MIC);
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_MUTE_MIC);
    }

    if (mmi_vt_get_speaker_status() == TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_UNMUTE_SPEAKER);
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_MUTE_SPEAKER);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_UNMUTE_SPEAKER);
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_MUTE_SPEAKER);
    }    

    if (mmi_vt_get_hide_small_pic_status() == TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_HIDE_SMALL_PIC);
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_UNHIDE_SMALL_PIC);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_HIDE_SMALL_PIC);
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_UNHIDE_SMALL_PIC);
    }

    if (mmi_ucm_app_total_call(MMI_UCM_VIDEO_CALL_TYPE) > 0)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VT_INCALL_OPT_ALT_PIC);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VT_INCALL_OPT_ALT_PIC);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_incall_option
 * DESCRIPTION
 *  Shows the incall option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_incall_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_VT_INCALL_OPTION, NULL, mmi_vt_entry_incall_option, NULL);
    PRINT_INFORMATION("\n[mmi_vt_entry_incall_option] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_INCALL_OPTION);

    mmi_vt_handle_incall_option();

    numItems = GetNumOfChild_Ext(MENU_ID_VT_INCALL_OPT);
    GetSequenceStringIds_Ext(MENU_ID_VT_INCALL_OPT, nStrItemList);    
    SetParentHandler(MENU_ID_VT_INCALL_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_dialer_screen
 * DESCRIPTION
 *  vt dialer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_dialer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputStr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_DIALER, NULL, mmi_vt_entry_dialer_screen, NULL);    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_DIALER);
    inputStr = GetCurrInputBuffer(SCR_ID_VT_DIALER);

    ShowCategory16Screen(
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_vt_p->mo_info.dial_pad_buffer,
        (MMI_VT_DTMF_LEN + 1),
        guiBuffer);

    wgui_save_key_handlers();
    
    SetLeftSoftkeyFunction(mmi_vt_dialer_make_vt, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP); 

    SetKeyHandler(mmi_vt_dialer_make_vt, KEY_SEND, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_dialer_make_vt
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_dialer_make_vt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_entry_dummy();
    DeleteScreenIfPresent(SCR_ID_VT_DIALER);                

    mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) g_vt_p->mo_info.dial_pad_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_start_camera
 * DESCRIPTION
 *  turn on camera and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_start_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_camera_status(MMI_TRUE);

    /* If the local image displays in small region, unhide small image */
    if (mmi_vt_get_pic_switch_status() == MMI_FALSE)
    {
        mmi_vt_set_hide_small_pic_status(MMI_FALSE);
    }
    
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_stop_camera
 * DESCRIPTION
 *  turn off camera and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_stop_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_camera_status(MMI_FALSE);
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_mute_mic
 * DESCRIPTION
 *  mute mic and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_mute_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_mic_status(MMI_FALSE);
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_unmute_mic
 * DESCRIPTION
 *  unmute mic and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_unmute_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_mic_status(MMI_TRUE);
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_mute_speaker
 * DESCRIPTION
 *  mute speaker and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_mute_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_speaker_status(MMI_FALSE);
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_unmute_speaker
 * DESCRIPTION
 *  unmute speaker and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_unmute_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_speaker_status(MMI_TRUE);
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_switch_pic
 * DESCRIPTION
 *  switch pic and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_switch_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vt_get_pic_switch_status() == MMI_TRUE)
    {
        mmi_vt_set_pic_switch_status(MMI_FALSE);
    }
    else
    {
        mmi_vt_set_pic_switch_status(MMI_TRUE);
    }
    
    GoBackToHistory(SCR_ID_VT_INCALL);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_hide_small_pic
 * DESCRIPTION
 *  hide small picture and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_hide_small_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_hide_small_pic_status(MMI_TRUE);

    /* If the local image displays in small region, turn off camera */
    if (mmi_vt_get_pic_switch_status() == MMI_FALSE)
    {
        mmi_vt_set_camera_status(MMI_FALSE);
    }
    
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_incall_opt_unhide_small_pic
 * DESCRIPTION
 *  Unhide small picture and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_incall_opt_unhide_small_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_hide_small_pic_status(MMI_FALSE);
    GoBackToHistory(SCR_ID_VT_INCALL);
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_advance_brightness
 * DESCRIPTION
 *  Funtion is called when brightness menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_advance_brightness(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_brightness, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_advance_video_quality
 * DESCRIPTION
 *  Funtion is called when video quality menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_advance_video_quality(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_video_quality, KEY_EVENT_UP);
    return;
}

/* TODO */
void mmi_vt_highlight_advance_record_audio(void){;}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_advance_save_pic
 * DESCRIPTION
 *  Funtion is called when save picture menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_advance_save_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_save_pic, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_advance_mirror_image
 * DESCRIPTION
 *  Funtion is called when mirror menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_advance_mirror_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_mirror_image, KEY_EVENT_UP);
    return;
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_vt_hint_advance_brightness
 * DESCRIPTION
 *  To construct hint popup for brightness setting
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_hint_advance_brightness(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    sprintf((S8*) value, "%d", g_vt_p->incall_screen.ev);
    mmi_asc_to_ucs2((PS8) hintData[index], (PS8) value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_hint_advance_video_quality
 * DESCRIPTION
 *  To construct hint popup for video quality
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_hint_advance_video_quality(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    switch (g_vt_p->incall_screen.video_quality)
    {
        case MMI_VT_VIDEO_QUALITY_SMOOTH:
        {
            mmi_ucs2cpy((PS8) hintData[index], (S8*) GetString(STR_ID_VT_SMOOTH));
        }
        break;

        case MMI_VT_VIDEO_QUALITY_NORMAL:
        {
            mmi_ucs2cpy((PS8) hintData[index], (S8*) GetString(STR_ID_VT_NORMAL));
        }
        break;        

        case MMI_VT_VIDEO_QUALITY_SHARP:
        {
            mmi_ucs2cpy((PS8) hintData[index], (S8*) GetString(STR_ID_VT_SHARP));
        }
        break;        

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_hint_advance_mirror_image
 * DESCRIPTION
 *  To construct hint popup for video quality
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_hint_advance_mirror_image(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (mmi_vt_get_mirror_status() == MMI_TRUE)
    {
        mmi_ucs2cpy((PS8) hintData[index], (S8*) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (S8*) GetString(STR_GLOBAL_OFF));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_advance_get_hilite_index
 * DESCRIPTION
 *  Get current highlight index
 * PARAMETERS
 *  nIndex      [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_advance_get_hilite_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->incall_screen.curr_hilite_index = (U16)index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_advanced
 * DESCRIPTION
 *  Shows the advance screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_advanced(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *popUpList[MAX_SUB_MENUS];
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_VT_ADVANCE, NULL, mmi_vt_entry_advanced, NULL);
    PRINT_INFORMATION("\n[mmi_vt_entry_advanced] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_ADVANCE);

    numItems = GetNumOfChild_Ext(MENU_ID_VT_INCALL_OPT_ADVANCE);
    GetSequenceStringIds_Ext(MENU_ID_VT_INCALL_OPT_ADVANCE, nStrItemList);    
    SetParentHandler(MENU_ID_VT_INCALL_OPT_ADVANCE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_ID_VT_INCALL_OPT_ADVANCE, popUpList);

    ShowCategory52Screen(
        STR_ID_VT_ADVANCED,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_brightness
 * DESCRIPTION
 *  Shows the brightness screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_brightness(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_incall_screen_mode(MMI_VT_INCALL_SCREEN_MODE_BRIGHTNESS);

    if (IsScreenPresent(SCR_ID_VT_INCALL))
    {
        GoBackToHistory(SCR_ID_VT_INCALL);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_video_quality
 * DESCRIPTION
 *  Entry video quality screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_video_quality(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];
    S32 hiliteitem = 0;    
    U16 nNumofItem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_VIDEO_QUALITY, NULL, mmi_vt_entry_video_quality, NULL);

    PRINT_INFORMATION("\n[mmi_vt_entry_video_quality] \n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_VIDEO_QUALITY);
    
    nNumofItem = GetNumOfChild_Ext(MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY);
    GetSequenceStringIds_Ext(MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, nStrItemList);
    SetParentHandler(MENU_ID_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY);

    if (guiBuffer != NULL)
    {
        hiliteitem = (S32)g_vt_p->incall_screen.curr_hilite_index;
    }
    else
    {
        hiliteitem = (S32)mmi_vt_get_video_quality_status();
    }
    
    RegisterHighlightHandler(mmi_vt_advance_get_hilite_index);

    ShowCategory11Screen(
        STR_ID_VT_VIDEO_QUALITY,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vt_video_quality_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_video_quality_done
 * DESCRIPTION
 *  Set video quality
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_video_quality_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_video_quality_done] index = %d \n", g_vt_p->incall_screen.curr_hilite_index);

    mmi_vt_set_video_quality_status((mmi_vt_video_quality_enum)g_vt_p->incall_screen.curr_hilite_index);

    if (IsScreenPresent(SCR_ID_VT_INCALL))
    {
        GoBackToHistory(SCR_ID_VT_INCALL);
    }
    else
    {
        MMI_ASSERT(0);
    }
}

        
/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_save_pic    
 * DESCRIPTION
 *  Shows the save pic screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_save_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_incall_screen_mode(MMI_VT_INCALL_SCREEN_MODE_SNAPSHOT);

    if (IsScreenPresent(SCR_ID_VT_INCALL))
    {
        GoBackToHistory(SCR_ID_VT_INCALL);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_mirror_image
 * DESCRIPTION
 *  Mirror image and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_mirror_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vt_get_mirror_status() == MMI_TRUE)
    {
        mmi_vt_set_mirror_status(MMI_FALSE);
    }
    else
    {
        mmi_vt_set_mirror_status(MMI_TRUE);
    }
    
    GoBackToHistory(SCR_ID_VT_INCALL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_setting_answer_mode
 * DESCRIPTION
 *  Funtion is called when answer mode menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_setting_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_answer_mode, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_setting_dial_mode
 * DESCRIPTION
 *  Funtion is called when dial mode menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_setting_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_dial_mode, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_setting_alt_incall_pic
 * DESCRIPTION
 *  Funtion is called when alternative incall pic menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_setting_alt_incall_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_alt_incall_pic, KEY_EVENT_UP);
    return;
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_vt_hint_setting_alt_incall_pic
 * DESCRIPTION
 *  To construct hint popup for incall image setting
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_hint_setting_alt_incall_pic(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */
    memset((PS8) hintData[index], 0, sizeof(hintData[index]));

    if (mmi_ucs2strlen((S8*)g_vt_p->setting.incall_image_file_path) == 0)
    {
        mmi_ucs2ncpy((S8*)hintData[index], (S8*) GetString(STR_ID_VT_DEFAULT), (MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH) - 1);
    }
    else
    {
        mmi_ucs2ncpy((S8*)hintData[index], 
                    (S8*) mmi_vt_get_file_name((U16*)g_vt_p->setting.incall_image_file_path), 
                    (MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH) - 1);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_setting_audio_option
 * DESCRIPTION
 *  Funtion is called when audio option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_setting_audio_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->setting.audio_opt[MMI_VT_AUDIO_OPTION_MIC_OFF] = g_vt_p->setting.is_mic_off;
    g_vt_p->setting.audio_opt[MMI_VT_AUDIO_OPTION_SPEAKER_OFF] = g_vt_p->setting.is_speaker_off;
    SetLeftSoftkeyFunction(mmi_vt_entry_audio_option, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_setting
 * DESCRIPTION
 *  Shows the setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *popUpList[MAX_SUB_MENUS];
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_VT_SETTING, NULL, mmi_vt_entry_setting, NULL);
    PRINT_INFORMATION("\n[mmi_vt_entry_setting] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_SETTING);

    numItems = GetNumOfChild_Ext(MENU_ID_VT_INCALL_OPT_SETTING);
    GetSequenceStringIds_Ext(MENU_ID_VT_INCALL_OPT_SETTING, nStrItemList);    
    SetParentHandler(MENU_ID_VT_INCALL_OPT_SETTING);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_ID_VT_INCALL_OPT_SETTING, popUpList);

    ShowCategory52Screen(
        STR_ID_VT_VIDEO_CALL_SETTING,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vt_setting_get_hilite_index
 * DESCRIPTION
 *  Get current highlight index
 * PARAMETERS
 *  nIndex      [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_setting_get_hilite_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->setting.curr_hilite_index = (U16)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_answer_mode
 * DESCRIPTION
 *  Entry answer mode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];
    S32 hiliteitem = 0;    
    U16 nNumofItem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_ANSWER_MODE, NULL, mmi_vt_entry_answer_mode, NULL);

    PRINT_INFORMATION("\n[mmi_vt_entry_answer_mode] \n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_ANSWER_MODE);
    
    nNumofItem = GetNumOfChild_Ext(MENU_ID_VT_SETTING_ANSWER_MODE);
    GetSequenceStringIds_Ext(MENU_ID_VT_SETTING_ANSWER_MODE, nStrItemList);
    SetParentHandler(MENU_ID_VT_SETTING_ANSWER_MODE);

    if (guiBuffer != NULL)
    {
        hiliteitem = (S32)g_vt_p->setting.curr_hilite_index;
    }
    else
    {
        hiliteitem = (S32)g_vt_p->setting.answer_mode;
    }
    
    RegisterHighlightHandler(mmi_vt_setting_get_hilite_index);

    ShowCategory11Screen(
        STR_ID_VT_ANSWER_MODE,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vt_set_answer_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_answer_mode
 * DESCRIPTION
 *  Set answer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_set_answer_mode] index = %d \n",g_vt_p->setting.curr_hilite_index);
    
    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MMI_VT_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    
    WriteValue(NVRAM_VT_ANSWER_MODE, &(g_vt_p->setting.curr_hilite_index), DS_BYTE, &errorCode);
    
    g_vt_p->setting.answer_mode = (mmi_vt_answer_mode_enum)g_vt_p->setting.curr_hilite_index;
    
    DeleteScreenIfPresent(SCR_ID_VT_ANSWER_MODE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_dial_mode
 * DESCRIPTION
 *  Entry dial mode screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nStrItemList[MAX_SUB_MENUS];
    S32 hiliteitem = 0;    
    U16 nNumofItem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_DIAL_MODE, NULL, mmi_vt_entry_dial_mode, NULL);

    PRINT_INFORMATION("\n[mmi_vt_entry_dial_mode] \n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_DIAL_MODE);
    
    nNumofItem = GetNumOfChild_Ext(MENU_ID_VT_SETTING_DIAL_MODE);
    GetSequenceStringIds_Ext(MENU_ID_VT_SETTING_DIAL_MODE, nStrItemList);
    SetParentHandler(MENU_ID_VT_SETTING_DIAL_MODE);

    if (guiBuffer != NULL)
    {
        hiliteitem = (S32)g_vt_p->setting.curr_hilite_index;
    }
    else
    {
        hiliteitem = (S32)g_vt_p->setting.dial_mode;
    }
    
    RegisterHighlightHandler(mmi_vt_setting_get_hilite_index);

    ShowCategory11Screen(
        STR_ID_VT_DIAL_MODE,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16) hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vt_set_dial_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_dial_mode
 * DESCRIPTION
 *  Set dial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_set_dial_mode] index = %d \n",g_vt_p->setting.curr_hilite_index);
    
    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MMI_VT_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    
    WriteValue(NVRAM_VT_DIAL_MODE, &(g_vt_p->setting.curr_hilite_index), DS_BYTE, &errorCode);
    
    g_vt_p->setting.dial_mode = (mmi_vt_dial_mode_enum)g_vt_p->setting.curr_hilite_index;
    
    DeleteScreenIfPresent(SCR_ID_VT_DIAL_MODE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_alt_incall_pic
 * DESCRIPTION
 *  Shows the incall image setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_alt_incall_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_VT_ALT_INCALL_PIC, NULL, mmi_vt_entry_alt_incall_pic, NULL);
    PRINT_INFORMATION("\n[mmi_vt_entry_alt_incall_pic] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_ALT_INCALL_PIC);

    numItems = GetNumOfChild_Ext(MENU_ID_VT_SETTING_INCALL_IMAGE);
    GetSequenceStringIds_Ext(MENU_ID_VT_SETTING_INCALL_IMAGE, nStrItemList);    
    SetParentHandler(MENU_ID_VT_SETTING_INCALL_IMAGE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_VT_IMAGE_IN_VIDEO_CALL,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_audio_option
 * DESCRIPTION
 *  Entry audio option settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_audio_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 numItems = MMI_VT_AUDIO_OPTION_TOTAL_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_AUDIO_OPTION, NULL, mmi_vt_entry_audio_option, NULL);
    PRINT_INFORMATION("\n[mmi_vt_entry_audio_option] \n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_AUDIO_OPTION);
    subMenuDataPtrs[MMI_VT_AUDIO_OPTION_MIC_OFF] = (PU8) GetString((U16) STR_ID_VT_MIC_OFF);
    subMenuDataPtrs[MMI_VT_AUDIO_OPTION_SPEAKER_OFF] = (PU8) GetString((U16) STR_ID_VT_SPEAKER_OFF);

    SetCheckboxToggleRightSoftkeyFunctions(mmi_vt_entry_audio_opt_confirm, GoBackHistory);
    
    ShowCategory140Screen(
        STR_ID_VT_START_CALL_WITH,
        GetRootTitleIcon(MENU_ID_VT_MAIN),
        numItems,
        (U8 **) subMenuDataPtrs,
        (U8*) g_vt_p->setting.audio_opt,
        0,
        guiBuffer);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_audio_opt_confirm
 * DESCRIPTION
 *  Confirmation to save audio option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_audio_opt_confirm(void)
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

    SetLeftSoftkeyFunction(mmi_vt_audio_opt_confirm_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vt_audio_opt_confirm_no, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_audio_opt_confirm_yes
 * DESCRIPTION
 *  Confirm to save audio option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_audio_opt_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vt_p->setting.is_mic_off = g_vt_p->setting.audio_opt[MMI_VT_AUDIO_OPTION_MIC_OFF];
    g_vt_p->setting.is_speaker_off = g_vt_p->setting.audio_opt[MMI_VT_AUDIO_OPTION_SPEAKER_OFF];

    PRINT_INFORMATION("\n[mmi_vt_audio_opt_confirm_yes] mic_off=%d speaker_off=%d \n",
                        g_vt_p->setting.is_mic_off, g_vt_p->setting.is_speaker_off);
    
    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MMI_VT_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    
    WriteValue(NVRAM_VT_AUDIO_OPT_MIC, &(g_vt_p->setting.is_mic_off), DS_BYTE, &errorCode);
    WriteValue(NVRAM_VT_AUDIO_OPT_SPEAKER, &(g_vt_p->setting.is_speaker_off), DS_BYTE, &errorCode);
    
    DeleteScreenIfPresent(SCR_ID_VT_AUDIO_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_audio_opt_confirm_no
 * DESCRIPTION
 *  Cancel to save audio option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_audio_opt_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_audio_opt_confirm_no]\n");
    DeleteScreenIfPresent(SCR_ID_VT_AUDIO_OPTION);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_setting_incall_image_default
 * DESCRIPTION
 *  Funtion is called when default menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_setting_incall_image_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_set_incall_pic_default, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_highlight_setting_incall_image_user_define
 * DESCRIPTION
 *  Funtion is called when user define menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_highlight_setting_incall_image_user_define(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vt_entry_file_mgr_to_select_incall_pic, KEY_EVENT_UP);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_incall_pic_default
 * DESCRIPTION
 *  Set alt incall pic to default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_incall_pic_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 null_terminator[] = {0x00,0x00};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_set_incall_pic_default] \n");

    mmi_vt_set_incall_pic((U16*)null_terminator);

    /* go back to incall screen if during in-call */
    if (IsScreenPresent(SCR_ID_VT_INCALL_OPTION))
    {
        mmi_vt_set_camera_status(MMI_FALSE);
        DeleteScreenIfPresent(SCR_ID_VT_INCALL_OPTION);
        GoBackHistory();
    }
    else
    {
        DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                1,
                MMI_VT_POPUP_TIME_OUT,
                (U8) SUCCESS_TONE);
		
        DeleteScreenIfPresent(SCR_ID_VT_ALT_INCALL_PIC);
    }
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_file_mgr_to_select_incall_pic
 * DESCRIPTION
 *  Function for users to select incall pic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_file_mgr_to_select_incall_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);

    /* todo: set all supported filters here */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
    
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    if (mmi_ucm_app_total_call(MMI_UCM_VIDEO_CALL_TYPE) == 0)
    {
        PRINT_INFORMATION("\n[mmi_vt_entry_file_mgr_to_select_incall_pic] no video call \n");
        mmi_fmgr_select_path_and_enter(
                    APP_VT,
                    FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
                    filter,
                    (S8*) L"root",
                    (PsExtFuncPtr) mmi_vt_set_incall_pic_from_fm);
    }
    else
    {
        PRINT_INFORMATION("\n[mmi_vt_entry_file_mgr_to_select_incall_pic] video call exists \n");    
        mmi_fmgr_select_path_and_enter(
                    APP_VT,
                    FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
                    filter,
                    (S8*) L"root",
                    (PsExtFuncPtr) mmi_vt_set_incall_pic_from_fm_during_incall);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_incall_pic_from_fm
 * DESCRIPTION
 *  Select object from file manager
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_incall_pic_from_fm(PU16 file_path, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_set_incall_pic_from_fm] \n");
    
    if (file_path == NULL)
    {
        GoBackToHistory(SCR_ID_VT_ALT_INCALL_PIC);
        return;
    }

    mmi_vt_set_incall_pic(file_path);

    fmgr_reset_app_select();
    
    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MMI_VT_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);

    DeleteScreenIfPresent(SCR_ID_VT_ALT_INCALL_PIC);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_set_incall_pic_from_fm_during_incall
 * DESCRIPTION
 *  Select object from file manager
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_set_incall_pic_from_fm_during_incall(PU16 file_path, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_set_incall_pic_from_fm_during_incall] \n");
    
    if (file_path == NULL)
    {
        GoBackToHistory(SCR_ID_VT_INCALL_OPTION);
        return;
    }

    mmi_vt_set_incall_pic(file_path);
    mmi_vt_set_camera_status(MMI_FALSE);

    fmgr_reset_app_select();

    if (IsScreenPresent(SCR_ID_VT_INCALL))
    {
        GoBackToHistory(SCR_ID_VT_INCALL);
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_mo_fail_post_action_add_to_history
 * DESCRIPTION
 *  Add mo fail post action screen to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_mo_fail_post_action_add_to_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_mo_fail_post_action_add_to_history] \n");

    memset(&currHistory, 0, sizeof(currHistory));
    currHistory.scrnID = SCR_ID_VT_MO_FAIL_POST_ACTION;
    currHistory.entryFuncPtr = mmi_vt_entry_mo_fail_post_action;
    memset((S8*) currHistory.inputBuffer, 0, ENCODING_LENGTH);

    AddHistory(currHistory);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_mo_fail_post_action
 * DESCRIPTION
 *  Entry post action screen after failed MO 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_mo_fail_post_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 item_index = 0;
    U8 *listItemsIcons[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VT_MO_FAIL_POST_ACTION, NULL, mmi_vt_entry_mo_fail_post_action, NULL);

    subMenuDataPtrs[MMI_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL] = (U8*) GetString(STR_ID_VT_MAKE_VOICE_CALL);
    subMenuDataPtrs[MMI_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL] = (U8*) GetString(STR_ID_VT_REDIAL_VIDEO_CALL);
#ifdef MMS_SUPPORT    
    subMenuDataPtrs[MMI_VT_MO_FAIL_ACTION_SEND_MMS] = (U8*) GetString(STR_ID_VT_SEND_MMS);
#endif /* MMS_SUPPORT */
    subMenuDataPtrs[MMI_VT_MO_FAIL_ACTION_SEND_SMS] = (U8*) GetString(STR_ID_VT_SEND_SMS);

    for (item_index = 0; item_index < MMI_VT_MO_FAIL_ACTION_TOTAL_NUM; item_index++)
    {
        listItemsIcons[item_index] = (U8*) GetImage(gIndexIconsImageList[item_index]);
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VT_MO_FAIL_POST_ACTION);
    RegisterHighlightHandler(mmi_vt_setting_get_hilite_index);

    ShowCategory32Screen(
        (U8*) GetString(STR_ID_VT_FAIL_TO_MAKE_VIDEO_CALL),
        (U8*) GetImage(GetRootTitleIcon(MENU_ID_VT_MAIN)),
        (U8*) GetString(STR_GLOBAL_OK),
        (U8*) GetImage(IMG_GLOBAL_OK),
        (U8*) GetString(STR_GLOBAL_BACK),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        MMI_VT_MO_FAIL_ACTION_TOTAL_NUM,
        (U8 **) subMenuDataPtrs,
        listItemsIcons,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vt_process_mo_fail_post_action, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_process_mo_fail_post_action
 * DESCRIPTION
 *  Process mo fail action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_process_mo_fail_post_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_entry_dummy();
    DeleteScreenIfPresent(SCR_ID_VT_MO_FAIL_POST_ACTION);

    switch (g_vt_p->setting.curr_hilite_index)
    {
        case MMI_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL:
        {
            mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8*) g_vt_p->mo_info.dial_pad_buffer);
        }
        break;

        case MMI_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL:
        {
            mmi_ucm_app_make_call(MMI_UCM_VIDEO_CALL_TYPE, (U8*) g_vt_p->mo_info.dial_pad_buffer);
        }
        break;
        
    #ifdef MMS_SUPPORT
        case MMI_VT_MO_FAIL_ACTION_SEND_MMS:
        {
            mms_address_insert_hdlr((char*)g_vt_p->mo_info.dial_pad_buffer); 
        }
        break;
    #endif /* MMS_SUPPORT */

        case MMI_VT_MO_FAIL_ACTION_SEND_SMS:
        {
            mmi_frm_sms_api_entry_write_struct *sendData = OslMalloc(sizeof(mmi_frm_sms_api_entry_write_struct));
            U8* number = OslMalloc(MMI_UCM_MAX_NUM_URI_LEN + 1);

            memset((S8*) sendData, 0, sizeof(mmi_frm_sms_api_entry_write_struct));
            memset(number, 0, sizeof(number));

            mmi_ucs2_n_to_asc((S8*) number, (S8*)g_vt_p->mo_info.dial_pad_buffer, MMI_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);

            sendData->flag = MMI_FRM_SMS_ENTRY_WRITE_REPLY;
            sendData->ascii_addr = number;

            mmi_frm_sms_api_entry_write_msg(sendData);
            OslMfree(number);
            OslMfree(sendData);
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;        
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_add_incall_to_history
 * DESCRIPTION
 *  Add incall screen to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_add_incall_to_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&currHistory, 0, sizeof(currHistory));
    currHistory.scrnID = SCR_ID_VT_INCALL;
    currHistory.entryFuncPtr = mmi_vt_entry_in_call;
    memset((S8*) currHistory.inputBuffer, 0, ENCODING_LENGTH);

    AddHistory(currHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_entry_in_call
 * DESCRIPTION
 *  Entry in call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_entry_in_call()
{
    mmi_vt_init_incall_setting();

    if (mmi_ucm_app_total_call(MMI_UCM_VIDEO_CALL_TYPE) > 0)
    {
        g_vt_p->incall_screen.mode = MMI_VT_INCALL_SCREEN_MODE_INCALL;
    }
    else
    {
        g_vt_p->incall_screen.mode = MMI_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY;

        if (g_vt_p->setting.dial_mode == MMI_VT_DIAL_MODE_STOP_CAMERA)
        {
            mmi_vt_set_camera_status(MMI_FALSE);
        }
        else
        {
            mmi_vt_set_camera_status(MMI_TRUE);
        }
    }
    mmi_vtcs_entry_call_scr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_start_camera_query_yes
 * DESCRIPTION
 *  Confirm to start camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_start_camera_query_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VT_START_CAMERA_QUERY_TIMER);
    mmi_vt_set_camera_status(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_start_camera_query_no
 * DESCRIPTION
 *  Confirm to stop camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_start_camera_query_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VT_START_CAMERA_QUERY_TIMER);
    mmi_vt_set_camera_status(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_start_camera_query_timeout
 * DESCRIPTION
 *  Start Camera query timeour hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_start_camera_query_timeout (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vt_set_camera_status(MMI_FALSE);
    mmi_ucm_dispatch_cnf(MMI_UCM_CANCEL_CNF, NULL);
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_bt_set_audio_path
 * DESCRIPTION
 *  BT set audio path function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_bt_set_audio_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_SUPPORT__)
    if (mmi_bt_is_incall_aud_swap2bt() == MMI_TRUE)
    {
        PRINT_INFORMATION("[mmi_vt_bt_set_audio_path] transfer to AG \n");   
    
        /* Current voice path in BT, shall transfer to AG */
        mmi_bt_switch_voice_path_incall(MMI_FALSE);
    }
    else
    {
        PRINT_INFORMATION("[mmi_vt_bt_set_audio_path] transfer to BT \n");   
        
        /* Current voice path in AG, shall transfer to BT */
        mmi_bt_switch_voice_path_incall(MMI_TRUE);
    }
#endif /* defined(__MMI_BT_SUPPORT__) */

    return;
}   



/*****************************************************************************
 * FUNCTION
 *  mmi_vt_pre_entry_new_call
 * DESCRIPTION
 *  Pre entry function of new call editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_pre_entry_new_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0, keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("\n[mmi_vt_pre_entry_new_call]\n");

    GetkeyInfo(&keyCode, &keyType);

    mmi_vt_entry_dialer_screen();

    wgui_execute_key_handler(keyCode, keyType);

}

#endif /* __MMI_VIDEO_TELEPHONY__ */


