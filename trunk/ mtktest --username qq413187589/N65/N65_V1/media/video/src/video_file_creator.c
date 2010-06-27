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
 *    video_file_creator.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the interface to create media file(video part and common part).
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

extern MP4_FILELIST_STRUCT mp4_files;
kal_uint32  is_vedt;

const kal_uint16 month_day[12] =
{
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

void FSAL_WRITE_ZERO_GROUP(STFSAL * inp_file, kal_uint32 num, MEDIA_STATUS_CODE * result)
{
    kal_uint32 i;

    kal_uint8 data = 0;

    *result = MEDIA_STATUS_OK;

    for (i = 0; i < num; i++)
    {
        g_video_enc_status.FSAL_STATUS = FSAL_Write(inp_file, &data, 1);
        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = inp_file;
            *result = FSAL_ERROR;
            return;
        }
    }
}

kal_uint32 mpeg4_cratetime_translate(t_rtc * rtc_time)
{
    kal_uint32 addition_day;

    kal_uint32 time;
    addition_day = (((rtc_time->rtc_year - 1) - 1904) / 4) + 1;
    time = (((2000 + rtc_time->rtc_year - 1904) * 365 * 24 * 60* 60) + 
                 (month_day[rtc_time->rtc_mon - 1] + rtc_time->rtc_day + addition_day) * 24 * 60 * 60 + 
                 ((rtc_time->rtc_hour * 60 + rtc_time->rtc_min) * 60) + 
                  rtc_time->rtc_sec);

    if ((rtc_time->rtc_year & 0x03 == 0) && (rtc_time->rtc_mon > 2))
    {
        time += 24 * 60 * 60;
    }

    return time;
}

MEDIA_STATUS_CODE pre_defined_hr(kal_uint32 * mp4_file_pos, STFSAL * mp4_file)
{
    mp4_crt_write_int(*mp4_file_pos, 0x00010000, &mp4_files.REAL_META_FILE);

    mp4_crt_write_zero_group(*mp4_file_pos, 12, &mp4_files.REAL_META_FILE);
    mp4_crt_write_int(*mp4_file_pos, 0x00010000, &mp4_files.REAL_META_FILE);
    mp4_crt_write_zero_group(*mp4_file_pos, 12, &mp4_files.REAL_META_FILE);
    mp4_crt_write_int(*mp4_file_pos, 0x40000000, &mp4_files.REAL_META_FILE);
    return MEDIA_STATUS_OK;
}

kal_uint32 video_evaluate_real_meta_file_size(kal_bool short_header_mode)
{
    kal_uint32 file_size;

    kal_uint32 frame_no = g_video_enc_info_ptr->hisr_total_frames;

    if (short_header_mode) /*H.263*/
    {
        file_size = 564 + 
                    16 + (frame_no * 8) + 
                    20 + (frame_no * 4) + 
                    ((frame_no / g_video_enc_info_ptr->FRAME_RATE) * 4) + 16 + 
                    ((frame_no / Video_Enc_IntraPeriod) * 4) + 16;
    }
    else /*Mp4*/
    {
        file_size = 489 + 
                    151 + g_video_enc_info_ptr->VOS.size + 
                    16 + (frame_no * 8) + 
                    20 + (frame_no * 4) + 
                    (frame_no / g_video_enc_info_ptr->FRAME_RATE) * 4 + 16 + 
                    (frame_no / Video_Enc_IntraPeriod) * 4 + 16;
    }

    return file_size;
}

