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
 *   aud_media.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes media related functions of audio manager task.
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

/******************************************************************
 * MODULE
 *    AUD_MEDIA
 * DESCRIPTION
 *    This module defines the media related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "fat_fs.h"
/* DRM_REPLACE */
#include "drm_gprot.h"

#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

#include "FSAL.h"
#include "MP4_Parser.h"

#ifdef MP4_CODEC
#include "MP4_Producer_Audio.h"
#include "MP4_Sample_Data_Audio.h"
#include "drv_comm.h"
#include "visual_comm.h"
#include "lcd_if.h"
#include "rtc_sw.h"
#include "video_file_creator.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#endif /* MP4_CODEC */ 

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_v_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
#include "vid_main.h"
#include "vid_avi.h"
#endif /* defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#include "aud_daf_parser.h"
#include "aud_amr_parser.h"
#ifdef __RICH_AUDIO_PROFILE__
extern volatile kal_mutexid audio_input_stream_mutex;   /* from aud_input_stream.c */
#endif 

typedef MHdl *(*media_open_func_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);
typedef Media_Status(*media_ctrl_func_ptr) (MHdl *hdl);
typedef void (*media_set_buf_func_ptr) (MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len);
typedef Media_Status(*media_set_time_func_ptr) (MHdl *hdl, kal_uint32 msStartTime);
typedef Media_Event(*media_proc_func_ptr) (MHdl *hdl, Media_Event event);
typedef Media_Status(*media_get_info_func_ptr) (STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param);

#define UNKNOWN_MEDIA_FORMAT 255

#define AMR_HEADER   "#!AMR\n"
#define AWB_HEADER   "#!AMR-WB\n"

#define RECORD_MEM_MARGIN (512)
#define GET_DWORD(x) (((kal_uint32)(x)[0]) | (((kal_uint32)(x)[1])<<16))
#define SET_DWORD(x,y) ((x)[0]=(kal_uint16)((y)&0xffff),x[1]=(kal_uint16)((y)>>16))
#define GET_BIG_DWORD(x) ((((kal_uint32)(x)[0])<<24) | (((kal_uint32)(x)[1])<<16) | (((kal_uint32)(x)[2])<<8) | ((kal_uint32)(x)[3]))
#define SET_BIG_DWORD(x,y) ((x)[0]=(kal_uint8)((y)>>24),x[1]=(kal_uint8)(((y)>>16)&0xff),x[2]=(kal_uint8)(((y)>>8)&0xff),(x)[3]=(kal_uint8)((y)&0xff))

extern kal_bool mediaIsDataConsumed(void);
extern int mediaGetDataCount(void);

/*========== Local Variables =============*/

/* for store temp info in real resume mechanism */
kal_uint32 temp_last_time;
kal_uint32 temp_last_offset;

kal_bool aud_record_low_priority = KAL_FALSE;

typedef struct
{
    kal_uint8 *header;
    kal_uint16 size;
}
aud_file_header_struct;

aud_file_header_struct aud_file_header[2];

const kal_uint8 amr_header[] = AMR_HEADER;
const kal_uint8 awb_header[] = AWB_HEADER;

#if defined(__MED_VID_MOD__)
extern STMp4Parser *stMp4Parser_a_ptr;

#ifdef AAC_DECODE
#define MED_AUD_AAC_SILENCE_FRAME_SIZE  (16)
static const kal_uint8 med_aud_aac_silence_frame[MED_AUD_AAC_SILENCE_FRAME_SIZE] = 
{
    0xFF, 0xF1, 0x5C, 0xA0, 0x02, 0x1F, 0xFC,
    0x21, 0x00, 0x49, 0x90, 0x02, 0x19, 0x00, 0x23, 0x80
};
#endif /* AAC_DECODE */
#endif /* defined(__MED_VID_MOD__) */ 

#if defined(__MED_VID_ENC_MOD__)
extern STFSAL stFSALProducerAudData;
#endif /* defined(__MED_VID_ENC_MOD__) */ 

#if defined(__MED_MJPG_MOD__)
extern med_avi_info_struct avi_data;
#endif /* defined(__MED_MJPG_MOD__)*/ 


STFSAL current_file_stream;

/* Use Static Memory For FSAL Buffer to avoid External memory fragment */
#if defined(AUD_PROC_USE_EXT_MEM)
kal_uint8 med_aud_fasl_buf[AUD_PROC_BUF_SIZE];
#endif

#ifdef __MED_BT_A2DP_MOD__
#if defined(__BTMTK__)
extern void aud_bt_a2dp_open_codec(kal_int32 audio_format);
#endif
#endif /* __MED_BT_A2DP_MOD__ */ 

/* Parser for 3GP/MP4 audio */
#if defined(MED_PURE_AUDIO)

static void aud_media_free_mp4_parser(void);
static kal_uint8 aud_media_play_audio_track_in_video(
        kal_wchar *file_name,
        kal_uint8 play_style, 
        kal_bool first_time,
        kal_bool is_restore);
static kal_uint8 aud_media_replay_audio_track_in_video(kal_uint8 play_style, kal_bool replay);
static kal_bool aud_media_pause_audio_track_in_video(kal_uint8 **res);
static kal_bool aud_media_resume_audio_track_in_video(kal_uint8 **res);
static kal_bool aud_media_process_audio_track_in_video(kal_uint8 event);
static kal_uint8 aud_media_get_audio_duration_in_video(
        kal_wchar *file_name,
        kal_uint8 *aud_data,
        kal_uint32 aud_len,
        kal_int16 format,
        kal_uint32* duration);

#define AUD_DEC_SEEK_HINT_SIZE      (2047)
#define AUD_MP4_FSAL_BUF_SIZE       (1024 / 4)
#define AUD_MP4_STCO_BUF_SIZE       (512 / 4)
#define AUD_MP4_STSZ_BUF_SIZE       (512 / 4)
#define AUD_MP4_STBL_BUF_SIZE       (1024 / 4 * 8)

typedef struct
{
    STMp4Parser *stMp4Parser_aud;
    STFSAL *stFSAL_aud_stsz;
    STFSAL *stFSAL_aud_stco;
    STFSAL *stFSAL_aud_data;
    kal_uint32 *mp4_aud_buf;
    kal_uint32 *mp4_aud_data_buf;
    kal_uint32 *mp4_aud_stco_buf;
    kal_uint32 *mp4_aud_stsz_buf;
    kal_uint32 *mp4_aud_stbl_buf;
    FS_FileLocationHint *aud_seek_hint;
}aud_mp4_parser_var;

static aud_mp4_parser_var g_aud_mp4_parser;
static kal_uint32 temp_pause_time;

#endif /* #if defined(MED_PURE_AUDIO) */

#ifdef __VOIP__
extern kal_bool AM_IsVoIPOn(void);
#endif

/*========== Functions =============*/


/*****************************************************************************
 * FUNCTION
 *  aud_media_init
 * DESCRIPTION
 *  This function is used to init aud_media module
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_media_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_file_header[0].header = (kal_uint8*) amr_header;
    aud_file_header[0].size = sizeof(AMR_HEADER) - 1;

    aud_file_header[1].header = (kal_uint8*) awb_header;
    aud_file_header[1].size = sizeof(AWB_HEADER) - 1;

    aud_context_p->processing_data = KAL_FALSE;

#ifdef DEDI_AMR_REC_BUFFER
    aud_context_p->amr_buffer_p = NULL;
    aud_context_p->amr_buffer_size = 0;
#endif /* DEDI_AMR_REC_BUFFER */ 

    aud_context_p->start_offset = aud_context_p->end_offset = 0;

#ifdef __RICH_AUDIO_PROFILE__
    audio_input_stream_mutex = kal_create_mutex("audio_input_stream_mutex");
#endif 

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_open_record_file
 * DESCRIPTION
 *  This function is to open file for recording
 * PARAMETERS
 *  file_name       [?]         kal_uint8 format
 *  format          [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 aud_open_record_file(kal_wchar *file_name, kal_uint8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_uint8 res;
    kal_int32 result;
    kal_bool file_exist = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = aud_check_disc_space(file_name, RECORD_MEM_MARGIN)) != MED_RES_OK)
    {
        return res;
    }
    /* set current file foramt */
    aud_context_p->current_format = med_get_media_type((kal_wchar*) file_name);
    /* check if the format valid */
    if (aud_context_p->current_format == MED_TYPE_NONE)
    {
        if (format == MED_TYPE_NONE)
        {
            return MED_RES_INVALID_FORMAT;
        }
        else
        {
            aud_context_p->current_format = format;
        }
    }
    else if (aud_context_p->current_format == MED_TYPE_WAV)
    {
        if (format == MED_TYPE_WAV)
        {
            aud_context_p->current_format = MED_TYPE_WAV;
        }
        else
        {
            aud_context_p->current_format = MED_TYPE_WAV_DVI_ADPCM;
        }
    }
    else if (aud_context_p->current_format == MED_TYPE_GSM_EFR)
    {
        if (format == MED_TYPE_GSM_FR)
        {
            aud_context_p->current_format = MED_TYPE_GSM_FR;
        }
    }

    /* open the file */
    if ((aud_context_p->current_file_handle = FS_Open((kal_wchar*) file_name, FS_READ_WRITE | FS_NOBUSY_CHECK_MODE)) >= 0) /* Disable Busy Check Mode For Record */
    {
        file_exist = KAL_TRUE;
    }
    else
    {
        aud_context_p->current_file_handle = FS_Open((kal_wchar*) file_name, FS_CREATE | FS_READ_WRITE | FS_NOBUSY_CHECK_MODE); /* Disable Busy Check Mode For Record */
    }

    if (aud_context_p->current_file_handle >= 0)
    {
        if (file_exist)
        {
            FS_Seek(aud_context_p->current_file_handle, (int)0, FS_FILE_END);
        }
        else if (aud_context_p->current_format == MED_TYPE_AMR || aud_context_p->current_format == MED_TYPE_AMR_WB)
        {
            aud_file_header_struct *file_header;

            file_header = &(aud_file_header[aud_context_p->current_format - MED_TYPE_AMR]);
            result = FS_Write(aud_context_p->current_file_handle, file_header->header, file_header->size, &len);
            if (result != FS_NO_ERROR || len != file_header->size)
            {
                FS_Close(aud_context_p->current_file_handle);
                aud_context_p->current_file_handle = -1;
                return MED_RES_OPEN_FILE_FAIL;
            }
        #ifdef DEDI_AMR_REC_BUFFER
            if (aud_context_p->speech_on || Media_IsCSDMode())
            {
                aud_context_p->amr_buffer_size = AMR515_BufferSize();
                if (aud_context_p->amr_buffer_size > 0)
                {
                    aud_context_p->amr_buffer_p = med_alloc_int_mem(aud_context_p->amr_buffer_size);
                    AMR515_SetBuffer(aud_context_p->amr_buffer_p, aud_context_p->amr_buffer_size);
                }
            }
        #endif /* DEDI_AMR_REC_BUFFER */ 

        }

        kal_mem_cpy(aud_context_p->current_file_name, file_name, MAX_FILE_NAME_LEN * ENCODE_BYTE);

        return MED_RES_OK;
    }
    else if (aud_context_p->current_file_handle == FS_WRITE_PROTECTION)
    {
        return MED_RES_WRITE_PROTECTION;
    }
    else
    {
        return MED_RES_OPEN_FILE_FAIL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_close_record_file
 * DESCRIPTION
 *  This function is to close the recorded file.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 aud_close_record_file(void)
{
#if !defined(MT6205B) && !defined(MT6208)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->current_format == MED_TYPE_WAV ||
        aud_context_p->current_format == MED_TYPE_WAV_ALAW ||
        aud_context_p->current_format == MED_TYPE_WAV_ULAW || aud_context_p->current_format == MED_TYPE_WAV_DVI_ADPCM)
    {
        kal_uint8 *header_p;
        kal_uint32 data_len;

        Media_GetFileHeader(&header_p, &aud_context_p->buf_len);
        data_len = (kal_uint32) * (header_p + 4);

        data_len += (((kal_uint32) * (header_p + 5)) << 8);
        data_len += (((kal_uint32) * (header_p + 6)) << 16);
        data_len += (((kal_uint32) * (header_p + 7)) << 24);
        /* To check the file size consistency */
        result = FS_GetFileSize(aud_context_p->current_file_handle, &len);
        if (result == FS_NO_ERROR && (data_len + 8 != aud_context_p->offset || aud_context_p->offset != len))
        {
            AUD_VALUE_TRACE(data_len + 8, aud_context_p->offset, len);
            ASSERT(data_len + 8 == aud_context_p->offset);
        }

        if (aud_context_p->buf_len > 0)
        {
            FS_Seek(aud_context_p->current_file_handle, (int)0, FS_FILE_BEGIN);
            result = FS_Write(aud_context_p->current_file_handle, header_p, aud_context_p->buf_len, &len);
            if (result != FS_NO_ERROR || len != aud_context_p->buf_len)
            {
                FS_Close(aud_context_p->current_file_handle);
                aud_context_p->current_file_handle = -1;
                return MED_RES_FAIL;
            }
        }
        else
        {
            FS_Close(aud_context_p->current_file_handle);
            aud_context_p->current_file_handle = -1;
            return MED_RES_FAIL;
        }

    }
    else if (aud_context_p->current_format == MED_TYPE_AMR || aud_context_p->current_format == MED_TYPE_AMR_WB)
    {
        /* Append null data 0x7c if not record anything. 1 byte for 20ms, put 5 bytes here.*/
        if(aud_context_p->offset == 0)
        {
            kal_uint8 null_data[5] = {0x7c,0x7c,0x7c,0x7c,0x7c};
            result = FS_Write(aud_context_p->current_file_handle, &null_data, 5, &len);
        }
    
    #ifdef DEDI_AMR_REC_BUFFER
        if (aud_context_p->amr_buffer_p)
        {
            med_free_int_mem((void **)&aud_context_p->amr_buffer_p);
        }
    #endif /* DEDI_AMR_REC_BUFFER */ 
    }
#if defined(__VOIP__)
    else if(aud_context_p->current_format == MEDIA_FORMAT_VOIPEVL)
    {
        med_free_ext_mem((void**)&aud_context_p->record_buf);
        aud_context_p->record_buf = NULL;
    }
#endif /* #if defined(__VOIP__) */
#endif /* !defined(MT6205B) && !defined(MT6208) */ 
    FS_Close(aud_context_p->current_file_handle);
    aud_context_p->current_file_handle = -1;
    return MED_RES_OK;

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_and_store_info_to_temp
 * DESCRIPTION
 *  This function is to stop media play and store play info to temp.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_and_store_info_to_temp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid other type of stop procedures */
#ifdef __MED_GENERAL_TTS__
    if (aud_context_p->source_type == AUD_TTS)
    {
        aud_tts_stop_req_hdlr(NULL);
        return;
    }
    else
#endif
    if (aud_context_p->source_type > AUD_STRING)
    {
        return;
    }

    switch (aud_context_p->current_format)
    {
    #ifdef __MED_MMA_MOD__
        case MED_TYPE_SMF:
        case MED_TYPE_SMF_SND:
            ASSERT(aud_context_p->last_handle != NULL);
            temp_last_time = JSmf_GetCurrentTime(aud_context_p->last_handle);
            JSmf_Stop(aud_context_p->last_handle);
            JSmf_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info to temp: temp_last_time = %d", temp_last_time);
            break;
        case MED_TYPE_IMELODY:
            ASSERT(aud_context_p->last_handle != NULL);
            temp_last_time = JImy_GetCurrentTime(aud_context_p->last_handle);
            JImy_Stop(aud_context_p->last_handle);
            JImy_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info to temp: temp_last_time = %d", temp_last_time);
            break;
    #endif /* __MED_MMA_MOD__ */ 

        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_DAF:
        case MED_TYPE_MUSICAM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
        case MED_TYPE_AU:
        case MED_TYPE_AIFF:
        case MED_TYPE_WMA:
        case MED_TYPE_AAC:
        case MED_TYPE_M4A:
            ASSERT(aud_context_p->last_mhdl_handle != NULL);
            temp_last_time = aud_context_p->last_mhdl_handle->GetCurrentTime(aud_context_p->last_mhdl_handle);
            temp_last_offset = aud_context_p->last_mhdl_handle->GetFileOffset(aud_context_p->last_mhdl_handle);

            aud_context_p->last_mhdl_handle->Stop(aud_context_p->last_mhdl_handle);
            aud_context_p->last_mhdl_handle->Close(aud_context_p->last_mhdl_handle);
            aud_media_close_file_handle();
            aud_context_p->last_mhdl_handle = NULL;
            aud_context_p->cache_p = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info to temp: temp_last_time = %d, temp_last_offset = %d", temp_last_time, temp_last_offset);

            break;

#if defined(MED_PURE_AUDIO)
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
            ASSERT(aud_context_p->last_mhdl_handle != NULL);
            temp_last_time = aud_context_p->last_mhdl_handle->GetCurrentTime(aud_context_p->last_mhdl_handle);
            //temp_last_offset = aud_context_p->last_mhdl_handle->GetFileOffset(aud_context_p->last_mhdl_handle);

            aud_context_p->last_mhdl_handle->Stop(aud_context_p->last_mhdl_handle);
            aud_context_p->last_mhdl_handle->Close(aud_context_p->last_mhdl_handle);
            FSAL_Close(&current_file_stream);
            aud_media_free_mp4_parser();
            
            aud_context_p->last_mhdl_handle = NULL;
            aud_context_p->cache_p = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info to temp: temp_last_time = %d, temp_last_offset = %d", temp_last_time, temp_last_offset);
            break;
#endif /* #if defined(MED_PURE_AUDIO) */

        default:
            Media_Stop();
            temp_last_offset = aud_context_p->offset - (mediaGetDataCount() << 1);
            kal_prompt_trace(
                MOD_MED,
                "stop and store info to temp: offset = %d, temp_last_offset = %d",
                aud_context_p->offset,
                temp_last_offset);
            break;
    }

    aud_context_p->last_seq_no++;
}


