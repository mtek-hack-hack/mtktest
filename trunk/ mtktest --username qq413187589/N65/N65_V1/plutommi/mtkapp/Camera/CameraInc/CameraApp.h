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
 *  CameraApp.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Define Camera related data type
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CAMERA_DATATYPE_H_
#define _CAMERA_DATATYPE_H_

#include "MMI_features.h"
#include "CameraGprot.h"
#ifdef __MMI_CAMERA__

#include "resource_camera_skins.h"      /* UI custom config */

#ifdef __CAMERA_DSC_MODE__
#include "ae_awb.h"
#endif 

#ifdef MMI_ON_WIN32
#undef __MMI_CAMERA_5_OSD_LAYER__
#undef __MMI_CAMERA_3_OSD_LAYER__
#endif 


/****************************************************************************
* Define                                                            
*****************************************************************************/

/* Storage file path */
#define CAMERA_STORAGE_UNSAVE_FILENAME       FMGR_TEMP_FILE_CAMERA

/* capture to memory - [burst shot] and [multi shot] */
#define CAMERA_MEMORY_CAPTURE_IMAGE_COUNT       (12)    /* max 12 images */

#define CAMERA_HINT_CHAR_COUNT                  (25)
#define CAMERA_HINT_BUF_SIZE                    ((CAMERA_HINT_CHAR_COUNT+1)*ENCODING_LENGTH)

/* rotate */
#define CAMERA_PREVIEW_ROTATE_0              MDI_CAMERA_PREVIEW_ROTATE_0
#define CAMERA_PREVIEW_ROTATE_90             MDI_CAMERA_PREVIEW_ROTATE_90
#define CAMERA_PREVIEW_ROTATE_180            MDI_CAMERA_PREVIEW_ROTATE_180
#define CAMERA_PREVIEW_RORATE_270            MDI_CAMERA_PREVIEW_ROTATE_270
#define CAMERA_PREVIEW_ROTATE_0_MIRROR       MDI_CAMERA_PREVIEW_ROTATE_0_MIRROR
#define CAMERA_PREVIEW_ROTATE_90_MIRROR      MDI_CAMERA_PREVIEW_ROTATE_90_MIRROR
#define CAMERA_PREVIEW_ROTATE_180_MIRROR     MDI_CAMERA_PREVIEW_ROTATE_180_MIRROR
#define CAMERA_PREVIEW_ROTATE_270_MIRROR     MDI_CAMERA_PREVIEW_ROTATE_270_MIRROR

#define CAMERA_LCM_ROTATE_0                  MDI_CAMERA_LCM_ROTATE_0
#define CAMERA_LCM_ROTATE_90                 MDI_CAMERA_LCM_ROTATE_90
#define CAMERA_LCM_ROTATE_180                MDI_CAMERA_LCM_ROTATE_180
#define CAMERA_LCM_RORATE_270                MDI_CAMERA_LCM_ROTATE_270
#define CAMERA_LCM_ROTATE_0_MIRROR           MDI_CAMERA_LCM_ROTATE_0_MIRROR
#define CAMERA_LCM_ROTATE_90_MIRROR          MDI_CAMERA_LCM_ROTATE_90_MIRROR
#define CAMERA_LCM_ROTATE_180_MIRROR         MDI_CAMERA_LCM_ROTATE_180_MIRROR
#define CAMERA_LCM_ROTATE_270_MIRROR         MDI_CAMERA_LCM_ROTATE_270_MIRROR

#define CAMERA_SETTING_DUMMY  (0)

#define CAMERA_OSD_BUFFER_SIZE            (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2)

#if defined(__CAMERA_FEATURE_CONT_SHOT_TILE__)
#define CAMERA_TILE_RESULT_BUFFER_SIZE    ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#else 
#define CAMERA_TILE_RESULT_BUFFER_SIZE    (0)
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
#define CAMERA_OVERLAY_FRAME_BUFFER_SIZE     (((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)+4)
#else 
#define CAMERA_OVERLAY_FRAME_BUFFER_SIZE     (0)
#endif 

/* Debug info */
/*
 * #define CAMERA_CHECK_STATE(_STATE_)          MMI_ASSERT(g_camera_cntx.app_state == _STATE_);
 * #define CAMERA_ENTER_STATE(_STATE_)          {                                            \
 * CAMERA_TRACE_EXIT_STATE();             \
 * g_camera_cntx.app_next_state = _STATE_;\
 * mmi_camera_exit_current_state();       \
 * CAMERA_TRACE_ENTER_STATE();            \
 * mmi_camera_enter_state(_STATE_);       \
 * }
 * 
 * 
 * #define CAMERA_TRACE_FUNC_INIT()             kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_FUNC_INIT);                    
 * #define CAMERA_TRACE_FUNC_ENTER_APP()        kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_FUNC_ENTER_APP);
 * #define CAMERA_TRACE_FUNC_EXIT_APP()         kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_FUNC_EXIT_APP);
 * #define CAMERA_TRACE_FUNC_ENTER_SUBLCD()     kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_FUNC_ENTER_SUBLCD);
 * #define CAMERA_TRACE_FUNC_EXIT_SUBLCD()      kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_FUNC_EXIT_SUBLCD);
 * 
 * #define CAMERA_TRACE_CLAM_CLOSE_EVENT()      kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_CLAM_CLOSE_EVENT);
 * #define CAMERA_TRACE_CLAM_OPEN_EVENT()       kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_CLAM_OPEN_EVENT);
 * 
 * 
 * 
 * 
 * #define CAMERA_TRACE_ENTER_STATE()           kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_ENTER_STATE, g_camera_cntx.app_state);
 * #define CAMERA_TRACE_EXIT_STATE()            kal_trace(MMI_TRACE_G8_MEDIA, MMI_CAMERA_EXIT_STATE, g_camera_cntx.app_state);
 */
