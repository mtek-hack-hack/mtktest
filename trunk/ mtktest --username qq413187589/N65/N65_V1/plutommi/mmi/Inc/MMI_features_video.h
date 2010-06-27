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
 *   MMI_features_video.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Vdieo Feature Customization
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _VIDEO_FEATURES_H_
#define _VIDEO_FEATURES_H_

#include "MMI_features.h"
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)




#if defined(CAMERA_MODULE)
/***************************************************************************** 
*
*
* MT6218B, MT6217
*
*
*****************************************************************************/

    #if defined(PAP1301) || defined(PAP1302)
    /***************************************************************************** 
    *
    * Start of PAP1031, PAP1302
    *
    *****************************************************************************/
    /***************************************************************************** 
    * Video Recorder Feature
    *****************************************************************************/
    
    #define __VDOREC_FEATURE_ZOOM__
    #define __VDOREC_FEATURE_WB__
    #define __VDOREC_FEATURE_EV__
    //#define __VDOREC_FEATURE_NIGHT__
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT__
    #define __VDOREC_FEATURE_BANDING__                                                                 
    #define __VDOREC_FEATURE_VIDEO_QTY__
    //#define __VDOREC_FEATURE_SIZE_LIMIT__
    //#define __VDOREC_FEATURE_TIME_LIMIT__
    #define __VDOREC_FEATURE_RECORD_AUD__
    //#define __VDOREC_FEATURE_VIDEO_FORMAT__

    #if defined(PAP1302)
        #define __VDOREC_FEATURE_EFFECT__
    #else /* PAP1301 */
        //#define __VDOREC_FEATURE_EFFECT__
    #endif
    

    #if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
        #define __VDOREC_FEATURE_STORAGE__
    #endif 

    #define __VDOREC_FEATURE_MERGE_MENU__           /* will merge "Camcoder Setting" & "Video Setting" into one */
    //#define __VDOREC_FEATURE_RECORDING_ZOOM__ /* allows zooming while recording */
    //#define __VDOREC_FEATURE_RECORDING_EV__       /* allows adjust ev while recording */

    /***************************************************************************** 
    * Zoom
    *****************************************************************************/
    #define VDOREC_FEATURE_ZOOM_COUNT           (3)
    #define VDOREC_FEAUTRE_ZOOM_LIMIT           (40)

    #define VDOREC_FEATURE_ZOOM_0               (10)
    #define VDOREC_FEATURE_ZOOM_1               (20)
    #define VDOREC_FEATURE_ZOOM_2               (40)
    #define VDOREC_FEATURE_ZOOM_3               (0)
    #define VDOREC_FEATURE_ZOOM_4               (0)
    #define VDOREC_FEATURE_ZOOM_5               (0)
    #define VDOREC_FEATURE_ZOOM_6               (0)
    #define VDOREC_FEATURE_ZOOM_7               (0)
    #define VDOREC_FEATURE_ZOOM_8               (0)
    #define VDOREC_FEATURE_ZOOM_9               (0)
    #define VDOREC_FEATURE_ZOOM_10              (0)
    #define VDOREC_FEATURE_ZOOM_11              (0)
    #define VDOREC_FEATURE_ZOOM_12              (0)
    #define VDOREC_FEATURE_ZOOM_13              (0)
    #define VDOREC_FEATURE_ZOOM_14              (0)
    #define VDOREC_FEATURE_ZOOM_15              (0)
    #define VDOREC_FEATURE_ZOOM_16              (0)
    #define VDOREC_FEATURE_ZOOM_17              (0)
    #define VDOREC_FEATURE_ZOOM_18              (0)
    #define VDOREC_FEATURE_ZOOM_19              (0)
    #define VDOREC_FEATURE_ZOOM_20              (0)
    #define VDOREC_FEATURE_ZOOM_21              (0)
    #define VDOREC_FEATURE_ZOOM_22              (0)
    #define VDOREC_FEATURE_ZOOM_23              (0)
    #define VDOREC_FEATURE_ZOOM_24              (0)
    #define VDOREC_FEATURE_ZOOM_25              (0)
    #define VDOREC_FEATURE_ZOOM_26              (0)
    #define VDOREC_FEATURE_ZOOM_27              (0)
    #define VDOREC_FEATURE_ZOOM_28              (0)
    #define VDOREC_FEATURE_ZOOM_29              (0)
    #define VDOREC_FEATURE_ZOOM_30              (0)
    #define VDOREC_FEATURE_ZOOM_31              (0)
    #define VDOREC_FEATURE_ZOOM_32              (0)
    #define VDOREC_FEATURE_ZOOM_33              (0)
    #define VDOREC_FEATURE_ZOOM_34              (0)
    #define VDOREC_FEATURE_ZOOM_35              (0)    

    /***************************************************************************** 
    * CamCoder Setting
    *****************************************************************************/
    /******** customizable led highlight *********/
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    #define __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__

    /***************************************************************************** 
    * Video Recorder Setting
    *****************************************************************************/
    /******* customizable video qualtiy *********/
    //#define __VDOREC_FEATURE_VIDEO_QTY_FINE__
    #define __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    #define __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    #define __VDOREC_FEATURE_VIDEO_QTY_LOW__

    /******** customizable wb *********/
    #define __VDOREC_FEATURE_WB_AUTO__
    #define __VDOREC_FEATURE_WB_DAYLIGHT__
    #define __VDOREC_FEATURE_WB_TUNGSTEN__
    #define __VDOREC_FEATURE_WB_FLUORESCENT__
    //#define __VDOREC_FEATURE_WB_CLOUD__
    //#define __VDOREC_FEATURE_WB_INCANDESCENCE__

    /******* customizable ev *********/
    /* default will have off [ev 0] and [ev +1] [ev -1] menu if __VDOREC_FEATURE_EV__ is turn on */
    #define __VDOREC_FEATURE_EV_2__
    #define __VDOREC_FEATURE_EV_3__
    #define __VDOREC_FEATURE_EV_4__

    #if defined(PAP1302)
        #define __VDOREC_FEATURE_EFFECT_NORMAL__
        #define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
        #define __VDOREC_FEATURE_EFFECT_SEPIA__
        //#define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
        //#define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
        #define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
        //#define __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
        #define __VDOREC_FEATURE_EFFECT_BLACKBOARD__
        #define __VDOREC_FEATURE_EFFECT_WHITEBOARD__
        //#define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
        //#define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
        //#define __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
        //#define __VDOREC_FEATURE_EFFECT_CONTRAST__
        //#define __VDOREC_FEATURE_EFFECT_JEAN__
        //#define __VDOREC_FEATURE_EFFECT_SKETCH__
        //#define __VDOREC_FEATURE_EFFECT_OIL__
    #else /* PAP1301 */
        /******* customizable effect *********/
        #define __VDOREC_FEATURE_EFFECT_NORMAL__
        //#define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
        //#define __VDOREC_FEATURE_EFFECT_SEPIA__
        //#define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
        //#define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
        //#define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
        //#define __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
        //#define __VDOREC_FEATURE_EFFECT_BLACKBOARD__
        //#define __VDOREC_FEATURE_EFFECT_WHITEBOARD__
        //#define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
        //#define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
        //#define __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
        //#define __VDOREC_FEATURE_EFFECT_CONTRAST__
        //#define __VDOREC_FEATURE_EFFECT_JEAN__    
        //#define __VDOREC_FEATURE_EFFECT_SKETCH__
        //#define __VDOREC_FEATURE_EFFECT_OIL__ 
    #endif 

    /******* customizable size limit *********/
    //#define VDOREC_FEATURE_SIZE_LIMIT_1           (25)            /* 25k */
    //#define VDOREC_FEATURE_SIZE_LIMIT_2           (50)            /* 50k */
    //#define VDOREC_FEATURE_SIZE_LIMIT_3           (200)           /* 200k */

    /******* customizable time limit *********/
    //#define VDOREC_FEATURE_TIME_LIMIT_1           (15)            /* 15 sec */
    //#define VDOREC_FEATURE_TIME_LIMIT_2           (30)            /* 30 sec */
    //#define VDOREC_FEATURE_TIME_LIMIT_3           (60)            /* 60 sec */
    

    /******* SubLCD ********/
    #ifdef __MMI_SUBLCD__
    //  #define __VDOREC_FEATURE_SELF_RECORD__  /* not implement yet */
    #endif /* __MMI_SUBLCD__ */

    #define VDOREC_RECORD_KEY                   (KEY_CAMERA)
    #define VDOREC_RECORD_EXTRA_KEY1            (KEY_IP)            /* if no extra, use -1 */
    #define VDOREC_RECORD_EXTRA_KEY2            (-1)                /* if no extra, use -1 */


    #if defined(PAP1302)
        #define VDOREC_EFFECT_KEY               (KEY_1)             /* if no use hotkey, set -1 */
        #define VDOREC_WB_KEY                   (KEY_2)
        #define VDOREC_NIGHT_KEY                (-1)
        #define VDOREC_LED_HIGHLIGHT_KEY        (KEY_3)
    #else /* PAP1301 */
        #define VDOREC_EFFECT_KEY               (-1)                /* if no use hotkey, set -1 */
        #define VDOREC_WB_KEY                   (KEY_1)
        #define VDOREC_NIGHT_KEY                (-1)
        #define VDOREC_LED_HIGHLIGHT_KEY        (KEY_2)
    #endif
    
    /***************************************************************************** 
    *   Default Setting 
    *****************************************************************************/
    /*********** Preview ***********/
    #define VDOREC_DEFAULT_SETTING_ZOOM                 (0)  /* index - start from 0 */

    #define VDOREC_DEFAULT_SETTING_WB                   VDOREC_SETTING_WB_AUTO
    #define VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT        VDOREC_SETTING_LED_HIGHLIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_EV                   VDOREC_SETTING_EV_ZERO      
    #define VDOREC_DEFAULT_SETTING_NIGHT                VDOREC_SETTING_NIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_BANDING              VDOREC_SETTING_BANDING_60HZ

    #define VDOREC_DEFAULT_SETTING_EFFECT               VDOREC_SETTING_EFFECT_NORMAL

    #define VDOREC_DEFAULT_SETTING_VIDEO_SIZE           VDOREC_SETTING_VIDEO_SIZE_QCIF
    #define VDOREC_DEFAULT_SETTING_VIDEO_QTY            VDOREC_SETTING_VIDEO_QTY_NORMAL
    #define VDOREC_DEFAULT_SETTING_SIZE_LIMIT           VDOREC_SETTING_SIZE_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_TIME_LIMIT           VDOREC_SETTING_TIME_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_RECORD_AUD           VDOREC_SETTING_RECORD_AUD_ON
    #define VDOREC_DEFAULT_SETTING_VIDEO_FORMAT         VDOREC_SETTING_VIDEO_FORMAT_MP4
    #define VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME      VDOREC_SETTING_COLOR_IDX_FRAME_OFF
    #define VDOREC_DEFAULT_SETTING_STORAGE              VDOREC_SETTING_STORAGE_PHONE

    #define VDOREC_DEFAULT_PREVIEW_LED_VALUE            (80)


    /* preview rotation */
    #if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #else /* not define SENSOR_ROTATION */
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #endif /* SENSOR_ROTATION */



    /***************************************************************************** 
    * Video Player Feature
    *****************************************************************************/
    //#define __VDOPLY_FEATURE_SPEED__
    #define __VDOPLY_FEATURE_VOLUME__
    
