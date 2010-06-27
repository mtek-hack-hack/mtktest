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
 *
 * Filename:
 * ---------
 *    video_file_creator.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines the related information of the media file.
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
#ifndef VIDEO_FILE_CREATOR_H
#define VIDEO_FILE_CREATOR_H

#ifndef _RTC_SW_H
#error "Please include rtc_sw.h before video_file_creator.h"
#endif 

#ifndef __MED_STATUS_H__
#error "Please include med_status.h before video_file_creator.h"
#endif 

#define UNUSED_ATOM     0xffffffff

/*Meta file content*/
#define file_create_pos_is_short_header      0x0
#define file_create_pos_average_frame_rate   0x4
#define file_create_pos_time_scale           0x8
#define file_create_pos_frame_width          0xc
#define file_create_pos_frame_heigth         0x10
#define file_create_pos_is_veditor           0x14
#define file_create_pos_temp1                0x18
#define file_create_pos_temp2                0x1c
#define file_create_pos_video_mdatsz_pos     0x20
#define file_create_pos_vos_length           0x24
#define file_create_pos_vos_data             0x28

/// The files for video driver will create Media file
///
typedef struct {
   STFSAL      MEDIA_VIDEO_FILE;
   STFSAL      MEDIA_META_FILE;
   STFSAL      REAL_META_FILE;
}MP4_FILELIST_STRUCT;

/// The necessary information for video file creator
///
typedef struct 
{
   kal_uint32  short_header;
   kal_uint32  create_time;
   ///total_time = frame_number/FRAME_RATE; duartion = total_time*TIME_SCALE
   ///
   kal_uint32  frame_number;
   kal_uint32  frame_width;
   kal_uint32  frame_height;
   kal_uint8   *VOS_ptr;
   kal_uint32  VOS_length;
   kal_uint32  frame_rate;
   kal_uint32  time_scale;
   kal_uint32  temp_video_size;
   kal_uint32  total_duration;   /*Unit: ms*/
}MP4_FILE_CREATE_STRUCT;

/// The ATOM structure
/// 
typedef struct 
{
   kal_uint32 pos;
   kal_uint32 size;
}FC_ATOM_STRUCTURE;

/// The ATOM name
///
typedef enum
{
   moov,
   trak,
   mdia,
   minf,
   stbl,
   stsd,
   mp4v,
   s263,
   stts,
   stsc,
   MAX_ATOM_TYPE_NUMBER
}FC_ATOM_TYPE;
   
typedef struct 
{  
   FC_ATOM_STRUCTURE FC_ATOM[MAX_ATOM_TYPE_NUMBER];
}MP4_FILE_INFO;

#define mp4_crt_write_int(_pos,_data,_file)   \
{\
   g_video_enc_status.FSAL_STATUS = FSAL_Write_UINT (_file, _data);\
   if (g_video_enc_status.FSAL_STATUS!=FSAL_OK)\
   {\
      VIDEO_ASSERT(0);\
      return FSAL_ERROR;\
   }\
   (_pos)+=4;\
}

#define mp4_crt_write_short(_pos,_data,_file)   \
{\
   g_video_enc_status.FSAL_STATUS = FSAL_Write_UINT16(_file, _data);\
   if (g_video_enc_status.FSAL_STATUS!=FSAL_OK)\
   {\
      VIDEO_ASSERT(0);\
      return FSAL_ERROR;\
   }\
   (_pos)+=2;\
}

#define mp4_crt_write_char(_pos,_data,_file)   \
{\
   kal_uint8   out_data = _data;\
   g_video_enc_status.FSAL_STATUS = FSAL_Write_Bytes(_file, (kal_uint8 *)&out_data, 1);\
   if (g_video_enc_status.FSAL_STATUS!=FSAL_OK)\
   {\
      VIDEO_ASSERT(0);\
      return FSAL_ERROR;\
   }\
   (_pos)+=1;\
}

#define mp4_crt_write_char_group(_pos,_data, _len,_file)   \
{\
   g_video_enc_status.FSAL_STATUS = FSAL_Write_Bytes(_file, (kal_uint8 *)_data, _len);\
   if (g_video_enc_status.FSAL_STATUS!=FSAL_OK)\
   {\
      VIDEO_ASSERT(0);\
      return FSAL_ERROR;\
   }\
   (_pos)+=_len;\
}

