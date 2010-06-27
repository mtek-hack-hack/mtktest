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
 *  gui_title.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  title related funtions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "Wgui_title.h"
#include "gui_title.h"
#include "wgui_status_icons.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MMI_UI_TITLE_TRANSITION__

#define GUI_TITLE_TRANSITION_R2L_COUNT 5        /* UI_device_width; */
#define GUI_TITLE_TRANSITION_L2R_COUNT 5        /* UI_device_width; */
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__

#define GUI_TITLE_EFFECT_TYPE__(A)   MMI_UI_TITLE_IMAGE_ANIMATE_##A
#define GUI_TITLE_EFFECT_TYPE_(A)    GUI_TITLE_EFFECT_TYPE__(A)
#define GUI_TITLE_EFFECT_TYPE(A)     GUI_TITLE_EFFECT_TYPE_(A)

#define GUI_TITLE_IMAGE_ANIMATION_TIMER 50
#define SHIFT_TITLE_IMAGE 5

#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

#define GUI_TITLE_SCROLL_TIME           50

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*****************************************************************************              
 * Variable                                                                    
 *****************************************************************************/
UI_window_title_theme *current_window_title_theme = NULL;
UI_window_title_theme *current_thick_title_theme = NULL;
U16 title_bg_id = 0;    /* added for customized title background image */

static gui_title_struct *g_gui_title_current_scrolling_target;

S32 (*gui_title_show_normal) (gui_title_struct *, U32) = NULL;
void (*gui_title_show_background) (gui_title_struct *, S32, S32, S32, S32) = NULL;

extern BOOL r2lMMIFlag;

#ifdef __MMI_UI_TITLE_TRANSITION__

S32 g_title_prev_menu_shortcut = -1;
S32 g_title_temp_last_shortcut = -1;
static bitmap g_title_bitmap_for_transition;
static U8 bitmap_data_for_title_transition[LCD_WIDTH * MAX_TITLE_AREA_HEIGHT_FOR_TRANSITION * __MMI_MAIN_BASE_LAYER_FORMAT__]; /* for 16 bit */

#ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
static S32 transition_required = 0;
#endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__

static gui_title_struct *g_gui_title_current_animation_target;
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
#ifdef __MMI_UI_TITLE_TRANSITION__
static void gui_title_get_bitmap_for_transition(gui_title_struct *t);
static MMI_BOOL gui_title_pre_show(gui_title_struct *t);

static gui_title_struct *g_gui_title_transition_target;

#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)

#ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
static void gui_title_show_previous_for_transition(gui_title_struct *t);
#endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */

static void gui_title_show_transition_non_blocking(void);
#else /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 
static void gui_title_show_transition(gui_title_struct *t);

#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 
static void gui_title_show_scrolling_background(S32 x1, S32 y1, S32 x2, S32 y2);
static void gui_title_scrolling_timer_callback(void);
static void gui_title_show_scrolling(gui_title_struct *t);
static void gui_title_show_scrolling_ex(void);

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
static void gui_title_animate_image(void);
static void gui_title_show_animate_image(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2);
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);

