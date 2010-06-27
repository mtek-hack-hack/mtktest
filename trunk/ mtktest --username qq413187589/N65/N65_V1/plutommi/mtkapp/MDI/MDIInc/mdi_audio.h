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
/*****************************************************************************
 *
 * Filename:
 * ---------
 * mdi_audio.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Audio interfce header file
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MDI_AUDIO_H_
#define _MDI_AUDIO_H_

#ifndef _MDI_DATATYPE_H_
#error "Must include mdi_datatype.h before include this file"
#endif 

typedef enum
{
    MDI_AUD_VOL_0,
    MDI_AUD_VOL_1,
    MDI_AUD_VOL_2,
    MDI_AUD_VOL_3,
    MDI_AUD_VOL_4,
    MDI_AUD_VOL_5,
    MDI_AUD_VOL_6,
    MDI_AUD_VOL_NUM
} MDI_AUD_VOL_ENUM;

typedef enum
{
    MDI_AUD_VOL_EX_0,
    MDI_AUD_VOL_EX_1,
    MDI_AUD_VOL_EX_2,
    MDI_AUD_VOL_EX_3,
    MDI_AUD_VOL_EX_4,
    MDI_AUD_VOL_EX_5,
    MDI_AUD_VOL_EX_6,
    MDI_AUD_VOL_EX_7,
    MDI_AUD_VOL_EX_8,
    MDI_AUD_VOL_EX_9,
    MDI_AUD_VOL_EX_10,
    MDI_AUD_VOL_EX_11,
    MDI_AUD_VOL_EX_12,
    MDI_AUD_VOL_EX_13,
    MDI_AUD_VOL_EX_14,
    MDI_AUD_VOL_EX_15,
    MDI_AUD_VOL_EX_NUM
} MDI_AUD_VOL_EX_ENUM;

/* The enum should be the same as "med_main.h" */
enum
{
    MDI_AUDIO_SUCCESS = 0,          /* 0 */
    MDI_AUDIO_FAIL,                 /* 1 */
    MDI_AUDIO_BUSY,                 /* 2 */
    MDI_AUDIO_DISC_FULL,            /* 3 */
    MDI_AUDIO_OPEN_FILE_FAIL,       /* 4 */
    MDI_AUDIO_END_OF_FILE,          /* 5 */
    MDI_AUDIO_TERMINATED,           /* 6 */
    MDI_AUDIO_BAD_FORMAT,           /* 7 */
    MDI_AUDIO_INVALID_FORMAT,       /* 8 */
    MDI_AUDIO_ERROR,                /* 9 */
    MDI_AUDIO_NO_DISC,              /* 10 */
    MDI_AUDIO_NO_SPACE,             /* 11 */
    MDI_AUDIO_INVALID_HANDLE,       /* 12 */
    MDI_AUDIO_NO_HANDLE,            /* 13 */
    MDI_AUDIO_RESUME,               /* 14 */
    MDI_AUDIO_BLOCKED,              /* 15 */
    MDI_AUDIO_MEM_INSUFFICIENT,     /* 16 */
    MDI_AUDIO_BUFFER_INSUFFICIENT,  /* 17 */
    MDI_AUDIO_FILE_EXIST,           /* 18 */
    MDI_AUDIO_WRITE_PROTECTION,     /* 19 */
    MDI_AUDIO_PARAM_ERROR,          /* 20 */
    /* MP4,AAC */
    MDI_AUDIO_UNSUPPORTED_CHANNEL,  /* 21 */
    MDI_AUDIO_UNSUPPORTED_FREQ,
    MDI_AUDIO_UNSUPPORTED_TYPE,
    MDI_AUDIO_UNSUPPORTED_OPERATION,
    MDI_AUDIO_PARSER_ERROR,
    MDI_AUDIO_VIDEO_ERROR,
    MDI_AUDIO_AUDIO_ERROR,
    MDI_AUDIO_FSAL_ERROR,
    MDI_AUDIO_MP4_PRODUCER_ERROR,
    MDI_AUDIO_MP4_SAMPLEDATA_ERROR,
    MDI_AUDIO_MP4_NO_VIDEO_TRACK,
    MDI_AUDIO_MP4_NO_AUDIO_TRACK,
    /* VR */
    MDI_AUDIO_ID_MISMATCH,          /* 33 */
    MDI_AUDIO_ID_EXIST,
    MDI_AUDIO_TRAINING_CONTINUE,
    MDI_AUDIO_NO_SOUND,
    MDI_AUDIO_TOO_SIMILAR,
    MDI_AUDIO_TOO_DIFFERENT,
    MDI_AUDIO_NO_MATCH,
    MDI_AUDIO_SPEAK_TOO_SHORT,
    MDI_AUDIO_SPEAK_TOO_LONG,
    /* Some value does not mapping from "med_main.h" */
    /* FM Record */
    MDI_AUDIO_STOP_FM_RECORD = 65,  /* 65 */
    /* Audio Post Process */
    MDI_AUDIO_UNSUPPORTED_SPEED,    /* 66 */
    /* BT A2DP */
    MDI_AUDIO_A2DP_CLOSE,
    MDI_AUDIO_A2DP_DISCOVER_SEP_FAIL,
    MDI_AUDIO_A2DP_GET_SEP_CAP_FAIL,
    MDI_AUDIO_A2DP_NO_MATCH_CAP,
    MDI_AUDIO_A2DP_CONFIG_STREAM_FAIL,
    MDI_AUDIO_A2DP_RECONFIG_STREAM_FAIL,
    MDI_AUDIO_A2DP_OPEN_STREAM_FAIL,
    MDI_AUDIO_A2DP_START_STREAM_FAIL,
    MDI_AUDIO_A2DP_PAUSE_STREAM_FAIL,