#define CAMERA_STATE_IN(_STATE_)             (g_camera_cntx.app_state==_STATE_)
#define CAMERA_CHECK_STATE(_STATE_)          MMI_ASSERT(g_camera_cntx.app_state == _STATE_);
#define CAMERA_ENTER_STATE(_STATE_)          {                                            \
                                                   CAMERA_TRACE_EXIT_STATE();             \
                                                   g_camera_cntx.app_next_state = _STATE_;\
                                                   mmi_camera_exit_current_state();       \
                                                   CAMERA_TRACE_ENTER_STATE();            \
                                                   mmi_camera_enter_state(_STATE_);       \
                                             }

#define CAMERA_TRACE_FUNC_INIT()             {}
#define CAMERA_TRACE_FUNC_ENTER_APP()        {}
#define CAMERA_TRACE_FUNC_EXIT_APP()         {}
#define CAMERA_TRACE_FUNC_ENTER_SUBLCD()     {}
#define CAMERA_TRACE_FUNC_EXIT_SUBLCD()      {}

#define CAMERA_TRACE_CLAM_CLOSE_EVENT()      {}
#define CAMERA_TRACE_CLAM_OPEN_EVENT()       {}

#define CAMERA_TRACE_ENTER_STATE()           {}
#define CAMERA_TRACE_EXIT_STATE()            {}

/****************************************************************************
* Typedef                                                      
*****************************************************************************/
#ifdef __CAMERA_FEATURE_XENON_FLASH__
/*********** Xenon Flash States ***********/
typedef enum
{
    MMI_CAMERA_XENON_FLASH_OFF = 0,
    MMI_CAMERA_XENON_FLASH_CHARGING,
    MMI_CAMERA_XENON_FLASH_CHARGING_1,
    MMI_CAMERA_XENON_FLASH_READY,
    NUM_OF_MMI_CAMERA_XENON_FLASH
} camera_xenon_flash_state_enum;
#endif

/*********** CAPTURE PATH ***********/
typedef enum
{
    CAPTURE_FROM_MEMORY,
    CAPTURE_FROM_LAYER,

    NUM_OF_CAPTURE_PATH
} camera_capture_path;

/************ up/down key function ************/
typedef enum
{
    CAMERA_ZOOMIN,
    CAMERA_ZOOMOUT,
    CAMERA_MF_FORWARD,
    CAMERA_MF_BACKWARD,

    NUM_OF_KEY_FUNCTION
} camera_key_map2_function_enum;

/*********** Add Frame *****/
typedef enum
{
#ifdef __CAMERA_FEATURE_ADD_FRAME_NORMAL__
    ADD_FRAME_NORMAL,
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME_TILESHOT__
    ADD_FRAME_TILESHOT,
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    ADD_FRAME_COLOR_IDX,
#endif 
    NUM_OF_ADD_FRAME_KIND
} camera_add_frame_kind;

/*********** Overlay Frame kind *****/
typedef enum
{
    FOUR_BY_THREE,
    FIVE_BY_FOUR,
    NOT_SUPPORT,
    NUM_OF_OVERLAY_FRAME_KIND
} camera_overlay_frame_kind;

/*********** AUTO FOCUS *************/
typedef enum
{
    AF_ANIMATION_STEP1,
    AF_ANIMATION_STEP2,
    AF_ANIMATION_STEP3,
    AF_ANIMATION_END
} camera_af_animtaion_process;

typedef enum
{
    AF_CALCULATE,
    AF_SUCCEED,
    AF_FAIL,
    AF_CANCEL
} camera_af_states;

/*********** WB ***********/
typedef enum
{

#ifdef __CAMERA_FEATURE_WB_AUTO__
    CAMERA_SETTING_WB_AUTO,
#endif 

#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
    CAMERA_SETTING_WB_DAYLIGHT,
#endif 

#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
    CAMERA_SETTING_WB_TUNGSTEN,
#endif 

#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
    CAMERA_SETTING_WB_FLUORESCENT,
#endif 

#ifdef __CAMERA_FEATURE_WB_CLOUD__
    CAMERA_SETTING_WB_CLOUD,
#endif 

#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
    CAMERA_SETTING_WB_INCANDESCENCE,
#endif 

#ifdef __CAMERA_FEATURE_WB_MANUAL__
    CAMERA_SETTING_WB_MANUAL,
#endif 

    CAMERA_SETTING_WB_COUNT
} camera_setting_wb_enum;

