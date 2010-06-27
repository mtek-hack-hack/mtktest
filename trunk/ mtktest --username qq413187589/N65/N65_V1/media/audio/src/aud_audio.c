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
 * aud_audio.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes audio functions of audio manager task.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/******************************************************************
 * MODULE
 *    AUD_AUDIO
 * DESCRIPTION
 *    This module defines the audio related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =======*/

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "custom_equipment.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"

#include "nvram_data_items.h"
#include "nvram_struct.h"
#include "device.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 
#ifdef __MED_CAM_MOD__
#include "cam_main.h"
#endif 
#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
#include "vid_main.h"
#endif 

/*==== TYPE DEFINE =======*/
typedef enum
{
    AUD_MEDIA_PATH_BT_A2DP,
    AUD_MEDIA_PATH_BT_HFP,
    AUD_MEDIA_PATH_BT_BOTH
}aud_media_check_bt_path_enum;

/*==== VARIABLES =======*/
kal_uint8 current_playing_fmradio_volume_level = 0;
extern kal_uint8 current_playing_melody_volume_level;   /* defined in aud_melody.c */
extern kal_bool audio_bluetooth_on;                     /* defined in aud_speech.c */

#if defined(TV_OUT_SUPPORT)
kal_bool audio_tv_cable_in = KAL_FALSE;
kal_bool audio_tv_loud_speaker = KAL_FALSE;
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_audio_init
 * DESCRIPTION
 *  This function is used to init audio module for audio manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_audio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->audio_mode = AUD_MODE_NORMAL;
    aud_context_p->identifier = 0;
    aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER2;
    custom_cfg_audio_ec_range(&aud_context_p->min_ec_level, &aud_context_p->max_ec_level);
    aud_context_p->audio_mute = KAL_FALSE;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_get_audio_mode_req_struct *req_p;
    l4aud_get_audio_mode_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_MODE_REQ_HDLR);

    req_p = (l4aud_get_audio_mode_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (l4aud_get_audio_mode_cnf_struct*) construct_local_para(sizeof(l4aud_get_audio_mode_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->mode = aud_context_p->audio_mode;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_GET_AUDIO_MODE_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DUMMY_CNF
    l4aud_set_audio_mode_cnf_struct *cnf_p = NULL;
#endif 

    l4aud_set_audio_mode_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_SET_AUDIO_MODE_REQ_HDLR);

    req_p = (l4aud_set_audio_mode_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->audio_mode = req_p->mode;
    aud_set_aud_path_volume(req_p->mode);

#ifdef DUMMY_CNF
    cnf_p = (l4aud_set_audio_mode_cnf_struct*) construct_local_para(sizeof(l4aud_set_audio_mode_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->result = KAL_TRUE;
    cnf_p->cause = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_SET_AUDIO_MODE_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */ 

}


/*****************************************************************************
 * FUNCTION
 *  aud_gpio_detect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_gpio_detect_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * l4aud_gpio_detect_ind_struct* ind_p;
     * 
     * AUD_FUNC_ENTRY(AUD_GPIO_DETECT_IND_HDLR)
     * 
     * ind_p = (l4aud_gpio_detect_ind_struct*)ilm_ptr->local_para_ptr;
     * 
     * switch(ind_p->gpio_device)
     * {
     * case EXT_DEV_NONE:
     * if (aud_context_p->audio_mode == AUD_MODE_HEADSET )
     * aud_context_p->audio_mode = AUD_MODE_NORMAL;
     * break;
     * case EXT_DEV_EARPHONE:
     * aud_context_p->audio_mode = AUD_MODE_HEADSET;
     * break;
     * }
     * aud_set_aud_path_volume(aud_context_p->audio_mode);
     */
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_profile_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_get_audio_profile_req_struct *req_p;
    l4aud_get_audio_profile_cnf_struct *cnf_p = NULL;
    kal_uint8 mode;
    audio_profile_struct *profile_p;
    custom_acoustic_struct *data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_PROFILE_REQ_HDLR);
    req_p = (l4aud_get_audio_profile_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (l4aud_get_audio_profile_cnf_struct*)
        construct_local_para(sizeof(l4aud_get_audio_profile_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    mode = req_p->mode;
    profile_p = &cnf_p->audio_profile;
    data_p = &aud_context_p->acoustic_data;
    profile_p->mode = mode;

    if (mode < MAX_VOL_CATE)
    {
        kal_mem_cpy(
            profile_p->speech,
            data_p->volume_gain[mode][AUD_VOLUME_SPH],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_SPH]));
        kal_mem_cpy(
            profile_p->keytone,
            data_p->volume_gain[mode][AUD_VOLUME_KEY],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_KEY]));
        kal_mem_cpy(
            profile_p->melody,
            data_p->volume_gain[mode][AUD_VOLUME_MEDIA],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_MEDIA]));
        kal_mem_cpy(
            profile_p->sound,
            data_p->volume_gain[mode][AUD_VOLUME_FMR],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_FMR]));
        kal_mem_cpy(
            profile_p->mic,
            data_p->volume_gain[mode][AUD_VOLUME_MIC],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_MIC]));
        profile_p->sidetone = data_p->volume_gain[mode][AUD_VOLUME_SID][0];
    #ifdef __16_LEVEL_AUDIO_VOLUME__
        /* get 16-level audio volume settings */
        profile_p->max_melody_volume_gain = data_p->max_melody_volume_gain[mode];
        profile_p->melody_volume_gain_step = data_p->melody_volume_gain_step[mode];
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
        cnf_p->result = KAL_TRUE;
    }
#if defined(TV_OUT_SUPPORT)
    else if(mode == VOL_TV_OUT)
    {
        memset(profile_p, 0 , sizeof(audio_profile_struct));
    #ifdef __16_LEVEL_AUDIO_VOLUME__
        /* get 16-level audio volume settings */
        profile_p->max_melody_volume_gain = data_p->max_melody_volume_gain[mode];
        profile_p->melody_volume_gain_step = data_p->melody_volume_gain_step[mode];
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
        kal_mem_cpy(
            profile_p->tv_out_volume_gain,
            data_p->tv_out_volume_gain,
            sizeof(data_p->tv_out_volume_gain));    
    }
#endif /* TV_OUT_SUPPORT */
    else
    {
        cnf_p->result = KAL_FALSE;
    }

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_GET_AUDIO_PROFILE_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_profile_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    l4aud_set_audio_profile_req_struct *req_p = NULL;
    audio_profile_struct *profile_p;
    custom_acoustic_struct *data_p;
    kal_uint8 mode;
    kal_bool write_to_nvram = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_set_audio_profile_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY(AUD_SET_AUDIO_PROFILE_REQ_HDLR);

    if (req_p)
    {
        aud_context_p->src_id = req_p->src_id;
        profile_p = &req_p->audio_profile;
        data_p = &aud_context_p->acoustic_data;
        mode = profile_p->mode;

        if (mode < MAX_VOL_CATE)
        {
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_SPH],
                profile_p->speech,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_SPH]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_KEY],
                profile_p->keytone,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_KEY]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_MEDIA],
                profile_p->melody,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_MEDIA]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_FMR],
                profile_p->sound,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_FMR]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_MIC],
                profile_p->mic,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_MIC]));
            kal_mem_set(
                data_p->volume_gain[mode][AUD_VOLUME_SID],
                profile_p->sidetone,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_SID]));
    #ifdef __16_LEVEL_AUDIO_VOLUME__
            /* set 16-level audio volume settings */
            data_p->max_melody_volume_gain[mode] = profile_p->max_melody_volume_gain;
            data_p->melody_volume_gain_step[mode] = profile_p->melody_volume_gain_step;
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
            aud_set_aud_path_volume(aud_context_p->audio_mode);
            write_to_nvram = KAL_TRUE;
        }