    /* Decoder */
    MDI_AUDIO_DECODER_NOT_SUPPORT = 94,

    /* The above message should be the same value as "med_main.h" */
    MDI_AUDIO_HFP_SCO_CONNECTED = 200,
    MDI_AUDIO_DRM_PROHIBIT,
    MDI_AUDIO_DRM_TIMEOUT,
    MDI_NO_OF_EVENT
};


typedef enum
{
    MDI_AUDIO_IDLE,
    MDI_AUDIO_PLAY,
    MDI_AUDIO_PLAY_PAUSED,
    MDI_AUDIO_RECORD,
    MDI_AUDIO_RECORD_PAUSED,
    MDI_AUDIO_SPEECH_ON,
    MDI_AUDIO_VRSI_PROCESS,
    MDI_AUDIO_POC_ON,
    MDI_NO_AUDIO_STATE
} MDI_AUDIO_STATE_ENUM;

typedef enum
{
    MDI_AUDIO_PLAY_KT,
    MDI_AUDIO_PLAY_TONE,
    MDI_AUDIO_PLAY_ID,
    MDI_AUDIO_PLAY_STRING,
    MDI_AUDIO_PLAY_FILE,
    MDI_AUDIO_RECORD_FILE,
    MDI_AUDIO_RECORD_FM_RADIO,
    MDI_AUDIO_PLAY_FM_RADIO,
    MDI_AUDIO_RECORD_VR_VOICE,
    MDI_AUDIO_VRSI_PLAY_TTS,
    MDI_AUDIO_VRSI_PLAY_TAG,
    MDI_AUDIO_VRSI_RECORD,
    MDI_AUDIO_POC_ENCODE,
    MDI_AUDIO_POC_DECODE,
    MDI_AUDIO_PLAY_TTS,
    MDI_NO_AUDIO_MODE
} MDI_AUDIO_PLAY_MODE_ENUM;