#ifdef __MMI_UI_TITLE_TRANSITION__


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_transition_enable
 * DESCRIPTION
 *  enable transition
 * PARAMETERS
 *  t               [IN/OUT]        Is the struct of title   
 *  enable          [IN]        
  * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_transition_enable(gui_title_struct *t, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->enable_transition = enable;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_transition_enable
 * DESCRIPTION
 *  is title transition enalbed
 * PARAMETERS
 *  t               [IN/OUT]        Is the struct of title 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_is_transition_enable(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->enable_transition;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_bitmap_for_transition
 * DESCRIPTION
 *  This functions is for getting the bitmap for previous title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_get_bitmap_for_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_title_bitmap_for_transition.data = bitmap_data_for_title_transition;
    _get_bitmap(
        t->prev_title_x,
        MMI_title_y,
        t->prev_title_x + MMI_title_width - 1,
        MMI_title_y + MMI_title_height - 1,
        &g_title_bitmap_for_transition);
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_pre_show
 * DESCRIPTION
 *  Do something before show title in transition
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *****************************************************************************/
static MMI_BOOL gui_title_pre_show(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_title_transition_target = t;
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
    if (t->enable_transition && is_in_nonblocking_title_transition() == 0)
    {
        if (t->prev_icon || mmi_ucs2strlen((const s8*)t->prev_text) == 0)
        {
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
            gui_title_get_bitmap_for_transition(t);
        #endif 
        }
    }
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    if (is_in_nonblocking_title_transition() == 0 && g_title_bitmap_for_transition.data != NULL)
#else 
    if (is_in_nonblocking_title_transition() == 0 && transition_required == 1)
#endif 
    {
#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 
        if (t->transition_style && t->check_for_transition)
        {
            if (t->transition_on_keys)
            {
                U16 keyCode, keyType;

                GetkeyInfo(&keyCode, &keyType);
                if (keyCode == KEY_RIGHT_ARROW)
                {
                    set_title_transition(WGUI_TRANSITION_R2L);

                    t->check_for_transition = 0;
                #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
                    disable_animated_title_effect();
                #endif 
                #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
                    gui_title_show_transition_non_blocking();
                #else 
                    gui_title_show_transition(t);
                #endif 
                #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
                    enable_animated_title_effect();
                #endif 
                    t->check_for_transition = 1;
                }
                else if (keyCode == KEY_LEFT_ARROW)
                {
                    set_title_transition(WGUI_TRANSITION_L2R);
                    t->check_for_transition = 0;
                #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
                    gui_title_show_transition_non_blocking();
                #else 
                    gui_title_show_transition(t);
                #endif 
                    t->check_for_transition = 1;
                }
                else
                {
                    bitblt = MMI_FALSE;
                }
            }
            else
            {
                t->check_for_transition = 0;
            #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
                gui_title_show_transition_non_blocking();
            #else 
                gui_title_show_transition(t);
            #endif 
                t->check_for_transition = 1;
            }
        }
    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
    }
    else
    {
    #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        if (g_title_bitmap_for_transition.data == NULL && is_in_nonblocking_title_transition() == 0 &&
            (t->check_for_transition && t->transition_style))
    #else /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
        if (is_in_nonblocking_title_transition() == 0 && transition_required == 0 &&
            (t->check_for_transition && t->transition_style))
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
        {
            bitblt = MMI_FALSE;
        }
    }
    #endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 
    return bitblt;
}


#if(!TITLE_TRANSITION_STYLE_NON_BLOCKING)
/*****************************************************************************
 * FUNCTION
 *  gui_title_show_transition
 * DESCRIPTION
 *  This functions draws the transition title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (t->transition_style)
    {
        case WGUI_TRANSITION_R2L:
        {
            S32 prev_x = t->x;
            S32 prev_width = t->width;
            S32 i, transition_count;
            S32 transition_resolution;

            i = transition_count = GUI_TITLE_TRANSITION_R2L_COUNT;
            transition_resolution = t->width / transition_count;
            t->x = t->x + t->width - 1;
            while (i - 1)
            {
                t->x -= transition_resolution;

                gui_title_show(t, GUI_TITLE_PART_ALL);
                i--;
            }
            t->width = prev_width;
            t->x = prev_x;

        }
            break;
        case WGUI_TRANSITION_L2R:
        {
            S32 prev_x = t->x;
            S32 prev_width = t->width;
            S32 i, transition_count;
            S32 transition_resolution;

            i = transition_count = GUI_TITLE_TRANSITION_L2R_COUNT;
            transition_resolution = t->width / transition_count;
            t->x -= t->width;
            while (i - 1)
            {
                t->x += transition_resolution;
                gui_title_show(t, GUI_TITLE_PART_ALL);
                i--;
            }
            t->width = prev_width;
            t->x = prev_x;

        }
            break;
    }
}
#endif /* !TITLE_TRANSITION_STYLE_NON_BLOCKING */


/*****************************************************************************
 * FUNCTION
 *  gui_title_in_transition_blocking
 * DESCRIPTION
 *  is title transition in non block
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_in_transition_blocking(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->in_blocking;
}

#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)


/*****************************************************************************
 * FUNCTION
 *  gui_title_stop_transition_non_blocking
 * DESCRIPTION
 *  This functions draws the transition title with timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_stop_transition_non_blocking(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    S32 temp_menu_shortcut;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_title_show_transition_non_blocking);
    t->check_for_transition = 1;
    if (is_in_nonblocking_title_transition() == 1)
    {
        t->x = t->prev_title_x;
        gui_lock_double_buffer();
    #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        if (g_title_prev_menu_shortcut != -1)
        {
            temp_menu_shortcut = t->sc.number;
            t->sc.number = g_title_prev_menu_shortcut;
            gui_title_show(t, GUI_TITLE_PART_ALL);
            t->sc.number = temp_menu_shortcut;
        }
        else
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
        {
            gui_title_show(t, GUI_TITLE_PART_ALL);
        }
        gui_unlock_double_buffer();
        t->in_blocking = 0;
    }
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    g_title_bitmap_for_transition.data = NULL;
#else 
    transition_required = 0;
#endif 
}


#ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/*****************************************************************************
 * FUNCTION
 *  gui_title_show_previous_for_transition
 * DESCRIPTION
 *  Show the previous title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_previous_for_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_no = -1;
    U8 temp_title_string[GUI_TITLE_BUFFER_SIZE];
    PU8 temp_title_icon = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_no = t->sc.number;
    t->sc.number = g_title_temp_last_shortcut;

    mmi_ucs2ncpy((S8*)temp_title_string, (S8*)t->text, GUI_TITLE_MAX_LENGTH);
    temp_title_icon = t->icon;
    mmi_ucs2ncpy((S8*)t->text, (const S8*)t->prev_text, GUI_TITLE_MAX_LENGTH);
    t->icon = t->prev_icon;

    gui_title_show(t, GUI_TITLE_PART_ALL);

    t->sc.number = temp_no;
    mmi_ucs2ncpy((S8*)t->text, (const S8*)temp_title_string, GUI_TITLE_MAX_LENGTH);
    t->icon = temp_title_icon;
}
#endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_transition_non_blocking
 * DESCRIPTION
 *  This functions draws the transition title with timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_transition_non_blocking(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 transition_count;
    static S32 transition_resolution;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
    g_title_bitmap_for_transition.data = bitmap_data_for_title_transition;
#endif 
    switch (g_gui_title_transition_target->transition_style)
    {
        case WGUI_TRANSITION_R2L:
        {
            transition_count = GUI_TITLE_TRANSITION_R2L_COUNT;
            if (is_in_nonblocking_title_transition() == 0)
            {
                g_gui_title_transition_target->in_blocking = MMI_TRUE;
            #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                gui_title_show_previous_for_transition(t);
            #endif 
                transition_resolution = g_gui_title_transition_target->width / transition_count;
                g_gui_title_transition_target->x =
                    g_gui_title_transition_target->x + g_gui_title_transition_target->width - 1;
                gui_add_pre_cleanup_hook(wgui_title_tranisition_abort_cleanup_function);
            }
            g_gui_title_transition_target->x -= transition_resolution;
            move_menu_shortcut_handler(
                g_gui_title_transition_target->x + g_gui_title_transition_target->width - MMI_menu_shortcut_box.width,
                g_gui_title_transition_target->y);
            gui_lock_double_buffer();
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
            _show_bitmap(
                (g_gui_title_transition_target->x - g_gui_title_transition_target->width),
                g_gui_title_transition_target->y,
                &g_title_bitmap_for_transition);
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
            gui_title_show(g_gui_title_transition_target, GUI_TITLE_PART_ALL);
            gui_unlock_double_buffer();
            gdi_layer_blt_previous(
                g_gui_title_transition_target->prev_title_x,
                g_gui_title_transition_target->y,
                g_gui_title_transition_target->prev_title_x + g_gui_title_transition_target->width,
                g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
            if ((g_gui_title_transition_target->x - transition_resolution) > 0)
            {
                gui_start_timer(TITLE_TRANSITION_NON_BLOCKING_TIMER, gui_title_show_transition_non_blocking);
            }
            else
            {
                move_menu_shortcut_handler(
                    g_gui_title_transition_target->width - MMI_menu_shortcut_box.width,
                    g_gui_title_transition_target->y);
            #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                if (g_title_prev_menu_shortcut != -1)
                {
                    g_title_prev_menu_shortcut = -1;
                }
            #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
                gui_title_stop_transition_non_blocking(g_gui_title_transition_target);
                gdi_layer_blt_previous(
                    g_gui_title_transition_target->x,
                    g_gui_title_transition_target->y,
                    g_gui_title_transition_target->x + g_gui_title_transition_target->width,
                    g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
            }
            break;
        }
        case WGUI_TRANSITION_L2R:
        {
            transition_count = GUI_TITLE_TRANSITION_L2R_COUNT;
            if (is_in_nonblocking_title_transition() == 0)
            {
                g_gui_title_transition_target->in_blocking = MMI_TRUE;
            #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                gui_title_show_previous_for_transition(t);
            #endif 
                transition_resolution = g_gui_title_transition_target->width / transition_count;
                g_gui_title_transition_target->x -= g_gui_title_transition_target->width + 1;
                gui_add_pre_cleanup_hook(wgui_title_tranisition_abort_cleanup_function);
            }

            g_gui_title_transition_target->x += transition_resolution;
            gui_lock_double_buffer();
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
            _show_bitmap(
                (g_gui_title_transition_target->x + g_gui_title_transition_target->width),
                g_gui_title_transition_target->y,
                &g_title_bitmap_for_transition);
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
            gui_title_show(g_gui_title_transition_target, GUI_TITLE_PART_ALL);
            gui_unlock_double_buffer();
            gdi_layer_blt_previous(
                g_gui_title_transition_target->prev_title_x,
                g_gui_title_transition_target->y,
                g_gui_title_transition_target->prev_title_x + g_gui_title_transition_target->width,
                g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
            if ((g_gui_title_transition_target->x + transition_resolution) < 0)
            {
                gui_start_timer(TITLE_TRANSITION_NON_BLOCKING_TIMER, gui_title_show_transition_non_blocking);
            }
            else
            {
            #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
                if (g_title_prev_menu_shortcut != -1)
                {
                    g_title_prev_menu_shortcut = -1;
                }
            #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */ 
                gui_title_stop_transition_non_blocking(g_gui_title_transition_target);
                gdi_layer_blt_previous(
                    g_gui_title_transition_target->x,
                    g_gui_title_transition_target->y,
                    g_gui_title_transition_target->x + g_gui_title_transition_target->width,
                    g_gui_title_transition_target->y + g_gui_title_transition_target->height - 1);
            }
            break;
        }
    }

}

