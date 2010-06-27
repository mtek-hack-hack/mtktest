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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef VIDEO_EDITOR_H
#define VIDEO_EDITOR_H

#include "video_editor_glb.h"

#define MAX_VIDEO_EDITOR_SECTION    2000
/// if the duration < VIDEO_EDITOR_DROP_DURATION(ms), this frame will be drop
///
#define VIDEO_EDITOR_DROP_DURATION           10
/// Maximum video editor frame width
///
#define VIDEO_EDITOR_MAX_FRAME_WIDTH         176
/// Maximum video editor frame height
///
#define VIDEO_EDITOR_MAX_FRAME_HEIGHT        144
#define VIDEO_EDITOR_ENC_BUFFER_SIZE    (VIDEO_EDITOR_MAX_FRAME_WIDTH*VIDEO_EDITOR_MAX_FRAME_HEIGHT+128)
///  Decode bitstream buffer size per decode buffer
///
#define VIDEO_EDITOR_DEC_BUFFER_SIZE                (DEC_MAX_FRAME_WIDTH*DEC_MAX_FRAME_HEIGHT*3)
#define VIDEO_EDITOR_DEC_BUFFER_COUNT             3

typedef enum {
   VIEDO_EDITOR_TYPE_SINGLE_FILE=0xa5,
   VIEDO_EDITOR_TYPE_MULTI_FILE
} VIEDO_EDITOR_TYPE;

typedef enum   {
   /// Buffer empty event, upper layer should fill up the buffer
   ///
   VIDEO_EDITOR_DEC_EVENT_BUFFER_EMPTY=100,
   /// video seek handler.
   ///
   VIDEO_EDITOR_DEC_DRV_SEEK_ACTION,
   /// No Video track event
   ///
   VIDEO_EDITOR_DEC_EVENT_NO_TRACK,
   /// Seek ready event
   ///
   VIDEO_EDITOR_DEC_EVENT_SEEK_DONE,

   /// VIDEO bitstream buffer is available, and wait MED task move these data 
   /// to video bitstream file
   VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL,
   /// VIDEO meta buffer is available, and wait MED task move these data to video meta file
   ///
   VIDEO_EDITOR_ENC_EVENT_META_BUFFER_AVAIL,
   /// Count file size for file size limit
   ///
   VIDEO_EDITOR_ENC_EVENT_COUNT_FILE_SIZE,
   /// Someting wrong in video driver, upper layer should call function 
   /// to obtain error casue.
   VIDEO_EDITOR_EVENT_FAIL,
   /// Viedo editor complete event
   ///
   VIDEO_EDITOR_EVENT_COMPLETE,
   /// Max event number
   ///
   VIDEO_EDITOR_MAX_EVENT
} VIDEO_EDITOR_EVENT;

typedef struct 
{
   /*video editor time base = VIDEO_COMMON_TIME_BASE*/
   /*Encoder*/
   kal_bool                      short_header;
   kal_uint32                    bit_rate;
   kal_uint16                    encode_frame_width;
   kal_uint16                    encode_frame_height;
   //VIEDO_EDITOR_TYPE             editor_type;
   
   /*For image*/
   kal_uint8                     *image_yuv420_buffer;
   kal_uint16                    image_yuv420_width;
   kal_uint16                    image_yuv420_height;
   /*for video decoder*/
   STMp4Parser                   *pstVIDParser;
   STFSAL                        *pstVIDFSAL;
   STMp4Parser                   *pstAUDParser;
   STFSAL                        *pstAUDFSAL;
   /*all*/
   kal_bool                      need_avsync;
   void                          (*call_back)(kal_uint8 event);
   kal_uint32                    video_start_time;
   kal_uint32                    audio_start_time;
   kal_uint32                    av_duration;
   /*effect*/
   kal_uint32                    effect_start_time;
   kal_uint32                    effect_duration;
}VIDEO_EDITOR_OPEN_STRUCT;

typedef struct 
{
   /*For image*/
   kal_uint8                     *image_yuv420_buffer;
   kal_uint16                    image_yuv420_width;
   kal_uint16                    image_yuv420_height;
   /*for video decoder*/
   STMp4Parser                   *pstVIDParser;
   STFSAL                        *pstVIDFSAL;
   STMp4Parser                   *pstAUDParser;
   STFSAL                        *pstAUDFSAL;
   kal_bool							 	is_new_video;
   /*video editor time base = VIDEO_COMMON_TIME_BASE*/
   kal_bool                      need_avsync;
   void                          (*call_back)(kal_uint8 event);
   kal_uint32                    video_start_time;
   kal_uint32                    audio_start_time;
   kal_uint32                    av_duration;
   /*effect*/
   kal_uint32                    effect_start_time;
   kal_uint32                    effect_duration;
}VIDEO_EDITOR_OPEN_NEXT_STRUCT;

typedef struct
{
   /*IPP*/
   kal_uint32                          hw_update_layer;
   kal_uint32                          lcd_buffer_address; /*RGB888, and size is depended on MMI setup*/
   lcd_frame_update_to_mem_struct      *lcd_para;
   //VIDEO_DECODE_EFFECT_ENUM            effect;
   void                                (*effect_cb)(void);
} VIDEO_EDITOR_IMGPATH_STRUCT;

extern void MPEG4_EDITOR_LISR(void);
extern void VIDEO_EDITOR_DEC_DONE_HISR(void);
extern void video_editor_image_path_open(VIDEO_EDITOR_IMGPATH_STRUCT *image_path_data);
extern void video_editor_start(void);
extern MEDIA_STATUS_CODE video_editor_open(VIDEO_EDITOR_OPEN_STRUCT *veditor_struct, VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, kal_uint32 *current_video_frame_no);
extern MEDIA_STATUS_CODE video_editor_open_next(VIDEO_EDITOR_OPEN_NEXT_STRUCT *veditor_struct, VEDITOR_AVSYNC_AUDIO_STRUCT *audio_avsync, kal_uint32 *current_video_frame_no);
extern MEDIA_STATUS_CODE video_editor_seek_by_frame(kal_uint32 frame, void (*callback)(kal_uint8 event));
extern MEDIA_STATUS_CODE video_editor_dec_put_frame_to_buffer(void);
extern void video_editor_image_path_close(void);
extern void video_editor_close(void);
extern void video_editor_seek_action(void);
extern MEDIA_STATUS_CODE video_editor_enc_store_file(kal_uint32 max_size, kal_uint32 *real_store_size);
extern MEDIA_STATUS_CODE video_editor_meta_store_file(kal_uint32 max_size, kal_uint32 *real_store_size);

#endif   /*VIDEO_EDITOR_H*/


