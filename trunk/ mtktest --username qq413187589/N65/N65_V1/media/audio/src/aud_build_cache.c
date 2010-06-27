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
 * Aud_build_cache.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes functions for audio cache building.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_V_NOT_PRESENT

/*==== INCLUDES =========*/

#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "time.h"
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
#include "med_v_struct.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#include "fat_fs.h"
#include "med_utility.h"
//#include "aud_build_cache.h"
#include "med_v_main.h"
#include "med_v_context.h"


extern kal_int16 med_get_media_type(kal_wchar *file_name);

typedef struct 
{
    STFSAL file;
    MHdl *handle_p;
    void* file_buf;
    void* proc_buf;
    kal_bool stop_build_cache;          /*for stopping the ongoing sending message to process*/
    kal_bool first_time_build_cache;    /*to prevent from mutiltiple audio file open*/
    kal_bool start_build_cache_success; /*to indicate if the start build cache success*/
    kal_uint32 build_cache_duration;    /*the total cached duration in ms*/
    kal_uint32 total_duration;          /*duration of current cached file (not actual total duratoin, 
                                        need to calculate in porportion to progress )*/   
    kal_uint32 prev_progress;           /*we use this variable to check whether update duration or not*/ 
    kal_bool total_duration_refined;    /*a flag to judge if total duration has been updated 
                                        at least once*/
} _audio_media_struct; 

static _audio_media_struct audio_media_cache;

//static kal_uint8 audio_cache_file_buf[CACHE_FILE_BUF_SIZE];
//static kal_uint8 audio_cache_proc_buf[CACHE_PROC_BUF_SIZE];

/*****************************************************************************
 * FUNCTION
 *  build_cache_reset_variables
 * DESCRIPTION
 *  to reset all build cache variable.
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
void build_cache_reset_variables()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_media_cache.first_time_build_cache = KAL_TRUE;
    audio_media_cache.start_build_cache_success = KAL_FALSE;
    audio_media_cache.stop_build_cache = KAL_TRUE;
    audio_media_cache.build_cache_duration = 0;
    audio_media_cache.total_duration = 0;
    audio_media_cache.prev_progress = 0 ;
    audio_media_cache.total_duration_refined = KAL_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  build_cache_calc_total_duration
 * DESCRIPTION
 *  to calculate more acturate total duration during build cache.
 * PARAMETERS
 *  kal_unit32      [in]     
 * RETURNS
 *  void
 *****************************************************************************/