/*****************************************************************************
 * FUNCTION
 *  aud_stop_unfinished_process
 * DESCRIPTION
 *  This function is to stop unfinished media process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_unfinished_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        {
            /* Stop voice memo recording process */
            aud_media_stop_and_store_info_to_temp();
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
            /* stop the driver like led, backlight and vibrator */
            aud_melody_stop_driver();
            /* free file buffer */
            aud_free_melody_file_buffer();
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /* Stop voice memo recording process */
            aud_media_stop_and_store_info_to_temp();
            /* free file buffer */
            aud_free_melody_file_buffer();
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        case AUD_MEDIA_PLAY_FINISH:
        {
            /* Stop voice memo recording process */
            aud_media_stop_and_store_info_to_temp();
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        case AUD_VM_RECORD:
        case AUD_MEDIA_RECORD:
        case AUD_MEDIA_RECORD_PAUSED:
        {
            kal_uint32 len;
            kal_int32 result;

            /* Stop voice memo recording process */
            Media_Stop();

            /* Restore input source when stop recording */
            L1SP_SetInputSource(aud_context_p->input_device);

            /* Write the remaining data to file */
            Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
            ASSERT(aud_context_p->buf_p != NULL);
            //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

            result = FS_Write(
                        aud_context_p->current_file_handle,
                        aud_context_p->buf_p,
                        aud_context_p->buf_len * 2,
                        &len);

            /* update offset */
            aud_context_p->offset += len;

            Media_ReadDataDone(len >> 1);
            AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
            AUD_VALUE_TRACE(result, -1, -1);

            if (result == FS_NO_ERROR)
            {
                /* in case that encounter ring buffer boundary */
                Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
                if (aud_context_p->buf_len > 0)
                {
                    ASSERT(aud_context_p->buf_p != NULL);
                    //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

                    result = FS_Write(
                                aud_context_p->current_file_handle,
                                aud_context_p->buf_p,
                                aud_context_p->buf_len * 2,
                                &len);

                    /* update offset */
                    aud_context_p->offset += len;

                    Media_ReadDataDone(len >> 1);
                    AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
                    AUD_VALUE_TRACE(result, -1, -1);                    
                }
            }

            /* close record file, add header if wav */
            aud_close_record_file();

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_record_callback
 * DESCRIPTION
 *  This function is the callback function for recording audio.
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_callback(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_media_read_data_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_MEDIA_RECORD_CALLBACK, event, aud_record_low_priority);

    if (event == MEDIA_TERMINATED)
    {
        return;
    }

#ifndef MED_V_NOT_PRESENT
    if(aud_record_low_priority)
    {
        aud_send_med_v_read_data_ind((kal_uint8)event);
    }
    else
#endif /* #ifndef MED_V_NOT_PRESENT */    
    {
        ind_p = (aud_media_read_data_ind_struct*) construct_local_para(sizeof(aud_media_read_data_ind_struct), TD_CTRL);
        ind_p->event = event;

        aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_READ_DATA_IND, ind_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_record_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio record request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_req_struct *msg_p = NULL;
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_RECORD_REQ_HDLR);
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_media_record_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    /* if keytone is playing, stop it */
    aud_keytone_stop();

    /* if tone is playing, stop it */
    if (aud_context_p->tone_playing)
    {
        aud_tone_stop();
    }

#ifdef __MED_MMA_MOD__
    /* close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */ 

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
    if (!vid_is_audio_channel_available())
    {
        /* send confirm message to L4 */
        aud_set_result(MED_RES_BUSY);
        AUD_SET_EVENT(AUD_EVT_RECORD);
        if (aud_context_p->src_mod != MOD_MMI)
        {
            aud_send_media_record_cnf(MED_RES_BUSY);
        }
        return;
    }
#endif /* defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)*/ 

    if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
          aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
          aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
    {
        aud_stop_unfinished_process();
    }

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_IDLE:
        {
            /* Keep maximum record size and time */
            aud_context_p->size_limit = msg_p->size_limit;
            aud_context_p->time_limit = msg_p->time_limit;

            result = aud_open_record_file((kal_wchar*) msg_p->file_name, (kal_uint8) msg_p->format);
            if (result != MED_RES_OK)
            {
                aud_set_result(result);
                AUD_SET_EVENT(AUD_EVT_RECORD);
                if (aud_context_p->src_mod != MOD_MMI)
                {
                    aud_send_media_record_cnf(result);
                }
                return;
            }
            if (aud_context_p->current_file_handle >= 0)
            {
                if (!msg_p->default_input)
                {
                    L1SP_SetInputSource(custom_cfg_hw_aud_input_path(msg_p->input_source));
                    aud_context_p->use_default_input = KAL_FALSE;
                }
                else
                {
                    aud_context_p->use_default_input = KAL_TRUE;
                }

                /* Set record buffer callback threshold, 200 words (400 bytes) by system default */
                Media_SetRBThreshold(200);

                /* Set record buffer */
            #if defined(__VOIP__)
                if(aud_context_p->current_format == MEDIA_FORMAT_VOIPEVL)
                {
                    /* Use 200k buffer for VOIP raw data record */
                    aud_context_p->record_buf = (kal_uint16*)med_alloc_ext_mem( 100*1024*sizeof(kal_uint16) );
                    ASSERT(aud_context_p->record_buf != NULL);
                    Media_SetBuffer(aud_context_p->record_buf, 100*1024);
                }
                else
            #endif /* #if defined(__VOIP__)*/
                {
                    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                }

                /* Start to record, check record quality and change format or bit rate here */
                if(aud_context_p->current_format == MED_TYPE_WAV_DVI_ADPCM)
                {
                    /* Can not record 16K wave in call*/
                    if(msg_p->quality != AUD_REC_QUALITY_LOW && !aud_context_p->speech_on)
                    {
                        result = Media_Record(MEDIA_FORMAT_WAV_DVI_ADPCM_16K, aud_media_record_callback, NULL);
                    }
                    else
                    {
                        result = Media_Record(MEDIA_FORMAT_WAV_DVI_ADPCM, aud_media_record_callback, NULL);
                    }
                }
                else if(aud_context_p->current_format == MED_TYPE_AMR)
                {
                    if(msg_p->quality != AUD_REC_QUALITY_LOW)
                    {
                        result = Media_Record(MEDIA_FORMAT_AMR, aud_media_record_callback, (void*)0x03);
                    }
                    else
                    {
                        result = Media_Record(MEDIA_FORMAT_AMR, aud_media_record_callback, (void*)0x09);
                    }
                }
            #if defined(AMRWB_ENCODE)
                else if(aud_context_p->current_format == MED_TYPE_AMR_WB)
                {
                    if(msg_p->quality != AUD_REC_QUALITY_LOW)
                    {
                        result = Media_Record(MEDIA_FORMAT_AMR_WB, aud_media_record_callback, (void*)0x28);
                    }
                    else
                    {
                        result = Media_Record(MEDIA_FORMAT_AMR_WB, aud_media_record_callback, (void*)0x20);
                    }
                }
            #endif
                else
                {
                    result = Media_Record((Media_Format) aud_context_p->current_format, aud_media_record_callback, NULL);
                }

            #if !defined(__MTK_TARGET__)    /* MODIS */
                result = MEDIA_SUCCESS;
            #endif 

                /* Inform Med-V if record to low priority task */
            #if !defined(MED_V_NOT_PRESENT) && defined(__VOIP__)
                if(((aud_context_p->current_format == MEDIA_FORMAT_VOIPEVL) || AM_IsVoIPOn()) &&
                   (result == MEDIA_SUCCESS))
                {
                    aud_record_low_priority = KAL_TRUE;
                    aud_send_med_v_start_record_req();
                }
                else
            #endif /* #ifndef MED_V_NOT_PRESENT */
                {
                    aud_record_low_priority = KAL_FALSE;
                }

                if (result != MEDIA_SUCCESS)
                {
                    /* Restore input source when stop recording */
                    L1SP_SetInputSource(aud_context_p->input_device);

                #if defined(__VOIP__)
                    /* Assign buffer back to normal ring buffer */
                    if(aud_context_p->current_format == MEDIA_FORMAT_VOIPEVL)
                    {
                        med_free_ext_mem((void**)&aud_context_p->record_buf);
                        aud_context_p->record_buf = NULL;
                    }
                #endif /* #if defined(__VOIP__) */

                    /* Close file handle */
                    FS_Close(aud_context_p->current_file_handle);
                    aud_context_p->current_file_handle = -1;

                    aud_set_result(aud_get_res(result));
                    AUD_SET_EVENT(AUD_EVT_RECORD);
                    if (aud_context_p->src_mod != MOD_MMI)
                    {
                        aud_send_media_record_cnf(aud_get_res(result));
                    }
                    return;
                }

                /* reset offset */
                aud_context_p->offset = 0;

                aud_set_result(MED_RES_OK);
                AUD_SET_EVENT(AUD_EVT_RECORD);
                if (aud_context_p->src_mod != MOD_MMI)
                {
                    aud_send_media_record_cnf(MED_RES_OK);
                }

                /* enter AUD_MEDIA_RECORD state */
                AUD_ENTER_STATE(AUD_MEDIA_RECORD);
            }
            else
            {
                /* send confirm message to L4 */
                aud_set_result(MED_RES_OPEN_FILE_FAIL);
                AUD_SET_EVENT(AUD_EVT_RECORD);
                if (aud_context_p->src_mod != MOD_MMI)
                {
                    aud_send_media_record_cnf(MED_RES_OPEN_FILE_FAIL);
                }
            }

            break;
        }
        default:
        {

            /* send confirm message to L4 */
            aud_set_result(MED_RES_BUSY);
            AUD_SET_EVENT(AUD_EVT_RECORD);
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_record_cnf(MED_RES_BUSY);
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_stream_event_callback
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_stream_event_callback(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_media_play_stream_event_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p =
        (aud_media_play_stream_event_ind_struct*) construct_local_para(
                                                    sizeof(aud_media_play_stream_event_ind_struct),
                                                    TD_CTRL);

    ind_p->src_id = aud_context_p->src_id;
    ind_p->event = event;
    ind_p->seq_no = aud_context_p->last_seq_no;

    aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_PLAY_STREAM_EVENT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_byte_stream
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  data            [?]         
 *  size            [IN]        
 *  play_style      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 aud_media_play_byte_stream(kal_uint8 *data, kal_uint32 size, kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    kal_uint8 result;
    media_open_func_ptr openFunc = NULL;
    media_ctrl_func_ptr closeFunc, playFunc;
    media_set_buf_func_ptr setBufFunc;
    media_set_time_func_ptr setStartTimeFunc, setStopTimeFunc;
    Media_VM_PCM_Param vpFormat;
    void *param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(aud_context_p->state == AUD_MEDIA_IDLE);

#if !defined(__MTK_TARGET__)    /* MODIS */
    return MED_RES_OK;
#else /* !defined(__MTK_TARGET__) */ 
    /* open file for playing */
    FSAL_Direct_SetRamFileSize(&current_file_stream, size);

    if ((eFSALRet = FSAL_Open(&current_file_stream, data, FSAL_ROMFILE)) != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
    }
    else
    {
        switch (aud_context_p->current_format)
        {
            case MED_TYPE_GSM_FR:
            case MED_TYPE_GSM_HR:
            case MED_TYPE_GSM_EFR:
                vpFormat.mediaType = aud_context_p->current_format;
                vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
                param = &vpFormat;
                openFunc = VM_Open;
                break;

            case MED_TYPE_PCM_8K:
            case MED_TYPE_PCM_16K:
            case MED_TYPE_G711_ALAW:
            case MED_TYPE_G711_ULAW:
            case MED_TYPE_DVI_ADPCM:
                vpFormat.mediaType = aud_context_p->current_format;
                vpFormat.vmParam = 0;
                param = &vpFormat;
                openFunc = PCM_Open;
                break;

        #ifdef AMR_DECODE
            case MED_TYPE_AMR:
        #ifdef AMRWB_DECODE
            case MED_TYPE_AMR_WB:
        #endif 
                vpFormat.mediaType = aud_context_p->current_format;
                vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
                param = &vpFormat;
                openFunc = AMR_Open;
                break;
        #endif /* AMR_DECODE */ 
        #ifdef DAF_DECODE
            case MED_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MED_TYPE_MUSICAM:
        #endif
                openFunc = DAF_Open;
                break;
        #endif /* DAF_DECODE */ 

            case MED_TYPE_WAV:
            case MED_TYPE_WAV_ALAW:
            case MED_TYPE_WAV_ULAW:
            case MED_TYPE_WAV_DVI_ADPCM:
                openFunc = WAV_Open;
                break;

        #ifdef AU_DECODE
            case MED_TYPE_AU:
                openFunc = AU_Open;
                break;
        #endif /* AU_DECODE */
        #ifdef AIFF_DECODE
            case MED_TYPE_AIFF:
                openFunc = AIFF_Open;
                break;
        #endif /* AIFF_DECODE */
        #ifdef WMA_DECODE
            case MED_TYPE_WMA:
                openFunc = WMA_Open;
                break;
        #endif /* WMA_DECODE */ 
        #ifdef AAC_DECODE
            case MED_TYPE_AAC:
                openFunc = AAC_Open;
                break;
        #endif /* AAC_DECODE */ 
        #if defined(AAC_DECODE)
            case MED_TYPE_M4A:
                openFunc = M4A_Open;
                break;
        #endif /* defined(AAC_DECODE) */ 
            default:
                ASSERT(0);
        }

        /* No need to set buffer for ROM file */
        FSAL_SetBuffer(&current_file_stream, 0, NULL);

        if ((aud_context_p->last_mhdl_handle = openFunc(aud_media_play_stream_event_callback, &current_file_stream, param)) == NULL)
        {
            aud_media_close_file_handle();
            return MED_RES_BAD_FORMAT;
        }
        closeFunc = aud_context_p->last_mhdl_handle->Close;
        playFunc = aud_context_p->last_mhdl_handle->Play;
        setBufFunc = aud_context_p->last_mhdl_handle->SetBuffer;
        setStartTimeFunc = aud_context_p->last_mhdl_handle->SetStartTime;
        setStopTimeFunc = aud_context_p->last_mhdl_handle->SetStopTime;

        /* call L1AUD to set buffer */
        setBufFunc(aud_context_p->last_mhdl_handle, (kal_uint8*) aud_context_p->ring_buf, AUD_RING_BUFFER_LEN * 2);

        aud_melody_play_style_convert(play_style);

    #ifdef __MED_BT_A2DP_MOD__
    #if defined(__BTMTK__)
        aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
    #endif
    #endif /* __MED_BT_A2DP_MOD__ */ 

        /* Play string portion */
        if (aud_context_p->start_offset != 0)
        {
            setStartTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->start_offset);
        }
        if (aud_context_p->end_offset != 0)
        {
            setStopTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->end_offset);
        }

        if ((result = playFunc(aud_context_p->last_mhdl_handle)) != MEDIA_SUCCESS)
        {
            closeFunc(aud_context_p->last_mhdl_handle);
            aud_media_close_file_handle();

            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            return aud_get_res(result);
        }

        result = MED_RES_OK;
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    }
    return result;

#endif /* !defined(__MTK_TARGET__) */ /* #if !defined(__MTK_TARGET__) */

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_file_stream
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  file_name       [?]         
 *  play_style      [IN]        
 *  first_time      [IN]        
 *  resume          [IN]
 *  cache_p         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 aud_media_play_file_stream(
    kal_wchar *file_name,
    kal_uint8 play_style, 
    kal_uint8 first_time,
    kal_bool resume,
    void* cache_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    kal_uint8 result;
    media_open_func_ptr openFunc = NULL;
    media_ctrl_func_ptr closeFunc, playFunc;
    media_set_buf_func_ptr setBufFunc;
    media_set_time_func_ptr setStartTimeFunc, setStopTimeFunc;
    Media_VM_PCM_Param vpFormat;
    void *param = NULL;
    kal_uint8 *pbFSALBuf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(aud_context_p->state == AUD_MEDIA_IDLE);

#if !defined(__MTK_TARGET__)    /* MODIS */
    return MED_RES_OK;
#else /* !defined(__MTK_TARGET__) */ 
    /* open file for playing */
    if ((eFSALRet = FSAL_Open(&current_file_stream, file_name, FSAL_READ)) != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
    }
    else
    {
        switch (aud_context_p->current_format)
        {
            case MED_TYPE_GSM_EFR:
            case MED_TYPE_VR:
                vpFormat.mediaType = aud_context_p->current_format;
                vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
                param = &vpFormat;
                openFunc = VM_Open;
                break;

            case MED_TYPE_PCM_8K:
            case MED_TYPE_PCM_16K:
            case MED_TYPE_DVI_ADPCM:
                vpFormat.mediaType = aud_context_p->current_format;
                vpFormat.vmParam = 0;
                param = &vpFormat;
                openFunc = PCM_Open;
                break;

        #ifdef AMR_DECODE
            case MED_TYPE_AMR:
        #ifdef AMRWB_DECODE
            case MED_TYPE_AMR_WB:
        #endif 
                vpFormat.mediaType = aud_context_p->current_format;
                vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
                param = &vpFormat;
                openFunc = AMR_Open;
                break;
        #endif /* AMR_DECODE */ 
        #ifdef DAF_DECODE
            case MED_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MED_TYPE_MUSICAM:
        #endif
                openFunc = DAF_Open;
                break;
        #endif /* DAF_DECODE */ 
            case MED_TYPE_WAV:
            case MED_TYPE_WAV_DVI_ADPCM:
                openFunc = WAV_Open;
                break;

        #ifdef AU_DECODE
            case MED_TYPE_AU:
                openFunc = AU_Open;
                break;
        #endif /* AU_DECODE */
        #ifdef AIFF_DECODE
            case MED_TYPE_AIFF:
                openFunc = AIFF_Open;
                break;
        #endif /* AIFF_DECODE */
        #ifdef WMA_DECODE
            case MED_TYPE_WMA:
                openFunc = WMA_Open;
                break;
        #endif /* WMA_DECODE */ 
        #ifdef AAC_DECODE
            case MED_TYPE_AAC:
                openFunc = AAC_Open;
                break;
        #endif /* AAC_DECODE */ 
        #if defined(AAC_DECODE)
            case MED_TYPE_M4A:
                openFunc = M4A_Open;
                break;
        #endif /* defined(AAC_DECODE) */ 
            default:
                ASSERT(0);
        }

        /* Set Buffer for file */
    #if defined(AUD_PROC_USE_EXT_MEM)
        //pbFSALBuf = (kal_uint8*) med_alloc_ext_mem(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
        pbFSALBuf = &med_aud_fasl_buf[0];
    #else 
        pbFSALBuf = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #endif 

        FSAL_SetBuffer(&current_file_stream, AUD_PROC_BUF_SIZE, pbFSALBuf);

        if ((aud_context_p->last_mhdl_handle = openFunc(aud_media_play_stream_event_callback, &current_file_stream, param)) == NULL)
        {
            aud_media_close_file_handle();
            return MED_RES_BAD_FORMAT;
        }

        if( cache_p != NULL )
            aud_context_p->last_mhdl_handle->SetCacheTbl( 
                aud_context_p->last_mhdl_handle, cache_p, NULL );
        
        closeFunc = aud_context_p->last_mhdl_handle->Close;
        playFunc = aud_context_p->last_mhdl_handle->Play;
        setBufFunc = aud_context_p->last_mhdl_handle->SetBuffer;
        setStartTimeFunc = aud_context_p->last_mhdl_handle->SetStartTime;
        setStopTimeFunc = aud_context_p->last_mhdl_handle->SetStopTime;

        /* call L1AUD to set buffer */
        setBufFunc(aud_context_p->last_mhdl_handle, (kal_uint8*) aud_context_p->ring_buf, AUD_RING_BUFFER_LEN * 2);

        if (first_time)
        {
            /* follow ring tone volume */
            aud_set_active_ring_tone_volume();
            /* To start ascending timer */
            aud_melody_play_style_convert(play_style);
        }

        if (resume)
        {
            /* Use file offset directly to just to fast restore*/
            aud_context_p->last_mhdl_handle->SetStoreFlag(aud_context_p->last_mhdl_handle, KAL_TRUE);
            setStartTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->last_time);
            aud_context_p->last_mhdl_handle->SetFileOffset(aud_context_p->last_mhdl_handle, aud_context_p->last_offset);
        }
        else    /* Play file portion */
        {
            /* Not a restore action, need to seek again.*/        
            aud_context_p->last_mhdl_handle->SetStoreFlag(aud_context_p->last_mhdl_handle, KAL_FALSE);        
            if (aud_context_p->start_offset != 0)
            {
                setStartTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->start_offset);
            }
            if (aud_context_p->end_offset != 0)
            {
                setStopTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->end_offset);
            }
        }

    #ifdef __MED_BT_A2DP_MOD__
    #if defined(__BTMTK__)
        aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
    #endif
    #endif /* __MED_BT_A2DP_MOD__ */ 

        aud_context_p->cache_p = cache_p;

        result = playFunc(aud_context_p->last_mhdl_handle);

        if (result != MEDIA_SUCCESS /* && result != MEDIA_SEEK_FAIL */ )
        {
            closeFunc(aud_context_p->last_mhdl_handle);
            aud_media_close_file_handle();

            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            aud_context_p->cache_p = NULL;

            return aud_get_res(result);
        }

        result = MED_RES_OK;
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    }
    return result;

#endif /* !defined(__MTK_TARGET__) */ /* #if !defined(__MTK_TARGET__) */

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_replay_by_handle
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  play_style      [IN]        
 *  replay          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 aud_media_replay_by_handle(kal_uint8 play_style, kal_bool replay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;
    media_ctrl_func_ptr closeFunc, playFunc;
    media_set_time_func_ptr setStartTimeFunc, setStopTimeFunc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    closeFunc = aud_context_p->last_mhdl_handle->Close;
    playFunc = aud_context_p->last_mhdl_handle->Play;
    setStartTimeFunc = aud_context_p->last_mhdl_handle->SetStartTime;
    setStopTimeFunc = aud_context_p->last_mhdl_handle->SetStopTime;

    if (replay)
    {
        /* follow ring tone volume */
        aud_set_active_ring_tone_volume();
        /* To start ascending timer */
        aud_melody_start_crescendo(play_style);

        setStartTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->start_offset);

        if (aud_context_p->end_offset != 0)
        {
            setStopTimeFunc(aud_context_p->last_mhdl_handle, aud_context_p->end_offset);
        }
    }

    result = playFunc(aud_context_p->last_mhdl_handle);

    if (result != MEDIA_SUCCESS /* && result != MEDIA_SEEK_FAIL */ )
    {
        closeFunc(aud_context_p->last_mhdl_handle);
        aud_media_close_file_handle();

        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);

        return aud_get_res(result);
    }

    AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_pause_file_stream
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  res     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_media_pause_file_stream(kal_uint8 *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;
    media_ctrl_func_ptr pauseFunc, closeFunc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->current_format)
    {
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_DAF:
        case MED_TYPE_MUSICAM:            
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
        case MED_TYPE_AU:
        case MED_TYPE_AIFF:
        case MED_TYPE_AAC:
        case MED_TYPE_WMA:
        case MED_TYPE_M4A:
            break;

    #if defined(MED_PURE_AUDIO)
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
            return aud_media_pause_audio_track_in_video(&res);
            break;
    #endif /* #if defined(MED_PURE_AUDIO) */
    
        default:
            return KAL_FALSE;
    }

    pauseFunc = aud_context_p->last_mhdl_handle->Pause;
    closeFunc = aud_context_p->last_mhdl_handle->Close;

    result = pauseFunc(aud_context_p->last_mhdl_handle);

    if (result == MEDIA_SUCCESS)
    {
        *res = MED_RES_OK;
        AUD_ENTER_STATE(AUD_MEDIA_PLAY_PAUSED);
    }
    else if (result == MEDIA_UNSUPPORTED_OPERATION)
    {
        *res = MED_RES_UNSUPPORTED_OPERATION;
    }
    else
    {
        /* close handle */
        closeFunc(aud_context_p->last_mhdl_handle);
        aud_media_close_file_handle();
        aud_context_p->last_mhdl_handle = NULL;

        AUD_ENTER_STATE(AUD_MEDIA_IDLE);

        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);

        *res = aud_get_res((kal_uint8) result);

        aud_context_p->last_mhdl_handle = NULL;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_resume_file_stream
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  res     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_media_resume_file_stream(kal_uint8 *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;
    media_ctrl_func_ptr resumeFunc, closeFunc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->current_format)
    {
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_DAF:
        case MED_TYPE_MUSICAM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
        case MED_TYPE_AU:
        case MED_TYPE_AIFF:
        case MED_TYPE_AAC:
        case MED_TYPE_WMA:
        case MED_TYPE_M4A:
            break;

    #if defined(MED_PURE_AUDIO)
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
            return aud_media_resume_audio_track_in_video(&res);
            break;
    #endif /* #if defined(MED_PURE_AUDIO) */

        default:
            return KAL_FALSE;
    }

    /* Seek while paused state, need to replay again for resume */
    if (aud_context_p->state == AUD_MEDIA_SEEK_PAUSED)
    {
        *res = aud_media_replay_by_handle(0, KAL_FALSE);
        return KAL_TRUE;
    }

