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
 *  mdi_camera.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access camera related functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_CAMERA__

#include "stdC.h"
#include "L4Dr1.h"

#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "QueueGprot.h" /* message handling */
#include "fat_fs.h"
#include "gdi_include.h"        /* include data type */
#include "gui.h"
#include "med_api.h"
#include "mdi_datatype.h"
#include "med_api.h"    /* media task */

#ifdef __SW_JPEG_CODEC_SUPPORT__
#include "jpeg.h"
#endif

#include "mdi_camera.h" /* include camera related define */
#include "EventsGprot.h"        /* event hadnling - get message return from camera driver */
#include "gpioInc.h"    /* avoid sleep when using camera */
#include "fat_fs.h"

#include "lcd_if.h"
#include "lcd_sw_rnd.h"

#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"

#if defined(ISP_SUPPORT)
   /* for visual effect */
#ifdef __MTK_TARGET__
#include "reg_base.h"
#include "IntrCtrl.h"
#include "drv_comm.h"
#include "drvpdn.h"
#include "jpeg.h"
#include "visualhisr.h"
#include "visual_comm.h"
#include "fat_fs.h"
#include "resizer.h"
#include "isp_if.h"
#include "imgproc.h"
#include "img_comm.h"
#include "imgdma.h"
#include "Image_effect.h"
#endif /* __MTK_TARGET__ */ /* ISP_SUPPORT */
#endif /* defined(ISP_SUPPORT) */ 

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

/***************************************************************************** 
* Typedef
*****************************************************************************/
/* camera state machine */
typedef enum
{
    CAMERA_STATE_POWER_OFF = 0,
    CAMERA_STATE_IDLE,
    CAMERA_STATE_PREVIEWING,
    CAMERA_STATE_BARCODE_CAPTURING
} mdi_camera_state_enum;


#define MDI_CAMERA_CHECK_FOCUS(_X_)\
do{\
    if (camera_setting_p->af_zone##_X_##_x == 0 && camera_setting_p->af_zone##_X_##_y == 0)\
    {\
        cam_preview_data.af_zone##_X_##_x = layer_offset_x + cam_preview_data.preview_width/2;\
        cam_preview_data.af_zone##_X_##_y = layer_offset_y + cam_preview_data.preview_height/2;\
    }\
    else\
    {\
        cam_preview_data.af_zone##_X_##_x = camera_setting_p->af_zone##_X_##_x;\
        cam_preview_data.af_zone##_X_##_y = camera_setting_p->af_zone##_X_##_y;\
    }\
}while(0)

/***************************************************************************** 
* Local Variable
*****************************************************************************/
mdi_camera_context_struct g_mdi_camera_cntx;
mdi_camera_context_struct *mdi_camera_p = &g_mdi_camera_cntx;
mdi_camera_setting_struct *camera_setting_p = &g_mdi_camera_cntx.setting;
mdi_camera_preview_struct *camera_preview_p = &g_mdi_camera_cntx.preview;

mdi_camera_mwb_process_struct *camera_mwb_p = &g_mdi_camera_cntx.mwb;

static mdi_callback cameraCurrentHandler;


/* callback function */
void (*mdi_camera_non_block_burst_shot_result_callback) (MDI_RESULT, U16) = NULL;

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    void (*mdi_xenon_flash_status_callback) (MDI_RESULT) = NULL;
#endif

/***************************************************************************** 
* Local Function
*****************************************************************************/
static MDI_RESULT mdi_camera_preview_start_internal(void);
static void mdi_camera_af_finish_ind(void *inMsg);

#ifdef BARCODE_SUPPORT
static mdi_barcode_callback barcodeCurrentHandler;
static void mdi_camera_barcode_decode_finish_ind(void *inMsg);
static MDI_RESULT mdi_camera_barcodereader_preview_start_internal(void);
#endif

#if MDI_CAMERA_MT6228_SERIES
static void mdi_camera_non_block_burst_capture_result_hdlr(void *msg_ptr);
#endif 

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
static void mdi_camera_xenon_flash_ind(void *inMsg);
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_xenon_flash_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_camera_xenon_flash_ind(void *inMsg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_xenon_flash_ind_struct *msg_p = (media_cam_xenon_flash_ind_struct*) inMsg;
    U16 status = msg_p->status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_xenon_flash_status_callback)
    {   
        switch (status)
        {
            case CAM_XENON_FLASH_READY:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_SUCCEED);
                break;
            case CAM_XENON_FLASH_CHARGING:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_XENONFLASH_CHARGING);
                break;
            case CAM_XENON_FLASH_TIMEOUT:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT);
                break;
            case CAM_XENON_FLASH_LOW_BATTERY:
                mdi_xenon_flash_status_callback(MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY);
                break;
        }
    }
#endif /* __MTK_TARGET__ */ 
}
#endif /* __MDI_CAMERA_XENON_FLASH_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_init
 * DESCRIPTION
 *  init MDI Camera
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
    mdi_camera_p->seq_num = 0;
    mdi_camera_p->burst_cap_count = 0;

    return MDI_RES_CAMERA_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_power_on
 * DESCRIPTION
 *  power on the camera module
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_power_on()
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if state is right */
    ASSERT(mdi_camera_p->state == CAMERA_STATE_POWER_OFF);

    ret = media_cam_power_up(stack_int_get_active_module_id(), mdi_camera_p->seq_num);

    if (ret == MED_RES_OK)
    {
        /* Power On succeed */
        mdi_camera_p->state = CAMERA_STATE_IDLE;
        return MDI_RES_CAMERA_SUCCEED;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_power_off
 * DESCRIPTION
 *  power off the camera module
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_power_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_power_down(stack_int_get_active_module_id(), 100);

    mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
    mdi_camera_p->seq_num++;

    return MDI_RES_CAMERA_SUCCEED;

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start
 * DESCRIPTION
 *  start preview
 * PARAMETERS
 *  preview_p                   [IN]        Preview data
 *  setting_p                   [IN]        Setting data
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_preview_start(
            mdi_camera_preview_struct *preview_p,
            mdi_camera_setting_struct *setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg check */
    ASSERT(preview_p->blt_layer_flag > 0);
    ASSERT(preview_p->preview_layer_flag > 0);

    g_mdi_camera_cntx.is_tvout = preview_p->is_tvout;

    /* 
     * Note, src_key_color in camera_preview_p only needs for MT6218 with backend, for MT6218,
     * we only support 16 bit color depth, so, U16 is enoguth 
     */
     
    /* init camera parameters */
    memcpy(camera_preview_p, preview_p, sizeof(mdi_camera_preview_struct));
    memcpy(camera_setting_p, setting_p, sizeof(mdi_camera_setting_struct));

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    mdi_xenon_flash_status_callback = preview_p->xenon_flash_status_callback;
    SetProtocolEventHandler(mdi_camera_xenon_flash_ind, MSG_ID_MEDIA_CAM_XENON_FLASH_STATUS_IND);
#endif

    if (mdi_camera_p->state == CAMERA_STATE_IDLE)
    {
        ret = mdi_camera_preview_start_internal();

        if (ret >= 0)
        {
            /* preview successfully */
            mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        }

        return ret;
    }
    else
    {
        /* start preview at wrong state */
    #ifndef __MTK_TARGET__  /* MNT Simulator */
        /* on MNT, direct call internal function for debugging */
        mdi_camera_preview_start_internal();
        return MDI_RES_CAMERA_SUCCEED;

    #else /* __MTK_TARGET__ */ 
        /* Target */
        return MDI_RES_CAMERA_ERR_FAILED;
    #endif /* __MTK_TARGET__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_start_internal
 * DESCRIPTION
 *  init MDI Camera
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static MDI_RESULT mdi_camera_preview_start_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct cam_preview_data;

    U8 *buf_ptr;
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U8 layer_rotate;    
    MDI_RESULT ret;
    S32 lcd_width;
    S32 lcd_height;
    S32 lcd_offset_x;
    S32 lcd_offset_y;
    S32 lcd_start_x;
    S32 lcd_start_y;
    S32 lcd_end_x;
    S32 lcd_end_y;
    S32 clip_x1,clip_x2,clip_y1,clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if preview on sublcd, set sublcd active, so we may get correct paramater from following functions */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_SUBLCD)
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    }

    /* get layer info */
    gdi_layer_push_and_set_active(camera_preview_p->preview_layer_handle);

    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gdi_layer_get_clip(&clip_x1,&clip_y1,&clip_x2,&clip_y2);
    layer_rotate = gdi_layer_get_rotate();
    gdi_layer_pop_and_restore_active();

    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_SUBLCD)
    {
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }

    /* preview on whihc lcm */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_MAINLCD)
    {
        cam_preview_data.lcd_id = MAIN_LCD;
        lcd_width = LCD_WIDTH;
        lcd_height = LCD_HEIGHT;
    }
    else
    {
        cam_preview_data.lcd_id = SUB_LCD;
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }

    cam_preview_data.camera_offset_x = (layer_offset_x < 0) ? 0 : layer_offset_x;
    cam_preview_data.camera_offset_y = (layer_offset_y < 0) ? 0 : layer_offset_y;

    cam_preview_data.preview_width = camera_setting_p->preview_width;
    cam_preview_data.preview_height = camera_setting_p->preview_height;

    if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270_MIRROR))
    {
        lcd_offset_x = GDI_LCD_WIDTH - layer_offset_y - clip_y2 - 1;
        lcd_offset_y = layer_offset_x + clip_x1;
    }
    else if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90) ||
             (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90_MIRROR))
    {
        lcd_offset_x = layer_offset_y + clip_y1;
        lcd_offset_y = GDI_LCD_HEIGHT - layer_offset_x - clip_x2 - 1;
    }
    else
    {
    #if defined(GDI_USING_LAYER_ROTATE)
        if (layer_rotate == LCD_LAYER_ROTATE_90)
        {
            lcd_offset_x = GDI_LCD_WIDTH - layer_offset_y - clip_y2;
            lcd_offset_y = layer_offset_x + clip_x1;
        }
        else
    #endif /* defined(GDI_USING_LAYER_ROTATE) */ 
        {
            lcd_offset_x = layer_offset_x + clip_x1;
            lcd_offset_y = layer_offset_y + clip_y1;
        }        
    }

    lcd_start_x = lcd_offset_x;
    lcd_start_y = lcd_offset_y;

    if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270_MIRROR) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90_MIRROR))
    {
        /* rotate 90 or 270 for horizonal view */
        lcd_end_x = lcd_offset_x + (clip_y2 - clip_y1);
        lcd_end_y = lcd_offset_y + (clip_x2 - clip_x1);
    }
    else
    {
        lcd_end_x = lcd_offset_x + (clip_x2 - clip_x1);
        lcd_end_y = lcd_offset_y + (clip_y2 - clip_y1);
    }

    PRINT_INFORMATION_2(MMI_TRACE_G8_MEDIA, "lsx=%d,lsy=%d,lex=%d,ley=%d,lox=%d,loy=%d,cx1=%d,cy1=%d,cx2=%d,cy2=%d",lcd_start_x,lcd_start_y,lcd_end_x,lcd_end_y,layer_offset_x,layer_offset_y,clip_x1,clip_y1,clip_x2,clip_y2);

    /* force inside lcd region */
    if (lcd_start_x < 0)
    {
        lcd_start_x = 0;
    }
    else if (lcd_start_x > UI_device_width - 1)
    {
        lcd_start_x = UI_device_width - 1;
    }

    if (lcd_start_y < 0)
    {
        lcd_start_y = 0;
    }
    else if (lcd_start_y > UI_device_height - 1)
    {
        lcd_start_y = UI_device_height - 1;
    }

    if (lcd_end_x < 0)
    {
        lcd_end_x = 0;
    }
    else if (lcd_end_x > UI_device_width - 1)
    {
        lcd_end_x = UI_device_width - 1;
    }

    if (lcd_end_y < 0)
    {
        lcd_end_y = 0;
    }
    else if (lcd_end_y > UI_device_height - 1)
    {
        lcd_end_y = UI_device_height - 1;
    }

    if (gdi_lcd_get_rotate_by_layer())
    {
        /* if using LCD rotate, the roi region will be the phisical potion as lcd */
        cam_preview_data.roi_offset_x = GDI_LAYER_OFFSET + lcd_offset_x;
        cam_preview_data.roi_offset_y = GDI_LAYER_OFFSET + lcd_offset_y;
    }
    else
    {
        /* if using LCM rotate, layers are rotated, so the position is the same as layer pos */
        cam_preview_data.roi_offset_x = GDI_LAYER_OFFSET + layer_offset_x;
        cam_preview_data.roi_offset_y = GDI_LAYER_OFFSET + layer_offset_y;
    }


    /* force inside lcd region */
    if (cam_preview_data.roi_offset_x < GDI_LAYER_OFFSET)
    {
        cam_preview_data.roi_offset_x = GDI_LAYER_OFFSET;
    }
    else if (cam_preview_data.roi_offset_x > GDI_LAYER_OFFSET + UI_device_width - 1)
    {
        cam_preview_data.roi_offset_x = GDI_LAYER_OFFSET + UI_device_width - 1;
    }

    if (cam_preview_data.roi_offset_y < GDI_LAYER_OFFSET)
    {
        cam_preview_data.roi_offset_y = GDI_LAYER_OFFSET;
    }
    else if (cam_preview_data.roi_offset_y > GDI_LAYER_OFFSET + UI_device_height - 1)
    {
        cam_preview_data.roi_offset_y = GDI_LAYER_OFFSET + UI_device_height - 1;
    }

    cam_preview_data.lcd_start_x = lcd_start_x;
    cam_preview_data.lcd_start_y = lcd_start_y;
    cam_preview_data.lcd_end_x = lcd_end_x;
    cam_preview_data.lcd_end_y = lcd_end_y;   
    cam_preview_data.lcd_update = camera_preview_p->is_lcd_update;

    /* preview offset x, y are offset from lcd_start_x, lcd_start_y */
    cam_preview_data.preview_offset_x = 0; /* not used */
    cam_preview_data.preview_offset_y = 0; /* not used */

    cam_preview_data.image_buffer_p = (void*)buf_ptr;
    cam_preview_data.image_width = (kal_uint16) camera_setting_p->image_width;
    cam_preview_data.image_height = (kal_uint16) camera_setting_p->image_height;

    cam_preview_data.buffer_width = (kal_uint16) layer_width;
    cam_preview_data.buffer_height = (kal_uint16) layer_height;
    cam_preview_data.image_buffer_size =
        (kal_uint32) ((camera_setting_p->preview_width * camera_setting_p->preview_height *
                       GDI_LAYER.act_bit_per_pixel) >> 3);

    /* set settings parameters */
    cam_preview_data.effect = (kal_uint16) camera_setting_p->effect;
    cam_preview_data.WB = (kal_uint16) camera_setting_p->wb;
    cam_preview_data.exposure = (kal_uint16) camera_setting_p->ev;
    cam_preview_data.zoom_factor = (kal_uint16) camera_setting_p->zoom;
    cam_preview_data.banding_freq = (kal_uint8) camera_setting_p->banding;
    cam_preview_data.flash_mode = (kal_uint16) camera_setting_p->flash;

    cam_preview_data.brightness = (kal_uint16) camera_setting_p->brightness;
    cam_preview_data.contrast = (kal_uint16) camera_setting_p->contrast;
    cam_preview_data.saturation = (kal_uint16) camera_setting_p->saturation;
    cam_preview_data.hue = (kal_uint16) camera_setting_p->hue;
    cam_preview_data.night_mode = (kal_bool) camera_setting_p->night;
    cam_preview_data.snapshot_number = 1;

    cam_preview_data.continue_capture = (kal_uint8) camera_setting_p->continue_capture;

