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
 *	med_trc.h
 *
 * Project:
 * --------
 *   MT6205
 *
 * Description:
 * ------------
 *   This is trace map definition.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _MED_TRC_H
#define _MED_TRC_H

#ifndef GEN_FOR_PC

   #ifndef _STACK_CONFIG_H
   #error "stack_config.h should be included before tst_config.h"
   #endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


#ifndef _KAL_TRACE_H
   #error "kal_trace.h should be included before tst_trace.h"
#endif

BEGIN_TRACE_MAP(MOD_MED)

    /* TRACE_FUNC trace class */   
    /* GENERAL */
    TRC_MSG(MEM_INFO, "MED memory: total: %d, left: %d, alloc: %d, ptr: %x, cnt after alloc : %d")
    TRC_MSG(FREE_MEM_INFO, "MED free memory: ptr: %x, cnt after free : %d, left: %d")
    TRC_MSG(AUD_STATE, "AUD State: %d")
    TRC_MSG(AUD_CHECK_VALUE, "AUD vals: %d, %d, %d")
    TRC_MSG(AUD_CHECK_VOLUME, "Mode: %d VOL: %d, %d")
    TRC_MSG(AUD_CHECK_PATH, "Mode: %d PATH: %d, %d")
    TRC_MSG(ERROR_AUD_NVRAM_DATA_LEN, "Error: original len:%d, current len:%d")
    TRC_MSG(AUD_WAIT_EVT_TRC, "AUD Wait Event: %d, %d")
    TRC_MSG(AUD_SET_EVT_TRC, "AUD Set Event: %d, %d")
    TRC_MSG(AUD_RESULT, "AUD result: cause: %d, state: %d, seq_num: %d")

    /* camera */
    TRC_MSG(CAM_STATE, "CAM State: %d")
    TRC_MSG(CAM_CHECK_VALUE, "CAM vals: %d, %d, %d")
    TRC_MSG(CAM_WAIT_EVT_TRC, "CAM Wait Event: %d, %d")
    TRC_MSG(CAM_SET_EVT_TRC, "CAM Set Event: %d, %d")
    TRC_MSG(CAM_RESULT, "CAM result: cause: %d, state: %d, seq_num: %d")
    TRC_MSG(CAM_BUFFER, "CAM buffer[1:2i, 2:i+e, 3:2e, 4:single]: %d")
    TRC_MSG(CAM_QR_RESULT,"QR result: cause: %d")
    TRC_MSG(CAM_CLOSE_IMG_RESULT,"CAM close image file result: %d")

    /* image */
    TRC_MSG(IMG_STATE, "IMG State: %d")
    TRC_MSG(IMG_CHECK_VALUE, "IMG vals: %d, %d, %d")
    TRC_MSG(IMG_WAIT_EVT_TRC, "IMG Wait Event: %d, %d")
    TRC_MSG(IMG_SET_EVT_TRC, "IMG Set Event: %d, %d")
    TRC_MSG(IMG_RESULT, "IMG result: cause: %d, state: %d, seq_num: %d")
    /* video */
    TRC_MSG(VID_STATE, "VID State: %d")
    TRC_MSG(VID_CHECK_VALUE, "VID vals: %d, %d, %d")
    TRC_MSG(VID_FILE_INFO, "VID file info: v-data:%d, a-data:%d, v-meta:%d, a-meta:%d, v-rm:%d, a-rm:%d")
    TRC_MSG(VID_VIS_ERROR, "VID visual error: cause: %d, aux: %d")
    TRC_MSG(VID_AUD_ERROR, "VID audio error: cause: %d, aux: %d")
    TRC_MSG(VID_PARSE_ERROR, "VID mp4 parse error: cause: %d, aux: %d")
    TRC_MSG(VID_FSAL_ERROR, "VID fsal error: cause: %d, aux: %d")
    TRC_MSG(VID_RESULT, "VID result: cause: %d, state: %d, seq_num: %d")
    TRC_MSG(VID_WAIT_EVT_TRC, "VID Wait Event: %d, line: %d")
    TRC_MSG(VID_SET_EVT_TRC, "VID Set Event: %d, line: %d")
    TRC_MSG(VID_VIS_DBG_INFO, "Video debug info: %d, %d, %d, %d, %d, line: %d")
    /* web camera */
    TRC_MSG(WEBCAM_STATE, "Webcam State: %d")
    TRC_MSG(WEBCAM_CHECK_VALUE, "Webcam vals: %d, %d, %d")
    TRC_MSG(WEBCAM_WAIT_EVT_TRC, "Webcam Wait Event: %d, %d")
    TRC_MSG(WEBCAM_SET_EVT_TRC, "Webcam Set Event: %d, %d")
    TRC_MSG(WEBCAM_RESULT, "WEBCAM result: cause: %d, state: %d, seq_num: %d")

    /* tv out */
    TRC_MSG(TVO_STATE, "TVO State: %d")
    TRC_MSG(TVO_CHECK_VALUE, "TVO vals: %d, %d, %d")
    TRC_MSG(TVO_WAIT_EVT_TRC, "TVO Wait Event: %d, %d")
    TRC_MSG(TVO_SET_EVT_TRC, "TVO Set Event: %d, %d")
    TRC_MSG(TVO_RESULT, "TVO result: cause: %d, state: %d, seq_num: %d")

    /* MED */
    TRC_MSG(MED_NVRAM_READ_DATA_CNF_HDLR, "MED: med_nvram_read_data_cnf_hdlr")
    TRC_MSG(MED_NVRAM_WRITE_DATA_CNF_HDLR, "MED: med_nvram_write_data_cnf_hdlr")

    /* Speech */
    TRC_MSG(AUD_SPEECH_SET_FIR_COEFF, "AUD: aud_speech_set_fir_coefficient(), input_index=[%d], output_index=[%d]")

    /* VM */
    TRC_MSG(AUD_VM_RECORD_REQ_HDLR, "AUD: aud_vm_record_req_hdlr")
    TRC_MSG(AUD_VM_PLAY_REQ_HDLR, "AUD: aud_vm_play_req_hdlr")
    TRC_MSG(AUD_VM_STOP_REQ_HDLR, "AUD: aud_vm_stop_req_hdlr")
    TRC_MSG(AUD_VM_DELETE_REQ_HDLR, "AUD: aud_vm_delete_req_hdlr")
    TRC_MSG(AUD_VM_DELETE_CNF_HDLR, "AUD: aud_vm_delete_cnf_hdlr")
    TRC_MSG(AUD_VM_ABORT_REQ_HDLR, "AUD: aud_vm_abort_req_hdlr")
    TRC_MSG(AUD_VM_PAUSE_REQ_HDLR, "AUD: aud_vm_pause_req_hdlr")
    TRC_MSG(AUD_VM_RESUME_REQ_HDLR, "AUD: aud_vm_resume_req_hdlr")
    TRC_MSG(AUD_VM_APPEND_REQ_HDLR, "AUD: aud_vm_append_req_hdlr")
    TRC_MSG(AUD_VM_RENAME_REQ_HDLR, "AUD: aud_vm_rename_req_hdlr")
    TRC_MSG(AUD_VM_GET_INFO_REQ_HDLR, "AUD: aud_vm_get_info_req_hdlr")
    TRC_MSG(AUD_VM_GET_INFO_CNF_HDLR, "AUD: aud_vm_get_info_cnf_hdlr")
    TRC_MSG(AUD_VM_READ_DATA_IND_HDLR, "AUD: aud_vm_read_data_ind_hdlr")
    TRC_MSG(AUD_VM_WRITE_CNF_HDLR, "AUD: aud_vm_write_cnf_hdlr")
    TRC_MSG(AUD_VM_WRITE_DATA_IND_HDLR, "AUD: aud_vm_write_data_ind_hdlr")
    TRC_MSG(AUD_VM_READ_CNF_HDLR, "AUD: aud_vm_read_cnf_hdlr")   

    /*Record */
    TRC_MSG(AUD_MEDIA_RECORD_REQ_HDLR, "AUD: aud_media_record_req_hdlr")
    TRC_MSG(AUD_MEDIA_RECORD_CALLBACK, "AUD: aud_media_record_callback(): event = [%d], low task = [%d]")
    TRC_MSG(AUD_MEDIA_READ_DATA_IND_HDLR, "AUD: aud_media_read_data_ind_hdlr")
    TRC_MSG(AUD_MEDIA_RECORD_LOW_STOP_CNF_HDLR, "AUD: aud_media_record_low_stop_cnf_hdlr(): state = [%d]")
    TRC_MSG(AUD_MEDIA_RECORD_LOW_PAUSE_CNF_HDLR, "AUD: aud_media_record_low_pause_cnf_hdlr(): state = [%d]")
    TRC_MSG(AUD_MEDIA_RECORD_LOW_RESUME_CNF_HDLR, "AUD: aud_media_record_low_resume_cnf_hdlr(): state = [%d]")
    TRC_MSG(AUD_MEDIA_RECORD_LOW_ERROR_IND_HDLR, "AUD: aud_media_record_low_error_ind_hdlr(): state = [%d]")    
    TRC_MSG(MED_V_AUD_START_RECORD_REQ_HDLR, "AUD: med_v_aud_start_record_req_hdlr(): state = [%d]")
    TRC_MSG(MED_V_AUD_STOP_RECORD_REQ_HDLR, "AUD: med_v_aud_stop_record_req_hdlr(): state = [%d]")
    TRC_MSG(MED_V_AUD_PAUSE_RECORD_REQ_HDLR, "AUD: med_v_aud_pause_record_req_hdlr(): state = [%d]")
    TRC_MSG(MED_V_AUD_RESUME_RECORD_REQ_HDLR, "AUD: med_v_aud_resume_record_req_hdlr(): state = [%d]")    
    TRC_MSG(MED_V_AUD_READ_DATA_IND_HDLR, "AUD: med_v_aud_read_data_ind_hdlr(): state = [%d]")

    /* Play */
    TRC_MSG(AUD_MEDIA_PLAY_REQ_HDLR, "AUD: aud_media_play_req_hdlr")
    TRC_MSG(AUD_MEDIA_STOP_REQ_HDLR, "AUD: aud_media_stop_req_hdlr")
    TRC_MSG(AUD_MEDIA_PAUSE_REQ_HDLR, "AUD: aud_media_pause_req_hdlr")
    TRC_MSG(AUD_MEDIA_RESUME_REQ_HDLR, "AUD: aud_media_resume_req_hdlr")
    TRC_MSG(AUD_MEDIA_WRITE_DATA_IND_HDLR, "AUD: aud_media_write_data_ind_hdlr")

    TRC_MSG(AUD_GET_AUDIO_MODE_REQ_HDLR, "AUD: aud_get_audio_mode_req_hdlr")
    TRC_MSG(AUD_SET_AUDIO_MODE_REQ_HDLR, "AUD: aud_set_audio_mode_req_hdlr")
    TRC_MSG(AUD_GET_AUDIO_PROFILE_REQ, "AUD: aud_get_audio_profile_req")
    TRC_MSG(AUD_GET_AUDIO_PROFILE_REQ_HDLR, "AUD: aud_get_audio_profile_req_hdlr")
    TRC_MSG(AUD_SET_AUDIO_PROFILE_REQ_HDLR, "AUD: aud_set_audio_profile_req_hdlr")
    TRC_MSG(AUD_GET_AUDIO_PARAM_REQ_HDLR, "AUD: aud_get_audio_param_req_hdlr")
    TRC_MSG(AUD_SET_AUDIO_PARAM_REQ_HDLR, "AUD: aud_set_audio_param_req_hdlr")
    TRC_MSG(AUD_STARTUP_READ_NVRAM_DATA, "AUD: aud_startup_read_nvram_data")
    TRC_MSG(AUD_MELODY_STOP_BY_PLAY, "AUD: aud_melody_stop_by_play")
    TRC_MSG(AUD_MELODY_PLAY, "AUD: aud_melody_play")
    TRC_MSG(AUD_MELODY_STOP, "AUD: aud_melody_stop")
    TRC_MSG(AUD_MELODY_PLAY_BY_NAME, "AUD: aud_melody_play_by_name")
    TRC_MSG(AUD_WAV_PLAY_BY_STRING, "AUD: aud_wav_play_by_string")
    TRC_MSG(AUD_MIDI_PLAY_BY_STRING, "AUD: aud_midi_play_by_string")
    TRC_MSG(AUD_IMELODY_PLAY_BY_STRING, "AUD: aud_imelody_play_by_string")
    TRC_MSG(AUD_GPIO_DETECT_IND_HDLR, "AUD: aud_set_audio_mode_req_hdlr")
    TRC_MSG(AUD_SET_TV_OUT_AUD_PATH, "AUD: aud_set_tv_out_aud_path")
    TRC_MSG(AUD_SET_TV_OUT_PARAM, "AUD: aud_set_tv_out_aud_path")
    TRC_MSG(AUD_AUDIO_SET_MELODY_PATH_VOLUME, "AUD: aud_audio_set_melody_path_volume")
    TRC_MSG(AUD_AUDIO_SET_FMRDO_PATH_VOLUME, "AUD: aud_audio_set_fmrdo_path_volume")    

    TRC_MSG(AUD_VR_INIT_RCG_REQ_HDLR, "AUD: aud_vr_init_rcg_req_hdlr")
    TRC_MSG(AUD_VR_INIT_TRN_REQ_HDLR, "AUD: aud_vr_init_trn_req_hdlr")
    TRC_MSG(AUD_VR_VOICE_IN_REQ_HDLR, "AUD: aud_vr_voice_in_req_hdlr")
    TRC_MSG(AUD_VR_SD_RCG_VOICE_IN_REQ_HDLR, "AUD: aud_vr_sd_rcg_voice_in_req_hdlr")
    TRC_MSG(AUD_VR_SD_TRN_VOICE_IN_REQ_HDLR, "AUD: aud_vr_sd_trn_voice_in_req_hdlr")
    TRC_MSG(AUD_VR_VOICE_IN_RCG_CALLBACK, "AUD: aud_vr_voice_in_rcg_callback")
    TRC_MSG(AUD_VR_VOICE_IN_TRN_CALLBACK, "AUD: aud_vr_voice_in_trn_callback")
    TRC_MSG(AUD_VR_DEL_TAG_REQ_HDLR, "AUD: aud_vr_del_tag_req_hdlr")
    TRC_MSG(AUD_VR_CHECK_TAG_REQ_HDLR, "AUD: aud_vr_del_tag_req_hdlr")
    TRC_MSG(AUD_VR_SYNC_DB_REQ_HDLR, "AUD: aud_vr_sync_db_req_hdlr")
    TRC_MSG(AUD_VR_PLAY_TAG_REQ_HDLR, "AUD: aud_vr_play_tag_req_hdlr")
    TRC_MSG(AUD_VR_GET_DIR_REQ_HDLR, "AUD: aud_vr_get_dir_req_hdlr")
    TRC_MSG(AUD_VR_ADD_TAG_REQ_HDLR, "AUD: aud_vr_add_tag_req_hdlr")
    TRC_MSG(AUD_VR_ABORT_REQ_HDLR, "AUD: aud_vr_abort_req_hdlr")

    /* MMA */
    TRC_MSG(AUD_MMA_FSAL_PROCESS_EVENT_IND_HDLR, "MMA: aud_mma_fsal_process_event_ind_hdlr(): Type = [%d]")
    TRC_MSG(AUD_MMA_PAUSE_SINGLE_REQ, "MMA: aud_mma_pause_single_req(): Player Used = [%d], State = [%d], Progress DL = [%d]")
    TRC_MSG(AUD_MMA_RESUME_SINGLE_REQ, "MMA: aud_mma_resume_single_req(): Player Used = [%d], State = [%d], Progress DL = [%d]")
    TRC_MSG(AUD_MMA_WRITE_DATA_IND_REQ_HDLR, "MMA: aud_mma_write_data_ind_req_hdlr(): Player State = [%d]")

    /* Sound Effect */
    TRC_MSG(AUD_REVERB_SET_COEFF_REQ_HDLR, "AUD: aud_reverb_set_coeff_req_hdlr(): Reverb = [%d]")
    TRC_MSG(AUD_REVERB_TURN_ON_REQ_HDLR, "AUD: aud_reverb_turn_on_req_hdlr(): EQ = [%d], Reverb = [%d], Surround = [%d]")
    TRC_MSG(AUD_REVERB_TURN_OFF_REQ_HDLR, "AUD: aud_reverb_turn_off_req_hdlr(): EQ = [%d], Reverb = [%d], Surround = [%d]")
    TRC_MSG(AUD_SURROUND_TURN_ON_REQ_HDLR, "AUD: aud_surround_turn_on_req_hdlr(): EQ = [%d], Reverb = [%d], Surround = [%d]")
    TRC_MSG(AUD_SURROUND_TURN_OFF_REQ_HDLR, "AUD: aud_surround_turn_off_req_hdlr(): EQ = [%d], Reverb = [%d], Surround = [%d]")
    TRC_MSG(AUD_EQ_SET_MAGNITUDE_REQ_HDLR, "AUD: aud_eq_set_magnitude_req_hdlr(): EQ = [%d]")
    TRC_MSG(AUD_EQ_TURN_ON_REQ_HDLR, "AUD: aud_eq_turn_on_req_hdlr(): EQ = [%d], Reverb = [%d], Surround = [%d]")
    TRC_MSG(AUD_EQ_TURN_OFF_REQ_HDLR, "AUD: aud_eq_turn_off_req_hdlr(): EQ = [%d], Reverb = [%d], Surround = [%d]")
    
    /* CTM */
    TRC_MSG(AUD_CTM_OPEN_REQ_HDLR, "AUD: aud_ctm_open_req_hdlr")
    TRC_MSG(AUD_CTM_CLOSE_REQ_HDLR, "AUD: aud_ctm_close_req_hdlr")
    TRC_MSG(AUD_CTM_CONNECT_REQ_HDLR, "AUD: aud_ctm_connect_req_hdlr")
    TRC_MSG(AUD_CTM_SEND_TEXT_REQ_HDLR, "AUD: aud_ctm_send_text_req_hdlr")
    TRC_MSG(AUD_CTM_EVENT_IND_HDLR, "AUD: aud_ctm_event_ind_hdlr")
    TRC_MSG(CTM_STATE, "CTM State: %d")
    TRC_MSG(CTM_CHECK_VALUE, "CTM Val: %d")
    TRC_MSG(CTM_CHECK_VALUES, "CTM Vals: %d %d %d")
    TRC_MSG(CTM_CHECK_READ_TEXT_STEP_1, "CTM Read Text Step 1: %d %d %d")
    TRC_MSG(CTM_CHECK_READ_TEXT_STEP_2, "CTM Read Text Step 2: %d %d %d")

    /* BT A2DP */
    // func: msg hdlr
    TRC_MSG(AUD_BT_A2DP_STATE, "AUD_BT_A2DP State: %d")
    TRC_MSG(AUD_BT_A2DP_CHECK_VALUE, "AUD_BT_A2DP Vals: %d, %d, %d")
    TRC_MSG(AUD_BT_A2DP_ABORT_REQ_HDLR,"aud_bt_a2dp_abort_req_hdlr")
    TRC_MSG(AUD_BT_A2DP_STREAM_QOS_IND_HDLR,"aud_bt_a2dp_stream_qos_ind_hdlr")
    // func: req
    TRC_MSG(AUD_BT_A2DP_STREAM_CONFIG_AND_OPEN_REQ,"aud_bt_a2dp_stream_config_and_open_req")
    TRC_MSG(AUD_BT_A2DP_STREAM_ABORT_REQ,"aud_bt_a2dp_stream_abort_req")
    TRC_MSG(AUD_BT_A2DP_STREAM_RECONFIG_REQ,"aud_bt_a2dp_stream_reconfig_req")
    TRC_MSG(AUD_BT_A2DP_STREAM_START_REQ,"aud_bt_a2dp_stream_start_req")
    TRC_MSG(AUD_BT_A2DP_STREAM_PAUSE_REQ,"aud_bt_a2dp_stream_pause_req")
    TRC_MSG(AUD_BT_A2DP_STREAM_CLOSE_REQ,"aud_bt_a2dp_stream_close_req")
    // func: util
    TRC_MSG(AUD_BT_A2DP_RESET_STATE,"aud_bt_a2dp_reset_state")
    TRC_MSG(AUD_BT_A2DP_OPEN_CODEC,"aud_bt_a2dp_open_codec")
    TRC_MSG(AUD_BT_A2DP_CLOSE_CODEC,"aud_bt_a2dp_close_codec")
    TRC_MSG(AUD_BT_A2DP_OPEN_RESULT,"aud_bt_a2dp_open_result: %d")
    TRC_MSG(AUD_BT_A2DP_GET_AUDIO_CONFIG,"aud_bt_a2dp_get_audio_config: %d")
    TRC_MSG(AUD_BT_A2DP_PROCESS_CMD,"aud_bt_a2dp_process_cmd: %d,%d,%d")
    TRC_MSG(AUD_BT_A2DP_CMD_QUEUE_CLR,"aud_bt_a2dp_cmd_queue_clear: %d,%d,%d")
    TRC_MSG(AUD_BT_A2DP_CMD_QUEUE_POP,"aud_bt_a2dp_cmd_queue_pop: %d,%d,%d")
    TRC_MSG(AUD_BT_A2DP_CMD_QUEUE_ADD,"aud_bt_a2dp_cmd_queue_add: %d,%d,%d")
    TRC_MSG(AUD_BT_A2DP_MEDIA_RESET_OUTPUT,"aud_bt_a2dp_media_reset_output: media_output_on=%d, on=%d")
    TRC_MSG(AUD_BT_A2DP_SET_OUTPUT_ON,"aud_bt_a2dp_set_output_on: output_on=%d, on=%d")
    // func: hdlr
    TRC_MSG(AUD_BT_A2DP_MEDIA_PLAY_HDLR,"aud_bt_a2dp_media_play_hdlr: media_output_on=%d")
    TRC_MSG(AUD_BT_A2DP_MEDIA_PAUSE_HDLR,"aud_bt_a2dp_media_pause_hdlr: media_output_on=%d")
    TRC_MSG(AUD_BT_A2DP_MEDIA_RESUME_HDLR,"aud_bt_a2dp_media_resume_hdlr: media_output_on=%d")
    TRC_MSG(AUD_BT_A2DP_MEDIA_STOP_HDLR,"aud_bt_a2dp_media_stop_hdlr: media_output_on=%d")

    /* BT HFP */
    TRC_MSG(AUD_BT_HFP_STATE, "AUD_BT_HFP State: %d")
    TRC_MSG(AUD_BT_HFP_CHECK_VALUE, "AUD_BT_HFP Vals: %d, %d, %d")
    // func: msg hdlr
    TRC_MSG(AUD_BT_HFP_OPEN_REQ_HDLR,"aud_bt_hfp_open_req_hdlr: state=%d, audio_path_on=%d")
    TRC_MSG(AUD_BT_HFP_CLOSE_REQ_HDLR,"aud_bt_hfp_close_req_hdlr: state=%d, audio_path_on=%d")
    TRC_MSG(AUD_BT_HFP_TURN_ON_REQ_HDLR,"aud_bt_hfp_turn_on_req_hdlr: state=%d, disabled=%d")
    TRC_MSG(AUD_BT_HFP_TURN_OFF_REQ_HDLR,"aud_bt_hfp_turn_off_req_hdlr: state=%d, disabled=%d")
    TRC_MSG(AUD_BT_HFP_SCO_CONNECT_CNF_HDLR,"aud_bt_hfp_so_connect_cnf_hdlr: state=%d, audio_path_on=%d, result=%d")
    TRC_MSG(AUD_BT_HFP_SCO_CONNECT_IND_HDLR,"aud_bt_hfp_so_connect_ind_hdlr: state=%d, audio_path_on=%d")
    TRC_MSG(AUD_BT_HFP_SCO_DISCONNECT_CNF_HDLR,"aud_bt_hfp_so_disconnect_cnf_hdlr: state=%d, audio_path_on=%d, result=%d")
    TRC_MSG(AUD_BT_HFP_SCO_DISCONNECT_IND_HDLR,"aud_bt_hfp_so_disconnect_ind_hdlr: state=%d, audio_path_on=%d")
    // func: util
    TRC_MSG(AUD_BT_HFP_RESET_STATE,"aud_bt_hfp_reset_state")
    TRC_MSG(AUD_BT_HFP_IS_AUDIO_PATH_ON,"aud_bt_hfp_is_audio_path_on: state=%d, audio_path_on=%d")
    TRC_MSG(AUD_BT_HFP_SET_AUDIO_PATH,"aud_bt_hfp_set_audio_path: state=%d, audio_path_on=%d, on=%d")
    TRC_MSG(AUD_BT_HFP_SET_AUDIO_PATH_ON,"aud_bt_hfp_set_audio_path_on: state=%d, audio_path_on=%d ")
    TRC_MSG(AUD_BT_HFP_SET_AUDIO_PATH_OFF,"aud_bt_hfp_set_audio_path_off: state=%d, audio_path_on=%d ")


    /* RTP / VOIP */
    TRC_MSG(RTP_CHECK_RETURN, "RTP Return: %d")
    TRC_MSG(RTP_CHECK_VALUE, "RTP Val: %d")
    TRC_MSG(RTP_CHECK_VALUES, "RTP Vals: %d %d %d")
    TRC_MSG(RTP_CHECK_RTP_GET_VALUE, "RTP: seq:%d ssrc:%d")
    TRC_MSG(RTP_CHECK_CODEC, "Codec: AMR:%d 9:%d 31:%d 6_16:%d 6_24:%d 6_32:%d 6_40:%d A:%d U:%d CN:%d")
    TRC_MSG(RTP_CHECK_PTIME_MAXPTIME, "RTP: ptime:%d max_ptime:%d")
    TRC_MSG(RTP_CHECK_IDLE, "VoIP Idle")
    TRC_MSG(RTP_CHECK_ENCODE, "VoIP Encode")
    TRC_MSG(RTP_CHECK_DECODE, "VoIP Decode")
    TRC_MSG(RTP_CHECK_ENDECODE, "VoIP Encode/Decode")
    TRC_MSG(RTP_ERROR_PACKET_LOST, "RTP DATA LOST: cumul_lost = %d")
    TRC_MSG(RTP_CHECK_SENT_PACKET, "RTP SEND: ret = %d, seq = %d")
    TRC_MSG(RTP_CHECK_RECV_PACKET, "RTP RECV: ret = %d, seq = %d")
    TRC_MSG(RTP_CHECK_PLAY_PACKET, "RTP PLAY: Payload=%d, Seq=%d, Size=%d")
    TRC_MSG(RTP_CHECK_RECORD_PACKET, "RTP RECORD: len = %d") 

    /* STREAM */
    TRC_MSG(STREAM_CHECK_RETURN, "STREAM Return: %d")
    TRC_MSG(STREAM_CHECK_VALUE, "STREAM Val: %d")
    TRC_MSG(STREAM_CHECK_VALUES, "STREAM Vals: %d %d %d")

    TRC_MSG(STREAM_FSM_STATE, "STREAM FSM State: %d")    

    TRC_MSG(STREAM_INFO_MSG_IGNORED, "Stream message ignored!!")    
    TRC_MSG(STREAM_INFO_L1_PACKET_LOST, "Stream packet lost from L1!!")    

    TRC_MSG(STREAM_INFO_L1_CALL_A_GETSAMPLINGFREQ, "Stream Calling: A_GetSamplingFreq()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GETSAMPLINGFREQ, "Stream Return: A_GetSamplingFreq(): Freq:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_GETCHANNELNUM, "Stream Calling: A_GetChannelNum()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GETCHANNELNUM, "Stream Return: A_GetChannelNum(): Num:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_GETIMAGERESOLUTION, "Stream Calling: V_GetImageResolution()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_GETIMAGERESOLUTION, "Stream Return: V_GetImageResolution(): w:%d, h:%d, status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_GETBUFFERSTATUS, "Stream Calling: A_GetBufferStatus()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GETBUFFERSTATUS, "Stream Return: A_GetBufferStatus(): dura:%d, fr_sz:%d, tt_sz:%d, mbtd:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_GETBUFFERDURATION, "Stream Calling: V_GetBufferDuration()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_GETBUFFERDURATION, "Stream Return: V_GetBufferDuration(): dura:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_GETBUFFERSTATUS, "Stream Calling: V_GetBufferStatus()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_GETBUFFERSTATUS, "Stream Return: V_GetBufferStatus(): percentage:%d, fr_buf_sz:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_GETPLAYTIME, "Stream Calling: A_GetPlayTime()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GETPLAYTIME, "Stream Return: A_GetPlayTime(): playing_time:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_GETPLAYTIME, "Stream Calling: V_GetPlayTime()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_GETPLAYTIME, "Stream Return: V_GetPlayTime(): playing_time:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_IMAGEPATHOPEN_1, "Stream Calling: V_ImagePathOpen(), w:%d, h:%d, ofst_x:%d, ofst_y:%d, cntras:%d, brit:%d, lcdhwtri:%d, imgpitch:%d, imgdataform:%d, im_pitchbyte:%d, tvoutput:%d, buf1_addr:%d, buf2_addr:%d, buf_size:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_IMAGEPATHOPEN_2, "Stream Calling: V_ImagePathOpen(), w:%d, h:%d, ofst_x:%d, ofst_y:%d, cntras:%d, brit:%d, lcdhwtri:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_IMAGEPATHOPEN, "Stream Return: V_ImagePathOpen()")
    TRC_MSG(STREAM_INFO_L1_CALL_V_START, "Stream Calling: V_Start(), curr_play_time:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_START, "Stream Return: V_Start()")
    TRC_MSG(STREAM_INFO_L1_CALL_A_START, "Stream Calling: A_Start(), curr_play_time:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_START, "Stream Return: A_Start()")
    TRC_MSG(STREAM_INFO_L1_CALL_A_STOP, "Stream Calling: A_Stop()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_STOP, "Stream Return: A_Stop()")
    TRC_MSG(STREAM_INFO_L1_CALL_A_SETVOLUMELEVEL, "Stream Calling: A_SetVolumeLevel()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_SETVOLUMELEVEL, "Stream Return: A_SetVolumeLevel()")
    TRC_MSG(STREAM_INFO_L1_CALL_V_STOP, "Stream Calling: V_Stop()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_STOP, "Stream Return: V_Stop()")
    TRC_MSG(STREAM_INFO_L1_CALL_V_SWITCH_SCREEN_VIDEOSTOP, "Stream Calling: V_SwitchScreen_VideoStop()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_SWITCH_SCREEN_VIDEOSTOP, "Stream Return: V_SwitchScreen_VideoStop()")
    TRC_MSG(STREAM_INFO_L1_CALL_V_SWITCH_SCREEN_VIDEOSTART, "Stream Calling: V_SwitchScreen_VideoStart()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_SWITCH_SCREEN_VIDEOSTART, "Stream Return: V_SwitchScreen_VideoStart()")    
    TRC_MSG(STREAM_INFO_L1_CALL_V_IMAGEPATHCLOSE, "Stream Calling: V_ImagePathClose()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_IMAGEPATHCLOSE, "Stream Return: V_ImagePathClose()")
    TRC_MSG(STREAM_INFO_L1_CALL_A_CLOSE, "Stream Calling: A_Close()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_CLOSE, "Stream Return: A_Close()")
    TRC_MSG(STREAM_INFO_L1_CALL_V_CLOSE, "Stream Calling: V_Close()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_CLOSE, "Stream Return: V_Close()")
    TRC_MSG(STREAM_INFO_L1_CALL_A_PUTPACKET, "Stream Calling: A_PutPacket(), pt:%d, seq:%d, sz:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_PUTPACKET, "Stream Return: A_PutPacket(), result:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_PUTPACKET, "Stream Calling: V_PutPacket(), pt:%d, seq:%d, sz:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_PUTPACKET, "Stream Return: V_PutPacket(), result:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_OPENDLCHANNEL, "Stream Calling: A_OpenDLChannel(), codec:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_OPENDLCHANNEL, "Stream Return: A_OpenDLChannel(), handle:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_GETCODECCAP_AMR, "Stream Calling: A_GetCodecCapability_AMR()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GETCODECCAP_AMR, "Stream Return: A_GetCodecCapability_AMR(), oct_aln:%d, itlv:%d, chnl:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_CONFIG_AMR, "Stream Calling: A_Config_AMR(), oct_aln:%d, itlv:%d, chnl:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_CONFIG_AMR, "Stream Return: A_Config_AMR(), status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_GET_BUF_SIZE, "Stream Calling: A_GetBufferSize()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GET_BUF_SIZE, "Stream Return: A_GetBufferSize(), bufsize:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_SET_BUF, "Stream Calling: A_SetBuffer(), bufsize:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_SET_BUF, "Stream Return: A_SetBuffer(), status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_GETCODECCAP_AAC, "Stream Calling: A_GetCodecCapability_AAC()")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_GETCODECCAP_AAC, "Stream Return: A_GetCodecCapability_AAC(), rate:%d, bitrat:%d, cpres:%d, mode:%d, strmType:%d, SizeLen:%d, IdxLen:%d, IdxDellen:%d, ConstSize:%d, ConstDura:%d, MaxDisplace:%d, DeintlvBufSize:%d, prof_lev_id:%d, object:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_A_CONFIG_AAC, "Stream Calling: A_Config_AAC(), rate:%d, bitrat:%d, cpres:%d, mode:%d, strmType:%d, SizeLen:%d, IdxLen:%d, IdxDellen:%d, ConstSize:%d, ConstDura:%d, MaxDisplace:%d, DeintlvBufSize:%d, prof_lev_id:%d, object:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_A_CONFIG_AAC, "Stream Return: A_Config_AAC(), status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_OPENHANDLE, "Stream Calling: V_Get_Handle()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_OPENHANDLE, "Stream Return: V_Get_Handle(), handle:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_SETACTIVECODEC, "Stream Calling: V_SetActiveCodec(), codec:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_SETACTIVECODEC, "Stream Return: V_SetActiveCodec(), status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_GETCODECCAP_MP4, "Stream Calling: V_GetCapability_MP4()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_GETCODECCAP_MP4, "Stream Return: V_GetCapability_MP4(), timescale:%d, profile_level:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_CONFIG_MP4, "Stream Calling: V_Config_MP4(), timescale:%d, profile_level:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_CONFIG_MP4, "Stream Return: V_Config_MP4(), status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_GETCODECCAP_H263, "Stream Calling: V_GetCapability_H263()")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_GETCODECCAP_H263, "Stream Return: V_GetCapability_H263(), timescale:%d, profile:%d, level:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_CONFIG_H263, "Stream Calling: V_Config_H263(), timescale:%d, profile:%d, level:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_CONFIG_H263, "Stream Return: V_Config_H263(), status:%d")
    TRC_MSG(STREAM_INFO_L1_CALL_V_CHECKPKTS, "Stream Calling: V_CheckPkts(), start_seq:%d, diff_thres:%d")
    TRC_MSG(STREAM_INFO_L1_RETURN_V_CHECKPKTS, "Stream Return: V_CheckPkts(), status:%d")



    TRC_MSG(FUNC_STREAM_FSM, "stream_fsm(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_IDLE, "stream_fsm_handle_idle_state(): session_id:%d")    
    TRC_MSG(FUNC_STREAM_FSM_SET_CHANNEL, "stream_fsm_handle_set_channel_state(): session_id:%d")    
    TRC_MSG(FUNC_STREAM_FSM_DESCRIBE, "stream_fsm_handle_describe_state(): session_id:%d")    
    TRC_MSG(FUNC_STREAM_FSM_SETUP, "stream_fsm_handle_setup_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SEEK, "stream_fsm_handle_seek_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_BUFFERING, "stream_fsm_handle_buffering_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_PLAY, "stream_fsm_handle_play_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_STOPPING, "stream_fsm_handle_stoping_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_STOP, "stream_fsm_handle_stop_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_TEARDOWN, "stream_fsm_handle_teardown_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_REMOVE_CHANNEL, "stream_fsm_handle_remove_channel_state(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_IDLE_WITH_STREAM_CONNECT_REQ, "stream_fsm_idle_with_stream_connect_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SET_CHANNEL_WITH_RTSP_SET_CHANNEL_RSP, "stream_fsm_set_channel_with_rtsp_set_channel_rsp(): session_id:%d")
    TRC_MSG(FUNC_STREAM_SETUP_AUDIO_VIDEO_SESSION, "stream_setup_audio_video_session(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_ALL_SWITCH_TO_IDLE, "stream_fsm_all_switch_to_idle(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_CONNECT_PHASE_WITH_RTSP_DISCONNECT_IND, "stream_fsm_connect_phase_with_rtsp_disconnect_ind(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_ALL_WITH_STREAM_FORCE_ABORT_REQ, "stream_fsm_all_with_stream_force_abort_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_DESCRIBE_WITH_RTSP_REQUEST_RSP, "stream_fsm_describe_with_rtsp_request_rsp(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SETUP_WITH_RTSP_REQUEST_RSP, "stream_fsm_setup_with_rtsp_request_rsp(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_ALL_SWITCH_TO_TEARDOWN, "stream_fsm_all_switch_to_teardown(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_ALL_WITH_STREAM_SET_STOP_TIME_REQ, "stream_fsm_all_with_stream_set_stop_time_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_STOPING_STOP_WITH_STREAM_SEEK_REQ, "stream_fsm_stoping_stop_with_stream_seek_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SEEK_BUFFERING_WITH_STREAM_ABORT_RSP, "stream_fsm_seek_buffering_with_stream_abort_rsp(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SEEK_BUFFERING_WITH_RTSP_DISCONNECT_IND, "stream_fsm_seek_buffering_with_rtsp_disconnect_ind(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SEEK_BUFFERING_WITH_STREAM_GET_INFO_REQ, "stream_fsm_seek_buffering_with_stream_get_info_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SEEK_BUFFERING_WITH_STREAM_SET_INFO_REQ, "stream_fsm_seek_buffering_with_stream_set_info_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_SEEK_WITH_RTSP_REQUEST_RSP, "stream_fsm_seek_with_rtsp_request_rsp(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_BUFFERING_WITH_STREAM_GET_DL_PERCENTAGE_REQ, "stream_fsm_buffering_with_stream_get_dl_percentage_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_PLAY_WITH_STREAM_GET_PLAYING_TIME_REQ, "stream_fsm_play_with_stream_get_playing_time_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_BUFFERING_WITH_STREAM_PLAY_REQ, "stream_fsm_buffering_with_stream_play_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_PLAY_WITH_STREAM_STOP_REQ, "stream_fsm_play_with_stream_stop_req(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_PLAY_WITH_STREAM_SWITCH_SCREEN_VIDEOSTOP_REQ, "stream_fsm_play_with_stream_switch_screen_videostop_req(): session_id:%d")    
    TRC_MSG(FUNC_STREAM_FSM_PLAY_WITH_STREAM_SWITCH_SCREEN_VIDEOSTART_REQ, "stream_fsm_play_with_stream_switch_screen_videostart_req(): session_id:%d")    
    TRC_MSG(FUNC_STREAM_FSM_PLAY_WITH_RTSP_DISCONNECT_IND, "stream_fsm_play_with_rtsp_disconnect_ind(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_PLAY_SET_AUDIO_LEVEL_REQ, "stream_fsm_play_with_set_audio_level_req(): session_id:%d, level:%d")
    TRC_MSG(FUNC_STREAM_FSM_STOPPING_STOP_WITH_RTSP_DISCONNECT_IND, "stream_fsm_stopping_stop_with_rtsp_disconnect_ind(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_STOPPING_WITH_RTSP_REQUEST_RSP, "stream_fsm_stopping_with_rtsp_request_rsp(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FSM_TEARDOWN_SWITCH_TO_REMOVE_CHANNEL, "stream_fsm_teardown_switch_to_remove_channel(): session_id:%d")
    TRC_MSG(FUNC_STREAM_CREATE_AUDIO_VIDEO_RTP_SESSION, "stream_create_audio_video_rtp_session(): session_id:%d")
    TRC_MSG(FUNC_STREAM_CLOSE_AUDIO_VIDEO_RTP_SESSION, "stream_close_audio_video_rtp_session(): session_id:%d")
    TRC_MSG(FUNC_STREAM_CREATE_AUDIO_VIDEO_L1_SESSION, "stream_create_audio_video_l1_session(): session_id:%d")
    TRC_MSG(FUNC_STREAM_STOP_AUDIO_VIDEO_L1_SESSION, "stream_stop_audio_video_l1_session(): session_id:%d")
    TRC_MSG(FUNC_STREAM_CLOSE_AUDIO_VIDEO_L1_SESSION, "stream_close_audio_video_l1_session(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FILL_AMR_CAP, "stream_fill_amr_cap(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FILL_AAC_CAP, "stream_fill_aac_cap(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FILL_MP4V_CAP, "stream_fill_mp4v_cap(): session_id:%d")
    TRC_MSG(FUNC_STREAM_FILL_H263_CAP, "stream_fill_h263_cap(): session_id:%d")
    TRC_MSG(FUNC_STREAM_RTP_RECV_CALLBACK, "stream_rtp_recv_callback(): rtp_handle:%d")
    TRC_MSG(FUNC_STREAM_RTCP_RECV_CALLBACK, "stream_rtcp_recv_callback(): rtp_handle:%d")
    TRC_MSG(FUNC_STREAM_FIND_SESSION_BY_REQUEST_ID, "stream_find_session_by_request_id(): request_id:%d")
    TRC_MSG(FUNC_STREAM_FIND_SESSION_BY_RTSP_CHANNEL, "stream_find_session_by_rtsp_channel(): channel_id:%d")
    TRC_MSG(FUNC_STREAM_GET_LATEST_OUT_REQUEST_ID, "stream_get_latest_out_request_id(): session_id:%d")
    TRC_MSG(FUNC_STREAM_RTSP_REQUEST_REQ_AUX, "stream_rtsp_request_req_aux(): session_id:%d")
    TRC_MSG(FUNC_STREAM_GET_EXT_MEM, "stream_get_ext_mem(): size:%d")
    TRC_MSG(FUNC_STREAM_FREE_EXT_MEM, "stream_free_ext_mem(): buffer:%d")
    TRC_MSG(FUNC_STREAM_PARSE_SDP_FILE, "stream_parse_sdp_file(): session_id:%d")
    TRC_MSG(FUNC_STREAM_CONVERT_L1_CODEC_TYPE, "stream_convert_l1_codec_type(): codec_type:%d")
    TRC_MSG(FUNC_STREAM_GET_AUDIO_CODEC_RATE, "stream_get_audio_codec_rate(): session_id:%d")
    TRC_MSG(FUNC_STREAM_L1_CALLBACK_IND_HDLR, "stream_l1_callback_ind_hdlr(): session_id:%d")    
    TRC_MSG(FUNC_STREAM_GET_PLAY_TIME_TIMEOUT_CALLBACK, "stream_get_play_time_timeout_callback(): session_id:%d")

    TRC_MSG(VIDEO_STREAM_PUTPACKET_STATUS_1, "[v_drv] PutPacket Status: In-seq packet (seq#: %d), current seq# (%d)")
    TRC_MSG(VIDEO_STREAM_PUTPACKET_STATUS_2, "[v_drv] PutPacket Status: Packet dropped (seq#: %d), current seq# (%d)")
    TRC_MSG(VIDEO_STREAM_PUTPACKET_STATUS_3, "[v_drv] PutPacket Status: Packet out-of-seq (seq#: %d), current seq# (%d)")
    TRC_MSG(VIDEO_STREAM_PUTPACKET_STATUS_4, "[v_drv] PutPacket Status: Complete buffering initial packets (seq#: %d), current seq# (%d)")    
    TRC_MSG(VIDEO_STREAM_PUTPACKET_STATUS_5, "[v_drv] PutPacket Status: Buffering initial packets (seq#: %d), current seq# (%d)")
    TRC_MSG(VIDEO_STREAM_PUTPACKET_STATUS2, "[v_drv_r] Reorder Buffer Entry Status: Index (%d), seq# (%d), size (%d)")
    TRC_MSG(VIDEO_STREAM_REORDER_BUFFER_STATUS, "[v_drv_r] Reorder Buffer Status: current seq# (%d), total pkts (%d), buffer_size (%d), size_used (%d)")
    TRC_MSG(VIDEO_STREAM_REORDER_BUFFER_STATUS2, "[v_drv_r] Reorder Buffer Status after get_pkt: current seq# (%d), total pkts (%d), buffer_size (%d), size_used (%d)")    

    TRC_MSG(VIDEO_STREAM_DECODE_BUFFER_STATUS, "[v_drv_d] Decode Buffer Entry Status: index (%d), first frame# (%d), frames_to_decode (%d), duration_to_decode (%d ms), used_percentage (%d)")
    TRC_MSG(VIDEO_STREAM_DECODE_BUFFER_STATUS2, "[v_drv_d] Decode Buffer Status: frames_to_decode (%d), duration_to_decode (%d ms), used_percentage (%d)")
    TRC_MSG(VIDEO_STREAM_DECODE_BUFFER_STATUS3, "[v_drv_d] Decode Buffer Status: total buffers (%d), read_buffer_id (%d), write_buffer_id (%d)")
    TRC_MSG(VIDEO_STREAM_DECODE_BUFFER_STATUS4, "[v_drv_d_1] Decode Buffer Status: frame# (%d), duration (%d), size (%d)")
    TRC_MSG(VIDEO_STREAM_DECODE_BUFFER_STATUS5, "[v_drv_d_2] Decode Buffer Status: Buffer index (%d), Fill FPS (%d)")
    TRC_MSG(VIDEO_STREAM_DECODE_BUFFER_STATUS6, "[v_drv_d_2] Decode Buffer Status: Buffer index (%d), Consume FPS (%d)")

    /******* Video - Progressive DL ********/

    /* MED result  */
    TRC_MSG(MED_TRC_RES_OK, "[MED] result: MED_RES_OK, line: %d") /* 0 */
    TRC_MSG(MED_TRC_RES_FAIL, "[MED] result: MED_RES_FAIL, line: %d")    
    TRC_MSG(MED_TRC_RES_BUSY, "[MED] result: MED_RES_BUSY, line: %d")
    TRC_MSG(MED_TRC_RES_DISC_FULL, "[MED] result: MED_RES_DISC_FULL, line: %d")
    TRC_MSG(MED_TRC_RES_OPEN_FILE_FAIL, "[MED] result: MED_RES_OPEN_FILE_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_END_OF_FILE, "[MED] result: MED_RES_END_OF_FILE, line: %d")
    TRC_MSG(MED_TRC_RES_TERMINATED, "[MED] result: MED_RES_TERMINATED, line: %d")
    TRC_MSG(MED_TRC_RES_BAD_FORMAT, "[MED] result: MED_RES_BAD_FORMAT, line: %d")
    TRC_MSG(MED_TRC_RES_INVALID_FORMAT, "[MED] result: MED_RES_INVALID_FORMAT, line: %d")
    TRC_MSG(MED_TRC_RES_ERROR, "[MED] result: MED_RES_ERROR, line: %d")
    TRC_MSG(MED_TRC_RES_NO_DISC, "[MED] result: MED_RES_NO_DISC, line: %d") /* 10 */
    TRC_MSG(MED_TRC_RES_NOT_ENOUGH_SPACE, "[MED] result: MED_RES_NOT_ENOUGH_SPACE, line: %d")    
    TRC_MSG(MED_TRC_RES_INVALID_HANDLE, "[MED] result: MED_RES_INVALID_HANDLE, line: %d")        
    TRC_MSG(MED_TRC_RES_NO_HANDLE, "[MED] result: MED_RES_NO_HANDLE, line: %d")    
    TRC_MSG(MED_TRC_RES_RESUME, "[MED] result: MED_RES_RESUME, line: %d")    
    TRC_MSG(MED_TRC_RES_BLOCKED, "[MED] result: MED_RES_BLOCKED, line: %d")    
    TRC_MSG(MED_TRC_RES_MEM_INSUFFICIENT, "[MED] result: MED_RES_MEM_INSUFFICIENT, line: %d")    
    TRC_MSG(MED_TRC_RES_BUFFER_INSUFFICIENT, "[MED] result: MED_RES_BUFFER_INSUFFICIENT, line: %d")    
    TRC_MSG(MED_TRC_RES_FILE_EXIST, "[MED] result: MED_RES_FILE_EXIST, line: %d")    
    TRC_MSG(MED_TRC_RES_WRITE_PROTECTION, "[MED] result: MED_RES_WRITE_PROTECTION, line: %d")    
    TRC_MSG(MED_TRC_RES_PARAM_ERROR, "[MED] result: MED_RES_PARAM_ERROR, line: %d") /* 20 */
    TRC_MSG(MED_TRC_RES_UNSUPPORTED_CHANNEL, "[MED] result: MED_RES_UNSUPPORTED_CHANNEL, line: %d") 
    TRC_MSG(MED_TRC_RES_UNSUPPORTED_FREQ, "[MED] result: MED_RES_UNSUPPORTED_FREQ, line: %d") 
    TRC_MSG(MED_TRC_RES_UNSUPPORTED_TYPE, "[MED] result: MED_RES_UNSUPPORTED_TYPE, line: %d") 
    TRC_MSG(MED_TRC_RES_UNSUPPORTED_OPERATION, "MED_RES_UNSUPPORTED_OPERATION, line: %d") 
    TRC_MSG(MED_TRC_RES_PARSER_ERROR, "[MED] result: MED_RES_PARSER_ERROR, line: %d") 
    TRC_MSG(MED_TRC_RES_VIDEO_ERROR, "[MED] result: MED_RES_VIDEO_ERROR, line: %d") 
    TRC_MSG(MED_TRC_RES_AUDIO_ERROR, "[MED] result: MED_RES_AUDIO_ERROR, line: %d") 
    TRC_MSG(MED_TRC_RES_FSAL_ERROR, "[MED] result: MED_RES_FSAL_ERROR, line: %d") 
    TRC_MSG(MED_TRC_RES_MP4_PRODUCER_ERROR, "[MED] result: MED_RES_MP4_PRODUCER_ERROR, line: %d") 
    TRC_MSG(MED_TRC_RES_MP4_SAMPLEDATA_ERROR, "[MED] result: MED_RES_MP4_SAMPLEDATA_ERROR, line: %d") /* 30 */
    TRC_MSG(MED_TRC_RES_MP4_NO_VIDEO_TRACK, "[MED] result: MED_RES_MP4_NO_VIDEO_TRACK, line: %d") 
    TRC_MSG(MED_TRC_RES_MP4_NO_AUDIO_TRACK, "[MED] result: MED_RES_MP4_NO_AUDIO_TRACK, line: %d") 
    TRC_MSG(MED_TRC_RES_ID_MISMATCH, "[MED] result: MED_RES_ID_MISMATCH, line: %d") 
    TRC_MSG(MED_TRC_RES_ID_EXIST, "[MED] result: MED_RES_ID_EXIST, line: %d") 
    TRC_MSG(MED_TRC_RES_TRAINING_CONTINUE, "[MED] result: MED_RES_TRAINING_CONTINUE, line: %d") 
    TRC_MSG(MED_TRC_RES_NO_SOUND, "[MED] result: MED_RES_NO_SOUND, line: %d") 
    TRC_MSG(MED_TRC_RES_TOO_SIMILAR, "[MED] result: MED_RES_TOO_SIMILAR, line: %d") 
    TRC_MSG(MED_TRC_RES_TOO_DIFFERENT, "[MED] result: MED_RES_TOO_DIFFERENT, line: %d") 
    TRC_MSG(MED_TRC_RES_NO_MATCH, "[MED] result: MED_RES_NO_MATCH, line: %d") 
    TRC_MSG(MED_TRC_RES_SPEAK_TOO_LONG, "[MED] result: MED_RES_SPEAK_TOO_LONG, line: %d") /* 40 */
    TRC_MSG(MED_TRC_RES_SPEAK_TOO_SHORT, "[MED] result: MED_RES_SPEAK_TOO_SHORT, line: %d") 
    TRC_MSG(MED_TRC_RES_AUDIO_END, "[MED] result: MED_RES_AUDIO_END, line: %d") 
    TRC_MSG(MED_TRC_RES_VIDEO_END, "[MED] result: MED_RES_VIDEO_END, line: %d") 
    TRC_MSG(MED_TRC_RES_VIDEO_IMAGE_TOO_LARGE, "[MED] result: MED_RES_VIDEO_IMAGE_TOO_LARGE, line: %d") 
    TRC_MSG(MED_TRC_RES_VIDEO_FILE_TOO_LARGE, "[MED] result: MED_RES_VIDEO_FILE_TOO_LARGE, line: %d") 
    TRC_MSG(MED_TRC_RES_VIDEO_FRAME_RATE_TOO_HIGH, "[MED] result: MED_RES_VIDEO_FRAME_RATE_TOO_HIGH, line: %d") 
    TRC_MSG(MED_TRC_RES_VIDEO_SEEK_PARTIAL_DONE, "[MED] result: MED_RES_VIDEO_SEEK_PARTIAL_DONE, line: %d") 
    TRC_MSG(MED_TRC_RES_VRSI_OK, "[MED] result: MED_RES_VRSI_OK, line: %d") 
    TRC_MSG(MED_TRC_RES_VRSI_ERR_UNINITIALIZED, "[MED] result: MED_RES_VRSI_ERR_UNINITIALIZED, line: %d") 
    TRC_MSG(MED_TRC_RES_VRSI_ERR_BUSY, "[MED] result: MED_RES_VRSI_ERR_BUSY, line: %d") /* 50 */
    TRC_MSG(MED_TRC_RES_VRSI_ERR_MEM_INSUFFICIENT, "[MED] result: MED_RES_VRSI_ERR_MEM_INSUFFICIENT, line: %d") 
    TRC_MSG(MED_TRC_RES_VRSI_ERR_DATA_ERROR, "[MED] result: MED_RES_VRSI_ERR_DATA_ERROR, line: %d") 
    TRC_MSG(MED_TRC_RES_VRSI_ERR_LIBRARY_CORRUPT, "[MED] result: MED_RES_VRSI_ERR_LIBRARY_CORRUPT, line: %d")     
    TRC_MSG(MED_TRC_RES_VRSI_ERR_BAD_GRAMMAR, "[MED] result: MED_RES_VRSI_ERR_BAD_GRAMMAR, line: %d")     
    TRC_MSG(MED_TRC_RES_VRSI_ERR_LANG_NOT_SUPPORT, "[MED] result: MED_RES_VRSI_ERR_LANG_NOT_SUPPORT, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_NO_MATCH_TAG, "[MED] result: MED_RES_VRSI_ERR_NO_MATCH_TAG, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_TTS_TOO_LONG, "[MED] result: MED_RES_VRSI_ERR_TTS_TOO_LONG, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_SESSION, "[MED] result: MED_RES_VRSI_ERR_SESSION, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_NO_SOUND, "[MED] result: MED_RES_VRSI_ERR_NO_SOUND, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_CMD_TRN_FAIL, "[MED] result: MED_RES_VRSI_ERR_CMD_TRN_FAIL, line: %d") /* 60 */
    TRC_MSG(MED_TRC_RES_VRSI_ERR_CMD_RCG_FAIL, "[MED] result: MED_RES_VRSI_ERR_CMD_RCG_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_DGT_RCG_FAIL, "[MED] result: MED_RES_VRSI_ERR_DGT_RCG_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_DGT_ADP_FAIL, "[MED] result: MED_RES_VRSI_ERR_DGT_ADP_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_VRSI_ERR_UNKNOWN, "[MED] result: MED_RES_VRSI_ERR_UNKNOWN, line: %d")
    TRC_MSG(MED_TRC_RES_STOP_FM_RECORD, "[MED] result: MED_RES_STOP_FM_RECORD, line: %d")
    TRC_MSG(MED_TRC_RES_UNSUPPORTED_SPEED, "[MED] result: MED_RES_UNSUPPORTED_SPEED, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_CLOSE, "[MED] result: MED_RES_A2DP_CLOSE, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_DISCOVER_SEP_FAIL, "[MED] result: MED_RES_A2DP_DISCOVER_SEP_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_GET_SEP_CAP_FAIL, "[MED] result: MED_RES_A2DP_GET_SEP_CAP_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_NO_MATCH_CAP, "[MED] result: MED_RES_A2DP_NO_MATCH_CAP, line: %d") /* 70 */
    TRC_MSG(MED_TRC_RES_A2DP_CONFIG_STREAM_FAIL, "[MED] result: MED_RES_A2DP_CONFIG_STREAM_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_RECONFIG_STREAM_FAIL, "[MED] result: MED_RES_A2DP_RECONFIG_STREAM_FAIL, line: %d")    
    TRC_MSG(MED_TRC_RES_A2DP_OPEN_STREAM_FAIL, "[MED] result: MED_RES_A2DP_OPEN_STREAM_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_START_STREAM_FAIL, "[MED] result: MED_RES_A2DP_START_STREAM_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_A2DP_PAUSE_STREAM_FAIL, "[MED] result: MED_RES_A2DP_PAUSE_STREAM_FAIL, line: %d")
    TRC_MSG(MED_TRC_RES_HFP_CLOSE, "[MED] result: MED_RES_HFP_CLOSE, line: %d")
    TRC_MSG(MED_TRC_RES_IMG_DECODE_TIME_OUT, "[MED] result: MED_RES_IMG_DECODE_TIME_OUT, line: %d")    
    TRC_MSG(MED_TRC_RES_ROOT_DIR_FULL, "[MED] result: MED_RES_ROOT_DIR_FULL, line: %d")    
    TRC_MSG(MED_TRC_RES_BR_IMAGE_ERROR, "[MED] result: MED_RES_BR_IMAGE_ERROR, line: %d") /* 79 */
    TRC_MSG(MED_TRC_RES_BR_MODULE_ERROR, "[MED] result: MED_RES_BR_MODULE_ERROR, line: %d")    
    TRC_MSG(MED_TRC_RES_BR_OUT_OF_MEMORY, "[MED] result: MED_RES_BR_OUT_OF_MEMORY, line: %d")    
    TRC_MSG(MED_TRC_RES_BR_OVER_VERSION, "[MED] result: MED_RES_BR_OVER_VERSION, line: %d")        
    TRC_MSG(MED_TRC_RES_PDL_AUDIO_UNDERFLOW, "[MED] result: MED_RES_PDL_AUDIO_UNDERFLOW, line: %d") /* 83 */   
    TRC_MSG(MED_TRC_RES_PDL_VIDEO_UNDERFLOW, "[MED] result: MED_RES_PDL_VIDEO_UNDERFLOW, line: %d") 
    TRC_MSG(MED_TRC_RES_STREAM_BEARER_DISCONNECTED, "[MED] result: MED_RES_STREAM_BEARER_DISCONNECTED, line: %d") /* 85 */
    TRC_MSG(MED_TRC_RES_STREAM_INVALID_SDP, "[MED] result: MED_RES_STREAM_INVALID_SDP, line: %d")  
    TRC_MSG(MED_TRC_RES_STREAM_RTSP_SET_CHANNEL_FAIL, "[MED] result: MED_RES_STREAM_RTSP_SET_CHANNEL_FAIL, line: %d")  
    TRC_MSG(MED_TRC_RES_STREAM_RTSP_REQUEST_FAIL, "[MED] result: MED_RES_STREAM_RTSP_REQUEST_FAIL, line: %d")  
    TRC_MSG(MED_TRC_RES_STREAM_PLAY_FINISH, "[MED] result: MED_RES_STREAM_PLAY_FINISH, line: %d")  
    TRC_MSG(MED_TRC_RES_STREAM_BUFFER_UNDERFLOW, "[MED] result: MED_RES_STREAM_BUFFER_UNDERFLOW, line: %d")      
    TRC_MSG(MED_TRC_RES_STREAM_BUFFER_OVERFLOW, "[MED] result: MED_RES_STREAM_BUFFER_OVERFLOW, line: %d")  
    TRC_MSG(MED_TRC_RES_STREAM_INVALID_RESOLUTION, "[MED] result: MED_RES_STREAM_INVALID_RESOLUTION, line: %d")  
    TRC_MSG(MED_TRC_RES_STREAM_STOP_TIMEOUT, "[MED] result: MED_RES_STREAM_STOP_TIMEOUT, line: %d")
    TRC_MSG(MED_TRC_RES_VDOEDT_ENCODE_FAIL, "[MED] result: MED_RES_VDOEDT_ENCODE_FAIL, line: %d")  
    TRC_MSG(MED_TRC_RES_DECODER_NOT_SUPPORT, "[MED] result: MED_RES_DECODER_NOT_SUPPORT, line: %d")
    TRC_MSG(MED_TRC_RES_REACH_STOP_TIME, "[MED] result: MED_RES_REACH_STOP_TIME, line: %d")
    TRC_MSG(MED_TRC_RES_UNKNOWN_ENUM, "[MED]  result: UNKNOWN ENUM [%d] !!Plz add new trace, line: %d")

   
    /* vid_state */
    TRC_MSG(VID_TRC_VID_STATE_IDLE, "[VID] vid_state: VID_IDLE, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PREVIEW, "[VID] vid_state: VID_PREVIEW, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_RECORD, "[VID] vid_state: VID_RECORD, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_RECORD_FINISH, "[VID] vid_state: VID_RECORD_FINISH, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_RECORD_PAUSED, "[VID] vid_state: VID_RECORD_PAUSED, line: %d")  
    TRC_MSG(VID_TRC_VID_STATE_OPEN_FILE, "[VID] vid_state: VID_OPEN_FILE, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_FILE_READY, "[VID] vid_state: VID_FILE_READY, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PLAY_INIT, "[VID] vid_state: VID_PLAY_INIT, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PLAY, "[VID] vid_state: VID_PLAY, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_AUDIO_PLAY_FINISH, "[VID] vid_state: VID_AUDIO_PLAY_FINISH, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_AUDIO_PLAY_ERROR, "[VID] vid_state: VID_AUDIO_PLAY_ERROR, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_VISUAL_PLAY_FINISH, "[VID] vid_state: VID_VISUAL_PLAY_FINISH, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PLAY_PAUSED, "[VID] vid_state: VID_PLAY_PAUSED, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_FILE_MERGE, "[VID] vid_state: VID_FILE_MERGE, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_SEEK, "[VID] vid_state: VID_SEEK, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PLAY_STOP_VISUAL, "[VID] vid_state: VID_PLAY_STOP_VISUAL, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_RECORD_STOP_VISUAL, "[VID] vid_state: VID_RECORD_STOP_VISUAL, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_DELAY_OPEN, "[VID] vid_state: VID_DELAY_OPEN, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_RECORD_ABORTING, "[VID] vid_state: VID_RECORD_ABORTING, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PLAY_ABORTING, "[VID] vid_state: VID_PLAY_ABORTING, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_START_PREVIEW, "[VID] vid_state: VID_START_PREVIEW, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_FILE_MERGE_STOPPING, "[VID] vid_state: VID_FILE_MERGE_STOPPING, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_PDL_META_BUFFERING, "[VID] vid_state: VID_PDL_META_BUFFERING, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_VIDEO_PLAY_UNDERFLOW, "[VID] vid_state: VID_VIDEO_PLAY_UNDERFLOW, line: %d") 
    TRC_MSG(VID_TRC_VID_STATE_EDITOR_FILE_MERGE, "[VID] vid_state: VID_EDITOR_FILE_MERGE, line: %d")       
    TRC_MSG(VID_TRC_VID_STATE_REACH_STOP_TIME, "[VID] vid_state: VID_PLAY_REACH_STOP_TIME, line: %d")       
    TRC_MSG(VID_TRC_VID_STATE_EDITOR_MERGE_STOPPING, "[VID] vid_state: VID_EDITOR_MERGE_STOPPING, line: %d")           
    TRC_MSG(VID_TRC_VID_STATE_RECORD_UPDATE_BLT_PAUSED, "[VID] vid_state: VID_RECORD_UPDATE_BLT_PAUSED, line: %d")           
    TRC_MSG(VID_TRC_VID_STATE_UNKNOW, "[VID] vid_state: UNKNOWN, line: %d")           

    /* vid_aud_state */
    TRC_MSG(VID_TRC_VID_STATE_AUD_IDEL, "[VID] vid_aud_state: VID_AUD_IDLE, line: %d")
    TRC_MSG(VID_TRC_VID_STATE_AUD_PLAY_NORMAL, "[VID] vid_aud_state: VID_AUD_PLAY_NORMAL, line: %d")  
    TRC_MSG(VID_TRC_VID_STATE_AUD_PLAY_HIGH_SPEED, "[VID] vid_aud_state: VID_AUD_PLAY_HIGH_SPEED, line: %d")  
    TRC_MSG(VID_TRC_VID_STATE_AUD_PLAY_DUMMY, "[VID] vid_aud_state: VID_AUD_PLAY_DUMMY, line: %d") 
    TRC_MSG(VID_TRC_VID_STATE_AUD_RECORD, "[VID] vid_aud_state: VID_AUD_RECORD, line: %d")  
    TRC_MSG(VID_TRC_VID_STATE_AUD_RECORD_PAUSED, "[VID] vid_aud_state: VID_AUD_RECORD_PAUSED, line: %d") 
    TRC_MSG(VID_TRC_VID_STATE_AUD_PLAY_UNDERFLOW, "[VID] vid_aud_state: VID_AUD_PLAY_UNDERFLOW, line: %d")     
    TRC_MSG(VID_TRC_VID_STATE_AUD_UNKNOW, "[VID] vid_aud_state: UNKNOWN, line: %d")           

    /* misc */
    TRC_MSG(VID_TRC_ENTER_VID_STATE, "[VID] Enter VID state: %d, line: %d")
    TRC_MSG(VID_TRC_ENTER_AUD_STATE, "[VID] Enter AUD state: %d, line: %d")    
    TRC_MSG(VID_TRC_FILE_SIZE, "[VID] file_size: %d")   
    TRC_MSG(VID_TRC_AUD_DURATION, "[VID] aud_duration: %d")   
    TRC_MSG(VID_TRC_VID_DURATION, "[VID] vid_duration: %d")      
    TRC_MSG(VID_TRC_AV_DURATION, "[VID] aud_dur: %d, vid_dur: %d")          
    TRC_MSG(VID_TRC_TOTAL_DURATION, "[VID] total_dur: %d, total_aud_dur: %d, total_vid_dur: %d")
    TRC_MSG(VID_TRC_CUR_TIME, "[VID] cur_time: %d, line: %d")    
    TRC_MSG(VID_TRC_STOP_TIME, "[VID] stop_time: %d, line: %d")        
    TRC_MSG(VID_TRC_START_TIME, "[VID] start_time: %d")       
    TRC_MSG(VID_TRC_DURATION, "[VID] duration: %d")        
    TRC_MSG(VID_TRC_PERCENT, "[VID] percent: %d, line: %d")            
    TRC_MSG(VID_TRC_BUFFER_TIME, "[VID] available: %d, current: %d, need: %d") 
    TRC_MSG(VID_TRC_MAX_TIME, "[VID] max time: %d, line: %d")     
    TRC_MSG(VID_TRC_BUFFER_LEN, "[VID] buffer_len: %d") 
    TRC_MSG(VID_TRC_DRIVER_RET, "[VID] ret: %d")
    TRC_MSG(VID_TRC_EVENT, "[VID] event: %d")
    TRC_MSG(VID_TRC_LINE, "[VID] line: %d")
    TRC_MSG(VID_TRC_FRAME_COUNT, "[VID] frame_count: %d")
    TRC_MSG(VID_TRC_FPS, "[VID] fps: %d")
    TRC_MSG(VID_TRC_SPEED, "[VID] speed: %d")    
    TRC_MSG(VID_TRC_RETURN_VALUE, "[VID] return value: %d, line: %d")
    TRC_MSG(VID_TRC_RECORD_FILE_SIZE, "[VID] v_size: %d, v_meta: %d, v_rm: %d, a_size, %d, a_meta: %d, a_rm: %d, line: %d")
    TRC_MSG(VID_TRC_RECORD_FILE_LIMIT, "[VID] limit: %d, sum: %d, line: %d")
    TRC_MSG(VID_TRC_DISC_FREE_SPACE, "[VID] free_cluster: %d, cluster_size: %d, free_size: %d, line: %d")
    TRC_MSG(VID_TRC_AUDIO_PROFILE, "[VID] sample_rate: %d, channel_no: %d, format: %d")
    TRC_MSG(VID_TRC_TRACK_INFO, "[VID] audio_track: %d, video_track: %d")
    TRC_MSG(VID_TRC_AUD_READ_BUF, "[VID] audio_total_buf: %d, read_buf: %d")
    TRC_MSG(VID_TRC_AUD_FRAME, "[VID] audio_frame: %d, line: %d")
    TRC_MSG(VID_TRC_CUR_TICK, "[VID] cur_tick: %d, line: %d")
    TRC_MSG(VID_TRC_USE_PESUDO_MERGE, "[VID] pseudo_merge: %d, line: %d")
    TRC_MSG(VID_TRC_TICK_PER_FRAME_PERIOD, "[VID] tick_per_frame_period: %d, line: %d")    

    /* function */
    TRC_MSG(VID_TRC_LOAD_VIDEO_WORKING_DATA_BUF, "[VID] vid_load_video_working_data_buf(), handle: %d")
    TRC_MSG(VID_TRC_LOAD_VIDEO_WORKING_DATA_VAR, "[VID] vid_load_video_working_data_var(), handle: %d")   
    TRC_MSG(VID_TRC_STORE_VIDEO_WORKING_DATA_VAR, "[VID] vid_store_video_working_data_var(), handle: %d")       
    TRC_MSG(VID_TRC_CLEAR_VIDEO_WORKING_DATA, "[VID] vid_clear_video_working_data()")       
    TRC_MSG(VID_TRC_ADD_VIDEO_WORKING_DATA_ITEM, "[VID] vid_add_video_working_data_item()")       
    TRC_MSG(VID_TRC_REMOVE_VIDEO_WORKING_DATA_ITEM, "[VID] vid_remove_video_working_data_item(), handle: %d")  
    TRC_MSG(VID_TRC_UPDATE_FRAME_TO_BUFFER, "[VID] vid_update_frame_to_buffer()")  
    TRC_MSG(VID_TRC_EVALUATE_RESIDUAL_SIZE, "[VID] vid_evaluate_residual_size(), size: %d")  
    TRC_MSG(VID_TRC_EVALUATE_AUDIO_REAL_META_FILE_SIZE, "[VID] vid_evaluate_audio_real_meta_file_size(), time: %d")  
    TRC_MSG(VID_TRC_EVALUATE_AUDIO_META_FILE_SIZE, "[VID] vid_evaluate_audio_meta_file_size(), time: %d")  
    TRC_MSG(VID_TRC_FILE_VISUAL_RESIDUAL_SIZE, "[VID] vid_file_visual_residual_size()")  
    TRC_MSG(VID_TRC_FILE_AUDIO_RESIDUAL_SIZE, "[VID] vid_file_audio_residual_size()")  
    TRC_MSG(VID_TRC_FILE_META_RESIDUAL_SIZE, "[VID] vid_file_meta_residual_size()")  
    TRC_MSG(VID_TRC_GET_CURRENT_FILE_SIZE, "[VID] vid_get_current_file_size()")  
    TRC_MSG(VID_TRC_GET_DISC_FREE_SPACE, "[VID] vid_get_disc_free_space()")      
    TRC_MSG(VID_TRC_RELEASE_MEMORY, "[VID] vid_release_memory(), ext_add: %d, int_add: %d")  
    TRC_MSG(VID_TRC_STOP_UNFINISHED_AUDIO, "[VID] vid_stop_unfinished_audio()")  
    TRC_MSG(VID_TRC_AUDIO_RECORD_CALLBACK_DUMMY, "[VID] vid_audio_record_callback_dummy(), event %d")      
    TRC_MSG(VID_TRC_SAVE_FILE_PATH, "[VID] vid_save_file_path()")      
    TRC_MSG(VID_TRC_OPEN_AUDIO_FILE_FOR_RECORD, "[VID] vid_open_audio_file_for_record()")          
    TRC_MSG(VID_TRC_OPEN_VISUAL_FILE_FOR_RECORD, "[VID] vid_open_visual_file_for_record()")    
    TRC_MSG(VID_TRC_CLOSE_VISUAL_FILE_FOR_RECORD, "[VID] vid_close_visual_file_for_record()")    
    TRC_MSG(VID_TRC_CLOSE_AUDIO_FILE_FOR_RECORD, "[VID] vid_close_audio_file_for_record()")    
    TRC_MSG(VID_TRC_PREVIEW_REQ_HDLR, "[VID] vid_preview_req_hdlr()")    
    TRC_MSG(VID_TRC_RECORD_REQ_HDLR, "[VID] vid_record_req_hdlr()") 
    TRC_MSG(VID_TRC_STOP_REQ_HDLR, "[VID] vid_stop_req_hdlr()") 
    TRC_MSG(VID_TRC_FILE_MERGE_REQ_HDLR, "[VID] vid_file_merge_req_hdlr()") 
    TRC_MSG(VID_TRC_OPEN_REQ_HDLR, "[VID] vid_open_req_hdlr()")    
    TRC_MSG(VID_TRC_CLOSE_PLAY_FILE, "[VID] vid_close_play_file(), media_mode: %d, handle: %d")     
    TRC_MSG(VID_TRC_CLOSE_REQ_HDLR, "[VID] vid_close_req_hdlr()") 
    TRC_MSG(VID_TRC_AUDIO_PLAY_CALLBACK, "[VID] vid_audio_play_callback(), event %d")      
    TRC_MSG(VID_TRC_AUDIO_PLAY_CALLBACK_DUMMY, "[VID] vid_audio_play_callback_dummy(), event %d")        
    TRC_MSG(VID_TRC_PLAY_DUMMY_AUDIO, "[VID] vid_play_dummy_audio()")        
    TRC_MSG(VID_TRC_GET_ACCURATE_PLAY_SPEED, "[VID] vid_get_accurate_play_speed()")        
    TRC_MSG(VID_TRC_PLAY_RESTART, "[VID] vid_play_restart()")     
    TRC_MSG(VID_TRC_PLAY_FINISH_HDLR, "[VID] vid_play_finish_hdlr(), repeat: %d")         
    TRC_MSG(VID_TRC_PLAY_REQ_HDLR, "[VID] vid_play_req_hdlr(), repeat: %d")             
    TRC_MSG(VID_TRC_SEEK_REQ_HDLR, "[VID] vid_seek_req_hdlr()")    
    TRC_MSG(VID_TRC_PAUSE_REQ_HDLR, "[VID] vid_pause_req_hdlr()")        
    TRC_MSG(VID_TRC_RESUME_REQ_HDLR, "[VID] vid_resume_req_hdlr()")            
    TRC_MSG(VID_TRC_SET_STOP_TIME_HDLR, "[VID] vid_set_stop_time_req_hdlr()") 
    TRC_MSG(VID_TRC_CHECK_STOP_TIME, "[VID] vid_check_stop_time()")     
    TRC_MSG(VID_TRC_GET_IFRAME_REQ_HDLR, "[VID] vid_get_iframe_req_hdlr()")     
    TRC_MSG(VID_TRC_SET_DISPLAY_REQ_HDLR, "[VID] vid_set_display_req_hdlr()")         
    TRC_MSG(VID_TRC_UPDATE_BLT_PAUSE_REQ_HDLR, "[VID] vid_update_blt_pause_req_hdlr()")             
    TRC_MSG(VID_TRC_UPDATE_BLT_RESUME_REQ_HDLR, "[VID] vid_update_blt_resume_req_hdlr()")                 
    TRC_MSG(VID_TRC_SET_PARAM_REQ_HDLR, "[VID] vid_set_param_req_hdlr()")             
    TRC_MSG(VID_TRC_VISUAL_RECORD_CNF_HDLR, "[VID] vid_visual_record_cnf_hdlr()")      
    TRC_MSG(VID_TRC_VISUAL_STOP_CNF_HDLR, "[VID] vid_visual_stop_cnf_hdlr()")          
    TRC_MSG(VID_TRC_VISUAL_PLAY_CNF_HDLR, "[VID] vid_visual_play_cnf_hdlr()")      
    TRC_MSG(VID_TRC_VISUAL_SEEK_CNF_HDLR, "[VID] vid_visual_seek_cnf_hdlr()")          
    TRC_MSG(VID_TRC_VISUAL_FILE_MERGE_CNF_HDLR, "[VID] vid_visual_file_merge_cnf_hdlr()")              
    TRC_MSG(VID_TRC_VISUAL_RECORD_FINISH_IND_HDLR, "[VID] vid_visual_record_finish_ind_hdlr()")
    TRC_MSG(VID_TRC_VISUAL_PLAY_FINISH_IND_HDLR, "[VID] vid_visual_play_finish_ind_hdlr()") 
    TRC_MSG(VID_TRC_AUDIO_PLAY_FINISH_IND_HDLR, "[VID] vid_audio_play_finish_ind_hdlr()")
    TRC_MSG(VID_TRC_ERROR_REVOCER_IND_HDLR, "[VID] vid_error_recover_ind_hdlr()")    
    TRC_MSG(VID_TRC_CLEAN_TMP_FILES, "[VID] vid_clean_temp_files()")
    TRC_MSG(VID_TRC_CHECK_UNFINISHED_FILE, "[VID] vid_check_unfinished_file()")    
    TRC_MSG(VID_TRC_STOP_UNFINISHED_TASK, "[VID] vid_stop_unfinished_task()")       
    TRC_MSG(VID_TRC_ABORT_BY_CLIENT_SWITCHING, "[VID] vid_abort_by_client_switching()")          
    TRC_MSG(VID_TRC_IS_AUDIO_CHANNEL_AVAILABLE, "[VID] vid_is_audio_channel_available()")              
    TRC_MSG(VID_TRC_SET_OVERLAY_PALETTER_REQ_HDLR, "[VID] vid_set_overlay_palette_req_hdlr()")          
    TRC_MSG(VID_TRC_GET_PDL_MAX_TIME_REQ_HDLR, "[VID] vid_get_pdl_max_time_req_hdlr()")
    TRC_MSG(VID_TRC_GET_PDL_PERCENT_REQ_HDLR, "[VID] vid_get_pdl_precent_req_hdlr()")
    TRC_MSG(VID_TRC_CHECK_IS_PDL_REQ_HDLR, "[VID] vid_check_is_pdl_req_hdlr()")    
    TRC_MSG(VID_TRC_PDL_META_BUFFERING_HDLR, "[VID] vid_pdl_meta_buffering_hdlr()")
    TRC_MSG(VID_TRC_CHECK_PDL_FILE_META, "[VID] vid_check_pdl_file_meta()")    
    TRC_MSG(VID_TRC_OPEN_PLAY_FILE, "[VID] vid_open_play_file()")        
    TRC_MSG(VID_TRC_PLAY_AUDIO, "[VID] vid_play_audio(), frame: %d")       
    TRC_MSG(VID_TRC_STOP_VISUAL, "[VID] vid_stop_visual()")
    TRC_MSG(VID_TRC_STOP_AUDIO, "[VID] vid_stop_audio()")    
    TRC_MSG(VID_TRC_DECODE_EVENT_IND_HDLR, "[VID] vid_decode_event_ind_hdlr()")    
    TRC_MSG(VID_TRC_SEND_PLAY_FINISH_IND, "[VID] vid_send_play_finish_ind()")    
    TRC_MSG(VID_TRC_SET_RESULT, "[VID] vid_set_result()")    
    TRC_MSG(VID_TRC_EDT_ENCODE_EVENT_IND_HDLR, "[VID] vid_edt_encode_event_ind_hdlr()")    
    TRC_MSG(VID_TRC_EDT_APPEND_AUDIO, "[VID] vid_edt_append_audio()")    
    TRC_MSG(VID_TRC_EDT_APPEND_IMAGE, "[VID] vid_edt_append_image()")    
    TRC_MSG(VID_TRC_EDT_APPEND_VIDEO, "[VID] vid_edt_append_video()")   
    TRC_MSG(VID_TRC_EDT_SET_ACTIVE_REQ_HDLR, "[VID] vid_edt_set_active_req_hdlr()")       
    TRC_MSG(VID_TRC_EDT_OPEN_VISUAL_FILE_FOR_ENCODE, "[VID] vid_edt_open_visual_file_for_encode()")       
    TRC_MSG(VID_TRC_EDT_OPEN_AUDIO_FILE_FOR_ENCODE, "[VID] vid_edt_open_audio_file_for_encode()")       
    TRC_MSG(VID_TRC_EDT_ENCODE_START, "[VID] vid_edt_encode_start()")       
    TRC_MSG(VID_TRC_EDT_ENC_MERGE_REQ_HDLR, "[VID] vid_edt_enc_merge_req_hdlr()")  
    TRC_MSG(VID_TRC_EDT_ENC_STOP_MERGE_REQ_HDLR, "[VID] vid_edt_enc_stop_merge_req_hdlr()")  
    TRC_MSG(VID_TRC_EDT_OPEN_BGM_REQ_HDLR, "[VID] vid_edt_open_bgm_req_hdlr()")  
    TRC_MSG(VID_TRC_EDT_CLOSE_BGM_REQ_HDLR, "[VID] vid_edt_close_bgm_req_hdlr()")       
    TRC_MSG(VID_TRC_EDT_OPEN_SILENCE_REQ_HDLR, "[VID] vid_edt_open_silence_req_hdlr()")
    TRC_MSG(VID_TRC_EDT_CLOSE_SILENCE_REQ_HDLR, "[VID] vid_edt_close_silence_req_hdlr()")
    TRC_MSG(VID_TRC_EDT_FREE_RESOURCE, "[VID] vid_edt_free_resource()")
    TRC_MSG(VID_TRC_EDT_ENC_OPEN_REQ_HDLR, "[VID] vid_edt_enc_open_req_hdlr()")
    TRC_MSG(VID_TRC_EDT_ENC_CLOSE_REQ_HDLR, "[VID] vid_edt_enc_close_req_hdlr()") 
    TRC_MSG(VID_TRC_EDT_ENC_APPEND_REQ_HDLR, "[VID] vid_edt_enc_append_req_hdlr()")     


    /* vid calling driver */
    TRC_MSG(VID_TRC_CALLING_MP4_AUDIO_READ, "[VID] calling: MP4_Audio_Read(), line: %d")
    TRC_MSG(VID_TRC_CALLING_MP4_AUDIO_SEEK, "[VID] calling: MP4_Audio_Seek(), line: %d, frame: %d")    
    TRC_MSG(VID_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, "[VID] calling: MP4_Video_GetAvailableDur(), line: %d")
    TRC_MSG(VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, "[VID] calling: MP4_Audio_GetAvailableDur(), line: %d")
    TRC_MSG(VID_TRC_CALLING_MP4_VIDEO_FRAME_AVAILABLE, "[VID] calling: MP4_Video_FrameAvailable(), line: %d")    
    TRC_MSG(VID_TRC_CALLING_DEC_PUT_FRAME_TO_BUFFER, "[VID] calling: video_dec_put_frame_to_buffer(), line: %d")
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_PLAY, "[VID] calling: video_dec_play(), line: %d")
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_RECOVER, "[VID] calling: video_dec_recover(), line: %d")
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_SEEK, "[VID] calling: video_dec_seek(), time: %d, line: %d")    
    TRC_MSG(VID_TRC_CALLING_VIDEO_MEMORYMODE_OPEN, "[VID] calling: video_memorymode_open(), width: %d, height: %d")    
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_CLIP_INITIALIZE, "[VID] calling: video_dec_clip_initialize(), line: %d")    
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_PDL_INITIALIZE, "[VID] calling: video_dec_clip_initialize(), line: %d")  
    TRC_MSG(VID_TRC_CALLING_AUD_BT_A2DP_OPEN_CODEC, "[VID] calling: aud_bt_a2dp_open_codec(), line: %d")            
    TRC_MSG(VID_TRC_CALLING_AUD_BT_A2DP_CLOSE_CODEC_IND, "[VID] calling: aud_bt_a2dp_close_codec_ind(), line: %d")    
    TRC_MSG(VID_TRC_CALLING_MEDIA_STOP, "[VID] calling: Media_Stop(), line: %d")        
    TRC_MSG(VID_TRC_CALLING_MEDIA_PLAY, "[VID] calling: Media_Play(), line: %d")    
    TRC_MSG(VID_TRC_CALLING_MEDIA_PAUSE, "[VID] calling: Media_Pause(), line: %d") 
    TRC_MSG(VID_TRC_CALLING_MEDIA_RESUME, "[VID] calling: Media_Resume(), line: %d") 
    TRC_MSG(VID_TRC_CALLING_MEDIA_RECORD, "[VID] calling: Media_Record(), line: %d")     
    
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_GET_PLAY_TIME, "[VID] calling: video_dec_get_play_time(), line: %d")    
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_SET_DISPLAY, "[VID] calling: video_dec_set_display(), flag: %d, line: %d")    
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_SET_AUDIO, "[VID] calling: video_dec_set_audio(), flag: %d, line: %d")        
    TRC_MSG(VID_TRC_CALLING_MP4_AUDIO_TIMETOSAMPLENO, "[VID] calling: MP4_Audio_TimeToSampleNo(), cur_time: %d, line: %d")        
    TRC_MSG(VID_TRC_CALLING_VIDEO_DEC_DISPLAY, "[VID] calling: video_dec_display(), line: %d")            
    TRC_MSG(VID_TRC_CALLING_AUD_BT_CLOSE_CODEC_FOR_OPEN, "[VID] calling: aud_bt_a2dp_close_codec_for_open(), line: %d")            
    TRC_MSG(VID_TRC_CALLING_MP4_ISPDPROFILE, "[VID] calling: MP4_IsPDProfile(), line: %d") 


    /* MED's trace in MMI task */
    TRC_MSG(VID_MMI_TRC_CUR_TIME, "[VID_MMI] cur_time: %d, line: %d") 

    /* mp4 parser ret */
    TRC_MSG(VID_TRC_MP4_PARSER_OK, "[MP4 Parser] result: MP4_PARSER_OK, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_FILE_READ_ERROR, "[MP4 Parser] result: MP4_PARSER_FILE_READ_ERROR, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_FILE_SEEK_ERROR, "[MP4 Parser] result: MP4_PARSER_FILE_SEEK_ERROR, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_FILE_ACCESS_ERROR, "[MP4 Parser] result: MP4_PARSER_FILE_ACCESS_ERROR, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_PARSE_ERROR, "[MP4 Parser] result: MP4_PARSER_PARSE_ERROR, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_PARSE_TRAK_ERROR, "[MP4 Parser] result: MP4_PARSER_PARSE_TRAK_ERROR, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_ATOM_NOT_FOUND, "[MP4 Parser] result: MP4_PARSER_ATOM_NOT_FOUND, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_ES_DESCR_TAG_EXPECTED, "[MP4 Parser] result: MP4_PARSER_ES_DESCR_TAG_EXPECTED, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_BITR_BOX_EXPECTED, "[MP4 Parser] result: MP4_PARSER_BITR_BOX_EXPECTED, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_D263_BOX_EXPECTED, "[MP4 Parser] result: MP4_PARSER_D263_BOX_EXPECTED, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_DAMR_BOX_EXPECTED, "[MP4 Parser] result: MP4_PARSER_DAMR_BOX_EXPECTED, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_64BIT_NOT_SUPPORT, "[MP4 Parser] result: MP4_PARSER_64BIT_NOT_SUPPORT, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_LARGER_31BIT_NOT_SUPPORT, "[MP4 Parser] result: MP4_PARSER_LARGER_31BIT_NOT_SUPPORT, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_TOO_MANY_TRACKS, "[MP4 Parser] result: MP4_PARSER_TOO_MANY_TRACKS, line: %d")  
    TRC_MSG(VID_TRC_MP4_PARSER_EXTERNAL_DATA_REFERENCE, "[MP4 Parser] result: MP4_PARSER_EXTERNAL_DATA_REFERENCE, line: %d")  
    TRC_MSG(VID_TRC_MP4_PARSER_AUDIO_TOO_MANY_CHANNEL, "[MP4 Parser] result: MP4_PARSER_AUDIO_TOO_MANY_CHANNEL, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT, "[MP4 Parser] result: MP4_PARSER_SCALABLE_STREAM_NOT_SUPPORT, line: %d")      
    TRC_MSG(VID_TRC_MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT, "[MP4 Parser] result: MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT, line: %d")           
    TRC_MSG(VID_TRC_MP4_PARSER_960_120_IMDCT_NOT_SUPPORT, "[MP4 Parser] result: MP4_PARSER_960_120_IMDCT_NOT_SUPPORT, line: %d")           
    TRC_MSG(VID_TRC_MP4_PARSER_NO_MOOV, "[MP4 Parser] result: MP4_PARSER_NO_MOOV, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_NO_MVHD, "[MP4 Parser] result: MP4_PARSER_NO_MVHD, line: %d")   
    TRC_MSG(VID_TRC_MP4_PARSER_NO_TRAK, "[MP4 Parser] result: MP4_PARSER_NO_TRAK, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_NO_TKHD, "[MP4 Parser] result: MP4_PARSER_NO_TKHD, line: %d")    
    TRC_MSG(VID_TRC_MP4_PARSER_NO_MDIA, "[MP4 Parser] result: MP4_PARSER_NO_MDIA, line: %d")   
    TRC_MSG(VID_TRC_MP4_PARSER_NO_MDHD, "[MP4 Parser] result: MP4_PARSER_NO_MDHD, line: %d")  
    TRC_MSG(VID_TRC_MP4_PARSER_NO_HDLR, "[MP4 Parser] result: MP4_PARSER_NO_HDLR, line: %d")      
    TRC_MSG(VID_TRC_MP4_PARSER_NO_MINF, "[MP4 Parser] result: MP4_PARSER_NO_MINF, line: %d")    
    TRC_MSG(VID_TRC_MP4_PARSER_NO_STBL, "[MP4 Parser] result: MP4_PARSER_NO_STBL, line: %d") 
    TRC_MSG(VID_TRC_MP4_PARSER_NO_STSD, "[MP4 Parser] result: MP4_PARSER_NO_STSD, line: %d") 
    TRC_MSG(VID_TRC_MP4_PARSER_NO_STTS, "[MP4 Parser] result: MP4_PARSER_NO_STTS, line: %d")    
    TRC_MSG(VID_TRC_MP4_PARSER_NO_STSC, "[MP4 Parser] result: MP4_PARSER_NO_STSC, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_NO_STCO, "[MP4 Parser] result: MP4_PARSER_NO_STCO, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_WARNING_TRAILING_GARBAGE, "[MP4 Parser] result: MP4_PARSER_WARNING_TRAILING_GARBAGE, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_READ_EOF, "[MP4 Parser] result: MP4_PARSER_READ_EOF, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_NO_SUCH_TRACK, "[MP4 Parser] result: MP4_PARSER_NO_SUCH_TRACK, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_INVALID_ARGUMENT, "[MP4 Parser] result: MP4_PARSER_INVALID_ARGUMENT, line: %d")   
    TRC_MSG(VID_TRC_MP4_PARSER_INTERNAL_ERROR, "[MP4 Parser] result: MP4_PARSER_INTERNAL_ERROR, line: %d")
    TRC_MSG(VID_TRC_MP4_PARSER_NO_SUCH_SAMPLE, "[MP4 Parser] result: MP4_PARSER_NO_SUCH_SAMPLE, line: %d")
    TRC_MSG(VID_TRC_MP4_UNKNOWN_ENUM, "[MP4 Parser] result: UNKNOWN ENUM [%d] !!Plz add new trace, line: %d")

    /* aud drv ret */
    TRC_MSG(AUD_TRC_DRV_MEDIA_SUCCESS, "[AUD DRV] result: MEDIA_SUCCESS, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_FAIL, "[AUD DRV] result: MEDIA_FAIL, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_REENTRY, "[AUD DRV] result: MEDIA_REENTRY, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_NOT_INITIALIZED, "[AUD DRV] result: MEDIA_NOT_INITIALIZED, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_BAD_FORMAT, "[AUD DRV] result: MEDIA_BAD_FORMAT, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_BAD_PARAMETER, "[AUD DRV] result: MEDIA_BAD_PARAMETER, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_BAD_COMMAND, "[AUD DRV] result: MEDIA_BAD_COMMAND, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_NO_HANDLER, "[AUD DRV] result: MEDIA_NO_HANDLER, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_UNSUPPORTED_CHANNEL, "[AUD DRV] result: MEDIA_UNSUPPORTED_CHANNEL, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_UNSUPPORTED_FREQ, "[AUD DRV] result: MEDIA_UNSUPPORTED_FREQ, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_UNSUPPORTED_TYPE, "[AUD DRV] result: MEDIA_UNSUPPORTED_TYPE, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_UNSUPPORTED_OPERATION, "[AUD DRV] result: MEDIA_UNSUPPORTED_OPERATION, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_SEEK_FAIL, "[AUD DRV] result: MEDIA_SEEK_FAIL, line: %d")
    TRC_MSG(AUD_TRC_DRV_MEDIA_SEEK_EOF, "[AUD DRV] result: MEDIA_SEEK_EOF, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_READ_FAIL, "[AUD DRV] result: MEDIA_READ_FAIL, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_WRITE_FAIL, "[AUD DRV] result: MEDIA_WRITE_FAIL, line: %d")    
    TRC_MSG(AUD_TRC_DRV_MEDIA_DISK_FULL, "[AUD DRV] result: MEDIA_DISK_FULL, line: %d")        
    TRC_MSG(AUD_TRC_DRV_MEDIA_MERGE_TYPE_MISMATCH, "[AUD DRV] result: MEDIA_MERGE_TYPE_MISMATCH, line: %d") 
    TRC_MSG(AUD_TRC_DRV_UNKNOWN_ENUM, "[AUD DRV] result: UNKNOWN ENUM [%d] !!Plz add new trace, line: %d")

    /* vid drv ret */
    TRC_MSG(VID_TRC_DRV_MEDIA_STATUS_OK, "[VID DRV] result: MEDIA_STATUS_OK, line: %d")
    TRC_MSG(VID_TRC_DRV_MP4_PARSER_ERROR, "[VID DRV] result: MP4_PARSER_ERROR, line: %d")
    TRC_MSG(VID_TRC_DRV_VIDEO_ERROR, "[VID DRV] result: VIDEO_ERROR, line: %d")
    TRC_MSG(VID_TRC_DRV_AUDIO_ERROR, "[VID DRV] result: AUDIO_ERROR, line: %d")    
    TRC_MSG(VID_TRC_DRV_FSAL_ERROR, "[VID DRV] result: FSAL_ERROR, line: %d")        
    TRC_MSG(VID_TRC_DRV_FSAL_READ_EOF, "[VID DRV] result: FSAL_READ_EOF, line: %d")
    TRC_MSG(VID_TRC_DRV_FSAL_SEEK_EOF, "[VID DRV] result: FSAL_SEEK_EOF, line: %d")
    TRC_MSG(VID_TRC_DRV_FS_ERROR, "[VID DRV] result: FS_ERROR, line: %d")    
    TRC_MSG(VID_TRC_DRV_MP4_PRODUCER_ERROR, "[VID DRV] result: MP4_PRODUCER_ERROR, line: %d")        
    TRC_MSG(VID_TRC_DRV_MP4_SAMPLEDATA_ERROR, "[VID DRV] result: MP4_SAMPLEDATA_ERROR, line: %d")            
    TRC_MSG(VID_TRC_DRV_NO_VISUAL_TRACK, "[VID DRV] result: NO_VISUAL_TRACK, line: %d")
    TRC_MSG(VID_TRC_DRV_UNKNOWN_ENUM, "[VID DRV] result: UNKNOWN ENUM [%d] !!Plz add new trace, line: %d")

    /* video drv decode event */
    TRC_MSG(VID_TRC_VIDEO_DEC_EVENT_BUFFER_EMPTY, "[VID DRV] dec_event: VIDEO_DEC_EVENT_BUFFER_EMPTY, line: %d")  
    TRC_MSG(VID_TRC_VIDEO_DEC_EVENT_COMPLETE, "[VID DRV] dec_event: VIDEO_DEC_EVENT_COMPLETE, line: %d")  
    TRC_MSG(VID_TRC_VIDEO_DEC_EVENT_SEEK_PARTIAL_DONE, "[VID DRV] dec_event: VIDEO_DEC_EVENT_SEEK_PARTIAL_DONE, line: %d")  
    TRC_MSG(VID_TRC_VIDEO_DEC_EVENT_SEEK_DONE, "[VID DRV] dec_event: VIDEO_DEC_EVENT_SEEK_DONE, line: %d")  
    TRC_MSG(VID_TRC_VIDEO_DEC_EVENT_NO_TRACK, "[VID DRV] dec_event: VIDEO_DEC_EVENT_NO_TRACK, line: %d")   
    TRC_MSG(VID_TRC_VIDEO_DEC_EVENT_FAIL, "[VID DRV] dec_event: VIDEO_DEC_EVENT_FAIL, line: %d")    
    TRC_MSG(VID_TRC_VIDEO_DEC_RECOVER, "[VID DRV] dec_event: VIDEO_DEC_RECOVER, line: %d")      
    TRC_MSG(VID_TRC_VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE, "[VID DRV] dec_event: VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE, line: %d")  
    TRC_MSG(VID_TRC_VIDEO_DEC_DRV_SEEK_ACTION, "[VID DRV] dec_event: VIDEO_DEC_DRV_SEEK_ACTION, line: %d")  
    TRC_MSG(MED_TRC_VIDEO_DEC_UNKNOWN_ENUM, "[MED] dec_event: UNKNOWN ENUM [%d] !!Plz add new trace, line: %d")  

    /* vis calling driver */
    TRC_MSG(VIS_TRC_CALLING_VIDEO_DEC_PUT_FRAME_TO_BUFFER, "[VIS] calling: video_dec_put_frame_to_buffer(), line: %d, ret: %d")
    TRC_MSG(VIS_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, "[VIS] calling: MP4_Video_GetAvailableDur(), line: %d, ret: %d, time: %d")

    /* vis misc */
    TRC_MSG(VIS_TRC_DECODE_EVENT, "[VIS] event: %d")    

    /* vis function */
    TRC_MSG(VIS_TRC_SEND_PLAY_FINISH_IND, "[VIS] vis_send_play_finish_ind()")
    TRC_MSG(VIS_TRC_DECODE_DATA_IND_HDLR, "[VIS] vis_decode_visual_data_ind_hdlr()")    
        
    /* vis state */
    TRC_MSG(VIS_TRC_VIS_STATE_VISUAL_IDLE, "[VIS] vis_state: VISUAL_IDLE")   
    TRC_MSG(VIS_TRC_VIS_STATE_VISUAL_PLAY, "[VIS] vis_state: VISUAL_PLAY")       
    TRC_MSG(VIS_TRC_VIS_STATE_VISUAL_RECORD, "[VIS] vis_state: VISUAL_RECORD")
    
    /* aud media */
    TRC_MSG(AUD_MED_TRC_WRITE_DATA_IND_HDLR, "[AUD_MED] aud_media_write_data_ind_hdlr()")
    
    TRC_MSG(AUD_MED_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, "[AUD_MED] calling: MP4_Audio_GetAvailableDur(), line: %d, ret: %d, time: %d")
    TRC_MSG(AUD_MED_TRC_CALLING_MP4_AUDIO_READ, "[AUD_MED] calling: MP4_Audio_Read(), line: %d, ret: %d")


    /* MED_AVI V2 */
    TRC_MSG(VID_TRC_RELEASE_RECORDER_MEMORY, "[VID] vid_release_recorder_memory()")      
    TRC_MSG(VID_TRC_STOP_CAMERA_PREVIEW, "[VID] vid_stop_camera_preview()")          

    TRC_MSG(VID_TRC_AUDIO_RECORD_CALLBACK, "[VID] vid_audio_record_callback(), event: %d")      
    TRC_MSG(VID_TRC_WRITE_AUDIO, "[VID] vid_write_audio()") 
    TRC_MSG(VID_TRC_RECORD_AUDIO, "[VID] vid_record_audio()") 
    TRC_MSG(VID_TRC_STOP_AUDIO_PLAY, "[VID] vid_stop_audio_play()")   
    TRC_MSG(VID_TRC_STOP_AUDIO_RECORD, "[VID] vid_stop_audio_record()")         
    TRC_MSG(VID_TRC_OPEN_AVI_RECORD_FILE, "[VID] vid_open_avi_record_file()")  
    TRC_MSG(VID_TRC_CLOSE_AVI_RECORD_FILE, "[VID] vid_close_avi_record_file()")  
    TRC_MSG(VID_TRC_START_VIDEO_RECORD, "[VID] vid_start_video_record()")  
    TRC_MSG(VID_TRC_FETCH_DATA_HANDLER, "[VID] vid_fetch_data_handler()")  
    TRC_MSG(VID_TRC_SEND_MJPEG_ENCODE_IND, "[VID] vid_send_mjpeg_encode_ind()") 
    TRC_MSG(VID_TRC_STOP_VIDEO_RECORD, "[VID] vid_stop_video_record()")     
    TRC_MSG(VID_TRC_PAUSE_VIDEO_RECORD, "[VID] vid_pause_video_record()")         
    TRC_MSG(VID_TRC_RESUME_VIDEO_RECORD, "[VID] vid_resume_video_record()")      
    TRC_MSG(VID_TRC_PREVIEW_CHECK, "[VID] vid_preview_check()")    
    TRC_MSG(VID_TRC_RELEASE_PLAYER_MEMORY, "[VID] vid_release_player_memory()")        
    TRC_MSG(VID_TRC_DECODE_IMAGE_CALLBACK, "[VID] vid_decode_image_callback(), cause: %d")   
    TRC_MSG(VID_TRC_OPEN_AUDIO, "[VID] vid_open_audio()")  
    TRC_MSG(VID_TRC_CLOSE_AUDIO, "[VID] vid_close_audio()")      

    TRC_MSG(VID_TRC_IS_JPG_ENCODNG, "[VID] is_jpeg_encoding: %d ")  

    TRC_MSG(VID_TRC_CALLING_MJPEG_ENCODE_START, "[VID] calling: mjpeg_encode_start()")                
    TRC_MSG(VID_TRC_CALLING_JPEG_ENCODE_PROCESS, "[VID] calling: jpeg_encode_process(), line: %d")            
    TRC_MSG(VID_TRC_CALLING_MJPEG_ENCODE_PROCESS, "[VID] calling: mjpeg_encode_process(), line: %d")            
    TRC_MSG(VID_TRC_CALLING_EXT_CAMERA_VIDEO_CLIP, "[VID] calling: ext_cam_video_clip(), line: %d")
    TRC_MSG(VID_TRC_CALLING_EXIT_EXT_CAMERA_PREVIEW, "[VID] calling: ext_cam_stop_preview(), line: %d")
    TRC_MSG(VID_TRC_CALLING_EXT_CAMERA_READY_CHECK, "[VID] calling: ext_cam_is_preview_ready(), line: %d")
    TRC_MSG(VID_TRC_CALLING_EXT_CAMERA_POWER_OFF, "[VID] calling: ext_cam_power_off(), line: %d")
    TRC_MSG(VID_TRC_CALLING_EXT_CAMERA_POWER_ON, "[VID] calling: ext_cam_power_on(), line: %d")
    TRC_MSG(VID_TRC_CALLING_EXIT_MJPEG_ENCODE_PROCESS, "[VID] calling: exit_mjpeg_encode_process(), line: %d")                 
    TRC_MSG(VID_TRC_CALLING_GET_MJPEG_FRAME_RATE, "[VID] calling: get_mjpeg_frame_rate(), line: %d") 
    TRC_MSG(VID_TRC_CALLING_MJPG_ENCODE_PAUSE, "[VID] calling: mjpeg_encode_pause(), line: %d") 
    TRC_MSG(VID_TRC_CALLING_MJPG_ENCODE_RESUME, "[VID] calling: mjpeg_encode_resume(), line: %d")     
    TRC_MSG(VID_TRC_CALLING_START_JPEG_VIDEO_PLAY, "[VID] calling: start_jpeg_video_play(), line: %d")    
    TRC_MSG(VID_TRC_CALLING_STOP_JPEG_VIDEO_PLAY, "[VID] calling: stop_jpeg_video_play(), line: %d")    

    TRC_MSG(VID_TRC_MJPEG_ENCODE_EVENT_IND_HDLR, "[VID] vid_mjpeg_encode_event_ind_hdlr()")  

    TRC_MSG(VID_TRC_CAMERA_RETRY_COUNT, "[VID] retry_count: %d, check_count: %d, line: %d")   

    /* AVI */
    TRC_MSG(AVI_TRC_OPEN_PLAY_INTERNAL, "[AVI] med_avi_open_play_internal()")    

    TRC_MSG(AVI_TRC_PARSE_FILE_HEADER, "[AVI] Parse File Header")   
    TRC_MSG(AVI_TRC_PARSE_FILE_HEADER_DONE, "[VID] Parse File Header - Done")  
    TRC_MSG(AVI_TRC_PARSE_VID_HEADER, "[AVI] Parse VID Header")     
    TRC_MSG(AVI_TRC_PARSE_VID_HEADER_DONE, "[AVI] Parse VID Header - Done")         
    TRC_MSG(AVI_TRC_PARSE_AUD_HEADER, "[AVI] Parse AUD Header")     
    TRC_MSG(AVI_TRC_PARSE_AUD_HEADER_DONE, "[AVI] Parse AUD Header - Done")    
    TRC_MSG(AVI_TRC_PARSE_AUD_ON, "[AVI] Aud: on")  
    TRC_MSG(AVI_TRC_PARSE_AUD_OFF, "[AVI] Aud: off")      
    TRC_MSG(AVI_TRC_PARSE_MOVI, "[AVI] Parse MOVI")    
    TRC_MSG(AVI_TRC_PARSE_MOVI_DONE, "[AVI] Parse MOVI - Done")        
    TRC_MSG(AVI_TRC_PARSE_FINISH, "[AVI] Parse finish")            
    TRC_MSG(AVI_TRC_AUD_SAMPLE_RATE, "[AVI] aud_sample_rate: %d")   
    TRC_MSG(AVI_TRC_AUD_CHANNEL, "[AVI] aud_channel: %d")
    TRC_MSG(AVI_TRC_AUD_BIT_PER_SAMPLE, "[AVI] aud_bit_per_sample: %d")
    TRC_MSG(AVI_TRC_AUD_FRAME, "[AVI] aud_frame: %d")    
    TRC_MSG(AVI_TRC_VID_FPS, "[AVI] vid_fps: %d")
    TRC_MSG(AVI_TRC_VID_WIDTH, "[AVI] vid_width: %d")
    TRC_MSG(AVI_TRC_VID_HEIGHT, "[AVI] vid_height: %d")
    TRC_MSG(AVI_TRC_VID_DURATION_IN_MS, "[AVI] vid_duration_in_ms: %d")    
    TRC_MSG(AVI_TRC_VID_RATE, "[AVI] vid_rate: %d")
    TRC_MSG(AVI_TRC_VID_SCALE, "[AVI] vid_scale: %d")
    TRC_MSG(AVI_TRC_VID_FRAME, "[AVI] vid_frame: %d")
    
    /* Mobile TV */

    TRC_MSG(MTV_TRC_BEFORE, "[MTV] >>> %Mmtv_debug_event_t")
    TRC_MSG(MTV_TRC_AFTER,  "[MTV] <<< %Mmtv_debug_event_t")
    TRC_MSG(MTV_TRC_EVENT,  "[MTV] *** %Mmtv_debug_event_t")

    TRC_MSG(MTV_TRC_DEMUX_OPENING, "[MTV][DEMUX] opening")
    TRC_MSG(MTV_TRC_DEMUX_OPENED, "[MTV][DEMUX] opened")
    TRC_MSG(MTV_TRC_DEMUX_SENDING, "[MTV][DEMUX] sending %d bytes to demux")
    TRC_MSG(MTV_TRC_DEMUX_SENT, "[MTV][DEMUX] %d bytes sent")
    TRC_MSG(MTV_TRC_DEMUX_ON_AUDIO_STREAM, "[MTV][DEMUX] audio stream is found")
    TRC_MSG(MTV_TRC_DEMUX_ON_VIDEO_STREAM, "[MTV][DEMUX] video stream is found")
    TRC_MSG(MTV_TRC_DEMUX_ON_STREAM_DATA, "[MTV][DEMUX] %d bytes data (time:%u) from stream #%d")
    TRC_MSG(MTV_TRC_DEMUX_ON_STATUS, "[MTV][DEMUX] CL demux status = %MCL_Status")
    TRC_MSG(MTV_TRC_DEMUX_CLOSING, "[MTV][DEMUX] closing demux")
    TRC_MSG(MTV_TRC_DEMUX_CLOSED, "[MTV][DEMUX] closed")
    TRC_MSG(MTV_TRC_DEMUX_ERROR, "[MTV][DEMUX] some error happened!")
    TRC_MSG(MTV_TRC_DEMUX_INVALID_TS_PACKET, "[MTV][DEMUX] Invalid MPEG-2 TS packet!")
    TRC_MSG(MTV_TRC_DEMUX_PACKET, "[MTV][DEMUX] Demuxed packet from stream (%u): size = %u, time = %u")
    TRC_MSG(MTV_TRC_DEMUX_TOTAL_STREAMS, "[MTV][DEMUX] # streams = %d")

    TRC_MSG(MTV_TRC_OPEN, "[MTV] open service manager")
    TRC_MSG(MTV_TRC_CONFIG, "[MTV] configure service manager")
    TRC_MSG(MTV_TRC_SEARCH_SERVICES, "[MTV] search services, source:%Mmedia_mtv_service_source_enum")
    TRC_MSG(MTV_TRC_ABORT_SEARCHING, "[MTV] abort service searching")
    TRC_MSG(MTV_TRC_START_SERVICE, "[MTV] start service, service_id:0x%x, activities:%d")
    TRC_MSG(MTV_TRC_SERVICE_EVENT, "[MTV] service event = %Mmtv_spi_event_t")
    TRC_MSG(MTV_TRC_UNSUPPORTED_SERVICE_TYPE, "[MTV] unsupported service type: %Mdab_application_type_t")

    TRC_MSG(MTV_TRC_TDMB_RESTART_SERVICE, "[MTV] restarting DAB/T-DMB service, service_id:0x%x")

    TRC_MSG(MTV_TRC_BE_OPEN, "[MTV][BE] open buffer engine")
    TRC_MSG(MTV_TRC_BE_ADD_STREAM, "[MTV][BE] add stream (type = %Mmtv_stream_type_t)")
    TRC_MSG(MTV_TRC_BE_WRITE_PACKET, "[MTV][BE] write packet #%d (%d bytes) to stream #%d")
    TRC_MSG(MTV_TRC_BE_READ_PACKET, "[MTV][BE] read packet")
    TRC_MSG(MTV_TRC_BE_SET_DELAY, "[MTV][BE] set buffer delay to %d seconds")
    TRC_MSG(MTV_TRC_BE_DISCARD_ALL, "[MTV] discard all content in time-shift buffer")
    TRC_MSG(MTV_TRC_BE_SET_PAUSE, "[MTV][BE] set buffer pause to %d")
    TRC_MSG(MTV_TRC_BE_SAVING, "[MTV][BE] saving time-shift buffer to file")
    TRC_MSG(MTV_TRC_BE_SAVED, "[MTV][BE] saving time-shift buffer is done")
    TRC_MSG(MTV_TRC_BE_SETTING_MAX_SIZE, "[MTV][BE] setting max buffer size to be %u KB")
    TRC_MSG(MTV_TRC_BE_MAX_SIZE_APPLIED, "[MTV][BE] max buffer size %u KB is applied")
    TRC_MSG(MTV_TRC_BE_CLOSE, "[MTV][BE] close buffer engine")
    TRC_MSG(MTV_TRC_BE_STATE, "[MTV][BE] state = %Mmtv_buffer_engine_read_state_t")
    TRC_MSG(MTV_TRC_BE_TIMESTAMP_BASE, "[MTV][BE] timestamp base is set to %u")

    TRC_MSG(MTV_TRC_START_PLAYER, "[MTV] start player, service_id:0x%x")
    TRC_MSG(MTV_TRC_STOP_PLAYER, "[MTV] stop player, service_id:0x%x")
    TRC_MSG(MTV_TRC_START_RECORDER, "[MTV] start recorder, service_id:0x%x")
    TRC_MSG(MTV_TRC_STOP_RECORDER, "[MTV] stop recorder, service_id:0x%x")

    TRC_MSG(MTV_TRC_RECORDER_STARTING, "[MTV][REC] starting recorder")
    TRC_MSG(MTV_TRC_RECORDER_STARTED, "[MTV][REC] recorder started")
    TRC_MSG(MTV_TRC_RECORDER_STOPPING, "[MTV][REC] stopping recorder")
    TRC_MSG(MTV_TRC_RECORDER_STOPPED, "[MTV][REC] recorder stopped")
    TRC_MSG(MTV_TRC_RECORDER_SAVING, "[MTV][REC] saving recorded program")
    TRC_MSG(MTV_TRC_RECORDER_SAVED, "[MTV][REC] recorded program saved")
    TRC_MSG(MTV_TRC_RECORDER_ERROR, "[MTV][REC] recorded error = %d")
    TRC_MSG(MTV_TRC_RECORDER_SAVING_CHECKPOINT, "[MTV][REC] saving checkpoint")
    TRC_MSG(MTV_TRC_RECORDER_CHECKPOINT_SAVED, "[MTV][REC] checkpoint saved")
    TRC_MSG(MTV_TRC_RECORDER_RECOVERING_FAILED, "[MTV][REC] failed to recover recording, error = %d")

    TRC_MSG(MTV_TRC_AUDIO_ERROR, "[MTV] audio decoder error = %d")
    TRC_MSG(MTV_TRC_VIDEO_ERROR, "[MTV] video decoder error = %d")
    TRC_MSG(MTV_TRC_STOP_SERVICE, "[MTV] stop service, service_id:0x%x")
    TRC_MSG(MTV_TRC_CLOSE, "[MTV] close service manager")

    TRC_MSG(MTV_TRC_DEMOD_ERROR, "[MTV][DEMOD] demodulator error = 0x%x")
    TRC_MSG(MTV_TRC_DEMOD_OPENING, "[MTV][DEMOD] opening demodulator")
    TRC_MSG(MTV_TRC_DEMOD_OPENED, "[MTV][DEMOD] demodulator opened")
    TRC_MSG(MTV_TRC_DEMOD_SCANNING, "[MTV][DEMOD] scanning available services")
    TRC_MSG(MTV_TRC_DEMOD_SCANNED, "[MTV][DEMOD] available services are scanned")
    TRC_MSG(MTV_TRC_DEMOD_TUNING, "[MTV][DEMOD] tuning to band:%d and frequency:%d")
    TRC_MSG(MTV_TRC_DEMOD_BAND_TUNED, "[MTV][DEMOD] band tuned")
    TRC_MSG(MTV_TRC_DEMOD_FREQUENCY_TUNED, "[MTV][DEMOD] frequency tuned")
    TRC_MSG(MTV_TRC_DEMOD_STARTING_SERVICE, "[MTV][DEMOD] start service 0x%x")
    TRC_MSG(MTV_TRC_DEMOD_SERVICE_STARTED, "[MTV][DEMOD] service started")
    TRC_MSG(MTV_TRC_DEMOD_STOPPING_SERVICE, "[MTV][DEMOD] stop service 0x%x")
    TRC_MSG(MTV_TRC_DEMOD_SERVICE_STOPPED, "[MTV][DEMOD] service stopped")
    TRC_MSG(MTV_TRC_DEMOD_RECONFIG, "[MTV][DEMOD] reconfiguration happened, code = %d")
    TRC_MSG(MTV_TRC_DEMOD_SERVICE_ANNOUNCEMENT, "[MTV][DEMOD] announcement has arrived")
    TRC_MSG(MTV_TRC_DEMOD_GET_DATA, "[MTV][DEMOD] Get data %d bytes")
    TRC_MSG(MTV_TRC_DEMOD_CLOSE, "[MTV][DEMOD] close demodulator")

    /* END - Mobile TV */

    /* Video Call Function */
    TRC_MSG(VCALL_TRC_VCALL_INIT, "[VCALL] vcall_init()")
    TRC_MSG(VCALL_TRC_SEND_VIDEO_CODEC_OPEN_REQ, "[VCALL] vcall_send_video_codec_open_req()")
    TRC_MSG(VCALL_TRC_SEND_VIDEO_CODEC_CLOSE_REQ, "[VCALL] vcall_send_video_codec_close_req()")
    TRC_MSG(VCALL_TRC_SEND_CHANNEL_REPORT_IND, "[VCALL] vcall_send_channel_report_ind()")
    TRC_MSG(VCALL_TRC_SEND_CHANNEL_STATUS_IND, "[VCALL] vcall_send_channel_status_ind()")    
    TRC_MSG(VCALL_TRC_SEND_VIDEO_REPLENISH_DATA_READY_IND, "[VCALL] vcall_send_video_replenish_data_ready_ind()")  
    TRC_MSG(VCALL_TRC_SEND_VIDEO_ENCODE_DATA_READY_IND, "[VCALL] vcall_send_video_encode_data_ready_ind()")      
    TRC_MSG(VCALL_TRC_SEND_VIDEO_CODEC_REPORT_IND, "[VCALL] vcall_send_video_codec_report_ind(), event: %d, para: %d")
    TRC_MSG(VCALL_TRC_SET_RESULT, "[VCALL] media_vcall_set_result(), line: %d")          
    TRC_MSG(VCALL_TRC_PEER_VIDEO_FRAME_TIMEOUT_CALLBACK, "[VCALL] vcall_peer_video_frame_timeout_callback()")          
    TRC_MSG(VCALL_TRC_INIT_VIDEO_YUV_BUFFER, "[VCALL] vcall_init_video_yuv_buffer(), buffer_size: %d")   
    TRC_MSG(VCALL_TRC_DEINIT_VIDEO_YUV_BUFFER, "[VCALL] vcall_deinit_video_yuv_buffer()")   
    TRC_MSG(VCALL_TRC_GET_IN_VIDEO_DATA_STATE, "[VCALL] vcall_get_in_video_data_state()")       
    TRC_MSG(VCALL_TRC_VIDEO_SET_DECODE_DATA_PARA, "[VCALL] vcall_video_set_decode_data_para()")       
    TRC_MSG(VCALL_TRC_DISPLAY_CALLBACK, "[VCALL] vcall_display_callback()")       
    TRC_MSG(VCALL_TRC_CONFIG_IMAGE_DATA_PATH, "[VCALL] vcall_config_image_data_path()")  
    TRC_MSG(VCALL_TRC_CLOSE_IMAGE_DATA_PATH, "[VCALL] vcall_close_image_data_path()")      
    TRC_MSG(VCALL_TRC_UPDATE_PEER_VIEW, "[VCALL] vcall_update_peer_view()")          
    TRC_MSG(VCALL_TRC_DECODE_NEXT_VIDEO_FRAME, "[VCALL] vcall_decode_next_video_frame()")
    TRC_MSG(VCALL_TRC_CONSUME_VIDEO_ENCODER, "[VCALL] vcall_consume_video_encoder()")    
    TRC_MSG(VCALL_TRC_OPEN_VIDEO_ENCODER, "[VCALL] vcall_open_video_encoder()")
    TRC_MSG(VCALL_TRC_CLOSE_VIDEO_ENCODER, "[VCALL] vcall_close_video_encoder()")
    TRC_MSG(VCALL_TRC_OPEN_VIDEO_DECODER, "[VCALL] vcall_open_video_decoder()")  
    TRC_MSG(VCALL_TRC_CLOSE_VIDEO_DECODER, "[VCALL] vcall_close_video_decoder()") 
    TRC_MSG(VCALL_TRC_START_VIDEO_DECODER, "[VCALL] vcall_start_video_decoder()") 
    TRC_MSG(VCALL_TRC_STOP_VIDEO_DECODER, "[VCALL] vcall_stop_video_decoder()")     
    TRC_MSG(VCALL_TRC_OPEN_SPEECH_CODEC, "[VCALL] vcall_open_speech_codec()")      
    TRC_MSG(VCALL_TRC_CLOSE_SPEECH_CODEC, "[VCALL] vcall_open_speech_codec()")    
    TRC_MSG(VCALL_TRC_VIDEO_CODEC_OPEN_REQ_HDLR, "[VCALL] vcall_video_codec_open_req_hdlr()")     
    TRC_MSG(VCALL_TRC_VIDEO_CODEC_CLOSE_REQ_HDLR, "[VCALL] vcall_video_codec_close_req_hdlr()")     
    TRC_MSG(VCALL_TRC_CHANNEL_STATUS_IND_HDLR, "[VCALL] vcall_channel_status_ind_hdlr()")    
    TRC_MSG(VCALL_TRC_VIDEO_REPLENISH_DATA_READY_IND_HDLR, "[VCALL] vcall_video_replenish_data_ready_ind_hdlr()")        
    TRC_MSG(VCALL_TRC_VIDEO_DECODE_DATA_READY_IND_HDLR, "[VCALL] vcall_video_decode_data_ready_ind_hdlr()") 
    TRC_MSG(VCALL_TRC_VIDEO_ENCODE_DATA_READY_IND_HDLR, "[VCALL] vcall_video_encode_data_ready_ind_hdlr()") 

    /* Video Call Calling */
    TRC_MSG(VCALL_TRC_CALLING_RESULT, "[VCALL] calling result: %d, line: %d")   
    TRC_MSG(VCALL_TRC_CALLING_FULLVIDEO_PROCESS, "[VCALL] calling: fullvideo_process(), line: %d") 
    TRC_MSG(VCALL_TRC_CALLING_EXIT_FULLVIDEO_PROCESS, "[VCALL] calling: exit_fullvideo_process(), line: %d")    
    TRC_MSG(VCALL_TRC_CALLING_IDP_FULLVIDEO_DECODE_DISPLAY, "[VCALL] calling: idp_fullvideo_decode_display(), line: %d")   
    TRC_MSG(VCALL_TRC_CALLING_IDP_YUV_MOVE_DONE, "[VCALL] calling: idp_fullvideo_yuv_move_done(), line: %d")       
    TRC_MSG(VCALL_TRC_CALLING_MED_VT_Q_QUERY, "[VCALL] calling: vt_med_query_downlink_video_Q_state(), line: %d")
    TRC_MSG(VCALL_TRC_CALLING_MED_VT_GET_FRAME, "[VCALL] calling: vt_med_get_downlink_video_Q_frame(), line: %d")    
    TRC_MSG(VCALL_TRC_CALLING_MED_VT_BUFF_CONSUME, "[VCALL] calling: vt_med_consume_downlink_video_Q_buff(), line: %d")        
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_GETNEXTPACKET, "[VCALL] calling: VideoCall_GetNextPacket(), line: %d")            
    TRC_MSG(VCALL_TRC_CALLING_VT_VIDEO_PUT_OUTGOING_DATA, "[VCALL] calling: vt_video_put_outgoing_data(), line: %d")            
    TRC_MSG(VCALL_TRC_CALLING_CONFIG_RGB2YUV420_DATA_PATH, "[VCALL] calling: config_RGB2YUV420_data_path(), line: %d")     
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_CFGENC, "[VCALL] calling: VideoCall_CfgEnc(), line: %d")
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_STARTENC, "[VCALL] calling: VideoCall_StartEnc(), line: %d")
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_STOPENC, "[VCALL] calling: VideoCall_StopEnc(), line: %d")
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_CLOSEENC, "[VCALL] calling: VideoCall_CloseEnc(), line: %d")    
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_CFGDEC, "[VCALL] calling: VideoCall_CfgDec(), line: %d")
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_CLOSEDEC, "[VCALL] calling: VideoCall_CloseDec(), line: %d")    
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_STARTDEC, "[VCALL] calling: VideoCall_StartDec(), line: %d") 
    TRC_MSG(VCALL_TRC_CALLING_VIDEOCALL_STOPDEC, "[VCALL] calling: VideoCall_StopDec(), line: %d") 
    TRC_MSG(VCALL_TRC_CALLING_L1_SPEECH_ON, "[VCALL] calling: L1SP_Speech_On(), line: %d") 
    TRC_MSG(VCALL_TRC_CALLING_L1_SPEECH_OFF, "[VCALL] calling: L1SP_Speech_Off(), line: %d") 

    /* Video Call Misc */
    TRC_MSG(VCALL_TRC_VIDEO_ENCODER_ENTER_STATE, "[VCALL] VIDEO_ENCODER enter state: %d, line: %d")
    TRC_MSG(VCALL_TRC_VIDEO_DECODER_ENTER_STATE, "[VCALL] VIDEO_DECODER enter state: %d, line: %d")
    TRC_MSG(VCALL_TRC_SPEECH_ENCODER_ENTER_STATE, "[VCALL] SPEECH_ENCODER enter state: %d, line: %d")
    TRC_MSG(VCALL_TRC_SPEECH_DECODER_ENTER_STATE, "[VCALL] SPEECH_DECODER enter state: %d, line: %d")

    TRC_MSG(VCALL_TRC_VID_DECODER_STATE_CLOSED, "[VCALL_EX] VID DECODER State: VCALL_CODEC_STATE_CLOSED, line: %d")          
    TRC_MSG(VCALL_TRC_VID_DECODER_STATE_PENDING, "[VCALL_EX] VID DECODER State: VCALL_CODEC_STATE_PENDING, line: %d")                   
    TRC_MSG(VCALL_TRC_VID_DECODER_STATE_OPEN, "[VCALL_EX] VID DECODER State: VCALL_CODEC_STATE_OPEN, line: %d")                    
    TRC_MSG(VCALL_TRC_VID_DECODER_STATE_DECODING, "[VCALL_EX] VID DECODER State: VCALL_CODEC_STATE_DECODING, line: %d")          
    TRC_MSG(VCALL_TRC_VID_DECODER_STATE_UNKNOWN, "[VCALL_EX] VID DECODER State: UNKNOWN, %d, line: %d")          

    TRC_MSG(VCALL_TRC_VID_ENCODER_STATE_CLOSED, "[VCALL_EX] VID ENCODER State: VCALL_CODEC_STATE_CLOSED, line: %d")                    
    TRC_MSG(VCALL_TRC_VID_ENCODER_STATE_PENDING, "[VCALL_EX] VID ENCODER State: VCALL_CODEC_STATE_PENDING, line: %d")                   
    TRC_MSG(VCALL_TRC_VID_ENCODER_STATE_OPEN, "[VCALL_EX] VID ENCODER State: VCALL_CODEC_STATE_OPEN, line: %d")                   
    TRC_MSG(VCALL_TRC_VID_ENCODER_STATE_UNKNOWN, "[VCALL_EX] VID ENCODER State: UNKNOWN, %d, line: %d")          

    TRC_MSG(VCALL_TRC_AUD_DECODER_STATE_CLOSED, "[VCALL_EX] AUD DECODER State: VCALL_CODEC_STATE_CLOSED, line: %d")          
    TRC_MSG(VCALL_TRC_AUD_DECODER_STATE_PENDING, "[VCALL_EX] AUD DECODER State: VCALL_CODEC_STATE_PENDING, line: %d")                   
    TRC_MSG(VCALL_TRC_AUD_DECODER_STATE_OPEN, "[VCALL_EX] AUD DECODER State: VCALL_CODEC_STATE_OPEN, line: %d")                    
    TRC_MSG(VCALL_TRC_AUD_DECODER_STATE_UNKNOWN, "[VCALL_EX] AUD DECODER State: UNKNOWN, %d, line: %d")        

    TRC_MSG(VCALL_TRC_AUD_ENCODER_STATE_CLOSED, "[VCALL_EX] AUD ENCODER State: VCALL_CODEC_STATE_CLOSED, line: %d")                    
    TRC_MSG(VCALL_TRC_AUD_ENCODER_STATE_PENDING, "[VCALL_EX] AUD ENCODER State: VCALL_CODEC_STATE_PENDING, line: %d")                   
    TRC_MSG(VCALL_TRC_AUD_ENCODER_STATE_OPEN, "[VCALL_EX] AUD ENCODER State: VCALL_CODEC_STATE_OPEN, line: %d")                   
    TRC_MSG(VCALL_TRC_AUD_ENCODER_STATE_UNKNOWN, "[VCALL_EX] AUD ENCODER State: UNKNOWN, %d, line: %d")          

    TRC_MSG(VCALL_TRC_PEER_VIEW_TYPE_HIDE, "[VCALL_EX] Peer Type: VCALL_VIEW_HIDE, line: %d")                
    TRC_MSG(VCALL_TRC_PEER_VIEW_TYPE_SHOW_IMAGE, "[VCALL_EX] Peer Type: VCALL_VIEW_SHOW_IMAGE, line: %d")          
    TRC_MSG(VCALL_TRC_PEER_VIEW_TYPE_SHOW_VIDEO, "[VCALL_EX] Peer Type: VCALL_VIEW_SHOW_VIDEO, line: %d")          
    TRC_MSG(VCALL_TRC_PEER_VIEW_TYPE_UNKNOWN, "[VCALL_EX] Peer Type: UNKNOWN, %d, line: %d")               

    TRC_MSG(VCALL_TRC_LOCAL_VIEW_TYPE_HIDE, "[VCALL_EX] Local Type: VCALL_VIEW_HIDE, line: %d")                  
    TRC_MSG(VCALL_TRC_LOCAL_VIEW_TYPE_SHOW_IMAGE, "[VCALL_EX] Local Type: VCALL_VIEW_SHOW_IMAGE, line: %d")           
    TRC_MSG(VCALL_TRC_LOCAL_VIEW_TYPE_SHOW_VIDEO, "[VCALL_EX] Local Type: VCALL_VIEW_SHOW_VIDEO, line: %d")          
    TRC_MSG(VCALL_TRC_LOCAL_VIEW_TYPE_UNKNOWN, "[VCALL_EX] Local Type: UNKNOWN, %d, line: %d")              

    TRC_MSG(VCALL_TRC_VT_DATA_STATE_INIT, "[VCALL_EX] VT Date State: VCALL_DATA_INIT, line: %d")          
    TRC_MSG(VCALL_TRC_VT_DATA_STATE_STARVATION, "[VCALL_EX] VT Date State: VCALL_DATA_STARVATION, line: %d")          
    TRC_MSG(VCALL_TRC_VT_DATA_STATE_REPLENISH, "[VCALL_EX] VT Date State: VCALL_DATA_REPLENISH, line: %d")          
    TRC_MSG(VCALL_TRC_VT_DATA_STATE_CONSUMING, "[VCALL_EX] VT Date State: VCALL_DATA_CONSUMING, line: %d")          
    TRC_MSG(VCALL_TRC_VT_DATA_STATE_UNKNOWN, "[VCALL_EX] VT Date State: UNKNOWN, %d, line: %d")          

    TRC_MSG(VCALL_TRC_IN_VID_CHANNEL_CLOSED, "[VCALL_EX] IN VID Channel State: VCALL_CHANNEL_STATE_CLOSED, line: %d")
    TRC_MSG(VCALL_TRC_IN_VID_CHANNEL_OPEN, "[VCALL_EX] IN VID Channel State: VCALL_CHANNEL_STATE_OPEN, line: %d")    
    TRC_MSG(VCALL_TRC_IN_VID_CHANNEL_UNKNOWN, "[VCALL_EX] IN VID Channel State: UNKNOWN, %d, line: %d")   
    
    TRC_MSG(VCALL_TRC_OUT_VID_CHANNEL_CLOSED, "[VCALL_EX] OUT VID Channel State: VCALL_CHANNEL_STATE_CLOSED, line: %d")
    TRC_MSG(VCALL_TRC_OUT_VID_CHANNEL_OPEN, "[VCALL_EX] OUT VID Channel State: VCALL_CHANNEL_STATE_OPEN, line: %d")    
    TRC_MSG(VCALL_TRC_OUT_VID_CHANNEL_UNKNOWN, "[VCALL_EX] OUT VID Channel State: UNKNOWN, %d, line: %d")   
    
    TRC_MSG(VCALL_TRC_IN_AUD_CHANNEL_CLOSED, "[VCALL_EX] IN AUD Channel State: VCALL_CHANNEL_STATE_CLOSED, line: %d")
    TRC_MSG(VCALL_TRC_IN_AUD_CHANNEL_OPEN, "[VCALL_EX] IN AUD Channel State: VCALL_CHANNEL_STATE_OPEN, line: %d")    
    TRC_MSG(VCALL_TRC_IN_AUD_CHANNEL_UNKNOWN, "[VCALL_EX] IN AUD Channel State: UNKNOWN, %d, line: %d") 
    
    TRC_MSG(VCALL_TRC_OUT_AUD_CHANNEL_CLOSED, "[VCALL_EX] OUT AUD Channel State: VCALL_CHANNEL_STATE_CLOSED, line: %d")
    TRC_MSG(VCALL_TRC_OUT_AUD_CHANNEL_OPEN, "[VCALL_EX] OUT AUD Channel State: VCALL_CHANNEL_STATE_OPEN, line: %d")    
    TRC_MSG(VCALL_TRC_OUT_AUD_CHANNEL_UNKNOWN, "[VCALL_EX] OUT AUD Channel State: UNKNOWN, %d, line: %d") 

    TRC_MSG(VCALL_TRC_IDP_DECODE_VIDEO_SRC_WIDTH, "[VCALL_EX] IDP_DECODE_DATA_PATH: video_src_width, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_VIDEO_SRC_HEIGHT, "[VCALL_EX] IDP_DECODE_DATA_PATH: video_src_height, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_DISPLAY_WIDTH, "[VCALL_EX] IDP_DECODE_DATA_PATH: display_width, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_DISPLAY_HEIGHT, "[VCALL_EX] IDP_DECODE_DATA_PATH: display_height, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_PAN, "[VCALL_EX] IDP_DECODE_DATA_PATH: pan, %d, line: %d")         
    TRC_MSG(VCALL_TRC_IDP_DECODE_RESIZE_TAR_WIDTH, "[VCALL_EX] IDP_DECODE_DATA_PATH: resize_tar_width, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_RESIZE_TAR_HEIGHT, "[VCALL_EX] IDP_DECODE_DATA_PATH: resize_tar_height, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_VIDEO_Y_BUFFER_ADDRESS, "[VCALL_EX] IDP_DECODE_DATA_PATH: video_y_buffer_address, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_VIDEO_U_BUFFER_ADDRESS, "[VCALL_EX] IDP_DECODE_DATA_PATH: video_u_buffer_address, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_VIDEO_V_BUFFER_ADDRESS, "[VCALL_EX] IDP_DECODE_DATA_PATH: video_v_buffer_address, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_CONTRAST_LEVEL, "[VCALL_EX] IDP_DECODE_DATA_PATH: contrast_level, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_BRIGHTNESS_LEVEL, "[VCALL_EX] IDP_DECODE_DATA_PATH: brightness_level, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_FORCE_LCD_HW_TRIGGER, "[VCALL_EX] IDP_DECODE_DATA_PATH: force_lcd_hw_trigger, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_IS_UPDATE, "[VCALL_EX] IDP_DECODE_DATA_PATH: is_update, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_IMAGE_PITCH_MODE, "[VCALL_EX] IDP_DECODE_DATA_PATH: image_pitch_mode, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_IMAGE_DATA_FORMAT, "[VCALL_EX] IDP_DECODE_DATA_PATH: image_data_format, %d, line: %d")             
    TRC_MSG(VCALL_TRC_IDP_DECODE_IMAGE_PITCH_BYTES, "[VCALL_EX] IDP_DECODE_DATA_PATH: image_pitch_bytes, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_FRAME_BUFFER_ADDRESS, "[VCALL_EX] IDP_DECODE_DATA_PATH: frame_buffer_address, %d, line: %d")          
    TRC_MSG(VCALL_TRC_IDP_DECODE_FRAME_BUFFER_SIZE, "[VCALL_EX] IDP_DECODE_DATA_PATH: frame_buffer_size, %d, line: %d")              
    TRC_MSG(VCALL_TRC_IDP_DECODE_DECODE_UPDATE_LAYER, "[VCALL_EX] IDP_DECODE_DATA_PATH: decode_update_layer, %d, line: %d")                

    TRC_MSG(VCALL_TRC_IDP_ENCODE_INTMEM_START_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: intmem_start_address, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_INTMEM_SIZE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: intmem_size, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_EXTMEM_START_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: extmem_start_address, %d, line: %d")    
    TRC_MSG(VCALL_TRC_IDP_ENCODE_EXTMEM_SIZE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: extmem_size, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_BUFFER1_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: video_buffer1_address, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_BUFFER2_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: video_buffer2_address, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_INT_MEM, "[VCALL_EX] IDP_ENCODE_DATA_PATH: init_mem, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_SOURCE_WIDTH, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_source_width, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_SOURCE_HEIGHT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_source_height, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_IMAGE_WIDTH, "[VCALL_EX] IDP_ENCODE_DATA_PATH: viedo_encode_image_width, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_IMAGE_HEIGHT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: viedo_encode_image_height, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_TARGET_WIDTH, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_target_width, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_TARGET_HEIGHT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_target_height, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ENCODE_BIT_RATE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: encode_bit_rate, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_SHORT_HEADER_MODE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: short_header_mode, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_RESUME_ENABLE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: resume_enable, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_LCD_ID, "[VCALL_EX] IDP_ENCODE_DATA_PATH: lcd_id, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_LCM_START_X, "[VCALL_EX] IDP_ENCODE_DATA_PATH: lcm_start_x, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_LCM_START_Y, "[VCALL_EX] IDP_ENCODE_DATA_PATH: lcm_start_y, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_LCM_END_X, "[VCALL_EX] IDP_ENCODE_DATA_PATH: lcm_end_x, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_LCM_END_Y, "[VCALL_EX] IDP_ENCODE_DATA_PATH: lcm_end_y, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ROI_OFFSET_X, "[VCALL_EX] IDP_ENCODE_DATA_PATH: roi_offset_x, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ROI_OFFSET_Y, "[VCALL_EX] IDP_ENCODE_DATA_PATH: roi_offset_y, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_UPDATE_LAYER, "[VCALL_EX] IDP_ENCODE_DATA_PATH: update_layer, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_HW_UPDATE_LAYER, "[VCALL_EX] IDP_ENCODE_DATA_PATH: hw_update_layer, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ROTATE_VALUE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: rotate_value, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_MIRROR, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_mirror, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_SKIP_FRAME_COUNT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: skip_frame_count, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_FRAME_RATE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: frame_rate, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_FRAME_BUFFER_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: frame_buffer_address, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_FRAME_BUFFER_SIZE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: frame_buffer_size, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_OFFSET_X, "[VCALL_EX] IDP_ENCODE_DATA_PATH: video_encode_offset_x, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_OFFSET_Y, "[VCALL_EX] IDP_ENCODE_DATA_PATH: video_encode_offset_y, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ROI_BACKGROUND_COLOR, "[VCALL_EX] IDP_ENCODE_DATA_PATH: roi_background_color, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_LCD_UPDATE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: lcd_update, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ZOOM_FACTOR, "[VCALL_EX] IDP_ENCODE_DATA_PATH: zoom_factor, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_CONTRAST_LEVEL, "[VCALL_EX] IDP_ENCODE_DATA_PATH: contrast_level, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_BRIGHTNESS_LEVEL, "[VCALL_EX] IDP_ENCODE_DATA_PATH: brightness_level, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_SATURATION_VALUE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: saturation_value, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_WB_MODE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: wb_mode, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_EV_VALUE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: ev_value, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_BANDING_FREQ, "[VCALL_EX] IDP_ENCODE_DATA_PATH: banding_freq, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_EFFECT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_effect, %d, line: %d")
    TRC_MSG(VCALL_TRC_IDP_ENCODE_NIGHT_MODE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: night_mode, %d, line: %d")    
    TRC_MSG(VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_MODE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: overlay_frame_mode, %d, line: %d")    
    TRC_MSG(VCALL_TRC_IDP_ENCODE_OVERLAY_COLOR_DEPTH, "[VCALL_EX] IDP_ENCODE_DATA_PATH: overlay_color_depth, %d, line: %d") 
    TRC_MSG(VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_SOURCE_KEY, "[VCALL_EX] IDP_ENCODE_DATA_PATH: overlay_frame_source_key, %d, line: %d")    
    TRC_MSG(VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_WIDTH, "[VCALL_EX] IDP_ENCODE_DATA_PATH: overlay_frame_width, %d, line: %d") 
    TRC_MSG(VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_HEIGHT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: overlay_frame_height, %d, line: %d")    
    TRC_MSG(VCALL_TRC_IDP_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: overlay_frame_buffer_address, %d, line: %d") 
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_PITCH_MODE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_pitch_mode, %d, line: %d")    
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_DATA_FORMAT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_data_format, %d, line: %d") 
    TRC_MSG(VCALL_TRC_IDP_ENCODE_IMAGE_PITCH_BYTES, "[VCALL_EX] IDP_ENCODE_DATA_PATH: image_pitch_bytes, %d, line: %d") 
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output, %d, line: %d") 
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_WIDTH, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_width, %d, line: %d")     
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_HEIGHT, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_height, %d, line: %d")     
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_OFFSET_X, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_offset_x, %d, line: %d")     
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_OFFSET_Y, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_offset_y, %d, line: %d")         
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_BUFFER1_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_buffer1_address, %d, line: %d")     
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_BUFFER2_ADDRESS, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_buffer2_address, %d, line: %d")         
    TRC_MSG(VCALL_TRC_IDP_ENCODE_TV_OUTPUT_BUFFER_SIZE, "[VCALL_EX] IDP_ENCODE_DATA_PATH: tv_output_buffer_size, %d, line: %d")  
    TRC_MSG(VCALL_TRC_IDP_ENCODE_VIDEO_ENCODE_CB, "[VCALL_EX] IDP_ENCODE_DATA_PATH: video_encode_cb, %d, line: %d")      
    TRC_MSG(VCALL_TRC_IDP_ENCODE_ENCODE_EVENT_CB, "[VCALL_EX] IDP_ENCODE_DATA_PATH: encode_event_cb, %d, line: %d")      
    TRC_MSG(VCALL_TRC_IDP_ENCODE_CAM_ENCODE_CB, "[VCALL_EX] IDP_ENCODE_DATA_PATH: cam_encode_cb, %d, line: %d")      
    
    /* Video driver */
    /* video_decore.c */
    TRC_MSG(MPEG4_TRC_READ_HEADER_INFORMATION, "[DRV MP4]mpeg4_read_header_imformation: Loc (%d), bitcnt (%d)")
    TRC_MSG(MPEG4_TRC_READ_VOP_HEADER, "[DRV MP4]mpeg4_read_VOP_header: Loc (%d), bitcnt (%d)")
    TRC_MSG(MPEG4_TRC_READ_VOP_HEADER_NOT_CODED, "[DRV MP4]mpeg4_read_VOP_header_not_coded: bitcnt (%d)")
    TRC_MSG(MPEG4_TRC_READ_VOP_HEADER_VALID_VOP, "[DRV MP4]mpeg4_read_VOP_header_valid_VOP: bitcnt (%d)")
    TRC_MSG(MPEG4_TRC_READ_VOP_HEADER_NO_SHV_START_CODE, "[DRV MP4]mpeg4_read_VOP_header_no_SHV_START_CODE: bitcnt (%d)")
    TRC_MSG(MPEG4_TRC_READ_VOP_HEADER_VALID_SHV_VOP, "[DRV MP4]mpeg4_read_VOP_header_valid_SHV_VOP: bitcnt (%d), vop_coding_type (%d)")
    TRC_MSG(MPEG4_TRC_DEC_START, "[DRV MP4]mpeg4_decode_start_b_parsed_vol: %d, vos==NULL (%d)")
    TRC_MSG(MPEG4_TRC_DEC_START_ERR1, "[DRV MP4]mpeg4_decode_start_err1: (w:%d,h:%d)")    
    TRC_MSG(MPEG4_TRC_DEC_START_H263, "mpeg4_decode_start: h263")
    TRC_MSG(MPEG4_TRC_DEC_START_MP4_ERR, "mpeg4_decode_start: mpeg4 but vos=null or no VOL header")
    TRC_MSG(MPEG4_TRC_DEC_START_MP4_NORMAL, "mpeg4_decode_start: mpeg4, normal (w:%d, h:%d)")
    TRC_MSG(MPEG4_TRC_DEC_START_END, "mpeg4_decode_start_end: (w:%d, h:%d)")
    TRC_MSG(MPEG4_TRC_DEC_MAIN_POS1, "mpeg4_decode_main: pos1, (w:%d, h:%d), 263 (%d)")
    TRC_MSG(MPEG4_TRC_DEC_MAIN_POS2, "mpeg4_decode_main: pos2, (w:%d, h:%d), 263 (%d)")
    TRC_MSG(MPEG4_TRC_DEC_MAIN_READ_VOP_FAIL, "mpeg4_decode_main: read_VOP fail. Set non_coded. (status: %d, bitcnt: %d)")
    TRC_MSG(MPEG4_TRC_DEC_MAIN_READ_VOP_OK, "mpeg4_decode_main: read_VOP ok. non_coded (%d)")

    /* video_call_mp4.c */
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_OPEN_START, "[DRV MP4]mpeg4_videocall_dec_parse_open_start")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_OPEN_END, "[DRV MP4]mpeg4_videocall_dec_parse_open_end")
    TRC_MSG(H263_TRC_VIDEOCALL_DEC_PARSE_OPEN_START,"[DRV MP4]h263_videocall_dec_parse_open_start")
    TRC_MSG(H263_TRC_VIDEOCALL_DEC_PARSE_OPEN_ENDT,"[DRV MP4]h263_videocall_dec_parse_open_end")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_START,"[DRV MP4]mpeg4_videocall_dec_parse_packet_start: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_NO_VOS_HDR_ERR,"[DRV MP4]mpeg4_videocall_dec_parse_packet_no_VOS_hdr_err: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_VOS_HDR,"[DRV MP4]mpeg4_videocall_dec_parse_packet_mpg4_got_VOS_hdr: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_SHORT_HDR,"[DRV MP4]mpeg4_videocall_dec_parse_packet_short_hdr") 
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_NO_VOP_HDR_ERR,"[DRV MP4]mpeg4_videocall_dec_parse_packet_no_VOP_hdr_err: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_VOP_HDR,"[DRV MP4]mpeg4_videocall_dec_parse_packet_got_VOP_hdr")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_VOP_HDR_NOT_COMPLETE,"[DRV MP4]mpeg4_videocall_dec_parse_packet_VOP_hdr_not_complete")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_GOT_ANOTHER_VOP,"[DRV MP4]mpeg4_videocall_dec_parse_packet_got_another_VOP_in_pkt: %d")    
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_RES,"[DRV MP4]mpeg4_videocall_dec_parse_pkt_res: (w:%d, h:%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_RES2,"[DRV MP4]mpeg4_videocall_dec_parse_res2: (w:%d, h:%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_I,"[DRV MP4]mpeg4_videocall_dec_parse_packet I: b_sync_frame: %x,%x,%x,%x,%x,%x")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_P,"[DRV MP4]mpeg4_videocall_dec_parse_packet P: b_sync_frame: %x,%x,%x,%x,%x,%x")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSE_PKT_END,"[DRV MP4]mpeg4_videocall_dec_parse_packet_end: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_OPEN_START, "[DRV MP4]mpeg4_videocall_dec_open_start")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_OPEN_END, "[DRV MP4]mpeg4_videocall_dec_open_end")
    TRC_MSG(H263_TRC_VIDEOCALL_DEC_OPEN_START,"[DRV MP4]h263_videocall_dec_open_start")
    TRC_MSG(H263_TRC_VIDEOCALL_DEC_OPEN_ENDT,"[DRV MP4]h263_videocall_dec_open_end")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_OPEN_START, "[DRV MP4]mpeg4_videocall_enc_open_start")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_OPEN_END,"[DRV MP4]mpeg4_videocall_enc_open_end")
    TRC_MSG(H263_TRC_VIDEOCALL_ENC_OPEN_START,"[DRV MP4]h263_videocall_enc_open_start")
    TRC_MSG(H263_TRC_VIDEOCALL_ENC_OPEN_END,"[DRV MP4]h263_videocall_enc_open_end")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_INIT_START,"[DRV MP4]mpeg4_videocall_dec_init_start")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_INIT_END,"[DRV MP4]mpeg4_videocall_dec_init_end")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_SHORT_HDR,"[DRV MP4]mpeg4_videocall_dec_parseinfo_short_hdr") 
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_VOS_HDR_NOT_FOUND,"[DRV MP4]mpeg4_videocall_dec_parseinfo_VOS_hdr_not_found_err")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_VOS_HDR_FOUND,"[DRV MP4]mpeg4_videocall_dec_parseinfo_VOS_hdr_found")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_VOP_SHV_HDR_ERR,"[DRV MP4]mpeg4_videocall_dec_parseinfo_no_VOP_SHV_hdr_err")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_WIDTH_OVER_LIMIT,"[DRV MP4]mpeg4_videocall_dec_parseinfo_width_over_chip_limitation")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_HEIGHT_OVER_LIMIT,"[DRV MP4]mpeg4_videocall_dec_parseinfo_height_over_chip_limitation")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_W_H_OVER_LIMIT,"[DRV MP4]mpeg4_videocall_dec_parseinfo_w_h_over_dec_limitation")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_NORMAL_VOP,"[DRV MP4]mpeg4_videocall_dec_parseinfo_normal_VOP, vop type(%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_PARSEINFO_NOT_CODED_VOP,"[DRV MP4]mpeg4_videocall_dec_parseinfo_not_coded_VOP")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_DEC_SUCCESS,"[DRV MP4]mpeg4_videocall_dec_success: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_INIT,"[DRV MP4]mpeg4_videocall_enc_init: fps (%d), enc_yuvsrc (%d), w (%d), h (%d), shv (%d), bps (%d), maxPktSize (%d), forceI (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_CONFIG_START,"[DRV MP4]mpeg4_videocall_enc_config_start: fcode (%d), b_resync_marker (%d), Q (%d), time_increment (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_PARSEINFO,"[DRV MP4]mpeg4_videocall_enc_parseinfo: enc_time_stamp (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_START,"[DRV MP4]mpeg4_videocall_enc_start: b_force_I (%d), FrmCnt (%d), buffer_length (%d), pkt_size_limit (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_COMPLETE,"[DRV MP4]mpeg4_videocall_enc_complete: (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_RESUME,"[DRV MP4]mpeg4_videocall_enc_resume: start_addr (%d), size (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_UPDATE_INFO,"[DRV MP4]mpeg4_videocall_enc_update_info: bps (%d), fps (%d), Q (%d), total_bytes (%d), pred_Type (%d), frmCnt (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_UPDATE_I,"[DRV MP4]mpeg4_videocall_enc_update_I: (%d)")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_DROP_PREV_FRAME,"[DRV MP4]mpeg4_videocall_enc_drop_prev_frame")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_FIND_PKT_BOUNDARY,"[DRV MP4]mpeg4_videocall_enc_find_pkt_boundary: len(%d), ind(%d): %d,%d,%d,%d,%d,%d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_NOT_FIND_PKT_BOUNDARY,"[DRV MP4]mpeg4_videocall_enc_not_find_pkt_boundary: %d")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_STOP,"[DRV MP4]mpeg4_videocall_enc_stop")
    TRC_MSG(MPEG4_TRC_VIDEOCALL_ENC_CLOSE,"[DRV MP4]mpeg4_videocall_enc_close")

    /* video_call_if.c */
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_AVAILABLE_CODECS,"[DRV VideoCall]VideoCall_GetAvailableCodecs")
    TRC_MSG(VIDEOCALL_DRV_TRC_SET_DEC_PARSE_CODEC,"[DRV VideoCall]VideoCall_SetDecParseCodec")
    TRC_MSG(VIDEOCALL_DRV_TRC_SET_DEC_ACTIVE_CODEC,"[DRV VideoCall]VideoCall_SetDecActiveCodec")
    TRC_MSG(VIDEOCALL_DRV_TRC_SET_ENC_ACTIVE_CODEC,"[DRV VideoCall]VideoCall_SetEncActiveCodec")
    TRC_MSG(VIDEOCALL_DRV_TRC_CONFIG_DEC,"[DRV VideoCall]VideoCall_CfgDec")
    TRC_MSG(VIDEOCALL_DRV_TRC_PARSE_PKT,"[DRV VideoCall]VideoCall_ParsePacket: %d")
    TRC_MSG(VIDEOCALL_DRV_TRC_PARSE_PKT_CONTENT,"[DRV VideoCall]VideoCall_ParsePacket Content: %x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x")
    TRC_MSG(VIDEOCALL_DRV_TRC_CLOSE_DEC,"[DRV VideoCall]VideoCall_CloseDec")
    TRC_MSG(VIDEOCALL_DRV_TRC_START_DEC,"[DRV VideoCall]VideoCall_StartDec")
    TRC_MSG(VIDEOCALL_DRV_TRC_STOP_DEC,"[DRV VideoCall]VideoCall_StopDec")
    TRC_MSG(VIDEOCALL_DRV_TRC_CONFIG_ENC,"[DRV VideoCall]VideoCall_CfgEnc")
    TRC_MSG(VIDEOCALL_DRV_TRC_START_ENC,"[DRV VideoCall]VideoCall_StartEnc")
    TRC_MSG(VIDEOCALL_DRV_TRC_ENC_UPDATE_I,"[DRV VideoCall]VideoCall_Enc_UpdateI")
    TRC_MSG(VIDEOCALL_DRV_TRC_STOP_ENC,"[DRV VideoCall]VideoCall_StopEnc")
    TRC_MSG(VIDEOCALL_DRV_TRC_CLOSE_ENC,"[DRV VideoCall]VideoCall_CloseEnc")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT,"[DRV VideoCall]VideoCall_GetNextPacket")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_1ST_PKT,"[DRV VideoCall]VideoCall_Get1stPacket")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_READ_META,"[DRV VideoCall]VideoCall_GetNextPacket_Read_Meta: len(%d), time(%d), b_ret(%d), vop_type(%d), q(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_1ST_I_FRAME,"[DRV VideoCall]VideoCall_GetNextPacket_1st_I_frame: elapsedTimeMS(%d), IfrmCnt(%d), PfrmCnt(%d), vop_type(%d), q(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_GET_FRAME,"[DRV VideoCall]VideoCall_GetNextPacket_get_frame: elapsedTimeMS(%d), IfrmCnt(%d), PfrmCnt(%d), vop_type(%d), q(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_READ_LEFT_PKT,"[DRV VideoCall]VideoCall_GetNextPacket_Read_Left_Pkt: len(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_NO_LEF_PKT,"[DRV VideoCall]VideoCall_GetNextPacket_No_Left_Pkt: len(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_READ_DATA,"[DRV VideoCall]VideoCall_GetNextPacket_Read_Data: buf_size(%d), pkt_size(%d), read_size(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_FOUND_PKT_BOUNDARY,"[DRV VideoCall]VideoCall_GetNextPacket_Found_Pkt_Boundary: pkt_size(%d), pkt_bdry_ind(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_NO_PKT_BOUNDARY,"[DRV VideoCall]VideoCall_GetNextPacket_No_Pkt_Boundary")
    TRC_MSG(VIDEOCALL_DRV_TRC_GET_NEXT_PKT_OK,"[DRV VideoCall]VideoCall_GetNextPacket_OK: total_get_away_bytes (%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_RATE_CONTROL_START,"[DRV VideoCall]VideoCall_RateControl_start: mode(%d), temp(%d), target_frm_bits(%d), bits(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_RATE_RECOVER_P,"[DRV VideoCall]videocall_enc_rate_recover_q: quant_temp(%d), big_q_cnt(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_RATE_CONTROL_END,"[DRV VideoCall]videocall_enc_rate_control_end: drop_frame(%d), temp(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_TOGGLE_DROP_FRAME_TRUE,"[DRV VideoCall]videocall_ToggleDropFrame TRUE: drop_frame(%d)")
    TRC_MSG(VIDEOCALL_DRV_TRC_TOGGLE_DROP_FRAME_FALSE,"[DRV VideoCall]videocall_ToggleDropFrame FALSE: drop_frame(%d), quant_temp(%d)")

    
END_TRACE_MAP(MOD_MED)

#endif /* _MED_TRC_H */

#endif /* MED_NOT_PRESENT */