#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 

#endif /* __MMI_UI_TITLE_TRANSITION__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_scrolling_background
 * DESCRIPTION
 *  Fill the title bar with default color when text is scrolling
 * PARAMETERS
 *  x1      [IN]        Left-top x,y position of title bar
 *  y1      [IN]        Left-top x,y position of title bar
 *  x2      [IN]        Right-bottom x,y position of title bar
 *  y2      [IN]        Right-bottom x,y position of title bar
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_scrolling_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_title_show_background(g_gui_title_current_scrolling_target, x1, y1, x2 - x1 + 1, y2 - y1 + 1);
    gui_pop_clip();

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_scrolling_timer_callback
 * DESCRIPTION
 *  scrolling title bat timer callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_scrolling_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_gui_title_current_scrolling_target->scrolling_text);
}

/*****************************************************************************
 * FUNCTION
 *  gui_title_show_scrolling_ex
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_scrolling_ex(void)
{
    gui_title_show_scrolling(&g_wgui_title_bar);
    gdi_layer_blt_previous(
        g_wgui_title_bar.x,
        g_wgui_title_bar.y,
        g_wgui_title_bar.x + g_wgui_title_bar.width - 1,
        g_wgui_title_bar.y + g_wgui_title_bar.height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  gui_title_show_scrolling
 * DESCRIPTION
 *  Show scrolling title on title bar
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_scrolling(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 width = 0, height, tw = 0, th = 0, width2 = 0, height2 = 0;
    S32 w1 = 0, w2 = 0, h1 = 0, h2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(t->style & GUI_TITLE_STYLE_SCROLLING))
    {
        return;
    }

    gui_lock_double_buffer();
    gui_push_clip();
    gui_reset_clip();
    gui_set_clip(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);

    gui_title_show_background(t, t->x, t->y, t->width, t->height);

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE   
    wgui_status_icon_integrated_register_redraw(gui_title_show_scrolling_ex);
    wgui_status_icon_integrated_get_area(STATUS_ICON_SIGNAL_STRENGTH, &w1, &h1);
    wgui_status_icon_integrated_get_area(STATUS_ICON_BATTERY_STRENGTH, &w2, &h2);
    wgui_status_icon_integrated_show(STATUS_ICON_SIGNAL_STRENGTH, t->x, t->y + t->height - h1);
    wgui_status_icon_integrated_show(STATUS_ICON_BATTERY_STRENGTH, t->x + t->width - w2, t->y + t->height - h2);
    if (!r2lMMIFlag)
    {
        gui_shortcut_move(&t->sc, t->width - t->sc.width - w1, t->sc.y);
    }
    else
    {
        gui_shortcut_move(&t->sc, w2, t->sc.y);
    }
#endif


    if (t->icon != NULL)
    {
        x1 = t->x + t->scrolling_icon_x + w1;
        y1 = t->y + t->scrolling_icon_y;
        x2 = x1 + t->width - 1;
        y2 = y1 + (t->y + t->height) - 1;
        gui_set_clip(x1, y1, x2, y2);
        gui_measure_image(t->icon, &width, &height);

        /* for R2L characters */
        if (!r2lMMIFlag)
        {
            gui_show_transparent_image(
                x1,
                y1,
                t->icon,
                gui_transparent_color(0, 0, 0));
            if ((width == 0) || (height == 0))
            {
                t->scrolling_text.x = GUI_TITLE_NON_ICON_GAP + w1;
            }
            else
            {
                t->scrolling_text.x = width + GUI_TITLE_ICON_GAP + w1;
            }

        }
        else
        {
            gui_show_transparent_image(
                t->width - width - 1 - w2,
                t->y + t->scrolling_icon_y,
                t->icon,
                gui_transparent_color(0, 0, 0));
            if ((width == 0) || (height == 0))
            {
                t->scrolling_text.x = t->width - GUI_TITLE_NON_ICON_GAP - w2;
            }
            else
            {
                t->scrolling_text.x = t->width - width - GUI_TITLE_ICON_GAP - w2;
            }

        }
    }
    else
    {
        /* for R2L characters */
        if (!r2lMMIFlag)
        {
            t->scrolling_text.x = GUI_TITLE_NON_ICON_GAP + w1;
        }
        else
        {
            t->scrolling_text.x = t->width - GUI_TITLE_NON_ICON_GAP - w2;
        }
    }

    if (t->icon2 != NULL)
    {
        x1 = t->x + t->scrolling_icon_x + w1;
        y1 = t->y + t->scrolling_icon_y;
        x2 = x1 + t->width - 1;
        y2 = y1 + (t->y + t->height) - 1;
        gui_set_clip(x1, y1, x2, y2);
        gui_measure_image(t->icon2, &width2, &height2);

        /* for R2L characters */
        if (!r2lMMIFlag)
        {
            gui_show_transparent_image(
                t->x + t->width - width2 - t->scrolling_icon_x - w2,
                t->y + t->scrolling_icon_y,
                t->icon2,
                gui_transparent_color(0, 0, 0));

        }
        else
        {
            gui_show_transparent_image(
                t->x + t->scrolling_icon_x + w1,
                t->y + t->scrolling_icon_y,
                t->icon2,
                gui_transparent_color(0, 0, 0));

        }
    }

    if (mmi_ucs2strlen((const S8*)t->text) != 0)
    {
        gui_measure_string(t->scrolling_text.text, &tw, &th);
        if (t->icon2)
        {
            t->scrolling_text.width = t->width - width2 - width - GUI_TITLE_SCROLLING_GAP;      /* 110906 scrolling title: reserve 2 pixels on each side for border */
        }
        else if (gui_shortcut_is_show(&t->sc) && t->no_icon_shct == MMI_TRUE)
        {
            t->scrolling_text.width = t->width - gui_shortcut_get_width(&t->sc) - width - GUI_TITLE_SCROLLING_GAP;      /* 110906 scrolling title: reserve 2 pixels on each side for border */
        }
        else
        {
            t->scrolling_text.width = t->width - width - GUI_TITLE_SCROLLING_GAP;
        }
        t->scrolling_text.width -= w1 + w2;
        /* 2L characters */
        if (r2lMMIFlag)
        {
            if (tw < t->scrolling_text.width)
            {
                //t->scrolling_text.x = ((t->width - tw) >> 1) + tw - t->scrolling_text.width;
                t->scrolling_text.x = t->width - ((t->scrolling_text.width - tw)>>1) - w1 - width - tw;
                t->scrolling_text.width = tw;
            }
        }
        else
        {
            //if (((t->width - tw) >> 1) > t->scrolling_text.x)//110906 scrolling title
            //{
            //    t->scrolling_text.x = (t->width - tw) >> 1;
            //}
            if (tw < t->scrolling_text.width)
            {
                t->scrolling_text.x += ((t->scrolling_text.width - tw) >> 1);
                t->scrolling_text.width = tw;
            }
        }

        gui_show_scrolling_text(&t->scrolling_text);
    }
    if (t->icon2 == NULL)
    {
        if (t->no_icon_shct == MMI_FALSE)
        {
            MMI_disable_title_shortcut_display = 1;
            t->sc.display_enabled = 1;
            disable_menu_shortcut_box_display = 1;
        }
        gui_shortcut_show(&t->sc);
    }
    gui_pop_clip();
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(t->x, t->y, t->x + t->width - 1, t->y + t->height - 1);
}

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__