#if ( MDI_CAMERA_MT6225_SERIES || MDI_CAMERA_MT6227_SERIES)
    cam_preview_data.ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data.dsc_mode = (kal_uint8) camera_setting_p->dsc_mode;
    cam_preview_data.af_metering_mode = (kal_uint8) camera_setting_p->af_metering_mode;
    cam_preview_data.af_mode = (kal_uint8) camera_setting_p->af_mode;
    cam_preview_data.iso_setting = (kal_uint8) camera_setting_p->iso;
#elif (MDI_CAMERA_MT6228_SERIES)
    cam_preview_data.ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data.iso_setting = (kal_uint8) camera_setting_p->iso;
    cam_preview_data.dsc_mode = (kal_uint8) camera_setting_p->dsc_mode;
    cam_preview_data.tv_setting = (kal_uint16) camera_setting_p->shutter_pri;
    cam_preview_data.av_setting = (kal_uint8) camera_setting_p->aperture_pri;
    cam_preview_data.af_metering_mode = (kal_uint8) camera_setting_p->af_metering_mode;
    cam_preview_data.af_mode = (kal_uint8) camera_setting_p->af_mode;

    cam_preview_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    cam_preview_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    cam_preview_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    cam_preview_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    cam_preview_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    cam_preview_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
    #ifdef __MTK_TARGET__
    cam_preview_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    cam_preview_data.image_pitch_mode = FALSE;
    cam_preview_data.tv_output = FALSE;
#endif 

    MDI_CAMERA_CHECK_FOCUS(0);
    MDI_CAMERA_CHECK_FOCUS(1);
    MDI_CAMERA_CHECK_FOCUS(2);
    MDI_CAMERA_CHECK_FOCUS(3);
    MDI_CAMERA_CHECK_FOCUS(4);

    /* rotate */
    cam_preview_data.rotate = camera_setting_p->preview_rotate;
    cam_preview_data.lcd_rotate = camera_setting_p->lcm_rotate;

    /* fixed para */
    cam_preview_data.gamma = 0;
    cam_preview_data.frame_rate = CAMERA_PERVIEW_FRAME_RATE;

    cam_preview_data.update_layer = camera_preview_p->blt_layer_flag;
    cam_preview_data.hw_update_layer = camera_preview_p->preview_layer_flag;
    cam_preview_data.src_key_color = camera_preview_p->src_key_color;   /* GDI_COLOR_TRANSPARENT */
    cam_preview_data.roi_background_color = GDI_COLOR_BLACK;

#if (MDI_CAMERA_MT6228_SERIES)
    cam_preview_data.tv_output = FALSE;
#endif 

    /* TV out */
#ifdef __MMI_TVOUT__

    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            /* set tvout owner to Camera */
            g_mdi_camera_cntx.tvout_prev_owner = mdi_tvout_get_owner();

            if (g_mdi_camera_cntx.tvout_prev_owner != MDI_TV_OWNER_CAMERA)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_CAMERA);
            }

            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_CAMERA,
                    (PU16) & cam_preview_data.tv_output_mode,     /* mode_ptr */
                    (PU16) & cam_preview_data.tv_output_width, /* buf_width_ptr */
                    (PU16) & cam_preview_data.tv_output_height,        /* buf_height_ptr */
                    (PU32) & cam_preview_data.tv_output_buffer_size,   /* buf size */
                    (PU8*) & cam_preview_data.tv_output_buffer1_address,      /* buf1 pp */
                    (PU8*) & cam_preview_data.tv_output_buffer2_address,      /* buf2 pp */
                    NULL,      /* rotate_buf_1_pp */
                    NULL);     /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                cam_preview_data.tv_output = TRUE;
            #if 0    
            #ifdef LCM_ROTATE_SUPPORT
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
            #else /* LCM_ROTATE_SUPPORT */ 
/* under construction !*/
/* under construction !*/
            #endif /* LCM_ROTATE_SUPPORT */       
            #endif 

            if (gdi_lcd_get_rotate_by_layer())
            {
                /* if using LCD rotate, the roi region will be the phisical potion as lcd */
                cam_preview_data.tv_output_offset_x = (lcd_offset_x < 0) ? 0 : lcd_offset_x;
                cam_preview_data.tv_output_offset_y = (lcd_offset_y < 0) ? 0 : lcd_offset_y;
            }
            else
            {
                /* if using LCM rotate, layers are rotated, so the position is the same as layer pos */
                cam_preview_data.tv_output_offset_x = (layer_offset_x < 0) ? 0 : layer_offset_x;
                cam_preview_data.tv_output_offset_y = (layer_offset_y < 0) ? 0 : layer_offset_y;
            }
            
            }
            else
            {
                /* tvout not enable , restore owner to GDI */
                if (g_mdi_camera_cntx.tvout_prev_owner != MDI_TV_OWNER_CAMERA)
                {
                    mdi_tvout_set_owner(g_mdi_camera_cntx.tvout_prev_owner);
                }
            }
        }   /* tvout is enable or not */
    }
#endif /* __MMI_TVOUT__ */ 

#if (MDI_CAMERA_MT6228_SERIES)
    /* store preview info for MT6228 burst shot */
    g_mdi_camera_cntx.lcd_id = cam_preview_data.lcd_id;
    g_mdi_camera_cntx.lcm_start_x = cam_preview_data.lcd_start_x;
    g_mdi_camera_cntx.lcm_start_y = cam_preview_data.lcd_start_y;
    g_mdi_camera_cntx.lcm_end_x = cam_preview_data.lcd_end_x;
    g_mdi_camera_cntx.lcm_end_y = cam_preview_data.lcd_end_y;
    g_mdi_camera_cntx.update_layer = cam_preview_data.update_layer;
    g_mdi_camera_cntx.hw_update_layer = cam_preview_data.hw_update_layer;
    g_mdi_camera_cntx.frame_buf_size = cam_preview_data.image_buffer_size;
    g_mdi_camera_cntx.frame_buf_ptr = cam_preview_data.image_buffer_p;
    g_mdi_camera_cntx.roi_offset_x = cam_preview_data.roi_offset_x;
    g_mdi_camera_cntx.roi_offset_y = cam_preview_data.roi_offset_y;
    g_mdi_camera_cntx.tv_output_offset_x = cam_preview_data.tv_output_offset_x;
    g_mdi_camera_cntx.tv_output_offset_y = cam_preview_data.tv_output_offset_y;
#endif 

    mdi_camera_p->is_preview_stopped = FALSE;

#ifdef __MTK_TARGET__
    ret = media_cam_preview(stack_int_get_active_module_id(), &cam_preview_data);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_CAMERA_ERR_HW_NOT_READY;
    }
    else
    {
        mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        return MDI_RES_CAMERA_SUCCEED;
    }
#else /* __MTK_TARGET__ */ 
    ret = MED_RES_OK;
    return ret;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_preview_stop
 * DESCRIPTION
 *  shutdown the camer module
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_preview_stop(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->is_preview_stopped == FALSE)
    {
        media_cam_stop(stack_int_get_active_module_id());
    }

#ifdef __MDI_CAMERA_XENON_FLASH_SUPPORT__
    mdi_xenon_flash_status_callback = NULL;
#endif

#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    /* already powered off */
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        //mdi_camera_p->state = CAMERA_STATE_IDLE; //hongzhe.liu add
        return MDI_RES_CAMERA_SUCCEED;
    }

    mdi_camera_p->state = CAMERA_STATE_IDLE;
    mdi_camera_p->is_preview_stopped = TRUE;

    return MDI_RES_CAMERA_SUCCEED;

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_file
 * DESCRIPTION
 *  capture jpeg
 * PARAMETERS
 *  file_name               [?]         
 *  continue_capture        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_file(S8 *file_name, U8 continue_capture)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }
#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
    capture_data.memory_output = FALSE;
#endif
    capture_data.image_width = camera_setting_p->image_width;
    capture_data.image_height = camera_setting_p->image_height;

    capture_data.media_mode = MED_MODE_FILE;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_ISP;   /* ISP */
    capture_data.data = (void*)file_name;
    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.snapshot_number = 1;
    capture_data.gray_mode = 0;
    capture_data.continue_capture = continue_capture;