#if !defined(__MMI_MAINLCD_128X128__) && !defined(MT6218B)
    #define __VDOPLY_FEATURE_FULLSCREEN__
#endif

    //#define __VDOPLY_FEATURE_SNAPSHOT__       /* 6218B, 6217 dont support jpeg encoder */

    /* misc config */
    //#define __VDOPLY_FEATURE_VOLUME_MUTE__      /* allows audio mute */

    #define VDOPLY_FEATURE_SPEED_COUNT  (0)     /* not used */
    #define VDOPLY_DEFAULT_SPEED        (0)     /* not used */
    
    #define VDOPLY_FEATURE_SPEED_0      (0)
    #define VDOPLY_FEATURE_SPEED_1      (0)
    #define VDOPLY_FEATURE_SPEED_2      (0)
    #define VDOPLY_FEATURE_SPEED_3      (0)
    #define VDOPLY_FEATURE_SPEED_4      (0)
    #define VDOPLY_FEATURE_SPEED_5      (0)
    #define VDOPLY_FEATURE_SPEED_6      (0)
    #define VDOPLY_FEATURE_SPEED_7      (0)
    #define VDOPLY_FEATURE_SPEED_8      (0)

    #define VDOPLY_SNAP_EXTRA_KEY       (-1)  /* if no extra, use -1 */
    
    /***************************************************************************** 
    *
    * End of PAP1031
    *
    *****************************************************************************/
    
    #elif defined(AIT700) || defined(AIT701)
    /***************************************************************************** 
    *
    * Start of AIT700, AIT701PAP1302
    *
    *****************************************************************************/
    /***************************************************************************** 
    * Video Recorder Feature
    *****************************************************************************/
    
    #define __VDOREC_FEATURE_ZOOM__
    #define __VDOREC_FEATURE_WB__
    #define __VDOREC_FEATURE_EV__
    //#define __VDOREC_FEATURE_NIGHT__
    
    #ifdef LED_ONOFF_SUPPOR
        //#define __VDOREC_FEATURE_LED_HIGHLIGHT__
    #endif
    
    #define __VDOREC_FEATURE_BANDING__                                                                 
    #define __VDOREC_FEATURE_VIDEO_QTY__
    //#define __VDOREC_FEATURE_SIZE_LIMIT__
    //#define __VDOREC_FEATURE_TIME_LIMIT__
    //#define __VDOREC_FEATURE_RECORD_AUD__
    //#define __VDOREC_FEATURE_VIDEO_FORMAT__
    #define __VDOREC_FEATURE_EFFECT__

    

    #if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
        #define __VDOREC_FEATURE_STORAGE__
    #endif 

    //#define __VDOREC_FEATURE_MERGE_MENU__         /* will merge "Camcoder Setting" & "Video Setting" into one */
    #define __VDOREC_FEATURE_RECORDING_ZOOM__   /* allows zooming while recording */
    #define __VDOREC_FEATURE_RECORDING_EV__     /* allows adjust ev while recording */

    /***************************************************************************** 
    * Zoom
    *****************************************************************************/
    #define VDOREC_FEATURE_ZOOM_COUNT           (3)
    #define VDOREC_FEAUTRE_ZOOM_LIMIT           (40)
    
    #define VDOREC_FEATURE_ZOOM_0               (10)
    #define VDOREC_FEATURE_ZOOM_1               (20)
    #define VDOREC_FEATURE_ZOOM_2               (40)
    #define VDOREC_FEATURE_ZOOM_3               (0)
    #define VDOREC_FEATURE_ZOOM_4               (0)
    #define VDOREC_FEATURE_ZOOM_5               (0)
    #define VDOREC_FEATURE_ZOOM_6               (0)
    #define VDOREC_FEATURE_ZOOM_7               (0)
    #define VDOREC_FEATURE_ZOOM_8               (0)
    #define VDOREC_FEATURE_ZOOM_9               (0)
    #define VDOREC_FEATURE_ZOOM_10              (0)
    #define VDOREC_FEATURE_ZOOM_11              (0)
    #define VDOREC_FEATURE_ZOOM_12              (0)
    #define VDOREC_FEATURE_ZOOM_13              (0)
    #define VDOREC_FEATURE_ZOOM_14              (0)
    #define VDOREC_FEATURE_ZOOM_15              (0)
    #define VDOREC_FEATURE_ZOOM_16              (0)
    #define VDOREC_FEATURE_ZOOM_17              (0)
    #define VDOREC_FEATURE_ZOOM_18              (0)
    #define VDOREC_FEATURE_ZOOM_19              (0)
    #define VDOREC_FEATURE_ZOOM_20              (0)
    #define VDOREC_FEATURE_ZOOM_21              (0)
    #define VDOREC_FEATURE_ZOOM_22              (0)
    #define VDOREC_FEATURE_ZOOM_23              (0)
    #define VDOREC_FEATURE_ZOOM_24              (0)
    #define VDOREC_FEATURE_ZOOM_25              (0)
    #define VDOREC_FEATURE_ZOOM_26              (0)
    #define VDOREC_FEATURE_ZOOM_27              (0)
    #define VDOREC_FEATURE_ZOOM_28              (0)
    #define VDOREC_FEATURE_ZOOM_29              (0)
    #define VDOREC_FEATURE_ZOOM_30              (0)
    #define VDOREC_FEATURE_ZOOM_31              (0)
    #define VDOREC_FEATURE_ZOOM_32              (0)
    #define VDOREC_FEATURE_ZOOM_33              (0)
    #define VDOREC_FEATURE_ZOOM_34              (0)
    #define VDOREC_FEATURE_ZOOM_35              (0)  

    /***************************************************************************** 
    * CamCoder Setting
    *****************************************************************************/
    /******** customizable led highlight *********/
    #define __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__

    /***************************************************************************** 
    * Video Recorder Setting
    *****************************************************************************/
    /******* customizable video qualtiy *********/
    //#define __VDOREC_FEATURE_VIDEO_QTY_FINE__
    #define __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    #define __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    #define __VDOREC_FEATURE_VIDEO_QTY_LOW__

    /******** customizable wb *********/
    #define __VDOREC_FEATURE_WB_AUTO__
    #define __VDOREC_FEATURE_WB_DAYLIGHT__
    #define __VDOREC_FEATURE_WB_TUNGSTEN__
    #define __VDOREC_FEATURE_WB_FLUORESCENT__
    //#define __VDOREC_FEATURE_WB_CLOUD__
    //#define __VDOREC_FEATURE_WB_INCANDESCENCE__

    /******* customizable ev *********/
    /* default will have off [ev 0] and [ev +1] [ev -1] menu if __VDOREC_FEATURE_EV__ is turn on */
    #define __VDOREC_FEATURE_EV_2__
    #define __VDOREC_FEATURE_EV_3__
    #define __VDOREC_FEATURE_EV_4__
    
    #define __VDOREC_FEATURE_EFFECT_NORMAL__
    #define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    #define __VDOREC_FEATURE_EFFECT_SEPIA__
    //#define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    //#define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    #define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    #define __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    #define __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    #define __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    //#define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    //#define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    //#define __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    //#define __VDOREC_FEATURE_EFFECT_CONTRAST__
    //#define __VDOREC_FEATURE_EFFECT_JEAN__
    //#define __VDOREC_FEATURE_EFFECT_SKETCH__
    //#define __VDOREC_FEATURE_EFFECT_OIL__

    /******* customizable size limit *********/
    //#define VDOREC_FEATURE_SIZE_LIMIT_1           (25)            /* 25k */
    //#define VDOREC_FEATURE_SIZE_LIMIT_2           (50)            /* 50k */
    //#define VDOREC_FEATURE_SIZE_LIMIT_3           (200)           /* 200k */

    /******* customizable time limit *********/
    //#define VDOREC_FEATURE_TIME_LIMIT_1           (15)            /* 15 sec */
    //#define VDOREC_FEATURE_TIME_LIMIT_2           (30)            /* 30 sec */
    //#define VDOREC_FEATURE_TIME_LIMIT_3           (60)            /* 60 sec */
    

    /******* SubLCD ********/
    #ifdef __MMI_SUBLCD__
    //  #define __VDOREC_FEATURE_SELF_RECORD__  /* not implement yet */
    #endif /* __MMI_SUBLCD__ */

    #define VDOREC_RECORD_KEY                   (KEY_CAMERA)
    #define VDOREC_RECORD_EXTRA_KEY1            (KEY_IP)            /* if no extra, use -1 */
    #define VDOREC_RECORD_EXTRA_KEY2            (-1)                /* if no extra, use -1 */

    /* disable hot key since AIT700, AIT701 cant display hint */
    #define VDOREC_EFFECT_KEY                       (-1)            /* if no use hotkey, set -1 */
    #define VDOREC_WB_KEY                           (-1)
    #define VDOREC_NIGHT_KEY                        (-1)
    #define VDOREC_LED_HIGHLIGHT_KEY                (-1)
    
    /***************************************************************************** 
    *   Default Setting 
    *****************************************************************************/
    /*********** Preview ***********/
    #define VDOREC_DEFAULT_SETTING_ZOOM             (0)  /* index - start from 0 */

    #define VDOREC_DEFAULT_SETTING_WB               VDOREC_SETTING_WB_AUTO
    #define VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT    VDOREC_SETTING_LED_HIGHLIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_EV               VDOREC_SETTING_EV_ZERO      
    #define VDOREC_DEFAULT_SETTING_NIGHT            VDOREC_SETTING_NIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_BANDING          VDOREC_SETTING_BANDING_60HZ

    #define VDOREC_DEFAULT_SETTING_EFFECT           VDOREC_SETTING_EFFECT_NORMAL

    #define VDOREC_DEFAULT_SETTING_VIDEO_SIZE       VDOREC_SETTING_VIDEO_SIZE_QCIF
    #define VDOREC_DEFAULT_SETTING_VIDEO_QTY        VDOREC_SETTING_VIDEO_QTY_NORMAL
    #define VDOREC_DEFAULT_SETTING_SIZE_LIMIT       VDOREC_SETTING_SIZE_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_TIME_LIMIT       VDOREC_SETTING_TIME_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_RECORD_AUD       VDOREC_SETTING_RECORD_AUD_ON
    #define VDOREC_DEFAULT_SETTING_VIDEO_FORMAT     VDOREC_SETTING_VIDEO_FORMAT_MP4
    #define VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME  VDOREC_SETTING_COLOR_IDX_FRAME_OFF
    
    #define VDOREC_DEFAULT_SETTING_STORAGE              VDOREC_SETTING_STORAGE_PHONE

    #define VDOREC_DEFAULT_PREVIEW_LED_VALUE            (80)


    /* preview rotation */
    #if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #else /* not define SENSOR_ROTATION */
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #endif /* SENSOR_ROTATION */



    /***************************************************************************** 
    * Video Player Feature
    *****************************************************************************/
    //#define __VDOPLY_FEATURE_SPEED__
    #define __VDOPLY_FEATURE_VOLUME__
    
