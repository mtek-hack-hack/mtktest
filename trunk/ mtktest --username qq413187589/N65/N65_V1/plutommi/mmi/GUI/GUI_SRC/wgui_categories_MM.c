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
 *   wgui_categories_MM.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Main Menu related categories.
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"
#include "DebugInitDef.h"

#include "GlobalDefs.h"
#include "gui_data_types.h"
#include "gui_themes.h"
#include "gui.h"
#ifdef __MMI_UI_TECHNO_STATUS_ICON__
#include "Gui_Setting.h"
#endif 
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "EventsDef.h"
#include "CustThemesRes.h"
#include "MainMenuDef.h"
#include "MainMenuType.h"
#include "gdi_include.h"
#include "lcd_sw_rnd.h"
#include "wgui.h"
#include "wgui_inputs.h"
#include "wgui_categories.h"
#include "wgui_softkeys.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_defs.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_MM.h"
#ifdef __MMI_WGUI_MINI_TAB_BAR__
#include "wgui_tab_bars.h"
#endif 
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "SATGProts.h"
#include "app_mem.h"

#include "wgui_status_icons.h"

/************ Global Variables *************/
extern S32 wgui_current_pop_up_description_index;
extern color active_title_txt_border_col;
extern BOOL r2lMMIFlag;

#ifdef __MMI_UI_TITLE_TRANSITION__
extern void set_title_transition(wgui_transition_styles style);
extern void reset_title_transition(void);
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 
#ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__
extern void register_horizontal_fixed_list_keys(void);
#endif 
extern void standard_animated_matrix_highlight_handler_type2(S32 item_index);

UI_string_type MMI_bg_string;
PU8 MMI_bg_image;
PU8 MMI_bg_animation;

#if (ENABLE_DIRECT_MAIN_MENU_IMPLEMENTATION)

/* Direct main menu implementation                                */
/* Matrix main menu: Fixed number of items with all items being visible */
#define MAIN_MENU_N_ROWS                     (3)
#define MAIN_MENU_N_COLUMNS                  (3)
#define MAIN_MENU_MAX_ITEMS                  (MAIN_MENU_N_ROWS*MAIN_MENU_N_COLUMNS)
#define MAIN_MENU_HIGHLIGHT_OFFSET_X            ((MAIN_MENU_HIGHLIGHTED_IMAGE_WIDTH>>1)-(MAIN_MENU_NORMAL_IMAGE_WIDTH>>1))
#define MAIN_MENU_HIGHLIGHT_OFFSET_Y            ((MAIN_MENU_HIGHLIGHTED_IMAGE_HEIGHT>>1)-(MAIN_MENU_NORMAL_IMAGE_HEIGHT>>1))
#define MAIN_MENU_HIGHLIGHTED_GRID_COLOR     {  0,0,0,100      }
#define MAIN_MENU_NORMAL_GRID_COLOR          {  160,160,160,100   }
#define MAIN_MENU_X1                      (0)
#define MAIN_MENU_Y1                      (MMI_TITLE_HEIGHT+1)
#define MAIN_MENU_X2                      (127)
#define MAIN_MENU_Y2                      (MMI_TITLE_HEIGHT+100+1)

#define MAIN_MENU_ITEM_HIGHLIGHTED           0x00000001
#define MAIN_MENU_LOOP                       0x00000002
#define MAIN_MENU_DISPLAY_GRID               0x00000004
#define MAIN_MENU_DISPLAY_ITEM_GRID          0x00000008

extern U16 title_bg_id;
extern icontext_button MMI_softkeys[];

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);
extern void (*MMI_matrix_highlight_handler) (S32 index);

/* structure of matrix menu */
/* Store current main menu type..matrix,list,circular */
S32 MMI_main_menu_type = MATRIX_MENU;
U16 gMainMenuAnimation[MAX_MAIN_MENU_ITEMS];
U16 gMainMenuTitleIcon[MAX_MAIN_MENU_ITEMS];
S32 main_menu_index = -1;

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
void (*Cat414MatrixExitHandler) (S32 index) = NULL;
#endif 

/* 082806 240x320 matrix Start */
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static MMI_ID_TYPE mm_bg_ID;
static S8 *mm_bg_filename;
static S32 mm_bg_x, mm_bg_y;
static U8 mm_bg_opacity;
static S32 mm_bg_flags;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */ 
/* 082806 240x320 matrix End */

#endif /* (ENABLE_DIRECT_MAIN_MENU_IMPLEMENTATION) */ 

/* For 3D circular main menu */
extern gdi_handle animation_handle;

#ifdef __MMI_UI_TECHNO_STATUS_ICON__
extern void arrange_status_icons();
extern void show_status_icons();
#endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
#if((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))
extern void stop_rotate_circular_menu(void);
#endif 

#if ENABLE_CIRCULAR_3D_MENU

/*****************************************************************************
 * FUNCTION
 *  set_circular_menu_category_history
 * DESCRIPTION
 *  set main menu matirx history
 * PARAMETERS
 *  history_ID          [IN]        History ID
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
U8 set_circular_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        circular_menu_category_history *h = (circular_menu_category_history*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            wgui_CM3D_menu.highlighted_item = h->highlighted_item;
            wgui_CM3D_menu.flags = h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  get_circular_menu_category_history
 * DESCRIPTION
 *  get main menu matirx history
 * PARAMETERS
 *  history_ID          [IN]        History ID
 *  history_buffer      [OUT]       History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void get_circular_menu_category_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        circular_menu_category_history *h = (circular_menu_category_history*) history_buffer;

        h->history_ID = hID;
        h->highlighted_item = (S16) wgui_CM3D_menu.highlighted_item;
        h->flags = wgui_CM3D_menu.flags;
    }
}

#endif /* ENABLE_CIRCULAR_3D_MENU */