MEDIA_STATUS_CODE video_enc_get_is_vedt(STFSAL * meta_file, kal_uint32 * is_vedt_value)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_is_veditor);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)is_vedt_value, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_totalframes(STFSAL * video_file, STFSAL * meta_file, MP4_FILE_CREATE_STRUCT * file_struct, kal_uint32 * total_frames)
{
    kal_uint32 file_size;

    kal_uint32 video_file_size;
    kal_uint32 index;
    kal_uint32 total_frame_size = 0;
    kal_uint32 length_temp;
    MEDIA_STATUS_CODE result;
    kal_uint32 temp;
    kal_uint32 vos_length = file_struct->VOS_length;

    if (file_struct->temp_video_size == 0)
    {
        g_video_enc_status.FSAL_STATUS = FSAL_GetFileSize(video_file, &video_file_size);
        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = video_file;
            return FSAL_ERROR;
        }
    }
    else
    {
        video_file_size = file_struct->temp_video_size;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_GetFileSize(meta_file, &file_size);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    file_size = file_size - ((vos_length + file_create_pos_vos_data + 3) / 4) * 4;
    temp = file_size / 8;
    *total_frames = 0;

    for (index = 0; index < temp; index++)
    {
        result = mpeg4_get_frame_length_from_meta_file(index, vos_length, &length_temp);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        if ((video_file_size - 0x20) >= (total_frame_size + length_temp))
            total_frame_size += length_temp;
        else
        {
            g_video_enc_status.FSAL_STATUS = FSAL_Direct_Seek(video_file, total_frame_size + 0x20);

            if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
            {
                VIDEO_ASSERT(0);

                g_video_enc_status.FSAL_ERROR_FILE = video_file;
                return FSAL_ERROR;
            }

            FS_Truncate(video_file->hFile);
            break;
        }
        (*total_frames)++;
    }
    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_type(STFSAL * meta_file, kal_uint32 * type)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_is_short_header);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)type, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_framerate(STFSAL * meta_file, kal_uint32 * frame_rate)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_average_frame_rate);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)frame_rate, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_timescale(STFSAL * meta_file, kal_uint32 * timescale)
{
	 MEDIA_STATUS_CODE result;
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_time_scale);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)timescale, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }
	 
	 result = video_enc_get_is_vedt(meta_file, &is_vedt); //Video editor or not, Jensen add, 2007/03/07
    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_frame_size(STFSAL * meta_file, kal_uint32 * width, kal_uint32 * height)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_frame_width);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)width, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)height, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_vos_length(STFSAL * meta_file, kal_uint32 * length)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_vos_length);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)length, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_vos_data(kal_uint8 * vos, kal_uint32 length, STFSAL * meta_file)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_vos_data);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)vos, length);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_mdatsz_pos(STFSAL * meta_file, kal_uint32 * pos)
{
    g_video_enc_status.FSAL_STATUS = FSAL_Seek(meta_file, file_create_pos_video_mdatsz_pos);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(meta_file, (kal_uint8 *)pos, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE mpeg4_get_frame_timestamp_from_meta_file(kal_uint32 frame_number, kal_uint32 vos_length, kal_uint32 * result)
{
    kal_uint32 length_pos;

    length_pos = (((file_create_pos_vos_data + vos_length + 3) / 4) * 4) + (8 * frame_number);

    g_video_enc_status.FSAL_STATUS = FSAL_Seek(&mp4_files.MEDIA_META_FILE, length_pos);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(&mp4_files.MEDIA_META_FILE, (kal_uint8 *)result, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE mpeg4_get_frame_length_from_meta_file(kal_uint32 frame_number, kal_uint32 vos_length, kal_uint32 * result)
{
    kal_uint32 length_pos;

    length_pos = (((file_create_pos_vos_data + vos_length + 3) / 4) * 4) + (8 * frame_number) + 4;

    g_video_enc_status.FSAL_STATUS = FSAL_Seek(&mp4_files.MEDIA_META_FILE, length_pos);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_Read(&mp4_files.MEDIA_META_FILE, (kal_uint8 *)result, 4);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
        return FSAL_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE mpeg4_generate_max_buffer_and_frame(kal_uint32 * total_frame_length, kal_uint32 * avg_frame, kal_uint32 * max_frame, kal_uint32 frame_number, kal_uint32 frame_rate, kal_uint32 vos_length)
{
    kal_uint32 i;

    kal_uint32 total;
    kal_uint32 total1;
    kal_uint32 frame_length_i;
    MEDIA_STATUS_CODE result;

    result = mpeg4_get_frame_length_from_meta_file(0, vos_length, &total1);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    total = total1;
    *total_frame_length = 0;
    *max_frame = total1;

    for (i = 1; i < frame_number; i++)
    {
        result = mpeg4_get_frame_length_from_meta_file(i, vos_length, &frame_length_i);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        if (*max_frame<frame_length_i)
            *max_frame = frame_length_i;

        total += frame_length_i;
        total1 += frame_length_i;
        if ((i + 1) % (frame_rate) == 0)
        {
            if (*total_frame_length<total1)
                *total_frame_length = total1;
            total1 = 0;
        }
    }

    if (*total_frame_length<total1)
        *total_frame_length = total1;

    *total_frame_length = *total_frame_length * 8; //bits
    total = total * 8;                             //bits
    *avg_frame = total *(frame_rate / frame_number);
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE mpeg4_generate_avg_buffer_and_frame(kal_uint32 * total_frame_length, kal_uint32 * max_frame, kal_uint32 frame_number, kal_uint32 frame_rate, kal_uint32 vos_length)
{
    kal_uint32 total;

    kal_uint32 i;
    kal_uint32 temp;
    MEDIA_STATUS_CODE result;

    total = 0;

    for (i = 0; i < frame_number; i++)
    {
        result = mpeg4_get_frame_length_from_meta_file(i, vos_length, &temp);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        total += temp;
    }

    total *= 8;

    //if( frame_number > (int)(frame_rate));
    total = total * (int)(frame_rate / ((int)frame_number));

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_get_total_duration(MP4_FILE_CREATE_STRUCT * file_creat_struct, kal_uint32 * duration)
{
    kal_uint32 i;

    kal_uint32 temp_prev;
    kal_uint32 temp;
    MEDIA_STATUS_CODE result;
    kal_uint32 vos_length;
    kal_uint32 pre_duration = 0;
    kal_uint32 stts_time;

    *duration = 0;
    temp_prev = 0;

#if defined(__VIDEO_EDITOR__)
	if (file_creat_struct->frame_number == 1)
    {
        if (is_vedt)
		  {
		  		if (VIDEO_EDITOR_DATA.lastest_frame_furation != 0)
		  		{
		  			*duration = VIDEO_EDITOR_DATA.lastest_frame_furation;
		  		}
		  		else
		  		{
		  			*duration = VIDEO_ANYBASE_TO_ANYBASE(65, 1000, file_creat_struct->time_scale);
		  		}
		  }
		  else
		  {
		  		*duration = VIDEO_ANYBASE_TO_ANYBASE(65, 1000, file_creat_struct->time_scale);
		  }
    }
    else
    {
        g_video_enc_status.FSAL_STATUS = FSAL_Seek(&mp4_files.MEDIA_META_FILE, file_create_pos_vos_length);

        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
            return FSAL_ERROR;
        }

        g_video_enc_status.FSAL_STATUS = FSAL_Read(&mp4_files.MEDIA_META_FILE, (kal_uint8 *)&vos_length, 4);

        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
            return FSAL_ERROR;
        }
        
        for (i = 0; i < file_creat_struct->frame_number - 1; i++)
        {
            result = mpeg4_get_frame_timestamp_from_meta_file(i + 1, vos_length, &temp);

            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }

            stts_time = (temp - temp_prev);

            if ((stts_time & 0xf0000000) != 0) /*impossible happen, if happen, fix tricky bug,*/
                stts_time = pre_duration;

            *duration += stts_time;
            pre_duration = stts_time;
            temp_prev = temp;
        }
        if (is_vedt)
		  {
		  		if (VIDEO_EDITOR_DATA.lastest_frame_furation != 0)
		  		{
		  			*duration = (*duration)+VIDEO_EDITOR_DATA.lastest_frame_furation;
		  		}
		  		else
		  		{
		  			*duration = (*duration)+VIDEO_ANYBASE_TO_ANYBASE(500, 1000, file_creat_struct->time_scale);
		  		}
		  }
		  else
		  {
		  		*duration = (*duration)+VIDEO_ANYBASE_TO_ANYBASE(500, 1000, file_creat_struct->time_scale);
		  }
    }
#else	/*!__VIDEO_EDITOR__*/
    if (file_creat_struct->frame_number == 1)
    {
        *duration = 500;
    }
    else
    {
        g_video_enc_status.FSAL_STATUS = FSAL_Seek(&mp4_files.MEDIA_META_FILE, file_create_pos_vos_length);

        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
            return FSAL_ERROR;
        }

        g_video_enc_status.FSAL_STATUS = FSAL_Read(&mp4_files.MEDIA_META_FILE, (kal_uint8 *)&vos_length, 4);

        if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
        {
            VIDEO_ASSERT(0);

            g_video_enc_status.FSAL_ERROR_FILE = &mp4_files.MEDIA_META_FILE;
            return FSAL_ERROR;
        }
        for (i = 0; i < file_creat_struct->frame_number - 1; i++)
        {
            result = mpeg4_get_frame_timestamp_from_meta_file(i + 1, vos_length, &temp);

            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }

            stts_time = (temp - temp_prev);

            if ((stts_time & 0xf0000000) != 0) /*impossible happen, if happen, fix tricky bug,*/
                stts_time = pre_duration;

            *duration += stts_time;
            pre_duration = stts_time;
            temp_prev = temp;
        }
    }
#endif
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_check_meta_file_is_enough(STFSAL * video_file, STFSAL * meta_file, STFSAL * audio_file)
{
    kal_uint32 file_size;

    kal_uint32 video_file_size;
    MEDIA_STATUS_CODE result;
    kal_uint32 vos_length;
    kal_uint32 total_frames;

    if ((video_file == NULL) || (meta_file == NULL))
    {
        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FILE_CANT_MERGE;

        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_GetFileSize(video_file, &video_file_size);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = video_file;
        return FSAL_ERROR;
    }

    g_video_enc_status.FSAL_STATUS = FSAL_GetFileSize(meta_file, &file_size);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = meta_file;
        return FSAL_ERROR;
    }

    if ((file_size >= 0x18) && (video_file_size > 0x20))
    {
        result = video_enc_get_vos_length(meta_file, &vos_length);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        file_size = file_size - ((vos_length + 0x18 + 3) / 4) * 4;
        total_frames = file_size / 8;
        if (total_frames < 1)
        {
            g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FILE_CANT_MERGE;

            VIDEO_ASSERT(0);
            return VIDEO_ERROR;
        }
    }
    else
    {
        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FILE_CANT_MERGE;

        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_enc_generate_META_file(MP4_FILE_CREATE_STRUCT * file_creat_struct, STFSAL * real_meta_file, MP4_FILE_INFO * video_file_info)
{
    t_rtc test_time;

    kal_uint32 i;
    kal_uint32 temp;
    kal_uint32 create_time;
    kal_uint32 duration;
    kal_uint32 mp4_file_pos;
    kal_uint32 avg_frame_lentgh;
    MEDIA_STATUS_CODE result;
    kal_uint32 length_tmp;
    kal_uint32 temp_prev;
    kal_uint32 pre_duration = 0;
    kal_uint32 stts_time;
    kal_uint32 stts_count;
    kal_uint32 stts_entry_count;
    kal_uint32 stts_entry_addr;
#if 0
/* under construction !*/
#endif

    if (file_creat_struct->frame_number < 1)
    {
        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_FILE_CANT_MERGE;

        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }

    test_time.rtc_year = 4;
    test_time.rtc_mon = 2;
    test_time.rtc_day = 15;
    test_time.rtc_hour = 12;
    test_time.rtc_min = 5;
    test_time.rtc_sec = 5;

    if (file_creat_struct->time_scale <= file_creat_struct->frame_rate)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.VIDEO_STATUS = VIDEO_ENC_NOT_SUPPORT;
        return VIDEO_ERROR;
    }

    /*Initialize*/
    for (i = 0; i < MAX_ATOM_TYPE_NUMBER; i++)
    {
        video_file_info->FC_ATOM[i].pos = 0xffffffff;
    }

    mp4_file_pos = 0;
    /** mdat **/
    mp4_crt_write_int(mp4_file_pos, 0x2E, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "mdat", 4, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x01808080, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x0E118080, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x8009051F, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x0F808080, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x020001C0, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x10126104, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x1FC00000, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x1FC00000, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x44282282, real_meta_file);
    mp4_crt_write_short(mp4_file_pos, 0x9F80, real_meta_file);

    //moov size
    video_file_info->FC_ATOM[moov].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file); //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "moov", 4, real_meta_file);

    /* moov->mvhd  size*/
    mp4_crt_write_int(mp4_file_pos, 0x6c, real_meta_file);                           //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "mvhd", 4, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);                            //version + flags
    create_time = mpeg4_cratetime_translate(&test_time);
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->create_time, real_meta_file); //create time,just for test
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->create_time, real_meta_file); //modification time, just for test
    
#if defined(__VIDEO_EDITOR__)
	 {
	     kal_uint32 temp_time_scale = 8000;
	     kal_uint32 temp_duration;
	     mp4_crt_write_int(mp4_file_pos, temp_time_scale, real_meta_file);  //time scale
	     result = video_enc_get_total_duration(file_creat_struct, &duration);
	     if (result != MEDIA_STATUS_OK)
	     {
	         VIDEO_ASSERT(0);
	         return result;
	     }
		  temp_duration = (kal_uint32)VIDEO_ANYBASE_TO_ANYBASE(duration, file_creat_struct->time_scale, temp_time_scale);
	     file_creat_struct->total_duration = (kal_uint32)VIDEO_ANYBASE_TO_MS(temp_duration, temp_time_scale);
	     mp4_crt_write_int(mp4_file_pos, temp_duration, real_meta_file); //duration
    }
#else	/*!__VIDEO_EDITOR__*/
	 {
	 	    mp4_crt_write_int(mp4_file_pos, file_creat_struct->time_scale, real_meta_file);  //time scale
		    result = video_enc_get_total_duration(file_creat_struct, &duration);
		    if (result != MEDIA_STATUS_OK)
		    {
		        VIDEO_ASSERT(0);
		        return result;
		    }
		    file_creat_struct->total_duration = (kal_uint32)VIDEO_ANYBASE_TO_MS(duration, file_creat_struct->time_scale);
		    mp4_crt_write_int(mp4_file_pos, duration, real_meta_file); //duration
	 }
#endif	/*__VIDEO_EDITOR__*/
    
    mp4_crt_write_int(mp4_file_pos, 0x00010000, real_meta_file);
    mp4_crt_write_short(mp4_file_pos, 0x0100, real_meta_file);
    //   mp4_crt_write_zero_group(mp4_file_pos,16,real_meta_file);
    mp4_crt_write_zero_group(mp4_file_pos, 10, real_meta_file);
    pre_defined_hr(&mp4_file_pos, real_meta_file);
    mp4_crt_write_zero_group(mp4_file_pos, 24, real_meta_file);

    if (file_creat_struct->short_header == 0)
    {
        mp4_crt_write_int(mp4_file_pos, 0x04, real_meta_file);
    }
    else
    {
        mp4_crt_write_int(mp4_file_pos, 0x10000, real_meta_file);
    }

    /** moov->iods **/
    if (file_creat_struct->short_header == 0)
    {
        mp4_crt_write_int(mp4_file_pos, 0x2A, real_meta_file);

        mp4_crt_write_char_group(mp4_file_pos, "iods", 4, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x10808080, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x19004FFF, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0xFFFF03FF, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0E808080, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x04000000, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x020E8080, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x80040000, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 0x0003, real_meta_file);
    }

    /** moov->video trak **/
    video_file_info->FC_ATOM[trak].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file); //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "trak", 4, real_meta_file);

    /** moov->trak->tkhd **/
    mp4_crt_write_int(mp4_file_pos, 0x5c, real_meta_file); //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "tkhd", 4, real_meta_file);

    if (file_creat_struct->short_header == 0)
    {
        mp4_crt_write_int(mp4_file_pos, 0x1, real_meta_file);
    } // version+flag
    else
    {
        mp4_crt_write_int(mp4_file_pos, 0x7, real_meta_file);
    }                                                                                // version+flag

    mp4_crt_write_int(mp4_file_pos, file_creat_struct->create_time, real_meta_file); //create time
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->create_time, real_meta_file); //modification time
    mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);                              //Track ID
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file);                              //Reserved
    mp4_crt_write_int(mp4_file_pos, duration, real_meta_file);
    mp4_crt_write_zero_group(mp4_file_pos, 16, real_meta_file);
    result = pre_defined_hr(&mp4_file_pos, real_meta_file);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }

    if (file_creat_struct->short_header == 0)
    {
        mp4_crt_write_int(mp4_file_pos, 0x01400000, real_meta_file); //Pre-defined
        mp4_crt_write_int(mp4_file_pos, 0x00f00000, real_meta_file); //Pre-defined
    }
    else
    {
        mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_width << 16, real_meta_file);  //Pre-defined
        mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_height << 16, real_meta_file); //Pre-defined
    }

    /** moov->trak->mdia **/
    video_file_info->FC_ATOM[mdia].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file); //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "mdia", 4, real_meta_file);
    /** moov->trak->mdhd **/
    mp4_crt_write_int(mp4_file_pos, 0x20, real_meta_file);                           //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "mdhd", 4, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);                            // version+flag
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->create_time, real_meta_file); //create time
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->create_time, real_meta_file); //modification time
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->time_scale, real_meta_file);  //time scale
    mp4_crt_write_int(mp4_file_pos, duration, real_meta_file);                       //time duration

    if (file_creat_struct->short_header == 0)
    {
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file); // language+quality
    }
    else
    {
        mp4_crt_write_int(mp4_file_pos, 0x55C40000, real_meta_file); // language+quality
    }

    /** moov->trak->hdlr **/
    mp4_crt_write_int(mp4_file_pos, 0x21, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "hdlr", 4, real_meta_file);
    mp4_crt_write_zero_group(mp4_file_pos, 8, real_meta_file);  //predefined, component type
    mp4_crt_write_char_group(mp4_file_pos, "vide", 4, real_meta_file);
    mp4_crt_write_zero_group(mp4_file_pos, 13, real_meta_file); //reserved

    /** moov->trak->minf **/
    video_file_info->FC_ATOM[minf].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "minf", 4, real_meta_file);
    /** moov->trak->minf->vmhd **/
    mp4_crt_write_int(mp4_file_pos, 20, real_meta_file);               //size
    mp4_crt_write_char_group(mp4_file_pos, "vmhd", 4, real_meta_file); //vmhd
    mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);                // version+flag
    mp4_crt_write_zero_group(mp4_file_pos, 8, real_meta_file);         //Predefined

    /** moov->trak->minf->dinf **/
    mp4_crt_write_int(mp4_file_pos, 36, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "dinf", 4, real_meta_file); //dinf
    mp4_crt_write_int(mp4_file_pos, 0x01C, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "dref", 4, real_meta_file); //dref
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file);                // version+flag
    mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);                // number of entries
    mp4_crt_write_int(mp4_file_pos, 12, real_meta_file);               //size
    mp4_crt_write_char_group(mp4_file_pos, "url ", 4, real_meta_file); //type = url
    mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);                // version+flag

    /** moov->trak->minf->stbl **/
    video_file_info->FC_ATOM[stbl].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "stbl", 4, real_meta_file); //stbl

    /** moov->trak->minf->stbl->stsd **/
    video_file_info->FC_ATOM[stsd].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "stsd", 4, real_meta_file); //stsd
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file);                //version, flags
    mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);                //number of entries

    if (file_creat_struct->short_header == 0)
    {
        kal_uint32 max_frame_length;

        kal_uint32 frame_length_sum_per_second;

        video_file_info->FC_ATOM[s263].pos = 0xffffffff;
        video_file_info->FC_ATOM[mp4v].pos = mp4_file_pos;
        mp4_crt_write_int(mp4_file_pos, 0xad, real_meta_file); //<==position??
        mp4_crt_write_char_group(mp4_file_pos, "mp4v", 4, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);  /*		*/
        mp4_crt_write_int(mp4_file_pos, 0x1, real_meta_file);  /* array*/
        mp4_crt_write_zero_group(mp4_file_pos, 16, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, ((kal_uint16)file_creat_struct->frame_width), real_meta_file);
        mp4_crt_write_short(mp4_file_pos, ((kal_uint16)file_creat_struct->frame_height), real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x480000, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x480000, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 0x1, real_meta_file);
        mp4_crt_write_zero_group(mp4_file_pos, 32, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 24, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 0xFFFF, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, (49 + file_creat_struct->VOS_length), real_meta_file);
        mp4_crt_write_char_group(mp4_file_pos, "esds", 4, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x03808080, real_meta_file);                            //DESC 3
        mp4_crt_write_char(mp4_file_pos, (file_creat_struct->VOS_length + 32), real_meta_file); //length
        mp4_crt_write_short(mp4_file_pos, 0x01, real_meta_file);                                //content
        mp4_crt_write_char(mp4_file_pos, 0x0, real_meta_file);                                  //content
        mp4_crt_write_int(mp4_file_pos, 0x04808080, real_meta_file);                            //DESC 4
        mp4_crt_write_char(mp4_file_pos, (file_creat_struct->VOS_length + 18), real_meta_file); //length
        result = mpeg4_generate_max_buffer_and_frame(&frame_length_sum_per_second, &avg_frame_lentgh, &max_frame_length, file_creat_struct->frame_number, file_creat_struct->frame_rate, file_creat_struct->VOS_length);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }

        mp4_crt_write_short(mp4_file_pos, 0x2011, real_meta_file);
        mp4_crt_write_char(mp4_file_pos, ((max_frame_length & 0xff0000) >> 16), real_meta_file);
        mp4_crt_write_short(mp4_file_pos, ((kal_uint16)(max_frame_length & 0xffff)), real_meta_file);
        mp4_crt_write_int(mp4_file_pos, frame_length_sum_per_second, real_meta_file); //maxBitrate
        mp4_crt_write_int(mp4_file_pos, avg_frame_lentgh, real_meta_file);            //avgBitrate 
        mp4_crt_write_int(mp4_file_pos, 0x05808080, real_meta_file);                  //DESC 5
        mp4_crt_write_char(mp4_file_pos, file_creat_struct->VOS_length, real_meta_file);

        if (((file_creat_struct->VOS_ptr[0] << 24) + (file_creat_struct->VOS_ptr[1] << 16) + (file_creat_struct->VOS_ptr[2] << 8) + file_creat_struct->VOS_ptr[3]) == 0x1b0)
        {
            mp4_crt_write(mp4_file_pos, (kal_uint8 *)file_creat_struct->VOS_ptr, file_creat_struct->VOS_length, real_meta_file);
        //mp4_file_pos += file_creat_struct->VOS_length;
        }
        else
        {
            mp4_crt_write_int(mp4_file_pos, 0x000001B0, real_meta_file);

            mp4_crt_write_int(mp4_file_pos, 0x01000001, real_meta_file);
            mp4_crt_write_short(mp4_file_pos, 0xB509, real_meta_file);
            mp4_crt_write(mp4_file_pos, (kal_uint8 *)file_creat_struct->VOS_ptr, (file_creat_struct->VOS_length - 10), real_meta_file);
        //mp4_file_pos += (file_creat_struct->VOS_length-10);
        }

        mp4_crt_write_int(mp4_file_pos, 0x06808080, real_meta_file); //DESC 6
        mp4_crt_write_char(mp4_file_pos, 0x01, real_meta_file);      //length
        mp4_crt_write_char(mp4_file_pos, 0x02, real_meta_file);
        video_file_info->FC_ATOM[mp4v].size = mp4_file_pos - video_file_info->FC_ATOM[mp4v].pos;
    }
    else
    {
        video_file_info->FC_ATOM[mp4v].pos = 0xffffffff;

        video_file_info->FC_ATOM[s263].pos = mp4_file_pos;
        mp4_crt_write_int(mp4_file_pos, 0, real_meta_file); //<==position??
        mp4_crt_write_char_group(mp4_file_pos, "s263", 4, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x1, real_meta_file);
        mp4_crt_write_zero_group(mp4_file_pos, 16, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, ((kal_uint16)file_creat_struct->frame_width), real_meta_file);
        mp4_crt_write_short(mp4_file_pos, ((kal_uint16)file_creat_struct->frame_height), real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x480000, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x480000, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 0x1, real_meta_file);
        mp4_crt_write_zero_group(mp4_file_pos, 32, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 24, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 0xFFFF, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 0xF, real_meta_file);
        mp4_crt_write_char_group(mp4_file_pos, "d263MTK ", 8, real_meta_file);
        mp4_crt_write_short(mp4_file_pos, 0x0a, real_meta_file);
        mp4_crt_write_char(mp4_file_pos, 0x0, real_meta_file);
        video_file_info->FC_ATOM[s263].size = mp4_file_pos - video_file_info->FC_ATOM[s263].pos;
    }

    video_file_info->FC_ATOM[stsd].size = mp4_file_pos - video_file_info->FC_ATOM[stsd].pos;

    /** stts **/
    video_file_info->FC_ATOM[stts].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);                                 //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "stts", 4, real_meta_file);

    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file);                                 //version, flags
    stts_entry_addr = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_number - 1, real_meta_file); //number of entries
    result = mpeg4_get_frame_timestamp_from_meta_file(0, file_creat_struct->VOS_length, &temp);

    if (result != MEDIA_STATUS_OK)
    {
        VIDEO_ASSERT(0);
        return result;
    }
