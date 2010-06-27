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
 * med_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes function prototypes of media task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _MED_MAIN_H
#define _MED_MAIN_H

typedef enum
{
    MED_MODE_STREAM = 0,        /* Streaming media mode */
    MED_MODE_FILE,              /* File media mode */
    MED_MODE_ARRAY,             /* Array media mode */
    MED_MODE_BUFFER,            /* Buffer mode, used for camera capture, media task allocate the capture buffer and return the address, release the buffer when camera power off. */
    MED_MODE_EDITOR_FILE,       /* File for video editor, will store the context */
    MED_MODE_PDL_FILE,          /* Progressive DL video file */
    MED_NO_OF_MODE
}
med_mode_enum;

/* this shall be sync with aud_defs.h, backward compatible */
typedef enum
{
    MED_TYPE_NONE = -1,
    MED_TYPE_GSM_FR,        /* 0 */
    MED_TYPE_GSM_HR,        /* 1 */
    MED_TYPE_GSM_EFR,       /* 2 */
    MED_TYPE_AMR,           /* 3 */
    MED_TYPE_AMR_WB,        /* 4 */
    MED_TYPE_DAF,           /* 5 */
    MED_TYPE_AAC,           /* 6 */
    MED_TYPE_PCM_8K,        /* 7 */
    MED_TYPE_PCM_16K,       /* 8 */
    MED_TYPE_G711_ALAW,     /* 9 */
    MED_TYPE_G711_ULAW,     /* 10 */
    MED_TYPE_DVI_ADPCM,     /* 11 */
    MED_TYPE_VR,            /* 12 */
    MED_TYPE_WAV,           /* 13 */
    MED_TYPE_WAV_ALAW,      /* 14 */
    MED_TYPE_WAV_ULAW,      /* 15 */
    MED_TYPE_WAV_DVI_ADPCM, /* 16 */
    MED_TYPE_SMF,           /* 17 */
    MED_TYPE_IMELODY,       /* 18 */
    MED_TYPE_SMF_SND,       /* 19 */
    MED_TYPE_MMF,           /* 20 */
    MED_TYPE_AU,            /* 21 */
    MED_TYPE_AIFF,          /* 22 */
    MED_TYPE_VRSI,          /* 23 */
    MED_TYPE_WMA,           /* 24 */
    MED_TYPE_M4A,           /* 25 */
    MED_TYPE_3GP,           /* 26 */
    MED_TYPE_MP4,           /* 27 */
    MED_TYPE_JPG,           /* 28 */
    MED_TYPE_GIF,           /* 29 */
    MED_TYPE_MJPG,          /* 30 */
    MED_TYPE_PNG,           /* 31 */
    MED_TYPE_MUSICAM,       /* 32 */
    MED_NO_OF_TYPE
}
med_type_enum;

