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
 * med_global.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global definitions of media task.
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

#include "lcd_Sw_inc.h"

#ifndef _MED_GLOBAL_H
#define _MED_GLOBAL_H

/*======== CONSTANTS ==========*/
#if defined(OV9655)
#define YUV_130_SENSOR
#endif 

#if defined(MT6217) || defined(MT6218B)
#define MT6217_SERIES  1
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6225_SERIES  0
#elif defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define MT6217_SERIES  0
#define MT6219_SERIES  1
#define MT6228_SERIES  0
#define MT6225_SERIES  0
#elif defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  1
#define MT6225_SERIES  0
#elif defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235)
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6225_SERIES  1
#else
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6225_SERIES  0
#endif 

/* for Catcher to inject test messages */
// #define TST_HANDLER
/* for vm logging */
// #define VM_LOG

#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif

#if defined(__MTV_SUPPORT__)
#define __MED_MTV_MOD__
#endif

#ifdef __CTM_SUPPORT__
#define __MED_CTM_MOD__
#endif 

#if defined( __BT_HFG_PROFILE__ )
#define __MED_BT_HFP_MOD__

#if defined(__BT_AUDIO_VIA_SCO__)
#define __MED_BT_AUDIO_VIA_SCO__
#endif

#if defined(__BT_FM_VIA_SCO__)
#define __MED_BT_FM_VIA_SCO__
#endif

#endif /* #if defined( __BT_HFG_PROFILE__ ) */

#if defined(__BT_A2DP_PROFILE__)
#define __MED_BT_A2DP_MOD__
#endif 

#if defined(__MED_BT_HFP_MOD__) || defined(__MED_BT_A2DP_MOD__)
#define __MED_BT_MOD__
#endif 

#if defined(PLUTO_MMI)
#define __MMI_SUPPORT_BACKLIGHT_SYNC__
#define __MMI_SUPPORT_LED_SYNC__
#define __16_LEVEL_AUDIO_VOLUME__
#endif /* defined(PLUTO_MMI) */ 

#if defined(__POC__)
#define __MED_POC_MOD__
#endif 

#if !defined(MT6205B) && !defined(MT6208) && !defined(MT6223)
#define __RICH_AUDIO_PROFILE__  /* (1)Spectrum (2)Build Cache, (3)ID3 Parser */
#endif

#if !defined(MT6205B) && !defined(MT6208) && !defined(MT6223) && !defined(MT6223P)
#define __MED_MMA_JAVA_CTRL__ /* Advance MMA control */
#endif

#if !defined(MT6205B) && !defined(MT6208)
#define AMR_DECODE
#endif /* !defined(MT6205B) && !defined(MT6208) */ 

#if defined(MED_LOW) || defined(MED_MODEM)
#define SLIM_AUDIO_PROFILE
#endif 

#if defined(PURE_AUDIO_SUPPORT)
#define MED_PURE_AUDIO
#endif

#if defined (ISP_SUPPORT)
#define __MED_CAM_MOD__

#ifdef WEBCAM_SUPPORT
#define __MED_WEBCAM_MOD__
#endif 

#if defined(AF_SUPPORT)
#define __CAM_AUTO_FOCUS__
#endif 
#endif /* defined (ISP_SUPPORT) */ 

#if defined(TV_OUT_SUPPORT)
#define __MED_TVO_MOD__
#endif 

#if defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE)
#define __MED_IMG_MOD__
#endif 

#if defined (MP4_CODEC) 
    #define __MED_VID_MOD__

    #if defined (ISP_SUPPORT)
        #define __MED_VID_ENC_MOD__

        #if defined(VDOEDT_SUPPORT)
            #define __MED_VID_EDT_MOD__
        #endif        
    #endif

    #ifdef PGDL_SUPPORT
        #define __MED_VID_PDL_MOD__
    #endif 
    
#endif 


#if defined (MJPG_SUPPORT) 
    #define __MED_MJPG_MOD__ 
    
    #if defined (ISP_SUPPORT)
        #define __MED_MJPG_ENC_MOD__
    #endif 
#endif 

#if defined (DSP_WT_SYN)
#define __MED_MMA_MOD__
#endif 

#if defined (FM_RADIO_ENABLE)
#define __MED_FMR_MOD__
#endif 

#if defined (ANALOG_TV_SUPPORT)
#define __MED_TLG_TV_MOD__
#endif

#if defined(VR_ENABLE)
#define __MED_VR_MOD__
#endif 

#if defined(VRSI_ENABLE)
#define __MED_VRSI_MOD__
#endif 

#if defined(BGSND_ENABLE) 
#define __MED_SND_MOD__
#endif 

#if defined(AUD_TIME_STRETCH)
#define __MED_AUD_TIME_STRETCH__
#endif

#if defined(AUD_REVERB)
#define __MED_AUD_REVERB__
#endif

#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
#define __MED_AUD_SURROUND__
#endif

#if defined(AUDIO_EQUALIZER_ENABLE)
#define __MED_AUD_EQUALIZER__
#endif

/* Either turn on (1)time stretch (2)reverb (3)3D surround (4)equalizer */
#if defined(AUD_TIME_STRETCH) || defined(AUD_REVERB) || defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP) || defined(AUDIO_EQUALIZER_ENABLE)
#define __MED_AUD_AUDIO_EFFECT__
#endif

#ifdef DEDI_AMR_REC
#define DEDI_AMR_REC_BUFFER
#endif 

#if defined (__POC__) || defined (STREAM_SUPPORT) || defined (__VOIP__)
#define __MED_RTP_MOD__
#endif 

#if defined(STREAM_SUPPORT)
#define __MED_STREAM_MOD__
#endif 

#if defined(__GENERAL_TTS__)
#define __MED_GENERAL_TTS__
#endif

#define SET_VOLUME_WHEN_PLAY

#define  AUD_IDLE  0
#define  AUD_VM_IDLE                   0
#define  AUD_VM_RECORD                 1
#define  AUD_VM_RECORD_PAUSED          4
#define  AUD_VM_PLAY                      5
#define  AUD_VM_PLAY_PAUSED            6
#define  AUD_VM_PLAY_FINISH            7

/* audio state */
#define  AUD_MEDIA_IDLE             0
#define  AUD_MEDIA_PLAY             30
#define  AUD_MEDIA_PLAY_FINISH      31
#define  AUD_MEDIA_PLAY_PAUSED      32
#define  AUD_MEDIA_RECORD             33
#define  AUD_MEDIA_RECORD_PAUSED      34
#define  AUD_MEDIA_SEEK_PAUSED      35

#define  AUD_MEDIA_UNDERFLOW        36
#define  AUD_MEDIA_UNDERFLOW_PAUSE  37
#define  AUD_MEDIA_WRITE_DATA_PAUSE 38