enum
{
    MDI_FORMAT_NONE = -1,
    MDI_FORMAT_GSM_FR,          /* 0 */
    MDI_FORMAT_GSM_HR,          /* 1 */
    MDI_FORMAT_GSM_EFR,         /* 2 */
    MDI_FORMAT_AMR,             /* 3 */
    MDI_FORMAT_AMR_WB,          /* 4 */
    MDI_FORMAT_DAF,             /* 5 */
    MDI_FORMAT_AAC,             /* 6 */
    MDI_FORMAT_PCM_8K,          /* 7 */
    MDI_FORMAT_PCM_16K,         /* 8 */
    MDI_FORMAT_G711_ALAW,       /* 9 */
    MDI_FORMAT_G711_ULAW,       /* 10 */
    MDI_FORMAT_DVI_ADPCM,       /* 11 */
    MDI_FORMAT_VR,              /* 12 */
    MDI_FORMAT_WAV,             /* 13 */
    MDI_FORMAT_WAV_ALAW,        /* 14 */
    MDI_FORMAT_WAV_ULAW,        /* 15 */
    MDI_FORMAT_WAV_DVI_ADPCM,   /* 16 */
    MDI_FORMAT_SMF,             /* 17 */
    MDI_FORMAT_IMELODY,         /* 18 */
    MDI_FORMAT_SMF_SND,         /* 19 */
    MDI_FORMAT_MMF,             /* 20 */
    MDI_FORMAT_AU,              /*  21 */
    MDI_FORMAT_AIFF,            /*  22 */
    MDI_FORMAT_VRSI,            /*  23 */
    MDI_FORMAT_WMA,             /*  24 */
    MDI_FORMAT_M4A,             /*  25 */
    MDI_FORMAT_3GP,             /* 26 */
    MDI_FORMAT_MP4,             /* 27 */
    MDI_FORMAT_JPG,             /* 28 */
    MDI_FORMAT_GIF,             /* 29 */
    MDI_FORMAT_MJPG,            /* 30 */
    MDI_FORMAT_PNG,             /* 31 */
    MDI_FORMAT_MUSICAM,         /* 32 */
    MDI_NO_OF_FORMAT
};

typedef enum
{
    MDI_BACKGROUND_APP_POC,
    MDI_BACKGROUND_APP_FMR,
    MDI_BACKGROUND_APP_AUDPLY,
    MDI_BACKGROUND_APP_TOTAL
} MDI_BACKGROUND_APP;

typedef enum
{
    MDI_AUDIO_BT_STATE_IDLE,
    MDI_AUDIO_BT_STATE_WAIT_OPEN,
    MDI_AUDIO_BT_STATE_OPEN,
    MDI_AUDIO_BT_STATE_WAIT_CLOSE
} MDI_AUDIO_BT_STATE_ENUM;

typedef enum
{
    MDI_AUDIO_SPEECH_APP_ID_NONE,
    MDI_AUDIO_SPEECH_APP_ID_GSM,
    MDI_AUDIO_SPEECH_APP_ID_WCDMA,
    MDI_AUDIO_SPEECH_APP_ID_SIM2,
    MDI_AUDIO_SPEECH_APP_ID_VOIP,
    MDI_AUDIO_SPEECH_APP_ID_3G324M
} MDI_AUDIO_SPEECH_APP_ID_ENUM;

typedef enum
{
    MDI_AUDIO_REC_QUALITY_LOW,
    MDI_AUDIO_REC_QUALITY_MED,
    MDI_AUDIO_REC_QUALITY_HIGH,
    MDI_AUDIO_REC_QUALITY_BEST
} MDI_AUDIO_REC_QUALITY_ENUM;

#ifdef __GENERAL_TTS__
typedef enum
{
    MDI_TTS_STR_TEXT,		/*regard input as normal text */
	MDI_TTS_STR_PHN_SBL,	/*regard input as phonetic symbol */
    MDI_TTS_STR_CHAR		/*regard input as character set*/
} MDI_AUD_TTS_STR_TYPE;

typedef struct {
    U16 *text_string;
    U16 str_type;	/* String Type */
    U16 lang;	    /* Language */
    U16 app_type;	/* Application Type */
    U16 gander;	    /* Gender */
    U8 volume;	    /* Volume, from 0~6 */
    U8 path;		/* Audio Path */
    U8 pitch;	    /* Audio Pitch, from 0~100 */
    U8 speed;	    /* Audio Speed, from 0~100 */
    mdi_callback callback;
} mdi_audio_tts_struct;
#endif /*__GENERAL_TTS__*/

