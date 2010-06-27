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
 * aud_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of audio manager task.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _AUD_MAIN_H
#define _AUD_MAIN_H

typedef enum
{
    AUD_EVT_NOWAIT = 0,
    AUD_EVT_PLAY = 0x0001,
    AUD_EVT_STOP = 0x0002,
    AUD_EVT_RECORD = 0x0004,
    AUD_EVT_PAUSE = 0x0008,
    AUD_EVT_RESUME = 0x0010,
    AUD_EVT_BLOCK = 0x0020,
    AUD_EVT_FMR_ON = 0x0040,
    AUD_EVT_FMR_OFF = 0x0080,
    AUD_EVT_FMR_SET = 0x0100,
    AUD_EVT_FMR_MUTE = 0x0200,
    AUD_EVT_VR_GET_VER = 0x0400,
    AUD_EVT_VR_GET_PARAM = 0x0800,
    AUD_EVT_VR_SET_PARAM = 0x1000,
    AUD_EVT_VR_INIT_RCG = 0x2000,
    AUD_EVT_VR_INIT_TRN = 0x4000,
    AUD_EVT_VR_VOICE_IN = 0x8000,
    AUD_EVT_VR_DEL_TAG = 0x10000,
    AUD_EVT_VR_CHECK_TAG = 0x20000,
    AUD_EVT_VR_SYNC_DB = 0x40000,
    AUD_EVT_VR_PLAY_TAG = 0x80000,
    AUD_EVT_VR_GET_DIR = 0x100000,
    AUD_EVT_VR_ADD_TAG = 0x200000,
    AUD_EVT_VR_ABORT = 0x400000,
    AUD_EVT_GET_DURATION = 0x800000,
    AUD_EVT_GET_PROGRESS_TIME = 0x1000000,
    AUD_EVT_SET_PROGRESS_TIME = 0x2000000,
    AUD_EVT_GET_SPECTRUM = 0x4000000,
    AUD_EVT_FMR_EVA_THRESHOLD = 0x8000000,
    AUD_EVT_BT_CLOSE_AUDIO = 0x10000000,
    AUD_EVT_BT_TURN_OFF_AUDIO = 0x20000000,
    AUD_EVT_IS_PURE_AUDIO = 0x40000000    
}
aud_wait_event_enum;

//ANALOG_TV_SUPPORT
#ifdef __MED_TLG_TV_MOD__
typedef enum
{
   TLG_TV_EVT_NOWAIT    = 0,
   TLG_TV_EVT_PWR_ON   = 0x0001,
   TLG_TV_EVT_PWR_OFF = 0x0002,
   TLG_TV_EVT_OPEN_PATH = 0x0004,
   TLG_TV_EVT_CLOSE_PATH = 0x0008,
   TLG_TV_EVT_MUTE = 0x0010
} 
fmt_wait_event_enum; 
#endif //#ifdef __MED_TLG_TV_MOD__

typedef enum
{
    VRSI_EVT_INIT = 0x0001,
    VRSI_EVT_ADD_TAGS = 0x0002,
    VRSI_EVT_START_CMD_TRN = 0x0004,
    VRSI_EVT_START_CMD_RCG = 0x0008,
    VRSI_EVT_START_DIGIT_RCG = 0x0010,
    VRSI_EVT_START_DIGIT_ADAPT = 0x0020,
    VRSI_EVT_PLAY_TAG = 0x0040,
    VRSI_EVT_PLAY_TTS = 0x0080,
    VRSI_EVT_GET_TAG_NUM = 0x0100,
    VRSI_EVT_GET_TAG_INFO = 0x0200,
    VRSI_EVT_DEL_TAGS = 0x0400,
    VRSI_EVT_RESET_TAGS = 0x0800,
    VRSI_EVT_SYNC_DB = 0x1000,
    VRSI_EVT_ABORT = 0x2000,
    VRSI_EVT_CLOSE = 0x4000
}
vrsi_wait_event_enum;

typedef enum
{
    AUD_VR_STATE_IDLE,
    AUD_VR_STATE_TRN_SESSION,
    AUD_VR_STATE_RCG_SESSION,
    AUD_VR_NO_OF_STATE
} aud_vr_state_enum;

typedef enum
{
    AUD_VR_SD_SESSION_STAGE_NOT_READY,
    AUD_VR_SD_SESSION_STAGE_READY,
    AUD_VR_SD_SESSION_STAGE_PROCESS,
    AUD_VR_SD_SESSION_STAGE_WAIT,
    AUD_VR_SD_SESSION_STAGE_PROCESS_2ND,
    AUD_VR_SD_SESSION_NO_OF_STAGE
} aud_vr_sd_session_stage_enum;

typedef enum
{
    AUD_CTM_STATE_IDLE,
    AUD_CTM_STATE_READY,
    AUD_CTM_STATE_CONNECTING,
    AUD_CTM_STATE_CONNECTED,
    AUD_CTM_STATE_SENDING,
    AUD_CTM_NO_OF_STATE
} aud_ctm_state_enum;

typedef struct
{
    module_type src_mod;
    kal_uint32 session_id;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
    kal_uint16 group_id;
    kal_uint16 word_id;
    kal_int16 db_drive;
    kal_uint8 state;
    kal_uint8 mode;
    kal_uint8 lang;
}
aud_vr_context_struct;

typedef struct
{
    VRSI_AddTags_Param addtags_param;
    VRSI_Tag_Param tag_param;
    VRSI_Recog_Result *recog_result;
    VRSI_Digit_Recog_Result *dgt_rcg_result;
    kal_uint8 *buffer;
    kal_uint16 *id_list;
    kal_uint8 *grammar;
    kal_uint32 session_id;
    kal_bool session_on;
    kal_uint8 pmp_len;
    kal_uint8 state;
    const kal_uint16 *pmp_text;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
} aud_vrsi_context_struct;

typedef struct
{
    kal_uint8 stage;
    kal_uint16 id_array[VR_SD_MAX_GROUP_NUM][VR_SD_MAX_GROUP_TAG_NUM];
    kal_uint16 id_length[VR_SD_MAX_GROUP_NUM];
    kal_uint8 *buffer;
}
aud_vr_sd_context_struct;