/* audio post process state */
#define  AUD_EFFECT_UNSET     0 /* Parameter not set */
#define  AUD_EFFECT_OFF    1
#define  AUD_EFFECT_ON        2
//#define  AUD_EFFECT_INT       3 /* Interrupt */

/* camera state */
#define CAM_IDLE        0
#define CAM_READY      1
#define CAM_START_PREVIEW      2
#define CAM_PREVIEW      3
#define CAM_POWER_UP     4
#define CAM_CAPTURE      5
#define CAM_CAPTURE_BARCODE 6

/* image state */
#define IMG_IDLE        0
#define IMG_JPG_DECODE      1
#define IMG_JPG_ENCODE      2
#define IMG_GIF_DECODE       3
#define IMG_GIF_V2_DECODE 4
#define IMG_PNG_DECODE     5

/* video state */
#define VID_IDLE                        0
#define VID_PREVIEW                     1
#define VID_RECORD                      2
#define VID_RECORD_FINISH               3
#define VID_RECORD_PAUSED               4
#define VID_OPEN_FILE                   5
#define VID_FILE_READY                  6
#define VID_PLAY_INIT                   7
#define VID_PLAY                        8
#define VID_AUDIO_PLAY_FINISH           9
#define VID_AUDIO_PLAY_ERROR            10
#define VID_VISUAL_PLAY_FINISH          11
#define VID_PLAY_PAUSED                 12
#define VID_FILE_MERGE                  13
#define VID_SEEK                        14
#define VID_GET_IFRAME                  15
#define VID_PLAY_STOP_VISUAL            16
#define VID_RECORD_STOP_VISUAL          17
#define VID_DELAY_OPEN                  18
#define VID_RECORD_ABORTING             19
#define VID_PLAY_ABORTING               20
#define VID_START_PREVIEW               21
#define VID_FILE_MERGE_STOPPING         22
#define VID_PDL_META_BUFFERING          23
#define VID_VIDEO_PLAY_UNDERFLOW        24
#define VID_PLAY_REACH_STOP_TIME        25
#define VID_EDITOR_FILE_MERGE           26
#define VID_EDITOR_MERGE_STOPPING       27
#define VID_RECORD_UPDATE_BLT_PAUSED    28

#define VID_AUD_IDLE              0
#define VID_AUD_PLAY_NORMAL       1
#define VID_AUD_PLAY_HIGH_SPEED   2
#define VID_AUD_PLAY_DUMMY        3
#define VID_AUD_RECORD            4
#define VID_AUD_RECORD_PAUSED     5
#define VID_AUD_PLAY_UNDERFLOW    6

/* Web camera state */
#define WEBCAM_IDLE             0
#define WEBCAM_START_PREVIEW    1
#define WEBCAM_PREVIEW          2
#define WEBCAM_CAPTURE          3
#define WEBCAM_PAUSING          4
#define WEBCAM_PAUSED           5
#define WEBCAM_STOPPING         6

/* TV output state */
#define TVO_IDLE        0
#define TVO_DETECTION  1
#define TVO_READY      2
#define TVO_UPDATE      3

#define INVALID_VM_ID      255
#define MAX_FILE_NAME_LEN  261
#define MAX_VM_LOG_LEN  (200*1024)
#define IMY_DEFAULT_INSTRUMENT   74     /* Flute */

/* audio ring buffer */
#ifdef SLIM_AUDIO_PROFILE
#define AUD_RING_BUFFER_LEN     (1*1024)
#else /* SLIM_AUDIO_PROFILE */ 
#define AUD_RING_BUFFER_LEN     (8*1024)
#define MJPG_AUDIO_CHUNK_SIZE    (AUD_RING_BUFFER_LEN*2)
#endif /* SLIM_AUDIO_PROFILE */ 

/* Memory usage for audio new architecture */
#if defined(LOW_COST_SUPPORT)
#define AUD_PROC_MEM_SIZE  (0)  /* Use Control Buffer For FSAL Buffer */
#define AUD_PROC_BUF_SIZE  (512)
#else /* defined(LOW_COST_SUPPORT) */ 
#define AUD_PROC_MEM_SIZE  (0)       /* Use Static Memory For FSAL Buffer to avoid External memory fragment */
#define AUD_PROC_BUF_SIZE  (1024)
#define AUD_PROC_USE_EXT_MEM
#endif /* defined(LOW_COST_SUPPORT) */ 

#if defined(TV_OUT_SUPPORT)
#define MAX_TVO_BUFFER_SIZE   (0)        /* 512x384x2x2 - Make sure sync with MDI_TV's buffer size */
#else 
#define MAX_TVO_BUFFER_SIZE   (0)
#endif 

#if defined(__MMI_MAINLCD_240X320__) && defined(M3D_MMI_SUPPORT)
#define M3D_PARSE_BUFFER_SIZE   (100*1024)        /* Because Opengl and OOB will occupy the memory according to the width/height, we enlarge the media memory buffer when the LCD width/height is 240/320       */
#else 
#define M3D_PARSE_BUFFER_SIZE   (0)
#endif 

#if defined(WEBCAM_SUPPORT)
    #define MAX_WEBCAM_BUFFER_SIZE      (145*1024)       /* (0xC000+12)*3 - Make sure sync with webcam */
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define WEBCAM_JPEG_BUFFER_SIZE (640*480)   
    #endif
#else /* defined(WEBCAM_SUPPORT) */
    #define MAX_WEBCAM_BUFFER_SIZE      (0)
    #define WEBCAM_JPEG_BUFFER_SIZE     (0)
#endif /* defined(WEBCAM_SUPPORT) */

#ifdef JPG_DECODE
#if MT6225_SERIES
#define MAX_IMG_DEC_INT_MEM_SIZE   (45*1024)   /* to support zoom */      /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (4096)       /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
    #if defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223)
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
    #elif defined(YUV_130_SENSOR)
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (1280*1024*3/2)   /* need more due to camera preview enhancement */
    #else
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (640*480*3/2)   /* need more due to camera preview enhancement */
    #endif
#elif MT6217_SERIES
#define MAX_IMG_DEC_INT_MEM_SIZE   (40320)   /* to support zoom */      /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (4096)       /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#elif MT6219_SERIES
#define MAX_IMG_DEC_INT_MEM_SIZE   (150*1024)   /* to support zoom */   /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (4096)       /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#else /* MT6228, MT6229, ... */
#define MAX_IMG_DEC_INT_MEM_SIZE   (64*1024)     /* to support zoom */  /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (150*1024)   /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#endif 
#else /* JPG_DECODE */ 
#define MAX_IMG_DEC_INT_MEM_SIZE   (0)  /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (0)  /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (0)       /* Buffer size for multi-run JPG decode. */
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#endif /* JPG_DECODE */ 