#if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
    aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
#endif
    /* Resume from paused state */
    resumeFunc = aud_context_p->last_mhdl_handle->Resume;
    closeFunc = aud_context_p->last_mhdl_handle->Close;

    result = resumeFunc(aud_context_p->last_mhdl_handle);

    if (result == MEDIA_SUCCESS)
    {
        *res = MED_RES_OK;
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    }
    else
    {
        /* close handle */
        closeFunc(aud_context_p->last_mhdl_handle);
        aud_media_close_file_handle();
        aud_context_p->last_mhdl_handle = NULL;

        AUD_ENTER_STATE(AUD_MEDIA_IDLE);

        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);

        *res = aud_get_res((kal_uint8) result);
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_process_file_stream
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_media_process_file_stream(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Event result;
    kal_uint8 replay_result = MED_RES_FAIL;
    media_proc_func_ptr procFunc;
    media_ctrl_func_ptr stopFunc, closeFunc;
    kal_uint8 res;
    aud_media_play_stream_event_ind_struct *ind_p = (aud_media_play_stream_event_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->last_seq_no != ind_p->seq_no ||
        (aud_context_p->state != AUD_MEDIA_PLAY && aud_context_p->state != AUD_MEDIA_PLAY_PAUSED))
    {
        AUD_VALUE_TRACE(ind_p->seq_no, aud_context_p->last_seq_no, aud_context_p->state);
        return KAL_FALSE;
    }

#if defined(MED_PURE_AUDIO)
    /* Handle video's pure audio file differently */
    if(aud_context_p->current_format == MED_TYPE_3GP ||
       aud_context_p->current_format == MED_TYPE_MP4)
    {
        return aud_media_process_audio_track_in_video(ind_p->event);
    }
#endif /* #if defined(MED_PURE_AUDIO) */

    /* Handle traditional audio type here */
    switch (aud_context_p->current_format)
    {
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_DAF:
        case MED_TYPE_MUSICAM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
        case MED_TYPE_AU:
        case MED_TYPE_AIFF:
        case MED_TYPE_AAC:
        case MED_TYPE_WMA:
        case MED_TYPE_M4A:
            break;

        default:
            return KAL_FALSE;
    }

    procFunc = aud_context_p->last_mhdl_handle->Process;
    stopFunc = aud_context_p->last_mhdl_handle->Stop;
    closeFunc = aud_context_p->last_mhdl_handle->Close;

    if (aud_context_p->state == AUD_MEDIA_PLAY)
    {
        result = procFunc(aud_context_p->last_mhdl_handle, (Media_Event) ind_p->event);

        AUD_VALUE_TRACE(result, __LINE__, -1);

        /*update duration*/
        if(result == MEDIA_UPDATE_DUR)
        {
            kal_uint32 duration;
            if(aud_context_p->cache_p == NULL)
            {
                return KAL_TRUE;
            }
            switch(aud_context_p->current_format)
            {
                case MED_TYPE_AMR:
                case MED_TYPE_AMR_WB:
                case MED_TYPE_DAF:
                case MED_TYPE_MUSICAM:
                case MED_TYPE_AAC:
                    duration = aud_context_p->last_mhdl_handle->GetTotalDuration(aud_context_p->last_mhdl_handle);
                    break;
                default:
                    return KAL_TRUE;
            }
            aud_send_update_duration_ind(duration);
            return KAL_TRUE;
        }

        if (result != MEDIA_NONE)
        {
            /* Enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);

            /* Stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            /* Stop play */
            temp_last_time = aud_context_p->last_mhdl_handle->GetCurrentTime(aud_context_p->last_mhdl_handle);
            stopFunc(aud_context_p->last_mhdl_handle);

            aud_context_p->last_seq_no++;

            /* Play again */
            if ((result == MEDIA_END || result == MEDIA_STOP_TIME_UP) && (aud_context_p->play_style != DEVICE_AUDIO_PLAY_ONCE))
            {
                replay_result = aud_media_replay_by_handle(aud_context_p->play_style, KAL_TRUE);
            }
            else    /* No replay, clost it */
            {
                closeFunc(aud_context_p->last_mhdl_handle);
                aud_media_close_file_handle();
                aud_context_p->last_mhdl_handle = NULL;
                aud_context_p->cache_p = NULL;
            }

            AUD_VALUE_TRACE(result, replay_result, aud_context_p->play_style);

            /* No replay or replay fail, send finish indication message */
            if (replay_result != MED_RES_OK)
            {
                if ((result == MEDIA_END || result == MEDIA_STOP_TIME_UP) && (aud_context_p->play_style == DEVICE_AUDIO_PLAY_ONCE))
                {
                    res = MED_RES_END_OF_FILE;
                }
                else if(result == MEDIA_DECODER_UNSUPPORT)
                {
                    res = MED_RES_DECODER_NOT_SUPPORT;
                }
                else
                {
                    res = MED_RES_ERROR;
                }

                if (aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_RING)
                {
                    aud_send_audio_play_finish_ind(res);
                }
                else
                {
                    aud_send_media_play_finish_ind(res);
                }
            }
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio play request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;
    l4aud_media_play_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_PLAY_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_media_play_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    if (aud_context_p->speech_on
    #if defined(__MED_VID_MOD__)  || defined(__MED_MJPG_MOD__)
        || !vid_is_audio_channel_available()
    #endif 
        )
    {
        aud_set_result(MED_RES_BUSY);
        AUD_SET_EVENT(AUD_EVT_PLAY);
        if (aud_context_p->src_mod != MOD_MMI)
        {
            aud_send_media_play_cnf(MED_RES_BUSY);
        }
    }
    else
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        /* if tone is playing, stop it */
        if (aud_context_p->tone_playing)
        {
            aud_tone_stop();
        }

    #ifdef __MED_MMA_MOD__
        /* close all mma tasks */
        aud_mma_close_all();
    #endif /* __MED_MMA_MOD__ */ 

        if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
              aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
              aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
        {
            aud_stop_unfinished_process();

            aud_context_p->play_mode = AUD_MEDIA_PLAY_AS_SONG;

            /* set volume and path */
            SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, msg_p->volume);
            aud_context_p->melody_output_device = msg_p->output_path;

            aud_get_active_device_path_by_mode(msg_p->output_path,aud_melody_set_output_device);

            aud_context_p->current_format = med_get_media_type(msg_p->file_name);
            aud_context_p->identifier = msg_p->identifier;
            aud_context_p->start_offset = msg_p->start_offset;
            aud_context_p->end_offset = msg_p->end_offset;
            switch (aud_context_p->current_format)
            {
                case MED_TYPE_SMF:
                case MED_TYPE_SMF_SND:
                case MED_TYPE_IMELODY:
                case MED_TYPE_MMF:
                    result = aud_melody_play_by_name(msg_p->file_name, msg_p->play_style, 0);
                    break;

            #ifdef DAF_DECODE
                case MED_TYPE_DAF:
            #ifdef MUSICAM_DECODE
                case MED_TYPE_MUSICAM:
            #endif 
            #endif /*DAF_DECODE*/
            #ifdef AMR_DECODE
                case MED_TYPE_AMR:
            #ifdef AMRWB_DECODE
                case MED_TYPE_AMR_WB:
            #endif 
            #endif /* AMR_DECODE */ 
                case MED_TYPE_GSM_EFR:
                case MED_TYPE_PCM_8K:
                case MED_TYPE_PCM_16K:
                case MED_TYPE_DVI_ADPCM:
                case MED_TYPE_WAV:
                case MED_TYPE_WAV_DVI_ADPCM:
            #ifdef AIFF_DECODE
                case MED_TYPE_AIFF:
            #endif
            #ifdef AU_DECODE
                case MED_TYPE_AU:
            #endif
            #ifdef AAC_DECODE
                case MED_TYPE_AAC:
            #endif 
            #ifdef WMA_DECODE
                case MED_TYPE_WMA:
            #endif 
            #if defined(AAC_DECODE)
                case MED_TYPE_M4A:
            #endif 
                    aud_context_p->source_type = AUD_FILE;
                    aud_context_p->play_style = msg_p->play_style;
                    result = aud_media_play_file_stream(
                        msg_p->file_name,
                        msg_p->play_style,
                        1,
                        KAL_FALSE,
                        msg_p->cache_p);
                    break;

            #if defined(MED_PURE_AUDIO)
                case MED_TYPE_3GP:
                case MED_TYPE_MP4:
                    aud_context_p->source_type = AUD_FILE;
                    aud_context_p->play_style = msg_p->play_style;

                    result = aud_media_play_audio_track_in_video(
                        msg_p->file_name,
                        msg_p->play_style,
                        KAL_TRUE,
                        KAL_FALSE);
                    break;
            #endif /*defined(MED_PURE_AUDIO)*/

                default:
                    result = MED_RES_INVALID_FORMAT;
                    break;

            }
            aud_set_result((kal_int32) result);
            AUD_SET_EVENT(AUD_EVT_PLAY);
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_play_cnf(result);
            }
        }
        else
        {
            aud_set_result((kal_int32) MED_RES_BUSY);
            AUD_SET_EVENT(AUD_EVT_PLAY);
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_play_cnf(MED_RES_BUSY);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_record
 * DESCRIPTION
 * 
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_int32 result;
    kal_uint8 res;
    kal_uint8 cnf_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VALUE_TRACE(255, aud_context_p->state, __LINE__);

    if(aud_context_p->state == AUD_VM_RECORD ||
       aud_context_p->state == AUD_MEDIA_RECORD ||
       aud_context_p->state == AUD_MEDIA_RECORD_PAUSED)
    {
        #if !defined(__MTK_TARGET__)    /* MODIS */
            FS_Close(aud_context_p->current_file_handle);

            /* set event to let caller go */
            AUD_SET_EVENT(AUD_EVT_STOP);

            /* send confirm message to L4 */
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_stop_cnf(MED_RES_OK, NULL);
            }

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            return;
        #endif /* !defined(__MTK_TARGET__) */ 

        /* Stop voice memo recording process */
        Media_Stop();

        /* Restore input source when stop recording */
        L1SP_SetInputSource(aud_context_p->input_device);

        /* Write the remaining data to file */
        Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
        ASSERT(aud_context_p->buf_p != NULL);
        //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

        result = FS_Write(
                    aud_context_p->current_file_handle,
                    aud_context_p->buf_p,
                    aud_context_p->buf_len * 2,
                    &len);

        /* update offset */
        aud_context_p->offset += len;

        Media_ReadDataDone(len >> 1);
        AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
        AUD_VALUE_TRACE(result, -1, -1);

        if (result == FS_NO_ERROR)
        {
            /* in case that encounter ring buffer boundary */
            Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
            if (aud_context_p->buf_len > 0)
            {
                ASSERT(aud_context_p->buf_p != NULL);
                ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

                result = FS_Write(
                            aud_context_p->current_file_handle,
                            aud_context_p->buf_p,
                            aud_context_p->buf_len * 2,
                            &len);

                /* update offset */
                aud_context_p->offset += len;

                Media_ReadDataDone(len >> 1);
                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
                AUD_VALUE_TRACE(result, -1, -1);

                if (result == FS_NO_ERROR)
                {
                    cnf_result = MED_RES_OK;
                }
                else if (result == FS_DISK_FULL)
                {
                    cnf_result = MED_RES_DISC_FULL;
                    /* set disc full to TRUE */
                    aud_context_p->disc_full = KAL_TRUE;
                }
                else
                {
                    cnf_result = MED_RES_FAIL;
                }
            }
            else
            {
                cnf_result = MED_RES_OK;
            }
        }
        else if (result == FS_DISK_FULL)
        {
            cnf_result = MED_RES_DISC_FULL;
            /* set disc full to TRUE */
            aud_context_p->disc_full = KAL_TRUE;
        }
        else
        {
            cnf_result = MED_RES_FAIL;
        }

        /* close record file, add header if wav */
        res = aud_close_record_file();

        /* set event to let caller go */
        AUD_SET_EVENT(AUD_EVT_STOP);

        if (res == MED_RES_FAIL)
        {
            cnf_result = MED_RES_FAIL;
        }

        /* send confirm message to L4 */
        if (aud_context_p->src_mod != MOD_MMI)
        {
            aud_send_media_stop_cnf(cnf_result, aud_context_p->current_file_name);
        }

        /* enter AUD_MEDIA_IDLE state */
        AUD_ENTER_STATE(AUD_MEDIA_IDLE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio stop request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        case AUD_MEDIA_RECORD:
        case AUD_MEDIA_RECORD_PAUSED:
        {
        #ifndef MED_V_NOT_PRESENT
            if(aud_record_low_priority)
            {
                aud_send_med_v_stop_record_req();
            }
            else
        #endif /* #ifndef MED_V_NOT_PRESENT */
            {
                aud_media_stop_record();
            }
            break;
        }
        case AUD_MEDIA_PLAY:
        {
            /* Stop */
            aud_media_stop_and_store_info_to_temp();
            /* stop the driver like led, backlight and vibrator */
            aud_melody_stop_driver();
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
            /* free file buffer */
            aud_free_melody_file_buffer();
            /* set event to let caller go */
            AUD_SET_EVENT(AUD_EVT_STOP);

            /* send confirm message to L4 */
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);
            }

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /* Stop */
            aud_media_stop_and_store_info_to_temp();
            /* free file buffer */
            aud_free_melody_file_buffer();
            /* set event to let caller go */
            AUD_SET_EVENT(AUD_EVT_STOP);

            /* send confirm message to L4 */
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);
            }

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        case AUD_MEDIA_PLAY_FINISH:
        {
            /* stop the play, in case too many data in the buffer */
            aud_media_stop_and_store_info_to_temp();

            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            /* set event to let caller go */
            AUD_SET_EVENT(AUD_EVT_STOP);

            /* send confirm message to L4 */
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);
            }

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }
        default:
        {
            /* Media_Stop(); */

            /* set event to let caller go */
            AUD_SET_EVENT(AUD_EVT_STOP);

            /* send confirm message to L4 */
            if (aud_context_p->src_mod != MOD_MMI)
            {
                aud_send_media_stop_cnf(MED_RES_OK, NULL);
            }

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            break;
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_close_file_handle
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_close_file_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_file_stream.bBuffering && current_file_stream.pbBuf != NULL)
    {
    #if defined(AUD_PROC_USE_EXT_MEM)
        //med_free_ext_mem((void **)&(current_file_stream.pbBuf));
    #else 
        free_ctrl_buffer((void*)current_file_stream.pbBuf);
    #endif 
    }

    result = FSAL_Close(&current_file_stream);
    AUD_VALUE_TRACE(result, -1, -1);
    memset(&current_file_stream, 0, sizeof(STFSAL));
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_pause_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio pause request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_int32 result;
    kal_uint8 res;
    l4aud_media_pause_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_PAUSE_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_media_pause_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_RECORD:
        {
        #if !defined(__MTK_TARGET__)    /* MODIS */
            res = MED_RES_OK;
            AUD_SET_EVENT(AUD_EVT_PAUSE);
            aud_send_media_pause_cnf(MED_RES_OK, NULL);
            AUD_ENTER_STATE(AUD_MEDIA_RECORD_PAUSED);
        #else /* !defined(__MTK_TARGET__) */ 

        #ifndef MED_V_NOT_PRESENT
            if(aud_record_low_priority)
            {
                aud_send_med_v_pause_record_req();
                return;
            }
            else
        #endif /* #ifndef MED_V_NOT_PRESENT */
            {
                res = aud_get_res(Media_Pause());

                /* Write the remaining data to file */
                Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
                ASSERT(aud_context_p->buf_p != NULL);
                //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

                result = FS_Write(
                            aud_context_p->current_file_handle,
                            aud_context_p->buf_p,
                            aud_context_p->buf_len * 2,
                            &len);

                /* update offset */
                aud_context_p->offset += len;

                Media_ReadDataDone(len >> 1);
                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
                AUD_VALUE_TRACE(result, -1, -1);

                if (result == MED_RES_OK)
                {
                    AUD_ENTER_STATE(AUD_MEDIA_RECORD_PAUSED);
                }
                else
                {
                    /* inform L1AUD to stop recording process */
                    Media_Stop();

                    /* close record file, add header if wav */
                    aud_close_record_file();

                    /* delete empty file */
                    if (aud_context_p->offset == 0)
                    {
                        FS_Delete(aud_context_p->current_file_name);
                    }

                    if (result == FS_DISK_FULL)
                    {
                        res = MED_RES_DISC_FULL;
                    }
                    else
                    {
                        res = MED_RES_FAIL;
                    }

                    /* enter AUD_MEDIA_IDLE state */
                    AUD_ENTER_STATE(AUD_MEDIA_IDLE);
                }
            }
        #endif /* !defined(__MTK_TARGET__) */ 
            break;
        }
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_FINISH:
        {
            /* Pause the playing process for stream type audio */
            if (aud_media_pause_file_stream(&res))
            {
                goto pause_finished;
            }

            /* Pause the playing process for non-stream type audio */
        #ifdef __MED_MMA_MOD__
            res = aud_get_res((kal_uint8) aud_melody_pause());
        #else 
            res = aud_get_res((kal_uint8) Media_Pause());
        #endif 

            aud_store_driver_status();
            aud_melody_stop_driver();

            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            if (res == MED_RES_OK)
            {
                AUD_ENTER_STATE(AUD_MEDIA_PLAY_PAUSED);
            }
            else if (res != MED_RES_UNSUPPORTED_OPERATION)
            {
            #ifdef __MED_MMA_MOD__
                aud_melody_close_handle();
            #endif 
                /* free file buffer */
                aud_free_melody_file_buffer();

                AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            }
            break;
        }
        default:
        {
            res = MED_RES_FAIL;
            break;
        }

    }
  pause_finished:
    aud_set_result((kal_int32) res);
    AUD_SET_EVENT(AUD_EVT_PAUSE);
    /* send confirm message to L4/MMI */
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_pause_cnf(res, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_resume_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio resume request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    l4aud_media_resume_req_struct *msg_p = NULL;
    kal_uint8 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_MEDIA_RESUME_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_media_resume_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_RECORD_PAUSED:
        {
        #ifndef MED_V_NOT_PRESENT        
            if(aud_record_low_priority)
            {
                aud_send_med_v_resume_record_req();
                return;
            }
            else
        #endif /* #ifndef MED_V_NOT_PRESENT */
            {
                /* start to resume */
                res = aud_get_res((kal_uint8) Media_Resume());

                if (res == MED_RES_OK)
                {
                    /* enter AUD_MEDIA_RECORD state */
                    AUD_ENTER_STATE(AUD_MEDIA_RECORD);
                }
                else
                {
                    /* enter AUD_MEDIA_IDLE state */
                    AUD_ENTER_STATE(AUD_MEDIA_IDLE);
                }
            }
            break;
        }
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {

            /* Resume from pause for stream type audio */
            if ((aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_SONG) && aud_media_resume_file_stream(&res))
            {
                goto resume_finished;
            }

            /* This is the case for midi or imy play not streaming play */
            {
                /* restore driver status */
                aud_restore_driver_status();

                /* start to resume */
            #ifdef __MED_MMA_MOD__
                res = aud_get_res((kal_uint8) aud_melody_resume());
            #else 
                res = aud_get_res((kal_uint8) Media_Resume());
            #endif 

                if (res == MED_RES_OK)
                {
                    /* enter AUD_MEDIA_PLAY state */
                    AUD_ENTER_STATE(AUD_MEDIA_PLAY);
                }
                else
                {
                #ifdef __MED_MMA_MOD__
                    aud_melody_close_handle();
                #endif 
                    /* stop drivers */
                    aud_melody_stop_driver();
                    /* free file buffer */
                    aud_free_melody_file_buffer();
                    /* enter AUD_MEDIA_IDLE state */
                    AUD_ENTER_STATE(AUD_MEDIA_IDLE);
                }
            }
            break;
        }
        default:
        {
            res = MED_RES_FAIL;
            break;
        }
    }
  resume_finished:
    aud_set_result((kal_int32) res);
    AUD_SET_EVENT(AUD_EVT_RESUME);
    if (aud_context_p->src_mod != MOD_MMI)
    {
        aud_send_media_resume_cnf(res);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_and_store_info
 * DESCRIPTION
 *  This function is to stop media play and store play info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_and_store_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid other type of stop procedures */
    if (aud_context_p->source_type > AUD_STRING)
    {
        return;
    }

    switch (aud_context_p->current_format)
    {
    #ifdef __MED_MMA_MOD__
        case MED_TYPE_SMF:
        case MED_TYPE_SMF_SND:
            ASSERT(aud_context_p->last_handle != NULL);
            aud_context_p->last_time = temp_last_time = (kal_uint32) JSmf_GetCurrentTime(aud_context_p->last_handle);
            JSmf_Stop(aud_context_p->last_handle);
            JSmf_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info: temp_last_time = %d", temp_last_time);
            break;
        case MED_TYPE_IMELODY:
            ASSERT(aud_context_p->last_handle != NULL);
            aud_context_p->last_time = temp_last_time = (kal_uint32) JImy_GetCurrentTime(aud_context_p->last_handle);
            JImy_Stop(aud_context_p->last_handle);
            JImy_Close(aud_context_p->last_handle);
            aud_context_p->last_handle = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info: temp_last_time = %d", temp_last_time);
            break;
    #endif /* __MED_MMA_MOD__ */ 

        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_VR:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_DAF:
        case MED_TYPE_MUSICAM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_DVI_ADPCM:
        case MED_TYPE_AU:
        case MED_TYPE_AIFF:
        case MED_TYPE_WMA:
        case MED_TYPE_AAC:
        case MED_TYPE_M4A:
            ASSERT(aud_context_p->last_mhdl_handle != NULL);
            aud_context_p->last_time = temp_last_time =
                aud_context_p->last_mhdl_handle->GetCurrentTime(aud_context_p->last_mhdl_handle);
            /* Keep file offset for later fast restore */
            aud_context_p->last_offset = temp_last_offset =
                aud_context_p->last_mhdl_handle->GetFileOffset(aud_context_p->last_mhdl_handle);
           
            aud_context_p->last_mhdl_handle->Stop(aud_context_p->last_mhdl_handle);
            aud_context_p->last_mhdl_handle->Close(aud_context_p->last_mhdl_handle);
            aud_media_close_file_handle();
            aud_context_p->last_mhdl_handle = NULL;
            aud_context_p->cache_p = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info: temp_last_time = %d, temp_last_offset = %d", temp_last_time, temp_last_offset);
            break;

#if defined(MED_PURE_AUDIO)
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
            ASSERT(aud_context_p->last_mhdl_handle != NULL);
            aud_context_p->last_time = temp_last_time =
                aud_context_p->last_mhdl_handle->GetCurrentTime(aud_context_p->last_mhdl_handle);
           
            aud_context_p->last_mhdl_handle->Stop(aud_context_p->last_mhdl_handle);
            aud_context_p->last_mhdl_handle->Close(aud_context_p->last_mhdl_handle);
            FSAL_Close(&current_file_stream);
            aud_media_free_mp4_parser();
            aud_context_p->last_mhdl_handle = NULL;
            aud_context_p->cache_p = NULL;
            kal_prompt_trace(MOD_MED, "stop and store info: temp_last_time = %d, temp_last_offset = %d", temp_last_time, temp_last_offset);
            break;
#endif /* #if defined(MED_PURE_AUDIO) */

        default:
            Media_Stop();
            kal_prompt_trace(
                MOD_MED,
                "stop and store info: offset = %d, temp_last_offset = %d",
                aud_context_p->offset,
                temp_last_offset);
            break;
    }

    aud_context_p->last_seq_no++;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_store_info_from_temp
 * DESCRIPTION
 *  This function is to store play info from temp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_store_info_from_temp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->last_time = temp_last_time;
    /* Keep file offset for later fast restore */
    aud_context_p->last_offset = temp_last_offset;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_store_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio pause request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_store_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 res;
    l4aud_media_store_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_media_store_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        {
            /* Stop voice memo recording process */
            aud_media_stop_and_store_info();
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
            /* stop the driver like led, backlight and vibrator */
            aud_melody_stop_driver();
            /* free file buffer */
            aud_free_melody_file_buffer();
            /* set event to let caller go */
            /* AUD_SET_EVENT(AUD_EVT_STOP); */
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            res = MED_RES_OK;
            break;
        }
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_SEEK_PAUSED:
        {
            /* Stop voice memo recording process */
            aud_media_stop_and_store_info();
            /* free file buffer */
            aud_free_melody_file_buffer();
            /* set event to let caller go */
            /* AUD_SET_EVENT(AUD_EVT_STOP); */

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            res = MED_RES_OK;
            break;
        }
        case AUD_MEDIA_PLAY_FINISH:
        {
            /* stop the play, in case too many data in the buffer */
            aud_media_stop_and_store_info();
            /* stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);
            /* set event to let caller go */
            /* AUD_SET_EVENT(AUD_EVT_STOP); */
            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            res = MED_RES_END_OF_FILE;
            break;
        }
        case AUD_MEDIA_IDLE:
        {
            aud_media_store_info_from_temp();
            /* set event to let caller go */
            /* AUD_SET_EVENT(AUD_EVT_STOP); */
            res = MED_RES_OK;
            break;
        }
        default:
        {
            /* Stop voice memo recording process */
            Media_Stop();

            /* set event to let caller go */
            /* AUD_SET_EVENT(AUD_EVT_STOP); */

            /* enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            res = MED_RES_FAIL;
            break;
        }

    }
    aud_set_result((kal_int32) res);
    AUD_SET_EVENT(AUD_EVT_PAUSE);
    /* send confirm message to L4/MMI */

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_restore_req_hdlr
 * DESCRIPTION
 *  This function is to handle the audio resume request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_restore_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    l4aud_media_restore_req_struct *msg_p = NULL;
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_media_restore_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    if (aud_context_p->speech_on)
    {
        aud_set_result(MED_RES_BUSY);
        AUD_SET_EVENT(AUD_EVT_RESUME);
    }
    else
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        /* if tone is playing, stop it */
        if (aud_context_p->tone_playing)
        {
            aud_tone_stop();
        }

    #ifdef __MED_MMA_MOD__
        /* close all mma tasks */
        aud_mma_close_all();
    #endif /* __MED_MMA_MOD__ */ 

        if (!(aud_context_p->state == AUD_MEDIA_RECORD ||
              aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
              aud_context_p->state == AUD_VM_RECORD || aud_context_p->state == AUD_VM_RECORD_PAUSED))
        {
            aud_stop_unfinished_process();

            aud_context_p->play_mode = AUD_MEDIA_PLAY_AS_SONG;

            /* set volume and path if from LMMI */
            if (aud_context_p->src_mod == MOD_MMI)
            {
                SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, msg_p->volume);
                aud_context_p->melody_output_device = msg_p->output_path;
                
                aud_get_active_device_path_by_mode(msg_p->output_path,aud_melody_set_output_device);
            }
            else
            {
                aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER_BOTH;
            }

            aud_context_p->current_format = med_get_media_type(msg_p->file_name);
            aud_context_p->identifier = msg_p->identifier;
            aud_context_p->start_offset = msg_p->start_offset;
            aud_context_p->end_offset = msg_p->end_offset;
            switch (aud_context_p->current_format)
            {
            #ifdef __MED_MMA_MOD__
                case MED_TYPE_SMF:
                case MED_TYPE_SMF_SND:
                case MED_TYPE_IMELODY:
                case MED_TYPE_MMF:
                    result = aud_melody_restore_by_name(msg_p->file_name, msg_p->play_style, 0);
                    break;
            #endif /* __MED_MMA_MOD__ */ 

                case MED_TYPE_AMR:
                case MED_TYPE_AMR_WB:
                case MED_TYPE_GSM_EFR:
                case MED_TYPE_VR:
                case MED_TYPE_PCM_8K:
                case MED_TYPE_PCM_16K:
                case MED_TYPE_DVI_ADPCM:
                case MED_TYPE_DAF:
                case MED_TYPE_MUSICAM:
                case MED_TYPE_WAV:
                case MED_TYPE_WAV_DVI_ADPCM:
                case MED_TYPE_AU:
                case MED_TYPE_AIFF:
            #ifdef AAC_DECODE
                case MED_TYPE_AAC:
            #endif 
            #ifdef WMA_DECODE
                case MED_TYPE_WMA:
            #endif 
            #if defined(AAC_DECODE)
                case MED_TYPE_M4A:
            #endif 
                    aud_context_p->source_type = AUD_FILE;
                    aud_context_p->play_style = msg_p->play_style;
                    result = aud_media_play_file_stream(msg_p->file_name, msg_p->play_style, 1, KAL_TRUE, msg_p->cache_p);
                    break;

            #if defined(MED_PURE_AUDIO)
                case MED_TYPE_3GP:
                case MED_TYPE_MP4:
                    aud_context_p->source_type = AUD_FILE;
                    aud_context_p->play_style = msg_p->play_style;
                    result = aud_media_play_audio_track_in_video(msg_p->file_name, msg_p->play_style, KAL_TRUE, KAL_TRUE);
                    break;
            #endif /* #if defined(MED_PURE_AUDIO) */

                default:
                    result = MED_RES_INVALID_FORMAT;
                    break;

            }
            aud_set_result((kal_int32) result);
            AUD_SET_EVENT(AUD_EVT_RESUME);
        }
        else
        {
            aud_set_result((kal_int32) MED_RES_BUSY);
            AUD_SET_EVENT(AUD_EVT_RESUME);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_read_data_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the audio read data indication.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_read_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    aud_media_read_data_ind_struct *msg_p;
    kal_uint32 len, prev_len;
    kal_int32 result;
    kal_uint8 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_uint8   cnf_result; */

    AUD_FUNC_ENTRY(AUD_MEDIA_READ_DATA_IND_HDLR);

    msg_p = (aud_media_read_data_ind_struct*) ilm_ptr->local_para_ptr;

#ifdef __MED_VID_ENC_MOD__
    if (VID_IN_STATE(VID_RECORD))
    {
        if (msg_p->event == MEDIA_DATA_NOTIFICATION)
        {
            kal_uint16 *pwBuf;
            kal_uint32 uBufLen;
            FSAL_Status eFSALRet;
            kal_uint32 residual_size;

            residual_size = vid_file_audio_residual_size();

            aud_context_p->processing_data = KAL_FALSE;
            
            if (residual_size ==0)
            {
                vid_send_visual_stop_req(NULL);
                VID_ENTER_STATE(VID_RECORD_FINISH);
                return;
            }
            
            Media_GetReadBuffer(&pwBuf, &uBufLen);
            if (residual_size < uBufLen * 2)
            {
                uBufLen = (residual_size >> 1);
            }
            eFSALRet = FSAL_Write(&stFSALProducerAudData, (kal_uint8*) pwBuf, uBufLen * 2);
            
            if (eFSALRet != FSAL_OK)
            {
                /* set the error code */
                vid_context_p->error_code = MED_RES_FSAL_ERROR;

                vid_send_visual_stop_req(NULL);
                VID_ENTER_STATE(VID_RECORD_FINISH);
                return;
            }
            Media_ReadDataDone(uBufLen);

            vid_context_p->file_size_info.audio_bitstream_size += uBufLen * 2;

            vid_context_p->current_time = video_enc_get_current_time();
            vid_context_p->file_size_info.audio_rm_size = vid_evaluate_audio_real_meta_file_size(vid_context_p->current_time);
            vid_context_p->file_size_info.audio_meta_size = vid_evaluate_audio_meta_file_size(vid_context_p->current_time);

            residual_size = vid_file_audio_residual_size();
            /* if (!(residual_size > (uBufLen*2) && ((residual_size-(uBufLen*2)) > vid_context_p->file_size_info.file_size_limit*1/100))) */
            if (residual_size == 0)
            {
                vid_send_visual_stop_req(NULL);
                VID_ENTER_STATE(VID_RECORD_FINISH);
            }
            /* tracking video file size */
            vid_context_p->file_size = vid_get_current_file_size();
            AUD_VALUE_TRACE(
                vid_context_p->file_size,
                vid_context_p->file_size_info.audio_bitstream_size,
                vid_context_p->file_size_info.audio_rm_size);
        }
        else if (msg_p->event == MEDIA_END || msg_p->event == MEDIA_ERROR)
        {
            vid_send_visual_stop_req(NULL);
            VID_ENTER_STATE(VID_RECORD_FINISH);
        }
        return;
    }

#endif /* __MED_VID_ENC_MOD__ */ 

#if defined(__MED_MJPG_ENC_MOD__)
    if (VID_IN_STATE(VID_RECORD))
    {
        if (msg_p->event == MEDIA_DATA_NOTIFICATION)
        {
            aud_context_p->processing_data = KAL_FALSE;
            
            if (vid_context_p->record_audio)
            {
                if (vid_write_audio() == MED_RES_BUSY)
                {
                    /* system too busy, cant dump data to file */
                    vid_context_p->error_code = MED_RES_BUSY;
                    
                    vid_stop_video_record();
                    vid_stop_camera_preview();

                    /* notify med_v to dump remained data */
                    vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_TERMINATE);
                    vid_send_visual_stop_req(NULL);
                    VID_ENTER_STATE(VID_RECORD_FINISH);                    
                }
            }
        }
        return;
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        /* 
         * Consume read buffer when in record paused state, let driver leave 
         * waiting state. Otherwise driver will be blocked.
         */
        /* [MAUI_00231781] */
        aud_context_p->processing_data = KAL_FALSE;
        
        Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*)&(aud_context_p->buf_len));
        kal_trace(TRACE_GROUP_4, VID_TRC_BUFFER_LEN, aud_context_p->buf_len);  

        Media_ReadDataDone(aud_context_p->buf_len);
    }
