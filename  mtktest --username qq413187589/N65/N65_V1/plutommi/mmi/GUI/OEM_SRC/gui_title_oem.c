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
 *  gui_title_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Extract the codes related drawing into this file for oem
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#include "MMI_features.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_title_pre_oem.h"
#include "gui_title.h"
#include "gui_title_post_oem.h"
#include "wgui_status_icons.h"


/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
static void gui_title_measure_area1(gui_title_struct *t, S32 *width, S32 *height);
static void gui_title_measure_area2(gui_title_struct *t, S32 *width, S32 *height);
static void gui_title_measure_text(gui_title_struct *t, S32 *offset_x_ptr, S32 *offset_y_ptr, S32 area_width);
static void gui_title_show_area1(gui_title_struct *t, S32 x, S32 y);
static void gui_title_show_area2(gui_title_struct *t, S32 x, S32 y);
static void gui_title_show_text(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
static void gui_title_show_status_icon(gui_title_struct *t);
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_title_oem_show_background
 * DESCRIPTION
 *  draw background of title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]            
 *  y       [IN]            
 *  w       [IN]            
 *  h       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_oem_show_background(gui_title_struct *t, S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x, y, x + w - 1, y + h - 1);

    /* modified to support wallpaper on bottom */
    if (!(t->style & GUI_TITLE_STYLE_DISABLEBG))
    {
        if (wgui_is_wallpaper_on_bottom() == MMI_TRUE)
        {
            gdi_draw_solid_rect(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1, GDI_COLOR_TRANSPARENT);  /* 061705 Calvin added */
            if (title_bg_id != 0)
            {
                gdi_image_draw_id(t->x, t->y, title_bg_id);
            }
            else
            {
                gui_draw_filled_area(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1, t->active_filler);
            }
        }
        else
        {
            gdi_draw_solid_rect(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1, GDI_COLOR_WHITE);        /* 090605 Title Calvin added */

            if (title_bg_id != 0)
            {
                gdi_image_draw_id(t->x, t->y, title_bg_id);
            }
            else
            {
                gui_draw_filled_area(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1, t->active_filler);
            }
        }
    #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
        if (gui_title_is_animation_enabled(t))
        {
            if (t->animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_NONE)
            {
                gui_title_show_animate_image_frame_0(t, t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);
            }
            if (t->animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_ONCE && t->current_frame_count == -1)
            {
                gui_title_show_animate_image_frame_0(t, t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);
            }
            else
            {
                gui_title_show_animate_image(t, t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);
            }
        }
    #endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 
    }
    else
    {
        gdi_draw_solid_rect(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1, GDI_COLOR_TRANSPARENT);
    }
    gui_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  gui_title_measure_area1
 * DESCRIPTION
 *  t->icon or leftarrow of mini tab bar
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  width       [IN/OUT]        Get the width of area1
 *  height      [IN/OUT]        Get the height of area1
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_measure_area1(gui_title_struct *t, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    S32 w, h;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t->icon != NULL)
    {
#if defined(__MMI_SCREEN_ROTATE__) && defined(GUI_COMMON_USE_THICK_TITLE)
        if (mmi_frm_is_screen_width_height_swapped() && t->height == MMI_THIN_TITLE_HEIGHT)
        {
            *width = GUI_TITLE_NON_ICON_GAP;
        }
        else
#endif
        {
        gdi_image_get_dimension((U8*) t->icon, width, height);
        *width = *width + GUI_TITLE_ICON_GAP;
        }
    }
    else
    {
        *width = GUI_TITLE_NON_ICON_GAP; 
        *height = 0;		
    }
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!r2lMMIFlag)
    {
        wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w, &h);
    }
    else
    {
        wgui_status_icon_integrated_get_area(STATUS_ICON_BATTERY_STRENGTH, &w, &h);
    }
    *width += w;