typedef struct
{
    kal_uint8 head;
    kal_uint8 tail;
    kal_uint16 queue[CTM_MAX_SEND_REQ_NUM + 1];
} aud_ctm_send_text_req_queue_struct;

typedef struct
{
    kal_uint8 state;
    kal_uint8 mode;
    kal_uint8 first_recv_utf8_byte;
    kal_bool more_recv_utf8_byte;
    module_type src_mod_id;
    kal_uint16 unsent_count;    /* count bytes */
    aud_ctm_send_text_req_queue_struct send_req_queue;
    kal_uint8 *buf_p;
    kal_uint8 *ucs2_utf8_buf_p;
    kal_uint8 input_vol, output_vol;
} aud_ctm_context_struct;

#define AUD_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(aud_context_p->aud_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define AUD_SET_EVENT(evt_) do{                                \
   kal_set_eg_events(aud_context_p->aud_event, (evt_),KAL_OR); \
   } while(0)

//ANALOG_TV_SUPPORT
#ifdef __MED_TLG_TV_MOD__
#define TLG_TV_WAIT_EVENT(evt_) do{ \
         kal_uint32 retrieved_events;\
         kal_retrieve_eg_events(aud_context_p->tlg_tv_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0) 
         
#define TLG_TV_SET_EVENT(evt_) do{ \
	kal_set_eg_events(aud_context_p->tlg_tv_event, (evt_),KAL_OR); \
	} while(0)

#endif //#ifdef __MED_TLG_TV_MOD__
//ANALOG_TV_SUPPORT