void build_cache_calc_total_duration(kal_uint32 progress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(audio_media_cache.handle_p != NULL)
    {
        if(progress > audio_media_cache.prev_progress)
        {
//            audio_media_cache.total_duration = audio_media_cache.handle_p->GetTotalDuration(audio_media_cache.handle_p);        
            audio_media_cache.total_duration = audio_media_cache.handle_p->GetCacheDuration(audio_media_cache.handle_p);
            audio_media_cache.total_duration = ((kal_uint64)audio_media_cache.total_duration*100)/progress ;
            audio_media_cache.total_duration_refined = KAL_TRUE;

            kal_prompt_trace(MOD_MED_V, "MED_V: cache update duration : %d",audio_media_cache.total_duration);

            /*update*/                   
            audio_media_cache.prev_progress = progress ;            
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  build_cache_close
 * DESCRIPTION
 *  close the build cache context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void build_cache_close( void )
{
    /* if it's not started, skip it */
    if( audio_media_cache.handle_p != NULL )
    {
        /* close func */
        audio_media_cache.handle_p->Close( audio_media_cache.handle_p );

        /* close file */
        FSAL_Close( &audio_media_cache.file );

        /* reset handle & start flag */
        audio_media_cache.handle_p = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  build_cache_process
 * DESCRIPTION
 *  do the process of build cache incrementally
 * PARAMETERS
 *  progress_p     [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool build_cache_process( kal_uint32 *progress_p )
{
    Media_Status result;
    kal_uint32 ticks1, ticks2 ;
    
    ASSERT( audio_media_cache.handle_p != NULL );

    kal_get_time(&ticks1);
    /* do build cache incrementally */
    audio_media_cache.handle_p->BuildCache( audio_media_cache.handle_p, &result, progress_p );
    kal_get_time(&ticks2);
    kal_prompt_trace(MOD_MED_V, "MED_V: buildCache Time : %d", (ticks2 - ticks1) ); 

    audio_media_cache.build_cache_duration = audio_media_cache.handle_p->GetCacheDuration(audio_media_cache.handle_p);
    /*update total duration*/
    build_cache_calc_total_duration( *progress_p );

    kal_prompt_trace(MOD_MED_V, "MED_V: build process : after progress = %d",*progress_p);

/*    if(*progress_p >50)
   {
        result = MEDIA_FAIL ;
    }*/
            
    if( result == MEDIA_SUCCESS )
    {
        return KAL_TRUE;
    }
    else
    {
        /* handle build cache failed case */
        build_cache_close();
        audio_media_cache.stop_build_cache = KAL_TRUE;
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  build_cache_start
 * DESCRIPTION
 *  start the process of build cache
 * PARAMETERS
 *  filename      [IN]
 *  cache_p       [IN]
 *  cache_size    [IN]
 *  file_buf_p    [IN]
 *  file_buf_size [IN]
 *  proc_buf_p    [IN]
 *  proc_buf_size [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool build_cache_start( kal_wchar *filename, 
    void* cache_p, kal_int32 cache_size,
    void *file_buf_p, kal_int32 file_buf_size, 
    void *proc_buf_p, kal_int32 proc_buf_size )
{
    kal_int16 type;
    Media_VM_PCM_Param vpFormat;
    kal_uint32 progress_p;
    kal_bool result ;


    ASSERT( audio_media_cache.handle_p == NULL );

    /* get media type from filename extension */
    type = med_get_media_type( filename );

    if( type == MED_TYPE_NONE )
        return KAL_FALSE;

    /* open file */
    if( FSAL_Open( &audio_media_cache.file, filename, FSAL_READ ) != FSAL_OK )
        return KAL_FALSE;

    FSAL_SetBuffer( &audio_media_cache.file, file_buf_size, (kal_uint8*)file_buf_p );

    //memset( cache_p, 0, cache_size );

    /* determine which open func */
    switch( type )
    {
#ifdef AMR_DECODE
    case MED_TYPE_AMR:
#ifdef AMRWB_DECODE
    case MED_TYPE_AMR_WB:
#endif        
        vpFormat.mediaType = MED_TYPE_AMR;
        vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
        audio_media_cache.handle_p = AMR_Open( NULL, &audio_media_cache.file, &vpFormat );
        kal_prompt_trace(MOD_MED_V, "MED_V: build cache AWB, AMR");
        break;
#endif /* AMR_DECODE */
#ifdef DAF_DECODE
    case MED_TYPE_DAF:
#ifdef MUSICAM_DECODE
    case MED_TYPE_MUSICAM:
#endif
        audio_media_cache.handle_p = DAF_Open( NULL, &audio_media_cache.file, NULL );
        break;
#endif /* DAF_DECODE */
#ifdef AAC_DECODE
    case MED_TYPE_AAC:
        audio_media_cache.handle_p = AAC_Open( NULL, &audio_media_cache.file, NULL );
        kal_prompt_trace(MOD_MED_V, "MED_V: build cache AAC"); 
    break;
#endif /* AAC_DECODE */ 
    default:
        /*others shall be blocked by audply application */
        ASSERT(0);
    }

    /* handle open func fail case */
    if( audio_media_cache.handle_p == NULL )
    {
        FSAL_Close( &audio_media_cache.file );
        kal_prompt_trace(MOD_MED_V, "MED_V: build  start : NULL");               
        return KAL_FALSE;
    }

    audio_media_cache.handle_p->SetCacheTbl( audio_media_cache.handle_p, cache_p, NULL );
    audio_media_cache.handle_p->SetBuffer( audio_media_cache.handle_p, 
        (kal_uint8*)proc_buf_p, proc_buf_size );

    result = build_cache_process(&progress_p);

    if(result)
    {
        audio_media_cache.build_cache_duration = audio_media_cache.handle_p->GetCacheDuration(audio_media_cache.handle_p);
    }

    return result ;
}

/*****************************************************************************
 * FUNCTION
 *  Audio_start_build_cache
 * DESCRIPTION
 *  Start to build cache after audply next button is long preesd
 * PARAMETERS
 *  ilm_ptr     
 * RETURNS
 *  void
 *****************************************************************************/
void audio_start_build_cache(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_req_struct *msg_p = (media_visual_audio_cache_req_struct*)ilm_ptr->local_para_ptr;

    media_visual_audio_cache_process_struct *msg_p_out = (media_visual_audio_cache_process_struct*)
            construct_local_para(sizeof(media_visual_audio_cache_process_struct), TD_CTRL);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*start build cache if needed*/
    if(audio_media_cache.first_time_build_cache)
    {
        kal_bool result = build_cache_start( 
        msg_p->filename, 
        msg_p->cache_p, msg_p->cache_size, 
        msg_p->file_buf_p, msg_p->file_buf_size, 
        msg_p->proc_buf_p, msg_p->proc_buf_size);
        
        audio_media_cache.first_time_build_cache = KAL_FALSE;
        if(result)
        {
            audio_media_cache.start_build_cache_success = KAL_TRUE;
        }
        else
        {
            build_cache_reset_variables();
            aud_send_build_cache_fail_ind();
        }
    }
    else
    {
        audio_media_cache.build_cache_duration = audio_media_cache.handle_p->GetCacheDuration(audio_media_cache.handle_p);
    }

    /*send message to trigger build process*/
    if(audio_media_cache.start_build_cache_success)
    {
        msg_p_out->build_cache_progress = msg_p->build_cache_progress ;
        audio_media_cache.stop_build_cache = KAL_FALSE ;
        aud_send_process_build_cache_req(MOD_MED_V,msg_p_out);
    }
    
    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_START);
    
}

/*****************************************************************************
 * FUNCTION
 *  audio_stop_build_cache
 * DESCRIPTION
 *  Stop the build cache action after audply next button is up after long pressed
 * PARAMETERS
 *  ilm_ptr     
 * RETURNS
 *  void
 *****************************************************************************/
void audio_stop_build_cache(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*stop the build cache process*/
    audio_media_cache.stop_build_cache = KAL_TRUE ;
}

/*****************************************************************************
 * FUNCTION
 *  audio_close_build_cache
 * DESCRIPTION
 *  Close build cache context
 * PARAMETERS
 *  ilm_ptr     
 * RETURNS
 *  void
 *****************************************************************************/
void audio_close_build_cache(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*close build cache context*/
    build_cache_close();

    /*stop the build cache process*/
    audio_media_cache.stop_build_cache = KAL_TRUE ;
    
    /*to make next time build cache to open build cache context*/
    audio_media_cache.first_time_build_cache = KAL_TRUE ;    

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_CLOSE);
    
}


/*****************************************************************************
 * FUNCTION
 *  audio_process_build_cache
 * DESCRIPTION
 *  keep pushing the process of building cache
 * PARAMETERS
 *  ilm_ptr     
 * RETURNS
 *  void
 *****************************************************************************/
void audio_process_build_cache(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_process_struct *msg_p = (media_visual_audio_cache_process_struct*)ilm_ptr->local_para_ptr ;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!audio_media_cache.stop_build_cache)
    {
        kal_bool result ;
        /*process the building cache*/
        result = build_cache_process(msg_p->build_cache_progress);

        if(!result)
        {
            build_cache_reset_variables();
            aud_send_build_cache_fail_ind();
            return ;
        }

        /*take care if it's over 100%*/
        if(*(msg_p->build_cache_progress) <100)
        {
            media_visual_audio_cache_process_struct *msg_p_out = (media_visual_audio_cache_process_struct*)
                construct_local_para(sizeof(media_visual_audio_cache_process_struct), TD_CTRL);
            
            msg_p_out->build_cache_progress = msg_p->build_cache_progress ;
            aud_send_process_build_cache_req(MOD_MED_V,msg_p_out);
        }
     }    
}

/*****************************************************************************
 * FUNCTION
 *  audio_reset_build_cache_variables
 * DESCRIPTION
 *  reset all build cache variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void audio_reset_build_cache_variables(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    build_cache_reset_variables();

    AUD_CACHE_SET_EVENT(AUD_CACHE_EVT_RESET);      
}


/*****************************************************************************
 * FUNCTION
 *  medv_audio_get_cache_duration
 * DESCRIPTION
 *  for audio player to query the cached duration
 * PARAMETERS
 *  kal_unit32      [OUT]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool medv_audio_get_cache_duration(kal_uint32 *duration )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(audio_media_cache.handle_p != NULL)
    {
        *duration = audio_media_cache.build_cache_duration ;
        return KAL_TRUE ;
    }
    else
    {
        return KAL_FALSE ;
    }
}

/*****************************************************************************
 * FUNCTION
 *  medv_audio_get_total_duration
 * DESCRIPTION
 *  for audio player to query the total duration
 * PARAMETERS
 *  kal_unit32      [OUT]     
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool medv_audio_get_total_duration(kal_uint32 *duration )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(audio_media_cache.total_duration_refined)
    {
        *duration = audio_media_cache.total_duration;
        return KAL_TRUE ;
    }
    else
    {
        return KAL_FALSE ;
    }
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

#endif /* MED_V_NOT_PRESENT */ 

