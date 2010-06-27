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
 * Filename:
 * ---------
 *  gui_panel.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Panel - UI component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

 
#include "MMI_features.h"
#include "gui_panel.h"
#include "DebugInitDef.h"
#include "gdi_include.h"
#include "GlobalConstants.h"
#include "KeyBrd.h"

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/
/* Current active panel on Pen Down or Key Down */
static gui_panel_struct *g_curr_active_panel;


/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_panel_show_element
 * DESCRIPTION
 *  Draw a painter element
 * PARAMETERS
 *  panel                   [IN/OUT]    panel
 *  element                 [IN]        panel element
 *  state                   [IN]        state of panel element 
 *  bg_is_already_drawn     [IN]        whether the panel background is already drawn.
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_panel_show_element(
                gui_panel_struct *panel, 
                gui_panel_element_struct *element, 
                gui_panel_elem_state_enum state,
                MMI_BOOL bg_is_already_drawn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    if (!bg_is_already_drawn && element->redraw_bg_after_state_changed)
    {
        gui_util_painter_show_clipped(
            &panel->background,
            panel->x,
            panel->y,
            element->x1,
            element->y1,
            element->x2,
            element->y2);
    }
    
    gui_util_painter_show(
        &element->painters[state],
        element->x1,
        element->y1,
        element->x2,
        element->y2);

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(element->x1, element->y1, element->x2, element->y2);
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_repeat_timer
 * DESCRIPTION
 *  Timer handler for repeat events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_panel_repeat_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_panel_element_struct *e;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_curr_active_panel)
    {
        return;
    }
    e = &g_curr_active_panel->elements[g_curr_active_panel->element_focus_index];
    /* Upper applications may use GetKeyInfo() to detect the event, 
       though it's not a good design */
    SetkeyInfo(e->keycode, KEY_EVENT_REPEAT);    
    e->repeat_event_callback();
    gui_start_timer(g_curr_active_panel->repeat_period, gui_panel_repeat_timer);
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_reset_state
 * DESCRIPTION
 *  Reset the current panel status when screen exits.
 *  Note: screen may have more than one panels at the same time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_panel_reset_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Avoid Repeat Event happening in gui_panel_repeat_timer() after screen exits.
       Note: MMI framework may send Key Down and Key Up in two screens separately. */
       
    g_curr_active_panel = NULL;
}

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_panel_create
 * DESCRIPTION
 *  Create a panel component
 *
 *  Note: the parameter 'display_focus' decides whether there is a focussed element.
 *  For example, audio player has a focussed button (Play, Stop), but dialing screen
 *  does not have a focussed button.
 * PARAMETERS
 *  panel                   [OUT]       panel
 *  x                       [IN]        
 *  y                       [IN]         
 *  width                   [IN]
 *  height                  [IN]
 *  background              [IN]        panel background painter
 *  display_focus           [IN]        whether to display focussed element differently
 *  repeat_period           [IN]        period of repeat events in milliseconds (0 for default)
 * RETURNS
 *  void
 *****************************************************************************/