#endif /* defined(__MED_MJPG_ENC_MOD__) */

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_RECORD:
        {
            if (msg_p->event == MEDIA_DATA_NOTIFICATION)
            {
                Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));

                ASSERT(aud_context_p->buf_p != NULL);
                //ASSERT(aud_context_p->buf_len <= AUD_RING_BUFFER_LEN);

                /* Check if total record data exceed size limit */
                if(aud_context_p->size_limit > 0)
                {
                    result = FS_GetFileSize(aud_context_p->current_file_handle, &len);
                    AUD_VALUE_TRACE(result, -1, __LINE__);
                    AUD_VALUE_TRACE(aud_context_p->size_limit, len, aud_context_p->buf_len * 2);
                    
                    if((result == FS_NO_ERROR) &&
                       ((len + aud_context_p->buf_len * 2) > aud_context_p->size_limit))
                    {
                        goto write_file_error;
                    }
                }

                /* Check if total record time exceed time limit */
                if(aud_context_p->time_limit > 0)
                {
                    kal_uint32 record_time;

                    record_time = Media_GetRecordedTime();
                    AUD_VALUE_TRACE(record_time, -1, __LINE__);
                    if(record_time > (aud_context_p->time_limit * 1000))
                    {
                        result = FS_NO_ERROR;
                        goto write_file_error;                        
                    }
                }

                result = FS_Write(
                            aud_context_p->current_file_handle,
                            aud_context_p->buf_p,
                            aud_context_p->buf_len * 2,
                            &len);
                /* update offset */
                aud_context_p->offset += len;
                prev_len = len;

                Media_ReadDataDone(len >> 1);
                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1);
                AUD_VALUE_TRACE(result, -1, -1);

                /* It's fine to encounter ring buffer boundary here, it will get twice when stop record .
                   So no need to get buffer twice here */

                if (result != FS_NO_ERROR)
                {
                    /* Reset previous write data */
                    if(prev_len > 0)
                    {
                        FS_Seek(aud_context_p->current_file_handle, (int)-prev_len, FS_FILE_CURRENT);
                        FS_Truncate(aud_context_p->current_file_handle);
                    }
                
                    goto write_file_error;
                }
            }
            else if (msg_p->event == MEDIA_ERROR)
            {
            	/* Assign any error cause to return */
                result = FS_ERROR_RESERVED;
                goto write_file_error;
            }

            return;
            break;
        }
        default:
        {
            return;
            break;
        }
    }