#if (MDI_CAMERA_MT6228_SERIES)
    capture_data.thumbnail_mode = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.tv_output = FALSE;
    capture_data.manual_wb = FALSE;
    capture_data.display = FALSE;
    capture_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    capture_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    capture_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    capture_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    capture_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    capture_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
#endif /* MDI_CAMERA_MT6228_SERIES */

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_in();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture jpeg */
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_out();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_DISC_FULL)
    {
        return MDI_RES_CAMERA_ERR_DISK_FULL;
    }
    else if (result == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
    }
    else if (result == MED_RES_NO_DISC)
    {
        return MDI_RES_CAMERA_ERR_NO_DISK;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_layer_to_file
 * DESCRIPTION
 *  capture from layers to a jpeg file
 * PARAMETERS
 *  capture_layer_flag      [IN]        Layer configuration
 *  file_name               [IN]        File_name
 *  offset_x                [IN]        Capture region's offset x
 *  offset_y                [IN]        Capture region's offset y
 *  width                   [IN]        Capture region's width
 *  height                  [IN]        Capture region's height
 *  continue_capture        [IN]        
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_layer_to_file(
            U32 capture_layer_flag,
            S8 *file_name,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height,
            U8 continue_capture)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    capture_data.image_width = width;
    capture_data.image_height = height;

    capture_data.media_mode = MED_MODE_FILE;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_MEM;   /* ISP */
    capture_data.data = (void*)file_name;
    capture_data.capture_layer = capture_layer_flag;
    capture_data.roi_offset_x = GDI_LAYER_OFFSET + offset_x;
    capture_data.roi_offset_y = GDI_LAYER_OFFSET + offset_y;
    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.snapshot_number = 1;
    capture_data.gray_mode = 0;
    capture_data.continue_capture = continue_capture;

#if (MDI_CAMERA_MT6228_SERIES)
    capture_data.manual_wb = FALSE;
    capture_data.thumbnail_mode = FALSE;
    capture_data.overlay_frame_mode = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.tv_output = FALSE;

    capture_data.update_layer = capture_layer_flag;
    capture_data.hw_update_layer = camera_preview_p->preview_layer_flag;
#endif /* MDI_CAMERA_MT6228_SERIES */

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_in();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture jpeg */
#ifdef __MTK_TARGET__
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);
#else /* __MTK_TARGET__ */ 
    /* avoid simulaotr compile warning */
    result = MED_RES_OK;
#endif /* __MTK_TARGET__ */ 

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_out();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_DISC_FULL)
    {
        return MDI_RES_CAMERA_ERR_DISK_FULL;
    }
    else if (result == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
    }
    else if (result == MED_RES_NO_DISC)
    {
        return MDI_RES_CAMERA_ERR_NO_DISK;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

}

#ifdef DRV_JPG_ENC_DIRECT_COUPLE_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory
 * DESCRIPTION
 *  capture jpeg
 * PARAMETERS
 *  buf_pp              [IN]        Pointer to a buffer pointer for jpeg file
 *  captured_size       [OUT]       Captured size
 *  pp_dc_buf           [IN/OUT]    direct couple buffer
 *  width               [IN]        width of decoded image
 *  height              [OUT]       height of decoded image
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory_direct_couple(U8 **buf_pp, U32 *captured_size, U32 dc_buf_addr, S32 buf_size, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    capture_data.memory_output = TRUE;
    capture_data.memory_output_width = width;
    capture_data.memory_output_height = height;
    capture_data.memory_output_buffer_address = dc_buf_addr;
    capture_data.memory_output_buffer_size = buf_size; 
    capture_data.image_width = camera_setting_p->image_width;
    capture_data.image_height = camera_setting_p->image_height;

    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_ISP;   /* ISP */
    capture_data.capture_buffer_p = (void **)buf_pp;
    capture_data.data = NULL;                   /* not used */
    capture_data.file_buffer_len = 0;           /* not used */
    capture_data.file_size_p = (kal_uint32*) captured_size;
    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.snapshot_number = 1;
    capture_data.gray_mode = 0;

#if (MDI_CAMERA_MT6228_SERIES)
    capture_data.thumbnail_mode = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.tv_output = FALSE;
    capture_data.manual_wb = FALSE;
    capture_data.display = FALSE;

    capture_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    capture_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    capture_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    capture_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    capture_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    capture_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
#endif /* MDI_CAMERA_MT6228_SERIES */

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_in();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture jpeg */
#ifdef __MTK_TARGET__
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);
#else /* __MTK_TARGET__ */ 
    /* avoid simulaotr compile warning */
    result = MED_RES_OK;
#endif /* __MTK_TARGET__ */ 

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_out();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_DISC_FULL)
    {
        return MDI_RES_CAMERA_ERR_DISK_FULL;
    }
    else if (result == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
    }
    else if (result == MED_RES_NO_DISC)
    {
        return MDI_RES_CAMERA_ERR_NO_DISK;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

}
#endif


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_to_memory
 * DESCRIPTION
 *  capture jpeg
 * PARAMETERS
 *  buf_pp              [IN]        Pointer to a buffer pointer for jpeg file
 *  captured_size       [OUT]       Captured size
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_to_memory(U8 **buf_pp, U32 *captured_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    capture_data.image_width = camera_setting_p->image_width;
    capture_data.image_height = camera_setting_p->image_height;

    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_ISP;   /* ISP */
    capture_data.capture_buffer_p = (void **)buf_pp;
    capture_data.data = NULL;                   /* not used */
    capture_data.file_buffer_len = 0;           /* not used */
    capture_data.file_size_p = (kal_uint32*) captured_size;
    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.snapshot_number = 1;
    capture_data.gray_mode = 0;

#if (MDI_CAMERA_MT6228_SERIES)
    capture_data.thumbnail_mode = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.tv_output = FALSE;
    capture_data.manual_wb = FALSE;
    capture_data.display = FALSE;

    capture_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    capture_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    capture_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    capture_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    capture_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    capture_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
#endif /* MDI_CAMERA_MT6228_SERIES */

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_in();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture jpeg */
#ifdef __MTK_TARGET__
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);
#else /* __MTK_TARGET__ */ 
    /* avoid simulaotr compile warning */
    result = MED_RES_OK;
#endif /* __MTK_TARGET__ */ 

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_out();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_DISC_FULL)
    {
        return MDI_RES_CAMERA_ERR_DISK_FULL;
    }
    else if (result == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
    }
    else if (result == MED_RES_NO_DISC)
    {
        return MDI_RES_CAMERA_ERR_NO_DISK;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_adjust_mwb
 * DESCRIPTION
 *  capture from layers to a memory, then cal mwb
 * PARAMETERS
 *  capture_layer_flag      [IN]        Layer configuration
 *  offset_x                [IN]        Capture region's offset x
 *  offset_y                [IN]        Capture region's offset y
 *  width                   [IN]        Capture region's width
 *  height                  [IN]        Capture region's height
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_adjust_mwb(U32 capture_layer_flag, S32 offset_x, S32 offset_y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->manual_wb = TRUE;
    ret = mdi_camera_capture_layer_to_memory(capture_layer_flag, NULL, NULL, offset_x, offset_y, width, height);
    camera_setting_p->manual_wb = FALSE;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_layer_to_memory
 * DESCRIPTION
 *  capture from layers to a memory, this is used for add frame
 * PARAMETERS
 *  capture_layer_flag      [IN]        Layer configuration
 *  buf_pp                  [IN]        Pointer to a buffer pointer for jpeg file
 *  captured_size           [OUT]       Captured size
 *  offset_x                [IN]        Capture region's offset x
 *  offset_y                [IN]        Capture region's offset y
 *  width                   [IN]        Capture region's width
 *  height                  [IN]        Capture region's height
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_layer_to_memory(
            U32 capture_layer_flag,
            U8 **buf_pp,
            U32 *captured_size,
            S32 offset_x,
            S32 offset_y,
            S32 width,
            S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    capture_data.image_width = width;
    capture_data.image_height = height;

    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_MEM;   /* ISP */
    capture_data.capture_buffer_p = (void **)buf_pp;
    capture_data.data = NULL;                   /* not used */
    capture_data.file_buffer_len = 0;           /* not used */
    capture_data.file_size_p = (kal_uint32*) captured_size;
    capture_data.capture_layer = capture_layer_flag;
    capture_data.roi_offset_x = GDI_LAYER_OFFSET + offset_x + camera_preview_p->preview_wnd_offset_x;
    capture_data.roi_offset_y = GDI_LAYER_OFFSET + offset_y + camera_preview_p->preview_wnd_offset_y;

    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.snapshot_number = 1;
    capture_data.gray_mode = 0;

#if (MDI_CAMERA_MT6228_SERIES)
    capture_data.manual_wb = camera_setting_p->manual_wb;
    capture_data.thumbnail_mode = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.tv_output = FALSE;
    capture_data.overlay_frame_mode = FALSE;

    capture_data.update_layer = capture_layer_flag;
    capture_data.hw_update_layer = camera_preview_p->preview_layer_flag;
#endif /* MDI_CAMERA_MT6228_SERIES */

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_in();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture jpeg */
#ifdef __MTK_TARGET__
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);
#else /* __MTK_TARGET__ */ 
    /* avoid simulaotr compile warning */
    result = MED_RES_OK;
#endif /* __MTK_TARGET__ */ 

#ifdef __MMI_TVOUT__
    /* temp solution for 200M pixtel catpure */
    /* the bandwidth is no enoguth for 200M capture with TV-out enable */
    if (g_mdi_camera_cntx.is_tvout && mdi_tvout_is_enable())
    {
        mdi_tvout_sleep_out();
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_NOT_ENOUGH_SPACE)
    {
        return MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_burst_capture_to_memory
 * DESCRIPTION
 *  burst shot capture
 * PARAMETERS
 *  capture_count       [IN]        Capture counter
 *  jpgs_ptr            [?]         
 *  jpg_ptr(?)          [OUT]       Captured jpeg info
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_burst_capture_to_memory(U32 capture_count, mdi_camera_jpegs_struct *jpgs_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    capture_data.image_width = camera_setting_p->image_width;
    capture_data.image_height = camera_setting_p->image_height;
    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_ISP;   /* ISP */

    capture_data.data = NULL;               /* not used */
    capture_data.file_buffer_len = 0;       /* not used */
    capture_data.file_size_p = NULL;        /* not used */
    capture_data.capture_buffer_p = NULL;   /* not used */

    capture_data.snapshot_number = capture_count;
    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.gray_mode = 0;
#ifdef __MTK_TARGET__
    capture_data.jpegs_p = (media_jpegs_struct*) jpgs_ptr;
#endif 

#if (MDI_CAMERA_MT6228_SERIES)
    capture_data.thumbnail_mode = FALSE;
    capture_data.manual_wb = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.tv_output = FALSE;

    capture_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    capture_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    capture_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    capture_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    capture_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    capture_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;
#endif /* MDI_CAMERA_MT6228_SERIES */

    /* capture jpeg */
#ifdef __MTK_TARGET__
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);
#else /* __MTK_TARGET__ */ 
    /* avoid simulaotr compile warning */
    result = MED_RES_OK;
#endif /* __MTK_TARGET__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_NOT_ENOUGH_SPACE)
    {
        return MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_non_block_burst_capture_to_memory
 * DESCRIPTION
 *  non block burst shot capture
 * PARAMETERS
 *  capture_count               [IN]        Capture counter
 *  jpgs_ptr                    [?]         
 *  capture_result_callback     [IN]        Capture result callback
 *  jpg_ptr(?)                  [OUT]       Captured jpeg info
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_non_block_burst_capture_to_memory(
            U32 capture_count,
            mdi_camera_jpegs_struct *jpgs_ptr,
            void (*capture_result_callback) (MDI_RESULT, U16))
{
#if (MDI_CAMERA_MT6228_SERIES)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_req_struct capture_data;
    S32 result;
#ifdef __MMI_TVOUT__
    MDI_RESULT ret;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state != CAMERA_STATE_PREVIEWING)
    {
        ASSERT(0);
    }

    ASSERT(capture_result_callback != NULL);

    g_mdi_camera_cntx.burst_cap_count = capture_count;

    mdi_camera_non_block_burst_shot_result_callback = capture_result_callback;
    SetProtocolEventHandler(mdi_camera_non_block_burst_capture_result_hdlr, MSG_ID_MEDIA_CAM_CAPTURE_EVENT_IND);

    capture_data.image_width = camera_setting_p->image_width;
    capture_data.image_height = camera_setting_p->image_height;
    capture_data.media_mode = MED_MODE_BUFFER;
    capture_data.image_quality = (U8) camera_setting_p->image_qty;
    capture_data.source_device = CAM_SRC_ISP;   /* ISP */

    capture_data.data = NULL;               /* not used */
    capture_data.file_buffer_len = 0;       /* not used */
    capture_data.file_size_p = NULL;        /* not used */
    capture_data.capture_buffer_p = NULL;   /* not used */

    capture_data.snapshot_number = capture_count;
    capture_data.flash_mode = (kal_uint16) camera_setting_p->flash;
    capture_data.gray_mode = 0;
    capture_data.continue_capture = TRUE;
#ifdef __MTK_TARGET__
    capture_data.jpegs_p = (media_jpegs_struct*) jpgs_ptr;
#endif 

    capture_data.thumbnail_mode = FALSE;
    #ifdef __MTK_TARGET__
    capture_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    capture_data.image_pitch_mode = FALSE;
    capture_data.manual_wb = FALSE;

    capture_data.display = TRUE;    /* diplay to LCM */
    capture_data.lcd_id = g_mdi_camera_cntx.lcd_id;
    capture_data.lcm_start_x = g_mdi_camera_cntx.lcm_start_x;
    capture_data.lcm_start_y = g_mdi_camera_cntx.lcm_start_y;
    capture_data.lcm_end_x = g_mdi_camera_cntx.lcm_end_x;
    capture_data.lcm_end_y = g_mdi_camera_cntx.lcm_end_y;
    capture_data.update_layer = g_mdi_camera_cntx.update_layer;
    capture_data.hw_update_layer = g_mdi_camera_cntx.hw_update_layer;
    capture_data.frame_buffer_address = (kal_uint32) g_mdi_camera_cntx.frame_buf_ptr;
    capture_data.frame_buffer_size = g_mdi_camera_cntx.frame_buf_size;
    capture_data.roi_offset_x = g_mdi_camera_cntx.roi_offset_x;
    capture_data.roi_offset_y = g_mdi_camera_cntx.roi_offset_y;

    capture_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    capture_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    capture_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    capture_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    capture_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    capture_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;

    capture_data.tv_output = FALSE;

    /* TV out */
#ifdef __MMI_TVOUT__

    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            /* set tvout owner to Camera */
            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_CAMERA,
                    NULL,                                   /* mode_ptr */
                    (PU16) & capture_data.tv_output_width,  /* buf_width_ptr */
                    (PU16) & capture_data.tv_output_height, /* buf_height_ptr */
                    (PU32) & capture_data.tv_output_buffer_size,       /* buf size */
                    (PU8*) & capture_data.tv_output_buffer1_address,  /* buf1 pp */
                    (PU8*) & capture_data.tv_output_buffer2_address,  /* buf2 pp */
                    NULL,                                   /* rotate_buf_1_pp */
                    NULL);                                  /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                capture_data.tv_output = TRUE;
                capture_data.tv_output_offset_x = g_mdi_camera_cntx.tv_output_offset_x;
                capture_data.tv_output_offset_y = g_mdi_camera_cntx.tv_output_offset_y;
            }

        }   /* tvout is enable or not */
    }
