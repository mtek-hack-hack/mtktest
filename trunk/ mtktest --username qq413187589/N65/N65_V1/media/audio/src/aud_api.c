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
 *   aud_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary exported functions of audio module.
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
#include "stack_config.h"
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
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
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
#include "med_v_main.h"
#include "med_v_context.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

static kal_int32 aud_result;
static kal_uint32 aud_value;

#ifdef __MED_MMA_MOD__
static kal_int32 mma_result;
static kal_int32 mma_handle;
#endif /* __MED_MMA_MOD__ */ 

#ifdef __MED_SND_MOD__
static kal_int32 bgsnd_result;
#endif 

#ifdef __MED_AUD_AUDIO_EFFECT__
static kal_int32 audio_effect_result;
#endif 

/*==== FUNCTIONS ===========*/


/*****************************************************************************
 * FUNCTION
 *  aud_debug_print_aud_drv_return
 * DESCRIPTION
 *  Print audio return cause
 * PARAMETERS
 *  aud_ret             [IN]        Media_Status
 *  line                [IN]        line
 * RETURNS
 *  void
 *****************************************************************************/
void aud_debug_print_aud_drv_return(kal_int32 aud_ret, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(aud_ret)
    {
        case MEDIA_SUCCESS:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_SUCCESS, line);
            break;
            
        case MEDIA_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_FAIL, line);
            break;
            
        case MEDIA_REENTRY:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_REENTRY, line);
            break;       

        case MEDIA_NOT_INITIALIZED:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_NOT_INITIALIZED, line);
            break;            

        case MEDIA_BAD_FORMAT:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_BAD_FORMAT, line);
            break;            

        case MEDIA_BAD_PARAMETER:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_BAD_PARAMETER, line);
            break;            

        case MEDIA_BAD_COMMAND:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_BAD_COMMAND, line);
            break;               

        case MEDIA_NO_HANDLER:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_NO_HANDLER, line);
            break;                    

        case MEDIA_UNSUPPORTED_CHANNEL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_CHANNEL, line);
            break;                    

        case MEDIA_UNSUPPORTED_FREQ:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_FREQ, line);
            break;                    

        case MEDIA_UNSUPPORTED_TYPE:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_TYPE, line);
            break;                    

        case MEDIA_UNSUPPORTED_OPERATION:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_UNSUPPORTED_OPERATION, line);
            break;                    

        case MEDIA_SEEK_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_SEEK_FAIL, line);
            break;                    

        case MEDIA_SEEK_EOF:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_SEEK_EOF, line);
            break;      

        case MEDIA_READ_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_READ_FAIL, line);
            break;      

        case MEDIA_WRITE_FAIL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_WRITE_FAIL, line);
            break;      

        case MEDIA_DISK_FULL:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_DISK_FULL, line);
            break;                  

        case MEDIA_MERGE_TYPE_MISMATCH:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_MEDIA_MERGE_TYPE_MISMATCH, line);
            break;       

        default:
            kal_trace(TRACE_GROUP_4, AUD_TRC_DRV_UNKNOWN_ENUM, aud_ret, line);
            break;
    }

}



