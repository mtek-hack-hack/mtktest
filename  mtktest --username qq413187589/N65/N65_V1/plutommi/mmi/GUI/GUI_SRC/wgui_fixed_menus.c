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
 *   wgui_fixed_menus.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  fixed menu related funtions
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
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "CustDataRes.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories.h"
#include "wgui_categories_defs.h"
#include "gui_custom_menus.h"
#include "gdi_include.h"
#include "MainMenuType.h"
#include "DebugInitDef.h"

#ifdef __MMI_UI_TECHNO_MAINMENU__
#include "MainMenuDef.h"
#endif 

#if defined(__MMI_UI_DALMATIAN_MAINMENU__)

#include "MainMenuDef.h"

#define NUMBER_OF_FRAMES 7      /* Number of transitions in Ball Animation in Main Menu. */

/* size of buffer allocated to ball. */
#define BALL_BUFFER ((BALL_WIDTH) * (BALL_HEIGHT) * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL / 8)
#endif /* defined(__MMI_UI_DALMATIAN_MAINMENU__) */ 

#include "GlobalDefs.h"
#include "wgui_draw_manager.h"

#include "ProfilingEngine.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
BOOL wgui_fixed_list_show_empty = MMI_TRUE;

extern BOOL r2lMMIFlag;

#ifdef __MMI_UI_TECHNO_MAINMENU__
enum
{
    TECHNO_MENU_ANIMATION_FRAME_ONE = 0,
    TECHNO_MENU_ANIMATION_FRAME_TWO = 0,
    TECHNO_MENU_ANIMATION_FRAME_THREE = 0,
    TECHNO_MENU_ANIMATION_FRAME_FOUR,
    TECHNO_MENU_ANIMATION_FRAME_FIVE
};

PU8 Techno_bgimage[BACKGROUND_FRAMES];

MMTechno_animo_menu Techno_menu[MAX_MAIN_MENU_ITEMS];

S32 frame = 0;

S32 current_frame = 1;

U8 is_next_item = 0;
#endif /* __MMI_UI_TECHNO_MAINMENU__ */ 

void (*_MMI_hide_fixed_list_menu) (void) = UI_dummy_function;

fixed_list_menu MMI_fixed_list_menu;

extern void draw_bg(void);
extern void draw_bg_animation(void);

extern void wgui_display_fixed_text_list_pop_up_description(void);

#ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
extern PU8 MMI_mm_animation;
#endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  dummy_highlight_handler
 * DESCRIPTION
 *  Dummy menu item highlight handler.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(item_index);
}


#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
S32 wgui_fixed_list_menu_frame_counter = 0;
#endif 

#if defined(__MMI_UI_DALMATIAN_MAINMENU__)
#ifdef __MMI_MAINLCD_176X220__
S32 ball1pos[NUMBER_OF_FRAMES][2] = { {116, 41},
{97, 51},
{81, 71},
{80, 86},
{81, 71},
{97, 51},
{116, 41}
};

S32 ball2pos[NUMBER_OF_FRAMES][2] = { {-2, 134},
{7, 111},
{38, 93},
{35, 86},
{38, 93},
{7, 134},
{-2, 134}
};

#elif defined(__MMI_MAINLCD_128X160__)
S32 ball1pos[NUMBER_OF_FRAMES][2] = { {85, 12},
{68, 30},
{50, 40},
{40, 50},
{50, 40},
{68, 30},
{85, 12}
};

S32 ball2pos[NUMBER_OF_FRAMES][2] = { {-8, 95},
{1, 80},
{10, 60},
{20, 50},
{10, 60},
{1, 80},
{-8, 95}
};
#endif 

MM_balls ball[NUMBER_OF_BALLS];

U8 ballimgdata[NUMBER_OF_BALLS][BALL_BUFFER];

U8 is_next_item = 0;


/*****************************************************************************
 * FUNCTION
 *  initialize_balls
 * DESCRIPTION
 *  Initialize the balls position and buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initialize_balls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ball[0].position = &ball1pos[0][0];
    ball[1].position = &ball2pos[0][0];

    memset(&ball[0].image, 0, sizeof(bitmap));
    memset(&ball[1].image, 0, sizeof(bitmap));
    memset(&ballimgdata[0], 0, BALL_BUFFER);
    memset(&ballimgdata[1], 0, BALL_BUFFER);

    ball[0].image.data = ballimgdata[0];
    ball[1].image.data = ballimgdata[1];
}

#endif /* defined(__MMI_UI_DALMATIAN_MAINMENU__) */


/*****************************************************************************
 * FUNCTION
 *  create_fixed_list
 * DESCRIPTION
 *  Creates the fixed list menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_list_menu(
        &MMI_fixed_list_menu,
        MMI_content_x,
        MMI_content_y,
        MMI_content_width,
        MMI_content_height);
#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    wgui_fixed_list_menu_frame_counter = 0;
#endif 

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif 
    normal_fixed_list();
}


/*****************************************************************************
 * FUNCTION
 *  plain_fixed_list
 * DESCRIPTION
 *  Set the list menu to plain display mode. (without background and scroll bar)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void plain_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags |= (UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_DISABLE_SCROLLBAR);
}


/*****************************************************************************
 * FUNCTION
 *  normal_fixed_list
 * DESCRIPTION
 *  Set the list menu to normal display mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void normal_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags &=
        ~(UI_LIST_MENU_ALIGN_TO_TOP | UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_DISABLE_SCROLLBAR |
          UI_LIST_MENU_ENABLE_TRANSITION | UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA |
          UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER | UI_LIST_MENU_DISABLE_PEN | UI_LIST_MENU_DISABLE_MENUITEM_GAP);

    /* force align to top as default */
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    _MMI_hide_fixed_list_menu = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  register_hide_fixed_list
 * DESCRIPTION
 *  Register the hide callback of the fixed list menu.
 * PARAMETERS
 *  f       [IN]        hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void register_hide_fixed_list(void (*f)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _MMI_hide_fixed_list_menu = f;
}


/*****************************************************************************
 * FUNCTION
 *  move_fixed_list
 * DESCRIPTION
 *  Move the fixed list menu.
 * PARAMETERS
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_fixed_list(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PLUTO_LISTBOX__)
    gui_move_fixed_list_menu(&MMI_fixed_list_menu, x + 1, y + 1);
#else /* defined(__MMI_PLUTO_LISTBOX__) */ 
    gui_move_fixed_list_menu(&MMI_fixed_list_menu, x, y);
#endif /* defined(__MMI_PLUTO_LISTBOX__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_highlight_handler
 * DESCRIPTION
 *  Register the highlight handler for the fixed list.
 * PARAMETERS
 *  f       [IN]        highlight handler of the fixed list
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_highlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_highlighted = f;
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_unhighlight_handler
 * DESCRIPTION
 *  Register the unhighlight handler for the fixed list.
 * PARAMETERS
 *  f       [IN]        unhighlight handler of the fixed list
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_unhighlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_unhighlighted = f;
}

#ifdef __MMI_UI_LIST_TRANSITION__

#define MMI_UI_LIST_TRANSITION_COUNT   10

wgui_transition_styles MMI_list_transition_style = WGUI_TRANSITION_NONE;
S32 MMI_check_list_for_transition = 1;


/*****************************************************************************
 * FUNCTION
 *  set_list_transition
 * DESCRIPTION
 *  Set the list transition style.
 * PARAMETERS
 *  style       [IN]        list transition style
 * RETURNS
 *  void
 *****************************************************************************/
void set_list_transition(wgui_transition_styles style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_transition_style = style;
}


/*****************************************************************************
 * FUNCTION
 *  get_list_transition
 * DESCRIPTION
 *  Return the list transition style.
 * PARAMETERS
 *  void
 * RETURNS
 *  List transition style
 *****************************************************************************/
wgui_transition_styles get_list_transition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_list_transition_style;
}


