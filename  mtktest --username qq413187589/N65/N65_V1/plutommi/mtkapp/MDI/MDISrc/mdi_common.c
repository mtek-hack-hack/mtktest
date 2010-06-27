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
 *  mdi_common.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MDI (Media Device Interface) common functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

/***************************************************************************** 
* Include
*****************************************************************************/
#include "stdC.h"
#include "L4Dr1.h"

#include "MMIDataType.h"    /* MMI Data type */
#include "gdi_include.h"        /* gdi */
#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_include.h"
#include "mdi_audio.h"          /* audio */
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)
#include "mdi_video.h"          /* video */
#endif 
#ifdef __MMI_CAMERA__
#include "mdi_camera.h"         /* camera */
#endif 
#include "lcd_if.h"             /* lcd interface */

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"             /* tvout */
#endif 

#include "DebugInitDef.h"       /* debug */

#ifdef  __MMI_GPS__
#include "mdi_gps.h"
#endif  /* __MMI_GPS__  */
// #ifdef __MMI_TARGET__
#include "med_api.h"    /* media task */
#include "med_main.h"   /* media task */
#include "med_struct.h" /* media task */
// #endif /* __MMI_TARGET__ */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    module_type mod_id;
    // TODO: shall split into audio_owner, video_owner, camera_owner in the future
} mdi_cnxt_struct;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/
mdi_cnxt_struct g_mdi_cntx = 
{
    MOD_MMI /* mod_id */
};


/*****************************************************************************
 * FUNCTION
 *  mdi_switch_device_ownership
 * DESCRIPTION
 *  This function is used for multiple tasks to get owner shipof multimedia device,
 *  such as audio, camera and video, etc.
 *  The previous action on this device will be forced to terminate.
 * PARAMETERS
 *  mod_id      [IN]        Owner, one of MOD_MMI, MOD_J2ME, etc
 *  device      [IN]        Device
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_switch_device_ownership(module_type mod_id, MDI_DEVICE_TYPE device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(device != 0);

    // TODO: shall split and check each device in the future
    if (device)
    {
        /* call this function will terminate ALL current using device and restore it to idle state */
        /* mdi_audio_block(mod_id); */
        media_aud_block(MOD_MMI, (kal_uint16) mod_id, (kal_uint8) AUD_BLOCK_ALL);

        /* call each device for state recovery since MEDIA/Driver is terminated */
        mdi_audio_blocked_recovery();

    #if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)
        mdi_video_blocked_recovery();
    #endif 

    #if defined(__MMI_CAMERA__)
        mdi_camera_blocked_recovery();
    #endif 
    }

    g_mdi_cntx.mod_id = mod_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_get_device_ownership
 * DESCRIPTION
 *  get current device ownership
 * PARAMETERS
 *  device      [IN]        Device
 * RETURNS
 *  module_type
 *****************************************************************************/
