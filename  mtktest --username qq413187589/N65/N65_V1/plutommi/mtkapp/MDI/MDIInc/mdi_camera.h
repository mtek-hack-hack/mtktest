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
 *  mdi_camera.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera interfce header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_CAMERA_H_
#define _MDI_CAMERA_H_

#ifdef __MMI_CAMERA__

#ifndef _MDI_DATATYPE_H_
#error "Please include mdi_datatype.h before mdi_camera.h"
#endif 


#include "med_api.h"

#if defined(MT6228) || defined(MT6229) || defined (MT6230) || defined(MT6238)
#define MDI_CAMERA_MT6228_SERIES  1
#define MDI_CAMERA_MT6227_SERIES  0
#define MDI_CAMERA_MT6225_SERIES  0
#define MDI_CAMERA_MT6219_SERIES  0
#define MDI_CAMERA_MT6217_SERIES  0
#elif defined(MT6227) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227D)
#define MDI_CAMERA_MT6228_SERIES  0
#define MDI_CAMERA_MT6227_SERIES  1
#define MDI_CAMERA_MT6225_SERIES  0
#define MDI_CAMERA_MT6219_SERIES  0
#define MDI_CAMERA_MT6217_SERIES  0
#elif defined(MT6225) || defined(MT6235)
#define MDI_CAMERA_MT6228_SERIES  0
#define MDI_CAMERA_MT6227_SERIES  0
#define MDI_CAMERA_MT6225_SERIES  1
#define MDI_CAMERA_MT6219_SERIES  0
#define MDI_CAMERA_MT6217_SERIES  0
#elif defined(MT6219)
#define MDI_CAMERA_MT6228_SERIES  0
#define MDI_CAMERA_MT6227_SERIES  0
#define MDI_CAMERA_MT6225_SERIES  0
#define MDI_CAMERA_MT6219_SERIES  1
#define MDI_CAMERA_MT6217_SERIES  0
#elif defined(MT6217) || defined(MT6218B)
#define MDI_CAMERA_MT6228_SERIES  0
#define MDI_CAMERA_MT6227_SERIES  0
#define MDI_CAMERA_MT6225_SERIES  0
#define MDI_CAMERA_MT6219_SERIES  0
#define MDI_CAMERA_MT6217_SERIES  1
#endif 


#if defined(XENON_FLASHLIGHT_ANTI_RED_EYE) || defined(XENON_FLASHLIGHT)
#define __MDI_CAMERA_XENON_FLASH_SUPPORT__
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef BARCODE_SUPPORT
typedef enum
{
    MDI_CAMERA_BARCODE_TYPE_UNKNOWN = 0,
    MDI_CAMERA_BARCODE_TYPE_QR = 0x0001,
    MDI_CAMERA_BARCODE_TYPE_DM = 0x0002,
    MDI_CAMERA_BARCODE_TYPE_EZ = 0x0004
}mdi_camera_barcode_type_enum;


typedef struct
{
    U8 retType;     //code type of the detected barcode:

    S16 nSymbols;    // total number of symbols in structured append
    S16 symbolId;    // symbol sequence indicator in structured append
    U8 parityData;  // parity data in structured append
    U8 encodeMode;  //0000,0001 1st bit is flag for HANZI mode,
                        //0000,0010 2nd bit is flag for KANJI mode,
                        //0000,0100 3rd bit is flag for UTF8 mode
    S32 nVersion;    
}mdi_camera_decode_result_struct;

typedef void (*mdi_barcode_callback) (mdi_result result, U8 encoding, U8 nsymbol, U8 symbolid, U8 paritydata, mdi_camera_barcode_type_enum barcode_type);
typedef void (*mdi_barcode_callback2) (mdi_result result, mdi_camera_decode_result_struct decode_result);

#endif

