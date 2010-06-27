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
 *   gui_windows.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Miscellaneous UI components. 
 *
 *   [Popup description]
 *   [Scrolling text]
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "gui_windows.h"
#include "gui_themes.h"

#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "kal_non_specific_general_types.h"

#include "FS_Type.h"
#include "gdi_include.h"
#include "gdi_image_gif.h"

#include "DebugInitDef.h"
#include "wgui.h"
#include "wgui_categories_MM.h"

#include "wgui_hint_pre_oem.h"
#include "wgui_hint_post_oem.h"

extern BOOL r2lMMIFlag;

/* GUI: Pop up description functions         */

S32 UI_pop_up_description_scroll_time = UI_TEXT_MENUITEM_SCROLL_TIME;
S32 UI_pop_up_description_scroll_size = UI_TEXT_MENUITEM_SCROLL_SIZE;
S32 UI_pop_up_description_scroll_gap = UI_TEXT_MENUITEM_SCROLL_GAP;
S32 UI_pop_up_description_scroll_pause = UI_TEXT_MENUITEM_SCROLL_PAUSE;

UI_pop_up_description_theme *current_pop_up_description_theme = NULL;

void (*gui_show_pop_up_description_ex)(UI_pop_up_description *b);

/*****************************************************************************
 * FUNCTION
 *  gui_set_pop_up_description_current_theme
 * DESCRIPTION
 *  Applies the current theme for a pop up description
 * PARAMETERS
 *  b       [IN]        Is the pop up description to use
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_pop_up_description_current_theme(UI_pop_up_description *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->background_filler = current_pop_up_description_theme->background_filler;
    b->text_color = current_pop_up_description_theme->text_color;
    b->text_font = current_pop_up_description_theme->text_font;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_pop_up_description_theme
 * DESCRIPTION
 *  Applies the given theme to a pop up description
 * PARAMETERS
 *  b       [IN]        Is the pop up description to use
 *  t       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_pop_up_description_theme(UI_pop_up_description *b, UI_pop_up_description_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->background_filler = t->background_filler;
    b->text_color = t->text_color;
    b->text_font = t->text_font;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_pop_up_description
 * DESCRIPTION
 *  Creates a pop up description
 * PARAMETERS
 *  b           [IN]        Is the pop up description (pre-allocated)
 *  x           [IN]        Is the position of the left-top corner of the pop up description
 *  y           [IN]        Is the position of the left-top corner of the pop up description
 *  width       [IN]        Is the width of the pop up description
 *  height      [IN]        Is the height of the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_pop_up_description(UI_pop_up_description *b, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->flags = 0;
    gui_set_pop_up_description_current_theme(b);
    b->text_x = 4;
    b->text_y = 2;
    b->text_width = 0;
    b->scroll_x = 0;
    b->scroll_width = width - 4;
    b->n_strings = 0;
    gui_show_pop_up_description_ex = gui_show_pop_up_description_oem;
}


/*****************************************************************************
 * FUNCTION
 *  gui_resize_pop_up_description
 * DESCRIPTION
 *  Resizes a pop up description
 * PARAMETERS
 *  b           [IN]        Is the pop up description
 *  width       [IN]        Is the width of the pop up description
 *  height      [IN]        Is the height of the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
void gui_resize_pop_up_description(UI_pop_up_description *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->width = width;
    b->height = height;
    b->scroll_x = 0;
    b->scroll_width = width - 4;
}


/*****************************************************************************
 * FUNCTION
 *  gui_move_pop_up_description
 * DESCRIPTION
 *  Moves a pop up description
 * PARAMETERS
 *  b       [IN]        Is the pop up description
 *  x       [IN]        Is the new location
 *  y       [IN]        Is the new location
 * RETURNS
 *  void
 *****************************************************************************/