#if !defined(__MMI_MAINLCD_128X128__) && !defined(MT6218B)
    #define __VDOPLY_FEATURE_FULLSCREEN__
#endif

    //#define __VDOPLY_FEATURE_SNAPSHOT__       /* 6218B, 6217 dont support jpeg encoder */

    /* misc config */
    #define __VDOPLY_FEATURE_VOLUME_MUTE__      /* allows audio mute */

    #define VDOPLY_FEATURE_SPEED_COUNT  (0)     /* not used */
    #define VDOPLY_DEFAULT_SPEED        (0)     /* not used */
    
    #define VDOPLY_FEATURE_SPEED_0      (0)
    #define VDOPLY_FEATURE_SPEED_1      (0)
    #define VDOPLY_FEATURE_SPEED_2      (0)
    #define VDOPLY_FEATURE_SPEED_3      (0)
    #define VDOPLY_FEATURE_SPEED_4      (0)
    #define VDOPLY_FEATURE_SPEED_5      (0)
    #define VDOPLY_FEATURE_SPEED_6      (0)
    #define VDOPLY_FEATURE_SPEED_7      (0)
    #define VDOPLY_FEATURE_SPEED_8      (0)
    
    #define VDOPLY_SNAP_EXTRA_KEY       (-1)    /* if no extra, use -1 */

    /***************************************************************************** 
    *
    * End of AIT700, AIT701
    *
    *****************************************************************************/
    
    #else
    /***************************************************************************** 
    *
    * Start of Undefine Camera Module 
    *
    *****************************************************************************/
    /***************************************************************************** 
    * Video Recorder Feature
    *****************************************************************************/
    #define __VDOREC_FEATURE_ZOOM__
    #define __VDOREC_FEATURE_WB__
    #define __VDOREC_FEATURE_EV__
    //#define __VDOREC_FEATURE_NIGHT__

    #ifdef LED_ONOFF_SUPPOR
        //#define __VDOREC_FEATURE_LED_HIGHLIGHT__
    #endif

    #define __VDOREC_FEATURE_BANDING__                                                                 
    #define __VDOREC_FEATURE_VIDEO_QTY__
    //#define __VDOREC_FEATURE_SIZE_LIMIT__
    //#define __VDOREC_FEATURE_TIME_LIMIT__
    //#define __VDOREC_FEATURE_RECORD_AUD__
    //#define __VDOREC_FEATURE_VIDEO_FORMAT__
    //#define __VDOREC_FEATURE_EFFECT__


    #if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
        #define __VDOREC_FEATURE_STORAGE__
    #endif 

    #if(defined(__MMI_MMS__) && defined(__MMI_WGUI_CSK_ENABLE__))
#ifndef __MED_MEM_POOL__
        #define __MMI_VDOREC_MMS_SUPPORT__
