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
 *
 * Filename:
 * ---------
 *    video_fileparse_adap.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the adaption layer of video driver for file parser api
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
 *============================================================================
 ****************************************************************************/
#ifdef MP4_CODEC
#include "drv_comm.h"
#include "med_status.h"
#include "visual_comm.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "l1audio.h"
#include "lcd_if.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"


static MEDIA_STATUS_CODE video_file_read_bitstream_data(kal_uint32 current_pos, kal_uint32 current_size,
                                                        kal_uint32 current_buffer_addr);

/* Read bitstream from file system to buffer
 * @param  current_pos is start position in the file
 * @param  current_size is total bytes that should be read
  * @param  current_buffer_addr is the buffer start address
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
static MEDIA_STATUS_CODE video_file_read_bitstream_data(kal_uint32 current_pos, kal_uint32 current_size,
                                                        kal_uint32 current_buffer_addr)
{
    if (current_size > 512)
    {
        g_video_dec_status.FSAL_STATUS = FSAL_Direct_Seek(g_video_dec_info_ptr->pstFSAL, current_pos);

        if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                kal_prompt_trace(MOD_MED, "FSAL_Direct_Seek Error: %d, %d, %d\n", g_video_dec_status.FSAL_STATUS, current_pos, current_size, current_buffer_addr);
            }
#endif
            g_video_dec_status.FSAL_ERROR_FILE = g_video_dec_info_ptr->pstFSAL;
            return FSAL_ERROR;
        }

        g_video_dec_status.FSAL_STATUS = FSAL_Direct_Read(g_video_dec_info_ptr->pstFSAL,
                                                          (kal_uint8 *)current_buffer_addr,
                                                          current_size);
        if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                kal_prompt_trace(MOD_MED, "FSAL_Direct_Read Error: %d, %d, %d\n", g_video_dec_status.FSAL_STATUS, current_pos, current_size, current_buffer_addr);
            }
#endif

            g_video_dec_status.FSAL_ERROR_FILE = g_video_dec_info_ptr->pstFSAL;
            return FSAL_ERROR;
        }
    }
    else
    {
        g_video_dec_status.FSAL_STATUS = FSAL_Seek(g_video_dec_info_ptr->pstFSAL, current_pos);

        if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                kal_prompt_trace(MOD_MED, "FSAL_Seek Error: %d, %d, %d\n", g_video_dec_status.FSAL_STATUS, current_pos, current_size, current_buffer_addr);
            }
#endif

            g_video_dec_status.FSAL_ERROR_FILE = g_video_dec_info_ptr->pstFSAL;
            return FSAL_ERROR;
        }

        g_video_dec_status.FSAL_STATUS = FSAL_Read(g_video_dec_info_ptr->pstFSAL, (kal_uint8 *)current_buffer_addr,
                                                   current_size);
        if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                kal_prompt_trace(MOD_MED, "FSAL_Read Error: %d, %d, %d\n", g_video_dec_status.FSAL_STATUS, current_pos, current_size, current_buffer_addr);
            }
#endif

            g_video_dec_status.FSAL_ERROR_FILE = g_video_dec_info_ptr->pstFSAL;
            return FSAL_ERROR;
        }
    }

    return MEDIA_STATUS_OK;
}


/* Get sample data from media file to video buffer. It will try to get as mamy data as possible
 *  If not continous, it will try to merge them
 * @param  VIDEO_DEC_FILE_READ_STRUCT structure.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
MEDIA_STATUS_CODE video_file_get_sample_data(VIDEO_DEC_FILE_READ_STRUCT *p_file_info)
{
    kal_uint32 current_pos = 0;
    kal_uint32 current_size = 0;
    kal_uint32 current_buffer_addr = 0;
    kal_uint32 sum = 0;
    kal_uint32 index;
    kal_uint32 result_frame_no;
    kal_uint32 result_frame_no_check;
    kal_uint32 start_read_no;
    MEDIA_STATUS_CODE result;

    p_file_info->result_frame_no = 0;
    p_file_info->result_size = 0;
    result_frame_no =  p_file_info->total_frame_no;
    start_read_no = 0;
    	
    /* get sample size */
    for (index = 0; index < result_frame_no; index++)
    {
        g_video_dec_status.PARSE_STATUS = MP4_GetSampleSize(g_video_dec_info_ptr->pMp4Parser,
                                                            (p_file_info->start_frame_no + index),
                                                            &p_file_info->p_frame_length[index],
                                                            MP4_TRACK_VIDEO);
        if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
        {
#ifdef PGDL_SUPPORT
            if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
               kal_prompt_trace(MOD_MED, "MP4_GetSampleSize Error: %d, %d\n", g_video_dec_status.PARSE_STATUS, p_file_info->start_frame_no, index);
            }
#endif        
        
            VIDEO_ASSERT(0);

            result_frame_no = index;
            g_video_dec_info_ptr->stop_frame_no = p_file_info->start_frame_no + result_frame_no;
            break;
        }
    }

    /* get sample offset */
    result_frame_no_check = result_frame_no;
    g_video_dec_status.PARSE_STATUS =
        MP4_GetSampleOffset_Array(g_video_dec_info_ptr->pMp4Parser,
                                  p_file_info->start_frame_no,
                                  p_file_info->temp_file_offset,
                                  &result_frame_no,
                                  MP4_TRACK_VIDEO);

    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        if((result_frame_no_check==result_frame_no) && (result_frame_no_check!=0))
        {
            /* since it is error, result frame no must be different from original */ 
            EXT_ASSERT(0, result_frame_no_check, 0, 0);
        }