#ifdef JPG_ENCODE
#if MT6225_SERIES
#define MAX_IMG_ENC_INT_MEM_SIZE   (3112)  /* 640x480 */       /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (0)  /* External encode memory size for hardware engine buffer */
    #if defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223)
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (0)
    #elif defined(YUV_130_SENSOR)
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (150*1024)        /* File buffer size for JPG encode. */
    #else
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (100*1024)        /* File buffer size for JPG encode. */
    #endif
#elif MT6219_SERIES
#define MAX_IMG_ENC_INT_MEM_SIZE   (49664)  /* 640x480 */       /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (0)  /* External encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_FILE_BUFFER_LEN   (150*1024)        /* File buffer size for JPG encode. */
#else /* MT6228, MT6229, ... */
#define MAX_IMG_ENC_INT_MEM_SIZE   (0)  /* 176x220 */   /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (41984)      /* External encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_FILE_BUFFER_LEN   (200*1024)        /* File buffer size for JPG encode. */
#endif /* MT6219_SERIES */ 
#else /* JPG_ENCODE */ 
#define MAX_IMG_ENC_INT_MEM_SIZE   (0)  /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (0)  /* External encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_FILE_BUFFER_LEN   (0)       /* File buffer size for JPG encode. */
#endif /* JPG_ENCODE */

#define MED_INT_STACK_MEM_SIZE 2800

#ifdef MP4_CODEC
    #if MT6219_SERIES

        #ifdef __TEARING_REDUCTION_FB_IN_INTSRAM__
            /* internal memory - 5K video encode image datapath, 15K Jpeg encode */
            #define MAX_VID_DEC_INT_MEM_SIZE   (5*1024)           /* Internal decode memory size for hardware engine buffer, 
                                                                     enlarge this to support video decode+jpeg encode at QVGA LCD size */
            #define MAX_VID_DEC_EXT_MEM_SIZE   ((235+115)*1024)   /* External decode memory size for hardware engine buffer */
        #else /* __TEARING_REDUCTION_FB_IN_INTSRAM__ */
            #define MAX_VID_DEC_INT_MEM_SIZE   (115*1024)   /* Internal decode memory size for hardware engine buffer, 
                                                               enlarge this to support video decode+jpeg encode at QVGA LCD size */
            #define MAX_VID_DEC_EXT_MEM_SIZE   ((235+15)*1024)   /* External decode memory size for hardware engine buffer + jpeg encode hardware buffer */
        #endif /* __TEARING_REDUCTION_FB_IN_INTSRAM__ */

        #define MAX_VID_ENC_INT_MEM_SIZE   (158*1024)   /* Internal encode memory size for hardware engine buffer */
        #define MAX_VID_ENC_EXT_MEM_SIZE   (500*1024)   /* External encode memory size for hardware engine buffer */

    #else /* MT6219_SERIES */ /* MT6228, MT6229, ... */
        #define MAX_VID_DEC_INT_MEM_SIZE   (45*1024)    /* Internal decode memory size for hardware engine buffer */
        #define MAX_VID_DEC_EXT_MEM_SIZE   ((1510+150)*1024)    /* External decode memory size for hardware engine buffer */

        #define MAX_VID_ENC_INT_MEM_SIZE   (4424)       /* Internal encode memory size for hardware engine buffer */
        #define MAX_VID_ENC_EXT_MEM_SIZE   (1500*1024)  /* External encode memory size for hardware engine buffer */
    #endif /* MT6219_SERIES */ 
    
#else /* MP4_CODEC */ 

    #define MAX_VID_DEC_INT_MEM_SIZE   (0)  /* Internal decode memory size for hardware engine buffer */
    #define MAX_VID_DEC_EXT_MEM_SIZE   (0)  /* External decode memory size for hardware engine buffer */

    #if defined(MT6225) || defined(MT6235) 
    
        /* EXTERNAL MEMORY */
        /********************************************************
         * frame buffer :        176 x 144 x 2 = 50688
         * jpg file buffer    :  70 x 1024 = 71680    
         ********************************************************/
        #define MAX_VID_ENC_INT_MEM_SIZE   (15 * 1024)    /* this will not be the upper bound */
        
        /* INTERNAL MEMORY */
        /********************************************************
         * vid drv working buffer :  176 x 8(line) x 3 = 4224 
         * sw jpg working buffer : 3 x 1024 = 3072 
         * sw encode y buffer :  176 x 144 = 25344        
         * sw encode u buffer :  176 x 144 / 4 = 6336                
         * sw encode v buffer :  176 x 144 / 4 = 6336            
         ********************************************************/
        #define MAX_VID_ENC_EXT_MEM_SIZE   (45 * 1024)   
        
    #else /* defined(MT6225) || defined(MT6235) */
        #define MAX_VID_ENC_INT_MEM_SIZE   (0)          /* Internal encode memory size for hardware engine buffer */
        #define MAX_VID_ENC_EXT_MEM_SIZE   (0)          /* External encode memory size for hardware engine buffer */
    #endif /* defined(MT6225) || defined(MT6235)  */

#endif /* MP4_CODEC */ 

/* video editor */
#ifdef MT6228_SERIES
    #define MAX_VID_EDT_INT_MEM_SIZE   (45 * 1024)      /* Internal decode/encode memory size */
    #define MAX_VID_EDT_EXT_MEM_SIZE   (1500 * 1024)    /* External decode/encode memory size */
#else /* MT6228_SERIES */
    #define MAX_VID_EDT_INT_MEM_SIZE   (0)              /* Internal decode/encode memory size */
    #define MAX_VID_EDT_EXT_MEM_SIZE   (0)              /* External decode/encode memory size */
#endif /* MT6228_SERIES */

#if defined(VRSI_ENABLE)
#define VRSI_MEM_SIZE (0) /* Share external memory with MED_EXT_MEM_SIZE */
#define VRSI_MEM_CHECK_SIZE (400*1024)
#else 
#define VRSI_MEM_SIZE (0)
#endif 

#define MEM_OVERHEAD  256

#ifdef ISP_SUPPORT

   /* audio melody buffer length */
#define AUD_MELODY_BUFFER_LEN     (100*1024)    /* 100K */
#if defined(MT6225) || defined(MT6235) 
    #if defined(YUV_130_SENSOR)
        #define MAX_CAM_FILE_BUFFER_LEN   (650*1024)    /* 500KB for 640x480 */
    #else
        #define MAX_CAM_FILE_BUFFER_LEN   (300*1024)    /* 500KB for 640x480 */
    #endif