#endif		
    #endif

    #define __VDOREC_FEATURE_MERGE_MENU__           /* will merge "Camcoder Setting" & "Video Setting" into one */
    //#define __VDOREC_FEATURE_RECORDING_ZOOM__ /* allows zooming while recording */
    //#define __VDOREC_FEATURE_RECORDING_EV__       /* allows adjust ev while recording */

    /***************************************************************************** 
    * Zoom
    *****************************************************************************/
    #define VDOREC_FEATURE_ZOOM_COUNT           (3)
    #define VDOREC_FEAUTRE_ZOOM_LIMIT           (40)

    #define VDOREC_FEATURE_ZOOM_0               (10)
    #define VDOREC_FEATURE_ZOOM_1               (20)
    #define VDOREC_FEATURE_ZOOM_2               (40)
    #define VDOREC_FEATURE_ZOOM_3               (0)
    #define VDOREC_FEATURE_ZOOM_4               (0)
    #define VDOREC_FEATURE_ZOOM_5               (0)
    #define VDOREC_FEATURE_ZOOM_6               (0)
    #define VDOREC_FEATURE_ZOOM_7               (0)
    #define VDOREC_FEATURE_ZOOM_8               (0)
    #define VDOREC_FEATURE_ZOOM_9               (0)
    #define VDOREC_FEATURE_ZOOM_10              (0)
    #define VDOREC_FEATURE_ZOOM_11              (0)
    #define VDOREC_FEATURE_ZOOM_12              (0)
    #define VDOREC_FEATURE_ZOOM_13              (0)
    #define VDOREC_FEATURE_ZOOM_14              (0)
    #define VDOREC_FEATURE_ZOOM_15              (0)
    #define VDOREC_FEATURE_ZOOM_16              (0)
    #define VDOREC_FEATURE_ZOOM_17              (0)
    #define VDOREC_FEATURE_ZOOM_18              (0)
    #define VDOREC_FEATURE_ZOOM_19              (0)
    #define VDOREC_FEATURE_ZOOM_20              (0)
    #define VDOREC_FEATURE_ZOOM_21              (0)
    #define VDOREC_FEATURE_ZOOM_22              (0)
    #define VDOREC_FEATURE_ZOOM_23              (0)
    #define VDOREC_FEATURE_ZOOM_24              (0)
    #define VDOREC_FEATURE_ZOOM_25              (0)
    #define VDOREC_FEATURE_ZOOM_26              (0)
    #define VDOREC_FEATURE_ZOOM_27              (0)
    #define VDOREC_FEATURE_ZOOM_28              (0)
    #define VDOREC_FEATURE_ZOOM_29              (0)
    #define VDOREC_FEATURE_ZOOM_30              (0)
    #define VDOREC_FEATURE_ZOOM_31              (0)
    #define VDOREC_FEATURE_ZOOM_32              (0)
    #define VDOREC_FEATURE_ZOOM_33              (0)
    #define VDOREC_FEATURE_ZOOM_34              (0)
    #define VDOREC_FEATURE_ZOOM_35              (0)  

    /***************************************************************************** 
    * CamCoder Setting
    *****************************************************************************/
    /******** customizable led highlight *********/
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    #define __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__


    /***************************************************************************** 
    * Video Recorder Setting
    *****************************************************************************/
    /******* customizable video qualtiy *********/
    //#define __VDOREC_FEATURE_VIDEO_QTY_FINE__
    #define __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    #define __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    #define __VDOREC_FEATURE_VIDEO_QTY_LOW__

    /******** customizable wb *********/
    #define __VDOREC_FEATURE_WB_AUTO__
    #define __VDOREC_FEATURE_WB_DAYLIGHT__
    #define __VDOREC_FEATURE_WB_TUNGSTEN__
    #define __VDOREC_FEATURE_WB_FLUORESCENT__
    #define __VDOREC_FEATURE_WB_CLOUD__
    #define __VDOREC_FEATURE_WB_INCANDESCENCE__

    /******* customizable ev *********/
    /* default will have off [ev 0] and [ev +1] [ev -1] menu if __VDOREC_FEATURE_EV__ is turn on */
    #define __VDOREC_FEATURE_EV_2__
    #define __VDOREC_FEATURE_EV_3__
    #define __VDOREC_FEATURE_EV_4__

    /******* customizable effect *********/
    #define __VDOREC_FEATURE_EFFECT_NORMAL__
    //#define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    //#define __VDOREC_FEATURE_EFFECT_SEPIA__
    //#define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    //#define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    //#define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    //#define __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    //#define __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    //#define __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    //#define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    //#define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    //#define __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    //#define __VDOREC_FEATURE_EFFECT_CONTRAST__
    //#define __VDOREC_FEATURE_EFFECT_JEAN__    
    //#define __VDOREC_FEATURE_EFFECT_SKETCH__
    //#define __VDOREC_FEATURE_EFFECT_OIL__ 


    /******* customizable size limit *********/
    //#define VDOREC_FEATURE_SIZE_LIMIT_1           (25)            /* 25k */
    //#define VDOREC_FEATURE_SIZE_LIMIT_2           (50)            /* 50k */
    //#define VDOREC_FEATURE_SIZE_LIMIT_3           (200)           /* 200k */

    /******* customizable time limit *********/
    //#define VDOREC_FEATURE_TIME_LIMIT_1           (15)            /* 15 sec */
    //#define VDOREC_FEATURE_TIME_LIMIT_2           (30)            /* 30 sec */
    //#define VDOREC_FEATURE_TIME_LIMIT_3           (60)            /* 60 sec */
    

    /******* SubLCD ********/
    #ifdef __MMI_SUBLCD__
    //  #define __VDOREC_FEATURE_SELF_RECORD__  /* not implement yet */
    #endif /* __MMI_SUBLCD__ */

    #define VDOREC_RECORD_KEY                   (KEY_CAMERA)
    #define VDOREC_RECORD_EXTRA_KEY1            (KEY_IP)            /* if no extra, use -1 */
    #define VDOREC_RECORD_EXTRA_KEY2            (-1)                /* if no extra, use -1 */
    
    #define VDOREC_EFFECT_KEY                   (KEY_1)         /* if no use hotkey, set -1 */
    #define VDOREC_WB_KEY                       (KEY_2)
    #define VDOREC_NIGHT_KEY                    (KEY_4)
    #define VDOREC_LED_HIGHLIGHT_KEY            (KEY_3)
    
    /***************************************************************************** 
    *   Default Setting 
    *****************************************************************************/
    /*********** Preview ***********/
    #define VDOREC_DEFAULT_SETTING_ZOOM                 (0)  /* index - start from 0 */

    #define VDOREC_DEFAULT_SETTING_WB                   VDOREC_SETTING_WB_AUTO
    #define VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT        VDOREC_SETTING_LED_HIGHLIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_EV                   VDOREC_SETTING_EV_ZERO      
    #define VDOREC_DEFAULT_SETTING_NIGHT                VDOREC_SETTING_NIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_BANDING              VDOREC_SETTING_BANDING_60HZ

    #define VDOREC_DEFAULT_SETTING_EFFECT               VDOREC_SETTING_EFFECT_NORMAL

    #define VDOREC_DEFAULT_SETTING_VIDEO_SIZE           VDOREC_SETTING_VIDEO_SIZE_QCIF
    #define VDOREC_DEFAULT_SETTING_VIDEO_QTY            VDOREC_SETTING_VIDEO_QTY_NORMAL
    #define VDOREC_DEFAULT_SETTING_SIZE_LIMIT           VDOREC_SETTING_SIZE_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_TIME_LIMIT           VDOREC_SETTING_TIME_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_RECORD_AUD           VDOREC_SETTING_RECORD_AUD_ON
    #define VDOREC_DEFAULT_SETTING_VIDEO_FORMAT         VDOREC_SETTING_VIDEO_FORMAT_MP4
    #define VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME      VDOREC_SETTING_COLOR_IDX_FRAME_OFF
    #define VDOREC_DEFAULT_SETTING_STORAGE              VDOREC_SETTING_STORAGE_PHONE

    #define VDOREC_DEFAULT_PREVIEW_LED_VALUE            (80)

    /* preview rotation */
    #if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #else /* not define SENSOR_ROTATION */
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #endif /* SENSOR_ROTATION */


    /***************************************************************************** 
    * Video Player Feature
    *****************************************************************************/
    #define __VDOPLY_FEATURE_SPEED__
    //#define __VDOPLY_FEATURE_VOLUME__
    //#define __VDOPLY_FEATURE_FULLSCREEN__
    //#define __VDOPLY_FEATURE_SNAPSHOT__

    #define VDOPLY_FEATURE_SPEED_COUNT  (0)     /* not used */
    #define VDOPLY_DEFAULT_SPEED        (0)     /* not used */
    
    #define VDOPLY_FEATURE_SPEED_0      (0)
    #define VDOPLY_FEATURE_SPEED_1      (0)
    #define VDOPLY_FEATURE_SPEED_2      (0)
    #define VDOPLY_FEATURE_SPEED_3      (0)
    #define VDOPLY_FEATURE_SPEED_4      (0)
    #define VDOPLY_FEATURE_SPEED_5      (0)
    #define VDOPLY_FEATURE_SPEED_6      (0)
    #define VDOPLY_FEATURE_SPEED_7      (0)
    #define VDOPLY_FEATURE_SPEED_8      (0)

    #define VDOPLY_SNAP_EXTRA_KEY       (-1)    /* if no extra, use -1 */
    
    /***************************************************************************** 
    *
    * End of Undefine Camera Module 
    *
    *****************************************************************************/
    #endif /* Camera module type */
    


