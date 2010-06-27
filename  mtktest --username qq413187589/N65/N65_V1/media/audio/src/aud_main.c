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
 *   aud_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of audio manager task.
 *
 * Author:
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

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */

#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

aud_context_struct *aud_context_p = &(med_context.aud_context);

/* ring buffer for VM recording/playback or DAF playing */

/* kal_uint8  melody_buffer[AUD_MELODY_BUFFER_LEN]; */

kal_uint16 ring_buffer[AUD_RING_BUFFER_LEN];

#ifdef __MED_BT_MOD__
extern kal_bool aud_bt_main(ilm_struct *ilm_ptr);
extern void aud_bt_init(void);
#endif /* __MED_BT_MOD__ */ 

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  aud_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->startup = KAL_TRUE;

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    aud_melody_startup();

#if defined(VM_SUPPORT) && defined(VM_LOG)
    aud_vm_startup();
#endif 

#ifdef __MED_MMA_MOD__
    aud_mma_startup();
#endif 

#ifdef __MED_VR_MOD__
    aud_vr_startup();
#endif 

#ifdef __MED_VRSI_MOD__
    aud_vrsi_startup();
#endif 

    /* Initialize background sound effect */
#ifdef __MED_SND_MOD__
    aud_snd_startup();
#endif 

    /* Initialize audio post process */
#if defined(__MED_AUD_AUDIO_EFFECT__)
    aud_post_process_startup();
#endif 

#ifdef __MED_GENERAL_TTS__
    aud_tts_startup();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_startup_param
 * DESCRIPTION
 *  This function is to set audio parameters when startup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_startup_param(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_mic_mute(KAL_TRUE);
    L1SP_LoadCommonSpeechPara(aud_context_p->audio_param.speech_common_para);
    aud_set_aud_path_volume(aud_context_p->audio_mode);
    aud_melody_set_max_swing(aud_context_p->audio_param.max_swing);
}


/*****************************************************************************
 * FUNCTION
 *  aud_startup_read_nvram_data
 * DESCRIPTION
 *  This function is to read audio nvram data when startup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_startup_read_nvram_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_STARTUP_READ_NVRAM_DATA);

    med_context_p->nvram_state = MED_POWERON_READING_NVRAM;
    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CUST_ACOUSTIC_DATA_LID, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  aud_main
 * DESCRIPTION
 *  This function is main message dispatching function of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_main(ilm_struct *ilm_ptr)
{
/* The following message is not use in MODEM project */
#ifndef MED_MODEM
#ifdef __MED_BT_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_bt_main(ilm_ptr))
    {
        return;
    }