#define MAX_CAM_CAP_INT_MEM_SIZE   (45*1024)   /* 1600x1200 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#elif ( defined(MT6226) || defined(MT6226D) )
#define MAX_CAM_FILE_BUFFER_LEN   (500*1024)    /* 500KB for 640x480 */
#define MAX_CAM_CAP_INT_MEM_SIZE   (128*1024)   /* 1600x1200 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#elif ( defined(MT6219) || defined(MT6226M)  )
#define MAX_CAM_FILE_BUFFER_LEN   (750*1024)    /* 750KB for 1280x1024 */
#define MAX_CAM_CAP_INT_MEM_SIZE   (128*1024)   /* 1600x1200 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#elif (defined(MT6227)|| defined(MT6227D))
#define MAX_CAM_FILE_BUFFER_LEN   (1000*1024)   /* 1000KB for 1600x1200 */
#define MAX_CAM_CAP_INT_MEM_SIZE   (128*1024)   /* 1600x1200 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#elif (defined(MT6238))
#define MAX_CAM_FILE_BUFFER_LEN   (1536*1024)   /* 1536KB for 1600x1200 */
#define MAX_CAM_CAP_INT_MEM_SIZE   (94*1024)   /* 1600x1200 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#else /* MT6228, MT6229, ... */
#define MAX_CAM_FILE_BUFFER_LEN   (1536*1024)   /* 1536KB for 1600x1200 */
#define MAX_CAM_CAP_INT_MEM_SIZE   (126*1024)   /* 2048x1536 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#endif 
#ifdef MP4_CODEC
#if MT6219_SERIES
#define MED_INT_MEM_SIZE   (MAX_VID_ENC_INT_MEM_SIZE+MEM_OVERHEAD)
#define MED_EXT_MEM_SIZE   (MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE+VRSI_MEM_SIZE+AUD_PROC_MEM_SIZE+MEM_OVERHEAD+M3D_PARSE_BUFFER_SIZE)
#define MAX_PROG_JPG_DEC_EXT_MEM_SIZE   (MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE-AUD_MELODY_BUFFER_LEN-MAX_IMG_DEC_FILE_BUFFER_LEN)
#else /* MT6219_SERIES */ /* MT6228, MT6229, ... */
#define MED_INT_MEM_SIZE   (MAX_CAM_CAP_INT_MEM_SIZE+MEM_OVERHEAD)
#define MED_EXT_MEM_SIZE   (MAX_IMG_ENC_EXT_MEM_SIZE+MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE+MAX_IMG_ENC_FILE_BUFFER_LEN+MAX_TVO_BUFFER_SIZE+VRSI_MEM_SIZE+AUD_PROC_MEM_SIZE+MEM_OVERHEAD+150*1024+M3D_PARSE_BUFFER_SIZE)
#define MAX_PROG_JPG_DEC_EXT_MEM_SIZE   (MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE-AUD_MELODY_BUFFER_LEN-MAX_IMG_DEC_FILE_BUFFER_LEN)
#endif /* MT6219_SERIES */ 
#else /* MP4_CODEC */ 

#if MAX_IMG_DEC_INT_MEM_SIZE > MAX_CAM_CAP_INT_MEM_SIZE
#define MED_INT_MEM_SIZE   (MAX_IMG_DEC_INT_MEM_SIZE+MEM_OVERHEAD)
#else
#define MED_INT_MEM_SIZE   (MAX_CAM_CAP_INT_MEM_SIZE+MEM_OVERHEAD)
#endif

#define MED_EXT_MEM_SIZE   (MAX_IMG_ENC_FILE_BUFFER_LEN+MAX_SW_JPG_YUV_BUFFER_SIZE+MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE+VRSI_MEM_SIZE+AUD_PROC_MEM_SIZE+MEM_OVERHEAD+M3D_PARSE_BUFFER_SIZE)
#define MAX_PROG_JPG_DEC_EXT_MEM_SIZE   (MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE-AUD_MELODY_BUFFER_LEN-MAX_IMG_DEC_FILE_BUFFER_LEN)
#endif /* MP4_CODEC */ 

#else /* no CAMERA_MODULE nor ISP */

#define MAX_CAM_FILE_BUFFER_LEN   (0)   /* Image file buffer size for camera capture */
#ifdef SLIM_AUDIO_PROFILE
#define AUD_MELODY_BUFFER_LEN     (512) /* 100KB */
#else 
#define AUD_MELODY_BUFFER_LEN     (100*1024)    /* 100KB */
#endif 
   /* internal memory size */
#if defined(MMS_SUPPORT) && defined(JPG_ENCODE)
#if MAX_IMG_ENC_INT_MEM_SIZE > MAX_IMG_DEC_INT_MEM_SIZE
#define MED_INT_MEM_SIZE   (MAX_IMG_ENC_INT_MEM_SIZE+MEM_OVERHEAD)
#else 
#define MED_INT_MEM_SIZE   (MAX_IMG_DEC_INT_MEM_SIZE+MEM_OVERHEAD)
#endif 
#elif (defined(DEDI_AMR_REC_BUFFER) && (MAX_IMG_DEC_INT_MEM_SIZE < 6108))
#define MED_INT_MEM_SIZE   (6108+MEM_OVERHEAD)
#else 
#define MED_INT_MEM_SIZE   (MAX_IMG_DEC_INT_MEM_SIZE+MEM_OVERHEAD)
#endif 
   /* external memory size */
#if defined(MMS_SUPPORT) && defined(JPG_ENCODE)
#define MED_EXT_MEM_SIZE   (750*1024+MEM_OVERHEAD+M3D_PARSE_BUFFER_SIZE)
#else 
#define MED_EXT_MEM_SIZE   (MAX_IMG_DEC_EXT_MEM_SIZE+MAX_IMG_DEC_FILE_BUFFER_LEN+AUD_MELODY_BUFFER_LEN+VRSI_MEM_SIZE+AUD_PROC_MEM_SIZE+MEM_OVERHEAD+M3D_PARSE_BUFFER_SIZE)
#endif 

#define MAX_PROG_JPG_DEC_EXT_MEM_SIZE   (MAX_IMG_DEC_EXT_MEM_SIZE+VRSI_MEM_SIZE)

#endif 

/* VRSI share external memory with camera. If external memory is less, redefine it. */
#if defined(VRSI_ENABLE)
#if ( MED_EXT_MEM_SIZE < VRSI_MEM_CHECK_SIZE )
#undef MED_EXT_MEM_SIZE
#define MED_EXT_MEM_SIZE VRSI_MEM_CHECK_SIZE
#endif /* #if ( MED_EXT_MEM_SIZE < VRSI_MEM_CHECK_SIZE ) */
#endif /* #if defined(VRSI_ENABLE) */

/* SWFlash check memory */
#if defined(SWFLASH_NEOMTEL)
#define SWFLASH_MEM_SIZE ((1000*1024)/*engine 600k + material 301k */+(LCD_WIDTH * LCD_HEIGHT* 2))
#if ( MED_EXT_MEM_SIZE < SWFLASH_MEM_SIZE )
#undef MED_EXT_MEM_SIZE
#define MED_EXT_MEM_SIZE (SWFLASH_MEM_SIZE+MEM_OVERHEAD)
#endif /* #if ( MED_EXT_MEM_SIZE < VRSI_MEM_CHECK_SIZE ) */
#endif