#if 0 //Jensen's comment, it is unnecessary in V2 environment.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    temp_prev = temp;

    stts_time = 0;
    stts_count = 0;
    stts_entry_count = 0;
    pre_duration = 0;

    if (file_creat_struct->frame_number == 1)
    {
        stts_entry_count++;
#if defined(__VIDEO_EDITOR__)
		  if (is_vedt)
		  {
		  		if (VIDEO_EDITOR_DATA.lastest_frame_furation != 0)
		  		{
		  			mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_number, real_meta_file); /*tricky for special case*/
	        		mp4_crt_write_int(mp4_file_pos, VIDEO_EDITOR_DATA.lastest_frame_furation, real_meta_file);
		  		}
		  		else
		  		{
		  			kal_uint32 temp_time;
		  			temp_time = VIDEO_ANYBASE_TO_ANYBASE(65, 1000, file_creat_struct->time_scale);
		  			mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_number, real_meta_file); /*tricky for special case*/
	        		mp4_crt_write_int(mp4_file_pos, temp_time, real_meta_file);
		  		}
		  }
		  else
#endif
		  {
		  	  kal_uint32 temp_time;
		  	  temp_time = VIDEO_ANYBASE_TO_ANYBASE(65, 1000, file_creat_struct->time_scale);
	        mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_number, real_meta_file); /*tricky for special case*/
	        mp4_crt_write_int(mp4_file_pos, temp_time, real_meta_file);
	     }
    }
    else
    {
        for (i = 0; i < file_creat_struct->frame_number - 1; i++)
        {
            result = mpeg4_get_frame_timestamp_from_meta_file(i + 1, file_creat_struct->VOS_length, &temp);

            if (result != MEDIA_STATUS_OK)
            {
                VIDEO_ASSERT(0);
                return result;
            }
#if 1
            stts_time = temp - temp_prev;
            kal_prompt_trace( MOD_MED_V, "prev=%d, stts_time=%d", temp_prev, stts_time);
            if ((stts_time & 0xf0000000) != 0) /*impossible happen, if happen, fix tricky bug,*/
                stts_time = pre_duration;

            if (i < file_creat_struct->frame_number - 2)
            {
                if (stts_time == pre_duration)
                    stts_count++;
                else
                {
                    if (i != 0)
                    {
                        stts_entry_count++;

                        mp4_crt_write_int(mp4_file_pos, (stts_count + 1), real_meta_file);
                        mp4_crt_write_int(mp4_file_pos, pre_duration, real_meta_file);
                        stts_count = 0;
                    }
                }
            }
            else
            {
                if (file_creat_struct->frame_number > 2)
                {
                	
#if defined(__VIDEO_EDITOR__)
						  if (is_vedt)
						  {
						  	   stts_entry_count += 3;
	
	                     mp4_crt_write_int(mp4_file_pos, (stts_count + 1), real_meta_file);
	                     mp4_crt_write_int(mp4_file_pos, pre_duration, real_meta_file);
	                     mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
	                    	mp4_crt_write_int(mp4_file_pos, stts_time, real_meta_file);
	                    
						  		if (VIDEO_EDITOR_DATA.lastest_frame_furation != 0)
						  		{
						  			mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
					        		mp4_crt_write_int(mp4_file_pos, VIDEO_EDITOR_DATA.lastest_frame_furation, real_meta_file);
						  		}
						  		else
						  		{
						  			kal_uint32 temp_time;
						  			
						  			temp_time = VIDEO_ANYBASE_TO_ANYBASE(500, 1000, file_creat_struct->time_scale);
						  			mp4_crt_write_int(mp4_file_pos, 1, real_meta_file); /*tricky for special case*/
					        		mp4_crt_write_int(mp4_file_pos, temp_time, real_meta_file);
						  		}
						  }
						  else
#endif	/*__VIDEO_EDITOR__*/
						  {
	                    stts_entry_count += 2;
	
	                    mp4_crt_write_int(mp4_file_pos, (stts_count + 1), real_meta_file);
	                    mp4_crt_write_int(mp4_file_pos, pre_duration, real_meta_file);
	                    mp4_crt_write_int(mp4_file_pos, 2, real_meta_file);
	                    mp4_crt_write_int(mp4_file_pos, stts_time, real_meta_file);
                    }
                    stts_count = 0;
                }
                else
                {
                    stts_entry_count++;
	                 mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_number, real_meta_file); /*tricky for special case*/
	                 mp4_crt_write_int(mp4_file_pos, stts_time, real_meta_file);
                    break;
                }
            }

            pre_duration = stts_time;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

            temp_prev = temp;
        }
    }

    video_file_info->FC_ATOM[stts].size = mp4_file_pos - video_file_info->FC_ATOM[stts].pos;

    /** stsc **/
    video_file_info->FC_ATOM[stsc].pos = mp4_file_pos;
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file); //<==position??
    mp4_crt_write_char_group(mp4_file_pos, "stsc", 4, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0x0, real_meta_file); //version, flag

    if (((file_creat_struct->frame_number % file_creat_struct->frame_rate) != 0) && (file_creat_struct->frame_number > file_creat_struct->frame_rate))
    {
        kal_uint32 div;

        mp4_crt_write_int(mp4_file_pos, 2, real_meta_file); /* number of entries */
        mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_rate, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
        div = (file_creat_struct->frame_number / file_creat_struct->frame_rate);
        mp4_crt_write_int(mp4_file_pos, (div + 1), real_meta_file);
        mp4_crt_write_int(mp4_file_pos, (file_creat_struct->frame_number - file_creat_struct->frame_rate * div), real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
    }
    else
    {
        mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);

        mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_rate, real_meta_file);
        mp4_crt_write_int(mp4_file_pos, 1, real_meta_file);
    }

    video_file_info->FC_ATOM[stsc].size = mp4_file_pos - video_file_info->FC_ATOM[stsc].pos;

    /** stsz **/
    mp4_crt_write_int(mp4_file_pos, (file_creat_struct->frame_number * 4) + 20, real_meta_file);
    mp4_crt_write_char_group(mp4_file_pos, "stsz", 4, real_meta_file);
    mp4_crt_write_zero_group(mp4_file_pos, 8, real_meta_file); /*	version, sample size ? */
    mp4_crt_write_int(mp4_file_pos, file_creat_struct->frame_number, real_meta_file);

    for (i = 0; i < file_creat_struct->frame_number; i++)
    {
        result = mpeg4_get_frame_length_from_meta_file(i, file_creat_struct->VOS_length, &length_tmp);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        mp4_crt_write_int(mp4_file_pos, length_tmp, real_meta_file);
    }

    /** stco **/
    temp = (file_creat_struct->frame_number / file_creat_struct->frame_rate);

    if (file_creat_struct->frame_number % file_creat_struct->frame_rate)
        temp++;

    mp4_crt_write_int(mp4_file_pos, (temp * 4 + 16), real_meta_file);

    mp4_crt_write_char_group(mp4_file_pos, "stco", 4, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file); /*	version,flags  */

    if (file_creat_struct->frame_number % file_creat_struct->frame_rate)
    {
        mp4_crt_write_int(mp4_file_pos, (file_creat_struct->frame_number / file_creat_struct->frame_rate) + 1, real_meta_file); //chunk number
    }
    else
    {
        mp4_crt_write_int(mp4_file_pos, (file_creat_struct->frame_number / file_creat_struct->frame_rate), real_meta_file);
    }

    temp = 0x020;

    for (i = 0; i < file_creat_struct->frame_number; i++)
    {
        if (i % ((int)file_creat_struct->frame_rate) == 0)
        {
            mp4_crt_write_int(mp4_file_pos, temp, real_meta_file);
        }

        result = mpeg4_get_frame_length_from_meta_file(i, file_creat_struct->VOS_length, &length_tmp);

        if (result != MEDIA_STATUS_OK)
        {
            VIDEO_ASSERT(0);
            return result;
        }
        temp += length_tmp;
    }

    /** stss **/
    temp = (file_creat_struct->frame_number / Video_Enc_IntraPeriod);

    if (temp == 0)
        temp = 1;