/*****************************************************************************
 * FUNCTION
 *  gui_title_animate_image
 * DESCRIPTION
 *  Call draw title & set reset the next frame variable to check, Internal & external call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_animate_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_title_current_animation_target->next_frame = MMI_TRUE;
    gui_lock_double_buffer();
    if (g_gui_title_current_animation_target)
    {
        gui_title_show(g_gui_title_current_animation_target, GUI_TITLE_PART_ALL);
        /* wgui_title_show(GUI_TITLE_PART_ALL); */
    }
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(
        g_gui_title_current_animation_target->x,
        g_gui_title_current_animation_target->y,
        g_gui_title_current_animation_target->x + g_gui_title_current_animation_target->width - 1,
        g_gui_title_current_animation_target->y + g_gui_title_current_animation_target->height - 1);
    g_gui_title_current_animation_target->next_frame = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_animate_image
 * DESCRIPTION
 *  Displays the moving image for moving title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x1      [IN]            
 *  y1      [IN]            
 *  x2      [IN]            
 *  y2      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_title_show_animate_image(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, no_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    gui_measure_image(get_image(IMG_TITLE_SCROLL), &iwidth, &iheight);
    if (iheight < y2 - y1)
    {
        y1 = y1 + (((y2 - y1 + 1) - iheight) >> 1);
    }
    no_frame = gui_image_n_frames(get_image(IMG_TITLE_SCROLL));
    if (no_frame == 1)
    {
        gui_show_image(x1 + t->animate_move, y1, get_image(IMG_TITLE_SCROLL));
        if ((t->animate_move >= x2) && t->animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_CONTINOUS)
        {
            t->animate_move = t->animate_move - x2 - iwidth;
        }
        else
        {
            t->animate_move = t->animate_move + SHIFT_TITLE_IMAGE;
        }
        gui_start_timer(GUI_TITLE_IMAGE_ANIMATION_TIMER, gui_title_animate_image);
    }
    else
    {
        gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), 0);
        if (t->current_frame_count != 0)
        {
            gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), (S16) t->current_frame_count);   /* Show frame by frame no. */
        }
        if (t->current_frame_count == no_frame)
        {
            t->current_frame_count = -1;
        }
        gui_start_timer(GUI_TITLE_IMAGE_ANIMATION_TIMER, gui_title_animate_image);
        if (t->animated_style == MMI_UI_TITLE_IMAGE_ANIMATE_ONCE && t->current_frame_count == -1)
        {
            return;
        }
        t->current_frame_count++;
    }
    t->backup_frame_count = t->current_frame_count;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_show_animate_image_frame_0
 * DESCRIPTION
 *  Displays the first frame of moving image for moving title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x1      [IN]            
 *  y1      [IN]            
 *  x2      [IN]            
 *  y2      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_show_animate_image_frame_0(gui_title_struct *t, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, no_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    UI_UNUSED_PARAMETER(x2);
    gui_measure_image(get_image(IMG_TITLE_SCROLL), &iwidth, &iheight);
    if (iheight < y2 - y1)
    {
        y1 = y1 + (((y2 - y1 + 1) - iheight) >> 1);
    }
    no_frame = gui_image_n_frames(get_image(IMG_TITLE_SCROLL));
    if (no_frame == 1)
    {
        gui_show_image(x1 + t->animate_move, y1, get_image(IMG_TITLE_SCROLL));
    }
    else if (no_frame > 1)
    {
        gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), 0);
        if (t->current_frame_count != -1 && (t->backup_frame_count != -1 && t->backup_frame_count != 0))
        {
            gui_show_animated_image_frame(x1, y1, get_image(IMG_TITLE_SCROLL), (S16) (t->backup_frame_count - 1));
        }
    }
}
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 



