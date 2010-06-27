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
 *   med_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of media task.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _MED_STRUCT_H
#define _MED_STRUCT_H

/*==== DEFINES ========*/

#define MAX_MELODY_FILE_NAME 50

/* define for kal_wchar */
#define ENCODE_BYTE   (2)

#define MAX_VM_FILE_NAME 20
#define MAX_NUM_OF_VM_LIST 20

#define MAX_MEDIA_FILE_NAME 512

#ifndef __VR_MED_CONST__
#define __VR_MED_CONST__
#define VR_SD_MAX_GROUP_TAG_NUM 20
#define VR_SD_MAX_GROUP_NUM 4
#define VR_MAX_RCG_RESULT_NUM 10
#define VR_MAX_DB_PATH_LEN 80
#define VR_MAX_ADD_ONCE_NUM 20
#endif /* __VR_MED_CONST__ */ 

#ifndef __BT_MED_CONST__
#define __BT_MED_CONST__
#define BT_HFP 0
#define BT_A2DP 1

#define BT_A2DP_AGGRESSIVE_MODE 0
#define BT_A2DP_PASSIVE_MODE 1
#define BT_A2DP_PTS_PASSIVE_MODE 2

#define BT_HFP_EARPHONE_MODE 0
#define BT_HFP_CARKIT_MODE 1
#endif /* __BT_MED_CONST__ */ 

#ifndef __CTM_MED_CONST__
#define __CTM_MED_CONST__
#define CTM_SEND_TEXT_CHAR_MAX_NUM 20
#define CTM_MAX_SEND_REQ_NUM 10
typedef struct
{
    kal_int16 cprm_tone_demod_down_samp;    /* 1 (0, 1) */
    kal_uint8 input_vol;
    kal_uint8 output_vol;
} ctm_param_struct;
#endif /* __CTM_MED_CONST__ */ 

#define VID_MJPG_ACCURATE_TIME_SHIFT    (10)  /* shift 10 bit for accuracy */


/*==== MESSAGE STRUCTS ==========*/

/* common */
typedef struct
{
    LOCAL_PARA_HDR
}
med_startup_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
med_startup_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 location;
    void **buffer_p;
    kal_uint32 buffer_size;
}
media_get_buffer_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 location;
    void **buffer_p;
}
media_free_buffer_req_struct;

typedef struct
{
    kal_uint8 play_audio;
    kal_uint8 audio_path;
    kal_bool mute;
    kal_uint32 volume;
} media_config_audio_struct;

typedef struct
{
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 display_offset_x;
    kal_uint16 display_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 play_speed;
    kal_uint8 display_device;
    kal_uint16 seq_num;
    kal_int16 lcd_rotate;
    kal_uint16 repeats;                     /* repeat count, 0xffff: infinite */

    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint16 video_display_offset_x;
    kal_uint16 video_display_offset_y;
    kal_bool force_lcd_hw_trigger;
#if (defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)) */

    kal_bool visible;
    kal_uint32 brightness;
    kal_uint32 contrast;
    kal_uint32 gamma;
} media_config_video_struct;

/* audio */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_get_audio_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 mode;
}
l4aud_get_audio_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 mode;
}
l4aud_set_audio_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
l4aud_set_audio_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 gpio_device;
}
l4aud_gpio_detect_ind_struct;

typedef struct
{
    kal_uint8 mode;
    kal_uint8 melody[7];
    kal_uint8 sound[7];
    kal_uint8 keytone[7];
    kal_uint8 speech[7];
    kal_uint8 mic[7];
    kal_uint8 sidetone;
    kal_uint8 max_melody_volume_gain;
    kal_uint8 melody_volume_gain_step;
    kal_uint8 tv_out_volume_gain[7];
}
audio_profile_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    audio_profile_struct audio_profile;
}
l4aud_set_audio_profile_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
l4aud_set_audio_profile_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 mode;
}
l4aud_get_audio_profile_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_profile_struct audio_profile;
}
l4aud_get_audio_profile_cnf_struct;

#define SPEECH_FIR_COEFF_NUM 45
#define MELODY_FIR_COEFF_NUM 25
#define AUDIO_COMP_COEFF_NUM 45

typedef struct
{
    kal_int16 speech_input_FIR_coeffs[6][SPEECH_FIR_COEFF_NUM];
    kal_int16 speech_output_FIR_coeffs[6][SPEECH_FIR_COEFF_NUM];
    kal_uint16 selected_FIR_output_index;
    kal_uint16 speech_common_para[12];
    kal_uint16 speech_mode_para[8][8];
    kal_uint16 max_swing;
    kal_int16 Melody_FIR_Coeff_Tbl[MELODY_FIR_COEFF_NUM];
#ifdef AUDIO_COMPENSATION_ENABLE
    kal_int16 audio_compensation_coeff[2][AUDIO_COMP_COEFF_NUM]; /* Loud speaker and earphone mode*/
#endif
}
audio_param_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    audio_param_struct audio_param;
}
l4aud_set_audio_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
l4aud_set_audio_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_get_audio_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_param_struct audio_param;
}
l4aud_get_audio_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 volume_type;
}
l4aud_get_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint8 volume_type;
    kal_uint8 volume;
}
l4aud_get_volume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 volume_type;
    kal_uint8 volume_level;
}
l4aud_get_gain_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint8 volume_gain;
}
l4aud_get_gain_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_type;
    kal_uint8 device;
}
l4aud_audio_set_device_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_set_device_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_type;
    kal_uint8 volume;
    kal_uint8 aux_volume;   /* for side tone used */
    kal_uint8 mode;
    kal_bool apply;
}
l4aud_audio_set_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_set_volume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_type;
    kal_uint8 volume_level;
    kal_uint8 gain;
}
l4aud_audio_set_gain_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_set_gain_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_id;
    kal_uint8 play_style;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
}
l4aud_audio_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_id;
}
l4aud_audio_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_MELODY_FILE_NAME];
    kal_uint8 play_style;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
}
l4aud_audio_play_by_name_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_play_by_name_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_MELODY_FILE_NAME];
}
l4aud_audio_stop_by_name_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_stop_by_name_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    const kal_uint8 *melody;
    kal_uint32 len;
    kal_uint8 format;
    kal_uint32 start_offset;
    kal_uint32 end_offset;
    kal_uint8 play_style;
    kal_uint16 identifier;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint8 blocking;
}
l4aud_audio_play_by_string_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_play_by_string_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_audio_stop_by_string_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_stop_by_string_cnf_struct;

/* this is the same to device_tones_struct and L1SP_Tones */
typedef struct
{
    kal_uint16 freq1;           /* First frequency                                    */
    kal_uint16 freq2;           /* Second frequency                                   */
    kal_uint16 on_duration;     /* Tone on duation, in ms unit, 0 for continuous tone */
    kal_uint16 off_duration;    /* Tone off duation, in ms unit, 0 for end of playing */
    kal_int8 next_operation;    /* Index of the next tone                             */
} aud_tones_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    aud_tones_struct *tone_list;
    kal_uint8 volume;
    kal_uint16 identifier;
}
l4aud_audio_play_tone_seq_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_play_tone_seq_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint16 identifier;
}
l4aud_audio_stop_tone_seq_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_stop_tone_seq_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 imy_len;
    kal_uint8 play_style;
    kal_uint16 identifier;
}
l4aud_audio_demo_imy_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_demo_imy_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    kal_uint16 identifier;
}
l4aud_audio_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 device;
    kal_bool mute;
}
l4aud_audio_mute_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_mute_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_type;
    kal_bool fir_on;
}
l4aud_audio_set_fir_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_set_fir_cnf_struct;

/* speech */

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool speech_on;
    kal_uint8 rat_mode;
}
l4aud_sp_set_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_sp_set_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 mic_volume;
    kal_uint8 sidetone_volume;
}
l4aud_sp_set_input_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_sp_set_input_mode_cnf_struct;

/* voice memo */

/* informatiom struct for voice memo files */
typedef struct
{
    kal_uint16 no_of_vm;
    kal_wchar file_name_list[MAX_NUM_OF_VM_LIST][MAX_VM_FILE_NAME];
    kal_bool more_entry;
    kal_uint32 free_space;
    kal_uint32 reserved;
}
aud_vm_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 direction;
}
l4aud_vm_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_record_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_VM_FILE_NAME];
}
l4aud_vm_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
    kal_wchar file_name[MAX_VM_FILE_NAME];
}
l4aud_vm_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_bool delete_all;
}
l4aud_vm_delete_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_delete_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_abort_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 result;
}
l4aud_vm_pause_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_resume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_VM_FILE_NAME];
}
l4aud_vm_append_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_append_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_get_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    aud_vm_info_struct vm_info;
}
l4aud_vm_get_info_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar old_file_name[MAX_VM_FILE_NAME];
    kal_wchar new_file_name[MAX_VM_FILE_NAME];
}
l4aud_vm_rename_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_rename_cnf_struct;

/* indication */

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 result;
}
l4aud_vm_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_vm_read_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_vm_write_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint8 play_style;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    void* cache_p;              /* cache */
}
l4aud_media_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint8 format;
    kal_uint8 quality;
    kal_bool  default_input;
    kal_uint8 input_source;
    kal_uint32 size_limit;
    kal_uint32 time_limit;    
}
l4aud_media_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_record_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
}
l4aud_media_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
}
l4aud_media_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_pause_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
}
l4aud_media_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_resume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
}
l4aud_media_store_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint8 play_style;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint16 identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    void *cache_p;
}
l4aud_media_restore_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 vol_type;
    kal_bool mute;
}
media_aud_set_mute_req_struct;

/* indication */

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_media_write_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_media_read_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 result;
    kal_uint16 identifier;
}
l4aud_media_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 duration;
    kal_uint16 identifier;
}
l4aud_media_play_update_dur_ind_struct;

/* FM Radio Begin: Added by Tim */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 output_path;
}
media_fmr_power_on_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_fmr_power_off_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 freq;
}
media_fmr_set_freq_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 mute;
}
media_fmr_mute_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 freq;
    kal_uint8 is_step_up;
}
media_fmr_check_is_valid_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 is_valid;
}
media_fmr_check_is_valid_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 freq;
    kal_uint8 is_step_up;
}
media_fmr_get_signal_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 signal_level;
}
media_fmr_get_signal_level_cnf_struct;

typedef struct 
{
   LOCAL_PARA_HDR
} 
media_fmr_evaluate_threshold_req_struct;

/* FM Radio End: Added by Tim */


//Analog tv begin
#ifdef  ANALOG_TV_SUPPORT

typedef struct {
   LOCAL_PARA_HDR
  // kal_uint8 output_path;
} 
media_analog_tv_open_path_req_struct;

typedef struct {
   LOCAL_PARA_HDR
} 
media_analog_tv_close_path_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 mute;
} 
media_analog_tv_mute_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 channel;
} 
media_analog_tv_set_channel_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 ret;
} 