#define VRSI_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                              \
         kal_retrieve_eg_events(aud_context_p->vrsi_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define VRSI_SET_EVENT(evt_) do{                                \
   kal_set_eg_events(aud_context_p->vrsi_event, (evt_),KAL_OR); \
   } while(0)

#define SET_CURRENT_VOLUME_LEVEL(_m_,_v_) if(aud_context_p->audio_mode<MAX_AUD_MODE_NUM&&_m_<AUD_MAX_VOLUME_TYPE)\
                                                aud_context_p->acoustic_data.volume[aud_context_p->audio_mode][_m_]=_v_
/* for MMA event group */
typedef enum
{
    MMA_EVT_NOWAIT = 0,
    MMA_EVT_OPEN = 0x0001,
    MMA_EVT_CLOSE = 0x0002,
    MMA_EVT_PLAY = 0x0004,
    MMA_EVT_STOP = 0x0008,
    MMA_EVT_PAUSE = 0x0010,
    MMA_EVT_RESUME = 0x0020,
    MMA_EVT_SET_START_TIME = 0x0040,
    MMA_EVT_SET_STOP_TIME = 0x0080,
    MMA_EVT_SET_RATE = 0x0100,
    MMA_EVT_SET_TEMPO = 0x0200,
    MMA_EVT_SET_PITCH = 0x0400,
    MMA_EVT_SET_VOLUME = 0x0800,
    MMA_EVT_SEND_LONG_MSG = 0x1000,
    MMA_EVT_SEND_SHORT_MSG = 0x2000,
    MMA_EVT_OPEN_DEVICE = 0x4000,
    MMA_EVT_CLOSE_DEVICE = 0x8000,
    MMA_EVT_SET_CHANNEL_VOLUME = 0x10000,
    MMA_EVT_SET_PROGRAM = 0x20000,
    MMA_EVT_SET_DATA = 0x40000,
    MMA_EVT_GET_DURATION = 0x80000,
    MMA_EVT_GET_CURR_TIME = 0x100000,
    MMA_EVT_GET_VOLUME = 0x200000,
    MMA_EVT_WRITE_DATA_IND = 0x400000,
    MMA_EVT_GET_AUD_INFO = 0x800000
}
mma_wait_event_enum;

#define MMA_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(aud_context_p->mma_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define MMA_SET_EVENT(evt_) kal_set_eg_events(aud_context_p->mma_event, (evt_),KAL_OR)

#if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)

typedef enum
{
    SND_EVT_NOWAIT = 0,
    SND_EVT_CHECK = 0x0001,
    SND_EVT_PLAY = 0x0002,
    SND_EVT_STOP = 0x0004,
    SND_EVT_SET = 0x0008,
    TS_EVT_CHECK = 0x0010,
    TS_EVT_SET = 0x0020,
    TS_EVT_CLOSE = 0x0040,
    REVERB_EVT_SET = 0x0080,
    REVERB_EVT_ON = 0x0100,
    REVERB_EVT_OFF = 0x0200,
    SURROUND_EVT_ON = 0x0400,
    SURROUND_EVT_OFF = 0x0800,
    EQ_EVT_SET = 0x1000,
    EQ_EVT_ON = 0x2000,
    EQ_EVT_OFF = 0x4000
}
aud_effect_wait_event_enum;

#define EFFECT_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                                \
         kal_retrieve_eg_events(aud_context_p->effect_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define EFFECT_SET_EVENT(evt_) kal_set_eg_events(aud_context_p->effect_event, (evt_),KAL_OR)

#endif /* #if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)*/ 

#if defined(__MED_GENERAL_TTS__)
typedef enum
{
    TTS_EVT_NO_WAIT = 0,
    TTS_EVT_PLAY = 0x0001,
    TTS_EVT_STOP = 0x0002,
    TTS_EVT_PAUSE = 0x0004,
    TTS_EVT_RESUME = 0x0008,
    TTS_EVT_SET_ATTR = 0x0010
}
aud_tts_wait_event_enum;

#define TTS_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                                \
         kal_retrieve_eg_events(aud_context_p->tts_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define TTS_SET_EVENT(evt_) kal_set_eg_events(aud_context_p->tts_event, (evt_),KAL_OR)

#endif /* #if defined(__MED_GENERAL_TTS__) */ 

#define aud_send_msg_to_med( src_id, msg_id, local_param_ptr ) aud_send_msg(src_id, MOD_MED, msg_id, local_param_ptr)
#define aud_send_msg_from_med( dst_id, msg_id, local_param_ptr ) aud_send_msg(MOD_MED, dst_id, msg_id, local_param_ptr)

#ifdef __MED_BT_A2DP_MOD__
typedef enum
{
    AUD_BT_A2DP_STATE_IDLE,
    AUD_BT_A2DP_STATE_CONFIGURED,
    AUD_BT_A2DP_STATE_OPEN,
    AUD_BT_A2DP_STATE_STREAMING
} aud_bt_a2dp_state_enum;

typedef enum
{
    AUD_BT_A2DP_WAIT_NONE,
    AUD_BT_A2DP_WAIT_ABORT,
    AUD_BT_A2DP_WAIT_DISCOVER,
    AUD_BT_A2DP_WAIT_GET_CAP,
    AUD_BT_A2DP_WAIT_CONFIG_STREAM,
    AUD_BT_A2DP_WAIT_RECONFIG_STREAM,
    AUD_BT_A2DP_WAIT_OPEN_STREAM,
    AUD_BT_A2DP_WAIT_START_STREAM,
    AUD_BT_A2DP_WAIT_PAUSE_STREAM,
    AUD_BT_A2DP_WAIT_CLOSE_STREAM
} aud_bt_a2dp_wait_enum;

typedef enum
{
    AUD_BT_A2DP_CMD_NONE,
    AUD_BT_A2DP_CMD_ABORT,
    AUD_BT_A2DP_CMD_RECONFIG_STREAM,
    AUD_BT_A2DP_CMD_START_STREAM,
    AUD_BT_A2DP_CMD_PAUSE_STREAM,
    AUD_BT_A2DP_CMD_CLOSE_STREAM
} aud_bt_a2dp_cmd_enum;

typedef enum
{
    AUD_BT_A2DP_SERVICE_STATUS_IDLE,
    AUD_BT_A2DP_SERVICE_STATUS_OPENING,
    AUD_BT_A2DP_SERVICE_STATUS_RUNNING,
    AUD_BT_A2DP_SERVICE_STATUS_CLOSING,
    AUD_BT_A2DP_SERVICE_STATUS_OPENING_CLOSING
} aud_bt_a2dp_sevice_status_enum;
#endif /* __MED_BT_A2DP_MOD__ */ 

#ifdef __MED_BT_HFP_MOD__
typedef enum
{
    AUD_BT_HFP_STATE_IDLE,
    AUD_BT_HFP_STATE_OPEN
} aud_bt_hfp_state_enum;

typedef enum
{
    AUD_BT_HFP_CMD_NONE,
    AUD_BT_HFP_CMD_CONNECT_SCO,
    AUD_BT_HFP_CMD_DISCONNECT_SCO
} aud_bt_hfp_cmd_enum;
#endif /* __MED_BT_HFP_MOD__ */ 

typedef enum
{
    AUD_REC_QUALITY_LOW,
    AUD_REC_QUALITY_MED,
    AUD_REC_QUALITY_HIGH,
    AUD_REC_QUALITY_BEST
} aud_rec_quality_enum;

/*==== PROTOTYPE ===========*/

/* main */
extern kal_bool aud_init(void);
extern void aud_main(ilm_struct *ilm_ptr);
extern void aud_startup_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_startup_param(void);
extern void aud_startup_read_nvram_data(void);
extern void aud_debug_print_aud_drv_return(kal_int32 aud_ret, kal_uint32 line);

/* audio */
extern kal_bool aud_audio_init(void);
extern void aud_get_audio_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_gpio_detect_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_profile_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_profile_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_set_melody_path_volume(kal_uint8 audio_mode);
extern void aud_audio_set_fmrdo_path_volume(kal_uint8 audio_mode);
extern void aud_set_aud_path_volume(kal_uint8 audio_mode);
extern void aud_set_tv_out_aud_path(kal_uint8 tv_on);
extern void aud_set_tv_out_param(kal_uint8 enable_loud_spk);
extern void aud_audio_get_volume_req(ilm_struct *ilm_ptr);
extern void aud_audio_get_gain_req(ilm_struct *ilm_ptr);
extern void aud_audio_set_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_mute_req_hdlr(ilm_struct *ilm_ptr);
extern kal_bool aud_cfg_audio_out_device(kal_uint8 audio_sound_id, kal_uint8 *out_device_path);
extern void aud_play_by_id_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_by_id_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_play_by_name_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_by_name_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_play_by_string_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_by_string_req_hdlr(ilm_struct *ilm_ptr);
extern kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level);
extern kal_uint8 aud_get_volume_level(kal_uint8 mode, kal_uint8 type);
extern void aud_audio_set_device_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_set_gain_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_block_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_headset_mode_output_path_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_spectrum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_start_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_get_duration_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_get_progress_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_set_progress_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_melody_volume(kal_uint8 mode, kal_uint8 level);
extern void aud_media_is_pure_audio_req_hdlr(ilm_struct *ilm_ptr);

/* speech */
extern kal_bool aud_speech_init(void);
extern void aud_speech_main(ilm_struct *ilm_ptr);
extern void aud_speech_set_output_device(kal_uint8 device);
extern void aud_speech_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_speech_set_input_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_speech_set_mode_req_hdlr(ilm_struct *ilm_ptr);

extern void aud_speech_set_fir(kal_bool fir_on);
extern void aud_speech_set_fir_coefficient(kal_int16 input_FIR_index, kal_int16 output_FIR_index);
extern void aud_speech_set_fir_index_by_mode(kal_uint8 audio_mode);
extern void aud_speech_set_fir_index(void);
extern void aud_mic_set_device(kal_uint8 device);
extern void aud_mic_set_device_no_apply(kal_uint8 device);
extern void aud_mic_set_volume(kal_uint8 volume1, kal_uint8 volume2);
extern void aud_mic_mute(kal_bool mute);
extern void aud_side_tone_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index);

/* keytone */
extern kal_bool aud_keytone_init(void);
extern void aud_keytone_main(ilm_struct *ilm_ptr);
extern void aud_keytone_set_output_device(kal_uint8 device);
extern void aud_keytone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_keytone_play(kal_uint8 audio_id, kal_uint8 audio_out_device);
extern void aud_keytone_stop(void);

/* tone */
extern kal_bool aud_tone_init(void);
extern void aud_tone_main(ilm_struct *ilm_ptr);
extern void aud_tone_set_output_device(kal_uint8 device);
extern void aud_tone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_tone_play(kal_uint8 audio_id, kal_uint8 audio_out_device);
extern void aud_tone_stop(void);
extern void aud_set_active_tone_volume(void);

/* melody */
extern kal_bool aud_melody_init(void);
extern void aud_free_melody_file_buffer(void);
extern kal_bool aud_melody_startup(void);
extern void aud_melody_main(ilm_struct *ilm_ptr);
extern void aud_melody_set_output_device(kal_uint8 device);
extern void aud_melody_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_set_active_ring_tone_volume(void);
extern void aud_set_active_sound_volume(void);
extern void aud_get_active_device_path_by_mode(kal_uint8 request_path, void (*set_path_func)(kal_uint8));
extern kal_uint8 aud_melody_play_style_convert(kal_uint8 play_style);
extern void aud_melody_stop_crescendo(void);
extern void aud_melody_start_crescendo(kal_uint8 play_style);
extern void aud_melody_crescendo_hdlr(void *arg);
extern void aud_melody_set_volume(kal_uint8 volume1, kal_int8 aud_melody_set_volume);
extern void aud_melody_play_by_id(kal_uint8 audio_id, kal_uint8 play_style, kal_uint8 audio_out_device);
extern kal_uint8 aud_melody_play_by_name(kal_wchar *file_name, kal_uint8 play_style, kal_uint8 audio_out_device);
extern kal_int32 aud_melody_play_by_string(
                    kal_uint8 *string,
                    kal_uint8 play_style,
                    kal_uint32 string_len,
                    kal_uint8 format);
extern kal_uint8 aud_melody_get_duration(kal_wchar *file_name, kal_uint8 *aud_data, kal_uint32 aud_len, kal_int16 format, kal_uint32* duration);
extern kal_uint8 aud_melody_restore_by_name(kal_wchar *file_name, kal_uint8 play_style, kal_uint8 audio_out_device);
extern Media_Status aud_melody_pause(void);
extern Media_Status aud_melody_resume(void);
extern void aud_melody_close_handle(void);
extern void aud_melody_set_max_swing(kal_uint16 max_swing);
extern void aud_media_play_event_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_event_callback(Media_Event event);
extern void aud_set_vibrator_enabled_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_melody_stop_driver(void);
extern void aud_melody_imy_close_backlight_ctrl(void);
extern void aud_melody_imy_vibrator_hdlr(kal_bool on);
extern void aud_melody_imy_led_hdlr(kal_bool on);
extern void aud_melody_imy_backlight_hdlr(kal_bool on);
extern void aud_store_driver_status(void);
extern void aud_restore_driver_status(void);

#ifdef __MED_MMA_MOD__
/* mma */
extern void mma_set_handle(kal_int32 handle);
extern void mma_set_result(kal_int32 result);
extern kal_bool aud_mma_startup(void);
extern void aud_mma_close_all(void);
extern void aud_mma_play_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_fsal_process_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_open_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_close_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_audio_info_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_duration_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_current_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_start_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_stop_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_rate_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_tempo_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_pitch_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_send_long_msg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_send_short_msg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_open_device_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_close_device_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_channel_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_program_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_data_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_write_data_ind_req_hdlr(ilm_struct *ilm_ptr);
extern kal_int16 aud_mma_get_media_type(kal_wchar *file_name);
#endif /* __MED_MMA_MOD__ */ 

#ifdef VM_SUPPORT
/* vm */
extern kal_bool aud_vm_init(void);
extern kal_bool aud_vm_startup(void);
extern void aud_vm_main(ilm_struct *ilm_ptr);
extern void aud_vm_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_vm_set_output_device(kal_uint8 device);
extern kal_bool aud_vm_check_valid_id(kal_uint8 vm_id);
extern void aud_vm_play(kal_uint8 file_id, kal_uint8 play_style, kal_uint8 out_device);
extern void aud_vm_stop(void);
extern void aud_vm_get_info_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_record_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_delete_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_abort_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_append_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_rename_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_get_info_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_read_data_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_vm_write_data_ind_hdlr(ilm_struct *ilm_ptr);

#endif /* VM_SUPPORT */ 

extern kal_bool aud_media_init(void);
extern void aud_media_main(ilm_struct *ilm_ptr);
extern void aud_media_record_req_hdlr(ilm_struct *ilm_ptr);
kal_uint8 aud_open_record_file(kal_wchar *file_name, kal_uint8 format);
kal_uint8 aud_close_record_file(void);

extern void aud_media_play_stream_event_callback(MHdl *handle, Media_Event event);
extern kal_uint8 aud_media_play_byte_stream(kal_uint8 *data, kal_uint32 size, kal_uint8 play_style);
extern kal_uint8 aud_media_play_file_stream(
                    kal_wchar *file_name,
                    kal_uint8 play_style,
                    kal_uint8 first_time,
                    kal_bool resume,
                    void* cache_p);
extern kal_bool aud_media_pause_file_stream(kal_uint8 *res);
extern kal_bool aud_media_resume_file_stream(kal_uint8 *res);
extern kal_bool aud_media_process_file_stream(ilm_struct *ilm_ptr);

extern void aud_media_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_close_file_handle(void);
extern void aud_media_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_store_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_restore_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_read_data_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_write_data_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_unfinished_process(void);

extern void aud_media_record_low_stop_cnf_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_record_low_pause_cnf_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_record_low_resume_cnf_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_record_low_error_ind_hdlr(ilm_struct *ilm_ptr);

extern void aud_send_fmr_power_on_req(module_type src_mod_id, kal_uint8 output_path);
extern void aud_send_fmr_power_off_req(module_type src_mod_id);
extern void aud_send_fmr_set_freq_req(module_type src_mod_id, kal_uint16 freq);
extern void aud_send_fmr_mute_req(module_type src_mod_id, kal_uint8 mute);
extern void aud_send_fmr_check_is_valid_stop_cnf(kal_uint8 is_valid);
#if defined(FM_RADIO_WITH_TV)
extern void aud_send_fmr_get_signal_level_cnf(kal_uint16 sig_lvl);
  #else
extern void aud_send_fmr_get_signal_level_cnf(kal_uint8 sig_lvl);
  #endif
extern void aud_send_fmr_evaluate_threshold_req(module_type src_mod_id);

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/* -- added for turn on/off backlight by MMI task -- */
extern void aud_backlight_ctrl_rsp_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_backlight_ctrl_req(module_type dst_mod_id, kal_uint8 on_off, kal_uint8 disable_timer);
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#ifdef __MMI_SUPPORT_LED_SYNC__
/* -- added for turn on/off led by MMI task -- */
extern void aud_led_ctrl_rsp_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_led_ctrl_req(module_type dst_mod_id, kal_uint8 on_off);
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

/* ilm */
extern void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void aud_send_msg(module_type src_id, module_type dst_id, kal_uint16 msg_id, void *local_param_ptr);

extern void aud_send_audio_play_finish_ind(kal_uint8 result);

extern void aud_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length);
extern void aud_send_startup_cnf(kal_uint8 result);
extern void aud_send_set_audio_profile_cnf(kal_uint8 result);
extern void aud_send_set_audio_param_cnf(kal_uint8 result);