/*****************************************************************************
 * FUNCTION
 *  draw_bg_animation
 * DESCRIPTION
 *  Displays the background image for new mainmenu category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_bg_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iw, ih;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image(MMI_bg_animation, &iw, &ih);
    if (animation_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(animation_handle);
    }
    wgui_set_animation_image(MMI_content_width - iw, UI_device_height - MMI_button_bar_height - ih, MMI_bg_animation);
    gui_set_clip(
        MMI_content_width - iw,
        UI_device_height - MMI_button_bar_height - ih,
        MMI_content_width - 1,
        UI_device_height - MMI_button_bar_height);
    gdi_image_draw_animation(
        MMI_content_width - iw,
        UI_device_height - MMI_button_bar_height - ih,
        MMI_bg_animation,
        &animation_handle);
}


/*****************************************************************************
 * FUNCTION
 *  draw_bg
 * DESCRIPTION
 *  Displays the background image for new mainmenu category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, character_height, tx, w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();
    gdi_layer_push_text_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_layer_set_text_clip(
        MMI_title_x,
        MMI_title_y,
        MMI_title_x + MMI_title_width - 1,
        MMI_title_y + MMI_title_height - 1);
    if (MMI_bg_image != NULL)
    {
        gui_measure_image(MMI_bg_image, &iwidth, &iheight);
        gui_show_image(0, 0, MMI_bg_image);
    }

    if (!r2lMMIFlag)
    {
        tx = 2;
    }
    else
    {
        tx = MMI_title_width - 2;
    }

    if (MMI_bg_string != NULL)  /* Fix for long titles  */
    {
        S32 tw;

        if (!r2lMMIFlag)
        {
            tw = MMI_title_width - tx;
        }
        else
        {
            tw = tx;
        }

        gui_set_font((UI_font_type) (current_MMI_theme->window_title_font));
        gui_measure_string(MMI_bg_string, &w, &character_height);
        gui_set_text_color(*current_MMI_theme->title_text_color);
        gui_set_text_border_color(*current_MMI_theme->title_text_border_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(
                MMI_title_x + tx + w,
                MMI_title_y + ((MMI_title_height >> 1) - (character_height >> 1)));
        }
        else
        {
            gui_move_text_cursor(MMI_title_x + tx, MMI_title_y + ((MMI_title_height >> 1) - (character_height >> 1)));
        }
        if (!MMI_disable_title_shortcut_display && MMI_menu_shortcut_number >= 0)
        {
            tw -= MMI_menu_shortcut_box.width;
            if (w < tw)
            {
                S32 _tx = tx;

                if (!r2lMMIFlag)
                {
                    tx = tx + (tw >> 1) - (w >> 1); /* Centers the title */
                    if (tx < _tx)
                    {
                        tx = _tx;
                    }
                }
                else
                {
                    tx = (MMI_title_width >> 1) - (w >> 1);
                    tx += w;
                    if (tx > _tx)
                    {
                        tx = _tx;
                    }
                }
            }
        }
        else
        {
            if (w < tw)
            {
                S32 _tx = tx;

                if (!r2lMMIFlag)
                {
                    tx = (MMI_title_width >> 1) - (w >> 1);
                    if (tx < _tx)
                    {
                        tx = _tx;
                    }
                }
                else
                {
                    tx = (MMI_title_width >> 1) - (w >> 1);
                    tx += w;
                    if (tx > _tx)
                    {
                        tx = _tx;
                    }
                }
            }
        }
    #if defined(__MMI_DEFAULT_THEME_3__) || defined(__MMI_DEFAULT_THEME_1__)
        gui_print_truncated_borderd_text(
            MMI_title_x + tx,
            MMI_title_y + ((MMI_title_height >> 1) - (character_height >> 1)),
            tw,
            MMI_bg_string);
    #else /* defined(__MMI_DEFAULT_THEME_3__) || defined(__MMI_DEFAULT_THEME_1__) */ 
        gui_print_truncated_text(
            MMI_title_x + tx,
            MMI_title_y + ((MMI_title_height >> 1) - (character_height >> 1)),
            tw,
            MMI_bg_string);
    #endif /* defined(__MMI_DEFAULT_THEME_3__) || defined(__MMI_DEFAULT_THEME_1__) */ 
    }
    gdi_layer_unlock_frame_buffer();
    show_menu_shortcut();
    gdi_layer_blt_previous(
        MMI_title_x,
        MMI_title_y,
        MMI_title_x + MMI_title_width - 1,
        MMI_title_y + MMI_title_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  standard_circular_3d_highlight_handler
 * DESCRIPTION
 *  System Highlight handler of 3d circular list
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_circular_3d_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_menu_shortcut_number = item_index + 1;
    MMI_highlighted_item_text = get_item_text(item_index);
    MMI_circular_3D_highlight_handler(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  standard_bg_ani_list_highlight_handler
 * DESCRIPTION
 *  System Highlight handler of bg_ani_list
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void standard_bg_ani_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();
    MMI_menu_shortcut_number = item_index + 1;
    MMI_highlighted_item_text = get_item_text(item_index);
    MMI_bg_string = MMI_highlighted_item_text;
    MMI_bg_image = get_image((MMI_ID_TYPE) (MAIN_MENU_BG_IMAGE_BASE + item_index));
    switch (item_index)
    {
        case 0:
        case 1:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_PHONEBOOK_ICON + item_index));
            break;
        case 2:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_CALL_HISTORY_ICON));
            break;
        case 3:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_SETTINGS_ICON));
            break;
        case 4:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_FUNANDGAMES_ICON));
            break;
        case 5:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_PROFILES_ICON));
            break;
        case 6:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_ORGANIZER_ICON));
            break;
        case 7:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_SERVICES_ICON));
            break;
        case 8:
            MMI_bg_animation = get_image((MMI_ID_TYPE) (MAIN_MENU_SHORTCUTS_ICON));
            break;

    }
    ExecuteCurrHiliteHandler(item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}


/*****************************************************************************
 * FUNCTION
 *  hide_main_menu_animation_frame
 * DESCRIPTION
 *  Hides the animating icon in a menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void hide_main_menu_animation_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_main_menu_type)
    {
        case LIST_MENU:
            break;
        case MATRIX_MENU:
            gui_hide_fixed_matrix_menu_highlighted_item(&MMI_fixed_matrix_menu);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  draw_main_menu_list_type_title
 * DESCRIPTION
 *  Redraws the category14 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_main_menu_list_type_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not redraw status bar because that will let integrated title status icons gone. */
    // show_title_status_icon();
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  category14_main_menu_list_highlight_handler
 * DESCRIPTION
 *  highlight handler for main menu lsit of category 14
 * PARAMETERS
 *  item_index      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void category14_main_menu_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
    if (MMI_main_menu_type == PAGE_MENU)
    {
        wgui_stop_transition_title_non_blocking();
        reset_title_transition();
    }
#ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    set_previous_title_shortcut(MMI_menu_shortcut_number);
#endif 
#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 
    MMI_menu_shortcut_number = item_index + 1;
    MMI_highlighted_item_text = get_item_text(item_index);
    MMI_title_string = MMI_highlighted_item_text;
    gdi_layer_lock_frame_buffer();
    MMI_list_highlight_handler(item_index);

    if (!menu_shortcut_handler_display)
    {
        draw_main_menu_list_type_title();
    }

    gui_hide_animations();

#ifdef __MMI_MAINLCD_320X240__
    /* change page background images */
    if (MMI_current_menu_type == PAGE_MENU)
    {
        dm_set_scr_bg_image(gMainMenuAnimation[item_index], NULL, -1, -1, 255);       
        /* check GDI_ERROR_HANDLE to prevent the goto item before the SCR BG layer is created. */
        if (dm_get_scr_bg_layer() != GDI_ERROR_HANDLE)
        {
            dm_draw_scr_bg_image();
        }
    }
#endif /* __MMI_MAINLCD_320X240__ */

#if (!defined(__MMI_UI_TECHNO_MAINMENU__))
    MMI_fixed_list_menu.item_display_function(
                            MMI_fixed_list_menu.items[MMI_fixed_list_menu.highlighted_item],
                            MMI_fixed_list_menu.common_item_data,
                            MMI_fixed_list_menu.x,
                            MMI_fixed_list_menu.y);
#endif /* (!defined(__MMI_UI_TECHNO_MAINMENU__)) */ 

    gdi_layer_unlock_frame_buffer();