void gui_move_pop_up_description(UI_pop_up_description *b, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_pop_up_description
 * DESCRIPTION
 *  Moves and resizes the pop up description
 * PARAMETERS
 *  b           [IN]        Is the pop up description
 *  x           [IN]        Is the position of the left-top corner of the pop up description
 *  y           [IN]        Is the position of the left-top corner of the pop up description
 *  width       [IN]        Is the width of the pop up description
 *  height      [IN]        Is the height of the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_pop_up_description(UI_pop_up_description *b, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->x = x;
    b->y = y;
    b->width = width;
    b->height = height;
    b->scroll_width = width - 4;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_pop_up_description_n_strings
 * DESCRIPTION
 *  Sets the number of strings to be displayed in the pop up description
 * PARAMETERS
 *  b       [IN]        Is the pop up description
 *  n       [IN]        Is the number of strings
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_pop_up_description_n_strings(UI_pop_up_description *b, S32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n < 0)
    {
        n = 0;
    }
    if (n > MAX_POP_UP_DESCRIPTION_STRINGS)
    {
        n = MAX_POP_UP_DESCRIPTION_STRINGS;
    }
    b->n_strings = n;
}


/*****************************************************************************
 * FUNCTION
 *  gui_set_pop_up_description_text
 * DESCRIPTION
 *  Sets the text to be displayed for a particular row
 * PARAMETERS
 *  b           [IN]        Is the pop up description
 *  i           [IN]        Is the row index (zero based)
 *  text        [IN]        Is the string
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_pop_up_description_text(UI_pop_up_description *b, S32 i, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (i >= 0 && i < b->n_strings)
    {
        b->text_strings[i] = text;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_autoresize_pop_up_description
 * DESCRIPTION
 *  Automatically resizes the pop up description based on the text inside it
 * PARAMETERS
 *  b           [IN]        Is the pop up description
 *  width       [IN]        Is the maximum width
 *  height      [IN]        Is the maximum height
 * RETURNS
 *  1 if there is some text in the pop up (Pop up can be displayed)
 *  0 if there is no text in the pop up (Pop up need not be displayed)
 *****************************************************************************/
U8 gui_autoresize_pop_up_description(UI_pop_up_description *b, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, w, bw = 0, th = 0, h, pw;
    U8 rvalue = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(height);
    if (b->n_strings == 0)
    {
        return (0);
    }
    gui_set_font(b->text_font);
    for (i = 0; i < b->n_strings; i++)
    {
        if (b->text_strings[i] != NULL)
        {
            gui_measure_string(b->text_strings[i], &w, &h);
            th += h;
            if (w > bw)
            {
                bw = w;
            }
            rvalue = 1;
        }
    }
    b->text_width = bw;
    bw += 8;
#if defined(UI_POPUP_DESCRIPTION_STYLE_3)
    th += 7;
#elif defined(UI_POPUP_DESCRIPTION_STYLE_2)
    th += 5;
#else 
    th += 4;
#endif 
    /* Permissible width is 3/4 of the actual width */
    pw = (width >> 1) + (width >> 2);
    if (bw > pw)
    {
        bw = pw;
    }
    /* if(th>height) th=height; */
    b->width = bw;
    b->height = th;
    b->scroll_width = b->width - 8;
    return (rvalue);
}

/* Text scrolling related functions within the Pop up description */

UI_pop_up_description *GUI_current_pop_up_description = NULL;
U8 GUI_current_pop_up_description_scroll = 0;
U8 GUI_current_pop_up_description_scroll_direction;
S32 GUI_current_pop_up_description_x;
S32 GUI_current_pop_up_description_y;
S32 GUI_current_pop_up_description_scroll_counter = 0;
UI_string_type GUI_current_pop_up_description_scroll_text[MAX_POP_UP_DESCRIPTION_STRINGS];
UI_string_type GUI_current_pop_up_description_scroll_text_end[MAX_POP_UP_DESCRIPTION_STRINGS];


/*****************************************************************************
 * FUNCTION
 *  gui_pop_up_description_scroll_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_pop_up_description_scroll_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags = GUI_current_pop_up_description->flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GUI_current_pop_up_description_scroll == 0)
    {
        return;
    }

    if (GUI_current_pop_up_description_scroll_counter)
    {
        GUI_current_pop_up_description_scroll_counter--;
    }
    else
    {
    #if(UI_USE_WORD_SCROLLING_TEXT)
        {
            S32 i;

            for (i = 0; i < MAX_POP_UP_DESCRIPTION_STRINGS; i++)
            {
                GUI_current_pop_up_description_scroll_text[i] = GUI_current_pop_up_description_scroll_text_end[i];
            }
        }
    #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        if (flags & UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL)
        {
            GUI_current_pop_up_description->scroll_x -= UI_pop_up_description_scroll_size;
            if (GUI_current_pop_up_description->scroll_x <=
                (-(GUI_current_pop_up_description->text_width + UI_pop_up_description_scroll_gap)))
            {
                GUI_current_pop_up_description->scroll_x = 0;
            }
        }
        else
        {
            if (GUI_current_pop_up_description_scroll_direction == 0)
            {
                GUI_current_pop_up_description->scroll_x -= UI_pop_up_description_scroll_size;
                if ((GUI_current_pop_up_description->scroll_x + GUI_current_pop_up_description->text_width) <=
                    (GUI_current_pop_up_description->scroll_width))
                {
                    GUI_current_pop_up_description_scroll_direction = 1;
                    GUI_current_pop_up_description_scroll_counter = UI_pop_up_description_scroll_pause;
                }
            }
            else if (GUI_current_pop_up_description_scroll_direction == 1)
            {
                GUI_current_pop_up_description->scroll_x += UI_pop_up_description_scroll_size;
                if (GUI_current_pop_up_description->scroll_x >= 0)
                {
                    GUI_current_pop_up_description_scroll_direction = 0;
                    GUI_current_pop_up_description_scroll_counter = UI_pop_up_description_scroll_pause;
                }
            }
        }
    #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
    }
    GUI_current_pop_up_description->flags |= UI_POP_UP_DESCRIPTION_DISPLAY_SCROLL;
    gui_show_pop_up_description((void*)GUI_current_pop_up_description);
    GUI_current_pop_up_description->flags &= ~UI_POP_UP_DESCRIPTION_DISPLAY_SCROLL;

    gui_BLT_double_buffer(
        GUI_current_pop_up_description_x,
        GUI_current_pop_up_description_y,
        GUI_current_pop_up_description_x + GUI_current_pop_up_description->width - 1,
        GUI_current_pop_up_description_y + GUI_current_pop_up_description->height - 1);

    gui_start_timer(UI_pop_up_description_scroll_time, gui_pop_up_description_scroll_handler);
}

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__


/*****************************************************************************
 * FUNCTION
 *  gui_pop_up_description_transition_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_pop_up_description_transition_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GUI_current_pop_up_description->transition_step > 0)
    {
        gui_lock_double_buffer();

        gui_show_pop_up_description((void*)GUI_current_pop_up_description);

        gui_unlock_double_buffer();
        gui_BLT_double_buffer(
            GUI_current_pop_up_description->x,
            GUI_current_pop_up_description->y,
            GUI_current_pop_up_description->x + GUI_current_pop_up_description->width - 1,
            GUI_current_pop_up_description->y + GUI_current_pop_up_description->height - 1);

        GUI_current_pop_up_description->transition_step--;
        if (GUI_current_pop_up_description->transition_step == 0)
        {
            gui_pop_up_description_start_scroll(GUI_current_pop_up_description);
        }
        else
        {
            gui_start_timer(POPUP_DESCRIPTION_TRANSITION_STEP_TIME, gui_pop_up_description_transition_handler);
        }
    }
}

#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_pop_up_description_start_scroll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  m       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_pop_up_description_start_scroll(UI_pop_up_description *m)
{
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m->transition_step > 0)
    {
        GUI_current_pop_up_description = m;
        gui_start_timer(UI_pop_up_description_scroll_time, gui_pop_up_description_transition_handler);
    }
    else
#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */ 
    if (m->text_width > m->scroll_width)
    {
    #if(UI_USE_WORD_SCROLLING_TEXT)
        {
            S32 i;

            for (i = 0; i < MAX_POP_UP_DESCRIPTION_STRINGS; i++)
            {
                GUI_current_pop_up_description_scroll_text[i] = m->text_strings[i];
            }
        }
        GUI_current_pop_up_description = m;
        GUI_current_pop_up_description_x = m->x;
        GUI_current_pop_up_description_y = m->y;
        GUI_current_pop_up_description_scroll = 1;
        GUI_current_pop_up_description_scroll_direction = 0;
        GUI_current_pop_up_description_scroll_counter = UI_pop_up_description_scroll_pause;
        gui_start_timer(UI_pop_up_description_scroll_time, gui_pop_up_description_scroll_handler);
    #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        if ((m->flags & UI_POP_UP_DESCRIPTION_MARQUEE_SCROLL) ||
            (m->flags & UI_POP_UP_DESCRIPTION_TWO_DIRECTION_SCROLL))
        {
            GUI_current_pop_up_description = m;
            GUI_current_pop_up_description_x = m->x;
            GUI_current_pop_up_description_y = m->y;
            GUI_current_pop_up_description_scroll = 1;
            GUI_current_pop_up_description_scroll_direction = 0;
            GUI_current_pop_up_description_scroll_counter = UI_pop_up_description_scroll_pause;
            gui_start_timer(UI_pop_up_description_scroll_time, gui_pop_up_description_scroll_handler);
        }
    #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
    }
    else
    {
        GUI_current_pop_up_description_scroll = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_pop_up_description_stop_scroll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_pop_up_description_stop_scroll(void)
{
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_pop_up_description_transition_handler);
    if (GUI_current_pop_up_description)
    {
        GUI_current_pop_up_description->transition_step = 0;
    }
#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */ 

    if (GUI_current_pop_up_description_scroll)
    {
        GUI_current_pop_up_description->scroll_x = 0;
        gui_cancel_timer(gui_pop_up_description_scroll_handler);
        GUI_current_pop_up_description_scroll = 0;
    }
}

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__