/* for aud_api.c, to send message to media task */
extern void aud_send_play_id_req(module_type src_mod_id, void *id_param);
extern void aud_send_stop_id_req(module_type src_mod_id, kal_uint8 audio_id);
extern void aud_send_play_string_req(module_type src_mod_id, void *string_param);
extern void aud_send_stop_string_req(module_type src_mod_id, kal_uint8 src_id);
extern void aud_send_play_file_req(module_type src_mod_id, void *file_param);
extern void aud_send_stop_file_req(module_type src_mod_id, kal_uint8 src_id);
extern void aud_send_record_req(
                module_type src_mod_id,
                kal_wchar *file_name,
                kal_uint8 format,
                kal_uint8 quality,
                kal_bool default_input,
                kal_uint8 input_source,
                kal_uint32 size_limit,
                kal_uint32 time_limit);
extern void aud_send_pause_req(module_type src_mod_id, kal_uint8 src_id);
extern void aud_send_resume_req(module_type src_mod_id, kal_uint8 src_id);
extern void aud_send_stop_record_req(module_type src_mod_id, kal_uint8 src_id);
extern void aud_send_block_req(module_type src_mod_id, kal_uint16 mod_id, kal_uint8 level);
extern void aud_send_set_vibrator_enabled_req(module_type src_mod_id, kal_uint8 enable);
extern void aud_send_set_headset_mode_output_path_req(module_type src_mod_id, kal_uint8 device);
extern void aud_send_store_req(module_type src_mod_id, kal_uint8 src_id);
extern void aud_send_restore_req(module_type src_mod_id, void *file_param);
extern void aud_send_get_spectrum_req(module_type src_mod_id, kal_uint8 *top_p, kal_uint8 *val_p);
extern void aud_send_start_calc_spectrum_req(module_type src_mod_id);
extern void aud_send_stop_calc_spectrum_req(module_type src_mod_id);
extern void aud_send_get_duration_req(module_type src_mod_id,
                               kal_bool default_handle,
                               void *file_name,
                               kal_uint8 *audio_data,
                               kal_uint32 len,
                               kal_uint8 format);