/*****************************************************************************
 * FUNCTION
 *  reset_list_transition
 * DESCRIPTION
 *  Reset the list transition style to none.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_list_transition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_transition_style = WGUI_TRANSITION_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  draw_transition_list
 * DESCRIPTION
 *  Draw the transition list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_transition_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_list_transition_style)
    {
        case WGUI_TRANSITION_D2T:
        {
            S32 prev_y = MMI_fixed_list_menu.y;
            S32 prev_height = MMI_fixed_list_menu.height;
            S32 i, transition_count;
            S32 transition_resolution;

            i = transition_count = MMI_UI_LIST_TRANSITION_COUNT;
            transition_resolution = MMI_fixed_list_menu.height / transition_count;
            MMI_fixed_list_menu.y = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
            MMI_fixed_list_menu.height = 0;

            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_ENABLE_TRANSITION;

            while (i - 1)
            {
                MMI_fixed_list_menu.y -= transition_resolution;
                MMI_fixed_list_menu.height += transition_resolution;
                move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
                resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
                MMI_fixed_list_menu.top = 0;
                show_fixed_list();
                i--;
            }

            MMI_fixed_list_menu.height = prev_height;
            MMI_fixed_list_menu.y = prev_y;

            move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
            show_fixed_list();

            break;
        }
            
        case WGUI_TRANSITION_T2D:
        {
            S32 prev_y = MMI_fixed_list_menu.y;
            S32 prev_height = MMI_fixed_list_menu.height;
            S32 i, transition_count;
            S32 transition_resolution;

            i = transition_count = MMI_UI_LIST_TRANSITION_COUNT;
            transition_resolution = MMI_fixed_list_menu.height / transition_count;
            MMI_fixed_list_menu.y -= (MMI_fixed_list_menu.height - 1);
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_ENABLE_TRANSITION;

            while (i - 1)
            {
                MMI_fixed_list_menu.y += transition_resolution;
                move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
                resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
                MMI_fixed_list_menu.top = 0;
                show_fixed_list();
                gui_BLT_double_buffer(
                    MMI_fixed_list_menu.x,
                    prev_y,
                    MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                    prev_y + prev_height - 1);
                i--;
            }

            MMI_fixed_list_menu.height = prev_height;
            MMI_fixed_list_menu.y = prev_y;

            move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
            show_fixed_list();
            gui_BLT_double_buffer(
                MMI_fixed_list_menu.x,
                prev_y,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                prev_y + prev_height - 1);
            leave_full_screen();

            break;
        }       
    }
}

#if (LIST_TRANSITION_STYLE_NON_BLOCKING)
static S32 g_in_list_transition = 0;
static S32 g_prev_list_y;
static S32 g_prev_list_height;


/*****************************************************************************
 * FUNCTION
 *  wgui_list_tranisition_abort_cleanup_function
 * DESCRIPTION
 *  Cleanup function for the list transition.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_tranisition_abort_cleanup_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_stop_list_transition_non_blocking();
}


/*****************************************************************************
 * FUNCTION
 *  draw_transition_list_non_blocking
 * DESCRIPTION
 *  Draw nonblocking list transition with timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void draw_transition_list_non_blocking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 temp_count, transition_count;
    static S32 transition_resolution;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_list_transition_style)
    {
        case WGUI_TRANSITION_D2T:
            if (is_in_nonblocking_list_transition() == 0)
            {
                g_in_list_transition = 1;
                save_copy_original_list_data();

                temp_count = transition_count = MMI_UI_LIST_TRANSITION_COUNT;
                transition_resolution = MMI_fixed_list_menu.height / transition_count;
                MMI_fixed_list_menu.y = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
                MMI_fixed_list_menu.height = 0;
                MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_ENABLE_TRANSITION;
                gui_add_cleanup_hook(wgui_list_tranisition_abort_cleanup_function);
            }
            MMI_fixed_list_menu.y -= transition_resolution;
            MMI_fixed_list_menu.height += transition_resolution;
            move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
            MMI_fixed_list_menu.top = 0;
            show_fixed_list();
            gui_BLT_double_buffer(
                MMI_fixed_list_menu.x,
                g_prev_list_y,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                g_prev_list_y + g_prev_list_height - 1);
            temp_count--;
            if (temp_count > 1)
            {
                gui_start_timer(LIST_TRANSITION_NON_BLOCKING_TIMER, draw_transition_list_non_blocking);
            }
            else
            {
                restore_saved_original_list_data();
                wgui_stop_list_transition_non_blocking();
                g_in_list_transition = 0;
                move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
                resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
                show_fixed_list();
            }
            break;

        case WGUI_TRANSITION_T2D:
            if (is_in_nonblocking_list_transition() == 0)
            {
                g_in_list_transition = 1;
                save_copy_original_list_data();

                temp_count = transition_count = MMI_UI_LIST_TRANSITION_COUNT;
                transition_resolution = MMI_fixed_list_menu.height / transition_count;
                MMI_fixed_list_menu.y -= (MMI_fixed_list_menu.height - 1);
                MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_BACKGROUND | UI_LIST_MENU_ENABLE_TRANSITION;
                gui_add_cleanup_hook(wgui_list_tranisition_abort_cleanup_function);
            }
            MMI_fixed_list_menu.y += transition_resolution;
            move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
            resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
            MMI_fixed_list_menu.top = 0;
            gui_lock_double_buffer();
            gui_push_clip();
            gui_set_clip(
                MMI_fixed_list_menu.x,
                g_prev_list_y,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                g_prev_list_y + g_prev_list_height - 1);
            show_fixed_list();
            gui_pop_clip();
            draw_title();
            show_status_icons();
            gui_unlock_double_buffer();
            gui_BLT_double_buffer(
                MMI_fixed_list_menu.x,
                0,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                g_prev_list_y + g_prev_list_height - 1);
            temp_count--;
            if (temp_count > 1)
            {
                gui_start_timer(LIST_TRANSITION_NON_BLOCKING_TIMER, draw_transition_list_non_blocking);
            }
            else
            {
                restore_saved_original_list_data();
                move_fixed_list(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y);
                resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height);
                wgui_stop_list_transition_non_blocking();
                show_fixed_list();
                gui_BLT_double_buffer(
                    MMI_fixed_list_menu.x,
                    g_prev_list_y,
                    MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                    g_prev_list_y + g_prev_list_height - 1);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_stop_list_transition_non_blocking
 * DESCRIPTION
 *  Stop the timer for list transition and reset variables.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_stop_list_transition_non_blocking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_in_nonblocking_list_transition())
    {
        MMI_fixed_list_menu.height = g_prev_list_height;
        MMI_fixed_list_menu.y = g_prev_list_y;
        g_in_list_transition = 0;
    }
    reset_list_transition();
    gui_cancel_timer(draw_transition_list_non_blocking);
}


/*****************************************************************************
 * FUNCTION
 *  is_in_nonblocking_list_transition
 * DESCRIPTION
 *  Return the non blocking list transition flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  List transition flag
 *****************************************************************************/
S32 is_in_nonblocking_list_transition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_in_list_transition;
}


/*****************************************************************************
 * FUNCTION
 *  get_original_prev_list_y_value
 * DESCRIPTION
 *  Return the original value of list start y position.
 * PARAMETERS
 *  void
 * RETURNS
 *  Start y value
 *****************************************************************************/
S32 get_original_prev_list_y_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_prev_list_y;
}


/*****************************************************************************
 * FUNCTION
 *  save_copy_original_list_data
 * DESCRIPTION
 *  Save the original value of list start y position and list height.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void save_copy_original_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_prev_list_y = MMI_fixed_list_menu.y;
    g_prev_list_height = MMI_fixed_list_menu.height;
}


/*****************************************************************************
 * FUNCTION
 *  restore_saved_original_list_data
 * DESCRIPTION
 *  Restore the original value of list start y position and list height.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void restore_saved_original_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.height = g_prev_list_height;
    MMI_fixed_list_menu.y = g_prev_list_y;
}

#endif /* (LIST_TRANSITION_STYLE_NON_BLOCKING) */ 

#endif /* __MMI_UI_LIST_TRANSITION__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_list_menu_show_empty_label_if_needed
 * DESCRIPTION
 *  Display "empty" in list menu if it is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_list_menu_show_empty_label_if_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items > 0 || !wgui_fixed_list_show_empty)
    {
        return;
    }

    gdi_layer_set_clip(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);

    gui_set_font(current_MMI_theme->list_menu_font);
    gui_set_text_color(*(current_MMI_theme->list_normal_text_color));

    str_ptr = GetString(STR_GLOBAL_EMPTY);

    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    offset_x = MMI_fixed_list_menu.x + ((MMI_fixed_list_menu.width - str_width) >> 1);
    offset_y = MMI_fixed_list_menu.y + ((MMI_fixed_list_menu.height - str_height) >> 1);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(offset_x + str_width, offset_y);
    }
    else
    {
        gui_move_text_cursor(offset_x, offset_y);
    }

    gui_print_text((UI_string_type) str_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  show_fixed_list
 * DESCRIPTION
 *  Show the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
    gui_add_cleanup_hook(gui_stop_list_highlight_effect);
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

#ifdef __MMI_UI_LIST_TRANSITION__
    if (MMI_check_list_for_transition && MMI_list_transition_style)
    {
    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        gui_reset_current_list_effect();
    #endif 

        MMI_check_list_for_transition = 0;
    #if(LIST_TRANSITION_STYLE_NON_BLOCKING)
        if (is_in_nonblocking_list_transition() == 0)
        {
            draw_transition_list_non_blocking();
        }
    #else /* (LIST_TRANSITION_STYLE_NON_BLOCKING) */ 
        draw_transition_list();
    #endif /* (LIST_TRANSITION_STYLE_NON_BLOCKING) */ 

        MMI_check_list_for_transition = 1;

    #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    #if(LIST_TRANSITION_STYLE_NON_BLOCKING)
        if (is_in_nonblocking_list_transition() == 0)
    #endif 
            gui_restore_current_list_effect();
    #else /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 
        return;
    #endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

    }
#endif /* __MMI_UI_LIST_TRANSITION__ */ 

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
    {
        _MMI_hide_fixed_list_menu();
    }
    
    gui_show_fixed_list_menu(&MMI_fixed_list_menu);
    wgui_display_fixed_text_list_pop_up_description();

#ifdef __MMI_UI_LIST_TRANSITION__
#if(LIST_TRANSITION_STYLE_NON_BLOCKING)
    if (get_list_transition() == WGUI_TRANSITION_T2D && !MMI_check_list_for_transition ||
        is_in_nonblocking_list_transition() == 1)
    {
        return;
    }
#else /* (LIST_TRANSITION_STYLE_NON_BLOCKING) */ 
    if (get_list_transition() == WGUI_TRANSITION_T2D && !MMI_check_list_for_transition)
    {
        return;
    }
#endif /* (LIST_TRANSITION_STYLE_NON_BLOCKING) */ 
#endif /* __MMI_UI_LIST_TRANSITION__ */ 

    /* if is emtpty folder, show a empty string */
    wgui_list_menu_show_empty_label_if_needed();

    gdi_layer_blt_previous(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
        MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))


/*****************************************************************************
 * FUNCTION
 *  wgui_fixed_list_menu_end_frame
 * DESCRIPTION
 *  Show the fixed list for the last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fixed_list_menu_end_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_fixed_list_menu_frame_counter >= 1)
    {
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_hide_animations();
        gui_lock_double_buffer();
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        wgui_display_fixed_text_list_pop_up_description();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
        wgui_fixed_list_menu_frame_counter = 0;
        gui_start_timer(UI_FRAME_SKIP_TIMEOUT, wgui_fixed_list_menu_end_frame);
    }
}

#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  redraw_fixed_list
 * DESCRIPTION
 *  Redraw the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ANI_BG_LIST_MENU)
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        gdi_layer_lock_frame_buffer();
        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        wgui_display_fixed_text_list_pop_up_description();
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);
    }
    else
    {
    #if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
        if (wgui_fixed_list_menu_frame_counter > 0)
        {
            wgui_fixed_list_menu_frame_counter++;
            gui_show_fixed_list_menu_no_draw(&MMI_fixed_list_menu);
        }
        else
        {
            wgui_fixed_list_menu_frame_counter = 1;
            gui_show_fixed_list_menu_no_draw(&MMI_fixed_list_menu);
            gui_start_timer(UI_FRAME_START_TIMEOUT, wgui_fixed_list_menu_end_frame);
        }
    #else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
        gdi_layer_lock_frame_buffer();

        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_BACKGROUND)
        {
            _MMI_hide_fixed_list_menu();
        }
        gui_show_fixed_list_menu(&MMI_fixed_list_menu);
        wgui_display_fixed_text_list_pop_up_description();

        gdi_layer_unlock_frame_buffer();

    #ifdef __MMI_UI_LIST_TRANSITION__
    #if(LIST_TRANSITION_STYLE_NON_BLOCKING)
        if (get_list_transition() == WGUI_TRANSITION_T2D && is_in_nonblocking_list_transition() == 1)
        {
            gdi_layer_blt_previous(
                MMI_fixed_list_menu.x,
                g_prev_list_y,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                g_prev_list_y + g_prev_list_height - 1);
        }
        else
    #endif /* (LIST_TRANSITION_STYLE_NON_BLOCKING) */ 
    #endif /* __MMI_UI_LIST_TRANSITION__ */ 
            gdi_layer_blt_previous(
                MMI_fixed_list_menu.x,
                MMI_fixed_list_menu.y,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
                MMI_fixed_list_menu.y + MMI_fixed_list_menu.height);

    #endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  clear_fixed_list_highlight_handler
 * DESCRIPTION
 *  Clear the highlight handler of the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_fixed_list_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    /* do nothing if there is only 1 menu item */
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);

    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_list_effect_slide_start();

    /* Max: to redraw list if there is only 1 item. */
    if (!((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0)))   /* return; */
    {
    #if defined(__MMI_UI_DALMATIAN_MAINMENU__)
        if (MMI_current_menu_type == PAGE_MENU)
        {
            is_next_item = 0;
            show_animated_balls();
        }
        else
    #endif /* defined(__MMI_UI_DALMATIAN_MAINMENU__) */ 
        {
            gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
        }
    }