/*********** Flash ***********/
typedef enum
{
    CAMERA_SETTING_FLASH_OFF,
    CAMERA_SETTING_FLASH_ON,
#ifdef __CAMERA_FEATURE_FLASH_AUTO__
    CAMERA_SETTING_FLASH_AUTO,
#endif 

#ifdef __CAMERA_FEATURE_FLASH_REDEYE__
    CAMERA_SETTING_FLASH_REDEYE,
#endif 

    CAMERA_SETTING_FLASH_COUNT
} camera_setting_flash_enum;

/*********** LED Highlight ***********/
typedef enum
{

    CAMERA_SETTING_LED_HIGHLIGHT_OFF,
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    CAMERA_SETTING_LED_HIGHLIGHT_ON,
#endif 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    CAMERA_SETTING_LED_HIGHLIGHT_WHITE,
    CAMERA_SETTING_LED_HIGHLIGHT_RED,
    CAMERA_SETTING_LED_HIGHLIGHT_GREEN,
    CAMERA_SETTING_LED_HIGHLIGHT_BLUE,
    CAMERA_SETTING_LED_HIGHLIGHT_YELLOW,
    CAMERA_SETTING_LED_HIGHLIGHT_PURPLE,
    CAMERA_SETTING_LED_HIGHLIGHT_CYAN,
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__ */ 

    CAMERA_SETTING_LED_HIGHLIGHT_COUNT
} camera_setting_led_highlight_enum;

/*********** Shutter Sound ***********/
typedef enum
{

#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_OFF__
    CAMERA_SETTING_SHUTTER_SOUND_OFF,
#endif 

#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_1__
    CAMERA_SETTING_SHUTTER_SOUND_1,
#endif 

#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_2__
    CAMERA_SETTING_SHUTTER_SOUND_2,
#endif 

#ifdef __CAMERA_FEATURE_SHUTTER_SOUND_3__
    CAMERA_SETTING_SHUTTER_SOUND_3,
#endif 
    CAMERA_SETTING_SHUTTER_SOUND_COUNT
} camera_setting_shutter_sound_enum;

/*********** EV ***********/
typedef enum
{

#ifdef __CAMERA_FEATURE_EV_4__
    CAMERA_SETTING_EV_N4,
#endif 

#ifdef __CAMERA_FEATURE_EV_3__

    CAMERA_SETTING_EV_N3,
#endif /* __CAMERA_FEATURE_EV_3__ */ 

#ifdef __CAMERA_FEATURE_EV_2__
    CAMERA_SETTING_EV_N2,
#endif 

    CAMERA_SETTING_EV_N1,
    CAMERA_SETTING_EV_0,
    CAMERA_SETTING_EV_P1,

#ifdef __CAMERA_FEATURE_EV_2__
    CAMERA_SETTING_EV_P2,
#endif 

#ifdef __CAMERA_FEATURE_EV_3__
    CAMERA_SETTING_EV_P3,
#endif 

#ifdef __CAMERA_FEATURE_EV_4__
    CAMERA_SETTING_EV_P4,
#endif 
    CAMERA_SETTING_EV_COUNT
} camera_setting_ev_enum;

/*********** Night ***********/
typedef enum
{
    CAMERA_SETTING_NIGHT_OFF = 0,
    CAMERA_SETTING_NIGHT_ON,
    CAMERA_SETTING_NIGHT_COUNT
} camera_setting_night_enum;

/*********** Closeup ***********/
typedef enum
{
    CAMERA_SETTING_CLOSEUP_OFF = 0,
    CAMERA_SETTING_CLOSEUP_ON,
    CAMERA_SETTING_CLOSEUP_COUNT
} camera_setting_closeup_enum;

/*********** Banding ***********/
typedef enum
{
    CAMERA_SETTING_BANDING_50HZ = 0,
    CAMERA_SETTING_BANDING_60HZ,
    CAMERA_SETTING_BANDING_COUNT
} camera_setting_banding_enum;

/*********** Effect ***********/
typedef enum
{
#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
    CAMERA_SETTING_EFFECT_NORMAL,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
    CAMERA_SETTING_EFFECT_GRAYSCALE,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
    CAMERA_SETTING_EFFECT_SEPIA,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
    CAMERA_SETTING_EFFECT_SEPIA_GREEN,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
    CAMERA_SETTING_EFFECT_SEPIA_BLUE,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
    CAMERA_SETTING_EFFECT_COLOR_INVERT,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
    CAMERA_SETTING_EFFECT_GRAY_INVERT,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
    CAMERA_SETTING_EFFECT_BLACKBOARD,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
    CAMERA_SETTING_EFFECT_WHITEBOARD,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
    CAMERA_SETTING_EFFECT_COPPER_CARVING,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
    CAMERA_SETTING_EFFECT_BLUE_CARVING,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
    CAMERA_SETTING_EFFECT_EMBOSSMENT,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
    CAMERA_SETTING_EFFECT_CONTRAST,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_JEAN__
    CAMERA_SETTING_EFFECT_JEAN,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
    CAMERA_SETTING_EFFECT_SKETCH,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_OIL__
    CAMERA_SETTING_EFFECT_OIL,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    CAMERA_SETTING_EFFECT_CUSTOM_FX_1,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    CAMERA_SETTING_EFFECT_CUSTOM_FX_2,
#endif 

#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    CAMERA_SETTING_EFFECT_CUSTOM_FX_3,
#endif 

    CAMERA_SETTING_EFFECT_COUNT
} camera_setting_effect_setting_enum;