/*==== MACROS ========*/

#ifdef PRODUCTION_RELEASE
#define MED_FUNC_ENTRY(X)
#define MED_MEM_INFO(v,w,x,y,z)
#define MED_FREE_MEM_INFO(x,y,z)
#else /* PRODUCTION_RELEASE */ 
#define __AUD_TRACE_ON__
#define __CAM_TRACE_ON__
#define __IMG_TRACE_ON__
#define __VID_TRACE_ON__
#define __CTM_TRACE_ON__
#define __WEBCAM_TRACE_ON__
#define __TVO_TRACE_ON__
#define __BT_A2DP_TRACE_ON__
#define __BT_HFP_TRACE_ON__
#define __RTP_TRACE_ON__
#define __STREAM_TRACE_ON__
#define __MTV_TRACE_ON__
#define __VCALL_TRACE_ON__

#define MED_FUNC_ENTRY(X)    kal_trace(TRACE_FUNC, X);
#define MED_MEM_INFO(v,w,x,y,z)    kal_trace(TRACE_INFO, MEM_INFO, v, w, x, y, z);
#define MED_FREE_MEM_INFO(x,y,z)   kal_trace(TRACE_INFO, FREE_MEM_INFO, x, y, z);
#endif /* PRODUCTION_RELEASE */ 

#ifdef __AUD_TRACE_ON__
#define AUD_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_FUNC_ENTRY3(F, x, y, z)    kal_trace(TRACE_GROUP_1, F, x, y, z);
#define AUD_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_STATE, s);
#define AUD_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_CHECK_VALUE, x, y, z);
#define AUD_TRACE_VOLUME(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_CHECK_VOLUME, x, y, z);
#define AUD_TRACE_PATH(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_CHECK_PATH, x, y, z);
#define AUD_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_1, AUD_WAIT_EVT_TRC, x, y);
#define AUD_SET_EVT(x,y)        kal_trace(TRACE_GROUP_1, AUD_SET_EVT_TRC, x, y);
#define AUD_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, AUD_RESULT, x, y, z);
#else /* __AUD_TRACE_ON__ */ 
#define AUD_FUNC_ENTRY(X)
#define AUD_FUNC_ENTRY1(F, x)
#define AUD_FUNC_ENTRY2(F, x, y)
#define AUD_FUNC_ENTRY3(F, x, y, z)
#define AUD_STATE_TRACE(s)
#define AUD_VALUE_TRACE(x,y,z)
#define AUD_TRACE_VOLUME(x,y,z)
#define AUD_TRACE_PATH(x,y,z)
#define AUD_WAIT_EVT(x,y)
#define AUD_SET_EVT(x,y)
#define AUD_RESULT_TRACE(x,y,z)
#endif /* __AUD_TRACE_ON__ */ 

#ifdef __CAM_TRACE_ON__
#define CAM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_2, X);
#define CAM_STATE_TRACE(s)    kal_trace(TRACE_STATE, CAM_STATE, s);
#define CAM_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_2, CAM_CHECK_VALUE, x, y, z);
#define CAM_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_2, CAM_WAIT_EVT_TRC, x, y);
#define CAM_SET_EVT(x,y)        kal_trace(TRACE_GROUP_2, CAM_SET_EVT_TRC, x, y);
#define CAM_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, CAM_RESULT, x, y, z);
#define CAM_BUFFER_TRACE(x)     kal_trace(TRACE_INFO,CAM_BUFFER,x);
#define CAM_QR_RESULT_TRACE(x)  kal_trace(TRACE_INFO,CAM_QR_RESULT,x);
#define CAM_CLOSE_IMAGE_RESULT_TRACE(x) kal_trace(TRACE_INFO,CAM_CLOSE_IMG_RESULT,x);
#else /* __CAM_TRACE_ON__ */ 
#define CAM_FUNC_ENTRY(X)
#define CAM_STATE_TRACE(s)
#define CAM_VALUE_TRACE(x,y,z)
#define CAM_WAIT_EVT(x,y)
#define CAM_SET_EVT(x,y)
#define CAM_RESULT_TRACE(x,y,z)
#define CAM_BUFFER_TRACE(x)     
#define CAM_QR_RESULT_TRACE(x)  
#define CAM_CLOSE_IMAGE_RESULT_TRACE(x) 
#endif /* __CAM_TRACE_ON__ */ 

#ifdef __IMG_TRACE_ON__
#define IMG_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_3, X);
#define IMG_STATE_TRACE(s)    kal_trace(TRACE_STATE, IMG_STATE, s);
#define IMG_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_3, IMG_CHECK_VALUE, x, y, z);
#define IMG_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_3, IMG_WAIT_EVT_TRC, x, y);
#define IMG_SET_EVT(x,y)        kal_trace(TRACE_GROUP_3, IMG_SET_EVT_TRC, x, y);
#define IMG_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, IMG_RESULT, x, y, z);
#else /* __IMG_TRACE_ON__ */ 
#define IMG_FUNC_ENTRY(X)
#define IMG_STATE_TRACE(s)
#define IMG_VALUE_TRACE(x,y,z)
#define IMG_WAIT_EVT(x,y)
#define IMG_SET_EVT(x,y)
#define IMG_RESULT_TRACE(x,y,z)
#endif /* __IMG_TRACE_ON__ */ 

#ifdef __VID_TRACE_ON__
#define VID_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_4, X);
#define VID_STATE_TRACE(s)    kal_trace(TRACE_STATE, VID_STATE, s);
#define VID_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_4, VID_CHECK_VALUE, x, y, z);
#define VID_FILE_TRACE(a,b,c,d,e,f)    kal_trace(TRACE_GROUP_4, VID_FILE_INFO, a, b, c, d, e, f);
#define VID_VIS_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_VIS_ERROR, x, y);                          \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_AUD_ERROR_TRACE(x,y)    kal_trace(TRACE_INFO, VID_AUD_ERROR, x, y);
#define VID_PARSE_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_PARSE_ERROR, x, y);                      \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_FSAL_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_FSAL_ERROR, x, y);                        \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, VID_RESULT, x, y, z);
#define VID_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_4, VID_WAIT_EVT_TRC, x, y);
#define VID_SET_EVT(x,y)        kal_trace(TRACE_GROUP_4, VID_SET_EVT_TRC, x, y);
#else /* __VID_TRACE_ON__ */ 
#define VID_FUNC_ENTRY(X)
#define VID_STATE_TRACE(s)
#define VID_VALUE_TRACE(x,y,z)
#define VID_FILE_TRACE(a,b,c,d,e,f)
#define VID_VIS_ERROR_TRACE(x,y)
#define VID_AUD_ERROR_TRACE(x,y)
#define VID_PARSE_ERROR_TRACE(x,y)
#define VID_FSAL_ERROR_TRACE(x,y)
#define VID_RESULT_TRACE(x,y,z)
#define VID_WAIT_EVT(x,y)
#define VID_SET_EVT(x,y)
#endif /* __VID_TRACE_ON__ */ 

