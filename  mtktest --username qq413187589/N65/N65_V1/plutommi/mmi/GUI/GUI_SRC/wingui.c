/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  wingui.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Wrappers for primitivive UI drawing 
 *
 *  o hatch fill 
 *  o smooth line (anti-alising)
 *  o text 
 *  o UI timer
 *  o bootup display
 *
 *  Otjher functions are replaced by other modules:
 *  
 *  o LCD handling      - replaced by GDI
 *  o line/rectangle    - replaced by GDI
 *  o layer/clipping    - replaced by GDI
 *  o string            - replaced by UCS2.c
 *  o bmp/gif/animation - replaced by GDI
 *   
 *  For example, applications and category screens should use GDI API directly 
 *  for image decoder and animations.
 * 
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * apply correct compile option: __MMI_RESOURCE_ENFB_SUPPORT__
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * check in [NewFeature]MMI trace string
 *
 * removed!
 * removed!
 * Add gdi_image_estimate_show_fullscreen_time bypass function.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Turn on backlight in the end of MMICheckDiskDisplay
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *******************************************************************************/
 

#include "mmi_features.h"       
#include "PixcomFontengine.h"
#include "MMIDataType.h"
#include "globalconstants.h"
#include "EventsGprot.h"
#include "TimerEvents.h"
#include "gui_config.h"
#include "Bootup.h"
#include "UCS2prot.h"
#include "gui_data_types.h"
#include "gui.h"
#include "gui_bytestream.h"
#include "wgui_categories_defs.h"
#include "kal_non_specific_general_types.h"
#include "gdi_include.h"        
#include "gui_setting.h"
#include "lcd_sw_rnd.h"
#include "wgui_status_icons.h"
#include "DebugInitDef.h"
#include "EventsGprot.h"

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined (__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__) || defined (UI_SCROLLBAR_STYLE_4)
#include"gd_primitive.h"        /* for gd functions */
#endif 

/* lcd driver related */
#include "kal_non_specific_general_types.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "lcd_if.h"
#include "L4Dr.h"
#include "FileManagerGProt.h"

#ifdef __MMI_SCREEN_ROTATE__
#include "ScreenRotationGprot.h"
#endif 

#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
#include "ResMemMgrGprot.h"
#endif

/************************************************************************/
/*  Variable                                                            */
/************************************************************************/
/* Device bitmaps used for graphics contexts */
/* Test valuse are used here and there for gui to determine use which LCD context */
bitmap main_LCD_device_bitmap;
bitmap sub_LCD_device_bitmap;

bitmap *current_LCD_device_bitmap = NULL;
bitmap *current_saved_LCD_device_bitmap = NULL;

UI_font_type UI_font;
color UI_current_text_color;

/* Body in PixcomFontEngine - to draw a string */
extern U32 ShowString(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight);

extern kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level);

/* 1: Selects OS timer implementation. Timers are multiplexed by the OS */
/* 0: Selects UI timer implementation. Timers are multiplexed by the UI */
#define  WINGUI_USE_OS_TIMERS       1

#if(!WINGUI_USE_OS_TIMERS)
#define UI_TIMER_RESOLUTION   100
#endif 

/* actual body of these parameter is at gui_wrapper.c */
extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;

#ifdef __MMI_SUBLCD__
extern S32 SUB_LCD_device_width;
extern S32 SUB_LCD_device_height;
#endif /* __MMI_SUBLCD__ */ 

extern U16 gCurrLangIndex;
extern U16 *MainLCD_ShadowBuf_p;
extern S16 MMI_status_icons_list1[];
extern S16 MMI_status_icons_list2[];
extern S16 MMI_status_icons_list3[];

/************************************************************************/
/* Function Pre-Declare                                               */
/************************************************************************/
void UI_set_sub_LCD_graphics_context(void);
void UI_set_main_LCD_graphics_context(void);
void UI_putpixel(S32 x, S32 y, color c);
void UI_putpixel_alpha(S32 x, S32 y, color c);

void _show_transparent_image(S32 x, S32 y, U8 *image, UI_transparent_color_type t);

U8 _show_animation_frame(S32 x, S32 y, U8 *image, S16 frame_number);
U8 _show_transparent_animation_frame(S32 x, S32 y, U8 *image, UI_transparent_color_type t, S16 frame_number);

/************************************************************************/
/* UnChanged Code                                                       */
/************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  UI_cross_hatch_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U32 UI_translate_gui_alpha_to_gdi_alpha(U8 alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 alpha_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alpha_value = (((U32)(alpha)) << 8) / 100;
    if (256 <= alpha_value)
    {
        alpha_value = 255;
    }
    return alpha_value;
}


/*****************************************************************************
 * FUNCTION
 *  UI_cross_hatch_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_cross_hatch_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_fill_dot_rect(x1,y1,x2,y2,gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha),c.r,c.g,c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_alternate_cross_hatch_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c1      [IN]        
 *  c2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_alternate_cross_hatch_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, k = 0;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!((x2 - x1 + 1) % 2))
    {
        flag = 1;
    }
    for (j = y1; j <= y2; j++)
    {
        if (flag)
        {
            pixtel_toggle(k);
        }
        for (i = x1; i <= x2; i++)
        {
            if (k)
            {
                UI_putpixel(i, j, c1);
            }
            else
            {
                UI_putpixel(i, j, c2);
            }
            pixtel_toggle(k);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_hatch_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_hatch_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, k = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = y1; j <= y2; j++)
    {
        if (k)
        {
            for (i = x1; i <= x2; i++)
            {
                UI_putpixel(i, j, c);
            }
        }
        pixtel_toggle(k);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_alternate_hatch_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c1      [IN]        
 *  c2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_alternate_hatch_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c1, color c2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, k = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = y1; j <= y2; j++)
    {
        if (k)
        {
            for (i = x1; i <= x2; i++)
            {
                UI_putpixel(i, j, c1);
            }
        }
        else
        {
            for (i = x1; i <= x2; i++)
            {
                UI_putpixel(i, j, c2);
            }
        }
        pixtel_toggle(k);
    }
}

/* Line drawing algorithm  */

/* Bresenham line drawing routine   */


/*****************************************************************************
 * FUNCTION
 *  UI_line_sign
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_line_sign(S32 a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a < 0)
    {
        return (-1);
    }
    else if (a > 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_line(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dx, dy, p, c1, c2, x, y, xinc, yinc, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dx = x2 - x1;
    dy = y2 - y1;
    xinc = UI_line_sign(dx);
    yinc = UI_line_sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    x = x1;
    y = y1;
    if (dx >= dy)
    {
        p = (dy << 1) - dx;
        c1 = dy << 1;
        c2 = (dy - dx) << 1;
        for (i = 0; i <= dx; i++)
        {
            gui_putpixel(x, y, c);
            if (p < 0)
            {
                p += c1;
            }
            else
            {
                p += c2;
                y += yinc;
            }
            x += xinc;
        }
    }
    else
    {
        p = (dx << 1) - dy;
        c1 = dx << 1;
        c2 = (dx - dy) << 1;
        for (i = 0; i <= dy; i++)
        {
            gui_putpixel(x, y, c);
            if (p < 0)
            {
                p += c1;
            }
            else
            {
                p += c2;
                x += xinc;
            }
            y += yinc;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_wline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 *  w       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_wline(S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dx, dy, p, c1, c2, x, y, xinc, yinc, i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dx = x2 - x1;
    dy = y2 - y1;
    xinc = UI_line_sign(dx);
    yinc = UI_line_sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    x = x1;
    y = y1;
    if (dx >= dy)
    {
        p = (dy << 1) - dx;
        c1 = dy << 1;
        c2 = (dy - dx) << 1;
        for (i = 0; i <= dx; i++)
        {
            for (j = (w >> 1); j >= 0; j--)
            {
                gui_putpixel(x, y - j, c);
                gui_putpixel(x, y + j, c);
            }
            if (p < 0)
            {
                p += c1;
            }
            else
            {
                p += c2;
                y += yinc;
            }
            x += xinc;
        }
    }
    else
    {
        p = (dx << 1) - dy;
        c1 = dx << 1;
        c2 = (dx - dy) << 1;
        for (i = 0; i <= dy; i++)
        {
            for (j = (w >> 1); j >= 0; j--)
            {
                gui_putpixel(x + j, y, c);
                gui_putpixel(x - j, y, c);
            }
            if (p < 0)
            {
                p += c1;
            }
            else
            {
                p += c2;
                x += xinc;
            }
            y += yinc;
        }
    }
}

/* Available only for Main LCD   */


/*****************************************************************************
 * FUNCTION
 *  UI_smooth_pixel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_smooth_pixel(S32 x, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color ca = c;
    color cb = c;
    color cc = c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ca.alpha = 100;
    cb.alpha = 40;
    cc.alpha = 20;
    UI_putpixel(x, y, ca);
    UI_putpixel(x - 1, y, cb);
    UI_putpixel(x + 1, y, cb);
    UI_putpixel(x, y - 1, cb);
    UI_putpixel(x, y + 1, cb);
    UI_putpixel(x - 1, y - 1, cc);
    UI_putpixel(x - 1, y + 1, cc);
    UI_putpixel(x + 1, y - 1, cc);
    UI_putpixel(x + 1, y + 1, cc);
}

/* Available only for Main LCD   */


/*****************************************************************************
 * FUNCTION
 *  UI_smooth_wline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 *  w       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_smooth_wline(S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dx, dy, p, c1, c2, x, y, xinc, yinc, i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dx = x2 - x1;
    dy = y2 - y1;
    xinc = UI_line_sign(dx);
    yinc = UI_line_sign(dy);
    dx = abs(dx);
    dy = abs(dy);
    x = x1;
    y = y1;
    if (dx >= dy)
    {
        p = (dy << 1) - dx;
        c1 = dy << 1;
        c2 = (dy - dx) << 1;
        for (i = 0; i <= dx; i++)
        {
            for (j = (w >> 1); j > 0; j--)
            {
                UI_smooth_pixel(x, y - j, c);
                UI_smooth_pixel(x, y + j, c);
            }
            UI_smooth_pixel(x, y, c);
            if (p < 0)
            {
                p += c1;
            }
            else
            {
                p += c2;
                y += yinc;
            }
            x += xinc;
        }
    }
    else
    {
        p = (dx << 1) - dy;
        c1 = dx << 1;
        c2 = (dx - dy) << 1;
        for (i = 0; i <= dy; i++)
        {
            for (j = (w >> 1); j > 0; j--)
            {
                UI_smooth_pixel(x + j, y, c);
                UI_smooth_pixel(x - j, y, c);
            }
            UI_smooth_pixel(x, y, c);
            if (p < 0)
            {
                p += c1;
            }
            else
            {
                p += c2;
                x += xinc;
            }
            y += yinc;
        }
    }
}

/* Wu antialiased line drawing algorithm  */
/* Uses fixed point math               */
#define _ALINE_SWAP(a,b)      \
      {  S32 temp=a;          \
         a=b;                 \
         b=temp;              \
      }