#if defined(TV_OUT_SUPPORT)
        else if(mode == VOL_TV_OUT)
        {
    #ifdef __16_LEVEL_AUDIO_VOLUME__
            /* set 16-level audio volume settings */
            data_p->max_melody_volume_gain[mode] = profile_p->max_melody_volume_gain;
            data_p->melody_volume_gain_step[mode] = profile_p->melody_volume_gain_step;
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
            kal_mem_cpy(
                data_p->tv_out_volume_gain,
                profile_p->tv_out_volume_gain,
                sizeof(data_p->tv_out_volume_gain));

             write_to_nvram = KAL_TRUE;
        }
#endif /* TV_OUT_SUPPORT */

        if (write_to_nvram && (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH))
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;
            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
                &(aud_context_p->acoustic_data),
                sizeof(custom_acoustic_struct));
        }
        else
        {
            aud_send_set_audio_profile_cnf(MED_RES_FAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_param_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_param_req(audio_param_struct *param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_cpy(param_p, &aud_context_p->audio_param, sizeof(audio_param_struct));
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_get_audio_param_req_struct *req_p;
    l4aud_get_audio_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_PARAM_REQ_HDLR);

    req_p = (l4aud_get_audio_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (l4aud_get_audio_param_cnf_struct*)
        construct_local_para(sizeof(l4aud_get_audio_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    kal_mem_cpy(&cnf_p->audio_param, &aud_context_p->audio_param, sizeof(audio_param_struct));

    cnf_p->result = KAL_TRUE;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_GET_AUDIO_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint8 param_data[NVRAM_EF_AUDIO_PARAM_SIZE];
    kal_uint8 *data_p;
    l4aud_set_audio_param_req_struct *req_p = NULL;
    audio_param_struct *param_p;
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_SET_AUDIO_PARAM_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (l4aud_set_audio_param_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p)
    {
        /* copy to context */
        aud_context_p->audio_param.selected_FIR_output_index = req_p->audio_param.selected_FIR_output_index;
        kal_mem_cpy(
            aud_context_p->audio_param.speech_common_para,
            req_p->audio_param.speech_common_para,
            (sizeof(kal_uint16) * 12));
        kal_mem_cpy(
            aud_context_p->audio_param.speech_mode_para,
            req_p->audio_param.speech_mode_para,
            (sizeof(kal_uint16) * 64));
        aud_context_p->audio_param.max_swing = req_p->audio_param.max_swing;

        L1SP_LoadCommonSpeechPara(aud_context_p->audio_param.speech_common_para);
        /* set audio path and volume */
        aud_set_aud_path_volume(aud_context_p->audio_mode);

        /* set max swing for sw synthesizer */
        aud_melody_set_max_swing(aud_context_p->audio_param.max_swing);

        /* write to NVRAM */
        param_p = &req_p->audio_param;
        data_p = param_data;
        for(i = 0; i < 6; i++)
        {
            kal_mem_cpy(data_p, &aud_context_p->audio_param.speech_input_FIR_coeffs[i][0], (sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM));
            data_p += (sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM);
        }
        for(i = 0; i < 6; i++)
        {
            kal_mem_cpy(data_p, &aud_context_p->audio_param.speech_output_FIR_coeffs[i][0], (sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM));
            data_p += (sizeof(kal_uint16) * SPEECH_FIR_COEFF_NUM);
        }
        kal_mem_cpy(data_p, &(aud_context_p->audio_param.selected_FIR_output_index), (sizeof(kal_uint16) * 1));
        data_p += (sizeof(kal_uint16) * 1);
        kal_mem_cpy(data_p, aud_context_p->audio_param.speech_common_para, (sizeof(kal_uint16) * 12));
        data_p += (sizeof(kal_uint16) * 12);
        kal_mem_cpy(data_p, aud_context_p->audio_param.speech_mode_para, (sizeof(kal_uint16) * 64));
        data_p += (sizeof(kal_uint16) * 64);
        kal_mem_cpy(data_p, &(aud_context_p->audio_param.max_swing), (sizeof(kal_uint16) * 1));
        data_p += (sizeof(kal_uint16) * 1);
        kal_mem_cpy(data_p, aud_context_p->audio_param.Melody_FIR_Coeff_Tbl, (sizeof(kal_int16) * MELODY_FIR_COEFF_NUM));
        data_p += sizeof(kal_int16) * MELODY_FIR_COEFF_NUM;

    #ifdef AUDIO_COMPENSATION_ENABLE
        for(i = 0; i < 2; i++)
        {
            kal_mem_cpy(data_p, &aud_context_p->audio_param.audio_compensation_coeff[i][0], (sizeof(kal_uint16) * AUDIO_COMP_COEFF_NUM));
            data_p += (sizeof(kal_uint16) * AUDIO_COMP_COEFF_NUM);
        }
    #else /* AUDIO_COMPENSATION_ENABLE */
        kal_mem_set(data_p, 0, 2*(sizeof(kal_uint16) * AUDIO_COMP_COEFF_NUM));
    #endif /* AUDIO_COMPENSATION_ENABLE */

        if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_AUDIO_PARAM_LID, param_data, sizeof(param_data));
        }
        else
        {
            aud_send_set_audio_param_cnf(MED_RES_FAIL);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_get_volume_gain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  type        [IN]        
 *  level       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(TV_OUT_SUPPORT)
    if (type == AUD_VOLUME_TVO)
    {
        if (level >= MAX_VOL_LEVEL)
        {
            return 0;
        }
        else
        {
            return aud_context_p->acoustic_data.tv_out_volume_gain[level];
        }
    }
#endif /* TV_OUT_SUPPORT */

    if ((mode >= MAX_VOL_CATE) || (type >= MAX_VOL_TYPE) || (level >= MAX_VOL_LEVEL))
    {
        return 0;
    }

    return aud_context_p->acoustic_data.volume_gain[mode][type][level];
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_volume_level(kal_uint8 mode, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mode >= MAX_VOL_CATE) || (type >= MAX_VOL_TYPE))
    {
        return 0;
    }
    return aud_context_p->acoustic_data.volume[mode][type];
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_melody_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_melody_volume(kal_uint8 mode, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 analog_gain;
    kal_int8 digital_gain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(level & 0x80))
    {
        digital_gain = 0;

    #if defined(TV_OUT_SUPPORT)
        if (mode == VOL_TV_OUT)
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_TVO, level);
        }
        else
    #endif /* TV_OUT_SUPPORT */
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_MEDIA, level);
        }
        
        aud_melody_set_output_volume(analog_gain, digital_gain); // Adam add
    }
    else
    {
    #ifdef __MED_BT_A2DP_MOD__
    #if defined(__BTMTK__)
        if (aud_bt_a2dp_is_mute_phone())
        {
            return;
        }
    #endif
    #endif /* __MED_BT_A2DP_MOD__ */ 
    #ifdef __16_LEVEL_AUDIO_VOLUME__
        level &= 0x0F;
        Media_SetLevelVolume( aud_context_p->acoustic_data.max_melody_volume_gain[mode],
            aud_context_p->acoustic_data.melody_volume_gain_step[mode],
            15 - level); 
    #else
        ASSERT(0);
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_is_set_melody_path_volume_by_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_is_set_melody_path_volume_by_bt(kal_uint8 check_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_BT_A2DP_MOD__
    if(check_mode == AUD_MEDIA_PATH_BT_A2DP || check_mode == AUD_MEDIA_PATH_BT_BOTH)
    {
    #if defined(__BTMTK__)
        if (aud_bt_a2dp_is_mute_phone())
    #endif
        {
            return KAL_TRUE;
        }
    }
#endif

#if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_AUDIO_VIA_SCO__)
    if(check_mode == AUD_MEDIA_PATH_BT_HFP || check_mode == AUD_MEDIA_PATH_BT_BOTH)
    {
        if(aud_bt_hfp_is_audio_path_on())
        {
            return KAL_TRUE;
        }
    }
#endif

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_melody_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_melody_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = 0;    
    kal_uint8 gain_audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_AUDIO_SET_MELODY_PATH_VOLUME);

    switch (audio_mode)
    {
        /*------------------ Normal Mode & Loud Speaker Mode ---------------------*/
        case AUD_MODE_NORMAL:
        case AUD_MODE_LOUDSPK:
            /* Set media path */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER_BOTH;
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER2;
                    }
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    audio_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                aud_melody_set_output_device(custom_cfg_hw_aud_output_path(audio_path));                
            }
            
            /* Set media volume, use playing melody volume level */
        #if defined(TV_OUT_SUPPORT)
            if (audio_tv_cable_in &&   /* TV out is on, and audio output to TV only */
                !audio_tv_loud_speaker &&
                aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_TV_OUT;
            }
            else
        #endif /* TV_OUT_SUPPORT */
            {
                if (audio_mode == AUD_MODE_NORMAL)
                {
                    gain_audio_mode = VOL_NORMAL;
                }
                else /* AUD_MODE_LOUDSPK */
                {
                    gain_audio_mode = VOL_HANDFREE;
                }
            }
            aud_set_melody_volume(gain_audio_mode, current_playing_melody_volume_level);

            break;
           
        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:
            /* Set media path */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_A2DP))
            {
                aud_melody_set_output_device(custom_cfg_hw_aud_output_path(aud_context_p->melody_output_device));
            }

            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
            if (aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HEADSET;
            }

            /* set media volume, use playing melody volume level */
            aud_set_melody_volume(gain_audio_mode, current_playing_melody_volume_level);

            break;

        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_fmrdo_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_fmrdo_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_path = 0;    
    kal_uint8 volume;    
    kal_uint8 aud_type;
    kal_uint8 gain_audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_AUDIO_SET_FMRDO_PATH_VOLUME);

    switch (audio_mode)
    {
        /*------------------ Normal Mode & Loud Speaker Mode ---------------------*/
        case AUD_MODE_NORMAL:
        case AUD_MODE_LOUDSPK:

            /* Set FM Radio path */
        #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
            if(!aud_bt_hfp_is_audio_path_on())
        #endif
            {
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER_BOTH;
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        audio_path = AUDIO_DEVICE_SPEAKER2;
                    }            
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    audio_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                aud_fmr_set_output_device(custom_cfg_hw_aud_output_path(audio_path));
            }

            /* Set FM radio volume */
        #if defined(TV_OUT_SUPPORT)
            if (audio_tv_cable_in &&   /* TV out is on, and audio output to TV only */
                !audio_tv_loud_speaker &&
                aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_type = AUD_VOLUME_TVO;
            }
            else
        #endif /* TV_OUT_SUPPORT */
            {
                aud_type = AUD_VOLUME_FMR;
            }

            if(audio_mode == AUD_MODE_NORMAL)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HANDFREE;
            }
            
            volume = aud_get_volume_gain(gain_audio_mode, aud_type, current_playing_fmradio_volume_level);
            aud_fmr_set_volume(volume);

            break;
           
        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:
            aud_fmr_set_output_device(custom_cfg_hw_aud_output_path(aud_context_p->melody_output_device));

            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
            if (aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HEADSET;
            }

            /* set fm radio volume, use playing fm radio volume level */
            volume = aud_get_volume_gain(gain_audio_mode, AUD_VOLUME_FMR, current_playing_fmradio_volume_level);
            aud_fmr_set_volume(volume);

            break;

        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_aud_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_aud_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_param_struct *param_p;
    kal_uint8 volume;

    /* To slove mute flag cleared by speech off */
    kal_bool mute;
    kal_uint8 speech_mode;
    kal_uint8 speech_volume_level;