/*****************************************************************************
 * FUNCTION
 *  gui_setup_pop_up_description_transition
 * DESCRIPTION
 *  Setup the transition animation of the pop up descriptions
 * PARAMETERS
 *  b       [IN]        Is the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
void gui_setup_pop_up_description_transition(UI_pop_up_description *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    b->transition_step = MAX_POP_UP_DESCRIPTION_TRANSITION_STEPS;
}

#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_show_pop_up_description
 * DESCRIPTION
 *  Displays the pop up description
 * PARAMETERS
 *  b       [IN]        Is the pop up description
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_pop_up_description(UI_pop_up_description *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_pop_up_description_ex(b);
}

/* Scrolling text object implementation      */
/* Externals for graphics context switching  */
extern bitmap main_LCD_device_bitmap;
extern bitmap sub_LCD_device_bitmap;
void UI_set_main_LCD_graphics_context(void);
void UI_set_sub_LCD_graphics_context(void);
extern bitmap *current_LCD_device_bitmap;


/*****************************************************************************
 * FUNCTION
 *  default_scrolling_text_draw_background
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
void default_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(x1, y1, x2, y2, c);
}

extern UI_font_type UI_font;


/*****************************************************************************
 * FUNCTION
 *  gui_create_scrolling_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s                   [?]         
 *  x                   [IN]        
 *  y                   [IN]        
 *  width               [IN]        
 *  height              [IN]        
 *  text                [IN]        
 *  timer_callback      [IN]        
 *  draw_background     [IN]        
 *  text_color          [IN]        
 *  border_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_create_scrolling_text(
        scrolling_text *s,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type text,
        void (*timer_callback) (void),
        void (*draw_background) (S32 x1, S32 y1, S32 x2, S32 y2),
        color text_color,
        color border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->x = x;
    s->y = y;
    s->scroll_x = 0;
    s->width = width;
    s->height = height;
    s->text = text;
    s->text_color = text_color;
    s->text_border_color = border_color;
    s->text_font = *UI_font;
    s->scroll_size = UI_TEXT_MENUITEM_SCROLL_SIZE;
    s->scroll_gap = UI_TEXT_MENUITEM_SCROLL_GAP;
    s->scroll_pause = UI_TEXT_MENUITEM_SCROLL_PAUSE;
    gui_set_font(&s->text_font);
    gui_measure_string(text, &s->text_width, &s->text_height);
    s->graphics_context = current_LCD_device_bitmap;

    if (timer_callback == NULL)
    {
        timer_callback = UI_dummy_function;
    }

    s->timer_callback = timer_callback;
    s->scroll_time = UI_TEXT_MENUITEM_SCROLL_TIME;
    s->flags = UI_SCROLLING_TEXT_MARQUEE_SCROLL;

    if (draw_background == NULL)
    {
        draw_background = default_scrolling_text_draw_background;
    }

    s->draw_background = draw_background;
}


/*****************************************************************************
 * FUNCTION
 *  gui_change_scrolling_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [?]         
 *  text        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_change_scrolling_text(scrolling_text *s, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->text = text;
    gui_set_font(&s->text_font);
    gui_measure_string(text, &s->text_width, &s->text_height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_change_scrolling_text_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [?]         
 *  font        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_change_scrolling_text_font(scrolling_text *s, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s->text_font = *font;
    gui_set_font(&s->text_font);
    gui_measure_string(s->text, &s->text_width, &s->text_height);
}


/*****************************************************************************
 * FUNCTION
 *  gui_redraw_scrolling_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_redraw_scrolling_text(scrolling_text *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, sw, sh;
    S32 cx1, cy1, cx2, cy2;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->graphics_context != current_LCD_device_bitmap)
    {
        if (s->graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (s->graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }
    }
    x1 = s->x;
    y1 = s->y;
    x2 = x1 + s->width - 1;
    y2 = y1 + s->height - 1;
    if (s->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
    {
        cx1 = x1 - 2;
        cy1 = y1 - 1;
        cx2 = x2 + 2;
        cy2 = y2 + 1;
    }
    else
    {
        cx1 = x1;
        cy1 = y1;
        cx2 = x2;
        cy2 = y2;
    }
    gui_push_clip();
    gui_push_text_clip();
    gui_set_text_clip(cx1, cy1, cx2, cy2);
    gui_set_clip(cx1, cy1, cx2, cy2);
    s->draw_background(cx1, cy1, cx2, cy2);
    gui_set_font(&s->text_font);
    gui_measure_string(s->text, &sw, &sh);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(s->x + s->scroll_x + s->width - 1, s->y);
    }
    else
    {
        gui_move_text_cursor(s->x + s->scroll_x, s->y);
    }
    gui_set_text_color(s->text_color);
    gui_set_line_height(sh);
    if (s->flags & UI_SCROLLING_TEXT_BORDERED_TEXT)
    {
        gui_set_text_border_color(s->text_border_color);
    #if(UI_USE_WORD_SCROLLING_TEXT)
        if (s->flags & UI_SCROLLING_TEXT_DISPLAY_SCROLL)
        {
            s->scroll_text_end = s->scroll_text;
        }
        else
        {
            s->scroll_text_end = s->text;
        }
        if (gui_print_truncated_bordered_text2(s->x + s->scroll_x, s->y, (x2 - x1 + 1), &s->scroll_text_end))
        {
            s->scroll_text_end = s->text;
        }
    #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        gui_print_bordered_text(s->text);
        if ((s->flags & UI_SCROLLING_TEXT_MARQUEE_SCROLL) && (s->flags & UI_SCROLLING_TEXT_ENABLE_SCROLL))
        {
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(s->x + s->scroll_x + s->width - 1 - (s->text_width + s->scroll_gap), s->y);
            }
            else
            {
                gui_move_text_cursor(s->x + s->scroll_x + s->text_width + s->scroll_gap, s->y);
            }

            gui_set_line_height(sh);
            gui_print_bordered_text(s->text);
        }
    #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
    }
    else
    {
    #if(UI_USE_WORD_SCROLLING_TEXT)
        if (s->flags & UI_SCROLLING_TEXT_DISPLAY_SCROLL)
        {
            s->scroll_text_end = s->scroll_text;
        }
        else
        {
            s->scroll_text_end = s->text;
        }
        if (gui_print_truncated_text2(s->x + s->scroll_x, s->y, (x2 - x1 + 1), &s->scroll_text_end))
        {
            s->scroll_text_end = s->text;
        }
    #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        gui_print_text(s->text);
        if ((s->flags & UI_SCROLLING_TEXT_MARQUEE_SCROLL) && (s->flags & UI_SCROLLING_TEXT_ENABLE_SCROLL))
        {
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(s->x + s->scroll_x + s->width - 1 - (s->text_width + s->scroll_gap), s->y);
            }
            else
            {
                gui_move_text_cursor(s->x + s->scroll_x + s->text_width + s->scroll_gap, s->y);
            }

            gui_set_line_height(sh);
            gui_print_text(s->text);
        }
    #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
    }

    gui_pop_clip();
    gui_pop_text_clip();
    gui_BLT_double_buffer(cx1, cy1, cx2, cy2);

    if (saved_graphics_context != current_LCD_device_bitmap)
    {
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_handle_scrolling_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_handle_scrolling_text(scrolling_text *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->scroll_counter)
    {
        s->scroll_counter--;
    }
    else
    {
    #if(UI_USE_WORD_SCROLLING_TEXT)
        s->scroll_text = s->scroll_text_end;
    #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        if (s->flags & UI_SCROLLING_TEXT_MARQUEE_SCROLL)
        {
            if (r2lMMIFlag)
            {
                s->scroll_x += s->scroll_size;
                if (s->scroll_x >= (s->text_width + s->scroll_gap))
                {
                    s->scroll_x = 0;
                }
            }
            else
            {
                s->scroll_x -= s->scroll_size;
                if (s->scroll_x <= (-(s->text_width + s->scroll_gap)))
                {
                    s->scroll_x = 0;
                }
            }
        }
        else
        {
            if (!(s->flags & UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT))
            {
                s->scroll_x -= s->scroll_size;
                if ((s->scroll_x + s->text_width) <= (s->width))
                {
                    s->flags |= UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT;
                    s->scroll_counter = s->scroll_pause;
                }
            }
            else if (s->flags & UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT)
            {
                s->scroll_x += s->scroll_size;
                if (s->scroll_x >= 0)
                {
                    s->flags &= ~UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT;
                    s->scroll_counter = s->scroll_pause;
                }
            }
        }
    #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        s->flags |= UI_SCROLLING_TEXT_DISPLAY_SCROLL;
        gui_redraw_scrolling_text(s);
        s->flags &= ~UI_SCROLLING_TEXT_DISPLAY_SCROLL;
    }
    gui_start_timer(s->scroll_time, s->timer_callback);
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrolling_text_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_scrolling_text_start(scrolling_text *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->text_width > s->width)
    {
        s->scroll_x = 0;
    #if(UI_USE_WORD_SCROLLING_TEXT)
        s->scroll_text = s->text;
        s->flags |= UI_SCROLLING_TEXT_ENABLE_SCROLL;
        s->flags &= ~UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT;
        s->scroll_counter = s->scroll_pause;
        gui_start_timer(s->scroll_time, s->timer_callback);
    #else /* (UI_USE_WORD_SCROLLING_TEXT) */ 
        if ((s->flags & UI_SCROLLING_TEXT_MARQUEE_SCROLL) || (s->flags & UI_SCROLLING_TEXT_TWO_DIRECTION_SCROLL))
        {
            s->flags |= UI_SCROLLING_TEXT_ENABLE_SCROLL;
            s->flags &= ~UI_SCROLLING_TEXT_SCROLL_DIRECTION_RIGHT;
            s->scroll_counter = s->scroll_pause;
            gui_start_timer(s->scroll_time, s->timer_callback);
        }
    #endif /* (UI_USE_WORD_SCROLLING_TEXT) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_scrolling_text_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_scrolling_text_stop(scrolling_text *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s->flags & UI_SCROLLING_TEXT_ENABLE_SCROLL)
    {
        gui_cancel_timer(s->timer_callback);
        s->flags &= ~UI_SCROLLING_TEXT_ENABLE_SCROLL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_show_scrolling_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_show_scrolling_text(scrolling_text *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_redraw_scrolling_text(s);
    gui_scrolling_text_start(s);
}

/* GUI multiple layer support utility */
#ifdef __GDI_MEMORY_PROFILE_2__
#include "lcd_if.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"

extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;

static S32 gui_image_frame_idx = 0;
static S32 gui_image_frame_count = 0;
static S32 gui_image_offset_x, gui_image_offset_y;
static S32 gui_image_clip_x1, gui_image_clip_y1, gui_image_clip_x2, gui_image_clip_y2;
static S32 gui_image_id;
gdi_handle gui_image_layer;
static U8 gdi_transparent_value;

#define GUI_OPACITY_SECOND_LAYER    60
#define GUI_OPACITY_BASED_LAYER  200
extern void PhnsetWallpaperBadFileCallBack(U16 imgID);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 


/*****************************************************************************
 * FUNCTION
 *  gui_layer_show_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_layer_show_animation(void)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE gdi_base_layer_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_HANDLE gui_animation; */

    gui_image_frame_idx = gui_image_frame_idx + 1;
    if ((gui_image_frame_idx) >= gui_image_frame_count)
    {
        gui_image_frame_idx = 0;
    }

    if (gui_is_entry_new_screen() == MMI_TRUE)
    {
        return; /* to avoid twice entry while time exipred */
    }

    /* dispaly wallpaper */
    gdi_layer_set_active(gui_image_layer);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->general_background_filler);
    gdi_layer_pop_clip();

    gdi_layer_push_clip();
    gdi_layer_set_clip(gui_image_clip_x1, gui_image_clip_y1, gui_image_clip_x2, gui_image_clip_y2);
    gdi_layer_set_opacity(TRUE, gdi_transparent_value);
    /* gdi_image_draw_animation_single_frame_id(gui_image_offset_x, gui_image_offset_y, gui_image_id, gui_image_frame_idx); */
    gdi_image_draw_animation(gui_image_offset_x, gui_image_offset_y, get_image((U16) gui_image_id), NULL);
    gdi_layer_pop_clip();

    gdi_layer_unlock_frame_buffer();

    gdi_layer_restore_base_active();

    gdi_layer_get_base_handle(&gdi_base_layer_hdlr);
    gdi_layer_set_blt_layer(gui_image_layer, gdi_base_layer_hdlr, 0, 0);
    gdi_layer_blt_previous(gui_image_clip_x1, gui_image_clip_y1, gui_image_clip_x2, gui_image_clip_y2);
    /* restore to base layer */
    /* gdi_layer_restore_base_active(); */

