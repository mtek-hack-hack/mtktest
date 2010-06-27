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
 *   aud_mma.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to handle all messages for Multiple Access Interface. 
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
#include "resource_audio.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "fat_fs.h"     /* for FAT FS */
#include "drm_gprot.h"  /* DRM_REPLACE */
#include "FSAL.h"
#include "MP4_Parser.h"

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

#if defined(__DRM_V02__)
#include "Drm_gprot.h"
#endif

#ifdef __MED_MMA_MOD__

/*==== DEFINES ===========*/
typedef MHdl *(*mma_single_open_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);
typedef Media_Status(*mma_singe_get_duration_ptr) (STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param);
typedef Media_Status(*mma_singe_get_meta_ptr) (kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param );

typedef struct
{
    STFSAL     fsal_handle;
    kal_int16  repeat;
    kal_int16  type;
    kal_bool   is_progressive_dl;  /* Play a progressive download file */
    kal_bool   is_dl_finish;       /* Is progressive download finish */
    kal_uint32 underflow_offset;   /* To store the offset when progressive dl underflow */
    kal_uint32 underflow_time;     /* To store the play time when progressive dl underflow */    
    kal_uint8  media_end_play_count;  /* To prevent data not played after download finish */
}
aud_mma_single_player_struct;

/*==== VARIABLES ===========*/
static aud_mma_single_player_struct aud_mma_single_player;
static aud_mma_single_player_struct *mma_single_p = &aud_mma_single_player;

/* Use Static Memory For FSAL Buffer to avoid External memory fragment */
#if defined(AUD_PROC_USE_EXT_MEM)
extern kal_uint8 med_aud_fasl_buf[];
#endif 

/*==== FUNCTIONS ===========*/
#ifdef __J2ME__
extern kal_uint8 jam_get_vib_on(void);
#endif 
static kal_bool aud_mma_check_valid_handle_and_used(kal_uint8 media_type, kal_int32 handle);
static kal_int16 aud_mma_is_single_player(kal_int32 handle);


#define MMA_BEGIN
/*****************************************************************************
 * FUNCTION
 *  aud_mma_startup
 * DESCRIPTION
 *  This function is to start mma module.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_mma_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(aud_context_p->player, 0, sizeof(aud_player_struct) * MMA_NO_OF_PLAYER);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_single_fsal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_single_fsal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FSAL_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_single_p->fsal_handle.bBuffering && mma_single_p->fsal_handle.pbBuf != NULL)
    {
    #if !defined(AUD_PROC_USE_EXT_MEM)
        free_ctrl_buffer((void*)mma_single_p->fsal_handle.pbBuf);
    #endif 
    }

    result = FSAL_Close(&mma_single_p->fsal_handle);
    AUD_VALUE_TRACE(result, -1, -1);
    memset(&mma_single_p->fsal_handle, 0, sizeof(STFSAL));
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_all_single_player
 * DESCRIPTION
 *  This function is to close all mma single player.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_all_single_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    if (player_p->used)
    {
        ASSERT(player_p->handle != NULL);

        if (mma_single_p->type == MMA_TYPE_MIDI)
        {
            JSmf_Stop((Media_Handle*) player_p->handle);
            JSmf_Close((Media_Handle*) player_p->handle);

            aud_free_melody_file_buffer();
        }
        else if (mma_single_p->type == MMA_TYPE_IMY)
        {
            JImy_Stop((Media_Handle*) player_p->handle);
            aud_melody_stop_driver();
            JImy_Close((Media_Handle*) player_p->handle);

            aud_free_melody_file_buffer();
        }
        else
        {
            mhdl_handle = (MHdl*) player_p->handle;

            mhdl_handle->Stop(mhdl_handle);
            mhdl_handle->Close(mhdl_handle);

            aud_mma_close_single_fsal();
        }

        player_p->used = KAL_FALSE;
        player_p->handle = NULL;
        mma_single_p->repeat = 0;
        mma_single_p->type = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_all_multi_player
 * DESCRIPTION
 *  This function is to close all multi-players.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_all_multi_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    aud_player_struct *player_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* close IMY player */
    player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
    {
        if (player_p->used)
        {
            JImy_Stop((Media_Handle*) player_p->handle);
            aud_melody_stop_driver();
            JImy_Close((Media_Handle*) player_p->handle);
            player_p->used = KAL_FALSE;
            player_p->handle = NULL;
        }
    }
    /* close SMF player */
    for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
    {
        player_p = &(aud_context_p->player[i]);
        if (player_p->used)
        {
            if(player_p->is_device)
            {
                JMidi_CloseDevice((Media_Handle*) player_p->handle);
            }
            else
            {
                JSmf_Stop((Media_Handle*) player_p->handle);
                JSmf_Close((Media_Handle*) player_p->handle);
            }
            
            player_p->used = KAL_FALSE;
            player_p->handle = NULL;
        }
    }
#ifdef JTONE_SUPPORT
    /* close TONE player */
    for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
    {
        player_p = &(aud_context_p->player[i]);
        if (player_p->used)
        {
            JTone_Stop((Media_Handle*) player_p->handle);
            JTone_Close((Media_Handle*) player_p->handle);
            player_p->used = KAL_FALSE;
            player_p->handle = NULL;
        }
    }