#ifdef __MMI_UI_TECHNO_MAINMENU__
    if (MMI_current_menu_type == PAGE_MENU)
    {
        is_next_item = 0;
        associate_techno_item_positions(0);
        show_techno_menu_animation();
    }
#endif /* __MMI_UI_TECHNO_MAINMENU__ */ 

    if (MMI_current_menu_type == PAGE_MENU)
    {
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);    
        return;
    }

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
#endif

    redraw_fixed_list();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
#endif
    
    gui_list_effect_slide_end();
    
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    /* do nothing if there is only 1 menu item */
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_list_effect_slide_start();

    /* Max: to redraw list if there is only 1 item. */
    if (!((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0)))   /* return; */
    {
    #if defined(__MMI_UI_DALMATIAN_MAINMENU__)
        if (MMI_current_menu_type == PAGE_MENU)
        {
            is_next_item = 1;
            show_animated_balls();
        }
        else
    #endif /* defined(__MMI_UI_DALMATIAN_MAINMENU__) */ 
        {
            gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
        }
    }

#ifdef __MMI_UI_TECHNO_MAINMENU__
    if (MMI_current_menu_type == PAGE_MENU)
    {
        is_next_item = 1;
        associate_techno_item_positions(1);
        show_techno_menu_animation();
    }
#endif /* __MMI_UI_TECHNO_MAINMENU__ */ 

    if (MMI_current_menu_type == PAGE_MENU)
    {
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);
        return;
    }

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);
#endif

    redraw_fixed_list();
    
#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_LIST_HIGHLIGHT);    
#endif

    gui_list_effect_slide_end();

    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_home
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
    gui_fixed_list_menu_goto_first_item(&MMI_fixed_list_menu);
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_end
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 
    gui_fixed_list_menu_goto_last_item(&MMI_fixed_list_menu);
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_previous_page
 * DESCRIPTION
 *  Go to the item in the previous page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_fixed_list_menu_goto_previous_page(&MMI_fixed_list_menu);
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }
    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_next_page
 * DESCRIPTION
 *  Go to the item in the next page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_fixed_list_menu_goto_next_page(&MMI_fixed_list_menu);
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

#if defined(__MMI_UI_DALMATIAN_MAINMENU__)
    S32 i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);        
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

#if defined(__MMI_UI_DALMATIAN_MAINMENU__)
    if (MMI_current_menu_type == PAGE_MENU)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            MMI_content_x,
            MMI_content_y,
            UI_device_width - 1,
            UI_device_height - MMI_button_bar_height - 1);
        for (i = 0; i < NUMBER_OF_BALLS; i++)
        {
            gui_show_image(*(ball[i].position + 0), *(ball[i].position + 1), get_image(MAIN_MENU_DALMATIAN_BALL));
        }
        gdi_layer_pop_clip();
    }
#endif /* defined(__MMI_UI_DALMATIAN_MAINMENU__) */ 

    if (MMI_current_menu_type == PAGE_MENU)
    {
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(act_lcd);    
        return;
    }

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item_push_first
 * DESCRIPTION
 *  Go to the specified item and make it the first displayed item if possible.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_item_push_first(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
    gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM;
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_CENTER_HIGHLIGHTED)
    {
        draw_bg();
        draw_bg_animation();
    }

    redraw_fixed_list();
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(act_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the fixed list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index < 0)
    {
        item_index = 0;
    }
    if (item_index > (MMI_fixed_list_menu.n_items - 1))
    {
        item_index = MMI_fixed_list_menu.n_items - 1;
    }
    MMI_fixed_list_menu.highlighted_item = -1;
    gui_fixed_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_shortcut_handler
 * DESCRIPTION
 *  Register the shortcut handler for the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(fixed_list_goto_item);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_measure
 * DESCRIPTION
 *  Get the dimension of the fixed list.
 * PARAMETERS
 *  width       [OUT]       width
 *  height      [OUT]       height
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_measure(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_fixed_list_menu.width;
    *height = MMI_fixed_list_menu.height;
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_list
 * DESCRIPTION
 *  Resize the fixed list.
 * PARAMETERS
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_list(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Auto resize the height based on height of menu-items and the specified height */
    /* FIXME. move the following code to gui_resize_fixed_list_menu */
    S32 w, h = 0, new_height = height;
    S32 ih, mh, rh, sh, th, count;
    gui_common_menuitem_base_struct *m = (gui_common_menuitem_base_struct*)MMI_fixed_list_menu.common_item_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     *  !!!CAUTION!!!
     *  resize_fixed_list() might be called with both NULL common menu item 
     *  and private menu items. For example, NO SIM MAIN MENU.
     */
    /* doing menu alignment only when the common menu item is not NULL */
    if (m)
    {
        if (MMI_fixed_list_menu.items != NULL)
        {
            MMI_fixed_list_menu.item_measure_function(
                                    MMI_fixed_list_menu.items[0],
                                    m,
                                    &w,
                                    &h);

            /* 
             * The two line menu item must be considered as a single line, or the menu 
             * center alignment below will go wrong when the number of single line 
             * menu items in the menu is odd.
             */
            if (m->ext_flags & UI_MENUITEM_EXT_CONTAIN_TWO_LINE_MENU_ITEM)
            {
                h >>= 1;
            }
        }
        else
        {
            MMI_fixed_list_menu.item_measure_function(NULL, m, &w, &h);
        }

        ih = h;

        /* If ih equals to 0, hopefully it will raise a divided-by-zero error. */
        count = height / ih;
        mh = count * ih;
        rh = height - mh;          

        if (MMI_fixed_list_menu.flags & UI_LIST_MENU_ALIGN_TO_TOP)
        {
            MMI_fixed_list_menu.spacing = 0;

            if (rh == 0)
            {   /* just fit, do not leaving 1 pixel spacing. */
                // TODO: FIXME!!! UNIFY MENU LOCATE LOGIC.
                MMI_fixed_list_menu.top = 0;
            }
            else
            {
                // TODO: remove the magic number, which is 1 pixel. NOTICE: the menu locate logic contains this pixel. */
                MMI_fixed_list_menu.top = 1;    
            }
        }
        else if (h > 0)
        {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
            /* Menu item spacing is not supported yet. */
            th = 0;
            sh = 0;

            MMI_fixed_list_menu.spacing = 0;
            MMI_fixed_list_menu.top = rh / 2;
        }
    }

    if (MMI_fixed_list_menu.item_resize_function != NULL)
    {
        MMI_fixed_list_menu.item_resize_function(w, 0); /* Change width of menuitem according to list menu at the same time. */
    }

    gui_resize_fixed_list_menu(&MMI_fixed_list_menu, width, new_height);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_list_keys
 * DESCRIPTION
 *  Register key handlers of the fixed list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
}


#ifdef __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__

/*****************************************************************************
 * FUNCTION
 *  register_horizontal_fixed_list_keys
 * DESCRIPTION
 *  Register key handlers of the horizontal fixed list, including 
 *  KEY_LEFT_ARROW and KEY_RIGHT_ARROW.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_horizontal_fixed_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_list_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_list_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#endif /* __MMI_UI_MM_HORIZONTAL_PAGE_STYLE__ */


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_list
 * DESCRIPTION
 *  Clear the key and highlight handlers for the fixed list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

#if((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
    gui_cancel_timer(wgui_fixed_list_menu_end_frame);
    wgui_fixed_list_menu_frame_counter = 0;
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
    normal_fixed_list();

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)      /* 072505 Calvin modified */
    gui_reset_transparent_source_layer();
#endif 

    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    MMI_fixed_list_menu.item_highlighted = dummy_highlight_handler;
    MMI_fixed_list_menu.highlighted_item = -1;
    wgui_text_menuitem_reset_scrolling();
    gui_fixed_icontext_list_menuitem_stop_scroll();

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_disable_looping
 * DESCRIPTION
 *  Disable looping.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_disable_looping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_LOOP;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_list_enable_looping
 * DESCRIPTION
 *  Enable looping.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_list_enable_looping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_LOOP;
}

/* Fixed matrix menu wrappers */

fixed_matrix_menu MMI_fixed_matrix_menu;


/*****************************************************************************
 * FUNCTION
 *  dummy_fixed_matrix_resize_function
 * DESCRIPTION
 *  Dummy matrix resize handler
 * PARAMETERS
 *  item_width      [IN]       item width 
 *  item_height     [IN]       item height
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fixed_matrix_resize_function(S32 item_width, S32 item_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(item_width);
    UI_UNUSED_PARAMETER(item_height);
}

void (*resize_fixed_matrix_menuitems) (S32 item_width, S32 item_height) = dummy_fixed_matrix_resize_function;


/*****************************************************************************
 * FUNCTION
 *  create_fixed_matrix
 * DESCRIPTION
 *  Creates the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void create_fixed_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_create_fixed_matrix_menu(
        &MMI_fixed_matrix_menu,
        MMI_content_x,
        MMI_content_y,
        MMI_content_width,
        MMI_content_height - MMI_matrix_bar_height);
}


/*****************************************************************************
 * FUNCTION
 *  move_fixed_matrix
 * DESCRIPTION
 *  Move the fixed matrix menu.
 * PARAMETERS
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_fixed_matrix(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_fixed_matrix_menu(&MMI_fixed_matrix_menu, x, y);
}


/*****************************************************************************
 * FUNCTION
 *  show_fixed_matrix
 * DESCRIPTION
 *  Show the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_fixed_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    if (MMI_current_menu_type == MATRIX_MENU_EMS)
    {
        gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
    }
    else
    {
        gui_main_menu_matrix_slide_stop();
        
    #ifdef __MMI_MATRIX_MAIN_MENU_OPTIMIZE__
        if (MMI_fixed_matrix_menu.flags & UI_MATRIX_MENU_FOR_MAINMENU)
        {
            gui_measure_image(
                MMI_mm_animation,
                &(MMI_fixed_matrix_menu.highlighted_item_width),
                &(MMI_fixed_matrix_menu.highlighted_item_height));
            if (MMI_fixed_matrix_menu.last_highlighted_item != -1)
            {
                mtk_UI_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
            }
            else
            {
                gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
            }
        }
        else
        {
            MMI_fixed_matrix_menu.highlighted_item_width = MMI_fixed_matrix_menu.item_width;
            MMI_fixed_matrix_menu.highlighted_item_height = MMI_fixed_matrix_menu.item_height;
            gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
        }
    #else /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
        gui_show_fixed_matrix_menu(&MMI_fixed_matrix_menu);
    #endif /* __MMI_MATRIX_MAIN_MENU_OPTIMIZE__ */ 
    }
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_fixed_matrix_menu.x,
        MMI_fixed_matrix_menu.y,
        MMI_fixed_matrix_menu.x + MMI_fixed_matrix_menu.width - 1,
        MMI_fixed_matrix_menu.y + MMI_fixed_matrix_menu.height - 1);
}