#define mp4_crt_write(_pos,_data, _len,_file)   \
{\
   g_video_enc_status.FSAL_STATUS = FSAL_Write(_file, _data, _len);\
   if (g_video_enc_status.FSAL_STATUS!=FSAL_OK)\
   {\
      VIDEO_ASSERT(0);\
      return FSAL_ERROR;\
   }\
   (_pos)+=_len;\
}

#define mp4_crt_write_zero_group(_pos,_len,_file)   \
{\
   MEDIA_STATUS_CODE result;\
   FSAL_WRITE_ZERO_GROUP(_file,_len, &result);\
   if (result != MEDIA_STATUS_OK)\
   {\
      VIDEO_ASSERT(0);\
      return result;\
   }\
   (_pos)+=_len;\
}

/*file creator*/
/**
 * This function will generate real meta file that will be attached behind bitstream file.
 * @param  file_creat_struct The necessary information for video file creator engine.
 * @param  real_meta_file The handle of real meta file
 * @param  video_file_info this structure store the atom information
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_generate_META_file(MP4_FILE_CREATE_STRUCT *file_creat_struct, STFSAL *real_meta_file, MP4_FILE_INFO  *video_file_info);
/**
 * This function will obtain the type of bitstream(H.263 or Mpeg4) from meta file.
 * @param  meta_file the handle of meta file.
 * @param  type is short header mode(H.263=1) or not(Mpeg4=0).
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_type(STFSAL *meta_file,kal_uint32 *type);
/**
 * This function will obtain the average frame rate from meta file.
 * @param  meta_file the handle of meta file.
 * @param  frame_rate frame rate.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_framerate(STFSAL *meta_file,kal_uint32 *frame_rate);
/**
 * This function will obtain the time scale(video time unit) from meta file.
 * @param  meta_file the handle of meta file.
 * @param  timescale Video time scale.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_timescale(STFSAL *meta_file,kal_uint32 *timescale);
/**
 * This function will obtain the frame size from meta file.
 * @param  meta_file the handle of meta file.
 * @param  width frame width.
 * @param  height frame height.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_frame_size(STFSAL *meta_file,kal_uint32 *width, kal_uint32 *height);
/**
 * This function will obtain the VOS length from meta file.
 * @param  meta_file the handle of meta file.
 * @param  length VOS length.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_vos_length(STFSAL *meta_file, kal_uint32 *length);
/**
 * This function will obtain the VOS length from meta file.
 * @param  vos the memeory that will store VOS bitstream.
 * @param  length VOS length.
 * @param  meta_file the handle of meta file.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_vos_data(kal_uint8 *vos, kal_uint32 length, STFSAL *meta_file);
/**
 * This function will check whether the information is enough to merge as a media file.
 * @param  video_file the handle of video bitstream file.
 * @param  meta_file the handle of video meta file.
 * @param  audio_file the handle of audio bitstream file.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_check_meta_file_is_enough(STFSAL *video_file, STFSAL *meta_file, STFSAL *audio_file);
/**
 * This function will obtain the position of mdat size in video bitstream file.
 * @param  meta_file the handle of video meta file.
 * @param  pos the position of mdat.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_mdatsz_pos(STFSAL *meta_file, kal_uint32 *pos);
/**
 * This function will obtain frame length information from media file.
 * @param  frame_number The frame number
 * @param  vos_length the VOS length in Meta file
 * @param  result the result of the length.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE mpeg4_get_frame_length_from_meta_file(kal_uint32 frame_number, kal_uint32 vos_length, kal_uint32 *result);
/**
 * This function will translate our RTC info to mpeg4 defined style.
 * @param  rtc_time RTC information
 * @return mpeg4 defined time style from RTC info.
 *
 */
extern kal_uint32 mpeg4_cratetime_translate(t_rtc *rtc_time);
/**
 * This function will obtain the total frame number from meta file.
 * @param  video_file the handle of video bitstream file
 * @param  meta_file the handle of video meta file
 * @param  vos_length The VOS length
 * @param  total_frames Total frame number
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 *
 */
extern MEDIA_STATUS_CODE video_enc_get_totalframes(STFSAL *video_file, STFSAL *meta_file, MP4_FILE_CREATE_STRUCT *file_struct, kal_uint32 *total_frames);
#endif   /*VIDEO_FILE_CREATOR_H*/