#endif
    t->icon_width = *width;
    t->icon_height = *height;

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_measure_area2
 * DESCRIPTION
 *  get the width of t->icon2 or t->sc or right arrow of mini tab bar
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  width       [IN/OUT]        Get the width of area2
 *  height      [IN/OUT]        Get the height of area2
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_measure_area2(gui_title_struct *t, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    S32 w, h;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (t->no_icon_shct == MMI_FALSE)
    {
    #ifdef __MMI_TITLE_BAR_NO_ICON_SHCT__  
        if (wgui_if_mini_tab_bar_enable())
        {
            gdi_image_get_dimension((U8*) get_image(RIGHT_RED_ARROW), width, height);
            *width = *width + GUI_TITLE_ICON_GAP;
        }
        else
        {
            *width = GUI_TITLE_NON_ICON_GAP;
        }
    #else /* __MMI_TITLE_BAR_NO_ICON_SHCT__ */
        if (t->icon2 != NULL)
        {
            gdi_image_get_dimension((U8*) t->icon2, width, height);
            *width = *width + GUI_TITLE_ICON_GAP;;
        }
        else
        {
            *width = GUI_TITLE_NON_ICON_GAP;
        }
        
    #endif /* __MMI_TITLE_BAR_NO_ICON_SHCT__ */         
    }
    else if (t->icon2 != NULL)
    {
        gdi_image_get_dimension((U8*) t->icon2, width, height);
        *width = *width + GUI_TITLE_ICON_GAP;;
    }
    else if (gui_shortcut_is_show(&t->sc))
    {
        *width = gui_shortcut_get_width(&t->sc);
        *width = *width + GUI_TITLE_NON_ICON_GAP;
    }
    else
    {
        *width = GUI_TITLE_NON_ICON_GAP;
    }
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!r2lMMIFlag)
    {
        wgui_status_icon_integrated_get_area(STATUS_ICON_BATTERY_STRENGTH, &w, &h);
        gui_shortcut_move(&t->sc, t->width - t->sc.width - w, t->sc.y);
    }
    else
    {
        wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w, &h);
        gui_shortcut_move(&t->sc, w, t->sc.y);
    }
    *width += w;
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_measure_text
 * DESCRIPTION
 *  get the width and height of text
 * PARAMETERS
 *  t                   [IN/OUT]        Is the struct of title
 *  offset_x_ptr        [IN/OUT]             
 *  offset_y_ptr        [IN/OUT]            
 *  area_width          [IN]            
 *  width               [IN/OUT]        Get the width of text
 *  height              [IN/OUT]        Get the height of text
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_measure_text(gui_title_struct *t, S32 *offset_x_ptr, S32 *offset_y_ptr, S32 area_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(t->normal_font);
    gui_measure_string((UI_string_type) t->text, &width, &height);
    width += GUI_TITLE_TEXT_GAP;
    *offset_y_ptr = (t->height - height) >> 1;
    if (width < t->width - area_width && !(t->style & GUI_TITLE_STYLE_LEFTALIGN))
    {
        *offset_x_ptr = (t->width - area_width - width) >> 1;
    }
}

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
/*****************************************************************************
 * FUNCTION
 *  gui_title_show_status_icon
 * DESCRIPTION
 *  draw icon of title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]            
 *  y       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_status_icon(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w, &h);
    gui_set_clip(t->x, t->y, t->x + w - 1, t->y + t->height - 1);
    wgui_status_icon_integrated_show(STATUS_ICON_SIGNAL_STRENGTH, t->x, t->y + t->height - h);
    wgui_status_icon_integrated_get_area(STATUS_ICON_BATTERY_STRENGTH, &w, &h);
    gui_set_clip(t->x + t->width - w, t->y, t->x + t->width - 1, t->y + t->height - 1);
    wgui_status_icon_integrated_show(STATUS_ICON_BATTERY_STRENGTH, t->x + t->width - w, t->y + t->height - h);
}
#endif



/*****************************************************************************
 * FUNCTION
 *  gui_title_show_area1
 * DESCRIPTION
 *  draw icon of title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]            
 *  y       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_area1(gui_title_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_src_layer, act_layer;
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    S32 w, h;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w, &h);
    if (!r2lMMIFlag)
    {
        wgui_status_icon_integrated_show(STATUS_ICON_SIGNAL_STRENGTH, 
            x - GUI_TITLE_ICON_GAP, t->y + t->height - h);
        x = x + w;
    }
    else
    {
        wgui_status_icon_integrated_show(STATUS_ICON_BATTERY_STRENGTH, t->x + t->width - w, t->y + t->height - h);
    }
#endif

    if (t->icon != NULL)
    {
        if (t->icon_ani_handle != GDI_ERROR_HANDLE)
        {
            gdi_image_stop_animation(t->icon_ani_handle);
            t->icon_ani_handle = GDI_ERROR_HANDLE;
        }

        /* Set active layer as the abm source layer for png title icon*/
    #if defined(__MMI_WALLPAPER_ON_BOTTOM__)
        
        gdi_image_abm_get_source_layer(&old_src_layer);
        gdi_layer_get_active(&act_layer);
        gdi_image_abm_set_source_layer(act_layer);
    #endif
        
        t->icon_x = x;
        t->icon_y = y;
    #if defined(__MMI_SCREEN_ROTATE__) && defined(GUI_COMMON_USE_THICK_TITLE)
        if (mmi_frm_is_screen_width_height_swapped() && t->height == MMI_THIN_TITLE_HEIGHT)
        {
        }
        else
    #endif
        {
            gdi_image_draw_animation(x, y, (U8*) t->icon, &t->icon_ani_handle);
        }
    #if defined(__MMI_WALLPAPER_ON_BOTTOM__)
        gdi_image_abm_set_source_layer(old_src_layer);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_area2
 * DESCRIPTION
 *  draw icon of title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]            
 *  y       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_area2(gui_title_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    S32 w, h;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w, &h);
    if (r2lMMIFlag)
    {
        x = x - GUI_TITLE_ICON_GAP + w;
    }
