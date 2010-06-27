/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_image_png.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Jpeg decoder.
 *
 * Author:
 * -------
 * -------
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gd_primitive.h"
#include "drm_gprot.h"

#ifdef GDI_USING_PNG
#include "gd_2d_engine.h"

#include "gui.h"        /* for timer */
#include "Unicodexdcl.h"
#include "stdlib.h"

#include "med_global.h"
#include "med_utility.h"


#include "png_decoder.h"
extern void sw_png_hook_png_decode_progress_callback(kal_int32 (*png_decode_progress_callback)(void));
extern void sw_png_hook_img_update_callback(void (*image_update_callback)(kal_int32 x1,kal_int32 y1,kal_int32 x2,kal_int32 y2));

#define PNG_FILE_BUFFER_SIZE        (16*1024)
#define GDI_IMAGE_PNG_TIMEOUT       5000 /* ms */

static png_config_struct gdi_image_png_config;
static png_inform_struct gdi_image_png_info;
static png_report_status_enum gdi_image_png_status;

/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_png_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    png_init();
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_dimension_internal
 * DESCRIPTION
 *  get png dimension, source is from memory
 * PARAMETERS
 *  png_src     [IN]        
 *  size        [IN]        
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_png_get_dimension_internal(U8 *png_src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_png_get_dimension)
    U8 BUFFER[24];
    U8 *buffer;

    while (1)
    {
        if (size == 0)  /* from file */
        {
            int h = gdi_lfs_open(gdi_lfs_handle,(U16*) png_src, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);

            if (h >= 0)
            {
                U32 len;
                h = gdi_lfs_handle;

                buffer = BUFFER;
                gdi_lfs_read(h, buffer, 24, &len);
                gdi_lfs_close(h);
                if (len == 24)
                    break;  /* success read data */
            }
        }
        else if (size >= 24)    /* from memory */
        {
            memcpy(BUFFER, png_src, 24);
            buffer = BUFFER;   /* success get data */
            break;
        }
        GDI_RETURN(GDI_FAILED);
    }
    if (memcmp(buffer, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)  /* PNG signature */
        if (*((U32*) (buffer + 8)) == 13 << 24)             /* must be IHDR, length = 13,but LSB */
            if (memcmp(buffer + 12, "IHDR", 4) == 0)        /* must be 'IHDR' */
            {
                buffer += 16;
                *width = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
                buffer += 4;
                *height = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
                GDI_RETURN(GDI_SUCCEED);
            }
    GDI_RETURN(GDI_FAILED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_png_get_dimension)
}

GDI_RESULT gdi_image_png_cf_from_hw(U8 png, gdi_color_format *cf)
{
    switch (png)
    {
        case RGB565:
            *cf = GDI_COLOR_FORMAT_16;
            break;
        case RGB888:
            *cf = GDI_COLOR_FORMAT_24;
            break;
        case ARGB8888:
            *cf = GDI_COLOR_FORMAT_32;
            break;
        default:
            return GDI_FAILED;
    }
    return GDI_SUCCEED;
}