extern void aud_send_get_progress_time_req(module_type src_mod_id);
extern void aud_send_set_progress_time_req(module_type src_mod_id, kal_uint32 progress);
extern void aud_send_check_is_pure_audio_req(module_type src_mod_id, void *file_name);

#ifndef MED_V_NOT_PRESENT
extern void aud_send_start_build_cache_req(module_type src_id, void *local_param_ptr);
extern void aud_send_stop_build_cache_req(module_type src_id);
extern void aud_send_close_build_cache_req(module_type src_id);
extern void aud_send_process_build_cache_req(module_type src_id, void *local_param_ptr);
extern void aud_send_reset_build_cache_vars_req(module_type src_id);
extern void aud_send_build_cache_fail_ind(void);
extern void aud_send_med_v_start_record_req(void);
extern void aud_send_med_v_stop_record_req(void);
extern void aud_send_med_v_pause_record_req(void);
extern void aud_send_med_v_resume_record_req(void);
extern void aud_send_med_v_read_data_ind(kal_uint8 event);
#endif /*MED_V_NOT_PRESENT*/
extern void aud_send_update_duration_ind(kal_uint32 duration);

#ifdef __MED_MMA_MOD__
/* mma */
extern void aud_send_mma_open_req(module_type src_mod_id, kal_int32 param);
extern void aud_send_mma_close_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_play_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_stop_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_pause_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_resume_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_get_audio_info_req(module_type src_mod_id, 
                                     kal_wchar* file_path,
                                     kal_uint8 media_type,
                                     kal_uint8* data,
                                     kal_uint32 data_len,
                                     void *audio_info);
extern void aud_send_mma_get_duration_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_get_current_time_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);

extern void aud_send_mma_set_start_time_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_int32 start_time);
extern void aud_send_mma_set_stop_time_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_int32 stop_time);
extern void aud_send_mma_get_volume_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_set_volume_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 volume);
extern void aud_send_mma_set_rate_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle, kal_int32 rate);
extern void aud_send_mma_set_tempo_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle, kal_int32 tempo);
extern void aud_send_mma_set_pitch_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle, kal_int32 pitch);
extern void aud_send_mma_send_long_msg_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 *buf,
                kal_uint16 len);
extern void aud_send_mma_send_short_msg_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 type,
                kal_uint8 data1,
                kal_uint8 data2);
extern void aud_send_mma_open_device_req(module_type src_mod_id, kal_uint8 media_type);
extern void aud_send_mma_close_device_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_set_channel_volume_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 channel,
                kal_uint8 level);