#endif
    if (t->no_icon_shct == MMI_FALSE)
    {
        MMI_disable_title_shortcut_display = 1;
        t->sc.display_enabled = 1;
        disable_menu_shortcut_box_display = 1;
    #ifdef __MMI_TITLE_BAR_NO_ICON_SHCT__
        if (wgui_if_mini_tab_bar_enable())
        {
            gdi_image_draw_id(x, y, RIGHT_RED_ARROW);
        }
    #else
        if (t->icon2 != NULL)
        {
            gui_show_transparent_image(x, y, t->icon2, gui_transparent_color(0, 0, 0));
        }
    #endif /* __MMI_TITLE_BAR_NO_ICON_SHCT__ */ 
    }
    else
    {
        if (t->icon2 != NULL)
        {
            gui_show_transparent_image(x, y, t->icon2, gui_transparent_color(0, 0, 0));
        }
    }
    
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE    
    if (!r2lMMIFlag)
    {
        wgui_status_icon_integrated_show(STATUS_ICON_BATTERY_STRENGTH, t->x + t->width - w, t->y + t->height - h);
    }
    else
    {
        wgui_status_icon_integrated_show(STATUS_ICON_SIGNAL_STRENGTH, 
            x - w, t->y + t->height - h);
    }    
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_text
 * DESCRIPTION
 *  draw title text
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x1      [IN]            
 *  y1      [IN]            
 *  x2      [IN]            
 *  y2      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_text(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(y2);
    gui_set_font(t->normal_font);
    gui_set_text_color(t->text_color);
    gui_move_text_cursor(x1, y1);

    gui_set_text_border_color(t->text_border_color);

    gui_measure_string((UI_string_type) t->text, &width, &height);
    gui_set_line_height(height);
    
#ifdef __MMI_UI_TITLE_TRANSITION__
    if (!t->check_for_transition)
    {
        if (!r2lMMIFlag)
        {
            gui_move_text_cursor(x1, y1);
        }
        else
        {   
            gui_move_text_cursor(x1 + width - 1, y1);
        }
        gui_print_bordered_text((UI_string_type) t->text);
    }
    else
#endif /* __MMI_UI_TITLE_TRANSITION__ */
    {
        if (!r2lMMIFlag)
        {
            gui_print_truncated_borderd_text(x1, y1, x2 - x1 + 1, (UI_string_type) t->text);
        }
        else
        {
            gui_print_truncated_borderd_text(x1, y1, x1 - x2 + 1, (UI_string_type) t->text);
        }
    }
}

 
/*****************************************************************************
 * FUNCTION
 *  gui_title_oem_show_normal_ex
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  part        [IN]            the part to be redraw (icon, icon2, text, shortcut, all)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_oem_show_normal_ex(void)
{
    gui_title_oem_show_normal(&g_wgui_title_bar, GUI_TITLE_PART_SIGANDBAT);
    gdi_layer_blt_previous(
        g_wgui_title_bar.x,
        g_wgui_title_bar.y,
        g_wgui_title_bar.x + g_wgui_title_bar.width - 1,
        g_wgui_title_bar.y + g_wgui_title_bar.height - 1);
}

 
/*****************************************************************************
 * FUNCTION
 *  gui_title_oem_show_normal
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  part        [IN]            the part to be redraw (icon, icon2, text, shortcut, all)
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_title_oem_show_normal(gui_title_struct *t, U32 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt = MMI_TRUE;
    S32 area1_width = 0, area1_height = 0, area2_width = 0, area2_height = 0;
    S32 text_x = 0, text_y = 0;
    S32 x1, y1, x2, y2;
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    S32 w1, h1, w2, h2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_TITLE_TRANSITION__
    bitblt = gui_title_pre_show(t);
#endif 

    gui_lock_double_buffer();
    gui_push_clip();
    gui_push_text_clip();

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE    
    if (part & GUI_TITLE_PART_SIGANDBAT)
    {
        wgui_status_icon_integrated_register_redraw(gui_title_oem_show_normal_ex);
    }    
#endif

    gui_title_measure_area1(t, &area1_width, &area1_height);
    gui_title_measure_area2(t, &area2_width, &area2_height);
    x1 = t->x;
    y1 = t->y;
    x2 = t->x + t->width - 1;
    y2 = t->y + t->height - 1;

    if (part == GUI_TITLE_PART_ALL)
    {
        gui_set_clip(x1, y1, x2, y2);
        gui_title_oem_show_background(t, x1, y1, t->width, t->height);
    }
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    else if (part == GUI_TITLE_PART_SIGANDBAT)
    {
        wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w1, &h1);
        gui_set_clip(x1, y1, x1 + w1 - 1, y2);
        gui_title_oem_show_background(t, x1, y1, w1, t->height);
        wgui_status_icon_integrated_get_area(STATUS_ICON_BATTERY_STRENGTH, &w2, &h2);
        gui_set_clip(x2 - w2, y1, x2, y2);
        gui_title_oem_show_background(t, x2 - w2, y1, w2, t->height);
    }
#endif
    else if (part == GUI_TITLE_PART_ICON)
    {
        if (!r2lMMIFlag)
        {
            gui_set_clip(x1, y1, x1 + area1_width - 1, y2);
            gui_title_oem_show_background(t, x1, y1, area1_width, t->height);
        }
        else
        {
            gui_set_clip(x2 - area1_width, y1, x2, y2);
            gui_title_oem_show_background(t, x2 - area1_width, y1, area1_width, t->height);
        }
        
    }
    else if (!t->sc.display_enabled && part == GUI_TITLE_PART_SHORTCUT && t->icon2 == NULL)
    { 
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        if (!r2lMMIFlag)
        {
            gui_set_clip(x2 - area2_width, y1, x2 - area2_width + t->sc.width, y2);
            gui_title_show_background(t, x2 - area2_width, y1, t->sc.width, t->height);
        }
        else
        {
            gui_set_clip(area2_width + x1 - 1 - t->sc.width, y1, area2_width + x1 - 1, y1);
            gui_title_show_background(t, area2_width + x1 - 1 - t->sc.width, y1, t->sc.width, t->height);
        }
#else
        if (!r2lMMIFlag)
        {
            gui_set_clip(x2 - area2_width, y1, x2, y2);
            gui_title_oem_show_background(t, x2 - area2_width, y1, area2_width, t->height);
        }
        else
        {
            gui_set_clip(x1, y1, area2_width + x1 - 1, y2);
            gui_title_oem_show_background(t, x1, y1, area2_width, t->height);
        }
#endif
        
    }

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE    
    if (part == GUI_TITLE_PART_SIGANDBAT)
    {
        gui_title_show_status_icon(t);
    }
#endif
    if (part & GUI_TITLE_PART_ICON)
    {
        if (!r2lMMIFlag)
        {
            gui_title_show_area1(t, x1 + GUI_TITLE_ICON_GAP, y1 + ((t->height - area1_height) >> 1));
        }
        else
        {
            gui_title_show_area1(t, x2 - area1_width, y1 + ((t->height - area1_height) >> 1));
        }
    }

    if (part & GUI_TITLE_PART_ICON2)
    {
        if (!r2lMMIFlag)
        {
            gui_title_show_area2(t, x2 - area2_width, y1 + ((t->height - area2_height) >> 1));
        }
        else
        {
            gui_title_show_area2(t, x1 + GUI_TITLE_ICON_GAP, y1 + ((t->height - area2_height) >> 1));
        }
    }

    if ((part & GUI_TITLE_PART_TEXT) && (mmi_ucs2strlen((const S8*)t->text) != 0))
    {
        gui_title_measure_text(t, &text_x, &text_y, area1_width + area2_width);

        if (!r2lMMIFlag)
        {
            gui_title_show_text(
                t,
                x1 + area1_width + text_x,
                y1 + text_y,
                x2 - area2_width - text_x,
                y2);
        }
        else
        {
            gui_title_show_text(
                t,
                x2 - area1_width - text_x,
                y1 + text_y,
                x1 + area2_width + text_x,
                y2);
        }

    }

#ifdef __MMI_UI_TITLE_TRANSITION__
    if (!t->enable_transition)
#endif 
    {
        if (t->icon2 == NULL && (part & GUI_TITLE_PART_SHORTCUT))
        {
            gui_shortcut_show(&t->sc);
        }
    }

    gui_pop_text_clip();
    gui_pop_clip();
    gui_unlock_double_buffer();

    return bitblt;
}