/*********** Image Size ***********/
typedef enum
{

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    CAMERA_SETTING_IMAGE_SIZE_SS,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    CAMERA_SETTING_IMAGE_SIZE_S,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    CAMERA_SETTING_IMAGE_SIZE_M,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    CAMERA_SETTING_IMAGE_SIZE_L,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    CAMERA_SETTING_IMAGE_SIZE_LL,
#endif 

#if defined(__CAMERA_130W_CHEAT__) 
   //Huyanwei Add It For 1280X960
    CAMERA_SETTING_IMAGE_SIZE_LLL,
#endif   

    CAMERA_SETTING_IMAGE_SIZE_COUNT
} camera_setting_image_size_enum;

/*********** Image Qty ***********/
typedef enum
{

#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
    CAMERA_SETTING_IMAGE_QTY_LOW,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
    CAMERA_SETTING_IMAGE_QTY_NORMAL,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
    CAMERA_SETTING_IMAGE_QTY_HIGH,
#endif 

#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
    CAMERA_SETTING_IMAGE_QTY_FINE,
#endif 

    CAMERA_SETTING_IMAGE_QTY_COUNT
} camera_setting_image_qty_enum;

/******* [Add Frame Menu] ********/
typedef enum
{

    CAMERA_SETTING_ADD_FRAME_OFF,

#ifdef __CAMERA_FEATURE_ADD_FRAME_1__
    CAMERA_SETTING_ADD_FRAME_1,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_2__
    CAMERA_SETTING_ADD_FRAME_2,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_3__
    CAMERA_SETTING_ADD_FRAME_3,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_4__
    CAMERA_SETTING_ADD_FRAME_4,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_5__
    CAMERA_SETTING_ADD_FRAME_5,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_6__
    CAMERA_SETTING_ADD_FRAME_6,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_7__
    CAMERA_SETTING_ADD_FRAME_7,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_8__
    CAMERA_SETTING_ADD_FRAME_8,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_9__
    CAMERA_SETTING_ADD_FRAME_9,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_10__
    CAMERA_SETTING_ADD_FRAME_10,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_1__
    CAMERA_SETTING_ADD_FRAME_CUSTOM_1,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_2__
    CAMERA_SETTING_ADD_FRAME_CUSTOM_2,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_3__
    CAMERA_SETTING_ADD_FRAME_CUSTOM_3,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_4__
    CAMERA_SETTING_ADD_FRAME_CUSTOM_4,
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME_CUSTOM_5__
    CAMERA_SETTING_ADD_FRAME_CUSTOM_5,
#endif 

    CAMERA_SETTING_ADD_FRAME_COUNT
} camera_setting_add_frame_enum;

/*********** Cont Shot ***********/
typedef enum
{

    CAMERA_SETTING_CONT_SHOT_OFF,
    CAMERA_SETTING_CONT_SHOT_1,

#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
    CAMERA_SETTING_CONT_SHOT_2,
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
    CAMERA_SETTING_CONT_SHOT_3,
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT_TILE__
    CAMERA_SETTING_CONT_SHOT_TILE,
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    CAMERA_SETTING_CONT_SHOT_BURST,
#endif 

    CAMERA_SETTING_CONT_SHOT_COUNT
} camera_setting_cont_shot_enum;

/*********** Delay Timer ***********/
typedef enum
{

    CAMERA_SETTING_DELAY_TIMER_OFF,
    CAMERA_SETTING_DELAY_TIMER_1,

#ifdef __CAMERA_FEATURE_DELAY_TIMER_2__
    CAMERA_SETTING_DELAY_TIMER_2,
#endif 

#ifdef __CAMERA_FEATURE_DELAY_TIMER_3__
    CAMERA_SETTING_DELAY_TIMER_3,
#endif 
    CAMERA_SETTING_DELAY_TIMER_COUNT
} camera_setting_delay_timer_enum;

/*********** AE Meter ***********/
typedef enum
{

#ifdef __CAMERA_FEATURE_AE_METER_AUTO__
    CAMERA_SETTING_AE_METER_AUTO,
#endif 

#ifdef __CAMERA_FEATURE_AE_METER_SPOT__
    CAMERA_SETTING_AE_METER_SPOT,
#endif 

#ifdef __CAMERA_FEATURE_AE_METER_CENTER__
    CAMERA_SETTING_AE_METER_CENTER,
#endif 

#ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
    CAMERA_SETTING_AE_METER_AVERAGE,
#endif 
    CAMERA_SETTING_AE_METER_COUNT
} camera_setting_ae_meter_enum;

/*********** Auto Focus ***********/
typedef enum
{
#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
    CAMERA_SETTING_AUTOFOCUS_1_ZONE,
#endif 

#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
    CAMERA_SETTING_AUTOFOCUS_3_ZONE,
#endif 

#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
    CAMERA_SETTING_AUTOFOCUS_5_ZONE,
#endif 

    CAMERA_SETTING_AUTOFOCUS_COUNT
} camera_setting_autofocus_enum;