#ifndef __MMI_UI_DALMATIAN_MAINMENU__
#ifdef __MMI_UI_TITLE_TRANSITION__
    if (MMI_main_menu_type == PAGE_MENU && is_mmi_title_transition_on_keys() == 0)
    {
        U16 keyCode, keyType;

        GetkeyInfo(&keyCode, &keyType);
    #ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__
        if (keyCode == KEY_RIGHT_ARROW)
    #else 
        if (keyCode == KEY_DOWN_ARROW || keyCode == KEY_VOL_DOWN)
    #endif 
        {
            set_title_transition(WGUI_TRANSITION_L2R);
            draw_title();
        #if(!TITLE_TRANSITION_STYLE_NON_BLOCKING)
            reset_title_transition();
        #endif 
        }
        else
    #ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__
        if (keyCode == KEY_LEFT_ARROW)
    #else 
        if (keyCode == KEY_UP_ARROW || keyCode == KEY_VOL_UP)
    #endif 
        {

            set_title_transition(WGUI_TRANSITION_R2L);
            draw_title();
        #if(!TITLE_TRANSITION_STYLE_NON_BLOCKING)
            reset_title_transition();
        #endif 
        }

    }
    else if (MMI_main_menu_type == PAGE_MENU && is_mmi_title_transition_on_keys() == 1)
    {
        draw_title();
    #if(!TITLE_TRANSITION_STYLE_NON_BLOCKING)
        reset_title_transition();
    #endif 
    }
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 
#endif /* __MMI_UI_DALMATIAN_MAINMENU__ */ 
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  initialize_mainmenu_title_icons
 * DESCRIPTION
 *  Called once during bootup to initialize category screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_mainmenu_title_icons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    MMI_ID_TYPE mm_iconID[MAX_MAIN_MENU_ITEMS];

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    U8 j = 0;
    U8 num_of_group = 0;
    U8 num_of_child = 0;
    U16 total_number = 0;
    U16 menu_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_group = (U8) GetNumOfChild(IDLE_SCREEN_MENU_ID);
    for (i = 0; i < num_of_group; i++)
    {
        menu_id = GetSeqItemId(IDLE_SCREEN_MENU_ID, (U16) i);
        num_of_child = (U8) GetNumOfChild(menu_id);
        GetSequenceImageIds(menu_id, mm_iconID);
        for (j = 0; j < num_of_child; j++)
        {
            MMI_ASSERT(total_number < MAX_MAIN_MENU_ITEMS);
            gMainMenuTitleIcon[total_number++] = MAIN_MENU_TITLE_ICON_BASE + mm_iconID[j] - MAIN_MENU_ICON_IMGBASE;
        }
    }
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    GetSequenceImageIds(IDLE_SCREEN_MENU_ID, mm_iconID);
    for (i = 0; i < MAX_MAIN_MENU_ITEMS; i++)
    {
        gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + mm_iconID[i] - MAIN_MENU_ICON_IMGBASE;
    }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
}


/*----------------------------------------------------------------------------
Function:		category14callback
Description:		callback from draw manager used to draw category 14 controlled area
Input Parameters:	co-ordinates
Output Parameters:	Void
Returns:			void
Remarks:			
----------------------------------------------------------------------------*/
#if defined __MMI_UI_TECHNO_MAINMENU__ || defined __MMI_UI_DALMATIAN_MAINMENU__
void category14_callback(dm_coordinates *coordinate)
{
#if defined(__MMI_UI_DALMATIAN_MAINMENU__)
	s32 i;
	s32 x1, y1, x2, y2;
#endif

#if defined(__MMI_UI_TECHNO_MAINMENU__)
	show_techno_menu();
#else
	show_fixed_list();
#endif

#if defined(__MMI_UI_DALMATIAN_MAINMENU__)
	gui_push_clip();
	initialize_balls();
	for(i = 0; i < NUMBER_OF_BALLS; i++)
	{
		x1 = *(ball[i].position + 0);
		y1 = *(ball[i].position + 1);
		x2 = x1 + BALL_WIDTH - 1;
		y2 = y1 + BALL_HEIGHT -1;
		if(x1 < MMI_content_x)
			x1 = MMI_content_x;
		if(y1 < MMI_content_y)
			y1 = MMI_content_y;
		if(x2> UI_device_width - 1)
			x2 = UI_device_width - 1;
		if(y2> UI_device_height - MMI_button_bar_height)
			y2 = UI_device_height - MMI_button_bar_height;
		_get_bitmap(x1, y1, x2, y2,	&ball[i].image);
	}
	gui_set_clip(MMI_content_x, MMI_content_y,
			UI_device_width - 1,
			UI_device_height - MMI_button_bar_height - 1);
	for(i = 0; i < NUMBER_OF_BALLS; i++)
	{
		gui_show_image(*(ball[i].position + 0),
				*(ball[i].position + 1),
				get_image(MAIN_MENU_DALMATIAN_BALL));
	}
	gui_pop_clip();
#endif

}
#endif


