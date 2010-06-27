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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   med_sap.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media task related message identity definition
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

   /*------------------------MED_MSG_CODE_BEGIN ---------------*/
MSG_ID_MED_STARTUP_REQ = MSG_ID_MED_CODE_BEGIN,
    MSG_ID_L4AUD_STARTUP_REQ = MSG_ID_MED_STARTUP_REQ,
    MSG_ID_MED_STARTUP_CNF,
    MSG_ID_L4AUD_STARTUP_CNF = MSG_ID_MED_STARTUP_CNF,
    MSG_ID_MEDIA_GET_BUFFER_REQ,
    MSG_ID_MEDIA_FREE_BUFFER_REQ,
    MSG_ID_MEDIA_TEMP_1,
    MSG_ID_MEDIA_TEMP_2,
    MSG_ID_L4AUD_GET_AUDIO_MODE_REQ,
    MSG_ID_MED_AUD_CODE_BEGIN = MSG_ID_L4AUD_GET_AUDIO_MODE_REQ,
    MSG_ID_L4AUD_GET_AUDIO_MODE_CNF,
    MSG_ID_L4AUD_SET_AUDIO_MODE_REQ,
    MSG_ID_L4AUD_SET_AUDIO_MODE_CNF,
    MSG_ID_L4AUD_GPIO_DETECT_IND,
    MSG_ID_L4AUD_GET_AUDIO_PROFILE_REQ,
    MSG_ID_L4AUD_GET_AUDIO_PROFILE_CNF,
    MSG_ID_L4AUD_SET_AUDIO_PROFILE_REQ,
    MSG_ID_L4AUD_SET_AUDIO_PROFILE_CNF,
    MSG_ID_L4AUD_GET_AUDIO_PARAM_REQ,
    MSG_ID_L4AUD_GET_AUDIO_PARAM_CNF,
    MSG_ID_L4AUD_SET_AUDIO_PARAM_REQ,
    MSG_ID_L4AUD_SET_AUDIO_PARAM_CNF,
    MSG_ID_L4AUD_AUDIO_GET_VOLUME_REQ,
    MSG_ID_L4AUD_AUDIO_GET_VOLUME_CNF,
    MSG_ID_L4AUD_AUDIO_GET_GAIN_REQ,
    MSG_ID_L4AUD_AUDIO_GET_GAIN_CNF,
    MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ,
    MSG_ID_L4AUD_AUDIO_SET_VOLUME_CNF,
    MSG_ID_L4AUD_AUDIO_SET_GAIN_REQ,
    MSG_ID_L4AUD_AUDIO_SET_GAIN_CNF,
    MSG_ID_L4AUD_AUDIO_SET_DEVICE_REQ,
    MSG_ID_L4AUD_AUDIO_SET_DEVICE_CNF,
    MSG_ID_L4AUD_AUDIO_PLAY_REQ,
    MSG_ID_L4AUD_AUDIO_PLAY_CNF,
    MSG_ID_L4AUD_AUDIO_STOP_REQ,
    MSG_ID_L4AUD_AUDIO_STOP_CNF,
    MSG_ID_L4AUD_AUDIO_PLAY_BY_NAME_REQ,
    MSG_ID_L4AUD_AUDIO_PLAY_BY_NAME_CNF,
    MSG_ID_L4AUD_AUDIO_STOP_BY_NAME_REQ,
    MSG_ID_L4AUD_AUDIO_STOP_BY_NAME_CNF,
    MSG_ID_L4AUD_AUDIO_PLAY_BY_STRING_REQ,
    MSG_ID_L4AUD_AUDIO_PLAY_BY_STRING_CNF,
    MSG_ID_L4AUD_AUDIO_STOP_BY_STRING_REQ,
    MSG_ID_L4AUD_AUDIO_STOP_BY_STRING_CNF,
    MSG_ID_L4AUD_AUDIO_PLAY_TONE_SEQ_REQ,
    MSG_ID_L4AUD_AUDIO_PLAY_TONE_SEQ_CNF,
    MSG_ID_L4AUD_AUDIO_STOP_TONE_SEQ_REQ,
    MSG_ID_L4AUD_AUDIO_STOP_TONE_SEQ_CNF,
    MSG_ID_L4AUD_AUDIO_DEMO_IMY_REQ,
    MSG_ID_L4AUD_AUDIO_DEMO_IMY_CNF,
    MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND,
    MSG_ID_L4AUD_AUDIO_MUTE_REQ,
    MSG_ID_L4AUD_AUDIO_MUTE_CNF,
    MSG_ID_L4AUD_AUDIO_SET_FIR_REQ,
    MSG_ID_L4AUD_AUDIO_SET_FIR_CNF,
    MSG_ID_L4AUD_SP_SET_INPUT_MODE_REQ,
    MSG_ID_L4AUD_SP_SET_INPUT_MODE_CNF,
    MSG_ID_L4AUD_SP_SET_MODE_REQ,
    MSG_ID_L4AUD_SP_SET_MODE_CNF,
    MSG_ID_L4AUD_VM_RECORD_REQ,
    MSG_ID_L4AUD_VM_RECORD_CNF,
    MSG_ID_L4AUD_VM_PLAY_REQ,
    MSG_ID_L4AUD_VM_PLAY_CNF,
    MSG_ID_L4AUD_VM_STOP_REQ,
    MSG_ID_L4AUD_VM_STOP_CNF,
    MSG_ID_L4AUD_VM_DELETE_REQ,
    MSG_ID_L4AUD_VM_DELETE_CNF,
    MSG_ID_L4AUD_VM_ABORT_REQ,
    MSG_ID_L4AUD_VM_ABORT_CNF,
    MSG_ID_L4AUD_VM_PAUSE_REQ,
    MSG_ID_L4AUD_VM_PAUSE_CNF,
    MSG_ID_L4AUD_VM_RESUME_REQ,
    MSG_ID_L4AUD_VM_RESUME_CNF,
    MSG_ID_L4AUD_VM_APPEND_REQ,
    MSG_ID_L4AUD_VM_APPEND_CNF,
    MSG_ID_L4AUD_VM_GET_INFO_REQ,
    MSG_ID_L4AUD_VM_GET_INFO_CNF,
    MSG_ID_L4AUD_VM_RENAME_REQ,
    MSG_ID_L4AUD_VM_RENAME_CNF,
    MSG_ID_L4AUD_VM_RECORD_FINISH_IND,
    MSG_ID_L4AUD_VM_PLAY_FINISH_IND,
    MSG_ID_AUD_VM_READ_DATA_IND,
    MSG_ID_AUD_VM_WRITE_DATA_IND,
    MSG_ID_L4AUD_MEDIA_RECORD_REQ,
    MSG_ID_L4AUD_MEDIA_RECORD_CNF,
    MSG_ID_L4AUD_MEDIA_PLAY_REQ,
    MSG_ID_L4AUD_MEDIA_PLAY_CNF,
    MSG_ID_L4AUD_MEDIA_STOP_REQ,
    MSG_ID_L4AUD_MEDIA_STOP_CNF,
    MSG_ID_L4AUD_MEDIA_PAUSE_REQ,
    MSG_ID_L4AUD_MEDIA_PAUSE_CNF,
    MSG_ID_L4AUD_MEDIA_RESUME_REQ,
    MSG_ID_L4AUD_MEDIA_RESUME_CNF,
    MSG_ID_AUD_MEDIA_READ_DATA_IND,
    MSG_ID_AUD_MEDIA_WRITE_DATA_IND,
    MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND,
    MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND,
    MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND,
    MSG_ID_AUD_MEDIA_PLAY_EVENT_IND,
    MSG_ID_AUD_MEDIA_PLAY_STREAM_EVENT_IND,
    MSG_ID_MEDIA_AUD_BLOCK_REQ,
    MSG_ID_L4AUD_MEDIA_STORE_REQ,
    MSG_ID_L4AUD_MEDIA_RESTORE_REQ,
    MSG_ID_MEDIA_AUD_SET_MUTE_REQ,
    MSG_ID_MEDIA_AUD_MPLAY_REQ,
    MSG_ID_MEDIA_AUD_MSTOP_REQ,
    MSG_ID_MEDIA_AUD_START_CALC_SPECTRUM_REQ,
    MSG_ID_MEDIA_AUD_STOP_CALC_SPECTRUM_REQ,
    MSG_ID_MEDIA_AUD_GET_SPECTRUM_REQ,
    MSG_ID_MEDIA_AUD_SET_VIBRATOR_ENABLED_REQ,
    MSG_ID_MEDIA_AUD_GET_DURATION_REQ,
    MSG_ID_MEDIA_AUD_GET_PROGRESS_TIME_REQ,
    MSG_ID_MEDIA_AUD_SET_PROGRESS_TIME_REQ,
    MSG_ID_MEDIA_AUD_CHECK_IS_PURE_AUDIO_REQ,
    MSG_ID_MED_AUD_CODE_END = MSG_ID_MEDIA_AUD_CHECK_IS_PURE_AUDIO_REQ,
    MSG_ID_MEDIA_CAM_POWER_UP_REQ,
    MSG_ID_MED_CAM_CODE_BEGIN = MSG_ID_MEDIA_CAM_POWER_UP_REQ,
    MSG_ID_MEDIA_CAM_POWER_DOWN_REQ,
    MSG_ID_MEDIA_CAM_READY_IND,
    MSG_ID_MEDIA_CAM_PREVIEW_REQ,
    MSG_ID_MEDIA_CAM_PREVIEW_FAIL_IND,
    MSG_ID_MEDIA_CAM_STOP_REQ,
    MSG_ID_MEDIA_CAM_CAPTURE_REQ,
    MSG_ID_MEDIA_CAM_SET_PARAM_REQ,
    MSG_ID_MEDIA_CAM_SET_FLASH_REQ,
    MSG_ID_MEDIA_CAM_START_FAST_ZOOM_REQ,
    MSG_ID_MEDIA_CAM_STOP_FAST_ZOOM_REQ,
    MSG_ID_MEDIA_CAM_GET_FAST_ZOOM_FACTOR_REQ,
    MSG_ID_MEDIA_CAM_GET_FOCUS_STEPS_REQ,
    MSG_ID_MEDIA_CAM_CAPTURE_EVENT_IND,
    MSG_ID_MEDIA_CAM_CAL_MANUAL_WB_REQ,
    MSG_ID_MEDIA_CAM_MWB_OPERATION_REQ,
    MSG_ID_MEDIA_CAM_SET_OVERLAY_PALETTE_REQ,
    MSG_ID_MEDIA_CAM_AF_PROCESS_DONE_IND,
    MSG_ID_MEDIA_CAM_EVENT_IND,
    MSG_ID_MEDIA_CAM_XENON_FLASH_STATUS_IND,
    MSG_ID_MEDIA_CAM_BARCODE_PREVIEW_REQ,
    MSG_ID_MEDIA_CAM_BARCODE_STOP_REQ,
    MSG_ID_MEDIA_CAM_BARCODE_CAPTURE_REQ,
    MSG_ID_MEDIA_CAM_BARCODE_STOP_CAPTURE_REQ,
    MSG_ID_MEDIA_CAM_BARCODE_DECODE_DONE_IND,
    MSG_ID_MED_CAM_CODE_END = MSG_ID_MEDIA_CAM_BARCODE_DECODE_DONE_IND,
    MSG_ID_MEDIA_IMG_DECODE_REQ,
    MSG_ID_MED_IMG_CODE_BEGIN = MSG_ID_MEDIA_IMG_DECODE_REQ,
    MSG_ID_MEDIA_IMG_DECODE_FINISH_IND,
    MSG_ID_MEDIA_IMG_DECODE_EVENT_IND,
    MSG_ID_MEDIA_IMG_ENCODE_REQ,
    MSG_ID_MEDIA_IMG_ENCODE_FINISH_IND,
    MSG_ID_MEDIA_IMG_ENCODE_EVENT_IND,
    MSG_ID_MEDIA_IMG_STOP_REQ,
    MSG_ID_MEDIA_IMG_RESIZE_REQ,
    MSG_ID_MEDIA_IMG_RESIZE_DONE_IND,
    MSG_ID_MEDIA_IMG_EXIF_DECODE_REQ,
    MSG_ID_MEDIA_IMG_TEMP_1,
    MSG_ID_MEDIA_IMG_TEMP_2,
    MSG_ID_MED_IMG_CODE_END = MSG_ID_MEDIA_IMG_TEMP_2,
    MSG_ID_MEDIA_VID_PREVIEW_REQ,
    MSG_ID_MED_VID_CODE_BEGIN = MSG_ID_MEDIA_VID_PREVIEW_REQ,
    MSG_ID_MEDIA_VID_RECORD_REQ,
    MSG_ID_MEDIA_VID_STOP_REQ,
    MSG_ID_MEDIA_VID_RECORD_FINISH_IND,
    MSG_ID_MEDIA_VID_ENCODE_EVENT_IND,
    MSG_ID_MEDIA_VID_ENCODE_AUDIO_DATA_IND,
    MSG_ID_MEDIA_VID_FILE_MERGE_REQ,
    MSG_ID_MEDIA_VID_FILE_MERGE_DONE_IND,
    MSG_ID_MEDIA_VID_OPEN_REQ,
    MSG_ID_MEDIA_VID_CLOSE_REQ,
    MSG_ID_MEDIA_VID_FILE_READY_IND,
    MSG_ID_MEDIA_VID_PLAY_REQ,
    MSG_ID_MEDIA_VID_PLAY_FINISH_IND,
    MSG_ID_MEDIA_VID_DECODE_EVENT_IND,
    MSG_ID_MEDIA_VID_EDT_ENCODE_EVENT_IND,
    MSG_ID_MEDIA_VID_DECODE_AUDIO_DATA_IND,
    MSG_ID_MEDIA_VID_PAUSE_REQ,
    MSG_ID_MEDIA_VID_RESUME_REQ,
    MSG_ID_MEDIA_VID_SET_STOP_TIME,
    MSG_ID_MEDIA_VID_SEEK_REQ,
    MSG_ID_MEDIA_VID_SEEK_DONE_IND,
    MSG_ID_MEDIA_VID_EDT_SET_ACTIVE_REQ,  
    MSG_ID_MEDIA_VID_EDT_ENC_OPEN_REQ,      
    MSG_ID_MEDIA_VID_EDT_ENC_CLOSE_REQ,
    MSG_ID_MEDIA_VID_EDT_ENC_APPEND_REQ,
    MSG_ID_MEDIA_VID_EDT_ENC_MERGE_REQ,
    MSG_ID_MEDIA_VID_EDT_ENC_STOP_MERGE_REQ,
    MSG_ID_MEDIA_VID_EDT_ENC_MERGE_DONE_IND,    
    MSG_ID_MEDIA_VID_EDT_OPEN_BGM_REQ,    
    MSG_ID_MEDIA_VID_EDT_CLOSE_BGM_REQ,  
    MSG_ID_MEDIA_VID_EDT_OPEN_SILENCE_REQ,    
    MSG_ID_MEDIA_VID_EDT_CLOSE_SILENCE_REQ,
    MSG_ID_MEDIA_VID_EDT_INIT_REQ,
    MSG_ID_MEDIA_VID_EDT_DEINIT_REQ,
    MSG_ID_MEDIA_VID_GET_PDL_PRECENT_REQ,
    MSG_ID_MEDIA_VID_GET_PDL_MAX_TIME_REQ,  
    MSG_ID_MEDIA_VID_CHECK_IS_PDL_REQ,      
    MSG_ID_MEDIA_VID_GET_INFO_REQ,
    MSG_ID_MEDIA_VID_GET_IFRAME_REQ,
    MSG_ID_MEDIA_VID_IFRAME_READY_IND,
    MSG_ID_MEDIA_VID_ERROR_RECOVER_IND,
    MSG_ID_MEDIA_VID_PLAY_RESTART_IND,
    MSG_ID_MEDIA_VID_AUDIO_PLAY_FINISH_IND,
    MSG_ID_MEDIA_VID_MJPEG_ENCODE_IND,    
    MSG_ID_MEDIA_VID_SET_DISPLAY_REQ,
    MSG_ID_MEDIA_VID_UPDATE_BLT_PAUSE_REQ,
    MSG_ID_MEDIA_VID_UPDATE_BLT_RESUME_REQ,
    MSG_ID_MEDIA_VID_SET_OVERLAY_PALETTE_REQ,
    MSG_ID_MEDIA_VID_SET_PARAM_REQ,
    MSG_ID_MED_VID_CODE_END = MSG_ID_MEDIA_VID_SET_PARAM_REQ,
    MSG_ID_MEDIA_TVO_START_REQ,
    MSG_ID_MED_TVO_CODE_BEGIN = MSG_ID_MEDIA_TVO_START_REQ,
    MSG_ID_MEDIA_TVO_STOP_REQ,
    MSG_ID_MEDIA_TVO_SET_MODE_REQ,
    MSG_ID_MEDIA_TVO_TV_CONNECT_IND,
    MSG_ID_MEDIA_TVO_AV_CABLE_DETECT_IND,
    MSG_ID_MEDIA_TVO_SET_PARAM_REQ,
    MSG_ID_MEDIA_TVO_TEMP_2,
    MSG_ID_MED_TVO_CODE_END = MSG_ID_MEDIA_TVO_TEMP_2,
    MSG_ID_MEDIA_WEBCAM_START_REQ,
    MSG_ID_MED_WEBCAM_CODE_BEGIN = MSG_ID_MEDIA_WEBCAM_START_REQ,
    MSG_ID_MEDIA_WEBCAM_START_CNF,
    MSG_ID_MEDIA_WEBCAM_STOP_REQ,
    MSG_ID_MEDIA_WEBCAM_PAUSE_REQ,
    MSG_ID_MEDIA_WEBCAM_RESUME_REQ,
    MSG_ID_MEDIA_WEBCAM_CAPTURE_REQ,
    MSG_ID_MEDIA_WEBCAM_ROTATE_REQ,
    MSG_ID_MEDIA_WEBCAM_ABORT_IND,
    MSG_ID_MEDIA_WEBCAM_ENCODE_REQ,
    MSG_ID_MEDIA_WEBCAM_TEMP_2,
    MSG_ID_MED_WEBCAM_CODE_END = MSG_ID_MEDIA_WEBCAM_TEMP_2,
    MSG_ID_MEDIA_MMA_OPEN_REQ,
    MSG_ID_MED_MMA_CODE_BEGIN = MSG_ID_MEDIA_MMA_OPEN_REQ,
    MSG_ID_MEDIA_MMA_CLOSE_REQ,
    MSG_ID_MEDIA_MMA_PLAY_REQ,
    MSG_ID_MEDIA_MMA_STOP_REQ,
    MSG_ID_MEDIA_MMA_PAUSE_REQ,
    MSG_ID_MEDIA_MMA_RESUME_REQ,
    MSG_ID_MEDIA_MMA_GET_AUDIO_INFO_REQ,
    MSG_ID_MEDIA_MMA_GET_DURATION_REQ,
    MSG_ID_MEDIA_MMA_GET_CURRENT_TIME_REQ,
    MSG_ID_MEDIA_MMA_SET_START_TIME_REQ,
    MSG_ID_MEDIA_MMA_SET_STOP_TIME_REQ,
    MSG_ID_MEDIA_MMA_GET_VOLUME_REQ,
    MSG_ID_MEDIA_MMA_SET_VOLUME_REQ,
    MSG_ID_MEDIA_MMA_SET_RATE_REQ,
    MSG_ID_MEDIA_MMA_SET_TEMPO_REQ,
    MSG_ID_MEDIA_MMA_SET_PITCH_REQ,
    MSG_ID_MEDIA_MMA_SEND_LONG_MSG_REQ,
    MSG_ID_MEDIA_MMA_SEND_SHORT_MSG_REQ,
    MSG_ID_MEDIA_MMA_OPEN_DEVICE_REQ,
    MSG_ID_MEDIA_MMA_CLOSE_DEVICE_REQ,
    MSG_ID_MEDIA_MMA_SET_CHANNEL_VOLUME_REQ,
    MSG_ID_MEDIA_MMA_SET_PROGRAM_REQ,
    MSG_ID_MEDIA_MMA_SET_DATA_REQ,
    MSG_ID_MEDIA_MMA_WRITE_DATA_IND_REQ,    
    MSG_ID_MEDIA_MMA_PLAY_EVENT_IND,
    MSG_ID_MEDIA_MMA_PROCESS_EVENT_IND,
    MSG_ID_MEDIA_MMA_CALLBACK_IND,    
    MSG_ID_MEDIA_MMA_TEMP_1,
    MSG_ID_MEDIA_MMA_TEMP_2,
    MSG_ID_MEDIA_MMA_TEMP_3,
    MSG_ID_MED_MMA_CODE_END = MSG_ID_MEDIA_MMA_TEMP_3,
    MSG_ID_MEDIA_FMR_POWER_ON_REQ,
    MSG_ID_MEDIA_FMR_POWER_OFF_REQ,
    MSG_ID_MEDIA_FMR_SET_FREQ_REQ,
    MSG_ID_MEDIA_FMR_MUTE_REQ,
    MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_REQ,
    MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_CNF,
    MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_REQ,
    MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_CNF,
    MSG_ID_MEDIA_FMR_EVALUATE_THRESHOLD_REQ,

   //#define ANALOG_TV_SUPPORT BEGIN
    MSG_ID_MEDIA_ANALOG_TV_POWER_UP_REQ,
    MSG_ID_MEDIA_ANALOG_TV_POWER_DOWN_REQ,
    MSG_ID_MEDIA_ANALOG_TV_OPEN_PATH_REQ,
    MSG_ID_MEDIA_ANALOG_TV_CLOSE_PATH_REQ,
    MSG_ID_MEDIA_ANALOG_TV_MUTE_REQ,
    MSG_ID_MEDIA_ANALOG_TV_SET_CHANNEL_REQ,
    MSG_ID_MEDIA_ANALOG_TV_SET_CHANNEL_CNF,
    MSG_ID_MEDIA_ANALOG_TV_GET_VALID_CHANNEL_REQ,
    MSG_ID_MEDIA_ANALOG_TV_GET_VALID_CHANNEL_CNF,
    //#endif //ANALOG_TV_SUPPORT
    
    MSG_ID_MEDIA_AUD_SET_HEADSET_MODE_OUTPUT_PATH,
    MSG_ID_MEDIA_SND_CHECK_BYTE_STREAM_FORMAT_REQ,
    MSG_ID_MEDIA_SND_CHECK_FILE_FORMAT_REQ,
    MSG_ID_MEDIA_SND_PLAY_BYTE_STREAM_REQ,
    MSG_ID_MEDIA_SND_PLAY_FILE_REQ,
    MSG_ID_MEDIA_SND_PLAY_EVENT_IND,
    MSG_ID_MEDIA_SND_PLAY_FINISH_IND,
    MSG_ID_MEDIA_SND_STOP_PLAY_REQ,
    MSG_ID_MEDIA_SND_SET_VOLUME_REQ,
    MSG_ID_MEDIA_AUD_STRETCH_CHECK_STREAM_FORMAT_REQ,
    MSG_ID_MEDIA_AUD_STRETCH_CHECK_FILE_FORMAT_REQ,
    MSG_ID_MEDIA_AUD_STRETCH_SET_SPEED_REQ,
    MSG_ID_MEDIA_AUD_STRETCH_CLOSE_REQ,
    MSG_ID_MEDIA_AUD_REVERB_SET_COEFF_REQ,
    MSG_ID_MEDIA_AUD_REVERB_TURN_ON_REQ,
    MSG_ID_MEDIA_AUD_REVERB_TURN_OFF_REQ,
    MSG_ID_MEDIA_AUD_SURROUND_TURN_ON_REQ,
    MSG_ID_MEDIA_AUD_SURROUND_TURN_OFF_REQ,
    MSG_ID_MEDIA_AUD_EQ_SET_MAGNITUDE_REQ,
    MSG_ID_MEDIA_AUD_EQ_TURN_ON_REQ,
    MSG_ID_MEDIA_AUD_EQ_TURN_OFF_REQ,
    MSG_ID_MEDIA_AUD_TTS_SET_ATTR_REQ,
    MSG_ID_MEDIA_AUD_TTS_PLAY_EVENT_IND,
    MSG_ID_MEDIA_AUD_TTS_PLAY_REQ,
    MSG_ID_MEDIA_AUD_TTS_STOP_REQ,
    MSG_ID_MEDIA_AUD_TTS_PAUSE_REQ,
    MSG_ID_MEDIA_AUD_TTS_RESUME_REQ,
    MSG_ID_MEDIA_AUD_TTS_UPDATE_INFO_IND,
    MSG_ID_MEDIA_VR_GET_VERSION_REQ,
    MSG_ID_MEDIA_VR_GET_PARAM_REQ,
    MSG_ID_MEDIA_VR_SET_PARAM_REQ,
    MSG_ID_MEDIA_VR_INIT_RCG_REQ,
    MSG_ID_MEDIA_VR_RCG_PROCESS_REQ,
    MSG_ID_MEDIA_VR_RCG_RESULT_IND,
    MSG_ID_MEDIA_VR_INIT_TRN_REQ,
    MSG_ID_MEDIA_VR_TRN_PROCESS_REQ,
    MSG_ID_MEDIA_VR_TRN_RESULT_IND,
    MSG_ID_MEDIA_VR_VOICE_IN_REQ,
    MSG_ID_MEDIA_VR_DEL_TAG_REQ,
    MSG_ID_MEDIA_VR_CHECK_TAG_REQ,
    MSG_ID_MEDIA_VR_SYNC_DB_REQ,
    MSG_ID_MEDIA_VR_PLAY_TAG_REQ,
    MSG_ID_MEDIA_VR_GET_DIR_REQ,
    MSG_ID_MEDIA_VR_ADD_TAG_REQ,
    MSG_ID_MEDIA_VR_ABORT_REQ,
    MSG_ID_MEDIA_VR_ABORT_IND,
    MSG_ID_MED_VR_CODE_END = MSG_ID_MEDIA_VR_ABORT_IND,
    MSG_ID_MEDIA_VRSI_INIT_REQ,
    MSG_ID_MEDIA_VRSI_ADD_TAGS_REQ,
    MSG_ID_MEDIA_VRSI_START_TRN_REQ,
    MSG_ID_MEDIA_VRSI_START_RCG_REQ,
    MSG_ID_MEDIA_VRSI_PLAY_TAG_REQ,
    MSG_ID_MEDIA_VRSI_PLAY_TTS_REQ,
    MSG_ID_MEDIA_VRSI_GET_TAGNUM_REQ,
    MSG_ID_MEDIA_VRSI_GET_TAGINFO_REQ,
    MSG_ID_MEDIA_VRSI_DEL_TAGS_REQ,
    MSG_ID_MEDIA_VRSI_RESET_TAGS_REQ,
    MSG_ID_MEDIA_VRSI_SYNC_DB_REQ,
    MSG_ID_MEDIA_VRSI_ABORT_REQ,
    MSG_ID_MEDIA_VRSI_CLOSE_REQ,
    MSG_ID_MEDIA_VRSI_PROCESS_IND,
    MSG_ID_MEDIA_VRSI_TRN_PROMPT_REQ,
    MSG_ID_MEDIA_VRSI_TRN_RESULT_IND,
    MSG_ID_MEDIA_VRSI_RCG_PROMPT_REQ,
    MSG_ID_MEDIA_VRSI_RCG_RESULT_IND,
    MSG_ID_MEDIA_VRSI_ERR_IND,
    MSG_ID_MEDIA_VRSI_PLAY_TAG_FINISH_IND,
    MSG_ID_MEDIA_VRSI_PLAY_TTS_FINISH_IND,
    MSG_ID_MED_VRSI_CODE_END = MSG_ID_MEDIA_VRSI_PLAY_TTS_FINISH_IND,
    MSG_ID_MEDIA_CTM_OPEN_REQ,
    MSG_ID_MED_CTM_CODE_BEGIN = MSG_ID_MEDIA_CTM_OPEN_REQ,
    MSG_ID_MEDIA_CTM_OPEN_CNF,
    MSG_ID_MEDIA_CTM_CLOSE_REQ,
    MSG_ID_MEDIA_CTM_CLOSE_CNF,
    MSG_ID_MEDIA_CTM_CONNECT_REQ,
    MSG_ID_MEDIA_CTM_CONNECT_CNF,
    MSG_ID_MEDIA_CTM_CONNECTED_IND,
    MSG_ID_MEDIA_CTM_SEND_TEXT_REQ,
    MSG_ID_MEDIA_CTM_SEND_TEXT_CNF,
    MSG_ID_MEDIA_CTM_RECV_TEXT_IND,
    MSG_ID_MEDIA_CTM_EVENT_IND,
    MSG_ID_MED_CTM_CODE_END = MSG_ID_MEDIA_CTM_EVENT_IND,
    MSG_ID_MEDIA_BT_AUDIO_OPEN_REQ,
    MSG_ID_MED_BT_AUDIO_CODE_START = MSG_ID_MEDIA_BT_AUDIO_OPEN_REQ,
    MSG_ID_MEDIA_BT_AUDIO_OPEN_CNF,
    MSG_ID_MEDIA_BT_AUDIO_OPEN_IND,
    MSG_ID_MEDIA_BT_AUDIO_CLOSE_REQ,
    MSG_ID_MEDIA_BT_AUDIO_CLOSE_CNF,
    MSG_ID_MEDIA_BT_AUDIO_CLOSE_IND,
    MSG_ID_MEDIA_BT_AUDIO_TURN_ON_REQ,
    MSG_ID_MEDIA_BT_AUDIO_TURN_OFF_REQ,
    MSG_ID_MED_BT_AUDIO_CODE_END = MSG_ID_MEDIA_BT_AUDIO_TURN_OFF_REQ,
    MSG_ID_MEDIA_IN_PROC_CALL_REQ,
    MSG_ID_MEDIA_BT_OPEN_CODEC_REQ,
    MSG_ID_MEDIA_BT_CLOSE_CODEC_REQ,
    MSG_ID_MEDIA_BT_CLOSE_CODEC_IND,
    MSG_ID_MED_RTP_CREATE_REQ,
    MSG_ID_MED_RTP_CODE_BEGIN = MSG_ID_MED_RTP_CREATE_REQ,   
    MSG_ID_MED_RTP_CLOSE_REQ,
    MSG_ID_MED_RTP_SET_REMOTE_ADDR_REQ,
    MSG_ID_MED_RTP_SET_NOTIFY_REQ,
    MSG_ID_MED_RTP_CLEAR_NOTIFY_REQ,
    MSG_ID_MED_RTP_SEND_REQ,
    MSG_ID_MED_RTP_RECV_REQ,
    MSG_ID_MED_RTP_SEND_RTCP_REQ,
    MSG_ID_MED_RTP_RECV_RTCP_REQ,
    MSG_ID_MED_RTP_SET_VALUE_REQ,
    MSG_ID_MED_RTP_GET_VALUE_REQ,
    MSG_ID_MED_RTP_SEND_DTMF_START_REQ,
    MSG_ID_MED_RTP_SEND_DTMF_STOP_REQ,
    MSG_ID_MED_RTP_CHECK_SRTP_PARAM_REQ,
    MSG_ID_MED_RTP_GET_SRTP_PARAM_REQ,
    MSG_ID_MED_RTP_SET_SRTP_PARAM_REQ,
    MSG_ID_MED_RTP_NOTIFY_IND,
    MSG_ID_MED_VOIP_INIT_REQ,
    MSG_ID_MED_VOIP_ENCODING_START_REQ,
    MSG_ID_MED_VOIP_ENCODING_STOP_REQ,
    MSG_ID_MED_VOIP_DECODING_START_REQ,
    MSG_ID_MED_VOIP_DECODING_STOP_REQ,
    MSG_ID_MED_VOIP_L1_ENCODING_CALLBACK_IND,
    MSG_ID_MED_VOIP_GET_VALUE_REQ,
    MSG_ID_MED_VOIP_SET_VALUE_REQ,
    MSG_ID_MED_VOIP_GET_CODEC_CAP_REQ,
    MSG_ID_MED_VOIP_MIXER_ADD_REQ,
    MSG_ID_MED_VOIP_MIXER_REMOVE_REQ,   
    MSG_ID_MED_VOIP_RTP_DISCONNECT_IND,
    MSG_ID_MED_RTP_CODE_END = MSG_ID_MED_VOIP_MIXER_REMOVE_REQ,
    MSG_ID_MEDIA_STREAM_INIT_REQ,
    MSG_ID_MED_STREAM_CODE_BEGIN = MSG_ID_MEDIA_STREAM_INIT_REQ,
    MSG_ID_MEDIA_STREAM_CONNECT_REQ,
    MSG_ID_MEDIA_STREAM_ABORT_REQ,
    MSG_ID_MEDIA_STREAM_FORCE_ABORT_REQ,
    MSG_ID_MEDIA_STREAM_SET_STOP_TIME_REQ,
    MSG_ID_MEDIA_STREAM_SEEK_REQ,
    MSG_ID_MEDIA_STREAM_GET_DL_PERCENTAGE_REQ,
    MSG_ID_MEDIA_STREAM_PLAY_REQ,
    MSG_ID_MEDIA_STREAM_STOP_REQ,
    MSG_ID_MEDIA_STREAM_DISCONNECT_REQ,
    MSG_ID_MEDIA_STREAM_DEINIT_REQ,
    MSG_ID_MEDIA_STREAM_GET_INFO_REQ,
    MSG_ID_MEDIA_STREAM_SET_INFO_REQ,
    MSG_ID_MEDIA_STREAM_SET_AUDIO_LEVEL_REQ,
    MSG_ID_MEDIA_STREAM_SWITCH_SCREEN_VIDEOSTOP_REQ,
    MSG_ID_MEDIA_STREAM_SWITCH_SCREEN_VIDEOSTART_REQ,
    MSG_ID_MEDIA_STREAM_SET_PARAM_REQ,
    MSG_ID_MEDIA_STREAM_GET_PLAYING_TIME_REQ,
    MSG_ID_MEDIA_STREAM_L1_CALLBACK_IND,
    MSG_ID_MEDIA_STREAM_CONNECTED_IND,
    MSG_ID_MEDIA_STREAM_SEEK_IND,
    MSG_ID_MEDIA_STREAM_PLAY_IND,
    MSG_ID_MED_STREAM_CODE_END = MSG_ID_MEDIA_STREAM_PLAY_IND,


    MSG_ID_MEDIA_VCALL_VIDEO_CODEC_OPEN_REQ,
    MSG_ID_MED_VCALL_CODE_BEGIN = MSG_ID_MEDIA_VCALL_VIDEO_CODEC_OPEN_REQ,
    MSG_ID_MEDIA_VCALL_VIDEO_CODEC_CLOSE_REQ,
    MSG_ID_MEDIA_VCALL_VIDEO_CODEC_REPORT_IND,
    MSG_ID_MEDIA_VCALL_CHANNEL_REPORT_IND,
 // MSG_ID_MEDIA_VCALL_CHANNEL_STATUS_IND,
    MSG_ID_MEDIA_VCALL_VIDEO_REPLENISH_DATA_READY_IND,
    MSG_ID_MEDIA_VCALL_VIDEO_ENCODE_DATA_READY_IND,
    MSG_ID_MEDIA_VCALL_VIDEO_DECODE_DATA_READY_IND,
    MSG_ID_MED_VCALL_CODE_END = MSG_ID_MEDIA_VCALL_VIDEO_DECODE_DATA_READY_IND,

    /**
      * @defgroup MTV_SAP Mobile TV SAP
      * @{
      */

    /**
      * This message is sent to initialize the mobile TV engine.
      *
      * Direction: MMI -> MED
      * @see media_mtv_open_req_struct
      */
    MSG_ID_MEDIA_MTV_OPEN_REQ, MSG_ID_MEDIA_MTV_CODE_BEGIN = MSG_ID_MEDIA_MTV_OPEN_REQ,

    /**
      * This message is sent to configure mobile TV engine.
      *
      * Direction: MMI -> MED
      * @see media_mtv_config_req_struct
      */
    MSG_ID_MEDIA_MTV_CONFIG_REQ,

    /**
      * This message is sent to find unsaved recording.
      *
      * Direction: MMI -> MED
      * @see media_mtv_find_unsaved_recording_req_struct
      */
    MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ,

    /**
      * This message is sent to recover unsaved recording into file.
      *
      * Direction: MMI -> MED
      * @see media_mtv_recover_recording_req_struct
      */
    MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ,

    /**
      * Comment for MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ
      *
      * Direction: MMI -> MED
      * @see media_mtv_abort_recovering_req_struct
      */
    MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ,

    /**
      * This message is sent to discard unsaved recording.
      *
      * Direction: MMI -> MED
      * @see media_mtv_discard_unsaved_recording_req_struct
      */
    MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ,

    /**
      * This message is sent to notify the  completion of recovering.
      *
      * Direction: MED -> MMI
      * @see media_mtv_complete_recovering_ind_struct
      */
    MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND,

    /**
      * This message is sent to start service searching.
      *
      * Direction: MMI -> MED
      * @see media_mtv_search_services_req_struct
      */
    MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ,

    /**
      * This message is sent to notify searching progress in percentage.
      *
      * Direction: MED -> MMI
      * @see media_mtv_search_progress_ind_struct
      */
    MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND,

    /**
      * This message is sent to abort service searching.
      *
      * Direction: MMI -> MED
      * @see media_mtv_abort_searching_req_struct
      */
    MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ,

    /**
      * This message is sent to indicate a service is found. Basic service information
      * can be found in the message. Other details such as program schedule can be
      * retrieved by function interface.
      *
      * Direction: MED -> MMI
      * @see media_mtv_service_found_ind_struct
      */
    MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND,

    /**
      * This message is sent to start a service with specified activities.
      *
      * Direction: MMI -> MED
      * @see media_mtv_start_service_req_struct
      */
    MSG_ID_MEDIA_MTV_START_SERVICE_REQ,

    /**
      * This message is sent to indicate some service event has happened.
      *
      * Direction: MED -> MMI
      * @see media_mtv_service_event_ind_struct
      */
    MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND,

    /**
      * This message is sent to start playing a service if it is paused or stopped.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_play_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ,

    /**
      * This message is sent to pause playing a service.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_pause_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ,

    /**
      * This message is sent to stop playing a service.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_stop_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ,

    /**
      * This message is sent to seek in time-shifted playback.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_seek_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ,

    /**
      * This message is sent to set playback rate such 4x fast forward or 2x rewind.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_set_rate_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ,

    /**
      * This message is sent to take a video snapshot.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_snapshot_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ,

    /**
      * This message is sent to retrieve player status information.
      *
      * Direction: MMI -> MED
      * @see media_mtv_player_get_status_req_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ,

    /**
      * This message is sent to indicate some player event has happened.
      *
      * Direction: MED -> MMI
      * @see media_mtv_player_event_ind_struct
      */
    MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND,

    /**
      * This message is sent to start recording.
      *
      * Direction: MMI -> MED
      * @see media_mtv_recorder_start_req_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_START_REQ,

    /**
      * This message is sent to stop recording.
      *
      * Direction: MMI -> MED
      * @see media_mtv_recorder_stop_req_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ,

    /**
      * This message is sent to save a recording into video file.
      *
      * Direction: MMI -> MED
      * @see media_mtv_recorder_save_req_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ,

    /**
      * Comment for MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ
      *
      * Direction: MMI -> MED
      * @see media_mtv_recorder_abort_saving_req_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ,

    /**
      * This message is sent to discard unsaved recording.
      *
      * Direction: MMI -> MED
      * @see media_mtv_recorder_discard_recording_req_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ,

    /**
      * This message is sent to retrieve recorder status information.
      *
      * Direction: MMI -> MED
      * @see media_mtv_recorder_get_status_req_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ,

    /**
      * This message is sent to indicate some recorder event has happened.
      *
      * Direction: MED -> MMI
      * @see media_mtv_recorder_event_ind_struct
      */
    MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND,

    /**
      * This message is sent to set service parameter.
      *
      * Direction: MMI -> MED
      * @see media_mtv_set_param_req_struct
      */
    MSG_ID_MEDIA_MTV_SET_PARAM_REQ,

    /**
      * This message is sent to get service parameter.
      *
      * Direction: MMI -> MED
      * @see media_mtv_get_param_req_struct
      */
    MSG_ID_MEDIA_MTV_GET_PARAM_REQ,

    /**
      * This message is sent to retrieve service status information.
      *
      * Direction: MMI -> MED
      * @see media_mtv_service_get_status_req_struct
      */
    MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ,

    /**
      * This message is sent to stop a service.
      *
      * Direction: MMI -> MED
      * @see media_mtv_stop_service_req_struct
      */
    MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ,

    /**
      * This message is sent to close the mobile TV engine.
      *
      * Direction: MMI -> MED
      * @see media_mtv_close_req_struct
      */
    MSG_ID_MEDIA_MTV_CLOSE_REQ,

    /**
      * This message to sent to perform asynchronous file writing.
      */
    MSG_ID_MEDIA_MTV_ASYNC_WRITE,

    /**
      * This message to sent to perform asynchronous callback.
      */
    MSG_ID_MEDIA_MTV_ASYNC_CALLBACK, MSG_ID_MEDIA_MTV_CODE_END = MSG_ID_MEDIA_MTV_ASYNC_CALLBACK,
    
    /** @} */

    MSG_ID_MED_CODE_END = MSG_ID_MEDIA_MTV_CODE_END,

/*------------------------MED_MSG_CODE_END -----------------*/