/*****************************************************************************
 * FUNCTION
 *  UI_antialiased_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_antialiased_line(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, x_inc, y_inc, dx, dy, px, py;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {

        if (dx == 0)
    	{
        	return;
    	}

        if (dx < 0)
        {
            dx = -dx;
            dy = -dy;
            _ALINE_SWAP(x1, x2);
            _ALINE_SWAP(y1, y2);
        }
        x = x1 << 16;
        y = y1 << 16;
        x_inc = 1 << 16;
        y_inc = (dy * 65536) / dx;
        while (1)
        {
            px = x >> 16;
            py = y >> 16;
            if (px >= x2)
            {
                break;
            }
        #ifndef __MMI_ALPHA_LAYER_SUPPORT__
            c.alpha = (U8) ((~y >> 8) & 0xff);
        #endif
            UI_putpixel_alpha(px, py, c);
        #ifndef __MMI_ALPHA_LAYER_SUPPORT__
            c.alpha = ((U8) (y >> 8) & 0xff);
        #endif
            UI_putpixel_alpha(px, py + 1, c);
            x += x_inc;
            y += y_inc;
        }
    }
    else
    {
        if (dy == 0)
        {
            return;
        }
    
        if (dy < 0)
        {
            dx = -dx;
            dy = -dy;
            _ALINE_SWAP(x1, x2);
            _ALINE_SWAP(y1, y2);
        }
        x = x1 << 16;
        y = y1 << 16;
        x_inc = (dx * 65536) / dy;
        y_inc = 1 << 16;
        while (1)
        {
            px = x >> 16;
            py = y >> 16;
            if (py >= y2)
            {
                break;
            }
        #ifndef __MMI_ALPHA_LAYER_SUPPORT__
            c.alpha = (U8) ((~x >> 8) & 0xff);
        #endif
            UI_putpixel_alpha(px, py, c);
        #ifndef __MMI_ALPHA_LAYER_SUPPORT__
            c.alpha = (U8) ((x >> 8) & 0xff);
        #endif
            UI_putpixel_alpha(px + 1, py, c);
            x += x_inc;
            y += y_inc;
        }
    }
}

/* Horizontal line drawing routine  */


/*****************************************************************************
 * FUNCTION
 *  flat_triangle_horizontal_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  x2      [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void flat_triangle_horizontal_line(S32 x1, S32 x2, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x2 < x1)
    {
        _ALINE_SWAP(x1, x2);
    }

    for (x = x1 + 1; x <= x2; x++)
    {
        gui_putpixel(x, y, c);
    }
}

/* Flat polygon (triangle) fill routine   */


/*****************************************************************************
 * FUNCTION
 *  flat_triangle_fill
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vertices        [IN]         
 *  c               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void flat_triangle_fill(polygon_vertex vertices[], color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tx, ty;
    S32 bx, by;
    S32 mx, my;
    S32 y;
    float m1, m2;
    float x1, x2;
    color color_value = c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vertices[0].y < vertices[1].y)
    {
        tx = vertices[0].x;
        ty = vertices[0].y;
        bx = vertices[1].x;
        by = vertices[1].y;
    }
    else
    {
        tx = vertices[1].x;
        ty = vertices[1].y;
        bx = vertices[0].x;
        by = vertices[0].y;
    }
    if (vertices[2].y < ty)
    {
        mx = tx;
        my = ty;
        tx = vertices[2].x;
        ty = vertices[2].y;
    }
    else if (vertices[2].y > by)
    {
        mx = bx;
        my = by;
        bx = vertices[2].x;
        by = vertices[2].y;
    }
    else
    {
        mx = vertices[2].x;
        my = vertices[2].y;
    }
    m1 = ((float)(mx - tx)) / ((float)(my - ty));
    m2 = ((float)(bx - tx)) / ((float)(by - ty));
    x1 = (float)tx;
    x2 = (float)tx;

    if (mx < bx)
    {
        for (y = ty; y < my; y++)
        {
            flat_triangle_horizontal_line((S32) x1, (S32) x2, y, color_value);
            x1 = (float)x1 + (float)m1;
            x2 = (float)x2 + (float)m2;
        }
        x1 = (float)mx;
        m1 = ((float)(bx - mx)) / ((float)(by - my));
        for (y = my; y < by; y++)
        {
            flat_triangle_horizontal_line((S32) x1, (S32) x2, y, color_value);
            x1 = (float)x1 + (float)m1;
            x2 = (float)x2 + (float)m2;
        }
    }
    else
    {
        for (y = ty; y < my; y++)
        {
            flat_triangle_horizontal_line((S32) x2, (S32) x1, y, color_value);
            x1 = (float)x1 + (float)m1;
            x2 = (float)x2 + (float)m2;
        }
        x1 = (float)mx;
        m1 = ((float)(bx - mx)) / ((float)(by - my));
        for (y = my; y < by; y++)
        {
            flat_triangle_horizontal_line((S32) x2, (S32) x1, y, color_value);
            x1 = (float)x1 + (float)m1;
            x2 = (float)x2 + (float)m2;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  polygon_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vertices        [IN]         
 *  n_vertices      [IN]        
 *  c               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void polygon_draw(polygon_vertex vertices[], S32 n_vertices, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_vertices < 3)
    {
        return;
    }
    for (i = 0; i < (n_vertices - 1); i++)
    {
        UI_antialiased_line(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y, c);
    }
    UI_antialiased_line(vertices[i].x, vertices[i].y, vertices[0].x, vertices[0].y, c);
}

#define ARROW_HEIGHT 10 /* 8 */
#define ARROW_WIDTH     5       /* 6//4 */