/* For Draw Manager  */


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_matrix_col_rows
 * DESCRIPTION
 *  Reset the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_matrix_col_rows(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_fixed_matrix_col_rows(&MMI_fixed_matrix_menu);
}


/*****************************************************************************
 * FUNCTION
 *  configure_fixed_matrix
 * DESCRIPTION
 *  Set the number of columns and rows and the dimension of the menuitems.
 * PARAMETERS
 *  item_width      [IN]        item width
 *  item_height     [IN]        item height
 *  n_columns       [IN]        number of columns
 *  n_rows          [IN]        number of rows
 * RETURNS
 *  void
 *****************************************************************************/
void configure_fixed_matrix(S32 item_width, S32 item_height, S32 n_columns, S32 n_rows)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fixed_matrix_menu_setup(&MMI_fixed_matrix_menu, item_width, item_height, n_columns, n_rows);
    resize_fixed_matrix_menuitems(MMI_fixed_matrix_menu.item_width, MMI_fixed_matrix_menu.item_height);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_highlight_handler
 * DESCRIPTION
 *  Register the highlight handler of the fixed matrix menu.
 * PARAMETERS
 *  f               [IN]        matrix highlight handler function
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_highlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.item_highlighted = f;
}


/*****************************************************************************
 * FUNCTION
 *  clear_fixed_matrix_highlight_handler
 * DESCRIPTION
 *  Clear the matrix highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void clear_fixed_matrix_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.item_highlighted = dummy_highlight_handler;
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif

    gui_main_menu_matrix_slide_start();
    
    gui_fixed_matrix_menu_goto_previous_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();

    gui_main_menu_matrix_slide_end();    

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif

    gui_main_menu_matrix_slide_start();

    gui_fixed_matrix_menu_goto_next_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();

    gui_main_menu_matrix_slide_end();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif        
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_column
 * DESCRIPTION
 *  Go to the previous column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_column(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_previous_column(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_column
 * DESCRIPTION
 *  Go to the next column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_column(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_next_column(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_row
 * DESCRIPTION
 *  Go to the previous row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
    
    gui_main_menu_matrix_slide_start();
    
    gui_fixed_matrix_menu_goto_previous_row(&MMI_fixed_matrix_menu);
    show_fixed_matrix();

    gui_main_menu_matrix_slide_end();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_row
 * DESCRIPTION
 *  Go to the the next row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
    
    gui_main_menu_matrix_slide_start();
    
    gui_fixed_matrix_menu_goto_next_row(&MMI_fixed_matrix_menu);
    show_fixed_matrix();

    gui_main_menu_matrix_slide_end();

#ifdef __MMI_INTERACTIVE_PROFILNG__
    mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_home
 * DESCRIPTION
 *  Go to the first item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_first_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_end
 * DESCRIPTION
 *  Go to the last item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_last_item(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_previous_page
 * DESCRIPTION
 *  Go to the previous page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_previous_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_previous_page(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_next_page
 * DESCRIPTION
 *  Go to the next page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_next_page(&MMI_fixed_matrix_menu);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Use last_highlighted_item = -2 to indicate this goto item function fails.
     * See main_menu_shortcut_executer().
     */
    // TODO: SHOULD USE A BETTER WAY TO RESPOND.
    if ((item_index >= MMI_fixed_matrix_menu.n_items) || (item_index < 0))
    {
        MMI_fixed_matrix_menu.last_highlighted_item = -2;

        return;
    }
    
    MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
    gui_fixed_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
    show_fixed_matrix();
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the fixed matrix.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.highlighted_item = -1;
    gui_fixed_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_shortcut_handler
 * DESCRIPTION
 *  Register the menu shortcut handler for the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(fixed_matrix_goto_item);
}


/*****************************************************************************
 * FUNCTION
 *  fixed_matrix_measure
 * DESCRIPTION
 *  Gets the dimension of the fixed matrix menu.
 * PARAMETERS
 *  width       [OUT]       width
 *  height      [OUT]       height
 * RETURNS
 *  void
 *****************************************************************************/
void fixed_matrix_measure(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = MMI_fixed_matrix_menu.width;
    *height = MMI_fixed_matrix_menu.height;
}


/*****************************************************************************
 * FUNCTION
 *  resize_fixed_matrix
 * DESCRIPTION
 *  Change the size of the fixed matrix menu.
 * PARAMETERS
 *  width       [IN]        width
 *  height      [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_fixed_matrix(S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_fixed_matrix_menu(&MMI_fixed_matrix_menu, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  register_fixed_matrix_keys
 * DESCRIPTION
 *  Register key handlers for the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_fixed_matrix_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(fixed_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_previous_column, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(fixed_matrix_goto_next_column, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_matrix
 * DESCRIPTION
 *  Clear key and highlight handlers for the fixed matrix menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
    
    clear_keyboard_key_handler();
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    MMI_fixed_matrix_menu.item_highlighted = dummy_highlight_handler;
}

#if ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))

UI_string_type wgui_CM3D_items[WGUI_CM3D_MAX_ITEMS];
PU8 wgui_CM3D_images[WGUI_CM3D_MAX_ITEMS * WGUI_CM3D_N_ITEM_IMAGES];
PU8 wgui_CM3D_common_images[WGUI_CM3D_N_COMMON_IMAGES];
S32 wgui_CM3D_n_items;
UI_3D_circular_menu wgui_CM3D_menu;

/* 081404 Calvin fine tuned */
CM3D_item_position wgui_CM3D_item_positions[] = 
{
#if !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__)     /* 041205 Calvin modieid */
    {120, 82},              /* 0  */
    {104, 82},
    {88, 82},
    {72, 82},               /* 1  */
    {58, 82},               /* {58,79}, */
    {44, 79},
    {28, 74},               /* 2  */
    {22, 68},
    {15, 64},               /* {14,66}, */
    {7, 51},    // {4,51},  /*      3       */
    {9, 42},                /* {4,42}, */
    {11, 31},               /* {14,33}, */
    {22, 26},   // {21,25}, /*      4       */
    {29, 23},               /* {30,24}, */
    {38, 18},               /* {40,20}, */
    {51, 16},               /* 5  */
    {60, 16},
    {67, 15},
    {78, 15},               /* 6  */
    {85, 15},
    {92, 14},
    {103, 16},              /* 7  */
    {106, 16},
    {112, 16},
    {120, 16},              /* 8  */
    {0, 0},
    {0, 0},
#else /* !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__) */ 
    {169, 128},             /* 0  */
    {143, 126},
    {119, 124},
    {95, 122},              /* 1  */
    {74, 119},              /* {58,79}, */
    {54, 117},
    {34, 115},              /* 2  */
    {23, 102},
    {12, 89},               /* {14,66}, */
    {2, 76},    // {4,51},  /*      3       */
    {9, 62},                /* {4,42}, */
    {16, 54},               /* {14,33}, */
    {36, 52},   // {21,25}, /*      4       */
    {47, 47},               /* {30,24}, */
    {58, 41},               /* {40,20}, */
    {70, 35},               /* 5  */
    {81, 32},
    {93, 29},
    {105, 26},              /* 6  */
    {115, 25},
    {125, 24},
    {136, 23},              /* 7  */
    {147, 22},
    {158, 21},
    {169, 20},              /* 8  */
    {0, 0},
    {0, 0},
#endif /* !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__) */ 
};