#elif defined(ISP_SUPPORT) && defined(MJPG_SUPPORT)
/***************************************************************************** 
*
*
* MT6225
* Note: only support up to 176x144 LCM size
*
*****************************************************************************/
    /***************************************************************************** 
    * Video Recorder Feature
    *****************************************************************************/
    #ifdef __MMI_TOUCH_SCREEN__
        #define __VDOREC_FEATURE_TOUCH_SCREEN__
    #endif /* __MMI_TOUCH_SCREEN__ */

    #ifdef HORIZONTAL_CAMERA
        #define __VDOREC_FEATURE_HORIZONTAL_VIEW__
    #endif /* HORIZONTAL_CAMERA */

    #define __VDOREC_FEATURE_ZOOM__
    #define __VDOREC_FEATURE_WB__
    #define __VDOREC_FEATURE_EV__
    #define __VDOREC_FEATURE_NIGHT__
    
    #ifdef LED_ONOFF_SUPPOR
        //#define __VDOREC_FEATURE_LED_HIGHLIGHT__
    #endif
    
    #define __VDOREC_FEATURE_BANDING__   
    #define __VDOREC_FEATURE_VIDEO_QTY__
    //#define __VDOREC_FEATURE_SIZE_LIMIT__     /* not used */   
    //#define __VDOREC_FEATURE_TIME_LIMIT__     /* not used */   
    //#define __VDOREC_FEATURE_RECORD_AUD__     /* not used */   
    //#define __VDOREC_FEATURE_VIDEO_FORMAT__   /* not used */   
    #define __VDOREC_FEATURE_EFFECT__

    #if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
        #define __VDOREC_FEATURE_STORAGE__
    #endif
    
    #if(defined(__MMI_MMS__) && defined(__MMI_WGUI_CSK_ENABLE__))
        #define __MMI_VDOREC_MMS_SUPPORT__
    #endif


    //#define __VDOREC_FEATURE_MERGE_MENU__         /* not used */
    #define __VDOREC_FEATURE_RECORDING_ZOOM__    
    #define __VDOREC_FEATURE_RECORDING_EV__       

    /***************************************************************************** 
    * Zoom
    *****************************************************************************/
    #define VDOREC_FEATURE_ZOOM_COUNT           (16)
    #define VDOREC_FEAUTRE_ZOOM_LIMIT           (40)

    #define VDOREC_FEATURE_ZOOM_0               (10)
    #define VDOREC_FEATURE_ZOOM_1               (12)
    #define VDOREC_FEATURE_ZOOM_2               (14)
    #define VDOREC_FEATURE_ZOOM_3               (16)
    #define VDOREC_FEATURE_ZOOM_4               (18)
    #define VDOREC_FEATURE_ZOOM_5               (20)
    #define VDOREC_FEATURE_ZOOM_6               (22)
    #define VDOREC_FEATURE_ZOOM_7               (24)
    #define VDOREC_FEATURE_ZOOM_8               (26)
    #define VDOREC_FEATURE_ZOOM_9               (28)
    #define VDOREC_FEATURE_ZOOM_10              (30)
    #define VDOREC_FEATURE_ZOOM_11              (32)
    #define VDOREC_FEATURE_ZOOM_12              (34)
    #define VDOREC_FEATURE_ZOOM_13              (36)
    #define VDOREC_FEATURE_ZOOM_14              (38)
    #define VDOREC_FEATURE_ZOOM_15              (40)
    #define VDOREC_FEATURE_ZOOM_16              (0)
    #define VDOREC_FEATURE_ZOOM_17              (0)
    #define VDOREC_FEATURE_ZOOM_18              (0)
    #define VDOREC_FEATURE_ZOOM_19              (0)
    #define VDOREC_FEATURE_ZOOM_20              (0)
    #define VDOREC_FEATURE_ZOOM_21              (0)
    #define VDOREC_FEATURE_ZOOM_22              (0)
    #define VDOREC_FEATURE_ZOOM_23              (0)
    #define VDOREC_FEATURE_ZOOM_24              (0)
    #define VDOREC_FEATURE_ZOOM_25              (0)
    #define VDOREC_FEATURE_ZOOM_26              (0)
    #define VDOREC_FEATURE_ZOOM_27              (0)
    #define VDOREC_FEATURE_ZOOM_28              (0)
    #define VDOREC_FEATURE_ZOOM_29              (0)
    #define VDOREC_FEATURE_ZOOM_30              (0)
    #define VDOREC_FEATURE_ZOOM_31              (0)
    #define VDOREC_FEATURE_ZOOM_32              (0)
    #define VDOREC_FEATURE_ZOOM_33              (0)
    #define VDOREC_FEATURE_ZOOM_34              (0)
    #define VDOREC_FEATURE_ZOOM_35              (0)   


    /***************************************************************************** 
    * CamCoder Setting
    *****************************************************************************/
    /******** customizable led highlight *********/
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__   /* may turn on if HW support LED */
    #ifdef HORIZONTAL_CAMERA
        //#define __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    #else
        //#define __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__
    #endif


    /***************************************************************************** 
    * Video Recorder Setting
    *****************************************************************************/
    /******* customizable video qualtiy *********/
    //#define __VDOREC_FEATURE_VIDEO_QTY_FINE__
    #define __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    #define __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    #define __VDOREC_FEATURE_VIDEO_QTY_LOW__

    /******** customizable wb *********/
    #define __VDOREC_FEATURE_WB_AUTO__
    #define __VDOREC_FEATURE_WB_DAYLIGHT__
    #define __VDOREC_FEATURE_WB_TUNGSTEN__
    #define __VDOREC_FEATURE_WB_FLUORESCENT__
    #define __VDOREC_FEATURE_WB_CLOUD__
    #define __VDOREC_FEATURE_WB_INCANDESCENCE__

    /******* customizable ev *********/
    /* default will have off [ev 0] and [ev +1] [ev -1] menu if __VDOREC_FEATURE_EV__ is turn on */
    #define __VDOREC_FEATURE_EV_2__
    #define __VDOREC_FEATURE_EV_3__
    #define __VDOREC_FEATURE_EV_4__


    /******* customizable effect *********/
    /* YUV sensor only support partial effect */
    #define __VDOREC_FEATURE_EFFECT_NORMAL__
    #define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    #define __VDOREC_FEATURE_EFFECT_SEPIA__
    #define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    #define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    #define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    //#define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    //#define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    //#define __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    //#define __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    //#define __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    //#define __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    //#define __VDOREC_FEATURE_EFFECT_CONTRAST__
    //#define __VDOREC_FEATURE_EFFECT_SKETCH__

    /******* customizable size limit *********/
    //#define VDOREC_FEATURE_SIZE_LIMIT_1             (0)           /* not used */
    //#define VDOREC_FEATURE_SIZE_LIMIT_2             (0)           /* not used */
    //#define VDOREC_FEATURE_SIZE_LIMIT_3             (0)           /* not used */

    /******* customizable time limit *********/
    //#define VDOREC_FEATURE_TIME_LIMIT_1             (0)            /* not used */
    //#define VDOREC_FEATURE_TIME_LIMIT_2             (0)            /* not used */
    //#define VDOREC_FEATURE_TIME_LIMIT_3             (0)            /* not used */
    
    /******* SubLCD ********/
    #ifdef __MMI_SUBLCD__
    //  #define __VDOREC_FEATURE_SELF_RECORD__  /* not implement yet */
    #endif /* __MMI_SUBLCD__ */

    #define VDOREC_RECORD_KEY                   (KEY_CAMERA)
    #define VDOREC_RECORD_EXTRA_KEY1            (KEY_IP)            /* if no extra, use -1 */
    #define VDOREC_RECORD_EXTRA_KEY2            (KEY_POWER)         /* if no extra, use -1 */
    
    #define VDOREC_EFFECT_KEY                   (KEY_1)         /* if no use hotkey, set -1 */
    #define VDOREC_WB_KEY                       (KEY_2)
    #define VDOREC_NIGHT_KEY                    (KEY_4)
    #define VDOREC_LED_HIGHLIGHT_KEY            (KEY_3)
    
    /***************************************************************************** 
    *   Default Setting 
    *****************************************************************************/
    /*********** Preview ***********/
    #define VDOREC_DEFAULT_SETTING_ZOOM                 (0) /* index - start from 0 */

    #define VDOREC_DEFAULT_SETTING_WB                   VDOREC_SETTING_WB_AUTO
    #define VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT        VDOREC_SETTING_LED_HIGHLIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_EV                   VDOREC_SETTING_EV_ZERO      
    #define VDOREC_DEFAULT_SETTING_NIGHT                VDOREC_SETTING_NIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_BANDING              VDOREC_SETTING_BANDING_60HZ

    #define VDOREC_DEFAULT_SETTING_EFFECT               VDOREC_SETTING_EFFECT_NORMAL

    #define VDOREC_DEFAULT_SETTING_VIDEO_SIZE           VDOREC_SETTING_VIDEO_SIZE_QCIF      /* not used */
    #define VDOREC_DEFAULT_SETTING_VIDEO_QTY            VDOREC_SETTING_VIDEO_QTY_NORMAL
    #define VDOREC_DEFAULT_SETTING_SIZE_LIMIT           VDOREC_SETTING_SIZE_LIMIT_NO_LIMIT  /* not used */
    #define VDOREC_DEFAULT_SETTING_TIME_LIMIT           VDOREC_SETTING_TIME_LIMIT_NO_LIMIT  /* not used */
    #define VDOREC_DEFAULT_SETTING_RECORD_AUD           VDOREC_SETTING_RECORD_AUD_ON        /* not used */      
    #define VDOREC_DEFAULT_SETTING_VIDEO_FORMAT         VDOREC_SETTING_VIDEO_FORMAT_MP4     /* not used */
    #define VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME      VDOREC_SETTING_COLOR_IDX_FRAME_OFF  /* not used */

    #define VDOREC_DEFAULT_SETTING_STORAGE              VDOREC_SETTING_STORAGE_PHONE

    #define VDOREC_DEFAULT_PREVIEW_LED_VALUE            (80)

    /* preview rotation */
    #if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #else /* not define SENSOR_ROTATION */
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #endif /* SENSOR_ROTATION */



    /***************************************************************************** 
    * Video Player Feature
    *****************************************************************************/
    #ifdef __MMI_TOUCH_SCREEN__
        #define __VDOPLY_FEATURE_TOUCH_SCREEN__
    #endif /* __MMI_TOUCH_SCREEN__ */

    #ifdef HORIZONTAL_CAMERA
    //  #define __VDOPLY_FEATURE_HORIZONTAL_VIEW__  /* may trun on if needed */
    #endif /* HORIZONTAL_CAMERA */

    #if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)	|| (defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__))
        #define __VDOPLY_FEATURE_ENHNACE_OPTION__ 
    #endif
    
    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)|| defined(__VDOPLY_FEATURE_ENHNACE_OPTION__)
        #define __VDOPLY_FEATURE_LSK_OPTION__       /* allows LSK change to option */
    #endif
    
    #define __VDOPLY_FEATURE_SPEED__          
    #define __VDOPLY_FEATURE_VOLUME__
    
    #ifndef __MMI_MAINLCD_128X128__
        #define __VDOPLY_FEATURE_FULLSCREEN__
        #define __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__         /* hide fullscreen osd for better performance */        
    #endif