media_analog_tv_set_channel_cnf_struct;

typedef struct {
   LOCAL_PARA_HDR
}
media_analog_tv_power_up_req_struct;

typedef struct {
   LOCAL_PARA_HDR
}
media_analog_tv_power_down_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 chan;
   
} 
media_analog_tv_get_valid_channel_req_struct;

typedef struct {
   LOCAL_PARA_HDR
   kal_uint8 ret;
} 
media_analog_tv_get_valid_channel_cnf_struct;
#endif //ANALOG_TV_SUPPORT


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 event;
    kal_uint32 seq_no;
}
aud_media_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 src_id;
    kal_uint8 event;
    kal_uint32 seq_no;
}
aud_media_play_stream_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 mod_id;
    kal_uint8 level;
}
media_aud_block_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 enabled;
}
media_aud_set_vibrator_enabled_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool use_default_handle;
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint8 *audio_data;
    kal_uint32 len;
    kal_uint8 format;	
}
media_aud_get_duration_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_aud_get_progress_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 progress;
}
media_aud_set_progress_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
}
media_aud_check_is_pure_audio_req_struct;

/**
  * CAMERA 
  */

typedef enum
{
    CAM_XENON_FLASH_OFF = 0,
    CAM_XENON_FLASH_CHARGING,
    CAM_XENON_FLASH_READY,
    CAM_XENON_FLASH_TIMEOUT,
    CAM_XENON_FLASH_LOW_BATTERY,
    CAM_XENON_FLASH_NUM
}
media_cam_xenon_flash_status_enum;

typedef struct
{
    LOCAL_PARA_HDR
    media_cam_xenon_flash_status_enum status;
}
media_cam_xenon_flash_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 seq_num;
}
media_cam_power_up_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 delay_time;
}
media_cam_power_down_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int16 result;
    kal_uint16 seq_num;
}
media_cam_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint16 buffer_width;
    kal_uint16 buffer_height;
    kal_uint16 preview_width;
    kal_uint16 preview_height;
    kal_uint16 preview_offset_x;
    kal_uint16 preview_offset_y;
    kal_uint16 camera_offset_x;
    kal_uint16 camera_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 frame_rate;
    kal_int16 contrast;
    kal_int16 brightness;
    kal_int16 saturation;
    kal_int16 hue;
    kal_int16 gamma;
    kal_int16 WB;
    kal_int16 exposure;
    kal_int16 effect;
    kal_int16 zoom_factor;
    kal_int16 rotate;
    kal_int16 lcd_rotate;
    kal_uint8 snapshot_number;
    kal_bool night_mode;
    kal_uint8 banding_freq;
    kal_uint16 flash_mode;  /* AUTO, ON, OFF, REDEYE */

    kal_bool  lcd_update;
    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint32 src_key_color;

    kal_uint8 continue_capture;

    /* LCD Setting */
    kal_uint32 roi_background_color;    /* set the background color */

    /* AF */
    kal_uint16 af_zone0_x;  /* AF Zone 0 X-coordinate, (0,0) means left-top corner */
    kal_uint16 af_zone0_y;  /* AF Zone 0 Y-coordinate */
    kal_uint16 af_zone1_x;  /* AF Zone 1 X-coordinate */
    kal_uint16 af_zone1_y;  /* AF Zone 1 Y-coordinate */
    kal_uint16 af_zone2_x;  /* AF Zone 2 X-coordinate */
    kal_uint16 af_zone2_y;  /* AF Zone 2 Y-coordinate */
    kal_uint16 af_zone3_x;  /* AF Zone 3 X-coordinate */
    kal_uint16 af_zone3_y;  /* AF Zone 3 Y-coordinate */
    kal_uint16 af_zone4_x;  /* AF Zone 4 X-coordinate */
    kal_uint16 af_zone4_y;  /* AF Zone 4 Y-coordinate */

#if defined(MT6225) || defined(MT6226D) || defined(MT6226) || defined(MT6226M) || defined(MT6227)|| defined (MT6227D) || defined(MT6235)
    /* ISP Setting */

    kal_uint8 dsc_mode;         /* NORMALSCENE, PORTRAIT, LANDSCAPE, SPORT, FLOWER, NIGHTSCENE, TV, AV, ISO */
    kal_uint8 ae_metering_mode; /* AUTO, SPOT, CENTRAL WEIGHT, AVERAGE */
    kal_uint8 af_mode;          /* AUTO, MACRO, INFINITE, MANUAL */
    kal_uint8 af_metering_mode; /* SINGLE, MULTI3, MULTI5 */
    kal_uint8 iso_setting;      /* AUTO, 100, 200, 400 */

#elif (defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))
    /* ISP Setting */

    kal_uint8 dsc_mode;         /* NORMALSCENE, PORTRAIT, LANDSCAPE, SPORT, FLOWER, NIGHTSCENE, TV, AV, ISO */
    kal_uint8 ae_metering_mode; /* AUTO, SPOT, CENTRAL WEIGHT, AVERAGE */
    kal_uint8 af_mode;          /* AUTO, MACRO, INFINITE, MANUAL */
    kal_uint8 af_metering_mode; /* SINGLE, MULTI3, MULTI5 */
    kal_uint16 tv_setting;      /* Shutter Priority Value Setting */
    kal_uint8 av_setting;       /* Aperture Priority Value Setting */
    kal_uint8 iso_setting;      /* AUTO, 100, 200, 400 */

    /* IPP Setting */
    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint8 overlay_color_depth;              /* The color depth of overlay frame buffer */
    kal_uint8 overlay_frame_source_key;
    kal_uint16 overlay_frame_width;             /* Image width of overlay frame buffer */
    kal_uint16 overlay_frame_height;            /* Image height of overlay frame buffer */
    kal_uint32 overlay_frame_buffer_address;    /* The starting address of overlay frame buffer */
    /* TV Setting */
    kal_uint8 tv_output_mode;
    kal_bool tv_output;
    kal_uint16 tv_output_width;                 /* image width for TV output */
    kal_uint16 tv_output_height;                /* image height for TV output */
    kal_uint16 tv_output_offset_x;              /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;              /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;       /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;       /* image buffer2 for TV source buffer */
    kal_uint32 tv_rotate_buffer1_address;       /* rotate buffer1 for TV source buffer */
    kal_uint32 tv_rotate_buffer2_address;       /* rotate buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;           /* image buffer size for TV source buffer */
#endif 

}
media_cam_preview_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_cam_preview_fail_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_stop_req_struct;

typedef struct
{
    kal_uint32 file_size[20];
    kal_uint32 file_address[20];
}
media_jpegs_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *text_buf;
    kal_uint32 buf_length;
    kal_uint8 barcode_type;
} media_cam_barcode_capture_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 source_device;
    kal_uint16 image_width;
    kal_uint16 image_height;
    void *image_buffer_p;
    void *data;
    void **capture_buffer_p;
    kal_uint32 file_buffer_len;
    kal_uint32 *file_size_p;
    kal_int16 flash_mode;
    kal_uint8 image_quality;
    kal_uint8 gray_mode;
    kal_uint8 snapshot_number;
    kal_uint32 capture_layer;   /* capture layer for capture from mem(lcd) case */
    kal_uint16 roi_offset_x;    /* offset x for capture from mem(lcd) case */
    kal_uint16 roi_offset_y;    /* offset y for capture from mem(lcd) case */
    media_jpegs_struct *jpegs_p;
    kal_uint8 continue_capture;
#if (defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238))
    /* JPEG Setting */
    kal_uint8 jpeg_yuv_mode;

    kal_bool thumbnail_mode;                    /* add thumbnail in JPEG file or not */
    kal_uint16 thumbnail_width;
    kal_uint16 thumbnail_height;
    /* ISP Setting */
    kal_bool manual_wb;                         /* KAL_TRUE or KAL_FALSE to enable or disable manual white balance */
    /* IPP Setting */
    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE */
    kal_uint8 overlay_color_depth;              /* 1/2/4/8 bpp */
    kal_uint8 overlay_frame_source_key;         /* source key of the overlay frame buffer */
    kal_uint16 overlay_frame_width;             /* overlay frame width */
    kal_uint16 overlay_frame_height;            /* overlay frame height */
    kal_uint32 overlay_frame_buffer_address;    /* bsae address of the overlay frame buffer */

    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    /* Display Setting */
    kal_uint8 lcd_id;
    kal_uint16 lcm_start_x;                 /* the start x axis of LCM to be updated */
    kal_uint16 lcm_start_y;                 /* the start y axis of LCM to be updated */
    kal_uint16 lcm_end_x;                   /* the end x axis of LCM to be updated */
    kal_uint16 lcm_end_y;                   /* the end y axis of LCM to be updated */
    //      kal_uint16      roi_offset_x;   /* the ROI window offset x from main window */
    //      kal_uint16      roi_offset_y;   /* the ROI window offset y from main window */
    kal_uint32 update_layer;                /* the updated layer */
    kal_uint32 hw_update_layer;             /* which layer will be applied by hw trigger or direct couple for MT6219 only */

    kal_bool display;   /* output to LCM or TV */
    kal_uint32 frame_buffer_address;
    kal_uint32 frame_buffer_size;

    kal_bool tv_output;                     /* works when display item is KAL_TRUE */
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer, if snapshot_number==1, this buffer is not necessary */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238)) */ 

#ifdef __SW_JPEG_CODEC_SUPPORT__
    kal_bool memory_output; /* is direct couple to another buffer */
    //IMAGE_FORMAT_ENUM memory_output_type;
    kal_uint16 memory_output_width;
    kal_uint16 memory_output_height;
    kal_uint32 memory_output_buffer_address;
    kal_uint32 memory_output_buffer_size;
#endif

}
media_cam_capture_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    kal_int16 value;
}
media_cam_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 flash_mode;
}
media_cam_set_flash_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
    kal_uint8 cause;
}
media_cam_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 event;
    kal_uint8 cause;
    kal_uint8 encoding;
    kal_uint8 nsymbol;
    kal_uint8 symbolid;
    kal_uint8 paritydata;
    kal_uint8 barcode_type;
}media_cam_barcode_event_ind_struct;


typedef struct
{
    kal_uint32 mwb_buffer_address;
    kal_uint16 mwb_image_width;
    kal_uint16 mwb_image_height;
} media_cam_mwb_process_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_cam_mwb_process_struct *pmwb;
    kal_uint8 op_type;
} media_cam_mwb_operation_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 palette_size;
    kal_uint32 *palette_addr;
} media_cam_set_overlay_palette_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 count;
}
media_cam_capture_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool zoom_in;
    kal_uint8 zoom_limit;
    kal_uint8 zoom_step;
    kal_uint8 zoom_speed;
}
media_cam_start_fast_zoom_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_stop_fast_zoom_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *factor;
}
media_cam_get_fast_zoom_factor_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *total_steps;
    kal_uint32 *current_steps;
    kal_bool *flag;
}
media_cam_get_focus_steps_req_struct;