/* Parameters settings - mapping to media(driver's setting) */
#define MDI_CAMERA_EV_P4                        CAM_EV_POS_4_3
#define MDI_CAMERA_EV_P3                        CAM_EV_POS_3_3
#define MDI_CAMERA_EV_P2                        CAM_EV_POS_2_3
#define MDI_CAMERA_EV_P1                        CAM_EV_POS_1_3
#define MDI_CAMERA_EV_0                         CAM_EV_ZERO
#define MDI_CAMERA_EV_N1                        CAM_EV_NEG_1_3
#define MDI_CAMERA_EV_N2                        CAM_EV_NEG_2_3
#define MDI_CAMERA_EV_N3                        CAM_EV_NEG_3_3
#define MDI_CAMERA_EV_N4                        CAM_EV_NEG_4_3
#define MDI_CAMERA_EV_COUNT                     CAM_NO_OF_EV

#define MDI_CAMERA_EFFECT_NOMRAL                CAM_EFFECT_ENC_NORMAL
#define MDI_CAMERA_EFFECT_GRAYSCALE             CAM_EFFECT_ENC_GRAYSCALE
#define MDI_CAMERA_EFFECT_SEPIA                 CAM_EFFECT_ENC_SEPIA
#define MDI_CAMERA_EFFECT_SEPIA_GREEN           CAM_EFFECT_ENC_SEPIAGREEN
#define MDI_CAMERA_EFFECT_SEPIA_BLUE            CAM_EFFECT_ENC_SEPIABLUE
#define MDI_CAMERA_EFFECT_COLOR_INVERT          CAM_EFFECT_ENC_COLORINV
#define MDI_CAMERA_EFFECT_GRAY_INVERT           CAM_EFFECT_ENC_GRAYINV
#define MDI_CAMERA_EFFECT_BLACKBOARD            CAM_EFFECT_ENC_BLACKBOARD
#define MDI_CAMERA_EFFECT_WHITEBOARD            CAM_EFFECT_ENC_WHITEBOARD
#define MDI_CAMERA_EFFECT_COPPER_CARVING        CAM_EFFECT_ENC_COPPERCARVING
#define MDI_CAMERA_EFFECT_BLUE_CARVING          CAM_EFFECT_ENC_BLUECARVING
#define MDI_CAMERA_EFFECT_EMBOSSMENT            CAM_EFFECT_ENC_EMBOSSMENT
#define MDI_CAMERA_EFFECT_CONTRAST              CAM_EFFECT_ENC_CONTRAST
#define MDI_CAMERA_EFFECT_JEAN                  CAM_EFFECT_ENC_JEAN
#define MDI_CAMERA_EFFECT_SKETCH                CAM_EFFECT_ENC_SKETCH
#define MDI_CAMERA_EFFECT_OIL                   CAM_EFFECT_ENC_OIL
#define MDI_CAMERA_EFFECT_COUNT                 CAM_NO_OF_EFFECT_ENC

#define MDI_CAMERA_WB_AUTO                      CAM_WB_AUTO
#define MDI_CAMERA_WB_DAYLIGHT                  CAM_WB_DAYLIGHT
#define MDI_CAMERA_WB_TUNGSTEN                  CAM_WB_TUNGSTEN
#define MDI_CAMERA_WB_FLUORESCENT               CAM_WB_FLUORESCENT
#define MDI_CAMERA_WB_CLOUD                     CAM_WB_CLOUD
#define MDI_CAMERA_WB_INCANDESCENCE             CAM_WB_INCANDESCENCE
#define MDI_CAMERA_WB_MANUAL                    CAM_WB_MANUAL
#define MDI_CAMERA_WB_COUNT                     CAM_NO_OF_WB

#define MDI_CAMERA_BANDING_50HZ                 CAM_BANDING_50HZ
#define MDI_CAMERA_BANDING_60HZ                 CAM_BANDING_60HZ
#define MDI_CAMERA_BANDING_COUNT                CAM_NO_OF_BANDING

