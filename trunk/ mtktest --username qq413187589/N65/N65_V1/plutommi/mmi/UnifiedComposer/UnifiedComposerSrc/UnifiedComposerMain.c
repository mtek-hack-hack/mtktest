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
 * UnifiedComposerMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements main utilities for Unified Composer.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMI_UNIFIED_COMPOSER_MAIN_C
#define _MMI_UNIFIED_COMPOSER_MAIN_C

#ifdef __MMI_UNIFIED_COMPOSER__

#include "FileMgr.h"
#include "FileManagerGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)
#include "mdi_video.h"
#endif 

/* micha1230 */
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "MessagesExDcl.h"
#include "MessagesResourceData.h"
#include "USBDeviceGprot.h"



#include "wgui_status_icons.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "ProfileGprots.h"

#include "PhoneBookGprot.h"
#include "PhoneBookDef.h"
#include "PhonebookTypes.h"

#include "Conversions.h"

#include "MemPoolContainerProt.h"
#include "wgui_asyncdynamic_menuitems.h"


#include "AudioPlayerProt.h"
#include "VdoPlyGProt.h"

#include "CallManagementGprot.h"
#include "CommonScreens.h"
#include "fmt_struct.h"
#include "DateTimeGprot.h"
#include "MessagesMiscell.h"
#include "SmsGuiInterfaceProt.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "custom_wap_config.h"
#include "AlarmFrameworkProt.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "MessagesL4Def.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "SMSFunc.h"

#include "IdleAppDef.h"
#include "xml_def.h"
#include "app_asyncfile.h"

#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderProt.h"
#endif /* __MMI_SOUND_RECORDER__ */

#ifdef __MMI_VIDEO_RECORDER__
#include "VdoRecGprot.h"
#endif /* __MMI_VIDEO_RECORDER__ */
#ifdef __MMI_MMS_2__
#include "MMSViewerAPPDefs.h"
#endif /* __MMI_MMS_2__ */

#include "UnifiedMessageGProt.h"
#include "custom_uc_config.h"
#include "UnifiedComposerResDef.h"
#include "UnifiedComposerGProt.h"
#include "UnifiedComposerProt.h"
#include "Mmsadp.h"  

mmi_uc_context_struct g_uc_cntx;    /* global context of uc */
mmi_uc_context_struct *g_uc_p = &g_uc_cntx;

extern MMI_PHB_ENTRY_BCD_STRUCT PhoneBook[];
#if defined(__MMI_TOUCH_SCREEN__)
/* To sync with phb design */
extern const UI_character_type mmi_phb_e_mail_allowed[];
#endif
extern U8 mmi_phb_convert_to_digit(U8 *dest, U8 *source, U8 max_dest_len);

extern int wap_entry_select_bookmark(void);
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
extern void mmi_frm_highlight_input_method_generic(void);
#endif

#ifdef __MMI_CAMERA__

extern void mmi_camera_entry_for_external_request(
                void (*camera_result_callback)(MMI_BOOL result, S8 *filepath));

#endif /* __MMI_CAMERA__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_init
 * DESCRIPTION
 *  Initialize Unified Composer application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_init_context();
    mmi_uc_set_protocol_event_handler();
    mmi_uc_create_adm_mem();
    mmi_uc_set_highlight_handler();
    mmi_uc_init_uc_folder();
    mmi_uc_init_setting();       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_highlight_handler
 * DESCRIPTION
 *  Set highlight handler for uc app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_set_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the option menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_DONE, mmi_uc_highlight_opt_done);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT, mmi_uc_highlight_opt_insert);
    SetHiliteHandler(MENU_ID_UC_OPT_REMOVE, mmi_uc_highlight_opt_remove);
    SetHiliteHandler(MENU_ID_UC_OPT_REPLACE, mmi_uc_highlight_opt_replace);
    SetHiliteHandler(MENU_ID_UC_OPT_PREVIEW, mmi_uc_highlight_opt_preview);
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT, mmi_uc_highlight_opt_slide_opt);
    SetHiliteHandler(MENU_ID_UC_OPT_MSG_TYPE_OPT, mmi_uc_highlight_opt_msg_type);    
    SetHiliteHandler(MENU_ID_UC_OPT_SEND_OPT, mmi_uc_highlight_opt_send_opt);
    SetHiliteHandler(MENU_ID_UC_OPT_MSG_DETAIL, mmi_uc_highlight_opt_msg_detail);
    SetHiliteHandler(MENU_ID_UC_OPT_INPUT_METHOD, mmi_uc_highlight_opt_input_method);    

    /* set address option menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_DONE, mmi_uc_highlight_addr_opt_done);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_ADD_NUMBER, mmi_uc_highlight_addr_opt_add_number);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_ADD_EMAIL, mmi_uc_highlight_addr_opt_add_email);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_EDIT, mmi_uc_highlight_addr_opt_edit);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_DELETE, mmi_uc_highlight_addr_opt_delete);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_DELETE_ALL, mmi_uc_highlight_addr_opt_delete_all);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_ADD_NUMBER_GROUP, mmi_uc_highlight_addr_opt_add_number_group);
    SetHiliteHandler(MENU_ID_UC_OPT_ADDR_ADD_EMAIL_GROUP, mmi_uc_highlight_addr_opt_add_email_group);

    /* set insert menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_IMAGE, mmi_uc_highlight_insert_image);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_AUDIO, mmi_uc_highlight_insert_audio);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_VIDEO, mmi_uc_highlight_insert_video);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_TEXT_TEMPLATE, mmi_uc_highlight_insert_text_template);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_ATTACHMENT, mmi_uc_highlight_insert_attachment);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_PHB_NUMBER, mmi_uc_highlight_insert_phb_number);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_PHB_NAME, mmi_uc_highlight_insert_phb_name);
    SetHiliteHandler(MENU_ID_UC_OPT_INSERT_BOOKMARK, mmi_uc_highlight_insert_bookmark);    
           
#ifdef __MMI_CAMERA__
        SetHiliteHandler(MENU_ID_UC_OPT_INSERT_NEW_IMAGE, mmi_uc_highlight_insert_new_image);
#endif /* __MMI_CAMERA__ */
    
#ifdef __MMI_SOUND_RECORDER__
        SetHiliteHandler(MENU_ID_UC_OPT_INSERT_NEW_AUDIO, mmi_uc_highlight_insert_new_audio);
#endif /* __MMI_SOUND_RECORDER__ */
    
#ifdef __MMI_VIDEO_RECORDER__
        SetHiliteHandler(MENU_ID_UC_OPT_INSERT_NEW_VIDEO, mmi_uc_highlight_insert_new_video);
#endif /* __MMI_VIDEO_RECORDER__ */

    /* set remove menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_REMOVE_IMAGE, mmi_uc_highlight_remove_image);
    SetHiliteHandler(MENU_ID_UC_OPT_REMOVE_AUDIO, mmi_uc_highlight_remove_audio);
    SetHiliteHandler(MENU_ID_UC_OPT_REMOVE_VIDEO, mmi_uc_highlight_remove_video);
    SetHiliteHandler(MENU_ID_UC_OPT_REMOVE_ATTACHMENT, mmi_uc_highlight_remove_attachment);

    /* set replace menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_REPLACE_IMAGE, mmi_uc_highlight_replace_image);
    SetHiliteHandler(MENU_ID_UC_OPT_REPLACE_AUDIO, mmi_uc_highlight_replace_audio);
    SetHiliteHandler(MENU_ID_UC_OPT_REPLACE_VIDEO, mmi_uc_highlight_replace_video);
    SetHiliteHandler(MENU_ID_UC_OPT_REPLACE_ATTACHMENT, mmi_uc_highlight_replace_attachment);

    /* set slide option menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_INSERT, mmi_uc_highlight_slide_opt_insert);
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE, mmi_uc_highlight_slide_opt_insert_before);
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_DELETE, mmi_uc_highlight_slide_opt_delete);
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS, mmi_uc_highlight_slide_opt_previous);
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_NEXT, mmi_uc_highlight_slide_opt_next);
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_GO_TO, mmi_uc_highlight_slide_opt_goto);        
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_TIMING, mmi_uc_highlight_slide_opt_timing);    
#ifdef __MMI_MMS_2__
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING, mmi_uc_highlight_slide_opt_text_timing);    
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING, mmi_uc_highlight_slide_opt_image_timing);    
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING, mmi_uc_highlight_slide_opt_audio_timing);    
    SetHiliteHandler(MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING, mmi_uc_highlight_slide_opt_video_timing);
#endif /* __MMI_MMS_2__ */

    /* set slide option menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_SETTING_PREFERRED_TYPE, mmi_uc_highlight_preferred_type);
    
    /* set done option menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_SEND, mmi_uc_highlight_done_opt_send);
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_SEND_AND_SAVE, mmi_uc_highlight_done_opt_send_and_save);
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_SAVE, mmi_uc_highlight_done_opt_save);
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_BACK_TO_EDIT_MSG, mmi_uc_highlight_done_opt_back_to_edit);
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_MSG_TYPE, mmi_uc_highlight_opt_msg_type);
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_SEND_OPT, mmi_uc_highlight_done_opt_send_opt);
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_EXIT, mmi_uc_highlight_done_opt_exit);
    
#if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
    SetHiliteHandler(MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE, mmi_uc_highlight_done_opt_save_as_template);
#endif /* __MMI_MMS_2__ */    

    /* set remove menu highlight handlers */
    SetHiliteHandler(MENU_ID_UC_EXIT_OPT_SAVE, mmi_uc_highlight_exit_opt_save);
    SetHiliteHandler(MENU_ID_UC_EXIT_OPT_EXIT, mmi_uc_highlight_exit_opt_exit);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_pre_entry_write_msg
 * DESCRIPTION
 *  Pre entry function of unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_pre_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_um_check_ready())
    {
        DisplayPopup(
            (PU8) GetString(mmi_um_get_not_available_string_id()),
            IMG_GLOBAL_ERROR,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
    
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) MMI_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (g_uc_p->send_info.action != MMI_UC_ACTION_IDLE)
    {
        DisplayPopup(
            (PU8) GetString(mmi_um_get_not_available_string_id()),
            IMG_GLOBAL_ERROR,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);            
        
        return;
    }
    
    g_uc_p->main.state = MMI_UC_STATE_WRITE_NEW_MSG;

    if (g_uc_p->msg.total_slide_num > 0 &&
        IsScreenPresent(SCR_ID_UC_EDITOR))
    {
        /* UC in entered by other apps, ex, bar code reader. And then MT call. Option\message center\write message */
        MMI_ASSERT(isInCall());
        
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_UC_DISCARD_EDITED_MSG_ID),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_uc_discard_msg_before_enter_write_msg, KEY_EVENT_UP);
    
    }
    else
    {
        mmi_uc_reset_msg();
        
        g_uc_p->msg_type.setting_msg_type = mmi_uc_get_setting_msg_type();
        g_uc_p->msg_type.curr_msg_type = g_uc_p->msg_type.setting_msg_type;
        g_uc_p->msg_type.caller_specific_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
        g_uc_p->msg_type.backup_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
        
        mmi_uc_process_entry_write_msg();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_discard_msg_before_enter_write_msg
 * DESCRIPTION
 *  Discard previous edited msg before entering write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_discard_msg_before_enter_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 startScrnId = SCR_ID_UC_EDITOR;
    U16 endScrnId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*---[UnifiedComposerMain.c] mmi_uc_discard_msg_before_enter_write_msg ---*\n");
    
    mmi_uc_reset_msg();
    
    /* UC in entered by other apps, ex, bar code reader. And then MT call. Option\message center\write message */
    MMI_ASSERT(isInCall());

    if (IsScreenPresent(startScrnId))
    {
        GetPreviousScrnIdOf(GetCmMarkerScrnID(), &endScrnId);
        if (endScrnId)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                 "*---[UnifiedComposerMain.c] End scrn id to be deleteted %d ---*\n", endScrnId);
            if (DeleteBetweenScreen(startScrnId, endScrnId))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*---[UnifiedComposerMain.c] Deleteted scrn id from %d to %d ---*\n",
                                     startScrnId, endScrnId);
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    g_uc_p->msg_type.setting_msg_type = mmi_uc_get_setting_msg_type();
    g_uc_p->msg_type.curr_msg_type = g_uc_p->msg_type.setting_msg_type;
    g_uc_p->msg_type.caller_specific_msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    g_uc_p->msg_type.backup_msg_type = MMI_UC_MSG_TYPE_DEFAULT;    
    
    mmi_uc_process_entry_write_msg();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_entry_write_msg
 * DESCRIPTION
 *  Process function of entering unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*---[UnifiedComposerMain.c] mmi_uc_process_entry_write_msg ---*\n");
    
    result = mmi_uc_check_uc_folder();
    if (result < 0)
    {            
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
            
        return;            
    }

    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
    {    
        title_id = STR_UC_FORWARD_ID;
    }
    else if (g_uc_p->main.state == MMI_UC_STATE_SEND)
    {    
        title_id = STR_UC_SEND_ID;
    }
    else
    {
        title_id = STR_UC_WRITE_MSG_ID;
    }
    
    mmi_uc_set_processing_screen(title_id, 
                                 STR_UC_PLEASE_WAIT_ID, 
                                 IMG_GLOBAL_PROGRESS, 
                                 0);
    mmi_uc_entry_processing_generic();

    /* need EMS library support  */
    mmi_uc_get_sms_setting();

    /* send get setting request to MMS */
    mmi_uc_get_mms_setting_req();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_write_msg_end_key_hdlr
 * DESCRIPTION
 *  End key handler for unified composer editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_write_msg_end_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!isInCall())
    {
        mmi_uc_handle_text_in_current_slide();
        /* mmi_uc_write_msg_delete_history_hdlr would be called in ExecuteRootMainHistoryScreen */
        //mmi_uc_write_msg_delete_history_hdlr(NULL);
    }
    
    ExecCurrEndKeyDownHandler();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_write_msg
 * DESCRIPTION
 *  Exit function from write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* If press RSK in uc screen to exit editor, msg would be reset in RSK handler mmi_uc_go_back_from_write_msg */
    if (g_uc_p->msg.current_slide)
    {
        result = mmi_uc_handle_text_in_current_slide();
        g_uc_p->main.current_text_file_save_result = result;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_write_msg
 * DESCRIPTION
 *  Entry function of unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* reset */
    g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
    g_uc_p->send_info.abort = MMI_UC_ABORT_NONE;

    /* disallow re-entering SMS application when there is a pending SMS job running in the background */
    if (mmi_frm_sms_check_action_pending())
    {
        DisplayPopup(
            (PU8) GetString(mmi_um_get_not_available_string_id()),
            IMG_GLOBAL_UNFINISHED,
            1,
            MESSAGES_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        /*main_cb will be called*/
        mmi_uc_reset_msg();      

        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);        
        return;
    }
    
    EntryNewScreen(SCR_ID_UC_EDITOR, mmi_uc_exit_write_msg, mmi_uc_entry_write_msg, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_write_msg*\n");
    
    AlmDisableSPOF();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_EDITOR);
    GetCurrEndKeyDownHandler();

    g_uc_p->send_info.curr_folder = (U16)mmi_um_get_current_msg_box_type();
   
    ShowCategory280Screen(STR_UC_WRITE_MSG_ID,
                         IMG_UC_ENTRY_SCRN_CAPTION_ID,
                         STR_GLOBAL_OPTIONS,
                         IMG_GLOBAL_OPTIONS,
                         STR_UC_EXIT_ID,
                         IMG_GLOBAL_BACK,
                         mmi_uc_convert_to_editor_msg_type(g_uc_p->msg_type.curr_msg_type),
                         INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
                         guiBuffer);

    SetLeftSoftkeyFunction(mmi_uc_pre_entry_option, KEY_EVENT_UP);

    SetKeyHandler(mmi_uc_pre_entry_option, KEY_SEND, KEY_EVENT_UP);

    RegisterInputMethodScreenCloseFunction(mmi_uc_go_back_from_write_msg);
    SetCategory280RightSoftkeyFunction(mmi_uc_go_back_from_write_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_write_msg_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);

    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
    SetDelScrnIDCallbackHandler(SCR_ID_UC_EDITOR, (HistoryDelCBPtr) mmi_uc_write_msg_delete_history_hdlr);

    if (g_uc_p->msg.fail_to_insert_signature)
    {
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            DisplayPopup((PU8) GetString(STR_UC_FAIL_TO_INSERT_SIGNATURE_ID),
                 IMG_GLOBAL_UNFINISHED,
                 1,
                 MMI_UC_POPUP_TIME_OUT,
                 (U8) ERROR_TONE);
       }
        g_uc_p->msg.fail_to_insert_signature = MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_write_msg_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_uc_write_msg_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->send_info.action == MMI_UC_ACTION_IDLE)
    {
        if (mmi_uc_is_pending_content())
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_write_msg_delete_history_hdlr save in background *\n");
    
            g_uc_p->send_info.action = MMI_UC_ACTION_SAVE_IN_BACKGROUND;

            /* Save the edited msg. */
            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
            {
                mmi_uc_save_sms_req();
            }
            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
               result = mmi_uc_create_mms_xml_description_file();

               if (result == FS_NO_ERROR)
               {
                   mmi_uc_create_mms_req();
               }
               else
               {
                   mmi_uc_reset_msg();
               }
            }
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_write_msg_delete_history_hdlr reset msg *\n");
            
            mmi_uc_reset_msg();
        }
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_write_msg_delete_history_hdlr Do Nothing *\n");    
        
        /* Disable following actions in mmi_uc_action_fsm() */
        //g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
    }
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_exit_option
 * DESCRIPTION
 *  Entry function of unified composer exit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_exit_option(void)
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
    EntryNewScreen(SCR_ID_UC_EXIT_OPT, mmi_uc_exit_generic, mmi_uc_entry_exit_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_exit_option *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_EXIT_OPT);

    numItems = GetNumOfChild_Ext(MENU_ID_UC_EXIT_OPT);
    GetSequenceStringIds_Ext(MENU_ID_UC_EXIT_OPT, nStrItemList);

    SetParentHandler(MENU_ID_UC_EXIT_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_exit_opt_save
 * DESCRIPTION
 *  Funtion is called when save item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_exit_opt_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_save_msg_before_exit_write_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_save_msg_before_exit_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_exit_opt_exit
 * DESCRIPTION
 *  Funtion is called when exit item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_exit_opt_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_discard_msg_before_exit_write_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_discard_msg_before_exit_write_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_go_back_from_write_msg
 * DESCRIPTION
 *  Go back function from write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_go_back_from_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_exit_write_msg();
    if (mmi_uc_is_pending_content())
    {        
        mmi_uc_entry_exit_option();                
    }
    else
    {
        mmi_uc_reset_msg();
        GoBackHistory();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_discard_msg_before_exit_write_msg
 * DESCRIPTION
 *  Go back function from write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_discard_msg_before_exit_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_reset_msg();
    DeleteScreenIfPresent(SCR_ID_UC_EDITOR);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_msg_before_exit_write_msg
 * DESCRIPTION
 *  Go back function from write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_msg_before_exit_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->main.current_text_file_save_result == FS_NO_ERROR)
    {
        mmi_uc_process_save();
    }
    else
    {                
        DisplayConfirm(
                       STR_GLOBAL_OK,
                       IMG_GLOBAL_OK,
                       0,
                       0,
                       get_string(STR_UC_STORAGE_FULL_MSG_CONTENT_LOSS_ID),
                       IMG_GLOBAL_INFO,
                       WARNING_TONE);
            
        SetLeftSoftkeyFunction(mmi_uc_process_save, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_pre_entry_option
 * DESCRIPTION
 *  Pre-entry function of unified composer option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_pre_entry_option(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_exit_write_msg();
    /*mmi_uc_update_msg_size(); */ 
    if (g_uc_p->main.current_text_file_save_result == FS_NO_ERROR)
    {
        mmi_uc_update_msg_size();  
        mmi_uc_entry_option();
    }
    else
    {
        if (g_uc_p->main.current_text_file_save_result == FS_DISK_FULL)
        {
            DisplayPopup(
                (PU8)GetString(STR_UC_STORAGE_FULL_DELETE_FILE_ID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);         
        }
        else
        {
            DisplayPopup(
                (PU8)GetString(GetFileSystemErrorString(g_uc_p->main.current_text_file_save_result)),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);                        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_option
 * DESCRIPTION
 *  Entry function of unified composer option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_option(void)
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
    EntryNewScreen(SCR_ID_UC_OPT, mmi_uc_exit_generic, mmi_uc_entry_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_option *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT);

    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REMOVE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REPLACE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_PREVIEW);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SEND_OPT);                
    }
    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER )
    {
        if (g_uc_p->msg.current_slide->image.object ||
            g_uc_p->msg.current_slide->audio.object ||
            g_uc_p->msg.current_slide->video.object ||
            g_uc_p->msg.total_attachment_num)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REMOVE);
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REPLACE);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REMOVE);
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REPLACE);
        }
        
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_PREVIEW);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SEND_OPT);
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT);
    }

    
    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY ||
        g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_MMS_ONLY ||
        mmi_uc_determine_msg_type_by_content() == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_MSG_TYPE_OPT);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_MSG_TYPE_OPT);
    }

    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_done
 * DESCRIPTION
 *  Entry function of done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    S32 items_num = 0;
    U16 inputBufferSize;    /* added for inline edit history */
    U16 image_list[MMI_UC_DONE_TOTAL_NUM] = {0};
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    EntryNewScreen(SCR_ID_UC_OPT_DONE, mmi_uc_exit_done, NULL, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_done *\n");

    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
    {    
        title_id = STR_UC_FORWARD_ID;
    }
    else if (g_uc_p->main.state == MMI_UC_STATE_SEND)
    {    
        title_id = STR_UC_SEND_ID;
    }
    else
    {
        title_id = STR_GLOBAL_OPTIONS;
    }

    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        items_num = MMI_UC_DONE_SMS_ONLY_TOTAL_NUM;
    }
    else
    {
        items_num = MMI_UC_DONE_TOTAL_NUM;
    }
   
    mmi_uc_update_msg_size();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE);

    InitializeCategory57Screen();

    mmi_uc_done_fill_inline_struct(image_list);
    RegisterHighlightHandler(mmi_uc_done_highlight_hdlr);

    inputBuffer = GetCurrNInputBuffer(SCR_ID_UC_OPT_DONE, &inputBufferSize); /* added for inline edit history */

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, MMI_UC_DONE_TOTAL_NUM, inputBuffer);      /* sets the data */
    }
    
    DisableCategory57ScreenDone();

    /* reset */
    g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
    g_uc_p->send_info.abort = MMI_UC_ABORT_NONE;

    ShowCategory57Screen(
        title_id,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        0,
        0,
        STR_GLOBAL_DONE,
        0,
        items_num,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_uc_entry_done_option, mmi_uc_entry_done_option);
    SetDelScrnIDCallbackHandler(SCR_ID_UC_OPT_DONE, (HistoryDelCBPtr) mmi_uc_done_delete_history_hdlr);

    StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_handle_msg_type_check);

    g_uc_p->send_info.curr_folder = (U16)mmi_um_get_current_msg_box_type();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_done_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_uc_done_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/               
    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
        g_uc_p->main.state == MMI_UC_STATE_SEND)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_done_delete_history_hdlr *\n"); 
        
        MMI_ASSERT(IsScreenPresent(SCR_ID_UC_EDITOR) != MMI_TRUE);

        if (g_uc_p->send_info.action == MMI_UC_ACTION_IDLE)
        {
            mmi_uc_reset_msg();
        }
        else
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_done_delete_history_hdlr Do Nothing *\n");    
            
            /* Disable following actions in mmi_uc_action_fsm() */
            //g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
        }        
    }
    return FALSE;
}

#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
void mmi_uc_goback_to_option_done(void)
{
    GoBackToHistory(SCR_ID_UC_OPT_DONE);
}


/*****************************************************************************
 * FUNCTION
 *   mmi_uc_input_method_and_done_go_back_to_option
 * DESCRIPTION
 *  Control return to subject editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_input_method_and_done_go_back_to_option(void)
{
    g_uc_p->msg.msg_size = wap_mma_uc_calc_msg_size(&g_uc_p->msg); 

    if (mmi_uc_check_if_exceed_MMS_size_limitation(g_uc_p->msg.msg_size))
    {
        memset(g_uc_p->msg.subject, 0, MMI_UC_MAX_SUBJECT_LEN + 1); 
        mmi_uc_update_msg_size();
        DisplayPopupCallBack(
        (PU8) GetString(STR_UC_MSG_SIZE_EXCEED_ID),
        IMG_GLOBAL_UNFINISHED,
        1,
        MMI_UC_POPUP_TIME_OUT,
        (U8) ERROR_TONE,
        mmi_uc_goback_to_option_done);
    }
    else
    {
        mmi_uc_update_msg_size();
        GoBackToHistory(SCR_ID_UC_OPT_DONE);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_input_method_and_done_hilite_handler
 * DESCRIPTION
 *  Highlighter to options on subject editor
 * PARAMETERS
 *  index       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_input_method_and_done_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index == 0)
	{
	
		ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
		ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
		SetLeftSoftkeyFunction(mmi_uc_input_method_and_done_go_back_to_option, KEY_EVENT_UP);
		SetKeyHandler(mmi_uc_input_method_and_done_go_back_to_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
		SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	}
	else
	{
		mmi_frm_highlight_input_method_generic();
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_edit_subject
 * DESCRIPTION
 *  Entry function of option menu after editing subject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_input_method_and_done(void)
{
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;
    EntryNewScreen(SCR_INPUT_METHOD_AND_DONE, NULL, mmi_uc_entry_input_method_and_done, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_AND_DONE);
    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    RegisterHighlightHandler(mmi_uc_input_method_and_done_hilite_handler);
    numItems = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_edit_subject
 * DESCRIPTION
 *  Entry function of editing subject field
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_edit_subject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_SUBJECT_EDITOR, NULL, mmi_uc_entry_edit_subject, NULL);
    gui_buffer_p = GetCurrGuiBuffer(SCR_ID_UC_SUBJECT_EDITOR);
    ShowCategory215Screen(
        STR_UC_SUBJECT_ID,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (PU8) g_uc_p->msg.subject,
        MMI_UC_MAX_SUBJECT_LEN + 1,
        gui_buffer_p);

    SetLeftSoftkeyFunction(mmi_uc_entry_input_method_and_done, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    
}
#endif /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_done_highlight_hdlr
 * DESCRIPTION
 *  Highligth handler for done menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_done_highlight_hdlr(S32 index)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->done.current_addr_index = 0;
    
    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        switch (index)
        {
            case MMI_UC_DONE_SMS_ONLY_TO:
            {
                g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_TO;
                if (g_uc_p->msg.to_num == 0)
                {
                    if ((g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num ) >= MMI_UC_MAX_ADDRESS_NUM)
                    {
                        ChangeLeftSoftkey(0, 0);
                    }
                    else
                    {            
                        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);                                    
                        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_option);
                    }
                }
                /* Do not allow to edit to field if reply SMS msg. */
                else if (g_uc_p->main.state == MMI_UC_STATE_REPLY &&
                         g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                {
                    ChangeLeftSoftkey(0, 0);
                }
                else
                {
                    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);            
                    SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_list);
                }            
            }
            break;            

            case MMI_UC_DONE_SMS_ONLY_MSG_DETAIL_CAPTION:
            {
                ChangeLeftSoftkey(STR_GLOBAL_VIEW, 0);
                SetCategory57LeftSoftkeyFunction(mmi_uc_entry_msg_detail);
            }
            break;

            default:
            {
                MMI_ASSERT(0);
            }
            break;
        }        
    }
    else
    {
        switch (index)
        {
            case MMI_UC_DONE_TO:
            {
                g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_TO;
                if (g_uc_p->msg.to_num == 0)
                {
                    if ((g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num ) >= MMI_UC_MAX_ADDRESS_NUM)
                    {
                        ChangeLeftSoftkey(0, 0);
                    }
                    else
                    {            
                        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);            
                        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_option);
                    }
                }
                /* Do not allow to edit to field if reply SMS msg. */
                else if (g_uc_p->main.state == MMI_UC_STATE_REPLY &&
                         g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                {
                    ChangeLeftSoftkey(0, 0);
                }
                else
                {
                    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);            
                    SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_list);
                }            
            }
            break;
            
            case MMI_UC_DONE_CC:
            {
                g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_CC;

                if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
                {
                    ASSERT(0);
                }
                else
                {
                    if (g_uc_p->msg.cc_num == 0)
                    {                
                        if ((g_uc_p->msg.to_num + g_uc_p->msg.bcc_num ) >= MMI_UC_MAX_ADDRESS_NUM)
                        {
                            ChangeLeftSoftkey(0, 0);
                        }
                        else
                        {            
                            ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                            SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_option);
                        }
                        
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_list);
                    }
                }
            }
            break;
            
            case MMI_UC_DONE_BCC:
            {
                g_uc_p->done.current_addr_type = MMI_UC_ADDRESS_GROUP_TYPE_BCC;

                if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
                {
                    ASSERT(0);
                }
                else
                {
                    if (g_uc_p->msg.bcc_num == 0)
                    {                
                        if ((g_uc_p->msg.to_num + g_uc_p->msg.cc_num ) >= MMI_UC_MAX_ADDRESS_NUM)
                        {
                            ChangeLeftSoftkey(0, 0);
                        }
                        else
                        {     
                            ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                            SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_option);
                        }
                        
                    }
                    else
                    {
                        ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
                        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_addr_list);
                    }            
                }
            }
            break;

            case MMI_UC_DONE_SUBJECT:
            {
                if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
                {
                    ASSERT(0);
                }
                else
                {
                    ChangeLeftSoftkey(STR_GLOBAL_EDIT, 0);
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__ 
                    SetCategory57LeftSoftkeyFunction(mmi_uc_entry_edit_subject);
#endif
                }
            }
            break;

            case MMI_UC_DONE_MSG_DETAIL_CAPTION:
            {
                ChangeLeftSoftkey(STR_GLOBAL_VIEW, 0);
                SetCategory57LeftSoftkeyFunction(mmi_uc_entry_msg_detail);
            }
            break;

            default:
            {
                MMI_ASSERT(0);
            }
            break;
        }    
    }
    
    ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
}


#ifdef __MMI_UC_SUB_PREFIX_MMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_add_prefix_before_subject
 * DESCRIPTION
 *  Add prefix RE: for reply msg and FW: for forward msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_add_prefix_before_subject(void)
{
    U8 prefix_buff[10]; /*ASCII*/
    U16 subject_buff[MMI_UC_MAX_SUBJECT_LEN + 1]; /*UCS2*/
    int prefix_char_num = 0;
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*---[UnifiedComposerMain.c] mmi_uc_add_prefix_before_subject ---*\n");
    if ( (MMI_UC_STATE_FORWARD != g_uc_p->main.state) && 
         (MMI_UC_STATE_REPLY != g_uc_p->main.state) &&
         (MMI_UC_STATE_REPLY_ALL != g_uc_p->main.state) )
    {
        return;
    }
    
    memset(prefix_buff, 0, sizeof(prefix_buff));
    memset(subject_buff, 0, sizeof(subject_buff));

    mmi_ucs2ncpy((S8*)subject_buff, (S8*)g_uc_p->msg.subject, MMI_UC_MAX_SUBJECT_LEN);

    if (MMI_UC_STATE_FORWARD == g_uc_p->main.state)
    {  
        sprintf((char*)prefix_buff, "%s ", "Fw:");
    }
    else
    {
        sprintf((char*)prefix_buff, "%s ", "Re:");
    }
    memset(g_uc_p->msg.subject, 0, sizeof(g_uc_p->msg.subject));
    mmi_asc_to_ucs2((S8*)g_uc_p->msg.subject, (S8*)prefix_buff);
    prefix_char_num = mmi_ucs2strlen((PS8)g_uc_p->msg.subject);
    mmi_ucs2ncat((S8*) g_uc_p->msg.subject, 
                              (const S8*)subject_buff, 
                              MMI_UC_MAX_SUBJECT_LEN - prefix_char_num);
    
    return;
}
#endif

#ifndef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__