/*****************************************************************************
 * FUNCTION
 *  draw_arrow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  arrow_type      [IN]        
 *  c               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void draw_arrow(S32 x, S32 y, U8 arrow_type, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    polygon_vertex v[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (arrow_type)
    {
        case 0: /* Left */
            v[0].x = x + 0;
            v[0].y = y + (ARROW_HEIGHT >> 1);
            v[1].x = x + ARROW_WIDTH;
            v[1].y = y + 0;
            v[2].x = x + ARROW_WIDTH;
            v[2].y = y + ARROW_HEIGHT;
            flat_triangle_fill(v, c);
            break;

        case 1: /* Right */
            v[0].x = x + ARROW_WIDTH;
            v[0].y = y + (ARROW_HEIGHT >> 1);
            v[1].x = x + 0;
            v[1].y = y + 0;
            v[2].x = x + 0;
            v[2].y = y + ARROW_HEIGHT;
            flat_triangle_fill(v, c);
            break;

        case 2: /* Up */
            v[0].x = x + (ARROW_WIDTH >> 1);
            v[0].y = y + 0;
            v[1].x = x;
            v[1].y = y + ARROW_HEIGHT;
            v[2].x = x + ARROW_WIDTH;
            v[2].y = y + ARROW_HEIGHT;
            flat_triangle_fill(v, c);
            break;

        case 3: /* Down */
            v[0].x = x + (ARROW_WIDTH >> 1);
            v[0].y = y + ARROW_HEIGHT;
            v[1].x = x + 0;
            v[1].y = y + 0;
            v[2].x = x + ARROW_WIDTH;
            v[2].y = y + 0;
            flat_triangle_fill(v, c);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  draw_resizeable_arrow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  arrow_type      [IN]        
 *  c               [IN]        
 *  width           [IN]        
 *  height          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void draw_resizeable_arrow(S32 x, S32 y, U8 arrow_type, color c, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    polygon_vertex v[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (arrow_type)
    {
        case 0: /* Left */
            v[0].x = x + 0;
            v[0].y = y + (height >> 1);
            v[1].x = x + width;
            v[1].y = y + 0;
            v[2].x = x + width;
            v[2].y = y + height;
            flat_triangle_fill(v, c);
            break;

        case 1: /* Right */
            v[0].x = x + width;
            v[0].y = y + (height >> 1);
            v[1].x = x + 0;
            v[1].y = y + 0;
            v[2].x = x + 0;
            v[2].y = y + height;
            flat_triangle_fill(v, c);
            break;

        case 2: /* Up */
            v[0].x = x + (width >> 1);
            v[0].y = y + 0;
            v[1].x = x;
            v[1].y = y + height;
            v[2].x = x + width;
            v[2].y = y + height;
            flat_triangle_fill(v, c);
            break;

        case 3: /* Down */
            v[0].x = x + (width >> 1);
            v[0].y = y + height;
            v[1].x = x + 0;
            v[1].y = y + 0;
            v[2].x = x + width;
            v[2].y = y + 0;
            flat_triangle_fill(v, c);
            break;
    }
}


/************************************************************************/
/* UnUsed Code - designed change, these might be removed in the future  */
/************************************************************************/
#define TEST_SUB_LCD_GRAPHICS_CONTEXT(gc) (((gc)==&sub_LCD_device_bitmap)?(1):(0))
#define TEST_MAIN_LCD_GRAPHICS_CONTEXT(gc)   (((gc)==&main_LCD_device_bitmap)?(1):(0))

#define SWITCH_GRAPHICS_CONTEXT(gc, flag)                                              \
      {  flag=0;                                                                       \
         if(current_LCD_device_bitmap!=gc)                                             \
         {  flag=1;                                                                    \
            current_saved_LCD_device_bitmap=current_LCD_device_bitmap;                 \
            if(gc==&sub_LCD_device_bitmap) UI_set_sub_LCD_graphics_context();          \
            else UI_set_main_LCD_graphics_context();                                   \
         }                                                                             \
      }

#define  RESTORE_GRAPHICS_CONTEXT(flag)                                                \
      {  if(flag)                                                                      \
         {  if(current_saved_LCD_device_bitmap==&sub_LCD_device_bitmap)                \
               UI_set_sub_LCD_graphics_context();                                      \
            else                                                                       \
               UI_set_main_LCD_graphics_context();                                     \
         }                                                                             \
      }

#define GET_GRAPHICS_CONTEXT(gc) (gc)=(bitmap*)(current_LCD_device_bitmap);

/************************************************************************/
/* Usable Code                                                         */
/************************************************************************/

void (*_ui_text_putpixel) (S32 x, S32 y, color c);
void (*_ui_text_putpixel_unconditional) (S32 x, S32 y, color c);

/* This functions is extern by pixcomFontEngine.c */
/* It set the actual draw color before calling ShowChar() */


/*****************************************************************************
 * FUNCTION
 *  UI_set_current_text_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_current_text_color(color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_text_color = c;
}

/************************************************************************/
/* Primitive Drawing                                                    */
/************************************************************************/
/* Pixtel's Draw Primitive Function */


/*****************************************************************************
 * FUNCTION
 *  UI_putpixel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_putpixel(S32 x, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_point(x, y, gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha), c.r, c.g, c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_putpixel_alpha
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_putpixel_alpha(S32 x, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_point(x, y, gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha), c.r, c.g, c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_vertical_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 *  x       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_vertical_line(S32 y1, S32 y2, S32 x, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_line(x, y1, x, y2, gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha), c.r, c.g, c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_horizontal_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  x2      [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_horizontal_line(S32 x1, S32 x2, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_line(x1, y, x2, y, gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha), c.r, c.g, c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_dotted_horizontal_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  x2      [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_dotted_horizontal_line(S32 x1, S32 x2, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = x1; i <= x2; i = i + 3)
    {
        UI_putpixel(i, y, c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_dotted_vertical_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 *  x       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_dotted_vertical_line(S32 y1, S32 y2, S32 x, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (y1>y2) */
    for (i = y1; i <= y2; i = i + 3)
    {
        UI_putpixel(x, i, c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_dashed_horizontal_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  x2      [IN]        
 *  y       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_dashed_horizontal_line(S32 x1, S32 x2, S32 y, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = x1; i <= x2; i = i + 6)
    {
        UI_putpixel(i, y, c);
        if ((i + 1) > x2)
        {
            return;
        }
        UI_putpixel(i + 1, y, c);
        if ((i + 2) > x2)
        {
            return;
        }
        UI_putpixel(i + 2, y, c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_dashed_vertical_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 *  x       [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_dashed_vertical_line(S32 y1, S32 y2, S32 x, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = y1; i <= y2; i = i + 6)
    {
        UI_putpixel(x, i, c);
        if ((i + 1) > y2)
        {
            return;
        }
        UI_putpixel(x, i + 1, c);
        if ((i + 2) > y2)
        {
            return;
        }
        UI_putpixel(x, i + 2, c);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_dotted_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_dotted_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_draw_dotted_horizontal_line(x1, x2, y1, c);
    UI_draw_dotted_horizontal_line(x1, x2, y2, c);
    UI_draw_dotted_vertical_line(y1, y2, x1, c);
    UI_draw_dotted_vertical_line(y1, y2, x2, c);
    UI_putpixel(x2, y2, c);
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_dashed_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_dashed_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_draw_dashed_horizontal_line(x1, x2, y1, c);
    UI_draw_dashed_horizontal_line(x1, x2, y2, c);
    UI_draw_dashed_vertical_line(y1, y2, x1, c);
    UI_draw_dashed_vertical_line(y1, y2, x2, c);
    UI_putpixel(x2, y2, c);
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_horizontal_line_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1              [IN]        
 *  y2              [IN]        
 *  x               [IN]        
 *  c               [IN]        
 *  type_line       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_horizontal_line_type(S32 y1, S32 y2, S32 x, color c, S32 type_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type_line)
    {
        case 0: /* NORMAL */
            UI_draw_horizontal_line(y1, y2, x, c);
            break;
        case 1: /* DOTTED */
            UI_draw_dotted_horizontal_line(y1, y2, x, c);
            break;
        case 2: /* DASHED */
            UI_draw_dashed_horizontal_line(y1, y2, x, c);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_vertical_line_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1              [IN]        
 *  y2              [IN]        
 *  x               [IN]        
 *  c               [IN]        
 *  type_line       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_vertical_line_type(S32 y1, S32 y2, S32 x, color c, S32 type_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type_line)
    {
        case 0: /* NORMAL */
            UI_draw_vertical_line(y1, y2, x, c);
            break;
        case 1: /* DOTTED */
            UI_draw_dotted_vertical_line(y1, y2, x, c);
            break;
        case 2: /* DASHED */
            UI_draw_dashed_vertical_line(y1, y2, x, c);
            break;
    }
}

void UI_draw_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c);


/*****************************************************************************
 * FUNCTION
 *  UI_draw_rectangle_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  c               [IN]        
 *  type_line       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_rectangle_type(S32 x1, S32 y1, S32 x2, S32 y2, color c, S32 type_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type_line)
    {
        case 0:
            UI_draw_rectangle(x1, y1, x2, y2, c);
            break;
        case 1: /* dottted */
            UI_draw_dotted_rectangle(x1, y1, x2, y2, c);
            break;
        case 2: /* dashed */
            UI_draw_dashed_rectangle(x1, y1, x2, y2, c);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_fill_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_fill_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha), c.r, c.g, c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_draw_rectangle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_draw_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(UI_translate_gui_alpha_to_gdi_alpha(c.alpha), c.r, c.g, c.b));
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_text_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_text_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set clip region */
    gdi_layer_set_text_clip(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_clip(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_layer_get_clip(&x1, &y1, &x2, &y2);

    /* still keep UI_clip info for pixtel show image for file
       this shall be remove when integrate font into gdi_font */

    UI_clip_x1 = x1;
    UI_clip_y1 = y1;
    UI_clip_x2 = x2;
    UI_clip_y2 = y2;
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_clip_with_bounding_box
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  bx1     [IN]        
 *  by1     [IN]        
 *  bx2     [IN]        
 *  by2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_clip_with_bounding_box(S32 x1, S32 y1, S32 x2, S32 y2, S32 bx1, S32 by1, S32 bx2, S32 by2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x1 < bx1)
    {
        x1 = bx1;
    }
    if (y1 < by1)
    {
        y1 = by1;
    }
    if (x2 > bx2)
    {
        x2 = bx2;
    }
    if (y2 > by2)
    {
        y2 = by2;
    }
    UI_set_clip(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  UI_reset_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_reset_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();

    UI_clip_x1 = 0;
    UI_clip_y1 = 0;
    UI_clip_x2 = UI_device_width - 1;
    UI_clip_y2 = UI_device_height - 1;

}


/*****************************************************************************
 * FUNCTION
 *  UI_reset_text_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_reset_text_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_text_clip();
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_text_clip
 * DESCRIPTION
 *  Deprecated. Currently "text clip" and "clip" are the same.
 * PARAMETERS
 *  x1      [OUT]     
 *  y1      [OUT]     
 *  x2      [OUT]     
 *  y2      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void UI_get_text_clip(S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_text_clip(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [OUT]     
 *  y1      [OUT]     
 *  x2      [OUT]     
 *  y2      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void UI_get_clip(S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  UI_push_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_push_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
}


/*****************************************************************************
 * FUNCTION
 *  UI_pop_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_pop_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  UI_push_text_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_push_text_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_text_clip();
}


/*****************************************************************************
 * FUNCTION
 *  UI_pop_text_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_pop_text_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_pop_text_clip();
}


/*****************************************************************************
 * FUNCTION
 *  _read_image_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S32 _read_image_length(U8 *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rvalue = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image == NULL)
    {
        return ((S32) 0);
    }
    else
    {
        rvalue |= (U32) (image[2]);
        rvalue |= (U32) ((U32) image[3] << 8);
        rvalue |= (U32) ((U32) image[4] << 16);
        return ((S32) rvalue);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_text_clip_preset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_text_clip_preset(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_x1, prev_y1, prev_x2, prev_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_text_clip(&prev_x1, &prev_y1, &prev_x2, &prev_y2);

    if (x1 > prev_x1)
    {
        prev_x1 = x1;
    }
    if (y1 > prev_y1)
    {
        prev_y1 = y1;
    }
    if (x2 < prev_x2)
    {
        prev_x2 = x2;
    }
    if (y2 < prev_y2)
    {
        prev_y2 = y2;
    }

    gdi_layer_set_text_clip(prev_x1, prev_y1, prev_x2, prev_y2);

}


/*****************************************************************************
 * FUNCTION
 *  UI_set_clip_preset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_clip_preset(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_x1, prev_y1, prev_x2, prev_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_clip(&prev_x1, &prev_y1, &prev_x2, &prev_y2);

    if (x1 > prev_x1)
    {
        prev_x1 = x1;
    }
    if (y1 > prev_y1)
    {
        prev_y1 = y1;
    }
    if (x2 < prev_x2)
    {
        prev_x2 = x2;
    }
    if (y2 < prev_y2)
    {
        prev_y2 = y2;
    }

    gdi_layer_set_clip(prev_x1, prev_y1, prev_x2, prev_y2);

}


/*****************************************************************************
 * FUNCTION
 *  UI_set_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_font(UI_font_type f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Let UI_font point to &static_font instead of input parameter */ 
    static stFontAttribute static_font;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static_font = *f;
    UI_font = &static_font;
    SetFont(static_font, 0);
}


/*****************************************************************************
 * FUNCTION
 *  UI_printf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_printf(const S8 *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rvalue;
    U8 temp_buffer[1024];
    va_list l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(l, format);
    rvalue = vsprintf((S8*) temp_buffer + (sizeof(temp_buffer) / 2) /* UI_printf_buffer */ , format, l);
    mmi_asc_to_ucs2((S8*) temp_buffer, (S8*) temp_buffer + (sizeof(temp_buffer) / 2) /* UI_printf_buffer */ );
    UI_set_current_text_color(UI_text_color);
    ShowString(UI_text_x, UI_text_y, *UI_font, 0, (U8*) temp_buffer, UI_text_height);
    return (rvalue);
}


/*****************************************************************************
 * FUNCTION
 *  UI_sprintf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_sprintf(UI_string_type s, const S8 *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rvalue;
    U8 temp_buffer[1024];
    va_list l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(l, format);
    rvalue = vsprintf((S8*) temp_buffer, format, l);
    mmi_asc_to_ucs2((S8*) s, (S8*) temp_buffer);
    return (rvalue);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_text(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text == NULL)
    {
        return;
    }
    UI_set_current_text_color(UI_text_color);
    ShowString(UI_text_x, UI_text_y, *UI_font, 0, (U8*) text, UI_text_height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_bordered_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_bordered_text(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text == NULL)
    {
        return;
    }
    UI_set_current_text_color(UI_text_color);
    ShowStringBordered(UI_text_x, UI_text_y, *UI_font, 0, (U8*) text, UI_text_height);
}

/* MTK Terry Add to Support print n characters */


/*****************************************************************************
 * FUNCTION
 *  UI_print_text_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  n           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_text_n(UI_string_type text, int n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text == NULL)
    {
        return;
    }
    UI_set_current_text_color(UI_text_color);
    ShowString_n(UI_text_x, UI_text_y, *UI_font, 0, (U8*) text, n, UI_text_height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_bordered_text_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  n           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_bordered_text_n(UI_string_type text, int n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text == NULL)
    {
        return;
    }
    UI_set_current_text_color(UI_text_color);
    ShowStringBordered_n(UI_text_x, UI_text_y, *UI_font, 0, (U8*) text, n, UI_text_height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_bordered_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_bordered_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_buffer[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_buffer[0] = (U8) c;
    temp_buffer[1] = (U8) (c >> 8);
    temp_buffer[2] = '\0';
    temp_buffer[3] = 0;
    UI_current_text_color = UI_text_color;
    ShowStringBordered(UI_text_x, UI_text_y, *UI_font, 0, (U8*) temp_buffer, 0);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_character(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_buffer[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_buffer[0] = (U8) c;
    temp_buffer[1] = (U8) (c >> 8);
    temp_buffer[2] = '\0';
    temp_buffer[3] = 0;
    UI_current_text_color = UI_text_color;
    ShowString(UI_text_x, UI_text_y, *UI_font, 0, (U8*) temp_buffer, 0);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_character_at_xy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_character_at_xy(UI_character_type c, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_text_color = UI_text_color;
    mmi_fe_show_char_at_xy(x, y, *UI_font, 0, c);
}


/*****************************************************************************
 * FUNCTION
 *  UI_print_stacked_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  curCh       [IN]        
 *  pre2Ch      [IN]        
 *  preCh       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_stacked_character(UI_character_type curCh, UI_character_type pre2Ch, UI_character_type preCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_text_color = UI_text_color;
    ShowStackedChar(UI_text_x, UI_text_y, *UI_font, 0, curCh, 0, 0, pre2Ch, preCh);

}


/*****************************************************************************
 * FUNCTION
 *  UI_print_bordered_stacked_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  curCh       [IN]        
 *  pre2Ch      [IN]        
 *  preCh       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_print_bordered_stacked_character(UI_character_type curCh, UI_character_type pre2Ch, UI_character_type preCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_current_text_color = UI_text_color;
    ShowStackedChar(UI_text_x, UI_text_y, *UI_font, 0, curCh, 0, 1, pre2Ch, preCh);

}


/*****************************************************************************
 * FUNCTION
 *  UI_move_text_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_move_text_cursor(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_text_x = x;
    UI_text_y = y;
    UI_text_height = 0;
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_line_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_line_height(S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_text_height = height;
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_text_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_text_color(color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_text_color = c;
    UI_current_text_color = UI_text_color;
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_text_border_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_text_border_color(color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_text_border_color = c;
}


/*****************************************************************************
 * FUNCTION
 *  UI_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *UI_malloc(size_t size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (OslMalloc(size));
}


/*****************************************************************************
 * FUNCTION
 *  UI_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void UI_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr != NULL)
    {
        OslMfree(ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_font_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_font_height(UI_font_type f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (Get_FontHeight(*f, (U8) gCurrLangIndex));
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_character_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_character_width(UI_character_type c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_CharWidthHeight(c, &w, &h);
    return (w);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_character_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_character_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (Get_CharHeight());
}


/*****************************************************************************
 * FUNCTION
 *  UI_measure_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c           [IN]        
 *  width       [OUT]         
 *  height      [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void UI_measure_character(UI_character_type c, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_CharWidthHeight(c, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_string_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_string_width(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight((U8*) text, &w, &h);
    return (w);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_string_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_string_height(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(text);
    return (Get_CharHeight());
}


/*****************************************************************************
 * FUNCTION
 *  UI_measure_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  width       [OUT]         
 *  height      [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void UI_measure_string(UI_string_type text, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight((U8*) text, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_string_width_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  n           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_string_width_n(UI_string_type text, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_n((U8*) text, n, &w, &h);
    return (w);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_string_width_w
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  w           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_string_width_w(UI_string_type text, S32 w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_w((U8*) text, w, &sw, &sh);
    return (sw);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_string_width_wn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  w           [IN]        
 *  n           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_string_width_wn(UI_string_type text, S32 w, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sw, sh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_wn((U8*) text, w, n, &sw, &sh);
    return (sw);
}


/*****************************************************************************
 * FUNCTION
 *  UI_measure_string_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  n           [IN]        
 *  width       [OUT]         
 *  height      [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void UI_measure_string_n(UI_string_type text, S32 n, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_n((U8*) text, n, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_measure_string_w
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  w           [IN]        
 *  width       [OUT]         
 *  height      [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void UI_measure_string_w(UI_string_type text, S32 w, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_w((U8*) text, w, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_measure_string_wn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  w           [IN]        
 *  n           [IN]        
 *  width       [OUT]         
 *  height      [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void UI_measure_string_wn(UI_string_type text, S32 w, S32 n, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight_wn((U8*) text, w, n, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_strlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_strlen(UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text == NULL)
    {
        return (0);
    }
    else
    {
        return (mmi_ucs2strlen((S8*) text));
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_strcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text1       [IN]        
 *  text2       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type UI_strcpy(UI_string_type text1, UI_string_type text2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((text1 == NULL) || (text2 == NULL))
    {
        return (NULL);
    }
    else
    {
        return ((UI_string_type) mmi_ucs2cpy((S8*) text1, (S8*) text2));
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_strncpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text1       [IN]        
 *  text2       [IN]        
 *  n           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type UI_strncpy(UI_string_type text1, UI_string_type text2, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((text1 == NULL) || (text2 == NULL))
    {
        return (NULL);
    }
    else
    {
        return ((UI_string_type) mmi_ucs2ncpy((S8*) text1, (S8*) text2, n));
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_strcat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text1       [IN]        
 *  text2       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type UI_strcat(UI_string_type text1, UI_string_type text2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((text1 == NULL) || (text2 == NULL))
    {
        return (NULL);
    }
    else
    {
        return ((UI_string_type) mmi_ucs2cat((S8*) text1, (S8*) text2));
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_strcmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text1       [IN]        
 *  text2       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_strcmp(UI_string_type text1, UI_string_type text2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((text1 == NULL) || (text2 == NULL))
    {
        return (-1);
    }
    else
    {
        return (mmi_ucs2cmp((S8*) text1, (S8*) text2));
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_strncmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text1       [IN]        
 *  text2       [IN]        
 *  n           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_strncmp(UI_string_type text1, UI_string_type text2, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((text1 == NULL) || (text2 == NULL))
    {
        return (-1);
    }
    else
    {
        return (mmi_ucs2ncmp((S8*) text1, (S8*) text2, n));
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_memcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  d       [OUT]         
 *  s       [IN]        
 *  n       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *UI_memcpy(void *d, const void *s, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (memcpy(d, s, n));
}


/*****************************************************************************
 * FUNCTION
 *  HW_itoa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value       [IN]        
 *  s           [OUT]         
 *  radix       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *HW_itoa(S32 value, S8 *s, S32 radix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s == NULL)
    {
        return (NULL);
    }
    else
    {
        /* JL/Pluto */
#define LEN 20

        U8 *temp;
        U32 rem;
        static U8 rev[LEN + 1];

        rev[LEN] = 0;
        if (value == 0)
        {
            (s)[0] = '0';
            ++(s);
            (s)[0] = '\0';
            return s;
        }
        temp = &rev[LEN];
        while (value)
        {
            rem = value % radix;
            if (rem < 10)
            {
                *--temp = (U8) (rem + '0');
            }
            else if (radix == 16)
            {
                *--temp = "abcdef"[rem - 10];
            }
            value /= radix;
        }
        while (*temp)
        {
            (s)[0] = *temp++;
            ++(s);
        }
        (s)[0] = '\0';
        return s;
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_itoa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value       [IN]        
 *  s           [IN]        
 *  radix       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_string_type UI_itoa(S32 value, UI_string_type s, S32 radix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s == NULL)
    {
        return (NULL);
    }
    else
    {
        S8 ts[32];

        HW_itoa(value, ts, radix);
        mmi_asc_to_ucs2((S8*) s, (S8*) ts);
        return (s);
    }
}


/*****************************************************************************
 * FUNCTION
 *  hw_atoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 hw_atoi(const S8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n = 0;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (s[i] != '\0')
    {
        n *= 10;
        n += s[i] - '0';
        i++;
    }
    return n;
}


/*****************************************************************************
 * FUNCTION
 *  HW_atoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 HW_atoi(const S8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n = 0;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (s[i] != '\0')
    {
        n *= 10;
        n += s[i] - '0';
        i++;
    }
    return n;
}


/*****************************************************************************
 * FUNCTION
 *  UI_atoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_atoi(UI_string_type s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ts[32];
    S32 conv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s == NULL)
    {
        return (0);
    }
    else
    {
        mmi_ucs2_to_asc(ts, (S8*) s);
        conv = HW_atoi((S8*) ts);
        return (conv);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_transparent_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  r       [IN]        
 *  g       [IN]        
 *  b       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_transparent_color_type UI_transparent_color(U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(r);
    UI_UNUSED_PARAMETER(g);
    UI_UNUSED_PARAMETER(b);
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  UI_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  r       [IN]        
 *  g       [IN]        
 *  b       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
color UI_color(U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = r;
    c.b = b;
    c.g = g;
    c.alpha = 100;
    return (c);
}


/*****************************************************************************
 * FUNCTION
 *  UI_color32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  r           [IN]        
 *  g           [IN]        
 *  b           [IN]        
 *  alpha       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
color UI_color32(U8 r, U8 g, U8 b, U8 alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = r;
    c.b = b;
    c.g = g;
    c.alpha = alpha;
    return (c);
}


/*****************************************************************************
 * FUNCTION
 *  UI_color_RGB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 *  r       [OUT]         
 *  g       [OUT]         
 *  b       [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void UI_color_RGB(color c, U8 *r, U8 *g, U8 *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *r = c.r;
    *g = c.g;
    *b = c.b;
}


/*****************************************************************************
 * FUNCTION
 *  UI_lock_double_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_lock_double_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  UI_unlock_double_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_unlock_double_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  UI_BLT_double_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_BLT_double_buffer(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  MMI_system_keybord_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_code        [IN]        
 *  key_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMI_system_keybord_handler(S32 key_code, S32 key_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(key_code);
    UI_UNUSED_PARAMETER(key_state);
}


#if(!WINGUI_USE_OS_TIMERS)

/* Software timers required by the UI  */

typedef struct _timer
{
    S32 counter;
    void (*callback) (void);
} timer;

#include "TimerEvents.h"

timer timer_functions[MAX_TIMERS];
S32 n_timers = 0;
S32 patch_timer_counter = 0;
U8 UI_timer_active = 1;

/*****************************************************************************
 * FUNCTION
 *  SW_StartTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SW_StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartNonAlignTimer(timerid, delay, funcPtr);
}


/*****************************************************************************
 * FUNCTION
 *  SW_StopTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timerid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SW_StopTimer(U16 timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(timerid);
}

void UI_timer(void);


/*****************************************************************************
 * FUNCTION
 *  UI_timer_control
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SW_StartTimer(UI_ELEMENTS_TIMER, UI_TIMER_RESOLUTION, UI_timer_control);
    UI_timer_active = 1;
    UI_timer();
}


/*****************************************************************************
 * FUNCTION
 *  UI_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  count           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_start_timer(S32 count, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* start the OS/hardware timer if necessary                    */
    if (n_timers >= MAX_TIMERS)
    {
        return;
    }
    /* Patch for the timer start bug:
       Note, for some reasons, the OS timer will not call UI_timer_control.
       So, when UI_start_timer is called again, we'll check if the OS timer
       is stuck. If its stuck, then we'll start the OS timer again       */
    if (n_timers > 0)
    {
        if (timer_functions[0].counter == patch_timer_counter)
        {
            SW_StartTimer(UI_ELEMENTS_TIMER, UI_TIMER_RESOLUTION, UI_timer_control);
            UI_timer_active = 1;
        }
    }
    if ((n_timers == 0) || (!UI_timer_active))
    {
        SW_StartTimer(UI_ELEMENTS_TIMER, UI_TIMER_RESOLUTION, UI_timer_control);
        UI_timer_active = 1;
    }
    else
    {   /* check if this function has already been hooked. If yes, remove it */
        for (i = 0; i < n_timers; i++)
        {
            if (timer_functions[i].callback == callback)
            {
                for (j = i; j < n_timers - 1; j++)
                {
                    timer_functions[j] = timer_functions[j + 1];
                }
                n_timers--;
            }
        }
    }
    timer_functions[n_timers].counter = count / UI_TIMER_RESOLUTION;
    timer_functions[n_timers].callback = callback;
    n_timers++;
    /* Patch for the timer start bug                               */
    patch_timer_counter = timer_functions[0].counter;
}


/*****************************************************************************
 * FUNCTION
 *  UI_cancel_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_cancel_timer(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n_timers <= 0)
    {
        return;
    }
    /* If the callback function has already been hooked, remove it          */
    for (i = 0; i < n_timers; i++)
    {
        if (timer_functions[i].callback == callback)
        {
            for (j = i; j < n_timers - 1; j++)
            {
                timer_functions[j] = timer_functions[j + 1];
            }
            n_timers--;
        }
    }
    /* if all software timers have expired, release the OS/hardware timer      */
    if (n_timers == 0)
    {
        SW_StopTimer(UI_ELEMENTS_TIMER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_cancel_all_timers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_cancel_all_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_timers = 0;
    SW_StopTimer(UI_ELEMENTS_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  UI_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void (*callback) (void);

    if (n_timers == 0)
    {
        if (UI_timer_active)
        {
            SW_StopTimer(UI_ELEMENTS_TIMER);
        }
        return;
    }
    for (i = 0; i < n_timers; i++)
    {
        timer_functions[i].counter--;
        if (timer_functions[i].counter <= 0)
        {
            callback = timer_functions[i].callback;
            for (j = i; j < n_timers - 1; j++)
            {
                timer_functions[j] = timer_functions[j + 1];
            }
            n_timers--;
            callback();
        }
    }
    /* if all software timers have expired, release the OS/hardware timer      */
    if (n_timers == 0)
    {
        SW_StopTimer(UI_ELEMENTS_TIMER);
    }
}

#else /* (!WINGUI_USE_OS_TIMERS) */ 

/* Externals   */

U8 HW_alignment_timer_flag = TIMER_IS_ALIGNMENT;


/*****************************************************************************
 * FUNCTION
 *  UI_enable_alignment_timers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_enable_alignment_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_alignment_timer_flag = TIMER_IS_ALIGNMENT;
}


/*****************************************************************************
 * FUNCTION
 *  UI_disable_alignment_timers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_disable_alignment_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_alignment_timer_flag = TIMER_IS_NO_ALIGNMENT;
}


/*****************************************************************************
 * FUNCTION
 *  HW_StartTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HW_StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartNonAlignTimer(timerid, delay, funcPtr);
}


/*****************************************************************************
 * FUNCTION
 *  HW_StopTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timerid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HW_StopTimer(U16 timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(timerid);
}

#define MAX_UI_TIMERS      (sizeof(UI_timer_IDs)/sizeof(UI_timer_IDs[0]))

U16 UI_timer_IDs[] = 
{
    UI_TIMER_ID_BASE + 0,
    UI_TIMER_ID_BASE + 1,
    UI_TIMER_ID_BASE + 2,
    UI_TIMER_ID_BASE + 3,
    UI_TIMER_ID_BASE + 4,
    UI_TIMER_ID_BASE + 5,
    UI_TIMER_ID_BASE + 6,
    UI_TIMER_ID_BASE + 7,
    UI_TIMER_ID_BASE + 8,
    UI_TIMER_ID_BASE + 9,
};

void (*UI_timer_callbacks[MAX_UI_TIMERS]) (void);

/* Flag=0 indicates timer is available */
U8 UI_timer_ID_flags[MAX_UI_TIMERS];

/* OS callback functions   */


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[0]);
    UI_timer_ID_flags[0] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[0] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[1]);
    UI_timer_ID_flags[1] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[1] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[2]);
    UI_timer_ID_flags[2] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[2] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[3]);
    UI_timer_ID_flags[3] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[3] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_4
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[4]);
    UI_timer_ID_flags[4] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[4] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[5]);
    UI_timer_ID_flags[5] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[5] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[6]);
    UI_timer_ID_flags[6] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[6] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_7(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[7]);
    UI_timer_ID_flags[7] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[7] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[8]);
    UI_timer_ID_flags[8] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[8] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_timer_callback_9
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_timer_callback_9(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HW_StopTimer(UI_timer_IDs[9]);
    UI_timer_ID_flags[9] = 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
#endif

    UI_timer_callbacks[9] ();

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_FALSE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  UI_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  count           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_start_timer(S32 count, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 all_timers_used = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if this function has already been hooked. If yes, remove it */
    for (i = 0; i < MAX_UI_TIMERS; i++)
    {
        if ((UI_timer_ID_flags[i]) && (UI_timer_callbacks[i] == callback))
        {
            HW_StopTimer(UI_timer_IDs[i]);
            UI_timer_callbacks[i] = UI_dummy_function;
            UI_timer_ID_flags[i] = 0;
        }
    }

    /* Check for free timer       */
    for (i = 0; i < MAX_UI_TIMERS; i++)
    {
        if (UI_timer_ID_flags[i] == 0)
        {
            all_timers_used = 0;
            break;
        }
    }
    /* If all timers are used, return   */
    if (all_timers_used)
    {
        return;
    }

    /* Hook the callback function and start the OS timer  */
    UI_timer_callbacks[i] = callback;
    switch (i)
    {
        case 0:
            HW_StartTimer(UI_timer_IDs[0], (U16) count, UI_timer_callback_0);
            break;
        case 1:
            HW_StartTimer(UI_timer_IDs[1], (U16) count, UI_timer_callback_1);
            break;
        case 2:
            HW_StartTimer(UI_timer_IDs[2], (U16) count, UI_timer_callback_2);
            break;
        case 3:
            HW_StartTimer(UI_timer_IDs[3], (U16) count, UI_timer_callback_3);
            break;
        case 4:
            HW_StartTimer(UI_timer_IDs[4], (U16) count, UI_timer_callback_4);
            break;
        case 5:
            HW_StartTimer(UI_timer_IDs[5], (U16) count, UI_timer_callback_5);
            break;
        case 6:
            HW_StartTimer(UI_timer_IDs[6], (U16) count, UI_timer_callback_6);
            break;
        case 7:
            HW_StartTimer(UI_timer_IDs[7], (U16) count, UI_timer_callback_7);
            break;
        case 8:
            HW_StartTimer(UI_timer_IDs[8], (U16) count, UI_timer_callback_8);
            break;
        case 9:
            HW_StartTimer(UI_timer_IDs[9], (U16) count, UI_timer_callback_9);
            break;
    }

    /* Set the timer to busy   */
    UI_timer_ID_flags[i] = 1;
}


/*****************************************************************************
 * FUNCTION
 *  UI_cancel_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_cancel_timer(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if this callback function is hooked */
    for (i = 0; i < MAX_UI_TIMERS; i++)
    {
        if (UI_timer_ID_flags[i] && UI_timer_callbacks[i] == callback)
        {
            UI_timer_ID_flags[i] = 0;
            HW_StopTimer(UI_timer_IDs[i]);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  UI_cancel_all_timers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_cancel_all_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_UI_TIMERS; i++)
    {
        if (UI_timer_ID_flags[i])
        {
            UI_timer_ID_flags[i] = 0;
            HW_StopTimer(UI_timer_IDs[i]);
            break;
        }
    }
}

#endif /* (!WINGUI_USE_OS_TIMERS) */ 

/* Internal bitmap format: most API are replaced by GDI */

void (*UI_hide_animation_frame_function) (void) = UI_dummy_function;


/*****************************************************************************
 * FUNCTION
 *  _measure_bitmap
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  b           [IN]     
 *  width       [OUT]     
 *  height      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void _measure_bitmap(bitmap *b, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b == NULL)
    {
        *width = 0;
        *height = 0;
    }
    else
    {
        *width = b->xsize;
        *height = b->ysize;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _show_bitmap
 * DESCRIPTION
 *  Deprecated by GDI gdi_image_cache_bmp_draw()
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  b       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void _show_bitmap(S32 x1, S32 y1, bitmap *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 layer_clip_x1;
    S32 layer_clip_x2;
    S32 layer_clip_y1;
    S32 layer_clip_y2;
    S32 start_x, end_x, start_y, end_y;
    U8 *layer_buf_ptr;
    U8 *bmp_data_ptr;
    S32 x2, y2;
    S32 vlaid_width;
    S32 byte_per_pixel;

    /* set active layer to base layer for pixtel's drawing */
    gdi_handle base_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_push_and_set_active(base_handle);

    bmp_data_ptr = b->data;
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);
    gdi_layer_get_clip(&layer_clip_x1, &layer_clip_y1, &layer_clip_x2, &layer_clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    byte_per_pixel = gdi_layer_get_bit_per_pixel()>>3;

    layer_clip_x1 -= layer_offset_x;
    layer_clip_x2 -= layer_offset_x;
    layer_clip_y1 -= layer_offset_y;
    layer_clip_y2 -= layer_offset_y;

    x2 = x1 + b->xsize - 1;
    y2 = y1 + b->ysize - 1;

    /* out of clip region */
    if ((x1 > layer_clip_x2) || (y1 > layer_clip_y2) || (x2 < layer_clip_x1) || (y2 < layer_clip_y1))
    {
        gdi_layer_pop_and_restore_active();
        return;
    }

    /* Calculate valid region */
    if (x1 < layer_clip_x1)
    {
        start_x = layer_clip_x1;
    }
    else
    {
        start_x = x1;
    }

    if (x2 > layer_clip_x2)
    {
        end_x = layer_clip_x2;
    }
    else
    {
        end_x = x2;
    }

    if (y1 < layer_clip_y1)
    {
        start_y = layer_clip_y1;
    }
    else
    {
        start_y = y1;
    }

    if (y2 > layer_clip_y2)
    {
        end_y = layer_clip_y2;
    }
    else
    {
        end_y = y2;
    }

    /* find update width */
    vlaid_width = end_x - start_x + 1;

    /* shift to bmp buffer start position */
    bmp_data_ptr += (start_y - y1) * b->row_bytes + (start_x - x1) * byte_per_pixel;

    /* shift to layer buffer start position */
    layer_buf_ptr += ((start_y - layer_offset_y) * layer_width + (start_x - layer_offset_x)) * byte_per_pixel;

    /* fill bitmap buffer */
    for (i = start_y; i <= end_y; i++)
    {
        memcpy(layer_buf_ptr, bmp_data_ptr, vlaid_width * byte_per_pixel);
        bmp_data_ptr += b->row_bytes;
        layer_buf_ptr += layer_width * byte_per_pixel;
    }

    /* restore current active layer */
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  _get_bitmap
 * DESCRIPTION
 *  Cache screen data to bitmap 'b'
 *  Deprecated by GDI gdi_image_cache_bmp_get()
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 *  b       [OUT]         
 * RETURNS
 *  void
 *****************************************************************************/
void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 layer_clip_x1;
    S32 layer_clip_x2;
    S32 layer_clip_y1;
    S32 layer_clip_y2;
    S32 start_x, end_x, start_y, end_y;
    U8 *layer_buf_ptr;
    U8 *bmp_data_ptr;
    S32 byte_per_pixel;

    /* set active layer to base layer for pixtel's drawing */
    gdi_handle base_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_push_and_set_active(base_handle);

    bmp_data_ptr = b->data;
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);

    gdi_layer_get_clip(&layer_clip_x1, &layer_clip_y1, &layer_clip_x2, &layer_clip_y2);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    byte_per_pixel = gdi_layer_get_bit_per_pixel()>>3;

    layer_clip_x1 -= layer_offset_x;
    layer_clip_x2 -= layer_offset_x;
    layer_clip_y1 -= layer_offset_y;
    layer_clip_y2 -= layer_offset_y;

    /* out of clip region */
    if ((x1 > layer_clip_x2) || (y1 > layer_clip_y2) || (x2 < layer_clip_x1) || (y2 < layer_clip_y1))
    {
        b->xsize = 0;
        b->xsize = 0;
        b->row_bytes = 0;

        gdi_layer_pop_and_restore_active();
        return;
    }

    /* Calculate valid region */
    if (x1 < layer_clip_x1)
    {
        start_x = layer_clip_x1;
    }
    else
    {
        start_x = x1;
    }

    if (x2 > layer_clip_x2)
    {
        end_x = layer_clip_x2;
    }
    else
    {
        end_x = x2;
    }

    if (y1 < layer_clip_y1)
    {
        start_y = layer_clip_y1;
    }
    else
    {
        start_y = y1;
    }

    if (y2 > layer_clip_y2)
    {
        end_y = layer_clip_y2;
    }
    else
    {
        end_y = y2;
    }

    /* fill bitmap info */
    b->xsize = end_x - start_x + 1;
    b->ysize = end_y - start_y + 1;
    b->row_bytes = b->xsize * byte_per_pixel;   /* 16-bit specific   */

    /* find source buffer start position of the active layer */

    /* shift to layer's coordiante */
    layer_offset_x = start_x - layer_offset_x;
    layer_offset_y = start_y - layer_offset_y;

    layer_buf_ptr += (layer_offset_y * layer_width + layer_offset_x) * byte_per_pixel;       /* 16-bit */

    /* fill bitmap buffer */
    for (i = 0; i < b->ysize; i++)
    {
        memcpy(bmp_data_ptr, layer_buf_ptr, b->row_bytes);
        bmp_data_ptr += b->row_bytes;
        layer_buf_ptr += layer_width * byte_per_pixel;   /* just to next row */
    }

    /* restore current active layer */
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  UI_dummy_hide_animation_function
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UI_dummy_hide_animation_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(x1);
    UI_UNUSED_PARAMETER(y1);
    UI_UNUSED_PARAMETER(x2);
    UI_UNUSED_PARAMETER(y2);
}