write_file_error:
    /* inform L1AUD to stop recording process */
    Media_Stop();

    /* Restore input source when stop recording */
    L1SP_SetInputSource(aud_context_p->input_device);

    /* close record file, add header if wav */
    res = aud_close_record_file();

    if (aud_context_p->offset == 0)
    {
        FS_HANDLE fh;
        kal_uint32 len = 0;

        /* Check if empty file, if yes delete it */
        fh = FS_Open(aud_context_p->current_file_name, FS_READ_ONLY | FS_NOBUSY_CHECK_MODE);

        if(fh >= 0)
        {
            FS_GetFileSize(fh, &len);
            FS_Close(fh);

            if(len == 0)
            {
                FS_Delete(aud_context_p->current_file_name);
            }
        }
    }

    if (result == FS_DISK_FULL)
    {
        aud_send_media_record_finish_ind(MED_RES_DISC_FULL);
    }
    else if(result == FS_NO_ERROR)
    {
        aud_send_media_record_finish_ind(MED_RES_OK);
    }
    else
    {
        aud_send_media_record_finish_ind(MED_RES_ERROR);
    }

    /* enter AUD_MEDIA_IDLE state */
    AUD_ENTER_STATE(AUD_MEDIA_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_write_data_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the audio write data indication.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_write_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_media_write_data_ind_struct *msg_p;
    Media_Event event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, AUD_MED_TRC_WRITE_DATA_IND_HDLR);
    AUD_FUNC_ENTRY(AUD_MEDIA_WRITE_DATA_IND_HDLR);

    msg_p = (aud_media_write_data_ind_struct*) ilm_ptr->local_para_ptr;
    
        
#ifdef __MED_VID_MOD__
    
    if (vid_context_p->mhdl_handle)
    {
        event = vid_context_p->mhdl_handle->Process(vid_context_p->mhdl_handle, (Media_Event)msg_p->event);
    }
    else
    {
        return;
    }

    if (VID_IN_STATE(VID_PLAY) && VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL))
    {
        if (event == MEDIA_DATA_REQUEST)
        {
            kal_uint32 read_size;
            MP4_Parser_Status eMp4ParserRet;
            kal_uint64 cur_time = 0;
            
            aud_context_p->processing_data = KAL_FALSE;

            vid_context_p->mhdl_handle->GetWriteBuffer(
                vid_context_p->mhdl_handle, 
                &vid_context_p->audio_buf_p, 
                &vid_context_p->audio_buf_len);

            if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {            
                /* get current time before read, if underflow, we need seek back to this time */
                video_dec_get_play_time(&cur_time);        
                kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, cur_time, __LINE__);                                                            
            }

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_READ, __LINE__); 
            
            eMp4ParserRet = MP4_Audio_Read(
                stMp4Parser_a_ptr, 
                vid_context_p->audio_buf_p, 
                vid_context_p->audio_buf_len, 
                &read_size);
            
            vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
            kal_trace(TRACE_GROUP_4, VID_TRC_AUD_READ_BUF, vid_context_p->audio_buf_len,  read_size);    
             
            if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {
                if (eMp4ParserRet == MP4_PARSER_READ_EOF)
                {
                    kal_uint32 available_time;      
                    MP4_Parser_Status eMp4AudParserRet;

                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, __LINE__);      
                    eMp4AudParserRet = MP4_Audio_GetAvailableDur(stMp4Parser_a_ptr, &available_time);
                    vid_debug_print_mp4_parser_return(eMp4AudParserRet, __LINE__);
                    kal_trace(TRACE_GROUP_4, VID_TRC_AUD_DURATION, available_time);  

                    kal_trace(
                        TRACE_GROUP_4, 
                        VID_TRC_TOTAL_DURATION, 
                        (kal_uint32)vid_context_p->total_time,
                        (kal_uint32)vid_context_p->total_audio_time,
                        (kal_uint32)vid_context_p->total_video_time); 

                    if (eMp4AudParserRet != MP4_PARSER_OK)
                    {

                        vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);                        
                        VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
                        vid_send_visual_stop_req(NULL);
                        return;
                    }     
                    
                    if (available_time < vid_context_p->total_audio_time)
                    {
                        /* undlerflow, let buffer in driver to play finish */
                        vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_UNDERFLOW);
                        VID_ENTER_STATE(VID_AUDIO_PLAY_FINISH);                        
                        return;
                    }    
                }
            }

            
            if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_READ_EOF)
            {
                vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);                   
                VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
                vid_send_visual_stop_req(NULL);
                return;
            }
            else if (eMp4ParserRet == MP4_PARSER_READ_EOF)
            {
                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);                
                
                /* we do not call DataFinished here, since we need keep dsp awake and fill silence audio */
                VID_ENTER_STATE(VID_AUDIO_PLAY_FINISH);
                return;
            }
            else
            {
                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);
                return;
            }

        }
        else if (event == MEDIA_END)
        {
            //ASSERT(event != MEDIA_END);
        }
        else if (event == MEDIA_ERROR)
        {
            VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
            vid_stop_audio();      
        #ifdef __MED_AUD_TIME_STRETCH__
            aud_stretch_close();
        #endif 
            VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            vid_send_visual_stop_req(NULL);
        }
        return;
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_FINISH) && VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL))
    {
        if (event == MEDIA_DATA_REQUEST)
        {
            aud_context_p->processing_data = KAL_FALSE;

            /* stuff dummy audio into audio buffer */
            if (vid_context_p->aud_format == MEDIA_FORMAT_AMR ||
                vid_context_p->aud_format == MEDIA_FORMAT_AMR_WB)
            {
                vid_context_p->mhdl_handle->GetWriteBuffer(
                    vid_context_p->mhdl_handle, 
                    &vid_context_p->audio_buf_p, 
                    &vid_context_p->audio_buf_len);     

                kal_mem_set(vid_context_p->audio_buf_p, 0x7C, vid_context_p->audio_buf_len); /* stuff silence audio */

                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, vid_context_p->audio_buf_len);
                vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle); 
            }
            else if (vid_context_p->aud_format == MEDIA_FORMAT_AAC)
            {
            #ifdef AAC_DECODE
                kal_uint32 read_size;
                kal_uint32 frame_count;
                kal_uint8 *buf_p;
                kal_uint32 remained_idx;                
            
                vid_context_p->mhdl_handle->GetWriteBuffer(
                    vid_context_p->mhdl_handle, 
                    &vid_context_p->audio_buf_p, 
                    &vid_context_p->audio_buf_len);     

                buf_p = vid_context_p->audio_buf_p;

                if (vid_context_p->audio_silence_remained != 0)
                {
                    /* when enter here, means we already stuff some slience audio into buffer */
                    remained_idx = MED_AUD_AAC_SILENCE_FRAME_SIZE - vid_context_p->audio_silence_remained;
                    
                    if (vid_context_p->audio_silence_remained <= vid_context_p->audio_buf_len)
                    {
                        /* able to stuff all remained buf */
                        memcpy(
                            (void*)buf_p, 
                            (void*)&med_aud_aac_silence_frame[remained_idx], 
                            vid_context_p->audio_silence_remained);

                        vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, vid_context_p->audio_silence_remained);
                        vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);

                        vid_context_p->audio_silence_remained = 0;
                        return;
                    }
                    else
                    {
                        /* can only stuff partial remained buf */
                        memcpy(
                            (void*)buf_p, 
                            (void*)&med_aud_aac_silence_frame[remained_idx], 
                            vid_context_p->audio_buf_len);

                        vid_context_p->audio_silence_remained -= vid_context_p->audio_buf_len;
                        
                        vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, vid_context_p->audio_buf_len);
                        vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);
                        return;
                    }
                }

                if (vid_context_p->audio_buf_len < MED_AUD_AAC_SILENCE_FRAME_SIZE)
                {
                    /* audio buf not enought to put whole silence frame */
                    
                    /* we load partial silence into audio buf */
                    memcpy(
                        (void*)buf_p, 
                        (void*)med_aud_aac_silence_frame, 
                        vid_context_p->audio_buf_len);

                    vid_context_p->audio_silence_remained 
                        = MED_AUD_AAC_SILENCE_FRAME_SIZE - vid_context_p->audio_buf_len;
                    vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, vid_context_p->audio_buf_len);
                    vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);    
                    return;                    
                }
                
                frame_count = vid_context_p->audio_buf_len / MED_AUD_AAC_SILENCE_FRAME_SIZE;
                read_size = frame_count * MED_AUD_AAC_SILENCE_FRAME_SIZE;

                while (frame_count)
                {
                    memcpy(
                        (void*)buf_p, 
                        (void*)med_aud_aac_silence_frame, 
                        MED_AUD_AAC_SILENCE_FRAME_SIZE);

                    buf_p += MED_AUD_AAC_SILENCE_FRAME_SIZE;
                    frame_count--;
                }

                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);    
                return;
            #else /* AAC_DECODE */
                /* try to decode AAC, but decoder not suppot */
                ASSERT(0);
            #endif /* AAC_DECODE */
            }
            else
            {
                /* unsupport audio format */
                ASSERT(0);
            }
       
            
        }
        else if (event == MEDIA_END)
        {
            vid_stop_visual();
            vid_stop_audio();
            vid_play_finish_hdlr();
        }
        else if (event == MEDIA_ERROR)
        {
            VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
            vid_stop_audio();
        #ifdef __MED_AUD_TIME_STRETCH__
            aud_stretch_close();
        #endif 
            VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            vid_send_visual_stop_req(NULL);
        }
        return;
    }    
    else if (VID_IN_STATE(VID_AUDIO_PLAY_FINISH) && VID_AUD_IN_STATE(VID_AUD_PLAY_UNDERFLOW))
    {
        aud_context_p->processing_data = KAL_FALSE;
        
        if (event == MEDIA_END)
        {
            vid_stop_visual();
            vid_stop_audio();                        
            vid_send_play_finish_ind(MED_RES_PDL_AUDIO_UNDERFLOW);   
            return;
        }
        else if (event == MEDIA_ERROR)
        {
            VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
            vid_stop_audio();            
        #ifdef __MED_AUD_TIME_STRETCH__
            aud_stretch_close();
        #endif 
            VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            vid_send_visual_stop_req(NULL);
        }
        return;
    }
    else if (VID_IN_STATE(VID_VISUAL_PLAY_FINISH) && VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL))
    {
        if (event == MEDIA_DATA_REQUEST)
        {
            kal_uint32 read_size;
            MP4_Parser_Status eMp4ParserRet;
            kal_uint64 cur_time = 0;

            aud_context_p->processing_data = KAL_FALSE;
            
            vid_context_p->mhdl_handle->GetWriteBuffer(
                vid_context_p->mhdl_handle, 
                &vid_context_p->audio_buf_p, 
                &vid_context_p->audio_buf_len);

            if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {            
                /* get current time before read, if underflow, we need seek back to this time */
                video_dec_get_play_time(&cur_time);        
                kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, cur_time, __LINE__);                                                            
            }

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_READ, __LINE__);                        
            
            eMp4ParserRet = MP4_Audio_Read(
                                stMp4Parser_a_ptr, 
                                vid_context_p->audio_buf_p, 
                                vid_context_p->audio_buf_len, 
                                &read_size);
            
            vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
            kal_trace(TRACE_GROUP_4, VID_TRC_AUD_READ_BUF, vid_context_p->audio_buf_len,  read_size);    

            if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {
                if (eMp4ParserRet == MP4_PARSER_READ_EOF)
                {
                    kal_uint32 available_time;      
                    MP4_Parser_Status eMp4AudParserRet;
                    
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, __LINE__);      
                    eMp4AudParserRet = MP4_Audio_GetAvailableDur(stMp4Parser_a_ptr, &available_time);
                    vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
                    kal_trace(TRACE_GROUP_4, VID_TRC_AUD_DURATION, available_time);  
                    
                    if (eMp4AudParserRet != MP4_PARSER_OK)
                    {
                        vid_stop_visual();
                        vid_stop_audio();
                        vid_send_play_finish_ind(MED_RES_PARSER_ERROR);
                        return;
                    }     

                    if (available_time < vid_context_p->total_audio_time)
                    {
                        /* undlerflow, let buffer in driver to play finish */
                        vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_UNDERFLOW);
                        return;
                    }    
                }
            }

            
            if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_READ_EOF)
            {
                vid_stop_visual();
                vid_stop_audio();
                vid_play_finish_hdlr();
                return;
            }
            else if (eMp4ParserRet == MP4_PARSER_READ_EOF)
            {
                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);
                VID_ENTER_STATE(VID_AUDIO_PLAY_FINISH);                
                return;
            }
            else
            {
                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);                
                return;
            }
        }
        else if (event == MEDIA_END || event == MEDIA_ERROR)
        {
            vid_stop_visual();
            vid_stop_audio();
            vid_play_finish_hdlr();
        }
        return;
    }
    else if (VID_IN_STATE(VID_VISUAL_PLAY_FINISH) && VID_AUD_IN_STATE(VID_AUD_PLAY_UNDERFLOW))
    {
        if (event == MEDIA_END)
        {
            vid_stop_visual();
            vid_stop_audio();                        
            vid_send_play_finish_ind(MED_RES_PDL_AUDIO_UNDERFLOW);   
        }
        else if (event == MEDIA_ERROR)
        {
            vid_stop_visual();
            vid_stop_audio();
            vid_play_finish_hdlr();
        }        
        return;
    }    

