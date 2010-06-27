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
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    video_editor.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines video editor api for media task
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__VIDEO_EDITOR__)
#include    "FSAL.h"
#include    "MP4_Parser.h"
#include    "MP4_Producer_Audio.h"
#include    "MP4_Sample_Data_Audio.h"
#include    "img_comm.h"
#include    "rtc_sw.h"
#include    "lcd_if.h"
#include    "video_file_creator.h"
#include    "drv_comm.h"
#include    "visual_comm.h"
#include    "l1audio.h"
#include    "bmd.h"
#include    "video_dec_glb.h"
#include    "video_enc_glb.h"
#include    "video_glb.h"
#include    "video_editor.h"
#include    "video_hw.h"
#include    "intrCtrl.h"
#include    "visualhisr.h"

extern VISUAL_MEM_STRUCT visual_mem;
extern VIDEO_EDITOR_STRUCT       VIDEO_EDITOR_DATA;
extern MP4_FILELIST_STRUCT       mp4_files;

extern kal_uint32 video_editor_get_virtual_time(void);
extern void video_editor_set_virtual_time(kal_uint32 virtual_time);

extern void video_enc_lisr_process(kal_uint32 encode_work_yuv, 
                                    kal_uint32 time_stamp, 
                                    kal_uint32 delay_offset);
extern void mpeg4_dec_seek_lisr_process(kal_uint32 status);
extern void video_dec_set_seek_frame(kal_uint32 frame_number);

extern MEDIA_STATUS_CODE video_editor_get_first_audio_frame(kal_uint32 video_frame, 
                                                     kal_uint32 *audio_first_frame_number,
                                                     kal_bool   *has_audio_frame);
extern MEDIA_STATUS_CODE video_editor_get_last_audio_frame(kal_uint32 current_video_frame, 
                                                    kal_uint32 *audio_last_frame_number);
extern MEDIA_STATUS_CODE video_encode_comm_setup(MP4ENC_SETUP_STRUCT *setup_input);
extern MEDIA_STATUS_CODE video_dec_editor_initialize(MP4DEC_INIT_STRUCT *init_input);
extern MEDIA_STATUS_CODE video_editor_avsync_info(kal_bool   av_sync, 
                                                 kal_uint32 video_start_time,
                                                 kal_uint32 audio_start_time,
                                                 kal_uint32 av_duration,
                                                 VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, 
                                                 kal_uint32 *current_video_frame_no);
extern MEDIA_STATUS_CODE video_dec_seek_by_frame(kal_uint32 frame_no, void (*callback)(kal_uint8 event), kal_bool seek_from_current_frame);
extern MEDIA_STATUS_CODE video_editor_av_duration_info(kal_uint32 audio_start_time,
                                                kal_uint32 av_duration,
                                                kal_uint32 *real_av_duration, /*Unit: common_base*/
                                                kal_uint32 *real_audio_start_time, /*Unit: common_base*/
                                                kal_uint32 *real_audio_end_time, /*Unit: common_base*/
                                                VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync);
extern MEDIA_STATUS_CODE video_editor_effect_duration(kal_uint32 effect_start_time, /*Unit: ms*/
                                               kal_uint32 effect_duration, /*Unit: ms*/
                                               kal_uint32 *effect_start_frame,
                                               kal_uint32 *effect_end_frame);
#ifdef MP4_MOVE_LISR_TO_HISR                                               
extern void mpeg4_dec_first_HISR(void);                                               
#endif
extern void mpeg4_dec_seek_HISR(void);
extern void video_enc_fr_evalutaion_init(kal_int32 frame_rate);

void MPEG4_EDITOR_ENC_LISR(void);
void MPEG4_EDITOR_LHISR(void);
void MPEG4_EDITOR_LISR(void);
void VIDEO_EDITOR_ENC_HISR(void);
void MPEG4_EDITOR_IMAGEPATH_START(kal_uint32 yuv_start_address);

video_editor_data_path_struct   video_editor_para;
kal_bool				is_section_first;

/*Video editor common part*/
kal_uint32 video_editor_avsync_first_frame(kal_uint32 current_time_stamp)
{
     kal_uint32 org_time_stamp = current_time_stamp;
	if (VIDEO_EDITOR_DATA.video_avsync.start_frame_number != VIDEO_EDITOR_DATA.video_avsync.end_frame_number)
	{
	   if (VIDEO_EDITOR_DATA.video_avsync.start_frame_discard)
	   {
	      current_time_stamp += mpeg4_dec_get_curr_frame_duration()+VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin;
	   }
	   else
	   {
	      current_time_stamp += VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin;
	   }
	}
	else
	{
		if (VIDEO_EDITOR_DATA.video_avsync.start_frame_discard)
	   {
	   	VIDEO_EDITOR_DATA.video_avsync.start_frame_discard = KAL_FALSE;
	   	current_time_stamp += VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin;
	      VIDEO_ASSERT(0);
	   }
	   else
	   {
	   	if (VIDEO_EDITOR_DATA.video_avsync.end_frame_discard)
	   	{
	   		current_time_stamp = current_time_stamp+VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin;
	   	}
	   	else
	   	{
	      	current_time_stamp = current_time_stamp+VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin+
	      								VIDEO_EDITOR_DATA.video_avsync.delta_end_frame_duratoin-mpeg4_dec_get_curr_frame_duration();
		}
	   	if (current_time_stamp < org_time_stamp)
	      {
	      	VIDEO_ASSERT(0);
  	   	     current_time_stamp = org_time_stamp+(kal_uint32)VIDEO_ANYBASE_TO_COMMBASE( VIDEO_EDITOR_DATA.av_duration, 1000);
	      }
	   }
	}
   return current_time_stamp;
}

