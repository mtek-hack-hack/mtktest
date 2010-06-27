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
 *  gui_main_menu_oem.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Main Menu OEM Layer
 *
 *  TODO:
 *      1. Remove __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ dependency
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui_categories_defs.h"
#include "gdi_include.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_util.h"
#include "gui_effect_oem.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
static S32 g_main_menu_matrix_effect_slide_disable = 1;
static S32 g_main_menu_matrix_old_highlight_x, g_main_menu_matrix_old_highlight_y;

static void gui_main_menu_matrix_slide_show_sliding(S32 x, S32 y, S32 width, S32 height);
static void gui_main_menu_matrix_slide_show_animation(S32 x, S32 y, S32 width, S32 height);
static void gui_main_menu_matrix_slide_hide_old_highlight(S32 x, S32 y, S32 width, S32 height);
static void gui_main_menu_matrix_get_highlight_position(S32 normal_x, S32 normal_y, S32 *anim_x, S32 *anim_y);
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__
extern S32 matrix_mm_active_image_num;
extern gui_image_rect matrix_mm_rect[];
#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_show_sliding
 * DESCRIPTION
 *  Show the matrix main menu highlight and recover the old rectangle.
 * PARAMETERS
 *  x            [IN]   x
 *  y            [IN]   y
 *  width        [IN]   width
 *  height       [IN]   height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_main_menu_matrix_slide_show_sliding(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     ax, ay;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* draw the highlight image */
    gdi_image_abm_get_source_layer_position(&ax, &ay);
    gdi_image_abm_set_source_layer_position(x, y);    
    gdi_image_draw(0, 0, current_MMI_theme->matrix_main_menu_highlight_image);       
    gdi_image_abm_set_source_layer_position(ax, ay);

    /* recover old rectangle by redrawing matrix normal icons */
    gui_main_menu_matrix_slide_hide_old_highlight(x, y, width, height);

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_show_animation
 * DESCRIPTION
 *  Show the matrix main menu animation using the gui menu item API.
 * PARAMETERS
 *  x            [IN]   x
 *  y            [IN]   y
 *  width        [IN]   width
 *  height       [IN]   height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_main_menu_matrix_slide_show_animation(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* show animation. NOTE: the animation position may be different to normal one */
    gui_show_animation_with_background_image(
        MMI_fixed_matrix_menu.cache_bmp_x1,
        MMI_fixed_matrix_menu.cache_bmp_y1,
        MMI_mm_animation,
        current_MMI_theme->matrix_main_menu_highlight_image,
        &(((fixed_icontext_menuitem_type*)MMI_fixed_matrix_menu.items[MMI_fixed_matrix_menu.highlighted_item])->item_icon_handle));

    gdi_layer_blt_previous(x, y, width, height);        
}


/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_hide_old_highlight
 * DESCRIPTION
 *  Hide old sliding rectangle.
 * PARAMETERS
 *  x       [IN]    x
 *  y       [IN]    y
 *  w       [IN]    width
 *  h       [IN]    height
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_main_menu_matrix_slide_hide_old_highlight(S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         i;
    gui_rect    intersect_rect;
    gui_rect    matrix_highlight_image_rect;
    gui_rect    *matrix_normal_icon_rect;
    PU8         matrix_normal_icon;
    S32         anim_x, anim_y;
    gui_rect    anim_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    /* fill the old rectangle with transparent color first */
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gdi_draw_solid_rect(x, y, x + width - 1, y + height - 1, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    
    for (i = 0; i < matrix_mm_active_image_num; i++)
    {
        matrix_normal_icon_rect = &(matrix_mm_rect[i].rect);
        matrix_normal_icon = matrix_mm_rect[i].image;
        
        gui_main_menu_matrix_get_highlight_position(matrix_normal_icon_rect->x, matrix_normal_icon_rect->y, &anim_x, &anim_y);

        /* 
         * use the animation rect for intersection because maybe it is going to restore an old
         * animated rectangle.
         */
        GUI_RECT(anim_rect, anim_x, anim_y, width, height);
        GUI_RECT(matrix_highlight_image_rect, x, y, width, height);

        /* draw all matrix icons in the image rect PARTIALLY and onto the main base layer */
        if (gui_rect_get_intersection(&anim_rect, &matrix_highlight_image_rect, &intersect_rect))
        {            
            gui_draw_image_with_alpha(
                matrix_normal_icon_rect->x, 
                matrix_normal_icon_rect->y, 
                &intersect_rect, 
                matrix_normal_icon, 
                GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
        }
    }
    
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_get_highlight_position
 * DESCRIPTION
 *  Get the animation position from the normal image position
 * PARAMETERS
 *  normal_x    [IN]    normal image x
 *  normal_y    [IN]    normal image y
 *  anim_x      [OUT]   animation x
 *  anim_xy     [OUT]   animation y
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_main_menu_matrix_get_highlight_position(S32 normal_x, S32 normal_y, S32 *anim_x, S32 *anim_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                 x1, y1;
    S32                 xoff2, yoff2;
    fixed_matrix_menu   *m;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m = &MMI_fixed_matrix_menu;

    if (m->highlighted_item_width > m->item_width)
    {
        xoff2 = (m->highlighted_item_width - m->item_width);
    }
    else
    {
        xoff2 = 0;
    }

    if (m->highlighted_item_height > m->item_height)
    {
        yoff2 = (m->highlighted_item_height - m->item_height);
    }
    else
    {
        yoff2 = 0;
    }

    x1 = normal_x - (xoff2 >> 1);
    y1 = normal_y - (yoff2 >> 1);

    if (x1 < m->x)
    {
        x1 = m->x;
    }

    if (y1 < m->y)
    {
        y1 = m->y;
    }

    *anim_x = x1;
    *anim_y = y1;
}

#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#ifdef __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_start
 * DESCRIPTION
 *  Matrix main menu highlight slide start call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_main_menu_matrix_slide_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sx, sy, w, h;        
    PU8 image;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_main_menu_matrix_effect_slide_disable = 0;
    image = current_MMI_theme->matrix_main_menu_highlight_image;

    /* only apply to matrix main menu */
    if ((image == NULL) ||
        (MMI_current_menu_type != MATRIX_MENU) ||
        !(MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_FOR_MAINMENU))
    {
        g_main_menu_matrix_effect_slide_disable = 1;

        return;
    }

    sx = MMI_fixed_matrix_menu.cache_bmp_x1;
    sy = MMI_fixed_matrix_menu.cache_bmp_y1;
    
    gdi_image_get_dimension(image, &w, &h);

    g_main_menu_matrix_old_highlight_x = sx;
    g_main_menu_matrix_old_highlight_y = sy;

    gdi_layer_lock_frame_buffer();

    /* recover unfinished */
    gui_effect_slide_create(
        sx, 
        sy,
        sx,
        sy,
        w,
        h,
        GUI_EFFECT_MAIN_MENU_MATRIX_SLIDE_DURATION,
        NULL,
        NULL,
        GUI_EFFECT_FRAME_FIRST);

    gui_effect_slide_close();

    gui_effect_set_blt_layer();   
}


/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_end
 * DESCRIPTION
 *  Matrix main menu highlight slide end call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_main_menu_matrix_slide_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     ex, ey, w, h;        
    PU8     image;
    S32     duration;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_main_menu_matrix_effect_slide_disable)
    {
        return;
    }

    /* restore blt layer handles */
    gui_effect_restore_blt_layer();    
    
    image = current_MMI_theme->matrix_main_menu_highlight_image;
      
    gdi_image_get_dimension(image, &w, &h);

    ex = MMI_fixed_matrix_menu.cache_bmp_x1;
    ey = MMI_fixed_matrix_menu.cache_bmp_y1;
    
    if ((g_main_menu_matrix_old_highlight_x == ex) && (g_main_menu_matrix_old_highlight_y == ey))
    {
        duration = 0;
    }
    else
    {
        duration = GUI_EFFECT_MAIN_MENU_MATRIX_SLIDE_DURATION;
    }

    gui_effect_slide_create(
        g_main_menu_matrix_old_highlight_x, 
        g_main_menu_matrix_old_highlight_y,
        ex,
        ey,
        w,
        h,
        duration,
        gui_main_menu_matrix_slide_show_sliding,
        gui_main_menu_matrix_slide_show_animation,
        GUI_EFFECT_FRAME_FIRST);

    gui_effect_register_hide_callback(gui_main_menu_matrix_slide_hide_old_highlight);

    gdi_layer_unlock_frame_buffer();    
    gdi_layer_blt_previous(0, 0, 0, 0);

    g_main_menu_matrix_effect_slide_disable = 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_is_under_control
 * DESCRIPTION
 *  Check if the sliding is fired by keys. This function is useful when redrawing
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  0: sliding is not started by key handlers; otherwise 1.
 *****************************************************************************/
S32 gui_main_menu_matrix_slide_is_under_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)(!g_main_menu_matrix_effect_slide_disable);
}


/*****************************************************************************
 * FUNCTION
 *  gui_main_menu_matrix_slide_stop
 * DESCRIPTION
 *  Stop the matrix main menu highlight sliding effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_main_menu_matrix_slide_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_effect_slide_close();
}

#endif /* __MMI_UI_MATRIX_MAIN_MENU_SLIDE_EFFECT__ */

