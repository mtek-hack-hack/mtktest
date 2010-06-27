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
 *  gui_scrollbars_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Scrollbars - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "gui_scrollbars_post_oem.h"
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "DebugInitDef.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"


#if defined(UI_SCROLLBAR_STYLE_5)
static S32 g_mmi_gui_scrollbar_width = 0;

/* Height of up/down button, or width of left/right button */
static S32 g_mmi_gui_scrollbar_button_size;

/* The scrollbar background is composed by three different images. */
static S32 g_mmi_gui_scrollbar_bar_size1;
static S32 g_mmi_gui_scrollbar_bar_size2;
static S32 g_mmi_gui_scrollbar_bar_size3;
static S32 g_mmi_gui_scrollbar_bar_size4;
/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_image_size
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_image_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_gui_scrollbar_width)
    {
        S32 iw, ih;
        
        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP), &iw, &ih);
        g_mmi_gui_scrollbar_width = iw;
        g_mmi_gui_scrollbar_button_size = ih;
        
        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size1 = ih;
        
        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size2 = ih;
        
        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size3 = ih;

    gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size4 = ih;
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_get_button_min_size
* DESCRIPTION
*  
* PARAMETERS
*  type            [IN]        
*  bar_width       [IN]        
* RETURNS
*  
*****************************************************************************/
S32 gui_scrollbar_get_button_min_size(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size();
    
    MMI_DBG_ASSERT(g_mmi_gui_scrollbar_width == bar_width);
    
    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON;
        break;
        
    case GUI_SCROLLBAR_BUTTON_UP:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_DOWN:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_LEFT:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        ret = g_mmi_gui_scrollbar_button_size + 2 /* 1 + 1 pixel spacing */ ;
        break;
        
    default:
        MMI_ASSERT(0);
    }
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_region
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
*  x           [IN]        
*  y           [IN]        
*  width       [IN]        
*  height      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_region(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remain;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);      
    }
    
    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {
        remain = height;
        while (remain > 0)
        {
            gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BGD), UI_DEFAULT_TRANSPARENT_COLOR);
            y += g_mmi_gui_scrollbar_bar_size4;
            remain -= g_mmi_gui_scrollbar_bar_size4;
        }
    }
    else
    {
        remain = width;
        while (remain > 0)
        {
            gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_BGD), UI_DEFAULT_TRANSPARENT_COLOR);
            x += g_mmi_gui_scrollbar_bar_size4;
            remain -= g_mmi_gui_scrollbar_bar_size4;
        }
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
*  b           [IN/OUT]         
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 x, y, width, height;
    BOOL is_button_pressed = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size();
    
    c = b->normal_up_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    
    if (width == 0 || height == 0)
    {
        return;
    }
    
    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }
    
    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }
    
    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2;
            
            
            x2 = x + width - 1;
            y2 = y + height - 1;
            if (height <= g_mmi_gui_scrollbar_bar_size1 + g_mmi_gui_scrollbar_bar_size3)
            {
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + width - 1, y + (height >> 1) - 1);
                }
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y + (height >> 1), x + width - 1, y + height - 1);
                }
                gui_show_transparent_image(x, y + height - g_mmi_gui_scrollbar_bar_size3, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), UI_DEFAULT_TRANSPARENT_COLOR);
            }
            else
            {
                S32 y1, y2, remain;
                
                y1 = y + g_mmi_gui_scrollbar_bar_size1;
                y2 = y + height - g_mmi_gui_scrollbar_bar_size3 - 1;
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), UI_DEFAULT_TRANSPARENT_COLOR);
                gui_show_transparent_image(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y1, x + width - 1, y2);
                }
                remain = y2 - y1 + 1;
                while (remain > 0)
                {
                    gui_show_transparent_image(x, y1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), UI_DEFAULT_TRANSPARENT_COLOR);
                    y1 += g_mmi_gui_scrollbar_bar_size2;
                    remain -= g_mmi_gui_scrollbar_bar_size2;
                }
            }
            
            break;
        }
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 x2, y2;
            
            
            x2 = x + width - 1;
            y2 = y + height - 1;
            if (width <= g_mmi_gui_scrollbar_bar_size1 + g_mmi_gui_scrollbar_bar_size3)
            {
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x, y, x + (width >> 1) - 1, y + height - 1);
                }
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x + (width >> 1), y, x + width - 1, y + height - 1);
                }
                gui_show_transparent_image(x + width - g_mmi_gui_scrollbar_bar_size3, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT), UI_DEFAULT_TRANSPARENT_COLOR);
            }
            else
            {
                S32 x1, x2, remain;
                
                x1 = x + g_mmi_gui_scrollbar_bar_size1;
                x2 = x + width - g_mmi_gui_scrollbar_bar_size3 - 1;
                gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT), UI_DEFAULT_TRANSPARENT_COLOR);
                gui_show_transparent_image(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT), UI_DEFAULT_TRANSPARENT_COLOR);
                if (gui_scrollbar_redraw_clip_enable)
                {
                    gui_set_clip(x1, y, x2, y + height - 1);
                }
                remain = x2 - x1 + 1;
                while (remain > 0)
                {
                    gui_show_transparent_image(x1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_MIDDLE), UI_DEFAULT_TRANSPARENT_COLOR);
                    x1 += g_mmi_gui_scrollbar_bar_size2;
                    remain -= g_mmi_gui_scrollbar_bar_size2;
                }
            }
            
            break;
        }
    
        
        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            {
                if (type == GUI_SCROLLBAR_BUTTON_UP)
                {
                    if (is_button_pressed)
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP_PRESSED), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                    else
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                    
                }
                else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
                {
                    if (is_button_pressed)
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_DOWN_PRESSED), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                    else
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_DOWN), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                }
                else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
                {
                    if (is_button_pressed)
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_LEFT_PRESSED), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                    else
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_LEFT), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                }
                else
                {
                    if (is_button_pressed)
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_RIGHT_PRESSED), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                    else
                    {
                        gui_show_transparent_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_RIGHT), UI_DEFAULT_TRANSPARENT_COLOR);
                    }
                }
                
                break;
        }
        
        default:
            MMI_DBG_ASSERT(0);
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
    
}

#elif defined(UI_SCROLLBAR_STYLE_4) 

/* Use image to draw the scrollbar. */

/* color of the moveable part (scroll button) */
static S32 g_mmi_gui_scrollbar_cache_hue = -1;
static S32 g_mmi_gui_scrollbar_cache_num_gcolor = 0;

static color g_mmi_gui_scrollbar_gradient[GUI_SCROLLBAR_NUM_GRADIENT_COLOR];

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
static color g_mmi_gui_scrollbar_bk_color;
static color g_mmi_gui_scrollbar_border_color;
#endif