#define MDI_AUD_MODE_NORMAL        0    /* Normal Mode */
#define MDI_AUD_MODE_HEADSET        1   /* HeadSet (Earphone) Mode */
#define MDI_AUD_MODE_LOUDSPK        2   /* Loudspeaker Mode */
#define MDI_MAX_AUD_MODE_NUM      3

#define MDI_VOLUME_CTN                0 /* MMI can apply to associate volume; call tone attribute */
#define MDI_VOLUME_KEY                1 /* MMI can apply to associate volume; keypad tone attribute */
#define MDI_VOLUME_MIC                2 /* microphone attribute */
#define MDI_VOLUME_FMR                3 /* MMI can apply to FM radio attribute */
#define MDI_VOLUME_SPH                4 /* MMI can apply to associate volume; speech sound attribute */
#define MDI_VOLUME_SID                 5        /* side tone attribute */
#define MDI_VOLUME_MEDIA            6   /* MMI can apply to associate volume; As MP3, Wave,... attribute */
#define MDI_MAX_VOLUME_TYPE         7

#define MDI_MAX_VOLUME_LEVEL            7

#define MDI_DEVICE_SPEAKER            0 /* Tone, Keypad sound to play on audio device. */
#define MDI_DEVICE_MICROPHONE          1        /* Microphone sound to send on audio device. */
#define MDI_DEVICE_SPEAKER2            4        /* earphone, carkit */
#define MDI_DEVICE_LOUDSPEAKER         5        /* loudspeaker for free sound */
#define MDI_DEVICE_SPEAKER_BOTH        6
#define MDI_DEVICE_BT_HEADSET 8 /* used to be OR bitwise with above audio output devices */

#define MDI_AUDIO_PLAY_CRESCENDO    0   /* Play sound for crescendo. */
#define MDI_AUDIO_PLAY_INFINITE     1   /* Play sound for infinite. */
#define MDI_AUDIO_PLAY_ONCE         2   /* Play sound for once. */
#define MDI_AUDIO_PLAY_DESCENDO     3   /* Play sound for descendo. */

#define MDI_INPUT_MIC1  0
#define MDI_INPUT_MIC2  1
#define MDI_INPUT_FMRR  2

/* Audio time stretch */
#define MDI_AUDIO_MAX_SPEED_NUM     5

#define MDI_AUDIO_SPEED_SLOW2    50
#define MDI_AUDIO_SPEED_SLOW1    80
#define MDI_AUDIO_SPEED_NORMAL   100    /* Original Speed */
#define MDI_AUDIO_SPEED_FAST1    125
#define MDI_AUDIO_SPEED_FAST2    160

#define MDI_AUD_VOL_EX(x) ((x) | 0x80)
#define MDI_AUD_PTH_EX(x) (x)


/*
*  TTS defines
*/
#ifdef __GENERAL_TTS__
#define	MDI_TTS_LANG_ENG	0x1;	/*English*/
#define	MDI_TTS_LANG_TWN	0x2;	/*Taiwan-accent Chinese*/
#define	MDI_TTS_LANG_MDN	0x4;	/*Mandarin*/

#define	MDI_TTS_TYPE_GENERAL	0x1;	/*General Purpose TTS*/
#define	MDI_TTS_TYPE_DIC		0x2;	/*Dictionary*/
#define	MDI_TTS_TYPE_NAME		0x4;	/*Name*/
#define	MDI_TTS_TYPE_GPS		0x8;	/*GPS, traffic guiding*/
#define	MDI_TTS_TYPE_WEATHER	0x10;	/*weather report*/
#define	MDI_TTS_TYPE_STOCK		0x20;	/*stock report*/

#define	MDI_TTS_GENDER_MALE	0x1;
#define	MDI_TTS_GENDER_FEMALE	0x2;
#define	MDI_TTS_GENDER_BOY		0x4
#define	MDI_TTS_GENDER_GIRL	0x8;
#endif /*__GENERAL_TTS__*/

/************ function prototype ***************/