#define MDI_CAMERA_JPG_QTY_FINE                 CAM_JPG_QTY_FINE
#define MDI_CAMERA_JPG_QTY_HIGH                 CAM_JPG_QTY_HIGH
#define MDI_CAMERA_JPG_QTY_NORMAL               CAM_JPG_QTY_NORMAL
#define MDI_CAMERA_JPG_QTY_LOW                  CAM_JPG_QTY_LOW
#define MDI_CAMERA_JPG_QTY_COUNT                CAM_NO_OF_JPG_QTY

#define MDI_CAMERA_FLASH_OFF                    CAM_FLASH_OFF
#define MDI_CAMERA_FLASH_ON                     CAM_FLASH_ON
#define MDI_CAMERA_FLASH_AUTO                   CAM_FLASH_AUTO
#define MDI_CAMERA_FLASH_REDEYE                 CAM_FLASH_REDEYE
#define MDI_CAMERA_FLASH_COUNT                  CAM_NO_OF_FLASH

#define MDI_CAMERA_AE_METER_AUTO                CAM_AE_METER_AUTO
#define MDI_CAMERA_AE_METER_SPOT                CAM_AE_METER_SPOT
#define MDI_CAMERA_AE_METER_CENTER              CAM_AE_METER_CENTRAL
#define MDI_CAMERA_AE_METER_AVERAGE             CAM_AE_METER_AVERAGE
#define MDI_CAMERA_AE_METER_COUNT               CAM_NO_OF_AE_METERING

#define MDI_CAMERA_ISO_AUTO                     CAM_ISO_AUTO
#define MDI_CAMERA_ISO_100                      CAM_ISO_100
#define MDI_CAMERA_ISO_200                      CAM_ISO_200
#define MDI_CAMERA_ISO_400                      CAM_ISO_400
#define MDI_CAMERA_ISO_COUNT                    CAM_NO_OF_ISO

#define MDI_CAMERA_MWB_ADJUST                   CAM_MWB_ADJUST
#define MDI_CAMERA_MWB_BACKUP                   CAM_MWB_BACKUP
#define MDI_CAMERA_MWB_RESTORE                  CAM_MWB_RESTORE
#define MDI_CAMERA_MWB_COUNT                    CAM_NO_OF_MWB

#define MDI_CAMERA_AUTOFOCUS_1_ZONE             CAM_AF_SINGLE_ZONE
#define MDI_CAMERA_AUTOFOCUS_3_ZONE             CAM_AF_MULTI3_ZONE
#define MDI_CAMERA_AUTOFOCUS_5_ZONE             CAM_AF_MULTI5_ZONE
#define MDI_CAMERA_AUTOFOCUS_METERING_COUNT     CAM_NO_OF_AF_METERING

#define MDI_CAMERA_AUTOFOCUS_MODE_AUTO          CAM_AF_AUTO_MODE
#define MDI_CAMERA_AUTOFOCUS_MODE_MACRO         CAM_AF_MACRO_MODE
#define MDI_CAMERA_AUTOFOCUS_MODE_INFINITE      CAM_AF_INFINITE_MODE
#define MDI_CAMERA_AUTOFOCUS_MODE_MANUAL        CAM_AF_MANUAL_MODE
#define MDI_CAMERA_AUTOFOCUS_MODE_COUNT         CAM_NO_OF_AF_MODE

#define MDI_CAMERA_DSC_MODE_AUTO                CAM_AUTO_DSC
#define MDI_CAMERA_DSC_MODE_PORTRAIT            CAM_PORTRAIT
#define MDI_CAMERA_DSC_MODE_LANDSCAPE           CAM_LANDSCAPE
#define MDI_CAMERA_DSC_MODE_SPORT               CAM_SPORT
#define MDI_CAMERA_DSC_MODE_FLOWER              CAM_FLOWER
#define MDI_CAMERA_DSC_MODE_NIGHT               CAM_NIGHTSCENE
#define MDI_CAMERA_DSC_MODE_SHUTTER_PRI         CAM_TV_MODE
#define MDI_CAMERA_DSC_MODE_APERTURE_PRI        CAM_AV_MODE
#define MDI_CAMERA_DSC_MODE_ISO                 CAM_ISO_MODE
#define MDI_CAMERA_DSC_MODE_COUNT               CAM_NO_OF_SCENE_MODE