void mmi_uc_subject_edit_complete_callback(U8 *string, S32 buffer_size)
{
    g_uc_p->msg.msg_size = wap_mma_uc_calc_msg_size(&g_uc_p->msg); 

    if (mmi_uc_check_if_exceed_MMS_size_limitation(g_uc_p->msg.msg_size))
    {
        memset(g_uc_p->msg.subject, 0, MMI_UC_MAX_SUBJECT_LEN + 1); 
        mmi_uc_update_msg_size();
        mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
    }
    else
    {
        mmi_uc_update_msg_size();
    }
    return;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_done_fill_inline_struct
 * DESCRIPTION
 *  Fill inline item of done menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_done_fill_inline_struct(U16* image_list)
{
    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        image_list[MMI_UC_DONE_SMS_ONLY_TO_CAPTION] = IMG_UC_TO_ID;
        image_list[MMI_UC_DONE_SMS_ONLY_TO] = 0;
        image_list[MMI_UC_DONE_SMS_ONLY_MSG_DETAIL_CAPTION] = IMG_UC_MSG_DETAIL_ID;
    }
    else
    {
        image_list[MMI_UC_DONE_TO_CAPTION] = IMG_UC_TO_ID;
        image_list[MMI_UC_DONE_TO] = 0;    
        image_list[MMI_UC_DONE_CC_CAPTION] = IMG_UC_CC_ID;
        image_list[MMI_UC_DONE_CC] = 0;
        image_list[MMI_UC_DONE_BCC_CAPTION] = IMG_UC_BCC_ID;
        image_list[MMI_UC_DONE_BCC] = 0;
        image_list[MMI_UC_DONE_SUBJECT_CAPTION] = IMG_UC_SUBJECT_ID;
        image_list[MMI_UC_DONE_SUBJECT] = 0;
        image_list[MMI_UC_DONE_MSG_DETAIL_CAPTION] = IMG_UC_MSG_DETAIL_ID;
    }

    /* To caption */
    SetInlineItemCaption(&wgui_inline_items[MMI_UC_DONE_TO_CAPTION], (U8*) GetString(STR_UC_TO_ID));

    /* To address */
    //SetInlineItemActivation(&wgui_inline_items[MMI_UC_DONE_TO], KEY_LSK, KEY_EVENT_UP);
    memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);

    if (g_uc_p->msg.to_num == 0)
    {
        /* display empty in the field */
    }
    else if (g_uc_p->msg.to_num == 1)
    {
        if (g_uc_p->msg.to_head->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
        {                
            S8 *name = NULL;
            S8 temp[(MMI_UC_MAX_PHONE_NUMBER_LEN+ 1) * ENCODING_LENGTH];

            memset(temp, 0, sizeof(temp));
            mmi_asc_to_ucs2(temp, (S8*) g_uc_p->msg.to_head->addr);

            if (strlen((S8*)g_uc_p->msg.to_head->addr) <= (MAX_PB_NUMBER_LENGTH + 1))
            {
                name = lookUpNumber(temp);
            }
            if (name != NULL && mmi_ucs2strlen(name) > 0)
            {
                mmi_ucs2ncpy((S8*) g_uc_p->done.to, name, MMI_UC_MAX_PHONE_NUMBER_LEN);
            }
            else
            {
                mmi_ucs2ncpy((S8*) g_uc_p->done.to, temp, MMI_UC_MAX_PHONE_NUMBER_LEN);
            }
        }
        else if (g_uc_p->msg.to_head->type == MMI_UC_ADDRESS_TYPE_EMAIL)
        {
            mmi_ucs2ncpy((S8*) g_uc_p->done.to,(S8*) g_uc_p->msg.to_head->addr, MMI_UC_MAX_EMAIL_LEN);
        }
        else
        {
            MMI_ASSERT(0);
        }        
    }
    else
    {
        U8 ascii_recipient_number[16];

        memset(ascii_recipient_number, 0, sizeof(ascii_recipient_number));
        sprintf((char*)ascii_recipient_number, "%d ", g_uc_p->msg.to_num);

        mmi_asc_to_ucs2((PS8) g_uc_p->done.to, (PS8) ascii_recipient_number);

        mmi_ucs2ncat((S8*) g_uc_p->done.to, 
                          (const S8*)GetString(STR_UC_RECIPIENTS_ID), 
                          MMI_UC_MAX_EMAIL_LEN - mmi_ucs2strlen((PS8) GetString(STR_UC_RECIPIENTS_ID)));        
    }
    SetInlineItemDisplayOnly(&wgui_inline_items[MMI_UC_DONE_TO], (U8*) (g_uc_p->done.to));


    if (g_uc_p->msg_type.caller_specific_msg_type != MMI_UC_MSG_TYPE_SMS_ONLY)
    {

        /* Cc caption */
        SetInlineItemCaption(&wgui_inline_items[MMI_UC_DONE_CC_CAPTION], (U8*) GetString(STR_UC_CC_ID));

        /* Cc address */
        //SetInlineItemActivation(&wgui_inline_items[MMI_UC_DONE_CC], KEY_LSK, KEY_EVENT_UP);
        memset(g_uc_p->done.cc, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);

        if (g_uc_p->msg.cc_num == 0)
        {
            /* display empty in the field */
        }
        else if (g_uc_p->msg.cc_num == 1)
        {
            if (g_uc_p->msg.cc_head->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
            {                
                S8 *name = NULL;
                S8 temp[(MMI_UC_MAX_PHONE_NUMBER_LEN + 1) * ENCODING_LENGTH];

                memset(temp, 0, sizeof(temp));
                mmi_asc_to_ucs2(temp, (S8*) g_uc_p->msg.cc_head->addr);

                if (strlen((S8*)g_uc_p->msg.cc_head->addr) <= (MAX_PB_NUMBER_LENGTH + 1))
                {
                    name = lookUpNumber(temp);
                }
                if (name != NULL && mmi_ucs2strlen(name) > 0)
                {
                    mmi_ucs2ncpy((S8*) g_uc_p->done.cc, name, MMI_UC_MAX_PHONE_NUMBER_LEN);
                }
                else
                {
                    mmi_ucs2ncpy((S8*) g_uc_p->done.cc, temp, MMI_UC_MAX_PHONE_NUMBER_LEN);
                }
            }
            else if (g_uc_p->msg.cc_head->type == MMI_UC_ADDRESS_TYPE_EMAIL)
            {
                mmi_ucs2ncpy((S8*) g_uc_p->done.cc, (S8*)g_uc_p->msg.cc_head->addr, MMI_UC_MAX_EMAIL_LEN);
            }
            else
            {
                MMI_ASSERT(0);
            }        
        }
        else
        {
            U8 ascii_recipient_number[16];

            memset(ascii_recipient_number, 0, sizeof(ascii_recipient_number));
            sprintf((char*)ascii_recipient_number, "%d ", g_uc_p->msg.cc_num);

            mmi_asc_to_ucs2((PS8) g_uc_p->done.cc, (PS8) ascii_recipient_number);

            mmi_ucs2ncat((S8*) g_uc_p->done.cc, 
                              (const S8*)GetString(STR_UC_RECIPIENTS_ID), 
                              MMI_UC_MAX_EMAIL_LEN - mmi_ucs2strlen((PS8) GetString(STR_UC_RECIPIENTS_ID)));        
        }
        SetInlineItemDisplayOnly(&wgui_inline_items[MMI_UC_DONE_CC], (U8*) (g_uc_p->done.cc));

        /* Bcc caption */
        SetInlineItemCaption(&wgui_inline_items[MMI_UC_DONE_BCC_CAPTION], (U8*) GetString(STR_UC_BCC_ID));

        /* Bcc address */
        //SetInlineItemActivation(&wgui_inline_items[MMI_UC_DONE_BCC], KEY_LSK, KEY_EVENT_UP);
        memset(g_uc_p->done.bcc, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);

        if (g_uc_p->msg.bcc_num == 0)
        {
            /* display empty in the field */
        }
        else if (g_uc_p->msg.bcc_num == 1)
        {
            if (g_uc_p->msg.bcc_head->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
            {                
                S8 *name = NULL;
                S8 temp[(MMI_UC_MAX_PHONE_NUMBER_LEN + 1) * ENCODING_LENGTH];

                memset(temp, 0, sizeof(temp));
                mmi_asc_to_ucs2(temp, (S8*) g_uc_p->msg.bcc_head->addr);

                if (strlen((S8*)g_uc_p->msg.bcc_head->addr) <= (MAX_PB_NUMBER_LENGTH + 1))
                {
                    name = lookUpNumber(temp);
                }
                if (name != NULL && mmi_ucs2strlen(name) > 0)
                {
                    mmi_ucs2ncpy((S8*) g_uc_p->done.bcc, name, MMI_UC_MAX_PHONE_NUMBER_LEN);
                }
                else
                {
                    mmi_ucs2ncpy((S8*) g_uc_p->done.bcc, temp, MMI_UC_MAX_PHONE_NUMBER_LEN);
                }
            }
            else if (g_uc_p->msg.bcc_head->type == MMI_UC_ADDRESS_TYPE_EMAIL)
            {
                mmi_ucs2ncpy((S8*) g_uc_p->done.bcc, (S8*) g_uc_p->msg.bcc_head->addr, MMI_UC_MAX_EMAIL_LEN);
            }
            else
            {
                MMI_ASSERT(0);
            }        
        }
        else
        {
            U8 ascii_recipient_number[16];

            memset(ascii_recipient_number, 0, sizeof(ascii_recipient_number));
            sprintf((char*) ascii_recipient_number, "%d ", g_uc_p->msg.bcc_num);

            mmi_asc_to_ucs2((PS8) g_uc_p->done.bcc, (PS8) ascii_recipient_number);

            mmi_ucs2ncat((S8*) g_uc_p->done.bcc, 
                              (const S8*)GetString(STR_UC_RECIPIENTS_ID), 
                              MMI_UC_MAX_EMAIL_LEN - mmi_ucs2strlen((PS8) GetString(STR_UC_RECIPIENTS_ID)));        
        }
        SetInlineItemDisplayOnly(&wgui_inline_items[MMI_UC_DONE_BCC], (U8*) (g_uc_p->done.bcc));

        /* Subject caption */
        SetInlineItemCaption(&wgui_inline_items[MMI_UC_DONE_SUBJECT_CAPTION], (U8*) GetString(STR_UC_SUBJECT_ID));
       
        /* Subject */
       
        /*Add prefix RE: for reply msg and FW: for forward msg*/
        /*Only add that for MMS, because SMS has no subject*/
#ifdef __MMI_UC_SUB_PREFIX_MMS__        
        if (MMI_UC_MSG_TYPE_MMS_PREFER == g_uc_p->msg_type.curr_msg_type)
        {
            mmi_uc_add_prefix_before_subject(); 
        }
#endif        
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
        
        SetInlineItemDisplayOnly(&wgui_inline_items[MMI_UC_DONE_SUBJECT], (U8*) (g_uc_p->msg.subject));
#else     
        SetInlineItemActivation(&wgui_inline_items[MMI_UC_DONE_SUBJECT], KEY_LSK, KEY_EVENT_UP);
        
        SetInlineItemFullScreenEdit(
            &wgui_inline_items[MMI_UC_DONE_SUBJECT],
            STR_UC_SUBJECT_ID,
            IMG_UC_ENTRY_SCRN_CAPTION_ID,
            (PU8) g_uc_p->msg.subject,
            MMI_UC_MAX_SUBJECT_LEN + 1,
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
        
        SetInlineFullScreenEditCustomFunction(
            &wgui_inline_items[MMI_UC_DONE_SUBJECT],
            mmi_uc_inline_generic_custom_function);
        RegisterInlineTextEditCompleteHandler(&wgui_inline_items[MMI_UC_DONE_SUBJECT], mmi_uc_subject_edit_complete_callback);
#endif
    }

    /* Message detail caption */
    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        //SetInlineItemActivation(&wgui_inline_items[MMI_UC_DONE_SMS_ONLY_MSG_DETAIL_CAPTION], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemDisplayOnly(&wgui_inline_items[MMI_UC_DONE_SMS_ONLY_MSG_DETAIL_CAPTION], (U8*)GetString(STR_UC_MESSAGE_DETAIL_ID));    
    }
    else
    {
        //SetInlineItemActivation(&wgui_inline_items[MMI_UC_DONE_MSG_DETAIL_CAPTION], KEY_LSK, KEY_EVENT_UP);
        SetInlineItemDisplayOnly(&wgui_inline_items[MMI_UC_DONE_MSG_DETAIL_CAPTION], (U8*)GetString(STR_UC_MESSAGE_DETAIL_ID));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_inline_generic_custom_function
 * DESCRIPTION
 *  Set LSK handle for inline full screen edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_inline_generic_custom_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInputMethodAndDoneCaptionIcon(IMG_UC_ENTRY_SCRN_CAPTION_ID);
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_done
 * DESCRIPTION
 *  Exit function of done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_UC_OPT_DONE;
    currHistory.entryFuncPtr = mmi_uc_entry_done;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_done_option
 * DESCRIPTION
 *  Entry function for done option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_done_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 title_id = STR_GLOBAL_OPTIONS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_DONE_OPT, mmi_uc_exit_generic, mmi_uc_entry_done_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_done_option *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE_OPT);

    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
    {    
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SAVE);
        
    #if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE);
    #endif /* __MMI_MMS_2__ */        

        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_BACK_TO_EDIT_MSG);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_EXIT);

        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SEND_OPT);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_SEND_OPT);
        }

        if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY ||
            g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_MMS_ONLY ||
            mmi_uc_determine_msg_type_by_content() == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_MSG_TYPE);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_MSG_TYPE);
        }
    }
    else if (g_uc_p->main.state == MMI_UC_STATE_SEND)
    {    
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SAVE);
        
    #if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE);
    #endif /* __MMI_MMS_2__ */                
    
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_BACK_TO_EDIT_MSG);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_EXIT);
        
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SEND_OPT);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_SEND_OPT);
        }

        if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY ||
            g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_MMS_ONLY ||
            mmi_uc_determine_msg_type_by_content() == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_MSG_TYPE);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_MSG_TYPE);
        }
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_SAVE);
        
    #if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SAVE_AS_TEMPLATE);
        } 
    #endif /* __MMI_MMS_2__ */          
    
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_BACK_TO_EDIT_MSG);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_MSG_TYPE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SEND_OPT);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_EXIT);    
    }
    
    /*Decide to show SEND_AND_SAVE in option menu or not*/ 
    {
        MMI_BOOL Hide_send_and_save = MMI_FALSE;
#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
        if ( g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER )
        {
            Hide_send_and_save = MMI_TRUE;
        }
#endif /* __MMI_MMS_2__ || __MMI_MMS_BGSR_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            Hide_send_and_save = MMI_TRUE;
        } 
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
        if (MMI_FALSE == Hide_send_and_save)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_DONE_SEND_AND_SAVE);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_DONE_SEND_AND_SAVE);
        }
    }
    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT_DONE_OPT);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT_DONE_OPT, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT_DONE_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        title_id,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_back_to_edit
 * DESCRIPTION
 *  Process back to editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_back_to_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UC_EDITOR))
    {
        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_exit
 * DESCRIPTION
 *  Process Exit msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (GetPreviousScrnIdOf(SCR_ID_UC_OPT_DONE, &screen_id))
    {
        mmi_uc_reset_msg();
        GoBackToHistory(screen_id);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_send_cancel
 * DESCRIPTION
 *  Process send cancel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_send_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UC_EDITOR))
    {
        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
    else
    {
        GoBackHistory();
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_mms_size_confirm_send
 * DESCRIPTION
 *  Process mms size confirmation before send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_mms_size_confirm_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 * pstr1, *pstr2 ;
    S8  *message;
    U32 temp_string_len = 12;
    U8 temp_string[12];
    U8 temp_ucs2_string[12 * ENCODING_LENGTH];
    FLOAT mms_size = 0;
    int msg_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    pstr1 = GetString(STR_UC_MMS_SIZE_CONFIRM_MSG_1);
    pstr2 = GetString(STR_UC_MMS_SIZE_CONFIRM_MSG_2);
    msg_size = (mmi_ucs2strlen(pstr1) + mmi_ucs2strlen(pstr2) + temp_string_len) * 2;
    message = (S8 *)OslMalloc(msg_size);

    mmi_ucs2cpy(message, pstr1);

    mms_size = (FLOAT)g_uc_p->msg.msg_size / (FLOAT) 1024.0;
    sprintf((char*)temp_string, " %.1f ", mms_size);
    mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
    mmi_ucs2cat(message, (S8*)temp_ucs2_string);

    mmi_ucs2cat(message, pstr2);

    DisplayConfirm(STR_GLOBAL_YES, 
                    0, 
                    STR_GLOBAL_NO, 
                    0, 
                    (UI_string_type)message,
                    IMG_GLOBAL_QUESTION, 
                    WARNING_TONE);

    OslMfree(message);
    /* Set the key handlers */
    SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_uc_process_send_cancel, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_mms_size_confirm_send_and_save
 * DESCRIPTION
 *  Process mms size confirmation before send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_mms_size_confirm_send_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 * pstr1, *pstr2 ;
    S8  *message;
    U32 temp_string_len = 12;
    U8 temp_string[12];
    U8 temp_ucs2_string[12 * ENCODING_LENGTH];
    FLOAT mms_size = 0;
    int msg_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    pstr1 = GetString(STR_UC_MMS_SIZE_CONFIRM_MSG_1);
    pstr2 = GetString(STR_UC_MMS_SIZE_CONFIRM_MSG_2);
    msg_size = (mmi_ucs2strlen(pstr1) + mmi_ucs2strlen(pstr2) + temp_string_len) * 2;
    message = (S8 *)OslMalloc(msg_size);

    mmi_ucs2cpy(message, pstr1);

    mms_size = (FLOAT)g_uc_p->msg.msg_size / (FLOAT) 1024.0;
    sprintf((char*)temp_string, " %.1f ", mms_size);
    mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
    mmi_ucs2cat(message, (S8*)temp_ucs2_string);

    mmi_ucs2cat(message, pstr2);

    DisplayConfirm(STR_GLOBAL_YES, 
                    0, 
                    STR_GLOBAL_NO, 
                    0, 
                    (UI_string_type)message,
                    IMG_GLOBAL_QUESTION, 
                    WARNING_TONE);

    OslMfree(message);
    /* Set the key handlers */
    SetLeftSoftkeyFunction(mmi_uc_process_send_and_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_uc_process_send_cancel, KEY_EVENT_UP);
}
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_send
 * DESCRIPTION
 *  Process Send msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        if (g_uc_p->msg.to_num == 0)
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_NO_RECEPIENT_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);            
        }
    #ifdef __MMI_MMS_2__
        else if (MMI_FALSE == mmi_uc_check_number_length_for_sms())
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_ADDR_LENGTH_EXCEED_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
        }
    #endif /* #ifdef __MMI_MMS_2__ */
        else
        {
            g_uc_p->send_info.action = MMI_UC_ACTION_SEND;    
            g_uc_p->send_info.curr_send_number = 0;
            mmi_uc_send_sms();
        }    
    }
    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        if (g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num  == 0)
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_NO_RECEPIENT_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);            
        }
        else
        {
        #if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
            g_uc_p->send_info.action = MMI_UC_ACTION_SEND_IN_BACKGROUND;
        #else /* __MMI_MMS_2__ */
            g_uc_p->send_info.action = MMI_UC_ACTION_SEND;
        #endif /* __MMI_MMS_2__ */
            
            mmi_uc_create_mms();
        }        
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_send
 * DESCRIPTION
 *  Process Send msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_send_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /*If background sending is enable for sms, this case should not happen*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        MMI_ASSERT(0);        
    }
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/

    /*If background sending is enable for mms, this case should not happen*/
#if defined(__MMI_MMS_BGSR_SUPPORT__)
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        MMI_ASSERT(0);        
    }
#endif
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        if (g_uc_p->msg.to_num == 0)
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_NO_RECEPIENT_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);            
        }
    #ifdef __MMI_MMS_2__
        else if (MMI_FALSE == mmi_uc_check_number_length_for_sms())
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_ADDR_LENGTH_EXCEED_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
        }
    #endif /* #ifdef __MMI_MMS_2__ */
        else
        {
            g_uc_p->send_info.action = MMI_UC_ACTION_SEND_AND_SAVE;    
            g_uc_p->send_info.curr_send_number = 0;
            mmi_uc_send_sms();
        }    
    }
    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        if (g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num  == 0)
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_NO_RECEPIENT_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);            
        }
        else
        {
            g_uc_p->send_info.action = MMI_UC_ACTION_SEND_AND_SAVE;
            mmi_uc_create_mms();
        }        
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_save
 * DESCRIPTION
 *  Process Save msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UmMsgBoxType msg_box = mmi_um_get_current_msg_box_type();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MMS_2__
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        if (g_uc_p->msg.to_num > 0)
        {
             if (MMI_FALSE == mmi_uc_check_number_length_for_sms())
             {
                DisplayPopup(
                        (PU8) GetString(STR_UC_ADDR_LENGTH_EXCEED_ID),
                        IMG_GLOBAL_ERROR,
                        1,
                        MMI_UC_POPUP_TIME_OUT,
                        (U8) ERROR_TONE);
                return;
             }
         }
    }
#endif /* #ifdef __MMI_MMS_2__ */
    
    g_uc_p->send_info.action = MMI_UC_ACTION_SAVE;
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        if (msg_box == UM_MSG_BOX_TYPE_DRAFT)
        {
            mmi_uc_set_processing_screen(
                        STR_GLOBAL_SAVING, 
                        STR_UC_PLEASE_WAIT_ID, 
                        IMG_GLOBAL_PROGRESS, 
                        0);
            
            mmi_uc_entry_processing_generic();

            /* save msg from SMS to SMS. Delete original one and then save new one. (for more free size)*/
            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
            {
                mmi_frm_sms_delete_sms(
                    mmi_uc_delete_sms_callback, 
                    MOD_MMI, 
                    MMI_FRM_SMS_DRAFTS, 
                    (U16)g_uc_p->send_info.existed_msg_id );
            }
            /* save msg from MMS to SMS. Save new one and then delete original one. */
            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                mmi_uc_save_sms_req();
                
            }
            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_DEFAULT)
            {
                /*this flow will happen --> when select sms in draft-->use number -->send sms (edit)-->done
                  -->done->save, in this case, existed_msg_type= MMI_UC_MSG_TYPE_DEFAULT;
                */
                mmi_uc_save_sms_req();

            }
            else
            {
                MMI_ASSERT(0);
            }            

            mmi_um_set_highlight_msg(0);
        }
        else if (msg_box == UM_MSG_BOX_TYPE_UNSENT && g_uc_p->msg.to_num > 0)
        {
            mmi_uc_set_processing_screen(
                        STR_GLOBAL_SAVING, 
                        STR_UC_PLEASE_WAIT_ID, 
                        IMG_GLOBAL_PROGRESS, 
                        0);
            
            mmi_uc_entry_processing_generic();

           /* save msg from SMS to SMS. Delete original one and then save new one. */
            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
            {
                mmi_frm_sms_delete_sms(
                    mmi_uc_delete_sms_callback, 
                    MOD_MMI, 
                    MMI_FRM_SMS_UNSENT, 
                    (U16)g_uc_p->send_info.existed_msg_id );
            }
            /* save msg from MMS to SMS. Save new one and then delete original one. */
            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                mmi_uc_save_sms_req();
            }
            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_DEFAULT)
            {
                /*this flow will happen --> when select sms in draft-->use number -->send sms (edit)-->done
                  -->done->save, in this case, existed_msg_type= MMI_UC_MSG_TYPE_DEFAULT;
                */
                mmi_uc_save_sms_req();

            }
            else
            {
                MMI_ASSERT(0);
            }            

            mmi_um_set_highlight_msg(0);
        }
        else
        {    
            mmi_uc_save_sms();
        }
    }
    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        /* The original mms msg would be deleted after mms creation if it belongs to draft folder */    
        mmi_uc_create_mms();
    }
    else
    {
        MMI_ASSERT(0);
    }

}


#if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_save_as_template
 * DESCRIPTION
 *  Process Save as template msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    g_uc_p->send_info.action = MMI_UC_ACTION_SAVE_AS_TEMPLATE;
    
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER )
    {        
        mmi_uc_create_mms();
    }
    else
    {
        MMI_ASSERT(0);
    }

}
#endif /* __MMI_MMS_2__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_sms
 * DESCRIPTION
 *  Send SMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__   
    mmi_uc_set_processing_screen(STR_UC_CREATING_ID, STR_UC_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0);
    mmi_uc_entry_processing_generic();
#else
    mmi_uc_entry_sending_sms();
#endif
    /*When backgournd sending is enabled, the api only handles the first step- save*/
    mmi_uc_send_sms_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_sms
 * DESCRIPTION
 *  Send SMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_set_processing_screen(
                STR_GLOBAL_SAVING, 
                STR_UC_PLEASE_WAIT_ID, 
                IMG_GLOBAL_PROGRESS, 
                0);
    
    mmi_uc_entry_processing_generic();        
    mmi_uc_save_sms_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_sms_req
 * DESCRIPTION
 *  Send SMS msg
 * Note: if enable background sending, this api only handle "save", not send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_sms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = NULL;
    mmi_uc_addr_struct* addr;
    U8 *handled_buffer = NULL;
    U16 handled_buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

    if (g_uc_p->send_info.curr_send_number == 0)
    {        
        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);

        if (g_uc_p->msg.current_slide->text.UCS2_count)
        {
            sendData->dcs = SMSAL_UCS2_DCS;

            handled_buffer_size = ( g_uc_p->msg.current_slide->text.char_count + 1) * ENCODING_LENGTH;

            MMI_ASSERT( handled_buffer_size <= MMI_UC_UTF8_TEXT_BUFFER_SIZE);

            handled_buffer = (U8*)applib_mem_screen_alloc((U16)handled_buffer_size);            
            memset((S8*) handled_buffer, 0, handled_buffer_size);
            memcpy((S8*) handled_buffer, 
                   (S8*) g_uc_p->main.text_buffer, 
                   g_uc_p->msg.current_slide->text.char_count * ENCODING_LENGTH);
            
        }
        else
        {
            sendData->dcs = SMSAL_DEFAULT_DCS;
            
            handled_buffer_size = ( g_uc_p->msg.current_slide->text.char_count + 
                                    g_uc_p->msg.current_slide->text.extension_char_count 
                                    + 1) * ENCODING_LENGTH;

            MMI_ASSERT( handled_buffer_size <= MMI_UC_UTF8_TEXT_BUFFER_SIZE);
        
            handled_buffer = (U8*)applib_mem_screen_alloc(handled_buffer_size);
            memset((S8*) handled_buffer, 0, handled_buffer_size);
            
            
            mmi_frm_sms_add_escape_symbol_for_extension_char(
                (U16*) handled_buffer,
                (U16*) g_uc_p->main.text_buffer,
                g_uc_p->msg.current_slide->text.char_count);
        }     

        MMI_ASSERT(mmi_frm_sms_fill_in_edit_buffer(handled_buffer, 
                                                   (U16)((handled_buffer_size / ENCODING_LENGTH) - 1), 
                                                   sendData->dcs, 
                                                   MMI_TRUE));

        applib_mem_screen_free(handled_buffer);
    }
    
    addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);

    strncpy((S8*) sendData->number, (S8*) addr->addr,MAX_DIGITS_SMS - 1);

    sendData->sendrequire |= MMI_FRM_SMS_SAVE_AFTER_FAIL;

    if (g_uc_p->main.state == MMI_UC_STATE_REPLY &&
        g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        sendData->sendrequire |= MMI_FRM_SMS_REPLY;

        sendData->replyindex = (U16)g_uc_p->send_info.existed_msg_id;
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    sendData->sendrequire |= MMI_FRM_SMS_BACKGROUND_SEND;
#endif    
    sendData->sendcheck |= MMI_FRM_SMS_SCR;

    mmi_frm_sms_send_sms(mmi_uc_send_sms_rsp, MOD_MMI, sendData);
    OslMfree(sendData);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_sms_rsp
 * DESCRIPTION
 *  Send SMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_sms_rsp(void *number, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*When background sending is enabled, rsp ok just means first step(save) ok*/
    if (result == MMI_FRM_SMS_OK)
    {
        g_uc_p->send_info.curr_send_number++;
        if (g_uc_p->send_info.curr_send_number < g_uc_p->msg.to_num)
        {
            mmi_uc_send_sms_req();
            return;
        }
    }

    g_uc_p->send_info.send_result = result;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_frm_sms_background_send_schedule();
#endif
    mmi_uc_action_fsm(MMI_UC_ACTION_SEND, result);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_sms_req
 * DESCRIPTION
 *  save SMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_sms_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct *sendData = NULL;
    mmi_uc_addr_struct* addr;
    U8 *handled_buffer = NULL;
    U16 handled_buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sendData = OslMalloc(sizeof(mmi_frm_sms_send_struct));
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);

    if (g_uc_p->msg.current_slide->text.UCS2_count)
    {
        sendData->dcs = SMSAL_UCS2_DCS;

        handled_buffer_size = ( g_uc_p->msg.current_slide->text.char_count + 1) * ENCODING_LENGTH;

        MMI_ASSERT( handled_buffer_size <= MMI_UC_UTF8_TEXT_BUFFER_SIZE);
        
        handled_buffer = (U8*)applib_mem_screen_alloc(handled_buffer_size);        
        memset((S8*) handled_buffer, 0, handled_buffer_size);
        memcpy((S8*) handled_buffer, 
               (S8*) g_uc_p->main.text_buffer, 
               g_uc_p->msg.current_slide->text.char_count * ENCODING_LENGTH);
        
    }
    else
    {
        sendData->dcs = SMSAL_DEFAULT_DCS;
        
        handled_buffer_size = ( g_uc_p->msg.current_slide->text.char_count + 
                                g_uc_p->msg.current_slide->text.extension_char_count 
                                + 1) * ENCODING_LENGTH;

        MMI_ASSERT( handled_buffer_size <= MMI_UC_UTF8_TEXT_BUFFER_SIZE);
    
        handled_buffer = (U8*)applib_mem_screen_alloc((U16)handled_buffer_size);
        memset((S8*) handled_buffer, 0, handled_buffer_size);
        
        mmi_frm_sms_add_escape_symbol_for_extension_char(
            (U16*) handled_buffer,
            (U16*) g_uc_p->main.text_buffer,
            g_uc_p->msg.current_slide->text.char_count);
    }     

    MMI_ASSERT(mmi_frm_sms_fill_in_edit_buffer(handled_buffer, 
                                               (U16)((handled_buffer_size / ENCODING_LENGTH) - 1), 
                                               sendData->dcs, 
                                               KAL_TRUE));
    applib_mem_screen_free(handled_buffer);

    if (g_uc_p->msg.to_num)
    {
        addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, 0);
        
        strncpy((S8*) sendData->number, (S8*) addr->addr,MAX_DIGITS_SMS - 1);
    }

    sendData->status = SMSAL_STO_DRAFT; /*protocol support. save to draft*/
    mmi_frm_sms_save_sms(mmi_uc_save_sms_rsp, MOD_MMI, sendData);
    OslMfree(sendData);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_sms_rsp
 * DESCRIPTION
 *  Save SMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_sms_rsp(void *status, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.save_result = result;
    mmi_uc_action_fsm(MMI_UC_ACTION_SAVE, result);

    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_delete_sms_callback
 * DESCRIPTION
 *  Delete SMS msg response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_delete_sms_callback(void *dummy, module_type mod, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_uc_action_fsm(MMI_UC_ACTION_DELETE, result);    
}
    
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_sending_sms
 * DESCRIPTION
 *  Entry function of sending sms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_sending_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_SENDING, NULL, mmi_uc_entry_sending_sms, NULL);
    
    ShowCategory8Screen(
        STR_SENDING_SMS,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        0,
        0,
        STR_GLOBAL_ABORT,
        IMG_SMS_COMMON_NOIMAGE,
        STR_SENDIING_SMS_BODY,
        IMG_NEW_SMS_SEND,
        NULL);
    
    GetCurrEndKeyDownHandler();

    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
    
    SetKeyHandler(mmi_uc_abort_send_sms_by_end_key, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_uc_abort_send_sms, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_sms
 * DESCRIPTION
 *  Abort sending SMS by RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.abort = MMI_UC_ABORT_NORMAL;
    mmi_uc_set_processing_screen(
            STR_GLOBAL_ABORTING, 
            STR_UC_PLEASE_WAIT_ID, 
            IMG_GLOBAL_PROGRESS, 
            0);
    
    mmi_uc_entry_processing_generic();        
    mmi_frm_sms_abort_sending_sms(MMI_FRM_SMS_ABORT_WITH_FINISH_IND);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_sms_by_end_key
 * DESCRIPTION
 *  Abort sending SMS by endkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_sms_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() == FALSE)
    {
        g_uc_p->send_info.abort = MMI_UC_ABORT_BY_END_KEY;
        mmi_uc_set_processing_screen(
                STR_GLOBAL_ABORTING, 
                STR_UC_PLEASE_WAIT_ID, 
                IMG_GLOBAL_PROGRESS, 
                0);
        
        mmi_uc_entry_processing_generic();
        DeleteUptoScrID(IDLE_SCREEN_ID);
        mmi_frm_sms_abort_sending_sms(MMI_FRM_SMS_ABORT_WITHOUT_FINISH_IND);

       ClearInputEventHandler(MMI_DEVICE_ALL);
       ClearKeyHandler(KEY_END, KEY_EVENT_UP);
       ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
       ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
       ClearKeyHandler(KEY_END, KEY_REPEAT);        
    }
    else
    {    
        ExecCurrEndKeyDownHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_action_fsm
 * DESCRIPTION
 *  FSM for unified composer action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_action_fsm (mmi_uc_action_type_enum action, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 end_screen_id ; /*uc_src_id_enum*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMain.c] mmi_uc_action_fsm action=%d state=%d cur_action=%d  res=%d*\n",
                         g_uc_p->send_info.action, g_uc_p->main.state, action, result);

    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMain.c] mmi_uc_action_fsm cur_msg_type=%d existed_msg_type=%d*\n",
                         g_uc_p->msg_type.curr_msg_type, g_uc_p->send_info.existed_msg_type);    
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    end_screen_id = SCR_ID_UC_PROCESSING;
#else
    end_screen_id = SCR_ID_UC_SENDING;
#endif
    
    switch (g_uc_p->send_info.action)
    {
        case MMI_UC_ACTION_SEND:
        {
            switch (g_uc_p->main.state)
            {
                case MMI_UC_STATE_WRITE_NEW_MSG:
                case MMI_UC_STATE_FORWARD:
                case MMI_UC_STATE_REPLY:
                case MMI_UC_STATE_REPLY_ALL:
                {
                    switch (action)
                    {
                        /* send , write new */
                        case MMI_UC_ACTION_SEND:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMI_FRM_SMS_OK:
                                    {
/* For background send, this case is triggerred when "save" successfully*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                        DisplayPopup(
                                            (PU8) GetString(STR_SENDING_SMS),
                                            IMG_NEW_SMS_SEND,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);

#else
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SENT_ID),
                                            IMG_SEND_SUCCESS_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);
#endif
                                        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, end_screen_id);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, end_screen_id);
                                        }                                    
                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();                                        
                                    }
                                    break;

/* the following cases will not happened in background send, because only save successfully (MMI_FRM_SMS_OK) or 
   fail (MMI_FRM_SMS_ERROR) result will be returned */
#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ 
                                    case MMI_FRM_SMS_ABORT:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_ABORTED_ID),
                                                IMG_GLOBAL_ACTIVATED,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);


                                            if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                            }                                            
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            mmi_uc_addr_struct* addr = NULL;
                                            addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);
                                            mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr); /*send-->end key to abort*/
                                            AlmEnableSPOF();
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    break;