/*****************************************************************************
 * FUNCTION
 *  ShowCategory14Screen
 * DESCRIPTION
 *  Displays the category14 screen . this is a scrren to show main menu
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        (see explanation below)
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory14Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 i, shortcut_width;
    U8 h_flag;
    S32 ixsize, iysize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    gdi_layer_lock_frame_buffer();
    UI_disable_alignment_timers();
    MMI_menu_shortcut_number = -1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    create_fixed_icontext_menuitems();
    MMI_main_menu_type = flags & 0xf;
    MMI_current_menu_type = flags & 0x0f;
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

#ifdef __MMI_UI_TECHNO_STATUS_ICON__
    MMI_title_x = MMI_TITLE_X + MMI_SIGNAL_WIDTH;
    MMI_title_width = UI_device_width - (2 * MMI_SIGNAL_WIDTH);
    MMI_title_height = 26;
    MMI_content_y = MMI_content_y - MMI_TITLE_HEIGHT + MMI_title_height;
    MMI_content_height = MMI_content_height + MMI_TITLE_HEIGHT - MMI_title_height;
#endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
    switch (MMI_main_menu_type)
    {
        case ANI_BG_LIST_MENU:
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_LOOP;
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BACKGROUND;
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_CENTER_HIGHLIGHTED;
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_HIGHLIGHT_DISPLAY;
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_DISPLAY;
            resize_fixed_list(40, MMI_content_height + 2);
            associate_fixed_icontext_list();
            MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_MARQUEE_SCROLL;
            MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_TWO_DIRECTION_SCROLL;
            for (i = 0; i < number_of_items; i++)
            {
                add_fixed_icontext_item(get_string(list_of_items[i]), get_image(list_of_icons[i]));

            #ifdef __MMI_MERGE_SAT_TO_MAINMENU__
            #ifndef WAP_SUPPORT
                if (IsSATPresent() && list_of_items[i] == MAIN_MENU_SERVICES_TEXT)
                {
                    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items) - 1].item_text =
                        (UI_string_type) GetSATMainMenuAlphaID();
                }
            #endif /* WAP_SUPPORT */ 
            #endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

            }
            register_fixed_list_shortcut_handler();
            register_fixed_list_keys();

            shortcut_width = set_menu_item_count(number_of_items) + 7;
            resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
            move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);

            resize_fixed_icontext_menuitems(0, MMI_content_height / 3);
            set_fixed_icontext_positions(MMI_ICONTEXT_MENUITEM_HEIGHT + 2, 0, 1, 0);
            move_fixed_list(0, (MMI_title_y + MMI_title_height));

            resize_fixed_list(40, MMI_content_height + 2);

            register_fixed_list_highlight_handler(standard_bg_ani_list_highlight_handler);
            MMI_current_menu_type = ANI_BG_LIST_MENU;
            h_flag = set_list_menu_category_history(MMI_CATEGORY14_LIST_ID, history_buffer);
            MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_SCROLLBAR;
            if (h_flag)
            {
                fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
            }
            else
            {
                if (history_buffer != NULL && main_menu_index != -1)
                {
                    highlighted_item = main_menu_index;
                }
                fixed_list_goto_item_no_redraw(highlighted_item);
            }
            break;

        case LIST_MENU:
        #ifdef __MMI_UI_MM_LIST_NO_GRID__
            gui_disable_fixed_list_line_draw();
        #endif 

            resize_fixed_list(MMI_content_width, MMI_content_height + 2);
            associate_fixed_icontext_list();
            set_MMI_list_main_menu_theme();
            gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
            gui_set_fixed_icontext_menuitem_theme(
                &MMI_fixed_icontext_menuitem,
                current_UI_theme->fixed_icontext_menuitem_theme);
            for (i = 0; i < number_of_items; i++)
            {
                add_fixed_icontext_item(get_string(list_of_items[i]), wgui_get_list_menu_icon(i, list_of_icons[i]));
            #ifdef __MMI_MERGE_SAT_TO_MAINMENU__
            #ifndef WAP_SUPPORT
                if (IsSATPresent() && list_of_items[i] == MAIN_MENU_SERVICES_TEXT)
                {
                    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items) - 1].item_text =
                        (UI_string_type) GetSATMainMenuAlphaID();
                }
            #endif /* WAP_SUPPORT */ 
            #endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 
            #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
                gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + list_of_icons[i] - MAIN_MENU_LIST_ICON_IMGBASE;
            #else 
                gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + list_of_icons[i] - MAIN_MENU_ICON_IMGBASE;
            #endif 
            }
            register_fixed_list_shortcut_handler();
            register_fixed_list_keys();
            shortcut_width = set_menu_item_count(number_of_items) + 7;
            resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
            move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
            register_hide_menu_shortcut(draw_title);
            gui_measure_image(MMI_fixed_icontext_menuitems[0].item_icon, &ixsize, &iysize);
            set_fixed_icontext_positions(ixsize + 2, 0, 1, 0);
        #ifdef __MMI_MAINLCD_240X320__
            resize_fixed_icontext_menuitems(0, MMI_content_height / 6);
            title_bg_id = MAIN_MENU_LIST_TITLE_BG;
        #else /* __MMI_MAINLCD_240X320__ */ 
            resize_fixed_icontext_menuitems(0, MMI_content_height / 3);
        #endif /* __MMI_MAINLCD_240X320__ */ 

            register_fixed_list_highlight_handler(standard_list_highlight_handler);
            MMI_current_menu_type = LIST_MENU;
            resize_fixed_list_to_content_height();
            h_flag = set_list_menu_category_history(MMI_CATEGORY14_LIST_ID, history_buffer);
            MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_SCROLLBAR;
            if (h_flag)
            {
                fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
            }
            else
            {
                if (history_buffer != NULL && main_menu_index != -1)
                {
                    highlighted_item = main_menu_index;
                }
                fixed_list_goto_item_no_redraw(highlighted_item);
            }
        #if (!defined(__MMI_UI_TECHNO_MAINMENU__) && !defined(__MMI_UI_DALMATIAN_MAINMENU__))
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_FOCUSSED_ANIMATE;
        #endif             
            resize_fixed_icontext_menuitems_to_list_width();
            dm_data.s32CatId = MMI_CATEGORY14_LIST_ID;
            break;

        case PAGE_MENU:
            /* Temporary:  Needs to be enhanced */
            gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
            gui_set_fixed_icontext_menuitem_theme(
                &MMI_fixed_icontext_menuitem,
                current_UI_theme->fixed_icontext_menuitem_theme);

        #ifdef __MMI_UI_TECHNO_MAINMENU__
            create_techno_main_menu(number_of_items, list_of_icons);
        #endif 
#if defined __MMI_UI_TECHNO_MAINMENU__ || defined __MMI_UI_DALMATIAN_MAINMENU__
            dm_register_category_controlled_callback(category14_callback);