#define MDI_CAMERA_PREVIEW_ROTATE_0             CAM_IMAGE_NORMAL
#define MDI_CAMERA_PREVIEW_ROTATE_90            CAM_IMAGE_ROTATE_90
#define MDI_CAMERA_PREVIEW_ROTATE_180           CAM_IMAGE_ROTATE_180
#define MDI_CAMERA_PREVIEW_ROTATE_270           CAM_IMAGE_ROTATE_270
#define MDI_CAMERA_PREVIEW_ROTATE_0_MIRROR      CAM_IMAGE_MIRROR
#define MDI_CAMERA_PREVIEW_ROTATE_90_MIRROR     CAM_IMAGE_MIRROR_ROTATE_90
#define MDI_CAMERA_PREVIEW_ROTATE_180_MIRROR    CAM_IMAGE_MIRROR_ROTATE_180
#define MDI_CAMERA_PREVIEW_ROTATE_270_MIRROR    CAM_IMAGE_MIRROR_ROTATE_270

#if defined(ISP_SUPPORT)
#define MDI_CAMERA_LCM_ROTATE_0              LCD_LAYER_ROTATE_NORMAL
#define MDI_CAMERA_LCM_ROTATE_90             LCD_LAYER_ROTATE_90
#define MDI_CAMERA_LCM_ROTATE_180            LCD_LAYER_ROTATE_180
#define MDI_CAMERA_LCM_ROTATE_270            LCD_LAYER_ROTATE_270
#define MDI_CAMERA_LCM_ROTATE_0_MIRROR       LCD_LAYER_MIRROR
#define MDI_CAMERA_LCM_ROTATE_90_MIRROR      LCD_LAYER_MIRROR_ROTATE_90
#define MDI_CAMERA_LCM_ROTATE_180_MIRROR     LCD_LAYER_MIRROR_ROTATE_180
#define MDI_CAMERA_LCM_ROTATE_270_MIRROR     LCD_LAYER_MIRROR_ROTATE_270

#define MDI_CAMERA_POST_EFFECT_NORMAL        CAM_EFFECT_DEC_NORMAL
#define MDI_CAMERA_POST_EFFECT_GRAYSCALE     CAM_EFFECT_DEC_GRAYSCALE
#define MDI_CAMERA_POST_EFFECT_SEPIA         CAM_EFFECT_DEC_SEPIA
#define MDI_CAMERA_POST_EFFECT_SEPIAGREEN    CAM_EFFECT_DEC_SEPIAGREEN
#define MDI_CAMERA_POST_EFFECT_SEPIABLUE     CAM_EFFECT_DEC_SEPIABLUE
#define MDI_CAMERA_POST_EFFECT_COLORINV      CAM_EFFECT_DEC_COLORINV
#define MDI_CAMERA_POST_EFFECT_GRAYINV       CAM_EFFECT_DEC_GRAYINV
#define MDI_CAMERA_POST_EFFECT_WATERCOLOR    CAM_EFFECT_DEC_WATERCOLOR
#define MDI_CAMERA_POST_EFFECT_LIGHTBLUR     CAM_EFFECT_DEC_LIGHTBLUR
#define MDI_CAMERA_POST_EFFECT_BLUR          CAM_EFFECT_DEC_BLUR
#define MDI_CAMERA_POST_EFFECT_STRONGBLUR    CAM_EFFECT_DEC_STRONGBLUR
#define MDI_CAMERA_POST_EFFECT_UNSHARP       CAM_EFFECT_DEC_UNSHARP
#define MDI_CAMERA_POST_EFFECT_SHARPEN       CAM_EFFECT_DEC_SHARPEN
#define MDI_CAMERA_POST_EFFECT_MORESHARPEN   CAM_EFFECT_DEC_MORESHARPEN
#define MDI_CAMERA_POST_EFFECT_MEDIAN        CAM_EFFECT_DEC_MEDIAN
#define MDI_CAMERA_POST_EFFECT_DILATION      CAM_EFFECT_DEC_DILATION
#define MDI_CAMERA_POST_EFFECT_EROSION       CAM_EFFECT_DEC_EROSION