#endif /* __MMI_TVOUT__ */ 

    /* capture jpeg */
#ifdef __MTK_TARGET__
    result = media_cam_capture(stack_int_get_active_module_id(), &capture_data);
#else /* __MTK_TARGET__ */ 
    /* avoid simulaotr compile warning */
    result = MED_RES_OK;
#endif /* __MTK_TARGET__ */ 

    /* capture will also stop preview */
    mdi_camera_p->is_preview_stopped = TRUE;

    /* after captured. back to idle state */
    mdi_camera_p->state = CAMERA_STATE_IDLE;

    if (result == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (result == MED_RES_NOT_ENOUGH_SPACE)
    {
        return MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }
#else /* MDI_CAMERA_MT6228_SERIES */ 
    /* only availabe on MT6228 */
    ASSERT(0);
    return MDI_RES_CAMERA_ERR_FAILED;
#endif /* MDI_CAMERA_MT6228_SERIES */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_non_block_burst_capture
 * DESCRIPTION
 *  stop non blocking burst capture
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_stop_non_block_burst_capture(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MDI_CAMERA_MT6228_SERIES)
    media_cam_stop(stack_int_get_active_module_id());

    /* capture will also stop preview TV-Out */
#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

#endif /* MDI_CAMERA_MT6228_SERIES */ 
#endif /* __MTK_TARGET__ */ 

    return MDI_RES_CAMERA_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_non_block_burst_capture_result_hdlr
 * DESCRIPTION
 *  burst capture result handler
 * PARAMETERS
 *  msg_ptr     [?]     
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
#if (MDI_CAMERA_MT6228_SERIES)
static void mdi_camera_non_block_burst_capture_result_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_capture_event_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_cam_capture_event_ind_struct*) msg_ptr;

    /* note:capture count start from 1 */

    if ((ind_p->result != MED_RES_OK) ||
        ((ind_p->result == MED_RES_OK) && ((ind_p->count) == g_mdi_camera_cntx.burst_cap_count)))
    {
        /* if failed, or if it is last capture - will enter here */

        g_mdi_camera_cntx.burst_cap_count = 0;

        /* capture will also stop preview TV-Out */
    #ifdef __MMI_TVOUT__
        /* restore owner to GDI */
        if (g_mdi_camera_cntx.is_tvout)
        {
            if (mdi_tvout_is_enable())
            {
                if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
                {
                    mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
                }
            }
        }
    #endif /* __MMI_TVOUT__ */ 

    }

    /* successful save file */
    if (ind_p->result == MED_RES_OK)
    {
        mdi_camera_non_block_burst_shot_result_callback(MDI_RES_CAMERA_SUCCEED, ind_p->count);
    }
    else if (ind_p->result == MED_RES_BUFFER_INSUFFICIENT)
    {
        mdi_camera_non_block_burst_shot_result_callback(MDI_RES_CAMERA_ERR_MEMORY_NOT_ENOUGH, ind_p->count);
    }
    else
    {
        mdi_camera_non_block_burst_shot_result_callback(MDI_RES_CAMERA_ERR_FAILED, ind_p->count);
    }

}
#endif /* MDI_CAMERA_MT6228_SERIES */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_is_ready_to_capture
 * DESCRIPTION
 *  check hw module is ready to capture (some module requires some time to power on and init)
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_camera_is_ready_to_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
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
 *  mdi_camera_update_para_banding
 * DESCRIPTION
 *  update banding value
 * PARAMETERS
 *  cam_para        [IN]        banding value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_banding(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->flash = cam_para;
    
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_BANDING, cam_para);
#endif 
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ev
 * DESCRIPTION
 *  update ev setting value
 * PARAMETERS
 *  cam_para        [IN]        Ev setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_ev(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_EV_COUNT);

    camera_setting_p->ev = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_EXPOSURE, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ev_adjust
 * DESCRIPTION
 *  update ev setting value - for factory mode to adjust ev balance
 * PARAMETERS
 *  cam_para        [IN]        Ev adjust value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_ev_adjust(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_EV_VALUE, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_zoom
 * DESCRIPTION
 *  update zoom setting value
 * PARAMETERS
 *  cam_para        [IN]        Zoom setting value (10 measn 1x, 40 means 4x, etc)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_zoom(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->zoom = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_ZOOM_FACTOR, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_effect
 * DESCRIPTION
 *  update effect setting value
 * PARAMETERS
 *  cam_para        [IN]        Effect setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_effect(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_EFFECT_COUNT);

    camera_setting_p->effect = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_EFFECT, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_wb
 * DESCRIPTION
 *  update wb setting value
 * PARAMETERS
 *  cam_para        [IN]        Wb setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_wb(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_WB_COUNT);

    camera_setting_p->wb = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_WB, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}



/*****************************************************************************
 * FUNCTION
 *  mdi_camera_restore_mwb
 * DESCRIPTION
 *  restore original mwb value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_restore_mwb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_mwb_operation(stack_int_get_active_module_id(), MDI_CAMERA_MWB_RESTORE);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_backup_mwb
 * DESCRIPTION
 *  backup mwb value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_backup_mwb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_mwb_operation(stack_int_get_active_module_id(), MDI_CAMERA_MWB_BACKUP);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_set_overlay_palette
 * DESCRIPTION
 *  set overlay palette
 * PARAMETERS
 *  palette_size            [IN]        
 *  palette_addr_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_set_overlay_palette(U8 palette_size, U32 *palette_addr_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_overlay_palette(stack_int_get_active_module_id(), (kal_uint8) palette_size, (kal_uint32*) palette_addr_ptr);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_brightness
 * DESCRIPTION
 *  update brightness setting value
 * PARAMETERS
 *  cam_para        [IN]        Brightness setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_brightness(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->brightness = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_BRIGHTNESS, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_saturation
 * DESCRIPTION
 *  update saturation setting value
 * PARAMETERS
 *  cam_para        [IN]        Saturation setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_saturation(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->saturation = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_SATURATION, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_contrast
 * DESCRIPTION
 *  update contrast setting value
 * PARAMETERS
 *  cam_para        [IN]        Contrast setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_contrast(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->contrast = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_CONTRAST, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_hue
 * DESCRIPTION
 *  update hue setting value
 * PARAMETERS
 *  cam_para        [IN]        Hue setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_hue(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->hue = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_HUE, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_night
 * DESCRIPTION
 *  update night mode setting value
 * PARAMETERS
 *  cam_para        [IN]        Night mode setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_night(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->night = cam_para;

#ifdef __MTK_TARGET__
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_NIGHT_MODE, cam_para);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_image_qty
 * DESCRIPTION
 *  update image quality setting value
 * PARAMETERS
 *  cam_para        [IN]        Image qty setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_image_qty(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cam_para < MDI_CAMERA_JPG_QTY_COUNT);
    camera_setting_p->image_qty = cam_para;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_image_size
 * DESCRIPTION
 *  update image size setting value
 * PARAMETERS
 *  image_width         [IN]        Captured iamge width
 *  image_height        [IN]        Captured iamge height
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_image_size(U16 image_width, U16 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->image_width = image_width;
    camera_setting_p->image_height = image_height;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_flash
 * DESCRIPTION
 *  update flash setting value
 * PARAMETERS
 *  cam_para        [IN]        Flash setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_flash(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->flash = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_FLASH, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_iso
 * DESCRIPTION
 *  update iso setting value
 * PARAMETERS
 *  cam_para        [IN]        Iso setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_iso(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->iso = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_ISO, cam_para);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_ae_meter
 * DESCRIPTION
 *  update ae meter setting value
 * PARAMETERS
 *  cam_para        [IN]        Ae meter setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_ae_meter(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->ae_meter = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_AE_METERING, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_dsc_mode
 * DESCRIPTION
 *  update shot(DSC) mode value
 * PARAMETERS
 *  cam_para        [IN]        Shot mode setting value
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_dsc_mode(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->dsc_mode = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_DSC_MODE, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_shutter_pri
 * DESCRIPTION
 *  update shutter priority value
 * PARAMETERS
 *  cam_para        [IN]        Shutter pri
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_shutter_pri(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->shutter_pri = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_SHUTTER_PRIORITY, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_aperture_pri
 * DESCRIPTION
 *  update apreture priority value
 * PARAMETERS
 *  cam_para        [IN]        Aperture pri
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_aperture_pri(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->aperture_pri = cam_para;

#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_APERTURE_PRIORITY, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_key
 * DESCRIPTION
 *  update af key value
 * PARAMETERS
 *  cam_para        [IN]        Af key
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_key(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_AF_KEY, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_mode
 * DESCRIPTION
 *  update af mode value
 * PARAMETERS
 *  cam_para        [IN]        Af mode
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_mode(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->af_mode = cam_para;
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_AF_MODE, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_af_metering
 * DESCRIPTION
 *  update af metering value
 * PARAMETERS
 *  cam_para        [IN]        Af metering
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_af_metering(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_setting_p->af_metering_mode = cam_para;
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_AF_METERING, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_update_para_manual_focus_dir
 * DESCRIPTION
 *  update manual focus direction value
 * PARAMETERS
 *  cam_para        [IN]        Manual focus dir
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_update_para_manual_focus_dir(U16 cam_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_MANUAL_FOCUS_DIR, cam_para);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_autofocus_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_stop_autofocus_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_AF_KEY, CAM_AF_RELEASE);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_af_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_af_finish_ind(void *inMsg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_event_ind_struct *msg_p = (media_cam_event_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cameraCurrentHandler)
    {
        cameraCurrentHandler((mdi_result) msg_p->cause);
    }
    else
    {
        ASSERT(0);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_mf_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_stop_mf_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_MANUAL_FOCUS_DIR, CAM_FOCUS_STOP);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_mf_backward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_mf_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_MANUAL_FOCUS_DIR, CAM_FOCUS_BACKWARD);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_mf_forward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_mf_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_MANUAL_FOCUS_DIR, CAM_FOCUS_FORWARD);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_mf_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_forward      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_start_mf_continue(BOOL is_forward)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (is_forward)
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_MANUAL_FOCUS_DIR, CAM_FOCUS_FORWARD_CONTINUE);
    }
    else
    {
        media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_MANUAL_FOCUS_DIR, CAM_FOCUS_BACKWARD_CONTINUE);
    }
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_focus_steps
 * DESCRIPTION
 *  get current zoom factor
 * PARAMETERS
 *  total_steps         [?]     
 *  current_steps       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mdi_camera_get_focus_steps(U32 *total_steps, U32 *current_steps)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flag = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_get_focus_steps(stack_int_get_active_module_id(), total_steps, current_steps, &flag);
    return flag;
#else /* __MTK_TARGET__ */ 
    return FALSE;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_autofocus_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_start_autofocus_process(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_set_param(stack_int_get_active_module_id(), CAM_PARAM_AF_KEY, CAM_AF_ONE_TIME);
#endif 
    cameraCurrentHandler = handler;
    SetProtocolEventHandler(mdi_camera_af_finish_ind, MSG_ID_MEDIA_CAM_AF_PROCESS_DONE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_encode_layer_to_jpeg
 * DESCRIPTION
 *  encode a layer and save as file
 * PARAMETERS
 *  layer_handle        [IN]        Layer handle
 *  file_name           [IN]        Filename for jpeg
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name)
{
#if defined(JPG_ENCODE) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    img_encode_struct encode_data;
    S32 image_width;
    S32 image_height;
    PU8 image_ptr;
    U32 file_size;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&image_width, &image_height);
    gdi_layer_get_buffer_ptr(&image_ptr);
    gdi_layer_pop_and_restore_active();

    encode_data.image_width = image_width;
    encode_data.image_height = image_height;

    encode_data.image_quality = CAM_JPG_QTY_HIGH;
    encode_data.image_buffer_p = (void*)image_ptr;
    encode_data.image_buffer_size = (image_width * image_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;

    encode_data.target_width = image_width;
    encode_data.target_height = image_height;
    encode_data.media_mode = MED_MODE_FILE;
    encode_data.media_type = MED_TYPE_JPG;

    encode_data.data = (void*)file_name;
    encode_data.file_size_p = (kal_uint32*) & file_size;
    encode_data.blocking = (kal_bool) TRUE;         /* blocking */
    encode_data.seq_num = (kal_uint16) 0;           /* not used */
    encode_data.file_buffer_len = (kal_uint32) 0;   /* not used */
    encode_data.gray_mode = 0;

#if (MDI_CAMERA_MT6228_SERIES)
    encode_data.jpeg_yuv_mode = JPEG_FORMAT_YUV420;
    encode_data.thumbnail_mode = FALSE;
    encode_data.overlay_frame_mode = FALSE;
#endif /* MDI_CAMERA_MT6228_SERIES */ 

    ret = media_img_encode(stack_int_get_active_module_id(), &encode_data);

    if (ret == MED_RES_OK)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        return MDI_RES_CAMERA_ERR_DISK_FULL;
    }
    else if (ret == MED_RES_WRITE_PROTECTION)
    {
        return MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
    }
    else if (ret == MED_RES_NO_DISC)
    {
        return MDI_RES_CAMERA_ERR_NO_DISK;
    }
    else if (ret == MED_RES_ROOT_DIR_FULL)
    {
        return MDI_RES_CAMERA_ERR_ROOT_DIR_FULL;
    }
    else
    {
        return MDI_RES_CAMERA_ERR_FAILED;
    }

#else /* defined(JPG_ENCODE) && defined(__MTK_TARGET__) */ 
    return MDI_RES_CAMERA_SUCCEED;
#endif /* defined(JPG_ENCODE) && defined(__MTK_TARGET__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_add_post_effect
 * DESCRIPTION
 *  preview fail handler (driver error)
 * PARAMETERS
 *  layer_handle        [IN]        
 *  effect_id           [IN]        
 *  msgPtr(?)           [IN]        Ready msg
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_add_post_effect(gdi_handle layer_handle, U16 effect_id)
{
#if defined(ISP_SUPPORT) && defined(__MTK_TARGET__) && (MDI_CAMERA_MT6225_SERIES == 0)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    PU8 buf_ptr;
    S32 buf_size;
    PU8 work_buf_ptr_1;
    PU8 work_buf_ptr_2;

    IMAGE_EFFECT_DEC_STRUCT effect_data;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();

    buf_size = (layer_width * layer_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;

    /* allocate from media task */
    media_get_ext_buffer(
        stack_int_get_active_module_id(),
        (void **)&work_buf_ptr_1,
        ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3));

    media_get_ext_buffer(
        stack_int_get_active_module_id(),
        (void **)&work_buf_ptr_2,
        ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3));

    /* NOTE: only some effect needs two buffer, like "water paint", etc */

    /* TODO: fix when support 888 format */
    effect_data.data_type = IBR1_TYPE_RGB565;
    effect_data.data_order = IBR1_ORDER_BGR888; /* not used - just give it a value */
#if (MDI_CAMERA_MT6228_SERIES)
    effect_data.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;
#endif 
    effect_data.source_buffer_address = (kal_uint32) buf_ptr;
    effect_data.dest1_buffer_address = (kal_uint32) work_buf_ptr_1;
    effect_data.dest2_buffer_address = (kal_uint32) work_buf_ptr_2;
    effect_data.image_width = layer_width;
    effect_data.image_height = layer_height;
    effect_data.effect_index = effect_id;
    effect_data.adj_level = 0;                  /* not used */
    effect_data.image_effect_dec_cb = NULL;     /* not used */

    image_effect_dec_process(&effect_data);

    /* copy result to soruce layer */
    memcpy(buf_ptr, work_buf_ptr_1, buf_size);

    /* free buffer */
    media_free_ext_buffer(stack_int_get_active_module_id(), (void **)&work_buf_ptr_1);
    media_free_ext_buffer(stack_int_get_active_module_id(), (void **)&work_buf_ptr_2);

#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_add_post_adjustment
 * DESCRIPTION
 *  preview fail handler (driver error)
 * PARAMETERS
 *  layer_handle        [IN]        
 *  adjustment_id       [IN]        
 *  value               [IN]        
 *  msgPtr(?)           [IN]        Ready msg
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_add_post_adjustment(gdi_handle layer_handle, U16 adjustment_id, S32 value)
{
#if defined(ISP_SUPPORT) && defined(__MTK_TARGET__)&& (MDI_CAMERA_MT6225_SERIES == 0)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    PU8 buf_ptr;
    S32 buf_size;
    PU8 work_buf_ptr_1;
    PU8 work_buf_ptr_2;

    IMAGE_EFFECT_DEC_STRUCT effect_data;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();

    buf_size = (layer_width * layer_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;

    /* allocate from media task */
    media_get_ext_buffer(
        stack_int_get_active_module_id(),
        (void **)&work_buf_ptr_1,
        ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3));

    media_get_ext_buffer(
        stack_int_get_active_module_id(),
        (void **)&work_buf_ptr_2,
        ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3));

    /* TEMP: HW BUGS on MT6219 - source cant be internal SRAM */
    memcpy(work_buf_ptr_2, buf_ptr, buf_size);
    memset(work_buf_ptr_1, 0, buf_size);

    /* TODO: fix when support 888 format */
    effect_data.data_type = IBR1_TYPE_RGB565;
    effect_data.data_order = IBR1_ORDER_BGR888;             /* not used - just give it a value */
#if (MDI_CAMERA_MT6228_SERIES)
    effect_data.dest_color_mode = IMGDMA_IBW_OUTPUT_RGB565;
#endif 
    effect_data.source_buffer_address = (kal_uint32) work_buf_ptr_2;
    effect_data.dest1_buffer_address = (kal_uint32) work_buf_ptr_1;
    effect_data.dest2_buffer_address = (kal_uint32) NULL;   /* not used */
    effect_data.image_width = layer_width;
    effect_data.image_height = layer_height;
    effect_data.effect_index = adjustment_id;
    effect_data.adj_level = value;
    effect_data.image_effect_dec_cb = NULL;                 /* not used */

    image_adj_dec_process(&effect_data);

    /* copy result to soruce layer */
    memcpy(buf_ptr, work_buf_ptr_1, buf_size);

    /* free buffer */
    media_free_ext_buffer(stack_int_get_active_module_id(), (void **)&work_buf_ptr_1);
    media_free_ext_buffer(stack_int_get_active_module_id(), (void **)&work_buf_ptr_2);

#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_start_fast_zoom
 * DESCRIPTION
 *  start fast zoom
 * PARAMETERS
 *  zoom_in         [IN]        
 *  zoom_limit      [IN]        
 *  zoom_step       [IN]        
 *  zoom_speed      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_start_fast_zoom(BOOL zoom_in, U8 zoom_limit, U8 zoom_step, U8 zoom_speed)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_start_fast_zoom(stack_int_get_active_module_id(), zoom_in, zoom_limit, zoom_step, zoom_speed);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_fast_zoom
 * DESCRIPTION
 *  stop fast zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_stop_fast_zoom(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_PREVIEWING)
    media_cam_stop_fast_zoom(stack_int_get_active_module_id());
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_fast_zoom_factor
 * DESCRIPTION
 *  get current zoom factor
 * PARAMETERS
 *  factor      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_get_fast_zoom_factor(U8 *factor)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_cam_get_fast_zoom_factor(stack_int_get_active_module_id(), factor);
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_get_max_zoom_factor
 * DESCRIPTION
 *  get max zoom factor
 * PARAMETERS
 *  image_width         [IN]        
 *  image_height        [IN]        
 *  width(?)            [IN]        Image width
 *  height(?)           [IN]        Image height
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mdi_camera_get_max_zoom_factor(S32 image_width, S32 image_height)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        return 10;
    }
    else
    {
        return (U16) media_cam_get_max_zoom_factor((U16) image_width, (U16) image_height);
    }
#else /* __MTK_TARGET__ */ 
    return 10;  /* 1x zooming */
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_load_default_setting
 * DESCRIPTION
 *  load camera default setting
 * PARAMETERS
 *  camera_setting_data                 [?]         
 *  mdi_camera_setting_struct(?)        [IN]        Camera setting structure
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_load_default_setting(mdi_camera_setting_struct *camera_setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* preview parametes */
    camera_setting_data->zoom = 10; /* 1x */
    camera_setting_data->wb = MDI_CAMERA_WB_AUTO;
    camera_setting_data->manual_wb = FALSE;
    camera_setting_data->ev = MDI_CAMERA_EV_0;
    camera_setting_data->banding = MDI_CAMERA_BANDING_50HZ;
    camera_setting_data->flash = MDI_CAMERA_FLASH_AUTO;
    camera_setting_data->night = 0;

    camera_setting_data->iso = MDI_CAMERA_ISO_AUTO;
    camera_setting_data->ae_meter = MDI_CAMERA_AE_METER_AUTO;
    camera_setting_data->dsc_mode = MDI_CAMERA_DSC_MODE_AUTO;
    camera_setting_data->af_mode = MDI_CAMERA_AUTOFOCUS_MODE_AUTO;
    camera_setting_data->af_metering_mode = MDI_CAMERA_AUTOFOCUS_1_ZONE;
    camera_setting_data->shutter_pri = 0;
    camera_setting_data->aperture_pri = 0;

    /* default effect */
    camera_setting_data->effect = MDI_CAMERA_EFFECT_NOMRAL;
    camera_setting_data->brightness = 128;
    camera_setting_data->saturation = 128;
    camera_setting_data->contrast = 128;
    camera_setting_data->hue = 0;

    camera_setting_data->overlay_frame_mode = FALSE;
    camera_setting_data->overlay_frame_depth = 0;
    camera_setting_data->overlay_frame_width = 0;
    camera_setting_data->overlay_frame_height = 0;
    camera_setting_data->overlay_frame_source_key = 0;
    camera_setting_data->overlay_frame_buffer_address = 0;

    /* capture parameters */
    camera_setting_data->image_qty = MDI_CAMERA_JPG_QTY_NORMAL;
    camera_setting_data->continue_capture = FALSE;

#ifdef AF_SUPPORT
    camera_setting_data->af_zone0_x = 0;
    camera_setting_data->af_zone0_y = 0;
    camera_setting_data->af_zone1_x = 0;
    camera_setting_data->af_zone1_y = 0;
    camera_setting_data->af_zone2_x = 0;
    camera_setting_data->af_zone2_y = 0;
    camera_setting_data->af_zone3_x = 0;
    camera_setting_data->af_zone3_y = 0;
    camera_setting_data->af_zone4_x = 0;
    camera_setting_data->af_zone4_y = 0;
#endif /* AF_SUPPORT */ 

}

#ifdef BARCODE_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mdi_camera_capture_and_decode_barcode
 * DESCRIPTION
 *  This function will let Camera enter preview and capture state.
 *  DRV will preview and capture at the same time,
 *  and try to decode barcode info from the raw image data.
 * PARAMETERS
 *  text_buf                        [IN]        
 *  buf_length                      [IN]        
 *  handler                         [IN]        
 *  barcode_decode_callback(?)      [OUT]       Callback function
 *  buf(?)                          [OUT]       Decoded information
 * RETURNS
 *  void
 *****************************************************************************/
MDI_RESULT mdi_camera_capture_and_decode_barcode(PS8 text_buf, S32 buf_length, mdi_barcode_callback handler, U8 barcode_type)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_cam_barcode_capture_struct capture_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    capture_req.text_buf = text_buf;
    capture_req.buf_length = buf_length;
    capture_req.barcode_type = barcode_type;

    media_cam_barcode_start_capture_end_decode(stack_int_get_active_module_id(), &capture_req);
    barcodeCurrentHandler = handler;
    SetProtocolEventHandler(mdi_camera_barcode_decode_finish_ind, MSG_ID_MEDIA_CAM_BARCODE_DECODE_DONE_IND);
    mdi_camera_p->state = CAMERA_STATE_BARCODE_CAPTURING;

#endif /* __MTK_TARGET__ */ 

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_barcode_decode_finish_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_barcode_decode_finish_ind(void *inMsg)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_barcode_event_ind_struct *msg_p = (media_cam_barcode_event_ind_struct *) inMsg;
    mdi_result return_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (barcodeCurrentHandler && mdi_camera_p->state != CAMERA_STATE_POWER_OFF)
    {
        /* after captured. back to idle state */
        mdi_camera_p->state = CAMERA_STATE_IDLE;
        mdi_camera_p->is_preview_stopped = TRUE;

        switch (msg_p->cause)
        {
            case MED_RES_BR_ERROR_BARCODE_TYPE:
                return_code = MDI_RES_BARCODEREADER_ERROR_CODE_TYPE;
                break;
            case MED_RES_BR_DECODE_TIMEOUT:
                return_code = MDI_RES_BARCODEREADER_DECODE_TIMEOUT;
                break;
            case MED_RES_BR_IMAGE_ERROR:
                return_code = MDI_RES_BARCODEREADER_IMAGE_ERROR;
                break;                
            case MED_RES_BR_MODULE_ERROR:
                return_code = MDI_RES_BARCODEREADER_MODULE_ERROR;
                break;                
            case MED_RES_BR_OUT_OF_MEMORY:
                return_code = MDI_RES_BARCODEREADER_OUT_OF_MEMORY;
                break;                
            case MED_RES_BR_OVER_VERSION:
                return_code = MDI_RES_BARCODEREADER_OVER_VERSION;
                break;                
            case MED_RES_OK:
            default:
                return_code = MDI_RES_BARCODEREADER_DECODE_OK;
                break;
        }
        barcodeCurrentHandler(return_code,msg_p->encoding,msg_p->nsymbol,msg_p->symbolid,msg_p->paritydata,msg_p->barcode_type);
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_stop_capture_and_decode_barcode
 * DESCRIPTION
 *  This function will make Camera leave preview and capture state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_stop_capture_and_decode_barcode(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->state == CAMERA_STATE_BARCODE_CAPTURING)
    {
        media_cam_barcode_stop_capture_and_decode(stack_int_get_active_module_id());
        mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
    }
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_barcodereader_preview_start
 * DESCRIPTION
 *  start preview
 * PARAMETERS
 *  preview_layer_handle        [IN]        Layer for preview
 *  preview_wnd_offset_x        [IN]        Window offset x
 *  preview_wnd_offset_y        [IN]        Window offset y
 *  preview_wnd_width           [IN]        Window width
 *  preview_wnd_height          [IN]        Window height
 *  blt_layer_flag              [IN]        Blt out layer flag
 *  preview_layer_flag          [IN]        Preview layer flag
 *  src_key_color               [IN]        
 *  is_tvout                    [IN]        Is display preview on tvout
 *  setting_p                   [IN]        Setting data
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_barcodereader_preview_start(
            gdi_handle preview_layer_handle,
            S32 preview_wnd_offset_x,
            S32 preview_wnd_offset_y,
            U16 preview_wnd_width,
            /* preview window width */ U16 preview_wnd_height,
            /* preview window height */ U32 blt_layer_flag,
            U32 preview_layer_flag,
            gdi_color src_key_color,
            BOOL is_tvout,
            mdi_camera_setting_struct *setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg check */
    ASSERT(blt_layer_flag > 0);
    ASSERT(preview_layer_flag > 0);

    g_mdi_camera_cntx.is_tvout = is_tvout;

    /* set preview wnd parameters */
    camera_preview_p->preview_layer_handle = preview_layer_handle;
    camera_preview_p->preview_wnd_offset_x = preview_wnd_offset_x;
    camera_preview_p->preview_wnd_offset_y = preview_wnd_offset_y;
    camera_preview_p->preview_wnd_width = preview_wnd_width;
    camera_preview_p->preview_wnd_height = preview_wnd_height;

    camera_preview_p->blt_layer_flag = blt_layer_flag;
    camera_preview_p->preview_layer_flag = preview_layer_flag;

    /* 
     * this parametes only needs for MT6218 with backend, for MT6218,
     * we only support 16 bit color depth, so, U16 is enoguth 
     */
    camera_preview_p->src_key_color = (U16) src_key_color;

    /* init camera parameters */
    memcpy(camera_setting_p, setting_p, sizeof(mdi_camera_setting_struct));

    if (mdi_camera_p->state == CAMERA_STATE_IDLE)
    {
        ret = mdi_camera_barcodereader_preview_start_internal();

        if (ret >= 0)
        {
            /* preview successfully */
            mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        }

        return ret;
    }
    else
    {
        /* start preview at wrong state */
    #ifndef __MTK_TARGET__  /* MNT Simulator */

        /* on MNT, direct call internal function for debugging */
        mdi_camera_barcodereader_preview_start_internal();
        return MDI_RES_CAMERA_SUCCEED;

    #else /* __MTK_TARGET__ */ 
        /* Target */
        return MDI_RES_CAMERA_ERR_FAILED;
    #endif /* __MTK_TARGET__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_barcodereader_preview_start_internal
 * DESCRIPTION
 *  init MDI Camera
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
static MDI_RESULT mdi_camera_barcodereader_preview_start_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct cam_preview_data;

    U8 *buf_ptr;
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    MDI_RESULT ret;
    S32 lcd_width;
    S32 lcd_height;
    S32 lcd_offset_x;
    S32 lcd_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if preview on sublcd, set sublcd active, so we may get correct paramater from following functions */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_SUBLCD)
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    }

    /* get layer info */
    gdi_layer_push_and_set_active(camera_preview_p->preview_layer_handle);

    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_pop_and_restore_active();

    cam_preview_data.camera_offset_x = layer_offset_x;
    cam_preview_data.camera_offset_y = layer_offset_y;

    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_SUBLCD)
    {
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }

    /* preview on whihc lcm */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_MAINLCD)
    {
        cam_preview_data.lcd_id = MAIN_LCD;
        lcd_width = LCD_WIDTH;
        lcd_height = LCD_HEIGHT;
    }
    else
    {
        cam_preview_data.lcd_id = SUB_LCD;
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }

    cam_preview_data.preview_width = camera_setting_p->preview_width;
    cam_preview_data.preview_height = camera_setting_p->preview_height;

    if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270_MIRROR))
    {
        lcd_offset_x = GDI_LCD_WIDTH - layer_offset_y - layer_height;
        lcd_offset_y = layer_offset_x;
    }
    else if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90) ||
             (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90_MIRROR))
    {
        lcd_offset_x = layer_offset_y;
        lcd_offset_y = GDI_LCD_HEIGHT - layer_offset_x - layer_width;
    }
    else
    {
        lcd_offset_x = layer_offset_x;
        lcd_offset_y = layer_offset_y;
    }

    cam_preview_data.lcd_update = TRUE;
    
    /* lcd start x, start y are coordinate on LCM, is the region will be update by driver */
    cam_preview_data.lcd_start_x = lcd_offset_x;
    cam_preview_data.lcd_start_y = lcd_offset_y;

    if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270_MIRROR) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90_MIRROR))
    {
        /* rotate 90 or 270 for horizonal view */
        cam_preview_data.lcd_end_x = lcd_offset_x + layer_height - 1;
        cam_preview_data.lcd_end_y = lcd_offset_y + layer_width - 1;
        cam_preview_data.roi_offset_x = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_x;
        cam_preview_data.roi_offset_y = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_y;
    }
    else
    {
        cam_preview_data.lcd_end_x = lcd_offset_x + layer_width - 1;
        cam_preview_data.lcd_end_y = lcd_offset_y + layer_height - 1;

        cam_preview_data.roi_offset_x = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_x;
        cam_preview_data.roi_offset_y = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_y;
    }

    /* preview offset x, y are offset from lcd_start_x, lcd_start_y */
    cam_preview_data.preview_offset_x = 0;
    cam_preview_data.preview_offset_y = 0;

    cam_preview_data.image_buffer_p = (void*)buf_ptr;
    cam_preview_data.image_width = (kal_uint16) camera_setting_p->image_width;
    cam_preview_data.image_height = (kal_uint16) camera_setting_p->image_height;

    cam_preview_data.buffer_width = (kal_uint16) layer_width;
    cam_preview_data.buffer_height = (kal_uint16) layer_height;
    cam_preview_data.image_buffer_size =
        (kal_uint32) ((camera_setting_p->preview_width * camera_setting_p->preview_height *
                       GDI_LAYER.act_bit_per_pixel) >> 3);

    /* set settings parameters */
    cam_preview_data.effect = (kal_uint16) camera_setting_p->effect;
    cam_preview_data.WB = (kal_uint16) camera_setting_p->wb;
    cam_preview_data.exposure = (kal_uint16) camera_setting_p->ev;
    cam_preview_data.zoom_factor = (kal_uint16) camera_setting_p->zoom;
    cam_preview_data.banding_freq = (kal_uint8) camera_setting_p->banding;
    cam_preview_data.flash_mode = (kal_uint16) camera_setting_p->flash;

    cam_preview_data.brightness = (kal_uint16) camera_setting_p->brightness;
    cam_preview_data.contrast = (kal_uint16) camera_setting_p->contrast;
    cam_preview_data.saturation = (kal_uint16) camera_setting_p->saturation;
    cam_preview_data.hue = (kal_uint16) camera_setting_p->hue;
    cam_preview_data.night_mode = (kal_bool) camera_setting_p->night;
    cam_preview_data.snapshot_number = 1;

    cam_preview_data.continue_capture = (kal_uint8) camera_setting_p->continue_capture;