/*
* RGB <-> HLS color space conversion with cache to avoid floating point arithmetics
*/


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_RGB_to_HLS
* DESCRIPTION
*  
* PARAMETERS
*  rgb     [IN]        
*  hls     [OUT]         
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_RGB_to_HLS(color rgb, UI_HLS_color *hls)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static color cached_rgb = {0, 0, 0, 0};
    static UI_HLS_color cached_hls = {0, 0, 0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(&rgb, &cached_rgb, sizeof(color)) != 0)
    {
        cached_rgb = rgb;
        gui_RGB_to_HLS(rgb, &cached_hls);
    }
    *hls = cached_hls;
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_precache_color1
* DESCRIPTION
*  Pre-cache color because the HLS colorspace conversion is slow
* PARAMETERS
*  theme_color     [IN]        Is the domination color the scrollbar
*  width           [IN]        Scrollbar width
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_precache_color1(color theme_color, S32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    S32 i;
    S32 num_gradient_color = width - 4; /* two-pixel border each side */
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    S32 transparent_color_r, transparent_color_g, transparent_color_b, r, g, b;
    S32 opacity_value = ((U32)GUI_SCROLLBAR_ALPHA) * 255 / 100;
    S32 inverse_opacity_value = 256 - ((U32)GUI_SCROLLBAR_ALPHA) * 255 / 100;;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_gradient_color > GUI_SCROLLBAR_NUM_GRADIENT_COLOR)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_GRADIENT_COLOR;
    }
    if (num_gradient_color <= 1)
    {
        num_gradient_color = 2;
    }
    
    gui_scrollbar_RGB_to_HLS(theme_color, &hls);
    
    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_cache_hue || num_gradient_color != g_mmi_gui_scrollbar_cache_num_gcolor)
    {
        g_mmi_gui_scrollbar_cache_num_gcolor = num_gradient_color;
        g_mmi_gui_scrollbar_cache_hue = hls.h;
        
        for (i = 0; i < num_gradient_color; i++)
        {
            S32 l, s;
            
            s = i * (GUI_SCROLLBAR_MAX_GRADIENT_SATURATION -
                GUI_SCROLLBAR_MIN_GRADIENT_SATURATION) / (num_gradient_color - 1);
            s = GUI_SCROLLBAR_MAX_GRADIENT_SATURATION - s;
            l = i * (GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS -
                GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS) / (num_gradient_color - 1);
            l = GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS - l;
            MMI_DBG_ASSERT(s >= 0 && s <= 255);
            MMI_DBG_ASSERT(l >= 0 && l <= 255);
            hls.s = (U8) s;
            hls.l = (U8) l;
            gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_gradient[i]);
        }
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
        
        g_mmi_gui_scrollbar_border_color = current_MMI_theme->scrollbar_background_filler->border_color;
        g_mmi_gui_scrollbar_bk_color = current_MMI_theme->scrollbar_background_filler->c;
        
        transparent_color_r = (current_MMI_theme->lite_disp_scr_bg_color->r >> 3) * opacity_value;
        transparent_color_g = (current_MMI_theme->lite_disp_scr_bg_color->g >> 2) * opacity_value;
        transparent_color_b = (current_MMI_theme->lite_disp_scr_bg_color->b >> 3) * opacity_value;
        r = g_mmi_gui_scrollbar_border_color.r >> 3;
        g = g_mmi_gui_scrollbar_border_color.g >> 2;
        b = g_mmi_gui_scrollbar_border_color.b >> 3;
        g_mmi_gui_scrollbar_border_color.r = ((transparent_color_r) +  (r * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_border_color.g = ((transparent_color_g) +  (g * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_border_color.b = ((transparent_color_b) +  (b * inverse_opacity_value)) >> 8;
        
        r = g_mmi_gui_scrollbar_bk_color.r >> 3;
        g = g_mmi_gui_scrollbar_bk_color.g >> 2;
        b = g_mmi_gui_scrollbar_bk_color.b >> 3;
        g_mmi_gui_scrollbar_bk_color.r = ((transparent_color_r) +  (r * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_bk_color.g = ((transparent_color_g) +  (g * inverse_opacity_value)) >> 8;
        g_mmi_gui_scrollbar_bk_color.b = ((transparent_color_b) +  (b * inverse_opacity_value)) >> 8;
#endif
    }
    
    
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_region
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
*  x           [IN]        
*  y           [IN]        
*  width       [IN]        
*  height      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_region(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_src_layer, scr_layer, act_layer;
    color color, border_color, white_color = {255, 255, 255, 100};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }
    
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    
    gdi_layer_get_active(&act_layer);
    
    old_src_layer = gui_get_transparent_source_layer();        
    gdi_image_abm_get_source_layer(&scr_layer);
    
    if (scr_layer == GDI_ERROR_HANDLE ||  scr_layer == GDI_NULL_HANDLE)            
    {
        scr_layer = act_layer;
    }

    gui_set_transparent_source_layer(scr_layer);

    /* sometimes gdi_image_abm_set_source_layer(base_layer) by application on purpose */
    if (scr_layer == act_layer)
    {
        gui_fill_rectangle(x, y, x + width - 1, y + height - 1, white_color);
        /* For white background in WAP and other !DM_SCR_BG screens */
    }

    border_color = current_MMI_theme->scrollbar_background_filler->border_color;
    color = current_MMI_theme->scrollbar_background_filler->c;
    border_color.alpha = GUI_SCROLLBAR_ALPHA;
    color.alpha = GUI_SCROLLBAR_ALPHA;
    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
    gui_fill_transparent_color(x, y, x + width - 1, y, border_color);
    gui_fill_transparent_color(x, y + height - 1, x + width, y + height - 1, border_color);
    gui_fill_transparent_color(x, y, x, y + height - 1, border_color);
    gui_fill_transparent_color(x + width - 1, y, x + width - 1, y + height, border_color);
    if(y != b->y)
    {
        gui_fill_transparent_color(
            x + 1, 
            y + 1 , 
            x + width - 2, 
            b->y, 
            color);
    }    
    if (y + height != b->y + b->height)
    {
        gui_fill_transparent_color(
            x + 1, 
            b->y + b->height - 1 , 
            x + width - 2, 
            y + height - 2, 
            color);
    }

#elif defined(__MMI_TOUCH_SCREEN__) 
    gui_fill_transparent_color(x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y, x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y, border_color);
    gui_fill_transparent_color(x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y + height - 1, x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y + height - 1, border_color);
    gui_fill_transparent_color(x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y, x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y + height - 1, border_color);
    gui_fill_transparent_color(x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y, x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, y + height, border_color);
    if(y != b->y)
    {
        gui_fill_transparent_color(
            x + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, 
            y + 1 , 
            x + width - 1 - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, 
            b->y, 
            color);
    }    
    if (y + height != b->y + b->height)
    {
        gui_fill_transparent_color(
            x + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, 
            b->y + b->height - 1 , 
            x + width - 1 - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, 
            y + height - 2, 
            color);
    }
    
#else
    gui_fill_transparent_color(x, y, x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, y , border_color);
    gui_fill_transparent_color(x, y + height - 1, x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP , y + height - 1, border_color);
    gui_fill_transparent_color(x, y, x , y + height - 1 , border_color);
    gui_fill_transparent_color(x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, y, x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, y + height - 1 , border_color);
    if(y != b->y)
    {
        gui_fill_transparent_color(
            x + 1, 
            y + 1 , 
            x + width - 1 - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, 
            b->y, 
            color);
    }    
    if (y + height != b->y + b->height)
    {
        gui_fill_transparent_color(
            x + 1, 
            b->y + b->height - 1 , 
            x + width - 1 - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, 
            y + height - 2, 
            color);
    }
#endif
    }
    else    
    {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
        gui_fill_transparent_color(x, y, x + width - 1, y, border_color);
        gui_fill_transparent_color(x, y + height - 1, x + width - 1, y + height - 1, border_color);
        gui_fill_transparent_color(x, y, x, y + height, border_color);
        gui_fill_transparent_color(x + width - 1, y, x + width - 1, y + height - 1, border_color);
        if(x != b->x)
        {
            gui_fill_transparent_color(
                x + 1, 
                y + 1, 
                b->x, 
                y + height - 2, 
                color);
        }    
        if (x + width != b->x + b->width)
        {
            gui_fill_transparent_color(
                b->x + b->width - 1, 
                y + 1, 
                x + width - 2, 
                y + height - 2, 
                color);
        }
#elif defined(__MMI_TOUCH_SCREEN__) 
        gui_fill_transparent_color(x, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, x + width - 1, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, border_color);
        gui_fill_transparent_color(x, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, x + width - 1, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, border_color);
        gui_fill_transparent_color(x, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, x, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, border_color);
        gui_fill_transparent_color(x + width - 1, y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, x + width - 1, y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP, border_color);
        if(x != b->x)
        {
            gui_fill_transparent_color(
                x + 1, 
                y + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, 
                b->x, 
                y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP - 1, 
                color);
        }    
        if (x + width != b->x + b->width)
        {
            gui_fill_transparent_color(
                b->x + b->width - 1, 
                y + 1 + GUI_SCROLLBAR_STYLE4_TOUCH_GAP, 
                x + width - 2, 
                y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP - 1, 
                color);
        }
#else
        gui_fill_transparent_color(x, y, x + width - 1, y, border_color);
        gui_fill_transparent_color(x, y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, x + width - 1 , y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP, border_color);
        gui_fill_transparent_color(x, y , x , y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP , border_color);
        gui_fill_transparent_color(x + width - 1, y, x + width - 1, y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP , border_color);
        if(x != b->x)
        {
            gui_fill_transparent_color(
                x + 1, 
                y + 1, 
                b->x, 
                y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP - 1, 
                color);
        }    
        if (x + width != b->x + b->width)
        {
            gui_fill_transparent_color(
                b->x + b->width - 1, 
                y + 1, 
                x + width - 2, 
                y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP - 1, 
                color);
        }
#endif
    }
    gui_set_transparent_source_layer(old_src_layer);
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
    
    gui_draw_rectangle(x, y, x + width - 1, y + height - 1, g_mmi_gui_scrollbar_border_color);
    
    gui_fill_rectangle(x + 1, y + 1, x + width - 2, y + height - 2, g_mmi_gui_scrollbar_bk_color);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_adjust_luminance
* DESCRIPTION
*  
* PARAMETERS
*  luminance       [IN/OUT]         
*  diff            [IN]        
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_adjust_luminance(U8 *luminance, S16 diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 l = *luminance;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l += diff;
    if (l > 255)
    {
        l = 255;
    }
    if (l < 0)
    {
        l = 0;
    }
    *luminance = (U8) l;
}

/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button_style2
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
*  b           [IN/OUT]         
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button_style2(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    color c;
    S32 x, y, width, height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    c = b->normal_up_filler->c;
    
    /* Scroll button does not support highlight in UI_SCROLLBAR_STYLE_2 */
    if (type != GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && type != GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
    {
        if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
        {
            y++;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
        else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
        {
            y += 2;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }
    
    /* shift the position to leave one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }
    
    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 i;
            S32 num_shadow_line;
            color cs[3];    /* shadow color */
            color cf;       /* fill color */
            
            gui_RGB_to_HLS(c, &hls);
            
            if (height < 5 || width < 5)
            {
                /* No room to display the bar in special style */
                gui_show_icon_button(b);
            }
            else
            {
                if ((type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && width >= 9) ||
                    (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && height >= 9))
                {
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[2]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 3;
                }
                else
                {
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance(&hls.l, 20);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 2;
                }
                
                if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL)
                {
                    S32 x2, y2;
                    
                    if (!(width % 2))
                    {
                        width--;
                    }
                    if (height >= 8)
                    {
                        /* Leave 1-pixel space */
                        y++;
                        height -= 2;
                    }
                    
                    x2 = x + width - 1;
                    y2 = y + height - 1;
                    
                    if (width <= 5)
                    {
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }
                        
                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);
                        
                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }
                        
                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }
                        
                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
                else
                {
                    S32 x2, y2;
                    
                    if (!(height % 2))
                    {
                        height--;
                    }
                    if (width >= 8)
                    {
                        /* Leave 1-pixel space */
                        x++;
                        width -= 2;
                    }
                    
                    x2 = x + width - 1;
                    y2 = y + height - 1;
                    
                    if (width <= 5)
                    {
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }
                        
                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);
                        
                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }
                        
                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }
                        
                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
            }
        }
        break;
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();    
    }
}