/*****************************************************************************
 * FUNCTION
 *  _measure_image
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  image       [IN]     
 *  width       [OUT]     
 *  height      [OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void _measure_image(U8 *image, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image == NULL)
    {
        return;
    }

    gdi_image_get_dimension((U8*) image, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_image_n_frames
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  image       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
S32 UI_get_image_n_frames(U8 *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bytestream bfile;
    S32 image_length /* ,n */ ;
    U8 image_identifier;
    S32 frame_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image == NULL)
    {
        return (0);
    }
    image_identifier = (U8) (image[0]);
    if (image_identifier == IMAGE_TYPE_INVALID)
    {
        return (0);
    }

    image_length = _read_image_length(image);
    bytestream_initialize(&bfile, (U8*) (image + 6), image_length);
    switch (image_identifier)
    {
        case IMAGE_TYPE_BMP:
        case IMAGE_TYPE_BMP_SEQUENCE:
        case IMAGE_TYPE_GIF:
        case IMAGE_TYPE_DEVICE_BITMAP:
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
        case IMAGE_TYPE_ABM:
        case IMAGE_TYPE_ABM_SEQUENCE:
        case IMAGE_TYPE_ABM_FILE_OFFSET:
        case IMAGE_TYPE_JPG:                
        case IMAGE_TYPE_AVI:                
        case IMAGE_TYPE_3GP:
        case IMAGE_TYPE_MP4:                
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        case IMAGE_TYPE_BMP_FILE_OFFSET:
        case IMAGE_TYPE_GIF_FILE_OFFSET:
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
            gdi_image_get_frame_count(image, &frame_count);
            return frame_count;
    }
    return (0);
}



