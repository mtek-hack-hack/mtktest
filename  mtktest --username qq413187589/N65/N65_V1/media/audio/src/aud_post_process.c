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
 *   aud_post_process.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to handle all messages for post audio process
 *   (include time stretch and 3D effect currently)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "custom_equipment.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "med_utility.h"
#include "MP4_Parser.h"
#include "drm_gprot.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MED_AUD_AUDIO_EFFECT__)

/* 
 * Local Variable
 */
aud_app_context_struct *aud_app_cntx_p = &med_context.app_context;

/* 
 * Local Function
 */
static kal_uint16 aud_stretch_get_mode_from_speed(kal_uint16 speed);

/* 
 * Global Variable
 */

/* 
 * Global Function
 */

#define BEGIN_AUD_POST_PROCESS_FUNCTION_DEF


/*****************************************************************************
 * FUNCTION
 *  aud_post_process_startup
 * DESCRIPTION
 *  This function is to initialize the audio post process interface in media task
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_post_process_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_app_cntx_p->state_stretch = AUD_EFFECT_OFF;
    aud_app_cntx_p->state_surround = AUD_EFFECT_OFF; 

    aud_app_cntx_p->state_reverb = AUD_EFFECT_UNSET;
    aud_app_cntx_p->state_eq = AUD_EFFECT_UNSET;
    
    return KAL_TRUE;
}


#if defined(__MED_AUD_TIME_STRETCH__)

#if defined(MED_PURE_AUDIO)
#define AUD_STRETCH_FSAL_ROM_SIZE   (2*1024)
#define AUD_DEC_SEEK_HINT_SIZE      (2047)
#define AUD_MP4_FSAL_BUF_SIZE       (1024 / 4)
#define AUD_MP4_STCO_BUF_SIZE       (512 / 4)
#define AUD_MP4_STSZ_BUF_SIZE       (512 / 4)
#define AUD_MP4_STBL_BUF_SIZE       (1024 / 4 * 8)
#endif /* #if defined(MED_PURE_AUDIO) */

/*****************************************************************************
 * FUNCTION
 *  aud_media_get_audio_format_in_video
 * DESCRIPTION
 *  This function is to get the audio format in video
 * PARAMETERS
 *
 * RETURNS
 * kal_uint8   result
 *****************************************************************************/