#define MDI_CAMERA_ADJUSMENT_BRIGHTNESS      CAM_ADJ_DEC_BRIGHTNESS
#define MDI_CAMERA_ADJUSMENT_CONTRAST        CAM_ADJ_DEC_CONTRAST
#define MDI_CAMERA_ADJUSMENT_SATURATION      CAM_ADJ_DEC_SATURATION
#define MDI_CAMERA_ADJUSMENT_HUE             CAM_ADJ_DEC_HUE
#define MDI_CAMERA_ADJUSMENT_COLOR_R         CAM_ADJ_DEC_ADJR
#define MDI_CAMERA_ADJUSMENT_COLOR_G         CAM_ADJ_DEC_ADJG
#define MDI_CAMERA_ADJUSMENT_COLOR_B         CAM_ADJ_DEC_ADJB
#else /* defined(ISP_SUPPORT) */ 
#define MDI_CAMERA_LCM_ROTATE_0              0
#define MDI_CAMERA_LCM_ROTATE_90             1
#define MDI_CAMERA_LCM_ROTATE_180            2
#define MDI_CAMERA_LCM_ROTATE_270            3
#define MDI_CAMERA_LCM_ROTATE_0_MIRROR       4
#define MDI_CAMERA_LCM_ROTATE_90_MIRROR      5
#define MDI_CAMERA_LCM_ROTATE_180_MIRROR     6
#define MDI_CAMERA_LCM_ROTATE_270_MIRROR     7

#define MDI_CAMERA_POST_EFFECT_NORMAL        0
#define MDI_CAMERA_POST_EFFECT_GRAYSCALE     1
#define MDI_CAMERA_POST_EFFECT_SEPIA         2
#define MDI_CAMERA_POST_EFFECT_SEPIAGREEN    3
#define MDI_CAMERA_POST_EFFECT_SEPIABLUE     4
#define MDI_CAMERA_POST_EFFECT_COLORINV      5
#define MDI_CAMERA_POST_EFFECT_GRAYINV       6
#define MDI_CAMERA_POST_EFFECT_WATERCOLOR    7
#define MDI_CAMERA_POST_EFFECT_LIGHTBLUR     8
#define MDI_CAMERA_POST_EFFECT_BLUR          9
#define MDI_CAMERA_POST_EFFECT_STRONGBLUR    10
#define MDI_CAMERA_POST_EFFECT_UNSHARP       11
#define MDI_CAMERA_POST_EFFECT_SHARPEN       12
#define MDI_CAMERA_POST_EFFECT_MORESHARPEN   13
#define MDI_CAMERA_POST_EFFECT_MEDIAN        14
#define MDI_CAMERA_POST_EFFECT_DILATION      15
#define MDI_CAMERA_POST_EFFECT_EROSION       16

#define MDI_CAMERA_ADJUSMENT_BRIGHTNESS      0
#define MDI_CAMERA_ADJUSMENT_CONTRAST        1
#define MDI_CAMERA_ADJUSMENT_SATURATION      2
#define MDI_CAMERA_ADJUSMENT_HUE             3
#define MDI_CAMERA_ADJUSMENT_COLOR_R         4
#define MDI_CAMERA_ADJUSMENT_COLOR_G         5
#define MDI_CAMERA_ADJUSMENT_COLOR_B         6
#endif /* defined(ISP_SUPPORT) */ 


#define MDI_CAMERA_JPEG_RESIZER_UPPER_BOUND  (640*480*GDI_MAINLCD_BIT_PER_PIXEL)>>3