extern void mdi_audio_init(void);
extern void mdi_audio_init_event_hdlrs(void);
extern void mdi_audio_start_background_timer(void);

#ifdef VR_ENABLE
extern mdi_result mdi_audio_play_voice_tag(
                    U8 mode,
                    U8 lang,
                    U8 group_id,
                    U16 word_id,
                    mdi_handle *handle_p,
                    mdi_callback handler);
extern mdi_result mdi_audio_start_vr_voice_record(
                    U32 session_id,
                    U8 seq_no,
                    mdi_handle *handle_p,
                    mdi_callback handler);
extern mdi_result mdi_audio_stop_vr_voice_record(void);
extern U32 mdi_audio_vr_rcg_session_id(void);
extern U32 mdi_audio_vr_trn_session_id(void);
extern U16 mdi_audio_vr_rcg_result_id_length(void);
extern U16 *mdi_audio_vr_rcg_result_id_array(void);
extern void mdi_audio_vr_rcg_result_ind(void *inMsg);
extern void mdi_audio_vr_trn_result_ind(void *inMsg);
extern void mdi_audio_vr_abort(void);
#endif /* VR_ENABLE */ 
extern mdi_result mdi_audio_play_id(U16 audio_id, U8 play_style, mdi_handle *handle_p, mdi_callback handler);
extern mdi_result mdi_audio_play_id_with_vol_path(
                    U16 audio_id,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_play_string(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler);
extern mdi_result mdi_audio_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_play_string_portion_with_vol_path(
       			    void *audio_data,
		            U32 len,
		            U8 format,
					U32 start_offset,
					U32 end_offset,
		            U8 play_style,
		            mdi_handle *handle_p,
		            mdi_callback handler,
		            U8 volume,
		            U8 path);
extern mdi_result mdi_audio_play_string_with_vol_path_non_block(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_play_file(void *file_name, U8 play_style, void *cache_p, mdi_callback handler);
extern mdi_result mdi_audio_play_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
extern void mdi_audio_play_text_event_handler(mdi_result result);
extern mdi_result mdi_audio_play_text_with_vol_path(
                    U8 *words,
                    S32 len,
                    S32 msecs,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 
extern mdi_result mdi_audio_store_file(mdi_handle audio_handle);
extern mdi_result mdi_audio_restore_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_stop_id(U16 audio_id);
extern mdi_result mdi_audio_stop_string(void);
extern mdi_result mdi_audio_stop_file(void);
extern mdi_result mdi_audio_stop_all(void);
extern mdi_result mdi_audio_stop_fmr(void);
extern mdi_result mdi_audio_pause(mdi_handle audio_handle, mdi_callback handler);
extern mdi_result mdi_audio_resume(mdi_handle audio_handle, mdi_callback handler);
extern mdi_result mdi_audio_start_record(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler);
extern mdi_result mdi_audio_start_record_with_limit(
                    void *file_name,
                    U8 format,
                    U8 quality,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U32 size_limit,
                    U32 time_limit);
extern mdi_result mdi_audio_stop_record(void);
extern void mdi_audio_resume_background_play(void);
extern void mdi_audio_suspend_background_play(void);
extern void mdi_audio_disable_background_play(void);
extern mdi_result mdi_audio_set_background_handler(U8 level, mdi_bg_callback handler);
extern mdi_result mdi_audio_reset_background_handler(U8 level);
extern void mdi_audio_set_volume(U8 type, U8 volume);
extern void mdi_audio_set_volume_no_apply(U8 type, U8 volume);
extern void mdi_audio_set_mic_volume(void);
//extern void mdi_audio_set_speech_mode(BOOL on);
extern void mdi_audio_set_mute(U8 vol_type, BOOL mute);
extern void mdi_audio_set_pseudo_play_file_callback(mdi_callback callback);
extern U32 mdi_audio_get_midi_size_limit(void);

extern void mdi_audio_bt_init(U8 profile, mdi_bt_callback open_handler, mdi_bt_callback close_handler);
extern U8 mdi_audio_bt_get_stream_status(U8 profile);
extern void mdi_audio_bt_close_stream_ind(void *msg);
extern void mdi_audio_bt_close_stream_cnf(void *msg);
extern void mdi_audio_bt_open_stream_ind(void *msg);
extern void mdi_audio_bt_open_stream_cnf(void *msg);
extern BOOL mdi_audio_bt_open_stream(U8 profile, U16 connect_id);
extern BOOL mdi_audio_bt_close_stream(U8 profile);
extern BOOL mdi_audio_bt_is_stream_open(U8 profile);
extern void mdi_audio_bt_hfp_turn_on(void);
extern void mdi_audio_bt_hfp_turn_off(void);
extern BOOL mdi_audio_bt_is_a2dp_codec_open(void);

extern void mdi_audio_set_headset_mode_output_path(unsigned char device);
extern mdi_result mdi_audio_set_vibrator_enabled(BOOL enable);
extern mdi_state mdi_audio_get_state(void);
extern U8 mdi_audio_get_audio_mode(void);
extern void mdi_audio_set_audio_mode(U8 mode);
extern BOOL mdi_audio_is_background_play_suspended(void);
extern BOOL mdi_audio_is_idle(void);
extern MMI_BOOL mdi_audio_is_playing(U16 audio_mode);
extern BOOL mdi_audio_is_speech_mode(void);
extern mdi_result mdi_audio_start_calc_spectrum(void);
extern mdi_result mdi_audio_stop_calc_spectrum(void);
extern mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p);
extern MMI_BOOL mdi_audio_is_pure_audio(void *file_name);
extern mdi_result mdi_audio_get_duration(void *file_name, U32 *time_p);
extern mdi_result mdi_audio_get_duration_by_string(kal_uint8 *audio_data, U32 len, U8 format, U32 *time_p);
extern mdi_result mdi_audio_get_progress_time(U32 *progress_time_p);
extern mdi_result mdi_audio_set_progress_time(U32 progress);

/*audio build cache*/
extern void mdi_audio_start_build_cache(
                    kal_wchar *filename,
                    U8 *cache_p, 
                    U32 cache_size,
                    U8 *file_buf_p,
                    U32 file_buf_size,
                    U8 *proc_buf_p,
                    U32 proc_buf_size,
                    void (*handler)(void*),
                    U32 *build_cache_progress);
extern void mdi_audio_stop_build_cache(void);
extern void mdi_audio_close_build_cache(void);
extern void mdi_audio_reset_build_cache_variables(void);
extern BOOL mdi_audio_build_cache_get_cache_duration(kal_uint32 *duration_p);
extern BOOL mdi_audio_build_cache_get_total_duration(kal_uint32 *duration_p);

extern void mdi_audio_regisiter_auto_update_duration_handler(void(*handler)(U32 duration));
extern MMI_BOOL mdi_audio_is_duration_need_build_cache(void *filename);


extern mdi_result mdi_audio_play_file_portion_with_vol_path(
                    void *file_name,
                    U32 start_offset,
                    U32 end_offset,
                    U8 play_style,
                    void *cache_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);

extern void mdi_audio_mma_init(void);
extern mdi_handle mdi_audio_mma_open_file(void *file_name, U8 repeats, mdi_mma_callback callback);
extern mdi_handle mdi_audio_mma_open_string(void *audio_data, U32 len, U8 mdi_format, U8 repeats, mdi_mma_callback callback);
extern mdi_result mdi_audio_mma_play(mdi_handle handle);
extern mdi_result mdi_audio_mma_pause(mdi_handle handle);
extern mdi_result mdi_audio_mma_resume(mdi_handle handle);
extern mdi_result mdi_audio_mma_stop(mdi_handle handle);
extern mdi_result mdi_audio_mma_close(mdi_handle handle);
extern kal_bool mdi_audio_mma_is_idle(void);
extern mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, S32 start_time);


extern mdi_handle mdi_audio_mma_open_midi(void *audio_data, U32 len, U8 repeats, mdi_mma_callback handler);
extern mdi_result mdi_audio_mma_close_midi(mdi_handle handle);
extern mdi_result mdi_audio_mma_play_midi(mdi_handle handle);
extern mdi_result mdi_audio_mma_stop_midi(mdi_handle handle);

extern mdi_handle mdi_audio_mma_open_wav(void *audio_data, U32 len, U8 repeats, mdi_mma_callback handler);
extern mdi_result mdi_audio_mma_close_wav(mdi_handle handle);
extern mdi_result mdi_audio_mma_play_wav(mdi_handle handle);
extern mdi_result mdi_audio_mma_stop_wav(mdi_handle handle);

// FM Radio Begin: Added by Tim
// functions in blocking mode
extern void mdi_fmr_power_on_with_path(U8 path, mdi_callback handler);
extern void mdi_fmr_power_off(void);
extern void mdi_fmr_set_freq(U16 freq);
extern void mdi_fmr_mute(U8 mute);

/* functions in non-blocking mode */
void mdi_fmr_check_is_valid_stop(U16 freq, BOOL is_step_up, void (*callback_func) (BOOL is_valid));
extern void mdi_fmr_cancel_checking_is_valid_stop(void);

 #if defined(FM_RADIO_WITH_TV)
void mdi_fmr_get_signal_level(U16 freq, BOOL is_step_up, void (*callback_func) (U16 sig_lvl));
#else
void mdi_fmr_get_signal_level(U16 freq, BOOL is_step_up, void (*callback_func) (U8 sig_lvl));
#endif

extern void mdi_fmr_cancel_getting_signal_level(void);
extern void mdi_fmr_evaluate_threshold(void);

/* FM Radio End: Added by Tim */

/* FM Radio Record Begin */
#if 1   /* FM_RADIO_RECORD */
extern mdi_result mdi_fmr_start_record(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler);
extern void mdi_fmr_record_finish_ind(void *inMsg);
extern mdi_result mdi_audio_stop_fmr_record_only(void);
extern void mdi_fmr_stop_record(void);
extern mdi_result mdi_fmr_pause_record(mdi_callback handler);
extern mdi_result mdi_frm_resume_record(mdi_callback handler);
#endif /* 1 */ 
/* FM Radio Record END */

#ifdef VRSI_ENABLE

extern void mdi_audio_vrsi_trn_prompt_req_hdlr(void *inMsg);
extern void mdi_audio_vrsi_trn_result_ind(void *inMsg);
extern void mdi_audio_vrsi_rcg_prompt_req_hdlr(void *inMsg);
extern void mdi_audio_vrsi_rcg_result_ind(void *inMsg);
extern void mdi_audio_vrsi_err_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_init(mdi_callback handler);
extern U32 mdi_audio_vrsi_new_session_id(void);
extern void mdi_audio_vrsi_stop(U32 session_id);
extern void mdi_audio_vrsi_close(void);
extern void mdi_audio_vrsi_play_tag_finish_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_play_tag(U32 session_id, U8 *grammar, U16 tag_id, U8 volume, U8 output_path);
extern void mdi_audio_vrsi_play_tts_finish_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_play_TTS(U32 session_id, U16 *text, U8 volume, U8 output_path, U8 lang);
extern void mdi_audio_vrsi_register_record(void);
extern void mdi_audio_vrsi_unregister_record(void);

#endif /* VRSI_ENABLE */ 

#if defined(__MMI_POC__)
extern mdi_result mdi_audio_poc_start_encode(mdi_callback handler);
extern mdi_result mdi_audio_poc_stop_encode(void);
extern mdi_result mdi_audio_poc_start_decode(mdi_callback handler);
extern mdi_result mdi_audio_poc_stop_decode(void);
#endif /* defined(__MMI_POC__) */ 

#if defined(BGSND_ENABLE) 
extern MMI_BOOL mdi_audio_snd_is_playing(void);
extern mdi_result mdi_audio_snd_check_string_format(void *audio_data, U32 len);
extern mdi_result mdi_audio_snd_check_file_format(void *file_name);
extern mdi_result mdi_audio_snd_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U16 repeat,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_snd_play_file_with_vol_path(
                    void *file_name,
                    U16 repeat,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern void mdi_audio_snd_play_finish_ind(void *inMsg);
extern mdi_result mdi_audio_snd_stop(void);
extern mdi_result mdi_audio_snd_set_volume(U8 volume);
#endif /* defined(BGSND_ENABLE) */ 

#if defined(AUD_TIME_STRETCH)
extern mdi_result mdi_audio_stretch_check_string_format(void *audio_data, U32 len, U16 format);
extern mdi_result mdi_audio_stretch_check_file_format(void *file_name);
extern mdi_result mdi_audio_stretch_set_speed(U16 speed);
extern void mdi_audio_stretch_close(void);
#endif /* #if defined(AUD_TIME_STRETCH) */

#if defined(AUD_REVERB)
extern mdi_result mdi_audio_reverb_set_coeff(S16 *coeff_table);
extern mdi_result mdi_audio_reverb_turn_on(void);
extern mdi_result mdi_audio_reverb_turn_off(void);
#endif /* #if defined(AUD_REVERB) */

#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
extern mdi_result mdi_audio_surround_turn_on(U8 mode);
extern mdi_result mdi_audio_surround_turn_off(void);
#endif /* #if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP) */

#if defined(AUDIO_EQUALIZER_ENABLE)
extern mdi_result mdi_audio_eq_set_magnitude(S8 *magnitude);
extern mdi_result mdi_audio_eq_turn_on(void);
extern mdi_result mdi_audio_eq_turn_off(void);
#endif /* #if defined(AUDIO_EQUALIZER_ENABLE) */

/* for All apps */
mdi_result mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);
mdi_result mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);
MDI_AUDIO_SPEECH_APP_ID_ENUM mdi_audio_speech_get_app_id(void);