/*****************************************************************************
* FUNCTION
*  gui_scrollbar_draw_button
* DESCRIPTION
*  
* PARAMETERS
*  type        [IN]        
*  b           [IN/OUT]         
* RETURNS
*  void
*****************************************************************************/
static void gui_scrollbar_draw_button(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c, border_color, color;
    S32 x, y, width, height;
    BOOL is_button_pressed = MMI_FALSE;
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
    gdi_handle old_src_layer, scr_layer, act_layer;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = current_MMI_theme->scrollbar_indicator_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    
    if (width == 0 || height == 0)
    {
        return;
    }
    
    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }
    
    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }
    
    switch (type)
    {
    case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        /* FALLTHROUGH no break */
    case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2;
            
            gui_scrollbar_precache_color1(c, width);
            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                /* 1 pixel spacing in the top and bottom side */
                x2 = x + width - GUI_SCROLLBAR_STYLE4_GAP;
            
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                y2 = y + height - 1;
#elif defined(__MMI_TOUCH_SCREEN__)
                y = y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2;
#else
                y = y;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP ;          
#endif
                x++;
                height--;
            }
            else
            {
                /* 1 pixel spacing in the left and right side */                
            y2 = y + height - GUI_SCROLLBAR_STYLE4_GAP;
            
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
            x2 = x + width - 1;
#elif defined(__MMI_TOUCH_SCREEN__)
            x = x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP;
            x2 = x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2;
#else
            x = x;
            x2 = x + width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP;          
#endif
                width--;
                x++;
            }
            
            gui_fill_rectangle(x, y + 1, x2 - 1, y2 - 1, c);
            gui_draw_horizontal_line(x + 2, x2 -3, y2 - 3 , g_mmi_gui_scrollbar_gradient[0]);
            gui_draw_vertical_line(y + 3, y2 - 3, x2 - 3, g_mmi_gui_scrollbar_gradient[0]);
            gui_draw_horizontal_line(x + 1, x2 -2, y2 - 2 , g_mmi_gui_scrollbar_gradient[1]);
            gui_draw_vertical_line(y + 2, y2 - 2, x2 - 2, g_mmi_gui_scrollbar_gradient[1]);    
            gui_draw_horizontal_line(x, x2 - 1, y2 - 1 , g_mmi_gui_scrollbar_gradient[2]);
            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1, g_mmi_gui_scrollbar_gradient[2]);
            
            break;
        }
        
    case GUI_SCROLLBAR_BUTTON_UP:
    case GUI_SCROLLBAR_BUTTON_LEFT:
    case GUI_SCROLLBAR_BUTTON_DOWN:
    case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
            S32 x2 = 0, y2 = 0;
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)

            gdi_layer_get_active(&act_layer);
            
            old_src_layer = gui_get_transparent_source_layer();
            gdi_image_abm_get_source_layer(&scr_layer);
            
            if (scr_layer == GDI_ERROR_HANDLE ||  scr_layer == GDI_NULL_HANDLE)            
            {
                scr_layer = act_layer;
            }
            
                gui_set_transparent_source_layer(scr_layer);
#endif
            
            if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
            {                
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                y2 = y + height - 1;                
#else
                y = y + GUI_SCROLLBAR_STYLE4_TOUCH_GAP;
                y2 = y + height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2;
#endif

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
                border_color = current_MMI_theme->scrollbar_background_filler->border_color;
                color = current_MMI_theme->scrollbar_background_filler->c;
                border_color.alpha = GUI_SCROLLBAR_ALPHA;
                color.alpha = GUI_SCROLLBAR_ALPHA;
                gui_fill_transparent_color(x, y, x, y2, border_color);
                gui_fill_transparent_color(x + y2 - y, y, x + y2 - y, y2, border_color);
                gui_fill_transparent_color(x, y, x + y2 - y, y, border_color);
                gui_fill_transparent_color(x, y2, x + y2 - y, y2, border_color);
                gui_fill_transparent_color(x + 1, y + 1, x + y2 - y - 1, y2 - 1, color);
                gui_set_transparent_source_layer(old_src_layer);
                
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */    
                gui_draw_rectangle(x, y, x + width - 1, y + height - 1, g_mmi_gui_scrollbar_border_color);
                
                gui_fill_rectangle(x + 1, y + 1, x + width - 2, y + height - 2, g_mmi_gui_scrollbar_bk_color);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
            }
            if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
#if defined(__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_128X160__)
                x2 = x + width - 1;                
#else
            x = x + GUI_SCROLLBAR_STYLE4_TOUCH_GAP;
            x2 = x + width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2;
#endif
            
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
            border_color = current_MMI_theme->scrollbar_background_filler->border_color;
            color = current_MMI_theme->scrollbar_background_filler->c;
            border_color.alpha = GUI_SCROLLBAR_ALPHA;
            color.alpha = GUI_SCROLLBAR_ALPHA;
            gui_fill_transparent_color(x, y, x, y + x2- x, border_color);
            gui_fill_transparent_color(x2, y, x2, y + x2- x, border_color);
            gui_fill_transparent_color(x, y, x2, y, border_color);
            gui_fill_transparent_color(x, y + x2- x, x2, y + x2- x, border_color);
            gui_fill_transparent_color(x + 1, y + 1, x2 - 1, y + x2- x - 1, color);
            gui_set_transparent_source_layer(old_src_layer);
            
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */    
            gui_draw_rectangle(x, y, x + width - 1, y + height - 1, g_mmi_gui_scrollbar_border_color);
            
            gui_fill_rectangle(x + 1, y + 1, x + width - 2, y + height - 2, g_mmi_gui_scrollbar_bk_color);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
            }

            
            if (is_button_pressed)
            {
                y++;
            }
            
            if (type == GUI_SCROLLBAR_BUTTON_UP)
            {
                S32 arrow_width = x2 - x + 1 - (GUI_SCROLLBAR_STYLE4_GAP << 1);
                S32 arrow_height;
                S32 x1, y1, i;
                
                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;
                
                x1 = (x2 - x + 1 - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + 1;
                
                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + arrow_height - 1 - 2; /* -1 for center */
                
                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 + 2, c);
                    y1--;
                    x1++;
                }
                y1 += 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 + 2, c);
                    y1++;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
                S32 arrow_width = x2 - x + 1 - (GUI_SCROLLBAR_STYLE4_GAP << 1);
                S32 arrow_height;
                S32 x1, y1, i;
                
                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;
                
                x1 = (x2 - x + 1 - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + 1;
                
                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;
                
                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 - 2, c);
                    y1++;
                    x1++;
                }
                y1 -= 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1, y1 - 2, c);
                    y1--;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP << 1);
                S32 arrow_width;
                S32 x1, y1, i;
                
                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;
                
                y1 = (y2 - y + 1 - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + 1;
                
                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + arrow_width - 3;  /* -1 for center */
                
                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1--;
                }
                x1 += 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1++;
                }
            }
            else
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP << 1);
                S32 arrow_width;
                S32 x1, y1, i;
                
                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;
                
                y1 = (y2 - y + 1 - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + 1;
                
                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x - 1;
                
                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1++;
                }
                x1 -= 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, c);
                    gui_putpixel(x1 + 2, y1, c);
                    y1++;
                    x1--;
                }
            }
            
            break;
        }
        
        default:
            MMI_DBG_ASSERT(0);
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
    
}