#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/ 
                                    case MMI_FRM_SMS_RETURN:
                                    {
                                        DeleteScreenIfPresent(end_screen_id);
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;

                                        
                                    case MMI_FRM_SMS_END:
                                    {
                                        /* If the SMS action is deleted, reset action state here */
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                    }
                                    break;

                                    case MMI_FRM_SMS_NUMINVALID:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                                            IMG_GLOBAL_ERROR,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);

                                        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, end_screen_id);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT, end_screen_id);   
                                        }
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;
                                                                        
                                    case MMI_FRM_SMS_NOTREADY:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                        
                                        DeleteScreenIfPresent(end_screen_id);
                                        AlmEnableSPOF();
                                    }
                                    break;
#ifdef  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__                                  
                                    case MMI_FRM_SMS_MEMFULL:                             
                                    case MMI_FRM_SMS_SC_EMPTY:
                                    case MMI_FRM_SMS_DATAEMPTY:
                                    case MMI_FRM_SMS_DATAEXCEED:
                                    case MMI_FRM_SMS_DATAINVALID:
                                    case MMI_FRM_SMS_ERROR:                                        
                                    { 

                                        mmi_frm_sms_api_result_handler_struct save_result;

                                        save_result.delete_sms_screen = KAL_FALSE; /*Because only for display popup*/
                                        save_result.display_popup = KAL_TRUE; 
                                        save_result.request_type = MMI_FRM_SMS_REQ_SAVE; /*This is only for MMI_FRM_SMS_OK. so the value in this case is meanless*/
                                        save_result.result = result;
                                        mmi_frm_sms_api_result_handler(&save_result);                                        

                                        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, end_screen_id);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, end_screen_id);
                                        }  

                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();               
                                    }
                                    break;
                                    
                                    default:
                                        MMI_ASSERT(0);
                                    break;
                                    
#else

                                    default:
                                    {
                                        mmi_uc_addr_struct* addr = NULL;

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        
                                        addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                        mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);
                                    }
                                    break;                                    
#endif

                                }    
                            }
                            /* send , write new mms*/
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        /* Avoid user to send abort after sending rsp is received. */
                                        if (GetExitScrnID() == SCR_ID_UC_SENDING)
                                        {
                                            ClearInputEventHandler(MMI_DEVICE_ALL);
                                            ClearKeyHandler(KEY_END, KEY_EVENT_UP);
                                            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
                                            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
                                            ClearKeyHandler(KEY_END, KEY_REPEAT);
                                        }
                                        else if (g_uc_p->send_info.abort != MMI_UC_ABORT_NONE)
                                        {
                                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                                 "*[UnifiedComposerMain.c] mmi_uc_action_fsm race condition for send_mms_rsp and cancel_mms_req *\n");
                                            
                                            g_uc_p->send_info.send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);                                        
                                    }
                                    break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }

                                    }
                                    break;

                                    default:
                                    {
                                        if (g_uc_p->send_info.abort != MMI_UC_ABORT_NONE)
                                        {
                                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                                 "*[UnifiedComposerMain.c] mmi_uc_action_fsm race condition for send_mms_rsp and cancel_mms_req *\n");
                                            
                                            g_uc_p->send_info.send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {                                        
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                    }
                                    break;  

                                }

                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        /* send , write new */
                        case MMI_UC_ACTION_SAVE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {                                
/* For background send, the following case will not happen, L4/mmsgrsr will take care*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__                               
                                MMI_ASSERT(0);
#else
                                if (g_uc_p->send_info.send_result == MMI_FRM_SMS_ABORT)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }                                        
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (result == MMI_FRM_SMS_OK)
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_SUCCESS),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }
                                    else
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_FAIL),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }

                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }                                    
                                    
                                    mmi_uc_delete_sms_frm_screen();
                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();
                                }                                                                
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        mmi_uc_reset_msg();
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }   
                                    mmi_uc_reset_msg();
                                    AlmEnableSPOF();            
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }

                        }
                        break;
                        
                        /* send , write new */
                        case MMI_UC_ACTION_DELETE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                MMI_ASSERT(0);
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                /* Deletion may fail in USB normal mode. */
                                
                                if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    DisplayPopup(
                                        (PU8) GetString(STR_UC_ABORTED_ID),
                                        IMG_GLOBAL_ACTIVATED,
                                        1,
                                        MMI_UC_POPUP_TIME_OUT,
                                        (U8) SUCCESS_TONE);

                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                        g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                    }                                       
                                    AlmEnableSPOF();
                                }
                                else
                                {
                                    mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_SENDING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_SENDING);
                                    }   
                                    mmi_uc_reset_msg();                                    
                                    AlmEnableSPOF(); 
                                }
                                
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }                            
                        }
                        break;
                        
                        /* send , write new */
                        default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break; /* send , write new  */

                /* send , edit */
                case MMI_UC_STATE_EDIT_EXISTED_MSG:
                case MMI_UC_STATE_SEND:
                {
                    UmMsgBoxType msg_box = (UmMsgBoxType)g_uc_p->send_info.curr_folder;
                    MMI_ASSERT(msg_box);

                    if (g_uc_p->send_info.action == MMI_UC_STATE_SEND)
                    {
                        MMI_ASSERT(msg_box == UM_MSG_BOX_TYPE_UNSENT || 
                                   msg_box == UM_MSG_BOX_TYPE_DRAFT);
                    }
                    
                    switch (action)
                    {
                        /* send , edit */
                        /*if background sending is enabled, the "SEND" here only mean "SAVE successfully*/ 
                        case MMI_UC_ACTION_SEND:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMI_FRM_SMS_OK:
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
/* For background send, this case is triggerred when "save" successfully*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	                                        DisplayPopup(
	                                            (PU8) GetString(STR_SENDING_SMS),
	                                            IMG_NEW_SMS_SEND,
	                                            1,
	                                            MMI_UC_POPUP_TIME_OUT,
	                                            (U8) SUCCESS_TONE);
#else


	                                        DisplayPopup(
	                                            (PU8) GetString(STR_UC_SENT_ID),
	                                            IMG_SEND_SUCCESS_PIC_MSG,
	                                            1,
	                                            MMI_UC_POPUP_TIME_OUT,
	                                            (U8) SUCCESS_TONE);
#endif  /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/            
     
                                            if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, end_screen_id);
                                            }
                                            else
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, end_screen_id);
                                            }   

                                            mmi_uc_reset_msg();
                                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
                                        }
                                        else  /*sent ok, then delete msg from draft*/
                                        {
                                            /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                            /* Do not display processing screen in such cases. */
                                            if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                            {
                                                mmi_uc_set_processing_screen(STR_GLOBAL_DELETE, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                                mmi_uc_entry_processing_after_send();
                                            }
                                            DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                            /*Delete the orignal message in draft/unsent*/
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                            }
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                    }
                                    break;

/*if BGS is enabled, the following case will be handled by L4*/
#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__      
                                    case MMI_FRM_SMS_ABORT:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_ABORTED_ID),
                                                IMG_GLOBAL_ACTIVATED,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);
                                            
                                            if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                                g_uc_p->main.state == MMI_UC_STATE_SEND)
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                            }
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                                msg_box == UM_MSG_BOX_TYPE_SENT)
                                            {
                                                mmi_uc_addr_struct* addr = NULL;
                                                addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                                mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr); /*send-->end ket to abort-->not sent--outbox */
                                                AlmEnableSPOF();
                                            }
                                            else
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    mmi_frm_sms_delete_sms(
                                                        mmi_uc_delete_sms_callback, 
                                                        MOD_MMI, 
                                                        MMI_FRM_SMS_DRAFTS, 
                                                        (U16)g_uc_p->send_info.existed_msg_id );
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_addr_struct* addr = NULL;

                                                    addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                    mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);    /*send-->end ket to abort-->not sent--outbox */                                                
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    break;

                                                                        
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/                                                                            
                                    case MMI_FRM_SMS_RETURN:
                                    {
                                        DeleteScreenIfPresent(end_screen_id);
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;
                                        
                                    case MMI_FRM_SMS_END:
                                    {
                                        /* If the SMS action is deleted, reset action state here */
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                    }
                                    break;
                                    
                                    case MMI_FRM_SMS_NOTREADY:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                        
                                        DeleteScreenIfPresent(end_screen_id);
                                        AlmEnableSPOF();
                                    }
                                    break;

                                    case MMI_FRM_SMS_NUMINVALID:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                                            IMG_GLOBAL_ERROR,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);

                                        if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_SENDING);   
                                        }  
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__                              
                                    case MMI_FRM_SMS_MEMFULL:                                        
                                    case MMI_FRM_SMS_SC_EMPTY:
                                    case MMI_FRM_SMS_DATAEMPTY:
                                    case MMI_FRM_SMS_DATAEXCEED:
                                    case MMI_FRM_SMS_DATAINVALID:
                                    case MMI_FRM_SMS_ERROR:                                        
                                    { 

                                        mmi_frm_sms_api_result_handler_struct save_result;

                                        save_result.delete_sms_screen = KAL_FALSE; /*Because only for display popup*/
                                        save_result.display_popup = KAL_TRUE; 
                                        save_result.request_type = MMI_FRM_SMS_REQ_SAVE; /*This is only for MMI_FRM_SMS_OK. so the value in this case is meanless*/
                                        save_result.result = result;
                                        mmi_frm_sms_api_result_handler(&save_result);        

                                        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                            g_uc_p->main.state == MMI_UC_STATE_SEND)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, end_screen_id);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, end_screen_id);
                                        }  


                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();       

                                    }
                                    break;

                                    default:
                                    {
                                        MMI_ASSERT(0);
                                    }
                                    break;
#else

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_uc_addr_struct* addr = NULL;
                                            
                                            addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                            mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);  /*send-->error-->not sent ok--outbox */                                              
                                        }
                                        else
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT)
                                            {
                                                mmi_um_set_highlight_msg(0);
                                            }

                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_addr_struct* addr = NULL;

                                                addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);     /*send-->error-->not sent ok--outbox */                                                                                             
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }                                        
                                    }
                                    break;                                    
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/ 
                                }    
                            }
                            /* send , edit*/
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (g_uc_p->send_info.abort != MMI_UC_ABORT_NONE)
                                        {
                                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                                 "*[UnifiedComposerMain.c] mmi_uc_action_fsm race condition for send_mms_rsp and cancel_mms_req *\n");
                                            
                                            g_uc_p->send_info.send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }
                                        
                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            /* Avoid user to send abort after sending rsp is received. */
                                            if (GetExitScrnID() == SCR_ID_UC_SENDING)
                                            {
                                                ClearInputEventHandler(MMI_DEVICE_ALL);
                                                ClearKeyHandler(KEY_END, KEY_EVENT_UP);
                                                ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
                                                ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
                                                ClearKeyHandler(KEY_END, KEY_REPEAT);
                                            }
                                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else
                                        {
                                            /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                            /* Do not display processing screen in such cases. */
                                            if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                            {
                                                mmi_uc_set_processing_screen(STR_GLOBAL_DELETE, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                                mmi_uc_entry_processing_after_send();
                                            }
                                            DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                            }
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }                                        
                                    }
                                    break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                                msg_box == UM_MSG_BOX_TYPE_SENT)
                                            {
                                                mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                            }
                                            else
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {                                                        
                                                    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);                                                        
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_delete_existed_mms();
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            } 
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    break;

                                    default:
                                    {
                                        if (g_uc_p->send_info.abort != MMI_UC_ABORT_NONE)
                                        {
                                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                                 "*[UnifiedComposerMain.c] mmi_uc_action_fsm race condition for send_mms_rsp and cancel_mms_req *\n");
                                            
                                            g_uc_p->send_info.send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                        }
                                        else
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT)
                                            {
                                                mmi_um_set_highlight_msg(0);
                                            }

                                            /* save msg from SMS to MMS. Save new one and then delete original one */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {                                                    
                                                mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);                                                        
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                    }
                                    break;  

                                }

                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        /* send , edit */
                        case MMI_UC_ACTION_SAVE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {                                
/* For background send, the following case will not happen, L4 will take care*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__                               
                                MMI_ASSERT(0);
#else                            
                                if (g_uc_p->send_info.send_result == MMI_FRM_SMS_ABORT)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == MMI_FRM_SMS_OK)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_delete_existed_mms();
                                                    return;                                                                                               
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                        }

                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();

                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (result == MMI_FRM_SMS_OK)
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                                return;                                                                                               
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }

                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_SUCCESS),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);

                                    }
                                    else
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_FAIL),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }   
                                    mmi_uc_delete_sms_frm_screen();
                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();
                                }                                                                
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */ 
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                     mmi_frm_sms_delete_sms(
                                                        mmi_uc_delete_sms_callback, 
                                                        MOD_MMI, 
                                                        MMI_FRM_SMS_DRAFTS, 
                                                        (U16)g_uc_p->send_info.existed_msg_id );
                                                    return;
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */                                                                                                                                               
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                        }
                                        
                                        mmi_uc_reset_msg();
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (result == MMA_RESULT_OK)
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            /* save msg from SMS to MMS. Save new one and then delete original one. */ 
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                 mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                                return;
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Do nothing. */                                                                                                                                               
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }                                        
                                    }
                                    
                                    mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  
                                    mmi_uc_reset_msg();
                                    AlmEnableSPOF();            
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }

                        }
                        break;
                        
                        /* send , edit */
                        case MMI_UC_ACTION_DELETE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {   

                                if (g_uc_p->send_info.send_result == MMI_FRM_SMS_OK)
                                {

/* For background send, this case is triggerred when "save" successfully, mean send from draft, send req already process 1st save ok, here, delete this sms from draft ok*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                    DisplayPopup(
                                        (PU8) GetString(STR_SENDING_SMS),
                                        IMG_NEW_SMS_SEND,
                                        1,
                                        MMI_UC_POPUP_TIME_OUT,
                                        (U8) SUCCESS_TONE);
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  

#else 
                                    DisplayPopup(
                                        (PU8) GetString(STR_UC_SENT_ID),
                                        IMG_SEND_SUCCESS_PIC_MSG,
                                        1,
                                        MMI_UC_POPUP_TIME_OUT,
                                        (U8) SUCCESS_TONE);
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  
#endif                                    
                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    mmi_uc_delete_sms_frm_screen();
                                    AlmEnableSPOF(); 
                                }
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__        
                                else
                                {
                                    MMI_ASSERT(0); /*if 1st save fail, not delete msg from draft, so here this case will not happened*/                           
                                }                        
#else                              
                                else if (g_uc_p->send_info.send_result == MMI_FRM_SMS_ABORT)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                            (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {                                                
                                                    mmi_uc_addr_struct* addr = NULL;
                                                    
                                                    addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                    mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);  /*abort*/                                              
                                                    return;    
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */                                                                                                                                           
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }                                                                                        
                                        }                                    
                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                        (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {                                                
                                                mmi_uc_addr_struct* addr = NULL;
                                                
                                                addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);   /*sent, del not ok*/                                             
                                                return;    
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Do nothing. */                                                                                                                                           
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }

                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_SUCCESS),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }
                                    else
                                    {                                        
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_FAIL),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }                                    

                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }   
                                    mmi_uc_delete_sms_frm_screen();
                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();

                                }
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {                            
                                if (g_uc_p->send_info.send_result == MMA_RESULT_OK)
                                {
                                    /* Original msg is deleted first in unsent and draft box cases */
                                    if (g_uc_p->send_info.new_msg_id)
                                    {
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
                                        return;
                                    }
                                    
                                    mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        if (IsScreenPresent(SCR_ID_UC_PROCESSING))
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                        }
                                        else if (IsScreenPresent(SCR_ID_UC_SENDING))
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_SENDING);
                                        }
                                        else 
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    else
                                    {
                                        if (IsScreenPresent(SCR_ID_UC_PROCESSING))
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                        }
                                        else if (IsScreenPresent(SCR_ID_UC_SENDING))
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_SENDING);
                                        }
                                        else 
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }  
                                    mmi_uc_reset_msg();                                    
                                    AlmEnableSPOF(); 
                                }
                                else if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                	if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
	                                {
	                                    /* Deletion may fail in USB normal mode. */
	                                    
	                                    DisplayPopup(
                                            (PU8) GetString(STR_UC_ABORTED_ID),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);
	                                    
	                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                            g_uc_p->main.state == MMI_UC_STATE_SEND)
	                                    {
	                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
	                                    }
	                                    else
	                                    {
	                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
	                                    }                                        
	                                    AlmEnableSPOF();
	                                }
	                                else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
	                                {
                                        if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                            (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {                                                
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                                    return;
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }

                                        mmi_uc_reset_msg();
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();
                                    }
                                    else 
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {                                    
                                    if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                        (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {                                                
                                                /* Do nothing. */
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                                return;
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }

                                    }
                                    
                                    mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);

                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }   
                                    mmi_uc_reset_msg();
                                    AlmEnableSPOF();
                                }
                                
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }                            
                        }
                        break;
                        
                        /* send , write new */
                        default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break; /* send , edit existed  */

                default:
                {
                    MMI_ASSERT(0);
                }
                break;

            }

        }
        break;

        case MMI_UC_ACTION_SEND_AND_SAVE:
        {
            UmMsgBoxType msg_box = (UmMsgBoxType)g_uc_p->send_info.curr_folder;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            MMI_ASSERT(g_uc_p->msg_type.curr_msg_type != MMI_UC_MSG_TYPE_SMS_PREFER);
#endif
#ifdef __MMI_MMS_BGSR_SUPPORT__
            MMI_ASSERT(g_uc_p->msg_type.curr_msg_type != MMI_UC_MSG_TYPE_MMS_PREFER);
#endif 
            
            switch (g_uc_p->main.state)
            {                
                /* send and save, write new */
                case MMI_UC_STATE_WRITE_NEW_MSG:
                case MMI_UC_STATE_FORWARD:                    
                case MMI_UC_STATE_REPLY:
                case MMI_UC_STATE_REPLY_ALL:
                {
                    switch (action)
                    {
                        /* send and save, write new */
                        case MMI_UC_ACTION_SEND:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMI_FRM_SMS_OK:
                                    {
                                        mmi_uc_addr_struct* addr = NULL;

                                        if (msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_um_set_highlight_msg(0);
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        
                                        addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, 0);                                        
                                        mmi_uc_save_sms_after_send(SMSAL_STO_SENT, addr->addr);
                                    }
                                    break;

                                    case MMI_FRM_SMS_ABORT:
                                    {                                                                                
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_ABORTED_ID),
                                                IMG_GLOBAL_ACTIVATED,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);
                                            
                                            if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                            }                                           
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            mmi_uc_addr_struct* addr = NULL;
                                            addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                            mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);
                                            AlmEnableSPOF();
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    break;
                                    
                                    case MMI_FRM_SMS_NOTREADY:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        AlmEnableSPOF();
                                    }
                                    break;

                                    case MMI_FRM_SMS_NUMINVALID:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                                            IMG_GLOBAL_ERROR,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);

                                        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_SENDING);   
                                        }
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;
                                    
                                    case MMI_FRM_SMS_RETURN:
                                    {
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;
                                        
                                    case MMI_FRM_SMS_END:
                                    {
                                        /* If the SMS action is deleted, reset action state here */
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                    }
                                        break;

                                    default:
                                    {
                                        mmi_uc_addr_struct* addr = NULL;

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        
                                        addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                        mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);
                                    }
                                    break;                                    
                                }    
                            }
                            /* send and save, write new */
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (g_uc_p->send_info.abort != MMI_UC_ABORT_NONE)
                                        {
                                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                                 "*[UnifiedComposerMain.c] mmi_uc_action_fsm race condition for send_mms_rsp and cancel_mms_req *\n");
                                            
                                            g_uc_p->send_info.send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }
                                        
                                        if (msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_um_set_highlight_msg(0);
                                        }
                                        
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(
                                                        STR_GLOBAL_SAVING, 
                                                        STR_UC_PLEASE_WAIT_ID, 
                                                        IMG_GLOBAL_PROGRESS, 
                                                        0);
                                            
                                            mmi_uc_entry_processing_after_send();        
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_SENT);
                                    }
                                    break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }

                                    }
                                    break;

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                    }
                                    break;  

                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        /* send and save, write new */
                        case MMI_UC_ACTION_SAVE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                if (g_uc_p->send_info.send_result == MMI_FRM_SMS_ABORT)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (g_uc_p->send_info.send_result == MMI_FRM_SMS_OK)
                                    {
                                        if (result == MMI_FRM_SMS_OK)
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_SUCCESS),
                                                IMG_SEND_SUCCESS_PIC_MSG,
                                                1,
                                                MESSAGES_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);

                                        }
                                        else
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_FAIL),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }

                                    }
                                    else
                                    {
                                        if (result == MMI_FRM_SMS_OK)
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_FAIL_SAVE_SUCCESS),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }
                                        else
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_FAIL_SAVE_FAIL),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }
                                    }
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  
                                    mmi_uc_delete_sms_frm_screen();
                                }
                                mmi_uc_reset_msg();
                                mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                AlmEnableSPOF();                                
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        mmi_uc_reset_msg();
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (g_uc_p->send_info.send_result == MMA_RESULT_OK)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_SUCCESS),
                                                IMG_SEND_SUCCESS_PIC_MSG,
                                                1,
                                                MESSAGES_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);
                                        }
                                        else
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_FAIL),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }

                                    }
                                    else
                                    {
                                        mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);
                                    }                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  
                                }
                                mmi_uc_reset_msg();
                                AlmEnableSPOF();                                
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        case MMI_UC_ACTION_DELETE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                MMI_ASSERT(0);
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                /* Deletion may fail in USB normal mode. */
                                
                                if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    DisplayPopup(
                                            (PU8) GetString(STR_UC_ABORTED_ID),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                        g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                    }                                        
                                    AlmEnableSPOF();
                                }
                                else
                                {
                                    MMI_ASSERT(0);     
                                }
                                
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }             

                        }
                        break;
                        
                        /* send and save, write new */
                        default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }

                }
                break; /* send and save, write new */
                
                case MMI_UC_STATE_EDIT_EXISTED_MSG:
                case MMI_UC_STATE_SEND:
                {
                    MMI_ASSERT(msg_box);
                    
                    if (g_uc_p->send_info.action == MMI_UC_STATE_SEND)
                    {
                        MMI_ASSERT(msg_box == UM_MSG_BOX_TYPE_UNSENT || 
                                   msg_box == UM_MSG_BOX_TYPE_DRAFT);
                    }
                    
                    switch (action)
                    {
                        /* send and save, edit */
                        case MMI_UC_ACTION_SEND:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMI_FRM_SMS_OK:
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_um_set_highlight_msg(0);
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {                                        
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_uc_addr_struct* addr = NULL;
                                            
                                            addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, 0);                                        
                                            mmi_uc_save_sms_after_send(SMSAL_STO_SENT, addr->addr);
                                        }
                                        else
                                        {
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                            }
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                    }
                                    break;

                                    case MMI_FRM_SMS_ABORT:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_ABORTED_ID),
                                                IMG_GLOBAL_ACTIVATED,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);
                                            
                                            if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                                g_uc_p->main.state == MMI_UC_STATE_SEND )
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                            }                                           
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                                msg_box == UM_MSG_BOX_TYPE_SENT)
                                            {
                                                mmi_uc_addr_struct* addr = NULL;
                                                addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                                mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);
                                                AlmEnableSPOF();
                                            }
                                            else
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    mmi_frm_sms_delete_sms(
                                                        mmi_uc_delete_sms_callback, 
                                                        MOD_MMI, 
                                                        MMI_FRM_SMS_DRAFTS, 
                                                        (U16)g_uc_p->send_info.existed_msg_id );
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_addr_struct* addr = NULL;

                                                    addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                    mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);                                                    
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }                                                
                                            }
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    break;
                                    
                                    case MMI_FRM_SMS_NOTREADY:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_SMS_MSG_NOT_READY_YET),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                        
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        AlmEnableSPOF();
                                    }
                                    break;

                                    case MMI_FRM_SMS_NUMINVALID:
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_ID_PHB_NUM_INVALID),
                                            IMG_GLOBAL_ERROR,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);

                                        if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_SENDING);   
                                        }
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;
                                    
                                    case MMI_FRM_SMS_RETURN:
                                    {
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                        
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();            
                                    }
                                    break;
                                        
                                    case MMI_FRM_SMS_END:
                                    {
                                        /* If the SMS action is deleted, reset action state here */
                                        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
                                    }
                                        break;

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_uc_addr_struct* addr = NULL;
                                            
                                            addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);                                        
                                            mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);                                                
                                        }
                                        else
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT)
                                            {
                                                mmi_um_set_highlight_msg(0);
                                            }
                                            
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_addr_struct* addr = NULL;

                                                addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);                                                    
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }                                        
                                    }
                                    break;                                    
                                }    
                            }
                            /* send and save , edit*/
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (g_uc_p->send_info.abort != MMI_UC_ABORT_NONE)
                                        {
                                            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                                                 "*[UnifiedComposerMain.c] mmi_uc_action_fsm race condition for send_mms_rsp and cancel_mms_req *\n");
                                            
                                            g_uc_p->send_info.send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            mmi_uc_action_fsm(MMI_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }
                                        
                                        if (msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_um_set_highlight_msg(0);
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {                                        
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                      STR_UC_PLEASE_WAIT_ID, 
                                                                      IMG_GLOBAL_PROGRESS, 
                                                                      0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);
                                       
                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_SENT);
                                        }
                                        else
                                        {
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    (U16)g_uc_p->send_info.existed_msg_id );
                                            }
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }                                        
                                    }
                                    break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                        {                                        
                                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                                msg_box == UM_MSG_BOX_TYPE_SENT)
                                            {
                                                mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                            }
                                            else
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /*mmi_frm_sms_delete_sms(
                                                        mmi_uc_delete_sms_callback, 
                                                        MOD_MMI, 
                                                        MMI_FRM_SMS_DRAFTS, 
                                                        g_uc_p->send_info.existed_msg_id );*/
                                                        
                                                    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);                                                        
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_delete_existed_mms();
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            } 
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }
                                    }
                                    break;

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode.*/
                                        /* Do not display processing screen in such cases. */
                                        if (IsScreenPresent(SCR_ID_UC_OPT_DONE))
                                        {
                                            mmi_uc_set_processing_screen(STR_GLOBAL_SAVING, 
                                                                         STR_UC_PLEASE_WAIT_ID, 
                                                                         IMG_GLOBAL_PROGRESS, 
                                                                         0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        DeleteScreenIfPresent(SCR_ID_UC_SENDING);

                                        if (msg_box == UM_MSG_BOX_TYPE_INBOX ||
                                            msg_box == UM_MSG_BOX_TYPE_SENT)
                                        {
                                            mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                        }
                                        else
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT)
                                            {
                                                mmi_um_set_highlight_msg(0);
                                            }
                                            
                                            /* save msg from SMS to MMS. Save new one and then delete original one */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /*mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    g_uc_p->send_info.existed_msg_id );*/
                                                    
                                                mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);                                                        
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                    }
                                    break;  

                                }

                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        /* send and save, edit */
                        case MMI_UC_ACTION_SAVE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {                                
                                if (g_uc_p->send_info.send_result == MMI_FRM_SMS_ABORT)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == MMI_FRM_SMS_OK)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_delete_existed_mms();
                                                    return;                                                                                               
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                        }

                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (g_uc_p->send_info.send_result == MMI_FRM_SMS_OK)
                                    {                                        
                                        if (result == MMI_FRM_SMS_OK)
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_SUCCESS),
                                                IMG_SEND_SUCCESS_PIC_MSG,
                                                1,
                                                MESSAGES_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);

                                        }
                                        else
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_FAIL),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }

                                    }
                                    else
                                    {
                                        if (result == MMI_FRM_SMS_OK)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_delete_existed_mms();
                                                    return;                                                                                               
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                            
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_FAIL_SAVE_SUCCESS),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }
                                        else
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_FAIL_SAVE_FAIL),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }
                                    }
                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  
                                    mmi_uc_delete_sms_frm_screen();
                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();
                                }                                                                
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */ 
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                     mmi_frm_sms_delete_sms(
                                                        mmi_uc_delete_sms_callback, 
                                                        MOD_MMI, 
                                                        MMI_FRM_SMS_DRAFTS, 
                                                        (U16)g_uc_p->send_info.existed_msg_id );
                                                    return;
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */                                                                                                                                               
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                        }
                                        
                                        mmi_uc_reset_msg();
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (g_uc_p->send_info.send_result == MMA_RESULT_OK)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_SUCCESS),
                                                IMG_SEND_SUCCESS_PIC_MSG,
                                                1,
                                                MESSAGES_POPUP_TIME_OUT,
                                                (U8) SUCCESS_TONE);
                                        }
                                        else
                                        {
                                            DisplayPopup(
                                                (PU8) GetString(STR_UC_SEND_SUCCESS_SAVE_FAIL),
                                                IMG_SEND_FAIL_PIC_MSG,
                                                1,
                                                MMI_UC_POPUP_TIME_OUT,
                                                (U8) ERROR_TONE);
                                        }

                                    }
                                    else
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */ 
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                     mmi_frm_sms_delete_sms(
                                                        mmi_uc_delete_sms_callback, 
                                                        MOD_MMI, 
                                                        MMI_FRM_SMS_DRAFTS, 
                                                        (U16)g_uc_p->send_info.existed_msg_id );
                                                    return;
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */                                                                                                                                               
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }                                                                                        
                                        }
                                        
                                        mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);
                                    }                                    
                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }  
                                    mmi_uc_reset_msg();
                                    AlmEnableSPOF();                   
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        case MMI_UC_ACTION_DELETE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {                                
                                if (g_uc_p->send_info.send_result == MMI_FRM_SMS_OK)
                                {
                                    mmi_uc_addr_struct* addr = NULL;

                                    addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, 0);  
                                    mmi_uc_save_sms_after_send(SMSAL_STO_SENT, addr->addr);
                                }
                                else if (g_uc_p->send_info.send_result == MMI_FRM_SMS_ABORT)
                                {                                    
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                            (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {                                                                                                    
                                                    mmi_uc_addr_struct* addr = NULL;
                                                    
                                                    addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                    mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);
                                                    return;
                                                    
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */                                                                                                                                           
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }                                                                                        
                                        }                                    
                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                        (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {                                                
                                                mmi_uc_addr_struct* addr = NULL;
                                                
                                                addr = mmi_uc_get_addr(MMI_UC_ADDRESS_GROUP_TYPE_TO, g_uc_p->send_info.curr_send_number);  
                                                mmi_uc_save_sms_after_send(SMSAL_STO_UNSENT, addr->addr);                                                
                                                return;    
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Do nothing. */                                                                                                                                           
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }

                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_SUCCESS),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }
                                    else
                                    {                                        
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_SEND_FAIL_SAVE_FAIL),
                                            IMG_SEND_FAIL_PIC_MSG,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) ERROR_TONE);
                                    }                                    

                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }   
                                    mmi_uc_delete_sms_frm_screen();
                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();
                                }
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (g_uc_p->send_info.send_result == MMA_RESULT_OK)
                                {
                                    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_SENT); 
                                }
                                else if (g_uc_p->send_info.send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (g_uc_p->send_info.abort == MMI_UC_ABORT_NORMAL)
                                    {
                                        MMI_ASSERT(result == MMA_RESULT_OK);
                                        
                                        DisplayPopup(
                                            (PU8) GetString(STR_UC_ABORTED_ID),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MMI_UC_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);
                                        
                                        if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
                                            g_uc_p->main.state == MMI_UC_STATE_SEND)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE_OPT, SCR_ID_UC_PROCESSING);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT, SCR_ID_UC_PROCESSING);
                                        }                                           
                                        AlmEnableSPOF();
                                    }
                                    else if (g_uc_p->send_info.abort == MMI_UC_ABORT_BY_END_KEY)
                                    {
                                        if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                            (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                                msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                                {                                                
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                                    return;
                                                }
                                                else
                                                {
                                                    MMI_ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }

                                        mmi_uc_reset_msg();
                                        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                        {
                                            GoBackHistory();
                                        }
                                        else
                                        {
                                            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                        }   
                                        AlmEnableSPOF();
                                    }
                                    else 
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else /* send fail*/
                                {                                    
                                    if ((g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER && result == MMI_FRM_SMS_OK) ||
                                        (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER && result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == UM_MSG_BOX_TYPE_UNSENT ||
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            /* save msg from SMS to MMS. Save new one and then delete original one. */
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {                                                
                                                /* Do nothing. */    
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_OUTBOX);
                                                return;
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            MMI_ASSERT(0);
                                        }

                                    }
                                    mmi_uc_display_mma_send_result_popup(g_uc_p->send_info.send_result);

                                    if (g_uc_p->main.state == MMI_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_DONE, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }   
                                    mmi_uc_reset_msg();
                                    AlmEnableSPOF();
                                }                                
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }                            
                        }
                        break;
                        
                        /* send , write new */
                        default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break;                                

                default:
                {
                    MMI_ASSERT(0);
                }
                break;

            }        
        }
        break;

        case MMI_UC_ACTION_SAVE:
        {
            UmMsgBoxType msg_box = (UmMsgBoxType)g_uc_p->send_info.curr_folder;
            /* save */
            switch (g_uc_p->main.state)
            {
                /* save, write new */
                case MMI_UC_STATE_WRITE_NEW_MSG:
                case MMI_UC_STATE_REPLY:
                case MMI_UC_STATE_REPLY_ALL:
                {
                    /* save, write new */
                    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                    {
                        /* save, write new, sms */
                        if (action == MMI_UC_ACTION_SAVE)
                        {
                            if (result == MMI_FRM_SMS_OK)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_GLOBAL_DONE),
                                    IMG_GLOBAL_ACTIVATED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) SUCCESS_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
                                    IMG_GLOBAL_UNFINISHED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) WARNING_TONE);                        
                            }
                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                            mmi_uc_reset_msg();
                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                            mmi_uc_delete_sms_frm_screen();
                            AlmEnableSPOF();
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }
                    }
                    /* save, write new */
                    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                    {
                        /* save, write new, mms */
                        if (action == MMI_UC_ACTION_SAVE)
                        {
                            if (result == MMA_RESULT_OK)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_GLOBAL_DONE),
                                    IMG_GLOBAL_ACTIVATED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) SUCCESS_TONE);
                            }
                            else if (result == MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID),
                                    IMG_GLOBAL_UNFINISHED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) WARNING_TONE);                        
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_UC_STORAGE_FULL_ID),
                                    IMG_GLOBAL_UNFINISHED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) WARNING_TONE); 
                            }

                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                            mmi_uc_reset_msg();
                            AlmEnableSPOF();
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }
                        
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }                    
                }
                break;

                /* save, edit existed */
                case MMI_UC_STATE_EDIT_EXISTED_MSG:
                {                    
                    /* save, edit */
                    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                    {
                        /* save, edit, sms */
                        if (action == MMI_UC_ACTION_SAVE)
                        {                        
                            if (result == MMI_FRM_SMS_OK)
                            {                                                                
                                if (msg_box == UM_MSG_BOX_TYPE_DRAFT || 
                                    (msg_box == UM_MSG_BOX_TYPE_UNSENT && g_uc_p->msg.to_num > 0))
                                {
                                    /* save msg from SMS to SMS. Delete original one and then save new one. */
                                    if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                    {                                
                                        DisplayPopup(
                                            (PU8) GetString(STR_GLOBAL_DONE),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MESSAGES_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);
                                    }
                                    /* save msg from MMS to SMS. Save new one and then delete original one. */
                                    else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                    {
                                        mmi_uc_delete_existed_mms();
                                        return;
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    DisplayPopup(
                                        (PU8) GetString(STR_GLOBAL_DONE),
                                        IMG_GLOBAL_ACTIVATED,
                                        1,
                                        MESSAGES_POPUP_TIME_OUT,
                                        (U8) SUCCESS_TONE);

                                }
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_SMS_FAILURE_MEM_FULL),
                                    IMG_GLOBAL_UNFINISHED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) WARNING_TONE);                        
                            }
                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                            mmi_uc_reset_msg();
                            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                            mmi_uc_delete_sms_frm_screen();
                            AlmEnableSPOF();
                        }
                        else if (action == MMI_UC_ACTION_DELETE)
                        {                        
                            if (msg_box == UM_MSG_BOX_TYPE_DRAFT || 
                               (msg_box == UM_MSG_BOX_TYPE_UNSENT && g_uc_p->msg.to_num > 0))
                            {
                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                {
                                    /*In SMS, delete orig one and then save new one, here, save new one if delete successfully*/
                                    if (result == MMI_FRM_SMS_OK)
                                    {
                                        mmi_uc_save_sms_req();
                                    }
                                    else
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_GLOBAL_UNFINISHED),
                                            IMG_GLOBAL_UNFINISHED,
                                            1,
                                            MESSAGES_POPUP_TIME_OUT,
                                            (U8) WARNING_TONE);
                                        
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                                        mmi_uc_reset_msg();
                                        mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
                                    }                            
                                }
                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                {
                                    /* Deletion may fail in USB normal mode. */
                                    
                                    DisplayPopup(
                                            (PU8) GetString(STR_GLOBAL_DONE),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MESSAGES_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);

                                    mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                                    mmi_uc_reset_msg();
                                    mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                                    mmi_uc_delete_sms_frm_screen();
                                    AlmEnableSPOF();
                                }
                                else
                                {
                                    MMI_ASSERT(0);
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }
                    }
                    /* save, edit */
                    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                    {
                        /* save, edit, mms */
                        if (action == MMI_UC_ACTION_SAVE)
                        {
                            if (result == MMA_RESULT_OK)
                            {
                                if (msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                {
                                    /* save msg from SMS to MMS. Save new one and then delete original one. */
                                    if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                    {
                                        mmi_frm_sms_delete_sms(
                                            mmi_uc_delete_sms_callback, 
                                            MOD_MMI, 
                                            MMI_FRM_SMS_DRAFTS, 
                                            (U16)g_uc_p->send_info.existed_msg_id );
                                        return;
                                    }
                                    /* save msg from MMS to MMS. Delete original one and then save new one. */
                                    else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_GLOBAL_DONE),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MESSAGES_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);                                        
                                    }
                                    else
                                    {
                                        MMI_ASSERT(0);
                                    }
                                }
                                else
                                {
                                    DisplayPopup(
                                        (PU8) GetString(STR_GLOBAL_DONE),
                                        IMG_GLOBAL_ACTIVATED,
                                        1,
                                        MESSAGES_POPUP_TIME_OUT,
                                        (U8) SUCCESS_TONE);
                                }
                            }
                            else if (result == MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID),
                                    IMG_GLOBAL_UNFINISHED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) WARNING_TONE);                        
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_UC_STORAGE_FULL_ID),
                                    IMG_GLOBAL_UNFINISHED,
                                    1,
                                    MESSAGES_POPUP_TIME_OUT,
                                    (U8) WARNING_TONE); 
                            }

                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                            mmi_uc_reset_msg();
                            AlmEnableSPOF();
                        }
                        else if (action == MMI_UC_ACTION_DELETE)
                        {
                            if (msg_box == UM_MSG_BOX_TYPE_DRAFT)
                            {
                                /* save msg from SMS to MMS. save new one and then delete original one . */
                                if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                {
                                    MMI_ASSERT(result == MMI_FRM_SMS_OK);
                                    DisplayPopup(
                                            (PU8) GetString(STR_GLOBAL_DONE),
                                            IMG_GLOBAL_ACTIVATED,
                                            1,
                                            MESSAGES_POPUP_TIME_OUT,
                                            (U8) SUCCESS_TONE);
                                    
                                    mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                                    mmi_uc_reset_msg();
                                    AlmEnableSPOF();
                                }
                                /* save msg from MMS to MMS. delete original one and then Save new one. */
                                else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                {
                                    if (result == MMA_RESULT_OK)
                                    {
                                        mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_DRAFT);
                                    }
                                    else
                                    {
                                        DisplayPopup(
                                            (PU8) GetString(STR_GLOBAL_UNFINISHED),
                                            IMG_GLOBAL_UNFINISHED,
                                            1,
                                            MESSAGES_POPUP_TIME_OUT,
                                            (U8) WARNING_TONE);

                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);

                                        mmi_uc_reset_msg();
                                        AlmEnableSPOF();
                                    }
                                }
                                else
                                {
                                    MMI_ASSERT(0);
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }                        
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }             
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;

            }        
        }
        break; /* save */

        case MMI_UC_ACTION_SAVE_IN_BACKGROUND:
        {
            /* save in background*/
            switch (g_uc_p->main.state)
            {
                /* save in background, write new */
                case MMI_UC_STATE_WRITE_NEW_MSG:
                case MMI_UC_STATE_REPLY:
                case MMI_UC_STATE_REPLY_ALL:
                case MMI_UC_STATE_EDIT_EXISTED_MSG:
                {
                    /* save in background, write new */
                    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                    {
                        /* save, write new, sms */
                        if (action == MMI_UC_ACTION_SAVE)
                        {
                            mmi_uc_reset_msg();

                            /* The ems buffer would be reset in SMS framework. */
                            //mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_SMS_PREFER);
                            AlmEnableSPOF();
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }
                    }
                    /* save in background, write new */
                    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                    {
                        /* save in background, write new, mms */
                        if (action == MMI_UC_ACTION_SAVE)
                        {
                            mmi_uc_reset_msg();
                            AlmEnableSPOF();
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }                        
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }                    
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break;

            }        
        }
        break; /* save in background */

#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))
    
        case MMI_UC_ACTION_SEND_IN_BACKGROUND:
        {
            switch (g_uc_p->main.state)
            {
                case MMI_UC_STATE_WRITE_NEW_MSG:
                case MMI_UC_STATE_FORWARD:
                case MMI_UC_STATE_REPLY:
                case MMI_UC_STATE_REPLY_ALL:
                {
                    switch (action)
                    {
                        /* send in background , write new */
                        case MMI_UC_ACTION_SEND:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                MMI_ASSERT(0);                                    
                            }
                            /* send in background , write new mms*/
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                mmi_uc_reset_msg();
                                
                                if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                {
                                    GoBackHistory();
                                }
                                else
                                {
                                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        /* send in background, write new */
                        case MMI_UC_ACTION_SAVE:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                        
                        /* send in background, write new */
                        case MMI_UC_ACTION_DELETE:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                        
                        /* send in background, write new */
                        default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break; /* send in background, write new  */

                /* send in background, edit */
                case MMI_UC_STATE_EDIT_EXISTED_MSG:
                case MMI_UC_STATE_SEND:
                {
                    UmMsgBoxType msg_box = (UmMsgBoxType)g_uc_p->send_info.curr_folder;
                    MMI_ASSERT(msg_box);

                    if (g_uc_p->send_info.action == MMI_UC_STATE_SEND)
                    {
                        MMI_ASSERT(msg_box == UM_MSG_BOX_TYPE_UNSENT || 
                                   msg_box == UM_MSG_BOX_TYPE_DRAFT);
                    }
                    
                    switch (action)
                    {
                        /* send in background, edit */
                        case MMI_UC_ACTION_SEND:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                MMI_ASSERT(0);
                            }
                            /* send in background, edit*/
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (
#ifndef __MMI_MMS_BGSR_SUPPORT__                                            
                                            msg_box == UM_MSG_BOX_TYPE_UNSENT ||   
#endif
                                            msg_box == UM_MSG_BOX_TYPE_DRAFT)
                                        {
                                            if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /*when sms deleting, use this screen to block mmi, to aviod display list, 
                                                  UM will get wrong info from sms*/

                                                if ( (GetExitScrnID() > SCR_ID_UC_START) &&
                                                      (GetExitScrnID() < SCR_ID_UC_END) )
                                                {
                                                    mmi_uc_set_processing_screen(
                                                            STR_GLOBAL_DELETE, 
                                                            STR_UC_PLEASE_WAIT_ID, 
                                                            IMG_GLOBAL_PROGRESS, 
                                                            0);
                                                
                                                    mmi_uc_entry_processing_generic();
                                                }
                                                else
                                                {
                                                    mmi_uc_add_processing_to_history();
                                                }
                                                
                                                mmi_frm_sms_delete_sms(
                                                    mmi_uc_delete_sms_callback, 
                                                    MOD_MMI, 
                                                    MMI_FRM_SMS_DRAFTS, 
                                                    g_uc_p->send_info.existed_msg_id );
                                            }
                                            else if (g_uc_p->send_info.existed_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                mmi_uc_delete_existed_mms();                                                
                                            }
                                            else
                                            {
                                                MMI_ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            mmi_uc_reset_msg();
                                            if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                            {
                                                GoBackHistory();
                                            }
                                            else
                                            {
                                                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                            }
                                        }
                                    }
                                    break;

                                    default:
                                    {
                                        MMI_ASSERT(0);
                                    }
                                    break;  

                                }

                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }
                        }
                        break;

                        /* send in background , edit */
                        case MMI_UC_ACTION_SAVE:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                        
                        /* send in background , edit */
                        case MMI_UC_ACTION_DELETE:
                        {
                            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
                            {
                                MMI_ASSERT(0);
                            }
                            else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
                            {
                                mmi_uc_reset_msg();
                                if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
                                {
                                    GoBackHistory();
                                }
                                else
                                {
                                    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                                }
                            }
                            else
                            {
                                MMI_ASSERT(0);
                            }                            
                        }
                        break;
                        
                        /* send , write new */
                        default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break; /* send , edit existed  */

                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;
#endif /* __MMI_MMS_2__ || __MMI_MMS_BGSR_SUPPORT__ */

        case MMI_UC_ACTION_DELETE_IN_BACKGROUND:
        {
            /* delete in background*/
            g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;

            if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
            {
                GoBackHistory();
            }
            else
            {
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            }            
        }
        break; /* delete in background */

        case MMI_UC_ACTION_IDLE:
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMain.c] mmi_uc_action_fsm IDLE DO Nothing *\n");        
        }
        break;
        
        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_create_mms
 * DESCRIPTION
 *  Create MMS xml file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_create_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_set_processing_screen(STR_UC_MMS_ID, STR_UC_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0); 
    mmi_uc_entry_processing_generic();
    
    result = mmi_uc_create_mms_xml_description_file();

    if (result == FS_NO_ERROR)
    {
        mmi_uc_create_mms_req();
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*---[UnifiedComposerMain.c] mmi_uc_create_mms_xml_description_file fail %d---*\n",result);
        if (result == FS_DISK_FULL)
        {
            DisplayPopup(
                (PU8)GetString(STR_UC_STORAGE_FULL_DELETE_FILE_ID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);         
        }
        else
        {
            DisplayPopup(
                (PU8)GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);                        
        }

        DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);

        /* reset state */
        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_mms
 * DESCRIPTION
 *  Send MMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.percent = 0;
    mmi_uc_entry_sending_mms();
    mmi_uc_send_mms_req(FALSE, 0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_and_save_mms
 * DESCRIPTION
 *  Send MMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_and_save_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_MMS_BGSR_SUPPORT__) || defined(__MMI_MMS_2__))
    MMI_ASSERT(0);  /*if background send, this case will not happen.*/