kal_uint8 aud_stretch_is_aduio_in_video_PP_support(kal_wchar *file_name, kal_uint8 *data, kal_uint32 data_len, kal_int16 data_format)
{
#if defined(MED_PURE_AUDIO)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MP4_Parser_Status eMp4ParserRet;
    FSAL_Status eFSALRet;
    kal_uint8 result;
    kal_bool is_file_opened = KAL_FALSE;
    kal_bool has_aud_track;
    kal_bool is_PP_support = KAL_FALSE;
    Media_Format audio_format;
    kal_uint32 filesize;
    kal_uint32 index;
    kal_uint64 temp;
    STFSAL stFSAL_ROM;
    kal_uint8 *fsal_rom_buf;

    STMp4Parser *stMp4Parser_aud;
    STFSAL *stFSAL_aud;
    STFSAL *stFSAL_aud_stsz;
    STFSAL *stFSAL_aud_stco;
    STFSAL *stFSAL_aud_aud_data;
    kal_uint32 *mp4_aud_buf;
    kal_uint32 *mp4_aud_data_buf;
    kal_uint32 *mp4_aud_stco_buf;
    kal_uint32 *mp4_aud_stsz_buf;
    kal_uint32 *mp4_aud_stbl_buf;
    FS_FileLocationHint *aud_seek_hint;
  
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
    is_file_opened = KAL_TRUE;

    /* Allocate working buffer for operation */    
    stMp4Parser_aud = (STMp4Parser*)get_ctrl_buffer(sizeof(STMp4Parser));
    stFSAL_aud_stsz = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));
    stFSAL_aud_stco = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));
    stFSAL_aud_aud_data = (STFSAL*)get_ctrl_buffer(sizeof(STFSAL));
    mp4_aud_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32) );
    mp4_aud_data_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_FSAL_BUF_SIZE*sizeof(kal_uint32) );
    mp4_aud_stco_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_STCO_BUF_SIZE*sizeof(kal_uint32) );
    mp4_aud_stsz_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_STSZ_BUF_SIZE*sizeof(kal_uint32) );
    mp4_aud_stbl_buf = (kal_uint32*)med_alloc_ext_mem( AUD_MP4_STBL_BUF_SIZE*sizeof(kal_uint32) );
    aud_seek_hint = (FS_FileLocationHint*)med_alloc_ext_mem( AUD_DEC_SEEK_HINT_SIZE*sizeof(FS_FileLocationHint) );

    /* Set buffer for FSAL */
    FSAL_SetBuffer(stFSAL_aud, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_aud_buf);

    /* Set seek hint */
    eFSALRet = FSAL_GetFileSize(stFSAL_aud, &filesize);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }

    for (index = 0; index < AUD_DEC_SEEK_HINT_SIZE; index++)
    {
        temp = ((kal_uint64) filesize * (kal_uint64) (index + 1)) / (kal_uint64) (AUD_DEC_SEEK_HINT_SIZE + 1);
        aud_seek_hint[index].Index = (kal_uint32) temp;
    }
    DRM_set_seek_hint(stFSAL_aud->hFile, AUD_DEC_SEEK_HINT_SIZE, aud_seek_hint);

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

    /* Prepare cache table */
    eMp4ParserRet = MP4_STBL_CacheTablePreprocess(
                        stMp4Parser_aud, 
                        mp4_aud_stbl_buf, 
                        AUD_MP4_STBL_BUF_SIZE);
                        
    if (eMp4ParserRet != MP4_PARSER_OK)
    {
        result = MED_RES_BAD_FORMAT;
        goto pure_audio_error_out;
    }    

    /* FSAL aud data */
    eFSALRet = FSAL_Open_Attach(stFSAL_aud_aud_data, stFSAL_aud);
    
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }
    FSAL_SetBuffer(stFSAL_aud_aud_data, AUD_MP4_FSAL_BUF_SIZE, (kal_uint8*)mp4_aud_data_buf);

    /* FASL stco */
    eFSALRet = FSAL_Open_Attach(stFSAL_aud_stco, stFSAL_aud);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }
    FSAL_SetBuffer(stFSAL_aud_stco, AUD_MP4_STCO_BUF_SIZE, (kal_uint8*)mp4_aud_stco_buf);

    /* FSAL stsz */
    eFSALRet = FSAL_Open_Attach(stFSAL_aud_stsz, stFSAL_aud);
    if (eFSALRet != FSAL_OK)
    {
        result = MED_RES_OPEN_FILE_FAIL;
        goto pure_audio_error_out;
    }
    FSAL_SetBuffer(stFSAL_aud_stsz, AUD_MP4_STSZ_BUF_SIZE, (kal_uint8*)mp4_aud_stsz_buf);

    /* Set FSAL to MP4 Parser */
    MP4_Audio_SetFSAL(stMp4Parser_aud, stFSAL_aud_aud_data);    
    MP4_SetFSAL_STCO(stMp4Parser_aud, MP4_TRACK_AUDIO, stFSAL_aud_stco);
    MP4_SetFSAL_STSZ(stMp4Parser_aud, MP4_TRACK_AUDIO, stFSAL_aud_stsz);
    MP4_UpdateSampleCount(stMp4Parser_aud, MP4_TRACK_AUDIO);

    /* Get Audio Type */
    audio_format = MP4_Audio_Type_To_Media_Format(MP4_GetAudioType(stMp4Parser_aud));
    AUD_VALUE_TRACE(audio_format, -1, __LINE__);

    /* The audio format in 3GP/MP4 file */
    switch (audio_format)
    {
        /* Check AMR / AMR-WB by format enum directly */
    #ifdef AMR_DECODE    
        case MEDIA_FORMAT_AMR:
    #ifdef AMRWB_DECODE        
        case MEDIA_FORMAT_AMR_WB:
    #endif         
            is_PP_support = AudioPP_TS_IsSupport((Media_Format) audio_format, NULL);
            break;
    #endif /*AMR_DECODE*/

        /* Need to wrap audio data in FSAL ROM file for check function */
    #if defined(AAC_DECODE)            
        case MEDIA_FORMAT_AAC:
        {
            kal_uint32 uSampleNo;
            kal_uint32 num_bytes;

            /* Seek to front and read a small range of data */
            eMp4ParserRet =  MP4_Audio_TimeToSampleNo(stMp4Parser_aud, 0, &uSampleNo );
            if(eMp4ParserRet != MP4_PARSER_OK)
            {
                result = MED_RES_FAIL;
                goto pure_audio_error_out; 
            }
            eMp4ParserRet =  MP4_Audio_Seek(stMp4Parser_aud, uSampleNo);
            if(eMp4ParserRet != MP4_PARSER_OK)
            {
                result = MED_RES_FAIL;
                goto pure_audio_error_out; 
            }

            /* Read audio data into buffer and set it to FSAL ROM file */
            fsal_rom_buf = (kal_uint8*)med_alloc_ext_mem( AUD_STRETCH_FSAL_ROM_SIZE*sizeof(kal_uint8) );
            eMp4ParserRet = MP4_Audio_Read(stMp4Parser_aud, fsal_rom_buf, AUD_STRETCH_FSAL_ROM_SIZE, &num_bytes);

            if((eMp4ParserRet != MP4_PARSER_OK) && (eMp4ParserRet != MP4_PARSER_READ_EOF))
            {
                med_free_ext_mem((void**)&fsal_rom_buf);
                result = MED_RES_FAIL;
                goto pure_audio_error_out;             
            }

            FSAL_Direct_SetRamFileSize(&stFSAL_ROM, num_bytes);
            eFSALRet = FSAL_Open(&stFSAL_ROM, (void*)fsal_rom_buf, FSAL_ROMFILE);

            if (eFSALRet != FSAL_OK)
            {
                med_free_ext_mem((void**)&fsal_rom_buf);            
                result = MED_RES_OPEN_FILE_FAIL;
                goto pure_audio_error_out;
            }

            /* check time stretch support by using extract audio data in FSAL ROM file */
            is_PP_support = AudioPP_TS_IsSupport((Media_Format) audio_format, &stFSAL_ROM);

            med_free_ext_mem((void**)&fsal_rom_buf);
            break;
        }            
    #endif /*AAC_DECODE*/            

        default:
            result = MED_RES_INVALID_FORMAT;
            goto pure_audio_error_out;
            break;
    }

    if (is_PP_support)
    {
        result = MED_RES_OK;
    }
    else
    {
        result = MED_RES_UNSUPPORTED_SPEED;
    }
     