/* this shall be sync with aud_defs.h, backward compatible */
typedef enum
{
    MED_RES_OK = 0,                 /* 0 */
    MED_RES_FAIL,                   /* 1 */
    MED_RES_BUSY,                   /* 2 */
    MED_RES_DISC_FULL,              /* 3 */
    MED_RES_OPEN_FILE_FAIL,         /* 4 */
    MED_RES_END_OF_FILE,            /* 5 */
    MED_RES_TERMINATED,             /* 6 */
    MED_RES_BAD_FORMAT,             /* 7 */
    MED_RES_INVALID_FORMAT,         /* 8 */
    MED_RES_ERROR,                  /* 9 */
    MED_RES_NO_DISC,                /* 10 */
    MED_RES_NOT_ENOUGH_SPACE,       /* 11 */
    MED_RES_INVALID_HANDLE,         /* 12 */
    MED_RES_NO_HANDLE,              /* 13 */
    MED_RES_RESUME,                 /* 14 */
    MED_RES_BLOCKED,                /* 15 */
    MED_RES_MEM_INSUFFICIENT,       /* 16 */
    MED_RES_BUFFER_INSUFFICIENT,    /* 17 */
    MED_RES_FILE_EXIST,             /* 18 */
    MED_RES_WRITE_PROTECTION,       /* 19 */
    MED_RES_PARAM_ERROR,            /* 20 */
    /* MP4,AAC */
    MED_RES_UNSUPPORTED_CHANNEL,    /* 21 */
    MED_RES_UNSUPPORTED_FREQ,
    MED_RES_UNSUPPORTED_TYPE,
    MED_RES_UNSUPPORTED_OPERATION,
    MED_RES_PARSER_ERROR,
    MED_RES_VIDEO_ERROR,
    MED_RES_AUDIO_ERROR,
    MED_RES_FSAL_ERROR,
    MED_RES_MP4_PRODUCER_ERROR,
    MED_RES_MP4_SAMPLEDATA_ERROR,
    MED_RES_MP4_NO_VIDEO_TRACK,
    MED_RES_MP4_NO_AUDIO_TRACK,
    /* VR */
    MED_RES_ID_MISMATCH,            /* 33 */
    MED_RES_ID_EXIST,
    MED_RES_TRAINING_CONTINUE,
    MED_RES_NO_SOUND,
    MED_RES_TOO_SIMILAR,
    MED_RES_TOO_DIFFERENT,
    MED_RES_NO_MATCH,
    MED_RES_SPEAK_TOO_LONG,
    MED_RES_SPEAK_TOO_SHORT,
    /* MP4,AAC */
    MED_RES_AUDIO_END,              /* 42 */
    MED_RES_VIDEO_END,
    MED_RES_VIDEO_IMAGE_TOO_LARGE,
    MED_RES_VIDEO_FILE_TOO_LARGE,
    MED_RES_VIDEO_FRAME_RATE_TOO_HIGH,
    MED_RES_VIDEO_SEEK_PARTIAL_DONE,
    /* VRSI */
    MED_RES_VRSI_OK,                /* 48 */
    MED_RES_VRSI_ERR_UNINITIALIZED,
    MED_RES_VRSI_ERR_BUSY,
    MED_RES_VRSI_ERR_MEM_INSUFFICIENT,
    MED_RES_VRSI_ERR_DATA_ERROR,
    MED_RES_VRSI_ERR_LIBRARY_CORRUPT,
    MED_RES_VRSI_ERR_BAD_GRAMMAR,
    MED_RES_VRSI_ERR_LANG_NOT_SUPPORT,
    MED_RES_VRSI_ERR_NO_MATCH_TAG,
    MED_RES_VRSI_ERR_TTS_TOO_LONG,
    MED_RES_VRSI_ERR_SESSION,
    MED_RES_VRSI_ERR_NO_SOUND,
    MED_RES_VRSI_ERR_CMD_TRN_FAIL,
    MED_RES_VRSI_ERR_CMD_RCG_FAIL,
    MED_RES_VRSI_ERR_DGT_RCG_FAIL,
    MED_RES_VRSI_ERR_DGT_ADP_FAIL,
    MED_RES_VRSI_ERR_UNKNOWN,       /* 64 */
    /* FM Record */
    MED_RES_STOP_FM_RECORD,         /* 65 */
    /* Audio Post Process */
    MED_RES_UNSUPPORTED_SPEED,      /* 66 */
    /* A2DP */
    MED_RES_A2DP_CLOSE,
    MED_RES_A2DP_DISCOVER_SEP_FAIL,
    MED_RES_A2DP_GET_SEP_CAP_FAIL,
    MED_RES_A2DP_NO_MATCH_CAP,
    MED_RES_A2DP_CONFIG_STREAM_FAIL,
    MED_RES_A2DP_RECONFIG_STREAM_FAIL,
    MED_RES_A2DP_OPEN_STREAM_FAIL,
    MED_RES_A2DP_START_STREAM_FAIL,
    MED_RES_A2DP_PAUSE_STREAM_FAIL,  /* 75 */
    /* HFP */
    MED_RES_HFP_CLOSE,
    /* Image */
    MED_RES_IMG_DECODE_TIME_OUT,
    MED_RES_ROOT_DIR_FULL,

    /* Barcode Reader */
    MED_RES_BR_IMAGE_ERROR,         /* 79 */
    MED_RES_BR_MODULE_ERROR,
    MED_RES_BR_OUT_OF_MEMORY,
    MED_RES_BR_OVER_VERSION,
    MED_RES_BR_DECODE_TIMEOUT,
    MED_RES_BR_ERROR_BARCODE_TYPE,

    /* Video - pdl */
    MED_RES_PDL_AUDIO_UNDERFLOW,    /* 85 */
    MED_RES_PDL_VIDEO_UNDERFLOW,         

    /* Streaming */
    MED_RES_STREAM_BEARER_DISCONNECTED,     /* 87 */
    MED_RES_STREAM_INVALID_SDP,    
    MED_RES_STREAM_RTSP_SET_CHANNEL_FAIL,
    MED_RES_STREAM_RTSP_REQUEST_FAIL,
    MED_RES_STREAM_PLAY_FINISH,
    MED_RES_STREAM_BUFFER_UNDERFLOW,
    MED_RES_STREAM_BUFFER_OVERFLOW,
    MED_RES_STREAM_INVALID_RESOLUTION,
    MED_RES_STREAM_INVALID_PARAMETER,    
    MED_RES_STREAM_STOP_TIMEOUT,    

    MED_RES_VDOEDT_ENCODE_FAIL,     
    MED_RES_DECODER_NOT_SUPPORT,    
    MED_RES_REACH_STOP_TIME,
    MED_NO_OF_RES
}
med_result_enum;