#endif
        #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
            enable_title_transition();
        #endif 
            resize_fixed_list(MMI_content_width, MMI_content_height + 2);
            associate_fixed_icontext_list();
            MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_MARQUEE_SCROLL;
            MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_TWO_DIRECTION_SCROLL;
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_CLIP;
            for (i = 0; i < number_of_items; i++)
            {
                /* Landscape page MM uses SCR BG images, not menu item icons. */
            #ifdef __MMI_MAINLCD_320X240__
                add_fixed_icontext_item(get_string(list_of_items[i]), NULL);
                /* save SCR BG image ID */
                gMainMenuAnimation[i] = list_of_icons[i];
            #else /* __MMI_MAINLCD_320X240__ */
                add_fixed_icontext_item(get_string(list_of_items[i]), get_image(list_of_icons[i]));
            #endif /* __MMI_MAINLCD_320X240__ */            

            #ifdef __MMI_MERGE_SAT_TO_MAINMENU__
            #ifndef WAP_SUPPORT
                if (IsSATPresent() && list_of_items[i] == MAIN_MENU_SERVICES_TEXT)
                {
                    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items) - 1].item_text =
                        (UI_string_type) GetSATMainMenuAlphaID();
                }
            #endif /* WAP_SUPPORT */ 
            #endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

            #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
                gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + list_of_icons[i] - MAIN_MENU_PAGE_ICON_IMGBASE;
            #else 
                gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + list_of_icons[i] - MAIN_MENU_ICON_IMGBASE;
            #endif
            }
            register_fixed_list_shortcut_handler();
        #ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__
            register_horizontal_fixed_list_keys();
        #else 
            register_fixed_list_keys();
        #endif 
            shortcut_width = set_menu_item_count(number_of_items) + 7;
            resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
            move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
            register_hide_menu_shortcut(draw_main_menu_list_type_title);
            move_fixed_list(0, (MMI_title_y + MMI_title_height));
            gui_measure_image(get_image(list_of_icons[0]), &ixsize, &iysize);
            resize_fixed_list(MMI_content_width, MMI_content_height);
            register_fixed_list_highlight_handler(category14_main_menu_list_highlight_handler);
            if (MMI_content_height < iysize)
            {
                resize_fixed_icontext_menuitems(MMI_content_width, MMI_content_height);
            }
            else
            {
                resize_fixed_icontext_menuitems(MMI_content_width, MMI_content_height);
            }

        #ifdef __MMI_MAINLCD_240X320__
            title_bg_id = MAIN_MENU_PAGE_TITLE_BG;
        #endif 

        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            title_bg_id = MAIN_MENU_PAGE_TITLE_BG;
            wgui_set_wallpaper_on_bottom(MMI_TRUE);
            dm_get_scr_bg_image(&mm_bg_ID, &mm_bg_filename, &mm_bg_x, &mm_bg_y, &mm_bg_opacity);
            dm_set_scr_bg_image(IMG_MAIN_MENU_PAGE_BG, NULL, -1, -1, 255);
            dm_get_scr_bg_flag(&mm_bg_flags);
            dm_set_scr_bg_flag(mm_bg_flags | DM_SCR_BG_FORCE_SHOW);
        #endif

            set_fixed_icontext_positions(0, 0, 0, (MMI_content_height - iysize) >> 1);
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_HIGHLIGHT | UI_MENUITEM_DISABLE_TEXT_DISPLAY;
            MMI_current_menu_type = PAGE_MENU;
            h_flag = set_list_menu_category_history(MMI_CATEGORY14_LIST_ID, history_buffer);
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
            if (h_flag)
            {
                fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
            }
            else
            {
                if (history_buffer != NULL && main_menu_index != -1)
                {
                    MMI_fixed_list_menu.highlighted_item = main_menu_index;
                    MMI_fixed_list_menu.first_displayed_item = main_menu_index;
                    MMI_fixed_list_menu.last_displayed_item = main_menu_index;
                    highlighted_item = main_menu_index;
                }
                fixed_list_goto_item_no_redraw(highlighted_item);
            }
        #if (!defined(__MMI_UI_TECHNO_MAINMENU__) && !defined(__MMI_UI_DALMATIAN_MAINMENU__))
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_FOCUSSED_ANIMATE;
        #endif 
            resize_fixed_icontext_menuitems_to_list_width();
            dm_data.s32CatId = MMI_CATEGORY14_LIST_ID;
            break;

        case MATRIX_MENU:
            associate_fixed_icontext_matrix();
            for (i = 0; i < number_of_items; i++)
            {
                add_fixed_icontext_item(get_string(list_of_items[i]), get_image(list_of_icons[i]));
            #ifdef __MMI_MERGE_SAT_TO_MAINMENU__
            #ifndef WAP_SUPPORT
                if (IsSATPresent() && list_of_items[i] == MAIN_MENU_SERVICES_TEXT)
                {
                    MMI_fixed_icontext_menuitems[(*fixed_icontext_menu_n_items) - 1].item_text =
                        (UI_string_type) GetSATMainMenuAlphaID();
                }
            #endif /* WAP_SUPPORT */ 
            #endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 
                gMainMenuAnimation[i] = MAIN_MENU_ICON_ANI_IMGBASE + list_of_icons[i] - MAIN_MENU_ICON_IMGBASE;
            #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
                gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + list_of_icons[i] - MAIN_MENU_MATRIX_ICON_IMGBASE;
            #else 
                gMainMenuTitleIcon[i] = MAIN_MENU_TITLE_ICON_BASE + list_of_icons[i] - MAIN_MENU_ICON_IMGBASE;
            #endif 
            }
            register_fixed_matrix_shortcut_handler();
            MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_LOOP | UI_MATRIX_MENU_FOR_MAINMENU;
        #if defined(__MMI_MAINMENU_MATRIX_LOOP__)
            {
                MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_VERTICAL_LOOP;
            }
        #endif /* defined(__MMI_MAINMENU_MATRIX_LOOP__) */ 
            register_fixed_matrix_loop_keys();
            MMI_current_menu_type = MATRIX_MENU;

            set_MMI_matrix_main_menu_theme();
            gui_set_fixed_matrix_menu_theme(&MMI_fixed_matrix_menu, current_UI_theme->fixed_matrix_menu_theme);
            gui_set_fixed_icontext_menuitem_theme(
                &MMI_fixed_icontext_menuitem,
                current_UI_theme->fixed_icontext_menuitem_theme);
            register_fixed_matrix_highlight_handler(standard_animated_matrix_highlight_handler_type2);
            move_fixed_matrix(0, (MMI_title_y + MMI_title_height));
            resize_fixed_matrix(MMI_content_width, MMI_content_height);
            if (number_of_items > 9)
            {
                ixsize = (MMI_content_width - MMI_fixed_matrix_menu.vbar.width - 6) / 3;
            }
            else
            {
                ixsize = (MMI_content_width - 6) / 3;
            }
            iysize = (MMI_content_height - 6) / 3;
            /* use image height as item height */
            gui_measure_image(get_image(list_of_icons[0]), &ixsize, &iysize);
            
        #ifdef __MMI_MAINLCD_320X240__
            configure_fixed_matrix(ixsize, iysize, 4, 0);
        #else /* __MMI_MAINLCD_320X240__ */
            configure_fixed_matrix(ixsize, iysize, 3, 0);
        #endif /* __MMI_MAINLCD_320X240__ */            
            
            shortcut_width = set_menu_item_count(number_of_items) + 7;
            resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
            move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
            register_hide_menu_shortcut(draw_title);
            set_fixed_icontext_positions(0, 0, 0, 0);
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_DISPLAY;
            MMI_disable_title_shortcut_display = 0;
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
            // title_bg_id = MAIN_MENU_MATRIX_TITLE_BG;
            // wgui_set_wallpaper_on_bottom(MMI_TRUE);
            // dm_get_scr_bg_image(&mm_bg_ID, &mm_bg_filename, &mm_bg_x, &mm_bg_y, &mm_bg_opacity);
            // dm_set_scr_bg_image(IMG_MAIN_MENU_MATRIX_BG, NULL, -1, -1, current_MMI_theme->bg_opacity_full);
            dm_get_scr_bg_flag(&mm_bg_flags);
            dm_set_scr_bg_flag(mm_bg_flags | DM_SCR_BG_FORCE_SHOW);
        #endif

            h_flag = set_matrix_menu_category_history(MMI_CATEGORY14_MATRIX_ID, history_buffer);
            if (h_flag)
        #ifdef __MMI_WGUI_MINI_TAB_BAR__
                if (wgui_if_mini_tab_bar_in_parent() == MMI_TRUE)
                {
                    S32 idx = (S32) wgui_mini_tab_bar_get_index();

                    fixed_matrix_goto_item_no_redraw(idx);
                }
                else
        #endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
                    fixed_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
            else
            {
                if (history_buffer != NULL && main_menu_index != -1)
                {
                    highlighted_item = main_menu_index;
                }
                fixed_matrix_goto_item_no_redraw(highlighted_item);
            }
            MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_FOCUSSED_ANIMATE;
            SetKeyHandler(fixed_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(fixed_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
            dm_data.s32CatId = MMI_CATEGORY14_MATRIX_ID;

        #ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
            /* allocate matrix highlight buffer from SCR ASM */      
            MMI_fixed_matrix_menu.buffer.buf_ptr = (U8*)applib_mem_screen_alloc(MMI_MAIN_MENU_MATRIX_HIGHLIGHTED_BUF_SIZE);
            MMI_ASSERT(MMI_fixed_matrix_menu.buffer.buf_ptr != NULL);
        #endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */
            break;

        #if(ENABLE_CIRCULAR_3D_MENU)
        case CIRCULAR_3D_MENU:
            entry_full_screen();
            MMI_current_menu_type = CIRCULAR_3D_MENU;
            create_circular_3d_menu(number_of_items, list_of_items, list_of_icons);
            register_circular_3d_menu_keys();
            register_circular_3d_highlight_handler(standard_circular_3d_highlight_handler);
            register_3d_menu_shortcut_handler();
            shortcut_width = set_menu_item_count(number_of_items) + 7;
            resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
            move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
            register_hide_menu_shortcut(show_circular_3d_menu);
            h_flag = set_circular_menu_category_history(MMI_CATEGORY14_CIRCULAR_ID, history_buffer);
            if (h_flag)
            {
                circular_3d_menu_goto_item_no_redraw(wgui_CM3D_menu.highlighted_item);
            }
            else
            {
                if (history_buffer != NULL && main_menu_index != -1)
                {
                    highlighted_item = main_menu_index;
                }
                circular_3d_menu_goto_item_no_redraw(highlighted_item);
            }
            dm_data.s32CatId = MMI_CATEGORY14_CIRCULAR_ID;
            break;
        #endif /* (ENABLE_CIRCULAR_3D_MENU) */ 
        #if(ENABLE_ROTATE_MENU)
        case ROTATE_MENU:
            entry_full_screen();
            MMI_current_menu_type = ROTATE_MENU;
            highlighted_item = number_of_items - 1;
            create_circular_3d_menu(number_of_items, list_of_items, list_of_icons);
            register_rotate_menu_keys();
            register_circular_3d_highlight_handler(standard_circular_3d_highlight_handler);
            register_3d_menu_shortcut_handler();
            shortcut_width = set_menu_item_count(number_of_items) + 7;
            resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
        #ifdef ROTATE_VERT_LINE_RIGHT
            move_menu_shortcut_handler(0, MMI_title_y);
        #else 
            move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
        #endif 
            register_hide_menu_shortcut(show_circular_3d_menu);

            h_flag = set_circular_menu_category_history(MMI_CATEGORY14_ROTATE_ID, history_buffer);
            if (h_flag)
            {
                circular_3d_menu_goto_item_no_redraw(wgui_CM3D_menu.highlighted_item);
            }
            else
            {
                if (history_buffer != NULL && main_menu_index != -1)
                {
                    highlighted_item = main_menu_index - 1;
                }
                circular_3d_menu_goto_item_no_redraw(highlighted_item);
            }
            dm_data.s32CatId = MMI_CATEGORY14_ROTATE_ID;
            break;
        #endif /* (ENABLE_ROTATE_MENU) */ 
    }

#ifdef __MMI_UI_TECHNO_STATUS_ICON__
    leave_full_screen();
#endif 
    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory14Screen;
    UI_hide_animation_frame_function = hide_main_menu_animation_frame;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory14History, GetCategory14HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory14Screen
 * DESCRIPTION
 *  Exits the category14 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory14Screen(void)
{
#if((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_main_menu_type == CIRCULAR_3D_MENU || MMI_main_menu_type == ROTATE_MENU)
    {
        stop_rotate_circular_menu();
    }
#endif /* ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU)) */ 
    UI_enable_alignment_timers();
    ClearHighlightHandler();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
    UI_hide_animation_frame_function = UI_dummy_function;
    gui_hide_animations();
#ifdef __MMI_UI_TECHNO_STATUS_ICON__
    MMI_title_x = MMI_TITLE_X;
    MMI_title_width = UI_device_width;
    MMI_title_height = MMI_TITLE_HEIGHT;
    MMI_content_y = MMI_CONTENT_Y;
    MMI_content_height = MMI_CONTENT_HEIGHT;
#endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
    switch (MMI_current_menu_type)
    {
        case ANI_BG_LIST_MENU:
            MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_CENTER_HIGHLIGHTED;
            MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_SCROLLBAR;
            MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_BACKGROUND;
            set_MMI_list_sub_menu_theme();
            gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
            gui_set_fixed_icontext_menuitem_theme(
                &MMI_fixed_icontext_menuitem,
                current_UI_theme->fixed_icontext_menuitem_theme);
            break;

        case LIST_MENU:
        case PAGE_MENU:
            /* disable lines grids on this category screen */
    #ifdef __MMI_UI_MM_LIST_NO_GRID__
            gui_enable_fixed_list_line_draw();
    #endif 

            MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_FOCUSSED_ANIMATE;
            set_MMI_list_sub_menu_theme();
            gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
            gui_set_fixed_icontext_menuitem_theme(
                &MMI_fixed_icontext_menuitem,
                current_UI_theme->fixed_icontext_menuitem_theme);
    #ifdef __MMI_MAINLCD_240X320__
            title_bg_id = 0;
    #endif 
    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
            disable_title_transition();
    #endif 

            if (MMI_current_menu_type == PAGE_MENU)
            {
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
                title_bg_id = 0;
                dm_set_scr_bg_flag(mm_bg_flags);
                dm_set_scr_bg_image_no_draw(mm_bg_ID, mm_bg_filename, mm_bg_x, mm_bg_y, mm_bg_opacity);
                wgui_reset_wallpaper_on_bottom();
#endif 
            }
            break;

        case MATRIX_MENU:
            MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_FOCUSSED_ANIMATE;
            MMI_fixed_matrix_menu.flags &= ~UI_MATRIX_MENU_FOR_MAINMENU;
            set_MMI_matrix_sub_menu_theme();
            gui_set_fixed_matrix_menu_theme(&MMI_fixed_matrix_menu, current_UI_theme->fixed_matrix_menu_theme);
            gui_set_fixed_icontext_menuitem_theme(
                &MMI_fixed_icontext_menuitem,
                current_UI_theme->fixed_icontext_menuitem_theme);
        #ifdef __MMI_WALLPAPER_ON_BOTTOM__
            title_bg_id = 0;
            dm_set_scr_bg_flag(mm_bg_flags);
            // dm_set_scr_bg_image_no_draw(mm_bg_ID, mm_bg_filename, mm_bg_x, mm_bg_y, mm_bg_opacity);
            // wgui_reset_wallpaper_on_bottom();
        #endif 

        #ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
            /* free matrix highlight buffer */
            applib_mem_screen_free(MMI_fixed_matrix_menu.buffer.buf_ptr);
        #endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */
            break;
    }
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_fixed_matrix();
#ifdef __MMI_UI_TECHNO_STATUS_ICON__
    arrange_status_icons();
    leave_full_screen();
#endif /* __MMI_UI_TECHNO_STATUS_ICON__ */ 
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory14HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the category14 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory14HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_menu_type)
    {
        case ANI_BG_LIST_MENU:
        case LIST_MENU:
        case PAGE_MENU:
            return (sizeof(list_menu_category_history));
            break;

        case MATRIX_MENU:
            return (sizeof(matrix_menu_category_history));
            break;
    #if(ENABLE_CIRCULAR_3D_MENU)
        case CIRCULAR_3D_MENU:
            return (sizeof(circular_menu_category_history));
            break;
    #endif /* (ENABLE_CIRCULAR_3D_MENU) */ 
    #if(ENABLE_ROTATE_MENU)
        case ROTATE_MENU:
            return (sizeof(circular_menu_category_history));
            break;
    #endif /* (ENABLE_ROTATE_MENU) */ 
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory14History
 * DESCRIPTION
 *  Gets the history buffer for the category14 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory14History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_current_menu_type)
    {
        case ANI_BG_LIST_MENU:
        case LIST_MENU:
        case PAGE_MENU:
            get_list_menu_category_history(MMI_CATEGORY14_LIST_ID, history_buffer);
            break;

        case MATRIX_MENU:
            get_matrix_menu_category_history(MMI_CATEGORY14_MATRIX_ID, history_buffer);
            break;
    #if(ENABLE_CIRCULAR_3D_MENU)
        case CIRCULAR_3D_MENU:
            get_circular_menu_category_history(MMI_CATEGORY14_CIRCULAR_ID, history_buffer);
            break;
    #endif /* (ENABLE_CIRCULAR_3D_MENU) */ 
    #if(ENABLE_ROTATE_MENU)
        case ROTATE_MENU:
            get_circular_menu_category_history(MMI_CATEGORY14_ROTATE_ID, history_buffer);
            break;
    #endif /* (ENABLE_ROTATE_MENU) */ 
    }
    return (history_buffer);
}