GDI_RESULT gdi_image_png_cf_to_hw(gdi_color_format cf, png_out_format_enum *png)
{
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            *png = RGB565;
            break;
        case GDI_COLOR_FORMAT_24:
            *png = RGB888;
            break;
        case GDI_COLOR_FORMAT_32:
            *png = ARGB8888;
            break;
        default:
            return GDI_FAILED;  /* hardware png decoder didn't support this color format */
    }
    return GDI_SUCCEED;
}
void gdi_image_png_callback(png_report_status_enum status)
{
    gdi_image_png_status = status;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_draw_internal
 * DESCRIPTION
 *  draw png
 *****************************************************************************/
GDI_RESULT gdi_image_png_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_blocking,
            void (*callback) (GDI_RESULT result))
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_png_draw_internal)
    {

        // set source image information        
        if (is_file)
        {
            gdi_image_png_config.decode_mode = PNG_DECODE_FILE;
            gdi_image_png_config.file_handle = DRM_open_file((U16*) src, FS_READ_ONLY | FS_OPEN_NO_DIR, DRM_PERMISSION_DISPLAY);
            if(gdi_image_png_config.file_handle<0)
                GDI_RETURN(GDI_FAILED);
            
            gdi_image_png_config.in_buffer_adrs = (kal_uint32) med_alloc_ext_mem(PNG_FILE_BUFFER_SIZE);
            GDI_DEBUG_ASSERT(gdi_image_png_config.in_buffer_adrs != NULL);
            if(gdi_image_png_config.in_buffer_adrs==NULL)
            {
                GDI_RETURN(GDI_FAILED);
            }
            gdi_image_png_config.in_buffer_size = PNG_FILE_BUFFER_SIZE;
        }
        else
        {
            gdi_image_png_config.decode_mode = PNG_DECODE_MEMORY;
            gdi_image_png_config.in_buffer_adrs = (kal_uint32) src;
            gdi_image_png_config.in_buffer_size = size;

        }
        // set output destination information
        gdi_image_png_config.output_buffer_adrs = (kal_uint32) gdi_act_layer->buf_ptr;
        gdi_image_png_config.output_buffer_size = gdi_act_layer->layer_size;
        gdi_image_png_config.shadow_w = gdi_act_layer->width;
        gdi_image_png_config.shadow_h = gdi_act_layer->height;
        gdi_image_png_cf_to_hw(gdi_act_layer->vcf, &gdi_image_png_config.out_format);

        // set work buffer for PNG decode
        gdi_image_png_config.work_buffer_size = gdi_work_buffer_size;
        gdi_image_png_config.work_buffer_adrs = (kal_uint32)gdi_work_buffer;

        // PNG decode buffer
        gdi_image_png_config.upper_buffer = (kal_uint32*) med_alloc_ext_mem(PNG_HW_BUFFER);
        GDI_DEBUG_ASSERT(gdi_image_png_config.upper_buffer != NULL);
        if(gdi_image_png_config.upper_buffer==NULL)
            GDI_RETURN(GDI_FAILED);

        // set clipping area
        gdi_image_png_config.clip_en = KAL_TRUE;
        gdi_image_png_config.clip_x1 = gdi_act_layer->clipx1;
        gdi_image_png_config.clip_y1 = gdi_act_layer->clipy1;
        gdi_image_png_config.clip_x2 = gdi_act_layer->clipx2;
        gdi_image_png_config.clip_y2 = gdi_act_layer->clipy2;

        // set output destination area
        gdi_image_png_config.dest_x = (S16)ox;
        gdi_image_png_config.dest_y = (S16)oy;
        gdi_image_png_config.expect_w = (kal_uint16) resized_width;
        gdi_image_png_config.expect_h = (kal_uint16) resized_height;

        // pass the layer source key if need
        if (gdi_act_layer_info->source_key_enable)
            gdi_image_png_config.src_key = gdi_act_layer_info->source_key;
        else
            gdi_image_png_config.src_key = 0x01ffffff;

        // misc
        gdi_image_png_config.cb = gdi_image_png_callback;
        gdi_image_png_config.cal_work_buffer_info_func = NULL;
        gdi_image_png_config.png_timeout_period = GDI_IMAGE_PNG_TIMEOUT/10;

        // callback
        {
            sw_png_hook_png_decode_progress_callback(gdi_image_progress_callback);
            sw_png_hook_img_update_callback(gdi_image_set_update_area);
        }

        /* trigger png decode */
        {
            png_report_status_enum status;
            status = png_decode_start(&gdi_image_png_config, &gdi_image_png_info);
            if (status != PNG_DECODING)
                gdi_image_png_status = status;
        }
        
        if (is_file)
        {
            med_free_ext_mem((void **)&gdi_image_png_config.in_buffer_adrs);
            DRM_close_file(gdi_image_png_config.file_handle);
        }
        med_free_ext_mem((void **)&gdi_image_png_config.upper_buffer);
        png_decode_stop();

        // check decode result
        {
            GDI_RESULT ret;
            switch(gdi_image_png_status)
            {
            case PNG_DECODE_TIMEOUT: ret = GDI_IMAGE_ERR_DECODE_TIME_OUT;break;
            case PNG_FINISH_IMAGE: ret = GDI_SUCCEED; break;
            default: ret = GDI_FAILED;break;
            }
            GDI_RETURN(ret);
        }
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_png_draw_internal)
}

#else /* not support png format */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_dimension_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  png_src     [?]         
 *  size        [IN]        
 *  width       [?]         
 *  height      [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_get_dimension_internal(U8 *png_src, U32 size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GDI_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_draw_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ox                  [IN]        
 *  oy                  [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 *  src                 [?]         
 *  size                [IN]        
 *  is_file             [IN]        
 *  is_blocking         [IN]        
 *  callback            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_draw_internal(
            S32 ox,
            S32 oy,
            S32 resized_width,
            S32 resized_height,
            U8 *src,
            U32 size,
            BOOL is_file,
            BOOL is_blocking,
            void (*callback) (GDI_RESULT result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GDI_FAILED;
}

#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_draw_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  frame_pos       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_png_draw_internal(
            x,
            y,
            w,
            h,
            data_ptr,
            img_size,
            TOBOOL(flag & GDI_IMAGE_CODEC_FLAG_IS_FILE),
            TRUE,
            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_png_get_dimension_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag            [IN]        
 *  data_ptr        [?]         
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_png_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        return gdi_image_png_get_dimension_file((S8*) data_ptr, width, height);
    }
    else
    {
        return gdi_image_png_get_dimension(data_ptr, img_size, width, height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_png_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
BOOL gdi_image_is_png_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    U8 buf[8];
    U32 len;
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = gdi_lfs_open(gdi_lfs_handle,(U16*) file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);
    if (f < 0) return FALSE;
    f = gdi_lfs_handle;

    result = gdi_lfs_read(f, buf, 8, &len);

    gdi_lfs_close(f);

    if (result == FS_NO_ERROR)
        if (len == 8)
            if (memcmp(buf, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)
            {
                return TRUE;
            }
    return FALSE;
}