#endif
    g_uc_p->send_info.percent = 0;
    mmi_uc_entry_sending_mms();
    mmi_uc_send_mms_req(TRUE, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_mms
 * DESCRIPTION
 *  Send SMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_set_processing_screen(
                STR_GLOBAL_SAVING, 
                STR_UC_PLEASE_WAIT_ID, 
                IMG_GLOBAL_PROGRESS, 
                0);
    
    mmi_uc_entry_processing_generic();        
    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_DRAFT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_mms_to_folder
 * DESCRIPTION
 *  Send SMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_mms_to_folder(U16 msg_box_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_set_processing_screen(
                STR_GLOBAL_SAVING, 
                STR_UC_PLEASE_WAIT_ID, 
                IMG_GLOBAL_PROGRESS, 
                0);
    
    mmi_uc_entry_processing_generic();        
    mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, msg_box_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_sending_mms
 * DESCRIPTION
 *  Entry function of sending MMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_sending_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_SENDING, NULL, mmi_uc_entry_sending_mms, NULL);

    ShowCategory402Screen(
        (U8 *) GetString(STR_UC_SENDING_MMS_ID), 
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        0, 
        0, 
        STR_GLOBAL_ABORT, 
        IMG_GLOBAL_BACK, 
        (U8 *) GetString(STR_UC_PLEASE_WAIT_ID), 
        g_uc_p->send_info.percent,
        NULL);
    
    GetCurrEndKeyDownHandler();

    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);
        
    SetKeyHandler(mmi_uc_abort_send_mms_by_end_key, KEY_END, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_uc_abort_send_mms, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_update_sending_mms_percent_and_retry
 * DESCRIPTION
 *  Update percent of sending MMS msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_update_sending_mms_percent_and_retry(U16 percent, U8 retry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
        "*---mmi_uc_update_sending_mms_percent_and_retry, percent=%d, retry=%d ---*\n",percent,retry);
    if (GetExitScrnID() == SCR_ID_UC_SENDING)
    {
        g_uc_p->send_info.percent = percent;
        
        if ( retry > 0)
        {
            const S8 * pstr1 ;
            S8  *message;
            U32 temp_string_len = 6; /*temp_string_len - for percentage wording --ex" 100%"*/
            U8 temp_string[6];
            U8 temp_ucs2_string[6 * ENCODING_LENGTH];
            int msg_size = 0;

            pstr1 = GetString(STR_UC_RESEND_ID);
            msg_size = (mmi_ucs2strlen(pstr1) + temp_string_len) * ENCODING_LENGTH; 

            message = (S8 *)OslMalloc(msg_size); 
            memset(message, 0, msg_size);

            sprintf((char*)temp_string, " %d%%", percent);
            mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
            mmi_ucs2cpy((PS8) message, (PS8) pstr1);
            mmi_ucs2cat(message, (S8*)temp_ucs2_string);     
            
            UpdateCategory402Value((U16) percent, (PU8) message);
            OslMfree(message);
        }
        else if (retry == 0)
        {
            UpdateCategory402Value((U16)percent, NULL);
        }
    }
    else
    {
        g_uc_p->send_info.percent = percent;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_mms
 * DESCRIPTION
 *  Abort sending MMS by RSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->send_info.abort = MMI_UC_ABORT_NORMAL;
    mmi_uc_set_processing_screen(
            STR_GLOBAL_ABORTING, 
            STR_UC_PLEASE_WAIT_ID, 
            IMG_GLOBAL_PROGRESS, 
            0);
    
    mmi_uc_entry_processing_generic();        
    mmi_uc_abort_send_mms_req(g_uc_p->send_info.new_msg_id);
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_abort_send_mms_by_end_key
 * DESCRIPTION
 *  Abort sending MMS by endkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_abort_send_mms_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort MMS sending if not in-call or in csd call for MMS over csd case. */
    if (isInCall() == FALSE || IsWapCallPresent())
    {
        g_uc_p->send_info.abort = MMI_UC_ABORT_BY_END_KEY;        
        mmi_uc_set_processing_screen(
                STR_GLOBAL_ABORTING, 
                STR_UC_PLEASE_WAIT_ID, 
                IMG_GLOBAL_PROGRESS, 
                0);
        
        mmi_uc_entry_processing_generic();
        DeleteUptoScrID(IDLE_SCREEN_ID);
        
        mmi_uc_abort_send_mms_req(g_uc_p->send_info.new_msg_id);

        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
    }
    else
    {
        ExecCurrEndKeyDownHandler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_send
 * DESCRIPTION
 *  Funtion is called when send menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
    if ((g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER) &&
        (g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num > 0))
    {
        SetLeftSoftkeyFunction(mmi_uc_entry_mms_size_confirm_send, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_entry_mms_size_confirm_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else 
    {
        SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#else /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
    SetLeftSoftkeyFunction(mmi_uc_process_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_send_and_save
 * DESCRIPTION
 *  Funtion is called when send and save menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_send_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMS_SIZE_CONFIRM_BEFORE_SEND__
    if ((g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER) &&
        (g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num > 0))
    {
        SetLeftSoftkeyFunction(mmi_uc_entry_mms_size_confirm_send_and_save, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_entry_mms_size_confirm_send_and_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else 
    {
        SetLeftSoftkeyFunction(mmi_uc_process_send_and_save, KEY_EVENT_UP);
        SetKeyHandler(mmi_uc_process_send_and_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#else /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
    SetLeftSoftkeyFunction(mmi_uc_process_send_and_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_send_and_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /*__MMS_SIZE_CONFIRM_BEFORE_SEND__*/
    return;
}

#if defined(__MMI_MMS_2__) || defined(__MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__)
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_save_as_template
 * DESCRIPTION
 *  Funtion is called when save as template menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_save_as_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_process_save_as_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_MMS_2__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_save
 * DESCRIPTION
 *  Funtion is called when save menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_process_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_back_to_edit
 * DESCRIPTION
 *  Funtion is called when back to edit menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_back_to_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_process_back_to_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_back_to_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_send_opt
 * DESCRIPTION
 *  Funtion is called when send option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_send_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_send_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_done_opt_exit
 * DESCRIPTION
 *  Funtion is called when exit menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_done_opt_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    SetLeftSoftkeyFunction(mmi_uc_process_exit, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_process_exit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_addr_list
 * DESCRIPTION
 *  Entry function for address list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_addr_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    S32 numitem = 0;
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMain.c] mmi_uc_entry_addr_list type=%d *\n",
                         g_uc_p->done.current_addr_type);    
    
    switch(g_uc_p->done.current_addr_type)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            numitem = g_uc_p->msg.to_num;
            title_id = STR_UC_TO_ID;
        }
        break;

        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            numitem = g_uc_p->msg.cc_num;
            title_id = STR_UC_CC_ID;
        }
        break;

        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            numitem = g_uc_p->msg.bcc_num;
            title_id = STR_UC_BCC_ID;
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
    }
    
    MMI_ASSERT(numitem);

    EntryNewScreen(SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_exit_generic, mmi_uc_entry_addr_list, NULL);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE_ADDR_LIST);
    RegisterHighlightHandler(mmi_uc_set_addr_index);
    
    if (guiBuffer != NULL)
    {
        hiliteitem = (g_uc_p->done.current_addr_index <= numitem) ? g_uc_p->done.current_addr_index : 0;
        /* change gui buffer content */
        change_cat184_list_menu_history_highlighted_item(hiliteitem, guiBuffer);
    }
    else if (g_uc_p->done.current_addr_index > 0)
    {
        hiliteitem = (g_uc_p->done.current_addr_index <= numitem) ? g_uc_p->done.current_addr_index : 0;
    }
    
    ShowCategory184Screen(
        title_id,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numitem,
        mmi_uc_addr_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_uc_entry_addr_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_addr_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_addr_index
 * DESCRIPTION
 *  Set current highlighted address index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_set_addr_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->done.current_addr_index = nIndex;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_addr_list_get_item
 * DESCRIPTION
 *  Get address list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
pBOOL mmi_uc_addr_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
    S8 *name = NULL;
    U8 i = 0;
    mmi_uc_addr_struct* addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp, 0, sizeof(temp));

    switch(g_uc_p->done.current_addr_type)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            addr = g_uc_p->msg.to_head;            
            MMI_ASSERT(item_index < g_uc_p->msg.to_num);
        }
        break;
    
        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            addr = g_uc_p->msg.cc_head;
            MMI_ASSERT(item_index < g_uc_p->msg.cc_num);            
        }
        break;
    
        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            addr = g_uc_p->msg.bcc_head;
            MMI_ASSERT(item_index < g_uc_p->msg.bcc_num);
        }
        break;
    
        default:
        {
            MMI_ASSERT(0);
        }
    }    

    for (i = 0; i < item_index; i++)
    {
        addr = addr->next;

        MMI_ASSERT(addr);
    }

    if (addr->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
    {
        mmi_asc_to_ucs2(temp, (S8*) addr->addr);

        if (strlen((S8*)addr->addr) <= (MAX_PB_NUMBER_LENGTH + 1))
        {
            name = lookUpNumber(temp);
        }
        
        if (name != NULL && mmi_ucs2strlen(name) > 0)
        {
            mmi_ucs2ncpy((S8*) str_buff, name, MAX_SUBMENU_CHARACTERS);
        }
        else
        {
            mmi_ucs2ncpy((S8*) str_buff, temp, MAX_SUBMENU_CHARACTERS);
        }
    }
    else
    {
        mmi_ucs2ncpy((S8*) str_buff, (S8*) addr->addr, MAX_SUBMENU_CHARACTERS);
    }
    
    *img_buff_p = (PU8) GetImage((U16) (gIndexIconsImageList[item_index]));

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_addr_option
 * DESCRIPTION
 *  Entry function for address option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_addr_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_DONE_ADDR_OPT, mmi_uc_exit_generic, mmi_uc_entry_addr_option, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_addr_option *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE_ADDR_OPT);

    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_DONE);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_EDIT);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_DELETE);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_DELETE_ALL);
    }
    else
    {    
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_DONE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_EDIT);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_DELETE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_DELETE_ALL);
    }

    if ((g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num ) < MMI_UC_MAX_ADDRESS_NUM)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_NUMBER);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_NUMBER_GROUP);

        if (g_uc_p->msg_type.caller_specific_msg_type != MMI_UC_MSG_TYPE_SMS_ONLY)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_EMAIL);        
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_EMAIL_GROUP);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_EMAIL);        
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_EMAIL_GROUP);        
        }
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_NUMBER);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_NUMBER_GROUP);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_EMAIL);        
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_ADDR_ADD_EMAIL_GROUP);        
    }

    switch(g_uc_p->done.current_addr_type)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            title_id = STR_UC_TO_OPTION_ID;
        }
        break;

        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            title_id = STR_UC_CC_OPTION_ID;
        }
        break;

        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            title_id = STR_UC_BCC_OPTION_ID;
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
    }

    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT_ADDR);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT_ADDR, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT_ADDR);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        title_id,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_done
 * DESCRIPTION
 *  Funtion is called when addr done menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_done(void)
{
    SetLeftSoftkeyFunction(mmi_uc_go_back_to_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_go_back_to_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_add_number
 * DESCRIPTION
 *  Funtion is called when addr add number menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_add_number(void)
{    
    /* use g_uc_p->done.to buffer to store phone number */
    /*here use MMI_UC_MAX_EMAIL_LEN, because to declare as MMI_UC_MAX_EMAIL_LEN*/
    memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
    g_uc_p->done.state = MMI_UC_DONE_STATE_ADD_NUMBER;

    SetLeftSoftkeyFunction(mmi_uc_entry_add_number, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_add_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_add_email
 * DESCRIPTION
 *  Funtion is called when addr add email menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_add_email(void)
{
    /* use g_uc_p->done.to buffer to store email */
    memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
    g_uc_p->done.state = MMI_UC_DONE_STATE_ADD_EMAIL;

    SetLeftSoftkeyFunction(mmi_uc_entry_add_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_add_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_edit
 * DESCRIPTION
 *  Funtion is called when addr edit menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_edit(void)
{
    /* use g_uc_p->done.to buffer to store edited address */
    memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);

    SetLeftSoftkeyFunction(mmi_uc_pre_entry_edit_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_pre_entry_edit_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_delete
 * DESCRIPTION
 *  Funtion is called when addr delete menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_delete(void)
{

    SetLeftSoftkeyFunction(mmi_uc_entry_delete_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_delete_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_delete_all
 * DESCRIPTION
 *  Funtion is called when addr delete all menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_delete_all(void)
{

    SetLeftSoftkeyFunction(mmi_uc_entry_delete_all_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_delete_all_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_add_number_group
 * DESCRIPTION
 *  Funtion is called when add number by group menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_add_number_group(void)
{
    g_uc_p->done.state = MMI_UC_DONE_STATE_ADD_NUMBER_GROUP;
    SetLeftSoftkeyFunction(mmi_uc_entry_add_addr_group, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_add_addr_group, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_addr_opt_add_email_group
 * DESCRIPTION
 *  Funtion is called when add email address by group menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_addr_opt_add_email_group(void)
{
    g_uc_p->done.state = MMI_UC_DONE_STATE_ADD_EMAIL_GROUP;
    SetLeftSoftkeyFunction(mmi_uc_entry_add_addr_group, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_add_addr_group, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_go_back_to_done
 * DESCRIPTION
 *  Entry done screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_go_back_to_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(IsScreenPresent(SCR_ID_UC_OPT_DONE));

    GoBackToHistory(SCR_ID_UC_OPT_DONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_add_number
 * DESCRIPTION
 *  Entry msg number screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_add_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_NUMBER, NULL, mmi_uc_entry_add_number, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_NUMBER);

    RegisterInputBoxEmptyFunction(mmi_uc_add_number_empty);
    RegisterInputBoxNotEmptyFunction(mmi_uc_add_number_not_empty);
    
    ShowCategory5Screen(
        STR_UC_ADD_NUMBER_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_PHONE_NUMBER,
        (U8*) g_uc_p->done.to,  /* use g_uc_p->done.to buffer to store phone number */
    #ifdef __MMI_MMS_2__
        MMI_UC_MAX_PHONE_NUMBER_LEN + 1,
    #else /* __MMI_MMS_2__ */
        MAX_DIGITS_SMS,
    #endif /* __MMI_MMS_2__ */
        guiBuffer);

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_add_number_empty
 * DESCRIPTION
 *  LSK handle when number input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_add_number_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
    SetLeftSoftkeyFunction(mmi_uc_search_phb_number, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_add_number_not_empty
 * DESCRIPTION
 *  LSK handle when number input is not empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_add_number_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_uc_addr_add_number_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_search_phb_number
 * DESCRIPTION
 *  Entry phonebook entry list to select phone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_search_phb_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UC_MULTI_SELECT__
    mmi_phb_generic_multi_select_list_pre_entry(MMI_PHB_ENTRY_FIELD_NUMBER, MMI_UC_MAX_ADDRESS_NUM, mmi_uc_get_multi_addr_callback, mmi_uc_check_valid_address);
#else
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmi_uc_get_address_from_phb);
#endif/*__MMI_UC_MULTI_SELECT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_address_from_phb
 * DESCRIPTION
 *  Get phonebook number
 * PARAMETERS
 *  name        [IN]        Name
 *  number      [IN]        Number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_address_from_phb(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER ||
        g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_NUMBER)
    {
        
    #ifdef __MMI_MMS_2__
        if (mmi_ucs2strlen((PS8) number) > (MMI_UC_MAX_PHONE_NUMBER_LEN))
    #else /* __MMI_MMS_2__ */
        if (mmi_ucs2strlen((PS8) number) > (MAX_DIGITS_SMS - 1))
    #endif /* __MMI_MMS_2__ */ 
        {
            DisplayPopup(
                (PU8) GetString(STR_UC_ADDR_LENGTH_EXCEED_ID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL ||
             g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_EMAIL)
    {
        if (mmi_ucs2strlen((PS8) number) > (MMI_UC_MAX_EMAIL_LEN ))
        {
            DisplayPopup(
                (PU8) GetString(STR_UC_ADDR_LENGTH_EXCEED_ID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
            return;
        }
    }

    memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
    if (number)
    {
        mmi_ucs2ncpy((S8*) g_uc_p->done.to, (PS8) number, MMI_UC_MAX_EMAIL_LEN);
    }

    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER)
    {
        HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_NUMBER, 
                       SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_NUMBER, 
                       mmi_uc_entry_add_number);

        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_NUMBER);
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL)
    {
        HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_EMAIL, 
                       SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_EMAIL, 
                       mmi_uc_entry_add_email);

        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_EMAIL);
    }    
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_NUMBER ||
             g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_EMAIL)
    {
        HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT_EDIT, 
                       SCR_ID_UC_OPT_DONE_ADDR_OPT_EDIT, 
                       mmi_uc_entry_edit_addr);
        
        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_OPT_EDIT);
    }
    else
    {
        MMI_ASSERT(0);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_addr_add_number_done
 * DESCRIPTION
 *  Get phonebook number
 * PARAMETERS
 *  name        [IN]        Name
 *  number      [IN]        Number
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_addr_add_number_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_ucs2strlen((S8*)g_uc_p->done.to) < MMI_UC_MIN_ADDR_LEN)
    {
        DisplayPopup(
                (PU8) GetString(STR_UC_ADDR_LENGTH_TOO_SHORT_ID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
                
        return;
    }

    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER)
    {    
        if (mmi_uc_check_duplicate_address(g_uc_p->done.to,
                               MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                               g_uc_p->done.current_addr_type) != NULL)
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                    
            DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            return;
        }

        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            /* Check if the msg size exceeds the MMS limitation */
            U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);

            if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size))
            {
                mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);

                return;
            }
        }       
    
        result = mmi_uc_add_address(g_uc_p->done.to,
                                    MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                   g_uc_p->done.current_addr_type); 
        
        MMI_ASSERT(result);

        /* update the highlighted address to the new one */
        if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
        {
            g_uc_p->done.current_addr_index = g_uc_p->msg.to_num - 1;
        }
        else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
        {
            g_uc_p->done.current_addr_index = g_uc_p->msg.cc_num - 1;
        }
        else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_BCC)
        {
            g_uc_p->done.current_addr_index = g_uc_p->msg.bcc_num - 1;
        }
        else
        {
            MMI_ASSERT(0);
        }

        /* reset guibuffer */
        if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
        {
            result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_LIST, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
            
            MMI_ASSERT(result);
        }

    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_NUMBER)
    {
        mmi_uc_addr_struct* addr = mmi_uc_get_highlighted_addr();
        mmi_uc_addr_struct* duplicate_addr = NULL;
        U8 ascii_addr[MMI_UC_MAX_PHONE_NUMBER_LEN + 1];
        U16 len = 0;

        duplicate_addr = mmi_uc_check_duplicate_address(g_uc_p->done.to,
                               MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                               g_uc_p->done.current_addr_type);

        if ((duplicate_addr != NULL) && 
            ((duplicate_addr != addr) ||
             (mmi_uc_check_duplicate_address_with_start_addr(g_uc_p->done.to,
                                       MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                       duplicate_addr->next) != NULL)))
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);

            DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            return;
        }
    
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            /* Check if the msg size exceeds the MMS limitation */
            U16 ori_addr_len = strlen((char*)addr->addr);
            U8* ori_ucs2_addr = OslMalloc((ori_addr_len + 1) * ENCODING_LENGTH);
            U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);
            U32 ori_addr_size = 0;

            memset(ori_ucs2_addr, 0, (ori_addr_len + 1) * ENCODING_LENGTH);
            mmi_asc_to_ucs2((S8*)ori_ucs2_addr, (S8*)addr->addr);
            ori_addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)ori_ucs2_addr);
            OslMfree(ori_ucs2_addr);

            if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size - ori_addr_size))
            {
                mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                return;
            }
        }

        memset(ascii_addr, 0, sizeof(ascii_addr));
        mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) g_uc_p->done.to, MMI_UC_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH);

        len = strlen((char*)ascii_addr);
        MMI_ASSERT(len <= MMI_UC_MAX_PHONE_NUMBER_LEN);

        kal_adm_free(g_uc_p->main.mem_pool_id , addr->addr);        
        addr->addr = kal_adm_alloc(g_uc_p->main.mem_pool_id, len + 1);
        MMI_ASSERT(addr->addr);
        
        memset(addr->addr, 0, len + 1);
        memcpy(addr->addr, ascii_addr, len);      
        
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (!IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
    {
        result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
        
        MMI_ASSERT(result);
    }
    
    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }
    
    mmi_uc_update_msg_size();
    
    GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_add_email
 * DESCRIPTION
 *  Entry msg email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_add_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_EMAIL, NULL, mmi_uc_entry_add_email, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE_ADDR_OPT_ADD_EMAIL);

    RegisterInputBoxEmptyFunction(mmi_uc_add_email_empty);
    RegisterInputBoxNotEmptyFunction(mmi_uc_add_email_not_empty);
    
        ShowCategory5Screen_ext(
        STR_UC_ADD_EMAIL_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) g_uc_p->done.to,  /* use g_uc_p->done.to buffer to store email address */
        MMI_UC_MAX_EMAIL_LEN + 1,
        guiBuffer,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL,
        NULL);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_editor_set_vk_keys(MMI_TRUE, mmi_phb_e_mail_allowed, NULL);