#ifdef PGDL_SUPPORT
        if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
           kal_prompt_trace(MOD_MED, "MP4_GetSampleOffset_Array Error: %d, %d\n", g_video_dec_status.PARSE_STATUS, p_file_info->start_frame_no, p_file_info->temp_file_offset);
        }
#endif

        VIDEO_ASSERT(0);
        g_video_dec_info_ptr->stop_frame_no = p_file_info->start_frame_no + result_frame_no;
    }

    /* set the last one offset as 0 */
    p_file_info->temp_file_offset[result_frame_no] = 0;

    /* calculate smaple sizes and read from file to buffer */
    current_pos = p_file_info->temp_file_offset[0];
    current_size = 0;
    current_buffer_addr = p_file_info->p_frame_buffer_addr[0];
    sum = 0;

    for (index = 0; index < result_frame_no; index++)
    {
        /*Search the max frame data to be prepared to buffer*/
        if ((index + 1) < result_frame_no)
        {
            p_file_info->p_frame_buffer_addr[index + 1] =
                     p_file_info->p_frame_buffer_addr[index]
                    + p_file_info->p_frame_length[index];
        }

        sum += p_file_info->p_frame_length[index];

        if (sum > p_file_info->max_size)
        {
            if(index > 0)
            {
                /* reach frame buffer size limit */
                result = video_file_read_bitstream_data(current_pos, current_size, current_buffer_addr);
           
                if (result != MEDIA_STATUS_OK)
                {
#ifdef PGDL_SUPPORT
                    if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                        kal_prompt_trace(MOD_MED, "video_file_read_bitstream_data Error: %d, %d, %d\n", result, current_pos, current_size, current_buffer_addr);
                    }
#endif                
                    VIDEO_ASSERT(0);
                    return result;
                }
                
                index--;
                p_file_info->result_size += current_size; 
                p_file_info->result_frame_no += (index - start_read_no + 1);
                start_read_no = index + 1;
            }
            break;
        }

        current_size += p_file_info->p_frame_length[index];
        if ((current_pos + current_size) != p_file_info->temp_file_offset[index + 1])
        {
            /* not continous data */
            result = video_file_read_bitstream_data(current_pos, current_size, current_buffer_addr);

            if (result != MEDIA_STATUS_OK)
            {
#ifdef PGDL_SUPPORT
                if (g_video_dec_status.scenario == VIDEO_SCENARIO_PGDL) {
                    kal_prompt_trace(MOD_MED, "video_file_read_bitstream_data Error2: %d, %d, %d\n", result, current_pos, current_size, current_buffer_addr);
                }
#endif
                VIDEO_ASSERT(0);
                return result;
            }

            p_file_info->result_size += current_size;
            p_file_info->result_frame_no += (index - start_read_no + 1);
            start_read_no = index + 1;
            current_buffer_addr = p_file_info->p_frame_buffer_addr[index+1];
            current_pos = p_file_info->temp_file_offset[index + 1];
            current_size = 0;
        }
    }
  
    return MEDIA_STATUS_OK;
}