/*****************************************************************************
 * FUNCTION
 *  aud_set_result
 * DESCRIPTION
 *  This function is to set the result of audio request.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_RESULT_TRACE(result, aud_context_p->state, -1);
    aud_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_pair_results
 * DESCRIPTION
 *  This function is to set the result and the value of audio request.
 * PARAMETERS
 *  result      [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_pair_results(kal_int32 result, kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VALUE_TRACE(result, value, aud_context_p->state);
    aud_result = result;
    aud_value = value;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_play_id
 * DESCRIPTION
 *  This function is to play audio ID.
 * PARAMETERS
 *  src_mod_id      [IN]        void *id_param
 *  id_param        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_play_id(module_type src_mod_id, void *id_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_play_id_req(src_mod_id, id_param);
    /* AUD_WAIT_EVENT(AUD_EVT_PLAY); */
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_id
 * DESCRIPTION
 *  This function is to stop audio ID.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 audio_id
 *  audio_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_aud_stop_id(module_type src_mod_id, kal_uint8 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_stop_id_req(src_mod_id, audio_id);
    AUD_WAIT_EVENT(AUD_EVT_STOP);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_play_string
 * DESCRIPTION
 *  This function is to play audio string.
 * PARAMETERS
 *  src_mod_id          [IN]        void *string_param
 *  string_param        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_play_string(module_type src_mod_id, void *string_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_string_struct *data_p = (aud_play_string_struct*) string_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_play_string_req(src_mod_id, string_param);
    if (data_p->blocking)
    {
        AUD_WAIT_EVENT(AUD_EVT_PLAY);
    }
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_string
 * DESCRIPTION
 *  This function is to stop audio string.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_string(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_stop_string_req(src_mod_id, src_id);
    AUD_WAIT_EVENT(AUD_EVT_STOP);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_play_file
 * DESCRIPTION
 *  This function is to play audio file.
 * PARAMETERS
 *  src_mod_id      [IN]        void *file_param
 *  file_param      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_play_file(module_type src_mod_id, void *file_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_play_file_req(src_mod_id, file_param);
    AUD_WAIT_EVENT(AUD_EVT_PLAY);
    return aud_result;
}

#ifdef __RICH_AUDIO_PROFILE__


/*****************************************************************************
 * FUNCTION
 *  media_aud_start_calc_spectrum
 * DESCRIPTION
 *  This function is to send the message to start to calculate the audio spectrum tops and vals
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_start_calc_spectrum(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_start_calc_spectrum_req(src_mod_id);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_calc_spectrum
 * DESCRIPTION
 *  This function is to send the message to stop calculating the audio spectrum tops and vals
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_calc_spectrum(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_stop_calc_spectrum_req(src_mod_id);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_get_spectrum
 * DESCRIPTION
 *  This function is to get the audio spectrum tops and vals:
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8* top_p, kal_uint8* val_p
 *  top_p           [?]         
 *  val_p           [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_spectrum(module_type src_mod_id, kal_uint8 *top_p, kal_uint8 *val_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_get_spectrum_req(src_mod_id, top_p, val_p);
    AUD_WAIT_EVENT(AUD_EVT_GET_SPECTRUM);
    return aud_result;
}
#endif /* __RICH_AUDIO_PROFILE__ */ 


/*****************************************************************************
 * FUNCTION
 *  media_aud_get_duration
 * DESCRIPTION
 *  This function is to get the audio file duration.
 * PARAMETERS
 *  src_mod_id      [IN]        void* file_name, kal_uint32* time_p
 *  file_name       [?]         
 *  time_p          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_duration(module_type src_mod_id,
                                 void *file_name,
                                 kal_uint8 *audio_data,
                                 kal_uint32 len,
                                 kal_uint8 format,
                                 kal_uint32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    *time_p = 0;

    aud_send_get_duration_req(src_mod_id, KAL_FALSE, file_name, audio_data, len, format);

    AUD_WAIT_EVENT(AUD_EVT_GET_DURATION);
    *time_p = aud_value;
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_get_progress_time
 * DESCRIPTION
 *  This function is to get the progress time (milliseconds) of playing audio file
 * PARAMETERS
 *  src_mod_id          [IN]        kal_uint32* progress_time_p
 *  progress_time_p     [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_get_progress_time(module_type src_mod_id, kal_uint32 *progress_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    *progress_time_p = 0;
    aud_send_get_progress_time_req(src_mod_id);
    AUD_WAIT_EVENT(AUD_EVT_GET_PROGRESS_TIME);
    *progress_time_p = aud_value;
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_progress_time
 * DESCRIPTION
 *  This function is to set the progress time (milliseconds) of playing audio file
 * PARAMETERS
 *  src_mod_id          [IN]        kal_uint32 progress_time
 *  progress_time       [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_set_progress_time(module_type src_mod_id, kal_uint32 progress_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_set_progress_time_req(src_mod_id, progress_time);
    AUD_WAIT_EVENT(AUD_EVT_SET_PROGRESS_TIME);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_check_is_pure_audio
 * DESCRIPTION
 *  This function is to check if a file pure audio file
 * PARAMETERS
 *  src_mod_id      [IN]        void* file_name, kal_uint32* time_p
 *  file_name       [?]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_aud_check_is_pure_audio(module_type src_mod_id, void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;

    aud_send_check_is_pure_audio_req(src_mod_id, file_name);

    AUD_WAIT_EVENT(AUD_EVT_IS_PURE_AUDIO);
    return (kal_bool)aud_result;
}


#ifndef MED_V_NOT_PRESENT

/*****************************************************************************
 * FUNCTION
 *  media_aud_start_build_cache
 * DESCRIPTION
 *  This function is to start audio build cache
 * PARAMETERS
 *  src_mod_id          [IN]
 *  cache_parm          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_start_build_cache(module_type src_mod_id, void *cache_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    aud_send_start_build_cache_req(src_mod_id,cache_parm);
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_START);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_close_build_cache
 * DESCRIPTION
 *  This function is to close audio build cache
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_close_build_cache(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    aud_send_close_build_cache_req(src_mod_id);
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_CLOSE);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  media_aud_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to reset audio build cache variables
 * PARAMETERS
 *  src_mod_id          [IN]
 * RETURNS
 * 
 *****************************************************************************/
void media_aud_reset_build_cache_variables(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    aud_send_reset_build_cache_vars_req(src_mod_id);
    AUD_CACUE_WAIT_EVENT(AUD_CACHE_EVT_RESET);
    return;
}
#endif /*MED_V_NOT_PRESENT*/

/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_file
 * DESCRIPTION
 *  This function is to stop audio file.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_file(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_stop_file_req(src_mod_id, src_id);
    AUD_WAIT_EVENT(AUD_EVT_STOP);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_start_record
 * DESCRIPTION
 *  This function is to start recording audio.
 * PARAMETERS
 *  src_mod_id          [IN]        kal_wchar* file_name, kal_uint8 format
 *  file_name           [?]         
 *  format              [IN]        
 *  quality             [IN]        0: Low, >0: High
 *  default_input       [IN]        
 *  input_source        [IN]        
 *  size_limit          [IN]        Max record size in byte. 0: unlimited
 *  time_limit          [IN]        Max record time in sec.  0: unlimited
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_start_record(
            module_type src_mod_id,
            kal_wchar *file_name,
            kal_uint8 format,
            kal_uint8 quality,            
            kal_bool default_input,
            kal_uint8 input_source,
            kal_uint32 size_limit,
            kal_uint32 time_limit)            
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_record_req(src_mod_id, file_name, format, quality, default_input, input_source, size_limit, time_limit);
    AUD_WAIT_EVENT(AUD_EVT_RECORD);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_stop_record
 * DESCRIPTION
 *  This function is to stop recording audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_stop_record(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_stop_record_req(src_mod_id, src_id);
    AUD_WAIT_EVENT(AUD_EVT_STOP);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_pause
 * DESCRIPTION
 *  This function is to pause audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_pause(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_pause_req(src_mod_id, src_id);
    AUD_WAIT_EVENT(AUD_EVT_PAUSE);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_resume
 * DESCRIPTION
 *  This function is to resume audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_resume(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_resume_req(src_mod_id, src_id);
    AUD_WAIT_EVENT(AUD_EVT_RESUME);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_store
 * DESCRIPTION
 *  This function is to pause audio and store play info.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  src_id          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_store(module_type src_mod_id, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_store_req(src_mod_id, src_id);
    AUD_WAIT_EVENT(AUD_EVT_PAUSE);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_restore
 * DESCRIPTION
 *  This function is to resume audio.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 src_id
 *  file_param      [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_restore(module_type src_mod_id, void *file_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_restore_req(src_mod_id, file_param);
    AUD_WAIT_EVENT(AUD_EVT_RESUME);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_block
 * DESCRIPTION
 *  This function is to block access to audio functions from all module except the given one.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint16 mod_id, kal_uint8 level
 *  mod_id          [IN]        
 *  level           [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_block(module_type src_mod_id, kal_uint16 mod_id, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_block_req(src_mod_id, mod_id, level);
    AUD_WAIT_EVENT(AUD_EVT_BLOCK);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_headset_mode_output_path
 * DESCRIPTION
 *  This function is to set headset mode output path.
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 device
 *  device          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_set_headset_mode_output_path(module_type src_mod_id, kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_set_headset_mode_output_path_req(src_mod_id, device);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_set_vibrator_enabled
 * DESCRIPTION
 *  This function is to set vibrator enabled
 * PARAMETERS
 *  src_mod_id      [IN]        kal_uint8 enable
 *  enable          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_aud_set_vibrator_enabled(module_type src_mod_id, kal_uint8 enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_set_vibrator_enabled_req(src_mod_id, enable);
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_power_on(module_type src_mod_id, kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_fmr_power_on_req(src_mod_id, output_path);
    AUD_WAIT_EVENT(AUD_EVT_FMR_ON);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_power_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_power_off(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_fmr_power_off_req(src_mod_id);
    AUD_WAIT_EVENT(AUD_EVT_FMR_OFF);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_set_freq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  freq            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_set_freq(module_type src_mod_id, kal_uint16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_fmr_set_freq_req(src_mod_id, freq);
    AUD_WAIT_EVENT(AUD_EVT_FMR_SET);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mute            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_mute(module_type src_mod_id, kal_uint8 mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_fmr_mute_req(src_mod_id, mute);
    AUD_WAIT_EVENT(AUD_EVT_FMR_MUTE);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_fmr_evaluate_threshold
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_fmr_evaluate_threshold(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_result = MED_RES_OK;
    aud_send_fmr_evaluate_threshold_req(src_mod_id);
    AUD_WAIT_EVENT(AUD_EVT_FMR_EVA_THRESHOLD);
    return aud_result;
}


// ANALOG_TV_SUPPORT
//Analog tv begin   add by Jonathan 
#ifdef __MED_TLG_TV_MOD__
kal_int32 media_aud_analog_tv_power_on(module_type src_mod_id)
{
    
   aud_result=MED_RES_OK;
   aud_send_analog_tv_power_up_req(src_mod_id);
   TLG_TV_WAIT_EVENT(TLG_TV_EVT_PWR_ON);
   return aud_result;
   
}

kal_int32 media_aud_analog_tv_power_off(module_type src_mod_id)
{
  
   aud_result=MED_RES_OK;
   aud_send_analog_tv_power_down_req(src_mod_id);
   TLG_TV_WAIT_EVENT(TLG_TV_EVT_PWR_OFF);
   return aud_result;
   
}
kal_int32 media_aud_analog_tv_open_path(module_type src_mod_id)
{
   aud_result=MED_RES_OK;
   aud_send_analog_tv_open_path_req(src_mod_id);
   TLG_TV_WAIT_EVENT(TLG_TV_EVT_OPEN_PATH);
   return aud_result;
}


kal_int32 media_aud_analog_tv_close_path(module_type src_mod_id)
{
   aud_result=MED_RES_OK;
   aud_send_analog_tv_close_path_req(src_mod_id);
   TLG_TV_WAIT_EVENT(TLG_TV_EVT_CLOSE_PATH);
   return aud_result;
}

kal_int32 media_aud_analog_tv_mute(module_type src_mod_id, kal_uint8 mute)
{
   aud_result=MED_RES_OK;
   aud_send_analog_tv_mute_req(src_mod_id, mute);
   TLG_TV_WAIT_EVENT(TLG_TV_EVT_MUTE);
   return aud_result;
}
#endif //#ifdef __MED_TLG_TV_MOD__

#ifdef __MED_MMA_MOD__
/********** MMA *****************/


/*****************************************************************************
 * FUNCTION
 *  mma_set_result
 * DESCRIPTION
 *  This function is set the mma status.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_result = result;
    AUD_VALUE_TRACE(result, -1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mma_set_handle
 * DESCRIPTION
 *  This function is set the mma media handle.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_set_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_handle = handle;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_open
 * DESCRIPTION
 *  This function is to open mma resource.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  param           [IN]        
 *  result          [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_open(module_type src_mod_id, mma_player_struct *param, kal_int32 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_open_req(src_mod_id, (kal_int32) param);
    MMA_WAIT_EVENT(MMA_EVT_OPEN);
    *result = mma_result;
    return mma_handle;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_close
 * DESCRIPTION
 *  This function is to close midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_close(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_close_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_CLOSE);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_play
 * DESCRIPTION
 *  This function is to play midi.
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_play(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_play_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_PLAY);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_stop
 * DESCRIPTION
 *  This function is to stop midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_stop(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_stop_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_STOP);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_pause
 * DESCRIPTION
 *  This function is to pause midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_pause(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_pause_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_PAUSE);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_resume
 * DESCRIPTION
 *  This function is to resume midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_resume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_resume_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_RESUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_audio_info
 * DESCRIPTION
 *  This function is to get audio information
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32 : Is get audio info success
 *****************************************************************************/
kal_int32 media_mma_aud_get_audio_info(module_type src_mod_id, kal_wchar* file_path, kal_uint8 media_type, kal_uint8* data, kal_uint32 data_len, void *audio_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_audio_info_req(src_mod_id, file_path, media_type, data, data_len, audio_info);
    MMA_WAIT_EVENT(MMA_EVT_GET_AUD_INFO);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_duration
 * DESCRIPTION
 *  This function is to get duration of audio.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_duration(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_duration_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_GET_DURATION);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_duration_by_data
 * DESCRIPTION
 *  This function is to get duration of midi by given midi data string.
 * PARAMETERS
 *  media_type      [IN]        
 *  data            [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_duration_by_data(kal_uint8 media_type, const kal_uint8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JSmf_GetMidiDuration(data);
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_current_time
 * DESCRIPTION
 *  This function is to get current time of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_current_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_current_time_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_GET_CURR_TIME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_start_time
 * DESCRIPTION
 *  This function is to set start time of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  start_time      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_start_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_start_time_req(src_mod_id, media_type, handle, start_time);
    MMA_WAIT_EVENT(MMA_EVT_SET_START_TIME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_stop_time
 * DESCRIPTION
 *  This function is to set stop time of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  stop_time       [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_stop_time(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 stop_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_stop_time_req(src_mod_id, media_type, handle, stop_time);
    MMA_WAIT_EVENT(MMA_EVT_SET_STOP_TIME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_volume
 * DESCRIPTION
 *  This function is to get volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 media_mma_aud_get_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_get_volume_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_GET_VOLUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_volume
 * DESCRIPTION
 *  This function is to set volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  volume          [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_volume_req(src_mod_id, media_type, handle, volume);
    MMA_WAIT_EVENT(MMA_EVT_SET_VOLUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_pitch
 * DESCRIPTION
 *  This function is to get pitch of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_pitch(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_GetPitchTranspose((Media_Handle*) handle);
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            return (kal_int32) JTone_GetPitchShift((Media_Handle*) handle);
    #endif
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_pitch
 * DESCRIPTION
 *  This function is to set pitch of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  pitch           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_pitch(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 pitch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_pitch_req(src_mod_id, media_type, handle, pitch);
    MMA_WAIT_EVENT(MMA_EVT_SET_PITCH);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_rate
 * DESCRIPTION
 *  This function is to get rate of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_rate(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_GetRate((Media_Handle*) handle);
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_rate
 * DESCRIPTION
 *  This function is to set rate of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  rate            [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_rate(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 rate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_rate_req(src_mod_id, media_type, handle, rate);
    MMA_WAIT_EVENT(MMA_EVT_SET_RATE);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_tempo
 * DESCRIPTION
 *  This function is to get tempo of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_get_tempo(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_GetTempo((Media_Handle*) handle);
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_tempo
 * DESCRIPTION
 *  This function is to set tempo of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  tempo           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_tempo(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_int32 tempo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_tempo_req(src_mod_id, media_type, handle, tempo);
    MMA_WAIT_EVENT(MMA_EVT_SET_TEMPO);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_open_device
 * DESCRIPTION
 *  This function is to open device of midi.
 * PARAMETERS
 *  media_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_open_device(module_type src_mod_id, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_open_device_req(src_mod_id, media_type);
    MMA_WAIT_EVENT(MMA_EVT_OPEN_DEVICE);
    return mma_handle;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_close_device
 * DESCRIPTION
 *  This function is to close device of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_close_device(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_close_device_req(src_mod_id, media_type, handle);
    MMA_WAIT_EVENT(MMA_EVT_CLOSE_DEVICE);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_send_long_msg
 * DESCRIPTION
 *  This function is to send long msg of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  buf             [?]         kal_uint16 len
 *  len             [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_send_long_msg(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 *buf, kal_uint16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_send_long_msg_req(src_mod_id, media_type, handle, buf, len);
    MMA_WAIT_EVENT(MMA_EVT_SEND_LONG_MSG);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_send_short_msg
 * DESCRIPTION
 *  This function is to send short msg of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  type            [IN]        kal_uint8 data1, kal_uint8 data2
 *  data1           [IN]        
 *  data2           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_send_short_msg(
            module_type src_mod_id, 
            kal_int32 handle,
            kal_uint8 media_type,
            kal_uint8 type,
            kal_uint8 data1,
            kal_uint8 data2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_send_short_msg_req(src_mod_id, media_type, handle, type, data1, data2);
    MMA_WAIT_EVENT(MMA_EVT_SEND_SHORT_MSG);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_channel_volume
 * DESCRIPTION
 *  This function is to get channel volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 media_mma_aud_get_channel_volume(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_GetChannelVolume((Media_Handle*) handle, channel);
        default:
            ASSERT(0);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_channel_volume
 * DESCRIPTION
 *  This function is to set channel volume of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        kal_uint8 level
 *  level           [IN]        
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_channel_volume(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_uint8 channel, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_channel_volume_req(src_mod_id, media_type, handle, channel, level);
    MMA_WAIT_EVENT(MMA_EVT_SET_CHANNEL_VOLUME);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_program
 * DESCRIPTION
 *  This function is to get program of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        kal_int16* bank, kal_int8* program
 *  bank            [?]         
 *  program         [?]         
 *  kal_int32 handler(?)
 * RETURNS
 *  void
 *****************************************************************************/
void media_mma_aud_get_program(
        kal_int32 handle,
        kal_uint8 media_type,
        kal_uint8 channel,
        kal_int16 *bank,
        kal_int8 *program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            JMidi_GetProgram((Media_Handle*) handle, channel, bank, program);
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_program
 * DESCRIPTION
 *  This function is to set program of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  channel         [IN]        kal_uint8 bank, kal_uint8 program
 *  bank            [IN]        
 *  program         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_program(
            module_type src_mod_id, 
            kal_int32 handle,
            kal_uint8 media_type,
            kal_uint8 channel,
            kal_uint8 bank,
            kal_uint8 program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_program_req(src_mod_id, media_type, handle, channel, bank, program);
    MMA_WAIT_EVENT(MMA_EVT_SET_PROGRAM);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_bank_support
 * DESCRIPTION
 *  This function is to check if bank query supported.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool media_mma_aud_bank_support(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_isBankQuerySupported();
        default:
            ASSERT(0);
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_bank_list
 * DESCRIPTION
 *  This function is to get the bank list of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  custom          [IN]        const kal_int16 **buf, kal_int16 *len
 *  buf             [IN]        
 *  len             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_mma_aud_get_bank_list(
        kal_int32 handle,
        kal_uint8 media_type,
        kal_bool custom,
        const kal_int16 **buf,
        kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            JMidi_GetBankList(custom, buf, len);
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_program_list
 * DESCRIPTION
 *  This function is to get the program list of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  bank            [IN]        const kal_int8 **buf, kal_int16 *len
 *  buf             [IN]        
 *  len             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void media_mma_aud_get_program_list(
        kal_int32 handle,
        kal_uint8 media_type,
        kal_int16 bank,
        const kal_int8 **buf,
        kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            JMidi_GetProgramList(bank, buf, len);
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_program_name
 * DESCRIPTION
 *  This function is to get the program name of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  bank            [IN]        const kal_int8 **buf, kal_int16 *len
 *  prog            [IN]        
 * RETURNS
 *  const kal_uint8*
 *****************************************************************************/
const kal_uint8 *media_mma_aud_get_program_name(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, kal_int8 prog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_GetProgramName(bank, prog);
        default:
            ASSERT(0);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_get_key_name
 * DESCRIPTION
 *  This function is to get the key name of midi.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  bank            [IN]        const kal_int8 **buf, kal_int16 *len
 *  prog            [IN]        
 *  key             [IN]        
 * RETURNS
 *  const kal_uint8*
 *****************************************************************************/
const kal_uint8 *media_mma_aud_get_key_name(
                    kal_int32 handle,
                    kal_uint8 media_type,
                    kal_int16 bank,
                    kal_int8 prog,
                    kal_int8 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JMidi_GetKeyName(bank, prog, key);
        default:
            ASSERT(0);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_set_data
 * DESCRIPTION
 *  This function is to set data of tone.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_set_data(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, mma_player_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_set_data_req(src_mod_id, media_type, handle, (kal_int32) param);
    MMA_WAIT_EVENT(MMA_EVT_SET_DATA);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_write_data_ind
 * DESCRIPTION
 *  This function is to indicate MMA progressive download has wrtie more data.
 * PARAMETERS
 *  handle          [IN]        
 *  media_type      [IN]        
 *  param           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 media_mma_aud_write_data_ind(module_type src_mod_id, kal_int32 handle, kal_uint8 media_type, kal_bool is_finish)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_mma_write_data_ind_req(src_mod_id, media_type, handle, is_finish);
    MMA_WAIT_EVENT(MMA_EVT_WRITE_DATA_IND);
    return mma_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_mma_aud_is_sp_midi
 * DESCRIPTION
 *  This function is to check if the midi type is sp-midi
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 media_mma_aud_is_sp_midi(kal_int32 handle, kal_uint8 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
            return JSmf_isSpMidi((Media_Handle*)handle);
        default:
            ASSERT(0);
    }
    return KAL_FALSE;
}

#endif /* __MED_MMA_MOD__ */ 

#ifdef __MED_VR_MOD__


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_get_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_get_version(module_type src_mod_id, kal_uint8 mode, kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_get_version_req(src_mod_id, mode, lang);
    AUD_WAIT_EVENT(AUD_EVT_VR_GET_VER);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_get_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  sim             [?]         
 *  diff            [?]         
 *  rej             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_get_param(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_int16 *sim,
            kal_int16 *diff,
            kal_int16 *rej)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_get_param_req(src_mod_id, mode, lang, sim, diff, rej);
    AUD_WAIT_EVENT(AUD_EVT_VR_GET_PARAM);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_set_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  sim             [IN]        
 *  diff            [IN]        
 *  rej             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_set_param(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_int16 sim,
            kal_int16 diff,
            kal_int16 rej)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_set_param_req(src_mod_id, mode, lang, sim, diff, rej);
    AUD_WAIT_EVENT(AUD_EVT_VR_SET_PARAM);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_init_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_init_rcg(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_init_rcg_req(src_mod_id, session_id, mode, lang, group_id);
    AUD_WAIT_EVENT(AUD_EVT_VR_INIT_RCG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_init_trn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_init_trn(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_init_trn_req(src_mod_id, session_id, mode, lang, group_id, word_id);
    AUD_WAIT_EVENT(AUD_EVT_VR_INIT_TRN);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_voice_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  seq_no          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_voice_in(module_type src_mod_id, kal_uint32 session_id, kal_uint8 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_voice_in_req(src_mod_id, session_id, seq_no);
    AUD_WAIT_EVENT(AUD_EVT_VR_VOICE_IN);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_del_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_del_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_del_tag_req(src_mod_id, mode, lang, group_id, word_id);
    AUD_WAIT_EVENT(AUD_EVT_VR_DEL_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_check_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_check_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_check_tag_req(src_mod_id, mode, lang, group_id, word_id);
    AUD_WAIT_EVENT(AUD_EVT_VR_CHECK_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_sync_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  id_length_p     [?]         
 *  id_array        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_sync_db(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 *id_length_p,
            kal_uint16 *id_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_sync_db_req(src_mod_id, mode, lang, group_id, id_length_p, id_array);
    AUD_WAIT_EVENT(AUD_EVT_VR_SYNC_DB);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_play_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_play_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 word_id,
            kal_uint16 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_play_tag_req(src_mod_id, mode, lang, group_id, word_id, identifier);
    AUD_WAIT_EVENT(AUD_EVT_VR_PLAY_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_get_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  folder_name     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_get_dir(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_get_dir_req(src_mod_id, mode, lang, group_id, folder_name);
    AUD_WAIT_EVENT(AUD_EVT_VR_GET_DIR);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_add_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  id_length       [IN]        
 *  id_array        [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vr_add_tag(
            module_type src_mod_id,
            kal_uint8 mode,
            kal_uint8 lang,
            kal_uint8 group_id,
            kal_uint16 id_length,
            kal_uint16 *id_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_add_tag_req(src_mod_id, mode, lang, group_id, id_length, id_array);
    AUD_WAIT_EVENT(AUD_EVT_VR_ADD_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vr_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vr_abort(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vr_abort_req(src_mod_id);
    AUD_WAIT_EVENT(AUD_EVT_VR_ABORT);
}
#endif /* __MED_VR_MOD__ */ 

#ifdef __MED_VRSI_MOD__


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_init(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_init_req(src_mod_id);
    VRSI_WAIT_EVENT(VRSI_EVT_INIT);
    return aud_result;
}

/* kal_uint32 media_aud_vrsi_new_session_id(void); */


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_add_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  session_id          [IN]        
 *  grammar             [?]         
 *  tag_num             [IN]        
 *  name_list           [IN]        
 *  long_list           [?]         
 *  is_name_list        [?]         
 *  id_list             [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_add_tags(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 *grammar,
            kal_uint16 tag_num,
            kal_uint16 **name_list,
            kal_int32 *long_list,
            kal_uint8 *is_name_list,
            kal_uint16 *id_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_add_tags_req(src_mod_id, session_id, grammar, tag_num, name_list, long_list, is_name_list, id_list);
    VRSI_WAIT_EVENT(VRSI_EVT_ADD_TAGS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_cmd_trn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_name        [?]         
 *  tag_long        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_cmd_trn(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 *grammar,
            kal_uint16 *tag_name,
            kal_int32 tag_long)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_cmd_trn_req(src_mod_id, session_id, grammar, tag_name, tag_long);
    VRSI_WAIT_EVENT(VRSI_EVT_START_CMD_TRN);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_cmd_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_cmd_rcg(module_type src_mod_id, kal_uint32 session_id, kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_cmd_rcg_req(src_mod_id, session_id, grammar);
    VRSI_WAIT_EVENT(VRSI_EVT_START_CMD_RCG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_digit_rcg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  lang            [IN]        
 *  limit           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_digit_rcg(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 lang,
            kal_uint16 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_digit_rcg_req(src_mod_id, session_id, lang, limit);
    VRSI_WAIT_EVENT(VRSI_EVT_START_DIGIT_RCG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_start_digit_adapt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_start_digit_adapt(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_start_digit_adapt_req(src_mod_id, session_id, lang);
    VRSI_WAIT_EVENT(VRSI_EVT_START_DIGIT_ADAPT);
    return aud_result;
}

/* void media_aud_vrsi_prompt_cnf(module_type src_mod_id, kal_uint32 session_id); */


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_play_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_id          [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_play_tag(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint8 *grammar,
            kal_uint16 tag_id,
            kal_uint8 volume,
            kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_play_tag_req(src_mod_id, session_id, grammar, tag_id, volume, output_path);
    VRSI_WAIT_EVENT(VRSI_EVT_PLAY_TAG);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_play_TTS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 *  text            [?]         
 *  volume          [IN]        
 *  output_path     [IN]        
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_play_TTS(
            module_type src_mod_id,
            kal_uint32 session_id,
            kal_uint16 *text,
            kal_uint8 volume,
            kal_uint8 output_path,
            kal_uint8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_play_TTS_req(src_mod_id, session_id, text, volume, output_path, lang);
    VRSI_WAIT_EVENT(VRSI_EVT_PLAY_TTS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_get_tag_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_get_tag_num(module_type src_mod_id, kal_uint8 *grammar, kal_int32 *tag_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_get_tag_num_req(src_mod_id, grammar, tag_num);
    VRSI_WAIT_EVENT(VRSI_EVT_GET_TAG_NUM);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_get_tag_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 *  name_list       [IN]        
 *  long_list       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_get_tag_info(
            module_type src_mod_id,
            kal_uint8 *grammar,
            kal_int32 tag_num,
            kal_uint16 *id_list,
            kal_uint16 **name_list,
            kal_int32 *long_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_get_tag_info_req(src_mod_id, grammar, tag_num, id_list, name_list, long_list);
    VRSI_WAIT_EVENT(VRSI_EVT_GET_TAG_INFO);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_del_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_del_tags(module_type src_mod_id, kal_uint8 *grammar, kal_int32 tag_num, kal_uint16 *id_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_del_tags_req(src_mod_id, grammar, tag_num, id_list);
    VRSI_WAIT_EVENT(VRSI_EVT_DEL_TAGS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_reset_tags
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_reset_tags(module_type src_mod_id, kal_uint8 *grammar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_reset_tags_req(src_mod_id, grammar);
    VRSI_WAIT_EVENT(VRSI_EVT_RESET_TAGS);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_sync_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  grammar         [?]         
 *  tag_num         [IN]        
 *  id_list         [?]         
 *  name_list       [IN]        
 *  sync_flag       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_sync_db(
            module_type src_mod_id,
            kal_uint8 *grammar,
            kal_int32 tag_num,
            kal_uint16 *id_list,
            kal_uint16 **name_list,
            kal_uint8 *sync_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_sync_db_req(src_mod_id, grammar, tag_num, id_list, name_list, sync_flag);
    VRSI_WAIT_EVENT(VRSI_EVT_SYNC_DB);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_abort(module_type src_mod_id, kal_uint32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_abort_req(src_mod_id, session_id);
    VRSI_WAIT_EVENT(VRSI_EVT_ABORT);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void media_aud_vrsi_close(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_vrsi_close_req(src_mod_id);
    VRSI_WAIT_EVENT(VRSI_EVT_CLOSE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_vrsi_get_error_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_vrsi_get_error_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return aud_vrsi_error();
}
#endif /* __MED_VRSI_MOD__ */ 

#ifdef __MED_SND_MOD__


/*****************************************************************************
 * FUNCTION
 *  aud_snd_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bgsnd_result = result;
    AUD_VALUE_TRACE(result, -1, -1);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_check_byte_stream_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_check_byte_stream_format(module_type src_mod_id, kal_uint8 *data, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_set_result(MED_RES_OK);
    aud_send_snd_check_byte_stream_format_req(src_mod_id, data, size);

    EFFECT_WAIT_EVENT(SND_EVT_CHECK);
    return bgsnd_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_check_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_name       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_check_file_format(module_type src_mod_id, kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_set_result(MED_RES_OK);
    aud_send_snd_check_file_format_req(src_mod_id, file_name);

    EFFECT_WAIT_EVENT(SND_EVT_CHECK);
    return bgsnd_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_play_byte_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 *  repeats         [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_play_byte_stream(
            module_type src_mod_id,
            kal_uint8 *data,
            kal_int32 size,
            kal_int16 repeats,
            kal_uint8 volume,
            kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_play_byte_stream_req(src_mod_id, data, size, repeats, volume, output_path);

    EFFECT_WAIT_EVENT(SND_EVT_PLAY);
    return bgsnd_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_play_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_name       [?]         
 *  repeats         [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_play_file(
            module_type src_mod_id,
            kal_wchar *file_name,
            kal_int16 repeats,
            kal_uint8 volume,
            kal_uint8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_play_file_req(src_mod_id, file_name, repeats, volume, output_path);

    EFFECT_WAIT_EVENT(SND_EVT_PLAY);
    return bgsnd_result;

}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_stop_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_stop_play(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_stop_play_req(src_mod_id);

    EFFECT_WAIT_EVENT(SND_EVT_STOP);
    return bgsnd_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_snd_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  volume          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_snd_set_volume(module_type src_mod_id, kal_uint8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_snd_set_volume_req(src_mod_id, volume);

    EFFECT_WAIT_EVENT(SND_EVT_SET);
    return bgsnd_result;
}

#endif /* __MED_SND_MOD__ */ 


#if defined(__MED_AUD_AUDIO_EFFECT__)
/*****************************************************************************
 * FUNCTION
 *  aud_app_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_app_set_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_effect_result = result;
    AUD_VALUE_TRACE(result, -1, -1);
}
#endif /*#if defined(__MED_AUD_AUDIO_EFFECT__)*/


#if defined(__MED_AUD_TIME_STRETCH__)
/*****************************************************************************
 * FUNCTION
 *  media_stretch_check_stream_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  data            [?]         
 *  size            [IN]        
 *  format          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_check_stream_format(
            module_type src_mod_id,
            kal_uint8 *data,
            kal_uint32 size,
            kal_uint16 format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_check_stream_format_req_struct *msg_p = (media_stretch_check_stream_format_req_struct*)
        construct_local_para(sizeof(media_stretch_check_stream_format_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->data_p = data;
    msg_p->size = size;
    msg_p->format = format;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_CHECK_STREAM_FORMAT_REQ, msg_p);

    EFFECT_WAIT_EVENT(TS_EVT_CHECK);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_stretch_check_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  file_path       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_check_file_format(module_type src_mod_id, kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_check_file_format_req_struct *msg_p = (media_stretch_check_file_format_req_struct*)
        construct_local_para(sizeof(media_stretch_check_file_format_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->file_path = file_path;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_CHECK_FILE_FORMAT_REQ, msg_p);

    EFFECT_WAIT_EVENT(TS_EVT_CHECK);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_stretch_set_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  speed           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_set_speed(module_type src_mod_id, kal_uint16 speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_stretch_set_speed_req_struct *msg_p = (media_stretch_set_speed_req_struct*)
        construct_local_para(sizeof(media_stretch_set_speed_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->speed = speed;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_SET_SPEED_REQ, msg_p);

    EFFECT_WAIT_EVENT(TS_EVT_SET);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_stretch_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_stretch_close(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_STRETCH_CLOSE_REQ, NULL);

    EFFECT_WAIT_EVENT(TS_EVT_CLOSE);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_TIME_STRETCH__) */


#if defined(__MED_AUD_REVERB__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_set_coeff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  coeff_table_ptr     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_reverb_set_coeff(kal_int16 *coeff_table_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_reverb_set_coeff_req_struct *msg_p = (media_reverb_set_coeff_req_struct*)
        construct_local_para(sizeof(media_reverb_set_coeff_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->coeff_table_ptr = coeff_table_ptr;

    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_REVERB_SET_COEFF_REQ, msg_p);

    EFFECT_WAIT_EVENT(REVERB_EVT_SET);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_reverb_turn_on_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_REVERB_TURN_ON_REQ, NULL);

    EFFECT_WAIT_EVENT(REVERB_EVT_ON);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_reverb_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_REVERB_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(REVERB_EVT_OFF);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_REVERB__) */ 

#if defined(__MED_AUD_SURROUND__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_surround_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_surround_turn_on_effect(kal_uint8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_surround_turn_on_req_struct *msg_p = (media_surround_turn_on_req_struct*)
        construct_local_para(sizeof(media_surround_turn_on_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->mode= mode;

    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_SURROUND_TURN_ON_REQ, msg_p);

    EFFECT_WAIT_EVENT(SURROUND_EVT_ON);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_surround_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_surround_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_SURROUND_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(SURROUND_EVT_OFF);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_SURROUND__) */


#if defined(__MED_AUD_EQUALIZER__)
/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_set_coeff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  coeff_table_ptr     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_eq_set_magnitude(kal_int8 *magnitude)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_eq_set_magnitude_req_struct *msg_p = (media_aud_eq_set_magnitude_req_struct*)
        construct_local_para(sizeof(media_aud_eq_set_magnitude_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(msg_p->magnitude, magnitude, 8);

    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_EQ_SET_MAGNITUDE_REQ, msg_p);

    EFFECT_WAIT_EVENT(EQ_EVT_SET);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_on_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_eq_turn_on_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_EQ_TURN_ON_REQ, NULL);

    EFFECT_WAIT_EVENT(EQ_EVT_ON);
    return audio_effect_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_reverb_turn_off_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_eq_turn_off_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(stack_int_get_active_module_id(), (kal_uint16) MSG_ID_MEDIA_AUD_EQ_TURN_OFF_REQ, NULL);

    EFFECT_WAIT_EVENT(EQ_EVT_OFF);
    return audio_effect_result;
}
#endif /* #if defined(__MED_AUD_EQUALIZER__) */ 


#ifdef __MED_GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_set_attr_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_set_attr_req(module_type src_mod_id, kal_uint32 attr_id, kal_uint32 attr_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_tts_set_attr_req(src_mod_id, attr_id, attr_value);
    TTS_WAIT_EVENT(TTS_EVT_SET_ATTR);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_play_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_play_req(module_type src_mod_id, void *tts_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_tts_play_req(src_mod_id, tts_param);
    TTS_WAIT_EVENT(TTS_EVT_PLAY);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_stop_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_stop_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_STOP_REQ, NULL);

    TTS_WAIT_EVENT(TTS_EVT_STOP);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_pause_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_pause_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_PAUSE_REQ, NULL);

    TTS_WAIT_EVENT(TTS_EVT_PAUSE);
    return aud_result;
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_tts_resume_req()
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 media_aud_tts_resume_req(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_AUD_TTS_RESUME_REQ, NULL);

    TTS_WAIT_EVENT(TTS_EVT_RESUME);
    return aud_result;
}
#endif /*#ifdef __MED_GENERAL_TTS__*/


#ifdef __MED_BT_MOD__
/*****************************************************************************
 * FUNCTION
 *  media_aud_bt_audio_close
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void media_aud_bt_audio_close(kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_bt_audio_close_req(stack_int_get_active_module_id(), profile);

    AUD_WAIT_EVENT(AUD_EVT_BT_CLOSE_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  media_aud_bt_audio_close
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void media_aud_bt_turn_off_audio(kal_uint8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_bt_audio_turn_off_req(stack_int_get_active_module_id(), profile);

    AUD_WAIT_EVENT(AUD_EVT_BT_TURN_OFF_AUDIO);
}
#endif /*#ifdef __MED_BT_MOD__*/

#endif /* MED_NOT_PRESENT */ 