#if (MDI_CAMERA_MT6225_SERIES || MDI_CAMERA_MT6227_SERIES)
    cam_preview_data.ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data.dsc_mode = (kal_uint8) camera_setting_p->dsc_mode;
    cam_preview_data.af_metering_mode = (kal_uint8) camera_setting_p->af_metering_mode;
    cam_preview_data.af_mode = (kal_uint8) camera_setting_p->af_mode;
#elif (MDI_CAMERA_MT6228_SERIES)
    cam_preview_data.ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data.iso_setting = (kal_uint8) camera_setting_p->iso;
    cam_preview_data.dsc_mode = (kal_uint8) camera_setting_p->dsc_mode;
    cam_preview_data.tv_setting = (kal_uint16) camera_setting_p->shutter_pri;
    cam_preview_data.av_setting = (kal_uint8) camera_setting_p->aperture_pri;
    cam_preview_data.af_metering_mode = (kal_uint8) camera_setting_p->af_metering_mode;
    cam_preview_data.af_mode = (kal_uint8) camera_setting_p->af_mode;

    cam_preview_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    cam_preview_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    cam_preview_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    cam_preview_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    cam_preview_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    cam_preview_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;

    #ifdef __MTK_TARGET__
    cam_preview_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    cam_preview_data.image_pitch_mode = FALSE;
    cam_preview_data.tv_output = FALSE;