#ifdef __WEBCAM_TRACE_ON__
#define WEBCAM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_6, X);
#define WEBCAM_STATE_TRACE(s)    kal_trace(TRACE_STATE, WEBCAM_STATE, s);
#define WEBCAM_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_6, WEBCAM_CHECK_VALUE, x, y, z);
#define WEBCAM_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_6, WEBCAM_WAIT_EVT_TRC, x, y);
#define WEBCAM_SET_EVT(x,y)        kal_trace(TRACE_GROUP_6, WEBCAM_SET_EVT_TRC, x, y);
#define WEBCAM_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, WEBCAM_RESULT, x, y, z);
#else /* __WEBCAM_TRACE_ON__ */ 
#define WEBCAM_FUNC_ENTRY(X)
#define WEBCAM_STATE_TRACE(s)
#define WEBCAM_VALUE_TRACE(x,y,z)
#define WEBCAM_WAIT_EVT(x,y)
#define WEBCAM_SET_EVT(x,y)
#define WEBCAM_RESULT_TRACE(x,y,z)
#endif /* __WEBCAM_TRACE_ON__ */ 

#ifdef __TVO_TRACE_ON__
#define TVO_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_5, X);
#define TVO_STATE_TRACE(s)    kal_trace(TRACE_STATE, TVO_STATE, s);
#define TVO_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_5, TVO_CHECK_VALUE, x, y, z);
#define TVO_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_5, TVO_WAIT_EVT_TRC, x, y);
#define TVO_SET_EVT(x,y)        kal_trace(TRACE_GROUP_5, TVO_SET_EVT_TRC, x, y);
#define TVO_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, TVO_RESULT, x, y, z);
#else /* __TVO_TRACE_ON__ */ 
#define TVO_FUNC_ENTRY(X)
#define TVO_STATE_TRACE(s)
#define TVO_VALUE_TRACE(x,y,z)
#define TVO_WAIT_EVT(x,y)
#define TVO_SET_EVT(x,y)
#define TVO_RESULT_TRACE(x,y,z)
#endif /* __TVO_TRACE_ON__ */ 

#ifdef __CTM_TRACE_ON__
#define CTM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define CTM_STATE_TRACE(s)    kal_trace(TRACE_STATE, CTM_STATE, s);
#define CTM_VALUE_TRACE(x)    kal_trace(TRACE_GROUP_1, CTM_CHECK_VALUE, x);
#define CTM_VALUES_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_VALUES, x, y, z);
#define CTM_READ_TEXT_TRACE1(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_READ_TEXT_STEP_1, x, y, z);
#define CTM_READ_TEXT_TRACE2(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_READ_TEXT_STEP_2, x, y, z);
#else /* __CTM_TRACE_ON__ */ 
#define CTM_FUNC_ENTRY(X)
#define CTM_STATE_TRACE(s)
#define CTM_VALUE_TRACE(x)
#define CTM_VALUES_TRACE(x,y,z)
#define CTM_READ_TEXT_TRACE1(x,y,z)
#define CTM_READ_TEXT_TRACE2(x,y,z)
#endif /* __CTM_TRACE_ON__ */ 

#ifdef __BT_A2DP_TRACE_ON__
#define AUD_BT_A2DP_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_BT_A2DP_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_BT_A2DP_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_BT_A2DP_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_BT_A2DP_STATE, s);
#define AUD_BT_A2DP_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_BT_A2DP_CHECK_VALUE, x, y, z);
#define AUD_BT_A2DP_FUNC_TRACE1(F,x)    kal_trace(TRACE_GROUP_1, F,x);
#define AUD_BT_A2DP_FUNC_TRACE2(F,x,y)    kal_trace(TRACE_GROUP_1, F,x,y);
#define AUD_BT_A2DP_FUNC_TRACE3(F,x,y,z)    kal_trace(TRACE_GROUP_1, F,x,y,z);
#else /* __BT_A2DP_TRACE_ON__ */ 
#define AUD_BT_A2DP_FUNC_ENTRY(X)
#define AUD_BT_A2DP_FUNC_ENTRY1(F,x)
#define AUD_BT_A2DP_FUNC_ENTRY2(F,x,y)
#define AUD_BT_A2DP_STATE_TRACE(s)
#define AUD_BT_A2DP_VALUE_TRACE(x,y,z)
#define AUD_BT_A2DP_FUNC_TRACE1(F,x)
#define AUD_BT_A2DP_FUNC_TRACE2(F,x,y)
#define AUD_BT_A2DP_FUNC_TRACE3(F,x,y,z)
#endif /* __BT_A2DP_TRACE_ON__ */ 

#ifdef __BT_HFP_TRACE_ON__
#define AUD_BT_HFP_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_BT_HFP_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_BT_HFP_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_BT_HFP_FUNC_ENTRY3(F, x, y, z)    kal_trace(TRACE_GROUP_1, F, x, y, z);
#define AUD_BT_HFP_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_BT_HFP_STATE, s);
#define AUD_BT_HFP_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_BT_HFP_CHECK_VALUE, x, y, z);
#define AUD_BT_HFP_FUNC_TRACE1(F,x)    kal_trace(TRACE_GROUP_1, F,x);
#define AUD_BT_HFP_FUNC_TRACE2(F,x,y)    kal_trace(TRACE_GROUP_1, F,x,y);
#define AUD_BT_HFP_FUNC_TRACE3(F,x,y,z)    kal_trace(TRACE_GROUP_1, F,x,y,z);
#else /* __BT_HFP_TRACE_ON__ */ 
#define AUD_BT_HFP_FUNC_ENTRY(X)
#define AUD_BT_HFP_FUNC_ENTRY1(F,x)
#define AUD_BT_HFP_FUNC_ENTRY2(F,x,y)
#define AUD_BT_HFP_FUNC_ENTRY3(F, x, y, z)
#define AUD_BT_HFP_STATE_TRACE(s)
#define AUD_BT_HFP_VALUE_TRACE(x,y,z)
#define AUD_BT_HFP_FUNC_TRACE1(F,x)
#define AUD_BT_HFP_FUNC_TRACE2(F,x,y)
#define AUD_BT_HFP_FUNC_TRACE3(F,x,y,z)
#endif /* __BT_HFP_TRACE_ON__ */ 