pure_audio_error_out:
    if (is_file_opened)
    {
        FSAL_Close(stFSAL_aud);

        free_ctrl_buffer(stMp4Parser_aud);        
        free_ctrl_buffer(stFSAL_aud_stsz);
        free_ctrl_buffer(stFSAL_aud_stco);
        free_ctrl_buffer(stFSAL_aud_aud_data);
        med_free_ext_mem((void**)&mp4_aud_buf);
        med_free_ext_mem((void**)&mp4_aud_data_buf);
        med_free_ext_mem((void**)&mp4_aud_stco_buf);
        med_free_ext_mem((void**)&mp4_aud_stsz_buf);
        med_free_ext_mem((void**)&mp4_aud_stbl_buf);     
        med_free_ext_mem((void**)&aud_seek_hint);
    }

    free_ctrl_buffer(stFSAL_aud);

    return result;

#else
    return MED_RES_INVALID_FORMAT;
#endif /* #if defined(MED_PURE_AUDIO) */

}

/*****************************************************************************
 * FUNCTION
 *  aud_stretch_check_stream_format_req_hdlr
 * DESCRIPTION
 *  This function is to check format for audio data stream
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_check_stream_format_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_support;
    STFSAL ext_file;
    FSAL_Status fsal_ret;
    media_stretch_check_stream_format_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_stretch_check_stream_format_req_struct*) ilm_ptr->local_para_ptr;

    FSAL_Direct_SetRamFileSize(&ext_file, msg_p->size);
    fsal_ret = FSAL_Open(&ext_file, (void*)msg_p->data_p, FSAL_ROMFILE);

    if (fsal_ret == FSAL_OK)
    {
        /* Check if the file can play with time stretch on */
        is_support = AudioPP_TS_IsSupport((Media_Format) msg_p->format, &ext_file);        

        FSAL_Close(&ext_file);

        if (is_support)
        {
            aud_app_set_result(MED_RES_OK);
            EFFECT_SET_EVENT(TS_EVT_CHECK);
            return;
        }
    }

    aud_app_set_result(MED_RES_FAIL);
    EFFECT_SET_EVENT(TS_EVT_CHECK);

}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_check_file_format_req_hdlr
 * DESCRIPTION
 *  This function is to check format for audio file
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_check_file_format_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 format;
    kal_bool is_support;
    STFSAL ext_file;
    FSAL_Status fsal_ret;
    media_stretch_check_file_format_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_stretch_check_file_format_req_struct*) ilm_ptr->local_para_ptr;

    /* Get file audio type from extension */
    format = med_get_media_type(msg_p->file_path);

    if(format == MED_TYPE_MP4 || format == MED_TYPE_3GP)
    {
        kal_uint8 result;

        /* Get video's audio type */
        result = aud_stretch_is_aduio_in_video_PP_support(msg_p->file_path, NULL, 0, 0);

        aud_app_set_result(result);
    }
    else
    {
        /* get file handle */
        fsal_ret = FSAL_Open(&ext_file, (void*)msg_p->file_path, FSAL_READ);

        if (fsal_ret == FSAL_OK)
        {
            /* Check if the file can play with time stretch on */
            is_support = AudioPP_TS_IsSupport((Media_Format) format, &ext_file);

            FSAL_Close(&ext_file);

            if (is_support)
            {
                aud_app_set_result(MED_RES_OK);
            }
            else
            {
                aud_app_set_result(MED_RES_UNSUPPORTED_SPEED);
            }
        }
        else if (fsal_ret == FSAL_OPEN_ERROR)
        {
            aud_app_set_result(MED_RES_OPEN_FILE_FAIL);
        }
        else
        {
            aud_app_set_result(MED_RES_FAIL);
        }
    }
    EFFECT_SET_EVENT(TS_EVT_CHECK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_set_speed_req_hdlr
 * DESCRIPTION
 *  This function is the request hanlder of setting play speed for all audio
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_set_speed_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_set_speed_req_struct *msg_p;
    kal_int32 set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (media_stretch_set_speed_req_struct*) ilm_ptr->local_para_ptr;

    /* Set time stretch speed */
    set_result = aud_stretch_set_speed(msg_p->speed);

    aud_app_set_result(set_result);
    EFFECT_SET_EVENT(TS_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_set_speed
 * DESCRIPTION
 *  This function is the interface of setting play speed for all audio for media task
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 aud_stretch_set_speed(kal_uint16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 mode;
    Media_Status ts_result;
    kal_int32 set_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Convert speed to mode */
    if ((mode = aud_stretch_get_mode_from_speed(speed)) != 0)
    {
        /* Set time stretch mode and turn on it */
        ts_result = AudioPP_TS_SetSpeed(mode);

        if (ts_result == MEDIA_SUCCESS)
        {
            aud_app_cntx_p->state_stretch = AUD_EFFECT_ON;
            set_result = MED_RES_OK;
        }
        else
        {
            set_result = MED_RES_FAIL;
        }
    }
    /* Unsupport speed mode */
    else
    {
        set_result = MED_RES_PARAM_ERROR;
    }

    return set_result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_close_req_hdlr
 * DESCRIPTION
 *  This function is the request handler of turning off play speed and play as normal speed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_close_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_stretch_close();

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(TS_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_close
 * DESCRIPTION
 *  This function is the interface of turning off play speed for media task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_stretch_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_app_cntx_p->state_stretch == AUD_EFFECT_ON)
    {
        AudioPP_TS_Close();
    }

    aud_app_cntx_p->state_stretch = AUD_EFFECT_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  aud_stretch_get_mode_from_speed
 * DESCRIPTION
 *  This function is to convert play speed to the mode provide by l1 audio
 * PARAMETERS
 *  speed       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint16 aud_stretch_get_mode_from_speed(kal_uint16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (speed)
    {
        case 50:
            mode = 1;
            break;
        case 80:
            mode = 2;
            break;
        case 125:
        case 128:
            mode = 3;
            break;
        case 160:
            mode = 4;
            break;
        default:
            break;
    }

    return mode;
}
#endif /*#if defined(__MED_AUD_TIME_STRETCH__)*/


#if defined(__MED_AUD_REVERB__)
/*****************************************************************************
 * FUNCTION
 *  aud_reverb_set_coeff_req_hdlr
 * DESCRIPTION
 *  This function is to set the 3D effect coefficient
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_reverb_set_coeff_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_reverb_set_coeff_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_REVERB_SET_COEFF_REQ_HDLR, aud_app_cntx_p->state_reverb);

    msg_p = (media_reverb_set_coeff_req_struct*) ilm_ptr->local_para_ptr;

    AudioPP_Reverb_SetCoeff(msg_p->coeff_table_ptr);

    /* First time set parameter. If not first time set, keep current state */
    if (aud_app_cntx_p->state_reverb == AUD_EFFECT_UNSET)
    {
        aud_app_cntx_p->state_reverb = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(REVERB_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_reverb_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on 3D sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_reverb_turn_on_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_REVERB_TURN_ON_REQ_HDLR, aud_app_cntx_p->state_eq, aud_app_cntx_p->state_reverb, aud_app_cntx_p->state_surround);


    /* Parameter is not set */
    if (aud_app_cntx_p->state_reverb == AUD_EFFECT_UNSET)
    {
        aud_app_set_result(MED_RES_FAIL);
    }
    /* Can not turn on with surround or equalizer at the same time */
    else if(aud_app_cntx_p->state_surround == AUD_EFFECT_ON || aud_app_cntx_p->state_eq == AUD_EFFECT_ON)
    {
        aud_app_set_result(MED_RES_BUSY);
    }
    /* Parameter is already set but not turn on or being paused by other feature. */
    else if (aud_app_cntx_p->state_reverb == AUD_EFFECT_OFF)
    {
        result = AudioPP_Reverb_TurnOn();
        aud_app_set_result((kal_int32) aud_get_res((kal_uint8) result));

        if (result == MEDIA_SUCCESS)
        {
            aud_app_cntx_p->state_reverb = AUD_EFFECT_ON;
        }
    }

    EFFECT_SET_EVENT(REVERB_EVT_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_reverb_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off 3D sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_reverb_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_REVERB_TURN_OFF_REQ_HDLR, aud_app_cntx_p->state_eq, aud_app_cntx_p->state_reverb, aud_app_cntx_p->state_surround);

    if (aud_app_cntx_p->state_reverb == AUD_EFFECT_ON)
    {
        AudioPP_Reverb_TurnOff();
    }

    /* If 3D effect is not set, do not change its state. */
    if (aud_app_cntx_p->state_reverb != AUD_EFFECT_UNSET)
    {
        aud_app_cntx_p->state_reverb = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(REVERB_EVT_OFF);
}

#endif /* #if defined(__MED_AUD_REVERB__) */


#if defined(__MED_AUD_SURROUND__)
/*****************************************************************************
 * FUNCTION
 *  aud_surround_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on 3d surround sound
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_surround_turn_on_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_surround_turn_on_req_struct *msg_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_SURROUND_TURN_ON_REQ_HDLR, aud_app_cntx_p->state_eq, aud_app_cntx_p->state_reverb, aud_app_cntx_p->state_surround);

    msg_p = (media_surround_turn_on_req_struct*) ilm_ptr->local_para_ptr;

    /* Can not turn on with reverb or surround at the same time */
    if(aud_app_cntx_p->state_reverb == AUD_EFFECT_ON || aud_app_cntx_p->state_eq == AUD_EFFECT_ON)
    {
        aud_app_set_result(MED_RES_BUSY);
    }
    else if(aud_app_cntx_p->state_surround == AUD_EFFECT_OFF)
    {
        AudioPP_Surround_Enable();
        AudioPP_Surround_ModeSelect(msg_p->mode);
        aud_app_cntx_p->state_surround = AUD_EFFECT_ON;
        aud_app_cntx_p->mode_surround = msg_p->mode;
    }
    else if((aud_app_cntx_p->state_surround == AUD_EFFECT_ON) &&
            (aud_app_cntx_p->mode_surround != msg_p->mode))
    {
        AudioPP_Surround_ModeSelect(msg_p->mode);
        aud_app_cntx_p->mode_surround = msg_p->mode;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(SURROUND_EVT_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_surround_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off 3d surround sound
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_surround_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_SURROUND_TURN_OFF_REQ_HDLR, aud_app_cntx_p->state_eq, aud_app_cntx_p->state_reverb, aud_app_cntx_p->state_surround);

    if(aud_app_cntx_p->state_surround == AUD_EFFECT_ON)
    {
        AudioPP_Surround_Disable();
        aud_app_cntx_p->state_surround = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(SURROUND_EVT_OFF);
}
#endif /* #if defined(__MED_AUD_SURROUND__) */


#if defined(__MED_AUD_EQUALIZER__)
/*****************************************************************************
 * FUNCTION
 *  aud_eq_set_magnitude_req_hdlr
 * DESCRIPTION
 *  This function is to set the equalizer magnitude
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_eq_set_magnitude_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_eq_set_magnitude_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_EQ_SET_MAGNITUDE_REQ_HDLR, aud_app_cntx_p->state_eq);

    msg_p = (media_aud_eq_set_magnitude_req_struct*) ilm_ptr->local_para_ptr;

    AudioPP_Equalizer_SetMag(msg_p->magnitude);

    /* First time set parameter. If not first time set, keep current state */
    if (aud_app_cntx_p->state_eq == AUD_EFFECT_UNSET)
    {
        aud_app_cntx_p->state_eq = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(EQ_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_eq_turn_on_req_hdlr
 * DESCRIPTION
 *  This function is to turn on equalizer sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_eq_turn_on_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_EQ_TURN_ON_REQ_HDLR, aud_app_cntx_p->state_eq, aud_app_cntx_p->state_reverb, aud_app_cntx_p->state_surround);

    /* Parameter is not set */
    if (aud_app_cntx_p->state_eq == AUD_EFFECT_UNSET)
    {
        aud_app_set_result(MED_RES_FAIL);
    }
    /* Can not turn on with reverb or surround at the same time */
    else if(aud_app_cntx_p->state_reverb == AUD_EFFECT_ON || aud_app_cntx_p->state_surround == AUD_EFFECT_ON)
    {
        aud_app_set_result(MED_RES_BUSY);
    }
    /* Parameter is already set but not turn on */
    else if (aud_app_cntx_p->state_eq == AUD_EFFECT_OFF)
    {
        AudioPP_Equalizer_TurnOn();
        aud_app_cntx_p->state_eq = AUD_EFFECT_ON;
    }

    EFFECT_SET_EVENT(EQ_EVT_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_eq_turn_off_req_hdlr
 * DESCRIPTION
 *  This function is to turn off equalizer sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_eq_turn_off_req_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY3(AUD_EQ_TURN_OFF_REQ_HDLR, aud_app_cntx_p->state_eq, aud_app_cntx_p->state_reverb, aud_app_cntx_p->state_surround);

    if (aud_app_cntx_p->state_eq == AUD_EFFECT_ON)
    {
        AudioPP_Equalizer_TurnOff();
    }

    /* If 3D effect is not set, do not change its state. */
    if (aud_app_cntx_p->state_eq != AUD_EFFECT_UNSET)
    {
        aud_app_cntx_p->state_eq = AUD_EFFECT_OFF;
    }

    aud_app_set_result(MED_RES_OK);
    EFFECT_SET_EVENT(EQ_EVT_OFF);
}
#endif /* #if defined(__MED_AUD_EQUALIZER__) */

#endif /* #if defined(__MED_AUD_AUDIO_EFFECT__)*/ 

#endif /* MED_NOT_PRESENT */ 