/* IMAGE */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 display_width;
    kal_uint16 display_height;

    kal_uint16 image_clip_x1;   /* clip window start x for clipping decoded image */
    kal_uint16 image_clip_x2;   /* clip window end x for clipping decoded image */
    kal_uint16 image_clip_y1;   /* clip window start y for clipping decoded image */
    kal_uint16 image_clip_y2;   /* clip window end y for clipping decoded image */

    int start_x, start_y;           /* destination position ( maybe < 0) */
    void *image_buffer_p;           /* destination buffer address */
    kal_uint32 image_buffer_size;   /* destination buffer size */
    kal_uint32 image_buffer_width;  /* destination buffer width */
    kal_uint32 image_buffer_height; /* destination buffer height */
    kal_uint8 image_buffer_format;  /* destination buffer format */

    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;             /* source (memory pointer or file name) */
    kal_uint32 file_size;   /* source size or file size */
    kal_uint16 seq_num;     /* serial number */
    kal_uint8 blocking;     /* blocking or not */
    void (*callback) (kal_int32 result);

    /* FOR JPEG ONLY */
    kal_bool jpeg_thumbnail_mode;   /* decode thumbnail or not */
    kal_bool jpeg_retry_thumbnail;
#if (defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6235) || defined(MT6238))
    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool memory_output;             /* output another image for TV output */
    kal_uint16 memory_output_width;     /* image width for TV output */
    kal_uint16 memory_output_height;    /* image height for TV output */
    kal_uint32 memory_output_buffer_address;
    kal_uint32 memory_output_buffer_size;
#endif /* (defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) ||defined(MT6225) || defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6235) || defined(MT6238)) */ 
    kal_uint16 decoded_image_width;     /* decoded image width */

    /* FOR GIF HW V2 ONLY */
    kal_uint32 cache_id;
    void *lct_addr;
    void *gct_addr;
    void *gif_info;
    kal_uint16 frame_number;
    kal_bool transparent_enable;
    kal_uint32 layer_src_key;
    kal_bool use_disposal_method;
    /* FOR PNG V1 ONLY */
    void (*blt_callback) (kal_uint8 *src, kal_uint32 src_pitch, kal_int16 src_x, kal_int16 src_y, kal_uint16 src_width, kal_uint16 src_height, kal_uint8 src_color_mode, kal_uint8 *dest, kal_uint32 dest_pitch, kal_int16 dest_x, kal_int16 dest_y, kal_uint8 dest_color_mode, kal_int16 clipx1, kal_int16 clipy1, kal_int16 clipx2, kal_int16 clipy2, kal_bool src_key_enable, kal_uint32 src_key); /* some case need MMI to bitblt to layer buffer. */

}
media_img_decode_req_struct;

typedef struct
{
    kal_char *filename;
    kal_char make[35];
    kal_char model[35];
    kal_char orientation[11];
    kal_char x_resolution[24];
    kal_char y_resolution[24];
    kal_char resolution_unit[12];
    kal_char software[35];
    kal_char date_time[35];
    kal_char ycbcr_positioning[9];
    kal_char exif_ifd[14];

    kal_char exposure_time[24];
    kal_char fnumber[24];
    kal_char exposure_program[18];
    kal_char iso_speed_ratings[6];
    kal_char exif_version[20];
    kal_char date_time_original[35];
    kal_char date_time_digitized[35];
    kal_char components_config[6];
    kal_char exposure_bias_value[24];
    kal_char metering_mode[24];
    kal_char light_source[17];
    kal_char flash[80];
    kal_char maker_note[20];
    kal_char flashpix_version[20];
    kal_char color_space[13];
    kal_char pixel_x_dimension[14];
    kal_char pixel_y_dimension[14];
    kal_char exposure_mode[16];
    kal_char digital_zoom_ratio[24];
    kal_char scene_capture_type[12];

} media_img_exif_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    media_img_exif_info_struct *exif_info;
}
media_img_exif_decode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
    kal_uint16 image_width;
    kal_uint16 image_height;
}
media_img_decode_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 cause;
    kal_uint32 arg0;
    kal_uint32 arg1;
}
media_img_decode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint8 image_quality;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint16 target_width;
    kal_uint16 target_height;
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 file_buffer_len;
    kal_uint32 *file_size_p;
    kal_uint16 seq_num;
    kal_uint8 blocking;
    kal_uint8 gray_mode;
#if (defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6225) || defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6235) || defined(MT6238))
    kal_uint8 jpeg_yuv_mode;    /* YUV420, YUV422 or Gray mode */

    kal_bool thumbnail_mode;    /* add thumbnail in JPEG file or not */
    kal_uint16 thumbnail_width;
    kal_uint16 thumbnail_height;

    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE */
    kal_uint8 overlay_color_depth;              /* 1/2/4/8 bpp */
    kal_uint8 overlay_frame_source_key;         /* source key of the overlay frame buffer */
    kal_uint16 overlay_frame_width;             /* overlay frame width */
    kal_uint16 overlay_frame_height;            /* overlay frame height */
    kal_uint32 overlay_frame_buffer_address;    /* bsae address of the overlay frame buffer */
#endif /* (defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6225) || defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6235) || defined(MT6238)) */ 
}
media_img_encode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_img_encode_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 cause;
}
media_img_encode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_img_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 src_image_address;    /* the source image buffer start address */
    kal_uint32 dest_image_address;                  /* the destination image buffer start address */
    kal_uint32 dest_buffer_size;                    /* the buffer size of destination image buffer size */
    kal_uint16 src_width;                           /* the width of image source */
    kal_uint16 src_height;                          /* the height of image source */
    kal_uint16 src_pitch;                           /* the pitch width of image source */
    kal_uint16 target_width;                        /* the width of target image */
    kal_uint16 target_height;                       /* the height of target image */
    kal_uint16 image_clip_x1;                       /* image clip window start x */
    kal_uint16 image_clip_x2;                       /* image clip window end x */
    kal_uint16 image_clip_y1;                       /* image clip window start y */
    kal_uint16 image_clip_y2;                       /* image clip window end x */
    kal_uint16 seq_num;                             /* use for non-blocking mode */
    kal_uint8 blocking;
    kal_uint8 type;                                 /* IBR1_TYPE_RGB565 or IBR1_TYPE_RGB888 */
    kal_uint8 data_order;                           /* IBR1_ORDER_BGR888 or IBR1_ORDER_RGB888 */
#if (defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6225) || defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6235)  || defined(MT6238))
    kal_bool image_pitch_mode;                      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;                    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;                   /* pitch width */
#endif /* (defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6225) || defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6235)  || defined(MT6238)) */ 
}
media_img_resize_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_img_resize_done_ind_struct;

/* VIDEO */
typedef enum
{
    MED_AVI_SAVE_TYPE_DATA,
    MED_AVI_SAVE_TYPE_IDX,
    MED_AVI_SAVE_TYPE_TERMINATE
} media_avi_save_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint16 buffer_width;
    kal_uint16 buffer_height;
    kal_uint16 preview_width;
    kal_uint16 preview_height;
    kal_uint16 preview_offset_x;
    kal_uint16 preview_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 frame_rate;
    kal_int16 contrast;
    kal_int16 brightness;
    kal_int16 saturation;
    kal_int16 hue;
    kal_int16 gamma;
    kal_int16 WB;
    kal_int16 exposure;
    kal_int16 effect;
    kal_int16 zoom_factor;
    kal_int16 rotate;
    kal_int16 lcd_rotate;
    kal_int16 flash_mode;
    kal_uint8 snapshot_number;
    kal_bool night_mode;
    kal_uint8 banding_freq;
    kal_uint8 encode_quality;
    kal_uint8 bit_stream_type;
    kal_uint8 gray_mode;
    kal_uint16 seq_num;

    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint32 src_key_color;
    kal_bool lcd_update;

#if (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238))
    /* ISP Setting */
    kal_bool manual_wb;             /* KAL_TRUE or KAL_FALSE to enable or disable manual white balance */
    kal_uint8 ae_metering_mode;     /* AUTO, SPOT, CENTRAL WEIGHT, AVERAGE */
    kal_uint8 iso_setting;          /* AUTO, 100, 200, 400 */
    kal_uint8 scene_mode;           /* NORMALSCENE, PORTRAIT, LANDSCAPE, SPORT, FLOWER, NIGHTSCENE */
    /* IPP Setting */
    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint8 overlay_color_depth;              /* The color depth of overlay frame buffer */
    kal_uint8 overlay_frame_source_key;
    kal_uint16 overlay_frame_width;             /* Image width of overlay frame buffer */
    kal_uint16 overlay_frame_height;            /* Image height of overlay frame buffer */
    kal_uint32 overlay_frame_buffer_address;    /* The starting address of overlay frame buffer */
    /* TV Setting */
    kal_uint8 tv_output_mode;
    kal_bool tv_output;
    kal_uint16 tv_output_width;                 /* image width for TV output */
    kal_uint16 tv_output_height;                /* image height for TV output */
    kal_uint16 tv_output_offset_x;              /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;              /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;       /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;       /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;           /* image buffer size for TV source buffer */
    /* LCD Setting */
    kal_uint32 roi_background_color;            /* set the background color */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238)) */ 

}
media_vid_preview_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 media_type;
    kal_uint8 record_audio;
    kal_uint8 encode_quality;
    void *data;
    kal_uint32 file_size_limit;
    kal_uint16 seq_num;

}
media_vid_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_encode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_read_audio_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_read_video_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_read_meta_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_path;
}
media_vid_file_merge_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_vid_file_merge_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_name_p;
    kal_uint16 seq_num;
    kal_uint16 cache_in_mem;
}
media_vid_open_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint32 total_frame_num;
    kal_uint64 total_time;
    kal_uint16 seq_num;
    kal_int32 handle;
}
media_vid_file_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_vid_close_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 data_size;
    kal_uint16 seq_num;
    kal_uint16 max_width;
    kal_uint16 max_height;
    kal_uint8 play_audio;
    kal_uint16 *image_width;
    kal_uint16 *image_height;
    kal_uint64 *total_time;    
    kal_int32 *handle;       
    kal_uint8 blocking;    
    kal_bool enable_aud_only;   /* allows to open aud only video */
}
media_vid_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;
    kal_int32 handle;
    kal_uint8 media_mode;
}
media_vid_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;    /* reseved */
    kal_uint8 media_type;                   /* reseved */
    void *data;                             /* reseved */
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 display_offset_x;
    kal_uint16 display_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 zoom_factor;                  /* reseved */
    kal_int16 frame_rate;                   /* reseved */
    kal_int16 contrast;                     /* reseved */
    kal_int16 brightness;                   /* reseved */
    kal_int16 play_speed;
    kal_uint8 play_audio;
    kal_uint8 display_device;
    kal_uint8 audio_path;
    kal_uint16 seq_num;
    kal_int16 lcd_rotate;
    kal_uint16 repeats;                     /* repeat count, 0xffff: infinite */

    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint16 video_display_offset_x;
    kal_uint16 video_display_offset_y;
    kal_bool force_lcd_hw_trigger;
