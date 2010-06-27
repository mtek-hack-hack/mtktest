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
 * aud_speech.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_SPEECH
 * DESCRIPTION
 *    This module defines the speech related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

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
#include "aud_main.h"
#include "med_main.h"
#ifdef __MED_VID_MOD__
#include "vid_main.h"
#endif 

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

kal_bool audio_bluetooth_on = KAL_FALSE;

#ifdef __MED_RTP_MOD__
extern kal_uint8 voip_curr_encoding_or_decoding(void); /* To check if rtp is running */
#endif /*__MED_RTP_MOD__*/

/* TEMP, shall revise */
extern void vcall_open_speech_codec(void);
extern void vcall_close_speech_codec(void);

/*****************************************************************************
 * FUNCTION
 *  aud_speech_init
 * DESCRIPTION
 *  This function is used to init this module.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_speech_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->speech_on = KAL_FALSE;
    aud_context_p->rat_mode = 0;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_SPEECH, device, -1) L1SP_SetOutputDevice(device);

}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SPH, volume1, digital_gain_index);
    L1SP_SetOutputVolume(volume1, digital_gain_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MIC, device, -1);
    aud_context_p->input_device = device;
    L1SP_SetInputSource(device);
}

/* Set input device to media task context only, apply to device later */


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_device_no_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_device_no_apply(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MIC, device, -1);
    aud_context_p->input_device = device;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1     [IN]        
 *  volume2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_volume(kal_uint8 volume1, kal_uint8 volume2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MIC, volume1, volume2);
    L1SP_SetMicrophoneVolume(volume1);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mute        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_mute(kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L1SP_MuteMicrophone(mute);
}


