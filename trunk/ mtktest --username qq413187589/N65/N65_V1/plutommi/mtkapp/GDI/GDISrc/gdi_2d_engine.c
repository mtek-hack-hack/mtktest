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
 *  gdi_mutex.c
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
#include "gdi_internal.h"
#include "2d_engine.h"

#define GDI_MAX_TILT_TABLE_SIZE 31

#if defined(GDI_USING_2D_ENGINE)


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_engine_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_engine_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g2d_init();
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_fill_rectangle(int x1, int y1, int x2, int y2, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g2d_rectangle_fill_without_clip(
        (U32) GDI_LAYER.buf_ptr,
        GDI_LAYER.width,
        x1,
        y1,
        ((x2 - x1 + 1) << 16) | (y2 - y1 + 1),
        color);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_bitblt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                 [?]         
 *  src_pitch           [IN]        
 *  src_x               [IN]        
 *  src_y               [IN]        
 *  dest_x              [IN]        
 *  dest_y              [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  gdi_transform       [IN]        
 *  use_src_key         [IN]        
 *  src_key             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_bitblt(
        U8 *src,
        S32 src_pitch,
        S32 src_x,
        S32 src_y,
        S32 dest_x,
        S32 dest_y,
        S32 width,
        S32 height,
        U8 gdi_transform,
        BOOL use_src_key,
        gdi_color src_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_2d_bitblt)
    g2d_parameter_struct g2d;

    g2d.g2d_operation_mode = G2D_OPERATION_BITBLT;

    g2d.src_color_mode = G2D_DEST_16BPP_LUT_DISABLE;
    g2d.dest_color_mode = G2D_DEST_16BPP_LUT_DISABLE;

    g2d.bitblt_mode = gdi_transform;

    g2d.clip_mode = G2D_CLIP_ENABLE;
    g2d.clip_start_x = GDI_LAYER.clipx1;
    g2d.clip_start_y = GDI_LAYER.clipy1;
    g2d.clip_end_x = GDI_LAYER.clipx2;
    g2d.clip_end_y = GDI_LAYER.clipy2;

    g2d.src_width = g2d.dest_width = width;
    g2d.src_height = g2d.dest_height = height;

    g2d.src_x = src_x;
    g2d.src_y = src_y;
    g2d.src_pitch = src_pitch;
    g2d.src_base_address = (U32) src;

    g2d.dest_x = dest_x;
    g2d.dest_y = dest_y;
    g2d.dest_base_address = (U32) GDI_LAYER.buf_ptr;
    g2d.dest_pitch_width = GDI_LAYER.width;

    if (use_src_key)
    {
        g2d.src_key_mode = G2D_SRC_KEY_ENABLE;
        g2d.src_key_color = src_key;
    }
    else
    {
        g2d.src_key_mode = G2D_SRC_KEY_DISABLE;
    }

    g2d_accelerator(&g2d);
    GDI_EXIT_CRITICAL_SECTION(gdi_2d_bitblt)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_alpha_bitblt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src             [?]         
 *  src_pitch       [IN]        
 *  src_x           [IN]        
 *  src_y           [IN]        
 *  dest_x          [IN]        
 *  dest_y          [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  src_alpha       [IN]        
 *  dest_alpha      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_alpha_bitblt(
        U8 *src,
        S32 src_pitch,
        S32 src_x,
        S32 src_y,
        S32 dest_x,
        S32 dest_y,
        S32 width,
        S32 height,
        U16 src_alpha,
        U16 dest_alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_2d_alpha_bitblt)
    g2d_parameter_struct g2d;

    g2d.g2d_operation_mode = G2D_OPERATION_ALPHA_BLENDING;

    g2d.src_color_mode = G2D_DEST_16BPP_LUT_DISABLE;
    g2d.dest_color_mode = G2D_DEST_16BPP_LUT_DISABLE;

    g2d.clip_mode = G2D_CLIP_ENABLE;
    g2d.clip_start_x = GDI_LAYER.clipx1;
    g2d.clip_start_y = GDI_LAYER.clipy1;
    g2d.clip_end_x = GDI_LAYER.clipx2;
    g2d.clip_end_y = GDI_LAYER.clipy2;

    g2d.src_width = g2d.dest_width = width;
    g2d.src_height = g2d.dest_height = height;

    g2d.src_x = src_x;
    g2d.src_y = src_y;
    g2d.src_pitch = src_pitch;
    g2d.src_base_address = (U32) src;

    g2d.dest_x = dest_x;
    g2d.dest_y = dest_y;
    g2d.dest_base_address = (U32) GDI_LAYER.buf_ptr;
    g2d.dest_pitch_width = GDI_LAYER.width;

    g2d.src_alpha = src_alpha;
    g2d.dest_alpha = dest_alpha;

    g2d_accelerator(&g2d);
    GDI_EXIT_CRITICAL_SECTION(gdi_2d_alpha_bitblt)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  color           [IN]        
 *  is_dotted       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_line(S16 x1, S16 y1, S16 x2, S16 y2, gdi_color color, BOOL is_dotted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g2d_parameter_struct g2d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g2d.g2d_operation_mode = G2D_OPERATION_LINE_DRAWING;

    g2d.src_color_mode = G2D_DEST_16BPP_LUT_DISABLE;
    g2d.dest_color_mode = G2D_DEST_16BPP_LUT_DISABLE;

    g2d.clip_mode = G2D_CLIP_ENABLE;
    g2d.clip_start_x = GDI_LAYER.clipx1;
    g2d.clip_start_y = GDI_LAYER.clipy1;
    g2d.clip_end_x = GDI_LAYER.clipx2;
    g2d.clip_end_y = GDI_LAYER.clipy2;

    g2d.start_x = x1;
    g2d.start_y = y1;
    g2d.end_x = x2;
    g2d.end_y = y2;

    g2d.pat_fg_color = color;
    if (is_dotted)
    {
        g2d.dotted_mode = G2D_LINE_DOTTED_MODE;
    }
    else
    {
        g2d.dotted_mode = G2D_LINE_LINE_MODE;
    }

    g2d.dest_base_address = (U32) GDI_LAYER.buf_ptr;
    g2d.dest_pitch_width = GDI_LAYER.width;

    g2d_accelerator(&g2d);
}
#endif /* defined(GDI_USING_2D_ENGINE) */ 

#ifdef GDI_USING_2D_ENGINE_V2
g2d_parameter_struct gdi_2d_data;


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_engine_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_engine_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_2d_data.clip_mode = G2D_CLIP_ENABLE;
    g2d_init();
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_begin(void)
{
    GDI_LOCK;
    g2d_begin(G2D_OWNER_GDI, NULL);
    
    gdi_2d_set_layer_as_dest_buffer((gdi_handle) gdi_act_layer);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_end(void)
{
    g2d_end(G2D_OWNER_GDI);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_set_layer_as_dest_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_set_layer_as_dest_buffer(gdi_handle handle)
{

    gdi_layer_struct *layer = (gdi_layer_struct*) handle;

    gdi_2d_set_dest_buffer(
            (U8*) layer->buf_ptr,
            layer->width,   /* pitch */
            layer->width,
            layer->height,
            0,
            0,
            layer->clipx1,
            layer->clipy1,
            layer->clipx2,
            layer->clipy2,
            layer->vcf);

}

/*****************************************************************************
 * FUNCTION
 *  gdi_2d_set_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [?]         
 *  dest_ptr        [?]         
 *  dest_pitch      [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  cf              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_set_buffer(
        gdi_2d_buffer_struct *dest,
        U8 *dest_ptr,
        U32 dest_pitch,
        U32 width,
        U32 height,
        S32 x,
        S32 y,
        S32 clipx1,
        S32 clipy1,
        S32 clipx2,
        S32 clipy2,
        gdi_color_format cf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest->base_address = (U32) dest_ptr;
    dest->x = (S16) x;
    dest->y = (S16) y;
    dest->pitch = (U16) dest_pitch;
    dest->height = (U16) height;
    dest->width = (U16) width;

    GDI_CLIP_TWO_RECT(clipx1, clipy1, clipx2, clipy2, 0, 0, width - 1, height - 1, 0) dest->clip_x1 = clipx1;
    dest->clip_y1 = clipy1;
    dest->clip_x2 = clipx2;
    dest->clip_y2 = clipy2;

    switch (cf)
    {
        case GDI_COLOR_FORMAT_8:
            dest->color_mode = FIRE_SRC_COLOR_8BPP_LUT_DIS;
            break;
        case GDI_COLOR_FORMAT_16:
            dest->color_mode = FIRE_SRC_COLOR_16BPP_RGB565;
            break;
        case GDI_COLOR_FORMAT_24:
            dest->color_mode = FIRE_SRC_COLOR_24BPP_RGB888;
            break;
        case GDI_COLOR_FORMAT_32:
            dest->color_mode = FIRE_SRC_COLOR_32BPP_ARGB8888;
            break;
        default:
            EXT_ASSERT(0, cf, cf, cf);  /* unsupport color format */
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_set_dest_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_ptr        [?]         
 *  dest_pitch      [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  clipx1          [IN]        
 *  clipy1          [IN]        
 *  clipx2          [IN]        
 *  clipy2          [IN]        
 *  cf              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_set_dest_buffer(
        U8 *dest_ptr,
        U32 dest_pitch,
        U32 width,
        U32 height,
        S32 x,
        S32 y,
        S32 clipx1,
        S32 clipy1,
        S32 clipx2,
        S32 clipy2,
        gdi_color_format cf)
{

        g2d_buffer_struct dest;
        gdi_2d_set_buffer(
            (gdi_2d_buffer_struct*) & dest,
            dest_ptr,
            dest_pitch,
            width,
            height,
            x,
            y,
            clipx1,
            clipy1,
            clipx2,
            clipy2,
            cf);

        switch (cf)
        {
            case GDI_COLOR_FORMAT_8:
                dest.color_mode = FIRE_DEST_COLOR_8BPP_LUT_DIS;
                break;
            case GDI_COLOR_FORMAT_16:
                dest.color_mode = FIRE_DEST_COLOR_16BPP_RGB565;
                break;
            case GDI_COLOR_FORMAT_24:
                dest.color_mode = FIRE_DEST_COLOR_24BPP_RGB888;
                break;
            case GDI_COLOR_FORMAT_32:
                dest.color_mode = FIRE_DEST_COLOR_32BPP_ARGB8888;
                break;
            default:
                GDI_ASSERT(0);  /* unsupport color format */
        }

        gdi_2d_data.dest_base_address = dest.base_address;
        gdi_2d_data.clip_start_x = dest.clip_x1;
        gdi_2d_data.clip_start_y = dest.clip_y1;
        gdi_2d_data.clip_end_x = dest.clip_x2;
        gdi_2d_data.clip_end_y = dest.clip_y2;
        gdi_2d_data.dest_color_mode = dest.color_mode;

        g2d_set_dest_buffer(G2D_OWNER_GDI, &dest);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_fill_triangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 *  x3          [IN]        
 *  y3          [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_fill_triangle(S32 x1, S32 y1, S32 x2, S32 y2, S32 x3, S32 y3, gdi_color color)
{
        S16 point[6];

        point[0] = x1;
        point[1] = y1;
        point[2] = x2;
        point[3] = y2;
        point[4] = x3;
        point[5] = y3;

        gdi_2d_fill_polygon(point, 6, color);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_fill_polygon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point           [?]         
 *  point_sum       [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_fill_polygon(S16 point[], U16 point_sum, gdi_color color)
{

        g2d_polygon_fill_struct data;

        data.point_number = point_sum;
        data.point_coordinate = point;
        data.fill_color = color;
        g2d_fill_polygon(G2D_OWNER_GDI, &data);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_set_font_attr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_tilt             [IN]        
 *  is_bold             [IN]        
 *  is_border           [IN]        
 *  enable_bg_color     [IN]        
 *  fg_color            [IN]        
 *  bg_color            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_set_font_attr(
        BOOL is_tilt,
        BOOL is_bold,
        BOOL is_border,
        BOOL enable_bg_color,
        gdi_color fg_color,
        gdi_color bg_color)
{

        g2d_font_attribute_struct attr;

        /* W05.50 Fix is_tilt does not work because is_tilt is not equal to KAL_TRUE */
        attr.tilt_mode = is_tilt ? KAL_TRUE : KAL_FALSE;
        attr.bold_mode = is_bold;
        attr.border_mode = is_border;
        attr.enable_bg_color = enable_bg_color;
        /* W05.50 Temp Solution for the system won't draw font if bg_color is equal to fg_color */
        if ((!enable_bg_color) && (!is_border))
        {
            bg_color = ~fg_color;
        }
        attr.fg_color = fg_color;
        attr.bg_color = bg_color;
        g2d_font_set_attribute(G2D_OWNER_GDI, &attr);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_draw_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  font_addr       [?]         
 *  bit_offset      [IN]        
 *  font_width      [IN]        
 *  font_height     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_draw_font(S32 x, S32 y, U8 *font_addr, U32 bit_offset, U32 font_width, U32 font_height)
{
        g2d_font_struct data;

        data.font_address = (U32) font_addr;
        data.bit_offset = bit_offset;
        data.font_width = (U16) font_width;
        data.font_height = (U16) font_height;
        data.start_x = (S16) x;
        data.start_y = (S16) y;
        g2d_draw_font(G2D_OWNER_GDI, &data);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_draw_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  color               [IN]        
 *  is_antialias        [IN]        
 *  is_dotted           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_draw_line(S32 x1, S32 y1, S32 x2, S32 y2, gdi_color color, BOOL is_antialias, BOOL is_dotted)
{
        g2d_line_struct data;
        S16 pos[4];

        pos[0] = x1;
        pos[1] = y1;
        pos[2] = x2;
        pos[3] = y2;

        data.line_count = 1;
        data.line_end_coordinate = pos;
        data.line_color = color;
        data.antialias_mode = is_antialias;
        data.dotted_mode = is_dotted;

        g2d_draw_line(G2D_OWNER_GDI, &data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_draw_polygon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point               [?]         
 *  point_sum           [IN]        
 *  color               [IN]        
 *  is_antialias        [IN]        
 *  is_dotted           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_draw_polygon(S16 point[], U16 point_sum, gdi_color color, BOOL is_antialias, BOOL is_dotted)
{
        g2d_polygon_struct data;

        data.polygon_number = point_sum;
        data.point_coordinate = point;
        data.line_color = color;
        data.antialias_mode = is_antialias;
        data.dotted_mode = is_dotted;

        g2d_draw_polygon(G2D_OWNER_GDI, &data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_fill_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_fill_rect(S32 x, S32 y, S32 width, S32 height, gdi_color color)
{
        g2d_rectangle_fill_struct data;

        data.start_x = x;
        data.start_y = y;
        data.width = width;
        data.height = height;
        data.fill_color = color;
        data.gradient_fill_mode = FALSE;
        g2d_fill_rectangle(G2D_OWNER_GDI, &data);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_fill_gradient_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  color               [IN]        
 *  is_tilt             [IN]        
 *  is_gradient         [IN]        
 *  delta_gradient      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_fill_gradient_rect(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        gdi_color color,
        BOOL is_tilt,
        BOOL is_gradient,
        U32 delta_gradient[8])
{
        g2d_rectangle_fill_struct data;

        data.start_x = x;
        data.start_y = y;
        data.width = width;
        data.height = height;
        data.fill_color = color;
        data.gradient_fill_mode = is_gradient;
        memcpy(data.delta_gradient, delta_gradient, sizeof(U32) * 8);
        data.tilt_mode = is_tilt;
        g2d_fill_rectangle(G2D_OWNER_GDI, &data);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_draw_arc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  radius          [IN]        
 *  color           [IN]        
 *  start_angle     [IN]        
 *  end_angle       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_draw_arc(S32 x, S32 y, S32 radius, gdi_color color, U32 start_angle, U32 end_angle)
{
        g2d_circle_struct data;

        data.circle_center_x = (S16) x;
        data.circle_center_y = (S16) y;
        data.circle_radius = (U16) radius;
        data.start_angle = (U16) start_angle;
        data.end_angle = (U16) end_angle;
        data.circle_color = color;

        g2d_draw_arc(G2D_OWNER_GDI, &data);

}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_bitblt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_tilt                 [IN]        
 *  enable_src_key          [IN]        
 *  src_key                 [IN]        
 *  is_alpha_blending       [IN]        
 *  alpha_value             [IN]        
 *  is_rop_mode             [IN]        
 *  rop_value               [IN]        
 *  transform_value         [IN]        
 *  src_list                [?]         
 *  list_count              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_bitblt(
        BOOL is_tilt,
        BOOL enable_src_key,
        gdi_color src_key,
        BOOL is_alpha_blending,
        U8 alpha_value,
        BOOL is_rop_mode,
        U8 rop_value,
        U8 transform_value,
        U8 transform_direction,
        gdi_2d_buffer_struct *src_list,
        kal_uint16 list_count)
{
        g2d_bitblt_struct data;

        data.tilt_mode = is_tilt;
        data.src_key_mode = enable_src_key;
        data.src_key_color = src_key;
        data.alpha_blending_mode = is_alpha_blending;
        data.alpha_value = alpha_value;
        data.rop_mode = is_rop_mode;
        data.rop_value = rop_value;
        data.transform_value = transform_value;
        data.src_list = (g2d_buffer_struct*) src_list;
        data.list_count = list_count;
        if (transform_value == GDI_TRANSFORM_NONE)
            data.blt_direction = transform_direction;
        else
            data.blt_direction = GDI_TRANSFORM_DIRECTION_LT;
        g2d_bitblt1(G2D_OWNER_GDI, &data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_draw_curve
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1          [IN]        
 *  y1          [IN]        
 *  x2          [IN]        
 *  y2          [IN]        
 *  x3          [IN]        
 *  y3          [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_draw_curve(S32 x1, S32 y1, S32 x2, S32 y2, S32 x3, S32 y3, gdi_color color)
{
        g2d_bezier_curve_struct data;

        data.start_x = x1;
        data.start_y = y1;
        data.middle_x = x2;
        data.middle_y = y2;
        data.end_x = x3;
        data.end_y = y3;
        g2d_draw_bezier_curve(G2D_OWNER_GDI, &data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_draw_gradient_h_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos                 [?]         
 *  line_width          [?]         
 *  line_number         [IN]        
 *  delta_gradient      [?]         
 *  line_color          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_draw_gradient_h_line(
        S16 pos[],
        /* line_number x 2 */ U16 line_width[],
        /* line_number */ U16 line_number,
        S32 delta_gradient[],
        /* line_number x 4 */ gdi_color line_color)
{
        g2d_gradient_line_struct data;

        data.line_start_coordinate = pos;
        data.line_width = line_width;
        data.line_number = line_number;
        data.delta_gardient = delta_gradient;
        data.line_color = line_color;

        g2d_draw_gradient_h_line(G2D_OWNER_GDI, &data);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_2d_copy_h_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                 [?]         
 *  mask_address        [?]         
 *  mask_length         [IN]        
 *  pos                 [?]         
 *  line_width          [?]         
 *  line_number         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_copy_h_line(
        gdi_2d_buffer_struct *src,
        U32 *mask_address,
        U32 mask_length,
        S16 pos[],
        /* line_number x2 */ U16 line_width[],
        /* line_number */ U16 line_number)
{
        g2d_line_copy_struct data;

        data.src = (g2d_buffer_struct*) src;
        data.mask_address = mask_address;
        data.mask_length = mask_length;
        data.line_start_coordinate = pos;
        data.line_width = line_width;
        data.line_number = line_number;

        g2d_copy_h_line(G2D_OWNER_GDI, &data);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_2d_set_tilt_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tilt_table      [IN]        
 *  table_size      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_2d_set_tilt_table(const U32 *tilt_table, U32 table_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* W06.04 Temp Solution for Italic Font */
    U8 i = 0;
    U8 maxsize = table_size > GDI_MAX_TILT_TABLE_SIZE ? GDI_MAX_TILT_TABLE_SIZE : table_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < maxsize; i++)
    {
        g2d_set_tilt_data((U8) i, (U8) tilt_table[maxsize - i - 1]);
    }
}
#endif /* GDI_USING_2D_ENGINE_V2 */ 