CM3D_item_position wgui_CM3DR_item_positions[] =    /* Positions for 3D Rotate Menu */
{
#if ( defined  (__MMI_MAINLCD_128X160__))

#ifdef ROTATE_HORI      /* circular horizontal */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {72, 40},   /*  1  */
    {60, 27},
    {48, 15},
    {36, 9},    /* 2  */
    {24, 15},   /* {120,120}, */
    {12, 27},   /* {120,120}, */
    {0, 40},    /*   3  */
    {128, 160}, /* {30,11}, */
    {128, 160}, /* {15,25}, */
#else /* ROTATE_HORI */ 
#ifdef ROTATE_VERT      /* ////vertical */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {36, 84},   /*  1  */
    {36, 70},
    {36, 56},
    {36, 42},   /* 2  */
    {36, 28},   /* {120,120}, */
    {36, 14},   /* {120,120}, */
    {36, 0},    /*   3  */
    {128, 160}, /* {40,20}, */
    {128, 160}, /* {40,10}, */
#else /* ROTATE_VERT */ 
#ifdef ROTATE_VERT_CIR  /* /default is vertical circular */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {4, 84},    /*   1  */
    {19, 70},
    {30, 56},
    {38, 42},   /* 2  */
    {30, 28},   /* {120,120}, */
    {19, 14},   /* {120,120}, */
    {4, 0},     /* 3  */
    {128, 160}, /* {18,35}, */
    {128, 160}, /* {10,27}, */
#else /* ROTATE_VERT_CIR */ 
#ifdef ROTATE_VERT_LINE /* ////vertical */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {0, 84},    /*   1  */
    {0, 70},
    {0, 56},
    {0, 42},    /* 2  */
    {0, 28},    /* {120,120}, */
    {0, 14},    /* {120,120}, */
    {0, 0},     /* 3  */
    {128, 160}, /* {8,20}, */
    {128, 160}, /* {8,10}, */
#else /* ROTATE_VERT_LINE */ 
#ifdef ROTATE_VERT_LINE_RIGHT   /* ////vertical */
    {128, 160}, /* 0  */
    {128, 160},
    {128, 160},
    {72, 84},   /*  1  */
    {72, 70},
    {72, 56},
    {72, 42},   /* 2  */
    {72, 28},   /* {120,120}, */
    {72, 14},   /* {120,120}, */
    {72, 0},    /*   3  */
    {128, 160}, /* {70,20}, */
    {128, 160}  /* {70,10} */
    // #endif
#endif /* ROTATE_VERT_LINE_RIGHT */ 
#endif /* ROTATE_VERT_LINE */ 
#endif /* ROTATE_VERT_CIR */ 
#endif /* ROTATE_VERT */ 
#endif /* ROTATE_HORI */ 
#elif defined( __MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)    /* 041205 Calvin modieid */

#ifdef ROTATE_HORI      /* circular horizontal */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {108, 66},  /* 1  */
    {90, 50},
    {72, 37},
    {54, 9},    /* 2  */
    {36, 37},   /* {177,220}, */
    {18, 50},   /* {177,220}, */
    {0, 66},    /*   3  */
    {177, 220}, /* {42,42}, */
    {177, 220}, /* {27,56}, */
#else /* ROTATE_HORI */ 
#ifdef ROTATE_VERT      /* ////vertical */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {40, 138},  /* 1  */
    {40, 115},
    {40, 92},
    {40, 69},   /* 2  */
    {40, 46},   /* {177,220}, */
    {40, 23},   /* {177,220}, */
    {40, 0},    /*   3  */
    {177, 220}, /* {80,30}, */
    {177, 220}, /* {80,20}, */
#else /* ROTATE_VERT */ 
#ifdef ROTATE_VERT_CIR  /* /default is vertical circular */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {33, 138},  /* 1  */// {4,95},/*  1       */
    {48, 115},  /* {14,80}, */
    {60, 93},
    {66, 69},   /* 2  */
    {60, 46},   /* {177,220}, */
    {48, 23},   /* {177,220}, */
    {33, 0},    /* 3  */
    {177, 220}, /* {50,60}, */
    {177, 220}, /* {40,50}, */
#else /* ROTATE_VERT_CIR */ 
#ifdef ROTATE_VERT_LINE /* ////vertical */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {0, 138},   /* 1  */
    {0, 115},
    {0, 92},
    {0, 69},    /* 2  */
    {0, 46},    /* {177,220}, */
    {0, 23},    /* {177,220}, */
    {0, 0},     /* 3  */
    {177, 220}, /* {29,33}, */
    {177, 220}, /* {29,20}, */
#else /* ROTATE_VERT_LINE */ 
#ifdef ROTATE_VERT_LINE_RIGHT   /* ////vertical */
    {177, 220}, /* 0  */
    {177, 220},
    {177, 220},
    {108, 138}, /* 1  */
    {108, 115},
    {108, 92},
    {108, 69},  /* 2  */
    {108, 46},  /* {177,220}, */
    {108, 23},  /* {177,220}, */
    {108, 0},   /* 3  */
    {177, 220}, /* {120,30}, */
    {177, 220}  /* {120,20} */
#endif /* ROTATE_VERT_LINE_RIGHT */ 
#endif /* ROTATE_VERT_LINE */ 
#endif /* ROTATE_VERT_CIR */ 
#endif /* ROTATE_VERT */ 
#endif /* ROTATE_HORI */ 
#else /* __MMI_MAINLCD_128X128__ */
#ifdef ROTATE_HORI      /* circular horizontal */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {79, 36},   /*  1  */
    {66, 23},
    {53, 14},
    {40, 4},    /* 2  */
    {27, 14},   /* {120,120}, */
    {14, 23},   /* {120,120}, */
    {1, 36},    /*   3  */
    {128, 128}, /* {30,11}, */
    {128, 128}, /* {15,25}, */
#else /* ROTATE_HORI */ 
#ifdef ROTATE_VERT      /* ////vertical */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {40, 72},   /*  1  */
    {40, 60},
    {40, 48},
    {40, 36},   /* 2  */
    {40, 24},   /* {120,120}, */
    {40, 12},   /* {120,120}, */
    {40, 0},    /*   3  */
    {128, 128}, /* {40,20}, */
    {128, 128}, /* {40,10}, */
#else /* ROTATE_VERT */ 
#ifdef ROTATE_VERT_CIR  /* /default is vertical circular */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {4, 72},    /*   1  */
    {17, 60},
    {28, 48},
    {38, 36},   /* 2  */
    {28, 24},   /* {120,120}, */
    {17, 12},   /* {120,120}, */
    {4, 0},     /* 3  */
    {128, 128}, /* {18,35}, */
    {128, 128}, /* {10,27}, */
#else /* ROTATE_VERT_CIR */ 
#ifdef ROTATE_VERT_LINE /* ////vertical */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {0, 72},    /*   1  */
    {0, 60},
    {0, 48},
    {0, 36},    /* 2  */
    {0, 24},    /* {120,120}, */
    {0, 12},    /* {120,120}, */
    {0, 0},     /* 3  */
    {128, 128}, /* {8,20}, */
    {128, 128}, /* {8,10}, */
#else /* ROTATE_VERT_LINE */ 
#ifdef ROTATE_VERT_LINE_RIGHT   /* ////vertical */
    {128, 128}, /* 0  */
    {128, 128},
    {128, 128},
    {80, 72},   /*  1  */
    {80, 60},
    {80, 48},
    {80, 36},   /* 2  */
    {80, 24},   /* {120,120}, */
    {80, 12},   /* {120,120}, */
    {80, 0},    /*   3  */
    {128, 128}, /* {70,20}, */
    {128, 128}  /* {70,10} */
#endif /* ROTATE_VERT_LINE_RIGHT */ 
#endif /* ROTATE_VERT_LINE */ 
#endif /* ROTATE_VERT_CIR */ 
#endif /* ROTATE_VERT */ 
#endif /* ROTATE_HORI */ 

#endif /* MMI_UI_STYLES */
};

/* Temporary theme data. Will be removed later */

UI_3D_circular_menu_theme wgui_CM3D_theme = 
{
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 100},
    &MMI_default_font,
    0
};


/*****************************************************************************
 * FUNCTION
 *  set_circular_3d_menu_items
 * DESCRIPTION
 *  Set the items, common images and item images to be used
 *  by the circular 3D menu.
 * PARAMETERS
 *  n_items     [IN]        Number of items
 *  items       [IN]        Array of items (n_items number of elements)
 *  images      [IN]        Array of item images ((n_items * number of images per item) number of elements)
 * RETURNS
 *  void
 *****************************************************************************/
void set_circular_3d_menu_items(S32 n_items, MMI_ID_TYPE *items, MMI_ID_TYPE *images)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_common_images[0] = get_image(CM3D_COMMON_IMAGE0_IMAGE_ID);
    wgui_CM3D_common_images[1] = get_image(CM3D_COMMON_IMAGE1_IMAGE_ID);
    wgui_CM3D_common_images[2] = get_image(CM3D_COMMON_IMAGE2_IMAGE_ID);
    wgui_CM3D_common_images[3] = get_image(CM3D_COMMON_IMAGE3_IMAGE_ID);

    wgui_CM3D_n_items = n_items;
    for (i = 0; i < n_items; i++)
    {
        wgui_CM3D_items[i] = get_string(items[i]);
    }
    for (i = 0; i < n_items; i++)
    {
        wgui_CM3D_images[i] = get_image(images[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  create_circular_3d_menu
 * DESCRIPTION
 *  Create the circular 3D menu.
 * PARAMETERS
 *  n_items     [IN]        Number of items
 *  items       [IN]        Array of String IDs corresponding to items (n_items number of elements)
 *  images      [IN]        Array of Image IDs corresponding to item images ((n_items * number of images per item) number of elements)
 * RETURNS
 *  void
 *****************************************************************************/
void create_circular_3d_menu(S32 n_items, MMI_ID_TYPE *items, MMI_ID_TYPE *images)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_theme.bg_filler = current_MMI_theme->main_menu_background_filler;
    current_3D_circular_menu_theme = &wgui_CM3D_theme;
    set_circular_3d_menu_items(n_items, items, images);
    if (MMI_current_menu_type == CIRCULAR_3D_MENU)
    {
        gui_create_3D_circular_menu(
            &wgui_CM3D_menu,
            0,
            0,
            UI_device_width,
            UI_device_height - MMI_softkey_height,
            WGUI_CM3D_N_DISPLAYED_ITEMS + 2,
            wgui_CM3D_item_positions,
            WGUI_CM3D_N_ITEM_IMAGES,
            wgui_CM3D_images,
            wgui_CM3D_common_images);
    }
    else
    {
        gui_create_3D_circular_menu(
            &wgui_CM3D_menu,
            0,
            0,
            UI_device_width,
            UI_device_height - MMI_softkey_height,
            WGUI_CM3D_N_DISPLAYED_ITEMS + 2,
            wgui_CM3DR_item_positions,
            WGUI_CM3D_N_ITEM_IMAGES,
            wgui_CM3D_images,
            wgui_CM3D_common_images);
    }
    gui_set_3D_circular_menu_items(&wgui_CM3D_menu, n_items, wgui_CM3D_items);
}


/*****************************************************************************
 * FUNCTION
 *  show_circular_3d_menu
 * DESCRIPTION
 *  Show the circular 3D menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_circular_3d_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = wgui_CM3D_menu.x;
    S32 y1 = wgui_CM3D_menu.y;
    S32 x2 = x1 + wgui_CM3D_menu.width - 1;
    S32 y2 = y1 + wgui_CM3D_menu.height - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
#if defined (__GDI_MEMORY_PROFILE_2__)
    gui_set_multilayer_mask(gui_get_multilayer_mask() | UI_MUL_BKG_MAINMENU);
#endif 
    gui_show_3D_circular_menu(&wgui_CM3D_menu);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
}

/* For Draw Manager  */


/*****************************************************************************
 * FUNCTION
 *  move_circular_3d_menu
 * DESCRIPTION
 *  Move the circular 3D menu.
 * PARAMETERS
 *  s32X        [IN]        x
 *  s32Y        [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_circular_3d_menu(S32 s32X, S32 s32Y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_3D_circular_menu(&wgui_CM3D_menu, s32X, s32Y);
}

/* Add for Draw Manager */


/*****************************************************************************
 * FUNCTION
 *  resize_circular_3d_menu
 * DESCRIPTION
 *  Resize the circular 3D menu.
 * PARAMETERS
 *  s32Width        [IN]        width
 *  s32Height       [IN]        height
 * RETURNS
 *  void
 *****************************************************************************/
void resize_circular_3d_menu(S32 s32Width, S32 s32Height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_resize_3D_circular_menu(&wgui_CM3D_menu, s32Width, s32Height);
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_gfx_processor
 * DESCRIPTION
 *  Circular 3D menu animation processor (Hooked to a timer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_gfx_processor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CM3D_MENU_GFX_TIMER
    if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        gui_start_timer(CM3D_MENU_GFX_TIMER, circular_3d_menu_gfx_processor);
    }
    else
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &=
            ~(UI_3D_CIRCULAR_MENU_TRANSITION_L1 | UI_3D_CIRCULAR_MENU_TRANSITION_L2 | UI_3D_CIRCULAR_MENU_TRANSITION_R1
              | UI_3D_CIRCULAR_MENU_TRANSITION_R2);

        if (MMI_current_menu_type == CIRCULAR_3D_MENU)
        {
            wgui_CM3D_menu.item_highlighted(GetCurrHiliteID());
        }
        else
        {
            if (GetCurrHiliteID() == wgui_CM3D_menu.n_items - 1)
            {
                wgui_CM3D_menu.item_highlighted(0);
            }
            else
            {
                wgui_CM3D_menu.item_highlighted(GetCurrHiliteID() + 1);
            }
        }
    }
#else /* CM3D_MENU_GFX_TIMER */ 
    if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        circular_3d_menu_gfx_processor();
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_L2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_L2;
        circular_3d_menu_gfx_processor();
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R1)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R1;
        wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        circular_3d_menu_gfx_processor();
    }
    else if (wgui_CM3D_menu.flags & UI_3D_CIRCULAR_MENU_TRANSITION_R2)
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &= ~UI_3D_CIRCULAR_MENU_TRANSITION_R2;
        circular_3d_menu_gfx_processor();
    }
    else
    {
        show_circular_3d_menu();
        wgui_CM3D_menu.flags &=
            ~(UI_3D_CIRCULAR_MENU_TRANSITION_L1 | UI_3D_CIRCULAR_MENU_TRANSITION_L2 | UI_3D_CIRCULAR_MENU_TRANSITION_R1
              | UI_3D_CIRCULAR_MENU_TRANSITION_R2);

        if (MMI_current_menu_type == CIRCULAR_3D_MENU)
        {
            wgui_CM3D_menu.item_highlighted(GetCurrHiliteID());
        }
        else
        {
            if (GetCurrHiliteID() == wgui_CM3D_menu.n_items - 1)
            {
                wgui_CM3D_menu.item_highlighted(0);
            }
            else
            {
                wgui_CM3D_menu.item_highlighted(GetCurrHiliteID() + 1);
            }
        }
    }