//    #define __VDOPLY_FEATURE_SNAPSHOT__
    #define __VDOPLY_FEATURE_VOLUME_MUTE__      /* allows audio mute */

    #define VDOPLY_FEATURE_SPEED_COUNT  (5)   
    #define VDOPLY_DEFAULT_SPEED        (1)     /* index - start from 0 */

    #define VDOPLY_FEATURE_SPEED_0      (50)
    #define VDOPLY_FEATURE_SPEED_1      (100)
    #define VDOPLY_FEATURE_SPEED_2      (200)
    #define VDOPLY_FEATURE_SPEED_3      (400)
    #define VDOPLY_FEATURE_SPEED_4      (800)
    #define VDOPLY_FEATURE_SPEED_5      (0)
    #define VDOPLY_FEATURE_SPEED_6      (0)
    #define VDOPLY_FEATURE_SPEED_7      (0)
    #define VDOPLY_FEATURE_SPEED_8      (0)

    #define VDOPLY_SNAP_EXTRA_KEY       (KEY_POWER) /* if no extra, use -1 */

#elif defined(ISP_SUPPORT) && defined(MP4_CODEC)
/***************************************************************************** 
*
*
* MT6219, MT6228
*
*
*****************************************************************************/

    /***************************************************************************** 
    *
    * Start of ISP 
    *
    *****************************************************************************/
    /***************************************************************************** 
    * Video Recorder Feature
    *****************************************************************************/

#ifdef __MMI_MAINLCD_240X320__
    #define __VDOREC_FEATURE_HIDE_OSD__
    #define __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__
#endif /* __MMI_MAINLCD_240X320__ */

    #ifdef __MMI_TOUCH_SCREEN__
        #define __VDOREC_FEATURE_TOUCH_SCREEN__
    #endif /* __MMI_TOUCH_SCREEN__ */

    #ifdef HORIZONTAL_CAMERA
        #define __VDOREC_FEATURE_HORIZONTAL_VIEW__
    #endif /* HORIZONTAL_CAMERA */

    #define __VDOREC_FEATURE_ZOOM__
    #define __VDOREC_FEATURE_WB__
    #define __VDOREC_FEATURE_EV__
    #define __VDOREC_FEATURE_NIGHT__
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT__
    #define __VDOREC_FEATURE_BANDING__   
    
    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)
        #define __VDOREC_FEATURE_VIDEO_SIZE__
    #endif
    
    #define __VDOREC_FEATURE_VIDEO_QTY__
    #define __VDOREC_FEATURE_SIZE_LIMIT__
    #define __VDOREC_FEATURE_TIME_LIMIT__
    #define __VDOREC_FEATURE_RECORD_AUD__
    #define __VDOREC_FEATURE_VIDEO_FORMAT__
    #define __VDOREC_FEATURE_EFFECT__

    #if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
        #define __VDOREC_FEATURE_STORAGE__
    #endif
    
    #if(defined(__MMI_MMS__) && defined(__MMI_WGUI_CSK_ENABLE__))
        #define __MMI_VDOREC_MMS_SUPPORT__
    #endif

    //#define __VDOREC_FEATURE_MERGE_MENU__     /* will merge "Camcoder Setting" & "Video Setting" into one */
    #define __VDOREC_FEATURE_RECORDING_ZOOM__       /* allows zooming while recording */
    #define __VDOREC_FEATURE_RECORDING_EV__     /* allows adjust ev while recording */

    /***************************************************************************** 
    * Zoom
    *****************************************************************************/
    #define VDOREC_FEATURE_ZOOM_COUNT           (36)
    #define VDOREC_FEAUTRE_ZOOM_LIMIT           (80)

    #define VDOREC_FEATURE_ZOOM_0               (10)
    #define VDOREC_FEATURE_ZOOM_1               (12)
    #define VDOREC_FEATURE_ZOOM_2               (14)
    #define VDOREC_FEATURE_ZOOM_3               (16)
    #define VDOREC_FEATURE_ZOOM_4               (18)
    #define VDOREC_FEATURE_ZOOM_5               (20)
    #define VDOREC_FEATURE_ZOOM_6               (22)
    #define VDOREC_FEATURE_ZOOM_7               (24)
    #define VDOREC_FEATURE_ZOOM_8               (26)
    #define VDOREC_FEATURE_ZOOM_9               (28)
    #define VDOREC_FEATURE_ZOOM_10              (30)
    #define VDOREC_FEATURE_ZOOM_11              (32)
    #define VDOREC_FEATURE_ZOOM_12              (34)
    #define VDOREC_FEATURE_ZOOM_13              (36)
    #define VDOREC_FEATURE_ZOOM_14              (38)
    #define VDOREC_FEATURE_ZOOM_15              (40)
    #define VDOREC_FEATURE_ZOOM_16              (42)
    #define VDOREC_FEATURE_ZOOM_17              (44)
    #define VDOREC_FEATURE_ZOOM_18              (46)
    #define VDOREC_FEATURE_ZOOM_19              (48)
    #define VDOREC_FEATURE_ZOOM_20              (50)
    #define VDOREC_FEATURE_ZOOM_21              (52)
    #define VDOREC_FEATURE_ZOOM_22              (54)
    #define VDOREC_FEATURE_ZOOM_23              (56)
    #define VDOREC_FEATURE_ZOOM_24              (58)
    #define VDOREC_FEATURE_ZOOM_25              (60)
    #define VDOREC_FEATURE_ZOOM_26              (62)
    #define VDOREC_FEATURE_ZOOM_27              (64)
    #define VDOREC_FEATURE_ZOOM_28              (66)
    #define VDOREC_FEATURE_ZOOM_29              (68)
    #define VDOREC_FEATURE_ZOOM_30              (70)
    #define VDOREC_FEATURE_ZOOM_31              (72)
    #define VDOREC_FEATURE_ZOOM_32              (74)
    #define VDOREC_FEATURE_ZOOM_33              (76)
    #define VDOREC_FEATURE_ZOOM_34              (78)
    #define VDOREC_FEATURE_ZOOM_35              (80)    


    /***************************************************************************** 
    * CamCoder Setting
    *****************************************************************************/
    /******** customizable led highlight *********/
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    //#define __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__


    /***************************************************************************** 
    * Video Recorder Setting
    *****************************************************************************/

    /******* customizable video size *********/ 
    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)
        /* 
         *  Disable SQCIF due to we dont add 128x96 overlay frame.
         * Disable QQVGA due to H.263 cant record 160x120 size .
         */ 
    