#ifdef __RTP_TRACE_ON__
#define RTP_RETURN_TRACE(x)                     kal_trace(TRACE_GROUP_1, RTP_CHECK_RETURN, x)
#define RTP_VALUE_TRACE(x)                      kal_trace(TRACE_GROUP_1, RTP_CHECK_VALUE, x)
#define RTP_VALUES_TRACE(x,y,z)                 kal_trace(TRACE_GROUP_1, RTP_CHECK_VALUES, x, y, z)
#define RTP_GET_VALUE_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RTP_GET_VALUE, x, y)
#define RTP_CODEC_TRACE(a,b,c,d,e,f,g,h,i,j)    kal_trace(TRACE_GROUP_1, RTP_CHECK_CODEC, a, b, c, d, e, f, g, h, i, j)
#define RTP_PTIME_TRACE(x,y)                    kal_trace(TRACE_GROUP_1, RTP_CHECK_PTIME_MAXPTIME, x, y)
#define RTP_IDLE_TRACE                          kal_trace(TRACE_GROUP_1, RTP_CHECK_IDLE)
#define RTP_ENCODING_TRACE                      kal_trace(TRACE_GROUP_1, RTP_CHECK_ENCODE)
#define RTP_DECODING_TRACE                      kal_trace(TRACE_GROUP_1, RTP_CHECK_DECODE)
#define RTP_ENDECODING_TRACE                    kal_trace(TRACE_GROUP_1, RTP_CHECK_ENDECODE)
#define RTP_DATA_LOST_TRACE(x)                  kal_trace(TRACE_GROUP_1, RTP_ERROR_PACKET_LOST, x)
#define RTP_DATA_SEND_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_SENT_PACKET, x, y)
#define RTP_DATA_RECV_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RECV_PACKET, x, y)
#define RTP_DATA_PLAY_TRACE(x,y,z)              kal_trace(TRACE_GROUP_1, RTP_CHECK_PLAY_PACKET, x, y, z)
#define RTP_DATA_RECORD_TRACE(x)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RECORD_PACKET, x)
#else /* __RTP_TRACE_ON__ */ 
#define RTP_RETURN_TRACE(x)
#define RTP_VALUE_TRACE(x)
#define RTP_VALUES_TRACE(x,y,z)
#define RTP_GET_VALUE_TRACE(x,y)
#define RTP_CODEC_TRACE(a,b,c,d,e,f,g,h,i,j)
#define RTP_PTIME_TRACE(x,y)
#define RTP_IDLE_TRACE
#define RTP_ENCODING_TRACE
#define RTP_DECODING_TRACE
#define RTP_ENDECODING_TRACE
#define RTP_DATA_LOST_TRACE(x)
#define RTP_DATA_SEND_TRACE(x,y)
#define RTP_DATA_RECV_TRACE(x,y)
#define RTP_DATA_PLAY_TRACE(x,y,z)
#define RTP_DATA_RECORD_TRACE(x)
#endif /* __RTP_TRACE_ON__ */ 

#ifdef __STREAM_TRACE_ON__
#define STREAM_RETURN_TRACE(x)                      kal_trace(TRACE_GROUP_1, STREAM_CHECK_RETURN, x)
#define STREAM_VALUE_TRACE(x)                       kal_trace(TRACE_GROUP_1, STREAM_CHECK_VALUE, x)
#define STREAM_VALUES_TRACE(x,y,z)                  kal_trace(TRACE_GROUP_1, STREAM_CHECK_VALUES, x, y, z)
#define STREAM_FUNC_LOG(TAG)                        kal_trace(TRACE_FUNC, TAG)
#define STREAM_FUNC_LOG2(TAG,VAR)                   kal_trace(TRACE_FUNC, TAG, VAR)
#define STREAM_FUNC_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define STREAM_FUNC_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_FUNC, TAG, VAR1, VAR2, VAR3)
#define STREAM_STATE_LOG(TAG, VAR)                  kal_trace(TRACE_STATE, TAG, VAR)
#define STREAM_INFO_LOG(TAG)                        kal_trace(TRACE_INFO, TAG)
#define STREAM_INFO_LOG2(TAG, VAR)                  kal_trace(TRACE_INFO, TAG, VAR)
#define STREAM_INFO_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define STREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_INFO, TAG, VAR1, VAR2, VAR3)
#define STREAM_INFO_LOG5(TAG, A, B, C, D)           kal_trace(TRACE_INFO, TAG, A, B, C, D)
#define STREAM_INFO_LOG6(TAG, A, B, C, D, E)        kal_trace(TRACE_INFO, TAG, A, B, C, D, E)
#define STREAM_INFO_LOG7(TAG, A, B, C, D, E, F)     kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F)
#define STREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)  kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G)
#define STREAM_INFO_LOG9(TAG, A, B, C, D, E, F, G, H)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H)
#define STREAM_INFO_LOG10(TAG, A, B, C, D, E, F, G, H, I)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I)
#define STREAM_INFO_LOG11(TAG, A, B, C, D, E, F, G, H, I, J)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J)
#define STREAM_INFO_LOG12(TAG, A, B, C, D, E, F, G, H, I, J, K)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K)
#define STREAM_INFO_LOG13(TAG, A, B, C, D, E, F, G, H, I, J, K, L)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L)
#define STREAM_INFO_LOG14(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)
#define STREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)

#define STREAM_WARNING_LOG(TAG)                     kal_trace(TRACE_WARNING, TAG)
#define STREAM_WARNING_LOG2(TAG, VAR)               kal_trace(TRACE_WARNING, TAG, VAR)
#define STREAM_ERROR_LOG(TAG)                       kal_trace(TRACE_ERROR, TAG)
#define STREAM_ERROR_LOG2(TAG, VAR)                 kal_trace(TRACE_ERROR, TAG, VAR)
#define STREAM_ERROR_LOG3(TAG, VAR1,VAR2)           kal_trace(TRACE_ERROR, TAG, VAR1,VAR2)
#define STREAM_PROMPT_TRACE(x)                      kal_prompt_trace(MOD_MED,"%s,%d:%s",__FILE__,__LINE__,x)
#else /* __STREAM_TRACE_ON__ */ 
#define STREAM_RETURN_TRACE(x)
#define STREAM_VALUE_TRACE(x)
#define STREAM_VALUES_TRACE(x,y,z)
#define STREAM_FUNC_LOG(TAG)
#define STREAM_FUNC_LOG2(TAG,VAR)
#define STREAM_FUNC_LOG3(TAG,VAR1,VAR2)
#define STREAM_FUNC_LOG4(TAG, VAR1, VAR2, VAR3)
#define STREAM_STATE_LOG(TAG, VAR)
#define STREAM_INFO_LOG(TAG)
#define STREAM_INFO_LOG2(TAG, VAR)
#define STREAM_INFO_LOG3(TAG,VAR1,VAR2)
#define STREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)
#define STREAM_INFO_LOG5(TAG, A, B, C, D)
#define STREAM_INFO_LOG6(TAG, A, B, C, D, E)
#define STREAM_INFO_LOG7(TAG, A, B, C, D, E, F)
#define STREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)
#define STREAM_INFO_LOG9(TAG, A, B, C, D, E, F, G, H)
#define STREAM_INFO_LOG10(TAG, A, B, C, D, E, F, G, H, I)
#define STREAM_INFO_LOG11(TAG, A, B, C, D, E, F, G, H, I, J)
#define STREAM_INFO_LOG12(TAG, A, B, C, D, E, F, G, H, I, J, K)
#define STREAM_INFO_LOG13(TAG, A, B, C, D, E, F, G, H, I, J, K, L)
#define STREAM_INFO_LOG14(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)
#define STREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)
#define STREAM_WARNING_LOG(TAG)
#define STREAM_WARNING_LOG2(TAG, VAR)
#define STREAM_ERROR_LOG(TAG)
#define STREAM_ERROR_LOG2(TAG, VAR)
#define STREAM_ERROR_LOG3(TAG, VAR1,VAR2)
#define STREAM_PROMPT_TRACE(x)
#endif /* __STREAM_TRACE_ON__ */ 