#endif /* CM3D_MENU_GFX_TIMER */ 
}


/*****************************************************************************
 * FUNCTION
 *  stop_rotate_circular_menu
 * DESCRIPTION
 *  Stop the circular 3D menu animation effect.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void stop_rotate_circular_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CM3D_MENU_GFX_TIMER
    gui_cancel_timer(circular_3d_menu_gfx_processor);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_previous
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_previous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_3D_circular_menu_goto_previous_item(&wgui_CM3D_menu);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_L1;
    circular_3d_menu_gfx_processor();
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_next
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_3D_circular_menu_goto_next_item(&wgui_CM3D_menu);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    wgui_CM3D_menu.flags |= UI_3D_CIRCULAR_MENU_TRANSITION_R1;
    circular_3d_menu_gfx_processor();
}


/*****************************************************************************
 * FUNCTION
 *  register_circular_3d_menu_keys
 * DESCRIPTION
 *  Registers the key handlers for the circular 3D menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_circular_3d_menu_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(circular_3d_menu_previous, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_previous, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  register_rotate_menu_keys
 * DESCRIPTION
 *  Register the key handlers for the rotate menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_rotate_menu_keys(void)
{
#ifdef ROTATE_HORI
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(circular_3d_menu_previous, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else /* ROTATE_HORI */ 
    SetKeyHandler(circular_3d_menu_previous, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(circular_3d_menu_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
#endif /* ROTATE_HORI */ 
}


/*****************************************************************************
 * FUNCTION
 *  register_circular_3d_highlight_handler
 * DESCRIPTION
 *  Register the highlight handler for the 3d circular menu.
 * PARAMETERS
 *  f               [IN]        hightlight handler function
 * RETURNS
 *  void
 *****************************************************************************/
void register_circular_3d_highlight_handler(void (*f)(S32 item_index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_menu.item_highlighted = f;
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the circular 3D menu.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_CM3D_menu.highlighted_item = -1;
    gui_3D_circular_menu_goto_item(&wgui_CM3D_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  circular_3d_menu_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void circular_3d_menu_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_current_menu_type == ROTATE_MENU)
    {
        item_index -= 1;
        if (item_index < 0)
        {
            item_index = wgui_CM3D_menu.n_items - 1;
        }
    }
    gui_3D_circular_menu_goto_item(&wgui_CM3D_menu, item_index);
    show_circular_3d_menu();
}


/*****************************************************************************
 * FUNCTION
 *  register_3d_menu_shortcut_handler
 * DESCRIPTION
 *  Register the shortcut handler for the circular 3d menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_3d_menu_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    register_menu_shortcut_keys();
    register_menu_shortcut_handler(circular_3d_menu_goto_item);
}

#endif /* ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU)) */ 

/* 
 * Slide control implementation  
 * 
 * Different implementation than 'horizontal_slide' and 'vertical_slide'
 */


/*****************************************************************************
 * FUNCTION
 *  create_slide_control
 * DESCRIPTION
 *  Create the slider control.
 * PARAMETERS
 *  s       [IN]        slider control object         
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void create_slide_control(slide_control *s, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->x = x;
    s->y = y;
    s->background_image = NULL;
    s->slide_image = NULL;
    s->value_string_width = 0;
    s->value_string_height = 0;
    s->value_string_gap = 0;
    s->lower_limit = 0;
    s->upper_limit = 0;
    s->current_value = 0;
#ifdef GDI_USING_LAYER
    s->display_layer = GDI_ERROR_HANDLE;
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    s->pen_state = GUI_SLIDE_CONTROL_PEN_STATE_INVALID;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_images
 * DESCRIPTION
 *  Set the slider control background and slider image.
 * PARAMETERS
 *  s                       [IN]        slider control object         
 *  background_image        [IN]        background image
 *  slide_image             [IN]        slider image
 * RETURNS
 *  void
 *****************************************************************************/
void set_slide_control_images(slide_control *s, PU8 background_image, PU8 slide_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->background_image = background_image;
    s->slide_image = slide_image;
    gui_measure_image(background_image, &s->bg_image_width, &s->bg_image_height);
    gui_measure_image(slide_image, &s->slide_image_width, &s->slide_image_height);
    s->width = s->bg_image_width - s->slide_image_width;
}

#ifdef GDI_USING_LAYER


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_layer
 * DESCRIPTION
 *  Set the slider control display layer
 * PARAMETERS
 *  s           [IN]        slider control object       
 *  layer       [IN]        layer handle to display the slider control
 * RETURNS
 *  void
 *****************************************************************************/
void set_slide_control_layer(slide_control *s, gdi_handle layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->display_layer = layer;
}


/*****************************************************************************
 * FUNCTION
 *  reset_slide_control_layer
 * DESCRIPTION
 *  Reset the slider control display layer.
 * PARAMETERS
 *  s           [IN]        slider control object
 * RETURNS
 *  void
 *****************************************************************************/
void reset_slide_control_layer(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->display_layer = GDI_ERROR_HANDLE;
}

#endif /* GDI_USING_LAYER */ 


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_label
 * DESCRIPTION
 *  Set the slider label text.
 * PARAMETERS
 *  s               [IN]        slider control object
 *  label_string    [IN]        slider label text
 * RETURNS
 *  void
 *****************************************************************************/
void set_slide_control_label(slide_control *s, U8 *label_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->label_string = label_string;
    if (s->label_string)
    {
        S32 str_width = 0, str_height = 0;

        gui_measure_string((UI_string_type) s->label_string, &str_width, &str_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  show_slide_control
 * DESCRIPTION
 *  Show the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object 
 * RETURNS
 *  void
 *****************************************************************************/
void show_slide_control(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, ub, lb, r;
    S32 move_width;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = 255;
    c.g = 255;
    c.b = 255;
    c.alpha = 100;
#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->display_layer);
    }
#endif /* GDI_USING_LAYER */ 
    gui_push_clip();
    gui_reset_clip();
    gui_fill_rectangle(s->x, s->y, s->x + s->bg_image_width - 1, s->y + s->bg_image_height - 1, c);

    gui_show_image(s->x, s->y, s->background_image);
    ub = s->upper_limit;
    lb = s->lower_limit;
    r = ub - lb;
    if (r == 0)
    {
        r = 1;
    }

    /* s->width = s->bg_image_width - s->slide_image_width in set_slide_control_images() */
    move_width = s->width - UI_SLIDER_X1_GAP - UI_SLIDER_X2_GAP;
    MMI_DBG_ASSERT(move_width >= 0);

    x = ((s->current_value - lb) * move_width) / r;
    
    gui_show_transparent_image(
        s->x + x + UI_SLIDER_X1_GAP,
        s->y + ((s->bg_image_height - s->slide_image_height) >> 1) /* s->start_y */ ,
        s->slide_image,
        0);
    gui_pop_clip();
#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* GDI_USING_LAYER */ 
}


/*****************************************************************************
 * FUNCTION
 *  show_slide_control_focus_area
 * DESCRIPTION
 *  Draw the focus rectangle of the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object     
 * RETURNS
 *  void
 *****************************************************************************/
void show_slide_control_focus_area(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->display_layer);
    }
#endif /* GDI_USING_LAYER */ 
    x1 = MMI_current_slide_control->x - GUI_SLIDE_CONTROL_FOCUS_GAP;
    y1 = MMI_current_slide_control->y - GUI_SLIDE_CONTROL_FOCUS_GAP;
    x2 = MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width - 1 + GUI_SLIDE_CONTROL_FOCUS_GAP;
    y2 = MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height - 1 + GUI_SLIDE_CONTROL_FOCUS_GAP;
    gdi_layer_reset_clip();
    gdi_draw_rect(x1, y1, x2, y2, GDI_COLOR_RED);
    gdi_layer_blt_previous(x1, y1, x2, y2);
#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* GDI_USING_LAYER */ 
}


/*****************************************************************************
 * FUNCTION
 *  hide_slide_control_focus_area
 * DESCRIPTION
 *  Clear the focus rectangle of the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object    
 * RETURNS
 *  void
 *****************************************************************************/
void hide_slide_control_focus_area(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->display_layer);
    }
#endif /* GDI_USING_LAYER */ 
    x1 = MMI_current_slide_control->x - 2;
    y1 = MMI_current_slide_control->y - 2;
    x2 = MMI_current_slide_control->x + MMI_current_slide_control->bg_image_width + 1;
    y2 = MMI_current_slide_control->y + MMI_current_slide_control->bg_image_height + 1;
    gdi_layer_reset_clip();
    gdi_draw_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gdi_layer_blt_previous(x1, y1, x2, y2);
#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* GDI_USING_LAYER */ 
}


/*****************************************************************************
 * FUNCTION
 *  show_slide_control_label
 * DESCRIPTION
 *  Show the slider control label text.
 * PARAMETERS
 *  s               [IN]        slider control object
 * RETURNS
 *  void
 *****************************************************************************/
void show_slide_control_label(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->label_string)
    {
        S32 str_width = 0, str_height = 0;

    #ifdef GDI_USING_LAYER
        if (s->display_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_push_and_set_active(s->display_layer);
        }
    #endif /* GDI_USING_LAYER */ 
        gui_measure_string((UI_string_type) s->label_string, &str_width, &str_height);
        if (r2lMMIFlag)
        {
            /* align the label to right edge of the slider background image */
            gui_move_text_cursor(s->x + s->bg_image_width - 1, s->y - str_height - GUI_SLIDE_CONTROL_TEXT_LABEL_TO_SLIDE_GAP);
        }
        else
        {
            gui_move_text_cursor(s->x, s->y - str_height - GUI_SLIDE_CONTROL_TEXT_LABEL_TO_SLIDE_GAP);
        }
        gui_set_text_color(UI_COLOR_BLACK);
        gui_print_text((UI_string_type) s->label_string);
    #ifdef GDI_USING_LAYER
        if (s->display_layer != GDI_ERROR_HANDLE)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* GDI_USING_LAYER */ 
    }
}