#endif

    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_add_email_empty
 * DESCRIPTION
 *  LSK handle when email input is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_add_email_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SEARCH, 0);
    SetLeftSoftkeyFunction(mmi_uc_search_phb_email, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_add_email_not_empty
 * DESCRIPTION
 *  LSK handle when email input is not empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_add_email_not_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    SetLeftSoftkeyFunction(mmi_uc_addr_add_email_done, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_search_phb_email
 * DESCRIPTION
 *  Entry phonebook entry list to select email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_search_phb_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UC_MULTI_SELECT__
    mmi_phb_generic_multi_select_list_pre_entry(MMI_PHB_ENTRY_FIELD_EMAIL, MMI_UC_MAX_ADDRESS_NUM, mmi_uc_get_multi_addr_callback, mmi_uc_check_valid_address);
#else
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_EMAIL, mmi_uc_get_address_from_phb);
#endif/*__MMI_UC_MULTI_SELECT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_addr_add_email_done
 * DESCRIPTION
 *  Get phonebook number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_addr_add_email_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_uc_is_email_addr_valid(g_uc_p->done.to))
    {
        DisplayPopup(
                (PU8) GetString(STR_GLOBAL_INVALID),
                IMG_GLOBAL_UNFINISHED,
                1,
                MMI_UC_POPUP_TIME_OUT,
                (U8) ERROR_TONE);
        return;
    }

    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL)
    {
        if (mmi_uc_check_duplicate_address(g_uc_p->done.to,
                               MMI_UC_ADDRESS_TYPE_EMAIL,
                               g_uc_p->done.current_addr_type) != NULL)
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
            
            DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            return;
        }
        
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            /* Check if the msg size exceeds the MMS limitation */
            U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);

            if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size))                
            {
                mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);

                return;
            }
        }
        
        result = mmi_uc_add_address(g_uc_p->done.to,
                                    MMI_UC_ADDRESS_TYPE_EMAIL,
                                   g_uc_p->done.current_addr_type); 
        
        MMI_ASSERT(result);

        /* update the highlighted address to the new one */
        if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
        {
            g_uc_p->done.current_addr_index = g_uc_p->msg.to_num - 1;
        }
        else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
        {
            g_uc_p->done.current_addr_index = g_uc_p->msg.cc_num - 1;
        }
        else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_BCC)
        {
            g_uc_p->done.current_addr_index = g_uc_p->msg.bcc_num - 1;
        }
        else
        {
            MMI_ASSERT(0);
        }

        /* reset guibuffer */
        if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
        {
            result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_LIST, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
            
            MMI_ASSERT(result);
        }

    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_EMAIL)
    {
        mmi_uc_addr_struct* addr = mmi_uc_get_highlighted_addr();
        mmi_uc_addr_struct* duplicate_addr = NULL;        
        U16 len = 0;

        duplicate_addr = mmi_uc_check_duplicate_address(g_uc_p->done.to,
                               MMI_UC_ADDRESS_TYPE_EMAIL,
                               g_uc_p->done.current_addr_type);

        if ((duplicate_addr != NULL) &&
            ((duplicate_addr != addr) ||
             (mmi_uc_check_duplicate_address_with_start_addr(g_uc_p->done.to,
                                        MMI_UC_ADDRESS_TYPE_EMAIL,
                                        duplicate_addr->next) != NULL)))
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);

            DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            return;
        }
    
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            /* Check if the msg size exceeds the MMS limitation */
            U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);
            U32 ori_addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)addr->addr);

            if (mmi_uc_check_if_exceed_MMS_size_limitation((addr_size + g_uc_p->msg.msg_size - ori_addr_size)))
            {                
                mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                return;
            }
        }

        len = mmi_ucs2strlen((char*)g_uc_p->done.to);
        MMI_ASSERT(len <= MMI_UC_MAX_EMAIL_LEN);

        kal_adm_free(g_uc_p->main.mem_pool_id , addr->addr);        
        addr->addr = kal_adm_alloc(g_uc_p->main.mem_pool_id, (len + 1) * ENCODING_LENGTH);
        MMI_ASSERT(addr->addr);
        
        memset(addr->addr, 0, (len + 1) * ENCODING_LENGTH);
        memcpy(addr->addr, g_uc_p->done.to, (len * ENCODING_LENGTH));      
        
    }
    else
    {
        MMI_ASSERT(0);
    }    

    if (!IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
    {
        result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
        
        MMI_ASSERT(result);
    }
    
    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }
    
    mmi_uc_update_msg_size();
    
    GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_LIST);
}

   
#ifdef __MMI_UC_MULTI_SELECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_multi_addr_callback
 * DESCRIPTION
 *  Add address group from phonebook callback
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
MMI_BOOL mmi_uc_check_valid_address(U16 cnt_IN, U16 *PhbIndex_IN)
{
    U32 index = 0;
    U8 UC_addr[(MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH];
    U32 cmp_index =0;
    U16 valide_num =0; 

    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER)
    {
    
        U8 PhbNum[MAX_DIGITS + 2];  
        U8 CmpPhbNum[MAX_DIGITS + 2];         
               
        for (index = 0 ; index < cnt_IN; index++)
        {
            /* 1- check all address (email/number) return by phonebook are valid*/
            /* 1a - check digit limitatiom*/  
            U8 type = 0; 
            if (PhoneBook[PhbIndex_IN[index]].tel.type == CSMCC_INTERNATIONAL_ADDR)
            {
#ifdef __MMI_MMS_2__
                if ((PhoneBook[PhbIndex_IN[index]].tel.length + 1) > (MMI_UC_MAX_PHONE_NUMBER_LEN))   
#else
                if ((PhoneBook[PhbIndex_IN[index]].tel.length + 1) > (MAX_DIGITS_SMS - 1))
#endif
                {
                    DisplayPopup(
                        
                     (PU8) GetString(STR_UC_ADDRESS_NUMBER_EXCEED_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "(+)mmi_uc_check_valid_address: (%d) number exceeds *\n",index); 
                    return MMI_FALSE;
                }
            }
            else
            {
#ifdef __MMI_MMS_2__
                if (PhoneBook[PhbIndex_IN[index]].tel.length > (MMI_UC_MAX_PHONE_NUMBER_LEN))   
#else
                if (PhoneBook[PhbIndex_IN[index]].tel.length > (MAX_DIGITS_SMS - 1))
#endif
                {
                    DisplayPopup(
                     (PU8) GetString(STR_UC_ADDRESS_NUMBER_EXCEED_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_uc_check_valid_address: (%d) number exceeds *\n",index); 
                    return MMI_FALSE;
                }
            }
            /* 1b- check if duplicate*/                  
            memset(PhbNum, 0, MAX_DIGITS + 2);
            mmi_phb_convert_to_digit((U8*) PhbNum, (U8*) PhoneBook[PhbIndex_IN[index]].tel.number, MAX_DIGITS + 2);
            
            for (cmp_index = index + 1; cmp_index < cnt_IN; cmp_index++)
            {
                memset(CmpPhbNum, 0, MAX_DIGITS + 2);
                mmi_phb_convert_to_digit((U8*) CmpPhbNum, (U8*) PhoneBook[PhbIndex_IN[cmp_index]].tel.number, MAX_DIGITS + 2);
                if (ComparePhoneNum(PhbNum, CmpPhbNum) == MMI_TRUE)
                //if (!memcmp(PhoneBook[PhbIndex_IN[index]].tel.number, PhoneBook[PhbIndex_IN[cmp_index]].tel.number, (MAX_PB_NUMBER_LENGTH + 1) / 2))
                {

                    DisplayPopup(
                     (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_uc_check_valid_address: (%d) number duplicate *\n",index); 
                    return MMI_FALSE;
                }
            }

            /* 2 - check the address returned by phb is duplicate with UC number list*/ 
            /*still memset email although current is number*/
            memset(UC_addr, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            if (PhoneBook[PhbIndex_IN[index]].tel.type == CSMCC_INTERNATIONAL_ADDR)
            {
                type = 1;
                mmi_asc_to_ucs2((S8*) UC_addr, "+");
            }
            mmi_asc_n_to_ucs2(
                 (S8*) &UC_addr[type * ENCODING_LENGTH], 
                 (S8*) PhbNum, 
                 PhoneBook[PhbIndex_IN[index]].tel.length);

            if (mmi_uc_check_duplicate_address(UC_addr,
                            MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                            g_uc_p->done.current_addr_type) != NULL)
            {
                DisplayPopup(
                    (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_uc_check_valid_address: (%d) number duplicate(UC) *\n",index);  
                return MMI_FALSE;
            }
            valide_num++;
        }/*for*/
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL)
    {
        U8* email_addr;
        U8 addr_length;

        
        for (index = 0 ; index < cnt_IN; index++)
        {  
            email_addr = mmi_phb_get_email_p(PhbIndex_IN[index], &addr_length);
            /*because when call 2nd mmi_phb_get_email_p, the orig address will be changed. because mmi_phb_get_email_p use global memory*/
            memset(UC_addr, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            strcpy((S8*)UC_addr,(S8*)email_addr);
            /* 1- check all address (email/number) return by phonebook are valid*/
            /* 1a - check email len limitatiom*/  
            if ( addr_length > MMI_UC_MAX_EMAIL_LEN)
            {
                DisplayPopup(
                 (PU8) GetString(STR_UC_ADDRESS_NUMBER_EXCEED_ID),
                 IMG_GLOBAL_UNFINISHED,
                 1,
                 MMI_UC_POPUP_TIME_OUT,
                 (U8) ERROR_TONE);
                
                return MMI_FALSE;

            }
            /* 1b- check if duplicate*/
            for (cmp_index = index + 1; cmp_index < cnt_IN; cmp_index++)
            {
                /*get next mail addr*/
                email_addr = mmi_phb_get_email_p(PhbIndex_IN[cmp_index], &addr_length);
                if (!strcmp((S8*)UC_addr, (S8*)email_addr))
                {
                    
                    DisplayPopup(
                     (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_uc_check_valid_address: (%d) email duplicate *\n",index); 
                    return MMI_FALSE;
                }
            }
            /* 2 - check the email address returned by phb is duplicate with UC email list*/ 

            memset(UC_addr, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);        
            mmi_asc_n_to_ucs2((S8*) UC_addr, (S8*) email_addr, addr_length);

            if (!mmi_uc_is_email_addr_valid(UC_addr))
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_INVALID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_uc_check_valid_address: (%d) email invalid *\n",index); 
                    return MMI_FALSE;;
            }

            if (mmi_uc_check_duplicate_address(UC_addr,
                               MMI_UC_ADDRESS_TYPE_EMAIL,
                               g_uc_p->done.current_addr_type) != NULL)
            {
                DisplayPopup(
                 (PU8) GetString(STR_UC_DUPLICATE_ADDRESS_ID),
                 IMG_GLOBAL_UNFINISHED,
                 1,
                 MMI_UC_POPUP_TIME_OUT,
                 (U8) ERROR_TONE);
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "mmi_uc_check_valid_address: (%d) email duplicate(UC) *\n",index); 

                return MMI_FALSE;
            }
            valide_num++;
        }/*for*/

    }
    /*check if */
    if ((g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num + valide_num) > MMI_UC_MAX_ADDRESS_NUM)
    {
         DisplayPopup(
            (PU8) GetString(STR_UC_ADDRESS_NUMBER_EXCEED_ID),
            IMG_GLOBAL_UNFINISHED,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
         return MMI_FALSE;
    }                 

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_multi_addr_callback
 * DESCRIPTION
 *  Add mltiple address from phonebook callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * this api is only be called when all info in phbindex is correct
 *****************************************************************************/
void mmi_uc_get_multi_addr_callback (U16 cnt, U16 *PhbIndex)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;
    BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
         
        return;
    }
    
    index = 0;
    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER)
    {
        U8 PhbNum[MAX_DIGITS + 2];        
        
        for (; index < cnt; index++)
        {        
            U8 type = 0;

            memset(PhbNum, 0, MAX_DIGITS + 2);
            mmi_phb_convert_to_digit((U8*) PhbNum, (U8*) PhoneBook[PhbIndex[index]].tel.number, MAX_DIGITS + 2);
            /*still memset email len, although it's phone number case*/
            memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            if (PhoneBook[PhbIndex[index]].tel.type == CSMCC_INTERNATIONAL_ADDR)
            {
                type = 1;
                mmi_asc_to_ucs2((S8*) g_uc_p->done.to, "+");
            }
            mmi_asc_n_to_ucs2(
                (S8*) &g_uc_p->done.to[type * ENCODING_LENGTH], 
                (S8*) PhbNum, 
                PhoneBook[PhbIndex[index]].tel.length);

            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                /* Check if the msg size exceeds the MMS limitation */
                U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);

                if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size))
                {
                    mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
                    }
                    else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_OPT);                 
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }                
                    return;
                }
            }
    
            result = mmi_uc_add_address(g_uc_p->done.to,
                                        MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                       g_uc_p->done.current_addr_type);         
            MMI_ASSERT(result);
            
            /* update the highlighted address to the new one */
            if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.to_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.cc_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_BCC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.bcc_num - 1;
            }
            else
            {
                MMI_ASSERT(0);
            }

            if (!IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }
            /* reset guibuffer */
            else
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_LIST, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            
            mmi_uc_update_msg_size();
        }        
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL)
    {
        U8* email_addr;
        U8 addr_length;
                
        for (; index < cnt; index++)
        {        

            email_addr = mmi_phb_get_email_p(PhbIndex[index], &addr_length);
  
            memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);            
            mmi_asc_n_to_ucs2((S8*) g_uc_p->done.to, (S8*) email_addr, addr_length);

            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                /* Check if the msg size exceeds the MMS limitation */
                U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);

                if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size))                
                {
                    mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
                    }
                    else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_OPT);                 
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }                              
                    return;
                }
            }
            
            result = mmi_uc_add_address(g_uc_p->done.to,
                                        MMI_UC_ADDRESS_TYPE_EMAIL,
                                       g_uc_p->done.current_addr_type); 
            
            MMI_ASSERT(result);

            /* update the highlighted address to the new one */
            if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.to_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.cc_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_BCC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.bcc_num - 1;
            }
            else
            {
                MMI_ASSERT(0);
            }
            
            if (!IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }
            /* reset guibuffer */
            else
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_LIST, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            
            mmi_uc_update_msg_size();
        }      
    }
    else
    {
        MMI_ASSERT(0);
    }
        
    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
    {
        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_LIST);
    }
    else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
    {
        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_OPT);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


#endif /*__MMI_UC_MULTI_SELECT__*/
   
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_get_group_addr_callback
 * DESCRIPTION
 *  Add address group from phonebook callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_get_group_addr_callback (U16 cnt, U16 *PhbIndex)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;
    BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
         
        return;
    }
    
    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER_GROUP)
    {
        U8 PhbNum[MAX_DIGITS + 2];        
        
        for (; index < cnt; index++)
        {        
            U8 type = 0;

            if ((g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num ) >= MMI_UC_MAX_ADDRESS_NUM)
            {
                 DisplayPopup(
                    (PU8) GetString(STR_UC_ADDRESS_NUMBER_EXCEED_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
                 
                if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
                {
                    DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
                }
                else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
                {
                    DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_OPT);                 
                }
                else
                {
                    MMI_ASSERT(0);
                }                
                return;
            }
                    
            memset(PhbNum, 0, MAX_DIGITS + 2);
            mmi_phb_convert_to_digit((U8*) PhbNum, (U8*) PhoneBook[PhbIndex[index]].tel.number, MAX_DIGITS + 2);
            
            /*still memset all, so use MMI_UC_MAX_EMAIL_LEN*/
            memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);
            if (PhoneBook[PhbIndex[index]].tel.type == CSMCC_INTERNATIONAL_ADDR)
            {
                type = 1;
                mmi_asc_to_ucs2((S8*) g_uc_p->done.to, "+");
            }
            mmi_asc_n_to_ucs2(
                (S8*) &g_uc_p->done.to[type * ENCODING_LENGTH], 
                (S8*) PhbNum, 
                PhoneBook[PhbIndex[index]].tel.length);

        #ifdef __MMI_MMS_2__
            if ( mmi_ucs2strlen((S8*)g_uc_p->done.to) > (MMI_UC_MAX_PHONE_NUMBER_LEN))
        #else /* __MMI_MMS_2__ */
            if ( mmi_ucs2strlen((S8*)g_uc_p->done.to) > (MAX_DIGITS_SMS - 1))
        #endif /* __MMI_MMS_2__ */            
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_get_group_addr_callback number length too long *\n");
                continue;
            }

            if (mmi_uc_check_duplicate_address(g_uc_p->done.to,
                               MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                               g_uc_p->done.current_addr_type) != NULL)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_get_group_addr_callback duplicate addr *\n");
                continue;
            }
            
            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                /* Check if the msg size exceeds the MMS limitation */
                U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);

                if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size))
                {
                    mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
                    }
                    else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_OPT);                 
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }                
                    return;
                }
            }
    
            result = mmi_uc_add_address(g_uc_p->done.to,
                                        MMI_UC_ADDRESS_TYPE_PHONE_NUMBER,
                                       g_uc_p->done.current_addr_type);         
            MMI_ASSERT(result);
            
            /* update the highlighted address to the new one */
            if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.to_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.cc_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_BCC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.bcc_num - 1;
            }
            else
            {
                MMI_ASSERT(0);
            }

            if (!IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }
            /* reset guibuffer */
            else
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_LIST, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            
            mmi_uc_update_msg_size();
        }        
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL_GROUP)
    {
        U8* email_addr;
        U8 addr_length;
                
        for (; index < cnt; index++)
        {        
            if ((g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num ) >= MMI_UC_MAX_ADDRESS_NUM)
            {
                 DisplayPopup(
                    (PU8) GetString(STR_UC_ADDRESS_NUMBER_EXCEED_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);

                if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
                {
                    DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
                }
                else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
                {
                    DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_OPT);                 
                }
                else
                {
                    MMI_ASSERT(0);
                }                              
                return;
            }

            email_addr = mmi_phb_get_email_p(PhbIndex[index], &addr_length);
            if ( addr_length > MMI_UC_MAX_EMAIL_LEN)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_get_group_addr_callback email addr length too long *\n");
                continue;
            }
            
            memset(g_uc_p->done.to, 0, (MMI_UC_MAX_EMAIL_LEN + 1) * ENCODING_LENGTH);            
            mmi_asc_n_to_ucs2((S8*) g_uc_p->done.to, (S8*) email_addr, addr_length);

            if (!mmi_uc_is_email_addr_valid(g_uc_p->done.to))
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_get_group_addr_callback invalid email addr *\n");
                continue;
            }

            if (mmi_uc_check_duplicate_address(g_uc_p->done.to,
                               MMI_UC_ADDRESS_TYPE_EMAIL,
                               g_uc_p->done.current_addr_type) != NULL)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_get_group_addr_callback duplicate addr *\n");
                continue;
            }
            
            if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
            {
                /* Check if the msg size exceeds the MMS limitation */
                U32 addr_size = wap_mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar *)g_uc_p->done.to);

                if (mmi_uc_check_if_exceed_MMS_size_limitation(addr_size + g_uc_p->msg.msg_size))                
                {
                    mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_LIST);
                    }
                    else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
                    {
                        DeleteUptoScrID(SCR_ID_UC_OPT_DONE_ADDR_OPT);                 
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }                              
                    return;
                }
            }
            
            result = mmi_uc_add_address(g_uc_p->done.to,
                                        MMI_UC_ADDRESS_TYPE_EMAIL,
                                       g_uc_p->done.current_addr_type); 
            
            MMI_ASSERT(result);

            /* update the highlighted address to the new one */
            if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_TO)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.to_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_CC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.cc_num - 1;
            }
            else if (g_uc_p->done.current_addr_type == MMI_UC_ADDRESS_GROUP_TYPE_BCC)
            {
                g_uc_p->done.current_addr_index = g_uc_p->msg.bcc_num - 1;
            }
            else
            {
                MMI_ASSERT(0);
            }
            
            if (!IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_OPT, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }
            /* reset guibuffer */
            else
            {
                result = HistoryReplace(SCR_ID_UC_OPT_DONE_ADDR_LIST, SCR_ID_UC_OPT_DONE_ADDR_LIST, mmi_uc_entry_addr_list);
                
                MMI_ASSERT(result);
            }

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            
            mmi_uc_update_msg_size();
        }      
    }
    else
    {
        MMI_ASSERT(0);
    }
        
    if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST))
    {
        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_LIST);
    }
    else if (IsScreenPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT))
    {
        GoBackToHistory(SCR_ID_UC_OPT_DONE_ADDR_OPT);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_pre_entry_edit_addr
 * DESCRIPTION
 *  Entry function for add address group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_add_addr_group(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_NUMBER_GROUP)
    {        
        mmi_phb_get_address_from_caller_group(MMI_PHB_ENTRY_FIELD_NUMBER, mmi_uc_get_group_addr_callback);
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_ADD_EMAIL_GROUP)
    {
        mmi_phb_get_address_from_caller_group(MMI_PHB_ENTRY_FIELD_EMAIL, mmi_uc_get_group_addr_callback);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_pre_entry_edit_addr
 * DESCRIPTION
 *  Pre-Entry function for edit address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_pre_entry_edit_addr(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_addr_struct* addr = mmi_uc_get_highlighted_addr();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr->type == MMI_UC_ADDRESS_TYPE_PHONE_NUMBER)
    {
        g_uc_p->done.state = MMI_UC_DONE_STATE_EDIT_NUMBER;        
        mmi_asc_n_to_ucs2((S8*) g_uc_p->done.to, (S8*) addr->addr, MMI_UC_MAX_PHONE_NUMBER_LEN);            
    }
    else if (addr->type == MMI_UC_ADDRESS_TYPE_EMAIL)
    {
        g_uc_p->done.state = MMI_UC_DONE_STATE_EDIT_EMAIL;
        mmi_ucs2ncpy((S8*)g_uc_p->done.to, (S8*) addr->addr, MMI_UC_MAX_EMAIL_LEN);
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_uc_entry_edit_addr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_edit_addr
 * DESCRIPTION
 *  Entry function for edit address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_edit_addr(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_UC_OPT_DONE_ADDR_OPT_EDIT, NULL, mmi_uc_entry_edit_addr, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_DONE_ADDR_OPT_EDIT);

    if (g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_NUMBER)
    {
        RegisterInputBoxEmptyFunction(mmi_uc_add_number_empty);
        RegisterInputBoxNotEmptyFunction(mmi_uc_add_number_not_empty);
        
        ShowCategory5Screen(
            STR_GLOBAL_EDIT,
            IMG_UC_ENTRY_SCRN_CAPTION_ID,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            INPUT_TYPE_PHONE_NUMBER,
            (U8*) g_uc_p->done.to,  /* use g_uc_p->done.to buffer to store phone number */
        #ifdef __MMI_MMS_2__
            MMI_UC_MAX_PHONE_NUMBER_LEN + 1,
        #else /* __MMI_MMS_2__ */
            MAX_DIGITS_SMS,
        #endif /* __MMI_MMS_2__ */
            guiBuffer);
    }
    else if (g_uc_p->done.state == MMI_UC_DONE_STATE_EDIT_EMAIL)
    {
        RegisterInputBoxEmptyFunction(mmi_uc_add_email_empty);
        RegisterInputBoxNotEmptyFunction(mmi_uc_add_email_not_empty);

        ShowCategory5Screen(
            STR_GLOBAL_EDIT,
            IMG_UC_ENTRY_SCRN_CAPTION_ID,
            STR_GLOBAL_OK,
            0,
            STR_GLOBAL_BACK,
            0,
            INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
            (U8*) g_uc_p->done.to,  /* use g_uc_p->done.to buffer to store email address */
            MMI_UC_MAX_EMAIL_LEN + 1,
            guiBuffer);
        
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_editor_set_vk_keys(MMI_TRUE, mmi_phb_e_mail_allowed, NULL);
    #endif        
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_delete_addr
 * DESCRIPTION
 *  Entry function for delete address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_delete_addr(void)
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
            get_string(STR_GLOBAL_DELETE),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_uc_process_delete_addr, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_delete_addr
 * DESCRIPTION
 *  Delete current highlighted address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_delete_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_addr_struct* addr = mmi_uc_get_highlighted_addr();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DeleteScreenIfPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT);

    switch (g_uc_p->done.current_addr_type)
    {
        case MMI_UC_ADDRESS_GROUP_TYPE_TO:
        {
            if (g_uc_p->msg.to_num == 1)
            {
                DeleteScreenIfPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            }
        }
        break;

        case MMI_UC_ADDRESS_GROUP_TYPE_CC:
        {
            if (g_uc_p->msg.cc_num == 1)
            {
                DeleteScreenIfPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            }
        }
        break;
        
        case MMI_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            if (g_uc_p->msg.bcc_num == 1)
            {
                DeleteScreenIfPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST);
            }
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;        
    } 

    mmi_uc_delete_addr(addr);

    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }
    mmi_uc_update_msg_size();

    GoBackHistory();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_delete_all_addr
 * DESCRIPTION
 *  Entry function for delete all address of some group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_delete_all_addr(void)
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
            get_string(STR_GLOBAL_DELETE_ALL),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_uc_process_delete_all_addr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_process_delete_all_addr
 * DESCRIPTION
 *  Delete current highlighted group addresses
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_process_delete_all_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DeleteScreenIfPresent(SCR_ID_UC_OPT_DONE_ADDR_OPT);
    DeleteScreenIfPresent(SCR_ID_UC_OPT_DONE_ADDR_LIST);

    mmi_uc_delete_all_addr(g_uc_p->done.current_addr_type);

    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }
    mmi_uc_update_msg_size();

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_msg_detail
 * DESCRIPTION
 *  Entry function for message detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_msg_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer, *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_MSG_DETAIL);

    info = (PU8) subMenuData;
    info[0] = 0;
    info[1] = 0;
            
    EntryNewScreen(SCR_ID_UC_MSG_DETAIL, mmi_uc_exit_generic,  mmi_uc_entry_msg_detail, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_msg_detail *\n");

    mmi_uc_msg_detail_fill_info(info);
    
    ShowCategory74Screen(
        STR_UC_MESSAGE_DETAIL_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_msg_detail_fill_info
 * DESCRIPTION
 *  Fill msg detail info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_msg_detail_fill_info(U8* information)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* info = information;    
    U32 temp_string_len = 30;
    U8 temp_string[30];
    U8 temp_ucs2_string[30 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* temp_string_len should be the same as length of temp_string[] and temp_ucs2_string[] */
    MMI_ASSERT(temp_string_len == 30);
    
    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
    {
        U32 page;
        U32 total_msg;
        U32 recipient;
        
        page = mmi_uc_get_sms_segment_number();
        recipient = g_uc_p->msg.to_num;
        total_msg = page * recipient;
        
        /* Msg type caption */
        mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_GLOBAL_1));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MESSAGE_TYPE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Msg type */
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_TEXT_MESSAGE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Msg page caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_2));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_PAGES_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Msg page */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);        
        sprintf((char*)temp_string, "%d", page);
        mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Recipient caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_3));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MSG_DETAIL_RECIPIENTS_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Recipient */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);        
        sprintf((char*)temp_string, "%d", recipient);
        mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Total msg caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_4));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_TOTAL_MESSAGES_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Total msg */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);        
        sprintf((char*)temp_string, "%d", total_msg);
        mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        
    }
    else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        FLOAT size = 0;
        U32 att_num = 1;
        U32 recipient;
        mmi_uc_attachment_info_struct* attach = g_uc_p->msg.attachment_head;
        
        recipient = g_uc_p->msg.to_num + g_uc_p->msg.cc_num + g_uc_p->msg.bcc_num ;
        size = (FLOAT)g_uc_p->msg.msg_size / (FLOAT) 1024.0;
          
        /* Msg type caption */
        mmi_ucs2cpy((PS8) info, (PS8) GetString(STR_GLOBAL_1));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MESSAGE_TYPE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Msg type */
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MULTIMEDIA_MESSAGE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");
        
        /* Msg size caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_2));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_SIZE_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Msg size */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);        
        sprintf((char*)temp_string, "%.1f KB", size);
        mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Recipient caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_3));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_MSG_DETAIL_RECIPIENTS_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Recipient */
        memset(temp_string, 0, temp_string_len);
        memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);        
        sprintf((char*)temp_string, "%d", recipient);
        mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len);
        mmi_ucs2cat((PS8) info, (PS8) L"   ");
        mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
        mmi_ucs2cat((PS8) info, (PS8) L"\n\n");

        /* Attachment caption */
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_4));
        mmi_ucs2cat((PS8) info, (PS8) L". ");
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_UC_ATTACHMENT_ID));
        mmi_ucs2cat((PS8) info, (PS8) L":\n");
        
        /* Attachments  */
        if (g_uc_p->msg.total_attachment_num == 0)
        {            
            mmi_ucs2cat((PS8) info, (PS8) L"\n");
        }
        else
        {
            mmi_ucs2cat((PS8) info, (PS8) L"\n");
            for (; att_num <= g_uc_p->msg.total_attachment_num ; att_num++)
            {
                FLOAT attach_size = (FLOAT)attach->object->size / (FLOAT) 1024.0;

                MMI_ASSERT(att_num <= MMI_UC_MAX_ATTACHMENT_NUM);
                MMI_ASSERT(att_num);
                
                memset(temp_string, 0, temp_string_len);                
                memset(temp_ucs2_string, 0, temp_string_len * ENCODING_LENGTH);        

                sprintf((char*)temp_string, " (%.1f KB)", attach_size);
                mmi_asc_n_to_ucs2((S8*)temp_ucs2_string, (S8*)temp_string, temp_string_len - 1);
                
                /*mmi_ucs2cat((PS8) info, (PS8) L"   "); *//*remove, because MAUI_00031978*/ 
                mmi_ucs2cat((PS8) info, (PS8) attach->object->file_name);
                mmi_ucs2cat((PS8) info, (PS8) temp_ucs2_string);
                mmi_ucs2cat((PS8) info, (PS8) L"\n");

                attach = attach->next;
            }
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_insert
 * DESCRIPTION
 *  Entry function for insert type list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_insert(void)
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
    EntryNewScreen(SCR_ID_UC_OPT_INSERT, mmi_uc_exit_generic, mmi_uc_entry_insert, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_insert *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_INSERT);

    if (g_uc_p->msg_type.caller_specific_msg_type == MMI_UC_MSG_TYPE_SMS_ONLY)
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_IMAGE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_AUDIO);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_VIDEO);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_ATTACHMENT);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_IMAGE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_AUDIO);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_VIDEO);
    }
    else
    {    
        if (g_uc_p->msg.total_slide_num == MMI_UC_MAX_MMS_SLIDE_NUM)
        {
            if (g_uc_p->msg.current_slide->image.object != NULL ||
                g_uc_p->msg.current_slide->video.object != NULL)
            {
                mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_IMAGE);
                mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_IMAGE);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_IMAGE);
            #ifdef __MMI_CAMERA__
                mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_IMAGE);
            #endif /* __MMI_CAMERA__ */
            }

            if (g_uc_p->msg.current_slide->audio.object != NULL ||
                g_uc_p->msg.current_slide->video.object != NULL)
            {
                mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_AUDIO);            
                mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_AUDIO);            
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_AUDIO);
            #ifdef __MMI_SOUND_RECORDER__
                mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_AUDIO);
            #endif /* __MMI_SOUND_RECORDER__ */
            }
            
            if (g_uc_p->msg.current_slide->video.object != NULL ||
                g_uc_p->msg.current_slide->image.object != NULL ||
                g_uc_p->msg.current_slide->audio.object != NULL)
            {
                mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_VIDEO);
                mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_VIDEO);
            }
            else
            {
                mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_VIDEO);
            #ifdef __MMI_VIDEO_RECORDER__
                mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_VIDEO);
            #endif /* __MMI_VIDEO_RECORDER__ */
            }
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_IMAGE);
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_AUDIO);
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_VIDEO);
            
        #ifdef __MMI_CAMERA__
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_IMAGE);
        #endif /* __MMI_CAMERA__ */
        
        #ifdef __MMI_SOUND_RECORDER__
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_AUDIO);
        #endif /* __MMI_SOUND_RECORDER__ */
        
        #ifdef __MMI_VIDEO_RECORDER__
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_VIDEO);
        #endif /* __MMI_VIDEO_RECORDER__ */
        }

        if (isInCall() && !IsWapCallPresent())
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_IMAGE);
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_AUDIO);
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_NEW_VIDEO);
        }

        if (g_uc_p->msg.total_attachment_num == MMI_UC_MAX_ATTACHMENT_NUM)
        {
            mmi_frm_hide_menu_item(MENU_ID_UC_OPT_INSERT_ATTACHMENT);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_INSERT_ATTACHMENT);  
        }              
    }

    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT_INSERT);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT_INSERT, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT_INSERT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_UC_INSERT_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_image
 * DESCRIPTION
 *  Funtion is called when insert image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_IMAGE;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_audio
 * DESCRIPTION
 *  Funtion is called when insert audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_AUDIO;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_video
 * DESCRIPTION
 *  Funtion is called when insert video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_VIDEO;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_attachment
 * DESCRIPTION
 *  Funtion is called when insert attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_ATTACHMENT;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_bookmark
 * DESCRIPTION
 *  Funtion is called when insert bookmark menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_TEXT;
    
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_insert_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_text_template
 * DESCRIPTION
 *  Funtion is called when insert attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_text_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_TEXT;
    
    SetLeftSoftkeyFunction(mmi_msg_entry_template_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_msg_entry_template_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_phb_number
 * DESCRIPTION
 *  Funtion is called when insert phb number menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_phb_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_TEXT;
    
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_phb_number, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_insert_phb_number, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_phb_name
 * DESCRIPTION
 *  Funtion is called when insert phb name menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_phb_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_TEXT;
    
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_phb_name, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_insert_phb_name, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


#ifdef __MMI_CAMERA__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_new_image
 * DESCRIPTION
 *  Funtion is called when insert new image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_new_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_IMAGE;
    
    SetLeftSoftkeyFunction(mmi_uc_enter_multimedia_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_enter_multimedia_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_CAMERA__ */


#ifdef __MMI_SOUND_RECORDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_new_audio
 * DESCRIPTION
 *  Funtion is called when insert new audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_new_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_AUDIO;
    
    SetLeftSoftkeyFunction(mmi_uc_enter_multimedia_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_enter_multimedia_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_SOUND_RECORDER__ */


#ifdef __MMI_VIDEO_RECORDER__
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_insert_new_video
 * DESCRIPTION
 *  Funtion is called when insert new video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_insert_new_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_VIDEO;
    
    SetLeftSoftkeyFunction(mmi_uc_enter_multimedia_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_enter_multimedia_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}
#endif /* __MMI_VIDEO_RECORDER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_enter_multimedia_app
 * DESCRIPTION
 *  Function for users to enter MM application to add new object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_enter_multimedia_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    U32 max_file_size = 0;
    U32 smil_size = 0;
    U16 temp_file_path[20] = L"D:\\temp.tmp";
    U16 file_name_size = 50;
    MMI_BOOL is_back = CheckIsBackHistory();
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT, mmi_uc_exit_generic, mmi_uc_enter_multimedia_app, NULL);
    
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMain.c] mmi_uc_enter_multimedia_app type=%d *\n",
                         g_uc_p->main.highlighted_object_type);    

    if (is_back)
    {
        StartTimer(UC_MSG_TYPE_CHECK_TIMER_ID, MMI_UC_MSG_TYPE_CHECK_TIME, mmi_uc_enter_multimedia_app_add_object);                
    }
    else
    {
        switch(g_uc_p->main.highlighted_object_type)
        {
#ifdef __MMI_CAMERA__        
            case MMI_UC_OBJECT_TYPE_IMAGE:
            {
                mmi_camera_entry_for_external_request(mmi_uc_enter_multimedia_app_callback);
            }
            break;
#endif

#ifdef __MMI_SOUND_RECORDER__
            case MMI_UC_OBJECT_TYPE_AUDIO:
            {
                if (g_uc_p->msg.current_slide->audio.object != NULL ||
                    g_uc_p->msg.current_slide->video.object != NULL)
                {
                    
                    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
                }

                smil_size = wap_mma_uc_calc_object_smil_size(MMA_INSERT_AUDIO, (kal_wchar*)temp_file_path);

                if (g_uc_p->mms_info.max_mms_size < (g_uc_p->msg.msg_size + new_slide_size + smil_size + file_name_size))
                {
                    
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[UnifiedComposerMain.c] Size exceed! mmi_uc_enter_multimedia_app max=%d max_mms=%d msg=%d slide=%d smil=%d *\n",
                                                             max_file_size,g_uc_p->mms_info.max_mms_size,g_uc_p->msg.msg_size,new_slide_size, smil_size);     
                    max_file_size = 0;
                }
                else  /*avoid overflow*/
                {
                    max_file_size = (g_uc_p->mms_info.max_mms_size - g_uc_p->msg.msg_size - new_slide_size - smil_size - file_name_size) / 1024;
                }
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*[UnifiedComposerMain.c] mmi_uc_enter_multimedia_app max=%d max_mms=%d msg=%d slide=%d smil=%d *\n",
                                         max_file_size,g_uc_p->mms_info.max_mms_size,g_uc_p->msg.msg_size,new_slide_size, smil_size);     

                if (max_file_size > 0)
                {
                    mmi_sndrec_entry_record_in_sms(NULL, max_file_size, (void(*)(BOOL, U16*))mmi_uc_enter_multimedia_app_callback);
                }
                else
                {
                    mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                    DeleteScreenIfPresent(SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                    return;
                }            
            }
            break;
#endif

#ifdef __MMI_VIDEO_RECORDER__

            case MMI_UC_OBJECT_TYPE_VIDEO:
            {
                if (g_uc_p->msg.current_slide->video.object != NULL ||
                    g_uc_p->msg.current_slide->image.object != NULL ||
                    g_uc_p->msg.current_slide->audio.object != NULL)
                {
                    
                    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
                }

                smil_size = wap_mma_uc_calc_object_smil_size(MMA_INSERT_VIDEO, (kal_wchar*)temp_file_path);

                if (g_uc_p->mms_info.max_mms_size <  (g_uc_p->msg.msg_size + new_slide_size + smil_size + file_name_size))
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*[UnifiedComposerMain.c] Size Exceed! mmi_uc_enter_multimedia_app max=%d max_mms=%d msg=%d slide=%d smil=%d *\n",
                                         max_file_size,g_uc_p->mms_info.max_mms_size,g_uc_p->msg.msg_size,new_slide_size, smil_size);     
                    max_file_size = 0;

                }
                else
                {
                    max_file_size = (g_uc_p->mms_info.max_mms_size - g_uc_p->msg.msg_size - new_slide_size - smil_size - file_name_size) / 1024;            
                }
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                         "*[UnifiedComposerMain.c] mmi_uc_enter_multimedia_app max=%d max_mms=%d msg=%d slide=%d smil=%d *\n",
                                         max_file_size,g_uc_p->mms_info.max_mms_size,g_uc_p->msg.msg_size,new_slide_size, smil_size);     
                if (max_file_size > 0)
                {
                    if (max_file_size >= 30) /*because video recorder can not record with accurate size, walk around*/
                    {
                        mmi_vdorec_entry_for_external_request(NULL,  max_file_size, mmi_uc_enter_multimedia_app_callback);        
                    }
                    else
                    {
                        mmi_uc_display_popup(MMI_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO);
                        DeleteScreenIfPresent(SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                        return;
                    }
                }
                else
                {
                    mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
                    DeleteScreenIfPresent(SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);
                    return;
                }
            }
            break;