#endif /* JTONE_SUPPORT */
    /* close WAV player */
    for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
    {
        player_p = &(aud_context_p->player[i]);
        if (player_p->used)
        {
            JWav_Stop((Media_Handle*) player_p->handle);
            JWav_Close((Media_Handle*) player_p->handle);
            med_free_ext_mem((void **)&(player_p->buf_p));
            player_p->used = KAL_FALSE;
            player_p->handle = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_all
 * DESCRIPTION
 *  This function is to close all mma tasks.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_mma_close_all_multi_player();
    aud_mma_close_all_single_player();
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_jtype_event_callback
 * DESCRIPTION
 *  This function is to handle play event callback.
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_jtype_event_callback(Media_Handle *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_play_event_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case MEDIA_LED_ON:
            aud_melody_imy_led_hdlr(KAL_TRUE);
            return;
        case MEDIA_LED_OFF:
            aud_melody_imy_led_hdlr(KAL_FALSE);
            return;
        case MEDIA_VIBRATOR_ON:
    #ifdef __J2ME__
            if (jam_get_vib_on())
    #endif 
                aud_melody_imy_vibrator_hdlr(KAL_TRUE);
            return;
        case MEDIA_VIBRATOR_OFF:
    #ifdef __J2ME__
            if (jam_get_vib_on())
    #endif 
                aud_melody_imy_vibrator_hdlr(KAL_FALSE);
            return;
        case MEDIA_BACKLIGHT_ON:
            aud_melody_imy_backlight_hdlr(KAL_TRUE);
            return;
        case MEDIA_BACKLIGHT_OFF:
            aud_melody_imy_backlight_hdlr(KAL_FALSE);
            return;
        case MEDIA_REPEATED:
            aud_melody_stop_driver();
            return;
        case MEDIA_TERMINATED:
            return;
        case MEDIA_ERROR:
        case MEDIA_END:
            aud_melody_stop_driver();
            break;
        default:
            break;
    }

    ind_p = (media_mma_play_event_ind_struct*) construct_local_para(sizeof(media_mma_play_event_ind_struct), TD_CTRL);

    ind_p->handle = (kal_int32) handle;
    ind_p->event = (kal_uint8) event;

    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_MMA_PLAY_EVENT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_play_event_ind_hdlr
 * DESCRIPTION
 *  This function is to handle play event indication.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_play_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_int32 handle;
    media_mma_play_event_ind_struct *ind_p;
    med_handler handler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_mma_play_event_ind_struct*) ilm_ptr->local_para_ptr;
    handle = ind_p->handle;

    switch (ind_p->event)
    {
        case MEDIA_END:
        case MEDIA_ERROR:
        case MEDIA_TERMINATED:
        case MEDIA_DATA_REQUEST:
        case MEDIA_DATA_NOTIFICATION:
            if (handle != NULL)
            {
                aud_player_struct *player_p;

                for (i = 0; i < MMA_NO_OF_PLAYER; i++)
                {
                    player_p = &(aud_context_p->player[i]);
                    if (player_p->used && player_p->handle == handle)
                    {
                    	player_p->state = AUD_MEDIA_IDLE;
                        handler = (med_handler) player_p->handler_func;
                        if (handler)
                        {
                            if(ind_p->event == MEDIA_END)
                            {
                                handler(ind_p->handle, MED_RES_END_OF_FILE);
                            }
                            else
                            {
                                handler(ind_p->handle, MED_RES_ERROR);
                            }
                        }
                        break;
                    }
                }
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_fsal_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_fsal_event_callback(MHdl *handle, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_process_event_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p =
        (media_mma_process_event_ind_struct*) construct_local_para(
                                                sizeof(media_mma_process_event_ind_struct),
                                                TD_CTRL);

    ind_p->handle = (kal_int32) handle;
    ind_p->event = (kal_uint8) event;

    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_MMA_PROCESS_EVENT_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_fsal_process_event_ind_hdlr
 * DESCRIPTION
 *  This function is ....
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_fsal_process_event_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_process_event_ind_struct *ind_p = (media_mma_process_event_ind_struct*) ilm_ptr->local_para_ptr;
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    Media_Event evt_result;
    Media_Status media_result;
    med_handler handler;
    kal_uint32 fsal_file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_MMA_FSAL_PROCESS_EVENT_IND_HDLR, mma_single_p->type);

    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    /* Player not in use */
    if (!player_p->used)
    {
        return;
    }

    switch (mma_single_p->type)
    {
        case MMA_TYPE_WAV:
    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
    #endif 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
        case MMA_TYPE_M4A:
    #endif 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
    #endif
            break;

        default:
            ASSERT(0);
            break;
    }

    mhdl_handle = (MHdl*) ind_p->handle;
    evt_result = mhdl_handle->Process(mhdl_handle, (Media_Event) ind_p->event);

    AUD_VALUE_TRACE(player_p->state, evt_result, -1);

    if (evt_result != MEDIA_NONE && evt_result != MEDIA_UPDATE_DUR)
    {
        AUD_VALUE_TRACE(-1, mma_single_p->is_progressive_dl, mma_single_p->is_dl_finish);

        /* Streaming */
        if(mma_single_p->is_progressive_dl)
        {
            /* Write data finish, but still have a short period of data not played*/        
            if(mma_single_p->is_dl_finish)
            {
                mma_single_p->underflow_offset = mhdl_handle->GetFileOffset(mhdl_handle);
                mma_single_p->underflow_time = mhdl_handle->GetCurrentTime(mhdl_handle);                
                FSAL_Direct_GetFileSize(&mma_single_p->fsal_handle, &fsal_file_size);

                AUD_VALUE_TRACE(mma_single_p->underflow_offset, fsal_file_size, -1);
                
                /* Play the last part of file */
                if((mma_single_p->underflow_offset < fsal_file_size) &&
                   (mma_single_p->media_end_play_count == 0))
                {
                    mhdl_handle->SetStoreFlag(mhdl_handle, KAL_TRUE);
                    mhdl_handle->SetStartTime(mhdl_handle, mma_single_p->underflow_time);
                    mhdl_handle->SetFileOffset(mhdl_handle, mma_single_p->underflow_offset);

                    media_result = mhdl_handle->Play(mhdl_handle);

                    AUD_VALUE_TRACE(media_result, mma_single_p->media_end_play_count, -1);

                    mma_single_p->media_end_play_count++;
                    
                    if(media_result == MEDIA_SUCCESS)
                    {
                        player_p->state = AUD_MEDIA_PLAY;
                        return;
                    }
                }
            }
            /* Streaming, underflow */
            else
            {
                /* Keep current file position and Keep file offset for fast restore */
                mma_single_p->underflow_offset = mhdl_handle->GetFileOffset(mhdl_handle);
                mma_single_p->underflow_time = mhdl_handle->GetCurrentTime(mhdl_handle);                
                handler = (med_handler) player_p->handler_func;

                /* Progressive download not finish, but already reach stop time */
                if(evt_result == MEDIA_STOP_TIME_UP)
                {
                    player_p->state = AUD_MEDIA_IDLE;
                    if (handler)
                    {
                        handler(ind_p->handle, MED_RES_END_OF_FILE);
                    }
                }
                else
                {
                    player_p->state = AUD_MEDIA_UNDERFLOW;                        
                    if (handler)
                    {
                        handler(ind_p->handle, MED_RES_BUFFER_INSUFFICIENT);
                    }
                }

                return;
            }
        }

        /* Play finish, callback application */
        // TODO: Play again~~~
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
    #endif /* 0 */ 

        /* Call callback handler if not continue playing */
        player_p->state = AUD_MEDIA_IDLE;
        handler = (med_handler) player_p->handler_func;
        if (handler)
        {
            if(evt_result == MEDIA_END || evt_result == MEDIA_STOP_TIME_UP)
            {
                handler(ind_p->handle, MED_RES_END_OF_FILE);
            }
            else if(evt_result == MEDIA_DECODER_UNSUPPORT)
            {
                handler(ind_p->handle, MED_RES_DECODER_NOT_SUPPORT);            	
            }            
            else
            {
                handler(ind_p->handle, MED_RES_ERROR);
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_data_by_jtype_req
 * DESCRIPTION
 *  This function is to open media handle.
 * PARAMETERS
 *  media_type      [IN]        
 *  data            [?]         
 *  size            [IN]        
 *  repeats         [IN]        
 *  handler         [IN]        
 *  result          [?]         
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 aud_mma_open_data_by_jtype_req(
                    kal_uint8 media_type,
                    kal_uint8 *data,
                    kal_int32 size,
                    kal_int16 repeats,
                    kal_int32 handler,
                    kal_uint8 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    Media_Handle *med_handle = NULL;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *result = MED_RES_BUSY;

    switch (media_type)
    {
        case MMA_TYPE_MIDI:
        {
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (!player_p->used)
                {
                    Media_SMF_Param *smf_param_p;

                    aud_mma_close_all_single_player();

                    if ((med_handle = JSmf_Open(aud_mma_jtype_event_callback, (Media_SMF_Param **) & smf_param_p)) != NULL)
                    {
                        smf_param_p->smffile = (const kal_uint8*)data;
                        smf_param_p->filesize = (kal_int32) size;
                        smf_param_p->repeats = (kal_int16) repeats;

                        player_p->handler_func = handler;
                        player_p->handle = (kal_int32) med_handle;
                        player_p->used = KAL_TRUE;
                        player_p->is_device = KAL_FALSE;
                        player_p->state = AUD_MEDIA_IDLE;
                        *result = MED_RES_OK;
                    }
                    else
                    {
                        *result = MED_RES_OPEN_FILE_FAIL;
                    }
                    break;
                }
            }
            break;
        }
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (!player_p->used)
                {
                    aud_mma_close_all_single_player();

                    if ((med_handle = JTone_Open(
                                        aud_mma_jtype_event_callback,
                                        (Media_ToneSeq_Param **) & player_p->param_p)) != NULL)
                    {
                        player_p->handler_func = handler;
                        player_p->handle = (kal_int32) med_handle;
                        player_p->used = KAL_TRUE;
                        player_p->state = AUD_MEDIA_IDLE;
                        *result = MED_RES_OK;
                    }
                    else
                    {
                        *result = MED_RES_OPEN_FILE_FAIL;
                    }
                    break;
                }
            }
            break;
        }
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_IMY:
        {
            Media_iMelody_Param *imy_param_p;

            player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);

            if (!player_p->used)
            {
                aud_mma_close_all_single_player();

                if ((med_handle = JImy_Open(aud_mma_jtype_event_callback, (Media_iMelody_Param **) & imy_param_p)) != NULL)
                {
                    imy_param_p->imyfile = (const kal_uint8*)data;
                    imy_param_p->filesize = (kal_int32) size;
                    imy_param_p->repeats = (kal_int16) repeats;
                    imy_param_p->default_instrument = IMY_DEFAULT_INSTRUMENT;

                    player_p->handler_func = handler;
                    player_p->handle = (kal_int32) med_handle;
                    player_p->used = KAL_TRUE;
                    player_p->state = AUD_MEDIA_IDLE;
                    *result = MED_RES_OK;
                }
                else
                {
                    *result = MED_RES_OPEN_FILE_FAIL;
                }
            }
            break;
        }
        case MMA_TYPE_WAV:
        {
            for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (!player_p->used)
                {
                    kal_uint32 buf_len;
                    Media_Status status = MEDIA_FAIL;
                    Media_Wav_Param *wav_param_p;

                    aud_mma_close_all_single_player();

                    if ((med_handle = JWav_Open(aud_mma_jtype_event_callback, (Media_Wav_Param **) & wav_param_p)) != NULL)
                    {
                        player_p->handler_func = handler;
                        player_p->handle = (kal_int32) med_handle;

                        wav_param_p->wavefile = (const kal_uint8*)data;
                        wav_param_p->filesize = size;
                        wav_param_p->repeats = repeats;

                        if ((status = JWav_Load(med_handle, &buf_len)) != MEDIA_SUCCESS)
                        {
                            JWav_Close(med_handle);
                            AUD_VALUE_TRACE(status, size, buf_len);
                            med_handle = NULL;
                            *result = aud_get_res(status);
                            break;
                        }
                        if ((player_p->buf_p = (kal_int16*) med_alloc_ext_mem(buf_len * sizeof(kal_uint16))) != NULL)
                        {
                            JWav_SetBuffer(med_handle, player_p->buf_p, buf_len);
                        }
                        else
                        {
                            JWav_Close(med_handle);
                            AUD_VALUE_TRACE(status, size, buf_len);
                            med_handle = NULL;
                            *result = MED_RES_FAIL;
                            ASSERT(player_p->buf_p != NULL);
                            break;
                        }

                        player_p->used = KAL_TRUE;
                        player_p->state = AUD_MEDIA_IDLE;
                        *result = MED_RES_OK;
                    }
                    else
                    {
                        *result = MED_RES_OPEN_FILE_FAIL;
                    }
                    break;
                }
            }
            break;
        }
        default:
            ASSERT(0);
            break;
    }

    return (kal_int32) med_handle;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_file_by_jtype_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]         
 *  repeats         [IN]        
 *  handler         [IN]        
 *  result          [?]         
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 aud_mma_open_file_by_jtype_req(
                    kal_wchar *file_path,
                    kal_int16 repeats,
                    kal_int32 handler,
                    kal_uint8 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fs_handle;
    aud_player_struct *player_p;
    Media_Handle *med_handle = NULL;
    kal_int16 mma_format;
    kal_uint32 len;
    kal_uint32 buf_len;
    kal_int32 fs_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    if (player_p->used)
    {
        *result = MED_RES_BUSY;
        return 0;
    }

    /* Use DRM to open the file, then copy data to buffer and use buffer to play */
    fs_handle = DRM_open_file(file_path, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_NOBUSY_CHECK_MODE, DRM_PERMISSION_PLAY);

    if (fs_handle < 0)
    {
        *result = MED_RES_OPEN_FILE_FAIL;
        return 0;
    }

    /* Check file Size */
    fs_result = DRM_file_size(fs_handle, &buf_len);
    if (!(fs_result == FS_NO_ERROR && buf_len > 0))
    {
        DRM_close_file(fs_handle);
        *result = MED_RES_BAD_FORMAT;
        return 0;
    }
    else if (buf_len > AUD_MELODY_BUFFER_LEN)
    {
        DRM_close_file(fs_handle);
        *result = MED_RES_MEM_INSUFFICIENT;
        return 0;
    }

    /* Allocate memory to store data in file */
    aud_context_p->melody_string_p = med_alloc_ext_mem(buf_len);

    if (aud_context_p->melody_string_p == NULL)
    {
        DRM_close_file(fs_handle);
        *result = MED_RES_MEM_INSUFFICIENT;
        return 0;
    }

    /* Read data from file to buffer */
    DRM_read_file(fs_handle, aud_context_p->melody_string_p, buf_len, &len);

    /* Close the file */
    DRM_close_file(fs_handle);

    /* Read error, free file buffer */
    if (len == 0)
    {
        aud_free_melody_file_buffer();
        *result = MED_RES_BAD_FORMAT;
        return 0;
    }

    aud_mma_close_all_multi_player();

    mma_format = aud_mma_get_media_type(file_path);

    switch (mma_format)
    {
        case MMA_TYPE_MIDI:
        {
            Media_SMF_Param *smf_param_p;

            if ((med_handle = JSmf_Open(aud_mma_jtype_event_callback, &smf_param_p)) != NULL)
            {
                smf_param_p->smffile = (const kal_uint8*)aud_context_p->melody_string_p;
                smf_param_p->filesize = len;
                smf_param_p->repeats = repeats;

                player_p->handler_func = handler;
                player_p->handle = (kal_int32) med_handle;
                player_p->used = KAL_TRUE;
                player_p->is_device = KAL_FALSE;                
                player_p->state = AUD_MEDIA_IDLE;
                *result = MED_RES_OK;
            }
            else
            {
                aud_free_melody_file_buffer();
                *result = MED_RES_INVALID_FORMAT;
                return 0;
            }
            break;
        }
        case MMA_TYPE_IMY:
        {
            Media_iMelody_Param *imy_param_p;

            if ((med_handle = JImy_Open(aud_mma_jtype_event_callback, &imy_param_p)) != NULL)
            {
                imy_param_p->imyfile = (const kal_uint8*)aud_context_p->melody_string_p;
                imy_param_p->filesize = len;
                imy_param_p->repeats = repeats;
                imy_param_p->default_instrument = IMY_DEFAULT_INSTRUMENT;

                player_p->handler_func = handler;
                player_p->handle = (kal_int32) med_handle;
                player_p->used = KAL_TRUE;
                player_p->state = AUD_MEDIA_IDLE;
                *result = MED_RES_OK;
            }
            else
            {
                aud_free_melody_file_buffer();
                *result = MED_RES_OPEN_FILE_FAIL;
            }
            break;
        }
        default:
        {
            aud_free_melody_file_buffer();
            *result = MED_RES_INVALID_FORMAT;
            return 0;
        }
    }

    mma_single_p->type = mma_format;
    return (kal_int32) med_handle;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_by_fsal_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  data            [?]         
 *  size            [IN]        
 *  file_path       [?]         
 *  repeats         [IN]        
 *  handler         [IN]        
 *  result          [?]         
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 aud_mma_open_by_fsal_req(
                    kal_uint8 media_type,
                    kal_uint8 *data,
                    kal_int32 size,
                    kal_wchar *file_path,
                    kal_int16 repeats,
                    kal_int32 handler,
                    kal_uint8 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    mma_single_open_ptr openFunc = NULL;
    Media_VM_PCM_Param vpFormat;
    void *param = NULL;
    MHdl *mhdl_handle = NULL;
    FSAL_Status eFSALRet;
    kal_int16 mma_format;
    kal_bool from_file = KAL_FALSE;
    kal_uint8 *pbFSALBuf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    if (player_p->used)
    {
        *result = MED_RES_BUSY;
        return 0;
    }

    /* Open file */
    if (file_path != NULL)
    {
        if ((eFSALRet = FSAL_Open(&mma_single_p->fsal_handle, file_path, FSAL_READ_SHARED)) != FSAL_OK)
        {
            *result = MED_RES_OPEN_FILE_FAIL;
            return 0;
        }
        mma_format = aud_mma_get_media_type(file_path);
        from_file = KAL_TRUE;
    }
    /* Open data */
    else
    {
        FSAL_Direct_SetRamFileSize(&mma_single_p->fsal_handle, size);
        if ((eFSALRet = FSAL_Open(&mma_single_p->fsal_handle, data, FSAL_ROMFILE)) != FSAL_OK)
        {
            *result = MED_RES_OPEN_FILE_FAIL;
            return 0;
        }

        mma_format = media_type;
    }

    /* Can not play with multiple player */
    aud_mma_close_all_multi_player();

    switch (mma_format)
    {
        case MMA_TYPE_WAV:
            openFunc = WAV_Open;
            break;
    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
            vpFormat.mediaType = MED_TYPE_AMR;  /* Note it is MED type here */
            vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param = &vpFormat;
            openFunc = AMR_Open;
            break;
    #endif /* AMR_DECODE */ 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
            vpFormat.mediaType = MED_TYPE_AMR_WB;  /* Note it is MED type here */
            vpFormat.vmParam = (kal_uint32) MEDIA_VMP_AS_RINGTONE;
            param = &vpFormat;
            openFunc = AMR_Open;
            break;        
    #endif /* AMRWB_DECODE */
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif
            openFunc = DAF_Open;
            break;
    #endif /* DAF_DECODE */ 
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
            openFunc = AAC_Open;
            break;
        case MMA_TYPE_M4A:
            openFunc = M4A_Open;
            break;
    #endif /* AAC_DECODE */ 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
            openFunc = AU_Open;
            break;
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
            openFunc = WMA_Open;
            break;
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
            openFunc = AIFF_Open;
            break;
    #endif /* AIFF_DECODE */
        default:
            ASSERT(0);
            break;
    }

    /* Set Buffer for file */
    if (from_file)
    {
    #if defined(AUD_PROC_USE_EXT_MEM)
        pbFSALBuf = &med_aud_fasl_buf[0];
    #else 
        pbFSALBuf = (kal_uint8*) get_ctrl_buffer(sizeof(kal_uint8) * AUD_PROC_BUF_SIZE);
    #endif 

        FSAL_SetBuffer(&mma_single_p->fsal_handle, AUD_PROC_BUF_SIZE, pbFSALBuf);
    }
    /* No need to set buffer for ROM file */
    else
    {
        FSAL_SetBuffer(&mma_single_p->fsal_handle, 0, NULL);
    }

    /* Open FSAL File */
    if ((mhdl_handle = openFunc(aud_mma_fsal_event_callback, &mma_single_p->fsal_handle, param)) == NULL)
    {
        aud_mma_close_single_fsal();
        *result = MED_RES_BAD_FORMAT;
        return 0;
    }

    /* Call Audio Driver to set ring buffer for playing */
    mhdl_handle->SetBuffer(mhdl_handle, (kal_uint8*) aud_context_p->ring_buf, AUD_RING_BUFFER_LEN * 2);

    player_p->handler_func = handler;
    mma_single_p->repeat = repeats;
    player_p->handle = (kal_int32) mhdl_handle;
    player_p->used = KAL_TRUE;
    player_p->state = AUD_MEDIA_IDLE;
    mma_single_p->type = mma_format;

    *result = MED_RES_OK;
    return (kal_int32) mhdl_handle;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_open_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_req_struct *req_p;
    kal_uint8 result = 0;
    kal_int32 handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_open_req_struct*) ilm_ptr->local_para_ptr;

    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_handle(NULL);
        MMA_SET_EVENT(MMA_EVT_OPEN);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_handle(NULL);
        MMA_SET_EVENT(MMA_EVT_OPEN);
        return;
    }

    /* stop playing tasks before open any multiple play task */
    if (AUD_IN_STATE(AUD_MEDIA_PLAY) || AUD_IN_STATE(AUD_MEDIA_PLAY_PAUSED) || AUD_IN_STATE(AUD_MEDIA_PLAY_FINISH))
    {
        aud_stop_unfinished_process();
    }

    ASSERT(aud_context_p->state == AUD_MEDIA_IDLE);

    /* Besides tone sequence, need either data or file path when open */
    if (req_p->media_type != MMA_TYPE_TONE)
    {
        ASSERT((req_p->data != NULL && req_p->file_path == NULL) || (req_p->data == NULL && req_p->file_path != NULL));
    }

    /*
     * Open a file
     */
    if (req_p->file_path != NULL)
    {
        kal_int16 media_type = aud_mma_get_media_type(req_p->file_path);

        /* All files are single player but use different interface */
        switch (media_type)
        {
            case MMA_TYPE_MIDI:
            case MMA_TYPE_IMY:
                /* Streaming not support for MIDI, IMY */
                if(req_p->progressive_dl)
                {
                    result = MED_RES_INVALID_FORMAT;
                }
                else
                {
                    mma_single_p->is_progressive_dl = KAL_FALSE;
                    handle = aud_mma_open_file_by_jtype_req(req_p->file_path, req_p->repeats, req_p->handler, &result);
                }
                break;

            case MMA_TYPE_WAV:
        #ifdef AMR_DECODE
            case MMA_TYPE_AMR:
        #endif 
        #ifdef AMRWB_DECODE
            case MMA_TYPE_AWB:
        #endif 
        #ifdef DAF_DECODE
            case MMA_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MMA_TYPE_MUSICAM:
        #endif 
        #endif /* DAF_DECODE */
        #ifdef AAC_DECODE
            case MMA_TYPE_AAC:
            case MMA_TYPE_M4A:
        #endif 
        #ifdef AU_DECODE
            case MMA_TYPE_AU:
        #endif
        #ifdef WMA_DECODE
            case MMA_TYPE_WMA:
        #endif
        #ifdef AIFF_DECODE
            case MMA_TYPE_AIFF:
        #endif /* AIFF_DECODE */
                if(req_p->progressive_dl)
                {
                    mma_single_p->is_progressive_dl = KAL_TRUE;
                    mma_single_p->is_dl_finish = KAL_FALSE;                    
                    mma_single_p->underflow_offset = 0;
                    mma_single_p->underflow_time = 0;
                    mma_single_p->media_end_play_count = 0;
                }
                else
                {
                    mma_single_p->is_progressive_dl = KAL_FALSE;
                }

                handle = aud_mma_open_by_fsal_req(
                            0,
                            NULL,
                            0,
                            req_p->file_path,
                            req_p->repeats,
                            req_p->handler,
                            &result);
                break;

            default:
                /* Not support type */
                result = MED_RES_INVALID_FORMAT;
                break;
        }
    }
    /*
     * Open data stream
     */
    else
    {
        /* Streaming not support for data type */
        if(req_p->progressive_dl)
        {
            result = MED_RES_INVALID_FORMAT;
        }
        else
        {
            switch (req_p->media_type)
            {
                    /* Multiple player */
                case MMA_TYPE_MIDI:
            #ifdef JTONE_SUPPORT
                case MMA_TYPE_TONE:
            #endif
                case MMA_TYPE_IMY:
                case MMA_TYPE_WAV:
                    handle = aud_mma_open_data_by_jtype_req(
                                req_p->media_type,
                                req_p->data,
                                req_p->size,
                                req_p->repeats,
                                req_p->handler,
                                &result);
                    break;

                    /* Single player, can't play with other players simultaneously */
            #ifdef AMR_DECODE
                case MMA_TYPE_AMR:
            #endif 
            #ifdef AMRWB_DECODE
                case MMA_TYPE_AWB:
            #endif 
            #ifdef DAF_DECODE
                case MMA_TYPE_DAF:
            #ifdef MUSICAM_DECODE
                case MMA_TYPE_MUSICAM:
            #endif 
            #endif /* DAF_DECODE */ 
            #ifdef AAC_DECODE
                case MMA_TYPE_AAC:
                case MMA_TYPE_M4A:
            #endif 
            #ifdef AU_DECODE
                case MMA_TYPE_AU:
            #endif
            #ifdef WMA_DECODE
                case MMA_TYPE_WMA:
            #endif
            #ifdef AIFF_DECODE
                case MMA_TYPE_AIFF:
            #endif
                    mma_single_p->is_progressive_dl = KAL_FALSE;
                    
                    handle = aud_mma_open_by_fsal_req(
                                req_p->media_type,
                                req_p->data,
                                req_p->size,
                                NULL,
                                req_p->repeats,
                                req_p->handler,
                                &result);
                    break;

                default:
                    /* Not support type */
                    result = MED_RES_INVALID_FORMAT;
                    break;
            }
        }
    }

    mma_set_result(result);
    mma_set_handle(handle);
    MMA_SET_EVENT(MMA_EVT_OPEN);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_multiple_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_close_multiple_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    Media_Status status = MEDIA_FAIL;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
        {
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    ASSERT(player_p->is_device == KAL_FALSE);
                    status = JSmf_Close((Media_Handle*) handle);

                    player_p->used = KAL_FALSE;
                    player_p->handle = NULL;
                    break;
                }
            }
            break;
        }
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    status = JTone_Close((Media_Handle*) handle);

                    player_p->handle = NULL;
                    player_p->used = KAL_FALSE;
                    break;
                }
            }
            break;
        }
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_IMY:
        {
            player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
            if (player_p->used && player_p->handle == handle)
            {
                status = JImy_Close((Media_Handle*) handle);

                player_p->used = KAL_FALSE;
                player_p->handle = NULL;
            }
            break;
        }
        case MMA_TYPE_WAV:
        {
            for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    status = JWav_Close((Media_Handle*) handle);
                    med_free_ext_mem((void **)&(player_p->buf_p));

                    player_p->used = KAL_FALSE;
                    player_p->handle = NULL;
                    break;
                }
            }
            break;
        }
        default:
            ASSERT(0);
            break;
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_close_single_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    ASSERT(player_p->handle == handle);

    if (player_p->used)
    {
        switch (media_type)
        {
            case MMA_TYPE_MIDI:
                status = JSmf_Close((Media_Handle*) player_p->handle);
                aud_free_melody_file_buffer();

                player_p->used = KAL_FALSE;
                player_p->handle = NULL;
                break;

            case MMA_TYPE_IMY:
                aud_melody_stop_driver();
                status = JImy_Close((Media_Handle*) player_p->handle);
                aud_free_melody_file_buffer();

                player_p->used = KAL_FALSE;
                player_p->handle = NULL;
                break;

            case MMA_TYPE_WAV:
        #ifdef AMR_DECODE
            case MMA_TYPE_AMR:
        #endif 
        #ifdef AMRWB_DECODE
            case MMA_TYPE_AWB:
        #endif 
        #ifdef DAF_DECODE
            case MMA_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MMA_TYPE_MUSICAM:
        #endif 
        #endif /* DAF_DECODE */
        #ifdef AAC_DECODE
            case MMA_TYPE_AAC:
            case MMA_TYPE_M4A:
        #endif 
        #ifdef AU_DECODE
            case MMA_TYPE_AU:
        #endif
        #ifdef WMA_DECODE
            case MMA_TYPE_WMA:
        #endif
        #ifdef AIFF_DECODE
            case MMA_TYPE_AIFF:
        #endif
                mhdl_handle = (MHdl*) handle;

                status = mhdl_handle->Close(mhdl_handle);
                aud_mma_close_single_fsal();

                player_p->used = KAL_FALSE;
                player_p->handle = NULL;
                mma_single_p->type = -1;

                break;
            default:
                ASSERT(0);
                break;
        }
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_req_hdlr
 * DESCRIPTION
 *  This function is to close media handle.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_close_req_struct *req_p;
    kal_int32 result = MED_RES_INVALID_HANDLE;
    kal_bool is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_CLOSE);
        return;
    }

    req_p = (media_mma_close_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(req_p->handle != NULL);
    is_single = aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        result = aud_mma_close_single_req(mma_single_p->type, req_p->handle);
    }
    else
    {
        result = aud_mma_close_multiple_req(req_p->media_type, req_p->handle);
    }

    mma_set_result(result);
    MMA_SET_EVENT(MMA_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_play_multiple_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_play_multiple_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    Media_Status status = MEDIA_FAIL;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
        {
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_IDLE)
                    {
                        status = JSmf_Play((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_IDLE)
                    {                
                        status = JTone_Play((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_IMY:
        {
            player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
            if (player_p->used && player_p->handle == handle)
            {
                if(player_p->state == AUD_MEDIA_IDLE)
                {
                    status = JImy_Play((Media_Handle*) handle);
                }
            }
            break;
        }
        case MMA_TYPE_WAV:
        {
            for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_IDLE)
                    {
                        status = JWav_Play((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
        default:
            ASSERT(0);
            break;
    }


    if(status == MEDIA_SUCCESS)
    {
        player_p->state = AUD_MEDIA_PLAY;
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_play_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_play_single_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    ASSERT(player_p->handle == handle);

    if (player_p->used && (player_p->state == AUD_MEDIA_IDLE))
    {
        switch (media_type)
        {
            case MMA_TYPE_MIDI:
                status = JSmf_Play((Media_Handle*) handle);
                break;

            case MMA_TYPE_IMY:
                status = JImy_Play((Media_Handle*) handle);
                break;

            case MMA_TYPE_WAV:
        #ifdef AMR_DECODE
            case MMA_TYPE_AMR:
        #endif 
        #ifdef AMRWB_DECODE
            case MMA_TYPE_AWB:
        #endif 
        #ifdef DAF_DECODE
            case MMA_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MMA_TYPE_MUSICAM:
        #endif 
        #endif /*DAF_DECODE */
        #ifdef AAC_DECODE
            case MMA_TYPE_AAC:
            case MMA_TYPE_M4A:
        #endif 
        #ifdef AU_DECODE
            case MMA_TYPE_AU:
        #endif
        #ifdef WMA_DECODE
            case MMA_TYPE_WMA:
        #endif                
        #ifdef AIFF_DECODE
            case MMA_TYPE_AIFF:
        #endif
                mhdl_handle = (MHdl*) handle;
                status = mhdl_handle->Play(mhdl_handle);

                break;
            default:
                ASSERT(0);
                break;
        }
    }

    AUD_VALUE_TRACE(status, mma_single_p->is_progressive_dl, mma_single_p->is_dl_finish);

    if(status == MEDIA_SUCCESS)
    {
        player_p->state = AUD_MEDIA_PLAY;
    }
    else
    {
        /* Seek exceed end of file when progressive download not finish */
        if((status == MEDIA_SEEK_EOF) && mma_single_p->is_progressive_dl && !mma_single_p->is_dl_finish)
        {
            if((media_type != MMA_TYPE_MIDI) && (media_type != MMA_TYPE_IMY))
            {
                player_p->state = AUD_MEDIA_UNDERFLOW;        
                /* Keep current file position and Keep file offset for fast restore */
                mma_single_p->underflow_offset = mhdl_handle->GetFileOffset(mhdl_handle);
                mma_single_p->underflow_time = mhdl_handle->GetCurrentTime(mhdl_handle);                

                return MED_RES_BUFFER_INSUFFICIENT;
            }
        }
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_play_req_hdlr
 * DESCRIPTION
 *  This function is to play the media.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_play_req_struct *req_p;
    kal_int32 result = MED_RES_INVALID_HANDLE;
    kal_bool is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_play_req_struct*) ilm_ptr->local_para_ptr;

    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_PLAY);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_PLAY);
        return;
    }

    /* No output path setting for mma now, use default setting */
    aud_get_active_device_path_by_mode(aud_context_p->melody_output_device, aud_melody_set_output_device);

    ASSERT(req_p->handle != NULL);
    is_single = aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        result = aud_mma_play_single_req(mma_single_p->type, req_p->handle);
    }
    else
    {
        result = aud_mma_play_multiple_req(req_p->media_type, req_p->handle);
    }

    mma_set_result(result);
    MMA_SET_EVENT(MMA_EVT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_stop_multiple_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_stop_multiple_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    Media_Status status = MEDIA_FAIL;
    med_result_enum result = MED_RES_INVALID_HANDLE;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
        {
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    status = JSmf_Stop((Media_Handle*) handle);
                    player_p->state = AUD_MEDIA_IDLE;
                    break;
                }
            }
            break;
        }
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    status = JTone_Stop((Media_Handle*) handle);
                    player_p->state = AUD_MEDIA_IDLE;                    
                    break;
                }
            }
            break;
        }
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_IMY:
            player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
            if (player_p->used && player_p->handle == handle)
            {
                aud_melody_stop_driver();
                status = JImy_Stop((Media_Handle*) handle);
                player_p->state = AUD_MEDIA_IDLE;                
            }
            break;
        case MMA_TYPE_WAV:
        {
            for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    status = JWav_Stop((Media_Handle*) handle);
                    player_p->state = AUD_MEDIA_IDLE;                    
                    break;
                }
            }
            break;
        }
        default:
            ASSERT(0);
            result = MED_RES_ERROR;
            break;
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_stop_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_stop_single_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    ASSERT(player_p->handle == handle);

    if (player_p->used)
    {
        switch (media_type)
        {
            case MMA_TYPE_MIDI:
                status = JSmf_Stop((Media_Handle*) handle);
                player_p->state = AUD_MEDIA_IDLE;                
                break;

            case MMA_TYPE_IMY:
                aud_melody_stop_driver();
                status = JImy_Stop((Media_Handle*) handle);
                player_p->state = AUD_MEDIA_IDLE;                
                break;

            case MMA_TYPE_WAV:
        #ifdef AMR_DECODE
            case MMA_TYPE_AMR:
        #endif 
        #ifdef AMRWB_DECODE
            case MMA_TYPE_AWB:
        #endif 
        #ifdef DAF_DECODE
            case MMA_TYPE_DAF:
        #ifdef MUSICAM_DECODE
            case MMA_TYPE_MUSICAM:
        #endif 
        #endif /* DAF_DECODE */
        #ifdef AAC_DECODE
            case MMA_TYPE_AAC:
            case MMA_TYPE_M4A:
        #endif 
        #ifdef AU_DECODE
            case MMA_TYPE_AU:
        #endif
        #ifdef WMA_DECODE
            case MMA_TYPE_WMA:
        #endif                
        #ifdef AIFF_DECODE
            case MMA_TYPE_AIFF:
        #endif
                mhdl_handle = (MHdl*) handle;
                status = mhdl_handle->Stop(mhdl_handle);
                player_p->state = AUD_MEDIA_IDLE;                
                break;
            default:
                ASSERT(0);
                break;
        }
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_stop_req_hdlr
 * DESCRIPTION
 *  This function is to stop the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_stop_req_struct *req_p;
    med_result_enum result = MED_RES_INVALID_HANDLE;
    kal_bool is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_STOP);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_STOP);
        return;
    }

    req_p = (media_mma_stop_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(req_p->handle != NULL);
    is_single = aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        result = aud_mma_stop_single_req(mma_single_p->type, req_p->handle);
    }
    else
    {
        result = aud_mma_stop_multiple_req(req_p->media_type, req_p->handle);
    }

    mma_set_result(result);
    MMA_SET_EVENT(MMA_EVT_STOP);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_pause_multiple_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_pause_multiple_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p = NULL;
    Media_Status status = MEDIA_FAIL;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
        {
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_PLAY)
                    {
                        status = JSmf_Pause((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_PLAY)
                    {
                        status = JTone_Pause((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_IMY:
            player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
            if (player_p->used && player_p->handle == handle)
            {
                if(player_p->state == AUD_MEDIA_PLAY)
                {
                    aud_store_driver_status();
                    aud_melody_stop_driver();                
                    status = JImy_Pause((Media_Handle*) handle);
                }
            }
            break;
        case MMA_TYPE_WAV:
        {
            for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_PLAY)
                    {        
                        status = JWav_Pause((Media_Handle*) handle);
                    }

                    break;
                }
            }
            break;
        }

        default:
            ASSERT(0);
            break;
    }

    if(status == MEDIA_SUCCESS)
    {
        player_p->state = AUD_MEDIA_PLAY_PAUSED;
    }
    else
    {
        player_p->state = AUD_MEDIA_IDLE;
    }
    
    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_pause_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_pause_single_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);
    ASSERT(player_p->handle == handle);

    AUD_FUNC_ENTRY3(AUD_MMA_PAUSE_SINGLE_REQ, player_p->used, player_p->state, mma_single_p->is_progressive_dl);

    if (player_p->used)
    {
        if(player_p->state == AUD_MEDIA_PLAY)
        {       
            switch (media_type)
            {
                case MMA_TYPE_MIDI:
                    status = JSmf_Pause((Media_Handle*) handle);
                    break;

                case MMA_TYPE_IMY:
                    aud_store_driver_status();
                    aud_melody_stop_driver();
                    status = JImy_Pause((Media_Handle*) handle);
                    break;

                case MMA_TYPE_WAV:
            #ifdef AMR_DECODE
                case MMA_TYPE_AMR:
            #endif 
            #ifdef AMRWB_DECODE
                case MMA_TYPE_AWB:
            #endif 
            #ifdef DAF_DECODE
                case MMA_TYPE_DAF:
            #ifdef MUSICAM_DECODE
                case MMA_TYPE_MUSICAM:
            #endif 
            #endif /* DAF_DECODE */
            #ifdef AAC_DECODE
                case MMA_TYPE_AAC:
                case MMA_TYPE_M4A:
            #endif 
            #ifdef AU_DECODE
                case MMA_TYPE_AU:
            #endif
            #ifdef WMA_DECODE
                case MMA_TYPE_WMA:
            #endif                    
            #ifdef AIFF_DECODE
                case MMA_TYPE_AIFF:
            #endif
                    mhdl_handle = (MHdl*) handle;
                    status = mhdl_handle->Pause(mhdl_handle);
                    break;

                default:
                    ASSERT(0);
                    break;
            }

            AUD_VALUE_TRACE(status, -1, -1);
            
            if(status == MEDIA_SUCCESS)
            {
                player_p->state = AUD_MEDIA_PLAY_PAUSED;
            }
            /* For AAC ADIF only, it can not pause and will continue play */
            else if(status != MEDIA_UNSUPPORTED_OPERATION)
            {
                player_p->state = AUD_MEDIA_IDLE;
            }
        }
        /* Progressive download, buffer underflow, audio driver is in idle state*/
        else if(mma_single_p->is_progressive_dl && (player_p->state == AUD_MEDIA_UNDERFLOW))
        {
            player_p->state = AUD_MEDIA_UNDERFLOW_PAUSE;
            status = MEDIA_SUCCESS;
        }
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_pause_req_hdlr
 * DESCRIPTION
 *  This function is to pause the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_pause_req_struct *req_p;
    med_result_enum result = MED_RES_INVALID_HANDLE;
    kal_bool is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_PAUSE);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_PAUSE);
        return;
    }

    req_p = (media_mma_pause_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(req_p->handle != NULL);
    is_single = aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        result = aud_mma_pause_single_req(mma_single_p->type, req_p->handle);
    }
    else
    {
        result = aud_mma_pause_multiple_req(req_p->media_type, req_p->handle);
    }

    mma_set_result(result);
    MMA_SET_EVENT(MMA_EVT_PAUSE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_resume_multiple_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_resume_multiple_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    Media_Status status = MEDIA_FAIL;
    med_result_enum result = MED_RES_INVALID_HANDLE;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (media_type)
    {
        case MMA_TYPE_MIDI:
        {
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_PLAY_PAUSED)
                    {
                        status = JSmf_Resume((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_PLAY_PAUSED)
                    {
                        status = JTone_Resume((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_IMY:
            player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
            if (player_p->used && player_p->handle == handle)
            {
                if(player_p->state == AUD_MEDIA_PLAY_PAUSED)
                {
                    aud_restore_driver_status();
                    status = JImy_Resume((Media_Handle*) handle);
                }

                if(status != MEDIA_SUCCESS)
                {
                    aud_melody_stop_driver();
                }
            }
            break;
        case MMA_TYPE_WAV:
        {
            for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == handle)
                {
                    if(player_p->state == AUD_MEDIA_PLAY_PAUSED)
                    {
                        status = JWav_Resume((Media_Handle*) handle);
                    }
                    break;
                }
            }
            break;
        }
        default:
            ASSERT(0);
            result = MED_RES_ERROR;
            break;
    }

    if(status == MEDIA_SUCCESS)
    {
        player_p->state = AUD_MEDIA_PLAY;
    }
    else if(status == MEDIA_SEEK_EOF)
   	{
        player_p->state = AUD_MEDIA_IDLE;
   	}

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_resume_single_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 aud_mma_resume_single_req(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);
    ASSERT(player_p->handle == handle);

    AUD_FUNC_ENTRY3(AUD_MMA_RESUME_SINGLE_REQ, player_p->used, player_p->state, mma_single_p->is_progressive_dl);

    if (player_p->used)
    {
        if(player_p->state == AUD_MEDIA_PLAY_PAUSED)
        {

            switch (media_type)
            {
                case MMA_TYPE_MIDI:
                    status = JSmf_Resume((Media_Handle*) handle);
                    break;

                case MMA_TYPE_IMY:
                    aud_restore_driver_status();                	
                    status = JImy_Resume((Media_Handle*) handle);

                    if(status != MEDIA_SUCCESS)
                    {
                        aud_melody_stop_driver();
                    }                    
                    break;

                case MMA_TYPE_WAV:
            #ifdef AMR_DECODE
                case MMA_TYPE_AMR:
            #endif 
            #ifdef AMRWB_DECODE
                case MMA_TYPE_AWB:
            #endif 
            #ifdef DAF_DECODE
                case MMA_TYPE_DAF:
            #ifdef MUSICAM_DECODE
                case MMA_TYPE_MUSICAM:
            #endif 
            #endif /* DAF_DECODE */
            #ifdef AAC_DECODE
                case MMA_TYPE_AAC:
                case MMA_TYPE_M4A:
            #endif 
            #ifdef AU_DECODE
                case MMA_TYPE_AU:
            #endif
            #ifdef WMA_DECODE
                case MMA_TYPE_WMA:
            #endif                    
            #ifdef AIFF_DECODE
               case MMA_TYPE_AIFF:
            #endif
                    mhdl_handle = (MHdl*) handle;
                    status = mhdl_handle->Resume(mhdl_handle);
                    
                    break;
                default:
                    ASSERT(0);
                    break;
            }

            AUD_VALUE_TRACE(status, -1, -1);
            
            if(status == MEDIA_SUCCESS)
            {
                player_p->state = AUD_MEDIA_PLAY;
            }
            else if(status == MEDIA_SEEK_EOF)
           	{
                player_p->state = AUD_MEDIA_IDLE;
           	}
        }
        /* Progressive download, buffer underflow pause, audio driver is in idle state */
        else if(mma_single_p->is_progressive_dl && (player_p->state == AUD_MEDIA_UNDERFLOW_PAUSE))
        {
            player_p->state = AUD_MEDIA_UNDERFLOW;
            status = MEDIA_SUCCESS;
        }
        /* Progressive download, buffer underflow pause, can play from last offset because new data write */
        else if(mma_single_p->is_progressive_dl && (player_p->state == AUD_MEDIA_WRITE_DATA_PAUSE))
        {
            /* Use file offset directly to fast restore*/
            mhdl_handle = (MHdl*) handle;
            mhdl_handle->SetStoreFlag(mhdl_handle, KAL_TRUE);
            mhdl_handle->SetStartTime(mhdl_handle, mma_single_p->underflow_time);
            mhdl_handle->SetFileOffset(mhdl_handle, mma_single_p->underflow_offset);

            status = mhdl_handle->Play(mhdl_handle);

            AUD_VALUE_TRACE(status, -1, -1);

            if(status == MEDIA_SUCCESS)
            {
                player_p->state = AUD_MEDIA_PLAY;
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    return (kal_int32) aud_get_res((kal_uint8) status);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_resume_req_hdlr
 * DESCRIPTION
 *  This function is to resume the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_resume_req_struct *req_p;
    med_result_enum result = MED_RES_INVALID_HANDLE;
    kal_bool is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_RESUME);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_RESUME);
        return;
    }

    req_p = (media_mma_resume_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(req_p->handle != NULL);
    is_single = aud_mma_is_single_player(req_p->handle);

    if (is_single)
    {
        result = aud_mma_resume_single_req(mma_single_p->type, req_p->handle);
    }
    else
    {
        result = aud_mma_resume_multiple_req(req_p->media_type, req_p->handle);
    }

    mma_set_result(result);
    MMA_SET_EVENT(MMA_EVT_RESUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_audio_info_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_audio_info_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_audio_info_req_struct *req_p;
    mma_singe_get_meta_ptr get_des_func = NULL;
    audInfoStruct *content_info;
    med_result_enum result = MED_RES_OK;
    kal_int16 media_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_FAIL);
        MMA_SET_EVENT(MMA_EVT_GET_AUD_INFO);
        return;
    }

    req_p = (media_mma_get_audio_info_req_struct*) ilm_ptr->local_para_ptr;

    if(req_p->file_path != NULL)
    {
        media_type = aud_mma_get_media_type(req_p->file_path);
    }
    else
    {
        media_type = req_p->media_type;
    }


    ASSERT(req_p->audio_info != NULL);
    content_info = (audInfoStruct*) req_p->audio_info;    

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            get_des_func = JSmf_GetMetaData;
            break;
            
        case MMA_TYPE_IMY:
            get_des_func = JImy_GetMetaData;
            break;
            
        case MMA_TYPE_WAV:
            get_des_func = WAV_GetMetaData;
            break;

    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
            get_des_func = AMR_GetMetaData;
            break;
    #endif /* AMR_DECODE */
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
            get_des_func = AMR_GetMetaData;
            break;    
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif
            get_des_func = DAF_GetMetaData;
            break;        
    #endif /* DAF_DECODE */
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
            get_des_func = AAC_GetMetaData;
            break;        
        case MMA_TYPE_M4A:
            get_des_func = NULL; //M4A_GetMetaData; /* Support later */
            break;
    #endif /* AAC_DECODE */
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
            get_des_func = AU_GetMetaData;
            break;
    #endif /* AU_DECODE */
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
            get_des_func = WMA_GetMetaData;
            break;
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
            get_des_func = AIFF_GetMetaData;
            break;
    #endif /* AIFF_DECODE */
        default:
            result = MED_RES_INVALID_FORMAT;
            break;
    }

    if (get_des_func != NULL)
    {
        if (get_des_func(req_p->file_path, req_p->data, req_p->data_len, content_info, NULL ) != MEDIA_SUCCESS)
        {
            result = MED_RES_FAIL;
        }
    }
    else
    {
        memset(content_info, 0, sizeof(audInfoStruct));
    }

    mma_set_result(result);
    MMA_SET_EVENT(MMA_EVT_GET_AUD_INFO);
    
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_duration_for_m4a
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 aud_mma_get_duration_for_m4a(STFSAL *pstFSAL)
{
    /* To reduce memory usage when not define advance control,
       not provide get duration for M4A format because it will use mp4 parser. */
#ifdef __MED_MMA_JAVA_CTRL__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STMp4Parser *pstMp4Parser_M4A;
    kal_uint32 uMediaDuration = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pstMp4Parser_M4A = (STMp4Parser *)get_ctrl_buffer( sizeof(STMp4Parser) );

    {
        MP4_Parser_Status eMp4ParserRet;
        eMp4ParserRet = MP4_Parse(pstMp4Parser_M4A, pstFSAL);
        if(eMp4ParserRet!=MP4_PARSER_OK && eMp4ParserRet!=MP4_PARSER_WARNING_TRAILING_GARBAGE)
        {
            free_ctrl_buffer( pstMp4Parser_M4A );
            return uMediaDuration;
        }
    }

    {
        MP4_Parser_Status eMP4Status;
      
        eMP4Status = MP4_GetMediaDuration(pstMp4Parser_M4A, &uMediaDuration, MP4_TRACK_AUDIO);
      
        if (eMP4Status==MP4_PARSER_OK)
        {
            kal_uint32 uAudioTimeScale;
         
            if (MP4_GetMediaTimeScale(pstMp4Parser_M4A, &uAudioTimeScale, MP4_TRACK_AUDIO)==MP4_PARSER_OK)
            {
                uMediaDuration = ((kal_uint64)uMediaDuration * 1000) / (kal_uint64)uAudioTimeScale;
            }
        }
    }

   free_ctrl_buffer( pstMp4Parser_M4A );
   return uMediaDuration;

#else /* #ifdef __MED_MMA_JAVA_CTRL__ */
    return 0;
#endif  /* #ifdef __MED_MMA_JAVA_CTRL__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_duration_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_duration_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_duration_req_struct *req_p;
    kal_int32 duration = -1;
    kal_bool is_valid_used, is_single;
    mma_singe_get_duration_ptr get_des_func = NULL;
    audInfoStruct *content_info;
    kal_uint32 is_precise;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(0);
        MMA_SET_EVENT(MMA_EVT_GET_DURATION);
        return;
    }

    req_p = (media_mma_get_duration_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            duration = JSmf_GetDuration((Media_Handle*) req_p->handle);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            duration = JTone_GetDuration((Media_Handle*) req_p->handle);
            break;
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_WAV:
            is_single = aud_mma_is_single_player(req_p->handle);
            if (is_single)
            {
                get_des_func = WAV_GetContentDescInfo;
            }
            else
            {
                duration = JWav_GetDuration((Media_Handle*) req_p->handle);
            }
            break;
        case MMA_TYPE_IMY:
            duration = JImy_GetDuration((Media_Handle*) req_p->handle);
            break;
        case MMA_TYPE_M4A:
            duration = (kal_int32)aud_mma_get_duration_for_m4a(&mma_single_p->fsal_handle);
            break;

    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
            get_des_func = AMR_GetContentDescInfo;
            break;
    #endif /* AMR_DECODE */
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
            get_des_func = AMR_GetContentDescInfo;
            break;    
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif        
            get_des_func = DAF_GetContentDescInfo;
            break;        
    #endif /* DAF_DECODE */
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
            get_des_func = AAC_GetContentDescInfo;
            break;        
    #endif /* AAC_DECODE */
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
            get_des_func = AU_GetContentDescInfo;
            break;
    #endif /* AU_DECODE */
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
            get_des_func = WMA_GetContentDescInfo;
            break;
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
            get_des_func = AIFF_GetContentDescInfo;
            break;
    #endif /* AIFF_DECODE */
        default:
            ASSERT(0);
            break;
    }

    if (get_des_func != NULL)
    {
        /* Make sure fsal is opened */
        ASSERT(mma_single_p->fsal_handle.pbFile != NULL || mma_single_p->fsal_handle.hFile != NULL);
        
        content_info = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));
        if (get_des_func(&mma_single_p->fsal_handle, content_info, (void*)&is_precise) == MEDIA_SUCCESS)
        {
            duration = content_info->time;
        }
        free_ctrl_buffer(content_info);
    }

    mma_set_result(duration);
    MMA_SET_EVENT(MMA_EVT_GET_DURATION);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_current_time_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_current_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_current_time_req_struct *req_p;
    kal_int32 curr_time = 0;
    MHdl *mhdl_handle = NULL;
    kal_bool is_valid_used, is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(0);
        MMA_SET_EVENT(MMA_EVT_GET_CURR_TIME);
        return;
    }

    req_p = (media_mma_get_current_time_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            curr_time = JSmf_GetCurrentTime((Media_Handle*) req_p->handle);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            curr_time = JTone_GetCurrentTime((Media_Handle*) req_p->handle);
            break;
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_WAV:
            is_single = aud_mma_is_single_player(req_p->handle);
            if (is_single)
            {
                mhdl_handle = (MHdl*) req_p->handle;
                curr_time = mhdl_handle->GetCurrentTime(mhdl_handle);
            }
            else
            {
                curr_time = JWav_GetCurrentTime((Media_Handle*) req_p->handle);
            }
            break;
        case MMA_TYPE_IMY:
            curr_time = JImy_GetCurrentTime((Media_Handle*) req_p->handle);
            break;

    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
    #endif 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */ 
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
        case MMA_TYPE_M4A:
    #endif 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
    #endif            
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
    #endif
            mhdl_handle = (MHdl*) req_p->handle;
            curr_time = mhdl_handle->GetCurrentTime(mhdl_handle);

            break;
        default:
            ASSERT(0);
            break;
    }

    mma_set_result(curr_time);
    MMA_SET_EVENT(MMA_EVT_GET_CURR_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_start_time_req_hdlr
 * DESCRIPTION
 *  This function is to set the start time of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_start_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_start_time_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    MHdl *mhdl_handle = NULL;
    kal_bool is_valid_used, is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_START_TIME);
        return;
    }

    req_p = (media_mma_set_start_time_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
            /* Multiple player */
        case MMA_TYPE_MIDI:
            status = JSmf_SetStartTime((Media_Handle*) req_p->handle, req_p->start_time);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            status = JTone_SetStartTime((Media_Handle*) req_p->handle, req_p->start_time);
            break;
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_WAV:
            is_single = aud_mma_is_single_player(req_p->handle);
            if (is_single)
            {
                mhdl_handle = (MHdl*) req_p->handle;
                status = mhdl_handle->SetStartTime(mhdl_handle, (kal_uint32) req_p->start_time);
            }
            else
            {
                status = JWav_SetStartTime((Media_Handle*) req_p->handle, req_p->start_time);
            }
            break;
        case MMA_TYPE_IMY:
            status = JImy_SetStartTime((Media_Handle*) req_p->handle, req_p->start_time);
            break;
            /* Single player */
    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
    #endif 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */ 
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
        case MMA_TYPE_M4A:
    #endif 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
    #endif
            mhdl_handle = (MHdl*) req_p->handle;

            /* Not a progressive download fast restore action, need to seek from beginning.*/
            mhdl_handle->SetStoreFlag(mhdl_handle, KAL_FALSE);        
            status = mhdl_handle->SetStartTime(mhdl_handle, (kal_uint32) req_p->start_time);
            break;

        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_START_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_stop_time_req_hdlr
 * DESCRIPTION
 *  This function is to set the stop time of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_stop_time_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_stop_time_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    MHdl *mhdl_handle = NULL;
    kal_bool is_valid_used, is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_STOP_TIME);
        return;
    }

    req_p = (media_mma_set_stop_time_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JSmf_SetStopTime((Media_Handle*) req_p->handle, req_p->stop_time);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            status = JTone_SetStopTime((Media_Handle*) req_p->handle, req_p->stop_time);
            break;
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_WAV:
            is_single = aud_mma_is_single_player(req_p->handle);
            if (is_single)
            {
                mhdl_handle = (MHdl*) req_p->handle;
                status = mhdl_handle->SetStopTime(mhdl_handle, (kal_uint32) req_p->stop_time);
            }
            else
            {
                status = JWav_SetStopTime((Media_Handle*) req_p->handle, req_p->stop_time);
            }
            break;
        case MMA_TYPE_IMY:
            status = JImy_SetStopTime((Media_Handle*) req_p->handle, req_p->stop_time);
            break;

    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
    #endif 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */ 
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
        case MMA_TYPE_M4A:
    #endif 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
    #endif
            mhdl_handle = (MHdl*) req_p->handle;
            status = mhdl_handle->SetStopTime(mhdl_handle, (kal_uint32) req_p->stop_time);
            break;

        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_STOP_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_get_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_get_volume_req_struct *req_p;
    kal_int32 volume = 0;
    MHdl *mhdl_handle = NULL;
    kal_bool is_valid_used, is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(0);
        MMA_SET_EVENT(MMA_EVT_GET_VOLUME);
        return;
    }

    req_p = (media_mma_get_volume_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
            /* Multiple player */
        case MMA_TYPE_MIDI:
            volume = JMidi_GetLevel((Media_Handle*) req_p->handle);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            volume = JTone_GetLevel((Media_Handle*) req_p->handle);
            break;
    #endif /*JTONE_SUPPORT */
        case MMA_TYPE_WAV:
            is_single = aud_mma_is_single_player(req_p->handle);
            if (is_single)
            {
                mhdl_handle = (MHdl*) req_p->handle;
                volume = mhdl_handle->GetLevel(mhdl_handle);
            }
            else
            {
                volume = JWav_GetLevel((Media_Handle*) req_p->handle);
            }
            break;
        case MMA_TYPE_IMY:
            volume = JImy_GetLevel((Media_Handle*) req_p->handle);
            break;
            /* Single player */
    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
    #endif 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */ 
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
        case MMA_TYPE_M4A:
    #endif 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
    #endif            
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
    #endif
            mhdl_handle = (MHdl*) req_p->handle;
            volume = mhdl_handle->GetLevel(mhdl_handle);

            break;
        default:
            ASSERT(0);
            break;
    }

    mma_set_result(volume);
    MMA_SET_EVENT(MMA_EVT_GET_VOLUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_volume_req_hdlr
 * DESCRIPTION
 *  This function is to set the volume of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_volume_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    MHdl *mhdl_handle = NULL;
    kal_bool is_valid_used, is_single;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_VOLUME);
        return;
    }

    req_p = (media_mma_set_volume_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
            /* Multiple player */
        case MMA_TYPE_MIDI:
            status = JMidi_SetLevel((Media_Handle*) req_p->handle, req_p->volume);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            status = JTone_SetLevel((Media_Handle*) req_p->handle, req_p->volume);
            break;
    #endif /* JTONE_SUPPORT */
        case MMA_TYPE_WAV:
            is_single = aud_mma_is_single_player(req_p->handle);
            if (is_single)
            {
                mhdl_handle = (MHdl*) req_p->handle;
                status = mhdl_handle->SetLevel(mhdl_handle, req_p->volume);
            }
            else
            {
                status = JWav_SetLevel((Media_Handle*) req_p->handle, req_p->volume);
            }
            break;
        case MMA_TYPE_IMY:
            status = JImy_SetLevel((Media_Handle*) req_p->handle, req_p->volume);
            break;
            /* Single player */
    #ifdef AMR_DECODE
        case MMA_TYPE_AMR:
    #endif 
    #ifdef AMRWB_DECODE
        case MMA_TYPE_AWB:
    #endif 
    #ifdef DAF_DECODE
        case MMA_TYPE_DAF:
    #ifdef MUSICAM_DECODE
        case MMA_TYPE_MUSICAM:
    #endif 
    #endif /* DAF_DECODE */ 
    #ifdef AAC_DECODE
        case MMA_TYPE_AAC:
        case MMA_TYPE_M4A:
    #endif 
    #ifdef AU_DECODE
        case MMA_TYPE_AU:
    #endif
    #ifdef WMA_DECODE
        case MMA_TYPE_WMA:
    #endif
    #ifdef AIFF_DECODE
        case MMA_TYPE_AIFF:
    #endif
            mhdl_handle = (MHdl*) req_p->handle;
            status = mhdl_handle->SetLevel(mhdl_handle, req_p->volume);
            break;

        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_VOLUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_rate_req_hdlr
 * DESCRIPTION
 *  This function is to set the rate of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_rate_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_rate_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_RATE);
        return;
    }

    req_p = (media_mma_set_rate_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SetRate((Media_Handle*) req_p->handle, req_p->rate);
            break;

        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_RATE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_tempo_req_hdlr
 * DESCRIPTION
 *  This function is to set the tempo of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_tempo_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_tempo_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_TEMPO);
        return;
    }

    req_p = (media_mma_set_tempo_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SetTempo((Media_Handle*) req_p->handle, req_p->tempo);
            break;

        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_TEMPO);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_pitch_req_hdlr
 * DESCRIPTION
 *  This function is to set the pitch of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_pitch_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_pitch_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_PITCH);
        return;
    }

    req_p = (media_mma_set_pitch_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SetPitchTranspose((Media_Handle*) req_p->handle, req_p->pitch);
            break;
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
            status = JTone_SetPitchShift((Media_Handle*) req_p->handle, (kal_int8) req_p->pitch);
            break;
    #endif /*JTONE_SUPPORT */
        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_PITCH);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_send_long_msg_req_hdlr
 * DESCRIPTION
 *  This function is to send long msg of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_send_long_msg_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_send_long_msg_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SEND_LONG_MSG);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_SEND_LONG_MSG);
        return;
    }

    req_p = (media_mma_send_long_msg_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SendLongMsg((Media_Handle*) req_p->handle, req_p->buf, req_p->len);
            break;

        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SEND_LONG_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_send_short_msg_req_hdlr
 * DESCRIPTION
 *  This function is to send short msg of the media.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_send_short_msg_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_send_short_msg_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SEND_SHORT_MSG);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_SEND_SHORT_MSG);
        return;
    }

    req_p = (media_mma_send_short_msg_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SendShortMsg((Media_Handle*) req_p->handle, req_p->type, req_p->data1, req_p->data2);
            break;
        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SEND_SHORT_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_open_device_req_hdlr
 * DESCRIPTION
 *  This function is to open device.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_open_device_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_device_req_struct *req_p;
    Media_Handle *handle = NULL;
    aud_player_struct *player_p;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_handle(NULL);
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_OPEN_DEVICE);
        return;
    }

    if (aud_context_p->speech_on)
    {
        mma_set_handle(NULL);
        mma_set_result(MED_RES_BUSY);
        MMA_SET_EVENT(MMA_EVT_OPEN_DEVICE);
        return;
    }

    req_p = (media_mma_open_device_req_struct*) ilm_ptr->local_para_ptr;
    mma_set_result(MED_RES_FAIL);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (!player_p->used)
                {
                    aud_mma_close_all_single_player();
                    memset(player_p, 0, sizeof(aud_player_struct));

                    if ((handle = JMidi_OpenDevice()) != NULL)
                    {
                        player_p->used = KAL_TRUE;
                        player_p->handle = (kal_int32) handle;
                        player_p->is_device = KAL_TRUE;
                        mma_set_result(MED_RES_OK);
                        break;
                    }
                }
            }
            break;
        default:
            break;
    }

    mma_set_handle((kal_int32) handle);
    MMA_SET_EVENT(MMA_EVT_OPEN_DEVICE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_close_device_req_hdlr
 * DESCRIPTION
 *  This function is to close device.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_close_device_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_close_device_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    aud_player_struct *player_p;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_CLOSE_DEVICE);
        return;
    }

    req_p = (media_mma_close_device_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->used && player_p->handle == req_p->handle)
                {
                    ASSERT(player_p->is_device);
                    status = JMidi_CloseDevice((Media_Handle*) req_p->handle);

                    player_p->used = KAL_FALSE;
                    player_p->handle = NULL;
                    break;
                }
            }

            break;
        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_CLOSE_DEVICE);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_channel_volume_req_hdlr
 * DESCRIPTION
 *  This function is to set channel volume.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_channel_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_channel_volume_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_CHANNEL_VOLUME);
        return;
    }

    req_p = (media_mma_set_channel_volume_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SetChannelVolume((Media_Handle*) req_p->handle, req_p->channel, req_p->level);
            break;
        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_CHANNEL_VOLUME);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_program_req_hdlr
 * DESCRIPTION
 *  This function is to set program.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_program_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_program_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;
    kal_bool is_valid_used;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_PROGRAM);
        return;
    }

    req_p = (media_mma_set_program_req_struct*) ilm_ptr->local_para_ptr;

    is_valid_used = aud_mma_check_valid_handle_and_used(req_p->media_type, req_p->handle);
    ASSERT(is_valid_used);

    switch (req_p->media_type)
    {
        case MMA_TYPE_MIDI:
            status = JMidi_SetProgram((Media_Handle*) req_p->handle, req_p->channel, req_p->bank, req_p->program);
            break;
        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_PROGRAM);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_set_data_req_hdlr
 * DESCRIPTION
 *  This function is to set data.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_set_data_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_set_data_req_struct *req_p;
    Media_Status status = MEDIA_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_SET_DATA);
        return;
    }

    req_p = (media_mma_set_data_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(req_p->handle != NULL);
    switch (req_p->media_type)
    {
    #ifdef JTONE_SUPPORT
        case MMA_TYPE_TONE:
        {
            kal_uint8 i;
            aud_player_struct *player_p;

            for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
            {
                player_p = &(aud_context_p->player[i]);
                if (player_p->handle == req_p->handle)
                {
                    Media_ToneSeq_Param *toneseq_param_p;

                    toneseq_param_p = (Media_ToneSeq_Param*) player_p->param_p;
                    toneseq_param_p->toneSeq = req_p->data;
                    toneseq_param_p->toneSeqLen = req_p->size;
                    toneseq_param_p->repeats = req_p->repeats;

                    break;
                }
            }
            break;
        }
    #endif /*JTONE_SUPPORT */
        default:
            break;
    }

    mma_set_result((kal_int32) aud_get_res((kal_uint8) status));
    MMA_SET_EVENT(MMA_EVT_SET_DATA);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_write_data_ind_req_hdlr
 * DESCRIPTION
 *  This function is to set data.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mma_write_data_ind_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_write_data_ind_req_struct *req_p;
    Media_Status status;
    aud_player_struct *player_p;
    MHdl *mhdl_handle = NULL;
    kal_uint32 fsal_file_size;
    med_handler handler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_mma_write_data_ind_req_struct*) ilm_ptr->local_para_ptr;

    if (aud_context_p->access_mod != ilm_ptr->src_mod_id)
    {
        mma_set_result(MED_RES_BLOCKED);
        MMA_SET_EVENT(MMA_EVT_WRITE_DATA_IND);
        return;
    }

    ASSERT(req_p->handle != NULL);
    ASSERT(mma_single_p->is_progressive_dl);

    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    AUD_FUNC_ENTRY1(AUD_MMA_WRITE_DATA_IND_REQ_HDLR, player_p->state);

    if ((player_p->used) && (player_p->handle == req_p->handle))
    {
        mhdl_handle = (MHdl*) player_p->handle;
        
        if(req_p->is_finish)
        {
            mma_single_p->is_dl_finish = KAL_TRUE;
        }

        /* Buffer underflow stop, play from last offset */
        if(player_p->state == AUD_MEDIA_UNDERFLOW)
        {

            FSAL_Direct_GetFileSize(&mma_single_p->fsal_handle, &fsal_file_size);

            if(mma_single_p->underflow_offset < fsal_file_size)
            {
                /* Use file offset directly to fast restore*/
                mhdl_handle->SetStoreFlag(mhdl_handle, KAL_TRUE);
                mhdl_handle->SetStartTime(mhdl_handle, mma_single_p->underflow_time);
                mhdl_handle->SetFileOffset(mhdl_handle, mma_single_p->underflow_offset);

                status = mhdl_handle->Play(mhdl_handle);

                AUD_VALUE_TRACE(status, -1, __LINE__);

                if(status == MEDIA_SUCCESS)
                {
                    player_p->state = AUD_MEDIA_PLAY;
                }
                else if (req_p->is_finish)
                {
                    player_p->state = AUD_MEDIA_IDLE;
                    
                    if(status == MEDIA_SEEK_EOF)
                    {
                        handler = (med_handler) player_p->handler_func;
                        if (handler)
                        {
                            handler(player_p->handle, MED_RES_END_OF_FILE);
                        }
                    }
                    else
                    {
                        mma_set_result(MED_RES_FAIL);
                        MMA_SET_EVENT(MMA_EVT_WRITE_DATA_IND);
                        return;
                    }
                }
            }
        }
        /* Pause in underflow, change status to write data */
        else if(player_p->state == AUD_MEDIA_UNDERFLOW_PAUSE)
        {
            player_p->state = AUD_MEDIA_WRITE_DATA_PAUSE;
        }
    }
    else
    {
        ASSERT(0);
    }

    mma_set_result(MED_RES_OK);
    MMA_SET_EVENT(MMA_EVT_WRITE_DATA_IND);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_check_valid_handle_and_used
 * DESCRIPTION
 *  This function is to check if the hadle is valid and currently being used
 * PARAMETERS
 *  media_type      [IN]        
 *  handle          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool aud_mma_check_valid_handle_and_used(kal_uint8 media_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    aud_player_struct *player_p;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check Single Player */
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);
    if (player_p->used && player_p->handle == handle)
    {
        result = KAL_TRUE;
    }
    /* If not single player, it may one of the following multiplayer */
    else
    {
        switch (media_type)
        {
            case MMA_TYPE_MIDI:
                for (i = MMA_PLAYER_SMF_1; i <= MMA_PLAYER_SMF_4; i++)
                {
                    player_p = &(aud_context_p->player[i]);
                    if (player_p->used && player_p->handle == handle)
                    {
                        result = KAL_TRUE;
                        break;
                    }
                }
                break;

        #ifdef JTONE_SUPPORT
            case MMA_TYPE_TONE:
                for (i = MMA_PLAYER_TONE_S1; i <= MMA_PLAYER_TONE_S4; i++)
                {
                    player_p = &(aud_context_p->player[i]);
                    if (player_p->used && player_p->handle == handle)
                    {
                        result = KAL_TRUE;
                        break;
                    }
                }
                break;
        #endif /*JTONE_SUPPORT*/
            case MMA_TYPE_IMY:
                player_p = &(aud_context_p->player[MMA_PLAYER_IMY]);
                if (player_p->used && player_p->handle == handle)
                {
                    result = KAL_TRUE;
                }
                break;

            case MMA_TYPE_WAV:
                /* Multiple Player */
                for (i = MMA_PLAYER_WAV_1; i <= MMA_PLAYER_WAV_3; i++)
                {
                    player_p = &(aud_context_p->player[i]);
                    if (player_p->used && player_p->handle == handle)
                    {
                        result = KAL_TRUE;
                        break;
                    }
                }
                break;

            default:
                break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_is_single_player
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 aud_mma_is_single_player(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_player_struct *player_p;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player_p = &(aud_context_p->player[MMA_PLAYER_SINGLE]);

    if (player_p->used && player_p->handle == handle)
    {
        result = KAL_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_mma_get_media_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 aud_mma_get_media_type(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *p;
    kal_wchar temp[6];
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = file_name + kal_wstrlen(file_name) - 5;

    kal_mem_cpy(temp, p, 2 * 6);

    for (i = 0; i < 5; i++)
    {
        if (temp[i] >= 97 /* 'a' */  && temp[i] <= 122 /* 'z' */ )
        {
            temp[i] -= 32 /* ('a'-'A') */ ;
        }
    }

    p = &temp[2];
    if (kal_wstrcmp(p, L".AU") == 0)
    {
        return MMA_TYPE_AU;
    }

    p = &temp[1];
    if (kal_wstrcmp(p, L".IMY") == 0)
    {
        return MMA_TYPE_IMY;
    }
    if (kal_wstrcmp(p, L".MID") == 0)
    {
        return MMA_TYPE_MIDI;
    }
    if (kal_wstrcmp(p, L".WAV") == 0)
    {
        return MMA_TYPE_WAV;
    }
    if (kal_wstrcmp(p, L".MP3") == 0)
    {
        return MMA_TYPE_DAF;
    }
    if (kal_wstrcmp(p, L".MP2") == 0)
    {
        return MMA_TYPE_MUSICAM;
    }
    if (kal_wstrcmp(p, L".AMR") == 0)
    {
        return MMA_TYPE_AMR;
    }
    if (kal_wstrcmp(p, L".AWB") == 0)
    {
        return MMA_TYPE_AWB;
    }
    if (kal_wstrcmp(p, L".AAC") == 0)
    {
        return MMA_TYPE_AAC;
    }
    if (kal_wstrcmp(p, L".WMA") == 0)
    {
        return MMA_TYPE_WMA;
    }
    if (kal_wstrcmp(p, L".M4A") == 0)
    {
        return MMA_TYPE_M4A;
    }
    if (kal_wstrcmp(p, L".AIF") == 0)
    {
        return MMA_TYPE_AIFF;
    }

#if defined(__DRM_V02__)
    if (kal_wstrcmp(p, L".ODF") == 0)
    {
        /* Make sure it is not multi-part ODF */
        if (!DRM_is_archive(NULL, file_name ))
        {
            kal_char *ext_name;
            kal_wchar temp_file_name[10];
            
            /* Single part ODF , get single part ODF content extension name */
            ext_name = DRM_get_content_ext(NULL, file_name);
            kal_wsprintf(temp_file_name, "A.%s", ext_name);

            return aud_mma_get_media_type(temp_file_name);
        }
    }
#endif /* defined(__DRM_V02__) */

    p = &temp[0];
    if (kal_wstrcmp(p, L".AIFF") == 0 || kal_wstrcmp(p, L".AIFC") == 0)
    {
        return MMA_TYPE_AIFF;
    }
    if (kal_wstrcmp(p, L".MIDI") == 0)
    {
        return MMA_TYPE_MIDI;
    }

    return -1;

}

#endif /* __MED_MMA_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