/*****************************************************************************
 * FUNCTION
 *  _show_image
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  image       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void _show_image(S32 x, S32 y, U8 *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw(x, y, image);
}


/*****************************************************************************
 * FUNCTION
 *  _show_transparent_image
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  image       [IN]         
 *  t           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void _show_transparent_image(S32 x, S32 y, U8 *image, UI_transparent_color_type t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ignore transparent function and treat as normal image */
    gdi_image_draw(x, y, image);
}


/*****************************************************************************
 * FUNCTION
 *  _show_animation_frame
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  image               [IN]         
 *  frame_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 _show_animation_frame(S32 x, S32 y, U8 *image, S16 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 image_identifier;
    S32 ret;

    /* set active layer to base layer for pixtel's drawing */
    gdi_handle base_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image == NULL)
    {
        return (0);
    }

    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_push_and_set_active(base_handle);

    image_identifier = (U8) (image[0]);

    switch (image_identifier)
    {
        case IMAGE_TYPE_INVALID:
            break;

        case IMAGE_TYPE_BMP:
        case IMAGE_TYPE_BMP_SEQUENCE:
        case IMAGE_TYPE_GIF:
        case IMAGE_TYPE_DEVICE_BITMAP:
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
        case IMAGE_TYPE_ABM:        
        case IMAGE_TYPE_ABM_SEQUENCE:
        case IMAGE_TYPE_ABM_FILE_OFFSET:
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        case IMAGE_TYPE_BMP_FILE_OFFSET:
        case IMAGE_TYPE_GIF_FILE_OFFSET:
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */    
            ret = gdi_image_draw_animation_single_frame(x, y, image, (U16) frame_number);
            gdi_layer_pop_and_restore_active();

            if (ret == GDI_IMAGE_SUCCEED)
            {
                return (1);
            }
            else
            {
                return (0);
            }
    }

    /* restore current active layer */
    gdi_layer_pop_and_restore_active();
    return (1);

}