#endif
            default:
            {
                MMI_ASSERT(0);
            }
            break;
        }
    }

    return;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_enter_multimedia_app_callback
 * DESCRIPTION
 *  Add object from Multimedia application
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_enter_multimedia_app_callback(MMI_BOOL result, S8* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flie_path_len = 0;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                         "*[UnifiedComposerMain.c] mmi_uc_enter_multimedia_app_callback result=%d *\n",
                         result);

    if (g_uc_p->main.file_path)
    {
        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
        g_uc_p->main.file_path = NULL;
    }

    if (result)
    {        
        flie_path_len = mmi_ucs2strlen((S8*)file_path);    

        g_uc_p->main.file_path = kal_adm_alloc(
                                        g_uc_p->main.mem_pool_id, 
                                        (flie_path_len + 1) * ENCODING_LENGTH);

        MMI_ASSERT(g_uc_p->main.file_path);
        mmi_ucs2ncpy((S8*)g_uc_p->main.file_path, (S8*)file_path, flie_path_len);
    }

    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_enter_multimedia_app_add_object
 * DESCRIPTION
 *  Add object from Multimedia application
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_enter_multimedia_app_add_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_image_path[MMI_UC_MAX_TEMP_FILE_LEN];
    mmi_uc_result result;
    U32 new_slide_size = 0;
    mma_insert_check_struct check_result;
    mmi_uc_slide_struct* slide = g_uc_p->msg.current_slide;
    mmi_uc_object_struct* object = NULL;
    U16* filePath = (U16*)g_uc_p->main.file_path;
    mma_insert_type_enum mms_type = mmi_uc_convert_to_mms_insert_type(g_uc_p->main.highlighted_object_type);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Success case in callback */
    if (g_uc_p->main.file_path != NULL)
    {                    
        memset(&check_result, 0, sizeof(mma_insert_check_struct));
        memset(mmi_uc_image_path, 0, MMI_UC_MAX_TEMP_FILE_LEN);                

        switch (g_uc_p->main.highlighted_object_type)
        {
            case MMI_UC_OBJECT_TYPE_IMAGE:
            {
                if (g_uc_p->msg.current_slide->image.object != NULL ||
                    g_uc_p->msg.current_slide->video.object != NULL)
                {
                   
                    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
                }
            }
            break;

            case MMI_UC_OBJECT_TYPE_AUDIO:
            {
                if (g_uc_p->msg.current_slide->audio.object != NULL ||
                    g_uc_p->msg.current_slide->video.object != NULL)
                {
                    
                    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
                }
            }
            break;

            case MMI_UC_OBJECT_TYPE_VIDEO:
            {
                if (g_uc_p->msg.current_slide->video.object != NULL ||
                    g_uc_p->msg.current_slide->image.object != NULL ||
                    g_uc_p->msg.current_slide->audio.object != NULL)
                {
                   
                    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
                }
            }
            break;
            
            default:
            {
                MMI_ASSERT(0);
                return;
            }
            break;
        }

        if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_IMAGE &&
            g_uc_p->mms_info.image_resize.enable)
        {        

            S32 resize_result;

            if (!mmi_uc_is_valid_image(filePath))
            {
                mmi_uc_display_resize_result_popup((U16)MMI_UC_RESIZING_FAILED_IN_GDI_FAILED);
                mmi_uc_delete_between_screens(SCR_ID_UC_OPT,SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);        
                kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                g_uc_p->main.file_path = NULL;
                return;                
            }

            MMI_UC_MAKE_IMAGE_FILE_PATH(mmi_uc_image_path, ++g_uc_p->main.image_no);
            resize_result = mmi_uc_resize_image(
                                    (U8*) filePath, 
                                    mmi_uc_image_path, 
                                    g_uc_p->mms_info.image_resize.width,
                                    g_uc_p->mms_info.image_resize.height);

            /* Error ! */
            if (resize_result < 0)
            {

                    mmi_uc_display_resize_result_popup((U16)resize_result);
                    mmi_uc_delete_between_screens(SCR_ID_UC_OPT,SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);        
                    kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
                    g_uc_p->main.file_path = NULL;
                    return;                
            }
            /* resized */
            else if (resize_result)
            {
                filePath = (PU16)mmi_uc_image_path;
            }
                /* resize_result == 0 means no need to resize */
            memset(&check_result, 0, sizeof(mma_insert_check_struct));        
        }

        wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                       filePath, 
                                       mms_type, 
                                       (g_uc_p->msg.msg_size + new_slide_size), 
                                       g_uc_p->mms_info.max_mms_size,
                                       &check_result);
        
        if (!(check_result.result))
        {
            result = mmi_uc_convert_mms_check_result(&check_result);
            mmi_uc_display_popup(result);
            mmi_uc_delete_between_screens(SCR_ID_UC_OPT,SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);        
            if (mmi_ucs2strlen((S8*)mmi_uc_image_path))
            {
                FS_Delete((WCHAR*)mmi_uc_image_path);
            }
            kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
            g_uc_p->main.file_path = NULL;
            return;
        }

        if (new_slide_size > 0)
        {
            slide = mmi_uc_insert_slide(g_uc_p->msg.current_slide);
            g_uc_p->msg.current_slide = slide;
            g_uc_p->msg.current_slide_num = slide->slide_num;
        }

        object = mmi_uc_insert_object((S8*) filePath, g_uc_p->main.highlighted_object_type);
        object->drm_type = check_result.drm_type;
        mmi_uc_insert_object_to_slide(object, slide, g_uc_p->main.highlighted_object_type);

        /* Determine layout */
        if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_IMAGE ||
            g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_VIDEO)
        {
            if (g_uc_p->msg.layout == MMI_UC_LAYOUT_DEFAULT)
            {
                if (g_uc_p->msg.current_slide->text.char_count)
                {
                    g_uc_p->msg.layout = MMI_UC_LAYOUT_THUMBNAIL_AT_BOTTOM;
                }
                else
                {
                    g_uc_p->msg.layout = MMI_UC_LAYOUT_THUMBNAIL_AT_TOP;
                }
            }
        }   
        
        if (mmi_uc_change_msg_type_if_needed())
        {
            mmi_uc_insert_signature_check();
        }
        
        mmi_uc_update_msg_size();
        
        if (new_slide_size)
        {
            mmi_uc_switch_slide(g_uc_p->msg.current_slide);
        }
        else
        {
            mmi_uc_editor_initialize();
            mmi_uc_set_editor_info(g_uc_p->msg.current_slide);
        }
    }
    
    if (GetExitScrnID() == SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT)
    {
        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
    else
    {
        mmi_uc_delete_between_screens(SCR_ID_UC_OPT,SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT);        
    }    

    if (g_uc_p->main.file_path != NULL)
    {
        kal_adm_free(g_uc_p->main.mem_pool_id, g_uc_p->main.file_path);
        g_uc_p->main.file_path = NULL;
    }
        
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_select_fmgr_object
 * DESCRIPTION
 *  Function for users to select inserted object according to selected type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_select_fmgr_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*FMGR_FILTER_INIT(&filter);*/  /*will be handled in mma_uc_set_file_mgr_filter*/
    
    switch (g_uc_p->main.highlighted_object_type)
    {
        case MMI_UC_OBJECT_TYPE_IMAGE:
        {
            if (g_uc_p->mms_info.creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE);
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_IMAGE_TYPES);*/
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE);
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_IMAGE_TYPES);*/
            }                
        }
        break;

        case MMI_UC_OBJECT_TYPE_AUDIO:
        {
            if (g_uc_p->mms_info.creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE);
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_AUDIO_TYPES);*/
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE);
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_AUDIO_TYPES);*/
            }                
        }
        break;

        case MMI_UC_OBJECT_TYPE_VIDEO:
        {
            if (g_uc_p->mms_info.creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE); 
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_VIDEO_TYPES);*/
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE); 
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_VIDEO_TYPES);*/
            }                
        }
        break;

        case MMI_UC_OBJECT_TYPE_ATTACHMENT:
        {
            if (g_uc_p->mms_info.creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE); 
                /*mmi_uc_set_file_mgr_filter(&filter, MMA_OPEN_RESTRICTED_ATTACHMENT_TYPES);*/
            }
            else
            {
                mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE); 
                /*mmi_uc_set_file_mgr_filter_all(&filter);*/
            }                
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    /* FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);*/  /*will be handled in mma_uc_set_file_mgr_filter*/
    /*FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);*/ /*will be handled in mma_uc_set_file_mgr_filter*/

    if (GetExitScrnID() == SCR_ID_UC_OPT_INSERT)
    {
        if(g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
        {
            mmi_fmgr_select_path_and_enter(
                        APP_MESSAGES,
                        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
                        filter,
                        (S8*) L"root",
                        (PsExtFuncPtr) mmi_uc_select_object_from_fm_to_insert);           
        }
        else
        {
            mmi_fmgr_select_path_and_enter(
                        APP_MESSAGES,
                        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
                        filter,
                        (S8*) L"root",
                        (PsExtFuncPtr) mmi_uc_select_object_from_fm_to_insert);
        }
    }
    else if (GetExitScrnID() == SCR_ID_UC_OPT_REPLACE ||
             GetExitScrnID() == SCR_ID_UC_OPT_ATTACHMENT_LIST)
    {
        if(g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
        {
            mmi_fmgr_select_path_and_enter(
                        APP_MESSAGES,
                        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
                        filter,
                        (S8*) L"root",
                        (PsExtFuncPtr) mmi_uc_select_object_from_fm_to_replace);
        }
        else
        {
            mmi_fmgr_select_path_and_enter(
                        APP_MESSAGES,
                        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
                        filter,
                        (S8*) L"root",
                        (PsExtFuncPtr) mmi_uc_select_object_from_fm_to_replace);
        }
    }
    else 
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_select_object_from_fm_to_insert
 * DESCRIPTION
 *  Select object from file manager
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_select_object_from_fm_to_insert(PU16 filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_image_path[MMI_UC_MAX_TEMP_FILE_LEN];
    mmi_uc_result result;
    U32 new_slide_size = 0;
    mma_insert_check_struct check_result;
    mmi_uc_slide_struct* slide = g_uc_p->msg.current_slide;
    mmi_uc_object_struct* object = NULL;
    mmi_uc_attachment_info_struct* att;
    mma_insert_type_enum mms_type = mmi_uc_convert_to_mms_insert_type(g_uc_p->main.highlighted_object_type);
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    memset(mmi_uc_image_path, 0, MMI_UC_MAX_TEMP_FILE_LEN);        
    
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_UC_OPT_INSERT);
        return;
    }

    if ( (handle = FS_GetAttributes((PU16) filePath)) < 0)
    {
        DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(handle)),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
        return;
    }

    mmi_uc_set_processing_screen(STR_UC_INSERT_ID, STR_UC_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0);
    mmi_uc_entry_processing_generic();

    switch (g_uc_p->main.highlighted_object_type)
    {
        case MMI_UC_OBJECT_TYPE_IMAGE:
        {
            if (g_uc_p->msg.current_slide->image.object != NULL ||
                g_uc_p->msg.current_slide->video.object != NULL)
            {
                
                new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
            }
        }
        break;

        case MMI_UC_OBJECT_TYPE_AUDIO:
        {
            if (g_uc_p->msg.current_slide->audio.object != NULL ||
                g_uc_p->msg.current_slide->video.object != NULL)
            {
               
                new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
            }
        }
        break;

        case MMI_UC_OBJECT_TYPE_VIDEO:
        {
            if (g_uc_p->msg.current_slide->video.object != NULL ||
                g_uc_p->msg.current_slide->image.object != NULL ||
                g_uc_p->msg.current_slide->audio.object != NULL)
            {
               
                new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);
            }
        }
        break;
        
        default:
        {
            ;
        }
        break;
    }

    if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_IMAGE &&
        g_uc_p->mms_info.image_resize.enable)
    {        

        /* Check if it is DRM file */
        
        wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                       filePath, 
                                       mms_type, 
                                       g_uc_p->msg.msg_size, 
                                       g_uc_p->mms_info.max_mms_size,
                                       &check_result);

        /* SD and SD without right DRM files cannot be resized. */
        if (check_result.result == MMI_TRUE && 
            (check_result.drm_type == MMA_DRM_SD_NO_RIGHT || check_result.drm_type == MMA_DRM_SD))
        {
            /* allows inserted but display default image for thumbnail for MMA_DRM_SD_NO_RIGHT. */
        }
        else
        {
            S32 resize_result;

            if (!mmi_uc_is_valid_image(filePath))
            {
                mmi_uc_display_resize_result_popup((U16)MMI_UC_RESIZING_FAILED_IN_GDI_FAILED);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                return;
            }

            MMI_UC_MAKE_IMAGE_FILE_PATH(mmi_uc_image_path, ++g_uc_p->main.image_no);
            resize_result = mmi_uc_resize_image(
                                    (U8*) filePath, 
                                    mmi_uc_image_path, 
                                    g_uc_p->mms_info.image_resize.width,
                                    g_uc_p->mms_info.image_resize.height);

            /* Error ! */
            if (resize_result < 0)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                                     "*---mmi_uc_select_object_from_fm_to_insert, mmi_uc_resize_image fail, w=%d, h=%d*\n",g_uc_p->mms_info.image_resize.width,g_uc_p->mms_info.image_resize.height);

                mmi_uc_display_resize_result_popup((U16)resize_result);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                return;                
            }
            /* resized */
            else if (resize_result)
            {
                filePath = (PU16)mmi_uc_image_path;
            }
            /* resize_result == 0 means no need to resize */
        }
        memset(&check_result, 0, sizeof(mma_insert_check_struct));        
    }

    object = mmi_uc_check_duplicate_object(filePath);

    if (g_uc_p->main.highlighted_object_type != MMI_UC_OBJECT_TYPE_ATTACHMENT &&
        object &&
        object->type != MMI_UC_OBJECT_TYPE_ATTACHMENT)
    {        
        U32 obj_smil_size = wap_mma_uc_calc_object_smil_size(mms_type, filePath);
        
        if (!mmi_uc_check_if_exceed_MMS_size_limitation(obj_smil_size + new_slide_size + g_uc_p->msg.msg_size))
        {
            if (new_slide_size > 0)
            {
                slide = mmi_uc_insert_slide(g_uc_p->msg.current_slide);
                g_uc_p->msg.current_slide = slide;
                g_uc_p->msg.current_slide_num = slide->slide_num;                
            }

            mmi_uc_insert_object_to_slide(object, slide, g_uc_p->main.highlighted_object_type);
        }
        else
        {
            mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            return;
        }
    }
    else
    {

        wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                       filePath, 
                                       mms_type, 
                                       (g_uc_p->msg.msg_size + new_slide_size), 
                                       g_uc_p->mms_info.max_mms_size,
                                       &check_result);
        
        if (!(check_result.result))
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                     "*---wap_mma_uc_insert_object_check fail when insert from fmgr ---*\n");
            result = mmi_uc_convert_mms_check_result(&check_result);
            mmi_uc_display_popup(result);
            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            if (mmi_ucs2strlen((S8*)mmi_uc_image_path))
            {
                FS_Delete((WCHAR*)mmi_uc_image_path);
            }
            return;
        }

        if (new_slide_size > 0)
        {
            slide = mmi_uc_insert_slide(g_uc_p->msg.current_slide);
            g_uc_p->msg.current_slide = slide;
            g_uc_p->msg.current_slide_num = slide->slide_num;
        }

        object = mmi_uc_insert_object((S8*) filePath, g_uc_p->main.highlighted_object_type);
        object->drm_type = check_result.drm_type;

        if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
        {
            att = mmi_uc_insert_attachment();
            mmi_uc_insert_object_to_attachment(object, att);
        }
        else
        {
            mmi_uc_insert_object_to_slide(object, slide, g_uc_p->main.highlighted_object_type);
        }       
    }

    fmgr_reset_app_select();        

    /* Determine layout */
    if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_IMAGE ||
        g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_VIDEO)
    {
        if (g_uc_p->msg.layout == MMI_UC_LAYOUT_DEFAULT)
        {
            if (g_uc_p->msg.current_slide->text.char_count)
            {
                g_uc_p->msg.layout = MMI_UC_LAYOUT_THUMBNAIL_AT_BOTTOM;
            }
            else
            {
                g_uc_p->msg.layout = MMI_UC_LAYOUT_THUMBNAIL_AT_TOP;
            }
        }
    }   
    
    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }
    
    mmi_uc_update_msg_size();
    
    if (new_slide_size)
    {
        mmi_uc_switch_slide(g_uc_p->msg.current_slide);
    }
    else
    {
        mmi_uc_editor_initialize();
        mmi_uc_set_editor_info(g_uc_p->msg.current_slide);
    }

    if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
    {
        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
    else
    {
        DeleteBetweenScreen(SCR_ID_UC_PROCESSING, SCR_ID_UC_OPT);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_insert_text_template
 * DESCRIPTION
 *  Insert template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_insert_text_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *templ;
    historyNode *History;
    U16 templateCharNum = 0;    
    U8 result = 1;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_insert_text_template *\n");

    templ = g_msg_cntx.templates[g_msg_cntx.currTemplateIndex];

    if (templ)
    {
        templateCharNum = mmi_ucs2strlen((PS8) templ);

        if (GetHistoryScrID(SCR_ID_UC_EDITOR, &History) == ST_SUCCESS)
        {
            result = wgui_uce_insert_text_template ((U8*) templ, templateCharNum, History->guiBuffer);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    GoBackToHistory(SCR_ID_UC_EDITOR);
    
    /* to pop up without playing tone. editor alreay play tone*/
    /* also pop up no space if not add all characters*/
    if ( (result == 0 && templateCharNum != 0) || (result != templateCharNum) )
    {
        mmi_uc_display_popup(MMI_UC_NO_SPACE);
    }
    
    DeInitTemplates();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_insert_bookmark
 * DESCRIPTION
 *  Entry bookmark list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_insert_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_uc_handle_select_bookmark_rsp, MSG_ID_WAP_SELECT_BOOKMARK_RSP);
    wap_entry_select_bookmark();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_handle_select_bookmark_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_handle_select_bookmark_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_select_bookmark_rsp_struct *msg_rsp = (wap_select_bookmark_rsp_struct*) (inMsg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_handle_select_bookmark_rsp,msg_rsp->result =%d *\n",msg_rsp->result);
    
    if (msg_rsp->result == 1)
    {
        historyNode *History;
        U16 chars_num = strlen((S8*)msg_rsp->url);
        U8 result = 0;

        if (chars_num > 0)
        {
            U8* ucs2_buffer = OslMalloc((chars_num + 1) * ENCODING_LENGTH);

            memset(ucs2_buffer, 0x00, (chars_num + 1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((S8*) ucs2_buffer, (S8*) msg_rsp->url, chars_num);
            
            if (GetHistoryScrID(SCR_ID_UC_EDITOR, &History) == ST_SUCCESS)
            {
                result = wgui_uce_insert_text_template ((U8*) ucs2_buffer, chars_num, History->guiBuffer);
            }
            else
            {
                MMI_ASSERT(0);
            }

            OslMfree(ucs2_buffer);
            
            if (MMI_TRUE == mmi_msg_check_interrupt())
            {                
                if (IsScreenPresent(SCR_ID_UC_EDITOR))
                {
                    DeleteUptoScrID(SCR_ID_UC_EDITOR);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_UC_EDITOR))
                {
                    GoBackToHistory(SCR_ID_UC_EDITOR);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                       
                if (result == 0)
                {            
                    mmi_uc_display_popup(MMI_UC_NO_SPACE);
                }
            }            
        }
        else
        {
            if (MMI_TRUE == mmi_msg_check_interrupt())
            {                
                if (IsScreenPresent(SCR_ID_UC_EDITOR))
                {
                    DeleteUptoScrID(SCR_ID_UC_EDITOR);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else
            {
                if (IsScreenPresent(SCR_ID_UC_EDITOR))
                {
                    GoBackToHistory(SCR_ID_UC_EDITOR);
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_insert_phb_number
 * DESCRIPTION
 *  Highlight Insert PHB number handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_insert_phb_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_ALL_NUMBER, mmi_uc_insert_number_from_phb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_insert_phb_name
 * DESCRIPTION
 *  Highlight Insert PHB name handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_insert_phb_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_NAME, mmi_uc_insert_name_from_phb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_insert_number_from_phb
 * DESCRIPTION
 *  Insert phonebook number into write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_insert_number_from_phb(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;
    U16 char_num;
    U8 result = 1;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_insert_number_from_phb *\n");

    if (NULL != number && (char_num = mmi_ucs2strlen(number)) > 0)
    {
        if (GetHistoryScrID(SCR_ID_UC_EDITOR, &History) == ST_SUCCESS)
        {
            result = wgui_uce_insert_text_template ((U8*) number, char_num, History->guiBuffer);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    GoBackToHistory(SCR_ID_UC_EDITOR);
    
    if (result == 0)
    {
        mmi_uc_display_popup(MMI_UC_NO_SPACE);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_insert_name_from_phb
 * DESCRIPTION
 *  Insert phonebook name into write msg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_insert_name_from_phb(S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    historyNode *History;
    U16 char_num = 0;
    U8 result = 1;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_insert_name_from_phb *\n");

    if (NULL != name && (char_num = mmi_ucs2strlen(name)) > 0)
    {
        if (GetHistoryScrID(SCR_ID_UC_EDITOR, &History) == ST_SUCCESS)
        {
            result = wgui_uce_insert_text_template ((U8*) name, char_num, History->guiBuffer);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_UNFINISHED,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);

        return;
    }

    GoBackToHistory(SCR_ID_UC_EDITOR);
    
    if (result == 0)
    {
        mmi_uc_display_popup(MMI_UC_NO_SPACE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_remove
 * DESCRIPTION
 *  Entry function for remove type list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_remove(void)
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
    EntryNewScreen(SCR_ID_UC_OPT_REMOVE, mmi_uc_exit_generic, mmi_uc_entry_remove, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_remove *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_REMOVE);

    if (g_uc_p->msg.current_slide->image.object)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REMOVE_IMAGE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REMOVE_IMAGE);
    }
    
    if (g_uc_p->msg.current_slide->audio.object)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REMOVE_AUDIO);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REMOVE_AUDIO);
    }

    if (g_uc_p->msg.current_slide->video.object)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REMOVE_VIDEO);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REMOVE_VIDEO);
    }

    if (g_uc_p->msg.total_attachment_num)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REMOVE_ATTACHMENT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REMOVE_ATTACHMENT);
    }

    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT_REMOVE);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT_REMOVE, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT_REMOVE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_UC_REMOVE_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_image
 * DESCRIPTION
 *  Funtion is called when remove image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_IMAGE;
    
    SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_remove_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_audio
 * DESCRIPTION
 *  Funtion is called when remove audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_AUDIO;
    
    SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_remove_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_video
 * DESCRIPTION
 *  Funtion is called when remove video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_VIDEO;
    
    SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_remove_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_attachment
 * DESCRIPTION
 *  Funtion is called when remove attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_remove_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_ATTACHMENT;
    
    SetLeftSoftkeyFunction(mmi_uc_entry_attachment_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_attachment_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_remove_object
 * DESCRIPTION
 *  Remove the object from current slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_remove_object(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_uc_p->main.highlighted_object_type)
    {
        case MMI_UC_OBJECT_TYPE_IMAGE:
        {                        
            if (mmi_uc_is_resized_image(g_uc_p->msg.current_slide->image.object->file_path) == MMI_TRUE)
            {
                FS_Delete((WCHAR*) g_uc_p->msg.current_slide->image.object->file_path);
            }
            
            if (g_uc_p->msg.current_slide->image.object->reference_count > 1)
            {
                g_uc_p->msg.current_slide->image.object->reference_count--;
            }
            else
            {
                mmi_uc_delete_object_from_list(g_uc_p->msg.current_slide->image.object);
            }
            memset(&(g_uc_p->msg.current_slide->image), 0, sizeof(mmi_uc_object_info_struct));
            wgui_uce_delete_object(mmi_uc_convert_to_editor_object_type(MMI_UC_OBJECT_TYPE_IMAGE));

            mmi_uc_reset_layout_if_needed();
            
            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }            
            mmi_uc_update_msg_size();
                
            GoBackToHistory(SCR_ID_UC_EDITOR);
        }
        break;

        case MMI_UC_OBJECT_TYPE_AUDIO:
        {
            if (g_uc_p->msg.current_slide->audio.object->reference_count > 1)
            {
                g_uc_p->msg.current_slide->audio.object->reference_count--;
            }
            else
            {
                mmi_uc_delete_object_from_list(g_uc_p->msg.current_slide->audio.object);
            }
            memset(&(g_uc_p->msg.current_slide->audio), 0, sizeof(mmi_uc_object_info_struct));
            wgui_uce_delete_object(mmi_uc_convert_to_editor_object_type(MMI_UC_OBJECT_TYPE_AUDIO));

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            mmi_uc_update_msg_size();
            
            GoBackToHistory(SCR_ID_UC_EDITOR);
        }
        break;
            
        case MMI_UC_OBJECT_TYPE_VIDEO:
        {
            if (g_uc_p->msg.current_slide->video.object->reference_count > 1)
            {
                g_uc_p->msg.current_slide->video.object->reference_count--;
            }
            else
            {
                mmi_uc_delete_object_from_list(g_uc_p->msg.current_slide->video.object);
            }
            memset(&(g_uc_p->msg.current_slide->video), 0, sizeof(mmi_uc_object_info_struct));
            wgui_uce_delete_object(mmi_uc_convert_to_editor_object_type(MMI_UC_OBJECT_TYPE_VIDEO));

            mmi_uc_reset_layout_if_needed();

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            mmi_uc_update_msg_size();
            
            GoBackToHistory(SCR_ID_UC_EDITOR);
        }
        break;

        case MMI_UC_OBJECT_TYPE_ATTACHMENT:
        {
            mmi_uc_attachment_info_struct* att = mmi_uc_get_attachment_by_index(g_uc_p->main.object_index);
            
            MMI_ASSERT(att->object->reference_count == 1);
            mmi_uc_delete_object_from_list(att->object);
            mmi_uc_delete_attachment_from_list(att);

            if (mmi_uc_change_msg_type_if_needed())
            {
                mmi_uc_insert_signature_check();
            }
            mmi_uc_update_msg_size();

            DisplayPopup((PU8) GetString(STR_UC_REMOVED_ID),
                         IMG_GLOBAL_ACTIVATED,
                         1,
                         MMI_UC_POPUP_TIME_OUT,
                         (U8) SUCCESS_TONE);            

            if (g_uc_p->msg.total_attachment_num == 0)
            {
                wgui_uce_delete_object(mmi_uc_convert_to_editor_object_type(MMI_UC_OBJECT_TYPE_ATTACHMENT));
                DeleteBetweenScreen(SCR_ID_UC_OPT, SCR_ID_UC_OPT_ATTACHMENT_LIST);
            }
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_attachment_list
 * DESCRIPTION
 *  Entry function of attachment list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_attachment_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U32 i = 0;
    mmi_uc_attachment_info_struct* attachment = g_uc_p->msg.attachment_head;
    U16 lsk_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_attachment_list *\n");
    EntryNewScreen(SCR_ID_UC_OPT_ATTACHMENT_LIST, mmi_uc_exit_generic, mmi_uc_entry_attachment_list, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_ATTACHMENT_LIST);
    SetParentHandler(MENU_ID_UC_OPT_REMOVE_ATTACHMENT);
    
    RegisterHighlightHandler(mmi_uc_set_index);

    for (; i < g_uc_p->msg.total_attachment_num; i++)
    {
        MMI_ASSERT(attachment);
        mmi_ucs2cpy((S8*) subMenuDataPtrs[i], (S8*) attachment->object->file_name);
        attachment = attachment->next;
    }

    if (IsScreenPresent(SCR_ID_UC_OPT_REMOVE))
    {
        lsk_id = STR_UC_REMOVE_ID;
    }
    else if (IsScreenPresent(SCR_ID_UC_OPT_REPLACE))
    {
        lsk_id = STR_UC_REPLACE_ID;
    }
    else
    {
        MMI_ASSERT(0);
    }

    ShowCategory84Screen(
        STR_UC_ATTACHMENT_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_uc_p->msg.total_attachment_num,
        (U8 **) subMenuDataPtrs,
        (PU16) gIndexIconsImageList,
        0,
        0,
        guiBuffer);

    if (lsk_id == STR_UC_REMOVE_ID)
    {
        SetLeftSoftkeyFunction(mmi_uc_remove_object, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    }
    
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_replace
 * DESCRIPTION
 *  Entry function for replace type list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_replace(void)
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
    EntryNewScreen(SCR_ID_UC_OPT_REPLACE, mmi_uc_exit_generic, mmi_uc_entry_replace, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_replace *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_REMOVE);

    if (g_uc_p->msg.current_slide->image.object)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REPLACE_IMAGE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REPLACE_IMAGE);
    }
    
    if (g_uc_p->msg.current_slide->audio.object)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REPLACE_AUDIO);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REPLACE_AUDIO);
    }

    if (g_uc_p->msg.current_slide->video.object)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REPLACE_VIDEO);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REPLACE_VIDEO);
    }

    if (g_uc_p->msg.total_attachment_num)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_REPLACE_ATTACHMENT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_REPLACE_ATTACHMENT);
    }

    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT_REPLACE);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT_REPLACE, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT_REPLACE);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_UC_REPLACE_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_remove_image
 * DESCRIPTION
 *  Funtion is called when replace image menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_IMAGE;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_audio
 * DESCRIPTION
 *  Funtion is called when replace audio menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_AUDIO;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_video
 * DESCRIPTION
 *  Funtion is called when replace video menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_VIDEO;
    
    SetLeftSoftkeyFunction(mmi_uc_select_fmgr_object, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_select_fmgr_object, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_replace_attachment
 * DESCRIPTION
 *  Funtion is called when replace attachment menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_replace_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_ATTACHMENT;
    
    SetLeftSoftkeyFunction(mmi_uc_entry_attachment_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_attachment_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_select_object_from_fm_to_replace
 * DESCRIPTION
 *  Select object from file manager
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_select_object_from_fm_to_replace(PU16 filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_image_path[MMI_UC_MAX_TEMP_FILE_LEN];
    mmi_uc_result result;
    mma_insert_check_struct check_result;
    mmi_uc_slide_struct* slide = g_uc_p->msg.current_slide;
    mmi_uc_object_struct* new_object = NULL;
    mmi_uc_object_struct* duplicated_object = NULL;
    mmi_uc_object_struct* replaced_object = NULL;
    mmi_uc_attachment_info_struct* att = NULL;
    mma_insert_type_enum mms_type = mmi_uc_convert_to_mms_insert_type(g_uc_p->main.highlighted_object_type);
    U32 new_obj_smil_size = 0;
    U32 replaced_obj_smil_size = 0;
    U32 replaced_obj_body_size = 0;
    U32 new_msg_size = 0;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    memset(mmi_uc_image_path, 0, MMI_UC_MAX_TEMP_FILE_LEN);
    
    if (filePath == NULL)
    {
        if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
        {
            if (g_uc_p->msg.total_attachment_num > 0)
            {
                GoBackToHistory(SCR_ID_UC_OPT_ATTACHMENT_LIST);
            }
            else
            {
                GoBackToHistory(SCR_ID_UC_OPT_REPLACE);
            }
        }
        else
        {
            GoBackToHistory(SCR_ID_UC_OPT_REPLACE);
        }
        return;
    }

    if ( (handle = FS_GetAttributes((PU16) filePath)) < 0)
    {
        DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(handle)),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
        return;
    }

    mmi_uc_set_processing_screen(STR_UC_REPLACE_ID, STR_UC_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0);
    mmi_uc_entry_processing_generic();

    if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
    {
        if (g_uc_p->main.object_index != MMI_UC_INVALID_INDEX)
        {
            att = mmi_uc_get_attachment_by_index(g_uc_p->main.object_index);
            replaced_object = att->object;
        }
        else
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_CONTENT_ERROR_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
            DeleteUptoScrID(SCR_ID_UC_EDITOR);
            return;
        }
    }
    else
    {
        replaced_object = mmi_uc_get_object_in_slide(slide, g_uc_p->main.highlighted_object_type);

        if (replaced_object == NULL)        
        {
            DisplayPopup(
                    (PU8) GetString(STR_UC_CONTENT_ERROR_ID),
                    IMG_GLOBAL_UNFINISHED,
                    1,
                    MMI_UC_POPUP_TIME_OUT,
                    (U8) ERROR_TONE);
            DeleteUptoScrID(SCR_ID_UC_EDITOR);
            return;
        }
    }

    if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_IMAGE &&
        g_uc_p->mms_info.image_resize.enable)
    {        
        /* Check if it is DRM file */
        
        wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                       filePath, 
                                       mms_type, 
                                       g_uc_p->msg.msg_size, 
                                       g_uc_p->mms_info.max_mms_size,
                                       &check_result);

        /* SD and SD without right DRM files cannot be resized. */
        if (check_result.result == MMI_TRUE && 
            (check_result.drm_type == MMA_DRM_SD_NO_RIGHT || check_result.drm_type == MMA_DRM_SD))
        {
            /* allows inserted but display default image for thumbnail for MMA_DRM_SD_NO_RIGHT. */
        }
        else
        {
            S32 resize_result;

            if (!mmi_uc_is_valid_image(filePath))
            {
                mmi_uc_display_resize_result_popup((U16)MMI_UC_RESIZING_FAILED_IN_GDI_FAILED);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                return;
            }

            MMI_UC_MAKE_IMAGE_FILE_PATH(mmi_uc_image_path, ++g_uc_p->main.image_no);
            resize_result = mmi_uc_resize_image(
                                    (U8*) filePath, 
                                    mmi_uc_image_path, 
                                    g_uc_p->mms_info.image_resize.width,
                                    g_uc_p->mms_info.image_resize.height);

            /* Error ! */
            if (resize_result < 0)
            {

                mmi_uc_display_resize_result_popup((U16)resize_result);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                return;                
            }
            /* resized */
            else if (resize_result)
            {
                filePath = (PU16)mmi_uc_image_path;
            }
            /* resize_result == 0 means no need to resize */
        }
        memset(&check_result, 0, sizeof(mma_insert_check_struct));   
    }
    
    duplicated_object = mmi_uc_check_duplicate_object(filePath);
    
    new_obj_smil_size = wap_mma_uc_calc_object_smil_size(mms_type, filePath);
    replaced_obj_smil_size = wap_mma_uc_calc_object_smil_size(mmi_uc_convert_to_mms_insert_type(replaced_object->type),
                                                         (const kal_wchar*)replaced_object->file_path);

    if (g_uc_p->main.highlighted_object_type != MMI_UC_OBJECT_TYPE_ATTACHMENT &&
        duplicated_object &&
        duplicated_object->type != MMI_UC_OBJECT_TYPE_ATTACHMENT)
    {        
        /* if the original object and the new object are the same, no need to delete the original object. */
        if (replaced_object->reference_count == 1 &&
            replaced_object != duplicated_object)
        {
            if (replaced_object->is_virtual_file)
            {
                U8 virtual_file_name[(FS_GenVFN_SIZE + FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
                S32 result;
                S32 file_handle;
                U16 virtual_file_name_len = sizeof(virtual_file_name);

                memset(virtual_file_name, 0, virtual_file_name_len);
                            
                file_handle = FS_Open(replaced_object->file_path, FS_READ_ONLY | FS_OPEN_SHARED);
                
                if (file_handle <= 0)
                {
                    MMI_ASSERT(0);
                }

            	result = FS_GenVirtualFileName( 
                                file_handle, 
                                (U16*)virtual_file_name, 
                        		(unsigned int)FS_GenVFN_SIZE, 
                        		replaced_object->offset, 
                        		replaced_object->size);
                
                if (result < 0)
                {
                    MMI_ASSERT(0);
                }
                
                mmi_ucs2cat((PS8) virtual_file_name, (PS8) L".");
                if (mmi_uc_get_file_extension(replaced_object->file_name))
                {
                    mmi_ucs2ncat((PS8) virtual_file_name, (PS8) mmi_uc_get_file_extension(replaced_object->file_name), virtual_file_name_len / ENCODING_LENGTH);
                }
                
                replaced_obj_body_size = wap_mma_uc_calc_object_multipart_size((U16*)virtual_file_name);

                FS_Close(file_handle);
            }
            else
            {
                replaced_obj_body_size = wap_mma_uc_calc_object_multipart_size(replaced_object->file_path);
            }
        }
        else
        {
            replaced_obj_body_size = 0;
        }

        new_msg_size = g_uc_p->msg.msg_size + new_obj_smil_size - replaced_obj_smil_size - replaced_obj_body_size;
        
        if (!mmi_uc_check_if_exceed_MMS_size_limitation(new_msg_size))
        {           
            replaced_object->reference_count--;        
            mmi_uc_insert_object_to_slide(duplicated_object, slide, g_uc_p->main.highlighted_object_type);

            if (replaced_object->reference_count == 0)
            {
                mmi_uc_delete_object_from_list(replaced_object);
            }
            
        }
        else
        {
            mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            if (mmi_ucs2strlen((S8*)mmi_uc_image_path))
            {
                FS_Delete((WCHAR*)mmi_uc_image_path);
            }
            return;
        }
    }
    else
    {
        if (replaced_object->reference_count == 1)
        {
            if (replaced_object->is_virtual_file)
            {
                U8 virtual_file_name[(FS_GenVFN_SIZE + FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
                S32 result;
                S32 file_handle;
                U16 virtual_file_name_len = sizeof(virtual_file_name);

                memset(virtual_file_name, 0, virtual_file_name_len);
                            
                file_handle = FS_Open(replaced_object->file_path, FS_READ_ONLY | FS_OPEN_SHARED);
                
                if (file_handle <= 0)
                {
                    MMI_ASSERT(0);
                }

            	result = FS_GenVirtualFileName( 
                                file_handle, 
                                (U16*)virtual_file_name, 
                        		(unsigned int)FS_GenVFN_SIZE, 
                        		replaced_object->offset, 
                        		replaced_object->size);
                
                if (result < 0)
                {
                    MMI_ASSERT(0);
                }
                
                mmi_ucs2cat((PS8) virtual_file_name, (PS8) L".");
                if (mmi_uc_get_file_extension(replaced_object->file_name))
                {
                    mmi_ucs2ncat((PS8) virtual_file_name, (PS8) mmi_uc_get_file_extension(replaced_object->file_name), virtual_file_name_len / ENCODING_LENGTH);
                }
                
                replaced_obj_body_size = wap_mma_uc_calc_object_multipart_size((U16*)virtual_file_name);

                FS_Close(file_handle);
            }
            else
            {
                replaced_obj_body_size = wap_mma_uc_calc_object_multipart_size(replaced_object->file_path);
            }
        }
        else
        {
            replaced_obj_body_size = 0;
        }

        new_msg_size = g_uc_p->msg.msg_size - replaced_obj_smil_size - replaced_obj_body_size;
    
        wap_mma_uc_insert_object_check(g_uc_p->mms_info.creation_mode,
                                       filePath, 
                                       mms_type, 
                                       new_msg_size, 
                                       g_uc_p->mms_info.max_mms_size,
                                       &check_result);
        
        if (!(check_result.result))
        {
            result = mmi_uc_convert_mms_check_result(&check_result);
            mmi_uc_display_popup(result);
            DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            if (mmi_ucs2strlen((S8*)mmi_uc_image_path))
            {
                FS_Delete((WCHAR*)mmi_uc_image_path);
            }
            return;
        }

        replaced_object->reference_count--;        
        
        if (replaced_object->reference_count == 0)
        {
            mmi_uc_delete_object_from_list(replaced_object);
        }
        
        new_object = mmi_uc_insert_object((S8*) filePath, g_uc_p->main.highlighted_object_type);
        new_object->drm_type = check_result.drm_type;

        if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
        {            
            mmi_uc_insert_object_to_attachment(new_object, att);
        }
        else
        {
            mmi_uc_insert_object_to_slide(new_object, slide, g_uc_p->main.highlighted_object_type);            
            
        }       
    }

    fmgr_reset_app_select();    
            
    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }

    mmi_uc_update_msg_size();
    mmi_uc_editor_initialize();
    mmi_uc_set_editor_info(g_uc_p->msg.current_slide);
    
    if (g_uc_p->main.highlighted_object_type == MMI_UC_OBJECT_TYPE_ATTACHMENT)
    {
        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
        {
            GoBackToHistory(SCR_ID_UC_OPT_ATTACHMENT_LIST);
        }
        else
        {
            U16 screen_id = 0;
            if (GetNextScrnIdOf(SCR_ID_UC_OPT_ATTACHMENT_LIST,&screen_id))
            {
                DeleteBetweenScreen(screen_id,  SCR_ID_UC_PROCESSING);
            }
            else
            {
                MMI_ASSERT(0);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            }            
        }        
    }
    else
    {        
        if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
        {
            GoBackToHistory(SCR_ID_UC_EDITOR);
        }
        else
        {
            U16 screen_id = 0;
            if (GetNextScrnIdOf(SCR_ID_UC_EDITOR,&screen_id))
            {
                DeleteBetweenScreen(screen_id,  SCR_ID_UC_PROCESSING);
            }
            else
            {
                MMI_ASSERT(0);
                DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
            }            
            
        }        
    }        
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_slide_opt
 * DESCRIPTION
 *  Entry function for slide option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_slide_opt(void)
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
    EntryNewScreen(SCR_ID_UC_OPT_SLIDE_OPT, mmi_uc_exit_generic, mmi_uc_entry_slide_opt, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_slide_opt *\n");
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_SLIDE_OPT);

    if (g_uc_p->msg.total_slide_num < MMI_UC_MAX_MMS_SLIDE_NUM)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_INSERT);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_INSERT);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE);
    }

    if (g_uc_p->msg.total_slide_num > 1)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_DELETE);
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_GO_TO);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_DELETE);
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_GO_TO);
    }

    if (g_uc_p->msg.current_slide->previous)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS);
    }

    if (g_uc_p->msg.current_slide->next)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_NEXT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_NEXT);
    }    

    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_TIMING);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_TIMING);
    }

