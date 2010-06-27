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
*  permission of MediaTek Inc. (C) 2004
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 * video_editor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    video global header files. Other modules should include this header file 
 *    to use video driver.
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
 * removed!
 * removed!
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
#ifndef VIDEO_EDITOR_COMM_H
#define VIDEO_EDITOR_COMM_H

typedef struct 
{
   kal_uint32  start_frame_number;  /*0~n-1*/
   kal_bool    start_frame_discard;
   kal_uint32  delta_start_frame_duratoin; 
      /* if start_frame_discard =1, 
         	first_frame_duration = first_frame_duration + delta_start_frame_duratoin; 
         if start_frame_discard =0, 
         	first_frame_duration = delta_start_frame_duratoin;*/
   kal_uint32  end_frame_number;  /*0~n-1*/
   kal_bool    end_frame_discard;
   kal_uint32  delta_end_frame_duratoin;
      /* if end_frame_discard =1, 
         	end_frame_duration = end_frame_duration + delta_end_frame_duratoin; 
         if end_frame_discard =0, 
         	end_frame_duration = delta_end_frame_duratoin;*/
} VEDITOR_AVSYNC_VIDEO_STRUCT;

typedef struct {
   kal_uint32  audio_start_frame;
   kal_uint32  audio_end_frame;
   kal_uint32  mute_frame_count; /*frame count*/
} VEDITOR_AVSYNC_AUDIO_STRUCT;

typedef enum {
   VIEDO_EDITOR_STATE_IDLE = 0,
   VIEDO_EDITOR_STATE_OPEN,
   VIEDO_EDITOR_STATE_OPEN_NEXT,
   VIEDO_EDITOR_STATE_SEEK,
   VIEDO_EDITOR_STATE_START,
   VIEDO_EDITOR_STATE_MAX
} VIEDO_EDITOR_STATE;

typedef struct 
{
   /*For image*/
   kal_uint8                     *image_yuv420_buffer;
   kal_uint16                    image_yuv420_width;
   kal_uint16                    image_yuv420_height;
   kal_uint32                    image_duration;
   /*for video decoder*/
   STMp4Parser                   *pstVIDParser;
   STFSAL                        *pstVIDFSAL;
   STMp4Parser                   *pstAUDParser;
   STFSAL                        *pstAUDFSAL;
   kal_bool								is_new_video;
   /*For encoder*/
   kal_uint8                     *video_enc_yuv420_buffer;
   kal_bool                      short_header;
   kal_uint32                    bit_rate;
   VIEDO_EDITOR_STATE            veditor_state;
   /*AV sync*/
   kal_uint32                    glb_time_stamp;
   kal_bool                      call_by_next;
   void                          (*call_back)(kal_uint8 event);
   kal_bool                      (*check_end_call_back)(void);
   void                          (*encode_complete_call_back)(void);
   kal_bool                      video_decode_end;
   kal_bool							 	is_force_end;
   VEDITOR_AVSYNC_VIDEO_STRUCT   video_avsync;
   VEDITOR_AVSYNC_AUDIO_STRUCT   audio_avsync;
   kal_bool                      need_avsync;
   kal_uint16                    decode_frame_width;
   kal_uint16                    decode_frame_height;
   kal_uint16                    encode_frame_width;
   kal_uint16                    encode_frame_height;
   kal_uint32                    video_time_scale;
   kal_uint32                    audio_time_scale;
   kal_uint32                    video_start_time;
   kal_uint32                    audio_start_time;
   kal_uint32                    av_duration;
   kal_uint32							total_frames;
   kal_uint32							hisr_total_frames;
   kal_uint32							lastest_frame_furation;	/*Unit: VIDEO_COMMON_TIME_BASE*/
   // image path type
   VIDEO_DEC_IMG_PATH_TYPE       path_type;
   /*effect*/
   kal_uint32                    effect_start_frame;
   kal_uint32                    effect_end_frame;
   void                          (*effect_cb)(void);
}VIDEO_EDITOR_STRUCT;

#endif   /**/