/*****************************************************************************
 * FUNCTION
 *  _show_transparent_animation_frame
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  image               [IN]         
 *  t                   [IN]        
 *  frame_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 _show_transparent_animation_frame(S32 x, S32 y, U8 *image, UI_transparent_color_type t, S16 frame_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* set active layer to base layer for pixtel's drawing */
    gdi_handle base_handle;

    U8 image_identifier;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image == NULL)
    {
        return (0);
    }

    gdi_layer_get_base_handle(&base_handle);
    gdi_layer_push_and_set_active(base_handle);

    image_identifier = (U8) (image[0]);
    switch (image_identifier)
    {
        case IMAGE_TYPE_INVALID:
            gdi_layer_pop_and_restore_active();
            return (0);

        case IMAGE_TYPE_BMP:
        case IMAGE_TYPE_BMP_SEQUENCE:
        case IMAGE_TYPE_GIF:
        case IMAGE_TYPE_DEVICE_BITMAP:
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
        case IMAGE_TYPE_ABM:
        case IMAGE_TYPE_ABM_SEQUENCE:
        case IMAGE_TYPE_ABM_FILE_OFFSET:
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        case IMAGE_TYPE_BMP_FILE_OFFSET:
        case IMAGE_TYPE_GIF_FILE_OFFSET:
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
            ret = gdi_image_draw_animation_single_frame(x, y, image, (U16) frame_number);

            gdi_layer_pop_and_restore_active();

            if (ret == GDI_IMAGE_SUCCEED)
            {
                return (1);
            }
            else
            {
                return (0);
            }
    }

    /* restore current active layer */
    gdi_layer_pop_and_restore_active();
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  UI_hide_animations
 * DESCRIPTION
 *  (Deprecated by GDI)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_hide_animations(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_stop_animation_all();
}

/* Character set functions */


/*****************************************************************************
 * FUNCTION
 *  UI_get_next_UCS2_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type UI_get_next_UCS2_character(UI_string_type *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c = **s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*s)++;
    return (c);
}


/*****************************************************************************
 * FUNCTION
 *  UI_get_previous_UCS2_character
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type UI_get_previous_UCS2_character(UI_string_type *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type c = **s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*s)--;
    return (c);
}

/************************************************************************/
/* LCD Context Swtich                                                   */
/************************************************************************/

/* this function will be called by categories */


/*****************************************************************************
 * FUNCTION
 *  UI_test_sub_LCD_graphics_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 UI_test_sub_LCD_graphics_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);

    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* UI wrappers to perform graphics context switching  */


/*****************************************************************************
 * FUNCTION
 *  UI_set_main_LCD_graphics_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_main_LCD_graphics_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);

    /* already is Main LCD, do nothing */
    if (act_lcd_handle == GDI_LCD_MAIN_LCD_HANDLE)
    {
        return;
    }

    /* set Main Lcd as active lcd */
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    current_LCD_device_bitmap = &main_LCD_device_bitmap;

    /* init UI golbal var for Main LCD */
    UI_device_width = MAIN_LCD_device_width;
    UI_device_height = MAIN_LCD_device_height;
    UI_clip_x1 = 0;
    UI_clip_x2 = UI_device_width - 1;
    UI_clip_y1 = 0;
    UI_clip_y2 = UI_device_height - 1;
    UI_old_clip_x1 = 0;
    UI_old_clip_y1 = 0;
    UI_old_clip_x2 = UI_device_width - 1;
    UI_old_clip_y2 = UI_device_height - 1;
    UI_text_x = 0;
    UI_text_y = 0;
}