typedef enum
{
#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
    CAMERA_SETTING_AUTOFOCUS_MODE_AUTO,
#endif 

#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
    CAMERA_SETTING_AUTOFOCUS_MODE_MACRO,
#endif 

#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
    CAMERA_SETTING_AUTOFOCUS_MODE_INFINITE,
#endif 

#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    CAMERA_SETTING_AUTOFOCUS_MODE_MANUAL,
#endif 

    CAMERA_SETTING_AUTOFOCUS_MODE_COUNT
} camera_setting_autofocus_mode_enum;

/*********** Shot mode ***********/
typedef enum
{

#ifdef __CAMERA_DSC_MODE_AUTO__
    CAMERA_SETTING_DSC_MODE_AUTO,
#endif 

#ifdef __CAMERA_DSC_MODE_PORTRAIT__
    CAMERA_SETTING_DSC_MODE_PORTRAIT,
#endif 

#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
    CAMERA_SETTING_DSC_MODE_LANDSCAPE,
#endif 

#ifdef __CAMERA_DSC_MODE_SPORT__
    CAMERA_SETTING_DSC_MODE_SPORT,
#endif 

#ifdef __CAMERA_DSC_MODE_FLOWER__
    CAMERA_SETTING_DSC_MODE_FLOWER,
#endif 

#ifdef __CAMERA_DSC_MODE_NIGHT__
    CAMERA_SETTING_DSC_MODE_NIGHT,
#endif 

#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
    CAMERA_SETTING_DSC_MODE_SHUTTER_PRI,
#endif 

#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
    CAMERA_SETTING_DSC_MODE_APERTURE_PRI,
#endif 

#ifdef __CAMERA_DSC_MODE_ISO__
    CAMERA_SETTING_DSC_MODE_ISO,
#endif 

    CAMERA_SETTING_DSC_MODE_COUNT
} camera_setting_dsc_mode_enum;

/*********** ISO ***********/
typedef enum
{

#ifdef __CAEMRA_FEATURE_ISO_AUTO__
    CAMERA_SETTING_ISO_AUTO,
#endif 

#ifdef __CAEMRA_FEATURE_ISO_100__
    CAMERA_SETTING_ISO_100,
#endif 

#ifdef __CAEMRA_FEATURE_ISO_200__
    CAMERA_SETTING_ISO_200,
#endif 

#ifdef __CAEMRA_FEATURE_ISO_400__
    CAMERA_SETTING_ISO_400,
#endif 

    CAMERA_SETTING_ISO_COUNT
} camera_setting_iso_enum;

/*********** OSD Status Icons ***********/
#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
typedef enum
{
    CAMERA_ICONBAR_ZOOM,
    CAMERA_ICONBAR_EV,
    CAMERA_ICONBAR_EFFECT,
    CAMERA_ICONBAR_WB,
    CAMERA_ICONBAR_FLASH,
    CAMERA_ICONBAR_LED_HIGHLIGHT,
    CAMERA_ICONBAR_NIGHT,
    CAMERA_ICONBAR_CLOSEUP,
    CAMERA_ICONBAR_ADD_FRAME,
    CAMERA_ICONBAR_CONT_SHOT,
    CAMERA_ICONBAR_DELAY_TIMER,
    CAMERA_ICONBAR_IMAGE_SIZE,
    CAMERA_ICONBAR_IMAGE_QTY,
    CAMERA_ICONBAR_STORAGE,
    CAMERA_ICONBAR_AE_METER,
    CAMERA_ICONBAR_DSC_MODE,
    CAMERA_ICONBAR_FOCUS_METER,
    CAMERA_ICONBAR_FOCUS_MODE,

    /* icon count */
    CAMERA_ICONBAR_ITEM_COUNT
} camera_iconbar_enum;
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

typedef struct
{
    U8 r;
    U8 g;
    U8 b;
} camera_flash_struct;

/* Setting are value will be store in nvram */
/* NVRAM ITEM SIZE: 84 byte */
typedef struct
{

    /* camera setting - 16 byte */
    U16 wb;
    U16 flash;
    U16 led_highlight;
    U16 shutter_sound;
    U16 ev;
    U16 night;
    U16 closeup;
    U16 banding;

    /* image setting - 4 byte */
    U16 image_size;
    U16 image_qty;

    /* others - 12 byte */
    U16 effect;
    U16 add_frame;
    U16 cont_shot;
    U16 delay_timer;
    U16 reserve1;   /* not used - it was storage before */
    U16 zoom_idx;

    /* custom effect - 24 byte */
    U16 fx_brightness[3];
    U16 fx_saturation[3];
    U16 fx_contrast[3];
    U16 fx_hue[3];

    /* extra - 14 byte */
    U16 iso;
    U16 ae_meter;
    U16 dsc_mode;
    U16 af_meter;
    U16 af_mode;
    U16 shutter_pri;
    U16 aperture_pri;

    /* reserve - 6 byte */

    U16 add_frame_tileshot;
    U16 add_frame_color_idx;
    U16 reserve9;

    /* flash & LED - 8 byte */
    U16 preview_flash_value;
    U16 capture_flash_value;
    U16 preview_led_value;
    U16 capture_led_value;

} camera_setting_struct;

typedef struct
{
    U32 offset;
    U32 size;
} camera_memory_capture_struct;