#endif /* __MED_VID_MOD__ */ 

#if defined(__MED_MJPG_MOD__)

    if (vid_context_p->mhdl_handle)
    {
        event = vid_context_p->mhdl_handle->Process(vid_context_p->mhdl_handle, (Media_Event)msg_p->event);
    }
    else
    {
        return;
    }

    if (VID_IN_STATE(VID_PLAY) && VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL))
    {
        if (event == MEDIA_DATA_REQUEST)
        {
            kal_uint32 read_size;
            kal_int32 ret;

            aud_context_p->processing_data = KAL_FALSE;
            Media_GetWriteBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));

            vid_context_p->mhdl_handle->GetWriteBuffer(
                vid_context_p->mhdl_handle, 
                &vid_context_p->audio_buf_p, 
                &vid_context_p->audio_buf_len);
            
            read_size = vid_context_p->audio_buf_len;
            ret = med_avi_read_audio_data((kal_char*)vid_context_p->audio_buf_p, &read_size);

            if (ret == MED_RES_AUDIO_ERROR)
            {
                vid_stop_audio();                        
                VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);                
                vid_send_visual_stop_req(NULL);                
                return;
            }
            else if (ret == MED_RES_AUDIO_END)
            {
                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);
            }
            else
            {
                vid_context_p->mhdl_handle->WriteDataDone(vid_context_p->mhdl_handle, read_size);
                vid_context_p->mhdl_handle->FinishWriteData(vid_context_p->mhdl_handle);                
            }

        }
        else if (event == MEDIA_END)
        {
            aud_context_p->processing_data = KAL_FALSE;
            vid_stop_audio();               
            VID_ENTER_STATE(VID_AUDIO_PLAY_FINISH);
            vid_send_visual_stop_req(NULL);
            return;            
        }
        else if (event == MEDIA_ERROR)
        {
            aud_context_p->processing_data = KAL_FALSE;
            vid_stop_audio();         
            VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
            vid_send_visual_stop_req(NULL);             
            return;
        }
        return;
    }
#endif /* defined(__MED_MJPG_MOD__) */

    /* Audio should not go this path, it should go new interface */
    ASSERT(AUD_IN_STATE(AUD_MEDIA_IDLE));

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_get_duration_by_handle
 * DESCRIPTION
 *  This function is to get the data length of an audio file by current play handle
 *  Only for DAF, AMR, AWB, AAC filr format
 * PARAMETERS
 *  duration      [OUT]   output duration
 * RETURNS
 * kal_uint8      result
 *****************************************************************************/
kal_uint8 aud_media_get_duration_by_handle(kal_uint32 *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*audio might have been stopped whils mmi try to get duration*/
    if(aud_context_p->last_mhdl_handle == NULL)
    {
        return result;
    }
    
    switch( aud_context_p->current_format )
    {
#ifdef DAF_DECODE
        case MED_TYPE_DAF:
#ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
#endif
#endif /* DAF_DECODE */
#ifdef AMR_DECODE
        case MED_TYPE_AMR:
#ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:
#endif 
#endif /* AMR_DECODE */ 
#ifdef AAC_DECODE
        case MED_TYPE_AAC:
#endif 
            ASSERT(aud_context_p->last_mhdl_handle != NULL);
            *duration = aud_context_p->last_mhdl_handle->GetTotalDuration(aud_context_p->last_mhdl_handle);
            result = MED_RES_OK;
            break;
        default:
            ASSERT(0);
            break;
    }
    return result ;
}

/*****************************************************************************
 * FUNCTION
 *  aud_media_get_duration
 * DESCRIPTION
 *  This function is to get the data length of an audio file with filename
 * PARAMETERS
 *  file_name     [IN]    filename
 *  duration      [OUT]   output duration
 * RETURNS
 * kal_uint8   result
 *****************************************************************************/
kal_uint8 aud_media_get_duration(kal_wchar *file_name, kal_uint8 *aud_data, kal_uint32 aud_len, kal_uint8 aud_format, kal_uint32 *duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = 0;
    FSAL_Status fasl_ret;
    STFSAL ext_fsal;
    kal_int16 format;    
    Media_Status get_result;
    audInfoStruct *content_info;
    media_get_info_func_ptr getdesFunc = NULL;    
    kal_uint8 *fsal_buf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(aud_data != NULL)
    {
        format = aud_format;
    }
    else
    {
        format = med_get_media_type(file_name);
    }
    *duration = 0 ;

    /* Non stream type audio */
    if( format == MED_TYPE_IMELODY || format == MED_TYPE_SMF || format == MED_TYPE_MMF)
    {
#ifdef __MED_MMA_MOD__
        return aud_melody_get_duration(file_name, aud_data, aud_len, format, duration);
#else
        return MED_RES_INVALID_FORMAT;
#endif
    }

#if defined(MED_PURE_AUDIO)
    /* MP4 format audio */
    if( format == MED_TYPE_MP4 || format == MED_TYPE_3GP)
    {
        return aud_media_get_audio_duration_in_video(file_name, aud_data, aud_len, format, duration);
    }
#endif /* #if defined(MED_PURE_AUDIO) */

    /* Open string data */
    if(aud_data != NULL)
    {
        FSAL_Direct_SetRamFileSize(&ext_fsal, aud_len);
        if ((fasl_ret = FSAL_Open(&ext_fsal, aud_data, FSAL_ROMFILE)) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
    }
    /* Open file for get content info */    
    else
    {
        if ((fasl_ret = FSAL_Open(&ext_fsal, file_name, FSAL_READ)) != FSAL_OK)
        {
            return MED_RES_OPEN_FILE_FAIL;
        }
        /* Need to set buffer here for performance */
        fsal_buf = (kal_uint8*)med_alloc_ext_mem(AUD_PROC_BUF_SIZE);
        if(fsal_buf != NULL)
        {
            FSAL_SetBuffer( &ext_fsal,  AUD_PROC_BUF_SIZE,  fsal_buf );
        }
    }

    switch (format)
    {
#ifdef DAF_DECODE
        case MED_TYPE_DAF:
#ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:
#endif
            getdesFunc = DAF_GetContentDescInfo;
            break;
#endif /* DAF_DECODE */ 
#ifdef AMR_DECODE
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
            getdesFunc = AMR_GetContentDescInfo;
            break;
#endif /* AMR_DECODE */ 
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_DVI_ADPCM:
            getdesFunc = WAV_GetContentDescInfo;
            break;
#ifdef AIFF_DECODE
        case MED_TYPE_AIFF:
            getdesFunc = AIFF_GetContentDescInfo;
            break;
#endif /* AIFF_DECODE */
#ifdef AU_DECODE
        case MED_TYPE_AU:
            getdesFunc = AU_GetContentDescInfo;
            break;
#endif /* AU_DECODE */
#ifdef AAC_DECODE
        case MED_TYPE_AAC:
            getdesFunc = AAC_GetContentDescInfo;
            break;
#endif /* AAC_DECODE */ 
#if defined(AAC_DECODE)
        case MED_TYPE_M4A:
            getdesFunc = M4A_GetContentDescInfo;
            break;
#endif /* defined(AAC_DECODE) */ 
#ifdef WMA_DECODE
    case MED_TYPE_WMA:
            getdesFunc = WMA_GetContentDescInfo;
            break;
#endif /* WMA_DECODE */ 
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_DVI_ADPCM:
        default:
            result = MED_RES_INVALID_FORMAT;
            break;
    }

    if (getdesFunc != NULL)
    {
        content_info = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));
        if ((get_result = getdesFunc(&ext_fsal, content_info, (void*)format)) == MEDIA_SUCCESS)
        {
            *duration = content_info->time;
        }
        else
        {
            result = aud_get_res(get_result);
        }
        free_ctrl_buffer(content_info);
    }

    if(fsal_buf != NULL)
    {
        med_free_ext_mem((void**)&fsal_buf);
    }

    FSAL_Close(&ext_fsal);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  aud_media_get_duration_req_hdlr
 * DESCRIPTION
 *  This function is to get the data length of the audio file playing
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
void aud_media_get_duration_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = 0;
    kal_uint32 duration = 0;
    media_aud_get_duration_req_struct *msg_p = (media_aud_get_duration_req_struct*) ilm_ptr->local_para_ptr;
    kal_wchar *file_name = msg_p->file_name;
    kal_bool use_default_handle = msg_p->use_default_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__)    /* MODIS */
    result = MED_RES_OK;
    duration = 0;
#else /* !defined(__MTK_TARGET__) */ 

    if(!use_default_handle)
    {
        if(msg_p->audio_data != NULL)
        {
            result = aud_media_get_duration(NULL, msg_p->audio_data, msg_p->len, msg_p->format, &duration);
        }
        else
        {
            result = aud_media_get_duration(file_name, NULL, 0, 0, &duration);        
        }
    }
    else
    {
        result = aud_media_get_duration_by_handle(&duration);
    }

#endif /* !defined(__MTK_TARGET__) */

    aud_set_pair_results(result, duration);
    AUD_SET_EVENT(AUD_EVT_GET_DURATION);

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_get_progress_time_req_hdlr
 * DESCRIPTION
 *  This function is to get the progress of the audio file playing
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  kal_uint8(?)
 *****************************************************************************/
void aud_media_get_progress_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;
    kal_uint32 progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_PAUSED:
        case AUD_MEDIA_PLAY_FINISH:
            if (aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_SONG)
            {
                switch( aud_context_p->current_format )
                {
                #ifdef __MED_MMA_MOD__
                    case MED_TYPE_SMF:
                    case MED_TYPE_SMF_SND:
                        ASSERT(aud_context_p->last_handle != NULL);
                        progress = (kal_uint32)JSmf_GetCurrentTime(aud_context_p->last_handle);
                        result = MED_RES_OK;
                        break;
                    case MED_TYPE_IMELODY:
                        ASSERT(aud_context_p->last_handle != NULL);
                        progress = (kal_uint32)JImy_GetCurrentTime(aud_context_p->last_handle);
                        result = MED_RES_OK;
                        break;
                #endif /* __MED_MMA_MOD__ */
                #ifdef DAF_DECODE
                    case MED_TYPE_DAF:
                #ifdef MUSICAM_DECODE
                    case MED_TYPE_MUSICAM:
                #endif
                #endif /* DAF_DECODE */
                #ifdef AMR_DECODE
                    case MED_TYPE_AMR:
                #ifdef AMRWB_DECODE
                    case MED_TYPE_AMR_WB:
                #endif 
                #endif /* AMR_DECODE */ 
                    case MED_TYPE_GSM_EFR:
                    case MED_TYPE_PCM_8K:
                    case MED_TYPE_PCM_16K:
                    case MED_TYPE_DVI_ADPCM:
                    case MED_TYPE_WAV:
                    case MED_TYPE_WAV_DVI_ADPCM:
                #ifdef AIFF_DECODE
                    case MED_TYPE_AIFF:
                #endif
                #ifdef AU_DECODE
                    case MED_TYPE_AU:
                #endif
                #ifdef AAC_DECODE
                    case MED_TYPE_AAC:
                #endif 
                #ifdef WMA_DECODE
                    case MED_TYPE_WMA:
                #endif 
                #if defined(AAC_DECODE)
                    case MED_TYPE_M4A:
                #endif
                #if defined(MED_PURE_AUDIO)
                    case MED_TYPE_3GP:
                    case MED_TYPE_MP4:
                #endif /* #if defined(MED_PURE_AUDIO) */
                        ASSERT(aud_context_p->last_mhdl_handle != NULL);
                        progress = aud_context_p->last_mhdl_handle->GetCurrentTime(aud_context_p->last_mhdl_handle);
                        result = MED_RES_OK;
                        break;
                    default:
                        result = MED_RES_FAIL;
                        progress = 0;
                        break;
                }
            }
            else
            {
                result = MED_RES_FAIL;
                progress = 0;
            }
            break;
        case AUD_MEDIA_IDLE:
            result = MED_RES_FAIL;
            progress = 0;
            break;
        default:
            result = MED_RES_FAIL;
            progress = 0;
            break;
    }

    aud_set_pair_results(result, progress);
    AUD_SET_EVENT(AUD_EVT_GET_PROGRESS_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_set_progress_time_req_hdlr
 * DESCRIPTION
 *  This function is to set the progress of the audio file playing
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  kal_uint8(?)
 *****************************************************************************/
void aud_media_set_progress_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = MED_RES_FAIL;
    Media_Status get_result;
    media_aud_set_progress_time_req_struct *msg_p = (media_aud_set_progress_time_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 progress = msg_p->progress;
    media_ctrl_func_ptr closeFunc, stopFunc;
    media_set_time_func_ptr setStartTimeFunc;
    kal_bool continue_play = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    closeFunc = aud_context_p->last_mhdl_handle->Close;
    stopFunc = aud_context_p->last_mhdl_handle->Stop;
    setStartTimeFunc = aud_context_p->last_mhdl_handle->SetStartTime;

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_PLAY:
        case AUD_MEDIA_PLAY_PAUSED:

            if (aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_SONG)
            {
                switch (aud_context_p->current_format)
                {
                    case MED_TYPE_AMR:
                    case MED_TYPE_AMR_WB:
                    case MED_TYPE_DAF:
                    case MED_TYPE_MUSICAM:

                        /* stop it at first */
                        stopFunc(aud_context_p->last_mhdl_handle);

                        aud_context_p->last_seq_no++;

                        /* stop volume crescendo timer */
                        med_stop_timer(AUD_TIMER_CRESCENDO);
                        /* enter AUD_MEDIA_IDLE state */

                        if (aud_context_p->state == AUD_MEDIA_PLAY)
                        {
                            AUD_ENTER_STATE(AUD_MEDIA_IDLE);
                            continue_play = KAL_TRUE;
                        }
                        else if (aud_context_p->state == AUD_MEDIA_PLAY_PAUSED)
                        {
                            AUD_ENTER_STATE(AUD_MEDIA_SEEK_PAUSED);
                        }

                        /* update start offset and play it */
                        get_result = setStartTimeFunc(aud_context_p->last_mhdl_handle, progress);

                        if (continue_play)  /* Continue Play */
                        {
                            result = aud_media_replay_by_handle(0, KAL_FALSE);
                        }
                        else
                        {
                            result = MED_RES_OK;
                        }

                        AUD_VALUE_TRACE(get_result, result, continue_play);
                        break;
                }
            }
            break;

        default:
            result = MED_RES_FAIL;
            break;
    }

    aud_set_result(result);
    AUD_SET_EVENT(AUD_EVT_SET_PROGRESS_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_record_low_stop_cnf_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_low_stop_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_MEDIA_RECORD_LOW_STOP_CNF_HDLR, aud_context_p->state);
    
    aud_media_stop_record();
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_record_low_pause_cnf_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_low_pause_cnf_hdlr(ilm_struct *ilm_ptr)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_record_pause_cnf_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_MEDIA_RECORD_LOW_PAUSE_CNF_HDLR, aud_context_p->state);
    
    msg_p = (media_v_audio_record_pause_cnf_struct*) ilm_ptr->local_para_ptr;

    if (aud_context_p->state == AUD_MEDIA_RECORD)
    {
        if(msg_p->result == MED_RES_OK)
        {
            AUD_ENTER_STATE(AUD_MEDIA_RECORD_PAUSED);
        }
        else
        {
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);        
        }

        aud_set_result((kal_int32) msg_p->result);
        AUD_SET_EVENT(AUD_EVT_PAUSE);
        /* send confirm message to L4/MMI */
        if (aud_context_p->src_mod != MOD_MMI)
        {
            aud_send_media_pause_cnf(msg_p->result, NULL);
        }    
    }