//      #define __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__     /* 128x96 */    
        #define __VDOREC_FEATURE_VIDEO_SIZE_QCIF__      /* 176x144 */
        #define __VDOREC_FEATURE_VIDEO_SIZE_CIF__       /* 352x288 */
//      #define __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__     /* 160x120 */

        //#define __VDOREC_COLOR_IDX_FRAME__
        #define __VDOREC_COLOR_IDX_FRAME_1__
        #define __VDOREC_COLOR_IDX_FRAME_2__
        #define __VDOREC_COLOR_IDX_FRAME_3__

        #define VDOREC_COLOR_IDX_FRAME_QVGA_WIDTH       (160)
        #define VDOREC_COLOR_IDX_FRAME_QVGA_HEIGHT      (120)
        #define VDOREC_COLOR_IDX_FRAME_QCIF_WIDTH       (176)
        #define VDOREC_COLOR_IDX_FRAME_QCIF_HEIGHT      (144)
    #endif /* MT6228 || MT6229 || MT6230 || MT6238 */
    
    /******* customizable video qualtiy *********/
    #define __VDOREC_FEATURE_VIDEO_QTY_FINE__
    #define __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    #define __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    #define __VDOREC_FEATURE_VIDEO_QTY_LOW__

    /******** customizable wb *********/
    #define __VDOREC_FEATURE_WB_AUTO__
    #define __VDOREC_FEATURE_WB_DAYLIGHT__
    #define __VDOREC_FEATURE_WB_TUNGSTEN__
    #define __VDOREC_FEATURE_WB_FLUORESCENT__
    #define __VDOREC_FEATURE_WB_CLOUD__
    #define __VDOREC_FEATURE_WB_INCANDESCENCE__

    /******* customizable ev *********/
    /* default will have off [ev 0] and [ev +1] [ev -1] menu if __VDOREC_FEATURE_EV__ is turn on */
    #define __VDOREC_FEATURE_EV_2__
    #define __VDOREC_FEATURE_EV_3__
    #define __VDOREC_FEATURE_EV_4__

#if defined(OV7660) && defined(YUV_SENSOR_SUPPORT)
    /* OV7660 YUV interface */
    #define __VDOREC_FEATURE_EFFECT_NORMAL__
    #define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    #define __VDOREC_FEATURE_EFFECT_SEPIA__
    #define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    #define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    #define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    #define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    #define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__  
#else
    /* MTK ISP */
    /******* customizable effect *********/
    #define __VDOREC_FEATURE_EFFECT_NORMAL__
    #define __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    #define __VDOREC_FEATURE_EFFECT_SEPIA__
    #define __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    #define __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    #define __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    #define __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    #define __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    #define __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    #define __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    #define __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    #define __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    #define __VDOREC_FEATURE_EFFECT_CONTRAST__
    //#define __VDOREC_FEATURE_EFFECT_JEAN__    /* turn of due some sensor might have problem */
    #define __VDOREC_FEATURE_EFFECT_SKETCH__
    //#define __VDOREC_FEATURE_EFFECT_OIL__ /* turn of due some sensor might have problem */
#endif 

    /******* customizable size limit *********/
    #define VDOREC_FEATURE_SIZE_LIMIT_1             (95)            /* 95k */
    #define VDOREC_FEATURE_SIZE_LIMIT_2             (195)           /* 195k */
    #define VDOREC_FEATURE_SIZE_LIMIT_3             (295)           /* 295k */

    /******* customizable time limit *********/
    #define VDOREC_FEATURE_TIME_LIMIT_1             (15)            /* 15 sec */
    #define VDOREC_FEATURE_TIME_LIMIT_2             (30)            /* 30 sec */
    #define VDOREC_FEATURE_TIME_LIMIT_3             (60)            /* 60 sec */
    

    /******* SubLCD ********/
    #ifdef __MMI_SUBLCD__
    //  #define __VDOREC_FEATURE_SELF_RECORD__  /* not implement yet */
    #endif /* __MMI_SUBLCD__ */

    #define VDOREC_RECORD_KEY                   (KEY_CAMERA)
    #define VDOREC_RECORD_EXTRA_KEY1            (KEY_IP)            /* if no extra, use -1 */
    #define VDOREC_RECORD_EXTRA_KEY2            (-1)                /* if no extra, use -1 */

#ifdef __VDOREC_FEATURE_HIDE_OSD__  
    /* if we hide osd, we also disable hotkey, it is hard for user to use hotkey without hint*/
    #define VDOREC_EFFECT_KEY                   (-1)            /* if no use hotkey, set -1 */
    #define VDOREC_WB_KEY                       (-1)
    #define VDOREC_NIGHT_KEY                    (-1)
    #define VDOREC_LED_HIGHLIGHT_KEY            (KEY_3)
#else
    #define VDOREC_EFFECT_KEY                   (KEY_1)         /* if no use hotkey, set -1 */
    #define VDOREC_WB_KEY                       (KEY_2)
    #define VDOREC_NIGHT_KEY                    (KEY_4)
    #define VDOREC_LED_HIGHLIGHT_KEY            (KEY_3)