void gui_panel_create(
        gui_panel_struct *panel,
        S32 x, 
        S32 y, 
        S32 width, 
        S32 height, 
        gui_util_painter_struct background,
        MMI_BOOL display_focus,
        U32 repeat_period)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(panel, 0, sizeof(gui_panel_struct));
    panel->x = x;
    panel->y = y;
    panel->width = width;
    panel->height = height;
    panel->background = background;
    panel->display_focus = display_focus ? 1 : 0;
    if (repeat_period)
    {
        panel->repeat_period = repeat_period;
    }
    else
    {
        panel->repeat_period = GUI_PANEL_DEFAULT_REPEAT_PERIOD;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_show
 * DESCRIPTION
 *  Show a panel component
 * PARAMETERS
 *  panel           [IN/OUT]        panel
 * RETURNS
 *  void
 *****************************************************************************/
void gui_panel_show(gui_panel_struct *panel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    S32 elem_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = panel->x;
    y1 = panel->y;
    x2 = panel->x + panel->width - 1;
    y2 = panel->y + panel->height - 1;
    
    gui_lock_double_buffer();
    
    gui_util_painter_show(&panel->background, x1, y1, x2, y2);

    for (elem_idx = 0; elem_idx < panel->element_count; elem_idx++)
    {
        gui_panel_element_struct *e = &panel->elements[elem_idx];
        gui_panel_elem_state_enum state;
        if (e->disabled_state)
        {
            state = GUI_PANEL_ELEM_STATE_DISABLED;
        }
        else if (e->down_state)
        {
            state = GUI_PANEL_ELEM_STATE_DOWN;
        }
        else if (panel->display_focus && elem_idx == panel->element_focus_index)
        {
            state = GUI_PANEL_ELEM_STATE_FOCUSSED;
        }
        else
        {
            state = GUI_PANEL_ELEM_STATE_NORMAL;
        }
        
        gui_util_painter_show(&e->painters[state], e->x1, e->y1, e->x2, e->y2);
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);

    /* Add cleanup handler */
    gui_add_cleanup_hook(gui_panel_reset_state);
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_set_element_focus
 * DESCRIPTION
 *  Set the foccused element
 * PARAMETERS
 *  panel                   [IN/OUT]    panel
 *  element_index           [IN]        element index to be focussed
 *  update_display          [IN]        whether to update the display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_panel_set_element_focus(
        gui_panel_struct *panel,
        S32 element_index,
        MMI_BOOL update_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_index >= 0 && element_index < panel->element_count &&
        element_index != panel->element_focus_index)
    {
        if (update_display)
        {
            if (panel->display_focus)
            {
                gui_panel_show_element(
                    panel, 
                    &panel->elements[panel->element_focus_index], 
                    GUI_PANEL_ELEM_STATE_NORMAL,
                    MMI_FALSE);
            }
            
            gui_panel_show_element(
                panel, 
                &panel->elements[element_index], 
                panel->display_focus ? GUI_PANEL_ELEM_STATE_FOCUSSED : GUI_PANEL_ELEM_STATE_NORMAL,
                MMI_FALSE);
        }
        
        panel->element_focus_index = element_index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_get_element_focus
 * DESCRIPTION
 *  Get the index of foccused element
 * PARAMETERS
 *  panel                   [IN]    panel
 * RETURNS
 *  Index of focused element
 *****************************************************************************/
S32 gui_panel_get_element_focus(gui_panel_struct *panel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return panel->element_focus_index;
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_add_element
 * DESCRIPTION
 *  Set the foccused element
 * 
 *  Note: If 'redraw_bg_after_state_changed' is 1, it typically has worse performance.
 *  It is usually used when painter is partially-transparent.
 *  If art designer can create images carefully (put the background into element image), then
 *  we can set redraw_bg_after_state_changed as 0.
 * PARAMETERS
 *  panel                           [IN/OUT]    panel
 *  x                               [IN]        x
 *  y                               [IN]        y
 *  width                           [IN]        width
 *  height                          [IN]        height
 *  keycode                         [IN]        registered key event (KEY_INVALID if no key event registered)
 *  down_event_callback             [IN]        callback when key/pen down
 *  up_event_callback               [IN]        callback when key/pen up
 *  repeat_event_callback           [IN]        callback when key stays pressed or pen stays on element
 *  normal_painter                  [IN]        painter when up 
 *  down_painter                    [IN]        painter when down
 *  focussed_painter                [IN]        painter when focussed. Only used when panel->display_focus is 1.
 *  redraw_bg_after_state_changed   [IN]        redrawn panel background when pressed/released/focussed/unfocussed
 * RETURNS
 *  The element index. -1 if failed
 *****************************************************************************/
S32 gui_panel_add_element(
        gui_panel_struct *panel,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U16 keycode,
        FuncPtr down_event_callback,
        FuncPtr up_event_callback,
        FuncPtr repeat_event_callback,
        gui_util_painter_struct normal_painter,
        gui_util_painter_struct down_painter,
        gui_util_painter_struct focussed_painter,
        gui_util_painter_struct disabled_painter,        
        MMI_BOOL redraw_bg_after_state_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_panel_element_struct *e;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (panel->element_count == GUI_PANEL_MAX_ELEMENT_COUNT)
    {
        MMI_DBG_ASSERT(0);
        return -1;
    }

    e = &panel->elements[panel->element_count];

    e->x1 = x;
    e->y1 = y;
    e->x2 = x + width - 1;
    e->y2 = y + height - 1;
    e->keycode = keycode;
    e->down_event_callback = down_event_callback ? down_event_callback : UI_dummy_function;
    e->up_event_callback = up_event_callback ? up_event_callback : UI_dummy_function;
    e->repeat_event_callback = repeat_event_callback ? repeat_event_callback : UI_dummy_function;
    e->painters[GUI_PANEL_ELEM_STATE_NORMAL] = normal_painter;
    e->painters[GUI_PANEL_ELEM_STATE_DOWN] = down_painter;
    e->painters[GUI_PANEL_ELEM_STATE_FOCUSSED] = focussed_painter;
    e->painters[GUI_PANEL_ELEM_STATE_DISABLED] = disabled_painter;
    e->down_state = 0;
    e->disabled_state = 0;
    e->redraw_bg_after_state_changed = redraw_bg_after_state_changed ? 1 : 0;

    return panel->element_count++;
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_enable_element
 * DESCRIPTION
 *  Enable/disable an element
 * PARAMETERS
 *  panel                   [IN/OUT]    panel
 *  elem_idx                [IN]        element index to be focussed
 *  enabled                 [IN]        If false, disable the element
 *  update_display          [IN]        whether to update the display
 * RETURNS
 *  void
 *****************************************************************************/
void gui_panel_enable_element(
            gui_panel_struct *panel,
            S32 elem_idx,
            MMI_BOOL enabled,
            MMI_BOOL update_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_panel_element_struct *e;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (elem_idx >= 0 && elem_idx < panel->element_count)
    {
        e = &panel->elements[elem_idx];

        /* This API does not work for focussed or pressed element */
        MMI_DBG_ASSERT(!e->down_state && elem_idx != panel->element_focus_index);

        if (enabled)
        {
            e->disabled_state = 0;
        }
        else
        {
            e->disabled_state = 1;
        }

        if (update_display)
        {            
            gui_panel_show_element(
                panel, 
                e, 
                enabled ? GUI_PANEL_ELEM_STATE_NORMAL : GUI_PANEL_ELEM_STATE_DISABLED,
                MMI_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_panel_general_key_handler
 * DESCRIPTION
 *  General key handler for panel elements
 * PARAMETERS
 *  panel                   [IN/OUT]    panel
 *  keycode                 [IN]        key code
 *  state                   [IN]        key type
 * RETURNS
 *  void
 *****************************************************************************/
void gui_panel_general_key_handler(gui_panel_struct *panel, U16 keycode, U16 keytype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < panel->element_count; i++)
    {
        gui_panel_element_struct *e = &panel->elements[i];
        if (e->keycode == keycode)
        {
        
            if (e->disabled_state)
            {
                continue;
            }
            
            switch (keytype)
            {
                case KEY_EVENT_DOWN:
                    if (panel->element_focus_index != i && panel->display_focus)
                    {
                        gui_panel_show_element(
                            panel, 
                            &panel->elements[panel->element_focus_index], 
                            GUI_PANEL_ELEM_STATE_NORMAL,
                            MMI_FALSE);
                    }

                    panel->element_focus_index = i;
                    gui_panel_show_element(
                        panel, 
                        e, 
                        GUI_PANEL_ELEM_STATE_DOWN,
                        MMI_FALSE);
                    e->down_state = 1;

                    /* Invoke callback */                    
                    e->down_event_callback();
                    
                    /* repeat timer */
                    g_curr_active_panel = panel;
                    gui_start_timer(panel->repeat_period, gui_panel_repeat_timer);
                    break;
                    
                case KEY_EVENT_UP:
                    gui_panel_show_element(
                        panel, 
                        e, 
                        panel->display_focus ? GUI_PANEL_ELEM_STATE_FOCUSSED : GUI_PANEL_ELEM_STATE_NORMAL,
                        MMI_FALSE);
                    
                    /* Invoke callback */
                    if (e->down_state == 1)
                    {
                        e->up_event_callback();
                    }
                    e->down_state = 0;

                    /* repeat timer */
                    g_curr_active_panel = NULL;
                    gui_cancel_timer(gui_panel_repeat_timer);
                    break;
                    
                default:
                    break;
            }
            
            break;
        }
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_panel_translate_pen_event
 * DESCRIPTION
 *  Pen event handler in GUI panel component
 * PARAMETERS
 *  panel           [IN/OUT]         
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  MMI_TRUE if the pen event is handled by panel.
 *  If pen_event != MMI_PEN_EVENT_DOWN, always return MMI_TRUE.
 *****************************************************************************/
MMI_BOOL gui_panel_translate_pen_event(
            gui_panel_struct *panel,
            mmi_pen_event_type_enum pen_event,
            S16 x,
            S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!panel || panel->element_count <= 0)
    {
        return MMI_FALSE;
    }

    /* Return true by default except for Pen Down */
    ret = MMI_TRUE;
    
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            ret = MMI_FALSE;
            panel->element_pen_down_index = -1;
            
            for (i = 0; i < panel->element_count; i++)
            {
                gui_panel_element_struct *e = &panel->elements[i];

                if (e->disabled_state)
                {
                    continue;
                }

                if (PEN_CHECK_BOUND(x, y, e->x1, e->y1, e->x2 - e->x1 + 1, e->y2 - e->y1 + 1))
                {
                    ret = MMI_TRUE;
                
                    if (panel->element_focus_index != i && panel->display_focus)
                    {
                        gui_panel_show_element(
                            panel, 
                            &panel->elements[panel->element_focus_index], 
                            GUI_PANEL_ELEM_STATE_NORMAL,
                            MMI_FALSE);
                    }
                    
                    panel->element_pen_down_index = i;
                    panel->element_focus_index = i;
                    gui_panel_show_element(panel, e, GUI_PANEL_ELEM_STATE_DOWN, MMI_FALSE);
                    e->down_state = 1;

                    /* Upper applications may use GetKeyInfo() to detect the event, 
                       though it's not a good design */
                    SetkeyInfo(e->keycode, KEY_EVENT_DOWN);
                    /* Invoke callback */                    
                    e->down_event_callback();

                    /* repeat timer */
                    g_curr_active_panel = panel;
                    gui_start_timer(panel->repeat_period, gui_panel_repeat_timer);
                    
                    break;
                }
            }
            break;

        case MMI_PEN_EVENT_UP:
            if (g_curr_active_panel == panel && panel->element_pen_down_index >= 0)
            {
                gui_panel_element_struct *e = &panel->elements[panel->element_pen_down_index];

                if (e->down_state) /* If pen was inside the region */
                {            
                    gui_panel_show_element(
                        panel, 
                        e, 
                        panel->display_focus ? GUI_PANEL_ELEM_STATE_FOCUSSED : GUI_PANEL_ELEM_STATE_NORMAL,
                        MMI_FALSE);
                    
                    e->down_state = 0;
                }

                /* Upper applications may use GetKeyInfo() to detect the event, 
                   though it's not a good design */
                SetkeyInfo(e->keycode, KEY_EVENT_UP);
                /* Invoke callback no matter pen was inside the element or not */
                e->up_event_callback();

                /* repeat timer */
                g_curr_active_panel = NULL;
                gui_cancel_timer(gui_panel_repeat_timer);
            }

            break;

        case MMI_PEN_EVENT_MOVE:
            if (g_curr_active_panel == panel && panel->element_pen_down_index >= 0)
            {
                gui_panel_element_struct *e = &panel->elements[panel->element_pen_down_index];
                MMI_BOOL point_inside = PEN_CHECK_BOUND(x, y, e->x1, e->y1, e->x2 - e->x1 + 1, e->y2 - e->y1 + 1);
                
                if (e->down_state && !point_inside) /* If pen was inside the region */
                {            
                    gui_panel_show_element(
                        panel, 
                        e, 
                        panel->display_focus ? GUI_PANEL_ELEM_STATE_FOCUSSED : GUI_PANEL_ELEM_STATE_NORMAL,
                        MMI_FALSE);
                    
                    e->down_state = 0;
                    gui_cancel_timer(gui_panel_repeat_timer);
                }
                else if (!e->down_state && point_inside)
                {
                    gui_panel_show_element(
                        panel, 
                        e, 
                        panel->display_focus ? GUI_PANEL_ELEM_STATE_FOCUSSED : GUI_PANEL_ELEM_STATE_NORMAL,
                        MMI_FALSE);
                    
                    e->down_state = 1;        
                    gui_start_timer(panel->repeat_period, gui_panel_repeat_timer);
                }
            }
            break;

        case MMI_PEN_EVENT_LONG_TAP:
        case MMI_PEN_EVENT_REPEAT:
            break;

        case MMI_PEN_EVENT_ABORT:
            g_curr_active_panel = NULL;
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}

#endif/* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_panel_set_element_image_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  panel                   [IN/OUT]    panel
 * RETURNS
 *  void
 *****************************************************************************/
void gui_panel_set_element_image_id(
        gui_panel_struct *panel,
        S32 element_index,
        gui_panel_elem_state_enum state,
        MMI_ID_TYPE image_id)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_index >= 0 && element_index < panel->element_count)
    {
        if (state >= GUI_PANEL_ELEM_STATE_NORMAL && state < GUI_PANEL_ELEM_STATE_TOTAL)
        {
            panel->elements[element_index].painters[state].type = GUI_UTIL_PAINTER_TYPE_IMAGEID;
            panel->elements[element_index].painters[state]._u.imageid = image_id;
        }
    }
}