#if 0
/* under construction !*/
/* under construction !*/
#endif

    mp4_crt_write_int(mp4_file_pos, (temp * 4 + 16), real_meta_file);

    mp4_crt_write_char_group(mp4_file_pos, "stss", 4, real_meta_file);
    mp4_crt_write_int(mp4_file_pos, 0, real_meta_file);    /*	version,flags  */
    mp4_crt_write_int(mp4_file_pos, temp, real_meta_file); /* number of entries */

    for (i = 0; i < temp; i++)
    {
        mp4_crt_write_int(mp4_file_pos, i * Video_Enc_IntraPeriod + 1, real_meta_file);
    }
#if 0
/* under construction !*/
/* under construction !*/
#endif

    g_video_enc_status.FSAL_STATUS = FSAL_Write_UINT_AT(real_meta_file, stts_entry_count, stts_entry_addr);

    if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
    {
        VIDEO_ASSERT(0);

        g_video_enc_status.FSAL_ERROR_FILE = real_meta_file;
        return FSAL_ERROR;
    }

    video_file_info->FC_ATOM[stbl].size = mp4_file_pos - video_file_info->FC_ATOM[stbl].pos;
    video_file_info->FC_ATOM[minf].size = mp4_file_pos - video_file_info->FC_ATOM[minf].pos;
    video_file_info->FC_ATOM[mdia].size = mp4_file_pos - video_file_info->FC_ATOM[mdia].pos;
    video_file_info->FC_ATOM[trak].size = mp4_file_pos - video_file_info->FC_ATOM[trak].pos;
    //Only video trak size
    video_file_info->FC_ATOM[moov].size = mp4_file_pos - video_file_info->FC_ATOM[moov].pos;
    //	FSAL_Direct_SetRamFileSize(real_meta_file, mp4_file_pos);
    temp = mp4_file_pos;

    for (i = 0; i < MAX_ATOM_TYPE_NUMBER; i++)
    {
        if (video_file_info->FC_ATOM[i].pos != 0xffffffff)
        {
            g_video_enc_status.FSAL_STATUS = FSAL_Write_UINT_AT(real_meta_file, video_file_info->FC_ATOM[i].size, video_file_info->FC_ATOM[i].pos);
            if (g_video_enc_status.FSAL_STATUS != FSAL_OK)
            {
                VIDEO_ASSERT(0);

                g_video_enc_status.FSAL_ERROR_FILE = real_meta_file;
                return FSAL_ERROR;
            }
        }
    }

    return MEDIA_STATUS_OK;
}
#else  /*!MP4_CODEC*/
#include "drv_comm.h"
#endif /*MP4_CODEC*/