/* for new list_matrix menu style */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__

#if defined(__MMI_MAINLCD_240X320__)
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH   65
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_RATIO 3
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 20
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 3
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#elif defined(__MMI_MAINLCD_320X240__) /* defined(__MMI_MAINLCD_240X320__) */ 
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH  36
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_RATIO 2
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 2
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 0
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH   40
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_RATIO 2
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 20
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 3
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#endif /* defined(__MMI_MAINLCD_240X320__) */

extern void stop_fixed_icontext_menuitem_animation(S32 index);
extern void wgui_set_title_bknd_display(MMI_BOOL state);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
extern void set_fixed_icontext_list_type2(void);
extern void create_fixed_icontext_list_menuitems2(S32 n_text_columns, S32 n_icon_columns);
extern void associate_fixed_icontext_list_list2(void);
extern void restore_fixed_icontext_list_type(void);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

extern gdi_handle wgui_layer_1;
extern MMI_ID_TYPE idle_screen_wallpaper_ID;

MMI_BOOL back_from_history = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  Cat414MatrixHighlightHandler
 * DESCRIPTION
 *  highlight handler for main menu lsit of category 414 on bi degree main menu
 * PARAMETERS
 *  index       [IN]        Of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void Cat414MatrixHighlightHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_matrix_highlight_handler(index);
    register_fixed_matrix_loop_keys();  /* for right arrow keys */
}