extern void aud_send_mma_set_program_req(
                module_type src_mod_id,
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 channel,
                kal_uint8 bank,
                kal_uint8 program);
extern void aud_send_mma_set_data_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle, kal_int32 param);
extern void aud_send_mma_write_data_ind_req(module_type src_mod_id, kal_uint8 media_type, kal_int32 handle, kal_bool is_finish);
#endif /* __MED_MMA_MOD__ */ 

#ifdef VM_SUPPORT

extern void aud_send_vm_get_info_cnf(void);
extern void aud_send_vm_record_cnf(kal_uint8 result);
extern void aud_send_vm_play_cnf(kal_uint8 result);
extern void aud_send_vm_stop_cnf(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_vm_abort_cnf(kal_uint8 result);
extern void aud_send_vm_pause_cnf(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_vm_resume_cnf(kal_uint8 result);
extern void aud_send_vm_append_cnf(kal_uint8 result);
extern void aud_send_vm_delete_cnf(kal_uint8 result);
extern void aud_send_vm_rename_cnf(kal_uint8 result);
extern void aud_send_vm_record_finish_ind(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_vm_play_finish_ind(kal_uint8 result);

#endif /* VM_SUPPORT */ 

extern void aud_send_media_record_cnf(kal_uint8 result);
extern void aud_send_media_play_cnf(kal_uint8 result);
extern void aud_send_media_stop_cnf(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_media_pause_cnf(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_media_resume_cnf(kal_uint8 result);
extern void aud_send_media_record_finish_ind(kal_uint8 result);
extern void aud_send_media_play_finish_ind(kal_uint8 result);

/* utility */
extern kal_uint8 aud_audio_out_dev_convert(kal_uint8 speaker_id);
extern kal_uint8 aud_get_res(kal_uint8 result);
extern kal_uint8 aud_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte);
extern int aud_create_full_path_folder(kal_uint16 *filepath);
extern kal_bool aud_is_streaming_type(kal_uint8 format);

extern void aud_fmr_power_on_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_power_off_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_set_freq_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_check_is_valid_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_get_signal_level_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_set_volume(kal_uint8 volume1);
extern void aud_fmr_set_output_device(kal_uint8 device);
extern void aud_fmr_evaluate_threshold_req_hdlr(ilm_struct *ilm_ptr);
extern kal_bool aud_fmr_is_power_on(void);

/* api */
extern void aud_set_result(kal_int32 result);
extern void aud_set_pair_results(kal_int32 result, kal_uint32 value);

/* VR */
#ifdef __MED_VR_MOD__
/* SD */
extern kal_int32 aud_vr_sd_find_word_id(kal_uint16 group_id, kal_uint16 word_id);
extern kal_int32 aud_vr_sd_extract_group_id(kal_uint16 *filename);
extern kal_int32 aud_vr_sd_extract_word_id(kal_uint16 *filename);
extern void aud_vr_sd_scan_tags_in_group_folder(kal_uint16 group_id, kal_uint16 *path);
extern void aud_vr_sd_filter_out_not_exist_tags(kal_uint16 group_id);
extern kal_bool aud_vr_sd_startup(void);
extern kal_int32 aud_vr_sd_init_rcg(void);
extern kal_int32 aud_vr_sd_init_trn(void);
extern void aud_vr_sd_rcg_process(void);
extern void aud_vr_sd_trn_process(void);
extern kal_int32 aud_vr_sd_rcg_voice_in(void);
extern kal_int32 aud_vr_sd_trn_voice_in(kal_uint8 seq_no);
extern kal_int32 aud_vr_sd_sync_db(kal_uint16 group_id, kal_uint16 *id_length_p, kal_uint16 *id_array);
extern kal_bool aud_vr_sd_delete_one_tag(kal_uint16 group_id, kal_uint16 word_id);
extern kal_int32 aud_vr_sd_delete_tag(kal_uint16 group_id, kal_uint16 word_id);
extern kal_int32 aud_vr_sd_add_tag(kal_uint16 group_id, kal_uint16 *cid_array, kal_uint16 cid_length);
extern kal_int32 aud_vr_sd_play_tag(void);

extern void aud_vr_sd_abort(void);

extern kal_bool aud_vr_check_db_folder(kal_uint16 *folder_name, kal_uint8 mode, kal_uint8 lang, kal_uint8 group_id);
extern kal_bool aud_vr_startup(void);
extern void aud_vr_main(ilm_struct *ilm_ptr);
extern void aud_vr_get_version_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_get_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_init_rcg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_init_trn_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_voice_in_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_del_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_check_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_sync_db_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_play_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_get_dir_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_add_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_abort_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_vr_get_version_req(module_type src_mod_id, kal_uint8 mode, kal_uint8 lang);
extern void aud_send_vr_get_param_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_int16 *sim,
                kal_int16 *diff,
                kal_int16 *rej);
extern void aud_send_vr_set_param_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_int16 sim,
                kal_int16 diff,
                kal_int16 rej);
extern void aud_send_vr_init_rcg_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id);
extern void aud_send_vr_init_trn_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id);
extern void aud_send_vr_voice_in_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 seq_no);
extern void aud_send_vr_rcg_result_ind(
                module_type dst_mod_id,
                kal_uint32 session_id,
                kal_int32 result,
                kal_uint16 id_length,
                kal_uint16 *id_array);
extern void aud_send_vr_trn_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_int32 result);
extern void aud_send_vr_del_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id);
extern void aud_send_vr_check_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id);
extern void aud_send_vr_sync_db_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 *id_length_p,
                kal_uint16 *id_array);
extern void aud_send_vr_play_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id,
                kal_uint16 identifier);
extern void aud_send_vr_get_dir_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 *folder_name);
extern void aud_send_vr_add_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 id_length,
                kal_uint16 *id_array);
extern void aud_send_vr_abort_req(module_type src_mod_id);
extern void aud_send_vr_abort_ind(module_type dst_mod_id, kal_uint32 session_id);
#endif /* __MED_VR_MOD__ */ 

