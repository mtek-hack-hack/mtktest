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
 * aud_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes common used functions of audio manager task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
/* Buffer Management */
#include "app_buff_alloc.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
/* for tst inject message */
#include "tst_sap.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "fat_fs.h"
#include "med_utility.h"

extern kal_int16 med_get_media_type(kal_wchar *file_name);

/* MED audio resource variable */
device_tones_struct **resource_tones = NULL;
#ifndef MED_MODEM
audio_resource_struct *resource_midis = NULL;
audio_resource_struct *resource_sounds = NULL;
audio_resource_struct *resource_message_sounds = NULL;
audio_resource_struct *resource_imelodys = NULL;
audio_resource_struct *resource_ems_sounds = NULL;
audio_resource_struct *resource_ems_imelodys = NULL;
audio_resource_struct *resource_mms_sounds = NULL;
#endif
/*****************************************************************************
 * FUNCTION
 *  aud_audio_out_dev_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speaker_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_audio_out_dev_convert(kal_uint8 speaker_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_device_out = L1SP_SPEAKER1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (speaker_id)
    {
        case AUDIO_DEVICE_SPEAKER:
            audio_device_out = L1SP_SPEAKER1;
            break;
        case AUDIO_DEVICE_SPEAKER2:
            audio_device_out = L1SP_SPEAKER2;
            break;
        case AUDIO_DEVICE_LOUDSPEAKER:
            audio_device_out = L1SP_LOUD_SPEAKER;
            break;
        case AUDIO_DEVICE_SPEAKER_BOTH:
            audio_device_out = L1SP_LOUD_SPEAKER | L1SP_SPEAKER2;
            break;
        case AUDIO_DEVICE_BUZZER:
            audio_device_out = L1SP_LOUD_SPEAKER;
            break;
        default:
            break;
    }

    return audio_device_out;
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_res(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MEDIA_SUCCESS:
            return MED_RES_OK;
        case MEDIA_FAIL:
            return MED_RES_FAIL;
        case MEDIA_BAD_FORMAT:
        case MEDIA_BAD_PARAMETER:
            return MED_RES_BAD_FORMAT;
        case MEDIA_BAD_COMMAND:
        case MEDIA_REENTRY:
            return MED_RES_BUSY;
        case MEDIA_NO_HANDLER:
            return MED_RES_NO_HANDLE;
        case MEDIA_UNSUPPORTED_CHANNEL:
            return MED_RES_UNSUPPORTED_CHANNEL;
        case MEDIA_UNSUPPORTED_FREQ:
            return MED_RES_UNSUPPORTED_FREQ;
        case MEDIA_UNSUPPORTED_TYPE:
            return MED_RES_UNSUPPORTED_TYPE;
        case MEDIA_UNSUPPORTED_OPERATION:
            return MED_RES_UNSUPPORTED_OPERATION;
        case MEDIA_SEEK_EOF:
            return MED_RES_END_OF_FILE;
        default:
            return MED_RES_FAIL;

    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_check_disc_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_name        [?]         
 *  free_byte       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte)
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
    kal_mem_set(dir, 0, 6);
    kal_mem_cpy(dir, dir_name, 4);
    /* check the available free space */
    result = FS_GetDiskInfo((kal_wchar*) dir, &disc_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

#ifdef __MTK_TARGET__
    if (result > 0 && result & (FS_DI_BASIC_INFO | FS_DI_FREE_SPACE))
    {
        if ((disc_info.FreeClusters * disc_info.SectorsPerCluster * disc_info.BytesPerSector) < free_byte)
        {
            return MED_RES_DISC_FULL;
        }
        else
        {
            return MED_RES_OK;
        }
    }
    else
    {
        return MED_RES_NO_DISC;
    }
#else /* __MTK_TARGET__ */ 
    return MED_RES_OK;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_is_streaming_type
 * DESCRIPTION
 *  This function is used to check if the audio file type is streaming.
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_is_streaming_type(kal_uint8 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (format)
    {
        case MED_TYPE_GSM_FR:
        case MED_TYPE_GSM_HR:
        case MED_TYPE_GSM_EFR:
        case MED_TYPE_AMR:
        case MED_TYPE_AMR_WB:
        case MED_TYPE_DAF:
        case MED_TYPE_MUSICAM:
        case MED_TYPE_PCM_8K:
        case MED_TYPE_PCM_16K:
        case MED_TYPE_G711_ALAW:
        case MED_TYPE_G711_ULAW:
        case MED_TYPE_DVI_ADPCM:
        case MED_TYPE_WAV:
        case MED_TYPE_WAV_ALAW:
        case MED_TYPE_WAV_ULAW:
        case MED_TYPE_WAV_DVI_ADPCM:
        case MED_TYPE_AU:
        case MED_TYPE_AIFF:
    #if defined(AAC_DECODE)
        case MED_TYPE_M4A:
    #endif 
            return KAL_TRUE;
        default:
            return KAL_FALSE;

    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_create_full_path_folder
 * DESCRIPTION
 *  check or make dir along the assigned path
 * PARAMETERS
 *  filepath        [?]     
 * RETURNS
 *  int
 *****************************************************************************/
int aud_create_full_path_folder(kal_uint16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *filepath_p = filepath;
    kal_int32 fs_ret = FS_FILE_EXISTS;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return FS_FILE_EXISTS;
    }

    /* skip drive, i.e. "C:\" */
    while (*filepath_p != L'\\')
    {
        if (*filepath_p != 0)
        {
            filepath_p++;
        }
        else
        {
            return FS_INVALID_FILENAME;
        }
    }

    while (*(filepath_p++))
    {
        if (*filepath_p == L'\\')
        {
            *filepath_p = 0;
            file_handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);
            /* check if path exists */
            if (file_handle < 0)
            {
                /* create dir */
                fs_ret = FS_CreateDir(filepath);
                *filepath_p = L'\\';
                if (fs_ret != FS_NO_ERROR)
                {
                    break;
                }
            }
            else
            {
                FS_Close(file_handle);
                *filepath_p = L'\\';
            }
        }
    }

    return fs_ret;
}

#ifdef TST_HANDLER


/*****************************************************************************
 * FUNCTION
 *  aud_tst_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tst_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(tst_inject != NULL);

    switch (tst_inject->index)
    {
        case 13:    /* audio play by name */
        {
            l4aud_audio_play_by_name_req_struct msg;

            kal_wsprintf(msg.file_name, "%s", tst_inject->string);
            msg.play_style = DEVICE_AUDIO_PLAY_INFINITE;
            msg.src_id = 0;
            ilm_ptr->local_para_ptr = (local_para_struct*) & msg;
            aud_play_by_name_req_hdlr(ilm_ptr);
            break;
        }
        case 14:    /* audio stop by name */
        {
            l4aud_audio_stop_by_name_req_struct msg;

            kal_wsprintf(msg.file_name, "%s", tst_inject->string);
            ilm_ptr->local_para_ptr = (local_para_struct*) & msg;
            aud_stop_by_name_req_hdlr(ilm_ptr);
            break;
        }
        case 15:    /* audio play by string */
        {
            l4aud_audio_play_by_string_req_struct msg;

            msg.melody = resource_midis[tst_inject->string[0] - '0'].data;
            msg.format = AUD_MEDIA_SMF;
            msg.play_style = DEVICE_AUDIO_PLAY_INFINITE;
            msg.len = resource_midis[tst_inject->string[0] - '0'].len;
            msg.src_id = 0;
            ilm_ptr->local_para_ptr = (local_para_struct*) & msg;
            aud_play_by_string_req_hdlr(ilm_ptr);
            break;
        }
        case 16:    /* audio stop by string */
        {
            l4aud_audio_stop_by_string_req_struct msg;

            msg.src_id = 0;
            ilm_ptr->local_para_ptr = (local_para_struct*) & msg;
            aud_stop_by_string_req_hdlr(ilm_ptr);
            break;
        }
    }

}