#if (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238))
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238)) */ 
}
media_vid_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_decode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_edt_encode_event_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool stop_preview;
}
media_vid_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 stop_time;
}
media_vid_set_stop_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 get_frame;
    kal_uint32 frame_num;
    kal_uint64 time;
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 display_offset_x;
    kal_uint16 display_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint8 blocking;
    kal_uint16 seq_num;
#if (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238))
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238)) */ 
}
media_vid_seek_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_seek_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
}
media_vid_snapshot_req_struct;


/**************************/
/*      Video Editor      */
/**************************/
typedef enum
{
    MED_VID_EDT_RES_TYPE_IMAGE,      
    MED_VID_EDT_RES_TYPE_VIDEO,        

    /* add before this */
    MED_VID_EDT_RES_TYPE_TOTAL
} media_vid_edt_res_type_enum;

typedef struct
{
    kal_bool    is_use;                 /* use this layer or not */
	kal_bool 	source_key_enable;		/* enable/disable source key for specified layer */
	kal_uint32 	source_key;				/* source key color in RGB565 format for specified layer */    
	kal_bool	opacity_enable;			/* enable/disable opacity for specified layer */
	kal_uint8	opacity_value;			/* opacity value for specified layer */    
	kal_uint16	offset_x;				/* x axis offset from main window for specified layer */
	kal_uint16	offset_y;				/* y axis offset from main widnow for specified layer */
	kal_uint16	width;					/* layer buffer height of specified layer */
	kal_uint16	height;				    /* layer buffer width of specified layer */
	kal_uint32	frame_buffer_address;	/* frame buffer start address of specified layer */
} media_vid_edt_layer_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;     /* video handle */
}
media_vid_edt_set_active_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 encode_video_width;   /* encode result(dest) width */
    kal_int32 encode_video_height;  /* encode result(dest) height */
    kal_wchar *filename;            /* file name of encoded video */
}
media_vid_edt_enc_open_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    
}
media_vid_edt_enc_close_req_struct;


 
typedef struct
{
    LOCAL_PARA_HDR
    media_vid_edt_res_type_enum resource_type;  /* resource type */
    
    kal_int32 video_handle;     /* video resource */
    kal_uint8 *img_buf_ptr;     /* image resource - must be RGB565 format */
    kal_uint32 img_buf_size;    /* image buffer size */

    media_vid_edt_layer_struct extra_layer_1;   /* extra layer */
    media_vid_edt_layer_struct extra_layer_2;   /* extra layer */
   
    kal_uint32 start_time;      /* resource start time */
    kal_uint32 end_time;        /* resource end time */
    
    kal_bool is_use_bgm;        /* use bgm or not */
    kal_uint32 bgm_start_time;  /* bgm's start time */
    kal_uint32 bgm_end_time;    /* bgm's end time */        
}
media_vid_edt_enc_append_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;             /* session id */        
    kal_wchar *filename;            /* file name of encoded video */    
}
media_vid_edt_enc_merge_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_edt_enc_stop_merge_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_edt_enc_merge_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;              /* bgm file name or source buffer ptr */
    kal_uint32 data_size;           /* if it is MEDIA_ARRAY, this shoulbe be buffer size */
    kal_uint8 media_mode;           /* media mode */    
    kal_uint8 media_type;           /* media type */
    kal_uint64 *aud_duration_p;     /* audio duration of this bgm */
}
media_vid_edt_open_bgm_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_edt_close_bgm_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;              /* bgm file name or source buffer ptr */
    kal_uint32 data_size;           /* if it is MEDIA_ARRAY, this shoulbe be buffer size */
    kal_uint8 media_mode;           /* media mode */  
    kal_uint8 media_type;           /* media type */
    kal_uint64 *aud_duration_p;     /* audio duration of this bgm */
}
media_vid_edt_open_silence_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_edt_close_silence_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool init;                  /* init or deinit */
}
media_vid_edt_init_req_struct;


/**************************/
/*  Video Progressive DL  */
/**************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *percent_p;
}
media_vid_get_pdl_percent_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 *max_time_p;
}
media_vid_get_pdl_max_time_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *file_buf_p;   
    kal_uint32 buf_size;
}
media_vid_check_is_pdl_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint16 frame_num;
    kal_uint16 seq_num;
    kal_uint8 blocking;
#if (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238))
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238)) */ 
}
media_vid_get_iframe_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_iframe_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 audio_start_frame_num;
}
media_vid_play_restart_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_vid_audio_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 device;
}
media_vid_set_display_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_update_blt_pause_req_struct;


typedef struct
{
    LOCAL_PARA_HDR  
    kal_uint16 buffer_width;            /* preview buffer width */
    kal_uint16 buffer_height;           /* preview buffer height */
    kal_uint16 preview_width;           /* preview width */
    kal_uint16 preview_height;          /* preview height */
    kal_uint16 preview_offset_x;        /* preview offset_x from lcd_offset_x */
    kal_uint16 preview_offset_y;        /* preview offset_y from lcd_offset_y */
    void *image_buffer_p;               /* preview buffer ptr */
    kal_uint32 image_buffer_size;       /* preview buffer size */
    kal_int16 frame_rate;               /* always VIDEO_PERVIEW_FRAME_RATE for video */
    kal_int16 rotate;                   /* preview image rotate */
    kal_int16 lcd_rotate;               /* lcm rotate */
    kal_uint8 lcd_id;                   /* lcd id */
    kal_uint16 lcd_start_x;             /* lcd start x, phisical offset on panel */
    kal_uint16 lcd_start_y;             /* lcd start y, phisical offset on panel */
    kal_uint16 lcd_end_x;               /* lcd end x, phisical offset on panel */
    kal_uint16 lcd_end_y;               /* lcd end y, phisical offset on panel */
    kal_uint16 roi_offset_x;            /* roi offset x */ 
    kal_uint16 roi_offset_y;            /* roi offset y */
    kal_uint32 update_layer;            /* full update layer */
    kal_uint32 hw_update_layer;         /* hw update layer - layer for video */
    kal_uint32 src_key_color;           /* src key */
    kal_bool lcd_update;                /* update lcd or not */

#if (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238))
    /* TV Setting */
    kal_uint8 tv_output_mode;                   /* tv mode */    
    kal_bool tv_output;                         /* output or not */
    kal_uint16 tv_output_width;                 /* image width for TV output */
    kal_uint16 tv_output_height;                /* image height for TV output */
    kal_uint16 tv_output_offset_x;              /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;              /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;       /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;       /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;           /* image buffer size for TV source buffer */
    
    /* LCD Setting */
    kal_uint32 roi_background_color;            /* set the background color */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238)) */ 
}
media_vid_update_blt_resume_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    kal_int16 value;
}
media_vid_set_param_req_struct;

/* Web camera */

typedef struct
{
    kal_uint16 width;
    kal_uint16 height;
    kal_uint8 *start_addr;
    kal_uint32 size;
}
webcam_default_jpeg_file_info;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 rotate;
    kal_uint16 banding;
    kal_uint16 seq_num; /* sequence num */
}
media_webcam_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num; /* sequence num */
    kal_bool camera_workable;
}
media_webcam_start_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;  /* sequence num */
}
media_webcam_abort_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_webcam_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    webcam_default_jpeg_file_info *file_info;
    kal_uint8 no_of_jpeg_files;
}
media_webcam_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 rotate;
}
media_webcam_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_webcam_capture_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 rotate;
}
media_webcam_rotate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 event;
}
media_webcam_encode_req_struct;


/* TV out */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 tv_output_mode;
    kal_uint8 tv_output_format;
    kal_uint16 tv_output_width;     /* image width for TV output */
    kal_uint16 tv_output_height;    /* image height for TV output */
}
media_tvo_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_tvo_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 tv_output_mode;
    kal_uint8 tv_output_format;
    kal_uint16 tv_output_width;     /* image width for TV output */
    kal_uint16 tv_output_height;    /* image height for TV output */
    kal_bool    tv_output_vertical_filter;
}
media_tvo_set_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_tvo_tv_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_tvo_av_cable_detect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type;
    kal_uint8 para;
}
media_tvo_set_param_req_struct;

/* MMA */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handler;
    kal_uint8 *data;
    kal_int32 size;
    kal_wchar* file_path;
    kal_int16 repeats;
    kal_bool progressive_dl; /* Is a progressive download file */
}
media_mma_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar* file_path;
    kal_uint8 media_type;
    kal_uint8* data;
    kal_uint32 data_len;
    kal_int32 handle;
    void *audio_info;
}
media_mma_get_audio_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_get_duration_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_get_current_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_int32 start_time;
}
media_mma_set_start_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_int32 stop_time;
}
media_mma_set_stop_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_get_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_uint8 volume;
}
media_mma_set_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_int32 rate;
}
media_mma_set_rate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_int32 tempo;
}
media_mma_set_tempo_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_int32 pitch;
}
media_mma_set_pitch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_uint8 *buf;
    kal_uint16 len;
}
media_mma_send_long_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_uint8 type;
    kal_uint8 data1;
    kal_uint8 data2;
}
media_mma_send_short_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handler;
    kal_uint8 *data;
    kal_int32 size;
    kal_int16 repeats;
}
media_mma_open_device_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
}
media_mma_close_device_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_uint8 channel;
    kal_uint8 level;
}
media_mma_set_channel_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_uint8 channel;
    kal_uint8 bank;
    kal_uint8 program;
}
media_mma_set_program_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_uint8 *data;
    kal_int32 size;
    kal_int16 repeats;
}
media_mma_set_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32 handle;
    kal_bool  is_finish;
}
media_mma_write_data_ind_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_mma_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_mma_process_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint16 player_id;
    kal_uint16 seq_id;
    kal_uint8 result;
}
media_mma_callback_ind_struct;