/***************************************************************************** 
* Typedef
*****************************************************************************/
/* preview on which LCM */
typedef enum
{
    MDI_CAMERA_PREVIEW_LCM_MAINLCD = 0,
    MDI_CAMERA_PREVIEW_LCM_SUBLCD,
    MDI_CAMERA_PREVIEW_LCM_COUNT
} mdi_camera_preview_lcm_enum;

/* flash, led highlight */
typedef struct
{
    U8 r;
    U8 g;
    U8 b;
} mdi_camera_flash_struct;

typedef struct
{
    kal_uint32 mwb_buffer_address;
    kal_uint16 mwb_image_width;
    kal_uint16 mwb_image_height;
} mdi_camera_mwb_process_struct;

/* setting */
typedef struct
{
    U16 wb;
    U16 ev;
    U16 zoom;
    U16 effect;
    U16 image_qty;
    U16 image_width;
    U16 image_height;
    U16 preview_width;
    U16 preview_height;
    U16 night;
    U16 banding;
    U16 lcm;
    U16 preview_rotate;
    U16 lcm_rotate;
    U16 brightness;
    U16 saturation;
    U16 contrast;
    U16 hue;
    U16 flash;
    U16 ae_meter;
    U16 iso;
    U16 dsc_mode;
    U16 osd_rotate;
    U16 af_metering_mode;
    U16 af_mode;
    U16 shutter_pri;
    U16 aperture_pri;
    BOOL manual_wb;

    U8 continue_capture;

   /***************************
   * Color Index Overlay
   ***************************/
    BOOL overlay_frame_mode;
    U8 overlay_frame_depth;
    U8 overlay_frame_source_key;
    U16 overlay_frame_width;
    U16 overlay_frame_height;
    U32 overlay_frame_buffer_address;

   /***************************
   * AF
   ***************************/
    kal_uint16 af_zone0_x;  /* AF Zone 0 X-coordinate, (0,0) means left-top corner */
    kal_uint16 af_zone0_y;  /* AF Zone 0 Y-coordinate */
    kal_uint16 af_zone1_x;  /* AF Zone 1 X-coordinate */
    kal_uint16 af_zone1_y;  /* AF Zone 1 Y-coordinate */
    kal_uint16 af_zone2_x;  /* AF Zone 2 X-coordinate */
    kal_uint16 af_zone2_y;  /* AF Zone 2 Y-coordinate */
    kal_uint16 af_zone3_x;  /* AF Zone 3 X-coordinate */
    kal_uint16 af_zone3_y;  /* AF Zone 3 Y-coordinate */
    kal_uint16 af_zone4_x;  /* AF Zone 4 X-coordinate */
    kal_uint16 af_zone4_y;  /* AF Zone 4 Y-coordinate */
} mdi_camera_setting_struct;

/* preview window data */
typedef struct
{
    gdi_handle preview_layer_handle;
    S32 preview_wnd_offset_x;
    S32 preview_wnd_offset_y;
    U16 preview_wnd_width;
    U16 preview_wnd_height;
    U32 blt_layer_flag;
    U32 preview_layer_flag;
    BOOL is_lcd_update;
    U16 src_key_color;
    BOOL is_tvout;
    void (*xenon_flash_status_callback) (mdi_result);
} mdi_camera_preview_struct;

/* mdi camera context */
typedef struct
{
    mdi_camera_setting_struct setting;
    mdi_camera_preview_struct preview;

    mdi_camera_mwb_process_struct mwb;

    U16 state;
    U16 seq_num;
    BOOL is_preview_stopped;
    BOOL is_tvout;
    U16 burst_cap_count;
    U16 tvout_prev_owner;

#if MDI_CAMERA_MT6228_SERIES
    /* info for burst capture for MT6228  and after */
    U8 lcd_id;
    U16 lcm_start_x;
    U16 lcm_start_y;
    U16 lcm_end_x;
    U16 lcm_end_y;
    U16 roi_offset_x;
    U16 roi_offset_y;
    S32 tv_output_offset_x;
    S32 tv_output_offset_y;
    U32 update_layer;
    U32 hw_update_layer;
    void *frame_buf_ptr;
    U32 frame_buf_size;
#endif /* MDI_CAMERA_MT6228_SERIES */ 

} mdi_camera_context_struct;