#ifdef __MED_VRSI_MOD__

extern void aud_vrsi_startup(void);
extern void aud_vrsi_main(ilm_struct *ilm_ptr);
extern void aud_vrsi_init_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_add_tags_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_start_trn_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_start_rcg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_process_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_play_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_play_tts_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_get_tagnum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_get_taginfo_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_del_tags_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_reset_tags_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_sync_db_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_abort_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_close_req_hdlr(ilm_struct *ilm_ptr);

extern void aud_vrsi_callback(VRSI_Event event);
extern void aud_vrsi_prompt_cnf(void);
extern kal_int32 aud_vrsi_error(void);
extern kal_int32 aud_vrsi_init(void);
extern kal_int32 aud_vrsi_add_tags(void);
extern void aud_vrsi_save_addtags_result(void);
extern kal_int32 aud_vrsi_start_cmd_rcg(void);
extern kal_int32 aud_vrsi_start_cmd_trn(void);
extern kal_int32 aud_vrsi_start_digit_rcg(kal_uint8 lang, kal_uint16 limit);
extern kal_int32 aud_vrsi_start_digit_adapt(kal_uint8 lang);
extern kal_int32 aud_vrsi_play_tag(kal_uint16 tag_id);
extern kal_int32 aud_vrsi_play_tts(kal_uint8 lang);
extern kal_int32 aud_vrsi_get_tagnum(kal_int32 *tagNum);
extern kal_int32 aud_vrsi_get_tag_info(
                    kal_int32 tagNum,
                    const kal_uint16 *pTagID,
                    kal_uint16 **ppTagName,
                    kal_int32 *pTagLong);
extern kal_int32 aud_vrsi_del_tags(kal_int32 tagNum, const kal_uint16 *pTagID);
extern kal_int32 aud_vrsi_reset_tags(void);
extern kal_int32 aud_vrsi_sync_db(
                    kal_uint32 tag_num,
                    kal_uint16 *id_list,
                    kal_uint16 **name_list,
                    kal_uint8 *sync_flag);
extern kal_int32 aud_vrsi_sync_db_by_id(kal_uint32 tag_num, kal_uint16 *id_list, kal_uint8 *sync_flag);
extern void aud_vrsi_abort(void);
extern void aud_vrsi_close(void);

extern void aud_send_vrsi_init_req(module_type src_mod_id);
extern void aud_send_vrsi_add_tags_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 *grammar,
                kal_uint16 tag_num,
                kal_uint16 **name_list,
                kal_int32 *long_list,
                kal_uint8 *is_name_list,
                kal_uint16 *id_list);
extern void aud_send_vrsi_start_cmd_trn_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 *grammar,
                kal_uint16 *tag_name,
                kal_int32 tag_long);
extern void aud_send_vrsi_start_cmd_rcg_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 *grammar);
extern void aud_send_vrsi_start_digit_rcg_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 lang,
                kal_uint16 limit);
extern void aud_send_vrsi_start_digit_adapt_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang);
extern void aud_send_vrsi_play_tag_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 *grammar,
                kal_uint16 tag_id,
                kal_uint8 volume,
                kal_uint8 output_path);
extern void aud_send_vrsi_play_TTS_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint16 *text,
                kal_uint8 volume,
                kal_uint8 output_path,
                kal_uint8 lang);
extern void aud_send_vrsi_get_tag_num_req(module_type src_mod_id, kal_uint8 *grammar, kal_int32 *tag_num);
extern void aud_send_vrsi_get_tag_info_req(
                module_type src_mod_id,
                kal_uint8 *grammar,
                kal_int32 tag_num,
                kal_uint16 *id_list,
                kal_uint16 **name_list,
                kal_int32 *long_list);
extern void aud_send_vrsi_del_tags_req(
                module_type src_mod_id,
                kal_uint8 *grammar,
                kal_int32 tag_num,
                kal_uint16 *id_list);
extern void aud_send_vrsi_reset_tags_req(module_type src_mod_id, kal_uint8 *grammar);
extern void aud_send_vrsi_sync_db_req(
                module_type src_mod_id,
                kal_uint8 *grammar,
                kal_int32 tag_num,
                kal_uint16 *id_list,
                kal_uint16 **name_list,
                kal_uint8 *sync_flag);
extern void aud_send_vrsi_abort_req(module_type src_mod_id, kal_uint32 session_id);
extern void aud_send_vrsi_close_req(module_type src_mod_id);
extern void aud_send_vrsi_process_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 proc_type);
extern void aud_send_vrsi_trn_prompt_req(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 pmp_mode);
extern void aud_send_vrsi_trn_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint16 tag_id);
extern void aud_send_vrsi_rcg_prompt_req(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 pmp_mode);
extern void aud_send_vrsi_rcg_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint16 res_type);
extern void aud_send_vrsi_err_ind(module_type dst_mod_id, kal_uint32 session_id);
extern void aud_send_vrsi_play_tag_finish_ind(module_type dst_mod_id, kal_uint32 session_id);
extern void aud_send_vrsi_play_tts_finish_ind(module_type dst_mod_id, kal_uint32 session_id);

#endif /* __MED_VRSI_MOD__ */ 

#ifdef __MED_CTM_MOD__
extern kal_bool aud_ctm_init(void);
extern kal_bool aud_ctm_set_speech_vol_and_path(kal_uint8 audio_mode);
extern void aud_ctm_main(ilm_struct *ilm_ptr);
extern void aud_send_ctm_open_req(module_type src_mod_id, kal_uint8 ctm_interface, ctm_param_struct *ctm_param);
extern void aud_send_ctm_open_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_close_req(module_type src_mod_id);
extern void aud_send_ctm_close_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_connect_req(module_type src_mod_id);
extern void aud_send_ctm_connect_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_connected_ind(module_type dst_mod_id);
extern void aud_send_ctm_send_text_req(module_type src_mod_id, kal_uint16 num_of_char, void *text);
extern void aud_send_ctm_send_text_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_recv_text_ind(module_type dst_mod_id, kal_uint16 num_of_char, void *text);
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_SND_MOD__
extern kal_bool aud_snd_startup(void);
extern void aud_snd_check_byte_stream_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_check_file_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_play_byte_stream_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_play_file_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_play_event_handler(Media_Handle *handle, Media_Event event);
extern void aud_snd_process_event(ilm_struct *ilm_ptr);
extern void aud_snd_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_set_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_set_output_device(kal_uint8 device);