#ifdef __MED_CTM_MOD__
    kal_bool tty_on;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_p = &aud_context_p->audio_param;

    /* for all audio mode */
    Media_SetMelodyFilter(MELODY_FIR_COEFF_NUM, param_p->Melody_FIR_Coeff_Tbl);

#ifdef __MED_BT_HFP_MOD__
    if (aud_bt_hfp_is_audio_path_on())
    {
    #ifdef __MED_BT_FM_VIA_SCO__
        if(aud_fmr_is_power_on())
        {
            speech_mode = SPH_MODE_FM_VIA_BT_CORDLESS;    
        }
        else
    #endif /* __MED_BT_FM_VIA_SCO__ */   
        {
            speech_mode = SPH_MODE_BT_EARPHONE;
        }
    }
    else
#endif /* __MED_BT_HFP_MOD__ */ 
    {
        speech_mode = audio_mode;
    }
    speech_volume_level = aud_get_volume_level(audio_mode, AUD_VOLUME_SPH);

#ifdef __MED_CTM_MOD__
    tty_on = aud_ctm_set_speech_vol_and_path(audio_mode);
#endif 

    /* Set output path and volume for melody and FM radio */
    aud_audio_set_melody_path_volume(audio_mode);
    aud_audio_set_fmrdo_path_volume(audio_mode);

    /* Set output path and volume for others */
    switch (audio_mode)
    {
        /*----------------------- Normal Mode -------------------------*/
        case AUD_MODE_NORMAL:
        {
            /* Set output device */
        #ifndef __MED_CTM_MOD__
        #ifdef __MED_BT_HFP_MOD__
            if (!aud_bt_hfp_is_audio_path_on())
        #endif        
            {
               aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER));
            }
        #endif /* #ifndef __MED_CTM_MOD__ */

        #ifdef __MED_BT_HFP_MOD__
            if (!aud_bt_hfp_is_audio_path_on())
        #endif
            {
                aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER));
                aud_tone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER));
            }

        #ifdef __MED_SND_MOD__
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        aud_snd_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH));
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        aud_snd_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));
                    }            
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    aud_snd_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));
                }
        #endif /* __MED_SND_MOD__ */

            /* For FM record, not use default input device during record phase, so don't apply input path right away */
            if ((AUD_IN_STATE(AUD_MEDIA_RECORD) || AUD_IN_STATE(AUD_MEDIA_RECORD_PAUSED))
                && !aud_context_p->use_default_input)
            {
                aud_mic_set_device_no_apply(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC1));
            }
            else
            {
            #ifndef __MED_CTM_MOD__
                aud_mic_set_device(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC1));
            #endif 
            }

        #ifndef __MED_CTM_MOD__
            /* set mic volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_MIC, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_MIC));
            aud_mic_set_volume(volume, volume);
        #endif /* __MED_CTM_MOD__ */ 
            /* set speech volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_SPH, speech_volume_level);
        #ifndef __MED_CTM_MOD__
            aud_speech_set_output_volume(volume, 0);
        #endif 
            L1SP_SetSpeechVolumeLevel(speech_volume_level);
            /* set general tone volume, use keypad tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_CTN, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_KEY));
            }
            aud_tone_set_output_volume(volume, 0);
            /* set key tone volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_KEY, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_KEY));
            aud_keytone_set_output_volume(volume, 0);
            /* set loopback volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_SID, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_SID));
            aud_side_tone_set_volume(volume, 0);

        #ifndef __MED_CTM_MOD__
            /* Set speech FIR coefficient */
            aud_speech_set_fir_index_by_mode(audio_mode);
        #endif /* __MED_CTM_MOD__ */ 
            if( speech_mode == AUD_MODE_NORMAL )
            {
                L1SP_SetSpeechMode(speech_mode, aud_context_p->audio_param.speech_mode_para[speech_mode]);
            }
            break;
        }

        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:

            /* Set output device */
        #ifndef __MED_CTM_MOD__
        #ifdef __MED_BT_HFP_MOD__
            if (!aud_bt_hfp_is_audio_path_on())
        #endif        
            {
               aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));
            }
        #endif /* #ifndef __MED_CTM_MOD__ */

            aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));
            aud_tone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));

    #ifdef __MED_SND_MOD__
            aud_snd_set_output_device(custom_cfg_hw_aud_output_path(aud_context_p->melody_output_device));
    #endif 

            /* For FM record, not use default input device during record phase, so don't apply input path right away */
            if ((AUD_IN_STATE(AUD_MEDIA_RECORD) || AUD_IN_STATE(AUD_MEDIA_RECORD_PAUSED))
                && !aud_context_p->use_default_input)
            {
                aud_mic_set_device_no_apply(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC2));
            }
            else
            {
            #ifndef __MED_CTM_MOD__
                aud_mic_set_device(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC2));
            #endif 
            }

        #ifndef __MED_CTM_MOD__
            /* set mic volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_MIC, aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_MIC));
            aud_mic_set_volume(volume, volume);
        #endif /* __MED_CTM_MOD__ */ 
            /* set speech volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SPH, speech_volume_level);
        #ifndef __MED_CTM_MOD__
            aud_speech_set_output_volume(volume, 0);
        #endif 
            L1SP_SetSpeechVolumeLevel(speech_volume_level);
            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(
                            VOL_HEADSET,
                            AUD_VOLUME_CTN,
                            aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_KEY));
            }
            aud_tone_set_output_volume(volume, 0);
            /* set key tone volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_KEY, aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_KEY));
            aud_keytone_set_output_volume(volume, 0);
            /* set loopback volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SID, aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_SID));
            aud_side_tone_set_volume(volume, 0);

        #ifndef __MED_CTM_MOD__
            /* Set speech FIR coefficient */
            aud_speech_set_fir_index_by_mode(audio_mode);
        #endif /* __MED_CTM_MOD__ */ 
            if( speech_mode == AUD_MODE_HEADSET )
            {
                L1SP_SetSpeechMode(speech_mode, aud_context_p->audio_param.speech_mode_para[speech_mode]);
            }
            break;

        /*------------------------ Loud Speaker --------------------------------*/
        case AUD_MODE_LOUDSPK:

            /* To slove mute flag cleared by speech off */
        #ifdef __MED_CTM_MOD__
            if (!tty_on)
        #endif 
            {
                mute = L1SP_IsMicrophoneMuted();
                L1SP_Speech_Off();
                kal_sleep_task(20);
                L1SP_MuteMicrophone(mute);
            }
            
            /* Set output device */
        #ifndef __MED_CTM_MOD__
        #ifdef __MED_BT_HFP_MOD__
            if (!aud_bt_hfp_is_audio_path_on())
        #endif
            {
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)
                {
                    /* Output to TV and Phone in H-Free Mode */
                    aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH));
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));
                }
            }
        #endif /* #ifndef __MED_CTM_MOD__ */

        #ifdef __MED_BT_HFP_MOD__
            if (!aud_bt_hfp_is_audio_path_on())
        #endif
            {
                aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));
                aud_tone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));
            }
            
        #ifdef __MED_SND_MOD__
            #if defined(TV_OUT_SUPPORT)
                if (audio_tv_cable_in)  /* Set output path to earphone to let it play through TV only. */
                {
                    if(audio_tv_loud_speaker)  /* Set output path to both TV out and mobile device */
                    {
                        aud_snd_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH));
                    }
                    else  /* Set output path to earphone to let it play through TV only. */
                    {
                        aud_snd_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));
                    }            
                }
                else
            #endif /* TV_OUT_SUPPORT */
                {
                    aud_snd_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));
                }        
        #endif /* __MED_SND_MOD__ */

            /* For FM record, not use default input device during record phase, so don't apply input path right away */
            if ((AUD_IN_STATE(AUD_MEDIA_RECORD) || AUD_IN_STATE(AUD_MEDIA_RECORD_PAUSED))
                && !aud_context_p->use_default_input)
            {
                aud_mic_set_device_no_apply(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC1));
            }
            else
            {
            #ifndef __MED_CTM_MOD__
                aud_mic_set_device(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC1));
            #endif 
            }

        #ifndef __MED_CTM_MOD__
            /* set mic volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_MIC, aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_MIC));
            aud_mic_set_volume(volume, volume);
        #endif /* __MED_CTM_MOD__ */ 
            /* set speech volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_SPH, speech_volume_level);
        #ifndef __MED_CTM_MOD__
            aud_speech_set_output_volume(volume, 0);
        #endif 
            L1SP_SetSpeechVolumeLevel(speech_volume_level);
            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(
                            VOL_HANDFREE,
                            AUD_VOLUME_CTN,
                            aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_KEY));
            }
            aud_tone_set_output_volume(volume, 0);
            /* set key tone volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_KEY, aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_KEY));
            aud_keytone_set_output_volume(volume, 0);
            /* set volume when play */
            /* set loopback volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_SID, aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_SID));
            aud_side_tone_set_volume(volume, 0);

        #ifndef __MED_CTM_MOD__
            /* Set speech FIR coefficient */
            aud_speech_set_fir_index_by_mode(audio_mode);
        #endif /* __MED_CTM_MOD__ */ 
            if( speech_mode == AUD_MODE_LOUDSPK )
            {
                L1SP_SetSpeechMode(speech_mode, aud_context_p->audio_param.speech_mode_para[speech_mode]);
            }
            /* If the speech shall be turned on, turn it on */
        #ifdef __MED_CTM_MOD__
            if (!tty_on)
        #endif 
            {
                if (aud_context_p->speech_on)
                {
                    L1SP_Speech_On(aud_context_p->rat_mode);
                }
            }
            break;

    }
}


