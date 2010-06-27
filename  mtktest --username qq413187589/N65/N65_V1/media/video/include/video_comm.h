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
 *   video_comm.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video common definitions
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
 
#ifndef VIDEO_COMM_H
#define VIDEO_COMM_H

#include "med_status.h"
///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                              decode and encode share difinitaions                     //
//////////////////////////////////////////////////////////////////

/* Maximu VOS bitstream length */
#define MAX_VOS_LENGTH 100

typedef enum 
{
      VIDEO_SCENARIO_DECODE=0,
      VIDEO_SCENARIO_ENCODE,
      VIDEO_SCENARIO_EDITOR,
#ifdef PGDL_SUPPORT
      VIDEO_SCENARIO_PGDL,
#endif
#ifdef STREAM_SUPPORT
      VIDEO_SCENARIO_STREAM,
#endif
      VIDEO_SCENARIO_VCALL,
      VIDEO_TOTAL_SCENARIO
} VIDEO_SCENARIO_ENUM;

/* Mpeg4 VOS information */
typedef struct 
{
   kal_uint8       vos_data[MAX_VOS_LENGTH];
   kal_uint32      size;
}MP4VIDEO_VOS_STRUCT;


///////////////////////////////////////////////////////////////////
//                                                                                                    //
//                                       debug and timing difinitaions                       //
//////////////////////////////////////////////////////////////////

//#define VIDEO_DBG_OPTION_ENABLE

#define MAX_VISIAL_DBG_INFO_SIZE       1024

#define VIDEO_COMMON_TIME_BASE         65536
#define VIDEO_GPT_TIME_BASE            100

#define MAX_VIDEO_ERROR_LINE           8

#ifdef VIDEO_DBG_OPTION_ENABLE
#define VIDEO_ASSERT(_condition) \
   {                             \
      ASSERT(_condition);        \
   }
#else   /*!VIDEO_DBG_OPTION_ENABLE*/
#define VIDEO_ASSERT(_condition) \
   {                             \
      if (!(_condition))         \
      {                          \
         video_assert(__LINE__); \
      }                          \
   }
#endif   /*VIDEO_DBG_OPTION_ENABLE*/

#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)
__inline void video_trace(kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}
#else /* (MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM) */
#define video_trace(...)                                      \
{                                                                                                               \
    if(kal_if_lisr())                                                                 \
    {                                                                                                          \
        video_assert(__LINE__);                                                                 \
    }                                                                                                          \
    else if(kal_if_hisr())                                                                           \
    {                                                                                                          \
        kal_dev_trace(TRACE_GROUP_10, __VA_ARGS__);   \
    }                                                                                                           \
    else                                                                                                      \
    {                                                                                                           \
        kal_trace(TRACE_GROUP_10, __VA_ARGS__);   \
    }                                                                                                          \
}   
#endif /* (MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM) */

#define VIDEO_ANYBASE_TO_MS(_TIME, _TIME_SCALE)                            ((kal_uint64)_TIME*1000/(kal_uint64)_TIME_SCALE)

#define VIDEO_ANYBASE_TO_COMMBASE(_TIME, _TIME_SCALE)                      ((kal_uint64)_TIME*VIDEO_COMMON_TIME_BASE/(kal_uint64)_TIME_SCALE)

#define VIDEO_COMMBASE_TO_ANYBASE(_TIME, _TIME_BASE)                       ((kal_uint64)_TIME*(kal_uint64)_TIME_BASE/VIDEO_COMMON_TIME_BASE)

#define VIDEO_ANYBASE_TO_GPTBASE(_TIME, _TIME_SCALE)                            ((kal_uint64)_TIME*VIDEO_GPT_TIME_BASE/(kal_uint64)_TIME_SCALE)

#define VIDEO_ANYBASE_TO_ANYBASE(_TIME_SRC, _TIME_BASE_SRC, _TIME_BASE_DST)    ((kal_uint64)_TIME_SRC*(kal_uint64)_TIME_BASE_DST/(kal_uint64)_TIME_BASE_SRC)