/* This function get frame duration from media file parser.
* @param  frame_no start frame number
* @param  size How many frames information is needed.
* @param  result the memory that store the result of frame time.
* @return Media status, which is based MEDIA_STATUS_CODE structure.
*/
MEDIA_STATUS_CODE video_file_get_frametime(kal_uint32 frame_no, kal_uint32 size, kal_uint64 *result)
{
    kal_uint32 index;
    kal_uint32 video_duration;
    kal_uint32 min_frame_time;
    MEDIA_STATUS_CODE result_code;

    /* get frame time */
    g_video_dec_status.PARSE_STATUS =
        MP4_GetDecodeTimeDelta_Array(g_video_dec_info_ptr->pMp4Parser, frame_no, result, &size, MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        g_video_dec_info_ptr->stop_frame_no = frame_no + size;
    }

    /* get total duration */
    g_video_dec_status.PARSE_STATUS = MP4_GetMediaDuration(g_video_dec_info_ptr->pMp4Parser, &video_duration,
                                                           MP4_TRACK_VIDEO);
    if (g_video_dec_status.PARSE_STATUS != MP4_PARSER_OK)
    {
        VIDEO_ASSERT(0);
        return MP4_PARSER_ERROR;
    }

    min_frame_time = VIDEO_ANYBASE_TO_ANYBASE(VIDEO_FILE_MIN_FRAME_DURATION, 1000, g_video_dec_info_ptr->video_time_scale);

    /* check each frame time and translate to AV ticks */
    for (index = 0; index < size; index++)
    {
        if ( (result[index] > video_duration) || (result[index] < min_frame_time))
        {
            VIDEO_ASSERT(0);
            /*Tricky to fix error file, modify frame interval*/
            if (index != 0)
            {
            	    result[index] = result[index-1];
            	}
            else
            {
                result_code = video_dec_translate_av_time(min_frame_time, &result[index]);
                if (result_code != MEDIA_STATUS_OK)
                {
                    VIDEO_ASSERT(0);
                    return result_code;
                }  
            }    
            /* previous one has translated, so not translate again */
            continue;
        }

        result_code = video_dec_translate_av_time(result[index], &result[index]);

        if (result_code != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result_code;
        }
        if (result[index] == 0)
        {
            /* After translate, frame time is zero*/
            VIDEO_ASSERT(0);
            /*Tricky to fix error file, modify frame interval*/
            if (index != 0)
            {
                /* share time with previous one */
                result[index] = result[index - 1] / 2;
                result[index - 1] = result[index - 1] - result[index];
            }
            else
            {
                result[index] = 64;
            }
        }
    }

    return MEDIA_STATUS_OK;
}


/* Obtain the decode type from media file
* @param None
* @return DECODE_TYPE_MPEG4 or DECODE_TYPE_H263
*/
DECODE_TYPE video_file_get_decode_type(void)
{
    MP4_Video_Type video_type;

    DECODE_TYPE type;
    video_type = MP4_GetVideoType(g_video_dec_info_ptr->pMp4Parser);

    switch (video_type)
    {
    case MP4_VIDEO_MPEG4:
        type = DECODE_TYPE_MPEG4;
        break;

    case MP4_VIDEO_H263:
        type = DECODE_TYPE_H263;
        break;

    default:
        type = DECODE_TYPE_UNKNOW;
        break;
    }

    return type;
}


/* Obtain VOS data from media file
 * @param  VOS VOS structure.
 * @return Media status, which is based MEDIA_STATUS_CODE structure.
 */
//MEDIA_STATUS_CODE video_file_get_vos_data(MP4VIDEO_VOS_STRUCT **VOS)
MEDIA_STATUS_CODE video_file_get_vos_data(kal_uint8* p_vos, kal_uint32 *p_vos_size)
{
    kal_uint32 vos_pos;

    /* Get VOS information */
    vos_pos = MP4_Video_GetVOSOffset(g_video_dec_info_ptr->pMp4Parser);
    *p_vos_size = MP4_Video_GetVOSSize(g_video_dec_info_ptr->pMp4Parser);

    if ((*p_vos_size) > 100)
    {
        VIDEO_ASSERT(0);

        g_video_dec_status.VIDEO_STATUS = VIDEO_DEC_FATAL_ERROR;
        return VIDEO_ERROR;
    }

    /* Read VOS from file system*/
    g_video_dec_status.FSAL_STATUS = FSAL_Seek(g_video_dec_info_ptr->pstFSAL, vos_pos);
    if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_dec_status.FSAL_ERROR_FILE = g_video_dec_info_ptr->pstFSAL;
        return FSAL_ERROR;
    }

    g_video_dec_status.FSAL_STATUS = FSAL_Read(g_video_dec_info_ptr->pstFSAL, p_vos, *p_vos_size);
    if (g_video_dec_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_dec_status.FSAL_ERROR_FILE = g_video_dec_info_ptr->pstFSAL;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