/* for GSM & WCDMA apps */
mdi_result mdi_audio_speech_codec_start(void);
mdi_result mdi_audio_speech_codec_stop(void);

/* for VoIP */
mdi_result mdi_audio_speech_encode_start(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_encode_stop(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_decode_start(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_decode_stop(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_mixer_add(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_mixer_remove(kal_int8 rtp_handle);
mdi_result mdi_audio_speech_dtmf_start(kal_int8 rtp_handle, kal_uint8 code, kal_uint8 type);
mdi_result mdi_audio_speech_dtmf_stop(kal_int8 rtp_handle);

/* General purpose TTS */
#ifdef __GENERAL_TTS__
extern mdi_result mdi_audio_tts_set_attr(U32 attr_id, U32 attr_value);
extern mdi_result mdi_audio_tts_play(mdi_audio_tts_struct tts_param);
extern mdi_result mdi_audio_tts_stop(void);
extern mdi_result mdi_audio_tts_pause(void);
extern mdi_result mdi_audio_tts_resume(void);
#endif /*__GENERAL_TTS__*/

/* Functions that provide MDI to other task */
extern void mdi_audio_blocked_recovery(void);
extern MMI_BOOL mdi_audio_message_dispatcher(void *ilm_ptr);

/* For DRM */
#ifdef __DRM_SUPPORT__
extern void mdi_audio_drm_disable_consume_count(void);
#endif /*__DRM_SUPPORT__*/

// anlog tv audio  Begin: Added by Jonathan
#if defined(ANALOG_TV_SUPPORT)
void mdi_tlg_tv_open_path(void);
void mdi_tlg_tv_close_path( void );
void mdi_tlg_tv_mute( U8 mute );
void  mdi_tlg_tv_set_volume(U8 volume);
void mdi_tlg_tv_set_channel(U8 channel,void (*callback_func)(U8 ret) );
void mdi_tlg_tv_set_channel_cnf( void* inMsg );
void mdi_tlg_tv_end_set_channel(void);
void mdi_tlg_tv_get_valid_channels( U8 channel,void (*callback_func)(U8 ret) );
void mdi_tlg_tv_get_valid_channel_cnf( void* inMsg );
#endif  //ANALOG_TV_SUPPORT


#endif /* _MDI_AUDIO_H_ */ 