#elif defined(UI_SCROLLBAR_STYLE_3) 
/* Use image to draw the scrollbar. */

/* Width of scrollbar */
static S32 g_mmi_gui_scrollbar_width = 0;

/* Height of up/down button, or width of left/right button */
static S32 g_mmi_gui_scrollbar_button_size;

/* The scrollbar background is composed by three different images. */
static S32 g_mmi_gui_scrollbar_bar_size1;
static S32 g_mmi_gui_scrollbar_bar_size2;
static S32 g_mmi_gui_scrollbar_bar_size3;

/* color of the arrow */
static S32 g_mmi_gui_scrollbar_arrow_cache_hue = -1;
static color g_mmi_gui_scrollbar_arrow_color;

/* color of the moveable part (scroll button) */
static S32 g_mmi_gui_scrollbar_cache_hue = -1;
static S32 g_mmi_gui_scrollbar_cache_num_gcolor = 0;

static color g_mmi_gui_scrollbar_border_color;
static color g_mmi_gui_scrollbar_dark_color;
static color g_mmi_gui_scrollbar_medium_color;
static color g_mmi_gui_scrollbar_light_color;
static color g_mmi_gui_scrollbar_gradient[GUI_SCROLLBAR_NUM_GRADIENT_COLOR];

/*
 * RGB <-> HLS color space conversion with cache to avoid floating point arithmetics
 */


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_RGB_to_HLS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rgb     [IN]        
 *  hls     [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_RGB_to_HLS(color rgb, UI_HLS_color *hls)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static color cached_rgb = {0, 0, 0, 0};
    static UI_HLS_color cached_hls = {0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (memcmp(&rgb, &cached_rgb, sizeof(color)) != 0)
    {
        cached_rgb = rgb;
        gui_RGB_to_HLS(rgb, &cached_hls);
    }
    *hls = cached_hls;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_precache_image_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_precache_image_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_gui_scrollbar_width)
    {
        S32 iw, ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP), &iw, &ih);
        g_mmi_gui_scrollbar_width = iw;
        g_mmi_gui_scrollbar_button_size = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size1 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size2 = ih;

        gui_measure_image((PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM), &iw, &ih);
        g_mmi_gui_scrollbar_bar_size3 = ih;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_precache_color1
 * DESCRIPTION
 *  Pre-cache color because the HLS colorspace conversion is slow
 * PARAMETERS
 *  theme_color     [IN]        Is the domination color the scrollbar
 *  width           [IN]        Scrollbar width
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_precache_color1(color theme_color, S32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    S32 i;
    S32 num_gradient_color = width - 4; /* two-pixel border each side */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_gradient_color > GUI_SCROLLBAR_NUM_GRADIENT_COLOR)
    {
        num_gradient_color = GUI_SCROLLBAR_NUM_GRADIENT_COLOR;
    }
    if (num_gradient_color <= 1)
    {
        num_gradient_color = 2;
    }

    gui_scrollbar_RGB_to_HLS(theme_color, &hls);

    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_cache_hue || num_gradient_color != g_mmi_gui_scrollbar_cache_num_gcolor)
    {
        g_mmi_gui_scrollbar_cache_num_gcolor = num_gradient_color;
        g_mmi_gui_scrollbar_cache_hue = hls.h;

        hls.s = GUI_SCROLLBAR_BORDER_SATURATION;
        hls.l = GUI_SCROLLBAR_BORDER_LIGHTNESS;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_border_color);

        hls.s = GUI_SCROLLBAR_DARK_SATURATION;
        hls.l = GUI_SCROLLBAR_DARK_LIGHTNESS;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_dark_color);

        hls.s = GUI_SCROLLBAR_MEDIUM_SATURATION;
        hls.l = GUI_SCROLLBAR_MEDIUM_LIGHTNESS;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_medium_color);

        hls.s = GUI_SCROLLBAR_LIGHT_SATURATION;
        hls.l = GUI_SCROLLBAR_LIGHT_LIGHTNESS;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_light_color);

        for (i = 0; i < num_gradient_color; i++)
        {
            S32 s, l;

            s = i * (GUI_SCROLLBAR_MAX_GRADIENT_SATURATION -
                     GUI_SCROLLBAR_MIN_GRADIENT_SATURATION) / (num_gradient_color - 1);
            s = GUI_SCROLLBAR_MAX_GRADIENT_SATURATION - s;
            l = i * (GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS -
                     GUI_SCROLLBAR_MIN_GRADIENT_LIGHTNESS) / (num_gradient_color - 1);
            l = GUI_SCROLLBAR_MAX_GRADIENT_LIGHTNESS - l;
            MMI_DBG_ASSERT(s >= 0 && s <= 255);
            MMI_DBG_ASSERT(l >= 0 && l <= 255);
            hls.s = (U8) s;
            hls.l = (U8) l;
            gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_gradient[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_precache_color2
 * DESCRIPTION
 *  Pre-cache color because the HLS colorspace conversion is slow
 * PARAMETERS
 *  theme_color     [IN]        Is the domination color the scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_precache_color2(color theme_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_RGB_to_HLS(theme_color, &hls);

    /* Recompute colors only if color hue is changed */
    if ((S32) hls.h != g_mmi_gui_scrollbar_arrow_cache_hue)
    {
        g_mmi_gui_scrollbar_arrow_cache_hue = (S32) hls.h;

        hls.s = GUI_SCROLLBAR_ARROW_SATURATION;
        hls.l = GUI_SCROLLBAR_ARROW_LIGHTNESS;
        gui_HLS_to_RGB(hls, &g_mmi_gui_scrollbar_arrow_color);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_minimum_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_scrollbar_get_minimum_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 min;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size();
    min = g_mmi_gui_scrollbar_bar_size1 + g_mmi_gui_scrollbar_bar_size3;

    if (min < GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON)
    {
        min = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON;
    }

    return min + ((g_mmi_gui_scrollbar_button_size + 2 /* 1+ 1 pixel spacing */ ) << 1);
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_button_min_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  bar_width       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_scrollbar_get_button_min_size(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size();

    MMI_DBG_ASSERT(g_mmi_gui_scrollbar_width == bar_width);

    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
            ret = GUI_SCROLLBAR_MIN_HEIGHT_SCROLL_BUTTON;
            break;

        case GUI_SCROLLBAR_BUTTON_UP:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_DOWN:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_LEFT:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            ret = g_mmi_gui_scrollbar_button_size + 2 /* 1 + 1 pixel spacing */ ;
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_draw_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_draw_region(gui_scrollbar_region_enum type, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }

    if (type == GUI_SCROLLBAR_REGION_VERTICAL)
    {
        if (height <= g_mmi_gui_scrollbar_bar_size1 + g_mmi_gui_scrollbar_bar_size3)
        {
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + width - 1, y + (height >> 1) - 1);
            }
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y + (height >> 1), x + width - 1, y + height - 1);
            }
            gui_show_image(x, y + height - g_mmi_gui_scrollbar_bar_size3, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
        }
        else
        {
            S32 y1, y2, remain;

            y1 = y + g_mmi_gui_scrollbar_bar_size1;
            y2 = y + height - g_mmi_gui_scrollbar_bar_size3 - 1;
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_TOP));
            gui_show_image(x, y2 + 1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_BOTTOM));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y1, x + width - 1, y2);
            }
            remain = y2 - y1 + 1;
            while (remain > 0)
            {
                gui_show_image(x, y1, (PU8) GetImage(IMG_SCROLLBAR_V_BAR_MIDDLE));
                y1 += g_mmi_gui_scrollbar_bar_size2;
                remain -= g_mmi_gui_scrollbar_bar_size2;
            }
        }
    }
    else
    {
        if (width <= g_mmi_gui_scrollbar_bar_size1 + g_mmi_gui_scrollbar_bar_size3)
        {
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x + (width >> 1) - 1, y + height - 1);
            }
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x + (width >> 1), y, x + width - 1, y + height - 1);
            }
            gui_show_image(x + width - g_mmi_gui_scrollbar_bar_size3, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
        }
        else
        {
            S32 x1, x2, remain;

            x1 = x + g_mmi_gui_scrollbar_bar_size1;
            x2 = x + width - g_mmi_gui_scrollbar_bar_size3 - 1;
            gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_LEFT));
            gui_show_image(x2 + 1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_RIGHT));
            if (gui_scrollbar_redraw_clip_enable)
            {
                gui_set_clip(x, y, x2, y + height - 1);
            }
            remain = x2 - x1 + 1;
            while (remain > 0)
            {
                gui_show_image(x1, y, (PU8) GetImage(IMG_SCROLLBAR_H_BAR_MIDDLE));
                x1 += g_mmi_gui_scrollbar_bar_size2;
                remain -= g_mmi_gui_scrollbar_bar_size2;
            }
        }
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_draw_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  b           [IN/OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_draw_button(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;
    S32 x, y, width, height;
    BOOL is_button_pressed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrollbar_precache_image_size();

    c = b->normal_up_filler->c;
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;

    if (width == 0 || height == 0)
    {
        return;
    }

    if ((b->flags & UI_BUTTON_SHIFT_BUTTON1) || (b->flags & UI_BUTTON_SHIFT_BUTTON2))
    {
        is_button_pressed = MMI_TRUE;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to keep one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
        {
            S32 x2, y2, i, cnt;

            gui_scrollbar_precache_color1(c, width);

            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                /* 1 pixel spacing in the top and bottom side */
                height--;
                y++;
            }
            else
            {
                /* 1 pixel spacing in the left and right side */
                width--;
                x++;
            }

            x2 = x + width - 1;
            y2 = y + height - 1;

            /* External border */
            gui_draw_horizontal_line(x + 2, x2 - 2, y, g_mmi_gui_scrollbar_border_color);
            gui_draw_horizontal_line(x + 2, x2 - 2, y2, g_mmi_gui_scrollbar_border_color);
            gui_draw_vertical_line(y + 2, y2 - 2, x, g_mmi_gui_scrollbar_border_color);
            gui_draw_vertical_line(y + 2, y2 - 2, x2, g_mmi_gui_scrollbar_border_color);
            gui_putpixel(x + 1, y + 1, g_mmi_gui_scrollbar_border_color);
            gui_putpixel(x + 1, y2 - 1, g_mmi_gui_scrollbar_border_color);
            gui_putpixel(x2 - 1, y + 1, g_mmi_gui_scrollbar_border_color);
            gui_putpixel(x2 - 1, y2 - 1, g_mmi_gui_scrollbar_border_color);
            /* Light border */
            gui_draw_vertical_line(y + 2, y2 - 2, x + 1, g_mmi_gui_scrollbar_light_color);
            gui_draw_horizontal_line(x + 2, x2 - 2, y + 1, g_mmi_gui_scrollbar_light_color);

            /* Gradient color fill */
            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                for (i = y + 2, cnt = 0; i <= y2 - 2; i++, cnt++)
                {
                    if (cnt >= GUI_SCROLLBAR_NUM_GRADIENT_COLOR)
                    {
                        cnt = GUI_SCROLLBAR_NUM_GRADIENT_COLOR - 1;
                    }
                    gui_draw_horizontal_line(x + 2, x2 - 2, i, g_mmi_gui_scrollbar_gradient[cnt]);
                }

                /* Dark border */
                gui_draw_vertical_line(y + 2, y2 - 2, x2 - 1, g_mmi_gui_scrollbar_medium_color);
                gui_draw_horizontal_line(x + 2, x2 - 2, y2 - 1, g_mmi_gui_scrollbar_dark_color);
            }
            else
            {
                for (i = x + 2, cnt = 0; i <= x2 - 2; i++, cnt++)
                {
                    if (cnt >= GUI_SCROLLBAR_NUM_GRADIENT_COLOR)
                    {
                        cnt = GUI_SCROLLBAR_NUM_GRADIENT_COLOR - 1;
                    }
                    gui_draw_vertical_line(y + 2, y2 - 2, i, g_mmi_gui_scrollbar_gradient[cnt]);
                }

                /* Dark border */
                gui_draw_vertical_line(y + 2, y2 - 2, x2 - 1, g_mmi_gui_scrollbar_dark_color);
                gui_draw_horizontal_line(x + 2, x2 - 2, y2 - 1, g_mmi_gui_scrollbar_medium_color);
            }

            /* Show a mark on the button */
            if (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
            {
                S32 mark_y1, mark_y2, mark_x;

                mark_y1 = y + ((height - GUI_SCROLLBAR_MARK_WIDTH) >> 1);
                mark_y2 = mark_y1 + GUI_SCROLLBAR_MARK_WIDTH - 1;

                if (width > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3)
                {
                    mark_x = x + (width >> 1) - 2;
                    for (i = 0; i < 3; i++)
                    {
                        gui_draw_vertical_line(mark_y1, mark_y2, mark_x++, g_mmi_gui_scrollbar_light_color);
                        gui_draw_vertical_line(mark_y1 + 1, mark_y2 + 1, mark_x++, g_mmi_gui_scrollbar_dark_color);
                    }
                }
                else if (width > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2)
                {
                    mark_x = x + (width >> 1) - 1;
                    for (i = 0; i < 2; i++)
                    {
                        gui_draw_vertical_line(mark_y1, mark_y2, mark_x++, g_mmi_gui_scrollbar_light_color);
                        gui_draw_vertical_line(mark_y1 + 1, mark_y2 + 1, mark_x++, g_mmi_gui_scrollbar_dark_color);
                    }
                }
            }
            else
            {
                S32 mark_x1, mark_x2, mark_y;

                mark_x1 = x + ((width - GUI_SCROLLBAR_MARK_WIDTH) >> 1);
                mark_x2 = mark_x1 + GUI_SCROLLBAR_MARK_WIDTH - 1;

                if (height > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_3)
                {
                    mark_y = y + (height >> 1) - 2;
                    for (i = 0; i < 3; i++)
                    {
                        gui_draw_horizontal_line(mark_x1, mark_x2, mark_y++, g_mmi_gui_scrollbar_light_color);
                        gui_draw_horizontal_line(mark_x1 + 1, mark_x2 + 1, mark_y++, g_mmi_gui_scrollbar_dark_color);
                    }
                }
                else if (height > GUI_SCROLLBAR_MIN_HEIGHT_WITH_MARK_2)
                {
                    mark_y = y + (height >> 1) - 1;
                    for (i = 0; i < 2; i++)
                    {
                        gui_draw_horizontal_line(mark_x1, mark_x2, mark_y++, g_mmi_gui_scrollbar_light_color);
                        gui_draw_horizontal_line(mark_x1 + 1, mark_x2 + 1, mark_y++, g_mmi_gui_scrollbar_dark_color);
                    }
                }
            }

            break;
        }

        case GUI_SCROLLBAR_BUTTON_UP:
        case GUI_SCROLLBAR_BUTTON_LEFT:
        case GUI_SCROLLBAR_BUTTON_DOWN:
        case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
            gui_scrollbar_precache_color2(c);

            if (is_button_pressed)
            {
                gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_DOWN));
            }
            else
            {
                gui_show_image(x, y, (PU8) GetImage(IMG_SCROLLBAR_BUTTON_UP));
            }

            if (is_button_pressed)
            {
                y++;
            }

            if (type == GUI_SCROLLBAR_BUTTON_UP)
            {
                S32 arrow_width = width - (GUI_SCROLLBAR_ARROW_GAP << 1);
                S32 arrow_height;
                S32 x1, y1, i;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y + arrow_height - 1 - 1; /* -1 for center */

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color);
                    y1--;
                    x1++;
                }
                y1 += 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color);
                    y1++;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
            {
                S32 arrow_width = width - (GUI_SCROLLBAR_ARROW_GAP << 1);
                S32 arrow_height;
                S32 x1, y1, i;

                arrow_width -= (arrow_width % 2);
                arrow_height = arrow_width >> 1;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                for (i = 0; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color);
                    y1++;
                    x1++;
                }
                y1 -= 2;
                for (i = 1; i < arrow_height; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1 + 1, y1, g_mmi_gui_scrollbar_arrow_color);
                    y1--;
                    x1++;
                }
            }
            else if (type == GUI_SCROLLBAR_BUTTON_LEFT)
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP << 1);
                S32 arrow_width;
                S32 x1, y1, i;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x + arrow_width - 1 - 1;  /* -1 for center */

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color);
                    y1++;
                    x1--;
                }
                x1 += 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color);
                    y1++;
                    x1++;
                }
            }
            else
            {
                S32 arrow_height = height - (GUI_SCROLLBAR_ARROW_GAP << 1);
                S32 arrow_width;
                S32 x1, y1, i;

                arrow_height -= (arrow_height % 2);
                arrow_width = arrow_height >> 1;

                y1 = (height - arrow_height);
                if (y1 > 0)
                {
                    y1 >>= 1;
                }
                else
                {
                    y1 = 0;
                }
                y1 += y;

                x1 = (width - arrow_width);
                if (x1 > 0)
                {
                    x1 >>= 1;
                }
                else
                {
                    x1 = 0;
                }
                x1 += x;

                for (i = 0; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color);
                    y1++;
                    x1++;
                }
                x1 -= 2;
                for (i = 1; i < arrow_width; i++)
                {
                    gui_putpixel(x1, y1, g_mmi_gui_scrollbar_arrow_color);
                    gui_putpixel(x1, y1 + 1, g_mmi_gui_scrollbar_arrow_color);
                    y1++;
                    x1--;
                }
            }

            break;
        }

        default:
            MMI_DBG_ASSERT(0);
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}