/* color scheme of background of slide control */
UI_filled_area wgui_slide_value_background_filler = {UI_FILLED_AREA_TYPE_COLOR | UI_FILLED_AREA_SINGLE_BORDER,
    UI_NULL_IMAGE,
    NULL,
    {255, 255, 255, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    0
};


/*****************************************************************************
 * FUNCTION
 *  show_slide_control_value
 * DESCRIPTION
 *  Show the slider control value.
 * PARAMETERS
 *  s               [IN]        slider control object      
 * RETURNS
 *  void
 *****************************************************************************/
void show_slide_control_value(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    color c = gui_color(0, 0, 0);
    U8 ts[32];
    S32 x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->flags & GUI_SLIDE_CONTROL_VALUE_POS_NONE)
    {
        return;
    }

    gui_itoa(s->current_value, (UI_string_type) ts, 10);
    gui_reset_clip();
    gui_set_font(&MMI_default_font);
    gui_measure_string((UI_string_type) ts, &w, &h);

    /* keep 1 pixel gap between the value rectangle and the focus rectangle */
    if (s->flags == GUI_SLIDE_CONTROL_VALUE_POS_HEAD)
    {
        x1 = s->x - s->value_string_width - s->value_string_gap - GUI_SLIDE_CONTROL_FOCUS_GAP - 1 - 1;  /* gap of focus rectangle */
        // y1 = s->y + s->bg_image_height - s->value_string_height + 1;
        y1 = s->y;
        x2 = x1 + s->value_string_width;
        if (s->value_string_height >= s->bg_image_height)
        {
            y2 = y1 + s->value_string_height;
        }
        else
        {
            y2 = y1 + s->bg_image_height;
        }
    }
    else if (s->flags == GUI_SLIDE_CONTROL_VALUE_POS_TAIL)
    {
        x1 = s->x + s->bg_image_width + s->value_string_gap + GUI_SLIDE_CONTROL_FOCUS_GAP + 1;  /* gap of focus rectangle */
        // y1 = s->y + s->bg_image_height - s->value_string_height + 1;
        y1 = s->y;
        x2 = x1 + s->value_string_width;
        if (s->value_string_height >= s->bg_image_height)
        {
            y2 = y1 + s->value_string_height;
        }
        else
        {
            y2 = y1 + s->bg_image_height;
        }
    }
    else if (s->flags == GUI_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
    {
        x1 = s->x + ((s->bg_image_width - s->value_string_width) >> 1) + 1;
        y1 = s->y + s->bg_image_height + GUI_SLIDE_CONTROL_FOCUS_GAP + 1;       /* 1 pixel gap for focus */
        x2 = x1 + s->value_string_width;
        y2 = y1 + s->value_string_height;
    }
    else
    {
        return;
    }

#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(s->display_layer);
    }
#endif /* GDI_USING_LAYER */ 

    gdi_draw_solid_rect(x1 + 1, y1 + 1, x2 - 1, y2 - 1, GDI_COLOR_WHITE);
    gdi_draw_rect(x1, y1, x2, y2, GDI_COLOR_BLACK);
    /* gui_draw_filled_area(x1,y1,x2,y2,&wgui_slide_value_background_filler); */

    gui_set_text_color(c);

    /* center alignment in both directions */
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x2 - ((x2 - x1 - w) >> 1) - 1, y1 + ((y2 - y1 - h) >> 1));
    }
    else
    {
        gui_move_text_cursor(x1 + ((x2 - x1 - w) >> 1), y1 + ((y2 - y1 - h) >> 1));
    }

    gui_print_text((UI_string_type) ts);
    gui_BLT_double_buffer(x1, y1, x2, y2);

#ifdef GDI_USING_LAYER
    if (s->display_layer != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif /* GDI_USING_LAYER */ 
}


/*****************************************************************************
 * FUNCTION
 *  slide_control_previous
 * DESCRIPTION
 *  Decrease the slider control value.
 * PARAMETERS
 *  s               [IN]        slider control object     
 * RETURNS
 *  void
 *****************************************************************************/
void slide_control_previous(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->current_value > s->lower_limit)
    {
        s->current_value--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  slide_control_next
 * DESCRIPTION
 *  Increase the slider control value.
 * PARAMETERS
 *  s               [IN]        slider control object     
 * RETURNS
 *  void
 *****************************************************************************/
void slide_control_next(slide_control *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->current_value < s->upper_limit)
    {
        s->current_value++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_limits
 * DESCRIPTION
 *  Set the slider control value range.
 * PARAMETERS
 *  s               [IN]        slider control object         
 *  lower_limit     [IN]        lowest (minimum) limit
 *  upper_limit     [IN]        uppest (maximum) limit
 * RETURNS
 *  void
 *****************************************************************************/
void set_slide_control_limits(slide_control *s, S32 lower_limit, S32 upper_limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digits;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->lower_limit = lower_limit;
    s->upper_limit = upper_limit;

    /* measure maximum number string width and height */
    for (digits = 1; (upper_limit /= 10); digits++);
    mmi_fe_measure_string_by_char_num((U8*)L"0123456789", digits, &s->value_string_width, &s->value_string_height);

    /* leave 2-pixel gaps for the text and rectangle in each direction */
    // TODO: config this in gui_config.h
    s->value_string_width += 4;
    s->value_string_height += 4;
}


/*****************************************************************************
 * FUNCTION
 *  set_slide_control_value
 * DESCRIPTION
 *  Set the slider control value.
 * PARAMETERS
 *  s           [IN]        slider control object         
 *  value       [IN]        slider control value
 * RETURNS
 *  void
 *****************************************************************************/
void set_slide_control_value(slide_control *s, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((value < s->lower_limit) || (value > s->upper_limit))
    {
        return;
    }
    s->current_value = value;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_setup_slide_control
 * DESCRIPTION
 *  Setup the slider control.
 * PARAMETERS
 *  s                   [IN]        slider control object        
 *  x                   [IN]        x
 *  y                   [IN]        y
 *  lower_limit         [IN]        minimum slider value
 *  upper_limit         [IN]        maximum slider value
 *  current_value       [IN]        current slider value
 *  change_callback     [IN]        slider change callback
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_setup_slide_control(
        slide_control *s,
        S32 x,
        S32 y,
        S32 lower_limit,
        S32 upper_limit,
        S32 current_value,
        void (*change_callback) (S32 value))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_slide_control(s, x, y);
    set_slide_control_images(
        s,
        (PU8) get_image(WGUI_SLIDE_CONTROL_BG_IMAGE_ID),
        (PU8) get_image(WGUI_SLIDE_CONTROL_SI_IMAGE_ID));
    s->change_callback = change_callback;
    set_slide_control_limits(s, lower_limit, upper_limit);
    set_slide_control_value(s, current_value);
}


/*****************************************************************************
 * FUNCTION
 *  move_slide_control_value
 * DESCRIPTION
 *  Move the position of the slider control value text.
 * PARAMETERS
 *  s       [IN]        slider control object         
 *  x       [IN]        x
 *  y       [IN]        y
 * RETURNS
 *  void
 *****************************************************************************/
void move_slide_control_value(slide_control *s, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* label is displayed */
    if (s->label_string)
    {
        S32 str_width = 0, str_height = 0;

        gui_measure_string((UI_string_type) s->label_string, &str_width, &str_height);
        s->x = x;
        s->y = y + str_height + 2;  /* gap is fixed to 2 */
    }
    else
    {
        s->x = x;
        s->y = y;
    }

}

#if defined(__MMI_UI_DALMATIAN_MAINMENU__)

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);


/*****************************************************************************
 * FUNCTION
 *  show_animated_balls
 * DESCRIPTION
 *  Animate the ball when up or down arrow is pressed in Main Menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_animated_balls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUMBER_OF_FRAMES - 1; i++)
    {
        gui_lock_double_buffer();
        gui_push_clip();
        gui_set_clip(MMI_content_x, MMI_content_y, UI_device_width - 1, UI_device_height - MMI_button_bar_height - 1);
        for (j = 0; j < NUMBER_OF_BALLS; j++)
        {
            x1 = *(ball[j].position + (2 * i + 0));
            y1 = *(ball[j].position + (2 * i) + 1);
            x2 = x1 + BALL_WIDTH - 1;
            y2 = y1 + BALL_HEIGHT - 1;
            if (x1 < MMI_content_x)
            {
                x1 = MMI_content_x;
            }
            if (y1 < MMI_content_y)
            {
                y1 = MMI_content_y;
            }
            if (x2 > UI_device_width - 1)
            {
                x2 = UI_device_width - 1;
            }
            if (y2 > UI_device_height - MMI_button_bar_height - 1)
            {
                y2 = UI_device_height - MMI_button_bar_height - 1;
            }
            _show_bitmap(x1, y1, &ball[j].image);
        }
        if (i == (NUMBER_OF_FRAMES / 2))
        {
            if (is_next_item)
            {
                gui_fixed_list_menu_goto_next_item(&MMI_fixed_list_menu);
            }
            else
            {
                gui_fixed_list_menu_goto_previous_item(&MMI_fixed_list_menu);
            }
        }
        for (j = 0; j < NUMBER_OF_BALLS; j++)
        {
            x1 = *(ball[j].position + (2 * (i + 1) + 0));
            y1 = *(ball[j].position + (2 * (i + 1)) + 1);
            x2 = x1 + BALL_WIDTH - 1;
            y2 = y1 + BALL_HEIGHT - 1;
            if (x1 < MMI_content_x)
            {
                x1 = MMI_content_x;
            }
            if (y1 < MMI_content_y)
            {
                y1 = MMI_content_y;
            }
            if (x2 > UI_device_width - 1)
            {
                x2 = UI_device_width - 1;
            }
            if (y2 > UI_device_height - MMI_button_bar_height)
            {
                y2 = UI_device_height - MMI_button_bar_height;
            }
            _get_bitmap(x1, y1, x2, y2, &ball[j].image);
        }
        for (j = 0; j < NUMBER_OF_BALLS; j++)
        {
            gui_show_image(
                *(ball[j].position + (2 * (i + 1)) + 0),
                *(ball[j].position + (2 * (i + 1)) + 1),
                get_image(MAIN_MENU_DALMATIAN_BALL));
        }
        gui_pop_clip();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_content_x,
            MMI_content_y,
            UI_device_width - 1,
            UI_device_height - MMI_button_bar_height - 1);
    }
}
#endif /* defined(__MMI_UI_DALMATIAN_MAINMENU__) */ 

#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  wgui_slide_control_translate_pen_position
 * DESCRIPTION
 *  Translate pen x position to the corresponding slider
 * PARAMETERS
 *  s           [IN]        slider control object         
 *  x           [IN]        pen x
 *  value       [OUT]       slider value      
 *  state       [OUT]       slider state
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_slide_control_translate_pen_position(
                slide_control *s,
                S16 x,
                S32 *value,
                gui_slide_control_pen_state_enum *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ub = s->upper_limit;
    S32 lb = s->lower_limit;
    S32 r = ub - lb;
    S32 sx;     /* scroll button x position */
    S32 sx2;    /* scroll button right x position */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x -= s->x;

    if (r == 0)
    {
        r = 1;
    }

    sx = ((s->current_value - lb) * s->width) / r;
    sx2 = ((s->current_value + 1 - lb) * s->width) / r - 1;

    *state = GUI_SLIDE_CONTROL_PEN_STATE_SLIDE;
    *value = s->current_value;
    if ((x < sx) && (s->current_value > lb))
    {
        if (x < 0)
        {
            x = 0;
        }
        *state = GUI_SLIDE_CONTROL_PEN_STATE_AREA1;
        /* (value * width / r)  <= x  < ((value + 1) * width / r) */
        *value = lb + x * r / s->width; /* Maybe lower than the real value due to integer division */
    }
    else if ((x >= sx + s->slide_image_width) && (x > sx2) && (s->current_value < ub))
    {
        /* It is possible s_slide_image_width is smaller or larger than (sx2-sx1+1) */

        if (x >= s->width + s->slide_image_width)
        {
            x = s->width + s->slide_image_width - 1;
        }
        *state = GUI_SLIDE_CONTROL_PEN_STATE_AREA2;
        *value = ub - (s->width + s->slide_image_width - 1 - x) * r / s->width; /* Maybe larger than the real value due to integer division */
    }

    MMI_DBG_ASSERT(*value >= lb && *value <= ub);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_slide_control_translate_pen_event
 * DESCRIPTION
 *  Pen event handler of the slider control.
 * PARAMETERS
 *  s               [IN]        slider control object         
 *  pen_event       [IN]        pen event    
 *  x               [IN]        pen x
 *  y               [IN]        pen y
 *  slide_event     [OUT]       pen event
 *  slide_param     [OUT]       pen parameter  
 * RETURNS
 *  Return MMI_TRUE if the pen event is handled; otherwise, MMI_FALSE.
 *****************************************************************************/
BOOL wgui_slide_control_translate_pen_event(
        slide_control *s,
        mmi_pen_event_type_enum pen_event,
        S16 x,
        S16 y,
        gui_slide_control_pen_event_enum *slide_event,
        gui_pen_event_param_struct *slide_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    S32 new_value;
    gui_slide_control_pen_state_enum new_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *slide_event = GUI_SLIDE_CONTROL_PEN_NONE;
    GUI_PEN_EVENT_PARAM_SET_VOID(slide_param);

    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, s->x, s->y, s->bg_image_width, s->bg_image_height))
            {
                wgui_slide_control_translate_pen_position(s, x, &new_value, &new_state);
                s->pen_state = new_state;

                if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA1)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->current_value - 1);
                }
                else if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA2)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->current_value + 1);
                }
            }
            else
            {
                ret = MMI_FALSE;
                s->pen_state = GUI_SLIDE_CONTROL_PEN_STATE_INVALID;
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_REPEAT:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_MOVE:
            if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA1)
            {
                wgui_slide_control_translate_pen_position(s, x, &new_value, &new_state);
                if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA1)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->current_value - 1);
                }
            }
            else if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA2)
            {
                wgui_slide_control_translate_pen_position(s, x, &new_value, &new_state);
                if (new_state == GUI_SLIDE_CONTROL_PEN_STATE_AREA2)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, s->current_value + 1);
                }
            }
            else if (s->pen_state == GUI_SLIDE_CONTROL_PEN_STATE_SLIDE)
            {
                wgui_slide_control_translate_pen_position(s, x, &new_value, &new_state);
                if (new_value != s->current_value)
                {
                    *slide_event = GUI_SLIDE_CONTROL_PEN_JUMP_TO_I;
                    GUI_PEN_EVENT_PARAM_SET_INTEGER(slide_param, new_value);
                }
            }
            else
            {
                /* Ignore the event */
            }
            break;

        case MMI_PEN_EVENT_UP:
            /* FALLTHROUGH no break */
        case MMI_PEN_EVENT_ABORT:
            /* Do nothing */
            break;
    }

    return ret;
}