#endif 

    MDI_CAMERA_CHECK_FOCUS(0);
    MDI_CAMERA_CHECK_FOCUS(1);
    MDI_CAMERA_CHECK_FOCUS(2);
    MDI_CAMERA_CHECK_FOCUS(3);
    MDI_CAMERA_CHECK_FOCUS(4);

    /* rotate */
    cam_preview_data.rotate = camera_setting_p->preview_rotate;
    cam_preview_data.lcd_rotate = camera_setting_p->lcm_rotate;

    /* fixed para */
    cam_preview_data.gamma = 0;
    cam_preview_data.frame_rate = CAMERA_PERVIEW_FRAME_RATE;

    cam_preview_data.update_layer = camera_preview_p->blt_layer_flag;
    cam_preview_data.hw_update_layer = camera_preview_p->preview_layer_flag;
    cam_preview_data.src_key_color = camera_preview_p->src_key_color;   /* GDI_COLOR_TRANSPARENT */
    cam_preview_data.roi_background_color = GDI_COLOR_BLACK;

#if (MDI_CAMERA_MT6228_SERIES)
    cam_preview_data.tv_output = FALSE;
#endif 

    /* TV out */
#ifdef __MMI_TVOUT__

    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            /* set tvout owner to Camera */
            g_mdi_camera_cntx.tvout_prev_owner = mdi_tvout_get_owner();

            if (g_mdi_camera_cntx.tvout_prev_owner != MDI_TV_OWNER_CAMERA)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_CAMERA);
            }

            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_CAMERA,
                    (PU16) & cam_preview_data.tv_output_mode,     /* mode_ptr */
                    (PU16) & cam_preview_data.tv_output_width, /* buf_width_ptr */
                    (PU16) & cam_preview_data.tv_output_height,        /* buf_height_ptr */
                    (PU32) & cam_preview_data.tv_output_buffer_size,   /* buf size */
                    (PU8*) & cam_preview_data.tv_output_buffer1_address,      /* buf1 pp */
                    (PU8*) & cam_preview_data.tv_output_buffer2_address,      /* buf2 pp */
                    NULL,      /* rotate_buf_1_pp */
                    NULL);     /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                cam_preview_data.tv_output = TRUE;
                cam_preview_data.tv_output_offset_x = lcd_offset_x;
                cam_preview_data.tv_output_offset_y = lcd_offset_y;
            }
            else
            {
                /* tvout not enable , restore owner to GDI */
                if (g_mdi_camera_cntx.tvout_prev_owner != MDI_TV_OWNER_CAMERA)
                {
                    mdi_tvout_set_owner(g_mdi_camera_cntx.tvout_prev_owner);
                }
            }
        }   /* tvout is enable or not */
    }