#if defined(TV_OUT_SUPPORT)
/*****************************************************************************
 * FUNCTION
 *  aud_set_tv_out_aud_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tv_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_tv_out_aud_path(kal_uint8 tv_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 volume;
    kal_uint8 gain_audio_mode;
    kal_uint8 output_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AUD_FUNC_ENTRY(AUD_SET_TV_OUT_AUD_PATH);
    AUD_VALUE_TRACE(tv_on, aud_context_p->audio_mode, audio_tv_cable_in);

    if(audio_tv_cable_in == tv_on)
    {
        return;
    }

    /* No need to change in headset mode when TV out enable/disable */
    if (aud_context_p->audio_mode == AUD_MODE_NORMAL || aud_context_p->audio_mode == AUD_MODE_LOUDSPK)
    {
        /* TV cable in*/
        if (tv_on)
        {
            /* Get hardware audio output path setting parameter. */
            if(audio_tv_loud_speaker ||
               aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH);
            }
            else /* Set output path to earphone to avoid hear sound from handset */
            {
                output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2);
            }

            /* Melody */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_melody_set_output_device(output_path);
            }

            /* FM Radio */
        #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
            if(!aud_bt_hfp_is_audio_path_on())            
        #endif
            {
                aud_fmr_set_output_device(output_path);
            }

            /* Background Sound Effect */
        #ifdef __MED_SND_MOD__
            aud_snd_set_output_device(output_path);
        #endif

            /* Set volume by using TV out gain value */
            /* Melody */
            if(audio_tv_loud_speaker ||
               aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                aud_set_melody_volume(aud_context_p->audio_mode, current_playing_melody_volume_level);
            }
            else
            {
                aud_set_melody_volume(VOL_TV_OUT, current_playing_melody_volume_level);
            }            

            /* FM Radio */
            if(audio_tv_loud_speaker ||
               aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_FMR, current_playing_fmradio_volume_level);
            }
            else
            {
                volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_TVO, current_playing_fmradio_volume_level);
            }

            aud_fmr_set_volume(volume);
        }
        /* TV cable out*/
        else
        {
            /* Set output path back to load speaker for melody and FM radio */
            output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER);

            /* Melody */
            if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
            {
                aud_melody_set_output_device(output_path);
            }

            /* FM Radio */
        #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
            if(!aud_bt_hfp_is_audio_path_on())
        #endif
            {
                aud_fmr_set_output_device(output_path);
            }

            /* Background Sound Effect */
        #ifdef __MED_SND_MOD__
            aud_snd_set_output_device(output_path);
        #endif

            /* Set volume by using TV out gain value */
            /* Melody */
            if (aud_context_p->audio_mode == AUD_MODE_NORMAL)
            {
                gain_audio_mode = VOL_NORMAL;
            }
            else
            {
                gain_audio_mode = VOL_HANDFREE;
            }
            aud_set_melody_volume(gain_audio_mode, current_playing_melody_volume_level);

            /* FM Radio */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_FMR, current_playing_fmradio_volume_level);
            aud_fmr_set_volume(volume);
        }
    }

    /* Change TV out status for audio path */
    if (tv_on)
    {
        audio_tv_cable_in = KAL_TRUE;
    }
    else
    {
        audio_tv_cable_in = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_tv_out_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable_loud_spk       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_tv_out_param(kal_uint8 enable_loud_spk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool change_path = KAL_FALSE;
    kal_uint8 output_path = 0;
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    AUD_FUNC_ENTRY(AUD_SET_TV_OUT_PARAM);
    AUD_VALUE_TRACE(enable_loud_spk, -1, audio_tv_loud_speaker);

    /* Check if we need to change audio path when change tv-out audio setting */
    if(enable_loud_spk != audio_tv_loud_speaker)
    {
        change_path = KAL_TRUE;
    }

    if(enable_loud_spk)
    {
        audio_tv_loud_speaker = KAL_TRUE;
    }
    else
    {
        audio_tv_loud_speaker = KAL_FALSE;
    }

    /* Change audio path right away if TV cable in */
    if(change_path &&
       audio_tv_cable_in &&
       (aud_context_p->audio_mode == AUD_MODE_NORMAL || aud_context_p->audio_mode == AUD_MODE_LOUDSPK))
    {
        /* Get hardware audio output path setting parameter. */
        if(audio_tv_loud_speaker)
        {
            output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER_BOTH);
        }
        else /* Set output path to earphone to avoid hear sound from handset */
        {
            output_path = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2);
        }
    
        /* Melody */
        if (!aud_is_set_melody_path_volume_by_bt(AUD_MEDIA_PATH_BT_BOTH))
        {
            aud_melody_set_output_device(output_path);
        }

        /* FM Radio */
    #if defined(__MED_BT_HFP_MOD__) && defined(__MED_BT_FM_VIA_SCO__)
        if(!aud_bt_hfp_is_audio_path_on())
    #endif
        {
            aud_fmr_set_output_device(output_path);
        }

        /* Background Sound Effect */
    #ifdef __MED_SND_MOD__
        aud_snd_set_output_device(output_path);
    #endif

        /* Set volume by using TV out gain value */
        /* Melody */
        if(audio_tv_loud_speaker ||
           aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            aud_set_melody_volume(VOL_NORMAL, current_playing_melody_volume_level);
        }
        else
        {
            aud_set_melody_volume(VOL_TV_OUT, current_playing_melody_volume_level);
        }

        /* FM Radio */
        if(audio_tv_loud_speaker ||
           aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_FMR, current_playing_fmradio_volume_level);
        }
        else
        {
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_TVO, current_playing_fmradio_volume_level);
        }
        aud_fmr_set_volume(volume);
    }
}
#endif /* TV_OUT_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_device_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_device_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    void *cnf_p = NULL;
#endif /* DUMMY_CNF */ 

    l4aud_audio_set_device_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_set_device_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->audio_type)
    {
        case AUD_TYPE_SPEECH:
            aud_speech_set_output_device(req_p->device);
            break;
        case AUD_TYPE_VM:
        case AUD_TYPE_VR:
            break;
        case AUD_TYPE_TONE:
            aud_tone_set_output_device(req_p->device);
            break;
        case AUD_TYPE_KEYTONE:
            aud_keytone_set_output_device(req_p->device);
            break;
        case AUD_TYPE_MELODY:
            aud_melody_set_output_device(req_p->device);
            break;
        case AUD_TYPE_MIC:
            aud_mic_set_device(req_p->device);
            break;
        case AUD_TYPE_FMR:
            aud_fmr_set_output_device(req_p->device);
            break;
    #ifdef __MED_SND_MOD__
        case AUD_TYPE_BGSND:
            aud_snd_set_output_device(req_p->device);
            break;
    #endif /* __MED_SND_MOD__ */ 
        default:
            break;

    }