/* VR related messages */
typedef struct
{
    kal_uint8 mode;
    kal_uint8 language;
    LOCAL_PARA_HDR
}
media_vr_get_version_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_int16 *sim;
    kal_int16 *diff;
    kal_int16 *rej;
}
media_vr_get_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_int16 sim;
    kal_int16 diff;
    kal_int16 rej;
}
media_vr_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_init_rcg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_int32 result;
    kal_uint16 id_length;
    kal_uint16 id_array[VR_MAX_RCG_RESULT_NUM];
}
media_vr_rcg_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 word_id;
}
media_vr_init_trn_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_int32 result;
}
media_vr_trn_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 seq_no;
}
media_vr_voice_in_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_int32 result;
}
media_vr_voice_in_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 word_id;
}
media_vr_del_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 word_id;
}
media_vr_check_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 *id_length_p;
    kal_uint16 *id_array;
}
media_vr_sync_db_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 word_id;
    kal_uint16 identifier;
}
media_vr_play_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 *folder_name;
}
media_vr_get_dir_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
    kal_uint16 id_length;
    kal_uint16 id_array[VR_MAX_ADD_ONCE_NUM];
}
media_vr_add_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vr_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
}
media_vr_abort_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 device;
}
media_aud_set_headset_mode_output_path_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vrsi_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 tag_num;
    kal_uint16 **name_list;
    kal_int32 *long_list;
    kal_uint8 *is_name_list;
    kal_uint16 *id_list;
} media_vrsi_add_tags_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 *tag_name;
    kal_int32 tag_long;
    kal_uint8 lang;
} media_vrsi_start_trn_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 pmp_mode;
} media_vrsi_trn_prompt_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 tag_id;
} media_vrsi_trn_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint8 lang;
    kal_uint16 limit;
} media_vrsi_start_rcg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 pmp_mode;
} media_vrsi_rcg_prompt_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 res_type;
} media_vrsi_rcg_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 proc_type;
} media_vrsi_process_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 tag_id;
    kal_uint8 volume;
    kal_uint8 output_path;
} media_vrsi_play_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 *text;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint8 lang;
} media_vrsi_play_tts_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 *tag_num;
} media_vrsi_get_tagnum_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 tag_num;
    kal_uint16 *id_list;
    kal_uint16 **name_list;
    kal_int32 *long_list;
} media_vrsi_get_taginfo_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 tag_num;
    kal_uint16 *id_list;
} media_vrsi_del_tags_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
} media_vrsi_reset_tags_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 tag_num;
    kal_uint16 *id_list;
    kal_uint16 **name_list;
    kal_uint8 *sync_flag;
} media_vrsi_sync_db_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vrsi_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_err_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_play_tag_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_play_tts_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 res_type;
    kal_uint16 tag_num;
    kal_uint16 *id_list;
    kal_uint16 **name_list;
    kal_int32 *long_list;
    kal_int16 pre_cmd;
    kal_int16 post_cmd;
} media_aud_vrsi_cmd_rcg_result_struct;

/*
 *  Sound Effect
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;
    kal_uint32 size;
} media_snd_check_byte_stream_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_name_p;
} media_snd_check_file_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;
    kal_int32 size;
    kal_int16 repeats;
    kal_uint8 volume;
    kal_uint8 output_path;
} media_snd_play_byte_stream_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_name_p;
    kal_int16 repeats;
    kal_uint8 volume;
    kal_uint8 output_path;
} media_snd_play_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
    kal_uint32 snd_handle;
} media_snd_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 result;
} media_snd_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 volume;
    kal_uint8 direction;
} media_snd_set_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 ctm_interface;
    ctm_param_struct ctm_param;
} media_ctm_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_ctm_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_ctm_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_ctm_connected_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 num_of_char;
    kal_wchar text[CTM_SEND_TEXT_CHAR_MAX_NUM + 1];
} media_ctm_send_text_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_send_text_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 num_of_char;
    kal_wchar text[CTM_SEND_TEXT_CHAR_MAX_NUM + 1];
} media_ctm_recv_text_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
} media_ctm_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *top_p;
    kal_uint8 *val_p;
} media_aud_get_spectrum_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_start_calc_spectrum_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_stop_calc_spectrum_req_struct;

/*
 *  Audio Post Process
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;
    kal_uint32 size;
    kal_uint16 format;
} media_stretch_check_stream_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_path;
} media_stretch_check_file_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 speed;
} media_stretch_set_speed_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 *coeff_table_ptr;
} media_reverb_set_coeff_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
} media_surround_turn_on_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_int8 magnitude[8];
}
media_aud_eq_set_magnitude_req_struct;

/*
*  General TTS
*/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 attr_id;
    kal_uint32 attr_value;
} media_aud_tts_set_attr_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 handle;
    kal_uint32 seq_no;
    void *data;
    kal_uint8 event;
}media_aud_tts_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 *tts_string;
    kal_uint16 str_type;
    kal_uint16 lang;
    kal_uint16 app_type;
    kal_uint16 gander;
    kal_uint16 identifier;
    kal_uint8  volume;
    kal_uint8  output_path;
    kal_uint8  pitch;
    kal_uint8  speed;
} media_aud_tts_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
} media_aud_tts_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
} media_aud_tts_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
} media_aud_tts_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *data;
} media_aud_tts_update_info_ind_struct;

/* ---- bt audio begin ---- */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;   /* 0: HFP, 1: A2DP */
    kal_uint8 mode;      /* HFP => 0: Earphone, 1: Car Kit /// A2DP => 0: INT mode, 1: ACP mode, 2: ACP mode for PTS only*/
    kal_uint16 connect_id;
} media_bt_audio_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
    kal_uint16 result;
} media_bt_audio_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_open_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
    kal_uint16 result;
} media_bt_audio_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
    kal_uint16 cause;
} media_bt_audio_close_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_turn_on_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_turn_off_req_struct;

/* ---- bt audio end ---- */

typedef void (*media_in_proc_call_type) (kal_uint32 arg1, void *arg2);
typedef struct
{
    LOCAL_PARA_HDR
    media_in_proc_call_type func;
    kal_uint32 func_arg1;
    void *func_arg2;
} media_in_proc_call_req_struct;

#ifndef __BT_A2DP_CODEC_TYPES__
#define __BT_A2DP_CODEC_TYPES__
typedef struct
{
	kal_uint8 min_bit_pool;
	kal_uint8 max_bit_pool;
	kal_uint8 block_len; // b0: 16, b1: 12, b2: 8, b3: 4
	kal_uint8 subband_num; // b0: 8, b1: 4
	kal_uint8 alloc_method; // b0: loudness, b1: SNR
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 16000
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
} bt_a2dp_sbc_codec_cap_struct;

typedef struct
{
	kal_uint8 layer; // b0: layerIII, b1: layerII, b0: layerI
	kal_bool CRC;
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
	kal_bool MPF; // is support MPF-2
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 24000, b4: 22050, b5: 16000
	kal_bool VBR; // is support VBR
	kal_uint16 bit_rate; // bit-rate index in ISO 11172-3 , b0:0000 ~ b14: 1110
} bt_a2dp_mp3_codec_cap_struct; /* all MPEG-1,2 Audio */


typedef struct
{
	kal_uint8 object_type; // b4: M4-scalable, b5: M4-LTP, b6: M4-LC, b7: M2-LC
	kal_uint16 sample_rate; // b0~b11: 96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000
	kal_uint8 channels; // b0: 2, b1: 1
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // constant/peak bits per second in 23 bit UiMsbf, 0:unknown
} bt_a2dp_aac_codec_cap_struct; /* all MPEG-2,4 AAC */

typedef struct
{
	kal_uint8 version; // 1:ATRAC, 2:ATRAC2, 3:ATRAC3
	kal_uint8 channel_mode; // b0: joint stereo, b1: dual, b2: single
	kal_uint8 sample_rate; // b0: 48000, b1: 44100
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // bit-rate index in ATRAC, b0: 0x0012 ~ b18: 0x0000
	kal_uint16 max_sul; // sound unit length in 16 bits UiMsbf
} bt_a2dp_atrac_codec_cap_struct; /* all ATRAC family */

typedef union
{
	bt_a2dp_sbc_codec_cap_struct sbc;
	bt_a2dp_mp3_codec_cap_struct mp3;
	bt_a2dp_aac_codec_cap_struct aac;
	bt_a2dp_atrac_codec_cap_struct atrac;
} bt_a2dp_audio_codec_cap_struct;

typedef struct
{
	kal_uint8 codec_type; // SBC, MP3
	bt_a2dp_audio_codec_cap_struct codec_cap;
} bt_a2dp_audio_cap_struct;
#endif /* __BT_A2DP_CODEC_TYPES__ */

typedef struct
{
    LOCAL_PARA_HDR
    bt_a2dp_audio_cap_struct cfg;
    kal_uint32 seq_no;
    kal_uint8 stream_handle;
    kal_bool immediate;
} media_bt_open_codec_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seq_no;
    kal_uint8 stream_handle;
} media_bt_close_codec_ind_struct;

/*=============================
 * Constants
 *=============================*/

#define MAX_RTP_NUM             (10)
#define MAX_CSRC_NUM            (1)
#define MAX_RR_NUM              (1)
#define MAX_APP_NUM             (2)
#define MAX_RB_NUM              (3)
#define MAX_SDES_CHUNK_NUM      (2)
#define MAX_SDES_ITEM_NUM       (5)
#define MAX_SDES_DATA_LEN       (64)
#define MAX_RTP_HEADER_EXT      (16)
#define MAX_SSRC_IN_RTCP_BYE    (3)
#define MAX_RTCP_BY_LEAVE_LEN   (32)
#define MAX_APP_DATA_LEN        (128)


#define RTP_SUCCESS             (0)
#define RTP_GENERAL_ERROR       (-1)
#define RTP_SOC_WOULD_BLOCK     (-2)
#define RTP_SOC_OTHER_ERROR     (-3)
#define RTP_CONFLICT_SSRC       (-4)
#define RTP_SRTP_AUTH_FAIL      (-5)
#define MAX_RTP_SOCK_ADDR_LEN   28

#define MAX_SRTP_CRYPTO_LEN	    50

/* RTP VoIP extension */

/*=============================
 * Enums
 *=============================*/

typedef enum
{
    RTP_DTMF_TYPE_INBAND,
    RTP_DTMF_TYPE_RFC2833,
    RTP_DTMF_TYPE_TOTAL
} rtp_dtmf_type_enum;

typedef enum
{
    RTP_DTMF_CODE_0,
    RTP_DTMF_CODE_1,
    RTP_DTMF_CODE_2,
    RTP_DTMF_CODE_3,
    RTP_DTMF_CODE_4,
    RTP_DTMF_CODE_5,
    RTP_DTMF_CODE_6,
    RTP_DTMF_CODE_7,
    RTP_DTMF_CODE_8,
    RTP_DTMF_CODE_9,
    RTP_DTMF_CODE_STAR,
    RTP_DTMF_CODE_HASH,
    RTP_DTMF_CODE_TOTAL
} rtp_dtmf_code_enum;

typedef enum
{
    RTCP_SR = 200,
    RTCP_RR,
    RTCP_SDES,
    RTCP_BYE,
    RTCP_APP
} rtcp_type_enum;       


typedef enum
{
    RTCP_SR_MASK    = 0x01,
    RTCP_RR_MASK    = 0x02,
    RTCP_SDES_MASK  = 0x04,
    RTCP_BYE_MASK   = 0x08,
    RTCP_APP_MASK   = 0x10
} rtcp_type_mask_enum;      


typedef enum
{
    RTCP_SDES_END,
    RTCP_SDES_CNAME,
    RTCP_SDES_NAME,
    RTCP_SDES_EMAIL,
    RTCP_SDES_PHONE,
    RTCP_SDES_LOC,
    RTCP_SDES_TOOL,
    RTCP_SDES_NOTE,
    RTCP_SDES_PRIV,
    RTCP_SDES_TOTAL
} rtcp_sdes_type_enum;