#endif /* __MMI_TVOUT__ */ 

#if (MDI_CAMERA_MT6228_SERIES)
    /* store preview info for MT6228 burst shot */
    g_mdi_camera_cntx.lcd_id = cam_preview_data.lcd_id;
    g_mdi_camera_cntx.lcm_start_x = cam_preview_data.lcd_start_x;
    g_mdi_camera_cntx.lcm_start_y = cam_preview_data.lcd_start_y;
    g_mdi_camera_cntx.lcm_end_x = cam_preview_data.lcd_end_x;
    g_mdi_camera_cntx.lcm_end_y = cam_preview_data.lcd_end_y;
    g_mdi_camera_cntx.update_layer = cam_preview_data.update_layer;
    g_mdi_camera_cntx.hw_update_layer = cam_preview_data.hw_update_layer;
    g_mdi_camera_cntx.frame_buf_size = cam_preview_data.image_buffer_size;
    g_mdi_camera_cntx.frame_buf_ptr = cam_preview_data.image_buffer_p;
    g_mdi_camera_cntx.roi_offset_x = cam_preview_data.roi_offset_x;
    g_mdi_camera_cntx.roi_offset_y = cam_preview_data.roi_offset_y;
    g_mdi_camera_cntx.tv_output_offset_x = cam_preview_data.tv_output_offset_x;
    g_mdi_camera_cntx.tv_output_offset_y = cam_preview_data.tv_output_offset_y;
#endif /* MDI_CAMERA_MT6228_SERIES */ 

    mdi_camera_p->is_preview_stopped = FALSE;

#ifdef __MTK_TARGET__
    ret = media_cam_barcode_preview(stack_int_get_active_module_id(), &cam_preview_data);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_CAMERA_ERR_HW_NOT_READY;
    }
    else
    {
        mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        return MDI_RES_CAMERA_SUCCEED;
    }
#else /* __MTK_TARGET__ */ 
    ret = MED_RES_OK;
    return ret;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_barcodereader_preview_stop
 * DESCRIPTION
 *  shutdown the camer module
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_RESULT
 *****************************************************************************/
MDI_RESULT mdi_camera_barcodereader_preview_stop(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->is_preview_stopped == FALSE)
    {
        media_cam_barcode_stop(stack_int_get_active_module_id());
    }

#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    /* already powered off */
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }

    mdi_camera_p->state = CAMERA_STATE_IDLE;
    mdi_camera_p->is_preview_stopped = TRUE;

    return MDI_RES_CAMERA_SUCCEED;

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
}
#endif /* BARCODE_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_flash_setting
 * DESCRIPTION
 *  This function will be called by mdi_switch_device_ownership when someone
 *  switch device ownership.
 *  When switching ownership, we will force media task to termiate all action
 *  and back to idle. MDI also need restore state to idle.
 * PARAMETERS
 *  is_on       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_flash_setting(BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    media_cam_flash_setting(stack_int_get_active_module_id(), is_on);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_camera_blocked_recovery
 * DESCRIPTION
 *  This function will be called by mdi_switch_device_ownership when someone
 *  switch device ownership.
 *  When switching ownership, we will force media task to termiate all action
 *  and back to idle. MDI also need restore state to idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_camera_blocked_recovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
        {
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
        }
    }
#endif /* __MMI_TVOUT__ */ 
#ifdef __MTK_TARGET__
    mdi_camera_p->state = CAMERA_STATE_POWER_OFF;
#endif 
}

/* hongzhe.liu add start */
#ifdef ANALOG_TV_SUPPORT

static MDI_RESULT mdi_camera_analog_tv_preview_start_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_cam_preview_req_struct cam_preview_data;

    U8 *buf_ptr;
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    MDI_RESULT ret;
    S32 lcd_width;
    S32 lcd_height;
    S32 lcd_offset_x;
    S32 lcd_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if preview on sublcd, set sublcd active, so we may get correct paramater from following functions */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_SUBLCD)
    {
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    }

    /* get layer info */
    gdi_layer_push_and_set_active(camera_preview_p->preview_layer_handle);

    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_layer_pop_and_restore_active();

    cam_preview_data.camera_offset_x = layer_offset_x;
    cam_preview_data.camera_offset_y = layer_offset_y;

    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_SUBLCD)
    {
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }

    /* preview on whihc lcm */
    if (camera_setting_p->lcm == MDI_CAMERA_PREVIEW_LCM_MAINLCD)
    {
        cam_preview_data.lcd_id = MAIN_LCD;
        lcd_width = LCD_WIDTH;
        lcd_height = LCD_HEIGHT;
    }
    else
    {
        cam_preview_data.lcd_id = SUB_LCD;
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    }

    cam_preview_data.preview_width = camera_setting_p->preview_width;
    cam_preview_data.preview_height = camera_setting_p->preview_height;

    if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270_MIRROR))
    {
        lcd_offset_x = GDI_LCD_WIDTH - layer_offset_y - layer_height;
        lcd_offset_y = layer_offset_x;
    }
    else if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90) ||
             (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90_MIRROR))
    {
        lcd_offset_x = layer_offset_y;
        lcd_offset_y = GDI_LCD_HEIGHT - layer_offset_x - layer_width;
    }
    else
    {
        lcd_offset_x = layer_offset_x;
        lcd_offset_y = layer_offset_y;
    }

    cam_preview_data.lcd_update = TRUE;
    
    /* lcd start x, start y are coordinate on LCM, is the region will be update by driver */
    cam_preview_data.lcd_start_x = lcd_offset_x;
    cam_preview_data.lcd_start_y = lcd_offset_y;

    if ((camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_270_MIRROR) ||
        (camera_setting_p->lcm_rotate == MDI_CAMERA_LCM_ROTATE_90_MIRROR))
    {
        /* rotate 90 or 270 for horizonal view */
        cam_preview_data.lcd_end_x = lcd_offset_x + layer_height - 1;
        cam_preview_data.lcd_end_y = lcd_offset_y + layer_width - 1;
        cam_preview_data.roi_offset_x = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_x;
        cam_preview_data.roi_offset_y = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_y;
    }
    else
    {
        cam_preview_data.lcd_end_x = lcd_offset_x + layer_width - 1;
        cam_preview_data.lcd_end_y = lcd_offset_y + layer_height - 1;

        cam_preview_data.roi_offset_x = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_x;
        cam_preview_data.roi_offset_y = (kal_uint16) GDI_LAYER_OFFSET + lcd_offset_y;
    }

    /* preview offset x, y are offset from lcd_start_x, lcd_start_y */
    cam_preview_data.preview_offset_x = 0;
    cam_preview_data.preview_offset_y = 0;

    cam_preview_data.image_buffer_p = (void*)buf_ptr;
    cam_preview_data.image_width = (kal_uint16) camera_setting_p->image_width;
    cam_preview_data.image_height = (kal_uint16) camera_setting_p->image_height;

    cam_preview_data.buffer_width = (kal_uint16) layer_width;
    cam_preview_data.buffer_height = (kal_uint16) layer_height;
    cam_preview_data.image_buffer_size =
        (kal_uint32) ((camera_setting_p->preview_width * camera_setting_p->preview_height *
                       GDI_LAYER.act_bit_per_pixel) >> 3);

    /* set settings parameters */
    cam_preview_data.effect = (kal_uint16) camera_setting_p->effect;
    cam_preview_data.WB = (kal_uint16) camera_setting_p->wb;
    cam_preview_data.exposure = (kal_uint16) camera_setting_p->ev;
    cam_preview_data.zoom_factor = (kal_uint16) camera_setting_p->zoom;
    cam_preview_data.banding_freq = (kal_uint8) camera_setting_p->banding;
    cam_preview_data.flash_mode = (kal_uint16) camera_setting_p->flash;

    cam_preview_data.brightness = (kal_uint16) camera_setting_p->brightness;
    cam_preview_data.contrast = (kal_uint16) camera_setting_p->contrast;
    cam_preview_data.saturation = (kal_uint16) camera_setting_p->saturation;
    cam_preview_data.hue = (kal_uint16) camera_setting_p->hue;
    cam_preview_data.night_mode = (kal_bool) camera_setting_p->night;
    cam_preview_data.snapshot_number = 1;

    cam_preview_data.continue_capture = (kal_uint8) camera_setting_p->continue_capture;