typedef enum
{
    MP4_ENC_DMA_LISR_ENTRY = 1,
    MP4_ENC_DMA_LISR_ENTRY1,
    MP4_ENC_DMA_LISR_END,
    MP4_ENC_DMA_LISR_END_1,
    MP4_ENC_DMA_LISR_FRAMEQUICK,
    MP4_ENC_HISR_OK = 10,
    MP4_ENC_HISR_DMA,
    MP4_ENC_HISR_END,
    MP4_ENC_ERR_REPT_HISR,
    MP4_DEC_LISR_ENTRY = 20,
    MP4_DEC_LISR_END,
    MP4_ENC_MP4LISR_ENTRY,
    MP4_DEC_HISR_DONE,
    MP4_DEC_HISR_LAST_ONE,
    MP4_DEC_HISR_ENTRY,
    MP4_DEC_HISR_SEND_ILM,
    MP4_DEC_HISR_END,
    MP4_DEC_SEEK_LISR_START = 30,
    MP4_DEC_SEEK_LISR_END,
    MP4_DEC_SEEK_HISR_START,
    MP4_DEC_SEEK_HISR_DONE,
    MP4_DEC_SEEK_HISR_END,
    MP4_DEC_TASK_IND_START = 40,
    MP4_DEC_TASK_IND_END,
    MP4_DEC_TASK_SEEK,
    MP4_DEC_TASK_IMG_HWPATH_OPEN,
    MP4_DEC_TASK_IMG_HWPATH_CLOSE,
    MP4_DEC_TASK_IMG_SWPATH_OPEN,
    MP4_DEC_TASK_IMG_SWPATH_DISP,
    MP4_DEC_TASK_IMG_SWPATH_CLOSE,
    MP4_DEC_SEEK_END_FRAME = 50,
    MP4_DEC_SEEK_ERROR_PARAMETER,
    MP4_ENC_TASK_IND_BITS_START = 60,
    MP4_ENC_TASK_IND_BITS_END,
    MP4_ENC_TASK_IND_META_START,
    MP4_ENC_TASK_IND_META_END,
    MP4_DEC_VIDEO_SEEK,
    MP4_DEC_AUDIO_SEEK,
    MP4_DEC_PLAY,
    MP4_DEC_DISPLAY_OK,
    MP4_DEC_DISPLAY_FAIL,
    MP4_DEC_PREV_DISPLAY_OK,
    MP4_DEC_PREV_DISPLAY_FAIL,
    MP4_MAY_ISR_ERROR,
#ifdef STREAM_SUPPORT        
    STREAM_REORDER_BUFFER_IN_SEQ,
    STREAM_REORDER_BUFFER_DROP_SEQ,
    STREAM_REORDER_BUFFER_OUT_SEQ,
    STREAM_REORDER_BUFFER_FIRST_SEQS,
    STREAM_HANDLE_SEQ,
    STREAM_FRAME_LENGTH,
    STREAM_FRAME_DURATION,
    STREAM_DEC_BUFFER_FILL_FPS,
    STREAM_DEC_BUFFER_FILL_DURATION,
    STREAM_DEC_BUFFER_FILL_INDEX,
    STREAM_DEC_BUFFER_CONSUME_FPS,
    STREAM_DEC_BUFFER_CONSUME_DURATION,
    STREAM_DEC_BUFFER_CONSUME_INDEX,
#endif
#ifdef PGDL_SUPPORT
    PDL_GetAvailDur_GT_0,
    PDL_GetAvailDur_EQ_0,
    PDL_SampleCnt_EQ_0,
    PDL_VidDuration_Error,
    PDL_VidDuration_OK,
    PDL_FrameAvail_VideoEnd,
    PDL_FrameAvail_OK,
    PDL_FrameAvail_READ_EOF,
    PDL_VidTimeScale_Error,
    PDL_GetSampleOffset_Error1,
    PDL_GetSampleOffset_Error2,
    PDL_GetSampleOffset_Error3,
    PDL_SetAudioPlaybackTimeBase,
    PDL_SetAudioPlaybackTimeBase2,
    PDL_SetAudioPlaybackTimeBase3,
    PDL_FSAL_READ_EOF,
    PDL_FSAL_SEEK_EOF,
    PDL_PUT_FRAME_TO_BUFFER_OK,
#endif
#ifdef __VIDEO_EDITOR__
	 MP4_EDT_OPEN,
	 MP4_EDT_OPEN_END,
	 MP4_EDT_OPEN_NEXT,
	 MP4_EDT_OPEN_NEXT_END,
	 MP4_EDT_SEEK_BY_FRAME,
	 MP4_EDT_SEEK_BY_FRAME_END,
	 MP4_EDT_SET_SEEK_LISR,
	 MP4_EDT_SET_SEEK_LISR_END,
	 MP4_EDT_START,
	 MP4_EDT_START_END,
	 MP4_EDT_CLOSE,
	 MP4_EDT_CLOSE_END,
	 MP4_EDT_IMAGE_PATH_OPEN,
	 MP4_EDT_IMAGE_PATH_OPEN_END,
	 MP4_EDT_IMAGE_PATH_CLOSE,
	 MP4_EDT_IMAGE_PATH_CLOSE_END,
	 MP4_EDT_ENC_HISR,
	 MP4_EDT_ENC_LISR,
	 MP4_EDT_START_IMG_PATH,
	 MP4_EDT_LISR,
	 MP4_EDT_PUT_FRAME_TO_BUFFER,
	 MP4_EDT_ENC_STORE_FILE,
	 MP4_EDT_ENC_DUMP_TO_FILE,
	 MP4_EDT_META_STORE_FILE,
	 MP4_EDT_SEEK_ERROR,
	 MP4_EDT_FORCE_END,
	 MP4_EDT_TIMING,
	 MP4_EDT_TIMING_END,
	 MP4_EDT_TIMING_ERR,
	 VISU_EXTMEM_INIT,
    VISU_EXTMEM_GET_BUFFER,
    VISU_EXTMEM_DEINIT,
    VISU_INTMEM_INIT,
    VISU_INTMEM_GET_BUFFER,
    VISU_INTMEM_DEINIT,
#endif 	/*__VIDEO_EDITOR__*/
#ifdef __3G_VIDEO_CALL__
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
    VISUAL_DBG_MAX_ID
}VIDEO_DBG_ID;

