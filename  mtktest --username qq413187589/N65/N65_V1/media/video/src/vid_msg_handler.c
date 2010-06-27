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
 *   vid_msg_handler.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of video module.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"         /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "fat_fs.h"
#include "custom_equipment.h"
#include "custom_video.h"

#include "rtc_sw.h"
#include "lcd_if.h"
#include "lcd_sw_inc.h"
#ifdef ISP_SUPPORT
#include "isp_if.h"
#endif 

#ifdef MP4_CODEC
#include "FSAL.h"
#include "MP4_Parser.h"
#include "MP4_Producer_Audio.h"
#include "MP4_Sample_Data_Audio.h"
#include "video_file_creator.h"
#include "drv_comm.h"
#include "visual_comm.h"
#include "bmd.h"
#include "video_enc_glb.h"
#include "video_dec_glb.h"
#include "video_glb.h"
#include "img_comm.h"
#endif /* MP4_CODEC */ 

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_smalloc.h"
#include "cam_main.h"
#include "vid_main.h"
#include "aud_main.h"
#include "img_main.h"

#ifdef MP4_CODEC
#include "med_v_main.h"
#include "med_v_struct.h"
#endif /* MP4_CODEC */ 

#if defined(__MED_MJPG_MOD__)
#include "jpeg.h"
#include "visualhisr.h"
#include "med_v_main.h"
#include "med_v_struct.h"
#include "vid_avi.h"
#include "swimg_resizer.h"
#endif /* defined(__MED_MJPG_MOD__) */ 

#if MT6228_SERIES
#include "imgdma.h"
#endif 

#ifdef __VID_TRACE_ON__
#include "med_trc.h"
#endif 

#include "Fs_errcode.h"
#include "Drm_gprot.h"  

#ifdef __SF_MP4_SUPPORT__
#include "fmt_def.h"
#endif   //__SF_MP4_SUPPORT__

#if defined(__MED_VID_MOD__)
/***************************************************************************** 
 * Source Code of MED_VID_MOD
 * MT6219 SERIES, MT6228_SERIES....
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VIDEO_RECORD_CIF_MEM_MARGIN     (150*1024)  /* CIF worst case */
#define VIDEO_RECORD_QCIF_MEM_MARGIN    (50*1024)   /* QCIF worst case */
#define VID_DEC_SEEK_HINT_SIZE          (2047)

#define VID_AMR_HEADER                  "#!AMR\n"
#define VID_AMR_HEADER_SIZE             (6)

#define VID_AMR_WB_HEADER               "#!AMR-WB\n"
#define VID_AMR_WB_HEADER_SIZE          (9)

#define VID_VOL_LEVEL_NOT_USED          (0xff)

typedef MHdl *(*vid_aud_open_func_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);

/* stop time */
#define VID_MAX_STOP_TIME           ((kal_uint64)(-1))      /* 64 bits */
#define VID_STOP_TIME_CHECK_ELAPSE  (300)                   /* 300ms check once */

#ifdef  __MED_VID_EDT_MOD__
#define VIDEO_EDT_DATA_P_COUNT            (5)
#else
#define VIDEO_EDT_DATA_P_COUNT            (0)
#endif

#ifdef __MED_CAM_MOD__
extern kal_uint8 cam_rotate_map[CAM_NO_OF_IMAGE_ROTATE];
#endif 


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct {
    kal_bool is_used;               /* this data entry is used or not */
    kal_uint8 media_mode;           /* the media mode like file, array, stream */
    kal_uint8 media_type;           /* 3GP, ... */
    kal_int32 file_handle;          /* the file handle of the file */
    kal_uint32 audio_frame_num;     /* the frame number of audio */
    kal_uint32 total_frame_num;     /* the total frame number of video file */
    kal_uint64 current_time;        /* the current time duration of the video play */
    kal_uint64 total_audio_time;    /* the total audio time duration of the video file */
    kal_uint64 total_video_time;    /* the total video duration of the video file */
    kal_uint64 total_time;          /* the total time duration of the video file */
    kal_uint8 video_track;          /* video track: audio, visual or both */
    kal_uint16 image_width;         /* the image width after decoder and resizer */
    kal_uint16 image_height;        /* the image height after decoder and resizer */
    kal_uint16 max_width;           /* the max image width expected for the play */
    kal_uint16 max_height;          /* the max image height expected for the play */
    
    Media_Format aud_format;        /* audio format */

    /* FSAL and other video context */
    MP4DEC_IMGPATH_STRUCT image_data_path;
    STMp4Parser stMp4Parser_a;
    STMp4Parser stMp4Parser_v;
    STFSAL stFSAL_a;
    STFSAL stFSAL_v;
    STFSAL stFSAL_a_stsz;
    STFSAL stFSAL_a_stco;
    STFSAL stFSAL_v_stsz;
    STFSAL stFSAL_v_stco;
    STFSAL stFSAL_aud_data;
    
    MP4DEC_MEMMODE_STRUCT memmode_input;

    kal_uint32 mp4_aud_buf[VID_MP4_FSAL_BUF_SIZE];             
    kal_uint32 mp4_vid_buf[VID_MP4_FSAL_BUF_SIZE];             
    kal_uint32 mp4_aud_data_buf[VID_MP4_FSAL_BUF_SIZE];
    kal_uint32 mp4_vid_stco_buf[VID_MP4_STCO_BUF_SIZE];           
    kal_uint32 mp4_aud_stco_buf[VID_MP4_STCO_BUF_SIZE];           
    kal_uint32 mp4_vid_stsz_buf[VID_MP4_STSZ_BUF_SIZE];           
    kal_uint32 mp4_aud_stsz_buf[VID_MP4_STSZ_BUF_SIZE];
    kal_uint32 mp4_stbl_buf[VID_MP4_STBL_BUF_SIZE];  
    
    FS_FileLocationHint vid_seek_hint[VID_DEC_SEEK_HINT_SIZE];
} video_data_struct;


typedef struct{
    STMp4Parser parser;
    STFSAL stFSAL_mp4;
    STFSAL stFSAL_aud_data;   
    STFSAL stFSAL_stsz;
    STFSAL stFSAL_stco;
    kal_uint32 mp4_buf[VID_MP4_FSAL_BUF_SIZE]; 
    kal_uint32 aud_data_buf[VID_MP4_FSAL_BUF_SIZE];
    kal_uint32 stco_buf[VID_MP4_STCO_BUF_SIZE]; 
    kal_uint32 stsz_buf[VID_MP4_STSZ_BUF_SIZE];  
    kal_uint32 stbl_buf[VID_MP4_STBL_BUF_SIZE]; 
    FS_FileLocationHint seek_hint[VID_DEC_SEEK_HINT_SIZE];
} video_mp4parser_struct;


typedef enum
{
    VID_MP4PARSER_SILENCE = 0,
#ifdef __MED_VID_EDT_BGM_SUPPORT__
    VID_MP4PARSER_BGM,
#endif
    VID_MP4PARSER_AUD_TYPE_COUNT
}video_mp4parser_aud_type_enum;


/***************************************************************************** 
 * Variable 
 *****************************************************************************/
/*****************/
/*    DECODER    */
/*****************/
kal_int32 vid_play_mem[2] = {MAX_VID_DEC_INT_MEM_SIZE, MAX_VID_DEC_EXT_MEM_SIZE};

/* the lcd data for play and replay */
lcd_frame_update_struct lcd_data;

MP4DEC_IMGPATH_STRUCT *image_data_path_ptr;
STMp4Parser *stMp4Parser_a_ptr;
STMp4Parser *stMp4Parser_v_ptr;
STFSAL *stFSAL_a_ptr;
STFSAL *stFSAL_v_ptr;
STFSAL *stFSAL_a_stsz_ptr;
STFSAL *stFSAL_a_stco_ptr;
STFSAL *stFSAL_v_stsz_ptr;
STFSAL *stFSAL_v_stco_ptr;
STFSAL *stFSAL_aud_data_ptr;
MP4DEC_MEMMODE_STRUCT *memmode_input_ptr;

FS_FileLocationHint *vid_seek_hint_ptr;
kal_uint32 *mp4_aud_buf_ptr;    
kal_uint32 *mp4_vid_buf_ptr; 
kal_uint32 *mp4_aud_data_buf_ptr;
kal_uint32 *mp4_vid_stco_buf_ptr;
kal_uint32 *mp4_aud_stco_buf_ptr;
kal_uint32 *mp4_vid_stsz_buf_ptr;
kal_uint32 *mp4_aud_stsz_buf_ptr;
kal_uint32 *mp4_stbl_buf_ptr;


/* extern from VIS */
extern kal_uint32 buffer_enc_tmp[1024 / 4];
extern kal_uint32 buffer_enc_real_meta_tmp[1024 / 4];
extern kal_uint32 buffer_merge_buffer[1024];
extern kal_uint32 buffer_enc_audio_sample_tmp[1024 / 4];
extern kal_uint32 buffer_enc_audio_tmp[1024 / 4];


MP4_FILELIST_STRUCT mp4_files;


#if defined(__MED_VID_ENC_MOD__)
/*****************/
/*    ENCODER    */
/*****************/
kal_int32 vid_record_mem[2] = {MAX_VID_ENC_INT_MEM_SIZE, MAX_VID_ENC_EXT_MEM_SIZE};
STFSAL stFSALProducerAudData;
STFSAL stFSALProducerAudMeta;
STMp4Producer stMp4Producer;
mpeg4_encode_process_struct mp4_encode;
#endif /* defined(__MED_VID_ENC_MOD__) */


#if defined(__MED_VID_PDL_MOD__)
/***********************/
/*    PROGRESSIVE DL   */
/***********************/
STMp4Parser stMp4Parser_pdl_a;
STMp4Parser stMp4Parser_pdl_v;
STFSAL stFSAL_pdl_a;
STFSAL stFSAL_pdl_v;
STFSAL stFSAL_pdl_a_stsz;
STFSAL stFSAL_pdl_v_stsz;
STFSAL stFSAL_pdl_a_stco;
STFSAL stFSAL_pdl_v_stco;
kal_uint32 mp4_pdl_aud_buf[VID_MP4_FSAL_BUF_SIZE];             
kal_uint32 mp4_pdl_vid_buf[VID_MP4_FSAL_BUF_SIZE];             
kal_uint32 mp4_pdl_aud_stco_buf[VID_MP4_STCO_BUF_SIZE];           
kal_uint32 mp4_pdl_vid_stco_buf[VID_MP4_STCO_BUF_SIZE];           
kal_uint32 mp4_pdl_aud_stsz_buf[VID_MP4_STSZ_BUF_SIZE];   
kal_uint32 mp4_pdl_vid_stsz_buf[VID_MP4_STSZ_BUF_SIZE];   
kal_uint32 mp4_pdl_stbl_buf[VID_MP4_STBL_BUF_SIZE];  
#endif /* defined(__MED_VID_PDL_MOD__) */

#ifdef __MED_VID_EDT_MOD__
/****************/
/*    EDITOR    */
/****************/
/* audio */
video_mp4parser_struct *video_edt_aud_mp4parser_p[VID_MP4PARSER_AUD_TYPE_COUNT];


VEDITOR_AVSYNC_AUDIO_STRUCT vid_edt_audio_avsync;
video_data_struct *video_data_list_p[VIDEO_EDT_DATA_P_COUNT];
#endif /* __MED_VID_EDT_MOD__ */

video_data_struct video_data;


/***************************************************************************** 
 * Local Functions 
 *****************************************************************************/
kal_int32 vid_open_play_file(void);
kal_int16 vid_close_visual_file_for_record(void);
kal_int16 vid_close_audio_file_for_record(void);
kal_int32 vid_dump_record_data_to_file(void);

#ifdef __MED_VID_PDL_MOD__
void vid_pdl_meta_buffering_hdlr(void *arg);
kal_int32 vid_check_pdl_file_meta(void);
#endif

#ifdef  __MED_VID_EDT_MOD__
static kal_int32 vid_edt_create_aud_mp4parser(
        video_mp4parser_struct *p,
        kal_uint8 *data_p,
        kal_uint32 data_size,
        kal_uint8 media_mode,
        kal_uint8 media_type,
        kal_uint64 *aud_duration_p);
#endif /*  __MED_VID_EDT_MOD__ */

/*****************************************************************************
 * FUNCTION
 *  vid_get_data_buffer
 * DESCRIPTION
 *  find data buffer.
 * PARAMETERS
 *  handle          [IN]        handle of the video data
 * RETURNS
 *  the pointer to the data buffer
 *****************************************************************************/
video_data_struct *vid_get_data_buffer(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MED_VID_EDT_MOD__    
    kal_int32 index = 0;
#endif /* __MED_VID_EDT_MOD__ */    
    video_data_struct *video_data_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == (kal_int32) &video_data)
    {
        video_data_p = & video_data;
    }
    else
    {
    #ifdef __MED_VID_EDT_MOD__     
        for (index = 0; index < VIDEO_EDT_DATA_P_COUNT; index++)
        {
            if (handle == (kal_int32)video_data_list_p[index])
            {
                /* hit! */
                video_data_p = video_data_list_p[index];
                break;
            }
        }
        if (index == VIDEO_EDT_DATA_P_COUNT)
        {
            /* miss - maybe already freed */
            ASSERT(0);
        }
    #endif /* __MED_VID_EDT_MOD__ */
    }
    
    if (video_data_p == NULL)
    {
        /* miss - maybe already freed */
        ASSERT(0);
    }


    return video_data_p;
}


/*****************************************************************************
 * FUNCTION
 *  vid_load_video_working_data_buf
 * DESCRIPTION
 *  Load video working data buffer.
 * PARAMETERS
 *  handle          [IN]        handle of the video data
 * RETURNS
 *  void 
 *****************************************************************************/
void vid_load_video_working_data_buf(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_data_struct *video_data_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_LOAD_VIDEO_WORKING_DATA_BUF, handle);

    video_data_p = vid_get_data_buffer(handle);    
    if (video_data_p == NULL)
    {
        /* miss - maybe already freed */
        ASSERT(0);
    }

    image_data_path_ptr     = &video_data_p->image_data_path;
    stMp4Parser_a_ptr       = &video_data_p->stMp4Parser_a;
    stMp4Parser_v_ptr       = &video_data_p->stMp4Parser_v;
    stFSAL_a_ptr            = &video_data_p->stFSAL_a;
    stFSAL_v_ptr            = &video_data_p->stFSAL_v;
    stFSAL_a_stsz_ptr       = &video_data_p->stFSAL_a_stsz;
    stFSAL_a_stco_ptr       = &video_data_p->stFSAL_a_stco;
    stFSAL_v_stsz_ptr       = &video_data_p->stFSAL_v_stsz;
    stFSAL_v_stco_ptr       = &video_data_p->stFSAL_v_stco;
    stFSAL_aud_data_ptr     = &video_data_p->stFSAL_aud_data;
    memmode_input_ptr       = &video_data_p->memmode_input;
    
    mp4_aud_buf_ptr         = video_data_p->mp4_aud_buf;    
    mp4_vid_buf_ptr         = video_data_p->mp4_vid_buf; 
    mp4_aud_data_buf_ptr    = video_data_p->mp4_aud_data_buf;
    mp4_vid_stco_buf_ptr    = video_data_p->mp4_vid_stco_buf;
    mp4_aud_stco_buf_ptr    = video_data_p->mp4_aud_stco_buf;
    mp4_vid_stsz_buf_ptr    = video_data_p->mp4_vid_stsz_buf;
    mp4_aud_stsz_buf_ptr    = video_data_p->mp4_aud_stsz_buf;
    mp4_stbl_buf_ptr        = video_data_p->mp4_stbl_buf;
    vid_seek_hint_ptr       = video_data_p->vid_seek_hint;
}


/*****************************************************************************
 * FUNCTION
 *  vid_load_video_working_data_var
 * DESCRIPTION
 *  Load video working data variables.
 * PARAMETERS
 *  handle          [IN]        handle of the video data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_load_video_working_data_var(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_data_struct *video_data_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_LOAD_VIDEO_WORKING_DATA_VAR, handle);
    
    video_data_p = vid_get_data_buffer(handle);
    
    if (video_data_p == NULL)
    {
        /* miss - maybe already freed */
        ASSERT(0);
    }
   
    vid_context_p->media_mode       = video_data_p->media_mode;
    vid_context_p->media_type       = video_data_p->media_type;
    vid_context_p->file_handle      = video_data_p->file_handle;
    vid_context_p->audio_frame_num  = video_data_p->audio_frame_num;
    vid_context_p->total_frame_num  = video_data_p->total_frame_num;
    vid_context_p->current_time     = video_data_p->current_time;
    vid_context_p->total_audio_time = video_data_p->total_audio_time;
    vid_context_p->total_video_time = video_data_p->total_video_time;
    vid_context_p->total_time       = video_data_p->total_time;
    vid_context_p->video_track      = video_data_p->video_track;
    vid_context_p->image_width      = video_data_p->image_width;
    vid_context_p->image_height     = video_data_p->image_height;
    vid_context_p->max_width        = video_data_p->max_width;
    vid_context_p->max_height       = video_data_p->max_height;
    vid_context_p->aud_format       = video_data_p->aud_format;
}


/*****************************************************************************
 * FUNCTION
 *  vid_store_video_working_data_var
 * DESCRIPTION
 *  Store video working data variables.
 * PARAMETERS
 *  handle          [IN]        handle of the video data
 * RETURNS
 *  void 
 *****************************************************************************/
void vid_store_video_working_data_var(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_data_struct *video_data_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STORE_VIDEO_WORKING_DATA_VAR, handle);
        
    video_data_p = vid_get_data_buffer(handle);
    
    if (video_data_p == NULL)
    {
        /* miss - maybe already freed */
        ASSERT(0);
    }
    
    video_data_p->media_mode        = vid_context_p->media_mode;
    video_data_p->media_type        = vid_context_p->media_type;
    video_data_p->file_handle       = vid_context_p->file_handle;
    video_data_p->audio_frame_num   = vid_context_p->audio_frame_num;
    video_data_p->total_frame_num   = vid_context_p->total_frame_num;
    video_data_p->current_time      = vid_context_p->current_time;
    video_data_p->total_audio_time  = vid_context_p->total_audio_time;
    video_data_p->total_video_time  = vid_context_p->total_video_time;
    video_data_p->total_time        = vid_context_p->total_time; 
    video_data_p->video_track       = vid_context_p->video_track;
    video_data_p->image_width       = vid_context_p->image_width;
    video_data_p->image_height      = vid_context_p->image_height;
    video_data_p->max_width         = vid_context_p->max_width;
    video_data_p->max_height        = vid_context_p->max_height;
    video_data_p->aud_format        = vid_context_p->aud_format;
}


/*****************************************************************************
 * FUNCTION
 *  vid_clear_video_working_data
 * DESCRIPTION
 *  Clear video working data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clear_video_working_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLEAR_VIDEO_WORKING_DATA);
    
    vid_context_p->handle = 0;

    vid_context_p->media_mode = 0;
    vid_context_p->media_type = 0;
    vid_context_p->file_handle = 0;
    vid_context_p->audio_frame_num = 0;
    vid_context_p->total_frame_num = 0;
    vid_context_p->current_time = 0;  
    vid_context_p->total_audio_time = 0;
    vid_context_p->total_video_time = 0;   
    vid_context_p->total_time = 0;
    vid_context_p->video_track = 0;
    vid_context_p->image_width = 0;
    vid_context_p->image_height = 0;          
    vid_context_p->max_width = 0;       
    vid_context_p->max_height = 0;

    image_data_path_ptr = NULL;
    stMp4Parser_a_ptr = NULL;
    stMp4Parser_v_ptr = NULL;
    stFSAL_a_ptr = NULL;
    stFSAL_v_ptr = NULL;
    stFSAL_a_stsz_ptr = NULL;
    stFSAL_a_stco_ptr = NULL;
    stFSAL_v_stsz_ptr = NULL;
    stFSAL_v_stco_ptr = NULL;
    stFSAL_aud_data_ptr = NULL;
    stFSAL_aud_data_ptr = NULL;    
    memmode_input_ptr = NULL;

    mp4_aud_buf_ptr = NULL;    
    mp4_vid_buf_ptr = NULL;
    mp4_aud_data_buf_ptr = NULL;
    mp4_vid_stco_buf_ptr = NULL;
    mp4_aud_stco_buf_ptr = NULL;
    mp4_vid_stsz_buf_ptr = NULL;
    mp4_aud_stsz_buf_ptr = NULL;
    mp4_stbl_buf_ptr = NULL;
    vid_seek_hint_ptr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vid_add_video_working_data_item
 * DESCRIPTION
 *  Add video working data item to repository.
 * PARAMETERS
 *  media_mode      [IN]        source type
 *  handle          [OUT]       handle ptr  
 * RETURNS
 *  void
 *****************************************************************************/
void vid_add_video_working_data_item(kal_uint8 media_mode, kal_int32 *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MED_VID_EDT_MOD__   
    kal_int32 index = 0;
#endif /* __MED_VID_EDT_MOD__ */
    video_data_struct *video_data_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_ADD_VIDEO_WORKING_DATA_ITEM);
    
    if (media_mode == MED_MODE_FILE ||
        media_mode == MED_MODE_ARRAY ||
        media_mode == MED_MODE_PDL_FILE)
    {
        video_data_p = &video_data;
    }
    else if (media_mode == MED_MODE_EDITOR_FILE)
    {
    #ifdef __MED_VID_EDT_MOD__
        ASSERT(video_data_list_p[0] != NULL);
    
        for (index = 0; index < VIDEO_EDT_DATA_P_COUNT; index++)
        {
            if (!video_data_list_p[index]->is_used)
            {
                /* find a usable entry */
                video_data_p = video_data_list_p[index];
                break;
            }
        }
        if (index == VIDEO_EDT_DATA_P_COUNT)
        {
            /* out of handle */
            ASSERT(0);
        }        
    #endif /* __MED_VID_EDT_MOD__ */        
    }
    else
    {
        /* shall not enter here */
        ASSERT(0);
    }
 
    video_data_p->is_used = KAL_TRUE;

    /* get entry address as handle */
    *handle = (kal_int32) video_data_p;

}


/*****************************************************************************
 * FUNCTION
 *  vid_remove_video_working_data_item
 * DESCRIPTION
 *  Remove video working data item from repository.
 * PARAMETERS
 *  media_mode          [IN]        source type
 *  handle              [IN]        handle to be removed
 * RETURNS
 *  void
 *****************************************************************************/
void vid_remove_video_working_data_item(kal_uint8 media_mode, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MED_VID_EDT_MOD__    
    kal_int32 index = 0;
#endif /* __MED_VID_EDT_MOD__ */    
    video_data_struct *video_data_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_REMOVE_VIDEO_WORKING_DATA_ITEM, handle);
    
    if (media_mode == MED_MODE_FILE ||
        media_mode == MED_MODE_ARRAY ||        
        media_mode == MED_MODE_PDL_FILE)
    {
        video_data_p = &video_data;
    }
    else if (media_mode == MED_MODE_EDITOR_FILE)
    {
        ASSERT(handle != NULL);
    #ifdef __MED_VID_EDT_MOD__
        for (index = 0; index < VIDEO_EDT_DATA_P_COUNT; index++)
        {
            if (handle == (kal_int32) video_data_list_p[index])
            {
                /* hit! */
                video_data_p = video_data_list_p[index];
                break;
            }
        }
        if (index == VIDEO_EDT_DATA_P_COUNT)
        {
            /* miss - maybe already freed */
            return;
        }
    #endif /* __MED_VID_EDT_MOD__ */
    }
    else
    {
        /* shall not enter here */
        ASSERT(0);
    }

    video_data_p->is_used = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  vid_get_audio_parser
 * DESCRIPTION
 *  Get MP4 audio parser ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  MP4 audio parser ptr
 *****************************************************************************/
STMp4Parser *vid_get_audio_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: 
     * Called by driver, this shall be remove. 
     * We shall pass parser ptr to driver instead of provide this function 
     */
    return (stMp4Parser_a_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vid_check_camera_is_idle
 * DESCRIPTION
 *  Check camera is idle or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle or not
 *****************************************************************************/
kal_bool vid_chcek_camera_is_idle(void)
{
#if defined(__MED_CAM_MOD__)
    return (kal_bool)CAM_IN_STATE(CAM_IDLE);
#else
    return KAL_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vid_update_frame_to_buffer
 * DESCRIPTION
 *  Update current frame image to the display buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_frame_to_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_FRAME_TO_BUFFER);
   
    if (vid_context_p->get_frame && vid_context_p->image_buffer_address)
    {
        memmode_input_ptr->disp_width = vid_context_p->display_width;
        memmode_input_ptr->disp_height = vid_context_p->display_height;
        memmode_input_ptr->lcd_buf_addr = (kal_uint32)vid_context_p->image_buffer_address;
        
        kal_trace(                                                  
            TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_MEMORYMODE_OPEN,   
            memmode_input_ptr->disp_width,                          
            memmode_input_ptr->disp_height);
        
        video_memorymode_open(memmode_input_ptr);
        video_dec_prev_frame_to_memory();
        video_memorymode_close();
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_get_result_from_media_status
 * DESCRIPTION
 *  Get result from MEDIA_STATUS_CODE.
 * PARAMETERS
 *  status      [IN]    MEDIA_STATUS_CODE    
 * RETURNS
 *  MED's return code
 *****************************************************************************/
kal_int32 vid_get_result_from_media_status(MEDIA_STATUS_CODE status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case MEDIA_STATUS_OK:
            return MED_RES_OK;
//	case CAMERA_MODULE_NOT_READY:   /*UNI@bw070627 如果camera module not ready,进入录象器可以退出，不会死机*/
//	   return MED_RES_CAMERA_NOT_READY;			
        case MP4_PARSER_ERROR:
            return MED_RES_PARSER_ERROR;
        case VIDEO_ERROR:
            VID_VIS_ERROR_TRACE(VIDEO_GetLastError(), vid_context_p->state);
            return MED_RES_VIDEO_ERROR;
        case AUDIO_ERROR:
            return MED_RES_AUDIO_ERROR;
        case FSAL_ERROR:
            return MED_RES_FSAL_ERROR;
        case FS_ERROR:
            return MED_RES_OPEN_FILE_FAIL;
        case MP4_PRODUCER_ERROR:
            return MED_RES_MP4_PRODUCER_ERROR;
        case MP4_SAMPLEDATA_ERROR:
            return MED_RES_MP4_SAMPLEDATA_ERROR;
        case VEDIT_AUDIO_TIME_ERROR:
            return MED_RES_AUDIO_ERROR;
        case SENSOR_ERROR:
            return MED_RES_ERROR;
        case FSAL_READ_EOF:
        case FSAL_SEEK_EOF:            
            return MED_RES_PDL_VIDEO_UNDERFLOW;
        default:
            return MED_RES_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_get_encode_result_from_media_status
 * DESCRIPTION
 *  for handling encode errors
 * PARAMETERS
 *  status      [IN]    MEDIA_STATUS_CODE    
 *  stfsal_p    [IN]    the FSAL pointer which may result error, NULL if don't care FSAL error.
 * RETURNS
 *  MED's return code
 *****************************************************************************/
kal_int32 vid_edt_get_encode_result_from_media_status(MEDIA_STATUS_CODE status, STFSAL *stfsal_p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stfsal_p == NULL || FSAL_ERROR != status )
    {
        return vid_get_result_from_media_status(status);
    }
    else
    {
        return vid_get_result_from_fsal_error(FSAL_GetLastError(stfsal_p));
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_result_from_fsal_error
 * DESCRIPTION
 *  Get result from FSAL_Status.
 * PARAMETERS
 *  error_code      [IN]       FSAL_Status    
 * RETURNS
 *  MED's return code
 *****************************************************************************/
kal_int32 vid_get_result_from_fsal_error(kal_int32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case FSAL_OK:
            return MED_RES_OK;
        case FSAL_OPEN_ERROR:
        case FSAL_CLOSE_ERROR:
            return MED_RES_OPEN_FILE_FAIL;
        case FSAL_READ_ERROR:
        case FSAL_WRITE_ERROR:
        case FSAL_SEEK_ERROR:
        case FS_ACCESS_DENIED:
        case FS_BAD_SECTOR:
        case FS_DATA_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
            return MED_RES_FSAL_ERROR;
        case FS_DISK_FULL:
            return MED_RES_DISC_FULL;
        default:
            return MED_RES_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_release_memory
 * DESCRIPTION
 *  Release internal/external memory used in video module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_release_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(                                  
        TRACE_GROUP_4,                          
        VID_TRC_RELEASE_MEMORY,                 
        vid_context_p->extmem_start_address,    
        vid_context_p->intmem_start_address);
    
    if (vid_context_p->intmem_start_address)
    {
        med_free_int_mem((void **)&vid_context_p->intmem_start_address);
        vid_context_p->intmem_start_address = NULL;
    }
    if (vid_context_p->extmem_start_address)
    {
        med_free_ext_mem((void **)&vid_context_p->extmem_start_address);
        vid_context_p->extmem_start_address = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_stop_unfinished_audio
 * DESCRIPTION
 *  Stop unfinished audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_unfinished_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_UNFINISHED_AUDIO);
    
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

    aud_stop_unfinished_process();

}



/*****************************************************************************
 * FUNCTION
 *  vid_stop_req_hdlr
 * DESCRIPTION
 *  This function is to handle video stop request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_PLAY) )    //huyi-20080414
{
#ifdef __SF_MP4_SUPPORT__
//Huyanwei Touch Here
        if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
        {
            kal_prompt_trace(MOD_MED, "vid_stop_req_hdlr, before vdo_stop_play_file");
            vdo_stop_play_file();
            VID_ENTER_STATE(VID_FILE_READY);
            VID_SET_EVENT(VID_EVT_STOP);
        }
        else
        {
#endif //__SF_MP4_SUPPORT__
        vid_stop_audio();
        VID_ENTER_STATE(VID_PLAY_STOP_VISUAL);
        vid_send_visual_stop_req(NULL);             
#ifdef __SF_MP4_SUPPORT__
	}
#endif //__SF_MP4_SUPPORT__
    }
      else if ( VID_IN_STATE(VID_AUDIO_PLAY_FINISH) || 
        VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        /* get current play for next play */
        video_dec_get_play_time(&vid_context_p->current_time);
       
        vid_stop_visual();
        vid_stop_audio();

        /* notify MED_V to stop */
        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_PLAY_STOP_VISUAL);
        return;
    }
    else if (VID_IN_STATE(VID_SEEK))
    {
        /* get current play for next play */
        video_dec_get_play_time(&vid_context_p->current_time);
        
        /* stop seek */
        video_dec_stop();

        /* enable sleep after recording */
        visual_enable_sleep();

        VID_ENTER_STATE(VID_FILE_READY);
        VID_SET_EVENT(VID_EVT_STOP);
        return;
    }
    else if (VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        video_dec_get_play_time(&vid_context_p->current_time);
        
        vid_stop_visual();
        vid_stop_audio();
        
        VID_SET_EVENT(VID_EVT_STOP);
        return;
    }
#if defined(__MED_VID_ENC_MOD__)
  else if (VID_IN_STATE(VID_IDLE))   /*UNI@bw070627 如果camera module not ready,进入录象器可以退出，不会死机*/
    {
     
        vid_release_memory();
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
        return;
    }
    else if (VID_IN_STATE(VID_PREVIEW))
    {
        exit_mpeg4_encode_process();
        vid_release_memory();
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
        return;
    }
    else if (VID_IN_STATE(VID_RECORD))
    {
        /* close video first to guarantee at leat one frame */
        video_enc_close();
        
        /* stop isp */
        exit_mpeg4_encode_process();
        
        /* stop audio encoding */
        Media_Stop();
    #ifdef __MED_AUD_TIME_STRETCH__
        aud_stretch_close();
    #endif 
    
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);

        /* notify visual to stop */
        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_RECORD_STOP_VISUAL);
        return;        
        
    }
    else if (VID_IN_STATE(VID_RECORD_FINISH))
    {
        /* 
         * in this tate, vid already send record finish notification to MED_V, 
         * we are waiting for MED_V cnf 
         */
        
        /* close video first to guarantee at leat one frame */
        video_enc_close();
        
        /* stop isp */
        exit_mpeg4_encode_process();
        
        /* stop the audio record process */
        Media_Stop();
        
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
        VID_ENTER_STATE(VID_RECORD_STOP_VISUAL);
        return;
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        /* stop mpeg encode process */
        exit_mpeg4_encode_process();
        
        /* close visula files */
        vid_close_visual_file_for_record();
        
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            vid_close_audio_file_for_record();
        }

        /* enable sleep after recording */
        visual_enable_sleep();
        vid_release_memory();

        /* release MMI first */
        VID_ENTER_STATE(VID_IDLE);        
        VID_SET_EVENT(VID_EVT_STOP);
        return;

    }
    else if (VID_IN_STATE(VID_FILE_MERGE))
    {
        VID_ENTER_STATE(VID_FILE_MERGE_STOPPING);
        return;
    }    
#endif /* defined(__MED_VID_ENC_MOD__) */
    else
    {
        VID_SET_EVENT(VID_EVT_STOP);
        return;
    }

    /* shall not enter here */
    ASSERT(0);
}



/*****************************************************************************
 * FUNCTION
 *  vid_audio_play_callback
 * DESCRIPTION
 *  Callback function of audio playback.
 * PARAMETERS
 *  event       [IN]       media event 
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_play_callback(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_PLAY_CALLBACK, event);    

    if (VID_AUD_IN_STATE(VID_AUD_PLAY_DUMMY) ||
        VID_AUD_IN_STATE(VID_AUD_PLAY_HIGH_SPEED))
    {
        /* ignore when in dummy state or in dummy highspeed */
        return;
    }
    
    switch (event)
    {
        case MEDIA_TERMINATED:
        case MEDIA_END:
        case MEDIA_ERROR:
        {
            aud_media_write_data_ind_struct *ind_p = NULL;

            ind_p = (aud_media_write_data_ind_struct*)
                construct_local_para(sizeof(aud_media_write_data_ind_struct), TD_CTRL);

            ind_p->event = event;

            aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_WRITE_DATA_IND, ind_p, NULL);
            break;
        }
        case MEDIA_DATA_REQUEST:
        {
            if (!aud_context_p->processing_data)
            {
                aud_media_write_data_ind_struct *ind_p = NULL;

                ind_p = (aud_media_write_data_ind_struct*)
                    construct_local_para(sizeof(aud_media_write_data_ind_struct), TD_CTRL);

                ind_p->event = event;

                aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_WRITE_DATA_IND, ind_p, NULL);
                aud_context_p->processing_data = KAL_TRUE;
            }
            break;
        }
    }
}




/*****************************************************************************
 * FUNCTION
 *  vid_audio_play_callback_dummy
 * DESCRIPTION
 *  Dummy callback function of audio playback.
 * PARAMETERS
 *  event       [IN]       media event 
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_play_callback_dummy(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_PLAY_CALLBACK_DUMMY, event);  
    
    switch (event)
    {
        case MEDIA_TERMINATED:
        case MEDIA_END:
        case MEDIA_DATA_REQUEST:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_open_play_file
 * DESCRIPTION
 *  Open file for playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  Open file result
 *****************************************************************************/
kal_int32 vid_open_play_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index;
    kal_uint64 temp;
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    MEDIA_STATUS_CODE status;
    kal_uint32 filesize;
    kal_int32 result = 0;
    kal_int32 hint_ret;
    MP4DEC_INIT_STRUCT clip_input;
    kal_bool is_codec_opened = KAL_FALSE;
    kal_bool has_aud_track;
    kal_bool has_vid_track;  
    kal_uint32 fps;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_PLAY_FILE);
    vid_debug_print_cur_state(__LINE__);
    
    if (vid_chcek_camera_is_idle() && 
        (VID_IN_STATE(VID_IDLE) || VID_IN_STATE(VID_PDL_META_BUFFERING)))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE ||
            vid_context_p->media_mode == MED_MODE_ARRAY ||
            vid_context_p->media_mode == MED_MODE_EDITOR_FILE ||
            vid_context_p->media_mode == MED_MODE_PDL_FILE)
        {
            status = MEDIA_STATUS_OK;
            vid_context_p->audio_file_open = KAL_FALSE;
            vid_context_p->video_file_open = KAL_FALSE;
        #ifdef __MED_VID_PDL_MOD__            
            vid_context_p->pdl_aud_file_open = KAL_FALSE;
            vid_context_p->pdl_vid_file_open = KAL_FALSE;
        #endif /* __MED_VID_PDL_MOD__ */            
            vid_context_p->video_track = MED_BOTH_TRACK;

            /* reset aud mute flag */
            aud_context_p->audio_mute = KAL_FALSE;

    
            /***************************************
            * MP4 Visual 
            ***************************************/
            if (vid_context_p->media_mode != MED_MODE_ARRAY)
            {
                eFSALRet = FSAL_Open(stFSAL_v_ptr, (void*)vid_context_p->current_file_name, FSAL_READ_SHARED);         
            }
            else
            {
                FSAL_Direct_SetRamFileSize(stFSAL_v_ptr, vid_context_p->file_size);
                eFSALRet = FSAL_Open(stFSAL_v_ptr, (void*)vid_context_p->file_buffer_address, FSAL_ROMFILE);                  
            }
            
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }

            vid_context_p->video_file_open = KAL_TRUE;

            if (vid_context_p->media_mode != MED_MODE_ARRAY)
            {           
                /* set buffer for FSAL is not from memory */
                
                FSAL_SetBuffer(stFSAL_v_ptr, (kal_uint32) VID_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_vid_buf_ptr);

                eFSALRet = FSAL_GetFileSize(stFSAL_v_ptr, &filesize);
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }

                for (index = 0; index < VID_DEC_SEEK_HINT_SIZE; index++)
                {
                    temp = ((kal_uint64) filesize * (kal_uint64) (index + 1)) / (kal_uint64) (VID_DEC_SEEK_HINT_SIZE + 1);
                    vid_seek_hint_ptr[index].Index = (kal_uint32) temp;
                }
                
                hint_ret = DRM_set_seek_hint(stFSAL_v_ptr->hFile, VID_DEC_SEEK_HINT_SIZE, vid_seek_hint_ptr);
                
                if (hint_ret < 0)
                {
                    VID_FSAL_ERROR_TRACE(hint_ret, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
            }
            
            /* Parse */
            eMp4ParserRet = MP4_Parse(stMp4Parser_v_ptr, stFSAL_v_ptr);
            if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
            {
                VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
                result = MED_RES_BAD_FORMAT;
                goto play_clip_file_error_out;
            }
            
            MP4_MetaHasAudioTrack(stMp4Parser_v_ptr, &has_aud_track);
            if (!has_aud_track)
            {
                vid_context_p->video_track &= (~MED_AUDIO_TRACK);
            }
            
            MP4_MetaHasVideoTrack(stMp4Parser_v_ptr, &has_vid_track);
            if (!has_vid_track)
            {
                vid_context_p->video_track &= (~MED_VISUAL_TRACK);
            }

            kal_trace(TRACE_GROUP_4, VID_TRC_TRACK_INFO, has_aud_track, has_vid_track);

            eFSALRet = FSAL_Open_Attach(stFSAL_v_stco_ptr, stFSAL_v_ptr);
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }

            eFSALRet = FSAL_Open_Attach(stFSAL_v_stsz_ptr, stFSAL_v_ptr);
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }

            if (vid_context_p->media_mode != MED_MODE_ARRAY)
            {             
                FSAL_SetBuffer(stFSAL_v_stco_ptr, VID_MP4_STCO_BUF_SIZE, (kal_uint8*)mp4_vid_stco_buf_ptr);
                FSAL_SetBuffer(stFSAL_v_stsz_ptr, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*)mp4_vid_stsz_buf_ptr);
            }
            
            MP4_SetFSAL_STCO(stMp4Parser_v_ptr, MP4_TRACK_VIDEO, stFSAL_v_stco_ptr);
            MP4_SetFSAL_STSZ(stMp4Parser_v_ptr, MP4_TRACK_VIDEO, stFSAL_v_stsz_ptr);
            MP4_STBL_CacheTablePreprocess(stMp4Parser_v_ptr, mp4_stbl_buf_ptr, VID_MP4_STBL_BUF_SIZE);

            /***************************************
            * MP4 Audio
            ***************************************/
            if (vid_context_p->media_mode != MED_MODE_ARRAY)
            {
                eFSALRet = FSAL_Open(stFSAL_a_ptr, (void*)vid_context_p->current_file_name, FSAL_READ_SHARED);                
            }
            else
            {
                FSAL_Direct_SetRamFileSize(stFSAL_a_ptr, vid_context_p->file_size);
                eFSALRet = FSAL_Open(stFSAL_a_ptr, (void*)vid_context_p->file_buffer_address, FSAL_ROMFILE);
            }
            
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }

            vid_context_p->audio_file_open = KAL_TRUE;

            if (vid_context_p->media_mode != MED_MODE_ARRAY)
            {
                hint_ret = DRM_set_seek_hint(stFSAL_a_ptr->hFile, VID_DEC_SEEK_HINT_SIZE, vid_seek_hint_ptr);

                if (hint_ret < 0)
                {
                    VID_FSAL_ERROR_TRACE(hint_ret, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }

                FSAL_SetBuffer(stFSAL_a_ptr, (kal_uint32) VID_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_aud_buf_ptr);
            }            
            
            MP4_Audio_SetFSAL(stMp4Parser_v_ptr, stFSAL_aud_data_ptr);
            MP4_Parser_Clone(stMp4Parser_v_ptr, stMp4Parser_a_ptr, stFSAL_a_ptr);

            eFSALRet = FSAL_Open_Attach(stFSAL_aud_data_ptr, stFSAL_a_ptr);
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }

            eFSALRet = FSAL_Open_Attach(stFSAL_a_stco_ptr, stFSAL_a_ptr);
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }

            eFSALRet = FSAL_Open_Attach(stFSAL_a_stsz_ptr, stFSAL_a_ptr);
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                result = MED_RES_OPEN_FILE_FAIL;
                goto play_clip_file_error_out;
            }
            
            if (vid_context_p->media_mode != MED_MODE_ARRAY)
            {          
                FSAL_SetBuffer(stFSAL_aud_data_ptr, VID_MP4_FSAL_BUF_SIZE, (kal_uint8*) mp4_aud_data_buf_ptr);
                FSAL_SetBuffer(stFSAL_a_stco_ptr, VID_MP4_STCO_BUF_SIZE, (kal_uint8*)mp4_aud_stco_buf_ptr);
                FSAL_SetBuffer(stFSAL_a_stsz_ptr, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*)mp4_aud_stsz_buf_ptr);                
            }
            
            MP4_SetFSAL_STCO(stMp4Parser_a_ptr, MP4_TRACK_AUDIO, stFSAL_a_stco_ptr);
            MP4_SetFSAL_STSZ(stMp4Parser_a_ptr, MP4_TRACK_AUDIO, stFSAL_a_stsz_ptr);
            MP4_UpdateSampleCount(stMp4Parser_a_ptr, MP4_TRACK_AUDIO);
            //MP4_STBL_CacheTablePreprocess(stMp4Parser_a_ptr, mp4_stbl_buf_ptr, VID_MP4_STBL_BUF_SIZE);

            /* PDL */
        #ifdef __MED_VID_PDL_MOD__            
            if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {
                /***************************************
                * PDL MP4 Audio
                ***************************************/
                eFSALRet = FSAL_Open(&stFSAL_pdl_a, (void*)vid_context_p->current_file_name, FSAL_READ_SHARED);
                
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
                
                vid_context_p->pdl_aud_file_open = KAL_TRUE;
                FSAL_SetBuffer(&stFSAL_pdl_a, (kal_uint32) VID_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_pdl_aud_buf);
                
                MP4_Parser_Clone(stMp4Parser_v_ptr, &stMp4Parser_pdl_a, &stFSAL_pdl_a);

                eFSALRet = FSAL_Open_Attach(&stFSAL_pdl_a_stco, &stFSAL_pdl_a);
                
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
                
                FSAL_SetBuffer(&stFSAL_pdl_a_stco, VID_MP4_STCO_BUF_SIZE, (kal_uint8*)mp4_pdl_aud_stco_buf);

                eFSALRet = FSAL_Open_Attach(&stFSAL_pdl_a_stsz, &stFSAL_pdl_a);
                
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
                
                FSAL_SetBuffer(&stFSAL_pdl_a_stsz, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*)mp4_pdl_aud_stsz_buf);
                
                MP4_SetFSAL_STCO(&stMp4Parser_pdl_a, MP4_TRACK_AUDIO, &stFSAL_pdl_a_stco);
                MP4_SetFSAL_STSZ(&stMp4Parser_pdl_a, MP4_TRACK_AUDIO, &stFSAL_pdl_a_stsz);
                MP4_UpdateSampleCount(&stMp4Parser_pdl_a, MP4_TRACK_AUDIO);
                //MP4_STBL_CacheTablePreprocess(&stMp4Parser_pdl_a, mp4_pdl_stbl_buf, VID_MP4_STBL_BUF_SIZE);
                
                hint_ret = DRM_set_seek_hint(stFSAL_pdl_a.hFile, VID_DEC_SEEK_HINT_SIZE, vid_seek_hint_ptr);  

                if (hint_ret < 0)
                {
                    VID_FSAL_ERROR_TRACE(hint_ret, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }

                /***************************************
                * PDL MP4 Visual
                ***************************************/
                eFSALRet = FSAL_Open(&stFSAL_pdl_v, (void*)vid_context_p->current_file_name, FSAL_READ_SHARED);
                
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
                
                vid_context_p->pdl_vid_file_open = KAL_TRUE;
                FSAL_SetBuffer(&stFSAL_pdl_v, (kal_uint32) VID_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_pdl_vid_buf);
                
                MP4_Parser_Clone(stMp4Parser_v_ptr, &stMp4Parser_pdl_v, &stFSAL_pdl_v);

                eFSALRet = FSAL_Open_Attach(&stFSAL_pdl_v_stco, &stFSAL_pdl_v);
                
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
                
                FSAL_SetBuffer(&stFSAL_pdl_v_stco, VID_MP4_STCO_BUF_SIZE, (kal_uint8*)mp4_pdl_vid_stco_buf);

                eFSALRet = FSAL_Open_Attach(&stFSAL_pdl_v_stsz, &stFSAL_pdl_v);
                
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }
                
                FSAL_SetBuffer(&stFSAL_pdl_v_stsz, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*)mp4_pdl_vid_stsz_buf);
                
                MP4_SetFSAL_STCO(&stMp4Parser_pdl_v, MP4_TRACK_VIDEO, &stFSAL_pdl_v_stco);
                MP4_SetFSAL_STSZ(&stMp4Parser_pdl_v, MP4_TRACK_VIDEO, &stFSAL_pdl_v_stsz);
                MP4_UpdateSampleCount(&stMp4Parser_pdl_v, MP4_TRACK_VIDEO);
                
                //MP4_STBL_CacheTablePreprocess(&stMp4Parser_pdl_v, mp4_pdl_stbl_buf, VID_MP4_STBL_BUF_SIZE);
                
                hint_ret = DRM_set_seek_hint(stFSAL_pdl_v.hFile, VID_DEC_SEEK_HINT_SIZE, vid_seek_hint_ptr);                 

                if (hint_ret < 0)
                {
                    VID_FSAL_ERROR_TRACE(hint_ret, __LINE__);
                    result = MED_RES_OPEN_FILE_FAIL;
                    goto play_clip_file_error_out;
                }

            }
        #endif /* __MED_VID_PDL_MOD__ */
        
            /* get audio sample rate and channel counnt */
            vid_context_p->audio_sample_rate = MP4_Audio_GetSamplingFreq(stMp4Parser_a_ptr);
            vid_context_p->audio_channel_no = MP4_Audio_GetChannelNum(stMp4Parser_a_ptr);

            /* get audio format */
            vid_context_p->aud_format = MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(stMp4Parser_a_ptr));

            kal_trace(
                TRACE_GROUP_4, 
                VID_TRC_AUDIO_PROFILE, 
                vid_context_p->audio_sample_rate,
                vid_context_p->audio_channel_no,
                vid_context_p->aud_format);       

            /* decode the 1st frame to get image frame dimen */
            vid_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(vid_play_mem[0]);
            vid_context_p->intmem_size = vid_play_mem[0];
            vid_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(vid_play_mem[1]);
            vid_context_p->extmem_size = vid_play_mem[1];
            
            if (vid_context_p->extmem_start_address == NULL || 
                vid_context_p->intmem_start_address == NULL)
            {
                /* release video memory */
                vid_release_memory();
                result = MED_RES_MEM_INSUFFICIENT;
                goto play_clip_file_error_out;
            }

            intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
            extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);

            is_codec_opened = KAL_TRUE;
            clip_input.pstMp4Parser = stMp4Parser_v_ptr;
            clip_input.pstFSAL = stFSAL_v_ptr;
            clip_input.video_dec_callback = NULL;
            clip_input.max_width = vid_context_p->max_width;
            clip_input.max_height = vid_context_p->max_height;
            clip_input.audio_enable = KAL_TRUE; /* always open audio */

            if (vid_context_p->media_mode == MED_MODE_FILE ||
                vid_context_p->media_mode == MED_MODE_ARRAY ||
                vid_context_p->media_mode == MED_MODE_EDITOR_FILE)
            {
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_CLIP_INITIALIZE, __LINE__);
                status = video_dec_initialize(&clip_input);                
                vid_debug_print_vid_drv_return(status, __LINE__);
            }
            else if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {
            #ifdef __MED_VID_PDL_MOD__    
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_PDL_INITIALIZE, __LINE__);            
                status = video_dec_PDL_initialize(&clip_input);
                vid_debug_print_vid_drv_return(status, __LINE__);
            #else
                ASSERT(0);
            #endif
            }

            if (status == NO_VISUAL_TRACK)
            {
                if (vid_context_p->is_enable_aud_only)
                {
                    vid_context_p->video_track &= (~MED_VISUAL_TRACK);
                }
                else
                {
                    result = MED_RES_INVALID_FORMAT;
                    goto play_clip_file_error_out;
                }
            }
            else if (status != MEDIA_STATUS_OK)
            {
                result = vid_get_result_from_media_status(status);
                goto play_clip_file_error_out;
            }

            if (VID_HAS_TRACK(MED_VISUAL_TRACK))
            {
                video_dec_get_total_time(&vid_context_p->total_audio_time, &vid_context_p->total_video_time);
                video_dec_get_frame_size(&vid_context_p->image_width, &vid_context_p->image_height);
                vid_context_p->total_frame_num = video_dec_get_total_frame();
                video_dec_get_total_play_time(&vid_context_p->total_time);
            }
            else
            {
                vid_context_p->image_width = 0;
                vid_context_p->image_height = 0;
                vid_context_p->total_frame_num = 0;
                vid_context_p->total_video_time = 0;
                
                video_dec_get_total_play_time(&vid_context_p->total_time);                
                vid_context_p->total_audio_time = vid_context_p->total_time;    
            }

            if (vid_context_p->media_mode == MED_MODE_EDITOR_FILE)
            {
                /* check if is a valid video for for editor */
                /* we can only process audio with AMR 8k */                
                if(vid_context_p->aud_format != MEDIA_FORMAT_AMR || 
                   vid_context_p->audio_sample_rate != 8000 ||
                   stMp4Parser_v_ptr->bFramesPerSample != 1)
                {
                    result = MED_RES_UNSUPPORTED_TYPE;
                    goto play_clip_file_error_out;
                }
                
                MP4_Meta_Estimate_FPS(stMp4Parser_v_ptr, &fps);

                if (fps > 30)
                {
                    /* only support video fps <= 30 */
                    result = MED_RES_UNSUPPORTED_TYPE;
                    goto play_clip_file_error_out;
                }
                
                /* Video Editor dont support A > V or V > A case */
                if (vid_context_p->total_time > vid_context_p->total_audio_time)
                {
                    vid_context_p->total_time = vid_context_p->total_audio_time;
                }

                if (vid_context_p->total_time > vid_context_p->total_video_time)
                {
                    vid_context_p->total_time = vid_context_p->total_video_time;
                }
            }
            
            vid_set_total_time(vid_context_p->total_time, vid_context_p->total_video_time, vid_context_p->total_audio_time);
            vid_set_image_size(vid_context_p->image_width, vid_context_p->image_height);

            kal_trace(
                TRACE_GROUP_4, 
                VID_TRC_TOTAL_DURATION, 
                (kal_uint32)vid_context_p->total_time,
                (kal_uint32)vid_context_p->total_audio_time,
                (kal_uint32)vid_context_p->total_video_time); 

            if (vid_context_p->media_mode == MED_MODE_FILE ||
                vid_context_p->media_mode == MED_MODE_ARRAY ||
                vid_context_p->media_mode == MED_MODE_PDL_FILE)
            {
                VID_ENTER_STATE(VID_FILE_READY);
                VID_AUD_ENTER_STATE(VID_AUD_IDLE);

                if (!vid_context_p->blocking)
                {
                    if (VID_HAS_TRACK(MED_VISUAL_TRACK))
                    {
                       vid_send_file_ready_ind(MED_RES_OK);
                    }
                    else
                    {
                       vid_send_file_ready_ind(MED_RES_MP4_NO_VIDEO_TRACK);
                    }

                    VID_RETURN(MED_RES_OK);                        
                }                                
                else
                {
                    if (VID_HAS_TRACK(MED_VISUAL_TRACK))
                    {
                       VID_RETURN(MED_RES_OK);    
                    }
                    else
                    {
                        VID_RETURN(MED_RES_MP4_NO_VIDEO_TRACK);                            
                    }
                }
            }
            else if (vid_context_p->media_mode == MED_MODE_EDITOR_FILE)
            {
                /* store variables to working data list */
                vid_store_video_working_data_var(vid_context_p->handle);   
                vid_set_handle(vid_context_p->handle);

                /* release resoure */
                video_dec_close();
                intmem_deinit();
                extmem_deinit();
                vid_release_memory();

                /* file opened, but we still cant play it, need set active first */
                VID_ENTER_STATE(VID_IDLE);
                VID_AUD_ENTER_STATE(VID_AUD_IDLE);
                    
                if (!vid_context_p->blocking)
                {
                    vid_send_file_ready_ind(MED_RES_OK);
                }                

                VID_RETURN(MED_RES_OK);                 
            }
        
        /**** error out ****/
        play_clip_file_error_out:
            if (vid_context_p->audio_file_open)
            {
                FSAL_Close(stFSAL_a_ptr);
            }
            
            if (vid_context_p->video_file_open)
            {
                FSAL_Close(stFSAL_v_ptr);
            }
        #ifdef __MED_VID_PDL_MOD__
            if (vid_context_p->pdl_aud_file_open)
            {
                FSAL_Close(&stFSAL_pdl_a);
            }

            if (vid_context_p->pdl_vid_file_open)
            {
                FSAL_Close(&stFSAL_pdl_v);
            }            
        #endif /* __MED_VID_PDL_MOD__ */

            if (is_codec_opened)
            {
                video_dec_close();
                /* deinit visual memory */
                intmem_deinit();
                extmem_deinit();
                /* release video memory */
                vid_release_memory();
            }

            vid_remove_video_working_data_item(vid_context_p->media_mode, vid_context_p->handle);
            vid_clear_video_working_data();

            /* restore default state */
            VID_ENTER_STATE(VID_IDLE);
            VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            
            VID_RETURN(result);            
            
        }
        else
        {
            VID_RETURN(MED_RES_UNSUPPORTED_TYPE);    
        }
    }
    else
    {
        VID_RETURN(MED_RES_BUSY);            
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_open_req_hdlr
 * DESCRIPTION
 *  Handle open video request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_open_req_struct *req_p;
    kal_int32 result;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_REQ_HDLR);
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_open_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->media_mode = req_p->media_mode;
    vid_context_p->media_type = req_p->media_type;
    vid_context_p->current_time = 0;
    vid_context_p->max_width = req_p->max_width;
    vid_context_p->max_height = req_p->max_height;
    vid_context_p->blocking = req_p->blocking;
    vid_context_p->is_enable_aud_only = req_p->enable_aud_only;

#if defined(__MED_CAM_MOD__)
    cam_abort_to_idle();
#endif
#ifdef __SF_MP4_SUPPORT__
    if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
    {
        if (CAM_IN_STATE(CAM_IDLE) && VID_IN_STATE(VID_IDLE))
        {
              kal_int32 result;
    
    	    result = vdo_open_play_file(req_p, vid_sf_send_file_ready_ind);
    	    kal_prompt_trace(MOD_MED, "In vid_open_req_hdlr, after vdo_open_file, result:%d", result);
    	    vid_set_result(result, __LINE__);
    	    if(result==MED_RES_OK)
		    {
		        VID_ENTER_STATE(VID_FILE_READY);
		    }
		    else
		    {
		        VID_ENTER_STATE(VID_IDLE);
		    }
        }
        else if (VID_IN_STATE(VID_FILE_MERGE))
        {
            if (vid_context_p->media_mode == MED_MODE_FILE ||
                vid_context_p->media_mode == MED_MODE_CLIP_FILE)
            {
                kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
            }
            else if (vid_context_p->media_mode == MED_MODE_CLIP_ARRAY)
            {
                vid_context_p->file_buffer_address = (kal_uint32) req_p->data;
                vid_context_p->file_size = req_p->data_size;
            }
            VID_ENTER_STATE(VID_DELAY_OPEN);
            return;
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else    //ELSE if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
#endif //__SF_MP4_SUPPORT__
{
    vid_add_video_working_data_item(vid_context_p->media_mode, &vid_context_p->handle);
    vid_load_video_working_data_buf(vid_context_p->handle);

    /* set brightness and contrast default value */
    memmode_input_ptr->brightness_level = 128;
    memmode_input_ptr->contrast_level = 128;
    image_data_path_ptr->brightness_level = 128;
    image_data_path_ptr->contrast_level = 128;

    /* reset stop time */
    vid_context_p->stop_time = VID_MAX_STOP_TIME;

    vid_context_p->vol_level = VID_VOL_LEVEL_NOT_USED;

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_IDLE))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE ||
            vid_context_p->media_mode == MED_MODE_EDITOR_FILE)
        {
            kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
            result = vid_open_play_file();
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_OPEN);
        }
        else if (vid_context_p->media_mode == MED_MODE_ARRAY)
        {
            vid_context_p->file_buffer_address = (kal_uint32) req_p->data;
            vid_context_p->file_size = req_p->data_size;
            result = vid_open_play_file();
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_OPEN);
        }
        else if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
        {
        #ifdef __MED_VID_PDL_MOD__            
            FSAL_Status eFSALRet;

            /* PDL file only support non-blocking */
            ASSERT(!vid_context_p->blocking);
            
            kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
            eFSALRet = FSAL_Open(stFSAL_v_ptr, (void*)vid_context_p->current_file_name, FSAL_READ_SHARED);

            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                vid_set_result(MED_RES_OPEN_FILE_FAIL, __LINE__);
                VID_SET_EVENT(VID_EVT_OPEN);   
                return;
            }
            
            FSAL_SetBuffer(stFSAL_v_ptr, (kal_uint32) VID_MP4_FSAL_BUF_SIZE, (kal_uint8*) mp4_vid_buf_ptr);
            
            result = vid_check_pdl_file_meta();

            if (result == MED_RES_OK)
            {   
                /* enough buffer for PDL to open file */
                FSAL_Close(stFSAL_v_ptr);                 
                result = vid_open_play_file();
                vid_set_result(result, __LINE__);             
                VID_SET_EVENT(VID_EVT_OPEN); 
                return;
            }
            else if (result == MED_RES_BUFFER_INSUFFICIENT)
            {
                /* NOT enough buffer for PDL open, waiting for more... */
                VID_ENTER_STATE(VID_PDL_META_BUFFERING);

                med_start_timer(VID_PDL_BUFFERING_TIMER, 1000, vid_pdl_meta_buffering_hdlr, 0);
                             
                vid_set_result(MED_RES_OK, __LINE__);             
                VID_SET_EVENT(VID_EVT_OPEN); 
                return;
            }
            else 
            {
                /* other errors */
                FSAL_Close(stFSAL_v_ptr);                      
                vid_set_result(result, __LINE__);
                VID_SET_EVENT(VID_EVT_OPEN);   
                return;
            }
        #endif /* __MED_VID_PDL_MOD__ */
        }
        else 
        {
            ASSERT(0);
        }
        
    }
    else if (VID_IN_STATE(VID_FILE_MERGE))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE ||
            vid_context_p->media_mode == MED_MODE_EDITOR_FILE)
        {
            kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
        }
        else if (vid_context_p->media_mode == MED_MODE_ARRAY)
        {
            vid_context_p->file_buffer_address = (kal_uint32) req_p->data;
            vid_context_p->file_size = req_p->data_size;
        }
        VID_ENTER_STATE(VID_DELAY_OPEN);
        /* after file merge done, we will open file */
        return;
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_OPEN);
        return;
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  vid_close_play_file
 * DESCRIPTION
 *  Close video file
 * PARAMETERS
 *  media_mode      [IN]        source type
 *  handle          [IN]        handle
 * RETURNS
 *  void
 *****************************************************************************/
void vid_close_play_file(kal_uint8 media_mode, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_PLAY_FILE, media_mode, handle);    

    /* check if all audio handle are close properly */
    ASSERT(vid_context_p->mhdl_handle == NULL);
    ASSERT(vid_context_p->dummy_mhdl_handle == NULL);    

    if (media_mode == MED_MODE_FILE ||
        media_mode == MED_MODE_ARRAY ||
        media_mode == MED_MODE_PDL_FILE)
    {
        FSAL_Close(stFSAL_a_ptr);
        FSAL_Close(stFSAL_v_ptr);
        
    #ifdef __MED_VID_PDL_MOD__
        if (media_mode == MED_MODE_PDL_FILE)
        {
            FSAL_Close(&stFSAL_pdl_a);
            FSAL_Close(&stFSAL_pdl_v);
        }
    #endif /* __MED_VID_PDL_MOD__ */

        video_dec_close();
    
        /* deinit visual memory */
        intmem_deinit();
        extmem_deinit();

        /* release video memory */
        vid_release_memory();

        vid_remove_video_working_data_item(media_mode, handle);
        vid_clear_video_working_data();

        VID_ENTER_STATE(VID_IDLE);            
    }
    else  if (media_mode == MED_MODE_EDITOR_FILE)
    {
        vid_load_video_working_data_buf(handle);
    
        FSAL_Close(stFSAL_a_ptr);
        FSAL_Close(stFSAL_v_ptr);

        vid_remove_video_working_data_item(media_mode, handle);
        vid_clear_video_working_data();

        VID_ENTER_STATE(VID_IDLE);            
    }

    
}


/*****************************************************************************
 * FUNCTION
 *  vid_close_req_hdlr
 * DESCRIPTION
 *  Handle close video request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    req_p = (media_vid_close_req_struct*) ilm_ptr->local_para_ptr;
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (req_p->media_mode == MED_MODE_FILE ||
        req_p->media_mode == MED_MODE_ARRAY)
    {
        if ((VID_IN_STATE(VID_FILE_READY) || VID_IN_STATE(VID_OPEN_FILE)))
        {
            vid_close_play_file(req_p->media_mode, 0);
        }
        else if (VID_IN_STATE(VID_DELAY_OPEN))
        {
            VID_ENTER_STATE(VID_IDLE);
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else if (req_p->media_mode == MED_MODE_PDL_FILE)
    {
        if (VID_IN_STATE(VID_PDL_META_BUFFERING))
        {
            med_stop_timer(VID_PDL_BUFFERING_TIMER);   
            FSAL_Close(stFSAL_v_ptr);          
            VID_ENTER_STATE(VID_IDLE);
        }
        else if ((VID_IN_STATE(VID_FILE_READY) || VID_IN_STATE(VID_OPEN_FILE)))
        {
            vid_close_play_file(req_p->media_mode, 0);
        }
        else if (VID_IN_STATE(VID_DELAY_OPEN))
        {
            VID_ENTER_STATE(VID_IDLE);
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else if (req_p->media_mode == MED_MODE_EDITOR_FILE)
    {
        vid_close_play_file(req_p->media_mode, req_p->handle);
    }
 
    VID_SET_EVENT(VID_EVT_CLOSE);
}



/*****************************************************************************
 * FUNCTION
 *  vid_play_dummy_audio
 * DESCRIPTION
 *  Play dummy audio frame. This function shall only be called within 
 *  vid_play_audio()
 * PARAMETERS
 *  void
 * RETURNS
 *  Play dummy audio result
 *****************************************************************************/
kal_int32 vid_play_dummy_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status status;

    Media_VM_PCM_Param vpFormat;
    void *param = NULL;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_DUMMY_AUDIO);  

#if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_AUD_BT_A2DP_CLOSE_CODEC_IND, __LINE__);  
    aud_bt_a2dp_close_codec_ind();
#endif

    /* close normal audio handle */
    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
        vid_context_p->mhdl_handle = NULL;
    }

    /* open audio handle for dummy audio */
    vpFormat.mediaType = MEDIA_FORMAT_AMR;
    vpFormat.vmParam = (kal_uint32)MEDIA_VMP_AS_RINGTONE;
    param = &vpFormat;        

    ASSERT(vid_context_p->dummy_mhdl_handle == NULL);

    if ((vid_context_p->dummy_mhdl_handle = AMR_Open(vid_audio_play_callback_dummy, NULL, param)) == NULL)
    {
        ASSERT(0);
    }

    vid_context_p->dummy_mhdl_handle->SetBuffer(
        vid_context_p->dummy_mhdl_handle, 
        (kal_uint8*)aud_context_p->ring_buf, 
        AUD_RING_BUFFER_LEN * 2);    

    /* stuff AMR header */
    vid_context_p->dummy_mhdl_handle->GetWriteBuffer(
        vid_context_p->dummy_mhdl_handle, 
        &vid_context_p->audio_buf_p, 
        &vid_context_p->audio_buf_len);
    
    kal_mem_cpy(vid_context_p->audio_buf_p, VID_AMR_HEADER, VID_AMR_HEADER_SIZE); /* driver's requirement */
    
    vid_context_p->dummy_mhdl_handle->WriteDataDone(
        vid_context_p->dummy_mhdl_handle, 
        VID_AMR_HEADER_SIZE);

    /* stuff dummy audio */
    vid_context_p->dummy_mhdl_handle->GetWriteBuffer(
        vid_context_p->dummy_mhdl_handle, 
        &vid_context_p->audio_buf_p, 
        &vid_context_p->audio_buf_len);
    
    kal_mem_set(vid_context_p->audio_buf_p, 0x7C, 2); /* stuff 2 no-data frames */
    vid_context_p->dummy_mhdl_handle->WriteDataDone(vid_context_p->dummy_mhdl_handle, 2);    

    /* To mute audio in case of noise, set analog gain to 0 */
    aud_melody_set_output_volume(0, 0);

    status = vid_context_p->dummy_mhdl_handle->Play(vid_context_p->dummy_mhdl_handle);
    
    if (status != MEDIA_SUCCESS)
    {
        if (vid_context_p->dummy_mhdl_handle != NULL)
        {
            vid_context_p->dummy_mhdl_handle->Close(vid_context_p->dummy_mhdl_handle);
            vid_context_p->dummy_mhdl_handle = NULL;
        }
        
        VID_RETURN(aud_get_res((kal_uint8)status));
    }
    
    VID_RETURN(MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_accurate_play_speed
 * DESCRIPTION
 *  Get the accurate play speed according to audio format.
 * PARAMETERS
 *  org_speed       [IN]        original play speed
 * RETURNS
 *  Accurate play speed
 *****************************************************************************/
kal_int16 vid_get_accurate_play_speed(kal_int16 org_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Format format;
    kal_int16 speed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_ACCURATE_PLAY_SPEED);  
    
    format = MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(stMp4Parser_a_ptr));

    speed = org_speed;
    
    switch (format)
    {
        case MEDIA_FORMAT_AAC:
            if (org_speed >= 125 && org_speed <= 130)
            {
                speed = 128;
            }
            break;
        case MEDIA_FORMAT_AMR:
            if (org_speed >= 125 && org_speed <= 130)
            {
                speed = 125;
            }
            break;
    }
    if (org_speed >= 75 && org_speed <= 80)
    {
        speed =  80;
    }
    else if (org_speed >= 150 && org_speed <= 160)
    {
        speed = 160;
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_SPEED, speed);  
    return speed;
}


/*****************************************************************************
 * FUNCTION
 *  vid_stop_visual
 * DESCRIPTION
 *  Stop visual.
 * PARAMETERS
 *  void
 * RETURNS
 *  vpod
 *****************************************************************************/
void vid_stop_visual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_VISUAL);    

    video_dec_stop();
    
    if (vid_context_p->image_path_open)
    {
        video_image_path_close();
        vid_context_p->image_path_open = KAL_FALSE;
        vid_update_frame_to_buffer();
    }

    /* stop "stop time" timer */
    med_stop_timer(VID_STOP_TIME_TIMER);   
    
    visual_enable_sleep();
    VID_ENTER_STATE(VID_FILE_READY);
}


/*****************************************************************************
 * FUNCTION
 *  vid_stop_audio
 * DESCRIPTION
 *  Stop audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_AUDIO); 

    if (VID_AUD_IN_STATE(VID_AUD_PLAY_HIGH_SPEED) ||
        VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL) || 
        VID_AUD_IN_STATE(VID_AUD_PLAY_DUMMY) ||
        VID_AUD_IN_STATE(VID_AUD_PLAY_UNDERFLOW))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         

        if (vid_context_p->mhdl_handle)
        {
            vid_context_p->mhdl_handle->Stop(vid_context_p->mhdl_handle);  
        }

        if (vid_context_p->dummy_mhdl_handle)
        {
            vid_context_p->dummy_mhdl_handle->Stop(vid_context_p->dummy_mhdl_handle);  
        }
        
    #ifdef __MED_AUD_TIME_STRETCH__
        aud_stretch_close();
    #endif 
    
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
    }

    /* close audio handle */
    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
        vid_context_p->mhdl_handle = NULL;
    }

    if (vid_context_p->dummy_mhdl_handle != NULL)
    {
        vid_context_p->dummy_mhdl_handle->Close(vid_context_p->dummy_mhdl_handle);
        vid_context_p->dummy_mhdl_handle = NULL;
    }
    
    /* stop "stop time" timer */
    med_stop_timer(VID_STOP_TIME_TIMER);   
}


/*****************************************************************************
 * FUNCTION
 *  vid_play_audio
 * DESCRIPTION
 *  Start play audio
 * PARAMETERS
 *  audio_frame_num     [IN]        the beginning audio frame
 * RETURNS
 *  play audio result
 *****************************************************************************/
kal_int32 vid_play_audio(kal_uint32 audio_frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Format eAudioFormat;
    MP4_Parser_Status eMp4ParserRet;
    MP4_Audio_Type eAudioType;

    kal_uint32 uReadSize;
    kal_int32 result;

    vid_aud_open_func_ptr openFunc = NULL;
    Media_VM_PCM_Param vpFormat;
    void *param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_AUDIO, audio_frame_num);
    kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);

    ASSERT(vid_context_p->play_audio);

    aud_context_p->processing_data = KAL_FALSE;
    vid_context_p->audio_silence_remained = 0; 

    /* open audio handle for audio track in video file */
    if (VID_HAS_TRACK(MED_AUDIO_TRACK) && 
        vid_context_p->media_mode != MED_MODE_EDITOR_FILE)
    {
        /* notice, video editor will open audio driver when set active */
        
        /* The audio format in 3GP/MP4 file */
        switch (vid_context_p->aud_format)
        {
        #ifdef AMR_DECODE    
            case MEDIA_FORMAT_AMR:
        #ifdef AMRWB_DECODE        
            case MEDIA_FORMAT_AMR_WB:
        #endif         
                vpFormat.mediaType = vid_context_p->aud_format;
                vpFormat.vmParam = (kal_uint32)MEDIA_VMP_AS_RINGTONE;
                param = &vpFormat;        
                openFunc = AMR_Open;
                break;
        #endif /*AMR_DECODE*/
        #if defined(AAC_DECODE)            
            case MEDIA_FORMAT_AAC:
                openFunc = AAC_Open;
                break;
        #endif /*AAC_DECODE*/    
        #if defined(BSAC_DECODE)
            case MEDIA_FORMAT_BSAC:
                openFunc = BSAC_Open;
                break;
        #endif /* BSAC_DECODE */        
            default:
            
                /* unsupported audio, play dummy audio */
                if ((result = vid_play_dummy_audio()) == MED_RES_OK)
                {
                    VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
                }
                
                VID_RETURN(result);
                break;
        }


        if ((vid_context_p->mhdl_handle = openFunc(vid_audio_play_callback, NULL, param)) == NULL)
        {
            /* if audio handle cant opened, open dummy audio */
            if ((result = vid_play_dummy_audio()) == MED_RES_OK)
            {
                VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
            }
            
            VID_RETURN(result);
        }

        if (vid_context_p->vol_level != VID_VOL_LEVEL_NOT_USED)
        {
            vid_context_p->mhdl_handle->SetLevel(vid_context_p->mhdl_handle, vid_context_p->vol_level);
        }

    }

    if (vid_context_p->audio_end)
    {
        if (vid_context_p->play_speed != 100)
        {
            if ((result = vid_play_dummy_audio()) == MED_RES_OK)
            {
                VID_AUD_ENTER_STATE(VID_AUD_PLAY_HIGH_SPEED);
            }

            VID_RETURN(result);
        }
        else
        {
            if ((result = vid_play_dummy_audio()) == MED_RES_OK)
            {
                VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
            }
            
            VID_RETURN(result);
        }
    }
    else
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_SEEK, audio_frame_num, __LINE__);                
        eMp4ParserRet = MP4_Audio_Seek(stMp4Parser_a_ptr, audio_frame_num);
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);

        if (eMp4ParserRet == MP4_PARSER_OK || eMp4ParserRet == MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            eAudioType = MP4_GetAudioType(stMp4Parser_a_ptr);
            eAudioFormat = MP4_Audio_Type_To_Media_Format(eAudioType);

            if (!VID_HAS_TRACK(MED_VISUAL_TRACK) && eAudioType == MP4_AUDIO_NONE)
            {
                /* no visual track and audio type not vaild, will not play this file */
                VID_RETURN(MED_RES_INVALID_FORMAT);
            }
            
            if (eAudioType != MP4_AUDIO_NONE && vid_context_p->play_speed == 100)
            {
                vid_context_p->mhdl_handle->SetBuffer(
                    vid_context_p->mhdl_handle, 
                    (kal_uint8*)aud_context_p->ring_buf, 
                    AUD_RING_BUFFER_LEN * 2);    

                /*Need to fill up header for amr/awb play */
                if(vid_context_p->aud_format == MED_TYPE_AMR)
                {
                    vid_context_p->mhdl_handle->GetWriteBuffer(
                        vid_context_p->mhdl_handle, 
                        &vid_context_p->audio_buf_p, 
                        &vid_context_p->audio_buf_len);
                    
                    kal_mem_cpy(vid_context_p->audio_buf_p, VID_AMR_HEADER, VID_AMR_HEADER_SIZE);
                    
                    vid_context_p->mhdl_handle->WriteDataDone(
                        vid_context_p->mhdl_handle, 
                        VID_AMR_HEADER_SIZE);
                }
                else if(vid_context_p->aud_format == MED_TYPE_AMR_WB)
                {
                    vid_context_p->mhdl_handle->GetWriteBuffer(
                        vid_context_p->mhdl_handle, 
                        &vid_context_p->audio_buf_p, 
                        &vid_context_p->audio_buf_len);
                    
                    kal_mem_cpy(vid_context_p->audio_buf_p, VID_AMR_WB_HEADER, VID_AMR_WB_HEADER_SIZE);
                    
                    vid_context_p->mhdl_handle->WriteDataDone(
                        vid_context_p->mhdl_handle, 
                        VID_AMR_WB_HEADER_SIZE);
                }

                vid_context_p->mhdl_handle->GetWriteBuffer(
                    vid_context_p->mhdl_handle, 
                    &vid_context_p->audio_buf_p, 
                    &vid_context_p->audio_buf_len);

                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_READ, __LINE__);    

                /* read size will be word size */
                eMp4ParserRet = MP4_Audio_Read(stMp4Parser_a_ptr, 
                                    (kal_uint8*)vid_context_p->audio_buf_p, 
                                    vid_context_p->audio_buf_len, 
                                    &uReadSize);
                
                vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
                kal_trace(TRACE_GROUP_4, VID_TRC_AUD_READ_BUF, vid_context_p->audio_buf_len,  uReadSize);                        


            #ifdef __MED_VID_PDL_MOD__
                if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
                {
                    if (eMp4ParserRet == MP4_PARSER_READ_EOF)
                    {
                        MP4_Parser_Status eMp4ParserGetAudRet;
                        MP4_Parser_Status eMp4ParsersSeekRet;                            
                        kal_uint32 available_time;  
                        kal_uint64 time_diff;
                        kal_uint64 cur_time;

                        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, __LINE__);      
                        eMp4ParserGetAudRet = MP4_Audio_GetAvailableDur(&stMp4Parser_pdl_a, &available_time);
                        vid_debug_print_mp4_parser_return(eMp4ParserGetAudRet, __LINE__);
                        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_DURATION, available_time);                               
                                                    
                        if (eMp4ParserGetAudRet != MP4_PARSER_OK)
                        {
                            VID_RETURN(MED_RES_PARSER_ERROR);
                        }     
                        
                        if (available_time < vid_context_p->total_audio_time)
                        {
                            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_GET_PLAY_TIME, __LINE__);      
                            video_dec_get_play_time(&cur_time);      
                            kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)cur_time, __LINE__);                                
                            time_diff = available_time - cur_time;    

                            kal_trace(
                                TRACE_GROUP_4, 
                                VID_TRC_TOTAL_DURATION, 
                                (kal_uint32)vid_context_p->total_time,
                                (kal_uint32)vid_context_p->total_audio_time,
                                (kal_uint32)vid_context_p->total_video_time); 
                            
                            if (time_diff < VID_PDL_BUFFER_TIME_FOR_PLAY)
                            {
                                /* already consumed by MP4_Audio_Read, seek to previous position */  
                                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_SEEK, audio_frame_num, __LINE__);                
                                eMp4ParsersSeekRet = MP4_Audio_Seek(stMp4Parser_a_ptr, audio_frame_num);                                
                                vid_debug_print_mp4_parser_return(eMp4ParsersSeekRet, __LINE__);
                                
                                VID_RETURN(MED_RES_PDL_AUDIO_UNDERFLOW);
                            }

                            /* not real EOF */
                            eMp4ParserRet = MP4_PARSER_OK;
                        }
                    }
                }
            #endif /* __MED_VID_PDL_MOD__ */

                if (eMp4ParserRet == MP4_PARSER_READ_EOF && uReadSize == 0 && 
                    (VID_IN_STATE(VID_VISUAL_PLAY_FINISH) || !VID_HAS_TRACK(MED_VISUAL_TRACK)))
                {
                    /* no more audio data and no visual track or visual already finished */
                    VID_RETURN(MED_RES_TERMINATED);
                }
            
                if (eMp4ParserRet == MP4_PARSER_OK ||
                    eMp4ParserRet == MP4_PARSER_NO_SUCH_TRACK ||
                    eMp4ParserRet == MP4_PARSER_READ_EOF ||
                    eMp4ParserRet == MP4_PARSER_WARNING_TRAILING_GARBAGE)
                {
                    Media_Status aud_ret;
                    
                    vid_context_p->mhdl_handle->WriteDataDone(
                        vid_context_p->mhdl_handle,
                        uReadSize);

                    /* Set to current active volume if audio is not muted */
                    if (!aud_context_p->audio_mute)
                    {
                        aud_set_active_ring_tone_volume();
                    }

                #ifdef __MED_AUD_TIME_STRETCH__                        
                    aud_stretch_close();
                #endif

                #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_AUD_BT_A2DP_OPEN_CODEC, __LINE__);      
                    aud_bt_a2dp_open_codec(vid_context_p->aud_format);
                #endif    

                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_PLAY, __LINE__);      
                    aud_ret = vid_context_p->mhdl_handle->Play(vid_context_p->mhdl_handle);
                    aud_debug_print_aud_drv_return(aud_ret, __LINE__);
                    
                    if (aud_ret == MEDIA_SUCCESS)
                    {
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_NORMAL);
                        VID_RETURN(MED_RES_OK);
                    }
                    else if (eMp4ParserRet == MP4_PARSER_READ_EOF)
                    {
                        /* This is the case that play to nearly end of file and Media play fails.
                           We should not regard it as error but EOF */

                        if (VID_HAS_TRACK(MED_VISUAL_TRACK))
                        {
                            if ((result = vid_play_dummy_audio()) == MED_RES_OK)
                            {
                                VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
                            }
                            VID_RETURN(result);
                        }
                        else
                        {
                            /* no visual track, should terminate */
                            VID_RETURN(MED_RES_TERMINATED);
                        }
                    }
                    else
                    {
                        /* other errors */
                        VID_RETURN(MED_RES_ERROR);
                    }
                }
                else    
                {
                    /* parser error */                        
                    VID_RETURN(MED_RES_PARSER_ERROR);
                }
            }
       #ifdef __MED_AUD_TIME_STRETCH__
            else if (eAudioType != MP4_AUDIO_NONE && 
                     AudioPP_TS_IsSupport(eAudioFormat, NULL) &&
                     vid_context_p->play_speed <= 160 && vid_context_p->play_speed >= 50)
            {
                vid_context_p->mhdl_handle->SetBuffer(
                    vid_context_p->mhdl_handle, 
                    (kal_uint8*)aud_context_p->ring_buf, 
                    AUD_RING_BUFFER_LEN * 2);    

                /*Need to fill up header for amr/awb play */
                if(vid_context_p->aud_format == MED_TYPE_AMR)
                {
                    vid_context_p->mhdl_handle->GetWriteBuffer(
                        vid_context_p->mhdl_handle, 
                        &vid_context_p->audio_buf_p, 
                        &vid_context_p->audio_buf_len);
                    
                    kal_mem_cpy(vid_context_p->audio_buf_p, VID_AMR_HEADER, VID_AMR_HEADER_SIZE);
                    
                    vid_context_p->mhdl_handle->WriteDataDone(
                        vid_context_p->mhdl_handle, 
                        VID_AMR_HEADER_SIZE);
                }
                else if(vid_context_p->aud_format == MED_TYPE_AMR_WB)
                {
                    vid_context_p->mhdl_handle->GetWriteBuffer(
                        vid_context_p->mhdl_handle, 
                        &vid_context_p->audio_buf_p, 
                        &vid_context_p->audio_buf_len);
                    
                    kal_mem_cpy(vid_context_p->audio_buf_p, VID_AMR_WB_HEADER, VID_AMR_WB_HEADER_SIZE);
                    
                    vid_context_p->mhdl_handle->WriteDataDone(
                        vid_context_p->mhdl_handle, 
                        VID_AMR_WB_HEADER_SIZE);
                }

                vid_context_p->mhdl_handle->GetWriteBuffer(
                    vid_context_p->mhdl_handle, 
                    &vid_context_p->audio_buf_p, 
                    &vid_context_p->audio_buf_len);

                
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_READ, __LINE__);   
                
                eMp4ParserRet = MP4_Audio_Read(
                    stMp4Parser_a_ptr, 
                    (kal_uint8*)vid_context_p->audio_buf_p, 
                    vid_context_p->audio_buf_len, 
                    &uReadSize);
                
                vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
                
                kal_trace(TRACE_GROUP_4, VID_TRC_AUD_READ_BUF, vid_context_p->audio_buf_len, uReadSize);    

            #ifdef __MED_VID_PDL_MOD__
                if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
                {
                    if (eMp4ParserRet == MP4_PARSER_READ_EOF)
                    {
                        MP4_Parser_Status eMp4ParserGetAudRet;
                        MP4_Parser_Status eMp4ParserSeekRet;                            
                        kal_uint32 available_time;  
                        kal_uint64 time_diff;
                        kal_uint64 cur_time;
                        
                        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, __LINE__);      
                        eMp4ParserGetAudRet = MP4_Audio_GetAvailableDur(&stMp4Parser_pdl_a, &available_time);
                        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
                        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_DURATION, available_time);  
                        
                        if (eMp4ParserGetAudRet != MP4_PARSER_OK)
                        {
                            VID_RETURN(MED_RES_PARSER_ERROR);
                        }     
                        
                        if (available_time < vid_context_p->total_audio_time)
                        {
                            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_GET_PLAY_TIME, __LINE__);      
                            video_dec_get_play_time(&cur_time);      
                            kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)cur_time, __LINE__);
                            time_diff = available_time - cur_time;    

                            kal_trace(
                                TRACE_GROUP_4, 
                                VID_TRC_TOTAL_DURATION, 
                                (kal_uint32)vid_context_p->total_time,
                                (kal_uint32)vid_context_p->total_audio_time,
                                (kal_uint32)vid_context_p->total_video_time); 
                            
                            if (time_diff < VID_PDL_BUFFER_TIME_FOR_PLAY)
                            {
                                /* already consumed by MP4_Audio_Read, seek to previous position */  
                                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_SEEK, audio_frame_num, __LINE__);                
                                eMp4ParserSeekRet = MP4_Audio_Seek(stMp4Parser_a_ptr, audio_frame_num);                                
                                vid_debug_print_mp4_parser_return(eMp4ParserSeekRet, __LINE__);
                                
                                VID_RETURN(MED_RES_PDL_AUDIO_UNDERFLOW);
                            }
                            
                            /* not real EOF */
                            eMp4ParserRet = MP4_PARSER_OK;                                
                        }
                    }
                }
           #endif /* __MED_VID_PDL_MOD__ */
           
                if (eMp4ParserRet == MP4_PARSER_OK ||
                    eMp4ParserRet == MP4_PARSER_NO_SUCH_TRACK ||
                    eMp4ParserRet == MP4_PARSER_READ_EOF ||
                    eMp4ParserRet == MP4_PARSER_WARNING_TRAILING_GARBAGE)
                {
                    Media_Status aud_ret;

                    vid_context_p->mhdl_handle->WriteDataDone(
                        vid_context_p->mhdl_handle,
                        uReadSize);
                    
                    /* Set to current active volume if audio is not muted */
                    if (!aud_context_p->audio_mute)
                    {
                        aud_set_active_ring_tone_volume();
                    }
                    
                    aud_stretch_set_speed(vid_context_p->play_speed);

                #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_AUD_BT_A2DP_OPEN_CODEC, __LINE__);                          
                    aud_bt_a2dp_open_codec(vid_context_p->aud_format);                        
                #endif

                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_PLAY, __LINE__);      
                    aud_ret = vid_context_p->mhdl_handle->Play(vid_context_p->mhdl_handle);                    
                    aud_debug_print_aud_drv_return(aud_ret, __LINE__);

                    if (aud_ret == MEDIA_SUCCESS)
                    {
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_NORMAL);
                        VID_RETURN(MED_RES_OK);
                    }
                    else if (eMp4ParserRet == MP4_PARSER_READ_EOF)
                    {
                        /* This is the case that play to nearly end of file and Media play fails.
                           We should not regard it as error but EOF */
                        if ((result = vid_play_dummy_audio()) == MED_RES_OK)
                        {
                            VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
                        }
                        VID_RETURN(result);
                    }
                    else
                    {
                        VID_RETURN(MED_RES_ERROR);
                    }
                }
                else    
                {
                    /* parser error */
                    VID_RETURN(MED_RES_PARSER_ERROR);
                }
            }
        #endif /* __MED_AUD_TIME_STRETCH__ */ 
            
            /* General case */
            if ((result = vid_play_dummy_audio()) == MED_RES_OK)
            {
                if (vid_context_p->play_speed == 100)
                {
                    VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
                }
                else
                {
                    VID_AUD_ENTER_STATE(VID_AUD_PLAY_HIGH_SPEED);
                }

                VID_RETURN(MED_RES_OK);
            }
            else
            {
                VID_RETURN(MED_RES_PARSER_ERROR);
            }

        }
        else if (eMp4ParserRet == MP4_PARSER_NO_SUCH_TRACK)
        {
            vid_context_p->video_track &= (~MED_AUDIO_TRACK);
            
            if (VID_HAS_TRACK(MED_VISUAL_TRACK))
            {
                if ((result = vid_play_dummy_audio()) == MED_RES_OK)
                {
                    if (vid_context_p->play_speed == 100)
                    {
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
                    }
                    else
                    {
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_HIGH_SPEED);
                    }
                }
                
                VID_RETURN(result);
            }
            else
            {
                /* no V and no A */
                VID_RETURN(MED_RES_BAD_FORMAT);
            }
        }
        else /* neither MP4_PARSER_OK nor MP4_PARSER_NO_SUCH_TRACK */
        {
            /* audio might broken, we may still play visual part */
            if (VID_HAS_TRACK(MED_VISUAL_TRACK))
            {
                if ((result = vid_play_dummy_audio()) == MED_RES_OK)
                {
                    if (vid_context_p->play_speed == 100)
                    {
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_DUMMY);
                    }
                    else
                    {
                        VID_AUD_ENTER_STATE(VID_AUD_PLAY_HIGH_SPEED);
                    }
                }
                
                VID_RETURN(result);
            }
            else
            {
                VID_RETURN(MED_RES_BAD_FORMAT);
            }
        }
    }
    
    VID_RETURN(MED_RES_OK);

}



/*****************************************************************************
 * FUNCTION
 *  vid_is_aud_playing
 * DESCRIPTION
 *  I aud playing.
 * PARAMETERS
 *  void
 * RETURNS
 *  is aud play nor not
 *****************************************************************************/
kal_bool vid_is_aud_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (vid_context_p->aud_state != VID_AUD_IDLE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_aud_format
 * DESCRIPTION
 *  Get audio format.
 * PARAMETERS
 *  void
 * RETURNS
 *  audio format
 *****************************************************************************/
kal_int32 vid_get_aud_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return vid_context_p->aud_format;
}


/*****************************************************************************
 * FUNCTION
 *  vid_check_stop_time
 * DESCRIPTION
 *  chcek stop time
 * PARAMETERS
 *  arg         [IN]        not used
 * RETURNS
 *  void
 *****************************************************************************/
void vid_check_stop_time(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_STOP_TIME);  
    vid_debug_print_cur_state(__LINE__);
    
    if (vid_context_p->stop_time == VID_MAX_STOP_TIME)
    {
        return;
    }
    
    kal_take_mutex(vid_context_p->vid_get_time_mutex);
    video_dec_get_play_time(&cur_time);
    kal_give_mutex(vid_context_p->vid_get_time_mutex);

    kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)cur_time);  
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_TIME, (kal_uint32)vid_context_p->stop_time);  
 
    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) ||
        VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        /* is playing */
        if (cur_time >= vid_context_p->stop_time)
        {
            vid_stop_audio();
            VID_ENTER_STATE(VID_PLAY_REACH_STOP_TIME);
            vid_send_visual_stop_req(NULL);    
            return;
        }
        else
        {
             med_start_timer(VID_STOP_TIME_TIMER, 300, vid_check_stop_time, 0);
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_play_restart
 * DESCRIPTION
 *  Restart video play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_RESTART);
    vid_debug_print_cur_state(__LINE__);
    
    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE || 
            vid_context_p->media_mode == MED_MODE_ARRAY || 
            vid_context_p->media_mode == MED_MODE_PDL_FILE ||
            vid_context_p->media_mode == MED_MODE_EDITOR_FILE)
        {
            MEDIA_STATUS_CODE status;
            kal_int32 result;
            MP4DEC_INIT_STRUCT clip_input;

            intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
            extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);

            clip_input.pstMp4Parser = stMp4Parser_v_ptr;
            clip_input.pstFSAL = stFSAL_v_ptr;
            clip_input.video_dec_callback = NULL;
            clip_input.max_width = vid_context_p->max_width;
            clip_input.max_height = vid_context_p->max_height;
            clip_input.audio_enable = KAL_TRUE; /* always open video */

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_CLIP_INITIALIZE, __LINE__);
            status = video_dec_initialize(&clip_input);                
            kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, status);    
                
            if (status != MEDIA_STATUS_OK)
            {
                result = vid_get_result_from_media_status(status);
                vid_send_play_finish_ind(result);
                VID_ENTER_STATE(VID_FILE_READY);
                VID_AUD_ENTER_STATE(VID_AUD_IDLE);
                return;
            }
            
            /* disable sleep when playing */
            visual_disable_sleep();
            
            if (VID_HAS_TRACK(MED_VISUAL_TRACK))
            {
                video_dec_set_play_speed(vid_context_p->play_speed);

                if (vid_context_p->display_device == MED_DISPLAY_TO_MAIN_LCD ||
                    vid_context_p->display_device == MED_DISPLAY_TO_SUB_LCD)
                {
                    video_image_path_open(image_data_path_ptr);
                    vid_context_p->image_path_open = KAL_TRUE;
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_DISPLAY, KAL_TRUE, __LINE__);                        
                    video_dec_set_display(KAL_TRUE);
                }
  
                vid_send_visual_play_req(NULL);

                vid_context_p->audio_end = KAL_FALSE;

                if (vid_context_p->play_audio)
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_AUDIO, KAL_TRUE, __LINE__);                                            
                    video_dec_set_audio(KAL_TRUE);
                }
                else
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_AUDIO, KAL_FALSE, __LINE__);                                            
                    video_dec_set_audio(KAL_FALSE);
                }


                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_PLAY, __LINE__);   
                status = video_dec_play(&vid_context_p->audio_frame_num, vis_send_decode_visual_data_ind, KAL_TRUE);                
                vid_debug_print_vid_drv_return(status, __LINE__);                
                kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, vid_context_p->audio_frame_num, __LINE__);                

  
                if (status != MEDIA_STATUS_OK)
                {
                    if (status == VIDEO_ERROR && VIDEO_GetLastError() == MED_STAT_VIDEO_DEC_SEEK_AUDIO_END)
                    {
                        VID_VIS_ERROR_TRACE(MED_STAT_VIDEO_DEC_SEEK_AUDIO_END, __LINE__);
                        vid_context_p->audio_end = KAL_TRUE;
                    }
                    else
                    {
                        vid_stop_visual();
                        vid_stop_audio();
                        vid_send_play_finish_ind(vid_get_result_from_media_status(status));
                        return;
                    }
                }

            }
            else
            {
                vid_context_p->audio_frame_num = 0;
            }

            if (vid_context_p->play_audio)
            {
                if (vid_context_p->play_audio && vid_context_p->current_time > vid_context_p->total_video_time)
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_TIMETOSAMPLENO, (kal_uint32)vid_context_p->current_time, __LINE__);                                            
                    MP4_Audio_TimeToSampleNo(
                        stMp4Parser_a_ptr,
                        vid_context_p->current_time,
                        &vid_context_p->audio_frame_num);
                    kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, vid_context_p->audio_frame_num, __LINE__);   
                }
                
                result = vid_play_audio(vid_context_p->audio_frame_num);
                
                if (result != MED_RES_OK)
                {
                    /* play error -> enter file ready state */
                    vid_stop_visual();
                    vid_stop_audio();
                    vid_send_play_finish_ind(result);
                    return;
                }
            }
        }

        VID_ENTER_STATE(VID_PLAY);
    }

}



/*****************************************************************************
 * FUNCTION
 *  vid_play_finish_hdlr
 * DESCRIPTION
 *  Play Finish.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_finish_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_FINISH_HDLR, vid_context_p->repeats);   
        
    if ((vid_context_p->media_mode == MED_MODE_FILE ||
         vid_context_p->media_mode == MED_MODE_ARRAY ||
         vid_context_p->media_mode == MED_MODE_EDITOR_FILE ||
         vid_context_p->media_mode == MED_MODE_PDL_FILE) && vid_context_p->repeats > 1)
    {
        if (vid_context_p->repeats != 0xffff)
        {
            vid_context_p->repeats--;
        }

        intmem_deinit();
        extmem_deinit();
        vid_play_restart();
    }
    else
    {
        vid_send_play_finish_ind(MED_RES_OK);
        VID_ENTER_STATE(VID_FILE_READY);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_play_req_hdlr
 * DESCRIPTION
 *  Handle video play request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_req_struct *req_p;

#ifdef __MED_VID_PDL_MOD__        
    kal_uint32 available_time;
    MP4_Parser_Status eMp4ParserAvailRet;
#endif 
    kal_uint64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_REQ_HDLR);      
    
    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_GET_PLAY_TIME, __LINE__); 
    kal_take_mutex(vid_context_p->vid_get_time_mutex);    
    video_dec_get_play_time(&cur_time);      
    kal_give_mutex(vid_context_p->vid_get_time_mutex);
    kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)cur_time, __LINE__);

    if ((vid_context_p->stop_time != VID_MAX_STOP_TIME) && 
        (cur_time >= vid_context_p->stop_time))
    {
        vid_set_result(MED_RES_REACH_STOP_TIME, __LINE__);
        VID_SET_EVENT(VID_EVT_PLAY);
        return;
    }

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_play_req_struct*) ilm_ptr->local_para_ptr;

    /* stop other audio */
    if (req_p->play_audio)
    {
        vid_stop_unfinished_audio();
    }

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        /* set this flag, so when stop, will able to put frame to buffer */
        vid_context_p->get_frame = KAL_TRUE;
        
        vid_context_p->image_buffer_address =
            (kal_uint32) req_p->image_buffer_p + req_p->display_offset_y * req_p->display_width * 2;
        image_data_path_ptr->lcd_data = &lcd_data;
        image_data_path_ptr->lcd_buf_addr = vid_context_p->image_buffer_address;

        image_data_path_ptr->disp_width = vid_context_p->display_width = req_p->display_width;
        image_data_path_ptr->disp_height = vid_context_p->display_height = req_p->display_height;
        image_data_path_ptr->video_display_offset_x = req_p->video_display_offset_x;
        image_data_path_ptr->video_display_offset_y = req_p->video_display_offset_y;
        image_data_path_ptr->force_lcd_hw_trigger = req_p->force_lcd_hw_trigger;
        
    #if MT6228_SERIES
    #ifdef __MED_TVO_MOD__
        /* TV Setting */
        tvo_context_p->tv_output = req_p->tv_output;
        tvo_context_p->tv_output_width = req_p->tv_output_width;
        tvo_context_p->tv_output_height = req_p->tv_output_height;
        tvo_context_p->tv_output_offset_x = req_p->tv_output_offset_x;
        tvo_context_p->tv_output_offset_y = req_p->tv_output_offset_y;
        tvo_context_p->tv_output_buffer1_address = req_p->tv_output_buffer1_address;
        tvo_context_p->tv_output_buffer2_address = req_p->tv_output_buffer2_address;
        tvo_context_p->tv_output_buffer_size = req_p->tv_output_buffer_size;
        /* LCD Setting */
        lcd_data.tv_output_width = tvo_context_p->tv_output_width;
        lcd_data.tv_output_height = tvo_context_p->tv_output_height;
        lcd_data.tv_output_offset_x = tvo_context_p->tv_output_offset_x;
        lcd_data.tv_output_offset_y = tvo_context_p->tv_output_offset_y;
        image_data_path_ptr->image_pitch_mode = req_p->image_pitch_mode;
        image_data_path_ptr->image_data_format = req_p->image_data_format;
        image_data_path_ptr->image_pitch_bytes = req_p->image_pitch_bytes;
        image_data_path_ptr->tv_output = tvo_context_p->tv_output;
        image_data_path_ptr->tv_output_frame_buffer1_address = (kal_uint32) tvo_context_p->tv_output_buffer1_address;
        image_data_path_ptr->tv_output_frame_buffer2_address = (kal_uint32) tvo_context_p->tv_output_buffer2_address;
        image_data_path_ptr->tv_output_frame_buffer_size = tvo_context_p->tv_output_buffer_size;
    #endif /* __MED_TVO_MOD__ */ 

    #endif /* MT6228_SERIES */ 
 
        if (vid_context_p->media_mode == MED_MODE_FILE || 
            vid_context_p->media_mode == MED_MODE_ARRAY ||
            vid_context_p->media_mode == MED_MODE_EDITOR_FILE ||
            vid_context_p->media_mode == MED_MODE_PDL_FILE)
        {
            MEDIA_STATUS_CODE status;
            kal_int32 result;

            vid_context_p->seq_num = req_p->seq_num;
            vid_context_p->display_device = req_p->display_device;
            vid_context_p->play_audio = req_p->play_audio;
            vid_context_p->repeats = req_p->repeats;
            vid_context_p->play_speed = vid_get_accurate_play_speed(req_p->play_speed);
            
            /* disable sleep when playing */
            visual_disable_sleep();
            if (VID_HAS_TRACK(MED_VISUAL_TRACK))
            {
                lcd_data.module_id = LCD_UPDATE_MODULE_MEDIA;
                lcd_data.lcd_id = req_p->lcd_id;
                lcd_data.lcm_start_x = req_p->lcd_start_x;
                lcd_data.lcm_start_y = req_p->lcd_start_y;
                lcd_data.lcm_end_x = req_p->lcd_end_x;
                lcd_data.lcm_end_y = req_p->lcd_end_y;
                lcd_data.roi_offset_x = req_p->roi_offset_x;
                lcd_data.roi_offset_y = req_p->roi_offset_y;
                lcd_data.update_layer = req_p->update_layer;
                lcd_data.hw_update_layer = req_p->hw_update_layer;
                lcd_data.fb_update_mode = LCD_HW_TRIGGER_MODE;
                lcd_data.rotate_value = (kal_uint8) req_p->lcd_rotate;
                
                video_dec_set_play_speed(vid_context_p->play_speed);
                vid_send_visual_play_req(NULL); /* to sync state of media-v */

                if (vid_context_p->display_device == MED_DISPLAY_TO_MAIN_LCD ||
                    vid_context_p->display_device == MED_DISPLAY_TO_SUB_LCD)
                {
                    video_image_path_open(image_data_path_ptr);
                    vid_context_p->image_path_open = KAL_TRUE;

                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_DISPLAY, KAL_TRUE, __LINE__);                       
                    video_dec_set_display(KAL_TRUE);
                }
                else if (vid_context_p->display_device == MED_DISPLAY_NONE)
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_DISPLAY, KAL_FALSE, __LINE__);                    
                    video_dec_set_display(KAL_FALSE);
                }

                vid_context_p->audio_end = KAL_FALSE;

                if (vid_context_p->play_audio)
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_AUDIO, KAL_TRUE, __LINE__);                      
                    video_dec_set_audio(KAL_TRUE);
                }
                else
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_AUDIO, KAL_FALSE, __LINE__);                      
                    video_dec_set_audio(KAL_FALSE);
                }

                if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
                {
                #ifdef __MED_VID_PDL_MOD__     
                    MEDIA_STATUS_CODE vid_ret;

                    /* get availabe time before start play */
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, __LINE__);      
                    eMp4ParserAvailRet = MP4_Video_GetAvailableDur(&stMp4Parser_pdl_v, &available_time);
                    vid_debug_print_mp4_parser_return(eMp4ParserAvailRet, __LINE__);
                    kal_trace(TRACE_GROUP_4, VID_TRC_VID_DURATION, available_time); 

                    if (eMp4ParserAvailRet != MP4_PARSER_OK)
                    {
                        vid_stop_visual();
                        vid_stop_audio();                        
                        vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
                        VID_SET_EVENT(VID_EVT_PLAY);
                        return;
                    }     

                    /* TRICKY!!!
                     * Must call MP4_Video_FrameAvailable() after MP4_Video_GetAvailableDur(), 
                     * this is due to driver's design.
                     */
                    /* call this function to check if video driver can start play or not */
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_VIDEO_FRAME_AVAILABLE, __LINE__);      
                    vid_ret = MP4_Video_FrameAvailable(&stMp4Parser_pdl_v);
                    vid_debug_print_vid_drv_return(vid_ret, __LINE__);

                    if (vid_ret != MEDIA_STATUS_OK)
                    {
                        if (vid_ret == FSAL_READ_EOF)
                        {
                            vid_stop_visual();
                            vid_stop_audio();                            
                            vid_set_result(MED_RES_PDL_VIDEO_UNDERFLOW, __LINE__);
                            VID_SET_EVENT(VID_EVT_PLAY);
                            return;
                        }
                        else if (vid_ret == VIDEO_ERROR)
                        {
                            vid_stop_visual();
                            vid_stop_audio();                            
                            vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
                            VID_SET_EVENT(VID_EVT_PLAY);
                            return;
                        }
                        else
                        {
                            /* invalid return code */
                            ASSERT(0);
                        }
                    }
                    
                #endif /* __MED_VID_PDL_MOD__ */
                }
                
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_PLAY, __LINE__);   
                status = video_dec_play(&vid_context_p->audio_frame_num, vis_send_decode_visual_data_ind, KAL_FALSE);                
                vid_debug_print_vid_drv_return(status, __LINE__);                
                kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, vid_context_p->audio_frame_num, __LINE__);                
 

            #ifdef __MED_VID_PDL_MOD__                
                if ((vid_context_p->media_mode == MED_MODE_PDL_FILE) && 
                    (status == FSAL_READ_EOF || status == FSAL_SEEK_EOF))
                {
                    kal_uint64 time_diff;
                    
                    if (available_time < vid_context_p->total_video_time)
                    {
                        time_diff = available_time - cur_time;    

                        kal_trace(
                            TRACE_GROUP_4, 
                            VID_TRC_TOTAL_DURATION, 
                            (kal_uint32)vid_context_p->total_time,
                            (kal_uint32)vid_context_p->total_audio_time,
                            (kal_uint32)vid_context_p->total_video_time);  
                        
                        if (time_diff < VID_PDL_BUFFER_TIME_FOR_PLAY)
                        {
                            vid_stop_visual();
                            vid_stop_audio();                            
                            vid_set_result(MED_RES_PDL_VIDEO_UNDERFLOW, __LINE__);
                            VID_SET_EVENT(VID_EVT_PLAY);  
                            return;
                        }
                        else
                        {
                            status = MEDIA_STATUS_OK;
                        }
                    }
                    
                }
            #endif /* __MED_VID_PDL_MOD__ */
              
                if (status != MEDIA_STATUS_OK)                                
                {
                    if (status == VIDEO_ERROR && VIDEO_GetLastError() == MED_STAT_VIDEO_DEC_SEEK_AUDIO_END)
                    {
                        VID_VIS_ERROR_TRACE(MED_STAT_VIDEO_DEC_SEEK_AUDIO_END, __LINE__);
                        vid_context_p->audio_end = KAL_TRUE;
                    }
                    else
                    {
                        vid_stop_visual();
                        vid_stop_audio();
                        vid_set_result(vid_get_result_from_media_status(status), __LINE__);
                        VID_SET_EVENT(VID_EVT_PLAY);
                        return;
                    }
                }

            }
            else
            {
                Media_A2V_EnableInterrupt(KAL_TRUE, 0);                        
                vid_context_p->audio_frame_num = 0;
            }

            if (vid_context_p->play_audio)
            {
                aud_context_p->melody_output_device = req_p->audio_path; 
                aud_get_active_device_path_by_mode(req_p->audio_path,aud_melody_set_output_device);

                if (VID_HAS_TRACK(MED_VISUAL_TRACK))
                {
                    if (vid_context_p->current_time > vid_context_p->total_video_time) 
                    {
                        /* A > V, get correct A's frame */
                        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_TIMETOSAMPLENO, (kal_uint32)vid_context_p->current_time, __LINE__);                                            
                        MP4_Audio_TimeToSampleNo(
                            stMp4Parser_a_ptr,
                            vid_context_p->current_time,
                            &vid_context_p->audio_frame_num);
                        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, vid_context_p->audio_frame_num, __LINE__);                       
                    }
                }
                else
                {
                    if (vid_context_p->current_time > vid_context_p->total_audio_time) 
                    {
                        /* a only, shall teminate, return OK and send play finish ind directly */
                        vid_stop_visual();
                        vid_stop_audio();        
                        vid_set_result(MED_RES_OK, __LINE__);
                        VID_SET_EVENT(VID_EVT_PLAY);

                        /* notify play finish */
                        vid_send_play_finish_ind(MED_RES_OK);   
                        return;
                    }
                    else
                    {
                        /* seek to current audio frame */
                        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_TIMETOSAMPLENO, (kal_uint32)vid_context_p->current_time, __LINE__);                                            
                        MP4_Audio_TimeToSampleNo(
                            stMp4Parser_a_ptr,
                            vid_context_p->current_time,
                            &vid_context_p->audio_frame_num);
                        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, vid_context_p->audio_frame_num, __LINE__);   
                    }
                }
            
                result = vid_play_audio(vid_context_p->audio_frame_num);

                if (result == MED_RES_TERMINATED)
                {
                    /* in this case, there is no V, and audio is terminated */
                    vid_stop_visual();
                    vid_stop_audio();
                    vid_set_result(MED_RES_OK, __LINE__);                    
                    vid_send_play_finish_ind(MED_RES_OK);
                    VID_SET_EVENT(VID_EVT_PLAY);     
                    return;         
                }
                else if (result != MED_RES_OK)
                {
                    vid_stop_visual();
                    vid_stop_audio();
                    vid_set_result(result, __LINE__);
                    VID_SET_EVENT(VID_EVT_PLAY);
                    return;
                }
                
            }
            else
            {
                /* do not play audio, will do nothing */
            }
        }
        else
        {
            /* unknow vid_context_p->media_mode */
            ASSERT(0);
        }
    
        if (VID_HAS_TRACK(MED_VISUAL_TRACK))
        {
            VID_ENTER_STATE(VID_PLAY);
        }
        else
        {   
            /* no visual track */
            VID_ENTER_STATE(VID_VISUAL_PLAY_FINISH);
        }

        if (vid_context_p->stop_time != VID_MAX_STOP_TIME)
        {
            /* playing - start a timer to check */
            med_start_timer(VID_STOP_TIME_TIMER, VID_STOP_TIME_CHECK_ELAPSE, vid_check_stop_time, 0);
        }
            
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

    VID_SET_EVENT(VID_EVT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *  vid_seek_req_hdlr
 * DESCRIPTION
 *  Handle video seek request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_seek_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct *req_p;
    MEDIA_STATUS_CODE status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SEEK_REQ_HDLR);      
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_seek_req_struct*) ilm_ptr->local_para_ptr;

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        if (!VID_HAS_TRACK(MED_VISUAL_TRACK))
        {
            vid_context_p->blocking = req_p->blocking;            
            vid_context_p->seq_num = req_p->seq_num;
            vid_context_p->current_time = req_p->time;
            
            /* disable sleep when seeking */
            visual_disable_sleep();

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SEEK, req_p->time, __LINE__);      
            status = video_dec_seek(req_p->time, vid_send_decode_event_ind);
            vid_debug_print_vid_drv_return(status, __LINE__);
            
            if (status != MEDIA_STATUS_OK)
            {
                vid_set_result(vid_get_result_from_media_status(status), __LINE__);
                visual_enable_sleep();
                VID_SET_EVENT(VID_EVT_SEEK);
                return;         
            }

            if (!vid_context_p->blocking)
            {
                VID_SET_EVENT(VID_EVT_SEEK); 
            }
           
            VID_ENTER_STATE(VID_SEEK);
            return;
        }

        vid_context_p->get_frame = req_p->get_frame;
        vid_context_p->image_buffer_address = (kal_uint32) req_p->image_buffer_p;
        vid_context_p->display_width = req_p->display_width;
        vid_context_p->display_height = req_p->display_height;
        vid_context_p->blocking = req_p->blocking;
        vid_context_p->seq_num = req_p->seq_num;
        
        /* seek to the required frame */
        vid_context_p->audio_end = KAL_FALSE;

        memmode_input_ptr->disp_width = vid_context_p->display_width;
        memmode_input_ptr->disp_height = vid_context_p->display_height;
        memmode_input_ptr->lcd_buf_addr = (kal_uint32) vid_context_p->image_buffer_address;
    #if MT6228_SERIES
        memmode_input_ptr->image_pitch_mode = KAL_FALSE; /* req_p->image_pitch_mode; */
        memmode_input_ptr->image_pitch_bytes = req_p->image_pitch_bytes;
        memmode_input_ptr->image_data_format = req_p->image_data_format;
    #ifdef __MED_TVO_MOD__
        memmode_input_ptr->tv_output = req_p->tv_output;
    #endif /* __MED_TVO_MOD__ */ 
    #endif /* MT6228_SERIES */ 
    
        /* disable sleep when seeking */
        visual_disable_sleep();
    
        if (vid_context_p->current_time == req_p->time && req_p->time != 0)
        {
            /* fill the image to the given image frame buffer */
            if (vid_context_p->get_frame && vid_context_p->image_buffer_address)
            {
                video_memorymode_open(memmode_input_ptr);
                video_dec_prev_frame_to_memory();
                video_memorymode_close();
            }
            
            /* enable sleep after recording */
            visual_enable_sleep();
            VID_ENTER_STATE(VID_FILE_READY);
            VID_SET_EVENT(VID_EVT_SEEK);
            
            if (!vid_context_p->blocking)
            {
                vid_send_seek_done_ind(MED_RES_OK);
            }
        }
        else
        {
            vid_context_p->current_time = req_p->time;

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SEEK, req_p->time, __LINE__);      
            status = video_dec_seek(req_p->time, vid_send_decode_event_ind);
            vid_debug_print_vid_drv_return(status, __LINE__);
           
            if (status != MEDIA_STATUS_OK)
            {
                vid_set_result(vid_get_result_from_media_status(status), __LINE__);
                
                /* enable sleep after recording */
                visual_enable_sleep();
                VID_SET_EVENT(VID_EVT_SEEK);
                return;
            }
            

            VID_ENTER_STATE(VID_SEEK);
            
            if (!vid_context_p->blocking)
            {
                VID_SET_EVENT(VID_EVT_SEEK);
            }
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_SEEK);
    }
}




/*****************************************************************************
 * FUNCTION
 *  vid_set_stop_time_req_hdlr
 * DESCRIPTION
 *  Handle video resume request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_stop_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_stop_time_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_STOP_TIME_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    req_p = (media_vid_set_stop_time_req_struct*) ilm_ptr->local_para_ptr;

    /* save stop time */
    vid_context_p->stop_time = req_p->stop_time;

    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) ||
        VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        /* playing - start a timer to check */
        med_start_timer(VID_STOP_TIME_TIMER, VID_STOP_TIME_CHECK_ELAPSE, vid_check_stop_time, 0);
    }

    VID_SET_EVENT(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_iframe_req_hdlr
 * DESCRIPTION
 *  Get Video i-frame request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_iframe_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_iframe_req_struct *req_p;
    kal_uint32 index;
    kal_uint64 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_IFRAME_REQ_HDLR);      
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_get_iframe_req_struct*) ilm_ptr->local_para_ptr;
    
    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_IDLE))
    {
        MP4_Parser_Status eMp4ParserRet;
        FSAL_Status eFSALRet;
        kal_uint32 filesize;
        kal_int32 result;

        eFSALRet = FSAL_Open_WithHandle(stFSAL_v_ptr, (void*)req_p->data);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            result = MED_RES_OPEN_FILE_FAIL;
            goto error_out;
        }
        FSAL_SetBuffer(stFSAL_v_ptr, VID_MP4_FSAL_BUF_SIZE, (kal_uint8*) mp4_vid_buf_ptr);

        eFSALRet = FSAL_GetFileSize(stFSAL_v_ptr, &filesize);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            result = MED_RES_OPEN_FILE_FAIL;
            goto error_out;
        }

        for (index = 0; index < VID_DEC_SEEK_HINT_SIZE; index++)
        {
            temp = ((kal_uint64) filesize * (kal_uint64) (index + 1)) / (kal_uint64) (VID_DEC_SEEK_HINT_SIZE + 1);
            vid_seek_hint_ptr[index].Index = (kal_uint32) temp;
        }
        DRM_set_seek_hint(stFSAL_v_ptr->hFile, VID_DEC_SEEK_HINT_SIZE, vid_seek_hint_ptr);

        eMp4ParserRet = MP4_Parse(stMp4Parser_v_ptr, stFSAL_v_ptr);
        if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
            result = MED_RES_BAD_FORMAT;
            goto error_out;
        }

        eMp4ParserRet = MP4_STBL_CacheTablePreprocess(
                            stMp4Parser_a_ptr, 
                            mp4_stbl_buf_ptr, 
                            VID_MP4_STBL_BUF_SIZE);
                          
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
            result = MED_RES_BAD_FORMAT;
            goto error_out;
        }

        eMp4ParserRet = MP4_Audio_SetFSAL(stMp4Parser_v_ptr, stFSAL_aud_data_ptr);
        if (eMp4ParserRet != FSAL_OK)
        {
            VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
            result = MED_RES_OPEN_FILE_FAIL;
            goto error_out;
        }

        eFSALRet = FSAL_Open_Attach(stFSAL_v_stco_ptr, stFSAL_v_ptr);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            result = MED_RES_OPEN_FILE_FAIL;
            goto error_out;
        }
        FSAL_SetBuffer(stFSAL_v_stco_ptr, VID_MP4_STCO_BUF_SIZE, (kal_uint8*) mp4_vid_stco_buf_ptr);

        eFSALRet = FSAL_Open_Attach(stFSAL_v_stsz_ptr, stFSAL_v_ptr);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            result = MED_RES_OPEN_FILE_FAIL;
            goto error_out;
        }
        FSAL_SetBuffer(stFSAL_v_stsz_ptr, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*) mp4_vid_stsz_buf_ptr);

        MP4_SetFSAL_STCO(stMp4Parser_v_ptr, MP4_TRACK_VIDEO, stFSAL_v_stco_ptr);
        MP4_SetFSAL_STSZ(stMp4Parser_v_ptr, MP4_TRACK_VIDEO, stFSAL_v_stsz_ptr);
        MP4_UpdateSampleCount(stMp4Parser_a_ptr, MP4_TRACK_VIDEO);

        /* decode the 1st frame to get image frame dimen */
        vid_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(vid_play_mem[0]);
        vid_context_p->intmem_size = vid_play_mem[0];
        vid_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(vid_play_mem[1]);
        vid_context_p->extmem_size = vid_play_mem[1];
        intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
        extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);

    #ifdef __MTK_TARGET__
        {
            MP4DEC_INIT_STRUCT mp4dec_init_input;

            mp4dec_init_input.pstFSAL = stFSAL_v_ptr;
            mp4dec_init_input.pstMp4Parser = stMp4Parser_v_ptr;
            //mp4dec_init_input.start_frame_no = req_p->frame_num;
            mp4dec_init_input.video_dec_callback = vid_send_decode_event_ind;
            video_dec_initialize(&mp4dec_init_input);
        }
    #else /* __MTK_TARGET__ */ 
        vid_send_decode_event_ind(VIDEO_DEC_EVENT_SEEK_DONE);
    #endif /* __MTK_TARGET__ */ 
        vid_context_p->blocking = req_p->blocking;
        vid_context_p->display_width = req_p->display_width;
        vid_context_p->display_height = req_p->display_height;
        vid_context_p->image_buffer_address = (kal_uint32) req_p->image_buffer_p;
        vid_context_p->image_buffer_size = req_p->image_buffer_size;

        memmode_input_ptr->disp_width = vid_context_p->display_width;
        memmode_input_ptr->disp_height = vid_context_p->display_height;
        memmode_input_ptr->lcd_buf_addr = (kal_uint32) vid_context_p->image_buffer_address;
    #if MT6228_SERIES
        memmode_input_ptr->image_pitch_mode = KAL_FALSE; /* req_p->image_pitch_mode; */
        memmode_input_ptr->image_pitch_bytes = req_p->image_pitch_bytes;
        memmode_input_ptr->image_data_format = req_p->image_data_format;
    #ifdef __MED_TVO_MOD__ 
        memmode_input_ptr->tv_output = req_p->tv_output;
    #endif /* __MED_TVO_MOD__ */ 
    #endif /* MT6228_SERIES */ 

        VID_ENTER_STATE(VID_GET_IFRAME);

        if (!vid_context_p->blocking)
        {
            VID_SET_EVENT(VID_EVT_GET_IFRAME);
        }
        return;

      error_out:
        if (vid_context_p->blocking)
        {
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_GET_IFRAME);
        }
        else
        {
            VID_SET_EVENT(VID_EVT_GET_IFRAME);
            vid_send_iframe_ready_ind((kal_int16) result);
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_GET_IFRAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_set_display_req_hdlr
 * DESCRIPTION
 *  This function is to handle video set display request
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_display_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_display_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_DISPLAY_REQ_HDLR);     

#if defined(NOKE_DEBUG)
    noke_dbg_printf( "vid_set_display_req_hdlr: entering ...\n\r" );
#endif	
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_set_display_req_struct*) ilm_ptr->local_para_ptr;

    if (vid_context_p->display_device != req_p->device)
    {
        vid_context_p->display_device = req_p->device;
        
        if (vid_context_p->display_device == MED_DISPLAY_TO_MAIN_LCD ||
            vid_context_p->display_device == MED_DISPLAY_TO_SUB_LCD)
        {
                    
            if (VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
            {
                if (vid_context_p->image_path_open != KAL_TRUE)
                {
                    video_image_path_open(image_data_path_ptr);
                    vid_context_p->image_path_open = KAL_TRUE;
                }

                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_DISPLAY, KAL_TRUE, __LINE__);                    
                video_dec_set_display(KAL_TRUE);
            }
        }
        else if (vid_context_p->display_device == MED_DISPLAY_NONE)
        {
            if ((VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
                && vid_context_p->image_path_open == KAL_TRUE)
            {
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_SET_DISPLAY, KAL_FALSE, __LINE__);                    
                video_dec_set_display(KAL_FALSE);
                
                video_image_path_close();
                vid_context_p->image_path_open = KAL_FALSE;
                
                /* update current frame to image buffer in case of direct-coupled playback */
                vid_update_frame_to_buffer();
            }
        }
    }
    
    VID_SET_EVENT(VID_EVT_BLOCK);

#if defined(NOKE_DEBUG)
    noke_dbg_printf( "vid_set_display_req_hdlr: exiting ...\n\r" );
#endif
}




/*****************************************************************************
 * FUNCTION
 *  vid_set_param_req_hdlr
 * DESCRIPTION
 *  Set Video parameter request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_param_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_PARAM_REQ_HDLR);     

    req_p = (media_vid_set_param_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->param_id)
    {
        case VID_PARAM_CONTRAST:
            memmode_input_ptr->contrast_level = (kal_uint8) req_p->value;
            image_data_path_ptr->contrast_level = (kal_uint8) req_p->value;
            break;
        case VID_PARAM_BRIGHTNESS:
            memmode_input_ptr->brightness_level = (kal_uint8) req_p->value;
            image_data_path_ptr->brightness_level = (kal_uint8) req_p->value;
            break;
        default:
            ASSERT(0);
            break;
    }

}




/*****************************************************************************
 * FUNCTION
 *  vid_visual_stop_cnf_hdlr
 * DESCRIPTION
 *  Handle visual stop confirm message from media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_stop_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    kal_uint32 cluster_size;
    FS_DiskInfo disc_info;
    kal_wchar drive[4] = L" :\\";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_STOP_CNF_HDLR);          
    vid_debug_print_cur_state(__LINE__);

    if (VID_IN_STATE(VID_PLAY_STOP_VISUAL))
    {
        video_dec_get_play_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)vid_context_p->current_time, __LINE__);
        
        VID_ENTER_STATE(VID_FILE_READY);
        VID_SET_EVENT(VID_EVT_STOP);
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        video_dec_get_play_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)vid_context_p->current_time, __LINE__);

        vid_stop_visual();
        vid_stop_audio();

        VID_ENTER_STATE(VID_FILE_READY);
        
        vid_send_play_finish_ind(MED_RES_AUDIO_ERROR);
    }
    else if (VID_IN_STATE(VID_PLAY_REACH_STOP_TIME))
    {
        video_dec_get_play_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)vid_context_p->current_time, __LINE__);

        vid_stop_visual();
        vid_stop_audio();

        VID_ENTER_STATE(VID_FILE_READY);
        
        vid_send_play_finish_ind(MED_RES_REACH_STOP_TIME);
    }
    else if (VID_IN_STATE(VID_PLAY_ABORTING))
    {
        /* get current play for next play */
        video_dec_get_play_time(&vid_context_p->current_time);
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);
        
        /* enable sleep after stop */
        visual_enable_sleep();

        VID_ENTER_STATE(VID_FILE_READY);
        
        vid_close_play_file(vid_context_p->media_mode, vid_context_p->handle);
        AUD_SET_EVENT(AUD_EVT_BLOCK);
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
    {
        ASSERT(0);
    }
    else if (VID_IN_STATE(VID_PLAY))
    {
        ASSERT(0);
    }
#if defined(__MED_VID_ENC_MOD__)
    else if (VID_IN_STATE(VID_RECORD))
    {
        /* stop video encode */
        video_enc_close();
        
        /* stop isp */
        exit_mpeg4_encode_process();

        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);                 
        Media_Stop();
        
    #ifdef __MED_AUD_TIME_STRETCH__
        aud_stretch_close();
    #endif 
    
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
        
        /* for debugging */
        vid_context_p->current_time = video_enc_get_current_time();
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);

        /* close visula files */
        vid_close_visual_file_for_record();
        
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            vid_close_audio_file_for_record();
        }

        /* release video memory */
        vid_release_memory();
        
        /* enable sleep after recording */
        visual_enable_sleep();

        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
    }
    else if (VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        /* for debugging */
        vid_context_p->current_time = video_enc_get_current_time();
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);
        
        /* close visula files */
        vid_close_visual_file_for_record();
        
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            vid_close_audio_file_for_record();
        }

        vid_release_memory();
        visual_enable_sleep();
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
    }
    else if (VID_IN_STATE(VID_RECORD_FINISH))
    {
        /* stop video encode */
        video_enc_close();
        
        /* stop isp */
        exit_mpeg4_encode_process();

        /* for debugging */
        vid_context_p->current_time = video_enc_get_current_time();
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);
        
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
        Media_Stop();
        
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);

        /* close visula files */
        vid_close_visual_file_for_record();
        
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            vid_close_audio_file_for_record();
        }

        /* release video memory */
        vid_release_memory();
        
        /* enable sleep after recording */
        visual_enable_sleep();

        VID_ENTER_STATE(VID_IDLE);
        if (vid_context_p->error_code != MED_RES_OK)
        {
            vid_send_record_finish_ind(vid_context_p->error_code);
        }
        else if (vid_context_p->file_size_limit > vid_context_p->file_size_info.file_size_limit ||
                 vid_context_p->file_size_limit == 0)
        {
            vid_send_record_finish_ind(MED_RES_DISC_FULL);
        }
        else
        {
            vid_send_record_finish_ind(MED_RES_END_OF_FILE);
        }
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        if (vid_dump_record_data_to_file() != MED_RES_OK)
        {
            /* stop isp */
            exit_mpeg4_encode_process();

            /* close visula files */
            vid_close_visual_file_for_record();
            
            /* close audio file */
            if (vid_context_p->record_audio)
            {
                vid_close_audio_file_for_record();
            }

            /* release video memory */
            vid_release_memory();

            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(result, __LINE__);
        }
        else
        {
            vid_set_result(result, __LINE__);
        }
        
        /* enable sleep after recording */
        visual_enable_sleep();

        VID_SET_EVENT(VID_EVT_PAUSE);
    }
    else if (VID_IN_STATE(VID_RECORD_ABORTING))
    {
        /* close visula files */
        vid_close_visual_file_for_record();
        
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            vid_close_audio_file_for_record();
        }

        /* release video memory */
        vid_release_memory();

        /* clean temp file due to block request */
        vid_clean_temp_files();
            
        /* enable sleep after recording */
        visual_enable_sleep();
    
        VID_ENTER_STATE(VID_IDLE);
        AUD_SET_EVENT(AUD_EVT_BLOCK);
    }   
#endif /* defined(__MED_VID_ENC_MOD__) */
    
    /* Log the disc info for debugging */
    drive[0] = vid_context_p->storing_path[0];
    FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
    cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

    kal_trace(                                                      
        TRACE_GROUP_4,                                              
        VID_TRC_DISC_FREE_SPACE,                                    
        disc_info.FreeClusters,                                     
        cluster_size,     
        cluster_size * disc_info.FreeClusters,                                                      
        __LINE__); 

}


/*****************************************************************************
 * FUNCTION
 *  vid_visual_play_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle visual play confirm message from media-v task
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_play_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_PLAY_CNF_HDLR);  

}


/*****************************************************************************
 * FUNCTION
 *  vid_visual_seek_cnf_hdlr
 * DESCRIPTION
 *  Handle visual seek confirm message from media-v task
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_seek_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_SEEK_CNF_HDLR);     
}



/*****************************************************************************
 * FUNCTION
 *  vid_visual_play_finish_ind_hdlr
 * DESCRIPTION
 *  Handle visual play finish indication message from media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_play_finish_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_PLAY_FINISH_IND_HDLR); 
    vid_debug_print_cur_state(__LINE__);
    
    ind_p = (media_visual_play_finish_ind_struct*) ilm_ptr->local_para_ptr;

    /* 
     * There maybe a very cirtial timing.
     * When MMI calling video play stop, VID will enter VID_PLAY_STOP_VISUAL state.
     * But at same time, MED_V (vis) underflow, and send play finish indication to MED.
     * it will enter following condition, and the stop's event will not be released in 
     * vid_visual_stop_cnf_hdlr()
     * plz refer to CR: 358376
     */

    if ((vid_context_p->media_mode == MED_MODE_PDL_FILE) && 
        (ind_p->result == MED_RES_PDL_VIDEO_UNDERFLOW) &&
        (!VID_IN_STATE(VID_PLAY_STOP_VISUAL)))
    {
        /* progressive video underflow */
        vid_stop_visual();
        vid_stop_audio();
        vid_send_play_finish_ind(MED_RES_PDL_VIDEO_UNDERFLOW);
        return;
    }
   
    if (VID_IN_STATE(VID_PLAY))
    {
        if (VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL) ||
            VID_AUD_IN_STATE(VID_AUD_PLAY_UNDERFLOW))
        {
            /* A > V case, visual is finised */
            VID_ENTER_STATE(VID_VISUAL_PLAY_FINISH);
        }
        else if (VID_AUD_IN_STATE(VID_AUD_PLAY_HIGH_SPEED) || 
                 VID_AUD_IN_STATE(VID_AUD_PLAY_DUMMY) || 
                 VID_AUD_IN_STATE(VID_AUD_IDLE)) 
        {
            vid_stop_visual();
            vid_stop_audio();            
            vid_play_finish_hdlr();
        }
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
    {
        /* ask l1audio to finish playing */
        /* 
         * we didnt call Media_DataFinished when aud play finish, 
         * since we need DSP keep awake 
         */
         
        vid_context_p->mhdl_handle->DataFinished(vid_context_p->mhdl_handle);
        vid_stop_visual();
        vid_stop_audio();            
        vid_play_finish_hdlr();
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        vid_stop_visual();
        vid_stop_audio();  
        vid_send_play_finish_ind(MED_RES_AUDIO_ERROR);
    }


}


/*****************************************************************************
 * FUNCTION
 *  vid_decode_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle visual decode event indication message from visual HISR
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_decode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_decode_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_DECODE_EVENT_IND_HDLR);
    vid_debug_print_cur_state(__LINE__);
    
    ind_p = (media_vid_decode_event_ind_struct*) ilm_ptr->local_para_ptr;
   
    switch (ind_p->event)
    {
        case VIDEO_DEC_DRV_SEEK_ACTION:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_DRV_SEEK_ACTION, __LINE__);              
            
            if (VID_IN_STATE(VID_OPEN_FILE) || VID_IN_STATE(VID_SEEK) || VID_IN_STATE(VID_GET_IFRAME))
            {
                video_seek_action();
            }
            break;

        case VIDEO_DEC_EVENT_BUFFER_EMPTY:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_EVENT_BUFFER_EMPTY, __LINE__);                         
            
            if (VID_IN_STATE(VID_OPEN_FILE) || VID_IN_STATE(VID_SEEK) || VID_IN_STATE(VID_GET_IFRAME))
            {
                MEDIA_STATUS_CODE status;
                kal_int32 result;

                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_DEC_PUT_FRAME_TO_BUFFER, __LINE__);                          
                status = video_dec_put_frame_to_buffer();
                vid_debug_print_vid_drv_return(status, __LINE__);
                
                if (status == MEDIA_STATUS_OK)
                {
                    break;
                }
                
                result = vid_get_result_from_media_status(status);
                
                if (VID_IN_STATE(VID_OPEN_FILE))
                {
                    video_dec_get_frame_size(&vid_context_p->image_width, &vid_context_p->image_height);
                    vid_context_p->total_frame_num = video_dec_get_total_frame();
                    video_dec_get_total_play_time(&vid_context_p->total_time);
                    VID_ENTER_STATE(VID_IDLE);
                    vid_send_file_ready_ind((kal_int16)result);
                }
                else if (VID_IN_STATE(VID_SEEK))
                {
                    visual_enable_sleep();

                    VID_ENTER_STATE(VID_FILE_READY);
                    if (vid_context_p->blocking)
                    {
                        vid_set_result(result, __LINE__);
                        VID_SET_EVENT(VID_EVT_SEEK);
                    }
                    else
                    {
                        vid_send_seek_done_ind((kal_int16)result);
                    }
                }
                else if (VID_IN_STATE(VID_GET_IFRAME))
                {
                    video_dec_close();
                    
                    intmem_deinit();
                    extmem_deinit();
                    vid_release_memory();

                    VID_ENTER_STATE(VID_IDLE);
                    if (vid_context_p->blocking)
                    {
                        vid_set_result(result, __LINE__);
                        VID_SET_EVENT(VID_EVT_GET_IFRAME);
                    }
                    else
                    {
                        vid_send_iframe_ready_ind((kal_int16)result);
                    }
                }
                break;
            }
            break;

        case VIDEO_DEC_EVENT_COMPLETE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_EVENT_COMPLETE, __LINE__);     
            
            if (VID_IN_STATE(VID_OPEN_FILE))
            {
                video_dec_get_frame_size(&vid_context_p->image_width, &vid_context_p->image_height);
                vid_context_p->total_frame_num = video_dec_get_total_frame();
                video_dec_get_total_play_time(&vid_context_p->total_time);
                VID_ENTER_STATE(VID_FILE_READY);
                vid_send_file_ready_ind(MED_RES_END_OF_FILE);
            }
            else if (VID_IN_STATE(VID_SEEK))
            {
                /* fill the image to the given image frame buffer */
                if (vid_context_p->get_frame && vid_context_p->image_buffer_address)
                {
                    video_memorymode_open(memmode_input_ptr);
                    video_dec_frame_to_memory();
                    video_memorymode_close();
                }

                visual_enable_sleep();

                VID_ENTER_STATE(VID_FILE_READY);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_END_OF_FILE, __LINE__);
                    VID_SET_EVENT(VID_EVT_SEEK);
                }
                else
                {
                    vid_send_seek_done_ind(MED_RES_END_OF_FILE);
                }
            }
            else if (VID_IN_STATE(VID_GET_IFRAME))
            {
                /* fill the image to the given image frame buffer */
                if (vid_context_p->image_buffer_address)
                {
                    memmode_input_ptr->disp_width = vid_context_p->display_width;
                    memmode_input_ptr->disp_height = vid_context_p->display_height;
                    memmode_input_ptr->lcd_buf_addr = (kal_uint32) vid_context_p->image_buffer_address;
                #if MT6228_SERIES
                    memmode_input_ptr->image_pitch_mode = KAL_FALSE;
                    memmode_input_ptr->image_pitch_bytes = 0;
                    memmode_input_ptr->image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
                #ifdef __MED_TVO_MOD__ 
                    memmode_input_ptr->tv_output = KAL_FALSE;
                #endif /* __MED_TVO_MOD__ */ 
                #endif /* MT6228_SERIES */ 
                    video_memorymode_open(memmode_input_ptr);
                    video_dec_frame_to_memory();
                    video_memorymode_close();
                }
                video_dec_close();

                /* deinit visual memory */
                intmem_deinit();
                extmem_deinit();

                /* release video memory */
                vid_release_memory();

                VID_ENTER_STATE(VID_IDLE);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_END_OF_FILE, __LINE__);
                    VID_SET_EVENT(VID_EVT_GET_IFRAME);
                }
                else
                {
                    vid_send_iframe_ready_ind(MED_RES_END_OF_FILE);
                }
            }
            break;

        case VIDEO_DEC_EVENT_SEEK_DONE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_EVENT_SEEK_DONE, __LINE__);  
            
            if (VID_IN_STATE(VID_OPEN_FILE))
            {
                video_dec_get_frame_size(&vid_context_p->image_width, &vid_context_p->image_height);
                vid_context_p->total_frame_num = video_dec_get_total_frame();
                video_dec_get_total_play_time(&vid_context_p->total_time);
                VID_ENTER_STATE(VID_FILE_READY);
                vid_send_file_ready_ind(MED_RES_OK);
            }
            else if (VID_IN_STATE(VID_SEEK))
            {
                if (VID_HAS_TRACK(MED_VISUAL_TRACK))
                {
                    /* fill the image to the given image frame buffer */
                    if (vid_context_p->get_frame && vid_context_p->image_buffer_address)
                    {
                        video_memorymode_open(memmode_input_ptr);
                        video_dec_frame_to_memory();
                        video_memorymode_close();
                    }
                }
                
                visual_enable_sleep();

                VID_ENTER_STATE(VID_FILE_READY);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_OK, __LINE__);
                    VID_SET_EVENT(VID_EVT_SEEK);
                }
                else
                {
                    vid_send_seek_done_ind(MED_RES_OK);
                }
            }
            else if (VID_IN_STATE(VID_GET_IFRAME))
            {
                /* fill the image to the given image frame buffer */
                if (vid_context_p->image_buffer_address)
                {
                    memmode_input_ptr->disp_width = vid_context_p->display_width;
                    memmode_input_ptr->disp_height = vid_context_p->display_height;
                    memmode_input_ptr->lcd_buf_addr = (kal_uint32) vid_context_p->image_buffer_address;
                #if MT6228_SERIES
                    memmode_input_ptr->image_pitch_mode = KAL_FALSE;
                    memmode_input_ptr->image_pitch_bytes = 0;
                    memmode_input_ptr->image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
                #ifdef __MED_TVO_MOD__ 
                    memmode_input_ptr->tv_output = KAL_FALSE;
                #endif /* __MED_TVO_MOD__ */ 
                #endif /* MT6228_SERIES */ 
                    video_memorymode_open(memmode_input_ptr);
                    video_dec_frame_to_memory();
                    video_memorymode_close();
                }
                video_dec_close();

                /* deinit visual memory */
                intmem_deinit();
                extmem_deinit();

                /* release video memory */
                vid_release_memory();

                VID_ENTER_STATE(VID_IDLE);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_OK, __LINE__);
                    VID_SET_EVENT(VID_EVT_GET_IFRAME);
                }
                else
                {
                    vid_send_iframe_ready_ind(MED_RES_OK);
                }
            }
            break;

        case VIDEO_DEC_EVENT_NO_TRACK:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_EVENT_NO_TRACK, __LINE__);  
            
            if (VID_IN_STATE(VID_OPEN_FILE))
            {
                video_dec_get_frame_size(&vid_context_p->image_width, &vid_context_p->image_height);
                vid_context_p->total_frame_num = video_dec_get_total_frame();
                video_dec_get_total_play_time(&vid_context_p->total_time);
                VID_ENTER_STATE(VID_FILE_READY);
                vid_send_file_ready_ind(MED_RES_MP4_NO_VIDEO_TRACK);
                vid_context_p->video_track &= (~MED_VISUAL_TRACK);
            }
            else if (VID_IN_STATE(VID_SEEK))
            {
                visual_enable_sleep();

                VID_ENTER_STATE(VID_FILE_READY);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_MP4_NO_VIDEO_TRACK, __LINE__);
                    VID_SET_EVENT(VID_EVT_SEEK);
                }
                else
                {
                    vid_send_seek_done_ind(MED_RES_MP4_NO_VIDEO_TRACK);
                }
            }
            else if (VID_IN_STATE(VID_GET_IFRAME))
            {
                video_dec_close();

                intmem_deinit();
                extmem_deinit();
                vid_release_memory();

                VID_ENTER_STATE(VID_IDLE);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_MP4_NO_VIDEO_TRACK, __LINE__);
                    VID_SET_EVENT(VID_EVT_GET_IFRAME);
                }
                else
                {
                    vid_send_iframe_ready_ind(MED_RES_MP4_NO_VIDEO_TRACK);
                }
            }
            break;

        case VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_SEEK_AUDIO_EVENT_COMPLETE, __LINE__);             
            break;
            
        case VIDEO_DEC_EVENT_FAIL:
            kal_trace(TRACE_GROUP_4, VID_TRC_VIDEO_DEC_EVENT_FAIL, __LINE__);     
            
            if (VID_IN_STATE(VID_OPEN_FILE))
            {
                video_dec_get_frame_size(&vid_context_p->image_width, &vid_context_p->image_height);
                vid_context_p->total_frame_num = video_dec_get_total_frame();
                video_dec_get_total_play_time(&vid_context_p->total_time);
                VID_ENTER_STATE(VID_IDLE);
                vid_send_file_ready_ind(MED_RES_VIDEO_ERROR);
            }
            else if (VID_IN_STATE(VID_SEEK))
            {
                visual_enable_sleep();

                VID_ENTER_STATE(VID_FILE_READY);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_VIDEO_ERROR, __LINE__);
                    VID_SET_EVENT(VID_EVT_SEEK);
                }
                else
                {
                    vid_send_seek_done_ind(MED_RES_VIDEO_ERROR);
                }
            }
            else if (VID_IN_STATE(VID_GET_IFRAME))
            {
                video_dec_close();
                intmem_deinit();
                extmem_deinit();
                vid_release_memory();

                VID_ENTER_STATE(VID_IDLE);
                if (vid_context_p->blocking)
                {
                    vid_set_result(MED_RES_VIDEO_ERROR, __LINE__);
                    VID_SET_EVENT(VID_EVT_GET_IFRAME);
                }
                else
                {
                    vid_send_iframe_ready_ind(MED_RES_VIDEO_ERROR);
                }
            }
            break;
        default:
            kal_trace(TRACE_GROUP_4, MED_TRC_VIDEO_DEC_UNKNOWN_ENUM, ind_p->event, __LINE__);             
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_audio_play_finish_ind_hdlr
 * DESCRIPTION
 *  Handle audio play finish indication message. It's used for playing
 *  at no-normal speed.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_play_finish_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_PLAY_FINISH_IND_HDLR);    

    vid_stop_visual();
    vid_stop_audio();
    vid_send_play_finish_ind(MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_error_recover_ind_hdlr
 * DESCRIPTION
 *  Handle error recover indication message from Media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_error_recover_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_ERROR_REVOCER_IND_HDLR);   
    vid_debug_print_cur_state(__LINE__);
    
    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) || 
        VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        MEDIA_STATUS_CODE status;

        /* Stop playing audio */
        if (VID_AUD_IN_STATE(VID_AUD_PLAY_HIGH_SPEED) ||
            VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL) || 
            VID_AUD_IN_STATE(VID_AUD_PLAY_DUMMY) ||
            VID_AUD_IN_STATE(VID_AUD_PLAY_UNDERFLOW))
        {
            vid_stop_audio();
        }

        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_VIDEO_DEC_RECOVER, __LINE__);
        status = video_dec_recover(&vid_context_p->audio_frame_num, vis_send_decode_visual_data_ind);
        vid_debug_print_vid_drv_return(status, __LINE__);        
        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, vid_context_p->audio_frame_num, __LINE__);                

    #ifdef __MED_VID_PDL_MOD__
        if (vid_context_p->media_mode == MED_MODE_PDL_FILE)
        {
            /* if EOF, means video_dec_recover cant get any frame */
            if (status == FSAL_READ_EOF || status == FSAL_SEEK_EOF)
            {
                vid_send_visual_stop_req(NULL);
                vid_stop_visual();
                vid_stop_audio();
                vid_send_play_finish_ind(MED_RES_PDL_VIDEO_UNDERFLOW); 
                med_debug_print_result(MED_RES_PDL_VIDEO_UNDERFLOW, __LINE__);
                return;
            }

            if (VID_AUD_IN_STATE(VID_AUD_PLAY_UNDERFLOW))
            {
                /*  
                 * [CR00389647]                
                 * if aud is in VID_AUD_PLAY_UNDERFLOW, 
                 * which means vid will be in VID_AUDIO_PLAY_FINISH.
                 *
                 * Error recover happened before we receive next 
                 * aud_media_write_data_ind.
                 *
                 * Since aud will restart again, we have to change
                 * vid state into VID_PLAY
                 */

                VID_ENTER_STATE(VID_PLAY);
            }
        }
    #endif /* __MED_VID_PDL_MOD__ */
    
        if (status != MEDIA_STATUS_OK)
        {
            if (status == VIDEO_ERROR &&
                VIDEO_GetLastError() == MED_STAT_VIDEO_DEC_SEEK_AUDIO_END)
            {
                /* video error due to audie end, will */
                kal_int32 result = MED_RES_OK;

                /* set this flag will play dummy video when calling vid_play_audio() */
                vid_context_p->audio_end = KAL_TRUE;
                
                if (vid_context_p->play_audio)
                {
                    result = vid_play_audio(vid_context_p->audio_frame_num);
                }
                
                if (result != MED_RES_OK)
                {
                    vid_send_visual_stop_req(NULL);                    
                    vid_stop_visual();
                    vid_stop_audio();
                    vid_send_play_finish_ind(result);
                    VID_ENTER_STATE(VID_FILE_READY);                    
                    return;
                }

            }
            else
            {
                /* vsiaul error */
                vid_send_visual_stop_req(NULL);
                vid_stop_visual();
                vid_stop_audio(); 
                vid_send_play_finish_ind((kal_int16)vid_get_result_from_media_status(status));
                VID_ENTER_STATE(VID_FILE_READY);
                return;
            }
        }

        /* resume audio */
        if (vid_context_p->play_audio)
        {
            kal_int32 result; 
            
        #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_AUD_BT_CLOSE_CODEC_FOR_OPEN, __LINE__);        
            aud_bt_a2dp_close_codec_for_open();
        #endif
            
            result = vid_play_audio(vid_context_p->audio_frame_num);
            
            if (result != MED_RES_OK)
            {
                vid_send_visual_stop_req(NULL);                    
                vid_stop_visual();
                vid_stop_audio();
                vid_send_play_finish_ind(result);
                VID_ENTER_STATE(VID_FILE_READY);                    
                return;
            }
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_stop_unfinished_task
 * DESCRIPTION
 *  This function is to stop video play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_unfinished_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_UNFINISHED_TASK);  
    vid_debug_print_cur_state(__LINE__);
    
    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_PLAY_PAUSED) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
    {
        /* get current play for next play */
        video_dec_get_play_time(&vid_context_p->current_time);
        
        vid_stop_visual();      
        vid_stop_audio();
        
        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_AUDIO_PLAY_ERROR);
        
    }
    else if (VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        vid_stop_visual();      
        vid_stop_audio();
        
        VID_ENTER_STATE(VID_FILE_READY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_is_audio_channel_available
 * DESCRIPTION
 *  Check if the audio channel is avaiable.
 * PARAMETERS
 *  void
 * RETURNS
 *  Avaialbe or not
 *****************************************************************************/
kal_bool vid_is_audio_channel_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_IS_AUDIO_CHANNEL_AVAILABLE);  
    vid_debug_print_cur_state(__LINE__);    

    if (VID_IN_STATE(VID_IDLE))
    {
        return KAL_TRUE;
    }
    else if (VID_IN_STATE(VID_PLAY) ||
             VID_IN_STATE(VID_PLAY_PAUSED) ||
             VID_IN_STATE(VID_AUDIO_PLAY_FINISH) ||
             VID_IN_STATE(VID_AUDIO_PLAY_ERROR) ||
             VID_IN_STATE(VID_VISUAL_PLAY_FINISH) ||
             VID_IN_STATE(VID_FILE_READY) ||
             VID_IN_STATE(VID_SEEK) || 
             VID_IN_STATE(VID_GET_IFRAME))
    {
        if (VID_AUD_IN_STATE(VID_AUD_IDLE))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else if (VID_IN_STATE(VID_RECORD) ||
             VID_IN_STATE(VID_RECORD_FINISH) || 
             VID_IN_STATE(VID_RECORD_PAUSED) || 
             VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_abort_by_client_switching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 vid_abort_by_client_switching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_ABORT_BY_CLIENT_SWITCHING);     
    vid_debug_print_cur_state(__LINE__);    

    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) || 
        VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        /* get current play for next play */
        video_dec_get_play_time(&vid_context_p->current_time);
        
        vid_stop_visual();
        vid_stop_audio();

        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_PLAY_ABORTING);
        VID_RETURN(MED_RES_BUSY);
    }
    else if (VID_IN_STATE(VID_FILE_READY))
    {
        /* close the video files */
        vid_close_play_file(vid_context_p->media_mode, vid_context_p->handle);
        VID_RETURN(MED_RES_OK);
    }
    else if (VID_IN_STATE(VID_SEEK))
    {
        /* get current play for next play */
        video_dec_get_play_time(&vid_context_p->current_time);
        /* stop seek */
        video_dec_stop();

        /* enable sleep after recording */
        visual_enable_sleep();

        VID_ENTER_STATE(VID_FILE_READY);
        /* close the video files */
        vid_close_play_file(vid_context_p->media_mode, vid_context_p->handle);
        VID_RETURN(MED_RES_OK);
    }
    else if (VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        video_dec_get_play_time(&vid_context_p->current_time);

        vid_stop_visual();
        vid_stop_audio();
        
        VID_ENTER_STATE(VID_FILE_READY);
        /* close the video files */
        vid_close_play_file(vid_context_p->media_mode, vid_context_p->handle);
        VID_RETURN(MED_RES_OK);
    }
    else if (VID_IN_STATE(VID_PDL_META_BUFFERING))
    {
        med_stop_timer(VID_PDL_BUFFERING_TIMER);   
        FSAL_Close(stFSAL_v_ptr);          
        VID_ENTER_STATE(VID_IDLE);
        VID_RETURN(MED_RES_OK);        
    }
    else if (VID_IN_STATE(VID_PLAY_REACH_STOP_TIME))
    {
        vid_stop_visual();
        vid_stop_audio();

        VID_ENTER_STATE(VID_PLAY_ABORTING);
        VID_RETURN(MED_RES_BUSY);        
    }
#if defined(__MED_VID_ENC_MOD__)
    else if (VID_IN_STATE(VID_PREVIEW))
    {
        /* stop isp */
        exit_mpeg4_encode_process();
        vid_release_memory();
        VID_ENTER_STATE(VID_IDLE);
        VID_RETURN(MED_RES_OK);
    }
    else if (VID_IN_STATE(VID_RECORD))
    {
        /* stop visual encoding */
        video_enc_close();
        
        /* stop isp */
        exit_mpeg4_encode_process();
        
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
        Media_Stop();
        
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_RECORD_ABORTING);
        VID_RETURN(MED_RES_BUSY);
    }
    else if (VID_IN_STATE(VID_RECORD_FINISH))
    {
        /* stop visual encoding */
        video_enc_close();
        
        /* stop isp */
        exit_mpeg4_encode_process();
        
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
        Media_Stop();
        
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);

        VID_ENTER_STATE(VID_RECORD_ABORTING);
        VID_RETURN(MED_RES_BUSY);
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {

        /* stop mpeg encode process */
        exit_mpeg4_encode_process();
        
        /* close visula files */
        vid_close_visual_file_for_record();
        
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            vid_close_audio_file_for_record();
        }

        /* enable sleep after recording */
        visual_enable_sleep();
        vid_release_memory();

        /* clean temp files in case they are mis-used by another application */
        vid_clean_temp_files();
        VID_ENTER_STATE(VID_IDLE);
        VID_RETURN(MED_RES_OK);
        
    }
    else if (VID_IN_STATE(VID_FILE_MERGE))
    {
        VID_ENTER_STATE(VID_RECORD_ABORTING);
        VID_RETURN(MED_RES_BUSY);
    }    
#endif /* defined(__MED_VID_ENC_MOD__) */
    else
    {
        VID_RETURN(MED_RES_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_set_vol_level
 * DESCRIPTION
 *  set vol level
 * PARAMETERS
 *  vol_level       [IN]        vol level
 * RETURNS
 *  
 *****************************************************************************/
void vid_set_vol_level(kal_uint8 vol_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->vol_level = vol_level;
    
    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->SetLevel(vid_context_p->mhdl_handle, vol_level);
    }
}


#if defined(__MED_VID_ENC_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_evaluate_residual_size
 * DESCRIPTION
 *  Evaluate the residual size with the given video size.
 * PARAMETERS
 *  video_size      [IN]         video size       
 * RETURNS
 *  Predicted residual size.
 *****************************************************************************/
kal_uint32 vid_evaluate_residual_size(kal_uint32 video_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 audio_size;
    kal_uint32 sum;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (vid_context_p->use_pseudo_merge)
    {
        kal_uint32 cluster_size;
        cluster_size = vid_context_p->file_size_info.disk_cluster_size;
        audio_size = (vid_context_p->file_size_info.audio_bitstream_size + (cluster_size - 1)) / (cluster_size);
        audio_size = audio_size * cluster_size;
        sum = (video_size + audio_size +
               vid_context_p->file_size_info.audio_meta_size + vid_context_p->file_size_info.video_meta_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        sum = ((sum + 1) / cluster_size) * cluster_size;
        
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            size = (vid_context_p->file_size_info.file_size_limit - 
                    sum + 
                    video_size -
                    vid_context_p->file_size_info.video_bitstream_size);
        }
        else
        {
            size = 0;
        }
    }
    else
    {
        sum = (video_size + vid_context_p->file_size_info.audio_bitstream_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            size =  (vid_context_p->file_size_info.file_size_limit - sum);
        }
        else
        {
            size = 0;
        }
    }

    return size; 
}


/*****************************************************************************
 * FUNCTION
 *  vid_evaluate_audio_real_meta_file_size
 * DESCRIPTION
 *  Evaluate the current audio real meta size.
 * PARAMETERS
 *  audio_record_time       [IN]        audio record time
 * RETURNS
 *  Predicted audio real meta size
 *****************************************************************************/
kal_uint32 vid_evaluate_audio_real_meta_file_size(kal_uint64 audio_record_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 aud_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EVALUATE_AUDIO_REAL_META_FILE_SIZE, (kal_uint32)audio_record_time);

    /* Only for AMR, not for WAMR */
    aud_time = (((audio_record_time * 213) >> 10) + 500);
    kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, aud_time, __LINE__);    
    
    return aud_time;
}


/*****************************************************************************
 * FUNCTION
 *  vid_evaluate_audio_meta_file_size
 * DESCRIPTION
 *  Evaluate the current audio meta size.
 * PARAMETERS
 *  audio_record_time       [IN]        audio record time
 * RETURNS
 *  Predicted audio meta size
 *****************************************************************************/
kal_uint32 vid_evaluate_audio_meta_file_size(kal_uint64 audio_record_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 aud_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EVALUATE_AUDIO_META_FILE_SIZE, (kal_uint32)audio_record_time);
    
    /* Only for AMR, not for WAMR */
    aud_time = ((audio_record_time / 20) + 50);
    kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, aud_time, __LINE__);    
  
    return aud_time;
}


/*****************************************************************************
 * FUNCTION
 *  vid_file_visual_residual_size
 * DESCRIPTION
 *  Get the residual file size for visual data.
 * PARAMETERS
 *  void
 * RETURNS
 *  Visual residual size
 *****************************************************************************/
kal_uint32 vid_file_visual_residual_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 video_size;
    kal_uint32 audio_size;
    kal_uint32 sum;
    kal_uint32 ret_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_VISUAL_RESIDUAL_SIZE);
    ret_val = 0;
    
    if (vid_context_p->use_pseudo_merge)
    {
        kal_uint32 cluster_size;
        cluster_size = vid_context_p->file_size_info.disk_cluster_size;
        video_size = (vid_context_p->file_size_info.video_bitstream_size + (cluster_size - 1)) / (cluster_size);
        video_size = video_size * cluster_size;
        audio_size = (vid_context_p->file_size_info.audio_bitstream_size + (cluster_size - 1)) / (cluster_size);
        audio_size = audio_size * cluster_size;
        sum = (video_size + audio_size +
               vid_context_p->file_size_info.audio_meta_size + vid_context_p->file_size_info.video_meta_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        sum = ((sum + 1) / cluster_size) * cluster_size;
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            ret_val =  
                vid_context_p->file_size_info.file_size_limit - 
                sum + 
                video_size -
                vid_context_p->file_size_info.video_bitstream_size;
        }
        else
        {
            ret_val = video_size - vid_context_p->file_size_info.video_bitstream_size;
        }
    }
    else
    {
        kal_uint32 res1, res2;
        sum = (vid_context_p->file_size_info.video_bitstream_size + vid_context_p->file_size_info.audio_bitstream_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            res1 = (vid_context_p->file_size_info.file_size_limit - sum);
        }
        else
        {
            res1= 0;
        }
        
        sum = sum + vid_context_p->file_size_info.audio_bitstream_size;

        if (vid_context_p->free_disc_space > sum + vid_context_p->rec_mem_margin)
        {
            res2 = (vid_context_p->free_disc_space - sum - vid_context_p->rec_mem_margin);
        }
        else
        {
            res2 = 0;
        }

        ret_val = MIN(res1, res2); 
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, ret_val, __LINE__);    
    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  vid_file_audio_residual_size
 * DESCRIPTION
 *  Get the residual file size for audio data.
 * PARAMETERS
 *  void
 * RETURNS
 *  Audio residual size
 *****************************************************************************/
kal_uint32 vid_file_audio_residual_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 video_size;
    kal_uint32 audio_size;
    kal_uint32 sum;
    kal_uint32 ret_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_AUDIO_RESIDUAL_SIZE);
    ret_val = 0;
    
    if (vid_context_p->use_pseudo_merge)
    {
        kal_uint32 cluster_size;
        cluster_size = vid_context_p->file_size_info.disk_cluster_size;
        video_size = (video_enc_get_bitstream_file_size() + (cluster_size - 1)) / (cluster_size);
        video_size = video_size * cluster_size;
        audio_size = (vid_context_p->file_size_info.audio_bitstream_size + (cluster_size - 1)) / (cluster_size);
        audio_size = audio_size * cluster_size;

        sum = (video_size + audio_size +
               vid_context_p->file_size_info.audio_meta_size + vid_context_p->file_size_info.video_meta_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        sum = ((sum + 1) / cluster_size) * cluster_size;
        
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            ret_val = 
                vid_context_p->file_size_info.file_size_limit - 
                sum + 
                audio_size -
                vid_context_p->file_size_info.audio_bitstream_size;
        }
        else
        {
            ret_val = 
                audio_size - 
                vid_context_p->file_size_info.audio_bitstream_size - 
                (cluster_size * 2);
        }
    }
    else
    {
        kal_uint32 res1, res2;
        
        sum = (video_enc_get_bitstream_file_size() + vid_context_p->file_size_info.audio_bitstream_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            res1 = (vid_context_p->file_size_info.file_size_limit - sum);
        }
        else
        {
            res1= 0;
        }
        
        sum = sum + vid_context_p->file_size_info.audio_bitstream_size;
        if (vid_context_p->free_disc_space > sum + vid_context_p->rec_mem_margin)
        {
            res2 = (vid_context_p->free_disc_space - sum - vid_context_p->rec_mem_margin);
        }
        else
        {
            res2 = 0;
        }

        ret_val = MIN(res1, res2);
    }
    
    kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, ret_val, __LINE__);         
    return ret_val;

}


/*****************************************************************************
 * FUNCTION
 *  vid_file_meta_residual_size
 * DESCRIPTION
 *  This function is to get the residual file size for meta data.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 vid_file_meta_residual_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 video_size;
    kal_uint32 audio_size;
    kal_uint32 sum;
    kal_uint32 ret_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_META_RESIDUAL_SIZE);
    ret_val = 0;
    
    if (vid_context_p->use_pseudo_merge)
    {
        kal_uint32 cluster_size;
        cluster_size = vid_context_p->file_size_info.disk_cluster_size;
        video_size = (vid_context_p->file_size_info.video_bitstream_size + (cluster_size - 1)) / (cluster_size);
        video_size = video_size * cluster_size;
        audio_size = (vid_context_p->file_size_info.audio_bitstream_size + (cluster_size - 1)) / (cluster_size);
        audio_size = audio_size * cluster_size;

        sum = (video_size + audio_size +
               vid_context_p->file_size_info.audio_meta_size + vid_context_p->file_size_info.video_meta_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        
        if (vid_context_p->file_size_info.file_size_limit > (sum))
        {
            ret_val = (vid_context_p->file_size_info.file_size_limit - (sum));
        }
        else
        {
            if (vid_context_p->file_size_info.video_meta_size < 128)
            {
                ret_val = 128;
            }
            else
            {
                ret_val = 0;
            }
        }
    }
    else
    {
        kal_uint32 res1, res2;
        
        sum = (vid_context_p->file_size_info.video_bitstream_size + vid_context_p->file_size_info.audio_bitstream_size +
               vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        if (vid_context_p->file_size_info.file_size_limit > sum)
        {
            res1 = (vid_context_p->file_size_info.file_size_limit - sum);
        }
        else
        {
            res1= 0;
        }
        
        sum = sum + vid_context_p->file_size_info.audio_bitstream_size;
        
        if (vid_context_p->free_disc_space > sum + vid_context_p->rec_mem_margin)
        {
            res2 = (vid_context_p->free_disc_space - sum - vid_context_p->rec_mem_margin);
        }
        else
        {
            res2 = 0;
        }
        
        if( MIN(res1, res2) >0)
        {
            ret_val = MIN(res1, res2);
        }
        else
        {
            if (vid_context_p->file_size_info.video_meta_size < 128)
            {
                ret_val = 128;
            }
            else
            {
                ret_val = 0;
            }
        }
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, ret_val, __LINE__);      
    return ret_val;    
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_current_file_size
 * DESCRIPTION
 *  Get the current video file size.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current file size
 *****************************************************************************/
kal_uint32 vid_get_current_file_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 video_size;
    kal_uint32 audio_size;
    kal_uint32 sum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_CURRENT_FILE_SIZE);

    if (vid_context_p->use_pseudo_merge)
    {
        kal_uint32 cluster_size;
        cluster_size = vid_context_p->file_size_info.disk_cluster_size;
        video_size = (vid_context_p->file_size_info.video_bitstream_size + (cluster_size - 1)) / (cluster_size);
        video_size = video_size * cluster_size;
        audio_size = (vid_context_p->file_size_info.audio_bitstream_size + (cluster_size - 1)) / (cluster_size);
        audio_size = audio_size * cluster_size;

        kal_trace(                                          
            TRACE_GROUP_4,                                  
            VID_TRC_RECORD_FILE_SIZE,                       
            video_size,                                     
            vid_context_p->file_size_info.video_meta_size,  
            vid_context_p->file_size_info.video_rm_size,       
            audio_size,                                     
            vid_context_p->file_size_info.audio_meta_size,  
            vid_context_p->file_size_info.audio_rm_size,    
            __LINE__);

        sum = (video_size + audio_size +
                   vid_context_p->file_size_info.audio_meta_size + vid_context_p->file_size_info.video_meta_size +
                   vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);

        kal_trace(                                          
            TRACE_GROUP_4,                                  
            VID_TRC_RECORD_FILE_LIMIT,                      
            vid_context_p->file_size_info.file_size_limit,  
            sum,                                            
            __LINE__);
        
        return sum;
    }
    else
    {
        kal_trace(                                              
            TRACE_GROUP_4,                                      
            VID_TRC_RECORD_FILE_SIZE,                           
            vid_context_p->file_size_info.video_bitstream_size, 
            vid_context_p->file_size_info.video_meta_size,      
            vid_context_p->file_size_info.video_rm_size,           
            vid_context_p->file_size_info.audio_bitstream_size, 
            vid_context_p->file_size_info.audio_meta_size,      
            vid_context_p->file_size_info.audio_rm_size,        
            __LINE__);
        
        sum =
            (vid_context_p->file_size_info.video_bitstream_size + vid_context_p->file_size_info.audio_bitstream_size +
             vid_context_p->file_size_info.audio_rm_size + vid_context_p->file_size_info.video_rm_size);
        
        kal_trace(                                          
            TRACE_GROUP_4,                                  
            VID_TRC_RECORD_FILE_LIMIT,                      
            vid_context_p->file_size_info.file_size_limit,  
            sum,                                            
            __LINE__);

        kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, sum, __LINE__);            
        return sum;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_disc_free_space
 * DESCRIPTION
 *  Get disc free space
 * PARAMETERS
 *  dir_name        [IN]     directory name
 *  free            [OUT]    disk free value, in byte
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
kal_uint16 vid_get_disc_free_space(kal_wchar *dir_name, kal_uint64 *free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_DISC_FREE_SPACE);
    
    /* TODO: free maybe overflow */
    
    kal_mem_set(dir, 0, 6);
    kal_mem_cpy(dir, dir_name, 4);
    
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (result > 0 && result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
    {
        *free = disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector;
        
        kal_trace(                                                      
            TRACE_GROUP_4,                                              
            VID_TRC_DISC_FREE_SPACE,                                    
            disc_info.FreeClusters,                                     
            disc_info.SectorsPerCluster * disc_info.BytesPerSector,     
            *free,                                                      
            __LINE__); 

        VID_RETURN(MED_RES_OK)
    }
    else
    {
        VID_RETURN(MED_RES_NO_DISC)        
    }
}
/*****************************************************************************
 * FUNCTION
 *  vid_audio_record_callback
 * DESCRIPTION
 *  Handle the callback of audio record.
 * PARAMETERS
 *  event       [IN]        Media_Event
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_record_callback(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_RECORD_CALLBACK, event);    
    
    switch (event)
    {
        case MEDIA_TERMINATED:
        case MEDIA_ERROR:
        case MEDIA_END:
        {
            aud_media_read_data_ind_struct *ind_p = NULL;

            ind_p = (aud_media_read_data_ind_struct*)
                construct_local_para(sizeof(aud_media_read_data_ind_struct), TD_CTRL);

            ind_p->event = event;

            aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_READ_DATA_IND, ind_p, NULL);
            break;
        }
        
        case MEDIA_DATA_NOTIFICATION:
        {
            if (!aud_context_p->processing_data)
            {
                aud_media_read_data_ind_struct *ind_p = NULL;

                ind_p = (aud_media_read_data_ind_struct*)
                    construct_local_para(sizeof(aud_media_read_data_ind_struct), TD_CTRL);

                ind_p->event = event;

                aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_READ_DATA_IND, ind_p, NULL);
                aud_context_p->processing_data = KAL_TRUE;
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_audio_record_callback_dummy
 * DESCRIPTION
 *  Handle the dummy callback of audio record.
 * PARAMETERS
 *  event       [IN]        Media_Event
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_record_callback_dummy(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_RECORD_CALLBACK_DUMMY, event);    
    
    switch (event)
    {
        case MEDIA_TERMINATED:
            break;
        case MEDIA_DATA_NOTIFICATION:
        {
            kal_uint16 *pwBuf;
            kal_uint32 uBufLen;

            Media_GetReadBuffer(&pwBuf, &uBufLen);
            Media_ReadDataDone(uBufLen);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_save_file_path
 * DESCRIPTION
 *  Save file path for further use.
 * PARAMETERS
 *  path        [IN]     file path
 * RETURNS
 *  Save file path result
 *****************************************************************************/
kal_int32 vid_save_file_path(kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SAVE_FILE_PATH);    
    
    FS_Rename((kal_wchar*) VID_DUMMY_INIT_FILE, (kal_wchar*) VID_INIT_FILE);
    fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_CREATE | FS_READ_WRITE);

    if (fd >= 0)
    {
        kal_wchar flag;

        if (vid_context_p->use_pseudo_merge)
        {
            flag = L'Y';
        }
        else
        {
            flag = L'N';
        }
        
        result = FS_Write(fd, &flag, (1) * ENCODE_BYTE, &len);
        result = FS_Write(fd, path, (kal_wstrlen(path) + 1) * ENCODE_BYTE, &len);

        kal_trace(TRACE_GROUP_4, VID_TRC_USE_PESUDO_MERGE, vid_context_p->use_pseudo_merge, __LINE__);          

        FS_Close(fd);

        if (result == FS_NO_ERROR)
        {
            VID_RETURN(MED_RES_OK);
        }
        else
        {
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);
        }
    }
    else
    {
        VID_RETURN(MED_RES_OPEN_FILE_FAIL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_open_audio_file_for_record
 * DESCRIPTION
 *  Open audio file for record.
 * PARAMETERS
 *  void
 * RETURNS
 *  Open file result
 *****************************************************************************/
kal_int16 vid_open_audio_file_for_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_AUDIO_FILE_FOR_RECORD);    
    
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_FILE);

    if ((vid_context_p->file_handle = FS_Open(vid_context_p->storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
        {
            VID_RETURN(MED_RES_WRITE_PROTECTION);
        }
        else
        {
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);
        }
    }

    eFSALRet = FSAL_Open_WithHandle(&stFSALProducerAudData, (void*)vid_context_p->file_handle);
    if (eFSALRet == FSAL_OK)
    {

        eFSALRet = FSAL_Write_UINT(&stFSALProducerAudData, 0);  /* file size */
        if (eFSALRet == FSAL_OK)
        {
            eFSALRet = FSAL_Write_UINT(&stFSALProducerAudData, BOX_TYPE_MDAT);
            
            if (eFSALRet == FSAL_OK)
            {
                VID_RETURN(MED_RES_OK);
            }
        }
        /* Fail */
        FSAL_Close(&stFSALProducerAudData);
        VID_RETURN(MED_RES_OPEN_FILE_FAIL);
    }
    else
    {
        if (FSAL_GetLastError(&stFSALProducerAudData) == FS_WRITE_PROTECTION)
        {
            VID_RETURN(MED_RES_WRITE_PROTECTION);
        }
        else
        {
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_open_visual_file_for_record
 * DESCRIPTION
 *  This function is to open visual files for record.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 vid_open_visual_file_for_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_VISUAL_FILE_FOR_RECORD);    
    
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_FILE);
    
    if ((vid_context_p->file_handle = FS_Open(vid_context_p->storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
        {
            VID_RETURN(MED_RES_WRITE_PROTECTION);
        }
        else
        {
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);
        }
    }
    eFSALRet = FSAL_Open_WithHandle(&mp4_files.MEDIA_VIDEO_FILE, (void*)vid_context_p->file_handle);
    if (eFSALRet == FSAL_OK)
    {
        /* Open meta file */
        med_remove_file_name(vid_context_p->storing_path);
        kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_META_FILE);
        if ((vid_context_p->file_handle = FS_Open(vid_context_p->storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
        {
            FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
            if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
            {
                VID_RETURN(MED_RES_WRITE_PROTECTION);
            }
            else
            {
                VID_RETURN(MED_RES_OPEN_FILE_FAIL);
            }
        }
        eFSALRet = FSAL_Open_WithHandle(&mp4_files.MEDIA_META_FILE, (void*)vid_context_p->file_handle);
        
        if (eFSALRet == FSAL_OK)
        {
            VID_RETURN(MED_RES_OK);
        }
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        
        VID_RETURN(MED_RES_OPEN_FILE_FAIL);
    }
    else
    {
        if (FSAL_GetLastError(&mp4_files.MEDIA_META_FILE) == FS_WRITE_PROTECTION)
        {
            VID_RETURN(MED_RES_WRITE_PROTECTION);
        }
        else
        {
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_close_visual_file_for_record
 * DESCRIPTION
 *  Close visual files for recording including dump data to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Close file result
 *****************************************************************************/
kal_int16 vid_close_visual_file_for_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    FSAL_Status eFSALRet;
    kal_uint32 residual_size;
    kal_uint32 increase_size;
    MEDIA_STATUS_CODE status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_VISUAL_FILE_FOR_RECORD);    
        
    residual_size = vid_file_meta_residual_size();

    /* Store META file */
    status = meta_enc_buffer_store_file(residual_size, &increase_size);
    VID_VALUE_TRACE(residual_size, increase_size, __LINE__); 
    if (status != MEDIA_STATUS_OK)
    {
        result = vid_get_result_from_media_status(status);
        vid_context_p->error_code = result;
    }
    /* Close meta file */
    eFSALRet = FSAL_Close(&mp4_files.MEDIA_META_FILE);
    if (eFSALRet != FSAL_OK && result == MED_RES_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__); 
        result = MED_RES_OPEN_FILE_FAIL;
        vid_context_p->error_code = result;
    }
    
    vid_context_p->file_size = vid_get_current_file_size();
    /* Store VIDEO file */
    if (residual_size > increase_size)
    {
        residual_size = residual_size - increase_size;
    }
    else
    {
        residual_size = 0;
    }
    status = video_enc_buffer_dump_to_file(residual_size, &increase_size);
    VID_VALUE_TRACE(residual_size, increase_size, __LINE__);

    vid_context_p->file_size_info.video_bitstream_size += increase_size;
    vid_context_p->file_size_info.video_rm_size = video_evaluate_real_meta_file_size(vid_context_p->file_size_info.short_header_mode);
    vid_context_p->file_size = vid_get_current_file_size();
    VID_VALUE_TRACE(vid_context_p->file_size, vid_context_p->file_size_info.video_bitstream_size, vid_context_p->file_size_info.video_rm_size); 
    
    if (status != MEDIA_STATUS_OK && result == MED_RES_OK)
    {
        result = vid_get_result_from_media_status(status);
        vid_context_p->error_code = result;
    }

    eFSALRet = FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
    if (eFSALRet != FSAL_OK && result == MED_RES_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        result = MED_RES_OPEN_FILE_FAIL;
        vid_context_p->error_code = result;
    }

    VID_RETURN(result);
}


/*****************************************************************************
 * FUNCTION
 *  vid_close_audio_file_for_record
 * DESCRIPTION
 *  Close audio file for recording including dump data to file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Close audio file result
 *****************************************************************************/
kal_int16 vid_close_audio_file_for_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;
    kal_uint16 *pwBuf;
    kal_uint32 uBufLen;
    FSAL_Status eFSALRet;
    kal_uint32 residual_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_AUDIO_FILE_FOR_RECORD);  
    
    residual_size = vid_file_audio_residual_size();

    Media_GetReadBuffer(&pwBuf, &uBufLen);
    if (residual_size < uBufLen * 2)
    {
        uBufLen = (residual_size >> 1);
    }
    if (uBufLen > 0)
    {
        eFSALRet = FSAL_Write(&stFSALProducerAudData, (kal_uint8*) pwBuf, uBufLen * 2);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__); 
            result = MED_RES_FSAL_ERROR;
            vid_context_p->error_code = result;
        }
        Media_ReadDataDone(uBufLen);
    }
    vid_context_p->file_size = vid_get_current_file_size();

    /* Close audio file */
    eFSALRet = FSAL_Close(&stFSALProducerAudData);
    if (eFSALRet != FSAL_OK && result == MED_RES_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__); 
        result = MED_RES_OPEN_FILE_FAIL;
        vid_context_p->error_code = result;
    }

    VID_RETURN(result);
}


/*****************************************************************************
 * FUNCTION
 *  vid_preview_req_hdlr
 * DESCRIPTION
 *  Handle video preview request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_preview_req_struct *req_p;
    MEDIA_STATUS_CODE status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PREVIEW_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_READY))
    {
        req_p = (media_vid_preview_req_struct*) ilm_ptr->local_para_ptr;

        mp4_encode.intmem_start_address 
            = vid_context_p->intmem_start_address 
            = (kal_uint32)med_alloc_int_mem(vid_record_mem[0]);
        
        mp4_encode.intmem_size 
            = vid_context_p->intmem_size 
            = vid_record_mem[0];
        
        mp4_encode.extmem_start_address 
            = vid_context_p->extmem_start_address 
            = (kal_uint32)med_alloc_ext_mem(vid_record_mem[1]);
        
        mp4_encode.extmem_size 
            = vid_context_p->extmem_size 
            = vid_record_mem[1];

        if(mp4_encode.extmem_start_address==NULL)
        {
            ASSERT(mp4_encode.extmem_start_address!=0);
            vid_release_memory();
            vid_set_result(MED_RES_MEM_INSUFFICIENT, __LINE__);
            VID_SET_EVENT(VID_EVT_PREVIEW);
            return;
        }

        mp4_encode.mpeg4_image_width = req_p->image_width;
        mp4_encode.mpeg4_image_height = req_p->image_height;

        if (req_p->image_width <= 176 && req_p->image_height <= 144)
        {
            /* smaller than QCIF */
            vid_context_p->rec_mem_margin = VIDEO_RECORD_QCIF_MEM_MARGIN;
        }
        else
        {
            vid_context_p->rec_mem_margin = VIDEO_RECORD_CIF_MEM_MARGIN;
        }
        
        
        /* 64000,128000,256000 */
        vid_context_p->encode_quality = req_p->encode_quality;

        if (vid_context_p->em_mode == VID_EM_MODE_ULTRA_HIGH_BITRATE)
        {
            /* engineer mode */
            mp4_encode.encode_bit_rate = 1000000;
            mp4_encode.skip_frame_count = 0;
        }
        else
        {
            vid_convert_quality_to_bitrate(
                mp4_encode.mpeg4_image_width,
                mp4_encode.mpeg4_image_height,
                req_p->encode_quality,
                &mp4_encode.encode_bit_rate,
                &mp4_encode.skip_frame_count);
        }
        
        vid_context_p->bit_stream_type = req_p->bit_stream_type;
        
        if (vid_context_p->bit_stream_type == VID_3GP_BIT_STREAM)
        {
            mp4_encode.short_header_mode = KAL_TRUE;
        }
        else
        {
            mp4_encode.short_header_mode = KAL_FALSE;
        }

        mp4_encode.image_target_width = req_p->preview_width;
        mp4_encode.image_target_height = req_p->preview_height;

        mp4_encode.lcd_id = req_p->lcd_id;
        mp4_encode.lcm_start_x = req_p->lcd_start_x;
        mp4_encode.lcm_start_y = req_p->lcd_start_y;
        mp4_encode.lcm_end_x = req_p->lcd_end_x;
        mp4_encode.lcm_end_y = req_p->lcd_end_y;
        mp4_encode.roi_offset_x = req_p->roi_offset_x;
        mp4_encode.roi_offset_y = req_p->roi_offset_y;
        mp4_encode.update_layer = req_p->update_layer;
        mp4_encode.hw_update_layer = req_p->hw_update_layer;
        mp4_encode.lcd_update = req_p->lcd_update;

        mp4_encode.frame_buffer_address = (kal_uint32) req_p->image_buffer_p;
        mp4_encode.frame_buffer_size = req_p->image_buffer_size;
        mp4_encode.mpeg4_offset_x = req_p->preview_offset_x;
        mp4_encode.mpeg4_offset_y = req_p->preview_offset_y;
        mp4_encode.resume_enable = KAL_FALSE;
        mp4_encode.rotate_value = (kal_uint8) req_p->lcd_rotate;
        mp4_encode.image_mirror = cam_rotate_map[req_p->rotate];
        mp4_encode.frame_rate = 15;

        mp4_encode.zoom_factor = (kal_uint8) req_p->zoom_factor;
        mp4_encode.ev_value = req_p->exposure;
        mp4_encode.wb_mode = req_p->WB;
        mp4_encode.contrast_level = req_p->contrast;
        mp4_encode.brightness_level = req_p->brightness;
        mp4_encode.saturation_value = req_p->saturation;
        mp4_encode.image_effect = req_p->effect;
        mp4_encode.night_mode = req_p->night_mode;
        mp4_encode.banding_freq = req_p->banding_freq;

        mp4_encode.encode_event_cb = vis_send_encode_visual_data_ind;
        mp4_encode.cam_encode_cb = cam_preview_callback;
    #if MT6228_SERIES
        /* IPP Setting */
        mp4_encode.overlay_frame_mode = req_p->overlay_frame_mode;
        mp4_encode.overlay_color_depth = req_p->overlay_color_depth;
        mp4_encode.overlay_frame_source_key = req_p->overlay_frame_source_key;
        mp4_encode.overlay_frame_width = req_p->overlay_frame_width;
        mp4_encode.overlay_frame_height = req_p->overlay_frame_height;
        mp4_encode.overlay_frame_buffer_address = req_p->overlay_frame_buffer_address;

        mp4_encode.image_pitch_mode = req_p->image_pitch_mode;
        mp4_encode.image_data_format = req_p->image_data_format;
        mp4_encode.image_pitch_bytes = req_p->image_pitch_bytes;

    #ifdef __MED_TVO_MOD__
        /* TVout Setting */    
        mp4_encode.tv_output = req_p->tv_output;
        mp4_encode.tv_output_width = req_p->tv_output_width;
        mp4_encode.tv_output_height = req_p->tv_output_height;
        mp4_encode.tv_output_offset_x = req_p->tv_output_offset_x;
        mp4_encode.tv_output_offset_y = req_p->tv_output_offset_y;
        mp4_encode.tv_output_buffer1_address = req_p->tv_output_buffer1_address;
        mp4_encode.tv_output_buffer2_address = req_p->tv_output_buffer2_address;
        mp4_encode.tv_output_buffer_size = req_p->tv_output_buffer_size;
    #endif /* __MED_TVO_MOD__ */ 
        /* LCD Setting */
        mp4_encode.roi_background_color = req_p->roi_background_color;
    #endif /* MT6228_SERIES */ 

        mp4_encode.init_mem = KAL_TRUE;
        status = (MEDIA_STATUS_CODE) mpeg4_encode_process(&mp4_encode);
    
        if (status != MEDIA_STATUS_OK)
        {
            vid_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(vid_get_result_from_media_status(status), __LINE__);
            VID_SET_EVENT(VID_EVT_PREVIEW);
            return;
        }
        else
        {
            vid_set_result(MED_RES_OK, __LINE__);
            VID_ENTER_STATE(VID_PREVIEW);
            VID_SET_EVENT(VID_EVT_PREVIEW);            
            return;
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_ENTER_STATE(VID_PREVIEW);        
        VID_SET_EVENT(VID_EVT_PREVIEW);        
        return;        
    }

    /* shall not enter here */
    ASSERT(0);

}


/*****************************************************************************
 * FUNCTION
 *  vid_record_req_hdlr
 * DESCRIPTION
 *  Handle video record request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_req_struct *req_p;
    kal_wchar drive[4] = L" :\\";
    FS_DiskInfo disc_info;
    kal_int32 result;
    MEDIA_STATUS_CODE status;
    Media_Status aud_status;
    kal_bool video_file_open = KAL_FALSE;
    kal_bool audio_file_open = KAL_FALSE;
    kal_uint32 cluster_size;
    kal_bool is_aud_codec_open = KAL_FALSE;
    kal_uint32 file_margin;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RECORD_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_record_req_struct*) ilm_ptr->local_para_ptr;

    vid_stop_unfinished_audio();

    vid_context_p->seq_num = req_p->seq_num;

    if (VID_IN_STATE(VID_PREVIEW))
    {
        
        /* stop unfinished audio task */
        aud_stop_unfinished_process();
        
        /* clean temp files in case of abort shut down when last file merge process */
        kal_mem_cpy(vid_context_p->storing_path, req_p->data, MAX_FILE_NAME_LEN * ENCODE_BYTE);
        med_remove_file_name(vid_context_p->storing_path);
        kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_FILE);
        FS_Delete(vid_context_p->storing_path);

        med_remove_file_name(vid_context_p->storing_path);
        kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
        FS_Delete(vid_context_p->storing_path);

        med_remove_file_name(vid_context_p->storing_path);
        kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_FILE);
        FS_Delete(vid_context_p->storing_path);

        med_remove_file_name(vid_context_p->storing_path);
        kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_META_FILE);
        FS_Delete(vid_context_p->storing_path);

        med_remove_file_name(vid_context_p->storing_path);
        kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_REAL_META_FILE);
        FS_Delete(vid_context_p->storing_path);

        /* reset the error code */
        vid_context_p->error_code = MED_RES_OK;

        /* init file info */
        kal_mem_set(&(vid_context_p->file_size_info), 0, sizeof(video_file_info_struct));
        
        /* check disc space before stop preview to prevent the preview screen from pausing */
        result = vid_get_disc_free_space((kal_wchar*) req_p->data, &vid_context_p->free_disc_space);
        
        /* Get disc info, free space, cluster size */
        drive[0] = vid_context_p->storing_path[0];

        vid_context_p->file_size_info.video_bitstream_size = 0x20;
        vid_context_p->file_size_info.video_rm_size = 0;
        vid_context_p->file_size_info.audio_rm_size = 0;
        
        FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);

        kal_prompt_trace(MOD_MED, "[VID] disk_info.BytePerSecotr:%d, line: %d", disc_info.BytesPerSector, __LINE__);
        kal_prompt_trace(MOD_MED, "[VID] disk_info.SectorsPerCluster:%d, line: %d", disc_info.SectorsPerCluster, __LINE__);        

        cluster_size 
            = vid_context_p->file_size_info.disk_cluster_size 
            = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

        kal_prompt_trace(MOD_MED, "[VID] cluster_size:%d, line: %d", vid_context_p->file_size_info.disk_cluster_size, __LINE__);        
        
        /* count the file size limit based on required and free memory space */
        vid_context_p->file_size_limit = req_p->file_size_limit;

        
        /* to start record, we need at least rec_mem_margin + 3 * cluster (for pesudo merge) */
        
        file_margin = cluster_size * 3;
        kal_prompt_trace(MOD_MED, "[VID] file_margin:%d, line: %d", file_margin, __LINE__);        

        /* check remained drive is enoguth or not (at least need 3 clusters for merge and record min size */
        if (vid_context_p->free_disc_space <= file_margin + vid_context_p->rec_mem_margin)
        {
            result = MED_RES_DISC_FULL;
            kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                     
            goto record_error;
        }  
            
        if (req_p->file_size_limit == 0)
        {
            /* if not size limit from MMI , the size limit depends on disc space */
            vid_context_p->use_pseudo_merge = KAL_TRUE;
            vid_context_p->file_size_info.file_size_limit = vid_context_p->free_disc_space - file_margin;
            kal_prompt_trace(MOD_MED, "[VID] file_size_limit:%d, line: %d", vid_context_p->file_size_info.file_size_limit, __LINE__);                     
        }
        else
        {
            /* if given size limit from MMI , the size limit depends on disc space and given size limit */
            vid_context_p->use_pseudo_merge = KAL_FALSE;
            if (vid_context_p->free_disc_space >= req_p->file_size_limit + file_margin)
            {
                vid_context_p->file_size_info.file_size_limit = req_p->file_size_limit;
                kal_prompt_trace(MOD_MED, "[VID] file_size_limit:%d, line: %d", vid_context_p->file_size_info.file_size_limit, __LINE__);                     
            }
            else 
            {
                vid_context_p->file_size_info.file_size_limit = vid_context_p->free_disc_space - file_margin;
                kal_prompt_trace(MOD_MED, "[VID] file_size_limit:%d, line: %d", vid_context_p->file_size_info.file_size_limit, __LINE__);                                     
            }
        }

        vid_context_p->file_size_info.short_header_mode = mp4_encode.short_header_mode;

        vid_context_p->media_mode = req_p->media_mode;

        if (req_p->media_mode == MED_MODE_FILE)
        {
            if (result != MED_RES_OK)
            {
                kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                     
                goto record_error;
            }

            kal_mem_cpy(vid_context_p->storing_path, req_p->data, MAX_FILE_NAME_LEN * ENCODE_BYTE);

            if (kal_wstrlen(vid_context_p->storing_path) < 3)
            {
                result = MED_RES_OPEN_FILE_FAIL;
                kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                     
                goto record_error;
            }

            vid_context_p->record_audio = req_p->record_audio;
            if ((result = vid_save_file_path(req_p->data)) != MED_RES_OK)
            {
                kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                                     
                goto record_error;
            }

            /* disable sleep when playing */
            visual_disable_sleep();

            Media_A2V_HookInterrupt(NULL);
            Media_A2V_SetTimeStamp(0x3FFF);
            Media_A2V_EnableInterrupt(KAL_TRUE, 0);

            if (vid_context_p->record_audio)
            {
                vid_context_p->file_size_info.audio_bitstream_size = 8;
                result = vid_open_audio_file_for_record();
                if (result != MED_RES_OK)
                {
                    kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                                         
                    goto record_error;
                }
                audio_file_open = KAL_TRUE;
                Media_SetBuffer((kal_uint16*) aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                video_enc_set_audioformat(MEDIA_FORMAT_AMR);
                /* video_enc_audiocallback(vid_audio_record_callback); */
            }
            else
            {
                vid_context_p->file_size_info.audio_bitstream_size = 0;
                Media_SetBuffer((kal_uint16*) aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                video_enc_set_audioformat(MEDIA_FORMAT_AMR);
                /* video_enc_audiocallback(vid_audio_record_callback_dummy); */
            }

            result = vid_open_visual_file_for_record();
            if (result != MED_RES_OK)
            {
                kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                                     
                goto record_error;
            }
            video_file_open = KAL_TRUE;

            /* Send message to sync state of media-v */
            vid_send_visual_record_req(NULL);
            
            /* reset this flag for audio recording callback */
            aud_context_p->processing_data = KAL_FALSE;
            
            /* Encode start */
            /* Start audio encoding */
            Media_A2V_SetInterruptCount(0);
            if (vid_context_p->record_audio)
            {
                aud_status = Media_Record(MEDIA_FORMAT_AMR, vid_audio_record_callback, (void*)0x03);   /* 0x03 = DSP AMR 12.20 type */
            }
            else
            {
                aud_status = Media_Record(MEDIA_FORMAT_AMR, vid_audio_record_callback_dummy, (void*)0x03);     /* 0x03 = DSP AMR 12.20 type */
            }
            
            if (aud_status != MEDIA_SUCCESS)
            {
                result = aud_get_res(aud_status);
                kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                                     
                goto record_error;
            }
            else
            {
                is_aud_codec_open = KAL_TRUE;
            }
            
            /* Start video encoding */
            status = (MEDIA_STATUS_CODE) mpeg4_encode_start();
            if (status != MEDIA_STATUS_OK)
            {
                result = vid_get_result_from_media_status(status);
                kal_prompt_trace(MOD_MED, "[VID] goto: record_error, line: %d", __LINE__);                                                                     
                goto record_error;
            }

            /* no error */
            result = MED_RES_OK;
            VID_ENTER_STATE(VID_RECORD);
            vid_set_result(result, __LINE__);            
            VID_SET_EVENT(VID_EVT_RECORD);
            return;

            /* ERROR HANDLING */            
        record_error:

            /* stop isp */                
            exit_mpeg4_encode_process();
            
            if (is_aud_codec_open)
            {
                /* stop audio encoding */                
                Media_Stop();
            }
            
            /* Enable sleep when play fail */
            visual_enable_sleep();

            Media_A2V_HookInterrupt(NULL);
            Media_A2V_SetTimeStamp(0x3FFF);
            Media_A2V_EnableInterrupt(KAL_FALSE, 0);

            if (audio_file_open)
            {
                FSAL_Close(&stFSALProducerAudData);
            }
            
            if (video_file_open)
            {
                FSAL_Close(&mp4_files.MEDIA_META_FILE);
                FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
            }
            
            vid_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(result, __LINE__);            
            VID_SET_EVENT(VID_EVT_RECORD);
            return;
                
        }
        else
        {
            vid_set_result(MED_RES_INVALID_FORMAT, __LINE__);
            VID_SET_EVENT(VID_EVT_RECORD);
            return;            
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_RECORD);
        return;        
    }

    /* shall not enter here */
    ASSERT(0);

}


/*****************************************************************************
 * FUNCTION
 *  vid_file_merge_req_hdlr
 * DESCRIPTION
 *  Handle video file merge request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_file_merge_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_file_merge_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_MERGE_REQ_HDLR);      
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_file_merge_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_IDLE))
    {
        /* disable sleep */
        visual_disable_sleep();
        
        /* send file merge message to Media-v task */
        vid_send_visual_file_merge_req((kal_uint8)MED_MODE_FILE);

        VID_ENTER_STATE(VID_FILE_MERGE);
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_FILE_MERGE);        
        return;
    }
    else
    {
        ASSERT(vid_context_p->state == VID_IDLE);
    }

}



/*****************************************************************************
 * FUNCTION
 *  vid_set_overlay_palette_req_hdlr
 * DESCRIPTION
 *  Set overlay palette request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_overlay_palette_req_hdlr(ilm_struct *ilm_ptr)
{
#if MT6228_SERIES
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_set_overlay_palette_req_struct *msg_p =
        (media_cam_set_overlay_palette_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_OVERLAY_PALETTER_REQ_HDLR);      
    
    set_overlay_palette(msg_p->palette_size, msg_p->palette_addr);
#endif /* MT6228_SERIES */ 
    VID_SET_EVENT(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_clean_temp_files
 * DESCRIPTION
 *  Clean temp files after file merge failed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clean_temp_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 len;
    kal_int32 result;
    kal_uint32 init_file_size;
    kal_int32 FSErrorCode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLEAN_TMP_FILES);      
        
    FS_CheckFile(VID_INIT_FILE);
    fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_READ_ONLY);
    if (fd >= 0)
    {
        FSErrorCode = FS_GetFileSize(fd, &init_file_size);

        if ((init_file_size > 0) && (FSErrorCode >= 0))
        {
            kal_wchar flag;

            result = FS_Read(fd, &flag, 1 * ENCODE_BYTE, &len);
            if (flag == L'Y')
            {
                vid_context_p->use_pseudo_merge = KAL_TRUE;
            }
            else
            {
                vid_context_p->use_pseudo_merge = KAL_FALSE;
            }
            VID_VALUE_TRACE(vid_context_p->use_pseudo_merge, flag, __LINE__);
            result = FS_Read(fd, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE, &len);
        }
        FS_Close(fd);
    }
    FS_Rename((kal_wchar*) VID_INIT_FILE, (kal_wchar*) VID_DUMMY_INIT_FILE);
    FS_Delete((kal_wchar*) VID_INIT_FILE);

    if (kal_wstrlen(vid_context_p->storing_path) < 3)
    {
        return;
    }

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_META_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_REAL_META_FILE);
    FS_Delete(vid_context_p->storing_path);
}


/*****************************************************************************
 * FUNCTION
 *  vid_pause_req_hdlr
 * DESCRIPTION
 *  Handle video pause request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_pause_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PAUSE_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    req_p = (media_vid_pause_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_RECORD))
    {
        if (req_p->stop_preview)
        {
            /* stop camera update */
            exit_mpeg4_encode_process();
            vid_context_p->is_preview_stopped = KAL_TRUE;
        }
        else
        {   /* pause camera update - still previewing */
            mpeg4_encode_pause();
            vid_context_p->is_preview_stopped = KAL_FALSE;            
        }
        
        video_encode_drv_pause();
        
        /* stop video encoding */
        video_enc_close();
        
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
        Media_Stop();
        
    #ifdef __MED_AUD_TIME_STRETCH__
        aud_stretch_close();
    #endif 
    
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);

        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_RECORD_PAUSED);
    }
    else if (VID_IN_STATE(VID_RECORD_FINISH))
    {
        /* stop isp */
        mpeg4_encode_pause();
        
        /* stop video encoding */
        video_enc_close();
        
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
        Media_Stop();
        
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);

        VID_ENTER_STATE(VID_RECORD_PAUSED);
    }
    else
    {
        /* Change to OK in case that the record finish ind is still in MMI's queue,
           There will be a unexpected error popup screen */
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_PAUSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_resume_req_hdlr
 * DESCRIPTION
 *  Handle video resume request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_resume_req_struct *req_p;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RESUME_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_resume_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE)
        {
            MEDIA_STATUS_CODE status = MEDIA_STATUS_OK;
            Media_Status aud_status;

            /* disable sleep when playing */
            visual_disable_sleep();

            Media_A2V_HookInterrupt(NULL);
            Media_A2V_SetTimeStamp(0x3FFF);
            Media_A2V_EnableInterrupt(KAL_TRUE, 0);

            /* reset this flag for audio recording callback */
            aud_context_p->processing_data = KAL_FALSE;
            
            /* Encode start */
            /* Start audio encoding */
            Media_A2V_SetInterruptCount(video_enc_get_prev_time_stamp());
            if (vid_context_p->record_audio)
            {
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_RECORD); 
                aud_status = Media_Record(MEDIA_FORMAT_AMR, vid_audio_record_callback, (void*)0x03);     /* 0x03 = DSP AMR 12.20 type */                
                aud_debug_print_aud_drv_return(aud_status, __LINE__);                     
            }
            else
            {
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_RECORD); 
                aud_status = Media_Record(MEDIA_FORMAT_AMR, vid_audio_record_callback_dummy, (void*)0x03);     /* 0x03 = DSP AMR 12.20 type */                
                aud_debug_print_aud_drv_return(aud_status, __LINE__);                

            }
            
            if (aud_status == MEDIA_SUCCESS)
            {
                /* Start video encoding */
                if (vid_context_p->is_preview_stopped)
                {
                    MEDIA_STATUS_CODE cam_ret;

                    /* 
                     * preview is stopped when pause - need restart camera,
                     * and do not inin memory 
                     */
                    mp4_encode.init_mem = KAL_FALSE;
                    cam_ret = (MEDIA_STATUS_CODE)mpeg4_encode_process(&mp4_encode);
                    ASSERT(cam_ret == MEDIA_STATUS_OK); 

                    status = (MEDIA_STATUS_CODE)mpeg4_encode_resume();
                }
                else
                {   
                    status = (MEDIA_STATUS_CODE)mpeg4_encode_resume();        
                }
        
            }

            
            if (!(aud_status == MEDIA_SUCCESS && status == MEDIA_STATUS_OK))
            {
                /* stop isp */
                exit_mpeg4_encode_process();

                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
                Media_Stop();
                
                vid_close_audio_file_for_record();
                vid_close_visual_file_for_record();
                
                if (aud_status == MEDIA_SUCCESS)
                {
                    result = vid_get_result_from_media_status(status);
                }
                else
                {
                    result = (kal_int32)aud_get_res((kal_uint8)aud_status);
                }
                vid_release_memory();
                VID_ENTER_STATE(VID_IDLE);
            }
            else
            {
                /* Send message to sync state of media-v */
                vid_send_visual_record_req(NULL);
                result = MED_RES_OK;
                VID_ENTER_STATE(VID_RECORD);
            }

            vid_set_result(result, __LINE__);
        }
        else
        {
            vid_set_result(MED_RES_INVALID_FORMAT, __LINE__);
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

    VID_SET_EVENT(VID_EVT_RESUME);
}




/*****************************************************************************
 * FUNCTION
 *  vid_visual_record_cnf_hdlr
 * DESCRIPTION
 *  Handle visual record confirm message from media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_record_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_RECORD_CNF_HDLR);      
}


/*****************************************************************************
 * FUNCTION
 *  vid_dump_data_to_file
 * DESCRIPTION
 *  Dump record data to file when paused
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 vid_dump_record_data_to_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 residual_size;
    kal_uint32 increase_size;
    MEDIA_STATUS_CODE status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for debugging */
    vid_context_p->current_time = video_enc_get_current_time();
    kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, vid_context_p->current_time, __LINE__);

    /* Dump visual data to file */
    residual_size = vid_file_visual_residual_size();
    status = video_enc_buffer_dump_to_file(residual_size, &increase_size);
    
    /* tracking video file size */
    if (status != MEDIA_STATUS_OK)
    {
        VID_RETURN(vid_get_result_from_media_status(status));
    }
    
    vid_context_p->file_size_info.video_bitstream_size += increase_size;
    vid_context_p->file_size_info.video_rm_size 
        = video_evaluate_real_meta_file_size(vid_context_p->file_size_info.short_header_mode);
    
    vid_context_p->file_size = vid_get_current_file_size();
    
    if (vid_context_p->file_size >= vid_context_p->file_size_info.file_size_limit)
    {
        if (vid_context_p->file_size_limit > vid_context_p->file_size_info.file_size_limit ||
            vid_context_p->file_size_limit == 0)
        {
            VID_RETURN(MED_RES_DISC_FULL);
        }
        else
        {
            VID_RETURN(MED_RES_END_OF_FILE);
        }
    }
    
    /* Dump visual meta data to file */
    residual_size = vid_file_meta_residual_size();
    status = meta_enc_buffer_store_file(residual_size, &increase_size);
    
    /* tracking video file size */
    vid_context_p->file_size = vid_get_current_file_size();
    
    if (status != MEDIA_STATUS_OK)
    {
        VID_RETURN(vid_get_result_from_media_status(status));
    }
    
    vid_context_p->file_size_info.video_meta_size += increase_size;
    vid_context_p->file_size_info.video_rm_size = video_evaluate_real_meta_file_size(vid_context_p->file_size_info.short_header_mode);
    vid_context_p->file_size = vid_get_current_file_size();
    
    if (vid_context_p->file_size >= vid_context_p->file_size_info.file_size_limit)
    {
        if (vid_context_p->file_size_limit > vid_context_p->file_size_info.file_size_limit ||
            vid_context_p->file_size_limit == 0)
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_END_OF_FILE;
        }
    }

    /* Dump audio data to file */
    if (vid_context_p->record_audio)
    {
        kal_uint16 *pwBuf;
        kal_uint32 uBufLen;
        FSAL_Status eFSALRet;

        Media_GetReadBuffer(&pwBuf, &uBufLen);
        if (uBufLen > 0)
        {
            eFSALRet = FSAL_Write(&stFSALProducerAudData, (kal_uint8*) pwBuf, uBufLen * 2);
            if (eFSALRet != FSAL_OK)
            {
                VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                VID_RETURN(MED_RES_FSAL_ERROR);
            }
            
            Media_ReadDataDone(uBufLen);
            
            /* read buffer again, in case at the ring buffer boundary */
            Media_GetReadBuffer(&pwBuf, &uBufLen);
            
            if (uBufLen > 0)
            {
                eFSALRet = FSAL_Write(&stFSALProducerAudData, (kal_uint8*) pwBuf, uBufLen * 2);
                if (eFSALRet != FSAL_OK)
                {
                    VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
                    VID_RETURN(MED_RES_FSAL_ERROR);
                }
                
                Media_ReadDataDone(uBufLen);
                vid_context_p->file_size_info.audio_bitstream_size += uBufLen * 2;

                vid_context_p->current_time = video_enc_get_current_time();
                vid_context_p->file_size_info.audio_rm_size = vid_evaluate_audio_real_meta_file_size(vid_context_p->current_time);
                vid_context_p->file_size_info.audio_meta_size = vid_evaluate_audio_meta_file_size(vid_context_p->current_time);
                
                if (vid_context_p->file_size >= vid_context_p->file_size_info.file_size_limit)
                {
                    if (vid_context_p->file_size_limit > vid_context_p->file_size_info.file_size_limit ||
                        vid_context_p->file_size_limit == 0)
                    {
                        VID_RETURN(MED_RES_DISC_FULL);
                    }
                    else
                    {
                        VID_RETURN(MED_RES_END_OF_FILE);
                    }
                }
            }
        }

    }

    VID_RETURN(MED_RES_OK);

}



/*****************************************************************************
 * FUNCTION
 *  vid_update_blt_pause_req_hdlr
 * DESCRIPTION
 *  Pause for update video blt parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_blt_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_pause_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_PAUSE_REQ_HDLR);     

    req_p = (media_vid_update_blt_pause_req_struct*)ilm_ptr->local_para_ptr;
    
    if (VID_IN_STATE(VID_RECORD))
    {
        /* stop camera and video encoder */
        exit_mpeg4_encode_process();
        video_encode_drv_pause();
        video_enc_close();

        if (vid_dump_record_data_to_file() != MED_RES_OK)
        {
            vid_close_visual_file_for_record();

            /* stop the audio record process */
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);                
            Media_Stop();
            
            /* Disable AV sync */
            Media_A2V_EnableInterrupt(KAL_FALSE, 0);
            VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            
            if (vid_context_p->record_audio)
            {
                vid_close_audio_file_for_record();
            }

            vid_release_memory();
            visual_enable_sleep();

            VID_ENTER_STATE(VID_IDLE);              
            vid_set_result(MED_RES_FAIL, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);        
            return;            
        }

        /* no error happened */
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
        
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        /* stop camear */
        exit_mpeg4_encode_process();

        /* no error happened */
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
        
    }
    else if (VID_IN_STATE(VID_PREVIEW))
    {
        /* stop camear */
        exit_mpeg4_encode_process();

        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);
        return; 
    }
    else
    {
        /* calling in wrong state */
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);
    }    

}



/*****************************************************************************
 * FUNCTION
 *  vid_update_blt_resume_req_hdlr
 * DESCRIPTION
 *  Resume for update video blt parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_blt_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_resume_req_struct *req_p;
    MEDIA_STATUS_CODE status = MEDIA_STATUS_OK;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_RESUME_REQ_HDLR);     

    req_p = (media_vid_update_blt_resume_req_struct*)ilm_ptr->local_para_ptr;
    
    /* update value */
    mp4_encode.image_target_width = req_p->preview_width;
    mp4_encode.image_target_height = req_p->preview_height;
    mp4_encode.lcd_id = req_p->lcd_id;
    mp4_encode.lcm_start_x = req_p->lcd_start_x;
    mp4_encode.lcm_start_y = req_p->lcd_start_y;
    mp4_encode.lcm_end_x = req_p->lcd_end_x;
    mp4_encode.lcm_end_y = req_p->lcd_end_y;
    mp4_encode.roi_offset_x = req_p->roi_offset_x;
    mp4_encode.roi_offset_y = req_p->roi_offset_y;
    mp4_encode.update_layer = req_p->update_layer;
    mp4_encode.hw_update_layer = req_p->hw_update_layer;
    mp4_encode.lcd_update = req_p->lcd_update;

    mp4_encode.frame_buffer_address = (kal_uint32) req_p->image_buffer_p;
    mp4_encode.frame_buffer_size = req_p->image_buffer_size;
    mp4_encode.mpeg4_offset_x = req_p->preview_offset_x;
    mp4_encode.mpeg4_offset_y = req_p->preview_offset_y;
    mp4_encode.rotate_value = (kal_uint8) req_p->lcd_rotate;

#if MT6228_SERIES

#ifdef __MED_TVO_MOD__
    mp4_encode.tv_output = req_p->tv_output;
    mp4_encode.tv_output_width = req_p->tv_output_width;
    mp4_encode.tv_output_height = req_p->tv_output_height;
    mp4_encode.tv_output_offset_x = req_p->tv_output_offset_x;
    mp4_encode.tv_output_offset_y = req_p->tv_output_offset_y;
    mp4_encode.tv_output_buffer1_address = req_p->tv_output_buffer1_address;
    mp4_encode.tv_output_buffer2_address = req_p->tv_output_buffer2_address;
    mp4_encode.tv_output_buffer_size = req_p->tv_output_buffer_size;
#endif /* __MED_TVO_MOD__ */ 

    mp4_encode.roi_background_color = req_p->roi_background_color;
#endif /* MT6228_SERIES */ 

    result = MED_RES_OK;

    if (VID_IN_STATE(VID_RECORD))
    {
        /* re-start camera and video encoder */
        mp4_encode.init_mem = KAL_FALSE;
        status = (MEDIA_STATUS_CODE)mpeg4_encode_process(&mp4_encode);
        
        if (status != MEDIA_STATUS_OK)
        {
            result = vid_get_result_from_media_status(status);
        }      

        if (result != MED_RES_OK)
        {

            vid_close_visual_file_for_record();
        
            if (vid_context_p->record_audio)
            {
                vid_close_audio_file_for_record();
            }
            
            vid_release_memory();
            visual_enable_sleep();

            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);            
            return;
        }

        status = (MEDIA_STATUS_CODE)mpeg4_encode_resume();
        
        if (status != MEDIA_STATUS_OK)
        {
            result = vid_get_result_from_media_status(status);
        }      

        if (result != MED_RES_OK)
        {
            exit_mpeg4_encode_process();            
            
            vid_close_visual_file_for_record();
        
            if (vid_context_p->record_audio)
            {
                vid_close_audio_file_for_record();
            }
            
            vid_release_memory();
            visual_enable_sleep();
            
            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);            
            return;
        }

        /* no error happened */
        vid_set_result(result, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
        
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        /* re-start camera, but do not init related buffer since we might resume recording*/
        mp4_encode.init_mem = KAL_FALSE;
        status = (MEDIA_STATUS_CODE)mpeg4_encode_process(&mp4_encode);
        
        if (status != MEDIA_STATUS_OK)
        {
            result = vid_get_result_from_media_status(status);
        }      

        if (result != MED_RES_OK)
        {
            vid_close_visual_file_for_record();
        
            if (vid_context_p->record_audio)
            {
                vid_close_audio_file_for_record();
            }
            
            vid_release_memory();
            visual_enable_sleep();
            
            VID_ENTER_STATE(VID_IDLE);        
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);            
            return;
        }

        /* no error happened */
        vid_set_result(result, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
        
    }
    else if (VID_IN_STATE(VID_PREVIEW))
    {
        /* re-start camera */
        mp4_encode.init_mem = KAL_TRUE;
        status = (MEDIA_STATUS_CODE)mpeg4_encode_process(&mp4_encode);

        if (status != MEDIA_STATUS_OK)
        {
            result = vid_get_result_from_media_status(status);
        }      

        if (result != MED_RES_OK)
        {
            vid_release_memory();
            VID_ENTER_STATE(VID_IDLE);
            vid_set_result(result, __LINE__);            
            return;
        }

        vid_set_result(result, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);
        return; 
    }
    else
    {
        /* calling in wrong state */
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_visual_file_merge_cnf_hdlr
 * DESCRIPTION
 *  Handle visual file merge confirm message from media-v task.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_file_merge_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_file_merge_cnf_struct *cnf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_FILE_MERGE_CNF_HDLR);    
    vid_debug_print_cur_state(__LINE__);
    
    cnf_p = (media_visual_file_merge_cnf_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_DELAY_OPEN))
    {
        kal_int32 result;

        /* the file merge process finished, send indication to notify MMI */
        VID_ENTER_STATE(VID_IDLE);
        vid_send_file_merge_done_ind(cnf_p->result);
        /* Then start the delayed video open process */
        result = vid_open_play_file();
        vid_set_result(result, __LINE__);
        VID_SET_EVENT(VID_EVT_OPEN);
        return;
    }
    else if (VID_IN_STATE(VID_RECORD_ABORTING))
    {
        visual_enable_sleep();
        VID_ENTER_STATE(VID_IDLE);
        AUD_SET_EVENT(AUD_EVT_BLOCK);
        return;        
    }
    else if (VID_IN_STATE(VID_FILE_MERGE_STOPPING))
    {
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
        return;        
    }
    else if (VID_IN_STATE(VID_EDITOR_FILE_MERGE))
    {
        visual_enable_sleep();
        VID_ENTER_STATE(VID_IDLE);
        vid_send_edt_encode_merge_done_ind(cnf_p->result);    
        return;        
    }
    else if (VID_IN_STATE(VID_EDITOR_MERGE_STOPPING))
    {
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_BLOCK);
        return;        
    }    
    else
    {
        visual_enable_sleep();
        VID_ENTER_STATE(VID_IDLE);
        vid_send_file_merge_done_ind(cnf_p->result);
        return;        
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_visual_record_finish_ind_hdlr
 * DESCRIPTION
 *  Handle visual record finish indication message from media-v task.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_record_finish_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_finish_ind_struct *ind_p;
    kal_uint32 cluster_size;
    FS_DiskInfo disc_info;
    kal_wchar drive[4] = L" :\\";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_RECORD_FINISH_IND_HDLR);    
    vid_debug_print_cur_state(__LINE__);
    
    ind_p = (media_visual_record_finish_ind_struct*) ilm_ptr->local_para_ptr;

    /* Log the disc info for debugging */
    drive[0] = vid_context_p->storing_path[0];
    FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
    cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

    kal_trace(                                                      
        TRACE_GROUP_4,                                              
        VID_TRC_DISC_FREE_SPACE,                                    
        disc_info.FreeClusters,                                     
        cluster_size,     
        cluster_size * disc_info.FreeClusters,                                                      
        __LINE__); 


    if (VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_FINISH))
    {
        kal_int16 result;

        /* stop video encode */
        video_enc_close();
        /* stop isp */
        exit_mpeg4_encode_process();

        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);         
        Media_Stop();
        
        /* Disable AV sync */
        Media_A2V_EnableInterrupt(KAL_FALSE, 0);
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
        /* close audio file */
        if (vid_context_p->record_audio)
        {
            result = vid_close_audio_file_for_record();
        }

        /* Log the disc info for debugging */
        FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
        cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

        kal_trace(                                                      
            TRACE_GROUP_4,                                              
            VID_TRC_DISC_FREE_SPACE,                                    
            disc_info.FreeClusters,                                     
            cluster_size,     
            cluster_size * disc_info.FreeClusters,                                                      
            __LINE__); 

        /* close visula files */
        result = vid_close_visual_file_for_record();

        /* Log the disc info for debugging */
        FS_GetDiskInfo(drive, &disc_info, FS_DI_BASIC_INFO| FS_DI_FREE_SPACE);
        cluster_size = disc_info.BytesPerSector * disc_info.SectorsPerCluster;

        kal_trace(                                                      
            TRACE_GROUP_4,                                              
            VID_TRC_DISC_FREE_SPACE,                                    
            disc_info.FreeClusters,                                     
            cluster_size,     
            cluster_size * disc_info.FreeClusters,                                                      
            __LINE__); 
        
        /* release video memory */
        vid_release_memory();
        
        /* enable sleep after recording */
        visual_enable_sleep();
        VID_ENTER_STATE(VID_IDLE);
        
        if (ind_p->result == MED_RES_OK || ind_p->result == MED_RES_END_OF_FILE)
        {
            if (vid_context_p->error_code != MED_RES_OK)
            {
                vid_send_record_finish_ind(vid_context_p->error_code);
            }
            else if (vid_context_p->file_size_limit > vid_context_p->file_size_info.file_size_limit ||
                     vid_context_p->file_size_limit == 0)
            {
                vid_send_record_finish_ind(MED_RES_DISC_FULL);
            }
            else
            {
                vid_send_record_finish_ind(MED_RES_END_OF_FILE);
            }
        }
        else
        {
            vid_send_record_finish_ind(ind_p->result);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_check_unfinished_file
 * DESCRIPTION
 *  Check unfinished video recording file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Has unfinished file or not
 *****************************************************************************/
kal_bool vid_check_unfinished_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    FS_HANDLE fd = -1;
    kal_uint32 len;
    kal_int32 result;
    kal_uint32 init_file_size;
    kal_int32 FSErrorCode;
    MEDIA_STATUS_CODE ret = MEDIA_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_UNFINISHED_FILE);    
    
    fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_READ_ONLY);
    if (fd >= 0)
    {
        FSErrorCode = FS_GetFileSize(fd, &init_file_size);
        VID_VALUE_TRACE(FSErrorCode, init_file_size, __LINE__);
        if ((init_file_size > 0) && (FSErrorCode >= 0))
        {
            kal_wchar flag;

            result = FS_Read(fd, &flag, 1 * ENCODE_BYTE, &len);
            if (flag == L'Y')
            {
                vid_context_p->use_pseudo_merge = KAL_TRUE;
            }
            else
            {
                vid_context_p->use_pseudo_merge = KAL_FALSE;
            }
            VID_VALUE_TRACE(vid_context_p->use_pseudo_merge, flag, __LINE__);
            result = FS_Read(fd, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE, &len);
            FS_Close(fd);
            if (len < 6)
            {
                fd = FS_CheckFile(VID_INIT_FILE);
                return KAL_FALSE;
            }

        }
        else
        {
            FS_Close(fd);
            fd = FS_CheckFile(VID_INIT_FILE);
            return KAL_FALSE;
        }
    }
    else
    {
        fd = FS_CheckFile(VID_INIT_FILE);
        return KAL_FALSE;
    }

    if (kal_wstrlen(vid_context_p->storing_path) < 3)
    {
        return KAL_FALSE;
    }
    /* check if visual file exists */
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_FILE);
    fd = FS_CheckFile(vid_context_p->storing_path);
    if ((fd != FS_NO_ERROR) && (fd != FS_FILE_NOT_FOUND))
    {
        vid_clean_temp_files();
        return KAL_FALSE;
    }

    eFSALRet = FSAL_Open(&mp4_files.MEDIA_VIDEO_FILE, (void*)vid_context_p->storing_path, FSAL_APPEND);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        vid_clean_temp_files();
        return KAL_FALSE;
    }
    /* check if visual meta file exists */
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_META_FILE);
    fd = FS_CheckFile(vid_context_p->storing_path);
    if ((fd != FS_NO_ERROR) && (fd != FS_FILE_NOT_FOUND))
    {
        vid_clean_temp_files();
        return KAL_FALSE;
    }
    eFSALRet = FSAL_Open(&mp4_files.MEDIA_META_FILE, (void*)vid_context_p->storing_path, FSAL_APPEND);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        vid_clean_temp_files();
        return KAL_FALSE;
    }

    /* check if visual real meta file exists */
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_REAL_META_FILE);
    fd = FS_CheckFile(vid_context_p->storing_path);
    if ((fd != FS_NO_ERROR) && (fd != FS_FILE_NOT_FOUND))
    {
        vid_clean_temp_files();
        return KAL_FALSE;
    }

    /* check if audio sample data exists */
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
    fd = FS_CheckFile(vid_context_p->storing_path);
    if ((fd != FS_NO_ERROR) && (fd != FS_FILE_NOT_FOUND))
    {
        vid_clean_temp_files();
        return KAL_FALSE;
    }

    /* check if audio file exists */
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_FILE);
    fd = FS_CheckFile(vid_context_p->storing_path);
    if ((fd != FS_NO_ERROR) && (fd != FS_FILE_NOT_FOUND))
    {
        vid_clean_temp_files();
        return KAL_FALSE;
    }

    if (fd == FS_NO_ERROR)
    {
        eFSALRet = FSAL_Open(&stFSALProducerAudData, (void*)vid_context_p->storing_path, FSAL_APPEND);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);

            ret = video_enc_check_meta_file_is_enough(&mp4_files.MEDIA_VIDEO_FILE, &mp4_files.MEDIA_META_FILE, NULL);

            FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
            FSAL_Close(&mp4_files.MEDIA_META_FILE);
        }
        else
        {

            ret = video_enc_check_meta_file_is_enough(
                    &mp4_files.MEDIA_VIDEO_FILE,
                    &mp4_files.MEDIA_META_FILE,
                    &stFSALProducerAudData);

            FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
            FSAL_Close(&mp4_files.MEDIA_META_FILE);
            FSAL_Close(&stFSALProducerAudData);
        }
    }
    else
    {
        /* Audio file does not exists */
        ret = video_enc_check_meta_file_is_enough(&mp4_files.MEDIA_VIDEO_FILE, &mp4_files.MEDIA_META_FILE, NULL);

        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        FSAL_Close(&mp4_files.MEDIA_META_FILE);
    }

    if (ret != MEDIA_STATUS_OK)
    {
        vid_clean_temp_files();
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}






#endif /* defined(__MED_VID_ENC_MOD__) */


#if defined(__MED_VID_PDL_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_check_pdl_file_meta
 * DESCRIPTION
 *  Check progressive download file's meta is enough or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 vid_check_pdl_file_meta(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    kal_uint32 file_size;
    kal_bool has_video_track;
    kal_uint32 vid_dur;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_PDL_FILE_META);

    /* get file size */
    eFSALRet = FSAL_GetFileSize(stFSAL_v_ptr, &file_size);
    
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        VID_RETURN(MED_RES_OPEN_FILE_FAIL);
    }

    eMp4ParserRet = MP4_GetMdatBoxOffset(stMp4Parser_v_ptr, stFSAL_v_ptr, &vid_context_p->meta_size);

    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
        VID_RETURN(MED_RES_OPEN_FILE_FAIL);                
    }

    if (file_size > vid_context_p->meta_size) 
    {
        /* TODO: this can be optimized to called once only */
        eMp4ParserRet = MP4_Parse(stMp4Parser_v_ptr, stFSAL_v_ptr);
        if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);                
        }

        eFSALRet = FSAL_Open_Attach(stFSAL_v_stco_ptr, stFSAL_v_ptr);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);                
        }

        eFSALRet = FSAL_Open_Attach(stFSAL_v_stsz_ptr, stFSAL_v_ptr);
        if (eFSALRet != FSAL_OK)
        {
            VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);                
        }

        if (vid_context_p->media_mode != MED_MODE_ARRAY)
        {                
            FSAL_SetBuffer(stFSAL_v_stco_ptr, VID_MP4_STCO_BUF_SIZE, (kal_uint8*)mp4_vid_stco_buf_ptr);
            FSAL_SetBuffer(stFSAL_v_stsz_ptr, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*)mp4_vid_stsz_buf_ptr);
        }
            
        MP4_SetFSAL_STCO(stMp4Parser_v_ptr, MP4_TRACK_VIDEO, stFSAL_v_stco_ptr);
        MP4_SetFSAL_STSZ(stMp4Parser_v_ptr, MP4_TRACK_VIDEO, stFSAL_v_stsz_ptr);
        MP4_STBL_CacheTablePreprocess(stMp4Parser_v_ptr, mp4_stbl_buf_ptr, VID_MP4_STBL_BUF_SIZE);
       
        MP4_MetaHasVideoTrack(stMp4Parser_v_ptr, &has_video_track);

        /* if has visual track, we need at least 1 frame for video driver to init */
        if (has_video_track)
        {
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, __LINE__);      
            eMp4ParserRet = MP4_Video_GetAvailableDur(stMp4Parser_v_ptr, &vid_dur);
            vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
            kal_trace(TRACE_GROUP_4, VID_TRC_VID_DURATION, vid_dur);         

            if (eMp4ParserRet != MP4_PARSER_OK)
            {
                VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
                VID_RETURN(MED_RES_BUFFER_INSUFFICIENT);              
            }

            if (vid_dur > 0)
            {
                /* pdl file is enough for playing */
                VID_RETURN(MED_RES_OK);  
            }
            else
            {
               VID_RETURN(MED_RES_BUFFER_INSUFFICIENT);
            }
        }
        else
        {
            VID_RETURN(MED_RES_OK);  
        }
     
    }
    else
    {
        VID_RETURN(MED_RES_BUFFER_INSUFFICIENT);
    }


}


/*****************************************************************************
 * FUNCTION
 *  vid_pdl_meta_buffering_hdlr
 * DESCRIPTION
 *  Handler for checking meta buffering.
 * PARAMETERS
 *  arg         [IN]        not used 
 * RETURNS
 *  void
 *****************************************************************************/
void vid_pdl_meta_buffering_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PDL_META_BUFFERING_HDLR);
    vid_debug_print_cur_state(__LINE__);
    
    if (VID_IN_STATE(VID_PDL_META_BUFFERING))
    {
        result = vid_check_pdl_file_meta();

        if (result == MED_RES_OK)
        {   
            /* enough buffer for PDL to open file */
            FSAL_Close(stFSAL_v_ptr);          
            VID_ENTER_STATE(VID_IDLE);
            
            result = vid_open_play_file();
    
            if (result != MED_RES_OK)
            {
                /* open play file failed */
                vid_send_file_ready_ind(result); 
                return;
            }
        }
        else if (result == MED_RES_BUFFER_INSUFFICIENT)
        {
            /* NOT enough buffer for PDL to open, waiting for more... */
            med_start_timer(VID_PDL_BUFFERING_TIMER, 300, vid_pdl_meta_buffering_hdlr, 0);
        }
        else 
        {
            /* other errors */
            FSAL_Close(stFSAL_v_ptr);     
            vid_send_file_ready_ind(result);
        }
    }
    else
    {
        ASSERT(0);
    }
    
}
#endif /* defined(__MED_VID_PDL_MOD__) */


#if defined(__MED_VID_EDT_MOD__)
/*****************************************************************************
 * FUNCTION
 *  vid_edt_set_active_req_hdlr
 * DESCRIPTION
 *  Set active request handler
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_set_active_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    media_vid_edt_set_active_req_struct *msg_p 
        = (media_vid_edt_set_active_req_struct*) ilm_ptr->local_para_ptr;
    
    MEDIA_STATUS_CODE status;
    kal_int32 result;
    MP4DEC_INIT_STRUCT clip_input;

    vid_aud_open_func_ptr openFunc = NULL;
    Media_VM_PCM_Param vpFormat;
    void *param = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_SET_ACTIVE_REQ_HDLR);    
    
    ASSERT(vid_context_p->handle != (kal_int32) &video_data);

    if (msg_p->handle != NULL)
    {
        ASSERT(VID_IN_STATE(VID_IDLE));
    
        for (index = 0; index < VIDEO_EDT_DATA_P_COUNT; index++)
        {
            if (msg_p->handle == (kal_int32) video_data_list_p[index])
            {
                /* hit! */
                vid_context_p->handle = msg_p->handle;
                break;
            }
        }

        /* load video's parameters */
        vid_load_video_working_data_var(vid_context_p->handle);

        /* load this video's working buffer */
        vid_load_video_working_data_buf(vid_context_p->handle);

        /* get working memory */
        /* decode the 1st frame to get image frame dimen */
        vid_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(vid_play_mem[0]);
        vid_context_p->intmem_size = vid_play_mem[0];
        vid_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(vid_play_mem[1]);
        vid_context_p->extmem_size = vid_play_mem[1];
        
        if (vid_context_p->extmem_start_address == NULL)
        {
            ASSERT(0);
        }

        intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
        extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);

        /* The audio format in 3GP/MP4 file */
        switch (vid_context_p->aud_format)
        {
        #ifdef AMR_DECODE    
            case MEDIA_FORMAT_AMR:
        #ifdef AMRWB_DECODE        
            case MEDIA_FORMAT_AMR_WB:
        #endif         
                vpFormat.mediaType = vid_context_p->aud_format;
                vpFormat.vmParam = (kal_uint32)MEDIA_VMP_AS_RINGTONE;
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
                vid_set_result(MED_RES_INVALID_FORMAT, __LINE__);
                VID_SET_EVENT(VID_EVT_BLOCK);                
                return;
        }

        ASSERT(vid_context_p->mhdl_handle == NULL);

        if ((vid_context_p->mhdl_handle = openFunc(vid_audio_play_callback, NULL, param)) == NULL)
        {
            vid_set_result(MED_RES_INVALID_FORMAT, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);    
            return;
        }


    #ifdef __MTK_TARGET__

        clip_input.pstMp4Parser = stMp4Parser_v_ptr;
        clip_input.pstFSAL = stFSAL_v_ptr;
        clip_input.video_dec_callback = NULL;
        clip_input.max_width = vid_context_p->max_width;
        clip_input.max_height = vid_context_p->max_height;
        clip_input.audio_enable = KAL_TRUE;     /* always enable audio */
        status = video_dec_initialize(&clip_input);
        
        if (status != MEDIA_STATUS_OK)
        {
            /* close audio handle */
            if (vid_context_p->mhdl_handle != NULL)
            {
                vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
                vid_context_p->mhdl_handle = NULL;
            }
            
            video_dec_close();
            /* deinit visual memory */
            intmem_deinit();
            extmem_deinit();
            /* release video memory */
            vid_release_memory();
            
            result = vid_get_result_from_media_status(status);
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);
            return;
        }
        
        vid_set_total_time(vid_context_p->total_time, vid_context_p->total_video_time, vid_context_p->total_audio_time);
        vid_set_image_size(vid_context_p->image_width, vid_context_p->image_height);
    #endif /* __MTK_TARGET__ */
        VID_ENTER_STATE(VID_FILE_READY);

        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);            
    }
    else
    {
        ASSERT(VID_IN_STATE(VID_FILE_READY) || VID_IN_STATE(VID_IDLE));
        /* handle == NULL, de-active current video */
        
        /* current handle must be an active handle */
        //ASSERT(vid_context_p->handle != NULL);

    #ifdef __MTK_TARGET__
        vid_clear_video_working_data();

        /* close audio handle */
        if (vid_context_p->mhdl_handle != NULL)
        {
            vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
            vid_context_p->mhdl_handle = NULL;
        }

        /* free memory */
        video_dec_close();

        /* deinit visual memory */
        intmem_deinit();
        extmem_deinit();
        
        /* release video memory */
        vid_release_memory();
    #endif /* __MTK_TARGET__ */

        VID_ENTER_STATE(VID_IDLE); 
       
        vid_set_result(MED_RES_OK, __LINE__);       
        VID_SET_EVENT(VID_EVT_BLOCK);
        return;
     }
}



/*****************************************************************************
 * FUNCTION
 *  vid_edt_open_visual_file_for_encode
 * DESCRIPTION
 *  This function is to open visual files for record.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 vid_edt_open_visual_file_for_encode(void)
{
     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    kal_int32 result;
    FS_HANDLE file_h;
    kal_wchar storing_path[MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_OPEN_VISUAL_FILE_FOR_ENCODE);  
    
    result = MED_RES_OK;
    vid_context_p->edt_is_v_data_file_opened = KAL_FALSE;
    vid_context_p->edt_is_v_meta_file_opened = KAL_FALSE;    
    vid_context_p->edt_is_v_real_meta_file_opened = KAL_FALSE;
    
    /* Open video file */
    kal_mem_cpy(storing_path, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE);
    
    med_remove_file_name(storing_path);
    kal_wstrcat(storing_path, VID_VISUAL_FILE);

    /* Delete if tmp file already exist */
    FS_Delete(storing_path);
    
    if ((file_h = FS_Open(storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        VID_FSAL_ERROR_TRACE(file_h, __LINE__);        
        
        if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
        {
            result = MED_RES_WRITE_PROTECTION;
            goto edt_open_vid_error_out;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto edt_open_vid_error_out;            
        }
    }
    vid_context_p->edt_is_v_data_file_opened = KAL_TRUE;
    
    eFSALRet = FSAL_Open_WithHandle(&mp4_files.MEDIA_VIDEO_FILE, (void*)file_h);

    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);        
        result = MED_RES_OPEN_FILE_FAIL;
        goto edt_open_vid_error_out;            
    }
    
    /* Open meta file */
    med_remove_file_name(storing_path);
    kal_wstrcat(storing_path, VID_VISUAL_META_FILE);

    /* Delete if tmp file already exist */
    FS_Delete(storing_path);
    
    if ((file_h = FS_Open(storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        if (file_h == FS_WRITE_PROTECTION)
        {
            result = MED_RES_WRITE_PROTECTION;
            goto edt_open_vid_error_out;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto edt_open_vid_error_out; 
        }
    }
    
    vid_context_p->edt_is_v_meta_file_opened = KAL_TRUE;
 
    eFSALRet = FSAL_Open_WithHandle(&mp4_files.MEDIA_META_FILE, (void*)file_h);
    
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);        
        result = MED_RES_OPEN_FILE_FAIL;
        goto edt_open_vid_error_out;            
    }

   
    /* Open real meta file */
    med_remove_file_name(storing_path);
    kal_wstrcat(storing_path, VID_VISUAL_REAL_META_FILE);

    /* Delete if tmp file already exist */
    FS_Delete(storing_path);
    
    if ((file_h = FS_Open(storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        if (file_h == FS_WRITE_PROTECTION)
        {
            result = MED_RES_WRITE_PROTECTION;
            goto edt_open_vid_error_out;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto edt_open_vid_error_out; 
        }
    }
    
    vid_context_p->edt_is_v_real_meta_file_opened = KAL_TRUE;
 
    eFSALRet = FSAL_Open_WithHandle(&mp4_files.REAL_META_FILE, (void*)file_h);
    
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);        
        result = MED_RES_OPEN_FILE_FAIL;
        goto edt_open_vid_error_out;            
    }

    VID_RETURN(MED_RES_OK);

    /* error handling */
edt_open_vid_error_out:
    if (vid_context_p->edt_is_v_data_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        vid_context_p->edt_is_v_data_file_opened = KAL_FALSE;
    }

    if (vid_context_p->edt_is_v_meta_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_META_FILE);
        vid_context_p->edt_is_v_meta_file_opened = KAL_FALSE;        
    }

    if (vid_context_p->edt_is_v_real_meta_file_opened)
    {
        FSAL_Close(&mp4_files.REAL_META_FILE);
        vid_context_p->edt_is_v_real_meta_file_opened = KAL_FALSE;        
    }


    VID_RETURN(result);
    
}



/*****************************************************************************
 * FUNCTION
 *  vid_edt_open_audio_file_for_record
 * DESCRIPTION
 *  This function is to open audio file for record.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 vid_edt_open_audio_file_for_encode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    kal_int32 result;
    FS_HANDLE file_h;
    kal_wchar storing_path[MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_OPEN_AUDIO_FILE_FOR_ENCODE);  
    
    result = MED_RES_OK;
    vid_context_p->edt_is_a_data_file_opened = KAL_FALSE;
    vid_context_p->edt_is_a_meta_file_opened = KAL_FALSE;    
    
   /* open aud file */
    kal_mem_cpy(storing_path, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE);    
    med_remove_file_name(storing_path);
    kal_wstrcat(storing_path, VID_AUDIO_FILE);

    /* Delete if tmp file already exist */
    FS_Delete(storing_path);
    
    if ((file_h = FS_Open(storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        VID_FSAL_ERROR_TRACE(file_h, __LINE__);        
        
        if (vid_context_p->file_handle == FS_WRITE_PROTECTION)
        {
            result = MED_RES_WRITE_PROTECTION;
            goto edt_open_aud_error_out;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto edt_open_aud_error_out;            
        }
    }
    vid_context_p->edt_is_a_data_file_opened = KAL_TRUE;
    
    eFSALRet = FSAL_Open_WithHandle(&stFSALProducerAudData, (void*)file_h);

    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);        
        result = MED_RES_OPEN_FILE_FAIL;
        goto edt_open_aud_error_out;            
    }
    
    FSAL_SetBuffer(
        &stFSALProducerAudData, 
        (kal_uint32)sizeof(buffer_enc_audio_tmp), 
        (kal_uint8*)buffer_enc_audio_tmp);


    /* open meta file */
    med_remove_file_name(storing_path);
    kal_wstrcat(storing_path, VID_AUDIO_SAMPLE_FILE);

    /* Delete if tmp file already exist */
    FS_Delete(storing_path);
    
    if ((file_h = FS_Open(storing_path, VID_TEMP_FILE_ATTRIBUTES)) < 0)
    {
        VID_FSAL_ERROR_TRACE(file_h, __LINE__);
        
        if (file_h == FS_WRITE_PROTECTION)
        {
            result = MED_RES_WRITE_PROTECTION;
            goto edt_open_aud_error_out;
        }
        else
        {
            result = MED_RES_OPEN_FILE_FAIL;
            goto edt_open_aud_error_out;            
        }
    }
    
    vid_context_p->edt_is_a_meta_file_opened = KAL_TRUE;
    eFSALRet = FSAL_Open_WithHandle(&stFSALProducerAudMeta, (void*)file_h);
    
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);        
        result = MED_RES_OPEN_FILE_FAIL;
        goto edt_open_aud_error_out;            
    }
    
    FSAL_SetBuffer(
        &stFSALProducerAudMeta,
        (kal_uint32)sizeof(buffer_enc_audio_sample_tmp),
        (kal_uint8*)buffer_enc_audio_sample_tmp);

    VID_RETURN(MED_RES_OK);

    /* error handling */
edt_open_aud_error_out:
    if (vid_context_p->edt_is_a_data_file_opened)
    {
        FSAL_Close(&stFSALProducerAudData);
        vid_context_p->edt_is_a_data_file_opened = KAL_FALSE;
    }

    if (vid_context_p->edt_is_a_meta_file_opened)
    {
        FSAL_Close(&stFSALProducerAudMeta);
        vid_context_p->edt_is_a_meta_file_opened = KAL_FALSE;
    }

    VID_RETURN(result);


}



/*****************************************************************************
 * FUNCTION
 *  vid_edt_encode_start
 * DESCRIPTION
 *  start trasncoding
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vid_edt_encode_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_EDITOR_IMGPATH_STRUCT     image_path_data;
    lcd_frame_update_to_mem_struct  lcd_para;
    lcd_layer_struct                video_layer_data;
    lcd_layer_struct                extra_layer_1_data;    
    lcd_layer_struct                extra_layer_2_data;        
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENCODE_START);      

    /* create image data path */
    image_path_data.lcd_para = &lcd_para;
    image_path_data.hw_update_layer = LCD_LAYER0_ENABLE; /* layer 0 for video */					
    image_path_data.lcd_buffer_address = (kal_uint32)vid_context_p->edt_lcd_buf_ptr;
    image_path_data.effect_cb = NULL;

    /* config lcd info */
    lcd_para.fb_update_mode = LCD_HW_TRIGGER_MODE;
    lcd_para.block_mode = KAL_FALSE;
    lcd_para.dest_block_width = vid_context_p->edt_video_width;
    lcd_para.dest_buffer_address = (kal_uint32)vid_context_p->edt_lcd_buf_ptr;
    lcd_para.dest_buffer_size = vid_context_p->edt_video_width*vid_context_p->edt_video_height*2;

    /* we will place the video at upper left corner (512,512) of ROI coordinate */
    /* !!this will not update to LCM */
    lcd_para.roi_offset_x = 512;			
    lcd_para.roi_offset_y = 512;			
    lcd_para.roi_width = vid_context_p->edt_video_width;				
    lcd_para.roi_height = vid_context_p->edt_video_height;		

    lcd_para.update_layer = LCD_LAYER0_ENABLE;

    if (vid_context_p->edt_extra_layer_1.is_use)
    {
        lcd_para.update_layer |= LCD_LAYER1_ENABLE;
    }

    if (vid_context_p->edt_extra_layer_2.is_use)
    {
        lcd_para.update_layer |= LCD_LAYER2_ENABLE;
    }
   
    lcd_para.hw_update_layer = LCD_LAYER0_ENABLE;
    lcd_para.hw_trigger_src = LCD_HW_TRIGGER_IBW2;
    lcd_para.roi_background_color = 0xffffffff;
    lcd_para.memory_data_format = LCD_WMEM_RGB565;
    
    video_editor_image_path_open(&image_path_data);
         
    /* config layer info */		
    video_layer_data.source_key_enable = KAL_FALSE;		
    video_layer_data.color_palette_enable = KAL_FALSE;	
    video_layer_data.opacity_enable = KAL_FALSE;		
    video_layer_data.source_color_format = LCD_LAYER_SOURCE_COLOR_RGB565;
    video_layer_data.color_palette_select = KAL_FALSE;	
    video_layer_data.rotate_value = LCD_LAYER_ROTATE_NORMAL;
    video_layer_data.x_offset = 512;					    
    video_layer_data.y_offset = 512;
    video_layer_data.row_number = vid_context_p->edt_video_height;  
    video_layer_data.column_number = vid_context_p->edt_video_width;
    video_layer_data.frame_buffer_address = (kal_uint32)vid_context_p->edt_lcd_buf_ptr;
    config_lcd_layer_window(LCD_LAYER0, &video_layer_data);

    if (vid_context_p->edt_extra_layer_1.is_use)
    {
        /* config extra layer 1 */	
        media_vid_edt_layer_struct *layer_p = &vid_context_p->edt_extra_layer_1;
	
        extra_layer_1_data.source_key_enable = layer_p->source_key_enable;
        extra_layer_1_data.source_key = layer_p->source_key;
        extra_layer_1_data.color_palette_enable = KAL_FALSE;
        extra_layer_1_data.opacity_enable = layer_p->opacity_enable;
        extra_layer_1_data.opacity_value= layer_p->opacity_value;
        extra_layer_1_data.source_color_format = LCD_LAYER_SOURCE_COLOR_RGB565;
        extra_layer_1_data.color_palette_select = KAL_FALSE;
        extra_layer_1_data.rotate_value = LCD_LAYER_ROTATE_NORMAL;
        extra_layer_1_data.x_offset = 512 + layer_p->offset_x;					    
        extra_layer_1_data.y_offset = 512 + layer_p->offset_y;					    
        extra_layer_1_data.row_number = layer_p->height;					    
        extra_layer_1_data.column_number = layer_p->width;	    
        extra_layer_1_data.frame_buffer_address = (kal_uint32)layer_p->frame_buffer_address;
        config_lcd_layer_window(LCD_LAYER1, &extra_layer_1_data);	
    }

    if (vid_context_p->edt_extra_layer_2.is_use)
    {
        /* config extra layer 2 */		        
        media_vid_edt_layer_struct *layer_p = &vid_context_p->edt_extra_layer_2;
         
        extra_layer_2_data.source_key_enable = layer_p->source_key_enable;
        extra_layer_2_data.source_key = layer_p->source_key;
        extra_layer_2_data.color_palette_enable = KAL_FALSE;
        extra_layer_2_data.opacity_enable = layer_p->opacity_enable;
        extra_layer_2_data.opacity_value= layer_p->opacity_value;
        extra_layer_2_data.source_color_format = LCD_LAYER_SOURCE_COLOR_RGB565;
        extra_layer_2_data.color_palette_select = KAL_FALSE;
        extra_layer_2_data.rotate_value = LCD_LAYER_ROTATE_NORMAL;
        extra_layer_2_data.x_offset = 512 + layer_p->offset_x;					    
        extra_layer_2_data.y_offset = 512 + layer_p->offset_y;					    
        extra_layer_2_data.row_number = layer_p->height;					    
        extra_layer_2_data.column_number = layer_p->width;	    
        extra_layer_2_data.frame_buffer_address = (kal_uint32)layer_p->frame_buffer_address;
        config_lcd_layer_window(LCD_LAYER2, &extra_layer_2_data);	
    }

    /* start transcode */    
    video_editor_start();

    return MED_RES_OK;

}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_get_error_from_mp4_status
 * DESCRIPTION
 *  mapping the error code from MP4 audio extraction to MED error code.
 * PARAMETERS
 *  mp4_error [in] error code from MP4 extractor
 * RETURNS
 *  MED error code
 *****************************************************************************/
static kal_int32 vid_edt_get_error_from_mp4_status(MP4_Aud_Extr_Status mp4_error)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mp4_error)
    {
        case MP4_AUD_EXTR_DISK_SPACE_NOT_ENOUGH:
            return MED_RES_DISC_FULL;
        case MP4_AUD_EXTR_FILE_WRITE_ERROR:
            return MED_RES_WRITE_PROTECTION;
        default:
            return MED_RES_PARAM_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_append_audio
 * DESCRIPTION
 *  append auio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vid_edt_append_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Aud_Extr_Status ext_ret;
    STMp4Parser *pMp4Parser = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_APPEND_AUDIO);

    if (vid_context_p->edt_is_use_bgm)
    {
    #ifdef __MED_VID_EDT_BGM_SUPPORT__
        pMp4Parser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->parser;
    #else
        pMp4Parser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->parser;
    #endif
    }
    else if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_IMAGE)
    {
        pMp4Parser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->parser;
    }
    else if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_VIDEO)
    {
        pMp4Parser = stMp4Parser_a_ptr;
    }
    else
    {
        ASSERT(0);
    }

    if (vid_context_p->edt_is_first_time_append)
    {
        /* data */
        ext_ret = MP4_ExtrAudio(
                    pMp4Parser, 
                    &stFSALProducerAudData, 
                    vid_edt_audio_avsync.audio_start_frame, 
                    vid_edt_audio_avsync.audio_end_frame);

        if (ext_ret != MP4_AUD_EXTR_OK)
        {
            VID_PARSE_ERROR_TRACE(ext_ret,  __LINE__);
            VID_RETURN(vid_edt_get_error_from_mp4_status(ext_ret));
        }

        /* meta */
        ext_ret = MP4_ExtrAudio_Write_Sample_Data(
                    pMp4Parser, 
                    &stFSALProducerAudMeta, 
                    vid_edt_audio_avsync.audio_start_frame,
                    vid_edt_audio_avsync.audio_end_frame);
        
        if (ext_ret != MP4_AUD_EXTR_OK)
        {
            VID_PARSE_ERROR_TRACE(ext_ret,  __LINE__);
            VID_RETURN(vid_edt_get_error_from_mp4_status(ext_ret));
        }
    }
    else
    {
        ext_ret = MP4_ExtrAudio_Append(
                    pMp4Parser, 
                    &stFSALProducerAudData, 
                    vid_edt_audio_avsync.audio_start_frame, 
                    vid_edt_audio_avsync.audio_end_frame);

        if (ext_ret != MP4_AUD_EXTR_OK)
        {
            VID_PARSE_ERROR_TRACE(ext_ret,  __LINE__);
            VID_RETURN(vid_edt_get_error_from_mp4_status(ext_ret));
        }            

        ext_ret = MP4_ExtrAudio_Write_Sample_Data_Append(
                    pMp4Parser, 
                    &stFSALProducerAudMeta, 
                    vid_edt_audio_avsync.audio_start_frame,
                    vid_edt_audio_avsync.audio_end_frame); 

        if (ext_ret != MP4_AUD_EXTR_OK)
        {
            VID_PARSE_ERROR_TRACE(ext_ret,  __LINE__);
            VID_RETURN(vid_edt_get_error_from_mp4_status(ext_ret));
        }                       
    }

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_append_image
 * DESCRIPTION
 *  append image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vid_edt_append_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_EDITOR_OPEN_STRUCT        editor_open_data;
    VIDEO_EDITOR_OPEN_NEXT_STRUCT   editor_open_next_data;
    RGB2YUV420_struct               rgb2yuv;
    MEDIA_STATUS_CODE               status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_APPEND_IMAGE);   
    
    if (vid_context_p->edt_is_visaul_drv_opened)
    {
        /* if visual driver is opened, and file changed, we need close it first */
        video_editor_close();  
        vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
        intmem_deinit();
        extmem_deinit();              
    }
    
    /* init memory */
    intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
    extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);

#ifdef __MED_VID_EDT_BGM_SUPPORT__
    if (vid_context_p->edt_is_use_bgm)
    {
        video_enc_set_audioformat(MEDIA_FORMAT_AMR);
    }
#endif /* __MED_VID_EDT_BGM_SUPPORT__ */

    /* convert image from RGB565 to YUV420 */
    rgb2yuv.src_address = (kal_uint32)vid_context_p->edt_img_buf_rgb_ptr;
    rgb2yuv.src_width = vid_context_p->edt_video_width;
    rgb2yuv.src_height = vid_context_p->edt_video_height;
    rgb2yuv.type = IBR1_TYPE_RGB565;
    rgb2yuv.order = IBR1_ORDER_RGB888; 
    rgb2yuv.tar_address = (kal_uint32)vid_context_p->edt_img_buf_yuv_ptr;

    open_image_data_path(SCENARIO_RGB2YUV420_ID);
    config_RGB2YUV420_data_path(SCENARIO_RGB2YUV420_ID, &rgb2yuv);
    close_image_data_path(SCENARIO_RGB2YUV420_ID);
    
    if (vid_context_p->edt_is_first_time_append)
    {
        /* fill editor's data */
        editor_open_data.image_yuv420_buffer = vid_context_p->edt_img_buf_yuv_ptr;
        editor_open_data.image_yuv420_width = vid_context_p->edt_video_width;
        editor_open_data.image_yuv420_height = vid_context_p->edt_video_height;
        editor_open_data.short_header = 0;        
        editor_open_data.bit_rate = 128000;
        editor_open_data.encode_frame_width = vid_context_p->edt_video_width;
        editor_open_data.encode_frame_height =vid_context_p->edt_video_height;        
        editor_open_data.pstVIDParser = NULL;
        editor_open_data.pstVIDFSAL = NULL;
    #ifdef __MED_VID_EDT_BGM_SUPPORT__        
        if (vid_context_p->edt_is_use_bgm)
        {    
            editor_open_data.pstAUDParser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->parser;
            editor_open_data.pstAUDFSAL = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->stFSAL_mp4;
            editor_open_data.audio_start_time = vid_context_p->edt_bgm_start_time;
        }
        else
    #endif /* __MED_VID_EDT_BGM_SUPPORT__ */
        {
            editor_open_data.pstAUDParser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->parser;  
            editor_open_data.pstAUDFSAL = &video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->stFSAL_mp4;
            editor_open_data.audio_start_time = 0;
        }

        editor_open_data.av_duration = vid_context_p->edt_end_time - vid_context_p->edt_start_time;
        editor_open_data.need_avsync = 0;
        editor_open_data.call_back = vid_edt_send_encode_event_ind; 

        status = video_editor_open(&editor_open_data, &vid_edt_audio_avsync, NULL);
        
        if (status != MEDIA_STATUS_OK)
        {
            video_editor_close();
            vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
            intmem_deinit();
            extmem_deinit();
        
            VID_VIS_ERROR_TRACE(status, __LINE__);
            VID_RETURN(vid_get_result_from_media_status(status));
        }        
    }
    else
    {
        /* fill editor's data */
        editor_open_next_data.image_yuv420_buffer = vid_context_p->edt_img_buf_yuv_ptr;
        editor_open_next_data.image_yuv420_width = vid_context_p->edt_video_width;
        editor_open_next_data.image_yuv420_height = vid_context_p->edt_video_height;
        editor_open_next_data.pstVIDParser = NULL;
        editor_open_next_data.pstVIDFSAL = NULL;
        editor_open_next_data.is_new_video = KAL_TRUE;
    #ifdef __MED_VID_EDT_BGM_SUPPORT__        
        if (vid_context_p->edt_is_use_bgm)
        {    
            editor_open_next_data.pstAUDParser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->parser;
            editor_open_next_data.pstAUDFSAL = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->stFSAL_mp4;
            editor_open_next_data.audio_start_time = vid_context_p->edt_bgm_start_time;
        }
        else
    #endif /* __MED_VID_EDT_BGM_SUPPORT__ */
        {
            editor_open_next_data.pstAUDParser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->parser;  
            editor_open_next_data.pstAUDFSAL = &video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->stFSAL_mp4;
            editor_open_next_data.audio_start_time = 0;
        }    


        editor_open_next_data.av_duration = vid_context_p->edt_end_time - vid_context_p->edt_start_time;
        editor_open_next_data.need_avsync = 0;
        editor_open_next_data.call_back = vid_edt_send_encode_event_ind; 

        status = video_editor_open_next(&editor_open_next_data, &vid_edt_audio_avsync, NULL);

        if (status != MEDIA_STATUS_OK)
        {
            video_editor_close();
            vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
            intmem_deinit();
            extmem_deinit();
        
            VID_VIS_ERROR_TRACE(status, __LINE__);
            VID_RETURN(vid_get_result_from_media_status(status));
        }        
    }

    /* start encode */
    vid_edt_encode_start();

    return MED_RES_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_append_video
 * DESCRIPTION
 *  append image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 vid_edt_append_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VIDEO_EDITOR_OPEN_STRUCT        editor_open_data;
    VIDEO_EDITOR_OPEN_NEXT_STRUCT   editor_open_next_data;
    kal_uint32                      seek_frame;
    MEDIA_STATUS_CODE               status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_APPEND_VIDEO);   
    
#ifdef __MED_VID_EDT_BGM_SUPPORT__
    if (vid_context_p->edt_is_use_bgm)
    {
        /* TODO: init bgm's audio */
        video_enc_set_audioformat(MEDIA_FORMAT_AMR);
    }
#endif /* __MED_VID_EDT_BGM_SUPPORT__ */

    if (vid_context_p->edt_is_first_time_append)
    {
        /* init memory */
        intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
        extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);

        
        /* fill editor's data */
        editor_open_data.short_header = 0;
        editor_open_data.bit_rate = 128000;
        editor_open_data.encode_frame_width = vid_context_p->edt_video_width;
        editor_open_data.encode_frame_height =vid_context_p->edt_video_height;
        editor_open_data.image_yuv420_buffer = NULL;
        editor_open_data.pstVIDParser = stMp4Parser_v_ptr;
        editor_open_data.pstVIDFSAL = stFSAL_v_ptr;
        editor_open_data.video_start_time = vid_context_p->edt_start_time;
    #ifdef __MED_VID_EDT_BGM_SUPPORT__        
        if (vid_context_p->edt_is_use_bgm)
        {
            editor_open_data.pstAUDParser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->parser;
            editor_open_data.pstAUDFSAL = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->stFSAL_mp4;
            editor_open_data.audio_start_time = vid_context_p->edt_bgm_start_time;
        }
        else
    #endif /* __MED_VID_EDT_BGM_SUPPORT__ */
        {
            editor_open_data.pstAUDParser = stMp4Parser_a_ptr;  
            editor_open_data.pstAUDFSAL = stFSAL_a_ptr;
            editor_open_data.audio_start_time = vid_context_p->edt_start_time;
        }

        editor_open_data.need_avsync = 1;
        editor_open_data.call_back = vid_edt_send_encode_event_ind;
        editor_open_data.av_duration = vid_context_p->edt_end_time - vid_context_p->edt_start_time;
        editor_open_data.effect_start_time = 0;
        editor_open_data.effect_duration = 0;

        vid_context_p->edt_is_visaul_drv_opened = KAL_TRUE;
        status = video_editor_open(&editor_open_data, &vid_edt_audio_avsync, &seek_frame);


        if (status != MEDIA_STATUS_OK)
        {
            vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
            video_editor_close();
            intmem_deinit();
            extmem_deinit();
            
            VID_VIS_ERROR_TRACE(status, __LINE__);
            VID_RETURN(vid_get_result_from_media_status(status));
        }
    }
    else
    {
        if (vid_context_p->edt_prev_append_video_handle == vid_context_p->edt_video_handle)
        {
            /* same as previosu video, do not init memory */
            editor_open_next_data.is_new_video = KAL_FALSE;
        }
        else
        {
            editor_open_next_data.is_new_video = KAL_TRUE;           
            if (vid_context_p->edt_is_visaul_drv_opened)
            {
                /* if visual driver is opened, and file changed, we need close it first */
                vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                video_editor_close();  
                intmem_deinit();
                extmem_deinit();                
            }
            
            intmem_init((void*)vid_context_p->intmem_start_address, vid_context_p->intmem_size);
            extmem_init((void*)vid_context_p->extmem_start_address, vid_context_p->extmem_size);
        }
        
        /* fill editor's data */
        editor_open_next_data.image_yuv420_buffer = NULL;
        editor_open_next_data.pstVIDParser = stMp4Parser_v_ptr;
        editor_open_next_data.pstVIDFSAL = stFSAL_v_ptr;
        editor_open_next_data.video_start_time = vid_context_p->edt_start_time;
    #ifdef __MED_VID_EDT_BGM_SUPPORT__        
        if (vid_context_p->edt_is_use_bgm)
        {
            editor_open_next_data.pstAUDParser = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->parser;
            editor_open_next_data.pstAUDFSAL = &video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->stFSAL_mp4;
            editor_open_next_data.audio_start_time = vid_context_p->edt_bgm_start_time;
        }
        else
    #endif /* __MED_VID_EDT_BGM_SUPPORT__ */
        {
            editor_open_next_data.pstAUDParser = stMp4Parser_a_ptr;  
            editor_open_next_data.pstAUDFSAL = stFSAL_a_ptr;
            editor_open_next_data.audio_start_time = vid_context_p->edt_start_time;
        }    
    
        editor_open_next_data.need_avsync = 1;
        editor_open_next_data.call_back = vid_edt_send_encode_event_ind;
        editor_open_next_data.av_duration = vid_context_p->edt_end_time - vid_context_p->edt_start_time;
        editor_open_next_data.effect_start_time = 0;
        editor_open_next_data.effect_duration = 0;

        vid_context_p->edt_is_visaul_drv_opened = KAL_TRUE;
        status = video_editor_open_next(&editor_open_next_data, &vid_edt_audio_avsync, &seek_frame);

        if (status != MEDIA_STATUS_OK)
        {
            vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
            video_editor_close();  
            intmem_deinit();
            extmem_deinit();
            
            VID_VIS_ERROR_TRACE(status, __LINE__);
            VID_RETURN(vid_get_result_from_media_status(status));
        }
        
    }

    vid_context_p->edt_prev_append_video_handle = vid_context_p->edt_video_handle;    
    status = video_editor_seek_by_frame(seek_frame, vid_edt_send_encode_event_ind);
    
    if (status != MEDIA_STATUS_OK)
    {
        vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
        video_editor_close();         
        intmem_deinit();
        extmem_deinit();
    
        VID_VIS_ERROR_TRACE(status, __LINE__);
        VID_RETURN(vid_get_result_from_media_status(status));
    }
        
    return MED_RES_OK;

}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_free_resource
 * DESCRIPTION
 *  free video ediotr encode related resource
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void vid_edt_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_FREE_RESOURCE);   


    /* close dest file */
    if (vid_context_p->edt_is_v_data_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        vid_context_p->edt_is_v_data_file_opened = KAL_FALSE;
    }

    if (vid_context_p->edt_is_v_meta_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_META_FILE);    
        vid_context_p->edt_is_v_meta_file_opened = KAL_FALSE;        
    }

    if (vid_context_p->edt_is_v_real_meta_file_opened)
    {
        FSAL_Close(&mp4_files.REAL_META_FILE);    
        vid_context_p->edt_is_v_real_meta_file_opened = KAL_FALSE;        
    }    

    if (vid_context_p->edt_is_a_data_file_opened)
    {
        FSAL_Close(&stFSALProducerAudData);
        vid_context_p->edt_is_a_data_file_opened = KAL_FALSE;        
    }

    if (vid_context_p->edt_is_a_meta_file_opened)
    {
        FSAL_Close(&stFSALProducerAudMeta);
        vid_context_p->edt_is_a_meta_file_opened = KAL_FALSE;        
    }
    
    /* free memory */
    med_free_ext_mem((void**)&vid_context_p->edt_lcd_buf_ptr);    
    med_free_ext_mem((void**)&vid_context_p->edt_img_buf_yuv_ptr);
    med_free_int_mem((void**)&vid_context_p->intmem_start_address); /* internal */
    med_free_ext_mem((void**)&vid_context_p->extmem_start_address);
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_enc_open_req_hdlr
 * DESCRIPTION
 *  Video editor encode open request hdlr
 * PARAMETERS
 *  ilm_ptr     [IN]    message data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_enc_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_open_req_struct *msg_p 
        = (media_vid_edt_enc_open_req_struct*) ilm_ptr->local_para_ptr;
   
    kal_int32 ret;
    kal_int32 memory_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENC_OPEN_REQ_HDLR);

    vid_context_p->edt_video_width = msg_p->encode_video_width;
    vid_context_p->edt_video_height = msg_p->encode_video_height;    
    kal_mem_cpy(vid_context_p->storing_path, msg_p->filename, MAX_FILE_NAME_LEN * ENCODE_BYTE);

    vid_context_p->edt_is_first_time_append = KAL_TRUE;
    vid_context_p->edt_prev_append_video_handle = NULL;

    /* allocate memory */
    vid_context_p->intmem_start_address = (kal_uint32)med_alloc_int_mem(MAX_VID_EDT_INT_MEM_SIZE);
    vid_context_p->intmem_size = MAX_VID_EDT_INT_MEM_SIZE;
    ASSERT(vid_context_p->intmem_start_address != NULL);
    
    vid_context_p->extmem_start_address = (kal_uint32)med_alloc_ext_mem(MAX_VID_EDT_EXT_MEM_SIZE);
    vid_context_p->extmem_size = MAX_VID_EDT_EXT_MEM_SIZE;
    ASSERT(vid_context_p->extmem_start_address != NULL);

    /* allocate image convert (RGB565->YUV420) buffer */
    /* TODO: YUV420 memory size???? */
    memory_size = vid_context_p->edt_video_width * vid_context_p->edt_video_height * 2;
    vid_context_p->edt_img_buf_yuv_ptr = (kal_uint8*)med_alloc_ext_mem(memory_size);
    ASSERT(vid_context_p->edt_img_buf_yuv_ptr != NULL);

    /* allocate working memory (fb update to mem) for merge layers to video (RGB565) */
    memory_size = vid_context_p->edt_video_width * vid_context_p->edt_video_height * 2;
    vid_context_p->edt_lcd_buf_ptr = (kal_uint8*)med_alloc_ext_mem(memory_size);
    ASSERT(vid_context_p->edt_lcd_buf_ptr != NULL);

    /* open FSAL of destination file */
    ret = vid_edt_open_visual_file_for_encode();
    
    if (ret != MED_RES_OK)
    {
        vid_edt_free_resource();
        vid_set_result(ret, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
    }
    
    ret = vid_edt_open_audio_file_for_encode();
        
    if (ret != MED_RES_OK)
    {
        vid_edt_free_resource();
        vid_set_result(ret, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
    }

    vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;

    /* non error happened */
    vid_set_result(MED_RES_OK, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_enc_close_req_hdlr
 * DESCRIPTION
 *  Video editor encode close request hdlr
 * PARAMETERS
 *  ilm_ptr     [IN]    message data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_enc_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    media_vid_edt_enc_close_req_struct *msg_p 
//        = (media_vid_edt_enc_close_req_struct*)ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENC_CLOSE_REQ_HDLR);

    /* if visual driver is opened, and file changed, we need close it first */
    if (vid_context_p->edt_is_visaul_drv_opened == KAL_TRUE)
    {
        video_editor_close();  
        vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
        intmem_deinit();
        extmem_deinit();                     
    }

    /* close opened files */
    if (vid_context_p->edt_is_v_data_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_VIDEO_FILE);
        vid_context_p->edt_is_v_data_file_opened = KAL_FALSE;
    }
    if (vid_context_p->edt_is_v_meta_file_opened)
    {
        FSAL_Close(&mp4_files.MEDIA_META_FILE);    
        vid_context_p->edt_is_v_meta_file_opened = KAL_FALSE;        
    }
    if (vid_context_p->edt_is_v_real_meta_file_opened)
    {
        FSAL_Close(&mp4_files.REAL_META_FILE);    
        vid_context_p->edt_is_v_real_meta_file_opened = KAL_FALSE;        
    }    
    if (vid_context_p->edt_is_a_data_file_opened)
    {
        FSAL_Close(&stFSALProducerAudData);
        vid_context_p->edt_is_a_data_file_opened = KAL_FALSE;        
    }
    if (vid_context_p->edt_is_a_meta_file_opened)
    {
        FSAL_Close(&stFSALProducerAudMeta);
        vid_context_p->edt_is_a_meta_file_opened = KAL_FALSE;        
    }

    /* delete all tmp files */
    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_AUDIO_SAMPLE_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_META_FILE);
    FS_Delete(vid_context_p->storing_path);

    med_remove_file_name(vid_context_p->storing_path);
    kal_wstrcat(vid_context_p->storing_path, VID_VISUAL_REAL_META_FILE);
    FS_Delete(vid_context_p->storing_path);

    vid_edt_free_resource();

    vid_set_result(MED_RES_OK, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_enc_append_req_hdlr
 * DESCRIPTION
 *  video editor encode append request hdlr
 * PARAMETERS
 *  ilm_ptr     [IN]    message data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_enc_append_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_append_req_struct *msg_p 
        = (media_vid_edt_enc_append_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENC_APPEND_REQ_HDLR);

    vid_context_p->src_mod = MOD_MMI;   /* currently only for MMI */    
    vid_context_p->edt_resource_type = msg_p->resource_type;
    vid_context_p->edt_is_appending = KAL_TRUE;

    if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_IMAGE)
    {
        vid_context_p->edt_img_buf_rgb_ptr = msg_p->img_buf_ptr;
        vid_context_p->edt_img_buf_size = msg_p->img_buf_size;        
    }
    else if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_VIDEO)
    {
        vid_context_p->edt_video_handle = msg_p->video_handle;
    }
    else
    {
        ASSERT(0);
    }

    memcpy(
        (void*)&vid_context_p->edt_extra_layer_1,  
        (void*)&msg_p->extra_layer_1, 
        sizeof(media_vid_edt_layer_struct));

    memcpy(
        (void*)&vid_context_p->edt_extra_layer_2,  
        (void*)&msg_p->extra_layer_2, 
        sizeof(media_vid_edt_layer_struct));

    vid_context_p->edt_start_time = msg_p->start_time;
    vid_context_p->edt_end_time = msg_p->end_time;    
    vid_context_p->edt_is_use_bgm = msg_p->is_use_bgm;
    vid_context_p->edt_bgm_start_time = msg_p->bgm_start_time;    
    vid_context_p->edt_bgm_end_time = msg_p->bgm_end_time;  


    if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_IMAGE)
    {
        ret = vid_edt_append_image();
        
        if (ret != MED_RES_OK)
        {
            /* has error, unlock event */
            vid_set_result(ret, __LINE__);         
            vid_context_p->edt_is_appending = KAL_FALSE;
            VID_SET_EVENT(VID_EVT_BLOCK);  
        }        
    }
    else if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_VIDEO)
    {
        /* load video's parameters and working buffer */
        vid_load_video_working_data_var(vid_context_p->edt_video_handle);
        vid_load_video_working_data_buf(vid_context_p->edt_video_handle);        
        ret = vid_edt_append_video();

        if (ret != MED_RES_OK)
        {
            /* has error, unlock event */
            vid_set_result(ret, __LINE__);
            vid_context_p->edt_is_appending = KAL_FALSE;            
            VID_SET_EVENT(VID_EVT_BLOCK);  
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_enc_merge_req_hdlr
 * DESCRIPTION
 *  Video editor encode merger request hdlr
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_enc_merge_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_enc_merge_req_struct *msg_p 
        = (media_vid_edt_enc_merge_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENC_MERGE_REQ_HDLR);
    
    vid_context_p->seq_num = msg_p->seq_num;
    vid_context_p->src_mod = MOD_MMI;   /* currently only for MMI */
    
    if (VID_IN_STATE(VID_IDLE))
    {
        /* disable sleep when playing */
        visual_disable_sleep();
        
        /* send file merge message to Media-v task */
        vid_send_visual_file_merge_req(MED_MODE_EDITOR_FILE);
        
        VID_ENTER_STATE(VID_EDITOR_FILE_MERGE);
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
    }
    else
    {
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_enc_stop_merge_req_hdlr
 * DESCRIPTION
 *  stop video editor encode merger request hdlr
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_enc_stop_merge_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    media_vid_edt_enc_stop_merge_req_struct *msg_p 
//        = (media_vid_edt_enc_stop_merge_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENC_STOP_MERGE_REQ_HDLR);    
   
    if (VID_IN_STATE(VID_EDITOR_FILE_MERGE))
    {
        VID_ENTER_STATE(VID_EDITOR_MERGE_STOPPING);
    }
    else
    {
        VID_SET_EVENT(VID_EVT_BLOCK);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_open_bgm_req_hdlr
 * DESCRIPTION
 *  open bgm for editor
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_open_bgm_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_VID_EDT_BGM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_open_silence_req_struct *msg_p 
        = (media_vid_edt_open_silence_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = vid_edt_create_aud_mp4parser(
                video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM],
                msg_p->data_p,
                msg_p->data_size,
                msg_p->media_mode,
                msg_p->media_type,
                msg_p->aud_duration_p);

    vid_set_result(result, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);

#else /*  __MED_VID_EDT_BGM_SUPPORT__ */
    ASSERT(0);
#endif /*  __MED_VID_EDT_BGM_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_close_bgm_req_hdlr
 * DESCRIPTION
 *  open bgm for editor
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_close_bgm_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_CLOSE_BGM_REQ_HDLR);
#ifdef __MED_VID_EDT_BGM_SUPPORT__
    FSAL_Close(&video_edt_aud_mp4parser_p[VID_MP4PARSER_BGM]->stFSAL_mp4);

    vid_set_result(MED_RES_OK, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);
    return;
#else
    ASSERT(0);
#endif /* __MED_VID_EDT_BGM_SUPPORT__ */

    
}



/*****************************************************************************
 * FUNCTION
 *  vid_edt_open_silence_req_hdlr
 * DESCRIPTION
 *  Open silence for editor
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_open_silence_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_open_silence_req_struct *msg_p 
        = (media_vid_edt_open_silence_req_struct*) ilm_ptr->local_para_ptr;
    kal_int32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = vid_edt_create_aud_mp4parser(
                video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE],
                msg_p->data_p,
                msg_p->data_size,
                msg_p->media_mode,
                msg_p->media_type,
                msg_p->aud_duration_p);

    vid_set_result(result, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);


}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_close_silence_req_hdlr
 * DESCRIPTION
 *  open silence for editor
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_close_silence_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_CLOSE_SILENCE_REQ_HDLR);
    FSAL_Close(&video_edt_aud_mp4parser_p[VID_MP4PARSER_SILENCE]->stFSAL_mp4);


    vid_set_result(MED_RES_OK, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_encode_event_ind_hdlr
 * DESCRIPTION
 *  transcode event ind handler for video editor
 * PARAMETERS
 *  ilm_ptr     [IN]        msg_data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_encode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_encode_event_ind_struct *ind_p;
    kal_uint32 stored_data;
    MEDIA_STATUS_CODE status;
    kal_int32 ret;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_edt_encode_event_ind_struct*) ilm_ptr->local_para_ptr;
    
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_ENCODE_EVENT_IND_HDLR);
    kal_trace(TRACE_GROUP_4, VID_TRC_EVENT, ind_p->event);    

    if (!vid_context_p->edt_is_appending)
    {
        /* driver may terminated by error, but there are messages in queue, should ingore them */
        /* may refer to CR231141 */
        return;
    }

    switch (ind_p->event)
    {
        case VIDEO_EDITOR_DEC_EVENT_BUFFER_EMPTY:
            status = video_editor_dec_put_frame_to_buffer();
            
            if (status != MEDIA_STATUS_OK)
            {
                VID_VIS_ERROR_TRACE(status, __LINE__);
                video_editor_image_path_close();    
            
                if (vid_context_p->edt_is_visaul_drv_opened == KAL_TRUE)
                {
                    video_editor_close();  
                    vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                    intmem_deinit();
                    extmem_deinit();                             
                }                     

                vid_set_result(vid_get_result_from_media_status(status), __LINE__);
                vid_context_p->edt_is_appending = KAL_FALSE;                    
                VID_SET_EVENT(VID_EVT_BLOCK);                
            }            
            break;

        case VIDEO_EDITOR_DEC_DRV_SEEK_ACTION:
            /* this wont have error */
            video_editor_seek_action();
            break;

        case VIDEO_EDITOR_DEC_EVENT_NO_TRACK:
            /* Only A, all no A no V */
            /* TODO: need handle */
            ASSERT(0);
            break;

        case VIDEO_EDITOR_DEC_EVENT_SEEK_DONE:
            ret = vid_edt_encode_start();

            if (ret != MED_RES_OK)
            {
                if (vid_context_p->edt_is_visaul_drv_opened == KAL_TRUE)
                {
                    video_editor_close();  
                    vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                    intmem_deinit();
                    extmem_deinit();                             
                }
                    
                vid_set_result(ret, __LINE__);  
                vid_context_p->edt_is_appending = KAL_FALSE;                                    
                VID_SET_EVENT(VID_EVT_BLOCK);                   
            }
            break;
           
        case VIDEO_EDITOR_ENC_EVENT_VIDEO_BUFFER_AVAIL:
            status = video_editor_enc_store_file(0xffffffff, &stored_data);

            if (status != MEDIA_STATUS_OK)
            {
                VID_VIS_ERROR_TRACE(status, __LINE__);
                video_editor_image_path_close();    

                if (vid_context_p->edt_is_visaul_drv_opened == KAL_TRUE)
                {
                    video_editor_close();  
                    vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                    intmem_deinit();
                    extmem_deinit();                             
                }   
                vid_set_result(vid_edt_get_encode_result_from_media_status(status, &(mp4_files.MEDIA_VIDEO_FILE)), __LINE__);
                vid_context_p->edt_is_appending = KAL_FALSE; 
                VID_SET_EVENT(VID_EVT_BLOCK);                
            } 
            break;
               
        case VIDEO_EDITOR_ENC_EVENT_META_BUFFER_AVAIL:
            status = video_editor_meta_store_file(0xffffffff, &stored_data);

            if (status != MEDIA_STATUS_OK)
            {
               VID_VIS_ERROR_TRACE(status, __LINE__);
               video_editor_image_path_close();

                if (vid_context_p->edt_is_visaul_drv_opened == KAL_TRUE)
                {
                    video_editor_close();  
                    vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                    intmem_deinit();
                    extmem_deinit();                             
                }            

                vid_set_result(vid_edt_get_encode_result_from_media_status(status, &(mp4_files.MEDIA_META_FILE)), __LINE__);
                vid_context_p->edt_is_appending = KAL_FALSE;
                VID_SET_EVENT(VID_EVT_BLOCK);                
            } 
            break;
               
        case VIDEO_EDITOR_ENC_EVENT_COUNT_FILE_SIZE:
            /* count size of the video file - may ignore */
            break;
            
        case VIDEO_EDITOR_EVENT_FAIL:
            /* encode error */
            video_editor_image_path_close();

            if (vid_context_p->edt_is_visaul_drv_opened == KAL_TRUE)
            {
                video_editor_close();  
                vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                intmem_deinit();
                extmem_deinit();                             
            }

            vid_set_result(MED_RES_MP4_PRODUCER_ERROR, __LINE__);
            vid_context_p->edt_is_appending = KAL_FALSE;            
            VID_SET_EVENT(VID_EVT_BLOCK);
            break;
               
        case VIDEO_EDITOR_EVENT_COMPLETE:
            /* encode finish */
            video_editor_image_path_close();

            if (vid_context_p->edt_resource_type == MED_VID_EDT_RES_TYPE_IMAGE)
            {
                video_editor_close();  
                vid_context_p->edt_is_visaul_drv_opened = KAL_FALSE;
                intmem_deinit();
                extmem_deinit();  
            }

            status = video_enc_buffer_dump_to_file(0xffffffff, &stored_data);

            if (status != MEDIA_STATUS_OK)
            {
                VID_VIS_ERROR_TRACE(status, __LINE__);
                vid_set_result(vid_edt_get_encode_result_from_media_status(status, &(mp4_files.MEDIA_VIDEO_FILE)), __LINE__);
                vid_context_p->edt_is_appending = KAL_FALSE;               
                VID_SET_EVENT(VID_EVT_BLOCK);     
                return;
            } 

            status = meta_enc_buffer_store_file(0xffffffff, &stored_data);

            if (status != MEDIA_STATUS_OK)
            {
                VID_VIS_ERROR_TRACE(status, __LINE__);
                vid_set_result(vid_edt_get_encode_result_from_media_status(status, &(mp4_files.MEDIA_META_FILE)), __LINE__);
                vid_context_p->edt_is_appending = KAL_FALSE;               
                VID_SET_EVENT(VID_EVT_BLOCK);  
                return;                              
            } 

            /* append audio */
            ret = vid_edt_append_audio();

            vid_context_p->edt_is_first_time_append = KAL_FALSE;           

            if (ret != MED_RES_OK)
            {
                vid_set_result(ret, __LINE__);
                vid_context_p->edt_is_appending = KAL_FALSE;                              
                VID_SET_EVENT(VID_EVT_BLOCK);
                return;
            }

            vid_set_result(MED_RES_OK, __LINE__);
            vid_context_p->edt_is_appending = KAL_FALSE;                           
            VID_SET_EVENT(VID_EVT_BLOCK);
            break;
            
       default:
           ASSERT(0);
           break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_edt_create_aud_mp4parser
 * DESCRIPTION
 *  Open audio for editor
 * PARAMETERS
 * video_mp4parser_struct *dest_p   [out]   the parser structure to create.
 * kal_uint8 *data_p                [in]    bgm file name or source buffer ptr 
 * kal_uint32 data_size             [in]    if it is MEDIA_ARRAY, this shoulbe be buffer size 
 * kal_uint8 media_mode             [in]    media mode   
 * kal_uint8 media_type             [in]    media type 
 * kal_uint64 *aud_duration_p       [out]   audio duration of this bgm 
 * RETURNS
 *  create result
 *****************************************************************************/
kal_int32 vid_edt_create_aud_mp4parser(
    video_mp4parser_struct *dest_p,
    kal_uint8 *data_p,
    kal_uint32 data_size,
    kal_uint8 media_mode,
    kal_uint8 media_type,
    kal_uint64 *aud_duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    kal_uint32 filesize;
    kal_int32 result;
    kal_uint32 index;
    kal_uint64 temp;
    kal_bool is_file_opened;
    kal_uint32 aud_duration;
    kal_uint32 time_scale;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_EDT_OPEN_SILENCE_REQ_HDLR);
    
    result = MED_RES_OK;
    is_file_opened = KAL_FALSE;


    if (media_mode == MED_MODE_ARRAY)
    {
        FSAL_Direct_SetRamFileSize(&dest_p->stFSAL_mp4, data_size);        
        eFSALRet = FSAL_Open(&dest_p->stFSAL_mp4, (void*)data_p, FSAL_ROMFILE);    
        vid_context_p->silence_media_mode = MED_MODE_ARRAY;
    } 
    else if (media_mode == MED_MODE_FILE)
    {
        eFSALRet = FSAL_Open(&dest_p->stFSAL_mp4, (void*)data_p, FSAL_READ); 
        vid_context_p->silence_media_mode = MED_MODE_FILE;        
    }
    else
    {
        ASSERT(0);
    }
  
    is_file_opened = KAL_TRUE;
    
    FSAL_SetBuffer(&dest_p->stFSAL_mp4, VID_MP4_FSAL_BUF_SIZE, (kal_uint8*)dest_p->mp4_buf);

    /* set seek hint */
    eFSALRet = FSAL_GetFileSize(&dest_p->stFSAL_mp4, &filesize);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        result = MED_RES_OPEN_FILE_FAIL;
        goto open_silence_error_out;
    }

    for (index = 0; index < VID_DEC_SEEK_HINT_SIZE; index++)
    {
        temp = ((kal_uint64) filesize * (kal_uint64) (index + 1)) / (kal_uint64) (VID_DEC_SEEK_HINT_SIZE + 1);
        dest_p->seek_hint[index].Index = (kal_uint32) temp;
    }
    DRM_set_seek_hint(dest_p->stFSAL_mp4.hFile, VID_DEC_SEEK_HINT_SIZE, dest_p->seek_hint);

    /* Creat MP4 parser */
    eMp4ParserRet = MP4_Parse(&dest_p->parser, &dest_p->stFSAL_mp4);

    if (eMp4ParserRet != MP4_PARSER_OK && eMp4ParserRet != MP4_PARSER_WARNING_TRAILING_GARBAGE)
    {
        VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
        result = MED_RES_BAD_FORMAT;
        goto open_silence_error_out;
    }

    eMp4ParserRet = MP4_STBL_CacheTablePreprocess(
                        &dest_p->parser, 
                        dest_p->stbl_buf, 
                        VID_MP4_STBL_BUF_SIZE);
                        
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
        result = MED_RES_BAD_FORMAT;
        goto open_silence_error_out;
    }

    /* FSAL aud data */
    eFSALRet = FSAL_Open_Attach(&dest_p->stFSAL_aud_data, &dest_p->stFSAL_mp4);
    
    if (eFSALRet != FSAL_OK)
    {
        VID_PARSE_ERROR_TRACE(eMp4ParserRet,  __LINE__);
        result = MED_RES_OPEN_FILE_FAIL;
        goto open_silence_error_out;
    }
    FSAL_SetBuffer(&dest_p->stFSAL_aud_data, VID_MP4_FSAL_BUF_SIZE, (kal_uint8*)dest_p->aud_data_buf);

    /* FASL stco */
    eFSALRet = FSAL_Open_Attach(&dest_p->stFSAL_stco, &dest_p->stFSAL_mp4);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        result = MED_RES_OPEN_FILE_FAIL;
        goto open_silence_error_out;
    }
    FSAL_SetBuffer(&dest_p->stFSAL_stco, VID_MP4_STCO_BUF_SIZE, (kal_uint8*)dest_p->stco_buf);

    /* FSAL stsz */
    eFSALRet = FSAL_Open_Attach(&dest_p->stFSAL_stsz, &dest_p->stFSAL_mp4);
    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        result = MED_RES_OPEN_FILE_FAIL;
        goto open_silence_error_out;
    }
    FSAL_SetBuffer(&dest_p->stFSAL_stsz, VID_MP4_STSZ_BUF_SIZE, (kal_uint8*)dest_p->stsz_buf);

    /* set FSAL to MP4 Parser */
    MP4_Audio_SetFSAL(&dest_p->parser, &dest_p->stFSAL_aud_data);
    MP4_SetFSAL_STCO(&dest_p->parser, MP4_TRACK_AUDIO, &dest_p->stFSAL_stco);
    MP4_SetFSAL_STSZ(&dest_p->parser, MP4_TRACK_AUDIO, &dest_p->stFSAL_stsz);
    MP4_UpdateSampleCount(&dest_p->parser, MP4_TRACK_AUDIO);

    eMp4ParserRet = MP4_GetMediaDuration(&dest_p->parser, &aud_duration, MP4_TRACK_AUDIO);

    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        result = MED_RES_PARSER_ERROR;
        goto open_silence_error_out;        
    }    

    eMp4ParserRet = MP4_GetMediaTimeScale(&dest_p->parser, &time_scale, MP4_TRACK_AUDIO);
     
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        result = MED_RES_PARSER_ERROR;
        goto open_silence_error_out;        
    }    

    aud_duration = (kal_uint64)aud_duration * (kal_uint64)1000 / (kal_uint64)time_scale;
    (*aud_duration_p) = (kal_uint64)aud_duration;
    
    return result;
    
open_silence_error_out:
    
    if (is_file_opened)
    {
        FSAL_Close(&dest_p->stFSAL_mp4);
    }

    return result;
        
}

/*****************************************************************************
 * FUNCTION
 *  vid_edt_init_req_hdlr
 * DESCRIPTION
 *  allocate additional video data memory for opening multiple video files.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_edt_init_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_edt_init_req_struct *p_para = (media_vid_edt_init_req_struct *) ilm_ptr->local_para_ptr;
    kal_int32 result = MED_RES_OK;
    kal_int32 i;
    kal_int32 byte2alloc;
    kal_uint8 *p_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_para->init)
    {
        /* initialize */
        if( vid_context_p->edt_video_buff_p != NULL)
        {
            result = MED_RES_ERROR;
            vid_set_result(result, __LINE__);
            VID_SET_EVENT(VID_EVT_BLOCK);
            return;
        }
        /* allocate memory */
        byte2alloc = sizeof(video_data_struct) * (VIDEO_EDT_DATA_P_COUNT) + sizeof(video_mp4parser_struct)  * (VID_MP4PARSER_AUD_TYPE_COUNT);
        vid_context_p->edt_video_buff_p = (kal_uint8 *)med_alloc_ext_mem(byte2alloc);

        if (vid_context_p->edt_video_buff_p != NULL)
        {
            for (i = 0, p_buffer = vid_context_p->edt_video_buff_p; i < VIDEO_EDT_DATA_P_COUNT; i++, p_buffer += sizeof(video_data_struct))
            {
                video_data_list_p[i] =  (video_data_struct*) p_buffer;
                video_data_list_p[i]->is_used = KAL_FALSE;
            }
            for (i = 0; i < VID_MP4PARSER_AUD_TYPE_COUNT; i++, p_buffer += sizeof(video_mp4parser_struct))
            {
                video_edt_aud_mp4parser_p[i] = (video_mp4parser_struct*)p_buffer;
            }
        }
        else
        {
            result = MED_RES_MEM_INSUFFICIENT;      
        }
    }
    else
    {
        /* deinit */
        if( vid_context_p->edt_video_buff_p != NULL)
        {
            for (i = 0 ; i < VIDEO_EDT_DATA_P_COUNT; i++)
            {
                 if (video_data_list_p[i] && video_data_list_p[i]->is_used)
                 {
                    /* some context is still being used */
                    ASSERT(0);
                 }
                 else
                 {
                    video_data_list_p[i] = NULL;
                 }
            }
            for (i = 0; i < VID_MP4PARSER_AUD_TYPE_COUNT; i++)
            {
                video_edt_aud_mp4parser_p[i] = NULL;
            }
            
            /* free memory */
            med_free_ext_mem((void **) &vid_context_p->edt_video_buff_p);
            vid_context_p->edt_video_buff_p = NULL;
        }
        else
        {
            result = MED_RES_ERROR;
        }
    }
    vid_set_result(result, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);

#else  /* __MTK_TARGET__ */

    vid_set_result(MED_RES_OK, __LINE__);
    VID_SET_EVENT(VID_EVT_BLOCK);
    
#endif /* __MTK_TARGET__ */
}

#endif /* __MED_VID_EDT_MOD__ */


#ifdef __MED_VID_PDL_MOD__
/*****************************************************************************
 * FUNCTION
 *  vid_get_pdl_precent_req_hdlr
 * DESCRIPTION
 *  Get pdl buffering percentage.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_pdl_precent_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_percent_req_struct *msg_p =
        (media_vid_get_pdl_percent_req_struct*) ilm_ptr->local_para_ptr;

    kal_uint32 aud_duration;
    kal_uint32 vid_duration;
    kal_int64 available_time;
    kal_int64 buf_duration;
    MP4_Parser_Status eMp4ParserRet;
    kal_uint32 buffer_time;   
    kal_uint32 file_size;
    kal_uint32 cur_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_PDL_PERCENT_REQ_HDLR);
    vid_debug_print_cur_state(__LINE__);

    if (VID_IN_STATE(VID_PDL_META_BUFFERING) || VID_IN_STATE(VID_IDLE))
    {
        /* META still not ready */
        *(msg_p->percent_p) = 0;          /* 0 % */
        kal_trace(TRACE_GROUP_4, VID_TRC_PERCENT, *(msg_p->percent_p), __LINE__);        
        VID_SET_EVENT(VID_EVT_GET_INFO);
        return;
    }
    

    FSAL_GetFileSize(stFSAL_v_ptr, &file_size);    
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_SIZE, file_size);

    if (VID_HAS_TRACK(MED_AUDIO_TRACK))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, __LINE__);      
        eMp4ParserRet = MP4_Audio_GetAvailableDur(&stMp4Parser_pdl_a, &aud_duration);
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_DURATION, aud_duration);  
         
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
            VID_SET_EVENT(VID_EVT_GET_INFO);
            return;
        }     
    }

    if (VID_HAS_TRACK(MED_VISUAL_TRACK))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, __LINE__);      
        eMp4ParserRet = MP4_Video_GetAvailableDur(&stMp4Parser_pdl_v, &vid_duration);
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
        kal_trace(TRACE_GROUP_4, VID_TRC_VID_DURATION, vid_duration);
       
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
            VID_SET_EVENT(VID_EVT_GET_INFO);
            return;
        }     
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_AV_DURATION, aud_duration, vid_duration);
    kal_trace(
        TRACE_GROUP_4, 
        VID_TRC_TOTAL_DURATION, 
        (kal_uint32)vid_context_p->total_time,
        (kal_uint32)vid_context_p->total_audio_time,
        (kal_uint32)vid_context_p->total_video_time); 

    if (!VID_HAS_TRACK(MED_VISUAL_TRACK))
    {
        /* A only */
        vid_duration = aud_duration;
    }
    else if (!VID_HAS_TRACK(MED_AUDIO_TRACK))
    {
        /* v only */
        aud_duration = vid_duration;        
    }

    /* total time < buffer time */
    if (vid_context_p->total_time < VID_PDL_BUFFER_TIME_FOR_PLAY)
    {
        buffer_time = vid_context_p->total_time;
    }
    else
    {
        buffer_time = VID_PDL_BUFFER_TIME_FOR_PLAY;
    }

    if (vid_context_p->total_audio_time > vid_context_p->total_video_time)
    {
        /* A > V */
        if (vid_duration >= vid_context_p->total_video_time)
        {
            /* get all V */ 
            available_time = aud_duration;
        }
        else
        {
            /* have A and V, use min value as duration */
            available_time = (vid_duration < aud_duration) ? (kal_uint64)vid_duration : (kal_uint64)aud_duration;
        }
    }
    else if (vid_context_p->total_video_time > vid_context_p->total_audio_time)
    {
        /* V > A */
        if (aud_duration >= vid_context_p->total_audio_time)
        {
            /* get all A */ 
            available_time = vid_duration;
        }
        else
        {
            /* have A and V, use min value as duration */
            available_time = (vid_duration < aud_duration) ? (kal_uint64)vid_duration : (kal_uint64)aud_duration;
        } 
    }
    else
    {
        available_time = (vid_duration < aud_duration) ? (kal_uint64)vid_duration : (kal_uint64)aud_duration;
    }
    
    if (available_time >= vid_context_p->total_time)
    {
        *(msg_p->percent_p) = 100;          /* 100 % */
        kal_trace(TRACE_GROUP_4, VID_TRC_PERCENT, *(msg_p->percent_p), __LINE__);
        VID_SET_EVENT(VID_EVT_GET_INFO);
        return;
    }
    
    cur_time = (kal_uint32)vid_context_p->current_time;
    kal_trace(TRACE_GROUP_4, VID_TRC_BUFFER_TIME, available_time, cur_time, buffer_time);

    buf_duration = available_time - vid_context_p->current_time;        
    if (buf_duration > buffer_time)
    {
        *(msg_p->percent_p) = 100;
    }
    else if (buf_duration < 0)
    {
        *(msg_p->percent_p) = 0;
    }
    else
    {
        *(msg_p->percent_p) = (kal_uint32)(buf_duration * 100 / buffer_time);
    }

    /* if buffer already enoguth, but video driver dont have enough buffer to start */
    if (VID_HAS_TRACK(MED_VISUAL_TRACK) && *(msg_p->percent_p) == 100)
    {
        MEDIA_STATUS_CODE vid_ret;
        
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_VIDEO_FRAME_AVAILABLE, __LINE__);      
        vid_ret = MP4_Video_FrameAvailable(&stMp4Parser_pdl_v);
        vid_debug_print_vid_drv_return(vid_ret, __LINE__);

        if (vid_ret != MEDIA_STATUS_OK)
        {
            if (vid_ret == FSAL_READ_EOF)
            {
                /* still not enough, set to 99% */
                *(msg_p->percent_p) = 99;
            }
            else if (vid_ret == VIDEO_ERROR)
            {
                vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
                VID_SET_EVENT(VID_EVT_GET_INFO);
                return;
            }
            else
            {
                /* invalid return code */
                ASSERT(0);
            }
        }
    }

    if (VID_HAS_TRACK(MED_AUDIO_TRACK) && 
        aud_duration < vid_context_p->total_audio_time)
    {
        /* if has audio track, and anduo track not totally downloaded */
        
        kal_uint32 uReadSize;
        kal_uint32 aud_frame;
        kal_uint32 aud_buf_percent;
        Media_VM_PCM_Param vpFormat;
        void *param = NULL;

        /* 
         * we need to open an audio handle to check if we current arrived data
         * can fill aud buf, we will open an AMR codec. (if the source is AAC, we 
         * still open AMR, we only need to check to buffer size, so which codec is fine)
         */
        vpFormat.mediaType = vid_context_p->aud_format;
        vpFormat.vmParam = (kal_uint32)MEDIA_VMP_AS_RINGTONE;
        param = &vpFormat;        

        if ((vid_context_p->mhdl_handle = AMR_Open(vid_audio_play_callback, NULL, param)) == NULL)
        {
            ASSERT(0);
        }
        
        vid_context_p->mhdl_handle->SetBuffer(
            vid_context_p->mhdl_handle, 
            (kal_uint8*)aud_context_p->ring_buf, 
            AUD_RING_BUFFER_LEN * 2);    

        vid_context_p->mhdl_handle->GetWriteBuffer(
            vid_context_p->mhdl_handle, 
            &vid_context_p->audio_buf_p, 
            &vid_context_p->audio_buf_len);

        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_TIMETOSAMPLENO, (kal_uint32)vid_context_p->current_time, __LINE__);   
        
        MP4_Audio_TimeToSampleNo(
            stMp4Parser_a_ptr,
            cur_time,
            &aud_frame);   
        
        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_FRAME, aud_frame, __LINE__);  

        /* seek to current play time position */
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_SEEK, aud_frame, __LINE__);                
        eMp4ParserRet = MP4_Audio_Seek(stMp4Parser_a_ptr, aud_frame);                                
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);

        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_READ, __LINE__);                        
        
        eMp4ParserRet = MP4_Audio_Read(
                            stMp4Parser_a_ptr, 
                            (kal_uint8*)vid_context_p->audio_buf_p, 
                            vid_context_p->audio_buf_len, 
                            &uReadSize);
        
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
        
        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_READ_BUF, vid_context_p->audio_buf_len,  uReadSize);    

        ASSERT(vid_context_p->audio_buf_len != 0);

        if (vid_context_p->audio_buf_len > uReadSize)
        {
            /* not enough aud buffer, will underflow when play */
            aud_buf_percent = uReadSize * 100 / vid_context_p->audio_buf_len;

            if (aud_buf_percent < *(msg_p->percent_p))
            {
                *(msg_p->percent_p) = aud_buf_percent;
            }
        }

        /* already consumed by MP4_Audio_Read, seek to previous position */
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_SEEK, aud_frame, __LINE__);                
        eMp4ParserRet = MP4_Audio_Seek(stMp4Parser_a_ptr, aud_frame);                                
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);

        /* close audio handle */
        vid_context_p->mhdl_handle->Stop(vid_context_p->mhdl_handle);  
        vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
        vid_context_p->mhdl_handle = NULL;
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_PERCENT, *(msg_p->percent_p), __LINE__);
    VID_SET_EVENT(VID_EVT_GET_INFO);

}



/*****************************************************************************
 * FUNCTION
 *  vid_get_pdl_max_time_req_hdlr
 * DESCRIPTION
 *  Get pdl max play time
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_pdl_max_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_pdl_max_time_req_struct *msg_p =
        (media_vid_get_pdl_max_time_req_struct*) ilm_ptr->local_para_ptr;

    kal_uint32 aud_duration = 0;
    kal_uint32 vid_duration = 0;
    kal_uint64 available_time;
    MP4_Parser_Status eMp4ParserRet;
    kal_uint32 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_PDL_MAX_TIME_REQ_HDLR);
    vid_debug_print_cur_state(__LINE__);

    FSAL_GetFileSize(stFSAL_v_ptr, &file_size);    
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_SIZE, file_size);

    ASSERT(stMp4Parser_a_ptr != 0);

    if (VID_IN_STATE(VID_PDL_META_BUFFERING))
    {
        /* META still not ready */
        *(msg_p->max_time_p) = 0;
        kal_trace(TRACE_GROUP_4, VID_TRC_MAX_TIME, (kal_uint32)(*(msg_p->max_time_p)), __LINE__);              
        VID_SET_EVENT(VID_EVT_GET_INFO);
        return;
    }

    if (VID_HAS_TRACK(MED_AUDIO_TRACK))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_AUDIO_GETAVAILABLEDUR, __LINE__);      
        eMp4ParserRet = MP4_Audio_GetAvailableDur(&stMp4Parser_pdl_a, &aud_duration);
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_DURATION, aud_duration);  
         
        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            vid_set_pdl_result(MED_RES_PARSER_ERROR, __LINE__);
            VID_SET_EVENT(VID_EVT_GET_INFO);
            return;
        }     
    }

    if (VID_HAS_TRACK(MED_VISUAL_TRACK))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_VIDEO_GETAVAILABLEDUR, __LINE__);      
        eMp4ParserRet = MP4_Video_GetAvailableDur(&stMp4Parser_pdl_v, &vid_duration);
        vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
        kal_trace(TRACE_GROUP_4, VID_TRC_VID_DURATION, vid_duration);

        if (eMp4ParserRet != MP4_PARSER_OK)
        {
            vid_set_pdl_result(MED_RES_PARSER_ERROR, __LINE__);
            VID_SET_EVENT(VID_EVT_GET_INFO);
            return;
        }     
    }


    kal_trace(TRACE_GROUP_4, VID_TRC_AV_DURATION, aud_duration, vid_duration);
    kal_trace(
        TRACE_GROUP_4, 
        VID_TRC_TOTAL_DURATION, 
        (kal_uint32)vid_context_p->total_time,
        (kal_uint32)vid_context_p->total_audio_time,
        (kal_uint32)vid_context_p->total_video_time); 
    
    if (!VID_HAS_TRACK(MED_VISUAL_TRACK))
    {
        /* A only */
        vid_duration = aud_duration;
    }
    else if (!VID_HAS_TRACK(MED_AUDIO_TRACK))
    {
        /* v only */
        aud_duration = vid_duration;        
    }
    
    if (vid_context_p->total_audio_time > vid_context_p->total_video_time)
    {
        /* A > V */
        if (vid_duration >= vid_context_p->total_video_time)
        {
            /* get all V */ 
            available_time = aud_duration;
        }
        else
        {
            /* have A and V, use min value as duration */
            available_time = (vid_duration < aud_duration) ? (kal_uint64)vid_duration : (kal_uint64)aud_duration;
        }
    }
    else if (vid_context_p->total_video_time > vid_context_p->total_audio_time)
    {
        /* V > A */
        if (aud_duration >= vid_context_p->total_audio_time)
        {
            /* get all A */ 
            available_time = vid_duration;
        }
        else
        {
            /* have A and V, use min value as duration */
            available_time = (vid_duration < aud_duration) ? (kal_uint64)vid_duration : (kal_uint64)aud_duration;
        } 
    }
    else
    {
        available_time = (vid_duration < aud_duration) ? (kal_uint64)vid_duration : (kal_uint64)aud_duration;
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_DURATION, available_time);

    if (available_time >= vid_context_p->total_time)
    {
        *(msg_p->max_time_p) = vid_context_p->total_time;
        kal_trace(TRACE_GROUP_4, VID_TRC_MAX_TIME, (kal_uint32)(*(msg_p->max_time_p)), __LINE__); 
        VID_SET_EVENT(VID_EVT_GET_INFO);
        return;
    }
    
    *(msg_p->max_time_p) = (kal_uint64)available_time;

    kal_trace(TRACE_GROUP_4, VID_TRC_MAX_TIME, (kal_uint32)(*(msg_p->max_time_p)), __LINE__); 
    VID_SET_EVENT(VID_EVT_GET_INFO);

}
          



/*****************************************************************************
 * FUNCTION
 *  vid_check_is_pdl_req_hdlr
 * DESCRIPTION
 *  Get pdl max play time.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_check_is_pdl_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_check_is_pdl_req_struct *msg_p =
        (media_vid_check_is_pdl_req_struct*) ilm_ptr->local_para_ptr;
    
    kal_bool is_pdl;
    FSAL_Status eFSALRet;
    MP4_Parser_Status eMp4ParserRet;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_IS_PDL_REQ_HDLR);
    vid_debug_print_cur_state(__LINE__);
    
    /* load context */
    vid_add_video_working_data_item(MED_MODE_PDL_FILE, &vid_context_p->handle);
    vid_load_video_working_data_buf(vid_context_p->handle);

    /* init fsal */
    FSAL_Direct_SetRamFileSize(stFSAL_v_ptr, msg_p->buf_size);    
    eFSALRet = FSAL_Open(stFSAL_v_ptr, (void*)msg_p->file_buf_p, FSAL_ROMFILE);

    if (eFSALRet != FSAL_OK)
    {
        VID_FSAL_ERROR_TRACE(eFSALRet, __LINE__);
        vid_set_result(MED_RES_OPEN_FILE_FAIL, __LINE__);
        VID_SET_EVENT(VID_EVT_GET_INFO);        
        return;
    }

    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MP4_ISPDPROFILE, __LINE__);
    eMp4ParserRet = MP4_IsPDProfile(stMp4Parser_v_ptr, stFSAL_v_ptr, &is_pdl);
    vid_debug_print_mp4_parser_return(eMp4ParserRet, __LINE__);
    
    FSAL_Close(stFSAL_v_ptr);
    
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        vid_set_result(MED_RES_PARSER_ERROR, __LINE__);
    }
    else
    {
        if (is_pdl)
        {
            vid_set_result(MED_RES_OK, __LINE__);
        }
        else
        {
            vid_set_result(MED_RES_INVALID_FORMAT, __LINE__);   
        }
    }

    VID_SET_EVENT(VID_EVT_GET_INFO);

}
#endif /* __MED_VID_PDL_MOD__ */
#endif /* defined(__MED_VID_MOD__) */ 



#if defined(__MED_MJPG_MOD__)
/***************************************************************************** 
 * Source Code of __MED_MJPG_MOD__
 *
 * __MED_MJPG_MOD__  : MT6225_SERIES
 * 
 * Notice: MT6217_SERIES already phase out
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VIDEO_RECORD_MEM_MARGIN         (10*1024)

#define VID_MAX_STOP_TIME               ((kal_uint64)(-1))      /* 64 bits */
#define VID_STOP_TIME_CHECK_ELAPSE      (300)                   /* 300ms check once */
#define VID_VOL_LEVEL_NOT_USED          (0xff)


#define MIN_VIDEO_FILE_SIZE             (20*1024)
#define MAX_MJPG_DIMENSION              (320*240)
#define MAX_MJPG_FILE_FRAME_RATE        (15)        /* max frame rate when open file */
#define MAX_MJPG_PLAY_FRAME_RATE        (15)        /* max frame rate when play file */

#define MJPG_FRAME_BUFFER_SIZE          (100*1024)  /* frame buffer for MJPEG */

#define VID_AMR_HEADER                  "#!AMR\n"
#define VID_AMR_HEADER_SIZE             (6)

#define VID_AMR_WB_HEADER               "#!AMR-WB\n"
#define VID_AMR_WB_HEADER_SIZE          (9)

typedef MHdl *(*vid_aud_open_func_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);


/***************************************************************************** 
 * Global Veriabe
 *****************************************************************************/
med_avi_info_struct avi_data;
lcd_frame_update_struct lcd_data;
static jpeg_decode_process_struct jpg_decode;

#ifdef __MED_MJPG_ENC_MOD__
static kal_int32 mjpeg_record_int_mem = MAX_VID_ENC_INT_MEM_SIZE;
static mjpeg_encode_process_struct mjpeg_encode;
#endif /* __MED_MJPG_ENC_MOD__ */


/***************************************************************************** 
 * Local Veriabe
 *****************************************************************************/
void vid_close_play_file(void); 
void vid_stop_audio(void);
void vid_stop_visual(void);
void vid_stop_unfinished_audio(void);
void vid_release_player_memory(void);
void vid_release_recorder_memory(void);
kal_int32 vid_close_avi_record_file(void);
kal_int32 vid_open_avi_record_file(kal_wchar *file_name);
kal_int32 vid_save_file_path(kal_wchar *path);
void vid_check_stop_time(void *arg);

#if defined(__MED_MJPG_ENC_MOD__)
void vid_stop_camera_preview(void);
#endif



/***************************************************************************** 
 * Extern - TODO: ask owner provide interface
 *****************************************************************************/
#ifdef __MED_CAM_MOD__
/* TODO: ask cam provide interface */
extern kal_uint8 cam_rotate_map[CAM_NO_OF_IMAGE_ROTATE];
#endif 

extern kal_bool mjpeg_get_encode_buffer(kal_uint32 *buf);



/*****************************************************************************
 * FUNCTION
 *  vid_check_camera_is_idle
 * DESCRIPTION
 *  Check camera is idle or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  Idle or not
 *****************************************************************************/
kal_bool vid_chcek_camera_is_idle(void)
{
#if defined(__MED_CAM_MOD__)
    return (kal_bool)CAM_IN_STATE(CAM_IDLE);
#else
    return KAL_TRUE;
#endif
}



/*****************************************************************************
 * FUNCTION
 *  vid_stop_unfinished_audio
 * DESCRIPTION
 *  Stop unfinished audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_unfinished_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_UNFINISHED_AUDIO);
    
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

    aud_stop_unfinished_process();

}



/*****************************************************************************
 * FUNCTION
 *  vid_visual_stop_cnf_hdlr
 * DESCRIPTION
 *  Handle visual stop confirm message from media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_stop_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_STOP_CNF_HDLR);          
    vid_debug_print_cur_state(__LINE__);
    
    if (VID_IN_STATE(VID_PLAY_ABORTING))
    {
        vid_close_play_file();
        VID_ENTER_STATE(VID_IDLE);
        AUD_SET_EVENT(AUD_EVT_BLOCK);            
    }
    else if (VID_IN_STATE(VID_PLAY))
    {
        vid_stop_audio();
        vid_stop_visual();

        /* seek to a vliad position */
        med_avi_seek_by_time(vid_context_p->time_played);
        
        VID_ENTER_STATE(VID_FILE_READY);                
        vid_play_finish_hdlr();
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
    {
        vid_stop_visual();  
        VID_ENTER_STATE(VID_FILE_READY);                        
        vid_play_finish_hdlr();        
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        vid_stop_visual();
        VID_ENTER_STATE(VID_FILE_READY);                
        vid_send_play_finish_ind(MED_RES_AUDIO_ERROR);  
    }
    else if (VID_IN_STATE(VID_PLAY_REACH_STOP_TIME))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)vid_context_p->time_played, __LINE__);
        vid_stop_audio();  
        vid_stop_visual();

        /* seek to a vliad position */
        med_avi_seek_by_time(vid_context_p->time_played);
        
        VID_ENTER_STATE(VID_FILE_READY);  
        vid_send_play_finish_ind(MED_RES_REACH_STOP_TIME);
    }
    else if (VID_IN_STATE(VID_PLAY_STOP_VISUAL))
    {
        /* print debug info */
        {
            kal_uint32 duration;
            kal_uint32 actual_fps;
            kal_get_time(&vid_context_p->debug_end_time);

            duration = vid_context_p->debug_end_time - vid_context_p->debug_start_time;
            duration = kal_ticks_to_milli_secs(duration) / 1000;

            if (duration == 0)
            {
                duration = 1;
            }
            
            actual_fps 
                = vid_context_p->debug_total_frame 
                - vid_context_p->debug_skip_frame 
                - vid_context_p->debug_drop_frame;

            actual_fps = actual_fps / duration;

            kal_prompt_trace(MOD_MED, "[VID] actual_fps:%d", actual_fps);
            kal_prompt_trace(MOD_MED, "[VID] origianl_fps:%d", avi_data.vid_fps);
            kal_prompt_trace(MOD_MED, "[VID] total_frame:%d", vid_context_p->debug_total_frame);
            kal_prompt_trace(MOD_MED, "[VID] drop_frame:%d", vid_context_p->debug_drop_frame);            
            kal_prompt_trace(MOD_MED, "[VID] skip_frame:%d", vid_context_p->debug_skip_frame);         
        }
        
        vid_stop_visual();

        /* seek to a vliad position */
        med_avi_seek_by_time(vid_context_p->time_played);
        
        VID_ENTER_STATE(VID_FILE_READY);                
        VID_SET_EVENT(VID_EVT_STOP);
    }
#ifdef __MED_MJPG_ENC_MOD__
    else if (VID_IN_STATE(VID_RECORD) || 
        VID_IN_STATE(VID_RECORD_FINISH))
    {
        vid_release_recorder_memory();        
        vid_close_avi_record_file();
        VID_ENTER_STATE(VID_IDLE);
        vid_send_record_finish_ind(vid_context_p->error_code);
    }
    else if (VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        vid_release_recorder_memory();           
        vid_close_avi_record_file();
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        VID_SET_EVENT(VID_EVT_PAUSE);
    }
    else if (VID_IN_STATE(VID_RECORD_ABORTING))
    {
        vid_release_recorder_memory();                   
        vid_close_avi_record_file();
        vid_clean_temp_files();
        VID_ENTER_STATE(VID_IDLE);
        AUD_SET_EVENT(AUD_EVT_BLOCK);        
    }
#endif /* __MED_MJPG_ENC_MOD__ */
   
}




/*****************************************************************************
 * FUNCTION
 *  vid_stop_unfinished_task
 * DESCRIPTION
 *  This function is to stop video play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_unfinished_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (VID_IN_STATE(VID_PLAY))
    {
        med_stop_timer(VID_FRAME_TIMER);

        if (vid_context_p->image_path_open)
        {
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_STOP_JPEG_VIDEO_PLAY, __LINE__);
            stop_jpeg_video_play();
            kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);
            
            vid_context_p->image_path_open = KAL_FALSE;
        }
        vid_release_player_memory();

        if (vid_context_p->play_audio)
        {
            vid_stop_audio();
        }

        VID_ENTER_STATE(VID_FILE_READY);
    }
#if defined(__MED_MJPG_ENC_MOD__)
    else if (VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_PAUSED))
    {
        vid_stop_video_record();
        vid_stop_camera_preview();
        
        VID_ENTER_STATE(VID_RECORD_ABORTING);
        vid_send_visual_stop_req(NULL);

    }
#endif /* defined(__MED_MJPG_ENC_MOD__) */
    
}




/*****************************************************************************
 * FUNCTION
 *  vid_abort_by_client_switching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 vid_abort_by_client_switching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_ABORT_BY_CLIENT_SWITCHING);     
    vid_debug_print_cur_state(__LINE__);    

    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) || 
        VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        vid_stop_audio();
        vid_send_visual_stop_req(NULL);
        VID_ENTER_STATE(VID_PLAY_ABORTING);
        VID_RETURN(MED_RES_BUSY);
    }
    else if (VID_IN_STATE(VID_FILE_READY))
    {
        vid_close_play_file();
        VID_ENTER_STATE(VID_IDLE);  
        VID_RETURN(MED_RES_OK);
    }
    else if (VID_IN_STATE(VID_SEEK) ||
             VID_IN_STATE(VID_VISUAL_PLAY_FINISH) ||
             VID_IN_STATE(VID_FILE_MERGE))
    {
        /* AVI dont have these states */
        ASSERT(0);
        VID_RETURN(MED_RES_OK);        
    }

#if defined(__MED_MJPG_ENC_MOD__)    
    else if (VID_IN_STATE(VID_PREVIEW))
    {
        vid_stop_camera_preview();
        vid_release_recorder_memory();                  
        
        VID_ENTER_STATE(VID_IDLE);
        VID_RETURN(MED_RES_OK);
    }
    else if (VID_IN_STATE(VID_RECORD) || 
             VID_IN_STATE(VID_RECORD_PAUSED))
    {
        vid_stop_video_record();
        vid_stop_camera_preview();

        /* notify visual to dump remained data */
        vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_TERMINATE);
        vid_send_visual_stop_req(NULL);

        VID_ENTER_STATE(VID_RECORD_ABORTING);
        VID_RETURN(MED_RES_BUSY);
    }
    else if (VID_IN_STATE(VID_RECORD_FINISH))
    {
        VID_ENTER_STATE(VID_RECORD_ABORTING);  
        VID_RETURN(MED_RES_BUSY);
    }
#endif /* defined(__MED_MJPG_ENC_MOD__) */
    else
    {
        VID_RETURN(MED_RES_OK);
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_stop_req_hdlr
 * DESCRIPTION
 *  Stop request handler
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_PLAY))
    {
#ifdef __SF_MP4_SUPPORT__
        if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
        {
            kal_prompt_trace(MOD_MED, "vid_stop_req_hdlr, before vdo_stop_play_file");
#ifndef WIN32
//Huyanwei Add Macro Control			
            vdo_stop_play_file();
#endif
            VID_ENTER_STATE(VID_FILE_READY);
            VID_SET_EVENT(VID_EVT_STOP);
        }
        else
        {
#endif //__SF_MP4_SUPPORT__    
        vid_stop_audio();
        VID_ENTER_STATE(VID_PLAY_STOP_VISUAL);
        vid_send_visual_stop_req(NULL);      
#ifdef __SF_MP4_SUPPORT__
        }
#endif //__SF_MP4_SUPPORT__		
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_FINISH) || 
             VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        /* if we are in these two stats, mean we send stop req to vis and wait from cnf */
        /* will wait for stop conf to unlock the event */
        VID_ENTER_STATE(VID_PLAY_STOP_VISUAL);
    }
#if defined(__MED_MJPG_ENC_MOD__)    
    else if (VID_IN_STATE(VID_PREVIEW))
    {
        vid_stop_camera_preview();
        vid_release_recorder_memory();                  
        VID_ENTER_STATE(VID_IDLE);
        VID_SET_EVENT(VID_EVT_STOP);
    }
    else if (VID_IN_STATE(VID_RECORD) || 
             VID_IN_STATE(VID_RECORD_PAUSED))
    {
        vid_stop_video_record();
        vid_stop_camera_preview();
        VID_ENTER_STATE(VID_RECORD_STOP_VISUAL);

        /* notify visual to dump remained data */
        vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_TERMINATE);

        vid_send_visual_stop_req(NULL);
    }
#endif /* defined(__MED_MJPG_ENC_MOD__) */    
    else
    {
        VID_SET_EVENT(VID_EVT_STOP);
    }
}



#if defined(__MED_MJPG_ENC_MOD__)
/*****************************************************************************
 *
 * Motion JPEG Recorder
 *
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  vid_release_recorder_memory
 * DESCRIPTION
 *  Release internal/external memory used in video module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_release_recorder_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RELEASE_RECORDER_MEMORY);    
    
    if (vid_context_p->intmem_start_address)
    {
        med_free_int_mem((void **)&vid_context_p->intmem_start_address);
        vid_context_p->intmem_start_address = NULL;
    }
    
    if (vid_context_p->extmem_start_address)
    {
        med_free_ext_mem((void **)&vid_context_p->extmem_start_address);
        vid_context_p->extmem_start_address = NULL;
    }
    
    if (vid_context_p->file_buffer_address)
    {
        med_free_ext_mem((void **)&vid_context_p->file_buffer_address);
        vid_context_p->file_buffer_address = NULL;
    }
   
    if (vid_context_p->mjpeg_frame_buf_p)
    {
        med_free_ext_mem((void **)&vid_context_p->mjpeg_frame_buf_p);       
        vid_context_p->mjpeg_frame_buf_p = NULL;
    }

    if (vid_context_p->mjpeg_resizer_buf_p)
    {
        med_free_ext_mem((void **)&vid_context_p->mjpeg_resizer_buf_p);
        vid_context_p->mjpeg_resizer_buf_p = NULL;
    }    

    if (vid_context_p->mjpeg_sw_jpg_intmem_buf_p)
    {
        med_free_int_mem((void **)&vid_context_p->mjpeg_sw_jpg_intmem_buf_p);
        vid_context_p->mjpeg_sw_jpg_intmem_buf_p = NULL;
    }

    if (vid_context_p->mjpeg_y_buf_p)
    {
        med_free_int_mem((void **)&vid_context_p->mjpeg_y_buf_p);
        vid_context_p->mjpeg_y_buf_p = NULL;
    }

    if (vid_context_p->mjpeg_u_buf_p)
    {
        med_free_int_mem((void **)&vid_context_p->mjpeg_u_buf_p);
        vid_context_p->mjpeg_u_buf_p = NULL;
    }    

    if (vid_context_p->mjpeg_v_buf_p)
    {
        med_free_int_mem((void **)&vid_context_p->mjpeg_v_buf_p);
        vid_context_p->mjpeg_v_buf_p = NULL;
    }        

}


/*****************************************************************************
 * FUNCTION
 *  vid_stop_camera_preview
 * DESCRIPTION
 *  Stop camera preview.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_camera_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_EXIT_MJPEG_ENCODE_PROCESS);      
    exit_mjpeg_encode_process();
    kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, 0);    

    CAM_ENTER_STATE(CAM_READY);    
}


/*****************************************************************************
 * FUNCTION
 *  vid_start_video_record
 * DESCRIPTION
 *  Start video record.
 * PARAMETERS
 *  void
 * RETURNS
 *  Start record result
 *****************************************************************************/
kal_int32 vid_start_video_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_START_VIDEO_RECORD);   
    
    /* send message to MED_V to start record */
    vid_send_visual_record_req(NULL);
    VID_ENTER_STATE(VID_RECORD);

    if (med_avi_get_cur_file_size() > vid_context_p->file_size_limit)
    {
        result = MED_RES_DISC_FULL;
        goto record_end;
    }

    /* init encode related flags */
    vid_context_p->mjpeg_insert_frame_count = 1;
    vid_context_p->mjpeg_is_jpg_encoding = KAL_FALSE;

    /* start record */
    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MJPEG_ENCODE_START);   
    vid_context_p->mjpeg_prev_frame_time = drv_get_current_time();    
    vid_context_p->mjpeg_is_fps_fixed = KAL_FALSE;
    mjpeg_encode_start();    
    kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, 0);          

    vid_context_p->frame_rate = 0;

    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_GET_MJPEG_FRAME_RATE, __LINE__);                 
    vid_context_p->frame_rate = get_mjpeg_frame_rate();
    kal_trace(TRACE_GROUP_4, VID_TRC_FPS, vid_context_p->frame_rate);          

    if (vid_context_p->rec_drop_frame != 0)
    {
        vid_context_p->frame_rate /= vid_context_p->rec_drop_frame;
        kal_trace(TRACE_GROUP_4, VID_TRC_FPS, vid_context_p->frame_rate);  
    }
    
    /* frame rate from get_mjpeg_frame_rate = fps * 10 */
    ASSERT(vid_context_p->frame_rate != 0);
    med_avi_update_fps(vid_context_p->frame_rate * 100, 1000);

    /* start video first, then start audio */
    if (vid_context_p->record_audio)
    {
        result = vid_record_audio();
    }
    
    VID_RETURN(result);

/* error handling */
record_end:
    /* stop record process */
    vid_stop_video_record();

    vid_stop_camera_preview();
    CAM_ENTER_STATE(CAM_READY);
    
    /* close the file and */
    vid_close_avi_record_file();
    VID_ENTER_STATE(VID_IDLE);
    
    VID_RETURN(result);


}


/*****************************************************************************
 * FUNCTION
 *  vid_mjpeg_encode_event_ind_hdlr
 * DESCRIPTION
 *  Motion Jpeg encode event
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
void vid_mjpeg_encode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mjpeg_encode_ind_struct *encode_p;    
    kal_uint32 file_size = 0;
    jpeg_encode_process_struct sw_jpeg_data;
    kal_uint32 buf_ptr;
    kal_bool is_get_buf;
    kal_int32 insert_frame_count;
    kal_uint8 encode_quality;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_MJPEG_ENCODE_EVENT_IND_HDLR);  
    vid_debug_print_cur_state(__LINE__);
        
    encode_p = (media_mjpeg_encode_ind_struct*)ilm_ptr->local_para_ptr;    

    if (VID_IN_STATE(VID_RECORD))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_FPS, vid_context_p->frame_rate);
        
        if (encode_p->is_update_fps)
        {
            /* update fps */
            med_avi_update_fps(vid_context_p->frame_rate, 1000);
        }       
        
        vid_context_p->mjpeg_is_jpg_encoding = KAL_TRUE;
        insert_frame_count = vid_context_p->mjpeg_insert_frame_count;
        vid_context_p->mjpeg_insert_frame_count = 1;
        ASSERT(insert_frame_count > 0);
        
        kal_trace(TRACE_GROUP_4, VID_TRC_FRAME_COUNT, insert_frame_count);      
        kal_trace(TRACE_GROUP_4, VID_TRC_IS_JPG_ENCODNG, 1);   

        is_get_buf = mjpeg_get_encode_buffer(&buf_ptr);

        switch (vid_context_p->encode_quality)
        {
            case VID_REC_QTY_LOW:
                encode_quality = JPEG_ENCODER_POOR_QUALITY;
                break;

            case VID_REC_QTY_NORMAL:
                encode_quality = JPEG_ENCODER_FAIR_QUALITY;                
                break;

            case VID_REC_QTY_HIGH:
                encode_quality = JPEG_ENCODER_GOOD_QUALITY;                
                break;

            case VID_REC_QTY_FINE:
                encode_quality = JPEG_ENCODER_HIGH_QUALITY;
                break;

            default:
                /* shall not enter here */
                ASSERT(0);
        }

        if (is_get_buf)
        {
            sw_jpeg_data.input_type				    = IMAGE_FORMAT_RGB565;		
            sw_jpeg_data.output_type			    = IMAGE_FORMAT_YUV420;	
            sw_jpeg_data.image_buffer_address	    = buf_ptr;	 
            sw_jpeg_data.jpeg_yuv_data[0]		    = (kal_uint8*)vid_context_p->mjpeg_y_buf_p;
            sw_jpeg_data.jpeg_yuv_size[0]           = vid_context_p->mjpeg_y_buf_size;
            sw_jpeg_data.jpeg_yuv_data[1]		    = (kal_uint8*)vid_context_p->mjpeg_u_buf_p;
            sw_jpeg_data.jpeg_yuv_size[1]           = vid_context_p->mjpeg_u_buf_size;
            sw_jpeg_data.jpeg_yuv_data[2]		    = (kal_uint8*)vid_context_p->mjpeg_v_buf_p;
            sw_jpeg_data.jpeg_yuv_size[2]           = vid_context_p->mjpeg_v_buf_size;
            sw_jpeg_data.intmem_start_address	    = vid_context_p->mjpeg_sw_jpg_intmem_buf_p;
            sw_jpeg_data.intmem_size			    = vid_context_p->mjpeg_sw_jpg_intmem_buf_size;			
            sw_jpeg_data.image_width			    = vid_context_p->image_width; 			
            sw_jpeg_data.image_height			    = vid_context_p->image_height;
            sw_jpeg_data.image_quality			    = encode_quality;		
            sw_jpeg_data.jpeg_file_start_address    = (kal_uint32)vid_context_p->file_buffer_address;	
            sw_jpeg_data.jpeg_file_buffer_size		= vid_context_p->file_size;	

            if(vid_context_p->image_width != vid_context_p->display_width ||
               vid_context_p->image_height != vid_context_p->display_height)
            {
                /* image size not match preview size. need use sw resizer */
                
                /* resize preview size to destination size */
                SWIMG_RESIZE_INFO swimg_resize_para;

                swimg_resize_para.InputType = IMAGE_FORMAT_RGB565;
                swimg_resize_para.OutputType = IMAGE_FORMAT_YUV420;
                swimg_resize_para.uTarWidth = vid_context_p->image_width;
                swimg_resize_para.uTarHeight = vid_context_p->image_height;
                swimg_resize_para.uSrcWidth = vid_context_p->display_width;
                swimg_resize_para.uSrcHeight = vid_context_p->display_height;
                swimg_resize_para.upYOut = (kal_uint8*)vid_context_p->mjpeg_y_buf_p;
                swimg_resize_para.upUOut = (kal_uint8*)vid_context_p->mjpeg_u_buf_p;
                swimg_resize_para.upVOut = (kal_uint8*)vid_context_p->mjpeg_v_buf_p;
                swimg_resize_para.uYSize = vid_context_p->image_width*vid_context_p->image_height;
                swimg_resize_para.uMemStartAddress = vid_context_p->mjpeg_resizer_buf_p;
                swimg_resize_para.uMemSize = vid_context_p->mjpeg_resizer_buf_size;

                if (swimg_fully_resize_init(&swimg_resize_para) != SWIMG_RESIZER_SUCCESS)
                {
                    /* shall never happened */
                    ASSERT (0);
                }

                /* pass rgb data in to resizer */
                swimg_resizer_put_data((void*)buf_ptr);

                swimg_fully_resize_deinit();

                /* after resize -> encode YUV->Jpeg file */
                /* RGB->Jpeg file */
                sw_jpeg_data.input_type				    = IMAGE_FORMAT_YUV420;		
                sw_jpeg_data.output_type			    = IMAGE_FORMAT_YUV420;	
                sw_jpeg_data.image_buffer_address	    = NULL;	 
                sw_jpeg_data.jpeg_yuv_data[0]		    = (kal_uint8*)vid_context_p->mjpeg_y_buf_p;
                sw_jpeg_data.jpeg_yuv_size[0]           = vid_context_p->mjpeg_y_buf_size;
                sw_jpeg_data.jpeg_yuv_data[1]		    = (kal_uint8*)vid_context_p->mjpeg_u_buf_p;
                sw_jpeg_data.jpeg_yuv_size[1]           = vid_context_p->mjpeg_u_buf_size;
                sw_jpeg_data.jpeg_yuv_data[2]		    = (kal_uint8*)vid_context_p->mjpeg_v_buf_p;
                sw_jpeg_data.jpeg_yuv_size[2]           = vid_context_p->mjpeg_v_buf_size;
                sw_jpeg_data.intmem_start_address	    = vid_context_p->mjpeg_sw_jpg_intmem_buf_p;
                sw_jpeg_data.intmem_size			    = vid_context_p->mjpeg_sw_jpg_intmem_buf_size;			
                sw_jpeg_data.image_width			    = vid_context_p->image_width; 			
                sw_jpeg_data.image_height			    = vid_context_p->image_height;
                sw_jpeg_data.image_quality			    = encode_quality;		
                sw_jpeg_data.jpeg_file_start_address    = (kal_uint32)vid_context_p->file_buffer_address;	
                sw_jpeg_data.jpeg_file_buffer_size		= vid_context_p->file_size;	

        	#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
                sw_jpeg_data.memory_output              = KAL_FALSE;
            #endif
                
            }
            else
            {
                /* RGB->Jpeg file */
                sw_jpeg_data.input_type				    = IMAGE_FORMAT_RGB565;		
                sw_jpeg_data.output_type			    = IMAGE_FORMAT_YUV420;	
                sw_jpeg_data.image_buffer_address	    = buf_ptr;	 
                sw_jpeg_data.jpeg_yuv_data[0]		    = (kal_uint8*)vid_context_p->mjpeg_y_buf_p;
                sw_jpeg_data.jpeg_yuv_size[0]           = vid_context_p->mjpeg_y_buf_size;
                sw_jpeg_data.jpeg_yuv_data[1]		    = (kal_uint8*)vid_context_p->mjpeg_u_buf_p;
                sw_jpeg_data.jpeg_yuv_size[1]           = vid_context_p->mjpeg_u_buf_size;
                sw_jpeg_data.jpeg_yuv_data[2]		    = (kal_uint8*)vid_context_p->mjpeg_v_buf_p;
                sw_jpeg_data.jpeg_yuv_size[2]           = vid_context_p->mjpeg_v_buf_size;
                sw_jpeg_data.intmem_start_address	    = vid_context_p->mjpeg_sw_jpg_intmem_buf_p;
                sw_jpeg_data.intmem_size			    = vid_context_p->mjpeg_sw_jpg_intmem_buf_size;			
                sw_jpeg_data.image_width			    = vid_context_p->image_width; 			
                sw_jpeg_data.image_height			    = vid_context_p->image_height;
                sw_jpeg_data.image_quality			    = encode_quality;		
                sw_jpeg_data.jpeg_file_start_address    = (kal_uint32)vid_context_p->file_buffer_address;	
                sw_jpeg_data.jpeg_file_buffer_size		= vid_context_p->file_size;	

        	#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
                sw_jpeg_data.memory_output              = KAL_FALSE;
            #endif

            }

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_JPEG_ENCODE_PROCESS, __LINE__);  
            
            #if defined(__SW_JPEG_CODEC_SUPPORT__)
            {
                kal_uint32 stack_begin;
                med_get_med_int_stack_mem(&stack_begin);
            
           #if defined(__MTK_TARGET__)
                /* switch stack only avaialbe on target */
                file_size = (kal_uint32)INT_SwitchStackToRun(
                                (void*)stack_begin,
                                MED_INT_STACK_MEM_SIZE,
                                (kal_func_ptr)jpeg_encode_process, 
                                1, /* 1 arg */
                                &sw_jpeg_data);
            #else /* __MTK_TARGET__ */
                file_size = jpeg_encode_process(&sw_jpeg_data);
            #endif /* __MTK_TARGET__ */

                med_free_med_int_stack_mem();
            }
            #else /* __SW_JPEG_CODEC_SUPPORT__ */
                ASSERT(0);
            #endif /* __SW_JPEG_CODEC_SUPPORT__ */

            kal_trace(TRACE_GROUP_4, VID_TRC_FILE_SIZE, file_size);              

            if (file_size > 0)
            {
                while(insert_frame_count)
                {
                    if (file_size + med_avi_get_cur_file_size() > vid_context_p->file_size_limit)
                    {
                        vid_context_p->error_code = MED_RES_DISC_FULL;
                        med_debug_print_result(vid_context_p->error_code, __LINE__);
                        goto enc_event_error_out;
                    }

                    /* reach record size/time limit */
                    if (med_avi_is_reach_record_limit())
                    {
                        vid_context_p->error_code = MED_RES_END_OF_FILE;
                        med_debug_print_result(vid_context_p->error_code, __LINE__);                        
                        goto enc_event_error_out;
                    }

                    if (med_avi_is_active_data_buf_sufficient(file_size) != MED_RES_OK)
                    {
                        if(med_avi_toggle_data_buffer() != MED_RES_OK)
                        {
                            vid_context_p->error_code = MED_RES_BUSY;
                            goto enc_event_error_out;                
                        }
                        
                        vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_DATA);
                    }

                    if (med_avi_is_active_idx_buf_sufficient() != MED_RES_OK)
                    {
                        if(med_avi_toggle_idx_buffer() != MED_RES_OK)
                        {
                            vid_context_p->error_code = MED_RES_BUSY;
                            goto enc_event_error_out;                
                        }
                        
                        vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_IDX);
                    }

                    med_avi_write_video_frame((kal_char*) vid_context_p->file_buffer_address, file_size);

                    insert_frame_count--;
                }
            }
            else
            {
                /* encode faild */
                vid_context_p->error_code = MED_RES_FAIL;
                med_debug_print_result(vid_context_p->error_code, __LINE__); 
                goto enc_event_error_out;
                
            }
        }
        else
        {
            /* error */
            vid_context_p->error_code = MED_RES_FAIL;            
            med_debug_print_result(vid_context_p->error_code, __LINE__); 
            goto enc_event_error_out;
        }
        
        vid_context_p->mjpeg_is_jpg_encoding = KAL_FALSE;

        kal_trace(TRACE_GROUP_4, VID_TRC_IS_JPG_ENCODNG, 0);   
  
    }
   
    return;

enc_event_error_out:
    {
        vid_context_p->mjpeg_is_jpg_encoding = KAL_FALSE;
    }

    vid_stop_video_record();
    vid_stop_camera_preview();

    /* notify med_v to dump remained data */
    vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_TERMINATE);
    
    vid_send_visual_stop_req(NULL);
    VID_ENTER_STATE(VID_RECORD_FINISH);
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_stop_video_record
 * DESCRIPTION
 *  Stop video Record.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_video_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_VIDEO_RECORD);     
    vid_debug_print_cur_state(__LINE__);
    
    if (VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_PAUSED))
    {
        if (vid_context_p->record_audio)
        {
            vid_stop_audio_record();

            /* write audio twich, to flush all buffer in double buffer */
            vid_write_audio();
            vid_write_audio();
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_pause_video_record
 * DESCRIPTION
 *  Pause video record.
 * PARAMETERS
 *  void
 * RETURNS
 *  Pause video record result
 *****************************************************************************/
kal_int32 vid_pause_video_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PAUSE_VIDEO_RECORD);     
    vid_debug_print_cur_state(__LINE__);    
    
    if (VID_IN_STATE(VID_RECORD))
    {
        kal_int16 result = MED_RES_OK;

        if (vid_context_p->record_audio && VID_AUD_IN_STATE(VID_AUD_RECORD))
        {
            Media_Status status;

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_PAUSE); 
            status = Media_Pause();
            aud_debug_print_aud_drv_return(status, __LINE__);

            /* store the audio data from ring buffer to file */
            /* write audio twich, to flush all buffer in double buffer */
            vid_write_audio();
            vid_write_audio();

            if (status == MEDIA_SUCCESS)
            {
                VID_AUD_ENTER_STATE(VID_AUD_RECORD_PAUSED);
            }
            else
            {
                VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            }
            result = aud_get_res((kal_uint8) status);
        }

        if (result == MED_RES_OK)
        {
            /* pause record */
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MJPG_ENCODE_PAUSE, __LINE__);             
            mjpeg_encode_pause();
            kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);             
            
            VID_ENTER_STATE(VID_RECORD_PAUSED);
        }
        else
        {
            /* stop record process */
            vid_stop_video_record();

            /* stop camera preview */
            vid_stop_camera_preview();
            CAM_ENTER_STATE(CAM_READY);
            
            /* close the file */
            vid_close_avi_record_file();
            VID_ENTER_STATE(VID_IDLE);
        }

        VID_RETURN(result);
    }
    else
    {
        VID_RETURN(MED_RES_BUSY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_resume_video_record
 * DESCRIPTION
 *  Resume video record.
 * PARAMETERS
 *  void
 * RETURNS
 *  Resume video record result
 *****************************************************************************/
kal_int32 vid_resume_video_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RESUME_VIDEO_RECORD);      
    vid_debug_print_cur_state(__LINE__);
   
    
    if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        /* start encode */
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MJPG_ENCODE_RESUME, __LINE__);             
        mjpeg_encode_resume();
        kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);              
        
        VID_ENTER_STATE(VID_RECORD);

        if (vid_context_p->record_audio && VID_AUD_IN_STATE(VID_AUD_RECORD_PAUSED))
        {
            Media_Status status;

            /* start to record */
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_RESUME, __LINE__);              
            status = Media_Resume();
            aud_debug_print_aud_drv_return(status, __LINE__);

            if (status == MEDIA_SUCCESS)
            {
                VID_AUD_ENTER_STATE(VID_AUD_RECORD);
            }
            else
            {
                VID_AUD_ENTER_STATE(VID_AUD_IDLE);
            }
            result = aud_get_res((kal_uint8) status);
        }

        if (result != MED_RES_OK)
        {
            /* stop record process */
            vid_stop_video_record();
            
            vid_stop_camera_preview();
            CAM_ENTER_STATE(CAM_READY);
            
            /* close the file and */
            vid_close_avi_record_file();
            VID_ENTER_STATE(VID_IDLE);

        }
        VID_RETURN(result);
    }
    else
    {
        VID_RETURN(MED_RES_BUSY);
    }

}



/*****************************************************************************
 * FUNCTION
 *  vid_record_req_hdlr
 * DESCRIPTION
 *  Handle video record request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_record_req_struct *req_p;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RECORD_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_record_req_struct*) ilm_ptr->local_para_ptr;

    vid_stop_unfinished_audio();

    vid_context_p->seq_num = req_p->seq_num;

    if (VID_IN_STATE(VID_PREVIEW))
    {
        vid_context_p->media_mode = req_p->media_mode;
        vid_context_p->encode_quality = req_p->encode_quality;

        switch (vid_context_p->encode_quality)
        {
            case VID_REC_QTY_LOW:
                vid_context_p->rec_drop_frame = 2; /* drop 1 frame each 2 frames */
                vid_context_p->rec_drop_counter = 0;
                break;

            case VID_REC_QTY_NORMAL:
                vid_context_p->rec_drop_frame = 0; /* do not drop frame */
                vid_context_p->rec_drop_counter = 0;
                break;

            case VID_REC_QTY_HIGH:
                vid_context_p->rec_drop_frame = 0; /* do not drop frame */
                vid_context_p->rec_drop_counter = 0;             
                break;

            case VID_REC_QTY_FINE:
                vid_context_p->rec_drop_frame = 0; /* do not drop frame */
                vid_context_p->rec_drop_counter = 0;
                break;

            default:
                /* shall not enter here */
                ASSERT(0);
        }

        
        vid_context_p->record_audio = req_p->record_audio;

        /* init */
        vid_context_p->frame_rate = 0;
        vid_context_p->period = 0;
        vid_context_p->total_frame_num = 0;
        vid_context_p->current_frame_num = 0;

        if (req_p->media_mode == MED_MODE_FILE)
        {
            if ((result = vid_save_file_path(req_p->data)) != MED_RES_OK)
            {
                vid_set_result(result, __LINE__);
            }
            else
            {
                if ((result = vid_open_avi_record_file((kal_wchar*) req_p->data)) == MED_RES_OK)
                {
                    if (vid_context_p->file_buffer_address == NULL)
                    {
                        /* insufficient memory */
                        ASSERT(0);
                    }
                    else
                    {
                        result = vid_start_video_record();
                    }
                    vid_set_result(result, __LINE__);
                }
                else
                {
                    vid_set_result(result, __LINE__);
                }
            }
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

    VID_SET_EVENT(VID_EVT_RECORD);
	
}


/*****************************************************************************
 * FUNCTION
 *  vid_preview_req_hdlr
 * DESCRIPTION
 *  Preview request handler for MT6225 + YUV sensor
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_preview_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_preview_req_struct *req_p;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PREVIEW_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
        
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (CAM_IN_STATE(CAM_READY))
    {
        req_p = (media_vid_preview_req_struct*)ilm_ptr->local_para_ptr;        
        
        /* EXTERNAL MEMORY */
        /********************************************************
         * frame buffer          :  176 x 144 x 2 = 50688
         * jpg file buffer       :  70 x 1024 = 71680    
         * resize working buffer :  define by driver
         ********************************************************/
        
        /* INTERNAL MEMORY */
        /********************************************************
         * vid drv working buffer :  176 x 8(line) x 3 = 4224 
         * sw jpg working buffer  :  3 x 1024 = 3072 
         * sw encode y buffer     :  176 x 144 = 25344        
         * sw encode u buffer     :  176 x 144 / 4 = 6336                
         * sw encode v buffer     :  176 x 144 / 4 = 6336            
         ********************************************************/

        /* our memory can only support record size smaller than 176x144 */
#if !defined(TV_RECORD_SUPPORT)		
        ASSERT(req_p->image_width <= 176);
#endif
        
        /* buf for video record */
        vid_context_p->intmem_start_address = (kal_uint32)med_alloc_int_mem(176 * 8 * 3); /* internal 4k */
        mjpeg_encode.intmem_start_address = vid_context_p->intmem_start_address;
        mjpeg_encode.intmem_size = mjpeg_record_int_mem;
        ASSERT(vid_context_p->intmem_start_address != NULL);

        /* do not need extmem working buffer */            
        vid_context_p->extmem_start_address = NULL; /* do not need external */
        mjpeg_encode.extmem_start_address = NULL;
        mjpeg_encode.extmem_size = 0;

        vid_context_p->mjpeg_frame_buf_size = req_p->image_buffer_size;
        vid_context_p->mjpeg_frame_buf_p 
            = (kal_uint32)med_alloc_ext_mem(vid_context_p->mjpeg_frame_buf_size);
        ASSERT(vid_context_p->mjpeg_frame_buf_p != NULL);

        /* buffer for SW jpeg encode */
        vid_context_p->file_size = 70 * 1024;   /* external: 70K */
        vid_context_p->file_buffer_address = (kal_uint32)med_alloc_ext_mem(vid_context_p->file_size);
        ASSERT(vid_context_p->file_buffer_address != NULL);        

        vid_context_p->mjpeg_sw_jpg_intmem_buf_size = 3 * 1024;   /* internal: 3K */
        vid_context_p->mjpeg_sw_jpg_intmem_buf_p 
            = (kal_uint32)med_alloc_int_mem(vid_context_p->mjpeg_sw_jpg_intmem_buf_size);
        ASSERT(vid_context_p->mjpeg_sw_jpg_intmem_buf_p != NULL);        

        if (req_p->image_width != req_p->preview_width || 
            req_p->image_height != req_p->preview_height)
        {
            /* preview size not match record size, need use sw resizer */
            vid_context_p->mjpeg_resizer_buf_size = swimg_get_require_mem_size(req_p->image_width ,req_p->image_height);
            vid_context_p->mjpeg_resizer_buf_p = (kal_uint32)med_alloc_ext_mem(vid_context_p->mjpeg_resizer_buf_size);
            ASSERT(vid_context_p->mjpeg_resizer_buf_p != NULL);        
        }
        else
        {
            vid_context_p->mjpeg_resizer_buf_size = 0;
            vid_context_p->mjpeg_resizer_buf_p = NULL;
        }
        
        /* internal 38k */
        vid_context_p->mjpeg_y_buf_size = 176 * 144;        
        vid_context_p->mjpeg_y_buf_p = (kal_uint32)med_alloc_int_mem(vid_context_p->mjpeg_y_buf_size);

        vid_context_p->mjpeg_u_buf_size = 176 * 144 / 4;    
        vid_context_p->mjpeg_u_buf_p = (kal_uint32)med_alloc_int_mem(vid_context_p->mjpeg_u_buf_size);

        vid_context_p->mjpeg_v_buf_size = 176 * 144 / 4;            
        vid_context_p->mjpeg_v_buf_p = (kal_uint32)med_alloc_int_mem(vid_context_p->mjpeg_v_buf_size);

        /* TODO: check record size allocate memory size */
         
        ASSERT(vid_context_p->mjpeg_y_buf_p != NULL);        
        ASSERT(vid_context_p->mjpeg_u_buf_p != NULL);     
        ASSERT(vid_context_p->mjpeg_v_buf_p != NULL);  

        /* record size */
        vid_context_p->image_width = req_p->image_width;
        vid_context_p->image_height = req_p->image_height;        

        /* preview size */
        vid_context_p->display_width= req_p->preview_width;
        vid_context_p->display_height= req_p->preview_height;

        /* output size is the same as preview size */
        mjpeg_encode.source_width = req_p->preview_width;
        mjpeg_encode.source_height = req_p->preview_height;
        mjpeg_encode.target_width = req_p->preview_width;
        mjpeg_encode.target_height = req_p->preview_height;

        mjpeg_encode.lcd_id = req_p->lcd_id;
        mjpeg_encode.lcm_start_x = req_p->lcd_start_x;
        mjpeg_encode.lcm_start_y = req_p->lcd_start_y;
        mjpeg_encode.lcm_end_x = req_p->lcd_end_x;
        mjpeg_encode.lcm_end_y = req_p->lcd_end_y;
        mjpeg_encode.roi_offset_x = req_p->roi_offset_x;
        mjpeg_encode.roi_offset_y = req_p->roi_offset_y;
        mjpeg_encode.update_layer = req_p->update_layer;
        mjpeg_encode.hw_update_layer = req_p->hw_update_layer;
        mjpeg_encode.lcd_update = req_p->lcd_update;
        mjpeg_encode.rotate_value = (kal_uint8)req_p->lcd_rotate;

        mjpeg_encode.frame_buffer_address = (kal_uint32)req_p->image_buffer_p;
        mjpeg_encode.frame_buffer_size = req_p->image_buffer_size;

        mjpeg_encode.frame_buffer_address1 = (kal_uint32)vid_context_p->mjpeg_frame_buf_p;
        mjpeg_encode.frame_buffer_size1 = vid_context_p->mjpeg_frame_buf_size;

        mjpeg_encode.image_mirror = cam_rotate_map[req_p->rotate];
        mjpeg_encode.zoom_factor = (kal_uint8) req_p->zoom_factor;
        mjpeg_encode.contrast_level = req_p->contrast;
        mjpeg_encode.brightness_level = req_p->brightness;
        mjpeg_encode.saturation_value = req_p->saturation;
        mjpeg_encode.wb_mode = req_p->WB;
        mjpeg_encode.ev_value = req_p->exposure;
        mjpeg_encode.banding_freq = req_p->banding_freq;
        mjpeg_encode.image_effect = req_p->effect;
        mjpeg_encode.night_mode = req_p->night_mode;
        mjpeg_encode.hue_value = 0;    /* hardcoded */ 
        mjpeg_encode.mjpeg_encode_cb = vid_send_mjpeg_encode_ind;

        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MJPEG_ENCODE_PROCESS, __LINE__);         
        ret = mjpeg_encode_process(&mjpeg_encode);
        kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, ret); 
        
        if (ret)
        {
            /* true mean preview start successfully */
            vid_set_result(MED_RES_OK, __LINE__);
            VID_ENTER_STATE(VID_PREVIEW);
            VID_SET_EVENT(VID_EVT_PREVIEW);               
        }
        else
        {
            vid_release_recorder_memory();
            vid_set_result(MED_RES_FAIL, __LINE__);
            VID_SET_EVENT(VID_EVT_PREVIEW);            
        }
    }
    else
    {
        vid_release_recorder_memory();
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_PREVIEW);        
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_save_file_path
 * DESCRIPTION
 *  Save file path for further use.
 * PARAMETERS
 *  path        [IN]     File path
 * RETURNS
 *  Save file path result
 *****************************************************************************/
kal_int32 vid_save_file_path(kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SAVE_FILE_PATH);    
    
    FS_Rename((kal_wchar*) VID_DUMMY_INIT_FILE, (kal_wchar*) VID_INIT_FILE);
    fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_CREATE | FS_READ_WRITE);

    if (fd >= 0)
    {
        result = FS_Write(fd, path, (kal_wstrlen(path) + 1) * ENCODE_BYTE, &len);
        FS_Close(fd);
        
        if (result == FS_NO_ERROR)
        {
            VID_RETURN(MED_RES_OK);
        }
        else
        {
            VID_RETURN(MED_RES_OPEN_FILE_FAIL);
        }
    }
    else
    {
        VID_RETURN(MED_RES_OPEN_FILE_FAIL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_get_disc_free_space
 * DESCRIPTION
 *  Get free disk space
 * PARAMETERS
 *  dir_name        [IN]     directory
 *  free            [OUT]    free  space
 * RETURNS
 *  Get space result
 *****************************************************************************/
kal_uint16 vid_get_disc_free_space(kal_wchar *dir_name, kal_uint64 *free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo disc_info;
    kal_wchar dir[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_DISC_FREE_SPACE);
    
    kal_mem_set(dir, 0, 6);
    kal_mem_cpy(dir, dir_name, 4);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (result > 0 && result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
    {
        *free = disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector;

        kal_trace(                                                      
            TRACE_GROUP_4,                                              
            VID_TRC_DISC_FREE_SPACE,                                    
            disc_info.FreeClusters,                                     
            disc_info.SectorsPerCluster * disc_info.BytesPerSector,     
            *free,                                                      
            __LINE__); 
        
        VID_RETURN(MED_RES_OK);
    }
    else
    {
        VID_RETURN(MED_RES_NO_DISC);
    }
}





/*****************************************************************************
 * FUNCTION
 *  vid_audio_record_callback
 * DESCRIPTION
 *  Callback of audio record.
 * PARAMETERS
 *  event       [IN]       record audio event
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_record_callback(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_RECORD_CALLBACK, event);   

    switch (event)
    {
        case MEDIA_TERMINATED:
        case MEDIA_ERROR:
        case MEDIA_END:
        {
            aud_media_read_data_ind_struct *ind_p = NULL;

            ind_p = (aud_media_read_data_ind_struct*)
                construct_local_para(sizeof(aud_media_read_data_ind_struct), TD_CTRL);

            ind_p->event = event;

            aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_READ_DATA_IND, ind_p, NULL);
            break;
        }
        
        case MEDIA_DATA_NOTIFICATION:
        {
           if (!aud_context_p->processing_data)
            {
                aud_media_read_data_ind_struct *ind_p = NULL;

                ind_p = (aud_media_read_data_ind_struct*)
                    construct_local_para(sizeof(aud_media_read_data_ind_struct), TD_CTRL);

                ind_p->event = event;

                aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_READ_DATA_IND, ind_p, NULL);
                aud_context_p->processing_data = KAL_TRUE;
            }
            break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  vid_write_audio
 * DESCRIPTION
 *  Write audio
 * PARAMETERS
 *  void
 * RETURNS
 *  Write audio result
 *****************************************************************************/
kal_int32 vid_write_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 audio_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_WRITE_AUDIO);  
    
    Media_GetReadBuffer((kal_uint16**)&(vid_context_p->audio_buf_p), (kal_uint32*)&(vid_context_p->audio_buf_len));
    kal_trace(TRACE_GROUP_4, VID_TRC_BUFFER_LEN, vid_context_p->audio_buf_len);  

    if (vid_context_p->audio_buf_len == 0)
    {
        VID_RETURN(MED_RES_FAIL);
    }

    audio_data = vid_context_p->audio_buf_len * 2;    /* 16 bit per sample */

    /* Check if reach size limit */
    if (audio_data + med_avi_get_cur_file_size() > vid_context_p->file_size_limit)
    {
        vid_stop_audio_record();
        VID_RETURN(MED_RES_DISC_FULL);
    }

    if (med_avi_is_active_data_buf_sufficient(audio_data) != MED_RES_OK)
    {
        if(med_avi_toggle_data_buffer() != MED_RES_OK)
        {
            VID_RETURN(MED_RES_BUSY);          
        }
        
        vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_DATA);
    }

    if (med_avi_is_active_idx_buf_sufficient() != MED_RES_OK)
    {
        if(med_avi_toggle_idx_buffer() != MED_RES_OK)
        {
            VID_RETURN(MED_RES_BUSY);          
        }
        
        vid_send_encode_visual_data_ind(MED_AVI_SAVE_TYPE_IDX);
    }

    med_avi_write_audio_data((kal_char*) vid_context_p->audio_buf_p, audio_data);

    Media_ReadDataDone(vid_context_p->audio_buf_len);

    VID_RETURN(MED_RES_OK);
}


#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add it 
extern int GetAnalogTvAppFlags(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  vid_record_audio
 * DESCRIPTION
 *  Record audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  Record audio result
 *****************************************************************************/
kal_int32 vid_record_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RECORD_AUDIO);  
    
    aud_context_p->processing_data = KAL_FALSE;    
    vid_context_p->audio_buf_p = (kal_uint8*)aud_context_p->ring_buf;
    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);

    Media_SetRBThreshold(AUD_RING_BUFFER_LEN / 2);

#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add it 
	if(GetAnalogTvAppFlags() == 0)
	{
			//when Record Tv ........
                    L1SP_SetInputSource(custom_cfg_hw_aud_input_path(2/* AUDIO_DEVICE_FMRR */));
                    aud_context_p->use_default_input = KAL_FALSE;
	}
#endif

    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_RECORD); 
    status = Media_Record(MED_TYPE_PCM_8K, vid_audio_record_callback, NULL);
    aud_debug_print_aud_drv_return(status, __LINE__);

    if (status == MEDIA_SUCCESS)
    {
        VID_AUD_ENTER_STATE(VID_AUD_RECORD);
    }

    VID_RETURN(aud_get_res((kal_uint8)status));
}




/*****************************************************************************
 * FUNCTION
 *  vid_open_avi_record_file
 * DESCRIPTION
 *  Open avi file for record
 * PARAMETERS
 *  file_name       [IN]     file name
 * RETURNS
 *  Open file result
 *****************************************************************************/
kal_int32 vid_open_avi_record_file(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    med_avi_rec_struct rec_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_AVI_RECORD_FILE);   
    
    kal_mem_cpy(vid_context_p->storing_path, file_name, MAX_FILE_NAME_LEN * ENCODE_BYTE);

    if ((result = vid_get_disc_free_space(
                    (kal_wchar*) vid_context_p->storing_path,
                    &vid_context_p->file_size_limit)) != MED_RES_OK)
    {
        VID_RETURN(MED_RES_FSAL_ERROR);
    }

    if (vid_context_p->file_size_limit < 
            VIDEO_RECORD_MEM_MARGIN + 
            MIN_VIDEO_FILE_SIZE + 
            med_avi_get_data_buf_size() + 
            med_avi_get_idx_buf_size())
    {
        VID_RETURN(MED_RES_DISC_FULL);
    }

    vid_context_p->file_size_limit -= VIDEO_RECORD_MEM_MARGIN;
    vid_context_p->file_size_limit -= med_avi_get_data_buf_size();
    vid_context_p->file_size_limit -= med_avi_get_idx_buf_size();    

    /* actaul FPS has to get after encode process starts */
    vid_context_p->frame_rate = 10;

    rec_data.vid_width = vid_context_p->image_width;
    rec_data.vid_height = vid_context_p->image_height;

    rec_data.vid_rate = vid_context_p->frame_rate * 1000;
    rec_data.vid_scale = 1000;

    rec_data.aud_bit_per_sample = 16;
    rec_data.aud_channel = 1;
    rec_data.aud_format = MED_AVI_AUD_FORMAT_PCM;
    rec_data.aud_sample_rate = 8000;

    result = med_avi_open_record_file(&rec_data, file_name);
    
    if (result != MED_RES_OK)
    {
        VID_RETURN(result);
    }
    else
    {
        /* store file name in global context */
        kal_mem_cpy(vid_context_p->current_file_name, file_name, MAX_FILE_NAME_LEN * ENCODE_BYTE);
        VID_RETURN(MED_RES_OK);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_close_avi_record_file
 * DESCRIPTION
 *  Close the recorded video clip file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Close avi file result
 *****************************************************************************/
kal_int32 vid_close_avi_record_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 res = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_AVI_RECORD_FILE);       
    
    med_avi_close_record_file();
    VID_RETURN(res);
}



/*****************************************************************************
 * FUNCTION
 *  vid_visual_record_cnf_hdlr
 * DESCRIPTION
 *  Handle visual record confirm message from media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_record_cnf_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}



/*****************************************************************************
 * FUNCTION
 *  vid_visual_record_finish_ind_hdlr
 * DESCRIPTION
 *  Handle visual record finish indication message from media-v task.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_record_finish_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_record_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_RECORD_FINISH_IND_HDLR);    
    vid_debug_print_cur_state(__LINE__);
    
    ind_p = (media_visual_record_finish_ind_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD) || VID_IN_STATE(VID_RECORD_FINISH))
    {
        vid_stop_video_record();
        vid_stop_camera_preview();
        vid_release_recorder_memory();

        vid_close_avi_record_file();

        VID_ENTER_STATE(VID_IDLE);
        vid_send_record_finish_ind(MED_RES_DISC_FULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_pause_req_hdlr
 * DESCRIPTION
 *  Handle video pause request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_pause_req_struct *req_p;
    kal_int32 vid_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PAUSE_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    req_p = (media_vid_pause_req_struct*) ilm_ptr->local_para_ptr;
   
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_RECORD))
    {
        vid_ret = vid_pause_video_record();

        vid_context_p->is_preview_stopped = KAL_FALSE;
        
        if (vid_ret == MED_RES_OK)
        {
            if (req_p->stop_preview)
            {
                vid_stop_camera_preview();
                vid_context_p->is_preview_stopped = KAL_TRUE;
            }
        }

        vid_set_result((kal_int32)vid_ret, __LINE__);
        VID_SET_EVENT(VID_EVT_PAUSE);
    }
    else
    {
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_PAUSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_resume_req_hdlr
 * DESCRIPTION
 *  Handle video resume request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_resume_req_struct *req_p;
    kal_int32 vid_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RESUME_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_resume_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD_PAUSED))
    {
        if(vid_context_p->is_preview_stopped)
        {
            kal_int32 mjpg_ret;            
            mjpg_ret = mjpeg_encode_process(&mjpeg_encode);
            kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, mjpg_ret);             
        }
        
        vid_ret = vid_resume_video_record();
        vid_set_result((kal_int32)vid_ret, __LINE__);
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

    VID_SET_EVENT(VID_EVT_RESUME);
}


/*****************************************************************************
 * FUNCTION
 *  vid_clean_temp_files
 * DESCRIPTION
 *  Clean temp files after file merge failed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_clean_temp_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 len;
    kal_int32 result;
    kal_uint32 init_file_size;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLEAN_TMP_FILES);  
    
    FS_CheckFile(VID_INIT_FILE);
    fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_READ_ONLY);
    
    if (fd >= 0)
    {
        fs_ret = FS_GetFileSize(fd, &init_file_size);

        if ((init_file_size > 0) && (fs_ret >= 0))
        {
            result = FS_Read(fd, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE, &len);
            FS_Close(fd);            
        }
        else
        {
            FS_Close(fd);            
            return;
        }
    }
    
    FS_Rename((kal_wchar*) VID_INIT_FILE, (kal_wchar*) VID_DUMMY_INIT_FILE);
    FS_Delete((kal_wchar*) VID_INIT_FILE);

    if (kal_wstrlen(vid_context_p->storing_path) < 3)
    {
        return;
    }

    med_remove_file_name(vid_context_p->storing_path);
    med_avi_clean_tmp_files(vid_context_p->storing_path);

}


/*****************************************************************************
 * FUNCTION
 *  vid_check_unfinished_file
 * DESCRIPTION
 *  Check unfinished video recording file.
 * PARAMETERS
 *  void
 * RETURNS
 *  Has unfinished file or not
 *****************************************************************************/
kal_bool vid_check_unfinished_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 init_file_size;
    kal_uint32 len;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_UNFINISHED_FILE);    
    
    fd = FS_Open((kal_wchar*)VID_INIT_FILE, FS_READ_ONLY);
    
    if (fd >= 0)
    {
        fs_ret = FS_GetFileSize(fd, &init_file_size);
        VID_VALUE_TRACE(fs_ret, init_file_size, __LINE__);
          
        if ((init_file_size > 0) && (fs_ret >= 0))
        {
            /* no error */
            fs_ret = FS_Read(fd, vid_context_p->storing_path, MAX_FILE_NAME_LEN * ENCODE_BYTE, &len);

            FS_Close(fd);      
            
            if (kal_wstrcmp(vid_context_p->current_file_name, vid_context_p->storing_path) != 0)
            {
                /* 
                 * string not match, means power down and power up again, 
                 * avi cant save due to global context is cleared 
                 */

                med_remove_file_name(vid_context_p->storing_path);
                med_avi_clean_tmp_files(vid_context_p->storing_path);
                return KAL_FALSE;
            }
        }
        else
        {
            /* has error */
            FS_Close(fd);
            fd = FS_CheckFile(VID_INIT_FILE);
            return KAL_FALSE;
        }
    }
    else
    {
        fd = FS_CheckFile(VID_INIT_FILE);
        return KAL_FALSE;
    }

    if (kal_wstrlen(vid_context_p->storing_path) < 3)
    {
        return KAL_FALSE;
    }

    med_remove_file_name(vid_context_p->storing_path);
    return med_avi_has_unsaved_file(vid_context_p->storing_path);

}


/*****************************************************************************
 * FUNCTION
 *  vid_file_merge_req_hdlr
 * DESCRIPTION
 *  Handle video file merge request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_file_merge_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_FILE_MERGE_REQ_HDLR);      
    vid_debug_print_cur_state(__LINE__);

    med_avi_merge_result(vid_context_p->current_file_name);
    
    VID_SET_EVENT(VID_EVT_FILE_MERGE);
    vid_send_file_merge_done_ind(MED_RES_OK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_update_blt_pause_req_hdlr
 * DESCRIPTION
 *  Pause for update video blt parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_blt_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_pause_req_struct *req_p;
    kal_int32 vid_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_PAUSE_REQ_HDLR);     
    vid_debug_print_cur_state(__LINE__);
    
    req_p = (media_vid_update_blt_pause_req_struct*)ilm_ptr->local_para_ptr;
 
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    if (VID_IN_STATE(VID_RECORD))
    {
        vid_ret = vid_pause_video_record();

        if (vid_ret == MED_RES_OK)
        {
            vid_stop_camera_preview();
        }

        VID_ENTER_STATE(VID_RECORD_UPDATE_BLT_PAUSED);
        vid_set_result((kal_int32)vid_ret, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);          
        return; 
    }
    else if (VID_IN_STATE(VID_RECORD_PAUSED) ||
             VID_IN_STATE(VID_PREVIEW))
    {
        /* stop camear */
        vid_stop_camera_preview();

        /* no error happened */
        vid_set_result(MED_RES_OK, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
        return;
        
    }
    else
    {
        /* calling in wrong state */
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);
        return;
    }    

}



/*****************************************************************************
 * FUNCTION
 *  vid_update_blt_resume_req_hdlr
 * DESCRIPTION
 *  Resume for update video blt parameter for video recroding
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_update_blt_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_update_blt_resume_req_struct *req_p;
    kal_int32 vid_ret;
    kal_int32 mjpg_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_UPDATE_BLT_RESUME_REQ_HDLR);     
    vid_debug_print_cur_state(__LINE__);

    req_p = (media_vid_update_blt_resume_req_struct*)ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_RECORD_UPDATE_BLT_PAUSED) ||
        VID_IN_STATE(VID_RECORD_PAUSED) ||
        VID_IN_STATE(VID_PREVIEW))
    {
        vid_context_p->src_mod = ilm_ptr->src_mod_id;
        vid_context_p->display_width= req_p->preview_width;
        vid_context_p->display_height= req_p->preview_height;
        mjpeg_encode.target_width = req_p->preview_width;
        mjpeg_encode.target_height = req_p->preview_height;
        mjpeg_encode.lcd_id = req_p->lcd_id;
        mjpeg_encode.lcm_start_x = req_p->lcd_start_x;
        mjpeg_encode.lcm_start_y = req_p->lcd_start_y;
        mjpeg_encode.lcm_end_x = req_p->lcd_end_x;
        mjpeg_encode.lcm_end_y = req_p->lcd_end_y;
        mjpeg_encode.roi_offset_x = req_p->roi_offset_x;
        mjpeg_encode.roi_offset_y = req_p->roi_offset_y;
        mjpeg_encode.update_layer = req_p->update_layer;
        mjpeg_encode.hw_update_layer = req_p->hw_update_layer;
        mjpeg_encode.lcd_update = req_p->lcd_update;
        mjpeg_encode.rotate_value = (kal_uint8)req_p->lcd_rotate;
        mjpeg_encode.frame_buffer_address = (kal_uint32)req_p->image_buffer_p;
        mjpeg_encode.frame_buffer_size = req_p->image_buffer_size;
        mjpeg_encode.image_mirror = cam_rotate_map[req_p->rotate];

        if (VID_IN_STATE(VID_RECORD_UPDATE_BLT_PAUSED))
        {
            mjpg_ret = mjpeg_encode_process(&mjpeg_encode);
            kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, mjpg_ret);             

            /* TRICKY!, vid_resume_video_record() only works in VID_RECORD_PAUSED state */
            VID_ENTER_STATE(VID_RECORD_PAUSED);
            vid_ret = vid_resume_video_record();
            vid_set_result((kal_int32)vid_ret, __LINE__);            
            VID_SET_EVENT(VID_EVT_BLOCK);            
        }
        else
        {
            mjpg_ret = mjpeg_encode_process(&mjpeg_encode);
            kal_trace(TRACE_GROUP_4, VID_TRC_DRIVER_RET, mjpg_ret);     

            if (mjpg_ret)
            {
                vid_set_result((kal_int32)MED_RES_OK, __LINE__);                        
            }
            else
            {
                vid_set_result((kal_int32)MED_RES_FAIL, __LINE__);                        
            }
            VID_SET_EVENT(VID_EVT_BLOCK);                
        }

    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_BLOCK);        
    }


}

#endif /* __MED_MJPG_ENC_MOD__ */




/*****************************************************************************
 *
 * Motion JPEG Player
 *
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  vid_stop_audio
 * DESCRIPTION
 *  Stop audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_AUDIO_PLAY);      
    
    if (vid_context_p->play_audio)
    {
        if (VID_AUD_IN_STATE(VID_AUD_PLAY_NORMAL))
        {
            aud_context_p->processing_data = KAL_FALSE;

            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);                     
            vid_context_p->mhdl_handle->Stop(vid_context_p->mhdl_handle);          
            VID_AUD_ENTER_STATE(VID_AUD_IDLE);
        }
    }

    /* close audio handle */
    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
        vid_context_p->mhdl_handle = NULL;
    }

}



/*****************************************************************************
 * FUNCTION
 *  vid_close_play_file
 * DESCRIPTION
 *  Close play file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_close_play_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (vid_context_p->media_mode == MED_MODE_FILE)
    {
        med_avi_close_play_file();
    }
    else if (vid_context_p->media_mode == MED_MODE_ARRAY)
    {
        med_avi_close_play_array();
    }

    /* close audio handle */
    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
        vid_context_p->mhdl_handle = NULL;
    }    
}



/*****************************************************************************
 * FUNCTION
 *  vid_stop_audio_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_audio_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_AUDIO_RECORD);   
    
    if (vid_context_p->record_audio && !VID_AUD_IN_STATE(VID_AUD_IDLE))
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_STOP, __LINE__);                 
        Media_Stop();
        VID_AUD_ENTER_STATE(VID_AUD_IDLE);
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_stop_visual
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_stop_visual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_VISUAL);      

    /* stop visual */
    if (vid_context_p->image_path_open)
    {
        kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_STOP_JPEG_VIDEO_PLAY, __LINE__);
        stop_jpeg_video_play();
        kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);
        
        vid_context_p->image_path_open = KAL_FALSE;
    }
    
    vid_release_player_memory();    
    VID_ENTER_STATE(VID_FILE_READY);    
}

/*****************************************************************************
 * FUNCTION
 *  vid_visual_play_finish_ind_hdlr
 * DESCRIPTION
 *  Handle visual play finish indication message from media-v task
 * PARAMETERS
 *  ilm_ptr     [IN]      msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_visual_play_finish_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_play_finish_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_VISUAL_PLAY_FINISH_IND_HDLR); 
    vid_debug_print_cur_state(__LINE__);

    ind_p = (media_visual_play_finish_ind_struct*) ilm_ptr->local_para_ptr;

    if (ind_p->result != MED_V_RES_OK)
    {
        vid_stop_audio();  
        vid_stop_visual();
        vid_send_play_finish_ind(MED_RES_VIDEO_ERROR);
        return;
    }

    if (VID_IN_STATE(VID_PLAY) ||
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
    {
        vid_stop_audio();                    
        vid_stop_visual();

        /* seek to a vliad position */
        med_avi_seek_by_time(vid_context_p->time_played);
        
        vid_play_finish_hdlr();
    }
    else if (VID_IN_STATE(VID_AUDIO_PLAY_ERROR))
    {
        vid_stop_audio();          
        vid_stop_visual();
        vid_send_play_finish_ind(MED_RES_AUDIO_ERROR);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vid_set_stop_time_req_hdlr
 * DESCRIPTION
 *  Set stop time
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_stop_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_stop_time_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_debug_print_cur_state(__LINE__);

    req_p = (media_vid_set_stop_time_req_struct*) ilm_ptr->local_para_ptr;

    /* save stop time */
    vid_context_p->stop_time = req_p->stop_time;

    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) ||
        VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        /* playing - start a timer to check */
        med_start_timer(VID_STOP_TIME_TIMER, VID_STOP_TIME_CHECK_ELAPSE, vid_check_stop_time, 0);
    }

    VID_SET_EVENT(VID_EVT_BLOCK);

}

/*****************************************************************************
 * FUNCTION
 *  vid_check_stop_time
 * DESCRIPTION
 *  chcek stop time
 * PARAMETERS
 *  arg         [IN]        not used
 * RETURNS
 *  void
 *****************************************************************************/
void vid_check_stop_time(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CHECK_STOP_TIME);  
    vid_debug_print_cur_state(__LINE__);
    
    if (vid_context_p->stop_time == VID_MAX_STOP_TIME)
    {
        return;
    }
    
    kal_trace(TRACE_GROUP_4, VID_TRC_CUR_TIME, (kal_uint32)vid_context_p->time_played);  
    kal_trace(TRACE_GROUP_4, VID_TRC_STOP_TIME, (kal_uint32)vid_context_p->stop_time);  
 
    if (VID_IN_STATE(VID_PLAY) || 
        VID_IN_STATE(VID_AUDIO_PLAY_FINISH) ||
        VID_IN_STATE(VID_VISUAL_PLAY_FINISH))
    {
        /* is playing */
        if (vid_context_p->time_played >= vid_context_p->stop_time)
        {
            vid_stop_audio();
            VID_ENTER_STATE(VID_PLAY_REACH_STOP_TIME);
            vid_send_visual_stop_req(NULL);    
            return;
        }
        else
        {
             med_start_timer(VID_STOP_TIME_TIMER, 300, vid_check_stop_time, 0);
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_release_player_memory
 * DESCRIPTION
 *  Release internal/external memory used in video module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_release_player_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_RELEASE_PLAYER_MEMORY);  
    
    if (vid_context_p->intmem_start_address)
    {
        med_free_int_mem((void **)&vid_context_p->intmem_start_address);
    }
    
    if (vid_context_p->extmem_start_address)
    {
        med_free_ext_mem((void **)&vid_context_p->extmem_start_address);
    }
    
    if (vid_context_p->file_buffer_address)
    {
        med_free_ext_mem((void **)&vid_context_p->file_buffer_address);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  vid_decode_image_callback
 * DESCRIPTION
 *  Callback function of decoding.
 * PARAMETERS
 *  cause       [IN]    decode cause    
 * RETURNS
 *  void
 *****************************************************************************/
void vid_decode_image_callback(kal_uint8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_DECODE_IMAGE_CALLBACK, cause);     

    img_context_p->processing = KAL_FALSE;
    /* in case the timeout msg in queue and callback at the same time */
    vid_send_decode_event_ind(cause);
}




/*****************************************************************************
 * FUNCTION
 *  vid_audio_play_callback
 * DESCRIPTION
 *  Callback function for audio play 
 * PARAMETERS
 *  event       [IN]      Media_Event  
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_play_callback(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_AUDIO_PLAY_CALLBACK, event);    
    
    switch (event)
    {
        case MEDIA_TERMINATED:
        case MEDIA_END:
        case MEDIA_ERROR:
        {
            aud_media_write_data_ind_struct *ind_p = NULL;

            ind_p = (aud_media_write_data_ind_struct*)
                construct_local_para(sizeof(aud_media_write_data_ind_struct), TD_CTRL);

            ind_p->event = event;

            aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_WRITE_DATA_IND, ind_p, NULL);
            break;
        }
        case MEDIA_DATA_REQUEST:
        {
            if (!aud_context_p->processing_data)
            {
                aud_media_write_data_ind_struct *ind_p = NULL;

                ind_p = (aud_media_write_data_ind_struct*)
                    construct_local_para(sizeof(aud_media_write_data_ind_struct), TD_CTRL);

                ind_p->event = event;

                aud_send_ilm(MOD_MED, MSG_ID_AUD_MEDIA_WRITE_DATA_IND, ind_p, NULL);
                aud_context_p->processing_data = KAL_TRUE;

            }
            break;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_open_audio
 * DESCRIPTION
 *  Open audio part.
 * PARAMETERS
 *  void
 * RETURNS
 *  Open result
 *****************************************************************************/
kal_int16 vid_open_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_AUDIO);      

    if (avi_data.aud_format == MED_AVI_AUD_FORMAT_PCM)
    {
        vid_context_p->play_audio = 1;
    }
    else
    {
        /* unsupport type */
        vid_context_p->play_audio = 0;
    }

    VID_AUD_ENTER_STATE(VID_AUD_IDLE);
    VID_RETURN(MED_RES_OK);

}


/*****************************************************************************
 * FUNCTION
 *  vid_close_audio
 * DESCRIPTION
 *  Close the audio part
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int16
 *****************************************************************************/
kal_int16 vid_close_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_AUDIO);       

    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->Close(vid_context_p->mhdl_handle);
        vid_context_p->mhdl_handle = NULL;
    }   
    
    VID_RETURN(MED_RES_OK);
}



/*****************************************************************************
 * FUNCTION
 *  vid_play_audio
 * DESCRIPTION
 *  Play audio.
 * PARAMETERS
 *  void
 * RETURNS
 *  Play audio result
 *****************************************************************************/
kal_int32 vid_play_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 read_size;
    kal_int32 audio_format;
    kal_int32 result;
    Media_Status aud_ret;
    Media_PCM_Stream_Param vpFormat;
    void *param = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_AUDIO, 0);

    if (vid_context_p->play_audio)
    {
        vpFormat.isStereo = 0;
        vpFormat.bitPerSample = 16;        
        vpFormat.sampleFreq = 8000;
        param = &vpFormat;
       
        if ((vid_context_p->mhdl_handle = PCM_Strm_Open(vid_audio_play_callback, param)) == NULL)
        {
            vid_context_p->play_audio = 0;
            VID_RETURN(MED_RES_FAIL);
        }
        
        vid_context_p->mhdl_handle->SetBuffer(
            vid_context_p->mhdl_handle, 
            (kal_uint8*)aud_context_p->ring_buf, 
            AUD_RING_BUFFER_LEN * 2);    
   
        vid_context_p->mhdl_handle->GetWriteBuffer(
            vid_context_p->mhdl_handle, 
            &vid_context_p->audio_buf_p, 
            &vid_context_p->audio_buf_len);

        read_size = vid_context_p->audio_buf_len;
        result = med_avi_read_audio_data((kal_char*)vid_context_p->audio_buf_p, &read_size);

        if (result != MED_RES_OK && result != MED_RES_AUDIO_END)
        {
            /* error */
            VID_RETURN(result);
        }

        kal_trace(TRACE_GROUP_4, VID_TRC_AUD_READ_BUF, vid_context_p->audio_buf_len, read_size);       

        if (read_size > 0)
        {
            if (avi_data.aud_format == MED_AVI_AUD_FORMAT_PCM)
            {
                if (avi_data.aud_sample_rate == 8000)
                {
                    audio_format = MEDIA_FORMAT_PCM_8K;
                }
                else if (avi_data.aud_sample_rate == 16000)
                {
                    audio_format = MEDIA_FORMAT_PCM_16K;
                }
                else
                {
                    VID_RETURN(MED_RES_INVALID_FORMAT);
                }

                vid_context_p->mhdl_handle->WriteDataDone(
                    vid_context_p->mhdl_handle,
                    read_size);

                /* Set to current active volume */
                if (!aud_context_p->audio_mute)
                {
                    aud_set_active_ring_tone_volume();
                }
                
                /* reset this flag for audio recording callback */
                aud_context_p->processing_data = KAL_FALSE;
                
            #if defined(__BTMTK__) && defined(__MED_BT_A2DP_MOD__)
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_AUD_BT_A2DP_OPEN_CODEC, __LINE__);                
                aud_bt_a2dp_open_codec(audio_format);
            #endif    

                /* set vol level if needed */
                if (vid_context_p->vol_level != VID_VOL_LEVEL_NOT_USED)
                {
                    vid_context_p->mhdl_handle->SetLevel(vid_context_p->mhdl_handle, vid_context_p->vol_level);
                }

                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_MEDIA_PLAY, __LINE__);       
                aud_ret = vid_context_p->mhdl_handle->Play(vid_context_p->mhdl_handle);            
                aud_debug_print_aud_drv_return(aud_ret, __LINE__);              
                
                if (aud_ret == MEDIA_SUCCESS)
                {
                    VID_AUD_ENTER_STATE(VID_AUD_PLAY_NORMAL);
                }
            }
        }
    }
    
    VID_RETURN(MED_RES_OK);

}

#ifdef __SF_MP4_SUPPORT__
static kal_bool s_sf_mp4_active=KAL_FALSE;

kal_bool vdo_sfmp4_is_active(void)
{
	return s_sf_mp4_active;
}
static void vdo_sfmp4_set_active(kal_bool active)
{
	s_sf_mp4_active=active;
}


enum
{
    SFMP4_PARAM_AUD_PLAY_CB=2,
	SFMP4_PARAM_AUD_INFO_CB=5
};
#ifndef WIN32
//Huyanwei Add Macro Control
extern void vdo_set_param(kal_uint32 idx,void* param);
#endif

static void vdo_on_sound_play(Media_Format fmt)
{
    //这个方法会在声音即将播放前被调用
    //TODO: FOR BT
}
static void vdo_on_aud_info(Media_Format fmt,kal_int32 channel,kal_int32 sample_rate)
{
	vid_context_p->audio_channel_no = channel;
    vid_context_p->audio_sample_rate = sample_rate;
}

#endif //__SF_MP4_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  vid_open_req_hdlr
 * DESCRIPTION
 *  Handle open video request.
 * PARAMETERS
 *  ilm_ptr     [IN]        msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_open_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_OPEN_REQ_HDLR);
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_open_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->media_mode = req_p->media_mode;
    vid_context_p->media_type = req_p->media_type;
    vid_context_p->open_audio = req_p->play_audio;
    vid_context_p->blocking = req_p->blocking;

    /* init global var */
    vid_context_p->stop_time = VID_MAX_STOP_TIME;
    vid_context_p->play_speed = 100;
    vid_context_p->mhdl_handle = NULL;
    vid_context_p->vol_level = VID_VOL_LEVEL_NOT_USED;

#if defined(__MED_CAM_MOD__)
    cam_abort_to_idle();
#endif 

#ifdef __SF_MP4_SUPPORT__
	vdo_sfmp4_set_active(KAL_FALSE);

    if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
    {
        if (CAM_IN_STATE(CAM_IDLE) && VID_IN_STATE(VID_IDLE))
        {
              kal_int32 result;
			  vdo_sfmp4_set_active(KAL_TRUE);
    #ifndef WIN32
//Huyanwei Add Macro Control
			  vdo_set_param(SFMP4_PARAM_AUD_INFO_CB,(void*)&vdo_on_aud_info);
    
    	    result = vdo_open_play_file(req_p, vid_sf_send_file_ready_ind);
	#endif			
    	    kal_prompt_trace(MOD_MED, "In vid_open_req_hdlr, after vdo_open_file, result:%d", result);
//UNI@bw_0802_0001 根据方案提供商修改MP4播放代码    	    
    	    if(result==MED_RES_OK)
            {
        	VID_ENTER_STATE(VID_FILE_READY);
            }
    	    else
    	    {
        	VID_ENTER_STATE(VID_IDLE);
            }
            vid_set_result(result, __LINE__);

        }
        else if (VID_IN_STATE(VID_FILE_MERGE))
        {
            if (vid_context_p->media_mode == MED_MODE_FILE )
//                || vid_context_p->media_mode == MED_MODE_CLIP_FILE)  //20080616, COMMENTED BY FORREST
            {
                kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
            }
#if 0	//20080616, COMMENTED BY FORREST			
            else if (vid_context_p->media_mode == MED_MODE_CLIP_ARRAY)
            {
                vid_context_p->file_buffer_address = (kal_uint32) req_p->data;
                vid_context_p->file_size = req_p->data_size;
            }
#endif 			
            VID_ENTER_STATE(VID_DELAY_OPEN);
            return;
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else
    {
#endif //__SF_MP4_SUPPORT__
    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_IDLE))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE)
        {
            kal_int32 result;

            if ((result = med_avi_open_play_file(&avi_data, (kal_wchar*) req_p->data)) == MED_RES_OK)
            {
                vid_context_p->time_played = 0;
                vid_context_p->accurate_time_played = 0;
                vid_context_p->total_time = avi_data.vid_duration_in_ms;

                vid_context_p->image_width = avi_data.vid_width;
                vid_context_p->image_height = avi_data.vid_height;
                VID_VALUE_TRACE(vid_context_p->image_width, vid_context_p->image_height, __LINE__);

                vid_context_p->audio_channel_no = avi_data.aud_channel;
                vid_context_p->audio_sample_rate = avi_data.aud_sample_rate;

                if (avi_data.aud_format == MED_AVI_AUD_FORMAT_PCM &&
                    avi_data.aud_sample_rate == 8000)
                {
                    vid_context_p->aud_format = MEDIA_FORMAT_PCM_8K;                    
                }
                else
                {
                    /* currently only support in-house recorded avi file, 8k PCM */
                    ASSERT(0);
                }

                if (vid_context_p->image_width * vid_context_p->image_height > MAX_MJPG_DIMENSION)
                {
                    vid_close_audio();
                    med_avi_close_play_file();
                    result = MED_RES_VIDEO_IMAGE_TOO_LARGE;
                    VID_ENTER_STATE(VID_IDLE);
                }
                else if (avi_data.vid_fps > MAX_MJPG_FILE_FRAME_RATE)
                {
                    vid_close_audio();
                    med_avi_close_play_file();
                    result = MED_RES_VIDEO_FRAME_RATE_TOO_HIGH;
                    VID_ENTER_STATE(VID_IDLE);
                }
                else
                {
                    if (vid_context_p->open_audio && result == MED_RES_OK)
                    {
                        result = vid_open_audio();
                    }

                    VID_ENTER_STATE(VID_FILE_READY);
                    vid_set_image_size(vid_context_p->image_width, vid_context_p->image_height);

                    /* for AVI codec, we only support V == A */                    
                    vid_set_total_time(vid_context_p->total_time, vid_context_p->total_time, vid_context_p->total_time);
                    vid_context_p->current_frame_num = 0;
                }

                if (!vid_context_p->blocking)
                {
                    vid_send_file_ready_ind(result);
                }
            }
            vid_set_result(result, __LINE__);
        }
        else if (vid_context_p->media_mode == MED_MODE_ARRAY)
        {
            kal_int32 result;

            if ((result = med_avi_open_play_array(&avi_data, (kal_char*) req_p->data, req_p->data_size)) == MED_RES_OK)
            {
                vid_context_p->time_played = 0;
                vid_context_p->accurate_time_played = 0;                
                vid_context_p->total_time = avi_data.vid_duration_in_ms;

                vid_context_p->image_width = avi_data.vid_width;
                vid_context_p->image_height = avi_data.vid_height;
                VID_VALUE_TRACE(vid_context_p->image_width, vid_context_p->image_height, __LINE__);

                if (vid_context_p->image_width * vid_context_p->image_height > MAX_MJPG_DIMENSION)
                {
                    vid_close_audio();
                    med_avi_close_play_array();
                    result = MED_RES_VIDEO_IMAGE_TOO_LARGE;
                    VID_ENTER_STATE(VID_IDLE);
                }
                else if (avi_data.vid_fps > MAX_MJPG_FILE_FRAME_RATE)
                {
                    vid_close_audio();
                    med_avi_close_play_array();
                    result = MED_RES_VIDEO_FRAME_RATE_TOO_HIGH;
                    VID_ENTER_STATE(VID_IDLE);
                }
                else
                {
                    if (vid_context_p->open_audio && result == MED_RES_OK)
                    {
                        result = vid_open_audio();
                    }
                    
                    VID_ENTER_STATE(VID_FILE_READY);
                    vid_set_image_size(vid_context_p->image_width, vid_context_p->image_height);

                    /* for AVI codec, we only support V == A */
                    vid_set_total_time(vid_context_p->total_time, vid_context_p->total_time, vid_context_p->total_time);
                    vid_context_p->current_frame_num = 0;
                }

                if (!vid_context_p->blocking)
                {
                    vid_send_file_ready_ind((kal_int16) result);
                }
            }
            vid_set_result(result, __LINE__);
        }
        else
        {
            vid_set_result(MED_RES_PARAM_ERROR, __LINE__);
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

#ifdef __SF_MP4_SUPPORT__
    	}
#endif //__SF_MP4_SUPPORT__	

    VID_SET_EVENT(VID_EVT_OPEN);

}


/*****************************************************************************
 * FUNCTION
 *  vid_close_req_hdlr
 * DESCRIPTION
 *  Handle close video request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SF_MP4_SUPPORT__
    media_vid_close_req_struct *req_p;
#endif //__SF_MP4_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_CLOSE_REQ_HDLR);  
    vid_debug_print_cur_state(__LINE__);
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

#ifdef __SF_MP4_SUPPORT__
    req_p = (media_vid_close_req_struct*) ilm_ptr->local_para_ptr;/*Added by bob, for mp4, @20070710*/
#endif //__SF_MP4_SUPPORT__

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        if (vid_context_p->media_mode == MED_MODE_FILE)
        {
#ifdef __SF_MP4_SUPPORT__
            if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
	{
	#ifndef WIN32
	//Huyanwei Add Macro Control
			vdo_close_play_file(req_p);
	#endif
	    }
            else
#endif //__SF_MP4_SUPPORT__        
            med_avi_close_play_file();
        }
        else if (vid_context_p->media_mode == MED_MODE_ARRAY)
        {
#ifdef __SF_MP4_SUPPORT__
            if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
	{
	#ifndef WIN32
	//Huyanwei Add Macro Control
			vdo_close_play_file(req_p);
	#endif
            }
            else
#endif //__SF_MP4_SUPPORT__        
            med_avi_close_play_array();
        }

        vid_close_audio();

        vid_set_result(MED_RES_OK, __LINE__);

        VID_ENTER_STATE(VID_IDLE);
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

    VID_SET_EVENT(VID_EVT_CLOSE);
}



/*****************************************************************************
 * FUNCTION
 *  vid_play_restart
 * DESCRIPTION
 *  Restart video play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_RESTART);
    vid_debug_print_cur_state(__LINE__);

    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        vid_context_p->time_played = 0;
        vid_context_p->accurate_time_played = 0;        
        
        vid_context_p->file_size = MJPG_FRAME_BUFFER_SIZE;        
        vid_context_p->file_buffer_address = (kal_uint32) med_alloc_ext_mem(MJPG_FRAME_BUFFER_SIZE);

        if (vid_context_p->file_buffer_address == NULL)
        {
            ASSERT(0);
            return;
        }

        vid_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);

        if (vid_context_p->intmem_start_address == NULL)
        {
            ASSERT(0);
            return;
        }

        vid_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_EXT_MEM_SIZE);
        if (vid_context_p->extmem_start_address == NULL)
        {
            ASSERT(0);
            return;
        }

        if (vid_context_p->display_device == MED_DISPLAY_TO_MAIN_LCD ||
            vid_context_p->display_device == MED_DISPLAY_TO_SUB_LCD)
        {
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_START_JPEG_VIDEO_PLAY, __LINE__);
            start_jpeg_video_play(&lcd_data);
            kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);
            
            vid_context_p->image_path_open = KAL_TRUE;
        }
        else if (vid_context_p->display_device == MED_DISPLAY_NONE)
        {
            vid_context_p->image_path_open = KAL_FALSE;
        }

        /* get tick */
        kal_get_time(&vid_context_p->start_tick);

        ASSERT(avi_data.vid_fps);
        
        vid_context_p->current_frame_num = 0;
        vid_context_p->current_time = 0;
        vid_context_p->debug_fps = 0;
        vid_context_p->debug_total_frame = 0;
        vid_context_p->debug_drop_frame = 0;
        vid_context_p->debug_skip_frame = 0;
        vid_context_p->debug_start_time = 0;
        vid_context_p->debug_end_time = 0;
        
        kal_get_time(&vid_context_p->debug_start_time);

        vid_context_p->drop_accumulator = 0;

        if (med_avi_seek_by_time(vid_context_p->current_time) != MED_RES_OK)
        {
            vid_stop_visual();
            vid_send_play_finish_ind(MED_RES_OK);
            return;
        }

        if (vid_play_audio() != MED_RES_OK)
        {
            vid_stop_visual();
            vid_send_play_finish_ind(MED_RES_OK);            
            return;            
        }

        /* callign MED_V to start visual play */
        vid_send_visual_play_req(NULL); /* to sync state of media-v */

        ASSERT(vid_context_p->play_speed == 100);

        VID_ENTER_STATE(VID_PLAY);    
        vid_set_result(MED_RES_OK, __LINE__);
        
    }
    else
    {
        ASSERT(0);
    }

}




/*****************************************************************************
 * FUNCTION
 *  vid_play_finish_hdlr
 * DESCRIPTION
 *  This function is the handler for play finished.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_finish_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_FINISH_HDLR, vid_context_p->repeats);   
    
    if ((vid_context_p->media_mode == MED_MODE_FILE ||
         vid_context_p->media_mode == MED_MODE_ARRAY) 
         && vid_context_p->repeats > 1)
    {
        if (vid_context_p->repeats != 0xffff)
        {
            vid_context_p->repeats--;
        }

        vid_play_restart();
        return;
    }
    else
    {
        VID_ENTER_STATE(VID_FILE_READY);
        vid_send_play_finish_ind(MED_RES_OK);
    }

}



/*****************************************************************************
 * FUNCTION
 *  vid_play_req_hdlr
 * DESCRIPTION
 *  Handle video play request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_PLAY_REQ_HDLR);      

#if defined(NOKE_DEBUG)
   noke_dbg_printf( "vid_play_req_hdlr: entering ... \n\r" );
#endif
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_play_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->seq_num = req_p->seq_num;

    if ((vid_context_p->stop_time != VID_MAX_STOP_TIME) && 
        (vid_context_p->time_played >= vid_context_p->stop_time))
    {
        vid_set_result(MED_RES_REACH_STOP_TIME, __LINE__);
        VID_SET_EVENT(VID_EVT_PLAY);
        return;
    }
#ifdef __SF_MP4_SUPPORT__
    if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
    {
        if (CAM_IN_STATE(CAM_IDLE) && VID_IN_STATE(VID_FILE_READY))
        {
        	kal_int32 result;
            
            vid_context_p->seq_num = req_p->seq_num;

            //setting the sound device for MP4/3GP playback
            vid_context_p->play_audio = req_p->play_audio;

#ifndef WIN32
//Huyanwei Add Macro Control
			vdo_set_param(SFMP4_PARAM_AUD_PLAY_CB,(void*)&vdo_on_sound_play);
#endif

            if (vid_context_p->play_audio)
            {
                vid_stop_unfinished_audio();
                aud_context_p->melody_output_device = req_p->audio_path;  
                aud_get_active_device_path_by_mode(req_p->audio_path,aud_melody_set_output_device);
            }

#if 1
	//Huyanwei Add It For Video Player
           lcd_data.update_layer = req_p->update_layer;
          lcd_data.hw_update_layer = req_p->hw_update_layer;
#endif

#ifndef WIN32
//Huyanwei Add Macro Control
            result = vdo_play_file(req_p, vid_sf_send_play_finish_ind);
#endif
            kal_prompt_trace(MOD_MED, "In vid_play_req_hdlr, after vdo_play_file, result:%d", result);
              
            if (result == MED_RES_OK)
            {
                VID_ENTER_STATE(VID_PLAY);
                vid_set_result(MED_RES_OK, __LINE__);
            }
            else
            {
            #ifndef WIN32
	//Huyanwei Add Macro Control
                vdo_stop_play_file();
	 #endif
                vid_set_result(MED_RES_FAIL, __LINE__);
                VID_SET_EVENT(VID_EVT_PLAY);
                return;
            }
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else
    	{
#endif //__SF_MP4_SUPPORT__
    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        vid_context_p->play_speed = req_p->play_speed;
        vid_context_p->repeats = req_p->repeats;

        if (vid_context_p->open_audio)
        {
            if (vid_context_p->play_speed == 100)
            {
                /* normal play speed */
                vid_context_p->play_audio = req_p->play_audio;
            }
            else
            {
                /* fast play, will disable audio */
                vid_context_p->play_audio = 0;
            }
        }
        else
        {
            vid_context_p->play_audio = 0;
        }

        vid_context_p->display_width = req_p->display_width;
        vid_context_p->display_height = req_p->display_height;
        vid_context_p->image_buffer_address = (kal_uint32) req_p->image_buffer_p;
        vid_context_p->image_buffer_size =
            (vid_context_p->display_width + 16) * (vid_context_p->display_height + 16) * 2;

        vid_context_p->file_size = MJPG_FRAME_BUFFER_SIZE;
        vid_context_p->file_buffer_address = (kal_uint32) med_alloc_ext_mem(MJPG_FRAME_BUFFER_SIZE);

        if (vid_context_p->file_buffer_address == NULL)
        {
            vid_release_player_memory();
            vid_set_result(MED_RES_VIDEO_IMAGE_TOO_LARGE, __LINE__);            
            VID_SET_EVENT(VID_EVT_PLAY);
            return;
        }

        vid_context_p->intmem_start_address = (kal_uint32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);

        if (vid_context_p->intmem_start_address == NULL)
        {
            vid_release_player_memory();
            vid_set_result(MED_RES_MEM_INSUFFICIENT, __LINE__);                        
            VID_SET_EVENT(VID_EVT_PLAY);
            return;
        }

        vid_context_p->intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
        vid_context_p->extmem_start_address = (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_EXT_MEM_SIZE);

        if (vid_context_p->extmem_start_address == NULL)
        {
            vid_release_player_memory();
            vid_set_result(MED_RES_MEM_INSUFFICIENT, __LINE__);                        
            VID_SET_EVENT(VID_EVT_PLAY);
            return;
        }

        vid_context_p->extmem_size = MAX_IMG_DEC_EXT_MEM_SIZE;

        lcd_data.module_id = LCD_UPDATE_MODULE_JPEG_VIDEO;
        lcd_data.lcd_id = req_p->lcd_id;
        lcd_data.lcm_start_x = req_p->lcd_start_x;
        lcd_data.lcm_start_y = req_p->lcd_start_y;
        lcd_data.lcm_end_x = req_p->lcd_end_x;
        lcd_data.lcm_end_y = req_p->lcd_end_y;
        lcd_data.roi_offset_x = req_p->roi_offset_x;
        lcd_data.roi_offset_y = req_p->roi_offset_y;
        lcd_data.update_layer = req_p->update_layer;
        lcd_data.hw_update_layer = req_p->hw_update_layer;
        lcd_data.fb_update_mode = LCD_SW_TRIGGER_MODE;
        lcd_data.rotate_value = (kal_uint8) req_p->lcd_rotate;
        /* play visual */

        if (vid_context_p->play_audio)
        {
            vid_stop_unfinished_audio();
        }

        vid_context_p->display_device = req_p->display_device;
        
        if (vid_context_p->display_device == MED_DISPLAY_TO_MAIN_LCD ||
            vid_context_p->display_device == MED_DISPLAY_TO_SUB_LCD)
        {
            kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_START_JPEG_VIDEO_PLAY, __LINE__);
            start_jpeg_video_play(&lcd_data);
            kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);
            
            vid_context_p->image_path_open = KAL_TRUE;
        }
        else if (vid_context_p->display_device == MED_DISPLAY_NONE)
        {
            vid_context_p->image_path_open = KAL_FALSE;
        }

        /* get tick */
        kal_get_time(&vid_context_p->start_tick);

        ASSERT(avi_data.vid_fps);

        vid_context_p->avi_scale = avi_data.vid_scale;
        vid_context_p->avi_rate = avi_data.vid_rate;        
           
         /* calc accurate frame duration, *1000 for sec->ms*/
        vid_context_p->accurate_period 
            = (1000 << VID_MJPG_ACCURATE_TIME_SHIFT) * 
              (kal_uint64)avi_data.vid_scale / 
              (kal_uint64)avi_data.vid_rate;

        /* calc frame duration, *1000 for sec->ms*/
        vid_context_p->period = 1000 * avi_data.vid_scale / avi_data.vid_rate;
        vid_context_p->period_fraction = vid_context_p->period;

        /* ajust play speed */
        vid_context_p->period_fraction *= 100;
        vid_context_p->period_fraction /= vid_context_p->play_speed;        
        
        /* frame rate */
        vid_context_p->frame_rate = avi_data.vid_rate / avi_data.vid_scale;
        
        /* adjust play speed */
        vid_context_p->frame_rate *= 100;
        vid_context_p->frame_rate /= vid_context_p->play_speed;

        kal_trace(
            TRACE_GROUP_4, 
            VID_TRC_TICK_PER_FRAME_PERIOD, 
            vid_context_p->tick_per_frame_period, 
            __LINE__);           

        vid_context_p->current_frame_num = 0;

        vid_context_p->max_play_frame_rate = MAX_MJPG_PLAY_FRAME_RATE;

        vid_context_p->debug_fps = 0;
        vid_context_p->debug_total_frame = 0;
        vid_context_p->debug_drop_frame = 0;
        vid_context_p->debug_skip_frame = 0;
        vid_context_p->debug_start_time = 0;
        vid_context_p->debug_end_time = 0;
        
        kal_get_time(&vid_context_p->debug_start_time);

        vid_context_p->drop_accumulator = 0;

        if (vid_context_p->frame_rate > vid_context_p->max_play_frame_rate)
        {
            /* video's fps > max fps */
            /* drop value = how many frame will drop one frame, kinda like a coutner */
            vid_context_p->drop_value = 
                ((vid_context_p->frame_rate - vid_context_p->max_play_frame_rate) * 1000) / vid_context_p->frame_rate;
        }
        else
        {
            /* set value = 0, will not drop frame */
            vid_context_p->drop_value = 0;
        }

        /* callign MED_V to start visual play */
        vid_send_visual_play_req(NULL); /* to sync state of media-v */

        /* switch audio path */
        if (vid_context_p->play_audio)
        {
            aud_context_p->melody_output_device = req_p->audio_path;  
            aud_get_active_device_path_by_mode(req_p->audio_path,aud_melody_set_output_device);
        }
        
        if (vid_play_audio() != MED_RES_OK)
        {
            /* error */
            vid_set_result(MED_RES_INVALID_FORMAT, __LINE__);
            VID_SET_EVENT(VID_EVT_PLAY);            
            return;
        }

        VID_ENTER_STATE(VID_PLAY);    

        if (vid_context_p->stop_time != VID_MAX_STOP_TIME)
        {
            /* playing - start a timer to check */
            med_start_timer(VID_STOP_TIME_TIMER, VID_STOP_TIME_CHECK_ELAPSE, vid_check_stop_time, 0);
        }
        
        vid_set_result(MED_RES_OK, __LINE__);
        
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }
#ifdef __SF_MP4_SUPPORT__
    	}
#endif //__SF_MP4_SUPPORT__

    VID_SET_EVENT(VID_EVT_PLAY);

#if defined(NOKE_DEBUG)
   noke_dbg_printf( "vid_play_req_hdlr: exiting ... \n\r" );
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vid_seek_req_hdlr
 * DESCRIPTION
 *  Handle video seek request.
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
void vid_seek_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SEEK_REQ_HDLR);     
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_seek_req_struct*) ilm_ptr->local_para_ptr;

#ifdef __SF_MP4_SUPPORT__
    if (vid_context_p->media_type != FMGR_TYPE_AVI && vid_context_p->media_type != MED_TYPE_MJPG)
    {
        if (CAM_IN_STATE(CAM_IDLE) && VID_IN_STATE(VID_FILE_READY))
        {
            if (req_p->time <= vid_context_p->total_time)
            {
                MEDIA_STATUS_CODE status;
    
                vid_context_p->blocking = req_p->blocking;            
                vid_context_p->seq_num = req_p->seq_num;
                vid_context_p->current_time = req_p->time;
    
                 kal_prompt_trace(MOD_MED, "IN vid_seek_req_hdlr, req_p->time:%d, before vdo_file_seek.", req_p->time);
    
                VID_ENTER_STATE(VID_SEEK);
  #ifndef WIN32
//Huyanwei Add Macro Control	              
                status = vdo_file_seek(req_p, NULL);			
                vdo_get_play_time(&req_p->time);
#endif
                 vid_context_p->current_time = req_p->time;
    
                 kal_prompt_trace(MOD_MED, "IN vid_seek_req_hdlr, status:%d, after vdo_file_seek.", status);
    
                if (status != MED_RES_OK)
                {
    			VID_ENTER_STATE(VID_FILE_READY);
                    vid_set_result(MED_RES_BAD_FORMAT, __LINE__);
                    //visual_enable_sleep();
                    VID_SET_EVENT(VID_EVT_SEEK);
                    return;
    		}
    
        		VID_ENTER_STATE(VID_FILE_READY);

                if (vid_context_p->blocking)
                {
                    vid_set_result(status, __LINE__);
                }
                else
                {
                    vid_send_seek_done_ind(status);
                }
    
    		kal_prompt_trace(MOD_MED, "IN vid_seek_req_hdlr, status:%d, exit.", status);
            }
        }
        else
        {
            vid_set_result(MED_RES_BUSY, __LINE__);
        }
    }
    else
    {
#endif //__SF_MP4_SUPPORT__
    
    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_FILE_READY))
    {
        if (req_p->time <= vid_context_p->total_time)
        {
            vid_context_p->blocking = req_p->blocking;
            vid_context_p->seq_num = req_p->seq_num;
            vid_context_p->current_time = req_p->time;

            med_avi_seek_by_time(vid_context_p->current_time);

            vid_context_p->time_played = vid_context_p->current_time;
            vid_context_p->accurate_time_played = (vid_context_p->current_time << VID_MJPG_ACCURATE_TIME_SHIFT);
            
            if (req_p->get_frame)
            {
                kal_uint8 dec_ret;

                vid_context_p->display_width = req_p->display_width;
                vid_context_p->display_height = req_p->display_height;
                vid_context_p->image_buffer_address = (kal_uint32) req_p->image_buffer_p;
                vid_context_p->image_buffer_size = (kal_uint32) req_p->image_buffer_size;
                vid_context_p->file_size = MJPG_FRAME_BUFFER_SIZE;
                vid_context_p->file_buffer_address = (kal_uint32) med_alloc_ext_mem(MJPG_FRAME_BUFFER_SIZE);

                if (vid_context_p->file_buffer_address > 0)
                {
                    kal_uint32 frame_size = vid_context_p->file_size;

                    if (med_avi_read_video_frame((kal_char*) vid_context_p->file_buffer_address, &frame_size) !=
                        MED_RES_OK)
                    {
                        vid_release_player_memory();
                        VID_ENTER_STATE(VID_FILE_READY);
                        vid_set_result(MED_RES_BAD_FORMAT, __LINE__);
                        VID_SET_EVENT(VID_EVT_SEEK);
                        return;
                    }

                    jpg_decode.jpeg_file_handle = 0;
                    jpg_decode.jpeg_file_buffer_address = vid_context_p->file_buffer_address;
                    jpg_decode.jpeg_file_size = frame_size;
                    jpg_decode.jpeg_file_buffer_size = frame_size;
                    jpg_decode.intmem_start_address = vid_context_p->intmem_start_address =
                        (kal_uint32) med_alloc_int_mem(MAX_IMG_DEC_INT_MEM_SIZE);
                    jpg_decode.intmem_size = vid_context_p->intmem_size = MAX_IMG_DEC_INT_MEM_SIZE;
                    jpg_decode.extmem_start_address = vid_context_p->extmem_start_address =
                        (kal_uint32) med_alloc_ext_mem(MAX_IMG_DEC_EXT_MEM_SIZE);
                    jpg_decode.extmem_size = vid_context_p->extmem_size = MAX_IMG_DEC_EXT_MEM_SIZE;

                    jpg_decode.image_buffer_address = (kal_uint32)vid_context_p->image_buffer_address;                    
                    jpg_decode.image_buffer_size = vid_context_p->image_buffer_size;
                    jpg_decode.image_width = vid_context_p->display_width;
                    jpg_decode.image_height = vid_context_p->display_height;
                    jpg_decode.jpeg_decode_cb = vid_decode_image_callback;
                    
                    #if defined(__SW_JPEG_CODEC_SUPPORT__)
                    {
                        kal_uint32 stack_begin;
                        
                        med_get_med_int_stack_mem(&stack_begin);

                    #if defined(__MTK_TARGET__)
                        /* switch stack only avaialbe on target */
                        dec_ret = (kal_uint8)INT_SwitchStackToRun(
                                        (void*)stack_begin,
                                        MED_INT_STACK_MEM_SIZE,
                                        (kal_func_ptr)jpeg_video_play, 
                                        2,          /* 2 arg */
                                        &jpg_decode,
                                        KAL_FALSE);
                    #else /* __MTK_TARGET__ */
                        dec_ret = jpeg_video_play(&jpg_decode, KAL_FALSE);
                    #endif /* __MTK_TARGET__ */

                        med_free_med_int_stack_mem();
                    }
                    #else /* __SW_JPEG_CODEC_SUPPORT__ */

                         dec_ret = jpeg_video_play(
                                    &jpg_decode,
                                    (kal_uint16*) vid_context_p->image_buffer_address,
                                    vid_context_p->display_width,
                                    KAL_FALSE);

                    #endif /* __SW_JPEG_CODEC_SUPPORT__ */

                    
                    VID_VALUE_TRACE(frame_size, vid_context_p->display_width, vid_context_p->display_height);
                    vid_release_player_memory();

                    VID_ENTER_STATE(VID_FILE_READY);
                    if (vid_context_p->blocking)
                    {
                        vid_set_result(img_get_decode_res(dec_ret), __LINE__);
                    }
                    else
                    {
                        vid_send_seek_done_ind(img_get_decode_res(dec_ret));
                    }
                }
                else
                {
                    vid_release_player_memory();
                    vid_set_result(MED_RES_VIDEO_IMAGE_TOO_LARGE, __LINE__);
                }

            }
        }
        else
        {
            vid_set_result(MED_RES_END_OF_FILE, __LINE__);
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

#ifdef __SF_MP4_SUPPORT__
    	}
#endif //__SF_MP4_SUPPORT__
	
    VID_SET_EVENT(VID_EVT_SEEK);
}


/*****************************************************************************
 * FUNCTION
 *  vid_get_iframe_req_hdlr
 * DESCRIPTION
 *  Get Video i-frame request
 * PARAMETERS
 *  ilm_ptr     [IN]     msg data
 * RETURNS
 *  void
 *****************************************************************************/
void vid_get_iframe_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_iframe_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_GET_IFRAME_REQ_HDLR);    
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_get_iframe_req_struct*) ilm_ptr->local_para_ptr;
    if (vid_chcek_camera_is_idle() && VID_IN_STATE(VID_IDLE))
    {
        kal_int32 result = MED_RES_OK;

        VID_SET_EVENT(VID_EVT_GET_IFRAME);
        vid_send_iframe_ready_ind((kal_int16) result);
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        VID_SET_EVENT(VID_EVT_GET_IFRAME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_set_display_req_hdlr
 * DESCRIPTION
 *  This function is to handle video set display request
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_display_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_set_display_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_DISPLAY_REQ_HDLR);   
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_set_display_req_struct*) ilm_ptr->local_para_ptr;

    if (vid_context_p->display_device != req_p->device)
    {
        vid_context_p->display_device = req_p->device;
        
        if (vid_context_p->display_device == MED_DISPLAY_TO_MAIN_LCD ||
            vid_context_p->display_device == MED_DISPLAY_TO_SUB_LCD)
        {
            if (VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
            {
                if (vid_context_p->image_path_open != KAL_TRUE)
                {
                    kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_START_JPEG_VIDEO_PLAY, __LINE__);
                    start_jpeg_video_play(&lcd_data);
                    kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);
                    
                    vid_context_p->image_path_open = KAL_TRUE;
                }
            }
        }
        else if (vid_context_p->display_device == MED_DISPLAY_NONE)
        {
            if ((VID_IN_STATE(VID_PLAY) || VID_IN_STATE(VID_AUDIO_PLAY_FINISH))
                && vid_context_p->image_path_open == KAL_TRUE)
            {
                kal_trace(TRACE_GROUP_4, VID_TRC_CALLING_STOP_JPEG_VIDEO_PLAY, __LINE__);
                stop_jpeg_video_play();
                kal_trace(TRACE_GROUP_4, VID_TRC_RETURN_VALUE, 0);                
                
                vid_context_p->image_path_open = KAL_FALSE;
            }
        }
    }
    VID_SET_EVENT(VID_EVT_BLOCK);
}



/*****************************************************************************
 * FUNCTION
 *  vid_set_param_req_hdlr
 * DESCRIPTION
 *  This function is to handle video set parameter request.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_set_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SF_MP4_SUPPORT__
    media_vid_set_param_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_SET_PARAM_REQ_HDLR);     

    req_p = (media_vid_set_param_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->param_id)
    {
        case VID_PARAM_CONTRAST:
#ifndef WIN32
//Huyanwei Add Macro Control				
            vdo_play_set_contrast((kal_uint8) req_p->value);
#endif
            break;

        case VID_PARAM_BRIGHTNESS:
#ifndef WIN32
//Huyanwei Add Macro Control			
	    vdo_play_set_brightness((kal_uint8) req_p->value);
#endif
            break;

        default:
            //ASSERT(0);
            break;
    }
#endif //__SF_MP4_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  vid_decode_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle visual decode event indication message from visual HISR
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_decode_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_decode_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_vid_decode_event_ind_struct*) ilm_ptr->local_para_ptr;
    if (VID_IN_STATE(VID_PLAY))
    {
        VID_ENTER_STATE(VID_PLAY);
    }
    if (VID_IN_STATE(VID_SEEK))
    {
        vid_release_player_memory();
        VID_ENTER_STATE(VID_FILE_READY);
        VID_SET_EVENT(VID_EVT_SEEK);
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_audio_play_finish_ind_hdlr
 * DESCRIPTION
 *  This function is to handle audio play finish indication message.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_audio_play_finish_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vid_context_p->play_audio)
    {
        vid_stop_audio();
    }
}



/*****************************************************************************
 * FUNCTION
 *  vid_is_audio_channel_available
 * DESCRIPTION
 *  Check if the audio channel is avaiable.
 * PARAMETERS
 *  void
 * RETURNS
 *  Avaialbe or not
 *****************************************************************************/
kal_bool vid_is_audio_channel_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, VID_TRC_IS_AUDIO_CHANNEL_AVAILABLE);  
    vid_debug_print_cur_state(__LINE__);    
    
    if (VID_IN_STATE(VID_IDLE))
    {
        return KAL_TRUE;
    }
    else if (VID_IN_STATE(VID_PLAY) ||
             VID_IN_STATE(VID_PLAY_PAUSED) ||
             VID_IN_STATE(VID_AUDIO_PLAY_FINISH) ||
             VID_IN_STATE(VID_AUDIO_PLAY_ERROR) ||
             VID_IN_STATE(VID_VISUAL_PLAY_FINISH) ||
             VID_IN_STATE(VID_FILE_READY) ||
             VID_IN_STATE(VID_OPEN_FILE) || 
             VID_IN_STATE(VID_SEEK) || 
             VID_IN_STATE(VID_GET_IFRAME))
    {
        if (VID_AUD_IN_STATE(VID_AUD_IDLE))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else if (VID_IN_STATE(VID_RECORD) ||
             VID_IN_STATE(VID_RECORD_FINISH) || 
             VID_IN_STATE(VID_RECORD_PAUSED) || 
             VID_IN_STATE(VID_RECORD_STOP_VISUAL))
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_set_vol_level
 * DESCRIPTION
 *  set vol level
 * PARAMETERS
 *  vol_level       [IN]        vol level
 * RETURNS
 *  
 *****************************************************************************/
void vid_set_vol_level(kal_uint8 vol_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->vol_level = vol_level; 
    
    if (vid_context_p->mhdl_handle != NULL)
    {
        vid_context_p->mhdl_handle->SetLevel(vid_context_p->mhdl_handle, vol_level);
    }
}


#endif /* defined(__MED_MJPG_MOD__) */ 
#endif /* MED_NOT_PRESENT */ 