#ifdef DUMMY_CNF
    cnf_p = (l4aud_audio_set_device_cnf_struct*)
        construct_local_para(sizeof(l4aud_audio_set_device_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_SET_DEVICE_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_get_volume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_get_volume_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_get_volume_req_struct *req_p;
    l4aud_get_volume_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_get_volume_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (l4aud_get_volume_cnf_struct*) construct_local_para(sizeof(l4aud_get_volume_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->volume_type = req_p->volume_type;
    cnf_p->result = KAL_TRUE;
    cnf_p->volume = aud_context_p->acoustic_data.volume[aud_context_p->audio_mode][req_p->volume_type];

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_AUDIO_GET_VOLUME_CNF, cnf_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DUMMY_CNF
    l4aud_audio_set_volume_cnf_struct *cnf_p = NULL;
#endif 
    kal_uint8 volume1, volume2, volume;

    l4aud_audio_set_volume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_set_volume_req_struct*) ilm_ptr->local_para_ptr;

    volume1 = req_p->volume;
    volume2 = req_p->aux_volume;
    aud_context_p->acoustic_data.volume[aud_context_p->audio_mode][req_p->audio_type] = req_p->volume;

    /* get volume gain from table */
    if (!(req_p->volume & 0x80))
    {
        volume1 = volume2 =
            aud_context_p->acoustic_data.volume_gain[aud_context_p->audio_mode][req_p->audio_type][req_p->volume];
    }
    else
    {
        ASSERT(req_p->audio_type == AUD_VOLUME_MEDIA);
    }

    /* call the corresponding handler */
    switch (req_p->audio_type)
    {
        case AUD_VOLUME_SPH:
            if (aud_context_p->speech_on)
            {
                aud_tone_set_output_volume(volume1, 0);
            }
            aud_speech_set_output_volume(volume1, 0);
            L1SP_SetSpeechVolumeLevel(req_p->volume);
            break;

        case AUD_VOLUME_KEY:
            aud_keytone_set_output_volume(volume1, 0);
            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_CTN, req_p->volume);
                aud_tone_set_output_volume(volume, 0);
            }
            break;
        case AUD_VOLUME_FMR:
            /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
            if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
            {
                volume1 = volume2 = aud_get_volume_gain(AUD_MODE_NORMAL, AUD_VOLUME_FMR, req_p->volume);
            }
        #if defined(TV_OUT_SUPPORT)
            else if (audio_tv_cable_in  &&  /* TV out is on, and audio output to TV only */
                    !audio_tv_loud_speaker &&
                    aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
            {
                volume1 = volume2 = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_TVO, req_p->volume);
            }
        #endif /* TV_OUT_SUPPORT */

            aud_fmr_set_volume(volume1);
            current_playing_fmradio_volume_level = req_p->volume;
            break;
        case AUD_VOLUME_MEDIA:
            if (req_p->apply)
        #ifdef __MED_VID_MOD__
                if (!(VID_IN_STATE(VID_PLAY)
                      && (VID_AUD_IN_STATE(VID_AUD_PLAY_DUMMY) || VID_AUD_IN_STATE(VID_AUD_PLAY_HIGH_SPEED))))
        #endif /* __MED_VID_MOD__ */ 
                {
                    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
                    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                    {
                        aud_set_melody_volume(VOL_NORMAL, req_p->volume);
                    }
                #if defined(TV_OUT_SUPPORT)
                    /* TV out is on, and audio output to TV only */                
                    else if (audio_tv_cable_in  &&
                             !audio_tv_loud_speaker &&
                             aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
                    {
                        aud_set_melody_volume(VOL_TV_OUT, req_p->volume);
                    }
                #endif /* TV_OUT_SUPPORT */
                    else
                    {
                        aud_set_melody_volume(aud_context_p->audio_mode, req_p->volume);
                    }
                    current_playing_melody_volume_level = req_p->volume;
                }
            /* disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;
        case AUD_VOLUME_MIC:
            aud_mic_set_volume(volume1, volume1);
            break;
        case AUD_VOLUME_SID:
            aud_side_tone_set_volume(volume1, 0);
            break;
        default:
            break;

    }

#ifdef DUMMY_CNF
    cnf_p = (l4aud_audio_set_volume_cnf_struct*)
        construct_local_para(sizeof(l4aud_audio_set_volume_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_AUDIO_SET_VOLUME_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */ 

    /* Store default volumn level to NVRAM for MODEM project */
#ifdef MED_MODEM
    if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
    {
        aud_context_p->src_mod = ilm_ptr->src_mod_id;
        aud_send_msg_to_nvram(
            MSG_ID_NVRAM_WRITE_REQ,
            NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
            &(aud_context_p->acoustic_data),
            sizeof(custom_acoustic_struct));
    }
#endif /* MED_MODEM */
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_get_gain_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_get_gain_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_get_gain_req_struct *req_p;
    l4aud_get_gain_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_get_gain_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (l4aud_get_gain_cnf_struct*) construct_local_para(sizeof(l4aud_get_gain_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->result = KAL_TRUE;
    cnf_p->volume_gain =
        aud_context_p->acoustic_data.volume_gain[aud_context_p->audio_mode][req_p->volume_type][req_p->volume_level];

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_AUDIO_GET_GAIN_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_gain_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_gain_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DUMMY_CNF
    l4aud_audio_set_gain_cnf_struct *cnf_p = NULL;
#endif 

    l4aud_audio_set_gain_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_set_gain_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->acoustic_data.volume_gain[aud_context_p->audio_mode][req_p->audio_type][req_p->volume_level] =
        req_p->gain;

#ifdef DUMMY_CNF
    cnf_p = (l4aud_audio_set_gain_cnf_struct*) construct_local_para(sizeof(l4aud_audio_set_gain_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_AUDIO_SET_GAIN_CNF, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_mute_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    void *cnf_p = NULL;
#endif /* DUMMY_CNF */ 

    l4aud_audio_mute_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_mute_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->device)
    {
        case AUDIO_DEVICE_MICROPHONE:
            /* call L1AUD to set microphone mute */
            aud_mic_mute(req_p->mute);
            break;
        default:
            break;
    }

#ifdef DUMMY_CNF
    cnf_p = (l4aud_audio_mute_cnf_struct*) construct_local_para(sizeof(l4aud_audio_mute_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_MUTE_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_mute_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_mute_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_mute_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->audio_mute = req_p->mute;
    if (req_p->mute)
    {
        switch (req_p->vol_type)
        {
            case AUD_VOLUME_CTN:
                aud_tone_set_output_volume(0, 0);
                break;
            case AUD_VOLUME_KEY:
                aud_keytone_set_output_volume(0, 0);
                break;
            case AUD_VOLUME_MIC:
                aud_mic_mute(req_p->mute);
                break;
            case AUD_VOLUME_SPH:
                aud_speech_set_output_volume(0, 0);
                break;
            case AUD_VOLUME_MEDIA:
                aud_melody_set_output_volume(0, 0);
                break;
            case AUD_VOLUME_FMR:
                aud_fmr_set_volume(0);
                break;
            case AUD_VOLUME_SID:
                break;
            default:
                break;
        }
    }
    else
    {
        kal_uint8 volume;

        volume = aud_get_volume_gain(
                    aud_context_p->audio_mode,
                    req_p->vol_type,
                    aud_get_volume_level(aud_context_p->audio_mode, req_p->vol_type));
        switch (req_p->vol_type)
        {
            case AUD_VOLUME_CTN:
                aud_tone_set_output_volume(volume, 0);
                break;
            case AUD_VOLUME_KEY:
                aud_keytone_set_output_volume(volume, 0);
                break;
            case AUD_VOLUME_MIC:
                aud_mic_mute(req_p->mute);
                break;
            case AUD_VOLUME_SPH:
                aud_speech_set_output_volume(volume, 0);
                break;
            case AUD_VOLUME_MEDIA:
                /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
                if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                    aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    aud_set_melody_volume(VOL_NORMAL, current_playing_melody_volume_level);
                }
            #if defined(TV_OUT_SUPPORT)
                /* TV out is on, and audio output to TV only */
                else if (audio_tv_cable_in &&
                         !audio_tv_loud_speaker &&
                         aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    aud_set_melody_volume(VOL_TV_OUT, current_playing_melody_volume_level);
                }
            #endif
                else
                {
                    aud_set_melody_volume(aud_context_p->audio_mode, current_playing_melody_volume_level);
                }

                break;
            case AUD_VOLUME_FMR:
                /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
                if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
                    aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    volume = aud_get_volume_gain(AUD_MODE_NORMAL, AUD_VOLUME_FMR, current_playing_fmradio_volume_level);
                }
            #if defined(TV_OUT_SUPPORT)
                /* TV out is on, and audio output to TV only */
                else if (audio_tv_cable_in &&
                         !audio_tv_loud_speaker &&
                         aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_TVO, current_playing_fmradio_volume_level);
                }
            #endif /* TV_OUT_SUPPORT */

                aud_fmr_set_volume(volume);
                break;
            case AUD_VOLUME_SID:
                break;
            default:
                break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    l4aud_audio_set_fir_cnf_struct *cnf_p = NULL;

    l4aud_audio_set_fir_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_set_fir_req_struct*) ilm_ptr->local_para_ptr;

    /* call L1AUD to set fir */
    AUD_VALUE_TRACE(req_p->audio_type, req_p->fir_on, -1);

    switch (req_p->audio_type)
    {
        case AUD_TYPE_SPEECH:
            aud_speech_set_fir(req_p->fir_on);
            break;
        default:
            break;
    }

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_SET_FIR_CNF;
    cnf_p = (l4aud_audio_set_fir_cnf_struct*) construct_local_para(sizeof(l4aud_audio_set_fir_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_cfg_audio_out_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id      [IN]        
 *  out_device_path     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_cfg_audio_out_device(kal_uint8 audio_sound_id, kal_uint8 *out_device_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(out_device_path != NULL);

    /* if there is no change, it will use the default value at PS */
    /* specially for connect tone */
    if ((audio_sound_id == TONE_CALL_CONNECT) || (audio_sound_id == TONE_WARNING2) || (audio_sound_id == TONE_ERROR2))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }
    else if (audio_sound_id <= TONE_NEGATIVE_ACK)
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
        }
    }
    else if ((audio_sound_id > TONE_NEGATIVE_ACK) && (audio_sound_id <= MAX_TONE_ID))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                /* if speech on, tone shall output via speaker1 */
                if (aud_context_p->speech_on)
                {
                    *out_device_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                /* if speech on, tone shall output via speaker1 */
                if (aud_context_p->speech_on)
                {
                    *out_device_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
        }
	//su-2008/12/04
	#if defined __VIBRATOR_TONE_SUPPORT__  //zhengming 080103 for vibrator tone
	if(audio_sound_id == TONE_VIBRATOR)
	{
               *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
	}
	#endif
    }
    else if ((audio_sound_id >= MIN_RING_TONE_ID) && (audio_sound_id <= MAX_RING_TONE_ID))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER_BOTH;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }
    else if ((audio_sound_id >= MIN_MIDI_ID) && (audio_sound_id <= MAX_MIDI_ID))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER_BOTH;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }
    else
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_play_by_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_play_by_id_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    l4aud_audio_play_cnf_struct *cnf_p = NULL;
#endif /* DUMMY_CNF */ 
    kal_uint8 audio_id;
    kal_uint8 audio_out_device;

    l4aud_audio_play_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_audio_play_req_struct*) ilm_ptr->local_para_ptr;

    audio_id = req_p->audio_id;

    aud_cfg_audio_out_device(audio_id, &audio_out_device);

    if (audio_id <= TONE_KEY_CLICK)
    {
        aud_keytone_stop();
        aud_keytone_play(audio_id, audio_out_device);
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        if (req_p->play_style == DEVICE_AUDIO_PLAY_INFINITE)
        {
            aud_context_p->tone_playing = KAL_TRUE;
        }
        aud_tone_play(audio_id, audio_out_device);
    }
    else
    {
/* The following message is not use in MODEM project */
#ifndef MED_MODEM
        if (aud_context_p->speech_on)
        {
            return;
        }

    #if defined(__MED_VID_MOD__) || defined (__MED_MJPG_MOD__)
        if (!vid_is_audio_channel_available())
        {
            return;
        }
    #endif /* defined(__MED_VID_MOD__) || defined (__MED_MJPG_MOD__) */ 
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        /* if tone is playing, stop it */
        if (aud_context_p->tone_playing)
        {
            aud_tone_stop();
        }
    #ifdef __MED_MMA_MOD__
        /* close all mma tasks */
        aud_mma_close_all();
    #endif /* __MED_MMA_MOD__ */ 

        if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
              aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
              aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
        {
            aud_stop_unfinished_process();

            aud_context_p->src_mod = ilm_ptr->src_mod_id;
            aud_context_p->identifier = req_p->identifier;

            /* set volume and path if from LMMI */
            if (aud_context_p->src_mod == MOD_MMI)
            {
                SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, req_p->volume);
                aud_context_p->melody_output_device = req_p->output_path;

                aud_get_active_device_path_by_mode(req_p->output_path, aud_melody_set_output_device);
            }
            else
            {
                aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER_BOTH;
            }
            aud_context_p->play_mode = AUD_MEDIA_PLAY_AS_RING;

            aud_melody_play_by_id(audio_id, req_p->play_style, audio_out_device);
        }
#endif /* MED_MODEM */
    }
    /* AUD_SET_EVENT(AUD_EVT_PLAY); */

#ifdef DUMMY_CNF
    cnf_p = (l4aud_audio_play_cnf_struct*) construct_local_para(sizeof(l4aud_audio_play_cnf_struct), TD_CTRL);
    cnf_p->result = MED_RES_OK;

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_PLAY_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_stop_by_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_by_id_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    l4aud_audio_stop_cnf_struct *cnf_p = NULL;
#endif /* DUMMY_CNF */ 

    kal_uint8 audio_id;

    l4aud_audio_stop_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (l4aud_audio_stop_req_struct*) ilm_ptr->local_para_ptr;

    audio_id = req_p->audio_id;

    if (audio_id <= TONE_KEY_CLICK)
    {
        aud_keytone_stop();
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        aud_tone_stop();
    }
    else
    {
/* The following message is not use in MODEM project */
#ifndef MED_MODEM
        if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
              aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
              aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
        {
            aud_stop_unfinished_process();
        }
#endif /* MED_MODEM */
    }
    /* set event to let caller go */
    AUD_SET_EVENT(AUD_EVT_STOP);

#ifdef DUMMY_CNF
    cnf_p = (l4aud_audio_stop_cnf_struct*) construct_local_para(sizeof(l4aud_audio_stop_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_STOP_CNF;

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 

}


/*****************************************************************************
 * FUNCTION
 *  aud_play_by_name_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_play_by_name_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;

    /* kal_uint8   audio_out_device=0; */
    l4aud_audio_play_by_name_cnf_struct *cnf_p = NULL;

    l4aud_audio_play_by_name_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (l4aud_audio_play_by_name_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (l4aud_audio_play_by_name_cnf_struct*)
        construct_local_para(sizeof(l4aud_audio_play_by_name_cnf_struct), TD_CTRL);

    if (aud_context_p->speech_on
#if defined(__MED_VID_MOD__) || defined (__MED_MJPG_MOD__)
        || !vid_is_audio_channel_available()
#endif 
        )
    {
        cnf_p->result = MED_RES_BUSY;
    }
    else
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        /* if tone is playing, stop it */
        if (aud_context_p->tone_playing)
        {
            aud_tone_stop();
        }

    #ifdef __MED_MMA_MOD__
        /* close all mma tasks */
        aud_mma_close_all();
    #endif /* __MED_MMA_MOD__ */ 

        if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
              aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
              aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
        {
            aud_stop_unfinished_process();

            aud_context_p->play_mode = AUD_MEDIA_PLAY_AS_RING;

            aud_context_p->identifier = req_p->identifier;

            /* set volume and path if from LMMI */
            if (aud_context_p->src_mod == MOD_MMI)
            {
                SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, req_p->volume);
                aud_context_p->melody_output_device = req_p->output_path;
                
                aud_get_active_device_path_by_mode(req_p->output_path, aud_melody_set_output_device);
            }
            else
            {
                aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER_BOTH;
            }

            aud_context_p->current_format = med_get_media_type(req_p->file_name);
            switch (aud_context_p->current_format)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_MMF:
                case MED_TYPE_SMF_SND:
                case MED_TYPE_IMELODY:
                    cnf_p->result = aud_melody_play_by_name(req_p->file_name, req_p->play_style, 0);
                    break;
                case MED_TYPE_DAF:
                case MED_TYPE_MUSICAM:
                case MED_TYPE_AMR:
                case MED_TYPE_AMR_WB:
                case MED_TYPE_GSM_EFR:
                case MED_TYPE_PCM_8K:
                case MED_TYPE_PCM_16K:
                case MED_TYPE_DVI_ADPCM:
                case MED_TYPE_WAV:
                case MED_TYPE_WAV_DVI_ADPCM:
                case MED_TYPE_AIFF:
                case MED_TYPE_AU:
                    aud_context_p->source_type = AUD_FILE;
                    aud_context_p->play_style = req_p->play_style;
                    aud_context_p->start_offset = aud_context_p->end_offset = 0;

                    cnf_p->result = aud_media_play_file_stream(req_p->file_name, req_p->play_style, 1, KAL_FALSE, NULL);

                    break;
                default:
                    cnf_p->result = MED_RES_INVALID_FORMAT;
                    break;
            }
        }
        else
        {
            cnf_p->result = MED_RES_BUSY;
        }
    }

    cnf_p->src_id = req_p->src_id;

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_PLAY_BY_NAME_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_stop_by_name_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_by_name_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    l4aud_audio_stop_by_name_cnf_struct *cnf_p = NULL;

    l4aud_audio_stop_by_name_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (l4aud_audio_stop_by_name_req_struct*) ilm_ptr->local_para_ptr;

    if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
          aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
          aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
    {
        aud_stop_unfinished_process();
    }

    /* set event to let caller go */
    AUD_SET_EVENT(AUD_EVT_STOP);

    cnf_msg_id = MSG_ID_L4AUD_AUDIO_STOP_BY_NAME_CNF;

    cnf_p = (l4aud_audio_stop_by_name_cnf_struct*)
        construct_local_para(sizeof(l4aud_audio_stop_by_name_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_play_by_string_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_play_by_string_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_play_by_string_cnf_struct *cnf_p = NULL;
    l4aud_audio_play_by_string_req_struct *req_p;
    kal_uint8 res = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (l4aud_audio_play_by_string_req_struct*) ilm_ptr->local_para_ptr;

    if (aud_context_p->speech_on
#if defined(__MED_VID_MOD__) || defined (__MED_MJPG_MOD__)
        || !vid_is_audio_channel_available()
#endif 
        )
    {
        res = MED_RES_BUSY;
    }
    else
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        /* if tone is playing, stop it */
        if (aud_context_p->tone_playing)
        {
            aud_tone_stop();
        }

    #ifdef __MED_MMA_MOD__
        /* close all mma tasks */
        aud_mma_close_all();
    #endif /* __MED_MMA_MOD__ */ 
        if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
              aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
              aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
        {
            aud_stop_unfinished_process();

            aud_context_p->play_mode = AUD_MEDIA_PLAY_AS_RING;
            aud_context_p->identifier = req_p->identifier;
            aud_context_p->current_format = req_p->format;
            aud_context_p->play_style = req_p->play_style;
            aud_context_p->start_offset = req_p->start_offset;
            aud_context_p->end_offset = req_p->end_offset;

            /* set volume and path if from LMMI */
            if (aud_context_p->src_mod == MOD_MMI)
            {
                SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, req_p->volume);
                aud_context_p->melody_output_device = req_p->output_path;
                
                aud_get_active_device_path_by_mode(req_p->output_path, aud_melody_set_output_device);
            }
            else
            {
                aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER_BOTH;
            }

            res = aud_melody_play_by_string((kal_uint8*) req_p->melody, req_p->play_style, req_p->len, req_p->format);
        }
        else
        {
            res = MED_RES_BUSY;
        }
    }

    aud_set_result((kal_int32) res);
    if (req_p->blocking)
    {
        AUD_SET_EVENT(AUD_EVT_PLAY);
    }

    if (!(aud_context_p->src_mod == MOD_MMI && req_p->blocking))
    {
        cnf_p = (l4aud_audio_play_by_string_cnf_struct*)
            construct_local_para(sizeof(l4aud_audio_play_by_string_cnf_struct), TD_CTRL);

        cnf_p->src_id = req_p->src_id;
        cnf_p->result = res;

        aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_AUDIO_PLAY_BY_STRING_CNF, cnf_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_stop_by_string_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_by_string_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_stop_by_string_cnf_struct *cnf_p = NULL;

    l4aud_audio_stop_by_string_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (l4aud_audio_stop_by_string_req_struct*) ilm_ptr->local_para_ptr;

    if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
          aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
          aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
    {
        aud_stop_unfinished_process();
    }
    aud_context_p->source_type = AUD_UNKNOWN_SOURCE_TYPE;
    aud_context_p->current_format = MED_TYPE_NONE;
    aud_context_p->string_p = NULL;

    /* set event to let caller go */
    AUD_SET_EVENT(AUD_EVT_STOP);

    if (aud_context_p->src_mod != MOD_MMI)
    {
        cnf_p = (l4aud_audio_stop_by_string_cnf_struct*)
            construct_local_para(sizeof(l4aud_audio_stop_by_string_cnf_struct), TD_CTRL);

        cnf_p->src_id = req_p->src_id;
        cnf_p->result = MED_RES_OK;

        aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_L4AUD_AUDIO_STOP_BY_STRING_CNF, cnf_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_block_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_block_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_block_req_struct *req_p;
    kal_int16 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_block_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->access_mod = (module_type) req_p->mod_id;
    aud_context_p->block_level = req_p->level;

    aud_keytone_stop();

    /* if tone is playing, stop it */
    if (aud_context_p->tone_playing)
    {
        aud_tone_stop();
    }

    /* Close all playing, recording action */    
    aud_stop_unfinished_process();

#ifdef __MED_MMA_MOD__
    /* close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */ 
#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
    result = vid_abort_by_client_switching();
#endif 
#ifdef __MED_CAM_MOD__
    cam_abort_to_idle();
#endif 
    if (result == MED_RES_OK)
    {
        AUD_SET_EVENT(AUD_EVT_BLOCK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_headset_mode_output_path_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_headset_mode_output_path_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_headset_mode_output_path_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_aud_set_headset_mode_output_path_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->melody_output_device = msg_p->device;
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET)
    {
        aud_melody_set_output_device(custom_cfg_hw_aud_output_path(msg_p->device));
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_in_proc_call_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_in_proc_call_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_req_struct *msg_p = (media_in_proc_call_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_p->func != NULL);
    msg_p->func(msg_p->func_arg1, msg_p->func_arg2);
}

#ifdef EXT_DAC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  aud_get_melody_volume_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_melody_volume_setting(kal_uint8 mode, kal_uint8 *MaxAnalogGain, kal_uint8 *step)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   *MaxAnalogGain =  aud_context_p->acoustic_data.max_melody_volume_gain[mode];
   *step = aud_context_p->acoustic_data.melody_volume_gain_step[mode];
}
#endif /* EXT_DAC_SUPPORT */

#endif /* MED_NOT_PRESENT */ 