/*****************************************************************************
 * FUNCTION
 *  aud_side_tone_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_side_tone_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SID, volume1, digital_gain_index);
    L1SP_SetSidetoneVolume(volume1);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_input_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_input_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    l4aud_sp_set_input_mode_cnf_struct *cnf_p = NULL;

    l4aud_sp_set_input_mode_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_sp_set_input_mode_req_struct*) ilm_ptr->local_para_ptr;

    /* call L1AUD to set speech mode */
    AUD_VALUE_TRACE(req_p->mode, req_p->mic_volume, req_p->sidetone_volume)
        cnf_msg_id = MSG_ID_L4AUD_SP_SET_INPUT_MODE_CNF;
    cnf_p = (l4aud_sp_set_input_mode_cnf_struct*)
        construct_local_para(sizeof(l4aud_sp_set_input_mode_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;
    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fir_on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir(kal_bool fir_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L1SP_SetFIR(fir_on);

}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_coefficient
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_FIR_index     [IN]    0 ~ 5: GSM/VOIP/Bluetooth  -1: For CTM
 *  output_FIR_index    [IN]    0 ~ 5: GSM/VOIP/Bluetooth  -1: For CTM
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_coefficient(kal_int16 input_FIR_index, kal_int16 output_FIR_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 *input_fir_coeff_p = NULL, *output_fir_coeff_p = NULL;
#ifdef __MED_CTM_MOD__
    kal_int16 baudot_fir_coeff[SPEECH_FIR_COEFF_NUM];
#endif /*__MED_CTM_MOD__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_SPEECH_SET_FIR_COEFF, input_FIR_index, output_FIR_index);

    input_fir_coeff_p = &aud_context_p->audio_param.speech_input_FIR_coeffs[input_FIR_index][0];
    output_fir_coeff_p = &aud_context_p->audio_param.speech_output_FIR_coeffs[output_FIR_index][0];        

#ifdef __MED_CTM_MOD__
    baudot_fir_coeff[0] = 0x7FFF;
    memset(&baudot_fir_coeff[1], 0, (sizeof(kal_uint16)*(SPEECH_FIR_COEFF_NUM-1)));

    if(input_FIR_index < 0)
    {
        input_fir_coeff_p = &baudot_fir_coeff[0];
    }

    if(output_FIR_index < 0)
    {
        output_fir_coeff_p = &baudot_fir_coeff[0];
    }
#endif /*__MED_CTM_MOD__*/


    /* Write Coefficient to L1 Audio */
    L1SP_Write_Audio_Coefficients(input_fir_coeff_p, output_fir_coeff_p);
    aud_speech_set_fir(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_index_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_index_by_mode(kal_uint8 audio_mode)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_param_struct *param_p;

    kal_uint8 speech_input_FIR_index = 0;
    kal_uint8 speech_output_FIR_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_p = &aud_context_p->audio_param;

#ifdef __MED_BT_HFP_MOD__
    if (aud_bt_hfp_is_audio_path_on())
    {
        speech_input_FIR_index = 3;
        speech_output_FIR_index = 3;
    }
    else
#endif /* __MED_BT_HFP_MOD__ */ 
    {
        switch (audio_mode)
        {
            /*----------------------- Normal Mode -------------------------*/
            case AUD_MODE_NORMAL:
            #ifdef __MED_RTP_MOD__
                if(voip_curr_encoding_or_decoding())
                {
                    speech_input_FIR_index = 4;
                    speech_output_FIR_index = 4;
                }
                else
            #endif /*__MED_RTP_MOD__*/
                {
                    speech_input_FIR_index = 0;
                    speech_output_FIR_index = param_p->selected_FIR_output_index;
                }
                break;

            /*----------------------- Headset Mode ------------------------*/
            case AUD_MODE_HEADSET:
                speech_input_FIR_index = 1;
                speech_output_FIR_index = 1;
                break;

            /*------------------------ Loud Speaker -----------------------*/
            case AUD_MODE_LOUDSPK:
            #ifdef __MED_RTP_MOD__
                if(voip_curr_encoding_or_decoding())
                {
                    speech_input_FIR_index = 5;
                    speech_output_FIR_index = 5;
                }
                else
            #endif /*__MED_RTP_MOD__*/
                {
                    speech_input_FIR_index = 2;
                    speech_output_FIR_index = 2;
                }            
                break;

            default:
                return;
                break;
        }
    }

    aud_speech_set_fir_coefficient(speech_input_FIR_index, speech_output_FIR_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_index
 * DESCRIPTION
 *  Use current audio mode to set FIR coefficient
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_index(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_speech_set_fir_index_by_mode(aud_context_p->audio_mode);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void AM_SetLoopBackTest(kal_bool enable);
void aud_speech_set_mode_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef DUMMY_CNF
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    l4aud_sp_set_mode_cnf_struct *cnf_p = NULL;
#endif /* DUMMY_CNF */ 
    l4aud_sp_set_mode_req_struct *req_p;
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (l4aud_sp_set_mode_req_struct*) ilm_ptr->local_para_ptr;

    /* call L1AUD to set speech mode */
    AUD_VALUE_TRACE(req_p->speech_on, -1, -1)
        /* if keytone is playing, stop it */
        aud_keytone_stop();

    /* if tone is playing, stop it */
    /* Remove in case that busy tone is stopped by speech off */
    //if (aud_context_p->tone_playing)
    //aud_tone_stop();

#ifdef __MED_MMA_MOD__
    /* close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */ 

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
    vid_stop_unfinished_task();
#endif 

    /* Don't stop record when 2G/3G speech handover */
    if ((aud_context_p->state != AUD_MEDIA_IDLE) &&
        (aud_context_p->state != AUD_MEDIA_RECORD) &&
        (aud_context_p->state != AUD_MEDIA_RECORD_PAUSED))
    {
        aud_stop_unfinished_process();
    }

    /* set general tone volume */
    if (req_p->speech_on)
        /* use speech volume for tone */
    {
        volume = aud_get_volume_gain(
                    aud_context_p->audio_mode,
                    AUD_VOLUME_SPH,
                    aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_SPH));
    }
    else
        /* reset tone volume level, use key tone volume level */
    {
        volume = aud_get_volume_gain(
                    aud_context_p->audio_mode,
                    AUD_VOLUME_CTN,
                    aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_KEY));
    }
    aud_tone_set_output_volume(volume, 0);

    aud_context_p->rat_mode = req_p->rat_mode;

    if (req_p->speech_on)
    {
        if (req_p->rat_mode == RAT_3G324M_MODE)
        {
        #ifdef __MED_VCALL_MOD__
            vcall_open_speech_codec();
        #endif 
        }
        else
        {
            L1SP_Speech_On(aud_context_p->rat_mode);
        #ifdef VM_LOG
            aud_vm_start_logging();
        #endif
        }
        aud_context_p->speech_on = KAL_TRUE;
    }
    else
    {
        if (req_p->rat_mode == RAT_3G324M_MODE)
        {
        #ifdef __MED_VCALL_MOD__            
            vcall_close_speech_codec();
        #endif
        }
        else
        {
        #ifdef VM_LOG
            aud_vm_stop_logging();
        #endif 
            AM_SetLoopBackTest(KAL_FALSE); 
            L1SP_Speech_Off();
        }
        aud_context_p->speech_on = KAL_FALSE;
    }
#ifdef DUMMY_CNF
    cnf_msg_id = MSG_ID_L4AUD_SP_SET_MODE_CNF;
    cnf_p = (l4aud_sp_set_mode_cnf_struct*) construct_local_para(sizeof(l4aud_sp_set_mode_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
#endif /* DUMMY_CNF */ 
}

#ifdef __MED_POC_MOD__

typedef void (*media_handler) (Media_Handle *handle, Media_Event event);


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_encode_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vocoder             [IN]        
 *  media_handler       [IN]        
 *  frame_threshold     [IN]        
 *  buffer_size         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_encode_start(
            kal_uint8 vocoder,
            void (*media_handler) (void),
            kal_int32 frame_threshold,
            kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer_size <= AUD_RING_BUFFER_LEN);

#ifndef __MTK_TARGET__
    {
        extern kal_int32 poc_encode_start(void);

        result = poc_encode_start();
    }
#else /* __MTK_TARGET__ */ 
    PoC_AMR_SetBuffer(aud_context_p->ring_buf, buffer_size);
    result = PoC_AMR_EncodeStart(vocoder, media_handler, frame_threshold);
#endif /* __MTK_TARGET__ */ 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_encode_get_payload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf             [?]         
 *  max_len         [IN]        
 *  frame_thres     [IN]        
 *  len_p           [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_encode_get_payload(
            kal_uint8 *buf,
            kal_int32 max_len,
            kal_int32 frame_thres,
            kal_int32 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 frames;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    *len_p = 42;
    {
        const kal_uint8 test_rtp_payload[] = 
        {
            0x80, 0xed, 0x03, 0x0a, 0x00, 0x00, 0x49, 0xf4, 0x00, 0x00, 0x00, 0xff, 0x31, 0x32, 0x33, 0x34,
            0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30,
            0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30
        };

        memcpy(buf, test_rtp_payload, sizeof(test_rtp_payload));
    }
#else /* __MTK_TARGET__ */ 
    frames = PoC_AMR_GetFrameCount();
    kal_wap_trace(stack_get_active_module_id(), TRACE_INFO, "PoC GetPayload: Frames remain = %d", frames);
    kal_wap_trace(stack_get_active_module_id(), TRACE_INFO, "PoC GetPayload: Frames got = %d", frame_thres);
    /* *len_p = PoC_AMR_GetPayload( buf, max_len, frames ); */
    *len_p = PoC_AMR_GetPayload(buf, max_len, frame_thres);
#endif /* __MTK_TARGET__ */ 

    return MED_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_encode_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_encode_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    {
        extern kal_int32 poc_encode_stop(void);

        result = poc_encode_stop();
    }
#else /* __MTK_TARGET__ */ 
    result = PoC_AMR_EncodeStop();
#endif /* __MTK_TARGET__ */ 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_decode_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer_size     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_decode_start(kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer_size <= AUD_RING_BUFFER_LEN);

#ifndef __MTK_TARGET__
    result = 0;
#else /* __MTK_TARGET__ */ 
    PoC_AMR_SetBuffer(aud_context_p->ring_buf, buffer_size);
    result = PoC_AMR_DecodeStart();
#endif /* __MTK_TARGET__ */ 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_decode_put_payload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf     [?]         
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_decode_put_payload(kal_uint8 *buf, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    result = 0;
#else 
    result = PoC_AMR_PutPayload(buf, len);
#endif 

    return (kal_int32) result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_amr_decode_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_speech_amr_decode_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    result = 0;
#else 
    result = PoC_AMR_DecodeStop();
#endif 

    return (kal_int32) result;
}

#endif /* __MED_POC_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

