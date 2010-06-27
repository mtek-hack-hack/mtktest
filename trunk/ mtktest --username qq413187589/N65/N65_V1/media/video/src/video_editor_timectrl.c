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
 *    video_editor_timectrl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines time control interface of video editor. 
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__VIDEO_EDITOR__)
#include    "FSAL.h"
#include    "MP4_Parser.h"
#include    "drv_comm.h"
#include    "visual_comm.h"
#include    "rtc_sw.h"
#include    "lcd_if.h"
#include    "bmd.h"
#include    "video_file_creator.h"
#include    "video_dec_glb.h"
#include    "video_enc_glb.h"
#include    "video_glb.h"
#include    "video_editor.h"

/*Audio adaption layer*/
MEDIA_STATUS_CODE video_editor_per_audio_frame_duration(kal_uint32 *audio_per_frame_duration /*Unit:comm_time_scale*/)
{
   *audio_per_frame_duration = 0;
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_av_duration_info(kal_uint32 audio_start_time,
                                                kal_uint32 av_duration,
                                                kal_uint32 *real_av_duration, /*Unit: common_base*/
                                                kal_uint32 *real_audio_start_time, /*Unit: common_base*/
                                                kal_uint32 *real_audio_end_time, /*Unit: common_base*/
                                                VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync)
{
   MEDIA_STATUS_CODE    result;
   kal_uint32           audio_frame_duration;
   kal_uint32           audio_frame_no;
   kal_uint64           temp_starttime_audio_scale;
   kal_uint64           temp_endtime_audio_scale;

   result = video_editor_per_audio_frame_duration(&audio_frame_duration);		/*Jensen*/
   
   /*Audio*/
   g_video_dec_status.PARSE_STATUS =
         MP4_Audio_TimeToSampleNo(VIDEO_EDITOR_DATA.pstAUDParser,
                     audio_start_time,   /*Unit: ms*/
                     &audio_frame_no);
   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
      VIDEO_ASSERT(0);
      return MP4_PARSER_ERROR;
   }
   audio_avsync->audio_start_frame = audio_frame_no;
   VIDEO_EDITOR_DATA.audio_avsync.audio_start_frame = audio_avsync->audio_start_frame;

   g_video_dec_status.PARSE_STATUS =
         MP4_Audio_TimeToSampleNo(VIDEO_EDITOR_DATA.pstAUDParser,
                     (audio_start_time+av_duration),   /*Unit: ms*/
                     &audio_frame_no);
   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
      VIDEO_ASSERT(0);
      return MP4_PARSER_ERROR;
   }
   
   if (audio_avsync->audio_start_frame >= audio_frame_no)
   {
      VIDEO_ASSERT(0);
      return VEDIT_AUDIO_TIME_ERROR;
   }

   if (audio_frame_no != 0)
      audio_avsync->audio_end_frame = audio_frame_no-1;
   else
      audio_avsync->audio_end_frame = audio_frame_no;
   VIDEO_EDITOR_DATA.audio_avsync.audio_end_frame = audio_avsync->audio_end_frame;      

   g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(VIDEO_EDITOR_DATA.pstAUDParser,
                                                       audio_avsync->audio_start_frame,
                                                       &temp_starttime_audio_scale,
                                                       MP4_TRACK_AUDIO);
   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
      if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_SAMPLE)
   	{
   	   VIDEO_ASSERT(0);
   		return MP4_PARSER_ERROR;
   	}
   }
   
   g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(VIDEO_EDITOR_DATA.pstAUDParser,
                                                       (audio_avsync->audio_end_frame+1),
                                                       &temp_endtime_audio_scale,
                                                       MP4_TRACK_AUDIO);
   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
      if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_SAMPLE)
   	{
   	   VIDEO_ASSERT(0);
   		return MP4_PARSER_ERROR;
   	}
   }
   
   *real_audio_start_time = VIDEO_ANYBASE_TO_COMMBASE(temp_starttime_audio_scale, VIDEO_EDITOR_DATA.audio_time_scale);
   *real_audio_end_time = VIDEO_ANYBASE_TO_COMMBASE(temp_endtime_audio_scale, VIDEO_EDITOR_DATA.audio_time_scale);
   *real_av_duration = VIDEO_ANYBASE_TO_COMMBASE((temp_endtime_audio_scale-temp_starttime_audio_scale), VIDEO_EDITOR_DATA.audio_time_scale);

   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_avsync_video_start_info(kal_uint32 ref_time,   /*Unit: COMM time scale*/
                                                       kal_uint32 *current_video_frame_no)
{
   kal_uint32           video_frame_no;
   kal_uint64           temp_time_video_scale;
   kal_uint32           start_time_video_scale = VIDEO_COMMBASE_TO_ANYBASE(ref_time, VIDEO_EDITOR_DATA.video_time_scale);
   g_video_dec_status.PARSE_STATUS = MP4_GetSampleNumber(VIDEO_EDITOR_DATA.pstVIDParser,
                                             &video_frame_no,
                                             start_time_video_scale,
                                             MP4_TRACK_VIDEO );
   if	(g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
   	if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_SAMPLE)
   	{
   	   VIDEO_ASSERT(0);
   		return MP4_PARSER_ERROR;
   	}
   }
   
   if ((video_frame_no+1) < g_video_dec_info_ptr->total_frames_in_file)
   {
      g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(VIDEO_EDITOR_DATA.pstVIDParser,
                                             (video_frame_no+1),
                                             &temp_time_video_scale,
                                             MP4_TRACK_VIDEO);
      if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
      {
         VIDEO_ASSERT(0);
         return MP4_PARSER_ERROR;
      }
      kal_prompt_trace( MOD_MED_V, "DT=%d,STV=%d", VIDEO_ANYBASE_TO_MS(temp_time_video_scale, VIDEO_EDITOR_DATA.video_time_scale), start_time_video_scale );
   }
   else
   {
   	temp_time_video_scale = VIDEO_COMMBASE_TO_ANYBASE(g_video_dec_info_ptr->video_duration, VIDEO_EDITOR_DATA.video_time_scale);
      kal_prompt_trace( MOD_MED_V, "DTF=%d", VIDEO_ANYBASE_TO_MS(temp_time_video_scale, VIDEO_EDITOR_DATA.video_time_scale));
   	VIDEO_ASSERT(0);
   }
   
   ASSERT(temp_time_video_scale >= start_time_video_scale);
   /*AV sync info: start_time*/
   VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin = VIDEO_ANYBASE_TO_COMMBASE((temp_time_video_scale-start_time_video_scale), VIDEO_EDITOR_DATA.video_time_scale);

   if ( VIDEO_EDITOR_DATA.video_avsync.delta_start_frame_duratoin < VIDEO_ANYBASE_TO_COMMBASE(VIDEO_EDITOR_DROP_DURATION, 1000) )
   {
      VIDEO_EDITOR_DATA.video_avsync.start_frame_number = (video_frame_no+1);
      VIDEO_EDITOR_DATA.video_avsync.start_frame_discard = KAL_TRUE;
      *current_video_frame_no = (video_frame_no+2);
       kal_prompt_trace( MOD_MED_V, "VST: SF=%d,CF=%d", VIDEO_EDITOR_DATA.video_avsync.start_frame_number, *current_video_frame_no);
   }
   else
   {
      VIDEO_EDITOR_DATA.video_avsync.start_frame_number = video_frame_no;
      VIDEO_EDITOR_DATA.video_avsync.start_frame_discard = KAL_FALSE;
      *current_video_frame_no = (video_frame_no+1);
      kal_prompt_trace( MOD_MED_V, "VSF:SF=%d,CF=%d", VIDEO_EDITOR_DATA.video_avsync.start_frame_number, *current_video_frame_no);      
   }
   
   if (*current_video_frame_no > g_video_dec_info_ptr->total_frames_in_file)
   {
   	*current_video_frame_no = g_video_dec_info_ptr->total_frames_in_file;
   	kal_prompt_trace( MOD_MED_V, "BC:CF=%d", *current_video_frame_no);      
   }
	if (VIDEO_EDITOR_DATA.video_avsync.start_frame_number > (g_video_dec_info_ptr->total_frames_in_file-1))
   {
		VIDEO_EDITOR_DATA.video_avsync.start_frame_number = (g_video_dec_info_ptr->total_frames_in_file-1);
		kal_prompt_trace( MOD_MED_V, "BC2:SF=%d", VIDEO_EDITOR_DATA.video_avsync.start_frame_number); 
   }
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_avsync_start_info(VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, 
                                                 kal_uint32       real_audio_start_time,
                                                 kal_uint32       *current_video_frame_no)
{                                                                        
   /*Only audio_avsync->audio_start_frame, and video AV sync start info*/
   MEDIA_STATUS_CODE    result;

   /*Vidio*/
   result = video_editor_avsync_video_start_info(real_audio_start_time, 
                                                 current_video_frame_no);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }

   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_avsync_video_end_info(kal_uint32 ref_time, /*Unit: COMM time scale*/
                                                     kal_uint32 addition_time)/*Unit: COMM time scale*/
{
   kal_uint32           video_frame_no;
   kal_uint64           temp_time_video_scale;
   kal_uint32           video_time;
   kal_uint32           end_time_video_scale = VIDEO_COMMBASE_TO_ANYBASE( ref_time, VIDEO_EDITOR_DATA.video_time_scale );;
   
   g_video_dec_status.PARSE_STATUS = MP4_GetSampleNumber(VIDEO_EDITOR_DATA.pstVIDParser,
                                             &video_frame_no,
                                             end_time_video_scale,
                                             MP4_TRACK_VIDEO );
   if	(g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
   	if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_SAMPLE)
   	{
   	   VIDEO_ASSERT(0);
   		return MP4_PARSER_ERROR;
   	}
   }

   if (g_video_dec_status.PARSE_STATUS == MP4_PARSER_NO_SUCH_SAMPLE)
   {
      video_frame_no = g_video_dec_info_ptr->total_frames_in_file-1;
   }
   
   g_video_dec_status.PARSE_STATUS = MP4_GetDecodeTime(VIDEO_EDITOR_DATA.pstVIDParser,
                                             video_frame_no,
                                             &temp_time_video_scale,
                                             MP4_TRACK_VIDEO);
   if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {        
   	VIDEO_ASSERT(0);
   	return MP4_PARSER_ERROR;
   }
   
         kal_prompt_trace( MOD_MED_V, "DET=%d,SETV=%d", VIDEO_ANYBASE_TO_MS(temp_time_video_scale, VIDEO_EDITOR_DATA.video_time_scale), VIDEO_ANYBASE_TO_MS(end_time_video_scale, VIDEO_EDITOR_DATA.video_time_scale) );
         
   video_time = VIDEO_ANYBASE_TO_COMMBASE(temp_time_video_scale, VIDEO_EDITOR_DATA.video_time_scale);
   ASSERT(video_time <= ref_time);
   kal_prompt_trace( MOD_MED_V, "XREF=%d,XV=%d,XA=%d", ref_time, video_time, addition_time );
   /*AV sync info: end_time*/
   VIDEO_EDITOR_DATA.video_avsync.delta_end_frame_duratoin = (ref_time-video_time+addition_time);
   kal_prompt_trace( MOD_MED_V, "EDU=%d", VIDEO_EDITOR_DATA.video_avsync.delta_end_frame_duratoin);
   if ( VIDEO_EDITOR_DATA.video_avsync.delta_end_frame_duratoin < VIDEO_ANYBASE_TO_COMMBASE(VIDEO_EDITOR_DROP_DURATION, 1000) )
   {
   	if (video_frame_no != 0)
   	{
      	VIDEO_EDITOR_DATA.video_avsync.end_frame_number = video_frame_no-1;
   	      kal_prompt_trace( MOD_MED_V, "VET:EF=%d", VIDEO_EDITOR_DATA.video_avsync.end_frame_number);
   	}
      else
      {
      	VIDEO_ASSERT(0);
      	VIDEO_EDITOR_DATA.video_avsync.end_frame_number = 0;
   	      kal_prompt_trace( MOD_MED_V, "ASS!EF=%d", VIDEO_EDITOR_DATA.video_avsync.end_frame_number);
      }
      VIDEO_EDITOR_DATA.video_avsync.end_frame_discard = KAL_TRUE;
   }
   else
   {
      VIDEO_EDITOR_DATA.video_avsync.end_frame_number = video_frame_no;
      VIDEO_EDITOR_DATA.video_avsync.end_frame_discard = KAL_FALSE;
      kal_prompt_trace( MOD_MED_V, "VEF:EF=%d", VIDEO_EDITOR_DATA.video_avsync.end_frame_number);
   }
   return MEDIA_STATUS_OK;
}
                                           
