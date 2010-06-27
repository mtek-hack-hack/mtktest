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
 *  gdi_image_hwgif.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Hardware Gif related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "stdc.h"
//#include "MMI_features.h"
//#include "MMIDataType.h"
//#include "fat_fs.h"

#include "gdi_internal.h"
#include "gd_primitive.h"
#include "gdd_include.h"

#if defined(__MTK_TARGET__)
#pragma Otime
#pragma no_check_stack
#endif /* defined(__MTK_TARGET__) */ 

extern U16 gdi_image_gif_transparent_index;
extern U8 gdi_image_gif_palette_size;

#if defined(GDI_USING_HW_GIF)

#include "2d_engine.h"
#include "gif_decoder.h"

static U16 gct_palette[256];
static U16 *lct_palette = (U16*)gdi_gif_local_palette;


static gif_para_struct para;
static gif_info_struct info;
static int last_frame;

extern gdi_image_gif_struct gdi_gif_cache[];
extern void GIF_Config_resource(gif_resource_struct *resource);


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_hwgif_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gif_resource_struct resource;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g2d_init();

    memset(&para, 0, sizeof(para));

    para.decode_test = KAL_FALSE;
    para.work_adrs = (kal_uint32) gdi_work_buffer;
    para.work_size = (kal_uint32) gdi_work_buffer_size;

    resource.stack = (kal_uint8*) gdi_gif_stack;
    resource.tree = (kal_uint8*) GDI_TREE_BUFFER;
    resource.GCT = (kal_uint8*) gct_palette;
    resource.LCT = (kal_uint8*) lct_palette;

    resource.stack_size = GDI_GIF_STACK_SIZE;
    resource.tree_size = GDI_GIF_TREE_SIZE;
    resource.GCT_size = 512;
    resource.LCT_size = 512;

    GIF_Config_resource(&resource);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                     [?]         
 *  src_size                [IN]        
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  frame_number            [IN]        
 *  use_disposal_method     [IN]        
 *  is_transparent          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_hwgif_display(
            U8 *src,
            U32 src_size,
            S32 ox,
            S32 oy,
            U16 frame_number,
            BOOL use_disposal_method,
            BOOL *is_transparent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
    BOOL single_bank_cache_reloaded;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
    if (gdi_image_single_bank_cache_load(src, src_size, &single_bank_cache_reloaded) != GDI_SUCCEED)
    {
        return GDI_FAILED;
    }
    
    src = gdi_image_single_bank_cache_get_buffer();
#endif /* GDI_USING_IMAGE_SINGLE_BANK_CACHE */
    
    do
    {
        gdi_image_gif_transparent_index = 256;
    #ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
        if (src != para.img_adrs || last_frame + 1 != frame_number || single_bank_cache_reloaded)    
    #else
        if (src != para.img_adrs || last_frame + 1 != frame_number)
    #endif        
        {
            para.img_adrs = src;
            para.img_size = src_size;
            para.reset = KAL_TRUE;
        }
        else
        {
            para.reset = KAL_FALSE;
        }
        last_frame = frame_number;

        if (use_disposal_method)
        {
            para.disposal_force = GIF_MTK_NO_ACTION;
        }
        else
        {
            para.disposal_force = GIF_NOT_DISPOSAL;
        }

        para.frame_number = frame_number;

        para.clip_x1 = GDI_LAYER.clipx1;
        para.clip_y1 = GDI_LAYER.clipy1;
        para.clip_x2 = GDI_LAYER.clipx2;
        para.clip_y2 = GDI_LAYER.clipy2;

        para.dest_x = ox;
        para.dest_y = oy;

        para.shadow_adrs = (kal_uint32) GDI_LAYER.buf_ptr;
        para.shadow_width = GDI_LAYER.width;
        para.shadow_height = GDI_LAYER.height;

        switch (GIF_Display_HW(&para, &info))
        {
            case GIF_FINISH_FRAME:
                result = GDI_SUCCEED;
                break;
            case GIF_LAST_FRAME:
                result = GDI_SUCCEED;
                break;
            case GIF_OUT_OF_RANGE:
                result = GDI_SUCCEED;
                break;
            case GIF_FORMAT_ERROR:
                result = GDI_FAILED;
                break;
                /*
                 * case GIF_NO_FRAME:
                 * case GIF_DECODE_TIMEOUT:
                 * case GIF_TRUNCATED_FILE:
                 * case GIF_MEM_INSUFFICEITN:
                 */
            default:
                result = GDI_FAILED;
                break;
        }
        gdi_anim_set_delay(info.delay_time * 10);
        gdi_image_set_update_area(ox,oy,ox+info.width-1,oy+info.height-1);

        gdi_image_gif_width = info.width;
        gdi_image_gif_height = info.height;
        *is_transparent = info.transparent_flag;
        if (info.transparent_flag)
        {
            gdi_image_gif_transparent_index = (U16) info.transparent_index;
        }

    } while (0);

    /* decode fail , force the reset the hw gif decoder. */
    if (result < 0)
    {
        para.img_adrs = NULL;
    }

    return result;
}