/*****************************************************************************
 * FUNCTION
 *  UI_set_sub_LCD_graphics_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UI_set_sub_LCD_graphics_context(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd_handle);

    /* already is Main LCD, do nothing */
    if (act_lcd_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        return;
    }

    /* set Sub Lcd and active lcd */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    current_LCD_device_bitmap = &sub_LCD_device_bitmap;

    /* init UI golbal var for Sub LCD */
    UI_device_width = SUB_LCD_device_width;
    UI_device_height = SUB_LCD_device_height;
    UI_clip_x1 = 0;
    UI_clip_x2 = SUB_LCD_device_width - 1;
    UI_clip_y1 = 0;
    UI_clip_y2 = SUB_LCD_device_height - 1;
    UI_old_clip_x1 = 0;
    UI_old_clip_y1 = 0;
    UI_old_clip_x2 = SUB_LCD_device_width - 1;
    UI_old_clip_y2 = SUB_LCD_device_height - 1;
    UI_text_x = 0;
    UI_text_y = 0;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  setup_UI_wrappers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void setup_UI_wrappers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup the main LCD device bitmap */
    /* this is uses some where out side wingui, cant be removed */
    main_LCD_device_bitmap.xsize = MAIN_LCD_device_width;
    main_LCD_device_bitmap.ysize = MAIN_LCD_device_height;
    main_LCD_device_bitmap.color_depth = GDI_MAINLCD_BIT_PER_PIXEL;     /* internal use 565 */
    main_LCD_device_bitmap.row_bytes = (MAIN_LCD_device_width * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
    main_LCD_device_bitmap.palette = NULL;

#ifdef __MMI_SUBLCD__
    /* Setup the sub LCD device bitmap     */
    /* this is uses some where out side wingui, cant be removed */
    sub_LCD_device_bitmap.xsize = SUB_LCD_device_width;
    sub_LCD_device_bitmap.ysize = SUB_LCD_device_height;
    sub_LCD_device_bitmap.color_depth = GDI_SUBLCD_BIT_PER_PIXEL;       /* internal use 565 */
    sub_LCD_device_bitmap.row_bytes = (SUB_LCD_device_width * GDI_SUBLCD_BIT_PER_PIXEL) >> 3;
    sub_LCD_device_bitmap.palette = NULL;
#endif /* __MMI_SUBLCD__ */ 

    /* init Main LCD first */
    current_LCD_device_bitmap = &main_LCD_device_bitmap;

    /* init UI golbal var for Main LCD */
    UI_device_width = MAIN_LCD_device_width;
    UI_device_height = MAIN_LCD_device_height;
    UI_clip_x1 = 0;
    UI_clip_x2 = UI_device_width - 1;
    UI_clip_y1 = 0;
    UI_clip_y2 = UI_device_height - 1;
    UI_old_clip_x1 = 0;
    UI_old_clip_y1 = 0;
    UI_old_clip_x2 = UI_device_width - 1;
    UI_old_clip_y2 = UI_device_height - 1;
    UI_text_x = 0;
    UI_text_y = 0;

    UI_text_color.alpha = 100;
    UI_text_color.r = 0;
    UI_text_color.g = 0;
    UI_text_color.b = 0;

    /* assign UI function pointers */
    gui_cross_hatch_fill_rectangle = UI_cross_hatch_fill_rectangle;
    gui_hatch_fill_rectangle = UI_hatch_fill_rectangle;
    gui_alternate_cross_hatch_fill_rectangle = UI_alternate_cross_hatch_fill_rectangle;
    gui_alternate_hatch_fill_rectangle = UI_alternate_hatch_fill_rectangle;
    gui_line = UI_line;
    gui_wline = UI_wline;
    gui_set_text_clip = UI_set_text_clip;
    gui_get_text_clip = UI_get_text_clip;
    gui_set_text_clip_preset = UI_set_text_clip_preset;
    gui_set_clip = UI_set_clip;
    gui_set_clip_with_bounding_box = UI_set_clip_with_bounding_box;
    gui_get_clip = UI_get_clip;
    gui_set_clip_preset = UI_set_clip_preset;
    gui_reset_clip = UI_reset_clip;
    gui_reset_text_clip = UI_reset_text_clip;
    gui_move_text_cursor = UI_move_text_cursor;
    gui_set_line_height = UI_set_line_height;
    gui_set_text_color = UI_set_text_color;
    gui_set_text_border_color = UI_set_text_border_color;
    gui_printf = UI_printf;
    gui_sprintf = UI_sprintf;
    gui_print_text = UI_print_text;
    gui_print_bordered_text = UI_print_bordered_text;
    gui_print_text_n = UI_print_text_n;
    gui_print_bordered_text_n = UI_print_bordered_text_n;
    gui_print_character = UI_print_character;
    gui_print_character_at_xy = UI_print_character_at_xy;
    gui_print_stacked_character = UI_print_stacked_character;
    gui_print_bordered_stacked_character = UI_print_bordered_stacked_character;
    gui_print_bordered_character = UI_print_bordered_character;
    gui_push_text_clip = UI_push_text_clip;
    gui_pop_text_clip = UI_pop_text_clip;
    gui_push_clip = UI_push_clip;
    gui_pop_clip = UI_pop_clip;
    gui_malloc = UI_malloc;
    gui_free = UI_free;
    gui_get_character_width = UI_get_character_width;
    gui_get_character_height = UI_get_character_height;
    gui_measure_character = UI_measure_character;
    gui_get_string_width = UI_get_string_width;
    gui_get_string_width_n = UI_get_string_width_n;
    gui_get_string_width_w = UI_get_string_width_w;
    gui_get_string_width_wn = UI_get_string_width_wn;
    gui_get_string_height = UI_get_string_height;
    gui_measure_string = UI_measure_string;
    gui_measure_string_n = UI_measure_string_n;
    gui_measure_string_w = UI_measure_string_w;
    gui_measure_string_wn = UI_measure_string_wn;
    gui_strlen = UI_strlen;
    gui_strcpy = UI_strcpy;
    gui_strncpy = UI_strncpy;
    gui_strcmp = UI_strcmp;
    gui_strncmp = UI_strncmp;
    gui_strcat = UI_strcat;
    gui_itoa = UI_itoa;
    gui_atoi = UI_atoi;
    gui_set_font = UI_set_font;
    gui_measure_image = _measure_image;
    gui_start_timer = UI_start_timer;
    gui_cancel_timer = UI_cancel_timer;
    gui_transparent_color = UI_transparent_color;
    gui_color = UI_color;
    gui_color32 = UI_color32;
    gui_color_RGB = UI_color_RGB;
    gui_image_n_frames = UI_get_image_n_frames;
    gui_memcpy = UI_memcpy;
    gui_get_next_character = UI_get_next_UCS2_character;
    gui_get_previous_character = UI_get_previous_UCS2_character;

    gui_putpixel = UI_putpixel;
    gui_draw_vertical_line = UI_draw_vertical_line;
    gui_draw_horizontal_line = UI_draw_horizontal_line;
    gui_fill_rectangle = UI_fill_rectangle;
    gui_draw_rectangle = UI_draw_rectangle;
    gui_hide_animations = UI_hide_animations;
    gui_show_image = _show_image;
    gui_show_transparent_image = _show_transparent_image;
    gui_show_animated_image_frame = _show_animation_frame;
    gui_show_transparent_animated_image_frame = _show_transparent_animation_frame;
    gui_lock_double_buffer = UI_lock_double_buffer;
    gui_unlock_double_buffer = UI_unlock_double_buffer;
    gui_BLT_double_buffer = UI_BLT_double_buffer;

    /* declare at wgui.c */
    MMI_status_bar_height = MMI_STATUS_BAR_HEIGHT;
#ifdef __MMI_SCREEN_ROTATE__
    /* 
     * NOTE: not all basic definitions of UI components has rotated value
     * because we do not support rotation of all category screens in current design.
     */
    if (mmi_frm_is_screen_width_height_swapped())
    {
        MMI_content_x = MMI_ROTATED_CONTENT_X;
        MMI_content_y = MMI_ROTATED_CONTENT_Y;
        MMI_content_height = MMI_ROTATED_CONTENT_HEIGHT;
        MMI_content_width = MMI_ROTATED_CONTENT_WIDTH;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */ 
    {
        MMI_content_x = MMI_CONTENT_X;
        MMI_content_y = MMI_CONTENT_Y;
        MMI_content_height = MMI_CONTENT_HEIGHT;
        MMI_content_width = MMI_CONTENT_WIDTH;
    }

    /* declare at wgui_categories.c */
    MMI_matrix_bar_height = MMI_MATRIX_BAR_HEIGHT;
    MMI_matrix_bar_x = MMI_MATRIX_BAR_X;
    MMI_matrix_bar_y = MMI_MATRIX_BAR_Y;
    MMI_matrix_bar_width = MMI_MATRIX_BAR_WIDTH;
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        MMI_title_height = MMI_ROTATED_TITLE_HEIGHT;
        MMI_title_width = MMI_ROTATED_TITLE_WIDTH;
        MMI_title_x = MMI_ROTATED_TITLE_X;
        MMI_title_y = MMI_ROTATED_TITLE_Y;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */ 
    {
        MMI_title_height = MMI_TITLE_HEIGHT;
        MMI_title_width = MMI_TITLE_WIDTH;
        MMI_title_x = MMI_TITLE_X;
        MMI_title_y = MMI_TITLE_Y;
    }
    MMI_button_bar_height = MMI_BUTTON_BAR_HEIGHT;
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        MMI_pop_up_dialog_x = MMI_ROTATED_POP_UP_DIALOG_X;
        MMI_pop_up_dialog_y = MMI_ROTATED_POP_UP_DIALOG_Y;
        MMI_pop_up_dialog_width = MMI_ROTATED_POP_UP_DIALOG_WIDTH;
        MMI_pop_up_dialog_height = MMI_ROTATED_POP_UP_DIALOG_HEIGHT;
        MMI_pop_up_dialog_full_height = MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */ 
    {
        MMI_pop_up_dialog_x = MMI_POP_UP_DIALOG_X;
        MMI_pop_up_dialog_y = MMI_POP_UP_DIALOG_Y;
        MMI_pop_up_dialog_width = MMI_POP_UP_DIALOG_WIDTH;
        MMI_pop_up_dialog_height = MMI_POP_UP_DIALOG_HEIGHT;
        MMI_pop_up_dialog_full_height = MMI_POP_UP_DIALOG_FULL_HEIGHT;
    }

    /* declare at wgui_inputs.c */
    MMI_multitap_x = MMI_MULTITAP_X;
    MMI_multitap_y = MMI_MULTITAP_Y;
    MMI_multitap_width = MMI_MULTITAP_WIDTH;
    MMI_multitap_height = MMI_MULTITAP_HEIGHT;
    MMI_singleline_inputbox_x = MMI_SINGLELINE_INPUTBOX_X;
    MMI_singleline_inputbox_y = MMI_SINGLELINE_INPUTBOX_Y;
    MMI_singleline_inputbox_width = MMI_SINGLELINE_INPUTBOX_WIDTH;
    MMI_singleline_inputbox_height = MMI_SINGLELINE_INPUTBOX_HEIGHT;
    MMI_multiline_inputbox_x = MMI_MULTILINE_INPUTBOX_X;
    MMI_multiline_inputbox_y = MMI_MULTILINE_INPUTBOX_Y;
    MMI_multiline_inputbox_width = MMI_MULTILINE_INPUTBOX_WIDTH;
    MMI_multiline_inputbox_height = MMI_MULTILINE_INPUTBOX_HEIGHT;
    MMI_general_inputbox_x = MMI_GENERAL_INPUTBOX_X;
    MMI_general_inputbox_y = MMI_GENERAL_INPUTBOX_Y;
    MMI_general_inputbox_width = MMI_GENERAL_INPUTBOX_WIDTH;
    MMI_general_inputbox_height = MMI_GENERAL_INPUTBOX_HEIGHT;
    MMI_menuitem_height = MMI_MENUITEM_HEIGHT;
    /* declare at wgui_status_icons.h */
    MMI_status_icon_bars[0].x = 0;                          /* x */
    MMI_status_icon_bars[0].y = 0;                          /* y */
    MMI_status_icon_bars[0].flags = 0;                      /* FLAGS */
    MMI_status_icon_bars[0].x1 = 0;                         /* x1 */
    MMI_status_icon_bars[0].y1 = 0;                         /* y1 */
    MMI_status_icon_bars[0].x2 = UI_device_width - 1;       /* x2 */
    MMI_status_icon_bars[0].y2 = MMI_STATUS_BAR_HEIGHT - 1; /* y2 */
    MMI_status_icon_bars[0].group_ID = 0;                   /* GROUP */
    MMI_status_icon_bars[0].n_icons = 0;                    /* N_ICONS */
    MMI_status_icon_bars[0].icon_list = MMI_status_icons_list1; /* ICON_LIST */
    MMI_status_icon_bars[0].graphics_context = &main_LCD_device_bitmap; /* LCD CONTEXT */
    MMI_status_icon_bars[0].layer_buffer= NULL;             /* LAYER BUFFER */ //061506 double buffer
    MMI_status_icon_bars[0].layer_handle= GDI_ERROR_HANDLE; /* LAYER HANDLE */ //061506 double buffer

    MMI_status_icon_bars[1].x = UI_device_width - 17;   /* x */
    MMI_status_icon_bars[1].y = 16;                     /* y */
    MMI_status_icon_bars[1].flags = 0;                  /* FLAGS */
    MMI_status_icon_bars[1].x1 = UI_device_width - 18;  /* x1 */
    MMI_status_icon_bars[1].y1 = 16;                    /* y1 */
    MMI_status_icon_bars[1].x2 = UI_device_width - 1;   /* x2 */
    MMI_status_icon_bars[1].y2 = 80;                    /* y2 */
    MMI_status_icon_bars[1].group_ID = 0;               /* GROUP */
    MMI_status_icon_bars[1].n_icons = 0;                /* N_ICONS */
    MMI_status_icon_bars[1].icon_list = MMI_status_icons_list2; /* ICON_LIST */
    MMI_status_icon_bars[1].graphics_context = &main_LCD_device_bitmap; /* LCD CONTEXT */
    MMI_status_icon_bars[1].layer_buffer= NULL;             /* LAYER BUFFER */ //061506 double buffer
    MMI_status_icon_bars[1].layer_handle= GDI_ERROR_HANDLE; /* LAYER HANDLE */ //061506 double buffer

    MMI_status_icon_bars[2].x = 0;          /* x */
    MMI_status_icon_bars[2].y = 0;          /* y */
    MMI_status_icon_bars[2].flags = 0;      /* FLAGS */
    MMI_status_icon_bars[2].x1 = 0;         /* x1 */
    MMI_status_icon_bars[2].y1 = 0;         /* y1 */
    MMI_status_icon_bars[2].x2 = 48 - 1;    /* x2 */
    MMI_status_icon_bars[2].y2 = 14;        /* y2 */
    MMI_status_icon_bars[2].group_ID = 0;   /* GROUP */
    MMI_status_icon_bars[2].n_icons = 0;    /* N_ICONS */
    MMI_status_icon_bars[2].icon_list = MMI_status_icons_list3; /* ICON_LIST */
    MMI_status_icon_bars[2].graphics_context = &sub_LCD_device_bitmap;  /* LCD CONTEXT */
    MMI_status_icon_bars[2].layer_buffer= NULL;             /* LAYER BUFFER */ //061506 double buffer
    MMI_status_icon_bars[2].layer_handle= GDI_ERROR_HANDLE; /* LAYER HANDLE */ //061506 double buffer

}


/*****************************************************************************
 * FUNCTION
 *  gui_setup_default_layout
 * DESCRIPTION
 *  Setup UI layout context to "Default Layout"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_default_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_content_x = MMI_CONTENT_X;
    MMI_content_y = MMI_CONTENT_Y;
    MMI_content_width = MMI_CONTENT_WIDTH;
    MMI_content_height = MMI_CONTENT_HEIGHT;

    MMI_title_x = MMI_TITLE_X;
    MMI_title_y = MMI_TITLE_Y;
    MMI_title_width = MMI_TITLE_WIDTH;
    MMI_title_height = MMI_TITLE_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  gui_setup_common_layout
 * DESCRIPTION
 *  Setup UI layout context to "Common Layout"
 *
 *  The major differences between "Default Layout" and "Common Layout" is that
 *  category screens using "Common Layout" need to call gui_setup_common_layout()
 *  explicitly, but "Default Layout" does not. 
 *
 *  "Common Layout" is used for category screens which can be customized for 
 *  layout other than PlutoMMI's default.
 *
 *  "Default Layout" is used for category screens which always use PlutoMMI's default
 *  because it may be difficult to be scalable. (e.g. need to change images)
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_common_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_content_x = MMI_COMMON_CONTENT_X;
    MMI_content_y = MMI_COMMON_CONTENT_Y;
    MMI_content_width = MMI_COMMON_CONTENT_WIDTH;
    MMI_content_height = MMI_COMMON_CONTENT_HEIGHT;

    MMI_title_x = MMI_COMMON_TITLE_X;
    MMI_title_y = MMI_COMMON_TITLE_Y;
    MMI_title_width = MMI_COMMON_TITLE_WIDTH;
    MMI_title_height = MMI_COMMON_TITLE_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  gui_setup_mainmenu_layout
 * DESCRIPTION
 *  Setup UI layout context to "Main Menu Layout"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_mainmenu_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_content_x = MMI_MAINMENU_CONTENT_X;
    MMI_content_y = MMI_MAINMENU_CONTENT_Y;
    MMI_content_width = MMI_MAINMENU_CONTENT_WIDTH;
    MMI_content_height = MMI_MAINMENU_CONTENT_HEIGHT;

    MMI_title_x = MMI_MAINMENU_TITLE_X;
    MMI_title_y = MMI_MAINMENU_TITLE_Y;
    MMI_title_width = MMI_MAINMENU_TITLE_WIDTH;
    MMI_title_height = MMI_MAINMENU_TITLE_HEIGHT;
}


/*****************************************************************************
 * FUNCTION
 *  gui_setup_submenu_layout
 * DESCRIPTION
 *  Setup UI layout context to "Sub Menu Layout"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_submenu_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_content_x = MMI_SUBMENU_CONTENT_X;
    MMI_content_y = MMI_SUBMENU_CONTENT_Y;
    MMI_content_width = MMI_SUBMENU_CONTENT_WIDTH;
    MMI_content_height = MMI_SUBMENU_CONTENT_HEIGHT;

    MMI_title_x = MMI_SUBMENU_TITLE_X;
    MMI_title_y = MMI_SUBMENU_TITLE_Y;
    MMI_title_width = MMI_SUBMENU_TITLE_WIDTH;
    MMI_title_height = MMI_SUBMENU_TITLE_HEIGHT;
}



/*****************************************************************************
 * FUNCTION
 *  InitDebugPrint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitDebugPrint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static BOOL is_debug_print_init = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_debug_print_init)
    {
        gdi_handle base_handle;

        /* init graphic library. including lcd and all drawing related modules */
        gdi_init();
        setup_UI_wrappers();

        gdi_layer_get_base_handle(&base_handle);
        gdi_layer_set_active(base_handle);
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();
        is_debug_print_init = TRUE;
    }
}