/* define as media stask's structure */
#define mdi_camera_jpegs_struct     jpegs_struct

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* init */
extern MDI_RESULT mdi_camera_init(void);

/* power on/off camera module */
extern MDI_RESULT mdi_camera_power_on(void);
extern MDI_RESULT mdi_camera_power_off(void);

/* start/stop  preview */
extern MDI_RESULT mdi_camera_preview_start(
                    mdi_camera_preview_struct *preview_p,
                    mdi_camera_setting_struct *setting_p);

extern MDI_RESULT mdi_camera_preview_stop(void);

/* capture */
extern MDI_RESULT mdi_camera_capture_to_file(S8 *file_name, U8 continue_capture);
extern MDI_RESULT mdi_camera_capture_to_memory(U8 **buf_pp, U32 *captured_size);

extern MDI_RESULT mdi_camera_capture_layer_to_file(
                    U32 capture_layer_flag,
                    S8 *filename,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height,
                    U8 continue_capture);

extern MDI_RESULT mdi_camera_capture_layer_to_memory(
                    U32 capture_layer_flag,
                    U8 **buf_pp,
                    U32 *captured_size,
                    S32 offset_x,
                    S32 offset_y,
                    S32 width,
                    S32 height);

extern MDI_RESULT mdi_camera_burst_capture_to_memory(U32 capture_count, mdi_camera_jpegs_struct *jpgs_ptr);

extern MDI_RESULT mdi_camera_non_block_burst_capture_to_memory(U32 capture_count,
                                                               mdi_camera_jpegs_struct *jpgs_ptr,
                                                               void (*capture_result_callback) (MDI_RESULT, U16));

extern MDI_RESULT mdi_camera_stop_non_block_burst_capture(void);

extern void mdi_camera_stop_autofocus_process(void);
extern void mdi_camera_start_autofocus_process(mdi_callback handler);

extern void mdi_camera_stop_mf_continue(void);
extern void mdi_camera_mf_backward(void);
extern void mdi_camera_mf_forward(void);
extern void mdi_camera_start_mf_continue(BOOL is_forward);
extern MMI_BOOL mdi_camera_get_focus_steps(U32 *total_steps, U32 *current_steps);

extern MDI_RESULT mdi_camera_adjust_mwb(U32 capture_layer_flag, S32 offset_x, S32 offset_y, S32 width, S32 height);
extern void mdi_camera_restore_mwb(void);
extern void mdi_camera_backup_mwb(void);
extern void mdi_camera_set_overlay_palette(U8 palette_size, U32 *palette_addr_ptr);

/* parameters */
extern void mdi_camera_update_para_banding(U16 cam_para);
extern void mdi_camera_update_para_ev(U16 cam_para);
extern void mdi_camera_update_para_zoom(U16 cam_para);
extern void mdi_camera_update_para_effect(U16 cam_para);
extern void mdi_camera_update_para_wb(U16 cam_para);
extern void mdi_camera_update_para_brightness(U16 cam_para);
extern void mdi_camera_update_para_saturation(U16 cam_para);
extern void mdi_camera_update_para_contrast(U16 cam_para);
extern void mdi_camera_update_para_hue(U16 cam_para);
extern void mdi_camera_update_para_night(U16 cam_pra);
extern void mdi_camera_update_para_ev_adjust(U16 cam_pra);