kal_uint32 video_editor_avsync_end_frame(kal_uint32 current_time_stamp)
{
	if (VIDEO_EDITOR_DATA.video_avsync.start_frame_number != VIDEO_EDITOR_DATA.video_avsync.end_frame_number)
	{
	   if (VIDEO_EDITOR_DATA.video_avsync.end_frame_discard)
	   {
	      current_time_stamp += mpeg4_dec_get_curr_frame_duration()+VIDEO_EDITOR_DATA.video_avsync.delta_end_frame_duratoin;
	   }
	   else
	   {
	      current_time_stamp += VIDEO_EDITOR_DATA.video_avsync.delta_end_frame_duratoin;
	   }
	}
	
   return current_time_stamp;
}

kal_bool video_editor_check_end(void)
{
   if (VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL)
   {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   }
   else 
   {  
      /*Image YUV420 path*/
      VIDEO_EDITOR_DATA.glb_time_stamp = VIDEO_EDITOR_DATA.glb_time_stamp+VIDEO_EDITOR_DATA.image_duration;
      VIDEO_EDITOR_DATA.video_decode_end = KAL_TRUE;
   }
   
   return VIDEO_EDITOR_DATA.video_decode_end;
}

MEDIA_STATUS_CODE video_editor_open(VIDEO_EDITOR_OPEN_STRUCT *veditor_struct, VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, kal_uint32 *current_video_frame_no)
{
   MEDIA_STATUS_CODE result;
   MP4ENC_SETUP_STRUCT  video_enc_input;
   MP4DEC_INIT_STRUCT   video_dec_input;
   
   video_dbg_trace(MP4_EDT_OPEN, video_get_current_time());
   VIDEO_EDITOR_DATA.video_enc_yuv420_buffer = NULL;
   is_section_first = KAL_TRUE;
   if ((visual_mem.ext_ram_init==KAL_FALSE)||(visual_mem.int_ram_init==KAL_FALSE))
  	{
  		ASSERT(0);
  	}

   if ( (visual_mem.ext_ram_index > 300000) || (visual_mem.int_ram_index > 2000) )
   {
      VIDEO_ASSERT(0);
   }

   if (veditor_struct->image_yuv420_buffer == NULL)   
   {
      ASSERT(veditor_struct->pstVIDParser != NULL);
   }
   else if (veditor_struct->pstVIDParser == NULL)
   {
      ASSERT(veditor_struct->image_yuv420_buffer != NULL);
   }
   ASSERT(VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_IDLE);
   ASSERT( (veditor_struct != NULL) && (audio_avsync != NULL) );

   VISUAL_Register_HISR(VISUAL_MP4_EDITOR_LISR_HISR_ID, MPEG4_EDITOR_LHISR);
   g_video_dec_status.scenario = VIDEO_SCENARIO_EDITOR;
   g_video_enc_status.scenario = VIDEO_SCENARIO_EDITOR;
   
   VIDEO_EDITOR_DATA.image_yuv420_buffer = veditor_struct->image_yuv420_buffer;
   VIDEO_EDITOR_DATA.image_yuv420_width = veditor_struct->image_yuv420_width;
   VIDEO_EDITOR_DATA.image_yuv420_height = veditor_struct->image_yuv420_height;
   VIDEO_EDITOR_DATA.pstVIDParser = veditor_struct->pstVIDParser;
   VIDEO_EDITOR_DATA.pstVIDFSAL = veditor_struct->pstVIDFSAL;
   VIDEO_EDITOR_DATA.pstAUDParser = veditor_struct->pstAUDParser;
   VIDEO_EDITOR_DATA.pstAUDFSAL = veditor_struct->pstAUDFSAL;
   VIDEO_EDITOR_DATA.is_new_video = KAL_TRUE;
   VIDEO_EDITOR_DATA.lastest_frame_furation = 0;
   
//   VIDEO_EDITOR_DATA.editor_type = veditor_struct->editor_type;
   VIDEO_EDITOR_DATA.call_back = veditor_struct->call_back;
   VIDEO_EDITOR_DATA.call_by_next = KAL_FALSE;
   VIDEO_EDITOR_DATA.need_avsync = veditor_struct->need_avsync;
   VIDEO_EDITOR_DATA.video_start_time = veditor_struct->video_start_time;
   VIDEO_EDITOR_DATA.audio_start_time = veditor_struct->audio_start_time;
   VIDEO_EDITOR_DATA.av_duration = veditor_struct->av_duration;
   VIDEO_EDITOR_DATA.check_end_call_back = video_editor_check_end;
   VIDEO_EDITOR_DATA.encode_complete_call_back = VIDEO_EDITOR_ENC_HISR;
   VIDEO_EDITOR_DATA.video_decode_end = KAL_FALSE;
   VIDEO_EDITOR_DATA.is_force_end = KAL_FALSE;

   /*Obtain AV time scale*/
   VIDEO_EDITOR_DATA.glb_time_stamp = 0;
   
   if (VIDEO_EDITOR_DATA.pstAUDParser != NULL)
   {
	   g_video_dec_status.PARSE_STATUS =
	               MP4_GetMediaTimeScale(VIDEO_EDITOR_DATA.pstAUDParser,
	                               &VIDEO_EDITOR_DATA.audio_time_scale,
	                               MP4_TRACK_AUDIO);
	   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
	   {
	      VIDEO_ASSERT(0);
	      return MP4_PARSER_ERROR;
	   }
	}
	else
	{
		VIDEO_ASSERT(0);
		VIDEO_EDITOR_DATA.audio_time_scale = 0;
	}
      
   if (veditor_struct->image_yuv420_buffer == NULL)
   {
   	/*Video path*/
      ASSERT(current_video_frame_no != NULL);

      g_video_dec_status.PARSE_STATUS =
               MP4_GetMediaTimeScale(VIDEO_EDITOR_DATA.pstVIDParser,
                               &VIDEO_EDITOR_DATA.video_time_scale,
                               MP4_TRACK_VIDEO);
      if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
      {
         VIDEO_ASSERT(0);
         return MP4_PARSER_ERROR;
      }
      
      /*Video decorder initialize*/
      ASSERT(g_video_dec_status.running == KAL_FALSE);
      ASSERT(g_video_enc_status.running == KAL_FALSE);
      
      /*Decode initialize*/
      video_dec_input.pstMp4Parser = veditor_struct->pstVIDParser;
      video_dec_input.pstFSAL = veditor_struct->pstVIDFSAL;
      video_dec_input.video_dec_callback = veditor_struct->call_back;
      video_dec_input.max_width = VIDEO_EDITOR_MAX_FRAME_WIDTH;
      video_dec_input.max_height = VIDEO_EDITOR_MAX_FRAME_HEIGHT; 
      video_dec_input.audio_enable = KAL_TRUE;	  
      result = video_dec_editor_initialize(&video_dec_input);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      
      VIDEO_EDITOR_DATA.decode_frame_width = g_video_dec_info_ptr->width;
      VIDEO_EDITOR_DATA.decode_frame_height = g_video_dec_info_ptr->height;
      VIDEO_EDITOR_DATA.encode_frame_width = veditor_struct->encode_frame_width;
      VIDEO_EDITOR_DATA.encode_frame_height = veditor_struct->encode_frame_height;
      if (VIDEO_EDITOR_DATA.video_enc_yuv420_buffer == NULL)
      {
         VIDEO_EDITOR_DATA.video_enc_yuv420_buffer = (kal_uint8 *)extmem_get_buffer(VIDEO_EDITOR_DATA.encode_frame_width*VIDEO_EDITOR_DATA.encode_frame_height*3/2);
      }
   
      VIDEO_EDITOR_DATA.bit_rate = veditor_struct->bit_rate;
      VIDEO_EDITOR_DATA.short_header = veditor_struct->short_header;
      video_enc_input.short_header   =  veditor_struct->short_header;
      video_enc_input.bit_rate       =  veditor_struct->bit_rate;
      video_enc_input.frame_width    =  veditor_struct->encode_frame_width;
      video_enc_input.frame_height   =  veditor_struct->encode_frame_height;
      video_enc_input.call_back      =  veditor_struct->call_back;
      
      /*Encode initialize*/
      result = video_encode_comm_setup(&video_enc_input);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }

      kal_prompt_trace( MOD_MED_V, "**O:EV=%d,EA=%d,Eav_T=%d", veditor_struct->video_start_time, veditor_struct->audio_start_time, veditor_struct->av_duration);
      /*Obtain AV sync info*/
      result = video_editor_avsync_info(veditor_struct->need_avsync, 
                                        veditor_struct->video_start_time,
                                        veditor_struct->audio_start_time,
                                        veditor_struct->av_duration,
                                        audio_avsync, 
                                        current_video_frame_no);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }

      kal_prompt_trace( MOD_MED_V, "O:AFS=%d,AFE=%d,MU=%d", audio_avsync->audio_start_frame, audio_avsync->audio_end_frame, audio_avsync->mute_frame_count);
      
      /*Obtain effect duration*/
      result = video_editor_effect_duration(veditor_struct->effect_start_time,
                                            veditor_struct->effect_duration,
                                            &VIDEO_EDITOR_DATA.effect_start_frame,
                                            &VIDEO_EDITOR_DATA.effect_end_frame);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_OPEN;
   }
   else  /*if (veditor_struct->image_yuv420_buffer == NULL)*/
   {
   	/*Image path*/
      kal_uint32        real_audio_start_time;
      kal_uint32        real_audio_end_time;
      
      /*Video decorder initialize*/
      ASSERT(g_video_dec_status.running == KAL_FALSE);
      ASSERT(g_video_enc_status.running == KAL_FALSE);
      VIDEO_EDITOR_DATA.image_yuv420_width = veditor_struct->image_yuv420_width;
      VIDEO_EDITOR_DATA.image_yuv420_height = veditor_struct->image_yuv420_height;
      VIDEO_EDITOR_DATA.encode_frame_width = veditor_struct->encode_frame_width;
      VIDEO_EDITOR_DATA.encode_frame_height = veditor_struct->encode_frame_height;
      VIDEO_EDITOR_DATA.bit_rate = veditor_struct->bit_rate;
      VIDEO_EDITOR_DATA.short_header = veditor_struct->short_header;
      VIDEO_EDITOR_DATA.total_frames = 0;
      VIDEO_EDITOR_DATA.hisr_total_frames = 0;
      video_enc_input.short_header   =  veditor_struct->short_header;
      video_enc_input.bit_rate       =  veditor_struct->bit_rate;
      video_enc_input.frame_width    =  veditor_struct->encode_frame_width;
      video_enc_input.frame_height   =  veditor_struct->encode_frame_height;
      video_enc_input.call_back      =  veditor_struct->call_back;

      if (VIDEO_EDITOR_DATA.video_enc_yuv420_buffer == NULL)
      {
         VIDEO_EDITOR_DATA.video_enc_yuv420_buffer = (kal_uint8 *)extmem_get_buffer(VIDEO_EDITOR_DATA.encode_frame_width*VIDEO_EDITOR_DATA.encode_frame_height*3/2);
      }
      
      /*Encode initialize*/
      result = video_encode_comm_setup(&video_enc_input);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }

      /*Obtain AV sync info*/
      result = video_editor_av_duration_info(veditor_struct->audio_start_time,
                                             veditor_struct->av_duration,
                                             &VIDEO_EDITOR_DATA.image_duration,
                                             &real_audio_start_time,
                                             &real_audio_end_time,
                                             audio_avsync);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      VIDEO_EDITOR_DATA.lastest_frame_furation = VIDEO_EDITOR_DATA.image_duration;
      VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_SEEK;
   }
   video_enc_fr_evalutaion_init(15);
   g_video_enc_info_ptr->total_frames = 0;
   g_video_enc_info_ptr->hisr_total_frames = 0;
   video_dbg_trace(MP4_EDT_OPEN_END, video_get_current_time());
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_open_next(VIDEO_EDITOR_OPEN_NEXT_STRUCT *veditor_struct, VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, kal_uint32 *current_video_frame_no)
{
   MEDIA_STATUS_CODE    result;
   MP4ENC_SETUP_STRUCT  video_enc_input;
   MP4DEC_INIT_STRUCT   video_dec_input;
   
   is_section_first = KAL_TRUE;
   video_dbg_trace(MP4_EDT_OPEN_NEXT, video_get_current_time());
  	if ((visual_mem.ext_ram_init==KAL_FALSE)||(visual_mem.int_ram_init==KAL_FALSE))
  	{
  		ASSERT(0);
  	}
   if (veditor_struct->is_new_video==KAL_FALSE)
   {
	    if ( (visual_mem.ext_ram_index <= 300000) || (visual_mem.int_ram_index <= 2000) )
	    {
         VIDEO_ASSERT(0);
       }
   }
   else
   {
		 if ( (visual_mem.ext_ram_index > 300000) || (visual_mem.int_ram_index > 2000) )
		 {
          VIDEO_ASSERT(0);
       }
   }

   if (veditor_struct->image_yuv420_buffer == NULL)   
   {
      ASSERT(veditor_struct->pstVIDParser != NULL);
   }
   else if (veditor_struct->pstVIDParser == NULL)
   {
      ASSERT(veditor_struct->image_yuv420_buffer != NULL);
   }
//   ASSERT(VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_IDLE);
   ASSERT( (veditor_struct != NULL) && (audio_avsync != NULL) );

   VISUAL_Register_HISR(VISUAL_MP4_EDITOR_LISR_HISR_ID, MPEG4_EDITOR_LHISR);
   g_video_dec_status.scenario = VIDEO_SCENARIO_EDITOR;
   g_video_enc_status.scenario = VIDEO_SCENARIO_EDITOR;
   
   VIDEO_EDITOR_DATA.lastest_frame_furation = 0;
   VIDEO_EDITOR_DATA.image_yuv420_buffer = veditor_struct->image_yuv420_buffer;
   VIDEO_EDITOR_DATA.image_yuv420_width = veditor_struct->image_yuv420_width;
   VIDEO_EDITOR_DATA.image_yuv420_height = veditor_struct->image_yuv420_height;
   VIDEO_EDITOR_DATA.pstVIDParser = veditor_struct->pstVIDParser;
   VIDEO_EDITOR_DATA.pstVIDFSAL = veditor_struct->pstVIDFSAL;
   VIDEO_EDITOR_DATA.pstAUDParser = veditor_struct->pstAUDParser;
   VIDEO_EDITOR_DATA.pstAUDFSAL = veditor_struct->pstAUDFSAL;
   VIDEO_EDITOR_DATA.is_new_video = veditor_struct->is_new_video;
   VIDEO_EDITOR_DATA.call_by_next = KAL_TRUE;
   VIDEO_EDITOR_DATA.call_back = veditor_struct->call_back;
   VIDEO_EDITOR_DATA.need_avsync = veditor_struct->need_avsync;
   VIDEO_EDITOR_DATA.video_start_time = veditor_struct->video_start_time;
   VIDEO_EDITOR_DATA.audio_start_time = veditor_struct->audio_start_time;
   VIDEO_EDITOR_DATA.av_duration = veditor_struct->av_duration;
   VIDEO_EDITOR_DATA.check_end_call_back = video_editor_check_end;
   VIDEO_EDITOR_DATA.encode_complete_call_back = VIDEO_EDITOR_ENC_HISR;
   VIDEO_EDITOR_DATA.video_decode_end = KAL_FALSE;
   VIDEO_EDITOR_DATA.is_force_end = KAL_FALSE;
   
   if (VIDEO_EDITOR_DATA.pstAUDParser != NULL)
   {
	   g_video_dec_status.PARSE_STATUS =
	               MP4_GetMediaTimeScale(VIDEO_EDITOR_DATA.pstAUDParser,
	                               &VIDEO_EDITOR_DATA.audio_time_scale,
	                               MP4_TRACK_AUDIO);
	   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
	   {
	      VIDEO_ASSERT(0);
	      return MP4_PARSER_ERROR;
	   }
	}
	else
	{
		VIDEO_ASSERT(0);
		VIDEO_EDITOR_DATA.audio_time_scale = 0;
	}
   
   if (veditor_struct->image_yuv420_buffer == NULL)
   {
   	/*Video path*/
      ASSERT(current_video_frame_no != NULL);
      g_video_dec_status.PARSE_STATUS =
               MP4_GetMediaTimeScale(VIDEO_EDITOR_DATA.pstVIDParser,
                               &VIDEO_EDITOR_DATA.video_time_scale,
                               MP4_TRACK_VIDEO);
      if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
      {
         VIDEO_ASSERT(0);
         return MP4_PARSER_ERROR;
      }
      
      /*Decode initialize*/
      video_dec_input.pstMp4Parser = veditor_struct->pstVIDParser;
      video_dec_input.pstFSAL = veditor_struct->pstVIDFSAL;
      video_dec_input.video_dec_callback = veditor_struct->call_back;
      video_dec_input.max_width = VIDEO_EDITOR_MAX_FRAME_WIDTH;
      video_dec_input.max_height = VIDEO_EDITOR_MAX_FRAME_HEIGHT; 
      video_dec_input.audio_enable = KAL_TRUE; 
      if (veditor_struct->is_new_video == KAL_TRUE)
      {
      	result = video_dec_editor_initialize(&video_dec_input);
      	if (result != MEDIA_STATUS_OK)
      	{
         	VIDEO_ASSERT(0);
         	return result;
      	}
      }
      
      VIDEO_EDITOR_DATA.decode_frame_width = g_video_dec_info_ptr->width;
      VIDEO_EDITOR_DATA.decode_frame_height = g_video_dec_info_ptr->height;
      
      /*Encode initialize*/
      video_enc_input.short_header   =  VIDEO_EDITOR_DATA.short_header;
      video_enc_input.bit_rate       =  VIDEO_EDITOR_DATA.bit_rate;
      video_enc_input.frame_width    =  VIDEO_EDITOR_DATA.encode_frame_width;
      video_enc_input.frame_height   =  VIDEO_EDITOR_DATA.encode_frame_height;
      if ( (VIDEO_EDITOR_DATA.video_enc_yuv420_buffer == NULL) && (veditor_struct->is_new_video == KAL_TRUE) )
      {
         VIDEO_EDITOR_DATA.video_enc_yuv420_buffer = (kal_uint8 *)extmem_get_buffer(VIDEO_EDITOR_DATA.encode_frame_width*VIDEO_EDITOR_DATA.encode_frame_height*3/2);
      }
      video_enc_input.call_back      =  veditor_struct->call_back;
      
      result = video_encode_comm_setup(&video_enc_input);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      
      kal_prompt_trace( MOD_MED_V, "(GBCNT)=%d", (kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(VIDEO_EDITOR_DATA.glb_time_stamp,1000));
      
      kal_prompt_trace( MOD_MED_V, "*ON:EV=%d,EA=%d,Eav_T=%d", veditor_struct->video_start_time, veditor_struct->audio_start_time, veditor_struct->av_duration);
      /*Obtain AV sync info*/
      result = video_editor_avsync_info(veditor_struct->need_avsync, 
                                        veditor_struct->video_start_time,
                                        veditor_struct->audio_start_time,
                                        veditor_struct->av_duration,
                                        audio_avsync, 
                                        current_video_frame_no);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      
      kal_prompt_trace( MOD_MED_V, "ON:AFS=%d,AFE=%d,MU=%d", audio_avsync->audio_start_frame, audio_avsync->audio_end_frame, audio_avsync->mute_frame_count);
      /*Obtain effect duration*/
      result = video_editor_effect_duration(veditor_struct->effect_start_time,
                                            veditor_struct->effect_duration,
                                            &VIDEO_EDITOR_DATA.effect_start_frame,
                                            &VIDEO_EDITOR_DATA.effect_end_frame);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      
      VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_OPEN_NEXT;
   }
   else  /*if (veditor_struct->image_yuv420_buffer == NULL)*/
   {
      kal_uint32        real_audio_start_time;
      kal_uint32        real_audio_end_time;
      
      /*Video decorder initialize*/
      video_enc_input.short_header   =  VIDEO_EDITOR_DATA.short_header;
      video_enc_input.bit_rate       =  VIDEO_EDITOR_DATA.bit_rate;
      video_enc_input.frame_width    =  VIDEO_EDITOR_DATA.encode_frame_width;
      video_enc_input.frame_height   =  VIDEO_EDITOR_DATA.encode_frame_height;
      video_enc_input.call_back      =  veditor_struct->call_back;
      
      ASSERT(veditor_struct->is_new_video == KAL_TRUE);
      
      if (VIDEO_EDITOR_DATA.video_enc_yuv420_buffer == NULL)
      {
         VIDEO_EDITOR_DATA.video_enc_yuv420_buffer = (kal_uint8 *)extmem_get_buffer(VIDEO_EDITOR_DATA.encode_frame_width*VIDEO_EDITOR_DATA.encode_frame_height*3/2);
      }
      
      /*Encode initialize*/
      result = video_encode_comm_setup(&video_enc_input);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }

      /*Obtain AV sync info*/
      result = video_editor_av_duration_info(veditor_struct->audio_start_time,
                                             veditor_struct->av_duration,
                                             &VIDEO_EDITOR_DATA.image_duration,
                                             &real_audio_start_time,
                                             &real_audio_end_time,
                                             audio_avsync);
                                                    
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      VIDEO_EDITOR_DATA.lastest_frame_furation = VIDEO_EDITOR_DATA.image_duration;
      VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_SEEK;
   }
   
   if (veditor_struct->is_new_video)
   {
   	g_video_enc_info_ptr->total_frames = VIDEO_EDITOR_DATA.total_frames;
   	g_video_enc_info_ptr->hisr_total_frames = VIDEO_EDITOR_DATA.hisr_total_frames;
   }
   video_enc_fr_evalutaion_init(15);
   video_dbg_trace(MP4_EDT_OPEN_NEXT_END, video_get_current_time());
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_seek_by_frame(kal_uint32 frame, void (*callback)(kal_uint8 event))
{
   MEDIA_STATUS_CODE result;
   ASSERT( (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_OPEN) ||
           (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_OPEN_NEXT) );
   
   video_dbg_trace(MP4_EDT_SEEK_BY_FRAME, video_get_current_time());
	result = video_dec_seek_by_frame(frame, callback, KAL_TRUE);
   if (result != MEDIA_STATUS_OK)
   {
      video_dbg_trace(MP4_EDT_SEEK_ERROR, video_get_current_time());
      VIDEO_ASSERT(0);
      return result;
   }
   video_dbg_trace(MP4_EDT_SEEK_BY_FRAME_END, video_get_current_time());

   VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_SEEK;
   return MEDIA_STATUS_OK;
}

void video_editor_set_seek_lisr(void)
{
   kal_uint32 savedMask;
   
   savedMask = SaveAndSetIRQMask();
   video_dbg_trace(MP4_EDT_SET_SEEK_LISR, video_get_current_time());
   
   g_mpeg4_dec_info_ptr->dec_state = MPEG4_DEC_STATE_SEEK;
#ifdef MP4_MOVE_LISR_TO_HISR     
   VISUAL_Register_HISR(VISUAL_MPEG4_SEEK_FIRST_HISR_ID, mpeg4_dec_seek_first_HISR);
#endif       
   VISUAL_Register_HISR(VISUAL_MP4_SEEK_HISR_ID,mpeg4_dec_seek_HISR);
   
#ifdef DRV_MP4_V1
   IRQ_Register_LISR(IRQ_MPEG4_CODE, MPEG4_EDITOR_LISR,"MPEG4Seek");
	IRQSensitivity(IRQ_MPEG4_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_MPEG4_CODE);
#else /*!DRV_MP4_V1*/
   IRQ_Register_LISR(IRQ_MPEG4_DEC_CODE, MPEG4_EDITOR_LISR,"MPEG4Seek");
	IRQSensitivity(IRQ_MPEG4_DEC_CODE,LEVEL_SENSITIVE);
	IRQUnmask(IRQ_MPEG4_DEC_CODE);
#endif   /*DRV_MP4_V1*/
	
	video_dbg_trace(MP4_EDT_SET_SEEK_LISR_END, video_get_current_time());
   RestoreIRQMask(savedMask);
}

void video_editor_start(void)
{
   ASSERT(VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_SEEK);
   
   video_dbg_trace(MP4_EDT_START, video_get_current_time());
   if (VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL)
   {
      //display, encode, then decode, encode, decode
      /*Decoder*/
      VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_START;

      if ((VIDEO_EDITOR_DATA.video_avsync.end_frame_number+1) < g_video_dec_info_ptr->total_frames_in_file)
      {
      	video_dec_clr_buffer(g_video_dec_info_ptr->seek_frame_number, (VIDEO_EDITOR_DATA.video_avsync.end_frame_number+2));
      }
      else if (VIDEO_EDITOR_DATA.video_avsync.end_frame_number < g_video_dec_info_ptr->total_frames_in_file)
		{
			video_dec_clr_buffer(g_video_dec_info_ptr->seek_frame_number, (VIDEO_EDITOR_DATA.video_avsync.end_frame_number+1));
      }
      else
      {
         video_dec_clr_buffer(g_video_dec_info_ptr->seek_frame_number, VIDEO_EDITOR_DATA.video_avsync.end_frame_number);
      }
      video_dec_set_seek_frame((VIDEO_EDITOR_DATA.video_avsync.end_frame_number+1));
      video_dec_put_frame_to_buffer();
   
      video_editor_set_seek_lisr();
      
      if (g_mpeg4_dec_info_ptr->dec_frames_no!= 0)
      {
          g_mpeg4_dec_info_ptr->dec_frames_no--;
   	}
      /*Encoder*/
      g_video_enc_info_ptr->force_I_frame = KAL_TRUE;
      
      MPEG4_EDITOR_IMAGEPATH_START(DRV_Reg32(MP4_DEC_REC_ADDR));
   }
   else  /*YUV 420 path*/
   {
      g_video_enc_info_ptr->force_I_frame = KAL_TRUE;
      MPEG4_EDITOR_IMAGEPATH_START((kal_uint32)VIDEO_EDITOR_DATA.image_yuv420_buffer);
      VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_START;
   }
   video_dbg_trace(MP4_EDT_START_END, video_get_current_time());
}

void video_editor_close(void)
{
   video_dbg_trace(MP4_EDT_CLOSE, video_get_current_time());
   if (VIDEO_EDITOR_DATA.veditor_state != VIEDO_EDITOR_STATE_START)
   {
   	VIDEO_ASSERT(0);
   }

   VIDEO_EDITOR_DATA.call_by_next = KAL_FALSE;
   VIDEO_EDITOR_DATA.video_enc_yuv420_buffer = NULL;
   if (g_video_enc_info_ptr != NULL)
   {
      VIDEO_EDITOR_DATA.total_frames = g_video_enc_info_ptr->total_frames;
      VIDEO_EDITOR_DATA.hisr_total_frames = g_video_enc_info_ptr->hisr_total_frames;
   }
   if ( (g_video_dec_info_ptr != NULL) && (g_video_dec_status.running == KAL_TRUE) )
   	video_dec_close();

   if ( (g_video_enc_info_ptr != NULL) && (g_video_enc_status.running == KAL_TRUE) )
      video_enc_close();
   
   video_dbg_trace(MP4_EDT_CLOSE_END, video_get_current_time());
   VIDEO_EDITOR_DATA.veditor_state = VIEDO_EDITOR_STATE_IDLE;
}

void video_editor_seek_action(void)
{
   if (VIDEO_EDITOR_DATA.veditor_state == VIEDO_EDITOR_STATE_START)
   {
      kal_prompt_trace( MOD_MED_V, "SK:GBCNT=%d", VIDEO_EDITOR_DATA.glb_time_stamp);
   }
   video_seek_action();
}

void video_editor_image_path_open(VIDEO_EDITOR_IMGPATH_STRUCT *image_path_data)
{
#ifdef DRV_MP4_V1
   ASSERT(0);
#else /*!DRV_MP4_V1*/
	video_dbg_trace(MP4_EDT_IMAGE_PATH_OPEN, video_get_current_time());
	
   open_image_data_path(SCENARIO_VIDEO_EDITOR_ID);
   
   if (VIDEO_EDITOR_DATA.image_yuv420_buffer != NULL)
   {
      video_editor_para.video_src_width=VIDEO_EDITOR_DATA.image_yuv420_width;      /*video encode source file size*/ 
      video_editor_para.video_src_height=VIDEO_EDITOR_DATA.image_yuv420_height;
   }
   else
   {
      video_editor_para.video_src_width=VIDEO_EDITOR_DATA.decode_frame_width;      /*video encode source file size*/ 
      video_editor_para.video_src_height=VIDEO_EDITOR_DATA.decode_frame_height;
   }
   video_editor_para.video_tar_width=VIDEO_EDITOR_DATA.encode_frame_width;      /*video encode target file size*/
   video_editor_para.video_tar_height=VIDEO_EDITOR_DATA.encode_frame_height;
   
   video_editor_para.contrast_level=128;   /* IPP contrast gain level */
   video_editor_para.brightness_level=128; /* IPP brightness level */    
   video_editor_para.ipp_para.hsa=0;   
   video_editor_para.ipp_para.cba=0;
   video_editor_para.ipp_para.inv=0;
   video_editor_para.ipp_para.clr=0;
   video_editor_para.ipp_para.gma=0;
   video_editor_para.hw_update_layer=image_path_data->hw_update_layer;
	video_editor_para.lcd_buffer_address=image_path_data->lcd_buffer_address;   /*RGB888 or RGB565, encode frame size*/
   video_editor_para.video_cb=MPEG4_EDITOR_ENC_LISR;
   video_editor_para.effect_cb = image_path_data->effect_cb;
   /*DRV_MP4_V2*/
   config_video_editor(SCENARIO_VIDEO_EDITOR_ID, &video_editor_para,image_path_data->lcd_para);
   VIDEO_EDITOR_DATA.effect_cb = image_path_data->effect_cb;
   VIDEO_EDITOR_DATA.path_type = VIDEO_DEC_IMG_PATH_HW;
   
   video_dbg_trace(MP4_EDT_IMAGE_PATH_OPEN_END, video_get_current_time());
#endif /*DRV_MP4_V1*/
}

void video_editor_image_path_close(void)
{
#ifdef DRV_MP4_V1
   ASSERT(0);
#else /*!DRV_MP4_V1*/
   if (VIDEO_EDITOR_DATA.path_type != VIDEO_DEC_IMG_PATH_HW)
   {
      VIDEO_ASSERT(0);
      video_dbg_trace(MP4_EDT_IMAGE_PATH_CLOSE_END, video_get_current_time());
      return;
   }
   video_dbg_trace(MP4_EDT_IMAGE_PATH_CLOSE, video_get_current_time());
   
   VIDEO_EDITOR_DATA.effect_cb = NULL;
   close_image_data_path(SCENARIO_VIDEO_EDITOR_ID); 
   VIDEO_EDITOR_DATA.path_type = VIDEO_DEC_IMG_PATH_NONE;
   
   video_dbg_trace(MP4_EDT_IMAGE_PATH_CLOSE_END, video_get_current_time());
#endif   /*DRV_MP4_V1*/
}

void VIDEO_EDITOR_ENC_HISR(void)
{
	video_dbg_trace(MP4_EDT_ENC_HISR, video_get_current_time());
   if (VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL) /*video path*/
      mpeg4_dec_seek_lisr_process(MP4_DEC_IRQ_STS_DEC);
}

void MPEG4_EDITOR_ENC_LISR(void)
{
   kal_uint32  time_stamp;
   
   video_dbg_trace(MP4_EDT_ENC_LISR, video_get_current_time());
   //Execute the encode process
   if (VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL)
   {
      time_stamp = VIDEO_EDITOR_DATA.glb_time_stamp;
		
      if (is_section_first)
	   {
	   	VIDEO_EDITOR_DATA.glb_time_stamp = video_editor_avsync_first_frame(VIDEO_EDITOR_DATA.glb_time_stamp);
	   	is_section_first = KAL_FALSE;
	   }
	   else if (g_mpeg4_dec_info_ptr->dec_frames_no == VIDEO_EDITOR_DATA.video_avsync.end_frame_number)
	   {
	   	VIDEO_EDITOR_DATA.glb_time_stamp = video_editor_avsync_end_frame(VIDEO_EDITOR_DATA.glb_time_stamp);
	   }
	   else
	   {
      	VIDEO_EDITOR_DATA.glb_time_stamp += mpeg4_dec_get_curr_frame_duration();
      }
		
      ASSERT(VIDEO_EDITOR_DATA.glb_time_stamp >= time_stamp);
      video_enc_lisr_process((kal_uint32)VIDEO_EDITOR_DATA.video_enc_yuv420_buffer, time_stamp, 0);
   }
   else
   {
      video_enc_lisr_process((kal_uint32)VIDEO_EDITOR_DATA.video_enc_yuv420_buffer, VIDEO_EDITOR_DATA.glb_time_stamp, 0);
   }
}

void MPEG4_EDITOR_START_IMG_PATH(kal_uint32 source_address, kal_bool enable)
{
   ASSERT(VIDEO_EDITOR_DATA.path_type == VIDEO_DEC_IMG_PATH_HW);
   
   if (VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL)
   {
      video_editor_para.source_video_y_buffer_address=(kal_uint32)source_address;
      video_editor_para.source_video_u_buffer_address=(kal_uint32)video_editor_para.source_video_y_buffer_address+VIDEO_EDITOR_DATA.decode_frame_width*VIDEO_EDITOR_DATA.decode_frame_height;
      video_editor_para.source_video_v_buffer_address=(kal_uint32)video_editor_para.source_video_y_buffer_address+((VIDEO_EDITOR_DATA.decode_frame_width*VIDEO_EDITOR_DATA.decode_frame_height*5)>>2);
   }
   else
   {
      video_editor_para.source_video_y_buffer_address=(kal_uint32)source_address;
      video_editor_para.source_video_u_buffer_address=(kal_uint32)video_editor_para.source_video_y_buffer_address+VIDEO_EDITOR_DATA.image_yuv420_width*VIDEO_EDITOR_DATA.image_yuv420_height;
      video_editor_para.source_video_v_buffer_address=(kal_uint32)video_editor_para.source_video_y_buffer_address+((VIDEO_EDITOR_DATA.image_yuv420_width*VIDEO_EDITOR_DATA.image_yuv420_height*5)>>2);
   }

   video_editor_para.target_video_y_buffer_address=(kal_uint32)VIDEO_EDITOR_DATA.video_enc_yuv420_buffer;
   video_editor_para.target_video_u_buffer_address=(kal_uint32)video_editor_para.target_video_y_buffer_address+VIDEO_EDITOR_DATA.encode_frame_width*VIDEO_EDITOR_DATA.encode_frame_height;
   video_editor_para.target_video_v_buffer_address=(kal_uint32)video_editor_para.target_video_y_buffer_address+((VIDEO_EDITOR_DATA.encode_frame_width*VIDEO_EDITOR_DATA.encode_frame_height*5)>>2);
   video_editor_para.video_cb=MPEG4_EDITOR_ENC_LISR;
   start_video_editor_data_path(&video_editor_para, enable);
}

void MPEG4_EDITOR_IMAGEPATH_START(kal_uint32 yuv_start_address)
{
	video_dbg_trace(MP4_EDT_START_IMG_PATH, video_get_current_time());
   if (VIDEO_EDITOR_DATA.effect_cb == NULL)
   {
      MPEG4_EDITOR_START_IMG_PATH(yuv_start_address, KAL_FALSE);
   }
   else
   {
      if (VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL)
      {
         /*Video path*/
         if (  (g_mpeg4_dec_info_ptr->dec_frames_no >= VIDEO_EDITOR_DATA.effect_start_frame) &&
               (g_mpeg4_dec_info_ptr->dec_frames_no <= VIDEO_EDITOR_DATA.effect_end_frame)   )
         {
            MPEG4_EDITOR_START_IMG_PATH(yuv_start_address, KAL_TRUE);
         }
         else
         {
            MPEG4_EDITOR_START_IMG_PATH(yuv_start_address, KAL_FALSE);
         }
      }
      else
      {
         /*Image path*/
         MPEG4_EDITOR_START_IMG_PATH(yuv_start_address, KAL_TRUE);
      }
   }
}

void MPEG4_EDITOR_LHISR(void)
{
   kal_uint32  status;
   kal_uint32  time_stamp;
   
   ASSERT(VIDEO_EDITOR_DATA.image_yuv420_buffer == NULL);
   
   status = DRV_Reg32(MP4_DEC_IRQ_STS);
	
	video_dbg_trace(MP4_EDT_LISR, video_get_current_time());
	video_dbg_trace(MP4_EDT_LISR, status);
	
	video_dbg_trace(MP4_EDT_TIMING, VIDEO_EDITOR_DATA.glb_time_stamp);
	   
   if ( (status & MP4_DEC_IRQ_STS_DEC) ||(g_mpeg4_dec_info_ptr->is_non_coded == KAL_TRUE) )
   {
     if (g_mpeg4_dec_info_ptr->is_non_coded == KAL_FALSE)
     	{
      DRV_WriteReg32(MP4_DEC_IRQ_ACK, MP4_DEC_IRQ_STS_DEC);
      DRV_WriteReg32(MP4_VLC_DMA_COMD, MP4_VLC_DMA_COMD_STOP);
     	}
     MPEG4_EDITOR_IMAGEPATH_START(DRV_Reg32(MP4_DEC_REC_ADDR));
   }
   else
   {
      time_stamp = VIDEO_EDITOR_DATA.glb_time_stamp;
		
      if (is_section_first)
	   {
	   	VIDEO_EDITOR_DATA.glb_time_stamp = video_editor_avsync_first_frame(VIDEO_EDITOR_DATA.glb_time_stamp);
	   	is_section_first = KAL_FALSE;
	   }
	   else if (g_mpeg4_dec_info_ptr->dec_frames_no == VIDEO_EDITOR_DATA.video_avsync.end_frame_number)
	   {
	   	VIDEO_EDITOR_DATA.glb_time_stamp = video_editor_avsync_end_frame(VIDEO_EDITOR_DATA.glb_time_stamp);
	   }
	   else
	   {
      	VIDEO_EDITOR_DATA.glb_time_stamp += mpeg4_dec_get_curr_frame_duration();
      }
		
		if (VIDEO_EDITOR_DATA.glb_time_stamp < time_stamp)
		{
		   VIDEO_ASSERT(0);
		   video_dbg_trace(MP4_EDT_TIMING_ERR, VIDEO_EDITOR_DATA.glb_time_stamp);
		}
      
      mpeg4_dec_seek_lisr_process(status);
      VIDEO_ASSERT(0);
      if (VIDEO_EDITOR_DATA.video_decode_end)
      {
      	VIDEO_EDITOR_DATA.is_force_end = KAL_TRUE;
      	//MPEG4_EDITOR_IMAGEPATH_START(DRV_Reg32(MP4_DEC_REF_ADDR));
      	visual_active_hisr(VISUAL_MP4_SEEK_HISR_ID);
      }
   }
   video_dbg_trace(MP4_EDT_TIMING_END, VIDEO_EDITOR_DATA.glb_time_stamp);
   IRQUnmask(IRQ_MPEG4_DEC_CODE);
}

void MPEG4_EDITOR_LISR(void)
{
	IRQMask(IRQ_MPEG4_DEC_CODE);
	visual_active_hisr(VISUAL_MP4_EDITOR_LISR_HISR_ID);
}

void VIDEO_EDITOR_DEC_DONE_HISR(void)
{
   VIDEO_EDITOR_DATA.video_decode_end = KAL_TRUE;
}

#else /*!__VIDEO_EDITOR__*/
#include    "drv_comm.h"
#endif   /*__VIDEO_EDITOR__*/