extern U32 ShowDebugString(S32 x, S32 y, stFontAttribute Font, U8 *String, S32 len, U32 LineHeight, U32 Bordered);


/*****************************************************************************
 * FUNCTION
 *  DebugPrint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 *  s       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void DebugPrint(U8 x, U8 y, S8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define DEBUG_CHAR_COUNT (256)

    S8 buffer[(DEBUG_CHAR_COUNT + 1) * ENCODING_LENGTH];
    stFontAttribute debug_font = {0, 0, 0, SMALL_FONT, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
    InitDebugPrint();

    /* flattern all layer content to base layer */
    gdi_layer_flatten_previous_to_base();

    /* set base layer as active layer */
    gdi_layer_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    
    /* init font setting */
    UI_set_font(&debug_font);
    UI_set_text_color(UI_color(0, 0, 0));
    UI_set_text_border_color(UI_color(255, 255, 255));

    memset(buffer, 0, (DEBUG_CHAR_COUNT + 1) * ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((PS8) buffer, s, DEBUG_CHAR_COUNT);

    UI_move_text_cursor(x, y);
    /* UI_print_text((UI_string_type)buffer); */
    UI_set_current_text_color(UI_text_color);
    ShowDebugString(UI_text_x, UI_text_y, *UI_font, (U8*) buffer, -1, UI_text_height, 1);

    gdi_layer_debug_blt();
}


/*****************************************************************************
 * FUNCTION
 *  MMISWChangeWarning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  space           [IN]        
 *  codeversion     [IN]        
 *  diskversion     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMISWChangeWarning(kal_uint8 type, kal_uint32 space, kal_uint8 const *codeversion, kal_uint8 const *diskversion)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    kal_uint8 dspl_text[80];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitDebugPrint();

    kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
    sprintf((char*)dspl_text, "SW Change:\n");
    DebugPrint(0, 10, (S8*) dspl_text);

    kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
    sprintf((char*)dspl_text, " From: %s\n", diskversion);
    DebugPrint(0, 20, (S8*) dspl_text);

    kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
    sprintf((char*)dspl_text, " To:    %s\n", codeversion);
    DebugPrint(0, 30, (S8*) dspl_text);

    if (type == 0)
    {
        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Err: Lack of space:\n");
        DebugPrint(0, 40, (S8*) dspl_text);

        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, " %d bytes needed.\n", space);
        DebugPrint(0, 50, (S8*) dspl_text);

        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Fix:Delete from USER.\n");
        DebugPrint(0, 60, (S8*) dspl_text);

        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "SW Change aborted.\n");
        DebugPrint(0, 70, (S8*) dspl_text);

    }
    else
    {
        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Err: Critical changes.\n");
        DebugPrint(0, 40, (S8*) dspl_text);

        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Fix:Backup please.\n");
        DebugPrint(0, 50, (S8*) dspl_text);

        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "SW change aborted.\n");
        DebugPrint(0, 60, (S8*) dspl_text);
    }

#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 
}


/*****************************************************************************
 * FUNCTION
 *  MMIResourceMismatchWarning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  errType         [IN]        
 *  errResType      [IN]        
 *  codeversion     [IN]        
 *  resversion      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMIResourceMismatchWarning(
        kal_int8 errType,
        kal_int8 errResType,
        kal_uint8 const *codeversion,
        kal_uint8 const *resversion)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    kal_uint8 dspl_text[80];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitDebugPrint();

    if (errType < 0)
    {
        return;
    }

    if (errResType == 0)
    {
        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Err: AUDIO Ver:\n");
        DebugPrint(0, 10, (S8*) dspl_text);
    }
    else if (errResType == 1)
    {
        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Err: IMAGE Ver:\n");
        DebugPrint(0, 10, (S8*) dspl_text);
    }
    else if (errResType == 2)
    {
        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Err: FONT Ver:\n");
        DebugPrint(0, 10, (S8*) dspl_text);
    }
    else
    {
        kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
        sprintf((char*)dspl_text, "Err: Res Ver:\n");
        DebugPrint(0, 10, (S8*) dspl_text);
    }

    kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
    sprintf((char*)dspl_text, " %s\n", resversion);
    DebugPrint(0, 20, (S8*) dspl_text);

    kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
    sprintf((char*)dspl_text, " Expected ver#:\n");
    DebugPrint(0, 40, (S8*) dspl_text);

    kal_mem_set(dspl_text, '\0', sizeof(dspl_text));
    sprintf((char*)dspl_text, " %s\n", codeversion);
    DebugPrint(0, 50, (S8*) dspl_text);

    while (1);
#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 
}


/*****************************************************************************
 * FUNCTION
 *  MMIGetGDIShowFullScreenTime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 MMIGetGDIShowFullScreenTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_estimate_show_fullscreen_time();
#else
    return 0;
#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 
}


/* Scan disk and display first logo image */
/*****************************************************************************
 * FUNCTION
 *  MMICheckDiskDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMICheckDiskDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)

    S32 height, width;
    S32 x, y;
    S32 UI_device_width = LCD_WIDTH;
    S32 UI_device_height = LCD_HEIGHT;
    static U8 PicHasBeenShown = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid screen flickering when it is called for several times */
    if (PicHasBeenShown == 0)
    {
        PicHasBeenShown = 1;
    }
    else
    {
        return;
    }

    /* init graphic library. including lcd and all drawing related modules */
    gdi_init();
    
#if defined(__MMI_RESOURCE_ENFB_SUPPORT__)
    /* 
     * Init Resource Memory Manamger  for E-NFB
     */
	mmi_frm_resmem_init();
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */


    InitDebugPrint();

    gdi_image_get_dimension_id(IMG_BOOTUP_SCANNING_LOGO, &width, &height);

    if (width > UI_device_width)
    {
        x = 0;
    }
    else
    {
        x = (UI_device_width >> 1) - (width >> 1);
    }
    if (height > UI_device_height)
    {
        y = 0;
    }
    else
    {
        y = (UI_device_height >> 1) - (height >> 1);
    }


    gdi_layer_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_image_draw_id(x, y, IMG_BOOTUP_SCANNING_LOGO);
    gdi_layer_blt(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0, 0, 0, UI_device_width - 1, UI_device_height - 1);

    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);

#endif /* !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI) */ 
}

/********   Transparency Code  *********************/

/* Added for transparency effect
 * It will take opacity value in calculation. */

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined (__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__) || defined (UI_SCROLLBAR_STYLE_4)

gdi_handle non_default_layer = GDI_LAYER_EMPTY_HANDLE;


/*****************************************************************************
 * FUNCTION
 *  gui_set_transparent_source_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_transparent_source_layer(gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    non_default_layer = layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_transparent_source_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
gdi_handle gui_get_transparent_source_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return non_default_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_reset_transparent_source_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_reset_transparent_source_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    non_default_layer = GDI_LAYER_EMPTY_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_is_current_transparency_with_multi_layer
 * DESCRIPTION
 *  This function returns if multilayer is enabled in transparency effect
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
S32 gui_is_current_transparency_with_multi_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (non_default_layer == GDI_LAYER_EMPTY_HANDLE) ? 0 : 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_fill_transparent_color
 * DESCRIPTION
 *  Fill the transparent color rectangle
 * PARAMETERS
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  c               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_fill_transparent_color(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 alpha = ((U32) c.alpha) * 255 / 100;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (non_default_layer != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_effect_alpha_blending_rect(non_default_layer, x1, y1, x2, y2, alpha, c.r, c.g, c.b);
    }
    else
    {
        gdi_handle active_layer;

        gdi_layer_get_active(&active_layer);
        gdi_effect_alpha_blending_rect(active_layer, x1, y1, x2, y2, alpha, c.r, c.g, c.b);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_transparent_color_filler
 * DESCRIPTION
 *  Choose the color filler
 * PARAMETERS
 *  x1              [IN]        
 *  y1              [IN]        
 *  x2              [IN]        
 *  y2              [IN]        
 *  c               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_transparent_color_filler(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 alpha_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_LCD->act_handle != GDI_LCD_MAIN_LCD_HANDLE)
    {
        alpha_value = ((c.alpha) << 8) / 100;
        if (256 == alpha_value)
        {
            alpha_value = 255;
        }
        gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(alpha_value, c.r, c.g, c.b));
    }
    else
#endif /* __MMI_SUBLCD__ */ 
    {
    #if __MMI_MAIN_BASE_LAYER_FORMAT__ == GDI_COLOR_FORMAT_32
        U32 alpha_value;
    
        alpha_value = ((c.alpha) << 8) / 100;
        if (256 == alpha_value)
        {
            alpha_value = 255;
        }
        gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(alpha_value, c.r, c.g, c.b));
    #else
        gui_fill_transparent_color(x1, y1, x2, y2, c);
    #endif
    }
}

#endif /* defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__) || defined (__MMI_UI_TRANSPARENT_EFFECT_IN_DALMATIAN_CALENDAR__)|| defined (UI_SCROLLBAR_STYLE_4) */ 