#endif /* defined(GDI_USING_HW_GIF) */ 

#ifdef GDI_USING_HW_GIF_V2

#include "fs_type.h"
#include "gif_decoder_v2.h"
#include "drm_gprot.h"

#include "med_api.h"
#include "med_main.h"
#include "med_struct.h"

typedef struct
{
    gif_status_enum cause;
    U32 fn;
} gdi_image_hwgif_state_struct;

static gif_config_struct gdi_image_hw_gif_v2_config;
static gif_info_struct gdi_image_hw_gif_v2_info;
static  gdi_image_hwgif_state_struct gif_result;
static U32 gct_palette[256];
static U32 *lct_palette = (U32*)gdi_gif_local_palette;

/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_cf_to_hw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cf          [IN]        
 *  hwgif       [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_cf_to_hw(gdi_color_format cf, gif_out_format_enum *hwgif)
{
#ifdef GDI_USING_HW_GIF_V2
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cf)
    {
        case GDI_COLOR_FORMAT_8:
            *hwgif = GIF_OUT_INDEX;
            break;
        case GDI_COLOR_FORMAT_16:
            *hwgif = GIF_OUT_RGB565;
            break;
        case GDI_COLOR_FORMAT_24:
            *hwgif = GIF_OUT_RGB888;
            break;
        default:
            return GDI_FAILED;  /* hardware gif decoder didn't support this color format */
    }
    return GDI_SUCCEED;

#else /* GDI_USING_HW_GIF_V2 */ 
    return GDI_FAILED;
#endif /* GDI_USING_HW_GIF_V2 */ 
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_gif_cf_from_hw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hwcf        [IN]        
 *  cf          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_gif_cf_from_hw(U8 hwcf, gdi_color_format *cf)
{
#ifdef GDI_USING_HW_GIF_V2
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (hwcf)
    {
        case GIF_OUT_INDEX:
            *cf = GDI_COLOR_FORMAT_8;
            break;
        case GIF_OUT_RGB565:
            *cf = GDI_COLOR_FORMAT_16;
            break;
        case GIF_OUT_RGB888:
            *cf = GDI_COLOR_FORMAT_24;
            break;
        default:
            return GDI_FAILED;
    }
    return GDI_SUCCEED;
#else /* GDI_USING_HW_GIF_V2 */ 
    return GDI_FAILED;
#endif /* GDI_USING_HW_GIF_V2 */ 
}


/*****************************************************************************
 * FUNCTION
 *  img_cal_work_buffer_info
 * DESCRIPTION
 *****************************************************************************/
static void gdi_image_hwgif_img_cal_work_buffer_info(
        kal_uint8 *ret_ratio,
        kal_int16 *wb_dest_x,
        kal_int16 *wb_dest_y,
        kal_uint16 *wb_width,
        kal_uint16 *wb_height,
        kal_uint32 wb_pixel_size,
        kal_uint16 img_w,
        kal_uint16 img_h,
        kal_int16 dest_x,
        kal_int16 dest_y,
        kal_uint16 expect_w,
        kal_uint16 expect_h,
        kal_int16 clipx1,
        kal_int16 clipy1,
        kal_int16 clipx2,
        kal_int16 clipy2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dx, dy;
    S32 dx1, dy1, dx2, dy2, dw, dh;
    S32 sx1, sy1, sx2, sy2, sw, sh;
    S32 rw1, rw2, rh1, rh2;
    S32 ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize default value */
    *ret_ratio = 0;
    *wb_dest_x = dest_x;
    *wb_dest_y = dest_y;

    dx = dest_x;
    dy = dest_y;
    dw = expect_w;
    dh = expect_h;

    sw = img_w;
    sh = img_h;

    rw1 = sw - 1;
    rw2 = dw - 1;
    rh1 = sh - 1;
    rh2 = dh - 1;
    if (rw2 <= 0)
    {
        rw2 = 1;
    }
    if (rh2 <= 0)
    {
        rh2 = 1;
    }

    /* calculate  C   (the real output area) */
    dx1 = dx;
    dy1 = dy;
    dx2 = dx1 + dw - 1;
    dy2 = dy1 + dh - 1;
    GDI_CLIP_TWO_RECT(dx1, dy1, dx2, dy2, clipx1, clipy1, clipx2, clipy2, return);
    dw = dx2 - dx1 + 1;
    dh = dy2 - dy1 + 1;

    /* calculate S  ( the source area which is mapping to C ) */
    sx1 = (dx1 - dx) * rw1 / rw2;
    sy1 = (dy1 - dy) * rh1 / rh2;
    sx2 = (dx2 - dx) * rw1 / rw2;
    sy2 = (dy2 - dy) * rh1 / rh2;
    sw = sx2 - sx1 + 1;
    sh = sy2 - sy1 + 1;

    /* check the ratio , how to fit into work buffer */
    for (ratio = 0; (sw >> ratio) * (sh >> ratio) > wb_pixel_size; ratio++)
    {
        ;
    }

    *ret_ratio = ratio;

    /* calculate the work buffer width/height depends on the ratio of sw,sh */
    *wb_width = sw >> ratio;
    *wb_height = sh >> ratio;

    /* calculate the dest_x,dest_y in work buffer coordinate */
    *wb_dest_x = -sx1 / (1 << ratio);
    *wb_dest_y = -sy1 / (1 << ratio);

}

void gdi_image_hwgif_callback(gif_status_enum status, kal_uint32 fn)
{
    gdi_image_hwgif_state_struct data;
    data.cause = status;
    data.fn = fn;
    gdd_send_img_codec_ind(&data,sizeof(data));
}
void gdi_image_hwgif_msg_handler(ilm_struct *ilm)
{
    gdi_image_hwgif_state_struct *p = (gdi_image_hwgif_state_struct*)
                                            &(((gdd_img_codec_event_ind_struct*)ilm->local_para_ptr)->header);
    if(!gdi_image_progress_callback())
        gif_result.cause = GIF_STATUS_TIMEOUT;
    
    gif_result.cause = p->cause;
    while(1)
    {
        switch(gif_result.cause)
        {
        case GIF_DECODING: // do nothing, just wait HW GIF...
            break;
        case GIF_STATUS_INEMPTY:
            gif_result.cause = gif_decode_resume(&gdi_image_hw_gif_v2_config, &gdi_image_hw_gif_v2_info);
            continue;
        case GIF_STATUS_COMPLETE:
            if (gdi_image_hw_gif_v2_config.frame_number > p->fn)      /* still need decode next frame */
            {
                gif_result.cause = gif_decode_resume(&gdi_image_hw_gif_v2_config, &gdi_image_hw_gif_v2_info);
                continue;                
            }
            else    /* reach target frame */
            {
                /* finish */
            }
        default:
            gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, NULL);
            gif_decode_stop();
            GDD_SET_EVENT(GDD_EVENT_WAIT_DECODING);
        }
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_start_decode
 * DESCRIPTION
 *  This function is to active gif driver to run
 *****************************************************************************/
void gdi_image_hwgif_start_decode(void)
{
    U8 cause;
    gdd_register_msg_handler(MSG_ID_MMI_GDD_IMG_CODEC_EVENT_IND, gdi_image_hwgif_msg_handler);
    
    cause = gif_decode_start(&gdi_image_hw_gif_v2_config,&gdi_image_hw_gif_v2_info);
    
    if(cause ==GIF_DECODING)
    {
//        gdd_start_timer(GDD_TIMER_IMAGE_CODEC_TIMEOUT,
//                        GDI_HW_JPEG_CODEC_WAITING_TIME,
//                        gdi_image_hwjpeg_timeout_handler, 0);
    }
    else
        gdi_image_hwgif_callback(cause,gdi_image_hw_gif_v2_config.frame_number);

    GDD_WAIT_EVENT(GDD_EVENT_WAIT_DECODING);
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_hwgif_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gif_init();
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_display_internal
 * DESCRIPTION
 *****************************************************************************/
GDI_RESULT gdi_image_hwgif_display_internal(
            U8 *src,
            U32 size,
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U16 frame_number,
            BOOL is_file,
            BOOL is_resized,
            BOOL use_disposal_method,
            BOOL is_blocking,
            BOOL transparent_enable,
            void (*callback) (GDI_RESULT result))
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_hwgif_display_internal)
    {
        gif_config_struct *config = &gdi_image_hw_gif_v2_config;
        gif_info_struct   *info   = &gdi_image_hw_gif_v2_info;
        FS_HANDLE file_handle = 0;

        gdi_image_gif_transparent_index = 256;

        if (is_file)
        {
            file_handle = *(FS_HANDLE *) gdi_bytestream_handle;

            if (file_handle < 0)
                GDI_RETURN(GDI_FAILED);

            config->decode_mode= GIF_DECODE_FILE;
            config->cache_id = gdi_image_gif_get_cache_key_from_file(file_handle, (S8*) src, size);
            config->file_handle= file_handle;
            config->file_buffer_adrs = (U8*)gdi_bytestream_buffer;
            config->file_buffer_size = BYTESTREAM_BUFFER_SIZE;
        }
        else
        {
            config->decode_mode= GIF_DECODE_MEMORY;
            config->cache_id = (U32) src;
            config->file_buffer_adrs = src;
            config->file_buffer_size = size;
        }

        if (!is_resized)
            resized_width = resized_height = 0; /* use orignal size */

        config->output_buffer_adrs = gdi_act_layer->buf_ptr;
        config->output_buffer_size = gdi_act_layer->layer_size;

        if (gdi_image_gif_cf_to_hw(gdi_act_layer->vcf, &config->out_format) != GDI_SUCCEED)
        {
            GDI_RETURN(GDI_FAILED);
        }

        config->disposal_en = use_disposal_method;

        config->work_buffer_size = gdi_work_buffer_size;
        config->work_buffer_adrs = (kal_uint8*)gdi_work_buffer;


        config->stack_adrs = (kal_uint32*) gdi_gif_stack;
        config->stack_size = GIF_STACK_SIZE;

        config->tree_adrs = (kal_uint32*)GDI_TREE_BUFFER;
        config->tree_size = GIF_TREE_SIZE;

        config->GCT_adrs = gct_palette;
        config->LCT_adrs = lct_palette;

        config->shadow_w = gdi_act_layer->width;
        config->shadow_h = gdi_act_layer->height;

        config->clip_x1 = gdi_act_layer->clipx1;
        config->clip_y1 = gdi_act_layer->clipy1;
        config->clip_x2 = gdi_act_layer->clipx2;
        config->clip_y2 = gdi_act_layer->clipy2;
        
        config->dest_x = ox;
        config->dest_y = oy;
        config->expect_w = (U16)resized_width;
        config->expect_h = (U16)resized_height;
        
        config->pack_enable = KAL_FALSE;
        config->clip_enable = KAL_TRUE;
        config->frame_number = frame_number;
        config->transparent_enable = transparent_enable;

        config->gif_cb = gdi_image_hwgif_callback;
        config->cal_work_buffer_info_func = gdi_image_hwgif_img_cal_work_buffer_info;

        if (gdi_act_layer_info->source_key_enable)
        {
            config->src_key = gdi_act_layer_info->source_key;
        }
        else
        {
            config->src_key = 0x01ffffff;
        }

        // setting the background color        
		{
            S32 x1,y1;
            x1=ox;
            y1=oy;

			if(x1<gdi_act_layer->clipx1) x1 = gdi_act_layer->clipx1;
			if(y1<gdi_act_layer->clipy1) y1 = gdi_act_layer->clipy1;
            
			config->bg_color = gdi_act_get_pixel(x1,y1);
		}

        gdi_image_hwgif_start_decode(); // and blocking until finish/error

        if(gif_result.cause != GIF_STATUS_COMPLETE)
            GDI_RETURN(GDI_FAILED);

        /* process the resize if need */
        {
            S32 resz_w = (S32) info->resz_w;
            S32 resz_h = (S32) info->resz_h;
            S32 lx, ly, lw, lh;

            lx = info->x >> resz_w;
            ly = info->y >> resz_h;
            lw = info->w >> resz_w;
            lh = info->h >> resz_h;

            if (info->use_work_buf && lw > 0 && lh > 0)
            {
                gdi_color_format cf;
                gdi_color src_key, layer_key;
                gd_bitblt_func bitblt;
                S32 dx1, dy1, dx2, dy2;
                S32 sx1, sy1, sx2, sy2;

                if (info->transparent_flag)
                {
                    src_key = info->src_key_2d;
                }
                else
                {
                    src_key = 0x01ffffff;
                }
                layer_key = config->src_key;

                gdi_image_gif_cf_from_hw(config->out_format, &cf);

                if ((info->lwidth >> resz_w) == config->expect_w
                    && (info->lheight >> resz_h) == config->expect_h)
                {
                    dx1 = config->dest_x + lx;
                    dy1 = config->dest_y + ly;
                    dx2 = dx1 + lw - 1;
                    dy2 = dy1 + lh - 1;

                    sx1 = info->wb_dest_x + lx;
                    sy1 = info->wb_dest_y + ly;
                    sx2 = sx1 + lw - 1;
                    sy2 = sy1 + lh - 1;

                    bitblt = gd_bitblt[cf];
                }
                else
                {
                    S32 rw1, rw2;
                    S32 rh1, rh2;

                    /* init rh/rw */
                    rw1 = config->expect_w - 1;
                    rh1 = config->expect_h - 1;
                    rw2 = (info->lwidth >> resz_w) - 1;
                    rh2 = (info->lheight >> resz_h) - 1;
                    if (rw2 <= 0)
                    {
                        rw2 = 1;
                    }
                    if (rh2 <= 0)
                    {
                        rh2 = 1;
                    }

                    /* calculate (sx1,sy1)-(sx2,sy2) */
                    sx1 = lx;
                    sy1 = ly;

                    sx2 = sx1 + lw - 1;
                    sy2 = sy1 + lh - 1;

                    /* calculate (dx1,dy1)-(dx2,dy2) */
                    dx1 = sx1 * rw1 / rw2;
                    dx2 = sx2 * rw1 / rw2;

                    dy1 = sy1 * rh1 / rh2;
                    dy2 = sy2 * rh1 / rh2;

                    /* move to real  destination */
                    sx1 += info->wb_dest_x;
                    sx2 += info->wb_dest_x;
                    sy1 += info->wb_dest_y;
                    sy2 += info->wb_dest_y;

                    dx1 += config->dest_x;
                    dx2 += config->dest_x;
                    dy1 += config->dest_y;
                    dy2 += config->dest_y;

                    bitblt = gd_resize_bitblt[cf];
                }
                bitblt(
                    config->output_buffer_adrs,
                    config->shadow_w,
                    config->shadow_h,
                    dx1,
                    dy1,
                    dx2,
                    dy2,
                    config->work_buffer_adrs,
                    info->wb_width,
                    info->wb_height,
                    sx1,
                    sy1,
                    sx2,
                    sy2,
                    config->clip_x1,
                    config->clip_y1,
                    config->clip_x2,
                    config->clip_y2,
                    src_key,
                    layer_key);
            }
        }            

        gdi_anim_set_delay(gdi_image_hw_gif_v2_info.delay_time * 10);
        gdi_image_set_update_area(ox,oy,ox+gdi_image_hw_gif_v2_info.lwidth-1,oy+gdi_image_hw_gif_v2_info.lheight-1);
        
        gdi_image_gif_width = gdi_image_hw_gif_v2_info.lwidth;
        gdi_image_gif_height = gdi_image_hw_gif_v2_info.lheight;


        /* Support Color Index Overlay */
        if (gdi_act_layer->vcf == GDI_COLOR_FORMAT_8)
        {
            int i = 0;
            U32 *active_palette;

            if (gdi_image_hw_gif_v2_info.LCT_flag)
            {
                active_palette = &lct_palette[0];
                gdi_image_gif_palette_size = gdi_image_hw_gif_v2_info.LCT_size;
            }
            else
            {
                active_palette = &gct_palette[0];
                gdi_image_gif_palette_size = gdi_image_hw_gif_v2_info.GCT_size;
            }
            for (i = 0; i < gdi_image_gif_palette_size; i++)
            {
                gdi_layer_set_palette(i, active_palette[i]);
            }

            if (gdi_image_hw_gif_v2_info.transparent_flag)
            {
                gdi_image_gif_transparent_index = (U16) gdi_image_hw_gif_v2_info.transparent_index;
            }

        }
        GDI_RETURN(GDI_SUCCEED);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_hwgif_display_internal)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_hwgif_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                     [?]         
 *  src_size                [IN]        
 *  ox                      [IN]        
 *  oy                      [IN]        
 *  frame_number            [IN]        
 *  use_disposal_method     [IN]        
 *  is_transparent          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_hwgif_display(
            U8 *src,
            U32 src_size,
            S32 ox,
            S32 oy,
            U16 frame_number,
            BOOL use_disposal_method,
            BOOL *is_transparent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_hwgif_display)
    GDI_RESULT result = gdi_image_hwgif_display_internal(
                            src,
                            src_size,
                            ox,
                            oy,
                            0,
                            0,      /* no resize */
                            frame_number,
                            FALSE,  /* no src file */
                            FALSE,  /* no resize */
                            use_disposal_method,
                            TRUE,   /* blocking */
                            TRUE,   /* transpanent enable */
                            NULL /* no callback function */ );

    if (result >= 0)
    {
        *is_transparent = gdi_image_hw_gif_v2_info.transparent_flag;
    }
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_hwgif_display)
}
#endif /* GDI_USING_HW_GIF_V2 */ 