#ifdef __MMI_MMS_2__

    mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING);
    mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING);
    mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING);
    mmi_frm_hide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING);

    if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
    {
        if (g_uc_p->msg.current_slide->text.object != NULL)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING);
        }

        if (g_uc_p->msg.current_slide->image.object)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING);
        }

        if (g_uc_p->msg.current_slide->audio.object)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING);
        }

        if (g_uc_p->msg.current_slide->video.object)
        {
            mmi_frm_unhide_menu_item(MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING);
        }
    }

#endif /* __MMI_MMS_2__ */

    numItems = GetNumOfChild_Ext(MENU_ID_UC_OPT_SLIDE_OPT);
    GetSequenceStringIds_Ext(MENU_ID_UC_OPT_SLIDE_OPT, nStrItemList);

    SetParentHandler(MENU_ID_UC_OPT_SLIDE_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_UC_SLIDE_OPTION_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
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
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_insert_slide
 * DESCRIPTION
 *  insert new slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_insert_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    mmi_uc_slide_struct* slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);

    if (!mmi_uc_check_if_exceed_MMS_size_limitation(new_slide_size + g_uc_p->msg.msg_size))
    {
        slide = mmi_uc_insert_slide(g_uc_p->msg.current_slide);
        g_uc_p->msg.current_slide = slide;
        g_uc_p->msg.current_slide_num = slide->slide_num;
        
        if (mmi_uc_change_msg_type_if_needed())
        {
            mmi_uc_insert_signature_check();
        }
        
        mmi_uc_update_msg_size();
        mmi_uc_switch_slide(g_uc_p->msg.current_slide);

        //mmi_uc_reset_text_buffer();
        //mmi_uc_editor_initialize();

        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
    else
    {
        mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
        return;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_insert_slide_before
 * DESCRIPTION
 *  insert new slide before current slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_insert_slide_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    mmi_uc_slide_struct* slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    new_slide_size = wap_mma_uc_calc_slide_smil_size(g_uc_p->msg.slide_timing);

    if (!mmi_uc_check_if_exceed_MMS_size_limitation(new_slide_size + g_uc_p->msg.msg_size))
    {
        slide = mmi_uc_insert_slide(g_uc_p->msg.current_slide->previous);
        g_uc_p->msg.current_slide = slide;
        g_uc_p->msg.current_slide_num = slide->slide_num;
        
        if (mmi_uc_change_msg_type_if_needed())
        {
            mmi_uc_insert_signature_check();
        }
        
        mmi_uc_update_msg_size();
        mmi_uc_switch_slide(g_uc_p->msg.current_slide);

        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
    else
    {
        mmi_uc_display_popup(MMI_UC_SIZE_EXCEEDS);
        return;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_delete_slide
 * DESCRIPTION
 *  insert new slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_delete_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_slide_struct* slide = g_uc_p->msg.current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide->next)
    {
        g_uc_p->msg.current_slide = slide->next;
    }
    else if (slide->previous)
    {
        g_uc_p->msg.current_slide = slide->previous;
    }
    else
    {
       g_uc_p->msg.current_slide = NULL;
    }     

    mmi_uc_delete_slide_with_object(slide);
    g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;

    mmi_uc_switch_slide(g_uc_p->msg.current_slide);

    if (mmi_uc_change_msg_type_if_needed())
    {
        mmi_uc_insert_signature_check();
    }
    mmi_uc_update_msg_size();

    GoBackToHistory(SCR_ID_UC_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_previous_slide
 * DESCRIPTION
 *  Go to previous slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_previous_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_slide_struct* slide = g_uc_p->msg.current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(slide->previous);
    
    g_uc_p->msg.current_slide = slide->previous;
    g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;

    mmi_uc_switch_slide(g_uc_p->msg.current_slide);
    mmi_uc_update_msg_size();

    GoBackToHistory(SCR_ID_UC_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_next_slide
 * DESCRIPTION
 *  Go to next slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_next_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_slide_struct* slide = g_uc_p->msg.current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(slide->next);
    
    g_uc_p->msg.current_slide = slide->next;
    g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;

    mmi_uc_switch_slide(g_uc_p->msg.current_slide);
    mmi_uc_update_msg_size();

    GoBackToHistory(SCR_ID_UC_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_goto_slide
 * DESCRIPTION
 *  Entry screen to edit slide number to enter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_goto_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 slide_number_digit = 0;
    U32 max_slide_number = MMI_UC_MAX_MMS_SLIDE_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_SLIDE_OPT_GOTO, NULL, mmi_uc_entry_goto_slide, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_SLIDE_OPT_GOTO);

    if (max_slide_number < 10)
    {
        slide_number_digit = 2;
    }
    else if (max_slide_number < 100)
    {
        slide_number_digit = 3;
    }
    else if (max_slide_number < 1000)
    {
        slide_number_digit = 4;
    }
    else if (max_slide_number < 10000)
    {
        slide_number_digit = 5;
    }
    else if (max_slide_number < 100000)
    {
        slide_number_digit = 6;
    }
    else
    {
        MMI_ASSERT(0);
    }

    ShowCategory5Screen(
        STR_UC_GO_TO_SOME_SLIDE_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_NUMERIC,
        (U8*) g_uc_p->main.slide_number,
        slide_number_digit,
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_uc_entry_goto_slide_done, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);   
}
      
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_goto_slide_done
 * DESCRIPTION
 *  Goto slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_goto_slide_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_buff[10];
    U16 slide_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*)ascii_buff, (S8*)g_uc_p->main.slide_number);
    slide_number = (U16) atoi(ascii_buff);

    if (slide_number == 0 || 
        slide_number > g_uc_p->msg.total_slide_num)
    {        
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
    }
    else
    {
        mmi_uc_slide_struct* slide = g_uc_p->msg.slide_head;
        U32 i = 1;

        MMI_ASSERT(slide);

        for (; i < slide_number; i++)
        {            
            slide = slide->next;
            MMI_ASSERT(slide);
        }
        
        g_uc_p->msg.current_slide = slide;
        g_uc_p->msg.current_slide_num = g_uc_p->msg.current_slide->slide_num;

        mmi_uc_switch_slide(g_uc_p->msg.current_slide);
        mmi_uc_update_msg_size();

        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_slide_timing
 * DESCRIPTION
 *  Entry screen to edit slide timing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_slide_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 timing_digit_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING, NULL, mmi_uc_entry_slide_timing, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING);
    
    if (g_uc_p->mms_info.sliding_time.max < 100)
    {
        timing_digit_len = 2;
    }
    else if (g_uc_p->mms_info.sliding_time.max < 1000)
    {
        timing_digit_len = 3;
    }
    else
    {
        timing_digit_len = 3;
    }
#ifdef __MMI_MMS_2__
    if (g_uc_p->msg.best_page_duration)
    {
        S32 obj_duration_digit = mmi_ucs2strlen((S8*)g_uc_p->main.slide_timing);
        if (timing_digit_len < obj_duration_digit)
        {
            timing_digit_len = obj_duration_digit;
        }
    }
#endif    
    ShowCategory5Screen(
        STR_UC_SLIDE_TIMING_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        INPUT_TYPE_NUMERIC,
        (U8*) g_uc_p->main.slide_timing,
        (timing_digit_len + 1),
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_uc_entry_slide_timing_done, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);   
}
      
/*****************************************************************************
 * FUNCTION
 *  mmi_uc_goback_to_editor
 * DESCRIPTION
 *  Go back to editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_goback_to_editor(void)
{
    GoBackToHistory(SCR_ID_UC_EDITOR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_slide_timing_done
 * DESCRIPTION
 *  Set slide timing and go back to editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_slide_timing_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_buff[6];
    U32 slide_timing = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)g_uc_p->main.slide_timing) != 0)
    {        
        mmi_ucs2_to_asc((S8*)ascii_buff, (S8*)g_uc_p->main.slide_timing);
        slide_timing = (U32) atoi(ascii_buff);
    }
#ifdef __MMI_MMS_2__
    if (g_uc_p->msg.best_page_duration &&
        mmi_ucs2strlen((S8*)g_uc_p->main.slide_timing) == 0)
    {        
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
    }        
    else
#endif
    if (mmi_ucs2strlen((S8*)g_uc_p->main.slide_timing) == 0 || 
        slide_timing < g_uc_p->mms_info.sliding_time.min ||     
        (slide_timing > g_uc_p->mms_info.sliding_time.max 
#ifdef __MMI_MMS_2__
        && (!g_uc_p->msg.best_page_duration)
#endif        
       ))
    {   
        U16 number_len = 10;
        U16 ucs2_number[10];
        U8 ascii_number[10];
        U16 temp_str_size = 200;
        U16* temp_str = OslMalloc(temp_str_size);

        memset(temp_str, 0, temp_str_size);

        mmi_ucs2cpy((S8*) temp_str, (S8*)GetString(STR_UC_INTERVAL_PREFIX_ID));
        mmi_ucs2cat((S8*) temp_str, (S8*)L" ");

        memset(ascii_number, 0, number_len);
        memset(ucs2_number, 0, number_len * ENCODING_LENGTH);        
        sprintf((char*)ascii_number, "%d", g_uc_p->mms_info.sliding_time.min);
        mmi_asc_n_to_ucs2((S8*)ucs2_number, (S8*)ascii_number, number_len);
        mmi_ucs2cat((PS8) temp_str, (PS8) ucs2_number);
        mmi_ucs2cat((S8*) temp_str, (S8*)L" ");

        mmi_ucs2cat((S8*) temp_str, (S8*)GetString(STR_UC_INTERVAL_INFIX_ID));
        mmi_ucs2cat((S8*) temp_str, (S8*)L" ");

        memset(ascii_number, 0, number_len);
        memset(ucs2_number, 0, number_len * ENCODING_LENGTH);        
        sprintf((char*)ascii_number, "%d", g_uc_p->mms_info.sliding_time.max);
        mmi_asc_n_to_ucs2((S8*)ucs2_number, (S8*)ascii_number, number_len);
        mmi_ucs2cat((PS8) temp_str, (PS8) ucs2_number);
        
        DisplayPopup((PU8) temp_str,
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);

        OslMfree(temp_str);
    }
    
#ifdef __MMI_MMS_2__
    else if ((g_uc_p->msg.current_slide->text.object && 
              g_uc_p->msg.current_slide->text.begin != MMI_UC_INVALID_VALUE && 
              slide_timing <= g_uc_p->msg.current_slide->text.begin) ||
             (g_uc_p->msg.current_slide->image.object && 
              g_uc_p->msg.current_slide->image.begin != MMI_UC_INVALID_VALUE && 
              slide_timing <= g_uc_p->msg.current_slide->image.begin) ||
             (g_uc_p->msg.current_slide->audio.object && 
              g_uc_p->msg.current_slide->audio.begin != MMI_UC_INVALID_VALUE && 
              slide_timing <= g_uc_p->msg.current_slide->audio.begin) ||
             (g_uc_p->msg.current_slide->video.object && 
              g_uc_p->msg.current_slide->video.begin != MMI_UC_INVALID_VALUE && 
              slide_timing <= g_uc_p->msg.current_slide->video.begin))
    {
        DisplayPopup((PU8) GetString(STR_UC_LESS_THAN_MEDIA_TIME_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
    }
    else if ( (g_uc_p->msg.best_page_duration) &&
        
              ((g_uc_p->msg.current_slide->audio.object && 
                g_uc_p->msg.current_slide->audio.end != MMI_UC_INVALID_VALUE && 
                slide_timing < g_uc_p->msg.current_slide->audio.end) ||
                (g_uc_p->msg.current_slide->video.object && 
                g_uc_p->msg.current_slide->video.end != MMI_UC_INVALID_VALUE && 
                slide_timing < g_uc_p->msg.current_slide->video.end))  )
    {
        DisplayPopup((PU8) GetString(STR_UC_LESS_THAN_MEDIA_TIME_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
    }  
#endif /* __MMI_MMS_2__ */

    else
    {

    #ifdef __MMI_MMS_2__
        if (g_uc_p->msg.current_slide->text.object && 
            g_uc_p->msg.current_slide->text.end != MMI_UC_INVALID_VALUE && 
            slide_timing < g_uc_p->msg.current_slide->text.end)
        {
            g_uc_p->msg.current_slide->text.end = slide_timing;
        }

        if (g_uc_p->msg.current_slide->image.object && 
            g_uc_p->msg.current_slide->image.end != MMI_UC_INVALID_VALUE && 
            slide_timing < g_uc_p->msg.current_slide->image.end)
        {
            g_uc_p->msg.current_slide->image.end = slide_timing;
        }
        
        if (g_uc_p->msg.current_slide->audio.object && 
            g_uc_p->msg.current_slide->audio.end != MMI_UC_INVALID_VALUE && 
            slide_timing < g_uc_p->msg.current_slide->audio.end)
        {
            g_uc_p->msg.current_slide->audio.end = slide_timing;
        }

        if (g_uc_p->msg.current_slide->video.object && 
            g_uc_p->msg.current_slide->video.end != MMI_UC_INVALID_VALUE && 
            slide_timing < g_uc_p->msg.current_slide->video.end)
        {
            g_uc_p->msg.current_slide->video.end = slide_timing;
        }
    #endif /* __MMI_MMS_2__ */
    
        g_uc_p->msg.current_slide->duration = slide_timing;
        DisplayPopupCallBack(
        (PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        MMI_UC_POPUP_TIME_OUT,
        (U8) SUCCESS_TONE,
        mmi_uc_goback_to_editor);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_insert
 * DESCRIPTION
 *  Funtion is called when insert slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_insert_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_insert_before
 * DESCRIPTION
 *  Funtion is called when insert slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_insert_before(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_insert_slide_before, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_insert_slide_before, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_delete
 * DESCRIPTION
 *  Funtion is called when delete slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_delete_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_delete_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_previous
 * DESCRIPTION
 *  Funtion is called when previous slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_previous_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_previous_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_next
 * DESCRIPTION
 *  Funtion is called when next slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_next_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_next_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_goto
 * DESCRIPTION
 *  Funtion is called when goto slide menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_goto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_uc_p->main.slide_number, 0, sizeof(g_uc_p->main.slide_number));
    SetLeftSoftkeyFunction(mmi_uc_entry_goto_slide, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_goto_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_timing
 * DESCRIPTION
 *  Funtion is called when slide timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_MMS_2__
    if ((!g_uc_p->msg.best_page_duration) && (g_uc_p->msg.current_slide->duration > g_uc_p->mms_info.sliding_time.max))
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", g_uc_p->mms_info.sliding_time.max); 
    }
    else
    {
#endif /*__MMI_MMS_2__*/     
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", g_uc_p->msg.current_slide->duration); 
#ifdef __MMI_MMS_2__
    }
#endif    
    SetLeftSoftkeyFunction(mmi_uc_entry_slide_timing, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_slide_timing, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#ifdef __MMI_MMS_2__

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_timing_inline_item
 * DESCRIPTION
 *  Set timing inline item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_set_timing_inline_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 timing_digit_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->mms_info.sliding_time.max < 100)
    {
        timing_digit_len = 2;
    }
    else if (g_uc_p->mms_info.sliding_time.max < 1000)
    {
        timing_digit_len = 3;
    }
    else
    {
        timing_digit_len = 3;
    }
    if (g_uc_p->msg.best_page_duration)
    {
        S32 obj_duration_digit = mmi_ucs2strlen((S8*)g_uc_p->main.slide_number);  /*END TIME*/
        if (timing_digit_len < obj_duration_digit)
        {
            timing_digit_len = obj_duration_digit;
        }
    }

    
    /* Start time caption*/
    SetInlineItemCaption(&(wgui_inline_items[0]), (U8*) GetString(STR_UC_START_TIME_ID));

    /* Start time */
    SetInlineItemActivation(&(wgui_inline_items[1]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &(wgui_inline_items[1]),
        g_uc_p->main.slide_timing,
        timing_digit_len + 1,
        INPUT_TYPE_NUMERIC);

    /* End time caption*/
    SetInlineItemCaption(&(wgui_inline_items[2]), (U8*) GetString(STR_UC_END_TIME_ID));

    /* End time */
    SetInlineItemActivation(&(wgui_inline_items[3]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &(wgui_inline_items[3]),
        g_uc_p->main.slide_number,  /* reuse slide_number buffer! */
        timing_digit_len + 1,
        INPUT_TYPE_NUMERIC);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_timing_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_timing_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->msg.best_page_duration)
    {
        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_timing_check_before_done);
    }
    else
    {
        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_timing_done);
    }
    
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory,GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_timing
 * DESCRIPTION
 *  Exit function of done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING;
    currHistory.entryFuncPtr = mmi_uc_entry_timing;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_timing
 * DESCRIPTION
 *  Entry screen to edit object timing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputBuffer = NULL;
    U16 inputBufferSize = 0;
    U16 image_list[4] = {0};
    U16 title_str = STR_UC_SLIDE_TEXT_TIMING_ID;

    U8 numOfItems = 4; /* start time and end time */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING, mmi_uc_exit_timing, NULL, NULL);

    InitializeCategory57Screen();
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING, &inputBufferSize);

    RegisterHighlightHandler(mmi_uc_entry_timing_highlight_hdlr);    
    mmi_uc_set_timing_inline_item();

    image_list[0] = IMG_GLOBAL_L1;
    image_list[1] = 0;
    image_list[2] = IMG_GLOBAL_L2;
    image_list[3] = 0;

    switch (g_uc_p->main.highlighted_object_type)
    {
        case MMI_UC_OBJECT_TYPE_TEXT:
        {
            title_str = STR_UC_SLIDE_TEXT_TIMING_ID;
            break;
        }

        case MMI_UC_OBJECT_TYPE_IMAGE:
        {
            title_str = STR_UC_SLIDE_IMAGE_TIMING_ID;
            break;
        }

        case MMI_UC_OBJECT_TYPE_AUDIO:
        {
            title_str = STR_UC_SLIDE_AUDIO_TIMING_ID;
            break;
        }

        case MMI_UC_OBJECT_TYPE_VIDEO:
        {
            title_str = STR_UC_SLIDE_VIDEO_TIMING_ID;
            break;
        }

        default:
        {
            MMI_ASSERT(0);
        }
    }

    ShowCategory57Screen(
        title_str,
        IMG_SMS_ENTRY_SCRN_CAPTION,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numOfItems,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);
    if (g_uc_p->msg.best_page_duration)
    {
        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_timing_check_before_done);
    }
    else
    {
        SetCategory57LeftSoftkeyFunction(mmi_uc_entry_timing_done);
    }
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory,GoBackHistory);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_timing_done
 * DESCRIPTION
 *  Set object timing and go back to editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_timing_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_buff_start_time[6];
    S8 ascii_buff_end_time[6];
    U32 start_time;
    U32 end_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*)g_uc_p->main.slide_timing) == 0 || 
        mmi_ucs2strlen((S8*)g_uc_p->main.slide_number) == 0)
    {        
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
        return;
    }        

    mmi_ucs2_to_asc((S8*)ascii_buff_start_time, (S8*)g_uc_p->main.slide_timing);
    start_time = (U32) atoi(ascii_buff_start_time);

    mmi_ucs2_to_asc((S8*)ascii_buff_end_time, (S8*)g_uc_p->main.slide_number);
    end_time = (U32) atoi(ascii_buff_end_time);

    if (start_time >= g_uc_p->msg.current_slide->duration ||
        end_time > g_uc_p->msg.current_slide->duration )
    {        
        DisplayPopup((PU8) GetString(STR_UC_EXCEED_SLIDE_TIME_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
    }    
    else if (start_time >= end_time)
    {        
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
    }
    else
    {
        switch (g_uc_p->main.highlighted_object_type)
        {
            case MMI_UC_OBJECT_TYPE_TEXT:
            {
                g_uc_p->msg.current_slide->text.begin = start_time;
                g_uc_p->msg.current_slide->text.end = end_time;
                break;
            }

            case MMI_UC_OBJECT_TYPE_IMAGE:
            {
                g_uc_p->msg.current_slide->image.begin = start_time;
                g_uc_p->msg.current_slide->image.end = end_time;
                break;
            }

            case MMI_UC_OBJECT_TYPE_AUDIO:
            {                
                g_uc_p->msg.current_slide->audio.begin = start_time;
                g_uc_p->msg.current_slide->audio.end = end_time;                
                break;
            }

            case MMI_UC_OBJECT_TYPE_VIDEO:
            {                
                g_uc_p->msg.current_slide->video.begin = start_time;
                g_uc_p->msg.current_slide->video.end = end_time;                
                break;
            }

            default:
            {
                MMI_ASSERT(0);
            }
        }
        
        GoBackToHistory(SCR_ID_UC_EDITOR);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_timing_check_before_done
 * DESCRIPTION
 *  check values and then set object timing and go back to editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_timing_check_before_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ascii_buff_start_time[10];
    S8 ascii_buff_end_time[10];
    U32 start_time;
    U32 end_time;
    U32 file_duration = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8*)ascii_buff_start_time, (S8*)g_uc_p->main.slide_timing);
    start_time = (U32) atoi(ascii_buff_start_time);
    /*use slide_number for temp*/
    mmi_ucs2_to_asc((S8*)ascii_buff_end_time, (S8*)g_uc_p->main.slide_number);  
    end_time = (U32) atoi(ascii_buff_end_time);

    if (start_time >= g_uc_p->msg.current_slide->duration ||
        end_time > g_uc_p->msg.current_slide->duration )
    {        
        DisplayPopup((PU8) GetString(STR_UC_EXCEED_SLIDE_TIME_ID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);
        return;
    }    
    else if (start_time >= end_time)
    {        
        DisplayPopup((PU8) GetString(STR_GLOBAL_INVALID),
                     IMG_GLOBAL_UNFINISHED,
                     1,
                     MMI_UC_POPUP_TIME_OUT,
                     (U8) ERROR_TONE);

        return;
    }
    /*get media duration, just for best page duration case*/

    switch (g_uc_p->main.highlighted_object_type)
    {
        case MMI_UC_OBJECT_TYPE_AUDIO:
        {
            
            if(mdi_audio_get_duration(g_uc_p->msg.current_slide->audio.object->file_path, &(file_duration)) != MDI_AUDIO_SUCCESS)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UC]#2, mdi_audio_get_duration fail");
                file_duration = 0;
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UC]#2, mdi_audio_get_duration (%d)",file_duration);
                file_duration = (file_duration / 1000);
            }
            
            break;
        }
        