#endif /* __GDI_MEMORY_PROFILE_2__ */ 

}
extern S32 cat33_n_frames;

/* 092005 draw_wallpaper Calvin Start */
extern S32 cat33_image_x;
extern S32 cat33_image_y;
extern S32 cat33_image_width;
extern S32 cat33_image_height;

/* 092005 draw_wallpaper Calvin End */


/*****************************************************************************
 * FUNCTION
 *  gui_layer_show_animation_ID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gui_show_layer      [IN]        
 *  trans_value         [IN]        
 *  frame_idx           [?]         
 *  image_id            [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  image_x1            [IN]        
 *  image_y1            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_layer_show_animation_ID(
        S32 gui_show_layer,
        U8 trans_value,
        S32 *frame_idx,
        U16 image_id,
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2,
        S32 image_x1,
        S32 image_y1)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_image_frame_count = cat33_n_frames;
    gui_image_frame_idx = *frame_idx;
    gui_image_clip_x1 = x1;
    gui_image_clip_y1 = y1;
    gui_image_clip_x2 = x2;
    gui_image_clip_y2 = y2;
    gui_image_offset_x = image_x1;
    gui_image_offset_y = image_y1;
    gui_image_id = image_id;
    gui_image_layer = gui_show_layer;
    gdi_transparent_value = trans_value;
    gui_layer_show_animation();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  gui_layer_show_animation_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gui_show_layer      [IN]        
 *  trans_value         [IN]        
 *  frame_idx           [?]         
 *  file_name           [?]         
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  image_x1            [IN]        
 *  image_y1            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_layer_show_animation_file(
        S32 gui_show_layer,
        U8 trans_value,
        S32 *frame_idx,
        S8 *file_name,
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2,
        S32 image_x1,
        S32 image_y1)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE gdi_base_layer_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U16 gui_image_frame_no; */

    if (gui_is_entry_new_screen() == MMI_TRUE)
    {
        return; /* to avoid twice entry while time exipred */
    }

    /* dispaly wallpaper */
    gdi_layer_set_active(gui_show_layer);

    gdi_layer_lock_frame_buffer();

    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, current_MMI_theme->general_background_filler);
    gdi_layer_pop_clip();

    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_layer_set_opacity(TRUE, trans_value);

    {
        S32 offset_x = 0;
        S32 offset_y = 0;
        S32 disp_height, disp_width;
        GDI_RESULT ret;

        disp_width = x2 - x1 + 1;
        disp_height = y2 - y1 + 1;

        gdi_image_get_dimension_file(file_name, &cat33_image_width, &cat33_image_height);

        if ((disp_width >= cat33_image_width) && (disp_height >= cat33_image_height))   /* image can be displayed entirely */
        {
            /* align preview window at the center of screen */
            offset_x = (disp_width - cat33_image_width) >> 1;
            offset_y = (disp_height - cat33_image_height) >> 1;

        #if defined(ENABLE_ANIMATED_WALLPAPERS)
            ret = gdi_image_draw_animation_file(offset_x, offset_y, (PS8) file_name, NULL);
        #else 
            ret = gdi_image_draw_file(offset_x, offset_y, (PS8) file_name);
        #endif 
        }
        else    /* image is larger than screen size */
        {
            S32 resized_offset_x;
            S32 resized_offset_y;
            S32 resized_width;
            S32 resized_height;

            gdi_image_util_fit_bbox(
                disp_width,
                disp_height,
                cat33_image_width,
                cat33_image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            /* for images of other formats, try to set center alignment */
        #if defined(ENABLE_ANIMATED_WALLPAPERS)
            ret = gdi_image_draw_animation_resized_file(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (PS8) file_name,
                    NULL);
        #else /* defined(ENABLE_ANIMATED_WALLPAPERS) */ 
            ret = gdi_image_draw_resized_file(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    (PS8) file_name);
        #endif /* defined(ENABLE_ANIMATED_WALLPAPERS) */ 
        }

        if (ret < 0 && ret != GDI_GIF_ERR_OUT_OF_CLIP_REGION && ret != GDI_BMP_ERR_OUT_OF_CLIP_REGION)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "draw_wallpaper():[$$$]GDI_RESULT:%d[$$$]\n", ret);
            PhnsetWallpaperBadFileCallBack(0);
        }
    }
    
    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_restore_base_active();
    gdi_layer_get_base_handle(&gdi_base_layer_hdlr);
    gdi_layer_set_blt_layer(gui_show_layer, gdi_base_layer_hdlr, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_free_multilayer_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_free_multilayer_screen(void)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_stop_animation_all();
    gui_cancel_timer(gui_layer_show_animation);

    /* flatten layers & free another layer */
    if (wgui_layer_1 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_flatten_to_base(wgui_layer_1, wgui_base_layer, 0, 0);

        gdi_layer_free(wgui_layer_1);
        wgui_layer_1 = GDI_LAYER_EMPTY_HANDLE;
    }

    gdi_layer_set_opacity(FALSE, 255);

    /* restore base to no transparent */
    gdi_layer_restore_base_active();
    gdi_layer_multi_layer_disable();

#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  gui_layer_transparent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gui_show_layer      [IN]        
 *  trans_value         [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_layer_transparent(S32 gui_show_layer, U8 trans_value, S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __GDI_MEMORY_PROFILE_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gdi_layer_get_base_handle(&wgui_base_layer); */
    gdi_layer_set_active(gui_show_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_BLUE);
    gdi_layer_set_opacity(TRUE, trans_value);
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_BLUE);
    gdi_layer_pop_clip();
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
}

static U8 mmi_ui_is_screen_changed = MMI_TRUE;


/*****************************************************************************
 * FUNCTION
 *  gui_set_entry_new_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_entry       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_entry_new_screen(U8 new_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ui_is_screen_changed = new_entry;
}


/*****************************************************************************
 * FUNCTION
 *  gui_is_entry_new_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 gui_is_entry_new_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ui_is_screen_changed;
}

#ifdef __GDI_MEMORY_PROFILE_2__
static S32 mmi_ui_multilayer_mask = UI_MUL_ALL_ON;
#else 
static S32 mmi_ui_multilayer_mask = UI_MUL_ALL_OFF;
#endif 


/*****************************************************************************
 * FUNCTION
 *  gui_set_multilayer_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_multilayer_mask      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gui_set_multilayer_mask(S32 in_multilayer_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ui_multilayer_mask = in_multilayer_mask;
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_multilayer_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 gui_get_multilayer_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ui_multilayer_mask;
}

/* Touch Panel - Utility functions for waiting longtap animation */

/* Typical longpress events comes after 0.3~0.6 sec. However,  we wait about 1~2 seconds 
   before entering fullscreen editor of inline menu. To indicate that it is waiting for a long period, 
   we display animation on pen down position.  Before the animation is finished, user can abort it 
   by moving away the pen or pen up. */

#ifdef __MMI_TOUCH_SCREEN__

static gui_wait_longpress_enum g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_UNDECIDED;
static mmi_pen_point_struct g_mmi_gui_wait_longpress_pen_origin_pos;

static S16 g_mmi_gui_wait_longpress_animation_frame;
static S16 g_mmi_gui_wait_longpress_animation_x;
static S16 g_mmi_gui_wait_longpress_animation_y;
static S16 g_mmi_gui_wait_longpress_animation_width;
static S16 g_mmi_gui_wait_longpress_animation_height;

static U8 g_mmi_gui_wait_longpress_layer_data[GUI_WAIT_LONGPRESS_CACHE_SIZE];
static gdi_handle *g_mmi_gui_wait_longpress_layer_p = NULL;


/*****************************************************************************
 * FUNCTION
 *  gui_wait_longpress_animation_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_wait_longpress_animation_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_gui_wait_longpress_layer_p);

    gdi_layer_push_and_set_active(*g_mmi_gui_wait_longpress_layer_p);

    gdi_layer_lock_frame_buffer();

    gdi_layer_reset_clip();

    /* Draw frame */
    gdi_draw_solid_rect(
        0,
        0,
        g_mmi_gui_wait_longpress_animation_width - 1,
        g_mmi_gui_wait_longpress_animation_height - 1,
        GDI_COLOR_TRANSPARENT);

    ret = gdi_image_draw_animation_single_frame_id(
            0,
            0,
            IMG_PEN_WAITING_LONGPRESS,
            g_mmi_gui_wait_longpress_animation_frame++);

    gdi_layer_unlock_frame_buffer();

    gdi_layer_pop_and_restore_active();

    gdi_layer_blt_previous(
        g_mmi_gui_wait_longpress_animation_x,
        g_mmi_gui_wait_longpress_animation_y,
        g_mmi_gui_wait_longpress_animation_x + g_mmi_gui_wait_longpress_animation_width - 1,
        g_mmi_gui_wait_longpress_animation_y + g_mmi_gui_wait_longpress_animation_height - 1);

    if (ret == GDI_IMAGE_SUCCEED)
    {
        gui_start_timer(gdi_image_get_animation_delay(), gui_wait_longpress_animation_handler);
    }
    else    /* Including error or GDI_GIF_LAST_FRAME */
    {
        /* Just change the state. The actions is triggered by gui_pen_wait_longpress() later */

        MMI_DBG_ASSERT(g_mmi_gui_wait_longpress_state == GUI_WAIT_LONGPRESS_ANIMATING);
        g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_ANIMATION_FINISHED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_wait_longpress_start_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_wait_longpress_start_animation(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iw, ih;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image((PU8) GetImage(IMG_PEN_WAITING_LONGPRESS), &iw, &ih);

    x -= (iw >> 1);
    y -= (ih >> 1);

    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }

    g_mmi_gui_wait_longpress_animation_frame = 0;
    g_mmi_gui_wait_longpress_animation_x = x;
    g_mmi_gui_wait_longpress_animation_y = y;
    g_mmi_gui_wait_longpress_animation_width = iw;
    g_mmi_gui_wait_longpress_animation_height = ih;
    if (x + iw >= UI_device_width)
    {
        g_mmi_gui_wait_longpress_animation_width = UI_device_width - x;
    }
    if (y + ih >= UI_device_height)
    {
        g_mmi_gui_wait_longpress_animation_height = UI_device_height - y;
    }

    if (g_mmi_gui_wait_longpress_layer_p == NULL)
    {
        MMI_ASSERT(((iw * ih * gdi_layer_get_bit_per_pixel() + 7) >> 3) <= GUI_WAIT_LONGPRESS_CACHE_SIZE);

        dm_create_layer_using_outside_memory(
            x,
            y,
            iw, /* full image width */
            ih, /* full image height */
            &g_mmi_gui_wait_longpress_layer_p,
            g_mmi_gui_wait_longpress_layer_data,
            GUI_WAIT_LONGPRESS_CACHE_SIZE,
            DM_LAYER_TOP);

        gdi_layer_push_and_set_active(*g_mmi_gui_wait_longpress_layer_p);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(*g_mmi_gui_wait_longpress_layer_p);
        gdi_layer_set_position(x, y);
        gdi_layer_pop_and_restore_active();
    }

    /* Because gui_wait_longpress_animation_handler() might  change g_mmi_gui_wait_longpress_state.
       Start a quick timer to execute it asynchronously */
    gui_start_timer(10, gui_wait_longpress_animation_handler);
}


/*****************************************************************************
 * FUNCTION
 *  gui_wait_longpress_stop_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_wait_longpress_stop_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(gui_wait_longpress_animation_handler);
}


/*****************************************************************************
 * FUNCTION
 *  gui_wait_longpress_hide_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_wait_longpress_hide_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_gui_wait_longpress_layer_p != NULL)
    {
        gdi_layer_push_and_set_active(*g_mmi_gui_wait_longpress_layer_p);

        gdi_layer_lock_frame_buffer();

        gdi_layer_reset_clip();

        gdi_draw_solid_rect(
            0,
            0,
            g_mmi_gui_wait_longpress_animation_width - 1,
            g_mmi_gui_wait_longpress_animation_height - 1,
            GDI_COLOR_TRANSPARENT);

        gdi_layer_unlock_frame_buffer();

        gdi_layer_pop_and_restore_active();

        gdi_layer_blt_previous(
            g_mmi_gui_wait_longpress_animation_x,
            g_mmi_gui_wait_longpress_animation_y,
            g_mmi_gui_wait_longpress_animation_x + g_mmi_gui_wait_longpress_animation_width - 1,
            g_mmi_gui_wait_longpress_animation_y + g_mmi_gui_wait_longpress_animation_height - 1);
    }
}

/* Called when screen is switched */


/*****************************************************************************
 * FUNCTION
 *  gui_pen_reset_waiting_longpress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_pen_reset_waiting_longpress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_wait_longpress_stop_animation();
    g_mmi_gui_wait_longpress_layer_p = NULL;
    g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_UNDECIDED;
}


/*****************************************************************************
 * FUNCTION
 *  gui_pen_wait_longpress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pen_event       [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gui_wait_longpress_enum gui_pen_wait_longpress(mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Register GUI clean up hook */
    gui_add_cleanup_hook(gui_pen_reset_waiting_longpress);

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_UNDECIDED;
    }

    switch (g_mmi_gui_wait_longpress_state)
    {
        case GUI_WAIT_LONGPRESS_INVALID:
            break;

        case GUI_WAIT_LONGPRESS_UNDECIDED:
            if (pen_event == MMI_PEN_EVENT_DOWN)
            {
                g_mmi_gui_wait_longpress_pen_origin_pos.x = x;
                g_mmi_gui_wait_longpress_pen_origin_pos.y = y;
            }
            else if (pen_event == MMI_PEN_EVENT_LONG_TAP)
            {
                /* MMI_PEN_EVENT_LONG_TAP only occurs on pen down position */
                g_mmi_gui_wait_longpress_pen_origin_pos.x = x;
                g_mmi_gui_wait_longpress_pen_origin_pos.y = y;

                gui_wait_longpress_start_animation(x, y);

                g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_ANIMATING;
            }
            else if (PEN_ABS(x, g_mmi_gui_wait_longpress_pen_origin_pos.x) +
                     PEN_ABS(y, g_mmi_gui_wait_longpress_pen_origin_pos.y) > GUI_WAIT_LONGPRESS_MAX_DISTANCE)
            {
                g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_INVALID;
            }
            break;

        case GUI_WAIT_LONGPRESS_ANIMATING:
            if (pen_event == MMI_PEN_EVENT_UP ||
                pen_event == MMI_PEN_EVENT_ABORT ||
                (PEN_ABS(x, g_mmi_gui_wait_longpress_pen_origin_pos.x) +
                 PEN_ABS(y, g_mmi_gui_wait_longpress_pen_origin_pos.y) > GUI_WAIT_LONGPRESS_MAX_DISTANCE))
            {
                gui_wait_longpress_stop_animation();
                gui_wait_longpress_hide_animation();
                g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_INVALID;
            }
            break;

        case GUI_WAIT_LONGPRESS_ANIMATION_FINISHED:
            gui_wait_longpress_stop_animation();
            gui_wait_longpress_hide_animation();
            g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_READY;
            break;

        case GUI_WAIT_LONGPRESS_READY:
            /* Return ready only one time */
            g_mmi_gui_wait_longpress_state = GUI_WAIT_LONGPRESS_INVALID;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    return g_mmi_gui_wait_longpress_state;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

