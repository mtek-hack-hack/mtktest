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
 *   aud_snd.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to handle all messages for background sound effect. 
 *
 * Author:
 * -------
 *   
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_SND_MOD__

/* 
 * Local Variable
 */
#define AUD_SND_MAX_VOL_LEVEL 7

aud_snd_context_struct *aud_snd_cntx_p = &med_context.snd_context;
static STFSAL aud_snd_file;

/* 
 * Global Function
 */

/*====  BEGIN FUNCTION DEFINITIONS ========*/


/*****************************************************************************
 * FUNCTION
 *  aud_snd_set_handle
 * DESCRIPTION
 *  This function is to store the file handle in the global context
 * PARAMETERS
 *  handle      [IN]        the file handle
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_snd_set_handle(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->snd_handle = handle;
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_get_handle
 * DESCRIPTION
 *  This function is to get the file handle from the global context
 * PARAMETERS
 *  void
 * RETURNS
 *  Media_Handle* : The file handle
 *****************************************************************************/
static Media_Handle *aud_snd_get_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_snd_cntx_p->snd_handle == 0)
    {
        return NULL;
    }
    else
    {
        return (Media_Handle*) aud_snd_cntx_p->snd_handle;
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_startup
 * DESCRIPTION
 *  This function is to initialize the background sound effect interface in media task
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_snd_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->state = AUD_MEDIA_IDLE;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_check_byte_stream_format_req_hdlr
 * DESCRIPTION
 *  This function is to check if the data format fit the background sound format
 * PARAMETERS
 *  ilm_ptr     [?]     The message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_check_byte_stream_format_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Format format;
    STFSAL snd_file;
    FSAL_Status eFSALRet;
    media_snd_check_byte_stream_format_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->src_mod = ilm_ptr->src_mod_id;
    msg_p = (media_snd_check_byte_stream_format_req_struct*) ilm_ptr->local_para_ptr;

#ifdef __MTK_TARGET__
    FSAL_Direct_SetRamFileSize(&snd_file, msg_p->size);
    eFSALRet = FSAL_Open(&snd_file, (void*)msg_p->data_p, FSAL_ROMFILE);

    if (eFSALRet != FSAL_OK)
    {
        aud_snd_set_result(MED_RES_OPEN_FILE_FAIL);
        EFFECT_SET_EVENT(SND_EVT_CHECK);
        return;
    }

    if (SND_GetFormat(&snd_file, &format) == MEDIA_SUCCESS)
    {
        aud_snd_set_result(MED_RES_OK);
    }
    else
    {
        aud_snd_set_result(MED_RES_BAD_FORMAT);
    }

    FSAL_Close(&snd_file);

#else /* #ifdef __MTK_TARGET__ */
    aud_snd_set_result(MED_RES_OK);
#endif /* #ifdef __MTK_TARGET__ */

    EFFECT_SET_EVENT(SND_EVT_CHECK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_check_file_format_req_hdlr
 * DESCRIPTION
 *  This function is to check if the external file format fit the background sound format
 * PARAMETERS
 *  ilm_ptr     [?]     The message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_check_file_format_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Format format;
    STFSAL snd_file;
    FSAL_Status eFSALRet;
    media_snd_check_file_format_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->src_mod = ilm_ptr->src_mod_id;
    msg_p = (media_snd_check_file_format_req_struct*) ilm_ptr->local_para_ptr;

#ifdef __MTK_TARGET__
    eFSALRet = FSAL_Open(&snd_file, (void*)msg_p->file_name_p, FSAL_READ);

    if (eFSALRet != FSAL_OK)
    {
        aud_snd_set_result(MED_RES_OPEN_FILE_FAIL);
        EFFECT_SET_EVENT(SND_EVT_CHECK);
        return;
    }

    if (SND_GetFormat(&snd_file, &format) == MEDIA_SUCCESS)
    {
        aud_snd_set_result(MED_RES_OK);
    }
    else
    {
        aud_snd_set_result(MED_RES_BAD_FORMAT);
    }

    FSAL_Close(&snd_file);
    
#else /* #ifdef __MTK_TARGET__ */
    aud_snd_set_result(MED_RES_OK);
#endif /* #ifdef __MTK_TARGET__ */

    EFFECT_SET_EVENT(SND_EVT_CHECK);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_play_byte_stream_req_hdlr
 * DESCRIPTION
 *  This function is to play a sound effect data stream
 * PARAMETERS
 *  ilm_ptr     [?]     message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_play_byte_stream_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    media_snd_play_byte_stream_req_struct *msg_p;
    Media_Handle *snd_handle = NULL;
    Snd_Param *snd_param;
    Media_Status snd_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->src_mod = ilm_ptr->src_mod_id;
    msg_p = (media_snd_play_byte_stream_req_struct*) ilm_ptr->local_para_ptr;

    AUD_VALUE_TRACE(aud_snd_cntx_p->state, -1, aud_context_p->state);

    /*
     *  If the background sound still playing, or
     *  forground sound is recording, then return busy
     */
    if ((aud_snd_cntx_p->state != AUD_MEDIA_IDLE)) //||
        //(aud_context_p->state == AUD_MEDIA_RECORD) || (aud_context_p->state == AUD_MEDIA_RECORD_PAUSED))
    {
        aud_snd_set_result(MED_RES_BUSY);
        EFFECT_SET_EVENT(SND_EVT_PLAY);
        return;
    }

#ifdef __MTK_TARGET__
    /* Load resource string */
    FSAL_Direct_SetRamFileSize(&aud_snd_file, msg_p->size);
    eFSALRet = FSAL_Open(&aud_snd_file, (void*)msg_p->data_p, FSAL_ROMFILE);

    if (eFSALRet != FSAL_OK)
    {
        aud_snd_set_result(MED_RES_OPEN_FILE_FAIL);
        EFFECT_SET_EVENT(SND_EVT_PLAY);
        return;
    }

    /* Open File and get background sound handle */
    snd_handle = SND_Open(aud_snd_play_event_handler, &snd_param);
    snd_param->pstFSAL = &aud_snd_file;
    snd_param->repeats = msg_p->repeats;
    // snd_param->format = msg_p->media_type;   /*Will check in SND_Play()*/

    /* Set output device for background sound, it will not affect forground sound output path, except in call */
    if (!aud_context_p->speech_on)
    {
        aud_context_p->melody_output_device = msg_p->output_path;
        aud_get_active_device_path_by_mode(msg_p->output_path, aud_snd_set_output_device);
    }

    /* Range 0 ~ AUD_SND_MAX_VOL_LEVEL */
    if (msg_p->volume > AUD_SND_MAX_VOL_LEVEL)
    {
        msg_p->volume = AUD_SND_MAX_VOL_LEVEL;
    }

    /*
     * Set uplink and downlink with the same volume
     * Always turn on speech channel. 
     * It can mute by itself in call menu. No need to modify in background sound interface.
     */
    SND_ConfigULMixer(snd_handle, KAL_TRUE, msg_p->volume);
    SND_ConfigDLMixer(snd_handle, KAL_TRUE, msg_p->volume);

    /* Begin to play background sound */
    if ((snd_status = SND_Play(snd_handle)) == MEDIA_SUCCESS)
    {
        aud_snd_cntx_p->state = AUD_MEDIA_PLAY;
        aud_snd_set_result(MED_RES_OK);
        aud_snd_set_handle((kal_uint32) snd_handle);
    }
    else
    {
        aud_snd_set_result((kal_int32) aud_get_res(snd_status));
        SND_Close(snd_handle);
        FSAL_Close(&aud_snd_file);
        aud_snd_set_handle(NULL);
    }

#else /* #ifdef __MTK_TARGET__ */
    aud_snd_set_result(MED_RES_OK);
#endif /* #ifdef __MTK_TARGET__ */

    EFFECT_SET_EVENT(SND_EVT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_play_file_req_hdlr
 * DESCRIPTION
 *  This function is to play a external file sound effect
 * PARAMETERS
 *  ilm_ptr     [?]     message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_play_file_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status eFSALRet;
    media_snd_play_file_req_struct *msg_p;
    Media_Handle *snd_handle = NULL;
    Snd_Param *snd_param;
    Media_Status snd_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->src_mod = ilm_ptr->src_mod_id;
    msg_p = (media_snd_play_file_req_struct*) ilm_ptr->local_para_ptr;

    AUD_VALUE_TRACE(aud_snd_cntx_p->state, -1, aud_context_p->state);

    /*
     *  If the background sound still playing, or
     *  forground sound is recording, then return busy
     */
    if ((aud_snd_cntx_p->state != AUD_MEDIA_IDLE)) // ||
        //(aud_context_p->state == AUD_MEDIA_RECORD) || (aud_context_p->state == AUD_MEDIA_RECORD_PAUSED))
    {
        aud_snd_set_result(MED_RES_BUSY);
        EFFECT_SET_EVENT(SND_EVT_PLAY);
        return;
    }

#ifdef __MTK_TARGET__
    /* Load file */
    eFSALRet = FSAL_Open(&aud_snd_file, (void*)msg_p->file_name_p, FSAL_READ | FSAL_NONBLOCKING);

    if (eFSALRet != FSAL_OK)
    {
        aud_snd_set_result(MED_RES_OPEN_FILE_FAIL);
        EFFECT_SET_EVENT(SND_EVT_PLAY);
        return;
    }

    /* Open File and get background sound handle */
    snd_handle = SND_Open(aud_snd_play_event_handler, &snd_param);
    snd_param->pstFSAL = &aud_snd_file;
    snd_param->repeats = msg_p->repeats;
    // snd_param->format = msg_p->media_type;   /*Will check in SND_Play()*/

    /* Set output device for background sound, it will not affect forground sound output path, except in call */
    if (!aud_context_p->speech_on)
    {
        aud_context_p->melody_output_device = msg_p->output_path;
        aud_get_active_device_path_by_mode(msg_p->output_path, aud_snd_set_output_device);

    }

    /* Range 0 ~ AUD_SND_MAX_VOL_LEVEL */
    if (msg_p->volume > AUD_SND_MAX_VOL_LEVEL)
    {
        msg_p->volume = AUD_SND_MAX_VOL_LEVEL;
    }

    /*
     * Set uplink and downlink with the same volume
     * Always turn on speech channel. 
     * It can mute by itself in call menu. No need to modify in background sound interface.
     */
    SND_ConfigULMixer(snd_handle, KAL_TRUE, msg_p->volume);
    SND_ConfigDLMixer(snd_handle, KAL_TRUE, msg_p->volume);

    /* Begin to play background sound */
    if ((snd_status = SND_Play(snd_handle)) == MEDIA_SUCCESS)
    {
        aud_snd_cntx_p->state = AUD_MEDIA_PLAY;
        aud_snd_set_result(MED_RES_OK);
        aud_snd_set_handle((kal_uint32) snd_handle);
    }
    else
    {
        aud_snd_set_result((kal_int32) aud_get_res(snd_status));
        SND_Close(snd_handle);
        FSAL_Close(&aud_snd_file);
        aud_snd_set_handle(NULL);
    }

#else /* #ifdef __MTK_TARGET__ */
    aud_snd_set_result(MED_RES_OK);
#endif /* #ifdef __MTK_TARGET__ */

    EFFECT_SET_EVENT(SND_EVT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_play_event_handler
 * DESCRIPTION
 *  The function is the callback function when the play stops
 * PARAMETERS
 *  handle      [?]         file handle
 *  event       [IN]        result
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_play_event_handler(Media_Handle *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_play_event_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_snd_play_event_ind_struct*) construct_local_para(sizeof(media_snd_play_event_ind_struct), TD_CTRL);

    ind_p->src_id = aud_snd_cntx_p->src_mod;
    ind_p->event = event;
    ind_p->snd_handle = (kal_uint32) handle;

    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_SND_PLAY_EVENT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_process_event
 * DESCRIPTION
 *  The function is the callback function when the play stops
 * PARAMETERS
 *  ilm_ptr     [?]     
 *  handle : file handle(?)
 *  event : result(?)
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_process_event(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_play_event_ind_struct *ind_p = (media_snd_play_event_ind_struct*) ilm_ptr->local_para_ptr;
    Media_Handle *snd_handle;
    Media_Handle *msg_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    snd_handle = aud_snd_get_handle();
    msg_handle = (Media_Handle*) ind_p->snd_handle;

    AUD_VALUE_TRACE(aud_snd_cntx_p->state, snd_handle, msg_handle);

    if (aud_snd_cntx_p->state != AUD_MEDIA_PLAY)
    {
        return;
    }

    switch (ind_p->event)
    {
        case MEDIA_END:

            if ((snd_handle != NULL) && (snd_handle == msg_handle))
            {
            #ifdef __MTK_TARGET__
                SND_Stop(snd_handle);
                SND_Close(snd_handle);
            #endif /* #ifdef __MTK_TARGET__ */
                FSAL_Close(&aud_snd_file);

                aud_snd_set_handle(NULL);
                aud_snd_cntx_p->state = AUD_MEDIA_IDLE;

                aud_send_snd_play_finish_ind(aud_snd_cntx_p->src_mod, MED_RES_END_OF_FILE);
            }
            break;

        case MEDIA_REPEATED:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop background sound playing.
 * PARAMETERS
 *  ilm_ptr     [?]     message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Handle *snd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->src_mod = ilm_ptr->src_mod_id;

    AUD_VALUE_TRACE(aud_snd_cntx_p->state, -1, aud_context_p->state);

#ifdef __MTK_TARGET__
    if (aud_snd_cntx_p->state != AUD_MEDIA_PLAY)
    {
        aud_snd_set_handle(NULL);
        aud_snd_set_result(MED_RES_OK);
        EFFECT_SET_EVENT(SND_EVT_STOP);
        return;
    }

    snd_handle = aud_snd_get_handle();

    if (snd_handle != NULL)
    {
        SND_Stop(snd_handle);
        SND_Close(snd_handle);
        FSAL_Close(&aud_snd_file);

        aud_snd_set_handle(NULL);
        aud_snd_set_result(MED_RES_OK);
    }
    else
    {
        aud_snd_set_result(MED_RES_FAIL);
    }
    
#else /* #ifdef __MTK_TARGET__ */
    aud_snd_set_result(MED_RES_OK);
#endif /* #ifdef __MTK_TARGET__ */

    aud_snd_cntx_p->state = AUD_MEDIA_IDLE;
    EFFECT_SET_EVENT(SND_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_set_volume_req_hdlr
 * DESCRIPTION
 *  This function is to set the background sound volume
 * PARAMETERS
 *  ilm_ptr     [?]     message pointer
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_set_volume_req_struct *msg_p;
    Media_Handle *snd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_snd_cntx_p->src_mod = ilm_ptr->src_mod_id;
    msg_p = (media_snd_set_volume_req_struct*) ilm_ptr->local_para_ptr;

#ifdef __MTK_TARGET__
    if (aud_snd_cntx_p->state != AUD_MEDIA_PLAY)
    {
        aud_snd_set_result(MED_RES_FAIL);
        EFFECT_SET_EVENT(SND_EVT_SET);
        return;
    }

    snd_handle = aud_snd_get_handle();

    if (snd_handle != NULL)
    {
        /* Range 0 ~ AUD_SND_MAX_VOL_LEVEL */
        if (msg_p->volume > AUD_SND_MAX_VOL_LEVEL)
        {
            msg_p->volume = AUD_SND_MAX_VOL_LEVEL;
        }

        SND_ConfigULMixer(snd_handle, KAL_TRUE, msg_p->volume);
        SND_ConfigDLMixer(snd_handle, KAL_TRUE, msg_p->volume);
        aud_snd_set_result(MED_RES_OK);
    }
    else
    {
        aud_snd_set_result(MED_RES_FAIL);
    }

#else
    aud_snd_set_result(MED_RES_OK);
#endif

    EFFECT_SET_EVENT(SND_EVT_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_snd_set_output_device
 * DESCRIPTION
 *  This function is to set the output path
 * PARAMETERS
 *  device      [IN]        
 *  ilm_ptr : message pointer(?)
 * RETURNS
 *  void
 *****************************************************************************/
void aud_snd_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_BGSND, device, -1);
#ifdef __MTK_TARGET__
    SND_SetOutputDevice(device);
#endif    

}

#endif /* __MED_SND_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