#ifdef __MMI_VIDEO_PLAYER__           
        case MMI_UC_OBJECT_TYPE_VIDEO:
        {

        /*1. check media file duration*/  
            mdi_video_info_struct vdo_info;
            MDI_RESULT result;

            result = mdi_video_ply_open_clip_file((PS8)g_uc_p->msg.current_slide->video.object->file_path, &vdo_info);
            if (result < 0)
            {
                file_duration = 0;
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UC]#2 mdi_audio_get_duration fail");
            }
            else
            {
                mdi_video_ply_close_clip_file();
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UC]#2 mdi_audio_get_duration =%d",vdo_info.total_time_duration);
                file_duration = (vdo_info.total_time_duration / 1000);
            }
            break;               
        }
#endif /*__MMI_VIDEO_PLAYER__*/  
            
    }/*switch*/
    if (end_time < start_time + file_duration) /*confirm popup to ask user*/
    {
        DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_UC_CAN_NOT_PLAY_COMPLETE), /*to do, need new string*/
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_uc_entry_timing_done, KEY_EVENT_UP);
    }
    else
    {
        mmi_uc_entry_timing_done();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_text_timing
 * DESCRIPTION
 *  Funtion is called when text timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_text_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_TEXT;

    if (g_uc_p->msg.current_slide->text.begin != MMI_UC_INVALID_VALUE && 
        g_uc_p->msg.current_slide->text.end != MMI_UC_INVALID_VALUE)
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", g_uc_p->msg.current_slide->text.begin);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->text.end);/* reuse slide_number buffer! */
    }
    else
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", 0);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->duration);/* reuse slide_number buffer! */
    }
    
    SetLeftSoftkeyFunction(mmi_uc_entry_timing, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_timing, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_image_timing
 * DESCRIPTION
 *  Funtion is called when image timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_image_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_IMAGE;

    if (g_uc_p->msg.current_slide->image.begin != MMI_UC_INVALID_VALUE && 
        g_uc_p->msg.current_slide->image.end != MMI_UC_INVALID_VALUE)
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", g_uc_p->msg.current_slide->image.begin);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->image.end);  /* reuse slide_number buffer! */  
    }
    else
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", 0);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->duration);/* reuse slide_number buffer! */
    }
    
    SetLeftSoftkeyFunction(mmi_uc_entry_timing, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_timing, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_video_timing
 * DESCRIPTION
 *  Funtion is called when video timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_video_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_VIDEO;

    if (g_uc_p->msg.current_slide->video.begin != MMI_UC_INVALID_VALUE && 
        g_uc_p->msg.current_slide->video.end != MMI_UC_INVALID_VALUE)
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", g_uc_p->msg.current_slide->video.begin);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->video.end);/* reuse slide_number buffer! */        
    }
    else
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", 0);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->duration);/* reuse slide_number buffer! */
    }
    
    SetLeftSoftkeyFunction(mmi_uc_entry_timing, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_timing, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_slide_opt_audio_timing
 * DESCRIPTION
 *  Funtion is called when audio timing menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_slide_opt_audio_timing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_uc_p->main.highlighted_object_type = MMI_UC_OBJECT_TYPE_AUDIO;

    if (g_uc_p->msg.current_slide->audio.begin != MMI_UC_INVALID_VALUE && 
        g_uc_p->msg.current_slide->audio.end != MMI_UC_INVALID_VALUE)
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", g_uc_p->msg.current_slide->audio.begin);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->audio.end); /* reuse slide_number buffer! */       
    }
    else
    {
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_timing, "%d", 0);
        kal_wsprintf( (kal_uint16 *)g_uc_p->main.slide_number, "%d", g_uc_p->msg.current_slide->duration);/* reuse slide_number buffer! */
    }
    
    SetLeftSoftkeyFunction(mmi_uc_entry_timing, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_timing, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

#endif /* __MMI_MMS_2__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_uc_save_msg_type
 * DESCRIPTION
 *  Save msg type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_uc_p->main.object_index == 0)
    {
        g_uc_p->msg_type.curr_msg_type = MMI_UC_MSG_TYPE_SMS_PREFER;
        g_uc_p->msg_type.caller_specific_msg_type = MMI_UC_MSG_TYPE_SMS_PREFER;
    }
    else if (g_uc_p->main.object_index == 1)
    {
        g_uc_p->msg_type.curr_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
        g_uc_p->msg_type.caller_specific_msg_type = MMI_UC_MSG_TYPE_MMS_PREFER;
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_uc_insert_signature_check();
    
    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    
    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
        g_uc_p->main.state == MMI_UC_STATE_SEND)
    {
        /* Prevent the msg change ind popup display */
        g_uc_p->done.pre_msg_type = g_uc_p->msg_type.curr_msg_type;
        
        if (IsScreenPresent(SCR_ID_UC_OPT_DONE_OPT))
        {
            DeleteUptoScrID(SCR_ID_UC_OPT_DONE_OPT);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (IsScreenPresent(SCR_ID_UC_EDITOR))
        {
            DeleteUptoScrID(SCR_ID_UC_EDITOR);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}

          
/*****************************************************************************
* FUNCTION
*  mmi_uc_entry_msg_type
* DESCRIPTION
*  Entry msg type screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_uc_entry_msg_type(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   U8 *guiBuffer;
   U16 nNumofItem = 2;
   S32 hiliteitem = 0;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   EntryNewScreen(SCR_ID_UC_OPT_MSG_TYPE_OPT, mmi_uc_exit_generic, mmi_uc_entry_msg_type, NULL);

   subMenuDataPtrs[0] = (PU8) GetString(STR_UC_TEXT_MESSAGE_ID);
   subMenuDataPtrs[1] = (PU8) GetString(STR_UC_MULTIMEDIA_MESSAGE_ID);
   
   guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_MSG_TYPE_OPT);
   
   if ((guiBuffer != NULL))
   {
       hiliteitem = g_uc_p->main.object_index;
       MMI_ASSERT(hiliteitem < nNumofItem);
   }
   else
   {
        if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_SMS_PREFER)
        {
            hiliteitem = 0;     
        }
        else if (g_uc_p->msg_type.curr_msg_type == MMI_UC_MSG_TYPE_MMS_PREFER)
        {
            hiliteitem = 1;
        }
        else
        {
            MMI_ASSERT(0);
        }
   }
   
   RegisterHighlightHandler(mmi_uc_set_index);

   ShowCategory109Screen(
       STR_UC_MESSAGE_TYPE_ID,
       IMG_UC_ENTRY_SCRN_CAPTION_ID,
       STR_GLOBAL_OK,
       IMG_GLOBAL_OK,
       STR_GLOBAL_BACK,
       IMG_GLOBAL_BACK,
       nNumofItem,
       subMenuDataPtrs,
       NULL,
       hiliteitem,
       guiBuffer);
   
   SetLeftSoftkeyFunction(mmi_uc_save_msg_type, KEY_EVENT_UP);
   SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
   SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_send_opt
 * DESCRIPTION
 *  Entry function of send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer = NULL;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */
    U16 image_list[MMI_UC_SEND_OPT_TOTAL_NUM] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(g_uc_p->msg_type.caller_specific_msg_type != MMI_UC_MSG_TYPE_SMS_ONLY);
    
    EntryNewScreen(SCR_ID_UC_OPT_SEND_OPT, mmi_uc_exit_send_opt, NULL, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_send_opt *\n");

    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_OPT_SEND_OPT);

    InitializeCategory57Screen();

    mmi_uc_send_opt_fill_inline_struct(image_list);

    if (guiBuffer)
    {
        inputBuffer = GetCurrNInputBuffer(SCR_ID_UC_OPT_SEND_OPT, &inputBufferSize); /* added for inline edit history */
    }

    if (inputBuffer)    /* added for inline edit history */
    {
        SetCategory57Data(wgui_inline_items, MMI_UC_SEND_OPT_TOTAL_NUM, inputBuffer);      /* sets the data */
    }
        
    ShowCategory57Screen(
        STR_UC_SEND_OPTION_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_UC_SEND_OPT_TOTAL_NUM,
        image_list,
        wgui_inline_items,
        0,
        guiBuffer);
    
    /* set key hdlr */
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    SetCategory57RightSoftkeyFunctions(mmi_uc_send_opt_done_hdlr, GoBackHistory);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_send_opt
 * DESCRIPTION
 *  Exit function of send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 inputBufferSize = 0;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_UC_OPT_SEND_OPT;
    currHistory.entryFuncPtr = mmi_uc_entry_send_opt;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
    GetCategory57History(currHistory.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);
    AddNHistory(currHistory, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_opt_fill_inline_struct
 * DESCRIPTION
 *  Fill inline item of send option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_opt_fill_inline_struct(U16* image_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    image_list[MMI_UC_SEND_OPT_VALIDITY_PERIOD_CAPTION] = IMG_UC_VALIDITY_PERIOD_ID;
    image_list[MMI_UC_SEND_OPT_VALIDITY_PERIOD] = 0;
    image_list[MMI_UC_SEND_OPT_DELIVERY_REPORT_CAPTION] = IMG_UC_DELIVERY_REPORT_ID;
    image_list[MMI_UC_SEND_OPT_DELIVERY_REPORT] = 0;
    image_list[MMI_UC_SEND_OPT_READ_REPORT_CAPTION] = IMG_UC_READ_REPORT_ID;
    image_list[MMI_UC_SEND_OPT_READ_REPORT] = 0;
    image_list[MMI_UC_SEND_OPT_PRIORITY_CAPTION] = IMG_UC_PRIORITY_ID;
    image_list[MMI_UC_SEND_OPT_PRIORITY] = 0;
    image_list[MMI_UC_SEND_OPT_DELIVERY_TIME_CAPTION] = IMG_UC_DELIVERY_TIME_ID;
    image_list[MMI_UC_SEND_OPT_DELIVERY_TIME] = 0;        

    g_uc_p->send_opt.read_report_str[0] = (UI_string_type)GetString((U16) (STR_GLOBAL_OFF));
    g_uc_p->send_opt.read_report_str[1] = (UI_string_type)GetString((U16) (STR_GLOBAL_ON));
    g_uc_p->send_opt.read_report = g_uc_p->msg.read_report;

    g_uc_p->send_opt.delivery_report_str[0] = (UI_string_type)GetString((U16) (STR_GLOBAL_OFF));
    g_uc_p->send_opt.delivery_report_str[1] = (UI_string_type)GetString((U16) (STR_GLOBAL_ON));
    g_uc_p->send_opt.delivery_report = g_uc_p->msg.delivery_report;        

    g_uc_p->send_opt.priority_str[0] = (UI_string_type)GetString((U16) (STR_UC_PRIORITY_LOW_ID));
    g_uc_p->send_opt.priority_str[1] = (UI_string_type)GetString((U16) (STR_UC_PRIORITY_MEDIUM_ID));
    g_uc_p->send_opt.priority_str[2] = (UI_string_type)GetString((U16) (STR_UC_PRIORITY_HIGH_ID));
    g_uc_p->send_opt.priority = g_uc_p->msg.priority - 1;        

    g_uc_p->send_opt.validity_period_str[0] = (UI_string_type)GetString((U16) (STR_UC_VALIDITY_PERIOD_1_HOUR_ID));
    g_uc_p->send_opt.validity_period_str[1] = (UI_string_type)GetString((U16) (STR_UC_VALIDITY_PERIOD_6_HOUR_ID));

    g_uc_p->send_opt.validity_period_str[2] = (UI_string_type)GetString((U16) (STR_UC_VALIDITY_PERIOD_12_HOUR_ID));
    g_uc_p->send_opt.validity_period_str[3] = (UI_string_type)GetString((U16) (STR_UC_VALIDITY_PERIOD_1_DAY_ID));
    g_uc_p->send_opt.validity_period_str[4] = (UI_string_type)GetString((U16) (STR_UC_VALIDITY_PERIOD_1_WEEK_ID));
    g_uc_p->send_opt.validity_period_str[5] = (UI_string_type)GetString((U16) (STR_UC_VALIDITY_PERIOD_MAX_ID));
    g_uc_p->send_opt.validity_period = g_uc_p->msg.expiry_time - 1;
    
    g_uc_p->send_opt.delivery_time_str[0] = (UI_string_type)GetString((U16) (STR_UC_DELIVERY_TIME_IMMEDIATE_ID));
    g_uc_p->send_opt.delivery_time_str[1] = (UI_string_type)GetString((U16) (STR_UC_DELIVERY_TIME_1_HOUR_ID));
    g_uc_p->send_opt.delivery_time_str[2] = (UI_string_type)GetString((U16) (STR_UC_DELIVERY_TIME_12_HOUR_ID));
    g_uc_p->send_opt.delivery_time_str[3] = (UI_string_type)GetString((U16) (STR_UC_DELIVERY_TIME_24_HOUR_ID));
    g_uc_p->send_opt.delivery_time = g_uc_p->msg.delivery_time - 1;                     
    
    /* Validity period */
    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_VALIDITY_PERIOD_CAPTION], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
                            0);

    SetInlineItemCaption(&wgui_inline_items[MMI_UC_SEND_OPT_VALIDITY_PERIOD_CAPTION],
                         (U8*) GetString(STR_UC_VALIDITY_PERIOD_ID));

    SetInlineItemSelect(&wgui_inline_items[MMI_UC_SEND_OPT_VALIDITY_PERIOD],
                        6,
                        (U8 **) g_uc_p->send_opt.validity_period_str,
                        &g_uc_p->send_opt.validity_period);

    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_VALIDITY_PERIOD], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
                            0);


    /* Delivery Report */
    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_REPORT_CAPTION], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
                            0);

    SetInlineItemCaption(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_REPORT_CAPTION],
                         (U8*) GetString(STR_UC_DELIVERY_REPORT_ID));

    SetInlineItemSelect(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_REPORT],
                        2,
                        (U8 **) g_uc_p->send_opt.delivery_report_str,
                        &g_uc_p->send_opt.delivery_report);

    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_REPORT], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
                            0);

    /* Read Report */
    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_READ_REPORT_CAPTION], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
                            0);

    SetInlineItemCaption(&wgui_inline_items[MMI_UC_SEND_OPT_READ_REPORT_CAPTION],
                         (U8*) GetString(STR_UC_READ_REPORT_ID));

    SetInlineItemSelect(&wgui_inline_items[MMI_UC_SEND_OPT_READ_REPORT],
                        2,
                        (U8 **) g_uc_p->send_opt.read_report_str,
                        &g_uc_p->send_opt.read_report);

    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_READ_REPORT], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
                            0);

    /* Priotiry */
    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_PRIORITY_CAPTION], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
                            0);

    SetInlineItemCaption(&wgui_inline_items[MMI_UC_SEND_OPT_PRIORITY_CAPTION],
                         (U8*) GetString(STR_UC_PRIORITY_ID));

    SetInlineItemSelect(&wgui_inline_items[MMI_UC_SEND_OPT_PRIORITY],
                        3,
                        (U8 **) g_uc_p->send_opt.priority_str,
                        &g_uc_p->send_opt.priority);

    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_PRIORITY], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
                            0);

    /* Delivery Time */
    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_TIME_CAPTION], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
                            0);

    SetInlineItemCaption(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_TIME_CAPTION],
                         (U8*) GetString(STR_UC_DELIVERY_TIME_ID));

    SetInlineItemSelect(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_TIME],
                        4,
                        (U8 **) g_uc_p->send_opt.delivery_time_str,
                        &g_uc_p->send_opt.delivery_time);

    SetInlineItemActivation(&wgui_inline_items[MMI_UC_SEND_OPT_DELIVERY_TIME], 
                            INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 
                            0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_opt_done_no_hdlr
 * DESCRIPTION
 *  Save the setting to context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_opt_done_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
        g_uc_p->main.state == MMI_UC_STATE_SEND)
    {
        if (IsScreenPresent(SCR_ID_UC_OPT_DONE_OPT))
        {
            GoBackToHistory(SCR_ID_UC_OPT_DONE_OPT);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (IsScreenPresent(SCR_ID_UC_EDITOR))
        {
            GoBackToHistory(SCR_ID_UC_EDITOR);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_opt_done_yes_hdlr
 * DESCRIPTION
 *  Save the setting to context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_opt_done_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString(STR_GLOBAL_DONE),
                 IMG_GLOBAL_ACTIVATED,
                 1,
                 MMI_UC_POPUP_TIME_OUT,
                 (U8) SUCCESS_TONE);

    g_uc_p->msg.read_report = g_uc_p->send_opt.read_report;
    g_uc_p->msg.delivery_report = g_uc_p->send_opt.delivery_report;
    g_uc_p->msg.priority = g_uc_p->send_opt.priority + 1;
    g_uc_p->msg.expiry_time = g_uc_p->send_opt.validity_period + 1;
    g_uc_p->msg.delivery_time = g_uc_p->send_opt.delivery_time + 1;
    
    if (g_uc_p->main.state == MMI_UC_STATE_FORWARD ||
        g_uc_p->main.state == MMI_UC_STATE_SEND)
    {
        if (IsScreenPresent(SCR_ID_UC_OPT_DONE_OPT))
        {
            DeleteUptoScrID(SCR_ID_UC_OPT_DONE_OPT);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (IsScreenPresent(SCR_ID_UC_EDITOR))
        {
            DeleteUptoScrID(SCR_ID_UC_EDITOR);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_send_opt_done_hdlr
 * DESCRIPTION
 *  Save the setting to context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_send_opt_done_hdlr(void)
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
    
    SetLeftSoftkeyFunction(mmi_uc_send_opt_done_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_uc_send_opt_done_no_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_input_method_done
 * DESCRIPTION
 *  Funtion is called when type of input method is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_input_method_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    GoBackToHistory(SCR_ID_UC_EDITOR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_done
 * DESCRIPTION
 *  Funtion is called when done menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_uc_p->done.pre_msg_type = g_uc_p->msg_type.curr_msg_type;
    
    SetLeftSoftkeyFunction(mmi_uc_entry_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_insert
 * DESCRIPTION
 *  Funtion is called when insert menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_insert, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_insert, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_remove
 * DESCRIPTION
 *  Funtion is called when remove menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_remove, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_remove, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_replace
 * DESCRIPTION
 *  Funtion is called when replace menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_replace, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_replace, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_slide_opt
 * DESCRIPTION
 *  Funtion is called when slide option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_slide_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_slide_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_slide_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_msg_type
 * DESCRIPTION
 *  Funtion is called when msg type menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_msg_type, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_msg_type, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_send_opt
 * DESCRIPTION
 *  Funtion is called when send option menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_send_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_send_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_send_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_msg_detail
 * DESCRIPTION
 *  Funtion is called when msg detail menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_msg_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_msg_detail, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_msg_detail, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_input_method
 * DESCRIPTION
 *  Funtion is called when input method menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetInputMethodAndDoneCaptionIcon(IMG_UC_ENTRY_SCRN_CAPTION_ID);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_uc_entry_input_method_done);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_opt_preview
 * DESCRIPTION
 *  Funtion is called when preview menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_opt_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_uc_entry_preview, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_preview, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_preview
 * DESCRIPTION
 *  Entry preview dummy screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_back = CheckIsBackHistory();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/            
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedComposerMain.c] mmi_uc_entry_preview redraw due to Small Screen *\n");
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */
                
    EntryNewScreen(SCR_ID_UC_MSG_PREVIEW, mmi_uc_exit_generic,  mmi_uc_entry_preview, NULL);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_preview *\n");

    if (is_back)
    {
        g_uc_p->send_info.action = MMI_UC_ACTION_IDLE;
        
        if (g_uc_p->send_info.new_msg_id)
        {
            mmi_uc_clear_msg_bearer(MMI_UC_MSG_TYPE_MMS_PREFER);
        }
        GoBackToHistory(SCR_ID_UC_EDITOR);        
    }
    else
    {
        g_uc_p->send_info.action = MMI_UC_ACTION_PREVIEW;
        MMI_ASSERT(g_uc_p->send_info.new_msg_id == 0);
        mmi_uc_create_mms();
    }    

    SetDelScrnIDCallbackHandler(SCR_ID_UC_MSG_PREVIEW, (HistoryDelCBPtr) mmi_uc_preview_delete_history_hdlr);
 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_uc_preview_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[UnifiedComposerMiscell.c] mmi_uc_preview_delete_history_hdlr(), send_info.action=%d new_msg_id=%d",
                             g_uc_p->send_info.action, g_uc_p->send_info.new_msg_id);
                             
    if (g_uc_p->send_info.action == MMI_UC_ACTION_PREVIEW && g_uc_p->send_info.new_msg_id)
    {
        g_uc_p->send_info.action = MMI_UC_ACTION_SAVE_IN_BACKGROUND;
        mmi_uc_save_mms_req(g_uc_p->send_info.new_msg_id, MMA_FOLDER_DRAFT);
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_mms
 * DESCRIPTION
 *  Preview mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_preview_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_uc_set_processing_screen(STR_UC_PREVIEW_ID, STR_UC_PLEASE_WAIT_ID, IMG_GLOBAL_PROGRESS, 0);
    mmi_uc_entry_processing_generic();
    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);

    mmi_uc_preview_mms_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_generic
 * DESCRIPTION
 *  Generic exit function for unified composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_set_processing_screen
 * DESCRIPTION
 *  Set string and image for UC processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_uc_p->processing.caption_str_id = captionStrId;
    g_uc_p->processing.body_str_id = bodyStrId;
    g_uc_p->processing.animation_image_id = animationImageId;
    g_uc_p->processing.RSK_str_id = rskStrId;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_exit_processing_generic
 * DESCRIPTION
 *  Exit generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UC_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_time_out_processing_generic
 * DESCRIPTION
 *  Time out call back of processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_time_out_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UC_INPROGRESS_TIMER_ID);
    if (GetExitScrnID() == SCR_ID_UC_PROCESSING)
    {
        DisplayPopup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_UNFINISHED,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) ERROR_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_processing
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_PROCESSING, mmi_uc_exit_processing_generic, mmi_uc_entry_processing, NULL);


    ShowCategory8Screen(
        g_uc_p->processing.caption_str_id,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        0,
        0,
        g_uc_p->processing.RSK_str_id,
        0,
        g_uc_p->processing.body_str_id,
        g_uc_p->processing.animation_image_id,
        NULL);


    if (g_uc_p->processing.RSK_str_id == 0)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);
        if (isInCall())
        {
            SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
        }

        StartTimer(UC_INPROGRESS_TIMER_ID, MMI_UC_INPROGRESS_TIME_OUT, mmi_uc_time_out_processing_generic);
    }
    else
    {
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_add_processing_to_history
 * DESCRIPTION
 *  Add processing screen to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_add_processing_to_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    history *pCurrHistory = NULL;
    pCurrHistory = OslMalloc(sizeof(history));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*)pCurrHistory, 0, sizeof(history));
    pCurrHistory->scrnID = SCR_ID_UC_PROCESSING;
    pCurrHistory->entryFuncPtr = mmi_uc_entry_processing;
    memset((S8*) pCurrHistory->inputBuffer, 0, ENCODING_LENGTH);

    AddHistory(*pCurrHistory);
    OslMfree(pCurrHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_processing_generic
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isIncomingCall() || AlmIsTonePlaying())
    {
        mmi_uc_add_processing_to_history();
    }
    else
    {
        mmi_uc_entry_processing();        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_processing_after_send
 * DESCRIPTION
 *  Entry MSG processing screen after send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_processing_after_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCR_ID_UC_SENDING)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_processing_after_send *\n");
        mmi_uc_entry_processing_generic();            
    }
    else if (IsScreenPresent(SCR_ID_UC_SENDING))
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_processing_after_send history replace *\n");
        HistoryReplace(SCR_ID_UC_SENDING, SCR_ID_UC_PROCESSING, mmi_uc_entry_processing);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_entry_processing_after_send DO NOTHING *\n");
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_highlight_preferred_type
 * DESCRIPTION
 *  Funtion is called when preferred msg type menu item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_highlight_preferred_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_uc_entry_preferred_type, KEY_EVENT_UP);
    SetKeyHandler(mmi_uc_entry_preferred_type, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_preferred_type
 * DESCRIPTION
 *  Entry preferred msg type screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_entry_preferred_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 2;
    S32 hiliteitem;
    S8 index;
    S16 errorCode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_PREFERRED_MSG_TYPE, mmi_uc_exit_generic, mmi_uc_entry_preferred_type, NULL);

    subMenuDataPtrs[0] = (PU8) GetString(STR_UC_TEXT_MESSAGE_ID);
    subMenuDataPtrs[1] = (PU8) GetString(STR_UC_MULTIMEDIA_MESSAGE_ID);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_PREFERRED_MSG_TYPE);
    
    if ((guiBuffer != NULL))
    {
        hiliteitem = g_uc_p->main.object_index;
        MMI_ASSERT(hiliteitem < nNumofItem);
    }
    else
    {
        ReadValue(NVRAM_UC_PREFERRED_MSG_TYPE, &index, DS_BYTE, &errorCode);
        hiliteitem = index;
    }
    
    RegisterHighlightHandler(mmi_uc_set_index);

    ShowCategory109Screen(
        STR_UC_MESSAGE_TYPE_ID,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        subMenuDataPtrs,
        NULL,
        hiliteitem,
        guiBuffer);
    
    SetLeftSoftkeyFunction(mmi_uc_save_preferred_type, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_entry_preferred_type
 * DESCRIPTION
 *  Entry preferred msg type screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_uc_save_preferred_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            MMI_UC_POPUP_TIME_OUT,
            (U8) SUCCESS_TONE);
    
    WriteValue(NVRAM_UC_PREFERRED_MSG_TYPE, &(g_uc_p->main.object_index), DS_BYTE, &errorCode);
    DeleteScreenIfPresent(SCR_ID_UC_PREFERRED_MSG_TYPE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_uc_handle_text_in_current_slide
 * DESCRIPTION
 *  Save content of text buffer to file OR delete text object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_uc_handle_text_in_current_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_text_path[MMI_UC_MAX_TEMP_FILE_LEN];
    mmi_uc_object_struct * object = NULL;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_uc_text_path, 0, MMI_UC_MAX_TEMP_FILE_LEN);
    MMI_UC_MAKE_TEXT_FILE_PATH(mmi_uc_text_path, g_uc_p->msg.current_slide_num);

    /* Add text object with empty content to the slide */
    if (g_uc_p->msg.current_slide->text.char_count > 0)
    {           
        result = mmi_uc_save_buffer_to_file(mmi_uc_text_path, g_uc_p->main.text_buffer,g_uc_p->msg.current_slide->text.char_count);

        if (result == FS_NO_ERROR)
        {
            if (g_uc_p->msg.current_slide->text.object == NULL)
            {
                object = mmi_uc_insert_object((S8*)mmi_uc_text_path, MMI_UC_OBJECT_TYPE_TEXT);
                mmi_uc_insert_object_to_slide(object, g_uc_p->msg.current_slide, MMI_UC_OBJECT_TYPE_TEXT);
            }
            else
            {
                g_uc_p->msg.current_slide->text.object->size = applib_get_file_size((kal_wchar*)mmi_uc_text_path);    
            }
        }
        else
        {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[UnifiedComposerMain.c] mmi_uc_handle_text_in_current_slide, save to file error=%d*\n",result);
        }
    }            
    /* Delete the text object */ 
    else if (g_uc_p->msg.current_slide->text.char_count == 0)
    {
        if (g_uc_p->msg.current_slide->text.object)
        {
            MMI_ASSERT(FS_Delete((U16*)mmi_uc_text_path) == FS_NO_ERROR);

            mmi_uc_delete_object_from_list(g_uc_p->msg.current_slide->text.object);
            memset(&(g_uc_p->msg.current_slide->text), 0, sizeof(mmi_uc_text_object_info_struct));            
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    return result;

}

#ifdef __MMI_MMS_2__
static U16 mmi_uc_preview_list_index;

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_get_hilited_index
 * DESCRIPTION
 *  hilight handler
 * PARAMETERS
 *  S32
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_uc_preview_get_hilited_index(S32 nIndex)
{
    mmi_uc_preview_list_index = (U16) nIndex;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_goto_slide
 * DESCRIPTION
 *  LSK handler for slide list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_uc_preview_goto_slide(void)
{
    mmi_mv_goto_slide((U16)mmi_uc_preview_list_index+1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_preview_slide_list_get_item
 * DESCRIPTION
 *  get item callback for category184
 * PARAMETERS
 *  S32
 *  UI_string_type
 *  PU8
 *  U8
 * RETURNS
 *  void
 *****************************************************************************/

pBOOL mmi_uc_preview_slide_list_get_item (S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define MMI_UC_INDEX_STR_LEN 5
    U16 temp [MMI_UC_INDEX_STR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp, 0, MMI_UC_INDEX_STR_LEN);
    kal_wsprintf(temp, " %d", item_index+1);
    mmi_ucs2ncpy((PS8)str_buff, (PS8) GetString(STR_UC_PREVIEW_SLIDE), MAX_SUB_MENU_SIZE);
    mmi_ucs2ncat((PS8)str_buff, (PS8) temp, MMI_UC_INDEX_STR_LEN);

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);

    return TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_uc_show_preview_slide_list
 * DESCRIPTION
 *  show slide list for preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_uc_show_preview_slide_list (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 num_of_slides;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_UC_PREVIEW_SLIDE_LIST, NULL, mmi_uc_show_preview_slide_list, NULL);

    num_of_slides = mmi_mv_get_total_slide_num();
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_UC_PREVIEW_SLIDE_LIST);

    if (guiBuffer != NULL)
    {
        mmi_uc_preview_list_index = (mmi_uc_preview_list_index < num_of_slides) ? mmi_uc_preview_list_index : 0;
    }
    else
    {
        mmi_uc_preview_list_index = mmi_mv_get_current_slide_num()-1;
    }
    
    RegisterHighlightHandler(mmi_uc_preview_get_hilited_index);

    ShowCategory184Screen(
        STR_UC_PREVIEW_SLIDE_LIST,
        IMG_UC_ENTRY_SCRN_CAPTION_ID,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_of_slides,
        mmi_uc_preview_slide_list_get_item,
        NULL,
        mmi_uc_preview_list_index,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_uc_preview_goto_slide, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_uc_preview_goto_slide, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 
}
#endif /* __MMI_MMS_2__ */

#endif /* __MMI_UNIFIED_COMPOSER__ */ 
#endif /* _MMI_UNIFIED_COMPOSER_MAIN_C */ 