#endif /* #ifndef MED_V_NOT_PRESENT */
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_record_low_resume_cnf_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_low_resume_cnf_hdlr(ilm_struct *ilm_ptr)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_record_resume_cnf_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_MEDIA_RECORD_LOW_RESUME_CNF_HDLR, aud_context_p->state);
    
    msg_p = (media_v_audio_record_resume_cnf_struct*) ilm_ptr->local_para_ptr;

    if (aud_context_p->state == AUD_MEDIA_RECORD_PAUSED)
    {
        if(msg_p->result == MED_RES_OK)
        {
            AUD_ENTER_STATE(AUD_MEDIA_RECORD);
        }
        else
        {
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);        
        }

        aud_set_result((kal_int32) msg_p->result);
        AUD_SET_EVENT(AUD_EVT_RESUME);
        if (aud_context_p->src_mod != MOD_MMI)
        {
            aud_send_media_resume_cnf(msg_p->result);
        }
    }
#endif /* #ifndef MED_V_NOT_PRESENT */
}

/*****************************************************************************
 * FUNCTION
 *  aud_media_record_low_error_ind_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_record_low_error_ind_hdlr(ilm_struct *ilm_ptr)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_v_audio_record_error_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_MEDIA_RECORD_LOW_ERROR_IND_HDLR, aud_context_p->state);

    msg_p = (media_v_audio_record_error_ind_struct*) ilm_ptr->local_para_ptr;

    switch (aud_context_p->state)
    {
        case AUD_MEDIA_RECORD:
        {
            if (msg_p->result != MED_RES_OK)
            {
                /* send indication message to L4 */
                aud_send_media_record_finish_ind(msg_p->result);

                /* enter AUD_MEDIA_IDLE state */
                AUD_ENTER_STATE(AUD_MEDIA_IDLE);
            }
            break;
        }
        default:
        {
            break;
        }
    }
#endif /* #ifndef MED_V_NOT_PRESENT */
}

#ifdef __RICH_AUDIO_PROFILE__


/*****************************************************************************
 * FUNCTION
 *  aud_start_calc_spectrum_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request to start to calculate audio spectrum tops and vals.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_start_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPT_Open();
}


/*****************************************************************************
 * FUNCTION
 *  aud_stop_calc_spectrum_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request to stop calculating audio spectrum tops and vals.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stop_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPT_Close();
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_spectrum_req_hdlr
 * DESCRIPTION
 *  This function is to handle the request to get latest audio spectrum tops and vals.
 *  tops and vals are two arrays of 16 uint8 values
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_spectrum_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_spectrum_req_struct *msg_p = (media_aud_get_spectrum_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SPT_GetSpectrum(msg_p->top_p, msg_p->val_p);

    aud_set_result(MED_RES_OK);

    AUD_SET_EVENT(AUD_EVT_GET_SPECTRUM);
}
#endif /* __RICH_AUDIO_PROFILE__ */ 


#if defined(MED_PURE_AUDIO)
/*****************************************************************************
 * FUNCTION
 *  aud_media_close_mp4_parser
 * DESCRIPTION
 *  This function is to free mp4 parser memory
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
static void aud_media_free_mp4_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ctrl_buffer(g_aud_mp4_parser.stMp4Parser_aud);        
    free_ctrl_buffer(g_aud_mp4_parser.stFSAL_aud_stsz);
    free_ctrl_buffer(g_aud_mp4_parser.stFSAL_aud_stco);
    free_ctrl_buffer(g_aud_mp4_parser.stFSAL_aud_data);
    med_free_ext_mem((void**)&g_aud_mp4_parser.mp4_aud_buf);
    med_free_ext_mem((void**)&g_aud_mp4_parser.mp4_aud_data_buf);
    med_free_ext_mem((void**)&g_aud_mp4_parser.mp4_aud_stco_buf);
    med_free_ext_mem((void**)&g_aud_mp4_parser.mp4_aud_stsz_buf);
    med_free_ext_mem((void**)&g_aud_mp4_parser.mp4_aud_stbl_buf);     
    med_free_ext_mem((void**)&g_aud_mp4_parser.aud_seek_hint);

    memset(&g_aud_mp4_parser, 0, sizeof(aud_mp4_parser_var));
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_play_audio_track_in_video
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint8 aud_media_play_audio_track_in_video(
      kal_wchar *file_name,
      kal_uint8 play_style, 
      kal_bool first_time,
      kal_bool is_restore)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    kal_uint8 result, play_result;
    kal_bool is_file_opened = KAL_FALSE;
    kal_bool is_aud_opened = KAL_FALSE;
    kal_bool is_data_finish = KAL_FALSE;    
    kal_bool has_aud_track;
    kal_uint32 filesize;
    kal_uint32 index;
    kal_uint64 temp;
    Media_Format audio_format;
    kal_uint32 parser_start_time;
    kal_uint32 aud_duration;

    media_open_func_ptr openFunc = NULL;
    Media_VM_PCM_Param vpFormat;
    void *param = NULL;
    MHdl *mhdl_handle = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(aud_context_p->state == AUD_MEDIA_IDLE);

#if !defined(__MTK_TARGET__)    /* MODIS */
    return MED_RES_OK;
#endif

    /* Open file for playing */   
    eFSALRet = FSAL_Open(&current_file_stream, (void*)file_name, FSAL_READ);     

    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }        
    is_file_opened = KAL_TRUE;

    /* Allocate buffer for parser */
    g_aud_mp4_parser.stMp4Parser_aud = (STMp4Parser*)get_ctrl_buffer(sizeof(STMp4Parser));
    g_aud_mp4_parser.stFSAL_aud_stsz = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));
    g_aud_mp4_parser.stFSAL_aud_stco = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));
    g_aud_mp4_parser.stFSAL_aud_data = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));
    g_aud_mp4_parser.mp4_aud_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32) );
    g_aud_mp4_parser.mp4_aud_data_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32) );
    g_aud_mp4_parser.mp4_aud_stco_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_STCO_BUF_SIZE*sizeof(kal_uint32) );
    g_aud_mp4_parser.mp4_aud_stsz_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_STSZ_BUF_SIZE*sizeof(kal_uint32) );
    g_aud_mp4_parser.mp4_aud_stbl_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_STBL_BUF_SIZE*sizeof(kal_uint32) );
    g_aud_mp4_parser.aud_seek_hint = (FS_FileLocationHint*)med_alloc_ext_mem( AUD_DEC_SEEK_HINT_SIZE*sizeof(FS_FileLocationHint) );

    /* Set buffer for FSAL */
    FSAL_SetBuffer(&current_file_stream, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)g_aud_mp4_parser.mp4_aud_buf);

    /* Set seek hint */
    eFSALRet = FSAL_GetFileSize(&current_file_stream, &filesize);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }

    for (index = 0; index < AUD_DEC_SEEK_HINT_SIZE; index++)
    {
        temp = ((kal_uint64) filesize * (kal_uint64) (index + 1)) / (kal_uint64) (AUD_DEC_SEEK_HINT_SIZE + 1);
        g_aud_mp4_parser.aud_seek_hint[index].Index = (kal_uint32) temp;
    }
    DRM_set_seek_hint(current_file_stream.hFile, AUD_DEC_SEEK_HINT_SIZE, g_aud_mp4_parser.aud_seek_hint);

    /* Creat MP4 parser */
    eMp4ParserRet = MP4_Parse(g_aud_mp4_parser.stMp4Parser_aud, &current_file_stream);

    AUD_VALUE_TRACE(eMp4ParserRet, -1, __LINE__);
    if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        result = MED_RES_BAD_FORMAT;
        goto pure_audio_error_out;
    }

    /* Check if there's audio track */
    MP4_MetaHasAudioTrack(g_aud_mp4_parser.stMp4Parser_aud, &has_aud_track);
    if (!has_aud_track)
    {
        result = MED_RES_MP4_NO_AUDIO_TRACK;
        goto pure_audio_error_out;
    }

    /* Assign buffer for cache table */
    eMp4ParserRet = MP4_STBL_CacheTablePreprocess(
                        g_aud_mp4_parser.stMp4Parser_aud, 
                        g_aud_mp4_parser.mp4_aud_stbl_buf, 
                        AUD_MP4_STBL_BUF_SIZE);
                        
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        AUD_VALUE_TRACE(eMp4ParserRet, -1, __LINE__);
        result = MED_RES_BAD_FORMAT;
        goto pure_audio_error_out;
    }    

    /* FSAL aud data */
    eFSALRet = FSAL_Open_Attach(g_aud_mp4_parser.stFSAL_aud_data, &current_file_stream);
    
    if (eFSALRet != FSAL_OK)
    {
        //VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }
    FSAL_SetBuffer(g_aud_mp4_parser.stFSAL_aud_data, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)g_aud_mp4_parser.mp4_aud_data_buf);

    /* FASL stco */
    eFSALRet = FSAL_Open_Attach(g_aud_mp4_parser.stFSAL_aud_stco, &current_file_stream);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }
    FSAL_SetBuffer(g_aud_mp4_parser.stFSAL_aud_stco, AUD_MP4_STCO_BUF_SIZE, (kal_uint8*)g_aud_mp4_parser.mp4_aud_stco_buf);

    /* FSAL stsz */
    eFSALRet = FSAL_Open_Attach(g_aud_mp4_parser.stFSAL_aud_stsz, &current_file_stream);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }
    FSAL_SetBuffer(g_aud_mp4_parser.stFSAL_aud_stsz, AUD_MP4_STSZ_BUF_SIZE, (kal_uint8*)g_aud_mp4_parser.mp4_aud_stsz_buf);

    /* Set FSAL to MP4 Parser */
    MP4_Audio_SetFSAL(g_aud_mp4_parser.stMp4Parser_aud, g_aud_mp4_parser.stFSAL_aud_data);    
    MP4_SetFSAL_STCO(g_aud_mp4_parser.stMp4Parser_aud, MP4_TRACK_AUDIO, g_aud_mp4_parser.stFSAL_aud_stco);
    MP4_SetFSAL_STSZ(g_aud_mp4_parser.stMp4Parser_aud, MP4_TRACK_AUDIO, g_aud_mp4_parser.stFSAL_aud_stsz);
    MP4_UpdateSampleCount(g_aud_mp4_parser.stMp4Parser_aud, MP4_TRACK_AUDIO);

    audio_format = MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_aud_mp4_parser.stMp4Parser_aud));
    AUD_VALUE_TRACE(audio_format, -1, __LINE__);

    /* The audio format in 3GP/MP4 file */
    switch (audio_format)
    {
    #ifdef AMR_DECODE    
        case MEDIA_FORMAT_AMR:
    #ifdef AMRWB_DECODE        
        case MEDIA_FORMAT_AMR_WB:
    #endif         
            vpFormat.mediaType = audio_format;
            vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param = &vpFormat;        
            openFunc = AMR_Open;
            break;
    #endif /*AMR_DECODE*/
    #if defined(AAC_DECODE)            
        case MEDIA_FORMAT_AAC:
            openFunc = AAC_Open;
            break;
    #endif /*AAC_DECODE*/            
        default:
            result = MED_RES_INVALID_FORMAT;
            goto pure_audio_error_out;
            break;
    }

    if ((aud_context_p->last_mhdl_handle = openFunc(aud_media_play_stream_event_callback, NULL, param)) == NULL)
    {
        //Print trace here
        result = MED_RES_BAD_FORMAT;
        goto pure_audio_error_out; 
    }
    is_aud_opened = KAL_TRUE;
    mhdl_handle = aud_context_p->last_mhdl_handle;

    /* Set the ring buffer for audio driver in the first time play request */
    mhdl_handle->SetBuffer(mhdl_handle, (kal_uint8*) aud_context_p->ring_buf, AUD_RING_BUFFER_LEN * 2);
    
    if (first_time)
    {
        /* follow ring tone volume */
        aud_set_active_ring_tone_volume();
        /* To start ascending timer */
        aud_melody_play_style_convert(play_style);
    }

    /* Find the start time */
    if (is_restore)
    {
        mhdl_handle->SetStartTime(mhdl_handle, aud_context_p->last_time);
        parser_start_time = aud_context_p->last_time;
    }
    /* First time request for play file portion */
    else
    {
        if (aud_context_p->start_offset != 0)
        {
            mhdl_handle->SetStartTime(mhdl_handle, aud_context_p->start_offset);
        }
        if (aud_context_p->end_offset != 0)
        {
            mhdl_handle->SetStopTime(mhdl_handle, aud_context_p->end_offset);
        }
        parser_start_time = aud_context_p->start_offset;
    }

    /* Get total duration to check if already play to file end */
    {
        kal_uint32 med_duration, time_scale;
        
        eMp4ParserRet = MP4_GetMediaDuration(g_aud_mp4_parser.stMp4Parser_aud, &med_duration, MP4_TRACK_AUDIO);
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto pure_audio_error_out;
        }    

        eMp4ParserRet = MP4_GetMediaTimeScale(g_aud_mp4_parser.stMp4Parser_aud, &time_scale, MP4_TRACK_AUDIO);
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto pure_audio_error_out;
        }

        /* Caculate duration in milliseconds */
        if(time_scale > 0)
        {
            aud_duration = (kal_uint32)(((kal_uint64)med_duration  * (kal_uint64)1000) / (kal_uint64)time_scale);
        }
        else
        {
            result = MED_RES_FAIL;
            goto pure_audio_error_out;    
        }
        AUD_VALUE_TRACE(aud_duration, -1, __LINE__);
    }

    /* Seek to MP4 frame by using start time */
    {
        kal_uint32 uSampleNo;

        eMp4ParserRet =  MP4_Audio_TimeToSampleNo(g_aud_mp4_parser.stMp4Parser_aud, parser_start_time, &uSampleNo );
        AUD_VALUE_TRACE(eMp4ParserRet, -1, __LINE__);
        if((eMp4ParserRet == MP4_PARSER_NO_SUCH_SAMPLE) && (parser_start_time >= aud_duration))
        {
            result = MED_RES_END_OF_FILE;
            goto pure_audio_error_out;
        }
        else if(eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto pure_audio_error_out;
        }

        eMp4ParserRet =  MP4_Audio_Seek(g_aud_mp4_parser.stMp4Parser_aud, uSampleNo);
        AUD_VALUE_TRACE(eMp4ParserRet, -1, __LINE__);
        if(eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto pure_audio_error_out; 
        }
    }

    /* Fill up ring buffer before play */
    {
        kal_uint8 *pBuf;
        kal_uint32 num_bytes;
        kal_uint32 buf_len;

        /*Need to fill up header for amr/awb play */
        if(audio_format == MED_TYPE_AMR)
        {
            mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
            kal_mem_cpy(pBuf, aud_file_header[0].header, aud_file_header[0].size);
            mhdl_handle->WriteDataDone(mhdl_handle, aud_file_header[0].size );
        }
        else if(audio_format == MED_TYPE_AMR_WB)
        {
            mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
            kal_mem_cpy(pBuf, aud_file_header[1].header, aud_file_header[1].size);
            mhdl_handle->WriteDataDone(mhdl_handle, aud_file_header[1].size );
        }

        mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
        eMp4ParserRet = MP4_Audio_Read(g_aud_mp4_parser.stMp4Parser_aud, pBuf, buf_len, &num_bytes);
        AUD_VALUE_TRACE(eMp4ParserRet, num_bytes, __LINE__);

        if((num_bytes == 0) && (parser_start_time >= aud_duration))
        {
            result = MED_RES_END_OF_FILE;
            goto pure_audio_error_out;        
        }
        if(eMp4ParserRet == MP4_PARSER_READ_EOF)
        {
            is_data_finish = KAL_TRUE;
        }
        if((eMp4ParserRet != MP4_PARSER_OK) && (eMp4ParserRet != MP4_PARSER_READ_EOF))
        {
            result = MED_RES_FAIL;
            goto pure_audio_error_out;
        }

        mhdl_handle->WriteDataDone(mhdl_handle, num_bytes );
    }

#ifdef __MED_BT_A2DP_MOD__
#if defined(__BTMTK__)
    aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
#endif
#endif /* __MED_BT_A2DP_MOD__ */ 

    /* Begin Play */
    play_result = mhdl_handle->Play(mhdl_handle);
    AUD_VALUE_TRACE(play_result, -1, __LINE__);

    if (play_result != MEDIA_SUCCESS)
    {
        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);

        result = aud_get_res(play_result);
        goto pure_audio_error_out;          
    }

    if(is_data_finish)
    {
        mhdl_handle->DataFinished(mhdl_handle);
    }

    result = MED_RES_OK;
    AUD_ENTER_STATE(AUD_MEDIA_PLAY);

    return result;