/* multimedia ui component */

typedef struct
{
    U16 image_id;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} CAM_UI_IMG;

typedef struct
{
    U16 image_id;
    S32 image_width;
    S32 image_height;
    S32 tile_offset_x;
    S32 tile_offset_y;
    S32 tile_width;
    S32 tile_height;
} CAM_UI_IMG_TILE;

typedef struct
{
    CAM_UI_IMG left;
    CAM_UI_IMG right;
    CAM_UI_IMG_TILE center;

    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} CAM_UI_TITLE;

typedef struct
{
    CAM_UI_IMG left;
    CAM_UI_IMG right;
    CAM_UI_IMG chat_mark;
    CAM_UI_IMG_TILE center;
    CAM_UI_IMG up_arrow;
    CAM_UI_IMG up_arrow_sel;
    CAM_UI_IMG up_arrow_dis;
    CAM_UI_IMG down_arrow;
    CAM_UI_IMG down_arrow_sel;
    CAM_UI_IMG down_arrow_dis;

    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} CAM_UI_BOTTOM;

typedef struct
{
    CAM_UI_IMG_TILE left;
    CAM_UI_IMG_TILE right;
    CAM_UI_IMG_TILE center;

    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} CAM_UI_BODY;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    BOOL is_press;
} camera_ui_touch_struct;