MEDIA_STATUS_CODE video_editor_avsync_end_info(VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync,
                                               kal_uint32 real_end_time)
{
   /*Only audio_avsync->audio_end_frame, and video AV sync end info*/
   MEDIA_STATUS_CODE    result;
   kal_uint32           additional_time;

   /*Vidio*/
   result = video_editor_per_audio_frame_duration(&additional_time); /*Jensen*/
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   result = video_editor_avsync_video_end_info(real_end_time, additional_time);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_non_avsync_info(kal_uint32 video_start_time /*Unit: ms*/,
                                               kal_uint32 av_duration /*Unit: COMM time scale*/,
                                               VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync,
                                               kal_uint32 *current_video_frame_no)
{
   MEDIA_STATUS_CODE    result;
   kal_uint32           temp_starttime_comm_scale;
   kal_uint32           temp_endtime_comm_scale;
   kal_uint32           additional_time = 0;
   
   temp_starttime_comm_scale = VIDEO_ANYBASE_TO_COMMBASE(video_start_time, 1000);
   /*Video*/
   result = video_editor_avsync_video_start_info(temp_starttime_comm_scale, 
                                                 current_video_frame_no);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }

   temp_endtime_comm_scale = temp_starttime_comm_scale+av_duration;
   result = video_editor_avsync_video_end_info(temp_endtime_comm_scale, additional_time);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_avsync_info(kal_bool   av_sync, 
                                           kal_uint32 video_start_time/*Unit: ms*/,
                                           kal_uint32 audio_start_time/*Unit: ms*/,
                                           kal_uint32 av_duration /*Unit: ms*/,
                                           VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, 
                                           kal_uint32 *current_video_frame_no)
{
   MEDIA_STATUS_CODE    result;
   kal_uint32           audio_frame_duration;
   kal_uint32 		      real_av_duration;
   kal_uint32           real_audio_start_time;
   kal_uint32           real_audio_end_time;
   
   result = video_editor_per_audio_frame_duration(&audio_frame_duration);		/*Jensen*/

   /*Obtain AV sync info*/
   result = video_editor_av_duration_info(audio_start_time,
                                          av_duration,
                                          &real_av_duration,
                                          &real_audio_start_time,
                                          &real_audio_end_time,
                                          audio_avsync);
   if (result != MEDIA_STATUS_OK)
   {
      VIDEO_ASSERT(0);
      return result;
   }
   
   kal_prompt_trace( MOD_MED_V, "AV:RAS=%d,RAE=%d,Rav_T=%d", 
   						(kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(real_audio_start_time, 1000), 
   						(kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(real_audio_end_time, 1000), 
   						(kal_uint32)VIDEO_COMMBASE_TO_ANYBASE(real_av_duration, 1000) );

   if(av_sync)
   {
      ASSERT(video_start_time == audio_start_time);

      /*Start time*/
      result = video_editor_avsync_start_info(audio_avsync, real_audio_start_time, current_video_frame_no);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
      /*End time*/
      result = video_editor_avsync_end_info(audio_avsync, real_audio_end_time);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
   }
   else
   {
      result = video_editor_non_avsync_info(video_start_time, 
                                            real_av_duration, 
                                            audio_avsync,
                                            current_video_frame_no);
      if (result != MEDIA_STATUS_OK)
      {
         VIDEO_ASSERT(0);
         return result;
      }
   }
   return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_editor_effect_duration(kal_uint32 effect_start_time, /*Unit: ms*/
                                               kal_uint32 effect_duration, /*Unit: ms*/
                                               kal_uint32 *effect_start_frame,
                                               kal_uint32 *effect_end_frame)
{
   kal_uint32           time_video_scale;
   
   time_video_scale = VIDEO_ANYBASE_TO_ANYBASE(effect_start_time, 1000, VIDEO_EDITOR_DATA.video_time_scale);
   g_video_dec_status.PARSE_STATUS = MP4_GetSampleNumber(VIDEO_EDITOR_DATA.pstVIDParser,
                                             effect_start_frame,
                                             time_video_scale,
                                             MP4_TRACK_VIDEO );
   if	(g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
   	if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_SAMPLE)
   	{
   	   VIDEO_ASSERT(0);
   		return MP4_PARSER_ERROR;
   	}
   }
   
   time_video_scale = VIDEO_ANYBASE_TO_ANYBASE((effect_start_time+effect_duration), 1000, VIDEO_EDITOR_DATA.video_time_scale);
   g_video_dec_status.PARSE_STATUS = MP4_GetSampleNumber(VIDEO_EDITOR_DATA.pstVIDParser,
                                             effect_end_frame,
                                             time_video_scale,
                                             MP4_TRACK_VIDEO );
   if	(g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
   {
   	if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_NO_SUCH_SAMPLE)
   	{
   	   VIDEO_ASSERT(0);
   		return MP4_PARSER_ERROR;
   	}
   }
   return MEDIA_STATUS_OK;
}

#else /*!__VIDEO_EDITOR__*/
#include    "drv_comm.h"
#endif   /*__VIDEO_EDITOR__*/

