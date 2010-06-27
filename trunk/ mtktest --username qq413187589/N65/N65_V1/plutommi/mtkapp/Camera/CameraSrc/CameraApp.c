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
 *  CameraApp.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera Applications v0.3
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_CAMERA__



#include "lcd_if.h"                     /* LCD layer enable flag */
#include "lcd_sw_rnd.h"                 /* for LCD size */
#define __MMI_CAMERA_ONLY__
#include "MMI_features_camera.h"        /* features */


#include "nvram_data_items.h"           /* ID to store file path */

/* framework related headers */
#include "gui.h"                        /* Gui functions */
#include "SettingDefs.h"                /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"             /* SUCCESS_TONE define */
#include "wgui.h"                       /* for GetDateTime() */
#include "CommonScreens.h"              /* DisplayPopup() */
#include "gpioInc.h"                    /* LED */
#include "SettingProfile.h"
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"           /* file path */
#include "FileMgr.h"
#include "mmiapi_enum.h"                /* Stop LED */
#include "MainMenuDef.h"                /* Multimedia icon */
#include "ProfileGprots.h"              /* playRequestedTone */
#include "SimDetectionGprot.h"

#ifdef __SW_JPEG_CODEC_SUPPORT__
#include "jpeg.h"
#endif

#ifdef EXIF_SUPPORT
#include "exif.h"
#endif 
/* gdi, mid, camera app headers */
#include "gdi_image_jpeg.h"             /* jpeg decoder */
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_audio.h"
#ifdef __MMI_AUDIO_REVERB_EFFECT__
#include "SoundEffect.h"
#endif

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#ifdef __CAMERA_FEATURE_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#include "resource_camera_skins.h"      /* UI custom config */
#include "CameraGprot.h"
#include "CameraApp.h"                  /* camera app data */
#include "CameraMenu.h"                 /* function declare */
#include "CameraResDef.h"              /* resource ID def */
#include "ImageViewer.h"

#include "gui_setting.h"
#include "wgui.h"

#ifdef __MMI_SUBLCD_CAMERA__
#include "IdleAppProt.h"
#endif

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_FTS_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIFtpGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_FTS_SUPPORT__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_OPP_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIOppGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_OPP_SUPPORT__ */ 

#if defined(__CAMERA_OSD_HORIZONTAL__)
#include "ScreenRotationGprot.h"
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
#include "imgdma.h"
#endif 


#ifdef __MMI_CAMERA_MMS_SUPPORT__
#include "wapadp.h"
#endif 

#include "USBDeviceGprot.h"

#if (MDI_CAMERA_MT6227_SERIES || MDI_CAMERA_MT6225_SERIES)
#define MMI_CAMERA_CHECK_CONCURRENCY
#endif 


/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND                  (0)
#define HINT_POPUP_FADE_TIME           (1200)
#define TOGGLE_POPUP_FADE_TIME         (800)
#define DONE_POPUP_FADE_TIME           (1000)
#define CAMERA_ERR_CORRUPT_FAT         (-1)
#define CAMERA_ERR_PHONE_DISK_FULL     (-2)
#define CAMERA_ERR_CARD_DISK_FULL      (-3)
#define CAMERA_ERR_WRITE_PROTECT       (-4)
#define CAMERA_ERR_ROOT_DIR_FULL       (-5)
#define CAMERA_ERR_SAVE_FAIL           (-6)
#define CAMERA_ERR_BT_IS_WORKING        (-7)


#define POPLIST_LIST_SPACING           (1)

#define CAMERA_AF_LARGE_WIDTH             (32)
#define CAMERA_AF_NORMAL_WIDTH            (32)
#define CAMERA_AF_SMALL_WIDTH             (32)

#if defined(VC0558)
#define CAMEAR_BG_TRASN_COLOR       (0x0821)
#else 
#define CAMEAR_BG_TRASN_COLOR       (GDI_COLOR_TRANSPARENT)
#endif 

#define TRANSLATE_COORDINATE_TO_270(X,Y,TMP)\
            TMP=X;                          \
            X=Y;                            \
            Y=(LCD_WIDTH-1)-TMP;

#define BEFORE_PLAY_AUDIO()\
         g_camera_cntx.is_audio_finished=FALSE;
/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* camera application state */
typedef enum
{
    CAMERA_STATE_EXIT = 0,                  /* 0 */

    /* main lcd */
    CAMERA_STATE_PREVIEW,                   /* 1 */
    CAMERA_STATE_COUNTDOWN,                 /* 2 */
    CAMERA_STATE_CONTSHOT,                  /* 3 */
    CAMERA_STATE_BURSTSHOT,                 /* 4 */
    CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM,    /* 5 */
    CAMERA_STATE_BURSTSHOT_SAVING,          /* 6 */
    CAMERA_STATE_SAVE_DONE,                 /* 7 */
    CAMERA_STATE_SAVE_CONFIRM,              /* 8 */

    /* toggle popup */
    CAMERA_STATE_TOGGLE_TO_SUB,             /* 10 */
    CAMERA_STATE_TOGGLE_TO_MAIN,            /* 11 */

    /* sub lcd */
    CAMERA_STATE_SUB_PREVIEW,               /* 12 */
    CAMERA_STATE_SUB_COUNTDOWN,             /* 13 */
    CAMERA_STATE_SUB_CONTSHOT,              /* 14 */
    CAMERA_STATE_SUB_BURSTSHOT,             /* 15 */
    CAMERA_STATE_SUB_BURSTSHOT_SAVING       /* 16 */
} camera_state_enum;

#ifdef __MMI_SUBLCD_CAMERA__
typedef enum
{
    SUB_CAMERA_STATE_EXIT = 0,                  /* 0 */

    /* main lcd */
    SUB_CAMERA_STATE_PREVIEW,                   /* 1 */
    SUB_CAMERA_STATE_COUNTDOWN,                 /* 2 */
    SUB_CAMERA_STATE_CONTSHOT,                  /* 3 */
    SUB_CAMERA_STATE_BURSTSHOT,                 /* 4 */
    SUB_CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM,    /* 5 */
    SUB_CAMERA_STATE_BURSTSHOT_SAVING,          /* 6 */
    SUB_CAMERA_STATE_SAVE_DONE,                 /* 7 */
    SUB_CAMERA_STATE_SAVE_CONFIRM,              /* 8 */

} sublcd_camera_state_enum;
#endif


/****************************************************************************
* Setting command map                                                                
*****************************************************************************/
/* mapping mmi settings to mdi command. */
/*********** EV ***********/
const U8 camera_ev_command_map[CAMERA_SETTING_EV_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_EV_4__
    MDI_CAMERA_EV_N4,   /* CAMERA_SETTING_EV_N4 */
#endif 

#ifdef __CAMERA_FEATURE_EV_3__
    MDI_CAMERA_EV_N3,   /* CAMERA_SETTING_EV_N3 */
#endif 

#ifdef __CAMERA_FEATURE_EV_2__
    MDI_CAMERA_EV_N2,   /* CAMERA_SETTING_EV_N2 */
#endif 

    MDI_CAMERA_EV_N1,   /* CAMERA_SETTING_EV_N1 */
    MDI_CAMERA_EV_0,    /* CAMERA_SETTING_EV_0 */
    MDI_CAMERA_EV_P1,   /* CAMERA_SETTING_EV_P1 */

#ifdef __CAMERA_FEATURE_EV_2__
    MDI_CAMERA_EV_P2,   /* CAMERA_SETTING_EV_P2 */
#endif 

#ifdef __CAMERA_FEATURE_EV_3__
    MDI_CAMERA_EV_P3,   /* CAMERA_SETTING_EV_P3 */
#endif 

#ifdef __CAMERA_FEATURE_EV_4__
    MDI_CAMERA_EV_P4,   /* CAMERA_SETTING_EV_P4 */
#endif 

    DUMMY_COMMAND
};

/*********** EFFECT ***********/
const U8 camera_effect_command_map[CAMERA_SETTING_EFFECT_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
    MDI_CAMERA_EFFECT_NOMRAL,   /* CAMERA_SETTING_EFFECT_NOMRAL */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
    MDI_CAMERA_EFFECT_GRAYSCALE,    /* CAMERA_SETTING_EFFECT_GRAYSCALE */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
    MDI_CAMERA_EFFECT_SEPIA,    /* CAMERA_SETTING_EFFECT_SEPIA */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
    MDI_CAMERA_EFFECT_SEPIA_GREEN,  /* CAMERA_SETTING_EFFECT_SEPIA_GREEN */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
    MDI_CAMERA_EFFECT_SEPIA_BLUE,   /* CAMERA_SETTING_EFFECT_SEPIA_BLUE */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
    MDI_CAMERA_EFFECT_COLOR_INVERT, /* CAMERA_SETTING_EFFECT_COLOR_INVERT */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
    MDI_CAMERA_EFFECT_GRAY_INVERT,  /* CAMERA_SETTING_EFFECT_GRAY_INVERT */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
    MDI_CAMERA_EFFECT_BLACKBOARD,   /* CAMERA_SETTING_EFFECT_BLACKBOARD */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
    MDI_CAMERA_EFFECT_WHITEBOARD,   /* CAMERA_SETTING_EFFECT_WHITEBOARD */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
    MDI_CAMERA_EFFECT_COPPER_CARVING,   /* CAMERA_SETTING_EFFECT_COPPER_CARVING */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
    MDI_CAMERA_EFFECT_BLUE_CARVING, /* CAMERA_SETTING_EFFECT_BLUE_CARVING */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
    MDI_CAMERA_EFFECT_EMBOSSMENT,   /* CAMERA_SETTING_EFFECT_EMBOSSMENT */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
    MDI_CAMERA_EFFECT_CONTRAST, /* CAMERA_SETTING_EFFECT_CONTRAST */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_JEAN__
    MDI_CAMERA_EFFECT_JEAN, /* CAMERA_SETTING_EFFECT_JEAN */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
    MDI_CAMERA_EFFECT_SKETCH,   /* CAMERA_SETTING_EFFECT_SKETCH */
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_OIL__
    MDI_CAMERA_EFFECT_OIL,  /* CAMERA_SETTING_EFFECT_OIL */
#endif 

    DUMMY_COMMAND
};

/*********** WB ***********/
const U8 camera_wb_command_map[CAMERA_SETTING_WB_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_WB_AUTO__
    MDI_CAMERA_WB_AUTO, /* CAMREA_SETTING_WB_AUTO */
#endif 

#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
    MDI_CAMERA_WB_DAYLIGHT, /* CAMERA_SETTING_WB_DAYLIGHT */
#endif 

#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
    MDI_CAMERA_WB_TUNGSTEN, /* CAMERA_SETTING_WB_TUNGSTEN */
#endif 

#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
    MDI_CAMERA_WB_FLUORESCENT,  /* CAMERA_SETTING_WB_FLUORESCENT */
#endif 

#ifdef __CAMERA_FEATURE_WB_CLOUD__
    MDI_CAMERA_WB_CLOUD,    /* CAMERA_SETTING_WB_CLOUD */
#endif 

#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
    MDI_CAMERA_WB_INCANDESCENCE,    /* CAMERA_SETTING_WB_INCANDESCENCE */
#endif 

#ifdef __CAMERA_FEATURE_WB_MANUAL__
    MDI_CAMERA_WB_MANUAL,   /* MDI_CAMERA_WB_MANUAL */
#endif 

    DUMMY_COMMAND
};

/*********** Image Qty ***********/
const U8 camera_image_qty_command_map[CAMERA_SETTING_IMAGE_QTY_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
    MDI_CAMERA_JPG_QTY_LOW, /* CAMERA_SETTING_IMAGE_QTY_LOW */
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
    MDI_CAMERA_JPG_QTY_NORMAL,  /* CAMERA_SETTING_IMAGE_QTY_NORMAL */
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
    MDI_CAMERA_JPG_QTY_HIGH,    /* CAMERA_SETTING_IMAGE_QTY_HIGH */
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
    MDI_CAMERA_JPG_QTY_FINE,    /* CAMREA_SETTING_IMAGE_QTY_FINE */
#endif 

    DUMMY_COMMAND
};

/*********** Banding ***********/
const U8 camera_banding_command_map[CAMERA_SETTING_BANDING_COUNT + 1] = 
{
    MDI_CAMERA_BANDING_50HZ,
    MDI_CAMERA_BANDING_60HZ,
    DUMMY_COMMAND
};

/*********** AE meter ***********/
const U8 camera_ae_meter_command_map[CAMERA_SETTING_AE_METER_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_AE_METER_AUTO__
    MDI_CAMERA_AE_METER_AUTO,   /* CAMERA_SETTING_AE_METER_AUTO */
#endif 

#ifdef __CAMERA_FEATURE_AE_METER_SPOT__
    MDI_CAMERA_AE_METER_SPOT,   /* CAMERA_SETTING_AE_METER_SPOT */
#endif 

#ifdef __CAMERA_FEATURE_AE_METER_CENTER__
    MDI_CAMERA_AE_METER_CENTER, /* CAMERA_SETTING_AE_METER_CENTER */
#endif 

#ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
    MDI_CAMERA_AE_METER_AVERAGE,    /* CAMERA_SETTING_AE_METER_AVERAGE */
#endif 

    DUMMY_COMMAND
};

/*********** Flash ***********/
const U8 camera_flash_command_map[CAMERA_SETTING_FLASH_COUNT + 1] = 
{
    MDI_CAMERA_FLASH_OFF,   /* CAMERA_SETTING_FLASH_OFF */
    MDI_CAMERA_FLASH_ON,    /* CAMERA_SETTING_FLASH_ON */

#ifdef __CAMERA_FEATURE_FLASH_AUTO__
    MDI_CAMERA_FLASH_AUTO,  /* CAMERA_SETTING_FLASH_AUTO */
#endif 

#ifdef __CAMERA_FEATURE_FLASH_REDEYE__
    MDI_CAMERA_FLASH_REDEYE,    /* CAMERA_SETTING_FLASH_REDEYE */
#endif 

    DUMMY_COMMAND
};

/*********** ISO ***********/
const U8 camera_iso_command_map[CAMERA_SETTING_ISO_COUNT + 1] = 
{
#ifdef __CAEMRA_FEATURE_ISO_AUTO__
    MDI_CAMERA_ISO_AUTO,    /* CAMERA_SETTING_ISO_AUTO */
#endif 

#ifdef __CAEMRA_FEATURE_ISO_100__
    MDI_CAMERA_ISO_100, /* CAMERA_SETTING_ISO_100 */
#endif 

#ifdef __CAEMRA_FEATURE_ISO_200__
    MDI_CAMERA_ISO_200, /* CAMERA_SETTING_ISO_200 */
#endif 

#ifdef __CAEMRA_FEATURE_ISO_400__
    MDI_CAMERA_ISO_400, /* CAMERA_SETTING_ISO_400 */
#endif 

    DUMMY_COMMAND
};

const U8 camera_autofocus_command_map[CAMERA_SETTING_AUTOFOCUS_COUNT + 1] = 
{
#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
    MDI_CAMERA_AUTOFOCUS_1_ZONE,
#endif 
#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
    MDI_CAMERA_AUTOFOCUS_3_ZONE,
#endif 
#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
    MDI_CAMERA_AUTOFOCUS_5_ZONE,
#endif 
    DUMMY_COMMAND
};

const U8 camera_autofocus_mode_command_map[CAMERA_SETTING_AUTOFOCUS_MODE_COUNT + 1] = 
{
#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
    MDI_CAMERA_AUTOFOCUS_MODE_AUTO,
#endif 
#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
    MDI_CAMERA_AUTOFOCUS_MODE_MACRO,
#endif 
#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
    MDI_CAMERA_AUTOFOCUS_MODE_INFINITE,
#endif 
#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    MDI_CAMERA_AUTOFOCUS_MODE_MANUAL,
#endif 
    DUMMY_COMMAND
};

/*********** Shot Mode ***********/
const U8 camera_dsc_mode_command_map[CAMERA_SETTING_DSC_MODE_COUNT + 1] = 
{
#ifdef __CAMERA_DSC_MODE_AUTO__
    MDI_CAMERA_DSC_MODE_AUTO,           /* CAMERA_SETTING_DSC_MODE_AUTO */
#endif 
#ifdef __CAMERA_DSC_MODE_PORTRAIT__
    MDI_CAMERA_DSC_MODE_PORTRAIT,       /* CAMERA_SETTING_DSC_MODE_PORTRAIT */
#endif 
#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
    MDI_CAMERA_DSC_MODE_LANDSCAPE,      /* CAMERA_SETTING_DSC_MODE_LANDSCAPE */
#endif 
#ifdef __CAMERA_DSC_MODE_SPORT__
    MDI_CAMERA_DSC_MODE_SPORT,          /* CAMERA_SETTING_DSC_MODE_SPORT */
#endif 
#ifdef __CAMERA_DSC_MODE_FLOWER__
    MDI_CAMERA_DSC_MODE_FLOWER,         /* CAMERA_SETTING_DSC_MODE_FLOWER */
#endif 
#ifdef __CAMERA_DSC_MODE_NIGHT__
    MDI_CAMERA_DSC_MODE_NIGHT,          /* CAMERA_SETTING_DSC_MODE_NIGHT */
#endif 
#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
    MDI_CAMERA_DSC_MODE_SHUTTER_PRI,    /* CAMERA_SETTING_DSC_MODE_SHUTTER_PRI */
#endif 
#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
    MDI_CAMERA_DSC_MODE_APERTURE_PRI,   /* CAMERA_SETTING_DSC_MODE_APERTURE_PRI */
#endif 

    DUMMY_COMMAND
};

/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern BOOL r2lMMIFlag;

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);

extern kal_uint8 GpioCtrlReq(kal_uint8 action);
extern BOOL IsClamClose(void);
extern void SetClamState(U16 clam_state);
extern void AudioStopReq(U16 soundId);
extern U16 GetCurKeypadTone(void);
extern void GpioDetectInd(void *info);


#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL wgui_test_lsk_position(mmi_pen_point_struct pos);
#endif 

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* camera contex */
camera_context_struct g_camera_cntx;

#if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined(__CAMERA_DSC_MODE_APERTURE_PRI__)
camera_dsc_mode_inline_data_struct g_camera_dsc_mode_cntx;
#endif 

/*****************************************************************************
* Local Function 
*****************************************************************************/
#ifdef __CAMERA_FEATURE_XENON_FLASH__
static void mmi_camera_xenon_flash_callback(mdi_result result);
#endif

static U8 mmi_camera_del_scr_callback(void* ptr);

/* setting / path / stroage */
static BOOL mmi_camera_get_storage_disk_path(PS8 drv_buf);
static void mmi_camera_restore_filename_seq_no(void);
static void mmi_camera_get_next_filename(PS8 file_buf_p);
static void mmi_camera_display_error_popup(void);

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_display_sublcd_error_popup(void);
#endif 

static void mmi_camera_dummy_func(void);

/* app */
static void mmi_camera_hilight_app(void);
static U16 mmi_camera_get_img_size_str_id(S32 image_width, S32 image_height);
static void mmi_camera_exit_app_screen(void);
static void mmi_camera_enter_state(camera_state_enum state);
static void mmi_camera_exit_current_state(void);
U8 mmi_camera_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event);
static void mmi_camera_calc_remain_storage(void);

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_self_capture(void);
#endif 

static void mmi_camera_toggle_hide_osd(void);

static void mmi_camera_turn_on_preview_led_highlight(void);
static void mmi_camera_turn_on_capture_led_highlight(void);
static void mmi_camera_turn_off_led_highlight(void);

/* mainlcd preview state */
static void mmi_camera_entry_preview_state(void);
static void mmi_camera_exit_preview_state(void);
static void mmi_camera_preview_set_key_hdlr(void);
static void mmi_camera_preview_create_resource(void);
static void mmi_camera_preview_free_resource(void);
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
static void mmi_camera_create_osd_layer(void);
static void mmi_camera_free_osd_layer(void);
static void mmi_camera_init_osd_icon_layer_position(void);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

void mmi_camera_preview_create_preview_resource(S32 offset_x, S32 offset_y, S32 width, S32 height, U8 rotate);
void mmi_camera_preview_free_preview_resource(void);

static void mmi_camera_preview_start(void);
static void mmi_camera_preview_stop(void);
static void mmi_camera_preview_set_blt_layer(BOOL is_previewing);
static void mmi_camera_preview_clear_background(void);

static void mmi_camera_preview_flatten_layer(BOOL is_previewing);

static void mmi_camera_preview_draw_osd(void);
static void mmi_camera_preview_draw_title(void);
static void mmi_camera_preview_draw_softkey(void);
static void mmi_camera_preview_draw_hint(void);
static void mmi_camera_preview_draw_icon(void);

static void mmi_camera_preview_draw_osd_timer(void);
static S32 mmi_camera_get_zoom_total_level_cnt(void);
static U16 mmi_camera_get_zoom_limit(U16 capture_size_enum);

#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
static U16 mmi_camera_get_zoom_level_idx(S32 factor);
static void mmi_camera_start_fast_zoom_in(void);
static void mmi_camera_start_fast_zoom_out(void);
static void mmi_camera_stop_fast_zoom(void);
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
static void mmi_camera_preview_draw_contshot_countbar(void);
#endif 

static void mmi_camera_preview_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);
static void mmi_camera_preview_hide_hint(void);

static U16 mmi_camera_preview_get_zoom_factor(void);
static void mmi_camera_preview_ev_inc_key_press(void);
static void mmi_camera_preview_ev_inc_key_release(void);
static void mmi_camera_preview_ev_dec_key_press(void);
static void mmi_camera_preview_ev_dec_key_release(void);

#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_right_arrow_press(void);
static void mmi_camera_iconbar_right_arrow_release(void);
static void mmi_camera_iconbar_left_arrow_press(void);
static void mmi_camera_iconbar_left_arrow_releas(void);
static void mmi_camera_iconbar_up_arrow_press(void);
static void mmi_camera_iconbar_up_arrow_release(void);
static void mmi_camera_iconbar_down_arrow_press(void);
static void mmi_camera_iconbar_down_arrow_release(void);
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
static void mmi_camera_mf_forward(void);
static void mmi_camera_mf_backward(void);
static void mmi_camera_mf_stop(void);
static void mmi_camera_mf_forward_continue(void);
static void mmi_camera_mf_backward_continue(void);
#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 


/* static void mmi_camera_exec_function_key(camera_key_map2_function_enum key); */
#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
static void mmi_camera_toggle_updown_key(void);
#endif 

#ifdef __CAMERA_FEATURE_ZOOM__
static void mmi_camera_preview_zoom_in(void);
static void mmi_camera_preview_zoom_out(void);

#ifndef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_preview_up_arrow_press(void);
static void mmi_camera_preview_up_arrow_release(void);
static void mmi_camera_preview_down_arrow_press(void);
static void mmi_camera_preview_down_arrow_release(void);
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 
#endif /* __CAMERA_FEATURE_ZOOM__ */ 

/* hotkeys */
#ifndef __CAMERA_FEATURE_ICONBAR_PANEL__
#ifdef __CAMERA_FEATURE_EFFECT__
static void mmi_camera_preview_effect_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_WB__
static void mmi_camera_preview_wb_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
static void mmi_camera_preview_led_highlight_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_FLASH__
static void mmi_camera_preview_flash_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_NIGHT__
static void mmi_camera_preview_night_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT__
static void mmi_camera_preview_cont_shot_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
static void mmi_camera_preview_delay_timer_hotkey_press(void);
#endif 

static void mmi_camera_preview_image_qty_hotkey_press(void);
static void mmi_camera_preview_image_size_hotkey_press(void);

#ifdef __CAMERA_FEATURE_STORAGE__
static void mmi_camera_preview_storage_hotkey_press(void);
#endif 

#ifdef __CAMERA_AUTOFOCUS_MODE__
static void mmi_camera_preview_af_mode_hotkey_press(void);
#endif 

#ifdef __CAMERA_AUTOFOCUS_METERING__
static void mmi_camera_preview_af_meter_hotkey_press(void);
#endif 

#ifdef __CAMERA_DSC_MODE__
static void mmi_camera_preview_dsc_mode_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_hotkey_press(void);
#endif 

#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

#ifdef __MMI_CAMERA_AF_TEST__
static void mmi_camera_af_test(void);
static void mmi_camera_af_test_start(void);
#endif /* __MMI_CAMERA_AF_TEST__ */ 

#if defined(__AF_SUPPORT_ONE_KEY__) || defined(__MMI_CAMERA_AF_TEST__)
static void mmi_camera_af_and_capture(void);
#endif
#ifdef __CAMERA_AUTOFOCUS_MODE__
static void mmi_camera_preview_af_mode_change(BOOL is_next);
#endif 

#ifdef __CAMERA_AUTOFOCUS_METERING__
static void mmi_camera_preview_af_meter_change(BOOL is_next);
#endif 

#ifdef __CAMERA_DSC_MODE__
static void mmi_camera_preview_dsc_mode_change(BOOL is_next);
    #if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined (__CAMERA_DSC_MODE_APERTURE_PRI__)
    static void mmi_camera_init_advanced_dsc_mode(void);
    #endif
#endif /* __CAMERA_DSC_MODE__ */ 


#ifdef __CAMERA_FEATURE_EFFECT__
static void mmi_camera_preview_effect_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_WB__
static void mmi_camera_preview_wb_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
static void mmi_camera_preview_led_highlight_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_FLASH__
static void mmi_camera_preview_flash_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_NIGHT__
static void mmi_camera_preview_night_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT__
static void mmi_camera_preview_cont_shot_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
static void mmi_camera_preview_delay_timer_change(BOOL is_next);
#endif 

static void mmi_camera_preview_image_size_change(BOOL is_next);

static void mmi_camera_preview_image_qty_change(BOOL is_next);

#ifdef __CAMERA_FEATURE_STORAGE__
static void mmi_camera_preview_storage_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_create_add_frame_layer(void);
static void mmi_camera_free_add_frame_layer(void);
static void mmi_camera_draw_add_frame(void);
static void mmi_camera_preview_change_frame_up(void);
static void mmi_camera_preview_change_frame_down(void);
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
static void mmi_camera_draw_add_frame_color_idx(void);
static camera_overlay_frame_kind mmi_camera_get_overlay_frame_kind(void);
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

static void mmi_camera_preview_lsk_press(void);
static void mmi_camera_preview_lsk_release(void);
static void mmi_camera_preview_rsk_press(void);
static void mmi_camera_preview_rsk_release(void);

/* countdown state */
static void mmi_camera_entry_countdown_state(void);
static void mmi_camera_exit_countdown_state(void);
static void mmi_camera_countdown_cyclic(void);
static void mmi_camera_countdown_stop_LED(void);

#ifdef __COUNTDOWN_USING_MMA__
static void mmi_camera_init_countdown_mma(void);
static void mmi_camera_deinit_countdown_mma(void);
#endif

/* contshot state */
static void mmi_camera_entry_contshot_state(void);
static void mmi_camera_exit_contshot_state(void);
static void mmi_camera_contshot_cyclic(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
   /* burstshot state */
static void mmi_camera_entry_burstshot_capture_state(void);
static void mmi_camera_exit_burstshot_capture_state(void);

#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count);
static void mmi_camera_burstshot_close_multi_sound(void);
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

   /* burstshot save confirm state */
static void mmi_camera_entry_burstshot_save_confirm_state(void);
static void mmi_camera_exit_burstshot_save_confirm_state(void);
static void mmi_camera_burstshot_save_confirm_lsk_press(void);
static void mmi_camera_burstshot_save_confirm_lsk_release(void);
static void mmi_camera_burstshot_save_confirm_rsk_press(void);
static void mmi_camera_burstshot_save_confirm_rsk_release(void);

   /* burstshot saving state */
static void mmi_camera_entry_burstshot_saving_state(void);
static void mmi_camera_exit_burstshot_saving_state(void);
static void mmi_camera_burstshot_saving_cyclic(void);
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/* save confirm state */
static void mmi_camera_entry_save_confirm_state(void);
static void mmi_camera_exit_save_confirm_state(void);
static void mmi_camera_save_confirm_lsk_press(void);
static void mmi_camera_save_confirm_lsk_release(void);
static void mmi_camera_save_confirm_rsk_press(void);
static void mmi_camera_save_confirm_rsk_release(void);
static void mmi_camera_save_confirm_cancel_file(void);
static void mmi_camera_save_confirm_save_file(void);

#ifdef __MMI_CAMERA_MMS_SUPPORT__
static void mmi_camera_save_confirm_send_to_mms_press(void);
static void mmi_camera_save_confirm_send_to_mms_release(void);
static void mmi_camera_save_and_send_to_mms(void);
#endif /* __MMI_CAMERA_MMS_SUPPORT__ */ 

static void mmi_camera_update_osd_touch_icon(void);

/* capture */
static void mmi_camera_capture(void);
static void mmi_camera_capture_button_press(void);
static void mmi_camera_capture_button_release(void);

#ifdef __CAMERA_AUTOFOCUS__
static void mmi_camera_capture_button_autofocus_pressed(void);
static void mmi_camera_capture_button_autofocus_released(void);
static void mmi_camera_autofocus_callback(mdi_result pMsg);
static void mmi_camera_play_af_succeed_finished(void);
static void mmi_camera_draw_autofocus_process(void);
static void mmi_camera_preview_draw_osd_timer(void);
static void mmi_camera_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color);
#endif /* __CAMERA_AUTOFOCUS__ */ 


#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_capture_play_multi_channel_sound(void);
#endif 

/* save done */
static void mmi_camera_entry_save_done_state(void);
static void mmi_camera_exit_save_done_state(void);
static void mmi_camera_save_done_timeout(void);

#ifdef __MMI_SUBLCD__
   /* sub screen */
void mmi_camera_entry_sublcd_screen(void);
void mmi_camera_exit_sublcd_screen(void);
static void mmi_camera_sublcd_capture(void);
#endif /* __MMI_SUBLCD__ */ 


#if defined(DOUBLE_CAMERA_SUPPORT)
//Huyanwei Add It 

/*if  double camera ,default is main camera--jonathan*/
BOOL  mmi_main_camera_active=KAL_TRUE;  	//SUB Camera
U16 double_cam = 0  ;						// 添加双camera切换=( !mmi_main_camera_active)

S32 obj_w=16,obj_h=16;

#ifndef MMI_ON_WIN32
//Huyanwei Add It For PC
extern BOOL sub_camera_is_ready_polling(void);  /*UNI@bw060721 当sub camera不存在能够使用main camera*/
extern BOOL main_camera_is_ready_polling(void); /*UNI@bw060726 当main camera不存在也能够使用sub camera*/
#endif

void mmi_init_double_cam_info();
static void mmi_camera_preview_double_cam_key_press(void);

#endif


#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
   /* toggle to sub state */
static void mmi_camera_entry_toggle_to_sub_state(void);
static void mmi_camera_exit_toggle_to_sub_state(void);
static void mmi_camera_toggle_to_sub_timeout(void);

   /* toggle to main state */
static void mmi_camera_entry_toggle_to_main_state(void);
static void mmi_camera_exit_toggle_to_main_state(void);
static void mmi_camera_toggle_to_main_timeout(void);

   /* sublcd preview state */
static void mmi_camera_entry_sublcd_preview_state(void);
static void mmi_camera_exit_sublcd_preview_state(void);
static void mmi_camera_sublcd_preview_set_key_hdlr(void);
static void mmi_camera_sublcd_preview_start(void);
static void mmi_camera_sublcd_preview_stop(void);
static void mmi_camera_sublcd_preview_set_blt_layer(BOOL is_previewing);
static void mmi_camera_sublcd_preview_lsk_press(void);
static void mmi_camera_sublcd_preview_rsk_press(void);
static void mmi_camera_sublcd_preview_lsk_release(void);
static void mmi_camera_sublcd_preview_rsk_release(void);

   /* sublcd countdown state */
static void mmi_camera_entry_sublcd_countdown_state(void);
static void mmi_camera_exit_sublcd_countdown_state(void);
static void mmi_camera_sublcd_countdown_cyclic(void);
static void mmi_camera_sublcd_countdown_stop_LED(void);

   /* sublcd contshot state */
static void mmi_camera_entry_sublcd_contshot_state(void);
static void mmi_camera_exit_sublcd_contshot_state(void);
static void mmi_camera_sublcd_contshot_cyclic(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
      /* sublcd burstshot state */
static void mmi_camera_entry_sublcd_burstshot_state(void);
static void mmi_camera_exit_sublcd_burstshot_state(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__
static void mmi_camera_sublcd_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count);
#endif 

#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

   /* sublcd burstshot saving state */
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_sublcd_burstshot_saving_state(void);
static void mmi_camera_exit_sublcd_burstshot_saving_state(void);
static void mmi_camera_sublcd_burstshot_saving_cyclic(void);
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

   /* sublcd capture */
static void mmi_camera_sublcd_capture_button_press(void);
static void mmi_camera_sublcd_capture(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    static void mmi_camera_sublcd_tileshot_capture(void);
    #endif 
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
static void mmi_camera_tileshot_capture(void);
static void mmi_camera_init_tileshot_layer(void);
#endif


/* util draw */
static void mmi_camera_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, camera_style_text_struct *style_txt);
static void mmi_camera_initilize_zoom_factor(void);

#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_camera_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_camera_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_camera_touch_scr_hit_test(S32 pos_x, S32 pos_y, camera_ui_touch_struct *touch_obj);
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

/* screen snapshot */
#ifdef __MMI_SCREEN_SNAPSHOT__
static void mmi_camera_entry_scr_snapshot_screen(void);
static void mmi_camera_exit_scr_snapshot_screen(void);
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 
#if defined(__CAMERA_OSD_HORIZONTAL__)
static void mmi_camera_config_layer_orientation(void);
#endif
static void mmi_camera_free_app_mem(void);
static void mmi_camera_app_mem_stop_callback(void);
static void mmi_camera_app_mem_success_callback(void);
static void mmi_camera_pre_initialize_camera_environment(void);
static void mmi_camera_post_initialize_camera_environment(void);
static void mmi_camera_initialize_framework_environment(void);
static void mmi_camera_entry_app_screen_internal(void);
#ifdef __MMI_SUBLCD_CAMERA__
static void mmi_sublcd_camera_exit_option_screen(void);
static void mmi_sublcd_camera_entry_preview_screen(void);
static void mmi_sublcd_camera_entry_flash_screen(void);
static void mmi_sublcd_camera_flash_highlight_hdlr(S32 idx);
static void mmi_sublcd_camera_exit_flash_screen(void);
static void mmi_sublcd_camera_exit(void);
static void mmi_sublcd_camera_set_flash(void);
static void mmi_sublcd_camera_hilight_preview(void);
static void mmi_sublcd_camera_hilight_flash(void);
static void mmi_sublcd_camera_hilight_flash_option(void);
static void mmi_sublcd_camera_hilight_exit(void);
U8 mmi_sublcd_camera_clam_close_event_hdlr(void *ptr);
static void mmi_sublicd_camera_display_error_screen(void);
static void mmi_sublcd_camera_capture(void);
static void mmi_sublcd_camera_preview_start(void);
static void mmi_sublcd_camera_entry_flash_screen_ex(void);
static void mmi_sublcd_camera_entry_preview_screen_ex(void);
static void mmi_sublcd_camera_entry_option_screen_ex(void);



static void mmi_sublcd_camera_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);

    mmi_camera_turn_on_capture_led_highlight();

    g_camera_cntx.is_continue_capture = FALSE;
    g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);

    /* play capture sound after capture */
    mmi_camera_capture_play_sound();

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 

    mmi_camera_turn_off_led_highlight();

    /* captured, previwing is stopped, change blt layer */
    mmi_camera_sublcd_preview_set_blt_layer(FALSE);

    ClearKeyEvents();
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        FS_Delete((U16*) buf_filename);
        mmi_camera_restore_filename_seq_no();
        DisplaySubLcdPopup(IMG_GLOBAL_WARNING);
        DeleteSubLCDScreen(SCR_ID_CAMERA_SUBLCD_APP);
        ClearInputEventHandler(MMI_DEVICE_KEY);
        return;
    }
    mmi_sublcd_camera_preview_start();

}

static void mmi_sublcd_camera_preview_start(void)
{
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    S32 sublcd_width;
    S32 sublcd_height;

    #if defined(ISP_SUPPORT)
        /* set correct lcm rotate && config rotate of preview layer, only ISP_SUPPORT need */
        gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
        gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
        gdi_layer_pop_and_restore_active();
    #endif /* defined(ISP_SUPPORT) */ 
      
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_layer_get_dimension(&sublcd_width, &sublcd_height);
        gdi_layer_set_blt_layer(g_camera_cntx.sublcd_base_layer_handle, 0, 0, 0);

    #ifdef CAMERA_MODULE_WITH_LCD
        gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
    #endif 
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

        /* turn on led highlight */
        mmi_camera_turn_on_preview_led_highlight();


    mdi_camera_load_default_setting(&camera_setting_data);
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_SUBLCD;

    camera_setting_data.preview_width = SUBLCD_CAMERA_PREVIEW_WIDTH;
    camera_setting_data.preview_height = SUBLCD_CAMERA_PREVIEW_HEIGHT;
    camera_setting_data.preview_rotate = CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE;
    camera_setting_data.lcm_rotate = CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE;

    camera_setting_data.image_width = SUBLCD_CAMERA_CAPTURE_WIDTH;
    camera_setting_data.image_height = SUBLCD_CAMERA_CAPTURE_HEIGHT;

    camera_setting_data.continue_capture = g_camera_cntx.is_continue_capture;

    /* preview data for preview start */
    camera_preview_data.preview_layer_handle = g_camera_cntx.sublcd_base_layer_handle;
    camera_preview_data.preview_wnd_offset_x = 0;
    camera_preview_data.preview_wnd_offset_y = 0;
    camera_preview_data.preview_wnd_width = sublcd_width;
    camera_preview_data.preview_wnd_height = sublcd_height;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = CAMEAR_BG_TRASN_COLOR;/* this value is use only CAMERA_MODULE_WITH_LCD */
    camera_preview_data.is_tvout = FALSE;
    camera_preview_data.xenon_flash_status_callback = NULL;

    /* start preview */
    g_camera_cntx.last_error = mdi_camera_preview_start(
                                &camera_preview_data,
                                &camera_setting_data);

}
BOOL mmi_sublcd_camera_delete_screen_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnid;
    BOOL ret = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(scrnid= SCR_ID_CAMERA_SUBLCD_APP; scrnid <= SCR_ID_CAMERA_SUBLCD_OPTION_FLASH; scrnid++)
    {
        if (IsSubLCDScreenPresent(scrnid))
        {
            DeleteSubLCDScreen(scrnid);
            ret = TRUE;
        }
        else if (GetSubLCActiveScreenId()==scrnid)
            ret = TRUE;
    }

    return ret;
}
static void mmi_sublicd_camera_display_error_screen(void)
{
    DisplaySubLcdPopup(IMG_GLOBAL_WARNING);
    mmi_sublcd_camera_delete_screen_if_present();
}
U8 mmi_sublcd_camera_clam_close_event_hdlr(void *ptr)
{

}
static void mmi_sublcd_camera_set_flash(void)
{
    /* off */
    if(g_camera_cntx.cur_select_flash_idx == 1) 
    {
        #ifdef __CAMERA_FEATURE_FLASH__
        g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
        #endif
        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        g_camera_cntx.setting.led_highlight = CAMERA_SETTING_LED_HIGHLIGHT_OFF;
        #endif
    }
    else
    {
        #ifdef __CAMERA_FEATURE_FLASH__
        g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_ON;
        #endif
        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        g_camera_cntx.setting.led_highlight = CAMERA_SETTING_LED_HIGHLIGHT_ON;
        #endif
    }
    mmi_camera_store_setting();
    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    GoBackSubLCDHistory();
}
static void mmi_sublcd_camera_entry_preview_screen(void)
{
   DisplaySubLCDScreen(SCR_ID_CAMERA_SUBLCD_APP, mmi_sublcd_camera_entry_preview_screen_ex, 1);
}
static void mmi_sublcd_camera_entry_preview_screen_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 cur_storage;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_KEY);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    g_camera_cntx.is_sublcd_previewing = TRUE;

    /* turn off 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_camera_cntx.is_3d_sound_on = mmi_settings_audio_reverb_get_status();
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_off();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 

   /************ init/config framework's environment  ************/

    /* entry full screen app */
    entry_full_screen();

    /* 
     * This is used to solve a very rare situation. When playing a IMELODY 
     * with backlight on/off, and the screen previous to this screen is a 
     * horizontal screen. Before enter this screen, the IMELODY turn off the
     * backlight. While exit previous screen, the layer rotate back to normal
     * size and the content is not correct. So when calling TurnOnBacklight, 
     * LCD is in sleepin state and draw wrong content to LCD.
     * So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* stop LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_GET);

    /* get sublcd base layer handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    gdi_lcd_freeze(TRUE);
    /************ init camera app environment ************/
 
    /* init some flags */
    g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
    g_camera_cntx.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;

    /* load Setting */
    mmi_camera_load_setting();

    /* allocate storage path buffer */
    g_camera_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_camera_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
    // g_camera_cntx.imgview_old_storage = g_imgview_context.storage;

    if (mmi_camera_check_and_restore_valid_drv())
    {
        /* drv is valid, create directory */
        mmi_imgview_get_storage_file_path(g_camera_cntx.storage_filepath);
        create_result = mmi_imgview_create_file_dir(g_camera_cntx.storage_filepath);

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = CAMERA_ERR_WRITE_PROTECT;

            /* has error - restore to phone */
            g_imgview_context.storage =  MMI_PUBLIC_DRV;
        }
        else if (create_result == FS_DISK_FULL)
        {
            if (cur_storage == MMI_IMGVIEW_STORAGE_PHONE)
            {
                g_camera_cntx.last_error = CAMERA_ERR_PHONE_DISK_FULL;
            }
            else
            {
                /* storage is card */
                g_camera_cntx.last_error = CAMERA_ERR_CARD_DISK_FULL;

                /* has error - restore to phone */
                g_imgview_context.storage =  MMI_PUBLIC_DRV;
            }
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            if (cur_storage == MMI_IMGVIEW_STORAGE_PHONE)
            {
                g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
            }
            else
            {
                /* storage is card */
                g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;

                /* has error - restore to phone */
                g_imgview_context.storage =  MMI_PUBLIC_DRV;
            }
        }
    }
    else
    {
        g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
        g_imgview_context.is_storage_ready = FALSE;
    }

    /* each time newly enter camera, zoom will be reset to default */
    if (guiBuffer == NULL)
    {
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    }

    /* power on and init hardware module */
    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)
    {
        g_camera_cntx.last_error = mdi_camera_power_on();
    }


   /************ enter next state ************/
    /* entry preview */
    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)  /* no error, if has error, will enter main then show error popup */
    {
        /* set key handler */

        /* preview start */
        mmi_sublcd_camera_preview_start();

        /* check if preview function has error */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_sublicd_camera_display_error_screen();
            return;
        }
    }
    else
    {
        mmi_sublicd_camera_display_error_screen();
        return;
    }
  
    SetKeyHandler(mmi_sublcd_camera_capture, KEY_CAMERA, KEY_EVENT_UP);
    SetKeyHandler(GoBackSubLCDHistory, KEY_CAMERA, KEY_EVENT_LONG_PRESS);
    SetSubLCDExitHandler(mmi_sublcd_camera_exit_preview_screen);
    ClearKeyEvents();
}


BOOL mmi_sublcd_camera_is_previewing(void)
{
    return g_camera_cntx.is_sublcd_previewing;
}
void mmi_sublcd_camera_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!IsSubLCDScreenPresent(SCR_ID_CAMERA_SUBLCD_APP))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = mmi_sublcd_camera_entry_preview_screen_ex;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_CAMERA_SUBLCD_APP);
    }


    /* turn off led highlight */
    mmi_camera_turn_off_led_highlight();

    /* stop previewing */
    mmi_camera_sublcd_preview_stop();

    /* turn on/of 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_on();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 

    /* shut down camera */
    mdi_camera_power_off();

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_RELEASE);

    /* let MMI can sleep */
    TurnOffBacklight();


    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* free buffer */
    gui_free(g_camera_cntx.storage_filepath);
    g_camera_cntx.storage_filepath = NULL;

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    gdi_lcd_freeze(FALSE);

#ifdef __MMI_SUBLCD__
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
    gdi_layer_pop_and_restore_active();
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* un-hook clam close msg */
    ClearInterruptEventHandler(MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* store camera setting back to NVRAM */
    mmi_camera_store_setting();

    g_camera_cntx.is_sublcd_previewing = FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_add_frame_highlight_hdlr
 * DESCRIPTION
 *  add frame highlight handler
 * PARAMETERS
 *  idx     [IN]        Highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sublcd_camera_flash_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.cur_select_flash_idx= idx;
}

static void mmi_sublcd_camera_entry_flash_screen(void)
{
    DisplaySubLCDScreen(SCR_ID_CAMERA_SUBLCD_OPTION_FLASH, mmi_sublcd_camera_entry_flash_screen_ex, 1);
}
static void mmi_sublcd_camera_entry_flash_screen_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    S32 hilight_item = 0;
    BOOL is_hide = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    mmi_camera_load_setting();
    #if defined(__CAMERA_FEATURE_FLASH__) 
    if (g_camera_cntx.setting.flash == CAMERA_SETTING_FLASH_OFF)
        hilight_item = 1;
    else 
        hilight_item = 0;
    #elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
    if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF )
        hilight_item = 1;
    else 
        hilight_item = 0;
    #endif

    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_SUBLCD_OPTION_FLASH);
    nItems = GetNumOfChild_Ext(MENU_ID_CAMERA_SUBLCD_FLASH);
    GetSequenceStringIds_Ext(MENU_ID_CAMERA_SUBLCD_FLASH, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_CAMERA_SUBLCD_FLASH, ItemIcons);
    SetParentHandler(MENU_ID_CAMERA_SUBLCD_FLASH);

    RegisterHighlightHandler(mmi_sublcd_camera_flash_highlight_hdlr);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_CAMERA_SUBLCD_FLASH, PopUpList);

    /* need to register clam open/close handler */

    ShowCategory314Screen(
        (U8*) GetString(STR_ID_CAMERA_FLASH),
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        hilight_item,
        guiBuffer);

    SetKeyHandler(mmi_sublcd_camera_set_flash, KEY_CAMERA, KEY_EVENT_UP);
    SetSubLCDExitHandler(mmi_sublcd_camera_exit_flash_screen);

}
static void mmi_sublcd_camera_exit(void)
{
    GoBackHistory();
    ClearKeyEvents();
}

static void mmi_sublcd_camera_exit_flash_screen(void)
{
    if (!IsSubLCDScreenPresent(SCR_ID_CAMERA_SUBLCD_OPTION_FLASH))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = mmi_sublcd_camera_entry_flash_screen_ex;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_CAMERA_SUBLCD_OPTION_FLASH);
    }
    ExitCategory314Screen();
}


static void mmi_sublcd_camera_hilight_preview(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_entry_preview_screen, KEY_CAMERA, KEY_EVENT_UP);
}


static void mmi_sublcd_camera_hilight_flash(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_entry_flash_screen, KEY_CAMERA, KEY_EVENT_UP);
}


static void mmi_sublcd_camera_hilight_flash_option(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_set_flash, KEY_CAMERA, KEY_EVENT_UP);
}


static void mmi_sublcd_camera_hilight_exit(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_exit, KEY_CAMERA, KEY_EVENT_UP);
}

static void mmi_sublcd_camera_event_handler(void)
{
    if (mmi_sublcd_camera_is_previewing())
        mmi_sublcd_camera_exit_preview_screen();

    /* resume background audio */
    mdi_audio_resume_background_play();

    ForceSubLCDScreen(ShowIdleAppSubLcd);
}

void mmi_sublcd_camera_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* for hiding audioplayr title */
    if (mmi_idle_is_on_idle_screen()==TRUE)
        EntryIdleScreen();

    EntryNewScreen(SCR_ID_CAMERA_SUBLCD_OPTION, mmi_sublcd_camera_event_handler, NULL, NULL);

    ShowCategoryDummyScreen();
    DisplaySubLCDScreen(SCR_ID_CAMERA_SUBLCD_OPTION, mmi_sublcd_camera_entry_option_screen_ex, 1);
}

void mmi_sublcd_camera_entry_option_screen_ex(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    BOOL is_hide = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_SUBLCD_OPTION);
    nItems = GetNumOfChild_Ext(MENU_ID_CAMERA_SUBLCD_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_CAMERA_SUBLCD_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_CAMERA_SUBLCD_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_CAMERA_SUBLCD_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_CAMERA_SUBLCD_OPTION, PopUpList);

    /* need to register clam open/close handler */

    ShowCategory314Screen(
        (U8*) GetString(STR_GLOBAL_OPTIONS),
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        guiBuffer);

    SetKeyHandler(mmi_sublcd_camera_exit, KEY_CAMERA, KEY_LONG_PRESS);
    ClearKeyEvents();    
    SetSubLCDExitHandler(mmi_sublcd_camera_exit_option_screen);

}

static void mmi_sublcd_camera_exit_option_screen(void)
{
    if (!IsSubLCDScreenPresent(SCR_ID_CAMERA_SUBLCD_OPTION))
    {
        SubLCDHistoryNode SubLCDHistory;

        SubLCDHistory.entryFuncPtr = mmi_sublcd_camera_entry_option_screen_ex;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_CAMERA_SUBLCD_OPTION);
    }
    ExitCategory314Screen();
}
#endif











/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)

extern void noke_drv_camera_flash_light_on(kal_bool light_on) ;
extern mdi_camera_setting_struct *camera_setting_p;


/*****************************************************************************
 * FUNCTION
 *  noke_mmi_camera_flash_light
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void noke_mmi_camera_flash_light_on(kal_bool light_on)
{
#if defined(DOUBLE_CAMERA_SUPPORT)
	if(   mmi_main_camera_active )
#endif
	{
		if( light_on  )
		{
			noke_drv_camera_flash_light_on( TRUE );
		}else{
			noke_drv_camera_flash_light_on( FALSE);
		}
	}
}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */
















/***************************************************************************
*
*  Settings / File Path / Storage handling                                                     
*
***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_check_and_restore_valid_drv
 * DESCRIPTION
 *  Check if desired path is ready or not. If not, will restore to valid path.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_camera_check_and_restore_valid_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(g_imgview_context.storage ,FS_MOUNT_STATE_ENUM))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_storage_disk_path
 * DESCRIPTION
 *  get current active storage disk path.
 * PARAMETERS
 *  drv_buf     [IN]        
 *  a(?)        [OUT]       Fill disk's name string.
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_camera_get_storage_disk_path(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (FS_NO_ERROR == FS_GetDevStatus(g_imgview_context.storage ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\", (U8)g_imgview_context.storage );
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }
    else
    {
        g_imgview_context.storage = (U16) MMI_PUBLIC_DRV;

        if (FS_NO_ERROR != FS_GetDevStatus(g_imgview_context.storage ,FS_MOUNT_STATE_ENUM))
            return FALSE;

        sprintf(buf, "%c:\\", (U8)g_imgview_context.storage );
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }   
}


#if defined(DOUBLE_CAMERA_SUPPORT)

//Huyanwei Add It 
#ifndef WIN32
extern void   mmi_double_camera_switch_handler(void); 
#endif

//Huyanwei Add it 
const U16 Camera_Switch_OffsetX = 240 - 33 ;
const U16 Camera_Switch_OffsetY = 320 - 66 ;
const U16 Camera_Switch_Width    = 30 ;
const U16 Camera_Switch_Height   = 24 ;


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_double_cam_key_press
 * DESCRIPTION
 * 
 * PARAMETERS
 
 *****************************************************************************/
static void mmi_camera_preview_double_cam_key_press(void)
{
    S8 str_buf[256];
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
	   
 #if 1
 	//Huyanwei Del it 
   	 pfnUnicodeStrcpy((PS8) str_buf, (PS8) L"[ ");
    	 pfnUnicodeStrcat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_IMAGE_DOUBLE_MODE));
   	 pfnUnicodeStrcat((PS8) str_buf, (PS8) L" ]");
	if(!mmi_main_camera_active)
  	  mmi_camera_preview_set_hint(
	         (PS8) str_buf,
        		(PS8) GetString((U16) (STR_ID_CAMERA_IMAGE_DOUBLE_MODE_MASTER)),
		HINT_POPUP_FADE_TIME);
	else
	    mmi_camera_preview_set_hint(
	        (PS8) str_buf,
        		(PS8) GetString((U16) (STR_ID_CAMERA_IMAGE_DOUBLE_MODE_SILVER)),
	        HINT_POPUP_FADE_TIME);
#endif 
	     double_cam = mmi_main_camera_active;
            mmi_camera_preview_draw_osd();

            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1); 
	    #ifndef WIN32
			 mmi_double_camera_switch_handler();	
	    #endif	
    }
}

/*****************************************************************************
 * FUNCTION
 *  U8  mmi_test_touch_object(S32 pos_x, S32 pos_y, s32 obj_x,s32 obj_y,s32 obj_w,s32 obj_h)
 * DESCRIPTION
 * 
 * PARAMETERS
 
 *****************************************************************************/
U8  mmi_test_touch_object(S32 pos_x, S32 pos_y, s32 obj_x,s32 obj_y,s32 obj_w,s32 obj_h)
{

  if((pos_x>=obj_x)&&(pos_x<=obj_x+obj_w)&&(pos_y>=obj_y)&&(pos_y<=obj_y+obj_h))
  	return 1;
  else
  	return 0;
  	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_init_double_cam_info
 * DESCRIPTION
 * 
 * PARAMETERS
 
 *****************************************************************************/
void mmi_init_double_cam_info()
{
	U16 image_id;
	S32 width = Camera_Switch_Width,  height = Camera_Switch_Height;
#if 0
	//Huyanwei Del ICON
	gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_DOUBLE_CAM_0,&width,&height);
#endif
	obj_w=width;
	obj_h=height;	
	mmi_main_camera_active=KAL_TRUE; 
	double_cam = ((mmi_main_camera_active == KAL_TRUE)?0:1);
	//与mmi_main_camera_active =true保持一致
}

/*****************************************************************************
 * FUNCTION
 *  BOOL  mmi_double_cam_icon_press(S32 pos_x, S32 pos_y)
 * DESCRIPTION
 * 
 * PARAMETERS
 
 *****************************************************************************/
BOOL  mmi_double_cam_icon_press(S32 pos_x, S32 pos_y)
{

#if 0
 	if(mmi_test_touch_object(pos_x,pos_y,g_camera_cntx.active_camera_osd_ptr->double_cam.offset_x,g_camera_cntx.active_camera_osd_ptr->double_cam.offset_y,obj_w,obj_h))
 #else
	 if(mmi_test_touch_object(pos_x,pos_y,Camera_Switch_OffsetX,Camera_Switch_OffsetY,Camera_Switch_Width,Camera_Switch_Height))
#endif
 	return TRUE;
 else
 	return FALSE;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_load_setting
 * DESCRIPTION
 *  load camera settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (!g_camera_cntx.is_setting_loaded)
    {
        U16 old_storage;
        ReadRecord(
            NVRAM_EF_CAMERA_SETTING_LID,
            1,
            (void*)&g_camera_cntx.setting,
            NVRAM_EF_CAMERA_SETTING_SIZE,
            &error);

        /* first time init */
        if (g_camera_cntx.setting.wb == 0xffff)
        {
            old_storage = g_imgview_context.storage;

            mmi_camera_restore_setting();

            if (old_storage != 0xffff)
            {
                g_imgview_context.storage = old_storage;
                WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);                
            }
        }

        g_camera_cntx.setting.preview_led_value = CAMERA_DEFAULT_PREVIEW_LED_VALUE;
        g_camera_cntx.setting.capture_led_value = CAMERA_DEFAULT_CAPTURE_LED_VALUE;

        /* init preview size based on LCD size */
        mmi_camera_preview_update_capture_size();

        /* load image viewer setting - for storage path */
        mmi_imgview_load_setting();

        g_camera_cntx.is_setting_loaded = TRUE;
    }

	#if defined(DOUBLE_CAMERA_SUPPORT)
	//Huyanwei Add It 
	mmi_init_double_cam_info();//UNI@bw_20070623 添加双camera切换
	#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_store_setting
 * DESCRIPTION
 *  store camera settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_CAMERA_SETTING_LID, 1, (void*)&g_camera_cntx.setting, NVRAM_EF_CAMERA_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_restore_setting
 * DESCRIPTION
 *  restore camera setting to default value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.setting.wb = CAMERA_DEFAULT_SETTING_WB;
    g_camera_cntx.setting.flash = CAMERA_DEFAULT_SETTING_FLASH;
    g_camera_cntx.setting.led_highlight = CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT;
    g_camera_cntx.setting.shutter_sound = CAMERA_DEFAULT_SETTING_SHUTTER_SOUND;
    g_camera_cntx.setting.ev = CAMERA_DEFAULT_SETTING_EV;
    g_camera_cntx.setting.night = CAMERA_DEFAULT_SETTING_NIGHT;
    g_camera_cntx.setting.closeup = CAMERA_DEFAULT_SETTING_CLOSEUP;
    g_camera_cntx.setting.banding = CAMERA_DEFAULT_SETTING_BANDING;
    g_camera_cntx.setting.image_size = CAMERA_DEFAULT_SETTING_IMAGE_SIZE;
    g_camera_cntx.setting.image_qty = CAMERA_DEFAULT_SETTING_IMAGE_QTY;

    g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    g_camera_cntx.setting.effect = CAMERA_DEFAULT_SETTING_EFFECT;
    g_camera_cntx.setting.add_frame = CAMERA_DEFAULT_SETTING_ADD_FRAME;
    g_camera_cntx.setting.add_frame_tileshot = CAMERA_DEFAULT_SETTING_ADD_FRAME;
    g_camera_cntx.setting.add_frame_color_idx = CAMERA_DEFAULT_SETTING_ADD_FRAME;
    g_camera_cntx.setting.cont_shot = CAMERA_DEFAULT_SETTING_CONT_SHOT;
    g_camera_cntx.setting.delay_timer = CAMERA_DEFAULT_SETTING_DELAY_TIMER;

    g_camera_cntx.setting.iso = CAMERA_DEFAULT_SETTING_ISO;
    g_camera_cntx.setting.ae_meter = CAMERA_DEFAULT_SETTING_AE_METER;
    g_camera_cntx.setting.af_meter = CAMERA_DEFAULT_SETTING_AUTOFOCUS;
    g_camera_cntx.setting.af_mode = 0;
    g_camera_cntx.setting.dsc_mode = CAMERA_DEFAULT_SETTING_DSC_MODE;
    g_camera_cntx.setting.shutter_pri = 0;
    g_camera_cntx.setting.aperture_pri = 0;

    g_camera_cntx.setting.fx_brightness[0] = CAMERA_DEFAULT_SETTING_BRIGHTNESS;
    g_camera_cntx.setting.fx_brightness[1] = CAMERA_DEFAULT_SETTING_BRIGHTNESS;
    g_camera_cntx.setting.fx_brightness[2] = CAMERA_DEFAULT_SETTING_BRIGHTNESS;
    g_camera_cntx.setting.fx_saturation[0] = CAMERA_DEFAULT_SETTING_SATURATION;
    g_camera_cntx.setting.fx_saturation[1] = CAMERA_DEFAULT_SETTING_SATURATION;
    g_camera_cntx.setting.fx_saturation[2] = CAMERA_DEFAULT_SETTING_SATURATION;
    g_camera_cntx.setting.fx_contrast[0] = CAMERA_DEFAULT_SETTING_CONTRAST;
    g_camera_cntx.setting.fx_contrast[1] = CAMERA_DEFAULT_SETTING_CONTRAST;
    g_camera_cntx.setting.fx_contrast[2] = CAMERA_DEFAULT_SETTING_CONTRAST;
    g_camera_cntx.setting.fx_hue[0] = CAMERA_DEFAULT_SETTING_HUE;
    g_camera_cntx.setting.fx_hue[1] = CAMERA_DEFAULT_SETTING_HUE;
    g_camera_cntx.setting.fx_hue[2] = CAMERA_DEFAULT_SETTING_HUE;

    g_camera_cntx.is_hide_osd = FALSE;

#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
        g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __CAMERA_FEATURE_XENON_FLASH__
    g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;    
#endif

    g_imgview_context.storage =   MMI_PUBLIC_DRV;
    WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);
    mmi_camera_preview_update_capture_size();

    mmi_camera_store_setting();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_restore_filename_seq_no
 * DESCRIPTION
 *  restore seq no when capture fail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_restore_filename_seq_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 filename_seq_no;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    if (filename_seq_no == 1)
        filename_seq_no = 9999;
    else 
        filename_seq_no--;

    WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_next_filename
 * DESCRIPTION
 *  get next file name for jpeg image
 * PARAMETERS
 *  file_buf_p      [IN]        
 *  a(?)            [OUT]       Next filename
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_get_next_filename(PS8 file_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;
    U16 file_check = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get/store sequentail number */
    ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }

    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;

    sprintf((PS8) buffer, "IMG%04d", filename_seq_no);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);

    while (1)
    {
        sprintf((PS8) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((PS8) UCS2_alpha, (PS8) buffer);

        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (PS8) L".jpg");

        mmi_ucs2cpy((PS8) file_buf_p, (PS8) g_camera_cntx.storage_filepath);
        mmi_ucs2cat((PS8) file_buf_p, (PS8) UCS2_testname);

        file_handle = FS_Open((U16*) file_buf_p, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            /* file not exit. return */
            WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
            return;
        }

        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count )
        {
            alpha_count = 'Z' - 'A' + 1;
            alpha_index = 0;
            filename_seq_no++;
            file_check++;
            if (filename_seq_no > 9999) /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
            sprintf((PS8) buffer, "IMG%04d", filename_seq_no);
            mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);

            /* check if number of files are > 9999 * 26*/
            if (file_check >= 9999)
                return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_display_error_popup
 * DESCRIPTION
 *  display a popup error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has error */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);

        /* temperary solution for MT6225 hot sensor key */
        if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
        {
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
        }        

        string_id = mmi_camera_get_error_string_by_error_enum((S32)g_camera_cntx.last_error);

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        DisplayPopupRotated(
            (PU8) GetString(string_id),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE,
            g_camera_cntx.osd_rotate);
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        DisplayPopup((PU8) GetString(string_id), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

        if ((g_camera_cntx.last_error == CAMERA_ERR_PHONE_DISK_FULL)
            || (g_camera_cntx.last_error == CAMERA_ERR_CARD_DISK_FULL)
            || (g_camera_cntx.last_error == CAMERA_ERR_CORRUPT_FAT)
            || (g_camera_cntx.last_error == CAMERA_ERR_ROOT_DIR_FULL))
        {
            /* if there is only phone storage, we will delete camera screen,
               else we will popup select storage screen for user */
            #if defined(__CAMERA_FEATURE_STORAGE__)
                return;
            #else
                g_imgview_context.is_storage_ready = TRUE;
                DeleteNHistory(1);                
            #endif
        }
        else if (g_camera_cntx.last_error == MDI_RES_CAMERA_ERR_HW_NOT_READY)
        {
            DeleteNHistory(1);
        }
        g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
        /* for External Request */
        if (g_camera_cntx.is_external_request == TRUE)
        {
            g_camera_cntx.callback_ptr(MMI_FALSE,NULL);
            return;
        }       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_error_string_by_error_enum
 * DESCRIPTION
 *  Get error string by error code.
 * PARAMETERS
 *  err_code
 * RETURNS
 *  error string id
 *****************************************************************************/
MMI_ID_TYPE mmi_camera_get_error_string_by_error_enum(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (err_code)
    {
        case CAMERA_ERR_BT_IS_WORKING:
            string_id = STR_ID_CAMERA_NOTIFY_BT_IS_WORKING;
            break;
        case MDI_RES_CAMERA_ERR_DISK_FULL:
            string_id = STR_ID_CAMERA_NOTIFY_DISK_FULL;
            break;
        case MDI_RES_CAMERA_ERR_NO_DISK:
            string_id = STR_ID_CAMERA_NOTIFY_NO_MEMORY_CARD;
            break;
        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
            string_id = STR_ID_CAMERA_NOTIFY_WRITE_PROTECTION;
            break;
        case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
            string_id = STR_ID_CAMERA_NOTIFY_CAPTURE_FAILED;
            break;
        case CAMERA_ERR_CARD_DISK_FULL:
            string_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case CAMERA_ERR_ROOT_DIR_FULL:
            string_id = FMGR_FS_ROOT_DIR_FULL_TEXT;
            break;
        case CAMERA_ERR_WRITE_PROTECT:
            string_id = FMGR_FS_WRITE_PROTECTION_TEXT;
            break;
        case MDI_RES_CAMERA_ERR_HW_NOT_READY:
            string_id = STR_ID_CAMERA_NOTIFY_HW_NOT_READY;
            break;
        case CAMERA_ERR_CORRUPT_FAT:
            string_id = FMGR_FS_FAT_ALLOC_ERROR_TEXT;
            break;
        case CAMERA_ERR_PHONE_DISK_FULL:
            /* phone disk full, cant create "Photos" folder */
            string_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case CAMERA_ERR_SAVE_FAIL:
            string_id = STR_ID_CAMERA_NOTIFY_SAVING_FAIL;
            break;
        case MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT:
            string_id = STR_ID_CAMERA_NOTIFY_XENON_TIMEOUT;
            break;
        case MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY:
            string_id = STR_ID_CAMERA_NOTIFY_XENON_LOW_BATTERY;
            break;
        default:
            string_id = STR_ID_CAMERA_NOTIFY_ERROR;
            break;
    }

    return string_id;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_display_sublcd_error_popup
 * DESCRIPTION
 *  display a popup error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_display_sublcd_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct clam_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has error */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        switch (g_camera_cntx.last_error)
        {
                /* these are recoverable errors */
                /* show on sublcd screen and keep previewing */
            case MDI_RES_CAMERA_ERR_DISK_FULL:
            case MDI_RES_CAMERA_ERR_NO_DISK:
            case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
            case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
            case CAMERA_ERR_SAVE_FAIL:
                /* play warning tone and re-entry preview state */
                playRequestedTone(WARNING_TONE);
                CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
                break;

            default:
                /* serious error, will exit camera app */
                GoBackHistory();

                /* 
                 * since clam close if aready intercept by camera app,
                 * we shall notify framework (gpio.c) to process clam close action 
                 */
                if (g_camera_cntx.is_clam_close)
                {
                    clam_event.gpio_device = EXT_DEV_CLAM_CLOSE;
                    GpioDetectInd(&clam_event);
                }

                break;
        }
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_dummy_func
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty function */
}

/****************************************************************************
*
*  Camera App                                                   
*
****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_hilight_app
 * DESCRIPTION
 *  app menu item hilight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_camera_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_img_size_img_id
 * DESCRIPTION
 *  get image string id based on customization
 * PARAMETERS
 *  image_width         [IN]        Capture image width
 *  image_height        [IN]        Capture image height
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_camera_get_img_size_img_id(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_width == 2048 && image_height == 1536)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_2048x1536;
    }
    else if (image_width == 1600 && image_height == 1200)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1600x1200;
    }
    else if (image_width == 1280 && image_height == 1024)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1280x1024;
    }
    else if (image_width == 1280 && image_height == 960)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1280x960;
    }
    else if (image_width == 800 && image_height == 600)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_800x600;
    }
    else if (image_width == 640 && image_height == 480)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_640x480;
    }
    else if (image_width == 320 && image_height == 240)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_320x240;
    }
    else if (image_width == 160 && image_height == 120)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_160x120;
    }
    else if (image_width == 80 && image_height == 60)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_80x60;
    }
    else if (image_width == 80 && image_height == 56)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_80x56;
    }
    else if (image_width == 240 && image_height == 320)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_240x320;
    }
    else if ((image_width == 176 && image_height == 220) || (image_width == 220 && image_height == 176))
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_176x220;
    }
    else if (image_width == 128 && image_height == 160)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x160;
    }
    else if (image_width == 128 && image_height == 128)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x128;
    }
    else if (image_width == 96 && image_height == 64)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_96x64;
    }
    else if (image_width == 128 && image_height == 85)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x85;
    }
    else
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_UNDEFINE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_img_size_str_id
 * DESCRIPTION
 *  get image string id based on customization
 * PARAMETERS
 *  image_width         [IN]        Capture image width
 *  image_height        [IN]        Capture image height
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_camera_get_img_size_str_id(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_width == 2048 && image_height == 1536)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_2048x1536;
    }
    else if (image_width == 1600 && image_height == 1200)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1600x1200;
    }
    else if (image_width == 1280 && image_height == 1024)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1280x1024;
    }
    else if (image_width == 1280 && image_height == 960)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1280x960;
    }
    else if (image_width == 800 && image_height == 600)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_800x600;
    }
    else if (image_width == 640 && image_height == 480)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_640x480;
    }
    else if (image_width == 320 && image_height == 240)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_320x240;
    }
    else if (image_width == 160 && image_height == 120)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_160x120;
    }
    else if (image_width == 80 && image_height == 60)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_80x60;
    }
    else if (image_width == 80 && image_height == 56)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_80x56;
    }
    else if (image_width == 240 && image_height == 320)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_240x320;
    }
    else if (image_width == 176 && image_height == 220)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_176x220;
    }
    else if (image_width == 128 && image_height == 160)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x160;
    }
    else if (image_width == 128 && image_height == 128)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x128;
    }
    else if (image_width == 96 && image_height == 64)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_96x64;
    }
    else if (image_width == 128 && image_height == 85)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x85;
    }
    else
    {
        return STR_ID_CAMERA_IMAGE_SIZE_UNDEFINE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_update_osd_touch_icon
 * DESCRIPTION
 *  update osd touch icons' positions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_update_osd_touch_icon()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_TOUCH_CLICKICON__
#define INIT_OSD_TOUCH_ICON(a,A)                                                               \
         do {                                                                                           \
            if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                      \
            {                                                                                           \
               gdi_image_get_dimension_id((U16)(IMG_ID_CAMERA_OSD_##A##_START+1),                       \
                                          &g_camera_cntx.touch_##a##.width,                             \
                                          &g_camera_cntx.touch_##a##.height);                           \
               g_camera_cntx.touch_##a##.offset_x = g_camera_cntx.active_camera_osd_ptr->##a##.offset_x;\
               g_camera_cntx.touch_##a##.offset_y = g_camera_cntx.active_camera_osd_ptr->##a##.offset_y;\
               g_camera_cntx.touch_##a##.is_press = FALSE;                                              \
            }                                                                                           \
         } while(0);
#else /* __CAMERA_FEATURE_TOUCH_CLICKICON__ */ 

    /* 
     * if touch screen is enable, but do not want to enable icon click, 
     * set icon offset to -1 and size to 0 
     */
#define INIT_OSD_TOUCH_ICON(a,A)                         \
         do {                                                     \
            if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)\
            {                                                     \
               g_camera_cntx.touch_##a##.width     = 0;           \
               g_camera_cntx.touch_##a##.height    = 0;           \
               g_camera_cntx.touch_##a##.offset_x  = -1;          \
               g_camera_cntx.touch_##a##.offset_y  = -1;          \
               g_camera_cntx.touch_##a##.is_press  = FALSE;       \
            }                                                     \
         } while(0);
#endif /* __CAMERA_FEATURE_TOUCH_CLICKICON__ */ 

    /* draw icon */
    INIT_OSD_TOUCH_ICON(effect, EFFECT);
    INIT_OSD_TOUCH_ICON(wb, WB);
    INIT_OSD_TOUCH_ICON(flash, FLASH);
    INIT_OSD_TOUCH_ICON(led_highlight, LED_HIGHLIGHT);
    INIT_OSD_TOUCH_ICON(night, NIGHT);
    if (g_camera_cntx.active_camera_osd_ptr->image_size.is_show)
    {
        gdi_image_get_dimension_id(
            (U16) (IMG_ID_CAMERA_IMAGE_SIZE_320x240),
            &g_camera_cntx.touch_image_size.width,
            &g_camera_cntx.touch_image_size.height);
        g_camera_cntx.touch_image_size.offset_x = g_camera_cntx.active_camera_osd_ptr->image_size.offset_x;
        g_camera_cntx.touch_image_size.offset_y = g_camera_cntx.active_camera_osd_ptr->image_size.offset_y;
        g_camera_cntx.touch_image_size.is_press = FALSE;
    }

    INIT_OSD_TOUCH_ICON(image_qty, IMAGE_QTY);
    INIT_OSD_TOUCH_ICON(cont_shot, CONT_SHOT);
    INIT_OSD_TOUCH_ICON(delay_timer, DELAY_TIMER);
    INIT_OSD_TOUCH_ICON(dsc_mode, DSC_MODE);
    INIT_OSD_TOUCH_ICON(af_mode, FOCUS_MODE);
    INIT_OSD_TOUCH_ICON(af_meter, FOCUS_METER);
    if (g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.is_show)
    {
        gdi_image_get_dimension_id(
            (U16) (IMG_ID_CAMERA_OSD_ZOOM_MF_TOGGLE),
            &g_camera_cntx.touch_zoom_mf_toggle.width,
            &g_camera_cntx.touch_zoom_mf_toggle.height);
        g_camera_cntx.touch_zoom_mf_toggle.offset_x = g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_x;
        g_camera_cntx.touch_zoom_mf_toggle.offset_y = g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_y;
        g_camera_cntx.touch_zoom_mf_toggle.is_press = FALSE;
    }
    INIT_OSD_TOUCH_ICON(iso, ISO);
    INIT_OSD_TOUCH_ICON(ae_meter, AE_METER);
    INIT_OSD_TOUCH_ICON(storage, STORAGE);

    /* ev inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_EV_INC),
        &g_camera_cntx.touch_ev_inc.width,
        &g_camera_cntx.touch_ev_inc.height);

    g_camera_cntx.touch_ev_inc.offset_x = g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x;
    g_camera_cntx.touch_ev_inc.offset_y = g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y;
    g_camera_cntx.touch_ev_inc.is_press = FALSE;

    /* ev dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_EV_DEC),
        &g_camera_cntx.touch_ev_dec.width,
        &g_camera_cntx.touch_ev_dec.height);

    g_camera_cntx.touch_ev_dec.offset_x = g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x;
    g_camera_cntx.touch_ev_dec.offset_y = g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y;
    g_camera_cntx.touch_ev_dec.is_press = FALSE;

    /* zoom inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC),
        &g_camera_cntx.touch_zoom_inc.width,
        &g_camera_cntx.touch_zoom_inc.height);

    g_camera_cntx.touch_zoom_inc.offset_x = g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x;
    g_camera_cntx.touch_zoom_inc.offset_y = g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y;
    g_camera_cntx.touch_zoom_inc.is_press = FALSE;

    /* zoom dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC),
        &g_camera_cntx.touch_zoom_dec.width,
        &g_camera_cntx.touch_zoom_dec.height);

    g_camera_cntx.touch_zoom_dec.offset_x = g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x;
    g_camera_cntx.touch_zoom_dec.offset_y = g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y;
    g_camera_cntx.touch_zoom_dec.is_press = FALSE;

    /* capture */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_CAPTURE),
        &g_camera_cntx.touch_capture.width,
        &g_camera_cntx.touch_capture.height);

    g_camera_cntx.touch_capture.offset_x = g_camera_cntx.active_camera_osd_ptr->capture.offset_x;
    g_camera_cntx.touch_capture.offset_y = g_camera_cntx.active_camera_osd_ptr->capture.offset_y;
    g_camera_cntx.touch_capture.is_press = FALSE;

#ifdef __MMI_CAMERA_MMS_SUPPORT__
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_FORWARD_TO_MMS),
        &g_camera_cntx.touch_mms_icon.width,
        &g_camera_cntx.touch_mms_icon.height);
    g_camera_cntx.touch_mms_icon.offset_x = g_camera_cntx.active_camera_osd_ptr->mms_icon.offset_x;
    g_camera_cntx.touch_mms_icon.offset_y = g_camera_cntx.active_camera_osd_ptr->mms_icon.offset_y;
    g_camera_cntx.touch_mms_icon.is_press = FALSE;
#endif /* __MMI_CAMERA_MMS_SUPPORT__ */ 

#undef INIT_OSD_TOUCH_ICON

}


#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_init_osd_icon_layer_position
 * DESCRIPTION
 *  update osd touch icons' positions
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_init_osd_icon_layer_position()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_osd_layeout_struct *active_camera_osd_ptr;

    active_camera_osd_ptr = &g_camera_osd_cntx;
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
#define INIT_OSD_ICON(a)                                                                                                                  \
         do {                                                                                                                                      \
            if(active_camera_osd_ptr->##a##.is_show)                                                                                               \
            {                                                                                                                                      \
               if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region0.offset_x)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region0.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region0.offset_x+active_camera_osd_ptr->osd_region0.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region0.offset_y+active_camera_osd_ptr->osd_region0.height))\
                  active_camera_osd_ptr->##a##.group_id = 0;                                                                                       \
               else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region1.offset_x)&&                                    \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region1.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region1.offset_x+active_camera_osd_ptr->osd_region1.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region1.offset_y+active_camera_osd_ptr->osd_region1.height))\
                  active_camera_osd_ptr->##a##.group_id = 1;                                                                                       \
               else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region2.offset_x)&&                                    \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region2.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region2.offset_x+active_camera_osd_ptr->osd_region2.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region2.offset_y+active_camera_osd_ptr->osd_region2.height))\
                  active_camera_osd_ptr->##a##.group_id = 2;                                                                                       \
               else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region3.offset_x)&&                                    \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region3.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region3.offset_x+active_camera_osd_ptr->osd_region3.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region3.offset_y+active_camera_osd_ptr->osd_region3.height))\
                  active_camera_osd_ptr->##a##.group_id = 3;                                                                                       \
               else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region4.offset_x)&&                                    \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region4.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region4.offset_x+active_camera_osd_ptr->osd_region4.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region4.offset_y+active_camera_osd_ptr->osd_region4.height))\
                  active_camera_osd_ptr->##a##.group_id = 4;                                                                                       \
            }                                                                                                                                      \
         } while(0)
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
#define INIT_OSD_ICON(a)                                                                                                                           \
         do {                                                                                                                                      \
            if(active_camera_osd_ptr->##a##.is_show)                                                                                               \
            {                                                                                                                                      \
               if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region0.offset_x)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region0.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region0.offset_x+active_camera_osd_ptr->osd_region0.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region0.offset_y+active_camera_osd_ptr->osd_region0.height))\
                  active_camera_osd_ptr->##a##.group_id = 0;                                                                                       \
               else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region1.offset_x)&&                                    \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region1.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region1.offset_x+active_camera_osd_ptr->osd_region1.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region1.offset_y+active_camera_osd_ptr->osd_region1.height))\
                  active_camera_osd_ptr->##a##.group_id = 1;                                                                                       \
               else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region2.offset_x)&&                                    \
                  (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region2.offset_y)&&                                         \
                  (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region2.offset_x+active_camera_osd_ptr->osd_region2.width)&&\
                  (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region2.offset_y+active_camera_osd_ptr->osd_region2.height))\
                  active_camera_osd_ptr->##a##.group_id = 2;                                                                                       \
            }                                                                                                                                      \
         } while(0)
#endif
    /* draw icon */

    INIT_OSD_ICON(effect);
    INIT_OSD_ICON(wb);
    INIT_OSD_ICON(flash);
    INIT_OSD_ICON(led_highlight);
    INIT_OSD_ICON(night);
    INIT_OSD_ICON(image_size);
    INIT_OSD_ICON(image_qty);
    INIT_OSD_ICON(cont_shot);
    INIT_OSD_ICON(delay_timer);
    INIT_OSD_ICON(dsc_mode);
    INIT_OSD_ICON(af_mode);
    INIT_OSD_ICON(af_meter);

    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(iso);
    INIT_OSD_ICON(ae_meter);
    INIT_OSD_ICON(storage);
    INIT_OSD_ICON(ev);
    INIT_OSD_ICON(ev_inc);
    INIT_OSD_ICON(ev_dec);
    INIT_OSD_ICON(zoom);
    INIT_OSD_ICON(zoom_inc);
    INIT_OSD_ICON(zoom_dec);
    /* capture */

    INIT_OSD_ICON(capture);
    INIT_OSD_ICON(mms_icon);
    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(add_frame);
    INIT_OSD_ICON(closeup);
    INIT_OSD_ICON(remain_storage);
    INIT_OSD_ICON(flash_charge_status);

#if defined(__CAMERA_OSD_HORIZONTAL__)
    active_camera_osd_ptr = &g_camera_osd_cntx_270;

    INIT_OSD_ICON(effect);
    INIT_OSD_ICON(wb);
    INIT_OSD_ICON(flash);
    INIT_OSD_ICON(led_highlight);
    INIT_OSD_ICON(night);
    INIT_OSD_ICON(image_size);
    INIT_OSD_ICON(image_qty);
    INIT_OSD_ICON(cont_shot);
    INIT_OSD_ICON(delay_timer);
    INIT_OSD_ICON(dsc_mode);
    INIT_OSD_ICON(af_mode);
    INIT_OSD_ICON(af_meter);

    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(iso);
    INIT_OSD_ICON(ae_meter);
    INIT_OSD_ICON(storage);
    INIT_OSD_ICON(ev);
    INIT_OSD_ICON(ev_inc);
    INIT_OSD_ICON(ev_dec);
    INIT_OSD_ICON(zoom);
    INIT_OSD_ICON(zoom_inc);
    INIT_OSD_ICON(zoom_dec);
    /* capture */

    INIT_OSD_ICON(capture);
    INIT_OSD_ICON(mms_icon);
    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(add_frame);
    INIT_OSD_ICON(closeup);
    INIT_OSD_ICON(remain_storage);    
    INIT_OSD_ICON(flash_charge_status);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

}
#endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)*/ 


#if defined(DOUBLE_CAMERA_SUPPORT)
//Huyanwei Add It 
BOOL  mmi_polling_active_camera(void)
{

     return  mmi_main_camera_active;
}

#ifndef WIN32
void   mmi_double_camera_switch_handler(void)
{
/*UNI@bw070605  main camera and sub camera 只能在preview状态下
  切换，并且不用退出*/
/*UNI@bw060721 当sub camera不存在能够使用main camera*/
/*UNI@bw060726 当main camera不存在也能够使用sub camera*/
if(mmi_main_camera_active)
{
#ifndef MMI_ON_WIN32
//Huyanwei Add It For PC
if(sub_camera_is_ready_polling()==KAL_FALSE)
{
      DisplayPopup((PU8) GetString(STR_ID_CAMERA_NOTIFY_HW_NOT_READY), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
      return;
}
  #endif
}
else
{
#ifndef MMI_ON_WIN32
//Huyanwei Add It For PC
if(main_camera_is_ready_polling()==KAL_FALSE)
  {
      DisplayPopup((PU8) GetString(STR_ID_CAMERA_NOTIFY_HW_NOT_READY), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
      return;
  }
  #endif
}
   if(g_camera_cntx.app_state==CAMERA_STATE_PREVIEW)
   {
     mmi_camera_preview_stop();
     mdi_camera_power_off();
     mmi_main_camera_active=(mmi_main_camera_active==KAL_TRUE)?0:1;
     mdi_camera_power_on();
     mmi_camera_preview_start();
   }
}
#endif
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_camera_init_app
 * DESCRIPTION
 *  nit camera application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U16 str_id;
    U16 img_id;

#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
    S32 image_height;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print trace Info */
    CAMERA_TRACE_FUNC_INIT();

    SetHiliteHandler(MENU_ID_CAMERA_APP, mmi_camera_hilight_app);

#ifdef __MMI_SUBLCD_CAMERA__
    SetHiliteHandler(MENU_ID_CAMERA_SUBLCD_PREVIEW, mmi_sublcd_camera_hilight_preview);
    #if defined(__CAMERA_FEATURE_FLASH__) || defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
        SetHiliteHandler(MENU_ID_CAMERA_SUBLCD_FLASH, mmi_sublcd_camera_hilight_flash);
        //SetHiliteHandler(MENU_ID_CAMERA_SUBLCD_FLASH_ON, mmi_sublcd_camera_hilight_flash_option);
        //SetHiliteHandler(MENU_ID_CAMERA_SUBLCD_FLASH_OFF, mmi_sublcd_camera_hilight_flash_option);
    #endif
    SetHiliteHandler(MENU_ID_CAMERA_SUBLCD_EXIT, mmi_sublcd_camera_hilight_exit);
#endif 


#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    SetHiliteHandler(MAIN_MENU_OPTION_CAMERA_APP, mmi_camera_hilight_app);
#endif 

    /* initialize camera app-based memory */
    applib_mem_ap_register(APPLIB_MEM_AP_ID_CAMERA,STR_ID_CAMERA_APP_NAME 
                ,IMG_ID_CAMERA_APP_ICON ,mmi_camera_app_mem_stop_callback);


    /* init Option Menu */
    mmi_camera_init_option_menu();

    /* init context */
    g_camera_cntx.app_state = CAMERA_STATE_EXIT;
    g_camera_cntx.app_prev_state = CAMERA_STATE_EXIT;
    g_camera_cntx.app_next_state = CAMERA_STATE_EXIT;

    g_camera_cntx.is_force_self_capture = FALSE;
    g_camera_cntx.is_setting_loaded = FALSE;
    g_camera_cntx.is_mainlcd_resource = FALSE;
    g_camera_cntx.is_sublcd_resource = FALSE;
    g_camera_cntx.is_sublcd_display = FALSE;
    g_camera_cntx.is_tileshot = FALSE;
    g_camera_cntx.is_fullscreen = FALSE;
    g_camera_cntx.is_dis_clam_open = FALSE;
    g_camera_cntx.is_cat65_show = FALSE;
    g_camera_cntx.is_multi_sound_open = FALSE;
    g_camera_cntx.is_continue_capture = FALSE;
    g_camera_cntx.has_camera_previewed = FALSE;
    g_camera_cntx.is_manual_autofocus = FALSE;
    g_camera_cntx.is_mms_ready = FALSE;
    g_camera_cntx.is_audio_finished = TRUE;
    g_camera_cntx.is_hide_osd = FALSE;
    /* for External Request */
    g_camera_cntx.is_external_request = FALSE;

    g_camera_cntx.base_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.add_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#if defined(__MMI_CAMERA_3_OSD_LAYER__)    
    g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle1 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle2 = GDI_LAYER_EMPTY_HANDLE;
#elif defined(__MMI_CAMERA_5_OSD_LAYER__)
    g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle1 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle2 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle3 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle4 = GDI_LAYER_EMPTY_HANDLE;
#else /* __MMI_CAMERA_3_OSD_LAYER__ */ 
    g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
#endif /* __MMI_CAMERA_3_OSD_LAYER__ */ 
    g_camera_cntx.sublcd_base_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.tileshot_result_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.tileshot_preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    g_camera_cntx.tile_cur_num = 0;

#if defined(__CAMERA_OSD_HORIZONTAL__)
    g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
    g_camera_cntx.base_UI_device_width = LCD_HEIGHT;
    g_camera_cntx.base_UI_device_height = LCD_WIDTH;
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
    g_camera_cntx.base_UI_device_width = LCD_WIDTH;
    g_camera_cntx.base_UI_device_height = LCD_HEIGHT;
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

    g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
    g_camera_cntx.active_camera_osd_ptr = &g_camera_osd_cntx;

#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    mmi_camera_init_osd_icon_layer_position();
#endif 
    g_camera_cntx.osd_UI_device_width = LCD_WIDTH;
    g_camera_cntx.osd_UI_device_height = LCD_HEIGHT;

    mmi_camera_preview_update_capture_size();
    g_camera_cntx.multi_sound_dummy_bg = 0;
    g_camera_cntx.multi_sound_capture0 = 0;
    g_camera_cntx.multi_sound_capture1 = 0;
    g_camera_cntx.multi_sound_capture2 = 0;

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    g_camera_cntx.image_size_before_burst = CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX;
#endif 

    memset(g_camera_cntx.hint1_buf, 0, CAMERA_HINT_BUF_SIZE);
    memset(g_camera_cntx.hint2_buf, 0, CAMERA_HINT_BUF_SIZE);

    /* init image size string */
    index = 0;

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;

#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);

    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 

#if defined(__CAMERA_130W_CHEAT__) 
   //Huyanwei Add It For 1280X960 Cheat .... Sorry ~~~
    //str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_LLL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LLL_HEIGHT);    
    str_id = mmi_camera_get_img_size_str_id(1280, 960);
    //img_id = mmi_camera_get_img_size_img_id(1280, 960);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);

    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;

#endif

    mmi_camera_update_osd_touch_icon();

#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
    g_camera_cntx.iconbar_start_idx = 0;
    g_camera_cntx.iconbar_selected_idx = (g_camera_cntx.active_camera_osd_ptr->iconbar.icon_per_page >> 1);
    g_camera_cntx.iconbar_item_per_page = g_camera_cntx.active_camera_osd_ptr->iconbar.icon_per_page;

    gdi_image_get_dimension_id(IMG_ID_CAMERA_ICONBAR_LEFT_ARROW, &g_camera_cntx.iconbar_arrow_width, &image_height);

    gdi_image_get_dimension_id(IMG_ID_CAMERA_ICONBAR_ITEM, &g_camera_cntx.iconbar_item_width, &image_height);

    index = 0;

#define INIT_ICONBAR_ITEM(__a__, __A__)                          \
      do {                                                             \
         if(g_camera_cntx.active_camera_osd_ptr->##__a__##.is_show)    \
         {                                                             \
            g_camera_cntx.iconbar_item[index] = CAMERA_ICONBAR_##__A__;\
            index++;                                                   \
         }                                                             \
      } while(0);

    INIT_ICONBAR_ITEM(zoom, ZOOM);
    INIT_ICONBAR_ITEM(ev, EV);
    INIT_ICONBAR_ITEM(effect, EFFECT);
    INIT_ICONBAR_ITEM(wb, WB);
    INIT_ICONBAR_ITEM(flash, FLASH);
    INIT_ICONBAR_ITEM(led_highlight, LED_HIGHLIGHT);
    INIT_ICONBAR_ITEM(night, NIGHT);
    INIT_ICONBAR_ITEM(closeup, CLOSEUP);
    INIT_ICONBAR_ITEM(cont_shot, CONT_SHOT);
    INIT_ICONBAR_ITEM(delay_timer, DELAY_TIMER);
    INIT_ICONBAR_ITEM(add_frame, ADD_FRAME);
    INIT_ICONBAR_ITEM(image_size, IMAGE_SIZE);
    INIT_ICONBAR_ITEM(image_qty, IMAGE_QTY);
    INIT_ICONBAR_ITEM(storage, STORAGE);
    INIT_ICONBAR_ITEM(ae_meter, AE_METER);
    INIT_ICONBAR_ITEM(dsc_mode, DSC_MODE);
    INIT_ICONBAR_ITEM(af_meter, FOCUS_METER);
    INIT_ICONBAR_ITEM(af_mode, FOCUS_MODE);
    g_camera_cntx.iconbar_item_count = index;

#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

#ifdef __MMI_SCREEN_SNAPSHOT__
    g_camera_cntx.is_screen_snapshot = FALSE;
#endif 

#ifdef __CAMERA_FEATURE_XENON_FLASH__
    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
#endif

}

#ifdef __CAMERA_FEATURE_XENON_FLASH__
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_xenon_flash_callback
 * DESCRIPTION
 *  xenon flash light indicator (from MED) hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_xenon_flash_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAMERA_STATE_IN(CAMERA_STATE_PREVIEW)||CAMERA_STATE_IN(CAMERA_STATE_SUB_PREVIEW))
    {
        switch(result)
        {
            case MDI_RES_CAMERA_SUCCEED:
                g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_READY;
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
                break;
            case MDI_RES_CAMERA_XENONFLASH_CHARGING:
                if (g_camera_cntx.xenon_flash_state == MMI_CAMERA_XENON_FLASH_CHARGING)
                    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_CHARGING_1;
                else
                    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_CHARGING;

                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
                break;
            case MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT:
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT;
                g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
                g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
                mmi_camera_display_error_popup();                
                break;
            case MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY:
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY;
                g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
                g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
                mmi_camera_display_error_popup();                
                break;
        }
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_del_scr_callback
 * DESCRIPTION
 *  camera delete screen callback handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_camera_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_free_app_mem();

    mmi_imgview_del_scr_callback(NULL);    

    /* for External Request */
    if (g_camera_cntx.is_external_request == TRUE)
    {
        g_camera_cntx.setting.cont_shot = g_camera_cntx.contshot_backup;
        g_camera_cntx.is_external_request = FALSE;
    }


    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_free_app_mem
 * DESCRIPTION
 *  This function is called to free camera app-based memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_free_app_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_mem_pool != NULL)
    {
        applib_mem_ap_free((void*)g_camera_cntx.app_mem_pool);
        g_camera_cntx.app_mem_pool = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_app_mem_stop_callback
 * DESCRIPTION
 *  callback function used by applib to free APP-Based Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free Memory */
    mmi_camera_free_app_mem();

    ASSERT(g_camera_cntx.app_mem_pool != NULL);

    /* free app-based memory */
    applib_mem_ap_free((void*)g_camera_cntx.app_mem_pool);
    g_camera_cntx.app_mem_pool = NULL;

    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_CAMERA,KAL_TRUE);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_app_mem_success_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.app_mem_pool 
        = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_CAMERA, CAMERA_DIRECT_COUPLE_BUFFER_SIZE);
    ASSERT(g_camera_cntx.app_mem_pool!=NULL); /* It should provide enough memory */
    mmi_camera_entry_app_screen();
}


int InCameraScreen = 0 ;
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_app_screen
 * DESCRIPTION
 *  entry camera application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(HORSERACE_SUPPORT)
	//Huyanwei Add It For Flag
	InCameraScreen = 1 ;
#endif
    mmi_camera_load_setting();

#ifdef __USB_IN_NORMAL_MODE__
    mmi_imgview_get_storage_file_path(buf_filepath);

    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8) buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 


#if defined(__MMI_FTS_SUPPORT__) && defined(MMI_CAMERA_CHECK_CONCURRENCY)
    if (mmi_ftp_server_is_receiving())
    {
        g_camera_cntx.last_error = CAMERA_ERR_BT_IS_WORKING;
        mmi_camera_display_error_popup();
        return;
    }
#endif

#if defined(__MMI_OPP_SUPPORT__) && defined(MMI_CAMERA_CHECK_CONCURRENCY)
    if (mmi_opp_is_receiving())
    {
        g_camera_cntx.last_error = CAMERA_ERR_BT_IS_WORKING;
        mmi_camera_display_error_popup();
        return;
    }
#endif

    /* user press camera key when clam close in Idle screen, ignore it */
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    if (IsClamClose())
    {
        if (GetActiveScreenId() == IDLE_SCREEN_ID)
        {
            return;
        }
        else
        {
            DisplayIdleScreen();
            return;
        }
    }
    else if (GetActiveScreenId() != SCR_ID_CAMERA_OPTION)
    {
        g_camera_cntx.is_clam_close = FALSE;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 


    /* allocate memory from App-Based ASM */
    if (g_camera_cntx.app_mem_pool==NULL && CAMERA_DIRECT_COUPLE_BUFFER_SIZE >0)
    {
        g_camera_cntx.app_mem_pool 
            = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_CAMERA, CAMERA_DIRECT_COUPLE_BUFFER_SIZE);

        if (g_camera_cntx.app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_CAMERA,
                IMG_ID_CAMERA_APP_ICON,
                CAMERA_DIRECT_COUPLE_BUFFER_SIZE ,
                mmi_camera_app_mem_success_callback);
            return;
        }       
    }

    #ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
    g_camera_cntx.direct_couple_buffer = (PU8) g_camera_cntx.app_mem_pool;
    g_camera_cntx.is_direct_couple = FALSE;
    #endif

    /* Pass pre-check, enter Camera Application */
    mmi_camera_entry_app_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_pre_initialize_camera_environment
 * DESCRIPTION
 *  entry camera application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_pre_initialize_camera_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_storage;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init some flags */
    g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
    g_camera_cntx.is_dis_clam_open = FALSE;
    g_camera_cntx.tile_cur_num = 0;
    g_camera_cntx.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;
    g_camera_cntx.is_continue_capture = FALSE;

    /* set default up/down key functions */
    if (g_camera_cntx.app_prev_state == CAMERA_STATE_EXIT)
    {
        g_camera_cntx.up_key = CAMERA_ZOOMIN;
        g_camera_cntx.down_key = CAMERA_ZOOMOUT;
        g_camera_cntx.toggle_updown_key = TRUE;
    }

#ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.af_state = AF_CANCEL;
    g_camera_cntx.is_af_capture = FALSE;
    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    if (g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
    {
        mdi_camera_get_focus_steps(&(g_camera_cntx.mf_level_cnt), &(g_camera_cntx.mf_level_idx));
    }
    #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
#endif /* __CAMERA_AUTOFOCUS__ */ 

    if (!g_camera_cntx.is_force_self_capture)
    {
        g_camera_cntx.is_clam_close = FALSE;
    }

    memset(g_camera_cntx.hint1_buf, 0, CAMERA_HINT_BUF_SIZE);
    memset(g_camera_cntx.hint2_buf, 0, CAMERA_HINT_BUF_SIZE);

    /* allocate storage path buffer */
    g_camera_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_camera_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
    cur_storage = g_imgview_context.storage;

    if (mmi_camera_check_and_restore_valid_drv())
    {
        /* drv is valid, create directory */
        mmi_imgview_get_storage_file_path(g_camera_cntx.storage_filepath);
        create_result = mmi_imgview_create_file_dir(g_camera_cntx.storage_filepath);

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = CAMERA_ERR_WRITE_PROTECT;
            g_imgview_context.is_storage_ready = FALSE;
        }
        else if (create_result == FS_DISK_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_CARD_DISK_FULL;
            g_imgview_context.is_storage_ready = FALSE;
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
            g_imgview_context.is_storage_ready = FALSE;
        }
        else
            g_imgview_context.is_storage_ready = TRUE;
    }
    else
    {
        g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
        g_imgview_context.is_storage_ready = FALSE;
    }
}

#if defined(__CAMERA_OSD_HORIZONTAL__)
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_config_layer_orientation
 * DESCRIPTION
 *  config layer orientation while HORIZONTAL_CAMERA is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_config_layer_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_TVOUT__
    /*  
     * Vertical | Horizontal |
     * -------------------------
     * w/o TV | LCD      | LCD        |
     * w   TV | LCD      | LCM        |
     * -------------------------      
     * 
     * * vertical = full sceren play
     * 
     * * gdi_lcd_set_rotate_by_layer(TRUE) = LCD Rotate
     * * gdi_lcd_set_rotate_by_layer(FALSE) = LCM Rotat
     */

    if (!mdi_tvout_is_enable())
    {
        /* tvout not enable */
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else if (g_camera_cntx.is_fullscreen)
    {
        /* tv-out is enable and is vertical display */
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {
        gdi_lcd_set_rotate_by_layer(FALSE);
    }
#else /* __MMI_TVOUT__ */ 
    /* if no tvout, we always use LCD rotate */
    gdi_lcd_set_rotate_by_layer(TRUE);
#endif /* __MMI_TVOUT__ */ 

    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_check_sensor_orientation();
    mmi_camera_check_osd_orientation();

#ifdef __MMI_TVOUT__
    /* since someone change lcd/lcm rotate mechanism (gdi_lcd_set_rotate_by_layer()), 
       we must call this function to change driver's mode */
    if (mdi_tvout_is_enable())
    {
        if (g_camera_cntx.is_fullscreen)
        {
            mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
        }
        else
        {
            mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
        }
    }
#endif /* __MMI_TVOUT__ */ 
}
#endif /* __CAMERA_OSD_HORIZONTAL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_post_initialize_camera_environment
 * DESCRIPTION
 *  init camera after camera power on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_post_initialize_camera_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init advanced dsc mode */
    #if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined (__CAMERA_DSC_MODE_APERTURE_PRI__)
        mmi_camera_init_advanced_dsc_mode();
    #endif 
    mmi_camera_preview_update_capture_size();


    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) 
    #if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__)
    if ((g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0)||(g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_TILE))
    #else
    if ((g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0))
    #endif 
    {
        g_camera_cntx.is_single_osd_layer = TRUE;
    }
    else
    {
        g_camera_cntx.is_single_osd_layer = FALSE;
    }
    #endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

    /* create preview resource */
    mmi_camera_preview_create_resource();

    /* config layer/lcd orientation if HORIZONTAL_CAMERA */
    #if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_camera_config_layer_orientation();
    #endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_initialize_framework_environment
 * DESCRIPTION
 *  entry camera application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_initialize_framework_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* turn off 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_camera_cntx.is_3d_sound_on = mmi_settings_audio_reverb_get_status();
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_off();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* 
     * This is used to solve a very rare situation. When playing a IMELODY 
     * with backlight on/off, and the screen previous to this screen is a 
     * horizontal screen. Before enter this screen, the IMELODY turn off the
     * backlight. While exit previous screen, the layer rotate back to normal
     * size and the content is not correct. So when calling TurnOnBacklight, 
     * LCD is in sleepin state and draw wrong content to LCD.
     * So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* stop LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_GET);

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

   /*********** init layer var ************/
    /* get mainlcd based layer handle */
    gdi_layer_get_base_handle(&g_camera_cntx.base_layer_handle);

    /* get sublcd base layer handle */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_camera_cntx.sublcd_base_layer_handle);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

   /************ draw sublcd and hook msg hdlr ************/
    /* entry sublcd */
    if (!g_camera_cntx.is_sublcd_display)
    {
        ForceSubLCDScreen(mmi_camera_entry_sublcd_screen);
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(
        MMI_FRM_INT_CLAM,
        mmi_camera_clam_close_event_hdlr,
        NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_app_screen_internal
 * DESCRIPTION
 *  entry camera application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_entry_app_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* debug info */
    CAMERA_TRACE_FUNC_ENTER_APP();
    CAMERA_CHECK_STATE(CAMERA_STATE_EXIT);

    /* if clam is opened and not enter from camera option menu */
    if (GetActiveScreenId() != SCR_ID_CAMERA_OPTION && g_camera_cntx.is_clam_close == FALSE)
    {
        /* reset force enter sub flag */
        g_camera_cntx.is_force_self_capture = FALSE;
    }

    /************ entry screen ************/
    if (g_camera_cntx.is_external_request == FALSE)
    {
        EntryNewScreen(SCR_ID_CAMERA_APP, mmi_camera_exit_app_screen, mmi_camera_entry_app_screen, MMI_FULL_SCREEN);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_APP);
        SetDelScrnIDCallbackHandler(SCR_ID_CAMERA_APP, mmi_camera_del_scr_callback);
    }
    else
    {
        /* for External Request */
        EntryNewScreen(SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN, mmi_camera_exit_app_screen, mmi_camera_entry_app_screen, MMI_FULL_SCREEN);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN);    
        SetDelScrnIDCallbackHandler(SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN, mmi_camera_del_scr_callback);
    }

    #if defined(__CAMERA_FEATURE_STORAGE__)
    /* if storage is not ready, entry select storage screen */
    if (g_imgview_context.is_storage_ready == FALSE)
    {
        mmi_camera_entry_storage_screen();
        return ;
    }
    #endif

    /* each time newly enter camera, zoom will be reset to default */
    if (guiBuffer == NULL)
    {
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    }

    /************ init/config framework's environment  ************/
    mmi_camera_initialize_framework_environment();

    /************ pre-init camera app environment ************
     * 1. init some flag before power on camera
     * 2. check storage 
     ********************************************************/
    mmi_camera_pre_initialize_camera_environment();


    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)
    {
        /* Power on and init hardware module */
        g_camera_cntx.last_error = mdi_camera_power_on();
    }

    /************ post-init camera app environment ************
    * no matter power on success or not, have to do post init
    *********************************************************/
    mmi_camera_post_initialize_camera_environment();


    /* check if there is small screen above camera */
    #ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }
    #endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 

   /************ enter next state ************/
    if ((g_camera_cntx.is_force_self_capture) && (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED))  /* no error, if has error, will enter main then show error popup */
    {
        /* force to enter sublcd preview from option menu */
    #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
        g_camera_cntx.is_force_self_capture = FALSE;
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
    #else 
        MMI_ASSERT(0);
    #endif
    }
    else
    {
        /* entry preview */
        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
    }

#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_camera_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_camera_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_camera_touch_scr_pen_move_hdlr);
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_app_screen
 * DESCRIPTION
 *  exit camera application screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print debug info */
    CAMERA_TRACE_FUNC_EXIT_APP();

    /* exit camera state */
    CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
    

/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)
	if((kal_uint16) camera_setting_p->flash == 1)
	{
		noke_mmi_camera_flash_light_on(KAL_FALSE);
	}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */

    /* stop capture and stop dummy bg midi for multi-channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    mmi_camera_burstshot_close_multi_sound();
    gui_cancel_timer(mmi_camera_burstshot_close_multi_sound);
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

    /* reset af related var */
#if defined(__CAMERA_AUTOFOCUS__)
    /* !IMPORTANT! Manual focus should not be turned on, it is not a matual function */
    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    if ((g_camera_cntx.setting.af_mode != CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL) && (g_camera_cntx.af_state != AF_CANCEL))
    #else 
    if (g_camera_cntx.af_state != AF_CANCEL)
    #endif 
    {
        mdi_camera_stop_autofocus_process();
        g_camera_cntx.af_state = AF_CANCEL;
    }
#endif /* defined(__CAMERA_AUTOFOCUS__) */ 

    /* stop hide hint timer */
    gui_cancel_timer(mmi_camera_preview_hide_hint);

    /* turn on/of 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_on();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 

    /* shut down camera */
    mdi_camera_power_off();

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_RELEASE);

    /* let MMI can sleep */
    TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* free buffer */
    gui_free(g_camera_cntx.storage_filepath);
    g_camera_cntx.storage_filepath = NULL;

#ifdef __MMI_SUBLCD__
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
    gdi_layer_pop_and_restore_active();

    /* exit sublcd */
    if (g_camera_cntx.is_sublcd_display)
    {
        GoBackSubLCDHistory();
        g_camera_cntx.is_sublcd_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* un-hook clam close msg */
    ClearInterruptEventHandler(MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

#if defined(__CAMERA_OSD_HORIZONTAL__)
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_rotate_by_layer(FALSE);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    g_imgview_context.imgview_rotate = CAMERA_DISPLAY_ROTATE_0;
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    mmi_camera_preview_free_preview_resource();

    /* free preview resource */
    mmi_camera_preview_free_resource();

    /* store camera setting back to NVRAM */
    mmi_camera_store_setting();

    /* store imageviewer's setting */
    WriteValue(NVRAM_IMGVIEW_STORAGE, &g_imgview_context.storage, DS_SHORT, &error);

    /* this will force title status to redraw */
    entry_full_screen();

#ifdef DOUBLE_CAMERA_SUPPORT
//Huyanwei Add It For Restore It 	
	mmi_main_camera_active=KAL_TRUE; 
	double_cam = ((mmi_main_camera_active == KAL_TRUE)?0:1);
#endif

#if defined(HORSERACE_SUPPORT)
//Huyanwei Add It For Flag
InCameraScreen = 0 ;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_enter_state
 * DESCRIPTION
 *  enter next state
 * PARAMETERS
 *  state       [IN]        State to enter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_enter_state(camera_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.app_prev_state = g_camera_cntx.app_state;
    g_camera_cntx.app_state = state;

    switch (state)
    {
        case CAMERA_STATE_EXIT:
            /* do nothing */
            break;

            /* main lcd */
        case CAMERA_STATE_PREVIEW:
            mmi_camera_entry_preview_state();
            break;

        case CAMERA_STATE_COUNTDOWN:
            mmi_camera_entry_countdown_state();
            break;

        case CAMERA_STATE_CONTSHOT:
/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)
		if((kal_uint16) camera_setting_p->flash == 1)
		{
			noke_mmi_camera_flash_light_on(KAL_TRUE);
		}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */
            mmi_camera_entry_contshot_state();
            break;

    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__

        case CAMERA_STATE_BURSTSHOT:
/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)
		if((kal_uint16) camera_setting_p->flash == 1)
		{
			noke_mmi_camera_flash_light_on(KAL_TRUE);
		}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */
            mmi_camera_entry_burstshot_capture_state();
            break;

        case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
            mmi_camera_entry_burstshot_save_confirm_state();
            break;

        case CAMERA_STATE_BURSTSHOT_SAVING:
            mmi_camera_entry_burstshot_saving_state();
            break;

    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

        case CAMERA_STATE_SAVE_DONE:
            mmi_camera_entry_save_done_state();
            break;

        case CAMERA_STATE_SAVE_CONFIRM:
            mmi_camera_entry_save_confirm_state();
            break;

    #ifdef __CAMERA_FEATURE_SELF_CAPTURE__

            /* toggle popup */
        case CAMERA_STATE_TOGGLE_TO_SUB:
            mmi_camera_entry_toggle_to_sub_state();
            break;

        case CAMERA_STATE_TOGGLE_TO_MAIN:
            mmi_camera_entry_toggle_to_main_state();
            break;

            /* sub lcd */
        case CAMERA_STATE_SUB_PREVIEW:
            mmi_camera_entry_sublcd_preview_state();
            break;

        case CAMERA_STATE_SUB_COUNTDOWN:
            mmi_camera_entry_sublcd_countdown_state();
            break;

        case CAMERA_STATE_SUB_CONTSHOT:
            mmi_camera_entry_sublcd_contshot_state();
            break;

    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        case CAMERA_STATE_SUB_BURSTSHOT:
            mmi_camera_entry_sublcd_burstshot_state();
            break;

        case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
            mmi_camera_entry_sublcd_burstshot_saving_state();
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    #endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_current_state
 * DESCRIPTION
 *  exit camera current state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_current_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)
		if((kal_uint16) camera_setting_p->flash == 1)
		{
			noke_mmi_camera_flash_light_on(KAL_FALSE);
		}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */
    switch (g_camera_cntx.app_state)
    {
        case CAMERA_STATE_EXIT:
            /* do nothing */
            break;

            /* main lcd */
        case CAMERA_STATE_PREVIEW:
            mmi_camera_exit_preview_state();
            break;

        case CAMERA_STATE_COUNTDOWN:
            mmi_camera_exit_countdown_state();
            break;

        case CAMERA_STATE_CONTSHOT:
            mmi_camera_exit_contshot_state();
            break;

    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__

        case CAMERA_STATE_BURSTSHOT:
            mmi_camera_exit_burstshot_capture_state();
            break;

        case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
            mmi_camera_exit_burstshot_save_confirm_state();
            break;

        case CAMERA_STATE_BURSTSHOT_SAVING:
            mmi_camera_exit_burstshot_saving_state();
            break;

    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

        case CAMERA_STATE_SAVE_DONE:
            mmi_camera_exit_save_done_state();
            break;

        case CAMERA_STATE_SAVE_CONFIRM:
            mmi_camera_exit_save_confirm_state();
            break;

    #ifdef __CAMERA_FEATURE_SELF_CAPTURE__

            /* toggle popup */
        case CAMERA_STATE_TOGGLE_TO_SUB:
            mmi_camera_exit_toggle_to_sub_state();
            break;

        case CAMERA_STATE_TOGGLE_TO_MAIN:
            mmi_camera_exit_toggle_to_main_state();
            break;

            /* sub lcd */
        case CAMERA_STATE_SUB_PREVIEW:
            mmi_camera_exit_sublcd_preview_state();
            break;

        case CAMERA_STATE_SUB_COUNTDOWN:
            mmi_camera_exit_sublcd_countdown_state();
            break;

        case CAMERA_STATE_SUB_CONTSHOT:
            mmi_camera_exit_sublcd_contshot_state();
            break;

    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        case CAMERA_STATE_SUB_BURSTSHOT:
            mmi_camera_exit_sublcd_burstshot_state();
            break;

        case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
            mmi_camera_exit_sublcd_burstshot_saving_state();
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    #endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_clam_close_event_hdlr
 * DESCRIPTION
 *  handle clam close event
 * PARAMETERS
 *  ptr     [IN]        Message data ptr
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
U8 mmi_camera_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
    {
        g_camera_cntx.is_clam_close = TRUE;
        SetClamState(EXT_DEV_CLAM_CLOSE);

        /* print debug info */
        CAMERA_TRACE_CLAM_CLOSE_EVENT();

        switch (g_camera_cntx.app_state)
        {
                /* main lcd */
            case CAMERA_STATE_PREVIEW:
            case CAMERA_STATE_COUNTDOWN:
            case CAMERA_STATE_CONTSHOT:
            case CAMERA_STATE_BURSTSHOT:
            case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
            case CAMERA_STATE_BURSTSHOT_SAVING:
            case CAMERA_STATE_SAVE_DONE:
            case CAMERA_STATE_SAVE_CONFIRM:
            case CAMERA_STATE_TOGGLE_TO_MAIN:
            case CAMERA_STATE_TOGGLE_TO_SUB:
                /* if clam close will not back to idle, goback to previous screen */
        #ifndef __MMI_CLAMCLOSE_BACK2IDLE__
                GoBackHistory();
        #endif 

                return FALSE;   /* pass this interrupt to framwork's handler */
                break;
                /* sub lcd */
            case CAMERA_STATE_SUB_COUNTDOWN:
            case CAMERA_STATE_SUB_CONTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
                CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
                mmi_gpio_detect_send_ack(interrupt_event);
                return TRUE;    /* block this event - do not call default handler */
                break;

            case CAMERA_STATE_SUB_PREVIEW:
        #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                /* stop and restart sublcd preview, will display correcly according to clam close/open */
                mmi_camera_sublcd_preview_stop();

                /* config rotate of preview layer, only ISP_SUPPORT need */
        #if defined(ISP_SUPPORT)
                gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
                gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
                gdi_layer_pop_and_restore_active();
        #endif /* defined(ISP_SUPPORT) */ 

                mmi_camera_sublcd_preview_start();
                mmi_gpio_detect_send_ack(interrupt_event);
                return TRUE;    /* block this event - do not call default handler */
        #else /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
                MMI_ASSERT(0);
        #endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
                break;

            default:
                MMI_ASSERT(0);  /* make sure all state is handled */
                break;
        }
    }
    else if (interrupt_event == EXT_DEV_CLAM_OPEN)
    {
        g_camera_cntx.is_clam_close = FALSE;
        SetClamState(EXT_DEV_CLAM_OPEN);

        /* print debug info */
        CAMERA_TRACE_CLAM_OPEN_EVENT();

        switch (g_camera_cntx.app_state)
        {
                /* main lcd */
            case CAMERA_STATE_PREVIEW:
            case CAMERA_STATE_COUNTDOWN:
            case CAMERA_STATE_CONTSHOT:
            case CAMERA_STATE_BURSTSHOT:
            case CAMERA_STATE_BURSTSHOT_SAVING:
            case CAMERA_STATE_SAVE_DONE:
            case CAMERA_STATE_TOGGLE_TO_MAIN:
            case CAMERA_STATE_TOGGLE_TO_SUB:
                /* clam open do nothing */
                return FALSE;   /* pass this interrupt to framwork's handler */
                break;

            case CAMERA_STATE_SAVE_CONFIRM:
                /* 
                 * this may happened when user capture tile image on sub. and all images
                 * are captured and enter save confirm state 
                 */
                if (g_camera_cntx.is_dis_clam_open)
                {
                    /* block this event - do not call default handler */
                    g_camera_cntx.is_dis_clam_open = FALSE;
                    mmi_gpio_detect_send_ack(interrupt_event);
                    return TRUE;
                }
                else
                {
                    return FALSE;
                }
                break;

                /* sub lcd */
            case CAMERA_STATE_SUB_COUNTDOWN:
            case CAMERA_STATE_SUB_CONTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
                CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
                mmi_gpio_detect_send_ack(interrupt_event);
                return TRUE;    /* block this event - do not call default handler */
                break;

            case CAMERA_STATE_SUB_PREVIEW:
            #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                /* stop and restart sublcd preview, will display correcly according to clam close/open */
                mmi_camera_sublcd_preview_stop();

                /* config rotate of preview layer, only ISP_SUPPORT need */
            #if defined(ISP_SUPPORT)
                gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
                gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE);
                gdi_layer_pop_and_restore_active();
            #endif /* defined(ISP_SUPPORT) */ 

                mmi_camera_sublcd_preview_start();
                mmi_gpio_detect_send_ack(interrupt_event);
                return TRUE;    /* block this event - do not call default handler */
            #else /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
                MMI_ASSERT(0);
            #endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
                break;

            default:
                MMI_ASSERT(0);  /* make sure all state is handled */
                break;
        }
    }


    /* return false means will pass this interrut to default handler */
    return FALSE;
}
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_calc_remain_storage
 * DESCRIPTION
 *  calculate remain storage precent
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_calc_remain_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    S8 disk_path[10];
    U32 disk_free_space;
    U32 disk_total_space;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get disk name, calculate available disk space */
    memset(disk_path, 0, sizeof(disk_path));

    mmi_camera_get_storage_disk_path(disk_path);
    fs_ret = FS_GetDiskInfo((kal_uint16*) disk_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    g_camera_cntx.remain_percent = 0;

    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters;
        disk_total_space = disk_info.TotalClusters;

        if (disk_total_space > 0)
        {
            g_camera_cntx.remain_percent = (U8) (disk_free_space * 100 / disk_total_space);
        }
        else
        {
            g_camera_cntx.remain_percent = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_toggle_hide_osd
 * DESCRIPTION
 *  toggle hide osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_toggle_hide_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_hide_osd = (g_camera_cntx.is_hide_osd) ? FALSE : TRUE;
    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_toggle_self_capture
 * DESCRIPTION
 *  toggle self capture (Main/Sub)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_self_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_TOGGLE_TO_SUB);
    }
    else if (g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW)
    {
        /* only when clam is open may toggle to main */
        if (!g_camera_cntx.is_clam_close)
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_TOGGLE_TO_MAIN);
        }
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_turn_on_preview_led_highlight
 * DESCRIPTION
 *  turn on preview led highlght
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_turn_on_preview_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    duty = (U8) g_camera_cntx.setting.preview_led_value;

    if (duty == 0)
    {
        custom_stop_flashlight();
        return;
    }

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    switch (g_camera_cntx.setting.led_highlight)
    {
        case CAMERA_SETTING_LED_HIGHLIGHT_WHITE:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_RED:
            custom_start_flashlight(1, 0, 0, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_GREEN:
            custom_start_flashlight(0, 1, 0, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_BLUE:
            custom_start_flashlight(0, 0, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_YELLOW:
            custom_start_flashlight(1, 1, 0, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_PURPLE:
            custom_start_flashlight(1, 0, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_CYAN:
            custom_start_flashlight(0, 1, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
            custom_stop_flashlight();
            break;

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__ */ 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    switch (g_camera_cntx.setting.led_highlight)
    {
        case CAMERA_SETTING_LED_HIGHLIGHT_ON:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
            custom_stop_flashlight();
            break;

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_turn_on_capture_led_highlight
 * DESCRIPTION
 *  turn on preview led highlght
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_turn_on_capture_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    duty = (U8) g_camera_cntx.setting.capture_led_value;

    if (duty == 0)
    {
        custom_stop_flashlight();
        return;
    }

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    switch (g_camera_cntx.setting.led_highlight)
    {
        case CAMERA_SETTING_LED_HIGHLIGHT_WHITE:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_RED:
            custom_start_flashlight(1, 0, 0, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_GREEN:
            custom_start_flashlight(0, 1, 0, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_BLUE:
            custom_start_flashlight(0, 0, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_YELLOW:
            custom_start_flashlight(1, 1, 0, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_PURPLE:
            custom_start_flashlight(1, 0, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_CYAN:
            custom_start_flashlight(0, 1, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
            custom_stop_flashlight();
            break;

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__ */ 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    switch (g_camera_cntx.setting.led_highlight)
    {
        case CAMERA_SETTING_LED_HIGHLIGHT_ON:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
            custom_stop_flashlight();
            break;

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_turn_off_led_highlight
 * DESCRIPTION
 *  turn off preview led highlght
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_turn_off_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_stop_flashlight();
}

/*****************************************************************************
*
*  Camera Main LCD Preview State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_preview_state
 * DESCRIPTION
 *  entry mainlcd preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_entry_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /************ init global var ************/
    g_camera_cntx.is_clam_close = FALSE;
    g_camera_cntx.is_lsk_pressed = FALSE;
    g_camera_cntx.is_rsk_pressed = FALSE;
    g_camera_cntx.is_ev_inc_pressed = FALSE;
    g_camera_cntx.is_ev_dec_pressed= FALSE;
    g_camera_cntx.is_up_arrow_pressed = FALSE;
    g_camera_cntx.is_down_arrow_pressed = FALSE;
    g_camera_cntx.is_capturing = FALSE;
    g_camera_cntx.is_fast_zoom = FALSE;
    g_camera_cntx.is_draw_timer_on = FALSE;
    /* for remove focus zone */
    #ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.is_autofocus_pressed = FALSE;
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            g_camera_cntx.is_mf_continue = FALSE;
        #endif 
    #endif
    g_camera_cntx.touch_effect.is_press = FALSE;
    g_camera_cntx.touch_wb.is_press = FALSE;
    g_camera_cntx.touch_flash.is_press = FALSE;
    g_camera_cntx.touch_led_highlight.is_press = FALSE;
    g_camera_cntx.touch_night.is_press = FALSE;
    g_camera_cntx.touch_image_size.is_press = FALSE;
    g_camera_cntx.touch_image_qty.is_press = FALSE;
    g_camera_cntx.touch_cont_shot.is_press = FALSE;
    g_camera_cntx.touch_delay_timer.is_press = FALSE;
    g_camera_cntx.touch_storage.is_press = FALSE;
    g_camera_cntx.touch_ev_inc.is_press = FALSE;
    g_camera_cntx.touch_ev_dec.is_press = FALSE;
    g_camera_cntx.touch_zoom_inc.is_press = FALSE;
    g_camera_cntx.touch_zoom_dec.is_press = FALSE;
    g_camera_cntx.touch_capture.is_press = FALSE;
    g_camera_cntx.touch_mms_icon.is_press = FALSE;
    g_camera_cntx.touch_dsc_mode.is_press = FALSE;
    g_camera_cntx.touch_af_mode.is_press = FALSE;
    g_camera_cntx.touch_af_meter.is_press = FALSE;
    g_camera_cntx.touch_zoom_mf_toggle.is_press = FALSE;

    /* calculate remain storage */
    mmi_camera_calc_remain_storage();

    /* update preview/capture size para */
    mmi_camera_preview_update_capture_size();

    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) 
    #if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__)
    if ((g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0)||(g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_TILE))
    #else
    if ((g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0))
    #endif 
    {
        if (g_camera_cntx.is_single_osd_layer != TRUE)
        {
            g_camera_cntx.is_single_osd_layer = TRUE;
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
        }
    }
    else
    {
        if (g_camera_cntx.is_single_osd_layer != FALSE)
        {
            g_camera_cntx.is_single_osd_layer = FALSE;
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
        }
    }
    #endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 


#if defined(__CAMERA_OSD_HORIZONTAL__)
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_check_sensor_orientation();
    mmi_camera_check_osd_orientation();
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
#endif 

#ifdef __MMI_SUBLCD__
    /* draw sublcd icon */
    mmi_camera_sublcd_draw_icon();
#endif /* __MMI_SUBLCD__ */ 


    if (g_camera_cntx.app_prev_state != CAMERA_STATE_CONTSHOT)
    {
        S32 offset_x = 0;
        S32 offset_y = 0;

    #ifdef HORIZONTAL_CAMERA
        offset_y = (LCD_WIDTH - g_camera_cntx.preview_height) >> 1;
    #else 
        offset_y = (LCD_HEIGHT - g_camera_cntx.preview_height) >> 1;
    #endif 
        mmi_camera_preview_free_preview_resource();
        mmi_camera_preview_create_preview_resource(
            offset_x,
            offset_y,
            g_camera_cntx.preview_width,
            g_camera_cntx.preview_height,
            g_camera_cntx.lcm_rotate);
    }

    /* init title bar */
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        reset_title_status_icon();
        show_status_icon_bar(0);
    #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

        /* hide short cut */
        MMI_menu_shortcut_number = -1;

        if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_caption)
        {
            ChangeTitle(MAIN_MENU_TITLE_MULTIMEDIA_ICON, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
        else
        {
            ChangeTitle(0, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
    }
    else
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
    #endif 
    }

    /* register keys */
    mmi_camera_preview_set_key_hdlr();

    /* clear base layer bg */
    if (g_camera_cntx.app_prev_state != CAMERA_STATE_CONTSHOT)
    {
        mmi_camera_preview_clear_background();
    }

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    if (g_camera_cntx.is_tileshot)
    {
        /* is in tile shot, we do not clear bg when from countdown and sub preview state */
        if (!(g_camera_cntx.app_prev_state == CAMERA_STATE_COUNTDOWN) &&
            !(g_camera_cntx.app_prev_state == CAMERA_STATE_TOGGLE_TO_MAIN))
        {
            mmi_camera_init_tileshot_layer();
        }
    }
    else
    {
        mmi_camera_init_tileshot_layer();
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_create_add_frame_layer();
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

    /* draw panel and softkey */
    mmi_camera_preview_set_hint(NULL, NULL, 0);
    mmi_camera_preview_draw_osd();

    /* set blt layer for non-previwing, and blt first skin */
    mmi_camera_preview_set_blt_layer(FALSE);
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    /* check if any error occurs in mmi_camera_entry_app_screen function */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }
    else
    {
        /* if no error occurs, start preview */
        mmi_camera_preview_set_blt_layer(TRUE);
        mmi_camera_preview_start();
    }

    /* check if preview success */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }

    /*
     * added the following code here for the max zoom factor can be retrieved correctly 
     * * only when camera has started preview at least once. So the following code is for 
     * * camera to get the correct max zoom factor and redraw the osd in case there should 
     * * be a zoom in/out bar.
     */

    #if !defined(__VGA_8XZOOM__) && defined(ISP_SUPPORT) && defined(__MTK_TARGET__)
        /* get zoom_limit from sensor driver */
        if ((g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)&&(g_camera_cntx.has_camera_previewed == FALSE))
        {
            g_camera_cntx.has_camera_previewed = TRUE;
            mmi_camera_initilize_zoom_factor();
        }
    #endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 


}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_preview_state
 * DESCRIPTION
 *  exit preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop timer */
    if (g_camera_cntx.app_next_state != CAMERA_STATE_COUNTDOWN)
    {
        gui_cancel_timer(mmi_camera_preview_hide_hint);
    }

#ifdef __CAMERA_FEATURE_ZOOM__
    gui_cancel_timer(mmi_camera_preview_zoom_out);
    gui_cancel_timer(mmi_camera_preview_zoom_in);
#endif /* __CAMERA_FEATURE_ZOOM__ */ 

#ifdef __CAMERA_FEATURE_EV__
    gui_cancel_timer(mmi_camera_preview_ev_inc_key_press);
    gui_cancel_timer(mmi_camera_preview_ev_dec_key_press);
#endif

#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
    mmi_camera_stop_fast_zoom();

    gui_cancel_timer(mmi_camera_start_fast_zoom_out);
    gui_cancel_timer(mmi_camera_start_fast_zoom_in);
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 

    gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
    g_camera_cntx.is_draw_timer_on = FALSE;

    /* there are some setting changed by using hotkey or preview panel, save them to NVRAM */
    mmi_camera_store_setting();

    /* exit app */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_preview_stop();

    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        /* copy tiled picture from tile result layer to base layer */
        if (g_camera_cntx.is_tileshot)
        {
        #ifdef __CAMERA_FEATURE_ADD_FRAME__
            /* if has add frame, merge layers to base  */
            gdi_layer_flatten_to_base(
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.add_frame_layer_handle,
                0,
                0);
        #else /* __CAMERA_FEATURE_ADD_FRAME__ */ 
            /* no add frame */
            gdi_layer_flatten_to_base(g_camera_cntx.tileshot_result_layer_handle, 0, 0, 0);
        #endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 
        }
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }

    /* toggle to sub */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_TOGGLE_TO_SUB)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_preview_stop();

    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        /* copy tiled picture from tile result layer to base layer */
        if (g_camera_cntx.is_tileshot)
        {
        #ifdef __CAMERA_FEATURE_ADD_FRAME__
            /* if has add frame, merge layers to base  */
            gdi_layer_flatten_to_base(
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.add_frame_layer_handle,
                0,
                0);
        #else /* __CAMERA_FEATURE_ADD_FRAME__ */ 
            /* no add frame */
            gdi_layer_flatten_to_base(g_camera_cntx.tileshot_result_layer_handle, 0, 0, 0);
        #endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 
        }
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

        mmi_camera_preview_free_preview_resource();

        if (g_camera_cntx.is_fullscreen)
        {
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.add_frame_layer_handle, 0, 0);
        }
        else
        {
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
        }

    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
    #endif 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_set_key_hdlr
 * DESCRIPTION
 *  set key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_set_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    /* register soft keys */
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

#ifdef __CAMERA_AUTOFOCUS__
    SetKeyHandler(mmi_camera_capture_button_autofocus_pressed, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_DOWN);
    SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_UP);
#ifdef __MMI_CAMERA_AF_TEST__
    /* 50 cont shot */
    SetKeyHandler(mmi_camera_af_test, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_capture_button_autofocus_pressed, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_1, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_camera_capture_button_autofocus_released, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_af_and_capture, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_0, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_camera_capture_button_autofocus_released, KEY_0, KEY_EVENT_UP);
#endif /* __MMI_CAMERA_AF_TEST__ */ 
#endif /* __CAMERA_AUTOFOCUS__ */ 

#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
      /*************************************/
    /* IconBar Panel Key                 */
      /*************************************/
    SetKeyHandler(mmi_camera_iconbar_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_iconbar_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_iconbar_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_iconbar_left_arrow_releas, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_iconbar_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_iconbar_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_iconbar_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_iconbar_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

    /* register capture and control keys */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        #ifdef __AF_SUPPORT_ONE_KEY__
        SetKeyHandler(mmi_camera_af_and_capture, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
        #else
        SetKeyHandler(mmi_camera_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
        #endif
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_UP);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
        SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_UP);
    }
	 


#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    SetKeyHandler(mmi_camera_toggle_self_capture, (U16) CAMERA_TOGGLE_SELF_CAPTURE_KEY, KEY_EVENT_DOWN);
#endif 

#else /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 
      /*************************************/
    /* Normal Key                        */
      /*************************************/

    /* change add frame hotkey - side keys */
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    SetKeyHandler(mmi_camera_preview_change_frame_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_change_frame_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

    /* register capture and control keys */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        #ifdef __AF_SUPPORT_ONE_KEY__
        SetKeyHandler(mmi_camera_af_and_capture, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
        #else
        SetKeyHandler(mmi_camera_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
        #endif
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_UP);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
        SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_UP);
    }



    /* ev / zooming */
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_90 || g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        SetKeyHandler(mmi_camera_preview_ev_inc_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_inc_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_preview_ev_dec_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_dec_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_camera_preview_ev_inc_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_inc_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_preview_ev_dec_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_dec_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
#ifdef __CAMERA_FEATURE_ZOOM__
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_90 || g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        SetKeyHandler(mmi_camera_preview_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_preview_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_camera_preview_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_preview_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
    }
#endif /* __CAMERA_FEATURE_ZOOM__ */ 

    /* hot keys */
#ifdef __CAMERA_FEATURE_EFFECT__
    if (CAMERA_EFFECT_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_effect_hotkey_press, (U16) CAMERA_EFFECT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_EFFECT__ */ 

#ifdef __CAMERA_FEATURE_WB__
    if (CAMERA_WB_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_wb_hotkey_press, (U16) CAMERA_WB_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_WB__ */ 

#ifdef __CAMERA_FEATURE_NIGHT__
    if (CAMERA_NIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_night_hotkey_press, (U16) CAMERA_NIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_NIGHT__ */ 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
    if (CAMERA_LED_HIGHLIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_led_highlight_hotkey_press, (U16) CAMERA_LED_HIGHLIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT__ */ 

#ifdef __CAMERA_FEATURE_FLASH__
    if (CAMERA_FLASH_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_flash_hotkey_press, (U16) CAMERA_FLASH_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_FLASH__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT__
    if (g_camera_cntx.is_external_request == FALSE)
    {
        if (CAMERA_CONT_SHOT_KEY != -1)
        {
            SetKeyHandler(mmi_camera_preview_cont_shot_hotkey_press, (U16) CAMERA_CONT_SHOT_KEY, KEY_EVENT_DOWN);
        }
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT__ */ 

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
    if (CAMERA_DELAY_TIMER_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_delay_timer_hotkey_press, (U16) CAMERA_DELAY_TIMER_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */ 

    if (CAMERA_IMAGE_SIZE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_image_size_hotkey_press, (U16) CAMERA_IMAGE_SIZE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_IMAGE_QTY_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_image_qty_hotkey_press, (U16) CAMERA_IMAGE_QTY_KEY, KEY_EVENT_DOWN);
    }

#ifdef __CAMERA_DSC_MODE__
    if (CAMERA_DSC_MODE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_dsc_mode_hotkey_press, (U16) CAMERA_DSC_MODE_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_DSC_MODE__ */ 

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
    if (CAMERA_ISO_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_iso_hotkey_press, (U16) CAMERA_ISO_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */ 

#ifdef __CAMERA_FEATURE_AE_METER__
    if (CAMERA_AE_METER_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_ae_meter_hotkey_press, (U16) CAMERA_AE_METER_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_AE_METER__ */ 

#ifdef __CAMERA_FEATURE_STORAGE__
    if (CAMERA_STORAGE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_storage_hotkey_press, (U16) CAMERA_STORAGE_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_STORAGE__ */ 

#ifdef __CAMERA_AUTOFOCUS_METERING__
    if (CAMERA_AF_METER_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_af_meter_hotkey_press, (U16) CAMERA_AF_METER_KEY, KEY_EVENT_DOWN);
    }
#endif 

#ifdef __CAMERA_AUTOFOCUS_MODE__
    if (CAMERA_AF_MODE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_af_mode_hotkey_press, (U16) CAMERA_AF_MODE_KEY, KEY_EVENT_DOWN);
    }
#endif

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    SetKeyHandler(mmi_camera_toggle_self_capture, (U16) CAMERA_TOGGLE_SELF_CAPTURE_KEY, KEY_EVENT_DOWN);
#endif 

    /* toggle hide OSD */
    SetKeyHandler(mmi_camera_toggle_hide_osd, CAMERA_TOGGLE_HIDE_OSD_KEY, KEY_EVENT_DOWN);

#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 
/* 2009.xx.xx Huyanwei Add It For Camere Captrue + */
        SetKeyHandler(mmi_camera_capture_button_press, KEY_CAMERA, KEY_EVENT_DOWN);
/* 2009.xx.xx Huyanwei Add It For Camere Captrue - */
#ifdef NO_LSK  //yuyang
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_SEND1, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_capture_button_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, KEY_LSK, KEY_EVENT_UP);//ghw222
#endif
#ifdef DOUBLE_CAMERA_SUPPORT  
//Huyanwei Add It     
    #ifndef WIN32
    //SetKeyHandler(mmi_double_camera_switch_handler, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_double_cam_key_press, KEY_0, KEY_EVENT_DOWN);    
    #endif  
#endif

}

#ifdef __CAMERA_AUTOFOCUS__

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_play_af_succeed_finished
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_play_af_succeed_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_audio_finished = TRUE;

    /* check if af is calculating by user half press soon after af callback,
       if no, reset is_autofocus_pressed flag , 2007/10/31 */
    if (g_camera_cntx.af_state != AF_CALCULATE)
        g_camera_cntx.is_autofocus_pressed = FALSE;    

    if (g_camera_cntx.is_af_capture == TRUE)
    {
        g_camera_cntx.is_af_capture = FALSE;
        mmi_camera_capture_button_press();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_autofocus_callback
 * DESCRIPTION
 *  callback while AF is succeed/fail
 * PARAMETERS
 *  result      [IN]        
 *  void(?)     [OUT]       PMsg
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_autofocus_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* parse pMsg to get result */
    /* and response to osd layer */
    if (g_camera_cntx.af_state == AF_CANCEL)
    {
        return;
    }

    g_camera_cntx.af_result = (U8) result;

    if (g_camera_cntx.app_state != CAMERA_STATE_EXIT)
    {
        if (g_camera_cntx.af_result == 0xFF)
        {
            g_camera_cntx.af_state = AF_FAIL;
            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_camera_preview_draw_osd_timer);

            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            if (g_camera_cntx.is_af_capture == TRUE)
            {
                g_camera_cntx.is_af_capture = FALSE;
                mmi_camera_capture_button_press();
            }

            /* reset is_autofocus_pressed flag */
            g_camera_cntx.is_autofocus_pressed = FALSE;
    
        }
        else
        {
            g_camera_cntx.af_state = AF_SUCCEED;

            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            {   /* play sound tmp */

                BEFORE_PLAY_AUDIO();

                if (g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
            #if defined(__MMI_CAMERA_HIGH_END__)
                    mdi_audio_play_string_with_vol_path(
                        (void*)camera_af_succeed,
                        (U32) CAMERA_SOUND_AF_SUCCEED_LEN,
                        MDI_FORMAT_WAV,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        (mdi_callback) mmi_camera_play_af_succeed_finished,
                        CAMERA_SHUTTER_SOUND_VOLUMN,
                        MDI_DEVICE_SPEAKER_BOTH);
            #else /* __MMI_CAMERA_HIGH_END__ */ 
                    mdi_audio_play_string_with_vol_path(
                        (void*)camera_sound_shutter_3,
                        (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                        MDI_FORMAT_DVI_ADPCM,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        (mdi_callback) mmi_camera_play_af_succeed_finished,
                        CAMERA_SHUTTER_SOUND_VOLUMN,
                        MDI_DEVICE_SPEAKER_BOTH);
            #endif /* __MMI_CAMERA_HIGH_END__ */ 
                else
                {
                    mmi_camera_play_af_succeed_finished();
                }
            }
        }
    }
}

#ifdef __MMI_CAMERA_AF_TEST__


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_af_test
 * DESCRIPTION
 *  press AF button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_af_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.setting.cont_shot = CAMERA_SETTING_CONT_SHOT_1;
    g_camera_cntx.cont_shot_total_count = 50;
    g_camera_cntx.cont_shot_count = 0;
    g_camera_cntx.is_af_test = TRUE;

    mmi_camera_af_test_start();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_af_test_start
 * DESCRIPTION
 *  press AF button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_af_test_start()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_autofocus_pressed = TRUE;
    g_camera_cntx.af_state = AF_CALCULATE;
    g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;

    /* send command to driver to start cal focus */
    mdi_camera_start_autofocus_process((mdi_callback) mmi_camera_autofocus_callback);

    /* draw animation for focus process */
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    mmi_camera_capture_button_press();
}
#endif /* __MMI_CAMERA_AF_TEST__ */ 

#if defined(__AF_SUPPORT_ONE_KEY__) || defined(__MMI_CAMERA_AF_TEST__)
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_af_and_capture
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_af_and_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_capture_button_autofocus_pressed();
    mmi_camera_capture_button_press();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture_button_autofocus_pressed
 * DESCRIPTION
 *  press AF button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_capture_button_autofocus_pressed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    if (g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
    {
        return;
    }
#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

    if (mdi_camera_is_ready_to_capture() == TRUE && g_camera_cntx.af_state != AF_CALCULATE)
    {
        g_camera_cntx.is_autofocus_pressed = TRUE;
        g_camera_cntx.af_state = AF_CALCULATE;
        g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;

        /* send command to driver to start cal focus */
        mdi_camera_start_autofocus_process((mdi_callback) mmi_camera_autofocus_callback);

        /* clear key handler */
        ClearInputEventHandler(MMI_DEVICE_KEY);

        SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

    #ifdef __CAMERA_AUTOFOCUS__
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_DOWN);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_UP);

        SetKeyHandler(mmi_camera_dummy_func, KEY_9, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, KEY_9, KEY_EVENT_UP);
    #endif /* __CAMERA_AUTOFOCUS__ */ 

        /* register capture and control keys */
        if (CAMERA_CAPTURE_KEY != -1)
        {
            SetKeyHandler(mmi_camera_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_capture_button_release, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
        }

        if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
        {
            SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_UP);
        }

        if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
        {
            SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
            SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_UP);
        }


        /* draw animation for focus process */
        g_camera_cntx.is_draw_timer_on = TRUE;
        gui_start_timer(100, mmi_camera_preview_draw_osd_timer);

        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture_button_autofocus_released
 * DESCRIPTION
 *  release AF button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_capture_button_autofocus_released()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    if (g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
    {
        return;
    }
#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

    if (g_camera_cntx.is_af_capture == FALSE)
    {
        g_camera_cntx.is_autofocus_pressed = FALSE;
        mdi_camera_stop_autofocus_process();

        g_camera_cntx.af_state = AF_CANCEL;

        /* register key */
        mmi_camera_preview_set_key_hdlr();

        /* send cancel command to driver to stop cal focus */
        gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
        g_camera_cntx.is_draw_timer_on = FALSE;

        /* draw animation for stopping focus process */
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_draw_bolder_rect
 * DESCRIPTION
 *  draw rect with bolder
 * PARAMETERS
 *  x1                  [IN]        Start x
 *  y1                  [IN]        Start y
 *  x2                  [IN]        End x
 *  y2                  [IN]        End y
 *  bolder_width        [IN]        Width of bolder
 *  frame_color         [IN]        
 *  gdi_color(?)        [IN]        Color of bolder
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    S32 offset_x = 0;
    S32 offset_y = 0;
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_y;
    }
    x1 -= offset_x;
    x2 -= offset_x;
    y1 -= offset_y;
    y2 -= offset_y;
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;
    }
    x1 -= offset_x;
    x2 -= offset_x;
    y1 -= offset_y;
    y2 -= offset_y;

#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    gdi_draw_rect(x1 - bolder_width, y1 - bolder_width, x2 + bolder_width, y2 + bolder_width, frame_color);
    gdi_draw_rect(x1 + bolder_width, y1 + bolder_width, x2 - bolder_width, y2 - bolder_width, frame_color);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_draw_autofocus_process
 * DESCRIPTION
 *  draw AF related OSD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_draw_autofocus_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 image_id = 0; */
    U16 af_x = 0;
    U16 af_y = 0;
    U16 af_width = 0;
    gdi_color af_color = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);
    }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 

#if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__) 
    if (g_camera_cntx.is_tileshot)
    {
        S32 offset_x = 0, offset_y = 0;
    
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
            offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_HEIGHT >> 1) + (LCD_HEIGHT >> 2);
            offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_WIDTH >> 1) + (LCD_WIDTH >> 2);
        }
        else if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
        {
            offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_WIDTH >> 1) + (LCD_WIDTH >> 2);
            offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_HEIGHT >> 1) + (LCD_HEIGHT >> 2);
        }
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_WIDTH >> 1) + (LCD_WIDTH >> 2);
        offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_HEIGHT >> 1) + (LCD_HEIGHT >> 2);
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

        switch (g_camera_cntx.af_state)
        {
            case AF_CALCULATE:

                if (g_camera_cntx.is_manual_autofocus == FALSE)
                {
                    if (g_camera_cntx.af_animation_process == AF_ANIMATION_END)
                    {
                        g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;
                    }

                    switch (g_camera_cntx.setting.af_meter)
                    {
                        /* only support 1 zone */
                        case CAMERA_SETTING_AUTOFOCUS_1_ZONE:
                        {
                            switch (g_camera_cntx.af_animation_process)
                            {
                                case AF_ANIMATION_STEP1:
                                    af_width = CAMERA_AF_LARGE_WIDTH;
                                    af_color = GDI_COLOR_WHITE;
                                    break;
                                case AF_ANIMATION_STEP2:
                                    af_color = GDI_COLOR_GRAY;
                                    af_width = CAMERA_AF_NORMAL_WIDTH;
                                    break;
                                case AF_ANIMATION_STEP3:
                                    af_color = GDI_COLOR_BLACK;
                                    af_width = CAMERA_AF_SMALL_WIDTH;
                                    break;
                            }
                            af_x = offset_x - af_width / 2;
                            af_y = offset_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_WHITE);
                        }
                            break;
                        default:
                            break;
                    }
                    g_camera_cntx.af_animation_process++;
                }
                break;
            case AF_SUCCEED:
                switch (g_camera_cntx.setting.af_meter)
                {
                    case CAMERA_SETTING_AUTOFOCUS_1_ZONE:
                    {
                        af_width = CAMERA_AF_SMALL_WIDTH;

                        af_x = offset_x - af_width / 2;
                        af_y = offset_y - af_width / 2;
                        mmi_camera_draw_bolder_rect(
                            af_x,
                            af_y,
                            af_x + af_width - 1,
                            af_y + af_width - 1,
                            1,
                            GDI_COLOR_GREEN);
                    }
                        break;
                    default:
                        ASSERT(0);
                        break;
                }

                break;
            case AF_FAIL:
                af_width = CAMERA_AF_SMALL_WIDTH;

                af_x = offset_x - af_width / 2;
                af_y = offset_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, GDI_COLOR_RED);

                break;
            case AF_CANCEL:
                break;

        }

    }
    else
#endif
    {
        switch (g_camera_cntx.af_state)
        {
            case AF_CALCULATE:

                if (g_camera_cntx.is_manual_autofocus == FALSE)
                {
                    if (g_camera_cntx.af_animation_process == AF_ANIMATION_END)
                    {
                        g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;
                    }

                    switch (g_camera_cntx.setting.af_meter)
                    {
                    #ifdef __CAMERA_AUTOFOCUS_5_ZONE__
                        case CAMERA_SETTING_AUTOFOCUS_5_ZONE:
                            switch (g_camera_cntx.af_animation_process)
                            {
                                case AF_ANIMATION_STEP1:
                                    af_color = GDI_COLOR_WHITE;
                                    break;
                                case AF_ANIMATION_STEP2:
                                    af_color = GDI_COLOR_GRAY;
                                    break;
                                case AF_ANIMATION_STEP3:
                                    af_color = GDI_COLOR_BLACK;
                                    break;
                            }

                            af_width = CAMERA_AF_SMALL_WIDTH;
                            af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            af_x = g_camera_cntx.af_zone1_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone1_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            af_x = g_camera_cntx.af_zone2_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone2_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            af_x = g_camera_cntx.af_zone3_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone3_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            af_x = g_camera_cntx.af_zone4_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone4_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            break;
                    #endif /* __CAMERA_AUTOFOCUS_5_ZONE__ */ 
                        #ifdef __CAMERA_AUTOFOCUS_3_ZONE__
                        case CAMERA_SETTING_AUTOFOCUS_3_ZONE:
                            switch (g_camera_cntx.af_animation_process)
                            {
                                case AF_ANIMATION_STEP1:
                                    af_color = GDI_COLOR_WHITE;
                                    break;
                                case AF_ANIMATION_STEP2:
                                    af_color = GDI_COLOR_GRAY;
                                    break;
                                case AF_ANIMATION_STEP3:
                                    af_color = GDI_COLOR_BLACK;
                                    break;
                            }

                            af_width = CAMERA_AF_SMALL_WIDTH;
                            af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            af_x = g_camera_cntx.af_zone1_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone1_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            af_x = g_camera_cntx.af_zone2_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone2_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                            break;
                        #endif /* __CAMERA_AUTOFOCUS_3_ZONE__ */ 
                        #ifdef __CAMERA_AUTOFOCUS_1_ZONE__
                        case CAMERA_SETTING_AUTOFOCUS_1_ZONE:
                        {
                            switch (g_camera_cntx.af_animation_process)
                            {
                                case AF_ANIMATION_STEP1:
                                    af_width = CAMERA_AF_LARGE_WIDTH;
                                    af_color = GDI_COLOR_WHITE;
                                    break;
                                case AF_ANIMATION_STEP2:
                                    af_color = GDI_COLOR_GRAY;
                                    af_width = CAMERA_AF_NORMAL_WIDTH;
                                    break;
                                case AF_ANIMATION_STEP3:
                                    af_color = GDI_COLOR_BLACK;
                                    af_width = CAMERA_AF_SMALL_WIDTH;
                                    break;
                            }

                            af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_WHITE);
                        }
                            break;
                        #endif /* __CAMERA_AUTOFOCUS_1_ZONE__ */ 
                        default:
                            break;
                    }
                    g_camera_cntx.af_animation_process++;
                }
                else
                {

                }

                break;
            case AF_SUCCEED:
                switch (g_camera_cntx.setting.af_meter)
                {
                #ifdef __CAMERA_AUTOFOCUS_5_ZONE__
                    case CAMERA_SETTING_AUTOFOCUS_5_ZONE:
                        af_width = CAMERA_AF_SMALL_WIDTH;
                        if (g_camera_cntx.af_result & 0x01)
                        {
                            af_x = g_camera_cntx.af_zone0_x;
                            af_y = g_camera_cntx.af_zone0_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        if (g_camera_cntx.af_result & 0x02)
                        {
                            af_x = g_camera_cntx.af_zone1_x;
                            af_y = g_camera_cntx.af_zone1_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        if (g_camera_cntx.af_result & 0x04)
                        {
                            af_x = g_camera_cntx.af_zone2_x;
                            af_y = g_camera_cntx.af_zone2_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        if (g_camera_cntx.af_result & 0x08)
                        {
                            af_x = g_camera_cntx.af_zone3_x;
                            af_y = g_camera_cntx.af_zone3_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        if (g_camera_cntx.af_result & 0x10)
                        {
                            af_x = g_camera_cntx.af_zone4_x;
                            af_y = g_camera_cntx.af_zone4_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        break;
                #endif /* __CAMERA_AUTOFOCUS_5_ZONE__ */ 
                    #ifdef __CAMERA_AUTOFOCUS_3_ZONE__
                    case CAMERA_SETTING_AUTOFOCUS_3_ZONE:
                        af_width = CAMERA_AF_SMALL_WIDTH;

                        if (g_camera_cntx.af_result & 0x01)
                        {
                            af_x = g_camera_cntx.af_zone0_x;
                            af_y = g_camera_cntx.af_zone0_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        if (g_camera_cntx.af_result & 0x02)
                        {
                            af_x = g_camera_cntx.af_zone1_x;
                            af_y = g_camera_cntx.af_zone1_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        if (g_camera_cntx.af_result & 0x04)
                        {
                            af_x = g_camera_cntx.af_zone2_x;
                            af_y = g_camera_cntx.af_zone2_y;
                            af_x -= af_width / 2;
                            af_y -= af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_GREEN);
                        }
                        break;
                    #endif /* __CAMERA_AUTOFOCUS_3_ZONE__ */ 
                    #ifdef __CAMERA_AUTOFOCUS_1_ZONE__
                    case CAMERA_SETTING_AUTOFOCUS_1_ZONE:
                    {
                        af_width = CAMERA_AF_SMALL_WIDTH;

                        af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                        af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                        mmi_camera_draw_bolder_rect(
                            af_x,
                            af_y,
                            af_x + af_width - 1,
                            af_y + af_width - 1,
                            1,
                            GDI_COLOR_GREEN);
                    }
                        break;
                    #endif /* __CAMERA_AUTOFOCUS_1_ZONE__ */ 
                    default:
                        ASSERT(0);
                        break;
                }

                break;
            case AF_FAIL:
                af_width = CAMERA_AF_SMALL_WIDTH;

                af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, GDI_COLOR_RED);

                break;
            case AF_CANCEL:
                break;

        }
     }
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_pop_and_restore_active();
    }  
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}

#endif /* __CAMERA_AUTOFOCUS__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_create_preview_resource
 * DESCRIPTION
 *  free main lcd's preview layer resource
 * PARAMETERS
 *  offset_x        [IN]        Preview layer offset x
 *  offset_y        [IN]        Preview layer offset y
 *  width           [IN]        Preview layer width
 *  height          [IN]        Preview_layer height
 *  rotate          [IN]        Lcm rotate
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_preview_create_preview_resource(S32 offset_x, S32 offset_y, S32 width, S32 height, U8 rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 buf_ptr;
    S32 buf_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(width * height <= LCD_WIDTH * LCD_HEIGHT);

    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);

    /* if < MT 6227 **************************************************************** */
    /*  calculate the right buf_ptr position.                                       */
   /********************************************************************************/
    if (offset_x != 0 || offset_y != 0)
    {
    #ifdef HORIZONTAL_CAMERA
        buf_ptr += ((offset_y * LCD_HEIGHT * GDI_LAYER.bits_per_pixel) >> 3);
    #else 
        buf_ptr += ((offset_y * LCD_WIDTH * GDI_LAYER.bits_per_pixel) >> 3);
    #endif 
        buf_ptr += ((offset_x * GDI_LAYER.bits_per_pixel) >> 3);
    }
    buf_size = ((width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
    gdi_layer_create_using_outside_memory(
        0,
        0,
        width,
        height,
        &g_camera_cntx.preview_layer_handle,
        (PU8) buf_ptr,
        buf_size);

    gdi_layer_set_active(g_camera_cntx.preview_layer_handle);
#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif 
    gdi_layer_set_position(offset_x, offset_y);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_free_preview_resource
 * DESCRIPTION
 *  free main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_preview_free_preview_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.preview_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        return;
    }
    gdi_layer_free(g_camera_cntx.preview_layer_handle);
    g_camera_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
}


#ifdef __CAMERA_FEATURE_ADD_FRAME__
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_create_add_frame_layer
 * DESCRIPTION
 *  create add frame layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_create_add_frame_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( g_camera_cntx.add_frame_layer_handle == GDI_LAYER_EMPTY_HANDLE
        &&((g_camera_cntx.is_fullscreen) && (g_camera_cntx.setting.add_frame != CAMERA_SETTING_ADD_FRAME_OFF) 
          ||(g_camera_cntx.setting.add_frame_tileshot != CAMERA_SETTING_ADD_FRAME_OFF)))
    {

        gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_camera_cntx.add_frame_layer_handle);
        gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    if ( g_camera_cntx.add_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE )
    {
        /* update frame */
        mmi_camera_draw_add_frame();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_free_add_frame_layer
 * DESCRIPTION
 *  create add frame layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_free_add_frame_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.add_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.add_frame_layer_handle);
        g_camera_cntx.add_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_create_resource
 * DESCRIPTION
 *  create main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_camera_cntx.is_mainlcd_resource == FALSE);
    /* if main lcd resoruce is not created */

   /************ base layer ************/
    /* get both MainLCD and SubLCD base handle */
    gdi_layer_get_base_handle(&g_camera_cntx.base_layer_handle);

    /* clear fullscreen */
    gdi_layer_clear(GDI_COLOR_BLACK);
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
#endif 

#if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__)
   /************ tile shot ************/
    /* create tile result buffer */
    g_camera_cntx.tileshot_result_buf_ptr = mmi_frm_scrmem_alloc(CAMERA_TILE_RESULT_BUFFER_SIZE);
    ASSERT(g_camera_cntx.tileshot_result_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_camera_cntx.tileshot_result_layer_handle,
        (PU8) g_camera_cntx.tileshot_result_buf_ptr,
        (S32) CAMERA_TILE_RESULT_BUFFER_SIZE);

    gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_TILE__) */ 

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    /* make sublcd active and get it's base layer handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_camera_cntx.sublcd_base_layer_handle);

    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

   /************ frame layer ************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_create_add_frame_layer();
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
   /************ overlay frame ************/
    /* create overlay frame buffer */
    g_camera_cntx.overlay_frame_buf_ptr_ori = g_camera_cntx.overlay_frame_buf_ptr = mmi_frm_scrmem_alloc(CAMERA_OVERLAY_FRAME_BUFFER_SIZE);
    ASSERT(g_camera_cntx.overlay_frame_buf_ptr != NULL);

    /* avoid hw issue :It is a hardware issue. 
       When the overlay frame buffer address is 16bytes alignment and the enlarge times is 2.
       It will cause the result. Please Vincent help to avoid such case. */
    if ((((kal_uint32) g_camera_cntx.overlay_frame_buf_ptr) & 0x0f) == 0)
    {
        g_camera_cntx.overlay_frame_buf_ptr += 4;
    }
    /* end of avoid hw issue */

    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_camera_cntx.overlay_frame_layer_handle,
        (PU8) g_camera_cntx.overlay_frame_buf_ptr,
        (S32) (CAMERA_OVERLAY_FRAME_BUFFER_SIZE) - 4);
    gdi_layer_push_and_set_active(g_camera_cntx.overlay_frame_layer_handle);

    /* gdi_layer_get_buffer_ptr(&(g_camera_cntx.overlay_frame_buf_ptr)); */

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /* update frame */
    if ((g_camera_cntx.setting.add_frame_color_idx != CAMERA_SETTING_ADD_FRAME_OFF)
        && (g_camera_cntx.is_fullscreen == FALSE) && (g_camera_cntx.is_tileshot == FALSE))
    {
        mmi_camera_draw_add_frame_color_idx();
    }

#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

   /************ osd layer ************/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    mmi_camera_create_osd_layer();
    g_camera_cntx.is_mainlcd_resource = TRUE;
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    /* create a double layer frame from outside memory */
    g_camera_cntx.osd_layer_buf_ptr0 = mmi_frm_scrmem_alloc(CAMERA_OSD_BUFFER_SIZE);
    ASSERT(g_camera_cntx.osd_layer_buf_ptr0 != NULL);

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_camera_cntx.osd_layer_handle0,
        (PU8) g_camera_cntx.osd_layer_buf_ptr0,
        (S32) (CAMERA_OSD_BUFFER_SIZE));

    gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    g_camera_cntx.is_mainlcd_resource = TRUE;

#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}


#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_create_osd_layer
 * DESCRIPTION
 *  create main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_create_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_size, width, height, offset_x, offset_y;
    camera_osd_layeout_struct *active_camera_osd_ptr;

#if defined(__CAMERA_OSD_HORIZONTAL__)
    camera_osd_layeout_struct *active_camera_osd_ptr_270;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__CAMERA_OSD_HORIZONTAL__)
#define CREATE_OSD_LAYER(__a__, __A__,__L__)                                                 \
   do {                                                                                         \
      if(active_camera_osd_ptr->##__a__##.width*active_camera_osd_ptr->##__a__##.height >       \
         active_camera_osd_ptr_270->##__a__##.width*active_camera_osd_ptr_270->##__a__##.height)\
      {                                                                                         \
         width = active_camera_osd_ptr->##__a__##.width;                                        \
         height = active_camera_osd_ptr->##__a__##.height;                                      \
         offset_x = active_camera_osd_ptr->##__a__##.offset_x;                                  \
         offset_y = active_camera_osd_ptr->##__a__##.offset_y;                                  \
      }                                                                                         \
      else                                                                                      \
      {                                                                                         \
         width = active_camera_osd_ptr_270->##__a__##.width;                                    \
         height = active_camera_osd_ptr_270->##__a__##.height;                                  \
         offset_x = active_camera_osd_ptr_270->##__a__##.offset_x;                              \
         offset_y = active_camera_osd_ptr_270->##__a__##.offset_y;                              \
      }                                                                                         \
      buf_size = (((width*height*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);                             \
      g_camera_cntx.##__A__##= mmi_frm_scrmem_alloc(buf_size);                                  \
      ASSERT(g_camera_cntx.##__A__##!=NULL);                                                    \
      gdi_layer_create_double_using_outside_memory(offset_x,                                    \
                                                   offset_y,                                    \
                                                   width,                                       \
                                                   height,                                      \
                                                   &g_camera_cntx.##__L__##,                    \
                                                   (PU8)g_camera_cntx.##__A__##,                \
                                                   (S32)buf_size);                              \
      gdi_layer_push_and_set_active(g_camera_cntx.##__L__##);                                   \
      gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);                                        \
      gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);                                    \
      gdi_layer_pop_and_restore_active();                                                       \
   } while(0);
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
#define CREATE_OSD_LAYER(__a__, __A__,__L__)                                 \
   do {                                                                         \
      width = active_camera_osd_ptr->##__a__##.width;                           \
      height = active_camera_osd_ptr->##__a__##.height;                         \
      offset_x = active_camera_osd_ptr->##__a__##.offset_x;                     \
      offset_y = active_camera_osd_ptr->##__a__##.offset_y;                     \
      buf_size = (((width*height*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);             \
      g_camera_cntx.##__A__##= mmi_frm_scrmem_alloc(buf_size);                  \
      ASSERT(g_camera_cntx.##__A__##!=NULL);                                    \
      gdi_layer_create_double_using_outside_memory(offset_x,                    \
                                                   offset_y,                    \
                                                   width,                       \
                                                   height,                      \
                                                   &g_camera_cntx.##__L__##,    \
                                                   (PU8)g_camera_cntx.##__A__##,\
                                                   (S32)buf_size);              \
      gdi_layer_push_and_set_active(g_camera_cntx.##__L__##);                   \
      gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);                        \
      gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);                    \
      gdi_layer_pop_and_restore_active();                                       \
   } while(0);

#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    if (g_camera_cntx.is_single_osd_layer)
    {
        g_camera_cntx.osd_layer_buf_ptr0 = mmi_frm_scrmem_alloc(CAMERA_OSD_BUFFER_SIZE);
        ASSERT(g_camera_cntx.osd_layer_buf_ptr0 != NULL);

        gdi_layer_create_double_using_outside_memory(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.osd_layer_handle0,
            (PU8) g_camera_cntx.osd_layer_buf_ptr0,
            (S32) (CAMERA_OSD_BUFFER_SIZE));

        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        active_camera_osd_ptr = &g_camera_osd_cntx;
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        active_camera_osd_ptr_270 = &g_camera_osd_cntx_270;
    #endif 
        /* layer 0 */
        CREATE_OSD_LAYER(osd_region0, osd_layer_buf_ptr0, osd_layer_handle0);
        /* layer 1 */
        CREATE_OSD_LAYER(osd_region1, osd_layer_buf_ptr1, osd_layer_handle1);
        /* layer 2 */
        CREATE_OSD_LAYER(osd_region2, osd_layer_buf_ptr2, osd_layer_handle2);

#ifdef __MMI_CAMERA_5_OSD_LAYER__
        /* layer 3 */
        CREATE_OSD_LAYER(osd_region3, osd_layer_buf_ptr3, osd_layer_handle3);
        /* layer 4 */
        CREATE_OSD_LAYER(osd_region4, osd_layer_buf_ptr4, osd_layer_handle4);
#endif        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_free_osd_layer
 * DESCRIPTION
 *  free main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_free_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle0 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle0);
        g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr0);
        g_camera_cntx.osd_layer_buf_ptr0 = NULL;
    }

   /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle1 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle1);
        g_camera_cntx.osd_layer_handle1 = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr1);
        g_camera_cntx.osd_layer_buf_ptr1 = NULL;
    }
   /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle2 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle2);
        g_camera_cntx.osd_layer_handle2 = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr2);
        g_camera_cntx.osd_layer_buf_ptr2 = NULL;
    }
#ifdef __MMI_CAMERA_5_OSD_LAYER__    
   /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle3 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle3);
        g_camera_cntx.osd_layer_handle3 = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr3);
        g_camera_cntx.osd_layer_buf_ptr3 = NULL;
    }
   /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle4 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle4);
        g_camera_cntx.osd_layer_handle4 = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr4);
        g_camera_cntx.osd_layer_buf_ptr4 = NULL;
    }
#endif    
}
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_free_resource
 * DESCRIPTION
 *  free main lcd's preview layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#endif 

   /****** free add frame layer ******/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    mmi_camera_free_osd_layer();
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
   /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle0 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle0);
        g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr0);
        g_camera_cntx.osd_layer_buf_ptr0 = NULL;
    }
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

#if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__)
      /************ free tile shot ************/
    /* free tile shot result layer */
    if (g_camera_cntx.tileshot_result_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.tileshot_result_layer_handle);
        g_camera_cntx.tileshot_result_layer_handle = GDI_LAYER_EMPTY_HANDLE;

        mmi_frm_scrmem_free((void*)g_camera_cntx.tileshot_result_buf_ptr);
        g_camera_cntx.tileshot_result_buf_ptr = NULL;
    }
    #endif /* defined(__CAMERA_FEATURE_CONT_SHOT_TILE__) */ 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
      /************ free tile shot ************/
    /* free tile shot result layer */
    if (g_camera_cntx.overlay_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.overlay_frame_layer_handle);
        g_camera_cntx.overlay_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;        

        mmi_frm_scrmem_free((void*)g_camera_cntx.overlay_frame_buf_ptr_ori);
        g_camera_cntx.overlay_frame_buf_ptr = NULL;
        g_camera_cntx.overlay_frame_buf_ptr_ori = NULL;
    }

#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    /* restore only base layer active */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);

    g_camera_cntx.is_mainlcd_resource = FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_init_tileshot_layer
 * DESCRIPTION
 *  update display rotate (0 | 90 | 180 | 270 )
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_init_tileshot_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate tileshot result layer */
    gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);

#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_90 || g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    }
    else
    {
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);

    }
    gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_start
 * DESCRIPTION
 *  start previewing of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    GDI_HANDLE preview_layer_handle = 0;
    U32 preview_layer_flag = 0;
    U32 blt_layer_flag = 0;
    S32 preview_wnd_offset_x = 0;
    S32 preview_wnd_offset_y = 0;
    U16 preview_wnd_width = 0;
    U16 preview_wnd_height = 0;

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    S32 offset_x = 0;
    S32 offset_y = 0;
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* preview parametes */
    camera_setting_data.zoom = mmi_camera_preview_get_zoom_factor();
    camera_setting_data.wb = camera_wb_command_map[g_camera_cntx.setting.wb];
    camera_setting_data.manual_wb = FALSE;
    camera_setting_data.ev = camera_ev_command_map[g_camera_cntx.setting.ev];
    camera_setting_data.banding = camera_banding_command_map[g_camera_cntx.setting.banding];
    camera_setting_data.flash = camera_flash_command_map[g_camera_cntx.setting.flash];
    camera_setting_data.osd_rotate = g_camera_cntx.osd_rotate;
    camera_setting_data.night = g_camera_cntx.setting.night;

    camera_setting_data.iso = camera_iso_command_map[g_camera_cntx.setting.iso];
    camera_setting_data.ae_meter = camera_ae_meter_command_map[g_camera_cntx.setting.ae_meter];
    camera_setting_data.dsc_mode = camera_dsc_mode_command_map[g_camera_cntx.setting.dsc_mode];
    camera_setting_data.af_mode = camera_autofocus_mode_command_map[g_camera_cntx.setting.af_mode];
    camera_setting_data.af_metering_mode = camera_autofocus_command_map[g_camera_cntx.setting.af_meter];
#if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__)
    camera_setting_data.shutter_pri = g_camera_dsc_mode_cntx.shutter_pri_value[g_camera_cntx.setting.shutter_pri];
#else 
    camera_setting_data.shutter_pri = 0;
#endif 

#if defined(__CAMERA_DSC_MODE_APERTURE_PRI__)
    camera_setting_data.aperture_pri = g_camera_dsc_mode_cntx.aperture_pri_value[g_camera_cntx.setting.aperture_pri];
#else 
    camera_setting_data.aperture_pri = 0;
#endif 

    /* default effect */
    camera_setting_data.effect = camera_effect_command_map[g_camera_cntx.setting.effect];
    camera_setting_data.brightness = 128;
    camera_setting_data.saturation = 128;
    camera_setting_data.contrast = 128;
    camera_setting_data.hue = 0;

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_1)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[0];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[0];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[0];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[0];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ */ 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_2)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[1];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[1];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[1];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[1];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ */ 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_3)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[2];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[2];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[2];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[2];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ */ 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    if ((g_camera_cntx.setting.add_frame_color_idx != CAMERA_SETTING_ADD_FRAME_OFF)
        && (g_camera_cntx.is_tileshot == FALSE) && (g_camera_cntx.is_fullscreen == FALSE))
    {
        camera_setting_data.overlay_frame_mode = TRUE;
        camera_setting_data.overlay_frame_depth = OVERLAY_8BPP_PHOTO_FRAME;     /* although we support 1/2/4/8, but we use 8 only b/c gdi layer support */
        camera_setting_data.overlay_frame_width = g_camera_cntx.overlay_frame_width;
        camera_setting_data.overlay_frame_height = g_camera_cntx.overlay_frame_height;
        camera_setting_data.overlay_frame_source_key = (U8) g_camera_cntx.overlay_frame_source_key;
        camera_setting_data.overlay_frame_buffer_address = (kal_uint32) g_camera_cntx.overlay_frame_buf_ptr;
    }
    else
    {
        camera_setting_data.overlay_frame_mode = FALSE;
        camera_setting_data.overlay_frame_depth = 0;
        camera_setting_data.overlay_frame_width = 0;
        camera_setting_data.overlay_frame_height = 0;
        camera_setting_data.overlay_frame_source_key = 0;
        camera_setting_data.overlay_frame_buffer_address = 0;
    }
#else /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    camera_setting_data.overlay_frame_mode = FALSE;
    camera_setting_data.overlay_frame_depth = 0;
    camera_setting_data.overlay_frame_width = 0;
    camera_setting_data.overlay_frame_height = 0;
    camera_setting_data.overlay_frame_source_key = 0;
    camera_setting_data.overlay_frame_buffer_address = 0;
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    camera_setting_data.preview_width = g_camera_cntx.preview_width;
    camera_setting_data.preview_height = g_camera_cntx.preview_height;

    /* capture parameters */
    camera_setting_data.image_qty = camera_image_qty_command_map[g_camera_cntx.setting.image_qty];
    camera_setting_data.image_width = g_camera_cntx.image_width;
    camera_setting_data.image_height = g_camera_cntx.image_height;

    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.preview_rotate = CAMERA_PREVIEW_MAINLCD_ROTATE;
    camera_setting_data.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;

    camera_setting_data.continue_capture = g_camera_cntx.is_continue_capture;

    /* AF */
    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();

    /* 
     * if using MT6218B series moudle with a Master backend (AIT700, etc),
     * we have to clear the preview layer's background to transparent,
     * and we have to resoret it after preview stop (stopped by capture command)
     */

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 

    if (g_camera_cntx.is_tileshot)
    {
    #ifndef __CAMERA_FEATURE_CONT_SHOT_TILE__
        MMI_ASSERT(0);
    #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 


        preview_layer_handle = g_camera_cntx.preview_layer_handle;

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
            offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_HEIGHT >> 1);
            offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_WIDTH >> 1);
        }
        else if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
        {
            switch (g_camera_cntx.tile_cur_num)
            {
                case 0:
                    offset_x = 0;
                    offset_y = LCD_WIDTH >> 1;;
                    break;
                case 1:
                    offset_x = 0;
                    offset_y = 0;
                    break;
                case 2:
                    offset_x = LCD_HEIGHT >> 1;
                    offset_y = LCD_WIDTH >> 1;
                    break;
                case 3:
                    offset_x = LCD_HEIGHT >> 1;
                    offset_y = 0;
                    break;
                default:
                    break;
            }
        }
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_WIDTH >> 1);
        offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_HEIGHT >> 1);
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 


    #ifdef __CAMERA_AUTOFOCUS__
        camera_setting_data.af_metering_mode = MDI_CAMERA_AUTOFOCUS_1_ZONE;
        camera_setting_data.af_mode = MDI_CAMERA_AUTOFOCUS_MODE_AUTO;
        camera_setting_data.af_zone0_x = offset_x + g_camera_cntx.preview_width / 2;
        camera_setting_data.af_zone0_y = offset_y + g_camera_cntx.preview_height / 2;
        camera_setting_data.af_zone1_x = 0;
        camera_setting_data.af_zone1_y = 0;
        camera_setting_data.af_zone2_x = 0;
        camera_setting_data.af_zone2_y = 0;
        camera_setting_data.af_zone3_x = 0;
        camera_setting_data.af_zone3_y = 0;
        camera_setting_data.af_zone4_x = 0;
        camera_setting_data.af_zone4_y = 0;

        g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x;
        g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x;
        g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x;
        g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x;
        g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x;

        g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y;
        g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y;
        g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y;
        g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y;
        g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y;
    #endif /* __CAMERA_AUTOFOCUS__ */ 

        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_set_position(offset_x, offset_y);
        gdi_layer_pop_and_restore_active();

        mmi_camera_preview_set_blt_layer(TRUE);

        /* tile shot, will draw on full tile preview layer, start from 0, 0 */
        preview_wnd_offset_x = 0;
        preview_wnd_offset_y = 0;
        preview_wnd_width = g_camera_cntx.preview_width;
        preview_wnd_height = g_camera_cntx.preview_height;

        /* tile result, preview, frame, OSD */
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
    }
    else
    {
    #ifdef __CAMERA_AUTOFOCUS__
    #ifdef HORIZONTAL_CAMERA
        {
            S32 tmp;

            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                camera_setting_data.af_zone0_x = CAMERA_AF_POSITION_1_X;
                camera_setting_data.af_zone0_y = CAMERA_AF_POSITION_1_Y;
                camera_setting_data.af_zone1_x = CAMERA_AF_POSITION_4_X;
                camera_setting_data.af_zone1_y = CAMERA_AF_POSITION_4_Y;
                camera_setting_data.af_zone2_x = CAMERA_AF_POSITION_5_X;
                camera_setting_data.af_zone2_y = CAMERA_AF_POSITION_5_Y;
                camera_setting_data.af_zone3_x = CAMERA_AF_POSITION_3_X;
                camera_setting_data.af_zone3_y = CAMERA_AF_POSITION_3_Y;
                camera_setting_data.af_zone4_x = CAMERA_AF_POSITION_2_X;
                camera_setting_data.af_zone4_y = CAMERA_AF_POSITION_2_Y;

                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x, camera_setting_data.af_zone0_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x, camera_setting_data.af_zone1_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x, camera_setting_data.af_zone2_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x, camera_setting_data.af_zone3_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x, camera_setting_data.af_zone4_y, tmp);

                g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x;
                g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x;
                g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x;
                g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x;
                g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x;

                g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y;
                g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y;
                g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y;
                g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y;
                g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y;
            }
            else
            {
                g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x = CAMERA_AF_POSITION_1_X;
                g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y = CAMERA_AF_POSITION_1_Y;
                g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x = CAMERA_AF_POSITION_2_X;
                g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y = CAMERA_AF_POSITION_2_Y;
                g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x = CAMERA_AF_POSITION_3_X;
                g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y = CAMERA_AF_POSITION_3_Y;
                g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x = CAMERA_AF_POSITION_4_X;
                g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y = CAMERA_AF_POSITION_4_Y;
                g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x = CAMERA_AF_POSITION_5_X;
                g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y = CAMERA_AF_POSITION_5_Y;

                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x, camera_setting_data.af_zone0_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x, camera_setting_data.af_zone1_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x, camera_setting_data.af_zone2_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x, camera_setting_data.af_zone3_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x, camera_setting_data.af_zone4_y, tmp);
            }
        }
    #else /* HORIZONTAL_CAMERA */ 
        g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x = CAMERA_AF_POSITION_1_X;
        g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y = CAMERA_AF_POSITION_1_Y;
        g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x = CAMERA_AF_POSITION_2_X;
        g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y = CAMERA_AF_POSITION_2_Y;
        g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x = CAMERA_AF_POSITION_3_X;
        g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y = CAMERA_AF_POSITION_3_Y;
        g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x = CAMERA_AF_POSITION_4_X;
        g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y = CAMERA_AF_POSITION_4_Y;
        g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x = CAMERA_AF_POSITION_5_X;
        g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y = CAMERA_AF_POSITION_5_Y;

    #endif /* HORIZONTAL_CAMERA */ 
    #endif /* __CAMERA_AUTOFOCUS__ */ 

        preview_layer_handle = g_camera_cntx.preview_layer_handle;

        /* use preview wnd's position */
        preview_wnd_offset_x = g_camera_cntx.active_camera_osd_ptr->preview_wnd.offset_x;
        preview_wnd_offset_y = g_camera_cntx.active_camera_osd_ptr->preview_wnd.offset_y;
        preview_wnd_width = g_camera_cntx.preview_width;
        preview_wnd_height = g_camera_cntx.preview_height;

        /* preview (hw), OSD */
    #if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
        #if defined(__MMI_CAMERA_5_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                blt_layer_flag =
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 |
                    GDI_LAYER_ENABLE_LAYER_3 | GDI_LAYER_ENABLE_LAYER_4 | GDI_LAYER_ENABLE_LAYER_5;
            }
            else
            {
                blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
            }
        #elif defined(__MMI_CAMERA_3_OSD_LAYER__) 
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                blt_layer_flag =
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 |
                    GDI_LAYER_ENABLE_LAYER_3 ;
            }
            else
            {
                blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
            }

        #else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
        #endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    #else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)*/ 
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
    #endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
    }

#ifdef __CAMERA_FEATURE_XENON_FLASH__
    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
#endif

    /* preview data for preview start */
    camera_preview_data.preview_layer_handle = preview_layer_handle;
    camera_preview_data.preview_wnd_offset_x = preview_wnd_offset_x;
    camera_preview_data.preview_wnd_offset_y = preview_wnd_offset_y;
    camera_preview_data.preview_wnd_width = preview_wnd_width;
    camera_preview_data.preview_wnd_height = preview_wnd_height;
    camera_preview_data.blt_layer_flag = blt_layer_flag;
    camera_preview_data.preview_layer_flag = preview_layer_flag;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
    camera_preview_data.is_tvout = TRUE;
    #ifdef __CAMERA_FEATURE_XENON_FLASH__
    camera_preview_data.xenon_flash_status_callback = mmi_camera_xenon_flash_callback;
    #else
    camera_preview_data.xenon_flash_status_callback = NULL;
    #endif
    g_camera_cntx.last_error
        = mdi_camera_preview_start(
            &camera_preview_data,
            &camera_setting_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_stop
 * DESCRIPTION
 *  stop previewing of main lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previewing */
    mdi_camera_preview_stop();

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    mmi_camera_preview_clear_background();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_set_blt_layer
 * DESCRIPTION
 *  set blt layer based on current status (ex: is previwing, has add frame, etc )
 * PARAMETERS
 *  is_previewing       [IN]        Is preview flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_set_blt_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_previewing)
    {
        if (g_camera_cntx.is_tileshot)
        {
        #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
            /* (1) previewing (2) tile shot */
            gdi_layer_set_blt_layer(
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
        #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
            MMI_ASSERT(0);
        #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
        }
        else
        {

            /* (1) previwing */
        #if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
        #if defined(__MMI_CAMERA_5_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {

                gdi_layer_set_blt_layer_ext(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle3,
                    g_camera_cntx.osd_layer_handle4,
                    g_camera_cntx.osd_layer_handle2);

            }
            else
            {

                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            }
        #elif defined(__MMI_CAMERA_3_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {

                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle2);

            }
            else
            {
                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            }
        
        #else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
            gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);

        #endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
        #else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
            gdi_layer_set_blt_layer(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
        #endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
        }

    }
    else
    {
        if (g_camera_cntx.is_tileshot)
        {
        #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
            /* (1) not previewing (2) tile shot */
            gdi_layer_set_blt_layer(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
        #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
            MMI_ASSERT(0);
        #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
        }
        else
        {
            /*  not previewing. */
        #if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
            #if defined(__MMI_CAMERA_5_OSD_LAYER__)
                if (g_camera_cntx.is_single_osd_layer == FALSE)
                {

                    gdi_layer_set_blt_layer_ext(
                        g_camera_cntx.preview_layer_handle,
                        g_camera_cntx.osd_layer_handle0,
                        g_camera_cntx.osd_layer_handle1,
                        g_camera_cntx.osd_layer_handle3,
                        g_camera_cntx.osd_layer_handle4,
                        g_camera_cntx.osd_layer_handle2);

                }
                else
                {
                    gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
                }
            #elif defined(__MMI_CAMERA_3_OSD_LAYER__)
                if (g_camera_cntx.is_single_osd_layer == FALSE)
                {

                    gdi_layer_set_blt_layer(
                        g_camera_cntx.preview_layer_handle,
                        g_camera_cntx.osd_layer_handle0,
                        g_camera_cntx.osd_layer_handle1,
                        g_camera_cntx.osd_layer_handle2);
                }
                else
                {
                    gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
                }
        
            #else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);

            #endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
        #else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);

        #endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_clear_background
 * DESCRIPTION
 *  clear backgroud of preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_clear_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    if (g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_color)
    {
        bg_color = GDI_RGB_TO_BUFFER_FORMAT(
                    g_camera_cntx.active_camera_osd_ptr->bg.r,
                    g_camera_cntx.active_camera_osd_ptr->bg.g,
                    g_camera_cntx.active_camera_osd_ptr->bg.b);

        gdi_layer_clear(bg_color);
    }

    if (g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_image_draw_id(0, 0, IMG_ID_CAMERA_PREVIEW_BACKGROUND);
    }

    if (!g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_color &&
        !g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }

    gdi_layer_pop_and_restore_active();

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* tile preview back groud */
    if (g_camera_cntx.preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_flatten_layer
 * DESCRIPTION
 *  flatten layers to base
 * PARAMETERS
 *  is_previewing       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_flatten_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_previewing)
    {
        if (g_camera_cntx.is_tileshot)
        {
        #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__       
            gdi_layer_flatten_to_base(
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0,
                0);
        #else
            ASSERT(0);
        #endif
        }
        else
        {
        #if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
            #if (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL==24)          
                gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
                gdi_layer_clear(GDI_COLOR_BLACK);
                gdi_layer_pop_and_restore_active();
            #elif defined(__MMI_CAMERA_5_OSD_LAYER__) 
                gdi_layer_flatten_to_base_ext(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, g_camera_cntx.osd_layer_handle2, g_camera_cntx.osd_layer_handle3, 0);
            #elif defined(__MMI_CAMERA_3_OSD_LAYER__) 
                gdi_layer_flatten_to_base(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, 0);
            #else
                gdi_layer_flatten_to_base(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            #endif
        #else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
            gdi_layer_flatten_to_base(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
        #endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
        }
    }
    else
    {
    #if (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL==24)          
        gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    #elif defined(__MMI_CAMERA_5_OSD_LAYER__) 
        gdi_layer_flatten_to_base_ext(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, g_camera_cntx.osd_layer_handle2, g_camera_cntx.osd_layer_handle3, 0);
    #elif defined(__MMI_CAMERA_3_OSD_LAYER__) 
        gdi_layer_flatten_to_base(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, 0);
    #else
        gdi_layer_flatten_to_base(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_hide_hint
 * DESCRIPTION
 *  hide hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_set_hint(NULL, NULL, 255);
    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_osd
 * DESCRIPTION
 *  draw preview title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_layer_set_active(g_camera_cntx.osd_layer_handle1);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_layer_set_active(g_camera_cntx.osd_layer_handle2);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    #ifdef __MMI_CAMERA_5_OSD_LAYER__
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle3);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_layer_set_active(g_camera_cntx.osd_layer_handle4);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    #endif
        gdi_layer_pop_and_restore_active();
    }
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
    gdi_layer_toggle_double();
    /* toggle double buffer */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

    /* do not draw any thing here */
    if ((g_camera_cntx.app_state != CAMERA_STATE_SAVE_CONFIRM) &&
        (g_camera_cntx.app_state != CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM) &&
        (g_camera_cntx.is_fullscreen) &&
        ((g_camera_cntx.setting.add_frame != 0) || (g_camera_cntx.setting.add_frame_tileshot != 0)) &&
        (g_camera_cntx.add_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE))
    {
        PU8 src;
        PU8 dest;
        U16 src_width, src_height, src_pitch;
        S32 src_offset_x, src_offset_y;
        S32 dest_pitch, dest_offset_x, dest_offset_y;
        gdi_rect_struct dest_clip;

        gdi_layer_get_buffer_ptr(&dest);

        gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
        gdi_layer_get_buffer_ptr(&src);

        src_pitch = g_camera_cntx.osd_UI_device_width;
        dest_pitch = g_camera_cntx.osd_UI_device_width;
        dest_clip.x1 = 0;
        dest_clip.y1 = 0;
        dest_clip.x2 = g_camera_cntx.osd_UI_device_width - 1;
        dest_clip.y2 = g_camera_cntx.osd_UI_device_height - 1;
        src_offset_x = 0;
        src_offset_y = 0;
        src_width = g_camera_cntx.osd_UI_device_width;
        src_height = g_camera_cntx.osd_UI_device_height;
        dest_offset_y = 0;
        dest_offset_x = 0;
        gdi_layer_pop_and_restore_active();

        gdi_2d_memory_blt_without_transpant_check(
            src,
            src_pitch,
            src_offset_x,
            src_offset_y,
            src_width,
            src_height,
            dest,
            dest_pitch,
            dest_offset_x,
            dest_offset_y,
            dest_clip,
            GDI_MAINLCD_BIT_PER_PIXEL);
    }

   /****** wanna draw any thing on OSD layer, please add code after this ******/
#ifdef __CAMERA_AUTOFOCUS__
    if (g_camera_cntx.is_autofocus_pressed == TRUE)
    {
        mmi_camera_draw_autofocus_process();
    }
#endif /* __CAMERA_AUTOFOCUS__ */ 

    mmi_camera_preview_draw_softkey();
    mmi_camera_preview_draw_title();

    if (g_camera_cntx.fade_time != 255)
    {
        mmi_camera_preview_draw_hint();
        g_camera_cntx.fade_time = 0;
    }

    if ((g_camera_cntx.app_state != CAMERA_STATE_SAVE_CONFIRM) &&
        (g_camera_cntx.app_state != CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM))
    {
        mmi_camera_preview_draw_icon();

        if (g_camera_cntx.app_state == CAMERA_STATE_CONTSHOT)
        {
        #ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
            mmi_camera_preview_draw_contshot_countbar();
        #endif 
        }
    }
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer)
    {
        gdi_layer_pop_and_restore_active();
    }
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)*/ 
    gdi_layer_pop_and_restore_active();
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_title
 * DESCRIPTION
 *  draw preview title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if is fullscreen display, do not draw title */
    if (g_camera_cntx.is_fullscreen)
    {
        return;
    }

    /* if not fullscreen and need title */
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar &&
        g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_caption)
    {
        gdi_layer_lock_frame_buffer();

        show_title_status_icon();
        draw_title();

        gdi_layer_unlock_frame_buffer();
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_softkey
 * DESCRIPTION
 *  draw preview softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    U16 lsk_id;
    U16 rsk_id;
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle3);
    }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    if ((g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM) ||
        (g_camera_cntx.app_state == CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM))
    {
        lsk_id = STR_GLOBAL_SAVE;
        rsk_id = STR_GLOBAL_CLEAR;
    }
    else
    {
        lsk_id = STR_GLOBAL_OPTIONS;

        /* if only have 23key, use rsk to capture */
    #ifdef __MMI_CAMERA_23KEY__
        rsk_id = STR_ID_CAMERA_RSK_CAPTURE;
    #else 
        rsk_id = STR_GLOBAL_BACK;
    #endif 

        if ((g_camera_cntx.app_state == CAMERA_STATE_PREVIEW) && (g_camera_cntx.tile_cur_num >= 1))
        {
            rsk_id = STR_GLOBAL_CLEAR;
        }
    }

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* if is fullscreen display, or normal display but without mmi_softkey */
    if ((g_camera_cntx.is_fullscreen) || (!g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey))
    {
        gui_set_font(&MMI_medium_font);

        /* lsk */
        str_ptr = (PS8) GetString(lsk_id);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
        #if defined(__CAMERA_OSD_HORIZONTAL__)
            wgui_softkey_get_offset_ex((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
        #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        }
        else
        {
            wgui_softkey_get_offset((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY);
        }

        /* check r2lMMIFlag flag to correct offset_x of string, due to we will do the change in 
         * mmi_camera_draw_style_text() */
        if (r2lMMIFlag)
        {
            lsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
        }

        if (g_camera_cntx.is_lsk_pressed)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }

        mmi_camera_draw_style_text(
            str_ptr,
            lsk_offset_x - offset_x,
            lsk_offset_y - offset_y,
            &g_camera_cntx.active_camera_osd_ptr->softkey.lsk);

        g_camera_cntx.touch_lsk.offset_x = lsk_offset_x;
        g_camera_cntx.touch_lsk.offset_y = lsk_offset_y;
        g_camera_cntx.touch_lsk.width = str_width;
        g_camera_cntx.touch_lsk.height = str_height;

        /* rsk */
        str_ptr = (PS8) GetString(rsk_id);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
        #if defined(__CAMERA_OSD_HORIZONTAL__)
            wgui_softkey_get_offset_ex((UI_string_type) str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
        #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        }
        else
        {
            wgui_softkey_get_offset((UI_string_type) str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY);
        }

        if (r2lMMIFlag)
        {
            rsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
        }

        
        if (g_camera_cntx.is_rsk_pressed)
        {
            rsk_offset_x++;
            rsk_offset_y++;
        }

        mmi_camera_draw_style_text(
            str_ptr,
            rsk_offset_x - offset_x,
            rsk_offset_y - offset_y,
            &g_camera_cntx.active_camera_osd_ptr->softkey.rsk);

        g_camera_cntx.touch_rsk.offset_x = rsk_offset_x;
        g_camera_cntx.touch_rsk.offset_y = rsk_offset_y;
        g_camera_cntx.touch_rsk.width = str_width;
        g_camera_cntx.touch_rsk.height = str_height;

    #if defined(__MMI_CAMERA_MMS_SUPPORT__)
        if (g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM && (g_camera_cntx.is_mms_ready == TRUE) &&
            mmi_bootup_get_active_flight_mode() == 0)
        {
            if (g_camera_cntx.is_mms_icon_pressed == FALSE)
            {
                gdi_image_draw_id(
                    g_camera_cntx.touch_mms_icon.offset_x - offset_x,
                    g_camera_cntx.touch_mms_icon.offset_y - offset_y,
                    IMG_ID_CAMERA_FORWARD_TO_MMS);
            }
            else
            {
                gdi_image_draw_id(
                    g_camera_cntx.touch_mms_icon.offset_x - offset_x + 1,
                    g_camera_cntx.touch_mms_icon.offset_y - offset_y + 1,
                    IMG_ID_CAMERA_FORWARD_TO_MMS);
            }
        }
    #endif /* defined(__MMI_CAMERA_MMS_SUPPORT__) */ 

    }
    else
    {
        if (g_camera_cntx.is_rsk_pressed)
        {
            set_softkey_flags_on(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN, MMI_RIGHT_SOFTKEY);
        }
        else
        {
            set_softkey_flags_off(UI_BUTTON_STATE_CLICKED, MMI_RIGHT_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_STATE_DOWN, MMI_RIGHT_SOFTKEY);
        }

        if (g_camera_cntx.is_lsk_pressed)
        {
            set_softkey_flags_on(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN, MMI_LEFT_SOFTKEY);
        }
        else
        {
            set_softkey_flags_off(UI_BUTTON_STATE_CLICKED, MMI_LEFT_SOFTKEY);
            set_softkey_flags_off(UI_BUTTON_STATE_DOWN, MMI_LEFT_SOFTKEY);
        }

        change_left_softkey(lsk_id, IMG_GLOBAL_OK);
        change_right_softkey(rsk_id, IMG_GLOBAL_BACK);

        /* draw MMI standard softkey */
        gdi_layer_lock_frame_buffer();

        show_softkey_background();

        show_left_softkey();
        show_right_softkey();

        gdi_layer_unlock_frame_buffer();

    }
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_hint
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x;
    S32 str1_offset_y;
    S32 str2_offset_x;
    S32 str2_offset_y;
    S32 spacing;
    PS8 hint_str1;
    PS8 hint_str2;

    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);
    }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)    
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    /* clear hint background region */

    /* draw hint */
    if (g_camera_cntx.active_camera_osd_ptr->hint_box.is_show)
    {
        hint_str1 = g_camera_cntx.hint1_buf;
        hint_str2 = g_camera_cntx.hint2_buf;

        /* be removed : clear hint backgounrd */

        gui_set_text_clip(
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x,
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y,
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + g_camera_cntx.active_camera_osd_ptr->hint_box.width - 1,
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y + g_camera_cntx.active_camera_osd_ptr->hint_box.height - 1);

        gui_measure_string((UI_string_type) hint_str1, &str1_width, &str1_height);
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);

        str1_offset_x = (g_camera_cntx.active_camera_osd_ptr->hint_box.width - str1_width) >> 1;

        spacing = g_camera_cntx.active_camera_osd_ptr->hint_box.height - str1_height - str2_height;
        spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

        str1_offset_y = spacing;
        str2_offset_y = str1_offset_y + spacing + str1_height;
        str2_offset_x = (g_camera_cntx.active_camera_osd_ptr->hint_box.width - str2_width) >> 1;

        gdi_layer_reset_clip();
        gui_reset_text_clip();

        if ((g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM) ||
            (g_camera_cntx.app_state == CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM))
        {

            mmi_camera_draw_style_text(
                hint_str1,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + str1_offset_x - offset_x,
                ((MMI_title_height - str1_height) >> 1) - offset_y,
                &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);

        }
        else
        {
            mmi_camera_draw_style_text(
                hint_str1,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + str1_offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y + str1_offset_y - offset_y,
                &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);

            mmi_camera_draw_style_text(
                hint_str2,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + str2_offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y + str2_offset_y - offset_y,
                &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
        }

        if (g_camera_cntx.fade_time != 0 && g_camera_cntx.fade_time != 255)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_camera_preview_hide_hint);
            g_camera_cntx.fade_time = 0;
        }
    }
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_zoom_total_level_cnt
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_camera_get_zoom_total_level_cnt()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_camera_cntx.setting.zoom_idx; i < CAMERA_FEATURE_ZOOM_COUNT; i++)
    {
        if (g_camera_feature_zoom[i] == g_camera_cntx.zoom_limit)
        {
            break;
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_zoom_level_idx
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  factor      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_camera_get_zoom_level_idx(S32 factor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CAMERA_FEATURE_ZOOM_COUNT; i++)
    {
        if (g_camera_feature_zoom[i] == factor)
        {
            return i;
        }
    }

    return g_camera_cntx.setting.zoom_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_icon
 * DESCRIPTION
 *  draw preview OSD panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U8 str_buf_UCS2[512];
    S32 str_width;
    S32 str_height;

#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
    S32 icon_offset_x;
    S32 icon_offset_y;
    S32 image_width;
    S32 image_height;
    S32 icon_bar_width;
    S32 icon_bar_height;
    S32 index;
    S32 offset_x;
    S32 offset_y;
    S32 i;
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__

      /******************************************************/
    /*                Draw Icon List                      */
      /******************************************************/
      /****** draw icon MACRO ******/
#define ICONBAR_DRAW_SWITCH(__a__,__A__)                                                                    \
      {                                                                                                           \
         case CAMERA_ICONBAR_##__A__##:                                                                           \
            gdi_image_get_dimension_id((U16)(IMG_ID_CAMERA_OSD_##__A__##_START+g_camera_cntx.setting.##__a__##+1),\
                                       &image_width,                                                              \
                                       &image_height);                                                            \
            icon_offset_x = ((icon_bar_width-image_width)>>1);                                                    \
            icon_offset_y = ((icon_bar_height-image_height)>>1);                                                  \
            icon_offset_x += offset_x;                                                                            \
            icon_offset_y += offset_y;                                                                            \
            if(index != g_camera_cntx.iconbar_selected_idx)                                                       \
            {                                                                                                     \
               gdi_image_draw_id(offset_x,                                                                        \
                                 offset_y,                                                                        \
                                 IMG_ID_CAMERA_ICONBAR_ITEM);                                                     \
            }                                                                                                     \
            else                                                                                                  \
            {                                                                                                     \
               gdi_image_draw_id(offset_x,                                                                        \
                                 offset_y,                                                                        \
                                 IMG_ID_CAMERA_ICONBAR_ITEM_SEL);                                                 \
            }                                                                                                     \
            gdi_image_draw_id(icon_offset_x,                                                                      \
                              icon_offset_y,                                                                      \
                              (U16)(IMG_ID_CAMERA_OSD_##__A__##_START+g_camera_cntx.setting.##__a__##+1));        \
            offset_x += g_camera_cntx.iconbar_item_width;                                                         \
            break;                                                                                                \
      }

#define ICONBAR_DRAW_SWITCH_IMGVIEW(__a__,__A__)                                                        \
      {                                                                                                       \
         case CAMERA_ICONBAR_##__A__##:                                                                       \
            gdi_image_get_dimension_id((U16)(IMG_ID_CAMERA_OSD_##__A__##_START+g_imgview_context.##__a__##+1),\
                                       &image_width,                                                          \
                                       &image_height);                                                        \
            icon_offset_x = ((icon_bar_width-image_width)>>1);                                                \
            icon_offset_y = ((icon_bar_height-image_height)>>1);                                              \
            icon_offset_x += offset_x;                                                                        \
            icon_offset_y += offset_y;                                                                        \
            if(index != g_camera_cntx.iconbar_selected_idx)                                                   \
            {                                                                                                 \
               gdi_image_draw_id(offset_x,                                                                    \
                                 offset_y,                                                                    \
                                 IMG_ID_CAMERA_ICONBAR_ITEM);                                                 \
            }                                                                                                 \
            else                                                                                              \
            {                                                                                                 \
               gdi_image_draw_id(offset_x,                                                                    \
                                 offset_y,                                                                    \
                                 IMG_ID_CAMERA_ICONBAR_ITEM_SEL);                                             \
            }                                                                                                 \
            gdi_image_draw_id(icon_offset_x,                                                                  \
                              icon_offset_y,                                                                  \
                              (U16)(IMG_ID_CAMERA_OSD_##__A__##_START+g_imgview_context.##__a__##+1));        \
            offset_x += g_camera_cntx.iconbar_item_width;                                                     \
            break;                                                                                            \
      }

    /* draw left arrow */
    offset_x = g_camera_cntx.active_camera_osd_ptr->iconbar.offset_x;
    offset_y = g_camera_cntx.active_camera_osd_ptr->iconbar.offset_y;
    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_LEFT_ARROW);
    gdi_image_get_dimension_id(IMG_ID_CAMERA_ICONBAR_LEFT_ARROW, &image_width, &image_height);

    offset_x += image_width;

    /* get iconbar width */
    gdi_image_get_dimension_id((U16) (IMG_ID_CAMERA_ICONBAR_ITEM), &icon_bar_width, &icon_bar_height);

    for (i = g_camera_cntx.iconbar_start_idx;
         i < g_camera_cntx.iconbar_start_idx + g_camera_cntx.iconbar_item_per_page; i++)
    {
        if (i < g_camera_cntx.iconbar_item_count)
        {
            index = i;
        }
        else
        {
            index = i - g_camera_cntx.iconbar_item_count;
        }

        switch (g_camera_cntx.iconbar_item[index])
        {
                ICONBAR_DRAW_SWITCH(zoom_idx, ZOOM);
                ICONBAR_DRAW_SWITCH(ev, EV);
                ICONBAR_DRAW_SWITCH(effect, EFFECT);
                ICONBAR_DRAW_SWITCH(dsc_mode, DSC_MODE);
                ICONBAR_DRAW_SWITCH(wb, WB);
                ICONBAR_DRAW_SWITCH(flash, FLASH);
                ICONBAR_DRAW_SWITCH(led_highlight, LED_HIGHLIGHT);
                ICONBAR_DRAW_SWITCH(night, NIGHT);
                ICONBAR_DRAW_SWITCH(closeup, CLOSEUP);
                ICONBAR_DRAW_SWITCH(ae_meter, AE_METER);
                ICONBAR_DRAW_SWITCH(cont_shot, CONT_SHOT);
                ICONBAR_DRAW_SWITCH(delay_timer, DELAY_TIMER);
                ICONBAR_DRAW_SWITCH(image_qty, IMAGE_QTY);
                ICONBAR_DRAW_SWITCH_IMGVIEW(storage, STORAGE);
                ICONBAR_DRAW_SWITCH(af_meter, FOCUS_METER);
                ICONBAR_DRAW_SWITCH(af_mode, FOCUS_MODE);

            case CAMERA_ICONBAR_IMAGE_SIZE:
                if (g_camera_cntx.is_tileshot == TRUE)
                {
                    gdi_image_get_dimension_id(
                        (U16) mmi_camera_get_img_size_img_id(LCD_WIDTH, LCD_HEIGHT),
                        &image_width,
                        &image_height);
                }
                else
                {
                    gdi_image_get_dimension_id(
                        (U16) mmi_camera_get_img_size_img_id(g_camera_cntx.image_width, g_camera_cntx.image_height),
                        &image_width,
                        &image_height);
                }

                icon_offset_x = ((icon_bar_width - image_width) >> 1);
                icon_offset_y = ((icon_bar_height - image_height) >> 1);
                icon_offset_x += offset_x;
                icon_offset_y += offset_y;
                if (index != g_camera_cntx.iconbar_selected_idx)
                {
                    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_ITEM);
                }
                else
                {
                    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_ITEM_SEL);
                }
                if (g_camera_cntx.is_tileshot == TRUE)
                {
                    gdi_image_draw_id(
                        icon_offset_x,
                        icon_offset_y,
                        (U16) mmi_camera_get_img_size_img_id(LCD_WIDTH, LCD_HEIGHT));
                }
                else
                {
                    gdi_image_draw_id(
                        icon_offset_x,
                        icon_offset_y,
                        (U16) mmi_camera_get_img_size_img_id(g_camera_cntx.image_width, g_camera_cntx.image_height));
                }
                offset_x += g_camera_cntx.iconbar_item_width;
                break;

            case CAMERA_ICONBAR_ADD_FRAME:
                gdi_image_get_dimension_id(
                    (U16) (IMG_ID_CAMERA_OSD_ADD_FRAME_START + g_camera_cntx.setting.add_frame + 1),
                    &image_width,
                    &image_height);

                icon_offset_x = ((icon_bar_width - image_width) >> 1);
                icon_offset_y = ((icon_bar_height - image_height) >> 1);
                icon_offset_x += offset_x;
                icon_offset_y += offset_y;

                if (g_camera_cntx.is_fullscreen)
                {
                    if (index != g_camera_cntx.iconbar_selected_idx)
                    {
                        gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_ITEM);
                    }
                    else
                    {
                        gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_ITEM_SEL);
                    }
                }
                else
                {
                    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_ITEM_DIS);
                }

                gdi_image_draw_id(
                    icon_offset_x,
                    icon_offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_ADD_FRAME_START + g_camera_cntx.setting.add_frame + 1));

                offset_x += g_camera_cntx.iconbar_item_width;
                break;
        }
    }
    /* draw right arrow */
    gdi_image_draw_id(offset_x, offset_y, IMG_ID_CAMERA_ICONBAR_RIGHT_ARROW);

#else /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

      /******************************************************/
    /*                Draw normal OSD icons               */
      /******************************************************/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
      /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
      do {                                                                                        \
         if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                   \
         {                                                                                        \
            if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
            {                                                                                     \
               switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                        \
                  {                                                                               \
                     case 0:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;     \
                        break;                                                                    \
                     case 1:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;     \
                        break;                                                                    \
                     case 2:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;     \
                        break;                                                                    \
                     case 3:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle3);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;     \
                        break;                                                                    \
                     case 4:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_y;     \
                        break;                                                                    \
                  }                                                                               \
            }                                                                                     \
                  gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->##a##.offset_x-offset_x, \
                                    g_camera_cntx.active_camera_osd_ptr->##a##.offset_y-offset_y, \
                              (U16)(IMG_ID_CAMERA_OSD_##A##_START+g_camera_cntx.setting.##a##+1));\
            if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
               gdi_layer_pop_and_restore_active();                                                \
         }                                                                                        \
      } while(0);
#define CHECK_OSD_LAYER_BEGIN(a)                                                       \
      do {                                                                                \
         if(g_camera_cntx.is_single_osd_layer==FALSE)                                     \
         {                                                                                \
            switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                   \
               {                                                                          \
                  case 0:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;\
                     break;                                                               \
                  case 1:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;\
                     break;                                                               \
                  case 2:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;\
                     break;                                                               \
                  case 3:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle3);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;\
                     break;                                                               \
                  case 4:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_y;\
                     break;                                                               \
               }                                                                          \
         }                                                                                \
      } while(0);

#define CHECK_OSD_LAYER_END()                     \
      do {                                           \
         if(g_camera_cntx.is_single_osd_layer==FALSE)\
            gdi_layer_pop_and_restore_active();      \
      } while(0);
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
      /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
      do {                                                                                        \
         if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                   \
         {                                                                                        \
            if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
            {                                                                                     \
               switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                        \
                  {                                                                               \
                     case 0:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;     \
                        break;                                                                    \
                     case 1:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;     \
                        break;                                                                    \
                     case 2:                                                                      \
                        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);           \
                        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;     \
                        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;     \
                        break;                                                                    \
                  }                                                                               \
            }                                                                                     \
                  gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->##a##.offset_x-offset_x, \
                                    g_camera_cntx.active_camera_osd_ptr->##a##.offset_y-offset_y, \
                              (U16)(IMG_ID_CAMERA_OSD_##A##_START+g_camera_cntx.setting.##a##+1));\
            if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
               gdi_layer_pop_and_restore_active();                                                \
         }                                                                                        \
      } while(0);
#define CHECK_OSD_LAYER_BEGIN(a)                                                       \
      do {                                                                                \
         if(g_camera_cntx.is_single_osd_layer==FALSE)                                     \
         {                                                                                \
            switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                   \
               {                                                                          \
                  case 0:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;\
                     break;                                                               \
                  case 1:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;\
                     break;                                                               \
                  case 2:                                                                 \
                     gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);      \
                     offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;\
                     offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;\
                     break;                                                               \
               }                                                                          \
         }                                                                                \
      } while(0);
#define CHECK_OSD_LAYER_END()                     \
      do {                                           \
         if(g_camera_cntx.is_single_osd_layer==FALSE)\
            gdi_layer_pop_and_restore_active();      \
      } while(0);
#else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
      /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
      do {                                                                                        \
         if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                   \
         {                                                                                        \
            gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->##a##.offset_x,                \
                              g_camera_cntx.active_camera_osd_ptr->##a##.offset_y,                \
                              (U16)(IMG_ID_CAMERA_OSD_##A##_START+g_camera_cntx.setting.##a##+1));\
         }                                                                                        \
      } while(0);
#define CHECK_OSD_LAYER_BEGIN(a)
#define CHECK_OSD_LAYER_END()

#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 

    if (!g_camera_cntx.is_hide_osd)
    {
        /* draw icon */
    #ifdef __CAMERA_FEATURE_EFFECT__
        DRAW_OSD_ICON(effect, EFFECT);
    #endif 

    #ifdef __CAMERA_FEATURE_WB__
        DRAW_OSD_ICON(wb, WB);
    #endif 

    #ifdef __CAMERA_FEATURE_FLASH__
        DRAW_OSD_ICON(flash, FLASH);
    #endif 

    #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
        DRAW_OSD_ICON(led_highlight, LED_HIGHLIGHT);
    #endif 

    #ifdef __CAMERA_FEATURE_EV__
        DRAW_OSD_ICON(ev, EV);
    #endif 

    #ifdef __CAMERA_FEATURE_NIGHT__
        DRAW_OSD_ICON(night, NIGHT);
    #endif 

    #ifdef __CAMERA_FEATURE_XENON_FLASH__
        CHECK_OSD_LAYER_BEGIN(flash_charge_status);
        if (g_camera_cntx.xenon_flash_state == MMI_CAMERA_XENON_FLASH_CHARGING)
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_y - offset_y,
                (U16)IMG_ID_CAMERA_FLASH_CHARGING);
        else if (g_camera_cntx.xenon_flash_state == MMI_CAMERA_XENON_FLASH_READY)
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_y - offset_y,
                (U16)IMG_ID_CAMERA_FLASH_FULL);
        CHECK_OSD_LAYER_END();        
    #endif

        DRAW_OSD_ICON(closeup, CLOSEUP);
        if (g_camera_cntx.active_camera_osd_ptr->image_size.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(image_size);
            if (g_camera_cntx.is_tileshot == TRUE)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
                    (U16) mmi_camera_get_img_size_img_id(LCD_WIDTH, LCD_HEIGHT));
            }
            else
            {

		#if 0		
		//Huyanwei Modify it 
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
                    (U16) mmi_camera_get_img_size_img_id(g_camera_cntx.image_width, g_camera_cntx.image_height));
		#else
			#if defined(__CAMERA_130W_CHEAT__) 
				if ((g_camera_cntx.image_width == CAMERA_FEATURE_IMAGE_SIZE_LLL_WIDTH ) && (g_camera_cntx.image_height == CAMERA_FEATURE_IMAGE_SIZE_LLL_HEIGHT) && (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_LLL))
				{										              
			                	gdi_image_draw_id(
			                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
			                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
			                    (U16) mmi_camera_get_img_size_img_id(1280, 960));				
				}
				else
				{
	 	                   gdi_image_draw_id(
		                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
		                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
		                    (U16) mmi_camera_get_img_size_img_id(g_camera_cntx.image_width, g_camera_cntx.image_height));
				}
			#else
		                gdi_image_draw_id(
		                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
		                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
		                    (U16) mmi_camera_get_img_size_img_id(g_camera_cntx.image_width, g_camera_cntx.image_height));
			#endif
		
		#endif
            }
            CHECK_OSD_LAYER_END();
        }

        DRAW_OSD_ICON(image_qty, IMAGE_QTY);

    #ifdef __CAMERA_FEATURE_CONT_SHOT__
        if (g_camera_cntx.is_external_request == FALSE)
        {   
            /* !for External Request */
            DRAW_OSD_ICON(cont_shot, CONT_SHOT);
        }
    #endif 

    #ifdef __CAMERA_DSC_MODE__
        DRAW_OSD_ICON(dsc_mode, DSC_MODE);
    #endif 

    #ifdef __CAMERA_FEATURE_DELAY_TIMER__
        DRAW_OSD_ICON(delay_timer, DELAY_TIMER);
    #endif 

    #ifdef __CAMERA_AUTOFOCUS_MODE__
        DRAW_OSD_ICON(af_mode, FOCUS_MODE);
    #endif 

    #ifdef __CAMERA_FEATURE_AE_METER__
        DRAW_OSD_ICON(ae_meter, AE_METER);
    #endif 

    #ifdef __CAMERA_AUTOFOCUS_METERING__
        DRAW_OSD_ICON(af_meter, FOCUS_METER);
    #endif 

    #ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        #ifdef __CAMERA_DSC_MODE_NIGHT__
            if(g_camera_cntx.active_camera_osd_ptr->iso.is_show && g_camera_cntx.setting.dsc_mode != CAMERA_SETTING_DSC_MODE_NIGHT)
        #else
            if(g_camera_cntx.active_camera_osd_ptr->iso.is_show)
        #endif
            {
                CHECK_OSD_LAYER_BEGIN(iso);
                gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->iso.offset_x - offset_x,
                                  g_camera_cntx.active_camera_osd_ptr->iso.offset_y - offset_y,
                                  (U16)(IMG_ID_CAMERA_OSD_ISO_START+g_camera_cntx.setting.iso+1));
                CHECK_OSD_LAYER_END();
            }
    #endif 


    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        if (g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
        {
            CHECK_OSD_LAYER_BEGIN(zoom_mf_toggle);
            if (g_camera_cntx.toggle_updown_key == FALSE)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_ZOOM_MF_TOGGLE_MF));
            }
            else
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_ZOOM_MF_TOGGLE_ZOOM));
            }
            CHECK_OSD_LAYER_END();
        }
    #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

    #ifdef __CAMERA_FEATURE_STORAGE__
        if (g_camera_cntx.active_camera_osd_ptr->storage.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(storage);
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->storage.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->storage.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_STORAGE_START + g_imgview_context.storage + 1));
            CHECK_OSD_LAYER_END();
        }
    #endif /* __CAMERA_FEATURE_STORAGE__ */ 
        /* ev */
    #ifdef __CAMERA_FEATURE_EV__
        DRAW_OSD_ICON(ev, EV);

        if (g_camera_cntx.active_camera_osd_ptr->ev_inc.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(ev_inc);

            if (g_camera_cntx.touch_ev_inc.is_press)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_EV_INC_SEL));
            }
            else
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_EV_INC));
            }

            CHECK_OSD_LAYER_END();
        }

        if (g_camera_cntx.active_camera_osd_ptr->ev_dec.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(ev_dec);

            if (g_camera_cntx.touch_ev_dec.is_press)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_EV_DEC_SEL));
            }
            else
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_EV_DEC));
            }
            CHECK_OSD_LAYER_END();
        }

    #endif /* __CAMERA_FEATURE_EV__ */ 

    #ifdef __CAMERA_FEATURE_ZOOM__
        /* zooming icon */
        if ((g_camera_cntx.toggle_updown_key == TRUE) && g_camera_cntx.active_camera_osd_ptr->zoom.is_show &&
            g_camera_cntx.zoom_limit != 10)
        {
            S32 bar_width, bar_height, slider_x, slider_y, slider_width, slider_height;
            U8 total_idx, current_idx;

            CHECK_OSD_LAYER_BEGIN(zoom);

            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->zoom.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->zoom.offset_y - offset_y,
                IMG_ID_CAMERA_OSD_ZOOM_BAR);

            /* CALCULATE THE SLIDER LOACTION AND DRAW */
            total_idx = mmi_camera_get_zoom_total_level_cnt();
            current_idx = (U8) g_camera_cntx.setting.zoom_idx;

        #ifdef __CAMERA_FAST_ZOOM_SUPPORT__
            if (g_camera_cntx.is_fast_zoom)
            {
                mdi_camera_get_fast_zoom_factor(&current_idx);
                g_camera_cntx.setting.zoom_idx = mmi_camera_get_zoom_level_idx(current_idx);
                current_idx = (U8) g_camera_cntx.setting.zoom_idx;
            }
        #endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 

            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_ZOOM_BAR, &bar_width, &bar_height);
            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_ZOOM_SLIDER, &slider_width, &slider_height);

            slider_x = g_camera_cntx.active_camera_osd_ptr->zoom.offset_x - (S32) (slider_width - bar_width) / 2;

            if (current_idx == total_idx)
            {
                slider_y = g_camera_cntx.active_camera_osd_ptr->zoom.offset_y;
            }
            else if (current_idx == 0)
            {
                slider_y = g_camera_cntx.active_camera_osd_ptr->zoom.offset_y + bar_height - slider_height;
            }
            else
            {
                slider_y =
                    g_camera_cntx.active_camera_osd_ptr->zoom.offset_y + (total_idx - current_idx) * (bar_height -
                                                                                                      slider_height) /
                    total_idx;

            }

            gdi_image_draw_id(slider_x - offset_x, slider_y - offset_y, IMG_ID_CAMERA_OSD_ZOOM_SLIDER);

            CHECK_OSD_LAYER_END();

            if (g_camera_cntx.active_camera_osd_ptr->zoom_inc.is_show)
            {
                CHECK_OSD_LAYER_BEGIN(zoom_inc);
                if (g_camera_cntx.touch_zoom_inc.is_press)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC));
                }
                CHECK_OSD_LAYER_END();
            }

            if (g_camera_cntx.active_camera_osd_ptr->zoom_dec.is_show)
            {
                CHECK_OSD_LAYER_BEGIN(zoom_dec);
                if (g_camera_cntx.touch_zoom_dec.is_press)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC));
                }
                CHECK_OSD_LAYER_END();
            }
        }

    #endif /* __CAMERA_FEATURE_ZOOM__ */ 

    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        if (g_camera_cntx.toggle_updown_key == FALSE &&
            g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
        {
            S32 bar_width, bar_height, slider_x, slider_y, slider_width, slider_height;
            U8 total_idx, current_idx;

            CHECK_OSD_LAYER_BEGIN(zoom);

            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->zoom.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->zoom.offset_y - offset_y,
                IMG_ID_CAMERA_OSD_MF_BAR);

            /* CALCULATE THE SLIDER LOACTION AND DRAW */
            if (g_camera_cntx.is_mf_continue == TRUE)
            {
                mdi_camera_get_focus_steps(&(g_camera_cntx.mf_level_cnt), &(g_camera_cntx.mf_level_idx));
            }

            total_idx = (U8) g_camera_cntx.mf_level_cnt;
            current_idx = (U8) g_camera_cntx.mf_level_idx;

            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_MF_BAR, &bar_width, &bar_height);
            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_MF_SLIDER, &slider_width, &slider_height);

            slider_x = g_camera_cntx.active_camera_osd_ptr->zoom.offset_x - (S32) (slider_width - bar_width) / 2;

            if (current_idx == total_idx)
            {
                slider_y = g_camera_cntx.active_camera_osd_ptr->zoom.offset_y;
            }
            else if (current_idx == 0)
            {
                slider_y = g_camera_cntx.active_camera_osd_ptr->zoom.offset_y + bar_height - slider_height;
            }
            else
            {
                slider_y =
                    g_camera_cntx.active_camera_osd_ptr->zoom.offset_y + (total_idx - current_idx) * (bar_height -
                                                                                                      slider_height) /
                    total_idx;

            }

            gdi_image_draw_id(slider_x - offset_x, slider_y - offset_y, IMG_ID_CAMERA_OSD_MF_SLIDER);

            CHECK_OSD_LAYER_END();

            if (g_camera_cntx.active_camera_osd_ptr->zoom_inc.is_show)
            {
                CHECK_OSD_LAYER_BEGIN(zoom_inc);
                if (g_camera_cntx.touch_zoom_inc.is_press)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_MF_INC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_MF_INC));
                }
                CHECK_OSD_LAYER_END();
            }

            if (g_camera_cntx.active_camera_osd_ptr->zoom_dec.is_show)
            {
                CHECK_OSD_LAYER_BEGIN(zoom_dec);
                if (g_camera_cntx.touch_zoom_dec.is_press)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_MF_DEC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_MF_DEC));
                }
                CHECK_OSD_LAYER_END();
            }
        }
    #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

        /* remain storage string */
        if (g_camera_cntx.active_camera_osd_ptr->remain_storage.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(remain_storage);
            gui_reset_text_clip();
            gui_set_font(&MMI_small_font);

            sprintf(str_buf, "%d%%", g_camera_cntx.remain_percent);
            mmi_asc_to_ucs2((PS8) str_buf_UCS2, (PS8) str_buf);

            gui_measure_string((UI_string_type) str_buf_UCS2, &str_width, &str_height);

            if (g_camera_cntx.active_camera_osd_ptr->remain_storage.is_right_align)
            {
                mmi_camera_draw_style_text(
                    (PS8) str_buf_UCS2,
                    g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_x - str_width - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_y - offset_y,
                    &g_camera_cntx.active_camera_osd_ptr->remain_storage.style_text);
            }
            else
            {
                mmi_camera_draw_style_text(
                    (PS8) str_buf_UCS2,
                    g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_y - offset_y,
                    &g_camera_cntx.active_camera_osd_ptr->remain_storage.style_text);
            }
            CHECK_OSD_LAYER_END();
        }
    }
    else
    {
    #ifdef __CAMERA_FAST_ZOOM_SUPPORT__
        /* While the osd is hiden and fast_zoom is true, still update zoom_idx from DRV */
        if (g_camera_cntx.is_fast_zoom)
        {
            U8 current_idx;
            mdi_camera_get_fast_zoom_factor(&current_idx);
            g_camera_cntx.setting.zoom_idx = mmi_camera_get_zoom_level_idx(current_idx);
        }
    #endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
    }

 #if defined(DOUBLE_CAMERA_SUPPORT)
 	//Huyanwei Add it 
 	if ( g_camera_cntx.is_hide_osd != KAL_TRUE)
 	{
 	  gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);   
 	if (double_cam/*mmi_main_camera_active*/ ==1)
        {
			#if 1        
                    gdi_image_draw_id(
                        Camera_Switch_OffsetX,
 		       Camera_Switch_OffsetY,
                        (U16) (IMG_ID_CAMERA_DOUBLE_0));
			#endif

			// Draw Sub  Camera 
        }
        else
        {
			#if 1        
            gdi_image_draw_id(
                        Camera_Switch_OffsetX,
 		       Camera_Switch_OffsetY,
                (U16) (IMG_ID_CAMERA_DOUBLE_1));
			#endif
			// Draw Main Camera 
        }
          gdi_layer_pop_and_restore_active();  
 	}
 #endif


    /* capture icon */
    if (g_camera_cntx.active_camera_osd_ptr->capture.is_show)
    {
        CHECK_OSD_LAYER_BEGIN(capture);
        if (g_camera_cntx.is_capturing)
        {
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->capture.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->capture.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_CAPTURE_SEL));
        }
        else
        {
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->capture.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->capture.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_CAPTURE));
        }
        CHECK_OSD_LAYER_END();
    }
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_contshot_countbar
 * DESCRIPTION
 *  draw contshot contbar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
static void mmi_camera_preview_draw_contshot_countbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
    S32 image_width;
    S32 image_height;
    S32 box_height;
    S32 offset_x;
    S32 offset_y;
    S32 remain_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.setting.cont_shot)
    {
        case CAMERA_SETTING_CONT_SHOT_1:
            img_id = IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_1;
            break;

        case CAMERA_SETTING_CONT_SHOT_2:
            img_id = IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_2;
            break;

        case CAMERA_SETTING_CONT_SHOT_3:
            img_id = IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_3;
            break;

        default:
            img_id = 0;
    }

    gdi_image_get_dimension_id(img_id, &image_width, &image_height);

    box_height = image_height / g_camera_cntx.cont_shot_total_count;
    remain_shot = g_camera_cntx.cont_shot_total_count - g_camera_cntx.cont_shot_count;

    if (g_camera_osd_cntx.cont_count_bar.is_top_align)
    {
        /* top align */
        offset_x = g_camera_osd_cntx.cont_count_bar.offset_x;
        offset_y = g_camera_osd_cntx.cont_count_bar.offset_y;

        gdi_layer_push_clip();
        gdi_layer_set_clip(offset_x, offset_y, offset_x + image_width - 1, offset_y + box_height * remain_shot - 1);

        gdi_image_draw_id(offset_x, offset_y, img_id);
        gdi_layer_pop_clip();
    }
    else
    {
        /* bottom align */
        offset_x = g_camera_osd_cntx.cont_count_bar.offset_x;
        offset_y = g_camera_osd_cntx.cont_count_bar.offset_y;

        gdi_layer_push_clip();
        gdi_layer_set_clip(offset_x, offset_y - box_height * remain_shot + 1, offset_x + image_width - 1, offset_y);

        gdi_image_draw_id(offset_x, offset_y - image_height + 1, img_id);
        gdi_layer_pop_clip();
    }

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_set_hint
 * DESCRIPTION
 *  set hint string
 * PARAMETERS
 *  hint_str1       [IN]        String 1
 *  hint_str2       [IN]        String 2
 *  fade_time       [IN]        Hint fade out time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear buffer */
    memset(g_camera_cntx.hint1_buf, 0, CAMERA_HINT_BUF_SIZE);
    memset(g_camera_cntx.hint2_buf, 0, CAMERA_HINT_BUF_SIZE);

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_camera_cntx.hint1_buf, (PS8) hint_str1, CAMERA_HINT_CHAR_COUNT);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_camera_cntx.hint2_buf, (PS8) hint_str2, CAMERA_HINT_CHAR_COUNT);
    }

    g_camera_cntx.fade_time = fade_time;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_check_sensor_orientation
 * DESCRIPTION
 *  update orientation between sensor and lcm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_OSD_HORIZONTAL__)
void mmi_camera_check_sensor_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate base layer */
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
    gdi_layer_pop_and_restore_active();

}
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_check_osd_orientation
 * DESCRIPTION
 *  update display rotate (0 | 90 | 180 | 270 )
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_check_osd_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
#define ROTATE_OSD_LAYER(__a__, __A__,__L__)                                                                                            \
   do {                                                                                                                                    \
   gdi_layer_push_and_set_active(g_camera_cntx.##__L__##);                                                                                 \
   gdi_layer_set_rotate(##__A__##);                                                                                                        \
   gdi_layer_resize(g_camera_cntx.active_camera_osd_ptr->##__a__##.width,g_camera_cntx.active_camera_osd_ptr->##__a__##.height);           \
   gdi_layer_set_position(g_camera_cntx.active_camera_osd_ptr->##__a__##.offset_x,g_camera_cntx.active_camera_osd_ptr->##__a__##.offset_y);\
   gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);                                                                                      \
   gdi_layer_pop_and_restore_active();                                                                                                     \
   } while(0);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    if (g_camera_cntx.previous_osd_rotate != g_camera_cntx.osd_rotate)
    {
        switch (g_camera_cntx.osd_rotate)
        {
            case CAMERA_DISPLAY_ROTATE_0:
                g_camera_cntx.active_camera_osd_ptr = &g_camera_osd_cntx;
                g_camera_cntx.osd_UI_device_height = LCD_HEIGHT;
                g_camera_cntx.osd_UI_device_width = LCD_WIDTH;
        #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
                if (g_camera_cntx.is_single_osd_layer)
                {
                    gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                    gdi_layer_set_rotate(CAMERA_DISPLAY_ROTATE_270);
                    gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
                    gdi_layer_set_position(0, 0);
                    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                    gdi_layer_pop_and_restore_active();
                }
                else
                {
                    ROTATE_OSD_LAYER(osd_region0, CAMERA_DISPLAY_ROTATE_270, osd_layer_handle0);
                    ROTATE_OSD_LAYER(osd_region1, CAMERA_DISPLAY_ROTATE_270, osd_layer_handle1);
                    ROTATE_OSD_LAYER(osd_region2, CAMERA_DISPLAY_ROTATE_270, osd_layer_handle2);
                    #ifdef __MMI_CAMERA_5_OSD_LAYER__
                        ROTATE_OSD_LAYER(osd_region3, CAMERA_DISPLAY_ROTATE_270, osd_layer_handle3);
                        ROTATE_OSD_LAYER(osd_region4, CAMERA_DISPLAY_ROTATE_270, osd_layer_handle4);
                    #endif
                }
        #else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
                gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                gdi_layer_toggle_double();
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);
                gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
        #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
                break;
#ifdef __CAMERA_OSD_HORIZONTAL__
            case CAMERA_DISPLAY_ROTATE_270:
                g_camera_cntx.active_camera_osd_ptr = &g_camera_osd_cntx_270;
                g_camera_cntx.osd_UI_device_height = LCD_WIDTH;
                g_camera_cntx.osd_UI_device_width = LCD_HEIGHT;
            #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
                if (g_camera_cntx.is_single_osd_layer)
                {
                    gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                    gdi_layer_set_rotate(CAMERA_DISPLAY_ROTATE_0);
                    gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
                    gdi_layer_set_position(0, 0);
                    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                    gdi_layer_pop_and_restore_active();
                }
                else
                {
                    ROTATE_OSD_LAYER(osd_region0, CAMERA_DISPLAY_ROTATE_0, osd_layer_handle0);
                    ROTATE_OSD_LAYER(osd_region1, CAMERA_DISPLAY_ROTATE_0, osd_layer_handle1);
                    ROTATE_OSD_LAYER(osd_region2, CAMERA_DISPLAY_ROTATE_0, osd_layer_handle2);
                    #ifdef __MMI_CAMERA_5_OSD_LAYER__
                        ROTATE_OSD_LAYER(osd_region3, CAMERA_DISPLAY_ROTATE_0, osd_layer_handle3);
                        ROTATE_OSD_LAYER(osd_region4, CAMERA_DISPLAY_ROTATE_0, osd_layer_handle4);
                    #endif
                }
            #else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
                gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                gdi_layer_toggle_double();
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
                break;
            #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
                break;
#endif
            default:
                ASSERT(0);
                break;
        }

        g_camera_cntx.previous_osd_rotate = g_camera_cntx.osd_rotate;
        mmi_camera_update_osd_touch_icon();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_zoom_limit
 * DESCRIPTION
 *  get zoom limit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_camera_get_zoom_limit(U16 capture_size_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_limit = 10;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(ISP_SUPPORT) && defined(__MTK_TARGET__)
    /* get zoom_limit from sensor driver */
    if (g_camera_cntx.has_camera_previewed == TRUE)
    {
        ASSERT(CAMERA_SETTING_IMAGE_SIZE_COUNT>capture_size_enum);
        zoom_limit = g_camera_cntx.max_zoom_limit[capture_size_enum];
    }
    else
#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
    {
        switch(capture_size_enum)
        {
	#if defined(__CAMERA_130W_CHEAT__) 
  	     //Huyanwei Add It 
            case CAMERA_SETTING_IMAGE_SIZE_LLL:
            zoom_limit = CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT;
	     break;
	 #endif			
        #if defined(__CAMERA_FEATURE_IMAGE_SIZE_LL__)
            case CAMERA_SETTING_IMAGE_SIZE_LL:
            zoom_limit = CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT;
            break;
        #endif
        #if defined(__CAMERA_FEATURE_IMAGE_SIZE_L__)
            case CAMERA_SETTING_IMAGE_SIZE_L:
            zoom_limit = CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT;
            break;
        #endif
        #if defined(__CAMERA_FEATURE_IMAGE_SIZE_M__)
            case CAMERA_SETTING_IMAGE_SIZE_M:
            zoom_limit = CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT;
            break;
        #endif
        #if defined(__CAMERA_FEATURE_IMAGE_SIZE_S__)
            case CAMERA_SETTING_IMAGE_SIZE_S:
            zoom_limit = CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT;
            break;
        #endif
        #if defined(__CAMERA_FEATURE_IMAGE_SIZE_SS__)
            case CAMERA_SETTING_IMAGE_SIZE_SS:
            zoom_limit = CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT;
            break;
        #endif
            default:
            break;            
        }    
    }
    return zoom_limit;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_update_capture_size
 * DESCRIPTION
 *  update capture size and preview size due to setting change
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_preview_update_capture_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#define UPDATE_IMAGE_SIZE(_SIZE_) \
    do{\
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_##_SIZE_##)\
    {\
        g_camera_cntx.preview_width = CAMERA_FEATURE_PREVIEW_SIZE_##_SIZE_##_WIDTH;\
        g_camera_cntx.preview_height = CAMERA_FEATURE_PREVIEW_SIZE_##_SIZE_##_HEIGHT;\
        g_camera_cntx.image_width = CAMERA_FEATURE_IMAGE_SIZE_##_SIZE_##_WIDTH;\
        g_camera_cntx.image_height = CAMERA_FEATURE_IMAGE_SIZE_##_SIZE_##_HEIGHT;\
    }\
    }while(0)


    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* check if is burst shot, if yes, change and store previous capture size */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {    
        /* if not correct image size, change to it */
        if (g_camera_cntx.setting.image_size != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX)
        {
            g_camera_cntx.image_size_before_burst = g_camera_cntx.setting.image_size;
            g_camera_cntx.setting.image_size = CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX;
        }
    }
    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    #if defined(__CAMERA_130W_CHEAT__) 
	//Huyanwei Add It 
       UPDATE_IMAGE_SIZE(LLL);	
    #endif

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    UPDATE_IMAGE_SIZE(LL);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    UPDATE_IMAGE_SIZE(L);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    UPDATE_IMAGE_SIZE(M);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    UPDATE_IMAGE_SIZE(S);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 

    #ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    UPDATE_IMAGE_SIZE(SS);
    #endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 


    g_camera_cntx.zoom_limit = mmi_camera_get_zoom_limit(g_camera_cntx.setting.image_size);


    if ((g_camera_cntx.image_width == LCD_WIDTH) && (g_camera_cntx.image_height == LCD_HEIGHT))
    {
        g_camera_cntx.is_fullscreen = TRUE;

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.is_tileshot != TRUE)
        {
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
            g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
        }
    #else 
        g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
    #endif 
    }
    else
    {
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.is_fullscreen == TRUE)
        {
            g_camera_cntx.previous_osd_rotate = g_camera_cntx.osd_rotate;
            g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
            g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
        }
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        g_camera_cntx.is_fullscreen = FALSE;
    }

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_TILE)
    {
        g_camera_cntx.is_tileshot = TRUE;

        g_camera_cntx.image_width = (g_camera_cntx.osd_UI_device_width >> 1);
        g_camera_cntx.image_height = (g_camera_cntx.osd_UI_device_height >> 1);

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.osd_UI_device_width == LCD_WIDTH)
        {
            g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
            g_camera_cntx.is_fullscreen = TRUE;
        }
        else
        {
            g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
            g_camera_cntx.is_fullscreen = FALSE;
        }
        g_camera_cntx.preview_width = (LCD_HEIGHT >> 1);
        g_camera_cntx.preview_height = (LCD_WIDTH >> 1);
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
        /* tile shot also is a kind of fullscreen shot */
        g_camera_cntx.is_fullscreen = TRUE;

        g_camera_cntx.preview_width = (LCD_WIDTH >> 1);
        g_camera_cntx.preview_height = (LCD_HEIGHT >> 1);

    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        /* set tileshot's zoom limit */
        g_camera_cntx.zoom_limit = CAMERA_FEATURE_PREVIEW_TILE_ZOOM_LIMIT;
    }
    else
    {
        g_camera_cntx.is_tileshot = FALSE;
    #if !defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.is_fullscreen)
        {
            g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
        }
        else
        {
            g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
        }
    #endif /* !defined(__CAMERA_OSD_HORIZONTAL__) */ 
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
        g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
        g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_get_zoom_factor
 * DESCRIPTION
 *  get zoom factor based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_camera_preview_get_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.setting.zoom_idx >= CAMERA_FEATURE_ZOOM_COUNT)
    {
        mmi_camera_restore_setting();
        return 0;
    }
    else
    {
        return g_camera_feature_zoom[g_camera_cntx.setting.zoom_idx];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_right_arrow_press
 * DESCRIPTION
 *  iconbar right arrow press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_right_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.iconbar_selected_idx++;
    if (g_camera_cntx.iconbar_selected_idx >= g_camera_cntx.iconbar_item_count)
    {
        g_camera_cntx.iconbar_selected_idx = 0;
    }

    g_camera_cntx.iconbar_start_idx++;
    if (g_camera_cntx.iconbar_start_idx >= g_camera_cntx.iconbar_item_count)
    {
        g_camera_cntx.iconbar_start_idx = 0;
    }

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_right_arrow_release
 * DESCRIPTION
 *  iconbar right arrow rlease
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_right_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_left_arrow_press
 * DESCRIPTION
 *  iconbar left arrow press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_left_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.iconbar_selected_idx--;
    if (g_camera_cntx.iconbar_selected_idx < 0)
    {
        g_camera_cntx.iconbar_selected_idx = g_camera_cntx.iconbar_item_count - 1;
    }

    g_camera_cntx.iconbar_start_idx--;
    if (g_camera_cntx.iconbar_start_idx < 0)
    {
        g_camera_cntx.iconbar_start_idx = g_camera_cntx.iconbar_item_count - 1;
    }

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_left_arrow_releas
 * DESCRIPTION
 *  iconbar left arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_left_arrow_releas(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_up_arrow_press
 * DESCRIPTION
 *  iconbar up arrow press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_up_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define ICONBAR_SETTING_INC(__a__,__A__)        \
   {                                               \
      case CAMERA_ICONBAR_##__A__##:               \
         mmi_camera_preview_##__a__##_change(TRUE);\
         break;                                    \
   }

    switch (g_camera_cntx.iconbar_item[g_camera_cntx.iconbar_selected_idx])
    {
        case CAMERA_ICONBAR_ZOOM:
    #ifdef __CAMERA_FEATURE_ZOOM__
            mmi_camera_preview_zoom_in();
    #endif 
            break;

        case CAMERA_ICONBAR_EV:
    #ifdef __CAMERA_FEATURE_EV__
            mmi_camera_preview_ev_inc_key_press();
    #endif 
            break;

        case CAMERA_ICONBAR_ADD_FRAME:
    #ifdef __CAMERA_FEATURE_ADD_FRAME__
            mmi_camera_preview_change_frame_up();
    #endif 
            break;

    #ifdef __CAMERA_FEATURE_EFFECT__
            ICONBAR_SETTING_INC(effect, EFFECT);
    #endif 

    #ifdef __CAMERA_FEATURE_WB__
            ICONBAR_SETTING_INC(wb, WB);
    #endif 

    #ifdef __CAMERA_FEATURE_FLASH__
            ICONBAR_SETTING_INC(flash, FLASH);
    #endif 

    #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
            ICONBAR_SETTING_INC(led_highlight, LED_HIGHLIGHT);
    #endif 

    #ifdef __CAMERA_FEATURE_NIGHT__
            ICONBAR_SETTING_INC(night, NIGHT);
    #endif 

    #ifdef __CAMERA_FEATURE_CONT_SHOT__
            ICONBAR_SETTING_INC(cont_shot, CONT_SHOT);
    #endif 

    #ifdef __CAMERA_FEATURE_DELAY_TIMER__
            ICONBAR_SETTING_INC(delay_timer, DELAY_TIMER);
    #endif 

            ICONBAR_SETTING_INC(image_size, IMAGE_SIZE);
            ICONBAR_SETTING_INC(image_qty, IMAGE_QTY);

    #ifdef __CAMERA_FEATURE_STORAGE__
            ICONBAR_SETTING_INC(storage, STORAGE);
    #endif 

    #ifdef __CAMERA_FEATURE_AE_METER__
            ICONBAR_SETTING_INC(ae_meter, AE_METER);
    #endif 

    #ifdef __CAMERA_DSC_MODE__
            ICONBAR_SETTING_INC(dsc_mode, DSC_MODE);
    #endif 

    #ifdef __CAMERA_AUTOFOCUS_MODE__
            ICONBAR_SETTING_INC(af_mode, FOCUS_MODE);
    #endif 

    #ifdef __CAMERA_AUTOFOCUS_METERING__
            ICONBAR_SETTING_INC(af_meter, FOCUS_METER);
    #endif 
    }

}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_up_arrow_release
 * DESCRIPTION
 *  icon bar up arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_up_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.iconbar_item[g_camera_cntx.iconbar_selected_idx])
    {
        case CAMERA_ICONBAR_ZOOM:
            gui_cancel_timer(mmi_camera_preview_zoom_in);
            break;

        case CAMERA_ICONBAR_EV:
            mmi_camera_preview_ev_inc_key_release();
            break;
    }
}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_down_arrow_press
 * DESCRIPTION
 *  iconbar down arrow press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_down_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define ICONBAR_SETTING_DEC(__a__,__A__)         \
   {                                                \
      case CAMERA_ICONBAR_##__A__##:                \
         mmi_camera_preview_##__a__##_change(FALSE);\
         break;                                     \
   }

    switch (g_camera_cntx.iconbar_item[g_camera_cntx.iconbar_selected_idx])
    {
        case CAMERA_ICONBAR_ZOOM:
    #ifdef __CAMERA_FEATURE_ZOOM__
            mmi_camera_preview_zoom_out();
    #endif 
            break;

        case CAMERA_ICONBAR_EV:
    #ifdef __CAMERA_FEATURE_EV__
            mmi_camera_preview_ev_dec_key_press();
    #endif 
            break;

        case CAMERA_ICONBAR_ADD_FRAME:
    #ifdef __CAMERA_FEATURE_ADD_FRAME__
            mmi_camera_preview_change_frame_down();
    #endif 
            break;

    #ifdef __CAMERA_FEATURE_EFFECT__
            ICONBAR_SETTING_DEC(effect, EFFECT);
    #endif 

    #ifdef __CAMERA_FEATURE_WB__
            ICONBAR_SETTING_DEC(wb, WB);
    #endif 

    #ifdef __CAMERA_FEATURE_FLASH__
            ICONBAR_SETTING_DEC(flash, FLASH);
    #endif 

    #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
            ICONBAR_SETTING_DEC(led_highlight, LED_HIGHLIGHT);
    #endif 

    #ifdef __CAMERA_FEATURE_NIGHT__
            ICONBAR_SETTING_DEC(night, NIGHT);
    #endif 

    #ifdef __CAMERA_FEATURE_CONT_SHOT__
            ICONBAR_SETTING_DEC(cont_shot, CONT_SHOT);
    #endif 

    #ifdef __CAMERA_FEATURE_DELAY_TIMER__
            ICONBAR_SETTING_DEC(delay_timer, DELAY_TIMER);
    #endif 

            ICONBAR_SETTING_DEC(image_size, IMAGE_SIZE);
            ICONBAR_SETTING_DEC(image_qty, IMAGE_QTY);

    #ifdef __CAMERA_FEATURE_STORAGE__
            ICONBAR_SETTING_DEC(storage, STORAGE);
    #endif 

    #ifdef __CAMERA_FEATURE_AE_METER__
            ICONBAR_SETTING_DEC(ae_meter, AE_METER);
    #endif 

    #ifdef __CAMERA_DSC_MODE__
            ICONBAR_SETTING_DEC(dsc_mode, DSC_MODE);
    #endif 

    #ifdef __CAMERA_AUTOFOCUS_MODE__
            ICONBAR_SETTING_DEC(af_mode, FOCUS_MODE);
    #endif 

    #ifdef __CAMERA_AUTOFOCUS_METERING__
            ICONBAR_SETTING_DEC(af_meter, FOCUS_METER);
    #endif 

    }
}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_iconbar_down_arrow_release
 * DESCRIPTION
 *  iconbar down arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
static void mmi_camera_iconbar_down_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.iconbar_item[g_camera_cntx.iconbar_selected_idx])
    {
        case CAMERA_ICONBAR_ZOOM:
            gui_cancel_timer(mmi_camera_preview_zoom_out);
            break;

        case CAMERA_ICONBAR_EV:
            mmi_camera_preview_ev_dec_key_release();
            break;
    }
}
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_ev_inc_key_press
 * DESCRIPTION
 *  preview right arrow pressed, adjust EV
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_ev_inc_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.ev < CAMERA_SETTING_EV_COUNT - 1)
        {
            g_camera_cntx.touch_ev_inc.is_press = TRUE;

            g_camera_cntx.setting.ev++;

            mdi_camera_update_para_ev(camera_ev_command_map[g_camera_cntx.setting.ev]);

            mmi_camera_preview_set_hint(NULL, NULL, 0);
            mmi_camera_preview_draw_osd();

            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);

            if (g_camera_cntx.is_ev_inc_pressed)
            {
                gui_start_timer(100, mmi_camera_preview_ev_inc_key_press);
            }
            else
            {
                /* first time press up arrow, use longer time */
                gui_start_timer(300, mmi_camera_preview_ev_inc_key_press);
                g_camera_cntx.is_ev_inc_pressed = TRUE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_ev_inc_key_release
 * DESCRIPTION
 *  preview right arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_ev_inc_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_preview_ev_inc_key_press);
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        g_camera_cntx.is_ev_inc_pressed = FALSE;
        g_camera_cntx.touch_ev_inc.is_press = FALSE;
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_ev_dec_key_press
 * DESCRIPTION
 *  preview left arrow pressed, adjust EV
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_ev_dec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.ev > 0)
        {
            g_camera_cntx.touch_ev_dec.is_press = TRUE;

            g_camera_cntx.setting.ev--;

            mdi_camera_update_para_ev(camera_ev_command_map[g_camera_cntx.setting.ev]);

            mmi_camera_preview_set_hint(NULL, NULL, 0);
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);

            if (g_camera_cntx.is_ev_dec_pressed)
            {
                gui_start_timer(100, mmi_camera_preview_ev_dec_key_press);
            }
            else
            {
                /* first time press up arrow, use longer time */
                gui_start_timer(300, mmi_camera_preview_ev_dec_key_press);
                g_camera_cntx.is_ev_dec_pressed = TRUE;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_ev_dec_key_release
 * DESCRIPTION
 *  preview left arrow release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_ev_dec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_preview_ev_dec_key_press);
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        g_camera_cntx.is_ev_dec_pressed = FALSE;
        g_camera_cntx.touch_ev_dec.is_press = FALSE;
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_initilize_zoom_factor
 * DESCRIPTION
 *  initialize zoom factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_initilize_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 zoom_limit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LL, L, M, S, SS */
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT;
    }

    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_SS)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_SS];
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT;
    }

    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_S)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_S];

#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT;
    }

    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_M)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_M];
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT;
    }
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_L)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_L];
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT;
    }
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_LL)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_LL];

#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 

#if defined(__CAMERA_130W_CHEAT__) 
    //Huyanwei Add It 
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_LLL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LLL_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_LLL_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_LLL_ZOOM_LIMIT;
    }
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_LLL)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_LLL];
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_zoom_in
 * DESCRIPTION
 *  zoom out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ZOOM__
static void mmi_camera_preview_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.zoom_idx < CAMERA_FEATURE_ZOOM_COUNT - 1)
        {
            if (g_camera_cntx.zoom_limit > mmi_camera_preview_get_zoom_factor())
            {
                g_camera_cntx.setting.zoom_idx += 1;

                g_camera_cntx.touch_zoom_inc.is_press = TRUE;

                /* get zoom factor based on features define */
                zoom_factor = mmi_camera_preview_get_zoom_factor();

                mdi_camera_update_para_zoom(zoom_factor);

                mmi_camera_preview_set_hint(NULL, NULL, 0);
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);

            #if defined(ISP_SUPPORT)
                /* only build-in camera use long pressed zooming feature */
                /* since backend module's zooming time is not stable, will cause zooming jump two level */
            #ifdef __CAMERA_FAST_ZOOM_SUPPORT__
                if (!g_camera_cntx.is_up_arrow_pressed)
                {
                    gui_start_timer(200, mmi_camera_start_fast_zoom_in);
                }
            #else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
                if (g_camera_cntx.is_up_arrow_pressed)
                {
                    gui_start_timer(100, mmi_camera_preview_zoom_in);
                }
                else
                {
                    /* first time press up arrow, use longer time */
                    gui_start_timer(300, mmi_camera_preview_zoom_in);
                }
            #endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            #endif /* defined(ISP_SUPPORT) */ 

            }
        }
        else
        {
            g_camera_cntx.touch_zoom_inc.is_press = FALSE;
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);
        }
    }

}
#endif /* __CAMERA_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_draw_osd_timer
 * DESCRIPTION
 *  redraw osd timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_draw_osd_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    if (g_camera_cntx.is_draw_timer_on)
    {
        gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_zoom_out
 * DESCRIPTION
 *  zoom out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ZOOM__
static void mmi_camera_preview_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.zoom_idx > 0)
        {
            g_camera_cntx.touch_zoom_dec.is_press = TRUE;

            g_camera_cntx.setting.zoom_idx -= 1;

            /* get zoom factor based on features define */
            zoom_factor = mmi_camera_preview_get_zoom_factor();

            mdi_camera_update_para_zoom(zoom_factor);

            mmi_camera_preview_set_hint(NULL, NULL, 0);
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);

        #if defined(ISP_SUPPORT)
        #ifdef __CAMERA_FAST_ZOOM_SUPPORT__
            if (!g_camera_cntx.is_down_arrow_pressed)
            {
                gui_start_timer(200, mmi_camera_start_fast_zoom_out);
            }
        #else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            /* only build-in camera use long pressed zooming feature */
            /* since backend module's zooming time is not stable, will cause zooming jump two level */
            if (g_camera_cntx.is_down_arrow_pressed)
            {
                gui_start_timer(100, mmi_camera_preview_zoom_out);
            }
            else
            {
                /* first time press down arrow, use longer time */
                gui_start_timer(300, mmi_camera_preview_zoom_out);
            }
        #endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
        #endif /* defined(ISP_SUPPORT) */ 

        }
        else
        {
            g_camera_cntx.touch_zoom_dec.is_press = FALSE;
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);
        }
    }
}
#endif /* __CAMERA_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_up_arrow_press
 * DESCRIPTION
 *  preview up arrow pressed, adjust zooming
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_up_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_camera_cntx.is_up_arrow_pressed)
    {
        switch (g_camera_cntx.up_key)
        {
            case CAMERA_ZOOMIN:
                mmi_camera_preview_zoom_in();
                break;
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            case CAMERA_MF_FORWARD:
                mmi_camera_mf_forward();
                break;
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
        }
    }

    g_camera_cntx.is_up_arrow_pressed = TRUE;
}
#endif /* defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_up_arrow_release
 * DESCRIPTION
 *  preview up arrow release, stop adjust zooming
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_up_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_up_arrow_pressed = FALSE;

    g_camera_cntx.touch_zoom_inc.is_press = FALSE;

    switch (g_camera_cntx.up_key)
    {
        case CAMERA_ZOOMIN:
    #ifdef __CAMERA_FAST_ZOOM_SUPPORT__
            if (g_camera_cntx.is_fast_zoom == TRUE)
            {
                g_camera_cntx.is_draw_timer_on = FALSE;
                mmi_camera_stop_fast_zoom();
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
                gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            }
            else if (g_camera_cntx.is_fast_zoom == FALSE)
            {
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
                gui_cancel_timer(mmi_camera_start_fast_zoom_in);
            }
    #else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            gui_cancel_timer(mmi_camera_preview_zoom_in);
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);
    #endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            break;
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        case CAMERA_MF_FORWARD:
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            if (g_camera_cntx.is_mf_continue == TRUE)
            {
                g_camera_cntx.is_draw_timer_on = FALSE;
                mmi_camera_mf_stop();
                gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            }
            else
            {
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
                gui_cancel_timer(mmi_camera_mf_forward_continue);
            }
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
            break;
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

    }
}
#endif /* defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_down_arrow_press
 * DESCRIPTION
 *  preview down arrow pressed, adjust zooming
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_down_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_camera_cntx.is_down_arrow_pressed)
    {
        switch (g_camera_cntx.down_key)
        {
            case CAMERA_ZOOMOUT:
                mmi_camera_preview_zoom_out();
                break;
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            case CAMERA_MF_BACKWARD:
                mmi_camera_mf_backward();
                break;
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
        }
    }

    g_camera_cntx.is_down_arrow_pressed = TRUE;

}
#endif /* defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_down_arrow_release
 * DESCRIPTION
 *  preview down arrow release, stop adjust zooming
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_down_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_down_arrow_pressed = FALSE;

    g_camera_cntx.touch_zoom_dec.is_press = FALSE;

    switch (g_camera_cntx.down_key)
    {
        case CAMERA_ZOOMOUT:
    #ifdef __CAMERA_FAST_ZOOM_SUPPORT__
            if (g_camera_cntx.is_fast_zoom == TRUE)
            {
                g_camera_cntx.is_draw_timer_on = FALSE;
                mmi_camera_stop_fast_zoom();
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);    
                gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            }
            else if (g_camera_cntx.is_fast_zoom == FALSE)
            {
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
                gui_cancel_timer(mmi_camera_start_fast_zoom_out);
            }
    #else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            gui_cancel_timer(mmi_camera_preview_zoom_out);
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);
    #endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            break;
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        case CAMERA_MF_BACKWARD:
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            if (g_camera_cntx.is_mf_continue == TRUE)
            {
                g_camera_cntx.is_draw_timer_on = FALSE;
                mmi_camera_mf_stop();
                gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            }
            else
            {
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
                gui_cancel_timer(mmi_camera_mf_backward_continue);
            }
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

            break;
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
    }

}
#endif /* defined(__CAMERA_FEATURE_ZOOM__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_effect_hotkey_press
 * DESCRIPTION
 *  effect setting hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_EFFECT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_effect_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_effect_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_EFFECT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_effect_change
 * DESCRIPTION
 *  chage effect
 * PARAMETERS
 *  is_next     [IN]        Change effect to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_EFFECT__
static void mmi_camera_preview_effect_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    BOOL is_custom_fx = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.effect < CAMERA_SETTING_EFFECT_COUNT - 1)
        {
            g_camera_cntx.setting.effect++;
        }
        else
        {
            g_camera_cntx.setting.effect = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.effect >= 1)
        {
            g_camera_cntx.setting.effect--;
        }
        else
        {
            g_camera_cntx.setting.effect = CAMERA_SETTING_EFFECT_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_EFFECT_SETTING));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.effect + STR_ID_CAMERA_EFFECT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    mmi_camera_preview_draw_osd();

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_1)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL]);
        mdi_camera_update_para_brightness(g_camera_cntx.setting.fx_brightness[0]);
        mdi_camera_update_para_saturation(g_camera_cntx.setting.fx_saturation[0]);
        mdi_camera_update_para_contrast(g_camera_cntx.setting.fx_contrast[0]);
        mdi_camera_update_para_hue(g_camera_cntx.setting.fx_hue[0]);

        is_custom_fx = TRUE;
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ */ 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_2)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL]);
        mdi_camera_update_para_brightness(g_camera_cntx.setting.fx_brightness[1]);
        mdi_camera_update_para_saturation(g_camera_cntx.setting.fx_saturation[1]);
        mdi_camera_update_para_contrast(g_camera_cntx.setting.fx_contrast[1]);
        mdi_camera_update_para_hue(g_camera_cntx.setting.fx_hue[1]);

        is_custom_fx = TRUE;
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ */ 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_3)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL]);
        mdi_camera_update_para_brightness(g_camera_cntx.setting.fx_brightness[2]);
        mdi_camera_update_para_saturation(g_camera_cntx.setting.fx_saturation[2]);
        mdi_camera_update_para_contrast(g_camera_cntx.setting.fx_contrast[2]);
        mdi_camera_update_para_hue(g_camera_cntx.setting.fx_hue[2]);

        is_custom_fx = TRUE;
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ */ 

    if (!is_custom_fx)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[g_camera_cntx.setting.effect]);
        mdi_camera_update_para_brightness(128);
        mdi_camera_update_para_saturation(128);
        mdi_camera_update_para_contrast(128);
        mdi_camera_update_para_hue(0);
    }

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_FEATURE_EFFECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_wb_hotkey_press
 * DESCRIPTION
 *  wb hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_WB__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_wb_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_wb_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_WB__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_wb_change
 * DESCRIPTION
 *  change wb
 * PARAMETERS
 *  is_next     [IN]        Change wb to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_WB__
static void mmi_camera_preview_wb_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.wb < CAMERA_SETTING_WB_COUNT - 1)
        {
            g_camera_cntx.setting.wb++;
        }
        else
        {
            g_camera_cntx.setting.wb = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.wb >= 1)
        {
            g_camera_cntx.setting.wb--;
        }
        else
        {
            g_camera_cntx.setting.wb = CAMERA_SETTING_WB_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_WB));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.wb + STR_ID_CAMERA_WB_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    mdi_camera_update_para_wb(camera_wb_command_map[g_camera_cntx.setting.wb]);

    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_FEATURE_WB__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_led_highlight_hotkey_press
 * DESCRIPTION
 *  led highlight hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_LED_HIGHLIGHT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_led_highlight_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_led_highlight_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_LED_HIGHLIGHT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_led_highlight_change
 * DESCRIPTION
 *  led highlight change
 * PARAMETERS
 *  is_next     [IN]        Change led highlight to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
static void mmi_camera_preview_led_highlight_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.led_highlight < CAMERA_SETTING_LED_HIGHLIGHT_COUNT - 1)
        {
            g_camera_cntx.setting.led_highlight++;
        }
        else
        {
            g_camera_cntx.setting.led_highlight = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.led_highlight >= 1)
        {
            g_camera_cntx.setting.led_highlight--;
        }
        else
        {
            g_camera_cntx.setting.led_highlight = CAMERA_SETTING_LED_HIGHLIGHT_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_LED_HIGHLIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.led_highlight + STR_ID_CAMERA_LED_HIGHLIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    /* trun on/off led highlight */
    mmi_camera_turn_on_preview_led_highlight();

}
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_flash_hotkey_press
 * DESCRIPTION
 *  flash hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_FLASH__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_flash_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_flash_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_FLASH__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_flash_change
 * DESCRIPTION
 *  flash change
 * PARAMETERS
 *  is_next     [IN]        Change led highlight to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_FLASH__
static void mmi_camera_preview_flash_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.flash < CAMERA_SETTING_FLASH_COUNT - 1)
        {
            g_camera_cntx.setting.flash++;
        }
        else
        {
            g_camera_cntx.setting.flash = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.flash >= 1)
        {
            g_camera_cntx.setting.flash--;
        }
        else
        {
            g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_FLASH));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.flash + STR_ID_CAMERA_FLASH_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    #ifdef __CAMERA_FEATURE_XENON_FLASH__
        if (g_camera_cntx.setting.flash == CAMERA_SETTING_FLASH_OFF)
            g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
    #endif
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_flash(camera_flash_command_map[g_camera_cntx.setting.flash]);

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_FEATURE_FLASH__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_night_hotkey_press
 * DESCRIPTION
 *  night hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_NIGHT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_night_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_night_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_NIGHT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_night_change
 * DESCRIPTION
 *  night change
 * PARAMETERS
 *  is_next     [IN]        Change night to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_NIGHT__
static void mmi_camera_preview_night_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.night < CAMERA_SETTING_NIGHT_COUNT - 1)
        {
            g_camera_cntx.setting.night++;
        }
        else
        {
            g_camera_cntx.setting.night = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.night >= 1)
        {
            g_camera_cntx.setting.night--;
        }
        else
        {
            g_camera_cntx.setting.night = CAMERA_SETTING_NIGHT_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_NIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.night + STR_ID_CAMERA_NIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    mdi_camera_update_para_night(g_camera_cntx.setting.night);

}
#endif /* __CAMERA_FEATURE_NIGHT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_image_size_hotkey_press
 * DESCRIPTION
 *  image size hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_image_size_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_image_size_change(TRUE);
}
#endif /* !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_image_size_change
 * DESCRIPTION
 *  image size change
 * PARAMETERS
 *  is_next     [IN]        Change image size to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_image_size_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    S32 prev_preview_width;
    S32 prev_preview_height;
    BOOL prev_is_fullscreen;
    BOOL prev_is_tileshot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change size */
    if (is_next)
    {
        if (g_camera_cntx.setting.image_size < CAMERA_SETTING_IMAGE_SIZE_COUNT - 1)
        {
            g_camera_cntx.setting.image_size++;
        }
        else
        {
            g_camera_cntx.setting.image_size = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.image_size >= 1)
        {
            g_camera_cntx.setting.image_size--;
        }
        else
        {
            g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_COUNT - 1;
        }
    }


#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    if (g_camera_cntx.is_tileshot)
    {
        g_camera_cntx.setting.cont_shot = CAMERA_SETTING_CONT_SHOT_OFF;
        g_camera_cntx.tile_cur_num = 0;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* disable burst shot if size can not support */
    if ((g_camera_cntx.setting.image_size != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX) &&
        (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST))
    {
        g_camera_cntx.setting.cont_shot = CAMERA_DEFAULT_SETTING_CONT_SHOT;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    /* backup previous */
    prev_preview_width = g_camera_cntx.preview_width;
    prev_preview_height = g_camera_cntx.preview_height;
    prev_is_fullscreen = g_camera_cntx.is_fullscreen;
    prev_is_tileshot = g_camera_cntx.is_tileshot;

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_IMAGE_SIZE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.image_size_str_id[g_camera_cntx.setting.image_size])),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    /* update parameters */
    mmi_camera_preview_update_capture_size();

    if ((prev_preview_width != g_camera_cntx.preview_width) ||
        (prev_preview_height != g_camera_cntx.preview_height) ||
        (prev_is_fullscreen != g_camera_cntx.is_fullscreen) ||
        (g_camera_cntx.setting.zoom_idx != CAMERA_DEFAULT_SETTING_ZOOM_IDX))
    {
        /* since preview para is changed, stop and restart preview */
        mmi_camera_preview_stop();

        /* restore zoom setting */
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;

    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (prev_is_fullscreen != g_camera_cntx.is_fullscreen)
        {
            if (g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0)
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
            }
            else
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
            }
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
        }
    #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

        /* set blt */
        mmi_camera_preview_set_blt_layer(FALSE);

        /* update add frame */
    #ifdef __CAMERA_FEATURE_ADD_FRAME__
        if (g_camera_cntx.add_frame_layer_handle == GDI_LAYER_EMPTY_HANDLE)
            mmi_camera_create_add_frame_layer();
    #endif 

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        mmi_camera_check_osd_orientation();

        /* update functions of up/down/left/right key */
        mmi_camera_preview_set_key_hdlr();
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

        /* clear background color */
        mmi_camera_preview_clear_background();
        mmi_camera_preview_draw_osd();

    #if defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__)

        if (!mdi_tvout_is_enable())
        {
            /* tvout not enable */
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else if (g_camera_cntx.is_fullscreen)
        {
            /* tv-out is enable and is vertical display */
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else
        {
            gdi_lcd_set_rotate_by_layer(FALSE);
        }

        if (mdi_tvout_is_enable())
        {
            /* when HORIZONTAL is enable, the fullscreen means vertical screen */
            if (g_camera_cntx.is_fullscreen)
            {
                mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
            }
            else
            {
                mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
            }
        }
    #endif /* defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__) */ 

        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
        mmi_camera_preview_free_preview_resource();
        {
            S32 offset_x = 0;
            S32 offset_y = 0;

        #ifdef HORIZONTAL_CAMERA
            offset_y = (LCD_WIDTH - g_camera_cntx.preview_height) >> 1;
        #else 
            offset_y = (LCD_HEIGHT - g_camera_cntx.preview_height) >> 1;
        #endif 

            mmi_camera_preview_create_preview_resource(
                offset_x,
                offset_y,
                g_camera_cntx.preview_width,
                g_camera_cntx.preview_height,
                g_camera_cntx.lcm_rotate);
        }

        /* update color idx frame */
    #ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
        if ((g_camera_cntx.setting.add_frame_color_idx != CAMERA_SETTING_ADD_FRAME_OFF)
            && (g_camera_cntx.is_fullscreen == FALSE) && (g_camera_cntx.is_tileshot == FALSE))
        {
            mmi_camera_draw_add_frame_color_idx();
        }
    #endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

        /* set blt layer for previwing */
        mmi_camera_preview_set_blt_layer(TRUE);

        mmi_camera_preview_start();

        /* check if preview success */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }

    }
    else
    {
        mdi_camera_update_para_zoom(mmi_camera_preview_get_zoom_factor());
        mdi_camera_update_para_image_size(g_camera_cntx.image_width, g_camera_cntx.image_height);

        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_image_qty_hotkey_press
 * DESCRIPTION
 *  imaeg qty hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_image_qty_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_image_qty_change(TRUE);
}
#endif /* !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_image_qty_change
 * DESCRIPTION
 *  image qty hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change image qty to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_image_qty_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.image_qty < CAMERA_SETTING_IMAGE_QTY_COUNT - 1)
        {
            g_camera_cntx.setting.image_qty++;
        }
        else
        {
            g_camera_cntx.setting.image_qty = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.image_qty >= 1)
        {
            g_camera_cntx.setting.image_qty--;
        }
        else
        {
            g_camera_cntx.setting.image_qty = CAMERA_SETTING_IMAGE_QTY_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_IMAGE_QTY));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.image_qty + STR_ID_CAMERA_IMAGE_QTY_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_image_qty(camera_image_qty_command_map[g_camera_cntx.setting.image_qty]);

    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_cont_shot_hotkey_press
 * DESCRIPTION
 *  cont shot hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_cont_shot_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_cont_shot_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_cont_shot_change
 * DESCRIPTION
 *  cont shot change
 * PARAMETERS
 *  is_next     [IN]        Change cont shot to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT__
static void mmi_camera_preview_cont_shot_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    BOOL need_restart_preview;
    BOOL need_change_capture_size = FALSE;
    S32 prev_preview_width;
    S32 prev_preview_height;

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    BOOL need_restore_image_size;
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    need_restart_preview = FALSE;

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* inti var */
    need_restore_image_size = FALSE;

    /* leaving burst shot */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        need_restore_image_size = TRUE;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* Before change is tile shot */
    if (g_camera_cntx.is_tileshot)
    {
        g_camera_cntx.setting.image_size = g_camera_cntx.previous_image_size;
        need_change_capture_size = TRUE;
        need_restart_preview = TRUE;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    if (is_next)
    {
        if (g_camera_cntx.setting.cont_shot < CAMERA_SETTING_CONT_SHOT_COUNT - 1)
        {
            g_camera_cntx.setting.cont_shot++;
        }
        else
        {
            g_camera_cntx.setting.cont_shot = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.cont_shot >= 1)
        {
            g_camera_cntx.setting.cont_shot--;
        }
        else
        {
            g_camera_cntx.setting.cont_shot = CAMERA_SETTING_CONT_SHOT_COUNT - 1;
        }
    }

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* AFTER change is tile shot */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_TILE)
    {
        g_camera_cntx.is_tileshot = TRUE;
        g_camera_cntx.tile_cur_num = 0;
        g_camera_cntx.previous_image_size = g_camera_cntx.setting.image_size;
        g_camera_cntx.setting.image_size = CAMERA_FEATURE_CONT_SHOT_TILE_IMAGE_IDX;
        need_change_capture_size = TRUE;
        need_restart_preview = TRUE;
    }
    else
    {
        g_camera_cntx.is_tileshot = FALSE;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* check change out from burst need to change image and preview size */
    if (need_restore_image_size)
    {
        if (g_camera_cntx.image_size_before_burst != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX)
        {
            /* restore preview */
            g_camera_cntx.setting.image_size = g_camera_cntx.image_size_before_burst;
            need_change_capture_size = TRUE;
        }
    }

    /* check if change to burst need to change image and preview size */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        /* store image size before enter burst shot */
        g_camera_cntx.image_size_before_burst = g_camera_cntx.setting.image_size;

        /* if not correct image size, change to it */
        if (g_camera_cntx.setting.image_size != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX)
        {
            g_camera_cntx.setting.image_size = CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX;
            need_change_capture_size = TRUE;
        }
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    if (need_change_capture_size)
    {
        prev_preview_width = g_camera_cntx.preview_width;
        prev_preview_height = g_camera_cntx.preview_height;

        mmi_camera_preview_update_capture_size();
        mdi_camera_update_para_image_size(g_camera_cntx.image_width, g_camera_cntx.image_height);

        if ((prev_preview_width != g_camera_cntx.preview_width) ||
            (prev_preview_height != g_camera_cntx.preview_height) ||
            (g_camera_cntx.setting.zoom_idx != CAMERA_DEFAULT_SETTING_ZOOM_IDX))
        {
            need_restart_preview = TRUE;
        }

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.previous_osd_rotate == CAMERA_DISPLAY_ROTATE_RESET)
        {
            need_restart_preview = TRUE;
        }
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_CONT_SHOT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.cont_shot + STR_ID_CAMERA_CONT_SHOT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 


    if (need_restart_preview)
    {
        /* since preview para is changed, stop and restart preview */
        mmi_camera_preview_stop();

#if (defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)) && defined(__CAMERA_OSD_HORIZONTAL__)
    #if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
        if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
        {
            /* not fullscreen(lcm size) but using single layer, change to using multi osd */
            if (g_camera_cntx.is_fullscreen == FALSE && g_camera_cntx.is_single_osd_layer == TRUE)
            {
                g_camera_cntx.is_single_osd_layer = FALSE;

                mmi_camera_free_osd_layer();
                mmi_camera_create_osd_layer();
                /* update osd layers */
                g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            }
        } 
        else
    #endif
    #if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__)
        if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_TILE)
        {
            /* tileshot and using multi osd, change to use single osd layer */
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                g_camera_cntx.is_single_osd_layer = TRUE;

                mmi_camera_free_osd_layer();
                mmi_camera_create_osd_layer();
                /* update osd layers */
                g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            }
        }
        else
    #endif
        {
            /* full screen and using multi-osd but with add_frame, change to using single osd */
            if (g_camera_cntx.is_fullscreen == TRUE && g_camera_cntx.is_single_osd_layer == FALSE &&
                g_camera_cntx.setting.add_frame != 0)
            {
                g_camera_cntx.is_single_osd_layer = TRUE;

                mmi_camera_free_osd_layer();
                mmi_camera_create_osd_layer();
                /* update osd layers */
                g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;

            }
        }
#endif /* (defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)) && defined(__CAMERA_OSD_HORIZONTAL__) */ 


    /* check if need to update osd orienation */
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.previous_osd_rotate == CAMERA_DISPLAY_ROTATE_RESET)
        {
            mmi_camera_check_osd_orientation();
            mmi_camera_preview_set_key_hdlr();
        }
    #endif

        /* restore zoom setting */
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;

        /* update add frame */
    #ifdef __CAMERA_FEATURE_ADD_FRAME__
        mmi_camera_create_add_frame_layer();
    #endif 

        /* update color idx frame */
    #ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
        if ((g_camera_cntx.setting.add_frame_color_idx != CAMERA_SETTING_ADD_FRAME_OFF)
            && (g_camera_cntx.is_fullscreen == FALSE) && (g_camera_cntx.is_tileshot == FALSE))
        {
            mmi_camera_draw_add_frame_color_idx();
        }
    #endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

        /* set blt */
        mmi_camera_preview_set_blt_layer(FALSE);

        /* clear background color */
        mmi_camera_preview_clear_background();

    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        /* tile result back groud */
        if (g_camera_cntx.is_tileshot)
        {
            mmi_camera_init_tileshot_layer();
        }
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

        mmi_camera_preview_draw_osd();

    #if defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__)
        if (!mdi_tvout_is_enable())
        {
            /* tvout not enable */
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else if (g_camera_cntx.is_fullscreen)
        {
            /* tv-out is enable and is vertical display */
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else
        {
            gdi_lcd_set_rotate_by_layer(FALSE);
        }

        if (mdi_tvout_is_enable())
        {
            /* when HORIZONTAL is enable, the fullscreen means vertical screen */
            if (g_camera_cntx.is_fullscreen)
            {
                mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
            }
            else
            {
                mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
            }
        }
    #endif /* defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__) */ 

        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

        {
            S32 offset_x = 0;
            S32 offset_y = 0;

            mmi_camera_preview_free_preview_resource();
        #ifdef HORIZONTAL_CAMERA
            offset_y = (LCD_WIDTH - g_camera_cntx.preview_height) >> 1;
        #else 
            offset_y = (LCD_HEIGHT - g_camera_cntx.preview_height) >> 1;
        #endif 
            mmi_camera_preview_create_preview_resource(
                offset_x,
                offset_y,
                g_camera_cntx.preview_width,
                g_camera_cntx.preview_height,
                g_camera_cntx.lcm_rotate);
        }

        /* set blt layer for previwing */
        mmi_camera_preview_set_blt_layer(TRUE);

        mmi_camera_preview_start();

        /* check if preview success */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
            return;
        }
    }
    else
    {
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

}
#endif /* __CAMERA_FEATURE_CONT_SHOT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_delay_timer_hotkey_press
 * DESCRIPTION
 *  delay_timer hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_DELAY_TIMER__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_delay_timer_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_delay_timer_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_DELAY_TIMER__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_delay_timer_change
 * DESCRIPTION
 *  delay_timer change
 * PARAMETERS
 *  is_next     [IN]        Change delay timer to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_DELAY_TIMER__
static void mmi_camera_preview_delay_timer_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.delay_timer < CAMERA_SETTING_DELAY_TIMER_COUNT - 1)
        {
            g_camera_cntx.setting.delay_timer++;
        }
        else
        {
            g_camera_cntx.setting.delay_timer = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.delay_timer >= 1)
        {
            g_camera_cntx.setting.delay_timer--;
        }
        else
        {
            g_camera_cntx.setting.delay_timer = CAMERA_SETTING_DELAY_TIMER_COUNT - 1;
        }
    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_DELAY_TIMER));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.delay_timer + STR_ID_CAMERA_DELAY_TIMER_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */ 

#ifdef __CAMERA_DSC_MODE__

#if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined (__CAMERA_DSC_MODE_APERTURE_PRI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_init_advanced_dsc_mode
 * DESCRIPTION
 *  shot mode initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_init_advanced_dsc_mode(void)
{
#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        shutter_info_struct tv_data;
        S32 i;
        S8 buffer[30];  /* for xxxx/xxxx */
        kal_bool *tmp_pointer;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        g_camera_dsc_mode_cntx.shutter_pri_count = 0;

        if (g_camera_cntx.setting.banding == CAMERA_SETTING_BANDING_60HZ)
        {
            tmp_pointer = shutter_pri_60hz_info;
        }
        else if (g_camera_cntx.setting.banding == CAMERA_SETTING_BANDING_50HZ)
        {
            tmp_pointer = shutter_pri_50hz_info;
        }
        else
        {
            tmp_pointer = shutter_pri_60hz_info;
        }

        for (i = 0; i < TV_NO; i++)
        {
            if (tmp_pointer[i] == TRUE)
            {
                get_shutter_priority_info(i, &tv_data);
                sprintf(buffer, "1/%d", (U16) tv_data.prtinfo / 10);
                mmi_asc_to_ucs2(
                    (PS8) g_camera_dsc_mode_cntx.shutter_pri_str[g_camera_dsc_mode_cntx.shutter_pri_count],
                    (PS8) buffer);
                g_camera_dsc_mode_cntx.shutter_pri_value[g_camera_dsc_mode_cntx.shutter_pri_count] = i;
                g_camera_dsc_mode_cntx.shutter_pri_count++;
            }
        }
    }
#endif /* __CAMERA_DSC_MODE_SHUTTER_PRI__ */ 

#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
    {
        aperture_info_struct av_data;
        S32 i;
        S8 buffer[30];

        g_camera_dsc_mode_cntx.aperture_pri_count = 0;

        for (i = 0; i < AV_NO; i++)
        {
            if (aperture_pri_info[i] == TRUE)
            {
                get_aperture_priority_info(i, &av_data);
                sprintf(buffer, "%f", (float)av_data.prtinfo / 10);
                mmi_asc_to_ucs2(
                    (PS8) g_camera_dsc_mode_cntx.aperture_pri_str[g_camera_dsc_mode_cntx.aperture_pri_count],
                    (PS8) buffer);
                g_camera_dsc_mode_cntx.aperture_pri_value[g_camera_dsc_mode_cntx.aperture_pri_count] = i;
                g_camera_dsc_mode_cntx.aperture_pri_count++;
            }
        }
    }
#endif /* __CAMERA_DSC_MODE_APERTURE_PRI__ */ 
}
#endif /*defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined (__CAMERA_DSC_MODE_APERTURE_PRI__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_dsc_mode_hotkey_press
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_dsc_mode_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_dsc_mode_change(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_dsc_mode_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_dsc_mode_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.dsc_mode < CAMERA_SETTING_DSC_MODE_COUNT - 1)
        {
            g_camera_cntx.setting.dsc_mode++;
        }
        else
        {
            g_camera_cntx.setting.dsc_mode = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.dsc_mode >= 1)
        {
            g_camera_cntx.setting.dsc_mode--;
        }
        else
        {
            g_camera_cntx.setting.dsc_mode = CAMERA_SETTING_DSC_MODE_COUNT - 1;
        }
    }


    /* night mode: should also set night_mode for DRV use */
#ifdef __CAMERA_DSC_MODE_NIGHT__
    if(g_camera_cntx.setting.dsc_mode == CAMERA_SETTING_DSC_MODE_NIGHT)
        g_camera_cntx.setting.night = 1;
    else
        g_camera_cntx.setting.night = 0;
#endif 

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_DSC_MODE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_dsc_mode(camera_dsc_mode_command_map[g_camera_cntx.setting.dsc_mode]);

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.dsc_mode + STR_ID_CAMERA_DSC_MODE_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}
#endif /* __CAMERA_DSC_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_iso_hotkey_press
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* night mode conflict with iso */
    #ifdef __CAMERA_DSC_MODE_NIGHT__
    if (g_camera_cntx.setting.dsc_mode == CAMERA_SETTING_DSC_MODE_NIGHT)
        return;
    #endif
    mmi_camera_preview_iso_change(TRUE);
}
#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_iso_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.iso < CAMERA_SETTING_ISO_COUNT - 1)
        {
            g_camera_cntx.setting.iso++;
        }
        else
        {
            g_camera_cntx.setting.iso = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.iso >= 1)
        {
            g_camera_cntx.setting.iso--;
        }
        else
        {
            g_camera_cntx.setting.iso = CAMERA_SETTING_ISO_COUNT - 1;
        }
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_ISO));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_iso(camera_iso_command_map[g_camera_cntx.setting.iso]);

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.iso + STR_ID_CAMERA_ISO_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}
#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_ae_meter_hotkey_press
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_ae_meter_change(TRUE);
}
#endif /* __CAMERA_FEATURE_AE_METER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_ae_meter_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.ae_meter < CAMERA_SETTING_AE_METER_COUNT - 1)
        {
            g_camera_cntx.setting.ae_meter++;
        }
        else
        {
            g_camera_cntx.setting.ae_meter = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.ae_meter >= 1)
        {
            g_camera_cntx.setting.ae_meter--;
        }
        else
        {
            g_camera_cntx.setting.ae_meter = CAMERA_SETTING_AE_METER_COUNT - 1;
        }
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_AE_METER));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_ae_meter(camera_ae_meter_command_map[g_camera_cntx.setting.ae_meter]);

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.ae_meter + STR_ID_CAMERA_AE_METER_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}
#endif /* __CAMERA_FEATURE_AE_METER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_af_mode_hotkey_press
 * DESCRIPTION
 *  AF mode hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_AUTOFOCUS_MODE__)
static void mmi_camera_preview_af_mode_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_af_mode_change(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_af_mode_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_af_mode_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.af_mode + 1 < CAMERA_SETTING_AUTOFOCUS_MODE_COUNT)
        {
            g_camera_cntx.setting.af_mode++;
        }
        else
        {
            g_camera_cntx.setting.af_mode = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.af_mode >= 1)
        {
            g_camera_cntx.setting.af_mode--;
        }
        else
        {
            g_camera_cntx.setting.af_mode = CAMERA_SETTING_AUTOFOCUS_MODE_COUNT - 1;
        }
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_AUTOFOCUS_MODE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_af_mode(camera_autofocus_mode_command_map[g_camera_cntx.setting.af_mode]);

#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    if (g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
    {
        mdi_camera_get_focus_steps(&(g_camera_cntx.mf_level_cnt), &(g_camera_cntx.mf_level_idx));
    }
#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.af_mode + STR_ID_CAMERA_AUTOFOCUS_MODE_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

#endif /* defined(__CAMERA_AUTOFOCUS_MODE__) */ /* __CAMERA_FEATURE_STORAGE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_af_meter_hotkey_press
 * DESCRIPTION
 *  AF metering hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_AUTOFOCUS_METERING__)
static void mmi_camera_preview_af_meter_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_af_meter_change(TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_af_meter_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_af_meter_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.af_meter + 1 < CAMERA_SETTING_AUTOFOCUS_COUNT)
        {
            g_camera_cntx.setting.af_meter++;
        }
        else
        {
            g_camera_cntx.setting.af_meter = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.af_meter >= 1)
        {
            g_camera_cntx.setting.af_meter--;
        }
        else
        {
            g_camera_cntx.setting.af_meter = CAMERA_SETTING_AUTOFOCUS_COUNT - 1;
        }
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_AUTOFOCUS_METERING));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_af_metering(camera_autofocus_command_map[g_camera_cntx.setting.af_meter]);

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.af_meter + STR_ID_CAMERA_AUTOFOCUS_START + 1)),
        HINT_POPUP_FADE_TIME);
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

#endif /* defined(__CAMERA_AUTOFOCUS_METERING__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_storage_hotkey_press
 * DESCRIPTION
 *  delay_timer hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_STORAGE__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__)
static void mmi_camera_preview_storage_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_storage_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_STORAGE__) && !defined(__CAMERA_FEATURE_ICONBAR_PANEL__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_storage_change
 * DESCRIPTION
 *  storage change
 * PARAMETERS
 *  is_next     [IN]        Change storage to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_STORAGE__
static void mmi_camera_preview_storage_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U16 cur_storage;
    S32 create_result;
    U8 total_num;
    U8 highlighted_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmgr_get_exist_storage_inline_list((S8)g_imgview_context.storage,&total_num,&(g_imgview_context.drv_inline_list_p),&highlighted_idx);

    if (total_num > 1) g_imgview_context.is_storage_path_changed = TRUE;
    else g_imgview_context.is_storage_path_changed = FALSE;

    if (is_next)
    {
        if (highlighted_idx < total_num - 1)
        {
            highlighted_idx++;
        }
        else
        {
            highlighted_idx= 0;
        }
    }
    else
    {
        if (highlighted_idx>= 1)
        {
            highlighted_idx--;
        }
        else
        {
            highlighted_idx= total_num-1;
        }

    }

#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_STORAGE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) (((U8**)g_imgview_context.drv_inline_list_p)[highlighted_idx]),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    mmi_fmgr_get_drive_letter_by_inline_index(highlighted_idx,(S8*)&g_imgview_context.storage);


    /* storage changed */
    if (g_imgview_context.is_storage_path_changed)
    {
        /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
        cur_storage = g_imgview_context.storage;

        if (mmi_camera_check_and_restore_valid_drv())
        {
            /* drv is valid, create directory */
            mmi_imgview_get_storage_file_path(g_camera_cntx.storage_filepath);
            create_result = mmi_imgview_create_file_dir(g_camera_cntx.storage_filepath);

            /* create directory failed */
            if (create_result == FS_WRITE_PROTECTION)
            {
                g_camera_cntx.last_error = CAMERA_ERR_WRITE_PROTECT;

                /* has error - restore to phone */
                g_imgview_context.storage = MMI_PUBLIC_DRV;
            }
            else if (create_result == FS_DISK_FULL)
            {
                if (cur_storage == (U16) MMI_PUBLIC_DRV)
                {
                    g_camera_cntx.last_error = CAMERA_ERR_PHONE_DISK_FULL;
                }
                else
                {
                    /* storage is card */
                    g_camera_cntx.last_error = CAMERA_ERR_CARD_DISK_FULL;

                    /* has error - restore to phone */
                    g_imgview_context.storage = MMI_PUBLIC_DRV;
                }
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                if (cur_storage == (U16) MMI_PUBLIC_DRV)
                {
                    g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
                }
                else
                {
                    /* storage is card */
                    g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;

                    /* has error - restore to phone */
                    g_imgview_context.storage = MMI_PUBLIC_DRV;
                }
            }

        }
        else
        {
            /* drv no valid, means card is plugged out (or phone FAT corrupted) */

            /* if storage before restoration is already in phone, means FAT is corrupted */
            if (cur_storage == (U16) MMI_PUBLIC_DRV)
            {
                g_camera_cntx.last_error = CAMERA_ERR_CORRUPT_FAT;
            }
            else
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
            }
        }

        /* check if preview success */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }

    }

}
#endif /* __CAMERA_FEATURE_STORAGE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_draw_add_frame
 * DESCRIPTION
 *  exit preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_draw_add_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    /* if frame is set and preview size is LCD size, draw frame */
    if ((g_camera_cntx.is_fullscreen) && (g_camera_cntx.setting.add_frame != CAMERA_SETTING_ADD_FRAME_OFF) ||
        (g_camera_cntx.setting.add_frame_tileshot != CAMERA_SETTING_ADD_FRAME_OFF))
    {
        if (g_camera_cntx.is_tileshot)
        {
            image_idx = (U16) (IMG_ID_CAMERA_TILE_ADD_FRAME_START + g_camera_cntx.setting.add_frame_tileshot);
        }
        else
        {
            image_idx = (U16) (IMG_ID_CAMERA_ADD_FRAME_START + g_camera_cntx.setting.add_frame);
        }

        gdi_image_draw_id(0, 0, (U16) (image_idx));

    }

    gdi_layer_pop_and_restore_active();
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_change_frame_down
 * DESCRIPTION
 *  change add frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_preview_change_frame_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_fullscreen)
    {
        if (g_camera_cntx.is_tileshot == TRUE)
        {
            prev_add_frame = g_camera_cntx.setting.add_frame_tileshot;

            if (g_camera_cntx.setting.add_frame_tileshot >= CAMERA_SETTING_ADD_FRAME_COUNT - 1)
            {
                g_camera_cntx.setting.add_frame_tileshot = 0;
            }
            else
            {
                g_camera_cntx.setting.add_frame_tileshot++;
            }
        }
        else
        {
            prev_add_frame = g_camera_cntx.setting.add_frame;

            if (g_camera_cntx.setting.add_frame >= CAMERA_SETTING_ADD_FRAME_COUNT - 1)
            {
                g_camera_cntx.setting.add_frame = 0;
            }
            else
            {
                g_camera_cntx.setting.add_frame++;
            }
        }

        mmi_camera_preview_stop();

        g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;

    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (g_camera_cntx.setting.add_frame == 0 || prev_add_frame == 0)
        {
            if (g_camera_cntx.setting.add_frame == 0)
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
            }
            else
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
            }

            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();

        #if defined(__CAMERA_OSD_HORIZONTAL__)
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            mmi_camera_check_osd_orientation();
        #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

            /* update blt layers */
            mmi_camera_preview_set_blt_layer(TRUE);
        }
    #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

        if (prev_add_frame == 0)
        {
            mmi_camera_create_add_frame_layer();
            mmi_camera_draw_add_frame();
        }
        else if (g_camera_cntx.setting.add_frame == 0)
            mmi_camera_free_add_frame_layer();
        else
            mmi_camera_draw_add_frame();

        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        mmi_camera_preview_draw_osd();

        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

        mmi_camera_preview_start();

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }

    }
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    else
    {
        if (g_camera_cntx.setting.add_frame_color_idx >= CAMERA_ADD_FRAME_COLOR_IDX_ITEM_COUNT - 1)
        {
            g_camera_cntx.setting.add_frame_color_idx = 0;
        }
        else
        {
            g_camera_cntx.setting.add_frame_color_idx++;
        }

        mdi_camera_preview_stop();
        mmi_camera_draw_add_frame_color_idx();
        mmi_camera_preview_start();
    }
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_change_frame_up
 * DESCRIPTION
 *  change add frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_preview_change_frame_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_fullscreen)
    {
        if (g_camera_cntx.is_tileshot == TRUE)
        {
            prev_add_frame = g_camera_cntx.setting.add_frame_tileshot;

            if (g_camera_cntx.setting.add_frame_tileshot == 0)
            {
                g_camera_cntx.setting.add_frame_tileshot = CAMERA_SETTING_ADD_FRAME_COUNT - 1;
            }
            else
            {
                g_camera_cntx.setting.add_frame_tileshot--;
            }
        }
        else
        {
            prev_add_frame = g_camera_cntx.setting.add_frame;

            if (g_camera_cntx.setting.add_frame == 0)
            {
                g_camera_cntx.setting.add_frame = CAMERA_SETTING_ADD_FRAME_COUNT - 1;
            }
            else
            {
                g_camera_cntx.setting.add_frame--;
            }
        }

        mmi_camera_preview_stop();

        g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;

    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (g_camera_cntx.setting.add_frame == 0 || prev_add_frame == 0)
        {
            if (g_camera_cntx.setting.add_frame == 0)
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
            }
            else
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
            }

            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();

        #if defined(__CAMERA_OSD_HORIZONTAL__)
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            mmi_camera_check_osd_orientation();
        #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

            /* update blt layers */
            mmi_camera_preview_set_blt_layer(TRUE);
        }
    #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

        if (prev_add_frame == 0)
        {
            mmi_camera_create_add_frame_layer();
            mmi_camera_draw_add_frame();
        }
        else if (g_camera_cntx.setting.add_frame == 0)
            mmi_camera_free_add_frame_layer();
        else
            mmi_camera_draw_add_frame();
            
        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

        mmi_camera_preview_start();

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }
    }
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    else
    {
        if (g_camera_cntx.setting.add_frame_color_idx == 0)
        {
            g_camera_cntx.setting.add_frame_color_idx = CAMERA_ADD_FRAME_COLOR_IDX_ITEM_COUNT - 1;
        }
        else
        {
            g_camera_cntx.setting.add_frame_color_idx--;
        }

        mdi_camera_preview_stop();
        mmi_camera_draw_add_frame_color_idx();
        mmi_camera_preview_start();

    }
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_lsk_press
 * DESCRIPTION
 *  previwe lsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = TRUE;

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_lsk_release
 * DESCRIPTION
 *  previwe lsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = FALSE;

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    mmi_camera_entry_option_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_rsk_press
 * DESCRIPTION
 *  previwe rsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = TRUE;

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_preview_rsk_release
 * DESCRIPTION
 *  previwe rsk released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_preview_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    S32 offset_x;
    S32 offset_y;
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = FALSE;

    mmi_camera_preview_draw_osd();

    /* for External Request */
    if (g_camera_cntx.is_external_request == TRUE)
    {
        g_camera_cntx.setting.cont_shot = g_camera_cntx.contshot_backup;
        g_camera_cntx.is_external_request = FALSE;
    }


    if ((g_camera_cntx.app_state == CAMERA_STATE_PREVIEW) &&
        (g_camera_cntx.is_tileshot) && (g_camera_cntx.tile_cur_num != 0))
    {
    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        mmi_camera_preview_stop();

        /* if is tile shot, and alreay captured tile image, clear it and re-capture */
        offset_x = (g_camera_cntx.tile_cur_num % 2) * (g_camera_cntx.osd_UI_device_width >> 1);
        offset_y = (g_camera_cntx.tile_cur_num / 2) * (g_camera_cntx.osd_UI_device_height >> 1);

        mmi_camera_preview_set_blt_layer(FALSE);

        gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);
        gdi_draw_solid_rect(
            offset_x,
            offset_y,
            offset_x + (g_camera_cntx.osd_UI_device_width >> 1) - 1,
            offset_y + (g_camera_cntx.osd_UI_device_height >> 1) - 1,
            GDI_COLOR_BLACK);
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

        gdi_layer_pop_and_restore_active();

        g_camera_cntx.tile_cur_num--;

        if (g_camera_cntx.tile_cur_num == 0)
        {
            /* redraw OSD, this will change RSK from Clear->Back when clear to tile's 1st image */
            mmi_camera_preview_draw_osd();
        }

        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
        mmi_camera_preview_set_blt_layer(TRUE);
        /* /gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width-1, g_camera_cntx.base_UI_device_height-1); */
        mmi_camera_preview_start();

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }

        return;
    #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
        MMI_ASSERT(0);
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    }
    else
    {
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

    /* camera with only 23key, will use RSK to capture */
#ifdef __MMI_CAMERA_23KEY__
    mmi_camera_capture_button_press();
#else 
    GoBackHistory();
#endif 
}

/*****************************************************************************
*
*  Main LCD Countdown State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_countdown_state
 * DESCRIPTION
 *  entry count down state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_entry_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_LONG_PRESS);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }


    /* init countdown para */
    switch (g_camera_cntx.setting.delay_timer)
    {
        case CAMERA_SETTING_DELAY_TIMER_1:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_1_DURATION * 1000;
        }
            break;

        case CAMERA_SETTING_DELAY_TIMER_2:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_2_DURATION * 1000;
        }
            break;

        case CAMERA_SETTING_DELAY_TIMER_3:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_3_DURATION * 1000;
        }
            break;

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;
    }

    #ifdef __COUNTDOWN_USING_MMA__
    mmi_camera_init_countdown_mma();
    #endif

    /* start count down */
    mmi_camera_countdown_cyclic();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_countdown_state
 * DESCRIPTION
 *  entry count down state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop countdown timer */
    gui_cancel_timer(mmi_camera_countdown_stop_LED);
    mmi_camera_countdown_stop_LED();
    gui_cancel_timer(mmi_camera_countdown_cyclic);

    #ifdef __COUNTDOWN_USING_MMA__
        gui_cancel_timer(mmi_camera_capture);
        gui_cancel_timer(mmi_camera_deinit_countdown_mma);
    #endif

    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
    #ifdef __COUNTDOWN_USING_MMA__
        if (g_camera_cntx.multi_sound_countdown != 0 && g_camera_cntx.multi_sound_dummy_bg != 0)
        {
            mmi_camera_deinit_countdown_mma();
        }
    #endif
    
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_preview_stop();

        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }

}

#ifdef __COUNTDOWN_USING_MMA__
static void mmi_camera_init_countdown_mma(void)
{
    /* set flag */

        /* open and play a dummy midi at backgroup - this is a must do to play multi-channel sound */
        g_camera_cntx.multi_sound_dummy_bg = mdi_audio_mma_open_midi((void*)camera_sound_dummy_bg, CAMERA_SOUND_DUMMY_BG_LEN, 0, NULL);
        mdi_audio_mma_play_midi(g_camera_cntx.multi_sound_dummy_bg);

        g_camera_cntx.multi_sound_countdown = mdi_audio_mma_open_wav(
                                            (void*)camera_sound_countdown,
                                            (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                            1,
                                            NULL);
}


static void mmi_camera_deinit_countdown_mma(void)
{
        mdi_audio_mma_stop_midi(g_camera_cntx.multi_sound_dummy_bg);
        mdi_audio_mma_close_midi(g_camera_cntx.multi_sound_dummy_bg);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_countdown);

        g_camera_cntx.multi_sound_countdown = 0;
        g_camera_cntx.multi_sound_dummy_bg = 0;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_camera_countdown_cyclic
 * DESCRIPTION
 *  count down delay timer cyclic loop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_countdown_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* countdonw duration and freq */
    if (g_camera_cntx.capture_countdown > 6000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }

        gui_start_timer(100, mmi_camera_countdown_stop_LED);
        gui_start_timer(1000, mmi_camera_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 1000;
        {
            #ifdef __COUNTDOWN_USING_MMA__
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
            #else
                mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                                    MDI_FORMAT_DVI_ADPCM,
                                                    DEVICE_AUDIO_PLAY_ONCE,
                                                    NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
            #endif
        }
    }
    else if (g_camera_cntx.capture_countdown > 2000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }

        gui_start_timer(100, mmi_camera_countdown_stop_LED);
        gui_start_timer(500, mmi_camera_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 500;

        {
            #ifdef __COUNTDOWN_USING_MMA__
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
            #else
                mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                                    MDI_FORMAT_DVI_ADPCM,
                                                    DEVICE_AUDIO_PLAY_ONCE,
                                                    NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
            #endif

        }
    }
    else if (g_camera_cntx.capture_countdown >= 0)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }

        gui_start_timer(100, mmi_camera_countdown_stop_LED);
        gui_start_timer(200, mmi_camera_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 200;

        {
            #ifdef __COUNTDOWN_USING_MMA__
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
            #else
                mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                                    MDI_FORMAT_DVI_ADPCM,
                                                    DEVICE_AUDIO_PLAY_ONCE,
                                                    NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
            #endif

        }
    }
    else
    {
    #ifdef __COUNTDOWN_USING_MMA__
        gui_start_timer(200, mmi_camera_deinit_countdown_mma);
        gui_start_timer(300, mmi_camera_capture);
    #else
        mmi_camera_capture();
    #endif
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_countdown_stop_LED
 * DESCRIPTION
 *  stop count down LED
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_countdown_stop_LED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
    }
}

/*****************************************************************************
*
*  Main LCD Cont Shot State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_contshot_state
 * DESCRIPTION
 *  entry contshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_entry_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }


#ifdef __MMI_CAMERA_AF_TEST__
    if (g_camera_cntx.is_af_test == FALSE)
    {
#endif /* __MMI_CAMERA_AF_TEST__ */ 
        /* init count down para */
        switch (g_camera_cntx.setting.cont_shot)
        {
            case CAMERA_SETTING_CONT_SHOT_1:
            {
                g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_1_COUNT;
                g_camera_cntx.cont_shot_count = 0;
            }
                break;

        #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
            case CAMERA_SETTING_CONT_SHOT_2:
            {
                g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_2_COUNT;
                g_camera_cntx.cont_shot_count = 0;
            }
                break;
        #endif /* __CAMERA_FEATURE_CONT_SHOT_2__ */ 
        #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
            case CAMERA_SETTING_CONT_SHOT_3:
            {
                g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_3_COUNT;
                g_camera_cntx.cont_shot_count = 0;
            }
                break;
        #endif /* __CAMERA_FEATURE_CONT_SHOT_3__ */ 
        }
    #ifdef __MMI_CAMERA_AF_TEST__
    }
    #endif 
    mmi_camera_contshot_cyclic();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_contshot_state
 * DESCRIPTION
 *  entry contshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel countdown timer */
    gui_cancel_timer(mmi_camera_contshot_cyclic);

    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_preview_stop();

        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_contshot_cyclic
 * DESCRIPTION
 *  cont shot cyclic loop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_contshot_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

#ifndef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
    S8 buffer[100];
    S8 UCS2_buffer[100];
#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.cont_shot_count + 1 == g_camera_cntx.cont_shot_total_count)
    {
        g_camera_cntx.is_continue_capture = FALSE;
    }
    else
    {
        g_camera_cntx.is_continue_capture = TRUE;
    }

    /* set capturing flag */
    g_camera_cntx.is_capturing = TRUE;

    if (g_camera_cntx.cont_shot_total_count != 1)
    {
    #ifndef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
        sprintf(buffer, "%d/%d", g_camera_cntx.cont_shot_count + 1, g_camera_cntx.cont_shot_total_count);
        mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);
        mmi_ucs2cpy((PS8) buffer, (PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING));
        mmi_camera_preview_set_hint((PS8) buffer, UCS2_buffer, 0);
    #else /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 
        mmi_camera_preview_set_hint(NULL, NULL, 0);
    #endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 

        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }
    else
    {
        /* if only 1 image, draw "Capture.." string */
        mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING), NULL, 0);
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

    /* will capture then save to file */
    mmi_camera_get_next_filename(buf_filename);

    /* start timer for next shot */
#ifdef __MMI_CAMERA_AF_TEST__
    if (g_camera_cntx.is_af_test == FALSE)
    {
        gui_start_timer(100, mmi_camera_contshot_cyclic);
    }
#else /* __MMI_CAMERA_AF_TEST__ */ 
    gui_start_timer(100, mmi_camera_contshot_cyclic);
#endif /* __MMI_CAMERA_AF_TEST__ */ 

    mmi_camera_turn_on_capture_led_highlight();

    if (g_camera_cntx.setting.add_frame == CAMERA_SETTING_ADD_FRAME_OFF)
    {
        switch (g_camera_cntx.capture_path)
        {
            case CAPTURE_FROM_MEMORY:
                g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);
                break;
            case CAPTURE_FROM_LAYER:
                g_camera_cntx.last_error = mdi_camera_capture_layer_to_file(
        #if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
                                                                               GDI_LAYER_ENABLE_LAYER_0,
        #else 
                                                                               GDI_LAYER_ENABLE_LAYER_1,
        #endif 
                                                                               buf_filename,
                                                                               0,
                                                                               0,
                                                                               g_camera_cntx.osd_UI_device_width,
                                                                               g_camera_cntx.osd_UI_device_height,
                                                                               g_camera_cntx.is_continue_capture);

                break;

            default:
                g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);
                break;
        }
    }
    else
    {
        switch (g_camera_cntx.capture_path)
        {
            case CAPTURE_FROM_MEMORY:
                g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);
                break;
            case CAPTURE_FROM_LAYER:
        #ifdef HORIZONTAL_CAMERA
                /* rotate add_frame_layer for orientation align while capturing */
                gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);
        #endif /* HORIZONTAL_CAMERA */ 

        #if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
                /* (0) Base-as preview buffer, (2) Add frame layer */
        #if defined(__MMI_CAMERA_5_OSD_LAYER__)
                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle4,
                    g_camera_cntx.add_frame_layer_handle,
                    0);
        #elif defined(__MMI_CAMERA_3_OSD_LAYER__)
                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle2,
                    g_camera_cntx.add_frame_layer_handle,
                    0);       
        #else /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.add_frame_layer_handle,
                    0);
        #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 

                g_camera_cntx.last_error
                    = mdi_camera_capture_layer_to_file(
                        GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_2,
                        buf_filename,
                        0,
                        0,
                        g_camera_cntx.osd_UI_device_width,
                        g_camera_cntx.osd_UI_device_height,
                        g_camera_cntx.is_continue_capture);

        #else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */
        #if defined(__MMI_CAMERA_5_OSD_LAYER__)
                gdi_layer_set_blt_layer(
                    g_camera_cntx.base_layer_handle,
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle4,
                    g_camera_cntx.add_frame_layer_handle);
        #elif defined(__MMI_CAMERA_3_OSD_LAYER__)
                gdi_layer_set_blt_layer(
                    g_camera_cntx.base_layer_handle,
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle2,
                    g_camera_cntx.add_frame_layer_handle);
        #else /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
                gdi_layer_set_blt_layer(
                    g_camera_cntx.base_layer_handle,
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.add_frame_layer_handle);
        #endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
                g_camera_cntx.last_error
                    = mdi_camera_capture_layer_to_file(
                        GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_3,
                        buf_filename,
                        0,
                        0,
                        g_camera_cntx.osd_UI_device_width,
                        g_camera_cntx.osd_UI_device_height,
                        g_camera_cntx.is_continue_capture);

        #endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */

        #ifdef HORIZONTAL_CAMERA
                /* reset rotation of add_frame_layer for orientation align after capturing */
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                gdi_layer_pop_and_restore_active();
        #endif /* HORIZONTAL_CAMERA */ 
                break;
            default:
                g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);
                break;
        }
    }

    /* play capture sound after capture */
    mmi_camera_capture_play_sound();

    /* after captured restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    if (!g_camera_cntx.is_fullscreen)
    {
        mmi_camera_preview_clear_background();
    }
#endif /* CAMERA_MODULE_WITH_LCD */ 

    mmi_camera_turn_off_led_highlight();

    /* captured, previwing is stopped, change blt layer */
    mmi_camera_preview_set_blt_layer(FALSE);


    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
    #ifdef __CAMERA_AUTOFOCUS__
    #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
        if (g_camera_cntx.setting.af_mode != CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
        {
            mdi_camera_stop_autofocus_process();
            g_camera_cntx.af_state = AF_CANCEL;
        }
    #else /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
        mdi_camera_stop_autofocus_process();
        g_camera_cntx.af_state = AF_CANCEL;
    #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
    #endif /* __CAMERA_AUTOFOCUS__ */ 

        g_camera_cntx.is_continue_capture = FALSE;

        mmi_camera_restore_filename_seq_no();
        
        gui_cancel_timer(mmi_camera_contshot_cyclic);
        FS_Delete((U16*) buf_filename);
        mmi_camera_display_error_popup();
        return;
    }

    g_camera_cntx.cont_shot_count++;

    /* terminate condition */
    if (g_camera_cntx.cont_shot_count >= g_camera_cntx.cont_shot_total_count)
    {
    #ifdef __MMI_CAMERA_AF_TEST__
        if (g_camera_cntx.is_af_test == TRUE)
        {
            g_camera_cntx.is_af_test = FALSE;
        }
    #endif /* __MMI_CAMERA_AF_TEST__ */ 

        /* stop timer */
        gui_cancel_timer(mmi_camera_contshot_cyclic);

        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);

        return;
    }
    else
    {
        /* change blt layer for previwing */
        mmi_camera_preview_set_blt_layer(TRUE);
        mmi_camera_preview_start();

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            g_camera_cntx.is_continue_capture = FALSE;
            /* stop timer */
            gui_cancel_timer(mmi_camera_contshot_cyclic);
            mmi_camera_display_error_popup();
            return;
        }
    #ifdef __MMI_CAMERA_AF_TEST__
        if (g_camera_cntx.is_af_test == TRUE)
        {
            mmi_camera_af_test_start();
        }
    #endif /* __MMI_CAMERA_AF_TEST__ */ 
    }

}

/*****************************************************************************
*
*  Burstshot State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_burstshot_capture_state
 * DESCRIPTION
 *  entry burstshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_burstshot_capture_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* clearn center key - since if not clear, this key will mapping to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

    mmi_camera_turn_on_capture_led_highlight();

    /* set capturing flag */
    g_camera_cntx.is_capturing = TRUE;

    mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_BURST_CAPTURING), NULL, 0);

#ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.is_autofocus_pressed = FALSE;
#endif 

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_UP);

    if (g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
    {
        /* start multi_channel sound, for capture sound effect */

        if (g_camera_cntx.is_multi_sound_open == FALSE)
        {
            /* multi_sound still not opened, open them */

            /* set flag */
            g_camera_cntx.is_multi_sound_open = TRUE;

            /* open and play a dummy midi at backgroup - this is a must do to play multi-channel sound */
            g_camera_cntx.multi_sound_dummy_bg = mdi_audio_mma_open_midi((void*)camera_sound_dummy_bg, CAMERA_SOUND_DUMMY_BG_LEN, 0, NULL);

            mdi_audio_mma_play_midi(g_camera_cntx.multi_sound_dummy_bg);

            g_camera_cntx.multi_sound_cap_idx = 0;

            switch (g_camera_cntx.setting.shutter_sound)
            {
                case CAMERA_SETTING_SHUTTER_SOUND_1:
                {
                    g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_1,
                                                            (U32) CAMERA_SOUND_SHUTTER_1_LEN,
                                                            1,
                                                            NULL);

                    g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_1,
                                                            (U32) CAMERA_SOUND_SHUTTER_1_LEN,
                                                            1,
                                                            NULL);

                    g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_1,
                                                            (U32) CAMERA_SOUND_SHUTTER_1_LEN,
                                                            1,
                                                            NULL);
                }
                    break;

                case CAMERA_SETTING_SHUTTER_SOUND_2:
                {
                    g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_2,
                                                            (U32) CAMERA_SOUND_SHUTTER_2_LEN,
                                                            1,
                                                            NULL);

                    g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_2,
                                                            (U32) CAMERA_SOUND_SHUTTER_2_LEN,
                                                            1,
                                                            NULL);

                    g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_2,
                                                            (U32) CAMERA_SOUND_SHUTTER_2_LEN,
                                                            1,
                                                            NULL);
                }
                    break;

                case CAMERA_SETTING_SHUTTER_SOUND_3:
                {
                    g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_3,
                                                            (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                                                            1,
                                                            NULL);

                    g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_3,
                                                            (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                                                            1,
                                                            NULL);

                    g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav(
                                                            (void*)camera_sound_shutter_3,
                                                            (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                                                            1,
                                                            NULL);
                }
                    break;
            }
        }
        else
        {
            /* multi_sound is alrady opened, stop the timer that will close it */
            gui_cancel_timer(mmi_camera_burstshot_close_multi_sound);
        }

    }

    /* MT6228 support non-blocking burst shot */
    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_non_block_burst_capture_to_memory(
            CAMERA_FEATURE_CONT_SHOT_BURST_COUNT,
            &g_camera_cntx.burst_jpg_data,
            mmi_camera_burstshot_capture_result_hdlr);

#else /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* burst shot shall play before capture */
    mmi_camera_capture_play_sound();

    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_burst_capture_to_memory(CAMERA_FEATURE_CONT_SHOT_BURST_COUNT, &g_camera_cntx.burst_jpg_data);

    /* clear capturing flag */
    g_camera_cntx.is_capturing = FALSE;

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    mmi_camera_preview_clear_background();
#endif 

    /* will enter save confirm, close led highlight */
    mmi_camera_turn_off_led_highlight();

    /* captured, previewing is stopped, change blt layer */
    mmi_camera_preview_set_blt_layer(FALSE);

    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }
    else
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM);
    }

#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_capture_result_hdlr
 * DESCRIPTION
 *  no block burst shot capture result handler
 * PARAMETERS
 *  ret                 [IN]        Burst shot result
 *  captured_count      [IN]        
 *  count(?)            [IN]        How many image is captured, count start from 1
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if camera is in EXIT state by interrup, just do nothing */
    if (g_camera_cntx.app_state == CAMERA_STATE_EXIT)
    {
        return;
    }

    /* capture count start from 1 */
    mmi_camera_capture_play_multi_channel_sound();

    if (ret >= 0)
    {
        /* no error happened */
        if (captured_count == CAMERA_FEATURE_CONT_SHOT_BURST_COUNT)
        {
            g_camera_cntx.is_capturing = FALSE;
        #ifdef __CAMERA_AUTOFOCUS__
        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            if (g_camera_cntx.setting.af_mode != CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
            {
                mdi_camera_stop_autofocus_process();
            }
        #else /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
            mdi_camera_stop_autofocus_process();
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
        #endif /* __CAMERA_AUTOFOCUS__ */ 
            PowerAndEndKeyHandler();

            /* will enter save confirm, close led highlight */
            mmi_camera_turn_off_led_highlight();
            
            CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM);
            return;
        }
    }
    else
    {
        g_camera_cntx.is_capturing = FALSE;
        g_camera_cntx.last_error = ret;
        mmi_camera_display_error_popup();
    }
}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ /* __CAMERA_FEATURE_CONT_SHOT_BURST__ & __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_close_multi_sound
 * DESCRIPTION
 *  no block burst shot capture result handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_burstshot_close_multi_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* capture count start from 1 */
    if (g_camera_cntx.is_multi_sound_open)
    {
        mdi_audio_mma_stop_midi(g_camera_cntx.multi_sound_dummy_bg);
        mdi_audio_mma_close_midi(g_camera_cntx.multi_sound_dummy_bg);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture0);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture0);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture1);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture1);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture2);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture2);

        g_camera_cntx.multi_sound_capture0 = 0;
        g_camera_cntx.multi_sound_capture1 = 0;
        g_camera_cntx.multi_sound_capture2 = 0;
        g_camera_cntx.multi_sound_dummy_bg = 0;

        g_camera_cntx.is_multi_sound_open = FALSE;
    }

}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ /* __CAMERA_FEATURE_CONT_SHOT_BURST__ & __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_burstshot_capture_state
 * DESCRIPTION
 *  entry burstshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_exit_burstshot_capture_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop capture and stop dummy bg midi for multi-channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)

    if (g_camera_cntx.is_capturing)
    {
        mdi_camera_stop_non_block_burst_capture();
    }

    /*
     * close multi-channel sound after 500 ms, this is used to 
     * avoid last sound be terminate when play to half 
     */
    gui_start_timer(500, mmi_camera_burstshot_close_multi_sound);

#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

    /* hide hint on panel if it is not fade out */
    mmi_camera_preview_hide_hint();

    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* mdi_camera_burst_shot_stop */
        /* need this function if burstshot is non-blocking */

        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/*****************************************************************************
*
*  BurstShot Save Confirm State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_burstshot_save_confirm_state
 * DESCRIPTION
 *  enter save confirm state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_burstshot_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 i, j;
    S32 image_box_width;
    S32 image_box_height;
    S32 image_box_offset_x;
    S32 image_box_offset_y;
    S32 spacing;
    S32 index;
    PU8 image_buf_ptr;
    U32 image_buf_size;
    S32 image_width = 0;
    S32 image_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init var */
    g_camera_cntx.is_lsk_pressed = FALSE;
    g_camera_cntx.is_rsk_pressed = FALSE;

    spacing = 2;

    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_burstshot_save_confirm_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_burstshot_save_confirm_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_burstshot_save_confirm_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_burstshot_save_confirm_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

    /* clear base layer background */
    mmi_camera_preview_clear_background();

    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    g_camera_cntx.is_single_osd_layer = TRUE;
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_free_osd_layer();
    mmi_camera_create_osd_layer();
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        mmi_camera_check_osd_orientation();
    #endif
    #endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);

    /* hide icons  */
    mmi_camera_preview_set_hint(NULL, NULL, 0);
    mmi_camera_preview_draw_osd();

    gdi_image_jpeg_get_dimension(
        (PU8) g_camera_cntx.burst_jpg_data.file_address[0],
        g_camera_cntx.burst_jpg_data.file_size[0],
        &image_width,
        &image_height);

    /* set clip region as content region */
    gdi_layer_reset_clip();

    /* calc image region */
    image_region_width = g_camera_cntx.osd_UI_device_width;
    image_region_height = g_camera_cntx.osd_UI_device_height;
    image_region_offset_x = 0;
    image_region_offset_y = 0;

    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
        image_region_height -= (MMI_title_height + MMI_title_y);
        image_region_offset_y += (MMI_title_height + MMI_title_y);
    }

    if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
    {
        image_region_height -= (MMI_button_bar_height);
    }

    /* TODO: check image_width & image_height no Zero */

    image_box_width = image_region_width - spacing * (CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL * 2);
    image_box_width /= CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL;

    image_box_height = image_region_height - spacing * (CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW * 2);
    image_box_height /= CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW;

    index = 0;
    for (i = 0; i < CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW; i++)
    {
        for (j = 0; j < CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL; j++)
        {
            image_buf_ptr = (PU8) g_camera_cntx.burst_jpg_data.file_address[index];
            image_buf_size = (U32) g_camera_cntx.burst_jpg_data.file_size[index];

            image_box_offset_x = image_region_offset_x + (j * 2 + 1) * spacing + j * image_box_width;
            image_box_offset_y = image_region_offset_y + (i * 2 + 1) * spacing + i * image_box_height;

            if ((image_box_width >= image_width) && (image_box_height >= image_height))
            {
                /* align preview window at the center of box */
                offset_x = image_box_offset_x + ((image_box_width - image_width) >> 1);
                offset_y = image_box_offset_y + ((image_box_height - image_height) >> 1);

                gdi_image_jpeg_draw(offset_x, offset_y, image_buf_ptr, image_buf_size);

                gdi_draw_rect(
                    image_box_offset_x + offset_x - 1,
                    image_box_offset_y + offset_y - 1,
                    image_box_offset_x + offset_x + image_width,
                    image_box_offset_y + offset_y + image_height,
                    GDI_COLOR_WHITE);
            }
            else
            {
                gdi_image_util_fit_bbox(
                    image_box_width,
                    image_box_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
                gdi_image_jpeg_draw_resized(
                    resized_offset_x + image_box_offset_x,
                    resized_offset_y + image_box_offset_y,
                    resized_width,
                    resized_height,
                    image_buf_ptr,
                    image_buf_size);

                gdi_draw_rect(
                    image_box_offset_x + resized_offset_x - 1,
                    image_box_offset_y + resized_offset_y - 1,
                    image_box_offset_x + resized_offset_x + resized_width,
                    image_box_offset_y + resized_offset_y + resized_height,
                    GDI_COLOR_WHITE);

            }

            /* blt */
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);

            /* next image */
            index++;
        }
    }

    /* draw save notify text */
    mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOTIFY_SAVE_CONFIRM), NULL, 0);
    mmi_camera_preview_draw_osd();

    /* blt */
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_burstshot_save_confirm_state
 * DESCRIPTION
 *  exit save confirm state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_exit_burstshot_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
    }
    else
    {
        /* clear panel */
        mmi_camera_preview_set_hint(NULL, NULL, 0);
        mmi_camera_preview_draw_osd();

        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_save_confirm_lsk_press
 * DESCRIPTION
 *  draw save confirm softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_save_confirm_lsk_release
 * DESCRIPTION
 *  lsk release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = FALSE;
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    /* enter burstshot saving to save file */
    CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT_SAVING);
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_save_confirm_rsk_press
 * DESCRIPTION
 *  draw save confirm softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_save_confirm_rsk_release
 * DESCRIPTION
 *  draw save confirm softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = FALSE;

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/*****************************************************************************
*
*  Save Burstshot State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_burstshot_saving_state
 * DESCRIPTION
 *  entry save burstshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }


    /* draw base layer only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);

#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif

    mmi_camera_free_add_frame_layer();

    ExitCategoryFunction();
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVING), IMG_GLOBAL_SAVE, NULL);
    g_camera_cntx.is_cat65_show = TRUE;


    /* start save burst shot */
    g_camera_cntx.burst_save_index = 0;
    mmi_camera_burstshot_saving_cyclic();
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_burstshot_saving_state
 * DESCRIPTION
 *  exit save burstshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_exit_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit popup screen to free drawmanager's resource */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }

    gui_cancel_timer(mmi_camera_burstshot_saving_cyclic);
    gdi_image_stop_animation_all();

    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
    
        /* flatten layer */
        mmi_camera_preview_flatten_layer(FALSE);
    }
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_burstshot_saving_cyclic
 * DESCRIPTION
 *  loop to save burstshot image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_saving_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 image_buf_ptr;
    U32 image_buf_size;
    U32 written;
    FS_HANDLE file_handle;

#ifdef EXIF_SUPPORT
    U32 size_of_exif_info = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);

    /* start timer for next shot */
    gui_start_timer(100, mmi_camera_burstshot_saving_cyclic);

    /* save burst shot image */

    image_buf_ptr = (PU8) g_camera_cntx.burst_jpg_data.file_address[g_camera_cntx.burst_save_index];
    image_buf_size = (U32) g_camera_cntx.burst_jpg_data.file_size[g_camera_cntx.burst_save_index];

    file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);

    if (file_handle > 0)
    {
    #ifdef EXIF_SUPPORT
        /* eixf_burst_mode_fill_header(kal_uint8* Buffer,kal_uint32 BufferOffset); */
    #if defined(__MTK_TARGET__)
        size_of_exif_info = eixf_burst_mode_fill_header(image_buf_ptr);
    #endif 
        image_buf_size += size_of_exif_info;
        image_buf_ptr -= size_of_exif_info;
    #endif /* EXIF_SUPPORT */ 
        FS_Write(file_handle, (void*)image_buf_ptr, image_buf_size, (U32*) & written);
        FS_Close(file_handle);

        /* cant write in whole file, must be disk full */
        if (image_buf_size != written)
        {
            /* delete the file that is not save complete */
            FS_Delete((U16*) buf_filename);
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
            mmi_camera_restore_filename_seq_no();
            /* will display a popup, go out application and re-enter */
            mmi_camera_display_error_popup();
            return;
        }
    }
    else
    {
        if (file_handle == FS_DISK_FULL)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_ROOT_DIR_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
        }
        else if (file_handle == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
        }
        else
        {
            g_camera_cntx.last_error = CAMERA_ERR_SAVE_FAIL;
        }
        mmi_camera_restore_filename_seq_no();
        /* will display a popup, go out application and re-enter */
        mmi_camera_display_error_popup();
        return;
    }

    /* teminate condition */
    if (g_camera_cntx.burst_save_index >= CAMERA_FEATURE_CONT_SHOT_BURST_COUNT - 1)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_SAVE_DONE);
        return;
    }

    /* increase index */
    g_camera_cntx.burst_save_index++;

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/*****************************************************************************
*
*  TileShot State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_tileshot_capture
 * DESCRIPTION
 *  tileshot capture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
static void mmi_camera_tileshot_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x = 0;
    S32 offset_y = 0;

    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if needs to show capture icon, update it */
    if (g_camera_cntx.active_camera_osd_ptr->capture.is_show)
    {
        g_camera_cntx.is_capturing = TRUE;
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_HEIGHT >> 1);
        offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_WIDTH >> 1);
    }
    else if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
    {
        offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_WIDTH >> 1);
        offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_HEIGHT >> 1);
    }
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    offset_x = (g_camera_cntx.tile_cur_num % 2) * (LCD_WIDTH >> 1);
    offset_y = (g_camera_cntx.tile_cur_num / 2) * (LCD_HEIGHT >> 1);

#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

    mmi_camera_turn_on_capture_led_highlight();
    switch (g_camera_cntx.capture_path)
    {
        case 0:
            g_camera_cntx.last_error
                = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
            break;
        case 1:
            gdi_layer_set_blt_layer(
                g_camera_cntx.preview_layer_handle,
                GDI_LAYER_MEDIA_HW_TRIGGER_LAYER,
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.add_frame_layer_handle);

            g_camera_cntx.last_error
                = mdi_camera_capture_layer_to_memory(
                    GDI_LAYER_ENABLE_LAYER_0,
                    &g_camera_cntx.capture_buf_ptr,
                    &g_camera_cntx.capture_size,
                    offset_x,
                    offset_y,
                    g_camera_cntx.osd_UI_device_width >> 1,
                    g_camera_cntx.osd_UI_device_height >> 1);

            gdi_layer_set_blt_layer(
                g_camera_cntx.tileshot_result_layer_handle,
                GDI_LAYER_MEDIA_HW_TRIGGER_LAYER,
                g_camera_cntx.add_frame_layer_handle,
                g_camera_cntx.osd_layer_handle0);

            break;
        default:
            g_camera_cntx.last_error
                = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
            break;
    }

    /* play capture sound after capture */
    mmi_camera_capture_play_sound();
    mmi_camera_turn_off_led_highlight();

    gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);

    offset_x = (g_camera_cntx.tile_cur_num % 2) * (g_camera_cntx.osd_UI_device_width >> 1);
    offset_y = (g_camera_cntx.tile_cur_num / 2) * (g_camera_cntx.osd_UI_device_height >> 1);

    /* TODO: add error handling */
    result = gdi_image_jpeg_draw(offset_x, offset_y, g_camera_cntx.capture_buf_ptr, g_camera_cntx.capture_size);

    gdi_layer_pop_and_restore_active();

    /* set hint to NULL */
    mmi_camera_preview_set_hint(NULL, NULL, 0);

    /* if needs to show capture icon, update it */
    g_camera_cntx.is_capturing = FALSE;
    mmi_camera_preview_draw_osd();

    /* change blt layer for not previwing */
    mmi_camera_preview_set_blt_layer(FALSE);

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    g_camera_cntx.tile_cur_num++;

    if (g_camera_cntx.tile_cur_num == 1)
    {
        /* first tile shot, change softkey from BACK->Clear */
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    }

    if (g_camera_cntx.tile_cur_num < 4)
    {
        /* change blt layer for previwing */
        mmi_camera_preview_set_blt_layer(TRUE);

        mmi_camera_preview_set_key_hdlr();

        if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
        {
            mmi_camera_preview_start();

            if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_camera_display_error_popup();
            }
        }
        else if (g_camera_cntx.app_state == CAMERA_STATE_COUNTDOWN)
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        g_camera_cntx.tile_cur_num = 0;

        /* sicne the tile preview buffer is using base layer's buffer, we have to clear it */
        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        CAMERA_ENTER_STATE(CAMERA_STATE_SAVE_CONFIRM);
    }

}
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_tileshot_capture
 * DESCRIPTION
 *  sublcd tileshot capture
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__) && defined(__CAMERA_FEATURE_SELF_CAPTURE__)
static void mmi_camera_sublcd_tileshot_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_turn_on_capture_led_highlight();

    g_camera_cntx.last_error
        = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);

    /* play capture sound after capture */
    mmi_camera_capture_play_sound();

    mmi_camera_turn_off_led_highlight();

    gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);

    offset_x = (g_camera_cntx.tile_cur_num % 2) * (UI_device_width >> 1);
    offset_y = (g_camera_cntx.tile_cur_num / 2) * (UI_device_height >> 1);

    result = gdi_image_jpeg_draw(offset_x, offset_y, g_camera_cntx.capture_buf_ptr, g_camera_cntx.capture_size);

    gdi_layer_pop_and_restore_active();

    g_camera_cntx.tile_cur_num++;

    if (g_camera_cntx.tile_cur_num < 4)
    {
        /* set maninlcd's blt layer, to display tile images */
        gdi_layer_set_blt_layer(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.add_frame_layer_handle, 0, 0);

        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
        if (g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW)
        {
            mmi_camera_sublcd_preview_start();

            if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_camera_display_error_popup();
            }
        }
        else if (g_camera_cntx.app_state == CAMERA_STATE_SUB_COUNTDOWN)
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
        }
    }
    else
    {
        /* do not need blt, enter save confirm will blt */

        g_camera_cntx.is_dis_clam_open = FALSE;

        g_camera_cntx.tile_cur_num = 0;
        CAMERA_ENTER_STATE(CAMERA_STATE_SAVE_CONFIRM);
    }

}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_TILE__) && defined(__CAMERA_FEATURE_SELF_CAPTURE__) */ 

/*****************************************************************************
*
*  Save Confirm State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_save_confirm_state
 * DESCRIPTION
 *  enter save confirm state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_entry_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 offset_x;
    S32 offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S32 result;
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init var */
    g_camera_cntx.is_lsk_pressed = FALSE;
    g_camera_cntx.is_rsk_pressed = FALSE;

    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_save_confirm_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_save_confirm_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_save_confirm_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_save_confirm_rsk_release, KEY_RSK, KEY_EVENT_UP);

#ifdef __MMI_CAMERA_MMS_SUPPORT__
    if (g_camera_cntx.is_external_request == FALSE && g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM && mms_is_ready())
    {
        g_camera_cntx.is_mms_ready = TRUE;
        SetKeyHandler(mmi_camera_save_confirm_send_to_mms_press, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_save_confirm_send_to_mms_release, KEY_ENTER, KEY_EVENT_UP);

        SetKeyHandler(mmi_camera_save_confirm_send_to_mms_press, KEY_9, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_save_confirm_send_to_mms_release, KEY_9, KEY_EVENT_UP);
        /* clearn center key - since if not clear, this key will mappign to LSK */
        if (CAMERA_CAPTURE_KEY != -1)
        {
            SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        }
    }
    else
    {
        g_camera_cntx.is_mms_ready = FALSE;
    }
#else /* __MMI_CAMERA_MMS_SUPPORT__ */ 

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

#endif /* __MMI_CAMERA_MMS_SUPPORT__ */ 

    /* free preview resource */
    mmi_camera_preview_free_preview_resource();
    #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    g_camera_cntx.is_single_osd_layer = TRUE;
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_free_osd_layer();
    mmi_camera_create_osd_layer();
    #if defined(__CAMERA_OSD_HORIZONTAL__)    
        mmi_camera_check_osd_orientation();
    #endif
    #endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */
#if defined(__CAMERA_OSD_HORIZONTAL__)

    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);

    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);

        /* for rotate layer to upright */
        #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        gdi_layer_set_active(g_camera_cntx.tileshot_result_layer_handle);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
        #endif
    }
    else
    {
        gdi_layer_clear_background(GDI_COLOR_BLACK);
    }

    gdi_layer_pop_and_restore_active();
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

    /* init title bar */
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        reset_title_status_icon();
        show_status_icon_bar(0);
    #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 

        /* hide short cut */
        MMI_menu_shortcut_number = -1;

        if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_caption)
        {
            ChangeTitle(MAIN_MENU_TITLE_MULTIMEDIA_ICON, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
        else
        {
            ChangeTitle(0, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
    }
    else
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
    #endif 
    }

    if (g_camera_cntx.is_tileshot)
    {
    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__

    #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
        /* draw sublcd icon */
        mmi_camera_sublcd_draw_icon();
    #endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0 && g_camera_cntx.setting.add_frame != 0)
            gdi_layer_set_blt_layer(
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.add_frame_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
        else
            gdi_layer_set_blt_layer(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
        MMI_ASSERT(0);
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
    }
    else
    {
        /* clear base layer background */
        mmi_camera_preview_clear_background();
        gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);

        /* get file dimension */
        result = gdi_image_jpeg_get_dimension(
                    g_camera_cntx.capture_buf_ptr,
                    g_camera_cntx.capture_size,
                    &image_width,
                    &image_height);

        /* set clip region as content region */
        gdi_layer_reset_clip();

#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
        if (g_camera_cntx.is_direct_couple == TRUE)
        {
            PU8 src;
            PU8 dest;
            U16 src_width, src_height, src_pitch;
            S32 src_offset_x=0, src_offset_y=0;
            S32 dest_pitch, dest_offset_x, dest_offset_y;
            gdi_rect_struct dest_clip;

            gdi_layer_get_buffer_ptr(&dest);
            src = g_camera_cntx.direct_couple_buffer;
            src_pitch = g_camera_cntx.resized_width;
            dest_pitch = g_camera_cntx.osd_UI_device_width;
            dest_clip.x1 = g_camera_cntx.resized_offset_x;
            dest_clip.y1 = g_camera_cntx.resized_offset_y;
            dest_clip.x2 = g_camera_cntx.resized_offset_x + g_camera_cntx.resized_width - 1;
            dest_clip.y2 = g_camera_cntx.resized_offset_y + g_camera_cntx.resized_height - 1;
            src_width = g_camera_cntx.resized_width;
            src_height = g_camera_cntx.resized_height;
            dest_offset_x = g_camera_cntx.resized_offset_x;
            dest_offset_y = g_camera_cntx.resized_offset_y;

            /* use 2D copy from cache layer to thumbnail layer */
            gdi_2d_memory_blt_without_transpant_check(
                src,
                src_pitch,
                src_offset_x,
                src_offset_y,
                src_width,
                src_height,
                dest,
                dest_pitch,
                dest_offset_x,
                dest_offset_y,
                dest_clip,
                GDI_MAINLCD_BIT_PER_PIXEL);

            g_camera_cntx.is_direct_couple = FALSE;
        }
        else
#endif
        {
            /* calc image region */
            image_region_width = g_camera_cntx.osd_UI_device_width;
            image_region_height = g_camera_cntx.osd_UI_device_height;
            image_region_offset_x = 0;
            image_region_offset_y = 0;

            if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
            {
                image_region_height -= (MMI_title_height + MMI_title_y);
                image_region_offset_y += (MMI_title_height + MMI_title_y);
            }

            if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
            {
                image_region_height -= (MMI_button_bar_height);
            }

            if (result >= 0)
            {
                if ((image_region_width >= image_width) && (image_region_height >= image_height))
                {
                    /* align preview window at the center of screen */
                    offset_x = image_region_offset_x + ((image_region_width - image_width) >> 1);
                    offset_y = image_region_offset_y + ((image_region_height - image_height) >> 1);

                    gdi_image_jpeg_draw(offset_x, offset_y, g_camera_cntx.capture_buf_ptr, g_camera_cntx.capture_size);
                }
                else
                {
                    gdi_image_util_fit_bbox(
                        image_region_width,
                        image_region_height,
                        image_width,
                        image_height,
                        &resized_offset_x,
                        &resized_offset_y,
                        &resized_width,
                        &resized_height);

                    gdi_image_jpeg_draw_resized(
                        resized_offset_x + image_region_offset_x,
                        resized_offset_y + image_region_offset_y,
                        resized_width,
                        resized_height,
                        g_camera_cntx.capture_buf_ptr,
                        g_camera_cntx.capture_size);
                }

            }
        }
    }
    /* draw save notify text */
    mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOTIFY_SAVE_CONFIRM), NULL, 0);

    mmi_camera_preview_draw_osd();

    /* blt */
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    if (g_camera_cntx.is_tileshot)
    {
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0 && g_camera_cntx.setting.add_frame != 0)
        {
            gdi_lcd_blt(
                g_camera_cntx.tileshot_result_layer_handle,
                g_camera_cntx.add_frame_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
        }
        else
        {
            gdi_lcd_blt(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
        }
    }
    else
    {
        /* blt */
        #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (g_camera_cntx.is_single_osd_layer)
        {
            gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
        }
        else
        {
            gdi_lcd_blt(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.osd_layer_handle3,
                0);
        }
        #else
            gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
        #endif


    }
#else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
    /* blt */
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);

#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_save_confirm_state
 * DESCRIPTION
 *  exit save confirm state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_lsk_press
 * DESCRIPTION
 *  draw save confirm softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* copy tiled picture from tile result layer to base layer */
    if (g_camera_cntx.is_tileshot)
    {
        gdi_lcd_blt(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    }
    else
#endif
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_lsk_release
 * DESCRIPTION
 *  lsk release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = FALSE;
    mmi_camera_preview_draw_osd();

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* copy tiled picture from tile result layer to base layer */
    if (g_camera_cntx.is_tileshot)
    {
        gdi_lcd_blt(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    }
    else
#endif
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    mmi_camera_save_confirm_save_file();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_rsk_press
 * DESCRIPTION
 *  draw save confirm softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* copy tiled picture from tile result layer to base layer */
    if (g_camera_cntx.is_tileshot)
    {
        gdi_lcd_blt(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    }
    else
#endif
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_rsk_release
 * DESCRIPTION
 *  draw save confirm softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = FALSE;

    mmi_camera_preview_draw_osd();
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* copy tiled picture from tile result layer to base layer */
    if (g_camera_cntx.is_tileshot)
    {
        gdi_lcd_blt(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    }
    else
#endif
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    mmi_camera_save_confirm_cancel_file();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_cancel_file
 * DESCRIPTION
 *  cancel file, do not save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_cancel_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter preview state */
    CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_save_file
 * DESCRIPTION
 *  save file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U32 written;
    FS_HANDLE file_handle;
    FS_HANDLE file_check;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    /* copy tiled picture from tile result layer to base layer */
    if (g_camera_cntx.is_tileshot)
    {

    #ifdef __CAMERA_FEATURE_ADD_FRAME__
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0 && g_camera_cntx.setting.add_frame != 0)
        {
            gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);

            /* if has add frame, merge layers */
            gdi_layer_flatten(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.add_frame_layer_handle, 0, 0);
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

        /* also copy result to base - this is for when popup show, the result will show at bg */
        gdi_layer_flatten(g_camera_cntx.tileshot_result_layer_handle, 0, 0, 0);

    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    /* blt base only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);

    gdi_layer_lock_frame_buffer();

    /* show popup category */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
    mmi_camera_free_add_frame_layer();

    ExitCategoryFunction();
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVING), IMG_GLOBAL_SAVE, NULL);
    g_camera_cntx.is_cat65_show = TRUE;


    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (g_camera_cntx.is_tileshot)
    {
    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        mmi_camera_get_next_filename(buf_filename);

        if (g_camera_cntx.setting.add_frame != CAMERA_SETTING_ADD_FRAME_OFF)
        {

            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }
            else
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }
        }
        else
        {
            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }
            else
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }

        }

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            /* will display a popup, go out application and re-enter */
            if (g_camera_cntx.is_cat65_show)
            {
                g_camera_cntx.is_cat65_show = FALSE;
                ExitCategoryFunction();
            }
            mmi_camera_restore_filename_seq_no();
            mmi_camera_display_error_popup();
            return;
        }
    #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
        MMI_ASSERT(0);
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    }
    else
    {

        /* this function has nvram access */
        mmi_camera_get_next_filename(buf_filename);

        file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);

        if (file_handle > 0)
        {
            file_check = FS_Write(file_handle, (void*)g_camera_cntx.capture_buf_ptr, g_camera_cntx.capture_size, (U32*) & written);
            FS_Close(file_handle);

            /* cant write in whole file, must be disk full */
            if (file_check != FS_NO_ERROR)
            {
                MMI_ID_TYPE str_id = 0;            
                /* delete the file that is not save complete */
                FS_Delete((U16*) buf_filename);

                str_id = GetFileSystemErrorString(file_check);

                if (g_camera_cntx.is_cat65_show)
                {
                    g_camera_cntx.is_cat65_show = FALSE;
                    ExitCategoryFunction();
                }

                mmi_camera_restore_filename_seq_no();
        
            #if defined(__CAMERA_OSD_HORIZONTAL__)
                DisplayPopupRotated(
                    (PU8) GetString(str_id),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE,
                    g_camera_cntx.osd_rotate);
            #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
                DisplayPopup(
                    (PU8) GetString(str_id),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            #endif
                return;
            }
        }
        else
        {
            if (file_handle == FS_DISK_FULL)
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
            }
            else if (file_handle == FS_ROOT_DIR_FULL)
            {
                g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
            }
            else if (file_handle == FS_WRITE_PROTECTION)
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
            }
            else
            {
                g_camera_cntx.last_error = CAMERA_ERR_SAVE_FAIL;
            }

            if (g_camera_cntx.is_cat65_show)
            {
                g_camera_cntx.is_cat65_show = FALSE;
                ExitCategoryFunction();
            }
            
            mmi_camera_restore_filename_seq_no();
            /* will display a popup, go out application and re-enter */
            mmi_camera_display_error_popup();
            return;
        }
    }

    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }

    /* for External Request */
    if (g_camera_cntx.is_external_request == TRUE)
    {
        mmi_ucs2cpy(g_camera_cntx.storage_filepath,buf_filename);
    }

    /* enter save done */
    CAMERA_ENTER_STATE(CAMERA_STATE_SAVE_DONE);

}

/*****************************************************************************
*
*  Save Done State 
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_save_done_state
 * DESCRIPTION
 *  enter save done state, show a save done popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_entry_save_done_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* draw base layer only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);

    gdi_layer_lock_frame_buffer();

    /* show popup category */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
    mmi_camera_free_add_frame_layer();

    ExitCategoryFunction();
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, NULL);
    g_camera_cntx.is_cat65_show = TRUE;


    gdi_layer_unlock_frame_buffer();

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    gui_start_timer(DONE_POPUP_FADE_TIME, mmi_camera_save_done_timeout);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_save_done_state
 * DESCRIPTION
 *  exit save done state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_exit_save_done_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* will display a popup, go out application and re-enter */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }

    gui_cancel_timer(mmi_camera_save_done_timeout);

    /* stop anmation on popup category */
    gdi_image_stop_animation_all();
#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_0);
        gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_done_timeout
 * DESCRIPTION
 *  save done popup timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_done_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter sub preview state */
    if (g_camera_cntx.is_external_request == FALSE)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
    }
    else 
    {
        /* for External Request */
        g_camera_cntx.callback_ptr(MMI_TRUE,g_camera_cntx.storage_filepath);
        GoBackHistory();
    }
   
}

/***************************************************************************
*
*  Mainlcd Capture 
*
***************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    U32 buf_size;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)
if((kal_uint16) camera_setting_p->flash==1)
{
	noke_mmi_camera_flash_light_on(KAL_TRUE);
}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */


    switch (g_camera_cntx.setting.cont_shot)
    {

        case CAMERA_SETTING_CONT_SHOT_OFF:
        {
            /* capture button pressed */
            g_camera_cntx.is_capturing = TRUE;

            mmi_camera_turn_on_capture_led_highlight();

            mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING), NULL, 0);
            mmi_camera_preview_draw_osd();

            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);

            /* call mdi to capture and save */
            if (g_camera_cntx.setting.add_frame == CAMERA_SETTING_ADD_FRAME_OFF)
            {
                switch (g_camera_cntx.capture_path)
                {
                    case CAPTURE_FROM_MEMORY:
                    #ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
                        /* Calculate the image buffer size */
                        image_region_width = g_camera_cntx.osd_UI_device_width;
                        image_region_height = g_camera_cntx.osd_UI_device_height;
                        image_region_offset_x = 0;
                        image_region_offset_y = 0;

                        if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
                        {
                            image_region_height -= (MMI_title_height + MMI_title_y);
                            image_region_offset_y += (MMI_title_height + MMI_title_y);
                        }

                        if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
                        {
                            image_region_height -= (MMI_button_bar_height);
                        }

                        if ((image_region_width >= g_camera_cntx.image_width) && (image_region_height >= g_camera_cntx.image_height))
                        {
                            g_camera_cntx.resized_offset_x = image_region_offset_x + ((image_region_width - g_camera_cntx.image_width) >> 1);
                            g_camera_cntx.resized_offset_y = image_region_offset_y + ((image_region_height - g_camera_cntx.image_height) >> 1);
                            g_camera_cntx.resized_width = g_camera_cntx.image_width;
                            g_camera_cntx.resized_height = g_camera_cntx.image_height;
                        }
                        else
                        {
                            gdi_image_util_fit_bbox(
                                image_region_width,
                                image_region_height,
                                g_camera_cntx.image_width,
                                g_camera_cntx.image_height,
                                &g_camera_cntx.resized_offset_x,
                                &g_camera_cntx.resized_offset_y,
                                &g_camera_cntx.resized_width,
                                &g_camera_cntx.resized_height);

                        }

                        buf_size = (((g_camera_cntx.resized_width *g_camera_cntx.resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);

                        ASSERT(g_camera_cntx.direct_couple_buffer!=NULL);

                        g_camera_cntx.last_error
                            = mdi_camera_capture_to_memory_direct_couple(&g_camera_cntx.capture_buf_ptr, 
                                                                         &g_camera_cntx.capture_size,
                                                                         (U32) g_camera_cntx.direct_couple_buffer, 
                                                                         buf_size, 
                                                                         g_camera_cntx.resized_width,
                                                                         g_camera_cntx.resized_height );
                        g_camera_cntx.is_direct_couple = TRUE;

                    #else
                        g_camera_cntx.last_error
                            = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
                    #endif
                        break;
                    case CAPTURE_FROM_LAYER:    /* capture layer to memory */
                        g_camera_cntx.last_error
                            = mdi_camera_capture_layer_to_memory(
                                GDI_LAYER_ENABLE_LAYER_0,
                                &g_camera_cntx.capture_buf_ptr,
                                &g_camera_cntx.capture_size,
                                0,
                                0,
                                g_camera_cntx.osd_UI_device_width,
                                g_camera_cntx.osd_UI_device_height);

                        break;
                    default:
                        g_camera_cntx.last_error
                            = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
                        break;
                }
            }
            else
            {
                switch (g_camera_cntx.capture_path)
                {
                    case CAPTURE_FROM_MEMORY:
                        g_camera_cntx.last_error
                            = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
                        break;
                    case CAPTURE_FROM_LAYER:
                #ifdef HORIZONTAL_CAMERA
                        /* rotate add_frame_layer for orientation align while capturing */
                        gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
                        gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);
                #endif /* HORIZONTAL_CAMERA */ 

                        gdi_layer_set_blt_layer(
                            g_camera_cntx.preview_layer_handle,
                            g_camera_cntx.osd_layer_handle0,
                            g_camera_cntx.add_frame_layer_handle,
                            0);

                        /* (0) Base-as preview buffer, (2) Add frame layer */

                        g_camera_cntx.last_error
                            = mdi_camera_capture_layer_to_memory(
                                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_2,
                                &g_camera_cntx.capture_buf_ptr,
                                &g_camera_cntx.capture_size,
                                0,
                                0,
                                g_camera_cntx.osd_UI_device_width,
                                g_camera_cntx.osd_UI_device_height);

                #ifdef HORIZONTAL_CAMERA
                        /* reset rotation of add_frame_layer for orientation align after capturing */
                        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                        gdi_layer_pop_and_restore_active();
                #endif /* HORIZONTAL_CAMERA */ 

                        break;
                    default:
                        g_camera_cntx.last_error
                            = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
                        break;
                }
            }

            /* play capture sound after capture */
            mmi_camera_capture_play_sound();

            g_camera_cntx.is_capturing = FALSE;

            /* restore background */
        #ifdef CAMERA_MODULE_WITH_LCD
            if (!g_camera_cntx.is_fullscreen)
            {
                mmi_camera_preview_clear_background();
            }
        #endif /* CAMERA_MODULE_WITH_LCD */ 

            /* will enter save confirm, close led highlight */
            mmi_camera_turn_off_led_highlight();

            /* captured, previewing is stopped, change blt layer */
            mmi_camera_preview_set_blt_layer(FALSE);

            if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_camera_display_error_popup();
                return;
            }
            else
            {
                CAMERA_ENTER_STATE(CAMERA_STATE_SAVE_CONFIRM);
            }
        }
            break;

        case CAMERA_SETTING_CONT_SHOT_1:
    #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
        case CAMERA_SETTING_CONT_SHOT_2:
    #endif 
    #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
        case CAMERA_SETTING_CONT_SHOT_3:
    #endif 
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_CONTSHOT);
            return;
        }
            break;
    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        case CAMERA_SETTING_CONT_SHOT_BURST:
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT);
            return;
        }
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        case CAMERA_SETTING_CONT_SHOT_TILE:
        {

            mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING), NULL, 0);
            mmi_camera_preview_draw_osd();
            gdi_layer_blt_previous(
                0,
                0,
                g_camera_cntx.base_UI_device_width - 1,
                g_camera_cntx.base_UI_device_height - 1);
            mmi_camera_tileshot_capture();
            return;
        }
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;

    }
/* 2009.04.20 added by hongzhe.liu for flash light + */
#if defined(__MAIN_CAMERA_WITH_FLASH__)  && !defined(WIN32)
		if((kal_uint16) camera_setting_p->flash == 1)
		{
			noke_mmi_camera_flash_light_on(KAL_FALSE);
		}
#endif
/* 2009.04.20 added by hongzhe.liu for flash light - */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture_button_press
 * DESCRIPTION
 *  capture button presse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_capture_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* capture only works if camera is ready, otherwise will ignore this action */
    if (mdi_camera_is_ready_to_capture() == TRUE)
    {
        /* HANDLE AF STATE */
    #ifdef __CAMERA_AUTOFOCUS__
        if (g_camera_cntx.af_state == AF_CALCULATE)
        {
            g_camera_cntx.is_af_capture = TRUE;
            return;
        }

        /* avoid that audio hang when playing focus succeed sound */ 
        if (g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF && g_camera_cntx.is_audio_finished == FALSE)
        {
            return;
        }
    #endif /* __CAMERA_AUTOFOCUS__ */ 

        /* if not self timer, capture the image */
        if (g_camera_cntx.setting.delay_timer == CAMERA_SETTING_DELAY_TIMER_OFF)
        {
            mmi_camera_capture();
        }
        else
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_COUNTDOWN);
        }
    }
#ifdef __MMI_CAMERA_AF_TEST__
    else if (g_camera_cntx.is_af_test == TRUE)
    {
        mmi_camera_capture_button_press();
    }
#endif /* __MMI_CAMERA_AF_TEST__ */ 
    /* flush key event */
    ClearKeyEvents();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture_button_release
 * DESCRIPTION
 *  capture button release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_capture_button_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flush all key event */
    ClearKeyEvents();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture_play_sound
 * DESCRIPTION
 *  play capture shutter sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camera_capture_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* force to close multi channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    mmi_camera_burstshot_close_multi_sound();
    gui_cancel_timer(mmi_camera_burstshot_close_multi_sound);
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

    /* play capture sound */
    switch (g_camera_cntx.setting.shutter_sound)
    {
        case CAMERA_SETTING_SHUTTER_SOUND_1:
        {
            mdi_audio_play_string_with_vol_path((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN,
        #if defined(__MMI_CAMERA_HIGH_END__)
                                                MDI_FORMAT_WAV,
        #else 
                                                MDI_FORMAT_DVI_ADPCM,
        #endif 
                                                DEVICE_AUDIO_PLAY_ONCE,
                                                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
        }
            break;

        case CAMERA_SETTING_SHUTTER_SOUND_2:
        {
            mdi_audio_play_string_with_vol_path((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN,
        #if defined(__MMI_CAMERA_HIGH_END__)
                                                MDI_FORMAT_WAV,
        #else 
                                                MDI_FORMAT_DVI_ADPCM,
        #endif 
                                                DEVICE_AUDIO_PLAY_ONCE,
                                                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
        }
            break;

        case CAMERA_SETTING_SHUTTER_SOUND_3:
        {
            mdi_audio_play_string_with_vol_path((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN,
        #if defined(__MMI_CAMERA_HIGH_END__)
                                                MDI_FORMAT_WAV,
        #else 
                                                MDI_FORMAT_DVI_ADPCM,
        #endif 
                                                DEVICE_AUDIO_PLAY_ONCE,
                                                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
        }
            break;

        case CAMERA_SETTING_SHUTTER_SOUND_OFF:
        default:
            /* do not play sound */
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_capture_play_multi_channel_sound
 * DESCRIPTION
 *  play capture shutter sound effect when support multi-channel
 *  this is for no-blocking burst shot for MT6228
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_capture_play_multi_channel_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* play capture sound */
    switch (g_camera_cntx.setting.shutter_sound)
    {
        case CAMERA_SETTING_SHUTTER_SOUND_1:
        case CAMERA_SETTING_SHUTTER_SOUND_2:
        case CAMERA_SETTING_SHUTTER_SOUND_3:
        {
            if (g_camera_cntx.multi_sound_cap_idx == 0)
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture0);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_capture0);
            }
            else if (g_camera_cntx.multi_sound_cap_idx == 1)
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture1);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_capture1);
            }
            else
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture2);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_capture2);
            }

            g_camera_cntx.multi_sound_cap_idx++;

            if (g_camera_cntx.multi_sound_cap_idx >= 3)
            {
                g_camera_cntx.multi_sound_cap_idx = 0;
            }

        }
            break;

        case CAMERA_SETTING_SHUTTER_SOUND_OFF:
        default:
            /* do not play sound */
            break;
    }

}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

/*****************************************************************************
*
*  Toggle To Sub State 
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_toggle_to_sub_state
 * DESCRIPTION
 *  enter toggle to sub state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_toggle_to_sub_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
    mmi_camera_free_add_frame_layer();

    ExitCategoryFunction();
    ShowCategory65Screen((PU8) GetString(STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_ON), IMG_GLOBAL_ACTIVATED, NULL);
    g_camera_cntx.is_cat65_show = TRUE;


    gui_start_timer(TOGGLE_POPUP_FADE_TIME, mmi_camera_toggle_to_sub_timeout);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_toggle_to_sub_state
 * DESCRIPTION
 *  exit save confirm state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_toggle_to_sub_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* will display a popup, go out application and re-enter */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }

    gui_cancel_timer(mmi_camera_toggle_to_sub_timeout);

    /* stop anmation on popup category */
    gdi_image_stop_animation_all();

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_toggle_to_sub_timeout
 * DESCRIPTION
 *  exit save confirm state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_to_sub_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter sub preview state */
    CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Toggle To Main State 
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_toggle_to_main_state
 * DESCRIPTION
 *  enter toggle to main state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_toggle_to_main_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* show popup category */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
    mmi_camera_free_add_frame_layer();

    ExitCategoryFunction();
    ShowCategory65Screen((PU8) GetString(STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_OFF), IMG_GLOBAL_ACTIVATED, NULL);
    g_camera_cntx.is_cat65_show = TRUE;


    gui_start_timer(TOGGLE_POPUP_FADE_TIME, mmi_camera_toggle_to_main_timeout);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_toggle_to_main_state
 * DESCRIPTION
 *  exit toggle to main state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_toggle_to_main_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* will display a popup, go out application and re-enter */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }

    gui_cancel_timer(mmi_camera_toggle_to_main_timeout);

    /* stop anmation on popup category */
    gdi_image_stop_animation_all();

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_toggle_to_main_timeout
 * DESCRIPTION
 *  toggle to main popup timeout
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_to_main_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter sub preview state */
    CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_camera_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print debug info */
    CAMERA_TRACE_FUNC_ENTER_SUBLCD();

    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_camera_exit_sublcd_screen);

    g_camera_cntx.is_sublcd_display = TRUE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_camera_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print debug info */
    CAMERA_TRACE_FUNC_EXIT_SUBLCD();

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    /* also stop preview here */
    mmi_camera_sublcd_preview_stop();
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

    g_camera_cntx.is_sublcd_display = FALSE;

    sub_history.entryFuncPtr = mmi_camera_entry_sublcd_screen;
    AddSubLCDHistory(&sub_history);

}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_draw_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_camera_sublcd_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 lcd_width;
    S32 lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id(
        (lcd_width - image_width) >> 1,
        (lcd_height - image_height) >> 1,
        IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
*
*  Sublcd Preview State 
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_sublcd_preview_state
 * DESCRIPTION
 *  entry sublcd preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_sublcd_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw a popup on mainlcd  */
    /* only first time enter sub preview needs to draw main lcd */
    if ((g_camera_cntx.app_prev_state == CAMERA_STATE_EXIT) ||
        (g_camera_cntx.app_prev_state == CAMERA_STATE_TOGGLE_TO_SUB))
    {
        gdi_layer_lock_frame_buffer();

        /* clear fullscreen */
    #ifdef CAMERA_MODULE_WITH_LCD
        gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
    #else 
        gdi_layer_clear(GDI_COLOR_BLACK);
    #endif 

    #if defined(__CAMERA_OSD_HORIZONTAL__)
        mmi_frm_reset_screen_rotation();
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
            mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
        {
            mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
        }
    #endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

    #ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
        force_no_small_screen();
    #endif 
        mmi_camera_free_add_frame_layer();

        ExitCategoryFunction();
        ShowCategory65Screen((PU8) GetString(STR_ID_CAMERA_NOFITY_SELF_CAPTURE_SUBLCD_PREVIEW), IMG_GLOBAL_INFO, NULL);
        g_camera_cntx.is_cat65_show = TRUE;

        /* IMG_GLOBAL_INFO may be an animation, we have to stop it avoid both lcd updating */
        gdi_image_stop_animation_all();
        gdi_layer_unlock_frame_buffer();

        mmi_camera_sublcd_preview_set_key_hdlr();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();

    /* set key handler */
    mmi_camera_sublcd_preview_set_key_hdlr();

    /* set correct lcm rotate */
    /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    if (g_camera_cntx.is_clam_close == TRUE)
    {
        gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
    }
    else
    {
        gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE);
    }
    gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
    /* preview start */
    mmi_camera_sublcd_preview_start();

    /* check if preview function has error */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_sublcd_error_popup();
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_sublcd_preview_state
 * DESCRIPTION
 *  exit sublcd preview state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_sublcd_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit app || toggle to main */

    /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
    gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
    if ((g_camera_cntx.app_next_state == CAMERA_STATE_EXIT) ||
        (g_camera_cntx.app_next_state == CAMERA_STATE_TOGGLE_TO_MAIN))
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_sublcd_preview_stop();

        /* exit popup screen to free drawmanager's resource */
        /* this shall call after preview is stopped, or will cause multiple lcd access */
        if (g_camera_cntx.is_cat65_show)
        {
            ExitCategoryFunction();
        }
    }

    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* 
         * when interrupt happened while clam is close (preview on sub)
         * we will go handling interrupt, when back from interrupt, 
         * we shall force enter sub again to keep clam open close state correct 
         */

        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_set_key_hdlr
 * DESCRIPTION
 *  set sublcd key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_set_key_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_camera_sublcd_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_sublcd_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_sublcd_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }



    SetKeyHandler(mmi_camera_toggle_self_capture, CAMERA_TOGGLE_SELF_CAPTURE_KEY, KEY_EVENT_DOWN);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_start
 * DESCRIPTION
 *  start previewing on sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    S32 sublcd_width;
    S32 sublcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get sublcd base layer handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_dimension(&sublcd_width, &sublcd_height);

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    /* preview parametes */
    camera_setting_data.zoom = mmi_camera_preview_get_zoom_factor();
    camera_setting_data.wb = camera_wb_command_map[g_camera_cntx.setting.wb];
    camera_setting_data.ev = camera_ev_command_map[g_camera_cntx.setting.ev];
    camera_setting_data.banding = camera_banding_command_map[g_camera_cntx.setting.banding];
    camera_setting_data.flash = camera_flash_command_map[g_camera_cntx.setting.flash];
    camera_setting_data.ae_meter = camera_ae_meter_command_map[g_camera_cntx.setting.ae_meter];
    camera_setting_data.iso = camera_iso_command_map[g_camera_cntx.setting.iso];
    camera_setting_data.night = g_camera_cntx.setting.night;
    camera_setting_data.dsc_mode = camera_dsc_mode_command_map[g_camera_cntx.setting.dsc_mode];

    /* effect */
    camera_setting_data.effect = camera_effect_command_map[g_camera_cntx.setting.effect];
    camera_setting_data.brightness = 128;
    camera_setting_data.saturation = 128;
    camera_setting_data.contrast = 128;
    camera_setting_data.hue = 0;

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_1)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[0];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[0];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[0];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[0];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ */ 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_2)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[1];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[1];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[1];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[1];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ */ 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_3)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[2];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[2];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[2];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[2];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ */ /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_32__ */

    /* preview size is sublcd size */
    camera_setting_data.preview_width = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH;
    camera_setting_data.preview_height = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT;

    /* capture parameters */
    camera_setting_data.image_qty = camera_image_qty_command_map[g_camera_cntx.setting.image_qty];
    camera_setting_data.image_width = g_camera_cntx.image_width;
    camera_setting_data.image_height = g_camera_cntx.image_height;

    /* preview on sublcd */
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_SUBLCD;

    #ifdef __CAMERA_AUTOFOCUS__
        g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH/2;
        g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT/2;
        g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x = 0;
        g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y = 0;
        g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x = 0;
        g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y = 0;
        g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x = 0;
        g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y = 0;
        g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x = 0;
        g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y = 0;
    #endif /* __CAMERA_AUTOFOCUS__ */ 


    if (g_camera_cntx.is_clam_close == TRUE)
    {
        camera_setting_data.preview_rotate = CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE;
        camera_setting_data.lcm_rotate = CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE;
    }
    else
    {
        camera_setting_data.preview_rotate = CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE;
        camera_setting_data.lcm_rotate = CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE;
    }

    camera_setting_data.continue_capture = g_camera_cntx.is_continue_capture;

    camera_setting_data.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
    /* set sublcd's layer info to lcd driver by calling gdi_layer_set_blt_layer() */
    /* set layer for preview */
    mmi_camera_sublcd_preview_set_blt_layer(TRUE);  /* TRUE == Preview */

    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();

    camera_preview_data.preview_layer_handle = g_camera_cntx.sublcd_base_layer_handle;
    camera_preview_data.preview_wnd_offset_x = 0;
    camera_preview_data.preview_wnd_offset_y = 0;
    camera_preview_data.preview_wnd_width = sublcd_width;
    camera_preview_data.preview_wnd_height = sublcd_height;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = CAMEAR_BG_TRASN_COLOR;/* this value is use only CAMERA_MODULE_WITH_LCD */
    camera_preview_data.is_tvout = FALSE;
    camera_preview_data.xenon_flash_status_callback = NULL;

    /* start preview */
    g_camera_cntx.last_error = mdi_camera_preview_start(
                                &camera_preview_data,
                                &camera_setting_data);

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_stop
 * DESCRIPTION
 *  stop previewing on sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_preview_stop();

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_set_blt_layer
 * DESCRIPTION
 *  set blt layer based on current status
 * PARAMETERS
 *  is_previewing       [IN]        Is preview flag
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_set_blt_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently no function, reserve it when sublcd will use multi-layer */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_set_blt_layer(g_camera_cntx.sublcd_base_layer_handle, 0, 0, 0);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_lsk_press
 * DESCRIPTION
 *  stop sublcd preview then mimic softkey press.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function will stop sublcd preview when soft key is down */
    /* if not stop sublcd preview first, mainlcd will draw softkey down and cause driver assert */

    if ((g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_CONTSHOT) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_COUNTDOWN))
    {
        mmi_camera_sublcd_preview_stop();
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        gui_cancel_timer(mmi_camera_sublcd_countdown_cyclic);
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_rsk_press
 * DESCRIPTION
 *  stop sublcd preview then mimic softkey press.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function will stop sublcd preview when soft key is down */
    /* if not stop sublcd preview first, mainlcd will draw softkey down and cause driver assert */
    /* if is preview on sub and RSK pressm, has to stop preview first then darw on Main */

    if ((g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_CONTSHOT) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_COUNTDOWN))
    {
        mmi_camera_sublcd_preview_stop();
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        gui_cancel_timer(mmi_camera_sublcd_countdown_cyclic);
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_lsk_release
 * DESCRIPTION
 *  stop sublcd preview then mimic softkey press.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_entry_option_menu_screen();
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_preview_rsk_release
 * DESCRIPTION
 *  stop sublcd preview then mimic softkey press.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Countdown State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_sublcd_countdown_state
 * DESCRIPTION
 *  entry count down state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_sublcd_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

    /* init countdown para */
    switch (g_camera_cntx.setting.delay_timer)
    {
        case CAMERA_SETTING_DELAY_TIMER_1:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_1_DURATION * 1000;
        }
            break;

        case CAMERA_SETTING_DELAY_TIMER_2:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_2_DURATION * 1000;
        }
            break;

        case CAMERA_SETTING_DELAY_TIMER_3:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_3_DURATION * 1000;
        }
            break;

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;
    }

    #ifdef __COUNTDOWN_USING_MMA__
    mmi_camera_init_countdown_mma();
    #endif

    /* start count down */
    mmi_camera_sublcd_countdown_cyclic();

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_sublcd_countdown_state
 * DESCRIPTION
 *  entry count down state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_sublcd_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop countdown timer */
    gui_cancel_timer(mmi_camera_sublcd_countdown_stop_LED);
    mmi_camera_sublcd_countdown_stop_LED();
    gui_cancel_timer(mmi_camera_sublcd_countdown_cyclic);
    #ifdef __COUNTDOWN_USING_MMA__
        gui_cancel_timer(mmi_camera_capture);
        gui_cancel_timer(mmi_camera_deinit_countdown_mma);
    #endif

    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
    #ifdef __COUNTDOWN_USING_MMA__
        if (g_camera_cntx.multi_sound_countdown != 0 && g_camera_cntx.multi_sound_dummy_bg != 0)
        {
            mmi_camera_deinit_countdown_mma();
        }
    #endif

        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_sublcd_preview_stop();

        /* 
         * when interrupt happened while clam is close (preview on sub)
         * we will go handling interrupt, when back from interrupt, 
         * we shall force enter sub again to keep clam open close state correct 
         */
        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_countdown_cyclic
 * DESCRIPTION
 *  count down delay timer cyclic loop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_countdown_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* countdonw duration and freq */
    if (g_camera_cntx.capture_countdown > 6000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }

        gui_start_timer(100, mmi_camera_sublcd_countdown_stop_LED);
        gui_start_timer(1000, mmi_camera_sublcd_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 1000;

        {
            #ifdef __COUNTDOWN_USING_MMA__
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
            #else
                mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                                    MDI_FORMAT_DVI_ADPCM,
                                                    DEVICE_AUDIO_PLAY_ONCE,
                                                    NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
            #endif
        }
    }
    else if (g_camera_cntx.capture_countdown > 2000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }

        gui_start_timer(100, mmi_camera_sublcd_countdown_stop_LED);
        gui_start_timer(500, mmi_camera_sublcd_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 500;

        {
            #ifdef __COUNTDOWN_USING_MMA__
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
            #else
                mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                                    MDI_FORMAT_DVI_ADPCM,
                                                    DEVICE_AUDIO_PLAY_ONCE,
                                                    NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
            #endif
        }
    }
    else if (g_camera_cntx.capture_countdown >= 0)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }

        gui_start_timer(100, mmi_camera_sublcd_countdown_stop_LED);
        gui_start_timer(200, mmi_camera_sublcd_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 200;

        {
            #ifdef __COUNTDOWN_USING_MMA__
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
            #else
                mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                                                    MDI_FORMAT_DVI_ADPCM,
                                                    DEVICE_AUDIO_PLAY_ONCE,
                                                    NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
            #endif
        }

    }
    else
    {
    #ifdef __COUNTDOWN_USING_MMA__
        gui_start_timer(200, mmi_camera_deinit_countdown_mma);
        gui_start_timer(300, mmi_camera_sublcd_capture);
    #else
        mmi_camera_sublcd_capture();
    #endif
        return;
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_countdown_stop_LED
 * DESCRIPTION
 *  stop count down LED
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_countdown_stop_LED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Cont Shot State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_sublcd_contshot_state
 * DESCRIPTION
 *  entry contshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_sublcd_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

    /* init count down para */
    switch (g_camera_cntx.setting.cont_shot)
    {
        case CAMERA_SETTING_CONT_SHOT_OFF:
        {
            g_camera_cntx.cont_shot_total_count = 1;
            g_camera_cntx.cont_shot_count = 0;
        }
            break;

        case CAMERA_SETTING_CONT_SHOT_1:
        {
            g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_1_COUNT;
            g_camera_cntx.cont_shot_count = 0;
        }
            break;

    #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
        case CAMERA_SETTING_CONT_SHOT_2:
        {
            g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_2_COUNT;
            g_camera_cntx.cont_shot_count = 0;
        }
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_2__ */ 
    #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
        case CAMERA_SETTING_CONT_SHOT_3:
        {
            g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_3_COUNT;
            g_camera_cntx.cont_shot_count = 0;
        }
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_3__ */ 
    }

    mmi_camera_sublcd_contshot_cyclic();

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_sublcd_contshot_state
 * DESCRIPTION
 *  entry contshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_sublcd_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel contshot timer */
    gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);

    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();

        /* stop previewing */
        mmi_camera_sublcd_preview_stop();

        /* 
         * when interrupt happened while clam is close (preview on sub)
         * we will go handling interrupt, when back from interrupt, 
         * we shall force enter sub again to keep clam open close state correct 
         */

        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_contshot_cyclic
 * DESCRIPTION
 *  cont shot cyclic loop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_contshot_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);

    /* start timer for next shot */
    gui_start_timer(100, mmi_camera_sublcd_contshot_cyclic);

    mmi_camera_turn_on_capture_led_highlight();

    if (g_camera_cntx.cont_shot_count + 1 == g_camera_cntx.cont_shot_total_count)
    {
        g_camera_cntx.is_continue_capture = FALSE;
    }
    else
    {
        g_camera_cntx.is_continue_capture = TRUE;
    }

    g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);

    /* play capture sound after capture */
    mmi_camera_capture_play_sound();

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 

    mmi_camera_turn_off_led_highlight();

    /* captured, previwing is stopped, change blt layer */
    mmi_camera_sublcd_preview_set_blt_layer(FALSE);

    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        g_camera_cntx.is_continue_capture = FALSE;
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        FS_Delete((U16*) buf_filename);
        mmi_camera_restore_filename_seq_no();
        mmi_camera_display_sublcd_error_popup();
        return;
    }

    g_camera_cntx.cont_shot_count++;

    /* terminate condition */
    if (g_camera_cntx.cont_shot_count >= g_camera_cntx.cont_shot_total_count)
    {
        /* stop timer */
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
        return;
    }
    else
    {
        /* change blt layer for previwing */
        mmi_camera_sublcd_preview_set_blt_layer(TRUE);

        /* config rotate of preview layer, only ISP_SUPPORT need */
    #if defined(ISP_SUPPORT)
        gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);

        if (g_camera_cntx.is_clam_close == TRUE)
        {
            gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
        }
        else
        {
            gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE);
        }

        gdi_layer_pop_and_restore_active();
    #endif /* defined(ISP_SUPPORT) */ 

        mmi_camera_sublcd_preview_start();

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            g_camera_cntx.is_continue_capture = FALSE;
            /* stop timer */
            gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
            mmi_camera_display_sublcd_error_popup();
            return;
        }
    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Capture Burst State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_sublcd_burstshot_state
 * DESCRIPTION
 *  entry contshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_entry_sublcd_burstshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

    mmi_camera_turn_on_capture_led_highlight();

    g_camera_cntx.is_capturing = TRUE;

#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)

    if (g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
    {
        /* start multi_channel sound, for capture sound effect */

        /* open and play a dummy midi at backgroup - this is a must do to play multi-channel sound */
        g_camera_cntx.multi_sound_dummy_bg = mdi_audio_mma_open_midi((void*)camera_sound_dummy_bg, CAMERA_SOUND_DUMMY_BG_LEN, 0, NULL);

        mdi_audio_mma_play_midi(g_camera_cntx.multi_sound_dummy_bg);

        g_camera_cntx.multi_sound_cap_idx = 0;

        switch (g_camera_cntx.setting.shutter_sound)
        {
            case CAMERA_SETTING_SHUTTER_SOUND_1:
            {
                g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN, 1, NULL);

                g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN, 1, NULL);

                g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN, 1, NULL);
            }

                break;

            case CAMERA_SETTING_SHUTTER_SOUND_2:
            {
                g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN, 1, NULL);

                g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN, 1, NULL);

                g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN, 1, NULL);
            }
                break;

            case CAMERA_SETTING_SHUTTER_SOUND_3:
            {
                g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN, 1, NULL);

                g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN, 1, NULL);

                g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN, 1, NULL);
            }
                break;
        }
    }

    /* MT6228 support non-blocking burst shot */
    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_non_block_burst_capture_to_memory(
            CAMERA_FEATURE_CONT_SHOT_BURST_COUNT,
            &g_camera_cntx.burst_jpg_data,
            mmi_camera_sublcd_burstshot_capture_result_hdlr);

#else /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    /* burst shot shall play before capture */
    mmi_camera_capture_play_sound();

    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_burst_capture_to_memory(CAMERA_FEATURE_CONT_SHOT_BURST_COUNT, &g_camera_cntx.burst_jpg_data);

    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 

    /* stop led */
    mmi_camera_turn_off_led_highlight();

    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        playRequestedTone(WARNING_TONE);
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
    }
    else
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_BURSTSHOT_SAVING);
    }

#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_sublcd_burstshot_state
 * DESCRIPTION
 *  entry contshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_exit_sublcd_burstshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop dummy bg midi for multi-channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)

    if (g_camera_cntx.is_capturing)
    {
        mdi_camera_stop_non_block_burst_capture();
    }

    if (g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
    {
        mdi_audio_mma_stop_midi(g_camera_cntx.multi_sound_dummy_bg);
        mdi_audio_mma_close_midi(g_camera_cntx.multi_sound_dummy_bg);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture0);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture0);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture1);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture1);

        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture2);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture2);

        g_camera_cntx.multi_sound_capture0 = 0;
        g_camera_cntx.multi_sound_capture1 = 0;
        g_camera_cntx.multi_sound_capture2 = 0;
        g_camera_cntx.multi_sound_dummy_bg = 0;
    }

#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
    }

    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* 
         * when interrupt happened while clam is close (preview on sub)
         * we will go handling interrupt, when back from interrupt, 
         * we shall force enter sub again to keep clam open close state correct 
         */

        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }

}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_burstshot_capture_result_hdlr
 * DESCRIPTION
 *  no block burst shot capture result handler
 * PARAMETERS
 *  ret                 [IN]        
 *  captured_count      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_sublcd_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if camera is in EXIT state by interrup, just do nothing */
    if (g_camera_cntx.app_state == CAMERA_STATE_EXIT)
    {
        return;
    }

    /* capture count start from 1 */
    mmi_camera_capture_play_multi_channel_sound();

    if (ret >= 0)
    {
        /* no error happened */
        if (captured_count == CAMERA_FEATURE_CONT_SHOT_BURST_COUNT)
        {
            g_camera_cntx.is_capturing = FALSE;
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_BURSTSHOT_SAVING);
            return;
        }
    }
    else
    {
        g_camera_cntx.is_capturing = FALSE;
        playRequestedTone(WARNING_TONE);
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
    }
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ /* __CAMERA_FEATURE_SELF_CAPTURE__ & __CAMERA_FEATURE_CONT_SHOT_BURST__ & __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__ */

/*****************************************************************************
*
*  Sublcd Save Burstshot State
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_sublcd_burstshot_saving_state
 * DESCRIPTION
 *  entry sublcd save burstshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_entry_sublcd_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    S32 lcd_width;
    S32 lcd_height;
    gdi_handle layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_UP);

    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }

    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }

    /* drwa saving string */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_reset_text_clip();

    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    gdi_layer_get_active(&layer_handle);

    str_ptr = (PS8) GetString(STR_ID_CAMERA_NOTIFY_SAVING);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    mmi_camera_draw_style_text(
        str_ptr,
        (lcd_width - str_width) >> 1,
        (lcd_height - str_height) >> 1,
        &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);

    gdi_layer_blt(layer_handle, 0, 0, 0, 0, 0, lcd_width - 1, lcd_height - 1);

    /* restore to main */
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    /* start save burst shot */
    g_camera_cntx.burst_save_index = 0;
    mmi_camera_sublcd_burstshot_saving_cyclic();
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_sublcd_burstshot_saving_state
 * DESCRIPTION
 *  exit sublcd save burstshot state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_exit_sublcd_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_sublcd_burstshot_saving_cyclic);
    gdi_image_stop_animation_all();

    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* 
         * when interrupt happened while clam is close (preview on sub)
         * we will go handling interrupt, when back from interrupt, 
         * we shall force enter sub again to keep clam open close state correct 
         */

        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }

}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_burstshot_saving_cyclic
 * DESCRIPTION
 *  loop to save sublcd burstshot image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_sublcd_burstshot_saving_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 image_buf_ptr;
    U32 image_buf_size;
    U32 written;
    FS_HANDLE file_handle;

#ifdef EXIF_SUPPORT
    U32 size_of_exif_info = 0;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);

    /* start timer for next shot */
    gui_start_timer(100, mmi_camera_sublcd_burstshot_saving_cyclic);

    /* save burst shot image */
    image_buf_ptr = (PU8) g_camera_cntx.burst_jpg_data.file_address[g_camera_cntx.burst_save_index];
    image_buf_size = (U32) g_camera_cntx.burst_jpg_data.file_size[g_camera_cntx.burst_save_index];

    file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);

    if (file_handle > 0)
    {
    #ifdef EXIF_SUPPORT
        /* eixf_burst_mode_fill_header(kal_uint8* Buffer,kal_uint32 BufferOffset); */
    #if defined(__MTK_TARGET__)
        size_of_exif_info = eixf_burst_mode_fill_header(image_buf_ptr);
    #endif 
        image_buf_size += size_of_exif_info;
        image_buf_ptr -= size_of_exif_info;
    #endif /* EXIF_SUPPORT */ 

        FS_Write(file_handle, (void*)image_buf_ptr, image_buf_size, (U32*) & written);
        FS_Close(file_handle);

        /* cant write in whole file, must be disk full */
        if (image_buf_size != written)
        {
            /* delete the file that is not save complete */
            FS_Delete((U16*) buf_filename);

            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;

            mmi_camera_restore_filename_seq_no();
            /* this is not serious error, will play a notify tone */
            /* it will directly re-entry sub preview state */
            mmi_camera_display_sublcd_error_popup();

            return;
        }
    }
    else
    {
        if (file_handle == FS_DISK_FULL)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_ROOT_DIR_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
        }
        else if (file_handle == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
        }
        else
        {
            g_camera_cntx.last_error = CAMERA_ERR_SAVE_FAIL;
        }

        mmi_camera_restore_filename_seq_no();
        /* this is not serious error, will play a notify tone */
        /* it will directly re-entry sub preview state */
        mmi_camera_display_sublcd_error_popup();
        return;
    }

    /* teminate condition */
    if (g_camera_cntx.burst_save_index >= CAMERA_FEATURE_CONT_SHOT_BURST_COUNT - 1)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
        return;
    }

    /* increase index */
    g_camera_cntx.burst_save_index++;

}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 

/***************************************************************************
*
*  Sublcd Capture 
*
***************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_capture
 * DESCRIPTION
 *  capture photo
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;    
    U32 buf_size;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.setting.cont_shot)
    {

        case CAMERA_SETTING_CONT_SHOT_OFF:
            mmi_camera_turn_on_capture_led_highlight();

            /* since user may capture when clam close, and open clam to view the captured image */
            /* disable clam open action */
            g_camera_cntx.is_dis_clam_open = TRUE;

        #ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
            /* Calculate the image buffer size */
            image_region_width = g_camera_cntx.osd_UI_device_width;
            image_region_height = g_camera_cntx.osd_UI_device_height;
            image_region_offset_x = 0;
            image_region_offset_y = 0;

            if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
            {
                image_region_height -= (MMI_title_height + MMI_title_y);
                image_region_offset_y += (MMI_title_height + MMI_title_y);
            }

            if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
            {
                image_region_height -= (MMI_button_bar_height);
            }

            if ((image_region_width >= g_camera_cntx.image_width) && (image_region_height >= g_camera_cntx.image_height))
            {
                resized_width = g_camera_cntx.image_width;
                resized_height = g_camera_cntx.image_height;
            }
            else
            {
                gdi_image_util_fit_bbox(
                    image_region_width,
                    image_region_height,
                    g_camera_cntx.image_width,
                    g_camera_cntx.image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

            }

            buf_size = (((resized_width *resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);

            ASSERT(g_camera_cntx.direct_couple_buffer!=NULL);

            g_camera_cntx.last_error
                = mdi_camera_capture_to_memory_direct_couple(&g_camera_cntx.capture_buf_ptr, 
                                                             &g_camera_cntx.capture_size,
                                                             (U32) g_camera_cntx.direct_couple_buffer, 
                                                             buf_size, 
                                                             resized_width,
                                                             resized_height );
            g_camera_cntx.is_direct_couple = TRUE;

        #else
            g_camera_cntx.last_error
                = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size);
        #endif

            /* play capture sound after capture */
            mmi_camera_capture_play_sound();

            mmi_camera_sublcd_draw_icon();

            mmi_camera_turn_off_led_highlight();
            CAMERA_ENTER_STATE(CAMERA_STATE_SAVE_CONFIRM);

            break;

        case CAMERA_SETTING_CONT_SHOT_1:

    #ifdef __CAMERA_FEATURE_CONT_SHOT_2__
        case CAMERA_SETTING_CONT_SHOT_2:
    #endif 

    #ifdef __CAMERA_FEATURE_CONT_SHOT_3__
        case CAMERA_SETTING_CONT_SHOT_3:
    #endif 
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_CONTSHOT);
            return;
        }
            break;

    #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        case CAMERA_SETTING_CONT_SHOT_BURST:
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_BURSTSHOT);
            return;
        }
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        case CAMERA_SETTING_CONT_SHOT_TILE:
        {
            mmi_camera_sublcd_tileshot_capture();
            return;
        }
            break;
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

        default:
            /* restore default value */
            mmi_camera_restore_setting();
            break;

    }

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_sublcd_capture_button_press
 * DESCRIPTION
 *  capture button presse
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_capture_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* capture only works is camera is ready, otherwise will ignore this action */
    if (mdi_camera_is_ready_to_capture() == TRUE)
    {
        /* if not self timer, capture the image */
        if (g_camera_cntx.setting.delay_timer == CAMERA_SETTING_DELAY_TIMER_OFF)
        {
            mmi_camera_sublcd_capture();
        }
        else
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_COUNTDOWN);
        }
    }

    /* flush key event */
    ClearKeyEvents();
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Utility drawing functions
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_draw_style_text
 * DESCRIPTION
 *  draw style text
 * PARAMETERS
 *  str             [IN]        String
 *  offset_x        [IN]        Offset x
 *  offset_y        [IN]        Offset y
 *  style_txt       [IN]        Text style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, camera_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    if (style_txt->style == CAMERA_TEXT_STYLE_NORMAL)
    {

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else if (style_txt->style == CAMERA_TEXT_STYLE_BORDER)
    {
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_bordered_text((UI_string_type) str);
    }
    else if (style_txt->style == CAMERA_TEXT_STYLE_SHADOW)
    {
        gui_move_text_cursor(offset_x + 1, offset_y + 1);
        gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_text((UI_string_type) str);

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else
    {
        MMI_ASSERT(0);
    }

}

/*****************************************************************************
*
*  Touch Screen Support
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    /* other screen use generic touch screen handler */
    if ((g_camera_cntx.is_fullscreen) || (!g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey))
    {
        /* LSK */
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk) == MMI_TRUE)
        {
            switch (g_camera_cntx.app_state)
            {
                    /* main lcd */
                case CAMERA_STATE_PREVIEW:
                case CAMERA_STATE_COUNTDOWN:
                case CAMERA_STATE_CONTSHOT:
                    mmi_camera_preview_lsk_press();
                    break;
                case CAMERA_STATE_BURSTSHOT:
            #if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                    mmi_camera_preview_lsk_press();
            #endif 
                    break;

                case CAMERA_STATE_SAVE_CONFIRM:
                    mmi_camera_save_confirm_lsk_press();
                    break;

                case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
            #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                    mmi_camera_burstshot_save_confirm_lsk_press();
            #endif 
                    break;

                    /* sub lcd */
                case CAMERA_STATE_SUB_PREVIEW:
                case CAMERA_STATE_SUB_COUNTDOWN:
                case CAMERA_STATE_SUB_CONTSHOT:
                case CAMERA_STATE_SUB_BURSTSHOT:
                case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
            #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                    mmi_camera_sublcd_preview_lsk_press();
            #endif 
                    break;
            }

            g_camera_cntx.touch_object = CAMERA_TOUCH_LSK;
            return;
        }

        /* RSK */
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk) == MMI_TRUE)
        {
            switch (g_camera_cntx.app_state)
            {
                    /* main lcd */
                case CAMERA_STATE_PREVIEW:
                case CAMERA_STATE_COUNTDOWN:
                case CAMERA_STATE_CONTSHOT:
                    mmi_camera_preview_rsk_press();
                    break;
                case CAMERA_STATE_BURSTSHOT:
            #if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                    mmi_camera_preview_rsk_press();
            #endif 
                    break;
                case CAMERA_STATE_SAVE_CONFIRM:
                    mmi_camera_save_confirm_rsk_press();
                    break;

                case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
            #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                    mmi_camera_burstshot_save_confirm_rsk_press();
            #endif 
                    break;

                    /* sub lcd */
                case CAMERA_STATE_SUB_PREVIEW:
                case CAMERA_STATE_SUB_COUNTDOWN:
                case CAMERA_STATE_SUB_CONTSHOT:
                case CAMERA_STATE_SUB_BURSTSHOT:
                case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
            #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                    mmi_camera_sublcd_preview_rsk_press();
            #endif 
                    break;
            }
            g_camera_cntx.touch_object = CAMERA_TOUCH_RSK;
            return;
        }

    }
    else
    {
        if (wgui_test_lsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked lsk */
            mmi_camera_preview_lsk_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_LSK;
            return;
        }
        if (wgui_test_rsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked rsk */
            mmi_camera_preview_rsk_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_RSK;
            return;
        }
    }
    /* while af is calculating, disable touch panel */
#ifdef __CAMERA_AUTOFOCUS__
    if (g_camera_cntx.af_state == AF_CALCULATE || g_camera_cntx.is_autofocus_pressed == TRUE)
    {
        g_camera_cntx.touch_object = CAMERA_TOUCH_NONE;
        return;
    }
#endif /* __CAMERA_AUTOFOCUS__ */ 

    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW && g_camera_cntx.is_capturing == FALSE)
    {
        /* osd test */
#define OSD_ICON_TOUCH_TEST(a,A)                                                             \
      do {                                                                                         \
         if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                    \
         {                                                                                         \
            if(mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_##a##) == MMI_TRUE)\
            {                                                                                      \
               mmi_camera_preview_##a##_hotkey_press();                                            \
               g_camera_cntx.touch_object = CAMERA_TOUCH_##A;                                      \
               return;                                                                             \
            }                                                                                      \
         }                                                                                         \
      } while(0);

        if (!g_camera_cntx.is_hide_osd)
        {

        #ifdef __CAMERA_FEATURE_EFFECT__
            OSD_ICON_TOUCH_TEST(effect, EFFECT);
        #endif 

        #ifdef __CAMERA_FEATURE_WB__
            OSD_ICON_TOUCH_TEST(wb, WB);
        #endif 

        #ifdef __CAMERA_FEATURE_FLASH__
            OSD_ICON_TOUCH_TEST(flash, FLASH);
        #endif 

        #ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
            OSD_ICON_TOUCH_TEST(led_highlight, LED_HIGHLIGHT);
        #endif 

        #ifdef __CAMERA_FEATURE_NIGHT__
            OSD_ICON_TOUCH_TEST(night, NIGHT);
        #endif 

	#if defined(DOUBLE_CAMERA_SUPPORT)
	//Huyanwei Add It 
	if(mmi_double_cam_icon_press(pos.x, pos.y))
	{	 
		mmi_camera_preview_double_cam_key_press();
		return;
	}		
	#endif


            OSD_ICON_TOUCH_TEST(image_size, IMAGE_SIZE);
            OSD_ICON_TOUCH_TEST(image_qty, IMAGE_QTY);

        #ifdef __CAMERA_FEATURE_CONT_SHOT__
            if (g_camera_cntx.is_external_request == FALSE)
            {
                /* !for External Request */
                OSD_ICON_TOUCH_TEST(cont_shot, CONT_SHOT);
            }
        #endif 

        #ifdef __CAMERA_FEATURE_DELAY_TIMER__
            OSD_ICON_TOUCH_TEST(delay_timer, DELAY_TIMER);
        #endif 

        #ifdef __CAMERA_DSC_MODE__
            OSD_ICON_TOUCH_TEST(dsc_mode, DSC_MODE);
        #endif 

        #ifdef __CAMERA_FEATURE_ISO_SUPPORT__
            #ifdef __CAMERA_DSC_MODE_NIGHT__
            if (g_camera_cntx.active_camera_osd_ptr->iso.is_show && g_camera_cntx.setting.dsc_mode != CAMERA_SETTING_DSC_MODE_NIGHT)
            #else
            if (g_camera_cntx.active_camera_osd_ptr->iso.is_show)
            #endif            
            {
                if(mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_iso) == MMI_TRUE)
                {
                   mmi_camera_preview_iso_hotkey_press();
                   g_camera_cntx.touch_object = CAMERA_TOUCH_ISO;
                   return;
                }
            }
        #endif 

        #ifdef __CAMERA_FEATURE_AE_METER__
            OSD_ICON_TOUCH_TEST(ae_meter, AE_METER);
        #endif 

        #ifdef __CAMERA_AUTOFOCUS_MODE__
            OSD_ICON_TOUCH_TEST(af_mode, AF_MODE);
        #endif 

        #ifdef __CAMERA_AUTOFOCUS_METERING__
            OSD_ICON_TOUCH_TEST(af_meter, AF_METER);
        #endif 

        #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_mf_toggle) == MMI_TRUE)
            {
                mmi_camera_toggle_updown_key();
                g_camera_cntx.touch_object = CAMERA_TOUCH_ZOOM_MF_TOGGLE;
                return;
            }
        #endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

        #ifdef __CAMERA_FEATURE_STORAGE__
            OSD_ICON_TOUCH_TEST(storage, STORAGE);
        #endif 

            /* ev inc test */
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_inc) == MMI_TRUE)
            {
                mmi_camera_preview_ev_inc_key_press();
                g_camera_cntx.touch_object = CAMERA_TOUCH_EV_INC;
                return;
            }

            /* ev dec test */
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_dec) == MMI_TRUE)
            {
                mmi_camera_preview_ev_dec_key_press();
                g_camera_cntx.touch_object = CAMERA_TOUCH_EV_DEC;
                return;
            }

            /* zoom inc test */
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_inc) == MMI_TRUE)
            {
                mmi_camera_preview_up_arrow_press();
                g_camera_cntx.touch_object = CAMERA_TOUCH_ZOOM_INC;
                return;
            }

            /* zoom dec test */
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_dec) == MMI_TRUE)
            {
                mmi_camera_preview_down_arrow_press();
                g_camera_cntx.touch_object = CAMERA_TOUCH_ZOOM_DEC;
                return;
            }
        }

        /* capture */
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_capture) == MMI_TRUE)
        {
        #ifdef __MMI_CAMERA_AF_TEST__
            mmi_camera_af_test();
        #else 
            mmi_camera_capture_button_press();
        #endif 
            g_camera_cntx.touch_object = CAMERA_TOUCH_CAPTURE;
            return;
        }
    }
#if defined(__MMI_CAMERA_MMS_SUPPORT__)
    else if (g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM && (g_camera_cntx.is_mms_ready == TRUE) &&
             mmi_bootup_get_active_flight_mode() == 0)
    {
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_mms_icon) == MMI_TRUE)
        {
            mmi_camera_save_confirm_send_to_mms_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_MMS_ICON;
        }
        return;
    }
#endif /* defined(__MMI_CAMERA_MMS_SUPPORT__) */ 

    g_camera_cntx.touch_object = CAMERA_TOUCH_NONE;

}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch (g_camera_cntx.touch_object)
    {
        case CAMERA_TOUCH_LSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk) == MMI_TRUE)
            {
                switch (g_camera_cntx.app_state)
                {
                        /* main lcd */
                    case CAMERA_STATE_PREVIEW:
                    case CAMERA_STATE_COUNTDOWN:
                    case CAMERA_STATE_CONTSHOT:
                        mmi_camera_preview_lsk_release();
                        break;
                    case CAMERA_STATE_BURSTSHOT:
                #if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                        mmi_camera_preview_lsk_release();
                #endif 
                        break;

                    case CAMERA_STATE_SAVE_CONFIRM:
                        mmi_camera_save_confirm_lsk_release();
                        break;

                    case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
                #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                        mmi_camera_burstshot_save_confirm_lsk_release();
                #endif 
                        break;

                        /* sub lcd */
                    case CAMERA_STATE_SUB_PREVIEW:
                    case CAMERA_STATE_SUB_COUNTDOWN:
                    case CAMERA_STATE_SUB_CONTSHOT:
                    case CAMERA_STATE_SUB_BURSTSHOT:
                    case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
                #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                        mmi_camera_sublcd_preview_rsk_release();
                #endif 
                        break;
                }
            }
            else if (g_camera_cntx.is_lsk_pressed == TRUE)
            {
                g_camera_cntx.is_lsk_pressed = FALSE;
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
            }
            break;

        case CAMERA_TOUCH_RSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk) == MMI_TRUE)
            {
                switch (g_camera_cntx.app_state)
                {
                        /* main lcd */
                    case CAMERA_STATE_PREVIEW:
                    case CAMERA_STATE_COUNTDOWN:
                    case CAMERA_STATE_CONTSHOT:
                        mmi_camera_preview_rsk_release();
                        break;
                    case CAMERA_STATE_BURSTSHOT:
                #if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                        mmi_camera_preview_rsk_release();
                #endif 
                        break;
                    case CAMERA_STATE_SAVE_CONFIRM:
                        mmi_camera_save_confirm_rsk_release();
                        break;

                    case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
                #ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                        mmi_camera_burstshot_save_confirm_rsk_release();
                #endif 
                        break;

                        /* sub lcd */
                    case CAMERA_STATE_SUB_PREVIEW:
                    case CAMERA_STATE_SUB_COUNTDOWN:
                    case CAMERA_STATE_SUB_CONTSHOT:
                    case CAMERA_STATE_SUB_BURSTSHOT:
                    case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
                #ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                        mmi_camera_sublcd_preview_lsk_release();
                #endif 
                        break;
                }
            }
            else if (g_camera_cntx.is_rsk_pressed == TRUE)
            {
                g_camera_cntx.is_rsk_pressed = FALSE;
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
            }

            break;

        case CAMERA_TOUCH_EV_INC:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_inc) == MMI_TRUE)
            {
                mmi_camera_preview_ev_inc_key_release();
            }
            break;

        case CAMERA_TOUCH_EV_DEC:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_dec) == MMI_TRUE)
            {
                mmi_camera_preview_ev_dec_key_release();
            }
            break;

        case CAMERA_TOUCH_ZOOM_INC:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_inc) == MMI_TRUE)
            {
                mmi_camera_preview_up_arrow_release();
            }
            break;

        case CAMERA_TOUCH_ZOOM_DEC:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_dec) == MMI_TRUE)
            {
                mmi_camera_preview_down_arrow_release();
            }
            break;
        #if defined(__MMI_CAMERA_MMS_SUPPORT__)
        case CAMERA_TOUCH_MMS_ICON:
            if (g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM && (g_camera_cntx.is_mms_ready == TRUE) &&
                mmi_bootup_get_active_flight_mode() == 0)
            {
                if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_mms_icon) == MMI_TRUE)
                {
                    mmi_camera_save_confirm_send_to_mms_release();
                }
            }
            break;
        #endif /* defined(__MMI_CAMERA_MMS_SUPPORT__) */ 

        default:
            break;
    }

}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL softkey_pressed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey_pressed = FALSE;
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        S32 tmp;

        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }

    switch (g_camera_cntx.touch_object)
    {
        case CAMERA_TOUCH_LSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }

            if (softkey_pressed != g_camera_cntx.is_lsk_pressed)
            {
                g_camera_cntx.is_lsk_pressed = softkey_pressed;
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
            }
            break;

        case CAMERA_TOUCH_RSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }

            if (softkey_pressed != g_camera_cntx.is_rsk_pressed)
            {
                g_camera_cntx.is_rsk_pressed = softkey_pressed;
                mmi_camera_preview_draw_osd();
                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
            }
            break;

        case CAMERA_TOUCH_EV_INC:
            if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_inc))
            {
                /* move out, treat as key release */
                mmi_camera_preview_ev_inc_key_release();
            }
            break;

        case CAMERA_TOUCH_EV_DEC:
            if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_dec))
            {
                /* move out, treat as key release */
                mmi_camera_preview_ev_dec_key_release();
            }
            break;

        case CAMERA_TOUCH_ZOOM_INC:
            if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_inc))
            {
                /* move out, treat as key release */
                mmi_camera_preview_up_arrow_release();
            }
            break;

        case CAMERA_TOUCH_ZOOM_DEC:
            if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_dec))
            {
                /* move out, treat as key release */
                mmi_camera_preview_down_arrow_release();
            }
            break;
        #if defined(__MMI_CAMERA_MMS_SUPPORT__)
        case CAMERA_TOUCH_MMS_ICON:
            if (g_camera_cntx.app_state == CAMERA_STATE_SAVE_CONFIRM && (g_camera_cntx.is_mms_ready == TRUE) &&
                mmi_bootup_get_active_flight_mode() == 0)
            {
                g_camera_cntx.is_mms_icon_pressed = FALSE;
                mmi_camera_preview_draw_osd();

                gdi_layer_blt_previous(
                    0,
                    0,
                    g_camera_cntx.base_UI_device_width - 1,
                    g_camera_cntx.base_UI_device_height - 1);
            }
            break;
        #endif /* defined(__MMI_CAMERA_MMS_SUPPORT__) */ 

    }
}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_touch_scr_hit_test
 * DESCRIPTION
 *  test if is within touch region
 * PARAMETERS
 *  pos_x           [IN]        Position x
 *  pos_y           [IN]        Position y
 *  touch_obj       [?]         
 *  touch(?)        [IN]        Touch object structure
 * RETURNS
 * BOOL
 *****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static BOOL mmi_camera_touch_scr_hit_test(S32 pos_x, S32 pos_y, camera_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

/*****************************************************************************
*
*  Screen Snapshot
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_scr_snapshot
 * DESCRIPTION
 *  snapshot screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__
void mmi_camera_scr_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_camera_cntx.is_screen_snapshot) ||               /* capture screen shot */
        (g_camera_cntx.app_state != CAMERA_STATE_EXIT) ||   /* in camera app */
        (mmi_vdorec_is_in_app()) ||                         /* in video recorder */
        (mmi_vdoply_is_in_app()))                           /* in video player */
    {
        return;
    }

    mmi_camera_entry_scr_snapshot_screen();

}
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_scr_snapshot_screen
 * DESCRIPTION
 *  entry  screen snapshot screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__
static void mmi_camera_entry_scr_snapshot_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_layer;
    S8 storage_filepath[FMGR_PATH_BUFFER_SIZE];
    S8 storage_filename[FMGR_PATH_BUFFER_SIZE];
    U16 cur_storage;
    S32 create_result;
    MDI_RESULT result;
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;
    MMI_ID_TYPE str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_screen_snapshot = TRUE;

    /* enter a new screen, force previous screen leave */
    EntryNewScreen(
        SCR_ID_CAMERA_SCREEN_SNAPSHOT,
        mmi_camera_exit_scr_snapshot_screen,
        NULL,   /* entry function is null, will not add to history by framework */
        NULL);

    /* load Setting */
    mmi_camera_load_setting();

    /* allocate storage path buffer */
    memset(storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);

    /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
    cur_storage = g_imgview_context.storage;

    /* drv is valid, create directory */
    mmi_imgview_get_storage_file_path(storage_filepath);
    create_result = mmi_imgview_create_file_dir(storage_filepath);

    /* create directory error check */
    if (create_result < 0)
    {
        str_id = GetFileSystemErrorString(create_result);
        
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        DisplayPopupRotated(
            (PU8) GetString(str_id),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE,
            g_camera_cntx.osd_rotate);
    #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        DisplayPopup(
            (PU8) GetString(str_id),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
    #endif
        return;
    }


    /* get/store sequentail number */
    ReadValue(NVRAM_SCR_SNAPSHOT_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }
    WriteValue(NVRAM_SCR_SNAPSHOT_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;

    sprintf((PS8) buffer, "SCR%04d", filename_seq_no);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);

    while (1)
    {
        sprintf((PS8) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((PS8) UCS2_alpha, (PS8) buffer);

        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (PS8) L".jpg");

        mmi_ucs2cpy((PS8) storage_filename, (PS8) storage_filepath);
        mmi_ucs2cat((PS8) storage_filename, (PS8) UCS2_testname);

        file_handle = FS_Open((U16*) storage_filename, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            break;
        }

        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count - 1)
        {
            break;
        }
    }

    /* play capture sound */
    mmi_camera_capture_play_sound();

    /* encode layer */
    gdi_layer_get_base_handle(&base_layer);
    result = mdi_camera_encode_layer_to_jpeg(base_layer, storage_filename);

    switch (result)
    {
        case MDI_RES_CAMERA_SUCCEED:
            /* use storage_filepath as tmp buffer */
            mmi_ucs2cpy(storage_filepath, (PS8) GetString(STR_ID_CAMERA_NOTIFY_SCREEN_CAPTURED));
            mmi_ucs2cat(storage_filepath, (PS8) L"\n");
            mmi_ucs2cat(storage_filepath, (PS8) UCS2_testname);
        #if defined(__CAMERA_OSD_HORIZONTAL__)
            DisplayPopupRotated((PU8) storage_filepath, IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE,g_camera_cntx.osd_rotate);
        #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
            DisplayPopup((PU8) storage_filepath, IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
        #endif
            return;
            break;

        default:
            str_id = mmi_camera_get_error_string_by_error_enum(result);
        #if defined(__CAMERA_OSD_HORIZONTAL__)
            DisplayPopupRotated((PU8) GetString(str_id), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE,g_camera_cntx.osd_rotate);
        #else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
            DisplayPopup((PU8) GetString(str_id), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
        #endif
            return;
            break;
    }

}
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_exit_scr_snapshot_screen
 * DESCRIPTION
 *  exit  screen snapshot screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__
static void mmi_camera_exit_scr_snapshot_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_screen_snapshot = FALSE;
}
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 

#ifdef __MMI_CAMERA_MMS_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_send_to_mms_press
 * DESCRIPTION
 *  press send_to_mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_send_to_mms_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_mms_icon_pressed = TRUE;
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_confirm_send_to_mms_release
 * DESCRIPTION
 *  release send_to_mms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_confirm_send_to_mms_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_mms_icon_pressed = FALSE;
    mmi_camera_preview_draw_osd();

    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    mmi_camera_save_and_send_to_mms();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_save_and_send_to_mms
 * DESCRIPTION
 *  save file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_save_and_send_to_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U32 written;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__

    /* copy tiled picture from tile result layer to base layer */
    if (g_camera_cntx.is_tileshot)
    {

    #ifdef __CAMERA_FEATURE_ADD_FRAME__
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0 && g_camera_cntx.setting.add_frame != 0)
        {
            gdi_layer_push_and_set_active(g_camera_cntx.tileshot_result_layer_handle);

            /* if has add frame, merge layers */
            gdi_layer_flatten(g_camera_cntx.tileshot_result_layer_handle, g_camera_cntx.add_frame_layer_handle, 0, 0);
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

        /* also copy result to base - this is for when popup show, the result will show at bg */
        gdi_layer_flatten(g_camera_cntx.tileshot_result_layer_handle, 0, 0, 0);

    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    /* blt base only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 

    gdi_layer_lock_frame_buffer();

    mmi_camera_free_add_frame_layer();

    ExitCategoryFunction();
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVING), IMG_GLOBAL_SAVE, NULL);
    g_camera_cntx.is_cat65_show = TRUE;


    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    if (g_camera_cntx.is_tileshot)
    {
    #ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
        mmi_camera_get_next_filename(buf_filename);

        if (g_camera_cntx.setting.add_frame != CAMERA_SETTING_ADD_FRAME_OFF)
        {

            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }
            else
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }
        }
        else
        {
            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }
            else
            {
                g_camera_cntx.last_error
                    = mdi_camera_encode_layer_to_jpeg(g_camera_cntx.tileshot_result_layer_handle, buf_filename);
            }

        }

        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            /* will display a popup, go out application and re-enter */
            if (g_camera_cntx.is_cat65_show)
            {
                g_camera_cntx.is_cat65_show = FALSE;
                ExitCategoryFunction();
            }
            
            mmi_camera_restore_filename_seq_no();
            mmi_camera_display_error_popup();
            return;
        }
    #else /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 
        MMI_ASSERT(0);
    #endif /* __CAMERA_FEATURE_CONT_SHOT_TILE__ */ 

    }
    else
    {

        /* this function has nvram access */
        mmi_camera_get_next_filename(buf_filename);

        file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);

        if (file_handle > 0)
        {
            FS_Write(file_handle, (void*)g_camera_cntx.capture_buf_ptr, g_camera_cntx.capture_size, (U32*) & written);
            FS_Close(file_handle);

            /* cant write in whole file, must be disk full */
            if (g_camera_cntx.capture_size != written)
            {
                /* delete the file that is not save complete */
                FS_Delete((U16*) buf_filename);

                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;

                if (g_camera_cntx.is_cat65_show)
                {
                    g_camera_cntx.is_cat65_show = FALSE;
                    ExitCategoryFunction();
                }
                mmi_camera_restore_filename_seq_no();
                /* will display a popup, go out application and re-enter */
                mmi_camera_display_error_popup();
                return;
            }
        }
        else
        {
            if (file_handle == FS_DISK_FULL)
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
            }
            else if (file_handle == FS_ROOT_DIR_FULL)
            {
                g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
            }
            else if (file_handle == FS_WRITE_PROTECTION)
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
            }
            else
            {
                g_camera_cntx.last_error = CAMERA_ERR_SAVE_FAIL;
            }

            if (g_camera_cntx.is_cat65_show)
            {
                g_camera_cntx.is_cat65_show = FALSE;
                ExitCategoryFunction();
            }
            mmi_camera_restore_filename_seq_no();
            /* will display a popup, go out application and re-enter */
            mmi_camera_display_error_popup();
            return;
        }
    }

    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }

    /* enter mms menu screen */
    mms_content_insert_hdlr((PS8) buf_filename);

}

#endif /* __MMI_CAMERA_MMS_SUPPORT__ */ 

#ifdef __CAMERA_FAST_ZOOM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_start_fast_zoom_in
 * DESCRIPTION
 *  start fast zoom operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_start_fast_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_fast_zoom = TRUE;
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
    mdi_camera_start_fast_zoom(TRUE, (U8) g_camera_cntx.zoom_limit, 1, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_start_fast_zoom_out
 * DESCRIPTION
 *  start fast zoom operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_start_fast_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_fast_zoom = TRUE;
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
    mdi_camera_start_fast_zoom(FALSE, (U8) g_camera_cntx.zoom_limit, 1, 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_stop_fast_zoom
 * DESCRIPTION
 *  stop fast zoom operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_stop_fast_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_stop_fast_zoom();
    g_camera_cntx.is_fast_zoom = FALSE;
}
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_draw_add_frame_color_idx
 * DESCRIPTION
 *  draw colo idx frame on overlay_frame layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
static void mmi_camera_draw_add_frame_color_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_idx = 0;
    gdi_color *p_gdi_palette;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_camera_cntx.overlay_frame_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    /* if frame is set , draw frame */
    if (g_camera_cntx.setting.add_frame_color_idx != CAMERA_SETTING_ADD_FRAME_OFF)
    {
        switch (mmi_camera_get_overlay_frame_kind())
        {
            case FOUR_BY_THREE:
                image_idx = (U16) (IMG_ID_CAMERA_COLOR_IDX_ADD_FRAME_START + g_camera_cntx.setting.add_frame_color_idx);
                g_camera_cntx.overlay_frame_width = CAMERA_ADD_FRAME_COLOR_IDX1_WIDTH;
                g_camera_cntx.overlay_frame_height = CAMERA_ADD_FRAME_COLOR_IDX1_HEIGHT;
                break;
            case FIVE_BY_FOUR:
                image_idx =
                    (U16) (IMG_ID_CAMERA_COLOR_IDX2_ADD_FRAME_START + g_camera_cntx.setting.add_frame_color_idx);
                g_camera_cntx.overlay_frame_width = CAMERA_ADD_FRAME_COLOR_IDX2_WIDTH;
                g_camera_cntx.overlay_frame_height = CAMERA_ADD_FRAME_COLOR_IDX2_HEIGHT;
                break;
            default:
                g_camera_cntx.setting.add_frame_color_idx = CAMERA_SETTING_ADD_FRAME_OFF;
                gdi_layer_pop_and_restore_active();
                return;
                break;
        }
        gdi_layer_resize(g_camera_cntx.overlay_frame_width, g_camera_cntx.overlay_frame_height);
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
        /* get palette and convert it into YUV444 */
        p_gdi_palette = gdi_layer_get_palette();
        g_camera_cntx.overlay_frame_source_key = gdi_image_gif_get_transparent_index();
        g_camera_cntx.overlay_frame_palette_size = gdi_image_gif_get_palette_size();
      /*************** RGB to YUV format **************************************************
      *
      *     [MSDN RGB888 to YUV444 (16bits)]
      *
      *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
      *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
      *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
      *     
      *     These formulas produce 8-bit results using coefficients 
      *     that require no more than 8 bits of (unsigned) precision. 
      *     Intermediate results require up to 16 bits of precision.
      *
      ***************************************************************************************/
        {
            U16 i;
            U32 Y, U, V;
            U32 R, G, B;
            U32 *p_overlay_palette;

            p_overlay_palette = &g_camera_cntx.overlay_palette[0];
            for (i = 0; i < 256; i++)
            {
                R = (U32) ((U8) (*p_gdi_palette >> 16));
                G = (U32) ((U8) (*p_gdi_palette >> 8));
                B = (U32) ((U8) (*p_gdi_palette));

                Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
                U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
                V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

                (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
                p_overlay_palette++;
                p_gdi_palette++;
            }
        }
        /* set palette, currently we only support 8bpp(256 colors) palette */
        mdi_camera_set_overlay_palette(255, &g_camera_cntx.overlay_palette[0]);
    }
    gdi_layer_pop_and_restore_active();
}
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_overlay_frame_kind
 * DESCRIPTION
 *  draw colo idx frame on overlay_frame layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
static camera_overlay_frame_kind mmi_camera_get_overlay_frame_kind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    camera_overlay_frame_kind ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_camera_cntx.image_width == 2048 && g_camera_cntx.image_height == 1536)
        || (g_camera_cntx.image_width == 1600 && g_camera_cntx.image_height == 1200)
        || (g_camera_cntx.image_width == 1280 && g_camera_cntx.image_height == 960)
        || (g_camera_cntx.image_width == 640 && g_camera_cntx.image_height == 480)
        || (g_camera_cntx.image_width == 800 && g_camera_cntx.image_height == 600)
        || (g_camera_cntx.image_width == 320 && g_camera_cntx.image_height == 240)
        || (g_camera_cntx.image_width == 160 && g_camera_cntx.image_height == 120)
        || (g_camera_cntx.image_width == 80 && g_camera_cntx.image_height == 60))
    {
        ret = FOUR_BY_THREE;
    }
    else if ((g_camera_cntx.image_width == 220 && g_camera_cntx.image_height == 176)
             || (g_camera_cntx.image_width == 1280 && g_camera_cntx.image_height == 1024))
    {
        ret = FIVE_BY_FOUR;
    }
    else
    {
        ret = NOT_SUPPORT;
    }
    return ret;
}
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_mf_forward
 * DESCRIPTION
 *  mf forward once
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_mf_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_camera_cntx.app_state == CAMERA_STATE_PREVIEW) && (g_camera_cntx.mf_level_idx < g_camera_cntx.mf_level_cnt))
    {
        g_camera_cntx.mf_level_idx++;
        g_camera_cntx.touch_zoom_inc.is_press = TRUE;

        mdi_camera_mf_forward();
        mmi_camera_preview_set_hint(NULL, NULL, 0);
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

        if (!g_camera_cntx.is_up_arrow_pressed)
        {
            gui_start_timer(200, mmi_camera_mf_forward_continue);
        }
    }
    else
    {
        g_camera_cntx.touch_zoom_inc.is_press = FALSE;
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_mf_backward
 * DESCRIPTION
 *  mf backward once
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_mf_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_camera_cntx.app_state == CAMERA_STATE_PREVIEW) && (g_camera_cntx.mf_level_idx > 0))
    {
        g_camera_cntx.mf_level_idx--;
        g_camera_cntx.touch_zoom_dec.is_press = TRUE;
        mdi_camera_mf_backward();
        mmi_camera_preview_set_hint(NULL, NULL, 0);
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

        if (!g_camera_cntx.is_down_arrow_pressed)
        {
            gui_start_timer(200, mmi_camera_mf_backward_continue);
        }
    }
    else
    {
        g_camera_cntx.touch_zoom_dec.is_press = FALSE;
        mmi_camera_preview_draw_osd();
        gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_mf_stop
 * DESCRIPTION
 *  stop mf action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_mf_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_stop_mf_continue();
    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
    g_camera_cntx.is_mf_continue = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_mf_forward_continue
 * DESCRIPTION
 *  start mf forward continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_mf_forward_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_mf_continue = TRUE;
    mdi_camera_start_mf_continue(TRUE);
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_mf_backward_continue
 * DESCRIPTION
 *  start mf backward continue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camera_mf_backward_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_mf_continue = TRUE;
    mdi_camera_start_mf_continue(FALSE);
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
}

#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 
/*****************************************************************************
* FUNCTION
*   mmi_camera_mf_get_level_cnt
* DESCRIPTION
*   get the mf status
* PARAMETERS
*   total_count OUT total idx number
* RETURNS
*   void    
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
/*
 * static void mmi_camera_exec_function_key(camera_key_map2_function_enum key)
 * {
 * switch(key)
 * {
 * case CAMERA_ZOOMIN:
 * mmi_camera_preview_zoom_in();
 * break;
 * case CAMERA_ZOOMOUT:
 * mmi_camera_preview_zoom_out();
 * break;
 * #ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
 * case CAMERA_MF_FORWARD:
 * mmi_camera_mf_forward();
 * break;
 * case CAMERA_MF_BACKWARD:
 * mmi_camera_mf_backward();
 * break;      
 * #endif
 * }
 * }
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_toggle_updown_key
 * DESCRIPTION
 *  get the mf status
 * PARAMETERS
 *  void
 *  total_count(?)      [OUT]       Total idx number
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
static void mmi_camera_toggle_updown_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.setting.af_mode == CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL)
    {
        if (g_camera_cntx.toggle_updown_key)
        {
            g_camera_cntx.up_key = CAMERA_MF_FORWARD;
            g_camera_cntx.down_key = CAMERA_MF_BACKWARD;
            g_camera_cntx.toggle_updown_key = FALSE;
        }
        else
        {
            g_camera_cntx.up_key = CAMERA_ZOOMIN;
            g_camera_cntx.down_key = CAMERA_ZOOMOUT;
            g_camera_cntx.toggle_updown_key = TRUE;
        }
    }

    mmi_camera_preview_draw_osd();
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);

}
#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_get_camera_banding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 OUT camera banding 
 *****************************************************************************/
U8 mmi_camera_get_camera_banding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_load_setting();
    return camera_banding_command_map[g_camera_cntx.setting.banding];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camera_entry_for_external_request
 * DESCRIPTION
 *  for External Request
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
 void mmi_camera_entry_for_external_request(
                void (*camera_result_callback)(MMI_BOOL result, S8 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_load_setting();
    g_camera_cntx.callback_ptr = camera_result_callback;
    g_camera_cntx.is_external_request = TRUE;
    g_camera_cntx.contshot_backup = g_camera_cntx.setting.cont_shot;
    g_camera_cntx.setting.cont_shot = 0;
    mmi_camera_entry_app_screen();
}

#endif /* __MMI_CAMERA__ */ 