typedef struct
{
    gdi_handle base_layer_handle;
    gdi_handle add_frame_layer_handle;
    gdi_handle tileshot_preview_layer_handle;
    gdi_handle tileshot_result_layer_handle;
    gdi_handle osd_layer_handle0;
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    gdi_handle osd_layer_handle1;
    gdi_handle osd_layer_handle2;
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */
    
#ifdef __MMI_CAMERA_5_OSD_LAYER__
    gdi_handle osd_layer_handle3;
    gdi_handle osd_layer_handle4;
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 

    gdi_handle sublcd_base_layer_handle;
    gdi_handle preview_layer_handle;

    gdi_handle overlay_frame_layer_handle;
    MDI_RESULT last_error;

    camera_setting_struct setting;

    camera_osd_layeout_struct *active_camera_osd_ptr;
    U8 osd_rotate;
    U8 previous_osd_rotate;

    U8 lcm_rotate;

    U32 UI_device_height;
    U32 UI_device_width;

    U32 osd_UI_device_width;
    U32 osd_UI_device_height;
    U32 base_UI_device_width;
    U32 base_UI_device_height;

    camera_capture_path capture_path;
    U8 previous_image_size;
    U16 dsc_mode_shutter_pri_str_id[20];
    U16 dsc_mode_aperture_pri_str_id[20];
    camera_af_animtaion_process af_animation_process;

    S32 capture_countdown;
    PS8 storage_filepath;
    PU8 osd_layer_buf_ptr0;
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    PU8 osd_layer_buf_ptr1;
    PU8 osd_layer_buf_ptr2;
    BOOL is_single_osd_layer;
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */

#ifdef __MMI_CAMERA_5_OSD_LAYER__
    PU8 osd_layer_buf_ptr3;
    PU8 osd_layer_buf_ptr4;
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    PU8 tileshot_result_buf_ptr;

#ifdef __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__
    PU8 overlay_frame_buf_ptr;
    PU8 overlay_frame_buf_ptr_ori;
    U16 overlay_frame_width;
    U16 overlay_frame_height;
    U16 overlay_frame_source_key;
    U16 overlay_frame_palette_size;
    U32 overlay_palette[256];
#endif /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    U16 preview_width;
    U16 preview_height;
    U16 image_width;
    U16 image_height;
    U16 zoom_limit;
    U16 max_zoom_limit[5];  /* LL, L, M, S, SS */
    U16 image_size_before_burst;
    U16 app_state;
    U16 app_prev_state;
    U16 app_next_state;
    S16 cont_shot_count;
    S16 cont_shot_total_count;
    PU8 capture_buf_ptr;
    U32 capture_size;

    U8 remain_percent;
    BOOL is_lsk_pressed;
    BOOL is_rsk_pressed;
    BOOL is_up_arrow_pressed;
    BOOL is_down_arrow_pressed;
    BOOL is_ev_inc_pressed;
    BOOL is_ev_dec_pressed;
    BOOL is_autofocus_pressed;
    BOOL is_manual_autofocus;
    camera_af_states af_state;
    U8 af_result;
    BOOL is_af_capture;
    BOOL is_capturing;
    BOOL is_clam_close;
    BOOL is_force_self_capture;
    BOOL is_setting_loaded;
    BOOL is_mainlcd_resource;
    BOOL is_sublcd_resource;
    BOOL is_fullscreen;
    BOOL is_sublcd_display;
    BOOL is_tileshot;
    BOOL is_dis_clam_open;
    BOOL is_cat65_show;
    BOOL is_hide_osd;
    BOOL is_multi_sound_open;
    BOOL is_mms_icon_pressed;
    BOOL is_fast_zoom;
    BOOL is_draw_timer_on;
    BOOL is_audio_finished;
    U8 is_continue_capture;
    BOOL has_camera_previewed;
    BOOL is_mms_ready;
    BOOL is_3d_sound_on;
    BOOL is_sublcd_previewing;


    BOOL toggle_updown_key;
    camera_key_map2_function_enum up_key;
    camera_key_map2_function_enum down_key;

#ifdef __CAMERA_AUTOFOCUS_MODE_MANUAL__
    BOOL is_mf_continue;
    U32 mf_level_idx;
    U32 mf_level_cnt;
#endif /* __CAMERA_AUTOFOCUS_MODE_MANUAL__ */ 

    S8 hint1_buf[CAMERA_HINT_BUF_SIZE];
    S8 hint2_buf[CAMERA_HINT_BUF_SIZE];
    U16 fade_time;
    U16 image_size_str_id[5];   /* LL, L, M, S, SS */
    U16 image_size_img_id[5];   /* LL, L, M, S, SS */
    U16 selected_effect;
    U16 selected_dsc_mode;
    U16 selected_iso;
    S32 cur_select_flash_idx;

    U8 tile_cur_num;
    mdi_handle multi_sound_dummy_bg;
    mdi_handle multi_sound_capture0;
    mdi_handle multi_sound_capture1;
    mdi_handle multi_sound_capture2;
    U16 multi_sound_cap_idx;

#ifdef __COUNTDOWN_USING_MMA__
    mdi_handle multi_sound_countdown;
#endif

#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
    mdi_camera_jpegs_struct burst_jpg_data;
    U16 burst_save_index;
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 

#ifdef __CAMERA_FEATURE_ICONBAR_PANEL__
    U16 iconbar_item[CAMERA_ICONBAR_ITEM_COUNT];
    S32 iconbar_start_idx;
    S32 iconbar_selected_idx;
    S32 iconbar_item_count;
    S32 iconbar_item_per_page;
    S32 iconbar_item_width;
    S32 iconbar_arrow_width;
#endif /* __CAMERA_FEATURE_ICONBAR_PANEL__ */ 

    U16 touch_object;
    camera_ui_touch_struct touch_lsk;
    camera_ui_touch_struct touch_rsk;

    camera_ui_touch_struct touch_effect;
    camera_ui_touch_struct touch_wb;
    camera_ui_touch_struct touch_flash;
    camera_ui_touch_struct touch_led_highlight;
    camera_ui_touch_struct touch_night;
    camera_ui_touch_struct touch_image_size;
    camera_ui_touch_struct touch_image_qty;
    camera_ui_touch_struct touch_cont_shot;
    camera_ui_touch_struct touch_delay_timer;
    camera_ui_touch_struct touch_zoom_inc;
    camera_ui_touch_struct touch_zoom_dec;
    camera_ui_touch_struct touch_ev_inc;
    camera_ui_touch_struct touch_ev_dec;
    camera_ui_touch_struct touch_capture;
    camera_ui_touch_struct touch_dsc_mode;
    camera_ui_touch_struct touch_af_mode;
    camera_ui_touch_struct touch_af_meter;
    camera_ui_touch_struct touch_zoom_mf_toggle;
    camera_ui_touch_struct touch_iso;
    camera_ui_touch_struct touch_ae_meter;
    camera_ui_touch_struct touch_storage;
    camera_ui_touch_struct touch_mms_icon;

   /***************************
   * AF
   ***************************/
#ifdef __CAMERA_AUTOFOCUS__
    U16 af_zone0_x; /* AF Zone 0 X-coordinate, (0,0) means left-top corner */
    U16 af_zone0_y; /* AF Zone 0 Y-coordinate */
    U16 af_zone1_x; /* AF Zone 1 X-coordinate */
    U16 af_zone1_y; /* AF Zone 1 Y-coordinate */
    U16 af_zone2_x; /* AF Zone 2 X-coordinate */
    U16 af_zone2_y; /* AF Zone 2 Y-coordinate */
    U16 af_zone3_x; /* AF Zone 3 X-coordinate */
    U16 af_zone3_y; /* AF Zone 3 Y-coordinate */
    U16 af_zone4_x; /* AF Zone 4 X-coordinate */
    U16 af_zone4_y; /* AF Zone 4 Y-coordinate */
#endif /* __CAMERA_AUTOFOCUS__ */ 

#ifdef __MMI_SCREEN_SNAPSHOT__
    BOOL is_screen_snapshot;
#endif 

    BOOL is_af_test;

    camera_result_callback callback_ptr;
    S16 external_requeset_error;
    PS8 camera_er_filepath;
    pBOOL is_external_request;
    U16 contshot_backup;
    
    void *app_mem_pool;

#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
    PU8 direct_couple_buffer;    
    pBOOL is_direct_couple;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;    
#endif
#ifdef __CAMERA_FEATURE_XENON_FLASH__
    camera_xenon_flash_state_enum  xenon_flash_state;
#endif

} camera_context_struct;

typedef struct
{
    CAM_UI_TITLE title;
    CAM_UI_BOTTOM bottom;
    CAM_UI_BODY body;

    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;

    U16 highlighted_index;
    U16 page_start_index;
    U16 item_per_page;
    U16 total_item_count;
    gdi_color highlight_color;
    gdi_color bg_color;
    void (*highlight_hdlr) (S32);

} CAM_UI_POPLIST;