extern void mdi_camera_update_para_image_qty(U16 cam_para);
extern void mdi_camera_update_para_image_size(U16 image_width, U16 image_height);
extern void mdi_camera_update_para_flash(U16 cam_para);
extern void mdi_camera_update_para_iso(U16 cam_para);
extern void mdi_camera_update_para_ae_meter(U16 cam_para);
extern void mdi_camera_update_para_dsc_mode(U16 cam_para);
extern void mdi_camera_update_para_shutter_pri(U16 cam_para);
extern void mdi_camera_update_para_aperture_pri(U16 cam_para);
extern void mdi_camera_update_para_af_key(U16 cam_para);
extern void mdi_camera_update_para_af_mode(U16 cam_para);
extern void mdi_camera_update_para_af_metering(U16 cam_para);
extern void mdi_camera_update_para_manual_focus_dir(U16 cam_para);

/* check state */
extern BOOL mdi_camera_is_ready_to_capture(void);

/* post-effect */
extern void mdi_camera_add_post_effect(gdi_handle layer_handle, U16 effect_id);
extern void mdi_camera_add_post_adjustment(gdi_handle layer_handle, U16 adjustment_id, S32 value);

/* fast zoomin */
extern void mdi_camera_start_fast_zoom(BOOL zoom_in, U8 zoom_limit, U8 zoom_step, U8 zoom_speed);
extern void mdi_camera_stop_fast_zoom(void);
extern void mdi_camera_get_fast_zoom_factor(U8 *factor);
extern U16 mdi_camera_get_max_zoom_factor(S32 image_width, S32 image_height);

extern MDI_RESULT mdi_camera_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name);
extern void mdi_camera_blocked_recovery(void);

extern void mdi_camera_load_default_setting(mdi_camera_setting_struct *camera_setting_data);
extern void mdi_camera_flash_setting(BOOL is_on);

#ifdef BARCODE_SUPPORT
extern MDI_RESULT mdi_camera_capture_and_decode_barcode(PS8 text_buf, S32 buf_length, mdi_barcode_callback handler, U8 barcode_type);
extern void mdi_camera_stop_capture_and_decode_barcode(void);
extern MDI_RESULT mdi_camera_barcodereader_preview_start(
                    gdi_handle preview_layer_handle,
                    S32 preview_wnd_offset_x,
                    /* offset from lcd's left up corner */ S32 preview_wnd_offset_y,
                    /* offset from lcd's left up corner */ U16 preview_wnd_width,
                    /* preview window width */ U16 preview_wnd_height,
                    /* preview window height */ U32 blt_layer_flag,
                    /* which layer shall be blt by driver */ U32 preview_layer_flag,
                    /* preview on which layer */ gdi_color src_key_color,
                    /* src key color */ BOOL is_tvout,
                    /* is display preview on tvout */ mdi_camera_setting_struct *setting_p);

extern MDI_RESULT mdi_camera_barcodereader_preview_stop(void);
#endif /* BARCODE_SUPPORT */

#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
MDI_RESULT mdi_camera_capture_to_memory_direct_couple(U8 **buf_pp, U32 *captured_size, U32 dc_buf_addr, S32 buf_size, S32 width, S32 height);
#endif

/* hongzhe.liu add start */
#ifdef ANALOG_TV_SUPPORT
extern MDI_RESULT mdi_camera_analog_tv_preview_start(
                    gdi_handle preview_layer_handle,
                    S32 preview_wnd_offset_x,
                    /* offset from lcd's left up corner */ S32 preview_wnd_offset_y,
                    /* offset from lcd's left up corner */ U16 preview_wnd_width,
                    /* preview window width */ U16 preview_wnd_height,
                    /* preview window height */ U32 blt_layer_flag,
                    /* which layer shall be blt by driver */ U32 preview_layer_flag,
                    /* preview on which layer */ gdi_color src_key_color,
                    /* src key color */ BOOL is_tvout,
                    /* is display preview on tvout */ mdi_camera_setting_struct *setting_p);
extern MDI_RESULT mdi_camera_analog_tv_preview_stop();
#endif
/* hongzhe.liu add end */

#endif /* __MMI_CAMERA__ */ 
#endif /* _MDI_CAMERA_H_ */ /* _CAMERA_API_H_ */