#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  reset_fixed_list_show_empty
 * DESCRIPTION
 *  Reset fixed list show empty flag. The "empty" string is shown by default. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_fixed_list_show_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_fixed_list_show_empty = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  disable_fixed_list_show_empty
 * DESCRIPTION
 *  Do not show the fixed list empty string.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void disable_fixed_list_show_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_fixed_list_show_empty = MMI_FALSE;
}


#ifdef __MMI_UI_TECHNO_MAINMENU__

#if defined(__MMI_MAINLCD_176X220__)
MMTechno_image_position image_position_next[] = 
{
    {17, 136},  /* positions for menu item 1, 5, 9, ... */
    {10, 100},
    {20, 45},
    {64, 67},
    {67, 85},

    {32, 97},   /* positions for menu item 2, 6, 10, ... */
    {26, 70},
    {38, 40},
    {73, 55},
    {65, 95},

    {50, 63},   /* positions for menu item 3, 7, 11, ... */
    {75, 52},
    {87, 78},
    {45, 98},
    {30, 95},

    {66, 27},   /* positions for menu item 4, 8, 12, ... */
    {88, 48},
    {85, 82},
    {52, 105},
    {30, 80}

};

MMTechno_image_position image_position_previous[] = 
{
    {17, 136},  /* positions for menu item 1, 5, 9, ... */
    {35, 140},
    {65, 125},
    {80, 95},
    {60, 75},

    {32, 97},   /* positions for menu item 2, 6, 10, ... */
    {40, 115},
    {78, 105},
    {90, 60},
    {65, 65},

    {50, 63},   /* positions for menu item 3, 7, 11, ... */
    {30, 72},
    {15, 100},
    {45, 120},
    {40, 105},

    {66, 27},   /* positions for menu item 4, 8, 12, ... */
    {40, 36},
    {15, 70},
    {42, 105},
    {45, 100}

};

#elif defined (__MMI_MAINLCD_128X160__)
MMTechno_image_position image_position_next[] = 
{
    {5, 86},    /* positions for menu item 1, 5, 9, ... */
    {5, 65},
    {25, 35},
    {64, 45},
    {30, 54},

    {23, 54},   /* positions for menu item 2, 6, 10, ... */
    {5, 35},
    {35, 15},
    {55, 65},
    {30, 54},

    {34, 32},   /* positions for menu item 3, 7, 11, ... */
    {55, 25},
    {65, 55},
    {25, 75},
    {30, 54},

    {47, 4},    /* positions for menu item 4, 8, 12, ... */
    {65, 25},
    {50, 65},
    {25, 70},
    {30, 54}

};

MMTechno_image_position image_position_previous[] = 
{
    {5, 86},    /* positions for menu item 1, 5, 9, ... */
    {30, 80},
    {65, 55},
    {25, 35},
    {30, 50},

    {23, 54},   /* positions for menu item 2, 6, 10, ... */
    {35, 80},
    {65, 70},
    {55, 45},
    {30, 50},

    {34, 32},   /* positions for menu item 3, 7, 11, ... */
    {15, 55},
    {25, 80},
    {45, 65},
    {30, 50},

    {47, 4},    /* positions for menu item 4, 8, 12, ... */
    {10, 36},
    {15, 70},
    {45, 90},
    {30, 50}

};
#endif 

S16 frame_number[] = 
{
    TECHNO_MENU_ANIMATION_FRAME_ONE,
    TECHNO_MENU_ANIMATION_FRAME_TWO,
    TECHNO_MENU_ANIMATION_FRAME_THREE,
    TECHNO_MENU_ANIMATION_FRAME_FOUR,
    TECHNO_MENU_ANIMATION_FRAME_FIVE
};


/*****************************************************************************
 * FUNCTION
 *  create_techno_main_menu
 * DESCRIPTION
 *  Initialize the main menu structure for Techno Style.
 * PARAMETERS
 *  no_of_main_menu_items       [IN]        number of items
 *  image                       [IN]        item image array
 * RETURNS
 *  void
 *****************************************************************************/
void create_techno_main_menu(S32 no_of_main_menu_items, MMI_ID_TYPE *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < no_of_main_menu_items; i++)
    {
        Techno_menu[i].item_image = get_image(image[i]);
        Techno_menu[i].item_position = &image_position_next[5 * (i % 4)];
    }
    Techno_bgimage[0] = get_image(MAIN_MENU_PAGE_BG);
    Techno_bgimage[1] = get_image(MAIN_MENU_PAGE_BG2);
    Techno_bgimage[2] = get_image(MAIN_MENU_PAGE_BG3);
    Techno_bgimage[3] = get_image(MAIN_MENU_PAGE_BG4);
    Techno_bgimage[4] = get_image(MAIN_MENU_PAGE_BG5);
}


/*****************************************************************************
 * FUNCTION
 *  associate_techno_item_positions
 * DESCRIPTION
 *  Associate the techno menu item position pointer.
 * PARAMETERS
 *  is_next     [IN]        0 for previous and 1 for next items.
 * RETURNS
 *  void
 *****************************************************************************/
void associate_techno_item_positions(U8 is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        for (i = 0; i < (MMI_fixed_list_menu.n_items); i++)
        {
            Techno_menu[i].item_position = &image_position_next[5 * (i % 4)];
        }
    }
    else
    {
        for (i = 0; i < (MMI_fixed_list_menu.n_items); i++)
        {
            Techno_menu[i].item_position = &image_position_previous[5 * (i % 4)];
        }
    }        
}


/*****************************************************************************
 * FUNCTION
 *  show_techno_menu_animation
 * DESCRIPTION
 *  Show the animated techno style page main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_techno_menu_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 Menu_number = MMI_menu_shortcut_number - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (current_frame = FIRST_FRAME; current_frame <= LAST_FRAME; current_frame++)
    {
        gui_lock_double_buffer();
        gui_push_clip();
        gui_set_clip(
            MMI_content_x,
            MMI_content_y,
            MMI_content_x + MMI_content_width - 1,
            MMI_content_y + MMI_content_height - 1);
        if (is_next_item == 1)
        {
            if (frame >= LAST_FRAME)
            {
                frame = FIRST_FRAME;
            }
            gui_show_image(MMI_content_x, MMI_content_y, Techno_bgimage[frame++]);
        }
        else
        {
            if (frame < FIRST_FRAME)
            {
                frame = LAST_FRAME;
            }
            gui_show_image(MMI_content_x, MMI_content_y, Techno_bgimage[frame--]);
        }

        gui_show_animated_image_frame(
            (Techno_menu[Menu_number].item_position + current_frame)->x,
            (Techno_menu[Menu_number].item_position + current_frame)->y,
            (Techno_menu[Menu_number].item_image),
            frame_number[current_frame]);
        gui_pop_clip();
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            MMI_content_x,
            MMI_content_y,
            MMI_content_x + MMI_content_width - 1,
            MMI_content_y + MMI_content_height - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  show_techno_menu
 * DESCRIPTION
 *  Show the page main menu last frame.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_techno_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(
        MMI_content_x,
        MMI_content_y,
        MMI_content_x + MMI_content_width - 1,
        MMI_content_y + MMI_content_height - 1);
    frame = LAST_FRAME;
    gui_show_image(MMI_content_x, MMI_content_y, Techno_bgimage[frame]);
    gui_show_animated_image_frame(
        (Techno_menu[MMI_menu_shortcut_number - 1].item_position + LAST_FRAME)->x,
        (Techno_menu[MMI_menu_shortcut_number - 1].item_position + LAST_FRAME)->y,
        (Techno_menu[MMI_menu_shortcut_number - 1].item_image),
        frame_number[LAST_FRAME]);
    gui_pop_clip();
}

#endif /* __MMI_UI_TECHNO_MAINMENU__ */