typedef struct
{
    VIDEO_DBG_ID tag;
    kal_uint32 time;
} VIDEO_DBG_DATA;

typedef struct
{
    VIDEO_DBG_DATA dbg_data[MAX_VISIAL_DBG_INFO_SIZE];
    kal_uint16 dbg_data_idx;
} VIDEO_DBG_STRUCT;


 /* Mpeg4 reset function for V1 series.
 * @param None
 * @return None                                                        
 */
extern void mp4_reset(void);

 /* Mpeg4 decode reset function.
 * @param None
 * @return None                                                        
 */
extern void mpeg4_dec_reset(void);

 /* Mpeg4 encode reset function.
 * @param None
 * @return None                                                        
 */
extern void mpeg4_enc_reset(void);

 /* Mpeg4 core reset function for V2 series.
 * @param None
 * @return None                                                        
 */
extern void mpeg4_core_reset(void);

 /* Mpeg4 wait done function for V1 series.
 * @param None
 * @return None                                                        
 */
extern void mpeg4_wait_done(void);

 /* Mpeg4 decode wait done function.
 * @param None
 * @return None                                                        
 */
extern void mpeg4_dec_wait_done(void);

 /* Mpeg4 encode wait done function.
 * @param None
 * @return None                                                        
 */
extern void mpeg4_enc_wait_done(void);

 /* Mpeg4 check hardware complete function.
 * @param None
 * @return None                                                        
 */
extern kal_bool mpeg4_dec_check_complete(void);

 /* Get current time function. (32K resolution)
 * @param None
 * @return None                                                        
 */
extern kal_uint32 video_get_current_time(void);

 /* Get duration time. (32K resolution)
 * @param previous_time. The previous time get from 32K ticks
 * @param current_time. The current time get from 32K ticks
 * @return time difference. (calculate limit)                                                       
 */
extern kal_uint32 video_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);

/* Get duration time. (ms)
 * @param previous_time. The previous time get from 32K ticks
 * @return time difference from previous to current time. (calculate limit, and translate to ms)                                                       
 */
extern kal_uint32 video_get_duration_ms(kal_uint32 previous_time);

/* This function will obtain the current video status.
 * @param None.
 * @return Media status, which is based MED_STATUS structure.                                                
 */
extern MED_STATUS VIDEO_GetLastError(void);

 /* Video assert debug function.
 * @param   line      file line number
 * @return  None                                         
 */
extern void video_assert(kal_uint32 line);

 /* This function add debug trace information to memory
 * @param  index  VIDEO debug id.
 * @param  time   Time stamp.
 * @return None
 */
extern void video_dbg_trace(VIDEO_DBG_ID index, kal_uint32 time);

/* This function will obtain the debug information of video driver.
 * @param  data1  video debug information1
 * @param  data2  video debug information2
 * @param  data3  video debug information3
 * @param  data4  video debug information4
 * @param  data_index  video debug information index
 * @return None
 */
extern void VIDEO_DbgInfo(kal_uint32 * data1, kal_uint32 * data2, kal_uint32 * data3, kal_uint32 * data4,
                          kal_uint32 * data_index);

#endif /*VIDEO_COMM_H*/