#endif 

    
    /***************************************************************************** 
    *   Default Setting 
    *****************************************************************************/
    /*********** Preview ***********/
    #define VDOREC_DEFAULT_SETTING_ZOOM                 (0) /* index - start from 0 */

    #define VDOREC_DEFAULT_SETTING_WB                   VDOREC_SETTING_WB_AUTO
    #define VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT        VDOREC_SETTING_LED_HIGHLIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_EV                   VDOREC_SETTING_EV_ZERO      
    #define VDOREC_DEFAULT_SETTING_NIGHT                VDOREC_SETTING_NIGHT_OFF
    #define VDOREC_DEFAULT_SETTING_BANDING              VDOREC_SETTING_BANDING_60HZ

    #define VDOREC_DEFAULT_SETTING_EFFECT               VDOREC_SETTING_EFFECT_NORMAL

    #define VDOREC_DEFAULT_SETTING_VIDEO_SIZE           VDOREC_SETTING_VIDEO_SIZE_QCIF
    #define VDOREC_DEFAULT_SETTING_VIDEO_QTY            VDOREC_SETTING_VIDEO_QTY_NORMAL
    #define VDOREC_DEFAULT_SETTING_SIZE_LIMIT           VDOREC_SETTING_SIZE_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_TIME_LIMIT           VDOREC_SETTING_TIME_LIMIT_NO_LIMIT
    #define VDOREC_DEFAULT_SETTING_RECORD_AUD           VDOREC_SETTING_RECORD_AUD_ON
    #define VDOREC_DEFAULT_SETTING_VIDEO_FORMAT         VDOREC_SETTING_VIDEO_FORMAT_MP4
    #define VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME      VDOREC_SETTING_COLOR_IDX_FRAME_OFF

    #define VDOREC_DEFAULT_SETTING_STORAGE              VDOREC_SETTING_STORAGE_PHONE

    #define VDOREC_DEFAULT_PREVIEW_LED_VALUE            (80)



    /* preview rotation */
    #if defined(SENSOR_ON_BODY)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #endif
    #elif defined(SENSOR_ON_COVER)
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #else /* not define SENSOR_ROTATION */
        #if defined(SENSOR_ROTATE_0)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #elif defined(SENSOR_ROTATE_180)
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_180
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_180_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_0_MIRROR
        #else
            /* rotate 90, 270 not used yet */
            #define VDOREC_MAINLCD_ROTATE               VDOREC_PREVIEW_ROTATE_0
            #define VDOREC_SUBLCD_CLAM_OPEN_ROTATE      VDOREC_PREVIEW_ROTATE_0_MIRROR
            #define VDOREC_SUBLCD_CLAM_CLOSE_ROTATE     VDOREC_PREVIEW_ROTATE_180_MIRROR
        #endif
    #endif /* SENSOR_ROTATION */



    /***************************************************************************** 
    * Video Player Feature
    *****************************************************************************/
    #if defined(__MMI_MAINLCD_240X320__)
        #define __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        #define __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
    #elif defined(__MMI_MAINLCD_320X240__)
        #define __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
    #endif /* __MMI_MAINLCD_240X320__ */

    #if defined(__TEARING_REDUCTION_FB_IN_INTSRAM__) 
        /* for MoDIS, Target Only */
        #define __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__
    #endif 
        
    #ifdef __MMI_TOUCH_SCREEN__
        #define __VDOPLY_FEATURE_TOUCH_SCREEN__
    #endif /* __MMI_TOUCH_SCREEN__ */

    #ifdef HORIZONTAL_CAMERA
    //  #define __VDOPLY_FEATURE_HORIZONTAL_VIEW__
    #endif /* HORIZONTAL_CAMERA */

    #if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)	|| (defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__))
        #define __VDOPLY_FEATURE_ENHNACE_OPTION__ 
    #endif
    
    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(__VDOPLY_FEATURE_ENHNACE_OPTION__)
        #define __VDOPLY_FEATURE_LSK_OPTION__       /* allows LSK change to option */
    #endif
    
    #define __VDOPLY_FEATURE_SPEED__
    #define __VDOPLY_FEATURE_VOLUME__
    
    #ifndef __MMI_MAINLCD_128X128__
        #define __VDOPLY_FEATURE_FULLSCREEN__
    #endif

//    #define __VDOPLY_FEATURE_SNAPSHOT__

    #ifdef __MMI_VIDEO_STREAM__
        #define __VDOPLY_FEATURE_UDP_PORT__
        #define __VDOPLY_FEATURE_PREDEFINE_URL__    
    #endif /* __MMI_VIDEO_STREAM__ */

    /* misc config */
    #define __VDOPLY_FEATURE_VOLUME_MUTE__      /* allows audio mute */

    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)
        #define VDOPLY_FEATURE_SPEED_COUNT  (8) 
        #define VDOPLY_DEFAULT_SPEED        (2)  /* index - start from 0 */     
        
        #define VDOPLY_FEATURE_SPEED_0      (50)
        #define VDOPLY_FEATURE_SPEED_1      (75)
        #define VDOPLY_FEATURE_SPEED_2      (100)
        #define VDOPLY_FEATURE_SPEED_3      (125)
        #define VDOPLY_FEATURE_SPEED_4      (150)
        #define VDOPLY_FEATURE_SPEED_5      (200)
        #define VDOPLY_FEATURE_SPEED_6      (400)
        #define VDOPLY_FEATURE_SPEED_7      (800)
        #define VDOPLY_FEATURE_SPEED_8      (0)
    #else
        #define VDOPLY_FEATURE_SPEED_COUNT  (5)     
        #define VDOPLY_DEFAULT_SPEED        (1)  /* index - start from 0 */
    
        #define VDOPLY_FEATURE_SPEED_0      (50)
        #define VDOPLY_FEATURE_SPEED_1      (100)
        #define VDOPLY_FEATURE_SPEED_2      (200)
        #define VDOPLY_FEATURE_SPEED_3      (400)
        #define VDOPLY_FEATURE_SPEED_4      (800)
        #define VDOPLY_FEATURE_SPEED_5      (0)
        #define VDOPLY_FEATURE_SPEED_6      (0)
        #define VDOPLY_FEATURE_SPEED_7      (0)
        #define VDOPLY_FEATURE_SPEED_8      (0)
    #endif

    #define VDOPLY_SNAP_EXTRA_KEY           (-1)    /* if no extra, use -1 */


    /***************************************************************************** 
    *
    * End of ISP 
    *
    *****************************************************************************/

#else

    /* Do not have Camera module or ISP, only have video play feature */
    /***************************************************************************** 
    * Video Player Feature
    *****************************************************************************/
    #ifdef __MMI_TOUCH_SCREEN__
        #define __VDOPLY_FEATURE_TOUCH_SCREEN__
    #endif /* __MMI_TOUCH_SCREEN__ */
    
    #ifdef HORIZONTAL_CAMERA
        #define __VDOPLY_FEATURE_HORIZONTAL_VIEW__
    #endif /* HORIZONTAL_CAMERA */
    
    #define __VDOPLY_FEATURE_SPEED__
    #define __VDOPLY_FEATURE_VOLUME__
    
    #ifndef __MMI_MAINLCD_128X128__
        #define __VDOPLY_FEATURE_FULLSCREEN__
    #endif
    
//    #define __VDOPLY_FEATURE_SNAPSHOT__

    /* misc config */
    #define __VDOPLY_FEATURE_VOLUME_MUTE__      /* allows audio mute */

    #if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)	|| (defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__))
        #define __VDOPLY_FEATURE_ENHNACE_OPTION__ 
    #endif
    
    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(__VDOPLY_FEATURE_ENHNACE_OPTION__)
        #define __VDOPLY_FEATURE_LSK_OPTION__       /* allows LSK change to option */
    #endif
    

    #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238)  
        #define VDOPLY_FEATURE_SPEED_COUNT  (8) 
        #define VDOPLY_DEFAULT_SPEED        (2)  /* index - start from 0 */     
        
        #define VDOPLY_FEATURE_SPEED_0      (50)
        #define VDOPLY_FEATURE_SPEED_1      (75)
        #define VDOPLY_FEATURE_SPEED_2      (100)
        #define VDOPLY_FEATURE_SPEED_3      (125)
        #define VDOPLY_FEATURE_SPEED_4      (150)
        #define VDOPLY_FEATURE_SPEED_5      (200)
        #define VDOPLY_FEATURE_SPEED_6      (400)
        #define VDOPLY_FEATURE_SPEED_7      (800)
        #define VDOPLY_FEATURE_SPEED_8      (0)
    #else
        #define VDOPLY_FEATURE_SPEED_COUNT  (5)     
        #define VDOPLY_DEFAULT_SPEED        (1)  /* index - start from 0 */
    
        #define VDOPLY_FEATURE_SPEED_0      (50)
        #define VDOPLY_FEATURE_SPEED_1      (100)
        #define VDOPLY_FEATURE_SPEED_2      (200)
        #define VDOPLY_FEATURE_SPEED_3      (400)
        #define VDOPLY_FEATURE_SPEED_4      (800)
        #define VDOPLY_FEATURE_SPEED_5      (0)
        #define VDOPLY_FEATURE_SPEED_6      (0)
        #define VDOPLY_FEATURE_SPEED_7      (0)
        #define VDOPLY_FEATURE_SPEED_8      (0)
    #endif

    #define VDOPLY_SNAP_EXTRA_KEY           (-1)  /* if no extra, use -1 */
#endif /* CAMERA_MODULE, ISP_SUPPORT */


#endif /* __MMI_VIDEO_PLAYER__ || __MMI_VIDEO_RECORDER__ */
#endif /* _VIDEO_FEATURES_H_ */