module_type mdi_get_device_ownership(MDI_DEVICE_TYPE device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mdi_cntx.mod_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_check_device_ownership
 * DESCRIPTION
 *  check current device ownership
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_check_device_ownership()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type module_id = stack_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mdi_cntx.mod_id == module_id)
    {
        return TRUE;
    }
    else
    {
        if (MOD_WAP == module_id)
        {
            PRINT_INFORMATION("mdi_check_device_ownership, WAP access MDI\n");
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_calc_blt_para()
 * DESCRIPTION
 *  Calculate blt parameters for camera / video / vcall
 * PARAMETERS
 *  disp_layer_handle   [IN]    display layer
 *  lcd_rotate          [IN]    lcd rotate value
 *  lcd id              [IN]    lcd id (using GDI_LCD_XXX_LCD_HANDLE)
 *  is_tvout            [IN]    tvout enable or not
 *  blt_data_p          [OUT]   blt parameters
 * RETURNS
 * BOOL
 *****************************************************************************/
void mdi_calc_blt_para(
    gdi_handle disp_layer_handle, 
    U16 lcd_rotate, 
    gdi_handle lcd_handle,    
    MMI_BOOL is_tvout,
    mdi_blt_para_struct *blt_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 lcd_offset_x;
    S32 lcd_offset_y;
    S32 lcd_start_x;
    S32 lcd_start_y;
    S32 lcd_end_x;
    S32 lcd_end_y;
    S32 clip_x1;
    S32 clip_y1;    
    S32 clip_x2;
    S32 clip_y2;    
    S32 lcd_width;
    S32 lcd_height;
    U8 *buf_ptr;
    U8 layer_rotate;
    gdi_handle prev_lcd_handle;
    U8 cur_lcd_rotate;
    S32 lcd_clip_x1;
    S32 lcd_clip_y1;    
    S32 lcd_clip_x2;        
    S32 lcd_clip_y2;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)blt_data_p, 0, sizeof(mdi_blt_para_struct));

    if (disp_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        /* null layer handle */
        return;
    }
        
    gdi_lcd_get_active(&prev_lcd_handle);
    gdi_lcd_set_active(lcd_handle);
    cur_lcd_rotate = gdi_lcd_get_rotate();

    if (cur_lcd_rotate == GDI_LAYER_ROTATE_0 || 
        cur_lcd_rotate == GDI_LAYER_ROTATE_0_MIRROR || 
        cur_lcd_rotate == GDI_LAYER_ROTATE_180 ||
        cur_lcd_rotate == GDI_LAYER_ROTATE_180_MIRROR)
    {
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    }        
    else
    {
        gdi_lcd_get_dimension(&lcd_height, &lcd_width);
    }

    gdi_lcd_set_active(prev_lcd_handle);

    /* get disp layer's paramters */
    gdi_layer_push_and_set_active(disp_layer_handle);


    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    layer_rotate = gdi_layer_get_rotate();    
    gdi_layer_pop_and_restore_active();

    /* transform the coordinate to phiscal LCD's coordinate */
    if ((lcd_rotate == MDI_LCD_ROTATE_270) || 
        (lcd_rotate == MDI_LCD_ROTATE_270_MIRROR))
    {
        lcd_offset_x = lcd_width - layer_offset_y - layer_height;
        lcd_offset_y = layer_offset_x;
    }
    else if ((lcd_rotate == MDI_LCD_ROTATE_90) || 
             (lcd_rotate == MDI_LCD_ROTATE_90_MIRROR))
    {
        lcd_offset_x = layer_offset_y;
        lcd_offset_y = lcd_height - layer_offset_x - layer_width;
    }
    else
    {
    #if defined(GDI_USING_LAYER_ROTATE)
        if (layer_rotate == MDI_LCD_ROTATE_90)
        {
            lcd_offset_x = lcd_width - layer_offset_y - layer_height;
            lcd_offset_y = layer_offset_x;
        }
        else
    #endif /* defined(GDI_USING_LAYER_ROTATE) */ 
        {
            lcd_offset_x = layer_offset_x;
            lcd_offset_y = layer_offset_y;
        }
    }

    lcd_start_x = lcd_offset_x;
    lcd_start_y = lcd_offset_y;

    /* if rotate 90 or 270 degree */
    if ((lcd_rotate == GDI_LAYER_ROTATE_90) || 
        (lcd_rotate == GDI_LAYER_ROTATE_90_MIRROR) ||
        (lcd_rotate == GDI_LAYER_ROTATE_270) || 
        (lcd_rotate == GDI_LAYER_ROTATE_270_MIRROR))
    {
        lcd_end_x = lcd_offset_x + layer_height - 1;
        lcd_end_y = lcd_offset_y + layer_width - 1;
    }
    else
    {
        lcd_end_x = lcd_offset_x + layer_width - 1;
        lcd_end_y = lcd_offset_y + layer_height - 1;
    }

    /* change clip from layer to lcd coord */
    if (MDI_LCD_ROTATE_90 == layer_rotate)
    {
        lcd_clip_x1 = layer_height - clip_y2 - 1;
        lcd_clip_x2 = layer_height - clip_y1 - 1;
        lcd_clip_y1 = clip_x1;
        lcd_clip_y2 = clip_x2;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_height - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_width - lcd_clip_y2 - 1);         
    }
    else if (MDI_LCD_ROTATE_180 == layer_rotate)
    {
        lcd_clip_x1 = layer_width - clip_x2 - 1;
        lcd_clip_x2 = layer_width - clip_x1 - 1;
        lcd_clip_y1 = layer_height - clip_y2 - 1;
        lcd_clip_y2 = layer_height - clip_y1 - 1;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_width - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_height - lcd_clip_y2 - 1);         
    }
    else if (MDI_LCD_ROTATE_270 == layer_rotate)
    {
        lcd_clip_x1 = clip_y2;
        lcd_clip_x2 = clip_y1;
        lcd_clip_y1 = layer_width - clip_x2 - 1;
        lcd_clip_y2 = layer_width - clip_x1 - 1;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_height - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_width - lcd_clip_y2 - 1);         
    }
    else
    {
        lcd_clip_x1 = clip_x1;
        lcd_clip_x2 = clip_x2;
        lcd_clip_y1 = clip_y1;
        lcd_clip_y2 = clip_y2;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_width - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_height - lcd_clip_y2 - 1);         
   }


    /* force inside lcd region */
    if (lcd_start_x < 0)
    {
        lcd_start_x = 0;
    }
    else if (lcd_start_x > lcd_width - 1)
    {
        lcd_start_x = lcd_width - 1;
    }

    if (lcd_start_y < 0)
    {
        lcd_start_y = 0;
    }
    else if (lcd_start_y > lcd_height - 1)
    {
        lcd_start_y = lcd_height - 1;
    }

    if (lcd_end_x < 0)
    {
        lcd_end_x = 0;
    }
    else if (lcd_end_x > lcd_width - 1)
    {
        lcd_end_x = lcd_width - 1;
    }

    if (lcd_end_y < 0)
    {
        lcd_end_y = 0;
    }
    else if (lcd_end_y > lcd_height - 1)
    {
        lcd_end_y = lcd_height - 1;
    }

    blt_data_p->lcd_start_x = lcd_start_x;
    blt_data_p->lcd_start_y = lcd_start_y;
    blt_data_p->lcd_end_x = lcd_end_x;
    blt_data_p->lcd_end_y = lcd_end_y;
    blt_data_p->display_width = layer_width;
    blt_data_p->display_height = layer_height;

    if (gdi_lcd_get_rotate_by_layer())
    {
        /* if using LCD rotate, the roi region will be the phisical potion as lcd */
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET + lcd_offset_x;
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET + lcd_offset_y;
    }
    else
    {
        /* if using LCM rotate, layers are rotated, so the position is the same as layer pos */
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET + layer_offset_x;
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET + layer_offset_y;
    }

    /* fit into clip */
    blt_data_p->roi_offset_x += lcd_clip_x1;
    blt_data_p->roi_offset_y += lcd_clip_y1; 

    /* force roi inside lcd region */
    if (blt_data_p->roi_offset_x < GDI_LAYER_OFFSET)
    {
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET;
    }
    else if (blt_data_p->roi_offset_x > GDI_LAYER_OFFSET + lcd_width - 1)
    {
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET + lcd_width - 1;
    }

    if (blt_data_p->roi_offset_y < GDI_LAYER_OFFSET)
    {
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET;
    }
    else if (blt_data_p->roi_offset_y > GDI_LAYER_OFFSET + lcd_height - 1)
    {
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET + lcd_height - 1;
    }

    blt_data_p->image_buffer_p = (void*)buf_ptr;
    blt_data_p->image_buffer_size = (layer_width * layer_height * GDI_LAYER.act_bit_per_pixel) >> 3;
    blt_data_p->lcd_rotate = lcd_rotate;
    blt_data_p->tv_output = FALSE;

    /* TV out */