#endif /* __MED_BT_MOD__ */ 
#endif /* MED_MODEM */
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_L4AUD_GET_AUDIO_MODE_REQ:
            aud_get_audio_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_SET_AUDIO_MODE_REQ:
            aud_set_audio_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_GPIO_DETECT_IND:
            aud_gpio_detect_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_GET_AUDIO_PROFILE_REQ:
            aud_get_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_SET_AUDIO_PROFILE_REQ:
            aud_set_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_GET_AUDIO_PARAM_REQ:
            aud_get_audio_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_SET_AUDIO_PARAM_REQ:
            aud_set_audio_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_SP_SET_INPUT_MODE_REQ:
            aud_speech_set_input_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_SP_SET_MODE_REQ:
            aud_speech_set_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_SET_FIR_REQ:
            break;
        case MSG_ID_L4AUD_AUDIO_SET_DEVICE_REQ:
            aud_audio_set_device_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_GET_VOLUME_REQ:
            aud_audio_get_volume_req(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ:
            aud_audio_set_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_GET_GAIN_REQ:
            aud_audio_get_gain_req(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_SET_GAIN_REQ:
            aud_audio_set_gain_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_PLAY_REQ:
            aud_play_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_STOP_REQ:
            aud_stop_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_MUTE_REQ:
            aud_audio_mute_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_MUTE_REQ:
            aud_set_mute_req_hdlr(ilm_ptr);
            break;
/* The following message is not use in MODEM project */
#ifndef MED_MODEM
        case MSG_ID_L4AUD_AUDIO_PLAY_BY_NAME_REQ:
            aud_play_by_name_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_STOP_BY_NAME_REQ:
            aud_stop_by_name_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_PLAY_BY_STRING_REQ:
            aud_play_by_string_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_STOP_BY_STRING_REQ:
            aud_stop_by_string_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_AUDIO_PLAY_TONE_SEQ_REQ:
            break;
        case MSG_ID_L4AUD_AUDIO_STOP_TONE_SEQ_REQ:
            break;
        case MSG_ID_L4AUD_AUDIO_DEMO_IMY_REQ:
            break;
            /* daf, xwav, amr */
        case MSG_ID_L4AUD_MEDIA_RECORD_REQ:
            aud_media_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_PLAY_REQ:
            aud_media_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_STOP_REQ:
            aud_media_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_PAUSE_REQ:
            aud_media_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_RESUME_REQ:
            aud_media_resume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_AUD_MEDIA_READ_DATA_IND:
            aud_media_read_data_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_AUD_MEDIA_WRITE_DATA_IND:
            aud_media_write_data_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_AUD_MEDIA_PLAY_EVENT_IND:
            aud_media_play_event_hdlr(ilm_ptr);
            break;
        case MSG_ID_AUD_MEDIA_PLAY_STREAM_EVENT_IND:
            aud_media_process_file_stream(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_BLOCK_REQ:
            aud_block_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_STORE_REQ:
            aud_media_store_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_MEDIA_RESTORE_REQ:
            aud_media_restore_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_VIBRATOR_ENABLED_REQ:
            aud_set_vibrator_enabled_req_hdlr(ilm_ptr);
            break;

    #ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
            /* -- added for turn on/off backlight by MMI task -- */
        case MSG_ID_MMIAPI_BACKLIGHT_CONTROL_RSP:
            aud_backlight_ctrl_rsp_hdlr(ilm_ptr);
            break;
    #endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
        case MSG_ID_MEDIA_AUD_SET_HEADSET_MODE_OUTPUT_PATH:
            aud_set_headset_mode_output_path_req_hdlr(ilm_ptr);
            break;

    #ifdef __MMI_SUPPORT_LED_SYNC__
            /* -- added for turn on/off backlight by MMI task -- */
        case MSG_ID_MMIAPI_LED_CONTROL_RSP:
            aud_led_ctrl_rsp_hdlr(ilm_ptr);
            break;
    #endif /* __MMI_SUPPORT_LED_SYNC__ */ 

    #ifdef __RICH_AUDIO_PROFILE__
        case MSG_ID_MEDIA_AUD_START_CALC_SPECTRUM_REQ:
            aud_start_calc_spectrum_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_CALC_SPECTRUM_REQ:
            aud_stop_calc_spectrum_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_SPECTRUM_REQ:
            aud_get_spectrum_req_hdlr(ilm_ptr);
            break;
    #endif /* __RICH_AUDIO_PROFILE__ */ 

            /* play file portion related function */
        case MSG_ID_MEDIA_AUD_GET_DURATION_REQ:
            aud_media_get_duration_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_PROGRESS_TIME_REQ:
            aud_media_get_progress_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_PROGRESS_TIME_REQ:
            aud_media_set_progress_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_CHECK_IS_PURE_AUDIO_REQ:
            aud_media_is_pure_audio_req_hdlr(ilm_ptr);
            break;
            
            /* FM Radio Begin: Added by Tim */
        case MSG_ID_MEDIA_FMR_POWER_ON_REQ:
            aud_fmr_power_on_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_POWER_OFF_REQ:
            aud_fmr_power_off_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_SET_FREQ_REQ:
            aud_fmr_set_freq_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_MUTE_REQ:
            aud_fmr_mute_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_REQ:
            aud_fmr_check_is_valid_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_REQ:
            aud_fmr_get_signal_level_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_FMR_EVALUATE_THRESHOLD_REQ:
            aud_fmr_evaluate_threshold_req_hdlr(ilm_ptr);
            break;
            /* FM Radio End: Added by Tim */

//ANALOG_TV_SUPPORT
//Analog tv begin
#ifdef  __MED_TLG_TV_MOD__
     case MSG_ID_MEDIA_ANALOG_TV_POWER_UP_REQ:
	     aud_analog_tv_power_up_hdlr(ilm_ptr);
           break;
      case MSG_ID_MEDIA_ANALOG_TV_POWER_DOWN_REQ:
           aud_analog_tv_power_down_hdlr(ilm_ptr);
            break;
       case MSG_ID_MEDIA_ANALOG_TV_OPEN_PATH_REQ:
		aud_analog_tv_open_path_req_hdlr( ilm_ptr );
		break;
	case MSG_ID_MEDIA_ANALOG_TV_CLOSE_PATH_REQ:
		aud_analog_tv_close_path_req_hdlr( ilm_ptr );
		break;
	case MSG_ID_MEDIA_ANALOG_TV_MUTE_REQ:
		aud_analog_tv_mute_req_hdlr( ilm_ptr );
		break;
	case MSG_ID_MEDIA_ANALOG_TV_SET_CHANNEL_REQ:
		aud_analog_tv_set_channel_req_hdlr( ilm_ptr );
		break;	
       case MSG_ID_MEDIA_ANALOG_TV_GET_VALID_CHANNEL_REQ:
	   	aud_analog_tv_get_valid_channel_req_hdlr(ilm_ptr);
	   	 break;
#endif		 
            /* VR Begin: Added by Tim */
    #ifdef __MED_VR_MOD__
        case MSG_ID_MEDIA_VR_GET_VERSION_REQ:
        case MSG_ID_MEDIA_VR_GET_PARAM_REQ:
        case MSG_ID_MEDIA_VR_SET_PARAM_REQ:
        case MSG_ID_MEDIA_VR_INIT_RCG_REQ:
        case MSG_ID_MEDIA_VR_INIT_TRN_REQ:
        case MSG_ID_MEDIA_VR_RCG_PROCESS_REQ:
        case MSG_ID_MEDIA_VR_TRN_PROCESS_REQ:
        case MSG_ID_MEDIA_VR_VOICE_IN_REQ:
        case MSG_ID_MEDIA_VR_DEL_TAG_REQ:
        case MSG_ID_MEDIA_VR_CHECK_TAG_REQ:
        case MSG_ID_MEDIA_VR_SYNC_DB_REQ:
        case MSG_ID_MEDIA_VR_PLAY_TAG_REQ:
        case MSG_ID_MEDIA_VR_GET_DIR_REQ:
        case MSG_ID_MEDIA_VR_ADD_TAG_REQ:
        case MSG_ID_MEDIA_VR_ABORT_REQ:
            aud_vr_main(ilm_ptr);
            break;
    #endif /* __MED_VR_MOD__ */ 
            /* VR End: Added by Tim */

    #ifdef __MED_VRSI_MOD__
        case MSG_ID_MEDIA_VRSI_INIT_REQ:
        case MSG_ID_MEDIA_VRSI_ADD_TAGS_REQ:
        case MSG_ID_MEDIA_VRSI_START_TRN_REQ:
        case MSG_ID_MEDIA_VRSI_START_RCG_REQ:
        case MSG_ID_MEDIA_VRSI_PROCESS_IND:
        case MSG_ID_MEDIA_VRSI_PLAY_TAG_REQ:
        case MSG_ID_MEDIA_VRSI_PLAY_TTS_REQ:
        case MSG_ID_MEDIA_VRSI_GET_TAGNUM_REQ:
        case MSG_ID_MEDIA_VRSI_GET_TAGINFO_REQ:
        case MSG_ID_MEDIA_VRSI_DEL_TAGS_REQ:
        case MSG_ID_MEDIA_VRSI_RESET_TAGS_REQ:
        case MSG_ID_MEDIA_VRSI_SYNC_DB_REQ:
        case MSG_ID_MEDIA_VRSI_ABORT_REQ:
        case MSG_ID_MEDIA_VRSI_CLOSE_REQ:
            aud_vrsi_main(ilm_ptr);
            break;
    #endif /* __MED_VRSI_MOD__ */ 

    #if defined(VM_SUPPORT) && defined(VM_LOG)
        case MSG_ID_L4AUD_VM_RECORD_REQ:
        case MSG_ID_L4AUD_VM_STOP_REQ:
        case MSG_ID_L4AUD_VM_DELETE_REQ:
        case MSG_ID_L4AUD_VM_ABORT_REQ:
        case MSG_ID_L4AUD_VM_PAUSE_REQ:
        case MSG_ID_L4AUD_VM_RESUME_REQ:
        case MSG_ID_L4AUD_VM_APPEND_REQ:
        case MSG_ID_L4AUD_VM_GET_INFO_REQ:
        case MSG_ID_AUD_VM_READ_DATA_IND:
        case MSG_ID_AUD_VM_WRITE_DATA_IND:
        case MSG_ID_L4AUD_VM_RENAME_REQ:
        case MSG_ID_L4AUD_VM_PLAY_REQ:
            aud_vm_main(ilm_ptr);
            break;
    #endif /* defined(VM_SUPPORT) && defined(VM_LOG) */ 

    #ifdef __MED_MMA_MOD__
            /* MMA */
        case MSG_ID_MEDIA_MMA_OPEN_REQ:
            aud_mma_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_CLOSE_REQ:
            aud_mma_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PLAY_REQ:
            aud_mma_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_STOP_REQ:
            aud_mma_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PAUSE_REQ:
            aud_mma_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_RESUME_REQ:
            aud_mma_resume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_AUDIO_INFO_REQ:
            aud_mma_get_audio_info_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_DURATION_REQ:
            aud_mma_get_duration_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_CURRENT_TIME_REQ:
            aud_mma_get_current_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_START_TIME_REQ:
            aud_mma_set_start_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_STOP_TIME_REQ:
            aud_mma_set_stop_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_GET_VOLUME_REQ:
            aud_mma_get_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_VOLUME_REQ:
            aud_mma_set_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PLAY_EVENT_IND:
            aud_mma_play_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_PROCESS_EVENT_IND:
            aud_mma_fsal_process_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_WRITE_DATA_IND_REQ:
            aud_mma_write_data_ind_req_hdlr(ilm_ptr);
            break;
    #ifdef __MED_MMA_JAVA_CTRL__
        case MSG_ID_MEDIA_MMA_SET_RATE_REQ:
            aud_mma_set_rate_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_TEMPO_REQ:
            aud_mma_set_tempo_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_PITCH_REQ:
            aud_mma_set_pitch_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SEND_LONG_MSG_REQ:
            aud_mma_send_long_msg_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SEND_SHORT_MSG_REQ:
            aud_mma_send_short_msg_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_OPEN_DEVICE_REQ:
            aud_mma_open_device_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_CLOSE_DEVICE_REQ:
            aud_mma_close_device_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_CHANNEL_VOLUME_REQ:
            aud_mma_set_channel_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_PROGRAM_REQ:
            aud_mma_set_program_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_SET_DATA_REQ:
            aud_mma_set_data_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_MMA_TEMP_2:
            break;
    #endif /* __MED_MMA_JAVA_CTRL__ */
    #endif /* __MED_MMA_MOD__ */ 

    #ifdef __MED_SND_MOD__
        case MSG_ID_MEDIA_SND_CHECK_BYTE_STREAM_FORMAT_REQ:
            aud_snd_check_byte_stream_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_CHECK_FILE_FORMAT_REQ:
            aud_snd_check_file_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_PLAY_BYTE_STREAM_REQ:
            aud_snd_play_byte_stream_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_PLAY_FILE_REQ:
            aud_snd_play_file_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_PLAY_EVENT_IND:
            aud_snd_process_event(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_STOP_PLAY_REQ:
            aud_snd_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_SND_SET_VOLUME_REQ:
            aud_snd_set_volume_req_hdlr(ilm_ptr);
            break;
    #endif /* __MED_SND_MOD__ */ 

    #if defined(__MED_AUD_TIME_STRETCH__)
        case MSG_ID_MEDIA_AUD_STRETCH_CHECK_STREAM_FORMAT_REQ:
            aud_stretch_check_stream_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STRETCH_CHECK_FILE_FORMAT_REQ:
            aud_stretch_check_file_format_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STRETCH_SET_SPEED_REQ:
            aud_stretch_set_speed_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STRETCH_CLOSE_REQ:
            aud_stretch_close_req_hdlr();
            break;
   #endif /* #if defined(__MED_AUD_TIME_STRETCH__) */
   #if defined(__MED_AUD_REVERB__)
        case MSG_ID_MEDIA_AUD_REVERB_SET_COEFF_REQ:
            aud_reverb_set_coeff_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_REVERB_TURN_ON_REQ:
            aud_reverb_turn_on_req_hdlr();
            break;
        case MSG_ID_MEDIA_AUD_REVERB_TURN_OFF_REQ:
            aud_reverb_turn_off_req_hdlr();
            break;
    #endif /* #ifdef defined(__MED_AUD_REVERB__) */ 
    #if defined(__MED_AUD_SURROUND__)
        case MSG_ID_MEDIA_AUD_SURROUND_TURN_ON_REQ:
            aud_surround_turn_on_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SURROUND_TURN_OFF_REQ:
            aud_surround_turn_off_req_hdlr();
            break;
    #endif /* #if defined(__MED_AUD_SURROUND__) */
   #if defined(__MED_AUD_EQUALIZER__)
        case MSG_ID_MEDIA_AUD_EQ_SET_MAGNITUDE_REQ:
            aud_eq_set_magnitude_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_EQ_TURN_ON_REQ:
            aud_eq_turn_on_req_hdlr();
            break;
        case MSG_ID_MEDIA_AUD_EQ_TURN_OFF_REQ:
            aud_eq_turn_off_req_hdlr();
            break;
    #endif /* #ifdef defined(__MED_AUD_EQUALIZER__) */ 
    #ifdef __MED_GENERAL_TTS__
        case MSG_ID_MEDIA_AUD_TTS_SET_ATTR_REQ:
            aud_tts_set_attr_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_PLAY_EVENT_IND:
            aud_tts_process_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_PLAY_REQ:
            aud_tts_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_STOP_REQ:
            aud_tts_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_PAUSE_REQ:
            aud_tts_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_TTS_RESUME_REQ:
            aud_tts_resume_req_hdlr(ilm_ptr);
            break;
    #endif /*#ifdef __MED_GENERAL_TTS__*/
        case MSG_ID_MEDIA_IN_PROC_CALL_REQ:
            aud_in_proc_call_req_hdlr(ilm_ptr);
            break;
#endif /* MED_MODEM */
        default:
            /* assert */
            break;
    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  aud_init
 * DESCRIPTION
 *  This function is used to init audio task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* aud_context_p->melody_string_p = &melody_buffer[0]; */
    aud_context_p->melody_string_p = NULL;
    aud_context_p->ring_buf = &ring_buffer[0];
    aud_context_p->buf_p = aud_context_p->ring_buf;
    aud_context_p->buf_len = 0;
    aud_context_p->offset = 0;
    aud_context_p->access_mod = MOD_MMI;
    aud_context_p->block_level = AUD_BLOCK_ALL;
    aud_context_p->aud_event = kal_create_event_group("aud_events");
    aud_context_p->mma_event = kal_create_event_group("mma_events");

//ANALOG_TV_SUPPORT
#ifdef __MED_TLG_TV_MOD__
   aud_context_p->tlg_tv_event = kal_create_event_group("tlg_tv_events");
#endif //#ifdef __MED_TLG_TV_MOD__

#if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)
    aud_context_p->effect_event = kal_create_event_group("effect_events");
#endif 

    if (!aud_speech_init())
    {
        return KAL_FALSE;
    }

    if (!aud_audio_init())
    {
        return KAL_FALSE;
    }

    if (!aud_keytone_init())
    {
        return KAL_FALSE;
    }

    if (!aud_tone_init())
    {
        return KAL_FALSE;
    }

    if (!aud_melody_init())
    {
        return KAL_FALSE;
    }

#if defined(VM_SUPPORT) && defined(VM_LOG)
    if (!aud_vm_init())
    {
        return KAL_FALSE;
    }
#endif /* defined(VM_SUPPORT) && defined(VM_LOG) */ 

    if (!aud_media_init())
    {
        return KAL_FALSE;
    }

#ifdef __MED_CTM_MOD__
    if (!aud_ctm_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_BT_MOD__
    aud_bt_init();
#endif 

    aud_context_p->my_mod_id = MOD_MED;
    aud_context_p->state = AUD_IDLE;
    aud_context_p->startup = KAL_FALSE;
    return KAL_TRUE;
}

#endif /* MED_NOT_PRESENT */ 