#ifdef __MTV_TRACE_ON__
#define MTV_TRACE kal_trace
#else /* __MTV_TRACE_ON__ */ 
#define MTV_TRACE if (0) kal_trace
#endif /* __MTV_TRACE_ON__ */ 
#define MTV_TRACE_GROUP_DEMOD   TRACE_INFO
#define MTV_TRACE_GROUP_DEMUX   TRACE_INFO
#define MTV_TRACE_GROUP_BE      TRACE_INFO

#ifndef MAX
#define MAX(a,b) (a>b)? a:b
#endif 
#ifndef MIN
#define MIN(a,b) (a<b)? a:b
#endif 

/* audio */
#define AUD_ENTER_STATE(_s_) AUD_STATE_TRACE(_s_)\
                              (aud_context_p->state = _s_)

#define AUD_IN_STATE(_s_) (aud_context_p->state == _s_)
#ifdef __MED_CAM_MOD__
/* camera */
#define CAM_ENTER_STATE(_s_) CAM_STATE_TRACE(_s_)\
                              (cam_context_p->state = _s_)

#define CAM_IN_STATE(_s_) (cam_context_p->state == _s_)
#endif /* __MED_CAM_MOD__ */ 

#ifdef __MED_IMG_MOD__
/* image */
#define IMG_ENTER_STATE(_s_) IMG_STATE_TRACE(_s_)\
                              (img_context_p->state = _s_)

#define IMG_IN_STATE(_s_) (img_context_p->state == _s_)
#endif /* __MED_IMG_MOD__ */ 

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)

#define VID_ENTER_STATE(_s_)                                        \
do {                                                                \
    kal_trace(TRACE_STATE, VID_TRC_ENTER_VID_STATE, _s_, __LINE__); \
    vid_context_p->state = _s_;                                     \
    vid_debug_print_cur_state(__LINE__);                            \
} while(0);

#define VID_AUD_ENTER_STATE(_s_)                                    \
do {                                                                \
    kal_trace(TRACE_STATE, VID_TRC_ENTER_AUD_STATE, _s_, __LINE__); \
    vid_context_p->aud_state = _s_;                                 \
    vid_debug_print_cur_state(__LINE__);                            \
} while(0);

#define VID_IN_STATE(_s_)       (vid_context_p->state == _s_)
#define VID_AUD_IN_STATE(_s_)   (vid_context_p->aud_state == _s_)

#define VID_RETURN(_return_)                        \
do {                                                \
    med_debug_print_result(_return_, __LINE__);     \
    return _return_;                                \
} while(0);

#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 

#if defined (__MED_WEBCAM_MOD__)
/* web camera */
#define WEBCAM_ENTER_STATE(_s_)  WEBCAM_STATE_TRACE(_s_)\
                              (webcam_context_p->state = _s_)

#define WEBCAM_IN_STATE(_s_) (webcam_context_p->state == _s_)
#endif /* defined (__MED_WEBCAM_MOD__) */ 

#if defined (__MED_TVO_MOD__)
/* tv output */
#define TVO_ENTER_STATE(_s_)  (tvo_context_p->state = _s_)

#define TVO_IN_STATE(_s_) (tvo_context_p->state == _s_)
#endif /* defined (__MED_TVO_MOD__) */ 

#ifdef __MED_CTM_MOD__
#define CTM_ENTER_STATE(_s_)  do { CTM_STATE_TRACE(_s_) \
                  aud_ctm_ctx.state = (_s_); } while(0)
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_BT_A2DP_MOD__
#define AUD_BT_A2DP_ENTER_STATE(_s_) AUD_BT_A2DP_STATE_TRACE(_s_)\
                  (aud_bt_a2dp_ctx.state = _s_)

#define AUD_BT_A2DP_IN_STATE(_s_) (aud_bt_a2dp_ctx.state == _s_)
#endif /* __MED_BT_A2DP_MOD__ */ 

#ifdef __MED_BT_HFP_MOD__
#define AUD_BT_HFP_ENTER_STATE(_s_) AUD_BT_HFP_STATE_TRACE(_s_)\
                  (aud_bt_hfp_ctx.state = _s_)

#define AUD_BT_HFP_IN_STATE(_s_) (aud_bt_hfp_ctx.state == _s_)
#endif /* __MED_BT_HFP_MOD__ */ 
/*==== TYPES =========*/

typedef enum
{
    AUD_MEDIA_PLAY_MODE_NONE,
    AUD_VM_PLAY_AS_RING,
    AUD_VM_PLAY_AS_MEMO,
    AUD_MEDIA_PLAY_AS_RING,
    AUD_MEDIA_PLAY_AS_SONG,
    NUM_OF_MEDIA_PLAY_MODE
}
aud_media_play_mode_enum;

typedef enum
{
    AUD_ID,
    AUD_FILE,
    AUD_STRING,
    AUD_FM_RADIO,
    AUD_TTS,
    AUD_UNKNOWN_SOURCE_TYPE
}
aud_source_type_enum;

typedef enum
{
    MED_NVRAM_IDLE,
    MED_POWERON_READING_NVRAM,
    MED_POWERON_READING_NVRAM_FINISH
}
med_nvram_state_enum;

typedef enum
{
    MMA_PLAYER_IMY = 0,
    MMA_PLAYER_SMF_1,
    MMA_PLAYER_SMF_2,
    MMA_PLAYER_SMF_3,
    MMA_PLAYER_SMF_4,
    MMA_PLAYER_TONE_S1,
    MMA_PLAYER_TONE_S2,
    MMA_PLAYER_TONE_S3,
    MMA_PLAYER_TONE_S4,
    MMA_PLAYER_WAV_1,
    MMA_PLAYER_WAV_2,
    MMA_PLAYER_WAV_3,
    MMA_PLAYER_SINGLE,
    MMA_NO_OF_PLAYER
}
mma_player_enum;

#endif /* _MED_GLOBAL_H */ 

#endif /* MED_NOT_PRESENT */ 