#if (MDI_CAMERA_MT6225_SERIES || MDI_CAMERA_MT6227_SERIES)
    cam_preview_data.ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data.dsc_mode = (kal_uint8) camera_setting_p->dsc_mode;
    cam_preview_data.af_metering_mode = (kal_uint8) camera_setting_p->af_metering_mode;
    cam_preview_data.af_mode = (kal_uint8) camera_setting_p->af_mode;
#elif (MDI_CAMERA_MT6228_SERIES)
    cam_preview_data.ae_metering_mode = (kal_uint8) camera_setting_p->ae_meter;
    cam_preview_data.iso_setting = (kal_uint8) camera_setting_p->iso;
    cam_preview_data.dsc_mode = (kal_uint8) camera_setting_p->dsc_mode;
    cam_preview_data.tv_setting = (kal_uint16) camera_setting_p->shutter_pri;
    cam_preview_data.av_setting = (kal_uint8) camera_setting_p->aperture_pri;
    cam_preview_data.af_metering_mode = (kal_uint8) camera_setting_p->af_metering_mode;
    cam_preview_data.af_mode = (kal_uint8) camera_setting_p->af_mode;

    cam_preview_data.overlay_frame_mode = camera_setting_p->overlay_frame_mode;
    cam_preview_data.overlay_color_depth = camera_setting_p->overlay_frame_depth;
    cam_preview_data.overlay_frame_source_key = camera_setting_p->overlay_frame_source_key;
    cam_preview_data.overlay_frame_width = camera_setting_p->overlay_frame_width;
    cam_preview_data.overlay_frame_height = camera_setting_p->overlay_frame_height;
    cam_preview_data.overlay_frame_buffer_address = camera_setting_p->overlay_frame_buffer_address;

    #ifdef __MTK_TARGET__
    cam_preview_data.image_data_format = IMGDMA_IBW_OUTPUT_RGB565;
    #endif
    cam_preview_data.image_pitch_mode = FALSE;
    cam_preview_data.tv_output = FALSE;
#endif 

    MDI_CAMERA_CHECK_FOCUS(0);
    MDI_CAMERA_CHECK_FOCUS(1);
    MDI_CAMERA_CHECK_FOCUS(2);
    MDI_CAMERA_CHECK_FOCUS(3);
    MDI_CAMERA_CHECK_FOCUS(4);

    /* rotate */
    cam_preview_data.rotate = camera_setting_p->preview_rotate;
    cam_preview_data.lcd_rotate = camera_setting_p->lcm_rotate;

    /* fixed para */
    cam_preview_data.gamma = 0;
    cam_preview_data.frame_rate = CAMERA_PERVIEW_FRAME_RATE;

    cam_preview_data.update_layer = camera_preview_p->blt_layer_flag;
    cam_preview_data.hw_update_layer = camera_preview_p->preview_layer_flag;
    cam_preview_data.src_key_color = camera_preview_p->src_key_color;   /* GDI_COLOR_TRANSPARENT */
    cam_preview_data.roi_background_color = GDI_COLOR_BLACK;

#if (MDI_CAMERA_MT6228_SERIES)
    cam_preview_data.tv_output = FALSE;
#endif 

    /* TV out */
#ifdef __MMI_TVOUT__

    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            /* set tvout owner to Camera */
            g_mdi_camera_cntx.tvout_prev_owner = mdi_tvout_get_owner();

            if (g_mdi_camera_cntx.tvout_prev_owner != MDI_TV_OWNER_CAMERA)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_CAMERA);
            }

            ret = mdi_tvout_get_para(
                    MDI_TV_OWNER_CAMERA,
                    (PU16) & cam_preview_data.tv_output_mode,     /* mode_ptr */
                    (PU16) & cam_preview_data.tv_output_width, /* buf_width_ptr */
                    (PU16) & cam_preview_data.tv_output_height,        /* buf_height_ptr */
                    (PU32) & cam_preview_data.tv_output_buffer_size,   /* buf size */
                    (PU8*) & cam_preview_data.tv_output_buffer1_address,      /* buf1 pp */
                    (PU8*) & cam_preview_data.tv_output_buffer2_address,      /* buf2 pp */
                    NULL,      /* rotate_buf_1_pp */
                    NULL);     /* rotate_buf_2_pp */

            if (ret == MDI_RES_TV_ENABLE)
            {
                cam_preview_data.tv_output = TRUE;
                cam_preview_data.tv_output_offset_x = lcd_offset_x;
                cam_preview_data.tv_output_offset_y = lcd_offset_y;
            }
            else
            {
                /* tvout not enable , restore owner to GDI */
                if (g_mdi_camera_cntx.tvout_prev_owner != MDI_TV_OWNER_CAMERA)
                {
                    mdi_tvout_set_owner(g_mdi_camera_cntx.tvout_prev_owner);
                }
            }
        }   /* tvout is enable or not */
    }
#endif /* __MMI_TVOUT__ */ 

#if (MDI_CAMERA_MT6228_SERIES)
    /* store preview info for MT6228 burst shot */
    g_mdi_camera_cntx.lcd_id = cam_preview_data.lcd_id;
    g_mdi_camera_cntx.lcm_start_x = cam_preview_data.lcd_start_x;
    g_mdi_camera_cntx.lcm_start_y = cam_preview_data.lcd_start_y;
    g_mdi_camera_cntx.lcm_end_x = cam_preview_data.lcd_end_x;
    g_mdi_camera_cntx.lcm_end_y = cam_preview_data.lcd_end_y;
    g_mdi_camera_cntx.update_layer = cam_preview_data.update_layer;
    g_mdi_camera_cntx.hw_update_layer = cam_preview_data.hw_update_layer;
    g_mdi_camera_cntx.frame_buf_size = cam_preview_data.image_buffer_size;
    g_mdi_camera_cntx.frame_buf_ptr = cam_preview_data.image_buffer_p;
    g_mdi_camera_cntx.roi_offset_x = cam_preview_data.roi_offset_x;
    g_mdi_camera_cntx.roi_offset_y = cam_preview_data.roi_offset_y;
    g_mdi_camera_cntx.tv_output_offset_x = cam_preview_data.tv_output_offset_x;
    g_mdi_camera_cntx.tv_output_offset_y = cam_preview_data.tv_output_offset_y;
#endif /* MDI_CAMERA_MT6228_SERIES */ 

    mdi_camera_p->is_preview_stopped = FALSE;

#ifdef __MTK_TARGET__
    ret = media_cam_preview(stack_int_get_active_module_id(), &cam_preview_data);

    if (ret != MED_RES_OK)
    {
        return MDI_RES_CAMERA_ERR_HW_NOT_READY;
    }
    else
    {
        mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        return MDI_RES_CAMERA_SUCCEED;
    }
#else /* __MTK_TARGET__ */ 
    ret = MED_RES_OK;
    return ret;
#endif /* __MTK_TARGET__ */ 

}


//extern void ev_dbg(const char * str );
MDI_RESULT mdi_camera_analog_tv_preview_start(
                    gdi_handle preview_layer_handle,
                    S32 preview_wnd_offset_x,
                    /* offset from lcd's left up corner */ S32 preview_wnd_offset_y,
                    /* offset from lcd's left up corner */ U16 preview_wnd_width,
                    /* preview window width */ U16 preview_wnd_height,
                    /* preview window height */ U32 blt_layer_flag,
                    /* which layer shall be blt by driver */ U32 preview_layer_flag,
                    /* preview on which layer */ gdi_color src_key_color,
                    /* src key color */ BOOL is_tvout,
                    /* is display preview on tvout */ mdi_camera_setting_struct *setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg check */
    ASSERT(blt_layer_flag > 0);
    ASSERT(preview_layer_flag > 0);

    g_mdi_camera_cntx.is_tvout = is_tvout;

    /* set preview wnd parameters */
    camera_preview_p->preview_layer_handle = preview_layer_handle;
    camera_preview_p->preview_wnd_offset_x = preview_wnd_offset_x;
    camera_preview_p->preview_wnd_offset_y = preview_wnd_offset_y;
    camera_preview_p->preview_wnd_width = preview_wnd_width;
    camera_preview_p->preview_wnd_height = preview_wnd_height;

    camera_preview_p->blt_layer_flag = blt_layer_flag;
    camera_preview_p->preview_layer_flag = preview_layer_flag;

    /* 
     * this parametes only needs for MT6218 with backend, for MT6218,
     * we only support 16 bit color depth, so, U16 is enoguth 
     */
    camera_preview_p->src_key_color = (U16) src_key_color;

    /* init camera parameters */
    memcpy(camera_setting_p, setting_p, sizeof(mdi_camera_setting_struct));

    
    if (mdi_camera_p->state == CAMERA_STATE_IDLE)
    {
        //ret = mdi_camera_analog_tv_preview_start_internal();
        ret = mdi_camera_preview_start_internal();

        if (ret >= 0)
        {
            /* preview successfully */
            mdi_camera_p->state = CAMERA_STATE_PREVIEWING;
        }

        return ret;
    }
    else
    {
        /* start preview at wrong state */
    #ifndef __MTK_TARGET__  /* MNT Simulator */

        /* on MNT, direct call internal function for debugging */
        mdi_camera_analog_tv_preview_start_internal();
        return MDI_RES_CAMERA_SUCCEED;

    #else /* __MTK_TARGET__ */ 
        /* Target */
        return MDI_RES_CAMERA_ERR_FAILED;
    #endif /* __MTK_TARGET__ */ 
    	}
}

MDI_RESULT mdi_camera_analog_tv_preview_stop()
{
	mdi_camera_preview_stop();
	mdi_camera_power_off();
#if 0
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_camera_p->is_preview_stopped == FALSE)
    {
        media_cam_barcode_stop(stack_int_get_active_module_id());
    }

#ifdef __MMI_TVOUT__
    /* restore owner to GDI */
    if (g_mdi_camera_cntx.is_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            if (g_mdi_camera_cntx.tvout_prev_owner == MDI_TV_OWNER_GDI)
            {
                mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            }
        }
    }
#endif /* __MMI_TVOUT__ */ 

    /* already powered off */
    if (mdi_camera_p->state == CAMERA_STATE_POWER_OFF)
    {
        return MDI_RES_CAMERA_SUCCEED;
    }

    mdi_camera_p->state = CAMERA_STATE_IDLE;
    mdi_camera_p->is_preview_stopped = TRUE;

    return MDI_RES_CAMERA_SUCCEED;

#else /* __MTK_TARGET__ */ 
    /* avoid compile warning in MNT */
    return MDI_RES_CAMERA_SUCCEED;
#endif /* __MTK_TARGET__ */ 
#endif
}

#endif
/* hongzhe.liu add end */

#endif /* __MMI_CAMERA__ */ 

