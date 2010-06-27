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
 *   aud_tts.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to provide general TTS interface
 *
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
#include "app_ltlcom.h"         /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"         /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
//#include "device.h"
//#include "custom_equipment.h"
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

#if defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
#include "vid_main.h"
#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)*/ 

#ifdef __MED_GENERAL_TTS__

#define AUD_TTS_MAX_ATTR_NUM    9

typedef struct
{
    kal_uint32 attr_id;
    kal_uint32 attr_value;
    kal_bool is_set;
}tts_value_struct;

/* 
 * Local Variable
 */
static TTS_Handle *g_aud_tts_handle;
static kal_uint8 *g_aud_tts_buff_p;
static tts_value_struct g_aud_tts_attr[AUD_TTS_MAX_ATTR_NUM];


/* 
 * Local Function
 */


/* 
 * Global Variable
 */

/* 
 * Global Function
 */
 

/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Create event group */
    aud_context_p->tts_event = kal_create_event_group("tts_events");

    /* Assign attribute id */
    g_aud_tts_attr[0].attr_id = TTS_ATTR_INPUT_CODEPAGE;
    g_aud_tts_attr[1].attr_id = TTS_ATTR_TEXT_SCOPE;
    g_aud_tts_attr[2].attr_id = TTS_ATTR_INPUT_MODE;
    g_aud_tts_attr[3].attr_id = TTS_ATTR_PROGRESS_CALLBACK;
    g_aud_tts_attr[4].attr_id = TTS_ATTR_READ_DIGIT;
    g_aud_tts_attr[5].attr_id = TTS_ATTR_CHINESE_NUMBER_1;
    g_aud_tts_attr[6].attr_id = TTS_ATTR_PHONEME_WATCH;
    g_aud_tts_attr[7].attr_id = TTS_ATTR_WATCH_CALLBACK;
    g_aud_tts_attr[8].attr_id = TTS_ATTR_SPEAK_STYLE;

    /* Clear set attribute flag */
    for(i = 0 ; i < AUD_TTS_MAX_ATTR_NUM ; i++)
    {
        g_aud_tts_attr[i].is_set = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_set_attr_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_int32 result = MED_RES_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_tts_set_attr_req_struct *msg_p = (media_aud_tts_set_attr_req_struct*) ilm_ptr->local_para_ptr;

    for(i = 0 ; i < AUD_TTS_MAX_ATTR_NUM ; i++)
    {
        if(g_aud_tts_attr[i].attr_id == msg_p->attr_id)
        {
            g_aud_tts_attr[i].attr_value = msg_p->attr_value;
            g_aud_tts_attr[i].is_set = KAL_TRUE;
            result = MED_RES_OK;
            break;
        }
    }

    aud_set_result(result);
    TTS_SET_EVENT(TTS_EVT_SET_ATTR);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_util_close_and_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_aud_tts_handle->Close(g_aud_tts_handle);
    med_free_ext_mem((void**)&g_aud_tts_buff_p);
    g_aud_tts_handle = NULL;
    g_aud_tts_buff_p = NULL;

    /* Clear set attribute flag */
    for(i = 0 ; i < AUD_TTS_MAX_ATTR_NUM ; i++)
    {
        g_aud_tts_attr[i].is_set = KAL_FALSE;
    }

    aud_context_p->last_seq_no++;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_play_event_ind(TTS_Handle *hdl, TTS_Event event, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_tts_play_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p =
        (media_aud_tts_play_event_ind_struct*) construct_local_para(
                                                    sizeof(media_aud_tts_play_event_ind_struct),
                                                    TD_CTRL);

    ind_p->handle = (kal_uint32)hdl;
    ind_p->event = event;
    ind_p->seq_no = aud_context_p->last_seq_no;

    if(event == TTS_WATCH)
    {
        ind_p->data = (void *)get_ctrl_buffer(sizeof(TTS_PROCESS_DATA));
        kal_mem_cpy(ind_p->data, data, sizeof(TTS_PROCESS_DATA));
    }
    else if(event == TTS_PROGRESS)
    {
        ind_p->data = (void *)get_ctrl_buffer(sizeof(TTSPROGRESS));
        kal_mem_cpy(ind_p->data, data, sizeof(TTS_PROCESS_DATA));        
    }
    else
    {
        ind_p->data = NULL;
    }

    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_AUD_TTS_PLAY_EVENT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_process_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_tts_play_event_ind_struct *ind_p = (media_aud_tts_play_event_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->last_seq_no != ind_p->seq_no ||
        (aud_context_p->state != AUD_MEDIA_PLAY && aud_context_p->state != AUD_MEDIA_PLAY_PAUSED))
    {
        AUD_VALUE_TRACE(ind_p->seq_no, aud_context_p->last_seq_no, aud_context_p->state);

        /* Free control buffer for data update */
        if((ind_p->event == TTS_WATCH) || (ind_p->event == TTS_PROGRESS))
        {
            free_ctrl_buffer(ind_p->data);
        }

        return;
    }

    switch (ind_p->event)
    {
        case TTS_END:
        case TTS_ERROR:
            ASSERT(g_aud_tts_handle != NULL);
        
            g_aud_tts_handle->Stop(g_aud_tts_handle);
            aud_tts_util_close_and_free();
            AUD_ENTER_STATE(AUD_MEDIA_IDLE);

            aud_context_p->last_seq_no++;

            if(ind_p->event == MEDIA_END)
            {
                aud_send_media_play_finish_ind(MED_RES_END_OF_FILE);
            }
            else
            {
                aud_send_audio_play_finish_ind(MED_RES_ERROR);
            }
            break;

       case TTS_WATCH:
       case TTS_PROGRESS:
            aud_send_tts_update_info_ind(ind_p->data);
            break;
        case TTS_DATA_REQUEST:
        default:
            break;
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_tts_play_req_struct *msg_p = (media_aud_tts_play_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 buff_size;
    kal_uint16 i;
    Media_Status result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: ADD Trace

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    if (aud_context_p->speech_on
    #if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
        || !vid_is_audio_channel_available()
    #endif 
        )
    {
        aud_set_result(MED_RES_BUSY);
        goto play_tts_done;
    }

    /* If keytone is playing, stop it */
    aud_keytone_stop();

    /* If tone is playing, stop it */
    if (aud_context_p->tone_playing)
    {
        aud_tone_stop();
    }

#ifdef __MED_MMA_MOD__
    /* Close all mma tasks */
    aud_mma_close_all();
#endif /* __MED_MMA_MOD__ */ 

    /* Recording, do not play */
    if ((aud_context_p->state == AUD_MEDIA_RECORD ||
         aud_context_p->state == AUD_MEDIA_RECORD_PAUSED ||
         aud_context_p->state == AUD_VM_RECORD ||
         aud_context_p->state == AUD_VM_RECORD_PAUSED))
    {
        aud_set_result((kal_int32) MED_RES_BUSY);
        goto play_tts_done;
    }

    /* Stop other playing process */
    aud_stop_unfinished_process();

    /* Set global variables */
    aud_context_p->play_mode = AUD_MEDIA_PLAY_MODE_NONE;
    aud_context_p->source_type = AUD_TTS;
    aud_context_p->src_id = 0; /* Not used here */
    aud_context_p->identifier = msg_p->identifier;

    /* Set volume and path */
    aud_context_p->melody_output_device = msg_p->output_path;
    aud_get_active_device_path_by_mode(msg_p->output_path,aud_melody_set_output_device);
    SET_CURRENT_VOLUME_LEVEL(AUD_VOLUME_MEDIA, msg_p->volume);
    aud_set_active_ring_tone_volume();

    /* Open TTS handle*/
    if((g_aud_tts_handle = TTS_Open(aud_tts_play_event_ind,
                                    (TTS_LANG)msg_p->lang,
                                    (TTS_TYPE)msg_p->app_type,
                                    (TTS_GENDER)msg_p->gander)) == NULL)
    {
        aud_set_result((kal_int32) MED_RES_FAIL);
        goto play_tts_done;
    }

    /* Set TTS working buffer */
    buff_size = g_aud_tts_handle->GetBufSize(g_aud_tts_handle);
    ASSERT(buff_size > 0);

    if((g_aud_tts_buff_p = (kal_uint8*)med_alloc_ext_mem(buff_size)) == NULL)
    {
        g_aud_tts_handle->Close(g_aud_tts_handle);
        g_aud_tts_handle = NULL;
        aud_set_result((kal_int32) MED_RES_MEM_INSUFFICIENT);
        goto play_tts_done;
    }
    g_aud_tts_handle->SetBuffer(g_aud_tts_handle, g_aud_tts_buff_p, buff_size);

    /* Set parameters */
    g_aud_tts_handle->SetPitch(g_aud_tts_handle, msg_p->pitch);
    //g_aud_tts_handle->SetVolume(g_aud_tts_handle, msg_p->volume); /* digital level, not used */
    g_aud_tts_handle->SetSpeed(g_aud_tts_handle, msg_p->speed);

    /* Set attributes */
    for(i = 0 ; i < AUD_TTS_MAX_ATTR_NUM ; i++)
    {
        if(g_aud_tts_attr[i].is_set)
        {
            g_aud_tts_handle->SetAttr(g_aud_tts_handle, g_aud_tts_attr[i].attr_id, g_aud_tts_attr[i].attr_value);
        }
    }

    /* Start to play */
    result = g_aud_tts_handle->Play(g_aud_tts_handle, (kal_wchar*)msg_p->tts_string, (TTS_STR_TYPE)msg_p->str_type);
    if(result == MEDIA_SUCCESS)
    {
        AUD_ENTER_STATE(AUD_MEDIA_PLAY);    
    }
    else
    {
        aud_tts_util_close_and_free();
    }

    aud_set_result((kal_int32) aud_get_res((kal_uint8)result));

play_tts_done:
    TTS_SET_EVENT(TTS_EVT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VALUE_TRACE(aud_context_p->state, -1, __LINE__);

    if (aud_context_p->state == AUD_MEDIA_PLAY ||
        aud_context_p->state == AUD_MEDIA_PLAY_PAUSED)
    {
        ASSERT(g_aud_tts_handle != NULL);

        g_aud_tts_handle->Stop(g_aud_tts_handle);
        aud_tts_util_close_and_free();
        AUD_ENTER_STATE(AUD_MEDIA_IDLE);

        aud_context_p->last_seq_no++;
    }
    
    aud_set_result((kal_int32) MED_RES_OK);
    TTS_SET_EVENT(TTS_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = g_aud_tts_handle->Pause(g_aud_tts_handle);
    AUD_VALUE_TRACE(result, aud_context_p->state, __LINE__);

    if (result == MEDIA_SUCCESS)
    {
        AUD_ENTER_STATE(AUD_MEDIA_PLAY_PAUSED);
    }
    else
    {
        g_aud_tts_handle->Stop(g_aud_tts_handle);
        aud_tts_util_close_and_free();
        AUD_ENTER_STATE(AUD_MEDIA_IDLE);
    }

    aud_set_result((kal_int32) aud_get_res((kal_uint8)result));
    TTS_SET_EVENT(TTS_EVT_PAUSE);
}


/*****************************************************************************
 * FUNCTION
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_tts_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = g_aud_tts_handle->Resume(g_aud_tts_handle);
    AUD_VALUE_TRACE(result, aud_context_p->state, __LINE__);

    if (result == MEDIA_SUCCESS)
    {
        AUD_ENTER_STATE(AUD_MEDIA_PLAY_PAUSED);
    }
    else
    {
        g_aud_tts_handle->Stop(g_aud_tts_handle);
        aud_tts_util_close_and_free();
        AUD_ENTER_STATE(AUD_MEDIA_IDLE);
    }

    aud_set_result((kal_int32) aud_get_res((kal_uint8)result));
    TTS_SET_EVENT(TTS_EVT_RESUME);
}

#endif /* __MED_GENERAL_TTS__ */
#endif /* MED_NOT_PRESENT */