#elif defined(UI_SCROLLBAR_STYLE_2)
/* 
 * We do not use gui_draw_filled_area and UI_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE#
 * because up/down/left/right and horizontal/vertical scroll has up and down states, and 
 * we need to define lots of filler types.
 */


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_get_button_min_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  bar_width       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_scrollbar_get_button_min_size(gui_scrollbar_buttton_enum type, S32 bar_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
            /* "Expected" minimum size. However, the size of button may be larger. */
            ret = 12;
            break;

        case GUI_SCROLLBAR_BUTTON_UP:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_DOWN:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_LEFT:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_RIGHT:
            if (bar_width < 5)
            {
                /* Do not display these button at all */
                ret = 0;
            }
            else if ((bar_width % 2) == 0)
            {
                ret = bar_width;
            }
            else
            {
                /* height of button = width - 1.  But we need leave two pixels for room between scroll button */
                ret = bar_width + 1;
            }
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_adjust_luminance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  luminance       [IN/OUT]         
 *  diff            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_adjust_luminance(U8 *luminance, S16 diff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 l = *luminance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l += diff;
    if (l > 255)
    {
        l = 255;
    }
    if (l < 0)
    {
        l = 0;
    }
    *luminance = (U8) l;
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrollbar_draw_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  b           [IN/OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_scrollbar_draw_button(gui_scrollbar_buttton_enum type, icon_button *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_HLS_color hls;
    color c;
    S32 x, y, width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = b->x;
    y = b->y;
    width = b->width;
    height = b->height;
    c = b->normal_up_filler->c;

    /* Scroll button does not support highlight in UI_SCROLLBAR_STYLE_2 */
    if (type != GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && type != GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL)
    {
        if (b->flags & UI_BUTTON_SHIFT_BUTTON1)
        {
            y++;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
        else if (b->flags & UI_BUTTON_SHIFT_BUTTON2)
        {
            y += 2;
            gui_RGB_to_HLS(c, &hls);
            hls.l = (U8) ((U16) hls.l * 3 / 4);
            hls.s = (U8) ((U16) hls.s * 5 / 6);
            gui_HLS_to_RGB(hls, &c);
        }
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x, y, x + width - 1, y + height - 1);
    }

    /* shift the position to leave one-pixel space */
    if (type == GUI_SCROLLBAR_BUTTON_LEFT || type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {
        x++;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP || type == GUI_SCROLLBAR_BUTTON_DOWN)
    {
        y++;
    }

    switch (type)
    {
        case GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL:
            /* FALLTHROUGH no break */
        case GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL:
        {
            S32 i;
            S32 num_shadow_line;
            color cs[3];    /* shadow color */
            color cf;       /* fill color */

            gui_RGB_to_HLS(c, &hls);

            if (height < 5 || width < 5)
            {
                /* No room to display the bar in special style */
                gui_show_icon_button(b);
            }
            else
            {
                if ((type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL && width >= 9) ||
                    (type == GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL && height >= 9))
                {
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[2]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 3;
                }
                else
                {
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[0]);
                    gui_scrollbar_adjust_luminance(&hls.l, 10);
                    gui_HLS_to_RGB(hls, &cs[1]);
                    gui_scrollbar_adjust_luminance(&hls.l, 20);
                    gui_HLS_to_RGB(hls, &cf);
                    num_shadow_line = 2;
                }

                if (type == GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL)
                {
                    S32 x2, y2;

                    if (!(width % 2))
                    {
                        width--;
                    }
                    if (height >= 8)
                    {
                        /* Leave 1-pixel space */
                        y++;
                        height -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);

                        for (i = x + 1; i < x2 - num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_vertical_line(y + 1, y2 - 1, x2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
                else
                {
                    S32 x2, y2;

                    if (!(height % 2))
                    {
                        height--;
                    }
                    if (width >= 8)
                    {
                        /* Leave 1-pixel space */
                        x++;
                        width -= 2;
                    }

                    x2 = x + width - 1;
                    y2 = y + height - 1;

                    if (width <= 5)
                    {
                        gui_draw_horizontal_line(x + 1, x2 - 1, y, c);
                        gui_draw_horizontal_line(x + 1, x2 - 1, y2, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x, c);
                        gui_draw_vertical_line(y + 1, y2 - 1, x2, c);
                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }
                    }
                    else
                    {
                        gui_draw_horizontal_line(x + 2, x2 - 2, y, c);
                        gui_draw_horizontal_line(x + 2, x2 - 2, y2, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x, c);
                        gui_draw_vertical_line(y + 2, y2 - 2, x2, c);

                        for (i = y + 1; i < y2 - num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, i, cf);
                        }

                        for (i = 0; i < num_shadow_line; i++)
                        {
                            gui_draw_horizontal_line(x + 1, x2 - 1, y2 - 1 - i, cs[i]);
                        }

                        gui_putpixel(x + 1, y + 1, c);
                        gui_putpixel(x2 - 1, y + 1, c);
                        gui_putpixel(x + 1, y2 - 1, c);
                        gui_putpixel(x2 - 1, y2 - 1, c);
                    }
                }
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_UP:
        {
            if ((width % 2) == 0)
            {
                width--;
            }

            if (width < 5 || (width == 5 && height < 4) || (width > 5 && height < width - 1))
            {
                /* Draw nothing */
            }
            else if (width == 5)
            {
                gui_putpixel(x, y + 2, c);
                gui_putpixel(x, y + 3, c);
                gui_putpixel(x + 1, y + 1, c);
                gui_putpixel(x + 1, y + 2, c);
                gui_putpixel(x + 2, y, c);
                gui_putpixel(x + 2, y + 1, c);
                gui_putpixel(x + 3, y + 1, c);
                gui_putpixel(x + 3, y + 2, c);
                gui_putpixel(x + 4, y + 2, c);
                gui_putpixel(x + 4, y + 3, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hw;
                S32 x2, y2;

                /* Reduce the height */
                height = width - 1;

                x2 = x + width - 1;
                y2 = y + height - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hw = (width >> 1);
                gui_draw_vertical_line(y + hw, y2, x, cb);
                for (i = 0; i < hw; i++)
                {
                    gui_putpixel(x + hw - i, y + i, cb);
                    gui_draw_vertical_line(y + i + 1, y2 - 1, x + hw - i, c);
                }
                for (i = 1; i < hw; i++)
                {
                    gui_putpixel(x + hw + i, y + i, cb);
                    gui_draw_vertical_line(y + i + 1, y2 - 1, x + hw + i, c);
                }
                gui_draw_vertical_line(y + hw, y2, x2, cb);
                gui_draw_horizontal_line(x, x2, y2, cb);
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_LEFT:
        {
            if ((height % 2) == 0)
            {
                height--;
            }

            if (height < 5 || (height == 5 && width < 4) || (height > 5 && width < height - 1))
            {
                /* Draw nothing */
            }
            else if (height == 5)
            {
                gui_putpixel(x + 2, y, c);
                gui_putpixel(x + 3, y, c);
                gui_putpixel(x + 1, y + 1, c);
                gui_putpixel(x + 2, y + 1, c);
                gui_putpixel(x, y + 2, c);
                gui_putpixel(x + 1, y + 2, c);
                gui_putpixel(x + 1, y + 3, c);
                gui_putpixel(x + 2, y + 3, c);
                gui_putpixel(x + 2, y + 4, c);
                gui_putpixel(x + 3, y + 4, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hh;
                S32 x2, y2;

                /* Reduce the width */
                width = height - 1;

                x2 = x + width - 1;
                y2 = y + height - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hh = (height >> 1);
                gui_draw_horizontal_line(x + hh, x2, y, cb);
                for (i = 0; i < hh; i++)
                {
                    gui_putpixel(x + i, y + hh - i, cb);
                    gui_draw_horizontal_line(x + i + 1, x2 - 1, y + hh - i, c);
                }
                for (i = 1; i < hh; i++)
                {
                    gui_putpixel(x + i, y + hh + i, cb);
                    gui_draw_horizontal_line(x + i + 1, x2 - 1, y + hh + i, c);
                }
                gui_draw_horizontal_line(x + hh, x2, y2, cb);
                gui_draw_vertical_line(y, y2, x2, cb);
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_DOWN:
        {
            S32 y1, y2;

            if ((width % 2) == 0)
            {
                width--;
            }

            // y2 = y + height - 1 - 1;
            // y1 = y2 - (width - 1) + 1;
            /* (width - 1) is the height drawn */
            y1 = y;
            y2 = y1 + (width - 1) - 1;

            if (width < 5 || (width == 5 && height < 4) || (width > 5 && height < width - 1))
            {
                /* Draw nothing */
            }
            else if (width == 5)
            {
                gui_putpixel(x, y2 - 2, c);
                gui_putpixel(x, y2 - 3, c);
                gui_putpixel(x + 1, y2 - 1, c);
                gui_putpixel(x + 1, y2 - 2, c);
                gui_putpixel(x + 2, y2, c);
                gui_putpixel(x + 2, y2 - 1, c);
                gui_putpixel(x + 3, y2 - 1, c);
                gui_putpixel(x + 3, y2 - 2, c);
                gui_putpixel(x + 4, y2 - 2, c);
                gui_putpixel(x + 4, y2 - 3, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hw;

                /* Reduce the height */
                height = width - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hw = (width >> 1);
                gui_draw_vertical_line(y1, y2 - hw, x, cb);
                for (i = 0; i < hw; i++)
                {
                    gui_putpixel(x + hw - i, y2 - i, cb);
                    gui_draw_vertical_line(y1 + 1, y2 - i - 1, x + hw - i, c);
                }
                for (i = 1; i < hw; i++)
                {
                    gui_putpixel(x + hw + i, y2 - i, cb);
                    gui_draw_vertical_line(y1 + 1, y2 - i - 1, x + hw + i, c);
                }
                gui_draw_vertical_line(y1, y2 - hw, x + width - 1, cb);
                gui_draw_horizontal_line(x, x + width - 1, y1, cb);
            }
        }
            break;

        case GUI_SCROLLBAR_BUTTON_RIGHT:
        {
            S32 x1, x2;

            if ((height % 2) == 0)
            {
                height--;
            }

            // x2 = x + width - 1 - 1;
            // x1 = x2 - (height - 1) + 1;
            /* (height - 1) is the width drawn */
            x1 = x;
            x2 = x + (height - 1) - 1;

            if (height < 5 || (height == 5 && width < 4) || (height > 5 && width < height - 1))
            {
                /* Draw nothing */
            }
            else if (height == 5)
            {
                gui_putpixel(x2 - 2, y, c);
                gui_putpixel(x2 - 3, y, c);
                gui_putpixel(x2 - 1, y + 1, c);
                gui_putpixel(x2 - 2, y + 1, c);
                gui_putpixel(x2, y + 2, c);
                gui_putpixel(x2 - 1, y + 2, c);
                gui_putpixel(x2 - 1, y + 3, c);
                gui_putpixel(x2 - 2, y + 3, c);
                gui_putpixel(x2 - 2, y + 4, c);
                gui_putpixel(x2 - 3, y + 4, c);
            }
            else
            {
                UI_HLS_color hls;
                color cb;
                S32 i, hh;

                /* Reduce the width */
                width = height - 1;

                gui_RGB_to_HLS(c, &hls);
                hls.l = (U8) (((U16) hls.l * 2 + 255) / 3);
                gui_HLS_to_RGB(hls, &cb);

                hh = (height >> 1);
                gui_draw_horizontal_line(x1, x2 - hh, y, cb);
                for (i = 0; i < hh; i++)
                {
                    gui_putpixel(x2 - i, y + hh - i, cb);
                    gui_draw_horizontal_line(x1 + 1, x2 - i - 1, y + hh - i, c);
                }
                for (i = 1; i < hh; i++)
                {
                    gui_putpixel(x2 - i, y + hh + i, cb);
                    gui_draw_horizontal_line(x1 + 1, x2 - i - 1, y + hh + i, c);
                }
                gui_draw_horizontal_line(x1, x2 - hh, y + height - 1, cb);
                gui_draw_vertical_line(y, y + height - 1, x1, cb);
            }
        }

            break;
    }

    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

}


#endif /* UI_SCROLLBAR_STYLE_5 */

#if defined(UI_SCROLLBAR_STYLE_1)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_1
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_1(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_show_icon_button(&v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_show_icon_button(&v->right_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_1
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_1(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Please read the description in gui_show_vertical_scrollbar()
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_show_icon_button(&v->left_button);
        gui_show_icon_button(&v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = v->height;
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif 

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gui_show_icon_button(&v->scroll_button);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_1
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_1(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {   
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_show_icon_button(&v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {   
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_show_icon_button(&v->down_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_1
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_1(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Tricky to handle scrollbar background here!
             * 
             * Some screens like Obigo or Jataayu WAP disable source key of layer, 
             * and WAP typically uses white background.
             *
             * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may 
             * produce weird display with inappropriate scrollbar background color 
             * created by MCT or PhoneSuite (Downloadable theme)
             *
             * We decide not to change WAP code, but use white color here for
             * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
             *
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_show_icon_button(&v->up_button);
        gui_show_icon_button(&v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = v->width;
    if (min_height > max_height)
    {
        min_height = max_height;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif 

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    gui_show_icon_button(&v->scroll_button);
}

#elif defined(UI_SCROLLBAR_STYLE_2)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_2
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_2(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_2
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_2(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Please read the description in gui_show_vertical_scrollbar()
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif 

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_2
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_2(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {   
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {   
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_2
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_2(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Tricky to handle scrollbar background here!
             * 
             * Some screens like Obigo or Jataayu WAP disable source key of layer, 
             * and WAP typically uses white background.
             *
             * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may 
             * produce weird display with inappropriate scrollbar background color 
             * created by MCT or PhoneSuite (Downloadable theme)
             *
             * We decide not to change WAP code, but use white color here for
             * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
             *
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif 

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
}

#elif defined(UI_SCROLLBAR_STYLE_3)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_3
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_3(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar_style_3
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_3(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Please read the description in gui_show_vertical_scrollbar()
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif 

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->x + v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height);
    }
    else
    {
        gui_scrollbar_draw_region(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height);
    }
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_3
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_3(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {   
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {   
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_3
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_3(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Tricky to handle scrollbar background here!
             * 
             * Some screens like Obigo or Jataayu WAP disable source key of layer, 
             * and WAP typically uses white background.
             *
             * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may 
             * produce weird display with inappropriate scrollbar background color 
             * created by MCT or PhoneSuite (Downloadable theme)
             *
             * We decide not to change WAP code, but use white color here for
             * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
             *
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif 

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height);
    }
    else
    {
        gui_scrollbar_draw_region(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height);
    }
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
}

#elif defined(UI_SCROLLBAR_STYLE_4)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_4(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
#endif 
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
#endif 
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_4(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    GDI_HANDLE gdi_lcd_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Please read the description in gui_show_vertical_scrollbar()
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    #endif 
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        min_width = v->height + 2;
    #else
    min_width = v->height - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2 + 3;
    #endif 
#endif 
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif 

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    gdi_lcd_get_active(&gdi_lcd_layer);
    if (gdi_lcd_layer == GDI_LCD_SUB_LCD_HANDLE)
    {
        gui_scrollbar_draw_button_style2(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    else 
    {
    if (buttons_flag)
    {
        gui_scrollbar_draw_region(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->x + v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height,
            &v->scroll_button);
    }
    else
    {
        gui_scrollbar_draw_region(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height, &v->scroll_button);
    }
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);
    }

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_4
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_4(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {   
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
#endif 
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {   
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
#if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
#endif 
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_4
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_4(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;
    GDI_HANDLE gdi_lcd_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Tricky to handle scrollbar background here!
             * 
             * Some screens like Obigo or Jataayu WAP disable source key of layer, 
             * and WAP typically uses white background.
             *
             * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may 
             * produce weird display with inappropriate scrollbar background color 
             * created by MCT or PhoneSuite (Downloadable theme)
             *
             * We decide not to change WAP code, but use white color here for
             * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
             *
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    #endif 
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
#if defined(__MMI_TOUCH_SCREEN__)
    #if defined (__MMI_MAINLCD_128X160__)
        min_height = v->width + 2;
    #else
    min_height = v->width - GUI_SCROLLBAR_STYLE4_TOUCH_GAP * 2 + 3;
    #endif
#else
    min_height = v->width - GUI_SCROLLBAR_STYLE4_NOTOUCH_GAP * 2 + 3;
#endif 
    if (min_height > max_height)
    {
        min_height = max_height;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif 

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    gdi_lcd_get_active(&gdi_lcd_layer);
    if (gdi_lcd_layer == GDI_LCD_SUB_LCD_HANDLE)
    {
        gui_scrollbar_draw_button_style2(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
    else 
    {
    if (buttons_flag)
    {
        gui_scrollbar_draw_region(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height,
            &v->scroll_button);
    }
    else
    {
        gui_scrollbar_draw_region(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height, &v->scroll_button);        
    }
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
    }
}

#elif defined(UI_SCROLLBAR_STYLE_5)
/*****************************************************************************
 * FUNCTION
*  gui_horizontal_scrollbar_redraw_button_style_5
* DESCRIPTION
*  Redraw the horizontal scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_horizontal_scrollbar_redraw_button_style_5(horizontal_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_LEFT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->left_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->left_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_RIGHT)
    {   
        if (pressed == MMI_TRUE)
        {
            v->right_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->right_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_horizontal_scrollbar
 * DESCRIPTION
 *  Displays the horizontal scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the horizontal scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_horizontal_scrollbar_style_5(horizontal_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_width, sb_x, sb_xrange, r, min_width = 0, max_width = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_HORIZONTAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_HORIZONTAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
    /* Style 3 use three image to compose scrollbar background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if (source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Please read the description in gui_show_vertical_scrollbar()
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_LEFT, &v->left_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_RIGHT, &v->right_button);
        max_width = v->width - v->left_button.width - v->right_button.width;
    }
    else
    {
        max_width = v->width;
    }

    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_width = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, v->height);
    if (min_width > max_width)
    {
        min_width = max_width;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_width = (v->scale * max_width) / v->range;
        }
        else
        {
            sbutton_width = max_width;
        }
    }
    else
    {
        sbutton_width = min_width;
    }
    if (sbutton_width < min_width)
    {
        sbutton_width = min_width;
    }
    if (sbutton_width > max_width)
    {
        sbutton_width = max_width;
    }
    sb_xrange = max_width - sbutton_width;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_x = (S32) ((S64) sb_xrange * v->value / r);
    }
    else
    {
        sb_x = 0;
    }
    if (sb_x < 0)
    {
        sb_x = 0;
    }
    if (sb_x > sb_xrange)
    {
        sb_x = sb_xrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_xrange;
#endif 

    v->scroll_button.width = sbutton_width;
    v->scroll_button.x = sb_x + x1 + (buttons_flag ? v->left_button.width : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region(
            GUI_SCROLLBAR_REGION_HORIZONTAL,
            v->x + v->left_button.x + v->left_button.width,
            v->y,
            v->right_button.x - v->left_button.x - v->left_button.width,
            v->height);
    }
    else
    {
        gui_scrollbar_draw_region(GUI_SCROLLBAR_REGION_HORIZONTAL, v->x, v->y, v->width, v->height);
    }
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_HORIZONTAL_SCROLL, &v->scroll_button);

}


/*****************************************************************************
 * FUNCTION
*  gui_vertical_scrollbar_redraw_button_style_5
* DESCRIPTION
*  Redraw the vertical scrollbar button
* PARAMETERS
*  v       [IN/OUT]            Is the vertical scrollbar object
* RETURNS
*  void
*****************************************************************************/
void gui_vertical_scrollbar_redraw_button_style_5(vertical_scrollbar *v, gui_scrollbar_buttton_enum type, MMI_BOOL pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        return;
    }
    if (type == GUI_SCROLLBAR_BUTTON_UP)
    {   
        if (pressed == MMI_TRUE)
        {
            v->up_button.flags |= UI_BUTTON_SHIFT_BUTTON1;
        }
        else
        {
            v->up_button.flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        }
        
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
    }
    else if (type == GUI_SCROLLBAR_BUTTON_DOWN)
    {   
        if (pressed == MMI_TRUE)
        {
            v->down_button.flags |= UI_BUTTON_SHIFT_BUTTON2;
        }
        else
        {
            v->down_button.flags &= ~UI_BUTTON_SHIFT_BUTTON2;
        }
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
    }
}


/*****************************************************************************
* FUNCTION
 *  gui_show_vertical_scrollbar_style_5
 * DESCRIPTION
 *  Displays the vertical scrollbar
 * PARAMETERS
 *  v       [IN/OUT]            Is the vertical scrollbar object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_vertical_scrollbar_style_5(vertical_scrollbar *v)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sbutton_height, sb_y, sb_yrange, r, min_height = 0, max_height = 0;
    U8 buttons_flag = 1;
    UI_filled_area *f;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (v->flags & UI_VERTICAL_SCROLLBAR_TYPE_BUTTONLESS)
    {
        buttons_flag = 0;
    }

    x1 = v->x;
    x2 = x1 + v->width - 1;
    y1 = v->y;
    y2 = y1 + v->height - 1;

    if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_FOCUSSED)
    {
        f = v->focussed_bar_filler;
    }
    else if (v->flags & UI_VERTICAL_SCROLLBAR_STATE_DISABLED)
    {
        f = v->disabled_bar_filler;
    }
    else
    {
        f = v->normal_bar_filler;
    }
    
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    }
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {
        BOOL source_key_enable;
        gdi_color source_key_value;

        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if ((wgui_is_wallpaper_on_bottom() == MMI_TRUE) && source_key_enable)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, source_key_value);
        }
        else
        {
            /*
             * Tricky to handle scrollbar background here!
             * 
             * Some screens like Obigo or Jataayu WAP disable source key of layer, 
             * and WAP typically uses white background.
             *
             * If we use 'gui_draw_filled_area(x1, y1, x2, y2, f);' instead, it may 
             * produce weird display with inappropriate scrollbar background color 
             * created by MCT or PhoneSuite (Downloadable theme)
             *
             * We decide not to change WAP code, but use white color here for
             * __MMI_WALLPAPER_ON_BOTTOM__ (> 240x320 screen)
             *
             */
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        }
    }
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    gui_draw_filled_area(x1, y1, x2, y2, f);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
    if (gui_scrollbar_redraw_clip_enable)
    {
        gui_pop_clip();
    }

    if (buttons_flag)
    {
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_UP, &v->up_button);
        gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_DOWN, &v->down_button);
        max_height = v->height - v->up_button.height - v->down_button.height;
    }
    else
    {
        max_height = v->height;
    }
    /* Show the scroll button based on range and value */
    r = v->range - v->scale;
    min_height = gui_scrollbar_get_button_min_size(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, v->width);
    if (min_height > max_height)
    {
        min_height = max_height;
    }
    if (v->scale > 0)
    {
        if (v->range > 0)
        {
            sbutton_height = (v->scale * max_height) / v->range;
        }
        else
        {
            sbutton_height = max_height;
        }
    }
    else
    {
        sbutton_height = min_height;
    }
    if (sbutton_height < min_height)
    {
        sbutton_height = min_height;
    }
    if (sbutton_height > max_height)
    {
        sbutton_height = max_height;
    }
    sb_yrange = max_height - sbutton_height;
    if (r > 0)
    {
        /* In case of very large r & v->value */
        sb_y = (S32) ((S64) sb_yrange * v->value / r);
    }
    else
    {
        sb_y = 0;
    }
    if (sb_y < 0)
    {
        sb_y = 0;
    }
    if (sb_y > sb_yrange)
    {
        sb_y = sb_yrange;
    }

#ifdef __MMI_TOUCH_SCREEN__
    v->pen_state.remain_space = (S16) sb_yrange;
#endif 

    v->scroll_button.height = sbutton_height;
    v->scroll_button.y = sb_y + y1 + (buttons_flag ? v->up_button.height : 0);
    if (buttons_flag)
    {
        gui_scrollbar_draw_region(
            GUI_SCROLLBAR_REGION_VERTICAL,
            v->x,
            v->up_button.y + v->up_button.height,
            v->width,
            v->down_button.y - v->up_button.y - v->up_button.height);
    }
    else
    {
        gui_scrollbar_draw_region(GUI_SCROLLBAR_REGION_VERTICAL, v->x, v->y, v->width, v->height);
    }
    gui_scrollbar_draw_button(GUI_SCROLLBAR_BUTTON_VERTICAL_SCROLL, &v->scroll_button);
}

#endif /* UI_SCROLLBAR_STYLE_1 */