typedef struct
{
    CAM_UI_IMG img_l_arrow;
    CAM_UI_IMG img_l_arrow_sel;
    CAM_UI_IMG img_l_arrow_dis;
    CAM_UI_IMG img_r_arrow;
    CAM_UI_IMG img_r_arrow_sel;
    CAM_UI_IMG img_r_arrow_dis;
    CAM_UI_IMG img_hide_tap;

    CAM_UI_IMG img_icon[15];        /* max 15 icons */
    CAM_UI_IMG img_icon_sel[15];    /* max 15 icons */
    BOOL is_image_icon_update[15];

    S32 total_icon_count;
    S32 icon_per_page;
    S32 highlighted_index;
    S32 page_start_index;   /* start icon index of this page */

    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} CAM_UI_ICONLIST;

#if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined(__CAMERA_DSC_MODE_APERTURE_PRI__)
typedef struct
{
#ifdef __CAMERA_DSC_MODE_SHUTTER_PRI__
    U16 shutter_pri_str[TV_NO][10];
    U16 shutter_pri_count;
    U16 shutter_pri_value[TV_NO];
#endif /* __CAMERA_DSC_MODE_SHUTTER_PRI__ */ 
#ifdef __CAMERA_DSC_MODE_APERTURE_PRI__
    U16 aperture_pri_str[AV_NO][10];
    U16 aperture_pri_count;
    U16 aperture_pri_value[TV_NO];
#endif /* __CAMERA_DSC_MODE_APERTURE_PRI__ */ 
} camera_dsc_mode_inline_data_struct;
#endif /* defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined(__CAMERA_DSC_MODE_APERTURE_PRI__) */ 

typedef enum
{
    CAMERA_TOUCH_RSK,
    CAMERA_TOUCH_LSK,
    CAMERA_TOUCH_EFFECT,
    CAMERA_TOUCH_WB,
    CAMERA_TOUCH_FLASH,
    CAMERA_TOUCH_LED_HIGHLIGHT,
    CAMERA_TOUCH_NIGHT,
    CAMERA_TOUCH_IMAGE_SIZE,
    CAMERA_TOUCH_IMAGE_QTY,
    CAMERA_TOUCH_CONT_SHOT,
    CAMERA_TOUCH_DELAY_TIMER,
    CAMERA_TOUCH_STORAGE,
    CAMERA_TOUCH_ZOOM_INC,  /* zoom in */
    CAMERA_TOUCH_ZOOM_DEC,  /* zoom out */
    CAMERA_TOUCH_EV_INC,
    CAMERA_TOUCH_EV_DEC,
    CAMERA_TOUCH_CAPTURE,
    CAMERA_TOUCH_MMS_ICON,
    CAMERA_TOUCH_DSC_MODE,
    CAMERA_TOUCH_ISO,
    CAMERA_TOUCH_AE_METER,
    CAMERA_TOUCH_AF_MODE,
    CAMERA_TOUCH_AF_METER,
    CAMERA_TOUCH_ZOOM_MF_TOGGLE,

    CAMERA_TOUCH_WB_LEFT_ARROW,
    CAMERA_TOUCH_WB_RIGHT_ARROW,

    CAMERA_TOUCH_NONE
} camera_touch_obj_enum;

/****************************************************************************
* Extern Global Variable                                                            
*****************************************************************************/
extern camera_context_struct g_camera_cntx;

#if defined(__CAMERA_DSC_MODE_SHUTTER_PRI__) || defined(__CAMERA_DSC_MODE_APERTURE_PRI__)
extern camera_dsc_mode_inline_data_struct g_camera_dsc_mode_cntx;
#endif 
/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern void mmi_camera_init_app(void);
extern void mmi_camera_entry_app_screen(void);
extern void mmi_camera_entry_storage_screen(void);
#ifdef __MMI_SUBLCD_CAMERA__
extern void mmi_sublcd_camera_entry_option_screen(void);
extern BOOL mmi_sublcd_camera_is_previewing(void);
extern void mmi_sublcd_camera_exit_preview_screen(void);
#endif
extern void mmi_camera_restore_setting(void);
extern void mmi_camera_load_setting(void);
extern void mmi_camera_store_setting(void);
extern void mmi_camera_preview_update_capture_size(void);

extern void mmi_camera_check_osd_orientation(void);
extern void mmi_camera_check_sensor_orientation(void);

extern void mmi_camera_exit_sublcd_screen(void);
extern void mmi_camera_entry_sublcd_screen(void);
extern void mmi_camera_preview_create_preview_resource(S32 offset_x, S32 offset_y, S32 width, S32 height, U8 rotate);
extern void mmi_camera_preview_free_preview_resource(void);

extern BOOL mmi_camera_get_storage_file_path(PS8 filepath);
extern BOOL mmi_camera_check_and_restore_valid_drv(void);

extern void mmi_camera_capture_play_sound(void);

#ifdef __MMI_SUBLCD__
extern void mmi_camera_sublcd_draw_icon(void);
extern BOOL mmi_sublcd_camera_delete_screen_if_present(void);
#endif 

extern U8 mmi_camera_get_camera_banding(void);


#endif /* __MMI_CAMERA__ */ 
#endif /* _CAMERA_DATATYPE_H_ */ 

