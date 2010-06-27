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
 *  gui_custom_menus.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Customized menu - UI component
 *
 *  [3D circular menu]
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_Features.h"
#include "gui_custom_menus.h"
#include "wgui.h"
#include "MainMenuType.h"
#include "CustMenuRes.h"
#include "CustDataRes.h"
#include "MainMenuDef.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))
extern BOOL r2lMMIFlag;
extern S32 MMI_current_menu_type;

UI_3D_circular_menu_theme *current_3D_circular_menu_theme = NULL;
#endif /* ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU)) */

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#if ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))

/*****************************************************************************
 * FUNCTION
 *  gui_set_3D_circular_menu_current_theme
 * DESCRIPTION
 *  Set the current theme for the 3D circular menu object.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_3D_circular_menu_current_theme(UI_3D_circular_menu *m)
{   /* set bkg theme color of 3D circular meneu equl to current theme */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->bg_filler = current_3D_circular_menu_theme->bg_filler;
    /* set text border  color of 3D circular meneu equl to current theme */
    m->text_border = current_3D_circular_menu_theme->text_border;
    /* set text   color of 3D circular meneu equl to current theme */
    m->text_color = current_3D_circular_menu_theme->text_color;
    /* set text font of 3D circular meneu equl to current theme */
    m->text_font = current_3D_circular_menu_theme->text_font;

    m->flags |= current_3D_circular_menu_theme->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_3D_circular_menu_theme
 * DESCRIPTION
 *  Set the given theme for the 3D circular menu object.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 *  t       [IN]        3D circular menu theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_3D_circular_menu_theme(UI_3D_circular_menu *m, UI_3D_circular_menu_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->bg_filler = t->bg_filler;
    m->text_border = t->text_border;
    m->text_color = t->text_color;
    m->text_font = t->text_font;
    m->flags |= t->flags;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_3D_circular_menu
 * DESCRIPTION
 *  Create a 3D circular menu object.
 *  
 *  n_displayed_items are the number of items that are displayed
 *  (Number of 3D objects displayed in the menu, including
 *  the two  off-screen objects)
 *  ie, n_displayed_items=Actual number of items being displayed + 2
 *  
 *  item_positions is a list of co-ordinates of the 3D objects
 *  including the transition co-ordinates in the following format:
 *  item_positions[0] = fixed co-ordinates of object 0
 *  item_positions[1] = transition 1 co-ordinates of object 0
 *  item_positions[2] = transition 2 co-ordinates of object 0
 *  item_positions[3] = fixed co-ordinates of object 1
 *  item_positions[4] = transition 1 co-ordinates of object 1
 *  ...
 *  This list has (n_displayed_items * 3) number of items.
 *  
 *  n_item_images  are the number of images per item
 *  (For example: Large frame, middle frame and small frame = 3 n_item_images)
 *  
 *  item_images    is an array of images in the following format:
 *  item_images[0]   = item 0: multi-frame image (n_item_images)
 *  item_images[1]   = item 1: multi-frame image (n_item_images)
 *  ...
 *  item_images[n_items-1]   = (item n_items-1), multi-frame image (n_item_images)
 *  
 *  common_images  is an array of images in the following format:
 *  n = n_displayed_items - n_item_images - 2
 *  Array:         image 0,    (Largest)
 *  image 1,
 *  ...
 *  image (n-1)    (Smallest)
 * PARAMETERS
 *  m                       [IN]        3D circular menu object
 *  x                       [IN]        x
 *  y                       [IN]        y
 *  width                   [IN]        width
 *  height                  [IN]        height
 *  n_displayed_items       [IN]        number of items
 *  item_positions          [IN]        item coordinates
 *  n_item_images           [IN]        number of images of a 3D circular item
 *  item_images             [IN]        item images
 *  common_images           [IN]        common images
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_3D_circular_menu(
        UI_3D_circular_menu *m,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        S32 n_displayed_items,
        CM3D_item_position *item_positions,
        S32 n_item_images,
        PU8 *item_images,
        PU8 *common_images)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->flags = 0;
    m->x = x;                                   /* start x postion of 3d circular menu */
    m->y = y;                                   /* start y postion of 3d circular menu */
    m->width = width;                           /* width of 3D circular menu */
    m->height = height;                         /* heighjt of 3D circular meneu */
    m->n_items = 0;
    m->n_displayed_items = n_displayed_items;   /* number of menu items */
    m->n_item_images = n_item_images;
    m->common_images = common_images;
    m->item_images = item_images;
    m->item_positions = item_positions;
    m->highlighted_item = 0;
    /* set 3d circular menu theme */
    gui_set_3D_circular_menu_current_theme(m);
    /* set hihlighted fun to dunmmy func */
    m->item_highlighted = UI_dummy_function_s32;
    /* set unhighlighted fun to dunmmy func */
    m->item_unhighlighted = UI_dummy_function_s32;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_3D_circular_menu_items
 * DESCRIPTION
 *  Set item text strings.
 * PARAMETERS
 *  m           [IN]        3D circular menu object
 *  n_items     [IN]        number of items
 *  items       [IN]        an array of strings. Each string is assigned to one item.
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_3D_circular_menu_items(UI_3D_circular_menu *m, S32 n_items, UI_string_type *items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->n_items = n_items;
    m->item_strings = items;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_3D_circular_menu
 * DESCRIPTION
 *  Resize a 3D circular menu object.
 * PARAMETERS
 *  m           [IN]        3D circular menu object
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_3D_circular_menu(UI_3D_circular_menu *m, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->width = width;
    m->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_3D_circular_menu
 * DESCRIPTION
 *  Move a 3D circular menu object.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_3D_circular_menu(UI_3D_circular_menu *m, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m->x = x;
    m->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_3D_circular_menu_goto_next_item
 * DESCRIPTION
 *  Highlight the next item.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_3D_circular_menu_goto_next_item(UI_3D_circular_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item; /* store current highlight index */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == (m->n_items - 1))
    {
        m->highlighted_item = 0;
    }
    else
    {
        m->highlighted_item++;
    }
    /* call unhighligted func */
    m->item_unhighlighted(old_highlighted_item);
    /* call highlighted func */
    m->item_highlighted(m->highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_3D_circular_menu_goto_previous_item
 * DESCRIPTION
 *  Highlight the previous item.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_3D_circular_menu_goto_previous_item(UI_3D_circular_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->highlighted_item == 0)
    {
        m->highlighted_item = m->n_items - 1;
    }
    else
    {
        m->highlighted_item--;
    }
    /* call unhighlghted func */
    m->item_unhighlighted(old_highlighted_item);
    /* call highlighted fun c */
    m->item_highlighted(m->highlighted_item);
}


/*****************************************************************************
 * FUNCTION
 *  gui_3D_circular_menu_goto_item
 * DESCRIPTION
 *  Highlight a specified item.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 *  i       [IN]        item index to be highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void gui_3D_circular_menu_goto_item(UI_3D_circular_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_highlighted_item = m->highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i >= 0 && i <= (m->n_items - 1))
    {
        m->highlighted_item = i;
    }
    /* call unhighlighted func */
    m->item_unhighlighted(old_highlighted_item);
    /* call highlighted func */
    if (MMI_current_menu_type == CIRCULAR_3D_MENU)
    {
        m->item_highlighted(m->highlighted_item);
    }
    else
    {
        if (m->highlighted_item == m->n_items - 1)
        {
            m->item_highlighted(0);
        }
        else
        {
            m->item_highlighted(m->highlighted_item + 1);
        }
    }
}

#include "kal_non_specific_general_types.h"
#include "lcd_sw.h"
#include "gdi_include.h"
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;


/*****************************************************************************
 * FUNCTION
 *  gui_show_3D_circular_menu
 * DESCRIPTION
 *  Show the 3D circular menu.
 * PARAMETERS
 *  m       [IN]        3D circular menu object
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_3D_circular_menu(UI_3D_circular_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 cx1, cy1, cx2, cy2;
    S32 tx1, ty1, tx2, ty2;
    S32 i, j, n, h, tx, ty, tw, th;
    S32 x, y, nr;
    S32 ni = m->n_item_images;
    U32 flags = m->flags;
    UI_string_type text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_get_clip(&cx1, &cy1, &cx2, &cy2);
    gui_get_text_clip(&tx1, &ty1, &tx2, &ty2);
    x1 = m->x;                  /* start x of 3d circular menu */
    y1 = m->y;                  /* start y position of 3d circular menu */
    x2 = x1 + m->width - 1;     /* end x position of 3d circular menu */
    y2 = y1 + m->height - 1;    /* end y position of 3d circular menu */
    ty = ((y2 - y1) >> 1) + y1;

    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);
    
    if (!(m->flags & UI_3D_CIRCULAR_MENU_DISABLE_BACKGROUND))
    {
        if ((gui_is_entry_new_screen() == MMI_TRUE) && (gui_get_multilayer_mask() & UI_MUL_BKG_MAINMENU))
        {
        #if (defined(__MMI_SUBMENU_USE_MM_IMAGE__) || (!defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_MAINMENU_ROTATE_SUPPORT__)) || !defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) /* 071705 Calvin modified */
            /* store the current frame number of animation wallppaer */
            extern S32 cat33_frame_number;

            /* store the image id of wallpaper */
            extern U16 idle_screen_wallpaper_ID;
            extern S8 *idle_screen_wallpaper_name;

            /* store the x position of wallpaer of idle screen */
            extern S32 cat33_image_x;

            /* store the y position of wallpaer of idle screen */
            extern S32 cat33_image_y;
        #else /* (defined(__MMI_SUBMENU_USE_MM_IMAGE__) || (!defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_MAINMENU_ROTATE_SUPPORT__)) || !defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) */ 
            S32 frame_number = 0;
            PU8 bg_img = NULL;
        #endif /* (defined(__MMI_SUBMENU_USE_MM_IMAGE__) || (!defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_MAINMENU_ROTATE_SUPPORT__)) || !defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) */ 

            gui_set_entry_new_screen(MMI_FALSE);

            /* Enable multilayer */
            gdi_layer_multi_layer_enable();
            gdi_layer_get_base_handle(&wgui_base_layer);

            /* gui_layer_transparent(wgui_base_layer, UI_SUBMENU_OPACITY_BASED_LAYER, x1,y1,x2,y2+1); */
            gui_layer_transparent(wgui_base_layer, UI_SUBMENU_OPACITY_BASED_LAYER, x1, y1, x2, y2);

            /* Create multilayer buffer */
            if (wgui_layer_1 == GDI_LAYER_EMPTY_HANDLE)
            {
                dm_create_layer(0, 0, UI_device_width, UI_device_height, &wgui_layer_1, DM_LAYER_ACTIVE_TOP);
            }
        #if (defined(__MMI_SUBMENU_USE_MM_IMAGE__) || (!defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_MAINMENU_ROTATE_SUPPORT__)) || !defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) /* 071705 Calvin modified */
            if (idle_screen_wallpaper_ID != 0)
            {
                gui_layer_show_animation_ID(
                    wgui_layer_1,
                    UI_SUBMENU_OPACITY_LAYER1,
                    &cat33_frame_number,
                    idle_screen_wallpaper_ID,
                    x1,
                    y1,
                    x2,
                    y2,
                    cat33_image_x,
                    cat33_image_y);
            }
            else
            {
                gui_layer_show_animation_file(
                    wgui_layer_1,
                    UI_SUBMENU_OPACITY_LAYER1,
                    &cat33_frame_number,
                    idle_screen_wallpaper_name,
                    x1,
                    y1,
                    x2,
                    y2,
                    cat33_image_x,
                    cat33_image_y);
            }
        #else /* (defined(__MMI_SUBMENU_USE_MM_IMAGE__) || (!defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_MAINMENU_ROTATE_SUPPORT__)) || !defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) */ 
            bg_img = (PU8) GetImage((U16) IMG_MAIN_MENU_CIRCULAR_BG);
            if (bg_img != NULL)
            {
                gui_layer_show_animation_ID(
                    wgui_layer_1,
                    UI_SUBMENU_OPACITY_BASED_LAYER,
                    &frame_number,
                    IMG_MAIN_MENU_CIRCULAR_BG,
                    x1,
                    y1,
                    x2,
                    y2,
                    0,
                    0);
            }
            else
            {
            #ifdef __GDI_MEMORY_PROFILE_2__
                GDI_HANDLE gdi_base_layer_hdlr;

                gdi_layer_set_active(wgui_layer_1);
                gdi_layer_lock_frame_buffer();
                gdi_layer_push_clip();
                gdi_layer_set_clip(x1, y1, x2, y2);
                gdi_layer_set_opacity(TRUE, UI_SUBMENU_OPACITY_BASED_LAYER);
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
                gdi_layer_pop_clip();
                gdi_layer_unlock_frame_buffer();
                gdi_layer_restore_base_active();
                gdi_layer_get_base_handle(&gdi_base_layer_hdlr);
                gdi_layer_set_blt_layer(wgui_layer_1, gdi_base_layer_hdlr, 0, 0);
                gdi_layer_blt_previous(x1, y1, x2, y2);
            #endif /* __GDI_MEMORY_PROFILE_2__ */ 
            }
        #endif /* (defined(__MMI_SUBMENU_USE_MM_IMAGE__) || (!defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && !defined(__MMI_MAINMENU_ROTATE_SUPPORT__)) || !defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) */ 
            gdi_layer_set_active(wgui_base_layer);
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
        else if (gui_get_multilayer_mask() & UI_MUL_BKG_MAINMENU)
        {
            gdi_layer_get_base_handle(&wgui_base_layer);
            /* gui_layer_transparent(wgui_base_layer, UI_SUBMENU_OPACITY_BASED_LAYER, x1,y1,x2,y2+1); */
            gui_layer_transparent(wgui_base_layer, UI_SUBMENU_OPACITY_BASED_LAYER, x1, y1, x2, y2);
            gdi_layer_set_active(wgui_base_layer);
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }
        else
        {
        #if ((defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) || defined (__MMI_MAINMENU_ROTATE_SUPPORT__)) && defined(__MMI_MAINMENU_STYLE_CHANGE_EN__))
            PU8 bg_img = NULL;

            bg_img = (PU8) GetImage((U16) IMG_MAIN_MENU_CIRCULAR_BG);
            if (bg_img != NULL)
            {
                gui_show_image(x1, y1, bg_img);
            }
            else
            {
                gui_set_clip(x1, y1, x2, y2);
                gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
                /* gui_draw_filled_area(x1, y1, x2, y2,m->bg_filler); */
            }
        #else /* ((defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) || defined (__MMI_MAINMENU_ROTATE_SUPPORT__)) && defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) */ 
            gui_set_clip(x1, y1, x2, y2);
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        #endif /* ((defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) || defined (__MMI_MAINMENU_ROTATE_SUPPORT__)) && defined(__MMI_MAINMENU_STYLE_CHANGE_EN__)) */ 
        }
    }

    if (m->n_items > 0)
    {
        nr = m->n_displayed_items - 2 - ni; /* -2 because of 2 off-screen */

        if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1))
        {
            j = (m->n_displayed_items - 2) * 3 + 2;
        }
        else if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2))
        {
            j = (m->n_displayed_items - 2) * 3 + 1;
        }
        else
        {
            j = (m->n_displayed_items - 2) * 3 + 0;
        }
        if (MMI_current_menu_type == CIRCULAR_3D_MENU)
        {
            for (i = (nr - 1); i >= 0; i--)
            {
                x = m->item_positions[j].x + x1;
                y = m->item_positions[j].y + y1;
                /* show transaparent imag e */
                gui_show_transparent_image(x, y, m->common_images[i], 0);
                j -= ni;
            }
        }
        else    /* For 3D Rotate Menu */
        {
            for (i = (nr - 1); i >= 0; i--)
            {
                j -= ni;
            }
        }
        n = ni;
        h = (m->highlighted_item + n - 1) % (m->n_items);
        if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2))
        {
            if (h == (m->n_items - 1))
            {
                h = 0;
            }
            else
            {
                h++;
            }
        }
        if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1))
        {
            x = m->item_positions[j].x + x1;
            y = m->item_positions[j].y + y1;

            /* show transaparent animated image frame */
            if (MMI_current_menu_type == CIRCULAR_3D_MENU)
            {
                gui_show_transparent_animated_image_frame(x, y, m->item_images[h], 0, (S16) (0));
            }

            if (h == 0)
            {
                h = m->n_items - 1;
            }
            else
            {
                h--;
            }
            j -= ni;
        }

        if (MMI_current_menu_type == CIRCULAR_3D_MENU)
        {
            for (i = 0; i < ni; i++)
            {
                x = m->item_positions[j].x + x1;
                y = m->item_positions[j].y + y1;
                /* show transaparent animated  image frame */
                gui_show_transparent_animated_image_frame(x, y, m->item_images[h], 0, (S16) i);
                if (h == 0)
                {
                    h = m->n_items - 1;
                }
                else
                {
                    h--;
                }
                j -= ni;
            }
            if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2))
            {
                x = m->item_positions[j].x + x1;
                y = m->item_positions[j].y + y1;
                /* show transaparent image */
                gui_show_transparent_image(x, y, m->item_images[h], 0);
            }
        }
        else
        {
            for (i = 0; i < ni; i++)
            {
                x = m->item_positions[j].x + x1;
                y = m->item_positions[j].y + y1;
                /* show transaparent animated  image frame */
                if (i == 1)
                {
                    if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2) ||
                        (flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1))
                    {
                        gui_show_transparent_animated_image_frame(x, y, m->item_images[h], 0, (S16) 1);
                    }
                    else
                    {
                        gui_show_transparent_animated_image_frame(x, y, m->item_images[h], 0, (S16) 2);
                    }
                }
                else
                {
                    gui_show_transparent_animated_image_frame(x, y, m->item_images[h], 0, (S16) 0);
                }
                if (h == 0)
                {
                    h = m->n_items - 1;
                }
                else
                {
                    h--;
                }
                j -= ni;
            }
            if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2))
            {
                x = m->item_positions[j].x + x1;
                y = m->item_positions[j].y + y1;

                /* show transaparent image */
                if (MMI_current_menu_type == CIRCULAR_3D_MENU)
                {
                    gui_show_transparent_image(x, y, m->item_images[h], 0);
                }
            }
        }

        if (m->item_strings != NULL)
        {
            if (MMI_current_menu_type == CIRCULAR_3D_MENU)
            {
                text = m->item_strings[(m->highlighted_item)];
            }
            else
            {
                if (m->highlighted_item == (m->n_items - 1))
                {
                    text = m->item_strings[0];  /* change the text here PDG1 KM */
                }
                else
                {
                    text = m->item_strings[(m->highlighted_item) + 1];
                }
            }
            gui_set_font(m->text_font);
            /* get string width */
            tw = gui_get_string_width(text);
            /* get character height */
            th = gui_get_character_height();
            if (MMI_current_menu_type == CIRCULAR_3D_MENU)
            {
                tx = x2 - tw - 2;
                ty -= th;
            }
            else
            {
            #ifdef ROTATE_HORI      /* this is center allign */
                if (tw < UI_device_width)
                {
                    tx = (UI_device_width - tw) / 2;
                }
                else
                {
                    tx = 0;
                }
                ty -= th;
                ty += 60;
                if (ty + th > y2)
                {
                    ty = (UI_device_height - (th + MMI_BUTTON_BAR_HEIGHT)) - 3;
                }
            #endif /* ROTATE_HORI */ 
            #ifdef ROTATE_VERT      /* for vertical this is right allign */
                tx = x2 - tw - 2;
                /* ty-=th; */
                ty = (UI_device_height - (th + MMI_BUTTON_BAR_HEIGHT)) - 3;
            #endif /* ROTATE_VERT */ 
            #ifdef ROTATE_VERT_CIR  /* for vertical this is right allign */
                tx = x2 - tw - 2;
                /* ty-=th; */
                ty = (UI_device_height - (th + MMI_BUTTON_BAR_HEIGHT)) - 3;
            #endif /* ROTATE_VERT_CIR */ 
            #ifdef ROTATE_VERT_LINE /* for vertical this is central allign */
                if (tw < UI_device_width)
                {
                    tx = x2 - tw - 2;
                }
                else
                {
                    tx = 0;
                }
                /* ty-=th; */
                ty = m->item_positions[6].y - th / 2 + 34;
            #endif /* ROTATE_VERT_LINE */ 
            #ifdef ROTATE_VERT_LINE_RIGHT   /* for vertical this is central allign */
                tx = 2;
                ty -= th;
            #endif /* ROTATE_VERT_LINE_RIGHT */ 
            }

            if (!r2lMMIFlag)
            {
                gui_move_text_cursor(tx, ty);
            }
            else
            {
                gui_move_text_cursor(tx + tw - 1, ty);
            }

            /* set text border color */
            gui_set_text_border_color(m->text_border);
            /* set text colrr */
            gui_set_text_color(m->text_color);
            /* print text */
            gui_print_bordered_text(text);
        }
    }
    gui_set_text_clip(tx1, ty1, tx2, ty2);
    gui_set_clip(cx1, cy1, cx2, cy2);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_3D_circular_menu_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the 3D circular menu.
 * PARAMETERS
 *  m               [IN]      3D circular menu object   
 *  pen_event       [IN]      pen event type
 *  x               [IN]      pen x  
 *  y               [IN]      pen y  
 *  menu_event      [OUT]     pen event result
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL gui_3D_circular_menu_translate_pen_event(
        UI_3D_circular_menu *m,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_3D_circular_menu_pen_enum *menu_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    U32 flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = MMI_TRUE;
    *menu_event = GUI_3D_CIRCULAR_MENU_PEN_NONE;
    flags = m->flags;

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        if (PEN_CHECK_BOUND(x, y, m->x, m->y, m->width, m->height))
        {
            S32 center_x1, center_y1;
            S32 iw, ih;

            m->pen_down_on_focused_item = MMI_FALSE;

            gui_measure_image(m->item_images[m->highlighted_item], &iw, &ih);

            if ((flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1) ||
                (flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2) ||
                (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1) || (flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2))
            {
                /* Discard pen events in animation */
            }
            else if (MMI_current_menu_type == CIRCULAR_3D_MENU)
            {
                center_x1 = m->x + m->item_positions[3].x;
                center_y1 = m->y + m->item_positions[3].y;

                if (PEN_CHECK_BOUND(x, y, center_x1, center_y1, iw, ih))
                {
                    m->pen_down_on_focused_item = MMI_TRUE;
                }
                else if (x - m->x < (m->width >> 1))
                {
                    *menu_event = GUI_3D_CIRCULAR_MENU_PEN_GOTO_NEXT;
                }
                else
                {
                    *menu_event = GUI_3D_CIRCULAR_MENU_PEN_GOTO_PREVIOUS;
                }
            }
            else
            {
                center_x1 = m->x + m->item_positions[6].x;
                center_y1 = m->y + m->item_positions[6].y;

                if (PEN_CHECK_BOUND(x, y, center_x1, center_y1, iw, ih))
                {
                    m->pen_down_on_focused_item = MMI_TRUE;
                }
            #ifdef ROTATE_HORI
                else if (x - m->x < (m->width >> 1))
            #else 
                else if (y - m->y < (m->height >> 1))
            #endif 
                {
                    *menu_event = GUI_3D_CIRCULAR_MENU_PEN_GOTO_NEXT;
                }
                else
                {
                    *menu_event = GUI_3D_CIRCULAR_MENU_PEN_GOTO_PREVIOUS;
                }
            }
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    else if (pen_event == MMI_PEN_EVENT_UP)
    {
        if (m->pen_down_on_focused_item)
        {
            *menu_event = GUI_3D_CIRCULAR_MENU_PEN_ITEM_SELECTED;
        }
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU)) */ /* Enable 3D menu */