extern void aud_send_snd_check_byte_stream_format_req(module_type src_mod_id, kal_uint8 *data, kal_uint32 size);
extern void aud_send_snd_check_file_format_req(module_type src_mod_id, kal_wchar *file_name);
extern void aud_send_snd_play_byte_stream_req(
                module_type src_mod_id,
                kal_uint8 *data,
                kal_int32 size,
                kal_int16 repeats,
                kal_uint8 volume,
                kal_uint8 output_path);
extern void aud_send_snd_play_file_req(
                module_type src_mod_id,
                kal_wchar *file_name,
                kal_int16 repeats,
                kal_uint8 volume,
                kal_uint8 output_path);
extern void aud_send_snd_play_finish_ind(module_type dst_mod_id, kal_int32 result);
extern void aud_send_snd_stop_play_req(module_type src_mod_id);
extern void aud_send_snd_set_volume_req(module_type src_mod_id, kal_uint8 volume);
#endif /* __MED_SND_MOD__ */ 

#ifdef __MED_GENERAL_TTS__
extern void aud_send_tts_set_attr_req(module_type src_mod_id, kal_uint32 attr_id, kal_uint32 attr_value);
extern void aud_send_tts_play_req(module_type src_mod_id, void *tts_param);
extern void aud_send_tts_update_info_ind(void *data);
#endif

#if defined(__MED_AUD_AUDIO_EFFECT__)
extern kal_bool aud_post_process_startup(void);
#endif
#if defined(__MED_AUD_TIME_STRETCH__)
extern void aud_stretch_check_stream_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stretch_check_file_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stretch_set_speed_req_hdlr(ilm_struct *ilm_ptr);
extern kal_int32 aud_stretch_set_speed(kal_uint16 speed);
extern void aud_stretch_close_req_hdlr(void);
extern void aud_stretch_close(void);
#endif /* #if defined(__MED_AUD_TIME_STRETCH__) */ 
#if defined(__MED_AUD_REVERB__)
extern void aud_reverb_set_coeff_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_reverb_turn_on_req_hdlr(void);
extern void aud_reverb_turn_off_req_hdlr(void);
#endif /* #if defined(__MED_AUD_REVERB__) */ 
#if defined(__MED_AUD_SURROUND__)
extern void aud_surround_turn_on_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_surround_turn_off_req_hdlr(void);
#endif /*#if defined(__MED_AUD_REVERB__)*/
#if defined(__MED_AUD_EQUALIZER__)
extern void aud_eq_set_magnitude_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_eq_turn_on_req_hdlr(void);
extern void aud_eq_turn_off_req_hdlr(void);
#endif /* #if defined(__MED_AUD_EQUALIZER__) */ 

#ifdef __MED_GENERAL_TTS__
extern void aud_tts_startup(void);
extern void aud_tts_set_attr_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_process_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_resume_req_hdlr(ilm_struct *ilm_ptr);
#endif /*#ifdef __MED_GENERAL_TTS__*/

extern void aud_send_bt_open_codec_req(module_type src_mod_id, bt_a2dp_audio_cap_struct *cfg, 
    kal_uint8 stream_handle, kal_bool immediate, kal_uint32 seq_no);
extern void aud_send_bt_close_codec_req(module_type src_mod_id);
extern void aud_send_bt_close_codec_ind(module_type src_mod_id,
    kal_uint8 stream_handle, kal_uint32 seq_no);
#ifdef __MED_BT_MOD__
extern void aud_send_bt_audio_open_req(
                module_type src_mod_id,
                kal_uint8 profile,
                kal_uint8 mode,
                kal_uint16 connect_id);
extern void aud_send_bt_audio_open_cnf(module_type dst_mod_id, kal_uint8 profile, kal_uint16 result);
extern void aud_send_bt_audio_open_ind(module_type dst_mod_id, kal_uint8 profile);
extern void aud_send_bt_audio_close_req(module_type src_mod_id, kal_uint8 profile);
extern void aud_send_bt_audio_close_cnf(module_type dst_mod_id, kal_uint8 profile, kal_uint16 result);
extern void aud_send_bt_audio_close_ind(module_type dst_mod_id, kal_uint8 profile, kal_uint16 cause);
extern void aud_send_bt_audio_turn_on_req(module_type src_mod_id, kal_uint8 profile);
extern void aud_send_bt_audio_turn_off_req(module_type src_mod_id, kal_uint8 profile);

#ifdef __MED_BT_HFP_MOD__
extern kal_bool aud_bt_hfp_is_audio_path_on(void);
extern void aud_bt_hfp_set_audio_path_on(void);
extern void aud_bt_hfp_set_audio_path_off(void);
extern void aud_bt_hfp_set_audio_path(kal_bool on);
#endif /* __MED_BT_HFP_MOD__ */ 

#ifdef __MED_BT_A2DP_MOD__
#if defined(__BTMTK__)
extern void aud_bt_a2dp_open_codec(kal_int32 audio_format);
extern void aud_bt_a2dp_close_codec_ind(void);
extern void aud_bt_a2dp_close_codec_for_open(void);
extern kal_bool aud_bt_a2dp_is_mute_phone(void);
extern kal_bool aud_bt_a2dp_is_codec_opened(void);
#endif
#endif /* __MED_BT_A2DP_MOD__ */

#endif /* __MED_BT_MOD__ */ 

extern void aud_in_proc_call_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_in_proc_call_req(
                module_type src_mod_id,
                media_in_proc_call_type func,
                kal_uint32 func_arg1,
                void *func_arg2);

#endif /* _AUD_MAIN_H */ /* _AUD_H */

#endif /* MED_NOT_PRESENT */ 