#endif /* TST_HANDLER */

#ifdef __RICH_AUDIO_PROFILE__
/*****************************************************************************
 * DATA STRUCTURE
 *  it contains a file STFSAL to be used by AMR_Open or DAF_Open
 *  and a handle_p to be returned by AMR_Open or DAF_Open 
 *  and most importantly it has BuildCache func that we use to build cache
 *****************************************************************************/
struct _media_struct
{
    STFSAL file;
    MHdl *handle_p;
    void* file_buf;
    void* proc_buf;
} media_cache;

/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_start
 * DESCRIPTION
 *  start the process of build cache
 * PARAMETERS
 *  filename     [IN]
 *  cache_p      [IN]
 *  cache_size   [IN]
 *  file_buf     [IN]
 *  file_buf_size[IN]
 *  proc_buf     [IN]
 *  proc_buf_size[IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_util_build_cache_start( kal_wchar *filename, 
    void* cache_p, kal_int32 cache_size, 
    void *file_buf, kal_int32 file_buf_size, 
    void *proc_buf, kal_int32 proc_buf_size )
{
    kal_int16 type;
    Media_VM_PCM_Param vpFormat;

    ASSERT( media_cache.handle_p == NULL );

    /* get media type from filename extension */
    type = med_get_media_type( filename );

    if( type == MED_TYPE_NONE )
        return KAL_FALSE;

    /* open file */
    if( FSAL_Open( &media_cache.file, filename, FSAL_READ ) != FSAL_OK )
        return KAL_FALSE;

    FSAL_SetBuffer( &media_cache.file, file_buf_size, (kal_uint8*)file_buf );

    memset( cache_p, 0, cache_size );

    /* determine which open func */
    switch( type )
    {
#ifdef AMR_DECODE
    case MED_TYPE_AMR:
        vpFormat.mediaType = MED_TYPE_AMR;
        vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
        media_cache.handle_p = AMR_Open( NULL, &media_cache.file, &vpFormat );
        break;
#endif /* AMR_DECODE */
#ifdef DAF_DECODE
    case MED_TYPE_DAF:
#ifdef MUSICAM_DECODE
    case MED_TYPE_MUSICAM:
#endif
        media_cache.handle_p = DAF_Open( NULL, &media_cache.file, NULL );
        break;
#endif /* DAF_DECODE */
#ifdef AAC_DECODE
    case MED_TYPE_AAC:
        media_cache.handle_p = AAC_Open( NULL, &media_cache.file, NULL );
        break;
#endif
    default:
        ASSERT(0);
    }

    /* handle open func fail case */
    if( media_cache.handle_p == NULL )
    {
        FSAL_Close( &media_cache.file );
        return KAL_FALSE;
    }

    media_cache.handle_p->SetCacheTbl( media_cache.handle_p, cache_p, NULL );
    media_cache.handle_p->SetBuffer( media_cache.handle_p, 
        (kal_uint8*)proc_buf, proc_buf_size );

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_stop
 * DESCRIPTION
 *  stop the process of build cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_util_build_cache_stop( void )
{
    /* if it's not started, skip it */
    if( media_cache.handle_p != NULL )
    {
        /* close func */
        media_cache.handle_p->Close( media_cache.handle_p );

        /* close file */
        FSAL_Close( &media_cache.file );

        /* reset handle & start flag */
        media_cache.handle_p = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_process
 * DESCRIPTION
 *  do the process of build cache incrementally
 * PARAMETERS
 *  progress_p     [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_util_build_cache_process( kal_uint32 *progress_p )
{
    Media_Status result;

    ASSERT( media_cache.handle_p != NULL );

    /* do build cache incrementally */
    media_cache.handle_p->BuildCache( media_cache.handle_p, &result, progress_p );

    if( result == MEDIA_SUCCESS )
    {
        return KAL_TRUE;
    }
    else
    {
        /* handle build cache failed case */
        aud_util_build_cache_stop();

        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_util_build_cache_get_duration
 * DESCRIPTION
 *  get the total duration from the process of build cache
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 aud_util_build_cache_get_duration( void )
{
    kal_uint32 duration;

    ASSERT( media_cache.handle_p != NULL );

    duration = media_cache.handle_p->GetTotalDuration( media_cache.handle_p );

    return duration;
}
#endif /* __RICH_AUDIO_PROFILE__ */

#endif /* MED_NOT_PRESENT */ 