typedef enum
{
    RTP_NOTIFY_NONE,
    RTP_NOTIFY_SOC,
    RTP_NOTIFY_PACKET,
    RTP_NOTIFY_TOTAL
} rtp_notify_type_enum;

typedef enum
{
    RTP_SEND_RTP    = 0x01,
    RTP_RECV_RTP    = 0x02
} rtp_packet_notify_event_enum;

typedef enum
{
    RTP_SOC_NTFY_READ_IND,
    RTP_SOC_NTFY_WRITE_IND,        
    RTP_SOC_SEND_RET,
    RTP_SOC_RECV_RET,
    RTCP_SOC_NTFY_READ_IND,
    RTCP_SOC_NTFY_WRITE_IND,        
    RTCP_SOC_SEND_RET,
    RTCP_SOC_RECV_RET,
    RTCP_SOC_TOTAL
} rtp_soc_notify_type_enum;

typedef enum
{
    SRTP_ENCRYPT_RTP    = 0X01,
    SRTP_ENCRYPT_RTCP   = 0X02,
    SRTP_AUTH_RTP       = 0x04,
    SRTP_AUTH_RTCP      = 0x08,
    SRTP_METHOD_DEFAULT = 0X0F
} rtp_srtp_method_enum;

typedef enum
{
    SRTP_CRYPTO_NONE,
    SRTP_CRYPTO_AES_CM_128_HMAC_SHA1_80,
    SRTP_CRYPTO_AES_CM_128_HMAC_SHA1_32,
    SRTP_CRYPTO_F8_128_HMAC_SHA1_80,
    SRTP_CRYPTO_TOTAL
} rtp_srtp_crypto_suites_enum;

typedef enum
{
    SRTP_FEC_ORDER_NONE,
    SRTP_FEC_ORDER_FEC_SRTP,
    SRTP_FEC_ORDER_SRTP_FEC,
    SRTP_FEC_ORDER_TOTAL
} rtp_srtp_fec_order_enum;

typedef enum
{
    VOIP_IDLE           = 0x00,
    VOIP_ENCODE         = 0x01,
    VOIP_DECODE         = 0x02,
    VOIP_ENCODE_DECODE  = 0x03
} voip_status_enum;     

typedef enum
{
    VOIP_CODEC_NONE     = 0x0000,
    VOIP_CODEC_AMR      = 0x0001,
    VOIP_CODEC_G729     = 0x0002,
    VOIP_CODEC_G7231    = 0x0004,
    VOIP_CODEC_G726_16  = 0x0008,
    VOIP_CODEC_G726_24  = 0x0010,
    VOIP_CODEC_G726_32  = 0x0020,
    VOIP_CODEC_G726_40  = 0X0040,
    VOIP_CODEC_PCMA     = 0X0080,
    VOIP_CODEC_PCMU     = 0X0100,
    VOIP_CODEC_CN                   = 0X0200,
    VOIP_CODEC_G729_ANNEXB_PRESENT  = 0x0400,
    VOIP_CODEC_G729_ANNEXB          = 0x0800,    
    VOIP_CODEC_G7231_ANNEXA_PRESENT = 0x1000,
    VOIP_CODEC_G7231_ANNEXA         = 0x2000    
}voip_codec_enum;


typedef enum
{
    VOIP_AMR_IDX_0  = 0x01,
    VOIP_AMR_IDX_1  = 0x02,
    VOIP_AMR_IDX_2  = 0x04,
    VOIP_AMR_IDX_3  = 0x08,
    VOIP_AMR_IDX_4  = 0x10,
    VOIP_AMR_IDX_5  = 0x20,
    VOIP_AMR_IDX_6  = 0x40,
    VOIP_AMR_IDX_7  = 0x80,
    VOIP_AMR_IDX_8  = 0xFF
} voip_amr_idx_enum;        

typedef enum
{
    VOIP_G7231_RATE_0530 = 1,
    VOIP_G7231_RATE_0630 = 2
} voip_g7231_rate_enum;

typedef enum
{
    VOIP_RTP_DISCONNECT_NONE,
    VOIP_RTP_DISCONNECT_NO_RTP_PKT_WARNING,
    VOIP_RTP_DISCONNECT_NO_RTP_PKT_DISCONNECT,
    VOIP_RTP_DISCONNECT_HIGH_ERR_RATE,
    VOIP_RTP_DISCONNECT_ICMP_UNREACHABLE,
    VOIP_RTP_DISCONNECT_TOTAL
} voip_rtp_disconnect_type_enum;


/*=============================
 * structs 
 *=============================*/

typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   fraction_lost;
    kal_int16   cumul_packet_lost;
    kal_uint32  last_sequence;
    kal_uint32  jitter;
    kal_uint32  lsr;
    kal_uint32  dlsr;
} rtcp_info_rb_struct;


typedef struct
{
    kal_uint32  ssrc;
    kal_uint32  ntp_timestamp_m;
    kal_uint32  ntp_timestamp_l;
    kal_uint32  rtp_timestamp;
    kal_uint32  packet_sent;
    kal_uint32  octet_sent;
    kal_uint8   no_report_block;
    rtcp_info_rb_struct report_block[MAX_RB_NUM];
} rtcp_info_sr_struct;


typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   no_report_block;
    rtcp_info_rb_struct report_block[MAX_RB_NUM];
} rtcp_info_rr_struct;


typedef struct
{
    kal_uint8   type;
    kal_uint8   no_data;
    kal_uint8   data[MAX_SDES_DATA_LEN];
} rtcp_info_sdes_item_struct;


typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   No_item;
    rtcp_info_sdes_item_struct  Item[MAX_SDES_ITEM_NUM];
} rtcp_info_sdes_chunk_struct;


typedef struct
{
    kal_uint8   no_chunk;
    rtcp_info_sdes_chunk_struct chunk[MAX_SDES_CHUNK_NUM];
} rtcp_info_sdes_struct;



typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   sub_type;
    kal_uint8   name[4];
    kal_uint8   no_data;
    kal_uint8   data[MAX_APP_DATA_LEN];
} rtcp_info_app_struct;


typedef struct
{
    kal_uint32  ssrc[MAX_SSRC_IN_RTCP_BYE];
    kal_uint8   no_ssrc;
    kal_uint8   no_leave_reason;
    kal_uint8   leave_reason[MAX_RTCP_BY_LEAVE_LEN];
} rtcp_info_bye_struct;


typedef struct
{
    kal_uint8   marker;
    kal_uint8   payload_type;
    kal_uint8   no_csrc;
    kal_uint32  csrc[MAX_CSRC_NUM] ;
    kal_uint16  seq_number;
    kal_uint32  time_stamp;
    kal_uint32  ssrc;
    kal_uint8   ext_avaliable;
    kal_uint8   ext[MAX_RTP_HEADER_EXT];
} rtp_info_struct;


typedef struct
{
    kal_uint8               valid_packet_mask;
    rtcp_info_sr_struct     sr;
    rtcp_info_sdes_struct   sdes;
    rtcp_info_bye_struct    bye;
    kal_uint8               no_rr;
    rtcp_info_rr_struct     rr[MAX_RR_NUM];
    kal_uint8               no_app;
    rtcp_info_app_struct    app[MAX_APP_NUM];
} rtcp_info_struct;


typedef struct
{
    kal_uint8   crypto_suite;                           //rtp_srtp_crypto_suites_enum
    kal_uint8   send_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   recv_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination    
    kal_uint8   lifetime_available;                     //KAL_TRUE / KAL_FALSE
    kal_uint64  lifetime;                               
    kal_uint8   KDR_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   KDR;                                    //(2^64, KDR = 64)
    kal_uint8   MKI_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   MKI_len;
    kal_uint8   MKI;
    kal_uint8   FEC_order;                              //rtp_srtp_fec_order_enum
    kal_uint16  FEC_key_len;                            //reserved
    kal_uint8*  FEC_key;                                //reserved
    kal_uint8   crypt_auth_mask;                        //rtp_srtp_method_enum
    kal_uint8   WSH_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint16  WSH;
} srtp_crypto_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  nwk_account_id;
    kal_uint8   local_ip[MAX_RTP_SOCK_ADDR_LEN];
    kal_uint8   remote_ip[MAX_RTP_SOCK_ADDR_LEN];
    kal_uint16  remote_rtp_port;
    kal_uint16  remote_rtcp_port;
    kal_uint16  local_rtp_port;
    kal_uint16  local_rtcp_port;
    kal_uint8   soc_qos_param;
} med_rtp_create_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_rtp_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   remote_ip[MAX_RTP_SOCK_ADDR_LEN];
    kal_uint16  remote_rtp_port;
    kal_uint16  remote_rtcp_port;
} med_rtp_set_remote_addr_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   soc_enable;
    kal_uint8   packet_enable;
    kal_uint8   packet_mask;
} med_rtp_set_notify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   soc_enable;
    kal_uint8   packet_enable;
    kal_uint8   packet_mask;
} med_rtp_clear_notify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   *payload;
    kal_uint32  payload_len;
} med_rtp_send_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   *buffer;
    kal_int32   buffer_size;
    rtp_info_struct *param;
} med_rtp_recv_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   packet_mask;
    kal_uint32  ssrc;
    kal_uint8   no_app;
    rtcp_info_app_struct *app;
} med_rtp_send_rtcp_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    rtcp_info_struct *rtcp_info;
} med_rtp_recv_rtcp_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   mask;               /* rtp_set_value_mask_enum */
    kal_uint32  timestamp;
    kal_uint32  seqnumber;
    kal_uint8   payload_type;
    kal_uint8   sdes_type;
    kal_uint8   no_sdes_data;
    kal_uint8   *sdes_data;
    kal_uint8   dtmf_payload_type;
} med_rtp_set_value_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint16  *seqnumber;
    kal_uint32  *ssrc;
} med_rtp_get_value_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   dtmf_code;
    kal_uint8   send_type;
} med_rtp_send_dtmf_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_rtp_send_dtmf_stop_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   crypto_suite;                           //rtp_srtp_crypto_suites_enum
    kal_uint8   send_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   recv_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination    
    kal_uint8   lifetime_available;                     //KAL_TRUE / KAL_FALSE
    kal_uint64  lifetime;                               
    kal_uint8   KDR_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   KDR;                                    //(2^64, KDR = 64)
    kal_uint8   MKI_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   MKI_len;
    kal_uint8   MKI;
    kal_uint8   FEC_order;                              //rtp_srtp_fec_order_enum
    kal_uint16  FEC_key_len;                            //reserved
    kal_uint8*  FEC_key;                                //reserved
    kal_uint8   crypt_auth_mask;                        //rtp_srtp_method_enum
    kal_uint8   WSH_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint16  WSH;
} med_rtp_check_srtp_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srtp_crypto_struct *srtp_crypto;
} med_rtp_get_srtp_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   crypto_suite;                           //rtp_srtp_crypto_suites_enum
    kal_uint8   send_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   recv_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination    
    kal_uint8   lifetime_available;                     //KAL_TRUE / KAL_FALSE
    kal_uint64  lifetime;                               
    kal_uint8   KDR_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   KDR;                                    //(2^64, KDR = 64)
    kal_uint8   MKI_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   MKI_len;
    kal_uint8   MKI;
    kal_uint8   FEC_order;                              //rtp_srtp_fec_order_enum
    kal_uint16  FEC_key_len;                            //reserved
    kal_uint8*  FEC_key;                                //reserved
    kal_uint8   crypt_auth_mask;                        //rtp_srtp_method_enum
    kal_uint8   WSH_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint16  WSH;
} med_rtp_set_srtp_param_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint16  codec_type;
    kal_uint16  modeset;
} med_voip_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_encoding_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_encoding_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_decoding_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_decoding_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   *voip_state;
    kal_uint16  *codec_type;
    kal_uint16  *ptime;
    kal_uint16  *maxptime;
    kal_uint16  *modeset_mask;
} med_voip_get_value_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   voip_set_value_mask;
    kal_uint16  ptime;
    kal_uint16  maxptime;
    kal_uint16  modeset_mask;
} med_voip_set_value_req_struct;