pure_audio_error_out:
    if(is_aud_opened)
    {
        mhdl_handle->Close(mhdl_handle);
        aud_context_p->last_mhdl_handle = NULL;
    }

    if (is_file_opened)
    {
        FSAL_Close(&current_file_stream);
        aud_media_free_mp4_parser();        
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_replay_audio_track_in_video
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  play_style      [IN]        
 *  replay          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint8 aud_media_replay_audio_track_in_video(kal_uint8 play_style, kal_bool replay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Parser_Status eMp4ParserRet;
    MHdl *mhdl_handle;
    kal_uint8 result;
    kal_uint32 parser_start_time;
    kal_uint32 aud_duration;
    kal_bool is_data_finish = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mhdl_handle = aud_context_p->last_mhdl_handle;
    ASSERT(mhdl_handle != NULL);
    
    /* Play again */
    if (replay)
    {
        /* follow ring tone volume */
        aud_set_active_ring_tone_volume();
        /* To start ascending timer */
        aud_melody_start_crescendo(play_style);

        mhdl_handle->SetStartTime(mhdl_handle, aud_context_p->start_offset);
        parser_start_time = aud_context_p->start_offset;

        if (aud_context_p->end_offset != 0)
        {
            mhdl_handle->SetStopTime(mhdl_handle, aud_context_p->end_offset);
        }
    }
    /* Resume from Pause */
    else
    {
        mhdl_handle->SetStartTime(mhdl_handle, temp_pause_time);    
        parser_start_time = temp_pause_time;
    }

    /* Reset buffer to fill new data */
    mhdl_handle->ResetMediaBuf(mhdl_handle);

    /* Get total duration to check if already play to file end */
    {
        kal_uint32 med_duration, time_scale;
        
        eMp4ParserRet = MP4_GetMediaDuration(g_aud_mp4_parser.stMp4Parser_aud, &med_duration, MP4_TRACK_AUDIO);
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto replay_audio_error_out;
        }    

        eMp4ParserRet = MP4_GetMediaTimeScale(g_aud_mp4_parser.stMp4Parser_aud, &time_scale, MP4_TRACK_AUDIO);
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto replay_audio_error_out;
        }

        /* Caculate duration in milliseconds */
        if(time_scale > 0)
        {
            aud_duration = (kal_uint32)(((kal_uint64)med_duration  * (kal_uint64)1000) / (kal_uint64)time_scale);
        }
        else
        {
            result = MED_RES_FAIL;
            goto replay_audio_error_out;    
        }
        AUD_VALUE_TRACE(aud_duration, -1, __LINE__);
    }

    /* Seek to MP4 frame by using start time */
    {
        kal_uint32 uSampleNo;

        eMp4ParserRet =  MP4_Audio_TimeToSampleNo(g_aud_mp4_parser.stMp4Parser_aud, parser_start_time, &uSampleNo );
        AUD_VALUE_TRACE(eMp4ParserRet, -1, __LINE__);
        if((eMp4ParserRet == MP4_PARSER_NO_SUCH_SAMPLE) && (parser_start_time >= aud_duration))
        {
            result = MED_RES_END_OF_FILE;
            goto replay_audio_error_out;
        }
        else if(eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MED_RES_FAIL;
            goto replay_audio_error_out;
        }
        
        eMp4ParserRet =  MP4_Audio_Seek(g_aud_mp4_parser.stMp4Parser_aud, uSampleNo);
        AUD_VALUE_TRACE(eMp4ParserRet, -1, __LINE__);
        if(eMp4ParserRet != MP4_PARSER_OK)
        {
            result = MEDIA_FAIL;
            goto replay_audio_error_out; 
        }
    }

    /* Fill up ring buffer before play */
    {
        Media_Format audio_format;    
        kal_uint8 *pBuf;
        kal_uint32 num_bytes;
        kal_uint32 buf_len;

        audio_format = MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(g_aud_mp4_parser.stMp4Parser_aud));

        /*Need to fill up header for amr/awb play */
        if(audio_format == MEDIA_FORMAT_AMR)
        {
            mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
            kal_mem_cpy(pBuf, aud_file_header[0].header, aud_file_header[0].size);
            mhdl_handle->WriteDataDone(mhdl_handle, aud_file_header[0].size );
        }
        else if(audio_format == MEDIA_FORMAT_AMR_WB)
        {
            mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
            kal_mem_cpy(pBuf, aud_file_header[1].header, aud_file_header[1].size);
            mhdl_handle->WriteDataDone(mhdl_handle, aud_file_header[1].size );
        }

        mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
        eMp4ParserRet = MP4_Audio_Read(g_aud_mp4_parser.stMp4Parser_aud, pBuf, buf_len, &num_bytes);
        AUD_VALUE_TRACE(eMp4ParserRet, num_bytes, __LINE__);

        if((num_bytes == 0) && (parser_start_time >= aud_duration))
        {
            result = MED_RES_END_OF_FILE;
            goto replay_audio_error_out;        
        }
        if(eMp4ParserRet == MP4_PARSER_READ_EOF)
        {
            is_data_finish = KAL_TRUE;
        }
        if((eMp4ParserRet != MP4_PARSER_OK) && (eMp4ParserRet != MP4_PARSER_READ_EOF))
        {
            result = MEDIA_FAIL;
            goto replay_audio_error_out;             
        }
      
        mhdl_handle->WriteDataDone(mhdl_handle, num_bytes );
    }

    result = mhdl_handle->Play(mhdl_handle);
    AUD_VALUE_TRACE(result, -1, __LINE__);

replay_audio_error_out:
    if (result != MEDIA_SUCCESS)
    {
        mhdl_handle->Close(mhdl_handle);
        FSAL_Close(&current_file_stream);
        aud_media_free_mp4_parser();

        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);
        AUD_ENTER_STATE(AUD_MEDIA_IDLE);
        
        return aud_get_res(result);
    }
    
    if(is_data_finish)
    {
        mhdl_handle->DataFinished(mhdl_handle);
    }
    AUD_ENTER_STATE(AUD_MEDIA_PLAY);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_pause_audio_track_in_video
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  res     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool aud_media_pause_audio_track_in_video(kal_uint8 **res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl *mhdl_handle;
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mhdl_handle = aud_context_p->last_mhdl_handle;
    ASSERT(mhdl_handle != NULL);

    switch (aud_context_p->current_format)
    {
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
            break;

        default:
            return KAL_FALSE;
    }

    temp_pause_time = mhdl_handle->GetCurrentTime(mhdl_handle);
    result = mhdl_handle->Stop(mhdl_handle);

    if (result == MEDIA_SUCCESS)
    {
        **res = MED_RES_OK;
        AUD_ENTER_STATE(AUD_MEDIA_PLAY_PAUSED);
    }
    else
    {
        /* Close handle */
        mhdl_handle->Close(mhdl_handle);
        FSAL_Close(&current_file_stream);
        aud_media_free_mp4_parser();
        aud_context_p->last_mhdl_handle = NULL;
 
        AUD_ENTER_STATE(AUD_MEDIA_IDLE);

        /* stop volume crescendo timer */
        med_stop_timer(AUD_TIMER_CRESCENDO);

        **res = aud_get_res((kal_uint8) result);
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_resume_audio_track_in_video
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  res     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool aud_media_resume_audio_track_in_video(kal_uint8 **res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (aud_context_p->current_format)
    {
        case MED_TYPE_3GP:
        case MED_TYPE_MP4:
            break;

        default:
            return KAL_FALSE;
    }

    /* Seek while paused state, need to replay again for resume */
    if (aud_context_p->state == AUD_MEDIA_SEEK_PAUSED ||
        aud_context_p->state == AUD_MEDIA_PLAY_PAUSED)
    {
    #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
        aud_bt_a2dp_open_codec((kal_int32)aud_context_p->current_format);
    #endif
    
        **res = aud_media_replay_audio_track_in_video(0, KAL_FALSE);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_process_audio_track_in_video
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool aud_media_process_audio_track_in_video(kal_uint8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MHdl *mhdl_handle;
    Media_Event result;
    kal_uint8 replay_result = MED_RES_FAIL;
    kal_uint8 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->state != AUD_MEDIA_PLAY)
    {
        return KAL_TRUE;
    }

    mhdl_handle = aud_context_p->last_mhdl_handle;
    ASSERT(mhdl_handle != NULL);

    result = mhdl_handle->Process(mhdl_handle, (Media_Event) event);

    /* Request more data to play */
    AUD_VALUE_TRACE(result, -1, __LINE__)

    switch(result)
    {
        case MEDIA_UPDATE_DUR:
            break;

        /* Fill up more data to buffer */
        case MEDIA_DATA_REQUEST:
        {
            kal_uint8 *pBuf;
            kal_uint32 buf_len;
            kal_uint32 num_bytes, cnt = 0;
            MP4_Parser_Status eMP4Status;

            do{
                mhdl_handle->GetWriteBuffer(mhdl_handle, &pBuf, &buf_len);
                if(buf_len == 0)
                {
                    break;
                }    
                eMP4Status = MP4_Audio_Read(g_aud_mp4_parser.stMp4Parser_aud, pBuf, buf_len, &num_bytes);
                AUD_VALUE_TRACE(eMP4Status, num_bytes, __LINE__)
                if(eMP4Status == MP4_PARSER_READ_EOF)
                {
                    mhdl_handle->DataFinished(mhdl_handle);
                }
                
                if((eMP4Status != MP4_PARSER_OK) && (eMP4Status != MP4_PARSER_READ_EOF))
                {
                    mhdl_handle->DataFinished(mhdl_handle);                	
                    return MEDIA_READ_ERROR;
                }
                mhdl_handle->WriteDataDone(mhdl_handle, num_bytes );
            }while(++cnt < 2);

            /* To inform audio driver to callback when need more data */
            mhdl_handle->FinishWriteData(mhdl_handle);
            break;
        }
        /* Stop and close video's audio play */
        case MEDIA_END:
        case MEDIA_ERROR:
        case MEDIA_STOP_TIME_UP:
            /* Enter AUD_MEDIA_IDLE state */
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);

            /* Stop volume crescendo timer */
            med_stop_timer(AUD_TIMER_CRESCENDO);

            /* Stop play */
            temp_last_time = mhdl_handle->GetCurrentTime(mhdl_handle);
            mhdl_handle->Stop(mhdl_handle);

            aud_context_p->last_seq_no++;

            /* Play again */
            if ((result == MEDIA_END || result == MEDIA_STOP_TIME_UP) && (aud_context_p->play_style != DEVICE_AUDIO_PLAY_ONCE))
            {
                replay_result = aud_media_replay_audio_track_in_video(aud_context_p->play_style, KAL_TRUE);
            }
            else    /* No replay, clost it */
            {
                mhdl_handle->Close(mhdl_handle);
                /* Close file */
                FSAL_Close(&current_file_stream);
                aud_media_free_mp4_parser();
                aud_context_p->last_mhdl_handle = NULL;
                aud_context_p->cache_p = NULL;
            }

            AUD_VALUE_TRACE(result, replay_result, aud_context_p->play_style);

            /* No replay or replay fail, send finish indication message */
            if (replay_result != MED_RES_OK)
            {
                if ((result == MEDIA_END || result == MEDIA_STOP_TIME_UP) && (aud_context_p->play_style == DEVICE_AUDIO_PLAY_ONCE))
                {
                    res = MED_RES_END_OF_FILE;
                }
                else if(result == MEDIA_DECODER_UNSUPPORT)
                {
                    res = MED_RES_DECODER_NOT_SUPPORT;
                }                
                else
                {
                    res = MED_RES_ERROR;
                }

                if (aud_context_p->play_mode == AUD_MEDIA_PLAY_AS_RING)
                {
                    aud_send_audio_play_finish_ind(res);
                }
                else
                {
                    aud_send_media_play_finish_ind(res);
                }
            }

            break;

        case MEDIA_NONE:
            break;
        default:
            ASSERT(0);
            break;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_media_get_audio_duration_in_video
 * DESCRIPTION
 *  This function is to get the data length of an audio file with filename
 * PARAMETERS
 *
 * RETURNS
 * kal_uint8   result
 *****************************************************************************/
static kal_uint8 aud_media_get_audio_duration_in_video(kal_wchar *file_name, kal_uint8 *aud_data, kal_uint32 aud_len, kal_int16 format, kal_uint32* duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    kal_uint8 result;
    kal_bool is_file_opened = KAL_FALSE;
    kal_bool has_aud_track;
    kal_uint32 aud_duration, med_duration, time_scale;

    STMp4Parser *stMp4Parser_aud;
    STFSAL *stFSAL_aud;
    kal_uint32 *mp4_aud_buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Open file for playing */
    stFSAL_aud = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));    
    eFSALRet = FSAL_Open(stFSAL_aud, (void*)file_name, FSAL_READ); 

    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }

    /* Allocate working buffer for operation */    
    is_file_opened = KAL_TRUE;

    stMp4Parser_aud = (STMp4Parser*)get_ctrl_buffer(sizeof(STMp4Parser));
    mp4_aud_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32) );

    /* Set buffer for FSAL */
    FSAL_SetBuffer(stFSAL_aud, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_aud_buf);

    /* Creat MP4 parser */
    eMp4ParserRet = MP4_Parse(stMp4Parser_aud, stFSAL_aud);

    if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        result = MED_RES_BAD_FORMAT;
        goto pure_audio_error_out;
    }

    /* Check if there's audio track */
    MP4_MetaHasAudioTrack(stMp4Parser_aud, &has_aud_track);
    if (!has_aud_track)
    {
        result = MED_RES_MP4_NO_AUDIO_TRACK;
        goto pure_audio_error_out;
    }

    /* Get media duration and time scale to count duration in milliseconds */
    eMp4ParserRet = MP4_GetMediaDuration(stMp4Parser_aud, &med_duration, MP4_TRACK_AUDIO);
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        result = MED_RES_PARSER_ERROR;
        goto pure_audio_error_out;
    }    

    eMp4ParserRet = MP4_GetMediaTimeScale(stMp4Parser_aud, &time_scale, MP4_TRACK_AUDIO);
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        result = MED_RES_PARSER_ERROR;
        goto pure_audio_error_out;
    }

    /* Caculate duration in milliseconds */
    if(time_scale > 0)
    {
        aud_duration = (kal_uint32)(((kal_uint64)med_duration  * (kal_uint64)1000) / (kal_uint64)time_scale);
    }
    else
    {
        result = MED_RES_PARSER_ERROR;
        goto pure_audio_error_out;    
    }

    *duration = aud_duration;
    result = MED_RES_OK;

pure_audio_error_out:
    if (is_file_opened)
    {
        FSAL_Close(stFSAL_aud);

        free_ctrl_buffer(stMp4Parser_aud);        
        med_free_ext_mem((void**)&mp4_aud_buf);
    }

    free_ctrl_buffer(stFSAL_aud);

    if(result != MED_RES_OK)
    {
        *duration = 0;    
    }

    return result;
}
#endif /* #if defined(MED_PURE_AUDIO) */

/*****************************************************************************
 * FUNCTION
 *  aud_media_is_pure_audio_req_hdlr
 * DESCRIPTION
 *  This function is to check if the file is pure audio file
 * PARAMETERS
 *
 * RETURNS
 * void
 *****************************************************************************/
void aud_media_is_pure_audio_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(MED_PURE_AUDIO)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_check_is_pure_audio_req_struct *msg_p = (media_aud_check_is_pure_audio_req_struct*) ilm_ptr->local_para_ptr;
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    kal_uint8 result;
    kal_bool is_file_opened = KAL_FALSE;
    kal_bool has_aud_track, has_vid_track;

    STMp4Parser *stMp4Parser_aud = NULL;
    STFSAL *stFSAL_aud;
    kal_uint32 *mp4_aud_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Open file for playing */
    stFSAL_aud = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));    
    eFSALRet = FSAL_Open(stFSAL_aud, (void*)msg_p->file_name, FSAL_READ); 

    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }

    /* Allocate working buffer for operation */    
    is_file_opened = KAL_TRUE;

    stMp4Parser_aud = (STMp4Parser*)get_ctrl_buffer(sizeof(STMp4Parser));
    mp4_aud_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32) );

    /* Set buffer for FSAL */
    FSAL_SetBuffer(stFSAL_aud, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_aud_buf);

    /* Creat MP4 parser */
    eMp4ParserRet = MP4_Parse(stMp4Parser_aud, stFSAL_aud);

    if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        result = MED_RES_BAD_FORMAT;
        goto pure_audio_error_out;
    }

    /* Check if there's audio track */
    MP4_MetaHasAudioTrack(stMp4Parser_aud, &has_aud_track);
    if (!has_aud_track)
    {
        result = MED_RES_MP4_NO_AUDIO_TRACK;
        goto pure_audio_error_out;
    }

    /* Check if there's video track */
    MP4_MetaHasVideoTrack(stMp4Parser_aud, &has_vid_track);
    if (has_vid_track)
    {
        result = MED_RES_ERROR;
        goto pure_audio_error_out;
    }

    result = MED_RES_OK;
    aud_set_result(KAL_TRUE);

pure_audio_error_out:
    AUD_VALUE_TRACE(result, -1, __LINE__);
    
    if (is_file_opened)
    {
        FSAL_Close(stFSAL_aud);

        free_ctrl_buffer(stMp4Parser_aud);        
        med_free_ext_mem((void**)&mp4_aud_buf);
    }

    free_ctrl_buffer(stFSAL_aud);

    if(result != MED_RES_OK)
    {
        aud_set_result(KAL_FALSE);
    }

    AUD_SET_EVENT(AUD_EVT_IS_PURE_AUDIO);
    
#else

    aud_set_result(KAL_FALSE);
    AUD_SET_EVENT(AUD_EVT_IS_PURE_AUDIO);
    
#endif /* #if defined(MED_PURE_AUDIO) */
}


#endif /* MED_NOT_PRESENT */ 