/*****************************************************************************
 * FUNCTION
 *  ShowCat414Matrix
 * DESCRIPTION
 *  Displays the category414 matrix menu
 * PARAMETERS
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        Not used
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCat414Matrix(
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        matrix_menu_category_history *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 symbol_width = 0, symbol_height = 0, width = 0, height = 0, str_width = 0, str_height = 0;
    S32 item_width = 0, item_height = 0;
    S32 max_str_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cat414MatrixExitHandler = stop_fixed_icontext_menuitem_animation;
    gdi_layer_lock_frame_buffer();
    PowerAndEndKeyHandler();

    MMI_current_menu_type = LIST_MATRIX_MENU;
    create_fixed_icontext_menuitems();
    associate_fixed_icontext_matrix();
    set_MMI_current_fixed_icontext_menuitem_theme_matrix_bidegree_menu();
    gui_set_fixed_icontext_menuitem_current_theme(&MMI_fixed_icontext_menuitem);    

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_menuitem_transparent_effect();
    disable_fixed_icontext_menuitem_transparent_effect();
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ */ 

    resize_fixed_matrix(
        UI_device_width - MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH,
        UI_device_height - MMI_title_height - MMI_button_bar_height - MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT);

    gui_set_font(&MMI_default_font);

    for (i = 0; i < number_of_items; i++)
    {
        PU8             img = (PU8)get_image(list_of_icons[i]);
        UI_string_type  str = get_string(list_of_items[i]);

        add_fixed_icontext_item(str, img);
        gui_measure_image(img, &symbol_width, &symbol_height);
        if (symbol_width > width)
        {
            width = symbol_width;
        }
        if (symbol_height > height)
        {
            height = symbol_height;
        }

        gui_measure_string(str, &str_width, &str_height);
        if (str_height > max_str_height)
        {
            max_str_height = str_height;
        }
    }   

    /* Arabic needs max string height. */
    str_height = max_str_height;
    
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_FOCUSSED_ANIMATE | UI_MENUITEM_MARQUEE_SCROLL;
    MMI_fixed_matrix_menu.flags |=
        UI_MATRIX_MENU_VERTICAL_TRIGGER | UI_MATRIX_MENU_DISABLE_SCROLLBAR | UI_MATRIX_MENU_DISABLE_BACKGROUND | 
        UI_MATRIX_MENU_ALIGN_LEFT_TOP;
    register_fixed_matrix_loop_keys();
    register_fixed_matrix_highlight_handler(Cat414MatrixHighlightHandler);

    item_width =
        ((UI_device_width - MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH) / MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT) -
        MMI_BI_DEGREE_MAIN_MENU_GAP;
    item_height = MMI_fixed_matrix_menu.height / MMI_BI_DEGREE_MAIN_MENU_ROW_RATIO;
    if ((item_height - height - str_height - MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP) <= 1)       /* can't set iy=0; */
    {
        set_fixed_icontext_positions(1, item_height - str_height, 0, 1);
    }
    else
    {
        set_fixed_icontext_positions(
            1,
            item_height - str_height,
            0,
            (item_height - height - str_height - MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP) >> 1);
    }
    configure_fixed_matrix(
        item_width,
        item_height,
        MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT,
        MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT);
    move_fixed_matrix(MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH, MMI_title_height);

    if (back_from_history == MMI_TRUE)
    {
        set_matrix_menu_category_history(MMI_CATEGORY414_ID, (U8*) history_buffer);
        fixed_matrix_goto_item_no_redraw(MMI_fixed_matrix_menu.highlighted_item);
        back_from_history = MMI_FALSE;
    }
    else
    {
        fixed_matrix_goto_item_no_redraw(highlighted_item);
    }

    MMI_disable_title_shortcut_display = 1;
    show_fixed_matrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        MMI_fixed_matrix_menu.x,
        MMI_fixed_matrix_menu.y,
        MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
        MMI_fixed_matrix_menu.y + MMI_fixed_matrix_menu.height);

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory414Screen
 * DESCRIPTION
 *  Exits the category414 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory414Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_enable_alignment_timers();
    ClearHighlightHandler();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 

    UI_hide_animation_frame_function = UI_dummy_function;
    gui_hide_animations();

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_menuitem_transparent_effect();
#endif 

    /* re-enable integrated title status icon display */
    wgui_status_icon_integrated_enable(MMI_TRUE);

    MMI_fixed_icontext_menuitem.flags &= ~UI_MENUITEM_FOCUSSED_ANIMATE | UI_MENUITEM_MARQUEE_SCROLL;
    MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_DISABLE_TEXT_DISPLAY | UI_MENUITEM_HIGHLIGHT_SWITCH_ICON;
    MMI_fixed_matrix_menu.flags &= ~(UI_MATRIX_MENU_LOOP | UI_MATRIX_MENU_VERTICAL_TRIGGER | UI_MATRIX_MENU_ALIGN_LEFT_TOP);
    MMI_fixed_matrix_menu.flags &= ~UI_MATRIX_MENU_DISABLE_SCROLLBAR;
    MMI_fixed_matrix_menu.flags &= ~UI_MATRIX_MENU_DISABLE_BACKGROUND;
    MMI_fixed_matrix_menu.trigger_top_function = UI_dummy_function;
    MMI_fixed_matrix_menu.trigger_bottom_function = UI_dummy_function;
    gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
    gui_set_fixed_icontext_list_menuitem_theme(
        &MMI_fixed_icontext_list_menuitem,
        current_UI_theme->fixed_icontext_list_menuitem_theme);
    set_MMI_matrix_sub_menu_theme();
    gui_set_fixed_matrix_menu_current_theme(&MMI_fixed_matrix_menu);
    gui_set_fixed_icontext_menuitem_current_theme(&MMI_fixed_icontext_menuitem);    
        
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    enable_softkey_background();
    gdi_layer_multi_layer_disable();
    wgui_set_title_bknd_display(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory414HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the category414 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory414HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(list_matrix_menu_category_history);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory414History
 * DESCRIPTION
 *  Gets the history buffer for the category14 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategory414History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_matrix_menu_category_history(MMI_CATEGORY414_ID, history_buffer);
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  cat14_list_highlight_handler
 * DESCRIPTION
 *  highlight handler for main menu lsit of category 14 on bi degree
 * PARAMETERS
 *  index       [IN]        Of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void cat14_list_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat414MatrixExitHandler != NULL)
    {
        Cat414MatrixExitHandler(MMI_fixed_matrix_menu.highlighted_item);
    }
    MMI_list_highlight_handler(index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_list_matrix_menu_hide_lsk
 * DESCRIPTION
 *  left softkey hide function on bi degree
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_matrix_menu_hide_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
    gdi_draw_solid_rect(
        MMI_softkeys[MMI_LEFT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width,
        UI_device_height - 1,
        GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_list_matrix_menu_hide_rsk
 * DESCRIPTION
 *  right softkey hide function on bi degree
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_matrix_menu_hide_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(0, UI_device_height - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);
    gdi_draw_solid_rect(
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x,
        UI_device_height - MMI_button_bar_height,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width,
        UI_device_height - 1,
        GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  Cate414CategoryControlAreaPenDownHandler
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  point       [IN]        position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL Cate414CategoryControlAreaPenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  Cate414CategoryControlAreaPenUpHandler
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  point       [IN]        position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL Cate414CategoryControlAreaPenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  Cate414CategoryControlAreaPenAbortHandler
 * DESCRIPTION
 *  pen abort handler
 * PARAMETERS
 *  point       [IN]        position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL Cate414CategoryControlAreaPenAbortHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_ABORT);
}


/*****************************************************************************
 * FUNCTION
 *  Cate414CategoryControlAreaPenLongTapHandler
 * DESCRIPTION
 *  pen longtap handler
 * PARAMETERS
 *  point       [IN]        position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL Cate414CategoryControlAreaPenLongTapHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  Cate414CategoryControlAreaPenRepeatHandler
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  point       [IN]        position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL Cate414CategoryControlAreaPenRepeatHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  Cate414CategoryControlAreaPenMoveHandler
 * DESCRIPTION
 *  414 pen move handler
 * PARAMETERS
 *  point       [IN]        pen move position
 * RETURNS
 *  Is handled
 *****************************************************************************/
MMI_BOOL Cate414CategoryControlAreaPenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_general_pen_matrix_menu_hdlr(point, MMI_PEN_EVENT_MOVE);
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  ShowCategory414Screen
 * DESCRIPTION
 *  Displays the category414 screen . this is a scrren to show main menu
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  list_of_icons2          [IN]        Array of icons
 *  list_of_menuitem_id     [IN]        Array of menuitem ID
 *  flags                   [IN]        Not used
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory414Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        U16 *list_of_icons2,
        U16 *list_of_menuitem_id,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 i;
    U8 h_flag;
    S32 ixsize, iysize;
    gdi_handle base_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    Cat414MatrixExitHandler = NULL;
    UI_disable_alignment_timers();
    MMI_menu_shortcut_number = -1;
    entry_full_screen();
    disable_softkey_background();
    wgui_set_title_bknd_display(MMI_FALSE);
    gdi_layer_get_base_handle(&base_layer_handle);
    gdi_layer_set_active(base_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    MMI_title_string = get_string(title);
    MMI_title_icon = get_image(title_icon);

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();
    register_hide_left_softkey(wgui_list_matrix_menu_hide_lsk);
    register_hide_right_softkey(wgui_list_matrix_menu_hide_rsk);
    create_fixed_icontext_menuitems();
    set_fixed_icontext_list_type2();
    create_fixed_icontext_list_menuitems2(1, 2);

    gui_set_fixed_list_menu_theme(&MMI_fixed_list_menu, current_UI_theme->fixed_list_menu_theme);
    gui_set_fixed_icontext_list_menuitem_theme(
        &MMI_fixed_icontext_list_menuitem,
        current_UI_theme->fixed_icontext_list_menuitem_theme);

    associate_fixed_icontext_list_list2();
    wgui_register_list_item_selected_callback_all(UI_dummy_function);

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    disable_fixed_icontext_menuitem_transparent_effect();
#endif 

    gui_measure_image(get_image(list_of_icons2[0]), &ixsize, &iysize);
    set_fixed_icontext_list_text_coordinates(0, 0, 0, 0, 0);
    set_fixed_icontext_list_icon_coordinates(0, 0, 0, ixsize, iysize);
    set_fixed_icontext_list_icon_coordinates(1, 0, 0, ixsize, iysize);

    for (i = 0; i < number_of_items; i++)
    {
        fixed_icontext_list_item_insert(i);
        add_fixed_icontext_list_item_icon(i, 0, get_image(list_of_icons[i]));
        add_fixed_icontext_list_item_icon(i, 1, get_image(list_of_icons2[i]));
        add_fixed_icontext_list_item_text(i, 0, NULL);
    }

    register_fixed_list_highlight_handler(cat14_list_highlight_handler);

    resize_fixed_icontext_list_menuitems(ixsize, iysize);

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_DISPLAY | UI_MENUITEM_HIGHLIGHT_SWITCH_ICON | UI_MENUITEM_FOCUSSED_ANIMATE;
    MMI_current_menu_type = LIST_MENU;

    /* Disable scrollbar, background, and menu item gap. */
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR | UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_DISABLE_MENUITEM_GAP;
    MMI_fixed_matrix_menu.trigger_top_function = fixed_list_goto_previous_item;
    MMI_fixed_matrix_menu.trigger_bottom_function = fixed_list_goto_next_item;

    h_flag = set_list_matrix_menu_category_history(MMI_CATEGORY414_ID, history_buffer);
    if (h_flag)
    {
        back_from_history = MMI_TRUE;
    }
    else
    {
        back_from_history = MMI_FALSE;
    }

    gdi_layer_unlock_frame_buffer();
    restore_fixed_icontext_list_type();
    ExitCategoryFunction = ExitCategory414Screen;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(
        Cate414CategoryControlAreaPenDownHandler,
        MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cate414CategoryControlAreaPenUpHandler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        Cate414CategoryControlAreaPenMoveHandler,
        MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        Cate414CategoryControlAreaPenLongTapHandler,
        MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
        Cate414CategoryControlAreaPenRepeatHandler,
        MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
        Cate414CategoryControlAreaPenAbortHandler,
        MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* disable integrated title signal icons */
    wgui_status_icon_integrated_enable(MMI_FALSE);

    dm_setup_category_functions(dm_redraw_category_screen, GetCategory414History, GetCategory414HistorySize);
    dm_register_category_controlled_callback(NULL);
    dm_data.s32CatId = MMI_CATEGORY414_ID;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