typedef struct {
   kal_uint8    amr_modeset;    /* voip_amr_idx_enum */
   kal_uint8    g7231_rate;     /* voip_g7231_rate_enum */
} med_voip_codec_cap_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   require_type;                   /* voip_status_enum */
    kal_uint16  *codec_type;                    /* voip_codec_enum */
    med_voip_codec_cap_struct   *codec_details;
} med_voip_get_codec_cap_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_mixer_add_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_mixer_remove_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    event_type;    /* voip_rtp_disconnect_type_enum */
} med_voip_rtp_disconnect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_int32   result;
    kal_uint32  ssrc;
    kal_uint8   notify_type;    /* rtp_notify_type_enum */
    kal_uint8   event_type;     /* rtp_packet_notify_event_enum / rtp_soc_notify_type_enum */
} med_rtp_notify_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  event;
    void        *handle;
    void        *host_data;
} med_voip_l1_encoding_callback_ind_struct;


/* Constants */
#define STREAM_MAX_TITLE_LEN        32
#define MED_MAX_LINK_PATH_LEN 256
#define MED_MAX_IP_LEN 4

/* Enums */
typedef enum
{
    MEDIA_STREAM_CONN_TYPE_NONE,
    MEDIA_STREAM_CONN_TYPE_RTSP_URL,
    MEDIA_STREAM_CONN_TYPE_SDP_FILE
} media_stream_conn_type_enum;

typedef enum
{
    MEDIA_STREAM_MEDIA_TYPE_NONE    = 0,
    MEDIA_STREAM_MEDIA_TYPE_AUDIO   = 0x01,
    MEDIA_STREAM_MEDIA_TYPE_VIDEO   = 0x02
} media_stream_media_type_enum;

/* Structures */

typedef struct
{
    kal_uint16  image_width;
    kal_uint16  image_height;
    kal_uint64  total_time;
    kal_uint32  sampleing_freq;
    kal_uint8   channel_num;
    kal_uint8   media_format;               /* Media_Format enum in l1audio.h */
} media_stream_get_info_struct;

typedef struct
{
    kal_uint8 media_mode;    				/* reseved */
    kal_uint8 media_type;                   /* reseved */
    void *data;                             /* reseved */
    kal_uint16 display_width;
    kal_uint16 display_height;
    kal_uint16 display_offset_x;
    kal_uint16 display_offset_y;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_int16 zoom_factor;                  /* reseved */
    kal_int16 frame_rate;                   /* reseved */
#if (0)
/* under construction !*/
/* under construction !*/
#endif    
    kal_int16 play_speed;
    kal_uint8 play_audio;
    kal_uint8 display_device;
    kal_uint8 audio_path;
    kal_uint16 seq_num;
    kal_int16 lcd_rotate;
    kal_uint16 repeats;                     /* repeat count, 0xffff: infinite */

    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint16 video_display_offset_x;
    kal_uint16 video_display_offset_y;
    kal_bool force_lcd_hw_trigger;
#if (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238))
    kal_bool image_pitch_mode;              /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;           /* pitch width */
    /* TV Setting */
    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif /* (defined(MT6228) || defined(MT6229)||defined(MT6230) || defined(MT6238) ) */ 
} media_stream_set_info_struct;

typedef struct
{
    kal_uint32  param_id;
    kal_int16   value;
} media_stream_set_param_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   *session_id;
} media_stream_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint16   request_id;
    kal_uint8   net_id;
    kal_uint8   type;                               /* media_stream_conn_type_enum */
    kal_wchar   link_path[MED_MAX_LINK_PATH_LEN];
    kal_bool    use_proxy;
    kal_uint8   proxy_ip[MED_MAX_IP_LEN];
    kal_uint16  proxy_port;
    kal_uint16  lowest_udp_port;
    kal_uint16  highest_udp_port;
} media_stream_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_force_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint64  stop_time;
} media_stream_set_stop_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint16   request_id;
    kal_uint64  start_time;
} media_stream_seek_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_get_dl_percentage_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint16   request_id;
} media_stream_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_deinit_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    media_stream_get_info_struct *info;
} media_stream_get_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    media_stream_set_info_struct    info;
} media_stream_set_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    kal_uint16 level;
} media_stream_set_audio_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
} media_stream_switch_screen_videostop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
} media_stream_switch_screen_videostart_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    media_stream_set_param_struct    param;
} media_stream_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint64 *playing_time;
} media_stream_get_playing_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   result;     /* med_result_enum */
    kal_uint8   session_id;
    kal_uint16   request_id;
    kal_uint8   type_mask;  /* media_stream_media_type_enum */
    kal_uint8   seekable;   /* kal_true , kal_false */
    kal_uint64  media_len;
    kal_uint64  media_bw;
    kal_uint8   title[STREAM_MAX_TITLE_LEN];
} media_stream_connected_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   type_mask;  /* media_stream_media_type_enum */
    kal_uint32   event;
} media_stream_l1_callback_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   result;     /* med_result_enum */
    kal_uint8   session_id;
    kal_uint16   request_id;
} media_stream_seek_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   result;     /* med_result_enum */
    kal_uint8   session_id;
    kal_uint16   request_id;
} media_stream_play_ind_struct;

/**
  * @defgroup MTV_SAP
  * @{
  */

/**
  * Service activity. Activities can be OR'ed together to specify multiple activities
  * at the same time.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_ACTIVITY_PLAY      = 0x00000001,   /**< play media data */
    MEDIA_MTV_SERVICE_ACTIVITY_RECORD    = 0x00000002,   /**< record media data */
    MEDIA_MTV_SERVICE_ACTIVITY_DUMP      = 0x00000004    /**< dump media data into file */
} media_mtv_service_activity_enum;

/**
  * Service types.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_UNKNOWN,          /**< unknown service */
    MEDIA_MTV_SERVICE_DIGITAL_RADIO,    /**< digital radio */
    MEDIA_MTV_SERVICE_DIGITAL_TV,       /**< digital TV */
    MEDIA_MTV_SERVICE_MOT_SLIDESHOW,    /**< MOT slide show */
    MEDIA_MTV_SERVICE_TPEG,             /**< Transport Protocol Experts Group */
    MEDIA_MTV_SERVICE_BWS,              /**< Broadcast WebSite */
    MEDIA_MTV_SERVICE_FILE_DOWNLOAD     /**< file download */
} media_mtv_service_type_enum;

/**
  * Service sources.
  */
typedef enum
{
    MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL,    /**< scanning services from live signal */
    MEDIA_MTV_SERVICES_FROM_LOCAL_DATABASE  /**< load service info from local cache */
} media_mtv_service_source_enum;

/**
  * Frequency band.
  */
typedef enum
{
    MEDIA_MTV_INVALID_BAND,

    MEDIA_MTV_TDMB_KOREA_BAND,
    MEDIA_MTV_TDMB_BAND_III,
    MEDIA_MTV_TDMB_L_BAND,
    MEDIA_MTV_TDMB_CANADA_BAND,
    MEDIA_MTV_TDMB_CHINESE_BAND,
    MEDIA_MTV_TDMB_BAND_II,
    MEDIA_MTV_TDMB_BAND_IF
} media_mtv_band_enum;

/**
  * Service flags.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_FREE = 0x01,          /**< the service is available for free */
    MEDIA_MTV_SERVICE_CLEAR_TO_AIR = 0x02   /**< the service is not scrambled */
} media_mtv_service_flag_enum;

/**
  * Service state.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_STATE_STOPPED,        /**< the service has been started */
    MEDIA_MTV_SERVICE_STATE_STARTED,        /**< the service is ready for play, record, or other purposes */
    MEDIA_MTV_SERVICE_STATE_READY           /**< the service has been stopped */
} media_mtv_service_state_enum;

/**
  * Service events.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_STARTED,              /**< the service has been started */
    MEDIA_MTV_SERVICE_READY,                /**< the service is ready for play, record, or other purposes */
    MEDIA_MTV_SERVICE_ERROR,                /**< some error has happened for a service */
    MEDIA_MTV_SERVICE_STOPPED,              /**< the service has been stopped */
    MEDIA_MTV_SERVICE_ADDED,                /**< new service is available */
    MEDIA_MTV_SERVICE_REMOVED               /**< existing service is removed */
} media_mtv_service_event_enum;

/**
  * Service parameters that represent various status or setting you can query
  * or change for a service.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_PARAM_DUMMY           /**< dummy parameter */
} media_mtv_service_param_enum;

/**
  * Player events.
  */
typedef enum
{
    MEDIA_MTV_PLAYER_STARTED,               /**< the player has been started */
    MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED,      /**< the playback of time-shift content has been paused */
    MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED,     /**< delayed (buffered) content is played */
    MEDIA_MTV_PLAYER_TIMESHIFT_LIVE,        /**< live broadcast content is played */
    MEDIA_MTV_PLAYER_TIMESHIFT_ERROR,       /**< a time-shift error has occurred */
    MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT,  /**< a rewind hits the beginning of time-shift buffer */
    MEDIA_MTV_PLAYER_END_OF_CONTENT,        /**< a forward playback catches up with the live recording point */
    MEDIA_MTV_PLAYER_SNAPSHOT_TAKEN,        /**< a video snapshot has been taken. the event parameter will be the snapshot filename.  */
    MEDIA_MTV_PLAYER_DYNAMIC_LABEL,         /**< a dynamic label is available. the event parameter will be a null-terminated wchar string. */
    MEDIA_MTV_PLAYER_ERROR,                 /**< an internal error of player has happened. the client should stop the player immediately. */
    MEDIA_MTV_PLAYER_STOPPED                /**< the player has been stopped */
} media_mtv_player_event_enum;