#ifdef __MMI_TVOUT__
    if (is_tvout)
    {
        S32 ret;
        
        ret = mdi_tvout_get_para(
                MDI_TV_OWNER_VIDEO,
                NULL,                                           /* mode_ptr */
                (PU16)&blt_data_p->tv_output_width,             /* buf_width_ptr */
                (PU16)&blt_data_p->tv_output_height,            /* buf_height_ptr */
                (PU32)&blt_data_p->tv_output_buffer_size,       /* buf size */
                (PU8*)&blt_data_p->tv_output_buffer1_address,   /* buf1 pp */
                (PU8*)&blt_data_p->tv_output_buffer2_address,   /* buf2 pp */
                NULL,                                           /* rotate_buf_1_pp */
                NULL);                                          /* rotate_buf_2_pp */

        if (ret == MDI_RES_TV_ENABLE)
        {
            blt_data_p->tv_output = TRUE;
            blt_data_p->tv_output_offset_x = blt_data_p->roi_offset_x - GDI_LAYER_OFFSET;
            blt_data_p->tv_output_offset_y = blt_data_p->roi_offset_y - GDI_LAYER_OFFSET;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

#endif /* __MMI_TVOUT__ */ 

}



/*****************************************************************************
 * FUNCTION
 *  mdi_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of MDI library.
 *  This function my be added to the message handler of other task (ex: Java)
 *  Therefore, the asyn callback will be called under caller's context.
 *  [Example] 
 *  if Java called mdi_video_ply_open, the open result callback will be called 
 *  under Java's context if Java put this message dispatcher in its message handler
 * PARAMETERS
 *  ilm_ptr             [IN]    ilm pointer
 * RETURNS
 *  MDI consume the message or not 
 * RETURN VALUE LIST
 *  MMI_TRUE        MDI consume this message
 *  MMI_FALSE       MDI didnt consume this message
 *****************************************************************************/
MMI_BOOL mdi_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mdi_audio_message_dispatcher(ilm_ptr))
    {
        return MMI_TRUE;
    }
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)    
    else if(mdi_video_message_dispatcher(ilm_ptr))
    {
        return MMI_TRUE;
    }
#endif /* defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_VIDEO_RECORDER__)  */
#ifdef __MMI_GPS__
    else if(mdi_gps_uart_message_dispatcher(ilm_ptr))
    {
        return MMI_TRUE;
    }
#endif /* __MMI_GPS__ */    
    return MMI_FALSE;
}