/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/
#ifdef __MMI_UI_TITLE_TRANSITION__


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_transition
 * DESCRIPTION
 *  This functions sets the transition style for title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]            The style in which the title should transiate R2L or L2R
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_transition(gui_title_struct *t, gui_title_transition_enum style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->transition_style = style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_transition
 * DESCRIPTION
 *  This functions get the transition style for title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  the style of title transition
 *****************************************************************************/
gui_title_transition_enum gui_title_get_transition(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->transition_style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_transition_on_keys
 * DESCRIPTION
 *  This functions sets the transition style for title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  onkey       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_transition_on_keys(gui_title_struct *t, MMI_BOOL onkey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->transition_on_keys = onkey;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_transition_on_keys
 * DESCRIPTION
 *  This functions gets the transition style for title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_get_transition_on_keys(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->transition_on_keys;
}

#endif /* __MMI_UI_TITLE_TRANSITION__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_title_show
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  part        [IN]            Part ID of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_show(gui_title_struct *t, U32 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    if (t->next_frame == MMI_FALSE && gui_title_is_animation_enabled(t))
    {
        gui_title_stop_animation(t);
    }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 
    if (t->style & GUI_TITLE_STYLE_SCROLLING)   /*  */
    {
        gui_title_show_scrolling(t);
    }
    else
    {
        bitblt = gui_title_show_normal(t, part);
    }
    return bitblt;

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_move
 * DESCRIPTION
 *  move title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]            
 *  y       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_move(gui_title_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_resize
 * DESCRIPTION
 *  resize title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  width       [IN]            
 *  height      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_resize(gui_title_struct *t, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->width = width;
    t->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_change
 * DESCRIPTION
 *  change title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  icon        [IN]            Left icon
 *  icon2       [IN]            Right icon
 *  text        [IN]            Text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_change(gui_title_struct *t, PU8 icon, PU8 icon2, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_TITLE_TRANSITION__
    t->prev_icon = t->icon;
    mmi_ucs2ncpy((S8*) t->prev_text, (S8*) t->text, GUI_TITLE_MAX_LENGTH);
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 
    if (text)
    {
        mmi_ucs2ncpy((S8*) t->text, (S8*) text, GUI_TITLE_MAX_LENGTH);
    }
    else
    {
        t->text[0] = 0;
        t->text[1] = 0;
    }
    t->icon = icon;
    t->icon2 = icon2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_create
 * DESCRIPTION
 *  create title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  x           [IN]            
 *  y           [IN]            
 *  wdith       [IN]            
 *  height      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_create(gui_title_struct *t, S32 x, S32 y, S32 wdith, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
    t->width = wdith;
    t->height = height;
    t->style = GUI_TITLE_STYLE_NORMAL;
    gui_title_set_current_theme(t);
    gui_title_show_normal = gui_title_oem_show_normal;
    gui_title_show_background = gui_title_oem_show_background;
#ifdef __MMI_TITLE_BAR_NO_ICON_SHCT__
    t->no_icon_shct = MMI_FALSE;
#else /*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
    t->no_icon_shct = MMI_TRUE;
#endif  /*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    gui_title_enable_animation(t, MMI_TRUE);
    g_gui_title_current_animation_target = t;
    t->animated_style = GUI_TITLE_EFFECT_TYPE(__MMI_UI_ANIMATED_TITLE_EFFECT__);
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_style
 * DESCRIPTION
 *  set title style
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_style(gui_title_struct *t, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->style = t->style | style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_unset_style
 * DESCRIPTION
 *  set title style for show icon
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_unset_style(gui_title_struct *t, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->style = t->style & ~style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_no_icon_shct
 * DESCRIPTION
 *  set title style for show icon
 * PARAMETERS
 *  t                   [IN/OUT]        Is the struct of title
 *  no_icon_shct        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_no_icon_shct(gui_title_struct *t, MMI_BOOL no_icon_shct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->no_icon_shct = no_icon_shct;
}

#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__


/*****************************************************************************
 * FUNCTION
 *  gui_title_start_animation
 * DESCRIPTION
 *  start timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_start_animation(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(GUI_TITLE_IMAGE_ANIMATION_TIMER, gui_title_animate_image);
    g_gui_title_current_animation_target = t;

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_stop_animation
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_stop_animation(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    t->animate_move = 0;
    t->backup_frame_count = t->current_frame_count;
    t->current_frame_count = 0;
    gui_cancel_timer(gui_title_animate_image);

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_enable_animation
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  enable_animation        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_enable_animation(gui_title_struct *t, MMI_BOOL enable_animation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->enable_animtion = enable_animation;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_animation_enabled
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_is_animation_enabled(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->enable_animtion;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_unset_animation_style
 * DESCRIPTION
 *  unset animation style
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_unset_animation_style(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->animated_style = GUI_TITLE_EFFECT_TYPE(__MMI_UI_ANIMATED_TITLE_EFFECT__);
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_animation_style
 * DESCRIPTION
 *  unset animation style
 * PARAMETERS
 *  t                   [IN/OUT]        Is the struct of title
 *  animated_style      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_animation_style(gui_title_struct *t, gui_title_effect_styles animated_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->animated_style = animated_style;
}

#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_title_start_scrolling
 * DESCRIPTION
 *  start scrolling
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_start_scrolling(gui_title_struct *t)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iwidth, iheight, character_height, tx, tw, w;
    S32 scrolling_title_icon_width = GUI_TITLE_SCROLLING_INIT_WIDTH;
    S32 scrolling_title_icon_height = GUI_TITLE_SCROLLING_INIT_HEIGHT;
    S32 scrolling_title_text_x;
    S32 scrolling_title_text_y;
    S32 scrolling_title_text_width;
    S32 scrolling_title_text_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->scrolling_icon_x = GUI_TITLE_SCROLLING_INIT_X;
    t->scrolling_icon_y = GUI_TITLE_SCROLLING_INIT_X;
    if (t->icon != NULL)
    {
        gui_measure_image(t->icon, &iwidth, &iheight);
        scrolling_title_icon_width = iwidth;
        scrolling_title_icon_height = iheight;
        if (scrolling_title_icon_width > (t->y + t->height))
        {
            scrolling_title_icon_width = (t->y + t->height);
        }
        if (scrolling_title_icon_height > (t->y + t->height))
        {
            scrolling_title_icon_height = (t->y + t->height);
        }
        t->scrolling_icon_y = ((t->height - scrolling_title_icon_height) >> 1);
        t->scrolling_icon_x = GUI_TITLE_SCROLLING_ICON_X;
    }
    if (mmi_ucs2strlen((const S8*)t->text) != 0)
    {
        scrolling_title_text_x = t->scrolling_icon_x + scrolling_title_icon_width + GUI_TITLE_ICON_GAP;
        gui_set_font(t->normal_font);
        gui_measure_string((UI_string_type) t->text, &w, &character_height);
        tx = scrolling_title_text_x;
        scrolling_title_text_y = t->y + (t->height >> 1) - (character_height >> 1);
        tw = t->width - tx;
        gui_set_text_color(t->text_color);
        gui_move_text_cursor(t->x + tx, t->y + ((t->height >> 1) - (character_height >> 1)));
        if (w < tw)
        {
            S32 _tx = tx;

            tx = (t->width >> 1) - (w >> 1);
            if (tx < _tx)
            {
                tx = _tx;
            }
        }
        tw = t->width - tx - GUI_TITLE_TEXT_GAP;
        scrolling_title_text_width = tw;
        scrolling_title_text_height = character_height;
        scrolling_title_text_x = tx;
        gui_create_scrolling_text(
            &t->scrolling_text,
            scrolling_title_text_x,
            scrolling_title_text_y,
            scrolling_title_text_width,
            scrolling_title_text_height,
            (UI_string_type) t->text,
            gui_title_scrolling_timer_callback,
            gui_title_show_scrolling_background,
            t->text_color,
            t->text_border_color);
        g_gui_title_current_scrolling_target = t;
        t->scrolling_text.scroll_pause <<= 1;
        t->scrolling_text.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
        t->scrolling_text.text_color = t->text_color;
        t->scrolling_text.text_border_color = t->text_border_color;

    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_stop_scrolling
 * DESCRIPTION
 *  stop scrolling
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_stop_scrolling(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(t);
    gui_cancel_timer(gui_title_scrolling_timer_callback);

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_theme
 * DESCRIPTION
 *  set the specify theme
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  th      [IN]            Specify theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_theme(gui_title_struct *t, UI_window_title_theme *th)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        t->active_filler = current_MMI_theme->rotated_title_filler;
    }
    else
#endif
    {
        t->active_filler = th->active_filler;
    }
    t->normal_font = th->text_font;
    t->active_font = th->text_font;
    t->text_color = th->active_text_color;
    t->text_border_color = th->text_border_color;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_current_theme
 * DESCRIPTION
 *  set current theme
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_current_theme(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_set_theme(t, current_window_title_theme);

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_register_callback
 * DESCRIPTION
 *  register the callback function of pre_goto and goto
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  pre_goto_funcptr        [IN]            
 *  goto_funcptr            [IN]            
 *  flag                    [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_register_callback(
        gui_title_struct *t,
        void (*pre_goto_funcptr) (S32 i),
        void (*goto_funcptr) (S32 i),
        U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO)
    {
        t->pre_goto_callback = pre_goto_funcptr;
    }
    if (flag & WGUI_TITLE_SHORTCUT_CHANGE_GOTO)
    {
        t->goto_callback = goto_funcptr;
    }

}