/**
  * Recorder events.
  */
typedef enum
{
    MEDIA_MTV_RECORDER_STARTED,         /**< the recorder has been started */
    MEDIA_MTV_RECORDER_SAVING,          /**< file saving is in progress */
    MEDIA_MTV_RECORDER_SAVING_SUCCEEDED, /**< file saving is succeeded */
    MEDIA_MTV_RECORDER_SAVING_FAILED,    /**< file saving is failed */
    MEDIA_MTV_RECORDER_ERROR,           /**< an internal error of recorder has happened. the client should stop the recorder immediately. */
    MEDIA_MTV_RECORDER_STOPPED          /**< the recorder has been stopped. the event parameter will be the recorded filename. */
} media_mtv_recorder_event_enum;

/**
  * Player states.
  */
typedef enum
{
    MEDIA_MTV_PLAYER_STATE_STOPPED,     /**< the player is stopped */
    MEDIA_MTV_PLAYER_STATE_PLAYING,     /**< the player is playing the media */
    MEDIA_MTV_PLAYER_STATE_PAUSED       /**< the player is paused */
} media_mtv_player_state_enum;

/**
  * Recorder states.
  */
typedef enum
{
    MEDIA_MTV_RECORDER_STATE_STOPPED,   /**< the recorder is started */
    MEDIA_MTV_RECORDER_STATE_STARTED,   /**< the recorder is stopped */
    MEDIA_MTV_RECORDER_STATE_SAVING     /**< the recorder is saving the recorded program */
} media_mtv_recorder_state_enum;

/**
  * Parameter for MSG_ID_MEDIA_MTV_OPEN_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32* context;    /**< opaque context data */
    kal_uint32* result;
} media_mtv_open_req_struct;

/**
  * Recording settings.
  */
typedef struct
{
    kal_bool enable_timeshift;          /**< indicate whether to enable time-shift */
    kal_uint32 max_timeshift_delay;     /**< maximum time-shift delay in seconds. set it to 0 if don't care */
    kal_uint32 max_timeshift_buffer_kb; /**< maximum time-shift buffer size. set it to 0 if don't care */
    kal_wchar* record_dir;              /**< the directory to save recorded programs */
} media_mtv_config_record_struct;

#define MEDIA_MTV_REQ_HEADER \
   kal_uint32 context; \
   kal_uint32* result;

/**
  * Parameter for MSG_ID_MEDIA_MTV_CONFIG_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_config_video_struct video;        /**< video output settings */
    media_config_audio_struct audio;        /**< audio output settings */
    media_mtv_config_record_struct record;  /**< record settings */
} media_mtv_config_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_bool* found;  /**< indicates whether there is any unsaved recording */
} media_mtv_find_unsaved_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_recover_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_abort_recovering_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_discard_unsaved_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 error;
} media_mtv_complete_recovering_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 source;          /**< specifies where the services info comes from. @see media_mtv_service_source_enum */
    kal_uint32 band;   /**< only used when source is MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL @see media_mtv_band_enum */
} media_mtv_search_services_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 percentage;      /**< search progress in percentage */
} media_mtv_search_progress_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_abort_searching_req_struct;

/**
  * Service information.
  */
typedef struct
{
    kal_uint32 service_id;      /**< unique service ID */
    kal_wchar* service_name;    /**< the service name */
    kal_uint32 service_number;  /**< service number for easy access */
    kal_uint32 service_type;    /**< the service type. @see media_mtv_service_type_enum */
    kal_uint32 service_flags;   /**< the service flags. @see media_mtv_service_flag_enum */
} media_mtv_service_info_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    media_mtv_service_info_struct info;
} media_mtv_service_found_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_START_SERVICE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;      /**< the service to start */
    kal_uint32 activities;      /**< the activities to start. @see media_mtv_service_activity_enum */
} media_mtv_start_service_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 service_id;      /**< the service where the status comes from */
    kal_uint32 event;           /**< event code. @see media_mtv_service_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_service_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_play_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_pause_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_stop_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_uint32 delay_in_seconds;    /**< time-shift delay in seconds */
} media_mtv_player_seek_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_int32 rate;             /**< playback rate in unit of 1/1000. negative value for reversed playback. */
} media_mtv_player_set_rate_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_SNAPSHOT_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_snapshot_req_struct;

/**
  * Player status information.
  */
typedef struct
{
    kal_uint32 state;           /**< @see media_mtv_player_state_enum */
    kal_uint32 play_delay;      /**< playback delay in seconds */
    kal_uint32 max_delay;       /**< maximum delay in seconds */
    kal_uint32 buffer_duration; /**< allowable buffer duration. buffer_duration will always be larger than max_delay. */
    kal_int32 play_rate;        /**< current play rate */
} media_mtv_player_status_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    media_mtv_player_status_struct* status;
} media_mtv_player_get_status_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 service_id;      /**< the service where the status comes from */
    kal_uint32 event;           /**< event code. @see media_mtv_player_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_player_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_START_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_start_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_stop_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_save_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_discard_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_abort_saving_req_struct;

/**
  * Recorder status information.
  */
typedef struct
{
    kal_uint32 state;               /**< @see media_mtv_recorder_state_enum */
    kal_uint32 recorded_duration;   /**< current recorder duration in seconds */
} media_mtv_recorder_status_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    media_mtv_recorder_status_struct* status;   /**< address of status struct */
} media_mtv_recorder_get_status_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 service_id;      /**< the service where the status comes from */
    kal_uint32 event;           /**< event code. @see media_mtv_recorder_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_recorder_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SET_PARAM_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;  /**< the service to change */
    kal_uint32 param;       /**< the parameter ID */
    kal_uint32 value;       /**< the parameter value */
} media_mtv_set_param_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_GET_PARAM_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;  /**< the service to query */
    kal_uint32 param;       /**< the parameter ID */
    kal_uint32* value;      /**< the parameter value */
} media_mtv_get_param_req_struct;

typedef struct
{
    media_mtv_service_state_enum state; /* service state */
    kal_uint32 signal_strength;     /**< the signal strength */

    /**
      * Indicates whether timeshift is available or not. For example, if the disk free space gets low,
      * time-shift will be disabled forcely. MMI can check this flag to decide whether the user can do
      * trick-mode playback or recording.
      */
    kal_bool timeshift_available;

} media_mtv_service_status_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    media_mtv_service_status_struct* status;    /**< address of status struct */
} media_mtv_service_get_status_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;  /**< the service to stop */
} media_mtv_stop_service_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_CLOSE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_close_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ASYNC_WRITE.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void* io;       /**< the pointer to async I/O object */
} media_mtv_async_write_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ASYNC_CALLBACK.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void (*callback)(void* param);  /**< the callback fucntion */
    void* param;                    /**< the opaque parameter for calback function */
} media_mtv_async_callback_req_struct;

/**
  * Parameter for MSG_ID_TDMB_DATA_INDICATION.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void* tdmb_demod;
} media_mtv_tdmb_data_ind_struct;

/** @} */

/* 
 * vcall messages
 */
typedef enum
{
    VCALL_VIEW_HIDE,
    VCALL_VIEW_SHOW_IMAGE,
    VCALL_VIEW_SHOW_VIDEO,
    
    VCALL_VIEW_TOTAL
} media_vcall_view_type_enum;

typedef enum
{
    VCALL_ENC_QTY_LOW = 0,
    VCALL_ENC_QTY_NORMAL,
    VCALL_ENC_QTY_FINE,

    VCALL_ENC_QTY_TOTAL
} media_vcall_enc_qty_enum;


/* Video recorder */
typedef enum
{
    VID_REC_QTY_LOW = 0,
    VID_REC_QTY_NORMAL,
    VID_REC_QTY_HIGH,
    VID_REC_QTY_FINE,
    
    VID_NO_OF_REC_QTY
} mdia_vid_rec_qty_enum;

typedef struct
{
    kal_uint16 encode_width; 	
    kal_uint16 encode_height;
    kal_uint16 preview_width;
    kal_uint16 preview_height;
    void *preview_buffer_p;
    kal_uint32 preview_buffer_size;

    kal_int16 camera_rotate;
    kal_int16 lcd_rotate;
    kal_int16 zoom_factor;
    kal_int16 exposure;

    kal_int16 contrast;
    kal_int16 brightness;
    kal_int16 saturation;
    kal_int16 hue;
    kal_int16 gamma;
    kal_int16 WB;
    kal_int16 effect;
    kal_bool night_mode;
    kal_uint8 banding_freq;
    kal_uint8 encode_quality;

    kal_uint16 seq_num;

    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint32 src_key_color;
    kal_bool lcd_update;

#if (defined(MT6228) || defined(MT6229)||defined(MT6230))
    /* TV Setting */
    kal_bool tv_output;
    kal_uint16 tv_output_width;                 /* image width for TV output */
    kal_uint16 tv_output_height;                /* image height for TV output */
    kal_uint16 tv_output_offset_x;              /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;              /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;       /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;       /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;           /* image buffer size for TV source buffer */

    /* LCD Setting */
    kal_uint32 roi_background_color;            /* set the background color */
    
    kal_uint8  image_data_format;
#endif
} media_video_record_struct;

typedef struct
{
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *display_buffer_p;
    kal_uint32 display_buffer_size;
    kal_int16 lcd_rotate;

    kal_int16 contrast;
    kal_int16 brightness;

    kal_uint16 seq_num;
    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;

#if (defined(MT6228) || defined(MT6229)||defined(MT6230))
    /* TV Setting */
    kal_bool tv_output;
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */
#endif

    kal_uint32 roi_background_color;        /* set the background color */
    kal_uint8 image_data_format;
} media_video_playback_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_vcall_view_type_enum recorder_view_type;
    media_vcall_view_type_enum player_view_type;
    media_video_record_struct recorder;
    media_video_playback_struct player;    
} media_vcall_video_codec_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vcall_video_codec_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vcall_channel_report_ind_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef struct
{
    LOCAL_PARA_HDR
} media_vcall_video_replenish_data_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event_seq_no;
} media_vcall_video_encode_data_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event_seq_no;
} media_vcall_video_decode_data_ready_ind_struct;


typedef enum
{
    VCALL_VIDEO_SIZE_QCIF,
    VCALL_VIDEO_SIZE_SQCIF
    
} media_vcall_video_size_enum;

typedef enum
{
    VCALL_EVENT_CHANGE_ENCODE_SIZE,
    VCALL_EVENT_CHANGE_ENCODE_QUALITY
    
} media_vcall_codec_event_enum;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seq_no;
    media_vcall_codec_event_enum codec_event;
    kal_int32 para;
} media_vcall_video_codec_report_ind_struct;


#endif /* _MED_STRUCT_H */ 

#endif /* MED_NOT_PRESENT */ 