typedef enum
{
    MED_NO_TRACK = 0x00,
    MED_AUDIO_TRACK = 0x01,
    MED_VISUAL_TRACK = 0x02,
    MED_BOTH_TRACK = 0x03
}
med_vid_track_enum;

typedef enum
{
    MED_VR_ISD_MODE = 0,
    MED_VR_CSI_MODE,
    MED_VR_PSI_MODE,
    MED_NO_OF_VR_MODE
}
med_vr_mode_enum;

typedef enum
{
    MED_VR_NO_CARE_LANG = 0,
    MED_VR_CHINESE_ENGLISH_LANG,
    MED_VR_CHINESE_LANG,
    MED_VR_ENGLISH_LANG,
    MED_NO_OF_VR_LANG
}
med_vr_lang_enum;

typedef enum
{
    MED_VRSI_TAIWAN_LANG,
    MED_VRSI_CHINA_LANG,
    MED_VRSI_AMERICAN_LANG,
    MED_VRSI_BRITISH_LANG,
    MED_VRSI_INVALID_LANG = 0xff
}
med_vrsi_lang_enum;

typedef enum
{
    MED_VRSI_RECOG_MPR,
    MED_VRSI_RECOG_OK,
    MED_VRSI_DIGIT_RECOG_MPR,
    MED_VRSI_DIGIT_RECOG_OK,
    MED_VRSI_DIGIT_ADAPT_MPR,
    MED_VRSI_DIGIT_ADAPT_OK,
    MED_VRSI_TRAIN_TAG_1ST_MPR,
    MED_VRSI_TRAIN_TAG_2ND_MPR,
    MED_VRSI_TRAIN_TAG_OK,
    MED_VRSI_TTS_OK,
    MED_VRSI_PLAY_TAG_OK,
    MED_VRSI_ERROR
} med_vrsi_event_enum;

typedef enum
{
    MED_VRSI_1ST_TRN_PROMPT,
    MED_VRSI_2ND_TRN_PROMPT,
    MED_VRSI_1ST_DGT_ADP_PROMPT,
    MED_VRSI_2ND_DGT_ADP_PROMPT,
    MED_VRSI_CMD_RCG_PROMPT,
    MED_VRSI_DGT_RCG_PROMPT
} med_vrsi_prompt_mode_enum;

#endif /* _MED_MAIN_H */ 

#endif /* MED_NOT_PRESENT */ 

